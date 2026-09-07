// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vguimatsurface/clip2d.cpp
// Functions: 17
// ============================================================

#include "vguimatsurface\clip2d.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: void EnableScissor(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableScissor(bool enable)
{
  g_bScissor = enable;
}

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: void SetScissorRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetScissorRect(int left, int top, int right, int bottom)
{
  if ( g_ScissorRect.left != left
    || g_ScissorRect.right != right
    || g_ScissorRect.top != top
    || g_ScissorRect.bottom != bottom )
  {
    g_ScissorRect.left = left;
    g_ScissorRect.top = top;
    g_ScissorRect.right = right;
    g_ScissorRect.bottom = bottom;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001060
// Name: float InterpTCoord(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl InterpTCoord(float val, float mins, float maxs, float tMin, float tMax)
{
  double v5; // st6

  if ( mins == maxs )
    v5 = (tMax - tMin) * 0.5;
  else
    v5 = (tMax - tMin) * (float)((float)(val - mins) / (float)(maxs - mins));
  return tMin + v5;
}

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: bool ClipRect(struct FontVertex_t const __near &,struct FontVertex_t const __near &,struct FontVertex_t __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipRect(const FontVertex_t *inUL, const FontVertex_t *inLR, FontVertex_t *pOutUL, FontVertex_t *pOutLR)
{
  float y; // xmm1_4
  float v5; // xmm1_4

  if ( g_bScissor )
  {
    if ( (float)g_ScissorRect.left <= inUL->m_Position.x )
      pOutUL->m_Position.x = inUL->m_Position.x;
    else
      pOutUL->m_Position.x = (float)g_ScissorRect.left;
    if ( inLR->m_Position.x < (float)g_ScissorRect.right )
      pOutLR->m_Position.x = inLR->m_Position.x;
    else
      pOutLR->m_Position.x = (float)g_ScissorRect.right;
    y = inUL->m_Position.y;
    if ( (float)g_ScissorRect.top <= y )
      pOutUL->m_Position.y = y;
    else
      pOutUL->m_Position.y = (float)g_ScissorRect.top;
    v5 = inLR->m_Position.y;
    if ( v5 < (float)g_ScissorRect.bottom )
      pOutLR->m_Position.y = v5;
    else
      pOutLR->m_Position.y = (float)g_ScissorRect.bottom;
    if ( pOutUL->m_Position.x > pOutLR->m_Position.x || pOutUL->m_Position.y > pOutLR->m_Position.y )
    {
      return 0;
    }
    else
    {
      if ( g_bStretchTexture )
      {
        pOutUL->m_TexCoord = inUL->m_TexCoord;
        pOutLR->m_TexCoord = inLR->m_TexCoord;
      }
      else
      {
        pOutUL->m_TexCoord.x = InterpTCoord(
                                 val: pOutUL->m_Position.x,
                                 mins: inUL->m_Position.x,
                                 maxs: inLR->m_Position.x,
                                 tMin: inUL->m_TexCoord.x,
                                 tMax: inLR->m_TexCoord.x);
        pOutLR->m_TexCoord.x = InterpTCoord(
                                 val: pOutLR->m_Position.x,
                                 mins: inUL->m_Position.x,
                                 maxs: inLR->m_Position.x,
                                 tMin: inUL->m_TexCoord.x,
                                 tMax: inLR->m_TexCoord.x);
        pOutUL->m_TexCoord.y = InterpTCoord(
                                 val: pOutUL->m_Position.y,
                                 mins: inUL->m_Position.y,
                                 maxs: inLR->m_Position.y,
                                 tMin: inUL->m_TexCoord.y,
                                 tMax: inLR->m_TexCoord.y);
        pOutLR->m_TexCoord.y = InterpTCoord(
                                 val: pOutLR->m_Position.y,
                                 mins: inUL->m_Position.y,
                                 maxs: inLR->m_Position.y,
                                 tMin: inUL->m_TexCoord.y,
                                 tMax: inLR->m_TexCoord.y);
      }
      return 1;
    }
  }
  else
  {
    *pOutUL = *inUL;
    *pOutLR = *inLR;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: bool ClipLineToPlane<class CClipTop>(class CClipTop __near &,struct FontVertex_t const __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipLineToPlane<CClipTop>(CClipTop *clipper, const FontVertex_t *pInVerts, FontVertex_t *pOutVerts)
{
  float top; // xmm0_4
  unsigned int v5; // ecx
  float v6; // xmm0_4
  FontVertex_t *v7; // edx

  top = (float)g_ScissorRect.top;
  if ( pInVerts->m_Position.y >= (float)g_ScissorRect.top )
  {
    if ( pInVerts[1].m_Position.y >= top )
    {
      *pOutVerts = *pInVerts;
      pOutVerts[1] = pInVerts[1];
      return 1;
    }
  }
  else if ( pInVerts[1].m_Position.y < top )
  {
    return 0;
  }
  v5 = 16 * (pInVerts->m_Position.y < (float)g_ScissorRect.top);
  pOutVerts[v5 / 0x10] = pInVerts[v5 / 0x10];
  v6 = (float)(top - pInVerts->m_Position.y) / (float)(pInVerts[1].m_Position.y - pInVerts->m_Position.y);
  v7 = &pOutVerts[v5 / 0xFFFFFFF0];
  v7[1].m_Position.x = (float)((float)(pInVerts[1].m_Position.x - pInVerts->m_Position.x) * v6) + pInVerts->m_Position.x;
  v7[1].m_Position.y = (float)((float)(pInVerts[1].m_Position.y - pInVerts->m_Position.y) * v6) + pInVerts->m_Position.y;
  v7[1].m_TexCoord.x = (float)((float)(pInVerts[1].m_TexCoord.x - pInVerts->m_TexCoord.x) * v6) + pInVerts->m_TexCoord.x;
  v7[1].m_TexCoord.y = (float)((float)(pInVerts[1].m_TexCoord.y - pInVerts->m_TexCoord.y) * v6) + pInVerts->m_TexCoord.y;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001410
// Name: bool ClipLineToPlane<class CClipBottom>(class CClipBottom __near &,struct FontVertex_t const __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipLineToPlane<CClipBottom>(CClipBottom *clipper, const FontVertex_t *pInVerts, FontVertex_t *pOutVerts)
{
  float bottom; // xmm2_4
  unsigned int v5; // ecx
  float v6; // xmm0_4
  FontVertex_t *v7; // edx

  bottom = (float)g_ScissorRect.bottom;
  if ( (float)g_ScissorRect.bottom > pInVerts->m_Position.y )
  {
    if ( bottom > pInVerts[1].m_Position.y )
    {
      *pOutVerts = *pInVerts;
      pOutVerts[1] = pInVerts[1];
      return 1;
    }
  }
  else if ( bottom <= pInVerts[1].m_Position.y )
  {
    return 0;
  }
  v5 = 16 * ((float)g_ScissorRect.bottom <= pInVerts->m_Position.y);
  pOutVerts[v5 / 0x10] = pInVerts[v5 / 0x10];
  v6 = (float)(pInVerts->m_Position.y - bottom) / (float)(pInVerts->m_Position.y - pInVerts[1].m_Position.y);
  v7 = &pOutVerts[v5 / 0xFFFFFFF0];
  v7[1].m_Position.x = (float)((float)(pInVerts[1].m_Position.x - pInVerts->m_Position.x) * v6) + pInVerts->m_Position.x;
  v7[1].m_Position.y = (float)((float)(pInVerts[1].m_Position.y - pInVerts->m_Position.y) * v6) + pInVerts->m_Position.y;
  v7[1].m_TexCoord.x = (float)((float)(pInVerts[1].m_TexCoord.x - pInVerts->m_TexCoord.x) * v6) + pInVerts->m_TexCoord.x;
  v7[1].m_TexCoord.y = (float)((float)(pInVerts[1].m_TexCoord.y - pInVerts->m_TexCoord.y) * v6) + pInVerts->m_TexCoord.y;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001530
// Name: bool ClipLineToPlane<class CClipLeft>(class CClipLeft __near &,struct FontVertex_t const __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipLineToPlane<CClipLeft>(CClipLeft *clipper, const FontVertex_t *pInVerts, FontVertex_t *pOutVerts)
{
  float left; // xmm3_4
  unsigned int v5; // ecx
  float x; // xmm1_4
  FontVertex_t *v7; // edx
  float v8; // xmm0_4

  left = (float)g_ScissorRect.left;
  if ( pInVerts->m_Position.x >= (float)g_ScissorRect.left )
  {
    if ( pInVerts[1].m_Position.x >= left )
    {
      *pOutVerts = *pInVerts;
      pOutVerts[1] = pInVerts[1];
      return 1;
    }
  }
  else if ( pInVerts[1].m_Position.x < left )
  {
    return 0;
  }
  v5 = 16 * (pInVerts->m_Position.x < (float)g_ScissorRect.left);
  pOutVerts[v5 / 0x10] = pInVerts[v5 / 0x10];
  x = pInVerts[1].m_Position.x;
  v7 = &pOutVerts[v5 / 0xFFFFFFF0];
  v8 = (float)(pInVerts->m_Position.x - left) / (float)(pInVerts->m_Position.x - x);
  v7[1].m_Position.x = (float)((float)(x - pInVerts->m_Position.x) * v8) + pInVerts->m_Position.x;
  v7[1].m_Position.y = (float)((float)(pInVerts[1].m_Position.y - pInVerts->m_Position.y) * v8) + pInVerts->m_Position.y;
  v7[1].m_TexCoord.x = (float)((float)(pInVerts[1].m_TexCoord.x - pInVerts->m_TexCoord.x) * v8) + pInVerts->m_TexCoord.x;
  v7[1].m_TexCoord.y = (float)((float)(pInVerts[1].m_TexCoord.y - pInVerts->m_TexCoord.y) * v8) + pInVerts->m_TexCoord.y;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001650
// Name: bool ClipLineToPlane<class CClipRight>(class CClipRight __near &,struct FontVertex_t const __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipLineToPlane<CClipRight>(CClipRight *clipper, const FontVertex_t *pInVerts, FontVertex_t *pOutVerts)
{
  float right; // xmm1_4
  unsigned int v5; // ecx
  float v6; // xmm1_4
  FontVertex_t *v7; // edx

  right = (float)g_ScissorRect.right;
  if ( (float)g_ScissorRect.right > pInVerts->m_Position.x )
  {
    if ( right > pInVerts[1].m_Position.x )
    {
      *pOutVerts = *pInVerts;
      pOutVerts[1] = pInVerts[1];
      return 1;
    }
  }
  else if ( right <= pInVerts[1].m_Position.x )
  {
    return 0;
  }
  v5 = 16 * ((float)g_ScissorRect.right <= pInVerts->m_Position.x);
  pOutVerts[v5 / 0x10] = pInVerts[v5 / 0x10];
  v6 = (float)(right - pInVerts->m_Position.x) / (float)(pInVerts[1].m_Position.x - pInVerts->m_Position.x);
  v7 = &pOutVerts[v5 / 0xFFFFFFF0];
  v7[1].m_Position.x = (float)((float)(pInVerts[1].m_Position.x - pInVerts->m_Position.x) * v6) + pInVerts->m_Position.x;
  v7[1].m_Position.y = (float)((float)(pInVerts[1].m_Position.y - pInVerts->m_Position.y) * v6) + pInVerts->m_Position.y;
  v7[1].m_TexCoord.x = (float)((float)(pInVerts[1].m_TexCoord.x - pInVerts->m_TexCoord.x) * v6) + pInVerts->m_TexCoord.x;
  v7[1].m_TexCoord.y = (float)((float)(pInVerts[1].m_TexCoord.y - pInVerts->m_TexCoord.y) * v6) + pInVerts->m_TexCoord.y;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001770
// Name: ScreenClip_CClipTop_
// Source: json
//------------------------------------------------------------------------------
void __usercall ScreenClip_CClipTop_(ScreenClipState_t *clip@<esi>)
{
  int m_iClipCount; // ecx
  int v2; // edi
  FontVertex_t **m_pMemory; // edx
  float *p_x; // ecx
  float top; // xmm2_4
  FontVertex_t **v6; // ebx
  float *v7; // eax
  int v8; // edx
  float v9; // xmm0_4
  FontVertex_t *v10; // edx
  float v11; // xmm3_4
  int m_iTempCount; // edx
  float v13; // xmm0_4
  FontVertex_t *v14; // edx
  float v15; // xmm3_4
  int v16; // ecx
  FontVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  int v18; // [esp+4h] [ebp-10h]
  FontVertex_t **pDestVert; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_iClipCount = clip->m_iClipCount;
  v18 = m_iClipCount;
  if ( m_iClipCount >= 3 )
  {
    v2 = 0;
    m_pMemory = clip->m_ppClipVertices[clip->m_iCurrVert].m_Memory.m_pMemory;
    p_x = &m_pMemory[m_iClipCount - 1]->m_Position.x;
    top = (float)g_ScissorRect.top;
    v6 = clip->m_ppClipVertices[clip->m_iCurrVert == 0].m_Memory.m_pMemory;
    pSrcVert = m_pMemory;
    pDestVert = v6;
    startInside = p_x[1] >= (float)g_ScissorRect.top;
    i = 0;
    if ( v18 > 0 )
    {
      while ( 1 )
      {
        v7 = &m_pMemory[i]->m_Position.x;
        if ( v7[1] < top )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_12;
          m_iTempCount = clip->m_iTempCount;
          clip->m_iTempCount = m_iTempCount + 1;
          v6 = pDestVert;
          v13 = (float)(top - p_x[1]) / (float)(v7[1] - p_x[1]);
          v14 = &clip->m_pTempVertices.m_Memory.m_pMemory[m_iTempCount];
          v14->m_Position.x = (float)((float)(*v7 - *p_x) * v13) + *p_x;
          v14->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v13) + p_x[1];
          v14->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v13) + p_x[2];
          v15 = (float)((float)(v7[3] - p_x[3]) * v13) + p_x[3];
          pDestVert[v2] = v14;
          v14->m_TexCoord.y = v15;
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v8 = clip->m_iTempCount;
            clip->m_iTempCount = v8 + 1;
            v6 = pDestVert;
            v9 = (float)(top - p_x[1]) / (float)(v7[1] - p_x[1]);
            v10 = &clip->m_pTempVertices.m_Memory.m_pMemory[v8];
            ++v2;
            v10->m_Position.x = (float)((float)(*v7 - *p_x) * v9) + *p_x;
            v10->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v9) + p_x[1];
            v10->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v9) + p_x[2];
            v11 = (float)((float)(v7[3] - p_x[3]) * v9) + p_x[3];
            pDestVert[v2 - 1] = v10;
            v10->m_TexCoord.y = v11;
          }
          v6[v2] = (FontVertex_t *)v7;
        }
        ++v2;
LABEL_12:
        ++i;
        p_x = v7;
        startInside = endInside;
        if ( i >= v18 )
          break;
        m_pMemory = pSrcVert;
      }
    }
    v16 = 1 - clip->m_iCurrVert;
    clip->m_iClipCount = v2;
    clip->m_iCurrVert = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: ScreenClip_CClipBottom_
// Source: json
//------------------------------------------------------------------------------
void __usercall ScreenClip_CClipBottom_(ScreenClipState_t *clip@<esi>)
{
  int m_iClipCount; // ecx
  int v2; // edi
  FontVertex_t **m_pMemory; // edx
  float *p_x; // ecx
  float bottom; // xmm2_4
  FontVertex_t **v6; // ebx
  float *v7; // eax
  int v8; // edx
  FontVertex_t *v9; // edx
  float v10; // xmm0_4
  float v11; // xmm3_4
  int m_iTempCount; // edx
  FontVertex_t *v13; // edx
  float v14; // xmm0_4
  float v15; // xmm3_4
  int v16; // ecx
  FontVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  int v18; // [esp+4h] [ebp-10h]
  FontVertex_t **pDestVert; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_iClipCount = clip->m_iClipCount;
  v18 = m_iClipCount;
  if ( m_iClipCount >= 3 )
  {
    v2 = 0;
    m_pMemory = clip->m_ppClipVertices[clip->m_iCurrVert].m_Memory.m_pMemory;
    p_x = &m_pMemory[m_iClipCount - 1]->m_Position.x;
    bottom = (float)g_ScissorRect.bottom;
    pSrcVert = m_pMemory;
    v6 = clip->m_ppClipVertices[clip->m_iCurrVert == 0].m_Memory.m_pMemory;
    pDestVert = v6;
    startInside = (float)g_ScissorRect.bottom > p_x[1];
    i = 0;
    if ( v18 > 0 )
    {
      while ( 1 )
      {
        v7 = &m_pMemory[i]->m_Position.x;
        if ( bottom <= v7[1] )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_12;
          m_iTempCount = clip->m_iTempCount;
          clip->m_iTempCount = m_iTempCount + 1;
          v6 = pDestVert;
          v13 = &clip->m_pTempVertices.m_Memory.m_pMemory[m_iTempCount];
          v14 = (float)(p_x[1] - bottom) / (float)(p_x[1] - v7[1]);
          v13->m_Position.x = (float)((float)(*v7 - *p_x) * v14) + *p_x;
          v13->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v14) + p_x[1];
          v13->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v14) + p_x[2];
          v15 = (float)((float)(v7[3] - p_x[3]) * v14) + p_x[3];
          pDestVert[v2] = v13;
          v13->m_TexCoord.y = v15;
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v8 = clip->m_iTempCount;
            clip->m_iTempCount = v8 + 1;
            v6 = pDestVert;
            v9 = &clip->m_pTempVertices.m_Memory.m_pMemory[v8];
            v10 = (float)(p_x[1] - bottom) / (float)(p_x[1] - v7[1]);
            v9->m_Position.x = (float)((float)(*v7 - *p_x) * v10) + *p_x;
            v9->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v10) + p_x[1];
            v9->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v10) + p_x[2];
            v11 = (float)((float)(v7[3] - p_x[3]) * v10) + p_x[3];
            pDestVert[v2] = v9;
            v9->m_TexCoord.y = v11;
            ++v2;
          }
          v6[v2] = (FontVertex_t *)v7;
        }
        ++v2;
LABEL_12:
        ++i;
        p_x = v7;
        startInside = endInside;
        if ( i >= v18 )
          break;
        m_pMemory = pSrcVert;
      }
    }
    v16 = 1 - clip->m_iCurrVert;
    clip->m_iClipCount = v2;
    clip->m_iCurrVert = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B30
// Name: ScreenClip_CClipLeft_
// Source: json
//------------------------------------------------------------------------------
void __usercall ScreenClip_CClipLeft_(ScreenClipState_t *clip@<esi>)
{
  int m_iClipCount; // edx
  int v2; // edi
  FontVertex_t **m_pMemory; // ecx
  float left; // xmm3_4
  FontVertex_t **v5; // ebx
  float *p_x; // eax
  float *v7; // ecx
  int v8; // edx
  FontVertex_t *v9; // edx
  float v10; // xmm0_4
  float v11; // xmm2_4
  int m_iTempCount; // edx
  FontVertex_t *v13; // edx
  float v14; // xmm0_4
  float v15; // xmm2_4
  int v16; // eax
  FontVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  int v18; // [esp+4h] [ebp-10h]
  FontVertex_t **pDestVert; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_iClipCount = clip->m_iClipCount;
  v18 = m_iClipCount;
  if ( m_iClipCount >= 3 )
  {
    v2 = 0;
    m_pMemory = clip->m_ppClipVertices[clip->m_iCurrVert].m_Memory.m_pMemory;
    left = (float)g_ScissorRect.left;
    pSrcVert = m_pMemory;
    v5 = clip->m_ppClipVertices[clip->m_iCurrVert == 0].m_Memory.m_pMemory;
    p_x = &m_pMemory[m_iClipCount - 1]->m_Position.x;
    pDestVert = v5;
    startInside = *p_x >= (float)g_ScissorRect.left;
    i = 0;
    while ( 1 )
    {
      v7 = &m_pMemory[i]->m_Position.x;
      if ( *v7 < left )
      {
        endInside = false;
        if ( !startInside )
          goto LABEL_12;
        m_iTempCount = clip->m_iTempCount;
        clip->m_iTempCount = m_iTempCount + 1;
        v5 = pDestVert;
        v13 = &clip->m_pTempVertices.m_Memory.m_pMemory[m_iTempCount];
        v14 = (float)(*p_x - left) / (float)(*p_x - *v7);
        v13->m_Position.x = (float)((float)(*v7 - *p_x) * v14) + *p_x;
        v13->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v14) + p_x[1];
        v13->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v14) + p_x[2];
        v15 = (float)((float)(v7[3] - p_x[3]) * v14) + p_x[3];
        pDestVert[v2] = v13;
        v13->m_TexCoord.y = v15;
      }
      else
      {
        endInside = true;
        if ( !startInside )
        {
          v8 = clip->m_iTempCount;
          clip->m_iTempCount = v8 + 1;
          v5 = pDestVert;
          v9 = &clip->m_pTempVertices.m_Memory.m_pMemory[v8];
          v10 = (float)(*p_x - left) / (float)(*p_x - *v7);
          v9->m_Position.x = (float)((float)(*v7 - *p_x) * v10) + *p_x;
          v9->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v10) + p_x[1];
          v9->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v10) + p_x[2];
          v11 = (float)((float)(v7[3] - p_x[3]) * v10) + p_x[3];
          pDestVert[v2] = v9;
          v9->m_TexCoord.y = v11;
          ++v2;
        }
        v5[v2] = (FontVertex_t *)v7;
      }
      ++v2;
LABEL_12:
      ++i;
      p_x = v7;
      startInside = endInside;
      if ( i >= v18 )
      {
        v16 = 1 - clip->m_iCurrVert;
        clip->m_iClipCount = v2;
        clip->m_iCurrVert = v16;
        return;
      }
      m_pMemory = pSrcVert;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D10
// Name: ScreenClip_CClipRight_
// Source: json
//------------------------------------------------------------------------------
void __usercall ScreenClip_CClipRight_(ScreenClipState_t *clip@<esi>)
{
  int m_iClipCount; // edx
  int v2; // edi
  FontVertex_t **m_pMemory; // ecx
  float right; // xmm3_4
  FontVertex_t **v5; // ebx
  float *p_x; // eax
  float *v7; // ecx
  int v8; // edx
  FontVertex_t *v9; // edx
  float v10; // xmm0_4
  float v11; // xmm2_4
  int m_iTempCount; // edx
  FontVertex_t *v13; // edx
  float v14; // xmm0_4
  float v15; // xmm2_4
  int v16; // eax
  FontVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  int v18; // [esp+4h] [ebp-10h]
  FontVertex_t **pDestVert; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_iClipCount = clip->m_iClipCount;
  v18 = m_iClipCount;
  if ( m_iClipCount >= 3 )
  {
    v2 = 0;
    m_pMemory = clip->m_ppClipVertices[clip->m_iCurrVert].m_Memory.m_pMemory;
    right = (float)g_ScissorRect.right;
    pSrcVert = m_pMemory;
    v5 = clip->m_ppClipVertices[clip->m_iCurrVert == 0].m_Memory.m_pMemory;
    p_x = &m_pMemory[m_iClipCount - 1]->m_Position.x;
    pDestVert = v5;
    startInside = (float)g_ScissorRect.right > *p_x;
    i = 0;
    while ( 1 )
    {
      v7 = &m_pMemory[i]->m_Position.x;
      if ( right <= *v7 )
      {
        endInside = false;
        if ( !startInside )
          goto LABEL_12;
        m_iTempCount = clip->m_iTempCount;
        clip->m_iTempCount = m_iTempCount + 1;
        v5 = pDestVert;
        v13 = &clip->m_pTempVertices.m_Memory.m_pMemory[m_iTempCount];
        v14 = (float)(right - *p_x) / (float)(*v7 - *p_x);
        v13->m_Position.x = (float)((float)(*v7 - *p_x) * v14) + *p_x;
        v13->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v14) + p_x[1];
        v13->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v14) + p_x[2];
        v15 = (float)((float)(v7[3] - p_x[3]) * v14) + p_x[3];
        pDestVert[v2] = v13;
        v13->m_TexCoord.y = v15;
      }
      else
      {
        endInside = true;
        if ( !startInside )
        {
          v8 = clip->m_iTempCount;
          clip->m_iTempCount = v8 + 1;
          v5 = pDestVert;
          v9 = &clip->m_pTempVertices.m_Memory.m_pMemory[v8];
          v10 = (float)(right - *p_x) / (float)(*v7 - *p_x);
          v9->m_Position.x = (float)((float)(*v7 - *p_x) * v10) + *p_x;
          v9->m_Position.y = (float)((float)(v7[1] - p_x[1]) * v10) + p_x[1];
          v9->m_TexCoord.x = (float)((float)(v7[2] - p_x[2]) * v10) + p_x[2];
          v11 = (float)((float)(v7[3] - p_x[3]) * v10) + p_x[3];
          pDestVert[v2] = v9;
          v9->m_TexCoord.y = v11;
          ++v2;
        }
        v5[v2] = (FontVertex_t *)v7;
      }
      ++v2;
LABEL_12:
      ++i;
      p_x = v7;
      startInside = endInside;
      if ( i >= v18 )
      {
        v16 = 1 - clip->m_iCurrVert;
        clip->m_iClipCount = v2;
        clip->m_iCurrVert = v16;
        return;
      }
      m_pMemory = pSrcVert;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: bool ClipLine(struct FontVertex_t const __near *,struct FontVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipLine(const FontVertex_t *pInVerts, FontVertex_t *pOutVerts)
{
  char result; // al
  FontVertex_t tempVerts[2]; // [esp+0h] [ebp-24h] BYREF
  CClipBottom bottom; // [esp+23h] [ebp-1h] BYREF

  if ( !g_bScissor || g_bFullScreenScissor )
  {
    *pOutVerts = *pInVerts;
    pOutVerts[1] = pInVerts[1];
    return 1;
  }
  else
  {
    result = ClipLineToPlane<CClipTop>(clipper: (CClipTop *)&bottom, pInVerts, pOutVerts: tempVerts);
    if ( result != 0 )
      return ClipLineToPlane<CClipBottom>(clipper: &bottom, pInVerts: tempVerts, pOutVerts) != 0
          && ClipLineToPlane<CClipLeft>(clipper: (CClipLeft *)&bottom, pInVerts: pOutVerts, pOutVerts: tempVerts) != 0
          && ClipLineToPlane<CClipRight>(clipper: (CClipRight *)&bottom, pInVerts: tempVerts, pOutVerts) != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: ScreenClipState_t::~ScreenClipState_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScreenClipState_t::~ScreenClipState_t(ScreenClipState_t *this)
{
  ScreenClipState_t *v1; // esi
  int i; // ebx
  void *m_iCurrVert; // eax

  v1 = this + 1;
  for ( i = 1; i >= 0; --i )
  {
    v1 = (ScreenClipState_t *)((char *)v1 - 20);
    v1->m_pTempVertices.m_Memory.m_pMemory = nullptr;
    if ( v1->m_iClipCount >= 0 )
    {
      if ( v1->m_iCurrVert != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v1->m_iCurrVert);
        v1->m_iCurrVert = 0;
      }
      v1->m_iTempCount = 0;
    }
    m_iCurrVert = (void *)v1->m_iCurrVert;
    v1->m_pTempVertices.m_Memory.m_nAllocationCount = v1->m_iCurrVert;
    if ( v1->m_iClipCount >= 0 )
    {
      if ( m_iCurrVert != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_iCurrVert);
        v1->m_iCurrVert = 0;
      }
      v1->m_iTempCount = 0;
    }
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pTempVertices);
}

//------------------------------------------------------------------------------
// Address: 0x10002100
// Name: int ClipPolygon(int,struct FontVertex_t __near *,int,int,struct FontVertex_t __near * __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClipPolygon(
        int iCount,
        FontVertex_t *pVerts,
        int iTranslateX,
        int iTranslateY,
        FontVertex_t ***pppOutVertex)
{
  int v5; // ecx
  int *p_m_nGrowSize; // eax
  int v7; // edi
  int v8; // esi
  FontVertex_t *v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *p_y; // eax
  FontVertex_t *m_pMemory; // esi
  char *v17; // ecx
  float *v18; // esi
  double v19; // st7
  FontVertex_t *v20; // esi
  float *v21; // esi
  double v22; // st7
  char *v23; // esi
  FontVertex_t *v24; // edi
  float *v25; // edi
  double v26; // st7
  FontVertex_t *v27; // edi
  char *v28; // esi
  float *v29; // edi
  int v30; // eax
  FontVertex_t *v31; // ecx
  float *p_x; // ecx
  int v34; // [esp+Ch] [ebp-Ch]

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    clip.m_pTempVertices.m_Memory.m_pMemory = nullptr;
    clip.m_pTempVertices.m_Memory.m_nAllocationCount = 0;
    clip.m_pTempVertices.m_Memory.m_nGrowSize = 0;
    clip.m_pTempVertices.m_Size = 0;
    clip.m_pTempVertices.m_pElements = nullptr;
    v5 = 1;
    p_m_nGrowSize = &clip.m_ppClipVertices[0].m_Memory.m_nGrowSize;
    do
    {
      *(p_m_nGrowSize - 2) = 0;
      *(p_m_nGrowSize - 1) = 0;
      *p_m_nGrowSize = 0;
      p_m_nGrowSize[1] = 0;
      p_m_nGrowSize[2] = 0;
      p_m_nGrowSize += 5;
      --v5;
    }
    while ( v5 >= 0 );
    atexit(func: ClipPolygon_::_2_::_dynamic_atexit_destructor_for__clip__);
  }
  v7 = iCount;
  v8 = 4 * iCount;
  if ( clip.m_pTempVertices.m_Size < 4 * iCount )
    CUtlVector<FontVertex_t,CUtlMemory<FontVertex_t,int>>::InsertMultipleBefore(
      this: &clip.m_pTempVertices,
      elem: clip.m_pTempVertices.m_Size,
      num: v8 - clip.m_pTempVertices.m_Size);
  if ( clip.m_ppClipVertices[0].m_Size < v8 )
    CUtlVector<FontVertex_t *,CUtlMemory<FontVertex_t *,int>>::InsertMultipleBefore(
      this: clip.m_ppClipVertices,
      elem: clip.m_ppClipVertices[0].m_Size,
      num: v8 - clip.m_ppClipVertices[0].m_Size);
  if ( clip.m_ppClipVertices[1].m_Size < v8 )
    CUtlVector<FontVertex_t *,CUtlMemory<FontVertex_t *,int>>::InsertMultipleBefore(
      this: &clip.m_ppClipVertices[1],
      elem: clip.m_ppClipVertices[1].m_Size,
      num: v8 - clip.m_ppClipVertices[1].m_Size);
  v9 = pVerts;
  v10 = 0;
  if ( iCount >= 4 )
  {
    v34 = 4 - (_DWORD)pVerts;
    v11 = -12 - (_DWORD)pVerts;
    v12 = -44 - (_DWORD)pVerts;
    v13 = (float)iTranslateX;
    v14 = (float)iTranslateY;
    p_y = &pVerts[2].m_TexCoord.y;
    while ( 1 )
    {
      m_pMemory = clip.m_pTempVertices.m_Memory.m_pMemory;
      v17 = (char *)p_y + v12;
      *(float *)((char *)&clip.m_pTempVertices.m_Memory.m_pMemory->m_Position.x + (unsigned int)v17) = *(p_y - 11);
      v18 = (float *)((int)&m_pMemory->m_Position.x + (_DWORD)v17);
      v18[1] = *(p_y - 10);
      v18[2] = *(p_y - 9);
      v18[3] = *(p_y - 8);
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory] = *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory]
                                                                            + v13;
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 4] = v14
                                                                                + *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                               + 4];
      v19 = *(p_y - 7);
      clip.m_ppClipVertices[0].m_Memory.m_pMemory[v10] = (FontVertex_t *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory];
      v20 = clip.m_pTempVertices.m_Memory.m_pMemory;
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 16] = v19;
      v21 = (float *)((char *)&v20[1].m_Position.x + (_DWORD)v17);
      v21[1] = *(p_y - 6);
      v21[2] = *(p_y - 5);
      v21[3] = *(p_y - 4);
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 16] = v13
                                                                                 + *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                                + 16];
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 20] = *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                                + 20]
                                                                                 + v14;
      v22 = *(p_y - 3);
      clip.m_ppClipVertices[0].m_Memory.m_pMemory[v10 + 1] = (FontVertex_t *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                + 16];
      v23 = (char *)p_y + v11;
      v24 = clip.m_pTempVertices.m_Memory.m_pMemory;
      *(float *)((char *)&clip.m_pTempVertices.m_Memory.m_pMemory->m_Position.x + (unsigned int)v23) = v22;
      v25 = (float *)((int)&v24->m_Position.x + (_DWORD)v23);
      v25[1] = *(p_y - 2);
      v25[2] = *(p_y - 1);
      v25[3] = *p_y;
      *(float *)&v23[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory] = *(float *)&v23[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory]
                                                                            + v13;
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 36] = v14
                                                                                 + *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                                + 36];
      v26 = p_y[1];
      clip.m_ppClipVertices[0].m_Memory.m_pMemory[v10 + 2] = (FontVertex_t *)((char *)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                            + (unsigned int)v23);
      v27 = clip.m_pTempVertices.m_Memory.m_pMemory;
      v28 = (char *)p_y + v34;
      *(float *)((char *)&clip.m_pTempVertices.m_Memory.m_pMemory->m_Position.x + (unsigned int)v28) = v26;
      v29 = (float *)((int)&v27->m_Position.x + (_DWORD)p_y + v34);
      v29[1] = p_y[2];
      v29[2] = p_y[3];
      v29[3] = p_y[4];
      *(float *)&v28[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory] = *(float *)&v28[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory]
                                                                            + v13;
      *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory + 52] = *(float *)&v17[(unsigned int)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                                                + 52]
                                                                                 + v14;
      v7 = iCount;
      clip.m_ppClipVertices[0].m_Memory.m_pMemory[v10 + 3] = (FontVertex_t *)((char *)clip.m_pTempVertices.m_Memory.m_pMemory
                                                                            + (unsigned int)p_y
                                                                            + v34);
      v10 += 4;
      p_y += 16;
      if ( v10 >= iCount - 3 )
        break;
      v12 = -44 - (_DWORD)pVerts;
      v11 = -12 - (_DWORD)pVerts;
    }
    v9 = pVerts;
  }
  if ( v10 < v7 )
  {
    v30 = v10;
    do
    {
      v31 = clip.m_pTempVertices.m_Memory.m_pMemory;
      clip.m_pTempVertices.m_Memory.m_pMemory[v30].m_Position.x = v9[v30].m_Position.x;
      p_x = &v31[v30].m_Position.x;
      ++v10;
      p_x[1] = v9[v30].m_Position.y;
      p_x[2] = v9[v30].m_TexCoord.x;
      p_x[3] = v9[v30].m_TexCoord.y;
      clip.m_pTempVertices.m_Memory.m_pMemory[v30].m_Position.x = clip.m_pTempVertices.m_Memory.m_pMemory[v30].m_Position.x
                                                                + (float)iTranslateX;
      clip.m_pTempVertices.m_Memory.m_pMemory[v30].m_Position.y = (float)iTranslateY
                                                                + clip.m_pTempVertices.m_Memory.m_pMemory[v30].m_Position.y;
      clip.m_ppClipVertices[0].m_Memory.m_pMemory[v10 - 1] = &clip.m_pTempVertices.m_Memory.m_pMemory[v30++];
    }
    while ( v10 < v7 );
  }
  if ( !g_bScissor || g_bFullScreenScissor )
  {
    *pppOutVertex = clip.m_ppClipVertices[0].m_Memory.m_pMemory;
    return v7;
  }
  else
  {
    clip.m_iClipCount = v7;
    clip.m_iTempCount = v7;
    clip.m_iCurrVert = 0;
    ScreenClip_CClipTop_(clip: &clip);
    ScreenClip_CClipBottom_(clip: &clip);
    ScreenClip_CClipLeft_(clip: &clip);
    ScreenClip_CClipRight_(clip: &clip);
    if ( clip.m_iClipCount >= 3 )
    {
      *pppOutVertex = clip.m_ppClipVertices[clip.m_iCurrVert].m_Memory.m_pMemory;
      return clip.m_iClipCount;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB4A0
// Name: _ClipPolygon_::_2_::_dynamic_atexit_destructor_for__clip__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl ClipPolygon_::_2_::_dynamic_atexit_destructor_for__clip__()
{
  ScreenClipState_t::~ScreenClipState_t(this: &clip);
}

//------------------------------------------------------------------------------
// Address: 0x100BB4B0
// Name: _dynamic_atexit_destructor_for__g_UserCursors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UserCursors__()
{
  CUtlDict<InputCursorHandle_t__ *,int>::RemoveAll(this: &g_UserCursors.m_UserCursors);
  CUtlRBTree<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int,CUtlMap<char const *,InputCursorHandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int,CUtlMap<char const *,InputCursorHandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int>,int>>(this: &g_UserCursors.m_UserCursors.m_Elements.m_Tree);
}
