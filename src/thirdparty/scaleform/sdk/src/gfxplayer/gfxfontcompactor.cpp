// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontcompactor.cpp
// Functions: 38
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontcompactor.h"

//------------------------------------------------------------------------------
// Address: 0x10184F70
// Name: private: static bool GFxFontCompactor::cmpKerningPairs(struct GFxFontCompactor::KerningPairType const __near &,struct GFxFontCompactor::KerningPairType const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxFontCompactor::cmpKerningPairs(CMorph *a, CMorph *aa, CMorph *b)
{
  bool v3; // cf

  v3 = LOWORD(aa->IMorphInternal::IMorph::__vftable) < LOWORD(b->IMorphInternal::IMorph::__vftable);
  if ( LOWORD(aa->IMorphInternal::IMorph::__vftable) == LOWORD(b->IMorphInternal::IMorph::__vftable) )
    return HIWORD(aa->IMorphInternal::IMorph::__vftable) < HIWORD(b->IMorphInternal::IMorph::__vftable);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10184FA0
// Name: private: void GFxFontCompactor::computeBounds(int __near *,int __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::computeBounds(GFxFontCompactor *this, int *x1, int *y1, int *x2, int *y2)
{
  unsigned int v6; // ecx
  double v7; // st7
  _DWORD *v8; // edi
  int v9; // eax
  unsigned int v10; // ebx
  int v11; // edx
  __int16 *v12; // esi
  double v13; // st5
  double v14; // st4
  __int16 *v15; // edi
  double v16; // st4
  bool v17; // c0
  bool v18; // c3
  double v19; // st7
  int v20; // ebx
  int v21; // eax
  double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st5
  double v26; // st4
  double v27; // st2
  bool v28; // c0
  bool v29; // c3
  double v30; // st5
  int v31; // esi
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  _DWORD *v36; // [esp+14h] [ebp-34h]
  float v37; // [esp+18h] [ebp-30h]
  float v38; // [esp+18h] [ebp-30h]
  float v39; // [esp+18h] [ebp-30h]
  float v40; // [esp+18h] [ebp-30h]
  float v41; // [esp+18h] [ebp-30h]
  float v42; // [esp+18h] [ebp-30h]
  float v43; // [esp+18h] [ebp-30h]
  float v44; // [esp+18h] [ebp-30h]
  float v45; // [esp+18h] [ebp-30h]
  float v46; // [esp+18h] [ebp-30h]
  float v47; // [esp+18h] [ebp-30h]
  float v48; // [esp+18h] [ebp-30h]
  float v49; // [esp+18h] [ebp-30h]
  float v50; // [esp+1Ch] [ebp-2Ch]
  float v51; // [esp+1Ch] [ebp-2Ch]
  float v52; // [esp+1Ch] [ebp-2Ch]
  float v53; // [esp+1Ch] [ebp-2Ch]
  float v54; // [esp+1Ch] [ebp-2Ch]
  float v55; // [esp+1Ch] [ebp-2Ch]
  float v56; // [esp+1Ch] [ebp-2Ch]
  float v57; // [esp+1Ch] [ebp-2Ch]
  float v58; // [esp+20h] [ebp-28h]
  float v59; // [esp+20h] [ebp-28h]
  float v60; // [esp+24h] [ebp-24h]
  float v61; // [esp+24h] [ebp-24h]
  unsigned int i; // [esp+28h] [ebp-20h]
  GFxFontCompactor *v63; // [esp+2Ch] [ebp-1Ch]
  int v64; // [esp+30h] [ebp-18h]
  float v65; // [esp+30h] [ebp-18h]
  float v66; // [esp+30h] [ebp-18h]
  unsigned int j; // [esp+34h] [ebp-14h]
  signed int ja; // [esp+34h] [ebp-14h]
  float v69; // [esp+38h] [ebp-10h]
  float v70; // [esp+38h] [ebp-10h]
  float v71; // [esp+38h] [ebp-10h]
  int v72; // [esp+3Ch] [ebp-Ch]
  int v73; // [esp+40h] [ebp-8h]
  int t; // [esp+44h] [ebp-4h]
  float ta; // [esp+44h] [ebp-4h]
  float tb; // [esp+44h] [ebp-4h]
  int tc; // [esp+44h] [ebp-4h]

  *x1 = 0x3FFF;
  *y1 = 0x3FFF;
  *x2 = -16383;
  *y2 = -16383;
  v6 = 0;
  v63 = this;
  i = 0;
  if ( *((_DWORD *)this + 10) != 0 )
  {
    v7 = 0.0;
    do
    {
      v8 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 4 * (v6 >> 6)) + 8 * (v6 & 0x3F));
      t = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * (*v8 >> 6)) + 4 * (*v8 & 0x3F));
      v9 = (__int16)t >> 1;
      v36 = v8;
      v73 = SHIWORD(t);
      v64 = v9;
      if ( v9 < *x1 )
        *x1 = v9;
      if ( SHIWORD(t) < *y1 )
        *y1 = SHIWORD(t);
      if ( v9 > *x2 )
        *x2 = v9;
      if ( SHIWORD(t) > *y2 )
        *y2 = SHIWORD(t);
      v10 = 1;
      if ( v8[1] > 1u )
      {
        do
        {
          v11 = *((_DWORD *)this + 9);
          v12 = (__int16 *)(*(_DWORD *)(v11 + 4 * ((*v8 + v10) >> 6)) + 4 * ((*v8 + v10) & 0x3F));
          if ( (*v12 & 1) != 0 )
          {
            v65 = (float)v64;
            ++v10;
            v69 = (float)(*v12 >> 1);
            v13 = v69;
            v14 = v69;
            v15 = (__int16 *)(*(_DWORD *)(v11 + 4 * ((v10 + *v8) >> 6)) + 4 * ((v10 + *v8) & 0x3F));
            v72 = *v15 >> 1;
            j = v10;
            v70 = v14 + v14 - v65 - (double)v72;
            if ( v7 == v70 )
              v16 = -1.0;
            else
              v16 = (v14 - v65) / v70;
            ta = v16;
            v17 = ta < v7;
            v18 = ta == v7;
            v19 = ta;
            if ( !v17 && !v18 && v19 < 1.0 )
            {
              v50 = (float)v73;
              v71 = v13;
              v60 = (float)v12[1];
              v37 = (v71 - v65) * v19 + v65;
              v58 = (v60 - v50) * v19 + v50;
              v51 = v60 + ((double)v15[1] - v60) * v19;
              v52 = v19 * (v51 - v58) + v58;
              v53 = floor(X: v52);
              v20 = (int)(v53 + 0.5);
              v54 = v71 + ((double)v72 - v71) * ta;
              v38 = ta * (v54 - v37) + v37;
              v39 = floor(X: v38);
              v21 = (int)(v39 + 0.5);
              if ( v21 < *x1 )
                *x1 = v21;
              if ( v20 < *y1 )
                *y1 = v20;
              if ( v21 > *x2 )
                *x2 = v21;
              if ( v20 > *y2 )
                *y2 = v20;
              v10 = j;
            }
            v40 = (float)v73;
            v22 = v40;
            v55 = v40;
            ja = v15[1];
            v41 = (float)v12[1];
            v23 = v41;
            v24 = v41;
            v42 = v24 + v24 - v55 - (double)ja;
            if ( 0.0 == v42 )
            {
              v25 = 0.0;
              v26 = -1.0;
            }
            else
            {
              v27 = v24;
              v25 = 0.0;
              v26 = (v27 - v55) / v42;
            }
            tb = v26;
            v28 = tb < v25;
            v29 = tb == v25;
            v30 = tb;
            if ( v28 || v29 || v30 >= 1.0 )
              goto LABEL_40;
            v56 = v65;
            v59 = v22;
            v66 = (float)(*v12 >> 1);
            v43 = v23;
            v61 = (v66 - v56) * v30 + v56;
            v57 = (v43 - v59) * v30 + v59;
            v44 = v43 + ((double)ja - v43) * v30;
            v45 = tb * (v44 - v57) + v57;
            v46 = floor(X: v45);
            v31 = (int)(v46 + 0.5);
            v47 = v66 + ((double)(*v15 >> 1) - v66) * tb;
            v48 = tb * (v47 - v61) + v61;
            v49 = floor(X: v48);
            v32 = (int)(v49 + 0.5);
            if ( v32 < *x1 )
              *x1 = v32;
            if ( v31 < *y1 )
              *y1 = v31;
            if ( v32 > *x2 )
              *x2 = v32;
            if ( v31 <= *y2 )
            {
LABEL_40:
              v34 = *(_DWORD *)v15;
              v7 = 0.0;
              v8 = v36;
              tc = v34;
            }
            else
            {
              v7 = 0.0;
              *y2 = v31;
              v33 = *(_DWORD *)v15;
              v8 = v36;
              tc = v33;
            }
          }
          else
          {
            tc = *(_DWORD *)v12;
          }
          v35 = (__int16)tc >> 1;
          v73 = SHIWORD(tc);
          v64 = v35;
          if ( v35 < *x1 )
            *x1 = v35;
          if ( SHIWORD(tc) < *y1 )
            *y1 = SHIWORD(tc);
          if ( v35 > *x2 )
            *x2 = v35;
          if ( SHIWORD(tc) > *y2 )
            *y2 = SHIWORD(tc);
          this = v63;
          ++v10;
        }
        while ( v10 < v8[1] );
        v6 = i;
      }
      i = ++v6;
    }
    while ( v6 < *((_DWORD *)this + 10) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185420
// Name: private: unsigned int GFxFontCompactor::navigateToEndGlyph(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<MorphVertexInfo_t,int> *__thiscall GFxFontCompactor::navigateToEndGlyph(_DWORD *this, unsigned int result)
{
  int v2; // eax
  void *v3; // ecx
  int v4; // edi
  BOOL v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // esi
  char *v8; // esi
  unsigned int v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // esi
  unsigned int v13; // esi
  unsigned int i; // ebx
  unsigned int numEdges; // [esp+Ch] [ebp-1Ch] BYREF
  void *v17; // [esp+10h] [ebp-18h]
  unsigned int numContours; // [esp+14h] [ebp-14h]
  char v19[12]; // [esp+18h] [ebp-10h] BYREF

  v2 = *(this + 3);
  v3 = this + 3;
  v4 = *(_DWORD *)(v2 + 12);
  v5 = (*(_BYTE *)((result & 0xFFF) + *(_DWORD *)(v4 + 4 * (result >> 12))) & 1) != 0;
  v17 = v3;
  v6 = ((*(_BYTE *)(((v5 + 1 + (_WORD)result) & 0xFFF) + *(_DWORD *)(v4 + 4 * ((v5 + 1 + result) >> 12))) & 1) != 0)
     + 1
     + v5
     + 1
     + result;
  v7 = ((*(_BYTE *)((v6 & 0xFFF) + *(_DWORD *)(v4 + 4 * (v6 >> 12))) & 1) != 0) + 1 + v6;
  v8 = (char *)(((*(_BYTE *)((v7 & 0xFFF) + *(_DWORD *)(v4 + 4 * (v7 >> 12))) & 1) != 0) + 1 + v7);
  v9 = *(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((unsigned int)v8 >> 12)) + ((unsigned __int16)v8 & 0xFFF));
  if ( (v9 & 1) != 0 )
  {
    numContours = (v9 >> 1)
                | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((unsigned int)(v8 + 1) >> 12))
                                      + ((unsigned int)(v8 + 1) & 0xFFF)) << 7);
    v10 = 2;
  }
  else
  {
    numContours = v9 >> 1;
    v10 = 1;
  }
  v11 = (unsigned int)&v8[v10];
  if ( numContours != 0 )
  {
    while ( 1 )
    {
      --numContours;
      v12 = ((*(_BYTE *)((v11 & 0xFFF) + *(_DWORD *)(v4 + 4 * (v11 >> 12))) & 1) != 0) + 1 + v11;
      v13 = ((*(_BYTE *)((v12 & 0xFFF) + *(_DWORD *)(v4 + 4 * (v12 >> 12))) & 1) != 0) + 1 + v12;
      v11 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
              this: (int *)v3,
              a2: v13,
              a3: (int *)&numEdges)
          + v13;
      if ( (numEdges & 1) == 0 )
      {
        for ( i = numEdges >> 1; i != 0; --i )
          v11 += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                   this: v17,
                   a2: v11,
                   a3: v19);
        numEdges = i - 1;
      }
      if ( numContours == 0 )
        break;
      v3 = v17;
    }
  }
  return (CUtlMemory<MorphVertexInfo_t,int> *)v11;
}

//------------------------------------------------------------------------------
// Address: 0x101855B0
// Name: public: bool GFxFontCompactor::PathsEqual(unsigned int,class GFxFontCompactor const __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFontCompactor::PathsEqual(
        const CVertexMorphDict::MorphVertexList_t *this,
        const CVertexMorphDict::MorphVertexList_t *pos,
        int a3,
        unsigned int cmpPos)
{
  int *p_m_nGrowSize; // edi
  char *v5; // ebx
  unsigned int v6; // esi
  unsigned int RawEdge; // edi
  unsigned int v9; // ecx
  _BYTE *v10; // edx
  _BYTE *v11; // esi
  int *v12; // [esp+10h] [ebp-2Ch]
  unsigned int pos2; // [esp+14h] [ebp-28h]
  unsigned int nb2; // [esp+18h] [ebp-24h] BYREF
  unsigned int size1; // [esp+1Ch] [ebp-20h] BYREF
  _BYTE v16[12]; // [esp+20h] [ebp-1Ch] BYREF
  _BYTE v17[12]; // [esp+2Ch] [ebp-10h] BYREF

  p_m_nGrowSize = &this->m_MorphInfo.m_Memory.m_nGrowSize;
  v12 = &this->m_MorphInfo.m_Memory.m_nGrowSize;
  v5 = (char *)pos
     + GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
         this: &this->m_MorphInfo.m_Memory.m_nGrowSize,
         a2: (unsigned int)pos,
         a3: (int *)&size1);
  v6 = cmpPos
     + GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
         this: (int *)(a3 + 12),
         a2: cmpPos,
         a3: (int *)&nb2);
  pos2 = v6;
  if ( size1 != nb2 )
    return 0;
  size1 >>= 1;
  if ( size1 != 0 )
  {
    while ( 1 )
    {
      --size1;
      RawEdge = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                  this: p_m_nGrowSize,
                  a2: (unsigned int)v5,
                  a3: v17);
      nb2 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
              this: (void *)(a3 + 12),
              a2: v6,
              a3: v16);
      if ( RawEdge != nb2 )
        return 0;
      v9 = RawEdge;
      v10 = v16;
      v11 = v17;
      if ( RawEdge >= 4 )
      {
        while ( *(_DWORD *)v11 == *(_DWORD *)v10 )
        {
          v9 -= 4;
          v10 += 4;
          v11 += 4;
          if ( v9 < 4 )
            goto LABEL_10;
        }
        return 0;
      }
LABEL_10:
      if ( v9 != 0 && (*v10 != *v11 || v9 > 1 && (v10[1] != v11[1] || v9 > 2 && v10[2] != v11[2])) )
        return 0;
      pos2 += nb2;
      v5 += RawEdge;
      if ( size1 == 0 )
        return 1;
      v6 = pos2;
      p_m_nGrowSize = v12;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101856D0
// Name: public: unsigned long GFxFontCompactor::ComputePathHash(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFontCompactor::ComputePathHash(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this@<ecx>,
        unsigned int pos,
        int edge)
{
  int *p_m_Size; // ebx
  int v4; // esi
  unsigned int v5; // edi
  unsigned int RawEdge; // eax
  unsigned int v7; // ecx
  int v8; // edx
  int *v9; // [esp+Ch] [ebp-18h]
  unsigned int size; // [esp+10h] [ebp-14h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-10h] BYREF

  p_m_Size = &this->m_Size;
  v4 = 0;
  v9 = &this->m_Size;
  v5 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
         this: &this->m_Size,
         a2: pos,
         a3: (int *)&size)
     + pos;
  size >>= 1;
  while ( size != 0 )
  {
    --size;
    RawEdge = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                this: p_m_Size,
                a2: v5,
                a3: v11);
    v5 += RawEdge;
    v7 = 0;
    if ( RawEdge != 0 )
    {
      do
      {
        v8 = (unsigned __int8)v11[v7++];
        v4 = v8 ^ (33 * v4);
      }
      while ( v7 < RawEdge );
      p_m_Size = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185760
// Name: public: void GFxFontCompactor::AssignGlyphAdvance(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontCompactor::AssignGlyphAdvance(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this,
        unsigned int glyphIndex,
        __int16 advanceX)
{
  int result; // eax

  result = glyphIndex;
  if ( glyphIndex < *((_DWORD *)this + 19) )
  {
    *(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 22) + 4 * (glyphIndex >> 6)) + 8 * (glyphIndex & 0x3F) + 2) = advanceX;
    return glyphIndex & 0x3F;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185920
// Name: void G_QuickSortSliced<class GArrayPagedPOD<struct GFxFontCompactor::KerningPairType,6,64,261>,bool (*)(struct GFxFontCompactor::KerningPairType const __near &,struct GFxFontCompactor::KerningPairType const __near &)>(class GArrayPagedPOD<struct GFxFontCompactor::KerningPairType,6,64,261> __near &,unsigned int,unsigned int,bool (*)(struct GFxFontCompactor::KerningPairType const __near &,struct GFxFontCompactor::KerningPairType const __near &))
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl G_QuickSortSliced<GArrayPagedPOD<GFxFontCompactor::KerningPairType,6,64,261>,bool (__cdecl *)(GFxFontCompactor::KerningPairType const &,GFxFontCompactor::KerningPairType const &)>(
        int a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 (__cdecl *a4)(int, int))
{
  unsigned int result; // eax
  unsigned int v5; // esi
  unsigned int *v6; // ecx
  int v7; // edx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // edx
  _DWORD *v13; // eax
  int v14; // edx
  unsigned int v15; // esi
  int v16; // ecx
  int *v17; // eax
  int *v18; // ecx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // eax
  int v23; // edx
  _DWORD *v24; // ecx
  int v25; // ecx
  int *v26; // eax
  int *v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // edx
  int *v32; // eax
  int v33; // ecx
  int *v34; // edi
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // ebx
  _DWORD *v39; // eax
  int v40; // edx
  unsigned int v41; // eax
  unsigned int *v42; // ecx
  unsigned int *v43; // edx
  int v44; // esi
  int v45; // edi
  int v46; // ebx
  int v47; // edx
  int v48; // eax
  int *v49; // ebx
  int *v50; // esi
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // eax
  unsigned int v54; // eax
  int v55; // edx
  int v56; // [esp+4h] [ebp-198h]
  int v57; // [esp+8h] [ebp-194h]
  int v58; // [esp+10h] [ebp-18Ch]
  int v59; // [esp+14h] [ebp-188h]
  int v60; // [esp+1Ch] [ebp-180h]
  int v61; // [esp+20h] [ebp-17Ch]
  int v62; // [esp+28h] [ebp-174h]
  int v63; // [esp+2Ch] [ebp-170h]
  unsigned int v64; // [esp+30h] [ebp-16Ch]
  int v65; // [esp+34h] [ebp-168h]
  int *v66; // [esp+34h] [ebp-168h]
  unsigned int v67; // [esp+38h] [ebp-164h]
  int v68; // [esp+3Ch] [ebp-160h]
  int v69; // [esp+3Ch] [ebp-160h]
  int v70; // [esp+40h] [ebp-15Ch]
  unsigned int *v71; // [esp+44h] [ebp-158h]
  unsigned int v72; // [esp+4Ch] [ebp-150h]
  unsigned int v73; // [esp+4Ch] [ebp-150h]
  unsigned int v74; // [esp+50h] [ebp-14Ch]
  int v75; // [esp+54h] [ebp-148h]
  unsigned int v76[80]; // [esp+58h] [ebp-144h] BYREF

  v75 = a1;
  result = a3;
  v5 = a2;
  if ( a3 - a2 >= 2 )
  {
    v6 = v76;
    v67 = a2;
    v70 = a3;
    while ( 1 )
    {
      v71 = v6;
      while ( (int)(v70 - v5) > 9 )
      {
        v7 = *(_DWORD *)(v75 + 12);
        v8 = (_DWORD *)(*(_DWORD *)(v7 + 4 * ((v5 + (int)(v70 - v5) / 2) >> 6)) + 8
                                                                                * ((v5 + (int)(v70 - v5) / 2) & 0x3F));
        v9 = 4 * (v5 >> 6);
        v10 = *(_DWORD *)(v9 + v7);
        v11 = 8 * (v5 & 0x3F);
        v12 = *(_DWORD *)(v10 + v11);
        v13 = (_DWORD *)(v11 + v10);
        v58 = v13[1];
        *v13 = *v8;
        v13[1] = v8[1];
        *v8 = v12;
        v8[1] = v58;
        v14 = *(_DWORD *)(v75 + 12);
        v74 = v5 + 1;
        v72 = 4 * ((v5 + 1) >> 6);
        v63 = 8 * ((v5 + 1) & 0x3F);
        v15 = v70 - 1;
        v64 = 4 * ((unsigned int)(v70 - 1) >> 6);
        v68 = 8 * (((_BYTE)v70 - 1) & 0x3F);
        if ( a4(a1: v68 + *(_DWORD *)(v64 + v14), a2: v63 + *(_DWORD *)(v14 + v72)) != 0 )
        {
          v16 = *(_DWORD *)(v75 + 12);
          v17 = (int *)(v63 + *(_DWORD *)(v16 + v72));
          v18 = (int *)(v68 + *(_DWORD *)(v16 + v64));
          v56 = *v18;
          v57 = v18[1];
          *v18 = *v17;
          v18[1] = v17[1];
          *v17 = v56;
          v17[1] = v57;
        }
        if ( a4(a1: v11 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v9), a2: v63 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v72)) != 0 )
        {
          v19 = *(_DWORD *)(v75 + 12);
          v20 = *(_DWORD *)(v19 + v72);
          v21 = *(_DWORD *)(v19 + v9);
          v22 = (_DWORD *)(v63 + v20);
          v23 = *(_DWORD *)(v21 + v11);
          v24 = (_DWORD *)(v11 + v21);
          v62 = v24[1];
          *v24 = *v22;
          v24[1] = v22[1];
          *v22 = v23;
          v22[1] = v62;
        }
        if ( a4(a1: v68 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v64), a2: v11 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v9)) != 0 )
        {
          v25 = *(_DWORD *)(v75 + 12);
          v26 = (int *)(v11 + *(_DWORD *)(v25 + v9));
          v27 = (int *)(v68 + *(_DWORD *)(v25 + v64));
          v60 = *v27;
          v61 = v27[1];
          *v27 = *v26;
          v27[1] = v26[1];
          *v26 = v60;
          v26[1] = v61;
        }
        while ( 1 )
        {
          do
          {
            v28 = *(_DWORD *)(v75 + 12);
            v65 = v11 + *(_DWORD *)(v28 + v9);
            ++v74;
          }
          while ( a4(a1: *(_DWORD *)(v28 + 4 * (v74 >> 6)) + 8 * (v74 & 0x3F), a2: v65) != 0 );
          do
            --v15;
          while ( a4(
                    a1: v11 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v9),
                    a2: *(_DWORD *)(*(_DWORD *)(v75 + 12) + 4 * (v15 >> 6)) + 8 * (v15 & 0x3F)) != 0 );
          if ( (int)v74 > (int)v15 )
            break;
          v29 = *(_DWORD *)(v75 + 12);
          v66 = (int *)(*(_DWORD *)(v29 + 4 * (v15 >> 6)) + 8 * (v15 & 0x3F));
          v30 = *(_DWORD *)(v29 + 4 * (v74 >> 6));
          v31 = *(_DWORD *)(v30 + 8 * (v74 & 0x3F) + 4);
          v32 = (int *)(v30 + 8 * (v74 & 0x3F));
          v59 = *v32;
          *v32 = *v66;
          v32[1] = v66[1];
          *v66 = v59;
          v66[1] = v31;
        }
        v33 = *(_DWORD *)(v75 + 12);
        v34 = (int *)(v11 + *(_DWORD *)(v33 + v9));
        v35 = *(_DWORD *)(v33 + 4 * (v15 >> 6));
        v36 = *v34;
        v37 = v15 & 0x3F;
        v38 = *(_DWORD *)(v35 + 8 * v37);
        v39 = (_DWORD *)(v35 + 8 * v37);
        v40 = v34[1];
        *v34 = v38;
        v34[1] = v39[1];
        *v39 = v36;
        v39[1] = v40;
        v41 = v74;
        if ( (int)(v15 - v67) <= (int)(v70 - v74) )
        {
          v43 = v71;
          v71 += 2;
          v43[1] = v70;
          v6 = v71;
          v70 = v15;
          v5 = v67;
          *v43 = v41;
        }
        else
        {
          v42 = v71;
          v71 += 2;
          v42[1] = v15;
          *v42 = v67;
          v6 = v71;
          v67 = v41;
          v5 = v41;
        }
      }
      result = v5;
      v73 = v5;
      v74 = v5 + 1;
      if ( (int)(v5 + 1) < v70 )
      {
        while ( 1 )
        {
          v44 = 4 * (result >> 6);
          v45 = 8 * (result & 0x3F);
          v46 = 4 * ((result + 1) >> 6);
          v69 = 8 * ((result + 1) & 0x3F);
          if ( a4(
                 a1: v69 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v46),
                 a2: v45 + *(_DWORD *)(*(_DWORD *)(v75 + 12) + v44)) != 0 )
          {
            do
            {
              v47 = v75;
              v48 = *(_DWORD *)(v75 + 12);
              v49 = (int *)(v69 + *(_DWORD *)(v48 + v46));
              v50 = (int *)(v45 + *(_DWORD *)(v48 + v44));
              v51 = *v49;
              v52 = v49[1];
              *v49 = *v50;
              v49[1] = v50[1];
              *v50 = v51;
              v53 = v73;
              v50[1] = v52;
              if ( v73 == v67 )
                break;
              --v73;
              v44 = 4 * ((v53 - 1) >> 6);
              v45 = 8 * (((_BYTE)v53 - 1) & 0x3F);
              v46 = 4 * (v53 >> 6);
              v69 = 8 * (v53 & 0x3F);
            }
            while ( a4(
                      a1: v69 + *(_DWORD *)(v46 + *(_DWORD *)(v47 + 12)),
                      a2: v45 + *(_DWORD *)(v44 + *(_DWORD *)(v47 + 12))) != 0 );
          }
          v73 = v74;
          result = v74 + 1;
          v74 = result;
          if ( (int)result >= v70 )
            break;
          result = v73;
        }
        v6 = v71;
      }
      if ( v6 <= v76 )
        break;
      v54 = *(v6 - 2);
      v55 = *(v6 - 1);
      v6 -= 2;
      v67 = v54;
      v70 = v55;
      v5 = v54;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186160
