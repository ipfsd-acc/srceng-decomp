// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/objsupport.cpp
// Functions: 6
// ============================================================

#include "utils\studiomdl\objsupport.h"

//------------------------------------------------------------------------------
// Address: 0x00419250
// Name: ParseVertex
// Source: json
//------------------------------------------------------------------------------
char __usercall ParseVertex@<al>(CUtlBuffer *bufParse@<esi>, characterset_t *breakSet@<edi>, int *v, int *t, int *n)
{
  char cmd[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false) <= 0 )
    return 0;
  *v = atoi(nptr: cmd);
  *n = 0;
  *t = 0;
  if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0 )
  {
    CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
    if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0
      || (CUtlBuffer::ParseToken(
            this: bufParse,
            pBreaks: breakSet,
            pTokenBuf: cmd,
            nMaxLen: 1024,
            bParseComments: false),
          *t = atoi(nptr: cmd),
          breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0) )
    {
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      *n = atoi(nptr: cmd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419370
// Name: char const __near * FindMtlEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl FindMtlEntry(const char *pTgaName)
{
  int v1; // esi
  int m_Size; // ebx
  int i; // edi
  const char *v4; // eax

  v1 = 0;
  m_Size = g_MtlLib.m_Size;
  if ( g_MtlLib.m_Size <= 0 )
    return pTgaName;
  for ( i = 0; ; ++i )
  {
    v4 = CUtlString::operator char const *(this: &g_MtlLib.m_Memory.m_pMemory[i].m_MtlName);
    if ( _V_stricmp(s1: v4, s2: pTgaName) == 0 )
      break;
    if ( ++v1 >= m_Size )
      return pTgaName;
  }
  return CUtlString::operator char const *(this: &g_MtlLib.m_Memory.m_pMemory[v1].m_TgaName);
}

//------------------------------------------------------------------------------
// Address: 0x004193D0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004194A0
// Name: void ParseMtlLib(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseMtlLib(CUtlBuffer *buf)
{
  CUtlBuffer *v1; // esi
  int v2; // edi
  int m_Size; // eax
  MtlInfo_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  CUtlString *p_m_MtlName; // ebx
  char tgaName[1024]; // [esp+8h] [ebp-904h] BYREF
  char mtlName[1024]; // [esp+408h] [ebp-504h] BYREF
  char tgaPath[260]; // [esp+808h] [ebp-104h] BYREF

  v1 = buf;
  v2 = -1;
  while ( v1->m_Error == 0 )
  {
    CUtlBuffer::GetLine(this: v1, pLine: g_szLine, nMaxChars: 4096);
    if ( V_strnicmp(s1: g_szLine, s2: "newmtl ", n: 7) != 0 )
    {
      if ( V_strnicmp(s1: g_szLine, s2: "map_Kd ", n: 7) == 0
        && v2 >= 0
        && sscanf(string: g_szLine, format: "map_Kd %s", tgaPath) == 1 )
      {
        V_FileBase(in: tgaPath, out: tgaName, maxlen: 1024);
        CUtlString::operator=(this: &g_MtlLib.m_Memory.m_pMemory[v2].m_TgaName, src: tgaName);
      }
    }
    else if ( sscanf(string: g_szLine, format: "newmtl %s", mtlName) == 1 )
    {
      m_Size = g_MtlLib.m_Size;
      v2 = g_MtlLib.m_Size;
      if ( g_MtlLib.m_Size + 1 > g_MtlLib.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<MtlInfo_t,int>::Grow(
          this: (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)&g_MtlLib,
          num: g_MtlLib.m_Size - g_MtlLib.m_Memory.m_nAllocationCount + 1);
        m_Size = g_MtlLib.m_Size;
      }
      m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      g_MtlLib.m_Size = m_Size + 1;
      v5 = m_Size - v2;
      g_MtlLib.m_pElements = g_MtlLib.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(dest: &g_MtlLib.m_Memory.m_pMemory[v2 + 1], src: &g_MtlLib.m_Memory.m_pMemory[v2], count: 32 * v5);
        m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      }
      v6 = v2;
      p_m_MtlName = &m_pMemory[v2].m_MtlName;
      if ( p_m_MtlName != nullptr )
      {
        CUtlString::CUtlString(this: &m_pMemory[v2].m_MtlName);
        CUtlString::CUtlString(this: p_m_MtlName + 1);
        m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      }
      CUtlString::operator=(this: &m_pMemory[v6].m_MtlName, src: mtlName);
      CUtlString::operator=(this: &g_MtlLib.m_Memory.m_pMemory[v6].m_TgaName, src: "debugempty");
      v1 = buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419640
// Name: int Load_OBJ(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_OBJ(s_source_t *psource)
{
  s_source_t *edi1; // edi
  s_sourceanim_t *v3; // eax
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *p_rawanim; // esi
  CUtlSymbolTableLargeBaseTreeEntry_t *v5; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int m_Size; // eax
  int v14; // esi
  int v15; // edi
  float *p_y; // ebx
  int v17; // edi
  int v18; // eax
  int v19; // esi
  float *v20; // ebx
  int v21; // eax
  Vector2D *v22; // ebx
  const char *MtlEntry; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  unsigned int v27; // edi
  int v28; // eax
  int v29; // ebx
  int v30; // edx
  int v31; // eax
  char cmd[1024]; // [esp+8h] [ebp-8A0h] BYREF
  char pFullDir[260]; // [esp+408h] [ebp-4A0h] BYREF
  char pFullMtlLibPath[260]; // [esp+50Ch] [ebp-39Ch] BYREF
  char pFullPath[260]; // [esp+610h] [ebp-298h] BYREF
  characterset_t breakSet; // [esp+714h] [ebp-194h] BYREF
  CUtlBuffer bufParse; // [esp+814h] [ebp-94h] BYREF
  s_tmpface_t f; // [esp+844h] [ebp-64h] BYREF
  int t2; // [esp+878h] [ebp-30h] BYREF
  int v0; // [esp+87Ch] [ebp-2Ch] BYREF
  int t0; // [esp+880h] [ebp-28h] BYREF
  Vector *v42; // [esp+884h] [ebp-24h]
  int n0; // [esp+888h] [ebp-20h] BYREF
  int v1; // [esp+88Ch] [ebp-1Ch] BYREF
  int v2; // [esp+890h] [ebp-18h] BYREF
  int n1; // [esp+894h] [ebp-14h] BYREF
  int n2; // [esp+898h] [ebp-10h] BYREF
  int t1; // [esp+89Ch] [ebp-Ch] BYREF
  Vector *v49; // [esp+8A0h] [ebp-8h]
  int material; // [esp+8A4h] [ebp-4h]

  material = -1;
  CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>::RemoveAll(this: &g_MtlLib);
  edi1 = psource;
  if ( OpenGlobalFile(src: psource->filename) == 0
    || GetGlobalFilePath(pSrc: psource->filename, pFullPath, nMaxLen: 260) == 0 )
  {
    return 0;
  }
  V_ExtractFilePath(path: pFullPath, dest: pFullDir, destSize: 260);
  if ( !g_quiet )
    printf(format: "grabbing %s\n", psource->filename);
  g_iLinecount = 0;
  psource->numbones = 1;
  *(_DWORD *)psource->localBone[0].name = *(_DWORD *)pszFlexControllerType;
  *(_DWORD *)&psource->localBone[0].name[4] = &unk_746C75;
  psource->localBone[0].parent = -1;
  v3 = FindOrAddSourceAnim(pSource: psource, pAnimName: "BindPose");
  p_rawanim = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v3->rawanim;
  v3->numframes = 1;
  v3->startframe = 0;
  v3->endframe = 0;
  if ( v3->rawanim.m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: v3->rawanim.m_Size,
      num: 1 - v3->rawanim.m_Size);
  *p_rawanim->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)calloc(count: 1u, size: 0x18u);
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  v5 = *p_rawanim->m_Memory.m_pMemory;
  v5->m_Hash = 0;
  *(_DWORD *)v5->m_String = 0;
  v5[1].m_Hash = 0;
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  v6 = *p_rawanim->m_Memory.m_pMemory;
  *(_DWORD *)v6[1].m_String = 0;
  v6[2].m_Hash = 0;
  *(_DWORD *)v6[2].m_String = 0;
  Build_Reference(pSource: psource, pAnimName: "BindPose");
  CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: "/\\");
  if ( GetLineInput() != 0 )
  {
    while ( strncmp(first: g_szLine, last: "v ", count: 2u) != 0 )
    {
      if ( strncmp(first: g_szLine, last: "vn ", count: 3u) == 0 )
      {
        v12 = g_numnormals;
        m_Size = g_normal.m_Size;
        v14 = g_numnormals + 1;
        g_numnormals = v14;
        if ( g_normal.m_Size < v14 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v14 - g_normal.m_Size);
          m_Size = g_normal.m_Size;
        }
        v15 = v12;
        v49 = &g_normal.m_Memory.m_pMemory[v15];
        if ( m_Size < v14 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: m_Size,
            num: v14 - m_Size);
          m_Size = g_normal.m_Size;
        }
        p_y = &g_normal.m_Memory.m_pMemory[v15].y;
        if ( m_Size < v14 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: m_Size,
            num: v14 - m_Size);
        sscanf(string: g_szLine, format: "vn %f %f %f", &g_normal.m_Memory.m_pMemory[v15], p_y, &v49->z);
        goto LABEL_80;
      }
      if ( strncmp(first: g_szLine, last: "vt ", count: 3u) == 0 )
      {
        v17 = g_numtexcoords;
        v18 = g_texcoord.m_Size;
        v19 = g_numtexcoords + 1;
        g_numtexcoords = v19;
        if ( g_texcoord.m_Size < v19 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v19 - g_texcoord.m_Size);
          v18 = g_texcoord.m_Size;
        }
        v20 = &g_texcoord.m_Memory.m_pMemory[v17].y;
        if ( v18 < v19 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: v18,
            num: v19 - v18);
        sscanf(string: g_szLine, format: "vt %f %f", &g_texcoord.m_Memory.m_pMemory[v17], v20);
        v21 = g_texcoord.m_Size;
        if ( g_texcoord.m_Size < v19 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v19 - g_texcoord.m_Size);
          v21 = g_texcoord.m_Size;
        }
        v22 = &g_texcoord.m_Memory.m_pMemory[v17];
        if ( v21 < v19 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: v21,
            num: v19 - v21);
        g_texcoord.m_Memory.m_pMemory[v17].y = 1.0 - v22->y;
        goto LABEL_80;
      }
      if ( V_strncmp(s1: g_szLine, s2: "mtllib ", count: 7) == 0 )
      {
        sscanf(string: g_szLine, format: "mtllib %s", cmd);
        CUtlBuffer::CUtlBuffer(this: &bufParse, growSize: 0, initSize: 0, nFlags: 1);
        V_ComposeFileName(path: pFullDir, filename: cmd, dest: pFullMtlLibPath, destSize: 260);
        if ( g_pFullFileSystem->ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: pFullMtlLibPath,
               a3: nullptr,
               a4: &bufParse,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          ParseMtlLib(buf: &bufParse);
        }
        if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
        goto LABEL_81;
      }
      if ( strncmp(first: g_szLine, last: "usemtl ", count: 7u) == 0 )
      {
        sscanf(string: g_szLine, format: "usemtl %s", cmd);
        MtlEntry = FindMtlEntry(pTgaName: cmd);
        v24 = LookupTexture(pTextureName: MtlEntry, bRelativePath: false);
        edi1->texmap[v24] = v24;
        material = UseTextureAsMaterial(textureindex: v24);
      }
      else if ( strncmp(first: g_szLine, last: "f ", count: 2u) == 0 )
      {
        if ( material < 0 )
        {
          v25 = LookupTexture(pTextureName: "debugempty.tga", bRelativePath: false);
          edi1->texmap[v25] = v25;
          material = UseTextureAsMaterial(textureindex: v25);
        }
        s_tmpface_t::s_tmpface_t(this: &f);
        v26 = _V_strlen(str: &pBuffer);
        CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: &pBuffer, nSize: v26, nFlags: 9);
        ParseVertex(&bufParse, &breakSet, v: &v0, t: &t0, n: &n0);
        ParseVertex(&bufParse, &breakSet, v: &v1, t: &t1, n: &n1);
        for ( ; bufParse.m_Error == 0; n1 = v31 )
        {
          if ( ParseVertex(&bufParse, &breakSet, v: &v2, t: &t2, n: &n2) == 0 )
            break;
          f.material = material;
          f.a = v0 - 1;
          v27 = g_numfaces;
          v28 = ++g_numfaces;
          if ( n0 <= 0 )
            f.na = 0;
          else
            f.na = n0 - 1;
          if ( t0 <= 0 )
            f.ta = 0;
          else
            f.ta = t0 - 1;
          f.b = v2 - 1;
          if ( n2 <= 0 )
            f.nb = 0;
          else
            f.nb = n2 - 1;
          v29 = t2;
          if ( t2 <= 0 )
            f.tb = 0;
          else
            f.tb = t2 - 1;
          f.c = v1 - 1;
          if ( n1 <= 0 )
            f.nc = 0;
          else
            f.nc = n1 - 1;
          if ( t1 <= 0 )
            f.tc = 0;
          else
            f.tc = t1 - 1;
          if ( g_face.m_Size < v28 )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: v28 - g_face.m_Size);
          v30 = v2;
          v31 = n2;
          g_face.m_Memory.m_pMemory[v27] = f;
          v1 = v30;
          t1 = v29;
        }
        CUtlBuffer::~CUtlBuffer(this: &bufParse);
        goto LABEL_80;
      }
