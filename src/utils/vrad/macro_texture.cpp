// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/macro_texture.cpp
// Functions: 8
// ============================================================

#include "utils\vrad\macro_texture.h"

//------------------------------------------------------------------------------
// Address: 0x10004D00
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010E60
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010EB0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10010EE0
// Name: class Vector SampleMacroTexture(class CMacroTextureData const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl SampleMacroTexture(Vector *result, const CMacroTextureData *t, const Vector *vWorldPos)
{
  float x; // xmm0_4
  int m_Width; // ebx
  float v5; // xmm3_4
  float v6; // xmm0_4
  int v7; // edx
  float y; // xmm0_4
  int m_Height; // ecx
  float v10; // xmm3_4
  float v11; // xmm0_4
  int v12; // eax
  int v13; // ecx
  unsigned __int8 *m_pMemory; // edx
  double v15; // xmm1_8
  unsigned __int8 *v17; // ecx
  int v18; // edx
  int v19; // ecx

  x = vWorldPos->x;
  m_Width = t->m_Width;
  if ( g_MacroWorldMins.x == g_MacroWorldMaxs.x )
  {
    if ( (float)(x - g_MacroWorldMaxs.x) < 0.0 )
      v6 = 0.0;
    else
      v6 = (double)t->m_Width - 0.00001;
  }
  else
  {
    v5 = (double)t->m_Width - 0.00001;
    v6 = (float)((float)(x - g_MacroWorldMins.x) * v5) / (float)(g_MacroWorldMaxs.x - g_MacroWorldMins.x);
  }
  v7 = (int)v6;
  y = vWorldPos->y;
  m_Height = t->m_Height;
  if ( g_MacroWorldMins.y == g_MacroWorldMaxs.y )
  {
    if ( (float)(y - g_MacroWorldMaxs.y) < 0.0 )
      v11 = 0.0;
    else
      v11 = (double)m_Height - 0.00001;
  }
  else
  {
    v10 = (double)m_Height - 0.00001;
    v11 = (float)((float)(y - g_MacroWorldMins.y) * v10) / (float)(g_MacroWorldMaxs.y - g_MacroWorldMins.y);
  }
  v12 = (int)v11;
  if ( v7 >= 0 )
  {
    if ( v7 > m_Width - 1 )
      v7 = m_Width - 1;
  }
  else
  {
    v7 = 0;
  }
  if ( v12 >= 0 )
  {
    if ( v12 > m_Height - 1 )
      v12 = m_Height - 1;
  }
  else
  {
    v12 = 0;
  }
  v13 = v7 + m_Width * (m_Height - v12 - 1);
  m_pMemory = t->m_ImageData.m_pMemory;
  v15 = (double)m_pMemory[4 * v13];
  v17 = &m_pMemory[4 * v13];
  v18 = v17[1];
  v19 = v17[2];
  *(float *)&v15 = v15 * 0.00392156862745098;
  result->x = *(float *)&v15;
  *(float *)&v15 = (double)v18 * 0.00392156862745098;
  result->y = *(float *)&v15;
  result->z = (double)v19 * 0.00392156862745098;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100110A0
// Name: void ApplyMacroTextures(int,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyMacroTextures(int iFace, const Vector *vWorldPos, Vector *outLuxel)
{
  Vector *v3; // eax
  Vector *v4; // eax
  Vector result; // [esp+8h] [ebp-Ch] BYREF

  if ( g_pGlobalMacroTextureData != nullptr )
  {
    v3 = SampleMacroTexture(&result, t: g_pGlobalMacroTextureData, vWorldPos);
    outLuxel->x = outLuxel->x * v3->x;
    outLuxel->y = v3->y * outLuxel->y;
    outLuxel->z = v3->z * outLuxel->z;
  }
  if ( g_FaceMacroTextures.m_Memory.m_pMemory[iFace] != nullptr )
  {
    v4 = SampleMacroTexture(&result, t: g_FaceMacroTextures.m_Memory.m_pMemory[iFace], vWorldPos);
    outLuxel->x = v4->x * outLuxel->x;
    outLuxel->y = v4->y * outLuxel->y;
    outLuxel->z = v4->z * outLuxel->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012160
// Name: class CMacroTextureData __near * LoadMacroTextureFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMacroTextureData *__usercall LoadMacroTextureFile@<eax>(int a1@<ebx>, int a2@<esi>, const char *pFilename)
{
  char *m_pMemory; // edi
  void *v4; // eax
  unsigned int (__thiscall *Size_2)(IBaseFileSystem *, void *); // eax
  int v7; // eax
  int v8; // esi
  int m_Size; // ebx
  void *v10; // esi
  _DWORD *v11; // esi
  IVTFTexture *VTFTexture; // edi
  _DWORD *v13; // eax
  int v14; // eax
  signed int v15; // edx
  void *v16; // eax
  void *v17; // eax
  unsigned __int8 *v18; // ebx
  unsigned __int8 *v19; // eax
  void *v20; // [esp-Ch] [ebp-58h]
  unsigned int v21; // [esp-Ch] [ebp-58h]
  CUtlBuffer buf; // [esp+4h] [ebp-48h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > tempData; // [esp+34h] [ebp-18h] BYREF
  void *hFile; // [esp+48h] [ebp-4h]

  m_pMemory = nullptr;
  v4 = g_pFileSystem->Open(this: g_pFileSystem, a2: pFilename, a3: "rb", a4: 0);
  hFile = v4;
  if ( v4 == nullptr )
    return nullptr;
  v20 = v4;
  Size_2 = g_pFileSystem->Size_2;
  memset(&tempData, 0, sizeof(tempData));
  v7 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int))Size_2)(a1: g_pFileSystem, a2: v20, a3: a2, a4: a1);
  v8 = v7;
  m_Size = 0;
  if ( v7 != 0 )
  {
    if ( v7 > 0 )
    {
      CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&tempData, num: v7);
      m_Size = tempData.m_Size;
      m_pMemory = tempData.m_Memory.m_pMemory;
    }
    m_Size += v8;
    tempData.m_Size = m_Size;
    tempData.m_pElements = m_pMemory;
    if ( m_Size - v8 > 0 && v8 > 0 )
      _V_memmove(dest: &m_pMemory[v8], src: m_pMemory, count: m_Size - v8);
  }
  v10 = hFile;
  g_pFileSystem->Read(this: g_pFileSystem, a2: m_pMemory, a3: m_Size, a4: hFile);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v10);
  v11 = nullptr;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::Put(this: &buf, pMem: m_pMemory, size: m_Size);
  VTFTexture = CreateVTFTexture();
  if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: false, a4: 0) )
    _Error(a1: "IVTFTexture::Unserialize( %s ) failed.", pFilename);
  ((void (__thiscall *)(IVTFTexture *, _DWORD))VTFTexture->ConvertImageFormat)(a1: VTFTexture, a2: 0);
  v13 = MemAlloc_Alloc(nSize: 0x14u);
  if ( v13 != nullptr )
  {
    v13[2] = 0;
    v13[3] = 0;
    v13[4] = 0;
    v11 = v13;
  }
  *v11 = VTFTexture->Width(this: VTFTexture);
  v14 = VTFTexture->Height(this: VTFTexture);
  v15 = 4 * v14 * *v11;
  v11[1] = v14;
  if ( v11[3] < v15 && (int)v11[4] >= 0 )
  {
    v16 = (void *)v11[2];
    v11[3] = v15;
    if ( v16 != nullptr )
      v17 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v16, a3: v15);
    else
      v17 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v15);
    v11[2] = v17;
  }
  v18 = (unsigned __int8 *)v11[2];
  v21 = 4 * v11[1] * *v11;
  v19 = VTFTexture->ImageData_3(this: VTFTexture);
  memcpy(dst: v18, src: v19, count: v21);
  DestroyVTFTexture(pTexture: VTFTexture);
  _Msg(a1: "-- LoadMacroTextureFile: %s\n", pFilename);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&tempData);
  return (CMacroTextureData *)v11;
}