// Name: public: void GFxFontCompactor::StartGlyph(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontCompactor::StartGlyph(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 10) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10186170
// Name: public: unsigned long GFxFontCompactor::ComputeGlyphHash(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFontCompactor::ComputeGlyphHash(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this@<ecx>,
        unsigned int pos,
        int a3)
{
  unsigned int v3; // esi
  int v5; // edi
  CUtlMemory<MorphVertexInfo_t,int> *v6; // eax
  int v7; // edx

  v3 = pos;
  v5 = 0;
  v6 = GFxFontCompactor::navigateToEndGlyph(this, result: pos);
  if ( pos < (unsigned int)v6 )
  {
    do
    {
      v7 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(this->m_Size + 12) + 4 * (v3 >> 12)) + (v3 & 0xFFF));
      ++v3;
      v5 = v7 ^ (33 * v5);
    }
    while ( v3 < (unsigned int)v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101861C0
// Name: public: bool GFxFontCompactor::GlyphsEqual(unsigned int,class GFxFontCompactor const __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFontCompactor::GlyphsEqual(
        const CVertexMorphDict::MorphVertexList_t *this,
        const CVertexMorphDict::MorphVertexList_t *pos,
        _DWORD *a3,
        unsigned int cmpPos)
{
  unsigned int v4; // esi
  int v7; // ecx
  unsigned int v8; // eax
  CUtlMemory<MorphVertexInfo_t,int> *end1; // [esp+14h] [ebp+8h]
  unsigned int v10; // [esp+18h] [ebp+Ch]

  v4 = (unsigned int)pos;
  end1 = GFxFontCompactor::navigateToEndGlyph(this, result: (unsigned int)pos);
  if ( (char *)end1 - v4 != (char *)GFxFontCompactor::navigateToEndGlyph(this: a3, result: cmpPos) - cmpPos )
    return 0;
  if ( v4 < (unsigned int)end1 )
  {
    v7 = *(_DWORD *)(a3[3] + 12);
    v8 = cmpPos;
    v10 = cmpPos;
    while ( *(_BYTE *)((v4 & 0xFFF)
                     + *(_DWORD *)(*(_DWORD *)(this->m_MorphInfo.m_Memory.m_nGrowSize + 12) + 4 * (v4 >> 12))) == *(_BYTE *)((v8 & 0xFFF) + *(_DWORD *)(v7 + 4 * (v8 >> 12))) )
    {
      ++v4;
      v8 = ++v10;
      if ( v4 >= (unsigned int)end1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10186260
// Name: public: void GFxFontCompactor::UpdateMetrics(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::UpdateMetrics(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this,
        const CVertexMorphDict::MorphVertexList_t *ascent,
        __int16 descent,
        __int16 leading)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v4 = *((_DWORD *)this + 27);
  *(_BYTE *)((((_WORD)v4 + 4) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v4 + 4) >> 12))) = (_BYTE)ascent;
  *(_BYTE *)(((v4 + 5) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v4 + 5) >> 12))) = BYTE1(ascent);
  v5 = *((_DWORD *)this + 27);
  *(_BYTE *)((((_WORD)v5 + 6) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v5 + 6) >> 12))) = descent;
  *(_BYTE *)(((v5 + 7) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v5 + 7) >> 12))) = HIBYTE(descent);
  v6 = *((_DWORD *)this + 27);
  *(_BYTE *)((((_WORD)v6 + 8) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v6 + 8) >> 12))) = leading;
  *(_BYTE *)(((v6 + 9) & 0xFFF)
           + *(_DWORD *)(*(_DWORD *)(this->m_Memory.m_nGrowSize + 12) + 4 * ((unsigned int)(v6 + 9) >> 12))) = HIBYTE(leading);
}

//------------------------------------------------------------------------------
// Address: 0x10186650
// Name: public: void GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
        CUtlMemory<MorphVertexInfo_t,int> *this,
        __int16 v)
{
  unsigned int *m_pMemory; // esi
  unsigned int v4; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi

  m_pMemory = (unsigned int *)this->m_pMemory;
  v4 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v4 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this: m_pMemory,
      nb: (unsigned int)this->m_pMemory->m_nVertexId >> 12);
  *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v4)) = v;
  v5 = (unsigned int *)this->m_pMemory;
  v6 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v6 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v5, nb: v6);
  *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = HIBYTE(v);
  return HIBYTE(v);
}

//------------------------------------------------------------------------------
// Address: 0x101866C0
// Name: public: void GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const MorphVertexInfo_t *__thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
        CUtlMemory<MorphVertexInfo_t,int> *this,
        unsigned int v)
{
  unsigned int *m_pMemory; // esi
  unsigned int v4; // ebx
  unsigned int *v5; // esi
  unsigned int v6; // edi
  unsigned int *v7; // esi
  unsigned int v8; // edi
  unsigned int *v9; // esi
  unsigned int v10; // edi
  const MorphVertexInfo_t *result; // eax

  m_pMemory = (unsigned int *)this->m_pMemory;
  v4 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v4 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this: m_pMemory,
      nb: v4);
  *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v4)) = v;
  v5 = (unsigned int *)this->m_pMemory;
  v6 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v6 >= v5[1] )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v5, nb: v6);
  *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = BYTE1(v);
  v7 = (unsigned int *)this->m_pMemory;
  v8 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v8 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v7, nb: v8);
  *(_BYTE *)(((*v7)++ & 0xFFF) + *(_DWORD *)(v7[3] + 4 * v8)) = BYTE2(v);
  v9 = (unsigned int *)this->m_pMemory;
  v10 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v10 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this: v9,
      nb: (unsigned int)this->m_pMemory->m_nVertexId >> 12);
  result = (const MorphVertexInfo_t *)v9[3];
  *(_BYTE *)(((*v9)++ & 0xFFF) + *(&result->m_nVertexId + v10)) = HIBYTE(v);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101867A0
// Name: public: void GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
        CUtlMemory<MorphVertexInfo_t,int> *this,
        __int16 v)
{
  unsigned int *m_pMemory; // esi
  unsigned int v4; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi

  m_pMemory = (unsigned int *)this->m_pMemory;
  v4 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v4 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this: m_pMemory,
      nb: (unsigned int)this->m_pMemory->m_nVertexId >> 12);
  *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v4)) = v;
  v5 = (unsigned int *)this->m_pMemory;
  v6 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  if ( v6 >= this->m_pMemory->m_nMorphTargetId )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v5, nb: v6);
  *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = HIBYTE(v);
  return HIBYTE(v);
}

