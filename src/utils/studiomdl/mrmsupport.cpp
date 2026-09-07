// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/mrmsupport.cpp
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00416F40
// Name: bool IsEnd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsEnd(const char *pLine)
{
  char v2; // al

  if ( strncmp(first: "end", last: pLine, count: 3u) != 0 )
    return false;
  v2 = pLine[3];
  return v2 == 0 || v2 == 10;
}

//------------------------------------------------------------------------------
// Address: 0x00416F80
// Name: int SortAndBalanceBones(int,int,int __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortAndBalanceBones(int iCount, int iMaxCount, char *bones, float *weights)
{
  signed int v4; // ecx
  char *v5; // edx
  float *v6; // ebx
  int v7; // esi
  int v8; // edi
  float *v9; // eax
  bool v10; // zf
  int v11; // esi
  int v12; // edi
  float *v13; // eax
  int *v14; // ecx
  int v15; // edx
  unsigned int v16; // ebx
  float v17; // xmm0_4
  int v18; // xmm0_4
  int v19; // xmm0_4
  int v20; // xmm0_4
  int v21; // eax
  float *v22; // eax
  int v23; // ebx
  int v24; // ecx
  float v25; // xmm0_4
  float *v26; // eax
  float *v27; // eax
  int v28; // esi
  float v29; // xmm0_4
  unsigned int v30; // edx
  float *v31; // eax
  int v33; // edx
  float v34; // xmm0_4
  unsigned int v35; // esi
  float *v36; // eax
  int v37; // [esp+4h] [ebp-10h]
  int v38; // [esp+8h] [ebp-Ch]
  int v39; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]
  int ja; // [esp+10h] [ebp-4h]
  int jc; // [esp+10h] [ebp-4h]
  int jd; // [esp+10h] [ebp-4h]
  int je; // [esp+10h] [ebp-4h]
  int jf; // [esp+10h] [ebp-4h]
  int jb; // [esp+10h] [ebp-4h]
  int t; // [esp+20h] [ebp+Ch]

  v4 = iCount;
  v5 = bones;
  v6 = weights;
  if ( iCount - 1 > 0 )
  {
    v7 = 0;
    v8 = 1;
    j = 0;
    v38 = 1;
    v37 = iCount - 1;
    do
    {
      if ( v8 < iCount )
      {
        v9 = (float *)((char *)weights + v7 + 4);
        v39 = iCount - v8;
        v7 = j;
        do
        {
          v10 = *(_DWORD *)&bones[v7] == *(_DWORD *)((char *)v9 + bones - (char *)weights);
          v7 = j;
          if ( v10 )
          {
            *(float *)((char *)weights + j) = *v9 + *(float *)((char *)weights + j);
            *v9 = 0.0;
          }
          ++v9;
          --v39;
        }
        while ( v39 != 0 );
        v8 = v38;
      }
      ++v8;
      v7 += 4;
      v10 = v37-- == 1;
      v38 = v8;
      j = v7;
    }
    while ( !v10 );
  }
  do
  {
    v11 = 0;
    v12 = 0;
    ja = v4 - 1;
    if ( v4 - 1 >= 4 )
    {
      v13 = v6 + 1;
      v14 = (int *)(v5 + 8);
      v15 = v5 - (char *)v6;
      v16 = ((unsigned int)(ja - 4) >> 2) + 1;
      v12 = 4 * v16;
      do
      {
        if ( *v13 > *(v13 - 1) )
        {
          jc = *(_DWORD *)((char *)v13 + v15);
          *(_DWORD *)((char *)v13 + v15) = *(v14 - 2);
          *(v14 - 2) = jc;
          v17 = *v13;
          *v13 = *(v13 - 1);
          *(v13 - 1) = v17;
          v11 = 1;
        }
        if ( v13[1] > *v13 )
        {
          jd = *v14;
          *v14 = *(_DWORD *)((char *)v13 + v15);
          *(_DWORD *)((char *)v13 + v15) = jd;
          v18 = *((_DWORD *)v13 + 1);
          v13[1] = *v13;
          *(_DWORD *)v13 = v18;
          v11 = 1;
        }
        if ( v13[2] > v13[1] )
        {
          je = v14[1];
          v14[1] = *v14;
          *v14 = je;
          v19 = *((_DWORD *)v13 + 2);
          v13[2] = v13[1];
          *((_DWORD *)v13 + 1) = v19;
          v11 = 1;
        }
        if ( v13[3] > v13[2] )
        {
          jf = v14[2];
          v14[2] = v14[1];
          v14[1] = jf;
          v20 = *((_DWORD *)v13 + 3);
          v13[3] = v13[2];
          *((_DWORD *)v13 + 2) = v20;
          v11 = 1;
        }
        v13 += 4;
        v14 += 4;
        --v16;
      }
      while ( v16 != 0 );
      v6 = weights;
      v5 = bones;
      v4 = iCount;
    }
    v21 = v4 - 1;
    jb = v4 - 1;
    if ( v12 < v4 - 1 )
    {
      v22 = &v6[v12 + 1];
      v23 = v5 - (char *)weights;
      do
      {
        if ( *v22 > *(v22 - 1) )
        {
          v24 = *(_DWORD *)((char *)v22 + v23);
          *(float *)((char *)v22 + v23) = *(float *)&v5[4 * v12];
          *(_DWORD *)&v5[4 * v12] = v24;
          v25 = *v22;
          *v22 = *(v22 - 1);
          *(v22 - 1) = v25;
          v11 = 1;
        }
        ++v12;
        ++v22;
      }
      while ( v12 < jb );
      v6 = weights;
      v4 = iCount;
      v21 = jb;
    }
  }
  while ( v11 != 0 );
  if ( v4 > 1 )
  {
    if ( v21 < 4 )
    {
LABEL_38:
      if ( v4 <= 1 )
        goto LABEL_47;
      v27 = &v6[v4 - 1];
      do
      {
        if ( *v27 >= 0.0001 )
          break;
        --v4;
        --v27;
      }
      while ( v4 > 1 );
    }
    else
    {
      v26 = &v6[v4 - 2];
      while ( v26[1] < 0.0001 )
      {
        if ( *v26 >= 0.0001 )
        {
          --v4;
          break;
        }
        if ( *(v26 - 1) >= 0.0001 )
        {
          v4 -= 2;
          break;
        }
        if ( *(v26 - 2) >= 0.0001 )
        {
          v4 -= 3;
          break;
        }
        v4 -= 4;
        v26 -= 4;
        if ( v4 <= 4 )
        {
          iCount = v4;
          goto LABEL_38;
        }
      }
    }
    iCount = v4;
  }
