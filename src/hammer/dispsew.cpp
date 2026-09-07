// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispsew.cpp
// Functions: 36
// ============================================================

#include "hammer\dispsew.h"

//------------------------------------------------------------------------------
// Address: 0x10022CA0
// Name: public: void CCoreDispInfo::SetMultiBlend(int,class Vector4D __near &,class Vector4D __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::SetMultiBlend(
        CCoreDispInfo *this,
        int index,
        Vector4D *vBlend,
        Vector4D *vAlphaBlend,
        Vector *vColor1,
        Vector *vColor2,
        Vector *vColor3,
        Vector *vColor4)
{
  CoreDispVert_t *v8; // eax

  v8 = &this->m_pVerts[index];
  v8->m_MultiBlend = *vBlend;
  v8->m_AlphaBlend = *vAlphaBlend;
  v8->m_vBlendColors[0] = *vColor1;
  v8->m_vBlendColors[1] = *vColor2;
  v8->m_vBlendColors[2] = *vColor3;
  v8->m_vBlendColors[3] = *vColor4;
}

//------------------------------------------------------------------------------
// Address: 0x10022D80
// Name: public: void CCoreDispInfo::GetMultiBlend(int,class Vector4D __near &,class Vector4D __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::GetMultiBlend(
        CCoreDispInfo *this,
        int index,
        Vector4D *vBlend,
        Vector4D *vAlphaBlend,
        Vector *vColor1,
        Vector *vColor2,
        Vector *vColor3,
        Vector *vColor4)
{
  CoreDispVert_t *v8; // eax

  v8 = &this->m_pVerts[index];
  *vBlend = v8->m_MultiBlend;
  *vAlphaBlend = v8->m_AlphaBlend;
  *vColor1 = v8->m_vBlendColors[0];
  *vColor2 = v8->m_vBlendColors[1];
  *vColor3 = v8->m_vBlendColors[2];
  *vColor4 = v8->m_vBlendColors[3];
}

