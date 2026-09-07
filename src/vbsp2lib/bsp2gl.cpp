// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/bsp2gl.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00420F70
// Name: DumpLumps
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpLumps(unsigned __int8 *pBSPData, void *nBSPDataSize)
{
  int v2; // esi
  unsigned __int8 *v3; // edi

  CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "index, size, offset\n");
  v2 = 0;
  v3 = pBSPData + 12;
  do
  {
    CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "%d, %d, %d\n", v2++, *(_DWORD *)v3, *((_DWORD *)v3 - 1));
    v3 += 16;
  }
  while ( v2 < 64 );
}

//------------------------------------------------------------------------------
// Address: 0x00420FC0
// Name: DecompressVisibility
// Source: json
//------------------------------------------------------------------------------
void __usercall DecompressVisibility(
        unsigned __int8 *pDestData@<edi>,
        int nNumClusters@<eax>,
        const unsigned __int8 *pSrcData)
{
  int v3; // eax
  int v4; // ecx
  int v6; // esi

  v3 = (nNumClusters + 7) / 8;
  v4 = 0;
  while ( v4 < v3 )
  {
    if ( *pSrcData != 0 )
    {
      pDestData[v4++] = *pSrcData++;
    }
    else
    {
      v6 = 0;
      if ( pSrcData[1] != 0 )
      {
        do
        {
          pDestData[v4] = 0;
          ++v6;
          ++v4;
        }
        while ( v6 < pSrcData[1] );
      }
      pSrcData += 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421010
// Name: void DumpLump(void __near *,unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpLump(void *fileHandle, unsigned __int8 *pBSPData, int nBSPDataSize, unsigned int nLumpIndex)
{
  if ( nLumpIndex > 0x3F )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Invalid lump index; must be in the range [0, %d).\n", 64);
  }
  else
  {
    SafeWrite(
      f: fileHandle,
      buffer: &pBSPData[*(_DWORD *)&pBSPData[16 * nLumpIndex + 8]],
      count: *(_DWORD *)&pBSPData[16 * nLumpIndex + 12]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421070
// Name: DumpFaces
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpFaces(void *fileHandle@<edi>, unsigned __int8 *pBSPData)
{
  int v3; // esi
  unsigned __int8 *v4; // esi
  signed int v5; // ebx
  __int16 *v6; // esi
  signed int nNumFaces; // [esp+1Ch] [ebp+8h]

  v3 = *((_DWORD *)pBSPData + 30);
  nNumFaces = *((_DWORD *)pBSPData + 31) / 0x38u;
  v4 = &pBSPData[v3];
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "index, planeIndex, bSide, bOnNode, firstEdge, numEdges, texInfo, dispinfo, unused_fogVolumeID, styles, lightofs, are"
    "a, origFace, lightmap_min0, lightmap_min1, lightmap_size0, lightmap_size1, numPrims, dynShadowsOn?, firstPrim, smoothgrp\n");
  v5 = 0;
  if ( nNumFaces > 0 )
  {
    v6 = (__int16 *)(v4 + 8);
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v5);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d, %d, %d, ",
        (unsigned __int16)*(v6 - 4),
        *((unsigned __int8 *)v6 - 6),
        *((unsigned __int8 *)v6 - 5),
        *((_DWORD *)v6 - 1),
        *v6,
        v6[1]);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %X, %d, %f, %d, ",
        v6[2],
        v6[3],
        *((_DWORD *)v6 + 2),
        *((_DWORD *)v6 + 3),
        *((float *)v6 + 4),
        *((_DWORD *)v6 + 9));
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d, ",
        *((_DWORD *)v6 + 5),
        *((_DWORD *)v6 + 6),
        *((_DWORD *)v6 + 7),
        *((_DWORD *)v6 + 8));
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d\n",
        v6[20] & 0x7FFF,
        (v6[20] & 0x8000) == 0,
        (unsigned __int16)v6[21],
        *((_DWORD *)v6 + 11));
      ++v5;
      v6 += 28;
    }
    while ( v5 < nNumFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421170
// Name: DumpTex
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpTex(unsigned __int8 *pBSPData@<ecx>, void *fileHandle@<edi>)
{
  int v2; // esi
  int v3; // ebx
  float *p_y; // esi
  float *v5; // ebx
  float *v6; // esi
  float *v7; // esi
  texinfo_s *pTexInfo; // [esp+28h] [ebp-18h]
  int nNumTexDatas; // [esp+2Ch] [ebp-14h]
  char *pTexStringData; // [esp+30h] [ebp-10h]
  signed int nNumTexInfos; // [esp+34h] [ebp-Ch]
  dtexdata_t *pTexData; // [esp+38h] [ebp-8h]
  int pTexDataa; // [esp+38h] [ebp-8h]
  int pTexDatab; // [esp+38h] [ebp-8h]
  unsigned __int8 *i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]

  pTexStringData = (char *)&pBSPData[*((_DWORD *)pBSPData + 174)];
  i = &pBSPData[*((_DWORD *)pBSPData + 178)];
  pTexData = (dtexdata_t *)&pBSPData[*((_DWORD *)pBSPData + 10)];
  v2 = *((_DWORD *)pBSPData + 11) >> 5;
  nNumTexDatas = v2;
  nNumTexInfos = *((_DWORD *)pBSPData + 27) / 0x48u;
  pTexInfo = (texinfo_s *)&pBSPData[*((_DWORD *)pBSPData + 26)];
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "index, reflectR, reflectG, reflectB, texName, width, height\n");
  v3 = 0;
  if ( v2 > 0 )
  {
    p_y = &pTexData->reflectivity.y;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v3);
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%f, %f, %f, ", *(p_y - 1), *p_y, p_y[1]);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%s, %d, %d\n",
        &pTexStringData[*(_DWORD *)&i[4 * *((_DWORD *)p_y + 2)]],
        *((_DWORD *)p_y + 3),
        *((_DWORD *)p_y + 4));
      ++v3;
      p_y += 8;
    }
    while ( v3 < nNumTexDatas );
  }
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "\n"
    "\n"
    "index, tex_uX, tex_uY, tex_uZ, tex_uShift, tex_vX, tex_vY, tex_vZ, tex_vShift, lightmap_uX, lightmap_uY, lightmap_uZ"
    ", lightmap_uShift, lightmap_vX, lightmap_vY, lightmap_vZ, lightmap_vShift, flags, texData\n");
  ia = 0;
  if ( nNumTexInfos > 0 )
  {
    v5 = &pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][2];
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", ia);
      v6 = v5 - 8;
      for ( pTexDataa = 2; pTexDataa != 0; --pTexDataa )
      {
        CmdLib_FPrintf(hFile: fileHandle, pFormat: "%f, %f, %f, %f, ", *(v6 - 2), *(v6 - 1), *v6, v6[1]);
        v6 += 4;
      }
      v7 = v5;
      for ( pTexDatab = 2; pTexDatab != 0; --pTexDatab )
      {
        CmdLib_FPrintf(hFile: fileHandle, pFormat: "%f, %f, %f, %f, ", *(v7 - 2), *(v7 - 1), *v7, v7[1]);
        v7 += 4;
      }
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%X, %d\n", *((_DWORD *)v5 + 6), *((_DWORD *)v5 + 7));
      v5 += 18;
      ++ia;
    }
    while ( ia < nNumTexInfos );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421360