LABEL_47:
  if ( v4 > iMaxCount )
  {
    iCount = iMaxCount;
    v4 = iMaxCount;
  }
  v28 = 0;
  v29 = 0.0;
  if ( v4 >= 4 )
  {
    v30 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v31 = v6 + 2;
    v28 = 4 * v30;
    do
    {
      v29 = (float)((float)((float)(v29 + *(v31 - 2)) + *(v31 - 1)) + *v31) + v31[1];
      v31 += 4;
      --v30;
    }
    while ( v30 != 0 );
  }
  for ( ; v28 < v4; ++v28 )
    v29 = v29 + v6[v28];
  if ( v29 > 0.0 )
  {
    v33 = 0;
    v34 = 1.0 / v29;
    if ( v4 >= 4 )
    {
      v35 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v36 = v6 + 2;
      v33 = 4 * v35;
      do
      {
        *(v36 - 2) = *(v36 - 2) * v34;
        *(v36 - 1) = *(v36 - 1) * v34;
        *v36 = *v36 * v34;
        v36[1] = v36[1] * v34;
        v36 += 4;
        --v35;
      }
      while ( v35 != 0 );
    }
    for ( ; v33 < v4; ++v33 )
      v6[v33] = v34 * v6[v33];
  }
  else if ( v4 > 0 )
  {
    *(float *)&t = 1.0 / (double)v4;
    memset32(v6, t, v4);
    return iCount;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00417320
// Name: void Grab_Materiallist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Materiallist(s_source_t *psource)
{
  int v1; // eax
  char path[260]; // [esp+4h] [ebp-13Ch] BYREF
  float g; // [esp+108h] [ebp-38h] BYREF
  rgb2_t a; // [esp+10Ch] [ebp-34h] BYREF
  rgb2_t d; // [esp+11Ch] [ebp-24h] BYREF
  rgb2_t s; // [esp+12Ch] [ebp-14h] BYREF
  int j; // [esp+13Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    if ( sscanf(
           string: g_szLine,
           format: "%d  %f %f %f %f   %f %f %f %f  %f %f %f %f  %f \"%[^\"]s",
           &j,
           &a,
           &a.g,
           &a.b,
           &a.a,
           &d,
           &d.g,
           &d.b,
           &d.a,
           &s,
           &s.g,
           &s.b,
           &s.a,
           &g,
           path) == 15 )
    {
      if ( path[0] != 0 )
      {
        if ( (unsigned int)j >= 0x200 )
          MdlError(fmt: "Too many materials, max %d\n", 512);
        v1 = LookupTexture(pTextureName: path, bRelativePath: false);
        psource->texmap[j] = v1;
      }
      else
      {
        psource->texmap[j] = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417440
// Name: int AddToVlist(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddToVlist(int v, int m, int n, int t)
{
  v_unify_t *v4; // eax
  v_unify_t *v5; // esi
  v_unify_t *v6; // eax

  v4 = v_list[v];
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    while ( v4->m != m || v4->n != n || v4->t != t )
    {
      v5 = v4;
      v4 = v4->next;
      if ( v4 == nullptr )
        goto LABEL_6;
    }
    ++v4->refcount;
    return v4 - v_listdata;
  }
  else
  {
LABEL_6:
    if ( (int)g_numvlist >= 0x80000 )
      MdlError(fmt: "Too many unified vertices\n");
    v6 = &v_listdata[g_numvlist++];
    v6->lastref = -1;
    v6->refcount = 1;
    v6->v = v;
    v6->m = m;
    v6->n = n;
    v6->t = t;
    if ( v5 != nullptr )
      v5->next = v6;
    else
      v_list[v] = v6;
    return g_numvlist - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417500
// Name: vlistCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl vlistCompare(_DWORD *elem1, _DWORD *elem2)
{
  v_unify_t *v2; // eax
  int m; // edx
  v_unify_t *v4; // ecx
  int v5; // esi
  int lastref; // eax
  int v8; // ecx

  v2 = &v_listdata[*elem1];
  m = v2->m;
  v4 = &v_listdata[*elem2];
  v5 = v4->m;
  if ( m < v5 )
    return -1;
  if ( m > v5 )
    return 1;
  lastref = v2->lastref;
  v8 = v4->lastref;
  if ( lastref < v8 )
    return -1;
  return lastref > v8;
}

//------------------------------------------------------------------------------
// Address: 0x00417550
// Name: SortVerticesByMaterial
// Source: json
//------------------------------------------------------------------------------
void __usercall SortVerticesByMaterial(int *pDesiredToVList@<esi>, int *pVListToDesired@<edi>)
{
  unsigned int v2; // ecx
  signed int i; // eax
  signed int j; // eax

  v2 = g_numvlist;
  for ( i = 0; i < (int)g_numvlist; ++i )
  {
    pDesiredToVList[i] = i;
    v2 = g_numvlist;
  }
  qsort(base: pDesiredToVList, num: v2, width: 4u, comp: (int (__cdecl *)(const void *, const void *))vlistCompare);
  for ( j = 0; j < (int)g_numvlist; ++j )
    pVListToDesired[pDesiredToVList[j]] = j;
}

//------------------------------------------------------------------------------
// Address: 0x004175A0
// Name: void Grab_MRMFaceupdates(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_MRMFaceupdates()
{
  do
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
  }
  while ( strncmp(first: "end", last: g_szLine, count: 3u) != 0 || byte_2E2F7EB != 0 && byte_2E2F7EB != 10 );
}

//------------------------------------------------------------------------------
// Address: 0x004178A0
// Name: void Grab_Vertexlist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Vertexlist(s_source_t *psource)
{
  int v1; // eax
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // edi
  double v13; // st7
  int v14; // eax
  float weights[4]; // [esp+Ch] [ebp-38h] BYREF
  int bones[4]; // [esp+1Ch] [ebp-28h] BYREF
  Vector p; // [esp+2Ch] [ebp-18h] BYREF
  int bone; // [esp+38h] [ebp-Ch] BYREF
  int iCount; // [esp+3Ch] [ebp-8h] BYREF
  int j; // [esp+40h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    v1 = sscanf(
           string: g_szLine,
           format: "%d %d %f %f %f %d %d %f %d %f %d %f %d %f",
           &j,
           &bone,
           &p,
           &p.y,
           &p.z,
           &iCount,
           bones,
           weights,
           &bones[1],
           &weights[1],
           &bones[2],
           &weights[2],
           &bones[3],
           &weights[3]);
    if ( v1 == 5 )
    {
      if ( bone < 0 || bone >= psource->numbones )
      {
        MdlWarning(fmt: "bogus bone index\n");
        MdlWarning(fmt: "%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
        MdlError(fmt: "Exiting due to errors\n");
      }
      v2 = j;
      if ( g_vertex.m_Size < j + 1 )
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
          elem: g_vertex.m_Size,
          num: j + 1 - g_vertex.m_Size);
      g_vertex.m_Memory.m_pMemory[v2] = p;
      v3 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v3].numbones = 1;
      v4 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v4].bone[0] = bone;
      v5 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v5].weight[0] = 1.0;
    }
    else
    {
      if ( v1 <= 5 )
        MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
      v6 = SortAndBalanceBones(iCount, iMaxCount: 3, (char *)bones, weights);
      v7 = j;
      iCount = v6;
      if ( g_vertex.m_Size < j + 1 )
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
          elem: g_vertex.m_Size,
          num: j + 1 - g_vertex.m_Size);
      g_vertex.m_Memory.m_pMemory[v7] = p;
      v8 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      v9 = v8;
      v10 = 0;
      for ( g_bone.m_Memory.m_pMemory[v9].numbones = iCount; v10 < iCount; g_bone.m_Memory.m_pMemory->weight[v14] = v13 )
      {
        v11 = j;
        if ( g_bone.m_Size < j + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: j + 1 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v11].bone[v10] = bones[v10];
        v12 = j;
        if ( g_bone.m_Size < j + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: j + 1 - g_bone.m_Size);
        v13 = weights[v10];
        v14 = v10 + 7 * v12;
        ++v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417BD0
// Name: void Grab_Facelist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Facelist()
{
  int v0; // edi
  s_tmpface_t f; // [esp+Ch] [ebp-38h] BYREF
  int j; // [esp+40h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    memset(&f.a, 255, 48);
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %d %d %d", &j, &f.a, &f.b, &f.c) != 4 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v0 = j;
    if ( g_face.m_Size < j + 1 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
    g_face.m_Memory.m_pMemory[v0] = f;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417CE0
// Name: void Grab_Texcoordlist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Texcoordlist()
{
  int v0; // esi
  int v1; // esi
  Vector2D t; // [esp+4h] [ebp-Ch] BYREF
  int j; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %f %f", &j, &t, &t.y) != 3 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v0 = j;
    t.y = 1.0 - t.y;
    if ( g_texcoord.m_Size < j + 1 )
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        this: &g_texcoord,
        elem: g_texcoord.m_Size,
        num: j + 1 - g_texcoord.m_Size);
    g_texcoord.m_Memory.m_pMemory[v0].x = t.x;
    v1 = j;
    if ( g_texcoord.m_Size < j + 1 )
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        this: &g_texcoord,
        elem: g_texcoord.m_Size,
        num: j + 1 - g_texcoord.m_Size);
    g_texcoord.m_Memory.m_pMemory[v1].y = t.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E00
// Name: void Grab_Normallist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Normallist(s_source_t *psource)
{
  int v1; // esi
  Vector n; // [esp+8h] [ebp-14h] BYREF
  int j; // [esp+14h] [ebp-8h] BYREF
  int bone; // [esp+18h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %d %f %f %f", &j, &bone, &n, &n.y, &n.z) != 5 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    if ( bone < 0 || bone >= psource->numbones )
    {
      MdlWarning(fmt: "bogus bone index\n");
      MdlWarning(fmt: "%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
      MdlError(fmt: "Exiting due to errors\n");
    }
    v1 = j;
    if ( g_normal.m_Size < j + 1 )
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
        elem: g_normal.m_Size,
        num: j + 1 - g_normal.m_Size);
    g_normal.m_Memory.m_pMemory[v1] = n;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F60
// Name: void Grab_Faceattriblist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Faceattriblist(s_source_t *psource)
{
  int v1; // ecx
  int m_Size; // eax
  int v3; // esi
  int v4; // esi
  unsigned int b; // edx
  int v6; // esi
  int v7; // ecx
  unsigned int b_low; // edx
  unsigned int tb_low; // edx
  unsigned int nb_low; // edx
  int v11; // edi
  s_tmpface_t f; // [esp+Ch] [ebp-40h] BYREF
  int smooth; // [esp+40h] [ebp-Ch] BYREF
  int material; // [esp+44h] [ebp-8h] BYREF
  int j; // [esp+48h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    memset(&f.a, 255, 48);
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2F7EB == 0 || byte_2E2F7EB == 10) )
      break;
    if ( sscanf(
           string: g_szLine,
           format: "%d %d %d %d %d %d %d %d %d",
           &j,
           &material,
           &smooth,
           &f.ta,
           &f.tb,
           &f.tc,
           &f.na,
           &f.nb,
           &f.nc) != 9 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v1 = j;
    m_Size = g_face.m_Size;
    v3 = j;
    if ( g_face.m_Size < j + 1 )
    {
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
      v1 = j;
      m_Size = g_face.m_Size;
    }
    f.a = g_face.m_Memory.m_pMemory[v3].a;
    v4 = v1;
    if ( m_Size < v1 + 1 )
    {
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: m_Size,
        num: v1 + 1 - m_Size);
      v1 = j;
      m_Size = g_face.m_Size;
    }
    b = g_face.m_Memory.m_pMemory[v4].b;
    v6 = v1;
    v7 = v1 + 1;
    f.b = b;
    if ( m_Size < v7 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: m_Size,
        num: v7 - m_Size);
    f.c = g_face.m_Memory.m_pMemory[v6].c;
    f.material = UseTextureAsMaterial(textureindex: psource->texmap[material]);
    if ( f.material < 0 )
      MdlError(fmt: "face %d references NULL texture %d\n", j, material);
    b_low = LOWORD(f.b);
    f.b = f.c;
    f.c = b_low;
    tb_low = LOWORD(f.tb);
    f.tb = f.tc;
    f.tc = tb_low;
    nb_low = LOWORD(f.nb);
    f.nb = f.nc;
    v11 = j;
    f.nc = nb_low;
    if ( g_face.m_Size < j + 1 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
    g_face.m_Memory.m_pMemory[v11] = f;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418170
// Name: void UnifyIndices(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyIndices()
{
  int v0; // edi
  int v1; // esi
  int m_Size; // eax
  s_tmpface_t *v3; // ebx
  int v4; // eax
  s_tmpface_t *v5; // ebx
  int v6; // eax
  s_tmpface_t *v7; // ebx
  int v8; // eax
  s_tmpface_t *v9; // ebx
  s_face_t *v10; // eax
  __int64 uface; // [esp+4h] [ebp-1Ch]
  unsigned __int64 uface_8; // [esp+Ch] [ebp-14h]
  s_tmpface_t *v13; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v14; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v15; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v16; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v17; // [esp+18h] [ebp-8h]
  s_tmpface_t *v18; // [esp+18h] [ebp-8h]
  s_tmpface_t *v19; // [esp+18h] [ebp-8h]
  s_tmpface_t *v20; // [esp+18h] [ebp-8h]
  int v21; // [esp+1Ch] [ebp-4h]

  v0 = 0;
  g_numvlist = 0;
  memset(dst: (unsigned __int8 *)v_list, value: 0, count: sizeof(v_list));
  memset(dst: (unsigned __int8 *)v_listdata, value: 0, count: sizeof(v_listdata));
  if ( (int)g_numfaces > 0 )
  {
    v21 = 0;
    v1 = 1;
    do
    {
      m_Size = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        m_Size = g_face.m_Size;
      }
      v17 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
        m_Size = g_face.m_Size;
      }
      v13 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
        m_Size = g_face.m_Size;
      }
      v3 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
      LODWORD(uface) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].a, m: v3->material, n: v13->na, t: v17->ta);
      v4 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v4 = g_face.m_Size;
      }
      v14 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
        v4 = g_face.m_Size;
      }
      v18 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
        v4 = g_face.m_Size;
      }
      v5 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
      HIDWORD(uface) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].b, m: v5->material, n: v18->nb, t: v14->tb);
      v6 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v6 = g_face.m_Size;
      }
      v15 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
        v6 = g_face.m_Size;
      }
      v19 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
        v6 = g_face.m_Size;
      }
      v7 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
      uface_8 = (unsigned int)AddToVlist(v: g_face.m_Memory.m_pMemory[v0].c, m: v7->material, n: v19->nc, t: v15->tc)
              | 0xFFFFFFFF00000000uLL;
      v8 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v8 = g_face.m_Size;
      }
      if ( g_face.m_Memory.m_pMemory[v0].d != -1 )
      {
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v16 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v20 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v9 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
        HIDWORD(uface_8) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].d, m: v9->material, n: v20->nd, t: v16->td);
      }
      if ( g_src_uface.m_Size < v1 )
        CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
          this: &g_src_uface,
          elem: g_src_uface.m_Size,
          num: v1 - g_src_uface.m_Size);
      v10 = &g_src_uface.m_Memory.m_pMemory[v21];
      *(_QWORD *)&v10->a = uface;
      ++v1;
      *(_QWORD *)&v10->c = uface_8;
      ++v0;
      ++v21;
    }
    while ( v1 - 1 < (int)g_numfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418520
// Name: BuildUniqueVertexList
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildUniqueVertexList(s_source_t *pSource, const int *pDesiredToVList)
{
  s_source_t *v2; // esi
  signed int numvertices; // edi
  s_vertexinfo_t *v4; // ebx
  int v; // edi
  int m_Size; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // edx
  Vector *m_pMemory; // ecx
  int v11; // eax
  float *p_x; // eax
  int n; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // esi
  Vector *v17; // ecx
  int v18; // eax
  float *v19; // eax
  int t; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // esi
  Vector2D *v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // edi
  int v29; // edx
  Vector2D *v30; // ecx
  int v31; // eax
  int v32; // esi
  int v33; // ebx
  int v34; // eax
  int v35; // esi
  int v36; // edi
  int v37; // edx
  s_boneweight_t *v38; // ecx
  int v39; // eax
  int v40; // edi
  int v41; // eax
  int v42; // ecx
  int v43; // esi
  int v44; // ebx
  int v45; // edx
  s_boneweight_t *v46; // ecx
  int v47; // eax
  s_vertexinfo_t *vertex; // [esp+8h] [ebp-1Ch]
  int v49; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int v51; // [esp+18h] [ebp-Ch]
  int v52; // [esp+18h] [ebp-Ch]
  int v53; // [esp+18h] [ebp-Ch]
  float *weight; // [esp+18h] [ebp-Ch]
  int k; // [esp+1Ch] [ebp-8h]
  int ka; // [esp+1Ch] [ebp-8h]
  int v57; // [esp+20h] [ebp-4h]

  v2 = pSource;
  numvertices = pSource->numvertices;
  pSource->vertex = (s_vertexinfo_t *)calloc(count: numvertices, size: 0x54u);
  i = 0;
  if ( numvertices <= 0 )
    return;
  v49 = 0;
  while ( 2 )
  {
    v4 = &v2->vertex[v49];
    v = v_listdata[pDesiredToVList[i]].v;
    v57 = pDesiredToVList[i];
    m_Size = g_vertex.m_Size;
    v7 = v + 1;
    vertex = v4;
    if ( g_vertex.m_Size >= v + 1 )
      goto LABEL_11;
    v8 = v7 - g_vertex.m_Size;
    v51 = g_vertex.m_Size;
    if ( v7 == g_vertex.m_Size )
      goto LABEL_11;
    v9 = v + 1;
    if ( v7 > g_vertex.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
        num: v8 + g_vertex.m_Size - g_vertex.m_Memory.m_nAllocationCount);
      m_Size = g_vertex.m_Size;
      v9 = v + 1;
    }
    m_pMemory = g_vertex.m_Memory.m_pMemory;
    g_vertex.m_Size = v8 + m_Size;
    g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
    v11 = m_Size - v51;
    if ( v11 > 0 && v8 > 0 )
    {
      _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[v9], src: &g_vertex.m_Memory.m_pMemory[v51], count: 12 * v11);
LABEL_11:
      m_pMemory = g_vertex.m_Memory.m_pMemory;
    }
    p_x = &m_pMemory[v].x;
    v4->position.x = *p_x;
    v4->position.y = p_x[1];
    v4->position.z = p_x[2];
    n = v_listdata[v57].n;
    v14 = g_normal.m_Size;
    v15 = n + 1;
    if ( g_normal.m_Size >= n + 1 )
      goto LABEL_19;
    v16 = v15 - g_normal.m_Size;
    v52 = g_normal.m_Size;
    if ( v15 == g_normal.m_Size )
      goto LABEL_19;
    if ( v15 > g_normal.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
        num: v16 + g_normal.m_Size - g_normal.m_Memory.m_nAllocationCount);
      v14 = g_normal.m_Size;
    }
    v17 = g_normal.m_Memory.m_pMemory;
    g_normal.m_Size = v16 + v14;
    v18 = v14 - v52;
    g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
    if ( v18 > 0 && v16 > 0 )
    {
      _V_memmove(dest: &g_normal.m_Memory.m_pMemory[n + 1], src: &g_normal.m_Memory.m_pMemory[v52], count: 12 * v18);
LABEL_19:
      v17 = g_normal.m_Memory.m_pMemory;
    }
    v19 = &v17[n].x;
    v4->normal.x = *v19;
    v4->normal.y = v19[1];
    v4->normal.z = v19[2];
    t = v_listdata[v57].t;
    v21 = g_texcoord.m_Size;
    v22 = t + 1;
    if ( g_texcoord.m_Size >= t + 1 )
      goto LABEL_27;
    v23 = v22 - g_texcoord.m_Size;
    v53 = g_texcoord.m_Size;
    if ( v22 == g_texcoord.m_Size )
      goto LABEL_27;
    if ( v22 > g_texcoord.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<mergelist_t,int>::Grow(
        this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
        num: g_texcoord.m_Size + v23 - g_texcoord.m_Memory.m_nAllocationCount);
      v21 = g_texcoord.m_Size;
    }
    v24 = g_texcoord.m_Memory.m_pMemory;
    g_texcoord.m_Size = v23 + v21;
    v25 = v21 - v53;
    g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
    if ( v25 > 0 && v23 > 0 )
    {
      _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[t + 1], src: &g_texcoord.m_Memory.m_pMemory[v53], count: 8 * v25);
