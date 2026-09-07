// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/v1support.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F640
// Name: ParseFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseFaceData(
        CDmeVertexData *pVertexData@<ecx>,
        int v1@<eax>,
        int material,
        int v2,
        int v3,
        int vi,
        int ni,
        int ti)
{
  int PositionIndex; // ebx
  int TexCoordIndex; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  unsigned int v16; // edi
  int v17; // eax
  int n; // [esp+48h] [ebp+8h]
  int na; // [esp+48h] [ebp+8h]
  int nb; // [esp+48h] [ebp+8h]
  s_tmpface_t f; // 0:^14.52

  f.d = -1;
  f.td = -1;
  f.nd = -1;
  f.material = material;
  PositionIndex = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v1);
  n = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v1);
  TexCoordIndex = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v1);
  if ( PositionIndex < 0 )
    f.a = 0;
  else
    f.a = vi + PositionIndex;
  if ( n < 0 )
    f.na = 0;
  else
    f.na = ni + n;
  if ( TexCoordIndex < 0 )
    f.ta = 0;
  else
    f.ta = ti + TexCoordIndex;
  v12 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v2);
  na = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v2);
  v13 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v2);
  if ( v12 < 0 )
    f.b = 0;
  else
    f.b = vi + v12;
  if ( na < 0 )
    f.nb = 0;
  else
    f.nb = ni + na;
  if ( v13 < 0 )
    f.tb = 0;
  else
    f.tb = ti + v13;
  v14 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v3);
  nb = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v3);
  v15 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v3);
  if ( v14 < 0 )
    f.c = 0;
  else
    f.c = vi + v14;
  if ( nb < 0 )
    f.nc = 0;
  else
    f.nc = ni + nb;
  if ( v15 < 0 )
    f.tc = 0;
  else
    f.tc = ti + v15;
  v16 = g_numfaces;
  v17 = g_numfaces + 1;
  g_numfaces = v17;
  if ( g_face.m_Size < v17 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v17 - g_face.m_Size);
  g_face.m_Memory.m_pMemory[v16] = f;
}

//------------------------------------------------------------------------------
// Address: 0x00467D80
// Name: int VectorCompare(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorCompare(const Vector *v1, const Vector *v2)
{
  return v2->x == v1->x && v2->y == v1->y && v2->z == v1->z;
}

//------------------------------------------------------------------------------
// Address: 0x00467DD0
// Name: int lookup_index(struct s_source_t __near *,int,class Vector __near &,class Vector __near &,class Vector2D,int,int __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lookup_index(
        s_source_t *psource,
        int material,
        Vector *vertex,
        Vector *normal,
        Vector2D texcoord,
        int iCount,
        int *bones,
        float *weights)
{
  int v8; // edx
  int m_Size; // ecx
  int v10; // edi
  int v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // ebx
  float *v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  Vector *m_pMemory; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // esi
  int v25; // edi
  int v26; // edx
  Vector *v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // esi
  int v31; // edi
  int v32; // ebx
  Vector2D *v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // esi
  int v37; // edi
  int v38; // ebx
  Vector2D *v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // esi
  int v43; // ebx
  int v44; // edi
  s_boneweight_t *v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // esi
  int v49; // ebx
  int v50; // edi
  s_boneweight_t *v51; // ecx
  int v52; // eax
  bool v53; // zf
  int v54; // eax
  int v55; // ecx
  int v57; // [esp+Ch] [ebp-20h]
  int v58; // [esp+10h] [ebp-1Ch]
  float *v59; // [esp+10h] [ebp-1Ch]
  int v60; // [esp+14h] [ebp-18h]
  int v61; // [esp+14h] [ebp-18h]
  int v62; // [esp+18h] [ebp-14h]
  int v63; // [esp+18h] [ebp-14h]
  int *p_m; // [esp+1Ch] [ebp-10h]
  int v65; // [esp+20h] [ebp-Ch]
  int v66; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v8 = 0;
  i = 0;
  if ( (int)g_numvlist > 0 )
  {
    m_Size = g_bone.m_Size;
    v10 = 0;
    v60 = 0;
    v11 = 1;
    v62 = 0;
    v66 = 0;
    v58 = 0;
    p_m = &v_listdata[0].m;
    do
    {
      if ( *p_m == material )
      {
        if ( g_normal.m_Size < v11 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v11 - g_normal.m_Size);
          m_Size = g_bone.m_Size;
          v8 = i;
        }
        if ( (float)((float)((float)(*(float *)((char *)&g_normal.m_Memory.m_pMemory->y + v10) * normal->y)
                           + (float)(normal->x * *(float *)((char *)&g_normal.m_Memory.m_pMemory->x + v10)))
                   + (float)(*(float *)((char *)&g_normal.m_Memory.m_pMemory->z + v10) * normal->z)) > normal_blend )
        {
          if ( g_vertex.m_Size < v11 )
          {
            CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
              elem: g_vertex.m_Size,
              num: v11 - g_vertex.m_Size);
            m_Size = g_bone.m_Size;
          }
          v12 = g_texcoord.m_Size;
          if ( vertex->x == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->x + v66)
            && vertex->y == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->y + v66)
            && vertex->z == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->z + v66) )
          {
            if ( g_texcoord.m_Size < v11 )
            {
              CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
                this: &g_texcoord,
                elem: g_texcoord.m_Size,
                num: v11 - g_texcoord.m_Size);
              v12 = g_texcoord.m_Size;
              m_Size = g_bone.m_Size;
            }
            if ( g_texcoord.m_Memory.m_pMemory[i].x == texcoord.x )
            {
              if ( v12 < v11 )
              {
                CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
                  this: &g_texcoord,
                  elem: v12,
                  num: v11 - v12);
                m_Size = g_bone.m_Size;
              }
              if ( g_texcoord.m_Memory.m_pMemory[i].y == texcoord.y )
              {
                if ( m_Size < v11 )
                {
                  CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                    this: &g_bone,
                    elem: m_Size,
                    num: v11 - m_Size);
                  m_Size = g_bone.m_Size;
                }
                v13 = iCount;
                if ( g_bone.m_Memory.m_pMemory[v62].numbones == iCount )
                {
                  v14 = 0;
                  if ( iCount > 0 )
                  {
                    v15 = weights;
                    v65 = v58;
                    do
                    {
                      if ( m_Size < v11 )
                      {
                        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                          this: &g_bone,
                          elem: m_Size,
                          num: v11 - m_Size);
                        m_Size = g_bone.m_Size;
                      }
                      if ( *(int *)((char *)g_bone.m_Memory.m_pMemory->bone + v65) != *(_DWORD *)((char *)v15
                                                                                                + (char *)bones
                                                                                                - (char *)weights) )
                        break;
                      if ( m_Size < v11 )
                      {
                        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                          this: &g_bone,
                          elem: m_Size,
                          num: v11 - m_Size);
                        m_Size = g_bone.m_Size;
                      }
                      if ( g_bone.m_Memory.m_pMemory->weight[v14 + v60] != *v15 )
                        break;
                      v65 += 4;
                      ++v14;
                      ++v15;
                    }
                    while ( v14 < iCount );
                    v13 = iCount;
                  }
                  if ( v14 == v13 )
                  {
                    v_listdata[i].lastref = g_numvlist;
                    return i;
                  }
                }
              }
            }
          }
          v8 = i;
          v10 = v66;
        }
      }
      p_m += 8;
      v60 += 7;
      ++v62;
      v58 += 28;
      ++v8;
      v10 += 12;
      ++v11;
      i = v8;
      v66 = v10;
    }
    while ( v8 < (int)g_numvlist );
    if ( v8 >= 0x80000 )
      MdlError(fmt: "too many indices in source: \"%s\"\n", psource->filename);
  }
  v16 = g_vertex.m_Size;
  if ( g_vertex.m_Size >= v8 + 1 )
    goto LABEL_43;
  v17 = v8 + 1 - g_vertex.m_Size;
  v18 = g_vertex.m_Size;
  if ( v17 == 0 )
    goto LABEL_43;
  v19 = v8 + 1;
  if ( v8 + 1 > g_vertex.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
      num: g_vertex.m_Size + v17 - g_vertex.m_Memory.m_nAllocationCount);
    v16 = g_vertex.m_Size;
    v8 = i;
  }
  m_pMemory = g_vertex.m_Memory.m_pMemory;
  g_vertex.m_Size = v17 + v16;
  v21 = v16 - v18;
  g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
  if ( v21 > 0 && v17 > 0 )
  {
    _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[v19], src: &g_vertex.m_Memory.m_pMemory[v18], count: 12 * v21);
    v8 = i;