LABEL_81:
      if ( GetLineInput() == 0 )
        goto LABEL_82;
    }
    v7 = g_numverts;
    v8 = g_vertex.m_Size;
    v9 = g_numverts + 1;
    g_numverts = v9;
    if ( g_vertex.m_Size < v9 )
    {
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: g_vertex.m_Size,
        num: v9 - g_vertex.m_Size);
      v8 = g_vertex.m_Size;
    }
    v10 = v7;
    v42 = &g_vertex.m_Memory.m_pMemory[v7];
    if ( v8 < v9 )
    {
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: v8,
        num: v9 - v8);
      v8 = g_vertex.m_Size;
    }
    v49 = &g_vertex.m_Memory.m_pMemory[v10];
    if ( v8 < v9 )
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: v8,
        num: v9 - v8);
    sscanf(string: g_szLine, format: "v %f %f %f", &g_vertex.m_Memory.m_pMemory[v10], &v49->y, &v42->z);
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    v11 = v7;
    g_bone.m_Memory.m_pMemory[v7].numbones = 1;
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    g_bone.m_Memory.m_pMemory[v11].bone[0] = 0;
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    g_bone.m_Memory.m_pMemory[v11].weight[0] = 1.0;
LABEL_80:
    edi1 = psource;
    goto LABEL_81;
  }