LABEL_27:
      v24 = g_texcoord.m_Memory.m_pMemory;
    }
    v4->texcoord.x = v24[t].x;
    v26 = g_texcoord.m_Size;
    k = v_listdata[v57].t;
    if ( g_texcoord.m_Size < k + 1 )
    {
      v27 = k + 1 - g_texcoord.m_Size;
      v28 = g_texcoord.m_Size;
      if ( v27 != 0 )
      {
        v29 = k + 1;
        if ( k + 1 > g_texcoord.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<mergelist_t,int>::Grow(
            this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
            num: g_texcoord.m_Size + v27 - g_texcoord.m_Memory.m_nAllocationCount);
          v26 = g_texcoord.m_Size;
          v29 = k + 1;
        }
        v30 = g_texcoord.m_Memory.m_pMemory;
        g_texcoord.m_Size = v27 + v26;
        v31 = v26 - v28;
        g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
        if ( v31 <= 0 || v27 <= 0 )
          goto LABEL_36;
        _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v29], src: &g_texcoord.m_Memory.m_pMemory[v28], count: 8 * v31);
      }
    }
    v30 = g_texcoord.m_Memory.m_pMemory;
LABEL_36:
    v4->texcoord.y = v30[k].y;
    v32 = v_listdata[v57].v;
    if ( g_bone.m_Size < v32 + 1 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v32 + 1 - g_bone.m_Size);
    v4->boneweight.numbones = g_bone.m_Memory.m_pMemory[v32].numbones;
    ka = 0;
    weight = v4->boneweight.weight;
    do
    {
      v33 = v_listdata[v57].v;
      v34 = g_bone.m_Size;
      if ( g_bone.m_Size >= v33 + 1 )
        goto LABEL_46;
      v35 = v33 + 1 - g_bone.m_Size;
      v36 = g_bone.m_Size;
      if ( v35 == 0 )
        goto LABEL_46;
      v37 = v33 + 1;
      if ( v33 + 1 > g_bone.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
          this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
          num: g_bone.m_Size + v35 - g_bone.m_Memory.m_nAllocationCount);
        v34 = g_bone.m_Size;
        v37 = v33 + 1;
      }
      v38 = g_bone.m_Memory.m_pMemory;
      g_bone.m_Size = v35 + v34;
      v39 = v34 - v36;
      g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
      if ( v39 > 0 && v35 > 0 )
      {
        _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v37], src: &g_bone.m_Memory.m_pMemory[v36], count: 28 * v39);
LABEL_46:
        v38 = g_bone.m_Memory.m_pMemory;
      }
      *(weight - 3) = *(float *)&v38[v33].bone[ka];
      v40 = v_listdata[v57].v;
      v41 = g_bone.m_Size;
      v42 = v40 + 1;
      if ( g_bone.m_Size >= v40 + 1 )
        goto LABEL_54;
      v43 = v42 - g_bone.m_Size;
      v44 = g_bone.m_Size;
      if ( v42 == g_bone.m_Size )
        goto LABEL_54;
      v45 = v40 + 1;
      if ( v42 > g_bone.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
          this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
          num: g_bone.m_Size + v43 - g_bone.m_Memory.m_nAllocationCount);
        v41 = g_bone.m_Size;
        v45 = v40 + 1;
      }
      v46 = g_bone.m_Memory.m_pMemory;
      g_bone.m_Size = v43 + v41;
      v47 = v41 - v44;
      g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
      if ( v47 > 0 && v43 > 0 )
      {
        _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v45], src: &g_bone.m_Memory.m_pMemory[v44], count: 28 * v47);
LABEL_54:
        v46 = g_bone.m_Memory.m_pMemory;
      }
      *weight++ = v46[v40].weight[ka++];
    }
    while ( ka < 3 );
    ++v49;
    vertex->material = v_listdata[v57].m;
    if ( ++i < pSource->numvertices )
    {
      v2 = pSource;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004189D0
// Name: faceCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl faceCompare(int *elem1, int *elem2)
{
  int v2; // ebx
  int v3; // edi
  int m_Size; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  s_tmpface_t *v10; // edi
  int i2; // [esp+Ch] [ebp-8h]
  int i1; // [esp+10h] [ebp-4h]
  s_tmpface_t *elem1a; // [esp+1Ch] [ebp+8h]
  const void *elem2a; // [esp+20h] [ebp+Ch]

  v2 = *elem2;
  v3 = *elem1;
  m_Size = g_face.m_Size;
  v5 = *elem1 + 1;
  i1 = *elem1;
  i2 = *elem2;
  elem2a = (const void *)v5;
  if ( g_face.m_Size < v5 )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v5 - g_face.m_Size);
    m_Size = g_face.m_Size;
  }
  v6 = v3;
  v7 = v2 + 1;
  elem1a = &g_face.m_Memory.m_pMemory[v6];
  if ( m_Size < v2 + 1 )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: v7 - m_Size);
    m_Size = g_face.m_Size;
  }
  v8 = v2;
  if ( elem1a->material < g_face.m_Memory.m_pMemory[v8].material )
    return -1;
  if ( m_Size < (int)elem2a )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: (int)elem2a - m_Size);
    m_Size = g_face.m_Size;
  }
  v10 = &g_face.m_Memory.m_pMemory[v6];
  if ( m_Size < v7 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: v7 - m_Size);
  if ( v10->material > g_face.m_Memory.m_pMemory[v8].material )
    return 1;
  if ( i1 < i2 )
    return -1;
  return i1 > i2;
}