LABEL_43:
    m_pMemory = g_vertex.m_Memory.m_pMemory;
  }
  v22 = v8;
  m_pMemory[v8] = *vertex;
  v23 = g_normal.m_Size;
  if ( g_normal.m_Size < v8 + 1 && (v24 = v8 + 1 - g_normal.m_Size, v25 = g_normal.m_Size, v24 != 0) )
  {
    v26 = v8 + 1;
    v57 = v24 + g_normal.m_Size;
    if ( v24 + g_normal.m_Size > g_normal.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
        num: g_normal.m_Size + v24 - g_normal.m_Memory.m_nAllocationCount);
      v23 = g_normal.m_Size;
      v26 = v57;
    }
    v27 = g_normal.m_Memory.m_pMemory;
    g_normal.m_Size = v24 + v23;
    v28 = v23 - v25;
    g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
    if ( v28 > 0 && v24 > 0 )
    {
      _V_memmove(dest: &g_normal.m_Memory.m_pMemory[v26], src: &g_normal.m_Memory.m_pMemory[v25], count: 12 * v28);
      v27 = g_normal.m_Memory.m_pMemory;
    }
    v8 = i;
  }
  else
  {
    v27 = g_normal.m_Memory.m_pMemory;
  }
  v27[v22] = *normal;
  v29 = g_texcoord.m_Size;
  if ( g_texcoord.m_Size >= v8 + 1 )
    goto LABEL_59;
  v30 = v8 + 1 - g_texcoord.m_Size;
  v31 = g_texcoord.m_Size;
  if ( v30 == 0 )
    goto LABEL_59;
  v32 = v8 + 1;
  if ( v8 + 1 > g_texcoord.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<mergelist_t,int>::Grow(
      this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
      num: g_texcoord.m_Size + v30 - g_texcoord.m_Memory.m_nAllocationCount);
    v29 = g_texcoord.m_Size;
    v8 = i;
  }
  v33 = g_texcoord.m_Memory.m_pMemory;
  g_texcoord.m_Size = v30 + v29;
  v34 = v29 - v31;
  g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
  if ( v34 > 0 && v30 > 0 )
  {
    _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v32], src: &g_texcoord.m_Memory.m_pMemory[v31], count: 8 * v34);
    v8 = i;
LABEL_59:
    v33 = g_texcoord.m_Memory.m_pMemory;
  }
  v33[v8].x = texcoord.x;
  v35 = g_texcoord.m_Size;
  if ( g_texcoord.m_Size < v8 + 1 )
  {
    v36 = v8 + 1 - g_texcoord.m_Size;
    v37 = g_texcoord.m_Size;
    if ( v36 != 0 )
    {
      v38 = v8 + 1;
      if ( v8 + 1 > g_texcoord.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<mergelist_t,int>::Grow(
          this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
          num: g_texcoord.m_Size + v36 - g_texcoord.m_Memory.m_nAllocationCount);
        v35 = g_texcoord.m_Size;
        v8 = i;
      }
      v39 = g_texcoord.m_Memory.m_pMemory;
      g_texcoord.m_Size = v36 + v35;
      v40 = v35 - v37;
      g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
      if ( v40 <= 0 || v36 <= 0 )
        goto LABEL_68;
      _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v38], src: &g_texcoord.m_Memory.m_pMemory[v37], count: 8 * v40);
      v8 = i;
    }
  }
  v39 = g_texcoord.m_Memory.m_pMemory;
