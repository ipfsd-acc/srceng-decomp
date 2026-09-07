// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbspinfo/vbspinfo.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E430
// Name: void CalculateTreeInfo_R(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateTreeInfo_R(int iNode, int depth)
{
  dnode_t *v2; // esi
  int v4; // eax

  v2 = &dnodes[iNode];
  if ( iNode >= 0 )
  {
    do
    {
      CalculateTreeInfo_R(iNode: v2->children[0], depth: ++depth);
      v4 = v2->children[1];
      v2 = &dnodes[v4];
    }
    while ( v4 >= 0 );
  }
  if ( g_nMinTreeDepth >= depth )
    g_nMinTreeDepth = depth;
  if ( g_nMaxTreeDepth <= depth )
    g_nMaxTreeDepth = depth;
  g_TotalTreeDepth += depth;
  g_TotalVariance = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)depth - g_nOptimumDepth) & _mask__AbsFloat_)
                  + g_TotalVariance;
}

//------------------------------------------------------------------------------
// Address: 0x0040E4C0
// Name: void CalcTreeDepth_R(int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcTreeDepth_R(int iNode, int iLevel, int *iMaxDepth)
{
  int v5; // eax
  int v6; // esi

  while ( 1 )
  {
    v5 = *iMaxDepth;
    if ( iLevel > *iMaxDepth )
      v5 = iLevel;
    *iMaxDepth = v5;
    if ( iNode < 0 )
      break;
    ++iLevel;
    v6 = iNode;
    CalcTreeDepth_R(iNode: dnodes[v6].children[0], iLevel, iMaxDepth);
    iNode = dnodes[v6].children[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E500
// Name: int WorldTextureCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WorldTextureCompareFunc(_DWORD *t1, _DWORD *t2)
{
  int v2; // eax
  int v3; // ecx

  v2 = t1[1];
  v3 = t2[1];
  if ( v2 >= v3 )
    return (v2 <= v3) - 1;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040E530
// Name: void PrintListStaticProps(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintListStaticProps()
{
  unsigned __int16 GameLumpHandle; // ax
  unsigned __int8 *GameLump; // eax
  unsigned __int8 *v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi
  unsigned __int16 *v6; // ebx
  StaticPropDictLump_t *pDictLump; // [esp+8h] [ebp-4h]

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1936749168);
  GameLump = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
  pDictLump = (StaticPropDictLump_t *)(GameLump + 4);
  v2 = &GameLump[128 * *(_DWORD *)GameLump + 4];
  v3 = *(_DWORD *)&v2[2 * *(_DWORD *)v2 + 4];
  v4 = (int)&v2[2 * *(_DWORD *)v2 + 4];
  v5 = 0;
  if ( v3 > 0 )
  {
    v6 = (unsigned __int16 *)(v4 + 28);
    do
    {
      printf(format: "%03d  %s\n", v5++, pDictLump[*v6].m_Name);
      v6 += 36;
    }
    while ( v5 < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E5A0
// Name: void PrintCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintCommandLine(int argc, char **argv)
{
  int i; // esi

  _Warning(a1: "Command line: ");
  for ( i = 0; i < argc; ++i )
    _Warning(a1: "\"%s\" ", argv[i]);
  _Warning(a1: "\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x0040E5F0
// Name: void DrawTreeToScratchPad_R(class IScratchPad3D __near *,int,int,float,float,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawTreeToScratchPad_R(
        IScratchPad3D *pPad,
        int iNode,
        int iLevel,
        float flXMin,
        float flXMax,
        const Vector *pParentPos)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  void (__thiscall *DrawLine)(IScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float z; // xmm1_4
  dnode_t *v11; // edi
  void (__thiscall *DrawPoint)(IScratchPad3D *, const CSPVert *, float); // edx
  float x; // [esp+28h] [ebp-48h] BYREF
  float y; // [esp+2Ch] [ebp-44h]
  float v15; // [esp+30h] [ebp-40h]
  int v16; // [esp+34h] [ebp-3Ch]
  int v17; // [esp+38h] [ebp-38h]
  int v18; // [esp+3Ch] [ebp-34h]
  int v19; // [esp+40h] [ebp-30h]
  float v20[7]; // [esp+44h] [ebp-2Ch] BYREF
  Vector vMyPos; // [esp+60h] [ebp-10h] BYREF
  float flMyX; // [esp+6Ch] [ebp-4h]

  v6 = (float)(flXMin + flXMax) * 0.5;
  v7 = (float)-iLevel * g_ySpacing;
  v8 = 0.0;
  flMyX = v6;
  vMyPos.x = 0.0;
  vMyPos.y = v6;
  vMyPos.z = v7;
  if ( pParentPos != nullptr )
  {
    DrawLine = pPad->DrawLine;
    v20[1] = (float)(flXMin + flXMax) * 0.5;
    x = pParentPos->x;
    y = pParentPos->y;
    z = pParentPos->z;
    v20[0] = 0.0;
    v20[2] = (float)-iLevel * g_ySpacing;
    v20[3] = 1.0;
    v20[4] = 0.0;
    v20[5] = 0.0;
    v20[6] = 1.0;
    v15 = z;
    v16 = 1065353216;
    v17 = 1065353216;
    v18 = 1065353216;
    v19 = 1065353216;
    DrawLine(this: pPad, a2: (const CSPVert *)&x, a3: (const CSPVert *)v20);
    v7 = vMyPos.z;
    v6 = vMyPos.y;
    v8 = vMyPos.x;
  }
  v11 = &dnodes[iNode];
  DrawPoint = pPad->DrawPoint;
  x = v8;
  y = v6;
  v15 = v7;
  v16 = 1065353216;
  v19 = 1065353216;
  if ( iNode >= 0 )
  {
    v17 = 1065353216;
    v18 = 1065353216;
    ((void (__thiscall *)(IScratchPad3D *, float *, int))DrawPoint)(a1: pPad, a2: &x, a3: 0x40000000);
    DrawTreeToScratchPad_R(
      pPad,
      iNode: v11->children[0],
      iLevel: iLevel + 1,
      flXMin,
      flXMax: flMyX,
      pParentPos: &vMyPos);
    DrawTreeToScratchPad_R(
      pPad,
      iNode: v11->children[1],
      iLevel: iLevel + 1,
      flXMin: flMyX,
      flXMax,
      pParentPos: &vMyPos);
  }
  else
  {
    v17 = 0;
    v18 = 0;
    ((void (__thiscall *)(IScratchPad3D *, float *, int))DrawPoint)(a1: pPad, a2: &x, a3: 1086324736);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E7A0
// Name: void DrawTreeToScratchPad(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawTreeToScratchPad()
{
  CScratchPad3D *v0; // edi
  int v1; // edx
  char v2; // cl
  float v3; // xmm1_4
  dnode_t *v4; // esi
  void (__thiscall *v5)(struct CScratchPad3D *, const CSPVert *, float); // edx
  void (__thiscall *DrawPoint)(struct CScratchPad3D *, const CSPVert *, float); // edx
  float v7[4]; // [esp+20h] [ebp-38h] BYREF
  int v8; // [esp+30h] [ebp-28h]
  int v9; // [esp+34h] [ebp-24h]
  int v10; // [esp+38h] [ebp-20h]
  Vector pParentPos; // [esp+3Ch] [ebp-1Ch] BYREF
  float v12; // [esp+48h] [ebp-10h]
  float flXMin; // [esp+4Ch] [ebp-Ch]
  float v14; // [esp+50h] [ebp-8h]
  int maxDepth; // [esp+54h] [ebp-4h] BYREF

  v0 = ScratchPad3D_Create(pFilename: "scratch.pad");
  v0->SetAutoFlush(this: v0, a2: false);
  maxDepth = 0;
  CalcTreeDepth_R(iNode: iNode, iLevel: 0, iMaxDepth: &maxDepth);
  v2 = maxDepth;
  if ( maxDepth >= 14 )
    v2 = 14;
  v3 = (double)(1 << v2) * g_xSpacing;
  flXMin = v3 * -0.5;
  g_ySpacing = (float)(v3 / (float)maxDepth) * 0.25;
  v12 = v3 * 0.5;
  pParentPos.z = g_ySpacing * 0.0;
  v4 = &dnodes[v1];
  v7[2] = g_ySpacing * 0.0;
  v14 = (float)((float)(v3 * -0.5) + (float)(v3 * 0.5)) * 0.5;
  pParentPos.x = 0.0;
  pParentPos.y = v14;
  v7[0] = 0.0;
  v7[1] = v14;
  v7[3] = 1.0;
  v10 = 1065353216;
  if ( v1 >= 0 )
  {
    DrawPoint = v0->DrawPoint;
    v8 = 1065353216;
    v9 = 1065353216;
    ((void (__thiscall *)(CScratchPad3D *, float *, int))DrawPoint)(a1: v0, a2: v7, a3: 0x40000000);
    DrawTreeToScratchPad_R(pPad: v0, iNode: v4->children[0], iLevel: 1, flXMin, flXMax: v14, &pParentPos);
    DrawTreeToScratchPad_R(pPad: v0, iNode: v4->children[1], iLevel: 1, flXMin: v14, flXMax: v12, &pParentPos);
  }
  else
  {
    v5 = v0->DrawPoint;
    v8 = 0;
    v9 = 0;
    ((void (__thiscall *)(CScratchPad3D *, float *, int))v5)(a1: v0, a2: v7, a3: 1086324736);
  }
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x0040E960
// Name: void PrintWorldTextureStats(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintWorldTextureStats(_iobuf *fp)
{
  signed int v1; // esi
  int i; // eax
  int v3; // edx
  texinfo_s *m_pMemory; // edi
  __int16 *p_texinfo; // ecx
  int texdata; // eax
  signed int j; // esi
  char *String; // eax

  v1 = numtexdata;
  for ( i = 0; i < v1; ++i )
  {
    stats[i].texdataID = i;
    dword_435B46C[2 * i] = 0;
  }
  v3 = numfaces;
  if ( numfaces > 0 )
  {
    m_pMemory = texinfo.m_Memory.m_pMemory;
    p_texinfo = &dfaces[0].texinfo;
    do
    {
      texdata = m_pMemory[*p_texinfo].texdata;
      ++dword_435B46C[2 * texdata];
      p_texinfo += 28;
      --v3;
    }
    while ( v3 != 0 );
  }
  qsort(base: stats, num: v1, width: 8u, comp: (int (__cdecl *)(const void *, const void *))WorldTextureCompareFunc);
  for ( j = 0; j < (int)numtexdata; ++j )
  {
    String = TexDataStringTable_GetString(stringID: dtexdata[stats[j].texdataID].nameStringTableID);
    fprintf(str: fp, format: "%5d surface(s) use material \"%s\"\n", dword_435B46C[2 * j], String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EA30
// Name: void PrintModelStats(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintModelStats()
{
  unsigned __int16 GameLumpHandle; // si
  int GameLumpVersion; // eax
  unsigned __int8 *GameLump; // eax
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int16 *v5; // edi
  const char *v6; // esi
  int v7; // esi
  int m_Id; // esi
  unsigned __int8 *v9; // eax
  int v10; // ecx
  int v11; // edx
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // ecx
  int v15; // eax
  unsigned __int16 *v16; // edi
  const char *v17; // esi
  int v18; // esi
  int v19; // esi
  unsigned __int8 *v20; // eax
  int v21; // ecx
  int v22; // edx
  unsigned __int8 *v23; // ebx
  unsigned __int8 *v24; // eax
  int v25; // ecx
  int v26; // eax
  unsigned __int16 *v27; // edi
  const char *v28; // esi
  int v29; // esi
  int v30; // esi
  epair_t *v31; // esi
  char *v32; // ebx
  const char *value; // edi
  int v34; // eax
  int v35; // esi
  int v36; // esi
  int v37; // edi
  int v38; // ebx
  int *v39; // ecx
  int v40; // eax
  int m_Size; // eax
  int v42; // esi
  int v43; // esi
  int v44; // edi
  int v45; // ebx
  int *m_pMemory; // ecx
  int v47; // eax
  int v48; // ebx
  const char *v49; // eax
  int v50; // edi
  int v51; // eax
  int v52; // esi
  int *v53; // ecx
  int v54; // eax
  int *v55; // esi
  const char *v56; // eax
  int *v57; // eax
  CUtlStringMap<int> modelMap; // [esp+Ch] [ebp-64h] BYREF
  int v59; // [esp+58h] [ebp-18h]
  int i; // [esp+5Ch] [ebp-14h]
  epair_t **j; // [esp+60h] [ebp-10h]
  CUtlSymbol result; // [esp+66h] [ebp-Ah] BYREF
  CUtlSymbol v63; // [esp+68h] [ebp-8h] BYREF
  CUtlSymbol v64; // [esp+6Ch] [ebp-4h] BYREF

  modelMap.m_Vector.m_Memory.m_pMemory = nullptr;
  modelMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  modelMap.m_Vector.m_Memory.m_nGrowSize = 32;
  modelMap.m_Vector.m_Size = 0;
  modelMap.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &modelMap.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1936749168);
  GameLumpVersion = CGameLump::GetGameLumpVersion(this: &g_GameLumps, handle: GameLumpHandle);
  switch ( GameLumpVersion )
  {
    case 9:
      GameLump = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
      v3 = GameLump + 4;
      v4 = &GameLump[128 * *(_DWORD *)GameLump + 8 + 2 * *(_DWORD *)&GameLump[128 * *(_DWORD *)GameLump + 4]];
      if ( *(int *)v4 > 0 )
      {
        v5 = (unsigned __int16 *)(v4 + 28);
        j = *(epair_t ***)v4;
        do
        {
          v6 = (const char *)&v3[128 * *v5];
          if ( CUtlSymbolTable::Find(this: &modelMap.m_SymbolTable, &result, pString: v6)->m_Id == 0xFFFF )
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v63, pString: v6);
            m_Id = v63.m_Id;
            if ( modelMap.m_Vector.m_Size <= v63.m_Id && modelMap.m_Vector.m_Size < v63.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v63.m_Id + 1 - modelMap.m_Vector.m_Size);
            modelMap.m_Vector.m_Memory.m_pMemory[m_Id] = 1;
          }
          else
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v64, pString: v6);
            v7 = v64.m_Id;
            if ( modelMap.m_Vector.m_Size <= v64.m_Id && modelMap.m_Vector.m_Size < v64.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v64.m_Id + 1 - modelMap.m_Vector.m_Size);
            ++modelMap.m_Vector.m_Memory.m_pMemory[v7];
          }
          v5 += 36;
          j = (epair_t **)((char *)j - 1);
        }
        while ( j != nullptr );
      }
      break;
    case 6:
      v9 = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
      v10 = *(_DWORD *)v9;
      v9 += 4;
      v10 <<= 7;
      v11 = *(_DWORD *)&v9[v10];
      v12 = v9;
      v13 = &v9[v10];
      v14 = *(_DWORD *)&v13[2 * v11 + 4];
      v15 = (int)&v13[2 * v11 + 4];
      if ( v14 > 0 )
      {
        v16 = (unsigned __int16 *)(v15 + 28);
        for ( j = (epair_t **)v14; j != nullptr; j = (epair_t **)((char *)j - 1) )
        {
          v17 = (const char *)&v12[128 * *v16];
          if ( CUtlSymbolTable::Find(this: &modelMap.m_SymbolTable, &result, pString: v17)->m_Id == 0xFFFF )
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v64, pString: v17);
            v19 = v64.m_Id;
            if ( modelMap.m_Vector.m_Size <= v64.m_Id && modelMap.m_Vector.m_Size < v64.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v64.m_Id + 1 - modelMap.m_Vector.m_Size);
            modelMap.m_Vector.m_Memory.m_pMemory[v19] = 1;
          }
          else
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v63, pString: v17);
            v18 = v63.m_Id;
            if ( modelMap.m_Vector.m_Size <= v63.m_Id && modelMap.m_Vector.m_Size < v63.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v63.m_Id + 1 - modelMap.m_Vector.m_Size);
            ++modelMap.m_Vector.m_Memory.m_pMemory[v18];
          }
          v16 += 32;
        }
      }
      break;
    case 5:
      v20 = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
      v21 = *(_DWORD *)v20;
      v20 += 4;
      v21 <<= 7;
      v22 = *(_DWORD *)&v20[v21];
      v23 = v20;
      v24 = &v20[v21];
      v25 = *(_DWORD *)&v24[2 * v22 + 4];
      v26 = (int)&v24[2 * v22 + 4];
      if ( v25 > 0 )
      {
        v27 = (unsigned __int16 *)(v26 + 28);
        for ( j = (epair_t **)v25; j != nullptr; j = (epair_t **)((char *)j - 1) )
        {
          v28 = (const char *)&v23[128 * *v27];
          if ( CUtlSymbolTable::Find(this: &modelMap.m_SymbolTable, &result, pString: v28)->m_Id == 0xFFFF )
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v64, pString: v28);
            v30 = v64.m_Id;
            if ( modelMap.m_Vector.m_Size <= v64.m_Id && modelMap.m_Vector.m_Size < v64.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v64.m_Id + 1 - modelMap.m_Vector.m_Size);
            modelMap.m_Vector.m_Memory.m_pMemory[v30] = 1;
          }
          else
          {
            CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v63, pString: v28);
            v29 = v63.m_Id;
            if ( modelMap.m_Vector.m_Size <= v63.m_Id && modelMap.m_Vector.m_Size < v63.m_Id + 1 )
              CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
                this: (CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *)&modelMap,
                elem: modelMap.m_Vector.m_Size,
                num: v63.m_Id + 1 - modelMap.m_Vector.m_Size);
            ++modelMap.m_Vector.m_Memory.m_pMemory[v29];
          }
          v27 += 30;
        }
      }
      break;
    default:
      break;
  }
  ParseEntities();
  i = 0;
  if ( num_entities > 0 )
  {
    j = &entities[0].epairs;
    do
    {
      v31 = *j;
      v32 = nullptr;
      value = nullptr;
      if ( *j == nullptr )
        goto LABEL_74;
      do
      {
        if ( _V_stricmp(s1: v31->key, s2: "classname") != 0 )
        {
          if ( _V_stricmp(s1: v31->key, s2: "model") == 0
            && StringAfterPrefix(str: v31->value, prefix: "models") != nullptr )
          {
            value = v31->value;
          }
        }
        else
        {
          v32 = v31->value;
        }
        v31 = v31->next;
      }
      while ( v31 != nullptr );
      if ( v32 == nullptr || value == nullptr )
        goto LABEL_74;
      if ( CUtlSymbolTable::Find(this: &modelMap.m_SymbolTable, &result, pString: value)->m_Id == 0xFFFF )
      {
        CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v64, pString: value);
        m_Size = modelMap.m_Vector.m_Size;
        v59 = v64.m_Id;
        if ( modelMap.m_Vector.m_Size <= v64.m_Id
          && (v42 = v64.m_Id + 1, modelMap.m_Vector.m_Size < v42)
          && (v43 = v42 - modelMap.m_Vector.m_Size, v44 = modelMap.m_Vector.m_Size, v43 != 0) )
        {
          v45 = v43 + modelMap.m_Vector.m_Size;
          if ( v43 + modelMap.m_Vector.m_Size > modelMap.m_Vector.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&modelMap,
              num: modelMap.m_Vector.m_Size + v43 - modelMap.m_Vector.m_Memory.m_nAllocationCount);
            m_Size = modelMap.m_Vector.m_Size;
          }
          m_pMemory = modelMap.m_Vector.m_Memory.m_pMemory;
          modelMap.m_Vector.m_Size = v43 + m_Size;
          v47 = m_Size - v44;
          modelMap.m_Vector.m_pElements = modelMap.m_Vector.m_Memory.m_pMemory;
          if ( v47 > 0 && v43 > 0 )
          {
            _V_memmove(
              dest: &modelMap.m_Vector.m_Memory.m_pMemory[v45],
              src: &modelMap.m_Vector.m_Memory.m_pMemory[v44],
              count: 4 * v47);
            goto LABEL_72;
          }
        }
        else
        {
LABEL_72:
          m_pMemory = modelMap.m_Vector.m_Memory.m_pMemory;
        }
        m_pMemory[v59] = 1;
        goto LABEL_74;
      }
      CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v63, pString: value);
      v34 = modelMap.m_Vector.m_Size;
      v59 = v63.m_Id;
      if ( modelMap.m_Vector.m_Size <= v63.m_Id )
      {
        v35 = v63.m_Id + 1;
        if ( modelMap.m_Vector.m_Size < v35 )
        {
          v36 = v35 - modelMap.m_Vector.m_Size;
          v37 = modelMap.m_Vector.m_Size;
          if ( v36 != 0 )
          {
            v38 = modelMap.m_Vector.m_Size + v36;
            if ( modelMap.m_Vector.m_Size + v36 > modelMap.m_Vector.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&modelMap,
                num: v36 + modelMap.m_Vector.m_Size - modelMap.m_Vector.m_Memory.m_nAllocationCount);
              v34 = modelMap.m_Vector.m_Size;
            }
            v39 = modelMap.m_Vector.m_Memory.m_pMemory;
            modelMap.m_Vector.m_Size = v36 + v34;
            v40 = v34 - v37;
            modelMap.m_Vector.m_pElements = modelMap.m_Vector.m_Memory.m_pMemory;
            if ( v40 <= 0 || v36 <= 0 )
              goto LABEL_63;
            _V_memmove(
              dest: &modelMap.m_Vector.m_Memory.m_pMemory[v38],
              src: &modelMap.m_Vector.m_Memory.m_pMemory[v37],
              count: 4 * v40);
          }
        }
      }
      v39 = modelMap.m_Vector.m_Memory.m_pMemory;