//------------------------------------------------------------------------------
// Address: 0x00418AC0
// Name: PointMeshesToVertexAndFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall PointMeshesToVertexAndFaceData(s_source_t *pSource@<esi>, int *pDesiredToSrcFace)
{
  int *p_vertexoffset; // eax
  int v3; // ecx
  int v4; // ebx
  int v5; // edx
  int v6; // edi
  int material; // eax
  int v8; // ecx
  bool v9; // cc
  int *v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // eax

  p_vertexoffset = &pSource->mesh[0].vertexoffset;
  v3 = 8;
  v4 = 0;
  do
  {
    *(p_vertexoffset - 1) = 0;
    *p_vertexoffset = pSource->numvertices;
    p_vertexoffset[1] = 0;
    p_vertexoffset[2] = pSource->numfaces;
    p_vertexoffset[3] = 0;
    p_vertexoffset[4] = pSource->numvertices;
    p_vertexoffset[5] = 0;
    p_vertexoffset[6] = pSource->numfaces;
    p_vertexoffset[7] = 0;
    p_vertexoffset[8] = pSource->numvertices;
    p_vertexoffset[9] = 0;
    p_vertexoffset[10] = pSource->numfaces;
    p_vertexoffset[11] = 0;
    p_vertexoffset[12] = pSource->numvertices;
    p_vertexoffset[13] = 0;
    p_vertexoffset[14] = pSource->numfaces;
    p_vertexoffset += 16;
    --v3;
  }
  while ( v3 != 0 );
  v5 = 0;
  if ( pSource->numvertices > 0 )
  {
    v6 = 0;
    do
    {
      material = pSource->vertex[v6].material;
      v8 = material + 12601;
      material *= 2;
      ++*(_DWORD *)&pSource->filename[16 * v8];
      v9 = *(&pSource->mesh[0].vertexoffset + 2 * material) <= v5;
      v10 = &pSource->mesh[0].vertexoffset + 2 * material;
      if ( !v9 )
        *v10 = v5;
      ++v5;
      ++v6;
    }
    while ( v5 < pSource->numvertices );
  }
  if ( pSource->numfaces > 0 )
  {
    do
    {
      v11 = pDesiredToSrcFace[v4];
      if ( g_face.m_Size < v11 + 1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v11 + 1 - g_face.m_Size);
      v12 = g_face.m_Memory.m_pMemory[v11].material;
      ++pSource->mesh[v12].numfaces;
      v13 = &pSource->filename[v12 * 16];
      if ( *((_DWORD *)v13 + 50407) > v4 )
        *((_DWORD *)v13 + 50407) = v4;
      ++v4;
    }
    while ( v4 < pSource->numfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418BF0
// Name: BuildFaceList
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFaceList(s_source_t *pSource, int *pVListToDesired, int *pDesiredToSrcFace)
{
  s_source_t *v3; // esi
  int v4; // eax
  int *p_faceoffset; // edi
  int v6; // ecx
  int m_Size; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // ebx
  int v11; // ecx
  int m; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v3 = pSource;
  pSource->face = (s_face_t *)calloc(count: pSource->numfaces, size: 0x10u);
  v4 = 0;
  m = 0;
  p_faceoffset = &pSource->mesh[0].faceoffset;
  do
  {
    if ( *(p_faceoffset - 1) != 0 )
    {
      v3->meshindex[v3->nummeshes++] = v4;
      v6 = *p_faceoffset;
      i = *p_faceoffset;
      if ( *p_faceoffset < *p_faceoffset + *(p_faceoffset - 1) )
      {
        v14 = v6;
        m_Size = g_src_uface.m_Size;
        do
        {
          v8 = pDesiredToSrcFace[v6];
          v9 = v8 + 1;
          if ( m_Size < v8 + 1 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: m_Size,
              num: v9 - m_Size);
          v10 = v8;
          pSource->face[v14].a = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].a] - *(p_faceoffset - 2);
          if ( g_src_uface.m_Size < v9 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
          pSource->face[v14].b = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].b] - *(p_faceoffset - 2);
          if ( g_src_uface.m_Size < v9 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
          pSource->face[v14].c = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].c] - *(p_faceoffset - 2);
          m_Size = g_src_uface.m_Size;
          if ( g_src_uface.m_Size < v9 )
          {
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
            m_Size = g_src_uface.m_Size;
          }
          v11 = i;
          if ( g_src_uface.m_Memory.m_pMemory[v10].d != -1 )
          {
            if ( m_Size < v9 )
            {
              CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
                this: &g_src_uface,
                elem: m_Size,
                num: v9 - m_Size);
              v11 = i;
            }
            pSource->face[v14].d = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].d] - *(p_faceoffset - 2);
            m_Size = g_src_uface.m_Size;
          }
          ++v14;
          v6 = v11 + 1;
          i = v6;
        }
        while ( v6 < *p_faceoffset + *(p_faceoffset - 1) );
        v3 = pSource;
        v4 = m;
      }
    }
    ++v4;
    p_faceoffset += 4;
    m = v4;
  }
  while ( v4 < 32 );
}

//------------------------------------------------------------------------------
// Address: 0x00418DC0
// Name: void BuildIndividualMeshes(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildIndividualMeshes(s_source_t *pSource)
{
  unsigned int v1; // edi
  int *v2; // edi
  _DWORD *v3; // ebx
  unsigned int v4; // ecx
  signed int i; // eax
  int *v_listsort; // [esp+Ch] [ebp-4h]

  v1 = 4 * g_numvlist;
  v_listsort = (int *)MemAlloc_Alloc(nSize: 4 * g_numvlist);
  v2 = (int *)MemAlloc_Alloc(nSize: v1);
  v3 = MemAlloc_Alloc(nSize: 4 * g_numfaces);
  SortVerticesByMaterial(pDesiredToVList: v_listsort, pVListToDesired: v2);
  v4 = g_numfaces;
  for ( i = 0; i < (int)g_numfaces; ++i )
  {
    v3[i] = i;
    v4 = g_numfaces;
  }
  qsort(base: v3, num: v4, width: 4u, comp: (int (__cdecl *)(const void *, const void *))faceCompare);
  pSource->numvertices = g_numvlist;
  pSource->numfaces = g_numfaces;
  BuildUniqueVertexList(pSource, pDesiredToVList: v_listsort);
  PointMeshesToVertexAndFaceData(pSource, pDesiredToSrcFace: v3);
  BuildFaceList(pSource, pVListToDesired: v2, pDesiredToSrcFace: v3);
  RemapVertexAnimations(pSource, pVListToDesired: v2);
  CalcModelTangentSpaces(pSrc: pSource);
  free(pMem: v3);
  free(pMem: v2);
  free(pMem: v_listsort);
}