LABEL_68:
  v39[v8].y = texcoord.y;
  if ( g_bone.m_Size < v8 + 1 )
  {
    CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
      this: &g_bone,
      elem: g_bone.m_Size,
      num: v8 + 1 - g_bone.m_Size);
    v8 = i;
  }
  g_bone.m_Memory.m_pMemory[v8].numbones = iCount;
  if ( iCount > 0 )
  {
    v61 = 28 * v8 + 16;
    v59 = weights;
    v63 = iCount;
    do
    {
      v41 = g_bone.m_Size;
      if ( g_bone.m_Size < v8 + 1 && (v42 = v8 + 1 - g_bone.m_Size, v43 = g_bone.m_Size, v42 != 0) )
      {
        v44 = v8 + 1;
        if ( v8 + 1 > g_bone.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
            this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
            num: g_bone.m_Size + v42 - g_bone.m_Memory.m_nAllocationCount);
          v41 = g_bone.m_Size;
        }
        v45 = g_bone.m_Memory.m_pMemory;
        g_bone.m_Size = v42 + v41;
        v46 = v41 - v43;
        g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
        if ( v46 > 0 && v42 > 0 )
        {
          _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v44], src: &g_bone.m_Memory.m_pMemory[v43], count: 28 * v46);
          v45 = g_bone.m_Memory.m_pMemory;
        }
        v8 = i;
      }
      else
      {
        v45 = g_bone.m_Memory.m_pMemory;
      }
      *(float *)((char *)v45 + v61 - 12) = *(float *)((char *)v59 + (char *)bones - (char *)weights);
      v47 = g_bone.m_Size;
      if ( g_bone.m_Size < v8 + 1 && (v48 = v8 + 1 - g_bone.m_Size, v49 = g_bone.m_Size, v48 != 0) )
      {
        v50 = v8 + 1;
        if ( v8 + 1 > g_bone.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
            this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
            num: g_bone.m_Size + v48 - g_bone.m_Memory.m_nAllocationCount);
          v47 = g_bone.m_Size;
        }
        v51 = g_bone.m_Memory.m_pMemory;
        g_bone.m_Size = v48 + v47;
        v52 = v47 - v49;
        g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
        if ( v52 > 0 && v48 > 0 )
        {
          _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v50], src: &g_bone.m_Memory.m_pMemory[v49], count: 28 * v52);
          v51 = g_bone.m_Memory.m_pMemory;
        }
        v8 = i;
      }
      else
      {
        v51 = g_bone.m_Memory.m_pMemory;
      }
      *(int *)((char *)&v51->numbones + v61) = *(int *)v59;
      v53 = v63-- == 1;
      ++v59;
      v61 += 4;
    }
    while ( !v53 );
  }
  v54 = v8;
  v_listdata[v54].m = material;
  v55 = g_numvlist;
  v_listdata[v54].v = v8;
  v_listdata[v54].n = v8;
  v_listdata[v54].t = v8;
  v_listdata[v54].lastref = v55;
  g_numvlist = v8 + 1;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004684E0
