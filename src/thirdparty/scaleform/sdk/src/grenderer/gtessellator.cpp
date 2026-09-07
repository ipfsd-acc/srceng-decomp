// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gtessellator.cpp
// Functions: 54
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gtessellator.h"

//------------------------------------------------------------------------------
// Address: 0x1018B390
// Name: private: static int GTessellator::pendingMonotoneStyle(struct GTessellator::PendingEndType const __near *)
// Source: json
//------------------------------------------------------------------------------
static char (__thiscall *__cdecl GTessellator::pendingMonotoneStyle(const DNameNode *const pe))(DNameNode *this)
{
  DNameNode_vtbl *v1; // eax

  v1 = pe[1].__vftable;
  if ( v1 != nullptr )
    return v1[1].getLastChar;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1018B3B0
// Name: private: static bool GTessellator::monoChainLess(struct GTessellator::MonoChainType const __near *,struct GTessellator::MonoChainType const __near *)
// Source: json
//------------------------------------------------------------------------------
static BOOL __cdecl GTessellator::monoChainLess(const pDNameNode *const a, const pDNameNode *const b)
{
  return *(float *)&b->me > (double)*(float *)&a->me;
}

//------------------------------------------------------------------------------
// Address: 0x1018B3E0
// Name: private: static bool GTessellator::styleLess(struct GTessellator::MonotoneType const __near &,struct GTessellator::MonotoneType const __near &)
// Source: json
//------------------------------------------------------------------------------
pDNameNode *__cdecl GTessellator::styleLess(pDNameNode *result, int a2)
{
  return (pDNameNode *)(result[2].__vftable < (pDNameNode_vtbl *)*(_DWORD *)(a2 + 16));
}

//------------------------------------------------------------------------------
// Address: 0x1018B400
// Name: private: static bool GTessellator::intersectionLess(struct GTessellator::IntersectionType const __near &,struct GTessellator::IntersectionType const __near &)
// Source: json
//------------------------------------------------------------------------------
static BOOL __cdecl GTessellator::intersectionLess(
        const struct GTessellator::IntersectionType *a1,
        const struct GTessellator::IntersectionType *a2)
{
  return *((float *)a2 + 2) > (double)*((float *)a1 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1018B430
// Name: private: static float GTessellator::distanceSquare(struct GPointType const __near &,struct GPointType const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GTessellator::distanceSquare(const _s_RTTIClassHierarchyDescriptor *result, float *dy)
{
  float v4; // [esp+8h] [ebp+8h]
  float dya; // [esp+Ch] [ebp+Ch]

  v4 = *dy - *(float *)&result->signature;
  dya = dy[1] - *(float *)&result->attributes;
  return (float)(dya * dya + v4 * v4);
}

//------------------------------------------------------------------------------
// Address: 0x1018B460
// Name: private: bool GTessellator::forwardMin(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GTessellator::forwardMin(GTessellator *this, int y, int start)
{
  int v3; // edx
  float ya; // [esp+Ch] [ebp+8h]

  v3 = (int)*(this + 15);
  ya = *(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)y >> 10)) + 8 * (y & 0x3FF) + 4);
  if ( y > start )
  {
    if ( ya <= (double)*(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)(y - 1) >> 10)) + 8 * ((y - 1) & 0x3FF) + 4)
      && *(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)(y + 1) >> 10)) + 8 * (((_WORD)y + 1) & 0x3FF) + 4) > (double)ya )
    {
      return 1;
    }
  }
  else if ( ya < (double)*(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)(y + 1) >> 10))
                                  + 8 * (((_WORD)y + 1) & 0x3FF)
                                  + 4) )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B510
// Name: private: bool GTessellator::reverseMin(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GTessellator::reverseMin(GTessellator *this, int y, int end)
{
  int v3; // edx
  unsigned int v5; // eax
  float ya; // [esp+Ch] [ebp+8h]

  v3 = (int)*(this + 15);
  v5 = y - 1;
  ya = *(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)y >> 10)) + 8 * (y & 0x3FF) + 4);
  if ( y < end )
  {
    if ( ya < (double)*(float *)(*(_DWORD *)(v3 + 4 * (v5 >> 10)) + 8 * (v5 & 0x3FF) + 4)
      && *(float *)(*(_DWORD *)(v3 + 4 * ((unsigned int)(y + 1) >> 10)) + 8 * (((_WORD)y + 1) & 0x3FF) + 4) >= (double)ya )
    {
      return 1;
    }
  }
  else if ( ya < (double)*(float *)(*(_DWORD *)(v3 + 4 * (v5 >> 10)) + 8 * (v5 & 0x3FF) + 4) )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B5B0
// Name: private: int GTessellator::findElderStyle(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GTessellator::findElderStyle(unsigned int *this)
{
  unsigned int v1; // eax
  unsigned int v2; // edx
  _DWORD *i; // ecx

  v1 = *(this + 55);
  v2 = *(this + 54);
  if ( v1 < v2 )
    return 0;
  for ( i = (_DWORD *)(*(this + 51) + 4 * v1); *i == 0; --i )
  {
    if ( --v1 < v2 )
      return 0;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1018B5E0
// Name: private: void GTessellator::perceiveStyles(class GArrayUnsafeLH_POD<struct GTessellator::MonoChainType __near *,133> const __near &)
// Source: json
//------------------------------------------------------------------------------
_HeapManager::Block *__thiscall GTessellator::perceiveStyles(int this, _HeapManager::Block *result)
{
  unsigned int v3; // ebx
  unsigned int i; // eax
  _HeapManager::Block *v5; // eax
  _DWORD *v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  unsigned int ElderStyle; // eax
  unsigned int leftAbove; // [esp+8h] [ebp-4h]

  v3 = 0;
  **(_DWORD **)(this + 204) = 0;
  for ( i = *(_DWORD *)(this + 216); i <= *(_DWORD *)(this + 220); ++i )
    *(_DWORD *)(*(_DWORD *)(this + 204) + 4 * i) = 0;
  v5 = result;
  leftAbove = 0;
  if ( *(_DWORD *)result->memBlock != 0 )
  {
    do
    {
      v6 = *((_DWORD **)&v5->next->next + v3);
      v6[11] &= ~4u;
      if ( (v6[11] & 2) == 0 )
      {
        v7 = v6[6];
        v8 = (_DWORD *)(*(_DWORD *)(this + 204) + 4 * v6[5]);
        if ( *(_DWORD *)this != 0 )
        {
          *v8 ^= 1u;
          *(_DWORD *)(*(_DWORD *)(this + 204) + 4 * v7) ^= 1u;
        }
        else
        {
          *v8 += v6[4];
          *(_DWORD *)(*(_DWORD *)(this + 204) + 4 * v7) -= v6[4];
        }
        ElderStyle = GTessellator::findElderStyle((unsigned int *)this);
        v6[10] = ElderStyle;
        v6[8] = leftAbove;
        if ( leftAbove != ElderStyle )
          v6[11] |= 4u;
        leftAbove = ElderStyle;
        v5 = result;
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)v5->memBlock );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1018B6A0
// Name: private: void GTessellator::swapChains(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::swapChains(GTessellator *this, unsigned int startIn, unsigned int endIn)
{
  unsigned int i; // edx
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // esi
  int *v9; // edi
  int v10; // esi
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  _DWORD *v14; // edi
  int *v15; // eax
  int v16; // esi
  int *startIna; // [esp+8h] [ebp+8h]

  for ( i = startIn; i < endIn; *v14 = v16 )
  {
    v4 = *(&(*(this + 50))->attributes + (i >> 6));
    v5 = (int)*(this + 38);
    v6 = *(_DWORD *)(v4 + 12 * (i & 0x3F) + 4);
    v7 = (_DWORD *)(v4 + 12 * (i & 0x3F));
    v8 = (int)*(this + 44);
    startIna = (int *)(v5 + 4 * *(_DWORD *)(v8 + 4 * v6));
    v9 = (int *)(v5 + 4 * *(_DWORD *)(v8 + 4 * *v7));
    v10 = *v9;
    *v9 = *startIna;
    *startIna = v10;
    v11 = (int)*(this + 44);
    v12 = v7[1];
    v13 = *(_DWORD *)(v11 + 4 * v12);
    v14 = (_DWORD *)(v11 + 4 * v12);
    v15 = (int *)(v11 + 4 * *v7);
    v16 = *v15;
    ++i;
    *v15 = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B720
// Name: private: bool GTessellator::shapeCoherent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GTessellator::shapeCoherent(GTessellator *this, unsigned int v)
{
  int v2; // esi
  float *v3; // edi
  unsigned int v4; // eax
  int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // eax
  double v10; // st7
  char v11; // fps^1
  bool v12; // c0
  char v13; // c2
  bool v14; // c3
  char v15; // fps^1
  int v17; // edx
  bool v18; // c0
  char v19; // c2
  bool v20; // c3
  char v21; // ah
  double v22; // st7
  int v23; // eax
  unsigned int v24; // eax
  int v25; // edx
  unsigned int v26; // ebx
  unsigned int v27; // eax
  int v28; // edx
  int v29; // eax
  double v30; // st7
  char v31; // fps^1
  bool v32; // c0
  char v33; // c2
  bool v34; // c3
  char v35; // fps^1
  bool v36; // c0
  char v37; // c2
  bool v38; // c3
  int v39; // eax
  int v40; // edx
  int v41; // eax
  int v42; // edx
  int v43; // ecx
  unsigned int v44; // ebx
  float *v45; // ebx
  float *v46; // eax
  int v47; // edx
  int v48; // ecx
  unsigned int v49; // ebx
  float *v50; // ebx
  float *v51; // eax
  int v52; // edx
  int v53; // ecx
  unsigned int v54; // ebx
  float *v55; // ebx
  unsigned int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // edx
  int v60; // ecx
  unsigned int v61; // ebx
  float *v62; // ebx
  unsigned int v63; // eax
  int v64; // ecx
  int v65; // eax
  float *cp; // [esp+10h] [ebp-18h]
  float cpa; // [esp+10h] [ebp-18h]
  float *cpb; // [esp+10h] [ebp-18h]
  float cpc; // [esp+10h] [ebp-18h]
  float cpd; // [esp+10h] [ebp-18h]
  float cpe; // [esp+10h] [ebp-18h]
  float cpf; // [esp+10h] [ebp-18h]
  float cpg; // [esp+10h] [ebp-18h]
  _DWORD v74[4]; // [esp+14h] [ebp-14h]

  v2 = (int)*(this + 68);
  v3 = (float *)(*(_DWORD *)(v2 + 4 * ((v & 0xBFFFFFFF) >> 10)) + 8 * (v & 0x3FF));
  if ( (v & 0x40000000) != 0 )
  {
    v4 = (unsigned int)*(this + 101);
    if ( v4 < 2 )
      return true;
    v5 = (int)*(this + 104);
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * ((v4 - 2) >> 8)) + 4 * (unsigned __int8)(v4 - 2));
    cp = (float *)(*(_DWORD *)(v2 + 4 * (v6 >> 10)) + 8 * (v6 & 0x3FF));
    v7 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * (((unsigned int)&(*(this + 101))[-1].pCatchableTypeArray + 3) >> 8))
                   + 4 * (unsigned __int8)(*((_BYTE *)this + 404) - 1));
    v8 = *(_DWORD *)(v2 + 4 * (v7 >> 10));
    v9 = v7 & 0x3FF;
    cpa = (*(float *)(v8 + 8 * v9 + 4) - cp[1]) * (*v3 - *(float *)(v8 + 8 * v9))
        - (v3[1] - *(float *)(v8 + 8 * v9 + 4)) * (*(float *)(v8 + 8 * v9) - *cp);
    v10 = cpa;
    v12 = cpa > 0.0;
    v13 = 0;
    v14 = 0.0 == cpa;
    BYTE1(v9) = v11;
    if ( !__SETP__(BYTE1(v9) & 0x44, 0) )
      return true;
    v17 = (int)*(this + 115);
    v18 = v10 > 0.0;
    v19 = 0;
    v20 = 0.0 == v10;
    v21 = v15;
    v22 = 0.0;
    if ( v17 == 0 )
    {
      v23 = 3;
      if ( v18 || v20 )
        v23 = 4;
      *(this + 115) = (GTessellator)v23;
      goto LABEL_17;
    }
  }
  else
  {
    v24 = (unsigned int)*(this + 105);
    if ( v24 < 2 )
      return true;
    v25 = (int)*(this + 108);
    v26 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * ((v24 - 2) >> 8)) + 4 * (unsigned __int8)(v24 - 2));
    cpb = (float *)(*(_DWORD *)(v2 + 4 * (v26 >> 10)) + 8 * (v26 & 0x3FF));
    v27 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * (((unsigned int)&(*(this + 105))[-1].pCatchableTypeArray + 3) >> 8))
                    + 4 * (unsigned __int8)(*((_BYTE *)this + 420) - 1));
    v28 = *(_DWORD *)(v2 + 4 * (v27 >> 10));
    v29 = v27 & 0x3FF;
    cpc = (*(float *)(v28 + 8 * v29 + 4) - cpb[1]) * (*v3 - *(float *)(v28 + 8 * v29))
        - (v3[1] - *(float *)(v28 + 8 * v29 + 4)) * (*(float *)(v28 + 8 * v29) - *cpb);
    v30 = cpc;
    v32 = cpc > 0.0;
    v33 = 0;
    v34 = 0.0 == cpc;
    BYTE1(v29) = v31;
    if ( !__SETP__(BYTE1(v29) & 0x44, 0) )
      return true;
    v17 = (int)*(this + 116);
    v36 = v30 > 0.0;
    v37 = 0;
    v38 = 0.0 == v30;
    v21 = v35;
    v22 = 0.0;
    if ( v17 == 0 )
    {
      v39 = 3;
      if ( v36 || v38 )
        v39 = 4;
      *(this + 116) = (GTessellator)v39;
      goto LABEL_17;
    }
  }
  if ( (v17 == 3) != ((v21 & 0x41) == 0) )
    return false;
LABEL_17:
  if ( *(this + 114) == nullptr )
  {
    v40 = (int)*(this + 115);
    if ( v40 != 0 )
    {
      v41 = (int)*(this + 116);
      if ( v41 != 0 )
      {
        v74[0] = 3;
        v74[1] = 1;
        v74[2] = 2;
        v74[3] = 4;
        *(this + 114) = (GTessellator)v74[(v41 == 4) | (2 * (v40 == 4))];
      }
    }
  }
  if ( *(this + 114) == (GTessellator)2 )
  {
    if ( (v & 0x40000000) != 0 )
    {
      v52 = (int)*(this + 105);
      v53 = (int)*(this + 108);
      v54 = *(_DWORD *)(*(_DWORD *)(v53 + 4 * ((unsigned int)(v52 - 2) >> 8)) + 4 * (unsigned __int8)(v52 - 2));
      v55 = (float *)(*(_DWORD *)(v2 + 4 * (v54 >> 10)) + 8 * (v54 & 0x3FF));
      v56 = *(_DWORD *)(*(_DWORD *)(v53 + 4 * ((unsigned int)(v52 - 1) >> 8)) + 4 * (unsigned __int8)(v52 - 1));
      v57 = *(_DWORD *)(v2 + 4 * (v56 >> 10));
      v58 = v56 & 0x3FF;
      cpf = (*(float *)(v57 + 8 * v58 + 4) - v55[1]) * (*v3 - *(float *)(v57 + 8 * v58))
          - (v3[1] - *(float *)(v57 + 8 * v58 + 4)) * (*(float *)(v57 + 8 * v58) - *v55);
      return v22 >= cpf;
    }
    else
    {
      v59 = (int)*(this + 101);
      v60 = (int)*(this + 104);
      v61 = *(_DWORD *)(*(_DWORD *)(v60 + 4 * ((unsigned int)(v59 - 2) >> 8)) + 4 * (unsigned __int8)(v59 - 2));
      v62 = (float *)(*(_DWORD *)(v2 + 4 * (v61 >> 10)) + 8 * (v61 & 0x3FF));
      v63 = *(_DWORD *)(*(_DWORD *)(v60 + 4 * ((unsigned int)(v59 - 1) >> 8)) + 4 * (unsigned __int8)(v59 - 1));
      v64 = *(_DWORD *)(v2 + 4 * (v63 >> 10));
      v65 = v63 & 0x3FF;
      cpg = (*(float *)(v64 + 8 * v65 + 4) - v62[1]) * (*v3 - *(float *)(v64 + 8 * v65))
          - (v3[1] - *(float *)(v64 + 8 * v65 + 4)) * (*(float *)(v64 + 8 * v65) - *v62);
      return v22 <= cpg;
    }
  }
  else
  {
    if ( *(this + 114) != (GTessellator)3 )
    {
      if ( *(this + 114) == (GTessellator)4 )
      {
        v42 = (int)*(this + 101);
        v43 = (int)*(this + 104);
        v44 = *(_DWORD *)(*(_DWORD *)(v43 + 4 * ((unsigned int)(v42 - 2) >> 8)) + 4 * (unsigned __int8)(v42 - 2));
        v45 = (float *)(*(_DWORD *)(v2 + 4 * (v44 >> 10)) + 8 * (v44 & 0x3FF));
        if ( (v & 0x40000000) == 0 )
        {
          v46 = (float *)(*(_DWORD *)(v2
                                    + 4
                                    * (*(_DWORD *)(*(_DWORD *)(v43 + 4 * ((unsigned int)(v42 - 1) >> 8))
                                                 + 4 * (unsigned __int8)(v42 - 1)) >> 10))
                        + 8
                        * (*(_DWORD *)(*(_DWORD *)(v43 + 4 * ((unsigned int)(v42 - 1) >> 8))
                                     + 4 * (unsigned __int8)(v42 - 1))
                         & 0x3FF));
          cpd = (v46[1] - v45[1]) * (*v3 - *v46) - (v3[1] - v46[1]) * (*v46 - *v45);
          if ( v22 > cpd )
            return false;
        }
      }
      return true;
    }
    v47 = (int)*(this + 105);
    v48 = (int)*(this + 108);
    v49 = *(_DWORD *)(*(_DWORD *)(v48 + 4 * ((unsigned int)(v47 - 2) >> 8)) + 4 * (unsigned __int8)(v47 - 2));
    v50 = (float *)(*(_DWORD *)(v2 + 4 * (v49 >> 10)) + 8 * (v49 & 0x3FF));
    if ( (v & 0x40000000) == 0 )
      return true;
    v51 = (float *)(*(_DWORD *)(v2
                              + 4
                              * (*(_DWORD *)(*(_DWORD *)(v48 + 4 * ((unsigned int)(v47 - 1) >> 8))
                                           + 4 * (unsigned __int8)(v47 - 1)) >> 10))
                  + 8
                  * (*(_DWORD *)(*(_DWORD *)(v48 + 4 * ((unsigned int)(v47 - 1) >> 8)) + 4 * (unsigned __int8)(v47 - 1))
                   & 0x3FF));
    cpe = (v51[1] - v50[1]) * (*v3 - *v51) - (v3[1] - v51[1]) * (*v51 - *v50);
    return v22 >= cpe;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BC10
// Name: private: void GTessellator::findMaxDiameter(unsigned int __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::findMaxDiameter(GTessellator *this, unsigned int *a2, unsigned int *a3)
{
  unsigned int v3; // ebx
  unsigned int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // edi
  float *v7; // eax
  double v8; // st7
  unsigned int v9; // eax
  double v10; // st6
  unsigned int v11; // edi
  int v12; // eax
  unsigned int v13; // edx
  int v14; // esi
  float *v15; // edi
  float *v16; // edx
  unsigned int v17; // eax
  float *v18; // eax
  int v19; // ecx
  double v20; // st7
  int v21; // ecx
  float v22; // [esp+Ch] [ebp-34h]
  float v23; // [esp+10h] [ebp-30h]
  float v24; // [esp+14h] [ebp-2Ch]
  float v25; // [esp+18h] [ebp-28h]
  float v26; // [esp+18h] [ebp-28h]
  float v27; // [esp+18h] [ebp-28h]
  GTessellator *v28; // [esp+1Ch] [ebp-24h]
  unsigned int v29; // [esp+20h] [ebp-20h]
  float *v30; // [esp+24h] [ebp-1Ch]
  float v31; // [esp+24h] [ebp-1Ch]
  float v32; // [esp+24h] [ebp-1Ch]
  float v33; // [esp+28h] [ebp-18h]
  int v34; // [esp+28h] [ebp-18h]
  unsigned int v35; // [esp+2Ch] [ebp-14h]
  unsigned int v36; // [esp+30h] [ebp-10h]
  unsigned int v37; // [esp+34h] [ebp-Ch]
  unsigned int v38; // [esp+38h] [ebp-8h]
  float *v39; // [esp+3Ch] [ebp-4h]
  float v40; // [esp+3Ch] [ebp-4h]
  float v41; // [esp+3Ch] [ebp-4h]
  float v42; // [esp+3Ch] [ebp-4h]

  v28 = this;
  v3 = *a3;
  v29 = (unsigned int)*(this + 109);
  v4 = *a2;
  v5 = *(_DWORD *)(*(&(*(this + 112))->attributes + (*a2 >> 8)) + 4 * (unsigned __int8)*a2);
  v6 = *(_DWORD *)(*(&(*(this + 112))->attributes + (*a3 >> 8)) + 4 * (unsigned __int8)*a3);
  v30 = (float *)(*(&(*(this + 68))->attributes + (v6 >> 10)) + 8 * (v6 & 0x3FF));
  v7 = (float *)(*(&(*(this + 68))->attributes + (v5 >> 10)) + 8 * (v5 & 0x3FF));
  v35 = *a2;
  v36 = *a3;
  v33 = *v30 - *v7;
  v8 = v30[1] - v7[1];
  v9 = v29;
  v31 = v8;
  v10 = v33;
  v34 = 0;
  v32 = v31 * v31 + v10 * v10;
  if ( v29 != 0 )
  {
    while ( 1 )
    {
      v11 = v3 + 1;
      v37 = v4 + 1;
      v38 = v3 + 1;
      if ( v4 + 1 >= v9 )
        v37 = v4 + 1 - v9;
      if ( v11 >= v9 )
        v38 = v11 - v9;
      v12 = (int)*(this + 112);
      v13 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * (v4 >> 8)) + 4 * (unsigned __int8)v4);
      v14 = (int)*(this + 68);
      v15 = (float *)(*(_DWORD *)(v14 + 4 * (v13 >> 10)) + 8 * (v13 & 0x3FF));
      v39 = (float *)(*(_DWORD *)(v14
                                + 4 * (*(_DWORD *)(*(_DWORD *)(v12 + 4 * (v3 >> 8)) + 4 * (unsigned __int8)v3) >> 10))
                    + 8 * (*(_DWORD *)(*(_DWORD *)(v12 + 4 * (v3 >> 8)) + 4 * (unsigned __int8)v3) & 0x3FF));
      v16 = (float *)(*(_DWORD *)(v14
                                + 4 * (*(_DWORD *)(*(_DWORD *)(v12 + 4 * (v37 >> 8)) + 4 * (unsigned __int8)v37) >> 10))
                    + 8 * (*(_DWORD *)(*(_DWORD *)(v12 + 4 * (v37 >> 8)) + 4 * (unsigned __int8)v37) & 0x3FF));
      v17 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * (v38 >> 8)) + 4 * (unsigned __int8)v38);
      v18 = (float *)(*(_DWORD *)(v14 + 4 * (v17 >> 10)) + 8 * (v17 & 0x3FF));
      v23 = *v39 - *v16;
      v24 = v39[1] - v16[1];
      v25 = *v18 - *v15;
      v40 = v18[1] - v15[1];
      v22 = v40 * v40 + v25 * v25;
      v41 = *v18 - *v16;
      v26 = v18[1] - v16[1];
      v27 = v26 * v26 + v41 * v41;
      v19 = 0;
      v42 = v24 * v24 + v23 * v23;
      if ( v42 >= (double)v22 )
      {
        v20 = v42;
      }
      else
      {
        v19 = 1;
        v20 = v22;
      }
      if ( v27 > v20 )
      {
        v19 = 2;
        v20 = v27;
      }
      if ( v19 != 0 )
      {
        v21 = v19 - 1;
        if ( v21 != 0 )
        {
          if ( v21 == 1 )
          {
            v4 = v37;
            v3 = v38;
            ++v34;
            v35 = v37;
            v36 = v38;
            goto LABEL_21;
          }
          v3 = v36;
        }
        else
        {
          v3 = v38;
          v36 = v38;
        }
        v4 = v35;
      }
      else
      {
        v4 = v37;
        v3 = v36;
        v35 = v37;
      }
LABEL_21:
      if ( v32 < v20 )
      {
        v32 = v20;
        *a2 = v4;
        *a3 = v3;
      }
      v9 = v29;
      if ( ++v34 >= v29 )
        return;
      this = v28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C520