//------------------------------------------------------------------------------
// Address: 0x10012340
// Name: public: int CUtlMap<char const __near *,class CMacroTextureData __near *,int>::Insert(char const __near * const __near &,class CMacroTextureData __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CMacroTextureData *,int>::Insert(
        CUtlMap<char const *,CMacroTextureData *,int> *this,
        const char **key,
        int insert)
{
  CMacroTextureData *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CMacroTextureData *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CMacroTextureData **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100123C0
// Name: void InitMacroTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMacroTexture(int a1@<ebx>, entity_t *a2@<esi>, const char *pBSPFilename)
{
  int v3; // edi
  bool v4; // zf
  CMacroTextureData *MacroTextureFile; // eax
  int v6; // ecx
  int m_Size; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // eax
  CMacroTextureData *elem; // eax
  CMacroTextureData **v12; // esi
  CMacroTextureData **v13; // edi
  char *v14; // eax
  char mapName[512]; // [esp+8h] [ebp-40Ch] BYREF
  char vtfFilename[512]; // [esp+208h] [ebp-20Ch] BYREF
  CUtlMap<char const *,CMacroTextureData *,int>::Node_t search; // [esp+408h] [ebp-Ch] BYREF
  char *key; // [esp+410h] [ebp-4h] BYREF

  v3 = 0;
  v4 = num_entities == 0;
  if ( num_entities > 0 )
  {
    a2 = entities;
    while ( strcmp(ValueForKey(ent: a2, key: "classname"), "worldspawn") != 0 )
    {
      ++v3;
      ++a2;
      if ( v3 >= num_entities )
        goto LABEL_7;
    }
    a2 = &entities[v3];
    GetVectorForKey(ent: a2, key: "world_mins", angle: (QAngle *)&g_MacroWorldMins);
    GetVectorForKey(ent: a2, key: "world_maxs", angle: (QAngle *)&g_MacroWorldMaxs);
LABEL_7:
    v4 = v3 == num_entities;
  }
  if ( v4 )
  {
    _Warning(a1: "MaskOnMacroTexture: can't find worldspawn");
  }
  else
  {
    V_FileBase(in: pBSPFilename, out: mapName, maxlen: 512);
    V_snprintf(pDest: vtfFilename, maxLen: 512, pFormat: "materials/macro/%s/base.vtf", mapName);
    MacroTextureFile = LoadMacroTextureFile(a1, (int)a2, pFilename: vtfFilename);
    v6 = numfaces;
    g_pGlobalMacroTextureData = MacroTextureFile;
    m_Size = 0;
    v8 = numfaces;
    g_FaceMacroTextures.m_Size = 0;
    if ( (_DWORD)numfaces != 0 )
    {
      if ( (int)numfaces > g_FaceMacroTextures.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_FaceMacroTextures,
          num: numfaces - g_FaceMacroTextures.m_Memory.m_nAllocationCount);
        m_Size = g_FaceMacroTextures.m_Size;
        v6 = numfaces;
      }
      g_FaceMacroTextures.m_Size = v8 + m_Size;
      g_FaceMacroTextures.m_pElements = g_FaceMacroTextures.m_Memory.m_pMemory;
      if ( m_Size > 0 && v8 > 0 )
      {
        _V_memmove(
          dest: &g_FaceMacroTextures.m_Memory.m_pMemory[v8],
          src: g_FaceMacroTextures.m_Memory.m_pMemory,
          count: 4 * m_Size);
        v6 = numfaces;
      }
    }
    v9 = 0;
    if ( v6 > 0 )
    {
      do
      {
        g_FaceMacroTextures.m_Memory.m_pMemory[v9] = nullptr;
        if ( v9 < g_FaceMacroTextureInfos.m_Size
          && g_FaceMacroTextureInfos.m_Memory.m_pMemory[v9].m_MacroTextureNameID != 0xFFFF )
        {
          V_snprintf(
            pDest: vtfFilename,
            maxLen: 512,
            pFormat: "%smaterials/%s.vtf",
            gamedir,
            &g_TexDataStringData.m_Memory.m_pMemory[g_TexDataStringTable.m_Memory.m_pMemory[g_FaceMacroTextureInfos.m_Memory.m_pMemory[v9].m_MacroTextureNameID]]);
          search.key = vtfFilename;
          v10 = CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::Find(
                  this: &g_MacroTextureLookup.m_Elements.m_Tree,
                  &search);
          if ( v10 < 0
            || v10 >= g_MacroTextureLookup.m_Elements.m_Tree.m_Elements.m_nAllocationCount
            || v10 > g_MacroTextureLookup.m_Elements.m_Tree.m_LastAlloc.index )
          {
            goto LABEL_26;
          }
          if ( (`CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_111CF2D0 = -1;
            dword_111CF2D4 = -1;
            dword_111CF2D8 = 1;
          }
          if ( g_MacroTextureLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Left == v10 )
LABEL_26:
            elem = nullptr;
          else
            elem = g_MacroTextureLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem;
          g_FaceMacroTextures.m_Memory.m_pMemory[v9] = elem;
          if ( g_FaceMacroTextures.m_Memory.m_pMemory[v9] == nullptr )
          {
            v12 = &g_FaceMacroTextures.m_Memory.m_pMemory[v9];
            *v12 = LoadMacroTextureFile(a1: v9, a2: (int)v12, pFilename: vtfFilename);
            v13 = &g_FaceMacroTextures.m_Memory.m_pMemory[v9];
            if ( *v13 != nullptr )
            {
              v14 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(vtfFilename) + 1);
              if ( v14 != nullptr )
                strcpy(v14, vtfFilename);
              else
                v14 = nullptr;
              key = v14;
              CUtlMap<char const *,CMacroTextureData *,int>::Insert(
                this: &g_MacroTextureLookup.m_Elements,
                (const char **)&key,
                insert: (int)v13);
            }
          }
        }
        ++v9;
      }
      while ( v9 < (int)numfaces );
    }
  }
}