// Name: void ParseFaceData(struct s_source_t __near *,int,struct s_face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFaceData(s_source_t *psource, int material, s_face_t *pFace)
{
  int v3; // esi
  int v4; // eax
  unsigned int v5; // esi
  int i; // edi
  int j; // edi
  const char *v8; // eax
  unsigned int v9; // esi
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int bones; // [esp+Ch] [ebp-203Ch] BYREF
  char v16; // [esp+10h] [ebp-2038h] BYREF
  char v17; // [esp+14h] [ebp-2034h] BYREF
  char v18; // [esp+18h] [ebp-2030h] BYREF
  float weights; // [esp+100Ch] [ebp-103Ch] BYREF
  char v20; // [esp+1010h] [ebp-1038h] BYREF
  char v21; // [esp+1014h] [ebp-1034h] BYREF
  char v22; // [esp+1018h] [ebp-1030h] BYREF
  Vector normal; // [esp+200Ch] [ebp-3Ch] BYREF
  _DWORD v24[3]; // [esp+2018h] [ebp-30h]
  Vector org; // [esp+2024h] [ebp-24h] BYREF
  int v26; // [esp+2030h] [ebp-18h]
  int v27; // [esp+2034h] [ebp-14h]
  int v28; // [esp+2038h] [ebp-10h] BYREF
  Vector2D v29; // [esp+203Ch] [ebp-Ch] BYREF
  int iCount; // [esp+2044h] [ebp-4h] BYREF

  v3 = 0;
  v27 = 0;
  do
  {
    memset(dst: (unsigned __int8 *)g_szLine, value: 0, count: sizeof(g_szLine));
    if ( GetLineInput() == 0 )
      MdlError(fmt: "%s: error on g_szLine %d: %s", g_szFilename, g_iLinecount, g_szLine);
    iCount = 0;
    v26 = sscanf(
            string: g_szLine,
            format: "%d %f %f %f %f %f %f %f %f %d %d %f %d %f %d %f %d %f",
            &v28,
            &org,
            &org.y,
            &org.z,
            &normal,
            &normal.y,
            &normal.z,
            &v29,
            &v29.y,
            &iCount,
            &bones,
            &weights,
            &v16,
            &v20,
            &v17,
            &v21,
            &v18,
            &v22);
    if ( v26 >= 9 )
    {
      if ( v28 < 0 || v28 >= psource->numbones )
        MdlError(fmt: "bogus bone index\n%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
      scale_vertex(&org);
      v4 = iCount;
      if ( iCount > 4 )
      {
        v5 = 0;
        for ( i = 18; i != 0; --i )
        {
          for ( ; g_szLine[v5] == 32; ++v5 )
            ;
          v5 += strlen(strtok(string: &g_szLine[v5], control: " ")) + 1;
        }
        v4 = iCount;
        for ( j = 4; j < iCount; ++j )
        {
          if ( j >= 1024 )
            break;
          for ( ; g_szLine[v5] == 32; ++v5 )
            ;
          v8 = strtok(string: &g_szLine[v5], control: " ");
          v9 = v5 + strlen(v8) + 1;
          *(&bones + j) = atoi(nptr: v8);
          v10 = strtok(string: &g_szLine[v9], control: " ");
          v5 = v9 + strlen(v10) + 1;
          *(&weights + j) = atof(nptr: v10);
          v4 = iCount;
        }
      }
      v29.y = 1.0 - v29.y;
      if ( v26 == 9 || v4 == 0 )
      {
        v11 = 1;
        bones = v28;
        weights = 1.0;
      }
      else
      {
        v11 = SortAndBalanceBones(iCount: v4, iMaxCount: 3, &bones, &weights);
      }
      iCount = v11;
      v12 = lookup_index(psource, material, vertex: &org, &normal, texcoord: v29, iCount: v11, &bones, &weights);
      v3 = v27;
      v24[v27] = v12;
    }
    v27 = ++v3;
  }
  while ( v3 < 3 );
  v13 = v24[2];
  pFace->a = v24[0];
  v14 = v24[1];
  pFace->b = v13;
  pFace->c = v14;
}

//------------------------------------------------------------------------------
// Address: 0x004687B0
// Name: void Grab_Triangles(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Triangles(s_source_t *psource)
{
  signed int i; // esi
  int v2; // esi
  const char *v3; // edi
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  int v10; // eax
  int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // esi
  char texturename[260]; // [esp+0h] [ebp-114h] BYREF
  s_face_t f; // [esp+104h] [ebp-10h] BYREF

  g_numfaces = 0;
  g_numvlist = 0;
  while ( GetLineInput() != 0 )
  {
    if ( IsEnd(pLine: g_szLine) )
      break;
    if ( strlen(g_szLine) < 0x104 )
    {
      strncpy(dest: (unsigned __int8 *)texturename, source: (unsigned __int8 *)g_szLine, count: 0x103u);
      for ( i = strlen(texturename) - 1; i >= 0; --i )
      {
        if ( isgraph(c: texturename[i]) != 0 )
          break;
      }
      texturename[i + 1] = 0;
      v2 = 0;
      if ( numrep > 0 )
      {
        v3 = sourcetexture[0];
        while ( *v3 != 0 )
        {
          if ( _V_stricmp(s1: texturename, s2: v3) == 0 )
          {
            v7 = defaulttexture[v2];
            v8 = (char *)(texturename - v7);
            do
            {
              v9 = *v7;
              v7[(_DWORD)v8] = *v7;
              ++v7;
            }
            while ( v9 != 0 );
            goto LABEL_19;
          }
          ++v2;
          v3 += 260;
          if ( v2 >= numrep )
            goto LABEL_19;
        }
        v4 = defaulttexture[v2];
        v5 = (char *)(texturename - v4);
        do
        {
          v6 = *v4;
          v4[(_DWORD)v5] = *v4;
          ++v4;
        }
        while ( v6 != 0 );
      }
LABEL_19:
      if ( texturename[0] != 0
        && _V_stricmp(s1: texturename, s2: "null.bmp") != 0
        && _V_stricmp(s1: texturename, s2: "null.tga") != 0
        && _V_stricmp(s1: texturename, s2: "debug/debugempty") != 0 )
      {
        v10 = LookupTexture(pTextureName: texturename, bRelativePath: g_smdVersion > 1);
        psource->texmap[v10] = v10;
        v11 = UseTextureAsMaterial(textureindex: v10);
        memset(&f, 255, sizeof(f));
        ParseFaceData(psource, material: v11, pFace: &f);
        if ( f.a != f.b && f.b != f.c && f.a != f.c )
        {
          v12 = g_numfaces;
          if ( g_src_uface.m_Size < (int)(g_numfaces + 1) )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: g_numfaces + 1 - g_src_uface.m_Size);
          g_src_uface.m_Memory.m_pMemory[v12] = f;
          v13 = g_numfaces;
          if ( g_face.m_Size < (int)(g_numfaces + 1) )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: g_numfaces + 1 - g_face.m_Size);
          g_face.m_Memory.m_pMemory[v13].material = v11;
          ++g_numfaces;
        }
      }
      else
      {
        GetLineInput();
        GetLineInput();
        GetLineInput();
      }
    }
    else
    {
      MdlWarning(fmt: "Unexpected data at line %d, (need a texture name) ignoring...\n", g_iLinecount);
    }
  }
  BuildIndividualMeshes(pSource: psource);
}

//------------------------------------------------------------------------------
// Address: 0x00468A70
// Name: int Load_SMD(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_SMD(s_source_t *psource)
{
  int result; // eax
  int v2; // eax
  char cmd[1024]; // [esp+4h] [ebp-404h] BYREF
  int option; // [esp+404h] [ebp-4h] BYREF

  g_smdVersion = 1;
  result = OpenGlobalFile(src: psource->filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "SMD MODEL %s\n", psource->filename);
    g_iLinecount = 0;
    while ( GetLineInput() != 0 )
    {
      v2 = sscanf(string: g_szLine, format: "%s %d", cmd, &option);
      if ( v2 != -1 && v2 != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "version") != 0 )
        {
          if ( _V_stricmp(s1: cmd, s2: "nodes") != 0 )
          {
            if ( _V_stricmp(s1: cmd, s2: "skeleton") != 0 )
            {
              if ( _V_stricmp(s1: cmd, s2: "triangles") != 0 )
              {
                if ( _V_stricmp(s1: cmd, s2: "vertexanimation") != 0 )
                {
                  if ( strncmp(first: cmd, last: "//", count: 2u) == 0
                    || strncmp(first: cmd, last: ";", count: 1u) == 0
                    || strncmp(first: cmd, last: "#", count: 1u) == 0 )
                  {
                    ProcessSourceComment(psource, pCommentString: cmd);
                  }
                  else
                  {
                    MdlWarning(fmt: "unknown studio command \"%s\"\n", cmd);
                  }
                }
                else
                {
                  Grab_Vertexanimation(psource, pAnimName: "BindPose");
                }
              }
              else
              {
                Grab_Triangles(psource);
              }
            }
            else
            {
              Grab_Animation(pSource: psource, pAnimName: "BindPose");
            }
          }
          else
          {
            psource->numbones = Grab_Nodes(pnodes: psource->localBone);
          }
        }
        else
        {
          if ( option < 1 || option > 2 )
            MdlError(fmt: "bad version\n");
          g_smdVersion = option;
        }
      }
    }
    fclose(stream: g_fpInput);
    return 1;
  }
  return result;
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0040AAF0
// Name: ParseFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseFaceData(
        CDmeVertexData *pVertexData@<ecx>,
        int v1@<eax>,
        int material,
        int v2,
        int v3,
        int vi,
        int ni,
        int ti)
{
  int PositionIndex; // ebx
  int TexCoordIndex; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  unsigned int v16; // edi
  int v17; // eax
  int n; // [esp+48h] [ebp+8h]
  int na; // [esp+48h] [ebp+8h]
  int nb; // [esp+48h] [ebp+8h]
  s_tmpface_t f; // 0:^14.52

  f.d = -1;
  f.td = -1;
  f.nd = -1;
  f.material = material;
  PositionIndex = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v1);
  n = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v1);
  TexCoordIndex = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v1);
  if ( PositionIndex < 0 )
    f.a = 0;
  else
    f.a = vi + PositionIndex;
  if ( n < 0 )
    f.na = 0;
  else
    f.na = ni + n;
  if ( TexCoordIndex < 0 )
    f.ta = 0;
  else
    f.ta = ti + TexCoordIndex;
  v12 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v2);
  na = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v2);
  v13 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v2);
  if ( v12 < 0 )
    f.b = 0;
  else
    f.b = vi + v12;
  if ( na < 0 )
    f.nb = 0;
  else
    f.nb = ni + na;
  if ( v13 < 0 )
    f.tb = 0;
  else
    f.tb = ti + v13;
  v14 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: v3);
  nb = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: v3);
  v15 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: v3);
  if ( v14 < 0 )
    f.c = 0;
  else
    f.c = vi + v14;
  if ( nb < 0 )
    f.nc = 0;
  else
    f.nc = ni + nb;
  if ( v15 < 0 )
    f.tc = 0;
  else
    f.tc = ti + v15;
  v16 = g_numfaces;
  v17 = g_numfaces + 1;
  g_numfaces = v17;
  if ( g_face.m_Size < v17 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v17 - g_face.m_Size);
  g_face.m_Memory.m_pMemory[v16] = f;
}

