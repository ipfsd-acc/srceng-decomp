// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/physicsbuild.cpp
// Functions: 26
// ============================================================

#include "vbsp2lib\physicsbuild.h"

//------------------------------------------------------------------------------
// Address: 0x10077B10
// Name: LoadSurfacePropFile
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfacePropFile(
        IBaseFileSystem *pFileSystem@<esi>,
        int a2@<ebx>,
        const char *pMaterialFilename,
        IPhysicsSurfaceProps *pPhysicsProperties)
{
  void *v4; // edi
  void *v5; // ebx
  int len; // [esp+4h] [ebp-4h]

  v4 = pFileSystem->Open(this: pFileSystem, a2: pMaterialFilename, a3: "rb", a4: 0);
  if ( v4 != nullptr )
  {
    len = ((int (__thiscall *)(IBaseFileSystem *, void *, int))pFileSystem->Size_2)(a1: pFileSystem, a2: v4, a3: a2);
    v5 = operator new(nSize: len);
    pFileSystem->Read(this: pFileSystem, a2: v5, a3: len, a4: v4);
    pFileSystem->Close(this: pFileSystem, a2: v4);
    pPhysicsProperties->ParseSurfaceData(this: pPhysicsProperties, a2: pMaterialFilename, a3: (const char *)v5);
    free(pMem: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077B80
// Name: public: void CPhysCollisionEntry::Cleanup(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntry::Cleanup(CPhysCollisionEntry *this, IPhysicsCollision *pPhysicsCollision)
{
  pPhysicsCollision->DestroyCollide(this: pPhysicsCollision, a2: this->m_pCollide);
  this->m_pCollide = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10077BA0
// Name: public: unsigned int CPhysCollisionEntry::GetCollisionBinarySize(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollisionEntry::GetCollisionBinarySize(
        CPhysCollisionEntry *this,
        IPhysicsCollision *pPhysicsCollision)
{
  return pPhysicsCollision->CollideSize(this: pPhysicsCollision, a2: this->m_pCollide);
}

//------------------------------------------------------------------------------
// Address: 0x10077BC0
// Name: public: unsigned int CPhysCollisionEntry::WriteCollisionBinary(class IPhysicsCollision __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollisionEntry::WriteCollisionBinary(
        CPhysCollisionEntry *this,
        IPhysicsCollision *pPhysicsCollision,
        unsigned __int8 *pDest)
{
  return pPhysicsCollision->CollideWrite(this: pPhysicsCollision, a2: (char *)pDest, a3: this->m_pCollide, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10077BE0
// Name: public: CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(class CPhysCollide __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryStaticSolid *__thiscall CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(
        CPhysCollisionEntryStaticSolid *this,
        struct CPhysCollide *pCollide,
        int contentsMask)
{
  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntryStaticSolid_vtbl *)&CPhysCollisionEntryStaticSolid::`vftable';
  this->m_ContentsMask = contentsMask;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077C00
// Name: public: CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(class CPhysCollide __near *,char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntrySolid *__thiscall CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(
        CPhysCollisionEntrySolid *this,
        struct CPhysCollide *pCollide,
        const char *pMaterialName,
        float flMass,
        float flVolume)
{
  this->m_flMass = flMass;
  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntrySolid_vtbl *)&CPhysCollisionEntrySolid::`vftable';
  this->m_pMaterialName = pMaterialName;
  this->m_flVolume = flVolume;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077C60
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetTrianglesInSphere(void __near *,class Vector const __near &,float,struct virtualmeshtrianglelist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetTrianglesInSphere(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        const Vector *center,
        float radius,
        virtualmeshtrianglelist_t *pList)
{
  int m_nIndexCount; // eax

  pList->triangleCount = this->m_nIndexCount / 3;
  m_nIndexCount = 3072;
  if ( this->m_nIndexCount < 3072 )
    m_nIndexCount = this->m_nIndexCount;
  _V_memcpy(
    dest: (unsigned __int8 *)pList->triangleIndices,
    src: (unsigned __int8 *)this->m_pIndices,
    count: 2 * m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x10077CA0
// Name: void LoadSurfaceProperties(class IBaseFileSystem __near *,class IPhysicsSurfaceProps __near *,class CSimpleMapFile const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadSurfaceProperties(
        IBaseFileSystem *pFileSystem,
        IPhysicsSurfaceProps *pPhysicsProperties,
        const CSimpleMapFile *pMapFile,
        int *pSurfacePropertyList)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  KeyValues *j; // edi
  const char *Name; // eax
  char *String; // eax
  const CSimpleMapFile *v9; // ecx
  IMaterial *Material; // eax
  int v11; // esi
  const char *MaterialVar; // ebx
  int i; // [esp+0h] [ebp-10h]
  KeyValues *pManifest; // [esp+4h] [ebp-Ch]
  int v15; // [esp+8h] [ebp-8h]
  bool found; // [esp+Fh] [ebp-1h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    pManifest = KeyValues::KeyValues(this: v4, setName: "scripts/surfaceproperties_manifest.txt");
  else
    pManifest = nullptr;
  v5 = pManifest;
  if ( KeyValues::LoadFromFile(
         this: pManifest,
         filesystem: pFileSystem,
         resourceName: "scripts/surfaceproperties_manifest.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( j = KeyValues::GetFirstSubKey(this: pManifest); j != nullptr; j = KeyValues::GetNextKey(this: j) )
    {
      Name = KeyValues::GetName(this: j);
      if ( _V_stricmp(s1: Name, s2: "file") == 0 )
      {
        String = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: szDescription);
        LoadSurfacePropFile(pFileSystem, a2: (int)pManifest, pMaterialFilename: String, pPhysicsProperties);
      }
    }
  }
  v9 = pMapFile;
  i = 0;
  if ( pMapFile->m_TextureData.m_Size > 0 )
  {
    v15 = 0;
    do
    {
      Material = FindMaterial(
                   materialName: v9->m_TextureData.m_Memory.m_pMemory[v15].m_MaterialName,
                   pFound: &found,
                   bComplain: true);
      v11 = -1;
      if ( Material != nullptr && found )
      {
        MaterialVar = GetMaterialVar(materialHandle: Material, propertyName: "$surfaceprop");
        if ( MaterialVar != nullptr )
        {
          v11 = pPhysicsProperties->GetSurfaceIndex(this: pPhysicsProperties, a2: MaterialVar);
          if ( v11 < 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
              _LoggingSystem_Log(
                a1: LOG_VBSP2,
                a2: 1,
                a3: "Can't find surfaceprop %s for material %s, using default.\n");
            v11 = pPhysicsProperties->GetSurfaceIndex(this: pPhysicsProperties, a2: "default");
          }
        }
      }
      ++v15;
      pSurfacePropertyList[i] = v11;
      v9 = pMapFile;
      ++i;
    }
    while ( i < pMapFile->m_TextureData.m_Size );
    v5 = pManifest;
  }
  KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10077E30
// Name: public: int CPhysConvexBuilder::FindFirstReferencedBrush(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysConvexBuilder::FindFirstReferencedBrush(CPhysConvexBuilder *this)
{
  int m_Size; // esi
  int result; // eax

  m_Size = this->pMapFile->m_Brushes.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( ((1 << (result & 0x1F)) & this->m_IsBrushReferenced.m_Ints[result >> 5]) == 0 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077E70
// Name: private: void CPhysConvexBuilder::VisitLeaves(int,class CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>> const __near &,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::VisitLeaves(
        CPhysConvexBuilder *this,
        int nNodeIndex,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *nodeList,
        const CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *leafList,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafBrushList)
{
  int i; // esi
  dnode_t *v7; // esi
  int v8; // esi
  dleaf_t *v9; // eax
  int v10; // edx
  int v11; // ecx

  for ( i = nNodeIndex; i >= 0; i = v7->children[1] )
  {
    v7 = &nodeList->m_Memory.m_pMemory[i];
    CPhysConvexBuilder::VisitLeaves(this, nNodeIndex: v7->children[0], nodeList, leafList, leafBrushList);
  }
  v8 = -1 - i;
  v9 = &leafList->m_Memory.m_pMemory[v8];
  v10 = 0;
  if ( v9->numleafbrushes != 0 )
  {
    do
    {
      v11 = leafBrushList->m_Memory.m_pMemory[v10 + v9->firstleafbrush];
      if ( (this->pMapFile->m_Brushes.m_Memory.m_pMemory[v11].m_ContentsFlags & this->m_ContentsMask) != 0 )
        this->m_IsBrushReferenced.m_Ints[v11 >> 5] |= 1 << (v11 & 0x1F);
      v9 = &leafList->m_Memory.m_pMemory[v8];
      ++v10;
    }
    while ( v10 < v9->numleafbrushes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077F20
// Name: private: class CPhysConvex __near * CPhysConvexBuilder::BuildConvexForBrush(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
struct CPhysConvex *__thiscall CPhysConvexBuilder::BuildConvexForBrush(CPhysConvexBuilder *this, int nBrushIndex)
{
  int v2; // edx
  MapBrush_t *v3; // edi
  float m_flShrink; // xmm0_4
  const CSimpleMapFile *pMapFile; // ebx
  char *v6; // esi
  int m_nPlaneIndex; // eax
  int v8; // ecx
  HashedPlane_t *m_pMemory; // eax
  float x; // xmm1_4
  HashedPlane_t *v11; // eax
  char v13[4]; // [esp+Ch] [ebp-418h] BYREF
  _BYTE tempPlanes_1020[20]; // [esp+40Ch] [ebp-18h] OVERLAPPED
  int v15; // [esp+420h] [ebp-4h]

  v2 = 0;
  v3 = &this->pMapFile->m_Brushes.m_Memory.m_pMemory[nBrushIndex];
  *(_DWORD *)&tempPlanes_1020[16] = this;
  v15 = 0;
  if ( v3->m_nNumSides > 0 )
  {
    m_flShrink = this->m_flShrink;
    pMapFile = this->pMapFile;
    v6 = v13;
    do
    {
      m_nPlaneIndex = pMapFile->m_BrushSides.m_Memory.m_pMemory[v2 + v3->m_nFirstSideIndex].m_nPlaneIndex;
      ++v15;
      v8 = m_nPlaneIndex;
      m_pMemory = pMapFile->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      x = m_pMemory[v8].m_vNormal.x;
      v11 = &m_pMemory[v8];
      *(float *)tempPlanes_1020 = x;
      *(float *)&tempPlanes_1020[4] = v11->m_vNormal.y;
      *(float *)&tempPlanes_1020[8] = v11->m_vNormal.z;
      *(float *)&tempPlanes_1020[12] = v11->m_flDistance - m_flShrink;
      *(_QWORD *)v6 = *(_QWORD *)tempPlanes_1020;
      *((_QWORD *)v6 + 1) = *(_QWORD *)&tempPlanes_1020[8];
      ++v2;
      v6 += 16;
    }
    while ( v2 < v3->m_nNumSides );
    this = *(CPhysConvexBuilder **)&tempPlanes_1020[16];
  }
  return ((struct CPhysConvex *(__stdcall *)(char *, int, int))this->m_pPhysicsCollision->ConvexFromPlanes)(
           a1: v13,
           a2: v15,
           a3: 1008981770);
}

//------------------------------------------------------------------------------
// Address: 0x10078000
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetVirtualMesh(void __near *,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetVirtualMesh(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        virtualmeshlist_t *pList)
{
  int m_Size; // edx
  int m_nIndexCount; // eax

  pList->pVerts = this->m_Vertices.m_Memory.m_pMemory;
  pList->indexCount = this->m_nIndexCount;
  pList->triangleCount = this->m_nIndexCount / 3;
  m_Size = this->m_Vertices.m_Size;
  pList->surfacePropsIndex = 0;
  pList->pHull = nullptr;
  m_nIndexCount = 3072;
  pList->vertexCount = m_Size;
  if ( this->m_nIndexCount < 3072 )
    m_nIndexCount = this->m_nIndexCount;
  _V_memcpy(dest: (unsigned __int8 *)pList->indices, src: (unsigned __int8 *)this->m_pIndices, count: 2 * m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x10078060
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetWorldspaceBounds(void __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetWorldspaceBounds(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        Vector *pMins,
        Vector *pMaxs)
{
  int v5; // edi
  int v6; // ebx

  ClearBounds(mins: pMins, maxs: pMaxs);
  v5 = 0;
  if ( this->m_Vertices.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      AddPointToBounds(v: &this->m_Vertices.m_Memory.m_pMemory[v6], mins: pMins, maxs: pMaxs);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_Vertices.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100780B0
// Name: public: CPhysConvexBuilder::CPhysConvexBuilder(float,int,class CSimpleMapFile const __near *,class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysConvexBuilder *__thiscall CPhysConvexBuilder::CPhysConvexBuilder(
        CPhysConvexBuilder *this,
        float flShrink,
        int contentsMask,
        const CSimpleMapFile *pMapFile,
        IPhysicsCollision *pPhysicsCollision)
{
  this->m_ContentsMask = contentsMask;
  this->m_flShrink = flShrink;
  this->m_Convexes.m_Memory.m_pMemory = nullptr;
  this->m_Convexes.m_Memory.m_nAllocationCount = 0;
  this->m_Convexes.m_Memory.m_nGrowSize = 0;
  this->m_Convexes.m_Size = 0;
  this->m_Convexes.m_pElements = nullptr;
  this->m_flTotalVolume = 0.0;
  if ( this != (CPhysConvexBuilder *)-32 )
    memset(dst: (unsigned __int8 *)&this->m_IsBrushReferenced, value: 0, count: sizeof(this->m_IsBrushReferenced));
  this->pMapFile = pMapFile;
  this->m_pPhysicsCollision = pPhysicsCollision;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078110
// Name: private: void CPhysConvexBuilder::AddBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::AddBrushes(CPhysConvexBuilder *this)
{
  int i; // ebx
  struct CPhysConvex *v3; // edi
  double v4; // st7
  int m_Size; // edi
  int m_nAllocationCount; // eax
  struct CPhysConvex **m_pMemory; // ecx
  int v8; // eax
  struct CPhysConvex **v9; // edi
  struct CPhysConvex *pBrushConvex; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->pMapFile->m_Brushes.m_Size; ++i )
  {
    if ( ((1 << (i & 0x1F)) & this->m_IsBrushReferenced.m_Ints[i >> 5]) != 0 )
    {
      v3 = CPhysConvexBuilder::BuildConvexForBrush(this, nBrushIndex: i);
      pBrushConvex = v3;
      if ( v3 != nullptr )
      {
        this->m_pPhysicsCollision->SetConvexGameData(this: this->m_pPhysicsCollision, a2: v3, a3: i);
        v4 = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))this->m_pPhysicsCollision->ConvexVolume)(
               a1: this->m_pPhysicsCollision,
               a2: v3);
        m_Size = this->m_Convexes.m_Size;
        m_nAllocationCount = this->m_Convexes.m_Memory.m_nAllocationCount;
        this->m_flTotalVolume = v4 + this->m_flTotalVolume;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            (CUtlMemory<vgui::TreeNode *,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Convexes.m_Size;
        m_pMemory = this->m_Convexes.m_Memory.m_pMemory;
        v8 = this->m_Convexes.m_Size - m_Size - 1;
        this->m_Convexes.m_pElements = this->m_Convexes.m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v8);
        v9 = &this->m_Convexes.m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = pBrushConvex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100781F0
// Name: private: void CTextBuffer::CopyData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyData(CTextBuffer *this, char *pData, int nLength)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax

  m_Size = this->m_Buffer.m_Size;
  if ( nLength != 0 )
  {
    m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
    if ( m_Size + nLength > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: nLength + m_Size - m_nAllocationCount);
    this->m_Buffer.m_Size += nLength;
    m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
    v7 = this->m_Buffer.m_Size - m_Size - nLength;
    this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
    if ( v7 > 0 && nLength > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + nLength],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: v7);
  }
  _V_memcpy(
    dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[m_Size],
    src: (unsigned __int8 *)pData,
    count: nLength);
}

//------------------------------------------------------------------------------
// Address: 0x10078260
// Name: public: CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(unsigned short __near *,int,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleBSPDisplacementMeshEvent *__thiscall CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(
        CSimpleBSPDisplacementMeshEvent *this,
        unsigned __int16 *pIndices,
        int nIndexCount,
        CCoreDispInfo *pDispInfo)
{
  int v5; // eax
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_Vertices; // esi
  int v7; // ecx
  unsigned __int16 *v8; // edx
  unsigned __int16 v9; // ax
  int v10; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  float *p_z; // eax
  unsigned int v17; // ebx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v21; // ecx
  int v22; // edx
  float *v23; // ecx
  int v24; // ebx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // eax
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]
  int nCount; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  p_m_Vertices = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_Vertices;
  this->__vftable = (CSimpleBSPDisplacementMeshEvent_vtbl *)&CSimpleBSPDisplacementMeshEvent::`vftable';
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_Size = 0;
  this->m_Vertices.m_pElements = nullptr;
  this->m_pIndices = pIndices;
  this->m_nIndexCount = nIndexCount;
  for ( i = 0; v5 < nIndexCount; ++v5 )
  {
    if ( pIndices[v5] > i )
      i = pIndices[v5];
  }
  v7 = 0;
  if ( nIndexCount / 2 > 0 )
  {
    v8 = &pIndices[nIndexCount - 1];
    do
    {
      v9 = pIndices[v7];
      pIndices[v7] = *v8;
      *v8 = v9;
      ++v7;
      --v8;
    }
    while ( v7 < nIndexCount / 2 );
  }
  v10 = i + 1;
  nCount = i + 1;
  p_m_Vertices[1].m_pMemory = nullptr;
  m_nAllocationCount = p_m_Vertices->m_nAllocationCount;
  if ( v10 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_Vertices, num: v10 - m_nAllocationCount);
  p_m_Vertices[1].m_pMemory = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)((char *)p_m_Vertices[1].m_pMemory + v10);
  m_pMemory = (unsigned __int8 *)p_m_Vertices->m_pMemory;
  v13 = (int)p_m_Vertices[1].m_pMemory - v10;
  p_m_Vertices[1].m_nAllocationCount = (int)p_m_Vertices->m_pMemory;
  if ( v13 > 0 && v10 > 0 )
    _V_memmove(dest: &m_pMemory[12 * v10], src: m_pMemory, count: 12 * v13);
  v14 = 0;
  if ( v10 >= 4 )
  {
    v15 = 0;
    p_z = &pDispInfo->m_pVerts->m_Vert.z;
    v17 = ((unsigned int)(i - 3) >> 2) + 1;
    ia = 4 * v17;
    do
    {
      v18 = p_m_Vertices->m_pMemory;
      v18[v15].m_Element = *(vgui::TreeNode **)(p_z - 2);
      p_z += 224;
      v18[v15].m_Previous = *(int *)(p_z - 225);
      v18[v15].m_Next = *(int *)(p_z - 224);
      v19 = (float *)&p_m_Vertices->m_pMemory[v15 + 1];
      *v19 = *(p_z - 170);
      v19[1] = *(p_z - 169);
      v19[2] = *(p_z - 168);
      v20 = (float *)&p_m_Vertices->m_pMemory[v15 + 2];
      *v20 = *(p_z - 114);
      v15 += 4;
      --v17;
      v20[1] = *(p_z - 113);
      v20[2] = *(p_z - 112);
      v21 = p_m_Vertices->m_pMemory;
      v21[v15 - 1].m_Element = *(vgui::TreeNode **)(p_z - 58);
      v21[v15 - 1].m_Previous = *(int *)(p_z - 57);
      v21[v15 - 1].m_Next = *(int *)(p_z - 56);
    }
    while ( v17 != 0 );
    v14 = ia;
    v10 = nCount;
  }
  if ( v14 < v10 )
  {
    v22 = v14;
    v23 = &pDispInfo->m_pVerts[v14].m_Vert.z;
    v24 = v10 - v14;
    do
    {
      v25 = p_m_Vertices->m_pMemory;
      v25[v22].m_Element = *(vgui::TreeNode **)(v23 - 2);
      v23 += 56;
      ++v22;
      --v24;
      v25[v22 - 1].m_Previous = *(int *)(v23 - 57);
      v25[v22 - 1].m_Next = *(int *)(v23 - 56);
    }
    while ( v24 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078440
// Name: public: void CPhysConvexBuilder::BuildConvexes(int,class CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>> const __near &,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::BuildConvexes(
        CPhysConvexBuilder *this,
        int nNodeIndex,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *nodeList,
        const CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *leafList,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafBrushList)
{
  CPhysConvexBuilder::VisitLeaves(this, nNodeIndex, nodeList, leafList, leafBrushList);
  CPhysConvexBuilder::AddBrushes(this);
}

//------------------------------------------------------------------------------
// Address: 0x10078470
// Name: public: void CTextBuffer::WriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteText(CTextBuffer *this, char *pText)
{
  CTextBuffer::CopyData(this, pData: pText, nLength: strlen(pText));
}

//------------------------------------------------------------------------------
// Address: 0x100784A0
// Name: public: void CTextBuffer::WriteIntKey(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteIntKey(CTextBuffer *this, const char *pKeyName, int nOutputData)
{
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( (int)_V_strlen(str: pKeyName) <= 1000 )
  {
    sprintf(string: tmp, format: "\"%s\" \"%d\"\n", pKeyName, nOutputData);
    CTextBuffer::CopyData(this, pData: tmp, nLength: strlen(tmp));
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error writing collision data %s.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078540
// Name: public: void CTextBuffer::WriteFloatKey(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteFloatKey(CTextBuffer *this, const char *pKeyName, float flOutputData)
{
  char string[8]; // [esp+10h] [ebp-400h] BYREF

  if ( (int)_V_strlen(str: pKeyName) <= 1000 )
  {
    sprintf(string, format: "\"%s\" \"%f\"\n", pKeyName, flOutputData);
    CTextBuffer::CopyData(this, pData: string, nLength: strlen(string));
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error writing collision data %s.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100785F0
// Name: public: void CTextBuffer::CopyStringQuotes(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyStringQuotes(CTextBuffer *this, char *pString)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  signed int v6; // eax
  unsigned int v7; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // ecx
  signed int v11; // eax

  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  m_Size = this->m_Buffer.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v6 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[m_Size + 1], src: (unsigned __int8 *)&m_pMemory[m_Size], count: v6);
  _V_memcpy(dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[m_Size], src: "\"", count: 1u);
  v7 = _V_strlen(str: pString);
  CTextBuffer::CopyData(this, pData: pString, nLength: v7);
  v8 = this->m_Buffer.m_Size;
  v9 = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v8 - v9 + 1);
  ++this->m_Buffer.m_Size;
  v10 = this->m_Buffer.m_Memory.m_pMemory;
  v11 = this->m_Buffer.m_Size - v8 - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[v8 + 1], src: (unsigned __int8 *)&v10[v8], count: v11);
  _V_memcpy(dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[v8], src: "\"", count: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100786B0
// Name: public: void CTextBuffer::Terminate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::Terminate(CTextBuffer *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  signed int v5; // eax

  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  m_Size = this->m_Buffer.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v5 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[m_Size + 1], src: (unsigned __int8 *)&m_pMemory[m_Size], count: v5);
  _V_memcpy(
    dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[m_Size],
    src: (unsigned __int8 *)&word_1010DB00,
    count: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10078710
// Name: public: virtual void CPhysCollisionEntryStaticSolid::WriteToTextBuffer(class CTextBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticSolid::WriteToTextBuffer(
        CPhysCollisionEntryStaticSolid *this,
        CTextBuffer *pTextBuffer,
        int nCollideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "staticsolid {\n", nLength: 14);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", nOutputData: nCollideIndex);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "contents", nOutputData: this->m_ContentsMask);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", nLength: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10078760
// Name: public: void CTextBuffer::WriteStringKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteStringKey(CTextBuffer *this, char *pKeyName, char *pOutputData)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // ecx
  signed int v11; // eax

  CTextBuffer::CopyStringQuotes(this, pString: pKeyName);
  m_Size = this->m_Buffer.m_Size;
  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v7 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[m_Size + 1], src: (unsigned __int8 *)&m_pMemory[m_Size], count: v7);
  _V_memcpy(dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[m_Size], src: " ", count: 1u);
  CTextBuffer::CopyStringQuotes(this, pString: pOutputData);
  v8 = this->m_Buffer.m_Size;
  v9 = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v8 - v9 + 1);
  ++this->m_Buffer.m_Size;
  v10 = this->m_Buffer.m_Memory.m_pMemory;
  v11 = this->m_Buffer.m_Size - v8 - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[v8 + 1], src: (unsigned __int8 *)&v10[v8], count: v11);
  _V_memcpy(dest: (unsigned __int8 *)&this->m_Buffer.m_Memory.m_pMemory[v8], src: "\n", count: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10078820
// Name: public: virtual void CPhysCollisionEntrySolid::WriteToTextBuffer(class CTextBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntrySolid::WriteToTextBuffer(
        CPhysCollisionEntrySolid *this,
        CTextBuffer *pTextBuffer,
        CTextBuffer *nCollideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "solid {\n", nLength: 8);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", nOutputData: (int)nCollideIndex);
  CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "mass", flOutputData: this->m_flMass);
  if ( this->m_pMaterialName != nullptr )
    CTextBuffer::WriteStringKey(this: pTextBuffer, pKeyName: "surfaceprop", pOutputData: (char *)this->m_pMaterialName);
  if ( this->m_flVolume != 0.0 )
    CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "volume", flOutputData: this->m_flVolume);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", nLength: 2);
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x0042B150
// Name: LoadSurfacePropFile
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfacePropFile(
        IBaseFileSystem *pFileSystem@<esi>,
        int a2@<ebx>,
        const char *pMaterialFilename,
        IPhysicsSurfaceProps *pPhysicsProperties)
{
  void *v4; // edi
  void *v5; // ebx
  int len; // [esp+4h] [ebp-4h]

  v4 = pFileSystem->Open(this: pFileSystem, a2: pMaterialFilename, a3: "rb", a4: 0);
  if ( v4 != nullptr )
  {
    len = ((int (__thiscall *)(IBaseFileSystem *, void *, int))pFileSystem->Size_2)(a1: pFileSystem, a2: v4, a3: a2);
    v5 = operator new(nSize: len);
    pFileSystem->Read(this: pFileSystem, a2: v5, a3: len, a4: v4);
    pFileSystem->Close(this: pFileSystem, a2: v4);
    pPhysicsProperties->ParseSurfaceData(this: pPhysicsProperties, a2: pMaterialFilename, a3: (const char *)v5);
    free(pMem: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B1C0
// Name: public: void CPhysCollisionEntry::Cleanup(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntry::Cleanup(CPhysCollisionEntry *this, IPhysicsCollision *pPhysicsCollision)
{
  pPhysicsCollision->DestroyCollide(this: pPhysicsCollision, a2: this->m_pCollide);
  this->m_pCollide = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042B1E0
// Name: public: unsigned int CPhysCollisionEntry::GetCollisionBinarySize(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollisionEntry::GetCollisionBinarySize(
        CPhysCollisionEntry *this,
        IPhysicsCollision *pPhysicsCollision)
{
  return pPhysicsCollision->CollideSize(this: pPhysicsCollision, a2: this->m_pCollide);
}

//------------------------------------------------------------------------------
// Address: 0x0042B200
// Name: public: unsigned int CPhysCollisionEntry::WriteCollisionBinary(class IPhysicsCollision __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollisionEntry::WriteCollisionBinary(
        CPhysCollisionEntry *this,
        IPhysicsCollision *pPhysicsCollision,
        unsigned __int8 *pDest)
{
  return pPhysicsCollision->CollideWrite(this: pPhysicsCollision, a2: (char *)pDest, a3: this->m_pCollide, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042B220
// Name: public: CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(class CPhysCollide __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryStaticSolid *__thiscall CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(
        CPhysCollisionEntryStaticSolid *this,
        struct CPhysCollide *pCollide,
        int contentsMask)
{
  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntryStaticSolid_vtbl *)&CPhysCollisionEntryStaticSolid::`vftable';
  this->m_ContentsMask = contentsMask;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B240
// Name: public: CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(class CPhysCollide __near *,char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntrySolid *__thiscall CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(
        CPhysCollisionEntrySolid *this,
        struct CPhysCollide *pCollide,
        const char *pMaterialName,
        float flMass,
        float flVolume)
{
  this->m_flMass = flMass;
  this->m_pCollide = pCollide;
  this->__vftable = (CPhysCollisionEntrySolid_vtbl *)&CPhysCollisionEntrySolid::`vftable';
  this->m_pMaterialName = pMaterialName;
  this->m_flVolume = flVolume;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B2A0
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetTrianglesInSphere(void __near *,class Vector const __near &,float,struct virtualmeshtrianglelist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetTrianglesInSphere(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        const Vector *center,
        float radius,
        virtualmeshtrianglelist_t *pList)
{
  int m_nIndexCount; // eax

  pList->triangleCount = this->m_nIndexCount / 3;
  m_nIndexCount = 3072;
  if ( this->m_nIndexCount < 3072 )
    m_nIndexCount = this->m_nIndexCount;
  _V_memcpy(dest: pList->triangleIndices, src: this->m_pIndices, count: 2 * m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x0042B2E0
// Name: void LoadSurfaceProperties(class IBaseFileSystem __near *,class IPhysicsSurfaceProps __near *,class CSimpleMapFile const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadSurfaceProperties(
        IBaseFileSystem *pFileSystem,
        IPhysicsSurfaceProps *pPhysicsProperties,
        const CSimpleMapFile *pMapFile,
        int *pSurfacePropertyList)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  KeyValues *j; // edi
  const char *Name; // eax
  const char *String; // eax
  const CSimpleMapFile *v9; // ecx
  const char *m_MaterialName; // edi
  void *Material; // eax
  int v12; // esi
  const char *MaterialVar; // ebx
  int i; // [esp+0h] [ebp-10h]
  KeyValues *pManifest; // [esp+4h] [ebp-Ch]
  int v16; // [esp+8h] [ebp-8h]
  bool found; // [esp+Fh] [ebp-1h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    pManifest = KeyValues::KeyValues(this: v4, setName: "scripts/surfaceproperties_manifest.txt");
  else
    pManifest = nullptr;
  v5 = pManifest;
  if ( KeyValues::LoadFromFile(
         this: pManifest,
         filesystem: pFileSystem,
         resourceName: "scripts/surfaceproperties_manifest.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( j = KeyValues::GetFirstSubKey(this: pManifest); j != nullptr; j = KeyValues::GetNextKey(this: j) )
    {
      Name = KeyValues::GetName(this: j);
      if ( _V_stricmp(s1: Name, s2: "file") == 0 )
      {
        String = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: defaultValue);
        LoadSurfacePropFile(pFileSystem, a2: (int)pManifest, pMaterialFilename: String, pPhysicsProperties);
      }
    }
  }
  v9 = pMapFile;
  i = 0;
  if ( pMapFile->m_TextureData.m_Size > 0 )
  {
    v16 = 0;
    do
    {
      m_MaterialName = v9->m_TextureData.m_Memory.m_pMemory[v16].m_MaterialName;
      Material = FindMaterial(materialName: m_MaterialName, pFound: &found, bComplain: true);
      v12 = -1;
      if ( Material != nullptr && found )
      {
        MaterialVar = GetMaterialVar(materialHandle: Material, propertyName: "$surfaceprop");
        if ( MaterialVar != nullptr )
        {
          v12 = pPhysicsProperties->GetSurfaceIndex(this: pPhysicsProperties, a2: MaterialVar);
          if ( v12 < 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2) != 0 )
              _LoggingSystem_Log(
                a1: LOG_VBSP2,
                a2: 1,
                a3: "Can't find surfaceprop %s for material %s, using default.\n",
                MaterialVar,
                m_MaterialName);
            v12 = pPhysicsProperties->GetSurfaceIndex(this: pPhysicsProperties, a2: "default");
          }
        }
      }
      ++v16;
      pSurfacePropertyList[i] = v12;
      v9 = pMapFile;
      ++i;
    }
    while ( i < pMapFile->m_TextureData.m_Size );
    v5 = pManifest;
  }
  KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0042B470
// Name: public: int CPhysConvexBuilder::FindFirstReferencedBrush(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysConvexBuilder::FindFirstReferencedBrush(CPhysConvexBuilder *this)
{
  int m_Size; // esi
  int result; // eax

  m_Size = this->pMapFile->m_Brushes.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( ((1 << (result & 0x1F)) & this->m_IsBrushReferenced.m_Ints[result >> 5]) == 0 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B4B0
// Name: private: void CPhysConvexBuilder::VisitLeaves(int,class CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>> const __near &,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::VisitLeaves(
        CPhysConvexBuilder *this,
        int nNodeIndex,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *nodeList,
        const CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *leafList,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafBrushList)
{
  int i; // esi
  dnode_t *v7; // esi
  int v8; // esi
  dleaf_t *v9; // eax
  int v10; // edx
  int v11; // ecx

  for ( i = nNodeIndex; i >= 0; i = v7->children[1] )
  {
    v7 = &nodeList->m_Memory.m_pMemory[i];
    CPhysConvexBuilder::VisitLeaves(this, nNodeIndex: v7->children[0], nodeList, leafList, leafBrushList);
  }
  v8 = -1 - i;
  v9 = &leafList->m_Memory.m_pMemory[v8];
  v10 = 0;
  if ( v9->numleafbrushes != 0 )
  {
    do
    {
      v11 = leafBrushList->m_Memory.m_pMemory[v10 + v9->firstleafbrush];
      if ( (this->pMapFile->m_Brushes.m_Memory.m_pMemory[v11].m_ContentsFlags & this->m_ContentsMask) != 0 )
        this->m_IsBrushReferenced.m_Ints[v11 >> 5] |= 1 << (v11 & 0x1F);
      v9 = &leafList->m_Memory.m_pMemory[v8];
      ++v10;
    }
    while ( v10 < v9->numleafbrushes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B560
// Name: private: class CPhysConvex __near * CPhysConvexBuilder::BuildConvexForBrush(int)
// Source: json
//------------------------------------------------------------------------------
struct CPhysConvex *__thiscall CPhysConvexBuilder::BuildConvexForBrush(CPhysConvexBuilder *this, int nBrushIndex)
{
  int v2; // edx
  MapBrush_t *v3; // edi
  float m_flShrink; // xmm0_4
  const CSimpleMapFile *pMapFile; // ebx
  CPhysConvexBuilder::BuildConvexForBrush::__l2::ListPlane_t *v6; // esi
  int m_nPlaneIndex; // eax
  int v8; // ecx
  HashedPlane_t *m_pMemory; // eax
  float x; // xmm1_4
  float *p_x; // eax
  CPhysConvexBuilder::BuildConvexForBrush::__l2::ListPlane_t tempPlanes[64]; // [esp+Ch] [ebp-418h] BYREF
  CPhysConvexBuilder::BuildConvexForBrush::__l2::ListPlane_t shrunkPlane; // [esp+40Ch] [ebp-18h]
  CPhysConvexBuilder *v15; // [esp+41Ch] [ebp-8h]
  int nPlaneCount; // [esp+420h] [ebp-4h]

  v2 = 0;
  v3 = &this->pMapFile->m_Brushes.m_Memory.m_pMemory[nBrushIndex];
  v15 = this;
  nPlaneCount = 0;
  if ( v3->m_nNumSides > 0 )
  {
    m_flShrink = this->m_flShrink;
    pMapFile = this->pMapFile;
    v6 = tempPlanes;
    do
    {
      m_nPlaneIndex = pMapFile->m_BrushSides.m_Memory.m_pMemory[v2 + v3->m_nFirstSideIndex].m_nPlaneIndex;
      ++nPlaneCount;
      v8 = m_nPlaneIndex;
      m_pMemory = pMapFile->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      x = m_pMemory[v8].m_vNormal.x;
      p_x = &m_pMemory[v8].m_vNormal.x;
      shrunkPlane.flNormal[0] = x;
      shrunkPlane.flNormal[1] = p_x[1];
      shrunkPlane.flNormal[2] = p_x[2];
      shrunkPlane.flDistance = p_x[3] - m_flShrink;
      *v6 = shrunkPlane;
      ++v2;
      ++v6;
    }
    while ( v2 < v3->m_nNumSides );
    this = v15;
  }
  return ((struct CPhysConvex *(__stdcall *)(CPhysConvexBuilder::BuildConvexForBrush::__l2::ListPlane_t *, int, int))this->m_pPhysicsCollision->ConvexFromPlanes)(
           a1: tempPlanes,
           a2: nPlaneCount,
           a3: 1008981770);
}

//------------------------------------------------------------------------------
// Address: 0x0042B640
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetVirtualMesh(void __near *,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetVirtualMesh(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        virtualmeshlist_t *pList)
{
  int m_Size; // edx
  int m_nIndexCount; // eax

  pList->pVerts = this->m_Vertices.m_Memory.m_pMemory;
  pList->indexCount = this->m_nIndexCount;
  pList->triangleCount = this->m_nIndexCount / 3;
  m_Size = this->m_Vertices.m_Size;
  pList->surfacePropsIndex = 0;
  pList->pHull = nullptr;
  m_nIndexCount = 3072;
  pList->vertexCount = m_Size;
  if ( this->m_nIndexCount < 3072 )
    m_nIndexCount = this->m_nIndexCount;
  _V_memcpy(dest: pList->indices, src: this->m_pIndices, count: 2 * m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x0042B6A0
// Name: public: virtual void CSimpleBSPDisplacementMeshEvent::GetWorldspaceBounds(void __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPDisplacementMeshEvent::GetWorldspaceBounds(
        CSimpleBSPDisplacementMeshEvent *this,
        void *pUserData,
        Vector *pMins,
        Vector *pMaxs)
{
  int v5; // edi
  int v6; // ebx

  ClearBounds(mins: pMins, maxs: pMaxs);
  v5 = 0;
  if ( this->m_Vertices.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      AddPointToBounds(v: &this->m_Vertices.m_Memory.m_pMemory[v6], mins: pMins, maxs: pMaxs);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_Vertices.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B6F0
// Name: public: CPhysConvexBuilder::CPhysConvexBuilder(float,int,class CSimpleMapFile const __near *,class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysConvexBuilder *__thiscall CPhysConvexBuilder::CPhysConvexBuilder(
        CPhysConvexBuilder *this,
        float flShrink,
        int contentsMask,
        const CSimpleMapFile *pMapFile,
        IPhysicsCollision *pPhysicsCollision)
{
  this->m_ContentsMask = contentsMask;
  this->m_flShrink = flShrink;
  this->m_Convexes.m_Memory.m_pMemory = nullptr;
  this->m_Convexes.m_Memory.m_nAllocationCount = 0;
  this->m_Convexes.m_Memory.m_nGrowSize = 0;
  this->m_Convexes.m_Size = 0;
  this->m_Convexes.m_pElements = nullptr;
  this->m_flTotalVolume = 0.0;
  if ( this != (CPhysConvexBuilder *)-32 )
    memset(dst: (unsigned __int8 *)&this->m_IsBrushReferenced, value: 0, count: sizeof(this->m_IsBrushReferenced));
  this->pMapFile = pMapFile;
  this->m_pPhysicsCollision = pPhysicsCollision;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B750
// Name: private: void CPhysConvexBuilder::AddBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::AddBrushes(CPhysConvexBuilder *this)
{
  int i; // ebx
  struct CPhysConvex *v3; // edi
  double v4; // st7
  int m_Size; // edi
  int m_nAllocationCount; // eax
  struct CPhysConvex **m_pMemory; // ecx
  int v8; // eax
  struct CPhysConvex **v9; // edi
  struct CPhysConvex *pBrushConvex; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->pMapFile->m_Brushes.m_Size; ++i )
  {
    if ( ((1 << (i & 0x1F)) & this->m_IsBrushReferenced.m_Ints[i >> 5]) != 0 )
    {
      v3 = CPhysConvexBuilder::BuildConvexForBrush(this, nBrushIndex: i);
      pBrushConvex = v3;
      if ( v3 != nullptr )
      {
        this->m_pPhysicsCollision->SetConvexGameData(this: this->m_pPhysicsCollision, a2: v3, a3: i);
        v4 = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))this->m_pPhysicsCollision->ConvexVolume)(
               a1: this->m_pPhysicsCollision,
               a2: v3);
        m_Size = this->m_Convexes.m_Size;
        m_nAllocationCount = this->m_Convexes.m_Memory.m_nAllocationCount;
        this->m_flTotalVolume = v4 + this->m_flTotalVolume;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ColorRGBExp32,int>::Grow(
            (CUtlMemory<BSPCluster_t,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Convexes.m_Size;
        m_pMemory = this->m_Convexes.m_Memory.m_pMemory;
        v8 = this->m_Convexes.m_Size - m_Size - 1;
        this->m_Convexes.m_pElements = this->m_Convexes.m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &this->m_Convexes.m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = pBrushConvex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B830
// Name: private: void CTextBuffer::CopyData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyData(CTextBuffer *this, const char *pData, int nLength)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Buffer.m_Size;
  if ( nLength != 0 )
  {
    m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
    if ( m_Size + nLength > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: nLength + m_Size - m_nAllocationCount);
    this->m_Buffer.m_Size += nLength;
    m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
    v7 = this->m_Buffer.m_Size - m_Size - nLength;
    this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
    if ( v7 > 0 && nLength > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + nLength], src: &m_pMemory[m_Size], count: v7);
  }
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[m_Size], src: pData, count: nLength);
}

//------------------------------------------------------------------------------
// Address: 0x0042B8A0
// Name: public: CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(unsigned short __near *,int,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleBSPDisplacementMeshEvent *__thiscall CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(
        CSimpleBSPDisplacementMeshEvent *this,
        unsigned __int16 *pIndices,
        int nIndexCount,
        CCoreDispInfo *pDispInfo)
{
  int v5; // eax
  CUtlMemory<MapEntityKeyValuePair_t,int> *p_m_Vertices; // esi
  int v7; // ecx
  unsigned __int16 *v8; // edx
  unsigned __int16 v9; // ax
  int v10; // ebx
  int m_nAllocationCount; // eax
  MapEntityKeyValuePair_t *m_pMemory; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  float *p_z; // eax
  unsigned int v17; // ebx
  MapEntityKeyValuePair_t *v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  MapEntityKeyValuePair_t *v21; // ecx
  int v22; // edx
  float *v23; // ecx
  int v24; // ebx
  MapEntityKeyValuePair_t *v25; // eax
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]
  int nCount; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  p_m_Vertices = (CUtlMemory<MapEntityKeyValuePair_t,int> *)&this->m_Vertices;
  this->__vftable = (CSimpleBSPDisplacementMeshEvent_vtbl *)&CSimpleBSPDisplacementMeshEvent::`vftable';
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_Size = 0;
  this->m_Vertices.m_pElements = nullptr;
  this->m_pIndices = pIndices;
  this->m_nIndexCount = nIndexCount;
  for ( i = 0; v5 < nIndexCount; ++v5 )
  {
    if ( pIndices[v5] > i )
      i = pIndices[v5];
  }
  v7 = 0;
  if ( nIndexCount / 2 > 0 )
  {
    v8 = &pIndices[nIndexCount - 1];
    do
    {
      v9 = pIndices[v7];
      pIndices[v7] = *v8;
      *v8 = v9;
      ++v7;
      --v8;
    }
    while ( v7 < nIndexCount / 2 );
  }
  v10 = i + 1;
  nCount = i + 1;
  p_m_Vertices[1].m_pMemory = nullptr;
  m_nAllocationCount = p_m_Vertices->m_nAllocationCount;
  if ( v10 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(this: p_m_Vertices, num: v10 - m_nAllocationCount);
  p_m_Vertices[1].m_pMemory = (MapEntityKeyValuePair_t *)((char *)p_m_Vertices[1].m_pMemory + v10);
  m_pMemory = p_m_Vertices->m_pMemory;
  v13 = (int)p_m_Vertices[1].m_pMemory - v10;
  p_m_Vertices[1].m_nAllocationCount = (int)p_m_Vertices->m_pMemory;
  if ( v13 > 0 && v10 > 0 )
    _V_memmove(dest: &m_pMemory[v10], src: m_pMemory, count: 12 * v13);
  v14 = 0;
  if ( v10 >= 4 )
  {
    v15 = 0;
    p_z = &pDispInfo->m_pVerts->m_Vert.z;
    v17 = ((unsigned int)(i - 3) >> 2) + 1;
    ia = 4 * v17;
    do
    {
      v18 = p_m_Vertices->m_pMemory;
      v18[v15].m_pKey = *(const char **)(p_z - 2);
      p_z += 224;
      v18[v15].m_pValue = *(const char **)(p_z - 225);
      *(float *)&v18[v15].m_bIsConnection = *(p_z - 224);
      v19 = (float *)&p_m_Vertices->m_pMemory[v15 + 1];
      *v19 = *(p_z - 170);
      v19[1] = *(p_z - 169);
      v19[2] = *(p_z - 168);
      v20 = (float *)&p_m_Vertices->m_pMemory[v15 + 2];
      *v20 = *(p_z - 114);
      v15 += 4;
      --v17;
      v20[1] = *(p_z - 113);
      v20[2] = *(p_z - 112);
      v21 = p_m_Vertices->m_pMemory;
      v21[v15 - 1].m_pKey = *(const char **)(p_z - 58);
      v21[v15 - 1].m_pValue = *(const char **)(p_z - 57);
      *(float *)&v21[v15 - 1].m_bIsConnection = *(p_z - 56);
    }
    while ( v17 != 0 );
    v14 = ia;
    v10 = nCount;
  }
  if ( v14 < v10 )
  {
    v22 = v14;
    v23 = &pDispInfo->m_pVerts[v14].m_Vert.z;
    v24 = v10 - v14;
    do
    {
      v25 = p_m_Vertices->m_pMemory;
      v25[v22].m_pKey = *(const char **)(v23 - 2);
      v23 += 56;
      ++v22;
      --v24;
      v25[v22 - 1].m_pValue = *(const char **)(v23 - 57);
      *(float *)&v25[v22 - 1].m_bIsConnection = *(v23 - 56);
    }
    while ( v24 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042BA80
// Name: public: void CPhysConvexBuilder::BuildConvexes(int,class CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>> const __near &,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConvexBuilder::BuildConvexes(
        CPhysConvexBuilder *this,
        int nNodeIndex,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *nodeList,
        const CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *leafList,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafBrushList)
{
  CPhysConvexBuilder::VisitLeaves(this, nNodeIndex, nodeList, leafList, leafBrushList);
  CPhysConvexBuilder::AddBrushes(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042BAB0
// Name: public: void CTextBuffer::WriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteText(CTextBuffer *this, const char *pText)
{
  CTextBuffer::CopyData(this, pData: pText, nLength: strlen(pText));
}

//------------------------------------------------------------------------------
// Address: 0x0042BAE0
// Name: public: void CTextBuffer::WriteIntKey(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteIntKey(CTextBuffer *this, const char *pKeyName, int nOutputData)
{
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( _V_strlen(str: pKeyName) <= 1000 )
  {
    sprintf(string: tmp, format: "\"%s\" \"%d\"\n", pKeyName, nOutputData);
    CTextBuffer::CopyData(this, pData: tmp, nLength: strlen(tmp));
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error writing collision data %s.\n", pKeyName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BB80
// Name: public: void CTextBuffer::WriteFloatKey(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteFloatKey(CTextBuffer *this, const char *pKeyName, float flOutputData)
{
  char tmp[1024]; // [esp+10h] [ebp-400h] BYREF

  if ( _V_strlen(str: pKeyName) <= 1000 )
  {
    sprintf(string: tmp, format: "\"%s\" \"%f\"\n", pKeyName, flOutputData);
    CTextBuffer::CopyData(this, pData: tmp, nLength: strlen(tmp));
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error writing collision data %s.\n", pKeyName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BC30
// Name: public: void CTextBuffer::CopyStringQuotes(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyStringQuotes(CTextBuffer *this, const char *pString)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // ecx
  int v11; // eax

  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  m_Size = this->m_Buffer.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v6 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v6);
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[m_Size], src: "\"", count: 1);
  v7 = _V_strlen(str: pString);
  CTextBuffer::CopyData(this, pData: pString, nLength: v7);
  v8 = this->m_Buffer.m_Size;
  v9 = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v8 - v9 + 1);
  ++this->m_Buffer.m_Size;
  v10 = this->m_Buffer.m_Memory.m_pMemory;
  v11 = this->m_Buffer.m_Size - v8 - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: v11);
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[v8], src: "\"", count: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042BCF0
// Name: public: void CTextBuffer::Terminate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::Terminate(CTextBuffer *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  m_Size = this->m_Buffer.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v5 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v5);
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[m_Size], src: &unk_44EB08, count: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042BD50
// Name: public: virtual void CPhysCollisionEntryStaticSolid::WriteToTextBuffer(class CTextBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntryStaticSolid::WriteToTextBuffer(
        CPhysCollisionEntryStaticSolid *this,
        CTextBuffer *pTextBuffer,
        int nCollideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "staticsolid {\n", nLength: 14);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", nOutputData: nCollideIndex);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "contents", nOutputData: this->m_ContentsMask);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", nLength: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0042BDA0
// Name: public: void CTextBuffer::WriteStringKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::WriteStringKey(CTextBuffer *this, const char *pKeyName, const char *pOutputData)
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
  m_Size = this->m_Buffer.m_Size;
  m_nAllocationCount = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Buffer.m_Size;
  m_pMemory = this->m_Buffer.m_Memory.m_pMemory;
  v7 = this->m_Buffer.m_Size - m_Size - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[m_Size], src: " ", count: 1);
  CTextBuffer::CopyStringQuotes(this, pString: pOutputData);
  v8 = this->m_Buffer.m_Size;
  v9 = this->m_Buffer.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v8 - v9 + 1);
  ++this->m_Buffer.m_Size;
  v10 = this->m_Buffer.m_Memory.m_pMemory;
  v11 = this->m_Buffer.m_Size - v8 - 1;
  this->m_Buffer.m_pElements = this->m_Buffer.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: v11);
  _V_memcpy(dest: &this->m_Buffer.m_Memory.m_pMemory[v8], src: "\n", count: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042BE60
// Name: public: virtual void CPhysCollisionEntrySolid::WriteToTextBuffer(class CTextBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollisionEntrySolid::WriteToTextBuffer(
        CPhysCollisionEntrySolid *this,
        CTextBuffer *pTextBuffer,
        int nCollideIndex)
{
  CTextBuffer::CopyData(this: pTextBuffer, pData: "solid {\n", nLength: 8);
  CTextBuffer::WriteIntKey(this: pTextBuffer, pKeyName: "index", nOutputData: nCollideIndex);
  CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "mass", flOutputData: this->m_flMass);
  if ( this->m_pMaterialName != nullptr )
    CTextBuffer::WriteStringKey(this: pTextBuffer, pKeyName: "surfaceprop", pOutputData: this->m_pMaterialName);
  if ( this->m_flVolume != 0.0 )
    CTextBuffer::WriteFloatKey(this: pTextBuffer, pKeyName: "volume", flOutputData: this->m_flVolume);
  CTextBuffer::CopyData(this: pTextBuffer, pData: "}\n", nLength: 2);
}

} // namespace vbsp2