// Name: public: bool GTessBaseLineIterator<class GArrayPagedLH_POD<struct GTessellator::PendingEndType,4,16,133>>::Next<int (*)(struct GTessellator::PendingEndType const __near *)>(int (*)(struct GTessellator::PendingEndType const __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall GTessBaseLineIterator<GArrayPagedLH_POD<GTessellator::PendingEndType,4,16,133>>::Next<int (__cdecl *)(GTessellator::PendingEndType const *)>(
        _DWORD *this,
        int (__cdecl *a2)(int))
{
  int v3; // edx
  unsigned int v4; // eax
  int v5; // edi
  int v6; // edx
  int v7; // ecx
  int v9; // [esp-4h] [ebp-8h]

  v3 = *(this + 2);
  *((_BYTE *)this + 32) = 0;
  if ( v3 == 0 )
    return 0;
  *(this + 5) = *(this + 6);
  v4 = *(this + 1);
  v5 = *this;
  v6 = v3 - 1;
  *(this + 2) = v6;
  *(this + 1) = v4 + 1;
  *(this + 4) = *(_DWORD *)(*(_DWORD *)(v5 + 12) + 4 * (v4 >> 4)) + 8 * (v4 & 0xF);
  if ( v6 != 0 )
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*this + 12) + 4 * ((v4 + 1) >> 4)) + 8 * ((v4 + 1) & 0xF));
  else
    v7 = *(this + 3);
  v9 = *(this + 4);
  *(this + 6) = v7;
  *(this + 7) = a2(a1: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018C5A0
// Name: void G_InsertionSortSliced<class GArrayPagedLH_POD<struct GTessellator::IntersectionType,6,64,133>,bool (*)(struct GTessellator::IntersectionType const __near &,struct GTessellator::IntersectionType const __near &)>(class GArrayPagedLH_POD<struct GTessellator::IntersectionType,6,64,133> __near &,unsigned int,unsigned int,bool (*)(struct GTessellator::IntersectionType const __near &,struct GTessellator::IntersectionType const __near &))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_InsertionSortSliced<GArrayPagedLH_POD<GTessellator::IntersectionType,6,64,133>,bool (__cdecl *)(GTessellator::IntersectionType const &,GTessellator::IntersectionType const &)>(
        int a1,
        int a2,
        int a3,
        unsigned __int8 (__cdecl *a4)(int, int))
{
  int result; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // esi
  int v15; // ebx
  unsigned int v16; // eax
  int v17; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  result = a2;
  v17 = a2 + 1;
  if ( a2 + 1 < a3 )
  {
    while ( 1 )
    {
      v5 = 4 * ((unsigned int)result >> 6);
      v6 = 12 * (result & 0x3F);
      v7 = 4 * ((unsigned int)(result + 1) >> 6);
      for ( i = 12 * ((result + 1) & 0x3F);
            a4(a1: i + *(_DWORD *)(v7 + *(_DWORD *)(a1 + 12)), a2: v6 + *(_DWORD *)(*(_DWORD *)(a1 + 12) + v5)) != 0;
            i = 12 * (v16 & 0x3F) )
      {
        v8 = *(_DWORD *)(a1 + 12);
        v9 = *(_DWORD *)(v8 + v5);
        v10 = (int *)(i + *(_DWORD *)(v7 + v8));
        v11 = *(_DWORD *)(v9 + v6);
        v12 = *v10;
        v13 = v10[1];
        v14 = (_DWORD *)(v6 + v9);
        v15 = v10[2];
        *v10 = v11;
        v10[1] = v14[1];
        v10[2] = v14[2];
        *v14 = v12;
        v16 = a2;
        v14[1] = v13;
        v14[2] = v15;
        if ( a2 <= 0 )
          break;
        --a2;
        v5 = 4 * ((v16 - 1) >> 6);
        v6 = 12 * (((_BYTE)v16 - 1) & 0x3F);
        v7 = 4 * (v16 >> 6);
      }
      a2 = v17;
      result = v17 + 1;
      v17 = result;
      if ( result >= a3 )
        break;
      result = a2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018D3E0
// Name: private: void GTessellator::removeLastMonoVertex(struct GTessellator::MonotoneType __near *)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge GTessellator::removeLastMonoVertex@<eax>(DNameStatusNode *this@<ecx>, char *m, char *a3)
{
  char *result; // eax
  int v4; // edx
  int v5; // edx
  unsigned int v6; // edx

  result = m;
  v4 = *((_DWORD *)m + 1);
  if ( v4 != -1 )
  {
    if ( v4 == *((_DWORD *)this + 89) - 1 )
    {
      v5 = *((_DWORD *)this + 89);
      if ( v5 != 0 )
        *((_DWORD *)this + 89) = v5 - 1;
    }
    *((_DWORD *)m + 1) = *((_DWORD *)m + 2);
    *((_DWORD *)m + 2) = *((_DWORD *)m + 3);
    v6 = *((_DWORD *)m + 1);
    *((_DWORD *)m + 3) = -1;
    if ( v6 == -1 )
    {
      *(_DWORD *)m = 0;
    }
    else
    {
      result = *(char **)(*((_DWORD *)this + 92) + 4 * (v6 >> 10));
      *(_DWORD *)&result[8 * (v6 & 0x3FF) + 4] = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018D460
// Name: public: unsigned int GTessellator::GetNumBytes(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GTessellator::GetNumBytes(UnDecorator *this)
{
  int v1; // esi
  char *v2; // edx

  v1 = *((_DWORD *)this + 78);
  v2 = (char *)&this->ZNameList.dNameBuffer[6][112 * *((_DWORD *)this + 25)
                                             + 48 * *((_DWORD *)this + 86)
                                             + 32
                                             * ((int)this->ZNameList.dNameBuffer[5]
                                              + 12 * *((_DWORD *)this + 98)
                                              + 8
                                              * ((int)this->ZNameList.dNameBuffer[1]
                                               + 2 * (int)this->ZNameList.dNameBuffer[9]
                                               + *((_DWORD *)this + 66)
                                               + *((_DWORD *)this + 90))
                                              + 4 * *((_DWORD *)this + 32)
                                              + *((_DWORD *)this + 94)
                                              + *((_DWORD *)this + 102)
                                              + *((_DWORD *)this + 106)
                                              + *((_DWORD *)this + 110))
                                             + 24 * *((_DWORD *)this + 48)
                                             + 14 * v1
                                             + 4 * *((_DWORD *)this + 82)]
     + 3 * *((_DWORD *)this + 73)
     + 3 * *((_DWORD *)this + 76)
     + *((_DWORD *)this + 22)
     + *((_DWORD *)this + 30)
     + *((_DWORD *)this + 26)
     + *((_DWORD *)this + 33)
     + *((_DWORD *)this + 37)
     + *((_DWORD *)this + 40)
     + *((_DWORD *)this + 49)
     + *((_DWORD *)this + 43)
     + *((_DWORD *)this + 46)
     + *((_DWORD *)this + 53)
     + *((_DWORD *)this + 67)
     + *((_DWORD *)this + 64)
     + *((_DWORD *)this + 79)
     + *((_DWORD *)this + 83)
     + *((_DWORD *)this + 87)
     + *((_DWORD *)this + 91)
     + *((_DWORD *)this + 95)
     + *((_DWORD *)this + 99)
     + *((_DWORD *)this + 103)
     + *((_DWORD *)this + 107)
     + *((_DWORD *)this + 111);
  return (char *)(this->ZNameList.index
                + 4
                * ((_DWORD)this->ArgList.dNameBuffer[4]
                 + (unsigned int)this->ZNameList.dNameBuffer[2]
                 + (unsigned int)this->ArgList.dNameBuffer[7]
                 + (unsigned int)v2));
}

//------------------------------------------------------------------------------
// Address: 0x1018D580
// Name: public: void GTessellator::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::Clear(GTessellator *this)
{
  *((float *)this + 56) = 1.0e30;
  *(this + 12) = nullptr;
  *((float *)this + 57) = 1.0e30;
  *(this + 16) = nullptr;
  *(this + 20) = nullptr;
  *((float *)this + 58) = -1.0e30;
  *(this + 24) = nullptr;
  *((float *)this + 59) = -1.0e30;
  *(this + 29) = nullptr;
  *(this + 31) = nullptr;
  *(this + 65) = nullptr;
  *(this + 85) = nullptr;
  *(this + 89) = nullptr;
  *(this + 93) = nullptr;
  *(this + 97) = nullptr;
  *(this + 54) = nullptr;
  *(this + 55) = nullptr;
  *((_BYTE *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018D5F0
// Name: private: void GTessellator::optimizeDirection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::optimizeDirection(GTessellator *this)
{
  double v2; // st7
  void **v3; // ebx
  void **v4; // edi
  float v5; // ecx
  double v6; // st7
  double v7; // st7
  double v8; // st6
  _DWORD *v9; // eax
  int v10; // edi
  unsigned int v11; // ecx
  int v12; // eax
  float *v13; // ebx
  float *v14; // edx
  double v15; // st4
  unsigned int v16; // ecx
  double v17; // st4
  double v18; // st4
  unsigned int v19; // eax
  bool v20; // cf
  unsigned int v21; // edx
  double v22; // st4
  unsigned int v23; // edx
  double v24; // st4
  double v25; // st4
  unsigned int v26; // ecx
  unsigned int v27; // eax
  unsigned int j; // eax
  int v29; // edi
  int v30; // ebx
  _DWORD *v31; // ecx
  int v32; // edx
  int v33; // edi
  _DWORD *v34; // eax
  unsigned int v35; // ecx
  float *v36; // eax
  double v37; // st7
  int v38; // [esp+8h] [ebp-24h]
  int v39; // [esp+10h] [ebp-1Ch] BYREF
  float v40; // [esp+14h] [ebp-18h]
  float v41; // [esp+18h] [ebp-14h]
  _DWORD *v42; // [esp+1Ch] [ebp-10h]
  int v43; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  float v45; // [esp+28h] [ebp-4h]

  v2 = *((float *)this + 58);
  *((_BYTE *)this + 8) = 0;
  v40 = v2 - *((float *)this + 56);
  v41 = *((float *)this + 59) - *((float *)this + 57);
  if ( v40 > 0.0 && v41 > 0.0 && (unsigned int)*(this + 12) > 0x40 )
  {
    v3 = (void **)(this + 6);
    if ( (unsigned int)*(this + 8) < 0x42 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
      *(this + 8) = (GTessellator)66;
      v39 = 133;
      *v3 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this + 6, a3: 264, a4: &v39);
    }
    *(this + 7) = (GTessellator)66;
    v4 = (void **)(this + 3);
    if ( (unsigned int)*(this + 5) < 0x42 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
      *(this + 5) = (GTessellator)66;
      v39 = 133;
      *v4 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this + 3, a3: 264, a4: &v39);
    }
    *(this + 4) = (GTessellator)66;
    memset(dst: (unsigned __int8 *)*v3, value: 0, count: 4 * (_DWORD)*(this + 7));
    memset(dst: (unsigned __int8 *)*v4, value: 0, count: 4 * (_DWORD)*(this + 4));
    v5 = 0.0;
    v6 = 64.0 / v40;
    v40 = 0.0;
    *(float *)&v39 = v6;
    v41 = 64.0 / v41;
    if ( *(this + 16) != nullptr )
    {
      v7 = *(float *)&v39;
      v8 = v41;
      do
      {
        v9 = (_DWORD *)(*(&(*(this + 19))->attributes + (LODWORD(v5) >> 6)) + 16 * (LOBYTE(v5) & 0x3F));
        v10 = *v9 + 1;
        v42 = v9;
        if ( v10 <= v9[1] )
        {
          v11 = v10 - 1;
          for ( i = v10 - 1; ; v11 = i )
          {
            v12 = (int)*(this + 15);
            v13 = (float *)(*(_DWORD *)(v12 + 4 * (v11 >> 10)) + 8 * (v11 & 0x3FF));
            v14 = (float *)(*(_DWORD *)(v12 + 4 * ((unsigned int)v10 >> 10)) + 8 * (v10 & 0x3FF));
            *(float *)&v39 = (*v13 - *((float *)this + 56)) * v7;
            v15 = *(float *)&v39 + 0.5;
            v39 = HIWORD(v45) | 0xC00;
            v41 = *(float *)&v14;
            v16 = (__int64)v15;
            *(float *)&v39 = (*v14 - *((float *)this + 56)) * v7;
            v17 = *(float *)&v39;
            v39 = HIWORD(v45) | 0xC00;
            v18 = v17 + 0.5;
            v19 = (__int64)v18;
            v20 = v16 < v19;
            if ( v16 > v19 )
            {
              v21 = v16;
              v16 = (__int64)v18;
              v19 = v21;
              v20 = v16 < v21;
            }
            if ( v20 )
            {
              do
                ++*(&(*(this + 3))->attributes + v16++);
              while ( v16 < v19 );
            }
            *(float *)&v39 = (v13[1] - *((float *)this + 57)) * v8;
            v22 = *(float *)&v39;
            v39 = HIWORD(v45) | 0xC00;
            v23 = (__int64)(v22 + 0.5);
            *(float *)&v39 = (*(float *)(LODWORD(v41) + 4) - *((float *)this + 57)) * v8;
            v24 = *(float *)&v39;
            v39 = HIWORD(v45) | 0xC00;
            v25 = v24 + 0.5;
            v26 = (__int64)v25;
            if ( v23 > v26 )
            {
              v27 = v23;
              v23 = (__int64)v25;
              v26 = v27;
            }
            for ( j = v23; j < v26; ++j )
              ++*(&(*(this + 6))->attributes + j);
            ++i;
            if ( ++v10 > v42[1] )
              break;
          }
          v5 = v40;
        }
        ++LODWORD(v5);
        v40 = v5;
      }
      while ( LODWORD(v5) < (unsigned int)*(this + 16) );
    }
    v29 = (int)*(this + 3);
    v40 = 0.0;
    v41 = 0.0;
    v42 = nullptr;
    v43 = 0;
    v45 = 0.0;
    i = 0;
    v30 = (int)*(this + 6);
    v31 = (_DWORD *)(v29 + 12);
    v32 = 0;
    v38 = v29 - v30;
    v33 = 0;
    v34 = (_DWORD *)(v30 + 4);
    v39 = 16;
    do
    {
      LODWORD(v40) += *(v31 - 3);
      v33 += *(_DWORD *)((char *)v34 + v38);
      i += *v34;
      v42 = (_DWORD *)((char *)v42 + *(v31 - 1));
      LODWORD(v45) += v34[1];
      LODWORD(v41) += *v31;
      v32 += *(v34 - 1);
      v43 += v34[2];
      v34 += 4;
      v31 += 4;
      --v39;
    }
    while ( *(float *)&v39 != 0.0 );
    if ( (unsigned int)v42 + v33 + LODWORD(v41) + LODWORD(v40) < v43 + LODWORD(v45) + i + v32 )
    {
      v35 = 0;
      if ( *(this + 12) != nullptr )
      {
        do
        {
          v36 = (float *)(*(&(*(this + 15))->attributes + (v35 >> 10)) + 8 * (v35 & 0x3FF));
          v45 = *v36;
          ++v35;
          *v36 = -v36[1];
          v36[1] = v45;
        }
        while ( v35 < (unsigned int)*(this + 12) );
      }
      v37 = *((float *)this + 56);
      *((_BYTE *)this + 8) = 1;
      v45 = v37;
      *((float *)this + 56) = -*((float *)this + 57);
      *((float *)this + 57) = v45;
      v45 = *((float *)this + 58);
      *((float *)this + 58) = -*((float *)this + 59);
      *((float *)this + 59) = v45;
      v45 = *((float *)this + 56);
      *(this + 56) = *(this + 58);
      *((float *)this + 58) = v45;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D9D0
// Name: public: void GTessellator::SetStyleVisibility(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::SetStyleVisibility(GTessellator *this, unsigned int a2, bool a3)
{
  unsigned int v3; // ebx
  unsigned int v5; // esi
  unsigned int v6; // ebx
  unsigned int i; // ecx
  int v8; // edx
  _BYTE *v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ecx
  _BYTE *v13; // eax
  _BYTE *v14; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  unsigned int v17; // [esp+18h] [ebp-4h]

  v3 = a2;
  v5 = (unsigned int)*(this + 10);
  v17 = v5;
  if ( a2 >= v5 )
  {
    if ( a2 >= (unsigned int)*(this + 11) )
    {
      v14 = nullptr;
      v15 = 0;
      v16 = 0;
      GArrayUnsafeBase<bool,GAllocatorGH_POD<bool,133>>::Reserve(this: (int)&v14, a2: v5, a3: 0);
      G_AppendArray<GArrayUnsafePOD<bool,133>,GArrayUnsafeLH_POD<bool,133>>(a1: &v14, a2: (int *)this + 9);
      GArrayUnsafeBase<bool,GAllocatorLH_POD<bool,133>>::Reserve(this: (int)(this + 9), a2: a2 + 1, a3: 32);
      v6 = v15;
      for ( i = 0; i < v6; *v9 = v8 )
      {
        v8 = (int)*(this + 10);
        v9 = (char *)*(this + 9) + v8;
        *(this + 10) = (GTessellator)(v8 + 1);
        LOBYTE(v8) = v14[i++];
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      v5 = v17;
      v3 = a2;
    }
    v10 = (unsigned int)*(this + 10);
    if ( v10 <= v3 )
    {
      v11 = v3 - v10 + 1;
      do
      {
        v12 = (int)*(this + 10);
        v13 = (char *)*(this + 9) + v12;
        --v11;
        *(this + 10) = (GTessellator)(v12 + 1);
        *v13 = 1;
      }
      while ( v11 != 0 );
    }
  }
  *((_BYTE *)&(*(this + 9))->attributes + v3) = a3;
  if ( v5 == 0 && v3 != 0 )
    LOBYTE((*(this + 9))->attributes) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018DAB0
// Name: private: void GTessellator::setupIntersections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::setupIntersections(GTessellator *this)
{
  GTessellator *v2; // edi
  EHExceptionRecord *v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // eax

  v2 = this + 35;
  v3 = (EHExceptionRecord *)(this + 38);
  if ( v2 != (GTessellator *)v3 )
  {
    v4 = (unsigned int)v2[1];
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(this: v3, cap: v4, extraTail: 0);
    *(this + 39) = (GTessellator)v4;
    if ( v4 != 0 )
      memmove(dst: (unsigned __int8 *)*(this + 38), src: (unsigned __int8 *)*v2, count: 4 * v4);
  }
  v5 = 0;
  if ( *(this + 36) != nullptr )
  {
    do
    {
      *(_DWORD *)(*(&(*v2)->attributes + v5) + 48) = v5;
      *(&(*(this + 44))->attributes + v5) = v5;
      ++v5;
    }
    while ( v5 < (unsigned int)*(this + 36) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018DB20
// Name: public: void GTessellator::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::ClearAndRelease(GTessellator *this)
{
  GTessellator::Clear(this);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 3));
  *(this + 5) = nullptr;
  *(this + 4) = nullptr;
  *(this + 3) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 6));
  *(this + 8) = nullptr;
  *(this + 7) = nullptr;
  *(this + 6) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 9));
  *(this + 11) = nullptr;
  *(this + 10) = nullptr;
  *(this + 9) = nullptr;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 12);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 16);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 20);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 24);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 28));
  *(this + 30) = nullptr;
  *(this + 29) = nullptr;
  *(this + 28) = nullptr;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 31);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 35));
  *(this + 37) = nullptr;
  *(this + 36) = nullptr;
  *(this + 35) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 38));
  *(this + 40) = nullptr;
  *(this + 39) = nullptr;
  *(this + 38) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 41));
  *(this + 43) = nullptr;
  *(this + 42) = nullptr;
  *(this + 41) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 44));
  *(this + 46) = nullptr;
  *(this + 45) = nullptr;
  *(this + 44) = nullptr;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 47);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 51));
  *(this + 53) = nullptr;
  *(this + 52) = nullptr;
  *(this + 51) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 62));
  *(this + 64) = nullptr;
  *(this + 63) = nullptr;
  *(this + 62) = nullptr;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 65);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 71));
  *(this + 73) = nullptr;
  *(this + 72) = nullptr;
  *(this + 71) = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 74));
  *(this + 76) = nullptr;
  *(this + 75) = nullptr;
  *(this + 74) = nullptr;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 77);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 81);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 85);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 89);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 93);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 97);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 101);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 105);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 109);
}

//------------------------------------------------------------------------------
// Address: 0x1018DD70
// Name: public: void GTessellator::SortMonotonesByStyle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::SortMonotonesByStyle(GTessellator *this)
{
  G_QuickSortSliced<GArrayPagedLH_POD<GTessellator::MonotoneType,6,64,133>,bool (__cdecl *)(GTessellator::MonotoneType const &,GTessellator::MonotoneType const &)>(
    a1: (int)(this + 85),
    a2: 0,
    a3: (int)*(this + 85),
    a4: (unsigned __int8 (__cdecl *)(int, int))GTessellator::styleLess);
}