//------------------------------------------------------------------------------
// Address: 0x00418E90
// Name: int Load_VRM(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_VRM(s_source_t *psource)
{
  int result; // eax
  char cmd[1024]; // [esp+4h] [ebp-404h] BYREF
  int option; // [esp+404h] [ebp-4h] BYREF

  result = OpenGlobalFile(src: psource->filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "grabbing %s\n", psource->filename);
    g_iLinecount = 0;
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) != nullptr )
    {
      ++g_iLinecount;
      sscanf(string: g_szLine, format: "%1023s %d", cmd, &option);
      if ( _V_stricmp(s1: cmd, s2: "version") != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "name") != 0 )
        {
          if ( _V_stricmp(s1: cmd, s2: "vertices") != 0 )
          {
            if ( _V_stricmp(s1: cmd, s2: "faces") != 0 )
            {
              if ( _V_stricmp(s1: cmd, s2: "materials") != 0 )
              {
                if ( _V_stricmp(s1: cmd, s2: "texcoords") != 0 )
                {
                  if ( _V_stricmp(s1: cmd, s2: "normals") != 0 )
                  {
                    if ( _V_stricmp(s1: cmd, s2: "tristrips") != 0 )
                    {
                      if ( _V_stricmp(s1: cmd, s2: "vertexlist") != 0 )
                      {
                        if ( _V_stricmp(s1: cmd, s2: "facelist") != 0 )
                        {
                          if ( _V_stricmp(s1: cmd, s2: "materiallist") != 0 )
                          {
                            if ( _V_stricmp(s1: cmd, s2: "texcoordlist") != 0 )
                            {
                              if ( _V_stricmp(s1: cmd, s2: "normallist") != 0 )
                              {
                                if ( _V_stricmp(s1: cmd, s2: "faceattriblist") != 0 )
                                {
                                  if ( _V_stricmp(s1: cmd, s2: "MRM") != 0
                                    && _V_stricmp(s1: cmd, s2: "MRMvertices") != 0
                                    && _V_stricmp(s1: cmd, s2: "MRMfaces") != 0 )
                                  {
                                    if ( _V_stricmp(s1: cmd, s2: "MRMfaceupdates") != 0 )
                                    {
                                      if ( _V_stricmp(s1: cmd, s2: "nodes") != 0 )
                                      {
                                        if ( _V_stricmp(s1: cmd, s2: "skeleton") != 0 )
                                          MdlError(fmt: "unknown VRM command : %s \n", cmd);
                                        Grab_Animation(pSource: psource, pAnimName: "BindPose");
                                      }
                                      else
                                      {
                                        psource->numbones = Grab_Nodes(pnodes: psource->localBone);
                                      }
                                    }
                                    else
                                    {
                                      Grab_MRMFaceupdates();
                                    }
                                  }
                                }
                                else
                                {
                                  Grab_Faceattriblist(psource);
                                }
                              }
                              else
                              {
                                Grab_Normallist(psource);
                              }
                            }
                            else
                            {
                              Grab_Texcoordlist();
                            }
                          }
                          else
                          {
                            Grab_Materiallist(psource);
                          }
                        }
                        else
                        {
                          Grab_Facelist();
                        }
                      }
                      else
                      {
                        Grab_Vertexlist(psource);
                      }
                    }
                  }
                  else
                  {
                    g_numnormals = option;
                  }
                }
                else
                {
                  g_numtexcoords = option;
                  if ( option == 0 )
                    MdlError(fmt: "model has no texture coordinates\n");
                }
              }
            }
            else
            {
              g_numfaces = option;
            }
          }
          else
          {
            g_numverts = option;
          }
        }
      }
      else if ( option != 2 )
      {
        MdlError(fmt: "bad version\n");
      }
    }
    UnifyIndices();
    BuildIndividualMeshes(pSource: psource);
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
// Address: 0x0040FBC0
// Name: bool IsEnd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsEnd(const char *pLine)
{
  char v2; // al

  if ( strncmp(first: "end", last: pLine, count: 3u) != 0 )
    return false;
  v2 = pLine[3];
  return v2 == 0 || v2 == 10;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC00
// Name: int SortAndBalanceBones(int,int,int __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortAndBalanceBones(int iCount, int iMaxCount, char *bones, float *weights)
{
  signed int v4; // ecx
  char *v5; // edx
  float *v6; // ebx
  int v7; // esi
  int v8; // edi
  float *v9; // eax
  bool v10; // zf
  int v11; // esi
  int v12; // edi
  float *v13; // eax
  int *v14; // ecx
  int v15; // edx
  unsigned int v16; // ebx
  float v17; // xmm0_4
  int v18; // xmm0_4
  int v19; // xmm0_4
  int v20; // xmm0_4
  int v21; // eax
  float *v22; // eax
  int v23; // ebx
  int v24; // ecx
  float v25; // xmm0_4
  float *v26; // eax
  float *v27; // eax
  int v28; // esi
  float v29; // xmm0_4
  unsigned int v30; // edx
  float *v31; // eax
  int v33; // edx
  float v34; // xmm0_4
  unsigned int v35; // esi
  float *v36; // eax
  int v37; // [esp+4h] [ebp-10h]
  int v38; // [esp+8h] [ebp-Ch]
  int v39; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]
  int ja; // [esp+10h] [ebp-4h]
  int jc; // [esp+10h] [ebp-4h]
  int jd; // [esp+10h] [ebp-4h]
  int je; // [esp+10h] [ebp-4h]
  int jf; // [esp+10h] [ebp-4h]
  int jb; // [esp+10h] [ebp-4h]
  int t; // [esp+20h] [ebp+Ch]

  v4 = iCount;
  v5 = bones;
  v6 = weights;
  if ( iCount - 1 > 0 )
  {
    v7 = 0;
    v8 = 1;
    j = 0;
    v38 = 1;
    v37 = iCount - 1;
    do
    {
      if ( v8 < iCount )
      {
        v9 = (float *)((char *)weights + v7 + 4);
        v39 = iCount - v8;
        v7 = j;
        do
        {
          v10 = *(_DWORD *)&bones[v7] == *(_DWORD *)((char *)v9 + bones - (char *)weights);
          v7 = j;
          if ( v10 )
          {
            *(float *)((char *)weights + j) = *v9 + *(float *)((char *)weights + j);
            *v9 = 0.0;
          }
          ++v9;
          --v39;
        }
        while ( v39 != 0 );
        v8 = v38;
      }
      ++v8;
      v7 += 4;
      v10 = v37-- == 1;
      v38 = v8;
      j = v7;
    }
    while ( !v10 );
  }
  do
  {
    v11 = 0;
    v12 = 0;
    ja = v4 - 1;
    if ( v4 - 1 >= 4 )
    {
      v13 = v6 + 1;
      v14 = (int *)(v5 + 8);
      v15 = v5 - (char *)v6;
      v16 = ((unsigned int)(ja - 4) >> 2) + 1;
      v12 = 4 * v16;
      do
      {
        if ( *v13 > *(v13 - 1) )
        {
          jc = *(_DWORD *)((char *)v13 + v15);
          *(_DWORD *)((char *)v13 + v15) = *(v14 - 2);
          *(v14 - 2) = jc;
          v17 = *v13;
          *v13 = *(v13 - 1);
          *(v13 - 1) = v17;
          v11 = 1;
        }
        if ( v13[1] > *v13 )
        {
          jd = *v14;
          *v14 = *(_DWORD *)((char *)v13 + v15);
          *(_DWORD *)((char *)v13 + v15) = jd;
          v18 = *((_DWORD *)v13 + 1);
          v13[1] = *v13;
          *(_DWORD *)v13 = v18;
          v11 = 1;
        }
        if ( v13[2] > v13[1] )
        {
          je = v14[1];
          v14[1] = *v14;
          *v14 = je;
          v19 = *((_DWORD *)v13 + 2);
          v13[2] = v13[1];
          *((_DWORD *)v13 + 1) = v19;
          v11 = 1;
        }
        if ( v13[3] > v13[2] )
        {
          jf = v14[2];
          v14[2] = v14[1];
          v14[1] = jf;
          v20 = *((_DWORD *)v13 + 3);
          v13[3] = v13[2];
          *((_DWORD *)v13 + 2) = v20;
          v11 = 1;
        }
        v13 += 4;
        v14 += 4;
        --v16;
      }
      while ( v16 != 0 );
      v6 = weights;
      v5 = bones;
      v4 = iCount;
    }
    v21 = v4 - 1;
    jb = v4 - 1;
    if ( v12 < v4 - 1 )
    {
      v22 = &v6[v12 + 1];
      v23 = v5 - (char *)weights;
      do
      {
        if ( *v22 > *(v22 - 1) )
        {
          v24 = *(_DWORD *)((char *)v22 + v23);
          *(float *)((char *)v22 + v23) = *(float *)&v5[4 * v12];
          *(_DWORD *)&v5[4 * v12] = v24;
          v25 = *v22;
          *v22 = *(v22 - 1);
          *(v22 - 1) = v25;
          v11 = 1;
        }
        ++v12;
        ++v22;
      }
      while ( v12 < jb );
      v6 = weights;
      v4 = iCount;
      v21 = jb;
    }
  }
  while ( v11 != 0 );
  if ( v4 > 1 )
  {
    if ( v21 < 4 )
    {
LABEL_38:
      if ( v4 <= 1 )
        goto LABEL_47;
      v27 = &v6[v4 - 1];
      do
      {
        if ( *v27 >= 0.05 )
          break;
        --v4;
        --v27;
      }
      while ( v4 > 1 );
    }
    else
    {
      v26 = &v6[v4 - 2];
      while ( v26[1] < 0.05 )
      {
        if ( *v26 >= 0.05 )
        {
          --v4;
          break;
        }
        if ( *(v26 - 1) >= 0.05 )
        {
          v4 -= 2;
          break;
        }
        if ( *(v26 - 2) >= 0.05 )
        {
          v4 -= 3;
          break;
        }
        v4 -= 4;
        v26 -= 4;
        if ( v4 <= 4 )
        {
          iCount = v4;
          goto LABEL_38;
        }
      }
    }
    iCount = v4;
  }
LABEL_47:
  if ( v4 > iMaxCount )
  {
    iCount = iMaxCount;
    v4 = iMaxCount;
  }
  v28 = 0;
  v29 = 0.0;
  if ( v4 >= 4 )
  {
    v30 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v31 = v6 + 2;
    v28 = 4 * v30;
    do
    {
      v29 = (float)((float)((float)(v29 + *(v31 - 2)) + *(v31 - 1)) + *v31) + v31[1];
      v31 += 4;
      --v30;
    }
    while ( v30 != 0 );
  }
  for ( ; v28 < v4; ++v28 )
    v29 = v29 + v6[v28];
  if ( v29 > 0.0 )
  {
    v33 = 0;
    v34 = 1.0 / v29;
    if ( v4 >= 4 )
    {
      v35 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v36 = v6 + 2;
      v33 = 4 * v35;
      do
      {
        *(v36 - 2) = *(v36 - 2) * v34;
        *(v36 - 1) = *(v36 - 1) * v34;
        *v36 = *v36 * v34;
        v36[1] = v36[1] * v34;
        v36 += 4;
        --v35;
      }
      while ( v35 != 0 );
    }
    for ( ; v33 < v4; ++v33 )
      v6[v33] = v34 * v6[v33];
  }
  else if ( v4 > 0 )
  {
    *(float *)&t = 1.0 / (double)v4;
    memset32(v6, t, v4);
    return iCount;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFA0
// Name: void Grab_Materiallist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Materiallist(s_source_t *psource)
{
  int v1; // eax
  char path[260]; // [esp+4h] [ebp-13Ch] BYREF
  float g; // [esp+108h] [ebp-38h] BYREF
  rgb2_t a; // [esp+10Ch] [ebp-34h] BYREF
  rgb2_t d; // [esp+11Ch] [ebp-24h] BYREF
  rgb2_t s; // [esp+12Ch] [ebp-14h] BYREF
  int j; // [esp+13Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    if ( sscanf(
           string: g_szLine,
           format: "%d  %f %f %f %f   %f %f %f %f  %f %f %f %f  %f \"%[^\"]s",
           &j,
           &a,
           &a.g,
           &a.b,
           &a.a,
           &d,
           &d.g,
           &d.b,
           &d.a,
           &s,
           &s.g,
           &s.b,
           &s.a,
           &g,
           path) == 15 )
    {
      if ( path[0] != 0 )
      {
        if ( (unsigned int)j >= 0x200 )
          MdlError(fmt: "Too many materials, max %d\n", 512);
        v1 = LookupTexture(pTextureName: path, bRelativePath: false);
        psource->texmap[j] = v1;
      }
      else
      {
        psource->texmap[j] = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004100C0
// Name: int AddToVlist(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddToVlist(int v, int m, int n, int t)
{
  v_unify_t *v4; // eax
  v_unify_t *v5; // esi
  v_unify_t *v6; // eax

  v4 = v_list[v];
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    while ( v4->m != m || v4->n != n || v4->t != t )
    {
      v5 = v4;
      v4 = v4->next;
      if ( v4 == nullptr )
        goto LABEL_6;
    }
    ++v4->refcount;
    return v4 - v_listdata;
  }
  else
  {
LABEL_6:
    if ( (int)g_numvlist >= 0x80000 )
      MdlError(fmt: "Too many unified vertices\n");
    v6 = &v_listdata[g_numvlist++];
    v6->lastref = -1;
    v6->refcount = 1;
    v6->v = v;
    v6->m = m;
    v6->n = n;
    v6->t = t;
    if ( v5 != nullptr )
      v5->next = v6;
    else
      v_list[v] = v6;
    return g_numvlist - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410180
// Name: vlistCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl vlistCompare(_DWORD *elem1, _DWORD *elem2)
{
  v_unify_t *v2; // eax
  int m; // edx
  v_unify_t *v4; // ecx
  int v5; // esi
  int lastref; // eax
  int v8; // ecx

  v2 = &v_listdata[*elem1];
  m = v2->m;
  v4 = &v_listdata[*elem2];
  v5 = v4->m;
  if ( m < v5 )
    return -1;
  if ( m > v5 )
    return 1;
  lastref = v2->lastref;
  v8 = v4->lastref;
  if ( lastref < v8 )
    return -1;
  return lastref > v8;
}

//------------------------------------------------------------------------------
// Address: 0x004101D0
// Name: SortVerticesByMaterial
// Source: json
//------------------------------------------------------------------------------
void __usercall SortVerticesByMaterial(int *pDesiredToVList@<esi>, int *pVListToDesired@<edi>)
{
  unsigned int v2; // ecx
  signed int i; // eax
  signed int j; // eax

  v2 = g_numvlist;
  for ( i = 0; i < (int)g_numvlist; ++i )
  {
    pDesiredToVList[i] = i;
    v2 = g_numvlist;
  }
  qsort(base: pDesiredToVList, num: v2, width: 4u, comp: (int (__cdecl *)(const void *, const void *))vlistCompare);
  for ( j = 0; j < (int)g_numvlist; ++j )
    pVListToDesired[pDesiredToVList[j]] = j;
}

//------------------------------------------------------------------------------
// Address: 0x00410220
// Name: void Grab_MRMFaceupdates(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_MRMFaceupdates()
{
  do
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
  }
  while ( strncmp(first: "end", last: g_szLine, count: 3u) != 0 || byte_2E2679B != 0 && byte_2E2679B != 10 );
}

//------------------------------------------------------------------------------
// Address: 0x00410520
// Name: void Grab_Vertexlist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Vertexlist(s_source_t *psource)
{
  int v1; // eax
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // edi
  double v13; // st7
  int v14; // eax
  float weights[4]; // [esp+Ch] [ebp-38h] BYREF
  int bones[4]; // [esp+1Ch] [ebp-28h] BYREF
  Vector p; // [esp+2Ch] [ebp-18h] BYREF
  int bone; // [esp+38h] [ebp-Ch] BYREF
  int iCount; // [esp+3Ch] [ebp-8h] BYREF
  int j; // [esp+40h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    v1 = sscanf(
           string: g_szLine,
           format: "%d %d %f %f %f %d %d %f %d %f %d %f %d %f",
           &j,
           &bone,
           &p,
           &p.y,
           &p.z,
           &iCount,
           bones,
           weights,
           &bones[1],
           &weights[1],
           &bones[2],
           &weights[2],
           &bones[3],
           &weights[3]);
    if ( v1 == 5 )
    {
      if ( bone < 0 || bone >= psource->numbones )
      {
        MdlWarning(fmt: "bogus bone index\n");
        MdlWarning(fmt: "%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
        MdlError(fmt: "Exiting due to errors\n");
      }
      v2 = j;
      if ( g_vertex.m_Size < j + 1 )
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
          elem: g_vertex.m_Size,
          num: j + 1 - g_vertex.m_Size);
      g_vertex.m_Memory.m_pMemory[v2] = p;
      v3 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v3].numbones = 1;
      v4 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v4].bone[0] = bone;
      v5 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v5].weight[0] = 1.0;
    }
    else
    {
      if ( v1 <= 5 )
        MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
      v6 = SortAndBalanceBones(iCount, iMaxCount: 3, (char *)bones, weights);
      v7 = j;
      iCount = v6;
      if ( g_vertex.m_Size < j + 1 )
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
          elem: g_vertex.m_Size,
          num: j + 1 - g_vertex.m_Size);
      g_vertex.m_Memory.m_pMemory[v7] = p;
      v8 = j;
      if ( g_bone.m_Size < j + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: j + 1 - g_bone.m_Size);
      v9 = v8;
      v10 = 0;
      for ( g_bone.m_Memory.m_pMemory[v9].numbones = iCount; v10 < iCount; g_bone.m_Memory.m_pMemory->weight[v14] = v13 )
      {
        v11 = j;
        if ( g_bone.m_Size < j + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: j + 1 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v11].bone[v10] = bones[v10];
        v12 = j;
        if ( g_bone.m_Size < j + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: j + 1 - g_bone.m_Size);
        v13 = weights[v10];
        v14 = v10 + 7 * v12;
        ++v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410850
// Name: void Grab_Facelist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Facelist()
{
  int v0; // edi
  s_tmpface_t f; // [esp+Ch] [ebp-38h] BYREF
  int j; // [esp+40h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    memset(&f.a, 255, 48);
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %d %d %d", &j, &f.a, &f.b, &f.c) != 4 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v0 = j;
    if ( g_face.m_Size < j + 1 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
    g_face.m_Memory.m_pMemory[v0] = f;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410960
// Name: void Grab_Texcoordlist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Texcoordlist()
{
  int v0; // esi
  int v1; // esi
  Vector2D t; // [esp+4h] [ebp-Ch] BYREF
  int j; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %f %f", &j, &t, &t.y) != 3 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v0 = j;
    t.y = 1.0 - t.y;
    if ( g_texcoord.m_Size < j + 1 )
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        this: &g_texcoord,
        elem: g_texcoord.m_Size,
        num: j + 1 - g_texcoord.m_Size);
    g_texcoord.m_Memory.m_pMemory[v0].x = t.x;
    v1 = j;
    if ( g_texcoord.m_Size < j + 1 )
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        this: &g_texcoord,
        elem: g_texcoord.m_Size,
        num: j + 1 - g_texcoord.m_Size);
    g_texcoord.m_Memory.m_pMemory[v1].y = t.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410A80
// Name: void Grab_Normallist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Normallist(s_source_t *psource)
{
  int v1; // esi
  Vector n; // [esp+8h] [ebp-14h] BYREF
  int j; // [esp+14h] [ebp-8h] BYREF
  int bone; // [esp+18h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    if ( sscanf(string: g_szLine, format: "%d %d %f %f %f", &j, &bone, &n, &n.y, &n.z) != 5 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    if ( bone < 0 || bone >= psource->numbones )
    {
      MdlWarning(fmt: "bogus bone index\n");
      MdlWarning(fmt: "%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
      MdlError(fmt: "Exiting due to errors\n");
    }
    v1 = j;
    if ( g_normal.m_Size < j + 1 )
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
        elem: g_normal.m_Size,
        num: j + 1 - g_normal.m_Size);
    g_normal.m_Memory.m_pMemory[v1] = n;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410BD0
// Name: void Grab_Faceattriblist(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Faceattriblist(s_source_t *psource)
{
  int v1; // ecx
  int m_Size; // eax
  int v3; // esi
  int v4; // esi
  unsigned int b; // edx
  int v6; // esi
  int v7; // ecx
  unsigned int b_low; // edx
  unsigned int tb_low; // edx
  unsigned int nb_low; // edx
  int v11; // edi
  s_tmpface_t f; // [esp+Ch] [ebp-40h] BYREF
  int smooth; // [esp+40h] [ebp-Ch] BYREF
  int material; // [esp+44h] [ebp-8h] BYREF
  int j; // [esp+48h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      ;
    ++g_iLinecount;
    memset(&f.a, 255, 48);
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_2E2679B == 0 || byte_2E2679B == 10) )
      break;
    if ( sscanf(
           string: g_szLine,
           format: "%d %d %d %d %d %d %d %d %d",
           &j,
           &material,
           &smooth,
           &f.ta,
           &f.tb,
           &f.tc,
           &f.na,
           &f.nb,
           &f.nc) != 9 )
      MdlError(fmt: "%s: error on line %d: %s", g_szFilename, g_iLinecount, g_szLine);
    v1 = j;
    m_Size = g_face.m_Size;
    v3 = j;
    if ( g_face.m_Size < j + 1 )
    {
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
      v1 = j;
      m_Size = g_face.m_Size;
    }
    f.a = g_face.m_Memory.m_pMemory[v3].a;
    v4 = v1;
    if ( m_Size < v1 + 1 )
    {
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: m_Size,
        num: v1 + 1 - m_Size);
      v1 = j;
      m_Size = g_face.m_Size;
    }
    b = g_face.m_Memory.m_pMemory[v4].b;
    v6 = v1;
    v7 = v1 + 1;
    f.b = b;
    if ( m_Size < v7 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: m_Size,
        num: v7 - m_Size);
    f.c = g_face.m_Memory.m_pMemory[v6].c;
    f.material = UseTextureAsMaterial(textureindex: psource->texmap[material]);
    if ( f.material < 0 )
      MdlError(fmt: "face %d references NULL texture %d\n", j, material);
    b_low = LOWORD(f.b);
    f.b = f.c;
    f.c = b_low;
    tb_low = LOWORD(f.tb);
    f.tb = f.tc;
    f.tc = tb_low;
    nb_low = LOWORD(f.nb);
    f.nb = f.nc;
    v11 = j;
    f.nc = nb_low;
    if ( g_face.m_Size < j + 1 )
      CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
        this: &g_face,
        elem: g_face.m_Size,
        num: j + 1 - g_face.m_Size);
    g_face.m_Memory.m_pMemory[v11] = f;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410DE0