//------------------------------------------------------------------------------
// Address: 0x10186810
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(
        CUtlMemory<MorphVertexInfo_t,int> *this@<ecx>,
        MorphVertexInfo_t *v,
        int a3)
{
  unsigned int *m_pMemory; // esi
  unsigned int v4; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi
  CUtlMemory<MorphVertexInfo_t,int> *v7; // [esp+Ch] [ebp-4h]

  m_pMemory = (unsigned int *)this->m_pMemory;
  v4 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
  v7 = this;
  if ( (unsigned int)v > 0x7F )
  {
    if ( v4 >= m_pMemory[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: m_pMemory,
        nb: v4);
      this = v7;
    }
    *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v4)) = (2 * (_BYTE)v) | 1;
    v5 = (unsigned int *)this->m_pMemory;
    v6 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
    if ( v6 >= this->m_pMemory->m_nMorphTargetId )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: (unsigned int)this->m_pMemory->m_nVertexId >> 12);
    *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = (unsigned int)v >> 7;
  }
  else
  {
    if ( v4 >= m_pMemory[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: m_pMemory,
        nb: v4);
    *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v4)) = 2 * (_BYTE)v;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101868D0
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
        CUtlMemory<MorphVertexInfo_t,int> *this@<ecx>,
        MorphVertexInfo_t *v,
        int a3)
{
  unsigned int *v5; // esi
  unsigned int v6; // edi
  unsigned int *m_pMemory; // edi
  char v8; // al
  unsigned int v9; // eax
  unsigned int *v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int v13; // eax
  unsigned int *v14; // edi
  unsigned int v15; // eax
  unsigned int *v16; // esi
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned int v19; // eax
  unsigned int *v20; // edi
  unsigned int v21; // eax
  unsigned int *v22; // edi
  unsigned int v23; // eax
  unsigned int *v24; // esi
  unsigned int v25; // edi
  unsigned int v26; // ebx
  unsigned int v27; // [esp+Ch] [ebp-4h]
  unsigned int v28; // [esp+Ch] [ebp-4h]
  unsigned int v29; // [esp+Ch] [ebp-4h]
  unsigned int v30; // [esp+Ch] [ebp-4h]
  unsigned int v31; // [esp+Ch] [ebp-4h]
  MorphVertexInfo_t *va; // [esp+18h] [ebp+8h]
  char v_3; // [esp+1Bh] [ebp+Bh]
  char v_3a; // [esp+1Bh] [ebp+Bh]
  char v_3b; // [esp+1Bh] [ebp+Bh]

  if ( (unsigned int)v > 0x3F )
  {
    m_pMemory = (unsigned int *)this->m_pMemory;
    v8 = 4 * (_BYTE)v;
    if ( (unsigned int)v > 0x3FFF )
    {
      if ( (unsigned int)v > 0x3FFFFF )
      {
        v_3b = v8 | 3;
        v19 = *m_pMemory >> 12;
        v30 = v19;
        if ( v19 >= m_pMemory[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: m_pMemory,
            nb: v19);
          v19 = v30;
        }
        *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v19)) = v_3b;
        v20 = (unsigned int *)this->m_pMemory;
        v21 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
        v31 = v21;
        if ( v21 >= this->m_pMemory->m_nMorphTargetId )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v20,
            nb: v21);
          v21 = v31;
        }
        *(_BYTE *)(((*v20)++ & 0xFFF) + *(_DWORD *)(v20[3] + 4 * v21)) = (unsigned int)v >> 6;
        v22 = (unsigned int *)this->m_pMemory;
        v23 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
        va = (MorphVertexInfo_t *)v23;
        if ( v23 >= this->m_pMemory->m_nMorphTargetId )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v22,
            nb: v23);
          v23 = (unsigned int)va;
        }
        *(_BYTE *)(((*v22)++ & 0xFFF) + *(_DWORD *)(v22[3] + 4 * v23)) = (unsigned int)v >> 14;
        v24 = (unsigned int *)this->m_pMemory;
        v25 = *v24 >> 12;
        v26 = (unsigned int)v >> 22;
        if ( v25 >= v24[1] )
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v24,
            nb: *v24 >> 12);
        *(_BYTE *)(((*v24)++ & 0xFFF) + *(_DWORD *)(v24[3] + 4 * v25)) = v26;
      }
      else
      {
        v_3a = v8 | 2;
        v13 = *m_pMemory >> 12;
        v28 = v13;
        if ( v13 >= m_pMemory[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: m_pMemory,
            nb: v13);
          v13 = v28;
        }
        *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v13)) = v_3a;
        v14 = (unsigned int *)this->m_pMemory;
        v15 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
        v29 = v15;
        if ( v15 >= this->m_pMemory->m_nMorphTargetId )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v14,
            nb: v15);
          v15 = v29;
        }
        *(_BYTE *)(((*v14)++ & 0xFFF) + *(_DWORD *)(v14[3] + 4 * v15)) = (unsigned int)v >> 6;
        v16 = (unsigned int *)this->m_pMemory;
        v17 = *v16 >> 12;
        v18 = (unsigned int)v >> 14;
        if ( v17 >= v16[1] )
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v16,
            nb: *v16 >> 12);
        *(_BYTE *)(((*v16)++ & 0xFFF) + *(_DWORD *)(v16[3] + 4 * v17)) = v18;
      }
    }
    else
    {
      v_3 = v8 | 1;
      v9 = *m_pMemory >> 12;
      v27 = v9;
      if ( v9 >= m_pMemory[1] )
      {
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: m_pMemory,
          nb: v9);
        v9 = v27;
      }
      *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v9)) = v_3;
      v10 = (unsigned int *)this->m_pMemory;
      v11 = *v10 >> 12;
      v12 = (unsigned int)v >> 6;
      if ( v11 >= v10[1] )
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v10,
          nb: *v10 >> 12);
      *(_BYTE *)(((*v10)++ & 0xFFF) + *(_DWORD *)(v10[3] + 4 * v11)) = v12;
    }
  }
  else
  {
    v5 = (unsigned int *)this->m_pMemory;
    v6 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
    if ( v6 >= this->m_pMemory->m_nMorphTargetId )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: *v5 >> 12);
    *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = 4 * (_BYTE)v;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186B20
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
        unsigned int **this,
        int a2)
{
  unsigned int *v2; // esi
  unsigned int v3; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi
  unsigned int **v7; // [esp+Ch] [ebp-4h]

  v2 = *this;
  v3 = **this >> 12;
  v7 = this;
  if ( (unsigned int)(a2 + 64) > 0x7F )
  {
    if ( v3 >= v2[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v2, nb: v3);
      this = v7;
    }
    *(_BYTE *)(((*v2)++ & 0xFFF) + *(_DWORD *)(v2[3] + 4 * v3)) = (2 * a2) | 1;
    v5 = *this;
    v6 = **this >> 12;
    if ( v6 >= (*this)[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: **this >> 12);
    *(_BYTE *)(((*v5)++ & 0xFFF) + *(_DWORD *)(v5[3] + 4 * v6)) = a2 >> 7;
    return 2;
  }
  else
  {
    if ( v3 >= v2[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v2, nb: v3);
    *(_BYTE *)(((*v2)++ & 0xFFF) + *(_DWORD *)(v2[3] + 4 * v3)) = 2 * a2;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186BE0
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteHLine(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteHLine(unsigned int **this, int a2)
{
  unsigned int *v3; // esi
  unsigned int v4; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi
  int v7; // ebx
  int v8; // edx
  int result; // eax
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // edi
  unsigned int **v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+1Ch] [ebp+8h]

  v3 = *this;
  v4 = **this >> 12;
  v14 = this;
  if ( (unsigned int)(a2 + 2048) > 0xFFF )
  {
    if ( v4 >= v3[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v3, nb: v4);
      this = v14;
    }
    *(_BYTE *)(((*v3)++ & 0xFFF) + *(_DWORD *)(v3[3] + 4 * v4)) = (16 * a2) | 1;
    v10 = *this;
    v11 = a2 >> 4;
    v12 = **this >> 12;
    v15 = a2 >> 4;
    if ( v12 >= (*this)[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v10, nb: v12);
      LOBYTE(v11) = v15;
    }
    *(_BYTE *)(((*v10)++ & 0xFFF) + *(_DWORD *)(v10[3] + 4 * v12)) = v11;
    v5 = *v14;
    v13 = **v14 >> 12;
    v7 = a2 >> 12;
    if ( v13 >= (*v14)[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: **v14 >> 12);
    v8 = *(_DWORD *)(v5[3] + 4 * v13);
    result = 3;
  }
  else
  {
    if ( v4 >= v3[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v3, nb: v4);
      this = v14;
    }
    *(_BYTE *)(((*v3)++ & 0xFFF) + *(_DWORD *)(v3[3] + 4 * v4)) = 16 * a2;
    v5 = *this;
    v6 = **this >> 12;
    v7 = a2 >> 4;
    if ( v6 >= (*this)[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: **this >> 12);
    v8 = *(_DWORD *)(v5[3] + 4 * v6);
    result = 2;
  }
  *(_BYTE *)(((*v5)++ & 0xFFF) + v8) = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186D00
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteVLine(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteVLine(unsigned int **this, int a2)
{
  unsigned int *v3; // esi
  unsigned int v4; // edi
  unsigned int *v5; // esi
  unsigned int v6; // edi
  int v7; // ebx
  int v8; // edx
  int result; // eax
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // edi
  unsigned int **v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+1Ch] [ebp+8h]

  v3 = *this;
  v4 = **this >> 12;
  v14 = this;
  if ( (unsigned int)(a2 + 2048) > 0xFFF )
  {
    if ( v4 >= v3[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v3, nb: v4);
      this = v14;
    }
    *(_BYTE *)(((*v3)++ & 0xFFF) + *(_DWORD *)(v3[3] + 4 * v4)) = (16 * a2) | 3;
    v10 = *this;
    v11 = a2 >> 4;
    v12 = **this >> 12;
    v15 = a2 >> 4;
    if ( v12 >= (*this)[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v10, nb: v12);
      LOBYTE(v11) = v15;
    }
    *(_BYTE *)(((*v10)++ & 0xFFF) + *(_DWORD *)(v10[3] + 4 * v12)) = v11;
    v5 = *v14;
    v13 = **v14 >> 12;
    v7 = a2 >> 12;
    if ( v13 >= (*v14)[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: **v14 >> 12);
    v8 = *(_DWORD *)(v5[3] + 4 * v13);
    result = 3;
  }
  else
  {
    if ( v4 >= v3[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v3, nb: v4);
      this = v14;
    }
    *(_BYTE *)(((*v3)++ & 0xFFF) + *(_DWORD *)(v3[3] + 4 * v4)) = (16 * a2) | 2;
    v5 = *this;
    v6 = **this >> 12;
    v7 = a2 >> 4;
    if ( v6 >= (*this)[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v5,
        nb: **this >> 12);
    v8 = *(_DWORD *)(v5[3] + 4 * v6);
    result = 2;
  }
  *(_BYTE *)(((*v5)++ & 0xFFF) + v8) = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186E20
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteLine(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteLine(
        CUtlMemory<MorphVertexInfo_t,int> *this,
        int x,
        int y)
{
  int v3; // ebx
  MorphVertexInfo_t *v5; // ecx
  MorphVertexInfo_t *v6; // ecx
  MorphVertexInfo_t *v8; // ecx
  int v9; // eax
  int v10; // ebx
  MorphVertexInfo_t *v11; // ecx
  MorphVertexInfo_t *v12; // ecx
  MorphVertexInfo_t *v13; // ecx
  MorphVertexInfo_t *v14; // ecx
  MorphVertexInfo_t *v15; // ecx
  MorphVertexInfo_t *v16; // ecx
  unsigned int *m_pMemory; // edi
  unsigned int v18; // eax
  unsigned int *v19; // edi
  unsigned int v20; // eax
  int v21; // eax
  unsigned int *v22; // edi
  unsigned int v23; // ebx
  unsigned int *v24; // edi
  unsigned int v25; // ebx
  unsigned int *v26; // esi
  unsigned int v27; // edi
  char v28; // bl
  unsigned int v29; // [esp+8h] [ebp-4h]

  v3 = x;
  if ( (unsigned int)(x + 32) > 0x3F || (unsigned int)(y + 32) > 0x3F )
  {
    if ( (unsigned int)(x + 512) > 0x3FF || (unsigned int)(y + 512) > 0x3FF )
    {
      if ( (unsigned int)(x + 0x2000) > 0x3FFF || (unsigned int)(y + 0x2000) > 0x3FFF )
      {
        m_pMemory = (unsigned int *)this->m_pMemory;
        HIBYTE(x) = (16 * x) | 7;
        v18 = *m_pMemory >> 12;
        v29 = v18;
        if ( v18 >= m_pMemory[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: m_pMemory,
            nb: v18);
          v18 = v29;
        }
        *(_BYTE *)(((*m_pMemory)++ & 0xFFF) + *(_DWORD *)(m_pMemory[3] + 4 * v18)) = HIBYTE(x);
        v19 = (unsigned int *)this->m_pMemory;
        v20 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
        x = v20;
        if ( v20 >= v19[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v19,
            nb: v20);
          v20 = x;
        }
        *(_BYTE *)((*v19 & 0xFFF) + *(_DWORD *)(v19[3] + 4 * v20)) = v3 >> 4;
        v21 = y;
        ++*v19;
        v22 = (unsigned int *)this->m_pMemory;
        HIBYTE(x) = ((_BYTE)v21 << 6) | (v3 >> 12) & 0x3F;
        v23 = *v22 >> 12;
        if ( v23 >= v22[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v22,
            nb: *v22 >> 12);
          v21 = y;
        }
        *(_BYTE *)(((*v22)++ & 0xFFF) + *(_DWORD *)(v22[3] + 4 * v23)) = HIBYTE(x);
        v24 = (unsigned int *)this->m_pMemory;
        v25 = (unsigned int)this->m_pMemory->m_nVertexId >> 12;
        x = v21 >> 2;
        if ( v25 >= v24[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v24,
            nb: v25);
          v21 = y;
        }
        *(_BYTE *)(((*v24)++ & 0xFFF) + *(_DWORD *)(v24[3] + 4 * v25)) = x;
        v26 = (unsigned int *)this->m_pMemory;
        v27 = *v26 >> 12;
        v28 = v21 >> 10;
        if ( v27 >= v26[1] )
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v26,
            nb: *v26 >> 12);
        *(_BYTE *)(((*v26)++ & 0xFFF) + *(_DWORD *)(v26[3] + 4 * v27)) = v28;
        return 5;
      }
      else
      {
        v13 = this->m_pMemory;
        HIBYTE(x) = (16 * x) | 6;
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this: (unsigned int *)v13,
          val: (char *)&x + 3);
        v14 = this->m_pMemory;
        HIBYTE(x) = v3 >> 4;
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this: (unsigned int *)v14,
          val: (char *)&x + 3);
        v15 = this->m_pMemory;
        HIBYTE(x) = (4 * y) | (v3 >> 12) & 3;
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this: (unsigned int *)v15,
          val: (char *)&x + 3);
        v16 = this->m_pMemory;
        HIBYTE(y) = y >> 6;
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this: (unsigned int *)v16,
          val: (char *)&y + 3);
        return 4;
      }
    }
    else
    {
      v8 = this->m_pMemory;
      HIBYTE(x) = (16 * x) | 5;
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        this: (unsigned int *)v8,
        val: (char *)&x + 3);
      v9 = v3;
      v10 = y;
      v11 = this->m_pMemory;
      HIBYTE(y) = ((_BYTE)y << 6) | (v9 >> 4) & 0x3F;
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        this: (unsigned int *)v11,
        val: (char *)&y + 3);
      v12 = this->m_pMemory;
      HIBYTE(y) = v10 >> 2;
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        this: (unsigned int *)v12,
        val: (char *)&y + 3);
      return 3;
    }
  }
  else
  {
    v5 = this->m_pMemory;
    HIBYTE(x) = (16 * x) | 4;
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
      this: (unsigned int *)v5,
      val: (char *)&x + 3);
    v6 = this->m_pMemory;
    HIBYTE(y) = (4 * y) | (v3 >> 4) & 3;
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
      this: (unsigned int *)v6,
      val: (char *)&y + 3);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101870A0
// Name: public: unsigned int GFxPathDataEncoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteQuad(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteQuad(
        unsigned int **this,
        int result,
        int cy,
        int a4,
        int ay)
{
  int v5; // ebx
  CUtlMemory<MorphVertexInfo_t,int> *v7; // edx
  CUtlMemory<MorphVertexInfo_t,int> *v8; // edi
  int v9; // eax
  int v10; // edx
  unsigned int *v11; // edi
  unsigned int v12; // ecx
  unsigned int *v13; // edi
  char v14; // cl
  unsigned int v15; // ebx
  char v16; // cl
  unsigned int *v17; // esi
  unsigned int v18; // edi
  char v19; // bl
  int v20; // eax
  unsigned int *v21; // edi
  unsigned int v22; // ecx
  unsigned int *v23; // ecx
  unsigned int v24; // edi
  unsigned int *v25; // edi
  unsigned int v26; // ebx
  char v27; // cl
  unsigned int *v28; // esi
  unsigned int v29; // edi
  int v30; // edx
  unsigned int *v31; // edi
  unsigned int v32; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // edi
  unsigned int *v35; // edi
  unsigned int v36; // ebx
  unsigned int *v37; // edi
  unsigned int v38; // ebx
  int v39; // ecx
  int v40; // ebx
  unsigned int v41; // edi
  unsigned int *v42; // edi
  unsigned int v43; // ecx
  unsigned int *v44; // ecx
  unsigned int v45; // edi
  unsigned int *v46; // ecx
  unsigned int v47; // edi
  unsigned int *v48; // edi
  char v49; // cl
  unsigned int v50; // ebx
  unsigned int *v51; // edi
  char v52; // cl
  unsigned int v53; // ebx
  int v54; // edx
  int v55; // ebx
  unsigned int v56; // edi
  unsigned int *v57; // ecx
  unsigned int *v58; // ecx
  unsigned int *v59; // ecx
  int v60; // ebx
  unsigned int *v61; // ecx
  unsigned int *v62; // ecx
  unsigned int *v63; // ecx
  unsigned int *v64; // ecx
  unsigned int *v65; // ecx
  unsigned int *v66; // ecx
  unsigned int *v67; // ecx
  int v68; // ebx
  unsigned int *v69; // ecx
  unsigned int *v70; // ecx
  unsigned int *v71; // ecx
  unsigned int *v72; // ecx
  unsigned int *v73; // ecx
  unsigned int *v74; // ecx
  unsigned int *v75; // ecx
  int v76; // ebx
  unsigned int *v77; // ecx
  int v78; // ebx
  unsigned int *v79; // ecx
  unsigned int *v80; // ecx
  unsigned int *v81; // edi
  unsigned int v82; // ecx
  unsigned int *v83; // ecx
  unsigned int v84; // edi
  unsigned int *v85; // ecx
  unsigned int v86; // edi
  unsigned int *v87; // ecx
  unsigned int v88; // edi
  CUtlMemory<MorphVertexInfo_t,int> *v89; // ecx
  unsigned int v90; // edi
  unsigned int *v91; // edi
  unsigned int v92; // ebx
  unsigned int *v93; // edi
  unsigned int v94; // ebx
  int v95; // ecx
  unsigned int *v96; // edi
  unsigned int v97; // ebx
  unsigned int *v98; // edi
  unsigned int v99; // edi
  CUtlMemory<MorphVertexInfo_t,int> *maxV; // [esp+Ch] [ebp-8h]
  int maxVa; // [esp+Ch] [ebp-8h]
  int maxVb; // [esp+Ch] [ebp-8h]
  int maxVc; // [esp+Ch] [ebp-8h]
  int maxVd; // [esp+Ch] [ebp-8h]
  int maxVe; // [esp+Ch] [ebp-8h]
  int maxVf; // [esp+Ch] [ebp-8h]
  int minV; // [esp+10h] [ebp-4h]

  v5 = cy;
  v7 = (CUtlMemory<MorphVertexInfo_t,int> *)result;
  v8 = (CUtlMemory<MorphVertexInfo_t,int> *)result;
  minV = result;
  maxV = (CUtlMemory<MorphVertexInfo_t,int> *)result;
  if ( cy < result )
  {
    v7 = (CUtlMemory<MorphVertexInfo_t,int> *)cy;
    minV = cy;
  }
  if ( cy > result )
  {
    v8 = (CUtlMemory<MorphVertexInfo_t,int> *)cy;
    maxV = (CUtlMemory<MorphVertexInfo_t,int> *)cy;
  }
  v9 = a4;
  if ( a4 < (int)v7 )
  {
    v7 = (CUtlMemory<MorphVertexInfo_t,int> *)a4;
    minV = a4;
  }
  if ( a4 > (int)v8 )
    maxV = (CUtlMemory<MorphVertexInfo_t,int> *)a4;
  if ( ay < (int)v7 )
    minV = ay;
  v10 = (int)maxV;
  if ( ay > (int)maxV )
    v10 = ay;
  if ( minV < -16 || v10 > 15 )
  {
    if ( minV < -64 || v10 > 63 )
    {
      if ( minV < -256 || v10 > 255 )
      {
        if ( minV < -1024 || v10 > 1023 )
        {
          if ( minV >= -4096 && v10 <= 4095 )
          {
            HIBYTE(cy) = (16 * result) | 0xC;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: *this,
              val: (char *)&cy + 3);
            v57 = *this;
            HIBYTE(cy) = result >> 4;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v57,
              val: (char *)&cy + 3);
            v58 = *this;
            HIBYTE(result) = (2 * v5) | (result >> 12) & 1;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v58,
              val: (char *)&result + 3);
            v59 = *this;
            HIBYTE(result) = ((_BYTE)a4 << 6) | (v5 >> 7) & 0x3F;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v59,
              val: (char *)&result + 3);
            v60 = a4;
            v61 = *this;
            HIBYTE(a4) = a4 >> 2;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v61,
              val: (char *)&a4 + 3);
            v62 = *this;
            HIBYTE(a4) = (8 * ay) | (v60 >> 10) & 7;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v62,
              val: (char *)&a4 + 3);
            v63 = *this;
            HIBYTE(a4) = ay >> 5;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v63,
              val: (char *)&a4 + 3);
            return 7;
          }
          if ( minV >= -16384 && v10 <= 0x3FFF )
          {
            HIBYTE(cy) = (16 * result) | 0xD;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: *this,
              val: (char *)&cy + 3);
            v64 = *this;
            HIBYTE(cy) = result >> 4;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v64,
              val: (char *)&cy + 3);
            v65 = *this;
            HIBYTE(result) = (8 * v5) | (result >> 12) & 7;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v65,
              val: (char *)&result + 3);
            v66 = *this;
            HIBYTE(result) = v5 >> 5;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v66,
              val: (char *)&result + 3);
            v67 = *this;
            HIBYTE(result) = (4 * a4) | (v5 >> 13) & 3;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v67,
              val: (char *)&result + 3);
            v68 = a4;
            v69 = *this;
            HIBYTE(a4) = a4 >> 6;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v69,
              val: (char *)&a4 + 3);
            v70 = *this;
            HIBYTE(a4) = (2 * ay) | (v68 >> 14) & 1;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v70,
              val: (char *)&a4 + 3);
            v71 = *this;
            HIBYTE(a4) = ay >> 7;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v71,
              val: (char *)&a4 + 3);
            return 8;
          }
          if ( minV >= -65536 && v10 <= 0xFFFF )
          {
            HIBYTE(cy) = (16 * result) | 0xE;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: *this,
              val: (char *)&cy + 3);
            v72 = *this;
            HIBYTE(cy) = result >> 4;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v72,
              val: (char *)&cy + 3);
            v73 = *this;
            HIBYTE(result) = (32 * v5) | (result >> 12) & 0x1F;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v73,
              val: (char *)&result + 3);
            v74 = *this;
            HIBYTE(result) = v5 >> 3;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v74,
              val: (char *)&result + 3);
            v75 = *this;
            HIBYTE(result) = ((_BYTE)a4 << 6) | (v5 >> 11) & 0x3F;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v75,
              val: (char *)&result + 3);
            v76 = a4;
            HIBYTE(a4) = a4 >> 2;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: *this,
              val: (char *)&a4 + 3);
            v77 = *this;
            HIBYTE(a4) = ((_BYTE)ay << 7) | (v76 >> 10) & 0x7F;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v77,
              val: (char *)&a4 + 3);
            v78 = ay;
            v79 = *this;
            HIBYTE(a4) = ay >> 1;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v79,
              val: (char *)&a4 + 3);
            v80 = *this;
            HIBYTE(a4) = v78 >> 9;
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              this: v80,
              val: (char *)&a4 + 3);
            return 9;
          }
          v81 = *this;
          HIBYTE(cy) = (16 * result) | 0xF;
          v82 = *v81 >> 12;
          maxVe = v82;
          if ( v82 >= v81[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v81,
              nb: v82);
            v9 = a4;
            v82 = maxVe;
          }
          *(_BYTE *)(((*v81)++ & 0xFFF) + *(_DWORD *)(v81[3] + 4 * v82)) = HIBYTE(cy);
          maxVf = result >> 4;
          v83 = *this;
          v84 = **this >> 12;
          cy = (int)v83;
          if ( v84 >= v83[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v83,
              nb: v84);
            v9 = a4;
            v83 = (unsigned int *)cy;
          }
          *(_BYTE *)((*v83 & 0xFFF) + *(_DWORD *)(v83[3] + 4 * v84)) = maxVf;
          ++*(_DWORD *)cy;
          HIBYTE(result) = ((_BYTE)v5 << 7) | (result >> 12) & 0x7F;
          v85 = *this;
          v86 = **this >> 12;
          cy = (int)v85;
          if ( v86 >= v85[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v85,
              nb: v86);
            v9 = a4;
            v85 = (unsigned int *)cy;
          }
          *(_BYTE *)((*v85 & 0xFFF) + *(_DWORD *)(v85[3] + 4 * v86)) = HIBYTE(result);
          ++*(_DWORD *)cy;
          result = v5 >> 1;
          v87 = *this;
          v88 = **this >> 12;
          cy = (int)v87;
          if ( v88 >= v87[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v87,
              nb: v88);
            v9 = a4;
            v87 = (unsigned int *)cy;
          }
          *(_BYTE *)((*v87 & 0xFFF) + *(_DWORD *)(v87[3] + 4 * v88)) = result;
          ++*(_DWORD *)cy;
          cy = v5 >> 9;
          v89 = (CUtlMemory<MorphVertexInfo_t,int> *)*this;
          v90 = **this >> 12;
          result = (int)v89;
          if ( v90 >= v89->m_nAllocationCount )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: (unsigned int *)v89,
              nb: v90);
            v9 = a4;
            v89 = (CUtlMemory<MorphVertexInfo_t,int> *)result;
          }
          *(_BYTE *)(((int)v89->m_pMemory & 0xFFF) + *(&v89[1].m_pMemory->m_nVertexId + v90)) = cy;
          ++*(_DWORD *)result;
          v91 = *this;
          HIBYTE(result) = (4 * v9) | (v5 >> 17) & 3;
          v92 = *v91 >> 12;
          if ( v92 >= v91[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v91,
              nb: *v91 >> 12);
            v9 = a4;
          }
          *(_BYTE *)(((*v91)++ & 0xFFF) + *(_DWORD *)(v91[3] + 4 * v92)) = HIBYTE(result);
          v93 = *this;
          v94 = **this >> 12;
          result = v9 >> 6;
          if ( v94 >= v93[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v93,
              nb: v94);
            v9 = a4;
          }
          *(_BYTE *)(((*v93)++ & 0xFFF) + *(_DWORD *)(v93[3] + 4 * v94)) = result;
          v95 = ay;
          v96 = *this;
          v97 = **this >> 12;
          HIBYTE(a4) = (32 * ay) | (v9 >> 14) & 0x1F;
          if ( v97 >= v96[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v96,
              nb: v97);
            v95 = ay;
          }
          *(_BYTE *)(((*v96)++ & 0xFFF) + *(_DWORD *)(v96[3] + 4 * v97)) = HIBYTE(a4);
          v98 = *this;
          v26 = **this >> 12;
          a4 = v95 >> 3;
          if ( v26 >= v98[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v98,
              nb: v26);
            v95 = ay;
          }
          *(_BYTE *)(((*v98)++ & 0xFFF) + *(_DWORD *)(v98[3] + 4 * v26)) = a4;
          v28 = *this;
          v99 = *v28 >> 12;
          LOBYTE(v26) = v95 >> 11;
          if ( v99 >= v28[1] )
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v28,
              nb: *v28 >> 12);
          v30 = *(_DWORD *)(v28[3] + 4 * v99);
          v20 = 10;
        }
        else
        {
          v42 = *this;
          HIBYTE(cy) = (16 * result) | 0xB;
          v43 = *v42 >> 12;
          maxVd = v43;
          if ( v43 >= v42[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v42,
              nb: v43);
            v9 = a4;
            v43 = maxVd;
          }
          *(_BYTE *)(((*v42)++ & 0xFFF) + *(_DWORD *)(v42[3] + 4 * v43)) = HIBYTE(cy);
          HIBYTE(result) = ((_BYTE)v5 << 7) | (result >> 4) & 0x7F;
          v44 = *this;
          v45 = **this >> 12;
          cy = (int)v44;
          if ( v45 >= v44[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v44,
              nb: v45);
            v9 = a4;
            v44 = (unsigned int *)cy;
          }
          *(_BYTE *)((*v44 & 0xFFF) + *(_DWORD *)(v44[3] + 4 * v45)) = HIBYTE(result);
          ++*(_DWORD *)cy;
          result = v5 >> 1;
          v46 = *this;
          v47 = **this >> 12;
          cy = (int)v46;
          if ( v47 >= v46[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v46,
              nb: v47);
            v9 = a4;
            v46 = (unsigned int *)cy;
          }
          *(_BYTE *)((*v46 & 0xFFF) + *(_DWORD *)(v46[3] + 4 * v47)) = result;
          ++*(_DWORD *)cy;
          v48 = *this;
          v49 = (v5 >> 9) & 3 | (4 * v9);
          v50 = **this >> 12;
          HIBYTE(result) = v49;
          if ( v50 >= v48[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v48,
              nb: v50);
            v9 = a4;
          }
          *(_BYTE *)(((*v48)++ & 0xFFF) + *(_DWORD *)(v48[3] + 4 * v50)) = HIBYTE(result);
          v51 = *this;
          v52 = (v9 >> 6) & 0x1F | (32 * ay);
          v53 = **this >> 12;
          HIBYTE(a4) = v52;
          if ( v53 >= v51[1] )
          {
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v51,
              nb: v53);
            v52 = HIBYTE(a4);
          }
          v54 = *(_DWORD *)(v51[3] + 4 * v53);
          v55 = ay;
          *(_BYTE *)(((*v51)++ & 0xFFF) + v54) = v52;
          v28 = *this;
          v56 = *v28 >> 12;
          v26 = v55 >> 3;
          if ( v56 >= v28[1] )
            GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
              this: v28,
              nb: *v28 >> 12);
          v30 = *(_DWORD *)(v28[3] + 4 * v56);
          v20 = 6;
        }
      }
      else
      {
        v31 = *this;
        HIBYTE(cy) = (16 * result) | 0xA;
        v32 = *v31 >> 12;
        maxVc = v32;
        if ( v32 >= v31[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v31,
            nb: v32);
          v9 = a4;
          v32 = maxVc;
        }
        *(_BYTE *)(((*v31)++ & 0xFFF) + *(_DWORD *)(v31[3] + 4 * v32)) = HIBYTE(cy);
        HIBYTE(result) = (32 * v5) | (result >> 4) & 0x1F;
        v33 = *this;
        v34 = **this >> 12;
        cy = (int)v33;
        if ( v34 >= v33[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v33,
            nb: v34);
          v9 = a4;
          v33 = (unsigned int *)cy;
        }
        *(_BYTE *)((*v33 & 0xFFF) + *(_DWORD *)(v33[3] + 4 * v34)) = HIBYTE(result);
        ++*(_DWORD *)cy;
        v35 = *this;
        HIBYTE(result) = ((_BYTE)v9 << 6) | (v5 >> 3) & 0x3F;
        v36 = *v35 >> 12;
        if ( v36 >= v35[1] )
        {
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v35,
            nb: *v35 >> 12);
          v9 = a4;
        }
        *(_BYTE *)(((*v35)++ & 0xFFF) + *(_DWORD *)(v35[3] + 4 * v36)) = HIBYTE(result);
        v37 = *this;
        v38 = **this >> 12;
        HIBYTE(a4) = ((_BYTE)ay << 7) | (v9 >> 2) & 0x7F;
        if ( v38 >= v37[1] )
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v37,
            nb: v38);
        v39 = *(_DWORD *)(v37[3] + 4 * v38);
        v40 = ay;
        *(_BYTE *)(((*v37)++ & 0xFFF) + v39) = HIBYTE(a4);
        v28 = *this;
        v41 = *v28 >> 12;
        v26 = v40 >> 1;
        if ( v41 >= v28[1] )
          GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            this: v28,
            nb: *v28 >> 12);
        v30 = *(_DWORD *)(v28[3] + 4 * v41);
        v20 = 5;
      }
    }
    else
    {
      v21 = *this;
      HIBYTE(cy) = (16 * result) | 9;
      v22 = *v21 >> 12;
      maxVb = v22;
      if ( v22 >= v21[1] )
      {
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v21, nb: v22);
        v9 = a4;
        v22 = maxVb;
      }
      *(_BYTE *)(((*v21)++ & 0xFFF) + *(_DWORD *)(v21[3] + 4 * v22)) = HIBYTE(cy);
      HIBYTE(result) = (8 * v5) | (result >> 4) & 7;
      v23 = *this;
      v24 = **this >> 12;
      cy = (int)v23;
      if ( v24 >= v23[1] )
      {
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v23, nb: v24);
        v9 = a4;
        v23 = (unsigned int *)cy;
      }
      *(_BYTE *)((*v23 & 0xFFF) + *(_DWORD *)(v23[3] + 4 * v24)) = HIBYTE(result);
      ++*(_DWORD *)cy;
      v25 = *this;
      HIBYTE(result) = (4 * v9) | (v5 >> 5) & 3;
      v26 = *v25 >> 12;
      if ( v26 >= v25[1] )
      {
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v25,
          nb: *v25 >> 12);
        v9 = a4;
      }
      *(_BYTE *)((*v25 & 0xFFF) + *(_DWORD *)(v25[3] + 4 * v26)) = HIBYTE(result);
      v27 = ay;
      ++*v25;
      v28 = *this;
      v29 = *v28 >> 12;
      LOBYTE(v26) = (v9 >> 6) & 1 | (2 * v27);
      if ( v29 >= v28[1] )
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v28,
          nb: *v28 >> 12);
      v30 = *(_DWORD *)(v28[3] + 4 * v29);
      v20 = 4;
    }
    *(_BYTE *)(((*v28)++ & 0xFFF) + v30) = v26;
  }
  else
  {
    v11 = *this;
    HIBYTE(cy) = (16 * result) | 8;
    v12 = *v11 >> 12;
    maxVa = v12;
    if ( v12 >= v11[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v11, nb: v12);
      v9 = a4;
      v12 = maxVa;
    }
    *(_BYTE *)(((*v11)++ & 0xFFF) + *(_DWORD *)(v11[3] + 4 * v12)) = HIBYTE(cy);
    v13 = *this;
    v14 = ((_BYTE)v9 << 6) | (2 * v5) & 0x3F | (result >> 4) & 1;
    v15 = **this >> 12;
    HIBYTE(result) = v14;
    if ( v15 >= v13[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v13, nb: v15);
      v9 = a4;
    }
    *(_BYTE *)((*v13 & 0xFFF) + *(_DWORD *)(v13[3] + 4 * v15)) = HIBYTE(result);
    v16 = ay;
    ++*v13;
    v17 = *this;
    v18 = *v17 >> 12;
    v19 = (v9 >> 2) & 7 | (8 * v16);
    if ( v18 >= v17[1] )
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        this: v17,
        nb: *v17 >> 12);
    *(_BYTE *)(((*v17)++ & 0xFFF) + *(_DWORD *)(v17[3] + 4 * v18)) = v19;
    return 3;
  }
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x10187BA0
// Name: public: GFxFontCompactor::GFxFontCompactor(class GArrayPagedLH_POD<unsigned char,12,256,261> __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxFontCompactor::GFxFontCompactor(_DWORD *this, int a2)
{
  *this = &GRefCountImplCore::`vftable';
  *(this + 1) = 1;
  *this = &GFxFontCompactor::`vftable';
  *(this + 2) = a2;
  *(this + 3) = a2;
  *(this + 4) = 0;
  *(this + 5) = 0;
  *(this + 6) = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
  *(this + 9) = 0;
  *(this + 10) = 0;
  *(this + 11) = 0;
  *(this + 12) = 0;
  *(this + 13) = 0;
  *(this + 14) = 0;
  *(this + 15) = 0;
  *(this + 16) = 0;
  *(this + 17) = 0;
  *(this + 18) = 0;
  *(this + 19) = 0;
  *(this + 20) = 0;
  *(this + 21) = 0;
  *(this + 22) = 0;
  *(this + 23) = 0;
  *(this + 24) = 0;
  *(this + 25) = 0;
  *(this + 26) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10187C10
// Name: public: virtual GFxFontCompactor::~GFxFontCompactor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::~GFxFontCompactor(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  this->m_Memory.m_pMemory = (CVertexMorphDict::MorphVertexList_t *)&GFxFontCompactor::`vftable';
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 23);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 19);
  GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this: (CInternalFileSystemPassThru<IBaseFileSystem> *)this + 9);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 14);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 10);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 6);
  GHashSetBase<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType>>::~GHashSetBase<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType>>(this: (ScaleformImageLoader *)(this + 1));
  GHashSetBase<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType>>::~GHashSetBase<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::ContourKeyType,GFxFontCompactor::ContourKeyType>>(this: (ScaleformImageLoader *)&this->m_pElements);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10187C70
