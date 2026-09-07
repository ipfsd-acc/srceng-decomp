// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/decals.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100B6D50
// Name: int Draw_DecalMax(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Draw_DecalMax()
{
  return g_nMaxDecals;
}

//------------------------------------------------------------------------------
// Address: 0x100B7340
// Name: class IMaterial __near * Draw_DecalMaterial(int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl Draw_DecalMaterial(int index)
{
  int v1; // eax
  DecalEntry *p_elem; // eax

  if ( index >= 0
    && index < g_DecalLookup.m_Size
    && (v1 = g_DecalLookup.m_Memory.m_pMemory[index]) >= 0
    && v1 < LOWORD(g_DecalDictionary.m_Tree.m_Elements.m_nAllocationCount)
    && (p_elem = &g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1].m_Data.elem) != nullptr )
  {
    return p_elem->material;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7390
// Name: char const __near * Draw_DecalNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Draw_DecalNameFromIndex(unsigned __int16 index)
{
  IMaterial *material; // ecx

  material = g_DecalDictionary.m_Tree.m_Elements.m_pMemory[index].m_Data.elem.material;
  if ( material != nullptr )
    return material->GetName(this: material);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x100B7EF0
// Name: int Draw_DecalIndexFromName(char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Draw_DecalIndexFromName(char *name, bool *found)
{
  unsigned __int16 v2; // ax
  CUtlMap<void *,DecalEntry,unsigned short>::Node_t search; // [esp+0h] [ebp-Ch] BYREF

  search.key = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: name);
  v2 = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_DecalDictionary.m_Tree,
         &search);
  if ( v2 == 0xFFFF )
  {
    if ( found != nullptr )
      *found = false;
    return 0;
  }
  else
  {
    if ( found != nullptr )
      *found = true;
    return g_DecalDictionary.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem.index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7F50
// Name: void Decal_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Decal_Shutdown()
{
  int i; // esi
  int *m_pMemory; // eax

  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_DecalDictionary.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &g_DecalDictionary.m_Tree,
                                i) )
  {
    if ( g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.material != nullptr )
      GL_UnloadMaterial(pMaterial: g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.material);
  }
  m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
  g_DecalLookup.m_Size = 0;
  if ( g_DecalLookup.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DecalLookup.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DecalLookup.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_DecalLookup.m_Memory.m_pMemory = nullptr;
    }
    g_DecalLookup.m_Memory.m_nAllocationCount = 0;
  }
  g_DecalLookup.m_pElements = m_pMemory;
  CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_DecalDictionary.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B7FF0
