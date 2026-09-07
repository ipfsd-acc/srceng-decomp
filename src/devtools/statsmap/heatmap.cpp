// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/heatmap.cpp
// Functions: 9
// ============================================================

#include "devtools\statsmap\heatmap.h"

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: public: bool CHeatMap::ResetImage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHeatMap::ResetImage(CHeatMap *this)
{
  void *v2; // edi
  unsigned int v4; // esi
  float v5; // xmm0_4
  char *m_szOverviewImage; // [esp+Ch] [ebp-8h]
  unsigned __int8 *buf; // [esp+10h] [ebp-4h]

  m_szOverviewImage = this->m_szOverviewImage;
  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_szOverviewImage, a3: "rb", a4: 0);
  if ( v2 != nullptr )
  {
    v4 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    buf = (unsigned __int8 *)operator new(nSize: v4 + 1);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf, a3: v4, a4: v2);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    buf[v4] = 0;
    if ( this->m_Image.data != nullptr )
      free(pMem: this->m_Image.data);
    this->m_Image.h = 0;
    this->m_Image.w = 0;
    this->m_Image.data = nullptr;
    if ( ReadBitmapRGB(raw: buf, rawlen: v4, image: &this->m_Image) != 0 )
    {
      this->m_flMaxValue = 0.0;
      v5 = (float)(StatsMap()->m_flScale * 256.0) / this->m_flMapScale;
      this->m_flRadius = v5;
      this->m_nRadius = (int)v5;
      this->m_flRadiusSqr = v5 * v5;
      return 1;
    }
    else
    {
      _Msg(
        a1: "Failed to read image data from %s\n"
        "Make sure this is a clean 24-bit bmp file.\n"
        "ACDSee can save out a clean BMP, but Photoshop seems to add some extra data.\n",
        m_szOverviewImage);
      return 0;
    }
  }
  else
  {
    _Msg(a1: "Failed to open overview m_Image file %s\n", this->m_szOverviewImage);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401940
// Name: private: static void CHeatMap::HSLToRGB(class Color __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHeatMap::HSLToRGB(Color *out, float *hsl)
{
  float v2; // xmm6_4
  __int128 v3; // xmm1
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  bool v7; // cc
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4

  v2 = 0.0;
  out->_color[3] = -1;
  if ( *hsl < 0.0 )
  {
    v3 = *(unsigned int *)hsl;
    do
    {
      v4 = v3;
      *(float *)&v4 = *(float *)&v3 + 360.0;
      v3 = v4;
    }
    while ( *(float *)&v4 < 0.0 );
    *(_DWORD *)hsl = v4;
  }
  if ( *hsl > 360.0 )
  {
    v5 = *(unsigned int *)hsl;
    do
    {
      v6 = v5;
      *(float *)&v6 = *(float *)&v5 - 360.0;
      v7 = (float)(*(float *)&v5 - 360.0) <= 360.0;
      v5 = v6;
    }
    while ( !v7 );
    *(_DWORD *)hsl = v6;
  }
  v8 = *hsl;
  if ( *hsl >= 120.0 )
  {
    if ( v8 < 240.0 )
    {
      v11 = 0.0;
      v10 = (float)(240.0 - v8) * 0.01666666666666667;
      v2 = (float)(v8 - 120.0) * 0.01666666666666667;
      goto LABEL_16;
    }
    v9 = *hsl - 240.0;
    v10 = 0.0;
    v2 = (float)(360.0 - v8) * 0.01666666666666667;
  }
  else
  {
    v9 = 120.0 - v8;
    v10 = v8 * 0.01666666666666667;
  }
  v11 = v9 * 0.01666666666666667;
  if ( v11 >= 1.0 )
    v11 = 1.0;
LABEL_16:
  if ( v10 >= 1.0 )
    v10 = 1.0;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v12 = hsl[1];
  v13 = 1.0 - v12;
  v14 = v12 * 2.0;
  v15 = (float)(v14 * v11) + v13;
  v16 = (float)(v14 * v10) + v13;
  v17 = (float)(v14 * v2) + v13;
  v18 = hsl[2];
  if ( v18 >= 0.5 )
  {
    out->_color[0] = (int)(float)((float)((float)((float)((float)(1.0 - v18) * v15) + (float)(v18 * 2.0)) - 1.0) * 255.0);
    out->_color[1] = (int)(float)((float)((float)((float)((float)(1.0 - hsl[2]) * v16) + (float)(hsl[2] * 2.0)) - 1.0)
                                * 255.0);
    out->_color[2] = (int)(float)((float)((float)((float)((float)(1.0 - hsl[2]) * v17) + (float)(hsl[2] * 2.0)) - 1.0)
                                * 255.0);
  }
  else
  {
    out->_color[0] = (int)(float)((float)(v18 * 255.0) * v15);
    out->_color[1] = (int)(float)((float)(hsl[2] * 255.0) * v16);
    out->_color[2] = (int)(float)((float)(hsl[2] * 255.0) * v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B60
// Name: public: static void CHeatMap::BuildLookup(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHeatMap::BuildLookup()
{
  Color *v0; // edx
  int i; // esi
  float hsl[3]; // [esp+0h] [ebp-10h] BYREF
  float flValue; // [esp+Ch] [ebp-4h]

  v0 = (Color *)operator new(nSize: 0x320u);
  if ( v0 != nullptr )
    memset(v0, 0, 0x320u);
  else
    v0 = nullptr;
  g_pHeatMapColors = v0;
  g_pHeatMapFastSquareRoot = (float *)operator new(nSize: 0x320u);
  for ( i = 0; i < 200; ++i )
  {
    flValue = (float)i * 0.0050251256;
    hsl[0] = 240.0 - (float)((float)(1.0 - flValue) * 240.0);
    hsl[1] = 1.0;
    hsl[2] = 0.5;
    CHeatMap::HSLToRGB(out: &g_pHeatMapColors[i], hsl);
    g_pHeatMapFastSquareRoot[i] = fsqrt(flValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C30
// Name: public: static void CHeatMap::DeleteLookup(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHeatMap::DeleteLookup()
{
  free(pMem: g_pHeatMapColors);
  free(pMem: g_pHeatMapFastSquareRoot);
  g_pHeatMapColors = nullptr;
  g_pHeatMapFastSquareRoot = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: void DrawColoredRect(struct Image_t __near *,int,int,int,int,class Color const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawColoredRect(Image_t *image, int x, int y, int w, int h, const Color *rgb, float flAlpha)
{
  float v7; // xmm0_4
  int v8; // ecx
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  unsigned __int8 *v13; // eax
  int v14; // edi
  int v15; // ecx
  int xa; // [esp+Ch] [ebp+Ch]
  int wa; // [esp+14h] [ebp+14h]
  int xx; // [esp+20h] [ebp+20h]

  v7 = flAlpha;
  if ( flAlpha >= 0.0 )
  {
    if ( flAlpha > 1.0 )
      v7 = 1.0;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = x;
  v9 = x + w;
  xx = x;
  wa = v9;
  if ( x < v9 )
  {
    v10 = y;
    do
    {
      if ( v8 >= 0 && v8 < image->w )
      {
        v11 = v10 + h;
        v12 = v10;
        xa = v10 + h;
        if ( v10 < v10 + h )
        {
          do
          {
            if ( v12 >= 0 && v12 < image->h )
            {
              v13 = &image->data[3 * v8 + 3 * v12 * image->w];
              v14 = 3;
              v15 = (char *)rgb - (char *)v13;
              do
              {
                *v13 = (int)(float)((float)((float)v13[v15] * v7) + (float)((float)*v13 * (float)(1.0 - v7)));
                ++v13;
                --v14;
              }
              while ( v14 != 0 );
              v10 = y;
              v8 = xx;
              v11 = xa;
            }
            ++v12;
          }
          while ( v12 < v11 );
          v9 = wa;
        }
      }
      xx = ++v8;
    }
    while ( v8 < v9 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DE0
// Name: public: void CHeatMap::GenerateAndSaveImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHeatMap::GenerateAndSaveImage(CHeatMap *this)
{
  int v2; // edi
  int v3; // ecx
  float *v4; // ebx
  float v5; // xmm1_4
  int v6; // eax
  int v7; // edi
  float v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  int m_Size; // ebx
  CHeatMapPoint *v13; // eax
  int v14; // edx
  int m_nRadius; // eax
  int v16; // ecx
  int v17; // ecx
  int w; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // ebx
  float m_flMaxValue; // xmm1_4
  int v24; // ecx
  int v25; // edi
  float v26; // xmm0_4
  int v27; // ebx
  float flAlpha; // xmm0_4
  float v29; // xmm0_4
  float *flOneOverMax; // [esp+10h] [ebp-2Ch]
  const Color *col; // [esp+14h] [ebp-28h]
  const Color *cola; // [esp+14h] [ebp-28h]
  Color *colb; // [esp+14h] [ebp-28h]
  int ypos; // [esp+18h] [ebp-24h]
  int yposa; // [esp+18h] [ebp-24h]
  float *info; // [esp+1Ch] [ebp-20h]
  float *slot; // [esp+20h] [ebp-1Ch]
  float *slota; // [esp+20h] [ebp-1Ch]
  float *slotb; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  int ia; // [esp+24h] [ebp-18h]
  float ooRadiusSqr; // [esp+28h] [ebp-14h]
  float *ooRadiusSqra; // [esp+28h] [ebp-14h]
  float *ooRadiusSqrb; // [esp+28h] [ebp-14h]
  int ooRadiusSqrc; // [esp+28h] [ebp-14h]
  float *y; // [esp+2Ch] [ebp-10h]
  int ya; // [esp+2Ch] [ebp-10h]
  int yb; // [esp+2Ch] [ebp-10h]
  float *contribution; // [esp+30h] [ebp-Ch]
  float *iProgress; // [esp+34h] [ebp-8h]
  int iProgressa; // [esp+34h] [ebp-8h]
  int iProgressb; // [esp+34h] [ebp-8h]
  Color black; // [esp+38h] [ebp-4h] BYREF

  info = (float *)operator new(nSize: 4 * this->m_Image.h * this->m_Image.w);
  _V_memset(dest: info, fill: 0, count: 4 * this->m_Image.h * this->m_Image.w);
  v2 = 2 * this->m_nRadius + 1;
  ooRadiusSqr = 1.0 / this->m_flRadiusSqr;
  ypos = v2;
  contribution = (float *)operator new(nSize: 4 * v2 * v2);
  _V_memset(dest: contribution, fill: 0, count: 4 * v2 * v2);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = contribution;
    v5 = ooRadiusSqr;
    i = (int)contribution;
    slot = &contribution[v2];
    do
    {
      v6 = 0;
      if ( v2 >= 4 )
      {
        col = (const Color *)(16 * v2);
        y = (float *)i;
        ooRadiusSqra = &v4[2 * v2 + v2 + v3];
        black = (Color)&v4[2 * v2 + v3];
        iProgress = slot;
        do
        {
          v7 = (v3 - this->m_nRadius) * (v3 - this->m_nRadius) + (v6 - this->m_nRadius) * (v6 - this->m_nRadius);
          if ( this->m_flRadiusSqr > (float)v7 )
            *y = 1.0 - (float)((float)v7 * v5);
          v8 = (float)((v3 - this->m_nRadius) * (v3 - this->m_nRadius)
                     + (v6 - this->m_nRadius + 1) * (v6 - this->m_nRadius + 1));
          if ( this->m_flRadiusSqr > v8 )
            *iProgress = 1.0 - (float)(v8 * v5);
          v9 = (float)((v3 - this->m_nRadius) * (v3 - this->m_nRadius)
                     + (v6 - this->m_nRadius + 2) * (v6 - this->m_nRadius + 2));
          if ( this->m_flRadiusSqr > v9 )
            **(float **)&black = 1.0 - (float)(v9 * v5);
          v10 = (float)((v3 - this->m_nRadius) * (v3 - this->m_nRadius)
                      + (v6 - this->m_nRadius + 3) * (v6 - this->m_nRadius + 3));
          if ( this->m_flRadiusSqr > v10 )
            *ooRadiusSqra = 1.0 - (float)(v10 * v5);
          y = (float *)((int)y + (_DWORD)col);
          iProgress = (float *)((int)iProgress + (_DWORD)col);
          *(_DWORD *)&black += col;
          ooRadiusSqra = (float *)((int)ooRadiusSqra + (_DWORD)col);
          v2 = ypos;
          v6 += 4;
        }
        while ( v6 < ypos - 3 );
        v4 = contribution;
      }
      if ( v6 < v2 )
      {
        ooRadiusSqrb = &v4[v3 + v2 * v6];
        do
        {
          v11 = (float)((v3 - this->m_nRadius) * (v3 - this->m_nRadius) + (v6 - this->m_nRadius)
                                                                        * (v6 - this->m_nRadius));
          if ( this->m_flRadiusSqr > v11 )
            *ooRadiusSqrb = 1.0 - (float)(v11 * v5);
          v2 = ypos;
          ooRadiusSqrb += ypos;
          ++v6;
        }
        while ( v6 < ypos );
        v4 = contribution;
      }
      i += 4;
      ++slot;
      ++v3;
    }
    while ( v3 < v2 );
  }
  _Plat_FloatTime(a1: v3);
  m_Size = this->m_Points.m_Size;
  ya = m_Size;
  iProgressa = 0;
  if ( StatsMap()->m_bVerbose )
    _Msg(a1: "Accumulating [");
  ia = 0;
  if ( m_Size > 0 )
  {
    ooRadiusSqrc = 0;
    do
    {
      v13 = &this->m_Points.m_Memory.m_pMemory[ooRadiusSqrc];
      v14 = (int)v13->y;
      cola = (const Color *)v13;
      slota = (float *)(int)v13->x;
      yposa = v14;
      for ( black = (Color)((v14 - this->m_nRadius) & ((v14 - this->m_nRadius < 0) - 1)); ; ++*(_DWORD *)&black )
      {
        m_nRadius = this->m_nRadius;
        v16 = m_nRadius + v14;
        if ( m_nRadius + v14 >= this->m_Image.h - 1 )
          v16 = this->m_Image.h - 1;
        if ( *(_DWORD *)&black > v16 )
          break;
        v17 = (int)slota - m_nRadius < 0 ? 0 : (unsigned int)slota - m_nRadius;
        if ( v17 <= (int)slota + m_nRadius )
        {
          do
          {
            w = this->m_Image.w;
            if ( v17 >= w )
              break;
            flOneOverMax = &info[v17 + *(_DWORD *)&black * w];
            v19 = contribution[v17 + this->m_nRadius + v2 * (*(_DWORD *)&black + this->m_nRadius - v14) - (_DWORD)slota];
            if ( v19 > 0.0 )
            {
              v20 = (float)(*(float *)&cola[2] * v19) + *flOneOverMax;
              *flOneOverMax = v20;
              if ( v20 > this->m_flMaxValue )
                this->m_flMaxValue = v20;
            }
            v14 = yposa;
            ++v17;
          }
          while ( v17 <= (int)slota + this->m_nRadius );
        }
      }
      if ( StatsMap()->m_bVerbose )
      {
        v21 = (float)((float)ia / (float)ya) * 60.0;
        if ( iProgressa < (int)v21 )
        {
          v22 = (int)v21 - iProgressa;
          iProgressa = (int)v21;
          do
          {
            _Msg(a1: ".");
            --v22;
          }
          while ( v22 != 0 );
        }
      }
      ++ooRadiusSqrc;
      ++ia;
    }
    while ( ia < ya );
  }
  if ( StatsMap()->m_bVerbose )
    _Msg(a1: "]\n");
  m_flMaxValue = this->m_flMaxValue;
  v24 = 0;
  iProgressb = 0;
  if ( m_flMaxValue > 0.0 )
  {
    black = 0;
    yb = 0;
    if ( this->m_Image.h > 0 )
    {
      do
      {
        v25 = 0;
        for ( slotb = &info[v24 * this->m_Image.w]; v25 < this->m_Image.w; ++v25 )
        {
          v26 = *slotb * (float)(1.0 / m_flMaxValue);
          v27 = (int)(float)((float)(v26 * 199.0) + 0.5);
          if ( v27 >= 0 )
          {
            if ( v27 > 199 )
              v27 = 199;
          }
          else
          {
            v27 = 0;
          }
          colb = &g_pHeatMapColors[v27];
          DrawColoredRect(image: &this->m_Image, x: v25, y: v24, w: 1, h: 1, rgb: &black, flAlpha: v26 * v26);
          flAlpha = g_pHeatMapFastSquareRoot[v27];
          if ( flAlpha != 0.0 && flAlpha <= 0.33000001 )
            flAlpha = 0.33000001;
          DrawColoredRect(image: &this->m_Image, x: v25, y: yb, w: 1, h: 1, rgb: colb, flAlpha);
          ++slotb;
          v24 = yb;
        }
        v29 = (float)((float)v24 / (float)this->m_Image.h) * 60.0;
        if ( iProgressb < (int)v29 )
          iProgressb = (int)v29;
        yb = ++v24;
      }
      while ( v24 < this->m_Image.h );
    }
  }
  _Plat_FloatTime(a1: v24);
  free(pMem: contribution);
  free(pMem: info);
  WriteJPeg(filename: this->m_szOutputImage, image: &this->m_Image);
  WriteJPegThumbnail(filename: this->m_szOutputImageThumbnail, image: &this->m_Image, width: 100, height: 100);
}

//------------------------------------------------------------------------------
// Address: 0x004024D0
// Name: public: CHeatMap::CHeatMap(char const __near *,char const __near *,char const __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
CHeatMap *__userpurge CHeatMap::CHeatMap@<eax>(
        CHeatMap *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pszProductName,
        const char *pszMapName,
        const char *pszOutputName,
        int map_x,
        int map_y,
        float map_scale)
{
  CStatsMap *v11; // eax
  CStatsMap *v12; // eax
  CStatsMap *v13; // eax
  CStatsMap *v14; // eax
  CStatsMap *v15; // eax
  CStatsMap *v16; // eax
  char *m_szImageOutputDir; // [esp-10h] [ebp-124h]
  char *v19; // [esp-10h] [ebp-124h]
  char buffer[260]; // [esp+0h] [ebp-114h] BYREF
  CHeatMap *v22; // [esp+104h] [ebp-10h]
  int v23; // [esp+110h] [ebp-4h]

  this->m_iMapX = map_x;
  this->__vftable = (CHeatMap_vtbl *)&CHeatMap::`vftable';
  this->m_iMapY = map_y;
  this->m_flMapScale = map_scale;
  v22 = this;
  this->m_Points.m_Memory.m_pMemory = nullptr;
  this->m_Points.m_Memory.m_nAllocationCount = 0;
  this->m_Points.m_Memory.m_nGrowSize = 0;
  this->m_Points.m_Size = 0;
  this->m_Points.m_pElements = nullptr;
  this->m_Image.data = nullptr;
  this->m_Image.h = 0;
  this->m_Image.w = 0;
  this->m_flMaxValue = 0.0;
  this->m_flRadius = 0.0;
  this->m_nRadius = 0;
  this->m_flRadiusSqr = 0.0;
  v23 = 0;
  if ( g_pHeatMapColors == nullptr )
    CHeatMap::BuildLookup();
  v11 = StatsMap();
  V_snprintf(
    pDest: this->m_szOverviewImage,
    maxLen: 260,
    pFormat: "%s/%s/%s.bmp",
    v11->m_szImageInputDir,
    pszProductName,
    pszMapName);
  V_FixSlashes(pname: this->m_szOverviewImage, separator: 92);
  _V_strlower(start: this->m_szOverviewImage);
  v12 = StatsMap();
  V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s", v12->m_szImageOutputDir);
  ((void (__thiscall *)(IFileSystem *, char *, _DWORD, int, int, int))g_pFullFileSystem->CreateDirHierarchy)(
    a1: g_pFullFileSystem,
    a2: buffer,
    a3: 0,
    a4: a3,
    a5: a4,
    a6: a2);
  v13 = StatsMap();
  V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/%s", v13->m_szImageOutputDir, pszProductName);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buffer, a3: nullptr);
  v14 = StatsMap();
  V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/%s/thumbs", v14->m_szImageOutputDir, pszProductName);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buffer, a3: nullptr);
  if ( StatsMap()->m_bSteamBeta )
  {
    v15 = StatsMap();
    V_snprintf(
      pDest: this->m_szOutputImage,
      maxLen: 260,
      pFormat: "%s/%s/beta_%s_%s",
      v15->m_szImageOutputDir,
      pszProductName,
      pszMapName,
      pszOutputName);
    m_szImageOutputDir = StatsMap()->m_szImageOutputDir;
    V_snprintf(
      pDest: this->m_szOutputImageThumbnail,
      maxLen: 260,
      pFormat: "%s/%s/thumbs/beta_%s_%s",
      m_szImageOutputDir,
      pszProductName,
      pszMapName,
      pszOutputName);
  }
  else
  {
    v16 = StatsMap();
    V_snprintf(
      pDest: this->m_szOutputImage,
      maxLen: 260,
      pFormat: "%s/%s/%s_%s",
      v16->m_szImageOutputDir,
      pszProductName,
      pszMapName,
      pszOutputName);
    v19 = StatsMap()->m_szImageOutputDir;
    V_snprintf(
      pDest: this->m_szOutputImageThumbnail,
      maxLen: 260,
      pFormat: "%s/%s/thumbs/%s_%s",
      v19,
      pszProductName,
      pszMapName,
      pszOutputName);
  }
  V_FixSlashes(pname: this->m_szOutputImage, separator: 92);
  _V_strlower(start: this->m_szOutputImage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402720
// Name: public: virtual CHeatMap::~CHeatMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHeatMap::~CHeatMap(CHeatMap *this)
{
  unsigned __int8 *data; // eax
  CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int> > *p_m_Points; // esi
  CHeatMapPoint *m_pMemory; // eax

  this->__vftable = (CHeatMap_vtbl *)&CHeatMap::`vftable';
  data = this->m_Image.data;
  if ( data != nullptr )
    free(pMem: data);
  p_m_Points = &this->m_Points;
  p_m_Points->m_Size = 0;
  if ( p_m_Points->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Points->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Points->m_Memory.m_pMemory);
      p_m_Points->m_Memory.m_pMemory = nullptr;
    }
    p_m_Points->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_Points->m_Memory.m_pMemory;
  p_m_Points->m_pElements = p_m_Points->m_Memory.m_pMemory;
  if ( p_m_Points->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_Points->m_Memory.m_pMemory = nullptr;
    }
    p_m_Points->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402800
// Name: public: void CHeatMap::AddPoint(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHeatMap::AddPoint(CHeatMap *this, float x, float y, float strength)
{
  int m_Size; // edx
  CHeatMapPoint point; // [esp+0h] [ebp-Ch] BYREF

  m_Size = this->m_Points.m_Size;
  point.x = x;
  point.y = y;
  point.strength = strength;
  CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int>>::InsertBefore(
    this: &this->m_Points,
    elem: m_Size,
    src: &point);
}