LABEL_82:
  UnifyIndices();
  BuildIndividualMeshes(pSource: edi1);
  fclose(stream: g_fpInput);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419DA0
// Name: int AppendVTAtoOBJ(struct s_source_t __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppendVTAtoOBJ(s_source_t *psource, char *filename, int frame)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // edi
  int v8; // esi
  int m_Size; // eax
  int v10; // edi
  int v11; // esi
  float *p_y; // ebx
  int v13; // eax
  int v14; // esi
  unsigned int v15; // edi
  int v16; // ebx
  unsigned int v17; // edi
  int v18; // eax
  s_sourceanim_t *v19; // edi
  s_bone_t *v20; // eax
  bool v21; // cc
  int v22; // esi
  int v23; // ebx
  int v24; // edx
  int v25; // esi
  Vector *v26; // eax
  s_vertanim_t *v27; // ecx
  int *v28; // edx
  int p_pos; // ecx
  int v30; // esi
  int v31; // eax
  Vector *v32; // eax
  s_vertanim_t *v33; // ecx
  int p_normal; // ecx
  double z; // st7
  int v36; // eax
  unsigned int v37; // [esp-14h] [ebp-4B8h]
  char cmd[1024]; // [esp+0h] [ebp-4A4h] BYREF
  matrix3x4_t m; // [esp+400h] [ebp-A4h] BYREF
  int t0; // [esp+430h] [ebp-74h] BYREF
  int t1; // [esp+434h] [ebp-70h] BYREF
  int t3; // [esp+438h] [ebp-6Ch] BYREF
  int t2; // [esp+43Ch] [ebp-68h] BYREF
  s_tmpface_t f; // [esp+440h] [ebp-64h] BYREF
  int v1; // [esp+474h] [ebp-30h] BYREF
  int n1; // [esp+478h] [ebp-2Ch] BYREF
  int v3; // [esp+47Ch] [ebp-28h] BYREF
  int n2; // [esp+480h] [ebp-24h] BYREF
  int v2; // [esp+484h] [ebp-20h] BYREF
  int n0; // [esp+488h] [ebp-1Ch] BYREF
  int n3; // [esp+48Ch] [ebp-18h] BYREF
  Vector tmp; // [esp+490h] [ebp-14h] BYREF
  int i; // [esp+49Ch] [ebp-8h]
  int v0; // [esp+4A0h] [ebp-4h] BYREF

  tmp.x = 1.570796;
  i = 0;
  tmp.y = 0.0;
  tmp.z = 0.0;
  AngleMatrix(angles: (const RadianEuler *)&tmp, matrix: &m);
  result = OpenGlobalFile(src: filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "grabbing %s\n", filename);
    g_iLinecount = 0;
    g_numfaces = 0;
    g_numtexcoords = 0;
    g_numnormals = 0;
    g_numverts = 0;
    while ( GetLineInput() != 0 )
    {
      if ( strncmp(first: g_szLine, last: "v ", count: 2u) == 0 )
      {
        v4 = g_numverts++;
        v5 = g_numverts;
        sscanf(string: g_szLine, format: "v %f %f %f", &tmp, &tmp.y, &tmp.z);
        if ( g_vertex.m_Size < v5 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
            elem: g_vertex.m_Size,
            num: v5 - g_vertex.m_Size);
        VectorTransform(in1: &tmp.x, in2: &m, out: &g_vertex.m_Memory.m_pMemory[v4].x);
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        v6 = v4;
        g_bone.m_Memory.m_pMemory[v4].numbones = 1;
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v6].bone[0] = 0;
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v6].weight[0] = 1.0;
      }
      else if ( strncmp(first: g_szLine, last: "vn ", count: 3u) == 0 )
      {
        v7 = g_numnormals++;
        v8 = g_numnormals;
        sscanf(string: g_szLine, format: "vn %f %f %f", &tmp, &tmp.y, &tmp.z);
        if ( g_normal.m_Size < v8 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v8 - g_normal.m_Size);
        VectorRotate(in1: &tmp.x, in2: &m, out: &g_normal.m_Memory.m_pMemory[v7].x);
      }
      else if ( strncmp(first: g_szLine, last: "vt ", count: 3u) == 0 )
      {
        m_Size = g_texcoord.m_Size;
        v10 = g_numtexcoords;
        v11 = g_numtexcoords + 1;
        g_numtexcoords = v11;
        if ( g_texcoord.m_Size < v11 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v11 - g_texcoord.m_Size);
          m_Size = g_texcoord.m_Size;
        }
        p_y = &g_texcoord.m_Memory.m_pMemory[v10].y;
        if ( m_Size < v11 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: m_Size,
            num: v11 - m_Size);
        sscanf(string: g_szLine, format: "vt %f %f", &g_texcoord.m_Memory.m_pMemory[v10], p_y);
      }
      else if ( strncmp(first: g_szLine, last: "usemtl ", count: 7u) == 0 )
      {
        sscanf(string: g_szLine, format: "usemtl %s", cmd);
        v13 = LookupTexture(pTextureName: cmd, bRelativePath: false);
        psource->texmap[v13] = v13;
        i = UseTextureAsMaterial(textureindex: v13);
      }
      else if ( strncmp(first: g_szLine, last: "f ", count: 2u) == 0 )
      {
        f.d = -1;
        f.td = -1;
        f.nd = -1;
        v15 = g_numfaces++;
        v14 = g_numfaces;
        v16 = sscanf(
                string: g_szLine,
                format: "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
                &v0,
                &t0,
                &n0,
                &v1,
                &t1,
                &n1,
                &v2,
                &t2,
                &n2,
                &v3,
                &t3,
                &n3);
        f.a = v0 - 1;
        f.na = n0 - 1;
        f.b = v2 - 1;
        f.nb = n2 - 1;
        f.c = v1 - 1;
        f.material = i;
        memset(&f.ta, 0, 12);
        f.nc = n1 - 1;
        if ( g_face.m_Size < v14 )
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: g_face.m_Size,
            num: v14 - g_face.m_Size);
        g_face.m_Memory.m_pMemory[v15] = f;
        if ( v16 == 12 )
        {
          f.a = v0 - 1;
          f.na = n0 - 1;
          f.b = v3 - 1;
          f.nb = n3 - 1;
          f.c = v2 - 1;
          v17 = g_numfaces;
          v18 = g_numfaces + 1;
          f.nc = n2 - 1;
          g_numfaces = v18;
          memset(&f.ta, 0, 12);
          if ( g_face.m_Size < v18 )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: v18 - g_face.m_Size);
          g_face.m_Memory.m_pMemory[v17] = f;
        }
      }
    }
    UnifyIndices();
    v19 = FindOrAddSourceAnim(pSource: psource, pAnimName: "BindPose");
    if ( frame == 0 )
    {
      psource->numbones = 1;
      *(_DWORD *)psource->localBone[0].name = *(_DWORD *)pszFlexControllerType;
      *(_DWORD *)&psource->localBone[0].name[4] = &unk_746C75;
      psource->localBone[0].parent = -1;
      v19->numframes = 1;
      v19->startframe = 0;
      v19->endframe = 0;
      if ( v19->rawanim.m_Size < 1 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      *v19->rawanim.m_Memory.m_pMemory = (s_bone_t *)calloc(count: 1u, size: 0x18u);
      if ( v19->rawanim.m_Size < 1 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      v20 = *v19->rawanim.m_Memory.m_pMemory;
      v20->pos.x = 0.0;
      v20->pos.y = 0.0;
      v20->pos.z = 0.0;
      v21 = v19->rawanim.m_Size < 1;
      tmp.x = 1.570796;
      tmp.y = 0.0;
      tmp.z = 0.0;
      if ( v21 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      (*v19->rawanim.m_Memory.m_pMemory)->rot = (RadianEuler)tmp;
      Build_Reference(pSource: psource, pAnimName: "BindPose");
      BuildIndividualMeshes(pSource: psource);
    }
    v22 = g_numvlist;
    v37 = g_numvlist;
    n3 = g_numvlist;
    v19->numvanims[frame] = g_numvlist;
    v23 = 0;
    v19->vanim[frame] = (s_vertanim_t *)calloc(count: v37, size: 0x28u);
    i = 0;
    if ( v22 > 0 )
    {
      v0 = (int)&v_listdata[0].n;
      do
      {
        v24 = v0;
        v19->vanim[frame][v23].vertex = i;
        v25 = *(_DWORD *)(v24 - 8);
        if ( g_vertex.m_Size < v25 + 1 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
            elem: g_vertex.m_Size,
            num: v25 + 1 - g_vertex.m_Size);
        v26 = &g_vertex.m_Memory.m_pMemory[v25];
        v27 = v19->vanim[frame];
        v27[v23].pos.x = v26->x;
        v28 = (int *)v0;
        p_pos = (int)&v27[v23].pos;
        *(float *)(p_pos + 4) = v26->y;
        *(float *)(p_pos + 8) = v26->z;
        v30 = *v28;
        v31 = *v28 + 1;
        if ( g_normal.m_Size < v31 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v31 - g_normal.m_Size);
        v0 += 32;
        v32 = &g_normal.m_Memory.m_pMemory[v30];
        v33 = v19->vanim[frame];
        v33[v23].normal.x = v32->x;
        p_normal = (int)&v33[v23].normal;
        *(float *)(p_normal + 4) = v32->y;
        ++v23;
        z = v32->z;
        v36 = i + 1;
        *(float *)(p_normal + 8) = z;
        i = v36;
      }
      while ( v36 < n3 );
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
// Address: 0x00411EC0
// Name: ParseVertex
// Source: json
//------------------------------------------------------------------------------
char __usercall ParseVertex@<al>(CUtlBuffer *bufParse@<esi>, characterset_t *breakSet@<edi>, int *v, int *t, int *n)
{
  char cmd[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false) <= 0 )
    return 0;
  *v = atoi(nptr: cmd);
  *n = 0;
  *t = 0;
  if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0 )
  {
    CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
    if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0
      || (CUtlBuffer::ParseToken(
            this: bufParse,
            pBreaks: breakSet,
            pTokenBuf: cmd,
            nMaxLen: 1024,
            bParseComments: false),
          *t = atoi(nptr: cmd),
          breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0) )
    {
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      *n = atoi(nptr: cmd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411FE0
// Name: char const __near * FindMtlEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl FindMtlEntry(const char *pTgaName)
{
  int v1; // esi
  int m_Size; // ebx
  int i; // edi
  const char *v4; // eax

  v1 = 0;
  m_Size = g_MtlLib.m_Size;
  if ( g_MtlLib.m_Size <= 0 )
    return pTgaName;
  for ( i = 0; ; ++i )
  {
    v4 = CUtlString::operator char const *(this: &g_MtlLib.m_Memory.m_pMemory[i].m_MtlName);
    if ( _V_stricmp(s1: v4, s2: pTgaName) == 0 )
      break;
    if ( ++v1 >= m_Size )
      return pTgaName;
  }
  return CUtlString::operator char const *(this: &g_MtlLib.m_Memory.m_pMemory[v1].m_TgaName);
}

//------------------------------------------------------------------------------
// Address: 0x00412040
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412110
// Name: void ParseMtlLib(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseMtlLib(CUtlBuffer *buf)
{
  CUtlBuffer *v1; // esi
  int v2; // edi
  int m_Size; // eax
  MtlInfo_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  CUtlString *p_m_MtlName; // ebx
  char tgaName[1024]; // [esp+8h] [ebp-904h] BYREF
  char mtlName[1024]; // [esp+408h] [ebp-504h] BYREF
  char tgaPath[260]; // [esp+808h] [ebp-104h] BYREF

  v1 = buf;
  v2 = -1;
  while ( v1->m_Error == 0 )
  {
    CUtlBuffer::GetLine(this: v1, pLine: g_szLine, nMaxChars: 4096);
    if ( V_strnicmp(s1: g_szLine, s2: "newmtl ", n: 7) != 0 )
    {
      if ( V_strnicmp(s1: g_szLine, s2: "map_Kd ", n: 7) == 0
        && v2 >= 0
        && sscanf(string: g_szLine, format: "map_Kd %s", tgaPath) == 1 )
      {
        V_FileBase(in: tgaPath, out: tgaName, maxlen: 1024);
        CUtlString::operator=(this: &g_MtlLib.m_Memory.m_pMemory[v2].m_TgaName, src: tgaName);
      }
    }
    else if ( sscanf(string: g_szLine, format: "newmtl %s", mtlName) == 1 )
    {
      m_Size = g_MtlLib.m_Size;
      v2 = g_MtlLib.m_Size;
      if ( g_MtlLib.m_Size + 1 > g_MtlLib.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<MtlInfo_t,int>::Grow(
          this: (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)&g_MtlLib,
          num: g_MtlLib.m_Size - g_MtlLib.m_Memory.m_nAllocationCount + 1);
        m_Size = g_MtlLib.m_Size;
      }
      m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      g_MtlLib.m_Size = m_Size + 1;
      v5 = m_Size - v2;
      g_MtlLib.m_pElements = g_MtlLib.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(dest: &g_MtlLib.m_Memory.m_pMemory[v2 + 1], src: &g_MtlLib.m_Memory.m_pMemory[v2], count: 32 * v5);
        m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      }
      v6 = v2;
      p_m_MtlName = &m_pMemory[v2].m_MtlName;
      if ( p_m_MtlName != nullptr )
      {
        CUtlString::CUtlString(this: &m_pMemory[v2].m_MtlName);
        CUtlString::CUtlString(this: p_m_MtlName + 1);
        m_pMemory = g_MtlLib.m_Memory.m_pMemory;
      }
      CUtlString::operator=(this: &m_pMemory[v6].m_MtlName, src: mtlName);
      CUtlString::operator=(this: &g_MtlLib.m_Memory.m_pMemory[v6].m_TgaName, src: "debugempty");
      v1 = buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004122B0
// Name: int Load_OBJ(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_OBJ(s_source_t *psource)
{
  s_source_t *edi1; // edi
  s_sourceanim_t *v3; // eax
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *p_rawanim; // esi
  CUtlSymbolTableLargeBaseTreeEntry_t *v5; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int m_Size; // eax
  int v14; // esi
  int v15; // edi
  float *p_y; // ebx
  int v17; // edi
  int v18; // eax
  int v19; // esi
  float *v20; // ebx
  int v21; // eax
  Vector2D *v22; // ebx
  const char *MtlEntry; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  unsigned int v27; // edi
  int v28; // eax
  int v29; // ebx
  int v30; // edx
  int v31; // eax
  char cmd[1024]; // [esp+8h] [ebp-8A0h] BYREF
  char pFullDir[260]; // [esp+408h] [ebp-4A0h] BYREF
  char pFullMtlLibPath[260]; // [esp+50Ch] [ebp-39Ch] BYREF
  char pFullPath[260]; // [esp+610h] [ebp-298h] BYREF
  characterset_t breakSet; // [esp+714h] [ebp-194h] BYREF
  CUtlBuffer bufParse; // [esp+814h] [ebp-94h] BYREF
  s_tmpface_t f; // [esp+844h] [ebp-64h] BYREF
  int t2; // [esp+878h] [ebp-30h] BYREF
  int v0; // [esp+87Ch] [ebp-2Ch] BYREF
  int t0; // [esp+880h] [ebp-28h] BYREF
  Vector *v42; // [esp+884h] [ebp-24h]
  int n0; // [esp+888h] [ebp-20h] BYREF
  int v1; // [esp+88Ch] [ebp-1Ch] BYREF
  int v2; // [esp+890h] [ebp-18h] BYREF
  int n1; // [esp+894h] [ebp-14h] BYREF
  int n2; // [esp+898h] [ebp-10h] BYREF
  int t1; // [esp+89Ch] [ebp-Ch] BYREF
  Vector *v49; // [esp+8A0h] [ebp-8h]
  int material; // [esp+8A4h] [ebp-4h]

  material = -1;
  CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>::RemoveAll(this: &g_MtlLib);
  edi1 = psource;
  if ( OpenGlobalFile(src: psource->filename) == 0
    || GetGlobalFilePath(pSrc: psource->filename, pFullPath, nMaxLen: 260) == 0 )
  {
    return 0;
  }
  V_ExtractFilePath(path: pFullPath, dest: pFullDir, destSize: 260);
  if ( !g_quiet )
    printf(format: "grabbing %s\n", psource->filename);
  g_iLinecount = 0;
  psource->numbones = 1;
  *(_DWORD *)psource->localBone[0].name = *(_DWORD *)pszFlexControllerType;
  *(_DWORD *)&psource->localBone[0].name[4] = &unk_746C75;
  psource->localBone[0].parent = -1;
  v3 = FindOrAddSourceAnim(pSource: psource, pAnimName: "BindPose");
  p_rawanim = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v3->rawanim;
  v3->numframes = 1;
  v3->startframe = 0;
  v3->endframe = 0;
  if ( v3->rawanim.m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: v3->rawanim.m_Size,
      num: 1 - v3->rawanim.m_Size);
  *p_rawanim->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)calloc(count: 1u, size: 0x18u);
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  v5 = *p_rawanim->m_Memory.m_pMemory;
  v5->m_Hash = 0;
  *(_DWORD *)v5->m_String = 0;
  v5[1].m_Hash = 0;
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  v6 = *p_rawanim->m_Memory.m_pMemory;
  *(_DWORD *)v6[1].m_String = 0;
  v6[2].m_Hash = 0;
  *(_DWORD *)v6[2].m_String = 0;
  Build_Reference(pSource: psource, pAnimName: "BindPose");
  CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: "/\\");
  if ( GetLineInput() != 0 )
  {
    while ( strncmp(first: g_szLine, last: "v ", count: 2u) != 0 )
    {
      if ( strncmp(first: g_szLine, last: "vn ", count: 3u) == 0 )
      {
        v12 = g_numnormals;
        m_Size = g_normal.m_Size;
        v14 = g_numnormals + 1;
        g_numnormals = v14;
        if ( g_normal.m_Size < v14 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v14 - g_normal.m_Size);
          m_Size = g_normal.m_Size;
        }
        v15 = v12;
        v49 = &g_normal.m_Memory.m_pMemory[v15];
        if ( m_Size < v14 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: m_Size,
            num: v14 - m_Size);
          m_Size = g_normal.m_Size;
        }
        p_y = &g_normal.m_Memory.m_pMemory[v15].y;
        if ( m_Size < v14 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: m_Size,
            num: v14 - m_Size);
        sscanf(string: g_szLine, format: "vn %f %f %f", &g_normal.m_Memory.m_pMemory[v15], p_y, &v49->z);
        goto LABEL_80;
      }
      if ( strncmp(first: g_szLine, last: "vt ", count: 3u) == 0 )
      {
        v17 = g_numtexcoords;
        v18 = g_texcoord.m_Size;
        v19 = g_numtexcoords + 1;
        g_numtexcoords = v19;
        if ( g_texcoord.m_Size < v19 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v19 - g_texcoord.m_Size);
          v18 = g_texcoord.m_Size;
        }
        v20 = &g_texcoord.m_Memory.m_pMemory[v17].y;
        if ( v18 < v19 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: v18,
            num: v19 - v18);
        sscanf(string: g_szLine, format: "vt %f %f", &g_texcoord.m_Memory.m_pMemory[v17], v20);
        v21 = g_texcoord.m_Size;
        if ( g_texcoord.m_Size < v19 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v19 - g_texcoord.m_Size);
          v21 = g_texcoord.m_Size;
        }
        v22 = &g_texcoord.m_Memory.m_pMemory[v17];
        if ( v21 < v19 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: v21,
            num: v19 - v21);
        g_texcoord.m_Memory.m_pMemory[v17].y = 1.0 - v22->y;
        goto LABEL_80;
      }
      if ( V_strncmp(s1: g_szLine, s2: "mtllib ", count: 7) == 0 )
      {
        sscanf(string: g_szLine, format: "mtllib %s", cmd);
        CUtlBuffer::CUtlBuffer(this: &bufParse, growSize: 0, initSize: 0, nFlags: 1);
        V_ComposeFileName(path: pFullDir, filename: cmd, dest: pFullMtlLibPath, destSize: 260);
        if ( g_pFullFileSystem->ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: pFullMtlLibPath,
               a3: nullptr,
               a4: &bufParse,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          ParseMtlLib(buf: &bufParse);
        }
        if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
        goto LABEL_81;
      }
      if ( strncmp(first: g_szLine, last: "usemtl ", count: 7u) == 0 )
      {
        sscanf(string: g_szLine, format: "usemtl %s", cmd);
        MtlEntry = FindMtlEntry(pTgaName: cmd);
        v24 = LookupTexture(pTextureName: MtlEntry, bRelativePath: false);
        edi1->texmap[v24] = v24;
        material = UseTextureAsMaterial(textureindex: v24);
      }
      else if ( strncmp(first: g_szLine, last: "f ", count: 2u) == 0 )
      {
        if ( material < 0 )
        {
          v25 = LookupTexture(pTextureName: "debugempty.tga", bRelativePath: false);
          edi1->texmap[v25] = v25;
          material = UseTextureAsMaterial(textureindex: v25);
        }
        s_tmpface_t::s_tmpface_t(this: &f);
        v26 = _V_strlen(str: &pBuffer);
        CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: &pBuffer, nSize: v26, nFlags: 9);
        ParseVertex(&bufParse, &breakSet, v: &v0, t: &t0, n: &n0);
        ParseVertex(&bufParse, &breakSet, v: &v1, t: &t1, n: &n1);
        for ( ; bufParse.m_Error == 0; n1 = v31 )
        {
          if ( ParseVertex(&bufParse, &breakSet, v: &v2, t: &t2, n: &n2) == 0 )
            break;
          f.material = material;
          f.a = v0 - 1;
          v27 = g_numfaces;
          v28 = ++g_numfaces;
          if ( n0 <= 0 )
            f.na = 0;
          else
            f.na = n0 - 1;
          if ( t0 <= 0 )
            f.ta = 0;
          else
            f.ta = t0 - 1;
          f.b = v2 - 1;
          if ( n2 <= 0 )
            f.nb = 0;
          else
            f.nb = n2 - 1;
          v29 = t2;
          if ( t2 <= 0 )
            f.tb = 0;
          else
            f.tb = t2 - 1;
          f.c = v1 - 1;
          if ( n1 <= 0 )
            f.nc = 0;
          else
            f.nc = n1 - 1;
          if ( t1 <= 0 )
            f.tc = 0;
          else
            f.tc = t1 - 1;
          if ( g_face.m_Size < v28 )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: v28 - g_face.m_Size);
          v30 = v2;
          v31 = n2;
          g_face.m_Memory.m_pMemory[v27] = f;
          v1 = v30;
          t1 = v29;
        }
        CUtlBuffer::~CUtlBuffer(this: &bufParse);
        goto LABEL_80;
      }
LABEL_81:
      if ( GetLineInput() == 0 )
        goto LABEL_82;
    }
    v7 = g_numverts;
    v8 = g_vertex.m_Size;
    v9 = g_numverts + 1;
    g_numverts = v9;
    if ( g_vertex.m_Size < v9 )
    {
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: g_vertex.m_Size,
        num: v9 - g_vertex.m_Size);
      v8 = g_vertex.m_Size;
    }
    v10 = v7;
    v42 = &g_vertex.m_Memory.m_pMemory[v7];
    if ( v8 < v9 )
    {
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: v8,
        num: v9 - v8);
      v8 = g_vertex.m_Size;
    }
    v49 = &g_vertex.m_Memory.m_pMemory[v10];
    if ( v8 < v9 )
      CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
        elem: v8,
        num: v9 - v8);
    sscanf(string: g_szLine, format: "v %f %f %f", &g_vertex.m_Memory.m_pMemory[v10], &v49->y, &v42->z);
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    v11 = v7;
    g_bone.m_Memory.m_pMemory[v7].numbones = 1;
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    g_bone.m_Memory.m_pMemory[v11].bone[0] = 0;
    if ( g_bone.m_Size < v9 )
      CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
        this: &g_bone,
        elem: g_bone.m_Size,
        num: v9 - g_bone.m_Size);
    g_bone.m_Memory.m_pMemory[v11].weight[0] = 1.0;