// Name: void Decal_Init(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl Decal_Init()
{
  Decal_Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x100B8080
// Name: void Draw_DecalSetName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Draw_DecalSetName(int decal, char *name)
{
  int i; // eax
  int v3; // esi
  int *m_pMemory; // ecx
  int v5; // eax
  void *v6; // esi
  unsigned __int16 v7; // ax
  IMaterial *Material; // eax
  CUtlMap<void *,DecalEntry,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF

  for ( i = g_DecalLookup.m_Size; decal >= g_DecalLookup.m_Size; i = g_DecalLookup.m_Size )
  {
    v3 = i;
    if ( i + 1 > g_DecalLookup.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_DecalLookup,
        num: i - g_DecalLookup.m_Memory.m_nAllocationCount + 1);
      i = g_DecalLookup.m_Size;
    }
    m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
    g_DecalLookup.m_Size = i + 1;
    v5 = i - v3;
    g_DecalLookup.m_pElements = g_DecalLookup.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &g_DecalLookup.m_Memory.m_pMemory[v3 + 1],
        src: &g_DecalLookup.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
    }
    m_pMemory[v3] = 0xFFFF;
  }
  v6 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: name);
  search.key = v6;
  v7 = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_DecalDictionary.m_Tree,
         &search);
  if ( v7 == 0xFFFF )
  {
    Material = GL_LoadMaterial(pName: name, pTextureGroupName: "Decal textures", bPrecache: true);
    search.key = v6;
    search.elem.material = Material;
    search.elem.index = decal;
    g_DecalLookup.m_Memory.m_pMemory[decal] = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                                                this: &g_DecalDictionary.m_Tree,
                                                insert: &search);
  }
  else
  {
    g_DecalDictionary.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.index = decal;
    g_DecalLookup.m_Memory.m_pMemory[decal] = v7;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B69F0
// Name: int Draw_DecalMax(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Draw_DecalMax()
{
  return g_nMaxDecals;
}

//------------------------------------------------------------------------------
// Address: 0x100B6FE0
// Name: class IMaterial __near * Draw_DecalMaterial(int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl Draw_DecalMaterial(int index)
{
  int v1; // eax
  DecalEntry *p_elem; // eax

  if ( index >= 0
    && index < g_DecalLookup.m_Size
    && (v1 = g_DecalLookup.m_Memory.m_pMemory[index]) >= 0
    && v1 < LOWORD(g_DecalDictionary.m_Tree.m_Elements.m_nAllocationCount)
    && (p_elem = &g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1].m_Data.elem) != nullptr )
  {
    return p_elem->material;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7030
// Name: char const __near * Draw_DecalNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Draw_DecalNameFromIndex(unsigned __int16 index)
{
  IMaterial *material; // ecx

  material = g_DecalDictionary.m_Tree.m_Elements.m_pMemory[index].m_Data.elem.material;
  if ( material != nullptr )
    return material->GetName(this: material);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x100B7B90
// Name: int Draw_DecalIndexFromName(char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Draw_DecalIndexFromName(char *name, bool *found)
{
  unsigned __int16 v2; // ax
  CUtlMap<void *,DecalEntry,unsigned short>::Node_t search; // [esp+0h] [ebp-Ch] BYREF

  search.key = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: name);
  v2 = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_DecalDictionary.m_Tree,
         &search);
  if ( v2 == 0xFFFF )
  {
    if ( found != nullptr )
      *found = false;
    return 0;
  }
  else
  {
    if ( found != nullptr )
      *found = true;
    return g_DecalDictionary.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem.index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7BF0
// Name: void Decal_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Decal_Shutdown()
{
  int i; // esi
  int *m_pMemory; // eax

  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_DecalDictionary.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &g_DecalDictionary.m_Tree,
                                i) )
  {
    if ( g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.material != nullptr )
      GL_UnloadMaterial(pMaterial: g_DecalDictionary.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.material);
  }
  m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
  g_DecalLookup.m_Size = 0;
  if ( g_DecalLookup.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DecalLookup.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DecalLookup.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_DecalLookup.m_Memory.m_pMemory = nullptr;
    }
    g_DecalLookup.m_Memory.m_nAllocationCount = 0;
  }
  g_DecalLookup.m_pElements = m_pMemory;
  CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_DecalDictionary.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B7C90
// Name: void Decal_Init(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl Decal_Init()
{
  Decal_Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x100B7D20
// Name: void Draw_DecalSetName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Draw_DecalSetName(int decal, char *name)
{
  int i; // eax
  int v3; // esi
  int *m_pMemory; // ecx
  int v5; // eax
  void *v6; // esi
  unsigned __int16 v7; // ax
  IMaterial *Material; // eax
  CUtlMap<void *,DecalEntry,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF

  for ( i = g_DecalLookup.m_Size; decal >= g_DecalLookup.m_Size; i = g_DecalLookup.m_Size )
  {
    v3 = i;
    if ( i + 1 > g_DecalLookup.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_DecalLookup,
        num: i - g_DecalLookup.m_Memory.m_nAllocationCount + 1);
      i = g_DecalLookup.m_Size;
    }
    m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
    g_DecalLookup.m_Size = i + 1;
    v5 = i - v3;
    g_DecalLookup.m_pElements = g_DecalLookup.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &g_DecalLookup.m_Memory.m_pMemory[v3 + 1],
        src: &g_DecalLookup.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = g_DecalLookup.m_Memory.m_pMemory;
    }
    m_pMemory[v3] = 0xFFFF;
  }
  v6 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: name);
  search.key = v6;
  v7 = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_DecalDictionary.m_Tree,
         &search);
  if ( v7 == 0xFFFF )
  {
    Material = GL_LoadMaterial(pName: name, pTextureGroupName: "Decal textures", bPrecache: true);
    search.key = v6;
    search.elem.material = Material;
    search.elem.index = decal;
    g_DecalLookup.m_Memory.m_pMemory[decal] = CUtlRBTree<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short,CUtlMap<void *,DecalEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,DecalEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                                                this: &g_DecalDictionary.m_Tree,
                                                insert: &search);
  }
  else
  {
    g_DecalDictionary.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.index = decal;
    g_DecalLookup.m_Memory.m_pMemory[decal] = v7;
  }
}

} // namespace engine_xlsp
