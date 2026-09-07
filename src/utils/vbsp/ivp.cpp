// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/ivp.cpp
// Functions: 41
// ============================================================

#include "utils\vbsp\ivp.h"

//------------------------------------------------------------------------------
// Address: 0x00407580
// Name: bool WaterLessFunc(struct WaterTexInfo const __near &,struct WaterTexInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl WaterLessFunc(const StaticPropLookup_t *src1, const StaticPropLookup_t *src2)
{
  return src1->m_ModelName.m_Id < src2->m_ModelName.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00412CD0
// Name: void DumpCollideToGlView(class CPhysCollide __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpCollideToGlView(int a1@<edi>, Vector *pCollide, const char *pFilename)
{
  Vector *v3; // esi
  const char *v4; // edi
  int v5; // esi
  _iobuf *v6; // edi
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int vertCount; // [esp+2Ch] [ebp-4h]

  v3 = pCollide;
  if ( pCollide != nullptr )
  {
    v4 = pFilename;
    _Msg(a1: "Writing %s...\n", pFilename);
    v5 = ((int (__thiscall *)(IPhysicsCollision *, Vector *, Vector **, int))physcollision->CreateDebugMesh)(
           a1: physcollision,
           a2: v3,
           a3: &pCollide,
           a4: a1);
    vertCount = v5;
    v6 = fopen(file: v4, mode: "w");
    v7 = v5 / 3;
    if ( v5 / 3 > 0 )
    {
      v8 = 0;
      v9 = v7;
      do
      {
        fprintf(str: v6, format: "3\n");
        fprintf(str: v6, format: "%6.3f %6.3f %6.3f 1 0 0\n", pCollide[v8].x, pCollide[v8].y, pCollide[v8].z);
        fprintf(
          str: v6,
          format: "%6.3f %6.3f %6.3f 0 1 0\n",
          pCollide[v8 + 1].x,
          pCollide[v8 + 1].y,
          pCollide[v8 + 1].z);
        fprintf(
          str: v6,
          format: "%6.3f %6.3f %6.3f 0 0 1\n",
          pCollide[v8 + 2].x,
          pCollide[v8 + 2].y,
          pCollide[v8 + 2].z);
        v8 += 3;
        --v9;
      }
      while ( v9 != 0 );
      v5 = vertCount;
    }
    fclose(stream: v6);
    ((void (__thiscall *)(IPhysicsCollision *, int))physcollision->DestroyDebugMesh)(a1: physcollision, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412E40
// Name: public: CPhysCollisionEntryStaticMesh::CPhysCollisionEntryStaticMesh(class CPhysCollide __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryStaticMesh *__thiscall CPhysCollisionEntryStaticMesh::CPhysCollisionEntryStaticMesh(
        CPhysCollisionEntryStaticMesh *this,
        CPhysCollide *pCollide,
        const char *pMaterialName)
{
  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntryStaticMesh_vtbl *)&CPhysCollisionEntryStaticMesh::`vftable';
  this->m_pMaterial = pMaterialName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412E60
// Name: public: CPhysCollisionEntryFluid::CPhysCollisionEntryFluid(class CPhysCollide __near *,char const __near *,float,class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryFluid *__thiscall CPhysCollisionEntryFluid::CPhysCollisionEntryFluid(
        CPhysCollisionEntryFluid *this,
        CPhysCollide *pCollide,
        const char *pSurfaceProp,
        float damping,
        const Vector *normal,
        float dist,
        int nContents)
{
  char *v8; // eax
  const char *v9; // ecx
  char *v10; // edx
  char v11; // al

  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntryFluid_vtbl *)&CPhysCollisionEntryFluid::`vftable';
  this->m_surfaceNormal = *normal;
  this->m_surfaceDist = dist;
  v8 = (char *)MemAlloc_Alloc(nSize: strlen(pSurfaceProp) + 1);
  this->m_pSurfaceProp = v8;
  v9 = pSurfaceProp;
  v10 = v8;
  do
  {
    v11 = *v9;
    *v10++ = *v9++;
  }
  while ( v11 != 0 );
  this->m_damping = damping;
  this->m_contentsMask = nContents;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412EF0
// Name: public: int CPlaneList::GetFirstBrushSide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlaneList::GetFirstBrushSide(CPlaneList *this)
{
  signed int v1; // eax
  dbrush_t *v2; // ebx
  int numsides; // esi
  int v4; // ecx
  char *v5; // edx
  int result; // eax
  bool *m_brushAdded; // [esp+Ch] [ebp-8h]
  int brushnumber; // [esp+10h] [ebp-4h]

  v1 = 0;
  brushnumber = 0;
  if ( (int)numbrushes <= 0 )
    return 0;
  v2 = dbrushes;
  m_brushAdded = this->m_brushAdded;
  while ( 1 )
  {
    if ( m_brushAdded[v1] )
    {
      numsides = v2->numsides;
      v4 = 0;
      if ( numsides > 0 )
        break;
    }
LABEL_9:
    ++v1;
    ++v2;
    brushnumber = v1;
    if ( v1 >= (int)numbrushes )
      return 0;
  }
  v5 = &byte_52B500E[8 * v2->firstside];
  while ( 1 )
  {
    result = v2->firstside + v4;
    if ( *v5 == 0 )
      return result;
    ++v4;
    v5 += 8;
    if ( v4 >= numsides )
    {
      v1 = brushnumber;
      goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F60
// Name: void EmitWaterMaterialFile(struct WaterTexInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitWaterMaterialFile(WaterTexInfo *wti)
{
  int m_nWaterDepth; // edi
  const char *v2; // eax
  int v3; // eax
  char v4; // cl
  const char *v5; // eax
  char waterTextureName[512]; // [esp+4h] [ebp-420h] BYREF
  char string[512]; // [esp+204h] [ebp-220h] BYREF
  char szDepth[32]; // [esp+404h] [ebp-20h] BYREF

  if ( wti != nullptr )
  {
    m_nWaterDepth = wti->m_nWaterDepth;
    v2 = CUtlSymbol::String(this: &wti->m_MaterialName);
    sprintf(string, format: "maps/%s/%s_depth_%i", mapbase, v2, m_nWaterDepth);
    strlwr(string);
    v3 = 0;
    do
    {
      v4 = string[v3];
      waterTextureName[v3++] = v4;
    }
    while ( v4 != 0 );
    sprintf(string: szDepth, format: "%i", wti->m_nWaterDepth);
    v5 = CUtlSymbol::String(this: &wti->m_MaterialName);
    CreateMaterialPatch(
      pOriginalMaterialName: v5,
      pNewMaterialName: waterTextureName,
      pNewKey: "$waterdepth",
      pNewValue: szDepth,
      nPatchType: PATCH_INSERT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413010
// Name: BuildWaterLeaf
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildWaterLeaf(node_t *pLeafIn)
{
  waterleaf_t *waterLeafOut; // ecx
  portal_t *i; // esi
  side_t *side; // eax
  BOOL v4; // edi
  float *p_x; // edx
  float z; // xmm0_4
  float v7; // xmm1_4
  double v8; // st7

  waterLeafOut->pNode = pLeafIn;
  waterLeafOut->waterLeafIndex = pLeafIn->diskId;
  waterLeafOut->outsideLeafIndex = -1;
  waterLeafOut->hasSurface = false;
  waterLeafOut->surfaceDist = 16384.0;
  waterLeafOut->surfaceNormal.x = 0.0;
  waterLeafOut->surfaceNormal.y = 0.0;
  waterLeafOut->surfaceNormal.z = 1.0;
  waterLeafOut->planenum = -1;
  waterLeafOut->surfaceTexInfo = -1;
  waterLeafOut->minZ = 16384.0;
  for ( i = pLeafIn->portals; i != nullptr; i = i->next[!v4] )
  {
    side = i->side;
    v4 = i->nodes[0] == pLeafIn;
    if ( side != nullptr && ((unsigned int)&unk_200403B & i->nodes[v4]->contents) == 0 )
    {
      p_x = &g_MainMap->mapplanes[side->planenum].normal.x;
      if ( !waterLeafOut->hasSurface
        || (z = waterLeafOut->surfaceNormal.z, v7 = p_x[2], z <= v7) && (z != v7 || waterLeafOut->surfaceDist < p_x[3]) )
      {
        if ( p_x[2] > 0.0 )
        {
          waterLeafOut->surfaceDist = p_x[3];
          waterLeafOut->surfaceNormal.x = *p_x;
          waterLeafOut->surfaceNormal.y = p_x[1];
          v8 = p_x[2];
          waterLeafOut->hasSurface = true;
          waterLeafOut->surfaceNormal.z = v8;
          waterLeafOut->outsideLeafIndex = i->nodes[v4]->diskId;
          waterLeafOut->surfaceTexInfo = i->side->texinfo;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413110
// Name: int FirstWaterTexinfo(struct bspbrush_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FirstWaterTexinfo(bspbrush_t *brushlist, int contents)
{
  bspbrush_t *v2; // esi
  mapbrush_t *original; // ecx
  int numsides; // edx
  int v5; // eax
  int *p_contents; // ecx

  v2 = brushlist;
  if ( brushlist == nullptr )
    return 0;
  while ( 1 )
  {
    original = v2->original;
    if ( (contents & original->contents) != 0 )
    {
      numsides = original->numsides;
      v5 = 0;
      if ( numsides > 0 )
        break;
    }
LABEL_7:
    v2 = v2->next;
    if ( v2 == nullptr )
      return 0;
  }
  p_contents = &original->original_sides->contents;
  while ( (contents & *p_contents) == 0 )
  {
    ++v5;
    p_contents += 23;
    if ( v5 >= numsides )
      goto LABEL_7;
  }
  return v2->original->original_sides[v5].texinfo;
}

//------------------------------------------------------------------------------
// Address: 0x00413170
// Name: FindBrushSide
// Source: json
//------------------------------------------------------------------------------
dbrushside_t *__usercall FindBrushSide@<eax>(int brushIndex@<eax>, const Vector *normal)
{
  float v2; // xmm0_4
  int v3; // ecx
  int v4; // eax
  dbrush_t *v5; // ecx
  int v6; // esi
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  unsigned int v10; // edi
  dbrushside_t *v11; // ecx
  dplane_t *v12; // edx
  dplane_t *v13; // edx
  dplane_t *v14; // edx
  dbrushside_t *v15; // edx
  int v16; // eax
  int i; // [esp+0h] [ebp-Ch]
  dbrush_t *pbrush; // [esp+4h] [ebp-8h]
  dbrushside_t *out; // [esp+8h] [ebp-4h]

  v2 = -1.0;
  v3 = brushIndex;
  v4 = dword_6EAA86C[3 * brushIndex];
  v5 = &dbrushes[v3];
  v6 = 0;
  pbrush = v5;
  out = nullptr;
  if ( v4 >= 4 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    v10 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v11 = (dbrushside_t *)((char *)&unk_52B5010 + 8 * v5->firstside);
    i = 4 * v10;
    do
    {
      v12 = &dplanes[v11[-1].planenum];
      if ( (float)((float)((float)(*(float *)&dword_7638ADC[5 * v11[-1].planenum] * y) + (float)(x * v12->normal.x))
                 + (float)(v12->normal.z * z)) > v2 )
      {
        v2 = (float)((float)(*(float *)&dword_7638ADC[5 * v11[-1].planenum] * y) + (float)(x * v12->normal.x))
           + (float)(v12->normal.z * z);
        out = v11 - 1;
      }
      if ( (float)((float)((float)(*(float *)&dword_7638ADC[5 * v11->planenum] * y)
                         + (float)(x * dplanes[v11->planenum].normal.x))
                 + (float)(dplanes[v11->planenum].normal.z * z)) > v2 )
      {
        v2 = (float)((float)(*(float *)&dword_7638ADC[5 * v11->planenum] * y)
                   + (float)(x * dplanes[v11->planenum].normal.x))
           + (float)(dplanes[v11->planenum].normal.z * z);
        out = v11;
      }
      v13 = &dplanes[v11[1].planenum];
      if ( (float)((float)((float)(*(float *)&dword_7638ADC[5 * v11[1].planenum] * y) + (float)(x * v13->normal.x))
                 + (float)(v13->normal.z * z)) > v2 )
      {
        v2 = (float)((float)(*(float *)&dword_7638ADC[5 * v11[1].planenum] * y) + (float)(x * v13->normal.x))
           + (float)(v13->normal.z * z);
        out = v11 + 1;
      }
      v14 = &dplanes[v11[2].planenum];
      if ( (float)((float)((float)(*(float *)&dword_7638ADC[5 * v11[2].planenum] * y) + (float)(x * v14->normal.x))
                 + (float)(v14->normal.z * z)) > v2 )
      {
        v2 = (float)((float)(*(float *)&dword_7638ADC[5 * v11[2].planenum] * y) + (float)(x * v14->normal.x))
           + (float)(v14->normal.z * z);
        out = v11 + 2;
      }
      v11 += 4;
      --v10;
    }
    while ( v10 != 0 );
    v5 = pbrush;
    v6 = i;
  }
  if ( v6 < v4 )
  {
    v15 = &dbrushsides[v6 + v5->firstside];
    v16 = v4 - v6;
    do
    {
      if ( (float)((float)((float)(*(float *)&dword_7638ADC[5 * v15->planenum] * normal->y)
                         + (float)(normal->x * dplanes[v15->planenum].normal.x))
                 + (float)(dplanes[v15->planenum].normal.z * normal->z)) > v2 )
      {
        v2 = (float)((float)(*(float *)&dword_7638ADC[5 * v15->planenum] * normal->y)
                   + (float)(normal->x * dplanes[v15->planenum].normal.x))
           + (float)(dplanes[v15->planenum].normal.z * normal->z);
        out = v15;
      }
      ++v15;
      --v16;
    }
    while ( v16 != 0 );
  }
  return out;
}

//------------------------------------------------------------------------------
// Address: 0x004135A0
// Name: void DumpCollideToPHY(class CPhysCollide __near *,class CTextBuffer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpCollideToPHY(CPhysCollide *pCollide, CTextBuffer *text, const char *pFilename)
{
  _iobuf *v3; // esi
  char *v4; // edi
  phyheader_s header; // [esp+Ch] [ebp-14h] BYREF
  int size; // [esp+1Ch] [ebp-4h] BYREF

  _Msg(a1: "Writing %s...\n", pFilename);
  v3 = fopen(file: pFilename, mode: "wb");
  header.id = 0;
  header.checkSum = 0;
  header.size = 16;
  header.solidCount = 1;
  fwrite(buffer: &header, size: 0x10u, count: 1u, stream: v3);
  size = physcollision->CollideSize(this: physcollision, a2: pCollide);
  fwrite(buffer: &size, size: 4u, count: 1u, stream: v3);
  v4 = (char *)MemAlloc_Alloc(nSize: size);
  physcollision->CollideWrite(this: physcollision, a2: v4, a3: pCollide, a4: false);
  fwrite(buffer: v4, size, count: 1u, stream: v3);
  fwrite(buffer: text->m_buffer.m_Memory.m_pMemory, size: text->m_buffer.m_Size, count: 1u, stream: v3);
  fclose(stream: v3);
  free(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00413670
// Name: public: virtual void CPhysCollisionEntrySolid::DumpCollide(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntrySolid::DumpCollide(
        CPhysCollisionEntrySolid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  char string[128]; // [esp+8h] [ebp-80h] BYREF

  sprintf(string, format: "%s%03d.phy", "collide", modelIndex);
  DumpCollideToPHY(pCollide: this->m_pCollide, text: pTextBuffer, pFilename: string);
  sprintf(string, format: "%s%03d.txt", "collide", modelIndex);
  DumpCollideToGlView(a1: modelIndex, pCollide: (Vector *)this->m_pCollide, pFilename: string);
}

//------------------------------------------------------------------------------
// Address: 0x004136E0
// Name: public: virtual void CPhysCollisionEntryStaticSolid::DumpCollide(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticSolid::DumpCollide(
        CPhysCollisionEntryStaticSolid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  char tmp[128]; // [esp+8h] [ebp-100h] BYREF
  char string[128]; // [esp+88h] [ebp-80h] BYREF

  sprintf(string: tmp, format: "static%02d", modelIndex);
  sprintf(string, format: "%s%03d.phy", tmp, collideIndex);
  DumpCollideToPHY(pCollide: this->m_pCollide, text: pTextBuffer, pFilename: string);
  sprintf(string, format: "%s%03d.txt", tmp, collideIndex);
  DumpCollideToGlView(a1: collideIndex, pCollide: (Vector *)this->m_pCollide, pFilename: string);
}

//------------------------------------------------------------------------------
// Address: 0x00413760
// Name: public: virtual void CPhysCollisionEntryStaticMesh::DumpCollide(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticMesh::DumpCollide(
        CPhysCollisionEntryStaticMesh *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  char tmp[128]; // [esp+8h] [ebp-100h] BYREF
  char string[128]; // [esp+88h] [ebp-80h] BYREF

  sprintf(string: tmp, format: "mesh%02d", modelIndex);
  sprintf(string, format: "%s%03d.phy", tmp, collideIndex);
  DumpCollideToPHY(pCollide: this->m_pCollide, text: pTextBuffer, pFilename: string);
  sprintf(string, format: "%s%03d.txt", tmp, collideIndex);
  DumpCollideToGlView(a1: collideIndex, pCollide: (Vector *)this->m_pCollide, pFilename: string);
}

//------------------------------------------------------------------------------
// Address: 0x004137E0
// Name: public: virtual void CPhysCollisionEntryFluid::DumpCollide(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryFluid::DumpCollide(
        CPhysCollisionEntryFluid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  char tmp[128]; // [esp+8h] [ebp-100h] BYREF
  char string[128]; // [esp+88h] [ebp-80h] BYREF

  sprintf(string: tmp, format: "water%02d", modelIndex);
  sprintf(string, format: "%s%03d.phy", tmp, collideIndex);
  DumpCollideToPHY(pCollide: this->m_pCollide, text: pTextBuffer, pFilename: string);
  sprintf(string, format: "%s%03d.txt", tmp, collideIndex);
  DumpCollideToGlView(a1: collideIndex, pCollide: (Vector *)this->m_pCollide, pFilename: string);
}

//------------------------------------------------------------------------------
// Address: 0x00413860
// Name: VisitLeaves_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl VisitLeaves_r(CPlaneList *planes, int node)
{
  int i; // esi
  dnode_t *v3; // esi
  int m_Size; // ecx
  int v5; // eax
  int v6; // edx
  int *j; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // eax

  for ( i = node; i >= 0; i = v3->children[1] )
  {
    v3 = &dnodes[i];
    VisitLeaves_r(planes, node: v3->children[0]);
  }
  m_Size = planes->m_leafList.m_Size;
  v5 = -1 - i;
  if ( m_Size != 0 )
  {
    v6 = 0;
    if ( m_Size <= 0 )
      return;
    for ( j = planes->m_leafList.m_Memory.m_pMemory; *j != v5; ++j )
    {
      if ( ++v6 >= m_Size )
        return;
    }
  }
  v8 = 16 * v5;
  v9 = 0;
  if ( word_4BA35DA[16 * v5] != 0 )
  {
    do
    {
      v10 = dleafbrushes[v9 + (unsigned __int16)word_4BA35D8[v8]];
      if ( (dword_6EAA870[3 * v10] & planes->m_contentsMask) != 0 )
        planes->m_brushAdded[v10] = true;
      ++v9;
    }
    while ( v9 < (unsigned __int16)word_4BA35DA[v8] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413900
// Name: WriteFogVolumeIDs
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteFogVolumeIDs(dmodel_t *pModel@<edi>)
{
  int firstface; // esi
  texinfo_s *m_pMemory; // ebx
  __int16 *p_texinfo; // eax
  node_t *v4; // ecx
  int diskId; // ecx
  __int16 v6; // dx
  float v7; // xmm1_4

  firstface = pModel->firstface;
  if ( firstface < firstface + pModel->numfaces )
  {
    m_pMemory = texinfo.m_Memory.m_pMemory;
    p_texinfo = &dfaces[firstface].texinfo;
    do
    {
      v4 = dfacenodes[firstface];
      p_texinfo[2] = -1;
      if ( v4 != nullptr && (m_pMemory[*p_texinfo].flags & 8) != 0 && v4->planenum == -1 )
      {
        diskId = v4->diskId;
        if ( diskId >= 0 )
        {
          v6 = word_4BA35DC[16 * diskId];
          v7 = dword_7638AE0[5 * (unsigned __int16)*(p_texinfo - 5)];
          p_texinfo[2] = v6;
          if ( v7 > 0.0 )
            *p_texinfo = dleafwaterdata[v6].surfaceTexInfoID;
        }
      }
      ++firstface;
      p_texinfo += 28;
    }
    while ( firstface < pModel->firstface + pModel->numfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004148B0
// Name: private: void CTextBuffer::CopyData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyData(CTextBuffer *this, char *pData, int len)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_buffer.m_Size;
  if ( len != 0 )
  {
    m_nAllocationCount = this->m_buffer.m_Memory.m_nAllocationCount;
    if ( m_Size + len > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_buffer.m_Memory, num: len + m_Size - m_nAllocationCount);
    this->m_buffer.m_Size += len;
    m_pMemory = this->m_buffer.m_Memory.m_pMemory;
    v7 = this->m_buffer.m_Size - m_Size - len;
    this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
    if ( v7 > 0 && len > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + len], src: &m_pMemory[m_Size], count: v7);
  }
  memcpy(dst: (unsigned __int8 *)&this->m_buffer.m_Memory.m_pMemory[m_Size], src: (unsigned __int8 *)pData, count: len);
}

//------------------------------------------------------------------------------
// Address: 0x00414920
// Name: PropIndex
// Source: json
//------------------------------------------------------------------------------
int __usercall PropIndex@<eax>(CUtlMemory<S3RGBA,int> *propList@<esi>, int propIndex)
{
  int m_pMemory; // edi
  int result; // eax
  int *v4; // ecx
  int m_nAllocationCount; // ecx
  int *v6; // ecx
  int v7; // eax
  int *v8; // eax

  m_pMemory = (int)propList[1].m_pMemory;
  result = 0;
  if ( m_pMemory <= 0 )
  {
LABEL_5:
    if ( m_pMemory >= 126 )
    {
      return 0;
    }
    else
    {
      m_nAllocationCount = propList->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CClassInput *,int>::Grow(this: propList, num: m_pMemory - m_nAllocationCount + 1);
      ++propList[1].m_pMemory;
      v6 = (int *)propList->m_pMemory;
      v7 = (int)propList[1].m_pMemory - m_pMemory - 1;
      propList[1].m_nAllocationCount = (int)propList->m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
      v8 = (int *)&propList->m_pMemory[m_pMemory];
      if ( v8 != nullptr )
        *v8 = propIndex;
      return m_pMemory + 1;
    }
  }
  else
  {
    v4 = (int *)propList->m_pMemory;
    while ( 1 )
    {
      ++result;
      if ( *v4 == propIndex )
        break;
      ++v4;
      if ( result >= m_pMemory )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004149B0
// Name: int RemapWorldMaterial(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RemapWorldMaterial(int materialIndexIn)
{
  return PropIndex(propList: (CUtlMemory<S3RGBA,int> *)&s_WorldPropList, propIndex: materialIndexIn);
}

//------------------------------------------------------------------------------
// Address: 0x004149D0
// Name: public: CPlaneList::CPlaneList(float,float)
// Source: json
//------------------------------------------------------------------------------
CPlaneList *__thiscall CPlaneList::CPlaneList(CPlaneList *this, float shrink, float merge)
{
  bool *v4; // eax

  this->m_convex.m_Memory.m_pMemory = nullptr;
  this->m_convex.m_Memory.m_nAllocationCount = 0;
  this->m_convex.m_Memory.m_nGrowSize = 0;
  this->m_convex.m_Size = 0;
  this->m_convex.m_pElements = nullptr;
  this->m_leafList.m_Memory.m_pMemory = nullptr;
  this->m_leafList.m_Memory.m_nAllocationCount = 0;
  this->m_leafList.m_Memory.m_nGrowSize = 0;
  this->m_leafList.m_Size = 0;
  this->m_leafList.m_pElements = nullptr;
  this->m_shrink = shrink;
  this->m_merge = merge;
  this->m_contentsMask = (int)&unk_200400B;
  v4 = (bool *)MemAlloc_Alloc(nSize: numbrushes);
  this->m_brushAdded = v4;
  memset(dst: (unsigned __int8 *)v4, value: 0, count: numbrushes);
  this->m_totalVolume = 0.0;
  this->m_leafList.m_Size = 0;
  if ( this->m_leafList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_leafList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_leafList.m_Memory.m_pMemory);
      this->m_leafList.m_Memory.m_pMemory = nullptr;
    }
    this->m_leafList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_leafList.m_pElements = this->m_leafList.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00414A70
// Name: public: void CPlaneList::AddConvex(class CPhysConvex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlaneList::AddConvex(CPlaneList *this, CPhysConvex *pConvex)
{
  double v3; // st7
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPhysConvex **m_pMemory; // ecx
  int v7; // eax
  CPhysConvex **v8; // eax

  if ( pConvex != nullptr )
  {
    v3 = ((double (__thiscall *)(IPhysicsCollision *, CPhysConvex *))physcollision->ConvexVolume)(
           a1: physcollision,
           a2: pConvex);
    m_Size = this->m_convex.m_Size;
    m_nAllocationCount = this->m_convex.m_Memory.m_nAllocationCount;
    this->m_totalVolume = v3 + this->m_totalVolume;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_convex.m_Size;
    m_pMemory = this->m_convex.m_Memory.m_pMemory;
    v7 = this->m_convex.m_Size - m_Size - 1;
    this->m_convex.m_pElements = this->m_convex.m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_convex.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = pConvex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414AF0
// Name: private: class CPhysConvex __near * CPlaneList::BuildConvexForBrush(int,float,class CPhysCollide __near *,float)
// Source: json
//------------------------------------------------------------------------------
CPhysConvex *__thiscall CPlaneList::BuildConvexForBrush(
        CPlaneList *this,
        int brushnumber,
        float shrink,
        CPhysCollide *pCollideTest,
        float shrinkMinimum)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_Size; // edi
  int v7; // eax
  int v8; // edx
  listplane_t *m_pMemory; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  float v13; // xmm0_4
  dplane_t *v14; // esi
  int v15; // esi
  _QWORD *normal; // esi
  int v17; // esi
  CUtlVector<listplane_t,CUtlMemory<listplane_t,int> > temp; // [esp+3Ch] [ebp-5Ch] BYREF
  __int64 v20; // [esp+50h] [ebp-48h]
  __int64 v21; // [esp+58h] [ebp-40h]
  Vector start; // [esp+60h] [ebp-38h] BYREF
  Vector end; // [esp+6Ch] [ebp-2Ch] BYREF
  float v24[3]; // [esp+78h] [ebp-20h] BYREF
  CPlaneList *v25; // [esp+84h] [ebp-14h]
  int v26; // [esp+88h] [ebp-10h]
  float shrinkThisPlane; // [esp+8Ch] [ebp-Ch]
  unsigned int v28; // [esp+90h] [ebp-8h]
  int i; // [esp+94h] [ebp-4h]

  v25 = this;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  m_Size = 0;
  temp.m_Memory.m_nAllocationCount = 32;
  temp.m_Memory.m_nGrowSize = 0;
  v7 = (int)Alloc_2(this: _g_pMemAlloc, a2: 512u);
  v8 = brushnumber;
  m_pMemory = (listplane_t *)v7;
  v10 = 12 * brushnumber;
  v11 = 0;
  temp.m_Memory.m_pMemory = m_pMemory;
  temp.m_Size = 0;
  temp.m_pElements = m_pMemory;
  i = 0;
  v26 = 12 * brushnumber;
  if ( dword_6EAA86C[3 * brushnumber] > 0 )
  {
    v28 = 0;
    do
    {
      v12 = v11 + *(int *)((char *)&dbrushes[0].firstside + v10);
      if ( byte_52B500E[8 * v12] == 0 )
      {
        v13 = shrink;
        v14 = &dplanes[dbrushsides[v12].planenum];
        shrinkThisPlane = shrink;
        if ( i < g_MainMap->mapbrushes[v8].numsides && !g_MainMap->mapbrushes[v8].original_sides[v28 / 0x5C].visible )
        {
          v13 = 0.0;
          shrinkThisPlane = 0.0;
        }
        if ( pCollideTest != nullptr && v13 != 0.0 )
        {
          physcollision->CollideGetExtent(
            this: physcollision,
            result: &start,
            a3: pCollideTest,
            a4: &vec3_origin,
            a5: &vec3_angle,
            a6: (const Vector *)v14);
          v24[0] = -v14->normal.x;
          v24[1] = -v14->normal.y;
          v24[2] = -v14->normal.z;
          physcollision->CollideGetExtent(
            this: physcollision,
            result: &end,
            a3: pCollideTest,
            a4: &vec3_origin,
            a5: &vec3_angle,
            a6: (const Vector *)v24);
          if ( shrinkMinimum <= COERCE_FLOAT(
                                  COERCE_UNSIGNED_INT(
                                    (float)((float)(v14->normal.y * (float)(end.y - start.y))
                                          + (float)(v14->normal.x * (float)(end.x - start.x)))
                                  + (float)(v14->normal.z * (float)(end.z - start.z)))
                                & _mask__AbsFloat_) )
            v13 = shrinkThisPlane;
          else
            v13 = 0.0;
        }
        v20 = *(_QWORD *)&v14->normal.x;
        *(float *)&v21 = v14->normal.z;
        *((float *)&v21 + 1) = v14->dist - v13;
        v15 = m_Size;
        if ( m_Size + 1 > temp.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<listplane_t,int>::Grow(this: &temp.m_Memory, num: m_Size - temp.m_Memory.m_nAllocationCount + 1);
          m_Size = temp.m_Size;
          m_pMemory = temp.m_Memory.m_pMemory;
        }
        temp.m_Size = ++m_Size;
        temp.m_pElements = m_pMemory;
        if ( m_Size - v15 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 16 * (m_Size - v15 - 1));
        v10 = v26;
        v8 = brushnumber;
        normal = (_QWORD *)m_pMemory[v15].normal;
        if ( normal != nullptr )
        {
          *normal = v20;
          normal[1] = v21;
        }
      }
      v28 += 92;
      v11 = i + 1;
      i = v11;
    }
    while ( v11 < *(int *)((char *)dword_6EAA86C + v10) );
  }
  v17 = ((int (__stdcall *)(listplane_t *, int, _DWORD))physcollision->ConvexFromPlanes)(
          a1: m_pMemory,
          a2: m_Size,
          a3: LODWORD(v25->m_merge));
  if ( temp.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return (CPhysConvex *)v17;
}

//------------------------------------------------------------------------------
// Address: 0x00414D90
// Name: public: int CPlaneList::AddBrushes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlaneList::AddBrushes(CPlaneList *this)
{
  int result; // eax
  int v2; // edi
  CPhysConvex *v4; // ebx
  void (__thiscall *SetConvexGameData)(IPhysicsCollision *, CPhysConvex *, unsigned int); // eax
  CPhysCollide *pUnshrunkCollide; // [esp+20h] [ebp-Ch]
  CPhysConvex *pConvex; // [esp+24h] [ebp-8h] BYREF
  int count; // [esp+28h] [ebp-4h]

  result = 0;
  v2 = 0;
  count = 0;
  if ( (int)numbrushes > 0 )
  {
    do
    {
      if ( this->m_brushAdded[v2] )
      {
        if ( this->m_shrink == 0.0 )
        {
          v4 = CPlaneList::BuildConvexForBrush(
                 this,
                 brushnumber: v2,
                 shrink: 0.0,
                 pCollideTest: nullptr,
                 shrinkMinimum: 1.0);
        }
        else
        {
          pConvex = CPlaneList::BuildConvexForBrush(
                      this,
                      brushnumber: v2,
                      shrink: 0.0,
                      pCollideTest: nullptr,
                      shrinkMinimum: 0.0);
          pUnshrunkCollide = physcollision->ConvertConvexToCollide(this: physcollision, a2: &pConvex, a3: 1);
          v4 = CPlaneList::BuildConvexForBrush(
                 this,
                 brushnumber: v2,
                 shrink: this->m_shrink,
                 pCollideTest: pUnshrunkCollide,
                 shrinkMinimum: this->m_shrink * 3.0);
          physcollision->DestroyCollide(this: physcollision, a2: pUnshrunkCollide);
        }
        if ( v4 != nullptr )
        {
          SetConvexGameData = physcollision->SetConvexGameData;
          ++count;
          SetConvexGameData(this: physcollision, a2: v4, a3: v2);
          CPlaneList::AddConvex(this, pConvex: v4);
        }
      }
      ++v2;
    }
    while ( v2 < (int)numbrushes );
    return count;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414E90
// Name: void EnumLeaves_r(class CUtlVector<struct node_t __near *,class CUtlMemory<struct node_t __near *,int>> __near &,struct node_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnumLeaves_r(CUtlVector<node_t *,CUtlMemory<node_t *,int> > *list, node_t *node, int contentsMask)
{
  node_t *i; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  node_t **m_pMemory; // ecx
  int v7; // eax
  node_t **v8; // ebx

  for ( i = node; i->planenum != -1; i = i->children[1] )
    EnumLeaves_r(list, node: i->children[0], contentsMask);
  if ( (contentsMask & i->contents) != 0 )
  {
    m_Size = list->m_Size;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v7 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &list->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414F20
// Name: Flood_FindConnectedWaterVolumes_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl Flood_FindConnectedWaterVolumes_r(
        CUtlVector<node_t *,CUtlMemory<node_t *,int> > *list,
        node_t *pLeaf,
        waterleaf_t *baseleaf,
        CBitVec<65536> *visited)
{
  node_t *v4; // ebx
  int diskId; // eax
  waterleaf_t *v6; // edx
  portal_t *i; // esi
  BOOL v8; // edi
  int v9; // eax
  unsigned int *v10; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  node_t **m_pMemory; // ecx
  int v14; // eax
  node_t **v15; // esi
  float z; // xmm0_4
  portal_t *portals; // esi
  BOOL v18; // ebx

  v4 = pLeaf;
  diskId = pLeaf->diskId;
  if ( diskId >= 0 && ((1 << (diskId & 0x1F)) & visited->m_Ints[(unsigned int)diskId >> 5]) == 0 )
  {
    v6 = baseleaf;
    if ( (pLeaf->contents & baseleaf->pNode->contents & 0x4030) != 0 )
    {
      for ( i = pLeaf->portals; i != nullptr; i = i->next[!v8] )
      {
        v8 = i->nodes[0] == pLeaf;
        if ( v6->hasSurface )
        {
          v9 = WindingOnPlaneSide(w: i->winding, normal: &v6->surfaceNormal, dist: v6->surfaceDist);
          if ( v9 == -2 || v9 == 0 )
            return;
          v6 = baseleaf;
        }
      }
      v10 = &visited->m_Ints[pLeaf->diskId >> 5];
      *v10 |= 1 << (pLeaf->diskId & 0x1F);
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
        v6 = baseleaf;
      }
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v14 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v14 > 0 )
      {
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
        v6 = baseleaf;
      }
      v15 = &list->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = pLeaf;
      z = pLeaf->mins.z;
      if ( v6->minZ <= z )
        z = v6->minZ;
      v6->minZ = z;
      portals = pLeaf->portals;
      if ( portals != nullptr )
      {
        while ( 1 )
        {
          v18 = portals->nodes[0] == v4;
          Flood_FindConnectedWaterVolumes_r(list, pLeaf: portals->nodes[v18], baseleaf, visited);
          portals = portals->next[!v18];
          if ( portals == nullptr )
            break;
          v4 = pLeaf;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415090
// Name: ConvertWaterModelToPhysCollide
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertWaterModelToPhysCollide(
        CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *collisionList,
        int modelIndex,
        float shrinkSize,
        float mergeTolerance)
{
  int v4; // ecx
  CPhysCollisionEntryFluid *v5; // ebx
  int v6; // edi
  char *v7; // edi
  int v8; // eax
  int m_Size; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  int *v13; // eax
  const struct CPhysCollide *v14; // eax
  CPhysCollide *v15; // esi
  CPhysCollisionEntryFluid *v16; // eax
  int v17; // esi
  int m_nAllocationCount; // eax
  CPhysCollisionEntry **m_pMemory; // ecx
  int v20; // eax
  CPhysCollisionEntry **v21; // esi
  int *v22; // eax
  bool v23; // sf
  CPhysConvex **v24; // eax
  bool v25; // sf
  CPlaneList planes; // [esp+38h] [ebp-5Ch] BYREF
  Vector top; // [esp+74h] [ebp-20h] BYREF
  dmodel_t *pModel; // [esp+80h] [ebp-14h]
  int v29; // [esp+84h] [ebp-10h]
  int i; // [esp+88h] [ebp-Ch]
  int v31; // [esp+8Ch] [ebp-8h]
  int j; // [esp+90h] [ebp-4h]

  v4 = modelIndex;
  v5 = nullptr;
  pModel = &dmodels[modelIndex];
  i = 0;
  if ( g_WaterModels.m_Size > 0 )
  {
    v6 = 0;
    v29 = 0;
    while ( 1 )
    {
      v7 = (char *)g_WaterModels.m_Memory.m_pMemory + v6;
      if ( *(_DWORD *)v7 == v4 )
      {
        CPlaneList::CPlaneList(this: &planes, shrink: shrinkSize, merge: mergeTolerance);
        v8 = *((_DWORD *)v7 + 14);
        planes.m_contentsMask = *((_DWORD *)v7 + 1);
        j = 0;
        if ( *((int *)v7 + 15) > 0 )
        {
          m_Size = planes.m_leafList.m_Size;
          v10 = 4 * v8;
          v31 = v10;
          do
          {
            v11 = *(int *)((char *)g_WaterLeafList.m_Memory.m_pMemory + v10);
            word_4BA35DC[16 * v11] = *((_WORD *)v7 + 32);
            v12 = m_Size;
            if ( m_Size + 1 > planes.m_leafList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CClassInput *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&planes.m_leafList,
                num: m_Size - planes.m_leafList.m_Memory.m_nAllocationCount + 1);
              m_Size = planes.m_leafList.m_Size;
            }
            planes.m_leafList.m_Size = ++m_Size;
            planes.m_leafList.m_pElements = planes.m_leafList.m_Memory.m_pMemory;
            if ( m_Size - v12 - 1 > 0 )
            {
              _V_memmove(
                dest: &planes.m_leafList.m_Memory.m_pMemory[v12 + 1],
                src: &planes.m_leafList.m_Memory.m_pMemory[v12],
                count: 4 * (m_Size - v12 - 1));
              m_Size = planes.m_leafList.m_Size;
            }
            v13 = &planes.m_leafList.m_Memory.m_pMemory[v12];
            if ( v13 != nullptr )
            {
              *v13 = v11;
              m_Size = planes.m_leafList.m_Size;
            }
            v10 = v31 + 4;
            ++j;
            v31 += 4;
          }
          while ( j < *((_DWORD *)v7 + 15) );
          v5 = nullptr;
        }
        VisitLeaves_r(&planes, node: pModel->headnode);
        CPlaneList::AddBrushes(this: &planes);
        if ( planes.m_convex.m_Size != 0 )
        {
          v14 = physcollision->ConvertConvexToCollide(
                  this: physcollision,
                  a2: planes.m_convex.m_Memory.m_pMemory,
                  a3: planes.m_convex.m_Size);
          v15 = v14;
          if ( v14 != nullptr )
          {
            if ( v7[28] == 0 )
            {
              *((_DWORD *)v7 + 2) = 0;
              *((_DWORD *)v7 + 3) = 0;
              *((_DWORD *)v7 + 4) = 1065353216;
              physcollision->CollideGetExtent(
                this: physcollision,
                result: &top,
                a3: v14,
                a4: &vec3_origin,
                a5: &vec3_angle,
                a6: (const Vector *)(v7 + 8));
              *((_DWORD *)v7 + 5) = LODWORD(top.z);
            }
            v16 = (CPhysCollisionEntryFluid *)MemAlloc_Alloc(nSize: 0x24u);
            if ( v16 != nullptr )
              v5 = CPhysCollisionEntryFluid::CPhysCollisionEntryFluid(
                     this: v16,
                     pCollide: v15,
                     pSurfaceProp: "water",
                     damping: 0.0099999998,
                     normal: (const Vector *)(v7 + 8),
                     dist: *((float *)v7 + 5),
                     nContents: *((_DWORD *)v7 + 1));
            v17 = collisionList->m_Size;
            m_nAllocationCount = collisionList->m_Memory.m_nAllocationCount;
            if ( v17 + 1 > m_nAllocationCount )
              CUtlMemory<CClassInput *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)collisionList,
                num: v17 - m_nAllocationCount + 1);
            ++collisionList->m_Size;
            m_pMemory = collisionList->m_Memory.m_pMemory;
            v20 = collisionList->m_Size - v17 - 1;
            collisionList->m_pElements = collisionList->m_Memory.m_pMemory;
            if ( v20 > 0 )
              _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * v20);
            v21 = &collisionList->m_Memory.m_pMemory[v17];
            if ( v21 != nullptr )
              *v21 = v5;
            v5 = nullptr;
          }
        }
        free(pMem: planes.m_brushAdded);
        v22 = planes.m_leafList.m_Memory.m_pMemory;
        planes.m_leafList.m_Size = 0;
        v23 = planes.m_leafList.m_Memory.m_nGrowSize < 0;
        if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( planes.m_leafList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_leafList.m_Memory.m_pMemory);
            v22 = nullptr;
            planes.m_leafList.m_Memory.m_pMemory = nullptr;
          }
          v23 = planes.m_leafList.m_Memory.m_nGrowSize < 0;
          planes.m_leafList.m_Memory.m_nAllocationCount = 0;
        }
        planes.m_leafList.m_pElements = v22;
        if ( !v23 )
        {
          if ( v22 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
            planes.m_leafList.m_Memory.m_pMemory = nullptr;
          }
          planes.m_leafList.m_Memory.m_nAllocationCount = 0;
        }
        v24 = planes.m_convex.m_Memory.m_pMemory;
        planes.m_convex.m_Size = 0;
        v25 = planes.m_convex.m_Memory.m_nGrowSize < 0;
        if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
        {
          if ( planes.m_convex.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_convex.m_Memory.m_pMemory);
            v24 = nullptr;
            planes.m_convex.m_Memory.m_pMemory = nullptr;
          }
          v25 = planes.m_convex.m_Memory.m_nGrowSize < 0;
          planes.m_convex.m_Memory.m_nAllocationCount = 0;
        }
        planes.m_convex.m_pElements = v24;
        if ( !v25 && v24 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
      }
      v6 = v29 + 68;
      ++i;
      v29 += 68;
      if ( i >= g_WaterModels.m_Size )
        break;
      v4 = modelIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415380
// Name: ConvertWorldBrushesToPhysCollide
// Source: json
//------------------------------------------------------------------------------
CPhysConvex **__usercall ConvertWorldBrushesToPhysCollide@<eax>(
        int a1@<edi>,
        float merge@<xmm0>,
        CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *collisionList,
        float shrinkSize,
        CPhysCollisionEntry_vtbl *contentsMask)
{
  int v5; // ebx
  CPhysCollide *v6; // esi
  ICollisionQuery *(__thiscall *CreateQueryModel)(IPhysicsCollision *, CPhysCollide *); // edx
  int v8; // edi
  int v9; // esi
  __int16 texinfo; // ax
  int v11; // eax
  CPhysCollisionEntry *v12; // eax
  CPhysCollisionEntry *v13; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPhysCollisionEntry **m_pMemory; // ecx
  int v17; // eax
  CPhysCollisionEntry **v18; // ebx
  int *v19; // eax
  CPhysConvex **result; // eax
  CPlaneList planes; // [esp+Ch] [ebp-80h] BYREF
  Vector points[3]; // [esp+48h] [ebp-44h] BYREF
  Vector normal; // [esp+6Ch] [ebp-20h] BYREF
  CPhysCollide *pCollide; // [esp+78h] [ebp-14h]
  int convex; // [esp+7Ch] [ebp-10h]
  int brushIndex; // [esp+80h] [ebp-Ch]
  int triCount; // [esp+84h] [ebp-8h]
  int j; // [esp+88h] [ebp-4h]

  CPlaneList::CPlaneList(this: &planes, shrink: shrinkSize, merge);
  planes.m_contentsMask = (int)contentsMask;
  VisitLeaves_r(&planes, node: nHeadNode);
  CPlaneList::AddBrushes(this: &planes);
  v5 = 0;
  if ( planes.m_convex.m_Size != 0 )
  {
    v6 = (CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *, CPhysConvex **, int, int))physcollision->ConvertConvexToCollide)(
                           a1: physcollision,
                           a2: planes.m_convex.m_Memory.m_pMemory,
                           a3: planes.m_convex.m_Size,
                           a4: a1);
    CreateQueryModel = physcollision->CreateQueryModel;
    pCollide = v6;
    v8 = (int)CreateQueryModel(this: physcollision, a2: v6);
    convex = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
    if ( convex > 0 )
    {
      do
      {
        triCount = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 8))(a1: v8, a2: v5);
        v9 = 0;
        brushIndex = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 12))(a1: v8, a2: v5);
        for ( j = 0; v9 < triCount; j = v9 )
        {
          (*(void (__thiscall **)(int, int, int, Vector *))(*(_DWORD *)v8 + 16))(a1: v8, a2: v5, a3: v9, a4: points);
          normal.x = (float)((float)(points[1].z - points[0].z) * (float)(points[2].y - points[0].y))
                   - (float)((float)(points[2].z - points[0].z) * (float)(points[1].y - points[0].y));
          normal.y = (float)((float)(points[2].z - points[0].z) * (float)(points[1].x - points[0].x))
                   - (float)((float)(points[1].z - points[0].z) * (float)(points[2].x - points[0].x));
          normal.z = (float)((float)(points[1].y - points[0].y) * (float)(points[2].x - points[0].x))
                   - (float)((float)(points[2].y - points[0].y) * (float)(points[1].x - points[0].x));
          VectorNormalize(vec: &normal);
          texinfo = FindBrushSide(brushIndex, &normal)->texinfo;
          if ( texinfo != -1 )
          {
            v11 = PropIndex(
                    propList: (CUtlMemory<S3RGBA,int> *)&s_WorldPropList,
                    propIndex: g_SurfaceProperties[::texinfo.m_Memory.m_pMemory[texinfo].texdata]);
            (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v8 + 28))(a1: v8, a2: v5, a3: j, a4: v11);
            v9 = j;
          }
          ++v9;
        }
        ++v5;
      }
      while ( v5 < convex );
      v6 = pCollide;
    }
    ((void (__thiscall *)(IPhysicsCollision *))physcollision->DestroyQueryModel)(a1: physcollision);
    v12 = (CPhysCollisionEntry *)MemAlloc_Alloc(nSize: 0xCu);
    if ( v12 != nullptr )
    {
      v12->m_pCollide = v6;
      v12->__vftable = (CPhysCollisionEntry_vtbl *)&CPhysCollisionEntryStaticSolid::`vftable';
      v12[1].__vftable = contentsMask;
      v13 = v12;
    }
    else
    {
      v13 = nullptr;
    }
    m_Size = collisionList->m_Size;
    m_nAllocationCount = collisionList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)collisionList,
        num: m_Size - m_nAllocationCount + 1);
    ++collisionList->m_Size;
    m_pMemory = collisionList->m_Memory.m_pMemory;
    v17 = collisionList->m_Size - m_Size - 1;
    collisionList->m_pElements = collisionList->m_Memory.m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
    v18 = &collisionList->m_Memory.m_pMemory[m_Size];
    if ( v18 != nullptr )
      *v18 = v13;
  }
  free(pMem: planes.m_brushAdded);
  v19 = planes.m_leafList.m_Memory.m_pMemory;
  planes.m_leafList.m_Size = 0;
  if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( planes.m_leafList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_leafList.m_Memory.m_pMemory);
      v19 = nullptr;
      planes.m_leafList.m_Memory.m_pMemory = nullptr;
    }
    planes.m_leafList.m_Memory.m_nAllocationCount = 0;
  }
  planes.m_leafList.m_pElements = v19;
  if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      planes.m_leafList.m_Memory.m_pMemory = nullptr;
    }
    planes.m_leafList.m_Memory.m_nAllocationCount = 0;
  }
  result = planes.m_convex.m_Memory.m_pMemory;
  planes.m_convex.m_Size = 0;
  if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( planes.m_convex.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_convex.m_Memory.m_pMemory);
      result = nullptr;
      planes.m_convex.m_Memory.m_pMemory = nullptr;
    }
    planes.m_convex.m_Memory.m_nAllocationCount = 0;
  }
  planes.m_convex.m_pElements = result;
  if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 && result != nullptr )
    return (CPhysConvex **)((int (__thiscall *)(IMemAlloc *, CPhysConvex **))_g_pMemAlloc->Free_2)(
                             a1: _g_pMemAlloc,
                             a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415660
// Name: BuildWorldPhysModel
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildWorldPhysModel(
        CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *collisionList@<esi>,
        int a2@<edi>,
        float shrinkSize,
        float mergeTolerance)
{
  ConvertWorldBrushesToPhysCollide(
    a1: a2,
    merge: mergeTolerance,
    collisionList,
    shrinkSize,
    contentsMask: &stru_2004003);
  ConvertWorldBrushesToPhysCollide(
    a1: a2,
    merge: mergeTolerance,
    collisionList,
    shrinkSize,
    contentsMask: (CPhysCollisionEntry_vtbl *)8);
  ConvertWorldBrushesToPhysCollide(
    a1: a2,
    merge: mergeTolerance,
    collisionList,
    shrinkSize,
    contentsMask: (CPhysCollisionEntry_vtbl *)0x10000);
  ConvertWorldBrushesToPhysCollide(
    a1: a2,
    merge: mergeTolerance,
    collisionList,
    shrinkSize,
    contentsMask: (CPhysCollisionEntry_vtbl *)0x20000);
  if ( g_bNoVirtualMesh || !physcollision->SupportsVirtualMesh(this: physcollision) )
    Disp_AddCollisionModels(collisionList, pModel: dmodels, contentsMask: (int)&unk_200400B);
  else
    Disp_BuildVirtualMesh(contentsMask: (int)&unk_200400B);
  ConvertWaterModelToPhysCollide(collisionList, modelIndex: 0, shrinkSize, mergeTolerance);
}

//------------------------------------------------------------------------------
// Address: 0x00415740
// Name: ConvertModelToPhysCollide
// Source: json
//------------------------------------------------------------------------------
CPhysConvex **__usercall ConvertModelToPhysCollide@<eax>(
        int a1@<eax>,
        float a2@<xmm0>,
        CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *collisionList,
        int mass,
        float shrinkSize)
{
  unsigned int v6; // esi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  int *v14; // eax
  CPhysConvex **result; // eax
  bool v16; // zf
  int v17; // edi
  texinfo_s *m_pMemory; // ebx
  int v19; // ecx
  bool v20; // cc
  dface_t *v21; // edx
  int v22; // esi
  int v23; // eax
  bool v24; // zf
  double area; // st7
  float v26; // xmm0_4
  int v27; // edx
  int v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  const char *v39; // edi
  int prop; // esi
  float m_totalVolume; // xmm0_4
  CPhysCollisionEntry *v42; // esi
  CPhysCollide *v43; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPhysCollisionEntry **v46; // ecx
  int v47; // eax
  CPhysCollisionEntry **v48; // eax
  int *v49; // eax
  int merge; // [esp+4h] [ebp-86Ch]
  ConvertModelToPhysCollide::__l9::<unnamed_type_proplist> proplist[256]; // [esp+14h] [ebp-85Ch]
  float thickness; // [esp+814h] [ebp-5Ch] BYREF
  CPhysCollide *pCollide; // [esp+818h] [ebp-58h]
  convertconvexparams_t params; // [esp+81Ch] [ebp-54h] BYREF
  float density; // [esp+82Ch] [ebp-44h] BYREF
  CPlaneList planes; // [esp+830h] [ebp-40h] BYREF
  float totalArea; // [esp+86Ch] [ebp-4h]
  float massa; // [esp+87Ch] [ebp+Ch]

  CPlaneList::CPlaneList(this: &planes, shrink: shrinkSize, merge: a2);
  v6 = 48 * a1;
  merge = *(int *)((char *)&nHeadNode + v6);
  planes.m_contentsMask = mass;
  VisitLeaves_r(&planes, node: merge);
  CPlaneList::AddBrushes(this: &planes);
  v7 = *(float *)&dword_89C0B68[v6 / 4] - *(float *)&dword_89C0B5C[v6 / 4];
  v8 = *(float *)&dword_89C0B6C[v6 / 4] - *(float *)&dword_89C0B60[v6 / 4];
  v9 = *(float *)&dword_89C0B64[v6 / 4] - dmodels[v6 / 0x30].mins.x;
  v10 = v7 * v8;
  v20 = (float)(v7 * v8) >= 0.0;
  *(_DWORD *)&params.buildOptimizedTraceTables = 0;
  params.pForcedOuterHull = nullptr;
  params.buildOuterConvexHull = planes.m_convex.m_Size > 1;
  params.buildDragAxisAreas = true;
  v11 = v8 * v9;
  if ( !v20 || v10 > v11 )
    v10 = v11;
  v12 = v7 * v9;
  if ( v10 < 0.0 || v10 > v12 )
    v10 = v12;
  v13 = v10 * 0.0099999998;
  if ( v13 >= 1.0 )
  {
    if ( v13 <= 1024.0 )
      params.dragAreaEpsilon = v13;
    else
      params.dragAreaEpsilon = 1024.0;
  }
  else
  {
    params.dragAreaEpsilon = 1.0;
  }
  pCollide = physcollision->ConvertConvexToCollideParams(
               this: physcollision,
               a2: planes.m_convex.m_Memory.m_pMemory,
               a3: planes.m_convex.m_Size,
               a4: &params);
  if ( pCollide != nullptr )
  {
    v17 = dword_89C0B84[v6 / 4];
    m_pMemory = texinfo.m_Memory.m_pMemory;
    v19 = 1;
    proplist[0].prop = -1;
    proplist[0].area = 1.0;
    v20 = v17 <= 0;
    if ( v17 == 0 )
    {
      proplist[1].prop = g_SurfaceProperties[m_pMemory[word_52B500A[4 * CPlaneList::GetFirstBrushSide(this: &planes)]].texdata];
      proplist[1].area = 2.0;
      v19 = 2;
      v20 = true;
    }
    if ( !v20 )
    {
      v21 = &dfaces[dword_89C0B80[v6 / 4]];
      do
      {
        v22 = g_SurfaceProperties[m_pMemory[v21->texinfo].texdata];
        v23 = 0;
        v24 = v19 == 0;
        if ( v19 > 0 )
        {
          while ( proplist[v23].prop != v22 )
          {
            if ( ++v23 >= v19 )
              goto LABEL_36;
          }
          proplist[v23].area = v21->area + proplist[v23].area;
LABEL_36:
          v24 = v19 == 0;
        }
        if ( (v24 || v23 >= v19) && (unsigned int)v19 < 0x100 )
        {
          area = v21->area;
          proplist[v19].prop = v22;
          proplist[v19++].area = area;
        }
        ++v21;
        --v17;
      }
      while ( v17 != 0 );
    }
    v26 = 0.0;
    v27 = -1;
    v28 = 0;
    v29 = 0.0;
    totalArea = 0.0;
    if ( v19 >= 4 )
    {
      do
      {
        v30 = proplist[v28].area;
        if ( v30 > v26 )
        {
          v27 = v28;
          v26 = proplist[v28].area;
        }
        v31 = v29 + v30;
        v32 = proplist[v28 + 1].area;
        if ( v32 > v26 )
        {
          v27 = v28 + 1;
          v26 = proplist[v28 + 1].area;
        }
        v33 = v31 + v32;
        v34 = proplist[v28 + 2].area;
        if ( v34 > v26 )
        {
          v27 = v28 + 2;
          v26 = proplist[v28 + 2].area;
        }
        v35 = v34 + v33;
        v36 = proplist[v28 + 3].area;
        if ( v36 > v26 )
        {
          v27 = v28 + 3;
          v26 = proplist[v28 + 3].area;
        }
        v28 += 4;
        v29 = v36 + v35;
      }
      while ( v28 < v19 - 3 );
      totalArea = v29;
    }
    if ( v28 < v19 )
    {
      do
      {
        v37 = proplist[v28].area;
        if ( v37 > v26 )
        {
          v27 = v28;
          v26 = proplist[v28].area;
        }
        ++v28;
        v38 = v37 + v29;
        v29 = v38;
      }
      while ( v28 < v19 );
      totalArea = v38;
    }
    massa = 1.0;
    v39 = "default";
    if ( v27 >= 0 )
    {
      prop = proplist[v27].prop;
      if ( prop < 0 )
        prop = 0;
      v39 = physprops->GetPropName(this: physprops, a2: prop);
      physprops->GetPhysicsProperties(this: physprops, a2: prop, a3: &density, a4: &thickness, a5: nullptr, a6: nullptr);
      if ( thickness == 0.0 )
        m_totalVolume = planes.m_totalVolume;
      else
        m_totalVolume = thickness * totalArea;
      massa = (float)(m_totalVolume * density) * 0.000016387063;
      if ( massa > 50000.0 )
        massa = 50000.0;
    }
    v42 = (CPhysCollisionEntry *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v42 != nullptr )
    {
      v43 = pCollide;
      v42->m_pCollide = pCollide;
      v42->__vftable = (CPhysCollisionEntry_vtbl *)&CPhysCollisionEntrySolid::`vftable';
      *(float *)&v42[1].__vftable = physcollision->CollideVolume(this: physcollision, a2: v43);
      *(float *)&v42[1].m_pCollide = massa;
      v42[2].__vftable = (CPhysCollisionEntry_vtbl *)v39;
    }
    else
    {
      v42 = nullptr;
    }
    m_Size = collisionList->m_Size;
    m_nAllocationCount = collisionList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)collisionList,
        num: m_Size - m_nAllocationCount + 1);
    ++collisionList->m_Size;
    v46 = collisionList->m_Memory.m_pMemory;
    v47 = collisionList->m_Size - m_Size - 1;
    collisionList->m_pElements = collisionList->m_Memory.m_pMemory;
    if ( v47 > 0 )
      _V_memmove(dest: &v46[m_Size + 1], src: &v46[m_Size], count: 4 * v47);
    v48 = &collisionList->m_Memory.m_pMemory[m_Size];
    if ( v48 != nullptr )
      *v48 = v42;
    free(pMem: planes.m_brushAdded);
    v49 = planes.m_leafList.m_Memory.m_pMemory;
    planes.m_leafList.m_Size = 0;
    if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planes.m_leafList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_leafList.m_Memory.m_pMemory);
        v49 = nullptr;
        planes.m_leafList.m_Memory.m_pMemory = nullptr;
      }
      planes.m_leafList.m_Memory.m_nAllocationCount = 0;
    }
    planes.m_leafList.m_pElements = v49;
    if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v49 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v49);
        planes.m_leafList.m_Memory.m_pMemory = nullptr;
      }
      planes.m_leafList.m_Memory.m_nAllocationCount = 0;
    }
    result = planes.m_convex.m_Memory.m_pMemory;
    planes.m_convex.m_Size = 0;
    if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planes.m_convex.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_convex.m_Memory.m_pMemory);
        result = nullptr;
        planes.m_convex.m_Memory.m_pMemory = nullptr;
      }
      planes.m_convex.m_Memory.m_nAllocationCount = 0;
    }
    planes.m_convex.m_pElements = result;
    if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
    {
      v16 = result == nullptr;
LABEL_89:
      if ( !v16 )
        return (CPhysConvex **)((int (__thiscall *)(IMemAlloc *, CPhysConvex **))_g_pMemAlloc->Free_2)(
                                 a1: _g_pMemAlloc,
                                 a2: result);
    }
  }
  else
  {
    free(pMem: planes.m_brushAdded);
    v14 = planes.m_leafList.m_Memory.m_pMemory;
    planes.m_leafList.m_Size = 0;
    if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planes.m_leafList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_leafList.m_Memory.m_pMemory);
        v14 = nullptr;
        planes.m_leafList.m_Memory.m_pMemory = nullptr;
      }
      planes.m_leafList.m_Memory.m_nAllocationCount = 0;
    }
    planes.m_leafList.m_pElements = v14;
    if ( planes.m_leafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v14 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
        planes.m_leafList.m_Memory.m_pMemory = nullptr;
      }
      planes.m_leafList.m_Memory.m_nAllocationCount = 0;
    }
    result = planes.m_convex.m_Memory.m_pMemory;
    planes.m_convex.m_Size = 0;
    if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planes.m_convex.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planes.m_convex.m_Memory.m_pMemory);
        result = nullptr;
        planes.m_convex.m_Memory.m_pMemory = nullptr;
      }
      planes.m_convex.m_Memory.m_nAllocationCount = 0;
    }
    planes.m_convex.m_pElements = result;
    if ( planes.m_convex.m_Memory.m_nGrowSize >= 0 )
    {
      v16 = result == nullptr;
      goto LABEL_89;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415CB0
// Name: public: void CTextBuffer::WriteIntKey(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteIntKey(CTextBuffer *this, const char *pKeyName, int outputData)
{
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( strlen(pKeyName) <= 0x3E8 )
  {
    sprintf(string: tmp, format: "\"%s\" \"%d\"\n", pKeyName, outputData);
    CTextBuffer::CopyData(this, pData: tmp, len: strlen(tmp));
  }
  else
  {
    _Msg(a1: "Error writing collision data %s\n", pKeyName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D30
// Name: public: void CTextBuffer::WriteFloatKey(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteFloatKey(CTextBuffer *this, const char *pKeyName, float outputData)
{
  char tmp[1024]; // [esp+10h] [ebp-400h] BYREF

  if ( strlen(pKeyName) <= 0x3E8 )
  {
    sprintf(string: tmp, format: "\"%s\" \"%f\"\n", pKeyName, outputData);
    CTextBuffer::CopyData(this, pData: tmp, len: strlen(tmp));
  }
  else
  {
    _Msg(a1: "Error writing collision data %s\n", pKeyName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415DC0
// Name: public: void CTextBuffer::WriteFloatArrayKey(char const __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteFloatArrayKey(
        CTextBuffer *this,
        const char *pKeyName,
        const float *outputData,
        int count)
{
  int i; // ebx
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  char *v8; // eax
  char v9; // cl
  signed int v10; // kr04_4
  char *m_pMemory; // edi
  CUtlMemory<char,int> *v12; // ebx
  int m_nAllocationCount; // eax
  char *v14; // ecx
  int v15; // eax
  signed int j; // eax
  char v17; // [esp+13h] [ebp-455h] BYREF
  char tmp[1024]; // [esp+14h] [ebp-454h] BYREF
  char buf[80]; // [esp+414h] [ebp-54h] BYREF
  CUtlMemory<char,int> *p_m_Memory; // [esp+464h] [ebp-4h]

  p_m_Memory = &this->m_buffer.m_Memory;
  if ( strlen(pKeyName) <= 0x3E8 )
  {
    sprintf(string: tmp, format: "\"%s\" \"", pKeyName);
    for ( i = 0; i < count; ++i )
    {
      sprintf(string: buf, format: "%f ", outputData[i]);
      v5 = strlen(buf) + 1;
      v6 = &v17;
      do
        v7 = *++v6;
      while ( v7 != 0 );
      qmemcpy(v6, buf, v5);
    }
    v8 = &v17;
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "\"\n");
    v10 = strlen(tmp);
    m_pMemory = p_m_Memory[1].m_pMemory;
    v12 = p_m_Memory;
    if ( v10 != 0 )
    {
      m_nAllocationCount = p_m_Memory->m_nAllocationCount;
      if ( (int)&m_pMemory[v10] > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: p_m_Memory, num: (int)&m_pMemory[v10 - m_nAllocationCount]);
      v12[1].m_pMemory += v10;
      v14 = v12->m_pMemory;
      v15 = &v12[1].m_pMemory[-v10] - m_pMemory;
      v12[1].m_nAllocationCount = (int)v12->m_pMemory;
      if ( v15 > 0 && v10 > 0 )
        _V_memmove(dest: &v14[v10 + (_DWORD)m_pMemory], src: &m_pMemory[(_DWORD)v14], count: v15);
      for ( j = 0; j < v10; ++j )
        ;
    }
    memcpy(dst: (unsigned __int8 *)&m_pMemory[(unsigned int)v12->m_pMemory], src: (unsigned __int8 *)tmp, count: v10);
  }
  else
  {
    _Msg(a1: "Error writing collision data %s\n", pKeyName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415F40
// Name: public: void CTextBuffer::CopyStringQuotes(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyStringQuotes(CTextBuffer *this, char *pString)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  char *v9; // ecx
  int v10; // eax

  m_nAllocationCount = this->m_buffer.m_Memory.m_nAllocationCount;
  m_Size = this->m_buffer.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_buffer.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_buffer.m_Size;
  m_pMemory = this->m_buffer.m_Memory.m_pMemory;
  v6 = this->m_buffer.m_Size - m_Size - 1;
  this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v6);
  this->m_buffer.m_Memory.m_pMemory[m_Size] = pDelimiter[0];
  CTextBuffer::CopyData(this, pData: pString, len: strlen(pString));
  v7 = this->m_buffer.m_Size;
  v8 = this->m_buffer.m_Memory.m_nAllocationCount;
  if ( v7 + 1 > v8 )
    CUtlMemory<bool,int>::Grow(this: &this->m_buffer.m_Memory, num: v7 - v8 + 1);
  ++this->m_buffer.m_Size;
  v9 = this->m_buffer.m_Memory.m_pMemory;
  v10 = this->m_buffer.m_Size - v7 - 1;
  this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &v9[v7 + 1], src: &v9[v7], count: v10);
  this->m_buffer.m_Memory.m_pMemory[v7] = pDelimiter[0];
}

//------------------------------------------------------------------------------
// Address: 0x00416000
// Name: public: virtual void CPhysCollisionEntryStaticSolid::WriteToTextBuffer(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticSolid::WriteToTextBuffer(
        CPhysCollisionEntryStaticSolid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "staticsolid {\n", len: 14);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", outputData: collideIndex);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "contents", outputData: this->m_contentsMask);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", len: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00416050
// Name: public: virtual void CPhysCollisionEntryStaticMesh::WriteToTextBuffer(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticMesh::WriteToTextBuffer(
        CPhysCollisionEntryStaticMesh *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "staticsolid {\n", len: 14);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", outputData: collideIndex);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", len: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00416090
// Name: void EmitPhysCollision(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall EmitPhysCollision(int a1@<edi>)
{
  int v1; // ecx
  dleaf_t *v2; // eax
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  int v4; // ecx
  int *p_m_nGrowSize; // eax
  int v6; // ebx
  bool v7; // zf
  CTextBuffer **v8; // esi
  CUtlMemory<char,int> *v9; // eax
  CUtlMemory<char,int> *v10; // ebx
  int *v11; // edx
  int v12; // esi
  int v13; // eax
  CTextBuffer *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v18; // eax
  char *v19; // eax
  int v20; // kr00_4
  unsigned int v21; // edi
  int v22; // ebx
  int v23; // eax
  char *v24; // ecx
  int v25; // eax
  int j; // eax
  const char *v27; // edi
  int v28; // kr08_4
  int v29; // eax
  char *v30; // ecx
  int v31; // eax
  int i; // eax
  int v33; // eax
  char *v34; // ecx
  int v35; // eax
  char *v36; // esi
  int v37; // eax
  char *v38; // ecx
  int v39; // eax
  unsigned int v40; // esi
  int v41; // ebx
  unsigned __int8 *v42; // esi
  int v43; // ebx
  int v44; // edi
  int v45; // eax
  int v46; // ecx
  unsigned __int8 *v47; // esi
  int v48; // edi
  int v49; // eax
  CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *v50; // edx
  int v51; // ebx
  char *v52; // esi
  CTextBuffer *v53; // edi
  CTextBuffer *v54; // edi
  bool v55; // sf
  char *v56; // eax
  double v57; // st7
  char *v58; // esi
  int k; // edi
  void *v60; // eax
  int mergeTolerance; // [esp+4h] [ebp-6440h]
  CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > collisionList[1024]; // [esp+14h] [ebp-6430h] BYREF
  char v63; // [esp+5014h] [ebp-1430h] BYREF
  CTextBuffer *v64[1024]; // [esp+5018h] [ebp-142Ch] BYREF
  char string[1024]; // [esp+6018h] [ebp-42Ch] BYREF
  int v66; // [esp+6418h] [ebp-2Ch]
  __int64 v67; // [esp+641Ch] [ebp-28h]
  __int64 v68; // [esp+6424h] [ebp-20h]
  CUtlMemory<char,int> *v69; // [esp+642Ch] [ebp-18h]
  int v70; // [esp+6430h] [ebp-14h]
  int v71; // [esp+6434h] [ebp-10h]
  int *p_m_Size; // [esp+6438h] [ebp-Ch]
  int v73; // [esp+643Ch] [ebp-8h]
  CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *v74; // [esp+6440h] [ebp-4h]

  v1 = numleafs;
  if ( numleafs > 0 )
  {
    v2 = dleafs;
    do
    {
      v2->contents &= ~0x100u;
      v2->leafWaterDataID = -1;
      ++v2;
      --v1;
    }
    while ( v1 != 0 );
  }
  PhysicsFactory = GetPhysicsFactory();
  if ( PhysicsFactory != nullptr )
    physcollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr);
  if ( physcollision == nullptr )
  {
    _Warning(a1: "!!! WARNING: Can't build collision data!\n");
    return;
  }
  v4 = 1023;
  p_m_nGrowSize = &collisionList[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v4;
  }
  while ( v4 >= 0 );
  v70 = 0;
  v74 = nullptr;
  v66 = (int)((double (*)(void))_Plat_FloatTime)();
  _Msg(a1: "Building Physics collision data...\n");
  v73 = 0;
  if ( nummodels > 0 )
  {
    v6 = 0;
    do
    {
      if ( v6 != 0 )
        ConvertModelToPhysCollide(
          a1: v6,
          a2: 0.0099999998,
          collisionList: &collisionList[v6],
          mass: (int)&unk_203403B,
          shrinkSize: 0.5);
      else
        BuildWorldPhysModel(collisionList, a2: a1, shrinkSize: 0.0, mergeTolerance: 0.0099999998);
      a1 = 20 * v6;
      v7 = collisionList[v6].m_Size == 0;
      v8 = &v64[v6];
      *v8 = nullptr;
      p_m_Size = &collisionList[v6].m_Size;
      if ( !v7 )
      {
        v9 = (CUtlMemory<char,int> *)MemAlloc_Alloc(nSize: 0x14u);
        if ( v9 != nullptr )
        {
          v9->m_pMemory = nullptr;
          v9->m_nAllocationCount = 0;
          v9->m_nGrowSize = 0;
          v9[1].m_pMemory = nullptr;
          v9[1].m_nAllocationCount = 0;
          v10 = v9;
          v69 = v9;
        }
        else
        {
          v10 = nullptr;
          v69 = nullptr;
        }
        v11 = p_m_Size;
        *v8 = (CTextBuffer *)v10;
        v12 = 0;
        if ( *v11 > 0 )
        {
          a1 += (int)collisionList;
          do
          {
            if ( dumpcollide != 0 )
              (*(void (__thiscall **)(_DWORD, CUtlMemory<char,int> *, int, int))(**(_DWORD **)(*(_DWORD *)a1 + 4 * v12)
                                                                               + 4))(
                a1: *(_DWORD *)(*(_DWORD *)a1 + 4 * v12),
                a2: v10,
                a3: v73,
                a4: v12);
            (***(void (__thiscall ****)(_DWORD, CUtlMemory<char,int> *, int, int))(*(_DWORD *)a1 + 4 * v12))(
              a1: *(_DWORD *)(*(_DWORD *)a1 + 4 * v12),
              a2: v10,
              a3: v73,
              a4: v12);
            v13 = physcollision->CollideSize(
                    this: physcollision,
                    a2: *(CPhysCollide **)(*(_DWORD *)(*(_DWORD *)a1 + 4 * v12++) + 4));
            v74 = (CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *)((char *)v74 + v13 + 4);
          }
          while ( v12 < *p_m_Size );
        }
        if ( v73 == 0 )
        {
          v14 = v64[0];
          if ( !g_bNoVirtualMesh && physcollision->SupportsVirtualMesh(this: physcollision) )
            CTextBuffer::CopyData(this: v14, pData: "virtualterrain {}\n", len: 18);
          if ( s_WorldPropList.m_Size != 0 )
          {
            m_Size = v14->m_buffer.m_Size;
            m_nAllocationCount = v14->m_buffer.m_Memory.m_nAllocationCount;
            if ( m_Size + 16 > m_nAllocationCount )
              CUtlMemory<bool,int>::Grow(this: &v14->m_buffer.m_Memory, num: m_Size - m_nAllocationCount + 16);
            v14->m_buffer.m_Size += 16;
            m_pMemory = v14->m_buffer.m_Memory.m_pMemory;
            v18 = v14->m_buffer.m_Size - m_Size - 16;
            v14->m_buffer.m_pElements = v14->m_buffer.m_Memory.m_pMemory;
            if ( v18 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 16], src: &m_pMemory[m_Size], count: v18);
            v19 = v14->m_buffer.m_Memory.m_pMemory;
            *(_QWORD *)&v19[m_Size] = *(_QWORD *)aMaterial_0;
            *(_QWORD *)&v19[m_Size + 8] = 0xA7B20656C626174LL;
            if ( s_WorldPropList.m_Size > 0 )
            {
              v71 = 1;
              p_m_Size = nullptr;
              while ( *(int *)((char *)p_m_Size + (unsigned int)s_WorldPropList.m_Memory.m_pMemory) >= 0 )
              {
                v27 = physprops->GetPropName(
                        this: physprops,
                        a2: *(int *)((char *)p_m_Size + (unsigned int)s_WorldPropList.m_Memory.m_pMemory));
                if ( strlen(v27) <= 0x3E8 )
                {
                  sprintf(string, format: "\"%s\" \"%d\"\n", v27, v71);
                  v28 = strlen(string);
                  v21 = v28;
                  v22 = v14->m_buffer.m_Size;
                  if ( v28 != 0 )
                  {
                    v29 = v14->m_buffer.m_Memory.m_nAllocationCount;
                    if ( v22 + v28 > v29 )
                      CUtlMemory<bool,int>::Grow(this: &v14->m_buffer.m_Memory, num: v28 + v22 - v29);
                    v14->m_buffer.m_Size += v28;
                    v30 = v14->m_buffer.m_Memory.m_pMemory;
                    v31 = v14->m_buffer.m_Size - v28 - v22;
                    v14->m_buffer.m_pElements = v14->m_buffer.m_Memory.m_pMemory;
                    if ( v31 > 0 && v28 > 0 )
                      _V_memmove(dest: &v30[v28 + v22], src: &v30[v22], count: v31);
                    for ( i = 0; i < v28; ++i )
                      ;
                  }
                  goto LABEL_55;
                }
                _Msg(a1: "Error writing collision data %s\n", v27);
LABEL_56:
                ++p_m_Size;
                if ( v71++ >= s_WorldPropList.m_Size )
                  goto LABEL_57;
              }
              sprintf(string, format: "\"%s\" \"%d\"\n", "default", v71);
              v20 = strlen(string);
              v21 = v20;
              v22 = v14->m_buffer.m_Size;
              if ( v20 != 0 )
              {
                v23 = v14->m_buffer.m_Memory.m_nAllocationCount;
                if ( v22 + v20 > v23 )
                  CUtlMemory<bool,int>::Grow(this: &v14->m_buffer.m_Memory, num: v20 + v22 - v23);
                v14->m_buffer.m_Size += v20;
                v24 = v14->m_buffer.m_Memory.m_pMemory;
                v25 = v14->m_buffer.m_Size - v22 - v20;
                v14->m_buffer.m_pElements = v14->m_buffer.m_Memory.m_pMemory;
                if ( v25 > 0 && v20 > 0 )
                  _V_memmove(dest: &v24[v22 + v20], src: &v24[v22], count: v25);
                for ( j = 0; j < v20; ++j )
                  ;
              }
LABEL_55:
              memcpy(
                dst: (unsigned __int8 *)&v14->m_buffer.m_Memory.m_pMemory[v22],
                src: (unsigned __int8 *)string,
                count: v21);
              v10 = v69;
              goto LABEL_56;
            }
LABEL_57:
            a1 = v14->m_buffer.m_Size;
            v33 = v14->m_buffer.m_Memory.m_nAllocationCount;
            if ( a1 + 2 > v33 )
              CUtlMemory<bool,int>::Grow(this: &v14->m_buffer.m_Memory, num: a1 - v33 + 2);
            v14->m_buffer.m_Size += 2;
            v34 = v14->m_buffer.m_Memory.m_pMemory;
            v35 = v14->m_buffer.m_Size - a1 - 2;
            v14->m_buffer.m_pElements = v14->m_buffer.m_Memory.m_pMemory;
            if ( v35 > 0 )
              _V_memmove(dest: &v34[a1 + 2], src: &v34[a1], count: v35);
            *(_WORD *)&v14->m_buffer.m_Memory.m_pMemory[a1] = *(_WORD *)"}\n";
          }
        }
        v36 = v10[1].m_pMemory;
        v37 = v10->m_nAllocationCount;
        if ( (int)(v36 + 1) > v37 )
          CUtlMemory<bool,int>::Grow(this: v10, num: (int)&v36[-v37 + 1]);
        ++v10[1].m_pMemory;
        v38 = v10->m_pMemory;
        v39 = v10[1].m_pMemory - v36 - 1;
        v10[1].m_nAllocationCount = (int)v10->m_pMemory;
        if ( v39 > 0 )
          _V_memmove(dest: &v38[(_DWORD)v36 + 1], src: &v38[(_DWORD)v36], count: v39);
        v10->m_pMemory[(unsigned int)v36] = 0;
        v74 = (CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *)((char *)v74
                                                                                         + (unsigned int)v10[1].m_pMemory);
        ++v70;
        v6 = v73;
      }
      v73 = ++v6;
    }
    while ( v6 < nummodels );
  }
  v40 = (unsigned int)(&v74->m_pElements + 4 * v70);
  g_PhysCollideSize = v40;
  v41 = 0;
  g_pPhysCollide = (unsigned __int8 *)MemAlloc_Alloc(nSize: (v40 + 3) & 0xFFFFFFFC);
  memset(dst: g_pPhysCollide, value: 0, count: v40);
  v42 = g_pPhysCollide;
  v73 = 0;
  if ( nummodels > 0 )
  {
    v74 = collisionList;
    do
    {
      if ( v64[v41] != nullptr )
      {
        v43 = v74->m_Size;
        v44 = 0;
        LODWORD(v67) = v73;
        HIDWORD(v68) = v43;
        for ( HIDWORD(v67) = 4 * v43; v44 < v43; ++v44 )
        {
          v45 = physcollision->CollideSize(this: physcollision, a2: v74->m_Memory.m_pMemory[v44]->m_pCollide);
          HIDWORD(v67) += v45;
        }
        v46 = v64[v73]->m_buffer.m_Size;
        *(_QWORD *)v42 = v67;
        LODWORD(v68) = v46;
        *((_QWORD *)v42 + 1) = v68;
        v47 = v42 + 16;
        v48 = 0;
        if ( v43 > 0 )
        {
          do
          {
            v49 = physcollision->CollideSize(this: physcollision, a2: v74->m_Memory.m_pMemory[v48]->m_pCollide);
            v50 = v74;
            v51 = v49;
            *(_DWORD *)v47 = v49;
            v52 = (char *)(v47 + 4);
            physcollision->CollideWrite(
              this: physcollision,
              a2: v52,
              a3: v50->m_Memory.m_pMemory[v48++]->m_pCollide,
              a4: false);
            v47 = (unsigned __int8 *)&v52[v51];
          }
          while ( v48 < SHIDWORD(v68) );
        }
        v53 = v64[v73];
        memcpy(dst: v47, src: (unsigned __int8 *)v53->m_buffer.m_Memory.m_pMemory, count: v53->m_buffer.m_Size);
        v41 = v73;
        v42 = &v47[v53->m_buffer.m_Size];
      }
      v54 = v64[v41];
      if ( v54 != nullptr )
      {
        v55 = v54->m_buffer.m_Memory.m_nGrowSize < 0;
        v54->m_buffer.m_Size = 0;
        if ( !v55 )
        {
          if ( v54->m_buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54->m_buffer.m_Memory.m_pMemory);
            v54->m_buffer.m_Memory.m_pMemory = nullptr;
          }
          v54->m_buffer.m_Memory.m_nAllocationCount = 0;
        }
        v55 = v54->m_buffer.m_Memory.m_nGrowSize < 0;
        v56 = v54->m_buffer.m_Memory.m_pMemory;
        v54->m_buffer.m_pElements = v54->m_buffer.m_Memory.m_pMemory;
        if ( !v55 )
        {
          if ( v56 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v56);
            v54->m_buffer.m_Memory.m_pMemory = nullptr;
          }
          v54->m_buffer.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v54);
      }
      ++v74;
      v73 = ++v41;
    }
    while ( v41 < nummodels );
  }
  v67 = -1;
  *(_QWORD *)v42 = -1;
  v68 = 0;
  *((_QWORD *)v42 + 1) = 0;
  v57 = _Plat_FloatTime(a1: g_PhysCollideSize);
  _Msg(a1: "done (%d) (%d bytes)\n", (int)(v57 - (double)v66), mergeTolerance);
  v58 = &v63;
  for ( k = 1023; k >= 0; --k )
  {
    v58 -= 20;
    *((_DWORD *)v58 + 3) = 0;
    if ( *((int *)v58 + 2) >= 0 )
    {
      if ( *(_DWORD *)v58 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v58);
        *(_DWORD *)v58 = 0;
      }
      *((_DWORD *)v58 + 1) = 0;
    }
    v60 = *(void **)v58;
    *((_DWORD *)v58 + 4) = *(_DWORD *)v58;
    if ( *((int *)v58 + 2) >= 0 )
    {
      if ( v60 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v60);
        *(_DWORD *)v58 = 0;
      }
      *((_DWORD *)v58 + 1) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416850
// Name: public: void CTextBuffer::WriteStringKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteStringKey(CTextBuffer *this, char *pKeyName, char *outputData)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // ecx
  int v11; // eax

  CTextBuffer::CopyStringQuotes(this, pString: pKeyName);
  m_Size = this->m_buffer.m_Size;
  m_nAllocationCount = this->m_buffer.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_buffer.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_buffer.m_Size;
  m_pMemory = this->m_buffer.m_Memory.m_pMemory;
  v7 = this->m_buffer.m_Size - m_Size - 1;
  this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
  this->m_buffer.m_Memory.m_pMemory[m_Size] = control[0];
  CTextBuffer::CopyStringQuotes(this, pString: outputData);
  v8 = this->m_buffer.m_Size;
  v9 = this->m_buffer.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<bool,int>::Grow(this: &this->m_buffer.m_Memory, num: v8 - v9 + 1);
  ++this->m_buffer.m_Size;
  v10 = this->m_buffer.m_Memory.m_pMemory;
  v11 = this->m_buffer.m_Size - v8 - 1;
  this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: v11);
  this->m_buffer.m_Memory.m_pMemory[v8] = OutputString[0];
}