// Name: private: void GFxFontCompactor::normalizeLastContour(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxFontCompactor::normalizeLastContour(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  int v2; // esi
  unsigned int *v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  unsigned int v7; // ecx
  unsigned int result; // eax
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // eax
  int v13; // eax
  unsigned int *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  int *v17; // edx
  unsigned int v18; // ecx
  int v19; // edx
  int v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // ebx
  int v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // ecx
  void *v30; // eax
  void *v31; // eax
  unsigned int v32; // [esp+Ch] [ebp-1Ch] BYREF
  int minX; // [esp+10h] [ebp-18h] BYREF
  int minY; // [esp+14h] [ebp-14h]
  unsigned int start; // [esp+18h] [ebp-10h]
  unsigned int *v36; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  unsigned int v38; // [esp+24h] [ebp-4h]

  v2 = *((_DWORD *)this + 9);
  v3 = (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 13) + 4 * ((unsigned int)(*((_DWORD *)this + 10) - 1) >> 6))
                      + 8 * ((*((_DWORD *)this + 10) - 1) & 0x3F));
  v4 = *(_DWORD *)(*(_DWORD *)(v2 + 4 * ((unsigned int)(*((_DWORD *)this + 6) - 1) >> 6))
                 + 4 * ((*((_DWORD *)this + 6) - 1) & 0x3F));
  v36 = v3;
  if ( (v4 & 1) == 0 )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * (*v3 >> 6)) + 4 * (*v3 & 0x3F));
    v38 = v5;
    if ( v5 == v4 )
    {
      --v3[1];
      v6 = *((_DWORD *)this + 6);
      if ( v6 != 0 )
        *((_DWORD *)this + 6) = v6 - 1;
    }
  }
  if ( v3[1] < 3 )
  {
    v7 = *v3;
    if ( v7 < *((_DWORD *)this + 6) )
      *((_DWORD *)this + 6) = v7;
    result = *((_DWORD *)this + 10);
    if ( result != 0 )
      *((_DWORD *)this + 10) = --result;
    return result;
  }
  result = *v3;
  v9 = *((_DWORD *)this + 9);
  minX = *(__int16 *)(*(_DWORD *)(v9 + 4 * (*v3 >> 6)) + 4 * (*v3 & 0x3F)) >> 1;
  minY = *(__int16 *)(*(_DWORD *)(v9 + 4 * (result >> 6)) + 4 * (result & 0x3F) + 2);
  v10 = 1;
  v11 = 0;
  if ( v36[1] <= 1 )
    return result;
  ++result;
  v32 = v36[1];
  i = result;
  do
  {
    v12 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * (result >> 6)) + 4 * (result & 0x3F));
    v38 = v12;
    if ( (v12 & 1) != 0 )
    {
      ++v10;
      ++i;
      goto LABEL_20;
    }
    v13 = SHIWORD(v12);
    if ( v13 < minY )
    {
      minY = v13;
LABEL_19:
      start = v10;
      v11 = v10;
      goto LABEL_20;
    }
    if ( v13 == minY && (__int16)v38 >> 1 < minX )
    {
      minX = (__int16)v38;
      goto LABEL_19;
    }
LABEL_20:
    ++v10;
    result = ++i;
  }
  while ( v10 < v32 );
  if ( v11 == 0 )
    return result;
  v14 = v36;
  *((_DWORD *)this + 14) = 0;
  v38 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * ((v11 + *v14) >> 6)) + 4 * ((v11 + *v14) & 0x3F));
  v15 = *((_DWORD *)this + 14);
  LOWORD(v38) = v38 & 0xFFFE;
  v16 = v15 >> 6;
  v32 = v16;
  if ( v16 >= *((_DWORD *)this + 15) )
  {
    GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
      this: (unsigned int *)this + 14,
      nb: v16);
    v16 = v32;
  }
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 4 * v16) + 4 * (*((_DWORD *)this + 14) & 0x3F)) = v38;
  v17 = (int *)v36;
  ++*((_DWORD *)this + 14);
  i = 1;
  if ( (unsigned int)v17[1] > 1 )
  {
    while ( 2 )
    {
      v18 = v17[1];
      minX = *v17;
      v19 = ++v11 % v18;
      v32 = v18;
      v20 = *((_DWORD *)this + 9);
      v38 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * ((unsigned int)(minX + v19) >> 6)) + 4 * ((minX + v19) & 0x3F));
      if ( (v38 & 1) != 0 )
      {
        ++i;
        start = v11 + 1;
        v21 = *((_DWORD *)this + 14) >> 6;
        v32 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * ((minX + start % v32) >> 6)) + 4 * ((minX + start % v32) & 0x3F));
        if ( v21 >= *((_DWORD *)this + 15) )
          GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
            this: (unsigned int *)this + 14,
            nb: v21);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 4 * v21) + 4 * ((*((_DWORD *)this + 14))++ & 0x3F)) = v38;
        v22 = *((_DWORD *)this + 14) >> 6;
        if ( v22 >= *((_DWORD *)this + 15) )
          GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
            this: (unsigned int *)this + 14,
            nb: *((_DWORD *)this + 14) >> 6);
        v23 = *(_DWORD *)(*((_DWORD *)this + 17) + 4 * v22);
        v24 = v32;
        v11 = start;
        goto LABEL_36;
      }
      v25 = *((_DWORD *)this + 17);
      v32 = *((_DWORD *)this + 14) - 1;
      if ( (((unsigned __int16)v38 ^ *(_WORD *)(*(_DWORD *)(v25 + 4 * (v32 >> 6)) + 4 * (v32 & 0x3F))) & 0xFFFE) != 0
        || HIWORD(v38) != *(_WORD *)(*(_DWORD *)(v25 + 4 * (v32 >> 6)) + 4 * (v32 & 0x3F) + 2) )
      {
        v26 = *((_DWORD *)this + 14) >> 6;
        v32 = v26;
        if ( v26 >= *((_DWORD *)this + 15) )
        {
          GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
            this: (unsigned int *)this + 14,
            nb: v26);
          v26 = v32;
        }
        v23 = *(_DWORD *)(*((_DWORD *)this + 17) + 4 * v26);
        v24 = v38;
LABEL_36:
        *(_DWORD *)(v23 + 4 * ((*((_DWORD *)this + 14))++ & 0x3F)) = v24;
      }
      v17 = (int *)v36;
      if ( ++i >= v36[1] )
        break;
      continue;
    }
  }
  if ( (unsigned int)*v17 < *((_DWORD *)this + 6) )
    *((_DWORD *)this + 6) = *v17;
  v27 = 0;
  i = 0;
  if ( *((_DWORD *)this + 14) != 0 )
  {
    do
    {
      v28 = *((_DWORD *)this + 6) >> 6;
      minY = *(_DWORD *)(*((_DWORD *)this + 17) + 4 * (v27 >> 6)) + 4 * (v27 & 0x3F);
      if ( v28 >= *((_DWORD *)this + 7) )
      {
        v29 = *((_DWORD *)this + 8);
        if ( v28 >= v29 )
        {
          v30 = *((void **)this + 9);
          if ( v30 != nullptr )
          {
            v32 = 4 * v29 + 256;
            v31 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v30, a3: v32);
          }
          else
          {
            minX = 261;
            v31 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 256, a3: &minX);
          }
          *((_DWORD *)this + 8) += 64;
          *((_DWORD *)this + 9) = v31;
        }
        v32 = 261;
        *(_DWORD *)(*((_DWORD *)this + 9) + 4 * v28) = GMemory::pGlobalHeap->Alloc_2(
                                                         this: GMemory::pGlobalHeap,
                                                         a2: 256,
                                                         a3: &v32);
        ++*((_DWORD *)this + 7);
        v27 = i;
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v28) + 4 * ((*((_DWORD *)this + 6))++ & 0x3F)) = *(_DWORD *)minY;
      i = ++v27;
    }
    while ( v27 < *((_DWORD *)this + 14) );
    v17 = (int *)v36;
  }
  result = *((_DWORD *)this + 14);
  v17[1] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10188020
// Name: public: void GFxFontCompactor::MoveTo(short,short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::MoveTo(GFxFontCompactor *this, __int16 a2, __int16 a3)
{
  unsigned int v4; // ebx
  int v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+18h] [ebp+8h]

  if ( *((_DWORD *)this + 10) != 0 )
    GFxFontCompactor::normalizeLastContour((CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)this);
  v4 = *((_DWORD *)this + 10) >> 6;
  v8 = *((_DWORD *)this + 6);
  if ( v4 >= *((_DWORD *)this + 11) )
    GArrayPagedBase<GFxFontCompactor::GlyphInfoType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::GlyphInfoType,261>>::allocatePage(
      this: (unsigned int *)this + 10,
      result: v4);
  v5 = *(_DWORD *)(*((_DWORD *)this + 13) + 4 * v4);
  v6 = *((_DWORD *)this + 10) & 0x3F;
  *(_DWORD *)(v5 + 8 * v6) = v8;
  *(_DWORD *)(v5 + 8 * v6 + 4) = 1;
  ++*((_DWORD *)this + 10);
  v7 = *((_DWORD *)this + 6) >> 6;
  LOWORD(v9) = 2 * a2;
  HIWORD(v9) = a3;
  if ( v7 >= *((_DWORD *)this + 7) )
    GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
      this: (unsigned int *)this + 6,
      nb: v7);
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v7) + 4 * ((*((_DWORD *)this + 6))++ & 0x3F)) = v9;
}

//------------------------------------------------------------------------------
// Address: 0x101880C0
// Name: public: void GFxFontCompactor::LineTo(short,short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::LineTo(GFxFontCompactor *this, __int16 a2, __int16 a3)
{
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // edx
  int v7; // [esp+18h] [ebp+Ch]

  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 4 * ((unsigned int)(*((_DWORD *)this + 10) - 1) >> 6))
                 + 8 * ((*((_DWORD *)this + 10) - 1) & 0x3F)
                 + 4) == 0
    || (v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * ((unsigned int)(*((_DWORD *)this + 6) - 1) >> 6))
                       + 4 * ((*((_DWORD *)this + 6) - 1) & 0x3F)),
        a2 != (__int16)v4 >> 1)
    || a3 != HIWORD(v4) )
  {
    v5 = *((_DWORD *)this + 6) >> 6;
    HIWORD(v7) = a3;
    if ( v5 >= *((_DWORD *)this + 7) )
      GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
        this: (unsigned int *)this + 6,
        nb: v5);
    LOWORD(v7) = 2 * a2;
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v5) + 4 * ((*((_DWORD *)this + 6))++ & 0x3F)) = v7;
    v6 = *(_DWORD *)(*((_DWORD *)this + 13) + 4 * ((unsigned int)(*((_DWORD *)this + 10) - 1) >> 6));
    ++*(_DWORD *)(v6 + 8 * ((*((_DWORD *)this + 10) - 1) & 0x3F) + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188170
// Name: public: void GFxFontCompactor::QuadTo(short,short,short,short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::QuadTo(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this,
        __int16 cx,
        __int16 cy,
        const CVertexMorphDict::MorphVertexList_t *ax,
        __int16 ay)
{
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ebx
  int v9; // ecx
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]
  int v12; // [esp+Ch] [ebp-4h]

  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 4 * ((unsigned int)(*((_DWORD *)this + 10) - 1) >> 6))
                 + 8 * ((*((_DWORD *)this + 10) - 1) & 0x3F)
                 + 4) == 0 )
    goto LABEL_6;
  v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * ((unsigned int)(*((_DWORD *)this + 6) - 1) >> 6))
                  + 4 * ((*((_DWORD *)this + 6) - 1) & 0x3F));
  v6 = (ay - SHIWORD(v10)) * (cx - (__int16)ax) - ((__int16)ax - ((__int16)v10 >> 1)) * (cy - ay);
  if ( v6 < 0 )
    v6 = ((__int16)ax - ((__int16)v10 >> 1)) * (cy - ay) - (ay - SHIWORD(v10)) * (cx - (__int16)ax);
  if ( v6 <= 5 )
  {
    GFxFontCompactor::LineTo((GFxFontCompactor *)this, a2: (__int16)ax, a3: ay);
  }
  else
  {
LABEL_6:
    v7 = *((_DWORD *)this + 6) >> 6;
    HIWORD(v11) = cy;
    if ( v7 >= *((_DWORD *)this + 7) )
      GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
        this: (unsigned int *)this + 6,
        nb: v7);
    LOWORD(v11) = (2 * cx) | 1;
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v7) + 4 * ((*((_DWORD *)this + 6))++ & 0x3F)) = v11;
    v8 = *((_DWORD *)this + 6) >> 6;
    LOWORD(v12) = (2 * (_WORD)ax) | 1;
    HIWORD(v12) = ay;
    if ( v8 >= *((_DWORD *)this + 7) )
      GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
        this: (unsigned int *)this + 6,
        nb: v8);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v8) + 4 * ((*((_DWORD *)this + 6))++ & 0x3F)) = v12;
    v9 = *(_DWORD *)(*((_DWORD *)this + 13) + 4 * ((unsigned int)(*((_DWORD *)this + 10) - 1) >> 6));
    *(_DWORD *)(v9 + 8 * ((*((_DWORD *)this + 10) - 1) & 0x3F) + 4) += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101882A0