// Name: DumpBrushes
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpBrushes(unsigned __int8 *pBSPData@<ecx>, void *fileHandle@<edi>)
{
  signed int v2; // esi
  int v3; // ebx
  int *p_numsides; // esi
  int v5; // ebx
  __int16 *p_dispinfo; // esi
  dbrushside_t *pBrushSides; // [esp+8h] [ebp-10h]
  int nNumBrushes; // [esp+Ch] [ebp-Ch]
  dbrush_t *pBrushes; // [esp+10h] [ebp-8h]
  int nNumBrushSides; // [esp+14h] [ebp-4h]

  pBrushes = (dbrush_t *)&pBSPData[*((_DWORD *)pBSPData + 74)];
  nNumBrushSides = *((_DWORD *)pBSPData + 79) >> 3;
  v2 = *((_DWORD *)pBSPData + 75) / 0xCu;
  nNumBrushes = v2;
  pBrushSides = (dbrushside_t *)&pBSPData[*((_DWORD *)pBSPData + 78)];
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "index, firstSide, numSides, contents\n");
  v3 = 0;
  if ( v2 > 0 )
  {
    p_numsides = &pBrushes->numsides;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v3);
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, %d, %x\n", *(p_numsides - 1), *p_numsides, p_numsides[1]);
      ++v3;
      p_numsides += 3;
    }
    while ( v3 < nNumBrushes );
  }
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "\n\nindex, planeIndex, texInfo, dispInfo, bevel\n");
  v5 = 0;
  if ( nNumBrushSides > 0 )
  {
    p_dispinfo = &pBrushSides->dispinfo;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v5);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d\n",
        (unsigned __int16)*(p_dispinfo - 2),
        *(p_dispinfo - 1),
        *p_dispinfo,
        *((unsigned __int8 *)p_dispinfo + 2));
      ++v5;
      p_dispinfo += 4;
    }
    while ( v5 < nNumBrushSides );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421440