//------------------------------------------------------------------------------
// Address: 0x00460FB0
// Name: int VectorCompare(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorCompare(const Vector *v1, const Vector *v2)
{
  return v2->x == v1->x && v2->y == v1->y && v2->z == v1->z;
}

//------------------------------------------------------------------------------
// Address: 0x00461000
// Name: int lookup_index(struct s_source_t __near *,int,class Vector __near &,class Vector __near &,class Vector2D,int,int __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lookup_index(
        s_source_t *psource,
        int material,
        Vector *vertex,
        Vector *normal,
        Vector2D texcoord,
        int iCount,
        int *bones,
        float *weights)
{
  int v8; // edx
  int m_Size; // ecx
  int v10; // edi
  int v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // ebx
  float *v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  Vector *m_pMemory; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // esi
  int v25; // edi
  int v26; // edx
  Vector *v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // esi
  int v31; // edi
  int v32; // ebx
  Vector2D *v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // esi
  int v37; // edi
  int v38; // ebx
  Vector2D *v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // esi
  int v43; // ebx
  int v44; // edi
  s_boneweight_t *v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // esi
  int v49; // ebx
  int v50; // edi
  s_boneweight_t *v51; // ecx
  int v52; // eax
  bool v53; // zf
  int v54; // eax
  int v55; // ecx
  int v57; // [esp+Ch] [ebp-20h]
  int v58; // [esp+10h] [ebp-1Ch]
  float *v59; // [esp+10h] [ebp-1Ch]
  int v60; // [esp+14h] [ebp-18h]
  int v61; // [esp+14h] [ebp-18h]
  int v62; // [esp+18h] [ebp-14h]
  int v63; // [esp+18h] [ebp-14h]
  int *p_m; // [esp+1Ch] [ebp-10h]
  int v65; // [esp+20h] [ebp-Ch]
  int v66; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v8 = 0;
  i = 0;
  if ( (int)g_numvlist > 0 )
  {
    m_Size = g_bone.m_Size;
    v10 = 0;
    v60 = 0;
    v11 = 1;
    v62 = 0;
    v66 = 0;
    v58 = 0;
    p_m = &v_listdata[0].m;
    do
    {
      if ( *p_m == material )
      {
        if ( g_normal.m_Size < v11 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v11 - g_normal.m_Size);
          m_Size = g_bone.m_Size;
          v8 = i;
        }
        if ( (float)((float)((float)(*(float *)((char *)&g_normal.m_Memory.m_pMemory->y + v10) * normal->y)
                           + (float)(normal->x * *(float *)((char *)&g_normal.m_Memory.m_pMemory->x + v10)))
                   + (float)(*(float *)((char *)&g_normal.m_Memory.m_pMemory->z + v10) * normal->z)) > normal_blend )
        {
          if ( g_vertex.m_Size < v11 )
          {
            CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
              elem: g_vertex.m_Size,
              num: v11 - g_vertex.m_Size);
            m_Size = g_bone.m_Size;
          }
          v12 = g_texcoord.m_Size;
          if ( vertex->x == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->x + v66)
            && vertex->y == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->y + v66)
            && vertex->z == *(float *)((char *)&g_vertex.m_Memory.m_pMemory->z + v66) )
          {
            if ( g_texcoord.m_Size < v11 )
            {
              CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
                this: &g_texcoord,
                elem: g_texcoord.m_Size,
                num: v11 - g_texcoord.m_Size);
              v12 = g_texcoord.m_Size;
              m_Size = g_bone.m_Size;
            }
            if ( g_texcoord.m_Memory.m_pMemory[i].x == texcoord.x )
            {
              if ( v12 < v11 )
              {
                CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
                  this: &g_texcoord,
                  elem: v12,
                  num: v11 - v12);
                m_Size = g_bone.m_Size;
              }
              if ( g_texcoord.m_Memory.m_pMemory[i].y == texcoord.y )
              {
                if ( m_Size < v11 )
                {
                  CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                    this: &g_bone,
                    elem: m_Size,
                    num: v11 - m_Size);
                  m_Size = g_bone.m_Size;
                }
                v13 = iCount;
                if ( g_bone.m_Memory.m_pMemory[v62].numbones == iCount )
                {
                  v14 = 0;
                  if ( iCount > 0 )
                  {
                    v15 = weights;
                    v65 = v58;
                    do
                    {
                      if ( m_Size < v11 )
                      {
                        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                          this: &g_bone,
                          elem: m_Size,
                          num: v11 - m_Size);
                        m_Size = g_bone.m_Size;
                      }
                      if ( *(int *)((char *)g_bone.m_Memory.m_pMemory->bone + v65) != *(_DWORD *)((char *)v15
                                                                                                + (char *)bones
                                                                                                - (char *)weights) )
                        break;
                      if ( m_Size < v11 )
                      {
                        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                          this: &g_bone,
                          elem: m_Size,
                          num: v11 - m_Size);
                        m_Size = g_bone.m_Size;
                      }
                      if ( g_bone.m_Memory.m_pMemory->weight[v14 + v60] != *v15 )
                        break;
                      v65 += 4;
                      ++v14;
                      ++v15;
                    }
                    while ( v14 < iCount );
                    v13 = iCount;
                  }
                  if ( v14 == v13 )
                  {
                    v_listdata[i].lastref = g_numvlist;
                    return i;
                  }
                }
              }
            }
          }
          v8 = i;
          v10 = v66;
        }
      }
      p_m += 8;
      v60 += 7;
      ++v62;
      v58 += 28;
      ++v8;
      v10 += 12;
      ++v11;
      i = v8;
      v66 = v10;
    }
    while ( v8 < (int)g_numvlist );
    if ( v8 >= 0x80000 )
      MdlError(fmt: "too many indices in source: \"%s\"\n", psource->filename);
  }
  v16 = g_vertex.m_Size;
  if ( g_vertex.m_Size >= v8 + 1 )
    goto LABEL_43;
  v17 = v8 + 1 - g_vertex.m_Size;
  v18 = g_vertex.m_Size;
  if ( v17 == 0 )
    goto LABEL_43;
  v19 = v8 + 1;
  if ( v8 + 1 > g_vertex.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
      num: g_vertex.m_Size + v17 - g_vertex.m_Memory.m_nAllocationCount);
    v16 = g_vertex.m_Size;
    v8 = i;
  }
  m_pMemory = g_vertex.m_Memory.m_pMemory;
  g_vertex.m_Size = v17 + v16;
  v21 = v16 - v18;
  g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
  if ( v21 > 0 && v17 > 0 )
  {
    _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[v19], src: &g_vertex.m_Memory.m_pMemory[v18], count: 12 * v21);
    v8 = i;