// Name: public: void GFxFontCompactor::AssignGlyphCode(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::AssignGlyphCode(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this,
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *glyphIndex,
        unsigned int glyphCode)
{
  unsigned __int16 v3; // si
  GPtr<GFxUserEventHandler> *v4; // edi
  int v5; // ecx
  int i; // eax
  int v7; // edx
  _UNKNOWN *retaddr; // [esp+4h] [ebp+4h]

  if ( (unsigned int)glyphIndex < *((_DWORD *)this + 19) )
  {
    v3 = glyphCode;
    v4 = (GPtr<GFxUserEventHandler> *)((char *)this + 72);
    *(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 22) + 4 * ((unsigned int)glyphIndex >> 6))
             + 8 * ((unsigned __int8)glyphIndex & 0x3F)) = glyphCode;
    glyphIndex = (CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)v3;
    if ( GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Get<unsigned short>(
           this: (int *)this + 18,
           a2: &glyphIndex) == 0 )
    {
      glyphIndex = (CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)v3;
      v5 = 5381;
      for ( i = 2; i != 0; --i )
      {
        v7 = *((unsigned __int8 *)&retaddr + i + 3);
        v5 = v7 + 65599 * v5;
      }
      GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::add<unsigned short>(
        this: v4,
        pheapAddr: v4,
        a3: &glyphIndex,
        a4: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188320
// Name: public: void GFxFontCompactor::AddKerningPair(unsigned int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::AddKerningPair(GFxFontCompactor *this, unsigned int a2, unsigned __int16 a3, int a4)
{
  __int16 v4; // bx
  unsigned __int16 v6; // di
  unsigned int v7; // edi
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // [esp+8h] [ebp-8h]

  v4 = a2;
  a2 = (unsigned __int16)a2;
  if ( GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Get<unsigned short>(
         this: (int *)this + 18,
         &a2) != 0 )
  {
    v6 = a3;
    a2 = a3;
    if ( GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Get<unsigned short>(
           this: (int *)this + 18,
           &a2) != 0 )
    {
      HIWORD(v11) = v6;
      v7 = *((_DWORD *)this + 23) >> 6;
      LOWORD(v11) = v4;
      v8 = a4;
      if ( v7 >= *((_DWORD *)this + 24) )
        GArrayPagedBase<GFxFontCompactor::GlyphInfoType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::GlyphInfoType,261>>::allocatePage(
          this: (unsigned int *)this + 23,
          result: v7);
      v9 = *(_DWORD *)(*((_DWORD *)this + 26) + 4 * v7);
      v10 = *((_DWORD *)this + 23) & 0x3F;
      *(_DWORD *)(v9 + 8 * v10) = v11;
      *(_DWORD *)(v9 + 8 * v10 + 4) = v8;
      ++*((_DWORD *)this + 23);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101883A0
// Name: public: void GFxFontCompactor::EndFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxFontCompactor::EndFont(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v1; // esi
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // ebx
  int *p_m_nGrowSize; // eax
  unsigned int *m_nGrowSize; // esi
  unsigned int v8; // edi
  unsigned int *v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // ebx
  CMorph *v12; // eax
  int v13; // ebx
  unsigned int *v14; // esi
  unsigned int v15; // edi
  unsigned int *v16; // esi
  unsigned int v17; // edi
  int v18; // ebx
  CMorph *v19; // ecx
  int *v20; // edi
  unsigned int result; // eax
  int m_nAllocationCount; // edx
  _DWORD *v23; // esi
  int v24; // ecx
  int v25; // eax
  __int16 v26; // bx
  unsigned int v27; // edi
  unsigned int v28; // ecx
  void *v29; // eax
  void *v30; // eax
  int *v31; // edx
  _DWORD *v32; // esi
  unsigned int v33; // edi
  unsigned int v34; // ecx
  void *v35; // eax
  void *v36; // eax
  _DWORD *v37; // esi
  __int16 v38; // bx
  unsigned int v39; // edi
  unsigned int v40; // ecx
  void *v41; // eax
  void *v42; // eax
  int *v43; // edx
  _DWORD *v44; // esi
  unsigned int v45; // edi
  unsigned int v46; // ecx
  void *v47; // eax
  void *v48; // eax
  _DWORD *v49; // esi
  ITextureRegenerator_vtbl *v50; // ebx
  unsigned int v51; // edi
  unsigned int v52; // ecx
  void *v53; // eax
  void *v54; // eax
  int *v55; // edx
  _DWORD *v56; // esi
  unsigned int v57; // edi
  unsigned int v58; // ecx
  void *v59; // eax
  void *v60; // eax
  unsigned int v61; // eax
  MorphVertexInfo_t *m_Size; // [esp-4h] [ebp-58h]
  int v63; // [esp+0h] [ebp-54h]
  int *p_m_Size; // [esp+Ch] [ebp-48h]
  int v65; // [esp+10h] [ebp-44h] BYREF
  int v66; // [esp+14h] [ebp-40h] BYREF
  int v67; // [esp+18h] [ebp-3Ch] BYREF
  int v68; // [esp+1Ch] [ebp-38h] BYREF
  int v69; // [esp+20h] [ebp-34h] BYREF
  int v70; // [esp+24h] [ebp-30h] BYREF
  int v71; // [esp+28h] [ebp-2Ch] BYREF
  unsigned int v72; // [esp+2Ch] [ebp-28h] BYREF
  int v73; // [esp+30h] [ebp-24h] BYREF
  int v74; // [esp+34h] [ebp-20h] BYREF
  int v75; // [esp+38h] [ebp-1Ch] BYREF
  unsigned int v76; // [esp+3Ch] [ebp-18h] BYREF
  CMorph *kerningPair; // [esp+40h] [ebp-14h]
  unsigned int ia; // [esp+44h] [ebp-10h]
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v79; // [esp+48h] [ebp-Ch]
  int *v80; // [esp+4Ch] [ebp-8h]
  char v81; // [esp+53h] [ebp-1h]

  v1 = this;
  v2 = 0;
  v79 = this;
  ia = 0;
  if ( *((_DWORD *)this + 19) != 0 )
  {
    while ( 1 )
    {
      v3 = *(_DWORD *)(v1[4].m_Memory.m_nGrowSize + 4 * (v2 >> 6));
      v4 = v2 & 0x3F;
      v5 = *(unsigned __int16 *)(v3 + 8 * v4);
      kerningPair = (CMorph *)(v3 + 8 * v4);
      p_m_nGrowSize = &v1->m_Memory.m_nGrowSize;
      m_nGrowSize = (unsigned int *)v1->m_Memory.m_nGrowSize;
      v8 = *m_nGrowSize >> 12;
      v80 = p_m_nGrowSize;
      if ( v8 >= m_nGrowSize[1] )
      {
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: m_nGrowSize,
          nb: v8);
        p_m_nGrowSize = v80;
      }
      *(_BYTE *)(((*m_nGrowSize)++ & 0xFFF) + *(_DWORD *)(m_nGrowSize[3] + 4 * v8)) = v5;
      v9 = (unsigned int *)*p_m_nGrowSize;
      v10 = *(_DWORD *)*p_m_nGrowSize >> 12;
      v11 = v5 >> 8;
      if ( v10 >= *(_DWORD *)(*p_m_nGrowSize + 4) )
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v9,
          nb: *(_DWORD *)*p_m_nGrowSize >> 12);
      v12 = kerningPair;
      *(_BYTE *)(((*v9)++ & 0xFFF) + *(_DWORD *)(v9[3] + 4 * v10)) = v11;
      v13 = SHIWORD(v12->IMorphInternal::IMorph::__vftable);
      v14 = (unsigned int *)v79->m_Memory.m_nGrowSize;
      v15 = *v14 >> 12;
      if ( v15 >= v14[1] )
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v14,
          nb: *v14 >> 12);
      *(_BYTE *)(((*v14)++ & 0xFFF) + *(_DWORD *)(v14[3] + 4 * v15)) = v13;
      v16 = (unsigned int *)v79->m_Memory.m_nGrowSize;
      v17 = *v16 >> 12;
      v18 = v13 >> 8;
      if ( v17 >= v16[1] )
        GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          this: v16,
          nb: *v16 >> 12);
      v19 = kerningPair;
      *(_BYTE *)(((*v16)++ & 0xFFF) + *(_DWORD *)(v16[3] + 4 * v17)) = v18;
      GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
        this: (CUtlMemory<MorphVertexInfo_t,int> *)&v79->m_Memory.m_nGrowSize,
        v: (unsigned int)v19->ITextureRegenerator::__vftable);
      ++ia;
      v1 = v79;
      if ( (CVertexMorphDict::MorphVertexList_t *)ia >= v79[3].m_pElements )
        break;
      v2 = ia;
    }
  }
  p_m_Size = &v1[4].m_Size;
  G_QuickSortSliced<GArrayPagedPOD<GFxFontCompactor::KerningPairType,6,64,261>,bool (__cdecl *)(GFxFontCompactor::KerningPairType const &,GFxFontCompactor::KerningPairType const &)>(
    a1: (int)&v1[4].m_Size,
    a2: 0,
    a3: v1[4].m_Size,
    a4: (unsigned __int8 (__cdecl *)(int, int))GFxFontCompactor::cmpKerningPairs);
  v20 = &v1->m_Memory.m_nGrowSize;
  m_Size = (MorphVertexInfo_t *)v1[4].m_Size;
  v80 = &v1->m_Memory.m_nGrowSize;
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)&v1->m_Memory.m_nGrowSize,
    v: m_Size,
    a3: v63);
  result = 0;
  ia = 0;
  if ( v1[4].m_Size != 0 )
  {
    while ( 1 )
    {
      m_nAllocationCount = v1[5].m_Memory.m_nAllocationCount;
      v23 = (_DWORD *)*v20;
      v24 = *(_DWORD *)(m_nAllocationCount + 4 * (result >> 6));
      v25 = result & 0x3F;
      v26 = *(_WORD *)(v24 + 8 * v25);
      v27 = *(_DWORD *)*v20 >> 12;
      kerningPair = (CMorph *)(v24 + 8 * v25);
      if ( v27 >= v23[1] )
      {
        v28 = v23[2];
        if ( v27 >= v28 )
        {
          v29 = (void *)v23[3];
          if ( v29 != nullptr )
          {
            v76 = 4 * v28 + 1024;
            v30 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v29, a3: v76);
          }
          else
          {
            v75 = 261;
            v30 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v23, a3: 1024, a4: &v75);
          }
          v23[2] += 256;
          v23[3] = v30;
        }
        v76 = 261;
        *(_DWORD *)(v23[3] + 4 * v27) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v23,
                                          a3: 4096,
                                          a4: &v76);
        ++v23[1];
      }
      v31 = v80;
      *(_BYTE *)(((*v23)++ & 0xFFF) + *(_DWORD *)(v23[3] + 4 * v27)) = v26;
      v32 = (_DWORD *)*v31;
      v33 = *(_DWORD *)*v31 >> 12;
      v81 = HIBYTE(v26);
      if ( v33 >= v32[1] )
      {
        v34 = v32[2];
        if ( v33 >= v34 )
        {
          v35 = (void *)v32[3];
          if ( v35 != nullptr )
          {
            v36 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v35, a3: 4 * v34 + 1024);
          }
          else
          {
            v74 = 261;
            v36 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v32, a3: 1024, a4: &v74);
          }
          v32[2] += 256;
          v32[3] = v36;
        }
        v73 = 261;
        *(_DWORD *)(v32[3] + 4 * v33) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v32,
                                          a3: 4096,
                                          a4: &v73);
        ++v32[1];
      }
      *(_BYTE *)(((*v32)++ & 0xFFF) + *(_DWORD *)(v32[3] + 4 * v33)) = v81;
      v37 = (_DWORD *)*v80;
      v38 = HIWORD(kerningPair->IMorphInternal::IMorph::__vftable);
      v39 = *(_DWORD *)*v80 >> 12;
      if ( v39 >= *(_DWORD *)(*v80 + 4) )
      {
        v40 = v37[2];
        if ( v39 >= v40 )
        {
          v41 = (void *)v37[3];
          if ( v41 != nullptr )
          {
            v72 = 4 * v40 + 1024;
            v42 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v41, a3: v72);
          }
          else
          {
            v71 = 261;
            v42 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v37, a3: 1024, a4: &v71);
          }
          v37[2] += 256;
          v37[3] = v42;
        }
        v72 = 261;
        *(_DWORD *)(v37[3] + 4 * v39) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v37,
                                          a3: 4096,
                                          a4: &v72);
        ++v37[1];
      }
      v43 = v80;
      *(_BYTE *)(((*v37)++ & 0xFFF) + *(_DWORD *)(v37[3] + 4 * v39)) = v38;
      v44 = (_DWORD *)*v43;
      v45 = *(_DWORD *)*v43 >> 12;
      v81 = HIBYTE(v38);
      if ( v45 >= v44[1] )
      {
        v46 = v44[2];
        if ( v45 >= v46 )
        {
          v47 = (void *)v44[3];
          if ( v47 != nullptr )
          {
            v48 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v47, a3: 4 * v46 + 1024);
          }
          else
          {
            v70 = 261;
            v48 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v44, a3: 1024, a4: &v70);
          }
          v44[2] += 256;
          v44[3] = v48;
        }
        v69 = 261;
        *(_DWORD *)(v44[3] + 4 * v45) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v44,
                                          a3: 4096,
                                          a4: &v69);
        ++v44[1];
      }
      *(_BYTE *)(((*v44)++ & 0xFFF) + *(_DWORD *)(v44[3] + 4 * v45)) = v81;
      v49 = (_DWORD *)*v80;
      v50 = kerningPair->ITextureRegenerator::__vftable;
      v51 = *(_DWORD *)*v80 >> 12;
      if ( v51 >= *(_DWORD *)(*v80 + 4) )
      {
        v52 = v49[2];
        if ( v51 >= v52 )
        {
          v53 = (void *)v49[3];
          if ( v53 != nullptr )
          {
            kerningPair = (CMorph *)(4 * v52 + 1024);
            v54 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v53, a3: kerningPair);
          }
          else
          {
            v68 = 261;
            v54 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v49, a3: 1024, a4: &v68);
          }
          v49[2] += 256;
          v49[3] = v54;
        }
        v67 = 261;
        *(_DWORD *)(v49[3] + 4 * v51) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v49,
                                          a3: 4096,
                                          a4: &v67);
        ++v49[1];
      }
      v55 = v80;
      *(_BYTE *)(((*v49)++ & 0xFFF) + *(_DWORD *)(v49[3] + 4 * v51)) = (_BYTE)v50;
      v56 = (_DWORD *)*v55;
      v57 = *(_DWORD *)*v55 >> 12;
      v81 = BYTE1(v50);
      if ( v57 >= v56[1] )
      {
        v58 = v56[2];
        if ( v57 >= v58 )
        {
          v59 = (void *)v56[3];
          if ( v59 != nullptr )
          {
            v60 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v59, a3: 4 * v58 + 1024);
          }
          else
          {
            v66 = 261;
            v60 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v56, a3: 1024, a4: &v66);
          }
          v56[2] += 256;
          v56[3] = v60;
        }
        v65 = 261;
        *(_DWORD *)(v56[3] + 4 * v57) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                          this: GMemory::pGlobalHeap,
                                          a2: v56,
                                          a3: 4096,
                                          a4: &v65);
        ++v56[1];
      }
      *(_BYTE *)((*v56 & 0xFFF) + *(_DWORD *)(v56[3] + 4 * v57)) = v81;
      v61 = ia;
      ++*v56;
      result = v61 + 1;
      ia = result;
      if ( result >= *p_m_Size )
        break;
      v1 = v79;
      result = ia;
      v20 = v80;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10188970
// Name: public: void GFxFontCompactor::StartFont(char const __near *,unsigned int,unsigned int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::StartFont(
        GFxFontCompactor *this,
        char *a2,
        __int16 a3,
        __int16 a4,
        __int16 a5,
        __int16 a6,
        __int16 a7)
{
  char i; // bl
  unsigned int *v9; // esi
  unsigned int v10; // eax
  unsigned int *v11; // ebx
  unsigned int v12; // eax
  _DWORD *v13; // edx
  unsigned int v14; // [esp+Ch] [ebp-4h]
  const char *v15; // [esp+18h] [ebp+8h]

  for ( i = *a2; i != 0; ++a2 )
  {
    v9 = *((unsigned int **)this + 2);
    v10 = *v9 >> 12;
    v14 = v10;
    if ( v10 >= v9[1] )
    {
      GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v9, nb: v10);
      v10 = v14;
    }
    *(_BYTE *)(((*v9)++ & 0xFFF) + *(_DWORD *)(v9[3] + 4 * v10)) = i;
    i = a2[1];
  }
  v11 = *((unsigned int **)this + 2);
  v12 = *v11 >> 12;
  v15 = (const char *)v12;
  if ( v12 >= v11[1] )
  {
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this: v11, nb: v12);
    v12 = (unsigned int)v15;
  }
  *(_BYTE *)(((*v11)++ & 0xFFF) + *(_DWORD *)(v11[3] + 4 * v12)) = 0;
  *((_DWORD *)this + 27) = **((_DWORD **)this + 2);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: a3);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: a4);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: a5);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: a6);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: a7);
  v13 = *((_DWORD **)this + 2);
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = *v13;
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: 0);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
    this: (CUtlMemory<MorphVertexInfo_t,int> *)((char *)this + 8),
    v: 0);
  GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this: (CInternalFileSystemPassThru<IBaseFileSystem> *)this + 9);
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 23) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10188A70
// Name: public: void GFxFontCompactor::EndGlyph(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCompactor::EndGlyph(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this,
        char mergeContours)
{
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v2; // edi
  unsigned __int16 v3; // ax
  unsigned int v4; // esi
  CUtlMemory<MorphVertexInfo_t,int> *p_m_nGrowSize; // ebx
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // ecx
  unsigned int v7; // eax
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  CVertexMorphDict::MorphVertexList_t *m_pElements; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // edi
  unsigned int k; // esi
  CVertexMorphDict::MorphVertexList_t *v18; // edx
  __int16 *v19; // ecx
  __int16 v20; // ax
  int v21; // edx
  unsigned int v22; // eax
  int v23; // esi
  int v24; // edx
  int v25; // ecx
  unsigned int v26; // ecx
  unsigned int v27; // eax
  int v28; // eax
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v29; // edi
  unsigned int v30; // esi
  int v31; // eax
  CVertexMorphDict::MorphVertexList_t *v32; // esi
  unsigned int v33; // eax
  bool v34; // zf
  int *v35; // esi
  int v36; // edi
  int *v37; // eax
  int v38; // eax
  CVertexMorphDict::MorphVertexList_t *v39; // ecx
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v40; // esi
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int m_Size; // eax
  float v45; // edx
  char v46; // ch
  unsigned int v47; // eax
  unsigned int p_m_MorphInfo; // eax
  float v49; // esi
  unsigned int v50; // esi
  int v51; // esi
  unsigned int v52; // ecx
  int v53; // eax
  int v54; // [esp+0h] [ebp-40h]
  int v55; // [esp+0h] [ebp-40h]
  int v56; // [esp+Ch] [ebp-34h] BYREF
  int v57; // [esp+10h] [ebp-30h]
  unsigned int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  unsigned int v60; // [esp+1Ch] [ebp-24h]
  unsigned int i; // [esp+20h] [ebp-20h] BYREF
  unsigned int startPath; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int numEdges; // [esp+28h] [ebp-18h] BYREF
  int y2; // [esp+2Ch] [ebp-14h] BYREF
  int y; // [esp+30h] [ebp-10h]
  unsigned int j; // [esp+34h] [ebp-Ch]
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v67; // [esp+38h] [ebp-8h]
  bool newShapesAdded; // [esp+3Fh] [ebp-1h]
  int mergeContoursa; // [esp+48h] [ebp+8h]
  CVertexMorphDict::MorphVertexList_t *mergeContoursb; // [esp+48h] [ebp+8h]

  v2 = this;
  v3 = *((_WORD *)this + 56);
  v4 = *(_DWORD *)this->m_Memory.m_nGrowSize;
  p_m_nGrowSize = (CUtlMemory<MorphVertexInfo_t,int> *)&this->m_Memory.m_nGrowSize;
  v67 = this;
  v59 = v3;
  v60 = v4;
  if ( *((_DWORD *)this + 10) != 0 )
    GFxFontCompactor::normalizeLastContour(this);
  GFxFontCompactor::computeBounds(
    this: (GFxFontCompactor *)v2,
    x1: (int *)&i,
    y1: (int *)&startPath,
    x2: (int *)&numEdges,
    &y2);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
    this: (unsigned int **)p_m_nGrowSize,
    a2: i);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
    this: (unsigned int **)p_m_nGrowSize,
    a2: startPath);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
    this: (unsigned int **)p_m_nGrowSize,
    a2: numEdges);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
    this: (unsigned int **)p_m_nGrowSize,
    a2: y2);
  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(
    this: p_m_nGrowSize,
    v: (MorphVertexInfo_t *)v2[2].m_Memory.m_pMemory,
    a3: v54);
  m_pMemory = v2[2].m_Memory.m_pMemory;
  newShapesAdded = false;
  if ( m_pMemory != nullptr )
  {
    v7 = 0;
    for ( i = 0; ; v7 = i )
    {
      v8 = (unsigned int *)(*(_DWORD *)(v2[2].m_Size + 4 * (v7 >> 6)) + 8 * (v7 & 0x3F));
      v9 = v8[1];
      y2 = (int)v8;
      numEdges = 0;
      j = 1;
      startPath = v9;
      if ( v9 > 1 )
      {
        m_pElements = v2[1].m_pElements;
        v11 = *v8 + 1;
        do
        {
          ++numEdges;
          if ( (*(_BYTE *)(*(&m_pElements->m_nMorphTargetId + (v11 >> 6)) + 4 * (v11 & 0x3F)) & 1) != 0 )
          {
            ++j;
            ++v11;
          }
          ++v11;
          ++j;
        }
        while ( j < startPath );
        v8 = (unsigned int *)y2;
      }
      v12 = *v8;
      v13 = *(&v2[1].m_pElements->m_nMorphTargetId + (v12 >> 6));
      v14 = v12 & 0x3F;
      v15 = *(__int16 *)(v13 + 4 * v14 + 2);
      v16 = *(__int16 *)(v13 + 4 * v14) >> 1;
      y = v15;
      GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
        this: (unsigned int **)p_m_nGrowSize,
        a2: v16);
      GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
        this: (unsigned int **)p_m_nGrowSize,
        a2: v15);
      startPath = p_m_nGrowSize->m_pMemory->m_nVertexId;
      GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
        this: p_m_nGrowSize,
        v: (MorphVertexInfo_t *)(2 * numEdges),
        a3: v55);
      for ( k = 1; k < *(_DWORD *)(y2 + 4); ++k )
      {
        v18 = v67[1].m_pElements;
        numEdges = *(_DWORD *)y2;
        v19 = (__int16 *)(*(&v18->m_nMorphTargetId + ((k + numEdges) >> 6)) + 4 * ((k + numEdges) & 0x3F));
        v20 = *v19;
        if ( (*v19 & 1) != 0 )
        {
          j = k + 1;
          v21 = *(&v18->m_nMorphTargetId + ((k + 1 + numEdges) >> 6));
          v22 = (k + 1 + numEdges) & 0x3F;
          v23 = *(__int16 *)(v21 + 4 * v22);
          v24 = v21 + 4 * v22;
          LOWORD(v22) = *v19;
          v25 = v19[1];
          numEdges = *(__int16 *)(v24 + 2);
          v23 >>= 1;
          GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteQuad(
            this: (unsigned int **)p_m_nGrowSize,
            result: ((__int16)v22 >> 1) - v16,
            cy: v25 - y,
            a4: v23 - ((__int16)v22 >> 1),
            ay: numEdges - v25);
          v16 = v23;
          k = j;
          y = numEdges;
        }
        else
        {
          v26 = v19[1];
          v27 = v20 >> 1;
          j = v27;
          numEdges = v26;
          if ( v27 == v16 )
          {
            GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteVLine(
              this: (unsigned int **)p_m_nGrowSize,
              a2: v26 - y);
          }
          else
          {
            v28 = v27 - v16;
            if ( v26 == y )
              GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteHLine(
                this: (unsigned int **)p_m_nGrowSize,
                a2: v28);
            else
              GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteLine(
                this: p_m_nGrowSize,
                x: v28,
                y: v26 - y);
          }
          v16 = j;
          y = numEdges;
        }
      }
      if ( mergeContours != 0 )
      {
        v29 = v67;
        v30 = startPath;
        v56 = (int)v67;
        GFxFontCompactor::ComputePathHash(this: v67, pos: startPath, edge: v55);
        v58 = v30;
        v32 = v29->m_pElements;
        v57 = v31;
        if ( v32 == nullptr )
          goto LABEL_36;
        v33 = v31 & (int)v32->m_MorphInfo.m_Memory.m_pMemory;
        v34 = *(&v32->m_MorphInfo.m_Memory.m_nAllocationCount + 5 * v33) == -2;
        v35 = &v32->m_MorphInfo.m_Memory.m_nAllocationCount + 5 * v33;
        numEdges = v33;
        v36 = v33;
        if ( v34 || v35[1] != v33 )
          goto LABEL_36;
        while ( 1 )
        {
          if ( v35[1] == v33 )
          {
            if ( GFxFontCompactor::PathsEqual(
                   this: (const CVertexMorphDict::MorphVertexList_t *)v35[2],
                   pos: (const CVertexMorphDict::MorphVertexList_t *)v35[4],
                   a3: (int)v67,
                   cmpPos: startPath) != 0 )
            {
              if ( v36 >= 0 )
              {
                v37 = &v67->m_pElements->m_MorphInfo.m_Size + 5 * v36;
                if ( (CVertexMorphDict::MorphVertexList_t *)((char *)v67->m_pElements + 20 * v36) != (CVertexMorphDict::MorphVertexList_t *)-16 )
                {
                  if ( startPath < p_m_nGrowSize->m_pMemory->m_nVertexId )
                    p_m_nGrowSize->m_pMemory->m_nVertexId = startPath;
                  GFxPathDataEncoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
                    this: p_m_nGrowSize,
                    v: (MorphVertexInfo_t *)((2 * v37[2]) | 1),
                    a3: v55);
                  break;
                }
              }
LABEL_36:
              GHashSetBase<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType>>::add<GFxFontCompactor::GlyphKeyType>(
                this: (ScaleformImageLoader *)&v67->m_pElements,
                pheapAddr: (ScaleformImageLoader *)&v67->m_pElements,
                a3: &v56,
                a4: v57);
              newShapesAdded = true;
              break;
            }
            v33 = numEdges;
          }
          v36 = *v35;
          if ( *v35 == -1 )
            goto LABEL_36;
          v35 = &v67->m_pElements->m_MorphInfo.m_Memory.m_nAllocationCount + 5 * v36;
        }
      }
      ++i;
      v2 = v67;
      if ( (CVertexMorphDict::MorphVertexList_t *)i >= v67[2].m_Memory.m_pMemory )
        break;
    }
    v4 = v60;
  }
  ++v2[5].m_Size;
  i = v4;
  if ( mergeContours != 0 && !newShapesAdded )
  {
    v56 = (int)v2;
    GFxFontCompactor::ComputeGlyphHash(this: v2, pos: v4, a3: v55);
    v39 = v2[1].m_Memory.m_pMemory;
    v58 = v4;
    v40 = v2 + 1;
    v57 = v38;
    if ( v39 != nullptr )
    {
      v41 = GHashSetBase<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType>>::findIndexCore<GFxFontCompactor::GlyphKeyType>(
              this: &v2[1].m_Memory.m_pMemory,
              a2: (int)&v56,
              a3: v38 & (int)v39->m_MorphInfo.m_Memory.m_pMemory);
      if ( v41 >= 0 )
      {
        v42 = 5 * v41;
        v43 = (int)(&v40->m_Memory.m_pMemory->m_MorphInfo.m_Size + v42);
        if ( (CVertexMorphDict::MorphVertexList_t *)((char *)v40->m_Memory.m_pMemory + 4 * v42) != (CVertexMorphDict::MorphVertexList_t *)-16 )
        {
          if ( v60 < p_m_nGrowSize->m_pMemory->m_nVertexId )
            p_m_nGrowSize->m_pMemory->m_nVertexId = v60;
          v60 = *(_DWORD *)(v43 + 8);
          goto LABEL_49;
        }
      }
      v38 = v57;
    }
    GHashSetBase<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType,GAllocatorGH<GFxFontCompactor::ContourKeyType,261>,GHashsetCachedEntry<GFxFontCompactor::GlyphKeyType,GFxFontCompactor::GlyphKeyType>>::add<GFxFontCompactor::GlyphKeyType>(
      this: (ScaleformImageLoader *)&v2[1],
      pheapAddr: (ScaleformImageLoader *)&v2[1],
      a3: &v56,
      a4: v38);
  }
