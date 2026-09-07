// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/motionmapper/motionmapper.cpp
// Functions: 40
// ============================================================

#include "utils\motionmapper\motionmapper.h"

//------------------------------------------------------------------------------
// Address: 0x004039A0
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // edi
  int v3; // esi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  _vsnprintf(string, count: 0x1FFFu, format: fmt, ap);
  v2 = nullptr;
  if ( uselogfile )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    vprint(depth: 0, fmt: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403A90
// Name: void __near * kalloc(int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl kalloc(unsigned int num, unsigned int size)
{
  k_memtotal += size * num;
  return calloc(count: num, size);
}

//------------------------------------------------------------------------------
// Address: 0x00403AB0
// Name: void MdlWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void MdlWarning(char *fmt, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  if ( g_quiet )
  {
    if ( g_bFirstWarning )
    {
      vprint(depth: 0, fmt: "%s :\n", fullpath);
      g_bFirstWarning = false;
    }
    vprint(depth: 0, fmt: "\t");
  }
  vprint(depth: 0, fmt: "WARNING: ");
  vprint(depth: 0, fmt, va);
}

//------------------------------------------------------------------------------
// Address: 0x00403B10
// Name: void MdlError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __noreturn MdlError(char *fmt, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  if ( g_quiet )
  {
    if ( g_bFirstWarning )
    {
      vprint(depth: 0, fmt: "%s :\n", fullpath);
      g_bFirstWarning = false;
    }
    vprint(depth: 0, fmt: "\t");
  }
  vprint(depth: 0, fmt: "ERROR: ");
  vprint(depth: 0, fmt, va);
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00403B80
// Name: int OpenGlobalFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl OpenGlobalFile(char *src)
{
  char *v1; // eax
  char *v2; // edx
  char v3; // cl
  int v4; // esi
  int v5; // ebx
  char *BasePath; // eax
  char *v7; // edx
  char v8; // cl
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char v13; // [esp+7h] [ebp-809h] BYREF
  char tmp[1024]; // [esp+8h] [ebp-808h] BYREF
  char filename[1024]; // [esp+408h] [ebp-408h] BYREF
  int pathLength; // [esp+808h] [ebp-8h] BYREF
  int numBasePaths; // [esp+80Ch] [ebp-4h]

  v1 = ExpandPath(path: src);
  v2 = (char *)(filename - v1);
  do
  {
    v3 = *v1;
    v1[(_DWORD)v2] = *v1;
    ++v1;
  }
  while ( v3 != 0 );
  v4 = CmdLib_GetNumBasePaths();
  numBasePaths = v4;
  if ( CmdLib_HasBasePath(pFileName_: filename, &pathLength) == 0 )
  {
    if ( FileTime(path: filename) != -1 )
    {
      g_fpInput = fopen(file: filename, mode: "r");
      if ( g_fpInput != nullptr )
        return 1;
      MdlWarning(fmt: "reader: could not open file '%s'\n", src);
    }
    return 0;
  }
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    BasePath = CmdLib_GetBasePath(i: v5);
    v7 = (char *)(tmp - BasePath);
    do
    {
      v8 = *BasePath;
      BasePath[(_DWORD)v7] = *BasePath;
      ++BasePath;
    }
    while ( v8 != 0 );
    v9 = &filename[strlen(&filename[pathLength]) + 1] - filename;
    v10 = &v13;
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, &filename[pathLength], v9);
    if ( FileTime(path: tmp) != -1 )
      break;
    if ( ++v5 >= numBasePaths )
      return 0;
  }
  g_fpInput = fopen(file: tmp, mode: "r");
  if ( g_fpInput == nullptr )
  {
    MdlWarning(fmt: "reader: could not open file '%s'\n", src);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403CF0
// Name: void clip_rotations(class RadianEuler __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl clip_rotations(RadianEuler *rot)
{
  int i; // ecx
  float x; // xmm0_4
  float v4; // xmm0_4

  for ( i = 3; i != 0; --i )
  {
    if ( rot->x >= 3.141592653589793 )
    {
      x = rot->x;
      do
        x = x - 6.283185307179586;
      while ( x >= 3.141592653589793 );
      rot->x = x;
    }
    if ( rot->x < -3.141592653589793 )
    {
      v4 = rot->x;
      do
        v4 = v4 + 6.283185307179586;
      while ( v4 < -3.141592653589793 );
      rot->x = v4;
    }
    rot = (RadianEuler *)((char *)rot + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D90
// Name: void Build_Reference(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Build_Reference(s_source_t *psource)
{
  int v2; // edi
  int *p_parent; // ebx
  s_bone_t *v4; // ecx
  int v5; // eax
  matrix3x4_t m; // [esp+8h] [ebp-34h] BYREF
  int i; // [esp+38h] [ebp-4h]
  matrix3x4_t *psourcea; // [esp+44h] [ebp+8h]

  v2 = 0;
  i = 0;
  if ( psource->numbones > 0 )
  {
    psourcea = psource->boneToPose;
    p_parent = &psource->localBone[0].parent;
    do
    {
      AngleMatrix(angles: &psource->rawanim[0][v2].rot, matrix: &m);
      v4 = psource->rawanim[0];
      m.m_flMatVal[0][3] = v4[v2].pos.x;
      m.m_flMatVal[1][3] = v4[v2].pos.y;
      v5 = *p_parent;
      m.m_flMatVal[2][3] = v4[v2].pos.z;
      if ( v5 == -1 )
        MatrixCopy(in: &m, out: psourcea);
      else
        ConcatTransforms(in1: &psource->boneToPose[v5], in2: &m, out: psourcea);
      ++psourcea;
      ++v2;
      p_parent += 33;
      ++i;
    }
    while ( i < psource->numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E60
// Name: int Grab_Nodes(struct s_node_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Grab_Nodes(s_node_t *pnodes)
{
  int v1; // eax
  int v2; // edi
  char name[1024]; // [esp+8h] [ebp-408h] BYREF
  int parent; // [esp+408h] [ebp-8h] BYREF
  int index; // [esp+40Ch] [ebp-4h] BYREF

  v1 = 0;
  v2 = 0;
  index = 0;
  do
  {
    pnodes[v1].parent = -1;
    v1 = index + 1;
    index = v1;
  }
  while ( v1 < 512 );
  if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
LABEL_8:
    MdlError(fmt: "Unexpected EOF at line %d\n", g_iLinecount);
  while ( 1 )
  {
    ++g_iLinecount;
    if ( sscanf(string: g_szLine, format: "%d \"%[^\"]\" %d", &index, name, &parent) != 3 )
      return v2 + 1;
    strncpy(dest: (unsigned __int8 *)&pnodes[index], source: (unsigned __int8 *)name, count: 0x80u);
    pnodes[index].parent = parent;
    if ( index > v2 )
      v2 = index;
    if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F70
// Name: void Grab_Animation(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Animation(int psource)
{
  s_source_t *v1; // esi
  int v2; // ebx
  int v3; // ebx
  int v4; // edi
  s_bone_t *v5; // ecx
  s_source_t *v6; // edi
  int startframe; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // ecx
  s_bone_t *v11; // eax
  float *p_x; // eax
  int v13; // ecx
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  s_bone_t **rawanim; // ecx
  char cmd[1024]; // [esp+Ch] [ebp-41Ch] BYREF
  RadianEuler rot; // [esp+40Ch] [ebp-1Ch] BYREF
  int size; // [esp+418h] [ebp-10h]
  Vector pos; // [esp+41Ch] [ebp-Ch] BYREF

  v1 = (s_source_t *)psource;
  v2 = 3 * *(_DWORD *)(psource + 268);
  *(_DWORD *)(psource + 101824) = -1;
  v3 = 8 * v2;
  v4 = -99999999;
  size = v3;
  if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
LABEL_20:
    MdlError(fmt: "unexpected EOF: %s\n", v1->filename);
  while ( 1 )
  {
    ++g_iLinecount;
    if ( sscanf(string: g_szLine, format: "%d %f %f %f %f %f %f", &psource, &pos, &pos.y, &pos.z, &rot, &rot.y, &rot.z) != 7 )
      break;
    if ( v1->startframe < 0 )
      MdlError(fmt: "Missing frame start(%d) : %s", g_iLinecount, g_szLine);
    v5 = v1->rawanim[v4];
    pos.z = g_currentscale * pos.z;
    pos.y = g_currentscale * pos.y;
    pos.x = g_currentscale * pos.x;
    v5[psource].pos = pos;
    v5[psource].rot = rot;
    clip_rotations(&rot);
LABEL_19:
    if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      goto LABEL_20;
  }
  if ( sscanf(string: g_szLine, format: "%1023s %d", cmd, &psource) == 0 )
    MdlError(fmt: "MdlError(%d) : %s", g_iLinecount, g_szLine);
  if ( strcmp(cmd, "time") == 0 )
  {
    v6 = (s_source_t *)psource;
    if ( v1->startframe == -1 )
      v1->startframe = psource;
    startframe = v1->startframe;
    if ( (int)v6 < startframe )
      MdlError(fmt: "Frame MdlError(%d) : %s", g_iLinecount, g_szLine);
    if ( (int)v6 > v1->endframe )
      v1->endframe = (int)v6;
    v4 = (int)&v6->filename[-startframe];
    if ( v1->rawanim[v4] == nullptr )
    {
      k_memtotal += v3;
      v1->rawanim[v4] = (s_bone_t *)calloc(count: 1u, size: v3);
      if ( v4 > 0 && *(&v1->endframe + v4) != 0 )
      {
        v8 = 0;
        if ( v1->numbones > 0 )
        {
          v9 = 0;
          do
          {
            v10 = *(&v1->endframe + v4);
            v11 = v1->rawanim[v4];
            v11[v9].pos.x = *(float *)(v10 + v9 * 24);
            ++v8;
            v11[v9].pos.y = *(float *)(v10 + v9 * 24 + 4);
            v11[v9].pos.z = *(float *)(v10 + v9 * 24 + 8);
            p_x = &v1->rawanim[v4][v9].rot.x;
            v13 = *(&v1->endframe + v4);
            v14 = *(float *)(v9 * 24 + v13 + 12);
            v15 = v9 * 24 + v13 + 12;
            *p_x = v14;
            ++v9;
            p_x[1] = *(float *)(v15 + 4);
            p_x[2] = *(float *)(v15 + 8);
          }
          while ( v8 < v1->numbones );
        }
        v3 = size;
      }
    }
    goto LABEL_19;
  }
  v16 = strcmp(cmd, "end");
  if ( v16 != 0 )
    MdlError(fmt: "MdlError(%d) : %s", g_iLinecount, g_szLine);
  v17 = v1->startframe;
  v18 = v1->endframe - v17 + 1;
  v1->numframes = v18;
  if ( v18 > 0 )
  {
    rawanim = v1->rawanim;
    do
    {
      if ( *rawanim == nullptr )
        MdlError(fmt: "%s is missing frame %d\n", v1->filename, v16 + v17);
      ++v16;
      ++rawanim;
    }
    while ( v16 < v1->numframes );
  }
  Build_Reference(psource: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004042D0
// Name: int lookup_index(struct s_source_t __near *,int,class Vector __near &,class Vector __near &,class Vector2D)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lookup_index(s_source_t *psource, int material, Vector *vertex, Vector *normal, Vector2D texcoord)
{
  Vector *v5; // ebx
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // edx
  unsigned int v10; // eax
  double z; // st7
  int v12; // eax
  int *p_m; // [esp+0h] [ebp-4h]

  v5 = normal;
  v6 = numvlist;
  v7 = 0;
  if ( (int)numvlist > 0 )
  {
    p_m = &v_listdata[0].m;
    v8 = 0;
    do
    {
      v5 = normal;
      if ( *p_m == material
        && (float)((float)((float)(*(float *)&dword_C40604[v8 / 4] * normal->y)
                         + (float)(g_normal[v8 / 0xC].x * normal->x))
                 + (float)(normal->z * *(float *)&dword_C40608[v8 / 4])) > normal_blend
        && vertex->x == g_vertex[v8 / 0xC].x
        && vertex->y == *(float *)&dword_D00604[v8 / 4]
        && vertex->z == *(float *)&dword_D00608[v8 / 4]
        && g_texcoord[v7].x == texcoord.x
        && dword_BC05F4[2 * v7] == texcoord.y )
      {
        v_listdata[v7].lastref = numvlist;
        return v7;
      }
      p_m += 8;
      ++v7;
      v8 += 12;
    }
    while ( v7 < (int)numvlist );
    if ( v7 >= 0x10000 )
      MdlError(fmt: "too many indices in source: \"%s\"\n", psource->filename);
  }
  g_vertex[v7].x = vertex->x;
  v10 = 12 * v7;
  dword_D00604[v10 / 4] = SLODWORD(vertex->y);
  dword_D00608[v10 / 4] = SLODWORD(vertex->z);
  g_normal[v10 / 0xC].x = v5->x;
  dword_C40604[v10 / 4] = SLODWORD(v5->y);
  z = v5->z;
  g_texcoord[v7].x = texcoord.x;
  *(float *)&dword_C40608[v10 / 4] = z;
  v12 = v7;
  v_listdata[v12].firstref = v6;
  v_listdata[v12].lastref = v6;
  v_listdata[v12].v = v7;
  v_listdata[v12].m = material;
  v_listdata[v12].n = v7;
  v_listdata[v12].t = v7;
  numvlist = v7 + 1;
  dword_BC05F4[2 * v7] = texcoord.y;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00404470
// Name: int lookup_texture(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lookup_texture(char *texturename, int maxlen)
{
  int v2; // esi
  s_texture_t *v3; // edi

  V_StripExtension(in: texturename, out: texturename, outSize: maxlen);
  v2 = 0;
  if ( (int)g_numtextures <= 0 )
  {
$LN12:
    strncpy(dest: (unsigned __int8 *)&g_texture[v2], source: (unsigned __int8 *)texturename, count: 0x104u);
    g_numtextures = (s_source_t *)((char *)g_numtextures + 1);
    g_texture[v2].material = -1;
  }
  else
  {
    v3 = g_texture;
    while ( _V_stricmp(s1: v3->name, s2: texturename) != 0 )
    {
      ++v2;
      ++v3;
      if ( v2 >= (int)g_numtextures )
      {
        if ( v2 >= 32 )
          MdlError(fmt: "Too many materials used, max %d\n", 32);
        goto $LN12;
      }
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00404500
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
// Address: 0x004048A0
// Name: int vlistCompare(void const __near *,void const __near *)
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
// Address: 0x004048F0
// Name: int faceCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl faceCompare(int *elem1, int *elem2)
{
  int v2; // eax
  int v3; // ecx
  int material; // edx
  int v5; // esi

  v2 = *elem1;
  v3 = *elem2;
  material = g_face[*elem1].material;
  v5 = g_face[*elem2].material;
  if ( material < v5 )
    return -1;
  if ( material > v5 )
    return 1;
  if ( v2 < v3 )
    return -1;
  return v2 > v3;
}

//------------------------------------------------------------------------------
// Address: 0x00404940
// Name: CalcTriangleTangentSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall CalcTriangleTangentSpace(
        int v3@<edx>,
        Vector *sVect@<ecx>,
        Vector *tVect@<esi>,
        s_source_t *pSrc,
        int v1,
        int v2)
{
  Vector2D *texcoord; // eax
  float x; // xmm4_4
  float y; // xmm5_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector *vertex; // eax
  float v14; // xmm5_4
  float v15; // xmm3_4
  int v16; // edx
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float edge01; // [esp+0h] [ebp-3Ch]
  float p2_4; // [esp+10h] [ebp-2Ch]
  float p2_8; // [esp+14h] [ebp-28h]
  float p1_4; // [esp+1Ch] [ebp-20h]
  float p1_8; // [esp+20h] [ebp-1Ch]
  int v2a; // [esp+4Ch] [ebp+10h]
  Vector p0; // 0:^2C.12

  texcoord = pSrc->texcoord;
  x = texcoord[v3].x;
  y = texcoord[v3].y;
  v9 = texcoord[v1].x;
  v10 = texcoord[v1].y;
  v11 = texcoord[v2].x;
  v12 = texcoord[v2].y;
  vertex = pSrc->vertex;
  v14 = y - v10;
  p0 = vertex[v1];
  v15 = vertex[v2].x - p0.x;
  p1_4 = vertex[v2].y;
  p1_8 = vertex[v2].z;
  v16 = v3;
  v17 = vertex[v16].x - p0.x;
  p2_4 = vertex[v16].y;
  p2_8 = vertex[v16].z;
  sVect->x = 0.0;
  sVect->y = 0.0;
  sVect->z = 0.0;
  edge01 = v15;
  v18 = v11 - v9;
  tVect->x = 0.0;
  tVect->y = 0.0;
  tVect->z = 0.0;
  v19 = x - v9;
  *(float *)&v2a = v12 - v10;
  v20 = (float)(v14 * (float)(v11 - v9)) - (float)(v19 * (float)(v12 - v10));
  if ( fabs(v20) > 1.0e-12 )
  {
    sVect->x = sVect->x - (float)((float)(1.0 / v20) * (float)((float)(*(float *)&v2a * v17) - (float)(v14 * edge01)));
    tVect->x = tVect->x - (float)((float)(1.0 / v20) * (float)((float)(v19 * edge01) - (float)(v18 * v17)));
  }
  v21 = (float)(v14 * v18) - (float)(v19 * *(float *)&v2a);
  if ( fabs(v21) > 1.0e-12 )
  {
    sVect->y = sVect->y
             - (float)((float)(1.0 / v21)
                     * (float)((float)(*(float *)&v2a * (float)(p2_4 - p0.y)) - (float)(v14 * (float)(p1_4 - p0.y))));
    tVect->y = tVect->y
             - (float)((float)(1.0 / v21)
                     * (float)((float)(v19 * (float)(p1_4 - p0.y)) - (float)(v18 * (float)(p2_4 - p0.y))));
  }
  v22 = (float)(v14 * v18) - (float)(v19 * *(float *)&v2a);
  if ( fabs(v22) > 1.0e-12 )
  {
    sVect->z = sVect->z
             - (float)((float)(1.0 / v22)
                     * (float)((float)(*(float *)&v2a * (float)(p2_8 - p0.z)) - (float)(v14 * (float)(p1_8 - p0.z))));
    tVect->z = tVect->z
             - (float)((float)(1.0 / v22)
                     * (float)((float)(v19 * (float)(p1_8 - p0.z)) - (float)((float)(p2_8 - p0.z) * v18)));
  }
  VectorNormalize(vec: sVect);
  VectorNormalize(vec: tVect);
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: FlipFacing
// Source: json
//------------------------------------------------------------------------------
void __usercall FlipFacing(s_source_t *pSrc@<edi>)
{
  int *p_numfaces; // edx
  int j; // ecx
  s_face_t *face; // esi
  unsigned int c; // ebx
  s_face_t *v5; // eax
  unsigned int b_low; // esi
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( pSrc->nummeshes > 0 )
  {
    p_numfaces = &pSrc->mesh[0].numfaces;
    do
    {
      for ( j = 0; j < *p_numfaces; v5->c = b_low )
      {
        face = pSrc->face;
        c = face[j + p_numfaces[1]].c;
        v5 = &face[j + p_numfaces[1]];
        b_low = LOWORD(v5->b);
        ++j;
        v5->b = c;
      }
      p_numfaces += 4;
      ++i;
    }
    while ( i < pSrc->nummeshes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404C80
// Name: void SaveNodes(struct s_source_t __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveNodes(s_source_t *source, CUtlBuffer *buf)
{
  int v2; // esi
  s_node_t *localBone; // edi

  if ( source->numbones > 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "nodes\n");
    v2 = 0;
    if ( source->numbones > 0 )
    {
      localBone = source->localBone;
      do
      {
        CUtlBuffer::Printf(this: buf, pFmt: "%d \"%s\" %d\n", v2++, localBone->name, localBone->parent);
        ++localBone;
      }
      while ( v2 < source->numbones );
    }
    CUtlBuffer::Printf(this: buf, pFmt: "end\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D00
// Name: void SaveAnimation(struct s_source_t __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveAnimation(s_source_t *source, CUtlBuffer *buf)
{
  int v3; // edi
  int v4; // esi
  int v5; // edi
  int frame; // [esp+54h] [ebp-4h]
  s_bone_t **sourcea; // [esp+60h] [ebp+8h]

  if ( source->numbones > 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "skeleton\n");
    v3 = 0;
    frame = 0;
    if ( source->numframes > 0 )
    {
      sourcea = source->rawanim;
      do
      {
        CUtlBuffer::Printf(this: buf, pFmt: "time %i\n", v3 + source->startframe);
        v4 = 0;
        if ( source->numbones > 0 )
        {
          v5 = 0;
          do
          {
            CUtlBuffer::Printf(
              this: buf,
              pFmt: "%d %f %f %f %f %f %f\n",
              v4++,
              (float)((float)(1.0 / g_currentscale) * (*sourcea)[v5].pos.x),
              (float)((*sourcea)[v5].pos.y * (float)(1.0 / g_currentscale)),
              (float)((*sourcea)[v5].pos.z * (float)(1.0 / g_currentscale)),
              (*sourcea)[v5].rot.x,
              (*sourcea)[v5].rot.y,
              (*sourcea)[v5].rot.z);
            ++v5;
          }
          while ( v4 < source->numbones );
          v3 = frame;
        }
        ++sourcea;
        frame = ++v3;
      }
      while ( v3 < source->numframes );
    }
    CUtlBuffer::Printf(this: buf, pFmt: "end\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E60
// Name: void M_ConcatTransforms(struct M_matrix4x4_t const __near &,struct M_matrix4x4_t const __near &,struct M_matrix4x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl M_ConcatTransforms(const M_matrix4x4_t *in1, const M_matrix4x4_t *in2, M_matrix4x4_t *out)
{
  out->m_flMatVal[0][0] = (float)((float)((float)(in1->m_flMatVal[0][0] * in2->m_flMatVal[0][0])
                                        + (float)(in2->m_flMatVal[1][0] * in1->m_flMatVal[0][1]))
                                + (float)(in1->m_flMatVal[0][2] * in2->m_flMatVal[2][0]))
                        + (float)(in1->m_flMatVal[0][3] * in2->m_flMatVal[3][0]);
  out->m_flMatVal[0][1] = (float)((float)((float)(in2->m_flMatVal[1][1] * in1->m_flMatVal[0][1])
                                        + (float)(in2->m_flMatVal[0][1] * in1->m_flMatVal[0][0]))
                                + (float)(in1->m_flMatVal[0][2] * in2->m_flMatVal[2][1]))
                        + (float)(in1->m_flMatVal[0][3] * in2->m_flMatVal[3][1]);
  out->m_flMatVal[0][2] = (float)((float)((float)(in1->m_flMatVal[0][0] * in2->m_flMatVal[0][2])
                                        + (float)(in2->m_flMatVal[1][2] * in1->m_flMatVal[0][1]))
                                + (float)(in2->m_flMatVal[2][2] * in1->m_flMatVal[0][2]))
                        + (float)(in2->m_flMatVal[3][2] * in1->m_flMatVal[0][3]);
  out->m_flMatVal[0][3] = (float)((float)((float)(in2->m_flMatVal[1][3] * in1->m_flMatVal[0][1])
                                        + (float)(in2->m_flMatVal[0][3] * in1->m_flMatVal[0][0]))
                                + (float)(in1->m_flMatVal[0][2] * in2->m_flMatVal[2][3]))
                        + (float)(in1->m_flMatVal[0][3] * in2->m_flMatVal[3][3]);
  out->m_flMatVal[1][0] = (float)((float)((float)(in1->m_flMatVal[1][1] * in2->m_flMatVal[1][0])
                                        + (float)(in1->m_flMatVal[1][0] * in2->m_flMatVal[0][0]))
                                + (float)(in1->m_flMatVal[1][2] * in2->m_flMatVal[2][0]))
                        + (float)(in1->m_flMatVal[1][3] * in2->m_flMatVal[3][0]);
  out->m_flMatVal[1][1] = (float)((float)((float)(in2->m_flMatVal[1][1] * in1->m_flMatVal[1][1])
                                        + (float)(in2->m_flMatVal[0][1] * in1->m_flMatVal[1][0]))
                                + (float)(in1->m_flMatVal[1][2] * in2->m_flMatVal[2][1]))
                        + (float)(in1->m_flMatVal[1][3] * in2->m_flMatVal[3][1]);
  out->m_flMatVal[1][2] = (float)((float)((float)(in1->m_flMatVal[1][1] * in2->m_flMatVal[1][2])
                                        + (float)(in1->m_flMatVal[1][0] * in2->m_flMatVal[0][2]))
                                + (float)(in1->m_flMatVal[1][2] * in2->m_flMatVal[2][2]))
                        + (float)(in2->m_flMatVal[3][2] * in1->m_flMatVal[1][3]);
  out->m_flMatVal[1][3] = (float)((float)((float)(in2->m_flMatVal[1][3] * in1->m_flMatVal[1][1])
                                        + (float)(in2->m_flMatVal[0][3] * in1->m_flMatVal[1][0]))
                                + (float)(in1->m_flMatVal[1][2] * in2->m_flMatVal[2][3]))
                        + (float)(in1->m_flMatVal[1][3] * in2->m_flMatVal[3][3]);
  out->m_flMatVal[2][0] = (float)((float)((float)(in1->m_flMatVal[2][1] * in2->m_flMatVal[1][0])
                                        + (float)(in1->m_flMatVal[2][0] * in2->m_flMatVal[0][0]))
                                + (float)(in1->m_flMatVal[2][2] * in2->m_flMatVal[2][0]))
                        + (float)(in1->m_flMatVal[2][3] * in2->m_flMatVal[3][0]);
  out->m_flMatVal[2][1] = (float)((float)((float)(in2->m_flMatVal[1][1] * in1->m_flMatVal[2][1])
                                        + (float)(in2->m_flMatVal[0][1] * in1->m_flMatVal[2][0]))
                                + (float)(in1->m_flMatVal[2][2] * in2->m_flMatVal[2][1]))
                        + (float)(in1->m_flMatVal[2][3] * in2->m_flMatVal[3][1]);
  out->m_flMatVal[2][2] = (float)((float)((float)(in1->m_flMatVal[2][1] * in2->m_flMatVal[1][2])
                                        + (float)(in1->m_flMatVal[2][0] * in2->m_flMatVal[0][2]))
                                + (float)(in1->m_flMatVal[2][2] * in2->m_flMatVal[2][2]))
                        + (float)(in1->m_flMatVal[2][3] * in2->m_flMatVal[3][2]);
  out->m_flMatVal[2][3] = (float)((float)((float)(in2->m_flMatVal[1][3] * in1->m_flMatVal[2][1])
                                        + (float)(in2->m_flMatVal[0][3] * in1->m_flMatVal[2][0]))
                                + (float)(in1->m_flMatVal[2][2] * in2->m_flMatVal[2][3]))
                        + (float)(in1->m_flMatVal[2][3] * in2->m_flMatVal[3][3]);
  out->m_flMatVal[3][0] = (float)((float)((float)(in1->m_flMatVal[3][1] * in2->m_flMatVal[1][0])
                                        + (float)(in1->m_flMatVal[3][0] * in2->m_flMatVal[0][0]))
                                + (float)(in1->m_flMatVal[3][2] * in2->m_flMatVal[2][0]))
                        + (float)(in1->m_flMatVal[3][3] * in2->m_flMatVal[3][0]);
  out->m_flMatVal[3][1] = (float)((float)((float)(in2->m_flMatVal[1][1] * in1->m_flMatVal[3][1])
                                        + (float)(in2->m_flMatVal[0][1] * in1->m_flMatVal[3][0]))
                                + (float)(in1->m_flMatVal[3][2] * in2->m_flMatVal[2][1]))
                        + (float)(in1->m_flMatVal[3][3] * in2->m_flMatVal[3][1]);
  out->m_flMatVal[3][2] = (float)((float)((float)(in1->m_flMatVal[3][1] * in2->m_flMatVal[1][2])
                                        + (float)(in1->m_flMatVal[3][0] * in2->m_flMatVal[0][2]))
                                + (float)(in1->m_flMatVal[3][2] * in2->m_flMatVal[2][2]))
                        + (float)(in2->m_flMatVal[3][2] * in1->m_flMatVal[3][3]);
  out->m_flMatVal[3][3] = (float)((float)((float)(in2->m_flMatVal[1][3] * in1->m_flMatVal[3][1])
                                        + (float)(in2->m_flMatVal[0][3] * in1->m_flMatVal[3][0]))
                                + (float)(in1->m_flMatVal[3][2] * in2->m_flMatVal[2][3]))
                        + (float)(in1->m_flMatVal[3][3] * in2->m_flMatVal[3][3]);
}

//------------------------------------------------------------------------------
// Address: 0x00405200
// Name: void M_AngleMatrix(class RadianEuler const __near &,class Vector const __near &,struct M_matrix4x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl M_AngleMatrix(const RadianEuler *angles, const Vector *position, M_matrix4x4_t *matrix)
{
  _BYTE v4[68]; // [esp+0h] [ebp-118h] OVERLAPPED BYREF
  M_matrix4x4_t my; // [esp+44h] [ebp-D4h] BYREF
  M_matrix4x4_t mx; // [esp+84h] [ebp-94h] BYREF
  M_matrix4x4_t temp1; // [esp+C4h] [ebp-54h] BYREF
  unsigned int sx; // [esp+104h] [ebp-14h]
  unsigned int cy; // [esp+108h] [ebp-10h]
  unsigned int sy; // [esp+10Ch] [ebp-Ch]
  unsigned int v11; // [esp+110h] [ebp-8h]
  float sz; // [esp+114h] [ebp-4h]
  float anglesa; // [esp+120h] [ebp+8h]
  float anglesb; // [esp+120h] [ebp+8h]
  float anglesc; // [esp+120h] [ebp+8h]

  anglesa = angles->x;
  __libm_sse2_sin(x: *(long double *)v4);
  sx = LODWORD(anglesa);
  __libm_sse2_cos(x: *(long double *)v4);
  v11 = LODWORD(anglesa);
  anglesb = angles->y;
  __libm_sse2_sin(x: *(long double *)v4);
  *(float *)&sy = anglesb;
  __libm_sse2_cos(x: *(long double *)v4);
  cy = LODWORD(anglesb);
  anglesc = angles->z;
  __libm_sse2_sin(x: *(long double *)v4);
  sz = anglesc;
  __libm_sse2_cos(x: *(long double *)v4);
  *(_QWORD *)&mx.m_flMatVal[0][0] = 1065353216;
  memset(&mx.m_flMatVal[0][2], 0, 12);
  mx.m_flMatVal[2][0] = 0.0;
  *(_QWORD *)&mx.m_flMatVal[3][0] = 0;
  *(_QWORD *)&mx.m_flMatVal[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&my.m_flMatVal[1][0] = 0x3F80000000000000LL;
  *(_QWORD *)&my.m_flMatVal[1][2] = 0;
  *(_QWORD *)&my.m_flMatVal[3][0] = 0;
  *(_QWORD *)&my.m_flMatVal[3][2] = 0x3F80000000000000LL;
  *(_DWORD *)&v4[16] = 0;
  memset(&v4[32], 0, 12);
  *(_QWORD *)&v4[44] = 1065353216;
  *(_QWORD *)&v4[52] = 0;
  *(_QWORD *)&v4[60] = 0x3F80000000000000LL;
  *(_QWORD *)&temp1.m_flMatVal[0][0] = 1065353216;
  *(_QWORD *)&temp1.m_flMatVal[0][2] = 0;
  *(_QWORD *)&temp1.m_flMatVal[1][0] = 0x3F80000000000000LL;
  memset(&temp1.m_flMatVal[1][2], 0, 16);
  *(_QWORD *)&temp1.m_flMatVal[3][0] = 0;
  *(_QWORD *)&temp1.m_flMatVal[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&mx.m_flMatVal[1][2] = sx;
  *(_QWORD *)&temp1.m_flMatVal[2][2] = 1065353216;
  LODWORD(mx.m_flMatVal[2][1]) = sx ^ 0x80000000;
  *(_QWORD *)&my.m_flMatVal[2][0] = sy;
  LODWORD(mx.m_flMatVal[1][1]) = v11;
  *(_QWORD *)&mx.m_flMatVal[2][2] = v11;
  *(_QWORD *)&v4[8] = LODWORD(anglesc);
  *(_QWORD *)&my.m_flMatVal[0][0] = cy;
  *(_QWORD *)&my.m_flMatVal[0][2] = COERCE_UNSIGNED_INT(-*(float *)&sy);
  *(_QWORD *)&my.m_flMatVal[2][2] = cy;
  *(float *)&v4[4] = anglesc;
  *(float *)&v4[20] = -anglesc;
  *(_QWORD *)&v4[24] = LODWORD(anglesc);
  M_ConcatTransforms(in1: &mx, in2: &my, out: &temp1);
  M_ConcatTransforms(in1: &temp1, in2: (const M_matrix4x4_t *)&v4[4], out: matrix);
  *(Vector *)&matrix->m_flMatVal[3][0] = *position;
}

//------------------------------------------------------------------------------
// Address: 0x004054D0
// Name: struct s_iksolve_t __near * New_IKSolve(void)
// Source: json
//------------------------------------------------------------------------------
s_iksolve_t *__cdecl New_IKSolve()
{
  s_iksolve_t *result; // eax

  k_memtotal += 2076;
  result = (s_iksolve_t *)calloc(count: 1u, size: 0x81Cu);
  result->reverseSolve = 0;
  result->extremityScale = 1.0;
  *(_QWORD *)&result->limbRootOffsetScale.y = 0;
  result->limbRootOffsetScale.x = 0.0;
  result->doRelativeLock = 0;
  result->relativeLockScale = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405530
// Name: void Set_DefaultTemplate(struct s_template_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Set_DefaultTemplate(s_template_t *pTemplate)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  float toeFloorZ; // xmm0_4
  unsigned __int8 *v6; // eax
  float v7; // xmm0_4
  unsigned __int8 *v8; // eax

  pTemplate->numJointScales = 0;
  strcpy(pTemplate->rootScaleJoint, "ValveBiped.Bip01_L_Foot");
  pTemplate->rootScaleAmount = 1.0;
  pTemplate->numIKSolves = 4;
  k_memtotal += 2076;
  v1 = calloc(count: 1u, size: 0x81Cu);
  *((_DWORD *)v1 + 256) = 0;
  *((_DWORD *)v1 + 257) = 1065353216;
  *(_QWORD *)(v1 + 1036) = 0;
  *((_DWORD *)v1 + 258) = 0;
  *((_DWORD *)v1 + 261) = 0;
  *((_DWORD *)v1 + 518) = 1065353216;
  pTemplate->ikSolves[0] = (s_iksolve_t *)v1;
  k_memtotal += 2076;
  v2 = calloc(count: 1u, size: 0x81Cu);
  *((_DWORD *)v2 + 256) = 0;
  *((_DWORD *)v2 + 257) = 1065353216;
  *(_QWORD *)(v2 + 1036) = 0;
  *((_DWORD *)v2 + 258) = 0;
  *((_DWORD *)v2 + 261) = 0;
  *((_DWORD *)v2 + 518) = 1065353216;
  pTemplate->ikSolves[1] = (s_iksolve_t *)v2;
  k_memtotal += 2076;
  v3 = calloc(count: 1u, size: 0x81Cu);
  *((_DWORD *)v3 + 256) = 0;
  *((_DWORD *)v3 + 257) = 1065353216;
  *(_QWORD *)(v3 + 1036) = 0;
  *((_DWORD *)v3 + 258) = 0;
  *((_DWORD *)v3 + 261) = 0;
  *((_DWORD *)v3 + 518) = 1065353216;
  pTemplate->ikSolves[2] = (s_iksolve_t *)v3;
  k_memtotal += 2076;
  v4 = calloc(count: 1u, size: 0x81Cu);
  *((_DWORD *)v4 + 256) = 0;
  *((_DWORD *)v4 + 257) = 1065353216;
  *((_DWORD *)v4 + 260) = 0;
  *((_DWORD *)v4 + 259) = 0;
  *((_DWORD *)v4 + 258) = 0;
  *((_DWORD *)v4 + 261) = 0;
  *((_DWORD *)v4 + 518) = 1065353216;
  toeFloorZ = pTemplate->toeFloorZ;
  pTemplate->ikSolves[3] = (s_iksolve_t *)v4;
  pTemplate->numPlaneConstraints = 2;
  k_memtotal += 1032;
  v6 = calloc(count: 1u, size: 0x408u);
  *((float *)v6 + 256) = toeFloorZ;
  *((_DWORD *)v6 + 257) = 2;
  pTemplate->planeConstraints[0] = (s_planeConstraint_t *)v6;
  strcpy((char *)v6, "ValveBiped.Bip01_L_Toe0");
  v7 = pTemplate->toeFloorZ;
  k_memtotal += 1032;
  v8 = calloc(count: 1u, size: 0x408u);
  *((_DWORD *)v8 + 257) = 2;
  *((float *)v8 + 256) = v7;
  pTemplate->planeConstraints[1] = (s_planeConstraint_t *)v8;
  strcpy((char *)v8, "ValveBiped.Bip01_R_Toe0");
  strcpy(pTemplate->ikSolves[0]->jointNameString, "ValveBiped.Bip01_L_Foot");
  pTemplate->ikSolves[0]->reverseSolve = 0;
  pTemplate->ikSolves[0]->extremityScale = 1.0;
  pTemplate->ikSolves[0]->limbRootOffsetScale.x = 1.0;
  pTemplate->ikSolves[0]->limbRootOffsetScale.y = 1.0;
  pTemplate->ikSolves[0]->limbRootOffsetScale.z = 0.0;
  strcpy(pTemplate->ikSolves[1]->jointNameString, "ValveBiped.Bip01_R_Foot");
  pTemplate->ikSolves[1]->reverseSolve = 0;
  pTemplate->ikSolves[1]->extremityScale = 1.0;
  pTemplate->ikSolves[1]->limbRootOffsetScale.x = 1.0;
  pTemplate->ikSolves[1]->limbRootOffsetScale.y = 1.0;
  pTemplate->ikSolves[1]->limbRootOffsetScale.z = 0.0;
  strcpy(pTemplate->ikSolves[2]->jointNameString, "ValveBiped.Bip01_R_Hand");
  pTemplate->ikSolves[2]->reverseSolve = 1;
  pTemplate->ikSolves[2]->extremityScale = 1.0;
  pTemplate->ikSolves[2]->limbRootOffsetScale.x = 0.0;
  pTemplate->ikSolves[2]->limbRootOffsetScale.y = 0.0;
  pTemplate->ikSolves[2]->limbRootOffsetScale.z = 1.0;
  strcpy(pTemplate->ikSolves[3]->jointNameString, "ValveBiped.Bip01_L_Hand");
  pTemplate->ikSolves[3]->reverseSolve = 1;
  pTemplate->ikSolves[3]->extremityScale = 1.0;
  pTemplate->ikSolves[3]->limbRootOffsetScale.x = 0.0;
  pTemplate->ikSolves[3]->limbRootOffsetScale.y = 0.0;
  pTemplate->ikSolves[3]->limbRootOffsetScale.z = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00405980
// Name: int checkCommand(char __near *,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl checkCommand(char *str, char *cmd, int numOptions, int numSplit)
{
  if ( strcmp(str, cmd) == 0 )
  {
    if ( numOptions <= numSplit )
      return 1;
    printf(
      format: "Error: Number or argument mismatch in template file cmd %s, requires %i, found %i\n",
      cmd,
      numOptions,
      numSplit);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004059E0
// Name: struct s_template_t __near * Load_Template(char __near *)
// Source: json
//------------------------------------------------------------------------------
s_template_t *__cdecl Load_Template(char *name)
{
  unsigned __int8 *v1; // esi
  s_template_t *result; // eax
  _BYTE *v3; // eax
  char **v4; // edi
  char **v5; // ebx
  char *i; // eax
  char *v7; // ebx
  int v8; // eax
  int v9; // edi
  char *v10; // edi
  _BYTE *v11; // edx
  char *v12; // ecx
  char v13; // al
  char *v14; // edi
  int v15; // xmm0_4
  unsigned __int8 *v16; // eax
  _BYTE *v17; // edx
  char *v18; // ecx
  char v19; // al
  const char *v20; // edi
  const char *v21; // edi
  const char *v22; // ebx
  int v23; // edi
  int v24; // edi
  int v25; // edi
  const char *v26; // edi
  char *v27; // edi
  char *v28; // edx
  _BYTE *v29; // eax
  char v30; // cl
  const char *v31; // edi
  const char *v32; // edi
  const char *v33; // ebx
  char *v34; // edi
  _BYTE *v35; // edx
  char *v36; // ecx
  char v37; // al
  const char *v38; // edi
  char *str[128]; // [esp+8h] [ebp-208h] BYREF
  int v40; // [esp+208h] [ebp-8h]
  char sep[4]; // [esp+20Ch] [ebp-4h] BYREF

  k_memtotal += 2588;
  v1 = calloc(count: 1u, size: 0xA1Cu);
  *((_DWORD *)v1 + 256) = 1065353216;
  *((_DWORD *)v1 + 257) = 0;
  *((_DWORD *)v1 + 386) = 0;
  *((_DWORD *)v1 + 644) = 1077106818;
  *((_DWORD *)v1 + 515) = 0;
  *((_DWORD *)v1 + 645) = 0;
  *((_DWORD *)v1 + 646) = 1065353216;
  result = (s_template_t *)OpenGlobalFile(src: name);
  if ( result != nullptr )
  {
    g_iLinecount = 0;
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) != nullptr )
    {
      ++g_iLinecount;
      if ( g_szLine[0] != 35 )
      {
        strrchr(string: (unsigned __int8 *)g_szLine, chr: 0xAu);
        if ( v3 != nullptr )
          *v3 = 0;
        v4 = str;
        strcpy(sep, " ");
        v5 = str;
        for ( i = strtok(string: g_szLine, control: sep); i != nullptr; i = strtok(string: nullptr, control: sep) )
          *v5++ = i;
        *v5 = nullptr;
        v7 = str[0];
        v8 = 0;
        if ( str[0] != nullptr )
        {
          do
          {
            ++v4;
            ++v8;
          }
          while ( *v4 != nullptr );
          if ( v8 >= 1 && *str[0] != 10 )
          {
            v9 = v8 - 1;
            if ( checkCommand(str: str[0], cmd: "twoJointIKSolve", numOptions: 1, numSplit: v8 - 1) != 0 )
            {
              v10 = str[1];
              printf(format: "\nCreating two joint IK solve %s\n", str[1]);
              *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1032] = New_IKSolve();
              v11 = *(_BYTE **)&v1[4 * *((_DWORD *)v1 + 257) + 1032];
              v12 = v10;
              do
              {
                v13 = *v12;
                *v11++ = *v12++;
              }
              while ( v13 != 0 );
              ++*((_DWORD *)v1 + 257);
            }
            else if ( checkCommand(str: v7, cmd: "oneJointPlaneConstraint", numOptions: 1, numSplit: v9) != 0 )
            {
              v14 = str[1];
              printf(format: "\nCreating one joint plane constraint %s\n", str[1]);
              v15 = *((_DWORD *)v1 + 644);
              k_memtotal += 1032;
              v40 = v15;
              v16 = calloc(count: 1u, size: 0x408u);
              *((_DWORD *)v16 + 256) = v40;
              *((_DWORD *)v16 + 257) = 2;
              *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 515) + 2064] = v16;
              v17 = *(_BYTE **)&v1[4 * *((_DWORD *)v1 + 515) + 2064];
              v18 = v14;
              do
              {
                v19 = *v18;
                *v17++ = *v18++;
              }
              while ( v19 != 0 );
              ++*((_DWORD *)v1 + 515);
            }
            else if ( checkCommand(str: v7, cmd: "reverseSolve", numOptions: 1, numSplit: v9) != 0 )
            {
              v20 = str[1];
              printf(format: "reverseSolve: %s\n", str[1]);
              *(_DWORD *)(*(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028] + 1024) = atoi(nptr: v20);
            }
            else if ( checkCommand(str: v7, cmd: "extremityScale", numOptions: 1, numSplit: v9) != 0 )
            {
              v21 = str[1];
              printf(format: "extremityScale: %s\n", str[1]);
              *(float *)(*(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028] + 1028) = atof(nptr: v21);
            }
            else if ( checkCommand(str: v7, cmd: "limbRootOffsetScale", numOptions: 3, numSplit: v9) != 0 )
            {
              v22 = str[3];
              printf(format: "limbRootOffsetScale: %s %s %s\n", str[1], str[2], str[3]);
              v23 = *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028];
              *(float *)(v23 + 1032) = atof(nptr: str[1]);
              v24 = *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028];
              *(float *)(v24 + 1036) = atof(nptr: str[2]);
              v25 = *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028];
              *(float *)(v25 + 1040) = atof(nptr: v22);
            }
            else if ( checkCommand(str: v7, cmd: "toeFloorZ", numOptions: 1, numSplit: v9) != 0 )
            {
              v26 = str[1];
              printf(format: "toeFloorZ: %s\n", str[1]);
              *((float *)v1 + 644) = atof(nptr: v26);
            }
            else if ( checkCommand(str: v7, cmd: "relativeLock", numOptions: 2, numSplit: v9) != 0 )
            {
              v27 = str[1];
              printf(format: "relativeLock: %s\n", str[1]);
              *(_DWORD *)(*(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028] + 1044) = 1;
              v28 = v27;
              v29 = (_BYTE *)(*(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028] + 1048);
              do
              {
                v30 = *v28;
                *v29++ = *v28++;
              }
              while ( v30 != 0 );
              *(float *)(*(_DWORD *)&v1[4 * *((_DWORD *)v1 + 257) + 1028] + 2072) = atof(nptr: str[2]);
            }
            else if ( checkCommand(str: v7, cmd: "rootScaleJoint", numOptions: 1, numSplit: v9) != 0 )
            {
              v31 = str[1];
              printf(format: "\nrootScaleJoint: %s\n", str[1]);
              strcpy((char *)v1, v31);
            }
            else if ( checkCommand(str: v7, cmd: "rootScaleAmount", numOptions: 1, numSplit: v9) != 0 )
            {
              v32 = str[1];
              printf(format: "rootScaleAmount: %s\n", str[1]);
              *((float *)v1 + 256) = atof(nptr: v32);
            }
            else if ( checkCommand(str: v7, cmd: "jointScale", numOptions: 2, numSplit: v9) != 0 )
            {
              v33 = str[2];
              v34 = str[1];
              printf(format: "\nCreating joint scale %s of %s\n", str[1], str[2]);
              *(_DWORD *)&v1[4 * *((_DWORD *)v1 + 386) + 1548] = kalloc(num: 1u, size: 0x404u);
              v35 = *(_BYTE **)&v1[4 * *((_DWORD *)v1 + 386) + 1548];
              v36 = v34;
              do
              {
                v37 = *v36;
                *v35++ = *v36++;
              }
              while ( v37 != 0 );
              *(float *)(*(_DWORD *)&v1[4 * (*((_DWORD *)v1 + 386))++ + 1548] + 1024) = atof(nptr: v33);
            }
            else if ( checkCommand(str: v7, cmd: "skeletonScale", numOptions: 2, numSplit: v9) != 0 )
            {
              v38 = str[1];
              printf(format: "\nCreating skeleton scale of %s\n", str[1]);
              *((_DWORD *)v1 + 645) = 1;
              *((float *)v1 + 646) = atof(nptr: v38);
            }
            else
            {
              MdlWarning(fmt: "unknown studio command\n");
            }
          }
        }
      }
    }
    fclose(stream: g_fpInput);
    return (s_template_t *)v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405F90
// Name: int GetNodeIndex(struct s_source_t __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetNodeIndex(s_source_t *psource, char *nodeName)
{
  int numbones; // edi
  int result; // eax
  s_node_t *i; // esi

  numbones = psource->numbones;
  result = 0;
  if ( numbones <= 0 )
    return -1;
  for ( i = psource->localBone; strcmp(nodeName, i->name) != 0; ++i )
  {
    if ( ++result >= numbones )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406000
// Name: void CatBonePath(int __near *,struct s_bone_t __near *,struct M_matrix4x4_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CatBonePath(int *indexPath, s_bone_t *boneArray, M_matrix4x4_t *resultMatrix, int rootOffset)
{
  int *v4; // ecx
  int v5; // ebx
  int *i; // eax
  int v7; // ebx
  int v8; // eax
  M_matrix4x4_t tempCum; // [esp+4h] [ebp-80h] BYREF
  M_matrix4x4_t thisMatrix; // [esp+44h] [ebp-40h] BYREF

  v4 = indexPath;
  v5 = 0;
  for ( i = indexPath; *i != -1; ++v5 )
    ++i;
  v7 = v5 - rootOffset - 1;
  if ( v7 > -1 )
  {
    while ( 1 )
    {
      v8 = v4[v7];
      *(_QWORD *)&thisMatrix.m_flMatVal[0][0] = 1065353216;
      *(_QWORD *)&thisMatrix.m_flMatVal[0][2] = 0;
      *(_QWORD *)&thisMatrix.m_flMatVal[1][0] = 0x3F80000000000000LL;
      memset(&thisMatrix.m_flMatVal[1][2], 0, 16);
      *(_QWORD *)&thisMatrix.m_flMatVal[2][2] = 1065353216;
      *(_QWORD *)&thisMatrix.m_flMatVal[3][0] = 0;
      *(_QWORD *)&thisMatrix.m_flMatVal[3][2] = 0x3F80000000000000LL;
      M_AngleMatrix(angles: &boneArray[v8].rot, position: &boneArray[v8].pos, matrix: &thisMatrix);
      tempCum = *resultMatrix;
      M_ConcatTransforms(in1: &thisMatrix, in2: &tempCum, out: resultMatrix);
      if ( --v7 <= -1 )
        break;
      v4 = indexPath;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004060E0
// Name: void ScaleJoints(struct s_source_t __near *,struct s_jointScale_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScaleJoints(s_source_t *pSkeleton, s_jointScale_t *jointScale)
{
  s_source_t *v2; // ecx
  int numframes; // eax
  int numbones; // eax
  float *v5; // ebx
  float scale; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  char v9[132]; // [esp+0h] [ebp-94h] BYREF
  int i; // [esp+84h] [ebp-10h]
  int j; // [esp+88h] [ebp-Ch]
  s_bone_t **rawanim; // [esp+8Ch] [ebp-8h]
  s_node_t *localBone; // [esp+90h] [ebp-4h]

  v2 = pSkeleton;
  numframes = pSkeleton->numframes;
  if ( numframes > 0 )
  {
    rawanim = pSkeleton->rawanim;
    for ( i = numframes; i != 0; --i )
    {
      numbones = v2->numbones;
      if ( numbones > 0 )
      {
        v5 = (float *)*rawanim;
        localBone = v2->localBone;
        for ( j = numbones; j != 0; --j )
        {
          qmemcpy(v9, localBone, sizeof(v9));
          if ( strcmp(jointScale->jointNameString, v9) == 0 )
          {
            scale = jointScale->scale;
            v7 = v5[1] * scale;
            v8 = v5[2] * scale;
            *v5 = *v5 * scale;
            v5[1] = v7;
            v5[2] = v8;
          }
          ++localBone;
          v5 += 6;
        }
        v2 = pSkeleton;
      }
      ++rawanim;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004061E0
// Name: void ScaleSkeleton(struct s_source_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScaleSkeleton(s_source_t *pSkeleton, float scale)
{
  s_source_t *v2; // ecx
  s_bone_t **rawanim; // ebx
  int numbones; // esi
  int v5; // edi
  float *p_z; // eax
  float *v7; // ecx
  unsigned int v8; // edx
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *p_x; // eax
  int v18; // esi
  float v19; // xmm2_4
  float v20; // xmm3_4
  int numframes; // [esp+0h] [ebp-4h]

  v2 = pSkeleton;
  if ( pSkeleton->numframes > 0 )
  {
    rawanim = pSkeleton->rawanim;
    numframes = pSkeleton->numframes;
    do
    {
      numbones = v2->numbones;
      v5 = 0;
      if ( numbones >= 4 )
      {
        p_z = &(*rawanim)->pos.z;
        v7 = &(*rawanim)[1].pos.z;
        v8 = ((unsigned int)(numbones - 4) >> 2) + 1;
        v5 = 4 * v8;
        do
        {
          v9 = *(p_z - 1);
          v10 = *p_z;
          *(p_z - 2) = *(p_z - 2) * scale;
          *(p_z - 1) = v9 * scale;
          *p_z = v10 * scale;
          v11 = *v7 * scale;
          v12 = scale * *(v7 - 1);
          p_z[4] = p_z[4] * scale;
          *(v7 - 1) = v12;
          *v7 = v11;
          v13 = v7[5];
          v14 = v7[6];
          p_z[10] = p_z[10] * scale;
          v7[5] = v13 * scale;
          v7[6] = v14 * scale;
          v15 = v7[11];
          v16 = scale * v7[12];
          p_z[16] = scale * p_z[16];
          v7[11] = v15 * scale;
          v7[12] = v16;
          p_z += 24;
          v7 += 24;
          --v8;
        }
        while ( v8 != 0 );
        v2 = pSkeleton;
      }
      if ( v5 < numbones )
      {
        p_x = &(*rawanim)[v5].pos.x;
        v18 = numbones - v5;
        do
        {
          v19 = p_x[1] * scale;
          v20 = p_x[2] * scale;
          *p_x = *p_x * scale;
          p_x[1] = v19;
          p_x[2] = v20;
          p_x += 6;
          --v18;
        }
        while ( v18 != 0 );
      }
      ++rawanim;
      --numframes;
    }
    while ( numframes != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406350
// Name: void CombineSkeletonAnimation(struct s_source_t __near *,struct s_source_t __near *,struct s_bone_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CombineSkeletonAnimation(s_source_t *pSkeleton, s_source_t *pAnimation, s_bone_t **ppAnim)
{
  s_source_t *v3; // edi
  int numframes; // eax
  int numbones; // esi
  unsigned __int8 *v6; // eax
  int v7; // edx
  int v8; // ebx
  s_bone_t *v9; // eax
  __int64 v10; // xmm0_8
  s_bone_t *v11; // eax
  __int64 v12; // xmm0_8
  s_bone_t *v13; // eax
  s_bone_t *v14; // eax
  float v15; // xmm0_4
  float v16; // ecx
  _DWORD v17[33]; // [esp+4h] [ebp-CCh] BYREF
  __int64 v18; // [esp+88h] [ebp-48h]
  __int64 v19; // [esp+90h] [ebp-40h]
  __int64 v20; // [esp+98h] [ebp-38h]
  __int64 v21; // [esp+A0h] [ebp-30h]
  __int128 v22; // [esp+A8h] [ebp-28h]
  int v23; // [esp+B8h] [ebp-18h]
  int v24; // [esp+BCh] [ebp-14h]
  int i; // [esp+C0h] [ebp-10h]
  s_bone_t **rawanim; // [esp+C4h] [ebp-Ch]
  s_node_t *localBone; // [esp+C8h] [ebp-8h]
  s_bone_t **v28; // [esp+CCh] [ebp-4h]

  v3 = pAnimation;
  numframes = pAnimation->numframes;
  if ( numframes <= 0 )
    return;
  v28 = ppAnim;
  rawanim = pAnimation->rawanim;
  for ( i = numframes; i != 0; --i )
  {
    numbones = v3->numbones;
    k_memtotal += 24 * numbones;
    v23 = numbones;
    v6 = calloc(count: 1u, size: 24 * numbones);
    v7 = 0;
    *v28 = (s_bone_t *)v6;
    v24 = 0;
    if ( numbones <= 0 )
      goto LABEL_13;
    v8 = 0;
    localBone = v3->localBone;
    do
    {
      v9 = *rawanim;
      v21 = *(_QWORD *)&(*rawanim)[v8].pos.x;
      v10 = *(_QWORD *)&v9[v8].pos.z;
      qmemcpy(v17, localBone, sizeof(v17));
      *(_QWORD *)&v22 = v10;
      *((_QWORD *)&v22 + 1) = *(_QWORD *)&v9[v8].rot.y;
      if ( v17[32] > -1 )
      {
        if ( v7 < pSkeleton->numbones )
        {
          v11 = pSkeleton->rawanim[0];
          v18 = *(_QWORD *)&v11[v8].pos.x;
          v19 = *(_QWORD *)&v11[v8].pos.z;
          v12 = *(_QWORD *)&v11[v8].rot.y;
          v13 = *v28;
          v20 = v12;
          v14 = &v13[v8];
          *(_QWORD *)&v14->pos.x = v18;
          v15 = *(float *)&v19;
          goto LABEL_11;
        }
        if ( !g_bGaveMissingBoneWarning )
        {
          g_bGaveMissingBoneWarning = true;
          _Warning(a1: "Warning: Target skeleton has less bones than source animation. Reverting to source data for extra bones.\n");
          v7 = v24;
        }
      }
      v14 = &(*v28)[v8];
      *(_QWORD *)&v14->pos.x = v21;
      v15 = *(float *)&v22;
LABEL_11:
      v16 = *((float *)&v22 + 3);
      ++localBone;
      v14->pos.z = v15;
      ++v7;
      ++v8;
      *(_QWORD *)&v14->rot.x = *(_QWORD *)((char *)&v22 + 4);
      v14->rot.z = v16;
      v24 = v7;
    }
    while ( v7 < v23 );
    v3 = pAnimation;
LABEL_13:
    ++rawanim;
    ++v28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064E0
// Name: void Grab_Vertexanimation(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Vertexanimation(s_source_t *psource)
{
  int v1; // ebx
  unsigned int v2; // esi
  int v3; // ecx
  float x; // xmm0_4
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  int startframe; // eax
  char cmd[1024]; // [esp+Ch] [ebp-41Ch] BYREF
  Vector normal; // [esp+40Ch] [ebp-1Ch] BYREF
  Vector pos; // [esp+418h] [ebp-10h] BYREF
  int index; // [esp+424h] [ebp-4h] BYREF

  v1 = -1;
  v2 = 0;
  if ( (_S1_0 & 1) == 0 )
    _S1_0 |= 1u;
  if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
LABEL_19:
    MdlError(fmt: "unexpected EOF: %s\n", psource->filename);
  while ( 1 )
  {
    ++g_iLinecount;
    if ( sscanf(
           string: g_szLine,
           format: "%d %f %f %f %f %f %f",
           &index,
           &pos,
           &pos.y,
           &pos.z,
           &normal,
           &normal.y,
           &normal.z) != 7 )
      break;
    if ( psource->startframe < 0 )
      MdlError(fmt: "Missing frame start(%d) : %s", g_iLinecount, g_szLine);
    if ( v1 < 0 )
      MdlError(fmt: "VTA Frame Sync (%d) : %s", g_iLinecount, g_szLine);
    v3 = index;
    x = pos.x;
    v5 = 9 * v2;
    tmpvanim[v5 / 9].vertex = index;
    *(float *)&dword_DC060C[v5] = x;
    dword_DC0610[v5] = LODWORD(pos.y);
    dword_DC0614[v5] = LODWORD(pos.z);
    dword_DC0618[v5] = LODWORD(normal.x);
    dword_DC061C[v5] = LODWORD(normal.y);
    dword_DC0620[v5] = LODWORD(normal.z);
    ++v2;
    if ( v3 >= psource->numvertices )
      psource->numvertices = v3 + 1;
LABEL_18:
    if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      goto LABEL_19;
  }
  if ( v2 != 0 )
  {
    psource->numvanims[v1] = v2;
    k_memtotal += 36 * v2;
    v6 = calloc(count: v2, size: 0x24u);
    psource->vanim[v1] = (s_vertanim_t *)v6;
    memcpy(dst: v6, src: (unsigned __int8 *)tmpvanim, count: 36 * v2);
  }
  else if ( v1 > 0 )
  {
    psource->numvanims[v1] = 0;
  }
  if ( sscanf(string: g_szLine, format: "%1023s %d", cmd, &index) == 0 )
    MdlError(fmt: "MdlError(%d) : %s", g_iLinecount, g_szLine);
  if ( strcmp(cmd, "time") == 0 )
  {
    startframe = psource->startframe;
    v2 = 0;
    if ( index < startframe )
      MdlError(fmt: "Frame MdlError(%d) : %s", g_iLinecount, g_szLine);
    if ( index > psource->endframe )
      MdlError(fmt: "Frame MdlError(%d) : %s", g_iLinecount, g_szLine);
    v1 = index - startframe;
    goto LABEL_18;
  }
  if ( strcmp(cmd, "end") != 0 )
    MdlError(fmt: "MdlError(%d) : %s", g_iLinecount, g_szLine);
  psource->numframes = psource->endframe - psource->startframe + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004067C0
// Name: void ParseFaceData(struct s_source_t __near *,int,struct s_face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFaceData(s_source_t *psource, int material, s_face_t *pFace)
{
  int v3; // edi
  unsigned int v4; // esi
  int i; // edi
  int j; // edi
  const char *v7; // eax
  unsigned int v8; // esi
  const char *v9; // eax
  int v10; // eax
  bool v11; // zf
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  float *v15; // edx
  double v16; // st7
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  float weights; // [esp+Ch] [ebp-103Ch] BYREF
  char v22; // [esp+10h] [ebp-1038h] BYREF
  char v23; // [esp+14h] [ebp-1034h] BYREF
  char v24; // [esp+18h] [ebp-1030h] BYREF
  int bones; // [esp+80Ch] [ebp-83Ch] BYREF
  char v26; // [esp+810h] [ebp-838h] BYREF
  char v27; // [esp+814h] [ebp-834h] BYREF
  char v28; // [esp+818h] [ebp-830h] BYREF
  unsigned int v29; // [esp+100Ch] [ebp-3Ch]
  unsigned int v30; // [esp+1010h] [ebp-38h]
  unsigned int v31; // [esp+1014h] [ebp-34h]
  Vector normal; // [esp+1018h] [ebp-30h] BYREF
  int v33; // [esp+1024h] [ebp-24h]
  int v34; // [esp+1028h] [ebp-20h]
  int v35; // [esp+102Ch] [ebp-1Ch] BYREF
  Vector2D v36; // [esp+1030h] [ebp-18h] BYREF
  Vector vertex; // [esp+1038h] [ebp-10h] BYREF
  int iCount; // [esp+1044h] [ebp-4h] BYREF

  v3 = 0;
  v34 = 0;
  do
  {
    v4 = 0;
    memset(dst: (unsigned __int8 *)g_szLine, value: 0, count: sizeof(g_szLine));
    if ( fgets(string: g_szLine, count: 4096, str: g_fpInput) == nullptr )
      MdlError(fmt: "%s: error on g_szLine %d: %s", g_szFilename, g_iLinecount, g_szLine);
    ++g_iLinecount;
    iCount = 0;
    v33 = sscanf(
            string: g_szLine,
            format: "%d %f %f %f %f %f %f %f %f %d %d %f %d %f %d %f %d %f",
            &v35,
            &vertex,
            &vertex.y,
            &vertex.z,
            &normal,
            &normal.y,
            &normal.z,
            &v36,
            &v36.y,
            &iCount,
            &bones,
            &weights,
            &v26,
            &v22,
            &v27,
            &v23,
            &v28,
            &v24);
    if ( v33 >= 9 )
    {
      if ( v35 < 0 || v35 >= psource->numbones )
        MdlError(fmt: "bogus bone index\n%d %s :\n%s", g_iLinecount, g_szFilename, g_szLine);
      vertex.x = vertex.x * g_currentscale;
      vertex.y = vertex.y * g_currentscale;
      vertex.z = vertex.z * g_currentscale;
      if ( iCount > 4 )
      {
        for ( i = 18; i != 0; --i )
        {
          for ( ; g_szLine[v4] == 32; ++v4 )
            ;
          v4 += strlen(strtok(string: &g_szLine[v4], control: " ")) + 1;
        }
        for ( j = 4; j < iCount; *(&weights + j++) = atof(nptr: v9) )
        {
          if ( j >= 512 )
            break;
          for ( ; g_szLine[v4] == 32; ++v4 )
            ;
          v7 = strtok(string: &g_szLine[v4], control: " ");
          v8 = v4 + strlen(v7) + 1;
          *(&bones + j) = atoi(nptr: v7);
          v9 = strtok(string: &g_szLine[v8], control: " ");
          v4 = v8 + strlen(v9) + 1;
        }
      }
      v36.y = 1.0 - v36.y;
      v10 = lookup_index(psource, material, &vertex, &normal, texcoord: v36);
      v3 = v34;
      v11 = v33 == 9;
      v12 = v10;
      *(&v29 + v34) = v10;
      if ( v11 || iCount == 0 )
      {
        v17 = v35;
        v18 = 7 * v10;
        g_bone[v18 / 7].numbones = 1;
        dword_70E8D4[v18] = v17;
        dword_70E8E0[v18] = 1065353216;
      }
      else
      {
        v13 = SortAndBalanceBones(iCount, iMaxCount: 3, (char *)&bones, &weights);
        v14 = 0;
        iCount = v13;
        g_bone[v12].numbones = v13;
        if ( v13 > 0 )
        {
          v15 = (float *)&dword_70E8E0[7 * v12];
          do
          {
            v16 = *(&weights + v14);
            *((_DWORD *)v15 - 3) = *(&bones + v14);
            *v15 = v16;
            ++v14;
            ++v15;
          }
          while ( v14 < v13 );
        }
      }
    }
    v34 = ++v3;
  }
  while ( v3 < 3 );
  v19 = v31;
  pFace->a = v29;
  v20 = v30;
  pFace->b = v30;
  pFace->c = v19;
  if ( flip_triangles != 0 )
  {
    pFace->b = v19;
    pFace->c = v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B30
// Name: struct s_source_t __near * MotionMap(struct s_source_t __near *,struct s_source_t __near *,struct s_template_t __near *)
// Source: json
//------------------------------------------------------------------------------
s_source_t *__usercall MotionMap@<eax>(
        int a1@<ebp>,
        double a2@<esi:edi>,
        s_source_t *pSource,
        s_source_t *pTarget,
        s_template_t *pTemplate)
{
  void *v5; // esp
  s_source_t *v6; // edi
  int v7; // esi
  int NodeIndex; // eax
  int *v9; // ecx
  s_jointScale_t **v10; // edx
  float v11; // xmm0_4
  __int64 v12; // xmm0_8
  int numframes; // eax
  bool v14; // cc
  char *v15; // edi
  int v16; // eax
  s_jointScale_t **v17; // edi
  int *v18; // ecx
  int parent; // edx
  s_bone_t *v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  int v23; // edi
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  s_bone_t *v27; // ecx
  bool v28; // zf
  float v29; // xmm0_4
  int v30; // eax
  s_jointScale_t **v31; // edx
  int *v32; // ecx
  s_bone_t *v33; // edx
  float v34; // xmm0_4
  s_bone_t *v35; // ecx
  int v36; // edi
  s_bone_t *v37; // eax
  s_bone_t *v38; // eax
  float v39; // xmm5_4
  float v40; // edi
  float x; // xmm1_4
  __int128 v42; // xmm0
  float v43; // xmm4_4
  float v44; // xmm1_4
  float v45; // eax
  double v46; // xmm0_8
  float v47; // xmm0_4
  float v48; // xmm0_4
  double v49; // xmm0_8
  double v50; // xmm0_8
  double v51; // xmm0_8
  float v52; // xmm0_4
  double v53; // xmm0_8
  float v54; // xmm0_4
  double v55; // xmm0_8
  double v56; // xmm0_8
  double v57; // xmm0_8
  s_bone_t *v58; // eax
  float v59; // edx
  float v60; // xmm1_4
  int v61; // xmm0_4
  double v62; // xmm0_8
  double v63; // xmm0_8
  int v64; // eax
  float v65; // edx
  RadianEuler *v66; // edi
  float v67; // xmm1_4
  float v68; // xmm0_4
  double v69; // xmm0_8
  double v70; // xmm0_8
  double v71; // xmm0_8
  int v72; // ecx
  s_bone_t *v73; // edx
  int v74; // eax
  float v75; // edx
  s_bone_t *v76; // edx
  int v77; // eax
  s_bone_t *v78; // edi
  float v79; // xmm6_4
  char *v80; // edx
  s_bone_t *v81; // eax
  int v82; // ecx
  float v83; // xmm0_4
  float v84; // xmm2_4
  float v85; // xmm3_4
  float v86; // xmm0_4
  float v87; // xmm3_4
  float v88; // xmm4_4
  int v89; // ecx
  int *v90; // eax
  s_bone_t **v91; // edx
  float v92; // xmm0_4
  int v93; // eax
  int v94; // eax
  s_bone_t *v95; // edx
  float v96; // xmm1_4
  float v97; // xmm0_4
  float v98; // xmm2_4
  float v99; // xmm0_4
  double v100; // xmm0_8
  double v101; // xmm0_8
  double v102; // xmm0_8
  int p_rot; // eax
  float v104; // edx
  s_bone_t **v105; // eax
  s_bone_t *v106; // edx
  int v107; // ecx
  s_bone_t *v109; // [esp+4h] [ebp-7CC0h]
  s_bone_t *v110; // [esp+Ch] [ebp-7CB8h]
  s_bone_t *v111; // [esp+Ch] [ebp-7CB8h]
  s_bone_t *v112; // [esp+Ch] [ebp-7CB8h]
  s_bone_t *v113; // [esp+Ch] [ebp-7CB8h]
  s_bone_t *v114; // [esp+Ch] [ebp-7CB8h]
  int scale; // [esp+14h] [ebp-7CB0h]
  long double v116; // [esp+18h] [ebp-7CACh]
  long double v117; // [esp+18h] [ebp-7CACh]
  long double v118; // [esp+18h] [ebp-7CACh]
  long double v119; // [esp+18h] [ebp-7CACh]
  long double v120; // [esp+18h] [ebp-7CACh]
  long double v121; // [esp+18h] [ebp-7CACh]
  long double v122; // [esp+18h] [ebp-7CACh]
  long double v123; // [esp+18h] [ebp-7CACh]
  long double v124; // [esp+18h] [ebp-7CACh]
  long double v125; // [esp+18h] [ebp-7CACh]
  long double v126; // [esp+18h] [ebp-7CACh]
  long double v127; // [esp+18h] [ebp-7CACh]
  long double v128; // [esp+18h] [ebp-7CACh]
  long double v129; // [esp+18h] [ebp-7CACh]
  long double v130; // [esp+18h] [ebp-7CACh]
  long double v131; // [esp+18h] [ebp-7CACh]
  long double v132; // [esp+18h] [ebp-7CACh]
  long double v133; // [esp+18h] [ebp-7CACh]
  long double v134; // [esp+18h] [ebp-7CACh]
  long double v135; // [esp+18h] [ebp-7CACh]
  long double v136; // [esp+18h] [ebp-7CACh]
  long double v137; // [esp+18h] [ebp-7CACh]
  long double v138; // [esp+18h] [ebp-7CACh]
  long double v139; // [esp+20h] [ebp-7CA4h]
  long double v140; // [esp+20h] [ebp-7CA4h]
  long double v141; // [esp+20h] [ebp-7CA4h]
  long double v142; // [esp+20h] [ebp-7CA4h]
  long double v143; // [esp+20h] [ebp-7CA4h]
  long double v144; // [esp+20h] [ebp-7CA4h]
  long double v145; // [esp+20h] [ebp-7CA4h]
  long double v146; // [esp+20h] [ebp-7CA4h]
  long double v147; // [esp+20h] [ebp-7CA4h]
  long double v148; // [esp+20h] [ebp-7CA4h]
  long double v149; // [esp+20h] [ebp-7CA4h]
  s_bone_t *v150[4000]; // [esp+28h] [ebp-7C9Ch] BYREF
  s_bone_t *v151[2000]; // [esp+3EA8h] [ebp-3E1Ch] BYREF
  int v152[512]; // [esp+5DE8h] [ebp-1EDCh] BYREF
  int v153; // [esp+65E8h] [ebp-16DCh] BYREF
  int v154; // [esp+65ECh] [ebp-16D8h]
  int v155; // [esp+6DE8h] [ebp-EDCh] BYREF
  float v156; // [esp+6DECh] [ebp-ED8h] BYREF
  int v157; // [esp+6DF0h] [ebp-ED4h] BYREF
  int v158[509]; // [esp+6DF4h] [ebp-ED0h] BYREF
  _DWORD v159[32]; // [esp+75E8h] [ebp-6DCh] BYREF
  M_matrix4x4_t v160; // [esp+7668h] [ebp-65Ch] BYREF
  M_matrix4x4_t v161; // [esp+76A8h] [ebp-61Ch] BYREF
  M_matrix4x4_t v162; // [esp+76E8h] [ebp-5DCh] BYREF
  M_matrix4x4_t v163; // [esp+7728h] [ebp-59Ch] BYREF
  M_matrix4x4_t v164; // [esp+7768h] [ebp-55Ch] BYREF
  M_matrix4x4_t v165; // [esp+77A8h] [ebp-51Ch] BYREF
  float v166; // [esp+77ECh] [ebp-4D8h]
  __int64 v167; // [esp+77F0h] [ebp-4D4h]
  M_matrix4x4_t v168; // [esp+77F8h] [ebp-4CCh] BYREF
  __int128 v169; // [esp+7838h] [ebp-48Ch]
  M_matrix4x4_t v170; // [esp+7848h] [ebp-47Ch] BYREF
  M_matrix4x4_t v171; // [esp+7888h] [ebp-43Ch] BYREF
  __int64 v172; // [esp+78CCh] [ebp-3F8h]
  float v173; // [esp+78D4h] [ebp-3F0h]
  M_matrix4x4_t v174; // [esp+78D8h] [ebp-3ECh] BYREF
  int v175; // [esp+7924h] [ebp-3A0h]
  int v176; // [esp+7928h] [ebp-39Ch]
  float v177; // [esp+792Ch] [ebp-398h]
  Vector v178; // [esp+7930h] [ebp-394h] BYREF
  float v179; // [esp+793Ch] [ebp-388h]
  float v180; // [esp+7940h] [ebp-384h]
  float v181; // [esp+7944h] [ebp-380h]
  float v182; // [esp+7948h] [ebp-37Ch]
  int v183; // [esp+794Ch] [ebp-378h]
  __int64 v184; // [esp+7950h] [ebp-374h]
  float toeFloorZ; // [esp+7958h] [ebp-36Ch]
  float v186; // [esp+795Ch] [ebp-368h]
  float v187; // [esp+7960h] [ebp-364h]
  int v188; // [esp+7964h] [ebp-360h]
  int v189; // [esp+7968h] [ebp-35Ch]
  float v190; // [esp+796Ch] [ebp-358h]
  M_matrix4x4_t v191; // [esp+7970h] [ebp-354h] BYREF
  Vector v192; // [esp+79B0h] [ebp-314h] BYREF
  __int64 v193; // [esp+79BCh] [ebp-308h]
  float v194; // [esp+79C4h] [ebp-300h]
  float v195; // [esp+79C8h] [ebp-2FCh]
  float v196; // [esp+79CCh] [ebp-2F8h]
  float v197; // [esp+79D0h] [ebp-2F4h]
  float v198; // [esp+79D4h] [ebp-2F0h]
  int v199; // [esp+79D8h] [ebp-2ECh]
  float v200; // [esp+79DCh] [ebp-2E8h]
  float v201; // [esp+79E0h] [ebp-2E4h]
  float v202; // [esp+79E4h] [ebp-2E0h]
  float v203; // [esp+79E8h] [ebp-2DCh]
  int v204; // [esp+79ECh] [ebp-2D8h]
  float v205; // [esp+79F0h] [ebp-2D4h]
  float v206; // [esp+79F4h] [ebp-2D0h]
  float v207; // [esp+79F8h] [ebp-2CCh]
  float v208; // [esp+79FCh] [ebp-2C8h]
  M_matrix4x4_t v209; // [esp+7A00h] [ebp-2C4h] BYREF
  Vector v210; // [esp+7A44h] [ebp-280h] BYREF
  float v211; // [esp+7A50h] [ebp-274h]
  __int64 v212; // [esp+7A54h] [ebp-270h]
  Vector v213; // [esp+7A5Ch] [ebp-268h] BYREF
  M_matrix4x4_t v214; // [esp+7A68h] [ebp-25Ch] BYREF
  Vector v215; // [esp+7AACh] [ebp-218h]
  M_matrix4x4_t v216; // [esp+7AB8h] [ebp-20Ch] BYREF
  int v217; // [esp+7AFCh] [ebp-1C8h]
  M_matrix4x4_t v218; // [esp+7B00h] [ebp-1C4h] BYREF
  s_bone_t **v219; // [esp+7B40h] [ebp-184h]
  float v220; // [esp+7B44h] [ebp-180h]
  float v221; // [esp+7B48h] [ebp-17Ch]
  float v222; // [esp+7B4Ch] [ebp-178h]
  M_matrix4x4_t v223; // [esp+7B50h] [ebp-174h] BYREF
  M_matrix4x4_t v224; // [esp+7B90h] [ebp-134h] BYREF
  float v225; // [esp+7BD0h] [ebp-F4h]
  float v226; // [esp+7BD4h] [ebp-F0h]
  float v227; // [esp+7BD8h] [ebp-ECh]
  float v228; // [esp+7BDCh] [ebp-E8h]
  float v229; // [esp+7BE0h] [ebp-E4h]
  float v230; // [esp+7BE4h] [ebp-E0h]
  float v231; // [esp+7BE8h] [ebp-DCh]
  float v232; // [esp+7BECh] [ebp-D8h]
  float v233; // [esp+7BF0h] [ebp-D4h]
  float v234; // [esp+7BF4h] [ebp-D0h]
  float v235; // [esp+7BF8h] [ebp-CCh]
  float v236; // [esp+7BFCh] [ebp-C8h]
  float v237; // [esp+7C00h] [ebp-C4h]
  float v238; // [esp+7C04h] [ebp-C0h]
  float v239; // [esp+7C08h] [ebp-BCh]
  float v240; // [esp+7C0Ch] [ebp-B8h]
  Vector v241; // [esp+7C14h] [ebp-B0h] BYREF
  Vector v242; // [esp+7C20h] [ebp-A4h] BYREF
  __int64 v243; // [esp+7C38h] [ebp-8Ch]
  float v244; // [esp+7C40h] [ebp-84h]
  Vector v245; // [esp+7C44h] [ebp-80h] BYREF
  s_bone_t **rawanim; // [esp+7C50h] [ebp-74h]
  int v247; // [esp+7C54h] [ebp-70h]
  int v248; // [esp+7C58h] [ebp-6Ch]
  const char **ikSolves; // [esp+7C5Ch] [ebp-68h]
  M_matrix4x4_t v250; // [esp+7C60h] [ebp-64h] BYREF
  s_jointScale_t **jointScales; // [esp+7CA4h] [ebp-20h]
  int v252; // [esp+7CA8h] [ebp-1Ch]
  s_bone_t **v253; // [esp+7CACh] [ebp-18h]
  char *v254; // [esp+7CB0h] [ebp-14h]
  float v255; // [esp+7CB4h] [ebp-10h]
  int v256; // [esp+7CB8h] [ebp-Ch]
  void *v257; // [esp+7CBCh] [ebp-8h]
  void *retaddr; // [esp+7CC4h] [ebp+0h]

  v256 = a1;
  v257 = retaddr;
  v5 = alloca(31896);
  v116 = a2;
  v6 = pTarget;
  if ( pTemplate->doSkeletonScale != 0 )
    ScaleSkeleton(pSkeleton: pTarget, scale: pTemplate->skeletonScale);
  v7 = 0;
  if ( pTemplate->numJointScales > 0 )
  {
    jointScales = pTemplate->jointScales;
    do
    {
      ScaleJoints(pSkeleton: pTarget, jointScale: *jointScales++);
      ++v7;
    }
    while ( v7 < pTemplate->numJointScales );
  }
  strcpy((char *)v159, "ValveBiped.Bip01");
  memset(dst: (unsigned __int8 *)&v159[4] + 1, value: 0, count: 0x6Fu);
  jointScales = (s_jointScale_t **)GetNodeIndex(psource: pSource, nodeName: (char *)v159);
  NodeIndex = GetNodeIndex(psource: pSource, nodeName: pTemplate->rootScaleJoint);
  rawanim = (s_bone_t **)NodeIndex;
  v9 = &v153;
  if ( NodeIndex <= -1 )
  {
    printf(format: "Error: Can't find node: %s\n", (const char *)&v153);
    exit(code: 0);
  }
  v10 = jointScales;
  v153 = NodeIndex;
  if ( (s_jointScale_t **)NodeIndex != jointScales )
  {
    do
    {
      NodeIndex = pSource->localBone[NodeIndex].parent;
      *++v9 = NodeIndex;
    }
    while ( (s_jointScale_t **)NodeIndex != v10 );
    NodeIndex = (int)rawanim;
  }
  v9[1] = -1;
  rawanim = pTarget->rawanim;
  v11 = (float)(pTarget->rawanim[0][NodeIndex].pos.x + pTarget->rawanim[0][v154].pos.x)
      / (float)(pSource->rawanim[0][NodeIndex].pos.x + pSource->rawanim[0][v154].pos.x);
  v181 = v11;
  if ( g_verbose )
    printf(format: "Root Scale Factor: %f\n", v11);
  v12 = *(_QWORD *)&pSource->rawanim[0][(_DWORD)jointScales].pos.x;
  v183 = 24 * (_DWORD)jointScales;
  v184 = v12;
  toeFloorZ = pTemplate->toeFloorZ;
  CombineSkeletonAnimation(pSkeleton: pTarget, pAnimation: pSource, ppAnim: v151);
  CombineSkeletonAnimation(pSkeleton: pTarget, pAnimation: pSource, ppAnim: v150);
  numframes = pSource->numframes;
  v217 = numframes;
  v252 = 0;
  if ( numframes > 0 )
  {
    v253 = pSource->rawanim;
    v199 = (char *)pTarget - (char *)pSource;
    do
    {
      scale = v252;
      *(s_bone_t **)((char *)v253 + v199) = v150[v252];
      printf(format: "Note: Processing frame: %i\n", scale);
      v14 = pTemplate->numIKSolves <= 0;
      v248 = 0;
      if ( !v14 )
      {
        ikSolves = (const char **)pTemplate->ikSolves;
        do
        {
          v254 = (char *)*ikSolves;
          v15 = v254;
          v16 = GetNodeIndex(psource: pSource, nodeName: v254);
          if ( v16 <= -1 )
          {
$LN1688:
            printf(format: "Error: Can't find node: %s\n", v15);
            exit(code: 0);
          }
          v17 = jointScales;
          v18 = &v155;
          v155 = v16;
          if ( (s_jointScale_t **)v16 != jointScales )
          {
            parent = v16;
            do
            {
              parent = pSource->localBone[parent].parent;
              *++v18 = parent;
            }
            while ( (s_jointScale_t **)parent != v17 );
          }
          v20 = pSource->rawanim[0];
          v18[1] = -1;
          v21 = v20[v16].pos.x + v20[LODWORD(v156)].pos.x;
          v22 = (*rawanim)[v16].pos.x + (*rawanim)[LODWORD(v156)].pos.x;
          v247 = 24 * v16;
          v208 = v22;
          v190 = v22 / v21;
          if ( g_verbose )
            printf(format: "limb length %s: %i: %f, factor %f\n", v254, v16, (float)(v21 - v22), (float)(v22 / v21));
          v23 = v252;
          v110 = pSource->rawanim[v252];
          *(_QWORD *)&v209.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v209.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v209.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v209.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v209.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v209.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v209.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v223.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v223.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v223.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v223.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v223.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v223.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v223.m_flMatVal[3][2] = 0x3F80000000000000LL;
          CatBonePath(indexPath: &v157, boneArray: v110, resultMatrix: &v209, rootOffset: 1);
          CatBonePath(
            indexPath: &v157,
            boneArray: *(s_bone_t **)((char *)v253 + v199),
            resultMatrix: &v223,
            rootOffset: 1);
          v24 = v223.m_flMatVal[3][0] - v209.m_flMatVal[3][0];
          v25 = v223.m_flMatVal[3][1] - v209.m_flMatVal[3][1];
          v26 = v223.m_flMatVal[3][2] - v209.m_flMatVal[3][2];
          v220 = v223.m_flMatVal[3][0] - v209.m_flMatVal[3][0];
          v221 = v223.m_flMatVal[3][1] - v209.m_flMatVal[3][1];
          v222 = v223.m_flMatVal[3][2] - v209.m_flMatVal[3][2];
          if ( g_verbose )
          {
            printf(format: "Grand parent delta: %f %f %f\n", v24, v25, v26);
            v24 = v220;
            v26 = v222;
            v25 = v221;
          }
          v27 = pSource->rawanim[v23];
          v220 = *((float *)v254 + 258) * v24;
          v221 = *((float *)v254 + 259) * v25;
          v222 = *((float *)v254 + 260) * v26;
          *(_QWORD *)&v218.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v218.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v218.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v218.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v218.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v218.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v218.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v216.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v216.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v216.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v216.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v216.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v216.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v216.m_flMatVal[3][2] = 0x3F80000000000000LL;
          M_AngleMatrix(angles: &v27[v155].rot, position: &v27[v155].pos, matrix: &v218);
          v109 = &pSource->rawanim[v23][LODWORD(v156)];
          M_AngleMatrix(angles: &v109->rot, position: &v109->pos, matrix: &v216);
          v225 = (float)((float)((float)(v216.m_flMatVal[0][0] * v218.m_flMatVal[0][0])
                               + (float)(v216.m_flMatVal[1][0] * v218.m_flMatVal[0][1]))
                       + (float)(v216.m_flMatVal[2][0] * v218.m_flMatVal[0][2]))
               + (float)(v216.m_flMatVal[3][0] * v218.m_flMatVal[0][3]);
          v226 = (float)((float)((float)(v218.m_flMatVal[0][0] * v216.m_flMatVal[0][1])
                               + (float)(v216.m_flMatVal[1][1] * v218.m_flMatVal[0][1]))
                       + (float)(v216.m_flMatVal[2][1] * v218.m_flMatVal[0][2]))
               + (float)(v216.m_flMatVal[3][1] * v218.m_flMatVal[0][3]);
          v227 = (float)((float)((float)(v218.m_flMatVal[0][0] * v216.m_flMatVal[0][2])
                               + (float)(v216.m_flMatVal[1][2] * v218.m_flMatVal[0][1]))
                       + (float)(v216.m_flMatVal[2][2] * v218.m_flMatVal[0][2]))
               + (float)(v216.m_flMatVal[3][2] * v218.m_flMatVal[0][3]);
          v228 = (float)((float)((float)(v218.m_flMatVal[0][0] * v216.m_flMatVal[0][3])
                               + (float)(v216.m_flMatVal[1][3] * v218.m_flMatVal[0][1]))
                       + (float)(v216.m_flMatVal[2][3] * v218.m_flMatVal[0][2]))
               + (float)(v216.m_flMatVal[3][3] * v218.m_flMatVal[0][3]);
          v255 = (float)(v216.m_flMatVal[0][0] * v218.m_flMatVal[1][0])
               + (float)(v216.m_flMatVal[1][0] * v218.m_flMatVal[1][1]);
          v229 = (float)(v255 + (float)(v216.m_flMatVal[2][0] * v218.m_flMatVal[1][2]))
               + (float)(v216.m_flMatVal[3][0] * v218.m_flMatVal[1][3]);
          v230 = (float)((float)((float)(v216.m_flMatVal[1][1] * v218.m_flMatVal[1][1])
                               + (float)(v216.m_flMatVal[0][1] * v218.m_flMatVal[1][0]))
                       + (float)(v216.m_flMatVal[2][1] * v218.m_flMatVal[1][2]))
               + (float)(v216.m_flMatVal[3][1] * v218.m_flMatVal[1][3]);
          v231 = (float)((float)((float)(v216.m_flMatVal[1][2] * v218.m_flMatVal[1][1])
                               + (float)(v216.m_flMatVal[0][2] * v218.m_flMatVal[1][0]))
                       + (float)(v216.m_flMatVal[2][2] * v218.m_flMatVal[1][2]))
               + (float)(v216.m_flMatVal[3][2] * v218.m_flMatVal[1][3]);
          v232 = (float)((float)((float)(v216.m_flMatVal[1][3] * v218.m_flMatVal[1][1])
                               + (float)(v216.m_flMatVal[0][3] * v218.m_flMatVal[1][0]))
                       + (float)(v216.m_flMatVal[2][3] * v218.m_flMatVal[1][2]))
               + (float)(v216.m_flMatVal[3][3] * v218.m_flMatVal[1][3]);
          v233 = (float)((float)((float)(v216.m_flMatVal[0][0] * v218.m_flMatVal[2][0])
                               + (float)(v216.m_flMatVal[1][0] * v218.m_flMatVal[2][1]))
                       + (float)(v216.m_flMatVal[2][0] * v218.m_flMatVal[2][2]))
               + (float)(v216.m_flMatVal[3][0] * v218.m_flMatVal[2][3]);
          v234 = (float)((float)((float)(v216.m_flMatVal[1][1] * v218.m_flMatVal[2][1])
                               + (float)(v216.m_flMatVal[0][1] * v218.m_flMatVal[2][0]))
                       + (float)(v216.m_flMatVal[2][1] * v218.m_flMatVal[2][2]))
               + (float)(v216.m_flMatVal[3][1] * v218.m_flMatVal[2][3]);
          v235 = (float)((float)((float)(v216.m_flMatVal[1][2] * v218.m_flMatVal[2][1])
                               + (float)(v216.m_flMatVal[0][2] * v218.m_flMatVal[2][0]))
                       + (float)(v216.m_flMatVal[2][2] * v218.m_flMatVal[2][2]))
               + (float)(v216.m_flMatVal[3][2] * v218.m_flMatVal[2][3]);
          v255 = v216.m_flMatVal[1][3] * v218.m_flMatVal[2][1];
          v236 = (float)((float)((float)(v216.m_flMatVal[1][3] * v218.m_flMatVal[2][1])
                               + (float)(v216.m_flMatVal[0][3] * v218.m_flMatVal[2][0]))
                       + (float)(v216.m_flMatVal[2][3] * v218.m_flMatVal[2][2]))
               + (float)(v216.m_flMatVal[3][3] * v218.m_flMatVal[2][3]);
          v28 = *((_DWORD *)v254 + 261) == 0;
          v237 = (float)((float)((float)(v216.m_flMatVal[0][0] * v218.m_flMatVal[3][0])
                               + (float)(v216.m_flMatVal[1][0] * v218.m_flMatVal[3][1]))
                       + (float)(v216.m_flMatVal[2][0] * v218.m_flMatVal[3][2]))
               + (float)(v216.m_flMatVal[3][0] * v218.m_flMatVal[3][3]);
          v238 = (float)((float)((float)(v216.m_flMatVal[1][1] * v218.m_flMatVal[3][1])
                               + (float)(v216.m_flMatVal[0][1] * v218.m_flMatVal[3][0]))
                       + (float)(v216.m_flMatVal[2][1] * v218.m_flMatVal[3][2]))
               + (float)(v216.m_flMatVal[3][1] * v218.m_flMatVal[3][3]);
          v239 = (float)((float)((float)(v216.m_flMatVal[1][2] * v218.m_flMatVal[3][1])
                               + (float)(v216.m_flMatVal[0][2] * v218.m_flMatVal[3][0]))
                       + (float)(v216.m_flMatVal[2][2] * v218.m_flMatVal[3][2]))
               + (float)(v216.m_flMatVal[3][2] * v218.m_flMatVal[3][3]);
          v240 = (float)((float)((float)(v216.m_flMatVal[1][3] * v218.m_flMatVal[3][1])
                               + (float)(v216.m_flMatVal[0][3] * v218.m_flMatVal[3][0]))
                       + (float)(v216.m_flMatVal[2][3] * v218.m_flMatVal[3][2]))
               + (float)(v216.m_flMatVal[3][3] * v218.m_flMatVal[3][3]);
          if ( v28 )
          {
            v29 = (float)((float)(v190 - 1.0) * *((float *)v254 + 257)) + 1.0;
            v237 = v237 * v29;
            v238 = (float)((float)((float)((float)(v216.m_flMatVal[1][1] * v218.m_flMatVal[3][1])
                                         + (float)(v216.m_flMatVal[0][1] * v218.m_flMatVal[3][0]))
                                 + (float)(v216.m_flMatVal[2][1] * v218.m_flMatVal[3][2]))
                         + (float)(v216.m_flMatVal[3][1] * v218.m_flMatVal[3][3]))
                 * v29;
            v239 = (float)((float)((float)((float)(v216.m_flMatVal[1][2] * v218.m_flMatVal[3][1])
                                         + (float)(v216.m_flMatVal[0][2] * v218.m_flMatVal[3][0]))
                                 + (float)(v216.m_flMatVal[2][2] * v218.m_flMatVal[3][2]))
                         + (float)(v216.m_flMatVal[3][2] * v218.m_flMatVal[3][3]))
                 * v29;
          }
          v111 = pSource->rawanim[v23];
          *(_QWORD *)&v250.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v250.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v250.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v250.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v250.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v250.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v250.m_flMatVal[3][2] = 0x3F80000000000000LL;
          CatBonePath(indexPath: &v157, boneArray: v111, resultMatrix: &v250, rootOffset: 1);
          v170.m_flMatVal[0][0] = (float)((float)((float)(v225 * v250.m_flMatVal[0][0])
                                                + (float)(v250.m_flMatVal[1][0] * v226))
                                        + (float)(v250.m_flMatVal[2][0] * v227))
                                + (float)(v250.m_flMatVal[3][0] * v228);
          v170.m_flMatVal[0][1] = (float)((float)((float)(v225 * v250.m_flMatVal[0][1])
                                                + (float)(v250.m_flMatVal[1][1] * v226))
                                        + (float)(v250.m_flMatVal[2][1] * v227))
                                + (float)(v250.m_flMatVal[3][1] * v228);
          v170.m_flMatVal[0][2] = (float)((float)((float)(v225 * v250.m_flMatVal[0][2])
                                                + (float)(v250.m_flMatVal[1][2] * v226))
                                        + (float)(v250.m_flMatVal[2][2] * v227))
                                + (float)(v250.m_flMatVal[3][2] * v228);
          v170.m_flMatVal[0][3] = (float)((float)((float)(v225 * v250.m_flMatVal[0][3])
                                                + (float)(v250.m_flMatVal[1][3] * v226))
                                        + (float)(v250.m_flMatVal[2][3] * v227))
                                + (float)(v250.m_flMatVal[3][3] * v228);
          v170.m_flMatVal[1][0] = (float)((float)((float)(v250.m_flMatVal[0][0] * v229)
                                                + (float)(v250.m_flMatVal[1][0] * v230))
                                        + (float)(v250.m_flMatVal[2][0] * v231))
                                + (float)(v250.m_flMatVal[3][0] * v232);
          v170.m_flMatVal[1][1] = (float)((float)((float)(v250.m_flMatVal[1][1] * v230)
                                                + (float)(v250.m_flMatVal[0][1] * v229))
                                        + (float)(v250.m_flMatVal[2][1] * v231))
                                + (float)(v250.m_flMatVal[3][1] * v232);
          v170.m_flMatVal[1][2] = (float)((float)((float)(v250.m_flMatVal[1][2] * v230)
                                                + (float)(v250.m_flMatVal[0][2] * v229))
                                        + (float)(v250.m_flMatVal[2][2] * v231))
                                + (float)(v250.m_flMatVal[3][2] * v232);
          v170.m_flMatVal[1][3] = (float)((float)((float)(v250.m_flMatVal[1][3] * v230)
                                                + (float)(v250.m_flMatVal[0][3] * v229))
                                        + (float)(v250.m_flMatVal[2][3] * v231))
                                + (float)(v250.m_flMatVal[3][3] * v232);
          v170.m_flMatVal[2][0] = (float)((float)((float)(v250.m_flMatVal[0][0] * v233)
                                                + (float)(v250.m_flMatVal[1][0] * v234))
                                        + (float)(v250.m_flMatVal[2][0] * v235))
                                + (float)(v250.m_flMatVal[3][0] * v236);
          v170.m_flMatVal[2][1] = (float)((float)((float)(v250.m_flMatVal[1][1] * v234)
                                                + (float)(v250.m_flMatVal[0][1] * v233))
                                        + (float)(v250.m_flMatVal[2][1] * v235))
                                + (float)(v250.m_flMatVal[3][1] * v236);
          v170.m_flMatVal[2][2] = (float)((float)((float)(v250.m_flMatVal[1][2] * v234)
                                                + (float)(v250.m_flMatVal[0][2] * v233))
                                        + (float)(v250.m_flMatVal[2][2] * v235))
                                + (float)(v250.m_flMatVal[3][2] * v236);
          v170.m_flMatVal[2][3] = (float)((float)((float)(v250.m_flMatVal[1][3] * v234)
                                                + (float)(v250.m_flMatVal[0][3] * v233))
                                        + (float)(v250.m_flMatVal[2][3] * v235))
                                + (float)(v250.m_flMatVal[3][3] * v236);
          v28 = *((_DWORD *)v254 + 261) == 0;
          v170.m_flMatVal[3][0] = (float)((float)((float)(v250.m_flMatVal[0][0] * v237)
                                                + (float)(v250.m_flMatVal[1][0] * v238))
                                        + (float)(v250.m_flMatVal[2][0] * v239))
                                + (float)(v250.m_flMatVal[3][0] * v240);
          v170.m_flMatVal[3][1] = (float)((float)((float)(v250.m_flMatVal[1][1] * v238)
                                                + (float)(v250.m_flMatVal[0][1] * v237))
                                        + (float)(v250.m_flMatVal[2][1] * v239))
                                + (float)(v250.m_flMatVal[3][1] * v240);
          v170.m_flMatVal[3][2] = (float)((float)((float)(v250.m_flMatVal[1][2] * v238)
                                                + (float)(v250.m_flMatVal[0][2] * v237))
                                        + (float)(v250.m_flMatVal[2][2] * v239))
                                + (float)(v250.m_flMatVal[3][2] * v240);
          v170.m_flMatVal[3][3] = (float)((float)((float)(v250.m_flMatVal[1][3] * v238)
                                                + (float)(v250.m_flMatVal[0][3] * v237))
                                        + (float)(v250.m_flMatVal[2][3] * v239))
                                + (float)(v250.m_flMatVal[3][3] * v240);
          if ( v28 )
          {
            v170.m_flMatVal[3][0] = v220 + v170.m_flMatVal[3][0];
            v170.m_flMatVal[3][1] = (float)((float)((float)((float)(v250.m_flMatVal[1][1] * v238)
                                                          + (float)(v250.m_flMatVal[0][1] * v237))
                                                  + (float)(v250.m_flMatVal[2][1] * v239))
                                          + (float)(v250.m_flMatVal[3][1] * v240))
                                  + v221;
            v170.m_flMatVal[3][2] = (float)((float)((float)((float)(v250.m_flMatVal[1][2] * v238)
                                                          + (float)(v250.m_flMatVal[0][2] * v237))
                                                  + (float)(v250.m_flMatVal[2][2] * v239))
                                          + (float)(v250.m_flMatVal[3][2] * v240))
                                  + v222;
          }
          else
          {
            v219 = (s_bone_t **)(v254 + 1048);
            v30 = GetNodeIndex(psource: pSource, nodeName: v254 + 1048);
            if ( v30 <= -1 )
            {
              printf(format: "Error: Can't find node: %s\n", (const char *)v219);
              exit(code: 0);
            }
            v31 = jointScales;
            v32 = v152;
            for ( v152[0] = v30; (s_jointScale_t **)v30 != v31; *v32 = v30 )
            {
              v30 = pSource->localBone[v30].parent;
              ++v32;
            }
            v33 = pSource->rawanim[v23];
            v32[1] = -1;
            *(_QWORD *)&v250.m_flMatVal[0][0] = 1065353216;
            *(_QWORD *)&v250.m_flMatVal[0][2] = 0;
            *(_QWORD *)&v250.m_flMatVal[1][0] = 0x3F80000000000000LL;
            memset(&v250.m_flMatVal[1][2], 0, 16);
            *(_QWORD *)&v250.m_flMatVal[2][2] = 1065353216;
            *(_QWORD *)&v250.m_flMatVal[3][0] = 0;
            *(_QWORD *)&v250.m_flMatVal[3][2] = 0x3F80000000000000LL;
            *(_QWORD *)&v209.m_flMatVal[0][0] = 1065353216;
            *(_QWORD *)&v209.m_flMatVal[0][2] = 0;
            *(_QWORD *)&v209.m_flMatVal[1][0] = 0x3F80000000000000LL;
            memset(&v209.m_flMatVal[1][2], 0, 16);
            *(_QWORD *)&v209.m_flMatVal[2][2] = 1065353216;
            *(_QWORD *)&v209.m_flMatVal[3][0] = 0;
            *(_QWORD *)&v209.m_flMatVal[3][2] = 0x3F80000000000000LL;
            *(_QWORD *)&v223.m_flMatVal[0][0] = 1065353216;
            *(_QWORD *)&v223.m_flMatVal[0][2] = 0;
            *(_QWORD *)&v223.m_flMatVal[1][0] = 0x3F80000000000000LL;
            memset(&v223.m_flMatVal[1][2], 0, 16);
            *(_QWORD *)&v223.m_flMatVal[2][2] = 1065353216;
            *(_QWORD *)&v223.m_flMatVal[3][0] = 0;
            *(_QWORD *)&v223.m_flMatVal[3][2] = 0x3F80000000000000LL;
            CatBonePath(indexPath: v152, boneArray: v33, resultMatrix: &v250, rootOffset: 1);
            v209.m_flMatVal[2][2] = v250.m_flMatVal[2][2];
            v209.m_flMatVal[1][0] = v250.m_flMatVal[0][1];
            v209.m_flMatVal[0][0] = v250.m_flMatVal[0][0];
            *(_QWORD *)&v209.m_flMatVal[2][0] = __PAIR64__(
                                                  LODWORD(v250.m_flMatVal[1][2]),
                                                  LODWORD(v250.m_flMatVal[0][2]));
            *(_QWORD *)&v209.m_flMatVal[0][1] = __PAIR64__(
                                                  LODWORD(v250.m_flMatVal[2][0]),
                                                  LODWORD(v250.m_flMatVal[1][0]));
            *(_QWORD *)&v209.m_flMatVal[1][1] = __PAIR64__(
                                                  LODWORD(v250.m_flMatVal[2][1]),
                                                  LODWORD(v250.m_flMatVal[1][1]));
            v209.m_flMatVal[3][0] = -(float)((float)((float)(v250.m_flMatVal[0][0] * v250.m_flMatVal[3][0])
                                                   + (float)(v250.m_flMatVal[3][1] * v250.m_flMatVal[0][1]))
                                           + (float)(v250.m_flMatVal[3][2] * v250.m_flMatVal[0][2]));
            v209.m_flMatVal[3][1] = -(float)((float)((float)(v250.m_flMatVal[3][1] * v250.m_flMatVal[1][1])
                                                   + (float)(v250.m_flMatVal[3][0] * v250.m_flMatVal[1][0]))
                                           + (float)(v250.m_flMatVal[3][2] * v250.m_flMatVal[1][2]));
            v209.m_flMatVal[3][2] = -(float)((float)((float)(v250.m_flMatVal[3][1] * v250.m_flMatVal[2][1])
                                                   + (float)(v250.m_flMatVal[3][0] * v250.m_flMatVal[2][0]))
                                           + (float)(v250.m_flMatVal[3][2] * v250.m_flMatVal[2][2]));
            M_ConcatTransforms(in1: &v170, in2: &v209, out: &v223);
            if ( *((float *)v254 + 518) != 1.0 )
            {
              v34 = *((float *)v254 + 518);
              v223.m_flMatVal[3][0] = v34 * v223.m_flMatVal[3][0];
              v223.m_flMatVal[3][1] = v34 * v223.m_flMatVal[3][1];
              v223.m_flMatVal[3][2] = v34 * v223.m_flMatVal[3][2];
            }
            v150[v23 + 2000] = pSource->rawanim[v23];
            v112 = v151[v23];
            pSource->rawanim[v23] = v112;
            *(_QWORD *)&v164.m_flMatVal[0][0] = 1065353216;
            *(_QWORD *)&v164.m_flMatVal[0][2] = 0;
            *(_QWORD *)&v164.m_flMatVal[1][0] = 0x3F80000000000000LL;
            memset(&v164.m_flMatVal[1][2], 0, 16);
            *(_QWORD *)&v164.m_flMatVal[2][2] = 1065353216;
            *(_QWORD *)&v164.m_flMatVal[3][0] = 0;
            *(_QWORD *)&v164.m_flMatVal[3][2] = 0x3F80000000000000LL;
            CatBonePath(indexPath: v152, boneArray: v112, resultMatrix: &v164, rootOffset: 1);
            M_ConcatTransforms(in1: &v223, in2: &v164, out: &v170);
            v35 = v150[v23 + 2000];
            v151[v23] = pSource->rawanim[v23];
            pSource->rawanim[v23] = v35;
          }
          v36 = v252;
          v37 = v151[v252];
          v150[v252 + 2000] = pSource->rawanim[v252];
          pSource->rawanim[v36] = v37;
          *(_QWORD *)&v174.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v174.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v174.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v174.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v174.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v174.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v174.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v191.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v191.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v191.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v191.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v191.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v191.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v191.m_flMatVal[3][2] = 0x3F80000000000000LL;
          CatBonePath(indexPath: &v157, boneArray: v37, resultMatrix: &v174, rootOffset: 1);
          CatBonePath(indexPath: v158, boneArray: pSource->rawanim[v36], resultMatrix: &v191, rootOffset: 1);
          v38 = pSource->rawanim[v252];
          v39 = *(float *)((char *)&v38->pos.x + v247);
          LODWORD(v40) = 24 * LODWORD(v156);
          x = v38[LODWORD(v156)].pos.x;
          v178.x = v170.m_flMatVal[3][0] - v174.m_flMatVal[3][0];
          v178.y = v170.m_flMatVal[3][1] - v174.m_flMatVal[3][1];
          v178.z = v170.m_flMatVal[3][2] - v174.m_flMatVal[3][2];
          v42 = 0;
          *(float *)&v42 = fsqrt((float)((float)(v178.x * v178.x) + (float)(v178.y * v178.y)) + (float)(v178.z * v178.z));
          v169 = v42;
          v43 = x * x;
          v44 = x * 2.0;
          v207 = (float)((float)(v43 + (float)(*(float *)&v42 * *(float *)&v42)) - (float)(v39 * v39))
               / (float)(v44 * *(float *)&v42);
          v201 = (float)((float)((float)(v39 * v39) + v43) - (float)(*(float *)&v42 * *(float *)&v42))
               / (float)(v44 * v39);
          VectorNormalize(vec: &v178);
          v215 = v178;
          v242 = *(Vector *)&v174.m_flMatVal[2][0];
          VectorNormalize(vec: &v242);
          v210.x = (float)(v215.z * v242.y) - (float)(v215.y * v242.z);
          v210.y = (float)(v215.x * v242.z) - (float)(v242.x * v215.z);
          v210.z = (float)(v242.x * v215.y) - (float)(v215.x * v242.y);
          VectorNormalize(vec: &v210);
          v242.x = (float)(v210.z * v215.y) - (float)(v210.y * v215.z);
          v242.y = (float)(v215.z * v210.x) - (float)(v210.z * v215.x);
          v242.z = (float)(v210.y * v215.x) - (float)(v215.y * v210.x);
          VectorNormalize(vec: &v242);
          *(__m128i *)&v160.m_flMatVal[0][0] = _mm_load_si128((const __m128i *)&v174);
          *(__m128i *)&v160.m_flMatVal[1][0] = _mm_load_si128((const __m128i *)v174.m_flMatVal[1]);
          *(__m128i *)&v160.m_flMatVal[2][0] = _mm_load_si128((const __m128i *)v174.m_flMatVal[2]);
          v45 = *((float *)v254 + 256);
          *(__m128i *)&v160.m_flMatVal[3][0] = _mm_load_si128((const __m128i *)v174.m_flMatVal[3]);
          *(Vector *)&v160.m_flMatVal[0][0] = v215;
          *(Vector *)&v160.m_flMatVal[1][0] = v210;
          *(Vector *)&v160.m_flMatVal[2][0] = v242;
          memset(&v171.m_flMatVal[0][2], 0, 12);
          memset(&v171.m_flMatVal[1][3], 0, 12);
          *(_QWORD *)&v171.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v171.m_flMatVal[3][2] = 0x3F80000000000000LL;
          memset(&v165.m_flMatVal[0][2], 0, 12);
          memset(&v165.m_flMatVal[1][3], 0, 12);
          *(_QWORD *)&v165.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v165.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v171.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v171.m_flMatVal[1][1] = 1065353216;
          *(_QWORD *)&v171.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v165.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v165.m_flMatVal[1][1] = 1065353216;
          *(_QWORD *)&v165.m_flMatVal[2][2] = 1065353216;
          v255 = v45;
          v46 = v207;
          if ( v45 == 0.0 )
          {
            __libm_sse2_acos(x: v116);
            v48 = v46;
            v47 = -v48;
          }
          else
          {
            __libm_sse2_acos(x: v116);
            v47 = v46;
          }
          v206 = v47;
          if ( v208 > *(float *)&v169 )
          {
            __libm_sse2_cos(x: v117);
            v182 = v47;
            v171.m_flMatVal[0][0] = v47;
            v49 = v206;
            __libm_sse2_sin(x: v118);
            *(float *)&v49 = v49;
            *(_QWORD *)&v171.m_flMatVal[0][1] = LODWORD(v49);
            v171.m_flMatVal[1][0] = -*(float *)&v49;
            *(_QWORD *)&v171.m_flMatVal[1][1] = LODWORD(v182);
            *(_QWORD *)&v171.m_flMatVal[2][0] = 0;
            v171.m_flMatVal[2][2] = 1.0;
          }
          M_ConcatTransforms(in1: &v171, in2: &v160, out: &v165);
          v159[16] = 1065353216;
          v159[17] = 0;
          v159[21] = 1065353216;
          v50 = v201;
          __libm_sse2_acos(x: v117);
          *(float *)&v50 = v50;
          v51 = *(float *)&v50;
          if ( v255 == 0.0 )
            v52 = 3.141592653589793 - v51;
          else
            v52 = v51 + 3.141592653589793;
          v203 = v52;
          if ( v208 > *(float *)&v169 )
          {
            __libm_sse2_cos(x: v119);
            v179 = v52;
            *(float *)&v159[16] = v52;
            v53 = v203;
            __libm_sse2_sin(x: v120);
            *(float *)&v53 = v53;
            v159[17] = LODWORD(v53);
            *(float *)&v159[21] = v179;
          }
          *(_QWORD *)&v163.m_flMatVal[1][2] = LODWORD(v191.m_flMatVal[2][1]);
          *(_QWORD *)&v163.m_flMatVal[0][2] = LODWORD(v191.m_flMatVal[2][0]);
          *(_QWORD *)&v163.m_flMatVal[0][0] = __PAIR64__(LODWORD(v191.m_flMatVal[1][0]), LODWORD(v191.m_flMatVal[0][0]));
          *(_QWORD *)&v163.m_flMatVal[2][2] = LODWORD(v191.m_flMatVal[2][2]);
          *(_QWORD *)&v163.m_flMatVal[1][0] = __PAIR64__(LODWORD(v191.m_flMatVal[1][1]), LODWORD(v191.m_flMatVal[0][1]));
          *(_QWORD *)&v163.m_flMatVal[2][0] = __PAIR64__(LODWORD(v191.m_flMatVal[1][2]), LODWORD(v191.m_flMatVal[0][2]));
          LODWORD(v163.m_flMatVal[3][0]) = COERCE_UNSIGNED_INT(
                                             (float)((float)(v191.m_flMatVal[0][0] * v191.m_flMatVal[3][0])
                                                   + (float)(v191.m_flMatVal[3][1] * v191.m_flMatVal[0][1]))
                                           + (float)(v191.m_flMatVal[3][2] * v191.m_flMatVal[0][2]))
                                         ^ _mask__NegFloat_;
          v163.m_flMatVal[3][3] = 1.0;
          *(_QWORD *)&v168.m_flMatVal[0][0] = 1065353216;
          v168.m_flMatVal[0][2] = 0.0;
          *(_QWORD *)&v168.m_flMatVal[1][1] = 1065353216;
          *(_QWORD *)&v168.m_flMatVal[2][1] = 0x3F80000000000000LL;
          memset(v168.m_flMatVal[3], 0, 12);
          v163.m_flMatVal[3][1] = -(float)((float)((float)(v191.m_flMatVal[3][1] * v191.m_flMatVal[1][1])
                                                 + (float)(v191.m_flMatVal[3][0] * v191.m_flMatVal[1][0]))
                                         + (float)(v191.m_flMatVal[3][2] * v191.m_flMatVal[1][2]));
          v163.m_flMatVal[3][2] = -(float)((float)((float)(v191.m_flMatVal[3][1] * v191.m_flMatVal[2][1])
                                                 + (float)(v191.m_flMatVal[3][0] * v191.m_flMatVal[2][0]))
                                         + (float)(v191.m_flMatVal[3][2] * v191.m_flMatVal[2][2]));
          M_ConcatTransforms(in1: &v165, in2: &v163, out: &v168);
          v180 = -v168.m_flMatVal[0][2];
          if ( fsqrt(1.0 - (float)(v180 * v180)) == 0.0 )
          {
            v54 = -v168.m_flMatVal[2][1];
            v198 = 0.0;
            v202 = 1.0;
          }
          else
          {
            v54 = v168.m_flMatVal[1][2];
            v198 = v168.m_flMatVal[0][1];
            v202 = v168.m_flMatVal[0][0];
          }
          __libm_sse2_atan2(y: v119, x: v139);
          *(float *)&v243 = v54;
          v55 = v198;
          __libm_sse2_atan2(y: v121, x: v140);
          *(float *)&v55 = v55;
          v244 = *(float *)&v55;
          v56 = *(float *)&v243;
          __libm_sse2_sin(x: v122);
          *(float *)&v56 = v56;
          v176 = LODWORD(v56);
          __libm_sse2_cos(x: v123);
          v57 = v180;
          __libm_sse2_atan2(y: v124, x: v141);
          *(float *)&v57 = v57;
          v58 = &pSource->rawanim[v252][v157];
          v59 = v244;
          HIDWORD(v243) = LODWORD(v57);
          *(_QWORD *)&v58->pos.x = *(_QWORD *)&v168.m_flMatVal[3][0];
          v58->pos.z = v168.m_flMatVal[3][2];
          *(_QWORD *)&v58->rot.x = v243;
          v60 = sqrt(1.0);
          v58->rot.z = v59;
          if ( v60 == 0.0 )
          {
            v200 = 0.0;
            v61 = 1065353216;
          }
          else
          {
            v200 = *(float *)&v159[17];
            v61 = v159[16];
          }
          v204 = v61;
          __libm_sse2_atan2(y: v125, x: v142);
          *(float *)&v243 = 0.0;
          v62 = v200;
          __libm_sse2_atan2(y: v126, x: v143);
          *(float *)&v62 = v62;
          v244 = *(float *)&v62;
          v63 = *(float *)&v243;
          __libm_sse2_sin(x: v127);
          *(float *)&v63 = v63;
          v189 = LODWORD(v63);
          __libm_sse2_cos(x: v128);
          __libm_sse2_atan2(y: v129, x: v144);
          v64 = v252;
          v65 = v244;
          v66 = (RadianEuler *)((char *)&pSource->rawanim[v252]->rot + LODWORD(v40));
          *((float *)&v243 + 1) = -0.0;
          *(_QWORD *)&v66->x = v243;
          v66->z = v65;
          v113 = pSource->rawanim[v64];
          *(_QWORD *)&v224.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v224.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v224.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v224.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v224.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v224.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v224.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v214.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v214.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v214.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v214.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v214.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v214.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v214.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v162.m_flMatVal[0][0] = 1065353216;
          v162.m_flMatVal[0][2] = 0.0;
          *(_QWORD *)&v162.m_flMatVal[1][1] = 1065353216;
          *(_QWORD *)&v162.m_flMatVal[2][1] = 0x3F80000000000000LL;
          CatBonePath(indexPath: (int *)&v156, boneArray: v113, resultMatrix: &v224, rootOffset: 1);
          v214.m_flMatVal[1][0] = v224.m_flMatVal[0][1];
          v214.m_flMatVal[0][0] = v224.m_flMatVal[0][0];
          *(_QWORD *)&v214.m_flMatVal[2][0] = __PAIR64__(LODWORD(v224.m_flMatVal[1][2]), LODWORD(v224.m_flMatVal[0][2]));
          *(_QWORD *)&v214.m_flMatVal[0][1] = __PAIR64__(LODWORD(v224.m_flMatVal[2][0]), LODWORD(v224.m_flMatVal[1][0]));
          *(_QWORD *)&v214.m_flMatVal[1][1] = __PAIR64__(LODWORD(v224.m_flMatVal[2][1]), LODWORD(v224.m_flMatVal[1][1]));
          v214.m_flMatVal[2][2] = v224.m_flMatVal[2][2];
          v214.m_flMatVal[3][0] = -(float)((float)((float)(v224.m_flMatVal[0][0] * v224.m_flMatVal[3][0])
                                                 + (float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[0][1]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[0][2]));
          v214.m_flMatVal[3][1] = -(float)((float)((float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[1][1])
                                                 + (float)(v224.m_flMatVal[3][0] * v224.m_flMatVal[1][0]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[1][2]));
          v214.m_flMatVal[3][2] = -(float)((float)((float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[2][1])
                                                 + (float)(v224.m_flMatVal[3][0] * v224.m_flMatVal[2][0]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[2][2]));
          M_ConcatTransforms(in1: &v170, in2: &v214, out: &v162);
          v67 = 1.0;
          v186 = -v162.m_flMatVal[0][2];
          if ( fsqrt(1.0 - (float)(v186 * v186)) == 0.0 )
          {
            v68 = -v162.m_flMatVal[2][1];
            v196 = 0.0;
          }
          else
          {
            v68 = v162.m_flMatVal[1][2];
            v196 = v162.m_flMatVal[0][1];
            v67 = v162.m_flMatVal[0][0];
          }
          v205 = v67;
          __libm_sse2_atan2(y: v130, x: v145);
          *(float *)&v243 = v68;
          v69 = v196;
          __libm_sse2_atan2(y: v131, x: v146);
          *(float *)&v69 = v69;
          v244 = *(float *)&v69;
          v70 = *(float *)&v243;
          __libm_sse2_sin(x: v132);
          *(float *)&v70 = v70;
          v188 = LODWORD(v70);
          __libm_sse2_cos(x: v133);
          v71 = v186;
          __libm_sse2_atan2(y: v134, x: v147);
          v72 = v252;
          v73 = pSource->rawanim[v252];
          ++ikSolves;
          v74 = (int)&v73->rot + v247;
          v75 = v244;
          *(float *)&v71 = v71;
          HIDWORD(v243) = LODWORD(v71);
          *(_QWORD *)v74 = v243;
          *(float *)(v74 + 8) = v75;
          v76 = v150[v72 + 2000];
          v151[v72] = pSource->rawanim[v72];
          v77 = v248;
          pSource->rawanim[v72] = v76;
          v248 = v77 + 1;
        }
        while ( v77 + 1 < pTemplate->numIKSolves );
      }
      v78 = *v253;
      v79 = *(float *)&v184;
      v80 = (char *)&v150[v252 + 2000];
      v219 = &v151[v252];
      v81 = *v219;
      *v253 = *v219;
      v82 = v183;
      v172 = *(_QWORD *)&v81[v183 / 0x18u].pos.x;
      v83 = v181;
      v84 = *(float *)&v172;
      v85 = *((float *)&v172 + 1) - *((float *)&v184 + 1);
      *(_DWORD *)v80 = v78;
      v173 = *(float *)((char *)&v81->pos.z + v82);
      v86 = (float)((float)(v83 - 1.0) * pTemplate->rootScaleAmount) + 1.0;
      v87 = (float)(v85 * v86) + *((float *)&v184 + 1);
      v88 = (float)((float)(v173 - toeFloorZ) * v86) + toeFloorZ;
      *(float *)((char *)&v81->pos.x + v82) = (float)((float)(v84 - v79) * v86) + v79;
      *(float *)((char *)&v81->pos.y + v82) = v87;
      *(float *)((char *)&v81->pos.z + v82) = v88;
      v14 = pTemplate->numPlaneConstraints <= 0;
      v254 = v80;
      v247 = 0;
      if ( !v14 )
      {
        ikSolves = (const char **)pTemplate->planeConstraints;
        do
        {
          v15 = (char *)*ikSolves;
          if ( g_verbose )
            printf(format: "Executing plane constraint: %s\n", *ikSolves);
          v248 = GetNodeIndex(psource: pSource, nodeName: v15);
          if ( v248 <= -1 )
            goto $LN1688;
          v89 = v248;
          v90 = &v155;
          v155 = v248;
          do
          {
            v89 = pSource->localBone[v89].parent;
            *++v90 = v89;
          }
          while ( v89 != -1 );
          v91 = v253;
          v90[1] = -1;
          v255 = v156;
          v114 = *v91;
          *(_QWORD *)&v223.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v223.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v223.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v223.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v223.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v223.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v223.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v250.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v250.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v250.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v250.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v250.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v250.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v250.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v224.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v224.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v224.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v224.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v224.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v224.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v224.m_flMatVal[3][2] = 0x3F80000000000000LL;
          *(_QWORD *)&v214.m_flMatVal[0][0] = 1065353216;
          *(_QWORD *)&v214.m_flMatVal[0][2] = 0;
          *(_QWORD *)&v214.m_flMatVal[1][0] = 0x3F80000000000000LL;
          memset(&v214.m_flMatVal[1][2], 0, 16);
          *(_QWORD *)&v214.m_flMatVal[2][2] = 1065353216;
          *(_QWORD *)&v214.m_flMatVal[3][0] = 0;
          *(_QWORD *)&v214.m_flMatVal[3][2] = 0x3F80000000000000LL;
          CatBonePath(indexPath: &v155, boneArray: v114, resultMatrix: &v223, rootOffset: 0);
          CatBonePath(indexPath: (int *)&v156, boneArray: *v253, resultMatrix: &v250, rootOffset: 0);
          CatBonePath(indexPath: &v157, boneArray: *v253, resultMatrix: &v224, rootOffset: 0);
          v214.m_flMatVal[0][0] = v224.m_flMatVal[0][0];
          v214.m_flMatVal[2][2] = v224.m_flMatVal[2][2];
          v214.m_flMatVal[1][0] = v224.m_flMatVal[0][1];
          *(_QWORD *)&v214.m_flMatVal[2][0] = __PAIR64__(LODWORD(v224.m_flMatVal[1][2]), LODWORD(v224.m_flMatVal[0][2]));
          v214.m_flMatVal[3][0] = -(float)((float)((float)(v224.m_flMatVal[3][0] * v224.m_flMatVal[0][0])
                                                 + (float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[0][1]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[0][2]));
          *(_QWORD *)&v214.m_flMatVal[1][1] = __PAIR64__(LODWORD(v224.m_flMatVal[2][1]), LODWORD(v224.m_flMatVal[1][1]));
          *(_QWORD *)&v214.m_flMatVal[0][1] = __PAIR64__(LODWORD(v224.m_flMatVal[2][0]), LODWORD(v224.m_flMatVal[1][0]));
          v214.m_flMatVal[3][1] = -(float)((float)((float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[1][1])
                                                 + (float)(v224.m_flMatVal[3][0] * v224.m_flMatVal[1][0]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[1][2]));
          v214.m_flMatVal[3][2] = -(float)((float)((float)(v224.m_flMatVal[3][1] * v224.m_flMatVal[2][1])
                                                 + (float)(v224.m_flMatVal[3][0] * v224.m_flMatVal[2][0]))
                                         + (float)(v224.m_flMatVal[3][2] * v224.m_flMatVal[2][2]));
          v92 = *((float *)v15 + 256);
          v93 = *((_DWORD *)v15 + 257);
          if ( v92 > v223.m_flMatVal[3][v93] )
          {
            if ( v92 <= v250.m_flMatVal[3][v93] )
            {
              v94 = *((_DWORD *)v15 + 257);
              v95 = *v253;
              v211 = v250.m_flMatVal[3][0];
              v166 = v250.m_flMatVal[3][0];
              v193 = *(_QWORD *)&v223.m_flMatVal[3][0];
              v194 = v223.m_flMatVal[3][2];
              v94 *= 4;
              v212 = *(_QWORD *)&v250.m_flMatVal[3][1];
              v167 = *(_QWORD *)&v250.m_flMatVal[3][1];
              v96 = *((float *)v15 + 256);
              v97 = (float)(*(float *)((char *)&v166 + v94) - v96) * (float)(*(float *)((char *)&v166 + v94) - v96);
              v98 = v95[v248].pos.x;
              *(float *)((char *)&v193 + v94) = v96;
              *(float *)((char *)&v211 + v94) = v96;
              v177 = fsqrt((float)(v98 * v98) - v97);
              v192.x = *(float *)&v193 - v211;
              v192.y = *((float *)&v193 + 1) - *(float *)&v212;
              v192.z = v194 - *((float *)&v212 + 1);
              VectorNormalize(vec: &v192);
              v241.x = (float)((float)(v177 * v192.x) + v211) - v250.m_flMatVal[3][0];
              v245 = *(Vector *)&v250.m_flMatVal[2][0];
              v241.y = (float)((float)(v192.y * v177) + *(float *)&v212) - v250.m_flMatVal[3][1];
              v241.z = (float)((float)(v192.z * v177) + *((float *)&v212 + 1)) - v250.m_flMatVal[3][2];
              VectorNormalize(vec: &v241);
              VectorNormalize(vec: &v245);
              v213.x = (float)(v245.y * v241.z) - (float)(v245.z * v241.y);
              v213.y = (float)(v245.z * v241.x) - (float)(v241.z * v245.x);
              v213.z = (float)(v241.y * v245.x) - (float)(v245.y * v241.x);
              VectorNormalize(vec: &v213);
              v245.x = (float)(v213.z * v241.y) - (float)(v213.y * v241.z);
              v245.y = (float)(v241.z * v213.x) - (float)(v213.z * v241.x);
              v245.z = (float)(v213.y * v241.x) - (float)(v241.y * v213.x);
              VectorNormalize(vec: &v245);
              *(Vector *)&v250.m_flMatVal[0][0] = v241;
              *(Vector *)&v250.m_flMatVal[2][0] = v245;
              *(Vector *)&v250.m_flMatVal[1][0] = v213;
              *(_QWORD *)&v161.m_flMatVal[0][0] = 1065353216;
              v161.m_flMatVal[0][2] = 0.0;
              *(_QWORD *)&v161.m_flMatVal[1][1] = 1065353216;
              *(_QWORD *)&v161.m_flMatVal[2][1] = 0x3F80000000000000LL;
              M_ConcatTransforms(in1: &v250, in2: &v214, out: &v161);
              v187 = -v161.m_flMatVal[0][2];
              if ( fsqrt(1.0 - (float)(v187 * v187)) == 0.0 )
              {
                v99 = -v161.m_flMatVal[2][1];
                v197 = 0.0;
                v195 = 1.0;
              }
              else
              {
                v99 = v161.m_flMatVal[1][2];
                v197 = v161.m_flMatVal[0][1];
                v195 = v161.m_flMatVal[0][0];
              }
              __libm_sse2_atan2(y: v116, x: v139);
              *(float *)&v243 = v99;
              v100 = v197;
              __libm_sse2_atan2(y: v135, x: v148);
              *(float *)&v100 = v100;
              v244 = *(float *)&v100;
              v101 = *(float *)&v243;
              __libm_sse2_sin(x: v136);
              *(float *)&v101 = v101;
              v175 = LODWORD(v101);
              __libm_sse2_cos(x: v137);
              v102 = v187;
              __libm_sse2_atan2(y: v138, x: v149);
              *(float *)&v102 = v102;
              p_rot = (int)&(*v253)[LODWORD(v255)].rot;
              v104 = v244;
              HIDWORD(v243) = LODWORD(v102);
              *(_QWORD *)p_rot = v243;
              *(float *)(p_rot + 8) = v104;
            }
            else
            {
              printf(format: "Error: Constraint parent has broken the plane, this frame's plane constraint unsolvable!\n");
            }
          }
          ++ikSolves;
          ++v247;
        }
        while ( v247 < pTemplate->numPlaneConstraints );
        v80 = v254;
      }
      v105 = v253;
      v106 = *(s_bone_t **)v80;
      *v219 = *v253;
      v107 = v252 + 1;
      *v105 = v106;
      v252 = v107;
      v253 = v105 + 1;
    }
    while ( v107 < v217 );
    numframes = v217;
    qmemcpy(rawanim, v151, 4 * v217);
    v6 = pTarget;
  }
  v6->numframes = numframes;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00409CB0
// Name: void Save_SMD(char const __near *,struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Save_SMD(const char *filename, s_source_t *source)
{
  void *v2; // eax
  void *v3; // esi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::Printf(this: &buf, pFmt: "version 1\n");
  SaveNodes(source, &buf);
  SaveAnimation(source, &buf);
  v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: filename, a3: "wb", a4: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    g_pFileSystem->Write(this: g_pFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v2);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00409EB0
// Name: void CalcModelTangentSpaces(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcModelTangentSpaces(s_source_t *pSrc)
{
  s_source_t *v1; // esi
  Vector *v2; // edi
  s_mesh_t *v3; // ebx
  int v4; // ecx
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v6; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v9; // eax
  int *v10; // edi
  int v11; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v12; // esi
  int v13; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  int *v16; // edi
  int v17; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v18; // esi
  int v19; // eax
  CUtlSymbolTable::StringPool_t **v20; // ecx
  int v21; // eax
  int v22; // ecx
  int *v23; // edi
  int numfaces; // esi
  int v25; // eax
  int v26; // ecx
  int v27; // esi
  int v28; // ecx
  Vector4D *v29; // edx
  s_face_t *v30; // eax
  s_face_t *v31; // eax
  int *p_m_Size; // esi
  int v33; // eax
  float v34; // xmm0_4
  const Vector *v35; // ebx
  float v36; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  int v41; // eax
  Vector *v42; // ecx
  Vector *v43; // ecx
  int v44; // eax
  int *v45; // edx
  Vector *vertex; // ecx
  int v47; // eax
  Vector *v48; // ecx
  Vector *v49; // ecx
  Vector4D *v50; // eax
  int v51; // xmm0_4
  s_mesh_t *v52; // ecx
  s_face_t *v53; // ecx
  int numvertices; // [esp-8h] [ebp-A8h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > triSVect; // [esp+14h] [ebp-8Ch] BYREF
  const Vector *normal; // [esp+28h] [ebp-78h]
  int *v57; // [esp+2Ch] [ebp-74h]
  Vector vertPos1; // [esp+30h] [ebp-70h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > vertToTriMap; // [esp+3Ch] [ebp-64h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > triTVect; // [esp+50h] [ebp-50h] BYREF
  int vertID2; // [esp+64h] [ebp-3Ch]
  int meshID; // [esp+68h] [ebp-38h]
  unsigned int v63; // [esp+6Ch] [ebp-34h]
  s_mesh_t *pMesh; // [esp+70h] [ebp-30h]
  unsigned int v65; // [esp+74h] [ebp-2Ch]
  int *meshindex; // [esp+78h] [ebp-28h]
  Vector4D *finalSVect; // [esp+7Ch] [ebp-24h]
  Vector tVect; // [esp+80h] [ebp-20h] BYREF
  s_face_t *pFace; // [esp+8Ch] [ebp-14h]
  Vector sVect; // [esp+90h] [ebp-10h] BYREF
  int triID; // [esp+9Ch] [ebp-4h]

  v1 = pSrc;
  v2 = nullptr;
  meshID = 0;
  if ( pSrc->nummeshes > 0 )
  {
    meshindex = pSrc->meshindex;
    while ( 1 )
    {
      numvertices = v1->mesh[*meshindex].numvertices;
      pMesh = &v1->mesh[*meshindex];
      v3 = pMesh;
      memset(&vertToTriMap, 0, sizeof(vertToTriMap));
      CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::InsertMultipleBefore(
        this: &vertToTriMap,
        elem: 0,
        num: numvertices);
      v4 = 0;
      triID = 0;
      if ( v3->numfaces > 0 )
      {
        while ( 1 )
        {
          pFace = &v1->face[v4 + v3->faceoffset];
          m_Size = vertToTriMap.m_Memory.m_pMemory[pFace->a].m_Size;
          v6 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertToTriMap.m_Memory.m_pMemory[pFace->a];
          m_nAllocationCount = v6->m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<int,int>::Grow(this: v6, num: m_Size - m_nAllocationCount + 1);
          ++v6[1].m_pMemory;
          m_pMemory = v6->m_pMemory;
          v9 = (int)v6[1].m_pMemory - m_Size - 1;
          v6[1].m_nAllocationCount = (int)v6->m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
          v10 = (int *)&v6->m_pMemory[m_Size];
          if ( v10 != nullptr )
            *v10 = triID;
          v11 = vertToTriMap.m_Memory.m_pMemory[pFace->b].m_Size;
          v12 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertToTriMap.m_Memory.m_pMemory[pFace->b];
          v13 = v12->m_nAllocationCount;
          if ( v11 + 1 > v13 )
            CUtlMemory<int,int>::Grow(this: v12, num: v11 - v13 + 1);
          ++v12[1].m_pMemory;
          v14 = v12->m_pMemory;
          v15 = (int)v12[1].m_pMemory - v11 - 1;
          v12[1].m_nAllocationCount = (int)v12->m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &v14[v11 + 1], src: &v14[v11], count: 4 * v15);
          v16 = (int *)&v12->m_pMemory[v11];
          if ( v16 != nullptr )
            *v16 = triID;
          v17 = vertToTriMap.m_Memory.m_pMemory[pFace->c].m_Size;
          v18 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertToTriMap.m_Memory.m_pMemory[pFace->c];
          v19 = v18->m_nAllocationCount;
          if ( v17 + 1 > v19 )
            CUtlMemory<int,int>::Grow(this: v18, num: v17 - v19 + 1);
          ++v18[1].m_pMemory;
          v20 = v18->m_pMemory;
          v21 = (int)v18[1].m_pMemory - v17 - 1;
          v18[1].m_nAllocationCount = (int)v18->m_pMemory;
          if ( v21 > 0 )
            _V_memmove(dest: &v20[v17 + 1], src: &v20[v17], count: 4 * v21);
          v22 = triID;
          v23 = (int *)&v18->m_pMemory[v17];
          if ( v23 != nullptr )
            *v23 = triID;
          v4 = v22 + 1;
          triID = v4;
          if ( v4 >= v3->numfaces )
            break;
          v1 = pSrc;
        }
        v2 = nullptr;
      }
      numfaces = v3->numfaces;
      v25 = 0;
      v26 = 0;
      memset(&triSVect, 0, sizeof(triSVect));
      memset(&triTVect, 0, sizeof(triTVect));
      if ( numfaces != 0 )
      {
        if ( numfaces > 0 )
        {
          CUtlMemory<Vector,int>::Grow(this: &triSVect.m_Memory, num: numfaces);
          v25 = triSVect.m_Size;
          v2 = triSVect.m_Memory.m_pMemory;
          v26 = triTVect.m_Size;
        }
        if ( v25 > 0 && numfaces > 0 )
        {
          _V_memmove(dest: &v2[numfaces], src: v2, count: 12 * v25);
          v26 = triTVect.m_Size;
        }
      }
      v27 = v3->numfaces;
      if ( v27 != 0 )
      {
        if ( v27 > 0 )
        {
          CUtlMemory<Vector,int>::Grow(this: &triTVect.m_Memory, num: v3->numfaces);
          v26 = triTVect.m_Size;
        }
        if ( v26 > 0 && v27 > 0 )
          _V_memmove(dest: &triTVect.m_Memory.m_pMemory[v27], src: triTVect.m_Memory.m_pMemory, count: 12 * v26);
      }
      v28 = 0;
      triID = 0;
      if ( v3->numfaces > 0 )
      {
        v29 = (Vector4D *)((char *)triTVect.m_Memory.m_pMemory - (char *)v2);
        for ( finalSVect = (Vector4D *)((char *)triTVect.m_Memory.m_pMemory - (char *)v2); ; v29 = finalSVect )
        {
          v30 = &pSrc->face[v28 + v3->faceoffset];
          CalcTriangleTangentSpace(
            v3: v3->vertexoffset + v30->c,
            sVect: v2,
            tVect: (Vector *)((char *)v2 + (_DWORD)v29),
            pSrc,
            v1: v3->vertexoffset + v30->a,
            v2: v3->vertexoffset + v30->b);
          v3 = pMesh;
          v28 = triID + 1;
          ++v2;
          triID = v28;
          if ( v28 >= pMesh->numfaces )
            break;
        }
        v2 = triSVect.m_Memory.m_pMemory;
      }
      v31 = (s_face_t *)v3->numvertices;
      triID = 0;
      pFace = v31;
      if ( (int)v31 > 0 )
      {
        p_m_Size = &vertToTriMap.m_Memory.m_pMemory->m_Size;
        v63 = 0;
        v57 = &vertToTriMap.m_Memory.m_pMemory->m_Size;
        while ( 1 )
        {
          v33 = v3->vertexoffset + triID;
          v34 = 0.0;
          v35 = &pSrc->normal[v33];
          v36 = 0.0;
          finalSVect = &pSrc->tangentS[v33];
          v37 = 0.0;
          v38 = 0.0;
          v39 = 0.0;
          v40 = 0.0;
          v41 = 0;
          memset(&sVect, 0, sizeof(sVect));
          memset(&tVect, 0, sizeof(tVect));
          normal = v35;
          if ( *p_m_Size > 0 )
          {
            do
            {
              v36 = v36 + v2[*(_DWORD *)(*(p_m_Size - 3) + 4 * v41)].x;
              v42 = &v2[*(_DWORD *)(*(p_m_Size - 3) + 4 * v41)];
              sVect.x = v36;
              v34 = v34 + v42->y;
              sVect.y = v34;
              v37 = v37 + v42->z;
              sVect.z = v37;
              v38 = v38 + triTVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v41)].x;
              v43 = &triTVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v41)];
              tVect.x = v38;
              v39 = v39 + v43->y;
              tVect.y = v39;
              v40 = v40 + v43->z;
              ++v41;
              tVect.z = v40;
            }
            while ( v41 < *p_m_Size );
          }
          if ( g_bZBrush )
          {
            vertPos1 = pSrc->vertex[v63 / 0xC];
            v44 = 0;
            vertID2 = 0;
            if ( (int)pFace > 0 )
            {
              v45 = v57;
              v65 = 0;
              do
              {
                if ( v44 != triID )
                {
                  vertex = pSrc->vertex;
                  if ( vertex[v65 / 0xC].x == vertPos1.x
                    && vertex[v65 / 0xC].y == vertPos1.y
                    && vertex[v65 / 0xC].z == vertPos1.z )
                  {
                    v47 = 0;
                    if ( *v45 > 0 )
                    {
                      do
                      {
                        v36 = v36 + v2[*(_DWORD *)(*(v45 - 3) + 4 * v47)].x;
                        v48 = &v2[*(_DWORD *)(*(v45 - 3) + 4 * v47)];
                        sVect.x = v36;
                        v34 = v34 + v48->y;
                        sVect.y = v34;
                        v37 = v37 + v48->z;
                        sVect.z = v37;
                        v38 = v38 + triTVect.m_Memory.m_pMemory[*(_DWORD *)(*(v45 - 3) + 4 * v47)].x;
                        v49 = &triTVect.m_Memory.m_pMemory[*(_DWORD *)(*(v45 - 3) + 4 * v47)];
                        tVect.x = v38;
                        v39 = v39 + v49->y;
                        tVect.y = v39;
                        v40 = v40 + v49->z;
                        ++v47;
                        tVect.z = v40;
                      }
                      while ( v47 < *v45 );
                      v35 = normal;
                    }
                  }
                }
                v65 += 12;
                v44 = vertID2 + 1;
                v45 += 5;
                vertID2 = v44;
              }
              while ( v44 < (int)pFace );
            }
          }
          if ( (float)((float)((float)(v35->y * (float)((float)(v37 * v38) - (float)(v40 * v36)))
                             + (float)(v35->x * (float)((float)(v40 * v34) - (float)(v39 * v37))))
                     + (float)(v35->z * (float)((float)(v39 * v36) - (float)(v34 * v38)))) < 0.0 )
          {
            tVect.x = (float)(v35->z * v34) - (float)(v35->y * v37);
            tVect.y = (float)(v37 * v35->x) - (float)(v35->z * v36);
            tVect.z = (float)(v35->y * v36) - (float)(v34 * v35->x);
            sVect.x = (float)(v35->y * tVect.z) - (float)(v35->z * tVect.y);
            sVect.y = (float)(v35->z * tVect.x) - (float)(tVect.z * v35->x);
            sVect.z = (float)(tVect.y * v35->x) - (float)(v35->y * tVect.x);
            VectorNormalize(vec: &sVect);
            VectorNormalize(vec: &tVect);
            v50 = finalSVect;
            finalSVect->x = sVect.x;
            v50->y = sVect.y;
            v50->z = sVect.z;
            v51 = -1082130432;
          }
          else
          {
            tVect.x = (float)(v35->y * v37) - (float)(v35->z * v34);
            tVect.y = (float)(v35->z * v36) - (float)(v37 * v35->x);
            tVect.z = (float)(v34 * v35->x) - (float)(v35->y * v36);
            sVect.x = (float)(v35->z * tVect.y) - (float)(v35->y * tVect.z);
            sVect.y = (float)(tVect.z * v35->x) - (float)(v35->z * tVect.x);
            sVect.z = (float)(v35->y * tVect.x) - (float)(tVect.y * v35->x);
            VectorNormalize(vec: &sVect);
            VectorNormalize(vec: &tVect);
            v50 = finalSVect;
            finalSVect->x = sVect.x;
            v50->y = sVect.y;
            v50->z = sVect.z;
            v51 = 1065353216;
          }
          v52 = pMesh;
          v63 += 12;
          LODWORD(v50->w) = v51;
          v53 = (s_face_t *)v52->numvertices;
          p_m_Size += 5;
          ++triID;
          pFace = v53;
          if ( triID >= (int)v53 )
            break;
          v3 = pMesh;
        }
      }
      if ( triTVect.m_Memory.m_nGrowSize >= 0 && triTVect.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: triTVect.m_Memory.m_pMemory);
      if ( triSVect.m_Memory.m_nGrowSize >= 0 && v2 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
      CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::RemoveAll(this: &vertToTriMap);
      if ( vertToTriMap.m_Memory.m_nGrowSize >= 0 && vertToTriMap.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertToTriMap.m_Memory.m_pMemory);
      ++meshindex;
      if ( ++meshID >= pSrc->nummeshes )
        break;
      v1 = pSrc;
      v2 = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A640
// Name: void BuildIndividualMeshes(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildIndividualMeshes(int psource)
{
  signed int v1; // ecx
  int v2; // edi
  int j; // eax
  signed int v4; // eax
  int m; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  Vector *v9; // edx
  int v10; // eax
  Vector *v11; // ebx
  Vector *v12; // edx
  Vector *v13; // ebx
  signed int v14; // ecx
  int n; // eax
  int v16; // ecx
  int ii; // eax
  int *v18; // eax
  int jj; // ecx
  int v20; // edx
  int v21; // eax
  char *v22; // eax
  int kk; // eax
  int material; // ecx
  int v25; // ecx
  unsigned __int8 *v26; // eax
  int v27; // edx
  int *v28; // eax
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  unsigned int v32; // edi
  unsigned int v33; // [esp-24h] [ebp-3Ch]
  unsigned int v34; // [esp-8h] [ebp-20h]
  int k; // [esp+Ch] [ebp-Ch]
  int ka; // [esp+Ch] [ebp-Ch]
  int v37; // [esp+10h] [ebp-8h]
  int v38; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]
  int ia; // [esp+20h] [ebp+8h]

  v1 = numvlist;
  v2 = 0;
  for ( j = 0; j < v1; ++j )
    v_listsort[j] = j;
  qsort(base: v_listsort, num: v1, width: 4u, comp: (int (__cdecl *)(const void *, const void *))vlistCompare);
  v4 = numvlist;
  for ( m = 0; m < v4; ++m )
    v_ilistsort[v_listsort[m]] = m;
  *(_DWORD *)(psource + 101780) = v4;
  k_memtotal += 28 * v4;
  *(_DWORD *)(psource + 101784) = calloc(count: v4, size: 0x1Cu);
  v7 = *(_DWORD *)(psource + 101780);
  *(_DWORD *)(psource + 101788) = 0;
  k_memtotal += 24 * v7;
  *(_DWORD *)(psource + 101792) = calloc(count: v7, size: 0x18u);
  *(_DWORD *)(psource + 101796) = operator new(nSize: 12 * *(_DWORD *)(psource + 101780));
  *(_DWORD *)(psource + 101800) = operator new(nSize: 12 * *(_DWORD *)(psource + 101780));
  *(_DWORD *)(psource + 101804) = operator new(nSize: 16 * *(_DWORD *)(psource + 101780));
  v33 = *(_DWORD *)(psource + 101780);
  k_memtotal += 8 * v33;
  *(_DWORD *)(psource + 101808) = calloc(count: v33, size: 8u);
  i = 0;
  if ( *(int *)(psource + 101780) > 0 )
  {
    k = 0;
    v37 = 0;
    v38 = 0;
    v8 = 8;
    do
    {
      v9 = (Vector *)(v38 + *(_DWORD *)(psource + 101796));
      v10 = v_listsort[v2];
      v11 = &g_vertex[v_listdata[v10].v];
      v9->x = v11->x;
      v9->y = v11->y;
      v9->z = v11->z;
      v12 = (Vector *)(v38 + *(_DWORD *)(psource + 101800));
      v13 = &g_normal[v_listdata[v10].n];
      v12->x = v13->x;
      v12->y = v13->y;
      v12->z = v13->z;
      *(float *)(*(_DWORD *)(psource + 101808) + 8 * v2) = g_texcoord[v_listdata[v10].t].x;
      *(float *)(*(_DWORD *)(psource + 101808) + 8 * v2 + 4) = dword_BC05F4[2 * v_listdata[v10].t];
      *(_DWORD *)(v37 + *(_DWORD *)(psource + 101784)) = g_bone[v_listdata[v10].v].numbones;
      *(_DWORD *)(v8 + *(_DWORD *)(psource + 101784) - 4) = dword_70E8D4[7 * v_listdata[v10].v];
      *(float *)(v8 + *(_DWORD *)(psource + 101784) + 8) = *(float *)&dword_70E8E0[7 * v_listdata[v10].v];
      *(_DWORD *)(v8 + *(_DWORD *)(psource + 101784)) = dword_70E8D8[7 * v_listdata[v10].v];
      *(float *)(v8 + *(_DWORD *)(psource + 101784) + 12) = flt_70E8E4[7 * v_listdata[v10].v];
      *(_DWORD *)(v8 + *(_DWORD *)(psource + 101784) + 4) = dword_70E8DC[7 * v_listdata[v10].v];
      *(float *)(v8 + *(_DWORD *)(psource + 101784) + 16) = flt_70E8E8[7 * v_listdata[v10].v];
      *(_DWORD *)(k + *(_DWORD *)(psource + 101792)) = v_listdata[v10].m;
      v38 += 12;
      v37 += 28;
      *(_DWORD *)(k + *(_DWORD *)(psource + 101792) + 4) = v_listdata[v10].firstref;
      *(_DWORD *)(k + *(_DWORD *)(psource + 101792) + 8) = v_listdata[v10].lastref;
      v2 = i + 1;
      v8 += 28;
      i = v2;
      k += 24;
    }
    while ( v2 < *(_DWORD *)(psource + 101780) );
  }
  v14 = g_numfaces;
  for ( n = 0; n < v14; ++n )
    facesort[n] = n;
  qsort(base: facesort, num: v14, width: 4u, comp: (int (__cdecl *)(const void *, const void *))faceCompare);
  v16 = g_numfaces;
  for ( ii = 0; ii < v16; ++ii )
    ifacesort[facesort[ii]] = ii;
  *(_DWORD *)(psource + 101812) = v16;
  v18 = (int *)(psource + 101272);
  for ( jj = 8; jj != 0; --jj )
  {
    *(v18 - 1) = 0;
    *v18 = *(_DWORD *)(psource + 101780);
    v18[1] = 0;
    v18[2] = g_numfaces;
    v18[3] = 0;
    v18[4] = *(_DWORD *)(psource + 101780);
    v18[5] = 0;
    v18[6] = g_numfaces;
    v18[7] = 0;
    v18[8] = *(_DWORD *)(psource + 101780);
    v18[9] = 0;
    v18[10] = g_numfaces;
    v18[11] = 0;
    v18[12] = *(_DWORD *)(psource + 101780);
    v18[13] = 0;
    v18[14] = g_numfaces;
    v18 += 16;
  }
  if ( *(int *)(psource + 101780) > 0 )
  {
    v20 = 0;
    do
    {
      v21 = 16 * *(_DWORD *)(v20 + *(_DWORD *)(psource + 101792));
      ++*(_DWORD *)(v21 + psource + 101268);
      v22 = (char *)(psource + v21);
      if ( *((_DWORD *)v22 + 25318) > jj )
        *((_DWORD *)v22 + 25318) = jj;
      ++jj;
      v20 += 24;
    }
    while ( jj < *(_DWORD *)(psource + 101780) );
  }
  for ( kk = 0; kk < *(_DWORD *)(psource + 101812); ++kk )
  {
    material = g_face[facesort[kk]].material;
    ++*(_DWORD *)(psource + 16 * material + 101276);
    v25 = 2 * (material + 6330);
    if ( *(_DWORD *)(psource + 8 * v25) > kk )
      *(_DWORD *)(psource + 8 * v25) = kk;
  }
  v34 = *(_DWORD *)(psource + 101812);
  k_memtotal += 12 * v34;
  v26 = calloc(count: v34, size: 0xCu);
  v27 = 0;
  *(_DWORD *)(psource + 101816) = v26;
  ka = 0;
  v28 = (int *)(psource + 101280);
  do
  {
    if ( *(v28 - 1) != 0 )
    {
      *(_DWORD *)(psource + 4 * *(_DWORD *)(psource + 101136) + 101140) = v27;
      v29 = *v28;
      ia = *v28;
      if ( *v28 < *v28 + *(v28 - 1) )
      {
        v30 = 12 * v29;
        do
        {
          v31 = 6 * facesort[v29];
          v32 = v_ilistsort[*(unsigned int *)((char *)&g_src_uface[0].a + 2 * v31)] - *(v28 - 2);
          v31 *= 2;
          *(_DWORD *)(v30 + *(_DWORD *)(psource + 101816)) = v32;
          *(_DWORD *)(v30 + *(_DWORD *)(psource + 101816) + 4) = v_ilistsort[*(int *)((char *)&dword_64E83C + v31)]
                                                               - *(v28 - 2);
          *(_DWORD *)(v30 + *(_DWORD *)(psource + 101816) + 8) = v_ilistsort[*(int *)((char *)&dword_64E840 + v31)]
                                                               - *(v28 - 2);
          v29 = ia + 1;
          v30 += 12;
          ia = v29;
        }
        while ( v29 < *v28 + *(v28 - 1) );
        v27 = ka;
      }
      ++*(_DWORD *)(psource + 101136);
    }
    ++v27;
    v28 += 4;
    ka = v27;
  }
  while ( v27 < 32 );
  CalcModelTangentSpaces(pSrc: (s_source_t *)psource);
}

//------------------------------------------------------------------------------
// Address: 0x0040ABD0
// Name: void Grab_Triangles(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Grab_Triangles(s_source_t *psource)
{
  signed int i; // esi
  int v2; // esi
  const char *v3; // edi
  int v4; // esi
  char *v5; // eax
  char v6; // cl
  int v7; // esi
  char *v8; // eax
  char v9; // cl
  int v10; // eax
  int *p_material; // ecx
  int v12; // edx
  int v13; // esi
  unsigned int v14; // eax
  char texturename[64]; // [esp+4h] [ebp-4Ch] BYREF
  s_face_t f; // [esp+44h] [ebp-Ch] BYREF

  g_numfaces = 0;
  numvlist = 0;
  while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) != nullptr )
  {
    ++g_iLinecount;
    if ( strncmp(first: "end", last: g_szLine, count: 3u) == 0 && (byte_BBF5CB == 0 || byte_BBF5CB == 10) )
      break;
    if ( (int)strlen(g_szLine) < 64 )
    {
      strncpy(dest: (unsigned __int8 *)texturename, source: (unsigned __int8 *)g_szLine, count: 0x3Fu);
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
            v7 = v2;
            v8 = defaulttexture[v7];
            do
            {
              v9 = *v8;
              v8[texturename - defaulttexture[v7]] = *v8;
              ++v8;
            }
            while ( v9 != 0 );
            goto LABEL_21;
          }
          ++v2;
          v3 += 260;
          if ( v2 >= numrep )
            goto LABEL_21;
        }
        v4 = v2;
        v5 = defaulttexture[v4];
        do
        {
          v6 = *v5;
          v5[texturename - defaulttexture[v4]] = *v5;
          ++v5;
        }
        while ( v6 != 0 );
      }
LABEL_21:
      if ( texturename[0] != 0
        && _V_stricmp(s1: texturename, s2: "null.bmp") != 0
        && _V_stricmp(s1: texturename, s2: "null.tga") != 0 )
      {
        v10 = lookup_texture(texturename, maxlen: 64);
        p_material = &g_texture[v10].material;
        psource->texmap[v10] = v10;
        if ( *p_material == -1 )
        {
          v12 = g_nummaterials;
          g_material[g_nummaterials] = v10;
          *p_material = v12;
          g_nummaterials = v12 + 1;
        }
        v13 = *p_material;
        ParseFaceData(psource, material: *p_material, pFace: &f);
        v14 = g_numfaces;
        g_src_uface[g_numfaces] = f;
        g_face[v14].material = v13;
        g_numfaces = v14 + 1;
      }
      else
      {
        fgets(string: g_szLine, count: 4096, str: g_fpInput);
        fgets(string: g_szLine, count: 4096, str: g_fpInput);
        fgets(string: g_szLine, count: 4096, str: g_fpInput);
        g_iLinecount += 3;
      }
    }
    else
    {
      MdlWarning(fmt: "Unexpected data at line %d, (need a texture name) ignoring...\n", g_iLinecount);
    }
  }
  BuildIndividualMeshes((int)psource);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE60
// Name: int Load_SMD(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_SMD(s_source_t *psource)
{
  int result; // eax
  int v2; // eax
  char cmd[1024]; // [esp+4h] [ebp-404h] BYREF
  int option; // [esp+404h] [ebp-4h] BYREF

  result = OpenGlobalFile(src: psource->filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "SMD MODEL %s\n", psource->filename);
    g_iLinecount = 0;
    while ( fgets(string: g_szLine, count: 4096, str: g_fpInput) != nullptr )
    {
      ++g_iLinecount;
      v2 = sscanf(string: g_szLine, format: "%s %d", cmd, &option);
      if ( v2 != -1 && v2 != 0 )
      {
        if ( strcmp(cmd, "version") == 0 )
        {
          if ( option != 1 )
            MdlError(fmt: "bad version\n");
        }
        else if ( strcmp(cmd, "nodes") == 0 )
        {
          psource->numbones = Grab_Nodes(pnodes: psource->localBone);
        }
        else if ( strcmp(cmd, "skeleton") == 0 )
        {
          Grab_Animation((int)psource);
        }
        else if ( strcmp(cmd, "triangles") == 0 )
        {
          Grab_Triangles(psource);
        }
        else if ( strcmp(cmd, "vertexanimation") == 0 )
        {
          Grab_Vertexanimation(psource);
        }
        else
        {
          MdlWarning(fmt: "unknown studio command\n");
        }
      }
    }
    fclose(stream: g_fpInput);
    is_v1support = 1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B0A0
// Name: struct s_source_t __near * Load_Source(char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
s_source_t *__cdecl Load_Source(const char *name, char *ext, bool reverse, bool isActiveModel)
{
  unsigned int v4; // kr00_4
  void *v5; // esp
  s_source_t *v6; // eax
  char v8[12]; // [esp+0h] [ebp-2Ch] BYREF
  char xext[32]; // [esp+Ch] [ebp-20h] BYREF

  if ( g_numsources >= 1524 )
    MdlError(fmt: "Load_Source( %s ) - overflowed g_numsources.", name);
  v4 = strlen(name);
  v5 = alloca(v4 + 1);
  strcpy(v8, name);
  V_ExtractFileExtension(path: v8, dest: xext, destSize: 32);
  if ( xext[0] != 0 )
    V_StripExtension(in: v8, out: v8, outSize: v4 + 1);
  else
    strncpy(dest: (unsigned __int8 *)xext, source: (unsigned __int8 *)ext, count: 0x20u);
  k_memtotal += 125848;
  v6 = (s_source_t *)calloc(count: 1u, size: 0x1EB98u);
  g_source[g_numsources] = v6;
  strncpy(dest: (unsigned __int8 *)v6, source: (unsigned __int8 *)g_szFilename, count: 0x104u);
  if ( isActiveModel )
    g_source[g_numsources]->isActiveModel = true;
  if ( xext[0] != 0 && _V_stricmp(s1: xext, s2: "smd") != 0
    || (V_snprintf(pDest: g_szFilename, maxLen: 1024, pFormat: "%s%s.smd", cddir[numdirs], v8),
        strncpy(dest: (unsigned __int8 *)g_source[g_numsources], source: (unsigned __int8 *)g_szFilename, count: 0x104u),
        Load_SMD(psource: g_source[g_numsources]) == 0) )
  {
    MdlError(fmt: "could not load file '%s'\n", g_source[g_numsources]->filename);
  }
  ++g_numsources;
  if ( reverse )
    FlipFacing(pSrc: *(&g_numtextures + g_numsources));
  return *(&g_numtextures + g_numsources);
}

//------------------------------------------------------------------------------
// Address: 0x0040B240
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int m_Size; // ebx
  void (__thiscall ***v4)(_DWORD, int, const char **); // eax
  const char **v5; // esi
  int v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  char *v9; // edx
  char v10; // cl
  int v11; // esi
  CUtlSymbol *m_pMemory; // ecx
  CUtlSymbol *v13; // eax
  double v14; // rdi
  char *v15; // eax
  char *v16; // edx
  char v17; // cl
  const char *v18; // eax
  const char *v19; // eax
  int v20; // eax
  char v21; // cl
  char *v22; // eax
  char *v23; // edx
  char v24; // cl
  char *v25; // eax
  char *v26; // edx
  char v27; // cl
  const char *v28; // eax
  const char *v29; // eax
  s_source_t *Source; // ebx
  unsigned __int8 *v31; // eax
  s_source_t *v32; // eax
  const char *v33; // eax
  const char *v35; // [esp+20h] [ebp-434h]
  char templateFileName[1024]; // [esp+34h] [ebp-420h] BYREF
  int useTemplate; // [esp+434h] [ebp-20h]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > filenames; // [esp+438h] [ebp-1Ch] BYREF
  CUtlSymbol sym; // [esp+44Ch] [ebp-8h] BYREF
  int v40; // [esp+450h] [ebp-4h]
  int savedregs; // [esp+454h] [ebp+0h] BYREF
  CUtlSymbol *argca; // [esp+45Ch] [ebp+8h]

  m_Size = 0;
  useTemplate = 0;
  vprint(depth: 0, fmt: "Valve Software - motionmapper.exe ((c) Valve Coroporation %s)\n", "Dec 28 2010");
  vprint(depth: 0, fmt: "--- Maps motion from one animation/skeleton onto another skeleton ---\n");
  v4 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  v5 = argv;
  (**v4)(a1: v4, a2: argc, a3: argv);
  InstallSpewFunction();
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  g_defaultscale = 1.0;
  g_currentscale = 1.0;
  *(_QWORD *)&filenames.m_Memory.m_nGrowSize = 0;
  filenames.m_pElements = (CUtlSymbol *)1070141403;
  *(_QWORD *)&g_defaultrotation.x = 0;
  g_defaultrotation.z = 1.5707964;
  if ( argc == 1 )
    MdlError(fmt: "usage: motionmapper [-quiet] [-verbose] [-templateFile filename] [-printTemplates] sourceanim.smd targ"
                  "etskeleton.smd output.smd\n"
                  "\tsourceanim:  should contain ref pose and animation data\n"
                  "\ttargetsekeleton:  should contain new ref pose, animation data ignored/can be absent\n"
                  "\toutput:  animation from source mapped onto target skeleton (contains new ref pose)\n"
                  "\t-templateFile filename : specifies a template file for guiding the mapping of motion\n"
                  "\t-printTemplate: Causes motionmapper to output the contents of an example template file, which can be"
                  " used in conjunction with the -templateFile argument to create various motion effects.\n"
                  "\n");
  v6 = 1;
  g_quiet = false;
  memset(&filenames, 0, sizeof(filenames));
  if ( argc > 1 )
  {
    v40 = 2;
    do
    {
      v7 = v5[v6];
      if ( *v7 == 45 )
      {
        if ( _V_stricmp(s1: v7, s2: "-allowdebug") != 0 )
        {
          if ( _V_stricmp(s1: v5[v6], s2: "-quiet") != 0 )
          {
            if ( _V_stricmp(s1: v5[v6], s2: "-verbose") != 0 )
            {
              if ( _V_stricmp(s1: v5[v6], s2: "-printTemplate") == 0 )
              {
                printf(format: "%s\n", templates);
                exit(code: 0);
              }
              if ( _V_stricmp(s1: v5[v6], s2: "-templateFile") == 0 )
              {
                if ( v40 >= argc )
                {
                  printf(format: "Error: -templateFile requires an argument, none found!");
                  MdlError(fmt: "usage: motionmapper [-quiet] [-verbose] [-templateFile filename] [-printTemplates] sourc"
                                "eanim.smd targetskeleton.smd output.smd\n"
                                "\tsourceanim:  should contain ref pose and animation data\n"
                                "\ttargetsekeleton:  should contain new ref pose, animation data ignored/can be absent\n"
                                "\toutput:  animation from source mapped onto target skeleton (contains new ref pose)\n"
                                "\t-templateFile filename : specifies a template file for guiding the mapping of motion\n"
                                "\t-printTemplate: Causes motionmapper to output the contents of an example template file"
                                ", which can be used in conjunction with the -templateFile argument to create various mot"
                                "ion effects.\n"
                                "\n");
                }
                v8 = v5[v6 + 1];
                v9 = (char *)(templateFileName - v8);
                do
                {
                  v10 = *v8;
                  v8[(_DWORD)v9] = *v8;
                  ++v8;
                }
                while ( v10 != 0 );
                useTemplate = 1;
                printf(format: "Note: %s passed as template file", templateFileName);
                ++v6;
                ++v40;
              }
            }
            else
            {
              g_quiet = false;
              g_verbose = true;
            }
          }
          else
          {
            g_quiet = true;
            g_verbose = false;
          }
        }
      }
      else
      {
        CUtlSymbol::CUtlSymbol(this: &sym, pStr: v5[v6]);
        v11 = m_Size;
        if ( m_Size + 1 > filenames.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlSymbol,int>::Grow(
            this: &filenames.m_Memory,
            num: m_Size - filenames.m_Memory.m_nAllocationCount + 1);
          m_Size = filenames.m_Size;
        }
        m_pMemory = filenames.m_Memory.m_pMemory;
        filenames.m_Size = ++m_Size;
        filenames.m_pElements = filenames.m_Memory.m_pMemory;
        if ( m_Size - v11 - 1 > 0 )
        {
          _V_memmove(
            dest: &filenames.m_Memory.m_pMemory[v11 + 1],
            src: &filenames.m_Memory.m_pMemory[v11],
            count: 2 * (m_Size - v11 - 1));
          m_pMemory = filenames.m_Memory.m_pMemory;
        }
        v13 = &m_pMemory[v11];
        v5 = argv;
        if ( v13 != nullptr )
          v13->m_Id = sym.m_Id;
      }
      ++v40;
      ++v6;
    }
    while ( v6 < argc );
    if ( m_Size == 3 )
    {
      HIDWORD(v14) = filenames.m_Memory.m_pMemory;
      argca = filenames.m_Memory.m_pMemory + 2;
      v15 = (char *)CUtlSymbol::String(this: filenames.m_Memory.m_pMemory + 2);
      v16 = (char *)(g_outfile - v15);
      do
      {
        v17 = *v15;
        v15[(_DWORD)v16] = *v15;
        ++v15;
      }
      while ( v17 != 0 );
      CmdLib_InitFileSystem(pFilename: g_outfile, maxMemoryUsage: 0);
      V_FileBase(in: g_outfile, out: g_outfile, maxlen: 1024);
      if ( !g_quiet )
        vprint(depth: 0, fmt: "%s, %s, %s, path %s\n", qdir, gamedir, g_outfile, v35);
      V_DefaultExtension(path: g_outfile, extension: ".smd", pathStringLength: 1024);
      if ( !g_quiet )
      {
        v18 = CUtlSymbol::String(this: (CUtlSymbol *)HIDWORD(v14));
        vprint(depth: 0, fmt: "Source animation:  %s\n", v18);
        v19 = CUtlSymbol::String(this: (CUtlSymbol *)(HIDWORD(v14) + 2));
        vprint(depth: 0, fmt: "Target skeleton:  %s\n", v19);
        vprint(depth: 0, fmt: "Creating on \"%s\"\n", g_outfile);
      }
      v20 = 0;
      do
      {
        v21 = g_outfile[v20];
        fullpath[v20++] = v21;
      }
      while ( v21 != 0 );
      v22 = ExpandPath(path: fullpath);
      v23 = (char *)(fullpath - v22);
      do
      {
        v24 = *v22;
        v22[(_DWORD)v23] = *v22;
        ++v22;
      }
      while ( v24 != 0 );
      v25 = ExpandArg(path: fullpath);
      v26 = (char *)(fullpath - v25);
      do
      {
        v27 = *v25;
        v25[(_DWORD)v26] = *v25;
        ++v25;
      }
      while ( v27 != 0 );
      v28 = CUtlSymbol::String(this: (CUtlSymbol *)HIDWORD(v14));
      LODWORD(v14) = Load_Source(name: v28, ext: "smd", reverse: false, isActiveModel: false);
      v29 = CUtlSymbol::String(this: (CUtlSymbol *)(HIDWORD(v14) + 2));
      Source = Load_Source(name: v29, ext: "smd", reverse: false, isActiveModel: false);
      if ( useTemplate != 0 )
      {
        HIDWORD(v14) = Load_Template(name: templateFileName);
      }
      else
      {
        printf(format: "Note: No template file specified, using defaults settings.\n");
        k_memtotal += 2588;
        v31 = calloc(count: 1u, size: 0xA1Cu);
        *((_DWORD *)v31 + 257) = 0;
        *((_DWORD *)v31 + 386) = 0;
        *((_DWORD *)v31 + 515) = 0;
        *((_DWORD *)v31 + 645) = 0;
        *((_DWORD *)v31 + 256) = 1065353216;
        *((_DWORD *)v31 + 644) = 1077106818;
        *((_DWORD *)v31 + 646) = 1065353216;
        HIDWORD(v14) = v31;
        Set_DefaultTemplate(pTemplate: (s_template_t *)v31);
      }
      v32 = MotionMap(
              a1: (int)&savedregs,
              a2: v14,
              pSource: (s_source_t *)LODWORD(v14),
              pTarget: Source,
              pTemplate: (s_template_t *)HIDWORD(v14));
      Save_SMD(filename: fullpath, source: v32);
      v33 = CUtlSymbol::String(this: argca);
      V_StripExtension(in: v33, out: outname, outSize: 1024);
      if ( !g_quiet )
        vprint(depth: 0, fmt: "\nCompleted \"%s\"\n", g_outfile);
      CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&filenames);
      return 0;
    }
  }
  printf(format: "Error: 3 file arguments required, %i found!", m_Size);
  MdlError(fmt: "usage: motionmapper [-quiet] [-verbose] [-templateFile filename] [-printTemplates] sourceanim.smd target"
                "skeleton.smd output.smd\n"
                "\tsourceanim:  should contain ref pose and animation data\n"
                "\ttargetsekeleton:  should contain new ref pose, animation data ignored/can be absent\n"
                "\toutput:  animation from source mapped onto target skeleton (contains new ref pose)\n"
                "\t-templateFile filename : specifies a template file for guiding the mapping of motion\n"
                "\t-printTemplate: Causes motionmapper to output the contents of an example template file, which can be u"
                "sed in conjunction with the -templateFile argument to create various motion effects.\n"
                "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00410C20
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
