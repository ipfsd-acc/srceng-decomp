// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapface.cpp
// Functions: 75
// ============================================================

#include "hammer\mapface.h"

//------------------------------------------------------------------------------
// Address: 0x10124F60
// Name: public: bool VMatrix::IsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall VMatrix::IsIdentity(VMatrix *this)
{
  return this->m[0][0] == 1.0
      && this->m[0][1] == 0.0
      && this->m[0][2] == 0.0
      && this->m[0][3] == 0.0
      && this->m[1][0] == 0.0
      && this->m[1][1] == 1.0
      && this->m[1][2] == 0.0
      && this->m[1][3] == 0.0
      && this->m[2][0] == 0.0
      && this->m[2][1] == 0.0
      && this->m[2][2] == 1.0
      && this->m[2][3] == 0.0
      && this->m[3][0] == 0.0
      && this->m[3][1] == 0.0
      && this->m[3][2] == 0.0
      && this->m[3][3] == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10125070
// Name: public: void CMapFace::GetTextureName(char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetTextureName(CMapFace *this, char *pszName)
{
  if ( pszName != nullptr )
  {
    if ( this->m_pTexture != nullptr )
      this->m_pTexture->GetShortName(this: this->m_pTexture, a2: pszName);
    else
      *pszName = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101250A0
// Name: protected: void CMapFace::UpdateFaceFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::UpdateFaceFlags(CMapFace *this)
{
  IEditorTexture *m_pTexture; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char tname[2048]; // [esp+4h] [ebp-800h] BYREF

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr )
    m_pTexture->GetShortName(this: m_pTexture, a2: tname);
  else
    tname[0] = 0;
  this->m_nFaceFlags = 0;
  strstr(str1: (unsigned __int8 *)tname, str2: "tools");
  if ( v3 != 0 )
  {
    strstr(str1: (unsigned __int8 *)tname, str2: "blocklight");
    if ( v4 != 0 )
      this->m_nFaceFlags |= 2u;
    strstr(str1: (unsigned __int8 *)tname, str2: "skybox");
    if ( v5 != 0 )
      this->m_nFaceFlags |= 1u;
    v6 = 0;
    while ( 1 )
    {
      strstr(str1: (unsigned __int8 *)tname, str2: (unsigned __int8 *)InvisToolTextures[v6]);
      if ( v7 != 0 )
        break;
      if ( (unsigned int)++v6 >= 10 )
        return;
    }
    this->m_nFaceFlags |= 3u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125170
// Name: public: void CMapFace::OnUndoRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::OnUndoRedo(CMapFace *this)
{
  CMainFrame *MainWnd; // eax

  MainWnd = GetMainWnd();
  if ( !CMainFrame::IsInFaceEditMode(this: MainWnd) )
    this->m_eSelectionState = SELECT_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10125190
// Name: public: void CMapFace::GetCenter(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetCenter(CMapFace *this, Vector *Center)
{
  int nPoints; // edx
  int v3; // esi
  int v4; // edx

  Center->x = 0.0;
  Center->y = 0.0;
  Center->z = 0.0;
  nPoints = this->nPoints;
  if ( nPoints != 0 )
  {
    v3 = 0;
    if ( nPoints > 0 )
    {
      v4 = 0;
      do
      {
        Center->x = this->Points[v4].x + Center->x;
        Center->y = this->Points[v4].y + Center->y;
        ++v3;
        Center->z = this->Points[v4++].z + Center->z;
      }
      while ( v3 < this->nPoints );
    }
    Center->x = Center->x / (float)this->nPoints;
    Center->y = Center->y / (float)this->nPoints;
    Center->z = Center->z / (float)this->nPoints;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125260
// Name: public: enum FaceOrientation_t CMapFace::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::GetOrientation(CMapFace *this)
{
  int v2; // esi
  float v3; // xmm1_4
  Vector Normal; // [esp+0h] [ebp-Ch] BYREF

  if ( this->plane.normal.x == 0.0 && this->plane.normal.y == 0.0 && this->plane.normal.z == 0.0 )
    return 6;
  Normal = this->plane.normal;
  v2 = 6;
  VectorNormalize(vec: &Normal);
  v3 = 0.0;
  if ( (float)((float)((float)(*(float *)&dword_10731754 * Normal.y) + (float)(FaceNormals[0].x * Normal.x))
             + (float)(*(float *)&dword_10731758 * Normal.z)) >= 0.0 )
  {
    v3 = (float)((float)(*(float *)&dword_10731754 * Normal.y) + (float)(FaceNormals[0].x * Normal.x))
       + (float)(*(float *)&dword_10731758 * Normal.z);
    v2 = 0;
  }
  if ( (float)((float)((float)(*(float *)&dword_10731760 * Normal.y) + (float)(*(float *)&dword_1073175C * Normal.x))
             + (float)(*(float *)&dword_10731764 * Normal.z)) >= v3 )
  {
    v3 = (float)((float)(*(float *)&dword_10731760 * Normal.y) + (float)(*(float *)&dword_1073175C * Normal.x))
       + (float)(*(float *)&dword_10731764 * Normal.z);
    v2 = 1;
  }
  if ( (float)((float)((float)(*(float *)&dword_1073176C * Normal.y) + (float)(*(float *)&dword_10731768 * Normal.x))
             + (float)(*(float *)&dword_10731770 * Normal.z)) >= v3 )
  {
    v3 = (float)((float)(*(float *)&dword_1073176C * Normal.y) + (float)(*(float *)&dword_10731768 * Normal.x))
       + (float)(*(float *)&dword_10731770 * Normal.z);
    v2 = 2;
  }
  if ( (float)((float)((float)(*(float *)&dword_10731778 * Normal.y) + (float)(*(float *)&dword_10731774 * Normal.x))
             + (float)(*(float *)&dword_1073177C * Normal.z)) >= v3 )
  {
    v3 = (float)((float)(*(float *)&dword_10731778 * Normal.y) + (float)(*(float *)&dword_10731774 * Normal.x))
       + (float)(*(float *)&dword_1073177C * Normal.z);
    v2 = 3;
  }
  if ( (float)((float)((float)(*(float *)&dword_10731784 * Normal.y) + (float)(*(float *)&dword_10731780 * Normal.x))
             + (float)(*(float *)&dword_10731788 * Normal.z)) >= v3 )
  {
    v3 = (float)((float)(*(float *)&dword_10731784 * Normal.y) + (float)(*(float *)&dword_10731780 * Normal.x))
       + (float)(*(float *)&dword_10731788 * Normal.z);
    v2 = 4;
  }
  if ( (float)((float)((float)(*(float *)&dword_10731790 * Normal.y) + (float)(*(float *)&dword_1073178C * Normal.x))
             + (float)(*(float *)&dword_10731794 * Normal.z)) >= v3 )
    return 5;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10125450
// Name: public: int CMapFace::IsTextureAxisValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapFace::IsTextureAxisValid(CMapFace *this)
{
  return (float)((float)((float)(this->plane.normal.y
                               * (float)((float)(this->texture.UAxis.x * this->texture.VAxis.z)
                                       - (float)(this->texture.VAxis.x * this->texture.UAxis.z)))
                       + (float)(this->plane.normal.x
                               * (float)((float)(this->texture.UAxis.z * this->texture.VAxis.y)
                                       - (float)(this->texture.UAxis.y * this->texture.VAxis.z))))
               + (float)(this->plane.normal.z
                       * (float)((float)(this->texture.VAxis.x * this->texture.UAxis.y)
                               - (float)(this->texture.UAxis.x * this->texture.VAxis.y)))) != 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10125500
// Name: public: void CMapFace::NormalizeTextureShifts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::NormalizeTextureShifts(CMapFace *this)
{
  Vector4D *p_VAxis; // esi
  int i; // ebx
  int v4; // eax
  float v5; // xmm0_4
  IEditorTexture *m_pTexture; // ecx

  p_VAxis = &this->texture.VAxis;
  for ( i = 4; i != 0; --i )
  {
    v4 = (int)rint(f: p_VAxis[-1].x);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(p_VAxis[-1].x - (float)v4) & _mask__AbsFloat_) < 0.001 )
      p_VAxis[-1].x = (float)v4;
    v5 = (float)(int)rint(f: p_VAxis->x);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(p_VAxis->x - v5) & _mask__AbsFloat_) < 0.001 )
      p_VAxis->x = v5;
    p_VAxis = (Vector4D *)((char *)p_VAxis + 4);
  }
  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr )
  {
    if ( m_pTexture->GetMappingWidth(this: m_pTexture) != 0 )
      this->texture.UAxis.w = fmod(
                                this->texture.UAxis.w,
                                (double)this->m_pTexture->GetMappingWidth(this: this->m_pTexture));
    if ( this->m_pTexture->GetMappingHeight(this: this->m_pTexture) != 0 )
      this->texture.VAxis.w = fmod(
                                this->texture.VAxis.w,
                                (double)this->m_pTexture->GetMappingHeight(this: this->m_pTexture));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125640
// Name: public: void CMapFace::GetFaceBounds(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetFaceBounds(CMapFace *this, Vector *pfMins, Vector *pfMaxs)
{
  int v3; // edx
  int v4; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v3 = 0;
  if ( this->nPoints > 0 )
  {
    v4 = 0;
    do
    {
      x = this->Points[v4].x;
      if ( pfMins->x > x || v3 == 0 )
        pfMins->x = x;
      y = this->Points[v4].y;
      if ( pfMins->y > y || v3 == 0 )
        pfMins->y = y;
      z = this->Points[v4].z;
      if ( pfMins->z > z || v3 == 0 )
        pfMins->z = z;
      v8 = this->Points[v4].x;
      if ( v8 > pfMaxs->x || v3 == 0 )
        pfMaxs->x = v8;
      v9 = this->Points[v4].y;
      if ( v9 > pfMaxs->y || v3 == 0 )
        pfMaxs->y = v9;
      v10 = this->Points[v4].z;
      if ( v10 > pfMaxs->z || v3 == 0 )
        pfMaxs->z = v10;
      ++v3;
      ++v4;
    }
    while ( v3 < this->nPoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125720
// Name: public: float CMapFace::GetNormalDistance(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapFace::GetNormalDistance(CMapFace *this, Vector *fPoint)
{
  return this->plane.normal.y * fPoint->y
       + this->plane.normal.x * fPoint->x
       + this->plane.normal.z * fPoint->z
       - this->plane.dist;
}

//------------------------------------------------------------------------------
// Address: 0x10125750
// Name: public: int CMapFace::GetTextureAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::GetTextureAlignment(CMapFace *this)
{
  float z; // xmm3_4
  float v3; // xmm4_4
  float y; // xmm5_4
  float v5; // xmm2_4
  float x; // xmm1_4
  float v7; // xmm0_4
  int v8; // edi
  int Orientation; // eax
  unsigned int v10; // eax
  Vector TexNormalAxis; // [esp+4h] [ebp-Ch] BYREF

  z = this->texture.UAxis.z;
  v3 = this->texture.VAxis.z;
  y = this->texture.UAxis.y;
  v5 = this->texture.VAxis.y;
  x = this->texture.UAxis.x;
  TexNormalAxis.x = (float)(z * v5) - (float)(y * v3);
  v7 = (float)(this->texture.VAxis.x * y) - (float)(x * v5);
  v8 = 0;
  TexNormalAxis.y = (float)(x * v3) - (float)(this->texture.VAxis.x * z);
  TexNormalAxis.z = v7;
  VectorNormalize(vec: &TexNormalAxis);
  if ( (float)((float)((float)(this->plane.normal.y * TexNormalAxis.y) + (float)(this->plane.normal.x * TexNormalAxis.x))
             + (float)(this->plane.normal.z * TexNormalAxis.z)) > 0.9999 )
    v8 = 2;
  Orientation = CMapFace::GetOrientation(this);
  if ( Orientation != 6 )
  {
    v10 = 6 * Orientation;
    if ( (float)((float)((float)((float)((float)(RightVectors[v10 / 6].x * *(float *)&dword_107317A0[v10 / 2])
                                       - (float)(DownVectors[v10 / 6].x * *(float *)&dword_107317E8[v10 / 2]))
                               * TexNormalAxis.y)
                       + (float)((float)((float)(*(float *)&dword_107317E8[v10 / 2] * *(float *)&dword_1073179C[v10 / 2])
                                       - (float)(*(float *)&dword_107317E4[v10 / 2] * *(float *)&dword_107317A0[v10 / 2]))
                               * TexNormalAxis.x))
               + (float)((float)((float)(DownVectors[v10 / 6].x * *(float *)&dword_107317E4[v10 / 2])
                               - (float)(RightVectors[v10 / 6].x * *(float *)&dword_1073179C[v10 / 2]))
                       * TexNormalAxis.z)) > 0.9999 )
      return v8 | 1;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101258D0
// Name: public: void CMapFace::GetTextureExtents(class Vector __near * const,class Vector2D __near &,class Vector2D __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetTextureExtents(CMapFace *this, Vector *Extents, Vector2D *TopLeft, Vector2D *BottomRight)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4

  v5 = (float)((float)((float)(Extents->y * this->texture.UAxis.y) + (float)(Extents->x * this->texture.UAxis.x))
             + (float)(Extents->z * this->texture.UAxis.z))
     / this->texture.scale[0];
  v6 = (float)((float)((float)(Extents->x * this->texture.VAxis.x) + (float)(Extents->y * this->texture.VAxis.y))
             + (float)(Extents->z * this->texture.VAxis.z))
     / this->texture.scale[1];
  TopLeft->x = v5;
  TopLeft->y = v6;
  BottomRight->x = v5;
  BottomRight->y = v6;
  v7 = (float)((float)((float)(Extents[1].y * this->texture.UAxis.y) + (float)(this->texture.UAxis.x * Extents[1].x))
             + (float)(Extents[1].z * this->texture.UAxis.z))
     / this->texture.scale[0];
  v8 = (float)((float)((float)(Extents[1].y * this->texture.VAxis.y) + (float)(this->texture.VAxis.x * Extents[1].x))
             + (float)(Extents[1].z * this->texture.VAxis.z))
     / this->texture.scale[1];
  if ( TopLeft->x > v7 )
    TopLeft->x = v7;
  if ( TopLeft->y > v8 )
    TopLeft->y = v8;
  if ( v7 > BottomRight->x )
    BottomRight->x = v7;
  if ( v8 > BottomRight->y )
    BottomRight->y = v8;
  v9 = (float)((float)((float)(Extents[2].y * this->texture.UAxis.y) + (float)(this->texture.UAxis.x * Extents[2].x))
             + (float)(Extents[2].z * this->texture.UAxis.z))
     / this->texture.scale[0];
  v10 = (float)((float)((float)(Extents[2].y * this->texture.VAxis.y) + (float)(this->texture.VAxis.x * Extents[2].x))
              + (float)(Extents[2].z * this->texture.VAxis.z))
      / this->texture.scale[1];
  if ( TopLeft->x > v9 )
    TopLeft->x = v9;
  if ( TopLeft->y > v10 )
    TopLeft->y = v10;
  if ( v9 > BottomRight->x )
    BottomRight->x = v9;
  if ( v10 > BottomRight->y )
    BottomRight->y = v10;
  v11 = (float)((float)((float)(Extents[3].y * this->texture.UAxis.y) + (float)(this->texture.UAxis.x * Extents[3].x))
              + (float)(Extents[3].z * this->texture.UAxis.z))
      / this->texture.scale[0];
  v12 = (float)((float)((float)(Extents[3].y * this->texture.VAxis.y) + (float)(this->texture.VAxis.x * Extents[3].x))
              + (float)(Extents[3].z * this->texture.VAxis.z))
      / this->texture.scale[1];
  if ( TopLeft->x > v11 )
    TopLeft->x = v11;
  if ( TopLeft->y > v12 )
    TopLeft->y = v12;
  if ( v11 > BottomRight->x )
    BottomRight->x = v11;
  if ( v12 > BottomRight->y )
    BottomRight->y = v12;
  v13 = (float)((float)((float)(Extents[4].y * this->texture.UAxis.y) + (float)(this->texture.UAxis.x * Extents[4].x))
              + (float)(Extents[4].z * this->texture.UAxis.z))
      / this->texture.scale[0];
  v14 = (float)((float)((float)(Extents[4].y * this->texture.VAxis.y) + (float)(this->texture.VAxis.x * Extents[4].x))
              + (float)(Extents[4].z * this->texture.VAxis.z))
      / this->texture.scale[1];
  if ( TopLeft->x > v13 )
    TopLeft->x = v13;
  if ( TopLeft->y > v14 )
    TopLeft->y = v14;
  if ( v13 > BottomRight->x )
    BottomRight->x = v13;
  if ( v14 > BottomRight->y )
    BottomRight->y = v14;
  v15 = (float)((float)((float)(Extents[5].y * this->texture.UAxis.y) + (float)(this->texture.UAxis.x * Extents[5].x))
              + (float)(Extents[5].z * this->texture.UAxis.z))
      / this->texture.scale[0];
  v16 = (float)((float)((float)(Extents[5].y * this->texture.VAxis.y) + (float)(this->texture.VAxis.x * Extents[5].x))
              + (float)(Extents[5].z * this->texture.VAxis.z))
      / this->texture.scale[1];
  if ( TopLeft->x > v15 )
    TopLeft->x = v15;
  if ( TopLeft->y > v16 )
    TopLeft->y = v16;
  if ( v15 > BottomRight->x )
    BottomRight->x = v15;
  if ( v16 > BottomRight->y )
    BottomRight->y = v16;
}

//------------------------------------------------------------------------------
// Address: 0x10125C80
// Name: public: void CMapFace::GetFaceExtents(class Vector __near * const)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetFaceExtents(CMapFace *this, Vector *Extents)
{
  int v2; // ebx
  int v3; // edi
  int v4; // edx
  Vector *v5; // esi
  Vector *Points; // esi
  float x; // xmm0_4
  Vector *v8; // esi
  Vector *v9; // esi
  Vector *v10; // esi
  float y; // xmm0_4
  Vector *v12; // esi
  Vector *v13; // esi
  Vector *v14; // esi
  float z; // xmm0_4
  Vector *v16; // esi

  v2 = 0;
  v3 = 1;
  if ( this->nPoints > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->Points[v4];
      if ( Extents->x > v5->x || v3 != 0 )
        *Extents = *v5;
      Points = this->Points;
      x = Points[v4].x;
      v8 = &Points[v4];
      if ( x > Extents[1].x || v3 != 0 )
        Extents[1] = *v8;
      v9 = &this->Points[v4];
      if ( Extents[2].y > v9->y || v3 != 0 )
        Extents[2] = *v9;
      v10 = this->Points;
      y = v10[v4].y;
      v12 = &v10[v4];
      if ( y > Extents[3].y || v3 != 0 )
        Extents[3] = *v12;
      v13 = &this->Points[v4];
      if ( Extents[4].z > v13->z || v3 != 0 )
        Extents[4] = *v13;
      v14 = this->Points;
      z = v14[v4].z;
      v16 = &v14[v4];
      if ( z > Extents[5].z || v3 != 0 )
        Extents[5] = *v16;
      ++v2;
      v3 = 0;
      ++v4;
    }
    while ( v2 < this->nPoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125DB0
// Name: public: void CMapFace::OffsetTexture(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::OffsetTexture(CMapFace *this, const Vector *Delta)
{
  this->texture.UAxis.w = this->texture.UAxis.w
                        - (float)((float)((float)((float)(this->texture.UAxis.y * Delta->y)
                                                + (float)(this->texture.UAxis.x * Delta->x))
                                        + (float)(this->texture.UAxis.z * Delta->z))
                                / this->texture.scale[0]);
  this->texture.VAxis.w = this->texture.VAxis.w
                        - (float)((float)((float)((float)(this->texture.VAxis.y * Delta->y)
                                                + (float)(this->texture.VAxis.x * Delta->x))
                                        + (float)(this->texture.VAxis.z * Delta->z))
                                / this->texture.scale[1]);
  CMapFace::NormalizeTextureShifts(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125E60
// Name: public: void CMapFace::RotateTextureAxes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::RotateTextureAxes(CMapFace *this, float fDegrees)
{
  float z; // xmm3_4
  float v4; // xmm4_4
  float y; // xmm5_4
  float v6; // xmm2_4
  float x; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float w; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  VMatrix Matrix; // [esp+4h] [ebp-60h] BYREF
  float v31; // [esp+44h] [ebp-20h]
  Vector4D VAxis; // [esp+48h] [ebp-1Ch]
  Vector Axis; // [esp+58h] [ebp-Ch] BYREF

  z = this->texture.UAxis.z;
  v4 = this->texture.VAxis.z;
  y = this->texture.UAxis.y;
  v6 = this->texture.VAxis.y;
  x = this->texture.UAxis.x;
  Axis.x = (float)(z * v6) - (float)(y * v4);
  v8 = x * v4;
  v9 = this->texture.VAxis.x;
  Axis.z = (float)(v9 * y) - (float)(x * v6);
  Axis.y = v8 - (float)(v9 * z);
  AxisAngleMatrix(&Matrix, &Axis, fAngle: fDegrees);
  v10 = this->texture.UAxis.y;
  v11 = this->texture.UAxis.z;
  w = this->texture.UAxis.w;
  v13 = (float)((float)((float)(this->texture.UAxis.x * Matrix.m[0][0]) + (float)(v10 * Matrix.m[0][1]))
              + (float)(v11 * Matrix.m[0][2]))
      + (float)(w * Matrix.m[0][3]);
  v14 = (float)((float)((float)(this->texture.UAxis.x * Matrix.m[1][0]) + (float)(v10 * Matrix.m[1][1]))
              + (float)(v11 * Matrix.m[1][2]))
      + (float)(w * Matrix.m[1][3]);
  v15 = this->texture.UAxis.x * Matrix.m[3][0];
  Axis.y = (float)((float)((float)(this->texture.UAxis.x * Matrix.m[2][0]) + (float)(v10 * Matrix.m[2][1]))
                 + (float)(v11 * Matrix.m[2][2]))
         + (float)(w * Matrix.m[2][3]);
  Axis.z = (float)((float)(v15 + (float)(v10 * Matrix.m[3][1])) + (float)(v11 * Matrix.m[3][2]))
         + (float)(w * Matrix.m[3][3]);
  v16 = this->texture.VAxis.y;
  v17 = this->texture.VAxis.x;
  v18 = this->texture.VAxis.z;
  v19 = this->texture.VAxis.w;
  v31 = (float)((float)((float)(v17 * Matrix.m[0][0]) + (float)(v16 * Matrix.m[0][1])) + (float)(v18 * Matrix.m[0][2]))
      + (float)(v19 * Matrix.m[0][3]);
  VAxis.x = (float)((float)((float)(v17 * Matrix.m[1][0]) + (float)(v16 * Matrix.m[1][1]))
                  + (float)(v18 * Matrix.m[1][2]))
          + (float)(v19 * Matrix.m[1][3]);
  v20 = v16 * Matrix.m[2][1];
  v21 = v17 * Matrix.m[2][0];
  v22 = (float)(v17 * Matrix.m[3][0]) + (float)(v16 * Matrix.m[3][1]);
  this->texture.UAxis.z = Axis.y;
  v23 = v21 + v20;
  this->texture.UAxis.w = Axis.z;
  v24 = v31;
  v25 = v18 * Matrix.m[2][2];
  v26 = v18 * Matrix.m[3][2];
  this->texture.UAxis.x = v13;
  this->texture.UAxis.y = v14;
  v27 = v23 + v25;
  v28 = v19 * Matrix.m[2][3];
  v29 = v19 * Matrix.m[3][3];
  this->texture.VAxis.x = v24;
  this->texture.VAxis.y = VAxis.x;
  this->texture.VAxis.z = v27 + v28;
  this->texture.VAxis.w = (float)(v22 + v26) + v29;
}

//------------------------------------------------------------------------------
// Address: 0x10126100
// Name: public: void CMapFace::CalcPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::CalcPlane(CMapFace *this)
{
  this->plane.normal = *GetNormalFromPoints(
                          p0: this->plane.planepts,
                          p1: &this->plane.planepts[1],
                          p2: &this->plane.planepts[2]);
  this->plane.dist = (float)((float)(this->plane.planepts[0].y * this->plane.normal.y)
                           + (float)(this->plane.normal.x * this->plane.planepts[0].x))
                   + (float)(this->plane.planepts[0].z * this->plane.normal.z);
}

//------------------------------------------------------------------------------
// Address: 0x10126180
// Name: public: void CMapFace::CalcPlaneFromFacePoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::CalcPlaneFromFacePoints(CMapFace *this)
{
  Vector *Points; // eax

  if ( this->nPoints >= 3 )
  {
    Points = this->Points;
    if ( Points != nullptr )
    {
      qmemcpy(this->plane.planepts, Points, sizeof(this->plane.planepts));
      CMapFace::CalcPlane(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101261E0
// Name: public: unsigned int CMapFace::AllocatePoints(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::AllocatePoints(CMapFace *this, int _nPoints)
{
  Vector *Points; // eax
  int nPoints; // ecx
  int v5; // eax
  Vector2D *m_pLightmapCoords; // [esp-Ch] [ebp-24h]
  Vector2D *m_pTextureCoords; // [esp-8h] [ebp-20h]

  Points = this->Points;
  if ( Points != nullptr )
  {
    nPoints = this->nPoints;
    if ( _nPoints == nPoints )
    {
      v5 = 7 * nPoints;
      return 4 * v5;
    }
    operator delete(p: Points);
    m_pTextureCoords = this->m_pTextureCoords;
    this->Points = nullptr;
    operator delete(p: m_pTextureCoords);
    m_pLightmapCoords = this->m_pLightmapCoords;
    this->m_pTextureCoords = nullptr;
    operator delete(p: m_pLightmapCoords);
    this->m_pLightmapCoords = nullptr;
  }
  this->nPoints = _nPoints;
  if ( _nPoints == 0 )
    return 0;
  this->Points = (Vector *)operator new[](nSize: 12 * _nPoints);
  this->m_pTextureCoords = (Vector2D *)operator new[](nSize: 8 * this->nPoints);
  this->m_pLightmapCoords = (Vector2D *)operator new[](nSize: 8 * this->nPoints);
  v5 = 7 * this->nPoints;
  return 4 * v5;
}

//------------------------------------------------------------------------------
// Address: 0x10126330
// Name: public: int CMapFace::CheckFace(class CCheckFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::CheckFace(CMapFace *this, CCheckFaceInfo *pInfo)
{
  int result; // eax
  float *p_z; // ebx
  int v5; // edi
  float *v6; // esi
  int v7; // edx
  float *v8; // ecx
  int _4; // [esp+4h] [ebp+0h] BYREF

  result = CheckFace(
             a1: (int)&_4,
             Points: this->Points,
             nPoints: this->nPoints,
             pNormal: &this->plane.normal,
             dist: this->plane.dist,
             pInfo);
  if ( result != 0 )
  {
    p_z = &this->plane.planepts[0].z;
    v5 = 0;
    v6 = &this->plane.planepts[0].z;
    while ( 2 )
    {
      v7 = 0;
      v8 = p_z;
      do
      {
        if ( v5 != v7 && *(v8 - 2) == *(v6 - 2) && *(v8 - 1) == *(v6 - 1) && *v8 == *v6 )
        {
          if ( pInfo != nullptr )
            strcpy(pInfo->szDescription, "face has duplicate plane points");
          return 0;
        }
        ++v7;
        v8 += 3;
      }
      while ( v7 < 3 );
      ++v5;
      v6 += 3;
      if ( v5 < 3 )
        continue;
      break;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10126420
// Name: public: void CMapFace::InitializeQuakeStyleTextureAxes(class Vector4D __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::InitializeQuakeStyleTextureAxes(CMapFace *this, Vector4D *UAxis, Vector4D *VAxis)
{
  float v3; // xmm0_4
  int v4; // eax
  float y; // xmm1_4
  float x; // xmm3_4
  float z; // xmm4_4
  int v8; // eax
  double v9; // st7

  v3 = 0.0;
  v4 = 0;
  if ( (_S2_7 & 1) == 0 )
  {
    _S2_7 |= 1u;
    baseaxis[0].x = 0.0;
    dword_107B1C0C = 0;
    dword_107B1C10 = 1065353216;
    dword_107B1C14 = 1065353216;
    dword_107B1C18 = 0;
    dword_107B1C1C = 0;
    dword_107B1C20 = 0;
    dword_107B1C24 = -1082130432;
    dword_107B1C28 = 0;
    dword_107B1C2C = 0;
    dword_107B1C30 = 0;
    dword_107B1C34 = -1082130432;
    dword_107B1C38 = 1065353216;
    dword_107B1C3C = 0;
    dword_107B1C40 = 0;
    dword_107B1C44 = 0;
    dword_107B1C48 = -1082130432;
    dword_107B1C4C = 0;
    dword_107B1C50 = 1065353216;
    dword_107B1C54 = 0;
    dword_107B1C58 = 0;
    dword_107B1C5C = 0;
    dword_107B1C60 = 1065353216;
    dword_107B1C64 = 0;
    dword_107B1C68 = 0;
    dword_107B1C6C = 0;
    dword_107B1C70 = -1082130432;
    dword_107B1C74 = -1082130432;
    dword_107B1C78 = 0;
    dword_107B1C7C = 0;
    dword_107B1C80 = 0;
    dword_107B1C84 = 1065353216;
    dword_107B1C88 = 0;
    dword_107B1C8C = 0;
    dword_107B1C90 = 0;
    dword_107B1C94 = -1082130432;
    dword_107B1C98 = 0;
    dword_107B1C9C = 1065353216;
    dword_107B1CA0 = 0;
    dword_107B1CA4 = 1065353216;
    dword_107B1CA8 = 0;
    dword_107B1CAC = 0;
    dword_107B1CB0 = 0;
    dword_107B1CB4 = 0;
    dword_107B1CB8 = -1082130432;
    dword_107B1CBC = 0;
    dword_107B1CC0 = -1082130432;
    dword_107B1CC4 = 0;
    dword_107B1CC8 = 1065353216;
    dword_107B1CCC = 0;
    dword_107B1CD0 = 0;
    dword_107B1CD4 = 0;
    dword_107B1CD8 = 0;
    dword_107B1CDC = -1082130432;
  }
  y = this->plane.normal.y;
  x = this->plane.normal.x;
  z = this->plane.normal.z;
  if ( (float)((float)((float)(y * *(float *)&dword_107B1C0C) + (float)(x * baseaxis[0].x))
             + (float)(z * *(float *)&dword_107B1C10)) > 0.0 )
    v3 = (float)((float)(this->plane.normal.y * *(float *)&dword_107B1C0C)
               + (float)(this->plane.normal.x * baseaxis[0].x))
       + (float)(this->plane.normal.z * *(float *)&dword_107B1C10);
  if ( (float)((float)((float)(y * *(float *)&dword_107B1C30) + (float)(x * *(float *)&dword_107B1C2C))
             + (float)(z * *(float *)&dword_107B1C34)) > v3 )
  {
    v3 = (float)((float)(y * *(float *)&dword_107B1C30) + (float)(x * *(float *)&dword_107B1C2C))
       + (float)(z * *(float *)&dword_107B1C34);
    v4 = 1;
  }
  if ( (float)((float)((float)(y * *(float *)&dword_107B1C54) + (float)(x * *(float *)&dword_107B1C50))
             + (float)(z * *(float *)&dword_107B1C58)) > v3 )
  {
    v3 = (float)((float)(y * *(float *)&dword_107B1C54) + (float)(x * *(float *)&dword_107B1C50))
       + (float)(z * *(float *)&dword_107B1C58);
    v4 = 2;
  }
  if ( (float)((float)((float)(y * *(float *)&dword_107B1C78) + (float)(x * *(float *)&dword_107B1C74))
             + (float)(z * *(float *)&dword_107B1C7C)) > v3 )
  {
    v3 = (float)((float)(y * *(float *)&dword_107B1C78) + (float)(x * *(float *)&dword_107B1C74))
       + (float)(z * *(float *)&dword_107B1C7C);
    v4 = 3;
  }
  if ( (float)((float)((float)(y * *(float *)&dword_107B1C9C) + (float)(x * *(float *)&dword_107B1C98))
             + (float)(z * *(float *)&dword_107B1CA0)) > v3 )
  {
    v3 = (float)((float)(y * *(float *)&dword_107B1C9C) + (float)(x * *(float *)&dword_107B1C98))
       + (float)(z * *(float *)&dword_107B1CA0);
    v4 = 4;
  }
  if ( (float)((float)((float)(y * *(float *)&dword_107B1CC0) + (float)(x * *(float *)&dword_107B1CBC))
             + (float)(z * *(float *)&dword_107B1CC4)) > v3 )
    v4 = 5;
  v8 = 18 * v4;
  v9 = *(float *)((char *)&dword_107B1C14 + 2 * v8);
  v8 *= 2;
  UAxis->x = v9;
  UAxis->y = *(float *)((char *)&dword_107B1C18 + v8);
  UAxis->z = *(float *)((char *)&dword_107B1C1C + v8);
  VAxis->x = *(float *)((char *)&dword_107B1C20 + v8);
  VAxis->y = *(float *)((char *)&dword_107B1C24 + v8);
  VAxis->z = *(float *)((char *)&dword_107B1C28 + v8);
}

//------------------------------------------------------------------------------
// Address: 0x101267C0
// Name: public: void CMapFace::RenderUnlit(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::RenderUnlit(CMapFace *this, bool enable)
{
  *((_BYTE *)this + 432) ^= (*((_BYTE *)this + 432) ^ (2 * enable)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x101267E0
// Name: void Modulate(class Color __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Modulate(Color *pColor, float f)
{
  pColor->_color[0] = (int)(float)((float)pColor->_color[0] * f);
  pColor->_color[1] = (int)(float)((float)pColor->_color[1] * f);
  pColor->_color[2] = (int)(float)((float)pColor->_color[2] * f);
}

//------------------------------------------------------------------------------
// Address: 0x10126830
// Name: ModeUsesTextureCoords
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall ModeUsesTextureCoords@<eax>(EditorRenderMode_t mode@<eax>)
{
  return mode == RENDER_MODE_TEXTURED
      || mode == RENDER_MODE_LIGHTMAP_GRID
      || mode == RENDER_MODE_TEXTURED_SHADED
      || mode == RENDER_MODE_LIGHT_PREVIEW2
      || mode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED;
}

//------------------------------------------------------------------------------
// Address: 0x10126860
// Name: public: virtual bool CMapFace::ShouldRenderLast(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapFace::ShouldRenderLast(CMapFace *this)
{
  IMaterial *v2; // eax

  if ( this->m_pTexture == nullptr || this->m_pTexture->GetMaterial(this: this->m_pTexture, a2: 1) == nullptr )
    return false;
  v2 = this->m_pTexture->GetMaterial(this: this->m_pTexture, a2: 1);
  return v2->IsTranslucent(this: v2) || this->m_uchAlpha != 0xFF;
}

//------------------------------------------------------------------------------
// Address: 0x101268C0
// Name: OpaqueFacesLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl OpaqueFacesLessFunc(const MapFaceRender_t *s1, const MapFaceRender_t *s2)
{
  EditorRenderMode_t m_RenderMode; // eax
  int v3; // ecx
  EditorRenderMode_t v4; // eax
  int v5; // eax

  m_RenderMode = s1->m_RenderMode;
  if ( m_RenderMode == RENDER_MODE_WIREFRAME )
    v3 = 2;
  else
    v3 = m_RenderMode == RENDER_MODE_SELECTION_OVERLAY;
  v4 = s2->m_RenderMode;
  if ( v4 == RENDER_MODE_WIREFRAME )
    v5 = 2;
  else
    v5 = v4 == RENDER_MODE_SELECTION_OVERLAY;
  if ( v3 < v5 )
    return true;
  if ( v3 <= v5 )
    return s1->m_pTexture < s2->m_pTexture;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10126920
// Name: public: void CMapFace::RenderVertices(class CRender __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::RenderVertices(CMapFace *this, CRender *pRender)
{
  int v3; // edi
  int v4; // ebx

  v3 = 0;
  if ( this->nPoints > 0 )
  {
    v4 = 0;
    do
    {
      CRender::DrawHandle(this: pRender, vCenter: &this->Points[v4], vOffset: nullptr);
      ++v3;
      ++v4;
    }
    while ( v3 < this->nPoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126960
// Name: protected: static enum ChunkFileResult_t CMapFace::LoadDispInfoCallback(class CChunkFile __near *,class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapFace::LoadDispInfoCallback(CChunkFile *pFile, CMapFace *pFace)
{
  CEditDispMgr *v2; // eax
  int v3; // edi
  CEditDispMgr *v4; // eax
  CMapDisp *v5; // esi
  ChunkFileResult_t result; // eax
  CEditDispMgr *v7; // eax
  CMapWorld *ActiveWorld; // eax
  IWorldEditDispMgr *m_pWorldDispMgr; // ecx

  SignalUpdate(ev: 0);
  v2 = EditDispMgr();
  v3 = v2->Create(this: v2);
  v4 = EditDispMgr();
  v5 = v4->GetDisp(this: v4, a2: v3);
  result = CMapDisp::LoadVMF(this: v5, pFile);
  if ( result == ChunkFile_Ok )
  {
    v5->SetParent(this: v5, a2: pFace);
    if ( pFace->m_DispHandle != 0xFFFF )
    {
      v7 = EditDispMgr();
      v7->Destroy(this: v7, a2: pFace->m_DispHandle);
    }
    pFace->m_DispHandle = v3;
    ActiveWorld = GetActiveWorld();
    if ( ActiveWorld != nullptr )
    {
      m_pWorldDispMgr = ActiveWorld->m_pWorldDispMgr;
      if ( m_pWorldDispMgr != nullptr )
        m_pWorldDispMgr->AddToWorld(this: m_pWorldDispMgr, a2: v3);
    }
    return ChunkFile_Ok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10126A00
// Name: protected: static enum ChunkFileResult_t CMapFace::LoadKeyCallback(char const __near *,char const __near *,struct LoadFace_t __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CMapFace::LoadKeyCallback(const char *szKey, const char *szValue, LoadFace_t *pLoadFace)
{
  CMapFace *pFace; // esi
  int v5; // eax

  SignalUpdate(ev: 0);
  pFace = pLoadFace->pFace;
  if ( _V_stricmp(s1: szKey, s2: "id") == 0 )
  {
    CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pFace->m_nFaceID);
    return false;
  }
  if ( _V_stricmp(s1: szKey, s2: "rotation") == 0 )
  {
    pFace->texture.rotate = atof(nptr: szValue);
    return false;
  }
  if ( _V_stricmp(s1: szKey, s2: "plane") == 0 )
    return sscanf(
             string: szValue,
             format: "(%f %f %f) (%f %f %f) (%f %f %f)",
             pFace->plane.planepts,
             &pFace->plane.planepts[0].y,
             &pFace->plane.planepts[0].z,
             &pFace->plane.planepts[1],
             &pFace->plane.planepts[1].y,
             &pFace->plane.planepts[1].z,
             &pFace->plane.planepts[2],
             &pFace->plane.planepts[2].y,
             &pFace->plane.planepts[2].z) != 9;
  if ( _V_stricmp(s1: szKey, s2: "material") == 0 )
  {
    strcpy(pLoadFace->szTexName, szValue);
    return false;
  }
  if ( _V_stricmp(s1: szKey, s2: "uaxis") == 0 )
  {
    v5 = sscanf(
           string: szValue,
           format: "[%f %f %f %f] %f",
           &pFace->texture.UAxis,
           &pFace->texture.UAxis.y,
           &pFace->texture.UAxis.z,
           &pFace->texture.UAxis.w,
           pFace->texture.scale);
    return v5 != 5;
  }
  if ( _V_stricmp(s1: szKey, s2: "vaxis") == 0 )
  {
    v5 = sscanf(
           string: szValue,
           format: "[%f %f %f %f] %f",
           &pFace->texture.VAxis,
           &pFace->texture.VAxis.y,
           &pFace->texture.VAxis.z,
           &pFace->texture.VAxis.w,
           &pFace->texture.scale[1]);
    return v5 != 5;
  }
  if ( _V_stricmp(s1: szKey, s2: "lightmapscale") == 0 )
  {
    pFace->texture.nLightmapScale = atoi(nptr: szValue);
    return false;
  }
  if ( _V_stricmp(s1: szKey, s2: "smoothing_groups") == 0 )
    pFace->m_fSmoothingGroups = atoi(nptr: szValue);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10126C00
// Name: public: void CMapFace::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::OnAddToWorld(CMapFace *this, CMapWorld *pWorld)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  SignalUpdate(ev: 0);
  if ( this->m_DispHandle != 0xFFFF )
  {
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    if ( ActiveWorldEditDispManager != nullptr )
      ActiveWorldEditDispManager->AddToWorld(this: ActiveWorldEditDispManager, a2: this->m_DispHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126C40
// Name: public: void CMapFace::OnRemoveFromWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::OnRemoveFromWorld(CMapFace *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  SignalUpdate(ev: 0);
  if ( this->m_DispHandle != 0xFFFF )
  {
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    if ( ActiveWorldEditDispManager != nullptr )
      ActiveWorldEditDispManager->RemoveFromWorld(this: ActiveWorldEditDispManager, a2: this->m_DispHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126C80
// Name: public: static void CMapFace::SetShowSelection(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::SetShowSelection(bool bShowSelection)
{
  CMapFace::m_bShowFaceSelection = bShowSelection;
}

//------------------------------------------------------------------------------
// Address: 0x10126C90
// Name: public: void CMapFace::SetTextureCoords(int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::SetTextureCoords(CMapFace *this, int nPoint, float u, float v)
{
  if ( nPoint < this->nPoints )
  {
    this->m_pTextureCoords[nPoint].x = u;
    this->m_pTextureCoords[nPoint].y = v;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126CD0
// Name: public: unsigned int CMapFace::GetDataSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::GetDataSize(CMapFace *this)
{
  int v2; // esi
  CEditDispMgr *v3; // eax
  int v4; // eax

  v2 = 28 * this->nPoints + 444;
  if ( this->m_DispHandle == 0xFFFF )
    return 28 * this->nPoints + 444;
  v3 = EditDispMgr();
  v4 = (int)v3->GetDisp(this: v3, a2: this->m_DispHandle);
  return v2 + ((1 << *(_DWORD *)(v4 + 36)) + 1) * ((1 << *(_DWORD *)(v4 + 36)) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10126D30
// Name: public: bool CMapFace::GetRender2DBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapFace::GetRender2DBox(CMapFace *this, Vector *boundMin, Vector *boundMax)
{
  int v4; // edi
  int v5; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4

  if ( this->nPoints == 0 )
    return 0;
  boundMin->z = 99999.0;
  boundMin->y = 99999.0;
  boundMin->x = 99999.0;
  v4 = 0;
  boundMax->z = -99999.0;
  boundMax->y = -99999.0;
  boundMax->x = -99999.0;
  if ( this->nPoints > 0 )
  {
    v5 = 0;
    do
    {
      x = this->Points[v5].x;
      if ( boundMin->x > x )
        boundMin->x = x;
      y = this->Points[v5].y;
      if ( boundMin->y > y )
        boundMin->y = y;
      z = this->Points[v5].z;
      if ( boundMin->z > z )
        boundMin->z = z;
      v9 = this->Points[v5].x;
      if ( v9 > boundMax->x )
        boundMax->x = v9;
      v10 = this->Points[v5].y;
      if ( v10 > boundMax->y )
        boundMax->y = v10;
      v11 = this->Points[v5].z;
      if ( v11 > boundMax->z )
        boundMax->z = v11;
      ++v4;
      ++v5;
    }
    while ( v4 < this->nPoints );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10126E40
// Name: public: bool CMapFace::GetCullBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapFace::GetCullBox(CMapFace *this, Vector *boundMin, Vector *boundMax)
{
  char result; // al
  CEditDispMgr *v5; // eax
  float *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4

  result = CMapFace::GetRender2DBox(this, boundMin, boundMax);
  if ( result != 0 )
  {
    if ( this->m_DispHandle != 0xFFFF )
    {
      v5 = EditDispMgr();
      v6 = (float *)v5->GetDisp(this: v5, a2: this->m_DispHandle);
      v7 = v6[266];
      v8 = v6[267];
      v9 = v6[268];
      v10 = v6[269];
      v11 = v6[270];
      v12 = v6[271];
      if ( boundMin->x > v7 )
        boundMin->x = v7;
      if ( boundMin->y > v8 )
        boundMin->y = v8;
      if ( boundMin->z > v9 )
        boundMin->z = v9;
      if ( v7 > boundMax->x )
        boundMax->x = v7;
      if ( v8 > boundMax->y )
        boundMax->y = v8;
      if ( v9 > boundMax->z )
        boundMax->z = v9;
      if ( boundMin->x > v10 )
        boundMin->x = v10;
      if ( boundMin->y > v11 )
        boundMin->y = v11;
      if ( boundMin->z > v12 )
        boundMin->z = v12;
      if ( v10 > boundMax->x )
        boundMax->x = v10;
      if ( v11 > boundMax->y )
        boundMax->y = v11;
      if ( v12 > boundMax->z )
        boundMax->z = v12;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10126F60
// Name: public: bool CMapFace::TraceLine(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapFace::TraceLine(
        CMapFace *this,
        Vector *HitPos,
        Vector *HitNormal,
        const Vector *Start,
        const Vector *End)
{
  CEditDispMgr *v6; // eax
  CMapDisp *v7; // eax
  float x; // xmm1_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float Starta; // [esp+14h] [ebp+10h]

  if ( this->m_DispHandle == 0xFFFF )
  {
    x = Start->x;
    y = End->y;
    z = End->z;
    Starta = End->x - Start->x;
    LODWORD(v13) = COERCE_UNSIGNED_INT(
                     (float)((float)(this->plane.normal.x * Starta)
                           + (float)((float)(y - Start->y) * this->plane.normal.y))
                   + (float)((float)(z - Start->z) * this->plane.normal.z))
                 ^ _mask__NegFloat_;
    if ( v13 == 0.0 )
    {
      return 0;
    }
    else
    {
      v14 = (float)((float)((float)((float)(this->plane.normal.x * x) + (float)(this->plane.normal.y * Start->y))
                          + (float)(this->plane.normal.z * Start->z))
                  - this->plane.dist)
          / v13;
      v15 = Start->y;
      v16 = y - v15;
      v17 = Start->z;
      HitPos->x = x + (float)(Starta * v14);
      HitPos->y = v15 + (float)(v16 * v14);
      HitPos->z = v17 + (float)((float)(z - v17) * v14);
      *HitNormal = this->plane.normal;
      return 1;
    }
  }
  else
  {
    v6 = EditDispMgr();
    v7 = v6->GetDisp(this: v6, a2: this->m_DispHandle);
    return CMapDisp::TraceLine(this: v7, vecHitPos: HitPos, vecHitNormal: HitNormal, vecRayStart: Start, vecRayEnd: End);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101270B0
// Name: public: bool CMapFace::TraceLineInside(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapFace::TraceLineInside(
        CMapFace *this,
        Vector *HitPos,
        Vector *HitNormal,
        const Vector *Start,
        const Vector *End,
        bool bNoDisp)
{
  CEditDispMgr *v7; // eax
  CMapDisp *v8; // eax
  float y; // xmm1_4
  float x; // xmm4_4
  float z; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  int nPoints; // ebx
  int v20; // eax
  int i; // edi
  int v22; // edx
  Vector *Points; // ecx
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  Vector *v29; // ecx
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  int v34; // ecx
  PLANE edgePlane; // [esp+4h] [ebp-40h] BYREF
  float v36; // [esp+38h] [ebp-Ch]
  float v37; // [esp+40h] [ebp-4h]
  float Starta; // [esp+54h] [ebp+10h]
  float bNoDispa; // [esp+5Ch] [ebp+18h]
  int bNoDispb; // [esp+5Ch] [ebp+18h]

  if ( this->m_DispHandle == 0xFFFF || bNoDisp )
  {
    y = this->plane.normal.y;
    x = Start->x;
    z = End->z;
    bNoDispa = this->plane.normal.x;
    Starta = this->plane.normal.z;
    v14 = (float)((float)((float)(bNoDispa * x) + (float)(y * Start->y)) + (float)(Starta * Start->z))
        - this->plane.dist;
    v36 = End->x - x;
    v15 = End->y;
    LODWORD(v16) = COERCE_UNSIGNED_INT(
                     (float)((float)(y * (float)(v15 - Start->y)) + (float)(bNoDispa * v36))
                   + (float)(Starta * (float)(z - Start->z)))
                 ^ _mask__NegFloat_;
    v37 = z - Start->z;
    if ( v16 != 0.0 )
      v14 = -(float)(v14
                   / (float)((float)((float)(y * (float)(v15 - Start->y)) + (float)(bNoDispa * v36))
                           + (float)(Starta * (float)(z - Start->z))));
    v17 = Start->y + (float)((float)(v15 - Start->y) * v14);
    v18 = Start->z + (float)((float)(z - Start->z) * v14);
    HitPos->x = x + (float)(v36 * v14);
    HitPos->y = v17;
    HitPos->z = v18;
    nPoints = this->nPoints;
    if ( nPoints <= 0 )
    {
      return 1;
    }
    else
    {
      v20 = 2;
      bNoDispb = 2;
      for ( i = 0; ; ++i )
      {
        v22 = (v20 - 1) % nPoints;
        Points = this->Points;
        v24 = Points[v22].y - Points[i].y;
        v25 = Points[v22].z - Points[i].z;
        v26 = Points[v22].x - Points[i].x;
        v27 = (float)(this->plane.normal.x * v25) - (float)(this->plane.normal.z * v26);
        v28 = (float)(this->plane.normal.y * v26) - (float)(this->plane.normal.x * v24);
        edgePlane.normal.x = (float)(this->plane.normal.z * v24) - (float)(this->plane.normal.y * v25);
        edgePlane.normal.y = v27;
        edgePlane.normal.z = v28;
        VectorNormalize(vec: &edgePlane.normal);
        nPoints = this->nPoints;
        v29 = this->Points;
        v30 = edgePlane.normal.x;
        v31 = edgePlane.normal.y;
        v32 = edgePlane.normal.z;
        v33 = (float)((float)(v29[i].y * edgePlane.normal.y) + (float)(edgePlane.normal.x * v29[i].x))
            + (float)(v29[i].z * edgePlane.normal.z);
        edgePlane.dist = v33;
        if ( (float)((float)((float)((float)(v29[bNoDispb % nPoints].y * edgePlane.normal.y)
                                   + (float)(v29[bNoDispb % nPoints].x * edgePlane.normal.x))
                           + (float)(v29[bNoDispb % nPoints].z * edgePlane.normal.z))
                   - v33) > 0.0 )
        {
          v30 = -edgePlane.normal.x;
          v31 = -edgePlane.normal.y;
          v32 = -edgePlane.normal.z;
          v33 = -v33;
        }
        if ( (float)((float)((float)((float)(v31 * HitPos->y) + (float)(HitPos->x * v30)) + (float)(HitPos->z * v32))
                   - v33) > 0.0 )
          break;
        v20 = bNoDispb + 1;
        v34 = bNoDispb++ - 1;
        if ( v34 >= nPoints )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    v7 = EditDispMgr();
    v8 = v7->GetDisp(this: v7, a2: this->m_DispHandle);
    return CMapDisp::TraceLine(this: v8, vecHitPos: HitPos, vecHitNormal: HitNormal, vecRayStart: Start, vecRayEnd: End);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101273D0
// Name: public: void CMapFace::AddSmoothingGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::AddSmoothingGroup(CMapFace *this, char iGroup)
{
  this->m_fSmoothingGroups |= 1 << (iGroup - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101273F0
// Name: public: void CMapFace::RemoveSmoothingGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::RemoveSmoothingGroup(CMapFace *this, char iGroup)
{
  this->m_fSmoothingGroups &= ~(1 << (iGroup - 1));
}

//------------------------------------------------------------------------------
// Address: 0x10127410
// Name: public: bool CMapFace::InSmoothingGroup(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapFace::InSmoothingGroup(CMapFace *this, char iGroup)
{
  return ((1 << (iGroup - 1)) & this->m_fSmoothingGroups) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10127430
// Name: public: CMapFace::~CMapFace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::~CMapFace(CMapFace *this)
{
  DetailObjects *m_pDetailObjects; // edi
  CMapFace::TangentSpaceAxes_t *m_pTangentAxes; // eax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  CEditDispMgr *v5; // eax
  Vector2D *m_pLightmapCoords; // [esp-10h] [ebp-1Ch]
  Vector2D *m_pTextureCoords; // [esp-Ch] [ebp-18h]

  this->__vftable = (CMapFace_vtbl *)&CMapFace::`vftable';
  SignalUpdate(ev: 0);
  operator delete(p: this->Points);
  m_pTextureCoords = this->m_pTextureCoords;
  this->Points = nullptr;
  operator delete(p: m_pTextureCoords);
  m_pLightmapCoords = this->m_pLightmapCoords;
  this->m_pTextureCoords = nullptr;
  operator delete(p: m_pLightmapCoords);
  m_pDetailObjects = this->m_pDetailObjects;
  this->m_pLightmapCoords = nullptr;
  if ( m_pDetailObjects != nullptr )
  {
    DetailObjects::~DetailObjects(this: m_pDetailObjects);
    operator delete(p: m_pDetailObjects);
  }
  m_pTangentAxes = this->m_pTangentAxes;
  this->m_pDetailObjects = nullptr;
  if ( m_pTangentAxes != nullptr )
  {
    operator delete(p: m_pTangentAxes);
    this->m_pTangentAxes = nullptr;
  }
  if ( this->m_DispHandle != 0xFFFF )
  {
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    if ( ActiveWorldEditDispManager != nullptr )
      ActiveWorldEditDispManager->RemoveFromWorld(this: ActiveWorldEditDispManager, a2: this->m_DispHandle);
    if ( this->m_DispHandle != 0xFFFF )
    {
      v5 = EditDispMgr();
      v5->Destroy(this: v5, a2: this->m_DispHandle);
    }
    this->m_DispHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127520
// Name: protected: void CMapFace::ComputeColor(class CRender3D __near *,bool,enum SelectionState_t,bool,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::ComputeColor(
        CMapFace *this,
        CRender3D *pRender,
        bool bRenderAsSelected,
        SelectionState_t faceSelectionState,
        bool ignoreLighting,
        Color *pColor)
{
  EditorRenderMode_t m_eCurrentRenderMode; // ebx
  float v8; // xmm0_4
  int nLightmapScale; // edi
  unsigned __int8 v10; // al
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  unsigned __int8 m_uchAlpha; // al
  unsigned __int8 b; // cl
  unsigned __int8 g; // dl
  float faceSelectionStatea; // [esp+20h] [ebp+14h]

  m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
  *(_WORD *)&pColor->_color[1] = -1;
  pColor->_color[0] = -1;
  pColor->_color[3] = this->m_uchAlpha;
  if ( ignoreLighting )
  {
    v8 = 1.0;
  }
  else
  {
    faceSelectionStatea = CRender3D::LightPlane(this: pRender, Normal: &this->plane.normal);
    v8 = faceSelectionStatea;
  }
  switch ( m_eCurrentRenderMode )
  {
    case RENDER_MODE_WIREFRAME:
      if ( bRenderAsSelected )
      {
        *(_WORD *)pColor->_color = -1;
        pColor->_color[2] = 0;
      }
      else
      {
        m_uchAlpha = this->m_uchAlpha;
        b = this->b;
        g = this->g;
        pColor->_color[0] = this->r;
        pColor->_color[1] = g;
        pColor->_color[2] = b;
        pColor->_color[3] = m_uchAlpha;
      }
      break;
    case RENDER_MODE_FLAT:
    case RENDER_MODE_TRANSLUCENT_FLAT:
      if ( bRenderAsSelected )
      {
        *(_WORD *)pColor->_color = 220;
        pColor->_color[2] = 0;
      }
      else
      {
        v10 = this->m_uchAlpha;
        v11 = this->b;
        v12 = this->g;
        pColor->_color[0] = this->r;
        pColor->_color[1] = v12;
        pColor->_color[2] = v11;
        pColor->_color[3] = v10;
      }
      pColor->_color[0] = (int)(float)((float)pColor->_color[0] * v8);
      pColor->_color[1] = (int)(float)((float)pColor->_color[1] * v8);
      pColor->_color[2] = (int)(float)((float)pColor->_color[2] * v8);
      break;
    case RENDER_MODE_TEXTURED:
    case RENDER_MODE_TEXTURED_SHADED:
    case RENDER_MODE_LIGHT_PREVIEW2:
    case RENDER_MODE_LIGHT_PREVIEW_RAYTRACED:
      pColor->_color[0] = (int)(float)((float)pColor->_color[0] * v8);
      pColor->_color[1] = (int)(float)((float)pColor->_color[1] * v8);
      pColor->_color[2] = (int)(float)((float)pColor->_color[2] * v8);
      break;
    case RENDER_MODE_LIGHTMAP_GRID:
      if ( bRenderAsSelected )
      {
        *(_WORD *)pColor->_color = 220;
        goto LABEL_26;
      }
      nLightmapScale = this->texture.nLightmapScale;
      if ( nLightmapScale <= 16 )
      {
        if ( nLightmapScale < 16 )
          pColor->_color[2] = 100;
      }
      else
      {
        pColor->_color[0] = -106;
      }
      goto LABEL_27;
    case RENDER_MODE_SELECTION_OVERLAY:
      if ( faceSelectionState == SELECT_MULTI_PARTIAL )
      {
        *(_WORD *)&pColor->_color[2] = 16484;
      }
      else if ( faceSelectionState == SELECT_NORMAL || bRenderAsSelected )
      {
        *pColor = (Color)1073742044;
      }
      break;
    case RENDER_MODE_SMOOTHING_GROUP:
      if ( CMapDoc::m_pMapDoc != nullptr
        && ((1 << (LOBYTE(CMapDoc::m_pMapDoc->m_SmoothingGroupVisual) - 1)) & this->m_fSmoothingGroups) != 0 )
      {
LABEL_26:
        pColor->_color[2] = 0;
      }
LABEL_27:
      Modulate(pColor, f: v8);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127750
// Name: protected: void CMapFace::AddFaceVertices(class CMeshBuilder __near &,class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::AddFaceVertices(
        CMapFace *this,
        CMeshBuilder *meshBuilder,
        CRender3D *pRender,
        bool bRenderSelected,
        SelectionState_t faceSelectionState)
{
  bool (__thiscall *GetTransformMatrix)(struct CMapFace *, VMatrix *); // edx
  bool v7; // al
  bool v8; // dl
  int v9; // edx
  int v10; // ecx
  Vector *Points; // eax
  double v13; // st7
  float *v14; // eax
  float *m_pCurrPosition; // ecx
  float *m_pCurrNormal; // ecx
  unsigned __int8 *m_pCurrColor; // eax
  Vector2D *m_pTextureCoords; // eax
  float *v19; // edx
  Vector2D *m_pLightmapCoords; // eax
  float *v21; // ecx
  CMapFace::TangentSpaceAxes_t *m_pTangentAxes; // ecx
  float *v23; // eax
  float *v24; // eax
  Vector *v25; // ecx
  VMatrix frame; // [esp+8h] [ebp-54h] BYREF
  Vector point; // [esp+48h] [ebp-14h] BYREF
  Color color; // [esp+54h] [ebp-8h] BYREF
  bool bHasParent; // [esp+5Bh] [ebp-1h]
  CMeshBuilder *meshBuildera; // [esp+64h] [ebp+8h]
  CRender3D *pRendera; // [esp+68h] [ebp+Ch]
  int bRenderSelecteda; // [esp+6Ch] [ebp+10h]
  int nPoint; // [esp+70h] [ebp+14h]

  GetTransformMatrix = this->GetTransformMatrix;
  color = 0;
  v7 = GetTransformMatrix(this, a2: &frame);
  v8 = (*((_BYTE *)this + 432) & 2) != 0;
  bHasParent = v7;
  CMapFace::ComputeColor(
    this,
    pRender,
    bRenderAsSelected: bRenderSelected,
    faceSelectionState,
    ignoreLighting: v8,
    pColor: &color);
  nPoint = 0;
  if ( this->nPoints > 0 )
  {
    v9 = color._color[2] | ((color._color[1] | ((color._color[0] | (color._color[3] << 8)) << 8)) << 8);
    v10 = 0;
    meshBuildera = (CMeshBuilder *)v9;
    pRendera = nullptr;
    bRenderSelecteda = 0;
    while ( 1 )
    {
      if ( bHasParent )
      {
        VectorTransform(
          in1: (const float *)((char *)&this->Points->x + v10),
          in2: (const matrix3x4_t *)&frame,
          out: &point.x);
        v9 = (int)meshBuildera;
        *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrPosition = point;
      }
      else
      {
        Points = this->Points;
        v13 = *(float *)((char *)&Points->x + v10);
        v14 = (float *)((char *)&Points->x + v10);
        m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *m_pCurrPosition = v13;
        m_pCurrPosition[1] = v14[1];
        m_pCurrPosition[2] = v14[2];
      }
      m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
      *m_pCurrNormal = this->plane.normal.x;
      m_pCurrColor = meshBuilder->m_VertexBuilder.m_pCurrColor;
      m_pCurrNormal[1] = this->plane.normal.y;
      m_pCurrNormal[2] = this->plane.normal.z;
      *(_DWORD *)m_pCurrColor = v9;
      m_pTextureCoords = this->m_pTextureCoords;
      v19 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v19 = m_pTextureCoords[nPoint].x;
      v19[1] = m_pTextureCoords[nPoint].y;
      m_pLightmapCoords = this->m_pLightmapCoords;
      v21 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
      *v21 = m_pLightmapCoords[nPoint].x;
      v21[1] = m_pLightmapCoords[nPoint].y;
      m_pTangentAxes = this->m_pTangentAxes;
      v23 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pTangentS
                    + meshBuilder->m_VertexBuilder.m_VertexSize_TangentS * meshBuilder->m_VertexBuilder.m_nCurrentVertex);
      *v23 = *(float *)((char *)&pRendera->__vftable + (_DWORD)m_pTangentAxes);
      v23[1] = *(float *)((char *)&pRendera->m_pView + (_DWORD)m_pTangentAxes);
      v23[2] = *(float *)((char *)&pRendera->m_DefaultFont + (_DWORD)m_pTangentAxes);
      v24 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pTangentT
                    + meshBuilder->m_VertexBuilder.m_VertexSize_TangentT * meshBuilder->m_VertexBuilder.m_nCurrentVertex);
      v25 = (Vector *)((char *)&this->m_pTangentAxes->binormal + (unsigned int)pRendera);
      *v24 = v25->x;
      v24[1] = v25->y;
      v24[2] = v25->z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
      bRenderSelecteda += 12;
      pRendera = (CRender3D *)((char *)pRendera + 24);
      if ( ++nPoint >= this->nPoints )
        break;
      v10 = bRenderSelecteda;
      v9 = (int)meshBuildera;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127930
// Name: protected: static void CMapFace::RenderFacesBatch(class CMeshBuilder __near &,class IMesh __near *,class CRender3D __near *,struct MapFaceRender_t __near * __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::RenderFacesBatch(
        CMeshBuilder *meshBuilder,
        IMesh *pMesh,
        CRender3D *pRender,
        MapFaceRender_t **ppFaces,
        int nFaceCount,
        int nVertexCount,
        int nIndexCount,
        bool bWireframe)
{
  __int16 v9; // di
  MapFaceRender_t *v10; // eax
  CMapFace *m_pMapFace; // ebx
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  MaterialPrimitiveType_t m_Type; // ebx
  int m_nVertexCount; // eax
  int nPoints; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  if ( bWireframe )
  {
    v9 = 0;
    CMeshBuilder::Begin(
      this: meshBuilder,
      pMesh,
      type: MATERIAL_LINES,
      nVertexCount,
      nIndexCount,
      pMeshSettings: nullptr);
  }
  else
  {
    CMeshBuilder::Begin(
      this: meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount,
      nIndexCount,
      pMeshSettings: nullptr);
    v9 = 0;
  }
  for ( i = 0; i < nFaceCount; ++i )
  {
    v10 = ppFaces[i];
    m_pMapFace = v10->m_pMapFace;
    CMapFace::AddFaceVertices(
      this: m_pMapFace,
      meshBuilder,
      pRender,
      bRenderSelected: v10->m_RenderSelected,
      faceSelectionState: v10->m_FaceSelectionState);
    v12 = m_pMapFace->nPoints;
    nPoints = v12;
    if ( bWireframe )
    {
      meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                          + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
      meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
      meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
      v13 = 1;
      if ( v12 > 1 )
      {
        do
        {
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                              + v13
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                              + v13
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          LOWORD(v12) = nPoints;
          ++v13;
        }
        while ( v13 < nPoints );
      }
      meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                          + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
      meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
      meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    }
    else
    {
      v14 = 2;
      if ( v12 > 2 )
      {
        do
        {
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                              + v14
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                              - 1;
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                              + v14
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          LOWORD(v12) = nPoints;
          ++v14;
        }
        while ( v14 < nPoints );
      }
    }
    v9 += v12;
  }
  if ( meshBuilder->m_bGenerateIndices )
  {
    m_Type = meshBuilder->m_Type;
    m_nVertexCount = meshBuilder->m_VertexBuilder.m_nVertexCount;
    switch ( m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder->m_IndexBuilder,
      primitiveType: m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder->m_pMesh->UnlockMesh(
    this: meshBuilder->m_pMesh,
    a2: meshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: meshBuilder);
  meshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10127C40
// Name: public: virtual void CMapFace::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::Render2D(CMapFace *this, CRender2D *pRender)
{
  SelectionState_t v3; // eax
  bool v4; // zf
  SelectionState_t v5; // edi
  char v6; // bl
  CCamera *Camera; // eax
  CEditDispMgr *v8; // eax
  CMapDisp *v9; // eax
  Vector maxs; // [esp+Ch] [ebp-3Ch] BYREF
  Vector mins; // [esp+18h] [ebp-30h] BYREF
  Vector vViewNormal; // [esp+24h] [ebp-24h] BYREF
  Vector2D pt; // [esp+30h] [ebp-18h] BYREF
  Vector2D pt2; // [esp+38h] [ebp-10h] BYREF
  SelectionState_t eFaceSelectionState; // [esp+40h] [ebp-8h]
  BOOL bRenderSelected; // [esp+44h] [ebp-4h]

  v3 = this->GetSelectionState(this);
  v4 = this->m_pParent == nullptr;
  v5 = v3;
  eFaceSelectionState = v3;
  if ( !v4 )
    v3 = this->m_pParent->GetSelectionState(this: this->m_pParent);
  v6 = 1;
  LOBYTE(bRenderSelected) = v3 != SELECT_NONE || v5 != SELECT_NONE && CMapFace::m_bShowFaceSelection;
  Camera = CRender::GetCamera(this: pRender);
  CCamera::GetViewForward(this: Camera, ViewForward: &vViewNormal);
  if ( COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)((float)(vViewNormal.y * this->plane.normal.y) + (float)(vViewNormal.x * this->plane.normal.x))
         + (float)(vViewNormal.z * this->plane.normal.z))
       & _mask__AbsFloat_) >= 0.000099999997 )
    v6 = 0;
  if ( this->m_DispHandle == 0xFFFF )
    goto LABEL_17;
  if ( v6 != 0 || bRenderSelected )
  {
    CMapFace::GetRender2DBox(this, boundMin: &mins, boundMax: &maxs);
    CRender::TransformPoint(this: pRender, vClient: &pt, vWorld: &mins);
    CRender::TransformPoint(this: pRender, vClient: &pt2, vWorld: &maxs);
    if ( Options.view2d.bDrawModels != 0
      && ((int)COERCE_FLOAT(COERCE_UNSIGNED_INT(pt2.x - pt.x) & _mask__AbsFloat_)
        + (int)COERCE_FLOAT(COERCE_UNSIGNED_INT(pt2.y - pt.y) & _mask__AbsFloat_) > 50
       || bRenderSelected) )
    {
      v8 = EditDispMgr();
      v9 = v8->GetDisp(this: v8, a2: this->m_DispHandle);
      CMapDisp::Render2D(this: v9, pRender, bIsSelected: bRenderSelected, faceSelectionState: eFaceSelectionState);
      return;
    }
LABEL_17:
    if ( v6 != 0 )
      return;
  }
  CRender::DrawPolyLine(this: pRender, nPoints: this->nPoints, Points: this->Points);
}

//------------------------------------------------------------------------------
// Address: 0x10127DC0
// Name: public: bool CMapFace::AllocTangentSpaceAxes(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapFace::AllocTangentSpaceAxes(CMapFace *this, int count)
{
  CMapFace::TangentSpaceAxes_t *counta; // [esp+18h] [ebp+8h]

  if ( count < 1 )
    return false;
  counta = (CMapFace::TangentSpaceAxes_t *)operator new[](nSize: 24 * count);
  this->m_pTangentAxes = counta;
  return counta != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10127EE0
// Name: public: class CMapFace __near * CMapFace::CopyFrom(class CMapFace const __near *,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall CMapFace::CopyFrom(CMapFace *this, CMapFace *pObject, char dwFlags, bool bUpdateDependencies)
{
  int nPoints; // eax
  CEditDispMgr *v6; // eax
  unsigned __int16 v7; // di
  CEditDispMgr *v8; // eax
  CEditDispMgr *v9; // eax
  CMapDisp *v10; // edi
  CEditDispMgr *v11; // eax
  CMapDisp *v12; // eax
  CEditDispMgr *v13; // eax
  DetailObjects *m_pDetailObjects; // esi

  SignalUpdate(ev: 0);
  if ( pObject != nullptr )
  {
    if ( this->Points != nullptr )
    {
      operator delete(p: this->Points);
      this->Points = nullptr;
    }
    if ( this->m_pTextureCoords != nullptr )
    {
      operator delete(p: this->m_pTextureCoords);
      this->m_pTextureCoords = nullptr;
    }
    if ( this->m_pLightmapCoords != nullptr )
    {
      operator delete(p: this->m_pLightmapCoords);
      this->m_pLightmapCoords = nullptr;
    }
    if ( this->m_pTangentAxes != nullptr )
    {
      operator delete(p: this->m_pTangentAxes);
      this->m_pTangentAxes = nullptr;
    }
    this->nPoints = 0;
    this->m_nFaceID = pObject->m_nFaceID;
    this->m_eSelectionState = pObject->GetSelectionState(this: pObject);
    qmemcpy(&this->texture, &pObject->texture, sizeof(this->texture));
    this->m_pTexture = pObject->m_pTexture;
    *((_BYTE *)this + 432) ^= (*((_BYTE *)this + 432) ^ *((_BYTE *)pObject + 432)) & 1;
    if ( (dwFlags & 2) != 0 )
    {
      this->Points = nullptr;
      nPoints = pObject->nPoints;
      this->nPoints = nPoints;
      if ( pObject->Points != nullptr && nPoints != 0 )
      {
        CMapFace::AllocatePoints(this, _nPoints: nPoints);
        CMapFace::AllocTangentSpaceAxes(this, count: this->nPoints);
        memcpy(dst: (unsigned __int8 *)this->Points, src: (unsigned __int8 *)pObject->Points, count: 12 * this->nPoints);
        memcpy(
          dst: (unsigned __int8 *)this->m_pTextureCoords,
          src: (unsigned __int8 *)pObject->m_pTextureCoords,
          count: 8 * this->nPoints);
        memcpy(
          dst: (unsigned __int8 *)this->m_pLightmapCoords,
          src: (unsigned __int8 *)pObject->m_pLightmapCoords,
          count: 8 * this->nPoints);
        memcpy(
          dst: (unsigned __int8 *)this->m_pTangentAxes,
          src: (unsigned __int8 *)pObject->m_pTangentAxes,
          count: 24 * this->nPoints);
      }
    }
    else
    {
      this->Points = nullptr;
      this->m_pTextureCoords = nullptr;
      this->m_pLightmapCoords = nullptr;
      this->m_pTangentAxes = nullptr;
      this->nPoints = 0;
    }
    if ( (dwFlags & 2) != 0 || (dwFlags & 1) != 0 )
      this->plane = pObject->plane;
    else
      memset(dst: (unsigned __int8 *)&this->plane, value: 0, count: sizeof(this->plane));
    if ( pObject->m_DispHandle == 0xFFFF )
    {
      if ( this->m_DispHandle != 0xFFFF )
      {
        v13 = EditDispMgr();
        v13->Destroy(this: v13, a2: this->m_DispHandle);
      }
      this->m_DispHandle = -1;
    }
    else
    {
      if ( this->m_DispHandle == 0xFFFF )
      {
        v6 = EditDispMgr();
        v7 = v6->Create(this: v6);
        if ( this->m_DispHandle != 0xFFFF )
        {
          v8 = EditDispMgr();
          v8->Destroy(this: v8, a2: this->m_DispHandle);
        }
        this->m_DispHandle = v7;
      }
      v9 = EditDispMgr();
      v10 = v9->GetDisp(this: v9, a2: this->m_DispHandle);
      v10->SetParent(this: v10, a2: this);
      v11 = EditDispMgr();
      v12 = v11->GetDisp(this: v11, a2: pObject->m_DispHandle);
      CMapDisp::CopyFrom(this: v10, pMapDisp: v12, bUpdateDependencies);
    }
    this->r = pObject->r;
    this->g = pObject->g;
    this->b = pObject->b;
    this->m_uchAlpha = pObject->m_uchAlpha;
    *((_BYTE *)this + 432) ^= (*((_BYTE *)this + 432) ^ *((_BYTE *)pObject + 432)) & 2;
    m_pDetailObjects = this->m_pDetailObjects;
    this->m_fSmoothingGroups = pObject->m_fSmoothingGroups;
    if ( m_pDetailObjects != nullptr )
    {
      DetailObjects::~DetailObjects(this: m_pDetailObjects);
      operator delete(p: m_pDetailObjects);
    }
    this->m_pDetailObjects = nullptr;
    DetailObjects::BuildAnyDetailObjects(pMapFace: this);
  }
  CMapFace::UpdateFaceFlags(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101282B0
// Name: protected: void CMapFace::DrawFace(class Color __near &,enum EditorRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::DrawFace(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Color *pColor,
        EditorRenderMode_t mode)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // ebx
  IMesh *v8; // eax
  int v9; // edi
  bool v10; // al
  int v11; // ebx
  int v12; // ecx
  Vector2D *m_pTextureCoords; // edx
  float y; // xmm1_4
  float *v15; // eax
  Vector2D *m_pLightmapCoords; // eax
  float x; // xmm0_4
  float v18; // xmm1_4
  float *v19; // eax
  bool v20; // zf
  Vector *Points; // eax
  int v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // xmm2_4
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // ecx
  CMapFace::TangentSpaceAxes_t *m_pTangentAxes; // ecx
  float *v28; // eax
  float *v29; // eax
  Vector *p_binormal; // ecx
  int m_nVertexCount; // eax
  int nPoints; // [esp-4h] [ebp-25Ch]
  VMatrix frame; // [esp+4h] [ebp-254h] BYREF
  CMeshBuilder meshBuilder; // [esp+44h] [ebp-214h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+22Ch] [ebp-2Ch]
  Vector point; // [esp+230h] [ebp-28h] BYREF
  IMatRenderContext *v37; // [esp+23Ch] [ebp-1Ch]
  IMesh *pMesh; // [esp+240h] [ebp-18h]
  int i; // [esp+244h] [ebp-14h]
  bool hasParent; // [esp+24Bh] [ebp-Dh]
  int v41; // [esp+254h] [ebp-4h]
  bool mode_3; // [esp+267h] [ebp+Fh]

  hasParent = this->GetTransformMatrix(this, a2: &frame);
  if ( mode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED || (this->m_nFaceFlags & 2) == 0 )
  {
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v41 = 0;
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                a1: materials,
                                a2: a3,
                                a3: a2);
    v7 = v6;
    v37 = v6;
    pRenderContext.m_pObject = v6;
    LOBYTE(v41) = 1;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    LOBYTE(v41) = 2;
    v8 = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    nPoints = this->nPoints;
    pMesh = v8;
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v8,
      type: (MaterialPrimitiveType_t)((mode != RENDER_MODE_WIREFRAME) + 5),
      numPrimitives: nPoints);
    v9 = 0;
    if ( this->nPoints > 0 )
    {
      v10 = ModeUsesTextureCoords(mode);
      v11 = 0;
      v12 = 0;
      mode_3 = v10;
      for ( i = 0; ; v12 = i )
      {
        if ( mode_3 )
        {
          m_pTextureCoords = this->m_pTextureCoords;
          y = m_pTextureCoords[v9].y;
          v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = m_pTextureCoords[v9].x;
          v15[1] = y;
          m_pLightmapCoords = this->m_pLightmapCoords;
          x = m_pLightmapCoords[v9].x;
          v18 = m_pLightmapCoords[v9].y;
          v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = x;
          v19[1] = v18;
        }
        v20 = !hasParent;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = pColor->_color[2]
                                                            | ((pColor->_color[1]
                                                              | ((pColor->_color[0] | (pColor->_color[3] << 8)) << 8)) << 8);
        Points = this->Points;
        if ( v20 )
        {
          v22 = *(_DWORD *)((char *)&Points->x + v12);
          v23 = *(_DWORD *)((char *)&Points->y + v12);
          v24 = *(_DWORD *)((char *)&Points->z + v12);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
          *((_DWORD *)m_pCurrPosition + 1) = v23;
          *((_DWORD *)m_pCurrPosition + 2) = v24;
        }
        else
        {
          VectorTransform(
            in1: (const float *)((char *)&Points->x + v12),
            in2: (const matrix3x4_t *)&frame,
            out: &point.x);
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = point;
        }
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = this->plane.normal.x;
        m_pCurrNormal[1] = this->plane.normal.y;
        m_pCurrNormal[2] = this->plane.normal.z;
        m_pTangentAxes = this->m_pTangentAxes;
        v28 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
        *v28 = m_pTangentAxes[v11].tangent.x;
        v28[1] = m_pTangentAxes[v11].tangent.y;
        v28[2] = m_pTangentAxes[v11].tangent.z;
        v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
        p_binormal = &this->m_pTangentAxes[v11].binormal;
        *v29 = p_binormal->x;
        v29[1] = p_binormal->y;
        v29[2] = p_binormal->z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        i += 12;
        ++v9;
        ++v11;
        if ( v9 >= this->nPoints )
          break;
      }
      v7 = v37;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    LOBYTE(v41) = 3;
    v7->EndRender(this: v7);
    LOBYTE(v41) = 0;
    v7->Release(this: v7);
    v41 = 4;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v41 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128640
// Name: protected: static void CMapFace::RenderTextureAxes(class CRender3D __near *,int,class CMapFace __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::RenderTextureAxes(CRender3D *pRender, int nCount, CMapFace **ppFaces)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v6; // esi
  CMapFace *v7; // eax
  float v8; // xmm1_4
  int nPoints; // ecx
  int *p_nPoints; // edx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float *p_x; // eax
  float v14; // xmm0_4
  float *m_pCurrPosition; // eax
  CMapFace *v16; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float *v24; // eax
  CMapFace *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float *v29; // eax
  float v30; // xmm1_4
  float v31; // xmm2_4
  int m_nVertexCount; // eax
  IMatRenderContext *v33; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-20Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-24h]
  IMesh *pMesh; // [esp+1F8h] [ebp-20h]
  IMatRenderContext *v37; // [esp+1FCh] [ebp-1Ch]
  Vector Center; // [esp+200h] [ebp-18h] BYREF
  int v39; // [esp+214h] [ebp-4h]

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v39 = 0;
  v3 = materials->GetRenderContext(this: materials);
  v37 = v3;
  pRenderContext.m_pObject = v3;
  LOBYTE(v39) = 1;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  LOBYTE(v39) = 2;
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  SetPrimitiveType = v4->SetPrimitiveType;
  pMesh = v4;
  SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(
    this: meshBuilder.m_pMesh,
    a2: 4 * nCount,
    a3: 4 * nCount,
    a4: &meshBuilder,
    a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4 * nCount;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(
    this: &meshBuilder.m_VertexBuilder,
    pMesh: v4,
    nMaxVertexCount: 4 * nCount,
    desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( nCount > 0 )
  {
    do
    {
      v7 = ppFaces[v6];
      v8 = 0.0;
      nPoints = v7->nPoints;
      p_nPoints = &v7->nPoints;
      v11 = 0.0;
      v12 = 0.0;
      memset(&Center, 0, sizeof(Center));
      if ( nPoints != 0 )
      {
        if ( nPoints > 0 )
        {
          p_x = &v7->Points->x;
          do
          {
            v8 = v8 + *p_x;
            v11 = v11 + p_x[1];
            v12 = v12 + p_x[2];
            p_x += 3;
            --nPoints;
          }
          while ( nPoints != 0 );
        }
        v14 = 1.0 / (float)*p_nPoints;
        v8 = v8 * v14;
        v11 = v11 * v14;
        v12 = v12 * v14;
        Center.x = v8;
        Center.y = v11;
        Center.z = v12;
      }
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = v8;
      m_pCurrPosition[1] = v11;
      m_pCurrPosition[2] = v12;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
      v16 = ppFaces[v6];
      x = v16->texture.UAxis.x;
      y = v16->texture.UAxis.y;
      z = v16->texture.UAxis.z;
      v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v21 = (float)(y * 10.0) + Center.y;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(x * 10.0) + Center.x;
      v22 = (float)(z * 10.0) + Center.z;
      v20[1] = v21;
      v20[2] = v22;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v23 = Center.x;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
      v24[1] = Center.y;
      v24[2] = Center.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      v25 = ppFaces[v6];
      v26 = v25->texture.VAxis.x;
      v27 = v25->texture.VAxis.y;
      v28 = v25->texture.VAxis.z;
      v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v30 = (float)(v27 * 10.0) + Center.y;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v26 * 10.0) + Center.x;
      v31 = (float)(v28 * 10.0) + Center.z;
      v29[1] = v30;
      v29[2] = v31;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      ++v6;
    }
    while ( v6 < nCount );
    v4 = pMesh;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
  CRender::PopRenderMode(this: pRender);
  LOBYTE(v39) = 3;
  v33 = v37;
  v37->EndRender(this: v37);
  LOBYTE(v39) = 0;
  v33->Release(this: v33);
  v39 = 4;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  v39 = -1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128A80
// Name: public: void CMapFace::Render3DGrid(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapFace::Render3DGrid(CMapFace *this, CRender3D *pRender)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  float v5; // edi
  float v6; // esi
  float *v7; // ecx
  __m128 v8; // xmm3
  float v9; // xmm5_4
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  double v15; // st7
  float x; // xmm6_4
  int nPoints; // ecx
  float v18; // edx
  Vector *Points; // eax
  float v20; // esi
  float v21; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm2_4
  unsigned int v29; // eax
  float v30; // xmm3_4
  int v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  int v38; // eax
  float v39; // xmm2_4
  char v40; // dl
  float v41; // xmm2_4
  int v42; // eax
  float v43; // esi
  Vector v44; // [esp+14h] [ebp-2B8h] BYREF
  float v45[3]; // [esp+20h] [ebp-2ACh] BYREF
  _BYTE Extents_4[556]; // [esp+30h] [ebp-29Ch] OVERLAPPED BYREF
  CMatRenderContextPtr pRenderContext; // [esp+25Ch] [ebp-70h]
  float fDelta[3]; // [esp+260h] [ebp-6Ch]
  Vector PointFound[2]; // [esp+26Ch] [ebp-60h]
  Vector Normal; // [esp+284h] [ebp-48h]
  float fStart; // [esp+290h] [ebp-3Ch]
  Vector Point1; // [esp+294h] [ebp-38h]
  float i; // [esp+2A0h] [ebp-2Ch]
  Vector Point2; // [esp+2A4h] [ebp-28h]
  int v55; // [esp+2B0h] [ebp-1Ch]
  float GridSize; // [esp+2B4h] [ebp-18h]
  int fGridPoint; // [esp+2B8h] [ebp-14h]
  IMesh *pMesh; // [esp+2BCh] [ebp-10h]
  int nPointsFound; // [esp+2C8h] [ebp-4h]

  GridSize = CRender3D::GetGridSize(this: pRender);
  CMapFace::GetFaceExtents(this, Extents: &v44);
  *(float *)&Extents_4[536] = v45[0] - v44.x;
  *(float *)&Extents_4[540] = *(float *)&Extents_4[12] - *(float *)Extents_4;
  *(float *)&Extents_4[544] = *(float *)&Extents_4[40] - *(float *)&Extents_4[28];
  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&Extents_4[44]);
  nPointsFound = 0;
  v3 = materials->GetRenderContext(this: materials);
  v4 = v3;
  LODWORD(Normal.y) = v3;
  *(_DWORD *)&Extents_4[532] = v3;
  LOBYTE(nPointsFound) = 1;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  LOBYTE(nPointsFound) = 2;
  v5 = COERCE_FLOAT((int)v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr));
  v6 = 0.0;
  v7 = v45;
  Point2.x = v5;
  Point2.z = 0.0;
  LODWORD(Point1.y) = v45;
  do
  {
    if ( *(float *)&Extents_4[4 * LODWORD(v6) + 536] != 0.0 )
    {
      v8.m128_i32[0] = 1258291200;
      v9 = *v7;
      PointFound[0].x = (float)(LODWORD(v6) % 3 == 0);
      PointFound[0].y = (float)(LODWORD(v6) % 3 == 1);
      PointFound[0].z = (float)(LODWORD(v6) % 3 == 2);
      v10 = (__m128)0x3F800000u;
      v10.m128_f32[0] = 1.0 / GridSize;
      v11 = v10;
      v11.m128_f32[0] = (float)(1.0 / GridSize) * *(v7 - 3);
      v12 = _mm_and_ps((__m128)0x80000000, v11);
      v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v12), v8).m128_f32[0]) & 0x4B000000
                     | v12.m128_i32[0];
      v13 = v11;
      v13.m128_f32[0] = (float)(v11.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
      v14 = v13;
      v14.m128_f32[0] = v13.m128_f32[0] - v11.m128_f32[0];
      PointFound[1].x = (float)(v13.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v12).m128_u32[0] & 0x3F800000))
                      * GridSize;
      v15 = ceil(X: (float)((float)(1.0 / GridSize) * v9));
      Point2.y = v15 * GridSize;
      x = PointFound[1].x;
      for ( i = PointFound[1].x; Point2.y > x; i = x )
      {
        nPoints = this->nPoints;
        v18 = 0.0;
        v55 = 0;
        fGridPoint = 0;
        if ( nPoints > 0 )
        {
          Point1.z = 0.0;
          do
          {
            Points = this->Points;
            v20 = *(float *)((char *)&Points->z + LODWORD(v18));
            *(_QWORD *)&PointFound[1].y = *(_QWORD *)((char *)&Points->x + LODWORD(v18));
            Normal.x = v20;
            if ( fGridPoint >= nPoints - 1 )
            {
              v21 = Points->x;
              y = Points->y;
              z = Points->z;
            }
            else
            {
              v21 = *(float *)((char *)&Points[1].x + LODWORD(v18));
              y = *(float *)((char *)&Points[1].y + LODWORD(v18));
              z = *(float *)((char *)&Points[1].z + LODWORD(v18));
            }
            v6 = Point2.z;
            v24 = *(&PointFound[1].y + LODWORD(Point2.z));
            Point1.x = z;
            fStart = y;
            Normal.z = v21;
            v25 = *(&Normal.z + LODWORD(Point2.z));
            if ( v25 != v24 )
            {
              v26 = (float)(x - v24) / (float)(v25 - v24);
              if ( v26 >= 0.0 && v26 <= 1.0 )
              {
                v27 = v55;
                v28 = y - PointFound[1].z;
                v29 = 12 * v55;
                *(float *)&Extents_4[v29 + 548] = (float)((float)(v21 - PointFound[1].y) * v26) + PointFound[1].y;
                v30 = (float)((float)(z - Normal.x) * v26) + Normal.x;
                *(float *)&Extents_4[v29 + 552] = (float)(v28 * v26) + PointFound[1].z;
                *(float *)&(&pRenderContext.m_pObject)[v29 / 4] = v30;
                v55 = v27 + 1;
                if ( v27 == 1 )
                {
                  *(float *)&Extents_4[224] = v5;
                  Extents_4[232] = 1;
                  *(_DWORD *)&Extents_4[228] = 1;
                  (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v5) + 40))(
                    a1: COERCE_FLOAT(LODWORD(v5)),
                    a2: 1);
                  (*(void (__thiscall **)(_DWORD, int, int, _BYTE *, _DWORD))(**(_DWORD **)&Extents_4[224] + 68))(
                    a1: *(_DWORD *)&Extents_4[224],
                    a2: 2,
                    a3: 2,
                    a4: &Extents_4[44],
                    a5: 0);
                  *(_DWORD *)&Extents_4[264] = *(_DWORD *)&Extents_4[200];
                  *(_DWORD *)&Extents_4[252] = LODWORD(v5) + 4;
                  *(_DWORD *)&Extents_4[260] = 0;
                  *(_DWORD *)&Extents_4[268] = 0;
                  *(float *)&Extents_4[452] = v5;
                  *(_DWORD *)&Extents_4[256] = 2;
                  Extents_4[284] = 0;
                  *(_DWORD *)&Extents_4[236] = *(_DWORD *)&Extents_4[208];
                  *(_DWORD *)&Extents_4[248] = *(_DWORD *)&Extents_4[220];
                  qmemcpy(&Extents_4[288], &Extents_4[44], 164);
                  *(_DWORD *)&Extents_4[460] = 2;
                  *(_DWORD *)&Extents_4[368] = *(_DWORD *)&Extents_4[124] != 0 ? 2 : 0;
                  *(_DWORD *)&Extents_4[464] = 0;
                  Extents_4[456] = 0;
                  if ( *(_DWORD *)&Extents_4[520] == -1 )
                  {
                    *(_DWORD *)&Extents_4[516] = 0;
                    *(_DWORD *)&Extents_4[520] = *(_DWORD *)&Extents_4[204];
                    *(_DWORD *)&Extents_4[524] = *(_DWORD *)&Extents_4[200];
                  }
                  v31 = *(_DWORD *)&Extents_4[372];
                  v32 = this->plane.normal.x;
                  v33 = this->plane.normal.y;
                  v34 = this->plane.normal.z;
                  *(_DWORD *)&Extents_4[484] = *(_DWORD *)&Extents_4[396];
                  *(_DWORD *)&Extents_4[476] = *(_DWORD *)&Extents_4[384];
                  *(_DWORD *)&Extents_4[492] = *(_DWORD *)&Extents_4[404];
                  *(_DWORD *)&Extents_4[488] = *(_DWORD *)&Extents_4[400];
                  *(_DWORD *)&Extents_4[500] = *(_DWORD *)&Extents_4[412];
                  *(_DWORD *)&Extents_4[496] = *(_DWORD *)&Extents_4[408];
                  *(_DWORD *)&Extents_4[508] = *(_DWORD *)&Extents_4[420];
                  *(_DWORD *)&Extents_4[504] = *(_DWORD *)&Extents_4[416];
                  *(_DWORD *)&Extents_4[480] = *(_DWORD *)&Extents_4[388];
                  *(_DWORD *)&Extents_4[512] = *(_DWORD *)&Extents_4[424];
                  v35 = (float)(v33 * 0.2) + *(float *)&Extents_4[552];
                  *(_DWORD *)&Extents_4[472] = *(_DWORD *)&Extents_4[372];
                  *(_DWORD *)&Extents_4[268] = 0;
                  *(_DWORD *)&Extents_4[468] = 0;
                  **(float **)&Extents_4[372] = (float)(v32 * 0.2) + *(float *)&Extents_4[548];
                  *(float *)(v31 + 4) = v35;
                  v36 = PointFound[0].z * 255.0;
                  *(float *)(v31 + 8) = (float)(v34 * 0.2) + *(float *)&pRenderContext.m_pObject;
                  BYTE2(pMesh) = (int)(float)(PointFound[0].x * 255.0);
                  HIBYTE(pMesh) = (int)(float)(PointFound[0].y * 255.0);
                  BYTE1(pMesh) = (int)v36;
                  **(_DWORD **)&Extents_4[480] = BYTE1(pMesh)
                                               | ((HIBYTE(pMesh)
                                                 | (((int)(float)(PointFound[0].x * 255.0) | 0xFFFFFF00) << 8)) << 8);
                  CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&Extents_4[288]);
                  v37 = this->plane.normal.y;
                  v38 = *(_DWORD *)&Extents_4[472];
                  v39 = this->plane.normal.z;
                  v40 = BYTE2(pMesh);
                  **(float **)&Extents_4[472] = (float)(this->plane.normal.x * 0.2) + fDelta[0];
                  v41 = (float)(v39 * 0.2) + fDelta[2];
                  *(float *)(v38 + 4) = (float)(v37 * 0.2) + fDelta[1];
                  *(float *)(v38 + 8) = v41;
                  **(_DWORD **)&Extents_4[480] = BYTE1(pMesh)
                                               | ((HIBYTE(pMesh) | ((*(_DWORD *)&v40 | 0xFFFFFF00) << 8)) << 8);
                  CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&Extents_4[288]);
                  if ( Extents_4[232] != 0 )
                  {
                    switch ( *(_DWORD *)&Extents_4[228] )
                    {
                      case 4:
                        v42 = 2 * *(_DWORD *)&Extents_4[464] - 2;
                        break;
                      case 5:
                        v42 = 2 * *(_DWORD *)&Extents_4[464];
                        break;
                      case 6:
                        v42 = 3 * *(_DWORD *)&Extents_4[464] - 6;
                        break;
                      case 7:
                        v42 = 6 * *(_DWORD *)&Extents_4[464] / 4;
                        break;
                      case 0xA:
                        v42 = 0;
                        break;
                      default:
                        v42 = *(_DWORD *)&Extents_4[464];
                        break;
                    }
                    CIndexBuilder::GenerateIndices(
                      this: (CIndexBuilder *)&Extents_4[236],
                      primitiveType: *(MaterialPrimitiveType_t *)&Extents_4[228],
                      nIndexCount: v42);
                  }
                  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _BYTE *))(**(_DWORD **)&Extents_4[224] + 80))(
                    a1: *(_DWORD *)&Extents_4[224],
                    a2: *(_DWORD *)&Extents_4[464],
                    a3: *(_DWORD *)&Extents_4[260],
                    a4: &Extents_4[44]);
                  *(_DWORD *)&Extents_4[252] = 0;
                  *(_DWORD *)&Extents_4[256] = 0;
                  *(_DWORD *)&Extents_4[460] = 0;
                  *(_DWORD *)&Extents_4[452] = 0;
                  *(_DWORD *)&Extents_4[364] = -1;
                  *(_DWORD *)&Extents_4[224] = 0;
                  (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)LODWORD(Point2.x) + 48))(
                    a1: LODWORD(Point2.x),
                    a2: -1,
                    a3: 0);
                  x = i;
                  v5 = Point2.x;
                  v18 = Point1.z;
                  v55 = 0;
                  v6 = Point2.z;
                }
              }
            }
            ++fGridPoint;
            nPoints = this->nPoints;
            LODWORD(v18) += 12;
            Point1.z = v18;
          }
          while ( fGridPoint < nPoints );
        }
        x = x + GridSize;
      }
    }
    ++LODWORD(v6);
    v7 = (float *)(LODWORD(Point1.y) + 28);
    Point2.z = v6;
    LODWORD(Point1.y) += 28;
  }
  while ( SLODWORD(v6) < 3 );
  CRender::PopRenderMode(this: pRender);
  LOBYTE(nPointsFound) = 3;
  v43 = Normal.y;
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(Normal.y) + 12))(a1: LODWORD(Normal.y));
  LOBYTE(nPointsFound) = 0;
  (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v43) + 4))(a1: COERCE_FLOAT(LODWORD(v43)));
  nPointsFound = 4;
  if ( *(_DWORD *)&Extents_4[452] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&Extents_4[452] + 8))(a1: *(_DWORD *)&Extents_4[452]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&Extents_4[452] + 16))(a1: *(_DWORD *)&Extents_4[452]);
  }
  nPointsFound = -1;
  if ( *(_DWORD *)&Extents_4[252] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&Extents_4[252] + 8))(a1: *(_DWORD *)&Extents_4[252]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&Extents_4[252] + 16))(a1: *(_DWORD *)&Extents_4[252]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129210
// Name: public: void CMapFace::CalcTangentSpaceAxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::CalcTangentSpaceAxes(CMapFace *this)
{
  int nPoints; // eax
  CMapFace::TangentSpaceAxes_t *v3; // edi
  CMapFace::TangentSpaceAxes_t *ptIndexa; // [esp+8h] [ebp-14h]
  int ptIndex; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]

  if ( this->m_pTangentAxes != nullptr )
  {
    operator delete(p: this->m_pTangentAxes);
    this->m_pTangentAxes = nullptr;
  }
  nPoints = this->nPoints;
  if ( nPoints >= 1 )
  {
    ptIndexa = (CMapFace::TangentSpaceAxes_t *)operator new[](nSize: 24 * nPoints);
    this->m_pTangentAxes = ptIndexa;
    if ( ptIndexa != nullptr )
    {
      ptIndex = 0;
      if ( this->nPoints > 0 )
      {
        v6 = 0;
        do
        {
          v3 = &this->m_pTangentAxes[v6];
          v3->binormal.x = this->texture.VAxis.x;
          v3->binormal.y = this->texture.VAxis.y;
          v3->binormal.z = this->texture.VAxis.z;
          VectorNormalize(vec: &v3->binormal);
          v3->tangent.x = (float)(this->plane.normal.y * v3->binormal.z)
                        - (float)(v3->binormal.y * this->plane.normal.z);
          v3->tangent.y = (float)(this->plane.normal.z * v3->binormal.x)
                        - (float)(v3->binormal.z * this->plane.normal.x);
          v3->tangent.z = (float)(v3->binormal.y * this->plane.normal.x)
                        - (float)(this->plane.normal.y * v3->binormal.x);
          VectorNormalize(vec: &v3->tangent);
          v3->binormal.x = (float)(v3->tangent.y * this->plane.normal.z) - (float)(this->plane.normal.y * v3->tangent.z);
          v3->binormal.y = (float)(v3->tangent.z * this->plane.normal.x) - (float)(v3->tangent.x * this->plane.normal.z);
          v3->binormal.z = (float)(this->plane.normal.y * v3->tangent.x) - (float)(v3->tangent.y * this->plane.normal.x);
          VectorNormalize(vec: &v3->binormal);
          if ( (float)((float)((float)(this->plane.normal.y
                                     * (float)((float)(this->texture.UAxis.z * this->texture.VAxis.x)
                                             - (float)(this->texture.UAxis.x * this->texture.VAxis.z)))
                             + (float)(this->plane.normal.x
                                     * (float)((float)(this->texture.UAxis.y * this->texture.VAxis.z)
                                             - (float)(this->texture.UAxis.z * this->texture.VAxis.y))))
                     + (float)(this->plane.normal.z
                             * (float)((float)(this->texture.UAxis.x * this->texture.VAxis.y)
                                     - (float)(this->texture.UAxis.y * this->texture.VAxis.x)))) > 0.0 )
          {
            v3->tangent.x = v3->tangent.x * -1.0;
            v3->tangent.y = v3->tangent.y * -1.0;
            v3->tangent.z = v3->tangent.z * -1.0;
          }
          ++v6;
          ++ptIndex;
        }
        while ( ptIndex < this->nPoints );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129B70
// Name: public: void CMapFace::CalcTextureCoords(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapFace::CalcTextureCoords(CMapFace *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  int v4; // ebx
  Vector *Points; // eax
  int v6; // edi
  Vector2D *m_pTextureCoords; // ebx
  int v8; // eax
  Vector2D *v9; // ecx
  Vector *v10; // eax
  float v11; // xmm1_4
  CEditDispMgr *v12; // eax
  CMapDisp *v13; // edi
  int v14; // [esp-8h] [ebp-1Ch]
  float t; // [esp+4h] [ebp-10h]
  float s; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( this->m_pTexture != nullptr )
  {
    if ( this->texture.scale[0] == 0.0 )
      this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
    if ( this->texture.scale[1] == 0.0 )
      this->texture.scale[1] = g_pGameConfig->m_fDefaultTextureScale;
    v3 = 0;
    i = 0;
    if ( this->nPoints > 0 )
    {
      v14 = a2;
      v4 = 0;
      v17 = 0;
      while ( 1 )
      {
        Points = this->Points;
        s = (float)((float)((float)((float)(*(float *)((char *)&Points->y + v4) * this->texture.UAxis.y)
                                  + (float)(this->texture.UAxis.x * *(float *)((char *)&Points->x + v4)))
                          + (float)(*(float *)((char *)&Points->z + v4) * this->texture.UAxis.z))
                  / this->texture.scale[0])
          + this->texture.UAxis.w;
        t = (float)((float)((float)((float)(*(float *)((char *)&Points->y + v4) * this->texture.VAxis.y)
                                  + (float)(*(float *)((char *)&Points->x + v4) * this->texture.VAxis.x))
                          + (float)(*(float *)((char *)&Points->z + v4) * this->texture.VAxis.z))
                  / this->texture.scale[1])
          + this->texture.VAxis.w;
        v6 = v3;
        if ( this->m_pTexture->GetMappingWidth(this: this->m_pTexture) != 0 )
        {
          m_pTextureCoords = this->m_pTextureCoords;
          m_pTextureCoords[v6].x = s / (float)this->m_pTexture->GetMappingWidth(this: this->m_pTexture);
          v4 = v17;
        }
        else
        {
          this->m_pTextureCoords[v6].x = 0.0;
        }
        v8 = this->m_pTexture->GetMappingHeight(this: this->m_pTexture);
        v9 = this->m_pTextureCoords;
        if ( v8 != 0 )
          v9[v6].y = t / (float)this->m_pTexture->GetMappingHeight(this: this->m_pTexture);
        else
          v9[v6].y = 0.0;
        if ( this->m_DispHandle == 0xFFFF )
        {
          v10 = this->Points;
          v11 = this->texture.scale[1] * (float)(1.0 / (float)this->texture.nLightmapScale);
          this->m_pLightmapCoords[v6].x = (float)((float)((float)((float)((float)(*(float *)((char *)&v10->y + v4)
                                                                                * this->texture.UAxis.y)
                                                                        + (float)(*(float *)((char *)&v10->x + v4)
                                                                                * this->texture.UAxis.x))
                                                                + (float)(*(float *)((char *)&v10->z + v4)
                                                                        * this->texture.UAxis.z))
                                                        / (float)this->texture.nLightmapScale)
                                                + (float)((float)((float)(1.0 / (float)this->texture.nLightmapScale)
                                                                * this->texture.scale[0])
                                                        * this->texture.UAxis.w))
                                        + 0.5;
          this->m_pLightmapCoords[v6].y = (float)((float)((float)((float)((float)(*(float *)((char *)&this->Points->y
                                                                                           + v4)
                                                                                * this->texture.VAxis.y)
                                                                        + (float)(this->texture.VAxis.x
                                                                                * *(float *)((char *)&this->Points->x
                                                                                           + v4)))
                                                                + (float)(*(float *)((char *)&this->Points->z + v4)
                                                                        * this->texture.VAxis.z))
                                                        / (float)this->texture.nLightmapScale)
                                                + (float)(this->texture.VAxis.w * v11))
                                        + 0.5;
        }
        v4 += 12;
        ++i;
        v17 = v4;
        if ( i >= this->nPoints )
          break;
        v3 = i;
      }
      a2 = v14;
    }
    if ( this->m_DispHandle != 0xFFFF && this->nPoints == 4 )
    {
      v12 = EditDispMgr();
      v13 = v12->GetDisp(this: v12, a2: this->m_DispHandle);
      CMapDisp::InitDispSurfaceData(this: v13, pFace: this, bGenerateStartPoint: false);
      CMapDisp::Create(this: v13, a2);
    }
    CMapFace::CalcTangentSpaceAxes(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129E90
// Name: protected: static void CMapFace::RenderGridsIfCloseEnough(class CRender3D __near *,int,class CMapFace __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::RenderGridsIfCloseEnough(CRender3D *pRender, int nCount, CMapFace **ppFaces)
{
  CCamera *Camera; // eax
  void *v4; // esp
  int v5; // esi
  int i; // edi
  float v7; // xmm2_4
  int j; // edi
  _DWORD v9[3]; // [esp+0h] [ebp-34h]
  Vector viewPoint; // [esp+Ch] [ebp-28h] BYREF
  Vector Mins; // [esp+18h] [ebp-1Ch] BYREF
  Vector Maxs; // [esp+24h] [ebp-10h] BYREF
  float fGridSize; // [esp+30h] [ebp-4h]

  if ( CRender3D::IsEnabled(this: pRender, eRenderState: RENDER_GRID) && !CRender3D::IsPicking(this: pRender) )
  {
    fGridSize = CRender3D::GetGridDistance(this: pRender);
    Camera = CRender::GetCamera(this: pRender);
    CCamera::GetViewPoint(this: Camera, ViewPoint: &viewPoint);
    v4 = alloca(4 * nCount);
    v5 = 0;
    for ( i = 0; i < nCount; ++i )
    {
      v7 = fGridSize;
      CMapFace::GetFaceBounds(this: ppFaces[i], pfMins: &Mins, pfMaxs: &Maxs);
      Mins.x = Mins.x - v7;
      Maxs.x = Maxs.x + v7;
      Mins.y = Mins.y - v7;
      Maxs.y = Maxs.y + v7;
      Mins.z = Mins.z - v7;
      Maxs.z = Maxs.z + v7;
      if ( IsPointInBox(pt: &viewPoint, boxMin: &Mins, boxMax: &Maxs) )
        v9[v5++] = ppFaces[i];
    }
    for ( j = 0; j < v5; ++j )
      CMapFace::Render3DGrid(this: (CMapFace *)v9[j], pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129FB0
// Name: protected: static void CMapFace::RenderWireframeFaces(class CRender3D __near *,int,struct MapFaceRender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::RenderWireframeFaces(CRender3D *pRender, int nCount, MapFaceRender_t **ppFaces)
{
  int v3; // esi
  void *v4; // esp
  int v5; // eax
  MapFaceRender_t *v6; // ecx
  void *v7; // esp
  CMapFace **v8; // eax
  int i; // edx
  CMapFace *v10[3]; // [esp+0h] [ebp-Ch] BYREF

  v3 = 0;
  v4 = alloca(4 * nCount);
  v5 = 0;
  if ( nCount > 0 )
  {
    do
    {
      v6 = ppFaces[v5];
      if ( v6->m_FaceSelectionState != SELECT_NONE )
        v10[v3++] = v6->m_pMapFace;
      ++v5;
    }
    while ( v5 < nCount );
    if ( v3 != 0 )
      CMapFace::RenderTextureAxes(pRender, nCount: v3, ppFaces: v10);
  }
  if ( CRender3D::IsEnabled(this: pRender, eRenderState: RENDER_GRID) )
  {
    v7 = alloca(4 * nCount);
    if ( nCount > 0 )
    {
      v8 = v10;
      for ( i = nCount; i != 0; --i )
      {
        *v8 = (CMapFace *)(*(CMapFace **)((char *)v8 + (char *)ppFaces - (char *)v10))->m_eSelectionState;
        ++v8;
      }
    }
    CMapFace::RenderGridsIfCloseEnough(pRender, nCount, ppFaces: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A050
// Name: protected: static void CMapFace::RenderFaces(class CRender3D __near *,int,struct MapFaceRender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapFace::RenderFaces(
        int a1@<edi>,
        int a2@<esi>,
        CRender3D *pRender,
        int nCount,
        MapFaceRender_t **ppFaces)
{
  int v5; // ebx
  MapFaceRender_t *v6; // ecx
  EditorRenderMode_t m_RenderMode; // eax
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v9; // edi
  IMesh *v10; // esi
  void (__thiscall *GetMaxToRender)(IMatRenderContext *, IMesh *, bool, int *, int *); // eax
  int nPoints; // eax
  int v13; // ecx
  int v14; // eax
  int i; // esi
  int v16; // eax
  MapFaceRender_t **v17; // edx
  IMesh *v18; // ebx
  int v19; // [esp-18h] [ebp-234h]
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-218h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-30h]
  int newVertices; // [esp+1F0h] [ebp-2Ch]
  IMesh *pMesh; // [esp+1F4h] [ebp-28h]
  int newIndices; // [esp+1F8h] [ebp-24h]
  int nMaxVerts; // [esp+1FCh] [ebp-20h] BYREF
  int nMaxIndices; // [esp+200h] [ebp-1Ch] BYREF
  BOOL bWireframe; // [esp+204h] [ebp-18h]
  int nVertexCount; // [esp+208h] [ebp-14h]
  int nIndexCount; // [esp+20Ch] [ebp-10h]
  int v30; // [esp+218h] [ebp-4h]

  v5 = 0;
  if ( nCount != 0 )
  {
    v6 = *ppFaces;
    m_RenderMode = (*ppFaces)->m_RenderMode;
    LOBYTE(bWireframe) = m_RenderMode == RENDER_MODE_WIREFRAME;
    if ( m_RenderMode == RENDER_MODE_TEXTURED
      || m_RenderMode == RENDER_MODE_TEXTURED_SHADED
      || m_RenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
      || m_RenderMode == RENDER_MODE_LIGHT_PREVIEW2 )
    {
      CRender::BindTexture(this: pRender, pTexture: v6->m_pTexture);
    }
    CRender::PushRenderMode(this: pRender, eRenderMode: (*ppFaces)->m_RenderMode);
    GetRenderContext = materials->GetRenderContext;
    nIndexCount = 0;
    nVertexCount = 0;
    v9 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))GetRenderContext)(
                                a1: materials,
                                a2: a1,
                                a3: a2);
    pRenderContext.m_pObject = v9;
    v30 = 0;
    if ( v9 != nullptr )
      v9->BeginRender(this: v9);
    v30 = 1;
    v10 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD))v9->GetDynamicMesh)(a1: v9, a2: 1, a3: 0);
    GetMaxToRender = v9->GetMaxToRender;
    pMesh = v10;
    GetMaxToRender(this: v9, a2: v10, a3: true, a4: &nMaxVerts, a5: &nMaxIndices);
    nPoints = (*ppFaces)->m_pMapFace->nPoints;
    v13 = 3 * nPoints - 6;
    if ( 2 * nPoints > v13 )
      v13 = 2 * nPoints;
    if ( nMaxVerts < nPoints || nMaxIndices < v13 )
      v9->GetMaxToRender(this: v9, a2: v10, a3: false, a4: &nMaxVerts, a5: &nMaxIndices);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    LOBYTE(v30) = 2;
    v14 = nCount;
    for ( i = 0; i < nCount; ++i )
    {
      v16 = ppFaces[i]->m_pMapFace->nPoints;
      newVertices = v16;
      if ( bWireframe )
        newIndices = 2 * v16;
      else
        newIndices = 3 * v16 - 6;
      if ( v16 + nVertexCount > nMaxVerts || nIndexCount + newIndices > nMaxIndices )
      {
        v19 = i - v5;
        v17 = &ppFaces[v5];
        v18 = pMesh;
        CMapFace::RenderFacesBatch(
          &meshBuilder,
          pMesh,
          pRender,
          ppFaces: v17,
          nFaceCount: v19,
          nVertexCount,
          nIndexCount,
          bWireframe);
        v9->GetMaxToRender(this: v9, a2: v18, a3: false, a4: &nMaxVerts, a5: &nMaxIndices);
        nVertexCount = 0;
        nIndexCount = 0;
        v16 = newVertices;
        v5 = i;
      }
      nVertexCount += v16;
      nIndexCount += newIndices;
      v14 = nCount;
    }
    CMapFace::RenderFacesBatch(
      &meshBuilder,
      pMesh,
      pRender,
      ppFaces: &ppFaces[v5],
      nFaceCount: v14 - v5,
      nVertexCount,
      nIndexCount,
      bWireframe);
    if ( bWireframe )
      CMapFace::RenderWireframeFaces(pRender, nCount, ppFaces);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v30) = 3;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    LOBYTE(v30) = 1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v30 = 5;
    v9->EndRender(this: v9);
    v30 = -1;
    v9->Release(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012ACB0
// Name: public: int CMapFace::Fix(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CMapFace::Fix@<eax>(CMapFace *this@<ecx>, int a2@<ebx>)
{
  Vector *planepts; // edi

  planepts = this->plane.planepts;
  this->plane.normal = *GetNormalFromPoints(
                          p0: this->plane.planepts,
                          p1: &this->plane.planepts[1],
                          p2: &this->plane.planepts[2]);
  this->plane.dist = (float)((float)(this->plane.planepts[0].y * this->plane.normal.y)
                           + (float)(this->plane.normal.x * planepts->x))
                   + (float)(this->plane.planepts[0].z * this->plane.normal.z);
  CMapFace::CalcTextureCoords(this, a2);
  DetailObjects::BuildAnyDetailObjects(pMapFace: this);
  return CMapFace::CheckFace(this, pInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1012AD40
// Name: public: void CMapFace::CreateFace(class Vector __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::CreateFace(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        Vector *pPoints,
        int _nPoints,
        bool bIsCordonFace)
{
  int v6; // eax
  int nPoints; // edi
  int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  int v11; // edx
  float *p_z; // eax
  Vector *Points; // ecx
  Vector *v14; // ecx
  Vector *v15; // ecx
  bool v16; // zf
  Vector *v17; // ecx
  int v18; // edx
  float *v19; // ecx
  Vector *v20; // eax
  double v21; // st7
  Vector *v22; // eax
  int j; // [esp+4h] [ebp-4h]
  int _nPointsa; // [esp+14h] [ebp+Ch]

  SignalUpdate(ev: 0);
  if ( _nPoints <= 0 )
  {
    CMapFace::AllocatePoints(this, _nPoints: -_nPoints);
    nPoints = this->nPoints;
    if ( nPoints > 0 )
    {
      v8 = 0;
      v9 = nPoints - 1;
      if ( v9 >= 0 )
      {
        v10 = v9 + 1;
        if ( v9 + 1 >= 4 )
        {
          _nPointsa = v10 >> 2;
          v11 = 0;
          p_z = &pPoints[v9 - 1].z;
          j = 4 * (v10 >> 2);
          v9 -= j;
          do
          {
            Points = this->Points;
            Points[v11].x = p_z[1];
            p_z -= 12;
            Points[v11].y = p_z[14];
            Points[v11].z = p_z[15];
            v14 = &this->Points[v11 + 1];
            v14->x = p_z[10];
            v14->y = p_z[11];
            v14->z = p_z[12];
            v15 = &this->Points[v11 + 2];
            v15->x = p_z[7];
            v11 += 4;
            v16 = _nPointsa-- == 1;
            v15->y = p_z[8];
            v15->z = p_z[9];
            v17 = this->Points;
            v17[v11 - 1].x = p_z[4];
            v17[v11 - 1].y = p_z[5];
            v17[v11 - 1].z = p_z[6];
          }
          while ( !v16 );
          v8 = j;
        }
        if ( v9 >= 0 )
        {
          v18 = v8;
          v19 = &pPoints[v9].z;
          do
          {
            v20 = this->Points;
            v20[v18++].x = *(v19 - 2);
            v21 = *(v19 - 1);
            v19 -= 3;
            --v9;
            v20[v18 - 1].y = v21;
            v20[v18 - 1].z = v19[3];
          }
          while ( v9 >= 0 );
        }
      }
    }
  }
  else
  {
    CMapFace::AllocatePoints(this, _nPoints);
    v6 = this->nPoints;
    if ( v6 > 0 )
      memcpy(dst: (unsigned __int8 *)this->Points, src: (unsigned __int8 *)pPoints, count: 12 * v6);
  }
  *((_BYTE *)this + 432) ^= (bIsCordonFace ^ *((_BYTE *)this + 432)) & 1;
  if ( this->nPoints >= 3 )
  {
    v22 = this->Points;
    if ( v22 != nullptr )
    {
      *(_QWORD *)&this->plane.planepts[0].x = *(_QWORD *)&v22->x;
      *(_QWORD *)&this->plane.planepts[0].z = *(_QWORD *)&v22->z;
      *(_QWORD *)&this->plane.planepts[1].y = *(_QWORD *)&v22[1].y;
      *(_QWORD *)&this->plane.planepts[2].x = *(_QWORD *)&v22[2].x;
      this->plane.planepts[2].z = v22[2].z;
      CMapFace::CalcPlane(this);
    }
  }
  CMapFace::CalcTextureCoords(this, a2);
  DetailObjects::BuildAnyDetailObjects(pMapFace: this);
}

//------------------------------------------------------------------------------
// Address: 0x1012AF20
// Name: public: void CMapFace::InitializeTextureAxes(enum TextureAlignment_t,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::InitializeTextureAxes(
        CMapFace *this@<ecx>,
        Vector4D *p_UAxis@<ebx>,
        TextureAlignment_t eAlignment,
        char dwFlags)
{
  CGameConfig *v5; // eax
  Vector4D *p_VAxis; // edi
  int Orientation; // eax
  unsigned int v8; // eax
  double x; // st7
  int v10; // eax

  if ( (dwFlags & 1) != 0
    || this->texture.UAxis.x == 0.0
    && this->texture.UAxis.y == 0.0
    && this->texture.UAxis.z == 0.0
    && this->texture.VAxis.x == 0.0
    && this->texture.VAxis.y == 0.0
    && this->texture.VAxis.z == 0.0 )
  {
    if ( (dwFlags & 4) != 0 )
      this->texture.rotate = 0.0;
    if ( (dwFlags & 8) != 0 )
    {
      this->texture.UAxis.w = 0.0;
      this->texture.VAxis.w = 0.0;
    }
    if ( (dwFlags & 0x10) != 0 )
    {
      v5 = g_pGameConfig;
      this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
      this->texture.scale[1] = v5->m_fDefaultTextureScale;
    }
    if ( (dwFlags & 2) != 0 )
    {
      p_UAxis = &this->texture.UAxis;
      this->texture.UAxis.x = 0.0;
      this->texture.UAxis.y = 0.0;
      this->texture.UAxis.z = 0.0;
      p_VAxis = &this->texture.VAxis;
      this->texture.VAxis.x = 0.0;
      this->texture.VAxis.y = 0.0;
      this->texture.VAxis.z = 0.0;
      Orientation = CMapFace::GetOrientation(this);
      if ( Orientation == 6 )
      {
        CMapFace::CalcTextureCoords(this, a2: (int)p_UAxis);
        return;
      }
      v8 = 6 * Orientation;
      x = DownVectors[v8 / 6].x;
      v10 = 2 * v8;
      p_VAxis->x = x;
      this->texture.VAxis.y = *(float *)((char *)dword_1073179C + v10);
      this->texture.VAxis.z = *(float *)((char *)dword_107317A0 + v10);
      if ( eAlignment == TEXTURE_ALIGN_FACE )
      {
        p_UAxis->x = (float)(this->texture.VAxis.z * this->plane.normal.y)
                   - (float)(this->texture.VAxis.y * this->plane.normal.z);
        this->texture.UAxis.y = (float)(this->plane.normal.z * this->texture.VAxis.x)
                              - (float)(this->texture.VAxis.z * this->plane.normal.x);
        this->texture.UAxis.z = (float)(this->texture.VAxis.y * this->plane.normal.x)
                              - (float)(p_VAxis->x * this->plane.normal.y);
        VectorNormalize(vec: (Vector *)&this->texture.UAxis);
        p_VAxis->x = (float)(this->texture.UAxis.y * this->plane.normal.z)
                   - (float)(this->texture.UAxis.z * this->plane.normal.y);
        this->texture.VAxis.y = (float)(this->texture.UAxis.z * this->plane.normal.x)
                              - (float)(this->plane.normal.z * this->texture.UAxis.x);
        this->texture.VAxis.z = (float)(p_UAxis->x * this->plane.normal.y)
                              - (float)(this->texture.UAxis.y * this->plane.normal.x);
        VectorNormalize(vec: (Vector *)&this->texture.VAxis);
      }
      else if ( eAlignment == TEXTURE_ALIGN_WORLD )
      {
        p_UAxis->x = *(float *)((char *)&RightVectors[0].x + v10);
        this->texture.UAxis.y = *(float *)((char *)dword_107317E4 + v10);
        this->texture.UAxis.z = *(float *)((char *)dword_107317E8 + v10);
      }
      else
      {
        CMapFace::InitializeQuakeStyleTextureAxes(this, UAxis: &this->texture.UAxis, VAxis: &this->texture.VAxis);
      }
      if ( this->texture.rotate != 0.0 )
        CMapFace::RotateTextureAxes(this, fDegrees: this->texture.rotate);
    }
    CMapFace::CalcTextureCoords(this, a2: (int)p_UAxis);
    DetailObjects::BuildAnyDetailObjects(pMapFace: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B1C0
// Name: public: void CMapFace::JustifyTextureUsingExtents(enum TextureJustification_t,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::JustifyTextureUsingExtents(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        TextureJustification_t eJustification,
        Vector *Extents)
{
  int v5; // eax
  int v6; // eax
  IEditorTexture *m_pTexture; // ecx
  int v8; // eax
  IEditorTexture *v9; // ecx
  float v10; // xmm0_4
  float Center; // [esp+0h] [ebp-18h]
  float Center_4; // [esp+4h] [ebp-14h]
  Vector2D TopLeft; // [esp+8h] [ebp-10h] BYREF
  Vector2D BottomRight; // [esp+10h] [ebp-8h] BYREF
  float eJustificationa; // [esp+20h] [ebp+8h]

  if ( this->texture.scale[0] == 0.0 )
    this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
  if ( this->texture.scale[1] == 0.0 )
    this->texture.scale[1] = g_pGameConfig->m_fDefaultTextureScale;
  if ( eJustification != TEXTURE_JUSTIFY_NONE )
  {
    if ( eJustification == TEXTURE_JUSTIFY_FIT )
    {
      this->texture.scale[0] = 1.0;
      this->texture.scale[1] = 1.0;
    }
    CMapFace::GetTextureExtents(this, Extents, &TopLeft, &BottomRight);
    Center_4 = (float)(BottomRight.y + TopLeft.y) * 0.5;
    switch ( eJustification )
    {
      case TEXTURE_JUSTIFY_TOP:
        LODWORD(this->texture.VAxis.w) = LODWORD(TopLeft.y) ^ _mask__NegFloat_;
        break;
      case TEXTURE_JUSTIFY_BOTTOM:
        v5 = this->m_pTexture->GetMappingHeight(this: this->m_pTexture);
        this->texture.VAxis.w = (float)v5 - BottomRight.y;
        break;
      case TEXTURE_JUSTIFY_LEFT:
        LODWORD(this->texture.UAxis.w) = LODWORD(TopLeft.x) ^ _mask__NegFloat_;
        break;
      case TEXTURE_JUSTIFY_CENTER:
        Center = (float)(BottomRight.x + TopLeft.x) * 0.5;
        this->texture.UAxis.w = (float)(this->m_pTexture->GetMappingWidth(this: this->m_pTexture) / 2) - Center;
        this->texture.VAxis.w = (float)(this->m_pTexture->GetMappingHeight(this: this->m_pTexture) / 2) - Center_4;
        break;
      case TEXTURE_JUSTIFY_RIGHT:
        v6 = this->m_pTexture->GetMappingWidth(this: this->m_pTexture);
        this->texture.UAxis.w = (float)v6 - BottomRight.x;
        break;
      case TEXTURE_JUSTIFY_FIT:
        m_pTexture = this->m_pTexture;
        if ( m_pTexture != nullptr
          && m_pTexture->GetMappingWidth(this: m_pTexture) != 0
          && this->m_pTexture->GetMappingHeight(this: this->m_pTexture) != 0 )
        {
          eJustificationa = BottomRight.x - TopLeft.x;
          v8 = this->m_pTexture->GetMappingWidth(this: this->m_pTexture);
          v9 = this->m_pTexture;
          v10 = BottomRight.y - TopLeft.y;
          this->texture.scale[0] = eJustificationa / (float)v8;
          this->texture.scale[1] = v10 / (float)v9->GetMappingHeight(this: v9);
        }
        else
        {
          this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
          this->texture.scale[1] = g_pGameConfig->m_fDefaultTextureScale;
        }
        CMapFace::JustifyTextureUsingExtents(this, eJustification: TEXTURE_JUSTIFY_TOP, Extents);
        CMapFace::JustifyTextureUsingExtents(this, eJustification: TEXTURE_JUSTIFY_LEFT, Extents);
        break;
      default:
        break;
    }
    CMapFace::NormalizeTextureShifts(this);
    CMapFace::CalcTextureCoords(this, a2: (int)Extents);
  }
  else
  {
    this->texture.UAxis.w = 0.0;
    this->texture.VAxis.w = 0.0;
    CMapFace::CalcTextureCoords(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B480
// Name: public: void CMapFace::CreateFace(struct winding_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::CreateFace(CMapFace *this, CMapDisp *w, char nFlags)
{
  int v4; // ecx
  int v5; // eax
  Vector *Points; // eax
  CEditDispMgr *v7; // eax
  int v8; // edi
  CEditDispMgr *v9; // eax
  CMapDisp *v10; // ebx
  CEditDispMgr *v11; // eax
  CEditDispMgr *v12; // eax
  CEditDispMgr *v13; // eax
  CMapDisp *pDisp; // [esp+14h] [ebp+8h]
  int hDisp; // [esp+18h] [ebp+Ch]

  SignalUpdate(ev: 0);
  CMapFace::AllocatePoints(this, _nPoints: (int)w->__vftable);
  v4 = 0;
  if ( this->nPoints > 0 )
  {
    v5 = 0;
    do
    {
      this->Points[v5] = *(Vector *)(v5 * 12 + w->m_nObjectID);
      ++v4;
      ++v5;
    }
    while ( v4 < this->nPoints );
  }
  if ( (nFlags & 1) == 0 && this->nPoints >= 3 )
  {
    Points = this->Points;
    if ( Points != nullptr )
    {
      *(_QWORD *)&this->plane.planepts[0].x = *(_QWORD *)&Points->x;
      *(_QWORD *)&this->plane.planepts[0].z = *(_QWORD *)&Points->z;
      *(_QWORD *)&this->plane.planepts[1].y = *(_QWORD *)&Points[1].y;
      *(_QWORD *)&this->plane.planepts[2].x = *(_QWORD *)&Points[2].x;
      this->plane.planepts[2].z = Points[2].z;
      this->plane.normal = *GetNormalFromPoints(
                              p0: this->plane.planepts,
                              p1: &this->plane.planepts[1],
                              p2: &this->plane.planepts[2]);
      this->plane.dist = (float)((float)(this->plane.planepts[0].y * this->plane.normal.y)
                               + (float)(this->plane.normal.x * this->plane.planepts[0].x))
                       + (float)(this->plane.planepts[0].z * this->plane.normal.z);
    }
  }
  if ( this->m_DispHandle == 0xFFFF || (nFlags & 2) == 0 )
  {
    CMapFace::CalcTextureCoords(this, a2: nFlags);
  }
  else if ( this->nPoints == 4 )
  {
    v7 = EditDispMgr();
    v8 = v7->Create(this: v7);
    v9 = EditDispMgr();
    v10 = v9->GetDisp(this: v9, a2: v8);
    hDisp = this->m_DispHandle;
    v11 = EditDispMgr();
    pDisp = v11->GetDisp(this: v11, a2: hDisp);
    v10->SetParent(this: v10, a2: this);
    this->m_DispHandle = v8;
    CMapDisp::InitData(this: v10, power: pDisp->m_CoreDispInfo.m_Power);
    CMapFace::CalcTextureCoords(this, a2: (unsigned __int8)v10);
    CMapDisp::Split(this: pDisp, hBuilderDisp: v8);
    v12 = EditDispMgr();
    v12->Destroy(this: v12, a2: hDisp);
  }
  else
  {
    v13 = EditDispMgr();
    v13->Destroy(this: v13, a2: this->m_DispHandle);
    this->m_DispHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B6A0
// Name: public: void CMapFace::SetTexture(class IEditorTexture __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::SetTexture(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        IEditorTexture *pTexture,
        bool bRescaleTextureCoordinates)
{
  IEditorTexture *m_pTexture; // ecx
  int v7; // eax
  float v8; // xmm0_4
  unsigned int v9; // eax
  IEditorTexture *v10; // ecx
  unsigned int v11; // eax
  IEditorTexture *v12; // ecx
  float flXFactor; // [esp+10h] [ebp+8h]
  float bRescaleTextureCoordinatesa; // [esp+14h] [ebp+Ch]
  float bRescaleTextureCoordinatesb; // [esp+14h] [ebp+Ch]

  SignalUpdate(ev: 0);
  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && pTexture != nullptr && bRescaleTextureCoordinates )
  {
    bRescaleTextureCoordinatesa = (float)m_pTexture->GetMappingWidth(this: m_pTexture);
    flXFactor = bRescaleTextureCoordinatesa / (float)pTexture->GetMappingWidth(this: pTexture);
    bRescaleTextureCoordinatesb = (float)this->m_pTexture->GetMappingHeight(this: this->m_pTexture);
    v7 = pTexture->GetMappingHeight(this: pTexture);
    this->texture.scale[0] = flXFactor * this->texture.scale[0];
    v8 = bRescaleTextureCoordinatesb / (float)v7;
    this->texture.scale[1] = v8 * this->texture.scale[1];
    this->texture.UAxis.w = this->texture.UAxis.w / flXFactor;
    this->texture.VAxis.w = this->texture.VAxis.w / v8;
  }
  this->m_pTexture = pTexture;
  pTexture->GetShortName(this: pTexture, a2: (char *)&this->texture);
  v9 = this->m_pTexture->GetSurfaceAttributes(this: this->m_pTexture);
  v10 = this->m_pTexture;
  this->texture.q2surface = v9;
  v11 = v10->GetSurfaceContents(this: v10);
  v12 = this->m_pTexture;
  this->texture.q2contents = v11;
  if ( v12 != nullptr )
  {
    v12->Load(this: v12);
    if ( this->m_pTexture->GetPreviewImageWidth(this: this->m_pTexture) != 0
      && this->m_pTexture->GetPreviewImageHeight(this: this->m_pTexture) != 0
      && this->m_pTexture->GetMappingWidth(this: this->m_pTexture) != 0
      && this->m_pTexture->GetMappingHeight(this: this->m_pTexture) != 0
      && this->m_pTexture->HasData(this: this->m_pTexture) )
    {
      CMapFace::CalcTextureCoords(this, a2);
    }
  }
  CMapFace::UpdateFaceFlags(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012B840
// Name: public: void CMapFace::SetTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFace::SetTexture(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        const char *pszNewTex,
        bool bRescaleTextureCoordinates)
{
  IEditorTexture *ActiveTexture; // eax

  SignalUpdate(ev: 0);
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: pszNewTex,
                    piIndex: nullptr,
                    bDummy: 1);
  CMapFace::SetTexture(this, a2, pTexture: ActiveTexture, bRescaleTextureCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x1012B880
// Name: protected: void CMapFace::RenderFace3D(class CRender3D __near *,enum EditorRenderMode_t,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::RenderFace3D(
        CMapFace *this,
        CRender3D *pRender,
        CMapFace *renderMode,
        int renderSelected,
        Color faceSelectionState)
{
  CRender3D *v5; // edi
  CEditDispMgr *v7; // eax
  CMapDisp *v8; // eax
  SelectionState_t v9; // ebx
  DetailObjects *m_pDetailObjects; // esi
  bool v11; // [esp-8h] [ebp-14h]

  v5 = pRender;
  CRender::PushRenderMode(this: pRender, eRenderMode: (EditorRenderMode_t)renderMode);
  if ( this->m_DispHandle != 0xFFFF && CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pMapDoc->m_bDispDraw3D )
  {
    v7 = EditDispMgr();
    v8 = v7->GetDisp(this: v7, a2: this->m_DispHandle);
    v9 = (SelectionState_t)faceSelectionState;
    CMapDisp::Render3D(this: v8, pRender: v5, bIsSelected: renderSelected, faceSelectionState);
  }
  else
  {
    v9 = (SelectionState_t)faceSelectionState;
    v11 = (*((_BYTE *)this + 432) & 2) != 0;
    pRender = nullptr;
    CMapFace::ComputeColor(
      this,
      pRender: v5,
      bRenderAsSelected: renderSelected,
      faceSelectionState: *(SelectionState_t *)&faceSelectionState,
      ignoreLighting: v11,
      pColor: (Color *)&pRender);
    CMapFace::DrawFace(this, a2: v9, a3: (int)v5, pColor: (Color *)&pRender, mode: (EditorRenderMode_t)renderMode);
  }
  if ( renderMode == (CMapFace *)4 )
  {
    if ( v9 != SELECT_NONE )
    {
      renderMode = this;
      CMapFace::RenderTextureAxes(pRender: v5, nCount: 1, ppFaces: &renderMode);
    }
    renderMode = this;
    CMapFace::RenderGridsIfCloseEnough(pRender: v5, nCount: 1, ppFaces: &renderMode);
    CRender::PopRenderMode(this: v5);
  }
  else
  {
    m_pDetailObjects = this->m_pDetailObjects;
    if ( m_pDetailObjects != nullptr && Options.general.bShowDetailObjects != 0 )
      CRender3D::AddTranslucentDeferredRendering(this: v5, pMapPoint: m_pDetailObjects);
    CRender::PopRenderMode(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B980
// Name: public: static void CMapFace::RenderOpaqueFaces(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFace::RenderOpaqueFaces(CRender3D *pRender)
{
  IMatRenderContext *v1; // eax
  int v2; // edi
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *p_m_Data; // esi
  void *v4; // esp
  int Inorder; // ebx
  UtlRBTreeNode_t<MapFaceRender_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<MapFaceRender_t,int> *v7; // eax
  IEditorTexture *m_nAllocationCount; // ecx
  IMatRenderContext *v9; // esi
  int v10; // [esp+0h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-20h]
  IMatRenderContext *v12; // [esp+10h] [ebp-1Ch]
  IEditorTexture *pLastTexture; // [esp+14h] [ebp-18h]
  int nLastRenderMode; // [esp+18h] [ebp-14h]
  MapFaceRender_t **ppMapFaces; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+28h] [ebp-4h]

  v1 = materials->GetRenderContext(this: materials);
  v12 = v1;
  pRenderContext.m_pObject = v1;
  v2 = 0;
  v16 = 0;
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v16 = 1;
  p_m_Data = g_CurrentOpaqueFaces;
  v4 = alloca(4 * g_CurrentOpaqueFaces->m_NumElements);
  ppMapFaces = (MapFaceRender_t **)&v10;
  nLastRenderMode = 0;
  pLastTexture = nullptr;
  Inorder = CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::FirstInorder(this: g_CurrentOpaqueFaces);
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      m_pMemory = p_m_Data->m_Elements.m_pMemory;
      p_m_Data = (CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *)&m_pMemory[Inorder].m_Data;
      if ( m_pMemory[Inorder].m_Data.m_RenderMode != nLastRenderMode
        || m_pMemory[Inorder].m_Data.m_pTexture != pLastTexture )
      {
        CMapFace::RenderFaces(a1: v2, a2: (int)p_m_Data, pRender, nCount: v2, ppFaces: ppMapFaces);
        v2 = 0;
      }
      if ( *(_WORD *)(p_m_Data->m_Elements.m_nGrowSize + 420) == 0xFFFF )
      {
        ppMapFaces[v2] = (MapFaceRender_t *)p_m_Data;
        m_nAllocationCount = (IEditorTexture *)p_m_Data->m_Elements.m_nAllocationCount;
        ++v2;
        nLastRenderMode = (int)p_m_Data->m_Elements.m_pMemory;
        pLastTexture = m_nAllocationCount;
      }
      else
      {
        v7 = p_m_Data->m_Elements.m_pMemory;
        if ( v7 == (UtlRBTreeNode_t<MapFaceRender_t,int> *)10
          || v7 == (UtlRBTreeNode_t<MapFaceRender_t,int> *)14
          || v7 == (UtlRBTreeNode_t<MapFaceRender_t,int> *)16
          || v7 == (UtlRBTreeNode_t<MapFaceRender_t,int> *)15 )
        {
          CRender::BindTexture(this: pRender, pTexture: (IEditorTexture *)p_m_Data->m_Elements.m_nAllocationCount);
        }
        CMapFace::RenderFace3D(
          this: (CMapFace *)p_m_Data->m_Elements.m_nGrowSize,
          pRender,
          renderMode: (CMapFace *)p_m_Data->m_Elements.m_pMemory,
          renderSelected: LOBYTE(p_m_Data->m_LessFunc),
          faceSelectionState: (Color)p_m_Data->m_Root);
      }
      Inorder = CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::NextInorder(
                  this: g_CurrentOpaqueFaces,
                  i: Inorder);
      if ( Inorder == -1 )
        break;
      p_m_Data = g_CurrentOpaqueFaces;
    }
  }
  CMapFace::RenderFaces(a1: v2, a2: (int)p_m_Data, pRender, nCount: v2, ppFaces: ppMapFaces);
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::RemoveAll(this: g_CurrentOpaqueFaces);
  v16 = 2;
  v9 = v12;
  if ( v12 != nullptr )
    v12->EndRender(this: v12);
  v16 = -1;
  if ( v9 != nullptr )
    v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1012BB10
// Name: public: enum ChunkFileResult_t CMapFace::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapFace::LoadVMF(CMapFace *this, CChunkFile *pFile)
{
  ChunkFileResult_t v3; // ebx
  IEditorTexture *ActiveTexture; // eax
  LoadFace_t LoadFace; // [esp+Ch] [ebp-120h] BYREF
  CChunkHandlerMap Handlers; // [esp+114h] [ebp-18h] BYREF
  int v8; // [esp+128h] [ebp-4h]

  SignalUpdate(ev: 0);
  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v8 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "dispinfo",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapFace::LoadDispInfoCallback,
    pData: this);
  memset(dst: (unsigned __int8 *)&LoadFace, value: 0, count: sizeof(LoadFace));
  LoadFace.pFace = this;
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  v3 = CChunkFile::ReadChunk(
         this: pFile,
         pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapFace::LoadKeyCallback,
         pData: &LoadFace);
  CChunkFile::PopHandlers(this: pFile);
  if ( v3 == ChunkFile_Ok )
  {
    CMapFace::CalcPlane(this);
    SignalUpdate(ev: 0);
    ActiveTexture = CTextureSystem::FindActiveTexture(
                      this: &g_Textures,
                      pszInputName: LoadFace.szTexName,
                      piIndex: nullptr,
                      bDummy: 1);
    CMapFace::SetTexture(this, a2: 0, pTexture: ActiveTexture, bRescaleTextureCoordinates: false);
  }
  v8 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1012BC00
// Name: public: enum ChunkFileResult_t CMapFace::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __userpurge CMapFace::SaveVMF@<eax>(
        CMapFace *this@<ecx>,
        int a2@<ebx>,
        CChunkFile *pFile,
        CSaveInfo *pSaveInfo)
{
  ChunkFileResult_t result; // eax
  TEXTURE *p_texture; // eax
  char v7; // cl
  CEditDispMgr *v8; // eax
  CMapDisp *v9; // eax
  char string[56]; // [esp+50h] [ebp-304h] BYREF
  char szBuf[512]; // [esp+98h] [ebp-2BCh] BYREF

  CMapFace::NormalizeTextureShifts(this);
  if ( CMapFace::CheckFace(this, pInfo: nullptr) == 0 )
    CMapFace::Fix(this, a2);
  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "side");
  if ( result == ChunkFile_Ok )
  {
    result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "id", nValue: this->m_nFaceID);
    if ( result == ChunkFile_Ok )
    {
      sprintf(
        string,
        format: "(%g %g %g) (%g %g %g) (%g %g %g)",
        this->plane.planepts[0].x,
        this->plane.planepts[0].y,
        this->plane.planepts[0].z,
        this->plane.planepts[1].x,
        this->plane.planepts[1].y,
        this->plane.planepts[1].z,
        this->plane.planepts[2].x,
        this->plane.planepts[2].y,
        this->plane.planepts[2].z);
      result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "plane", pszValue: string);
      if ( result == ChunkFile_Ok )
      {
        p_texture = &this->texture;
        do
        {
          v7 = p_texture->texture[0];
          p_texture->texture[&szBuf[440] - (char *)&this->texture] = p_texture->texture[0];
          p_texture = (TEXTURE *)((char *)p_texture + 1);
        }
        while ( v7 != 0 );
        strupr(string: &szBuf[440]);
        result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "material", pszValue: &szBuf[440]);
        if ( result == ChunkFile_Ok )
        {
          sprintf(
            string,
            format: "[%g %g %g %g] %g",
            this->texture.UAxis.x,
            this->texture.UAxis.y,
            this->texture.UAxis.z,
            this->texture.UAxis.w,
            this->texture.scale[0]);
          result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "uaxis", pszValue: string);
          if ( result == ChunkFile_Ok )
          {
            sprintf(
              string,
              format: "[%g %g %g %g] %g",
              this->texture.VAxis.x,
              this->texture.VAxis.y,
              this->texture.VAxis.z,
              this->texture.VAxis.w,
              this->texture.scale[1]);
            result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "vaxis", pszValue: string);
            if ( result == ChunkFile_Ok )
            {
              result = CChunkFile::WriteKeyValueFloat(this: pFile, pszKey: "rotation", fValue: this->texture.rotate);
              if ( result == ChunkFile_Ok )
              {
                result = CChunkFile::WriteKeyValueFloat(
                           this: pFile,
                           pszKey: "lightmapscale",
                           fValue: (float)this->texture.nLightmapScale);
                if ( result == ChunkFile_Ok )
                {
                  result = CChunkFile::WriteKeyValueInt(
                             this: pFile,
                             pszKey: "smoothing_groups",
                             nValue: this->m_fSmoothingGroups);
                  if ( result == ChunkFile_Ok )
                  {
                    if ( this->m_DispHandle == 0xFFFF )
                      return CChunkFile::EndChunk(this: pFile);
                    v8 = EditDispMgr();
                    v9 = v8->GetDisp(this: v8, a2: this->m_DispHandle);
                    result = CMapDisp::SaveVMF(this: v9, pFile, pSaveInfo);
                    if ( result == ChunkFile_Ok )
                      return CChunkFile::EndChunk(this: pFile);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012BF10
// Name: public: virtual void CMapFace::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMapFace::DoTransform(CMapFace *this@<ecx>, float a2@<ebp>, const VMatrix *matrix)
{
  int m_DispHandle; // eax
  int v5; // esi
  CEditDispMgr *v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // esi
  Vector *Points; // ecx
  float z; // eax
  __int64 v12; // xmm0_8
  float *p_x; // ecx
  float v14; // xmm1_4
  const VMatrix *v15; // esi
  Vector *v16; // eax
  int Wide; // eax
  float y; // edi
  _QWORD *v19; // esi
  float v20; // esi
  float v21; // eax
  float v22; // ecx
  __int128 v23; // xmm0
  __int128 v24; // xmm0
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  __int128 v29; // xmm4
  float v30; // xmm6_4
  float v31; // xmm4_4
  char v32; // cl
  float v33; // xmm5_4
  bool v34; // al
  char x_high; // dl
  float v36; // xmm6_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm3_4
  TextureAlignment_t Id; // eax
  int Name; // eax
  _QWORD *v42; // edi
  QAngle v43; // [esp+10h] [ebp-D0h] BYREF
  Vector v44; // [esp+1Ch] [ebp-C4h] BYREF
  Vector v45; // [esp+28h] [ebp-B8h] BYREF
  _BYTE v46[144]; // [esp+34h] [ebp-ACh] OVERLAPPED BYREF
  Vector vV; // [esp+C4h] [ebp-1Ch]
  Vector moveDelta; // [esp+D0h] [ebp-10h]
  CMapDisp *pDisp; // [esp+DCh] [ebp-4h] BYREF
  float fScaleU; // [esp+E0h] [ebp+0h]

  moveDelta.y = a2;
  moveDelta.z = fScaleU;
  LODWORD(vV.y) = this;
  SignalUpdate(ev: 0);
  if ( this->nPoints < 3 )
    return;
  m_DispHandle = this->m_DispHandle;
  *(_DWORD *)&v46[120] = 0;
  if ( (_WORD)m_DispHandle != 0xFFFF )
  {
    v5 = m_DispHandle;
    v6 = EditDispMgr();
    v7 = (int)v6->GetDisp(this: v6, a2: v5);
    *(_DWORD *)&v46[120] = v7;
    if ( v7 != 0 )
    {
      v44 = *(Vector *)(v7 + 1064);
      v45 = *(Vector *)(v7 + 1076);
    }
  }
  v8 = 0;
  if ( this->nPoints > 0 )
  {
    v9 = 0;
    do
    {
      Points = this->Points;
      z = Points[v9].z;
      v12 = *(_QWORD *)&Points[v9].x;
      p_x = &Points[v9].x;
      *(_QWORD *)&v46[108] = v12;
      *(float *)&v46[116] = z;
      v14 = 1.0
          / (float)((float)((float)((float)(matrix->m[3][1] * *((float *)&v12 + 1))
                                  + (float)(matrix->m[3][0] * *(float *)&v12))
                          + (float)(z * matrix->m[3][2]))
                  + matrix->m[3][3]);
      *p_x = (float)((float)((float)((float)(matrix->m[0][0] * *(float *)&v12)
                                   + (float)(matrix->m[0][1] * *((float *)&v12 + 1)))
                           + (float)(matrix->m[0][2] * z))
                   + matrix->m[0][3])
           * v14;
      p_x[1] = (float)((float)((float)((float)(matrix->m[1][1] * *((float *)&v12 + 1))
                                     + (float)(matrix->m[1][0] * *(float *)&v12))
                             + (float)(z * matrix->m[1][2]))
                     + matrix->m[1][3])
             * v14;
      ++v8;
      p_x[2] = (float)((float)((float)((float)(*((float *)&v12 + 1) * matrix->m[2][1])
                                     + (float)(matrix->m[2][0] * *(float *)&v12))
                             + (float)(matrix->m[2][2] * z))
                     + matrix->m[2][3])
             * v14;
      ++v9;
    }
    while ( v8 < this->nPoints );
  }
  v15 = matrix;
  if ( (float)((float)(matrix->m[1][1] * v15->m[0][0]) * v15->m[2][2]) < 0.0 )
    PointsRevertOrder(pPoints: this->Points, nPoints: this->nPoints);
  if ( this->nPoints >= 3 )
  {
    v16 = this->Points;
    if ( v16 != nullptr )
    {
      *(_QWORD *)&this->plane.planepts[0].x = *(_QWORD *)&v16->x;
      *(_QWORD *)&this->plane.planepts[0].z = *(_QWORD *)&v16->z;
      *(_QWORD *)&this->plane.planepts[1].y = *(_QWORD *)&v16[1].y;
      *(_QWORD *)&this->plane.planepts[2].x = *(_QWORD *)&v16[2].x;
      this->plane.planepts[2].z = v16[2].z;
      this->plane.normal = *GetNormalFromPoints(
                              p0: this->plane.planepts,
                              p1: &this->plane.planepts[1],
                              p2: &this->plane.planepts[2]);
      v15 = matrix;
      this->plane.dist = (float)((float)(this->plane.planepts[0].y * this->plane.normal.y)
                               + (float)(this->plane.normal.x * this->plane.planepts[0].x))
                       + (float)(this->plane.planepts[0].z * this->plane.normal.z);
    }
  }
  qmemcpy(v46, v15, 0x40u);
  MatrixAngles(src: matrix, vAngles: &v43);
  *(float *)&v46[108] = matrix->m[0][3];
  *(float *)&v46[112] = matrix->m[1][3];
  *(float *)&v46[116] = matrix->m[2][3];
  Wide = vgui::Image::GetWide(this: (vgui::Image *)&Options);
  vV.z = *(float *)&v46[112] * *(float *)&v46[112];
  HIBYTE(moveDelta.x) = Wide != 0;
  BYTE2(moveDelta.x) = (float)((float)((float)(*(float *)&v46[112] * *(float *)&v46[112])
                                     + (float)(*(float *)&v46[108] * *(float *)&v46[108]))
                             + (float)(*(float *)&v46[116] * *(float *)&v46[116])) > 0.00001;
  *(float *)&v46[12] = vec3_origin.x;
  *(float *)&v46[28] = vec3_origin.y;
  *(float *)&v46[44] = vec3_origin.z;
  if ( VMatrix::IsIdentity(this: (VMatrix *)v46) )
  {
    y = vV.y;
    if ( *(_DWORD *)(LODWORD(vV.y) + 416) != 0 )
    {
      if ( BYTE2(moveDelta.x) != 0 && HIBYTE(moveDelta.x) != 0 )
        CMapFace::OffsetTexture(this: (CMapFace *)LODWORD(vV.y), Delta: (const Vector *)&v46[108]);
      CMapFace::CalcTextureCoords(this: (CMapFace *)LODWORD(y), a2: (int)&pDisp);
    }
    v19 = *(_QWORD **)&v46[120];
    if ( *(_DWORD *)&v46[120] != 0 )
    {
      CMapDisp::UpdateSurfData(this: *(CMapDisp **)&v46[120], a2: (int)&pDisp, pFace: (CMapFace *)LODWORD(y));
      *(_QWORD *)&v46[64] = v19[133];
      *(_QWORD *)&v46[72] = v19[134];
      *(_QWORD *)&v46[80] = v19[135];
      CMapDisp::UpdateNeighborsOfDispsIntersectingBox(bbMin: &v44, bbMax: &v45, flPadding: 1.0);
      CMapDisp::UpdateNeighborsOfDispsIntersectingBox(
        bbMin: (const Vector *)&v46[64],
        bbMax: (const Vector *)&v46[76],
        flPadding: 1.0);
    }
    DetailObjects::BuildAnyDetailObjects(pMapFace: (CMapFace *)LODWORD(y));
    return;
  }
  v20 = vV.y;
  if ( *(_DWORD *)(LODWORD(vV.y) + 416) != 0 )
  {
    v21 = *(float *)(LODWORD(vV.y) + 288);
    *(_QWORD *)&v46[132] = *(_QWORD *)(LODWORD(vV.y) + 280);
    *(_QWORD *)&v46[96] = *(_QWORD *)(LODWORD(vV.y) + 296);
    vV.z = *(float *)&v46[132] * *(float *)&v46[132];
    v22 = *(float *)(LODWORD(vV.y) + 304);
    *(float *)&v46[140] = v21;
    v23 = 0;
    *(float *)&v23 = fsqrt(
                       (float)((float)(*(float *)&v46[132] * *(float *)&v46[132])
                             + (float)(*(float *)&v46[136] * *(float *)&v46[136]))
                     + (float)(*(float *)&v46[140] * *(float *)&v46[140]));
    *(_OWORD *)&v46[128] = v23;
    *(_DWORD *)&v46[124] = v23;
    vV.z = *(float *)&v46[96] * *(float *)&v46[96];
    *(float *)&v46[104] = v22;
    v24 = 0;
    *(float *)&v24 = fsqrt(
                       (float)((float)(*(float *)&v46[96] * *(float *)&v46[96])
                             + (float)(*(float *)&v46[100] * *(float *)&v46[100]))
                     + (float)(*(float *)&v46[104] * *(float *)&v46[104]));
    *(_OWORD *)&v46[64] = v24;
    LODWORD(vV.y) = v24;
    if ( *(float *)&v46[128] <= 0.0 )
      *(_DWORD *)&v46[124] = 1065353216;
    if ( *(float *)&v46[64] <= 0.0 )
      vV.y = 1.0;
    *(_QWORD *)&v46[132] = *(_QWORD *)(LODWORD(v20) + 280);
    *(float *)&v46[140] = v21;
    vV.z = 1.0
         / (float)((float)((float)((float)(*(float *)&v46[48] * *(float *)&v46[132])
                                 + (float)(*(float *)&v46[136] * *(float *)&v46[52]))
                         + (float)(v21 * *(float *)&v46[56]))
                 + *(float *)&v46[60]);
    v25 = (float)((float)((float)((float)(*(float *)v46 * *(float *)&v46[132])
                                + (float)(*(float *)&v46[4] * *(float *)&v46[136]))
                        + (float)(*(float *)&v46[8] * v21))
                + *(float *)&v46[12])
        * vV.z;
    v26 = (float)((float)((float)((float)(*(float *)&v46[16] * *(float *)&v46[132])
                                + (float)(*(float *)&v46[20] * *(float *)&v46[136]))
                        + (float)(*(float *)&v46[24] * v21))
                + *(float *)&v46[28])
        * vV.z;
    v27 = (float)((float)((float)((float)(*(float *)&v46[32] * *(float *)&v46[132])
                                + (float)(*(float *)&v46[36] * *(float *)&v46[136]))
                        + (float)(*(float *)&v46[40] * v21))
                + *(float *)&v46[44])
        * vV.z;
    *(_QWORD *)&v46[132] = *(_QWORD *)(LODWORD(v20) + 296);
    *(float *)&v46[140] = v22;
    vV.z = 1.0
         / (float)((float)((float)((float)(*(float *)&v46[48] * *(float *)&v46[132])
                                 + (float)(*(float *)&v46[136] * *(float *)&v46[52]))
                         + (float)(v22 * *(float *)&v46[56]))
                 + *(float *)&v46[60]);
    v28 = (float)((float)((float)((float)(*(float *)&v46[132] * *(float *)v46)
                                + (float)(*(float *)&v46[136] * *(float *)&v46[4]))
                        + (float)(v22 * *(float *)&v46[8]))
                + *(float *)&v46[12])
        * vV.z;
    *(float *)&v46[104] = (float)((float)((float)((float)(*(float *)&v46[32] * *(float *)&v46[132])
                                                + (float)(*(float *)&v46[136] * *(float *)&v46[36]))
                                        + (float)(v22 * *(float *)&v46[40]))
                                + *(float *)&v46[44])
                        * vV.z;
    *(float *)&v46[100] = (float)((float)((float)((float)(*(float *)&v46[16] * *(float *)&v46[132])
                                                + (float)(*(float *)&v46[136] * *(float *)&v46[20]))
                                        + (float)(v22 * *(float *)&v46[24]))
                                + *(float *)&v46[28])
                        * vV.z;
    v29 = 0;
    *(_DWORD *)&v46[64] = fsqrt((float)((float)(v25 * v25) + (float)(v26 * v26)) + (float)(v27 * v27));
    v30 = *(float *)&v46[64] / *(float *)&v46[124];
    *(float *)&v29 = fsqrt(
                       (float)((float)(v28 * v28) + (float)(*(float *)&v46[100] * *(float *)&v46[100]))
                     + (float)(*(float *)&v46[104] * *(float *)&v46[104]));
    *(_OWORD *)&v46[64] = v29;
    v31 = *(float *)&v29 / vV.y;
    *(float *)&v46[124] = v30;
    vV.y = v31;
    if ( v30 <= 0.0 )
    {
      v30 = 1.0;
      *(_DWORD *)&v46[124] = 1065353216;
    }
    if ( v31 > 0.0 )
    {
      if ( v31 >= 1.0001 || v31 <= 0.99989998 )
        goto LABEL_36;
    }
    else
    {
      v31 = 1.0;
      vV.y = 1.0;
    }
    if ( v30 < 1.0001 && v30 > 0.99989998 )
    {
      v32 = 1;
      goto LABEL_37;
    }
LABEL_36:
    v32 = 0;
LABEL_37:
    v33 = (float)((float)(v28 * v25) + (float)(*(float *)&v46[100] * v26)) + (float)(*(float *)&v46[104] * v27);
    v34 = v33 < 0.0024999999 && v33 > -0.0024999999;
    x_high = HIBYTE(moveDelta.x);
    if ( HIBYTE(moveDelta.x) != 0 && v34 )
    {
      *(float *)(LODWORD(v20) + 284) = v26 * (float)(1.0 / v30);
      *(float *)(LODWORD(v20) + 288) = v27 * (float)(1.0 / v30);
      v36 = (float)(1.0 / v30) * v25;
      v37 = *(float *)&v46[100];
      v38 = (float)(1.0 / v31) * v28;
      v39 = *(float *)&v46[104];
      *(float *)(LODWORD(v20) + 280) = v36;
      *(float *)(LODWORD(v20) + 296) = v38;
      *(float *)(LODWORD(v20) + 300) = v37 * (float)(1.0 / v31);
      *(float *)(LODWORD(v20) + 304) = v39 * (float)(1.0 / v31);
    }
    if ( v32 != 0 )
    {
      if ( x_high == 0 )
      {
        Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
        CMapFace::InitializeTextureAxes(
          this: (CMapFace *)LODWORD(v20),
          p_UAxis: (Vector4D *)&pDisp,
          eAlignment: Id,
          dwFlags: 3);
      }
    }
    else
    {
      Name = CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)&Options);
      HIBYTE(moveDelta.x) = Name != 0;
      if ( Name != 0 )
      {
        *(float *)(LODWORD(v20) + 316) = *(float *)&v46[124] * *(float *)(LODWORD(v20) + 316);
        *(float *)(LODWORD(v20) + 320) = vV.y * *(float *)(LODWORD(v20) + 320);
      }
    }
    if ( BYTE2(moveDelta.x) != 0 && HIBYTE(moveDelta.x) != 0 )
      CMapFace::OffsetTexture(this: (CMapFace *)LODWORD(v20), Delta: (const Vector *)&v46[108]);
    CMapFace::CalcTextureCoords(this: (CMapFace *)LODWORD(v20), a2: (int)&pDisp);
  }
  v42 = *(_QWORD **)&v46[120];
  if ( *(_DWORD *)&v46[120] != 0 )
  {
    (*(void (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)&v46[120] + 76))(a1: *(_DWORD *)&v46[120], a2: v46);
    *(_QWORD *)&v46[64] = v42[133];
    *(_QWORD *)&v46[72] = v42[134];
    *(_QWORD *)&v46[80] = v42[135];
    CMapDisp::UpdateNeighborsOfDispsIntersectingBox(bbMin: &v44, bbMax: &v45, flPadding: 1.0);
    CMapDisp::UpdateNeighborsOfDispsIntersectingBox(
      bbMin: (const Vector *)&v46[64],
      bbMax: (const Vector *)&v46[76],
      flPadding: 1.0);
  }
  DetailObjects::BuildAnyDetailObjects(pMapFace: (CMapFace *)LODWORD(v20));
}

//------------------------------------------------------------------------------
// Address: 0x1012CA20
// Name: public: CMapFace::CMapFace(void)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall CMapFace::CMapFace(CMapFace *this)
{
  char *NullTextureName; // ebx
  IEditorTexture *ActiveTexture; // eax

  this->__vftable = (CMapFace_vtbl *)&CMapAtom::`vftable';
  this->m_eSelectionState = SELECT_NONE;
  this->m_pParent = nullptr;
  this->m_nObjectID = CMapAtom::s_nObjectIDCtr++;
  this->__vftable = (CMapFace_vtbl *)&CMapFace::`vftable';
  memset(dst: (unsigned __int8 *)&this->texture, value: 0, count: sizeof(this->texture));
  memset(dst: (unsigned __int8 *)&this->plane, value: 0, count: sizeof(this->plane));
  this->m_pTexture = nullptr;
  this->m_pTangentAxes = nullptr;
  this->Points = nullptr;
  this->nPoints = 0;
  this->m_nFaceID = 0;
  this->m_pTextureCoords = nullptr;
  this->m_pLightmapCoords = nullptr;
  this->m_uchAlpha = -1;
  this->m_pDetailObjects = nullptr;
  this->m_DispHandle = -1;
  this->texture.nLightmapScale = g_pGameConfig->m_nDefaultLightmapScale;
  this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
  this->texture.scale[1] = g_pGameConfig->m_fDefaultTextureScale;
  NullTextureName = GetNullTextureName();
  SignalUpdate(ev: 0);
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: NullTextureName,
                    piIndex: nullptr,
                    bDummy: 1);
  CMapFace::SetTexture(this, a2: (int)NullTextureName, pTexture: ActiveTexture, bRescaleTextureCoordinates: false);
  if ( CMapFace::m_pLightmapGrid == nullptr )
    CMapFace::m_pLightmapGrid = CTextureSystem::FindActiveTexture(
                                  this: &g_Textures,
                                  pszInputName: "Debug/debugluxelsnoalpha",
                                  piIndex: nullptr,
                                  bDummy: 1);
  *((_BYTE *)this + 432) &= ~2u;
  this->m_fSmoothingGroups = 0;
  CMapFace::UpdateFaceFlags(this);
  SignalUpdate(ev: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012CB50
// Name: public: static void CMapFace::PushFaceQueue(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMapFace::PushFaceQueue()
{
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *v0; // eax
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *v1; // esi
  int m_Size; // eax
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > **m_pMemory; // ecx

  v0 = (CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *)operator new(nSize: 0x24u);
  if ( v0 != nullptr )
  {
    v0->m_LessFunc = OpaqueFacesLessFunc;
    v0->m_Elements.m_pMemory = nullptr;
    v0->m_Elements.m_nAllocationCount = 0;
    v0->m_Elements.m_nGrowSize = 0;
    v0->m_Root = -1;
    v0->m_NumElements = 0;
    v0->m_FirstFree = -1;
    v0->m_LastAlloc.index = -1;
    v0->m_pElements = v0->m_Elements.m_pMemory;
    v1 = v0;
  }
  else
  {
    v1 = nullptr;
  }
  m_Size = g_OpaqueInstanceFaces.m_Size;
  if ( g_OpaqueInstanceFaces.m_Size + 1 > g_OpaqueInstanceFaces.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&g_OpaqueInstanceFaces,
      num: g_OpaqueInstanceFaces.m_Size - g_OpaqueInstanceFaces.m_Memory.m_nAllocationCount + 1);
    m_Size = g_OpaqueInstanceFaces.m_Size;
  }
  m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  g_OpaqueInstanceFaces.m_Size = m_Size + 1;
  g_OpaqueInstanceFaces.m_pElements = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  if ( m_Size > 0 )
  {
    _V_memmove(
      dest: g_OpaqueInstanceFaces.m_Memory.m_pMemory + 1,
      src: g_OpaqueInstanceFaces.m_Memory.m_pMemory,
      count: 4 * m_Size);
    m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  }
  if ( m_pMemory != nullptr )
  {
    *m_pMemory = v1;
    g_CurrentOpaqueFaces = *g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  }
  else
  {
    g_CurrentOpaqueFaces = (CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *)MEMORY[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CC50
// Name: public: void CMapFaceList::Intersect(class CMapFaceList __near &,class CMapFaceList __near &,class CMapFaceList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFaceList::Intersect(
        CMapFaceList *this,
        CMapFaceList *IntersectWith,
        CUtlMemory<CCullTreeNode *,int> *In,
        CUtlMemory<CCullTreeNode *,int> *Out)
{
  CMapFaceList *v5; // ebx
  CMapFace *v7; // edx
  int m_Size; // ecx
  int v9; // eax
  CMapFace **m_pMemory; // ebx
  int v11; // ebx
  int v12; // eax
  CMapFace **v13; // ecx
  int v14; // eax
  CMapFace **v15; // ecx
  int v16; // eax
  CMapFace **v17; // ecx
  int v18; // eax
  CMapFace **v19; // ecx
  int m_nAllocationCount; // eax
  CMapFace **v21; // ecx
  int v22; // eax
  CMapFace **v23; // ebx
  CMapFace *v24; // edx
  int v25; // ecx
  int v26; // eax
  CMapFace **v27; // ebx
  int v28; // ebx
  int v29; // eax
  CMapFace **v30; // ecx
  int v31; // eax
  CMapFace **v32; // ecx
  int v33; // eax
  CMapFace **v34; // ecx
  int v35; // eax
  CMapFace **v36; // ecx
  int v37; // eax
  CMapFace **v38; // ecx
  int v39; // eax
  CMapFace **v40; // ebx
  int i; // [esp+Ch] [ebp-8h]
  CMapFaceList *Ina; // [esp+20h] [ebp+Ch]
  CMapFace *pFace; // [esp+24h] [ebp+10h]
  CMapFace *pFacea; // [esp+24h] [ebp+10h]

  v5 = this;
  for ( i = 0; i < this->m_Size; v5 = this )
  {
    v7 = v5->m_Memory.m_pMemory[i];
    m_Size = IntersectWith->m_Size;
    v9 = 0;
    pFace = v7;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = IntersectWith->m_Memory.m_pMemory;
    while ( *m_pMemory != v7 )
    {
      ++v9;
      ++m_pMemory;
      if ( v9 >= m_Size )
        goto LABEL_6;
    }
    if ( v9 == -1 )
    {
LABEL_6:
      v11 = (int)Out[1].m_pMemory;
      v12 = 0;
      if ( v11 > 0 )
      {
        v13 = (CMapFace **)Out->m_pMemory;
        while ( *v13 != v7 )
        {
          ++v12;
          ++v13;
          if ( v12 >= v11 )
            goto LABEL_24;
        }
        if ( v12 != -1 )
          goto LABEL_31;
      }
LABEL_24:
      m_nAllocationCount = Out->m_nAllocationCount;
      if ( v11 + 1 > m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(this: Out, num: v11 - m_nAllocationCount + 1);
        v7 = pFace;
      }
      ++Out[1].m_pMemory;
      v21 = (CMapFace **)Out->m_pMemory;
      v22 = (int)Out[1].m_pMemory - v11 - 1;
      Out[1].m_nAllocationCount = (int)Out->m_pMemory;
      if ( v22 > 0 )
      {
        _V_memmove(dest: &v21[v11 + 1], src: &v21[v11], count: 4 * v22);
        v7 = pFace;
      }
      v19 = (CMapFace **)Out->m_pMemory;
    }
    else
    {
      v11 = (int)In[1].m_pMemory;
      v14 = 0;
      if ( v11 > 0 )
      {
        v15 = (CMapFace **)In->m_pMemory;
        while ( *v15 != v7 )
        {
          ++v14;
          ++v15;
          if ( v14 >= v11 )
            goto LABEL_18;
        }
        if ( v14 != -1 )
          goto LABEL_31;
      }
LABEL_18:
      v16 = In->m_nAllocationCount;
      if ( v11 + 1 > v16 )
      {
        CUtlMemory<CVisGroup *,int>::Grow(this: In, num: v11 - v16 + 1);
        v7 = pFace;
      }
      ++In[1].m_pMemory;
      v17 = (CMapFace **)In->m_pMemory;
      v18 = (int)In[1].m_pMemory - v11 - 1;
      In[1].m_nAllocationCount = (int)In->m_pMemory;
      if ( v18 > 0 )
      {
        _V_memmove(dest: &v17[v11 + 1], src: &v17[v11], count: 4 * v18);
        v7 = pFace;
      }
      v19 = (CMapFace **)In->m_pMemory;
    }
    v23 = &v19[v11];
    if ( v23 != nullptr )
      *v23 = v7;
LABEL_31:
    ++i;
  }
  Ina = nullptr;
  if ( IntersectWith->m_Size > 0 )
  {
    while ( 1 )
    {
      v24 = IntersectWith->m_Memory.m_pMemory[(_DWORD)Ina];
      v25 = v5->m_Size;
      v26 = 0;
      pFacea = v24;
      if ( v25 <= 0 )
        goto LABEL_39;
      v27 = v5->m_Memory.m_pMemory;
      while ( *v27 != v24 )
      {
        ++v26;
        ++v27;
        if ( v26 >= v25 )
          goto LABEL_39;
      }
      if ( v26 == -1 )
      {
LABEL_39:
        v28 = (int)Out[1].m_pMemory;
        v29 = 0;
        if ( v28 <= 0 )
          goto LABEL_57;
        v30 = (CMapFace **)Out->m_pMemory;
        while ( *v30 != v24 )
        {
          ++v29;
          ++v30;
          if ( v29 >= v28 )
            goto LABEL_57;
        }
        if ( v29 == -1 )
        {
LABEL_57:
          v37 = Out->m_nAllocationCount;
          if ( v28 + 1 > v37 )
          {
            CUtlMemory<CVisGroup *,int>::Grow(this: Out, num: v28 - v37 + 1);
            v24 = pFacea;
          }
          ++Out[1].m_pMemory;
          v38 = (CMapFace **)Out->m_pMemory;
          v39 = (int)Out[1].m_pMemory - v28 - 1;
          Out[1].m_nAllocationCount = (int)Out->m_pMemory;
          if ( v39 > 0 )
          {
            _V_memmove(dest: &v38[v28 + 1], src: &v38[v28], count: 4 * v39);
            v24 = pFacea;
          }
          v36 = (CMapFace **)Out->m_pMemory;
LABEL_62:
          v40 = &v36[v28];
          if ( v40 != nullptr )
            *v40 = v24;
        }
      }
      else
      {
        v28 = (int)In[1].m_pMemory;
        v31 = 0;
        if ( v28 <= 0 )
          goto LABEL_51;
        v32 = (CMapFace **)In->m_pMemory;
        while ( *v32 != v24 )
        {
          ++v31;
          ++v32;
          if ( v31 >= v28 )
            goto LABEL_51;
        }
        if ( v31 == -1 )
        {
LABEL_51:
          v33 = In->m_nAllocationCount;
          if ( v28 + 1 > v33 )
          {
            CUtlMemory<CVisGroup *,int>::Grow(this: In, num: v28 - v33 + 1);
            v24 = pFacea;
          }
          ++In[1].m_pMemory;
          v34 = (CMapFace **)In->m_pMemory;
          v35 = (int)In[1].m_pMemory - v28 - 1;
          In[1].m_nAllocationCount = (int)In->m_pMemory;
          if ( v35 > 0 )
          {
            _V_memmove(dest: &v34[v28 + 1], src: &v34[v28], count: 4 * v35);
            v24 = pFacea;
          }
          v36 = (CMapFace **)In->m_pMemory;
          goto LABEL_62;
        }
      }
      Ina = (CMapFaceList *)((char *)Ina + 1);
      if ( (int)Ina >= IntersectWith->m_Size )
        return;
      v5 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CEE0
// Name: public: void CMapFaceIDList::Intersect(class CMapFaceIDList __near &,class CMapFaceIDList __near &,class CMapFaceIDList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFaceIDList::Intersect(
        CMapFaceIDList *this,
        CMapFaceIDList *IntersectWith,
        CUtlMemory<vgui::TreeNode *,int> *In,
        CUtlMemory<vgui::TreeNode *,int> *Out)
{
  CMapFaceIDList *v5; // ebx
  int v7; // edx
  int m_Size; // ecx
  int v9; // eax
  int *m_pMemory; // ebx
  int v11; // ebx
  int v12; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // ecx
  int v16; // eax
  int *v17; // ecx
  int v18; // eax
  int *v19; // ecx
  int m_nAllocationCount; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // ebx
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  int *v27; // ebx
  int v28; // ebx
  int v29; // eax
  int *v30; // ecx
  int v31; // eax
  int *v32; // ecx
  int v33; // eax
  int *v34; // ecx
  int v35; // eax
  int *v36; // ecx
  int v37; // eax
  int *v38; // ecx
  int v39; // eax
  int *v40; // ebx
  int i; // [esp+Ch] [ebp-8h]
  CMapFaceIDList *Ina; // [esp+20h] [ebp+Ch]
  int nFaceID; // [esp+24h] [ebp+10h]
  int nFaceIDa; // [esp+24h] [ebp+10h]

  v5 = this;
  for ( i = 0; i < this->m_Size; v5 = this )
  {
    v7 = v5->m_Memory.m_pMemory[i];
    m_Size = IntersectWith->m_Size;
    v9 = 0;
    nFaceID = v7;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = IntersectWith->m_Memory.m_pMemory;
    while ( *m_pMemory != v7 )
    {
      ++v9;
      ++m_pMemory;
      if ( v9 >= m_Size )
        goto LABEL_6;
    }
    if ( v9 == -1 )
    {
LABEL_6:
      v11 = (int)Out[1].m_pMemory;
      v12 = 0;
      if ( v11 > 0 )
      {
        v13 = (int *)Out->m_pMemory;
        while ( *v13 != v7 )
        {
          ++v12;
          ++v13;
          if ( v12 >= v11 )
            goto LABEL_24;
        }
        if ( v12 != -1 )
          goto LABEL_31;
      }
LABEL_24:
      m_nAllocationCount = Out->m_nAllocationCount;
      if ( v11 + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: Out, num: v11 - m_nAllocationCount + 1);
        v7 = nFaceID;
      }
      ++Out[1].m_pMemory;
      v21 = (int *)Out->m_pMemory;
      v22 = (int)Out[1].m_pMemory - v11 - 1;
      Out[1].m_nAllocationCount = (int)Out->m_pMemory;
      if ( v22 > 0 )
      {
        _V_memmove(dest: &v21[v11 + 1], src: &v21[v11], count: 4 * v22);
        v7 = nFaceID;
      }
      v19 = (int *)Out->m_pMemory;
    }
    else
    {
      v11 = (int)In[1].m_pMemory;
      v14 = 0;
      if ( v11 > 0 )
      {
        v15 = (int *)In->m_pMemory;
        while ( *v15 != v7 )
        {
          ++v14;
          ++v15;
          if ( v14 >= v11 )
            goto LABEL_18;
        }
        if ( v14 != -1 )
          goto LABEL_31;
      }
LABEL_18:
      v16 = In->m_nAllocationCount;
      if ( v11 + 1 > v16 )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: In, num: v11 - v16 + 1);
        v7 = nFaceID;
      }
      ++In[1].m_pMemory;
      v17 = (int *)In->m_pMemory;
      v18 = (int)In[1].m_pMemory - v11 - 1;
      In[1].m_nAllocationCount = (int)In->m_pMemory;
      if ( v18 > 0 )
      {
        _V_memmove(dest: &v17[v11 + 1], src: &v17[v11], count: 4 * v18);
        v7 = nFaceID;
      }
      v19 = (int *)In->m_pMemory;
    }
    v23 = &v19[v11];
    if ( v23 != nullptr )
      *v23 = v7;
LABEL_31:
    ++i;
  }
  Ina = nullptr;
  if ( IntersectWith->m_Size > 0 )
  {
    while ( 1 )
    {
      v24 = IntersectWith->m_Memory.m_pMemory[(_DWORD)Ina];
      v25 = v5->m_Size;
      v26 = 0;
      nFaceIDa = v24;
      if ( v25 <= 0 )
        goto LABEL_39;
      v27 = v5->m_Memory.m_pMemory;
      while ( *v27 != v24 )
      {
        ++v26;
        ++v27;
        if ( v26 >= v25 )
          goto LABEL_39;
      }
      if ( v26 == -1 )
      {
LABEL_39:
        v28 = (int)Out[1].m_pMemory;
        v29 = 0;
        if ( v28 <= 0 )
          goto LABEL_57;
        v30 = (int *)Out->m_pMemory;
        while ( *v30 != v24 )
        {
          ++v29;
          ++v30;
          if ( v29 >= v28 )
            goto LABEL_57;
        }
        if ( v29 == -1 )
        {
LABEL_57:
          v37 = Out->m_nAllocationCount;
          if ( v28 + 1 > v37 )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: Out, num: v28 - v37 + 1);
            v24 = nFaceIDa;
          }
          ++Out[1].m_pMemory;
          v38 = (int *)Out->m_pMemory;
          v39 = (int)Out[1].m_pMemory - v28 - 1;
          Out[1].m_nAllocationCount = (int)Out->m_pMemory;
          if ( v39 > 0 )
          {
            _V_memmove(dest: &v38[v28 + 1], src: &v38[v28], count: 4 * v39);
            v24 = nFaceIDa;
          }
          v36 = (int *)Out->m_pMemory;
LABEL_62:
          v40 = &v36[v28];
          if ( v40 != nullptr )
            *v40 = v24;
        }
      }
      else
      {
        v28 = (int)In[1].m_pMemory;
        v31 = 0;
        if ( v28 <= 0 )
          goto LABEL_51;
        v32 = (int *)In->m_pMemory;
        while ( *v32 != v24 )
        {
          ++v31;
          ++v32;
          if ( v31 >= v28 )
            goto LABEL_51;
        }
        if ( v31 == -1 )
        {
LABEL_51:
          v33 = In->m_nAllocationCount;
          if ( v28 + 1 > v33 )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: In, num: v28 - v33 + 1);
            v24 = nFaceIDa;
          }
          ++In[1].m_pMemory;
          v34 = (int *)In->m_pMemory;
          v35 = (int)In[1].m_pMemory - v28 - 1;
          In[1].m_nAllocationCount = (int)In->m_pMemory;
          if ( v35 > 0 )
          {
            _V_memmove(dest: &v34[v28 + 1], src: &v34[v28], count: 4 * v35);
            v24 = nFaceIDa;
          }
          v36 = (int *)In->m_pMemory;
          goto LABEL_62;
        }
      }
      Ina = (CMapFaceIDList *)((char *)Ina + 1);
      if ( (int)Ina >= IntersectWith->m_Size )
        return;
      v5 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D170
// Name: public: virtual void CMapFace::AddShadowingTriangles(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::AddShadowingTriangles(CMapFace *this, CUtlVector<Vector,CUtlMemory<Vector,int> > *tri_list)
{
  CMapFace *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // eax
  Vector *v12; // ecx
  int v13; // eax
  Vector *v14; // eax
  int v15; // edi
  int v16; // eax
  Vector *v17; // ebx
  Vector *v18; // ecx
  int v19; // eax
  Vector *v20; // eax
  Vector *Points; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int tri_lista; // [esp+18h] [ebp+8h]

  v2 = this;
  if ( (this->m_nFaceFlags & 1) == 0 )
  {
    i = 2;
    if ( this->nPoints > 2 )
    {
      tri_lista = 2;
      while ( 1 )
      {
        m_Size = tri_list->m_Size;
        Points = v2->Points;
        m_nAllocationCount = tri_list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CheckListItem,int>::Grow(this: &tri_list->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++tri_list->m_Size;
        m_pMemory = tri_list->m_Memory.m_pMemory;
        v7 = tri_list->m_Size - m_Size - 1;
        tri_list->m_pElements = tri_list->m_Memory.m_pMemory;
        if ( v7 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v7);
        v8 = &tri_list->m_Memory.m_pMemory[m_Size];
        if ( v8 != nullptr )
        {
          *(_QWORD *)&v8->x = *(_QWORD *)&Points->x;
          v8->z = Points->z;
        }
        v9 = tri_list->m_Size;
        v10 = (int)&v2->Points[tri_lista - 1];
        v11 = tri_list->m_Memory.m_nAllocationCount;
        if ( v9 + 1 > v11 )
          CUtlMemory<CheckListItem,int>::Grow(this: &tri_list->m_Memory, num: v9 - v11 + 1);
        ++tri_list->m_Size;
        v12 = tri_list->m_Memory.m_pMemory;
        v13 = tri_list->m_Size - v9 - 1;
        tri_list->m_pElements = tri_list->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[v9 + 1], src: &v12[v9], count: 12 * v13);
        v14 = &tri_list->m_Memory.m_pMemory[v9];
        if ( v14 != nullptr )
        {
          *(_QWORD *)&v14->x = *(_QWORD *)v10;
          v14->z = *(float *)(v10 + 8);
        }
        v15 = tri_list->m_Size;
        v16 = tri_list->m_Memory.m_nAllocationCount;
        v17 = &this->Points[tri_lista];
        if ( v15 + 1 > v16 )
          CUtlMemory<CheckListItem,int>::Grow(this: &tri_list->m_Memory, num: v15 - v16 + 1);
        ++tri_list->m_Size;
        v18 = tri_list->m_Memory.m_pMemory;
        v19 = tri_list->m_Size - v15 - 1;
        tri_list->m_pElements = tri_list->m_Memory.m_pMemory;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[v15 + 1], src: &v18[v15], count: 12 * v19);
        v20 = &tri_list->m_Memory.m_pMemory[v15];
        if ( v20 != nullptr )
        {
          *(_QWORD *)&v20->x = *(_QWORD *)&v17->x;
          v20->z = v17->z;
        }
        ++tri_lista;
        if ( ++i >= this->nPoints )
          break;
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D320
// Name: public: static void CMapFace::PopFaceQueue(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMapFace::PopFaceQueue()
{
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > **m_pMemory; // ecx
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > *v1; // esi

  m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  v1 = *g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  if ( g_OpaqueInstanceFaces.m_Size - 1 > 0 )
  {
    _V_memmove(
      dest: g_OpaqueInstanceFaces.m_Memory.m_pMemory,
      src: g_OpaqueInstanceFaces.m_Memory.m_pMemory + 1,
      count: 4 * (g_OpaqueInstanceFaces.m_Size - 1));
    m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  }
  --g_OpaqueInstanceFaces.m_Size;
  if ( v1 != nullptr )
  {
    CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::~CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>(this: v1);
    operator delete(p: v1);
    m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  }
  if ( g_OpaqueInstanceFaces.m_Size != 0 )
    g_CurrentOpaqueFaces = *m_pMemory;
  else
    g_CurrentOpaqueFaces = &g_OpaqueFaces;
}

//------------------------------------------------------------------------------
// Address: 0x1012D410
// Name: public: static void CMapFace::AddFaceToQueue(class CMapFace __near *,class IEditorTexture __near *,enum EditorRenderMode_t,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapFace::AddFaceToQueue(
        const char *a1@<edi>,
        CMapFace *pMapFace,
        IEditorTexture *pTexture,
        EditorRenderMode_t renderMode,
        bool selected,
        SelectionState_t faceSelectionState)
{
  MapFaceRender_t newEntry; // [esp+0h] [ebp-14h] BYREF

  newEntry.m_pTexture = pTexture;
  newEntry.m_RenderSelected = selected;
  newEntry.m_RenderMode = renderMode;
  newEntry.m_FaceSelectionState = faceSelectionState;
  newEntry.m_pMapFace = pMapFace;
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::Insert(
    this: g_CurrentOpaqueFaces,
    a2: a1,
    insert: &newEntry);
}

//------------------------------------------------------------------------------
// Address: 0x1012D450
// Name: public: virtual void CMapFace::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::Render3D(CMapFace *this, CRender3D *pRender)
{
  SelectionState_t v3; // eax
  const char *v4; // edi
  bool v5; // bl
  bool v6; // zf
  IEditorTexture *m_pTexture; // eax
  MapFaceRender_t insert; // [esp+4h] [ebp-1Ch] BYREF
  EditorRenderMode_t eCurrentRenderMode; // [esp+18h] [ebp-8h]
  int renderSelected; // [esp+1Ch] [ebp-4h]

  if ( this->nPoints == 0 )
    return;
  eCurrentRenderMode = pRender->m_eCurrentRenderMode;
  if ( eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED && (this->m_nFaceFlags & 2) != 0 )
    return;
  v3 = this->GetSelectionState(this);
  v4 = (const char *)v3;
  if ( this->m_pParent != nullptr )
    v3 = this->m_pParent->GetSelectionState(this: this->m_pParent);
  if ( Options.general.bShowNoDrawBrushes != 0 )
  {
    if ( v3 != SELECT_NONE )
      goto LABEL_14;
  }
  else
  {
    if ( v3 != SELECT_NONE )
      goto LABEL_14;
    if ( this->m_pTexture == g_Textures.m_pNoDrawTexture )
      return;
  }
  if ( v4 == nullptr || !CMapFace::m_bShowFaceSelection )
  {
    v5 = false;
    goto LABEL_15;
  }
LABEL_14:
  v5 = true;
LABEL_15:
  v6 = !pRender->m_DeferRendering;
  LOBYTE(renderSelected) = v5;
  if ( v6 )
  {
    CRender::BindTexture(this: pRender, pTexture: this->m_pTexture);
    CMapFace::RenderFace3D(
      this,
      pRender,
      renderMode: (CMapFace *)eCurrentRenderMode,
      renderSelected,
      faceSelectionState: (Color)v4);
    if ( v5 && CRender3D::NeedsOverlay(this: pRender) )
      CMapFace::RenderFace3D(this, pRender, renderMode: (CMapFace *)0xC, renderSelected, faceSelectionState: (Color)v4);
  }
  else
  {
    m_pTexture = this->m_pTexture;
    insert.m_RenderMode = eCurrentRenderMode;
    insert.m_pTexture = m_pTexture;
    insert.m_RenderSelected = v5;
    insert.m_pMapFace = this;
    insert.m_FaceSelectionState = (SelectionState_t)v4;
    CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::Insert(
      this: g_CurrentOpaqueFaces,
      a2: v4,
      &insert);
    if ( v5 && CRender3D::NeedsOverlay(this: pRender) )
      CMapFace::AddFaceToQueue(
        a1: v4,
        pMapFace: this,
        pTexture: this->m_pTexture,
        renderMode: RENDER_MODE_SELECTION_OVERLAY,
        selected: renderSelected,
        faceSelectionState: (SelectionState_t)v4);
  }
}