// Name: void UnifyIndices(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyIndices()
{
  int v0; // edi
  int v1; // esi
  int m_Size; // eax
  s_tmpface_t *v3; // ebx
  int v4; // eax
  s_tmpface_t *v5; // ebx
  int v6; // eax
  s_tmpface_t *v7; // ebx
  int v8; // eax
  s_tmpface_t *v9; // ebx
  s_face_t *v10; // eax
  __int64 uface; // [esp+4h] [ebp-1Ch]
  unsigned __int64 uface_8; // [esp+Ch] [ebp-14h]
  s_tmpface_t *v13; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v14; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v15; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v16; // [esp+14h] [ebp-Ch]
  s_tmpface_t *v17; // [esp+18h] [ebp-8h]
  s_tmpface_t *v18; // [esp+18h] [ebp-8h]
  s_tmpface_t *v19; // [esp+18h] [ebp-8h]
  s_tmpface_t *v20; // [esp+18h] [ebp-8h]
  int v21; // [esp+1Ch] [ebp-4h]

  v0 = 0;
  g_numvlist = 0;
  memset(dst: (unsigned __int8 *)v_list, value: 0, count: sizeof(v_list));
  memset(dst: (unsigned __int8 *)v_listdata, value: 0, count: sizeof(v_listdata));
  if ( (int)g_numfaces > 0 )
  {
    v21 = 0;
    v1 = 1;
    do
    {
      m_Size = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        m_Size = g_face.m_Size;
      }
      v17 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
        m_Size = g_face.m_Size;
      }
      v13 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
        m_Size = g_face.m_Size;
      }
      v3 = &g_face.m_Memory.m_pMemory[v0];
      if ( m_Size < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: m_Size,
          num: v1 - m_Size);
      LODWORD(uface) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].a, m: v3->material, n: v13->na, t: v17->ta);
      v4 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v4 = g_face.m_Size;
      }
      v14 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
        v4 = g_face.m_Size;
      }
      v18 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
        v4 = g_face.m_Size;
      }
      v5 = &g_face.m_Memory.m_pMemory[v0];
      if ( v4 < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v4, num: v1 - v4);
      HIDWORD(uface) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].b, m: v5->material, n: v18->nb, t: v14->tb);
      v6 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v6 = g_face.m_Size;
      }
      v15 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
        v6 = g_face.m_Size;
      }
      v19 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
        v6 = g_face.m_Size;
      }
      v7 = &g_face.m_Memory.m_pMemory[v0];
      if ( v6 < v1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(this: &g_face, elem: v6, num: v1 - v6);
      uface_8 = (unsigned int)AddToVlist(v: g_face.m_Memory.m_pMemory[v0].c, m: v7->material, n: v19->nc, t: v15->tc)
              | 0xFFFFFFFF00000000uLL;
      v8 = g_face.m_Size;
      if ( g_face.m_Size < v1 )
      {
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v1 - g_face.m_Size);
        v8 = g_face.m_Size;
      }
      if ( g_face.m_Memory.m_pMemory[v0].d != -1 )
      {
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v16 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v20 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
        {
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
          v8 = g_face.m_Size;
        }
        v9 = &g_face.m_Memory.m_pMemory[v0];
        if ( v8 < v1 )
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: v8,
            num: v1 - v8);
        HIDWORD(uface_8) = AddToVlist(v: g_face.m_Memory.m_pMemory[v0].d, m: v9->material, n: v20->nd, t: v16->td);
      }
      if ( g_src_uface.m_Size < v1 )
        CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
          this: &g_src_uface,
          elem: g_src_uface.m_Size,
          num: v1 - g_src_uface.m_Size);
      v10 = &g_src_uface.m_Memory.m_pMemory[v21];
      *(_QWORD *)&v10->a = uface;
      ++v1;
      *(_QWORD *)&v10->c = uface_8;
      ++v0;
      ++v21;
    }
    while ( v1 - 1 < (int)g_numfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411190
// Name: BuildUniqueVertexList
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildUniqueVertexList(s_source_t *pSource, const int *pDesiredToVList)
{
  s_source_t *v2; // esi
  signed int numvertices; // edi
  s_vertexinfo_t *v4; // ebx
  int v; // edi
  int m_Size; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // edx
  Vector *m_pMemory; // ecx
  int v11; // eax
  float *p_x; // eax
  int n; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // esi
  Vector *v17; // ecx
  int v18; // eax
  float *v19; // eax
  int t; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // esi
  Vector2D *v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // edi
  int v29; // edx
  Vector2D *v30; // ecx
  int v31; // eax
  int v32; // esi
  int v33; // ebx
  int v34; // eax
  int v35; // esi
  int v36; // edi
  int v37; // edx
  s_boneweight_t *v38; // ecx
  int v39; // eax
  int v40; // edi
  int v41; // eax
  int v42; // ecx
  int v43; // esi
  int v44; // ebx
  int v45; // edx
  s_boneweight_t *v46; // ecx
  int v47; // eax
  s_vertexinfo_t *vertex; // [esp+8h] [ebp-1Ch]
  int v49; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int v51; // [esp+18h] [ebp-Ch]
  int v52; // [esp+18h] [ebp-Ch]
  int v53; // [esp+18h] [ebp-Ch]
  float *weight; // [esp+18h] [ebp-Ch]
  int k; // [esp+1Ch] [ebp-8h]
  int ka; // [esp+1Ch] [ebp-8h]
  int v57; // [esp+20h] [ebp-4h]

  v2 = pSource;
  numvertices = pSource->numvertices;
  pSource->vertex = (s_vertexinfo_t *)calloc(count: numvertices, size: 0x54u);
  i = 0;
  if ( numvertices <= 0 )
    return;
  v49 = 0;
  while ( 2 )
  {
    v4 = &v2->vertex[v49];
    v = v_listdata[pDesiredToVList[i]].v;
    v57 = pDesiredToVList[i];
    m_Size = g_vertex.m_Size;
    v7 = v + 1;
    vertex = v4;
    if ( g_vertex.m_Size >= v + 1 )
      goto LABEL_11;
    v8 = v7 - g_vertex.m_Size;
    v51 = g_vertex.m_Size;
    if ( v7 == g_vertex.m_Size )
      goto LABEL_11;
    v9 = v + 1;
    if ( v7 > g_vertex.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
        num: v8 + g_vertex.m_Size - g_vertex.m_Memory.m_nAllocationCount);
      m_Size = g_vertex.m_Size;
      v9 = v + 1;
    }
    m_pMemory = g_vertex.m_Memory.m_pMemory;
    g_vertex.m_Size = v8 + m_Size;
    g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
    v11 = m_Size - v51;
    if ( v11 > 0 && v8 > 0 )
    {
      _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[v9], src: &g_vertex.m_Memory.m_pMemory[v51], count: 12 * v11);
LABEL_11:
      m_pMemory = g_vertex.m_Memory.m_pMemory;
    }
    p_x = &m_pMemory[v].x;
    v4->position.x = *p_x;
    v4->position.y = p_x[1];
    v4->position.z = p_x[2];
    n = v_listdata[v57].n;
    v14 = g_normal.m_Size;
    v15 = n + 1;
    if ( g_normal.m_Size >= n + 1 )
      goto LABEL_19;
    v16 = v15 - g_normal.m_Size;
    v52 = g_normal.m_Size;
    if ( v15 == g_normal.m_Size )
      goto LABEL_19;
    if ( v15 > g_normal.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
        num: v16 + g_normal.m_Size - g_normal.m_Memory.m_nAllocationCount);
      v14 = g_normal.m_Size;
    }
    v17 = g_normal.m_Memory.m_pMemory;
    g_normal.m_Size = v16 + v14;
    v18 = v14 - v52;
    g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
    if ( v18 > 0 && v16 > 0 )
    {
      _V_memmove(dest: &g_normal.m_Memory.m_pMemory[n + 1], src: &g_normal.m_Memory.m_pMemory[v52], count: 12 * v18);
LABEL_19:
      v17 = g_normal.m_Memory.m_pMemory;
    }
    v19 = &v17[n].x;
    v4->normal.x = *v19;
    v4->normal.y = v19[1];
    v4->normal.z = v19[2];
    t = v_listdata[v57].t;
    v21 = g_texcoord.m_Size;
    v22 = t + 1;
    if ( g_texcoord.m_Size >= t + 1 )
      goto LABEL_27;
    v23 = v22 - g_texcoord.m_Size;
    v53 = g_texcoord.m_Size;
    if ( v22 == g_texcoord.m_Size )
      goto LABEL_27;
    if ( v22 > g_texcoord.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<mergelist_t,int>::Grow(
        this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
        num: g_texcoord.m_Size + v23 - g_texcoord.m_Memory.m_nAllocationCount);
      v21 = g_texcoord.m_Size;
    }
    v24 = g_texcoord.m_Memory.m_pMemory;
    g_texcoord.m_Size = v23 + v21;
    v25 = v21 - v53;
    g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
    if ( v25 > 0 && v23 > 0 )
    {
      _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[t + 1], src: &g_texcoord.m_Memory.m_pMemory[v53], count: 8 * v25);