//------------------------------------------------------------------------------
// Address: 0x1018DEB0
// Name: private: void GTessellator::buildEdgeList(unsigned int,unsigned int,int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::buildEdgeList(
        GTessellator *this,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v6; // eax
  unsigned int *v7; // esi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edi
  double v13; // st7
  int v14; // eax
  double v15; // st7
  unsigned int v16; // edi
  double v17; // st6
  float *v18; // eax
  float v19; // edx
  GTessellator *v20; // ebx
  unsigned int v21; // esi
  float v22[14]; // [esp+Ch] [ebp-54h] BYREF
  unsigned int v23; // [esp+44h] [ebp-1Ch]
  float v24; // [esp+4Ch] [ebp-14h]
  unsigned int v25; // [esp+54h] [ebp-Ch]
  unsigned int i; // [esp+58h] [ebp-8h]
  GTessellator *v27; // [esp+5Ch] [ebp-4h]
  float *v28; // [esp+68h] [ebp+8h]

  v6 = (unsigned int)*(this + 20);
  v7 = (unsigned int *)(this + 20);
  v27 = this;
  v25 = v6;
  for ( i = 0; i < a3; ++i )
  {
    v9 = (int)*(this + 15);
    v10 = a2;
    a2 += a4;
    v28 = (float *)(*(_DWORD *)(v9 + 4 * (v10 >> 10)) + 8 * (v10 & 0x3FF));
    v11 = *(_DWORD *)(v9 + 4 * (a2 >> 10));
    v12 = a2 & 0x3FF;
    v13 = *(float *)(v11 + 8 * v12);
    v14 = v11 + 8 * v12;
    v15 = v13 - *v28;
    v16 = *v7 >> 10;
    v17 = *(float *)(v14 + 4) - v28[1];
    v23 = v10;
    v24 = v15 / v17;
    if ( v16 >= v7[1] )
    {
      GArrayPagedBase<GTessellator::EdgeType,10,64,GAllocatorPagedLH_POD<GTessellator::EdgeType,133>>::allocatePage(
        this: v7,
        a2: v16);
      v10 = v23;
    }
    v18 = (float *)(16 * (*v7 & 0x3FF) + *(_DWORD *)(v7[3] + 4 * v16));
    *(_DWORD *)v18 = v10;
    v19 = v24;
    *((_DWORD *)v18 + 1) = a2;
    v18[2] = v19;
    v18[3] = 0.0;
    ++*v7;
    this = v27;
    if ( i != 0 )
    {
      *(_DWORD *)(*(&v27[23]->attributes + ((*v7 - 2) >> 10)) + 16 * ((*v7 - 2) & 0x3FF) + 12) = *(&v27[23]->attributes
                                                                                                 + ((*v7 - 1) >> 10))
                                                                                               + 16
                                                                                               * ((*v7 - 1) & 0x3FF);
      this = v27;
    }
    v6 = v25;
  }
  v22[1] = 0.0;
  v22[3] = 0.0;
  v22[2] = 0.0;
  LODWORD(v22[0]) = *(&(*(this + 23))->attributes + (v6 >> 10)) + 16 * (v6 & 0x3FF);
  v20 = this + 24;
  LODWORD(v22[4]) = a4;
  LODWORD(v22[5]) = a5;
  v21 = (unsigned int)*(this + 24) >> 6;
  LODWORD(v22[6]) = a6;
  memset(&v22[7], 0, 20);
  v22[13] = 0.0;
  v22[12] = NAN;
  if ( v21 >= (unsigned int)*(this + 25) )
    GArrayPagedBase<GTessellator::MonoChainType,6,64,GAllocatorPagedLH_POD<GTessellator::MonoChainType,133>>::allocatePage(
      this: (unsigned int *)this + 24,
      a2: v21);
  qmemcpy((void *)(*(&v20[3]->attributes + v21) + 56 * ((unsigned int)*v20 & 0x3F)), v22, 56);
  *v20 = (GTessellator)((char *)*v20 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018E040
// Name: private: void GTessellator::addPath(class GCompoundShape::SPath const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::addPath(GTessellator *this, const struct GCompoundShape::SPath *a2, int a3)
{
  const struct GCompoundShape::SPath *v4; // ecx
  unsigned int *v5; // esi
  unsigned int *v6; // ebx
  int v7; // edx
  int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  int v11; // edi
  int v12; // eax
  int v13; // edx
  unsigned int v14; // ebx
  int v15; // esi
  _DWORD *v16; // eax
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+Ch] [ebp-1Ch]
  int v19; // [esp+10h] [ebp-18h]
  float v20; // [esp+14h] [ebp-14h]
  float v21; // [esp+18h] [ebp-10h]
  unsigned int v22; // [esp+1Ch] [ebp-Ch]
  GTessellator *v23; // [esp+20h] [ebp-8h]
  unsigned int v24; // [esp+24h] [ebp-4h]

  v4 = a2;
  v23 = this;
  if ( *((_DWORD *)a2 + 1) >= 2u )
  {
    v5 = (unsigned int *)(this + 12);
    v17 = (int)*(this + 12);
    v24 = 0;
    v6 = (unsigned int *)(this + 31);
    do
    {
      v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v4 + 20) + 4 * ((v24 + *((_DWORD *)v4 + 2)) >> 8));
      v8 = (unsigned __int8)(v24 + *((_BYTE *)v4 + 8));
      v20 = *(float *)(v7 + 8 * v8);
      v9 = *v6 >> 10;
      v21 = *(float *)(v7 + 8 * v8 + 4);
      v22 = *v5;
      if ( v9 >= v6[1] )
      {
        GArrayPagedBase<unsigned int,10,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: v9);
        v4 = a2;
      }
      *(_DWORD *)(*(_DWORD *)(v6[3] + 4 * v9) + 4 * ((*v6)++ & 0x3FF)) = v22;
      v10 = *v5 >> 10;
      if ( v10 >= v5[1] )
      {
        GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
          this: v5,
          a2: *v5 >> 10);
        v4 = a2;
      }
      v11 = *(_DWORD *)(v5[3] + 4 * v10);
      v12 = *v5 & 0x3FF;
      *(float *)(v11 + 8 * v12) = v20;
      *(float *)(v11 + 8 * v12 + 4) = v21;
      ++*v5;
      if ( *((float *)v23 + 56) > (double)v20 )
        *((float *)v23 + 56) = v20;
      if ( *((float *)v23 + 57) > (double)v21 )
        *((float *)v23 + 57) = v21;
      if ( *((float *)v23 + 58) < (double)v20 )
        *((float *)v23 + 58) = v20;
      if ( *((float *)v23 + 59) < (double)v21 )
        *((float *)v23 + 59) = v21;
      ++v24;
    }
    while ( v24 < *((_DWORD *)v4 + 1) );
    v13 = a3 + *((_DWORD *)v4 + 3);
    v14 = (unsigned int)v23[16] >> 6;
    v15 = *v5 - 1;
    v18 = v13;
    v19 = a3 + *((_DWORD *)v4 + 4);
    if ( v14 >= (unsigned int)v23[17] )
    {
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
        this: (unsigned int *)v23 + 16,
        a2: v14);
      v13 = v18;
    }
    v16 = (_DWORD *)(16 * ((unsigned int)v23[16] & 0x3F) + *(&v23[19]->attributes + v14));
    *v16 = v17;
    v16[1] = v15;
    v16[2] = v13;
    v16[3] = v19;
    v23[16] = (GTessellator)((char *)v23[16] + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018E1E0
// Name: private: void GTessellator::decomposePath(struct GTessellator::PathInfoType const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::decomposePath(pairNode *this, int *min)
{
  int *v2; // edi
  int v3; // esi
  pairNode *v4; // ebx
  int v5; // ecx
  unsigned int i; // edx
  int myLen; // eax
  signed int v8; // esi
  int v9; // ecx
  unsigned int j; // edx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-Ch]
  unsigned int numEdges; // [esp+14h] [ebp-4h]
  unsigned int numEdgesa; // [esp+14h] [ebp-4h]
  int mina; // [esp+20h] [ebp+8h]

  v2 = min;
  v3 = *min;
  v4 = this;
  v12 = min[1];
  if ( *min < v12 )
  {
    do
    {
      if ( (unsigned __int8)GTessellator::forwardMin(this: (GTessellator *)v4, y: v3, start: *v2) != 0 )
      {
        v5 = v3 + 1;
        numEdges = 1;
        for ( i = v3 + 2; v5 < v12; ++i )
        {
          myLen = v4[3].myLen;
          v2 = min;
          v4 = this;
          if ( *(float *)(*(_DWORD *)(myLen + 4 * ((unsigned int)v5 >> 10)) + 8 * (v5 & 0x3FF) + 4) >= (double)*(float *)(*(_DWORD *)(myLen + 4 * (i >> 10)) + 8 * (i & 0x3FF) + 4) )
            break;
          ++numEdges;
          ++v5;
        }
        GTessellator::buildEdgeList(this: (GTessellator *)v4, a2: v3, a3: numEdges, a4: 1, a5: v2[2], a6: v2[3]);
        v3 = v3 + numEdges - 1;
      }
      ++v3;
      v12 = v2[1];
    }
    while ( v3 < v12 );
  }
  v8 = v2[1];
  for ( mina = v8; v8 > *v2; mina = v8 )
  {
    if ( (unsigned __int8)GTessellator::reverseMin(this: (GTessellator *)v4, y: v8, end: v2[1]) != 0 )
    {
      v9 = v8 - 1;
      numEdgesa = 1;
      for ( j = v8 - 2; v9 > *v2; --j )
      {
        v11 = v4[3].myLen;
        v8 = mina;
        v4 = this;
        if ( *(float *)(*(_DWORD *)(v11 + 4 * ((unsigned int)v9 >> 10)) + 8 * (v9 & 0x3FF) + 4) >= (double)*(float *)(*(_DWORD *)(v11 + 4 * (j >> 10)) + 8 * (j & 0x3FF) + 4) )
          break;
        ++numEdgesa;
        --v9;
      }
      GTessellator::buildEdgeList(this: (GTessellator *)v4, a2: v8, a3: numEdgesa, a4: -1, a5: v2[2], a6: v2[3]);
      v8 += 1 - numEdgesa;
    }
    --v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018E340
// Name: private: unsigned int GTessellator::nextScanbeam(float,float,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GTessellator::nextScanbeam(
        GTessellator *this,
        float yb,
        float yt,
        unsigned int startMc,
        unsigned int j)
{
  double v6; // st7
  unsigned int v7; // eax
  double v8; // st6
  int v9; // ecx
  _DWORD *v10; // edx
  int v11; // edi
  unsigned int *v12; // edx
  unsigned int v13; // eax
  int v14; // edi
  float *v15; // edx
  double v16; // st5
  int v17; // edi
  const _s__ThrowInfo *v18; // eax
  const _s__ThrowInfo *v19; // edx
  int v20; // eax
  float *v21; // edx
  unsigned int v22; // eax
  int v23; // eax
  double v24; // st5
  unsigned int v25; // eax
  int v26; // edx
  int v27; // eax
  double v28; // st5
  float *v29; // edx
  double v30; // st5
  int v31; // edi
  const _s__ThrowInfo *v32; // eax
  const _s__ThrowInfo *v33; // ecx
  int v34; // eax
  float *v35; // ecx
  unsigned int k; // eax
  unsigned int v37; // edi
  unsigned int *v38; // ecx
  int v39; // edx
  unsigned int v40; // eax
  float *v41; // ecx
  double v42; // st5
  double v43; // st5
  int v44; // edx
  unsigned int v45; // ebx
  double v46; // st5
  int v47; // ecx
  double v48; // st4
  double v49; // st3
  double v50; // st4
  double v51; // st3
  bool v52; // c0
  bool v53; // c3
  double v54; // st4
  unsigned int v55; // eax
  unsigned int *v56; // ecx
  const _s__ThrowInfo *v57; // eax
  const _s__ThrowInfo *v58; // edi
  unsigned int v59; // ebx
  unsigned int v60; // eax
  int *v61; // edi
  int v62; // ecx
  unsigned int *v63; // edx
  bool v64; // cc
  int v65; // eax
  int v66; // eax
  int v67; // ecx
  int v68; // ebx
  float v69; // ecx
  double v70; // st5
  double v71; // st4
  double v72; // st5
  double v73; // st5
  unsigned int v74; // ebx
  unsigned int v75; // ecx
  void *v76; // eax
  const _s__ThrowInfo *v77; // eax
  int v78; // ecx
  int v79; // eax
  int v80; // eax
  unsigned int v81; // ecx
  bool v82; // sf
  int v83; // eax
  int v84; // edx
  _DWORD *v85; // eax
  int v86; // ecx
  int v87; // ebx
  _DWORD *v88; // edx
  int *v89; // eax
  int v90; // ecx
  unsigned int v91; // ecx
  int v93; // [esp+Ch] [ebp-20h]
  int v94; // [esp+10h] [ebp-1Ch]
  float v95; // [esp+14h] [ebp-18h]
  int v96; // [esp+18h] [ebp-14h] BYREF
  int v97; // [esp+1Ch] [ebp-10h] BYREF
  float den; // [esp+20h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-8h]
  unsigned int retFlags; // [esp+28h] [ebp-4h]
  float startMcc; // [esp+3Ch] [ebp+10h]
  unsigned int startMca; // [esp+3Ch] [ebp+10h]
  unsigned int startMcb; // [esp+3Ch] [ebp+10h]
  unsigned int ja; // [esp+40h] [ebp+14h]

  retFlags = j != 0;
  v6 = yt;
  *(float *)&v7 = 0.0;
  v8 = yb;
  *(this + 54) = (GTessellator)0x3FFFFFFF;
  *(this + 55) = nullptr;
  *(this + 42) = nullptr;
  *(float *)&i = 0.0;
  if ( *(this + 36) != nullptr )
  {
    do
    {
      v9 = *(&(*(this + 35))->attributes + v7);
      *(_DWORD *)(v9 + 44) &= ~8u;
      v10 = *(_DWORD **)v9;
      v11 = (int)*(this + 15);
      if ( v8 == *(float *)(*(_DWORD *)(v11 + 4 * (*(_DWORD *)(*(_DWORD *)v9 + 4) >> 10))
                          + 8 * (*(_DWORD *)(*(_DWORD *)v9 + 4) & 0x3FF)
                          + 4) )
      {
        v12 = (unsigned int *)v10[3];
        if ( v12 != nullptr )
        {
          *(_DWORD *)v9 = v12;
          v13 = *v12;
          v14 = (int)*(this + 15);
          v15 = (float *)(*(_DWORD *)(v14 + 4 * (v12[1] >> 10)) + 8 * (v12[1] & 0x3FF));
          *(float *)(v9 + 8) = *(float *)(*(_DWORD *)(v14 + 4 * (v13 >> 10)) + 8 * (v13 & 0x3FF));
          if ( v6 == v15[1] )
          {
            v16 = *v15;
          }
          else
          {
            v17 = *(&(*(this + 15))->attributes + (**(_DWORD **)v9 >> 10));
            v16 = (v6 - *(float *)(v17 + 8 * (**(_DWORD **)v9 & 0x3FF) + 4)) * *(float *)(*(_DWORD *)v9 + 8)
                + *(float *)(v17 + 8 * (**(_DWORD **)v9 & 0x3FF));
          }
          v18 = *(const _s__ThrowInfo **)(v9 + 20);
          den = v16;
          v19 = *(const _s__ThrowInfo **)(v9 + 24);
          *(float *)(v9 + 12) = den;
          if ( v18 != nullptr )
          {
            if ( v18 < *(this + 54) )
              *(this + 54) = v18;
            if ( v18 > *(this + 55) )
              *(this + 55) = v18;
          }
          if ( v19 != nullptr )
          {
            if ( v19 < *(this + 54) )
              *(this + 54) = v19;
            if ( v19 > *(this + 55) )
              *(this + 55) = v19;
          }
          v20 = (int)*(this + 42);
          v21 = (float *)(&(*(this + 41))->attributes + v20);
          *(this + 42) = (GTessellator)(v20 + 1);
          v22 = i;
          *v21 = *(float *)&i;
          *(_DWORD *)(v9 + 44) |= 8u;
        }
        else
        {
          v23 = *(_DWORD *)(v9 + 44);
          v24 = *(float *)(v9 + 12);
          retFlags |= 2u;
          *(float *)(v9 + 8) = v24;
          *(_DWORD *)(v9 + 44) = v23 | 2;
          v22 = i;
          *(_DWORD *)(v9 + 44) |= 8u;
        }
      }
      else
      {
        v25 = v10[1];
        v26 = *(_DWORD *)(v11 + 4 * (v25 >> 10));
        *(float *)(v9 + 8) = *(float *)(v9 + 12);
        v27 = v25 & 0x3FF;
        v28 = *(float *)(v26 + 8 * v27 + 4);
        v29 = (float *)(v26 + 8 * v27);
        if ( v6 == v28 )
        {
          v30 = *v29;
        }
        else
        {
          v31 = *(&(*(this + 15))->attributes + (**(_DWORD **)v9 >> 10));
          v30 = (v6 - *(float *)(v31 + 8 * (**(_DWORD **)v9 & 0x3FF) + 4)) * *(float *)(*(_DWORD *)v9 + 8)
              + *(float *)(v31 + 8 * (**(_DWORD **)v9 & 0x3FF));
        }
        v32 = *(const _s__ThrowInfo **)(v9 + 20);
        den = v30;
        *(float *)(v9 + 12) = den;
        v33 = *(const _s__ThrowInfo **)(v9 + 24);
        if ( v32 != nullptr )
        {
          if ( v32 < *(this + 54) )
            *(this + 54) = v32;
          if ( v32 > *(this + 55) )
            *(this + 55) = v32;
        }
        if ( v33 != nullptr )
        {
          if ( v33 < *(this + 54) )
            *(this + 54) = v33;
          if ( v33 > *(this + 55) )
            *(this + 55) = v33;
        }
        v34 = (int)*(this + 42);
        v35 = (float *)(&(*(this + 41))->attributes + v34);
        *(this + 42) = (GTessellator)(v34 + 1);
        v22 = i;
        *v35 = *(float *)&i;
      }
      v7 = v22 + 1;
      i = v7;
    }
    while ( v7 < (unsigned int)*(this + 36) );
  }
  if ( j != 0 )
  {
    for ( k = 4 * startMc; ; k = i )
    {
      v37 = *(unsigned int *)((char *)&(*(this + 28))->attributes + k);
      v38 = *(unsigned int **)v37;
      v39 = (int)*(this + 15);
      i = k + 4;
      v40 = *v38;
      v41 = (float *)(*(_DWORD *)(v39 + 4 * (v38[1] >> 10)) + 8 * (v38[1] & 0x3FF));
      v42 = *(float *)(*(_DWORD *)(v39 + 4 * (v40 >> 10)) + 8 * (v40 & 0x3FF));
      *(_DWORD *)(v37 + 44) = 8;
      *(float *)(v37 + 8) = v42;
      if ( v6 == v41[1] )
      {
        v43 = *v41;
      }
      else
      {
        v44 = *(&(*(this + 15))->attributes + (**(_DWORD **)v37 >> 10));
        v43 = (v6 - *(float *)(v44 + 8 * (**(_DWORD **)v37 & 0x3FF) + 4)) * *(float *)(*(_DWORD *)v37 + 8)
            + *(float *)(v44 + 8 * (**(_DWORD **)v37 & 0x3FF));
      }
      startMcc = v43;
      v45 = 0;
      v46 = startMcc;
      *(float *)(v37 + 12) = startMcc;
      v47 = (int)*(this + 36);
      for ( startMca = v47; v47 > 0; startMca = v47 )
      {
        v48 = *(float *)(v37 + 8);
        v47 >>= 1;
        v49 = *(float *)(*(&(*(this + 35))->attributes + v47 + v45) + 8);
        den = *((float *)&(*(this + 35))->attributes + v47 + v45);
        if ( v49 == v48 )
        {
          v54 = *(float *)(LODWORD(den) + 12);
          v52 = v54 < v46;
          v53 = v54 == v46;
        }
        else
        {
          v50 = *(float *)(v37 + 8);
          v51 = *(float *)(LODWORD(den) + 8);
          v52 = v51 < v50;
          v53 = v51 == v50;
        }
        if ( v52 || v53 )
        {
          v45 += v47 + 1;
          v47 = -1 - v47 + startMca;
        }
      }
      v55 = (unsigned int)*(this + 36);
      if ( v45 < v55 )
      {
        memmove(
          dst: (unsigned __int8 *)&(*(this + 35))->pmfnUnwind + 4 * v45,
          src: (unsigned __int8 *)&(*(this + 35))->attributes + 4 * v45,
          count: 4 * (v55 - v45));
        v6 = yt;
        v8 = yb;
        *(&(*(this + 35))->attributes + v45) = v37;
        *(this + 36) = (GTessellator)((char *)*(this + 36) + 1);
      }
      else
      {
        v56 = &(*(this + 35))->attributes + v55;
        *(this + 36) = (GTessellator)(v55 + 1);
        *v56 = v37;
      }
      v57 = *(const _s__ThrowInfo **)(v37 + 20);
      v58 = *(const _s__ThrowInfo **)(v37 + 24);
      if ( v57 != nullptr )
      {
        if ( v57 < *(this + 54) )
          *(this + 54) = v57;
        if ( v57 > *(this + 55) )
          *(this + 55) = v57;
      }
      if ( v58 != nullptr )
      {
        if ( v58 < *(this + 54) )
          *(this + 54) = v58;
        if ( v58 > *(this + 55) )
          *(this + 55) = v58;
      }
      if ( --j == 0 )
        break;
    }
  }
  v59 = retFlags;
  v60 = 0;
  v61 = (int *)(this + 47);
  *(this + 47) = nullptr;
  if ( (v59 & 1) != 0 )
  {
    *(this + 42) = nullptr;
    if ( *(this + 36) != nullptr )
    {
      do
      {
        if ( (*(_BYTE *)(*(&(*(this + 35))->attributes + v60) + 44) & 2) == 0 )
        {
          v62 = (int)*(this + 42);
          v63 = &(*(this + 41))->attributes + v62;
          *(this + 42) = (GTessellator)(v62 + 1);
          *v63 = v60;
        }
        ++v60;
      }
      while ( v60 < (unsigned int)*(this + 36) );
    }
  }
  v64 = (unsigned int)*(this + 42) <= 1;
  *(float *)&i = v6 - v8;
  if ( !v64 )
  {
    v65 = 0;
    startMcb = 0;
    do
    {
      ja = v65;
      if ( v65 >= 0 )
      {
        do
        {
          v66 = (int)*(this + 41);
          v67 = (int)*(this + 35);
          v68 = *(_DWORD *)(v67 + 4 * *(_DWORD *)(v66 + 4 * ja));
          v69 = *(float *)(v67 + 4 * *(_DWORD *)(v66 + 4 * ja + 4));
          v70 = *(float *)(v68 + 12);
          v71 = *(float *)(LODWORD(v69) + 12);
          den = v69;
          if ( v71 >= v70 )
            break;
          if ( *v61 == 0 )
          {
            GTessellator::setupIntersections(this);
            v69 = den;
            v8 = yb;
            v6 = yt;
          }
          v94 = *(_DWORD *)(LODWORD(v69) + 48);
          v93 = *(_DWORD *)(v68 + 48);
          den = *(float *)(LODWORD(v69) + 12)
              - *(float *)(LODWORD(v69) + 8)
              - *(float *)(v68 + 12)
              + *(float *)(v68 + 8);
          v72 = den;
          if ( 0.0 == den )
          {
            v73 = v8;
          }
          else
          {
            den = *(float *)(v68 + 8) - *(float *)(LODWORD(v69) + 8);
            v73 = den * *(float *)&i / v72 + v8;
          }
          v95 = v73;
          if ( v95 < v8 )
            v95 = v8;
          if ( v95 > v6 )
            v95 = v6;
          v74 = (unsigned int)*v61 >> 6;
          if ( v74 >= (unsigned int)*(this + 48) )
          {
            v75 = (unsigned int)*(this + 49);
            if ( v74 >= v75 )
            {
              v76 = (void *)*(this + 50);
              if ( v76 != nullptr )
              {
                LODWORD(den) = 4 * v75 + 256;
                v77 = (const _s__ThrowInfo *)GMemory::pGlobalHeap->Realloc(
                                               this: GMemory::pGlobalHeap,
                                               a2: v76,
                                               a3: LODWORD(den));
              }
              else
              {
                v97 = 133;
                v77 = (const _s__ThrowInfo *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                               this: GMemory::pGlobalHeap,
                                               a2: this + 47,
                                               a3: 256,
                                               a4: &v97);
              }
              *(this + 49) += 4;
              *(this + 50) = v77;
            }
            v96 = 133;
            v6 = yt;
            v8 = yb;
            *(&(*(this + 50))->attributes + v74) = (unsigned int)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                                   this: GMemory::pGlobalHeap,
                                                                   a2: this + 47,
                                                                   a3: 768,
                                                                   a4: &v96);
            *(this + 48) = (GTessellator)((char *)*(this + 48) + 1);
          }
          v78 = *(&(*(this + 50))->attributes + v74);
          v79 = 3 * (*v61 & 0x3F);
          *(_DWORD *)(v78 + 4 * v79) = v93;
          v80 = v78 + 4 * v79;
          *(_DWORD *)(v80 + 4) = v94;
          v81 = ja;
          *(float *)(v80 + 8) = v95;
          ++*v61;
          v82 = (--ja & 0x80000000) != 0;
          v83 = (int)*(this + 41);
          v84 = *(_DWORD *)(v83 + 4 * v81 + 4);
          v85 = (_DWORD *)(v83 + 4 * v81);
          v86 = (int)*(this + 35);
          v87 = *(_DWORD *)(v86 + 4 * v84);
          v88 = (_DWORD *)(v86 + 4 * v84);
          v89 = (int *)(v86 + 4 * *v85);
          v90 = *v89;
          *v89 = v87;
          *v88 = v90;
        }
        while ( !v82 );
      }
      v65 = startMcb + 1;
      v91 = startMcb + 2;
      ++startMcb;
    }
    while ( v91 < (unsigned int)*(this + 42) );
    v59 = retFlags;
  }
  if ( (unsigned int)*v61 > 1 )
    G_InsertionSortSliced<GArrayPagedLH_POD<GTessellator::IntersectionType,6,64,133>,bool (__cdecl *)(GTessellator::IntersectionType const &,GTessellator::IntersectionType const &)>(
      a1: (int)(this + 47),
      a2: 0,
      a3: *v61,
      a4: (unsigned __int8 (__cdecl *)(int, int))GTessellator::intersectionLess);
  return v59;
}

//------------------------------------------------------------------------------
// Address: 0x1018E980
// Name: private: unsigned int GTessellator::addEventVertex(struct GPointType const __near &)
// Source: json
//------------------------------------------------------------------------------
const DNameStatusNode *__thiscall GTessellator::addEventVertex(unsigned int *this, const DNameStatusNode *result)
{
  unsigned int v3; // ebx
  int v4; // ebx
  int v5; // eax

  if ( *((float *)this + 70) < (double)*(float *)&result->me
    || *((float *)this + 69) < (double)*(float *)&result->__vftable )
  {
    *(this + 69) = (unsigned int)result->__vftable;
    *(this + 70) = result->me;
    v3 = *(this + 65) >> 10;
    if ( v3 >= *(this + 66) )
      GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
        this: this + 65,
        a2: v3);
    v4 = *(_DWORD *)(*(this + 68) + 4 * v3);
    v5 = *(this + 65) & 0x3FF;
    *(_DWORD *)(v4 + 8 * v5) = *(this + 69);
    *(_DWORD *)(v4 + 8 * v5 + 4) = *(this + 70);
    ++*(this + 65);
  }
  return (const DNameStatusNode *)(*(this + 65) - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018EA20
// Name: private: unsigned int GTessellator::addEventVertex(struct GTessellator::MonoChainType const __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
const DNameStatusNode *__thiscall GTessellator::addEventVertex(
        GTessellator *this,
        const pDNameNode *const mc,
        float yb,
        bool x)
{
  int v5; // edx
  pDNameNode_vtbl *v7; // edi
  unsigned int length; // ecx
  int v9; // edx
  double v10; // st7
  int v11; // edx
  unsigned int v12; // ebx
  int v13; // ecx
  unsigned int v14; // eax
  float xa; // [esp+20h] [ebp+10h]

  if ( !x && mc[3].me == (DName *)mc[4].__vftable && mc[4].me == (DName *)mc[5].__vftable )
  {
    if ( ((int)mc[5].me & 8) != 0
      && (v5 = (int)*(this + 15),
          yb == *(float *)(*(_DWORD *)(v5 + 4 * ((unsigned int)mc->length >> 10)) + 8 * ((int)mc->length & 0x3FF) + 4)) )
    {
      return GTessellator::addEventVertex(
               (unsigned int *)this,
               result: (const DNameStatusNode *)(*(_DWORD *)(v5 + 4 * ((unsigned int)mc->length >> 10))
                                       + 8 * ((int)mc->length & 0x3FF)));
    }
    else
    {
      return (const DNameStatusNode *)-1;
    }
  }
  else
  {
    v7 = mc->__vftable;
    length = (unsigned int)mc->length;
    v9 = (int)*(this + 15);
    v10 = yb;
    if ( yb == *(float *)(*(_DWORD *)(v9 + 4 * (length >> 10)) + 8 * (length & 0x3FF) + 4) )
      return GTessellator::addEventVertex(
               (unsigned int *)this,
               result: (const DNameStatusNode *)(*(_DWORD *)(v9 + 4 * (length >> 10)) + 8 * (length & 0x3FF)));
    if ( ((int)mc[5].me & 2) != 0
      && (length = (unsigned int)v7->getLastChar,
          v10 == *(float *)(*(_DWORD *)(v9 + 4 * (length >> 10)) + 8 * (length & 0x3FF) + 4)) )
    {
      return GTessellator::addEventVertex(
               (unsigned int *)this,
               result: (const DNameStatusNode *)(*(_DWORD *)(v9 + 4 * (length >> 10)) + 8 * (length & 0x3FF)));
    }
    else
    {
      v11 = *(_DWORD *)(v9 + 4 * ((unsigned int)v7->length >> 10));
      xa = (v10 - *(float *)(v11 + 8 * ((int)v7->length & 0x3FF) + 4)) * *(float *)&v7->getString
         + *(float *)(v11 + 8 * ((int)v7->length & 0x3FF));
      if ( *((float *)this + 70) >= v10 )
      {
        if ( *((float *)this + 60) < xa - *((float *)this + 69) )
        {
          *((float *)this + 70) = yb;
          *((float *)this + 69) = xa;
          GArrayPagedBase<GPointType,10,64,GAllocatorPagedLH_POD<GPointType,133>>::PushBack(
            this: (unsigned int *)this + 65,
            a2: this + 69);
        }
        return (const DNameStatusNode *)((char *)&(*(this + 65))[-1].pCatchableTypeArray + 3);
      }
      else
      {
        *((float *)this + 69) = xa;
        *((float *)this + 70) = yb;
        v12 = (unsigned int)*(this + 65) >> 10;
        if ( v12 >= (unsigned int)*(this + 66) )
          GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
            this: (unsigned int *)this + 65,
            a2: (unsigned int)*(this + 65) >> 10);
        v13 = *(&(*(this + 68))->attributes + v12);
        v14 = (unsigned int)*(this + 65) & 0x3FF;
        *(_DWORD *)(v13 + 8 * v14) = *(this + 69);
        *(_DWORD *)(v13 + 8 * v14 + 4) = *(this + 70);
        *(this + 65) = (GTessellator)((char *)*(this + 65) + 1);
        return (const DNameStatusNode *)((char *)&(*(this + 65))[-1].pCatchableTypeArray + 3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EC20
// Name: private: void GTessellator::growMonotone(struct GTessellator::MonotoneType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GTessellator::growMonotone(_DWORD *this, int *m, unsigned int vertex)
{
  _DWORD *v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  unsigned int result; // eax
  _DWORD *v10; // edx
  _DWORD *v11; // edi
  unsigned int v12; // ebx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  unsigned int ma; // [esp+14h] [ebp+8h]

  if ( *m != 0 )
  {
    v10 = (_DWORD *)(*(_DWORD *)(*(this + 92) + 4 * ((unsigned int)m[1] >> 10)) + 8 * (m[1] & 0x3FF));
    result = vertex;
    ma = (unsigned int)v10;
    if ( *v10 != vertex )
    {
      v11 = this + 89;
      v12 = *(this + 89) >> 10;
      if ( v12 >= *(this + 90) )
      {
        GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
          this: this + 89,
          a2: *(this + 89) >> 10);
        v10 = (_DWORD *)ma;
      }
      v13 = *(_DWORD *)(v11[3] + 4 * v12);
      v14 = *v11 & 0x3FF;
      *(_DWORD *)(v13 + 8 * v14) = vertex;
      *(_DWORD *)(v13 + 8 * v14 + 4) = 0;
      ++*v11;
      v10[1] = *(_DWORD *)(v11[3] + 4 * ((unsigned int)(*v11 - 1) >> 10)) + 8 * ((*v11 - 1) & 0x3FF);
      v15 = m[1];
      m[3] = m[2];
      m[2] = v15;
      result = *v11 - 1;
      m[1] = result;
    }
  }
  else
  {
    v4 = this + 89;
    v5 = *(this + 89) >> 10;
    if ( v5 >= *(this + 90) )
      GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
        this: this + 89,
        a2: *(this + 89) >> 10);
    v6 = *(_DWORD *)(v4[3] + 4 * v5);
    v7 = *v4 & 0x3FF;
    *(_DWORD *)(v6 + 8 * v7) = vertex;
    *(_DWORD *)(v6 + 8 * v7 + 4) = 0;
    ++*v4;
    v8 = *(_DWORD *)(v4[3] + 4 * ((unsigned int)(*v4 - 1) >> 10)) + 8 * ((*v4 - 1) & 0x3FF);
    m[3] = -1;
    m[2] = -1;
    *m = v8;
    result = *v4 - 1;
    m[1] = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018ED30
// Name: private: struct GTessellator::MonotoneType __near * GTessellator::startMonotone(unsigned int)
// Source: json
//------------------------------------------------------------------------------
DNameNode *__thiscall GTessellator::startMonotone(unsigned int *this, DNameNode *result)
{
  _DWORD *v2; // esi
  unsigned int v3; // edi
  _DWORD *v4; // eax

  v2 = this + 85;
  v3 = *(this + 85) >> 6;
  if ( v3 >= *(this + 86) )
    GArrayPagedBase<GTessellator::MonotoneType,6,64,GAllocatorPagedLH_POD<GTessellator::MonotoneType,133>>::allocatePage(
      this: this + 85,
      a2: v3);
  v4 = (_DWORD *)(*(_DWORD *)(v2[3] + 4 * v3) + 24 * (*v2 & 0x3F));
  *v4 = 0;
  v4[1] = -1;
  v4[2] = -1;
  v4[3] = -1;
  v4[4] = result;
  v4[5] = 0;
  ++*v2;
  return (DNameNode *)(*(_DWORD *)(v2[3] + 4 * ((unsigned int)(*v2 - 1) >> 6)) + 24 * ((*v2 - 1) & 0x3F));
}

//------------------------------------------------------------------------------
// Address: 0x1018EDB0
// Name: private: void GTessellator::replaceMonotone(struct GTessellator::PendingEndType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::replaceMonotone(DNameNode *this, const DNameNode *pe, DNameNode *style)
{
  DNameNode_vtbl *v3; // eax
  DNameNode *started; // eax
  DNameNode_vtbl *v5; // ecx

  if ( *((_BYTE *)&style->__vftable + *((_DWORD *)this + 9)) != 0 )
  {
    v3 = pe[1].__vftable;
    if ( v3 != nullptr )
    {
      if ( (DNameNode *)v3[1].getLastChar != style && v3->length != nullptr )
      {
        started = GTessellator::startMonotone((unsigned int *)this, result: style);
        v5 = pe[1].__vftable;
        started->__vftable = (DNameNode_vtbl *)v5->length;
        started[1].__vftable = (DNameNode_vtbl *)v5->getLastChar;
        started[2].__vftable = (DNameNode_vtbl *)v5->getString;
        started[3].__vftable = (DNameNode_vtbl *)v5[1].length;
        started[4].__vftable = (DNameNode_vtbl *)v5[1].getLastChar;
        started[5].__vftable = (DNameNode_vtbl *)v5[1].getString;
        v3 = pe[1].__vftable;
        v3->length = nullptr;
        v3->getLastChar = (char (__thiscall *)(DNameNode *))-1;
        v3->getString = (char *(__thiscall *)(DNameNode *, char *, char *))-1;
        v3[1].length = (int (__thiscall *)(DNameNode *))-1;
        v3[1].getString = nullptr;
      }
      v3[1].getLastChar = (char (__thiscall *)(DNameNode *))style;
    }
    else
    {
      pe[1].__vftable = (DNameNode_vtbl *)GTessellator::startMonotone((unsigned int *)this, result: style);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EE40
// Name: private: void GTessellator::addPendingEnd(struct GTessellator::ScanChainType __near *,struct GTessellator::ScanChainType __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::addPendingEnd(
        GTessellator *this,
        struct GTessellator::ScanChainType *a2,
        struct GTessellator::ScanChainType *a3,
        float a4)
{
  int v5; // ebx
  int v6; // edx
  float v7; // ecx
  float v8; // edx
  float v9; // ecx
  int v10; // eax
  unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  float v16[7]; // [esp+4h] [ebp-24h] BYREF
  int v17; // [esp+20h] [ebp-8h]
  int v18; // [esp+24h] [ebp-4h]

  if ( a2 != nullptr )
  {
    v5 = *((_DWORD *)a2 + 1);
    if ( v5 != 0 && *((_BYTE *)&(*(this + 9))->attributes + *(_DWORD *)(v5 + 16)) != 0 )
    {
      if ( *(_DWORD *)(v5 + 20) == 0 )
      {
        v6 = *(_DWORD *)a3;
        v16[0] = a4;
        v7 = *(float *)(v6 + 28);
        v8 = *((float *)a2 + 2);
        v16[1] = v7;
        v9 = *((float *)this + 81);
        v16[2] = v8;
        v16[4] = v9;
        v16[3] = NAN;
        v16[5] = 0.0;
        v16[6] = NAN;
        GArrayPagedBase<GTessellator::BaseLineType,4,16,GAllocatorPagedLH_POD<GTessellator::BaseLineType,133>>::PushBack(
          this: (unsigned int *)this + 77,
          a2: v16);
        *(_DWORD *)(v5 + 20) = *(&(*(this + 80))->attributes
                               + (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) >> 4))
                             + 28 * (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) & 0xF);
      }
      v10 = *((_DWORD *)a3 + 1);
      v11 = (unsigned int *)(this + 81);
      v12 = (unsigned int)*(this + 81) >> 4;
      v17 = *((_DWORD *)a3 + 2);
      v18 = v10;
      if ( v12 >= v11[1] )
        GArrayPagedBase<GTessellator::PendingEndType,4,16,GAllocatorPagedLH_POD<GTessellator::PendingEndType,133>>::allocatePage(
          this: v11,
          a2: v12);
      v13 = *(_DWORD *)(v11[3] + 4 * v12);
      v14 = v18;
      v15 = *v11 & 0xF;
      *(_DWORD *)(v13 + 8 * v15) = v17;
      *(_DWORD *)(v13 + 8 * v15 + 4) = v14;
      ++*v11;
      ++*(_DWORD *)(*(_DWORD *)(v5 + 20) + 20);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EF30
// Name: private: void GTessellator::connectPendingToLeft(struct GTessellator::ScanChainType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::connectPendingToLeft(
        GTessellator *this,
        struct GTessellator::ScanChainType *a2,
        unsigned int targetVertex)
{
  int v3; // eax
  DNameNode_vtbl *v5; // ecx
  unsigned int v6; // edi
  char *(__thiscall *getString)(DNameNode *, char *, char *); // edx
  char (__thiscall *getLastChar)(DNameNode *); // eax
  char *(__thiscall *v9)(DNameNode *, char *, char *); // edi
  char (__thiscall *v10)(DNameNode *); // eax
  _DWORD *v11; // ebx
  int *v12; // ebx
  int *started; // eax
  int v14; // ecx
  int v15; // ebx
  unsigned int v16; // edx
  int v17; // eax
  int v18; // eax
  char (__thiscall *v19)(DNameNode *); // eax
  int v20; // eax
  char (__thiscall *v21)(DNameNode *); // [esp+10h] [ebp-34h]
  char *(__thiscall *v22)(DNameNode *, char *, char *); // [esp+14h] [ebp-30h]
  int (__thiscall *length)(DNameNode *); // [esp+18h] [ebp-2Ch]
  unsigned int v24; // [esp+24h] [ebp-20h]
  char v25; // [esp+2Ch] [ebp-18h]
  _DWORD v26[2]; // [esp+30h] [ebp-14h] BYREF
  int *v27; // [esp+38h] [ebp-Ch]
  unsigned int styleAbove; // [esp+3Ch] [ebp-8h]
  DNameNode lowerBase; // [esp+40h] [ebp-4h]

  v3 = *((_DWORD *)a2 + 1);
  v5 = *(DNameNode_vtbl **)(v3 + 20);
  v6 = *(_DWORD *)(v3 + 16);
  *(_DWORD *)(v3 + 20) = 0;
  getString = v5[1].getString;
  v26[1] = *((_DWORD *)a2 + 1);
  getLastChar = v5[1].getLastChar;
  lowerBase.__vftable = v5;
  styleAbove = v6;
  v9 = v5->getString;
  v22 = getString;
  length = v5[1].length;
  v21 = getLastChar;
  v24 = *(_DWORD *)(*(&(*(this + 84))->attributes + ((unsigned int)getLastChar >> 4))
                  + 8 * ((unsigned __int8)getLastChar & 0xF));
  v10 = v5->getLastChar;
  v26[0] = v9;
  v11 = v26;
  v25 = 1;
  while ( 1 )
  {
    if ( v9 == (char *(__thiscall *)(DNameNode *, char *, char *))v24 )
      goto LABEL_16;
    if ( v25 != 0 )
    {
      GTessellator::growMonotone(this, m: *((int **)a2 + 1), vertex: v24);
      v12 = *((int **)a2 + 1);
      if ( targetVertex == -1 )
        goto LABEL_16;
LABEL_5:
      GTessellator::growMonotone(this, m: v12, vertex: targetVertex | 0x40000000);
      GTessellator::growMonotone(this, m: v12, vertex: targetVertex & 0xBFFFFFFF);
      goto LABEL_16;
    }
    if ( v10 != (char (__thiscall *)(DNameNode *))styleAbove || v11[1] == 0 )
    {
      started = (int *)GTessellator::startMonotone((unsigned int *)this, result: (DNameNode *)styleAbove);
      v27 = started;
      v11[1] = started;
      if ( v9 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
      {
        GTessellator::growMonotone(this, m: started, vertex: (unsigned int)v9 | 0x40000000);
        started = v27;
      }
      if ( v24 != -1 )
        GTessellator::growMonotone(this, m: started, vertex: v24 & 0xBFFFFFFF);
    }
    v12 = (int *)v11[1];
    if ( v22 != nullptr )
    {
      if ( targetVertex != -1 )
        goto LABEL_5;
    }
    else
    {
      *((_DWORD *)a2 + 1) = v12;
      GTessellator::growMonotone(this, m: v12, vertex: targetVertex | 0x40000000);
    }
LABEL_16:
    v25 = 0;
    if ( v22 == nullptr )
      break;
    v14 = (int)*(this + 84);
    v22 = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)v22 - 1);
    v9 = (char *(__thiscall *)(DNameNode *, char *, char *))v24;
    v15 = *(_DWORD *)(v14 + 4 * ((unsigned int)v21 >> 4));
    v16 = (unsigned int)v21 + 1;
    v17 = (unsigned __int8)v21 & 0xF;
    v21 = (char (__thiscall *)(DNameNode *))((char *)v21 + 1);
    v11 = (_DWORD *)(v15 + 8 * v17);
    if ( v22 != nullptr )
      v24 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * (v16 >> 4)) + 8 * (v16 & 0xF));
    else
      v24 = (unsigned int)length;
    v18 = v11[1];
    if ( v18 != 0 )
      v10 = *(char (__thiscall **)(DNameNode *))(v18 + 16);
    else
      v10 = nullptr;
  }
  if ( lowerBase.__vftable == (DNameNode_vtbl *)(*(&(*(this + 80))->attributes
                                                 + (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) >> 4))
                                               + 28
                                               * (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) & 0xF)) )
  {
    v19 = lowerBase.__vftable[1].getLastChar;
    if ( (GTessellator)v19 < *(this + 81) )
      *(this + 81) = (GTessellator)v19;
    v20 = (int)*(this + 77);
    if ( v20 != 0 )
      *(this + 77) = (GTessellator)(v20 - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F140
// Name: private: void GTessellator::connectPendingToRight(struct GTessellator::ScanChainType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::connectPendingToRight(
        GTessellator *this,
        struct GTessellator::ScanChainType *styleAbove,
        unsigned int targetVertex)
{
  int v4; // eax
  struct GTessellator::ScanChainType *v5; // edx
  DNameNode_vtbl *v7; // ecx
  char (__thiscall *getLastChar)(DNameNode *); // esi
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // edi
  int v12; // eax
  int v13; // eax
  struct GTessellator::ScanChainType *v14; // eax
  unsigned int v15; // edi
  _DWORD *v16; // eax
  int *v17; // esi
  int *v18; // edi
  const _s__ThrowInfo *v19; // eax
  int v20; // eax
  char (__thiscall *v21)(DNameNode *); // [esp+10h] [ebp-2Ch]
  char *(__thiscall *getString)(DNameNode *, char *, char *); // [esp+14h] [ebp-28h]
  unsigned int length; // [esp+18h] [ebp-24h]
  int v24; // [esp+1Ch] [ebp-20h]
  unsigned int v25; // [esp+20h] [ebp-1Ch]
  unsigned int v26; // [esp+24h] [ebp-18h]
  int *v27; // [esp+34h] [ebp-8h]
  DNameNode lowerBase; // [esp+38h] [ebp-4h]
  struct GTessellator::ScanChainType *styleAbovea; // [esp+44h] [ebp+8h]

  v4 = *((_DWORD *)styleAbove + 1);
  v5 = *(struct GTessellator::ScanChainType **)(v4 + 16);
  v7 = *(DNameNode_vtbl **)(v4 + 20);
  *(_DWORD *)(v4 + 20) = 0;
  getLastChar = v7[1].getLastChar;
  v27 = *((int **)styleAbove + 1);
  lowerBase.__vftable = v7;
  styleAbovea = v5;
  length = (unsigned int)v7[1].length;
  getString = v7[1].getString;
  v26 = *(_DWORD *)(*(&(*(this + 84))->attributes + ((unsigned int)getLastChar >> 4))
                  + 8 * ((unsigned __int8)getLastChar & 0xF));
  GTessellator::growMonotone(this, m: v27, vertex: v26);
  GTessellator::growMonotone(this, m: *((int **)styleAbove + 1), vertex: targetVertex);
  while ( getString != nullptr )
  {
    v9 = (int)*(this + 84);
    getString = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)getString - 1);
    v10 = v26;
    v11 = *(_DWORD *)(v9 + 4 * ((unsigned int)getLastChar >> 4));
    v12 = (unsigned __int8)getLastChar & 0xF;
    getLastChar = (char (__thiscall *)(DNameNode *))((char *)getLastChar + 1);
    v25 = v26;
    v21 = getLastChar;
    v24 = v11 + 8 * v12;
    if ( getString != nullptr )
      v26 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * ((unsigned int)getLastChar >> 4)) + 8
                                                                               * ((unsigned __int8)getLastChar & 0xF));
    else
      v26 = length;
    v13 = *(_DWORD *)(v24 + 4);
    if ( v13 != 0 )
      v14 = *(struct GTessellator::ScanChainType **)(v13 + 16);
    else
      v14 = nullptr;
    if ( v10 != v26 )
    {
      if ( v14 != styleAbovea || *(_DWORD *)(v24 + 4) == 0 )
      {
        v15 = (unsigned int)*(this + 85) >> 6;
        if ( v15 >= (unsigned int)*(this + 86) )
        {
          GArrayPagedBase<GTessellator::MonotoneType,6,64,GAllocatorPagedLH_POD<GTessellator::MonotoneType,133>>::allocatePage(
            this: (unsigned int *)this + 85,
            a2: (unsigned int)*(this + 85) >> 6);
          v10 = v25;
        }
        v16 = (_DWORD *)(*(&(*(this + 88))->attributes + v15) + 24 * ((unsigned int)*(this + 85) & 0x3F));
        *v16 = 0;
        v16[1] = -1;
        v16[2] = -1;
        v16[3] = -1;
        v16[4] = styleAbovea;
        v16[5] = 0;
        *(this + 85) = (GTessellator)((char *)*(this + 85) + 1);
        v17 = (int *)(*(&(*(this + 88))->attributes + (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) >> 6))
                    + 24 * (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) & 0x3F));
        *(_DWORD *)(v24 + 4) = v17;
        if ( v10 != -1 )
          GTessellator::growMonotone(this, m: v17, vertex: v10 | 0x40000000);
        if ( v26 != -1 )
          GTessellator::growMonotone(this, m: v17, vertex: v26 & 0xBFFFFFFF);
        getLastChar = v21;
      }
      v18 = *(int **)(v24 + 4);
      if ( targetVertex != -1 )
      {
        GTessellator::growMonotone(this, m: v18, vertex: targetVertex | 0x40000000);
        GTessellator::growMonotone(this, m: v18, vertex: targetVertex & 0xBFFFFFFF);
      }
    }
  }
  if ( lowerBase.__vftable == (DNameNode_vtbl *)(*(&(*(this + 80))->attributes
                                                 + (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) >> 4))
                                               + 28
                                               * (((unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3) & 0xF)) )
  {
    v19 = (const _s__ThrowInfo *)lowerBase.__vftable[1].getLastChar;
    if ( v19 < *(this + 81) )
      *(this + 81) = v19;
    v20 = (int)*(this + 77);
    if ( v20 != 0 )
      *(this + 77) = (GTessellator)(v20 - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F360
// Name: private: void GTessellator::connectStartingToLeft(struct GTessellator::ScanChainType __near *,struct GTessellator::BaseLineType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::connectStartingToLeft(
        DNameNode *this,
        unsigned int scan,
        _DWORD *upperBase,
        void (__thiscall *targetVertex)(void *))
{
  int v5; // ecx
  unsigned int v6; // edi
  int *started; // ebx
  int *v8; // eax
  _DWORD *v9; // eax
  int *v10; // eax
  int *v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // [esp+10h] [ebp-28h]
  int v16; // [esp+14h] [ebp-24h]
  int v17; // [esp+18h] [ebp-20h]
  int v18; // [esp+20h] [ebp-18h]
  int v19; // [esp+24h] [ebp-14h]
  DNameNode *v20; // [esp+28h] [ebp-10h]
  char v21; // [esp+2Ch] [ebp-Ch]
  int *m; // [esp+30h] [ebp-8h]
  unsigned int ma; // [esp+30h] [ebp-8h]
  int v24; // [esp+34h] [ebp-4h]
  DNameNode *styleBelow; // [esp+40h] [ebp+8h]

  v5 = upperBase[6];
  v6 = scan;
  if ( v5 == -1 )
    v24 = scan;
  else
    v24 = *((_DWORD *)this + 74) + 12 * v5;
  v16 = upperBase[5];
  v17 = upperBase[3];
  v15 = upperBase[4];
  v18 = upperBase[2];
  v19 = *(_DWORD *)(*((_DWORD *)this + 74) + 12 * v15 + 8);
  styleBelow = *(DNameNode **)(*(_DWORD *)(scan + 4) + 16);
  v20 = (DNameNode *)upperBase[1];
  v21 = 1;
  started = (int *)GTessellator::startMonotone((unsigned int *)this, result: nullptr);
  v8 = *(int **)(v6 + 4);
  *started = *v8;
  started[1] = v8[1];
  started[2] = v8[2];
  started[3] = v8[3];
  started[4] = v8[4];
  started[5] = v8[5];
  v9 = *(_DWORD **)(v6 + 4);
  v9[1] = -1;
  v9[2] = -1;
  v9[3] = -1;
  *v9 = 0;
  v9[4] = styleBelow;
  v9[5] = 0;
  while ( 1 )
  {
    if ( v16 != 0 )
    {
      if ( v18 != v19 )
      {
        GTessellator::replaceMonotone(this, pe: (const DNameNode *)v6, style: styleBelow);
        m = *(int **)(v6 + 4);
        if ( targetVertex != (void (__thiscall *)(void *))-1 )
        {
          GTessellator::growMonotone(this, m: *(int **)(v6 + 4), vertex: (unsigned int)targetVertex | 0x40000000);
          GTessellator::growMonotone(this, m, vertex: (unsigned int)targetVertex & 0xBFFFFFFF);
        }
        v10 = *(int **)(v6 + 4);
        ma = (unsigned int)v10;
        if ( v18 != -1 )
        {
          GTessellator::growMonotone(this, m: v10, vertex: v18 | 0x40000000);
          v10 = (int *)ma;
        }
        if ( v19 != -1 )
          GTessellator::growMonotone(this, m: v10, vertex: v19 & 0xBFFFFFFF);
      }
    }
    else
    {
      *(_DWORD *)(v6 + 4) = started;
      if ( v18 != -1 )
        GTessellator::growMonotone(this, m: started, vertex: v18 | 0x40000000);
      if ( v19 != -1 )
        GTessellator::growMonotone(this, m: started, vertex: v19 & 0xBFFFFFFF);
    }
    if ( v20 != styleBelow || *(_DWORD *)(v6 + 4) == 0 )
    {
      if ( *((_BYTE *)&v20->__vftable + *((_DWORD *)this + 9)) != 0 )
      {
        if ( v21 != 0 )
          v6 = v24;
        GTessellator::replaceMonotone(this, pe: (const DNameNode *)v6, style: v20);
        v11 = *(int **)(v6 + 4);
        if ( v18 != -1 )
          GTessellator::growMonotone(this, m: v11, vertex: v18 | 0x40000000);
        if ( v19 != -1 )
          GTessellator::growMonotone(this, m: v11, vertex: v19 & 0xBFFFFFFF);
      }
      else
      {
        *(_DWORD *)(v6 + 4) = 0;
      }
    }
    v21 = 0;
    if ( v16 == 0 )
      break;
    --v16;
    v12 = *((_DWORD *)this + 74);
    v18 = v19;
    v13 = v15 + 1;
    v14 = 3 * v15++;
    v6 = v12 + 4 * v14;
    if ( v16 != 0 )
      v19 = *(_DWORD *)(v12 + 12 * v13 + 8);
    else
      v19 = v17;
    v20 = *(DNameNode **)(*(_DWORD *)v6 + 40);
  }
  upperBase[5] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018F5B0
// Name: private: void GTessellator::connectStartingToRight(struct GTessellator::ScanChainType __near *,struct GTessellator::BaseLineType __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::connectStartingToRight(
        DNameNode *this,
        unsigned int scan,
        _DWORD *upperBase,
        void (__thiscall *targetVertex)(void *))
{
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // ebx
  int *v8; // eax
  int v9; // ecx
  int *v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+14h] [ebp-24h]
  int v16; // [esp+18h] [ebp-20h]
  int v17; // [esp+24h] [ebp-14h]
  DNameNode *v18; // [esp+28h] [ebp-10h]
  char v19; // [esp+2Ch] [ebp-Ch]
  unsigned int m; // [esp+30h] [ebp-8h]
  int *ma; // [esp+30h] [ebp-8h]
  unsigned int mb; // [esp+30h] [ebp-8h]
  int v23; // [esp+34h] [ebp-4h]
  DNameNode *styleBelow; // [esp+40h] [ebp+8h]

  v5 = upperBase[6];
  v6 = scan;
  if ( v5 == -1 )
    v23 = scan;
  else
    v23 = *((_DWORD *)this + 74) + 12 * v5;
  v7 = upperBase[2];
  v15 = upperBase[5];
  v14 = upperBase[4];
  v16 = upperBase[3];
  v17 = *(_DWORD *)(*((_DWORD *)this + 74) + 12 * v14 + 8);
  v18 = (DNameNode *)upperBase[1];
  v19 = 1;
  styleBelow = *(DNameNode **)(*(_DWORD *)(scan + 4) + 16);
  while ( 1 )
  {
    if ( v19 != 0 )
    {
      v8 = *(int **)(v6 + 4);
      m = (unsigned int)v8;
      if ( v7 != -1 )
      {
        GTessellator::growMonotone(this, m: v8, vertex: v7 | 0x40000000);
        v8 = (int *)m;
      }
      v9 = v17;
      if ( v17 != -1 )
        goto LABEL_17;
    }
    else if ( v7 != v17 )
    {
      GTessellator::replaceMonotone(this, pe: (const DNameNode *)v6, style: styleBelow);
      ma = *(int **)(v6 + 4);
      if ( targetVertex != (void (__thiscall *)(void *))-1 )
      {
        GTessellator::growMonotone(this, m: *(int **)(v6 + 4), vertex: (unsigned int)targetVertex | 0x40000000);
        GTessellator::growMonotone(this, m: ma, vertex: (unsigned int)targetVertex & 0xBFFFFFFF);
      }
      v8 = *(int **)(v6 + 4);
      mb = (unsigned int)v8;
      if ( v7 != -1 )
      {
        GTessellator::growMonotone(this, m: v8, vertex: v7 | 0x40000000);
        v8 = (int *)mb;
      }
      if ( v17 != -1 )
      {
        v9 = v17;
LABEL_17:
        GTessellator::growMonotone(this, m: v8, vertex: v9 & 0xBFFFFFFF);
      }
    }
    if ( v18 != styleBelow || *(_DWORD *)(v6 + 4) == 0 )
    {
      if ( *((_BYTE *)&v18->__vftable + *((_DWORD *)this + 9)) != 0 )
      {
        if ( v19 != 0 )
          v6 = v23;
        GTessellator::replaceMonotone(this, pe: (const DNameNode *)v6, style: v18);
        v10 = *(int **)(v6 + 4);
        if ( v7 != -1 )
          GTessellator::growMonotone(this, m: v10, vertex: v7 | 0x40000000);
        if ( v17 != -1 )
          GTessellator::growMonotone(this, m: v10, vertex: v17 & 0xBFFFFFFF);
      }
      else
      {
        *(_DWORD *)(v6 + 4) = 0;
      }
    }
    v19 = 0;
    if ( v15 == 0 )
      break;
    --v15;
    v11 = *((_DWORD *)this + 74);
    v7 = v17;
    v12 = v14 + 1;
    v13 = 3 * v14++;
    v6 = v11 + 4 * v13;
    if ( v15 != 0 )
      v17 = *(_DWORD *)(v11 + 12 * v12 + 8);
    else
      v17 = v16;
    v18 = *(DNameNode **)(*(_DWORD *)v6 + 40);
  }
  upperBase[5] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018F790
// Name: private: void GTessellator::connectStartingToPending(struct GTessellator::ScanChainType __near *,struct GTessellator::BaseLineType __near *)
// Source: json
//------------------------------------------------------------------------------
DNameNode_vtbl *__thiscall GTessellator::connectStartingToPending(
        GTessellator *this,
        DNameNode *styleBetween,
        DNameNode upperBase)
{
  DNameNode_vtbl *v5; // eax
  DNameNode_vtbl *getString; // ebx
  DNameNode *getLastChar; // edx
  char (__thiscall *v8)(DNameNode *); // eax
  char *(__thiscall *v9)(DNameNode *, char *, char *); // edi
  int v10; // edx
  unsigned int v11; // eax
  char (__thiscall *v12)(DNameNode *); // edx
  char (__thiscall *v13)(DNameNode *); // edi
  int (__thiscall *v14)(DNameNode *); // edx
  char *(__thiscall *v15)(DNameNode *, char *, char *); // ecx
  char (__thiscall *v16)(DNameNode *); // eax
  int (__thiscall *v17)(DNameNode *); // edx
  char *(__thiscall *v18)(DNameNode *, char *, char *); // ecx
  int *v19; // eax
  int *v20; // eax
  DNameNode *v21; // eax
  int *v22; // eax
  char v23; // al
  char (__thiscall *v24)(DNameNode *); // edx
  int v25; // ecx
  DNameNode_vtbl *v26; // eax
  int v27; // ecx
  int v28; // eax
  DNameNode *v29; // eax
  DNameNode v30; // eax
  DNameNode *v31; // ecx
  char *(__thiscall *v32)(DNameNode *, char *, char *); // ebx
  int v33; // ecx
  const DNameNode *v34; // edi
  DNameNode_vtbl *v35; // eax
  DNameNode *started; // eax
  DNameNode_vtbl *v37; // ecx
  DNameNode *v38; // edx
  DNameNode_vtbl *v39; // eax
  char *(__thiscall *v40)(DNameNode *, char *, char *); // edx
  int *v41; // eax
  int *v42; // ebx
  unsigned int v43; // eax
  int *v44; // eax
  int *v45; // ebx
  int *v46; // ebx
  int *v47; // edi
  int v48; // ecx
  char *v49; // ebx
  int v50; // eax
  int (__thiscall *v51)(DNameNode *); // ecx
  DNameNode v52; // ecx
  unsigned int v53; // ecx
  DNameNode_vtbl *result; // eax
  const _s__ThrowInfo *v55; // ebx
  int v56; // eax
  GTessellator *v57; // [esp+Ch] [ebp-60h] BYREF
  char (__thiscall *v58)(DNameNode *); // [esp+10h] [ebp-5Ch]
  char *(__thiscall *v59)(DNameNode *, char *, char *); // [esp+14h] [ebp-58h]
  int (__thiscall *length)(DNameNode *); // [esp+18h] [ebp-54h]
  DNameNode *pe; // [esp+1Ch] [ebp-50h]
  unsigned int v62; // [esp+20h] [ebp-4Ch]
  unsigned int v63; // [esp+24h] [ebp-48h]
  char (__thiscall *v64)(DNameNode *); // [esp+28h] [ebp-44h]
  char v65; // [esp+2Ch] [ebp-40h]
  char *v66; // [esp+34h] [ebp-38h]
  char *(__thiscall *v67)(DNameNode *, char *, char *); // [esp+38h] [ebp-34h]
  int (__thiscall *v68)(DNameNode *); // [esp+3Ch] [ebp-30h]
  DNameNode *v69; // [esp+40h] [ebp-2Ch]
  char *(__thiscall *v70)(DNameNode *, char *, char *); // [esp+44h] [ebp-28h]
  int (__thiscall *v71)(DNameNode *); // [esp+48h] [ebp-24h]
  DNameNode *v72; // [esp+4Ch] [ebp-20h]
  _DWORD v73[2]; // [esp+54h] [ebp-18h] BYREF
  DNameNode lowerBase; // [esp+5Ch] [ebp-10h]
  int *v75; // [esp+60h] [ebp-Ch]
  int *v76; // [esp+64h] [ebp-8h]
  unsigned int stopNum; // [esp+68h] [ebp-4h]
  DNameNode *styleBetweena; // [esp+74h] [ebp+8h]

  v5 = styleBetween[1].__vftable;
  getString = (DNameNode_vtbl *)v5[1].getString;
  getLastChar = (DNameNode *)v5[1].getLastChar;
  v5[1].getString = nullptr;
  v73[0] = getString->getString;
  styleBetweena = getLastChar;
  v73[1] = styleBetween[1].__vftable;
  v8 = getString[1].getLastChar;
  v59 = getString[1].getString;
  length = getString[1].length;
  pe = (DNameNode *)v73;
  v9 = getString->getString;
  v57 = this + 81;
  v10 = (int)*(this + 84);
  v62 = (unsigned int)v9;
  v58 = v8;
  v11 = *(_DWORD *)(*(_DWORD *)(v10 + 4 * ((unsigned int)v8 >> 4)) + 8 * ((unsigned __int8)v8 & 0xF));
  v12 = getString->getLastChar;
  v63 = v11;
  v13 = upperBase.__vftable[1].getLastChar;
  v64 = v12;
  v67 = upperBase.__vftable[1].getString;
  v14 = upperBase.__vftable[1].length;
  v69 = styleBetween;
  v15 = upperBase.getString;
  v16 = upperBase.getLastChar;
  v68 = v14;
  v70 = v15;
  v17 = *((int (__thiscall **)(DNameNode *))&(*(this + 74))->pForwardCompat + 3 * (_DWORD)v13);
  v72 = (DNameNode *)v16;
  lowerBase.__vftable = getString;
  v65 = 1;
  v71 = v17;
  stopNum = (unsigned int)v59 < (unsigned int)v67;
  while ( 1 )
  {
    if ( (v18 = v70, v62 == v63)
      && (v70 == (char *(__thiscall *)(DNameNode *, char *, char *))-1 || v71 == (int (__thiscall *)(DNameNode *))-1)
      || (char *)v70 == (char *)v71 && (v62 == -1 || v63 == -1)
      || v62 == v63 && (char *)v70 == (char *)v71 )
    {
      v21 = v69;
    }
    else
    {
      if ( (char *)v64 != (char *)styleBetweena )
      {
        GTessellator::replaceMonotone((DNameNode *)this, pe, style: styleBetweena);
        v19 = (int *)pe[1].__vftable;
        v76 = v19;
        if ( v62 != -1 )
        {
          GTessellator::growMonotone(this, m: v19, vertex: v62 | 0x40000000);
          v19 = v76;
        }
        if ( v63 != -1 )
          GTessellator::growMonotone(this, m: v19, vertex: v63 & 0xBFFFFFFF);
        v18 = v70;
      }
      v20 = (int *)pe[1].__vftable;
      v76 = v20;
      if ( v18 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
      {
        GTessellator::growMonotone(this, m: v20, vertex: (unsigned int)v18 | 0x40000000);
        v20 = v76;
      }
      if ( v71 != (int (__thiscall *)(DNameNode *))-1 )
        GTessellator::growMonotone(this, m: v20, vertex: (unsigned int)v71 & 0xBFFFFFFF);
      v21 = v69;
      v69[1].__vftable = pe[1].__vftable;
    }
    if ( v72 != styleBetweena || v21[1].__vftable == nullptr )
    {
      if ( *((_BYTE *)&(*(this + 9))->attributes + (_DWORD)v72) != 0 )
      {
        GTessellator::replaceMonotone((DNameNode *)this, pe: v21, style: v72);
        v22 = (int *)v69[1].__vftable;
        v76 = v22;
        if ( v70 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
        {
          GTessellator::growMonotone(this, m: v22, vertex: (unsigned int)v70 | 0x40000000);
          v22 = v76;
        }
        if ( v71 != (int (__thiscall *)(DNameNode *))-1 )
          GTessellator::growMonotone(this, m: v22, vertex: (unsigned int)v71 & 0xBFFFFFFF);
      }
      else
      {
        v21[1].__vftable = nullptr;
      }
    }
    if ( v59 == (char *(__thiscall *)(DNameNode *, char *, char *))stopNum )
      break;
    v65 = 0;
    if ( v59 != nullptr )
    {
      v59 = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)v59 - 1);
      v23 = (char)v58;
      v62 = v63;
      v24 = v58;
      v58 = (char (__thiscall *)(DNameNode *))((char *)v58 + 1);
      v25 = (int)*(this + 84);
      pe = (DNameNode *)(*(_DWORD *)(v25 + 4 * ((unsigned int)v24 >> 4)) + 8 * (v23 & 0xF));
      if ( v59 != nullptr )
        v63 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * ((unsigned int)v58 >> 4)) + 8 * ((unsigned __int8)v58 & 0xF));
      else
        v63 = (unsigned int)length;
      v26 = pe[1].__vftable;
      if ( v26 != nullptr )
        v64 = v26[1].getLastChar;
      else
        v64 = nullptr;
    }
    if ( v67 != nullptr )
    {
      v27 = (int)*(this + 74);
      v70 = (char *(__thiscall *)(DNameNode *, char *, char *))v71;
      v28 = 3 * (_DWORD)v13;
      v13 = (char (__thiscall *)(DNameNode *))((char *)v13 + 1);
      v29 = (DNameNode *)(v27 + 4 * v28);
      v67 = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)v67 - 1);
      v69 = v29;
      if ( v67 != nullptr )
      {
        v30.__vftable = v29->__vftable;
        v71 = *(int (__thiscall **)(DNameNode *))(v27 + 12 * (_DWORD)v13 + 8);
        v72 = (DNameNode *)v30.__vftable[3].getLastChar;
      }
      else
      {
        v31 = (DNameNode *)v29->__vftable[3].getLastChar;
        v71 = v68;
        v72 = v31;
      }
    }
  }
  stopNum = v62;
  if ( v63 != -1 )
    stopNum = v63;
  if ( v67 != nullptr && stopNum != -1 )
  {
    v76 = nullptr;
    GTessBaseLineIterator<GArrayPagedLH_POD<GTessellator::PendingEndType,4,16,133>>::Next<int (__cdecl *)(GTessellator::PendingEndType const *)>(
      this: &v57,
      a2: (int (__cdecl *)(int))GTessellator::pendingMonotoneStyle);
    v67 = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)v67 - 1);
    v32 = (char *(__thiscall *)(DNameNode *, char *, char *))v71;
    v33 = (int)*(this + 74);
    v66 = (char *)v13 + 1;
    v70 = (char *(__thiscall *)(DNameNode *, char *, char *))v71;
    v34 = (const DNameNode *)(v33 + 12 * (_DWORD)v13);
    if ( v67 != nullptr )
      v71 = *(int (__thiscall **)(DNameNode *))(v33 + 12 * (_DWORD)v66 + 8);
    else
      v71 = v68;
    v72 = (DNameNode *)v34->__vftable[3].getLastChar;
    v35 = pe[1].__vftable;
    if ( v35 != nullptr && (DNameNode *)v35[1].getLastChar == styleBetweena )
    {
      started = GTessellator::startMonotone((unsigned int *)this, result: styleBetweena);
      v37 = pe[1].__vftable;
      started->__vftable = (DNameNode_vtbl *)v37->length;
      started[1].__vftable = (DNameNode_vtbl *)v37->getLastChar;
      started[2].__vftable = (DNameNode_vtbl *)v37->getString;
      started[3].__vftable = (DNameNode_vtbl *)v37[1].length;
      started[4].__vftable = (DNameNode_vtbl *)v37[1].getLastChar;
      v38 = pe;
      started[5].__vftable = (DNameNode_vtbl *)v37[1].getString;
      v76 = (int *)started;
      v39 = v38[1].__vftable;
      v39->getLastChar = (char (__thiscall *)(DNameNode *))-1;
      v39->getString = (char *(__thiscall *)(DNameNode *, char *, char *))-1;
      v39[1].length = (int (__thiscall *)(DNameNode *))-1;
      v39->length = nullptr;
      v39[1].getLastChar = (char (__thiscall *)(DNameNode *))styleBetweena;
      v39[1].getString = nullptr;
    }
    v40 = v67;
    while ( 1 )
    {
      if ( v40 != nullptr )
      {
        if ( (char *)v32 != (char *)v71 )
        {
          GTessellator::replaceMonotone((DNameNode *)this, pe: v34, style: styleBetweena);
          v45 = (int *)v34[1].__vftable;
          GTessellator::growMonotone(this, m: v45, vertex: stopNum | 0x40000000);
          GTessellator::growMonotone(this, m: v45, vertex: stopNum & 0xBFFFFFFF);
          v46 = (int *)v34[1].__vftable;
          if ( v70 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
            GTessellator::growMonotone(this, m: v46, vertex: (unsigned int)v70 | 0x40000000);
          if ( v71 != (int (__thiscall *)(DNameNode *))-1 )
            GTessellator::growMonotone(this, m: v46, vertex: (unsigned int)v71 & 0xBFFFFFFF);
          v32 = v70;
        }
      }
      else
      {
        v41 = v76;
        v34[1].__vftable = (DNameNode_vtbl *)v76;
        if ( v41 == nullptr )
        {
          v42 = (int *)GTessellator::startMonotone((unsigned int *)this, result: styleBetweena);
          v43 = v62;
          v34[1].__vftable = (DNameNode_vtbl *)v42;
          if ( v43 != -1 )
            GTessellator::growMonotone(this, m: v42, vertex: v43 | 0x40000000);
          if ( v63 != -1 )
            GTessellator::growMonotone(this, m: v42, vertex: v63 & 0xBFFFFFFF);
          v32 = v70;
        }
        v44 = (int *)v34[1].__vftable;
        v75 = v44;
        if ( v32 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
        {
          GTessellator::growMonotone(this, m: v44, vertex: (unsigned int)v32 | 0x40000000);
          v44 = v75;
        }
        if ( v71 != (int (__thiscall *)(DNameNode *))-1 )
          GTessellator::growMonotone(this, m: v44, vertex: (unsigned int)v71 & 0xBFFFFFFF);
      }
      if ( v72 != styleBetweena || v34[1].__vftable == nullptr )
      {
        if ( *((_BYTE *)&(*(this + 9))->attributes + (_DWORD)v72) != 0 )
        {
          GTessellator::replaceMonotone((DNameNode *)this, pe: v34, style: v72);
          v47 = (int *)v34[1].__vftable;
          if ( v32 != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
            GTessellator::growMonotone(this, m: v47, vertex: (unsigned int)v32 | 0x40000000);
          if ( v71 != (int (__thiscall *)(DNameNode *))-1 )
            GTessellator::growMonotone(this, m: v47, vertex: (unsigned int)v71 & 0xBFFFFFFF);
        }
        else
        {
          v34[1].__vftable = nullptr;
        }
      }
      if ( v67 == nullptr )
        break;
      v48 = (int)*(this + 74);
      v70 = (char *(__thiscall *)(DNameNode *, char *, char *))v71;
      v40 = (char *(__thiscall *)(DNameNode *, char *, char *))((char *)v67 - 1);
      v49 = v66 + 1;
      v50 = 3 * (_DWORD)v66;
      v67 = v40;
      ++v66;
      v34 = (const DNameNode *)(v48 + 4 * v50);
      if ( v40 != nullptr )
      {
        v51 = *(int (__thiscall **)(DNameNode *))(v48 + 12 * (_DWORD)v49 + 8);
        v32 = v70;
        v71 = v51;
        v72 = (DNameNode *)v34->__vftable[3].getLastChar;
      }
      else
      {
        v52.__vftable = v34->__vftable;
        v32 = v70;
        v71 = v68;
        v72 = (DNameNode *)v52.__vftable[3].getLastChar;
      }
    }
    getString = lowerBase.__vftable;
  }
  v53 = (unsigned int)&(*(this + 77))[-1].pCatchableTypeArray + 3;
  result = (DNameNode_vtbl *)*(&(*(this + 80))->attributes + (v53 >> 4));
  if ( getString == (DNameNode_vtbl *)((char *)result + 28 * (v53 & 0xF)) )
  {
    v55 = (const _s__ThrowInfo *)getString[1].getLastChar;
    if ( v55 < *(this + 81) )
      *(this + 81) = v55;
    v56 = (int)*(this + 77);
    if ( v56 != 0 )
    {
      result = (DNameNode_vtbl *)(v56 - 1);
      *(this + 77) = (GTessellator)result;
    }
    else
    {
      result = upperBase.__vftable;
    }
    upperBase.__vftable[1].getString = nullptr;
  }
  else
  {
    upperBase.__vftable[1].getString = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018FD60
// Name: private: void GTessellator::connectStarting(struct GTessellator::ScanChainType __near *,struct GTessellator::BaseLineType __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::connectStarting(
        GTessellator *this,
        struct GTessellator::ScanChainType *scan,
        DNameNode upperBase)
{
  struct GTessellator::ScanChainType *v3; // ebx
  int v5; // eax
  unsigned int v6; // eax
  unsigned int getString; // esi
  DNameNode_vtbl *v8; // eax
  unsigned int length; // ecx
  char *v10; // [esp+0h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v3 = scan;
  if ( scan == nullptr )
    goto LABEL_30;
  v5 = *((_DWORD *)scan + 1);
  if ( v5 == 0 )
    goto LABEL_30;
  v6 = *(_DWORD *)(v5 + 4);
  if ( v6 == -1 )
    getString = -1;
  else
    getString = *(_DWORD *)(*(&(*(this + 92))->attributes + (v6 >> 10)) + 8 * (v6 & 0x3FF));
  v8 = upperBase.__vftable;
  upperBase.getString = (char *(__thiscall *)(DNameNode *, char *, char *))-1;
  upperBase.__vftable[1].length = (int (__thiscall *)(DNameNode *))-1;
  i = 0;
  while ( getString != -1 )
  {
    if ( *(float *)&upperBase.length > (double)*(float *)(*(&(*(this + 68))->attributes
                                                          + ((getString & 0xBFFFFFFF) >> 10))
                                                        + 8 * (getString & 0x3FF)
                                                        + 4) )
    {
      v3 = scan;
      v8 = upperBase.__vftable;
      break;
    }
    if ( (getString & 0x40000000) != 0 )
      upperBase.getString = (char *(__thiscall *)(DNameNode *, char *, char *))(getString & 0xBFFFFFFF);
    else
      upperBase.__vftable[1].length = (int (__thiscall *)(DNameNode *))getString;
    v3 = scan;
    GTessellator::removeLastMonoVertex((DNameStatusNode *)this, m: *((char **)scan + 1), a3: v10);
    if ( *(_DWORD *)(*((_DWORD *)scan + 1) + 4) == -1 )
      getString = -1;
    else
      getString = *(_DWORD *)(*(&(*(this + 92))->attributes + (*(_DWORD *)(*((_DWORD *)scan + 1) + 4) >> 10))
                            + 8 * (*(_DWORD *)(*((_DWORD *)scan + 1) + 4) & 0x3FF));
    if ( ++i >= 2 )
    {
      v8 = upperBase.__vftable;
      break;
    }
    v8 = upperBase.__vftable;
  }
  if ( *(_DWORD *)(*((_DWORD *)v3 + 1) + 20) != 0 )
  {
    GTessellator::connectStartingToPending(this, styleBetween: (DNameNode *)v3, upperBase: (DNameNode)v8);
    return;
  }
  if ( getString == -1 )
  {
    length = (unsigned int)v8[1].length;
    if ( length != -1 )
    {
      getString = (unsigned int)v8[1].length;
      v8[1].length = (int (__thiscall *)(DNameNode *))-1;
      GTessellator::growMonotone(this, m: *((int **)v3 + 1), vertex: length);
LABEL_26:
      v8 = upperBase.__vftable;
      goto LABEL_27;
    }
    if ( v8->getString != (char *(__thiscall *)(DNameNode *, char *, char *))-1 )
    {
      getString = (unsigned int)v8->getString;
      v8->getString = (char *(__thiscall *)(DNameNode *, char *, char *))-1;
      GTessellator::growMonotone(this, m: *((int **)v3 + 1), vertex: getString);
      goto LABEL_26;
    }
  }
LABEL_27:
  if ( (getString & 0x40000000) != 0 )
  {
    GTessellator::connectStartingToLeft(
      (DNameNode *)this,
      scan: (unsigned int)v3,
      upperBase: v8,
      targetVertex: (void (__thiscall *)(void *))(getString & 0xBFFFFFFF));
    upperBase.__vftable[1].getString = nullptr;
    return;
  }
  GTessellator::connectStartingToRight(
    (DNameNode *)this,
    scan: (unsigned int)v3,
    upperBase: v8,
    targetVertex: (void (__thiscall *)(void *))getString);
LABEL_30:
  upperBase.__vftable[1].getString = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1018FEF0
// Name: public: void GTessellator::AddShape(class GCompoundShape const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::AddShape(GTessellator *this, const struct GCompoundShape *a2, int addStyle)
{
  const struct GCompoundShape *v3; // eax
  unsigned int i; // ebx
  int v5; // eax
  const _s__ThrowInfo *v6; // esi
  const _s__ThrowInfo *v7; // edi

  v3 = a2;
  for ( i = 0; i < *((_DWORD *)a2 + 6); ++i )
  {
    v5 = *(_DWORD *)(*((_DWORD *)v3 + 9) + 4 * (i >> 6)) + 24 * (i & 0x3F);
    v6 = (const _s__ThrowInfo *)(addStyle + *(_DWORD *)(v5 + 12));
    v7 = (const _s__ThrowInfo *)(addStyle + *(_DWORD *)(v5 + 16));
    if ( v6 != v7 )
    {
      GTessellator::addPath(this, a2: (const struct GCompoundShape::SPath *)v5, a3: addStyle);
      if ( v6 > *(this + 55) )
        *(this + 55) = v6;
      if ( v7 > *(this + 55) )
        *(this + 55) = v7;
    }
    v3 = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FF70
// Name: private: void GTessellator::prepareChainsAndScanbeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::prepareChainsAndScanbeams(GTessellator *this)
{
  GTessellator *v2; // ebx
  double v3; // st6
  double v4; // st6
  double v5; // st6
  double v6; // st5
  double v7; // st6
  double v8; // st6
  float v9; // eax
  unsigned int v10; // edi
  double v11; // st7
  unsigned int v12; // ecx
  int v13; // edx
  double v14; // st6
  int v15; // edx
  unsigned int v16; // edi
  const _s__ThrowInfo *v17; // ebx
  GTessellator *v18; // edi
  const _s__ThrowInfo *v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // edx
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  float v23; // [esp+10h] [ebp-8h]
  float v24; // [esp+14h] [ebp-4h]

  v2 = this + 31;
  G_QuickSortSliced<GArrayPagedLH_POD<unsigned int,10,64,133>,GTessellator::CmpScanbeams>(
    a1: (int)(this + 31),
    a2: 0,
    a3: (int)*(this + 31),
    a4: (int)(this + 12));
  v3 = *((float *)this + 56);
  if ( v3 < 0.0 )
    v3 = -v3;
  v23 = v3;
  v4 = *((float *)this + 58);
  if ( v4 < 0.0 )
    v4 = -v4;
  v24 = v4;
  v5 = v24;
  if ( v23 >= (double)v24 )
    v5 = v23;
  v23 = v5;
  *((float *)this + 60) = v23 * 0.000009999999747378752;
  v6 = *((float *)this + 57);
  if ( v6 < 0.0 )
    v6 = -v6;
  v23 = v6;
  v7 = *((float *)this + 59);
  if ( v7 < 0.0 )
    v7 = -v7;
  v24 = v7;
  v8 = v24;
  if ( v23 >= (double)v24 )
    v8 = v23;
  v23 = v8;
  v9 = 0.0;
  v10 = 0;
  v22 = 0;
  v24 = 0.0;
  *((float *)this + 61) = 0.000009999999747378752 * v23;
  v23 = -1.0e30;
  if ( *v2 != nullptr )
  {
    v11 = v23;
    do
    {
      v12 = *(_DWORD *)(*(&(*(this + 34))->attributes + (LODWORD(v9) >> 10)) + 4 * (LOWORD(v9) & 0x3FF));
      v13 = *(&(*(this + 15))->attributes + (v12 >> 10));
      v14 = *(float *)(v13 + 8 * (v12 & 0x3FF) + 4);
      v15 = v13 + 8 * (v12 & 0x3FF);
      if ( *((float *)this + 61) >= v14 - v11 )
      {
        *(float *)(v15 + 4) = v11;
      }
      else
      {
        *(_DWORD *)(*(&(*(this + 34))->attributes + (v10 >> 10)) + 4 * (v10 & 0x3FF)) = v12;
        v23 = *(float *)(v15 + 4);
        v11 = v23;
        v10 = ++v22;
      }
      LODWORD(v9) = LODWORD(v24) + 1;
      v2 = this + 31;
      v24 = v9;
    }
    while ( LODWORD(v9) < (unsigned int)*(this + 31) );
  }
  if ( v10 < (unsigned int)*v2 )
    *v2 = (GTessellator)v10;
  v16 = 0;
  if ( *(this + 16) != nullptr )
  {
    do
    {
      GTessellator::decomposePath(
        (pairNode *)this,
        min: (int *)(*(&(*(this + 19))->attributes + (v16 >> 6)) + 16 * (v16 & 0x3F)));
      ++v16;
    }
    while ( v16 < (unsigned int)*(this + 16) );
  }
  v17 = *(this + 24);
  v18 = this + 28;
  if ( v17 > *(this + 30) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*v18);
    *(this + 30) = v17 + 2;
    if ( v17 == (const _s__ThrowInfo *)-32 )
    {
      v19 = nullptr;
    }
    else
    {
      v22 = 133;
      v19 = (const _s__ThrowInfo *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                     this: GMemory::pGlobalHeap,
                                     a2: this + 28,
                                     a3: 4 * (_DWORD)(v17 + 2),
                                     a4: &v22);
    }
    *v18 = v19;
  }
  v20 = 0;
  *(this + 29) = v17;
  if ( *(this + 24) != nullptr )
  {
    do
    {
      v21 = *(&(*(this + 27))->attributes + (v20 >> 6)) + 56 * (v20 & 0x3F);
      v18 = this + 28;
      *(float *)(v21 + 4) = *(float *)(*(&(*(this + 15))->attributes + (**(_DWORD **)v21 >> 10))
                                     + 8 * (**(_DWORD **)v21 & 0x3FF)
                                     + 4);
      *(&(*(this + 28))->attributes + v20++) = v21;
    }
    while ( v20 < (unsigned int)*(this + 24) );
  }
  G_QuickSortSliced<GArrayUnsafeLH_POD<GTessellator::MonoChainType *,133>,bool (__cdecl *)(GTessellator::MonoChainType const *,GTessellator::MonoChainType const *)>(
    a1: (int *)v18,
    a2: 0,
    a3: v18[1],
    a4: (unsigned __int8 (__cdecl *)(int, int))GTessellator::monoChainLess);
}

//------------------------------------------------------------------------------
// Address: 0x101901E0
// Name: private: void GTessellator::triangulateCoherentCurve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::triangulateCoherentCurve(GTessellator *this)
{
  int *attributes; // eax
  unsigned int v3; // edx
  float v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // eax
  float v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edx
  float *v13; // eax
  float v14; // ecx
  unsigned int v15; // edx
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ecx
  int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ebx
  int v22; // eax
  float *v23; // ecx
  int v24; // edx
  int v25; // edi
  double v26; // st7
  float *v27; // edx
  double v28; // st7
  int v29; // eax
  float *v30; // edi
  double v31; // st6
  float *v32; // ebx
  double v33; // st4
  double v34; // st6
  double v35; // st6
  double v36; // st7
  int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  unsigned int v40; // [esp+Ch] [ebp-44h] BYREF
  float v41; // [esp+10h] [ebp-40h]
  unsigned int v42; // [esp+14h] [ebp-3Ch]
  unsigned int v43; // [esp+18h] [ebp-38h] BYREF
  float v44; // [esp+1Ch] [ebp-34h]
  unsigned int v45; // [esp+20h] [ebp-30h]
  float v46; // [esp+24h] [ebp-2Ch]
  float v47; // [esp+28h] [ebp-28h]
  float v48; // [esp+2Ch] [ebp-24h]
  float v49; // [esp+30h] [ebp-20h]
  char *v50; // [esp+34h] [ebp-1Ch]
  char *v51; // [esp+38h] [ebp-18h]
  unsigned int v52; // [esp+3Ch] [ebp-14h]
  int v53; // [esp+40h] [ebp-10h]
  unsigned int v54; // [esp+44h] [ebp-Ch]
  int v55; // [esp+48h] [ebp-8h]
  bool v56; // [esp+4Eh] [ebp-2h]
  bool v57; // [esp+4Fh] [ebp-1h]

  attributes = (int *)(*(this + 104))->attributes;
  v3 = *attributes;
  v4 = *(float *)((*(this + 108))->attributes + 4);
  v5 = attributes[1];
  v6 = 1;
  v7 = 1;
  v55 = 1;
  v53 = 1;
  v43 = v3;
  v44 = v4;
  v45 = v5;
  if ( v3 != LODWORD(v4) && LODWORD(v4) != v5 && v5 != v3 )
    GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::PushBack(
      this: (unsigned int *)this + 97,
      a2: &v43);
  v50 = (char *)&(*(this + 101))[-1].pCatchableTypeArray + 3;
  v51 = (char *)&(*(this + 105))[-1].pCatchableTypeArray + 3;
  v52 = 2;
  v54 = 2;
  while ( v6 < (unsigned int)v50 )
  {
    v16 = (int)*(this + 104);
    v17 = v6 >> 8;
    if ( v7 >= (unsigned int)v51 )
    {
      v37 = *(_DWORD *)(v16 + 4 * v17);
      ++v54;
      v38 = *(_DWORD *)(v37 + 4 * (unsigned __int8)v6);
      v39 = (int)*(this + 108);
      v43 = v38;
      ++v6;
      v44 = *(float *)(*(_DWORD *)(v39 + 4 * (v7 >> 8)) + 4 * (unsigned __int8)v7);
      v11 = *(_DWORD *)(*(&(*(this + 104))->attributes + (v6 >> 8)) + 4 * (unsigned __int8)v6);
      v55 = v6;
LABEL_9:
      v45 = v11;
      if ( v43 != LODWORD(v44) && LODWORD(v44) != v11 && v11 != v43 )
      {
        v12 = (unsigned int)*(this + 97) >> 10;
        v46 = *(float *)&v12;
        if ( v12 >= (unsigned int)*(this + 98) )
        {
          GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
            this: (unsigned int *)this + 97,
            a2: v12);
          *(float *)&v12 = v46;
        }
        v13 = (float *)(*(&(*(this + 100))->attributes + v12) + 12 * ((unsigned int)*(this + 97) & 0x3FF));
        v14 = v44;
        *(_DWORD *)v13 = v43;
        v15 = v45;
        v13[1] = v14;
        *((_DWORD *)v13 + 2) = v15;
        *(this + 97) = (GTessellator)((char *)*(this + 97) + 1);
      }
    }
    else
    {
      v18 = *(_DWORD *)(*(_DWORD *)(v16 + 4 * v17) + 4 * (unsigned __int8)v6);
      v19 = (int)*(this + 108);
      v49 = *(float *)(*(_DWORD *)(v19 + 4 * (v7 >> 8)) + 4 * (unsigned __int8)v7);
      v44 = v49;
      v43 = v18;
      v40 = v18;
      v20 = *(_DWORD *)(*(_DWORD *)(v16 + 4 * (v54 >> 8)) + 4 * (unsigned __int8)v54);
      v41 = v49;
      v21 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * (v52 >> 8)) + 4 * (unsigned __int8)v52);
      v22 = (int)*(this + 68);
      LODWORD(v49) = *(_DWORD *)(v22 + 4 * (v18 >> 10)) + 8 * (v18 & 0x3FF);
      v23 = (float *)(*(_DWORD *)(v22 + 4 * (LODWORD(v44) >> 10)) + 8 * (LOWORD(v44) & 0x3FF));
      v45 = v20;
      v24 = *(_DWORD *)(v22 + 4 * (v20 >> 10));
      v25 = v20 & 0x3FF;
      v26 = *(float *)(v24 + 8 * v25);
      v27 = (float *)(v24 + 8 * v25);
      v28 = v26 - *v23;
      v29 = *(_DWORD *)(v22 + 4 * (v21 >> 10));
      v30 = (float *)LODWORD(v49);
      v31 = *v23 - *(float *)LODWORD(v49);
      v42 = v21;
      v32 = (float *)(v29 + 8 * (v21 & 0x3FF));
      v49 = (v23[1] - *(float *)(LODWORD(v49) + 4)) * v28 - (v27[1] - v23[1]) * v31;
      v57 = v49 <= 0.0;
      v33 = (v23[1] - v30[1]) * (*v32 - *v23) - v31 * (v32[1] - v23[1]);
      v34 = *v32 - *v23;
      v49 = v33;
      v56 = v49 <= 0.0;
      if ( !v57 )
        goto LABEL_29;
      if ( v56 )
      {
        v49 = (v32[1] - v23[1]) * (*v27 - *v32) - v34 * (v27[1] - v32[1]);
        v57 = v49 <= 0.0;
        v49 = (v27[1] - v30[1]) * (*v32 - *v27) - (*v27 - *v30) * (v32[1] - v27[1]);
        v56 = v49 >= 0.0;
      }
      if ( !v57 )
        goto LABEL_29;
      if ( !v56 )
        goto LABEL_24;
      v48 = v28;
      v49 = v27[1] - v23[1];
      v46 = *v32 - *v30;
      v47 = v32[1] - v30[1];
      v35 = v46;
      v46 = v49 * v49 + v48 * v48;
      v36 = v46;
      v46 = v47 * v47 + v35 * v35;
      if ( v46 > v36 )
      {
LABEL_24:
        if ( v43 != LODWORD(v44) && LODWORD(v44) != v45 && v45 != v43 )
          GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::PushBack(
            this: (unsigned int *)this + 97,
            a2: &v43);
        v7 = v53;
        v6 = v55 + 1;
        ++v54;
        ++v55;
      }
      else
      {
LABEL_29:
        if ( v40 != LODWORD(v41) && LODWORD(v41) != v42 && v42 != v40 )
          GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::PushBack(
            this: (unsigned int *)this + 97,
            a2: &v40);
        v6 = v55;
        v7 = v53 + 1;
        ++v52;
        ++v53;
      }
    }
  }
  if ( v7 < (unsigned int)v51 )
  {
    v8 = (int)*(this + 104);
    ++v52;
    v9 = (int)*(this + 108);
    v43 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * (v6 >> 8)) + 4 * (unsigned __int8)v6);
    v10 = *(float *)(*(_DWORD *)(v9 + 4 * (v7 >> 8)) + 4 * (unsigned __int8)v7);
    ++v7;
    v44 = v10;
    v11 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * (v7 >> 8)) + 4 * (unsigned __int8)v7);
    v53 = v7;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190610
