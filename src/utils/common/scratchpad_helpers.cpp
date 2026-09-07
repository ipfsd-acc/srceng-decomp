// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/scratchpad_helpers.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10011F20
// Name: void ScratchPad_DrawWinding(class IScratchPad3D __near *,int,class Vector __near *,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScratchPad_DrawWinding(IScratchPad3D *pPad, int nPoints, Vector *pPoints, Vector vColor, Vector vOffset)
{
  int v5; // eax
  float *p_z; // esi
  int v7; // edi
  int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  void (__thiscall *DrawLine)(IScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14[7]; // [esp+4h] [ebp-38h] BYREF
  float v15[3]; // [esp+20h] [ebp-1Ch] BYREF
  Vector v16; // [esp+2Ch] [ebp-10h]
  int v17; // [esp+38h] [ebp-4h]

  v5 = 0;
  if ( nPoints > 0 )
  {
    p_z = &pPoints->z;
    do
    {
      v7 = v5 + 1;
      v16 = vColor;
      v14[3] = vColor.x;
      v14[4] = vColor.y;
      v8 = (v5 + 1) % nPoints;
      v9 = pPoints[v8].y + vOffset.y;
      v10 = pPoints[v8].z + vOffset.z;
      DrawLine = pPad->DrawLine;
      v15[0] = pPoints[v8].x + vOffset.x;
      v17 = 1065353216;
      v14[0] = *(p_z - 2) + vOffset.x;
      v15[1] = v9;
      v12 = *(p_z - 1) + vOffset.y;
      v15[2] = v10;
      v13 = *p_z + vOffset.z;
      v14[5] = vColor.z;
      v14[1] = v12;
      v14[2] = v13;
      v14[6] = 1.0;
      DrawLine(this: pPad, a2: (const CSPVert *)v14, a3: (const CSPVert *)v15);
      v5 = v7;
      p_z += 3;
    }
    while ( v7 < nPoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012020
// Name: void ScratchPad_DrawFace(class IScratchPad3D __near *,struct dface_t __near *,int,class CSPColor const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScratchPad_DrawFace(
        IScratchPad3D *pPad,
        dface_t *f,
        int iFaceNumber,
        const CSPColor *faceColor,
        const Vector *vOffset)
{
  Vector *m_pMemory; // ecx
  dface_t *v6; // esi
  int m_nAllocationCount; // edx
  int m_Size; // ebx
  int v9; // eax
  int v10; // eax
  Vector *v11; // edi
  int v12; // esi
  Vector *v13; // eax
  int numedges; // edx
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm3_4
  float v18; // xmm1_4
  float *p_z; // esi
  float m_flAlpha; // xmm6_4
  int v21; // eax
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  void (__thiscall *DrawLine)(IScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  void (__thiscall *DrawTextA)(IScratchPad3D *, const char *, const CTextParams *); // edx
  const Vector *v38; // [esp-Ch] [ebp-D0h]
  char str[64]; // [esp+Ch] [ebp-B8h] BYREF
  float v40[7]; // [esp+4Ch] [ebp-78h] BYREF
  CTextParams params; // [esp+68h] [ebp-5Ch] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > points; // [esp+A0h] [ebp-24h] BYREF
  Vector vCenter; // [esp+B4h] [ebp-10h] BYREF
  int iEdge; // [esp+C0h] [ebp-4h]

  m_pMemory = nullptr;
  v6 = f;
  m_nAllocationCount = 0;
  m_Size = 0;
  memset(&points, 0, sizeof(points));
  iEdge = 0;
  if ( f->numedges > 0 )
  {
    while ( 1 )
    {
      v9 = dsurfedges[iEdge + v6->firstedge];
      if ( v9 >= 0 )
        v10 = dedges[v9].v[0];
      else
        v10 = (unsigned __int16)word_102AF25A[-2 * v9];
      v11 = &dvertexes + v10;
      v12 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&points,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = points.m_Size;
        m_pMemory = points.m_Memory.m_pMemory;
      }
      points.m_Size = ++m_Size;
      points.m_pElements = m_pMemory;
      if ( m_Size - v12 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 12 * (m_Size - v12 - 1));
        m_pMemory = points.m_Memory.m_pMemory;
      }
      v13 = &m_pMemory[v12];
      if ( v13 != nullptr )
      {
        *(_QWORD *)&v13->x = *(_QWORD *)&v11->x;
        v13->z = v11->z;
      }
      v6 = f;
      numedges = f->numedges;
      if ( ++iEdge >= numedges )
        break;
      m_nAllocationCount = points.m_Memory.m_nAllocationCount;
    }
  }
  v15 = 0.0;
  v16 = 0;
  v17 = 0.0;
  v18 = 0.0;
  memset(&vCenter, 0, sizeof(vCenter));
  if ( m_Size > 0 )
  {
    p_z = &m_pMemory->z;
    do
    {
      iEdge = v16 + 1;
      m_flAlpha = faceColor->m_flAlpha;
      v21 = (v16 + 1) % m_Size;
      y = m_pMemory[v21].y;
      z = m_pMemory[v21].z;
      x = vOffset->x;
      v25 = vOffset->y;
      v26 = vOffset->z;
      DrawLine = pPad->DrawLine;
      v40[0] = m_pMemory[v21].x + vOffset->x;
      v28 = faceColor->m_vColor.x;
      v40[1] = y + v25;
      v29 = faceColor->m_vColor.y;
      v40[2] = z + v26;
      v30 = faceColor->m_vColor.z;
      v40[3] = v28;
      v40[4] = v29;
      v40[5] = v30;
      v40[6] = m_flAlpha;
      v31 = v25 + *(p_z - 1);
      v32 = v26 + *p_z;
      params.m_vPos.z = x + *(p_z - 2);
      *(float *)&params.m_bCentered = v31;
      params.m_vAngles.x = v32;
      params.m_vAngles.y = v28;
      params.m_vAngles.z = v29;
      *(float *)&params.m_bTwoSided = v30;
      params.m_flLetterWidth = m_flAlpha;
      DrawLine(this: pPad, a2: (const CSPVert *)&params.m_vPos.z, a3: (const CSPVert *)v40);
      v17 = vCenter.x + *(p_z - 2);
      v16 = iEdge;
      v15 = *(p_z - 1) + vCenter.y;
      v18 = *p_z + vCenter.z;
      m_pMemory = points.m_Memory.m_pMemory;
      p_z += 3;
      vCenter.x = v17;
      vCenter.y = v15;
      vCenter.z = v18;
    }
    while ( iEdge < m_Size );
  }
  v33 = 1.0 / (float)m_Size;
  v34 = v18 * v33;
  vCenter.x = vOffset->x + (float)(v33 * v17);
  v35 = vOffset->y + (float)(v15 * v33);
  v36 = vOffset->z + v34;
  vCenter.y = v35;
  vCenter.z = v36;
  if ( iFaceNumber != -1 )
  {
    V_snprintf(pDest: str, maxLen: 64, pFormat: "%d", iFaceNumber);
    v38 = (Vector *)((char *)&dplanes + 20 * f->planenum);
    params.m_flAlpha = 1.0;
    memset(&params.m_vPos, 0, sizeof(params.m_vPos));
    memset(&params.m_vAngles, 0, sizeof(params.m_vAngles));
    params.m_bTwoSided = true;
    params.m_bCentered = true;
    *(_WORD *)&params.m_bSolidBackground = 257;
    params.m_flLetterWidth = 2.0;
    params.m_vColor.x = 1.0;
    params.m_vColor.y = 0.0;
    params.m_vColor.z = 0.0;
    VectorAngles(forward: v38, angles: &params.m_vAngles);
    DrawTextA = pPad->DrawTextA;
    params.m_vPos = vCenter;
    params.m_bTwoSided = true;
    DrawTextA(this: pPad, a2: str, a3: &params);
    m_pMemory = points.m_Memory.m_pMemory;
  }
  if ( points.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10012360
// Name: void ScratchPad_DrawWorld(class IScratchPad3D __near *,bool,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScratchPad_DrawWorld(IScratchPad3D *pPad, bool bDrawFaceNumbers)
{
  __int16 *v3; // edi
  int v4; // esi
  int v5; // eax
  CSPColor v6; // [esp+4h] [ebp-20h] BYREF
  Vector vOffset; // [esp+14h] [ebp-10h] BYREF
  BOOL bAutoFlush; // [esp+20h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+8h]

  LOBYTE(bAutoFlush) = pPad->GetAutoFlush(this: pPad);
  pPad->SetAutoFlush(this: pPad, a2: false);
  i = 0;
  if ( numleafs > 0 )
  {
    v3 = &word_1008B26E;
    do
    {
      if ( (*(_DWORD *)(v3 - 11) & 0x8000000) == 0 )
      {
        v4 = 0;
        if ( *v3 != 0 )
        {
          memset(&vOffset, 0, sizeof(vOffset));
          v6.m_vColor.x = 1.0;
          v6.m_vColor.y = 1.0;
          v6.m_vColor.z = 1.0;
          v6.m_flAlpha = 1.0;
          do
          {
            if ( bDrawFaceNumbers )
              v5 = i;
            else
              v5 = -1;
            ScratchPad_DrawFace(
              pPad,
              f: &dfaces[dleaffaces[v4 + (unsigned __int16)*(v3 - 1)]],
              iFaceNumber: v5,
              faceColor: &v6,
              &vOffset);
            ++v4;
          }
          while ( v4 < (unsigned __int16)*v3 );
        }
      }
      v3 += 16;
      ++i;
    }
    while ( i < numleafs );
  }
  pPad->SetAutoFlush(this: pPad, a2: bAutoFlush);
}