LABEL_27:
      v24 = g_texcoord.m_Memory.m_pMemory;
    }
    v4->texcoord.x = v24[t].x;
    v26 = g_texcoord.m_Size;
    k = v_listdata[v57].t;
    if ( g_texcoord.m_Size < k + 1 )
    {
      v27 = k + 1 - g_texcoord.m_Size;
      v28 = g_texcoord.m_Size;
      if ( v27 != 0 )
      {
        v29 = k + 1;
        if ( k + 1 > g_texcoord.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<mergelist_t,int>::Grow(
            this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
            num: g_texcoord.m_Size + v27 - g_texcoord.m_Memory.m_nAllocationCount);
          v26 = g_texcoord.m_Size;
          v29 = k + 1;
        }
        v30 = g_texcoord.m_Memory.m_pMemory;
        g_texcoord.m_Size = v27 + v26;
        v31 = v26 - v28;
        g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
        if ( v31 <= 0 || v27 <= 0 )
          goto LABEL_36;
        _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[v29], src: &g_texcoord.m_Memory.m_pMemory[v28], count: 8 * v31);
      }
    }
    v30 = g_texcoord.m_Memory.m_pMemory;
LABEL_36:
    v4->texcoord.y = v30[k].y;
    v32 = v_listdata[v57].v;
    if ( g_bone.m_Size < v32 + 1 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v32 + 1 - g_bone.m_Size);
    v4->boneweight.numbones = g_bone.m_Memory.m_pMemory[v32].numbones;
    ka = 0;
    weight = v4->boneweight.weight;
    do
    {
      v33 = v_listdata[v57].v;
      v34 = g_bone.m_Size;
      if ( g_bone.m_Size >= v33 + 1 )
        goto LABEL_46;
      v35 = v33 + 1 - g_bone.m_Size;
      v36 = g_bone.m_Size;
      if ( v35 == 0 )
        goto LABEL_46;
      v37 = v33 + 1;
      if ( v33 + 1 > g_bone.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
          this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
          num: g_bone.m_Size + v35 - g_bone.m_Memory.m_nAllocationCount);
        v34 = g_bone.m_Size;
        v37 = v33 + 1;
      }
      v38 = g_bone.m_Memory.m_pMemory;
      g_bone.m_Size = v35 + v34;
      v39 = v34 - v36;
      g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
      if ( v39 > 0 && v35 > 0 )
      {
        _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v37], src: &g_bone.m_Memory.m_pMemory[v36], count: 28 * v39);
LABEL_46:
        v38 = g_bone.m_Memory.m_pMemory;
      }
      *(weight - 3) = *(float *)&v38[v33].bone[ka];
      v40 = v_listdata[v57].v;
      v41 = g_bone.m_Size;
      v42 = v40 + 1;
      if ( g_bone.m_Size >= v40 + 1 )
        goto LABEL_54;
      v43 = v42 - g_bone.m_Size;
      v44 = g_bone.m_Size;
      if ( v42 == g_bone.m_Size )
        goto LABEL_54;
      v45 = v40 + 1;
      if ( v42 > g_bone.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
          this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
          num: g_bone.m_Size + v43 - g_bone.m_Memory.m_nAllocationCount);
        v41 = g_bone.m_Size;
        v45 = v40 + 1;
      }
      v46 = g_bone.m_Memory.m_pMemory;
      g_bone.m_Size = v43 + v41;
      v47 = v41 - v44;
      g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
      if ( v47 > 0 && v43 > 0 )
      {
        _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v45], src: &g_bone.m_Memory.m_pMemory[v44], count: 28 * v47);
LABEL_54:
        v46 = g_bone.m_Memory.m_pMemory;
      }
      *weight++ = v46[v40].weight[ka++];
    }
    while ( ka < 3 );
    ++v49;
    vertex->material = v_listdata[v57].m;
    if ( ++i < pSource->numvertices )
    {
      v2 = pSource;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411640
// Name: faceCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl faceCompare(int *elem1, int *elem2)
{
  int v2; // ebx
  int v3; // edi
  int m_Size; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  s_tmpface_t *v10; // edi
  int i2; // [esp+Ch] [ebp-8h]
  int i1; // [esp+10h] [ebp-4h]
  s_tmpface_t *elem1a; // [esp+1Ch] [ebp+8h]
  const void *elem2a; // [esp+20h] [ebp+Ch]

  v2 = *elem2;
  v3 = *elem1;
  m_Size = g_face.m_Size;
  v5 = *elem1 + 1;
  i1 = *elem1;
  i2 = *elem2;
  elem2a = (const void *)v5;
  if ( g_face.m_Size < v5 )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v5 - g_face.m_Size);
    m_Size = g_face.m_Size;
  }
  v6 = v3;
  v7 = v2 + 1;
  elem1a = &g_face.m_Memory.m_pMemory[v6];
  if ( m_Size < v2 + 1 )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: v7 - m_Size);
    m_Size = g_face.m_Size;
  }
  v8 = v2;
  if ( elem1a->material < g_face.m_Memory.m_pMemory[v8].material )
    return -1;
  if ( m_Size < (int)elem2a )
  {
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: (int)elem2a - m_Size);
    m_Size = g_face.m_Size;
  }
  v10 = &g_face.m_Memory.m_pMemory[v6];
  if ( m_Size < v7 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: m_Size,
      num: v7 - m_Size);
  if ( v10->material > g_face.m_Memory.m_pMemory[v8].material )
    return 1;
  if ( i1 < i2 )
    return -1;
  return i1 > i2;
}