//------------------------------------------------------------------------------
// Address: 0x10022E60
// Name: bool EdgeCompare(class Vector __near *,class Vector __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EdgeCompare(Vector *pEdgePts1, Vector *pEdgePts2, int *edgeType1, int *edgeType2)
{
  float x; // xmm4_4
  float y; // xmm5_4
  float v6; // xmm2_4
  float z; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm4_4
  Vector *v15; // ebx
  int v16; // edi
  Vector *v17; // esi
  int v18; // eax
  float *p_x; // edx
  float *v20; // ecx
  int v21; // ecx
  int v23; // eax
  int v24; // eax
  int *v25; // ecx
  int v26; // eax
  Vector edge2[3]; // [esp+Ch] [ebp-58h] BYREF
  Vector edge1[3]; // [esp+30h] [ebp-34h] BYREF
  int ndxEdge2[2]; // [esp+54h] [ebp-10h]
  int ndxEdge1[2]; // [esp+5Ch] [ebp-8h]
  int ndx1; // [esp+6Ch] [ebp+8h]
  int overlapCount; // [esp+70h] [ebp+Ch]

  x = pEdgePts1[1].x;
  y = pEdgePts1[1].y;
  v6 = pEdgePts1->y;
  z = pEdgePts1[1].z;
  v8 = pEdgePts1->z;
  v9 = pEdgePts2[1].z;
  edge1[0].x = pEdgePts1->x;
  edge1[0].y = v6;
  edge1[0].z = v8;
  edge1[1].y = (float)(y + v6) * 0.5;
  v10 = pEdgePts2->x;
  edge1[1].x = (float)(x + edge1[0].x) * 0.5;
  edge1[1].z = (float)(z + v8) * 0.5;
  v11 = pEdgePts2->y;
  edge1[2].y = y;
  v12 = pEdgePts2[1].x;
  edge2[0].x = v10;
  edge1[2].z = z;
  v13 = pEdgePts2[1].y;
  edge1[2].x = x;
  v14 = pEdgePts2->z;
  edge2[0].y = v11;
  *edgeType1 = 0;
  edge2[1].x = (float)(v12 + v10) * 0.5;
  edge2[1].y = (float)(v13 + v11) * 0.5;
  *edgeType2 = 0;
  edge2[0].z = v14;
  edge2[1].z = (float)(v9 + v14) * 0.5;
  edge2[2].x = v12;
  edge2[2].y = v13;
  edge2[2].z = v9;
  overlapCount = 0;
  ndx1 = 0;
  v15 = edge1;
  do
  {
    v16 = 0;
    v17 = edge2;
    while ( 2 )
    {
      v18 = 0;
      p_x = &v17->x;
      v20 = &v15->x;
      while ( fabs(*v20 - *p_x) <= 1.0 )
      {
        ++v18;
        ++v20;
        ++p_x;
        if ( v18 >= 3 )
        {
          v21 = ndx1;
          if ( (ndx1 & 1) == 0 || v16 % 2 == 0 )
          {
            ndxEdge1[overlapCount] = ndx1;
            ndxEdge2[overlapCount++] = v16;
            goto LABEL_11;
          }
          break;
        }
      }
      ++v16;
      ++v17;
      if ( v16 < 3 )
        continue;
      break;
    }
    v21 = ndx1;
LABEL_11:
    ++v15;
    ndx1 = v21 + 1;
  }
  while ( v21 + 1 < 3 );
  if ( overlapCount != 2 )
    return 0;
  v23 = ndxEdge1[0];
  if ( ndxEdge1[0] % 2 != 0 )
  {
    v24 = ndxEdge1[1];
    v25 = edgeType1;
    *edgeType1 = 3;
    if ( v24 != 0 )
    {
      if ( v24 == 2 )
        *edgeType2 = 2;
    }
    else
    {
      *edgeType2 = 1;
    }
  }
  else
  {
    if ( ndxEdge1[1] % 2 == 0 )
      goto LABEL_24;
    *edgeType1 = 3;
    if ( v23 == 0 )
    {
      *edgeType2 = 1;
      v25 = edgeType1;
      goto LABEL_25;
    }
    if ( v23 == 2 )
    {
      *edgeType2 = 2;
      v25 = edgeType1;
    }
    else
    {
LABEL_24:
      v25 = edgeType1;
    }
  }
LABEL_25:
  v26 = ndxEdge2[0];
  if ( ndxEdge2[0] % 2 != 0 )
  {
    *edgeType2 = 3;
    v26 = ndxEdge2[1];
  }
  else
  {
    if ( ndxEdge2[1] % 2 == 0 )
      return 1;
    *edgeType2 = 3;
  }
  if ( v26 == 0 )
  {
    *v25 = 1;
    return 1;
  }
  if ( v26 == 2 )
    *v25 = 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100230D0
// Name: void GetPointFromSurface(class CMapFace __near *,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPointFromSurface(CMapFace *pFace, int ndxPt, Vector *pt)
{
  int m_DispHandle; // esi
  CEditDispMgr *v4; // eax
  Vector *v5; // eax

  m_DispHandle = pFace->m_DispHandle;
  if ( (_WORD)m_DispHandle == 0xFFFF )
  {
    v5 = &pFace->Points[ndxPt];
  }
  else
  {
    v4 = EditDispMgr();
    v5 = &v4->GetDisp(this: v4, a2: m_DispHandle)->m_CoreDispInfo.m_Surf.m_Points[ndxPt];
  }
  *pt = *v5;
}

//------------------------------------------------------------------------------
// Address: 0x10023130
// Name: void SewCorner_ResolveDisp(struct SewCornerData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewCorner_ResolveDisp(SewCornerData_t *pCornerData)
{
  int v1; // esi
  char v2; // bl
  CMapFace **pFaces; // edi
  CMapFace *v4; // eax
  IEditorTexture *m_pTexture; // eax
  int (__thiscall *GetShortName)(IEditorTexture *, char *); // edx
  SewCornerData_t *v7; // ecx
  int v8; // ebx
  int *ndxCorners; // edi
  int v10; // eax
  int v11; // esi
  CEditDispMgr *v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  int faceCount; // eax
  float v28; // xmm1_4
  int v29; // ebx
  int *v30; // edi
  int v31; // eax
  int v32; // esi
  CEditDispMgr *v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // esi
  int v37; // ecx
  bool v38; // zf
  int v39; // edx
  int v40; // edx
  char szMatName1[128]; // [esp+0h] [ebp-1D0h] BYREF
  char szMatName2[128]; // [esp+80h] [ebp-150h] BYREF
  Vector4D vAlphaBlend; // [esp+100h] [ebp-D0h] BYREF
  Vector4D vMultiBlend; // [esp+110h] [ebp-C0h] BYREF
  Vector vColor3; // [esp+120h] [ebp-B0h] BYREF
  Vector vColor1; // [esp+12Ch] [ebp-A4h] BYREF
  Vector vColor2; // [esp+138h] [ebp-98h] BYREF
  Vector vColor4; // [esp+144h] [ebp-8Ch] BYREF
  Vector4D vAvgAlphaBlend; // [esp+150h] [ebp-80h] BYREF
  Vector4D vAvgMultiBlend; // [esp+160h] [ebp-70h] BYREF
  Vector vAvgColor2; // [esp+170h] [ebp-60h] BYREF
  Vector vAvgColor3; // [esp+17Ch] [ebp-54h] BYREF
  Vector vAvgColor4; // [esp+188h] [ebp-48h] BYREF
  Vector vAvgColor1; // [esp+194h] [ebp-3Ch] BYREF
  Vector vAvgSubdivNormal; // [esp+1A0h] [ebp-30h] BYREF
  float avgDist; // [esp+1ACh] [ebp-24h]
  Vector vAvgSubdivPos; // [esp+1B0h] [ebp-20h] BYREF
  Vector vAvgField; // [esp+1BCh] [ebp-14h] BYREF
  float flAvgAlpha; // [esp+1C8h] [ebp-8h]
  bool bBlendAlpha; // [esp+1CFh] [ebp-1h]

  v1 = 0;
  v2 = 0;
  avgDist = 0.0;
  memset(&vAvgField, 0, sizeof(vAvgField));
  memset(&vAvgSubdivPos, 0, sizeof(vAvgSubdivPos));
  memset(&vAvgSubdivNormal, 0, sizeof(vAvgSubdivNormal));
  flAvgAlpha = 0.0;
  memset(&vAvgMultiBlend, 0, sizeof(vAvgMultiBlend));
  memset(&vAvgAlphaBlend, 0, sizeof(vAvgAlphaBlend));
  memset(&vAvgColor1, 0, sizeof(vAvgColor1));
  memset(&vAvgColor2, 0, sizeof(vAvgColor2));
  memset(&vAvgColor3, 0, sizeof(vAvgColor3));
  memset(&vAvgColor4, 0, sizeof(vAvgColor4));
  bBlendAlpha = true;
  if ( pCornerData->faceCount > 0 )
  {
    pFaces = pCornerData->pFaces;
    do
    {
      v4 = *pFaces;
      if ( *pFaces != nullptr && v4->m_DispHandle != 0xFFFF )
      {
        m_pTexture = v4->m_pTexture;
        GetShortName = m_pTexture->GetShortName;
        if ( v2 != 0 )
        {
          GetShortName(this: m_pTexture, a2: szMatName2);
          if ( _V_stricmp(s1: szMatName1, s2: szMatName2) != 0 )
          {
            bBlendAlpha = false;
            break;
          }
        }
        else
        {
          GetShortName(this: m_pTexture, a2: szMatName1);
          v2 = 1;
        }
      }
      ++v1;
      ++pFaces;
    }
    while ( v1 < pCornerData->faceCount );
  }
  v7 = pCornerData;
  v8 = 0;
  if ( pCornerData->faceCount > 0 )
  {
    ndxCorners = pCornerData->ndxCorners;
    do
    {
      v10 = *(ndxCorners - 16);
      if ( v10 != 0 )
      {
        v11 = *(unsigned __int16 *)(v10 + 420);
        if ( (_WORD)v11 != 0xFFFF )
        {
          v12 = EditDispMgr();
          v13 = (int)v12->GetDisp(this: v12, a2: v11);
          v14 = (1 << *(_DWORD *)(v13 + 36)) + 1;
          switch ( *ndxCorners )
          {
            case 0:
              v15 = 0;
              goto LABEL_21;
            case 1:
              v15 = v14 * (v14 - 1);
              goto LABEL_20;
            case 2:
              v15 = v14 * v14 - 1;
              goto LABEL_20;
            case 3:
              v15 = 1 << *(_DWORD *)(v13 + 36);
LABEL_20:
              if ( v15 != -1 )
              {
LABEL_21:
                v16 = *(_DWORD *)(v13 + 784);
                v17 = *(float *)(v16 + 224 * v15 + 12) + avgDist;
                v18 = *(float *)(v16 + 224 * v15 + 4) + vAvgField.y;
                v19 = *(float *)(v16 + 224 * v15 + 8) + vAvgField.z;
                v20 = (float *)(224 * v15 + v16);
                avgDist = v17;
                vAvgField.x = *v20 + vAvgField.x;
                v21 = v20[7] + vAvgSubdivPos.x;
                vAvgField.y = v18;
                v22 = v20[8] + vAvgSubdivPos.y;
                vAvgField.z = v19;
                v23 = v20[9] + vAvgSubdivPos.z;
                vAvgSubdivPos.x = v21;
                v24 = v20[4] + vAvgSubdivNormal.x;
                vAvgSubdivPos.y = v22;
                v25 = v20[5] + vAvgSubdivNormal.y;
                vAvgSubdivPos.z = v23;
                v26 = v20[6] + vAvgSubdivNormal.z;
                vAvgSubdivNormal.x = v24;
                vAvgSubdivNormal.y = v25;
                vAvgSubdivNormal.z = v26;
                if ( bBlendAlpha )
                  flAvgAlpha = *(float *)(*(_DWORD *)(v13 + 784) + 224 * v15 + 140) + flAvgAlpha;
                CCoreDispInfo::GetMultiBlend(
                  this: (CCoreDispInfo *)(v13 + 24),
                  index: v15,
                  vBlend: &vMultiBlend,
                  &vAlphaBlend,
                  &vColor1,
                  &vColor2,
                  &vColor3,
                  &vColor4);
                vAvgMultiBlend.x = vMultiBlend.x + vAvgMultiBlend.x;
                vAvgMultiBlend.y = vMultiBlend.y + vAvgMultiBlend.y;
                vAvgMultiBlend.z = vMultiBlend.z + vAvgMultiBlend.z;
                vAvgMultiBlend.w = vMultiBlend.w + vAvgMultiBlend.w;
                vAvgAlphaBlend.x = vAlphaBlend.x + vAvgAlphaBlend.x;
                vAvgAlphaBlend.y = vAlphaBlend.y + vAvgAlphaBlend.y;
                vAvgAlphaBlend.z = vAlphaBlend.z + vAvgAlphaBlend.z;
                vAvgAlphaBlend.w = vAlphaBlend.w + vAvgAlphaBlend.w;
                vAvgColor1.x = vColor1.x + vAvgColor1.x;
                vAvgColor1.y = vColor1.y + vAvgColor1.y;
                vAvgColor1.z = vColor1.z + vAvgColor1.z;
                vAvgColor2.x = vColor2.x + vAvgColor2.x;
                vAvgColor2.y = vColor2.y + vAvgColor2.y;
                vAvgColor2.z = vColor2.z + vAvgColor2.z;
                vAvgColor3.x = vColor3.x + vAvgColor3.x;
                vAvgColor3.y = vColor3.y + vAvgColor3.y;
                vAvgColor3.z = vColor3.z + vAvgColor3.z;
                vAvgColor4.x = vAvgColor4.x + vColor4.x;
                vAvgColor4.y = vColor4.y + vAvgColor4.y;
                vAvgColor4.z = vColor4.z + vAvgColor4.z;
              }
              break;
            default:
              break;
          }
        }
      }
      v7 = pCornerData;
      ++v8;
      ++ndxCorners;
    }
    while ( v8 < pCornerData->faceCount );
  }
  faceCount = v7->faceCount;
  v28 = 1.0 / (float)v7->faceCount;
  vAvgField.x = v28 * vAvgField.x;
  vAvgField.y = v28 * vAvgField.y;
  vAvgField.z = vAvgField.z * v28;
  vAvgSubdivPos.x = v28 * vAvgSubdivPos.x;
  vAvgSubdivPos.y = vAvgSubdivPos.y * v28;
  vAvgSubdivPos.z = vAvgSubdivPos.z * v28;
  vAvgSubdivNormal.x = v28 * vAvgSubdivNormal.x;
  vAvgSubdivNormal.y = vAvgSubdivNormal.y * v28;
  avgDist = v28 * avgDist;
  vAvgSubdivNormal.z = vAvgSubdivNormal.z * v28;
  if ( bBlendAlpha )
    flAvgAlpha = v28 * flAvgAlpha;
  vAvgMultiBlend.x = v28 * vAvgMultiBlend.x;
  vAvgMultiBlend.y = vAvgMultiBlend.y * v28;
  vAvgMultiBlend.z = vAvgMultiBlend.z * v28;
  vAvgMultiBlend.w = vAvgMultiBlend.w * v28;
  vAvgAlphaBlend.x = v28 * vAvgAlphaBlend.x;
  vAvgAlphaBlend.y = vAvgAlphaBlend.y * v28;
  vAvgAlphaBlend.z = vAvgAlphaBlend.z * v28;
  vAvgAlphaBlend.w = vAvgAlphaBlend.w * v28;
  vAvgColor1.x = v28 * vAvgColor1.x;
  vAvgColor1.y = vAvgColor1.y * v28;
  vAvgColor1.z = vAvgColor1.z * v28;
  vAvgColor2.x = v28 * vAvgColor2.x;
  vAvgColor2.y = vAvgColor2.y * v28;
  vAvgColor2.z = vAvgColor2.z * v28;
  vAvgColor3.x = v28 * vAvgColor3.x;
  vAvgColor3.y = vAvgColor3.y * v28;
  vAvgColor3.z = vAvgColor3.z * v28;
  vAvgColor4.x = v28 * vAvgColor4.x;
  vAvgColor4.y = vAvgColor4.y * v28;
  v29 = 0;
  vAvgColor4.z = vAvgColor4.z * v28;
  if ( faceCount > 0 )
  {
    v30 = v7->ndxCorners;
    do
    {
      v31 = *(v30 - 16);
      if ( v31 != 0 )
      {
        v32 = *(unsigned __int16 *)(v31 + 420);
        if ( (_WORD)v32 != 0xFFFF )
        {
          v33 = EditDispMgr();
          v34 = (int)v33->GetDisp(this: v33, a2: v32);
          v35 = (1 << *(_DWORD *)(v34 + 36)) + 1;
          switch ( *v30 )
          {
            case 0:
              v36 = 0;
              goto LABEL_37;
            case 1:
              v36 = v35 * (v35 - 1);
              goto LABEL_36;
            case 2:
              v36 = v35 * v35 - 1;
              goto LABEL_36;
            case 3:
              v36 = 1 << *(_DWORD *)(v34 + 36);
LABEL_36:
              if ( v36 != -1 )
              {
LABEL_37:
                v37 = 224 * v36;
                v38 = !bBlendAlpha;
                *(float *)(v37 + *(_DWORD *)(v34 + 784) + 12) = avgDist;
                *(Vector *)(*(_DWORD *)(v34 + 784) + v37) = vAvgField;
                v39 = *(_DWORD *)(v34 + 784);
                *(float *)(v37 + v39 + 28) = vAvgSubdivPos.x;
                v40 = 224 * v36 + v39 + 28;
                *(float *)(v40 + 4) = vAvgSubdivPos.y;
                *(float *)(v40 + 8) = vAvgSubdivPos.z;
                *(Vector *)(224 * v36 + *(_DWORD *)(v34 + 784) + 16) = vAvgSubdivNormal;
                if ( !v38 )
                  *(float *)(v37 + *(_DWORD *)(v34 + 784) + 140) = flAvgAlpha;
                CCoreDispInfo::SetMultiBlend(
                  this: (CCoreDispInfo *)(v34 + 24),
                  index: v36,
                  vBlend: &vAvgMultiBlend,
                  vAlphaBlend: &vAvgAlphaBlend,
                  vColor1: &vAvgColor1,
                  vColor2: &vAvgColor2,
                  vColor3: &vAvgColor3,
                  vColor4: &vAvgColor4);
              }
              break;
            default:
              break;
          }
        }
      }
      ++v29;
      ++v30;
    }
    while ( v29 < pCornerData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023890
// Name: void SewCorner_ResolveSolid(struct SewCornerData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewCorner_ResolveSolid(SewCornerData_t *pCornerData)
{
  int v1; // ebx
  int *ndxCorners; // edi
  int v3; // eax
  int v4; // esi
  CEditDispMgr *v5; // eax
  int v6; // esi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  _DWORD *v16; // edx
  Vector4D vClearMultiBlend; // [esp+0h] [ebp-38h] BYREF
  Vector4D vClearAlphaBlend; // [esp+10h] [ebp-28h] BYREF
  Vector vSet; // [esp+20h] [ebp-18h] BYREF
  Vector vNormal; // [esp+2Ch] [ebp-Ch] BYREF

  v1 = 0;
  vSet.x = 1.0;
  vSet.y = 1.0;
  vSet.z = 1.0;
  memset(&vClearMultiBlend, 0, sizeof(vClearMultiBlend));
  memset(&vClearAlphaBlend, 0, sizeof(vClearAlphaBlend));
  if ( pCornerData->faceCount > 0 )
  {
    ndxCorners = pCornerData->ndxCorners;
    do
    {
      v3 = *(ndxCorners - 16);
      if ( v3 != 0 )
      {
        v4 = *(unsigned __int16 *)(v3 + 420);
        if ( (_WORD)v4 != 0xFFFF )
        {
          v5 = EditDispMgr();
          v6 = (int)v5->GetDisp(this: v5, a2: v4);
          v7 = *(float *)(v6 + 88) - *(float *)(v6 + 52);
          v8 = *(float *)(v6 + 92) - *(float *)(v6 + 56);
          v9 = *(float *)(v6 + 64) - *(float *)(v6 + 52);
          v10 = *(float *)(v6 + 68) - *(float *)(v6 + 56);
          v11 = *(float *)(v6 + 60) - *(float *)(v6 + 48);
          v12 = *(float *)(v6 + 84) - *(float *)(v6 + 48);
          vNormal.x = (float)(v7 * v10) - (float)(v8 * v9);
          vNormal.y = (float)(v8 * v11) - (float)(v12 * v10);
          vNormal.z = (float)(v12 * v9) - (float)(v7 * v11);
          VectorNormalize(vec: &vNormal);
          v13 = (1 << *(_DWORD *)(v6 + 36)) + 1;
          switch ( *ndxCorners )
          {
            case 0:
              v14 = 0;
              goto LABEL_11;
            case 1:
              v14 = v13 * (v13 - 1);
              goto LABEL_10;
            case 2:
              v14 = v13 * v13 - 1;
              goto LABEL_10;
            case 3:
              v14 = 1 << *(_DWORD *)(v6 + 36);
LABEL_10:
              if ( v14 != -1 )
              {
LABEL_11:
                v15 = 224 * v14;
                *(_DWORD *)(*(_DWORD *)(v6 + 784) + v15 + 12) = 0;
                *(Vector *)(*(_DWORD *)(v6 + 784) + v15) = vNormal;
                v16 = (_DWORD *)(*(_DWORD *)(v6 + 784) + 224 * v14 + 28);
                *v16 = 0;
                v16[1] = 0;
                v16[2] = 0;
                *(Vector *)(*(_DWORD *)(v6 + 784) + 224 * v14 + 16) = vNormal;
                *(_DWORD *)(*(_DWORD *)(v6 + 784) + v15 + 140) = 0;
                CCoreDispInfo::SetMultiBlend(
                  this: (CCoreDispInfo *)(v6 + 24),
                  index: v14,
                  vBlend: &vClearMultiBlend,
                  vAlphaBlend: &vClearAlphaBlend,
                  vColor1: &vSet,
                  vColor2: &vSet,
                  vColor3: &vSet,
                  vColor4: &vSet);
              }
              break;
            default:
              break;
          }
        }
      }
      ++v1;
      ++ndxCorners;
    }
    while ( v1 < pCornerData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023AB0
// Name: void SewTJunc_ResolveDisp(struct SewTJuncData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewTJunc_ResolveDisp(SewTJuncData_t *pTJData)
{
  SewTJuncData_t *v1; // ebx
  bool v2; // cc
  float y; // xmm3_4
  float z; // xmm4_4
  float w; // xmm5_4
  float v6; // xmm6_4
  int *ndxCorners; // edi
  int v8; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // ecx
  int v14; // ecx
  int v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  int faceCount; // eax
  float v31; // xmm2_4
  float v32; // xmm1_4
  int *v33; // ebx
  int v34; // eax
  int v35; // esi
  CEditDispMgr *v36; // eax
  int v37; // eax
  int v38; // edi
  int v39; // ecx
  int v40; // ecx
  int v41; // ebx
  int v42; // esi
  int v43; // eax
  int v44; // eax
  int v45; // edx
  int v46; // edx
  Vector4D vAlphaBlend; // [esp+0h] [ebp-D4h] BYREF
  Vector4D vMultiBlend; // [esp+10h] [ebp-C4h] BYREF
  Vector vColor2; // [esp+20h] [ebp-B4h] BYREF
  Vector vColor4; // [esp+2Ch] [ebp-A8h] BYREF
  Vector vColor1; // [esp+38h] [ebp-9Ch] BYREF
  Vector vColor3; // [esp+44h] [ebp-90h] BYREF
  Vector4D vAvgAlphaBlend; // [esp+50h] [ebp-84h] BYREF
  Vector4D vAvgMultiBlend; // [esp+60h] [ebp-74h] BYREF
  Vector vAvgColor4; // [esp+70h] [ebp-64h] BYREF
  Vector vAvgColor3; // [esp+7Ch] [ebp-58h] BYREF
  Vector vAvgColor1; // [esp+88h] [ebp-4Ch] BYREF
  Vector vAvgColor2; // [esp+94h] [ebp-40h] BYREF
  Vector vAvgSubdivNormal; // [esp+A0h] [ebp-34h] BYREF
  float avgDist; // [esp+ACh] [ebp-28h]
  Vector vAvgSubdivPos; // [esp+B0h] [ebp-24h] BYREF
  float flAvgAlpha; // [esp+BCh] [ebp-18h]
  Vector vAvgField; // [esp+C0h] [ebp-14h] BYREF
  int i; // [esp+CCh] [ebp-8h]
  int *v65; // [esp+D0h] [ebp-4h]

  v1 = pTJData;
  v2 = pTJData->faceCount <= 0;
  y = 0.0;
  z = 0.0;
  w = 0.0;
  v6 = 0.0;
  avgDist = 0.0;
  memset(&vAvgField, 0, sizeof(vAvgField));
  memset(&vAvgSubdivPos, 0, sizeof(vAvgSubdivPos));
  memset(&vAvgSubdivNormal, 0, sizeof(vAvgSubdivNormal));
  flAvgAlpha = 0.0;
  memset(&vAvgMultiBlend, 0, sizeof(vAvgMultiBlend));
  memset(&vAvgAlphaBlend, 0, sizeof(vAvgAlphaBlend));
  memset(&vAvgColor1, 0, sizeof(vAvgColor1));
  memset(&vAvgColor2, 0, sizeof(vAvgColor2));
  memset(&vAvgColor3, 0, sizeof(vAvgColor3));
  memset(&vAvgColor4, 0, sizeof(vAvgColor4));
  i = 0;
  if ( !v2 )
  {
    ndxCorners = pTJData->ndxCorners;
    v65 = pTJData->ndxCorners;
    do
    {
      v8 = *(ndxCorners - 8);
      if ( v8 != 0 )
      {
        v9 = *(unsigned __int16 *)(v8 + 420);
        if ( (_WORD)v9 != 0xFFFF )
        {
          v10 = EditDispMgr();
          v11 = (int)v10->GetDisp(this: v10, a2: v9);
          v12 = v11;
          if ( *ndxCorners != -1 )
          {
            v13 = *(_DWORD *)(v11 + 36);
            switch ( *ndxCorners )
            {
              case 0:
                v14 = 0;
                goto LABEL_19;
              case 1:
                v14 = ((1 << v13) + 1) * (1 << v13);
                goto LABEL_17;
              case 2:
                v14 = ((1 << v13) + 1) * ((1 << v13) + 1) - 1;
                goto LABEL_17;
              case 3:
                v14 = 1 << v13;
                goto LABEL_17;
              default:
                goto LABEL_20;
            }
          }
          v15 = ndxCorners[8];
          if ( v15 == -1 )
            goto LABEL_20;
          v16 = (1 << MEMORY[0x23]) + 1;
          v17 = v16 / 2;
          switch ( v15 )
          {
            case 0:
              v14 = v17 * v16;
              break;
            case 1:
              v14 = v17 + ((1 << MEMORY[0x23]) + 1) * (1 << MEMORY[0x23]);
              break;
            case 2:
              v14 = v16 * (v16 - v17) - 1;
              break;
            case 3:
              v14 = (1 << MEMORY[0x23]) - v17;
              break;
            default:
              goto LABEL_20;
          }
LABEL_17:
          if ( v14 == -1 )
          {
LABEL_20:
            y = vAvgMultiBlend.y;
            z = vAvgMultiBlend.z;
            w = vAvgMultiBlend.w;
            v6 = vAvgAlphaBlend.y;
            ndxCorners = v65;
          }
          else
          {
            ndxCorners = v65;
LABEL_19:
            v18 = *(_DWORD *)(v12 + 784);
            v19 = *(float *)(v18 + 224 * v14 + 12) + avgDist;
            v20 = *(float *)(v18 + 224 * v14 + 4) + vAvgField.y;
            v21 = *(float *)(v18 + 224 * v14 + 8) + vAvgField.z;
            v22 = (float *)(224 * v14 + v18);
            avgDist = v19;
            vAvgField.x = *v22 + vAvgField.x;
            v23 = v22[7] + vAvgSubdivPos.x;
            vAvgField.y = v20;
            v24 = v22[8] + vAvgSubdivPos.y;
            vAvgField.z = v21;
            v25 = v22[9] + vAvgSubdivPos.z;
            vAvgSubdivPos.x = v23;
            v26 = v22[4] + vAvgSubdivNormal.x;
            vAvgSubdivPos.y = v24;
            v27 = v22[5] + vAvgSubdivNormal.y;
            vAvgSubdivPos.z = v25;
            v28 = v22[6] + vAvgSubdivNormal.z;
            vAvgSubdivNormal.x = v26;
            v29 = v22[35] + flAvgAlpha;
            vAvgSubdivNormal.y = v27;
            vAvgSubdivNormal.z = v28;
            flAvgAlpha = v29;
            CCoreDispInfo::GetMultiBlend(
              this: (CCoreDispInfo *)(v12 + 24),
              index: v14,
              vBlend: &vMultiBlend,
              &vAlphaBlend,
              &vColor1,
              &vColor2,
              &vColor3,
              &vColor4);
            y = vMultiBlend.y + vAvgMultiBlend.y;
            z = vMultiBlend.z + vAvgMultiBlend.z;
            w = vMultiBlend.w + vAvgMultiBlend.w;
            v6 = vAlphaBlend.y + vAvgAlphaBlend.y;
            vAvgMultiBlend.x = vMultiBlend.x + vAvgMultiBlend.x;
            vAvgAlphaBlend.x = vAlphaBlend.x + vAvgAlphaBlend.x;
            vAvgAlphaBlend.z = vAlphaBlend.z + vAvgAlphaBlend.z;
            vAvgAlphaBlend.w = vAlphaBlend.w + vAvgAlphaBlend.w;
            vAvgColor1.x = vColor1.x + vAvgColor1.x;
            vAvgMultiBlend.y = vMultiBlend.y + vAvgMultiBlend.y;
            vAvgMultiBlend.z = vMultiBlend.z + vAvgMultiBlend.z;
            vAvgMultiBlend.w = vMultiBlend.w + vAvgMultiBlend.w;
            vAvgAlphaBlend.y = vAlphaBlend.y + vAvgAlphaBlend.y;
            vAvgColor1.y = vColor1.y + vAvgColor1.y;
            vAvgColor1.z = vColor1.z + vAvgColor1.z;
            vAvgColor2.x = vColor2.x + vAvgColor2.x;
            vAvgColor2.y = vColor2.y + vAvgColor2.y;
            vAvgColor2.z = vColor2.z + vAvgColor2.z;
            vAvgColor3.x = vColor3.x + vAvgColor3.x;
            vAvgColor3.y = vColor3.y + vAvgColor3.y;
            vAvgColor3.z = vColor3.z + vAvgColor3.z;
            vAvgColor4.x = vAvgColor4.x + vColor4.x;
            vAvgColor4.y = vColor4.y + vAvgColor4.y;
            vAvgColor4.z = vColor4.z + vAvgColor4.z;
          }
          v1 = pTJData;
        }
      }
      ++ndxCorners;
      ++i;
      v65 = ndxCorners;
    }
    while ( i < v1->faceCount );
  }
  faceCount = v1->faceCount;
  v31 = 1.0 / (float)v1->faceCount;
  avgDist = v31 * avgDist;
  v32 = 1.0 / (float)faceCount;
  vAvgField.x = v32 * vAvgField.x;
  vAvgField.y = v32 * vAvgField.y;
  vAvgField.z = vAvgField.z * v32;
  vAvgSubdivPos.x = v32 * vAvgSubdivPos.x;
  vAvgSubdivPos.y = vAvgSubdivPos.y * v32;
  vAvgSubdivNormal.x = v32 * vAvgSubdivNormal.x;
  vAvgSubdivPos.z = vAvgSubdivPos.z * v32;
  vAvgSubdivNormal.y = vAvgSubdivNormal.y * v32;
  vAvgMultiBlend.x = v32 * vAvgMultiBlend.x;
  vAvgAlphaBlend.x = v32 * vAvgAlphaBlend.x;
  vAvgAlphaBlend.z = vAvgAlphaBlend.z * v32;
  vAvgAlphaBlend.w = vAvgAlphaBlend.w * v32;
  vAvgColor1.x = v32 * vAvgColor1.x;
  vAvgColor1.y = vAvgColor1.y * v32;
  vAvgColor1.z = vAvgColor1.z * v32;
  vAvgColor2.x = v32 * vAvgColor2.x;
  vAvgColor2.y = vAvgColor2.y * v32;
  vAvgColor2.z = vAvgColor2.z * v32;
  vAvgSubdivNormal.z = vAvgSubdivNormal.z * v32;
  flAvgAlpha = v31 * flAvgAlpha;
  vAvgMultiBlend.y = y * v32;
  vAvgMultiBlend.z = z * v32;
  vAvgMultiBlend.w = w * v32;
  vAvgAlphaBlend.y = v6 * v32;
  vAvgColor3.x = v32 * vAvgColor3.x;
  vAvgColor3.y = vAvgColor3.y * v32;
  vAvgColor3.z = vAvgColor3.z * v32;
  vAvgColor4.x = v32 * vAvgColor4.x;
  vAvgColor4.y = vAvgColor4.y * v32;
  vAvgColor4.z = vAvgColor4.z * v32;
  i = 0;
  if ( faceCount > 0 )
  {
    v33 = v1->ndxCorners;
    v65 = v33;
    do
    {
      v34 = *(v33 - 8);
      if ( v34 != 0 )
      {
        v35 = *(unsigned __int16 *)(v34 + 420);
        if ( (_WORD)v35 != 0xFFFF )
        {
          v36 = EditDispMgr();
          v37 = (int)v36->GetDisp(this: v36, a2: v35);
          v38 = v37;
          if ( *v33 == -1 )
          {
            v41 = v33[8];
            if ( v41 != -1 )
            {
              v42 = (1 << MEMORY[0x23]) + 1;
              v43 = v42 / 2;
              switch ( v41 )
              {
                case 0:
                  v40 = v43 * v42;
                  goto LABEL_39;
                case 1:
                  v40 = v43 + ((1 << MEMORY[0x23]) + 1) * (1 << MEMORY[0x23]);
                  goto LABEL_39;
                case 2:
                  v40 = v42 * (v42 - v43) - 1;
                  goto LABEL_39;
                case 3:
                  v40 = (1 << MEMORY[0x23]) - v43;
LABEL_39:
                  if ( v40 != -1 )
                  {
LABEL_40:
                    v44 = 224 * v40;
                    *(float *)(v44 + *(_DWORD *)(v38 + 784) + 12) = avgDist;
                    *(Vector *)(*(_DWORD *)(v38 + 784) + v44) = vAvgField;
                    v45 = *(_DWORD *)(v38 + 784);
                    *(float *)(v44 + v45 + 28) = vAvgSubdivPos.x;
                    v46 = 224 * v40 + v45 + 28;
                    *(float *)(v46 + 4) = vAvgSubdivPos.y;
                    *(float *)(v46 + 8) = vAvgSubdivPos.z;
                    *(Vector *)(224 * v40 + *(_DWORD *)(v38 + 784) + 16) = vAvgSubdivNormal;
                    *(float *)(v44 + *(_DWORD *)(v38 + 784) + 140) = flAvgAlpha;
                    CCoreDispInfo::SetMultiBlend(
                      this: (CCoreDispInfo *)(v38 + 24),
                      index: v40,
                      vBlend: &vAvgMultiBlend,
                      vAlphaBlend: &vAvgAlphaBlend,
                      vColor1: &vAvgColor1,
                      vColor2: &vAvgColor2,
                      vColor3: &vAvgColor3,
                      vColor4: &vAvgColor4);
                  }
                  break;
                default:
                  break;
              }
            }
          }
          else
          {
            v39 = *(_DWORD *)(v37 + 36);
            switch ( *v33 )
            {
              case 0:
                v40 = 0;
                goto LABEL_40;
              case 1:
                v40 = ((1 << v39) + 1) * (1 << v39);
                goto LABEL_39;
              case 2:
                v40 = ((1 << v39) + 1) * ((1 << v39) + 1) - 1;
                goto LABEL_39;
              case 3:
                v40 = 1 << v39;
                goto LABEL_39;
              default:
                break;
            }
          }
        }
      }
      v33 = v65 + 1;
      ++i;
      ++v65;
    }
    while ( i < pTJData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024290
// Name: void SewTJunc_ResolveSolid(struct SewTJuncData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewTJunc_ResolveSolid(SewTJuncData_t *pTJData)
{
  bool v1; // cc
  int *ndxCorners; // edi
  int v3; // eax
  int v4; // esi
  CEditDispMgr *v5; // eax
  int v6; // esi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  int v13; // ecx
  int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  int v17; // edi
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // edx
  Vector4D vClearMultiBlend; // [esp+0h] [ebp-40h] BYREF
  Vector4D vClearAlphaBlend; // [esp+10h] [ebp-30h] BYREF
  Vector vSet; // [esp+20h] [ebp-20h] BYREF
  Vector vNormal; // [esp+2Ch] [ebp-14h] BYREF
  int *v25; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v1 = pTJData->faceCount <= 0;
  vSet.x = 1.0;
  vSet.y = 1.0;
  vSet.z = 1.0;
  memset(&vClearMultiBlend, 0, sizeof(vClearMultiBlend));
  memset(&vClearAlphaBlend, 0, sizeof(vClearAlphaBlend));
  i = 0;
  if ( !v1 )
  {
    ndxCorners = pTJData->ndxCorners;
    v25 = pTJData->ndxCorners;
    do
    {
      v3 = *(ndxCorners - 8);
      if ( v3 != 0 )
      {
        v4 = *(unsigned __int16 *)(v3 + 420);
        if ( (_WORD)v4 != 0xFFFF )
        {
          v5 = EditDispMgr();
          v6 = (int)v5->GetDisp(this: v5, a2: v4);
          v7 = *(float *)(v6 + 88) - *(float *)(v6 + 52);
          v8 = *(float *)(v6 + 92) - *(float *)(v6 + 56);
          v9 = *(float *)(v6 + 64) - *(float *)(v6 + 52);
          v10 = *(float *)(v6 + 68) - *(float *)(v6 + 56);
          v11 = *(float *)(v6 + 60) - *(float *)(v6 + 48);
          v12 = *(float *)(v6 + 84) - *(float *)(v6 + 48);
          vNormal.x = (float)(v7 * v10) - (float)(v8 * v9);
          vNormal.y = (float)(v8 * v11) - (float)(v12 * v10);
          vNormal.z = (float)(v12 * v9) - (float)(v7 * v11);
          VectorNormalize(vec: &vNormal);
          if ( *ndxCorners == -1 )
          {
            v15 = ndxCorners[8];
            if ( v15 != -1 )
            {
              v16 = *(_DWORD *)(v6 + 36);
              v17 = (1 << v16) + 1;
              v18 = v17 / 2;
              switch ( v15 )
              {
                case 0:
                  v14 = v18 * v17;
                  goto LABEL_17;
                case 1:
                  v14 = v18 + ((1 << v16) + 1) * (1 << v16);
                  goto LABEL_17;
                case 2:
                  v14 = v17 * (v17 - v18) - 1;
                  goto LABEL_17;
                case 3:
                  v14 = (1 << v16) - v18;
LABEL_17:
                  if ( v14 != -1 )
                  {
LABEL_18:
                    v19 = 224 * v14;
                    *(_DWORD *)(*(_DWORD *)(v6 + 784) + v19 + 12) = 0;
                    *(Vector *)(*(_DWORD *)(v6 + 784) + v19) = vNormal;
                    v20 = (_DWORD *)(*(_DWORD *)(v6 + 784) + 224 * v14 + 28);
                    *v20 = 0;
                    v20[1] = 0;
                    v20[2] = 0;
                    *(Vector *)(*(_DWORD *)(v6 + 784) + 224 * v14 + 16) = vNormal;
                    *(_DWORD *)(*(_DWORD *)(v6 + 784) + v19 + 140) = 0;
                    CCoreDispInfo::SetMultiBlend(
                      this: (CCoreDispInfo *)(v6 + 24),
                      index: v14,
                      vBlend: &vClearMultiBlend,
                      vAlphaBlend: &vClearAlphaBlend,
                      vColor1: &vSet,
                      vColor2: &vSet,
                      vColor3: &vSet,
                      vColor4: &vSet);
                  }
                  break;
                default:
                  break;
              }
            }
          }
          else
          {
            v13 = *(_DWORD *)(v6 + 36);
            switch ( *ndxCorners )
            {
              case 0:
                v14 = 0;
                goto LABEL_18;
              case 1:
                v14 = ((1 << v13) + 1) * (1 << v13);
                goto LABEL_17;
              case 2:
                v14 = ((1 << v13) + 1) * ((1 << v13) + 1) - 1;
                goto LABEL_17;
              case 3:
                v14 = 1 << v13;
                goto LABEL_17;
              default:
                break;
            }
          }
        }
      }
      ndxCorners = v25 + 1;
      ++i;
      ++v25;
    }
    while ( i < pTJData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024530
// Name: bool SewEdge_IsSolidTJunc(struct SewEdgeData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SewEdge_IsSolidTJunc(SewEdgeData_t *pEdgeData, CMapFace *type)
{
  int v2; // ecx
  CMapFace **i; // eax

  v2 = 0;
  if ( pEdgeData->faceCount <= 0 )
    return 0;
  for ( i = pEdgeData->pFaces; i[6] != type || (*i)->m_DispHandle != 0xFFFF; ++i )
  {
    if ( ++v2 >= pEdgeData->faceCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024580
// Name: bool SewEdge_AddToListMerge(struct SewEdgeData_t __near *,struct SewEdgeData_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SewEdge_AddToListMerge(SewEdgeData_t *pEdgeData, SewEdgeData_t *pCmpData)
{
  bool result; // al
  int *type; // esi
  int v4; // eax
  int faceCount; // ebx
  int v6; // edx
  int *v7; // esi
  int v8; // edx
  int i; // [esp+4h] [ebp-Ch]
  int *v10; // [esp+8h] [ebp-8h]
  bool bReturn; // [esp+Fh] [ebp-1h]

  result = true;
  bReturn = true;
  i = 0;
  if ( pEdgeData->faceCount > 0 )
  {
    type = pEdgeData->type;
    v10 = pEdgeData->type;
    do
    {
      v4 = *type;
      if ( *type != 3 )
      {
        faceCount = pCmpData->faceCount;
        v6 = 0;
        if ( pCmpData->faceCount > 0 )
        {
          v7 = pCmpData->type;
          do
          {
            if ( *v7 != 3 && v4 == *v7 )
              break;
            ++v6;
            ++v7;
          }
          while ( v6 < faceCount );
          type = v10;
        }
        if ( v6 == faceCount )
        {
          v8 = *(type - 3);
          if ( faceCount >= 3 )
          {
            bReturn = false;
          }
          else
          {
            pCmpData->pFaces[faceCount] = (CMapFace *)*(type - 6);
            pCmpData->ndxEdges[pCmpData->faceCount] = v8;
            pCmpData->type[pCmpData->faceCount++] = v4;
          }
        }
      }
      ++type;
      ++i;
      v10 = type;
    }
    while ( i < pEdgeData->faceCount );
    return bReturn;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024620
// Name: void SewEdge_ResolveSolidTJunc(struct SewEdgeData_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_ResolveSolidTJunc(SewEdgeData_t *pEdgeData, int type, bool bStart)
{
  bool v3; // cc
  int *ndxEdges; // eax
  int v5; // esi
  CEditDispMgr *v6; // eax
  int v7; // esi
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  int v14; // ecx
  int v15; // edi
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  _DWORD *v20; // edx
  int v21; // edi
  int v22; // ebx
  int j; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  _DWORD *v27; // edx
  int k; // ebx
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  _DWORD *v32; // edx
  Vector4D vClearMultiBlend; // [esp+0h] [ebp-40h] BYREF
  Vector4D vClearAlphaBlend; // [esp+10h] [ebp-30h] BYREF
  Vector vSet; // [esp+20h] [ebp-20h] BYREF
  Vector vNormal; // [esp+2Ch] [ebp-14h] BYREF
  int i; // [esp+38h] [ebp-8h]
  int *v38; // [esp+3Ch] [ebp-4h]

  v3 = pEdgeData->faceCount <= 0;
  vSet.x = 1.0;
  vSet.y = 1.0;
  vSet.z = 1.0;
  memset(&vClearMultiBlend, 0, sizeof(vClearMultiBlend));
  memset(&vClearAlphaBlend, 0, sizeof(vClearAlphaBlend));
  i = 0;
  if ( !v3 )
  {
    ndxEdges = pEdgeData->ndxEdges;
    v38 = pEdgeData->ndxEdges;
    do
    {
      if ( ndxEdges[3] == type )
      {
        v5 = *(unsigned __int16 *)(*(ndxEdges - 3) + 420);
        if ( (_WORD)v5 != 0xFFFF )
        {
          v6 = EditDispMgr();
          v7 = (int)v6->GetDisp(this: v6, a2: v5);
          v8 = *(float *)(v7 + 88) - *(float *)(v7 + 52);
          v9 = *(float *)(v7 + 92) - *(float *)(v7 + 56);
          v10 = *(float *)(v7 + 64) - *(float *)(v7 + 52);
          v11 = *(float *)(v7 + 68) - *(float *)(v7 + 56);
          v12 = *(float *)(v7 + 60) - *(float *)(v7 + 48);
          v13 = *(float *)(v7 + 84) - *(float *)(v7 + 48);
          vNormal.x = (float)(v8 * v11) - (float)(v9 * v10);
          vNormal.y = (float)(v9 * v12) - (float)(v13 * v11);
          vNormal.z = (float)(v13 * v10) - (float)(v8 * v12);
          VectorNormalize(vec: &vNormal);
          v14 = *(_DWORD *)(v7 + 36);
          v15 = 1;
          if ( type == 3 )
          {
            v21 = 1 << v14;
            v22 = ((1 << v14) + 1) / 2;
            if ( bStart )
            {
              for ( j = 1; j < v22; ++j )
              {
                v24 = (1 << *(_DWORD *)(v7 + 36)) + 1;
                switch ( *v38 )
                {
                  case 0:
                    v25 = j * v24;
                    goto LABEL_23;
                  case 1:
                    v25 = j + v24 * (v24 - 1);
                    goto LABEL_23;
                  case 2:
                    v25 = v24 * (v24 - j) - 1;
                    goto LABEL_23;
                  case 3:
                    v25 = (1 << *(_DWORD *)(v7 + 36)) - j;
LABEL_23:
                    if ( v25 != -1 )
                    {
                      v26 = 224 * v25;
                      *(_DWORD *)(v26 + *(_DWORD *)(v7 + 784) + 12) = 0;
                      *(Vector *)(*(_DWORD *)(v7 + 784) + v26) = vNormal;
                      v27 = (_DWORD *)(224 * v25 + *(_DWORD *)(v7 + 784) + 28);
                      *v27 = 0;
                      v27[1] = 0;
                      v27[2] = 0;
                      *(Vector *)(224 * v25 + *(_DWORD *)(v7 + 784) + 16) = vNormal;
                      *(_DWORD *)(v26 + *(_DWORD *)(v7 + 784) + 140) = 0;
                      CCoreDispInfo::SetMultiBlend(
                        this: (CCoreDispInfo *)(v7 + 24),
                        index: v25,
                        vBlend: &vClearMultiBlend,
                        vAlphaBlend: &vClearAlphaBlend,
                        vColor1: &vSet,
                        vColor2: &vSet,
                        vColor3: &vSet,
                        vColor4: &vSet);
                    }
                    break;
                  default:
                    continue;
                }
              }
            }
            else
            {
              for ( k = v22 + 1; k < v21; ++k )
              {
                v29 = (1 << *(_DWORD *)(v7 + 36)) + 1;
                switch ( *v38 )
                {
                  case 0:
                    v30 = k * v29;
                    goto LABEL_33;
                  case 1:
                    v30 = k + v29 * (v29 - 1);
                    goto LABEL_33;
                  case 2:
                    v30 = v29 * (v29 - k) - 1;
                    goto LABEL_33;
                  case 3:
                    v30 = (1 << *(_DWORD *)(v7 + 36)) - k;
LABEL_33:
                    if ( v30 != -1 )
                    {
                      v31 = 224 * v30;
                      *(_DWORD *)(v31 + *(_DWORD *)(v7 + 784) + 12) = 0;
                      *(Vector *)(*(_DWORD *)(v7 + 784) + v31) = vNormal;
                      v32 = (_DWORD *)(224 * v30 + *(_DWORD *)(v7 + 784) + 28);
                      *v32 = 0;
                      v32[1] = 0;
                      v32[2] = 0;
                      *(Vector *)(224 * v30 + *(_DWORD *)(v7 + 784) + 16) = vNormal;
                      *(_DWORD *)(v31 + *(_DWORD *)(v7 + 784) + 140) = 0;
                      CCoreDispInfo::SetMultiBlend(
                        this: (CCoreDispInfo *)(v7 + 24),
                        index: v30,
                        vBlend: &vClearMultiBlend,
                        vAlphaBlend: &vClearAlphaBlend,
                        vColor1: &vSet,
                        vColor2: &vSet,
                        vColor3: &vSet,
                        vColor4: &vSet);
                    }
                    break;
                  default:
                    continue;
                }
              }
            }
          }
          else
          {
            v16 = 1 << v14;
            if ( 1 << v14 > 1 )
            {
              do
              {
                v17 = (1 << *(_DWORD *)(v7 + 36)) + 1;
                switch ( *v38 )
                {
                  case 0:
                    v18 = v15 * v17;
                    goto LABEL_12;
                  case 1:
                    v18 = v15 + v17 * (v17 - 1);
                    goto LABEL_12;
                  case 2:
                    v18 = v17 * (v17 - v15) - 1;
                    goto LABEL_12;
                  case 3:
                    v18 = (1 << *(_DWORD *)(v7 + 36)) - v15;
LABEL_12:
                    if ( v18 != -1 )
                    {
                      v19 = 224 * v18;
                      *(_DWORD *)(*(_DWORD *)(v7 + 784) + v19 + 12) = 0;
                      *(Vector *)(*(_DWORD *)(v7 + 784) + v19) = vNormal;
                      v20 = (_DWORD *)(*(_DWORD *)(v7 + 784) + 224 * v18 + 28);
                      *v20 = 0;
                      v20[1] = 0;
                      v20[2] = 0;
                      *(Vector *)(*(_DWORD *)(v7 + 784) + 224 * v18 + 16) = vNormal;
                      *(_DWORD *)(*(_DWORD *)(v7 + 784) + v19 + 140) = 0;
                      CCoreDispInfo::SetMultiBlend(
                        this: (CCoreDispInfo *)(v7 + 24),
                        index: v18,
                        vBlend: &vClearMultiBlend,
                        vAlphaBlend: &vClearAlphaBlend,
                        vColor1: &vSet,
                        vColor2: &vSet,
                        vColor3: &vSet,
                        vColor4: &vSet);
                    }
                    break;
                  default:
                    break;
                }
                ++v15;
              }
              while ( v15 < v16 );
            }
          }
        }
      }
      ndxEdges = v38 + 1;
      ++i;
      ++v38;
    }
    while ( i < pEdgeData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024AE0
// Name: void SewEdge_ResolveSolidNormal(struct SewEdgeData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_ResolveSolidNormal(SewEdgeData_t *pEdgeData)
{
  bool v1; // cc
  int v2; // esi
  CEditDispMgr *v3; // eax
  int v4; // esi
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  int v11; // edi
  int v12; // ebx
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  _DWORD *v17; // edx
  Vector4D vClearMultiBlend; // [esp+0h] [ebp-40h] BYREF
  Vector4D vClearAlphaBlend; // [esp+10h] [ebp-30h] BYREF
  Vector vSet; // [esp+20h] [ebp-20h] BYREF
  Vector vNormal; // [esp+2Ch] [ebp-14h] BYREF
  int i; // [esp+38h] [ebp-8h]
  int *ndxEdges; // [esp+3Ch] [ebp-4h]

  v1 = pEdgeData->faceCount <= 0;
  vSet.x = 1.0;
  vSet.y = 1.0;
  vSet.z = 1.0;
  memset(&vClearMultiBlend, 0, sizeof(vClearMultiBlend));
  memset(&vClearAlphaBlend, 0, sizeof(vClearAlphaBlend));
  i = 0;
  if ( !v1 )
  {
    ndxEdges = pEdgeData->ndxEdges;
    do
    {
      v2 = *(unsigned __int16 *)(*(ndxEdges - 3) + 420);
      if ( (_WORD)v2 != 0xFFFF )
      {
        v3 = EditDispMgr();
        v4 = (int)v3->GetDisp(this: v3, a2: v2);
        v5 = *(float *)(v4 + 88) - *(float *)(v4 + 52);
        v6 = *(float *)(v4 + 92) - *(float *)(v4 + 56);
        v7 = *(float *)(v4 + 64) - *(float *)(v4 + 52);
        v8 = *(float *)(v4 + 68) - *(float *)(v4 + 56);
        v9 = *(float *)(v4 + 60) - *(float *)(v4 + 48);
        v10 = *(float *)(v4 + 84) - *(float *)(v4 + 48);
        vNormal.x = (float)(v5 * v8) - (float)(v6 * v7);
        vNormal.y = (float)(v6 * v9) - (float)(v10 * v8);
        vNormal.z = (float)(v10 * v7) - (float)(v5 * v9);
        VectorNormalize(vec: &vNormal);
        v11 = 0;
        v12 = (1 << *(_DWORD *)(v4 + 36)) + 1;
        if ( v12 > 0 )
        {
          do
          {
            v13 = (1 << *(_DWORD *)(v4 + 36)) + 1;
            switch ( *ndxEdges )
            {
              case 0:
                v14 = v11 * v13;
                goto LABEL_10;
              case 1:
                v14 = v11 + v13 * (v13 - 1);
                goto LABEL_10;
              case 2:
                v14 = v13 * (v13 - v11) - 1;
                goto LABEL_10;
              case 3:
                v14 = (1 << *(_DWORD *)(v4 + 36)) - v11;
LABEL_10:
                if ( v14 != -1 )
                {
                  v15 = 224 * v14;
                  *(_DWORD *)(v15 + *(_DWORD *)(v4 + 784) + 12) = 0;
                  v16 = *(_DWORD *)(v4 + 784);
                  *(_DWORD *)(v16 + v15) = 0;
                  *(_DWORD *)(v16 + v15 + 4) = 0;
                  *(_DWORD *)(v16 + v15 + 8) = 0;
                  v17 = (_DWORD *)(224 * v14 + *(_DWORD *)(v4 + 784) + 28);
                  *v17 = 0;
                  v17[1] = 0;
                  v17[2] = 0;
                  *(Vector *)(224 * v14 + *(_DWORD *)(v4 + 784) + 16) = vNormal;
                  *(_DWORD *)(v15 + *(_DWORD *)(v4 + 784) + 140) = 0;
                  CCoreDispInfo::SetMultiBlend(
                    this: (CCoreDispInfo *)(v4 + 24),
                    index: v14,
                    vBlend: &vClearMultiBlend,
                    vAlphaBlend: &vClearAlphaBlend,
                    vColor1: &vSet,
                    vColor2: &vSet,
                    vColor3: &vSet,
                    vColor4: &vSet);
                }
                break;
              default:
                break;
            }
            ++v11;
          }
          while ( v11 < v12 );
        }
      }
      ++ndxEdges;
      ++i;
    }
    while ( i < pEdgeData->faceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024D30
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // ecx

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
        m_nAllocationCount = 32;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char *)_realloc_crt(ptr: m_pMemory, size: m_nAllocationCount);
    else
      this->m_pMemory = (char *)MemAlloc_Alloc(nSize: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024DC0
// Name: void AverageVectorFieldData(class CMapDisp __near *,int,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AverageVectorFieldData(CMapFace *pDisp1, int ndx1, CMapDisp *pDisp2, int ndx2)
{
  CoreDispVert_t *m_pVerts; // edx
  CoreDispVert_t *Points; // eax
  unsigned int v7; // esi
  float m_FieldDistance; // xmm0_4
  unsigned int v9; // edi
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  double v13; // st7
  CoreDispVert_t *v14; // edx
  float v15; // xmm0_4
  CoreDispVert_t *v16; // eax
  CoreDispVert_t *v17; // edx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float *p_x; // eax
  float v22; // xmm2_4
  float v23; // xmm0_4
  CoreDispVert_t *v24; // ecx
  CoreDispVert_t *v25; // eax
  int p_m_SubdivNormal; // esi
  char szMatName1[128]; // [esp+Ch] [ebp-1B0h] BYREF
  char szMatName2[128]; // [esp+8Ch] [ebp-130h] BYREF
  Vector4D vAlphaBlendB; // [esp+10Ch] [ebp-B0h] BYREF
  Vector4D vAlphaBlendA; // [esp+11Ch] [ebp-A0h] BYREF
  Vector vColorB[4]; // [esp+12Ch] [ebp-90h] BYREF
  Vector4D vMultiBlendB; // [esp+15Ch] [ebp-60h] BYREF
  CMapFace *pFace2; // [esp+16Ch] [ebp-50h]
  Vector4D vMultiBlendA; // [esp+170h] [ebp-4Ch] BYREF
  Vector vColorA[4]; // [esp+180h] [ebp-3Ch] BYREF
  Vector vAvg; // [esp+1B0h] [ebp-Ch] BYREF
  CMapFace *pFace1; // [esp+1C4h] [ebp+8h]

  m_pVerts = pDisp2->m_CoreDispInfo.m_pVerts;
  Points = (CoreDispVert_t *)pDisp1[1].Points;
  v7 = ndx1;
  m_FieldDistance = Points[ndx1].m_FieldDistance;
  v9 = ndx2;
  v10 = m_pVerts[ndx2].m_FieldDistance;
  v11 = (float)((float)(Points[ndx1].m_FieldVector.y * m_FieldDistance) + (float)(m_pVerts[ndx2].m_FieldVector.y * v10))
      * 0.5;
  v12 = (float)((float)(m_pVerts[ndx2].m_FieldVector.z * v10) + (float)(Points[ndx1].m_FieldVector.z * m_FieldDistance))
      * 0.5;
  vAvg.x = (float)((float)(m_pVerts[ndx2].m_FieldVector.x * v10)
                 + (float)(Points[ndx1].m_FieldVector.x * m_FieldDistance))
         * 0.5;
  vAvg.y = v11;
  vAvg.z = v12;
  v13 = VectorNormalize(vec: &vAvg);
  *(float *)((char *)&pDisp1[1].Points[1].x + v7 * 224) = v13;
  pDisp2->m_CoreDispInfo.m_pVerts[v9].m_FieldDistance = v13;
  *(Vector *)((char *)pDisp1[1].Points + v7 * 224) = vAvg;
  pDisp2->m_CoreDispInfo.m_pVerts[v9].m_FieldVector = vAvg;
  pFace1 = (CMapFace *)pDisp1->GetParent(this: pDisp1);
  pFace2 = (CMapFace *)pDisp2->GetParent(this: pDisp2);
  pFace1->m_pTexture->GetShortName(this: pFace1->m_pTexture, a2: szMatName1);
  pFace2->m_pTexture->GetShortName(this: pFace2->m_pTexture, a2: szMatName2);
  if ( _V_stricmp(s1: szMatName1, s2: szMatName2) == 0 )
  {
    v14 = (CoreDispVert_t *)pDisp1[1].Points;
    v15 = (float)(v14[v7].m_Alpha * 2.0) * 0.5;
    v14[v7].m_Alpha = v15;
    pDisp2->m_CoreDispInfo.m_pVerts[v9].m_Alpha = v15;
  }
  CCoreDispInfo::GetMultiBlend(
    this: (CCoreDispInfo *)&pDisp1->texture.texture[4],
    index: ndx1,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  CCoreDispInfo::GetMultiBlend(
    this: &pDisp2->m_CoreDispInfo,
    index: ndx2,
    vBlend: &vMultiBlendB,
    vAlphaBlend: &vAlphaBlendB,
    vColor1: vColorB,
    vColor2: &vColorB[1],
    vColor3: &vColorB[2],
    vColor4: &vColorB[3]);
  vMultiBlendA.x = (float)((float)((float)(vMultiBlendB.x + vMultiBlendA.x) * 0.5) + vMultiBlendB.x) * 0.5;
  vMultiBlendA.y = (float)((float)((float)(vMultiBlendB.y + vMultiBlendA.y) * 0.5) + vMultiBlendB.y) * 0.5;
  vMultiBlendA.z = (float)((float)((float)(vMultiBlendB.z + vMultiBlendA.z) * 0.5) + vMultiBlendB.z) * 0.5;
  vColorA[0].x = (float)(vColorB[0].x + vColorA[0].x) * 0.5;
  vColorA[0].y = (float)(vColorB[0].y + vColorA[0].y) * 0.5;
  vColorA[0].z = (float)(vColorB[0].z + vColorA[0].z) * 0.5;
  vMultiBlendA.w = (float)((float)((float)(vMultiBlendB.w + vMultiBlendA.w) * 0.5) + vMultiBlendB.w) * 0.5;
  vColorA[1].x = (float)(vColorA[1].x + vColorB[1].x) * 0.5;
  vColorA[1].y = (float)(vColorA[1].y + vColorB[1].y) * 0.5;
  vColorA[1].z = (float)(vColorA[1].z + vColorB[1].z) * 0.5;
  vColorA[2].x = (float)(vColorB[2].x + vColorA[2].x) * 0.5;
  vColorA[2].y = (float)(vColorB[2].y + vColorA[2].y) * 0.5;
  vColorA[2].z = (float)(vColorB[2].z + vColorA[2].z) * 0.5;
  vColorA[3].x = (float)(vColorA[3].x + vColorB[3].x) * 0.5;
  vColorA[3].y = (float)(vColorB[3].y + vColorA[3].y) * 0.5;
  vColorA[3].z = (float)(vColorB[3].z + vColorA[3].z) * 0.5;
  CCoreDispInfo::SetMultiBlend(
    this: (CCoreDispInfo *)&pDisp1->texture.texture[4],
    index: ndx1,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  CCoreDispInfo::SetMultiBlend(
    this: &pDisp2->m_CoreDispInfo,
    index: ndx2,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  v16 = (CoreDispVert_t *)pDisp1[1].Points;
  v17 = pDisp2->m_CoreDispInfo.m_pVerts;
  v18 = v16[v7].m_SubdivPos.y + v17[v9].m_SubdivPos.y;
  v19 = v17[v9].m_SubdivPos.x + v16[v7].m_SubdivPos.x;
  v20 = v17[v9].m_SubdivPos.z + v16[v7].m_SubdivPos.z;
  p_x = &v16[v7].m_FieldVector.x;
  vAvg.y = v18 * 0.5;
  vAvg.x = v19 * 0.5;
  vAvg.z = v20 * 0.5;
  p_x[7] = v19 * 0.5;
  p_x[8] = vAvg.y;
  p_x[9] = vAvg.z;
  v17[v9].m_SubdivPos = vAvg;
  v22 = v17[v9].m_SubdivNormal.z + p_x[6];
  v23 = p_x[5] + v17[v9].m_SubdivNormal.y;
  vAvg.x = v17[v9].m_SubdivNormal.x + p_x[4];
  vAvg.y = v23;
  vAvg.z = v22;
  VectorNormalize(vec: &vAvg);
  v24 = (CoreDispVert_t *)pDisp1[1].Points;
  v25 = pDisp2->m_CoreDispInfo.m_pVerts;
  v24[v7].m_SubdivNormal.x = vAvg.x;
  p_m_SubdivNormal = (int)&v24[v7].m_SubdivNormal;
  *(float *)(p_m_SubdivNormal + 4) = vAvg.y;
  *(float *)(p_m_SubdivNormal + 8) = vAvg.z;
  v25[v9].m_SubdivNormal = vAvg;
}

//------------------------------------------------------------------------------
// Address: 0x100252B0
// Name: void BlendVectorFieldData(class CMapDisp __near *,int,int,class CMapDisp __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendVectorFieldData(
        CMapDisp *pDisp1,
        CMapFace *ndxSrc1,
        int ndxDst1,
        CMapDisp *pDisp2,
        CMapFace *ndxSrc2,
        int ndxDst2,
        float blendFactor)
{
  CoreDispVert_t *m_pVerts; // edx
  float m_FieldDistance; // xmm1_4
  float x; // xmm5_4
  float y; // xmm6_4
  float z; // xmm7_4
  int v12; // ebx
  CoreDispVert_t *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  double v18; // st7
  unsigned int v19; // edi
  int v20; // esi
  CMapAtom_vtbl *v21; // edx
  CoreDispVert_t *v22; // eax
  float v23; // xmm0_4
  CoreDispVert_t *v24; // ecx
  int v25; // edx
  CoreDispVert_t *v26; // eax
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  char szMatName1[128]; // [esp+Ch] [ebp-1B0h] BYREF
  char szMatName2[128]; // [esp+8Ch] [ebp-130h] BYREF
  Vector4D vAlphaBlendB; // [esp+10Ch] [ebp-B0h] BYREF
  Vector4D vMultiBlendB; // [esp+11Ch] [ebp-A0h] BYREF
  Vector vColorB[4]; // [esp+12Ch] [ebp-90h] BYREF
  int v36; // [esp+15Ch] [ebp-60h]
  Vector4D vMultiBlendA; // [esp+160h] [ebp-5Ch] BYREF
  Vector4D vAlphaBlendA; // [esp+170h] [ebp-4Ch] BYREF
  Vector vColorA[4]; // [esp+180h] [ebp-3Ch] BYREF
  Vector vBlend; // [esp+1B0h] [ebp-Ch] BYREF
  CMapFace *pFace1; // [esp+1C8h] [ebp+Ch]
  CMapFace *pFace2; // [esp+1D4h] [ebp+18h]

  m_pVerts = pDisp2->m_CoreDispInfo.m_pVerts;
  m_FieldDistance = m_pVerts[(_DWORD)ndxSrc2].m_FieldDistance;
  x = m_pVerts[(_DWORD)ndxSrc2].m_FieldVector.x;
  y = m_pVerts[(_DWORD)ndxSrc2].m_FieldVector.y;
  z = m_pVerts[(_DWORD)ndxSrc2].m_FieldVector.z;
  v12 = (int)ndxSrc1;
  v13 = pDisp1->m_CoreDispInfo.m_pVerts;
  v14 = v13[(_DWORD)ndxSrc1].m_FieldDistance;
  v15 = v13[(_DWORD)ndxSrc1].m_FieldVector.x;
  v16 = v13[(_DWORD)ndxSrc1].m_FieldVector.y;
  v17 = v13[(_DWORD)ndxSrc1].m_FieldVector.z;
  v36 = 224 * (_DWORD)ndxSrc2;
  vBlend.x = (float)((float)((float)(x * m_FieldDistance) - (float)(v15 * v14)) * blendFactor) + (float)(v15 * v14);
  vBlend.y = (float)((float)((float)(y * m_FieldDistance) - (float)(v16 * v14)) * blendFactor) + (float)(v16 * v14);
  vBlend.z = (float)((float)((float)(z * m_FieldDistance) - (float)(v17 * v14)) * blendFactor) + (float)(v17 * v14);
  v18 = VectorNormalize(vec: &vBlend);
  v19 = ndxDst1;
  v20 = ndxDst2;
  pDisp1->m_CoreDispInfo.m_pVerts[v19].m_FieldDistance = v18;
  pDisp2->m_CoreDispInfo.m_pVerts[v20].m_FieldDistance = v18;
  pDisp1->m_CoreDispInfo.m_pVerts[v19].m_FieldVector = vBlend;
  v21 = pDisp1->__vftable;
  pDisp2->m_CoreDispInfo.m_pVerts[v20].m_FieldVector = vBlend;
  pFace1 = (CMapFace *)v21->GetParent(this: pDisp1);
  pFace2 = (CMapFace *)pDisp2->GetParent(this: pDisp2);
  pFace1->m_pTexture->GetShortName(this: pFace1->m_pTexture, a2: szMatName1);
  pFace2->m_pTexture->GetShortName(this: pFace2->m_pTexture, a2: szMatName2);
  if ( _V_stricmp(s1: szMatName1, s2: szMatName2) == 0 )
  {
    v22 = pDisp1->m_CoreDispInfo.m_pVerts;
    v23 = (float)((float)(pDisp2->m_CoreDispInfo.m_pVerts[v20].m_Alpha - v22[v19].m_Alpha) * blendFactor)
        + v22[v19].m_Alpha;
    v22[v19].m_Alpha = v23;
    pDisp2->m_CoreDispInfo.m_pVerts[v20].m_Alpha = v23;
  }
  CCoreDispInfo::GetMultiBlend(
    this: &pDisp1->m_CoreDispInfo,
    index: ndxDst1,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  CCoreDispInfo::GetMultiBlend(
    this: &pDisp2->m_CoreDispInfo,
    index: ndxDst2,
    vBlend: &vMultiBlendB,
    vAlphaBlend: &vAlphaBlendB,
    vColor1: vColorB,
    vColor2: &vColorB[1],
    vColor3: &vColorB[2],
    vColor4: &vColorB[3]);
  vMultiBlendA.x = (float)(vMultiBlendB.x + vMultiBlendA.x) * 0.5;
  vMultiBlendA.y = (float)(vMultiBlendB.y + vMultiBlendA.y) * 0.5;
  vMultiBlendA.z = (float)(vMultiBlendB.z + vMultiBlendA.z) * 0.5;
  vAlphaBlendA.x = (float)(vAlphaBlendB.x + vAlphaBlendA.x) * 0.5;
  vMultiBlendA.w = (float)(vMultiBlendB.w + vMultiBlendA.w) * 0.5;
  vAlphaBlendA.y = (float)(vAlphaBlendB.y + vAlphaBlendA.y) * 0.5;
  vAlphaBlendA.z = (float)(vAlphaBlendB.z + vAlphaBlendA.z) * 0.5;
  vColorA[0].x = (float)(vColorB[0].x + vColorA[0].x) * 0.5;
  vAlphaBlendA.w = (float)(vAlphaBlendB.w + vAlphaBlendA.w) * 0.5;
  vColorA[0].y = (float)(vColorB[0].y + vColorA[0].y) * 0.5;
  vColorA[0].z = (float)(vColorB[0].z + vColorA[0].z) * 0.5;
  vColorA[1].x = (float)(vColorA[1].x + vColorB[1].x) * 0.5;
  vColorA[1].y = (float)(vColorA[1].y + vColorB[1].y) * 0.5;
  vColorA[1].z = (float)(vColorA[1].z + vColorB[1].z) * 0.5;
  vColorA[2].x = (float)(vColorB[2].x + vColorA[2].x) * 0.5;
  vColorA[2].y = (float)(vColorB[2].y + vColorA[2].y) * 0.5;
  vColorA[2].z = (float)(vColorB[2].z + vColorA[2].z) * 0.5;
  vColorA[3].x = (float)(vColorB[3].x + vColorA[3].x) * 0.5;
  vColorA[3].y = (float)(vColorB[3].y + vColorA[3].y) * 0.5;
  vColorA[3].z = (float)(vColorB[3].z + vColorA[3].z) * 0.5;
  CCoreDispInfo::SetMultiBlend(
    this: &pDisp1->m_CoreDispInfo,
    index: ndxDst1,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  CCoreDispInfo::SetMultiBlend(
    this: &pDisp2->m_CoreDispInfo,
    index: ndxDst2,
    vBlend: &vMultiBlendA,
    vAlphaBlend: &vAlphaBlendA,
    vColor1: vColorA,
    vColor2: &vColorA[1],
    vColor3: &vColorA[2],
    vColor4: &vColorA[3]);
  v24 = pDisp2->m_CoreDispInfo.m_pVerts;
  v25 = v36;
  v26 = pDisp1->m_CoreDispInfo.m_pVerts;
  v27 = (float)((float)(v24[v36 / 0xE0u].m_SubdivPos.x - v26[v12].m_SubdivPos.x) * blendFactor) + v26[v12].m_SubdivPos.x;
  v28 = (float)((float)(v24[v36 / 0xE0u].m_SubdivPos.z - v26[v12].m_SubdivPos.z) * blendFactor) + v26[v12].m_SubdivPos.z;
  vBlend.y = (float)((float)(v24[v36 / 0xE0u].m_SubdivPos.y - v26[v12].m_SubdivPos.y) * blendFactor)
           + v26[v12].m_SubdivPos.y;
  vBlend.z = v28;
  vBlend.x = v27;
  v26[v19].m_SubdivPos.x = v27;
  v26[v19].m_SubdivPos.y = vBlend.y;
  v26[v19].m_SubdivPos.z = vBlend.z;
  v24[v20].m_SubdivPos = vBlend;
  v29 = (float)((float)(*(float *)((char *)&v24->m_SubdivNormal.x + v25) - v26[v12].m_SubdivNormal.x) * blendFactor)
      + v26[v12].m_SubdivNormal.x;
  v30 = (float)((float)(*(float *)((char *)&v24->m_SubdivNormal.z + v25) - v26[v12].m_SubdivNormal.z) * blendFactor)
      + v26[v12].m_SubdivNormal.z;
  vBlend.y = (float)((float)(*(float *)((char *)&v24->m_SubdivNormal.y + v25) - v26[v12].m_SubdivNormal.y) * blendFactor)
           + v26[v12].m_SubdivNormal.y;
  vBlend.z = v30;
  vBlend.x = v29;
  v26[v19].m_SubdivNormal.x = v29;
  v26[v19].m_SubdivNormal.y = vBlend.y;
  v26[v19].m_SubdivNormal.z = vBlend.z;
  v24[v20].m_SubdivNormal = vBlend;
}

//------------------------------------------------------------------------------
// Address: 0x10025830
// Name: void SewEdge_ResolveDispTJunc(struct SewEdgeData_t __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_ResolveDispTJunc(SewEdgeData_t *pEdgeData, int ndxTJ, int ndxTJNeighbor, bool bStart)
{
  int m_DispHandle; // esi
  int v5; // edi
  CEditDispMgr *v6; // eax
  CMapDisp *v7; // ebx
  CEditDispMgr *v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // ecx
  int v13; // edi
  int v14; // esi
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  int m_Power; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int k; // esi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // esi
  int v33; // ecx
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // eax
  int v41; // ebx
  int v42; // eax
  int v43; // ecx
  int v44; // edi
  int v45; // esi
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  int v49; // ecx
  int v50; // eax
  int v51; // ebx
  int v52; // eax
  int v53; // ecx
  int v54; // edi
  int v55; // esi
  int v56; // ecx
  int v57; // eax
  int blendFactor; // [esp+10h] [ebp-20h]
  int blendFactora; // [esp+10h] [ebp-20h]
  int v60; // [esp+14h] [ebp-1Ch]
  int v61; // [esp+14h] [ebp-1Ch]
  int v62; // [esp+14h] [ebp-1Ch]
  int v63; // [esp+18h] [ebp-18h]
  int v64; // [esp+18h] [ebp-18h]
  int v65; // [esp+18h] [ebp-18h]
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+1Ch] [ebp-14h]
  int v68; // [esp+1Ch] [ebp-14h]
  float v69; // [esp+1Ch] [ebp-14h]
  CMapDisp *pDisp2; // [esp+20h] [ebp-10h]
  CMapDisp *pDisp2a; // [esp+20h] [ebp-10h]
  int v72; // [esp+24h] [ebp-Ch]
  CMapDisp *pDisp1; // [esp+28h] [ebp-8h]
  CMapDisp *pDisp1a; // [esp+28h] [ebp-8h]
  bool j_3; // [esp+2Fh] [ebp-1h]
  int v76; // [esp+3Ch] [ebp+Ch]
  int v77; // [esp+40h] [ebp+10h]

  m_DispHandle = pEdgeData->pFaces[ndxTJ]->m_DispHandle;
  v5 = pEdgeData->pFaces[ndxTJNeighbor]->m_DispHandle;
  if ( (_WORD)m_DispHandle != 0xFFFF && (_WORD)v5 != 0xFFFF )
  {
    v6 = EditDispMgr();
    v7 = v6->GetDisp(this: v6, a2: m_DispHandle);
    pDisp2 = v7;
    v8 = EditDispMgr();
    v9 = (int)v8->GetDisp(this: v8, a2: v5);
    v10 = *(_DWORD *)(v9 + 36);
    pDisp1 = (CMapDisp *)v9;
    v60 = (1 << v7->m_CoreDispInfo.m_Power) + 1;
    v11 = v60 / 2;
    v63 = (1 << v10) + 1;
    v12 = 1 << v10;
    v13 = v12 / (v60 / 2);
    v72 = v13;
    j_3 = v13 < 1;
    if ( v13 < 1 )
    {
      v13 = v11 / v12;
      v72 = v11 / v12;
    }
    if ( bStart )
    {
      if ( v12 / (v60 / 2) >= 1 )
      {
        v20 = 1;
        for ( i = v72; v20 < v11; ++v20 )
        {
          m_Power = v7->m_CoreDispInfo.m_Power;
          v22 = (1 << m_Power) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJ] )
          {
            case 0:
              v23 = v20 * v22;
              break;
            case 1:
              v23 = v20 + ((1 << m_Power) + 1) * (1 << m_Power);
              break;
            case 2:
              v23 = v22 * (v22 - v20) - 1;
              break;
            case 3:
              v23 = (1 << m_Power) - v20;
              break;
            default:
              v23 = -1;
              break;
          }
          v24 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJNeighbor] )
          {
            case 0:
              v25 = v24 * (v24 - 1) - i * v24;
              break;
            case 1:
              v25 = v24 * v24 - i - 1;
              break;
            case 2:
              v25 = i * v24 + v24 - 1;
              break;
            case 3:
              v25 = i;
              break;
            default:
              v25 = -1;
              break;
          }
          v7 = pDisp2;
          AverageVectorFieldData((CMapFace *)pDisp1, ndx1: v25, pDisp2, ndx2: v23);
          i += v72;
        }
      }
      else
      {
        v14 = 1;
        for ( j = v13; v14 < v63; j += v72 )
        {
          v15 = v7->m_CoreDispInfo.m_Power;
          v16 = (1 << v15) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJ] )
          {
            case 0:
              v17 = v13 * v16;
              break;
            case 1:
              v17 = v13 + ((1 << v15) + 1) * (1 << v15);
              break;
            case 2:
              v17 = v16 * (v16 - v13) - 1;
              break;
            case 3:
              v17 = (1 << v15) - v13;
              break;
            default:
              v17 = -1;
              break;
          }
          v18 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJNeighbor] )
          {
            case 0:
              v19 = v18 * (v18 - 1) - v14 * v18;
              break;
            case 1:
              v19 = v18 * v18 - v14 - 1;
              break;
            case 2:
              v19 = v14 * v18 + v18 - 1;
              break;
            case 3:
              v19 = v14;
              break;
            default:
              v19 = -1;
              break;
          }
          AverageVectorFieldData((CMapFace *)pDisp1, ndx1: v19, pDisp2: v7, ndx2: v17);
          v13 = v72 + j;
          ++v14;
        }
      }
    }
    else
    {
      v68 = v13;
      if ( v12 / (v60 / 2) >= 1 )
      {
        v32 = v11 + 1;
        if ( v32 < 1 << v7->m_CoreDispInfo.m_Power )
        {
          do
          {
            v33 = v7->m_CoreDispInfo.m_Power;
            v34 = (1 << v33) + 1;
            switch ( pEdgeData->ndxEdges[ndxTJ] )
            {
              case 0:
                v35 = v32 * v34;
                break;
              case 1:
                v35 = v32 + ((1 << v33) + 1) * (1 << v33);
                break;
              case 2:
                v35 = v34 * (v34 - v32) - 1;
                break;
              case 3:
                v35 = (1 << v33) - v32;
                break;
              default:
                v35 = -1;
                break;
            }
            v36 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
            switch ( pEdgeData->ndxEdges[ndxTJNeighbor] )
            {
              case 0:
                v37 = v36 * (v36 - 1) - v68 * v36;
                break;
              case 1:
                v37 = v36 * v36 - v68 - 1;
                break;
              case 2:
                v37 = v68 * v36 + v36 - 1;
                break;
              case 3:
                v37 = v68;
                break;
              default:
                v37 = -1;
                break;
            }
            AverageVectorFieldData((CMapFace *)pDisp1, ndx1: v37, pDisp2: v7, ndx2: v35);
            v68 += v72;
            ++v32;
          }
          while ( v32 < v60 - 1 );
        }
      }
      else
      {
        for ( k = 1; k < v63; v68 += v72 )
        {
          v27 = v7->m_CoreDispInfo.m_Power;
          v28 = (1 << v27) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJ] )
          {
            case 0:
              v29 = ((1 << v27) + 1) * (1 << v27) - v13 * v28;
              break;
            case 1:
              v29 = v28 * v28 - v13 - 1;
              break;
            case 2:
              v29 = v13 * ((1 << v27) + 1) + (1 << v27);
              break;
            case 3:
              v29 = v13;
              break;
            default:
              v29 = -1;
              break;
          }
          v30 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
          switch ( pEdgeData->ndxEdges[ndxTJNeighbor] )
          {
            case 0:
              v31 = k * v30;
              break;
            case 1:
              v31 = k + v30 * (v30 - 1);
              break;
            case 2:
              v31 = v30 * (v30 - k) - 1;
              break;
            case 3:
              v31 = (1 << pDisp1->m_CoreDispInfo.m_Power) - k;
              break;
            default:
              v31 = -1;
              break;
          }
          AverageVectorFieldData((CMapFace *)pDisp1, ndx1: v31, pDisp2: v7, ndx2: v29);
          v13 = v72 + v68;
          ++k;
        }
      }
    }
    v69 = 1.0 / (float)v72;
    if ( j_3 )
    {
      pDisp1a = nullptr;
      blendFactor = v60 - v72;
      if ( v60 - v72 > 0 )
      {
        v77 = v72;
        v64 = 1 - v72;
        do
        {
          v38 = pEdgeData->ndxEdges[ndxTJ];
          v39 = pDisp2->m_CoreDispInfo.m_Power;
          v40 = (1 << v39) + 1;
          switch ( v38 )
          {
            case 0:
              v41 = (_DWORD)pDisp1a * v40;
              break;
            case 1:
              v41 = (int)pDisp1a + ((1 << v39) + 1) * (1 << v39);
              break;
            case 2:
              v41 = v40 * (v40 - (_DWORD)pDisp1a) - 1;
              break;
            case 3:
              v41 = (1 << v39) - (_DWORD)pDisp1a;
              break;
            default:
              v41 = -1;
              break;
          }
          v42 = (1 << v39) + 1;
          switch ( v38 )
          {
            case 0:
              v43 = v77;
              v44 = v77 * v42;
              break;
            case 1:
              v43 = v77;
              v44 = v77 + v42 * (v42 - 1);
              break;
            case 2:
              v43 = v77;
              v44 = v42 * (v42 - v77) - 1;
              break;
            case 3:
              v43 = v77;
              v44 = v42 - v77 - 1;
              break;
            default:
              v43 = v77;
              v44 = -1;
              break;
          }
          v45 = v43 + v64;
          if ( v43 + v64 < v43 )
          {
            v61 = v45 - (_DWORD)pDisp1a;
            do
            {
              v46 = (1 << pDisp2->m_CoreDispInfo.m_Power) + 1;
              switch ( pEdgeData->ndxEdges[ndxTJ] )
              {
                case 0:
                  v47 = v45 * v46;
                  break;
                case 1:
                  v47 = v45 + v46 * (v46 - 1);
                  break;
                case 2:
                  v47 = v46 * (v46 - v45) - 1;
                  break;
                case 3:
                  v47 = (1 << pDisp2->m_CoreDispInfo.m_Power) - v45;
                  break;
                default:
                  v47 = -1;
                  break;
              }
              BlendVectorFieldData(
                pDisp1: pDisp2,
                ndxSrc1: (CMapFace *)v41,
                ndxDst1: v47,
                pDisp2,
                ndxSrc2: (CMapFace *)v44,
                ndxDst2: v47,
                blendFactor: (float)v61++ * v69);
              ++v45;
            }
            while ( v45 < v77 );
          }
          v77 += v72;
          pDisp1a = (CMapDisp *)((char *)pDisp1a + v72);
        }
        while ( (int)pDisp1a < blendFactor );
      }
    }
    else
    {
      pDisp2a = nullptr;
      blendFactora = v63 - v72;
      if ( v63 - v72 > 0 )
      {
        v76 = v72;
        v65 = 1 - v72;
        do
        {
          v48 = pEdgeData->ndxEdges[ndxTJNeighbor];
          v49 = pDisp1->m_CoreDispInfo.m_Power;
          v50 = (1 << v49) + 1;
          switch ( v48 )
          {
            case 0:
              v51 = (_DWORD)pDisp2a * v50;
              break;
            case 1:
              v51 = (int)pDisp2a + ((1 << v49) + 1) * (1 << v49);
              break;
            case 2:
              v51 = v50 * (v50 - (_DWORD)pDisp2a) - 1;
              break;
            case 3:
              v51 = (1 << v49) - (_DWORD)pDisp2a;
              break;
            default:
              v51 = -1;
              break;
          }
          v52 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
          switch ( v48 )
          {
            case 0:
              v53 = v76;
              v54 = v76 * v52;
              break;
            case 1:
              v53 = v76;
              v54 = v76 + v52 * (v52 - 1);
              break;
            case 2:
              v53 = v76;
              v54 = v52 * (v52 - v76) - 1;
              break;
            case 3:
              v53 = v76;
              v54 = (1 << pDisp1->m_CoreDispInfo.m_Power) - v76;
              break;
            default:
              v53 = v76;
              v54 = -1;
              break;
          }
          v55 = v53 + v65;
          if ( v53 + v65 < v53 )
          {
            v62 = v55 - (_DWORD)pDisp2a;
            do
            {
              v56 = (1 << pDisp1->m_CoreDispInfo.m_Power) + 1;
              switch ( pEdgeData->ndxEdges[ndxTJNeighbor] )
              {
                case 0:
                  v57 = v55 * v56;
                  break;
                case 1:
                  v57 = v55 + v56 * (v56 - 1);
                  break;
                case 2:
                  v57 = v56 * (v56 - v55) - 1;
                  break;
                case 3:
                  v57 = (1 << pDisp1->m_CoreDispInfo.m_Power) - v55;
                  break;
                default:
                  v57 = -1;
                  break;
              }
              BlendVectorFieldData(
                pDisp1,
                ndxSrc1: (CMapFace *)v51,
                ndxDst1: v57,
                pDisp2: pDisp1,
                ndxSrc2: (CMapFace *)v54,
                ndxDst2: v57,
                blendFactor: (float)v62++ * v69);
              ++v55;
            }
            while ( v55 < v76 );
          }
          v76 += v72;
          pDisp2a = (CMapDisp *)((char *)pDisp2a + v72);
        }
        while ( (int)pDisp2a < blendFactora );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026020
// Name: void SewEdge_ResolveDispNormal(struct SewEdgeData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_ResolveDispNormal(CMapDisp *pEdgeData)
{
  int v2; // ebx
  int v3; // edi
  CEditDispMgr *v4; // eax
  int v5; // ebx
  CEditDispMgr *v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // esi
  int m_Power; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // esi
  int v27; // eax
  float v28; // xmm0_4
  int v29; // ecx
  int v30; // eax
  float v31; // [esp+10h] [ebp-20h]
  int v32; // [esp+14h] [ebp-1Ch]
  int v33; // [esp+18h] [ebp-18h]
  int blendRatio; // [esp+1Ch] [ebp-14h]
  int blendRatioa; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+20h] [ebp-10h]
  int v37; // [esp+24h] [ebp-Ch]
  int i; // [esp+24h] [ebp-Ch]
  int ndxLg; // [esp+28h] [ebp-8h]
  int ratio; // [esp+2Ch] [ebp-4h]
  int ratioa; // [esp+2Ch] [ebp-4h]
  CMapDisp *pSmDisp; // [esp+38h] [ebp+8h]

  v2 = *(unsigned __int16 *)(pEdgeData->m_nObjectID + 420);
  v3 = LOWORD(pEdgeData->m_pParent[21].__vftable);
  if ( (_WORD)v2 != 0xFFFF && (_WORD)v3 != 0xFFFF )
  {
    v4 = EditDispMgr();
    v5 = (int)v4->GetDisp(this: v4, a2: v2);
    v6 = EditDispMgr();
    v7 = (int)v6->GetDisp(this: v6, a2: v3);
    v8 = (1 << *(_DWORD *)(v5 + 36)) + 1;
    if ( v8 <= (1 << *(_DWORD *)(v7 + 36)) + 1 )
    {
      pSmDisp = (CMapDisp *)v7;
      v37 = *(_DWORD *)&pEdgeData->r;
      v9 = (1 << *(_DWORD *)(v5 + 36)) + 1;
      ratio = v5;
      ndxLg = *(_DWORD *)&pEdgeData->m_EditHandle;
      v8 = (1 << *(_DWORD *)(v7 + 36)) + 1;
    }
    else
    {
      ratio = v7;
      v9 = (1 << *(_DWORD *)(v7 + 36)) + 1;
      v37 = *(_DWORD *)&pEdgeData->m_EditHandle;
      pSmDisp = (CMapDisp *)v5;
      ndxLg = *(_DWORD *)&pEdgeData->r;
    }
    v10 = v8 - 1;
    v11 = (v8 - 1) / (v9 - 1);
    v12 = 1;
    v33 = v8 - 1;
    blendRatio = v9 - 1;
    v36 = v11;
    v13 = v11;
    if ( blendRatio > 1 )
    {
      do
      {
        v14 = (1 << *(_DWORD *)(ratio + 36)) + 1;
        switch ( v37 )
        {
          case 0:
            v15 = v12 * v14;
            break;
          case 1:
            v15 = v12 + v14 * (v14 - 1);
            break;
          case 2:
            v15 = v14 * (v14 - v12) - 1;
            break;
          case 3:
            v15 = (1 << *(_DWORD *)(ratio + 36)) - v12;
            break;
          default:
            v15 = -1;
            break;
        }
        v16 = (1 << pSmDisp->m_CoreDispInfo.m_Power) + 1;
        switch ( ndxLg )
        {
          case 0:
            v17 = v16 * (v16 - 1) - v13 * v16;
            break;
          case 1:
            v17 = v16 * v16 - v13 - 1;
            break;
          case 2:
            v17 = v13 * v16 + v16 - 1;
            break;
          case 3:
            v17 = v13;
            break;
          default:
            v17 = -1;
            break;
        }
        AverageVectorFieldData(pDisp1: (CMapFace *)ratio, ndx1: v15, pDisp2: pSmDisp, ndx2: v17);
        v13 += v36;
        ++v12;
      }
      while ( v12 < blendRatio );
      v11 = v36;
      v10 = v33;
    }
    v18 = 0;
    v31 = 1.0 / (float)v11;
    blendRatioa = 0;
    if ( v10 > 0 )
    {
      v19 = v11;
      ratioa = v11;
      v32 = 1 - v11;
      while ( 1 )
      {
        m_Power = pSmDisp->m_CoreDispInfo.m_Power;
        v21 = (1 << m_Power) + 1;
        switch ( ndxLg )
        {
          case 0:
            v22 = v18 * v21;
            break;
          case 1:
            v22 = v18 + ((1 << m_Power) + 1) * (1 << m_Power);
            break;
          case 2:
            v22 = v21 * (v21 - v18) - 1;
            break;
          case 3:
            v22 = (1 << m_Power) - v18;
            break;
          default:
            v22 = -1;
            break;
        }
        v23 = pSmDisp->m_CoreDispInfo.m_Power;
        v24 = (1 << v23) + 1;
        switch ( ndxLg )
        {
          case 0:
            v25 = v24 * v19;
            break;
          case 1:
            v25 = v19 + ((1 << v23) + 1) * (1 << v23);
            break;
          case 2:
            v25 = v24 * (v24 - v19) - 1;
            break;
          case 3:
            v25 = (1 << v23) - v19;
            break;
          default:
            v25 = -1;
            break;
        }
        v26 = v32 + v19;
        if ( v26 < ratioa )
        {
          v27 = v26 - v18;
          for ( i = v26 - v18; ; v27 = i )
          {
            v28 = (float)v27 * v31;
            v29 = (1 << pSmDisp->m_CoreDispInfo.m_Power) + 1;
            switch ( ndxLg )
            {
              case 0:
                v30 = v26 * v29;
                break;
              case 1:
                v30 = v26 + v29 * (v29 - 1);
                break;
              case 2:
                v30 = v29 * (v29 - v26) - 1;
                break;
              case 3:
                v30 = (1 << pSmDisp->m_CoreDispInfo.m_Power) - v26;
                break;
              default:
                v30 = -1;
                break;
            }
            BlendVectorFieldData(
              pDisp1: pSmDisp,
              ndxSrc1: (CMapFace *)v22,
              ndxDst1: v30,
              pDisp2: pSmDisp,
              ndxSrc2: (CMapFace *)v25,
              ndxDst2: v30,
              blendFactor: v28);
            ++i;
            if ( ++v26 >= ratioa )
              break;
          }
          v18 = blendRatioa;
        }
        ratioa += v36;
        v18 += v36;
        blendRatioa = v18;
        if ( v18 >= v33 )
          break;
        v19 = ratioa;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026340
// Name: void Faces_Update(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Faces_Update()
{
  CFaceEditSheet *m_pFaceEditSheet; // ebx
  int v1; // edi
  CMapFace *pMapFace; // eax
  int m_DispHandle; // esi
  CEditDispMgr *v4; // eax
  CMapDisp *v5; // eax
  int m_Size; // [esp+4h] [ebp-4h]

  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr && m_pFaceEditSheet->m_Faces.m_Size > 0 )
  {
    v1 = 0;
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    do
    {
      pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v1].pMapFace;
      if ( pMapFace != nullptr )
      {
        m_DispHandle = pMapFace->m_DispHandle;
        if ( (_WORD)m_DispHandle != 0xFFFF )
        {
          v4 = EditDispMgr();
          v5 = v4->GetDisp(this: v4, a2: m_DispHandle);
          CMapDisp::UpdateData(this: v5);
        }
      }
      ++v1;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100263C0
// Name: void SewCorner_Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewCorner_Resolve()
{
  int v0; // ecx
  SewCornerData_t *v1; // esi
  int v2; // eax
  CMapFace **pFaces; // ecx
  int cornerCount; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v0 = 0;
  cornerCount = s_CornerData.m_Size;
  for ( i = 0; v0 < cornerCount; i = v0 )
  {
    v1 = s_CornerData.m_Memory.m_pMemory[v0];
    if ( v1 != nullptr )
    {
      v2 = 0;
      if ( v1->faceCount <= 0 )
      {
LABEL_7:
        SewCorner_ResolveDisp(pCornerData: v1);
      }
      else
      {
        pFaces = v1->pFaces;
        while ( (*pFaces)->m_DispHandle != 0xFFFF )
        {
          ++v2;
          ++pFaces;
          if ( v2 >= v1->faceCount )
            goto LABEL_7;
        }
        SewCorner_ResolveSolid(pCornerData: v1);
      }
    }
    v0 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026440
// Name: void SewTJunc_Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewTJunc_Resolve()
{
  int v0; // ecx
  SewTJuncData_t *v1; // esi
  int v2; // eax
  CMapFace **pFaces; // ecx
  int tjCount; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v0 = 0;
  tjCount = s_TJData.m_Size;
  for ( i = 0; v0 < tjCount; i = v0 )
  {
    v1 = s_TJData.m_Memory.m_pMemory[v0];
    if ( v1 != nullptr )
    {
      v2 = 0;
      if ( v1->faceCount <= 0 )
      {
LABEL_7:
        SewTJunc_ResolveDisp(pTJData: v1);
      }
      else
      {
        pFaces = v1->pFaces;
        while ( (*pFaces)->m_DispHandle != 0xFFFF )
        {
          ++v2;
          ++pFaces;
          if ( v2 >= v1->faceCount )
            goto LABEL_7;
        }
        SewTJunc_ResolveSolid(pTJData: v1);
      }
    }
    v0 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100264C0
// Name: void SewEdge_Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_Resolve()
{
  int v0; // ecx
  SewEdgeData_t *v1; // edi
  int *type; // edx
  int v3; // eax
  CMapFace **v4; // ecx
  int faceCount; // eax
  int v6; // ecx
  int *v7; // esi
  int v8; // ecx
  int *v9; // esi
  int v10; // ebx
  int v11; // ecx
  int v12; // esi
  int v13; // edx
  CMapFace **pFaces; // ecx
  int edgeCount; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int ndxTJ; // [esp+8h] [ebp-Ch]
  int ndxTJEnd; // [esp+Ch] [ebp-8h]
  int ndxTJStart; // [esp+10h] [ebp-4h]

  v0 = 0;
  edgeCount = s_EdgeData.m_Size;
  for ( i = 0; v0 < edgeCount; i = v0 )
  {
    v1 = s_EdgeData.m_Memory.m_pMemory[v0];
    if ( v1 != nullptr )
    {
      type = v1->type;
      if ( v1->type[0] != 0 )
      {
        faceCount = v1->faceCount;
        v6 = 0;
        if ( v1->faceCount <= 0 )
        {
LABEL_14:
          ndxTJ = -1;
        }
        else
        {
          v7 = v1->type;
          while ( *v7 != 3 )
          {
            ++v6;
            ++v7;
            if ( v6 >= faceCount )
              goto LABEL_14;
          }
          ndxTJ = v6;
        }
        v8 = 0;
        if ( faceCount <= 0 )
        {
LABEL_19:
          v10 = -1;
          ndxTJStart = -1;
        }
        else
        {
          v9 = v1->type;
          while ( *v9 != 1 )
          {
            ++v8;
            ++v9;
            if ( v8 >= faceCount )
              goto LABEL_19;
          }
          v10 = v8;
          ndxTJStart = v8;
        }
        v11 = 0;
        if ( faceCount <= 0 )
        {
LABEL_23:
          v12 = -1;
          ndxTJEnd = -1;
        }
        else
        {
          while ( *type != 2 )
          {
            ++v11;
            ++type;
            if ( v11 >= faceCount )
              goto LABEL_23;
          }
          v12 = v11;
          ndxTJEnd = v11;
        }
        v13 = 0;
        if ( faceCount <= 0 )
        {
LABEL_30:
          if ( v10 != -1 )
          {
            if ( SewEdge_IsSolidTJunc(pEdgeData: v1, type: (CMapFace *)1) != 0 )
              SewEdge_ResolveSolidTJunc(pEdgeData: v1, type: 3, bStart: true);
            else
              SewEdge_ResolveDispTJunc(pEdgeData: v1, ndxTJ, ndxTJNeighbor: v10, bStart: true);
          }
          if ( v12 != -1 )
          {
            if ( SewEdge_IsSolidTJunc(pEdgeData: v1, type: (CMapFace *)2) != 0 )
              SewEdge_ResolveSolidTJunc(pEdgeData: v1, type: 3, bStart: false);
            else
              SewEdge_ResolveDispTJunc(pEdgeData: v1, ndxTJ, ndxTJNeighbor: v12, bStart: false);
          }
        }
        else
        {
          pFaces = v1->pFaces;
          while ( pFaces[6] != (CMapFace *)3 || (*pFaces)->m_DispHandle != 0xFFFF )
          {
            ++v13;
            ++pFaces;
            if ( v13 >= faceCount )
            {
              v12 = ndxTJEnd;
              v10 = ndxTJStart;
              goto LABEL_30;
            }
          }
          if ( ndxTJStart != -1 )
            SewEdge_ResolveSolidTJunc(pEdgeData: v1, type: 1, bStart: false);
          if ( ndxTJEnd != -1 )
            SewEdge_ResolveSolidTJunc(pEdgeData: v1, type: 2, bStart: false);
        }
      }
      else
      {
        v3 = 0;
        if ( v1->faceCount <= 0 )
        {
LABEL_8:
          SewEdge_ResolveDispNormal(pEdgeData: (CMapDisp *)v1);
        }
        else
        {
          v4 = v1->pFaces;
          while ( (*v4)->m_DispHandle != 0xFFFF )
          {
            ++v3;
            ++v4;
            if ( v3 >= v1->faceCount )
              goto LABEL_8;
          }
          SewEdge_ResolveSolidNormal(pEdgeData: v1);
        }
      }
    }
    v0 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026690
// Name: bool FindEnclosingTri(class Vector2D const __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &,int __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEnclosingTri(
        const Vector2D *vert,
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vertCoords,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *indices,
        int *pStartVert,
        float *bcCoords)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v5; // eax
  int v6; // esi
  Vector2D *m_pMemory; // ebx
  unsigned __int16 *v8; // eax
  int v9; // edx
  int v10; // esi
  float x; // xmm3_4
  float y; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float *p_x; // edx
  float *v16; // esi
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  Vector2D *v23; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v5 = indices;
  v6 = 0;
  i = 0;
  if ( indices->m_Size <= 0 )
    return 0;
  m_pMemory = vertCoords->m_Memory.m_pMemory;
  v23 = vertCoords->m_Memory.m_pMemory;
  while ( 1 )
  {
    v8 = v5->m_Memory.m_pMemory;
    v9 = v8[v6 + 2];
    v10 = v8[v6 + 1];
    x = m_pMemory[v10].x;
    y = m_pMemory[v9].y;
    v13 = m_pMemory[v10].y;
    v14 = m_pMemory[v9].x;
    p_x = &m_pMemory[v9].x;
    v16 = &m_pMemory[v10].x;
    m_pMemory = v23;
    v17 = &v23[v8[i]].x;
    v18 = 1.0
        / (float)((float)((float)(x - *v17) * (float)(y - v17[1])) - (float)((float)(v14 - *v17) * (float)(v13 - v17[1])));
    *bcCoords = (float)((float)((float)(v14 - x) * (float)(vert->y - v13))
                      - (float)((float)(y - v13) * (float)(vert->x - x)))
              * v18;
    v19 = (float)((float)((float)(*v17 - *p_x) * (float)(vert->y - p_x[1]))
                - (float)((float)(vert->x - *p_x) * (float)(v17[1] - p_x[1])))
        * v18;
    bcCoords[1] = v19;
    v20 = *bcCoords;
    v21 = (float)((float)((float)(*v16 - *v17) * (float)(vert->y - v17[1]))
                - (float)((float)(v16[1] - v17[1]) * (float)(vert->x - *v17)))
        * v18;
    bcCoords[2] = v21;
    if ( v20 >= 0.0 && v20 <= 1.0 && v19 >= 0.0 && v19 <= 1.0 && v21 >= 0.0 && v21 <= 1.0 )
      break;
    v5 = indices;
    v6 = i + 3;
    i = v6;
    if ( v6 >= indices->m_Size )
      return 0;
  }
  *pStartVert = i;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026A50
// Name: void PostFaceListSew(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostFaceListSew()
{
  int v0; // esi
  int i; // edi
  int v2; // esi
  int j; // edi
  int v4; // esi
  int k; // edi
  SewCornerData_t **m_pMemory; // eax
  SewTJuncData_t **v7; // eax
  SewEdgeData_t **v8; // eax

  v0 = 0;
  for ( i = s_CornerData.m_Size; v0 < i; ++v0 )
  {
    if ( s_CornerData.m_Memory.m_pMemory[v0] != nullptr )
      operator delete(p: s_CornerData.m_Memory.m_pMemory[v0]);
  }
  v2 = 0;
  for ( j = s_TJData.m_Size; v2 < j; ++v2 )
  {
    if ( s_TJData.m_Memory.m_pMemory[v2] != nullptr )
      operator delete(p: s_TJData.m_Memory.m_pMemory[v2]);
  }
  v4 = 0;
  for ( k = s_EdgeData.m_Size; v4 < k; ++v4 )
  {
    if ( s_EdgeData.m_Memory.m_pMemory[v4] != nullptr )
      operator delete(p: s_EdgeData.m_Memory.m_pMemory[v4]);
  }
  m_pMemory = s_CornerData.m_Memory.m_pMemory;
  s_CornerData.m_Size = 0;
  if ( s_CornerData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_CornerData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_CornerData.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_CornerData.m_Memory.m_pMemory = nullptr;
    }
    s_CornerData.m_Memory.m_nAllocationCount = 0;
  }
  s_CornerData.m_pElements = m_pMemory;
  v7 = s_TJData.m_Memory.m_pMemory;
  s_TJData.m_Size = 0;
  if ( s_TJData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_TJData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_TJData.m_Memory.m_pMemory);
      v7 = nullptr;
      s_TJData.m_Memory.m_pMemory = nullptr;
    }
    s_TJData.m_Memory.m_nAllocationCount = 0;
  }
  s_TJData.m_pElements = v7;
  v8 = s_EdgeData.m_Memory.m_pMemory;
  s_EdgeData.m_Size = 0;
  if ( s_EdgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_EdgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_EdgeData.m_Memory.m_pMemory);
      v8 = nullptr;
      s_EdgeData.m_Memory.m_pMemory = nullptr;
    }
    s_EdgeData.m_Memory.m_nAllocationCount = 0;
  }
  s_EdgeData.m_pElements = v8;
  Faces_Update();
}

//------------------------------------------------------------------------------
// Address: 0x10026B80
// Name: bool PrePlanarizeDependentVerts(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PrePlanarizeDependentVerts()
{
  CFaceEditSheet *m_pFaceEditSheet; // ecx
  int v2; // ebx
  CMapFace *pMapFace; // esi
  CEditDispMgr *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int i; // esi
  CFaceEditSheet *pSheet; // [esp+0h] [ebp-8h]
  int m_Size; // [esp+4h] [ebp-4h]

  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet == nullptr )
    return 0;
  if ( m_pFaceEditSheet->m_Faces.m_Size > 0 )
  {
    v2 = 0;
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    do
    {
      pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v2].pMapFace;
      if ( pMapFace != nullptr && pMapFace->m_DispHandle != 0xFFFF )
      {
        v4 = EditDispMgr();
        v5 = (int)v4->GetDisp(this: v4, a2: pMapFace->m_DispHandle);
        v6 = m_aCoreDispInfos.m_Size;
        v7 = m_aCoreDispInfos.m_Size;
        if ( m_aCoreDispInfos.m_Size + 1 > m_aCoreDispInfos.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&m_aCoreDispInfos,
            num: m_aCoreDispInfos.m_Size - m_aCoreDispInfos.m_Memory.m_nAllocationCount + 1);
          v6 = m_aCoreDispInfos.m_Size;
        }
        m_aCoreDispInfos.m_Size = v6 + 1;
        v8 = v6 - v7;
        m_aCoreDispInfos.m_pElements = m_aCoreDispInfos.m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(
            dest: &m_aCoreDispInfos.m_Memory.m_pMemory[v7 + 1],
            src: &m_aCoreDispInfos.m_Memory.m_pMemory[v7],
            count: 4 * v8);
        *(_DWORD *)(v5 + 864) = v7;
        m_aCoreDispInfos.m_Memory.m_pMemory[v7] = (CCoreDispInfo *)(v5 + 24);
        m_pFaceEditSheet = pSheet;
      }
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  v9 = m_aCoreDispInfos.m_Size;
  for ( i = 0; i < m_aCoreDispInfos.m_Size; ++i )
  {
    CCoreDispInfo::SetDispUtilsHelperInfo(
      this: m_aCoreDispInfos.m_Memory.m_pMemory[i],
      ppListBase: m_aCoreDispInfos.m_Memory.m_pMemory,
      listSize: v9);
    v9 = m_aCoreDispInfos.m_Size;
  }
  FindNeighboringDispSurfs(ppListBase: m_aCoreDispInfos.m_Memory.m_pMemory, nListSize: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026CB0
// Name: void SewCorner_AddToList(struct SewCornerData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewCorner_AddToList(SewCornerData_t *pCornerData)
{
  int v1; // esi
  CMapFace *v2; // eax
  int m_DispHandle; // edi
  CEditDispMgr *v4; // eax
  int v5; // eax
  float v6; // xmm0_4
  int m_Size; // eax
  int v8; // ebx
  SewCornerData_t *v9; // eax
  int v10; // esi
  CMapFace *v11; // eax
  int v12; // edi
  CEditDispMgr *v13; // eax
  int v14; // eax
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  Vector *Points; // eax
  float x; // xmm2_4
  int v20; // eax
  int v21; // esi
  int v22; // eax
  SewCornerData_t **v23; // eax
  Vector cmpPt; // [esp+Ch] [ebp-1Ch]
  Vector pt; // [esp+18h] [ebp-10h]
  int cornerCount; // [esp+24h] [ebp-4h]

  v1 = pCornerData->ndxCorners[0];
  v2 = pCornerData->pFaces[0];
  m_DispHandle = v2->m_DispHandle;
  if ( (_WORD)m_DispHandle == 0xFFFF )
  {
    v5 = (int)&v2->Points[v1];
  }
  else
  {
    v4 = EditDispMgr();
    v5 = (int)&v4->GetDisp(this: v4, a2: m_DispHandle)->m_CoreDispInfo.m_Surf.m_Points[v1];
  }
  pt.x = *(float *)v5;
  pt.y = *(float *)(v5 + 4);
  v6 = *(float *)(v5 + 8);
  m_Size = s_CornerData.m_Size;
  v8 = 0;
  pt.z = v6;
  cornerCount = s_CornerData.m_Size;
  if ( s_CornerData.m_Size > 0 )
  {
    do
    {
      v9 = s_CornerData.m_Memory.m_pMemory[v8];
      if ( v9 != nullptr )
      {
        v10 = v9->ndxCorners[0];
        v11 = v9->pFaces[0];
        v12 = v11->m_DispHandle;
        if ( (_WORD)v12 == 0xFFFF )
        {
          Points = v11->Points;
          x = Points[v10].x;
          v17 = (int)&Points[v10];
          cmpPt.x = x;
        }
        else
        {
          v13 = EditDispMgr();
          v14 = (int)v13->GetDisp(this: v13, a2: v12);
          v15 = 3 * v10 + 12;
          v16 = *(float *)(v14 + 4 * v15);
          v17 = v14 + 4 * v15;
          cmpPt.x = v16;
        }
        cmpPt.y = *(float *)(v17 + 4);
        cmpPt.z = *(float *)(v17 + 8);
        v20 = 0;
        while ( fabs(*(float *)((char *)&pt.x + v20) - *(float *)((char *)&cmpPt.x + v20)) <= 1.0 )
        {
          v20 += 4;
          if ( v20 >= 12 )
          {
            operator delete(p: pCornerData);
            return;
          }
        }
      }
      ++v8;
    }
    while ( v8 < cornerCount );
    m_Size = s_CornerData.m_Size;
  }
  v21 = m_Size;
  if ( m_Size + 1 > s_CornerData.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&s_CornerData,
      num: m_Size - s_CornerData.m_Memory.m_nAllocationCount + 1);
    m_Size = s_CornerData.m_Size;
  }
  s_CornerData.m_Size = m_Size + 1;
  v22 = m_Size - v21;
  s_CornerData.m_pElements = s_CornerData.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(
      dest: &s_CornerData.m_Memory.m_pMemory[v21 + 1],
      src: &s_CornerData.m_Memory.m_pMemory[v21],
      count: 4 * v22);
  v23 = &s_CornerData.m_Memory.m_pMemory[v21];
  if ( v23 != nullptr )
    *v23 = pCornerData;
}

//------------------------------------------------------------------------------
// Address: 0x10026E90
// Name: void SewCorner_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewCorner_Build()
{
  CFaceEditSheet *m_pFaceEditSheet; // eax
  int v1; // ebx
  int m_Size; // edx
  CMapFace *pMapFace; // edi
  int m_DispHandle; // esi
  CEditDispMgr *v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  Vector *Points; // eax
  SewCornerData_t *v11; // eax
  SewCornerData_t *v12; // esi
  int v13; // ecx
  CMapFace *v14; // ebx
  int v15; // edi
  CEditDispMgr *v16; // eax
  int v17; // eax
  Vector *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // edx
  Vector pt2; // [esp+4h] [ebp-4Ch]
  Vector pt; // [esp+10h] [ebp-40h]
  int ptCount; // [esp+1Ch] [ebp-34h]
  CMapFace *pFace; // [esp+20h] [ebp-30h]
  int ptCount2; // [esp+24h] [ebp-2Ch]
  int faceCount; // [esp+28h] [ebp-28h]
  CFaceEditSheet *pSheet; // [esp+2Ch] [ebp-24h]
  int v29; // [esp+30h] [ebp-20h]
  int ndxFace2; // [esp+34h] [ebp-1Ch]
  unsigned int v31; // [esp+38h] [ebp-18h]
  int ndxFace; // [esp+3Ch] [ebp-14h]
  unsigned int v33; // [esp+40h] [ebp-10h]
  int ndxPt2; // [esp+44h] [ebp-Ch]
  int ndxPt; // [esp+48h] [ebp-8h]
  unsigned int v36; // [esp+4Ch] [ebp-4h]

  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  v1 = 0;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr )
  {
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    faceCount = m_Size;
    ndxFace = 0;
    if ( m_Size > 0 )
    {
      v31 = 0;
      while ( 1 )
      {
        pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v31 / 0xC].pMapFace;
        pFace = pMapFace;
        if ( pMapFace != nullptr )
        {
          ptCount = pMapFace->nPoints;
          ndxPt = 0;
          if ( ptCount > 0 )
            break;
        }
LABEL_36:
        v31 += 12;
        if ( ++ndxFace >= m_Size )
          return;
      }
      v29 = 0;
      while ( 1 )
      {
        m_DispHandle = pMapFace->m_DispHandle;
        if ( (_WORD)m_DispHandle == 0xFFFF )
        {
          Points = pMapFace->Points;
          pt.x = *(float *)((char *)&Points->x + v1);
          pt.y = *(float *)((char *)&Points->y + v1);
          v9 = *(float *)((char *)&Points->z + v1);
        }
        else
        {
          v5 = EditDispMgr();
          v6 = (int)v5->GetDisp(this: v5, a2: m_DispHandle);
          v7 = *(float *)(v6 + v1 + 48);
          v8 = v6 + v1 + 48;
          pt.x = v7;
          pt.y = *(float *)(v8 + 4);
          v9 = *(float *)(v8 + 8);
        }
        pt.z = v9;
        v11 = (SewCornerData_t *)operator new(nSize: 0x84u);
        v12 = v11;
        v13 = 0;
        if ( v11 == nullptr )
          break;
        v11->faceCount = 0;
        ndxFace2 = 0;
        v33 = 0;
        do
        {
          if ( ndxFace != v13 )
          {
            v14 = pSheet->m_Faces.m_Memory.m_pMemory[v33 / 0xC].pMapFace;
            if ( v14 != nullptr )
            {
              ptCount2 = v14->nPoints;
              ndxPt2 = 0;
              if ( ptCount2 > 0 )
              {
                v36 = 0;
                do
                {
                  v15 = v14->m_DispHandle;
                  if ( (_WORD)v15 == 0xFFFF )
                  {
                    v18 = &v14->Points[v36 / 0xC];
                  }
                  else
                  {
                    v16 = EditDispMgr();
                    v17 = (int)v16->GetDisp(this: v16, a2: v15);
                    v18 = (Vector *)(v17 + v36 + 48);
                  }
                  pt2 = *v18;
                  v19 = 0;
                  while ( COERCE_FLOAT(
                            COERCE_UNSIGNED_INT(*(float *)((char *)&pt.x + v19) - *(float *)((char *)&pt2.x + v19))
                          & _mask__AbsFloat_) <= 1.0 )
                  {
                    v19 += 4;
                    if ( v19 >= 12 )
                    {
                      if ( v12->faceCount < 16 )
                      {
                        v12->pFaces[v12->faceCount] = v14;
                        v12->ndxCorners[v12->faceCount++] = ndxPt2;
                      }
                      else
                      {
                        AfxMessageBox(
                          lpszText: "Warning: Too many displacement faces at corner!\n",
                          nType: 0,
                          nIDHelp: 0);
                      }
                      break;
                    }
                  }
                  v36 += 12;
                  ++ndxPt2;
                }
                while ( ndxPt2 < ptCount2 );
                pMapFace = pFace;
                v13 = ndxFace2;
              }
            }
          }
          v33 += 12;
          ndxFace2 = ++v13;
        }
        while ( v13 < faceCount );
        v20 = v12->faceCount;
        if ( v12->faceCount <= 0 )
        {
          operator delete(p: v12);
        }
        else
        {
          if ( v20 < 16 )
          {
            v21 = ndxPt;
            v12->pFaces[v20] = pMapFace;
            v12->ndxCorners[v12->faceCount++] = v21;
          }
          else
          {
            AfxMessageBox(lpszText: "Warning: Too many displacement faces at corner!\n", nType: 0, nIDHelp: 0);
          }
          SewCorner_AddToList(pCornerData: v12);
        }
        ++ndxPt;
        v1 = v29 + 12;
        v29 += 12;
        if ( ndxPt >= ptCount )
        {
          m_pFaceEditSheet = pSheet;
          m_Size = faceCount;
          v1 = 0;
          goto LABEL_36;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027120
// Name: void SewTJunc_AddToList(struct SewTJuncData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewTJunc_AddToList(SewTJuncData_t *pTJData)
{
  int v1; // esi
  CMapFace *v2; // eax
  int m_DispHandle; // edi
  CEditDispMgr *v4; // eax
  int v5; // eax
  float v6; // xmm0_4
  int m_Size; // eax
  int v8; // ebx
  SewTJuncData_t *v9; // eax
  int v10; // esi
  CMapFace *v11; // eax
  int v12; // edi
  CEditDispMgr *v13; // eax
  int v14; // eax
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  Vector *Points; // eax
  float x; // xmm2_4
  int v20; // eax
  int v21; // esi
  int v22; // eax
  SewTJuncData_t **v23; // eax
  Vector cmpPt; // [esp+Ch] [ebp-1Ch]
  Vector pt; // [esp+18h] [ebp-10h]
  int tjCount; // [esp+24h] [ebp-4h]

  v1 = pTJData->ndxCorners[0];
  v2 = pTJData->pFaces[0];
  m_DispHandle = v2->m_DispHandle;
  if ( (_WORD)m_DispHandle == 0xFFFF )
  {
    v5 = (int)&v2->Points[v1];
  }
  else
  {
    v4 = EditDispMgr();
    v5 = (int)&v4->GetDisp(this: v4, a2: m_DispHandle)->m_CoreDispInfo.m_Surf.m_Points[v1];
  }
  pt.x = *(float *)v5;
  pt.y = *(float *)(v5 + 4);
  v6 = *(float *)(v5 + 8);
  m_Size = s_TJData.m_Size;
  v8 = 0;
  pt.z = v6;
  tjCount = s_TJData.m_Size;
  if ( s_TJData.m_Size > 0 )
  {
    do
    {
      v9 = s_TJData.m_Memory.m_pMemory[v8];
      if ( v9 != nullptr )
      {
        v10 = v9->ndxCorners[0];
        v11 = v9->pFaces[0];
        v12 = v11->m_DispHandle;
        if ( (_WORD)v12 == 0xFFFF )
        {
          Points = v11->Points;
          x = Points[v10].x;
          v17 = (int)&Points[v10];
          cmpPt.x = x;
        }
        else
        {
          v13 = EditDispMgr();
          v14 = (int)v13->GetDisp(this: v13, a2: v12);
          v15 = 3 * v10 + 12;
          v16 = *(float *)(v14 + 4 * v15);
          v17 = v14 + 4 * v15;
          cmpPt.x = v16;
        }
        cmpPt.y = *(float *)(v17 + 4);
        cmpPt.z = *(float *)(v17 + 8);
        v20 = 0;
        while ( fabs(*(float *)((char *)&pt.x + v20) - *(float *)((char *)&cmpPt.x + v20)) <= 1.0 )
        {
          v20 += 4;
          if ( v20 >= 12 )
          {
            operator delete(p: pTJData);
            return;
          }
        }
      }
      ++v8;
    }
    while ( v8 < tjCount );
    m_Size = s_TJData.m_Size;
  }
  v21 = m_Size;
  if ( m_Size + 1 > s_TJData.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&s_TJData,
      num: m_Size - s_TJData.m_Memory.m_nAllocationCount + 1);
    m_Size = s_TJData.m_Size;
  }
  s_TJData.m_Size = m_Size + 1;
  v22 = m_Size - v21;
  s_TJData.m_pElements = s_TJData.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &s_TJData.m_Memory.m_pMemory[v21 + 1], src: &s_TJData.m_Memory.m_pMemory[v21], count: 4 * v22);
  v23 = &s_TJData.m_Memory.m_pMemory[v21];
  if ( v23 != nullptr )
    *v23 = pTJData;
}

//------------------------------------------------------------------------------
// Address: 0x10027300
// Name: void SewTJunc_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewTJunc_Build()
{
  CFaceEditSheet *m_pFaceEditSheet; // eax
  int v1; // ebx
  int m_Size; // ecx
  CMapFace *pMapFace; // edi
  int m_DispHandle; // esi
  CEditDispMgr *v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  Vector *Points; // eax
  int v11; // ebx
  int v12; // esi
  CEditDispMgr *v13; // eax
  float *p_x; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  SewTJuncData_t *v17; // eax
  SewTJuncData_t *v18; // esi
  int v19; // ecx
  CMapFace *v20; // ebx
  int v21; // edi
  CEditDispMgr *v22; // eax
  int v23; // eax
  Vector *v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  Vector pt; // [esp+4h] [ebp-5Ch]
  Vector pt2; // [esp+10h] [ebp-50h]
  Vector tmpPt1; // [esp+1Ch] [ebp-44h]
  int v31; // [esp+28h] [ebp-38h]
  CMapFace *pFace; // [esp+2Ch] [ebp-34h]
  int ptCount2; // [esp+30h] [ebp-30h]
  int faceCount; // [esp+34h] [ebp-2Ch]
  CFaceEditSheet *pSheet; // [esp+38h] [ebp-28h]
  int ptCount; // [esp+3Ch] [ebp-24h]
  int ndxFace2; // [esp+40h] [ebp-20h]
  unsigned int v38; // [esp+44h] [ebp-1Ch]
  int ndxFace; // [esp+48h] [ebp-18h]
  int i; // [esp+4Ch] [ebp-14h]
  int ndxPt; // [esp+50h] [ebp-10h]
  unsigned int v42; // [esp+54h] [ebp-Ch]
  int ndxPt2; // [esp+58h] [ebp-8h]
  unsigned int v44; // [esp+5Ch] [ebp-4h]

  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  v1 = 0;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr )
  {
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    faceCount = m_Size;
    ndxFace = 0;
    if ( m_Size > 0 )
    {
      v38 = 0;
      while ( 1 )
      {
        pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v38 / 0xC].pMapFace;
        pFace = pMapFace;
        if ( pMapFace != nullptr )
        {
          ptCount = pMapFace->nPoints;
          ndxPt = 0;
          if ( ptCount > 0 )
            break;
        }
LABEL_40:
        v38 += 12;
        if ( ++ndxFace >= m_Size )
          return;
      }
      for ( i = 0; ; v1 = i )
      {
        m_DispHandle = pMapFace->m_DispHandle;
        if ( (_WORD)m_DispHandle == 0xFFFF )
        {
          Points = pMapFace->Points;
          tmpPt1.x = *(float *)((char *)&Points->x + v1);
          tmpPt1.y = *(float *)((char *)&Points->y + v1);
          v9 = *(float *)((char *)&Points->z + v1);
        }
        else
        {
          v5 = EditDispMgr();
          v6 = (int)v5->GetDisp(this: v5, a2: m_DispHandle);
          v7 = *(float *)(v6 + v1 + 48);
          v8 = v6 + v1 + 48;
          tmpPt1.x = v7;
          tmpPt1.y = *(float *)(v8 + 4);
          v9 = *(float *)(v8 + 8);
        }
        v31 = ndxPt + 1;
        v11 = pMapFace->m_DispHandle;
        tmpPt1.z = v9;
        v12 = (ndxPt + 1) % ptCount;
        if ( (_WORD)v11 == 0xFFFF )
        {
          p_x = &pMapFace->Points[v12].x;
        }
        else
        {
          v13 = EditDispMgr();
          p_x = &v13->GetDisp(this: v13, a2: v11)->m_CoreDispInfo.m_Surf.m_Points[v12].x;
        }
        v15 = (float)(p_x[1] + tmpPt1.y) * 0.5;
        v16 = (float)(p_x[2] + tmpPt1.z) * 0.5;
        pt.x = (float)(*p_x + tmpPt1.x) * 0.5;
        pt.y = v15;
        pt.z = v16;
        v17 = (SewTJuncData_t *)operator new(nSize: 0x64u);
        v18 = v17;
        if ( v17 == nullptr )
          break;
        v19 = 0;
        v17->faceCount = 0;
        ndxFace2 = 0;
        v42 = 0;
        do
        {
          if ( ndxFace != v19 )
          {
            v20 = pSheet->m_Faces.m_Memory.m_pMemory[v42 / 0xC].pMapFace;
            if ( v20 != nullptr )
            {
              ptCount2 = v20->nPoints;
              ndxPt2 = 0;
              if ( ptCount2 > 0 )
              {
                v44 = 0;
                do
                {
                  v21 = v20->m_DispHandle;
                  if ( (_WORD)v21 == 0xFFFF )
                  {
                    v24 = &v20->Points[v44 / 0xC];
                  }
                  else
                  {
                    v22 = EditDispMgr();
                    v23 = (int)v22->GetDisp(this: v22, a2: v21);
                    v24 = (Vector *)(v23 + v44 + 48);
                  }
                  pt2 = *v24;
                  v25 = 0;
                  while ( fabs(*(float *)((char *)&pt.x + v25) - *(float *)((char *)&pt2.x + v25)) <= 1.0 )
                  {
                    v25 += 4;
                    if ( v25 >= 12 )
                    {
                      if ( v18->faceCount < 8 )
                      {
                        v18->pFaces[v18->faceCount] = v20;
                        v18->ndxCorners[v18->faceCount] = ndxPt2;
                        v18->ndxEdges[v18->faceCount++] = -1;
                      }
                      else
                      {
                        AfxMessageBox(
                          lpszText: "Warning: Too many displacement faces at t-junction!\n",
                          nType: 0,
                          nIDHelp: 0);
                      }
                      break;
                    }
                  }
                  v44 += 12;
                  ++ndxPt2;
                }
                while ( ndxPt2 < ptCount2 );
                pMapFace = pFace;
                v19 = ndxFace2;
              }
            }
          }
          v42 += 12;
          ndxFace2 = ++v19;
        }
        while ( v19 < faceCount );
        v26 = v18->faceCount;
        if ( v18->faceCount <= 0 )
        {
          operator delete(p: v18);
        }
        else
        {
          if ( v26 < 8 )
          {
            v27 = ndxPt;
            v18->pFaces[v26] = pMapFace;
            v18->ndxCorners[v18->faceCount] = -1;
            v18->ndxEdges[v18->faceCount++] = v27;
          }
          else
          {
            AfxMessageBox(lpszText: "Warning: Too many displacement faces at t-junction!\n", nType: 0, nIDHelp: 0);
          }
          SewTJunc_AddToList(pTJData: v18);
        }
        i += 12;
        ndxPt = v31;
        if ( v31 >= ptCount )
        {
          m_pFaceEditSheet = pSheet;
          m_Size = faceCount;
          v1 = 0;
          goto LABEL_40;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027620
// Name: bool SewEdge_AddToListTJunc(struct SewEdgeData_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SewEdge_AddToListTJunc(SewEdgeData_t *pEdgeData)
{
  SewEdgeData_t *v1; // ecx
  int v2; // esi
  int *j; // edx
  CMapFace *v5; // eax
  int m_DispHandle; // ebx
  int v7; // edi
  CEditDispMgr *v8; // eax
  int v9; // eax
  float v10; // xmm0_4
  int v11; // edx
  CMapFace *v12; // eax
  int m_Size; // eax
  int v14; // edx
  SewEdgeData_t *v15; // edi
  int v16; // esi
  int *type; // eax
  CMapFace *v18; // eax
  int v19; // ecx
  int v20; // ebx
  CEditDispMgr *v21; // eax
  int v22; // eax
  float v23; // xmm0_4
  int v24; // edx
  CMapFace *v25; // eax
  int v26; // esi
  int v27; // ebx
  CEditDispMgr *v28; // eax
  Vector *v29; // eax
  int v30; // esi
  int v31; // eax
  SewEdgeData_t **v32; // eax
  bool v33; // bl
  Vector edgePts[2]; // [esp+4h] [ebp-40h] BYREF
  Vector edgePts2[2]; // [esp+1Ch] [ebp-28h] BYREF
  int edgeCount; // [esp+34h] [ebp-10h]
  int edgeType2; // [esp+38h] [ebp-Ch] BYREF
  int edgeType1; // [esp+3Ch] [ebp-8h] BYREF
  int i; // [esp+40h] [ebp-4h]

  v1 = pEdgeData;
  v2 = 0;
  if ( pEdgeData->faceCount > 0 )
  {
    for ( j = pEdgeData->type; *j != 3; ++j )
    {
      if ( ++v2 >= pEdgeData->faceCount )
        return 1;
    }
    if ( v2 != -1 )
    {
      v5 = pEdgeData->pFaces[v2];
      m_DispHandle = v5->m_DispHandle;
      i = v5->nPoints;
      v7 = pEdgeData->ndxEdges[v2];
      if ( (_WORD)m_DispHandle == 0xFFFF )
      {
        v9 = (int)&v5->Points[v7];
      }
      else
      {
        v8 = EditDispMgr();
        v9 = (int)&v8->GetDisp(this: v8, a2: m_DispHandle)->m_CoreDispInfo.m_Surf.m_Points[v7];
        v1 = pEdgeData;
      }
      edgePts[0].x = *(float *)v9;
      edgePts[0].y = *(float *)(v9 + 4);
      v10 = *(float *)(v9 + 8);
      v11 = (v1->ndxEdges[v2] + 1) % i;
      v12 = v1->pFaces[v2];
      edgePts[0].z = v10;
      GetPointFromSurface(pFace: v12, ndxPt: v11, pt: &edgePts[1]);
      m_Size = s_EdgeData.m_Size;
      v14 = 0;
      edgeCount = s_EdgeData.m_Size;
      i = 0;
      if ( s_EdgeData.m_Size > 0 )
      {
        while ( 1 )
        {
          v15 = s_EdgeData.m_Memory.m_pMemory[v14];
          if ( v15 != nullptr )
          {
            v16 = 0;
            if ( v15->faceCount > 0 )
            {
              type = v15->type;
              while ( *type != 3 )
              {
                ++v16;
                ++type;
                if ( v16 >= v15->faceCount )
                  goto LABEL_27;
              }
              if ( v16 != -1 )
              {
                v18 = v15->pFaces[v16];
                v19 = v18->m_DispHandle;
                v20 = v15->ndxEdges[v16];
                edgeType2 = v18->nPoints;
                edgeType1 = v19;
                if ( (_WORD)v19 == 0xFFFF )
                {
                  v22 = (int)&v18->Points[v20];
                }
                else
                {
                  v21 = EditDispMgr();
                  v22 = (int)&v21->GetDisp(this: v21, a2: edgeType1)->m_CoreDispInfo.m_Surf.m_Points[v20];
                }
                edgePts2[0].x = *(float *)v22;
                edgePts2[0].y = *(float *)(v22 + 4);
                v23 = *(float *)(v22 + 8);
                v24 = (v15->ndxEdges[v16] + 1) % edgeType2;
                v25 = v15->pFaces[v16];
                v26 = v25->m_DispHandle;
                edgePts2[0].z = v23;
                v27 = v24;
                if ( (_WORD)v26 == 0xFFFF )
                {
                  v29 = &v25->Points[v24];
                }
                else
                {
                  v28 = EditDispMgr();
                  v29 = &v28->GetDisp(this: v28, a2: v26)->m_CoreDispInfo.m_Surf.m_Points[v27];
                }
                edgePts2[1] = *v29;
                if ( EdgeCompare(pEdgePts1: edgePts, pEdgePts2: edgePts2, &edgeType1, &edgeType2) != 0 )
                {
                  v33 = SewEdge_AddToListMerge(pEdgeData, pCmpData: v15);
                  operator delete(p: pEdgeData);
                  return v33;
                }
                v14 = i;
              }
            }
          }
LABEL_27:
          i = ++v14;
          if ( v14 >= edgeCount )
          {
            m_Size = s_EdgeData.m_Size;
            break;
          }
        }
      }
      v30 = m_Size;
      if ( m_Size + 1 > s_EdgeData.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&s_EdgeData,
          num: m_Size - s_EdgeData.m_Memory.m_nAllocationCount + 1);
        m_Size = s_EdgeData.m_Size;
      }
      s_EdgeData.m_Size = m_Size + 1;
      v31 = m_Size - v30;
      s_EdgeData.m_pElements = s_EdgeData.m_Memory.m_pMemory;
      if ( v31 > 0 )
        _V_memmove(
          dest: &s_EdgeData.m_Memory.m_pMemory[v30 + 1],
          src: &s_EdgeData.m_Memory.m_pMemory[v30],
          count: 4 * v31);
      v32 = &s_EdgeData.m_Memory.m_pMemory[v30];
      if ( v32 != nullptr )
        *v32 = pEdgeData;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100278C0
// Name: void SewEdge_AddToListNormal(struct SewEdgeData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_AddToListNormal(SewEdgeData_t *pEdgeData)
{
  SewEdgeData_t *v1; // ecx
  CMapFace *v2; // eax
  int nPoints; // ebx
  int v4; // esi
  int m_DispHandle; // edi
  CEditDispMgr *v6; // eax
  int v7; // eax
  float v8; // xmm0_4
  int v9; // edx
  CMapFace *v10; // eax
  int v11; // edi
  int v12; // esi
  CEditDispMgr *v13; // eax
  int v14; // eax
  float v15; // xmm0_4
  int m_Size; // eax
  int v17; // ecx
  SewEdgeData_t *v18; // esi
  bool v19; // cc
  CMapFace **pFaces; // esi
  CMapFace *v21; // eax
  int v22; // ebx
  CMapFace *v23; // edi
  CEditDispMgr *v24; // eax
  int v25; // eax
  float v26; // xmm0_4
  int v27; // edx
  CMapFace *v28; // eax
  int v29; // ebx
  int v30; // edi
  CEditDispMgr *v31; // eax
  Vector *v32; // eax
  int v33; // esi
  int v34; // eax
  SewEdgeData_t **v35; // eax
  Vector edgePts[2]; // [esp+Ch] [ebp-48h] BYREF
  Vector edgePts2[2]; // [esp+24h] [ebp-30h] BYREF
  int edgeType1; // [esp+3Ch] [ebp-18h] BYREF
  int edgeCount; // [esp+40h] [ebp-14h]
  SewEdgeData_t *pCmpData; // [esp+44h] [ebp-10h]
  int edgeType2; // [esp+48h] [ebp-Ch] BYREF
  int i; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h]

  v1 = pEdgeData;
  v2 = pEdgeData->pFaces[0];
  nPoints = v2->nPoints;
  v4 = pEdgeData->ndxEdges[0];
  m_DispHandle = v2->m_DispHandle;
  if ( (_WORD)m_DispHandle == 0xFFFF )
  {
    v7 = (int)&v2->Points[v4];
  }
  else
  {
    v6 = EditDispMgr();
    v7 = (int)&v6->GetDisp(this: v6, a2: m_DispHandle)->m_CoreDispInfo.m_Surf.m_Points[v4];
    v1 = pEdgeData;
  }
  edgePts[0].x = *(float *)v7;
  edgePts[0].y = *(float *)(v7 + 4);
  v8 = *(float *)(v7 + 8);
  v9 = (v1->ndxEdges[0] + 1) % nPoints;
  v10 = v1->pFaces[0];
  v11 = v10->m_DispHandle;
  edgePts[0].z = v8;
  v12 = v9;
  if ( (_WORD)v11 == 0xFFFF )
  {
    v14 = (int)&v10->Points[v9];
  }
  else
  {
    v13 = EditDispMgr();
    v14 = (int)&v13->GetDisp(this: v13, a2: v11)->m_CoreDispInfo.m_Surf.m_Points[v12];
  }
  edgePts[1].x = *(float *)v14;
  edgePts[1].y = *(float *)(v14 + 4);
  v15 = *(float *)(v14 + 8);
  m_Size = s_EdgeData.m_Size;
  v17 = 0;
  edgePts[1].z = v15;
  edgeCount = s_EdgeData.m_Size;
  i = 0;
  if ( s_EdgeData.m_Size <= 0 )
  {
LABEL_22:
    v33 = m_Size;
    if ( m_Size + 1 > s_EdgeData.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&s_EdgeData,
        num: m_Size - s_EdgeData.m_Memory.m_nAllocationCount + 1);
      m_Size = s_EdgeData.m_Size;
    }
    s_EdgeData.m_Size = m_Size + 1;
    v34 = m_Size - v33;
    s_EdgeData.m_pElements = s_EdgeData.m_Memory.m_pMemory;
    if ( v34 > 0 )
      _V_memmove(
        dest: &s_EdgeData.m_Memory.m_pMemory[v33 + 1],
        src: &s_EdgeData.m_Memory.m_pMemory[v33],
        count: 4 * v34);
    v35 = &s_EdgeData.m_Memory.m_pMemory[v33];
    if ( v35 != nullptr )
      *v35 = pEdgeData;
  }
  else
  {
    while ( 1 )
    {
      v18 = s_EdgeData.m_Memory.m_pMemory[v17];
      pCmpData = v18;
      if ( v18 != nullptr )
      {
        v19 = v18->faceCount <= 0;
        j = 0;
        if ( !v19 )
          break;
      }
LABEL_20:
      i = ++v17;
      if ( v17 >= edgeCount )
      {
        m_Size = s_EdgeData.m_Size;
        goto LABEL_22;
      }
    }
    pFaces = v18->pFaces;
    while ( 1 )
    {
      v21 = *pFaces;
      v22 = (*pFaces)->m_DispHandle;
      v23 = pFaces[3];
      edgeType2 = (*pFaces)->nPoints;
      if ( (_WORD)v22 == 0xFFFF )
      {
        v25 = (int)&v21->Points[(_DWORD)v23];
      }
      else
      {
        v24 = EditDispMgr();
        v25 = (int)&v24->GetDisp(this: v24, a2: v22)->m_CoreDispInfo.m_Surf.m_Points[(_DWORD)v23];
      }
      edgePts2[0].x = *(float *)v25;
      edgePts2[0].y = *(float *)(v25 + 4);
      v26 = *(float *)(v25 + 8);
      v27 = ((int)&pFaces[3]->__vftable + 1) % edgeType2;
      v28 = *pFaces;
      v29 = (*pFaces)->m_DispHandle;
      edgePts2[0].z = v26;
      v30 = v27;
      if ( (_WORD)v29 == 0xFFFF )
      {
        v32 = &v28->Points[v27];
      }
      else
      {
        v31 = EditDispMgr();
        v32 = &v31->GetDisp(this: v31, a2: v29)->m_CoreDispInfo.m_Surf.m_Points[v30];
      }
      edgePts2[1] = *v32;
      if ( EdgeCompare(pEdgePts1: edgePts, pEdgePts2: edgePts2, &edgeType1, &edgeType2) != 0 )
        break;
      ++pFaces;
      if ( ++j >= pCmpData->faceCount )
      {
        v17 = i;
        goto LABEL_20;
      }
    }
    operator delete(p: pEdgeData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B60
// Name: void SewEdge_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SewEdge_Build()
{
  CFaceEditSheet *m_pFaceEditSheet; // eax
  int m_Size; // ecx
  CMapFace *pMapFace; // edi
  int v3; // ebx
  int m_DispHandle; // esi
  CEditDispMgr *v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  Vector *Points; // eax
  int v11; // ebx
  int v12; // esi
  CEditDispMgr *v13; // eax
  Vector *v14; // eax
  SewEdgeData_t *v15; // esi
  int v16; // eax
  CMapFace *v17; // ebx
  int v18; // edi
  CEditDispMgr *v19; // eax
  int v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  int v23; // ebx
  int v24; // edi
  CEditDispMgr *v25; // eax
  Vector *v26; // eax
  int v27; // eax
  Vector edgePts[2]; // [esp+4h] [ebp-80h] BYREF
  Vector edgePts2[2]; // [esp+1Ch] [ebp-68h] BYREF
  int v30; // [esp+34h] [ebp-50h]
  CMapFace *pFace; // [esp+38h] [ebp-4Ch]
  int v32; // [esp+3Ch] [ebp-48h]
  int type1; // [esp+40h] [ebp-44h] BYREF
  int type2; // [esp+44h] [ebp-40h] BYREF
  int faceCount; // [esp+48h] [ebp-3Ch]
  CFaceEditSheet *pSheet; // [esp+4Ch] [ebp-38h]
  int ptCount; // [esp+50h] [ebp-34h]
  int type1_keep; // [esp+54h] [ebp-30h]
  int ndxFace2; // [esp+58h] [ebp-2Ch]
  int ptCount2; // [esp+5Ch] [ebp-28h]
  unsigned int v41; // [esp+60h] [ebp-24h]
  int ndxFace; // [esp+64h] [ebp-20h]
  int i; // [esp+68h] [ebp-1Ch]
  int ndxPt; // [esp+6Ch] [ebp-18h]
  unsigned int v45; // [esp+70h] [ebp-14h]
  int ndxPt2; // [esp+74h] [ebp-10h]
  CMapFace *pFace2; // [esp+78h] [ebp-Ch]
  unsigned int v48; // [esp+7Ch] [ebp-8h]
  bool bError; // [esp+83h] [ebp-1h]

  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr )
  {
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    bError = false;
    faceCount = m_Size;
    ndxFace = 0;
    if ( m_Size > 0 )
    {
      v41 = 0;
      while ( 1 )
      {
        pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v41 / 0xC].pMapFace;
        pFace = pMapFace;
        if ( pMapFace != nullptr )
        {
          ptCount = pMapFace->nPoints;
          ndxPt = 0;
          if ( ptCount > 0 )
            break;
        }
LABEL_46:
        v41 += 12;
        if ( ++ndxFace >= m_Size )
        {
          if ( bError )
            AfxMessageBox(
              lpszText: "Not all selected faces could be sewn because too many selected faces share a single edge.\n"
              "\n"
              "Look for places where 3 or more selected faces (displacement or non-displacement) all share an edge.",
              nType: 0,
              nIDHelp: 0);
          return;
        }
      }
      v3 = 0;
      for ( i = 0; ; v3 = i )
      {
        type1_keep = 0;
        m_DispHandle = pMapFace->m_DispHandle;
        if ( (_WORD)m_DispHandle == 0xFFFF )
        {
          Points = pMapFace->Points;
          edgePts[0].x = *(float *)((char *)&Points->x + v3);
          edgePts[0].y = *(float *)((char *)&Points->y + v3);
          v9 = *(float *)((char *)&Points->z + v3);
        }
        else
        {
          v5 = EditDispMgr();
          v6 = (int)v5->GetDisp(this: v5, a2: m_DispHandle);
          v7 = *(float *)(v6 + v3 + 48);
          v8 = v6 + v3 + 48;
          edgePts[0].x = v7;
          edgePts[0].y = *(float *)(v8 + 4);
          v9 = *(float *)(v8 + 8);
        }
        v30 = ndxPt + 1;
        v11 = pMapFace->m_DispHandle;
        edgePts[0].z = v9;
        v12 = (ndxPt + 1) % ptCount;
        if ( (_WORD)v11 == 0xFFFF )
        {
          v14 = &pMapFace->Points[v12];
        }
        else
        {
          v13 = EditDispMgr();
          v14 = &v13->GetDisp(this: v13, a2: v11)->m_CoreDispInfo.m_Surf.m_Points[v12];
        }
        edgePts[1] = *v14;
        v15 = (SewEdgeData_t *)operator new(nSize: 0x28u);
        if ( v15 == nullptr )
          break;
        v16 = 0;
        v15->faceCount = 0;
        ndxFace2 = 0;
        v45 = 0;
        do
        {
          if ( ndxFace != v16 )
          {
            v17 = pSheet->m_Faces.m_Memory.m_pMemory[v45 / 0xC].pMapFace;
            pFace2 = v17;
            if ( v17 != nullptr )
            {
              ptCount2 = v17->nPoints;
              ndxPt2 = 0;
              if ( ptCount2 > 0 )
              {
                v48 = 0;
                while ( 1 )
                {
                  v18 = v17->m_DispHandle;
                  if ( (_WORD)v18 == 0xFFFF )
                  {
                    v21 = (int)&v17->Points[v48 / 0xC];
                  }
                  else
                  {
                    v19 = EditDispMgr();
                    v20 = (int)v19->GetDisp(this: v19, a2: v18);
                    v21 = v20 + v48 + 48;
                  }
                  edgePts2[0].x = *(float *)v21;
                  edgePts2[0].y = *(float *)(v21 + 4);
                  v22 = *(float *)(v21 + 8);
                  v32 = ndxPt2 + 1;
                  v23 = v17->m_DispHandle;
                  edgePts2[0].z = v22;
                  v24 = (ndxPt2 + 1) % ptCount2;
                  if ( (_WORD)v23 == 0xFFFF )
                  {
                    v26 = &pFace2->Points[v24];
                  }
                  else
                  {
                    v25 = EditDispMgr();
                    v26 = &v25->GetDisp(this: v25, a2: v23)->m_CoreDispInfo.m_Surf.m_Points[v24];
                  }
                  edgePts2[1] = *v26;
                  if ( EdgeCompare(pEdgePts1: edgePts, pEdgePts2: edgePts2, edgeType1: &type1, edgeType2: &type2) != 0 )
                  {
                    if ( v15->faceCount >= 3 )
                    {
                      bError = true;
                    }
                    else
                    {
                      v15->pFaces[v15->faceCount] = pFace2;
                      v15->ndxEdges[v15->faceCount] = ndxPt2;
                      v15->type[v15->faceCount++] = type2;
                    }
                    type1_keep = type1;
                  }
                  v48 += 12;
                  ndxPt2 = v32;
                  if ( v32 >= ptCount2 )
                    break;
                  v17 = pFace2;
                }
                pMapFace = pFace;
                v16 = ndxFace2;
              }
            }
          }
          v45 += 12;
          ndxFace2 = ++v16;
        }
        while ( v16 < faceCount );
        v27 = v15->faceCount;
        if ( v15->faceCount <= 0 )
        {
          operator delete(p: v15);
        }
        else
        {
          if ( v27 >= 3 )
          {
            bError = true;
          }
          else
          {
            v15->pFaces[v27] = pMapFace;
            v15->ndxEdges[v15->faceCount] = ndxPt;
            v15->type[v15->faceCount++] = type1_keep;
          }
          if ( v15->type[0] != 0 )
          {
            if ( SewEdge_AddToListTJunc(pEdgeData: v15) == 0 )
              bError = true;
          }
          else
          {
            SewEdge_AddToListNormal(pEdgeData: v15);
          }
        }
        i += 12;
        ndxPt = v30;
        if ( v30 >= ptCount )
        {
          m_pFaceEditSheet = pSheet;
          m_Size = faceCount;
          goto LABEL_46;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027ED0
// Name: void TesselateDisplacementNode<class CHammerTesselateHelper>(class CHammerTesselateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CHammerTesselateHelper>(
        CHammerTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  __int16 v6; // dx
  __int16 v7; // di
  int m_iNode; // ecx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *m_pIndices; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v13; // eax
  unsigned __int16 *v14; // ebx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v15; // edi
  int v16; // ebx
  int v17; // eax
  unsigned __int16 *v18; // ecx
  int v19; // eax
  unsigned __int16 *v20; // eax
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v21; // edi
  int v22; // ebx
  int v23; // eax
  unsigned __int16 *v24; // ecx
  int v25; // eax
  unsigned __int16 *v26; // eax
  int iVert; // [esp+Ch] [ebp-8h]
  int vertInc; // [esp+10h] [ebp-4h]
  int iCurTriVert; // [esp+1Ch] [ebp+8h]
  int iLevela; // [esp+24h] [ebp+10h]

  vertInc = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v5 = 0;
  iCurTriVert = 0;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    iLevela = 0;
    do
    {
      v6 = nodeIndex->x + vertInc * g_TWinding.m_Verts[iLevela].m_Index.x;
      v7 = nodeIndex->y + vertInc * g_TWinding.m_Verts[iLevela].m_Index.y;
      m_iNode = g_TWinding.m_Verts[iLevela].m_iNode;
      if ( m_iNode == -1 || pActiveChildren[m_iNode] == 0 )
      {
        if ( ((1 << ((v6 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v7) & 0x1F))
            & pHelper->m_pActiveVerts[(v6 + pHelper->m_pPowerInfo->m_SideLength * v7) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert] = v6 + v7 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          v5 = iCurTriVert + 1;
          iCurTriVert = v5;
          if ( v5 == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: pHelper->m_TempIndices);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[1]);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[2]);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            v5 = 1;
            iCurTriVert = 1;
          }
        }
        else
        {
          v5 = iCurTriVert;
        }
      }
      else
      {
        if ( v5 == 2 )
        {
          m_pIndices = pHelper->m_pIndices;
          pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          m_Size = m_pIndices->m_Size;
          m_nAllocationCount = m_pIndices->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &m_pIndices->m_Memory, num: m_Size - m_nAllocationCount + 1);
          ++m_pIndices->m_Size;
          m_pMemory = m_pIndices->m_Memory.m_pMemory;
          v13 = m_pIndices->m_Size - m_Size - 1;
          m_pIndices->m_pElements = m_pIndices->m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v13);
          v14 = &m_pIndices->m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = pHelper->m_TempIndices[0];
          v15 = pHelper->m_pIndices;
          v16 = v15->m_Size;
          v17 = v15->m_Memory.m_nAllocationCount;
          if ( v16 + 1 > v17 )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &v15->m_Memory, num: v16 - v17 + 1);
          ++v15->m_Size;
          v18 = v15->m_Memory.m_pMemory;
          v19 = v15->m_Size - v16 - 1;
          v15->m_pElements = v15->m_Memory.m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 2 * v19);
          v20 = &v15->m_Memory.m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = pHelper->m_TempIndices[1];
          v21 = pHelper->m_pIndices;
          v22 = v21->m_Size;
          v23 = v21->m_Memory.m_nAllocationCount;
          if ( v22 + 1 > v23 )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &v21->m_Memory, num: v22 - v23 + 1);
          ++v21->m_Size;
          v24 = v21->m_Memory.m_pMemory;
          v25 = v21->m_Size - v22 - 1;
          v21->m_pElements = v21->m_Memory.m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 2 * v25);
          v26 = &v21->m_Memory.m_pMemory[v22];
          if ( v26 != nullptr )
            *v26 = pHelper->m_TempIndices[2];
          pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
        }
        v5 = 0;
        iCurTriVert = 0;
      }
      ++iLevela;
      ++iVert;
    }
    while ( iVert < g_TWinding.m_nVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028150
// Name: void TesselateDisplacement_R<class CHammerTesselateHelper>(class CHammerTesselateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CHammerTesselateHelper>(
        CHammerTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v6; // edx
  int v7; // ebx
  const CPowerInfo *v8; // ecx
  const CVertIndex *v9; // esi
  unsigned int v10; // edx
  int bActiveChildren[4]; // [esp+0h] [ebp-24h] BYREF
  int oldIndexCount; // [esp+10h] [ebp-14h]
  int v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]
  int iChildNodeBit; // [esp+2Ch] [ebp+8h]

  if ( (`CHammerTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
  {
    `CHammerTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
    v14 = -1;
  }
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v6 = m_pPowerInfo->m_Power - 1;
  oldIndexCount = pHelper->m_nIndices;
  if ( iLevel < v6 )
  {
    v7 = 0;
    iChildNodeBit = iNodeBitIndex + 1;
    v13 = 16 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v8 = pHelper->m_pPowerInfo;
      v9 = &v8->m_pChildVerts->m_Verts[v13 / 4u];
      v10 = pHelper->m_pActiveVerts[(v9->x + v8->m_SideLength * v9->y) >> 5]
          & (1 << ((v9->x + LOBYTE(v8->m_SideLength) * v9->y) & 0x1F));
      bActiveChildren[v7] = v10;
      if ( v10 != 0 )
      {
        TesselateDisplacement_R<CHammerTesselateHelper>(
          pHelper,
          nodeIndex: v9,
          iNodeBitIndex: iChildNodeBit,
          iLevel: iLevel + 1);
      }
      else
      {
        if ( (`CHammerTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
        {
          `CHammerTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
          v14 = -1;
        }
        word_1078F4FA = 0;
      }
      iChildNodeBit += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      v13 += 4;
      ++v7;
    }
    while ( v7 < 4 );
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    HIBYTE(word_1078F4FA) = 0;
  }
  else
  {
    HIBYTE(word_1078F4FA) = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CHammerTesselateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  LOBYTE(word_1078F4FA) = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  `CHammerTesselateHelper::GetNodeInfo'::`2'::dummy = oldIndexCount;
}

//------------------------------------------------------------------------------
// Address: 0x100282B0
// Name: void SnapDependentVertsToSurface(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SnapDependentVertsToSurface(CCoreDispInfo *pCoreDisp)
{
  CCoreDispInfo_vtbl *v2; // eax
  bool *m_pMemory; // eax
  int m_Power; // ecx
  int v5; // edi
  int i; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int j; // edx
  Vector2D *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  CoreDispVert_t *m_pVerts; // eax
  float *p_x; // ecx
  int v18; // edx
  int v19; // edi
  float x; // xmm6_4
  float z; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // ecx
  int m_nGrowSize; // esi
  Vector2D *v29; // eax
  int v30; // esi
  bool *v31; // eax
  unsigned __int16 *v32; // eax
  CHammerTesselateHelper helper; // [esp+Ch] [ebp-94h] BYREF
  float v34; // [esp+2Ch] [ebp-74h]
  float v35; // [esp+30h] [ebp-70h]
  float flBCoords[3]; // [esp+34h] [ebp-6Ch] BYREF
  Vector vNewPos; // [esp+40h] [ebp-60h]
  int nIndex; // [esp+4Ch] [ebp-54h]
  int iStartVert; // [esp+50h] [ebp-50h] BYREF
  int iWid; // [esp+54h] [ebp-4Ch]
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > vertCoords; // [esp+58h] [ebp-48h] BYREF
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+6Ch] [ebp-34h] BYREF
  CUtlVector<bool,CUtlMemory<bool,int> > vertsTouched; // [esp+80h] [ebp-20h] BYREF
  int v44; // [esp+9Ch] [ebp-4h]
  int iHgt; // [esp+A8h] [ebp+8h]

  memset(&indices, 0, sizeof(indices));
  v44 = 1;
  v2 = pCoreDisp->__vftable;
  helper.m_pIndices = &indices;
  helper.m_pActiveVerts = pCoreDisp->m_AllowedVerts.m_Ints;
  helper.m_pPowerInfo = v2->GetPowerInfo(this: pCoreDisp);
  helper.m_nIndices = 0;
  TesselateDisplacement_R<CHammerTesselateHelper>(
    pHelper: &helper,
    nodeIndex: &helper.m_pPowerInfo->m_RootNode,
    iNodeBitIndex: 0,
    iLevel: 0);
  m_pMemory = nullptr;
  memset(&vertsTouched, 0, sizeof(vertsTouched));
  LOBYTE(v44) = 3;
  m_Power = pCoreDisp->m_Power;
  vertsTouched.m_Size = 0;
  v5 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      CUtlMemory<bool,int>::Grow(
        this: (CUtlMemory<char,int> *)&vertsTouched,
        num: ((1 << m_Power) + 1) * ((1 << m_Power) + 1));
      m_pMemory = vertsTouched.m_Memory.m_pMemory;
    }
    vertsTouched.m_Size += v5;
    vertsTouched.m_pElements = m_pMemory;
    if ( vertsTouched.m_Size - v5 > 0 && v5 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: vertsTouched.m_Size - v5);
      m_pMemory = vertsTouched.m_Memory.m_pMemory;
    }
  }
  memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: vertsTouched.m_Size);
  for ( i = 0; i < indices.m_Size; vertsTouched.m_Memory.m_pMemory[v7] = true )
    v7 = indices.m_Memory.m_pMemory[i++];
  memset(&vertCoords, 0, sizeof(vertCoords));
  LOBYTE(v44) = 5;
  v8 = 1 << pCoreDisp->m_Power;
  vertCoords.m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    this: &vertCoords,
    elem: 0,
    num: (v8 + 1) * (v8 + 1));
  v9 = 0;
  v10 = (1 << pCoreDisp->m_Power) + 1;
  if ( v10 > 0 )
  {
    do
    {
      for ( j = 0; j < v10; v10 = (1 << pCoreDisp->m_Power) + 1 )
      {
        v12 = &vertCoords.m_Memory.m_pMemory[j + v9 * v10];
        v12->y = (float)v9;
        v12->x = (float)j++;
      }
      ++v9;
      v10 = (1 << pCoreDisp->m_Power) + 1;
    }
    while ( v9 < v10 );
  }
  iHgt = 0;
  v13 = (1 << pCoreDisp->m_Power) + 1;
  if ( v13 > 0 )
  {
    do
    {
      v14 = 0;
      for ( iWid = 0; v14 < v13; v13 = (1 << v27) + 1 )
      {
        v15 = v14 + iHgt * v13;
        nIndex = v15;
        if ( !vertsTouched.m_Memory.m_pMemory[v15] )
        {
          iStartVert = -1;
          if ( FindEnclosingTri(
                 vert: &vertCoords.m_Memory.m_pMemory[v15],
                 &vertCoords,
                 &indices,
                 pStartVert: &iStartVert,
                 bcCoords: flBCoords) != 0 )
          {
            m_pVerts = pCoreDisp->m_pVerts;
            p_x = &m_pVerts[indices.m_Memory.m_pMemory[iStartVert]].m_Vert.x;
            v18 = indices.m_Memory.m_pMemory[iStartVert + 1];
            v19 = indices.m_Memory.m_pMemory[iStartVert + 2];
            x = m_pVerts[v18].m_Vert.x;
            z = m_pVerts[indices.m_Memory.m_pMemory[iStartVert]].m_Vert.z;
            v22 = m_pVerts[v19].m_Vert.y * flBCoords[2];
            v23 = m_pVerts[v19].m_Vert.z * flBCoords[2];
            v24 = m_pVerts[v19].m_Vert.x * flBCoords[2];
            v34 = m_pVerts[v18].m_Vert.y * flBCoords[1];
            v25 = *p_x;
            v35 = m_pVerts[v18].m_Vert.z * flBCoords[1];
            v26 = (float)((float)(p_x[1] * flBCoords[0]) + v34) + v22;
            vNewPos.x = (float)((float)(v25 * flBCoords[0]) + (float)(x * flBCoords[1])) + v24;
            vNewPos.y = v26;
            vNewPos.z = (float)((float)(z * flBCoords[0]) + v35) + v23;
            CCoreDispInfo::Position_Update(this: pCoreDisp, iVert: nIndex, vecPos: vNewPos);
            v14 = iWid;
          }
        }
        v27 = pCoreDisp->m_Power;
        iWid = ++v14;
      }
      ++iHgt;
      v13 = (1 << pCoreDisp->m_Power) + 1;
    }
    while ( iHgt < v13 );
  }
  LOBYTE(v44) = 6;
  m_nGrowSize = vertCoords.m_Memory.m_nGrowSize;
  v29 = vertCoords.m_Memory.m_pMemory;
  vertCoords.m_Size = 0;
  if ( vertCoords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( vertCoords.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: vertCoords.m_Memory.m_pMemory);
      vertCoords.m_Memory.m_pMemory = nullptr;
      v29 = nullptr;
    }
    vertCoords.m_Memory.m_nAllocationCount = 0;
  }
  vertCoords.m_pElements = v29;
  LOBYTE(v44) = 3;
  if ( m_nGrowSize >= 0 )
  {
    if ( v29 != nullptr )
    {
      free(pMem: v29);
      vertCoords.m_Memory.m_pMemory = nullptr;
    }
    vertCoords.m_Memory.m_nAllocationCount = 0;
  }
  LOBYTE(v44) = 7;
  v30 = vertsTouched.m_Memory.m_nGrowSize;
  v31 = vertsTouched.m_Memory.m_pMemory;
  vertsTouched.m_Size = 0;
  if ( vertsTouched.m_Memory.m_nGrowSize >= 0 )
  {
    if ( vertsTouched.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: vertsTouched.m_Memory.m_pMemory);
      vertsTouched.m_Memory.m_pMemory = nullptr;
      v31 = nullptr;
    }
    vertsTouched.m_Memory.m_nAllocationCount = 0;
  }
  vertsTouched.m_pElements = v31;
  LOBYTE(v44) = 1;
  if ( v30 >= 0 )
  {
    if ( v31 != nullptr )
    {
      free(pMem: v31);
      vertsTouched.m_Memory.m_pMemory = nullptr;
    }
    vertsTouched.m_Memory.m_nAllocationCount = 0;
  }
  v44 = 8;
  v32 = indices.m_Memory.m_pMemory;
  indices.m_Size = 0;
  if ( indices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( indices.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: indices.m_Memory.m_pMemory);
      v32 = nullptr;
      indices.m_Memory.m_pMemory = nullptr;
    }
    indices.m_Memory.m_nAllocationCount = 0;
  }
  indices.m_pElements = v32;
  v44 = -1;
  if ( indices.m_Memory.m_nGrowSize >= 0 && indices.m_Memory.m_pMemory != nullptr )
    free(pMem: indices.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100286C0
// Name: void PostPlanarizeDependentVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostPlanarizeDependentVerts()
{
  int i; // esi
  CCoreDispInfo **m_pMemory; // eax

  for ( i = 0; i < m_aCoreDispInfos.m_Size; ++i )
    SnapDependentVertsToSurface(pCoreDisp: m_aCoreDispInfos.m_Memory.m_pMemory[i]);
  m_aCoreDispInfos.m_Size = 0;
  if ( m_aCoreDispInfos.m_Memory.m_nGrowSize < 0 )
  {
    m_aCoreDispInfos.m_pElements = m_aCoreDispInfos.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = m_aCoreDispInfos.m_Memory.m_pMemory;
    if ( m_aCoreDispInfos.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: m_aCoreDispInfos.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      m_aCoreDispInfos.m_Memory.m_pMemory = nullptr;
    }
    m_aCoreDispInfos.m_Memory.m_nAllocationCount = 0;
    m_aCoreDispInfos.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028740
// Name: void FaceListSewEdges(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FaceListSewEdges()
{
  SewCorner_Build();
  SewTJunc_Build();
  SewEdge_Build();
  if ( PrePlanarizeDependentVerts() != 0 )
  {
    SetupAllowedVerts(ppListBase: m_aCoreDispInfos.m_Memory.m_pMemory, nListSize: m_aCoreDispInfos.m_Size);
    PostPlanarizeDependentVerts();
  }
  SewCorner_Resolve();
  SewTJunc_Resolve();
  SewEdge_Resolve();
  PostFaceListSew();
}