LABEL_43:
    m_pMemory = g_vertex.m_Memory.m_pMemory;
  }
  v22 = v8;
  m_pMemory[v8] = *vertex;
  v23 = g_normal.m_Size;
  if ( g_normal.m_Size < v8 + 1 && (v24 = v8 + 1 - g_normal.m_Size, v25 = g_normal.m_Size, v24 != 0) )
  {
    v26 = v8 + 1;
    v57 = v24 + g_normal.m_Size;
    if ( v24 + g_normal.m_Size > g_normal.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
        num: g_normal.m_Size + v24 - g_normal.m_Memory.m_nAllocationCount);
      v23 = g_normal.m_Size;
      v26 = v57;
    }
    v27 = g_normal.m_Memory.m_pMemory;
    g_normal.m_Size = v24 + v23;
    v28 = v23 - v25;
    g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
    if ( v28 > 0 && v24 > 0 )
    {
      _V_memmove(dest: &g_normal.m_Memory.m_pMemory[v26], src: &g_normal.m_Memory.m_pMemory[v25], count: 12 * v28);
      v27 = g_normal.m_Memory.m_pMemory;
    }
    v8 = i;
  }
  else
  {
    v27 = g_normal.m_Memory.m_pMemory;
  }
  v27[v22] = *normal;
  v29 = g_texcoord.m_Size;
  if ( g_texcoord.m_Size >= v8 + 1 )
    goto LABEL_59;
  v30 = v8 + 1 - g_texcoord.m_Size;
  v31 = g_texcoord.m_Size;
  if ( v30 == 0 )
    goto LABEL_59;
  v32 = v8 + 1;
  if ( v8 + 1 > g_texcoord.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<mergelist_t,int>::Grow(
      this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
      num: g_texcoord.m_Size + v30 - g_texcoord.m_Memory.m_nAllocationCount);
    v29 = g_texcoord.m_Size;
    v8 = i;
  }
  v33 = g_texcoord.m_Memory.m_pMemory;
  g_texcoord.m_Size = v30 + v29;
  v34 = v29 - v31;
  g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
  if ( v34 > 0 && v30 > 0 )
  {
    _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v32], src: &g_texcoord.m_Memory.m_pMemory[v31], count: 8 * v34);
    v8 = i;
LABEL_59:
    v33 = g_texcoord.m_Memory.m_pMemory;
  }
  v33[v8].x = texcoord.x;
  v35 = g_texcoord.m_Size;
  if ( g_texcoord.m_Size < v8 + 1 )
  {
    v36 = v8 + 1 - g_texcoord.m_Size;
    v37 = g_texcoord.m_Size;
    if ( v36 != 0 )
    {
      v38 = v8 + 1;
      if ( v8 + 1 > g_texcoord.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<mergelist_t,int>::Grow(
          this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
          num: g_texcoord.m_Size + v36 - g_texcoord.m_Memory.m_nAllocationCount);
        v35 = g_texcoord.m_Size;
        v8 = i;
      }
      v39 = g_texcoord.m_Memory.m_pMemory;
      g_texcoord.m_Size = v36 + v35;
      v40 = v35 - v37;
      g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
      if ( v40 <= 0 || v36 <= 0 )
        goto LABEL_68;
      _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v38], src: &g_texcoord.m_Memory.m_pMemory[v37], count: 8 * v40);
      v8 = i;
    }
  }
  v39 = g_texcoord.m_Memory.m_pMemory;