LABEL_49:
  m_Size = v2[5].m_Size;
  v2[5].m_pElements = (CVertexMorphDict::MorphVertexList_t *)((char *)v2[5].m_pElements
                                                            + p_m_nGrowSize->m_pMemory->m_nVertexId
                                                            - i);
  v45 = p_m_nGrowSize->m_pMemory->m_PositionDelta.y;
  mergeContoursa = m_Size;
  i = (unsigned int)v2[6].m_Memory.m_pMemory;
  v46 = BYTE1(m_Size);
  v47 = i + 1;
  *(_BYTE *)((i & 0xFFF) + *(_DWORD *)(LODWORD(v45) + 4 * (i >> 12))) = mergeContoursa;
  *(_BYTE *)((v47 & 0xFFF) + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * (v47 >> 12))) = v46;
  *(_BYTE *)(((i + 2) & 0xFFF) + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * ((i + 2) >> 12))) = BYTE2(mergeContoursa);
  *(_BYTE *)(((i + 3) & 0xFFF) + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * ((i + 3) >> 12))) = HIBYTE(mergeContoursa);
  mergeContoursb = v2[5].m_pElements;
  p_m_MorphInfo = (unsigned int)&v2[6].m_Memory.m_pMemory->m_MorphInfo;
  *(_BYTE *)(((LOWORD(v2[6].m_Memory.m_pMemory) + 4) & 0xFFF)
           + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * (p_m_MorphInfo >> 12))) = (_BYTE)mergeContoursb;
  v49 = p_m_nGrowSize->m_pMemory->m_PositionDelta.y;
  i = p_m_MorphInfo;
  *(_BYTE *)(((p_m_MorphInfo + 1) & 0xFFF) + *(_DWORD *)(LODWORD(v49) + 4 * ((p_m_MorphInfo + 1) >> 12))) = BYTE1(mergeContoursb);
  *(_BYTE *)(((i + 2) & 0xFFF) + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * ((i + 2) >> 12))) = BYTE2(mergeContoursb);
  *(_BYTE *)(((i + 3) & 0xFFF) + *(_DWORD *)(LODWORD(p_m_nGrowSize->m_pMemory->m_PositionDelta.y) + 4 * ((i + 3) >> 12))) = HIBYTE(mergeContoursb);
  v50 = (unsigned int)v2[3].m_pElements >> 6;
  if ( (CVertexMorphDict::MorphVertexList_t *)v50 >= v2[4].m_Memory.m_pMemory )
    GArrayPagedBase<GFxFontCompactor::GlyphInfoType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::GlyphInfoType,261>>::allocatePage(
      this: (unsigned int *)&v2[3].m_pElements,
      result: (unsigned int)v2[3].m_pElements >> 6);
  v51 = *(_DWORD *)(v2[4].m_Memory.m_nGrowSize + 4 * v50);
  v52 = v60;
  v53 = (int)v2[3].m_pElements & 0x3F;
  *(_DWORD *)(v51 + 8 * v53) = v59;
  *(_DWORD *)(v51 + 8 * v53 + 4) = v52;
  ++v2[3].m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x10189270
// Name: void G_QuickSortSliced<class GArrayUnsafeLH_POD<struct GTessellator::MonoChainType __near *,133>,bool (*)(struct GTessellator::MonoChainType const __near *,struct GTessellator::MonoChainType const __near *)>(class GArrayUnsafeLH_POD<struct GTessellator::MonoChainType __near *,133> __near &,unsigned int,unsigned int,bool (*)(struct GTessellator::MonoChainType const __near *,struct GTessellator::MonoChainType const __near *))
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl G_QuickSortSliced<GArrayUnsafeLH_POD<GTessellator::MonoChainType *,133>,bool (__cdecl *)(GTessellator::MonoChainType const *,GTessellator::MonoChainType const *)>(
        int *a1,
        int a2,
        _BYTE *a3,
        unsigned __int8 (__cdecl *a4)(int, int))
{
  _BYTE *result; // eax
  int v5; // ebx
  _BYTE *v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // edx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // ecx
  _DWORD *v23; // eax
  int v24; // edi
  int v25; // ecx
  _DWORD *v26; // eax
  int v27; // edx
  int v28; // [esp+8h] [ebp-158h]
  int v29; // [esp+8h] [ebp-158h]
  int v30; // [esp+8h] [ebp-158h]
  int v31; // [esp+Ch] [ebp-154h]
  _DWORD *v32; // [esp+14h] [ebp-14Ch]
  int v33; // [esp+18h] [ebp-148h]
  _BYTE v34[320]; // [esp+1Ch] [ebp-144h] BYREF

  result = a3;
  v5 = a2;
  if ( (unsigned int)&a3[-a2] >= 2 )
  {
    v6 = v34;
    v33 = a2;
    while ( 1 )
    {
      v31 = (int)result;
      v32 = v6;
      while ( v31 - v5 > 9 )
      {
        v7 = *(_DWORD *)(*a1 + 4 * v5);
        v8 = v5 + (v31 - v5) / 2;
        v9 = *(_DWORD *)(*a1 + 4 * v8);
        v10 = (_DWORD *)(*a1 + 4 * v8);
        *(_DWORD *)(*a1 + 4 * v5) = v9;
        *v10 = v7;
        v11 = *(_DWORD *)(*a1 + 4 * v5++ + 4);
        v12 = v31 - 1;
        if ( a4(a1: *(_DWORD *)(*a1 + 4 * v31 - 4), a2: v11) != 0 )
        {
          v13 = *a1;
          v14 = *(_DWORD *)(*a1 + 4 * v12);
          *(_DWORD *)(v13 + 4 * v12) = *(_DWORD *)(*a1 + 4 * v5);
          *(_DWORD *)(v13 + 4 * v5) = v14;
        }
        if ( a4(a1: *(_DWORD *)(*a1 + 4 * v33), a2: *(_DWORD *)(*a1 + 4 * v5)) != 0 )
        {
          v15 = *a1;
          v28 = *(_DWORD *)(*a1 + 4 * v33);
          *(_DWORD *)(v15 + 4 * v33) = *(_DWORD *)(*a1 + 4 * v5);
          *(_DWORD *)(v15 + 4 * v5) = v28;
        }
        if ( a4(a1: *(_DWORD *)(*a1 + 4 * v12), a2: *(_DWORD *)(*a1 + 4 * v33)) != 0 )
        {
          v16 = *a1;
          v29 = *(_DWORD *)(*a1 + 4 * v12);
          v17 = v33;
          *(_DWORD *)(v16 + 4 * v12) = *(_DWORD *)(v16 + 4 * v33);
          *(_DWORD *)(v16 + 4 * v17) = v29;
        }
        while ( 1 )
        {
          do
            v18 = *(_DWORD *)(*a1 + 4 * v5++ + 4);
          while ( a4(a1: v18, a2: *(_DWORD *)(*a1 + 4 * v33)) != 0 );
          do
            v19 = *(_DWORD *)(*a1 + 4 * v12-- - 4);
          while ( a4(a1: *(_DWORD *)(*a1 + 4 * v33), a2: v19) != 0 );
          v20 = *a1;
          if ( v5 > v12 )
            break;
          v21 = *(_DWORD *)(v20 + 4 * v5);
          *(_DWORD *)(v20 + 4 * v5) = *(_DWORD *)(v20 + 4 * v12);
          *(_DWORD *)(v20 + 4 * v12) = v21;
        }
        v30 = *(_DWORD *)(v20 + 4 * v33);
        *(_DWORD *)(v20 + 4 * v33) = *(_DWORD *)(v20 + 4 * v12);
        *(_DWORD *)(v20 + 4 * v12) = v30;
        if ( v12 - v33 <= v31 - v5 )
        {
          v23 = v32;
          v32 += 2;
          v6 = v32;
          *v23 = v5;
          v5 = v33;
          v23[1] = v31;
          v31 = v12;
        }
        else
        {
          v22 = v32;
          v32 += 2;
          *v22 = v33;
          v22[1] = v12;
          v6 = v32;
          v33 = v5;
        }
      }
      v24 = v5;
      v33 = v5 + 1;
      if ( v5 + 1 < v31 )
      {
        do
        {
          for ( ; a4(a1: *(_DWORD *)(*a1 + 4 * v24 + 4), a2: *(_DWORD *)(*a1 + 4 * v24)) != 0; --v24 )
          {
            v25 = *(_DWORD *)(*a1 + 4 * v24 + 4);
            v26 = (_DWORD *)(*a1 + 4 * v24);
            v26[1] = *v26;
            *v26 = v25;
            if ( v24 == v5 )
              break;
          }
          v24 = v33++;
        }
        while ( v33 < v31 );
        v6 = v32;
      }
      result = v34;
      if ( v6 <= v34 )
        break;
      v27 = *((_DWORD *)v6 - 2);
      result = *((_BYTE **)v6 - 1);
      v6 -= 8;
      v33 = v27;
      v5 = v27;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A2C0
// Name: void G_QuickSortSliced<class GArrayPagedLH_POD<struct GRectPacker::RectType,8,64,2>,bool (*)(struct GRectPacker::RectType const __near &,struct GRectPacker::RectType const __near &)>(class GArrayPagedLH_POD<struct GRectPacker::RectType,8,64,2> __near &,unsigned int,unsigned int,bool (*)(struct GRectPacker::RectType const __near &,struct GRectPacker::RectType const __near &))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_QuickSortSliced<GArrayPagedLH_POD<GRectPacker::RectType,8,64,2>,bool (__cdecl *)(GRectPacker::RectType const &,GRectPacker::RectType const &)>(
        int a1,
        unsigned int a2,
        int a3,
        unsigned __int8 (__cdecl *a4)(int, int))
{
  int result; // eax
  unsigned int v5; // ebx
  unsigned int *v6; // ecx
  int v7; // esi
  int *v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  int *v13; // eax
  int v14; // edx
  int v15; // edx
  unsigned int v16; // esi
  int v17; // ecx
  int *v18; // eax
  int *v19; // ecx
  int v20; // ecx
  int *v21; // eax
  int *v22; // ecx
  int v23; // ecx
  int *v24; // eax
  int *v25; // ecx
  unsigned int v26; // edx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int v30; // edx
  int *v31; // edi
  int v32; // ecx
  int *v33; // eax
  unsigned int *v34; // eax
  unsigned int *v35; // ecx
  int v36; // esi
  int v37; // ebx
  int v38; // edi
  int v39; // eax
  int v40; // esi
  int *v41; // edi
  int v42; // edx
  int v43; // eax
  int v44; // ecx
  _DWORD *v45; // esi
  int v46; // ebx
  unsigned int v47; // eax
  int v48; // ecx
  unsigned int v49; // eax
  int v50; // edx
  int v51; // [esp+8h] [ebp-1B4h]
  int v52; // [esp+Ch] [ebp-1B0h]
  int v53; // [esp+18h] [ebp-1A4h]
  int v54; // [esp+1Ch] [ebp-1A0h]
  int v55; // [esp+20h] [ebp-19Ch]
  int v56; // [esp+24h] [ebp-198h]
  int v57; // [esp+28h] [ebp-194h]
  int v58; // [esp+2Ch] [ebp-190h]
  int v59; // [esp+30h] [ebp-18Ch]
  int v60; // [esp+34h] [ebp-188h]
  int v61; // [esp+38h] [ebp-184h]
  int v62; // [esp+3Ch] [ebp-180h]
  int v63; // [esp+40h] [ebp-17Ch]
  int v64; // [esp+44h] [ebp-178h]
  int v65; // [esp+48h] [ebp-174h]
  int v66; // [esp+4Ch] [ebp-170h]
  unsigned int v67; // [esp+50h] [ebp-16Ch]
  int v68; // [esp+54h] [ebp-168h]
  unsigned int v69; // [esp+58h] [ebp-164h]
  int v70; // [esp+58h] [ebp-164h]
  int v71; // [esp+5Ch] [ebp-160h]
  int v72; // [esp+5Ch] [ebp-160h]
  int v73; // [esp+64h] [ebp-158h]
  unsigned int *v74; // [esp+68h] [ebp-154h]
  int v75; // [esp+6Ch] [ebp-150h]
  int *v76; // [esp+6Ch] [ebp-150h]
  int v77; // [esp+70h] [ebp-14Ch]
  int v78; // [esp+74h] [ebp-148h]
  unsigned int v79[80]; // [esp+78h] [ebp-144h] BYREF

  v78 = a1;
  result = a3;
  v5 = a2;
  if ( a3 - a2 >= 2 )
  {
    v6 = v79;
    v67 = a2;
    v68 = a3;
    while ( 1 )
    {
      v74 = v6;
      while ( (int)(v68 - v5) > 9 )
      {
        v7 = *(_DWORD *)(v78 + 12);
        v8 = (int *)(*(_DWORD *)(v7 + 4 * ((v5 + (int)(v68 - v5) / 2) >> 8))
                   + 12 * (unsigned __int8)(v5 + (int)(v68 - v5) / 2));
        v9 = 12 * (unsigned __int8)v5;
        v10 = 4 * (v5 >> 8);
        v11 = *(_DWORD *)(v10 + v7);
        v12 = *(_DWORD *)(v11 + v9 + 4);
        v13 = (int *)(v9 + v11);
        v53 = v13[2];
        v73 = v9;
        v14 = *v13;
        *v13 = *v8;
        v13[1] = v8[1];
        v13[2] = v8[2];
        *v8 = v14;
        v8[1] = v12;
        v8[2] = v53;
        v66 = 4 * (++v5 >> 8);
        v75 = *(_DWORD *)(v78 + 12);
        v15 = 12 * (unsigned __int8)v5 + *(_DWORD *)(v75 + v66);
        v16 = v68 - 1;
        v71 = 12 * (unsigned __int8)v5;
        v77 = 12 * (unsigned __int8)(v68 - 1);
        v69 = 4 * ((unsigned int)(v68 - 1) >> 8);
        if ( a4(a1: v77 + *(_DWORD *)(v69 + v75), a2: v15) != 0 )
        {
          v17 = *(_DWORD *)(v78 + 12);
          v18 = (int *)(v71 + *(_DWORD *)(v17 + v66));
          v19 = (int *)(v77 + *(_DWORD *)(v17 + v69));
          v57 = *v19;
          v58 = v19[1];
          v59 = v19[2];
          *v19 = *v18;
          v19[1] = v18[1];
          v19[2] = v18[2];
          *v18 = v57;
          v18[1] = v58;
          v18[2] = v59;
        }
        if ( a4(a1: v73 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v10), a2: v71 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v66)) != 0 )
        {
          v20 = *(_DWORD *)(v78 + 12);
          v21 = (int *)(v71 + *(_DWORD *)(v20 + v66));
          v22 = (int *)(v73 + *(_DWORD *)(v20 + v10));
          v63 = *v22;
          v64 = v22[1];
          v65 = v22[2];
          *v22 = *v21;
          v22[1] = v21[1];
          v22[2] = v21[2];
          *v21 = v63;
          v21[1] = v64;
          v21[2] = v65;
        }
        if ( a4(a1: v77 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v69), a2: v73 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v10)) != 0 )
        {
          v23 = *(_DWORD *)(v78 + 12);
          v24 = (int *)(v73 + *(_DWORD *)(v23 + v10));
          v25 = (int *)(v77 + *(_DWORD *)(v23 + v69));
          v54 = *v25;
          v55 = v25[1];
          v56 = v25[2];
          *v25 = *v24;
          v25[1] = v24[1];
          v25[2] = v24[2];
          *v24 = v54;
          v24[1] = v55;
          v24[2] = v56;
        }
        while ( 1 )
        {
          do
            ++v5;
          while ( a4(
                    a1: *(_DWORD *)(*(_DWORD *)(v78 + 12) + 4 * (v5 >> 8)) + 12 * (unsigned __int8)v5,
                    a2: v73 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v10)) != 0 );
          do
            --v16;
          while ( a4(
                    a1: v73 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v10),
                    a2: *(_DWORD *)(*(_DWORD *)(v78 + 12) + 4 * (v16 >> 8)) + 12 * (unsigned __int8)v16) != 0 );
          v26 = v16 >> 8;
          if ( (int)v5 > (int)v16 )
            break;
          v27 = *(_DWORD *)(v78 + 12);
          v76 = (int *)(*(_DWORD *)(v27 + 4 * v26) + 12 * (unsigned __int8)v16);
          v28 = (int *)(*(_DWORD *)(v27 + 4 * (v5 >> 8)) + 12 * (unsigned __int8)v5);
          v60 = *v28;
          v62 = v28[2];
          v61 = v28[1];
          *v28 = *v76;
          v28[1] = v76[1];
          v28[2] = v76[2];
          *v76 = v60;
          v76[1] = v61;
          v76[2] = v62;
        }
        v29 = *(_DWORD *)(v78 + 12);
        v30 = *(_DWORD *)(v29 + 4 * v26);
        v31 = (int *)(v73 + *(_DWORD *)(v29 + v10));
        v32 = *v31;
        v33 = (int *)(v30 + 12 * (unsigned __int8)v16);
        v51 = v31[1];
        v52 = v31[2];
        *v31 = *v33;
        v31[1] = v33[1];
        v31[2] = v33[2];
        *v33 = v32;
        v33[1] = v51;
        v33[2] = v52;
        if ( (int)(v16 - v67) <= (int)(v68 - v5) )
        {
          v35 = v74;
          v74 += 2;
          *v35 = v5;
          v5 = v67;
          v35[1] = v68;
          v6 = v74;
          v68 = v16;
        }
        else
        {
          v34 = v74;
          v74 += 2;
          *v34 = v67;
          v6 = v74;
          v34[1] = v16;
          v67 = v5;
        }
      }
      result = v5;
      v77 = v5;
      v72 = v5 + 1;
      if ( (int)(v5 + 1) < v68 )
      {
        while ( 1 )
        {
          v36 = 4 * ((unsigned int)result >> 8);
          v37 = 12 * (unsigned __int8)result;
          v38 = 4 * ((unsigned int)(result + 1) >> 8);
          v70 = 12 * (unsigned __int8)(result + 1);
          if ( a4(
                 a1: v70 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v38),
                 a2: v37 + *(_DWORD *)(*(_DWORD *)(v78 + 12) + v36)) != 0 )
          {
            do
            {
              v39 = *(_DWORD *)(v78 + 12);
              v40 = *(_DWORD *)(v39 + v36);
              v41 = (int *)(v70 + *(_DWORD *)(v39 + v38));
              v42 = *(_DWORD *)(v40 + v37);
              v43 = *v41;
              v44 = v41[1];
              v45 = (_DWORD *)(v37 + v40);
              v46 = v41[2];
              *v41 = v42;
              v41[1] = v45[1];
              v41[2] = v45[2];
              *v45 = v43;
              v47 = v77;
              v45[1] = v44;
              v45[2] = v46;
              if ( v47 == v67 )
                break;
              v48 = *(_DWORD *)(v78 + 12);
              v77 = v47 - 1;
              v36 = 4 * ((v47 - 1) >> 8);
              v37 = 12 * (unsigned __int8)(v47 - 1);
              v38 = 4 * (v47 >> 8);
              v70 = 12 * (unsigned __int8)v47;
            }
            while ( a4(a1: v70 + *(_DWORD *)(v38 + v48), a2: v37 + *(_DWORD *)(v36 + v48)) != 0 );
          }
          v77 = v72;
          result = v72 + 1;
          v72 = result;
          if ( result >= v68 )
            break;
          result = v77;
        }
        v6 = v74;
      }
      if ( v6 <= v79 )
        break;
      v49 = *(v6 - 2);
      v50 = *(v6 - 1);
      v6 -= 2;
      v67 = v49;
      v68 = v50;
      v5 = v49;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C6C0