// Name: private: void GTessellator::triangulateConvexShape(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::triangulateConvexShape(GTessellator *this)
{
  unsigned int v2; // eax
  unsigned int *v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edi
  double v8; // st7
  double v9; // st6
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ecx
  void *v13; // eax
  void *v14; // eax
  int *attributes; // eax
  _DWORD *v16; // edx
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int v19; // ecx
  void *v20; // eax
  void *v21; // eax
  unsigned int v22; // ebx
  unsigned int v23; // edx
  unsigned int v24; // esi
  GTessellator v25; // eax
  unsigned int v26; // edi
  int v27; // eax
  unsigned int v28; // edx
  _DWORD *v29; // eax
  GTessellator v30; // eax
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  GTessellator *v34; // edi
  unsigned int v35; // ecx
  _DWORD *v36; // eax
  unsigned int v37; // ecx
  GTessellator v38; // eax
  int v39; // ecx
  unsigned int v40; // ebx
  unsigned int v41; // ecx
  GTessellator v42; // eax
  unsigned int v43; // edx
  float *v44; // eax
  float *v45; // ecx
  double v46; // st6
  double v47; // st7
  GTessellator *v48; // esi
  unsigned int v49; // ecx
  unsigned int v50; // edx
  unsigned int *v51; // eax
  GTessellator *v52; // edi
  unsigned int v53; // ecx
  unsigned int v54; // edx
  unsigned int *v55; // eax
  unsigned int v56; // edx
  GTessellator v57; // eax
  int v58; // eax
  GTessellator *v59; // esi
  unsigned int v60; // ecx
  _DWORD *v61; // eax
  unsigned int v62; // [esp+14h] [ebp-38h]
  int v63; // [esp+18h] [ebp-34h]
  int v64; // [esp+18h] [ebp-34h]
  int v65; // [esp+18h] [ebp-34h]
  int v66; // [esp+1Ch] [ebp-30h]
  int v67; // [esp+1Ch] [ebp-30h]
  int v68; // [esp+1Ch] [ebp-30h]
  int v69; // [esp+20h] [ebp-2Ch]
  int v70; // [esp+20h] [ebp-2Ch]
  unsigned int v71; // [esp+20h] [ebp-2Ch]
  int v72; // [esp+20h] [ebp-2Ch]
  unsigned int v73; // [esp+24h] [ebp-28h]
  float v74; // [esp+24h] [ebp-28h]
  float v75; // [esp+24h] [ebp-28h]
  float v76; // [esp+24h] [ebp-28h]
  unsigned int v77; // [esp+24h] [ebp-28h]
  unsigned int v78; // [esp+24h] [ebp-28h]
  unsigned int v79; // [esp+24h] [ebp-28h]
  float *v80; // [esp+28h] [ebp-24h]
  float v81; // [esp+28h] [ebp-24h]
  float *v82; // [esp+2Ch] [ebp-20h]
  float v83; // [esp+2Ch] [ebp-20h]
  unsigned int v84; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int v85; // [esp+34h] [ebp-18h] BYREF
  unsigned int v86; // [esp+38h] [ebp-14h] BYREF
  unsigned int v87; // [esp+3Ch] [ebp-10h] BYREF
  unsigned int v88; // [esp+40h] [ebp-Ch] BYREF
  unsigned int i; // [esp+44h] [ebp-8h]
  GTessellator *v90; // [esp+48h] [ebp-4h]

  v2 = 0;
  v3 = (unsigned int *)(this + 109);
  v90 = this;
  *(this + 109) = nullptr;
  v87 = 0;
  i = 0;
  if ( *(this + 105) != nullptr )
  {
    do
    {
      v4 = *v3 >> 8;
      v85 = *(&(*(this + 108))->attributes + (v2 >> 8)) + 4 * (unsigned __int8)v2;
      if ( v4 >= v3[1] )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v3, a2: v4);
        v2 = i;
      }
      *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v4) + 4 * (unsigned __int8)(*v3)++) = *(_DWORD *)v85;
      i = ++v2;
    }
    while ( v2 < (unsigned int)*(this + 105) );
  }
  v5 = *v3 - 1;
  v85 = *(_DWORD *)(*(&(*(this + 104))->attributes + (((unsigned int)&(*(this + 101))[-1].pCatchableTypeArray + 3) >> 8))
                  + 4 * (unsigned __int8)(*((_BYTE *)this + 404) - 1));
  v6 = *(_DWORD *)(*(&(*(this + 112))->attributes + (v5 >> 8)) + 4 * (unsigned __int8)v5);
  v7 = v85;
  v85 &= 0x3FFu;
  v8 = *(float *)(*(&(*(this + 68))->attributes + (v7 >> 10)) + 8 * v85 + 4);
  v9 = *(float *)(*(&(*(this + 68))->attributes + (v6 >> 10)) + 8 * (v6 & 0x3FF) + 4);
  v86 = v5;
  if ( v9 < v8 )
    v86 = v5 + 1;
  v10 = (unsigned int)&(*(this + 101))[-1].pCatchableTypeArray + 3;
  for ( i = v10; v10 != 0; i = v10 )
  {
    v11 = *v3 >> 8;
    v84 = *(&(*(this + 104))->attributes + (v10 >> 8)) + 4 * (unsigned __int8)v10;
    if ( v11 >= v3[1] )
    {
      v12 = v3[2];
      if ( v11 >= v12 )
      {
        v13 = (void *)v3[3];
        if ( v13 != nullptr )
        {
          v85 = 4 * v12 + 256;
          v14 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v13, a3: v85);
        }
        else
        {
          v88 = 133;
          v14 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 256, a4: &v88);
        }
        v3[2] += 64;
        v3[3] = (unsigned int)v14;
      }
      v85 = 133;
      *(_DWORD *)(v3[3] + 4 * v11) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                       this: GMemory::pGlobalHeap,
                                       a2: v3,
                                       a3: 1024,
                                       a4: &v85);
      ++v3[1];
      v10 = i;
    }
    *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v11) + 4 * (unsigned __int8)(*v3)++) = *(_DWORD *)v84;
    --v10;
  }
  attributes = (int *)(*(this + 104))->attributes;
  v16 = (_DWORD *)(*(this + 108))->attributes;
  v17 = *attributes;
  v88 = (unsigned int)attributes;
  if ( v17 != *v16 )
  {
    v18 = *v3 >> 8;
    if ( v18 >= v3[1] )
    {
      v19 = v3[2];
      if ( v18 >= v19 )
      {
        v20 = (void *)v3[3];
        if ( v20 != nullptr )
        {
          v84 = 4 * v19 + 256;
          v21 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v20, a3: v84);
        }
        else
        {
          v84 = 133;
          v21 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 256, a4: &v84);
        }
        v3[2] += 64;
        v3[3] = (unsigned int)v21;
      }
      v85 = 133;
      *(_DWORD *)(v3[3] + 4 * v18) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                       this: GMemory::pGlobalHeap,
                                       a2: v3,
                                       a3: 1024,
                                       a4: &v85);
      ++v3[1];
      attributes = (int *)v88;
    }
    *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v18) + 4 * (unsigned __int8)(*v3)++) = *attributes;
  }
  GTessellator::findMaxDiameter(this, a2: &v87, a3: &v86);
  v22 = *v3;
  v23 = (*v3 + v87 - 1) % *v3;
  v85 = v22;
  v24 = v23;
  v25 = v90[112];
  v26 = (v87 + 1) % v22;
  v63 = *(_DWORD *)(*(&v25->attributes + (v87 >> 8)) + 4 * (unsigned __int8)v87);
  v66 = *(_DWORD *)(*(&v25->attributes + (v26 >> 8)) + 4 * (unsigned __int8)v26);
  v27 = *(_DWORD *)(*(&v25->attributes + (v23 >> 8)) + 4 * (unsigned __int8)v23);
  v69 = v27;
  if ( v63 != v66 && v66 != v27 && v27 != v63 )
  {
    v28 = (unsigned int)v90[97] >> 10;
    v84 = v28;
    if ( v28 >= (unsigned int)v90[98] )
    {
      GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
        this: (unsigned int *)v90 + 97,
        a2: v28);
      v28 = v84;
    }
    v29 = (_DWORD *)(*(&v90[100]->attributes + v28) + 12 * ((unsigned int)v90[97] & 0x3FF));
    *v29 = v63;
    v29[1] = v66;
    v29[2] = v69;
    v90[97] = (GTessellator)((char *)v90[97] + 1);
  }
  while ( 1 )
  {
    while ( v24 != v86 )
    {
      v37 = v24 >> 8;
      if ( v26 == v86 )
      {
        v56 = (v24 + v22 - 1) % v22;
        v57 = v90[112];
        v65 = *(_DWORD *)(*(&v57->attributes + v37) + 4 * (unsigned __int8)v24);
        v68 = *(_DWORD *)(*(&v57->attributes + (v26 >> 8)) + 4 * (unsigned __int8)v26);
        v58 = *(_DWORD *)(*(&v57->attributes + (v56 >> 8)) + 4 * (unsigned __int8)v56);
        v87 = v56;
        v72 = v58;
        if ( v65 != v68 && v68 != v58 && v58 != v65 )
        {
          v59 = v90;
          v60 = (unsigned int)v90[97] >> 10;
          v79 = v60;
          if ( v60 >= (unsigned int)v90[98] )
          {
            GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
              this: (unsigned int *)v90 + 97,
              a2: v60);
            v60 = v79;
          }
          v61 = (_DWORD *)(*(&v59[100]->attributes + v60) + 12 * ((unsigned int)v59[97] & 0x3FF));
          *v61 = v65;
          v61[1] = v68;
          v61[2] = v72;
          v59[97] = (GTessellator)((char *)v59[97] + 1);
          v56 = v87;
        }
        v24 = v56;
      }
      else
      {
        v87 = (v24 + v22 - 1) % v22;
        v38 = v90[112];
        v39 = *(&v38->attributes + v37);
        v88 = (v26 + 1) % v22;
        v40 = *(_DWORD *)(v39 + 4 * (unsigned __int8)v24);
        i = *(_DWORD *)(*(&v38->attributes + (v26 >> 8)) + 4 * (unsigned __int8)v26);
        v71 = *(_DWORD *)(*(&v38->attributes + (v87 >> 8)) + 4 * (unsigned __int8)v87);
        v41 = *(_DWORD *)(*(&v38->attributes + (v88 >> 8)) + 4 * (unsigned __int8)v88);
        v42 = v90[68];
        v62 = v41;
        v80 = (float *)(*(&v42->attributes + (v40 >> 10)) + 8 * (v40 & 0x3FF));
        v82 = (float *)(*(&v42->attributes + (i >> 10)) + 8 * (i & 0x3FF));
        v84 = *(&v42->attributes + (v71 >> 10)) + 8 * (v71 & 0x3FF);
        v43 = v84;
        v44 = (float *)(*(&v42->attributes + (v41 >> 10)) + 8 * (v41 & 0x3FF));
        *(float *)&v84 = *(float *)v84 - *v82;
        v45 = v80;
        v83 = *(float *)(v43 + 4) - v82[1];
        v81 = *v44 - *v80;
        v74 = v44[1] - v45[1];
        v46 = v74;
        v75 = v83 * v83 + *(float *)&v84 * *(float *)&v84;
        v47 = v75;
        v76 = v81 * v81 + v46 * v46;
        if ( v76 <= v47 )
        {
          if ( v40 != i && i != v62 && v62 != v40 )
          {
            v52 = v90;
            v53 = (unsigned int)v90[97] >> 10;
            v78 = v53;
            if ( v53 >= (unsigned int)v90[98] )
            {
              GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
                this: (unsigned int *)v90 + 97,
                a2: v53);
              v53 = v78;
            }
            v54 = i;
            v55 = (unsigned int *)(*(&v52[100]->attributes + v53) + 12 * ((unsigned int)v52[97] & 0x3FF));
            *v55 = v40;
            v55[1] = v54;
            v55[2] = v62;
            v52[97] = (GTessellator)((char *)v52[97] + 1);
          }
          v26 = v88;
          v22 = v85;
        }
        else
        {
          if ( v40 != i && i != v71 && v71 != v40 )
          {
            v48 = v90;
            v49 = (unsigned int)v90[97] >> 10;
            v77 = v49;
            if ( v49 >= (unsigned int)v90[98] )
            {
              GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
                this: (unsigned int *)v90 + 97,
                a2: v49);
              v49 = v77;
            }
            v50 = i;
            v51 = (unsigned int *)(*(&v48[100]->attributes + v49) + 12 * ((unsigned int)v48[97] & 0x3FF));
            *v51 = v40;
            v51[1] = v50;
            v51[2] = v71;
            v48[97] = (GTessellator)((char *)v48[97] + 1);
          }
          v24 = v87;
          v22 = v85;
        }
      }
    }
    if ( v26 == v86 )
      break;
    v30 = v90[112];
    v31 = *(&v30->attributes + (v24 >> 8));
    v88 = (v26 + 1) % v22;
    v64 = *(_DWORD *)(v31 + 4 * (unsigned __int8)v24);
    v32 = *(_DWORD *)(*(&v30->attributes + (v26 >> 8)) + 4 * (unsigned __int8)v26);
    v33 = *(_DWORD *)(*(&v30->attributes + (v88 >> 8)) + 4 * (unsigned __int8)v88);
    v67 = v32;
    v70 = v33;
    if ( v64 != v32 && v32 != v33 && v33 != v64 )
    {
      v34 = v90;
      v35 = (unsigned int)v90[97] >> 10;
      v73 = v35;
      if ( v35 >= (unsigned int)v90[98] )
      {
        GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
          this: (unsigned int *)v90 + 97,
          a2: v35);
        v35 = v73;
      }
      v36 = (_DWORD *)(*(&v34[100]->attributes + v35) + 12 * ((unsigned int)v34[97] & 0x3FF));
      *v36 = v64;
      v36[1] = v67;
      v36[2] = v70;
      v34[97] = (GTessellator)((char *)v34[97] + 1);
    }
    v26 = v88;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190D50
