// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/detailobjects.cpp
// Functions: 19
// ============================================================

#include "utils\vbsp\detailobjects.h"

//------------------------------------------------------------------------------
// Address: 0x00407560
// Name: public: void Vector2D::Init(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector2D::Init(Vector2D *this, float ix, float iy)
{
  this->x = ix;
  this->y = iy;
}

//------------------------------------------------------------------------------
// Address: 0x004075A0
// Name: FindDetailVBSPName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FindDetailVBSPName()
{
  int v0; // esi
  entity_t *i; // edi
  char *result; // eax

  v0 = 0;
  if ( num_entities <= 0 )
    return "detail.vbsp";
  for ( i = (entity_t *)&entities; strcmp(ValueForKey(ent: i, key: "classname"), "worldspawn") != 0; ++i )
  {
    if ( ++v0 >= num_entities )
      return "detail.vbsp";
  }
  result = ValueForKey(ent: (entity_t *)&entities + v0, key: "detailvbsp");
  if ( result == nullptr || *result == 0 )
    return "detail.vbsp";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407630
// Name: ComputeDetailLeaf
// Source: json
//------------------------------------------------------------------------------
int __usercall ComputeDetailLeaf@<eax>(const Vector *pt@<eax>)
{
  int v1; // ecx
  dnode_t *v2; // ecx

  v1 = 0;
  do
  {
    v2 = &dnodes[v1];
    if ( dplanes[v2->planenum].dist <= (float)((float)((float)(*(float *)&dword_7638ADC[5 * v2->planenum] * pt->y)
                                                     + (float)(dplanes[v2->planenum].normal.x * pt->x))
                                             + (float)(dplanes[v2->planenum].normal.z * pt->z)) )
      v1 = v2->children[0];
    else
      v1 = v2->children[1];
  }
  while ( v1 >= 0 );
  return -1 - v1;
}

//------------------------------------------------------------------------------
// Address: 0x004076A0
// Name: ComputeDisplacementFaceArea
// Source: json
//------------------------------------------------------------------------------
float *__usercall ComputeDisplacementFaceArea@<eax>(dface_t *pFace@<eax>)
{
  int firstedge; // edi
  int v2; // ecx
  int *v3; // edi
  int v4; // esi
  int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  int v9; // eax
  BOOL v10; // ecx
  dedge_t *v11; // eax
  int v12; // edx
  int v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm6_4
  int v16; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float *result; // eax
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // [esp-10h] [ebp-1Ch]
  float v24; // [esp-Ch] [ebp-18h]
  float v25; // [esp-8h] [ebp-14h]
  float v26; // [esp-4h] [ebp-10h]

  firstedge = pFace->firstedge;
  v2 = dsurfedges[firstedge];
  v3 = &dsurfedges[firstedge];
  v26 = 0.0;
  v4 = 1;
  v5 = 3 * dedges[abs32(v2)].v[v2 < 0];
  v6 = *(&dvertexes.x + v5);
  v7 = *(&dvertexes.y + v5);
  v8 = *(&dvertexes.z + v5);
  v23 = v6;
  v24 = v7;
  v25 = v8;
  while ( 1 )
  {
    v9 = v3[v4];
    v10 = v9 < 0;
    v11 = &dedges[abs32(v9)];
    ++v4;
    v12 = 2 * v10;
    v13 = 3 * v11->v[v10];
    v14 = *(&dvertexes.z + v13) - v8;
    v15 = *(&dvertexes.x + v13) - v6;
    v16 = 3 * v11->v[v12 / 0xFFFFFFFE + 1];
    v17 = *(&dvertexes.x + v16) - v6;
    v18 = *(&dvertexes.y + v16);
    result = &dvertexes.x + v16;
    v20 = v18 - v7;
    v21 = *(&dvertexes.y + v13) - v7;
    v22 = result[2] - v8;
    v26 = (float)(fsqrt(
                    (float)((float)((float)((float)(v17 * v14) - (float)(v22 * v15))
                                  * (float)((float)(v17 * v14) - (float)(v22 * v15)))
                          + (float)((float)((float)(v20 * v15) - (float)(v17 * v21))
                                  * (float)((float)(v20 * v15) - (float)(v17 * v21))))
                  + (float)((float)((float)(v22 * v21) - (float)(v20 * v14))
                          * (float)((float)(v22 * v21) - (float)(v20 * v14))))
                * 0.5)
        + v26;
    if ( v4 > 2 )
      break;
    v8 = v25;
    v7 = v24;
    v6 = v23;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407840
// Name: SortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortFunc(unsigned __int16 *arg1, unsigned __int16 *arg2)
{
  if ( arg1[13] - arg2[13] >= 0 )
    return arg1[13] > (unsigned int)arg2[13];
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00407BD0
// Name: SelectGroup
// Source: json
//------------------------------------------------------------------------------
int __usercall SelectGroup@<eax>(int a1@<edx>, float a2@<xmm0>)
{
  int v2; // ebx
  int v3; // eax
  int v4; // esi
  float *v5; // ecx
  float *v6; // ecx
  int v7; // edi
  int result; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  float dist; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 20);
  v3 = v2 - 1;
  v4 = 0;
  if ( v2 - 1 < 4 )
  {
LABEL_8:
    if ( v4 < v3 )
    {
      v6 = (float *)(*(_DWORD *)(a1 + 8) + 8 * (3 * v4 + 3));
      do
      {
        if ( *v6 > a2 )
          break;
        ++v4;
        v6 += 6;
      }
      while ( v4 < v3 );
    }
  }
  else
  {
    v5 = (float *)(*(_DWORD *)(a1 + 8) + 48);
    while ( *(v5 - 6) <= a2 )
    {
      if ( *v5 > a2 )
      {
        ++v4;
        break;
      }
      if ( v5[6] > a2 )
      {
        v4 += 2;
        break;
      }
      if ( v5[12] > a2 )
      {
        v4 += 3;
        break;
      }
      v4 += 4;
      v5 += 24;
      if ( v4 >= v2 - 4 )
        goto LABEL_8;
    }
  }
  v7 = v4 + 1;
  if ( v4 + 1 >= v2 )
    v7 = v4;
  if ( v4 == v7 )
    return v4;
  v9 = *(float *)(*(_DWORD *)(a1 + 8) + 24 * v7) - *(float *)(*(_DWORD *)(a1 + 8) + 24 * v4);
  dist = 0.0;
  if ( v9 != 0.0 )
    dist = (float)(a2 - *(float *)(*(_DWORD *)(a1 + 8) + 24 * v4)) / v9;
  v10 = (float)rand() * 0.000030518509;
  result = v4;
  if ( v10 <= dist )
    return v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407CD0
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: (unsigned int *)&src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408CF0
// Name: AddDetailDictLump
// Source: json
//------------------------------------------------------------------------------
int __usercall AddDetailDictLump@<eax>(char *pModelName@<eax>)
{
  int m_Size; // eax
  int v2; // esi
  char *v3; // edi
  unsigned int v4; // edx
  DetailObjectDictLump_t *i; // ecx
  int v6; // ebx
  int v7; // eax
  DetailObjectDictLump_t *v8; // edi
  DetailObjectDictLump_t dictLump; // [esp+Ch] [ebp-80h] BYREF

  strncpy(dest: (unsigned __int8 *)&dictLump, source: (unsigned __int8 *)pModelName, count: 0x80u);
  m_Size = s_DetailObjectDictLump.m_Size;
  v2 = s_DetailObjectDictLump.m_Size - 1;
  if ( s_DetailObjectDictLump.m_Size - 1 >= 0 )
  {
    v3 = &s_DetailObjectDictLump.m_Memory.m_pMemory->m_Name[(v2 << 7) - (_DWORD)&dictLump];
    while ( 2 )
    {
      v4 = 128;
      for ( i = &dictLump; ; i = (DetailObjectDictLump_t *)((char *)i + 4) )
      {
        if ( v4 < 4 )
          return v2;
        if ( *(_DWORD *)&i->m_Name[(_DWORD)v3] != *(_DWORD *)i->m_Name )
          break;
        v4 -= 4;
      }
      v3 -= 128;
      if ( --v2 >= 0 )
        continue;
      break;
    }
  }
  v6 = s_DetailObjectDictLump.m_Size;
  if ( s_DetailObjectDictLump.m_Size + 1 > s_DetailObjectDictLump.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<StaticPropDictLump_t,int>::Grow(
      this: &s_DetailObjectDictLump.m_Memory,
      num: s_DetailObjectDictLump.m_Size - s_DetailObjectDictLump.m_Memory.m_nAllocationCount + 1);
    m_Size = s_DetailObjectDictLump.m_Size;
  }
  s_DetailObjectDictLump.m_Size = m_Size + 1;
  v7 = m_Size - v6;
  s_DetailObjectDictLump.m_pElements = s_DetailObjectDictLump.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: &s_DetailObjectDictLump.m_Memory.m_pMemory[v6 + 1],
      src: &s_DetailObjectDictLump.m_Memory.m_pMemory[v6],
      count: v7 << 7);
  v8 = &s_DetailObjectDictLump.m_Memory.m_pMemory[v6];
  if ( v8 != nullptr )
    *v8 = dictLump;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00408DE0
// Name: AddDetailSpriteToLump
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDetailSpriteToLump(
        const Vector2D *pTex@<eax>,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        unsigned __int8 nOrientation,
        const Vector2D *pPos,
        float flScale,
        unsigned __int8 iType,
        unsigned __int8 iShapeAngle,
        unsigned __int8 iShapeSize,
        unsigned __int8 iSwayAmount)
{
  int m_Size; // eax
  int v12; // esi
  int v13; // eax
  DetailObjectLump_t *v14; // esi
  int v15; // ecx
  char *v16; // edi
  unsigned int v17; // edx
  DetailSpriteDictLump_t *i; // eax
  unsigned __int16 v19; // ax
  DetailSpriteDictLump_t src; // [esp+Ch] [ebp-20h] BYREF

  m_Size = s_DetailObjectLump.m_Size;
  v12 = s_DetailObjectLump.m_Size;
  if ( s_DetailObjectLump.m_Size + 1 > s_DetailObjectLump.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<DetailObjectLump_t,int>::Grow(
      this: &s_DetailObjectLump.m_Memory,
      num: s_DetailObjectLump.m_Size - s_DetailObjectLump.m_Memory.m_nAllocationCount + 1);
    m_Size = s_DetailObjectLump.m_Size;
  }
  s_DetailObjectLump.m_Size = m_Size + 1;
  v13 = m_Size - v12;
  s_DetailObjectLump.m_pElements = s_DetailObjectLump.m_Memory.m_pMemory;
  if ( v13 > 0 )
    _V_memmove(
      dest: &s_DetailObjectLump.m_Memory.m_pMemory[v12 + 1],
      src: &s_DetailObjectLump.m_Memory.m_pMemory[v12],
      count: 52 * v13);
  if ( v12 >= 0xFFFF )
    _Error(a1: "Error! Too many detail props emitted on this map! (64K max!)n");
  v14 = &s_DetailObjectLump.m_Memory.m_pMemory[v12];
  v15 = s_DetailSpriteDictLump.m_Size - 1;
  src.m_UL = *pPos;
  src.m_LR = pPos[1];
  src.m_TexUL = *pTex;
  src.m_TexLR = pTex[1];
  if ( s_DetailSpriteDictLump.m_Size - 1 >= 0 )
  {
    v16 = (char *)s_DetailSpriteDictLump.m_Memory.m_pMemory + 32 * v15 - (_DWORD)&src;
    while ( 2 )
    {
      v17 = 32;
      for ( i = &src; ; i = (DetailSpriteDictLump_t *)((char *)i + 4) )
      {
        if ( v17 < 4 )
        {
          v19 = v15;
          goto LABEL_15;
        }
        if ( *(_DWORD *)((char *)&i->m_UL.x + (_DWORD)v16) != LODWORD(i->m_UL.x) )
          break;
        v17 -= 4;
      }
      v16 -= 32;
      if ( --v15 >= 0 )
        continue;
      break;
    }
  }
  v19 = CUtlVector<DetailSpriteDictLump_t,CUtlMemory<DetailSpriteDictLump_t,int>>::InsertBefore(
          this: &s_DetailSpriteDictLump,
          elem: s_DetailSpriteDictLump.m_Size,
          &src);
LABEL_15:
  v14->m_DetailModel = v19;
  v14->m_Angles = *vecAngles;
  v14->m_Origin = *vecOrigin;
  v14->m_Leaf = ComputeDetailLeaf(pt: vecOrigin);
  v14->m_Orientation = nOrientation;
  v14->m_Type = iType;
  v14->m_Lighting = (ColorRGBExp32)&unk_FFFFFF;
  v14->m_LightStyles = 0;
  v14->m_LightStyleCount = 0;
  v14->m_flScale = flScale;
  v14->m_ShapeAngle = iShapeAngle;
  v14->m_ShapeSize = iShapeSize;
  v14->m_SwayAmount = iSwayAmount;
}

//------------------------------------------------------------------------------
// Address: 0x004090F0
// Name: IsModelValid
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsModelValid@<al>(const char *pModelName@<esi>, int a2@<ebx>)
{
  unsigned __int16 v2; // ax
  bool m_IsValid; // bl
  const char *v5; // [esp+0h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+4h] [ebp-38h] BYREF
  StaticPropLookup_t lookup; // [esp+34h] [ebp-8h] BYREF
  CUtlSymbol v9; // [esp+3Ah] [ebp-2h] BYREF

  CUtlSymbol::CUtlSymbol(this: &v9, pStr: v5);
  lookup.m_ModelName = v9;
  v2 = CUtlRBTree<StaticPropLookup_t,unsigned short,bool (__cdecl *)(StaticPropLookup_t const &,StaticPropLookup_t const &),CUtlMemory<UtlRBTreeNode_t<StaticPropLookup_t,unsigned short>,unsigned short>>::Find(
         this: &s_StaticPropLookup,
         search: &lookup);
  if ( v2 != 0xFFFF )
    return s_StaticPropLookup.m_Elements.m_pMemory[v2].m_Data.m_IsValid;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  lookup.m_IsValid = LoadStudioModel(pModelName, pEntityType: "detail_prop", &buf);
  if ( !lookup.m_IsValid )
    _Warning(a1: "Error loading studio model \"%s\"!\n", pModelName);
  CUtlRBTree<StaticPropLookup_t,unsigned short,bool (__cdecl *)(StaticPropLookup_t const &,StaticPropLookup_t const &),CUtlMemory<UtlRBTreeNode_t<StaticPropLookup_t,unsigned short>,unsigned short>>::Insert(
    this: &s_StaticPropLookup,
    insert: &lookup);
  m_IsValid = lookup.m_IsValid;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    ((void (__thiscall *)(IMemAlloc *, unsigned __int8 *, int))_g_pMemAlloc->Free_2)(
      a1: _g_pMemAlloc,
      a2: buf.m_Memory.m_pMemory,
      a3: a2);
  return m_IsValid;
}

//------------------------------------------------------------------------------
// Address: 0x004091B0
// Name: AddDetailToLump
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDetailToLump(
        char *pModelName@<eax>,
        const Vector *pt,
        const QAngle *angles,
        unsigned __int8 nOrientation)
{
  DetailObjectLump_t *v5; // edi

  if ( IsModelValid(pModelName, a2: (int)pt) )
  {
    if ( s_DetailObjectLump.m_Size == 0xFFFF )
    {
      ++s_nDetailOverflow;
    }
    else
    {
      v5 = &s_DetailObjectLump.m_Memory.m_pMemory[CUtlVector<DetailObjectLump_t,CUtlMemory<DetailObjectLump_t,int>>::AddToTail(this: &s_DetailObjectLump)];
      v5->m_DetailModel = AddDetailDictLump(pModelName);
      v5->m_Angles = *angles;
      v5->m_Origin = *pt;
      v5->m_Leaf = ComputeDetailLeaf(pt);
      v5->m_Lighting.b = -1;
      *(_WORD *)&v5->m_Lighting.r = -1;
      v5->m_Lighting.exponent = 0;
      v5->m_LightStyles = 0;
      v5->m_LightStyleCount = 0;
      v5->m_Orientation = nOrientation;
      v5->m_Type = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409260
// Name: PlaceDetail
// Source: json
//------------------------------------------------------------------------------
void __usercall PlaceDetail(const Vector *normal@<eax>, DetailModel_t *model, const Vector *pt)
{
  DetailModel_t *v3; // esi
  float z; // xmm0_4
  float m_MinCosAngle; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  const VMatrix *v10; // eax
  int v11; // eax
  entity_t *v12; // edi
  int v13; // esi
  float v14; // xmm1_4
  char *v15; // eax
  int fDegrees; // [esp+10h] [ebp-110h]
  VMatrix result; // [esp+20h] [ebp-100h] BYREF
  VMatrix rot; // [esp+60h] [ebp-C0h] BYREF
  VMatrix matrix; // [esp+A0h] [ebp-80h] BYREF
  Vector vAxis; // [esp+E0h] [ebp-40h] BYREF
  QAngle angles; // [esp+ECh] [ebp-34h] BYREF
  Vector yaxis; // [esp+F8h] [ebp-28h] BYREF
  Vector xaxis; // [esp+104h] [ebp-1Ch] BYREF
  Vector zaxis; // [esp+110h] [ebp-10h] BYREF
  int i; // [esp+11Ch] [ebp-4h]
  float flScale; // [esp+128h] [ebp+8h]

  v3 = model;
  z = normal->z;
  if ( model->m_MaxCosAngle <= z )
  {
    m_MinCosAngle = model->m_MinCosAngle;
    if ( m_MinCosAngle <= z
      || (*(float *)&i = (float)(z - model->m_MaxCosAngle) / (float)(m_MinCosAngle - model->m_MaxCosAngle),
          (float)((float)rand() * 0.000030518509) <= *(float *)&i) )
    {
      if ( (model->m_Flags & 1) != 0 )
      {
        angles.x = 0.0;
        angles.y = (float)((float)rand() * 360.0) * 0.000030518509;
        angles.z = 0.0;
      }
      else
      {
        zaxis = *normal;
        VectorNormalize(vec: &zaxis);
        v7 = 1.0;
        v8 = 0.0;
        xaxis.x = 1.0;
        xaxis.y = 0.0;
        xaxis.z = 0.0;
        if ( (float)(COERCE_FLOAT(
                       COERCE_UNSIGNED_INT((float)((float)(zaxis.y * 0.0) + zaxis.x) + (float)(zaxis.z * 0.0))
                     & _mask__AbsFloat_)
                   - 1.0) > -0.001 )
        {
          v7 = 0.0;
          v8 = 1.0;
          xaxis.x = 0.0;
          xaxis.y = 1.0;
          xaxis.z = 0.0;
        }
        yaxis.x = (float)(zaxis.y * 0.0) - (float)(v8 * zaxis.z);
        yaxis.y = (float)(zaxis.z * v7) - (float)(zaxis.x * 0.0);
        yaxis.z = (float)(v8 * zaxis.x) - (float)(zaxis.y * v7);
        VectorNormalize(vec: &yaxis);
        xaxis.x = (float)(yaxis.y * zaxis.z) - (float)(yaxis.z * zaxis.y);
        xaxis.y = (float)(yaxis.z * zaxis.x) - (float)(zaxis.z * yaxis.x);
        xaxis.z = (float)(zaxis.y * yaxis.x) - (float)(yaxis.y * zaxis.x);
        VectorNormalize(vec: &xaxis);
        *(_QWORD *)&matrix.m[0][0] = __PAIR64__(LODWORD(yaxis.x), LODWORD(xaxis.x));
        *(_QWORD *)&matrix.m[1][0] = __PAIR64__(LODWORD(yaxis.y), LODWORD(xaxis.y));
        *(_QWORD *)&matrix.m[2][0] = __PAIR64__(LODWORD(yaxis.z), LODWORD(xaxis.z));
        *(_QWORD *)&matrix.m[0][2] = __PAIR64__(LODWORD(vec3_origin.x), LODWORD(zaxis.x));
        *(_QWORD *)&matrix.m[1][2] = __PAIR64__(LODWORD(vec3_origin.y), LODWORD(zaxis.y));
        *(_QWORD *)&matrix.m[2][2] = __PAIR64__(LODWORD(vec3_origin.z), LODWORD(zaxis.z));
        v9 = (float)((float)rand() * 360.0) * 0.000030518509;
        vAxis.x = 0.0;
        vAxis.y = 0.0;
        vAxis.z = 1.0;
        SetupMatrixAxisRot(result: &rot, &vAxis, fDegrees: v9);
        v10 = VMatrix::operator*(this: &matrix, &result, vm: &rot);
        VMatrix::operator=(this: &matrix, mOther: v10);
        MatrixAngles(src: &matrix, vAngles: &angles);
      }
      *(float *)&v11 = 0.0;
      *(float *)&i = 0.0;
      if ( g_BlockerList.m_Size <= 0 )
      {
LABEL_16:
        if ( v3->m_Type != 0 )
        {
          v14 = 1.0;
          if ( v3->m_flRandomScaleStdDev != 0.0 )
          {
            flScale = fabs(_RandomGaussianFloat(a1: 1065353216, a2: LODWORD(v3->m_flRandomScaleStdDev)));
            v14 = flScale;
          }
          AddDetailSpriteToLump(
            pTex: v3->m_Tex,
            vecOrigin: pt,
            vecAngles: &angles,
            nOrientation: v3->m_Orientation,
            pPos: v3->m_Pos,
            flScale: v14,
            iType: v3->m_Type,
            iShapeAngle: v3->m_ShapeAngle,
            iShapeSize: v3->m_ShapeSize,
            iSwayAmount: v3->m_SwayAmount);
        }
        else
        {
          fDegrees = v3->m_Orientation;
          v15 = (char *)CUtlSymbol::String(this: &v3->m_ModelName);
          AddDetailToLump(pModelName: v15, pt, &angles, nOrientation: fDegrees);
        }
      }
      else
      {
        while ( 1 )
        {
          v12 = g_BlockerList.m_Memory.m_pMemory[v11];
          v13 = 0;
          if ( v12->numbrushes > 0 )
            break;
LABEL_14:
          i = ++v11;
          if ( v11 >= g_BlockerList.m_Size )
          {
            v3 = model;
            goto LABEL_16;
          }
        }
        while ( !IsPointInBox(
                   pt,
                   boxMin: &g_MainMap->mapbrushes[v13 + v12->firstbrush].mins,
                   boxMax: &g_MainMap->mapbrushes[v13 + v12->firstbrush].maxs) )
        {
          if ( ++v13 >= v12->numbrushes )
          {
            v11 = i;
            goto LABEL_14;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409640
// Name: EmitDetailObjectsOnFace
// Source: json
//------------------------------------------------------------------------------
void __usercall EmitDetailObjectsOnFace(float a1@<ebp>, dface_t *pFace, DetailObject_t *detail)
{
  __int16 numedges; // si
  int firstedge; // ecx
  int v5; // edi
  float x; // ecx
  float y; // edi
  int v8; // eax
  BOOL v9; // ecx
  dedge_t *v10; // eax
  DetailObject_t *v11; // esi
  int v12; // edx
  int v13; // ecx
  float v14; // xmm3_4
  float v15; // xmm4_4
  int v16; // eax
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  int v20; // eax
  float v21; // xmm2_4
  int v22; // eax
  DetailObjectGroup_t *m_pMemory; // esi
  int v24; // edi
  int v25; // eax
  int m_Size; // ecx
  float v27; // xmm0_4
  int v28; // eax
  float *p_m_Amount; // esi
  float v30; // xmm2_4
  float v31; // xmm4_4
  DetailObjectGroup_t *v32; // ecx
  int v33; // edx
  DetailModel_t *v34; // eax
  int v35; // ecx
  float v36; // [esp-28h] [ebp-7Ch]
  Vector v37; // [esp-Ch] [ebp-60h] BYREF
  Vector normal; // [esp+0h] [ebp-54h] BYREF
  Vector pt; // [esp+Ch] [ebp-48h]
  Vector areaVec; // [esp+18h] [ebp-3Ch]
  Vector e2; // [esp+24h] [ebp-30h]
  Vector e1; // [esp+30h] [ebp-24h]
  int *pSurfEdges; // [esp+3Ch] [ebp-18h]
  dvertex_t *pFirstVertex; // [esp+40h] [ebp-14h]
  float v45; // [esp+44h] [ebp-10h]
  float v; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int retaddr; // [esp+54h] [ebp+0h]

  v = a1;
  i = retaddr;
  numedges = pFace->numedges;
  if ( numedges >= 3 )
  {
    firstedge = pFace->firstedge;
    v5 = dsurfedges[firstedge];
    LODWORD(x) = &dsurfedges[firstedge];
    e1.x = x;
    pFirstVertex = (dvertex_t *)1;
    LODWORD(y) = &dvertexes + dedges[abs32(v5)].v[v5 < 0];
    e1.y = y;
    if ( numedges - 1 > 1 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(LODWORD(x) + 4 * (_DWORD)pFirstVertex);
        v9 = v8 < 0;
        v10 = &dedges[abs32(v8)];
        v11 = detail;
        v12 = 2 * v9;
        v13 = 3 * v10->v[v9];
        v14 = *(&dvertexes.x + v13) - *(float *)LODWORD(y);
        v15 = *(&dvertexes.y + v13) - *(float *)(LODWORD(y) + 4);
        v16 = 3 * v10->v[v12 / 0xFFFFFFFE + 1];
        v17 = *(&dvertexes.x + v16) - *(float *)LODWORD(y);
        v18 = *(&dvertexes.y + v16) - *(float *)(LODWORD(y) + 4);
        v19 = *(&dvertexes.z + v16) - *(float *)(LODWORD(y) + 8);
        e2.z = *(&dvertexes.z + v13) - *(float *)(LODWORD(y) + 8);
        areaVec.y = v18;
        pt.x = (float)(v19 * v15) - (float)(e2.z * v18);
        areaVec.x = v17;
        areaVec.z = v19;
        pt.y = (float)(e2.z * v17) - (float)(v19 * v14);
        pt.z = (float)(v18 * v14) - (float)(v17 * v15);
        v36 = fsqrt((float)((float)(pt.y * pt.y) + (float)(pt.z * pt.z)) + (float)(pt.x * pt.x));
        v20 = (int)((float)((float)(v36 * 0.5) * detail->m_Density) * 0.000001);
        e2.x = v14;
        e2.y = v15;
        if ( v20 > 0 )
        {
          LODWORD(e1.z) = v20;
          while ( 1 )
          {
            v45 = (float)rand() * 0.000030518509;
            v21 = (float)rand() * 0.000030518509;
            *(float *)&pSurfEdges = v21;
            if ( v21 > (float)(1.0 - v45) )
            {
              v45 = 1.0 - v45;
              *(float *)&pSurfEdges = 1.0 - v21;
            }
            v22 = SelectGroup(a1: (int)v11, a2: 1.0);
            m_pMemory = v11->m_Groups.m_Memory.m_pMemory;
            v24 = v22;
            v25 = rand();
            m_Size = m_pMemory[v24].m_Models.m_Size;
            v27 = (float)v25 * 0.000030518509;
            v28 = 0;
            if ( m_Size > 0 )
            {
              p_m_Amount = &m_pMemory[v24].m_Models.m_Memory.m_pMemory->m_Amount;
              while ( *p_m_Amount < v27 )
              {
                ++v28;
                p_m_Amount += 17;
                if ( v28 >= m_Size )
                  goto LABEL_17;
              }
              if ( v28 >= 0 )
              {
                v30 = (float)(e2.z * v45) + *(float *)(LODWORD(e1.y) + 8);
                v31 = (float)(areaVec.x * *(float *)&pSurfEdges)
                    + (float)((float)(e2.x * v45) + *(float *)LODWORD(e1.y));
                normal.y = (float)(areaVec.y * *(float *)&pSurfEdges)
                         + (float)((float)(e2.y * v45) + *(float *)(LODWORD(e1.y) + 4));
                v32 = detail->m_Groups.m_Memory.m_pMemory;
                normal.z = (float)(areaVec.z * *(float *)&pSurfEdges) + v30;
                v37.x = (float)(-1.0 / v36) * pt.x;
                v33 = v28;
                normal.x = v31;
                v34 = v32[v24].m_Models.m_Memory.m_pMemory;
                v37.y = pt.y * (float)(-1.0 / v36);
                v37.z = pt.z * (float)(-1.0 / v36);
                PlaceDetail(normal: &v37, model: &v34[v33], pt: &normal);
              }
            }
LABEL_17:
            if ( --LODWORD(e1.z) == 0 )
              break;
            v11 = detail;
          }
          y = e1.y;
        }
        v35 = pFace->numedges - 1;
        pFirstVertex = (dvertex_t *)((char *)pFirstVertex + 1);
        if ( (int)pFirstVertex >= v35 )
          break;
        x = e1.x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004099B0
// Name: EmitDetailObjectsOnDisplacementFace
// Source: json
//------------------------------------------------------------------------------
void __usercall EmitDetailObjectsOnDisplacementFace(
        dface_t *pFace@<eax>,
        float a2@<xmm0>,
        float detail,
        CCoreDispInfo *coreDispInfo)
{
  DetailObject_t *v4; // ebx
  double v5; // xmm0_8
  int v6; // eax
  int v7; // eax
  DetailObjectGroup_t *m_pMemory; // esi
  int v9; // edi
  int v10; // eax
  int m_Size; // ecx
  float v12; // xmm0_4
  int v13; // eax
  float *p_m_Amount; // esi
  Vector normal; // [esp+20h] [ebp-20h] BYREF
  Vector pt; // [esp+2Ch] [ebp-14h] BYREF
  float u; // [esp+38h] [ebp-8h]
  int v18; // [esp+3Ch] [ebp-4h]

  ComputeDisplacementFaceArea(pFace);
  v4 = (DetailObject_t *)LODWORD(detail);
  v5 = (float)(a2 * *(float *)(LODWORD(detail) + 4)) * 0.000001;
  if ( (int)v5 > 0 )
  {
    v18 = (int)v5;
    do
    {
      u = (float)rand() * 0.000030518509;
      v6 = rand();
      CCoreDispInfo::GetPositionOnSurface(
        this: coreDispInfo,
        u,
        v: (float)v6 * 0.000030518509,
        vPos: &pt,
        pNormal: &normal,
        pAlpha: &detail);
      detail = detail * 0.0039215689;
      v7 = SelectGroup(a1: (int)v4, a2: detail);
      m_pMemory = v4->m_Groups.m_Memory.m_pMemory;
      v9 = v7;
      v10 = rand();
      m_Size = m_pMemory[v9].m_Models.m_Size;
      v12 = (float)v10 * 0.000030518509;
      v13 = 0;
      if ( m_Size > 0 )
      {
        p_m_Amount = &m_pMemory[v9].m_Models.m_Memory.m_pMemory->m_Amount;
        while ( *p_m_Amount < v12 )
        {
          ++v13;
          p_m_Amount += 17;
          if ( v13 >= m_Size )
            goto LABEL_10;
        }
        if ( v13 >= 0 )
          PlaceDetail(&normal, model: &v4->m_Groups.m_Memory.m_pMemory[v9].m_Models.m_Memory.m_pMemory[v13], &pt);
      }
LABEL_10:
      --v18;
    }
    while ( v18 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409AD0
// Name: ParseDetailGroup
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseDetailGroup(int detailId@<eax>, KeyValues *pGroupKeyValues)
{
  int v3; // esi
  int v4; // eax
  DetailObjectGroup_t *v5; // ecx
  DetailObjectGroup_t *v6; // ecx
  DetailObjectGroup_t *v7; // esi
  KeyValues *FirstSubKey; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DetailModel_t *m_pMemory; // ecx
  int v12; // eax
  DetailModel_t *v13; // ecx
  DetailModel_t *v14; // esi
  const char *String; // eax
  unsigned __int16 m_Id; // ax
  const char *v17; // eax
  const char *v18; // ebx
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  const char *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  double Float; // st7
  float v28; // xmm0_4
  double v29; // st7
  float v30; // xmm0_4
  double v31; // st7
  double v32; // st7
  int Int; // eax
  float m_MaxCosAngle; // xmm0_4
  bool v35; // cc
  int v36; // ecx
  int v37; // edx
  const char *pSpriteData; // [esp+10h] [ebp-24h]
  float pSpriteDataa; // [esp+10h] [ebp-24h]
  float pSpriteDatab; // [esp+10h] [ebp-24h]
  float pSpriteDatac; // [esp+10h] [ebp-24h]
  DetailObjectGroup_t *group; // [esp+14h] [ebp-20h]
  float alpha; // [esp+18h] [ebp-1Ch]
  float alphaa; // [esp+18h] [ebp-1Ch]
  float flTextureSize; // [esp+1Ch] [ebp-18h] BYREF
  float y; // [esp+20h] [ebp-14h] BYREF
  float flHeight; // [esp+24h] [ebp-10h] BYREF
  float x; // [esp+28h] [ebp-Ch] BYREF
  float flWidth; // [esp+2Ch] [ebp-8h] BYREF
  CUtlSymbol v50; // [esp+32h] [ebp-2h] BYREF

  alpha = KeyValues::GetFloat(this: pGroupKeyValues, keyName: "alpha", defaultValue: 1.0);
  v3 = detailId;
  v4 = s_DetailObjectDict.m_Memory.m_pMemory[detailId].m_Groups.m_Size - 1;
  if ( v4 >= 0 )
  {
    if ( s_DetailObjectDict.m_Memory.m_pMemory[detailId].m_Groups.m_Size < 4 )
    {
LABEL_9:
      if ( v4 >= 0 )
      {
        v6 = &s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[v4];
        do
        {
          if ( alpha > v6->m_Alpha )
            break;
          --v6;
          --v4;
        }
        while ( v4 >= 0 );
      }
    }
    else
    {
      v5 = &s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[v4 - 2];
      while ( alpha <= v5[2].m_Alpha )
      {
        if ( alpha > v5[1].m_Alpha )
        {
          --v4;
          break;
        }
        if ( alpha > v5->m_Alpha )
        {
          v4 -= 2;
          break;
        }
        if ( alpha > v5[-1].m_Alpha )
        {
          v4 -= 3;
          break;
        }
        v4 -= 4;
        v5 -= 4;
        if ( v4 < 3 )
          goto LABEL_9;
      }
    }
  }
  v7 = &s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int>>::InsertBefore(
                                                                                this: &s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups,
                                                                                elem: v4 + 1)];
  group = v7;
  v7->m_Alpha = alpha;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pGroupKeyValues);
  alphaa = 0.0;
  if ( FirstSubKey != nullptr )
  {
    do
    {
      if ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
      {
        m_Size = v7->m_Models.m_Size;
        m_nAllocationCount = v7->m_Models.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<DetailModel_t,int>::Grow(this: &v7->m_Models.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++v7->m_Models.m_Size;
        m_pMemory = v7->m_Models.m_Memory.m_pMemory;
        v12 = v7->m_Models.m_Size - m_Size - 1;
        v7->m_Models.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 68 * v12);
        v13 = &v7->m_Models.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          v13->m_ModelName.m_Id = -1;
        v14 = &v7->m_Models.m_Memory.m_pMemory[m_Size];
        String = KeyValues::GetString(this: FirstSubKey, keyName: "model", defaultValue: nullptr);
        CUtlSymbol::CUtlSymbol(this: &v50, pStr: String);
        m_Id = v50.m_Id;
        v14->m_ModelName = v50;
        if ( m_Id == 0xFFFF )
        {
          pSpriteData = KeyValues::GetString(this: FirstSubKey, keyName: "sprite", defaultValue: nullptr);
          if ( pSpriteData != nullptr )
          {
            v17 = KeyValues::GetString(this: FirstSubKey, keyName: "sprite_shape", defaultValue: nullptr);
            v18 = v17;
            if ( v17 != nullptr )
            {
              if ( _V_stricmp(s1: v17, s2: "cross") != 0 )
                v14->m_Type = _V_stricmp(s1: v18, s2: "tri") != 0 ? 1 : 3;
              else
                v14->m_Type = 2;
            }
            else
            {
              v14->m_Type = 1;
            }
            v14->m_Tex[0].x = 0.0;
            v14->m_Tex[0].y = 0.0;
            v14->m_Tex[1].x = 0.0;
            v14->m_Tex[1].y = 0.0;
            x = 0.0;
            y = 0.0;
            flWidth = 64.0;
            flHeight = 64.0;
            flTextureSize = 512.0;
            if ( sscanf(string: pSpriteData, format: "%f %f %f %f %f", &x, &y, &flWidth, &flHeight, &flTextureSize) != 5
              || flTextureSize == 0.0 )
            {
              _Error(
                a1: "Invalid arguments to \"sprite\" in detail.vbsp (model %s)!\n",
                (const char *)v14->m_ModelName.m_Id);
            }
            v19 = 1.0 / flTextureSize;
            v20 = flHeight + y;
            v21 = x;
            v14->m_Tex[0].y = (float)(y + 0.5) * (float)(1.0 / flTextureSize);
            v22 = flWidth + x;
            v14->m_Tex[0].x = (float)(v21 + 0.5) * v19;
            v14->m_Tex[1].x = (float)(v22 - 0.5) * v19;
            v14->m_Tex[1].y = (float)(v20 - 0.5) * v19;
            v14->m_Pos[0].x = -10.0;
            v14->m_Pos[0].y = 20.0;
            v14->m_Pos[1].x = 10.0;
            v14->m_Pos[1].y = 0.0;
            v23 = KeyValues::GetString(this: FirstSubKey, keyName: "spritesize", defaultValue: nullptr);
            if ( v23 != nullptr )
            {
              sscanf(string: v23, format: "%f %f %f %f", &x, &y, &flWidth, &flHeight);
              v24 = flHeight * y;
              v25 = flHeight - (float)(flHeight * y);
              v26 = flWidth - (float)(flWidth * x);
              v14->m_Pos[0].x = -(float)(flWidth * x);
              v14->m_Pos[0].y = v25;
              v14->m_Pos[1].x = v26;
              v14->m_Pos[1].y = -v24;
            }
            v14->m_flRandomScaleStdDev = KeyValues::GetFloat(
                                           this: FirstSubKey,
                                           keyName: "spriterandomscale",
                                           defaultValue: 0.0);
            Float = KeyValues::GetFloat(this: FirstSubKey, keyName: "sway", defaultValue: 0.0);
            if ( Float >= 0.0 )
            {
              v28 = Float;
              pSpriteDataa = Float;
              if ( pSpriteDataa > 1.0 )
                v28 = 1.0;
            }
            else
            {
              v28 = 0.0;
            }
            v14->m_SwayAmount = (int)(v28 * 255.0);
            v14->m_ShapeAngle = KeyValues::GetInt(this: FirstSubKey, keyName: "shape_angle", defaultValue: 0);
            v29 = KeyValues::GetFloat(this: FirstSubKey, keyName: "shape_size", defaultValue: 0.0);
            if ( v29 >= 0.0 )
            {
              v30 = v29;
              pSpriteDatab = v29;
              if ( pSpriteDatab > 1.0 )
                v30 = 1.0;
            }
            else
            {
              v30 = 0.0;
            }
            v14->m_ShapeSize = (int)(v30 * 255.0);
          }
        }
        else
        {
          v14->m_Type = 0;
        }
        v31 = KeyValues::GetFloat(this: FirstSubKey, keyName: "amount", defaultValue: 1.0) + alphaa;
        v14->m_Amount = v31;
        alphaa = v31;
        v14->m_Flags = 0;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "upright", defaultValue: 0) != 0 )
          v14->m_Flags |= 1u;
        pSpriteDatac = KeyValues::GetFloat(this: FirstSubKey, keyName: "minAngle", defaultValue: 180.0);
        v32 = KeyValues::GetFloat(this: FirstSubKey, keyName: "maxAngle", defaultValue: 180.0);
        v14->m_MinCosAngle = cos(pSpriteDatac * 3.141592653589793 * 0.005555555555555556);
        v14->m_MaxCosAngle = cos(v32 * 3.141592653589793 * 0.005555555555555556);
        Int = KeyValues::GetInt(this: FirstSubKey, keyName: "detailOrientation", defaultValue: 0);
        m_MaxCosAngle = v14->m_MaxCosAngle;
        v35 = m_MaxCosAngle <= v14->m_MinCosAngle;
        v14->m_Orientation = Int;
        if ( !v35 )
          v14->m_MinCosAngle = m_MaxCosAngle;
        v7 = group;
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    if ( alphaa > 1.0 )
    {
      v36 = 0;
      if ( v7->m_Models.m_Size > 0 )
      {
        v37 = 0;
        do
        {
          ++v36;
          v7->m_Models.m_Memory.m_pMemory[v37].m_Amount = (float)(1.0 / alphaa)
                                                        * v7->m_Models.m_Memory.m_pMemory[v37].m_Amount;
          ++v37;
        }
        while ( v36 < v7->m_Models.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A050
// Name: void EmitDetailModels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitDetailModels()
{
  int v0; // ebx
  entity_t *v1; // edi
  int m_Size; // eax
  int v3; // esi
  entity_t **m_pMemory; // ecx
  int v5; // eax
  entity_t **v6; // eax
  int v7; // eax
  int v8; // ecx
  __int16 *p_dispinfo; // ebx
  float flPercent; // xmm0_4
  dtexdata_t *TexData; // esi
  const char *String; // eax
  void *OriginalMaterial; // eax
  const char *MaterialVar; // edi
  int v15; // eax
  DetailObject_t *v16; // ecx
  const char *v17; // eax
  DetailObject_t *v18; // edi
  unsigned int hammerfaceid; // esi
  mapdispinfo_t *v20; // esi
  int v21; // ebx
  entity_t *v22; // esi
  const char *v23; // edi
  unsigned __int8 v24; // di
  float v25; // xmm0_4
  float v26; // xmm1_4
  char *v27; // edi
  unsigned __int8 v28; // al
  CCoreDispInfo coreDispInfo; // [esp+28h] [ebp-3ACh] BYREF
  Vector2D pos[2]; // [esp+374h] [ebp-60h] BYREF
  Vector origin; // [esp+384h] [ebp-50h] BYREF
  QAngle angles; // [esp+390h] [ebp-44h] BYREF
  DetailObject_t search; // [esp+39Ch] [ebp-38h] BYREF
  Vector2D tex[2]; // [esp+3B8h] [ebp-1Ch] BYREF
  __int16 *v35; // [esp+3C8h] [ebp-Ch]
  float flTextureSize; // [esp+3CCh] [ebp-8h]
  CUtlSymbol v37; // [esp+3D0h] [ebp-4h] BYREF
  bool found; // [esp+3D3h] [ebp-1h] BYREF
  int savedregs; // [esp+3D4h] [ebp+0h] BYREF

  StartPacifier(pPrefix: "Placing detail props : ");
  v0 = 0;
  g_BlockerList.m_Size = 0;
  if ( num_entities > 0 )
  {
    v1 = (entity_t *)&entities;
    do
    {
      if ( strcmp(ValueForKey(ent: v1, key: "classname"), "func_detail_blocker") == 0 )
      {
        m_Size = g_BlockerList.m_Size;
        v3 = g_BlockerList.m_Size;
        if ( g_BlockerList.m_Size + 1 > g_BlockerList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CClassInput *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&g_BlockerList,
            num: g_BlockerList.m_Size - g_BlockerList.m_Memory.m_nAllocationCount + 1);
          m_Size = g_BlockerList.m_Size;
        }
        m_pMemory = g_BlockerList.m_Memory.m_pMemory;
        g_BlockerList.m_Size = m_Size + 1;
        v5 = m_Size - v3;
        g_BlockerList.m_pElements = g_BlockerList.m_Memory.m_pMemory;
        if ( v5 > 0 )
        {
          _V_memmove(
            dest: &g_BlockerList.m_Memory.m_pMemory[v3 + 1],
            src: &g_BlockerList.m_Memory.m_pMemory[v3],
            count: 4 * v5);
          m_pMemory = g_BlockerList.m_Memory.m_pMemory;
        }
        v6 = &m_pMemory[v3];
        if ( v6 != nullptr )
          *v6 = v1;
      }
      ++v0;
      ++v1;
    }
    while ( v0 < num_entities );
  }
  v7 = numfaces;
  v8 = 0;
  flTextureSize = 0.0;
  if ( numfaces > 0 )
  {
    p_dispinfo = &dfaces[0].dispinfo;
    v35 = &dfaces[0].dispinfo;
    do
    {
      flPercent = (float)v8 / (float)v7;
      UpdatePacifier(flPercent);
      TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[*(p_dispinfo - 1)].texdata);
      String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
      OriginalMaterial = FindOriginalMaterial(materialName: String, pFound: &found, bComplain: false);
      if ( found )
      {
        MaterialVar = GetMaterialVar(materialHandle: OriginalMaterial, propertyName: "%detailtype");
        if ( MaterialVar != nullptr )
        {
          memset(&search.m_Groups, 0, sizeof(search.m_Groups));
          CUtlSymbol::CUtlSymbol(this: &v37, pStr: MaterialVar);
          search.m_Name = v37;
          v15 = 0;
          if ( s_DetailObjectDict.m_Size <= 0 )
          {
LABEL_22:
            v17 = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
            _Warning(a1: "Material %s uses unknown detail object type %s!\n", v17, MaterialVar);
          }
          else
          {
            v16 = s_DetailObjectDict.m_Memory.m_pMemory;
            while ( v37.m_Id != v16->m_Name.m_Id )
            {
              ++v15;
              ++v16;
              if ( v15 >= s_DetailObjectDict.m_Size )
                goto LABEL_21;
            }
            if ( v15 < 0 )
            {
LABEL_21:
              p_dispinfo = v35;
              goto LABEL_22;
            }
            v18 = &s_DetailObjectDict.m_Memory.m_pMemory[v15];
            hammerfaceid = dfaceids.m_Memory.m_pMemory[LODWORD(flTextureSize)].hammerfaceid;
            srand(seed: hammerfaceid);
            _RandomSeed(a1: hammerfaceid);
            p_dispinfo = v35;
            if ( *v35 >= 0 )
            {
              v20 = (mapdispinfo_t *)((char *)&mapdispinfo + 33668 * *v35);
              CCoreDispInfo::CCoreDispInfo(this: &coreDispInfo);
              DispMapToCoreDispInfo(
                pMapDisp: v20,
                pCoreDispInfo: &coreDispInfo,
                pFace: nullptr,
                pSwappedTexInfos: nullptr);
              EmitDetailObjectsOnDisplacementFace(
                pFace: (dface_t *)(p_dispinfo - 6),
                a2: flPercent,
                detail: *(float *)&v18,
                &coreDispInfo);
              CCoreDispInfo::~CCoreDispInfo(this: &coreDispInfo);
            }
            else
            {
              EmitDetailObjectsOnFace(a1: COERCE_FLOAT(&savedregs), pFace: (dface_t *)(v35 - 6), detail: v18);
            }
          }
          CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &search.m_Groups);
          if ( search.m_Groups.m_Memory.m_nGrowSize >= 0 && search.m_Groups.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Groups.m_Memory.m_pMemory);
        }
      }
      v7 = numfaces;
      v8 = LODWORD(flTextureSize) + 1;
      p_dispinfo += 28;
      flTextureSize = *(float *)&v8;
      v35 = p_dispinfo;
    }
    while ( v8 < numfaces );
  }
  v21 = 0;
  if ( num_entities > 0 )
  {
    v22 = (entity_t *)&entities;
    while ( 1 )
    {
      v23 = ValueForKey(ent: v22, key: "classname");
      if ( strcmp(v23, "detail_prop") == 0 || strcmp(v23, "prop_detail") == 0 )
        break;
      if ( strcmp(v23, "prop_detail_sprite") == 0 )
      {
        GetVectorForKey(ent: v22, key: "origin", angle: (QAngle *)&origin);
        GetVectorForKey(ent: v22, key: "angles", angle: &angles);
        v24 = IntForKey(ent: v22, key: "detailOrientation");
        GetVector2DForKey(ent: v22, key: "position_ul", vec: pos);
        GetVector2DForKey(ent: v22, key: "position_lr", vec: &pos[1]);
        GetVector2DForKey(ent: v22, key: "tex_ul", vec: tex);
        GetVector2DForKey(ent: v22, key: "tex_size", vec: &tex[1]);
        flTextureSize = FloatForKey(ent: v22, key: "tex_total_size");
        v25 = (float)(tex[0].x - 0.5) + tex[1].x;
        v26 = (float)(tex[0].y - 0.5) + tex[1].y;
        tex[0].y = (float)(1.0 / flTextureSize) * (float)(tex[0].y + 0.5);
        tex[0].x = (float)(1.0 / flTextureSize) * (float)(tex[0].x + 0.5);
        tex[1].x = (float)(1.0 / flTextureSize) * v25;
        tex[1].y = (float)(1.0 / flTextureSize) * v26;
        AddDetailSpriteToLump(
          pTex: tex,
          vecOrigin: &origin,
          vecAngles: &angles,
          nOrientation: v24,
          pPos: pos,
          flScale: 1.0,
          iType: 1u,
          iShapeAngle: 0,
          iShapeSize: 0,
          iSwayAmount: 0);
LABEL_37:
        v22->epairs = nullptr;
      }
      ++v21;
      ++v22;
      if ( v21 >= num_entities )
        goto LABEL_39;
    }
    GetVectorForKey(ent: v22, key: "origin", angle: (QAngle *)&origin);
    GetVectorForKey(ent: v22, key: "angles", angle: &angles);
    v27 = ValueForKey(ent: v22, key: "model");
    v28 = IntForKey(ent: v22, key: "detailOrientation");
    AddDetailToLump(pModelName: v27, pt: &origin, &angles, nOrientation: v28);
    goto LABEL_37;
  }
LABEL_39:
  EndPacifier(bCarriageReturn: true);
}

//------------------------------------------------------------------------------
// Address: 0x0040A570
// Name: void EmitDetailObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitDetailObjects()
{
  EmitDetailModels();
  SetLumpData();
  if ( s_nDetailOverflow != 0 )
    _Warning(a1: "Error! Too many detail props on this map. %d were not emitted!\n", s_nDetailOverflow);
}

//------------------------------------------------------------------------------
// Address: 0x0040A6D0
// Name: ParseDetailObjectFile
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParseDetailObjectFile(KeyValues *keyValues)
{
  KeyValues *i; // edi
  int v2; // ebx
  const char *Name; // eax
  DetailObject_t *v4; // esi
  KeyValues *j; // esi
  CUtlSymbol v6; // [esp+12h] [ebp-2h] BYREF

  for ( i = KeyValues::GetFirstSubKey(this: keyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetFirstSubKey(this: i) != nullptr )
    {
      v2 = CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::InsertBefore(
             this: &s_DetailObjectDict,
             elem: s_DetailObjectDict.m_Size);
      Name = KeyValues::GetName(this: i);
      CUtlSymbol::CUtlSymbol(this: &v6, pStr: Name);
      s_DetailObjectDict.m_Memory.m_pMemory[v2].m_Name = v6;
      v4 = &s_DetailObjectDict.m_Memory.m_pMemory[v2];
      v4->m_Density = KeyValues::GetFloat(this: i, keyName: "density", defaultValue: 0.0);
      for ( j = KeyValues::GetFirstSubKey(this: i); j != nullptr; j = KeyValues::GetNextKey(this: j) )
      {
        if ( KeyValues::GetFirstSubKey(this: j) != nullptr )
          ParseDetailGroup(detailId: v2, pGroupKeyValues: j);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A7A0
// Name: void LoadEmitDetailObjectDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEmitDetailObjectDictionary()
{
  char *DetailVBSPName; // edi
  KeyValues *v1; // eax
  KeyValues *v2; // esi

  DetailVBSPName = FindDetailVBSPName();
  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: DetailVBSPName);
  else
    v2 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v2,
         filesystem: g_pFileSystem,
         resourceName: DetailVBSPName,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    ParseDetailObjectFile(keyValues: v2);
  }
  KeyValues::deleteThis(this: v2);
}