// Name: void G_QuickSortSliced<class GArrayPagedLH_POD<unsigned int,10,64,133>,struct GTessellator::CmpScanbeams>(class GArrayPagedLH_POD<unsigned int,10,64,133> __near &,unsigned int,unsigned int,struct GTessellator::CmpScanbeams)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_QuickSortSliced<GArrayPagedLH_POD<unsigned int,10,64,133>,GTessellator::CmpScanbeams>(
        int a1,
        unsigned int a2,
        int a3,
        int a4)
{
  int result; // eax
  int v5; // ebx
  unsigned int v6; // esi
  unsigned int *i; // edi
  int v8; // edi
  int *v9; // eax
  int *v10; // ecx
  int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // esi
  int v15; // edi
  unsigned int v16; // ebx
  int v17; // ebx
  unsigned int *v18; // edi
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // esi
  int v22; // edi
  double v23; // st7
  _DWORD *v24; // esi
  int v25; // eax
  int v26; // esi
  int v27; // edi
  _DWORD *v28; // eax
  int v29; // esi
  int v30; // ebx
  int v31; // edi
  int v32; // eax
  int v33; // esi
  int v34; // ebx
  _DWORD *v35; // esi
  int *v36; // eax
  int v37; // edi
  unsigned int v38; // edx
  int v39; // edi
  int v40; // eax
  unsigned int v41; // [esp+8h] [ebp-174h]
  int v42; // [esp+Ch] [ebp-170h]
  int v43; // [esp+10h] [ebp-16Ch]
  unsigned int *v44; // [esp+14h] [ebp-168h]
  int v45; // [esp+18h] [ebp-164h]
  unsigned int *v46; // [esp+1Ch] [ebp-160h]
  int *v47; // [esp+1Ch] [ebp-160h]
  int *v48; // [esp+1Ch] [ebp-160h]
  unsigned int *v49; // [esp+20h] [ebp-15Ch]
  int v50; // [esp+24h] [ebp-158h]
  unsigned int v51; // [esp+24h] [ebp-158h]
  unsigned int v52; // [esp+28h] [ebp-154h]
  unsigned int v53; // [esp+28h] [ebp-154h]
  unsigned int v54; // [esp+2Ch] [ebp-150h]
  int *v55; // [esp+2Ch] [ebp-150h]
  int v56; // [esp+30h] [ebp-14Ch]
  int v57; // [esp+34h] [ebp-148h]
  unsigned int v58[80]; // [esp+38h] [ebp-144h] BYREF

  result = a1;
  v5 = a3;
  v6 = a2;
  v57 = a1;
  if ( a3 - a2 >= 2 )
  {
    for ( i = v58; ; i -= 2 )
    {
      v45 = v5;
      v41 = v6;
      while ( 1 )
      {
        v49 = i;
        if ( (int)(v5 - v6) <= 9 )
          break;
        v8 = *(_DWORD *)(v57 + 12);
        v9 = (int *)(*(_DWORD *)(v8 + 4 * ((v6 + (int)(v5 - v6) / 2) >> 10)) + 4 * ((v6 + (int)(v5 - v6) / 2) & 0x3FF));
        v43 = 4 * (v6 >> 10);
        v10 = (int *)(4 * (v6 & 0x3FF) + *(_DWORD *)(v43 + v8));
        v42 = 4 * (v6 & 0x3FF);
        v11 = *v10;
        *v10 = *v9;
        *v9 = v11;
        v56 = *(_DWORD *)(v57 + 12);
        v12 = v6 + 1;
        v13 = v5 - 1;
        v14 = 4 * ((v6 + 1) >> 10);
        v15 = 4 * (v12 & 0x3FF);
        v44 = (unsigned int *)(v15 + *(_DWORD *)(v14 + v56));
        v52 = *v44;
        v50 = 4 * (((_WORD)v5 - 1) & 0x3FF);
        v54 = 4 * ((unsigned int)(v5 - 1) >> 10);
        v46 = (unsigned int *)(v50 + *(_DWORD *)(v54 + v56));
        v16 = *v46;
        v56 = *v46 & 0x3FF;
        if ( *(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * (v52 >> 10)) + 8 * (v52 & 0x3FF) + 4) > (double)*(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * (v16 >> 10)) + 8 * v56 + 4) )
        {
          v53 = *v46;
          *v46 = *v44;
          *v44 = v53;
        }
        v17 = *(_DWORD *)(v57 + 12);
        v18 = (unsigned int *)(*(_DWORD *)(v14 + v17) + v15);
        v19 = *v18;
        v56 = v42 + *(_DWORD *)(v43 + v17);
        if ( *(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * (v19 >> 10)) + 8 * (v19 & 0x3FF) + 4) > (double)*(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * (*(_DWORD *)v56 >> 10)) + 8 * (*(_DWORD *)v56 & 0x3FF) + 4) )
        {
          v20 = *(_DWORD *)v56;
          *(_DWORD *)v56 = *v18;
          *v18 = v20;
        }
        v21 = *(_DWORD *)(v57 + 12);
        v22 = *(_DWORD *)(a4 + 12);
        v47 = (int *)(v50 + *(_DWORD *)(v54 + v21));
        v23 = *(float *)(*(_DWORD *)(v22 + 4 * ((unsigned int)*v47 >> 10)) + 8 * (*v47 & 0x3FF) + 4);
        v56 = v42 + *(_DWORD *)(v43 + v21);
        if ( *(float *)(*(_DWORD *)(v22 + 4 * (*(_DWORD *)v56 >> 10)) + 8 * (*(_DWORD *)v56 & 0x3FF) + 4) > v23 )
        {
          v24 = (_DWORD *)v56;
          v25 = *v47;
          *v47 = *(_DWORD *)v56;
          *v24 = v25;
        }
        while ( 1 )
        {
          v26 = *(_DWORD *)(v57 + 12);
          do
            ++v12;
          while ( *(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * (*(_DWORD *)(v42 + *(_DWORD *)(v43 + v26)) >> 10))
                           + 8 * (*(_DWORD *)(v42 + *(_DWORD *)(v43 + v26)) & 0x3FF)
                           + 4) > (double)*(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12)
                                                               + 4
                                                               * (*(_DWORD *)(*(_DWORD *)(v26 + 4 * (v12 >> 10))
                                                                            + 4 * (v12 & 0x3FF)) >> 10))
                                                   + 8
                                                   * (*(_DWORD *)(*(_DWORD *)(v26 + 4 * (v12 >> 10)) + 4 * (v12 & 0x3FF))
                                                    & 0x3FF)
                                                   + 4) );
          do
            --v13;
          while ( *(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12)
                                       + 4 * (*(_DWORD *)(*(_DWORD *)(v26 + 4 * (v13 >> 10)) + 4 * (v13 & 0x3FF)) >> 10))
                           + 8 * (*(_DWORD *)(*(_DWORD *)(v26 + 4 * (v13 >> 10)) + 4 * (v13 & 0x3FF)) & 0x3FF)
                           + 4) > (double)*(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12)
                                                               + 4 * (*(_DWORD *)(v42 + *(_DWORD *)(v43 + v26)) >> 10))
                                                   + 8 * (*(_DWORD *)(v42 + *(_DWORD *)(v43 + v26)) & 0x3FF)
                                                   + 4) );
          v27 = v13 & 0x3FF;
          if ( (int)v12 > (int)v13 )
            break;
          v28 = (_DWORD *)(*(_DWORD *)(v26 + 4 * (v13 >> 10)) + 4 * v27);
          v29 = *(_DWORD *)(v26 + 4 * (v12 >> 10));
          v30 = v12 & 0x3FF;
          v31 = *(_DWORD *)(v29 + 4 * v30);
          *(_DWORD *)(v29 + 4 * v30) = *v28;
          *v28 = v31;
        }
        v32 = *(_DWORD *)(v57 + 12);
        v33 = *(_DWORD *)(v32 + 4 * (v13 >> 10));
        v34 = *(_DWORD *)(v33 + 4 * v27);
        v35 = (_DWORD *)(v33 + 4 * v27);
        v36 = (int *)(v42 + *(_DWORD *)(v43 + v32));
        v37 = *v36;
        *v36 = v34;
        v5 = v45;
        *v35 = v37;
        v6 = v41;
        if ( (int)(v13 - v41) <= (int)(v45 - v12) )
        {
          v49[1] = v45;
          v5 = v13;
          *v49 = v12;
          v45 = v13;
        }
        else
        {
          *v49 = v41;
          v6 = v12;
          v49[1] = v13;
          v41 = v12;
        }
        i = v49 + 2;
      }
      result = v6 + 1;
      v38 = v6;
      v51 = v6 + 1;
      if ( (int)(v6 + 1) < v5 )
      {
        do
        {
          while ( 1 )
          {
            v39 = *(_DWORD *)(v57 + 12);
            v55 = (int *)(*(_DWORD *)(v39 + 4 * ((v38 + 1) >> 10)) + 4 * ((v38 + 1) & 0x3FF));
            v48 = (int *)(*(_DWORD *)(v39 + 4 * (v38 >> 10)) + 4 * (v38 & 0x3FF));
            if ( *(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * ((unsigned int)*v48 >> 10)) + 8 * (*v48 & 0x3FF) + 4) <= (double)*(float *)(*(_DWORD *)(*(_DWORD *)(a4 + 12) + 4 * ((unsigned int)*v55 >> 10)) + 8 * (*v55 & 0x3FF) + 4) )
              break;
            v40 = *v55;
            *v55 = *v48;
            *v48 = v40;
            if ( v38 == v6 )
              break;
            --v38;
          }
          v38 = v51;
          result = v51 + 1;
          v51 = result;
        }
        while ( result < v45 );
        i = v49;
      }
      if ( i <= v58 )
        break;
      v6 = *(i - 2);
      v5 = *(i - 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018CBC0
// Name: void G_QuickSortSliced<class GArrayPagedLH_POD<struct GTessellator::MonotoneType,6,64,133>,bool (*)(struct GTessellator::MonotoneType const __near &,struct GTessellator::MonotoneType const __near &)>(class GArrayPagedLH_POD<struct GTessellator::MonotoneType,6,64,133> __near &,unsigned int,unsigned int,bool (*)(struct GTessellator::MonotoneType const __near &,struct GTessellator::MonotoneType const __near &))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_QuickSortSliced<GArrayPagedLH_POD<GTessellator::MonotoneType,6,64,133>,bool (__cdecl *)(GTessellator::MonotoneType const &,GTessellator::MonotoneType const &)>(
        int a1,
        unsigned int a2,
        int a3,
        unsigned __int8 (__cdecl *a4)(int, int))
{
  int v4; // ebx
  int result; // eax
  unsigned int v6; // esi
  unsigned int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int *v17; // eax
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int *v21; // ecx
  int v22; // ecx
  int *v23; // eax
  int *v24; // ecx
  int v25; // ecx
  unsigned int v26; // edx
  int v27; // ebx
  int *v28; // eax
  int v29; // edx
  int v30; // ebx
  int *v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // ecx
  int *v35; // edi
  int *v36; // eax
  int v37; // ecx
  unsigned int *v38; // ecx
  unsigned int *v39; // edx
  int v40; // esi
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // eax
  int *v45; // ecx
  int *v46; // eax
  int v47; // esi
  int v48; // edi
  int v49; // ebx
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // eax
  int v53; // edx
  int v54; // [esp-Ch] [ebp-22Ch]
  int v55; // [esp-Ch] [ebp-22Ch]
  int v56; // [esp-8h] [ebp-228h]
  int v57; // [esp-8h] [ebp-228h]
  int v58; // [esp+14h] [ebp-20Ch]
  int v59; // [esp+18h] [ebp-208h]
  int v60; // [esp+1Ch] [ebp-204h]
  int v61; // [esp+24h] [ebp-1FCh]
  int v62; // [esp+28h] [ebp-1F8h]
  int v63; // [esp+2Ch] [ebp-1F4h]
  int v64; // [esp+30h] [ebp-1F0h]
  int v65; // [esp+34h] [ebp-1ECh]
  int v66; // [esp+40h] [ebp-1E0h]
  int v67; // [esp+44h] [ebp-1DCh]
  int v68; // [esp+48h] [ebp-1D8h]
  int v69; // [esp+4Ch] [ebp-1D4h]
  int v70; // [esp+50h] [ebp-1D0h]
  int v71; // [esp+54h] [ebp-1CCh]
  int v72; // [esp+58h] [ebp-1C8h]
  int v73; // [esp+5Ch] [ebp-1C4h]
  int v74; // [esp+60h] [ebp-1C0h]
  int v75; // [esp+64h] [ebp-1BCh]
  int v76; // [esp+68h] [ebp-1B8h]
  int v77; // [esp+6Ch] [ebp-1B4h]
  int v78; // [esp+70h] [ebp-1B0h]
  int v79; // [esp+74h] [ebp-1ACh]
  int v80; // [esp+78h] [ebp-1A8h]
  int v81; // [esp+7Ch] [ebp-1A4h]
  int v82; // [esp+80h] [ebp-1A0h]
  int v83; // [esp+84h] [ebp-19Ch]
  int v84; // [esp+88h] [ebp-198h]
  int v85; // [esp+8Ch] [ebp-194h]
  int v86; // [esp+90h] [ebp-190h]
  int v87; // [esp+94h] [ebp-18Ch]
  int v88; // [esp+98h] [ebp-188h]
  int v89; // [esp+9Ch] [ebp-184h]
  int v90; // [esp+A0h] [ebp-180h]
  int v91; // [esp+A4h] [ebp-17Ch]
  int v92; // [esp+A8h] [ebp-178h]
  int v93; // [esp+ACh] [ebp-174h]
  unsigned int v94; // [esp+B0h] [ebp-170h]
  int v95; // [esp+B8h] [ebp-168h]
  int v96; // [esp+BCh] [ebp-164h]
  unsigned int v97; // [esp+C0h] [ebp-160h]
  int v98; // [esp+C0h] [ebp-160h]
  unsigned int v99; // [esp+C4h] [ebp-15Ch]
  unsigned int *v100; // [esp+C8h] [ebp-158h]
  int v101; // [esp+D0h] [ebp-150h]
  int v102; // [esp+D0h] [ebp-150h]
  int v103; // [esp+D4h] [ebp-14Ch]
  int v104; // [esp+D8h] [ebp-148h]
  unsigned int v105[80]; // [esp+DCh] [ebp-144h] BYREF

  v4 = a1;
  result = a3;
  v6 = a2;
  if ( a3 - a2 >= 2 )
  {
    v7 = v105;
    v99 = a2;
    v95 = a3;
    while ( 1 )
    {
      v100 = v7;
      while ( (int)(v95 - v6) > 9 )
      {
        v8 = (int *)(*(_DWORD *)(*(_DWORD *)(v4 + 12) + 4 * ((v6 + (int)(v95 - v6) / 2) >> 6))
                   + 24 * ((v6 + (int)(v95 - v6) / 2) & 0x3F));
        v96 = 24 * (v6 & 0x3F);
        v9 = 4 * (v6 >> 6);
        v10 = (int *)(v96 + *(_DWORD *)(v9 + *(_DWORD *)(v4 + 12)));
        v88 = *v10;
        v89 = v10[1];
        v90 = v10[2];
        v91 = v10[3];
        v92 = v10[4];
        v93 = v10[5];
        *v10 = *v8;
        v10[1] = v8[1];
        v10[2] = v8[2];
        v10[3] = v8[3];
        v10[4] = v8[4];
        v10[5] = v8[5];
        *v8 = v88;
        v8[1] = v89;
        v8[2] = v90;
        v8[3] = v91;
        v8[4] = v92;
        v8[5] = v93;
        LOBYTE(v10) = v6 + 1;
        v97 = v6 + 1;
        v11 = 4 * ((v6 + 1) >> 6);
        v12 = v95 - 1;
        v13 = 24 * ((unsigned __int8)v10 & 0x3F);
        v94 = v11;
        v14 = v13 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v11);
        v101 = v13;
        v104 = 24 * (((_BYTE)v95 - 1) & 0x3F);
        v15 = *(_DWORD *)(v4 + 12);
        v103 = 4 * ((unsigned int)(v95 - 1) >> 6);
        if ( a4(a1: v104 + *(_DWORD *)(v103 + v15), a2: v14) != 0 )
        {
          v16 = *(_DWORD *)(v4 + 12);
          v17 = (int *)(v101 + *(_DWORD *)(v16 + v94));
          v18 = (int *)(v104 + *(_DWORD *)(v16 + v103));
          v76 = *v18;
          v77 = v18[1];
          v78 = v18[2];
          v79 = v18[3];
          v80 = v18[4];
          v81 = v18[5];
          *v18 = *v17;
          v18[1] = v17[1];
          v18[2] = v17[2];
          v18[3] = v17[3];
          v18[4] = v17[4];
          v18[5] = v17[5];
          *v17 = v76;
          v17[1] = v77;
          v17[2] = v78;
          v17[3] = v79;
          v17[4] = v80;
          v17[5] = v81;
        }
        if ( a4(a1: v96 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v9), a2: v101 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v94)) != 0 )
        {
          v19 = *(_DWORD *)(v4 + 12);
          v20 = (int *)(v101 + *(_DWORD *)(v19 + v94));
          v21 = (int *)(v96 + *(_DWORD *)(v19 + v9));
          v70 = *v21;
          v71 = v21[1];
          v72 = v21[2];
          v73 = v21[3];
          v74 = v21[4];
          v75 = v21[5];
          *v21 = *v20;
          v21[1] = v20[1];
          v21[2] = v20[2];
          v21[3] = v20[3];
          v21[4] = v20[4];
          v21[5] = v20[5];
          *v20 = v70;
          v20[1] = v71;
          v20[2] = v72;
          v20[3] = v73;
          v20[4] = v74;
          v20[5] = v75;
        }
        if ( a4(a1: v104 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v103), a2: v96 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v9)) != 0 )
        {
          v22 = *(_DWORD *)(v4 + 12);
          v23 = (int *)(v96 + *(_DWORD *)(v22 + v9));
          v24 = (int *)(v104 + *(_DWORD *)(v22 + v103));
          v82 = *v24;
          v83 = v24[1];
          v84 = v24[2];
          v85 = v24[3];
          v86 = v24[4];
          v87 = v24[5];
          *v24 = *v23;
          v24[1] = v23[1];
          v24[2] = v23[2];
          v24[3] = v23[3];
          v24[4] = v23[4];
          v24[5] = v23[5];
          *v23 = v82;
          v23[1] = v83;
          v23[2] = v84;
          v23[3] = v85;
          v23[4] = v86;
          v23[5] = v87;
        }
        while ( 1 )
        {
          do
          {
            v25 = *(_DWORD *)(v4 + 12);
            v103 = v96 + *(_DWORD *)(v25 + v9);
            ++v97;
          }
          while ( a4(a1: *(_DWORD *)(v25 + 4 * (v97 >> 6)) + 24 * (v97 & 0x3F), a2: v103) != 0 );
          do
            --v12;
          while ( a4(
                    a1: v96 + *(_DWORD *)(*(_DWORD *)(v4 + 12) + v9),
                    a2: *(_DWORD *)(*(_DWORD *)(v4 + 12) + 4 * (v12 >> 6)) + 24 * (v12 & 0x3F)) != 0 );
          v26 = v12 >> 6;
          if ( (int)v97 > (int)v12 )
            break;
          v27 = *(_DWORD *)(v4 + 12);
          v28 = (int *)(*(_DWORD *)(v27 + 4 * v26) + 24 * (v12 & 0x3F));
          v29 = *(_DWORD *)(v27 + 4 * (v97 >> 6));
          v30 = *(_DWORD *)(v29 + 24 * (v97 & 0x3F) + 4);
          v31 = (int *)(v29 + 24 * (v97 & 0x3F));
          v32 = *v31;
          v66 = v31[2];
          v67 = v31[3];
          v68 = v31[4];
          v69 = v31[5];
          *v31 = *v28;
          v31[1] = v28[1];
          v31[2] = v28[2];
          v31[3] = v28[3];
          v31[4] = v28[4];
          v31[5] = v28[5];
          v33 = v30;
          v4 = a1;
          *v28 = v32;
          v28[1] = v33;
          v28[2] = v66;
          v28[3] = v67;
          v28[4] = v68;
          v28[5] = v69;
        }
        v34 = *(_DWORD *)(v4 + 12);
        v35 = (int *)(v96 + *(_DWORD *)(v34 + v9));
        v36 = (int *)(*(_DWORD *)(v34 + 4 * v26) + 24 * (v12 & 0x3F));
        v37 = *v35;
        v61 = v35[1];
        v62 = v35[2];
        v63 = v35[3];
        v64 = v35[4];
        v65 = v35[5];
        *v35 = *v36;
        v35[1] = v36[1];
        v35[2] = v36[2];
        v35[3] = v36[3];
        v35[4] = v36[4];
        v35[5] = v36[5];
        *v36 = v37;
        v36[1] = v61;
        v36[2] = v62;
        v36[3] = v63;
        v36[4] = v64;
        v36[5] = v65;
        if ( (int)(v12 - v99) <= (int)(v95 - v97) )
        {
          v39 = v100;
          v100 += 2;
          v39[1] = v95;
          v7 = v100;
          v95 = v12;
          v6 = v99;
          *v39 = v97;
        }
        else
        {
          v38 = v100;
          v100 += 2;
          v38[1] = v12;
          *v38 = v99;
          v7 = v100;
          v99 = v97;
          v6 = v97;
        }
      }
      result = v6;
      v104 = v6;
      v98 = v6 + 1;
      if ( (int)(v6 + 1) < v95 )
      {
        while ( 1 )
        {
          v102 = *(_DWORD *)(v4 + 12);
          v40 = 4 * ((unsigned int)result >> 6);
          v41 = 24 * (result & 0x3F);
          v42 = 4 * ((unsigned int)(result + 1) >> 6);
          v56 = v41 + *(_DWORD *)(v102 + v40);
          v54 = 24 * ((result + 1) & 0x3F) + *(_DWORD *)(v102 + v42);
          v103 = 24 * ((result + 1) & 0x3F);
          if ( a4(a1: v54, a2: v56) != 0 )
          {
            do
            {
              v43 = *(_DWORD *)(a1 + 12);
              v44 = *(_DWORD *)(v43 + v40);
              v45 = (int *)(v103 + *(_DWORD *)(v43 + v42));
              v46 = (int *)(v41 + v44);
              v47 = *v45;
              v48 = v45[1];
              v49 = v45[2];
              v58 = v45[3];
              v59 = v45[4];
              v60 = v45[5];
              *v45 = *v46;
              v45[1] = v46[1];
              v45[2] = v46[2];
              v45[3] = v46[3];
              v45[4] = v46[4];
              v45[5] = v46[5];
              *v46 = v47;
              v46[1] = v48;
              v46[2] = v49;
              v46[3] = v58;
              v46[4] = v59;
              v46[5] = v60;
              v50 = v104;
              if ( v104 == v99 )
                break;
              v51 = *(_DWORD *)(a1 + 12);
              --v104;
              v40 = 4 * ((v50 - 1) >> 6);
              v41 = 24 * (((_BYTE)v50 - 1) & 0x3F);
              v42 = 4 * (v50 >> 6);
              v57 = v41 + *(_DWORD *)(v40 + v51);
              v55 = 24 * (v50 & 0x3F) + *(_DWORD *)(v42 + v51);
              v103 = 24 * (v50 & 0x3F);
            }
            while ( a4(a1: v55, a2: v57) != 0 );
          }
          v4 = a1;
          v104 = v98;
          result = v98 + 1;
          v98 = result;
          if ( result >= v95 )
            break;
          result = v104;
        }
        v7 = v100;
      }
      if ( v7 <= v105 )
        break;
      v52 = *(v7 - 2);
      v53 = *(v7 - 1);
      v7 -= 2;
      v99 = v52;
      v95 = v53;
      v6 = v52;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199E80