// Name: private: void GTessellator::processCoherentShape(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::processCoherentShape(GTessellator *this)
{
  int v1; // eax

  v1 = (int)*(this + 114);
  if ( v1 == 3 || v1 == 4 )
  {
    GTessellator::triangulateCoherentCurve(this);
  }
  else if ( v1 == 2 )
  {
    GTessellator::triangulateConvexShape(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190D70
// Name: private: void GTessellator::createCoherentNucleus(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::createCoherentNucleus(
        GTessellator *this,
        unsigned int v1,
        unsigned int v2,
        unsigned int v3)
{
  unsigned int *v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // ebx
  unsigned int *v9; // esi
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned int v12; // edi
  unsigned int v13; // ebx
  unsigned int v14; // esi
  int v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int *v18; // esi
  unsigned int v19; // ebx
  unsigned int v20; // ebx
  unsigned int v21; // edi
  unsigned int v22; // ebx
  unsigned int v23; // esi
  bool left1; // [esp+Fh] [ebp-1h]
  unsigned int v1a; // [esp+18h] [ebp+8h]
  unsigned int v2a; // [esp+1Ch] [ebp+Ch]
  unsigned int v3a; // [esp+20h] [ebp+10h]

  v3a = v3 & 0xBFFFFFFF;
  v2a = v2 & 0xBFFFFFFF;
  v6 = (unsigned int *)(this + 101);
  v7 = (unsigned int)*(this + 101) >> 8;
  left1 = (v1 & 0x40000000) != 0;
  v1a = v1 & 0xBFFFFFFF;
  if ( left1 == ((v2 & 0x40000000) != 0) )
  {
    if ( v7 >= (unsigned int)*(this + 102) )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: v7);
    *(_DWORD *)(*(_DWORD *)(v6[3] + 4 * v7) + 4 * (unsigned __int8)(*v6)++) = v2a;
    v8 = (unsigned int)*(this + 105);
    v9 = (unsigned int *)(this + 105);
    v10 = v8 >> 8;
    if ( v10 >= v9[1] )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v9, a2: v10);
    *(_DWORD *)(*(_DWORD *)(v9[3] + 4 * v10) + 4 * (unsigned __int8)(*v9)++) = v2a;
    if ( left1 )
    {
      v11 = *v6 >> 8;
      if ( v11 >= v6[1] )
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: *v6 >> 8);
      *(_DWORD *)(*(_DWORD *)(v6[3] + 4 * v11) + 4 * (unsigned __int8)(*v6)++) = v1a;
      v12 = *v9 >> 8;
      if ( v12 >= v9[1] )
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v9, a2: *v9 >> 8);
      *(_DWORD *)(*(_DWORD *)(v9[3] + 4 * v12) + 4 * (unsigned __int8)(*v9)++) = v3a;
      return;
    }
    v13 = *v9 >> 8;
    if ( v13 >= v9[1] )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v9, a2: *v9 >> 8);
    *(_DWORD *)(*(_DWORD *)(v9[3] + 4 * v13) + 4 * (unsigned __int8)(*v9)++) = v1a;
    v14 = *v6 >> 8;
    if ( v14 >= v6[1] )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: *v6 >> 8);
    v15 = *(_DWORD *)(v6[3] + 4 * v14);
    v16 = v3a;