LABEL_68:
  v39[v8].y = texcoord.y;
  if ( g_bone.m_Size < v8 + 1 )
  {
    CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
      this: &g_bone,
      elem: g_bone.m_Size,
      num: v8 + 1 - g_bone.m_Size);
    v8 = i;
  }
  g_bone.m_Memory.m_pMemory[v8].numbones = iCount;
  if ( iCount > 0 )
  {
    v61 = 28 * v8 + 16;
    v59 = weights;
    v63 = iCount;
    do
    {
      v41 = g_bone.m_Size;
      if ( g_bone.m_Size < v8 + 1 && (v42 = v8 + 1 - g_bone.m_Size, v43 = g_bone.m_Size, v42 != 0) )
      {
        v44 = v8 + 1;
        if ( v8 + 1 > g_bone.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
            this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
            num: g_bone.m_Size + v42 - g_bone.m_Memory.m_nAllocationCount);
          v41 = g_bone.m_Size;
        }
        v45 = g_bone.m_Memory.m_pMemory;
        g_bone.m_Size = v42 + v41;
        v46 = v41 - v43;
        g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
        if ( v46 > 0 && v42 > 0 )
        {
          _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v44], src: &g_bone.m_Memory.m_pMemory[v43], count: 28 * v46);
          v45 = g_bone.m_Memory.m_pMemory;
        }
        v8 = i;
      }
      else
      {
        v45 = g_bone.m_Memory.m_pMemory;
      }
      *(float *)((char *)v45 + v61 - 12) = *(float *)((char *)v59 + (char *)bones - (char *)weights);
      v47 = g_bone.m_Size;
      if ( g_bone.m_Size < v8 + 1 && (v48 = v8 + 1 - g_bone.m_Size, v49 = g_bone.m_Size, v48 != 0) )
      {
        v50 = v8 + 1;
        if ( v8 + 1 > g_bone.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
            this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
            num: g_bone.m_Size + v48 - g_bone.m_Memory.m_nAllocationCount);
          v47 = g_bone.m_Size;
        }
        v51 = g_bone.m_Memory.m_pMemory;
        g_bone.m_Size = v48 + v47;
        v52 = v47 - v49;
        g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
        if ( v52 > 0 && v48 > 0 )
        {
          _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v50], src: &g_bone.m_Memory.m_pMemory[v49], count: 28 * v52);
          v51 = g_bone.m_Memory.m_pMemory;
        }
        v8 = i;
      }
      else
      {
        v51 = g_bone.m_Memory.m_pMemory;
      }
      *(int *)((char *)&v51->numbones + v61) = *(int *)v59;
      v53 = v63-- == 1;
      ++v59;
      v61 += 4;
    }
    while ( !v53 );
  }
  v54 = v8;
  v_listdata[v54].m = material;
  v55 = g_numvlist;
  v_listdata[v54].v = v8;
  v_listdata[v54].n = v8;
  v_listdata[v54].t = v8;
  v_listdata[v54].lastref = v55;
  g_numvlist = v8 + 1;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00461710