LABEL_63:
      ++v39[v59];
LABEL_74:
      j += 11;
      ++i;
    }
    while ( i < num_entities );
  }
  v48 = 0;
  if ( modelMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v49 = CUtlSymbolTable::String(this: &modelMap.m_SymbolTable, id: (CUtlSymbol)v48);
      CUtlSymbolTable::AddString(this: &modelMap.m_SymbolTable, result: &v63, pString: v49);
      v50 = v63.m_Id;
      v51 = modelMap.m_Vector.m_Size;
      if ( modelMap.m_Vector.m_Size <= v63.m_Id && modelMap.m_Vector.m_Size < v63.m_Id + 1 )
      {
        v52 = v63.m_Id + 1 - modelMap.m_Vector.m_Size;
        i = modelMap.m_Vector.m_Size;
        if ( v52 != 0 )
        {
          v59 = v63.m_Id + 1;
          if ( v59 > modelMap.m_Vector.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&modelMap,
              num: v63.m_Id + 1 - modelMap.m_Vector.m_Memory.m_nAllocationCount);
            v51 = modelMap.m_Vector.m_Size;
          }
          v53 = modelMap.m_Vector.m_Memory.m_pMemory;
          modelMap.m_Vector.m_Size = v52 + v51;
          modelMap.m_Vector.m_pElements = modelMap.m_Vector.m_Memory.m_pMemory;
          v54 = v51 - i;
          if ( v54 <= 0 || v52 <= 0 )
            goto LABEL_85;
          _V_memmove(
            dest: &modelMap.m_Vector.m_Memory.m_pMemory[v59],
            src: &modelMap.m_Vector.m_Memory.m_pMemory[i],
            count: 4 * v54);
        }
      }
      v53 = modelMap.m_Vector.m_Memory.m_pMemory;
