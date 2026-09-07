// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_horizontalslice.cpp
// Functions: 4
// ============================================================

#include "fow\fow_horizontalslice.h"

//------------------------------------------------------------------------------
// Address: 0x101FBBA0
// Name: public: void CFoW_HorizontalSlice::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_HorizontalSlice::Clear(CFoW_HorizontalSlice *this)
{
  CUtlSphereTree::Node *m_pMemory; // ecx

  this->m_SphereTree.m_FreelistHead = -1;
  this->m_SphereTree.m_NumNodesInTree = 0;
  this->m_SphereTree.m_PrevInsertedNode = -1;
  this->m_SphereTree.m_Nodes.m_Size = 0;
  if ( this->m_SphereTree.m_Nodes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_SphereTree.m_Nodes.m_pElements = this->m_SphereTree.m_Nodes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_SphereTree.m_Nodes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SphereTree.m_Nodes.m_Memory.m_pMemory);
      this->m_SphereTree.m_Nodes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_SphereTree.m_Nodes.m_Memory.m_pMemory;
    this->m_SphereTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
    this->m_SphereTree.m_Nodes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBBF0
// Name: public: CFoW_HorizontalSlice::CFoW_HorizontalSlice(void)
// Source: json
//------------------------------------------------------------------------------
CFoW_HorizontalSlice *__thiscall CFoW_HorizontalSlice::CFoW_HorizontalSlice(CFoW_HorizontalSlice *this)
{
  this->m_SphereTree.__vftable = (CUtlSphereTree_vtbl *)&CUtlSphereTree::`vftable';
  this->m_SphereTree.m_Nodes.m_Memory.m_pMemory = nullptr;
  this->m_SphereTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
  this->m_SphereTree.m_Nodes.m_Memory.m_nGrowSize = 0;
  this->m_SphereTree.m_Nodes.m_pElements = nullptr;
  this->m_SphereTree.m_FreelistHead = -1;
  this->m_SphereTree.m_NumNodesInTree = 0;
  this->m_SphereTree.m_PrevInsertedNode = -1;
  this->m_SphereTree.m_Nodes.m_Size = 0;
  if ( this->m_SphereTree.m_Nodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SphereTree.m_Nodes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SphereTree.m_Nodes.m_Memory.m_pMemory);
      this->m_SphereTree.m_Nodes.m_Memory.m_pMemory = nullptr;
    }
    this->m_SphereTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SphereTree.m_Nodes.m_pElements = this->m_SphereTree.m_Nodes.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FBC50
// Name: public: void CFoW_HorizontalSlice::AddHorizontalOccluder(class CFoW_LineOccluder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_HorizontalSlice::AddHorizontalOccluder(
        CFoW_HorizontalSlice *this,
        CFoW_LineOccluder *pLineOccluder)
{
  float x; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  Vector4D bounds; // [esp+0h] [ebp-10h] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  x = pLineOccluder->m_vEnd.x;
  v3 = (float)(x + pLineOccluder->m_vStart.x) * 0.5;
  v4 = x - pLineOccluder->m_vStart.x;
  v5 = pLineOccluder->m_vEnd.y - pLineOccluder->m_vStart.y;
  v6 = (float)(pLineOccluder->m_vEnd.y + pLineOccluder->m_vStart.y) * 0.5;
  bounds.x = v3;
  bounds.z = 0.0;
  bounds.y = v6;
  bounds.w = fsqrt((float)(v5 * v5) + (float)(v4 * v4));
  CUtlSphereTree::Insert(this: &this->m_SphereTree, a2: (int)&savedregs, pData: pLineOccluder, (const Vector *)&bounds);
}

//------------------------------------------------------------------------------
// Address: 0x101FBCD0
// Name: public: void CFoW_HorizontalSlice::ObstructViewer(class CFoW __near *,class CFoW_Viewer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_HorizontalSlice::ObstructViewer(CFoW_HorizontalSlice *this, CFoW *pFoW, CFoW_Viewer *pViewer)
{
  int v3; // esi
  float y; // xmm0_4
  void **m_pMemory; // eax
  CFoW_LineOccluder *FixedPointerArray[400]; // [esp+8h] [ebp-664h] BYREF
  Vector4D TestSphere; // [esp+648h] [ebp-24h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > FoundOccluders; // [esp+658h] [ebp-14h] BYREF

  v3 = 0;
  TestSphere.x = pViewer->m_vLocation.x;
  y = pViewer->m_vLocation.y;
  FoundOccluders.m_Memory.m_pMemory = (void **)FixedPointerArray;
  TestSphere.y = y;
  FoundOccluders.m_pElements = (void **)FixedPointerArray;
  TestSphere.z = 0.0;
  TestSphere.w = pViewer->m_flRadius;
  FoundOccluders.m_Memory.m_nAllocationCount = 400;
  FoundOccluders.m_Memory.m_nGrowSize = -1;
  FoundOccluders.m_Size = 0;
  CUtlSphereTree::IntersectWithSphere(
    this: &this->m_SphereTree,
    sphere: &TestSphere,
    bPartial: true,
    result: &FoundOccluders,
    maxResults: 400,
    cut: nullptr);
  if ( FoundOccluders.m_Size > 0 )
  {
    do
      CFoW_LineOccluder::ObstructViewer(this: FixedPointerArray[v3++], pFoW, pViewer);
    while ( v3 < FoundOccluders.m_Size );
  }
  m_pMemory = FoundOccluders.m_Memory.m_pMemory;
  FoundOccluders.m_Size = 0;
  if ( FoundOccluders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( FoundOccluders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: FoundOccluders.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      FoundOccluders.m_Memory.m_pMemory = nullptr;
    }
    FoundOccluders.m_Memory.m_nAllocationCount = 0;
  }
  FoundOccluders.m_pElements = m_pMemory;
  if ( FoundOccluders.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}
