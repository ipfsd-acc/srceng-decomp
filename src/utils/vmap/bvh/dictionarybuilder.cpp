// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/dictionarybuilder.cpp
// Functions: 11
// ============================================================

#include "utils\vmap\bvh\dictionarybuilder.h"

//------------------------------------------------------------------------------
// Address: 0x0040CAA0
// Name: public: void CResourceDictionaryBuilder::InitTextureData(struct InstanceGeometry_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceDictionaryBuilder::InitTextureData(
        CResourceDictionaryBuilder *this,
        InstanceGeometry_t *pInstanceGeometry)
{
  int m_nMeshes; // ebx
  int v4; // esi

  do
  {
    m_nMeshes = pInstanceGeometry->m_nMeshes;
    if ( pInstanceGeometry->m_nMeshes > 0 )
    {
      v4 = 0;
      do
      {
        CBuilderMesh::InitTextureData(this: &pInstanceGeometry->m_pMeshes[v4++]);
        --m_nMeshes;
      }
      while ( m_nMeshes != 0 );
    }
    pInstanceGeometry = pInstanceGeometry->m_pNextLOD;
  }
  while ( pInstanceGeometry != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x0040CC20
// Name: public: void CResourceDictionaryBuilder::InitTextureData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceDictionaryBuilder::InitTextureData(CResourceDictionaryBuilder *this)
{
  int v1; // eax
  InstanceGeometry_t *v2; // edi
  int m_nMeshes; // ebx
  int v4; // esi
  InstanceGeometry_t *m_pNextLOD; // edi
  int nInstanceGeometries; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  CResourceDictionaryBuilder *v8; // [esp+8h] [ebp-4h]

  v1 = 0;
  v8 = this;
  nInstanceGeometries = this->m_InstanceGeometryList.m_Size;
  i = 0;
  if ( nInstanceGeometries > 0 )
  {
    do
    {
      v2 = this->m_InstanceGeometryList.m_Memory.m_pMemory[v1];
      m_nMeshes = v2->m_nMeshes;
      if ( v2->m_nMeshes > 0 )
      {
        v4 = 0;
        do
        {
          CBuilderMesh::InitTextureData(this: &v2->m_pMeshes[v4++]);
          --m_nMeshes;
        }
        while ( m_nMeshes != 0 );
        this = v8;
      }
      m_pNextLOD = v2->m_pNextLOD;
      if ( m_pNextLOD != nullptr )
      {
        CResourceDictionaryBuilder::InitTextureData(this, pInstanceGeometry: m_pNextLOD);
        this = v8;
      }
      v1 = i + 1;
      i = v1;
    }
    while ( v1 < nInstanceGeometries );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC90
// Name: public: unsigned __int64 CResourceDictionaryBuilder::Serialize(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CResourceDictionaryBuilder::Serialize(CResourceDictionaryBuilder *this, _iobuf *fp)
{
  int m_nInputLayouts; // eax
  int i; // esi
  const char *NameForInputLayout; // eax
  __int64 v6; // rcx
  unsigned int v7; // esi
  int v8; // edi
  int NumFields; // ebx
  RenderInputLayoutField_t *LayoutFields; // eax
  int m_nResources; // eax
  CBVHDictionaryEntry entry; // [esp+Ch] [ebp-F0h] BYREF
  BVHInputLayoutDesc_t desc; // [esp+74h] [ebp-88h] BYREF
  BVHResourceDictionaryHeader_t DictHeader; // [esp+A4h] [ebp-58h] BYREF
  CResourceDictionaryBuilder *v16; // [esp+ECh] [ebp-10h]
  unsigned int v17; // [esp+F0h] [ebp-Ch]
  unsigned __int64 nBytes; // [esp+F4h] [ebp-8h]

  v16 = this;
  DictHeader.m_nInputLayouts = CDmAttributeOp<CUtlSymbolLarge>::ValueSize((CDmeRigIKConstraintOperator *)this);
  DictHeader.m_nResources = this->m_EntryList.m_Size;
  V_snprintf(pDest: DictHeader.m_pPageFile, maxLen: 100, pFormat: "%s", this->m_pPageFile);
  fwrite(buffer: &DictHeader, size: 0x48u, count: 1u, stream: fp);
  m_nInputLayouts = DictHeader.m_nInputLayouts;
  for ( i = 0; i < DictHeader.m_nInputLayouts; ++i )
  {
    desc.m_nFields = GetNumFields(nLayout: i);
    desc.m_pFields = nullptr;
    NameForInputLayout = GetNameForInputLayout(nLayout: i);
    V_strncpy(pDest: desc.m_pName, pSrc: NameForInputLayout, maxLen: 32);
    fwrite(buffer: &desc, size: 0x30u, count: 1u, stream: fp);
    m_nInputLayouts = DictHeader.m_nInputLayouts;
  }
  v6 = (unsigned int)(48 * m_nInputLayouts);
  v7 = (unsigned __int64)(v6 + 72) >> 32;
  LODWORD(v6) = v6 + 72;
  v8 = 0;
  nBytes = __PAIR64__(v7, v6);
  if ( m_nInputLayouts > 0 )
  {
    do
    {
      NumFields = GetNumFields(nLayout: v8);
      LayoutFields = GetLayoutFields(nLayout: v8);
      fwrite(buffer: LayoutFields, size: 56 * NumFields, count: 1u, stream: fp);
      nBytes += (unsigned int)(56 * NumFields);
      ++v8;
    }
    while ( v8 < DictHeader.m_nInputLayouts );
    v7 = HIDWORD(nBytes);
    v6 = (unsigned int)nBytes;
  }
  m_nResources = DictHeader.m_nResources;
  if ( DictHeader.m_nResources > 0 )
  {
    v17 = 0;
    do
    {
      entry = v16->m_EntryList.m_Memory.m_pMemory[v17 / 0x68];
      fwrite(buffer: &entry, size: 0x68u, count: 1u, stream: fp);
      m_nResources = DictHeader.m_nResources;
      v17 += 104;
      ++HIDWORD(v6);
    }
    while ( SHIDWORD(v6) < DictHeader.m_nResources );
    v7 = HIDWORD(nBytes);
    LODWORD(v6) = nBytes;
  }
  return __PAIR64__(v7, v6) + (unsigned int)(104 * m_nResources);
}

//------------------------------------------------------------------------------
// Address: 0x0040CE60
// Name: public: CResourceDictionaryBuilder::CResourceDictionaryBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CResourceDictionaryBuilder *__thiscall CResourceDictionaryBuilder::CResourceDictionaryBuilder(
        CResourceDictionaryBuilder *this)
{
  this->__vftable = (CResourceDictionaryBuilder_vtbl *)&CResourceDictionaryBuilder::`vftable';
  this->m_InstanceGeometryList.m_Memory.m_pMemory = nullptr;
  this->m_InstanceGeometryList.m_Memory.m_nAllocationCount = 0;
  this->m_InstanceGeometryList.m_Memory.m_nGrowSize = 0;
  this->m_InstanceGeometryList.m_Size = 0;
  this->m_InstanceGeometryList.m_pElements = nullptr;
  this->m_EntryList.m_Memory.m_pMemory = nullptr;
  this->m_EntryList.m_Memory.m_nAllocationCount = 0;
  this->m_EntryList.m_Memory.m_nGrowSize = 0;
  this->m_EntryList.m_Size = 0;
  this->m_EntryList.m_pElements = nullptr;
  this->m_nCurrentSize = 0;
  this->m_UniqueDict.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_UniqueDict.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_UniqueDict.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_UniqueDict.m_Vector.m_Size = 0;
  this->m_UniqueDict.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_UniqueDict.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  this->m_UniqueMaterials.m_Memory.m_pMemory = nullptr;
  this->m_UniqueMaterials.m_Memory.m_nAllocationCount = 0;
  this->m_UniqueMaterials.m_Memory.m_nGrowSize = 0;
  this->m_UniqueMaterials.m_Size = 0;
  this->m_UniqueMaterials.m_pElements = nullptr;
  this->m_UniqueMaterialEntries.m_Memory.m_pMemory = nullptr;
  this->m_UniqueMaterialEntries.m_Memory.m_nAllocationCount = 0;
  this->m_UniqueMaterialEntries.m_Memory.m_nGrowSize = 0;
  this->m_UniqueMaterialEntries.m_Size = 0;
  this->m_UniqueMaterialEntries.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040CF10
// Name: public: int CResourceDictionaryBuilder::AddEntry(unsigned char,unsigned __int64,int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceDictionaryBuilder::AddEntry(
        CResourceDictionaryBuilder *this,
        unsigned __int8 nFlags,
        unsigned __int64 nSizeBytes,
        int nResourceType,
        char *pName,
        bool bInstanced)
{
  unsigned int m_nCurrentSize; // ecx
  unsigned int m_nCurrentSize_high; // edx
  bool v9; // cf
  int m_Size; // eax
  CBVHDictionaryEntry src; // [esp+Ch] [ebp-D0h] BYREF
  CBVHDictionaryEntry entry; // [esp+74h] [ebp-68h] BYREF

  m_nCurrentSize = this->m_nCurrentSize;
  m_nCurrentSize_high = HIDWORD(this->m_nCurrentSize);
  entry.m_Flags = nFlags;
  entry.m_ChunkDesc.m_nOffset = __PAIR64__(m_nCurrentSize_high, m_nCurrentSize);
  entry.m_ChunkDesc.m_nSize = nSizeBytes;
  entry.m_nRefCount = 0;
  entry.m_nResourceType = nResourceType;
  V_strncpy(pDest: entry.m_pName, pSrc: pName, maxLen: 64);
  v9 = __CFADD__((_DWORD)nSizeBytes, this->m_nCurrentSize);
  LODWORD(this->m_nCurrentSize) += nSizeBytes;
  entry.m_bInstanceData = bInstanced;
  HIDWORD(this->m_nCurrentSize) += HIDWORD(nSizeBytes) + v9;
  m_Size = this->m_EntryList.m_Size;
  src = entry;
  return CUtlVector<CBVHDictionaryEntry,CUtlMemory<CBVHDictionaryEntry,int>>::InsertBefore(
           this: &this->m_EntryList,
           elem: m_Size,
           &src);
}

//------------------------------------------------------------------------------
// Address: 0x0040CFA0
// Name: public: int CResourceDictionaryBuilder::AddUniqueMaterial(bool __near *,struct Material_t __near &,unsigned char,unsigned __int64,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceDictionaryBuilder::AddUniqueMaterial(
        CResourceDictionaryBuilder *this,
        bool *pWriteOut,
        Material_t *material,
        unsigned __int8 nFlags,
        unsigned __int64 nSizeBytes,
        char *pName)
{
  int v7; // esi
  int v8; // edi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  Material_t *m_pMemory; // ecx
  int v12; // eax
  Material_t *v13; // edi
  unsigned int m_nCurrentSize_high; // edx
  unsigned int m_nCurrentSize; // ecx
  bool v16; // cf
  int v17; // eax
  int v18; // edi
  CBVHDictionaryEntry *v19; // ecx
  int v20; // eax
  CBVHDictionaryEntry *v21; // eax
  int v22; // eax
  CUtlMemory<S3RGBA,int> *p_m_UniqueMaterialEntries; // esi
  int v24; // ebx
  S3RGBA *v25; // ecx
  int v26; // eax
  int *v27; // ebx
  _BYTE v29[104]; // [esp+Ch] [ebp-D4h]
  _QWORD v30[13]; // [esp+74h] [ebp-6Ch] BYREF
  int nMaterials; // [esp+DCh] [ebp-4h]

  v7 = 0;
  nMaterials = this->m_UniqueMaterials.m_Size;
  if ( nMaterials <= 0 )
  {
LABEL_5:
    m_Size = this->m_UniqueMaterials.m_Size;
    m_nAllocationCount = this->m_UniqueMaterials.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<Material_t,int>::Grow(this: &this->m_UniqueMaterials.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_UniqueMaterials.m_Size;
    m_pMemory = this->m_UniqueMaterials.m_Memory.m_pMemory;
    v12 = this->m_UniqueMaterials.m_Size - m_Size - 1;
    this->m_UniqueMaterials.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 164 * v12);
    v13 = &this->m_UniqueMaterials.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      qmemcpy(v13, material, sizeof(Material_t));
    m_nCurrentSize_high = HIDWORD(this->m_nCurrentSize);
    m_nCurrentSize = this->m_nCurrentSize;
    BYTE4(v30[12]) = nFlags;
    v30[2] = nSizeBytes;
    v30[1] = __PAIR64__(m_nCurrentSize_high, m_nCurrentSize);
    LODWORD(v30[3]) = 0;
    LODWORD(v30[4]) = 17;
    V_strncpy(pDest: (char *)&v30[4] + 4, pSrc: pName, maxLen: 64);
    v16 = __CFADD__((_DWORD)nSizeBytes, this->m_nCurrentSize);
    LODWORD(this->m_nCurrentSize) += nSizeBytes;
    HIDWORD(this->m_nCurrentSize) += HIDWORD(nSizeBytes) + v16;
    v17 = this->m_EntryList.m_Memory.m_nAllocationCount;
    BYTE5(v30[12]) = 0;
    qmemcpy(v29, v30, sizeof(v29));
    v18 = this->m_EntryList.m_Size;
    if ( v18 + 1 > v17 )
      CUtlMemory<CBVHDictionaryEntry,int>::Grow(this: &this->m_EntryList.m_Memory, num: v18 - v17 + 1);
    ++this->m_EntryList.m_Size;
    v19 = this->m_EntryList.m_Memory.m_pMemory;
    v20 = this->m_EntryList.m_Size - v18 - 1;
    this->m_EntryList.m_pElements = v19;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[v18 + 1], src: &v19[v18], count: 104 * v20);
    v21 = &this->m_EntryList.m_Memory.m_pMemory[v18];
    if ( v21 != nullptr )
      qmemcpy(v21, v29, sizeof(CBVHDictionaryEntry));
    v22 = this->m_UniqueMaterialEntries.m_Memory.m_nAllocationCount;
    p_m_UniqueMaterialEntries = (CUtlMemory<S3RGBA,int> *)&this->m_UniqueMaterialEntries;
    v24 = this->m_UniqueMaterialEntries.m_Size;
    if ( v24 + 1 > v22 )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_UniqueMaterialEntries, num: v24 - v22 + 1);
    ++p_m_UniqueMaterialEntries[1].m_pMemory;
    v25 = p_m_UniqueMaterialEntries->m_pMemory;
    v26 = (int)p_m_UniqueMaterialEntries[1].m_pMemory - v24 - 1;
    p_m_UniqueMaterialEntries[1].m_nAllocationCount = (int)p_m_UniqueMaterialEntries->m_pMemory;
    if ( v26 > 0 )
      _V_memmove(dest: &v25[v24 + 1], src: &v25[v24], count: 4 * v26);
    v27 = (int *)&p_m_UniqueMaterialEntries->m_pMemory[v24];
    if ( v27 != nullptr )
      *v27 = v18;
    *pWriteOut = true;
    return v18;
  }
  else
  {
    v8 = 0;
    while ( _V_memcmp(m1: &this->m_UniqueMaterials.m_Memory.m_pMemory[v8], m2: material, count: 164) != 0 )
    {
      ++v7;
      ++v8;
      if ( v7 >= nMaterials )
        goto LABEL_5;
    }
    return this->m_UniqueMaterialEntries.m_Memory.m_pMemory[v7];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D1B0
// Name: public: int CResourceDictionaryBuilder::AddInstanceGeometry(struct InstanceGeometry_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceDictionaryBuilder::AddInstanceGeometry(
        CResourceDictionaryBuilder *this,
        InstanceGeometry_t *pInstanceGeometry)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_InstanceGeometryList; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_InstanceGeometryList.m_Memory.m_nAllocationCount;
  p_m_InstanceGeometryList = (CUtlMemory<S3RGBA,int> *)&this->m_InstanceGeometryList;
  m_Size = this->m_InstanceGeometryList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_InstanceGeometryList, num: m_Size - m_nAllocationCount + 1);
  ++p_m_InstanceGeometryList[1].m_pMemory;
  m_pMemory = p_m_InstanceGeometryList->m_pMemory;
  v6 = (int)p_m_InstanceGeometryList[1].m_pMemory - m_Size - 1;
  p_m_InstanceGeometryList[1].m_nAllocationCount = (int)p_m_InstanceGeometryList->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_InstanceGeometryList->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)pInstanceGeometry;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040D270
// Name: public: int CResourceDictionaryBuilder::AddUniqueItem(bool __near *,char __near *,unsigned char,unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceDictionaryBuilder::AddUniqueItem(
        CResourceDictionaryBuilder *this,
        bool *pWriteOut,
        char *pFileName,
        unsigned __int8 nFlags,
        unsigned __int64 nSizeBytes,
        int nResourceType)
{
  unsigned __int16 m_Id; // bx
  bool *v8; // eax
  unsigned __int16 v9; // ax
  int m_Size; // edx
  int v11; // ecx
  int *v12; // esi
  CUtlSymbol v14; // [esp+Ah] [ebp-2h] BYREF

  m_Id = CUtlSymbolTable::Find(this: &this->m_UniqueDict.m_SymbolTable, result: &v14, pString: pFileName)->m_Id;
  v8 = pWriteOut;
  *pWriteOut = false;
  if ( m_Id == 0xFFFF )
  {
    *v8 = true;
    CUtlSymbolTable::AddString(
      this: &this->m_UniqueDict.m_SymbolTable,
      result: (CUtlSymbol *)&pWriteOut,
      pString: pFileName);
    v9 = (unsigned __int16)pWriteOut;
    m_Size = this->m_UniqueDict.m_Vector.m_Size;
    if ( m_Size <= (unsigned __int16)pWriteOut )
    {
      v11 = (unsigned __int16)pWriteOut + 1;
      if ( m_Size < v11 )
      {
        CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
          this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_UniqueDict,
          elem: m_Size,
          num: v11 - m_Size);
        v9 = (unsigned __int16)pWriteOut;
      }
    }
    m_Id = v9;
    v12 = &this->m_UniqueDict.m_Vector.m_Memory.m_pMemory[v9];
    *v12 = CResourceDictionaryBuilder::AddEntry(
             this,
             nFlags,
             nSizeBytes,
             nResourceType,
             pName: pFileName,
             bInstanced: false);
  }
  return this->m_UniqueDict.m_Vector.m_Memory.m_pMemory[m_Id];
}

//------------------------------------------------------------------------------
// Address: 0x0040D330
// Name: public: int CResourceDictionaryBuilder::AddTextureToDictionary(char __near *,class IVTFTexture __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceDictionaryBuilder::AddTextureToDictionary(
        CResourceDictionaryBuilder *this,
        char *pTextureName,
        IVTFTexture *pVTFTexture,
        _iobuf *fp)
{
  int result; // eax
  int v5; // edi
  char pRelativePath[260]; // [esp+8h] [ebp-440h] BYREF
  char pOnDiskName[256]; // [esp+10Ch] [ebp-33Ch] BYREF
  char pFullFileName[260]; // [esp+20Ch] [ebp-23Ch] BYREF
  char pCommand[260]; // [esp+310h] [ebp-138h] BYREF
  CUtlBuffer buf; // [esp+414h] [ebp-34h] BYREF
  bool bWrite; // [esp+447h] [ebp-1h] BYREF

  bWrite = false;
  result = CResourceDictionaryBuilder::AddUniqueItem(
             this,
             pWriteOut: &bWrite,
             pFileName: pTextureName,
             nFlags: 8u,
             nSizeBytes: 0x100u,
             nResourceType: 3);
  v5 = result;
  if ( bWrite )
  {
    _V_memset(dest: pOnDiskName, fill: 0, count: 256);
    V_strncpy(pDest: pOnDiskName, pSrc: pTextureName, maxLen: 256);
    fwrite(buffer: pOnDiskName, size: 0x100u, count: 1u, stream: fp);
    V_FixupPathName(pOut: pRelativePath, nOutLen: 0x104u, pPath: pTextureName);
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pRelativePath,
      a3: "GAME",
      a4: pFullFileName,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    if ( !V_IsAbsolutePath(pStr: pFullFileName) )
    {
      g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: pCommand, a5: 260);
      *_V_strstr(s1: pCommand, search: ";") = 0;
      V_snprintf(pDest: pFullFileName, maxLen: 260, pFormat: "%s%s", pCommand, pRelativePath);
    }
    if ( pVTFTexture != nullptr )
    {
      V_ExtractFilePath(path: pFullFileName, dest: pCommand, destSize: 260);
      if ( !g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: pCommand, a3: nullptr) )
        Q_mkdir(path: pCommand);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
      pVTFTexture->Serialize(this: pVTFTexture, a2: &buf);
      if ( !g_pFullFileSystem->WriteFile(
              this: &g_pFullFileSystem->IBaseFileSystem,
              a2: pFullFileName,
              a3: nullptr,
              a4: &buf) )
        _Warning(a1: "Error writing texture %s\n", pFullFileName);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFullFileName, a3: nullptr) )
    {
      V_snprintf(pDest: pCommand, maxLen: 260, pFormat: "-allowdebug -i %s", pFullFileName);
      ShellExecuteA(
        hwnd: nullptr,
        lpOperation: nullptr,
        lpFile: "resourcecompiler.exe",
        lpParameters: pCommand,
        lpDirectory: nullptr,
        nShowCmd: 0);
    }
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D570
// Name: public: void CResourceDictionaryBuilder::AddEntriesForInstanceGeometry(struct InstanceGeometry_t __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceDictionaryBuilder::AddEntriesForInstanceGeometry(
        CResourceDictionaryBuilder *this,
        InstanceGeometry_t *pInstanceGeometry,
        _iobuf *fp)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int *v7; // eax
  InstanceGeometry_t *v8; // ecx
  int v9; // esi
  int *v10; // eax
  CBuilderMesh *v11; // edi
  int v12; // esi
  int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  int m_nVertexCount; // edx
  int m_nCurrentSize; // ecx
  int m_nCurrentSize_high; // edx
  bool v19; // cf
  int m_nAllocationCount; // eax
  int v21; // edi
  CBVHDictionaryEntry *m_pMemory; // ecx
  int v23; // eax
  CBVHDictionaryEntry *v24; // eax
  unsigned int m_nIndexCount; // esi
  int v26; // edx
  int v27; // eax
  int v28; // edi
  CBVHDictionaryEntry *v29; // ecx
  int v30; // eax
  CBVHDictionaryEntry *v31; // eax
  int *v32; // edx
  int v33; // eax
  InstanceGeometry_t *m_pNextLOD; // ecx
  _BYTE v35[104]; // [esp+Ch] [ebp-160h]
  _BYTE v36[104]; // [esp+74h] [ebp-F8h]
  _DWORD v37[26]; // [esp+DCh] [ebp-90h] BYREF
  BVHBufferDesc_t BufferDesc; // [esp+144h] [ebp-28h] BYREF
  unsigned int v39; // [esp+150h] [ebp-1Ch]
  CBuilderMesh *mesh; // [esp+154h] [ebp-18h]
  int nMeshes; // [esp+158h] [ebp-14h]
  int m_nTextures; // [esp+15Ch] [ebp-10h]
  int iEntry; // [esp+160h] [ebp-Ch]
  int m; // [esp+164h] [ebp-8h]
  bool bWriteOut; // [esp+16Bh] [ebp-1h] BYREF

  while ( 1 )
  {
    v5 = 4 * pInstanceGeometry->m_nMeshes;
    v6 = (unsigned __int64)(unsigned int)pInstanceGeometry->m_nMeshes >> 30 != 0;
    nMeshes = pInstanceGeometry->m_nMeshes;
    v4 = nMeshes;
    pInstanceGeometry->m_ppEntries = (int **)MemAlloc_Alloc(nSize: v5 | -v6);
    v7 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v4 >> 30 != 0 ? -1 : 4 * v4);
    v8 = pInstanceGeometry;
    pInstanceGeometry->m_pEntryCounts = v7;
    m = 0;
    if ( v4 > 0 )
    {
      v39 = 0;
      do
      {
        mesh = &v8->m_pMeshes[v39 / 0x174];
        v9 = mesh->m_Material.m_nTextures + 3;
        m_nTextures = mesh->m_Material.m_nTextures;
        v8->m_pEntryCounts[m] = v9;
        v10 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v9 >> 30 != 0 ? -1 : 4 * v9);
        v11 = mesh;
        pInstanceGeometry->m_ppEntries[m] = v10;
        bWriteOut = false;
        iEntry = CResourceDictionaryBuilder::AddUniqueMaterial(
                   this,
                   pWriteOut: &bWriteOut,
                   material: &v11->m_Material.m_Material,
                   nFlags: 2u,
                   nSizeBytes: 0xA4u,
                   pName: pInstanceGeometry->m_pOriginalModelName);
        if ( bWriteOut )
          fwrite(buffer: &v11->m_Material, size: 0xA4u, count: 1u, stream: fp);
        v12 = 0;
        for ( *pInstanceGeometry->m_ppEntries[m] = iEntry; v12 < m_nTextures; ++v12 )
        {
          v13 = CResourceDictionaryBuilder::AddTextureToDictionary(
                  this,
                  pTextureName: v11->m_Material.m_ppTextures[v12]->m_szVTFName,
                  pVTFTexture: nullptr,
                  fp);
          pInstanceGeometry->m_ppEntries[m][v12 + 1] = v13;
        }
        v14 = v11->m_mesh.m_nVertexCount * v11->m_mesh.m_nVertexStrideFloats;
        v15 = 4 * v11->m_mesh.m_nVertexStrideFloats;
        BufferDesc.m_nBufferType = RENDER_BUFFER_TYPE_STATIC;
        m_nVertexCount = v11->m_mesh.m_nVertexCount;
        BufferDesc.m_nElementSizeInBytes = v15;
        v14 *= 4;
        BufferDesc.m_nElementCount = m_nVertexCount;
        fwrite(buffer: &BufferDesc, size: 0xCu, count: 1u, stream: fp);
        fwrite(buffer: v11->m_mesh.m_pVerts, size: v14, count: 1u, stream: fp);
        m_nCurrentSize = this->m_nCurrentSize;
        m_nCurrentSize_high = HIDWORD(this->m_nCurrentSize);
        v37[6] = 0;
        v37[5] = 0;
        v37[8] = 0;
        LOBYTE(v37[25]) = 8;
        v37[2] = m_nCurrentSize;
        v37[3] = m_nCurrentSize_high;
        v37[4] = v14 + 12;
        V_strncpy(pDest: (char *)&v37[9], pSrc: pInstanceGeometry->m_pOriginalModelName, maxLen: 64);
        v19 = __CFADD__(v14 + 12, this->m_nCurrentSize);
        LODWORD(this->m_nCurrentSize) += v14 + 12;
        HIDWORD(this->m_nCurrentSize) += v19;
        m_nAllocationCount = this->m_EntryList.m_Memory.m_nAllocationCount;
        BYTE1(v37[25]) = 0;
        qmemcpy(v36, v37, sizeof(v36));
        iEntry = this->m_EntryList.m_Size;
        v21 = iEntry;
        if ( iEntry + 1 > m_nAllocationCount )
          CUtlMemory<CBVHDictionaryEntry,int>::Grow(
            this: &this->m_EntryList.m_Memory,
            num: iEntry - m_nAllocationCount + 1);
        ++this->m_EntryList.m_Size;
        m_pMemory = this->m_EntryList.m_Memory.m_pMemory;
        v23 = this->m_EntryList.m_Size - v21 - 1;
        this->m_EntryList.m_pElements = m_pMemory;
        if ( v23 > 0 )
          _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 104 * v23);
        v24 = &this->m_EntryList.m_Memory.m_pMemory[v21];
        if ( v24 != nullptr )
        {
          qmemcpy(v24, v36, sizeof(CBVHDictionaryEntry));
          v21 = iEntry;
        }
        pInstanceGeometry->m_ppEntries[m][m_nTextures + 1] = v21;
        m_nIndexCount = mesh->m_mesh.m_nIndexCount;
        BufferDesc.m_nBufferType = RENDER_BUFFER_TYPE_STATIC;
        m_nIndexCount *= 4;
        BufferDesc.m_nElementCount = mesh->m_mesh.m_nIndexCount;
        BufferDesc.m_nElementSizeInBytes = 4;
        fwrite(buffer: &BufferDesc, size: 0xCu, count: 1u, stream: fp);
        fwrite(buffer: mesh->m_mesh.m_pIndices, size: m_nIndexCount, count: 1u, stream: fp);
        v26 = this->m_nCurrentSize;
        v37[3] = HIDWORD(this->m_nCurrentSize);
        v37[6] = 0;
        LOBYTE(v37[25]) = 8;
        v37[2] = v26;
        v37[4] = m_nIndexCount + 12;
        v37[5] = __CFADD__(m_nIndexCount, 12);
        v37[8] = 2;
        V_strncpy(pDest: (char *)&v37[9], pSrc: pInstanceGeometry->m_pOriginalModelName, maxLen: 64);
        v19 = __CFADD__(m_nIndexCount + 12, this->m_nCurrentSize);
        LODWORD(this->m_nCurrentSize) += m_nIndexCount + 12;
        HIDWORD(this->m_nCurrentSize) += v37[5] + v19;
        v27 = this->m_EntryList.m_Memory.m_nAllocationCount;
        BYTE1(v37[25]) = 0;
        qmemcpy(v35, v37, sizeof(v35));
        iEntry = this->m_EntryList.m_Size;
        v28 = iEntry;
        if ( iEntry + 1 > v27 )
          CUtlMemory<CBVHDictionaryEntry,int>::Grow(this: &this->m_EntryList.m_Memory, num: iEntry - v27 + 1);
        ++this->m_EntryList.m_Size;
        v29 = this->m_EntryList.m_Memory.m_pMemory;
        v30 = this->m_EntryList.m_Size - v28 - 1;
        this->m_EntryList.m_pElements = v29;
        if ( v30 > 0 )
          _V_memmove(dest: &v29[v28 + 1], src: &v29[v28], count: 104 * v30);
        v31 = &this->m_EntryList.m_Memory.m_pMemory[v28];
        if ( v31 != nullptr )
        {
          qmemcpy(v31, v35, sizeof(CBVHDictionaryEntry));
          v28 = iEntry;
        }
        v32 = pInstanceGeometry->m_ppEntries[m];
        v39 += 372;
        v33 = m + 1;
        v32[m_nTextures + 2] = v28;
        v8 = pInstanceGeometry;
        m = v33;
      }
      while ( v33 < nMeshes );
    }
    m_pNextLOD = v8->m_pNextLOD;
    if ( m_pNextLOD == nullptr )
      break;
    pInstanceGeometry = m_pNextLOD;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D920
// Name: public: void CResourceDictionaryBuilder::CreateInstanceEntries(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceDictionaryBuilder::CreateInstanceEntries(CResourceDictionaryBuilder *this, _iobuf *fp)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_InstanceGeometryList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
    this->m_nInstancedEntries = this->m_EntryList.m_Size;
  }
  else
  {
    do
      CResourceDictionaryBuilder::AddEntriesForInstanceGeometry(
        this,
        pInstanceGeometry: this->m_InstanceGeometryList.m_Memory.m_pMemory[v4++],
        fp);
    while ( v4 < m_Size );
    this->m_nInstancedEntries = this->m_EntryList.m_Size;
  }
}