//------------------------------------------------------------------------------
// Address: 0x00411730
// Name: PointMeshesToVertexAndFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall PointMeshesToVertexAndFaceData(s_source_t *pSource@<esi>, int *pDesiredToSrcFace)
{
  int *p_vertexoffset; // eax
  int v3; // ecx
  int v4; // ebx
  int v5; // edx
  int v6; // edi
  int material; // eax
  int v8; // ecx
  bool v9; // cc
  int *v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // eax

  p_vertexoffset = &pSource->mesh[0].vertexoffset;
  v3 = 8;
  v4 = 0;
  do
  {
    *(p_vertexoffset - 1) = 0;
    *p_vertexoffset = pSource->numvertices;
    p_vertexoffset[1] = 0;
    p_vertexoffset[2] = pSource->numfaces;
    p_vertexoffset[3] = 0;
    p_vertexoffset[4] = pSource->numvertices;
    p_vertexoffset[5] = 0;
    p_vertexoffset[6] = pSource->numfaces;
    p_vertexoffset[7] = 0;
    p_vertexoffset[8] = pSource->numvertices;
    p_vertexoffset[9] = 0;
    p_vertexoffset[10] = pSource->numfaces;
    p_vertexoffset[11] = 0;
    p_vertexoffset[12] = pSource->numvertices;
    p_vertexoffset[13] = 0;
    p_vertexoffset[14] = pSource->numfaces;
    p_vertexoffset += 16;
    --v3;
  }
  while ( v3 != 0 );
  v5 = 0;
  if ( pSource->numvertices > 0 )
  {
    v6 = 0;
    do
    {
      material = pSource->vertex[v6].material;
      v8 = material + 12601;
      material *= 2;
      ++*(_DWORD *)&pSource->filename[16 * v8];
      v9 = *(&pSource->mesh[0].vertexoffset + 2 * material) <= v5;
      v10 = &pSource->mesh[0].vertexoffset + 2 * material;
      if ( !v9 )
        *v10 = v5;
      ++v5;
      ++v6;
    }
    while ( v5 < pSource->numvertices );
  }
  if ( pSource->numfaces > 0 )
  {
    do
    {
      v11 = pDesiredToSrcFace[v4];
      if ( g_face.m_Size < v11 + 1 )
        CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
          this: &g_face,
          elem: g_face.m_Size,
          num: v11 + 1 - g_face.m_Size);
      v12 = g_face.m_Memory.m_pMemory[v11].material;
      ++pSource->mesh[v12].numfaces;
      v13 = &pSource->filename[v12 * 16];
      if ( *((_DWORD *)v13 + 50407) > v4 )
        *((_DWORD *)v13 + 50407) = v4;
      ++v4;
    }
    while ( v4 < pSource->numfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411860
// Name: BuildFaceList
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFaceList(s_source_t *pSource, int *pVListToDesired, int *pDesiredToSrcFace)
{
  s_source_t *v3; // esi
  int v4; // eax
  int *p_faceoffset; // edi
  int v6; // ecx
  int m_Size; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // ebx
  int v11; // ecx
  int m; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v3 = pSource;
  pSource->face = (s_face_t *)calloc(count: pSource->numfaces, size: 0x10u);
  v4 = 0;
  m = 0;
  p_faceoffset = &pSource->mesh[0].faceoffset;
  do
  {
    if ( *(p_faceoffset - 1) != 0 )
    {
      v3->meshindex[v3->nummeshes++] = v4;
      v6 = *p_faceoffset;
      i = *p_faceoffset;
      if ( *p_faceoffset < *p_faceoffset + *(p_faceoffset - 1) )
      {
        v14 = v6;
        m_Size = g_src_uface.m_Size;
        do
        {
          v8 = pDesiredToSrcFace[v6];
          v9 = v8 + 1;
          if ( m_Size < v8 + 1 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: m_Size,
              num: v9 - m_Size);
          v10 = v8;
          pSource->face[v14].a = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].a] - *(p_faceoffset - 2);
          if ( g_src_uface.m_Size < v9 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
          pSource->face[v14].b = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].b] - *(p_faceoffset - 2);
          if ( g_src_uface.m_Size < v9 )
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
          pSource->face[v14].c = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].c] - *(p_faceoffset - 2);
          m_Size = g_src_uface.m_Size;
          if ( g_src_uface.m_Size < v9 )
          {
            CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
              this: &g_src_uface,
              elem: g_src_uface.m_Size,
              num: v9 - g_src_uface.m_Size);
            m_Size = g_src_uface.m_Size;
          }
          v11 = i;
          if ( g_src_uface.m_Memory.m_pMemory[v10].d != -1 )
          {
            if ( m_Size < v9 )
            {
              CUtlVector<s_face_t,CUtlMemory<s_face_t,int>>::InsertMultipleBefore(
                this: &g_src_uface,
                elem: m_Size,
                num: v9 - m_Size);
              v11 = i;
            }
            pSource->face[v14].d = pVListToDesired[g_src_uface.m_Memory.m_pMemory[v10].d] - *(p_faceoffset - 2);
            m_Size = g_src_uface.m_Size;
          }
          ++v14;
          v6 = v11 + 1;
          i = v6;
        }
        while ( v6 < *p_faceoffset + *(p_faceoffset - 1) );
        v3 = pSource;
        v4 = m;
      }
    }
    ++v4;
    p_faceoffset += 4;
    m = v4;
  }
  while ( v4 < 32 );
}

//------------------------------------------------------------------------------
// Address: 0x00411A30
// Name: void BuildIndividualMeshes(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildIndividualMeshes(s_source_t *pSource)
{
  unsigned int v1; // edi
  int *v2; // edi
  _DWORD *v3; // ebx
  unsigned int v4; // ecx
  signed int i; // eax
  int *v_listsort; // [esp+Ch] [ebp-4h]

  v1 = 4 * g_numvlist;
  v_listsort = (int *)MemAlloc_Alloc(nSize: 4 * g_numvlist);
  v2 = (int *)MemAlloc_Alloc(nSize: v1);
  v3 = MemAlloc_Alloc(nSize: 4 * g_numfaces);
  SortVerticesByMaterial(pDesiredToVList: v_listsort, pVListToDesired: v2);
  v4 = g_numfaces;
  for ( i = 0; i < (int)g_numfaces; ++i )
  {
    v3[i] = i;
    v4 = g_numfaces;
  }
  qsort(base: v3, num: v4, width: 4u, comp: (int (__cdecl *)(const void *, const void *))faceCompare);
  pSource->numvertices = g_numvlist;
  pSource->numfaces = g_numfaces;
  BuildUniqueVertexList(pSource, pDesiredToVList: v_listsort);
  PointMeshesToVertexAndFaceData(pSource, pDesiredToSrcFace: v3);
  BuildFaceList(pSource, pVListToDesired: v2, pDesiredToSrcFace: v3);
  RemapVertexAnimations(pSource, pVListToDesired: v2);
  CalcModelTangentSpaces(pSrc: pSource);
  free(pMem: v3);
  free(pMem: v2);
  free(pMem: v_listsort);
}

//------------------------------------------------------------------------------
// Address: 0x00411B00
// Name: int Load_VRM(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_VRM(s_source_t *psource)
{
  int result; // eax
  char cmd[1024]; // [esp+4h] [ebp-404h] BYREF
  int option; // [esp+404h] [ebp-4h] BYREF

  result = OpenGlobalFile(src: psource->filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "grabbing %s\n", psource->filename);
    g_iLinecount = 0;
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) != nullptr )
    {
      ++g_iLinecount;
      sscanf(string: g_szLine, format: "%1023s %d", cmd, &option);
      if ( _V_stricmp(s1: cmd, s2: "version") != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "name") != 0 )
        {
          if ( _V_stricmp(s1: cmd, s2: "vertices") != 0 )
          {
            if ( _V_stricmp(s1: cmd, s2: "faces") != 0 )
            {
              if ( _V_stricmp(s1: cmd, s2: "materials") != 0 )
              {
                if ( _V_stricmp(s1: cmd, s2: "texcoords") != 0 )
                {
                  if ( _V_stricmp(s1: cmd, s2: "normals") != 0 )
                  {
                    if ( _V_stricmp(s1: cmd, s2: "tristrips") != 0 )
                    {
                      if ( _V_stricmp(s1: cmd, s2: "vertexlist") != 0 )
                      {
                        if ( _V_stricmp(s1: cmd, s2: "facelist") != 0 )
                        {
                          if ( _V_stricmp(s1: cmd, s2: "materiallist") != 0 )
                          {
                            if ( _V_stricmp(s1: cmd, s2: "texcoordlist") != 0 )
                            {
                              if ( _V_stricmp(s1: cmd, s2: "normallist") != 0 )
                              {
                                if ( _V_stricmp(s1: cmd, s2: "faceattriblist") != 0 )
                                {
                                  if ( _V_stricmp(s1: cmd, s2: "MRM") != 0
                                    && _V_stricmp(s1: cmd, s2: "MRMvertices") != 0
                                    && _V_stricmp(s1: cmd, s2: "MRMfaces") != 0 )
                                  {
                                    if ( _V_stricmp(s1: cmd, s2: "MRMfaceupdates") != 0 )
                                    {
                                      if ( _V_stricmp(s1: cmd, s2: "nodes") != 0 )
                                      {
                                        if ( _V_stricmp(s1: cmd, s2: "skeleton") != 0 )
                                          MdlError(fmt: "unknown VRM command : %s \n", cmd);
                                        Grab_Animation(pSource: psource, pAnimName: "BindPose");
                                      }
                                      else
                                      {
                                        psource->numbones = Grab_Nodes(pnodes: psource->localBone);
                                      }
                                    }
                                    else
                                    {
                                      Grab_MRMFaceupdates();
                                    }
                                  }
                                }
                                else
                                {
                                  Grab_Faceattriblist(psource);
                                }
                              }
                              else
                              {
                                Grab_Normallist(psource);
                              }
                            }
                            else
                            {
                              Grab_Texcoordlist();
                            }
                          }
                          else
                          {
                            Grab_Materiallist(psource);
                          }
                        }
                        else
                        {
                          Grab_Facelist();
                        }
                      }
                      else
                      {
                        Grab_Vertexlist(psource);
                      }
                    }
                  }
                  else
                  {
                    g_numnormals = option;
                  }
                }
                else
                {
                  g_numtexcoords = option;
                  if ( option == 0 )
                    MdlError(fmt: "model has no texture coordinates\n");
                }
              }
            }
            else
            {
              g_numfaces = option;
            }
          }
          else
          {
            g_numverts = option;
          }
        }
      }
      else if ( option != 2 )
      {
        MdlError(fmt: "bad version\n");
      }
    }
    UnifyIndices();
    BuildIndividualMeshes(pSource: psource);
    fclose(stream: g_fpInput);
    return 1;
  }
  return result;
}

} // namespace studiomdl