// Name: void G_QuickSortSliced<class GArrayUnsafeLH_POD<unsigned int,136>,struct GEdgeAA::EdgeIdxLess>(class GArrayUnsafeLH_POD<unsigned int,136> __near &,unsigned int,unsigned int,struct GEdgeAA::EdgeIdxLess)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_QuickSortSliced<GArrayUnsafeLH_POD<unsigned int,136>,GEdgeAA::EdgeIdxLess>(
        int *a1,
        _DWORD *a2,
        int a3,
        int a4,
        int a5)
{
  int result; // eax
  int v6; // esi
  int v7; // edi
  _BYTE *v8; // ecx
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // esi
  unsigned int v15; // ecx
  int v16; // ebx
  unsigned int *v17; // ecx
  int v18; // esi
  unsigned int v19; // ebx
  bool v20; // cf
  int v21; // ebx
  int v22; // ecx
  int v23; // edx
  unsigned int *v24; // ecx
  int v25; // edx
  unsigned int v26; // esi
  bool v27; // cf
  int v28; // ecx
  int v29; // edx
  unsigned int *v30; // ecx
  int v31; // edx
  unsigned int v32; // esi
  bool v33; // cf
  int v34; // edx
  unsigned int v35; // ecx
  int v36; // edi
  int v37; // esi
  unsigned int v38; // eax
  unsigned int *v39; // eax
  unsigned int v40; // edx
  bool v41; // cf
  int v42; // ebx
  int v43; // eax
  int v44; // ecx
  unsigned int v45; // edi
  int v46; // edx
  unsigned int v47; // eax
  unsigned int *v48; // eax
  bool v49; // cf
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // ecx
  int v54; // esi
  _DWORD *v55; // edx
  unsigned int *v56; // ecx
  int v57; // esi
  unsigned int v58; // ebx
  bool v59; // cf
  int v60; // eax
  int v61; // eax
  unsigned int v62; // [esp+8h] [ebp-168h]
  unsigned int *v63; // [esp+Ch] [ebp-164h]
  int v64; // [esp+Ch] [ebp-164h]
  int v65; // [esp+10h] [ebp-160h]
  _DWORD *v66; // [esp+14h] [ebp-15Ch]
  int v67; // [esp+18h] [ebp-158h]
  int v68; // [esp+18h] [ebp-158h]
  int v69; // [esp+18h] [ebp-158h]
  int v70; // [esp+1Ch] [ebp-154h]
  int v71; // [esp+24h] [ebp-14Ch]
  int v72; // [esp+28h] [ebp-148h]
  _BYTE v73[320]; // [esp+2Ch] [ebp-144h] BYREF

  result = (int)a1;
  v6 = a3;
  v7 = (int)a2;
  if ( (unsigned int)(a3 - (_DWORD)a2) >= 2 )
  {
    v8 = v73;
    v70 = a3;
    while ( 1 )
    {
      v65 = v7;
      while ( 1 )
      {
        v66 = v8;
        if ( v6 - v7 <= 9 )
          break;
        v9 = *a1;
        v10 = *(_DWORD *)(*a1 + 4 * v7);
        v11 = v7 + (v6 - v7) / 2;
        *(_DWORD *)(v9 + 4 * v7) = *(_DWORD *)(*a1 + 4 * v11);
        *(_DWORD *)(v9 + 4 * v11) = v10;
        v12 = *a1;
        v13 = v6 - 1;
        v14 = *(_DWORD *)(a5 + 12);
        v72 = v13;
        v15 = *(_DWORD *)(v12 + 4 * v13);
        v16 = *(_DWORD *)(v14 + 4 * (v15 >> 10));
        v71 = v7 + 1;
        v17 = (unsigned int *)(v16 + 12 * (v15 & 0x3FF));
        v18 = *(_DWORD *)(v14 + 4 * (*(_DWORD *)(v12 + 4 * (v7 + 1)) >> 10));
        v19 = *(_DWORD *)(v18 + 12 * (*(_DWORD *)(v12 + 4 * (v7 + 1)) & 0x3FF));
        v20 = *v17 < v19;
        if ( *v17 == v19 )
          v20 = v17[1] < *(_DWORD *)(v18 + 12 * (*(_DWORD *)(v12 + 4 * (v7 + 1)) & 0x3FF) + 4);
        v21 = v71;
        if ( v20 )
        {
          v22 = *(_DWORD *)(v12 + 4 * v72);
          *(_DWORD *)(v12 + 4 * v72) = *(_DWORD *)(v12 + 4 * v71);
          *(_DWORD *)(v12 + 4 * v21) = v22;
        }
        v23 = *(_DWORD *)(a5 + 12);
        v67 = *a1;
        v24 = (unsigned int *)(*(_DWORD *)(v23 + 4 * (*(_DWORD *)(v67 + 4 * v7) >> 10))
                             + 12 * (*(_DWORD *)(v67 + 4 * v7) & 0x3FF));
        v25 = *(_DWORD *)(v23 + 4 * (*(_DWORD *)(*a1 + 4 * v21) >> 10));
        v26 = *(_DWORD *)(v25 + 12 * (*(_DWORD *)(*a1 + 4 * v21) & 0x3FF));
        v27 = *v24 < v26;
        if ( *v24 == v26 )
          v27 = v24[1] < *(_DWORD *)(v25 + 12 * (*(_DWORD *)(*a1 + 4 * v21) & 0x3FF) + 4);
        if ( v27 )
        {
          v28 = *(_DWORD *)(v67 + 4 * v7);
          *(_DWORD *)(v67 + 4 * v7) = *(_DWORD *)(v67 + 4 * v21);
          *(_DWORD *)(v67 + 4 * v21) = v28;
        }
        v68 = *a1;
        v29 = *(_DWORD *)(a5 + 12);
        v30 = (unsigned int *)(*(_DWORD *)(v29 + 4 * (*(_DWORD *)(v68 + 4 * v72) >> 10))
                             + 12 * (*(_DWORD *)(v68 + 4 * v72) & 0x3FF));
        v31 = *(_DWORD *)(v29 + 4 * (*(_DWORD *)(*a1 + 4 * v7) >> 10));
        v32 = *(_DWORD *)(v31 + 12 * (*(_DWORD *)(*a1 + 4 * v7) & 0x3FF));
        v33 = *v30 < v32;
        if ( *v30 == v32 )
          v33 = v30[1] < *(_DWORD *)(v31 + 12 * (*(_DWORD *)(*a1 + 4 * v7) & 0x3FF) + 4);
        if ( v33 )
        {
          v34 = *(_DWORD *)(v68 + 4 * v72);
          *(_DWORD *)(v68 + 4 * v72) = *(_DWORD *)(v68 + 4 * v7);
          *(_DWORD *)(v68 + 4 * v7) = v34;
        }
        while ( 1 )
        {
          v35 = *(_DWORD *)(*a1 + 4 * v7);
          v36 = *(_DWORD *)(a5 + 12);
          v63 = (unsigned int *)(*(_DWORD *)(v36 + 4 * (v35 >> 10)) + 12 * (v35 & 0x3FF));
          v69 = *a1;
          v62 = *v63;
          v37 = *a1 + 4 * v21;
          while ( 1 )
          {
            v38 = *(_DWORD *)(v37 + 4);
            v37 += 4;
            v39 = (unsigned int *)(*(_DWORD *)(v36 + 4 * (v38 >> 10)) + 12 * (v38 & 0x3FF));
            v40 = *v39;
            v71 = v21 + 1;
            v41 = v40 < v62;
            if ( v40 == v62 )
              v41 = v39[1] < v63[1];
            if ( !v41 )
              break;
            v21 = v71;
          }
          v42 = *(_DWORD *)(a5 + 12);
          v6 = v72;
          v43 = 3 * (v35 & 0x3FF);
          v44 = *(_DWORD *)(v42 + 4 * (v35 >> 10));
          v45 = *(_DWORD *)(v44 + 4 * v43);
          v64 = v44 + 4 * v43;
          v46 = v69 + 4 * v72;
          do
          {
            v47 = *(_DWORD *)(v46 - 4);
            v46 -= 4;
            v48 = (unsigned int *)(*(_DWORD *)(v42 + 4 * (v47 >> 10)) + 12 * (v47 & 0x3FF));
            --v6;
            v49 = v45 < *v48;
            if ( v45 == *v48 )
              v49 = *(_DWORD *)(v64 + 4) < v48[1];
          }
          while ( v49 );
          v21 = v71;
          v7 = v65;
          v72 = v6;
          if ( v71 > v6 )
            break;
          v50 = *(_DWORD *)(v69 + 4 * v71);
          *(_DWORD *)(v69 + 4 * v71) = *(_DWORD *)(v69 + 4 * v6);
          *(_DWORD *)(v69 + 4 * v6) = v50;
        }
        v51 = *a1;
        v52 = *(_DWORD *)(*a1 + 4 * v65);
        *(_DWORD *)(v51 + 4 * v65) = *(_DWORD *)(*a1 + 4 * v6);
        *(_DWORD *)(v51 + 4 * v6) = v52;
        if ( v6 - v65 <= v70 - v21 )
        {
          *v66 = v21;
          v66[1] = v70;
          v70 = v6;
          v8 = v66 + 2;
        }
        else
        {
          *v66 = v65;
          v66[1] = v6;
          v7 = v21;
          v65 = v21;
          v8 = v66 + 2;
          v6 = v70;
        }
      }
      result = v7;
      v72 = v7;
      v71 = v7 + 1;
      if ( v7 + 1 < v6 )
      {
        do
        {
          while ( 1 )
          {
            v53 = *(_DWORD *)(*a1 + 4 * result + 4);
            v54 = *(_DWORD *)(a5 + 12);
            v55 = (_DWORD *)(*a1 + 4 * result);
            v56 = (unsigned int *)(*(_DWORD *)(v54 + 4 * (v53 >> 10)) + 12 * (v53 & 0x3FF));
            v57 = *(_DWORD *)(v54 + 4 * (*v55 >> 10));
            v58 = *(_DWORD *)(v57 + 12 * (*v55 & 0x3FF));
            v59 = *v56 < v58;
            if ( *v56 == v58 )
              v59 = v56[1] < *(_DWORD *)(v57 + 12 * (*v55 & 0x3FF) + 4);
            if ( !v59 )
              break;
            v60 = v55[1];
            v55[1] = *v55;
            *v55 = v60;
            if ( v72 == v7 )
              break;
            result = --v72;
          }
          result = v71;
          v72 = v71++;
        }
        while ( v71 < v70 );
        v8 = v66;
      }
      if ( v8 <= v73 )
        break;
      v61 = *((_DWORD *)v8 - 1);
      v7 = *((_DWORD *)v8 - 2);
      v8 -= 8;
      v70 = v61;
      v6 = v61;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A340
// Name: void G_QuickSortSliced<class GArrayPagedLH_POD<struct GEdgeAA::TriangleType,8,64,136>,struct GEdgeAA::TriangleLess>(class GArrayPagedLH_POD<struct GEdgeAA::TriangleType,8,64,136> __near &,unsigned int,unsigned int,struct GEdgeAA::TriangleLess)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl G_QuickSortSliced<GArrayPagedLH_POD<GEdgeAA::TriangleType,8,64,136>,GEdgeAA::TriangleLess>(
        int a1,
        _DWORD *a2,
        _DWORD *a3)
{
  _DWORD *result; // eax
  int v4; // ebx
  int *v5; // ecx
  int v6; // esi
  int *v7; // ecx
  int v8; // edx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  int v13; // edx
  int v14; // edx
  unsigned int v15; // esi
  _DWORD *v16; // ecx
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  _DWORD *v20; // ecx
  _DWORD *v21; // eax
  _DWORD *v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // ecx
  int v25; // eax
  int *v26; // eax
  int v27; // edx
  int v28; // edi
  int *v29; // ecx
  int v30; // edx
  int v31; // ecx
  int v32; // ecx
  int *v33; // edi
  int v34; // edx
  int v35; // ecx
  int *v36; // eax
  int *v37; // eax
  int *v38; // ecx
  int v39; // edx
  int *v40; // esi
  int *i; // edi
  int v42; // eax
  int v43; // ecx
  int v44; // ecx
  _DWORD *v45; // eax
  int v46; // edx
  int v47; // [esp+Ch] [ebp-1C0h]
  int v48; // [esp+14h] [ebp-1B8h]
  int v49; // [esp+18h] [ebp-1B4h]
  int v50; // [esp+24h] [ebp-1A8h]
  int v51; // [esp+30h] [ebp-19Ch]
  int v52; // [esp+34h] [ebp-198h]
  int v53; // [esp+38h] [ebp-194h]
  int v54; // [esp+3Ch] [ebp-190h]
  int v55; // [esp+40h] [ebp-18Ch]
  int v56; // [esp+44h] [ebp-188h]
  int v57; // [esp+4Ch] [ebp-180h]
  int v58; // [esp+50h] [ebp-17Ch]
  int v59; // [esp+54h] [ebp-178h]
  int v60; // [esp+58h] [ebp-174h]
  int v61; // [esp+5Ch] [ebp-170h]
  int v62; // [esp+60h] [ebp-16Ch]
  _DWORD *v63; // [esp+68h] [ebp-164h]
  _DWORD *v64; // [esp+68h] [ebp-164h]
  int v65; // [esp+6Ch] [ebp-160h]
  int v66; // [esp+70h] [ebp-15Ch]
  _DWORD *v67; // [esp+74h] [ebp-158h]
  int *v68; // [esp+78h] [ebp-154h]
  _DWORD *v69; // [esp+80h] [ebp-14Ch]
  _DWORD *v70; // [esp+84h] [ebp-148h]
  int v71[80]; // [esp+88h] [ebp-144h] BYREF

  result = a3;
  v4 = (int)a2;
  if ( (unsigned int)((char *)a3 - (char *)a2) >= 2 )
  {
    v5 = v71;
    v67 = a2;
    v66 = (int)a3;
    while ( 1 )
    {
      v68 = v5;
      while ( v66 - v4 > 9 )
      {
        v6 = *(_DWORD *)(a1 + 12);
        v7 = (int *)(*(_DWORD *)(v6 + 4 * ((unsigned int)(v4 + (v66 - v4) / 2) >> 8))
                   + 12 * (unsigned __int8)(v4 + (v66 - v4) / 2));
        v8 = 12 * (unsigned __int8)v4;
        v9 = 4 * ((unsigned int)v4 >> 8);
        v10 = *(_DWORD *)(v9 + v6);
        v11 = *(_DWORD *)(v10 + v8 + 4);
        v12 = (int *)(v8 + v10);
        v51 = v12[2];
        v65 = v8;
        v13 = *v12;
        *v12 = *v7;
        v12[1] = v7[1];
        v12[2] = v7[2];
        *v7 = v13;
        v7[1] = v11;
        v7[2] = v51;
        v14 = *(_DWORD *)(a1 + 12);
        v69 = (_DWORD *)(4 * ((unsigned int)++v4 >> 8));
        v63 = (_DWORD *)(12 * (unsigned __int8)v4 + *(_DWORD *)((char *)v69 + v14));
        v15 = v66 - 1;
        v56 = 12 * (unsigned __int8)(v66 - 1);
        v70 = (_DWORD *)(*(_DWORD *)(4 * ((unsigned int)(v66 - 1) >> 8) + v14) + v56);
        v52 = v9;
        if ( (unsigned __int8)GEdgeAA::TriangleLess::operator()(a1: v70, a2: v63) != 0 )
        {
          v16 = v70;
          v53 = *v70;
          v55 = v70[2];
          v54 = v70[1];
          *v70 = *v63;
          v16[1] = v63[1];
          v16[2] = v63[2];
          *v63 = v53;
          v63[1] = v54;
          v63[2] = v55;
        }
        v17 = *(_DWORD *)(a1 + 12);
        v64 = (_DWORD *)(*(_DWORD *)((char *)v69 + v17) + 12 * (unsigned __int8)v4);
        v69 = (_DWORD *)(*(_DWORD *)(v9 + v17) + v65);
        if ( (unsigned __int8)GEdgeAA::TriangleLess::operator()(a1: v69, a2: v64) != 0 )
        {
          v18 = v69;
          v57 = *v69;
          v59 = v69[2];
          v58 = v69[1];
          *v69 = *v64;
          v18[1] = v64[1];
          v18[2] = v64[2];
          *v64 = v57;
          v64[1] = v58;
          v64[2] = v59;
        }
        v19 = *(_DWORD *)(a1 + 12);
        v20 = (_DWORD *)(v65 + *(_DWORD *)(v9 + v19));
        v21 = (_DWORD *)(v56 + *(_DWORD *)(4 * ((unsigned int)(v66 - 1) >> 8) + v19));
        v69 = v20;
        v70 = v21;
        if ( (unsigned __int8)GEdgeAA::TriangleLess::operator()(a1: v21, a2: v20) != 0 )
        {
          v22 = v70;
          v60 = *v70;
          v61 = v70[1];
          v62 = v70[2];
          v23 = v69;
          *v70 = *v69;
          v22[1] = v23[1];
          v22[2] = v23[2];
          *v23 = v60;
          v23[1] = v61;
          v23[2] = v62;
        }
        while ( 1 )
        {
          v24 = *(_DWORD **)(a1 + 12);
          v25 = *(_DWORD *)((char *)v24 + v9);
          v70 = v24;
          v69 = (_DWORD *)(v65 + v25);
          while ( 1 )
          {
            ++v4;
            if ( (unsigned __int8)GEdgeAA::TriangleLess::operator()(
                                    a1: v24[(unsigned int)v4 >> 8] + 12 * (unsigned __int8)v4,
                                    a2: v69) == 0 )
              break;
            v24 = v70;
          }
          do
            --v15;
          while ( (unsigned __int8)GEdgeAA::TriangleLess::operator()(
                                     a1: v69,
                                     a2: v70[v15 >> 8] + 12 * (unsigned __int8)v15) != 0 );
          if ( v4 > (int)v15 )
            break;
          v26 = (int *)(v70[v15 >> 8] + 12 * (unsigned __int8)v15);
          v27 = v70[(unsigned int)v4 >> 8];
          v28 = *(_DWORD *)(v27 + 12 * (unsigned __int8)v4 + 4);
          v29 = (int *)(v27 + 12 * (unsigned __int8)v4);
          v30 = *v29;
          v50 = v29[2];
          *v29 = *v26;
          v29[1] = v26[1];
          v29[2] = v26[2];
          v31 = v28;
          v9 = v52;
          *v26 = v30;
          v26[1] = v31;
          v26[2] = v50;
        }
        v32 = *(_DWORD *)(a1 + 12);
        v33 = (int *)(v65 + *(_DWORD *)(v9 + v32));
        v34 = *(_DWORD *)(v32 + 4 * (v15 >> 8));
        v35 = *v33;
        v36 = (int *)(v34 + 12 * (unsigned __int8)v15);
        v48 = v33[1];
        v49 = v33[2];
        *v33 = *v36;
        v33[1] = v36[1];
        v33[2] = v36[2];
        *v36 = v35;
        v36[1] = v48;
        v36[2] = v49;
        if ( (int)(v15 - (_DWORD)v67) <= v66 - v4 )
        {
          v38 = v68;
          v68 += 2;
          *v38 = v4;
          v4 = (int)v67;
          v38[1] = v66;
          v5 = v68;
          v66 = v15;
        }
        else
        {
          v37 = v68;
          v68 += 2;
          *v37 = (int)v67;
          v5 = v68;
          v37[1] = v15;
          v67 = (_DWORD *)v4;
        }
      }
      result = (_DWORD *)(v4 + 1);
      v70 = (_DWORD *)(v4 + 1);
      if ( v4 + 1 < v66 )
      {
        do
        {
          v39 = *(_DWORD *)(a1 + 12);
          v40 = (int *)(*(_DWORD *)(v39 + 4 * ((unsigned int)v4 >> 8)) + 12 * (unsigned __int8)v4);
          for ( i = (int *)(*(_DWORD *)(v39 + 4 * ((unsigned int)(v4 + 1) >> 8)) + 12 * (unsigned __int8)(v4 + 1));
                (unsigned __int8)GEdgeAA::TriangleLess::operator()(a1: i, a2: v40) != 0;
                i = (int *)(*(_DWORD *)(v44 + 4 * ((unsigned int)(v4 + 1) >> 8)) + 12 * (unsigned __int8)(v4 + 1)) )
          {
            v42 = *i;
            v43 = i[1];
            v47 = i[2];
            *i = *v40;
            i[1] = v40[1];
            i[2] = v40[2];
            *v40 = v42;
            v40[1] = v43;
            v40[2] = v47;
            if ( (_DWORD *)v4 == v67 )
              break;
            v44 = *(_DWORD *)(a1 + 12);
            --v4;
            v40 = (int *)(*(_DWORD *)(v44 + 4 * ((unsigned int)v4 >> 8)) + 12 * (unsigned __int8)v4);
          }
          v4 = (int)v70;
          result = (_DWORD *)((char *)v70 + 1);
          v70 = result;
        }
        while ( (int)result < v66 );
        v5 = v68;
      }
      if ( v5 <= v71 )
        break;
      v45 = (_DWORD *)*(v5 - 2);
      v46 = *(v5 - 1);
      v5 -= 2;
      v67 = v45;
      v66 = v46;
      v4 = (int)v45;
    }
  }
  return result;
}