LABEL_32:
    *(_DWORD *)(v15 + 4 * (unsigned __int8)(*v6)++) = v16;
    return;
  }
  if ( v7 >= (unsigned int)*(this + 102) )
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: v7);
  *(_DWORD *)(*(_DWORD *)(v6[3] + 4 * v7) + 4 * (unsigned __int8)(*v6)++) = v3a;
  v17 = (unsigned int)*(this + 105);
  v18 = (unsigned int *)(this + 105);
  v19 = v17 >> 8;
  if ( v19 >= v18[1] )
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v18, a2: v19);
  *(_DWORD *)(*(_DWORD *)(v18[3] + 4 * v19) + 4 * (unsigned __int8)(*v18)++) = v3a;
  if ( !left1 )
  {
    v22 = *v18 >> 8;
    if ( v22 >= v18[1] )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v18, a2: *v18 >> 8);
    *(_DWORD *)(*(_DWORD *)(v18[3] + 4 * v22) + 4 * (unsigned __int8)(*v18)++) = v1a;
    v23 = *v6 >> 8;
    if ( v23 >= v6[1] )
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: *v6 >> 8);
    v15 = *(_DWORD *)(v6[3] + 4 * v23);
    v16 = v2a;
    goto LABEL_32;
  }
  v20 = *v6 >> 8;
  if ( v20 >= v6[1] )
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v6, a2: *v6 >> 8);
  *(_DWORD *)(*(_DWORD *)(v6[3] + 4 * v20) + 4 * (unsigned __int8)(*v6)++) = v1a;
  v21 = *v18 >> 8;
  if ( v21 >= v18[1] )
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this: v18, a2: *v18 >> 8);
  *(_DWORD *)(*(_DWORD *)(v18[3] + 4 * v21) + 4 * (unsigned __int8)(*v18)++) = v2a;
}

//------------------------------------------------------------------------------
// Address: 0x10190FD0
// Name: private: void GTessellator::addTriangle(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::addTriangle(GTessellator *this, unsigned int v1, unsigned int v2, unsigned int v3)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  const _s__ThrowInfo *v7; // eax
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  _DWORD *v11; // eax
  unsigned int v12; // edi
  const _s__ThrowInfo *v13; // eax
  const _s__ThrowInfo *v14; // ecx
  int v15[3]; // [esp+Ch] [ebp-Ch] BYREF

  v5 = v2 & 0xBFFFFFFF;
  v6 = v3 & 0xBFFFFFFF;
  v15[0] = v1 & 0xBFFFFFFF;
  v15[1] = v2 & 0xBFFFFFFF;
  v15[2] = v3 & 0xBFFFFFFF;
  if ( (v1 & 0xBFFFFFFF) != (v2 & 0xBFFFFFFF) && v5 != v6 && v6 != (v1 & 0xBFFFFFFF) )
  {
    if ( *((_BYTE *)this + 5) != 0 )
    {
      v7 = *(this + 97);
      if ( v7 != *(this + 113) )
      {
        v8 = *(&(*(this + 100))->attributes + (((unsigned int)&v7[-1].pCatchableTypeArray + 3) >> 10));
        v9 = 3 * (((unsigned int)&v7[-1].pCatchableTypeArray + 3) & 0x3FF);
        v10 = *(_DWORD *)(v8 + 4 * v9 + 4) == v5;
        v11 = (_DWORD *)(v8 + 4 * v9);
        if ( v10 && *v11 == v6 || v11[2] == v6 && *v11 == v5 )
        {
          v12 = v1;
          if ( GTessellator::shapeCoherent(this, v: v1) )
          {
            if ( (v1 & 0x40000000) != 0 )
              GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
                this: (unsigned int *)this + 101,
                a2: v15);
            else
              GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
                this: (unsigned int *)this + 105,
                a2: v15);
            goto LABEL_23;
          }
        }
        else
        {
          v12 = v1;
        }
        if ( (unsigned int)*(this + 101) > 3 && (unsigned int)*(this + 105) > 3 && (int)*(this + 114) > 1 )
        {
          v13 = *(this + 113);
          if ( v13 < *(this + 97) )
            *(this + 97) = v13;
          GTessellator::processCoherentShape(this);
        }
        v14 = *(this + 97);
        *(this + 101) = nullptr;
        *(this + 105) = nullptr;
        *(this + 114) = nullptr;
        *(this + 115) = nullptr;
        *(this + 116) = nullptr;
        *(this + 113) = v14;
        GTessellator::createCoherentNucleus(this, v1: v12, v2, v3);
        goto LABEL_23;
      }
      GTessellator::createCoherentNucleus(this, v1, v2, v3);
    }