LABEL_80:
    edi1 = psource;
    goto LABEL_81;
  }
LABEL_82:
  UnifyIndices();
  BuildIndividualMeshes(pSource: edi1);
  fclose(stream: g_fpInput);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412A10
// Name: int AppendVTAtoOBJ(struct s_source_t __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppendVTAtoOBJ(s_source_t *psource, char *filename, int frame)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // edi
  int v8; // esi
  int m_Size; // eax
  int v10; // edi
  int v11; // esi
  float *p_y; // ebx
  int v13; // eax
  int v14; // esi
  unsigned int v15; // edi
  int v16; // ebx
  unsigned int v17; // edi
  int v18; // eax
  s_sourceanim_t *v19; // edi
  s_bone_t *v20; // eax
  bool v21; // cc
  int v22; // esi
  int v23; // ebx
  int v24; // edx
  int v25; // esi
  Vector *v26; // eax
  s_vertanim_t *v27; // ecx
  int *v28; // edx
  int p_pos; // ecx
  int v30; // esi
  int v31; // eax
  Vector *v32; // eax
  s_vertanim_t *v33; // ecx
  int p_normal; // ecx
  double z; // st7
  int v36; // eax
  unsigned int v37; // [esp-14h] [ebp-4B8h]
  char cmd[1024]; // [esp+0h] [ebp-4A4h] BYREF
  matrix3x4_t m; // [esp+400h] [ebp-A4h] BYREF
  int t0; // [esp+430h] [ebp-74h] BYREF
  int t1; // [esp+434h] [ebp-70h] BYREF
  int t3; // [esp+438h] [ebp-6Ch] BYREF
  int t2; // [esp+43Ch] [ebp-68h] BYREF
  s_tmpface_t f; // [esp+440h] [ebp-64h] BYREF
  int v1; // [esp+474h] [ebp-30h] BYREF
  int n1; // [esp+478h] [ebp-2Ch] BYREF
  int v3; // [esp+47Ch] [ebp-28h] BYREF
  int n2; // [esp+480h] [ebp-24h] BYREF
  int v2; // [esp+484h] [ebp-20h] BYREF
  int n0; // [esp+488h] [ebp-1Ch] BYREF
  int n3; // [esp+48Ch] [ebp-18h] BYREF
  Vector tmp; // [esp+490h] [ebp-14h] BYREF
  int i; // [esp+49Ch] [ebp-8h]
  int v0; // [esp+4A0h] [ebp-4h] BYREF

  tmp.x = 1.570796;
  i = 0;
  tmp.y = 0.0;
  tmp.z = 0.0;
  AngleMatrix(angles: (const RadianEuler *)&tmp, matrix: &m);
  result = OpenGlobalFile(src: filename);
  if ( result != 0 )
  {
    if ( !g_quiet )
      printf(format: "grabbing %s\n", filename);
    g_iLinecount = 0;
    g_numfaces = 0;
    g_numtexcoords = 0;
    g_numnormals = 0;
    g_numverts = 0;
    while ( GetLineInput() != 0 )
    {
      if ( strncmp(first: g_szLine, last: "v ", count: 2u) == 0 )
      {
        v4 = g_numverts++;
        v5 = g_numverts;
        sscanf(string: g_szLine, format: "v %f %f %f", &tmp, &tmp.y, &tmp.z);
        if ( g_vertex.m_Size < v5 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
            elem: g_vertex.m_Size,
            num: v5 - g_vertex.m_Size);
        VectorTransform(in1: &tmp.x, in2: &m, out: &g_vertex.m_Memory.m_pMemory[v4].x);
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        v6 = v4;
        g_bone.m_Memory.m_pMemory[v4].numbones = 1;
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v6].bone[0] = 0;
        if ( g_bone.m_Size < v5 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: v5 - g_bone.m_Size);
        g_bone.m_Memory.m_pMemory[v6].weight[0] = 1.0;
      }
      else if ( strncmp(first: g_szLine, last: "vn ", count: 3u) == 0 )
      {
        v7 = g_numnormals++;
        v8 = g_numnormals;
        sscanf(string: g_szLine, format: "vn %f %f %f", &tmp, &tmp.y, &tmp.z);
        if ( g_normal.m_Size < v8 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v8 - g_normal.m_Size);
        VectorRotate(in1: &tmp.x, in2: &m, out: &g_normal.m_Memory.m_pMemory[v7].x);
      }
      else if ( strncmp(first: g_szLine, last: "vt ", count: 3u) == 0 )
      {
        m_Size = g_texcoord.m_Size;
        v10 = g_numtexcoords;
        v11 = g_numtexcoords + 1;
        g_numtexcoords = v11;
        if ( g_texcoord.m_Size < v11 )
        {
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: g_texcoord.m_Size,
            num: v11 - g_texcoord.m_Size);
          m_Size = g_texcoord.m_Size;
        }
        p_y = &g_texcoord.m_Memory.m_pMemory[v10].y;
        if ( m_Size < v11 )
          CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
            this: &g_texcoord,
            elem: m_Size,
            num: v11 - m_Size);
        sscanf(string: g_szLine, format: "vt %f %f", &g_texcoord.m_Memory.m_pMemory[v10], p_y);
      }
      else if ( strncmp(first: g_szLine, last: "usemtl ", count: 7u) == 0 )
      {
        sscanf(string: g_szLine, format: "usemtl %s", cmd);
        v13 = LookupTexture(pTextureName: cmd, bRelativePath: false);
        psource->texmap[v13] = v13;
        i = UseTextureAsMaterial(textureindex: v13);
      }
      else if ( strncmp(first: g_szLine, last: "f ", count: 2u) == 0 )
      {
        f.d = -1;
        f.td = -1;
        f.nd = -1;
        v15 = g_numfaces++;
        v14 = g_numfaces;
        v16 = sscanf(
                string: g_szLine,
                format: "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
                &v0,
                &t0,
                &n0,
                &v1,
                &t1,
                &n1,
                &v2,
                &t2,
                &n2,
                &v3,
                &t3,
                &n3);
        f.a = v0 - 1;
        f.na = n0 - 1;
        f.b = v2 - 1;
        f.nb = n2 - 1;
        f.c = v1 - 1;
        f.material = i;
        memset(&f.ta, 0, 12);
        f.nc = n1 - 1;
        if ( g_face.m_Size < v14 )
          CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
            this: &g_face,
            elem: g_face.m_Size,
            num: v14 - g_face.m_Size);
        g_face.m_Memory.m_pMemory[v15] = f;
        if ( v16 == 12 )
        {
          f.a = v0 - 1;
          f.na = n0 - 1;
          f.b = v3 - 1;
          f.nb = n3 - 1;
          f.c = v2 - 1;
          v17 = g_numfaces;
          v18 = g_numfaces + 1;
          f.nc = n2 - 1;
          g_numfaces = v18;
          memset(&f.ta, 0, 12);
          if ( g_face.m_Size < v18 )
            CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
              this: &g_face,
              elem: g_face.m_Size,
              num: v18 - g_face.m_Size);
          g_face.m_Memory.m_pMemory[v17] = f;
        }
      }
    }
    UnifyIndices();
    v19 = FindOrAddSourceAnim(pSource: psource, pAnimName: "BindPose");
    if ( frame == 0 )
    {
      psource->numbones = 1;
      *(_DWORD *)psource->localBone[0].name = *(_DWORD *)pszFlexControllerType;
      *(_DWORD *)&psource->localBone[0].name[4] = &unk_746C75;
      psource->localBone[0].parent = -1;
      v19->numframes = 1;
      v19->startframe = 0;
      v19->endframe = 0;
      if ( v19->rawanim.m_Size < 1 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      *v19->rawanim.m_Memory.m_pMemory = (s_bone_t *)calloc(count: 1u, size: 0x18u);
      if ( v19->rawanim.m_Size < 1 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      v20 = *v19->rawanim.m_Memory.m_pMemory;
      v20->pos.x = 0.0;
      v20->pos.y = 0.0;
      v20->pos.z = 0.0;
      v21 = v19->rawanim.m_Size < 1;
      tmp.x = 1.570796;
      tmp.y = 0.0;
      tmp.z = 0.0;
      if ( v21 )
        CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v19->rawanim,
          elem: v19->rawanim.m_Size,
          num: 1 - v19->rawanim.m_Size);
      (*v19->rawanim.m_Memory.m_pMemory)->rot = (RadianEuler)tmp;
      Build_Reference(pSource: psource, pAnimName: "BindPose");
      BuildIndividualMeshes(pSource: psource);
    }
    v22 = g_numvlist;
    v37 = g_numvlist;
    n3 = g_numvlist;
    v19->numvanims[frame] = g_numvlist;
    v23 = 0;
    v19->vanim[frame] = (s_vertanim_t *)calloc(count: v37, size: 0x28u);
    i = 0;
    if ( v22 > 0 )
    {
      v0 = (int)&v_listdata[0].n;
      do
      {
        v24 = v0;
        v19->vanim[frame][v23].vertex = i;
        v25 = *(_DWORD *)(v24 - 8);
        if ( g_vertex.m_Size < v25 + 1 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_vertex,
            elem: g_vertex.m_Size,
            num: v25 + 1 - g_vertex.m_Size);
        v26 = &g_vertex.m_Memory.m_pMemory[v25];
        v27 = v19->vanim[frame];
        v27[v23].pos.x = v26->x;
        v28 = (int *)v0;
        p_pos = (int)&v27[v23].pos;
        *(float *)(p_pos + 4) = v26->y;
        *(float *)(p_pos + 8) = v26->z;
        v30 = *v28;
        v31 = *v28 + 1;
        if ( g_normal.m_Size < v31 )
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&g_normal,
            elem: g_normal.m_Size,
            num: v31 - g_normal.m_Size);
        v0 += 32;
        v32 = &g_normal.m_Memory.m_pMemory[v30];
        v33 = v19->vanim[frame];
        v33[v23].normal.x = v32->x;
        p_normal = (int)&v33[v23].normal;
        *(float *)(p_normal + 4) = v32->y;
        ++v23;
        z = v32->z;
        v36 = i + 1;
        *(float *)(p_normal + 8) = z;
        i = v36;
      }
      while ( v36 < n3 );
    }
    fclose(stream: g_fpInput);
    return 1;
  }
  return result;
}

} // namespace studiomdl