LABEL_85:
      v55 = &v53[v50];
      v56 = CUtlSymbolTable::String(this: &modelMap.m_SymbolTable, id: (CUtlSymbol)v48);
      printf(format: "%s,%d\n", v56, *v55);
      ++v48;
    }
    while ( v48 < modelMap.m_SymbolTable.m_Lookup.m_NumElements );
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &modelMap.m_SymbolTable);
  v57 = modelMap.m_Vector.m_Memory.m_pMemory;
  modelMap.m_Vector.m_Size = 0;
  if ( modelMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( modelMap.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: modelMap.m_Vector.m_Memory.m_pMemory);
      v57 = nullptr;
      modelMap.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    modelMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  modelMap.m_Vector.m_pElements = v57;
  if ( modelMap.m_Vector.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
}

//------------------------------------------------------------------------------
// Address: 0x0040EFC0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  double v3; // rdi
  void (__thiscall ***v4)(_DWORD, int, const char **); // eax
  int v5; // ebx
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al
  char *v9; // eax
  char *v10; // edx
  char v11; // cl
  _iobuf *v12; // eax
  _iobuf *v13; // esi
  int v14; // edi
  _iobuf *v15; // eax
  bool v16; // cc
  const char *v17; // eax
  const char *v18; // eax
  int v19; // esi
  double v20; // xmm0_8
  float v21; // xmm1_4
  int i; // esi
  long double v24; // [esp+38h] [ebp-578h]
  long double v25; // [esp+38h] [ebp-578h]
  char fullbspname[260]; // [esp+44h] [ebp-56Ch] BYREF
  char source[1024]; // [esp+148h] [ebp-468h] BYREF
  bool extractlumps[64]; // [esp+548h] [ebp-68h] BYREF
  float v29; // [esp+588h] [ebp-28h]
  float v30; // [esp+58Ch] [ebp-24h]
  Vector wmaxs; // [esp+590h] [ebp-20h] BYREF
  Vector wmins; // [esp+59Ch] [ebp-14h] BYREF
  bool bShowMapBounds; // [esp+5ABh] [ebp-5h]
  bool bHaveAnyToExtract; // [esp+5ACh] [ebp-4h]
  bool bListStaticProps; // [esp+5ADh] [ebp-3h]
  bool bWorldTextureStats; // [esp+5AEh] [ebp-2h]
  bool bModelStats; // [esp+5AFh] [ebp-1h]

  SetupDefaultToolsMinidumpHandler();
  memset(dst: (unsigned __int8 *)extractlumps, value: 0, count: sizeof(extractlumps));
  bHaveAnyToExtract = false;
  SetHDRMode(bHDR: false);
  v4 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v4)(a1: v4, a2: argc, a3: argv);
  InitCommandLineProgram(&argc, (char ***)&argv);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  PrintCommandLine(argc, (char **)argv);
  if ( argc == 1 )
  {
    printf(format: "vbspinfo:  build date(Dec 28 2010)\n");
    printf(format: "usage: vbspinfo [parameters] bspfile [bspfiles]\n");
    printf(format: "   -treeinfo            \n");
    printf(format: "   -worldtexturestats   \n");
    printf(format: "   -modelstats          \n");
    printf(format: "   -liststaticprops     \n");
    printf(format: "   -X[lump ID]          Extract BSP lump to file. i.e -X0 extracts entity lump.\n");
    printf(format: "   -size\t\t\t\tShow .bsp worldmodel bounds\n");
    _Error(a1: "Incorrect syntax.");
  }
  v5 = 1;
  bWorldTextureStats = false;
  bModelStats = false;
  bListStaticProps = false;
  bShowMapBounds = false;
  if ( argc <= 1 )
    return 0;
  v24 = v3;
  while ( _V_stricmp(s1: argv[v5], s2: "-treeinfo") == 0 )
  {
    g_bTreeInfo = true;
LABEL_63:
    if ( ++v5 >= argc )
      return 0;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-drawtree") == 0 )
  {
    g_bDrawTree = true;
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-worldtexturestats") == 0 )
  {
    bWorldTextureStats = true;
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-modelstats") == 0 )
  {
    bModelStats = true;
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-liststaticprops") == 0 )
  {
    bListStaticProps = true;
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-steamlocal") == 0 || _V_stricmp(s1: argv[v5], s2: "-steam") == 0 )
    goto LABEL_63;
  if ( V_strncasecmp(s1: argv[v5], s2: "-X", n: 2) == 0 )
  {
    extractlumps[atoi(nptr: argv[v5] + 2)] = true;
    bHaveAnyToExtract = true;
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: argv[v5], s2: "-size") == 0 )
  {
    bShowMapBounds = true;
    goto LABEL_63;
  }
  if ( !bWorldTextureStats && !bModelStats && !bListStaticProps )
    printf(format: "---------------------\n");
  v6 = argv[v5];
  v7 = source;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
  }
  while ( v8 != 0 );
  V_DefaultExtension(path: source, extension: ".bsp", pathStringLength: 1024);
  v9 = ExpandPath(path: source);
  v10 = (char *)(source - v9);
  do
  {
    v11 = *v9;
    v9[(_DWORD)v10] = *v9;
    ++v9;
  }
  while ( v11 != 0 );
  v12 = fopen(file: source, mode: "rb");
  v13 = v12;
  if ( v12 != nullptr )
  {
    fseek(stream: v12, offset: 0, whence: 2);
    v14 = ftell(stream: v13);
    fclose(stream: v13);
  }
  else
  {
    v14 = 0;
  }
  if ( !bWorldTextureStats && !bModelStats && !bListStaticProps )
    _Msg(a1: "reading %s (%d)\n", source, v14);
  if ( !bHaveAnyToExtract )
  {
    LoadBSPFile(filename: source);
    if ( bWorldTextureStats )
    {
      v15 = __iob_func();
      PrintWorldTextureStats(fp: v15 + 1);
    }
    else if ( bModelStats )
    {
      __iob_func();
      PrintModelStats();
    }
    else if ( bListStaticProps )
    {
      __iob_func();
      PrintListStaticProps();
    }
    else if ( bShowMapBounds )
    {
      printf(
        format: "Full     :  (%8.3f %8.3f %8.3f) - (%8.3f %8.3f %8.3f)\n",
        dmodels[0].mins.x,
        *(float *)&dword_42748B4,
        *(float *)&dword_42748B8,
        *(float *)&dword_42748BC,
        *(float *)&dword_42748C0,
        *(float *)&dword_42748C4);
      v16 = num_entities <= 0;
      if ( num_entities == 0 )
      {
        ParseEntities();
        v16 = num_entities <= 0;
      }
      if ( !v16 )
      {
        while ( strcmp(ValueForKey(ent: entities, key: "classname"), "worldspawn") != 0 )
        {
          ++v5;
          if ( num_entities <= 0 )
            goto LABEL_55;
        }
        memset(&wmins, 0, sizeof(wmins));
        memset(&wmaxs, 0, sizeof(wmaxs));
        v17 = ValueForKey(ent: entities, key: "world_mins");
        sscanf(string: v17, format: "%f %f %f", &wmins, &wmins.y, &wmins.z);
        v18 = ValueForKey(ent: entities, key: "world_maxs");
        sscanf(string: v18, format: "%f %f %f", &wmaxs, &wmaxs.y, &wmaxs.z);
        printf(
          format: "No Skybox:  (%8.3f %8.3f %8.3f) - (%8.3f %8.3f %8.3f)\n",
          wmins.x,
          wmins.y,
          wmins.z,
          wmaxs.x,
          wmaxs.y,
          wmaxs.z);
      }
    }
    else
    {
      PrintBSPFileSizes();
    }
LABEL_55:
    if ( g_bTreeInfo )
    {
      v19 = numnodes;
      v29 = (float)numnodes;
      v20 = (float)numnodes;
      __libm_sse2_log(x: v24);
      *(float *)&v20 = v20;
      v30 = *(float *)&v20;
      __libm_sse2_log(x: v25);
      v21 = (float)(int)(float)(v30 / (float)2.0);
      g_nOptimumDepth = v21;
      g_nMinTreeDepth = 999999;
      g_nMaxTreeDepth = -999999;
      g_TotalTreeDepth = 0;
      g_TotalVariance = 0.0;
      CalculateTreeInfo_R(iNode: iNode, depth: 0);
      printf(
        format: "\n"
        "\t-------------------\n"
        "\tTREE INFO:\n"
        "\t-------------------\n"
        "\tNumber of nodes ------------------ : %d\n"
        "\tOptimum tree depth (logN) -------- : %.3f\n"
        "\tMinimum tree depth --------------- : %d\n"
        "\tMaximum tree depth --------------- : %d\n"
        "\tAverage tree depth --------------- : %.3f\n"
        "\tAverage leaf variance from optimum : %.3f\n"
        "\n",
        v19,
        v21,
        g_nMinTreeDepth,
        g_nMaxTreeDepth,
        (float)((float)g_TotalTreeDepth / v29),
        (float)(g_TotalVariance / v29));
    }
    if ( g_bDrawTree )
      DrawTreeToScratchPad();
    if ( !bWorldTextureStats && !bModelStats && !bListStaticProps )
      printf(format: "---------------------\n");
    goto LABEL_63;
  }
  OpenBSPFile(filename: source);
  _fullpath(UserBuf: fullbspname, path: source, maxlen: 0x104u);
  for ( i = 0; i < 64; ++i )
  {
    if ( extractlumps[i] )
    {
      printf(format: "Extracting lump %d.\n", i);
      WriteLumpToFile(filename: fullbspname, lump: i);
    }
  }
  CloseBSPFile();
  printf(format: "Finished extraction.\n");
  return 0;
}