// Name: DumpBSP
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpBSP(unsigned __int8 *pBSPData@<ecx>, void *fileHandle@<esi>)
{
  int v2; // edi
  signed int v3; // ebx
  float *p_y; // edi
  int v5; // ebx
  int *children; // edi
  int v7; // ebx
  $FDC08CDABB02C9E9473686151E1F0C06 *v8; // edi
  int j; // ebx
  int k; // ebx
  unsigned __int64 v11; // [esp+20h] [ebp-40h]
  unsigned __int16 *pLeafBrushes; // [esp+38h] [ebp-28h]
  int nNumLeafBrushes; // [esp+3Ch] [ebp-24h]
  unsigned __int16 *pLeafFaces; // [esp+40h] [ebp-20h]
  dleaf_t *pLeaves; // [esp+44h] [ebp-1Ch]
  dnode_t *pNodes; // [esp+48h] [ebp-18h]
  dmodel_t *pModels; // [esp+4Ch] [ebp-14h]
  int nNumLeaves; // [esp+50h] [ebp-10h]
  int nNumNodes; // [esp+54h] [ebp-Ch]
  int nNumLeafFaces; // [esp+58h] [ebp-8h]
  int i; // [esp+5Ch] [ebp-4h]

  pModels = (dmodel_t *)&pBSPData[*((_DWORD *)pBSPData + 58)];
  nNumNodes = *((_DWORD *)pBSPData + 23) >> 5;
  pNodes = (dnode_t *)&pBSPData[*((_DWORD *)pBSPData + 22)];
  nNumLeaves = *((_DWORD *)pBSPData + 43) >> 5;
  pLeaves = (dleaf_t *)&pBSPData[*((_DWORD *)pBSPData + 42)];
  nNumLeafBrushes = *((_DWORD *)pBSPData + 71) >> 1;
  pLeafBrushes = (unsigned __int16 *)&pBSPData[*((_DWORD *)pBSPData + 70)];
  v2 = *((_DWORD *)pBSPData + 67) >> 1;
  v3 = *((_DWORD *)pBSPData + 59) / 0x30u;
  nNumLeafFaces = v2;
  pLeafFaces = (unsigned __int16 *)&pBSPData[*((_DWORD *)pBSPData + 66)];
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "index, minX, minY, minZ, maxX, maxY, maxZ, originX, originY, originZ, Root Node, 1st Face, Num Faces\n");
  i = 0;
  if ( v3 > 0 )
  {
    p_y = &pModels->maxs.y;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", i);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%f, %f, %f, %f, %f, %f, ",
        *(p_y - 4),
        *(p_y - 3),
        *(p_y - 2),
        *(p_y - 1),
        *p_y,
        p_y[1]);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%f, %f, %f, %d, %d, %d\n",
        p_y[2],
        p_y[3],
        p_y[4],
        *((_DWORD *)p_y + 5),
        *((_DWORD *)p_y + 6),
        *((_DWORD *)p_y + 7));
      p_y += 12;
      ++i;
    }
    while ( i < v3 );
    v2 = nNumLeafFaces;
  }
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "\n\nindex, planeIndex, child0, child1, minX, minY, minZ, maxX, maxY, maxZ, firstFace, numFaces, area\n");
  v5 = 0;
  if ( nNumNodes > 0 )
  {
    children = pNodes->children;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v5);
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, %d, %d, ", *(children - 1), *children, children[1]);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, ",
        *((__int16 *)children + 4),
        *((__int16 *)children + 5),
        *((__int16 *)children + 6));
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, ",
        *((__int16 *)children + 7),
        *((__int16 *)children + 8),
        *((__int16 *)children + 9));
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d\n",
        *((unsigned __int16 *)children + 10),
        *((unsigned __int16 *)children + 11),
        *((__int16 *)children + 12));
      ++v5;
      children += 8;
    }
    while ( v5 < nNumNodes );
    v2 = nNumLeafFaces;
  }
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "\n"
    "\n"
    "index, contents, cluster, area, flags, minX, minY, minZ, maxX, maxY, maxZ, firstLeafFace, numLeafFaces, firstLeafBru"
    "sh, numLeafBrushes, leafWater\n");
  v7 = 0;
  if ( nNumLeaves > 0 )
  {
    v8 = &pLeaves->___u2;
    do
    {
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", v7);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d, ",
        *(_DWORD *)&v8[-3].bf,
        *(_WORD *)&v8[-1],
        (__int16)(*(_WORD *)v8 << 7) >> 7,
        *(_WORD *)v8 >> 9);
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, %d, %d, ", *(_WORD *)&v8[1], *(_WORD *)&v8[2], *(_WORD *)&v8[3]);
      CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, %d, %d, ", *(_WORD *)&v8[4], *(_WORD *)&v8[5], *(_WORD *)&v8[6]);
      v11 = __PAIR64__(*(_WORD *)&v8[9], *(_WORD *)&v8[8]);
      CmdLib_FPrintf(
        hFile: fileHandle,
        pFormat: "%d, %d, %d, %d, %d,\n",
        *(_WORD *)&v8[7],
        (_DWORD)v11,
        HIDWORD(v11),
        *(_WORD *)&v8[10],
        *(_WORD *)&v8[11]);
      ++v7;
      v8 += 16;
    }
    while ( v7 < nNumLeaves );
    v2 = nNumLeafFaces;
  }
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "\n\nLeaf Faces\n");
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "index, faceIndex\n");
  for ( j = 0; j < v2; ++j )
  {
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", j);
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d\n", pLeafFaces[j]);
  }
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "\n\nLeaf Brushes\n");
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "index, brushIndex\n");
  for ( k = 0; k < nNumLeafBrushes; ++k )
  {
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, ", k);
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d\n", pLeafBrushes[k]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004217B0
// Name: DumpPlanes
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpPlanes(void *nBSPDataSize)
{
  unsigned __int8 *pBSPData; // ecx
  signed int v2; // ebx
  unsigned __int8 *v3; // esi
  signed int v4; // edi
  unsigned __int8 *v5; // esi

  v2 = *((_DWORD *)pBSPData + 7) / 0x14u;
  v3 = &pBSPData[*((_DWORD *)pBSPData + 6)];
  CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "index, nX, nY, nZ, dist, type\n");
  v4 = 0;
  if ( v2 > 0 )
  {
    v5 = v3 + 12;
    do
    {
      CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "%d, ", v4);
      CmdLib_FPrintf(
        hFile: nBSPDataSize,
        pFormat: "%f, %f, %f, %f, %d\n",
        *((float *)v5 - 3),
        *((float *)v5 - 2),
        *((float *)v5 - 1),
        *(float *)v5,
        *((_DWORD *)v5 + 1));
      ++v4;
      v5 += 20;
    }
    while ( v4 < v2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421850
// Name: DumpStaticProps
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpStaticProps(void *fileHandle@<edi>, unsigned __int8 *pBSPData)
{
  unsigned __int8 *v2; // esi
  unsigned int v3; // ebx
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  int v7; // ebx
  const char *v8; // esi
  int v9; // ebx
  unsigned __int16 *v10; // esi
  int v11; // ebx
  unsigned __int16 *v12; // esi
  unsigned int nDataSize; // [esp+38h] [ebp-8h]
  unsigned __int8 *pData; // [esp+3Ch] [ebp-4h]

  v2 = &pBSPData[*((_DWORD *)pBSPData + 142)];
  nDataSize = *((_DWORD *)pBSPData + 143);
  if ( nDataSize < 0x14 )
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "No static prop data.\n");
  v3 = *(_DWORD *)v2;
  pData = v2 + 4;
  if ( nDataSize < 16 * *(_DWORD *)v2 + 4 )
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "Corrupt game lump data.\n");
  v4 = 0;
  if ( v3 != 0 )
  {
    v5 = pData;
    do
    {
      if ( *(_DWORD *)v5 == 1936749168 )
        break;
      ++v4;
      v5 += 16;
    }
    while ( v4 < v3 );
  }
  if ( v4 == v3 )
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "Static prop data not found.\n");
  v6 = &pBSPData[*(_DWORD *)&pData[16 * v4 + 8]];
  v7 = *(_DWORD *)v6;
  v8 = (const char *)(v6 + 4);
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "Dictionary Entry\n");
  for ( ; v7 != 0; --v7 )
  {
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%s\n", v8);
    v8 += 128;
  }
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "\n\n");
  v9 = *(_DWORD *)v8;
  v10 = (unsigned __int16 *)(v8 + 4);
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "Leaf Entry\n");
  for ( ; v9 != 0; --v9 )
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d\n", *v10++);
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "\n\n");
  v11 = *(_DWORD *)v10;
  v12 = v10 + 2;
  CmdLib_FPrintf(
    hFile: fileHandle,
    pFormat: "OriginX, OriginY, OriginZ, AnglesX, AnglesY, AnglesZ, Prop Type, First Leaf, Leaf Count\n");
  for ( ; v11 != 0; --v11 )
  {
    CmdLib_FPrintf(
      hFile: fileHandle,
      pFormat: "%f, %f, %f, %f, %f, %f, ",
      *(float *)v12,
      *((float *)v12 + 1),
      *((float *)v12 + 2),
      *((float *)v12 + 3),
      *((float *)v12 + 4),
      *((float *)v12 + 5));
    CmdLib_FPrintf(hFile: fileHandle, pFormat: "%d, %d, %d\n", v12[12], v12[13], v12[14]);
    v12 += 36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421A00
// Name: WriteGLFace
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteGLFace(
        unsigned __int8 *pBSPData@<eax>,
        int nFaceIndex@<edx>,
        void *fileHandle,
        float nBSPDataSize,
        Vector vColor)
{
  int v5; // ebx
  int v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // edi
  int i; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // ecx
  Vector *pVertexData; // [esp+48h] [ebp-Ch]
  dedge_t fileEdge; // [esp+4Ch] [ebp-8h]
  int *pSurfEdgeData; // [esp+50h] [ebp-4h]

  v5 = *((_DWORD *)pBSPData + 50);
  v6 = *((_DWORD *)pBSPData + 30);
  pSurfEdgeData = (int *)&pBSPData[*((_DWORD *)pBSPData + 54)];
  v7 = &pBSPData[v5];
  v8 = &pBSPData[56 * nFaceIndex + v6];
  pVertexData = (Vector *)&pBSPData[*((_DWORD *)pBSPData + 14)];
  CmdLib_FPrintf(hFile: fileHandle, pFormat: "%i\n", *((__int16 *)v8 + 4));
  for ( i = 0; i < *((__int16 *)v8 + 4); ++i )
  {
    v10 = pSurfEdgeData[i + *((_DWORD *)v8 + 1)];
    v11 = 0;
    if ( v10 < 0 )
    {
      v10 = -v10;
      v11 = 1;
    }
    fileEdge = *(dedge_t *)&v7[4 * v10];
    v12 = fileEdge.v[v11];
    CmdLib_FPrintf(
      hFile: fileHandle,
      pFormat: "%6.3f %6.3f %6.3f %6.3f %6.3f %6.3f\n",
      pVertexData[v12].x,
      pVertexData[v12].y,
      pVertexData[v12].z,
      nBSPDataSize,
      vColor.x,
      vColor.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B20
// Name: WriteGLLeaf
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteGLLeaf(unsigned __int8 *pBSPData@<esi>, int nLeafIndex@<edx>, void *fileHandle)
{
  unsigned __int8 *v3; // eax
  int v4; // edx
  unsigned __int8 *v5; // ecx
  int v6; // edi
  unsigned __int8 *v7; // ebx
  int v8; // edx
  Vector v9; // [esp-8h] [ebp-20h]
  __m128i v10; // [esp+8h] [ebp-10h] BYREF

  v3 = &pBSPData[32 * nLeafIndex + *((_DWORD *)pBSPData + 42)];
  v4 = *((unsigned __int16 *)v3 + 10);
  v5 = &pBSPData[*((_DWORD *)pBSPData + 66)];
  v6 = 0;
  v10.m128i_i32[3] = (int)v3;
  if ( *((_WORD *)v3 + 11) != 0 )
  {
    v7 = &v5[2 * v4];
    do
    {
      v8 = *(unsigned __int16 *)v7;
      dword_469090 += 23;
      *(float *)&v10.m128i_i32[2] = (float)(unsigned __int8)dword_469090 * 0.0039215689;
      v10.m128i_i32[0] = v10.m128i_i32[2];
      v10.m128i_i32[1] = v10.m128i_i32[2];
      v9.y = *(float *)&v10.m128i_i32[2];
      WriteGLFace(
        pBSPData,
        nFaceIndex: v8,
        fileHandle,
        nBSPDataSize: *(float *)_mm_loadl_epi64(&v10).m128i_i32,
        vColor: v9);
      ++v6;
      v7 += 2;
    }
    while ( v6 < *(unsigned __int16 *)(v10.m128i_i32[3] + 22) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421BC0
// Name: WriteGLNode
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteGLNode(void *fileHandle, unsigned __int8 *pBSPData, int nBSPDataSize, int nNodeIndex)
{
  unsigned __int8 *v5; // edi

  while ( nNodeIndex >= 0 )
  {
    v5 = &pBSPData[32 * nNodeIndex + *((_DWORD *)pBSPData + 22)];
    WriteGLNode(fileHandle, pBSPData, nBSPDataSize, nNodeIndex: *((_DWORD *)v5 + 1));
    nNodeIndex = *((_DWORD *)v5 + 2);
  }
  WriteGLLeaf(pBSPData, nLeafIndex: -1 - nNodeIndex, fileHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00421C10
// Name: void WriteGLBSPFile(void __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteGLBSPFile(void *fileHandle, unsigned __int8 *pBSPData, int nBSPDataSize)
{
  unsigned int v4; // edx
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // edi
  bool v8; // zf
  unsigned int v9; // [esp+4h] [ebp-4h]
  unsigned __int8 *pBSPDataa; // [esp+14h] [ebp+Ch]

  v4 = *((_DWORD *)pBSPData + 59) / 0x30u;
  if ( v4 != 0 )
  {
    v5 = &pBSPData[*((_DWORD *)pBSPData + 58) + 36];
    pBSPDataa = v5;
    v9 = v4;
    do
    {
      v6 = *(_DWORD *)v5;
      if ( v6 >= 0 )
      {
        v7 = &pBSPData[32 * v6 + *((_DWORD *)pBSPData + 22)];
        WriteGLNode(fileHandle, pBSPData, nBSPDataSize, nNodeIndex: *((_DWORD *)v7 + 1));
        WriteGLNode(fileHandle, pBSPData, nBSPDataSize, nNodeIndex: *((_DWORD *)v7 + 2));
      }
      else
      {
        WriteGLLeaf(pBSPData, nLeafIndex: -1 - v6, fileHandle);
      }
      v5 = pBSPDataa + 48;
      v8 = v9-- == 1;
      pBSPDataa += 48;
    }
    while ( !v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421CA0
// Name: DumpVisibility
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpVisibility(unsigned __int8 *pBSPData@<eax>, void *nBSPDataSize)
{
  unsigned __int8 *v2; // esi
  int v3; // edi
  int m_Size; // eax
  int v5; // eax
  int j; // edi
  int v7; // eax
  int k; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > decompressedRow; // [esp+8h] [ebp-20h] BYREF
  int v10; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  _DWORD *v12; // [esp+24h] [ebp-4h]

  v2 = &pBSPData[*((_DWORD *)pBSPData + 18)];
  memset(&decompressedRow, 0, sizeof(decompressedRow));
  if ( *((_DWORD *)pBSPData + 19) != 0 )
  {
    CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "# clusters, %d\n", *(_DWORD *)v2);
    v3 = (*(_DWORD *)v2 + 7) / 8;
    m_Size = 0;
    decompressedRow.m_Size = 0;
    if ( v3 != 0 )
    {
      if ( v3 > 0 )
      {
        CUtlMemory<char,int>::Grow(this: &decompressedRow.m_Memory, num: v3);
        m_Size = decompressedRow.m_Size;
      }
      if ( m_Size > 0 && v3 > 0 )
        _V_memmove(
          dest: &decompressedRow.m_Memory.m_pMemory[v3],
          src: decompressedRow.m_Memory.m_pMemory,
          count: m_Size);
    }
    CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "Cluster PVS:\n");
    v5 = *(_DWORD *)v2;
    i = 0;
    if ( v5 > 0 )
    {
      v12 = v2 + 4;
      do
      {
        DecompressVisibility(pDestData: decompressedRow.m_Memory.m_pMemory, nNumClusters: v5, pSrcData: &v2[*v12]);
        for ( j = 0; j < *(_DWORD *)v2; ++j )
          CmdLib_FPrintf(
            hFile: nBSPDataSize,
            pFormat: "%d, ",
            ((unsigned __int8)(1 << (j % 8)) & decompressedRow.m_Memory.m_pMemory[j / 8]) != 0);
        CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "\n");
        v5 = *(_DWORD *)v2;
        v12 += 2;
        ++i;
      }
      while ( i < v5 );
    }
    CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "Cluster PAS:\n");
    v7 = *(_DWORD *)v2;
    i = 0;
    if ( v7 > 0 )
    {
      v12 = v2 + 8;
      do
      {
        DecompressVisibility(pDestData: decompressedRow.m_Memory.m_pMemory, nNumClusters: v7, pSrcData: &v2[*v12]);
        for ( k = 0; k < *(_DWORD *)v2; ++k )
        {
          v10 = 1 << (k % 8);
          CmdLib_FPrintf(
            hFile: nBSPDataSize,
            pFormat: "%d, ",
            ((unsigned __int8)v10 & decompressedRow.m_Memory.m_pMemory[k / 8]) != 0);
        }
        CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "\n");
        v7 = *(_DWORD *)v2;
        v12 += 2;
        ++i;
      }
      while ( i < v7 );
    }
    if ( decompressedRow.m_Memory.m_nGrowSize >= 0 && decompressedRow.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: decompressedRow.m_Memory.m_pMemory);
  }
  else
  {
    CmdLib_FPrintf(hFile: nBSPDataSize, pFormat: "No cluster data.\n");
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&decompressedRow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421EC0
// Name: void DumpBSPInfo(char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpBSPInfo(const char *pPrefixName, unsigned __int8 *pBSPData)
{
  void *v2; // edi
  void *v3; // esi
  void *v4; // edi
  char path[260]; // [esp+Ch] [ebp-124h] BYREF
  void *lumpFile; // [esp+110h] [ebp-20h]
  void *staticPropFile; // [esp+114h] [ebp-1Ch]
  void *entitiesFile; // [esp+118h] [ebp-18h]
  void *planesFile; // [esp+11Ch] [ebp-14h]
  void *brushesFile; // [esp+120h] [ebp-10h]
  void *facesFile; // [esp+124h] [ebp-Ch]
  void *visibilityFile; // [esp+128h] [ebp-8h]
  void *texFile; // [esp+12Ch] [ebp-4h]

  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_lumps.csv", pPrefixName);
  v2 = SafeOpenWrite(filename: path);
  lumpFile = v2;
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_faces.csv", pPrefixName);
  facesFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_tex.csv", pPrefixName);
  texFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_ent.txt", pPrefixName);
  entitiesFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_brush.csv", pPrefixName);
  brushesFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_bsp.csv", pPrefixName);
  v3 = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_planes.csv", pPrefixName);
  planesFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_vis.csv", pPrefixName);
  visibilityFile = SafeOpenWrite(filename: path);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "%s_sprop.csv", pPrefixName);
  staticPropFile = SafeOpenWrite(filename: path);
  DumpLumps(pBSPData, nBSPDataSize: v2);
  DumpFaces(fileHandle: facesFile, pBSPData);
  DumpTex(pBSPData, fileHandle: texFile);
  SafeWrite(f: entitiesFile, buffer: &pBSPData[*((_DWORD *)pBSPData + 2)], count: *((_DWORD *)pBSPData + 3));
  DumpBrushes(pBSPData, fileHandle: brushesFile);
  DumpBSP(pBSPData, fileHandle: v3);
  DumpPlanes(nBSPDataSize: planesFile);
  DumpVisibility(pBSPData, nBSPDataSize: visibilityFile);
  v4 = staticPropFile;
  DumpStaticProps(fileHandle: staticPropFile, pBSPData);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
  g_pFileSystem->Close(this: g_pFileSystem, a2: visibilityFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: planesFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
  g_pFileSystem->Close(this: g_pFileSystem, a2: brushesFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: entitiesFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: texFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: facesFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: lumpFile);
}