// Name: void ParseFaceData(struct s_source_t __near *,int,struct s_face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFaceData(s_source_t *psource, int material, s_face_t *pFace)
{
  int v3; // esi
  int v4; // eax
  unsigned int v5; // esi
  int i; // edi
  int j; // edi
  const char *v8; // eax
  unsigned int v9; // esi
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int bones; // [esp+Ch] [ebp-203Ch] BYREF
  char v16; // [esp+10h] [ebp-2038h] BYREF
  char v17; // [esp+14h] [ebp-2034h] BYREF
  char v18; // [esp+18h] [ebp-2030h] BYREF
  float weights; // [esp+100Ch] [ebp-103Ch] BYREF
  char v20; // [esp+1010h] [ebp-1038h] BYREF
  char v21; // [esp+1014h] [ebp-1034h] BYREF
  char v22; // [esp+1018h] [ebp-1030h] BYREF
  Vector normal; // [esp+200Ch] [ebp-3Ch] BYREF
  _DWORD v24[3]; // [esp+2018h] [ebp-30h]
  Vector org; // [esp+2024h] [ebp-24h] BYREF
  int v26; // [esp+2030h] [ebp-18h]
  int v27; // [esp+2034h] [ebp-14h]
  int v28; // [esp+2038h] [ebp-10h] BYREF
  Vector2D v29; // [esp+203Ch] [ebp-Ch] BYREF
  int iCount; // [esp+2044h] [ebp-4h] BYREF

  v3 = 0;
  v27 = 0;
  do
  {
    memset(dst: (unsigned __int8 *)g_szLine, value: 0, count: sizeof(g_szLine));
    if ( GetLineInput() == 0 )
      MdlError(fmt: "%s: error on g_szLine %d: %s", g_szFilename, g_iLinecount, g_szLine);
    iCount = 0;
    v26 = sscanf(
            string: g_szLine,
            format: "%d %f %f %f %f %f %f %f %f %d %d %f %d %f %d %f %d %f",
            &v28,
            &org,
            &org.y,
            &org.z,
            &normal,
            &normal.y,
            &normal.z,
            &v29,
            &v29.y,
            &iCount,
            &bones,
            &weights,
            &v16,
            &v20,
            &v17,
            &v21,
            &v18,
            &v22);
    if ( v26 >= 9 )
    {
      if ( v28 < 0 || v28 >= psource->numbones )
        MdlError(fmt: "bogus bone index\n%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
      scale_vertex(&org);
      v4 = iCount;
      if ( iCount > 4 )
      {
        v5 = 0;
        for ( i = 18; i != 0; --i )
        {
          for ( ; g_szLine[v5] == 32; ++v5 )
            ;
          v5 += strlen(strtok(string: &g_szLine[v5], control: " ")) + 1;
        }
        v4 = iCount;
        for ( j = 4; j < iCount; ++j )
        {
          if ( j >= 1024 )
            break;
          for ( ; g_szLine[v5] == 32; ++v5 )
            ;
          v8 = strtok(string: &g_szLine[v5], control: " ");
          v9 = v5 + strlen(v8) + 1;
          *(&bones + j) = atoi(nptr: v8);
          v10 = strtok(string: &g_szLine[v9], control: " ");
          v5 = v9 + strlen(v10) + 1;
          *(&weights + j) = atof(nptr: v10);
          v4 = iCount;
        }
      }
      v29.y = 1.0 - v29.y;
      if ( v26 == 9 || v4 == 0 )
      {
        v11 = 1;
        bones = v28;
        weights = 1.0;
      }
      else
      {
        v11 = SortAndBalanceBones(iCount: v4, iMaxCount: 3, &bones, &weights);
      }
      iCount = v11;
      v12 = lookup_index(psource, material, vertex: &org, &normal, texcoord: v29, iCount: v11, &bones, &weights);
      v3 = v27;
      v24[v27] = v12;
    }
    v27 = ++v3;
  }
  while ( v3 < 3 );
  v13 = v24[2];
  pFace->a = v24[0];
  v14 = v24[1];
  pFace->b = v13;
  pFace->c = v14;
}

//------------------------------------------------------------------------------
// Address: 0x004619E0
// Name: void Grab_Triangles(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Triangles(s_source_t *psource)
{
  signed int i; // esi
  int v2; // esi
  const char *v3; // edi
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  int v10; // eax
  int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // esi
  char texturename[260]; // [esp+0h] [ebp-114h] BYREF
  s_face_t f; // [esp+104h] [ebp-10h] BYREF

  g_numfaces = 0;
  g_numvlist = 0;
  while ( GetLineInput() != 0 )
  {
    if ( IsEnd(pLine: g_szLine) )
      break;
    if ( strlen(g_szLine) < 0x104 )
    {
      strncpy(dest: (unsigned __int8 *)texturename, source: (unsigned __int8 *)g_szLine, count: 0x103u);
      for ( i = strlen(texturename) - 1; i >= 0; --i )
      {
        if ( isgraph(c: texturename[i]) != 0 )
          break;
      }
      texturename[i + 1] = 0;
      v2 = 0;
      if ( numrep > 0 )
      {
        v3 = sourcetexture[0];
        while ( *v3 != 0 )
        {
          if ( _V_stricmp(s1: texturename, s2: v3) == 0 )
          {
            v7 = defaulttexture[v2];
            v8 = (char *)(texturename - v7);
            do
            {
              v9 = *v7;
              v7[(_DWORD)v8] = *v7;
              ++v7;
            }
            while ( v9 != 0 );
            goto LABEL_19;
          }
          ++v2;
          v3 += 260;
          if ( v2 >= numrep )
            goto LABEL_19;
        }
        v4 = defaulttexture[v2];
        v5 = (char *)(texturename - v4);
        do
        {
          v6 = *v4;
          v4[(_DWORD)v5] = *v4;
          ++v4;
        }
        while ( v6 != 0 );
      }
LABEL_19:
      if ( texturename[0] != 0
        && _V_stricmp(s1: texturename, s2: "null.bmp") != 0
        && _V_stricmp(s1: texturename, s2: "null.tga") != 0
        && _V_stricmp(s1: texturename, s2: "debug/debugempty") != 0 )
      {
        v10 = LookupTexture(pTextureName: texturename, bRelativePath: g_smdVersion > 1);
        psource->texmap[v10] = v10;
        v11 = UseTextureAsMaterial(textureindex: v10);
        memset(&f, 255, sizeof(f));
        ParseFaceData(psource, material: v11, pFace: &f);
        if ( f.a != f.b && f.b != f.c && f.a != f.c )
        {
          v12 = g_numfaces;
          if ( g_src_uface.m_Size < (int)(g_numfaces + 1) )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: g_numfaces + 1 - g_src_uface.m_Size);
          g_src_uface.m_Memory.m_pMemory[v12] = f;
          v13 = g_numfaces;
          if ( g_face.m_Size < (int)(g_numfaces + 1) )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: g_numfaces + 1 - g_face.m_Size);
          g_face.m_Memory.m_pMemory[v13].material = v11;
          ++g_numfaces;
        }
      }
      else
      {
        GetLineInput();
        GetLineInput();
        GetLineInput();
      }
    }
    else
    {
      MdlWarning(fmt: "Unexpected data at line %d, (need a texture name) ignoring...\n", g_iLinecount);
    }
  }
  BuildIndividualMeshes(pSource: psource);
}

//------------------------------------------------------------------------------
// Address: 0x00461CA0
// Name: int Load_SMD(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_SMD(s_source_t *psource)
{
  int result; // eax
  int v2; // eax
  char cmd[1024]; // [esp+4h] [ebp-404h] BYREF
  int option; // [esp+404h] [ebp-4h] BYREF

  g_smdVersion = 1;
  result = OpenGlobalFile(src: psource->filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "SMD MODEL %s\n", psource->filename);
    g_iLinecount = 0;
    while ( GetLineInput() != 0 )
    {
      v2 = sscanf(string: g_szLine, format: "%s %d", cmd, &option);
      if ( v2 != -1 && v2 != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "version") != 0 )
        {
          if ( _V_stricmp(s1: cmd, s2: "nodes") != 0 )
          {
            if ( _V_stricmp(s1: cmd, s2: "skeleton") != 0 )
            {
              if ( _V_stricmp(s1: cmd, s2: "triangles") != 0 )
              {
                if ( _V_stricmp(s1: cmd, s2: "vertexanimation") != 0 )
                {
                  if ( strncmp(first: cmd, last: "//", count: 2u) == 0
                    || strncmp(first: cmd, last: ";", count: 1u) == 0
                    || strncmp(first: cmd, last: "#", count: 1u) == 0 )
                  {
                    ProcessSourceComment(psource, pCommentString: cmd);
                  }
                  else
                  {
                    MdlWarning(fmt: "unknown studio command \"%s\"\n", cmd);
                  }
                }
                else
                {
                  Grab_Vertexanimation(psource, pAnimName: "BindPose");
                }
              }
              else
              {
                Grab_Triangles(psource);
              }
            }
            else
            {
              Grab_Animation(pSource: psource, pAnimName: "BindPose");
            }
          }
          else
          {
            psource->numbones = Grab_Nodes(pnodes: psource->localBone);
          }
        }
        else
        {
          if ( option < 1 || option > 2 )
            MdlError(fmt: "bad version\n");
          g_smdVersion = option;
        }
      }
    }
    fclose(stream: g_fpInput);
    return 1;
  }
  return result;
}

} // namespace studiomdl