LABEL_23:
    GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::PushBack(
      this: (unsigned int *)this + 97,
      a2: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191140
// Name: private: bool GTessellator::addTrianglePilot(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GTessellator::addTrianglePilot(GTessellator *this, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // ecx
  int v5; // edx
  unsigned int v6; // eax
  double v7; // st7
  float *v8; // eax
  unsigned int v9; // esi
  float *v10; // edx
  unsigned int v12; // ecx
  unsigned int *v13; // eax
  float v15; // [esp+18h] [ebp+8h]
  unsigned int v16; // [esp+18h] [ebp+8h]

  v4 = (int)*(this + 68);
  v5 = *(_DWORD *)(v4 + 4 * ((a3 & 0xBFFFFFFF) >> 10));
  v6 = a3 & 0x3FF;
  v7 = *(float *)(v5 + 8 * v6 + 4);
  v8 = (float *)(v5 + 8 * v6);
  v9 = a2 & 0xBFFFFFFF;
  v10 = (float *)(*(_DWORD *)(v4 + 4 * ((a4 & 0xBFFFFFFF) >> 10)) + 8 * (a4 & 0x3FF));
  v15 = (v7 - *(float *)(*(_DWORD *)(v4 + 4 * (v9 >> 10)) + 8 * (v9 & 0x3FF) + 4)) * (*v10 - *v8)
      - (v10[1] - v8[1]) * (*v8 - *(float *)(*(_DWORD *)(v4 + 4 * (v9 >> 10)) + 8 * (v9 & 0x3FF)));
  if ( 0.0 == v15 )
    return 1;
  if ( v15 > 0.0 )
    return 0;
  v12 = (unsigned int)*(this + 97) >> 10;
  v16 = v12;
  if ( v12 >= (unsigned int)*(this + 98) )
  {
    GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
      this: (unsigned int *)this + 97,
      a2: v12);
    v12 = v16;
  }
  v13 = (unsigned int *)(*(&(*(this + 100))->attributes + v12) + 12 * ((unsigned int)*(this + 97) & 0x3FF));
  *v13 = v9;
  v13[1] = a3 & 0xBFFFFFFF;
  v13[2] = a4 & 0xBFFFFFFF;
  *(this + 97) = (GTessellator)((char *)*(this + 97) + 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10191260
// Name: private: bool GTessellator::triangulateMonotonePilot(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GTessellator::triangulateMonotonePilot(GTessellator *this, unsigned int convex)
{
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // eax
  _DWORD *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  float *v9; // edx
  unsigned int v10; // eax
  float *v11; // edx
  _DWORD **v13; // eax
  bool v14; // zf
  unsigned int v15; // ebx
  int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int v21; // eax
  unsigned int *v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  int v27; // edx
  int v28; // ecx
  double v29; // st7
  int v30; // ecx
  unsigned int v31; // ebx
  double v32; // st7
  double v33; // st6
  double v34; // st5
  double v35; // st7
  double v36; // st7
  int v37; // eax
  int v38; // edx
  int v39; // ebx
  unsigned int v40; // ecx
  unsigned int v41; // eax
  int v42; // edx
  float *v43; // ebx
  int v44; // eax
  int v45; // ecx
  char v46; // al
  int v47; // eax
  unsigned int v48; // eax
  int v49; // edx
  bool v50; // cc
  unsigned int v51; // ecx
  int v52; // eax
  int v53; // ebx
  unsigned int v54; // eax
  char v55; // al
  unsigned int v56; // [esp+10h] [ebp-34h]
  float v57; // [esp+18h] [ebp-2Ch]
  unsigned int topStack; // [esp+1Ch] [ebp-28h] BYREF
  unsigned int topLeft; // [esp+20h] [ebp-24h]
  unsigned int topRight; // [esp+24h] [ebp-20h]
  unsigned int v61; // [esp+28h] [ebp-1Ch]
  unsigned int p1; // [esp+2Ch] [ebp-18h]
  unsigned int v63; // [esp+30h] [ebp-14h]
  unsigned int iRight; // [esp+34h] [ebp-10h]
  unsigned int topStrip; // [esp+38h] [ebp-Ch] BYREF
  unsigned int iLeft; // [esp+3Ch] [ebp-8h]
  bool t1Valid; // [esp+43h] [ebp-1h]

  v3 = (int)*(this + 88);
  v4 = convex >> 6;
  v5 = convex & 0x3F;
  *(this + 97) = nullptr;
  *(this + 101) = nullptr;
  *(this + 105) = nullptr;
  *(this + 113) = nullptr;
  *(this + 114) = nullptr;
  *(this + 115) = nullptr;
  *(this + 116) = nullptr;
  v6 = *(_DWORD **)(*(_DWORD *)(v3 + 4 * v4) + 24 * v5);
  if ( v6 == nullptr )
    return 1;
  v7 = *(&(*(this + 68))->attributes + ((*v6 & 0xBFFFFFFF) >> 10)) + 8 * (*v6 & 0x3FF);
  HIBYTE(convex) = 1;
  p1 = v7;
  v63 = v7;
  iRight = v7;
  topStrip = v7;
  do
  {
    if ( (*v6 & 0x40000000) != 0 )
    {
      topRight = *v6 & 0xBFFFFFFF;
      v8 = (unsigned int)*(this + 101) >> 8;
      v61 = v8;
      if ( v8 >= (unsigned int)*(this + 102) )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
          this: (unsigned int *)this + 101,
          a2: v8);
        v8 = v61;
      }
      *(float *)(*(&(*(this + 104))->attributes + v8) + 4 * (unsigned __int8)*(this + 101)) = *(float *)&topRight;
      *(this + 101) = (GTessellator)((char *)*(this + 101) + 1);
      if ( HIBYTE(convex) != 0 )
      {
        v9 = (float *)(*(&(*(this + 68))->attributes + ((*v6 & 0xBFFFFFFF) >> 10)) + 8 * (*v6 & 0x3FF));
        *(float *)&topRight = (*(float *)(v63 + 4) - *(float *)(p1 + 4)) * (*v9 - *(float *)v63)
                            - (v9[1] - *(float *)(v63 + 4)) * (*(float *)v63 - *(float *)p1);
        if ( *(float *)&topRight < 0.0 )
          HIBYTE(convex) = 0;
        p1 = v63;
        v63 = (unsigned int)v9;
      }
    }
    else
    {
      v10 = (unsigned int)*(this + 105) >> 8;
      v61 = v10;
      if ( v10 >= (unsigned int)*(this + 106) )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
          this: (unsigned int *)this + 105,
          a2: v10);
        v10 = v61;
      }
      *(_DWORD *)(*(&(*(this + 108))->attributes + v10) + 4 * (unsigned __int8)*(this + 105)) = *v6;
      *(this + 105) = (GTessellator)((char *)*(this + 105) + 1);
      if ( HIBYTE(convex) != 0 )
      {
        v11 = (float *)(*(&(*(this + 68))->attributes + (*v6 >> 10)) + 8 * (*v6 & 0x3FF));
        *(float *)&topRight = (*(float *)(topStrip + 4) - *(float *)(iRight + 4)) * (*v11 - *(float *)topStrip)
                            - (v11[1] - *(float *)(topStrip + 4)) * (*(float *)topStrip - *(float *)iRight);
        if ( *(float *)&topRight > 0.0 )
          HIBYTE(convex) = 0;
        iRight = topStrip;
        topStrip = (unsigned int)v11;
      }
    }
    v6 = (_DWORD *)v6[1];
  }
  while ( v6 != nullptr );
  if ( (unsigned int)*(this + 101) < 2 || (unsigned int)*(this + 105) < 2 )
    return 0;
  if ( HIBYTE(convex) != 0 )
  {
    GTessellator::triangulateConvexShape(this);
    return 1;
  }
  v13 = (_DWORD **)*(this + 104);
  v14 = **v13 == *(_DWORD *)(*(this + 108))->attributes;
  *(this + 93) = nullptr;
  v15 = v14;
  v16 = **v13 | 0x40000000;
  iLeft = 1;
  convex = v16;
  iRight = v14;
  GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
    this: (unsigned int *)this + 93,
    a2: (int *)&convex);
  v17 = *(_DWORD *)((*(this + 104))->attributes + 4);
  if ( v17 >= *(_DWORD *)((*(this + 108))->attributes + 4 * (unsigned __int8)v15) )
  {
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
      this: (unsigned int *)this + 93,
      a2: (int *)(*(&(*(this + 108))->attributes + (v15 >> 8)) + 4 * (unsigned __int8)v15));
    iRight = ++v15;
  }
  else
  {
    convex = v17 | 0x40000000;
    iLeft = 2;
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
      this: (unsigned int *)this + 93,
      a2: (int *)&convex);
  }
  v18 = iLeft;
  v19 = (unsigned int)*(this + 105);
  topLeft = (unsigned int)*(this + 101);
  topRight = v19;
  v63 = iLeft - 1;
  while ( v18 < topLeft )
  {
    if ( v15 >= topRight )
    {
      v20 = *(_DWORD *)(*(&(*(this + 104))->attributes + (iLeft >> 8)) + 4 * (unsigned __int8)iLeft) | 0x40000000;
      ++v63;
      ++iLeft;
      goto LABEL_29;
    }
    if ( v15 == 0 )
    {
      v25 = *(_DWORD *)(*(&(*(this + 104))->attributes + (v18 >> 8)) + 4 * (unsigned __int8)v18);
      v20 = *(_DWORD *)(*(this + 108))->attributes;
      if ( v25 >= v20 )
      {
        iRight = 1;
      }
      else
      {
        v20 = v25 | 0x40000000;
        ++iLeft;
        ++v63;
      }
      goto LABEL_29;
    }
    v26 = *(_DWORD *)(*(&(*(this + 104))->attributes + (v63 >> 8)) + 4 * (unsigned __int8)v63);
    v56 = *(_DWORD *)(*(&(*(this + 108))->attributes + ((v15 - 1) >> 8)) + 4 * (unsigned __int8)(v15 - 1));
    p1 = *(_DWORD *)(*(&(*(this + 104))->attributes + (iLeft >> 8)) + 4 * (unsigned __int8)iLeft);
    v61 = *(_DWORD *)(*(&(*(this + 108))->attributes + (iRight >> 8)) + 4 * (unsigned __int8)iRight);
    v27 = (int)*(this + 68);
    convex = *(_DWORD *)(v27 + 4 * (v26 >> 10)) + 8 * (v26 & 0x3FF);
    v28 = *(_DWORD *)(v27 + 4 * (v56 >> 10));
    v29 = *(float *)(v28 + 8 * (v56 & 0x3FF));
    v30 = v28 + 8 * (v56 & 0x3FF);
    topStack = *(_DWORD *)(v27 + 4 * (p1 >> 10)) + 8 * (p1 & 0x3FF);
    v31 = convex;
    v32 = v29 - *(float *)convex;
    v33 = *(float *)topStack;
    topStrip = *(_DWORD *)(v27 + 4 * (v61 >> 10)) + 8 * (v61 & 0x3FF);
    *(float *)&convex = (v33 - *(float *)v30) * (*(float *)(v30 + 4) - *(float *)(convex + 4))
                      - (*(float *)(topStack + 4) - *(float *)(v30 + 4)) * v32;
    t1Valid = *(float *)&convex <= 0.0;
    v34 = (*(float *)(v30 + 4) - *(float *)(v31 + 4)) * (*(float *)topStrip - *(float *)v30)
        - v32 * (*(float *)(topStrip + 4) - *(float *)(v30 + 4));
    v35 = *(float *)topStrip - *(float *)v30;
    *(float *)&convex = v34;
    HIBYTE(convex) = *(float *)&convex <= 0.0;
    if ( !t1Valid )
      goto LABEL_47;
    if ( HIBYTE(convex) != 0 )
    {
      *(float *)&convex = (*(float *)(topStrip + 4) - *(float *)(v30 + 4)) * (*(float *)topStack - *(float *)topStrip)
                        - v35 * (*(float *)(topStack + 4) - *(float *)(topStrip + 4));
      t1Valid = *(float *)&convex <= 0.0;
      *(float *)&convex = (*(float *)topStrip - *(float *)topStack) * (*(float *)(topStack + 4) - *(float *)(v31 + 4))
                        - (*(float *)(topStrip + 4) - *(float *)(topStack + 4)) * (*(float *)topStack - *(float *)v31);
      HIBYTE(convex) = *(float *)&convex >= 0.0;
    }
    if ( !t1Valid )
    {
LABEL_47:
      if ( HIBYTE(convex) == 0 )
        return 0;
LABEL_48:
      v20 = v61;
      ++iRight;
      goto LABEL_29;
    }
    if ( HIBYTE(convex) != 0 )
    {
      *(float *)&convex = GTessellator::distanceSquare(
                            result: (const _s_RTTIClassHierarchyDescriptor *)v30,
                            dy: (float *)topStack);
      v36 = GTessellator::distanceSquare(result: (const _s_RTTIClassHierarchyDescriptor *)v31, dy: (float *)topStrip);
      if ( *(float *)&convex >= v36 )
        goto LABEL_48;
    }
    ++iLeft;
    v20 = p1 | 0x40000000;
    ++v63;
LABEL_29:
    topStack = *(_DWORD *)(*(&(*(this + 96))->attributes
                           + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                         + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1));
    topStrip = v20;
    HIBYTE(convex) = (v20 & 0x40000000) != 0;
    if ( HIBYTE(convex) == ((topStack & 0x40000000) != 0) )
    {
      if ( (unsigned int)*(this + 93) > 1 )
      {
        topStack = 4 * ((v20 & 0xBFFFFFFF) >> 10);
        v61 = 8 * (v20 & 0x3FF);
        do
        {
          v38 = (int)*(this + 93);
          v39 = (int)*(this + 96);
          v40 = *(_DWORD *)(*(_DWORD *)(v39 + 4 * ((unsigned int)(v38 - 1) >> 8)) + 4 * (unsigned __int8)(v38 - 1));
          v41 = *(_DWORD *)(*(_DWORD *)(v39 + 4 * ((unsigned int)(v38 - 2) >> 8)) + 4 * (unsigned __int8)(v38 - 2));
          v42 = (int)*(this + 68);
          convex = v41;
          p1 = v40;
          v40 &= ~0x40000000u;
          v43 = (float *)(*(_DWORD *)(v42 + 4 * ((v41 & 0xBFFFFFFF) >> 10)) + 8 * (v41 & 0x3FF));
          v44 = *(_DWORD *)(v42 + 4 * (v40 >> 10));
          v45 = v40 & 0x3FF;
          v57 = (*(float *)(v44 + 8 * v45 + 4) - *(float *)(v61 + *(_DWORD *)(v42 + topStack) + 4))
              * (*v43 - *(float *)(v44 + 8 * v45))
              - (v43[1] - *(float *)(v44 + 8 * v45 + 4))
              * (*(float *)(v44 + 8 * v45) - *(float *)(v61 + *(_DWORD *)(v42 + topStack)));
          v20 = topStrip;
          if ( v57 < 0.0 != ((p1 & 0x40000000) != 0) )
            break;
          if ( (p1 & 0x40000000) != 0 )
            v46 = GTessellator::addTrianglePilot(this, a2: topStrip, a3: p1, a4: convex);
          else
            v46 = GTessellator::addTrianglePilot(this, a2: topStrip, a3: convex, a4: p1);
          if ( v46 == 0 )
            return 0;
          v47 = (int)*(this + 93);
          if ( v47 != 0 )
            *(this + 93) = (GTessellator)(v47 - 1);
        }
        while ( (unsigned int)*(this + 93) > 1 );
      }
      v48 = (unsigned int)*(this + 93) >> 8;
      convex = v48;
      if ( v48 >= (unsigned int)*(this + 94) )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
          this: (unsigned int *)this + 93,
          a2: v48);
        v48 = convex;
      }
      v49 = *(&(*(this + 96))->attributes + v48);
      v18 = iLeft;
      *(_DWORD *)(v49 + 4 * (unsigned __int8)*(this + 93)) = v20;
      *(this + 93) = (GTessellator)((char *)*(this + 93) + 1);
      v15 = iRight;
    }
    else
    {
      while ( (unsigned int)*(this + 93) > 1 )
      {
        p1 = *(_DWORD *)(*(&(*(this + 96))->attributes
                         + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                       + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1));
        v21 = (int)*(this + 93);
        if ( v21 != 0 )
          *(this + 93) = (GTessellator)(v21 - 1);
        v22 = (unsigned int *)(*(&(*(this + 96))->attributes
                               + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                             + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1));
        if ( HIBYTE(convex) != 0 )
        {
          v23 = p1;
          v24 = *v22;
        }
        else
        {
          v23 = *v22;
          v24 = p1;
        }
        if ( GTessellator::addTrianglePilot(this, a2: v20, a3: v24, a4: v23) == 0 )
          return 0;
      }
      v37 = (int)*(this + 93);
      if ( v37 != 0 )
        *(this + 93) = (GTessellator)(v37 - 1);
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
        this: (unsigned int *)this + 93,
        a2: (int *)&topStack);
      GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
        this: (unsigned int *)this + 93,
        a2: (int *)&topStrip);
      v15 = iRight;
      v18 = iLeft;
    }
  }
  if ( v15 < topRight )
  {
    v20 = *(_DWORD *)(*(&(*(this + 108))->attributes + (iRight >> 8)) + 4 * (unsigned __int8)iRight);
    ++iRight;
    goto LABEL_29;
  }
  v50 = (unsigned int)*(this + 93) <= 1;
  convex = *(unsigned int *)(*(&(*(this + 104))->attributes
                             + (((unsigned int)&(*(this + 101))[-1].pCatchableTypeArray + 3) >> 8))
                           + 4 * (unsigned __int8)(*((_BYTE *)this + 404) - 1));
  if ( v50 )
    return 1;
  while ( 1 )
  {
    v51 = *(_DWORD *)(*(&(*(this + 96))->attributes + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                    + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1));
    v52 = (int)*(this + 93);
    if ( v52 != 0 )
      *(this + 93) = (GTessellator)(v52 - 1);
    v53 = (int)*(this + 96);
    v54 = (unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3;
    v55 = (v51 & 0x40000000) != 0
        ? GTessellator::addTrianglePilot(
            this,
            a2: convex,
            a3: v51,
            a4: *(_DWORD *)(*(_DWORD *)(v53 + 4 * (v54 >> 8)) + 4 * (unsigned __int8)v54))
        : GTessellator::addTrianglePilot(
            this,
            a2: convex,
            a3: *(_DWORD *)(*(_DWORD *)(v53 + 4 * (v54 >> 8)) + 4 * (unsigned __int8)v54),
            a4: v51);
    if ( v55 == 0 )
      break;
    if ( (unsigned int)*(this + 93) <= 1 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10191B70
// Name: private: void GTessellator::triangulateMonotoneRegular(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::triangulateMonotoneRegular(GTessellator *this, unsigned int p2)
{
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  unsigned int v7; // edi
  unsigned int *v8; // eax
  unsigned int v9; // edi
  bool v10; // dl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // edi
  int v17; // ecx
  int v18; // edx
  unsigned int v19; // edi
  unsigned int v20; // eax
  int v21; // edx
  unsigned int v22; // ecx
  float *v23; // edi
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  unsigned int v27; // edi
  unsigned int v28; // edi
  unsigned int v29; // ecx
  int v30; // eax
  const _s__ThrowInfo *v31; // eax
  unsigned int v32; // [esp-Ch] [ebp-2Ch]
  unsigned int v33; // [esp-8h] [ebp-28h]
  unsigned int p1; // [esp+8h] [ebp-18h]
  float v35; // [esp+Ch] [ebp-14h]
  unsigned int topStack; // [esp+14h] [ebp-Ch]
  _DWORD *v37; // [esp+18h] [ebp-8h]
  _DWORD *v38; // [esp+18h] [ebp-8h]
  unsigned int *i; // [esp+18h] [ebp-8h]
  unsigned int topStrip; // [esp+1Ch] [ebp-4h]
  unsigned int p2a; // [esp+28h] [ebp+8h]
  unsigned int p2b; // [esp+28h] [ebp+8h]
  bool p2_3; // [esp+2Bh] [ebp+Bh]

  v3 = (int)*(this + 88);
  *(this + 97) = nullptr;
  *(this + 101) = nullptr;
  *(this + 105) = nullptr;
  *(this + 113) = nullptr;
  *(this + 114) = nullptr;
  *(this + 115) = nullptr;
  *(this + 116) = nullptr;
  v4 = *(_DWORD **)(*(_DWORD *)(v3 + 4 * (p2 >> 6)) + 24 * (p2 & 0x3F));
  v37 = v4;
  if ( v4 != nullptr )
  {
    v5 = v4[1];
    if ( v5 != 0 && *(_DWORD *)(v5 + 4) != 0 )
    {
      *(this + 93) = nullptr;
      if ( *(this + 94) == nullptr )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
          this: (unsigned int *)this + 93,
          a2: 0);
        v4 = v37;
      }
      *(_DWORD *)((*(this + 96))->attributes + 4 * (unsigned __int8)*(this + 93)) = *v4;
      *(this + 93) = (GTessellator)((char *)*(this + 93) + 1);
      v6 = (_DWORD *)v4[1];
      v7 = (unsigned int)*(this + 93) >> 8;
      v38 = v6;
      if ( v7 >= (unsigned int)*(this + 94) )
      {
        GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
          this: (unsigned int *)this + 93,
          a2: v7);
        v6 = v38;
      }
      *(_DWORD *)(*(&(*(this + 96))->attributes + v7) + 4 * (unsigned __int8)*(this + 93)) = *v6;
      *(this + 93) = (GTessellator)((char *)*(this + 93) + 1);
      v8 = (unsigned int *)v6[1];
      for ( i = v8; i[1] != 0; v8 = i )
      {
        v9 = (unsigned int)*(this + 93);
        topStrip = *v8;
        topStack = *(_DWORD *)(*(&(*(this + 96))->attributes + ((v9 - 1) >> 8)) + 4 * (unsigned __int8)(v9 - 1));
        v10 = (*v8 & 0x40000000) != 0;
        p2_3 = v10;
        if ( v10 == ((topStack & 0x40000000) != 0) )
        {
          if ( v9 > 1 )
          {
            do
            {
              v17 = (int)*(this + 93);
              v18 = (int)*(this + 96);
              v19 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * ((unsigned int)(v17 - 1) >> 8)) + 4 * (unsigned __int8)(v17 - 1));
              v20 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * ((unsigned int)(v17 - 2) >> 8)) + 4 * (unsigned __int8)(v17 - 2));
              v21 = (int)*(this + 68);
              p2a = v20;
              p1 = v19;
              v22 = v19 & 0xBFFFFFFF;
              v23 = (float *)(*(_DWORD *)(v21 + 4 * ((v20 & 0xBFFFFFFF) >> 10)) + 8 * (v20 & 0x3FF));
              v24 = *(_DWORD *)(v21 + 4 * (v22 >> 10));
              v25 = v22 & 0x3FF;
              v35 = (*(float *)(v24 + 8 * v25 + 4)
                   - *(float *)(8 * (topStrip & 0x3FF) + *(_DWORD *)(4 * ((topStrip & 0xBFFFFFFF) >> 10) + v21) + 4))
                  * (*v23 - *(float *)(v24 + 8 * v25))
                  - (v23[1] - *(float *)(v24 + 8 * v25 + 4))
                  * (*(float *)(v24 + 8 * v25)
                   - *(float *)(8 * (topStrip & 0x3FF) + *(_DWORD *)(4 * ((topStrip & 0xBFFFFFFF) >> 10) + v21)));
              if ( v35 < 0.0 != ((p1 & 0x40000000) != 0) )
                break;
              if ( (p1 & 0x40000000) != 0 )
              {
                v33 = p2a;
                v32 = p1;
              }
              else
              {
                v33 = p1;
                v32 = p2a;
              }
              GTessellator::addTriangle(this, v1: topStrip, v2: v32, v3: v33);
              v26 = (int)*(this + 93);
              if ( v26 != 0 )
                *(this + 93) = (GTessellator)(v26 - 1);
            }
            while ( (unsigned int)*(this + 93) > 1 );
          }
          v27 = (unsigned int)*(this + 93) >> 8;
          if ( v27 >= (unsigned int)*(this + 94) )
            GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
              this: (unsigned int *)this + 93,
              a2: (unsigned int)*(this + 93) >> 8);
          *(_DWORD *)(*(&(*(this + 96))->attributes + v27) + 4 * (unsigned __int8)*(this + 93)) = topStrip;
        }
        else
        {
          if ( v9 > 1 )
          {
            while ( 1 )
            {
              v11 = *(_DWORD *)(*(&(*(this + 96))->attributes + ((v9 - 1) >> 8)) + 4 * (unsigned __int8)(v9 - 1));
              v12 = (int)*(this + 93);
              if ( v12 != 0 )
                *(this + 93) = (GTessellator)(v12 - 1);
              v13 = (unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3;
              if ( v10 )
                GTessellator::addTriangle(
                  this,
                  v1: topStrip,
                  v2: *(_DWORD *)(*(&(*(this + 96))->attributes + (v13 >> 8)) + 4 * (unsigned __int8)v13),
                  v3: v11);
              else
                GTessellator::addTriangle(
                  this,
                  v1: topStrip,
                  v2: v11,
                  v3: *(_DWORD *)(*(&(*(this + 96))->attributes + (v13 >> 8)) + 4 * (unsigned __int8)v13));
              v9 = (unsigned int)*(this + 93);
              if ( v9 <= 1 )
                break;
              v10 = p2_3;
            }
          }
          v14 = (int)*(this + 93);
          if ( v14 != 0 )
            *(this + 93) = (GTessellator)(v14 - 1);
          v15 = (unsigned int)*(this + 93) >> 8;
          if ( v15 >= (unsigned int)*(this + 94) )
            GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
              this: (unsigned int *)this + 93,
              a2: (unsigned int)*(this + 93) >> 8);
          *(_DWORD *)(*(&(*(this + 96))->attributes + v15) + 4 * (unsigned __int8)*(this + 93)) = topStack;
          *(this + 93) = (GTessellator)((char *)*(this + 93) + 1);
          v16 = (unsigned int)*(this + 93) >> 8;
          if ( v16 >= (unsigned int)*(this + 94) )
            GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
              this: (unsigned int *)this + 93,
              a2: (unsigned int)*(this + 93) >> 8);
          *(_DWORD *)(*(&(*(this + 96))->attributes + v16) + 4 * (unsigned __int8)*(this + 93)) = topStrip;
        }
        *(this + 93) = (GTessellator)((char *)*(this + 93) + 1);
        i = (unsigned int *)i[1];
      }
      v28 = *v8;
      p2b = *v8;
      while ( (unsigned int)*(this + 93) > 1 )
      {
        v29 = *(_DWORD *)(*(&(*(this + 96))->attributes
                          + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                        + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1));
        v30 = (int)*(this + 93);
        if ( v30 != 0 )
          *(this + 93) = (GTessellator)(v30 - 1);
        if ( (v29 & 0x40000000) != 0 )
        {
          v28 = p2b;
          GTessellator::addTriangle(
            this,
            v1: p2b,
            v2: v29,
            v3: *(_DWORD *)(*(&(*(this + 96))->attributes
                        + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                      + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1)));
        }
        else
        {
          GTessellator::addTriangle(
            this,
            v1: v28,
            v2: *(_DWORD *)(*(&(*(this + 96))->attributes
                        + (((unsigned int)&(*(this + 93))[-1].pCatchableTypeArray + 3) >> 8))
                      + 4 * (unsigned __int8)(*((_BYTE *)this + 372) - 1)),
            v3: v29);
        }
      }
      if ( (unsigned int)*(this + 101) > 3 && (unsigned int)*(this + 105) > 3 && (int)*(this + 114) > 1 )
      {
        v31 = *(this + 113);
        if ( v31 < *(this + 97) )
          *(this + 97) = v31;
        GTessellator::processCoherentShape(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192040
// Name: public: void GTessellator::TriangulateMonotone(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::TriangulateMonotone(GTessellator *this, unsigned int idx)
{
  if ( *((_BYTE *)this + 7) == 0 || GTessellator::triangulateMonotonePilot(this, convex: idx) == 0 )
    GTessellator::triangulateMonotoneRegular(this, p2: idx);
}

//------------------------------------------------------------------------------
// Address: 0x10192070
// Name: private: void GTessellator::growMonotoneAndConnect(struct GTessellator::ScanChainType __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::growMonotoneAndConnect(
        GTessellator *this,
        struct GTessellator::ScanChainType *styleAbove,
        unsigned int vertex,
        int __formal)
{
  int *v4; // eax
  int v5; // esi

  if ( styleAbove != nullptr )
  {
    v4 = *((int **)styleAbove + 1);
    if ( v4 != nullptr )
    {
      v5 = v4[5];
      if ( v5 != 0 )
      {
        if ( *(float *)(*(&(*(this + 68))->attributes + ((vertex & 0xBFFFFFFF) >> 10)) + 8 * (vertex & 0x3FF) + 4) == *(float *)v5 )
        {
          *(_DWORD *)(v5 + 12) = vertex & 0xBFFFFFFF;
        }
        else if ( (vertex & 0x40000000) != 0 )
        {
          GTessellator::connectPendingToLeft(this, a2: styleAbove, targetVertex: vertex);
        }
        else
        {
          GTessellator::connectPendingToRight(this, styleAbove, targetVertex: vertex);
        }
      }
      else
      {
        GTessellator::growMonotone(this, m: v4, vertex);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192100
// Name: private: void GTessellator::sweepScanbeam(class GArrayUnsafeLH_POD<struct GTessellator::MonoChainType __near *,133> const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::sweepScanbeam(GTessellator *this, _DWORD *a2, float yb)
{
  _DWORD *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  bool v7; // zf
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int v10; // eax
  struct GTessellator::ScanChainType *v11; // edi
  const pDNameNode **v12; // ebx
  const pDNameNode *v13; // ecx
  DName *me; // eax
  DName *v15; // edx
  unsigned int length; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // eax
  int v20; // edi
  double v21; // st7
  pDNameNode_vtbl *v22; // edx
  int v23; // ecx
  unsigned int v24; // ebx
  int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // ebx
  const DNameStatusNode *v28; // eax
  int v29; // edi
  unsigned int v30; // ebx
  const DNameStatusNode *v31; // eax
  int v32; // edi
  int v33; // ebx
  const DNameStatusNode *v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  int v37; // ebx
  int v38; // edi
  unsigned int v39; // ecx
  struct GTessellator::ScanChainType *v40; // ebx
  struct GTessellator::ScanChainType *v41; // edi
  int v42; // eax
  int v43; // eax
  int v44; // eax
  struct GTessellator::ScanChainType *v45; // edi
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  int v51; // ebx
  DNameNode *v52; // eax
  unsigned int v53; // ebx
  char *v54; // ecx
  char *v55; // eax
  struct GTessellator::ScanChainType *v56; // eax
  struct GTessellator::ScanChainType *v57; // eax
  int v58; // edi
  int v59; // ecx
  struct GTessellator::ScanChainType *v60; // eax
  unsigned int v61; // ebx
  struct GTessellator::ScanChainType *v62; // edx
  _DWORD *v63; // eax
  int v64; // eax
  DNameNode *v65; // eax
  DNameNode *started; // eax
  const pDNameNode **v67; // edi
  unsigned int v68; // ecx
  int *v69; // eax
  float *v70; // edx
  unsigned int v71; // ecx
  const pDNameNode *v72; // eax
  unsigned int v73; // eax
  unsigned int v74; // ebx
  unsigned int v75; // edx
  _DWORD *v76; // eax
  int v77; // eax
  unsigned int v78; // ecx
  struct GTessellator::ScanChainType *v79; // edi
  int *v80; // eax
  float *v81; // edx
  unsigned int v82; // ecx
  int *v83; // eax
  unsigned int v84; // ecx
  float *v85; // ebx
  GTessellator *v86; // ebx
  GTessellator *v87; // esi
  const _s__ThrowInfo *v88; // edi
  const _s__ThrowInfo *v89; // eax
  unsigned int j; // ecx
  _DWORD *v91; // eax
  struct GTessellator::ScanChainType *v92; // [esp-4h] [ebp-6Ch]
  struct GTessellator::ScanChainType *v93; // [esp-4h] [ebp-6Ch]
  unsigned int v94; // [esp+0h] [ebp-68h]
  unsigned int v95; // [esp+0h] [ebp-68h]
  unsigned int v96; // [esp+0h] [ebp-68h]
  unsigned int v97; // [esp+4h] [ebp-64h]
  unsigned int v98; // [esp+4h] [ebp-64h]
  float v99[5]; // [esp+14h] [ebp-54h] BYREF
  int v100; // [esp+28h] [ebp-40h]
  unsigned int v101; // [esp+2Ch] [ebp-3Ch]
  unsigned int v102; // [esp+30h] [ebp-38h]
  float v103; // [esp+34h] [ebp-34h]
  unsigned int i; // [esp+38h] [ebp-30h]
  unsigned int v105; // [esp+3Ch] [ebp-2Ch]
  int v106; // [esp+40h] [ebp-28h]
  unsigned int prevAbove; // [esp+44h] [ebp-24h]
  int v108; // [esp+48h] [ebp-20h]
  const pDNameNode **v109; // [esp+4Ch] [ebp-1Ch]
  struct GTessellator::ScanChainType *v110; // [esp+50h] [ebp-18h]
  unsigned int v111; // [esp+54h] [ebp-14h]
  struct GTessellator::ScanChainType *v112; // [esp+58h] [ebp-10h]
  struct GTessellator::ScanChainType *styleAbove; // [esp+5Ch] [ebp-Ch]
  unsigned int below; // [esp+60h] [ebp-8h]
  unsigned int above; // [esp+64h] [ebp-4h]

  v4 = a2;
  v5 = 0;
  *(this + 75) = nullptr;
  for ( *(float *)&i = 0.0; v5 < v4[1]; i = v5 )
  {
    v6 = *(_DWORD *)(*v4 + 4 * v5);
    v7 = (*(_BYTE *)(v6 + 44) & 4) == 0;
    *(_DWORD *)(v6 + 52) = v5;
    if ( !v7 )
    {
      v8 = (int)*(this + 75);
      v9 = &(*(this + 74))->attributes + 3 * v8;
      *(this + 75) = (GTessellator)(v8 + 1);
      *v9 = v6;
      v9[1] = 0;
      v9[2] = -1;
      v5 = i;
      v4 = a2;
    }
    ++v5;
  }
  below = 0;
  v99[0] = yb;
  above = 0;
  prevAbove = -1;
  v112 = nullptr;
  styleAbove = nullptr;
  v100 = 0;
  v108 = 0;
  v111 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = (unsigned int)*(this + 72);
        if ( below >= v10 || above >= (unsigned int)*(this + 75) )
          break;
        v11 = (struct GTessellator::ScanChainType *)((char *)*(this + 71) + v108);
        v12 = (const pDNameNode **)((char *)*(this + 74) + v111);
        v13 = *v12;
        me = (*v12)[6].me;
        v15 = *(DName **)(*(_DWORD *)v11 + 52);
        v110 = v11;
        v109 = v12;
        if ( me == v15 )
        {
          if ( v13[3].me != (DName *)v13[4].__vftable || v13[4].me != (DName *)v13[5].__vftable )
          {
            v20 = (int)*(this + 15);
            v21 = yb;
            if ( yb == *(float *)(*(_DWORD *)(v20 + 4 * ((unsigned int)v13->length >> 10))
                                + 8 * ((int)v13->length & 0x3FF)
                                + 4) )
            {
              v19 = (int)GTessellator::addEventVertex(
                           (unsigned int *)this,
                           result: (const DNameStatusNode *)(*(_DWORD *)(v20 + 4 * ((unsigned int)v13->length >> 10))
                                                   + 8 * ((int)v13->length & 0x3FF)));
LABEL_30:
              v12 = v109;
              v11 = v110;
              goto LABEL_31;
            }
            v22 = v13->__vftable;
            if ( ((int)v13[5].me & 2) != 0
              && v21 == *(float *)(*(_DWORD *)(v20 + 4 * ((unsigned int)v22->getLastChar >> 10))
                                 + 8 * ((int)v22->getLastChar & 0x3FF)
                                 + 4) )
            {
              v19 = (int)GTessellator::addEventVertex(
                           (unsigned int *)this,
                           result: (const DNameStatusNode *)(*(_DWORD *)(v20 + 4 * ((unsigned int)v22->getLastChar >> 10))
                                                   + 8 * ((int)v22->getLastChar & 0x3FF)));
              goto LABEL_30;
            }
            v23 = *(_DWORD *)(v20 + 4 * ((unsigned int)v22->length >> 10));
            *(float *)&i = (v21 - *(float *)(v23 + 8 * ((int)v22->length & 0x3FF) + 4)) * *(float *)&v22->getString
                         + *(float *)(v23 + 8 * ((int)v22->length & 0x3FF));
            if ( *((float *)this + 70) < v21 )
            {
              v105 = i;
              *(this + 69) = (GTessellator)i;
              *(float *)&v106 = v21;
              *(this + 70) = (GTessellator)v106;
              v24 = (unsigned int)*(this + 65) >> 10;
              if ( v24 >= (unsigned int)*(this + 66) )
                GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
                  this: (unsigned int *)this + 65,
                  a2: (unsigned int)*(this + 65) >> 10);
              v25 = *(&(*(this + 68))->attributes + v24);
              goto LABEL_24;
            }
            if ( *((float *)this + 60) < *(float *)&i - *((float *)this + 69) )
            {
              v102 = i;
              *(this + 69) = (GTessellator)i;
              v103 = v21;
              *((float *)this + 70) = v103;
              v27 = (unsigned int)*(this + 65) >> 10;
              if ( v27 >= (unsigned int)*(this + 66) )
                GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
                  this: (unsigned int *)this + 65,
                  a2: (unsigned int)*(this + 65) >> 10);
              v25 = *(&(*(this + 68))->attributes + v27);
LABEL_24:
              v26 = (unsigned int)*(this + 65) & 0x3FF;
              *(_DWORD *)(v25 + 8 * v26) = *(this + 69);
              *(_DWORD *)(v25 + 8 * v26 + 4) = *(this + 70);
              *(this + 65) = (GTessellator)((char *)*(this + 65) + 1);
            }
            v19 = (int)&(*(this + 65))[-1].pCatchableTypeArray + 3;
            goto LABEL_30;
          }
          if ( ((int)v13[5].me & 8) != 0
            && (length = (unsigned int)v13->length,
                v17 = (int)*(this + 15),
                v18 = *(_DWORD *)(v17 + 4 * (length >> 10)),
                i = length,
                yb == *(float *)(v18 + 8 * (length & 0x3FF) + 4)) )
          {
            v19 = (int)GTessellator::addEventVertex(
                         (unsigned int *)this,
                         result: (const DNameStatusNode *)(*(_DWORD *)(v17 + 4 * (i >> 10)) + 8 * (i & 0x3FF)));
          }
          else
          {
            v19 = -1;
          }
LABEL_31:
          v12[2] = (const pDNameNode *)v19;
          *((_DWORD *)v11 + 2) = v19;
          ++below;
          ++above;
          v108 += 12;
          v111 += 12;
        }
        else if ( me >= v15 )
        {
          v28 = GTessellator::addEventVertex(this, mc: *(const pDNameNode *const *)v11, yb, x: true);
          ++below;
          v108 += 12;
          *((_DWORD *)v11 + 2) = v28;
        }
        else
        {
          ++above;
          v111 += 12;
          v12[2] = (const pDNameNode *)GTessellator::addEventVertex(this, mc: v13, yb, x: true);
        }
      }
      if ( above >= (unsigned int)*(this + 75) )
        break;
      v29 = (int)*(this + 74);
      v30 = v111;
      v31 = GTessellator::addEventVertex(this, mc: *(const pDNameNode *const *)(v29 + v111), yb, x: true);
      ++above;
      *(_DWORD *)(v29 + v111 + 8) = v31;
      v111 = v30 + 12;
    }
    if ( below >= v10 )
      break;
    v32 = (int)*(this + 71);
    v33 = v108;
    v34 = GTessellator::addEventVertex(this, mc: *(const pDNameNode *const *)(v32 + v108), yb, x: true);
    ++below;
    *(_DWORD *)(v32 + v108 + 8) = v34;
    v108 = v33 + 12;
  }
  v35 = 0;
  below = 0;
LABEL_40:
  above = v35;
  while ( 2 )
  {
    while ( 2 )
    {
      while ( 1 )
      {
        v36 = (unsigned int)*(this + 72);
        if ( below >= v36 || above >= (unsigned int)*(this + 75) )
          break;
        v37 = (int)*(this + 71);
        v38 = (int)*(this + 74);
        v39 = *(_DWORD *)(v37 + 12 * below + 8);
        v40 = (struct GTessellator::ScanChainType *)(12 * below + v37);
        i = 12 * below;
        v41 = (struct GTessellator::ScanChainType *)(12 * above + v38);
        v106 = 12 * above;
        v110 = v40;
        v42 = 1;
        v111 = v39;
        if ( v39 != *((_DWORD *)v41 + 2) )
          v42 = 3 - (*(_DWORD *)(*(_DWORD *)v41 + 52) < *(_DWORD *)(*(_DWORD *)v40 + 52));
        v43 = v42 - 1;
        if ( v43 == 0 )
        {
          if ( v39 == -1 )
          {
            if ( v100 != 0 )
              GTessellator::connectStarting(this, scan: v112, upperBase: (DNameNode)v99);
LABEL_92:
            *((_DWORD *)v41 + 1) = *((_DWORD *)v40 + 1);
            goto LABEL_93;
          }
          GTessellator::growMonotoneAndConnect(this, styleAbove: v112, vertex: v111, __formal: 0);
          GTessellator::growMonotoneAndConnect(this, styleAbove, vertex: v111, __formal: 0);
          if ( v100 != 0 )
            GTessellator::connectStarting(this, scan: v112, upperBase: (DNameNode)v99);
          v108 = v106;
          v106 = below + 1;
          prevAbove = above + 1;
          while ( 1 )
          {
            v54 = nullptr;
            v55 = nullptr;
            if ( v106 < (unsigned int)*(this + 72) )
              v54 = (char *)&(*(this + 71))->pCatchableTypeArray + i;
            if ( prevAbove < (unsigned int)*(this + 75) )
              v55 = (char *)&(*(this + 74))->pCatchableTypeArray + v108;
            if ( v54 != nullptr )
            {
              if ( v55 == nullptr )
                goto LABEL_78;
              if ( *((_DWORD *)v54 + 2) == *((_DWORD *)v55 + 2) )
                goto LABEL_86;
            }
            if ( v55 != nullptr && *((_DWORD *)v55 + 2) == v111 )
            {
              ++above;
              ++prevAbove;
              v57 = v41;
              v58 = (int)*(this + 74);
              v59 = v108 + 12;
              *((_DWORD *)v57 + 1) = 0;
              styleAbove = v57;
              v60 = *(struct GTessellator::ScanChainType **)(*(_DWORD *)v57 + 40);
              v41 = (struct GTessellator::ScanChainType *)(v59 + v58);
              v108 = v59;
              v7 = *((_BYTE *)&(*(this + 9))->attributes + (_DWORD)v60) == 0;
              v109 = (const pDNameNode **)v41;
              v112 = v60;
              if ( !v7 )
              {
                v61 = (unsigned int)*(this + 85) >> 6;
                if ( v61 >= (unsigned int)*(this + 86) )
                  GArrayPagedBase<GTessellator::MonotoneType,6,64,GAllocatorPagedLH_POD<GTessellator::MonotoneType,133>>::allocatePage(
                    this: (unsigned int *)this + 85,
                    a2: (unsigned int)*(this + 85) >> 6);
                v62 = v112;
                v63 = (_DWORD *)(*(&(*(this + 88))->attributes + v61) + 24 * ((unsigned int)*(this + 85) & 0x3F));
                *v63 = 0;
                v63[1] = -1;
                v63[2] = -1;
                v63[3] = -1;
                v63[4] = v62;
                v63[5] = 0;
                *(this + 85) = (GTessellator)((char *)*(this + 85) + 1);
                v94 = v111 | 0x40000000;
                v92 = styleAbove;
                *((_DWORD *)styleAbove + 1) = *(&(*(this + 88))->attributes
                                              + (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) >> 6))
                                            + 24 * (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) & 0x3F);
                GTessellator::growMonotoneAndConnect(this, styleAbove: v92, vertex: v94, __formal: 1);
                v41 = (struct GTessellator::ScanChainType *)v109;
                v40 = v110;
              }
              GTessellator::growMonotoneAndConnect(this, styleAbove, vertex: v111, __formal: 1);
              continue;
            }
LABEL_78:
            if ( v54 == nullptr || *((_DWORD *)v54 + 2) != v111 )
            {
LABEL_86:
              i = v111 | 0x40000000;
              GTessellator::growMonotoneAndConnect(this, styleAbove: v40, vertex: v111 | 0x40000000, __formal: 0);
              v64 = *(_DWORD *)v41;
              if ( *(_DWORD *)(*(_DWORD *)v40 + 36) == *(_DWORD *)(*(_DWORD *)v41 + 40) )
              {
                GTessellator::growMonotoneAndConnect(this, styleAbove, vertex: v111, __formal: 0);
                goto LABEL_92;
              }
              *((_DWORD *)v41 + 1) = 0;
              v65 = *(DNameNode **)(v64 + 40);
              if ( *((_BYTE *)&(*(this + 9))->attributes + (_DWORD)v65) != 0 )
              {
                started = GTessellator::startMonotone((unsigned int *)this, result: v65);
                v95 = i;
                *((_DWORD *)v41 + 1) = started;
                GTessellator::growMonotoneAndConnect(this, styleAbove: v41, vertex: v95, __formal: 1);
              }
LABEL_93:
              ++below;
              prevAbove = above;
              v112 = v40;
              styleAbove = v41;
              v35 = above + 1;
              goto LABEL_40;
            }
            v56 = v40;
            v40 = (struct GTessellator::ScanChainType *)((char *)&(*(this + 71))->pCatchableTypeArray + i);
            i += 12;
            ++below;
            ++v106;
            v112 = v56;
            v110 = v40;
            GTessellator::growMonotoneAndConnect(this, styleAbove: v56, vertex: v111 | 0x40000000, __formal: 1);
            GTessellator::growMonotoneAndConnect(this, styleAbove: v112, vertex: v111, __formal: 1);
          }
        }
        v44 = v43 - 1;
        if ( v44 != 0 )
        {
          if ( v44 == 1 )
          {
            v45 = v112;
            GTessellator::growMonotoneAndConnect(this, styleAbove: v112, vertex: v111, __formal: 1);
            GTessellator::growMonotoneAndConnect(
              this,
              styleAbove: v40,
              vertex: *((_DWORD *)v40 + 2) | 0x40000000,
              __formal: 1);
            if ( v100 != 0 )
              GTessellator::connectStarting(this, scan: v45, upperBase: (DNameNode)v99);
            GTessellator::addPendingEnd(this, a2: styleAbove, a3: v40, a4: yb);
            ++below;
            prevAbove = -1;
            v112 = v40;
          }
        }
        else
        {
          if ( v112 == nullptr
            || (v46 = *((_DWORD *)v112 + 1)) == 0
            || *((_BYTE *)&(*(this + 9))->attributes + *(_DWORD *)(v46 + 16)) == 0 )
          {
            GTessellator::growMonotoneAndConnect(this, styleAbove, vertex: *((_DWORD *)v41 + 2), __formal: 1);
            v50 = *(_DWORD *)v41;
            v51 = *((_DWORD *)v41 + 2);
            *((_DWORD *)v41 + 1) = 0;
            v52 = *(DNameNode **)(v50 + 40);
            v53 = v51 | 0x40000000;
            if ( *((_BYTE *)&(*(this + 9))->attributes + (_DWORD)v52) != 0 )
            {
              *((_DWORD *)v41 + 1) = GTessellator::startMonotone((unsigned int *)this, result: v52);
              GTessellator::growMonotoneAndConnect(this, styleAbove: v41, vertex: v53, __formal: 1);
            }
LABEL_64:
            ++above;
            styleAbove = v41;
            continue;
          }
          if ( v100 != 0 )
          {
            ++v100;
          }
          else
          {
            v99[1] = *(float *)(*(_DWORD *)v41 + 32);
            LODWORD(v99[4]) = above;
            v100 = 1;
            v101 = prevAbove;
          }
          if ( styleAbove == nullptr )
            goto LABEL_64;
          v47 = *((_DWORD *)styleAbove + 1);
          if ( v47 == 0 )
            goto LABEL_64;
          v48 = *(_DWORD *)(v47 + 20);
          if ( v48 == 0 || yb != *(float *)v48 )
            goto LABEL_64;
          v49 = *((_DWORD *)v41 + 2);
          ++above;
          *(_DWORD *)(v48 + 12) = v49;
          styleAbove = v41;
        }
      }
      if ( above < (unsigned int)*(this + 75) )
      {
        v67 = (const pDNameNode **)*(this + 74) + 3 * above;
        v68 = (unsigned int)v67[2];
        v109 = v67;
        if ( styleAbove != nullptr )
        {
          v69 = *((int **)styleAbove + 1);
          if ( v69 != nullptr )
          {
            v70 = (float *)v69[5];
            i = (unsigned int)v70;
            if ( v70 != nullptr )
            {
              v71 = v68 & 0xBFFFFFFF;
              if ( *(float *)(*(&(*(this + 68))->attributes + (v71 >> 10)) + 8 * (v71 & 0x3FF) + 4) == *v70 )
              {
                *(_DWORD *)(i + 12) = v71;
              }
              else
              {
                v97 = (unsigned int)v67[2];
                if ( (v97 & 0x40000000) != 0 )
                  GTessellator::connectPendingToLeft(this, a2: styleAbove, targetVertex: v97);
                else
                  GTessellator::connectPendingToRight(this, styleAbove, targetVertex: v97);
              }
            }
            else
            {
              GTessellator::growMonotone(this, m: v69, vertex: v68);
            }
          }
        }
        v106 = (unsigned int)v67[2] | 0x40000000;
        v72 = *v67;
        v67[1] = nullptr;
        v73 = (unsigned int)v72[5].__vftable;
        v7 = *((_BYTE *)&(*(this + 9))->attributes + v73) == 0;
        i = v73;
        if ( !v7 )
        {
          v74 = (unsigned int)*(this + 85) >> 6;
          if ( v74 >= (unsigned int)*(this + 86) )
            GArrayPagedBase<GTessellator::MonotoneType,6,64,GAllocatorPagedLH_POD<GTessellator::MonotoneType,133>>::allocatePage(
              this: (unsigned int *)this + 85,
              a2: (unsigned int)*(this + 85) >> 6);
          v75 = i;
          v76 = (_DWORD *)(*(&(*(this + 88))->attributes + v74) + 24 * ((unsigned int)*(this + 85) & 0x3F));
          *v76 = 0;
          v76[1] = -1;
          v76[2] = -1;
          v76[3] = -1;
          v76[4] = v75;
          v76[5] = 0;
          *(this + 85) = (GTessellator)((char *)*(this + 85) + 1);
          v96 = v106;
          v93 = (struct GTessellator::ScanChainType *)v109;
          v109[1] = (const pDNameNode *)(*(&(*(this + 88))->attributes
                                         + (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) >> 6))
                                       + 24 * (((unsigned int)&(*(this + 85))[-1].pCatchableTypeArray + 3) & 0x3F));
          GTessellator::growMonotoneAndConnect(this, styleAbove: v93, vertex: v96, __formal: 1);
          v67 = v109;
        }
        ++above;
        styleAbove = (struct GTessellator::ScanChainType *)v67;
        continue;
      }
      break;
    }
    if ( below < v36 )
    {
      v77 = (int)*(this + 71);
      v78 = *(_DWORD *)(v77 + 12 * below + 8);
      v79 = (struct GTessellator::ScanChainType *)(v77 + 12 * below);
      v110 = v79;
      if ( v112 != nullptr )
      {
        v80 = *((int **)v112 + 1);
        if ( v80 != nullptr )
        {
          v81 = (float *)v80[5];
          i = (unsigned int)v81;
          if ( v81 != nullptr )
          {
            v82 = v78 & 0xBFFFFFFF;
            if ( *(float *)(*(&(*(this + 68))->attributes + (v82 >> 10)) + 8 * (v82 & 0x3FF) + 4) == *v81 )
            {
              *(_DWORD *)(i + 12) = v82;
            }
            else
            {
              v98 = *((_DWORD *)v79 + 2);
              if ( (v98 & 0x40000000) != 0 )
                GTessellator::connectPendingToLeft(this, a2: v112, targetVertex: v98);
              else
                GTessellator::connectPendingToRight(this, styleAbove: v112, targetVertex: v98);
            }
          }
          else
          {
            GTessellator::growMonotone(this, m: v80, vertex: v78);
          }
        }
      }
      v83 = *((int **)v79 + 1);
      v84 = *((_DWORD *)v79 + 2) | 0x40000000;
      if ( v83 != nullptr )
      {
        v85 = (float *)v83[5];
        i = (unsigned int)v85;
        if ( v85 != nullptr )
        {
          v79 = v110;
          if ( *(float *)(*(&(*(this + 68))->attributes + ((v84 & 0xBFFFFFFF) >> 10)) + 8 * (v84 & 0x3FF) + 4) == *v85 )
          {
            *(_DWORD *)(i + 12) = v84 & 0xBFFFFFFF;
          }
          else if ( (v84 & 0x40000000) != 0 )
          {
            GTessellator::connectPendingToLeft(this, a2: v110, targetVertex: v84);
          }
          else
          {
            GTessellator::connectPendingToRight(this, styleAbove: v110, targetVertex: v84);
          }
        }
        else
        {
          GTessellator::growMonotone(this, m: v83, vertex: v84);
        }
      }
      if ( v100 != 0 )
        GTessellator::connectStarting(this, scan: v112, upperBase: (DNameNode)v99);
      GTessellator::addPendingEnd(this, a2: styleAbove, a3: v79, a4: yb);
      ++below;
      prevAbove = -1;
      v112 = v79;
      continue;
    }
    break;
  }
  v86 = this + 74;
  v87 = this + 71;
  i = (unsigned int)v86;
  if ( v86 != v87 )
  {
    v88 = v86[1];
    if ( v88 > v87[2] )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*v87);
      v87[2] = v88;
      if ( v88 != nullptr )
      {
        LODWORD(yb) = 133;
        v89 = (const _s__ThrowInfo *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                       this: GMemory::pGlobalHeap,
                                       a2: v87,
                                       a3: 12 * (_DWORD)v88,
                                       a4: &yb);
        v86 = (GTessellator *)i;
      }
      else
      {
        v89 = nullptr;
      }
      *v87 = v89;
    }
    v87[1] = v88;
    if ( v88 != nullptr )
      memmove(dst: (unsigned __int8 *)*v87, src: (unsigned __int8 *)*v86, count: 12 * (_DWORD)v88);
  }
  for ( j = 0; j < a2[1]; v91[9] = v91[10] )
  {
    v91 = *(_DWORD **)(*a2 + 4 * j);
    v91[7] = v91[8];
    ++j;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192C20
// Name: private: void GTessellator::processInterior(float,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::processInterior(int this, float yb, float yTop, int yt2)
{
  double v4; // st7
  int v5; // ebx
  unsigned int v6; // esi
  int v8; // edx
  unsigned int v9; // ecx
  double v10; // st6
  double v11; // st7
  int v12; // ecx
  int v13; // ebx
  unsigned int v14; // edi
  int v15; // edx
  unsigned int v16; // ecx
  unsigned int startIn; // [esp+10h] [ebp-Ch]
  unsigned int startIna; // [esp+10h] [ebp-Ch]
  float yt; // [esp+18h] [ebp-4h]
  float yt2a; // [esp+2Ch] [ebp+10h]

  v4 = yb;
  v5 = *(_DWORD *)(this + 188);
  yt = yb;
  v6 = 0;
  startIn = v5;
  if ( v5 < 4 )
  {
    v10 = yb;
LABEL_10:
    while ( v6 < v5 )
    {
      yt = *(float *)(*(_DWORD *)(*(_DWORD *)(this + 200) + 4 * (v6 >> 6)) + 12 * (v6 & 0x3F) + 8);
      v10 = yt;
      if ( yt > v4 )
        break;
      ++v6;
      yt2 = 1;
    }
  }
  else
  {
    v8 = *(_DWORD *)(this + 200);
    v9 = 2;
    while ( 1 )
    {
      yt = *(float *)(*(_DWORD *)(v8 + 4 * (v6 >> 6)) + 12 * (v6 & 0x3F) + 8);
      v10 = yt;
      if ( yt > v4 )
        break;
      yt2 = 1;
      yt = *(float *)(*(_DWORD *)(v8 + 4 * ((v9 - 1) >> 6)) + 12 * (((_BYTE)v9 - 1) & 0x3F) + 8);
      v10 = yt;
      if ( yt > v4 )
      {
        ++v6;
        break;
      }
      yt = *(float *)(*(_DWORD *)(v8 + 4 * (v9 >> 6)) + 12 * (v9 & 0x3F) + 8);
      v10 = yt;
      if ( yt > v4 )
      {
        v6 += 2;
        break;
      }
      yt = *(float *)(*(_DWORD *)(v8 + 4 * ((v9 + 1) >> 6)) + 12 * ((v9 + 1) & 0x3F) + 8);
      v10 = yt;
      if ( yt > v4 )
      {
        v6 += 3;
        break;
      }
      v5 = startIn;
      v6 += 4;
      v9 += 4;
      if ( v6 >= startIn - 3 )
        goto LABEL_10;
    }
  }
  v11 = v10;
  GTessellator::swapChains((GTessellator *)this, startIn: 0, a3: v6);
  v13 = v12;
  if ( yt2 != 0 )
  {
    GTessellator::perceiveStyles(this: v12, result: (_HeapManager::Block *)(v12 + 152));
    v11 = yt;
  }
  v14 = *(_DWORD *)(v13 + 188);
  if ( v6 < v14 )
  {
    while ( 1 )
    {
      yt2a = v11;
      startIna = v6;
      if ( v6 < v14 )
      {
        if ( (int)(v14 - v6) < 4 )
        {
LABEL_32:
          while ( v6 < v14 )
          {
            yt2a = *(float *)(*(_DWORD *)(*(_DWORD *)(v13 + 200) + 4 * (v6 >> 6)) + 12 * (v6 & 0x3F) + 8);
            if ( yt2a > v11 )
              break;
            ++v6;
          }
        }
        else
        {
          v15 = *(_DWORD *)(v13 + 200);
          v16 = v6 + 2;
          while ( 1 )
          {
            yt2a = *(float *)(*(_DWORD *)(v15 + 4 * (v6 >> 6)) + 12 * (v6 & 0x3F) + 8);
            if ( yt2a > v11 )
              break;
            yt2a = *(float *)(*(_DWORD *)(v15 + 4 * ((v16 - 1) >> 6)) + 12 * (((_BYTE)v16 - 1) & 0x3F) + 8);
            if ( yt2a > v11 )
            {
              ++v6;
              break;
            }
            yt2a = *(float *)(*(_DWORD *)(v15 + 4 * (v16 >> 6)) + 12 * (v16 & 0x3F) + 8);
            if ( yt2a > v11 )
            {
              v6 += 2;
              break;
            }
            yt2a = *(float *)(*(_DWORD *)(v15 + 4 * ((v16 + 1) >> 6)) + 12 * ((v16 + 1) & 0x3F) + 8);
            if ( yt2a > v11 )
            {
              v6 += 3;
              break;
            }
            v6 += 4;
            v16 += 4;
            if ( v6 >= v14 - 3 )
            {
              v13 = this;
              goto LABEL_32;
            }
          }
          v13 = this;
        }
      }
      GTessellator::perceiveStyles(this: v13, result: (_HeapManager::Block *)(v13 + 152));
      GTessellator::sweepScanbeam(this: (GTessellator *)v13, a2: (_DWORD *)(v13 + 152), yb);
      GTessellator::swapChains(this: (GTessellator *)v13, startIn: startIna, a3: v6);
      v14 = *(_DWORD *)(v13 + 188);
      yb = yt;
      yt = yt2a;
      if ( v6 >= v14 )
        break;
      v11 = yt2a;
    }
  }
  GTessellator::perceiveStyles(this: v13, result: (_HeapManager::Block *)(v13 + 140));
  if ( yTop > (double)yt )
    GTessellator::sweepScanbeam(this: (GTessellator *)v13, a2: (_DWORD *)(v13 + 140), yb: yt);
}

//------------------------------------------------------------------------------
// Address: 0x10192F30
// Name: public: void GTessellator::Monotonize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::Monotonize(GTessellator *this)
{
  const _s__ThrowInfo *v2; // edi
  bool v3; // zf
  const _s__ThrowInfo *v4; // edi
  _DWORD **v5; // edx
  int v6; // edi
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int *v10; // ecx
  int Scanbeam; // eax
  char v12; // bl
  unsigned int v13; // edx
  GTessellator v14; // edi
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // ecx
  float *v18; // eax
  unsigned int startMc; // [esp+1Ch] [ebp-10h]
  float startMca; // [esp+1Ch] [ebp-10h]
  float yb; // [esp+20h] [ebp-Ch]
  unsigned int v22; // [esp+24h] [ebp-8h]
  float yt; // [esp+28h] [ebp-4h]

  if ( *(this + 31) != nullptr )
  {
    v2 = (const _s__ThrowInfo *)((char *)&(*(this + 55))->attributes + 1);
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
      this: (EHExceptionRecord *)(this + 51),
      cap: (unsigned int)v2,
      extraTail: 0x20u);
    *(this + 52) = v2;
    GTessellator::SetStyleVisibility(this, a2: (unsigned int)&(*(this + 55))->attributes + 1, a3: true);
    v3 = *((_BYTE *)this + 4) == 0;
    *((float *)this + 69) = -1.0e30;
    *((float *)this + 70) = -1.0e30;
    if ( !v3 )
      GTessellator::optimizeDirection(this);
    GTessellator::prepareChainsAndScanbeams(this);
    v22 = 0;
    startMc = 0;
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
      this: (EHExceptionRecord *)(this + 35),
      cap: (unsigned int)*(this + 24),
      extraTail: 0x20u);
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
      this: (EHExceptionRecord *)(this + 38),
      cap: (unsigned int)*(this + 24),
      extraTail: 0x20u);
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
      this: (EHExceptionRecord *)(this + 41),
      cap: (unsigned int)*(this + 24),
      extraTail: 0x20u);
    v4 = *(this + 24);
    GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
      this: (EHExceptionRecord *)(this + 44),
      cap: (unsigned int)v4,
      extraTail: 0x20u);
    *(this + 45) = v4;
    GArrayUnsafeBase<GTessellator::ScanChainType,GAllocatorLH_POD<GTessellator::ScanChainType,133>>::Reserve(
      this: (int)(this + 71),
      a2: (unsigned int)*(this + 24),
      a3: 32);
    GArrayUnsafeBase<GTessellator::ScanChainType,GAllocatorLH_POD<GTessellator::ScanChainType,133>>::Reserve(
      this: (int)(this + 74),
      a2: (unsigned int)*(this + 24),
      a3: 32);
    v5 = (_DWORD **)*(this + 34);
    v6 = (int)*(this + 15);
    *(this + 77) = nullptr;
    *(this + 81) = nullptr;
    yt = *(float *)(*(_DWORD *)(v6 + 4 * (**v5 >> 10)) + 8 * (**v5 & 0x3FF) + 4);
    yb = yt;
    if ( *(this + 31) != nullptr )
    {
      do
      {
        v7 = v22 + 1;
        v22 = v7;
        if ( v7 < (unsigned int)*(this + 31) )
          yt = *(float *)(*(&(*(this + 15))->attributes
                          + (*(_DWORD *)(*(&(*(this + 34))->attributes + (v7 >> 10)) + 4 * (v7 & 0x3FF)) >> 10))
                        + 8 * (*(_DWORD *)(*(&(*(this + 34))->attributes + (v7 >> 10)) + 4 * (v7 & 0x3FF)) & 0x3FF)
                        + 4);
        v8 = startMc;
        v9 = startMc;
        if ( startMc < (unsigned int)*(this + 29) )
        {
          v10 = &(*(this + 28))->attributes + startMc;
          do
          {
            if ( *(float *)(*v10 + 4) > (double)yb )
              break;
            ++v8;
            ++v10;
          }
          while ( v8 < (unsigned int)*(this + 29) );
          startMc = v8;
        }
        Scanbeam = GTessellator::nextScanbeam(this, yb, yt, startMc: v9, j: v8 - v9);
        v12 = Scanbeam;
        if ( *(this + 47) != nullptr )
        {
          GTessellator::processInterior((int)this, yb, yTop: yt, yt2: Scanbeam);
        }
        else
        {
          if ( Scanbeam != 0 )
            GTessellator::perceiveStyles((int)this, result: (_HeapManager::Block *)(this + 35));
          GTessellator::sweepScanbeam(this, a2: this + 35, yb);
        }
        if ( (v12 & 2) != 0 )
        {
          v13 = 0;
          v14 = nullptr;
          if ( *(this + 36) != nullptr )
          {
            do
            {
              v15 = (int)*(this + 35);
              v16 = *(_DWORD *)(v15 + 4 * v13);
              if ( (*(_BYTE *)(v16 + 44) & 2) == 0 )
              {
                *(_DWORD *)(v15 + 4 * (_DWORD)v14) = v16;
                v14 = (GTessellator)((char *)v14 + 1);
              }
              ++v13;
            }
            while ( v13 < (unsigned int)*(this + 36) );
          }
          if ( v14 < *(this + 36) )
            *(this + 36) = v14;
          v7 = v22;
        }
        yb = yt;
      }
      while ( v7 < (unsigned int)*(this + 31) );
    }
    if ( *((_BYTE *)this + 8) != 0 )
    {
      v17 = 0;
      if ( *(this + 65) != nullptr )
      {
        do
        {
          v18 = (float *)(*(&(*(this + 68))->attributes + (v17 >> 10)) + 8 * (v17 & 0x3FF));
          startMca = v18[1];
          ++v17;
          v18[1] = -*v18;
          *v18 = startMca;
        }
        while ( v17 < (unsigned int)*(this + 65) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101931C0
// Name: public: void GTessellator::Monotonize(class GCompoundShape const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::Monotonize(GTessellator *this, const struct GCompoundShape *a2, int addStyle)
{
  GTessellator::Clear(this);
  GTessellator::AddShape(this, a2, addStyle);
  GTessellator::Monotonize(this);
}