//------------------------------------------------------------------------------
// Address: 0x00416900
// Name: public: virtual void CPhysCollisionEntrySolid::WriteToTextBuffer(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntrySolid::WriteToTextBuffer(
        CPhysCollisionEntrySolid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "solid {\n", len: 8);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", outputData: collideIndex);
  CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "mass", outputData: this->m_mass);
  if ( this->m_pMaterial != nullptr )
    CTextBuffer::WriteStringKey(this: pTextBuffer, pKeyName: "surfaceprop", outputData: (char *)this->m_pMaterial);
  if ( this->m_volume != 0.0 )
    CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "volume", outputData: this->m_volume);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", len: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00416990
// Name: public: virtual void CPhysCollisionEntryFluid::WriteToTextBuffer(class CTextBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryFluid::WriteToTextBuffer(
        CPhysCollisionEntryFluid *this,
        CTextBuffer *pTextBuffer,
        int modelIndex,
        int collideIndex)
{
  float array[4]; // [esp+Ch] [ebp-10h] BYREF

  CTextBuffer::CopyData(this: pTextBuffer, pData: "fluid {\n", len: 8);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", outputData: collideIndex);
  CTextBuffer::WriteStringKey(this: pTextBuffer, pKeyName: "surfaceprop", outputData: this->m_pSurfaceProp);
  CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "damping", outputData: this->m_damping);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "contents", outputData: this->m_contentsMask);
  *(Vector *)array = this->m_surfaceNormal;
  array[3] = this->m_surfaceDist;
  CTextBuffer::WriteFloatArrayKey(this: pTextBuffer, pKeyName: "surfaceplane", outputData: array, count: 4);
  CTextBuffer::WriteFloatArrayKey(this: pTextBuffer, pKeyName: "currentvelocity", outputData: &vec3_origin.x, count: 3);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", len: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00416A60
