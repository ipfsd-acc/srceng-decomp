// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_movesolver.cpp
// Functions: 3
// ============================================================

#include "game\server\ai_movesolver.h"

//------------------------------------------------------------------------------
// Address: 0x100616F0
// Name: private: void CAI_MoveSolver::NormalizeSuggestions(struct AI_MoveSuggestion_t __near *,struct AI_MoveSuggestion_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveSolver::NormalizeSuggestions(
        CAI_MoveSolver *this,
        AI_MoveSuggestion_t *pBegin,
        AI_MoveSuggestion_t *pEnd)
{
  AI_Arc_t *p_arc; // eax
  float span; // xmm1_4
  float min; // xmm2_4
  float center; // xmm0_4
  float v7; // xmm0_4

  if ( pBegin != pEnd )
  {
    p_arc = &pBegin->arc;
    do
    {
      span = p_arc[-1].span;
      if ( span >= 0.0099999998 )
      {
        min = g_AI_MoveSuggWeights[LODWORD(p_arc[-1].center)].min;
        p_arc[-1].span = (float)((float)(g_AI_MoveSuggWeights[LODWORD(p_arc[-1].center)].max - min) * span) + min;
      }
      else
      {
        p_arc[-1].span = 0.0;
      }
      center = p_arc->center;
      if ( p_arc->center < 0.0 )
      {
        do
          center = center + 360.0;
        while ( center < 0.0 );
        p_arc->center = center;
      }
      v7 = p_arc->center;
      if ( p_arc->center >= 360.0 )
      {
        do
          v7 = v7 - 360.0;
        while ( v7 >= 360.0 );
        p_arc->center = v7;
      }
      p_arc += 3;
    }
    while ( &p_arc[-1] != (AI_Arc_t *)pEnd );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061B90
// Name: public: void CAI_MoveSolver::VisualizeRegulations(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveSolver::VisualizeRegulations(CAI_MoveSolver *this, const Vector *origin)
{
  int m_Size; // ebx
  AI_MoveSuggestion_t *m_pMemory; // edi
  int v5; // ebx
  float *p_center; // edi
  float v8; // xmm0_4
  Vector *v9; // eax
  float x; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float y; // xmm1_4
  float v22; // xmm7_4
  float z; // xmm2_4
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > regulations; // [esp+10h] [ebp-5Ch] BYREF
  Vector v25; // [esp+24h] [ebp-48h] BYREF
  Vector v26; // [esp+30h] [ebp-3Ch] BYREF
  Vector result; // [esp+3Ch] [ebp-30h] BYREF
  Vector side2; // [esp+48h] [ebp-24h] BYREF
  Vector side1; // [esp+54h] [ebp-18h] BYREF
  Vector mid; // [esp+60h] [ebp-Ch] BYREF
  float flMaxAngle; // [esp+74h] [ebp+8h]

  if ( this->m_Regulations.m_Size != 0 )
  {
    memset(&regulations, 0, sizeof(regulations));
    CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::AddVectorToTail(
      this: &regulations,
      src: &this->m_Regulations);
    m_Size = regulations.m_Size;
    m_pMemory = regulations.m_Memory.m_pMemory;
    CAI_MoveSolver::NormalizeSuggestions(
      this,
      pBegin: regulations.m_Memory.m_pMemory,
      pEnd: &regulations.m_Memory.m_pMemory[regulations.m_Size]);
    v5 = m_Size - 1;
    if ( v5 >= 0 )
    {
      p_center = &m_pMemory[v5].arc.center;
      do
      {
        v8 = p_center[1] * 0.5;
        flMaxAngle = v8 + *p_center;
        side1 = *UTIL_YawToVector(&result, yaw: *p_center - v8);
        side2 = *UTIL_YawToVector(result: &v26, yaw: flMaxAngle);
        v9 = UTIL_YawToVector(result: &v25, yaw: *p_center);
        x = v9->x;
        mid = *v9;
        v11 = *(p_center - 1);
        if ( v11 < 0.0 )
        {
          v12 = (float)((float)(v11 * -1.0) * 40.0) + 10.0;
          mid.x = x * v12;
          mid.y = mid.y * v12;
          v13 = side1.z * v12;
          mid.z = mid.z * v12;
          v14 = side1.x * v12;
          v15 = side1.y * v12;
          v16 = side2.x * v12;
          v17 = side2.y * v12;
          v18 = side2.z * v12;
          v19 = origin->x;
          v20 = origin->x + v14;
          y = origin->y;
          side1.x = v20;
          v22 = y + v15;
          z = origin->z;
          side1.y = v22;
          mid.x = v19 + mid.x;
          side2.x = v19 + v16;
          side2.y = y + v17;
          side1.z = z + v13;
          side2.z = z + v18;
          mid.y = y + mid.y;
          mid.z = z + mid.z;
          NDebugOverlay::Triangle(
            p1: origin,
            p2: &mid,
            p3: &side1,
            r: 255,
            g: 0,
            b: 0,
            a: 48,
            noDepthTest: true,
            duration: 0.1);
          NDebugOverlay::Triangle(
            p1: origin,
            p2: &side2,
            p3: &mid,
            r: 255,
            g: 0,
            b: 0,
            a: 48,
            noDepthTest: true,
            duration: 0.1);
        }
        p_center -= 6;
        --v5;
      }
      while ( v5 >= 0 );
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&regulations);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061E70
// Name: public: bool CAI_MoveSolver::Solve(struct AI_MoveSuggestion_t const __near *,int,struct AI_MoveSolution_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_MoveSolver::Solve(
        CAI_MoveSolver *this,
        const AI_MoveSuggestion_t *pSuggestions,
        int nSuggestions,
        AI_MoveSolution_t *pResult)
{
  int m_Size; // esi
  float v7; // xmm1_4
  float v8; // xmm0_4
  AI_MoveSuggestion_t *v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  float v13; // xmm2_4
  int v14; // ecx
  unsigned int flags; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // edx
  unsigned int v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // edx
  unsigned int v23; // eax
  float v24; // xmm1_4
  float v25; // xmm0_4
  int v26; // edx
  unsigned int v27; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  int v30; // edx
  float weight; // xmm2_4
  int v32; // ecx
  unsigned int v33; // eax
  float v34; // xmm1_4
  float v35; // xmm0_4
  int v36; // edx
  bool v37; // cc
  int v38; // ecx
  float bias; // xmm0_4
  int v40; // eax
  CAI_MoveSolver::Solve::__l7::Solution_t *v41; // edx
  int v42; // edx
  AI_MoveSuggestion_t *pHighSuggestion; // ecx
  float v44; // xmm1_4
  float v45; // xmm0_4
  bool v46; // sf
  int v47; // [esp-8h] [ebp-5D4h]
  CAI_MoveSolver::Solve::__l7::Solution_t solutions[120]; // [esp+8h] [ebp-5C4h] BYREF
  int j; // [esp+5A8h] [ebp-24h]
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > suggestions; // [esp+5ACh] [ebp-20h] BYREF
  int v51; // [esp+5C0h] [ebp-Ch]
  int i; // [esp+5C4h] [ebp-8h]
  int v53; // [esp+5C8h] [ebp-4h]
  float *pSuggestionsa; // [esp+5D4h] [ebp+8h]
  int center; // [esp+5D8h] [ebp+Ch]

  if ( nSuggestions == 0 )
    return 0;
  if ( nSuggestions != 1 || this->m_Regulations.m_Size != 0 || pSuggestions->type != AIMST_MOVE )
  {
    v47 = nSuggestions + this->m_Regulations.m_Size;
    memset(&suggestions, 0, sizeof(suggestions));
    CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::EnsureCapacity(this: &suggestions, num: v47);
    CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::CopyArray(
      this: &suggestions,
      pArray: pSuggestions,
      size: nSuggestions);
    CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::AddVectorToTail(
      this: &suggestions,
      src: &this->m_Regulations);
    memset(solutions, 0, sizeof(solutions));
    m_Size = suggestions.m_Size;
    CAI_MoveSolver::NormalizeSuggestions(
      this,
      pBegin: suggestions.m_Memory.m_pMemory,
      pEnd: &suggestions.m_Memory.m_pMemory[suggestions.m_Size]);
    if ( m_Size > 0 )
    {
      pSuggestionsa = &suggestions.m_Memory.m_pMemory->arc.span;
      for ( j = m_Size; j != 0; --j )
      {
        v7 = *pSuggestionsa * 0.5;
        v8 = *(pSuggestionsa - 1) - v7;
        v9 = (AI_MoveSuggestion_t *)(pSuggestionsa - 3);
        center = (int)(float)(int)(float)((float)((float)(v7 * 120.0) * 0.0027777778) + 0.5);
        if ( v8 < 0.0 )
          v8 = v8 + 360.0;
        v10 = (int)(float)((float)(*pSuggestionsa * 120.0) * 0.0027777778) + 1;
        v11 = 0;
        v12 = (int)(float)((float)(v8 * 120.0) * 0.0027777778);
        i = 0;
        v51 = v10;
        if ( v10 >= 4 )
        {
          v13 = *(pSuggestionsa - 2);
          v14 = 1;
          v53 = (int)(float)(int)(float)((float)((float)(v7 * 120.0) * 0.0027777778) + 0.5) - 2;
          do
          {
            if ( v13 <= 0.0 )
            {
              v17 = v13;
            }
            else
            {
              flags = v9->flags;
              v16 = (float)(int)abs32(v53 + 2) * 0.00083333335;
              if ( (flags & 1) != 0 && v11 > center || (flags & 2) != 0 && v11 < center )
                v16 = v16 * 0.9;
              v17 = *(pSuggestionsa - 2) - (float)(*(pSuggestionsa - 2) * v16);
            }
            v18 = (v12 + v14 - 1) % 120;
            solutions[v18].bias = solutions[v18].bias + v17;
            if ( v17 > solutions[v18].highBias )
            {
              solutions[v18].highBias = v17;
              solutions[v18].pHighSuggestion = v9;
            }
            if ( v13 <= 0.0 )
            {
              v21 = v13;
            }
            else
            {
              v19 = v9->flags;
              v20 = (float)(int)abs32(v53 + 1) * 0.00083333335;
              if ( (v19 & 1) != 0 && v14 > center || (v19 & 2) != 0 && v14 < center )
                v20 = v20 * 0.9;
              v21 = *(pSuggestionsa - 2) - (float)(*(pSuggestionsa - 2) * v20);
            }
            v22 = (v14 + v12) % 120;
            solutions[v22].bias = solutions[v22].bias + v21;
            if ( v21 > solutions[v22].highBias )
            {
              solutions[v22].highBias = v21;
              solutions[v22].pHighSuggestion = v9;
            }
            if ( v13 <= 0.0 )
            {
              v25 = v13;
            }
            else
            {
              v23 = v9->flags;
              v24 = (float)(int)abs32(v53) * 0.00083333335;
              if ( (v23 & 1) != 0 && v14 + 1 > center || (v23 & 2) != 0 && v14 + 1 < center )
                v24 = v24 * 0.9;
              v25 = *(pSuggestionsa - 2) - (float)(*(pSuggestionsa - 2) * v24);
            }
            v26 = (v12 + v14 + 1) % 120;
            solutions[v26].bias = solutions[v26].bias + v25;
            if ( v25 > solutions[v26].highBias )
            {
              solutions[v26].highBias = v25;
              solutions[v26].pHighSuggestion = v9;
            }
            if ( v13 <= 0.0 )
            {
              v29 = v13;
            }
            else
            {
              v27 = v9->flags;
              v28 = (float)(int)abs32(v53 - 1) * 0.00083333335;
              if ( (v27 & 1) != 0 && v14 + 2 > center || (v27 & 2) != 0 && v14 + 2 < center )
                v28 = v28 * 0.9;
              v29 = *(pSuggestionsa - 2) - (float)(*(pSuggestionsa - 2) * v28);
            }
            v30 = (v12 + v14 + 2) % 120;
            solutions[v30].bias = solutions[v30].bias + v29;
            if ( v29 > solutions[v30].highBias )
            {
              solutions[v30].highBias = v29;
              solutions[v30].pHighSuggestion = v9;
            }
            v10 = v51;
            v53 -= 4;
            v11 = i + 4;
            v14 += 4;
            i = v11;
          }
          while ( v11 < v51 - 3 );
        }
        if ( v11 < v10 )
        {
          weight = v9->weight;
          v32 = center - v11;
          do
          {
            if ( weight <= 0.0 )
            {
              v35 = weight;
            }
            else
            {
              v33 = v9->flags;
              v34 = (float)(int)abs32(v32) * 0.00083333335;
              if ( (v33 & 1) != 0 && v11 > center || (v33 & 2) != 0 && v11 < center )
                v34 = v34 * 0.9;
              v35 = v9->weight - (float)(v9->weight * v34);
            }
            v36 = (v11 + v12) % 120;
            v37 = v35 <= solutions[v36].highBias;
            solutions[v36].bias = solutions[v36].bias + v35;
            if ( !v37 )
            {
              solutions[v36].highBias = v35;
              solutions[v36].pHighSuggestion = v9;
            }
            v11 = i + 1;
            --v32;
            i = v11;
          }
          while ( v11 < v51 );
        }
        pSuggestionsa += 6;
      }
    }
    v38 = -1;
    bias = 0.0;
    v40 = 2;
    v41 = &solutions[1];
    do
    {
      if ( v41[-1].bias > bias )
      {
        v38 = v40 - 2;
        bias = v41[-1].bias;
      }
      if ( v41->bias > bias )
      {
        v38 = v40 - 1;
        bias = v41->bias;
      }
      if ( v41[1].bias > bias )
      {
        v38 = v40;
        bias = v41[1].bias;
      }
      if ( v41[2].bias > bias )
      {
        v38 = v40 + 1;
        bias = v41[2].bias;
      }
      if ( v41[3].bias > bias )
      {
        v38 = v40 + 2;
        bias = v41[3].bias;
      }
      if ( v41[4].bias > bias )
      {
        v38 = v40 + 3;
        bias = v41[4].bias;
      }
      v40 += 6;
      v41 += 6;
    }
    while ( v40 - 2 < 120 );
    if ( v38 == -1 )
    {
      if ( suggestions.m_Memory.m_nGrowSize >= 0 && suggestions.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: suggestions.m_Memory.m_pMemory);
      return 0;
    }
    else
    {
      v42 = 3 * v38;
      pHighSuggestion = solutions[v38].pHighSuggestion;
      v44 = pHighSuggestion->arc.center;
      v45 = (float)v42;
      if ( v44 > (float)v42 && (float)(v45 + 3.0) >= v44 )
        v45 = pHighSuggestion->arc.center;
      v46 = suggestions.m_Memory.m_nGrowSize < 0;
      pResult->dir = v45;
      if ( !v46 && suggestions.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: suggestions.m_Memory.m_pMemory);
      return 1;
    }
  }
  else
  {
    pResult->dir = pSuggestions->arc.center;
    return 1;
  }
}