// Name: int FindOrCreateWaterTexInfo(struct texinfo_s __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrCreateWaterTexInfo(texinfo_s *pBaseInfo, float depth)
{
  texinfo_s *v2; // ebx
  dtexdata_t *TexData; // eax
  const char *v4; // eax
  int v5; // edi
  const char *v6; // esi
  int v7; // eax
  char v8; // cl
  int v9; // eax
  dtexdata_t *v11; // eax
  int v12; // esi
  int v13; // [esp-4h] [ebp-664h]
  char fullname[512]; // [esp+Ch] [ebp-654h] BYREF
  char materialname[512]; // [esp+20Ch] [ebp-454h] BYREF
  char string[512]; // [esp+40Ch] [ebp-254h] BYREF
  texinfo_s ti; // [esp+60Ch] [ebp-54h] BYREF
  WaterTexInfo lookup; // [esp+654h] [ebp-Ch] BYREF

  v2 = pBaseInfo;
  TexData = GetTexData(index: pBaseInfo->texdata);
  v4 = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
  v5 = (int)depth;
  v6 = v4;
  sprintf(string, format: "maps/%s/%s_depth_%i", mapbase, v4, (int)depth);
  strlwr(string);
  v7 = 0;
  do
  {
    v8 = string[v7];
    fullname[v7++] = v8;
  }
  while ( v8 != 0 );
  *(_DWORD *)&lookup.m_FullName.m_Id = -1;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pBaseInfo + 1, pStr: fullname);
  lookup.m_FullName.m_Id = HIWORD(pBaseInfo);
  v9 = CUtlRBTree<WaterTexInfo,int,bool (__cdecl *)(WaterTexInfo const &,WaterTexInfo const &),CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>>::Find(
         this: &g_WaterTexInfos,
         search: &lookup);
  if ( v9 != -1 )
    return g_WaterTexInfos.m_Elements.m_pMemory[v9].m_Data.m_nTexInfo;
  lookup.m_nWaterDepth = v5;
  sprintf(string: materialname, format: "%s", v6);
  strlwr(string: materialname);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pBaseInfo + 1, pStr: materialname);
  ti = *v2;
  v13 = v2->texdata;
  lookup.m_MaterialName.m_Id = HIWORD(pBaseInfo);
  v11 = GetTexData(index: v13);
  ti.texdata = FindAliasedTexData(pName_: fullname, sourceTexture: v11);
  lookup.m_nTexInfo = FindOrCreateTexInfo(searchTexInfo: &ti);
  v12 = CUtlRBTree<WaterTexInfo,int,bool (__cdecl *)(WaterTexInfo const &,WaterTexInfo const &),CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>>::Insert(
          this: &g_WaterTexInfos,
          insert: &lookup);
  EmitWaterMaterialFile(wti: &g_WaterTexInfos.m_Elements.m_pMemory[v12].m_Data);
  return g_WaterTexInfos.m_Elements.m_pMemory[v12].m_Data.m_nTexInfo;
}

//------------------------------------------------------------------------------
// Address: 0x00416BC0
// Name: void EmitWaterVolumesForBSP(struct dmodel_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitWaterVolumesForBSP(dmodel_t *pModel, node_t *node)
{
  int m_Size; // esi
  int v3; // ebx
  int v4; // ecx
  float *p_z; // eax
  float *v6; // ebx
  int v7; // xmm0_4
  int v8; // eax
  int WaterTexinfo; // esi
  int v10; // edi
  float v11; // xmm1_4
  int v12; // edx
  int v13; // xmm0_4
  int v14; // edx
  float v15; // xmm0_4
  float depth; // xmm0_4
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  __int16 *p_surfaceTexInfoID; // edx
  __int16 v21; // dx
  dleafwaterdata_t *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  node_t *v26; // edi
  int v27; // esi
  int *v28; // eax
  int v29; // eax
  int v30; // esi
  watermodel_t *m_pMemory; // ecx
  int v32; // eax
  watermodel_t *v33; // edi
  node_t **v34; // eax
  node_t **v35; // eax
  CBitVec<65536> dst; // [esp+10h] [ebp-2088h] BYREF
  _BYTE v37[68]; // [esp+2010h] [ebp-88h] BYREF
  CUtlVector<waterleaf_t,CUtlMemory<waterleaf_t,int> > v38; // [esp+2054h] [ebp-44h] BYREF
  int v39; // [esp+2068h] [ebp-30h]
  CUtlVector<node_t *,CUtlMemory<node_t *,int> > list; // [esp+206Ch] [ebp-2Ch] BYREF
  int i; // [esp+2080h] [ebp-18h]
  CUtlVector<node_t *,CUtlMemory<node_t *,int> > v42; // [esp+2084h] [ebp-14h] BYREF

  memset(&list, 0, sizeof(list));
  EnumLeaves_r(&list, node, contentsMask: 16432);
  m_Size = 0;
  v3 = 0;
  memset(&v38, 0, sizeof(v38));
  if ( list.m_Size > 0 )
  {
    do
    {
      BuildWaterLeaf(pLeafIn: list.m_Memory.m_pMemory[v3]);
      v4 = 0;
      if ( m_Size <= 0 )
      {
LABEL_8:
        CUtlVector<waterleaf_t,CUtlMemory<waterleaf_t,int>>::InsertBefore(
          this: &v38,
          elem: m_Size,
          src: (const waterleaf_t *)&v37[24]);
      }
      else
      {
        p_z = &v38.m_Memory.m_pMemory->surfaceNormal.z;
        while ( v37[44] == 0 || *((_BYTE *)p_z + 12) != 0 && *p_z > *(float *)&v37[32] )
        {
          ++v4;
          p_z += 11;
          if ( v4 >= m_Size )
            goto LABEL_8;
        }
        CUtlVector<waterleaf_t,CUtlMemory<waterleaf_t,int>>::InsertBefore(
          this: &v38,
          elem: v4,
          src: (const waterleaf_t *)&v37[24]);
      }
      m_Size = v38.m_Size;
      ++v3;
    }
    while ( v3 < list.m_Size );
  }
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  memset(&v42, 0, sizeof(v42));
  if ( m_Size > 0 )
  {
    v6 = &v38.m_Memory.m_pMemory->surfaceNormal.z;
    for ( i = m_Size; i != 0; --i )
    {
      Flood_FindConnectedWaterVolumes_r(
        list: &v42,
        pLeaf: *((node_t **)v6 + 8),
        baseleaf: (waterleaf_t *)(v6 - 2),
        visited: &dst);
      if ( v42.m_Size != 0 )
      {
        v7 = *((_DWORD *)v6 - 2);
        v8 = *((_DWORD *)v6 + 8);
        WaterTexinfo = *((_DWORD *)v6 + 6);
        v10 = *(_DWORD *)(v8 + 64);
        v11 = v6[2];
        *(_DWORD *)v37 = nummodels;
        v37[28] = *((_BYTE *)v6 + 12);
        *(float *)&v37[32] = v6[4];
        v12 = *((_DWORD *)v6 + 5);
        *(_DWORD *)&v37[8] = v7;
        *(float *)&v37[12] = *(v6 - 1);
        v13 = *(_DWORD *)v6;
        *(_DWORD *)&v37[36] = v12;
        v14 = *((_DWORD *)v6 + 7);
        *(_DWORD *)&v37[16] = v13;
        v15 = v6[1];
        *(_DWORD *)&v37[44] = v14;
        *(float *)&v37[20] = v15;
        *(_DWORD *)&v37[4] = v10;
        *(float *)&v37[24] = v11;
        *(_DWORD *)&v37[40] = WaterTexinfo;
        *(_DWORD *)&v37[48] = v8;
        *(_DWORD *)&v37[56] = g_WaterLeafList.m_Size;
        *(_DWORD *)&v37[60] = v42.m_Size;
        depth = v15 - v11;
        if ( WaterTexinfo < 0 )
        {
          WaterTexinfo = FirstWaterTexinfo(brushlist: *(bspbrush_t **)(v8 + 56), contents: v10);
          *(_DWORD *)&v37[40] = WaterTexinfo;
        }
        v17 = FindOrCreateWaterTexInfo(pBaseInfo: &texinfo.m_Memory.m_pMemory[WaterTexinfo], depth);
        v18 = *(float *)&v37[24];
        v19 = 0;
        *(_DWORD *)&v37[52] = v17;
        if ( numleafwaterdata <= 0 )
        {
LABEL_21:
          v21 = *(_WORD *)&v37[40];
          v22 = &dleafwaterdata[numleafwaterdata];
          v23 = numleafwaterdata + 1;
          v22->surfaceZ = *(float *)&v37[20];
          v22->minZ = v18;
          v22->surfaceTexInfoID = v21;
          numleafwaterdata = v23;
          v19 = v23 - 1;
        }
        else
        {
          p_surfaceTexInfoID = &dleafwaterdata[0].surfaceTexInfoID;
          while ( *((float *)p_surfaceTexInfoID - 2) != *(float *)&v37[20]
               || *((float *)p_surfaceTexInfoID - 1) != *(float *)&v37[24]
               || *p_surfaceTexInfoID != WaterTexinfo )
          {
            ++v19;
            p_surfaceTexInfoID += 6;
            if ( v19 >= numleafwaterdata )
              goto LABEL_21;
          }
        }
        v24 = 0;
        *(_DWORD *)&v37[64] = v19;
        v39 = 0;
        if ( v42.m_Size > 0 )
        {
          v25 = g_WaterLeafList.m_Size;
          do
          {
            v26 = v42.m_Memory.m_pMemory[v24];
            v27 = v25;
            if ( v25 + 1 > g_WaterLeafList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CClassInput *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&g_WaterLeafList,
                num: v25 - g_WaterLeafList.m_Memory.m_nAllocationCount + 1);
              v25 = g_WaterLeafList.m_Size;
            }
            g_WaterLeafList.m_Size = ++v25;
            g_WaterLeafList.m_pElements = g_WaterLeafList.m_Memory.m_pMemory;
            if ( v25 - v27 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_WaterLeafList.m_Memory.m_pMemory[v27 + 1],
                src: &g_WaterLeafList.m_Memory.m_pMemory[v27],
                count: 4 * (v25 - v27 - 1));
              v25 = g_WaterLeafList.m_Size;
            }
            v28 = &g_WaterLeafList.m_Memory.m_pMemory[v27];
            if ( v28 != nullptr )
            {
              *v28 = v26->diskId;
              v25 = g_WaterLeafList.m_Size;
            }
            v24 = v39 + 1;
            v39 = v24;
          }
          while ( v24 < v42.m_Size );
        }
        v29 = g_WaterModels.m_Size;
        v42.m_Size = 0;
        v30 = g_WaterModels.m_Size;
        if ( g_WaterModels.m_Size + 1 > g_WaterModels.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<DetailModel_t,int>::Grow(
            this: (CUtlMemory<DetailModel_t,int> *)&g_WaterModels,
            num: g_WaterModels.m_Size - g_WaterModels.m_Memory.m_nAllocationCount + 1);
          v29 = g_WaterModels.m_Size;
        }
        m_pMemory = g_WaterModels.m_Memory.m_pMemory;
        g_WaterModels.m_Size = v29 + 1;
        v32 = v29 - v30;
        g_WaterModels.m_pElements = g_WaterModels.m_Memory.m_pMemory;
        if ( v32 > 0 )
        {
          _V_memmove(
            dest: &g_WaterModels.m_Memory.m_pMemory[v30 + 1],
            src: &g_WaterModels.m_Memory.m_pMemory[v30],
            count: 68 * v32);
          m_pMemory = g_WaterModels.m_Memory.m_pMemory;
        }
        v33 = &m_pMemory[v30];
        if ( v33 != nullptr )
          qmemcpy(v33, v37, sizeof(watermodel_t));
      }
      v6 += 11;
    }
  }
  WriteFogVolumeIDs(pModel);
  v34 = v42.m_Memory.m_pMemory;
  v42.m_Size = 0;
  if ( v42.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v42.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_Memory.m_pMemory);
      v34 = nullptr;
      v42.m_Memory.m_pMemory = nullptr;
    }
    v42.m_Memory.m_nAllocationCount = 0;
  }
  v42.m_pElements = v34;
  if ( v42.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v34 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34);
      v42.m_Memory.m_pMemory = nullptr;
    }
    v42.m_Memory.m_nAllocationCount = 0;
  }
  if ( v38.m_Memory.m_nGrowSize >= 0 && v38.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38.m_Memory.m_pMemory);
  v35 = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      v35 = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = v35;
  if ( list.m_Memory.m_nGrowSize >= 0 && v35 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v35);
}
