// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/saverestore_filesystem.cpp
// Functions: 28
// ============================================================

#include "engine\saverestore_filesystem.h"

//------------------------------------------------------------------------------
// Address: 0x101CE910
// Name: void SaveInMemoryCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveInMemoryCallback()
{
  _Warning(a1: "save_in_memory is compatible with only the Xbox 360!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101CEAB0
// Name: public: void CSaveRestoreFileSystem::Compress(struct CSaveDirectory::file_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSaveRestoreFileSystem::Compress(CSaveRestoreFileSystem *this, CSaveDirectory::file_t *pFile)
{
  CUtlBuffer *pCompressedBuffer; // edi
  CUtlBuffer *pBuffer; // ecx
  unsigned int nSize; // edx
  int *p_nCompressedSize; // edi
  unsigned __int8 *v7; // eax
  CUtlBuffer *v8; // edi
  unsigned int v9; // edi
  unsigned int nCompressedSize; // eax
  const char *v11; // eax
  CLZSS v12; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch]
  unsigned int v14; // [esp+20h] [ebp-8h]
  CSaveRestoreFileSystem *compressor; // [esp+24h] [ebp-4h] OVERLAPPED
  float destBytes; // [esp+30h] [ebp+8h]

  pCompressedBuffer = pFile->pCompressedBuffer;
  compressor = this;
  pCompressedBuffer->m_Get = 0;
  pCompressedBuffer->m_Put = 0;
  pCompressedBuffer->m_nOffset = 0;
  pCompressedBuffer->m_nMaxPut = 0;
  pCompressedBuffer->m_Error = 0;
  if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
      pCompressedBuffer->m_Memory.m_pMemory = nullptr;
    }
    pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
  }
  pBuffer = pFile->pBuffer;
  nSize = pFile->nSize;
  p_nCompressedSize = (int *)&pFile->nCompressedSize;
  v13 = 2048;
  v7 = CLZSS::Compress(
         this: (CLZSS *)&v12.m_pHashTarget,
         pInput: pBuffer->m_Memory.m_pMemory,
         inputLength: nSize,
         pOutputSize: &pFile->nCompressedSize);
  if ( v7 != nullptr )
  {
    CUtlBuffer::AssumeMemory(
      this: pFile->pCompressedBuffer,
      pMemory: v7,
      nSize: *p_nCompressedSize,
      nInitialPut: *p_nCompressedSize,
      nFlags: 0);
  }
  else
  {
    CUtlBuffer::Put(this: pFile->pCompressedBuffer, pMem: pFile->pBuffer->m_Memory.m_pMemory, size: pFile->nSize);
    *p_nCompressedSize = pFile->nSize;
  }
  CUtlBuffer::SeekGet(this: pFile->pCompressedBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::SeekPut(this: pFile->pCompressedBuffer, type: SEEK_HEAD, offset: *p_nCompressedSize);
  v8 = pFile->pBuffer;
  v8->m_Get = 0;
  v8->m_Put = 0;
  v8->m_nOffset = 0;
  v8->m_nMaxPut = 0;
  v8->m_Error = 0;
  if ( v8->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Memory.m_pMemory);
      v8->m_Memory.m_pMemory = nullptr;
    }
    v8->m_Memory.m_nAllocationCount = 0;
  }
  v9 = pFile->nSize;
  nCompressedSize = pFile->nCompressedSize;
  pFile->nSize = 0;
  v14 = nCompressedSize;
  destBytes = 0.0;
  if ( v9 != 0 )
    destBytes = (1.0 - (double)nCompressedSize / (double)v9) * 100.0;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = CUtlSymbolTable::String(this: &compressor->m_pSaveDirectory->m_SymbolTable, id: pFile->name);
    _Msg(a1: "SIM: SaveDir: (%s) Compressed %d bytes to %d bytes. (%.0f%%)\n", v11, v9, v14, destBytes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEC20
// Name: public: void CSaveRestoreFileSystem::Uncompress(struct CSaveDirectory::file_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Uncompress(CSaveRestoreFileSystem *this, CSaveDirectory::file_t *pFile)
{
  CUtlBuffer *pBuffer; // edi
  CUtlBuffer *pCompressedBuffer; // ecx
  unsigned int ActualSize; // eax
  unsigned __int8 *v5; // edi
  int v6; // eax
  CUtlBuffer *v7; // ecx
  unsigned int nCompressedSize; // edi
  unsigned int nSize; // ebx
  const char *v10; // eax
  CLZSS compressor; // [esp+Ch] [ebp-10h] BYREF
  CSaveRestoreFileSystem *v12; // [esp+18h] [ebp-4h]

  pBuffer = pFile->pBuffer;
  v12 = this;
  pBuffer->m_Get = 0;
  pBuffer->m_Put = 0;
  pBuffer->m_nOffset = 0;
  pBuffer->m_nMaxPut = 0;
  pBuffer->m_Error = 0;
  if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( pBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
      pBuffer->m_Memory.m_pMemory = nullptr;
    }
    pBuffer->m_Memory.m_nAllocationCount = 0;
  }
  pCompressedBuffer = pFile->pCompressedBuffer;
  compressor.m_nWindowSize = 4096;
  ActualSize = CLZSS::GetActualSize(this: &compressor, pInput: pCompressedBuffer->m_Memory.m_pMemory);
  if ( ActualSize != 0 )
  {
    v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: ActualSize);
    v6 = CLZSS::Uncompress(this: &compressor, pInput: pFile->pCompressedBuffer->m_Memory.m_pMemory, pOutput: v5);
    CUtlBuffer::AssumeMemory(this: pFile->pBuffer, pMemory: v5, nSize: v6, nInitialPut: v6, nFlags: 0);
  }
  else
  {
    CUtlBuffer::Put(
      this: pFile->pBuffer,
      pMem: pFile->pCompressedBuffer->m_Memory.m_pMemory,
      size: pFile->nCompressedSize);
  }
  v7 = pFile->pBuffer;
  pFile->nSize = v7->m_nMaxPut;
  CUtlBuffer::SeekGet(this: v7, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::SeekPut(this: pFile->pBuffer, type: SEEK_HEAD, offset: pFile->nSize);
  nCompressedSize = pFile->nCompressedSize;
  nSize = pFile->nSize;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = CUtlSymbolTable::String(this: &v12->m_pSaveDirectory->m_SymbolTable, id: pFile->name);
    _Msg(a1: "SIM: SaveDir: (%s) Uncompressed %d bytes to %d bytes.\n", v10, nCompressedSize, nSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CF830
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::AsyncWrite(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  int v8; // ebx
  int v9; // eax
  CSaveDirectory::file_t *p_elem; // esi

  v8 = -5;
  v9 = this->Open(this, a2: pFileName, a3: "wb", a4: nullptr);
  if ( v9 != 0 )
  {
    p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.elem;
    if ( p_elem->eType == 1 )
    {
      CUtlBuffer::Put(
        this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.elem.pBuffer,
        pMem: pSrc,
        size: nSrcBytes);
      p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
      CSaveRestoreFileSystem::Compress(this, pFile: p_elem);
      v8 = 0;
    }
    else
    {
      _Warning(a1: "AsyncWrite: Attempted to write to a read-only file");
    }
  }
  if ( bFreeMemory )
    free(pMem: pSrc);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101CF8C0
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::AsyncAppend(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  int v7; // ebx
  int v8; // eax
  CSaveDirectory::file_t *p_elem; // esi

  v7 = -5;
  v8 = this->Open(this, a2: pFileName, a3: "a", a4: nullptr);
  if ( v8 != 0 )
  {
    p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem;
    if ( p_elem->eType == 1 )
    {
      CUtlBuffer::Put(
        this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.pBuffer,
        pMem: pSrc,
        size: nSrcBytes);
      p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
      CSaveRestoreFileSystem::Compress(this, pFile: p_elem);
      v7 = 0;
    }
    else
    {
      _Warning(a1: "AsyncAppend: Attempted to write to a read-only file");
    }
  }
  if ( bFreeMemory )
    free(pMem: pSrc);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101CF950
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystem::AsyncAppendFile(
        CSaveRestoreFileSystem *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  int v5; // eax

  v5 = this->Open(this, a2: pSrcFileName, a3: "rb", a4: nullptr);
  if ( v5 != 0 )
    return this->AsyncAppend(
             this,
             a2: pDestFileName,
             a3: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem.pBuffer->m_Memory.m_pMemory,
             a4: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem.nSize,
             a5: false,
             a6: nullptr);
  else
    return FSASYNC_ERR_FILEOPEN;
}

//------------------------------------------------------------------------------
// Address: 0x101CF9B0
// Name: public: virtual bool CSaveRestoreFileSystem::DirectoryExtract(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystem::DirectoryExtract(
        CSaveRestoreFileSystem *this,
        void *pFile,
        int fileCount,
        bool bIsXSave)
{
  void *v5; // ebx
  int v6; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v8; // eax
  int p_elem; // edi
  void *v10; // eax
  const char *v11; // eax
  char fileName[260]; // [esp+Ch] [ebp-108h] BYREF
  int i; // [esp+110h] [ebp-4h]

  i = 0;
  if ( fileCount <= 0 )
    return 1;
  v5 = pFile;
  while ( 1 )
  {
    this->Read(this, a2: fileName, a3: 260, a4: v5);
    this->Read(this, a2: &pFile, a3: 4, a4: v5);
    if ( pFile == nullptr )
      break;
    v6 = this->Open(this, a2: fileName, a3: "wb", a4: nullptr);
    if ( v6 == 0 )
      break;
    m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
    v8 = (unsigned __int16)v6;
    p_elem = (int)&m_pMemory[v8].m_Data.elem;
    CUtlBuffer::EnsureCapacity(this: m_pMemory[v8].m_Data.elem.pCompressedBuffer, num: (int)pFile);
    v10 = (void *)this->Read(
                    this,
                    a2: (void *)(**(_DWORD **)(p_elem + 20)
                           + *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 16)
                           - *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 32)),
                    a3: (int)pFile,
                    a4: v5);
    if ( v10 != pFile )
      break;
    CUtlBuffer::SeekPut(this: *(CUtlBuffer **)(p_elem + 20), type: SEEK_HEAD, offset: (int)pFile);
    *(_DWORD *)(p_elem + 12) = pFile;
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    {
      v11 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
      _Msg(a1: "SIM: Extracted: %s [Size: %d KB]\n", v11, *(_DWORD *)(p_elem + 12) >> 10);
    }
    if ( ++i >= fileCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CFAD0
// Name: public: virtual bool CSaveRestoreFileSystem::LoadFileFromDisk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystem::LoadFileFromDisk(CSaveRestoreFileSystem *this, const char *pFilename)
{
  int v3; // ebx
  void *v5; // edi
  CSaveDirectory::file_t *p_elem; // esi

  v3 = this->Open(this, a2: pFilename, a3: "wb", a4: nullptr);
  if ( v3 == 0 )
    return 0;
  v5 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: pFilename, a3: "rb", a4: 0, a5: 0, a6: 0);
  if ( v5 == nullptr )
    return 0;
  p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem;
  if ( !g_pFileSystem->ReadToBuffer(this: g_pFileSystem, a2: v5, a3: p_elem->pCompressedBuffer, a4: 0, a5: nullptr) )
    return 0;
  p_elem->nCompressedSize = p_elem->pCompressedBuffer->m_nMaxPut;
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SIM: Loaded %s into memory\n", pFilename);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D0DA0
// Name: private: int CSaveRestoreFileSystem::GetFileIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::GetFileIndex(CSaveRestoreFileSystem *this, const char *filename)
{
  const char *v3; // eax
  const char *v4; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  char pDest[260]; // [esp+4h] [ebp-120h] BYREF
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t search; // [esp+108h] [ebp-1Ch] BYREF

  v3 = V_UnqualifiedFileName(in: filename);
  V_strncpy(pDest, pSrc: v3, maxLen: 260);
  v4 = _V_strlower(start: pDest);
  CUtlSymbolTable::AddString(this: &this->m_pSaveDirectory->m_SymbolTable, result: (CUtlSymbol *)&filename, pString: v4);
  m_pSaveDirectory = this->m_pSaveDirectory;
  search.elem.name.m_Id = -1;
  memset(&search.elem.nSize, 0, 16);
  search.key.m_Id = (unsigned __int16)filename;
  return CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_pSaveDirectory->m_Files.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x101D0E20
// Name: public: virtual bool CSaveRestoreFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystem::FileExists(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  int FileIndex; // eax

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pFileName);
  if ( FileIndex == 0xFFFF )
    FileIndex = 0;
  return FileIndex != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D0E40
// Name: public: virtual void CSaveRestoreFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Close(CSaveRestoreFileSystem *this, void *hFile)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CSaveDirectory::file_t *p_elem; // edi
  const char *v6; // eax
  CUtlBuffer *pBuffer; // esi

  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Files->m_Tree,
           i: (unsigned __int16)hFile) != (_WORD)hFile )
    {
      m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      p_elem = &m_pMemory[(unsigned __int16)hFile].m_Data.elem;
      if ( p_elem->eType != 0 )
      {
        CSaveRestoreFileSystem::Compress(this, pFile: &m_pMemory[(unsigned __int16)hFile].m_Data.elem);
      }
      else
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
        {
          v6 = CUtlSymbolTable::String(
                 this: &this->m_pSaveDirectory->m_SymbolTable,
                 id: m_pMemory[(unsigned __int16)hFile].m_Data.elem.name);
          _Msg(a1: "SIM: Closed file: %s\n", v6);
        }
        pBuffer = p_elem->pBuffer;
        pBuffer->m_Get = 0;
        pBuffer->m_Put = 0;
        pBuffer->m_nOffset = 0;
        pBuffer->m_nMaxPut = 0;
        pBuffer->m_Error = 0;
        if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
        {
          if ( pBuffer->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
            pBuffer->m_Memory.m_pMemory = nullptr;
          }
          pBuffer->m_Memory.m_nAllocationCount = 0;
        }
        p_elem->nSize = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0F30
// Name: public: virtual int CSaveRestoreFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::Read(CSaveRestoreFileSystem *this, void *pOutput, int size, void *hFile)
{
  int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) != (_WORD)hFile )
      {
        if ( this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.eType == 0 )
          return CUtlBuffer::GetUpTo(
                   this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
                   pMem: pOutput,
                   nSize: size);
        _Warning(a1: "Read: Attempted to read from a write-only file");
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D0FB0
// Name: public: virtual int CSaveRestoreFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::Write(CSaveRestoreFileSystem *this, const void *pInput, int size, void *hFile)
{
  int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  CSaveDirectory::file_t *p_elem; // esi

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) != (_WORD)hFile )
      {
        p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem;
        if ( p_elem->eType == 1 )
        {
          CUtlBuffer::Put(
            this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
            pMem: pInput,
            size);
          p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
          return size;
        }
        _Warning(a1: "Write: Attempted to write to a read-only file");
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1040
// Name: public: virtual void CSaveRestoreFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Seek(
        CSaveRestoreFileSystem *this,
        void *hFile,
        int pos,
        FileSystemSeek_t method)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  CSaveDirectory::file_t *p_elem; // eax

  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Files->m_Tree,
           i: (unsigned __int16)hFile) != (_WORD)hFile )
    {
      p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem;
      if ( p_elem->eType != 0 )
      {
        if ( p_elem->eType == 1 )
          CUtlBuffer::SeekPut(
            this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
            type: (CUtlBuffer::SeekType_t)method,
            offset: pos);
      }
      else
      {
        CUtlBuffer::SeekGet(
          this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
          type: (CUtlBuffer::SeekType_t)method,
          offset: pos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D10C0
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Tell(CSaveRestoreFileSystem *this, void *hFile)
{
  unsigned int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int eType; // ecx

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) == (_WORD)hFile )
        return 0;
      m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      eType = m_pMemory[(unsigned __int16)hFile].m_Data.elem.eType;
      if ( eType == 0 )
        return m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer->m_Get;
      if ( eType != 1 )
        return 0;
      else
        return m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer->m_Put;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1140
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Size(CSaveRestoreFileSystem *this, void *hFile)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx

  if ( hFile == nullptr )
    return 0;
  p_m_Files = &this->m_pSaveDirectory->m_Files;
  if ( (unsigned __int16)hFile >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
    || (unsigned __int16)hFile > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_Files->m_Tree,
         i: (unsigned __int16)hFile) == (_WORD)hFile )
  {
    return 0;
  }
  else
  {
    return this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.nSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D11A0
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Size(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  void *FileIndex; // eax

  FileIndex = (void *)CSaveRestoreFileSystem::GetFileIndex(this, filename: pFileName);
  if ( FileIndex == (void *)0xFFFF )
    FileIndex = nullptr;
  return this->Size_2(this, a2: FileIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101D11D0
// Name: public: void CSaveRestoreFileSystem::DirectorCopyToMemory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSaveRestoreFileSystem::DirectorCopyToMemory(
        CSaveRestoreFileSystem *this,
        const char *pPath,
        const char *pDestFileName)
{
  int v4; // eax
  int v5; // edx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  CUtlBuffer *pCompressedBuffer; // edi
  int p_elem; // ebx
  const void **v9; // edx
  unsigned __int16 Inorder; // ax
  int v11; // edi
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *v12; // eax
  CUtlSymbol v13; // cx
  int v14; // edi
  int FileIndex; // eax
  unsigned int nCompressedSize; // eax
  int v17; // edx
  const char *v18; // eax
  const char *v19; // eax
  _BYTE dst[268]; // [esp+14h] [ebp-10Ch] OVERLAPPED BYREF
  unsigned __int16 szFileName_252; // [esp+128h] [ebp+8h]
  int szFileName_256; // [esp+12Ch] [ebp+Ch]

  v4 = this->Open(this, a2: pDestFileName, a3: "ab+", a4: pPath);
  if ( v4 != 0 )
  {
    v5 = (unsigned __int16)v4;
    m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
    pCompressedBuffer = m_pMemory[v5].m_Data.elem.pCompressedBuffer;
    p_elem = (int)&m_pMemory[v5].m_Data.elem;
    pCompressedBuffer->m_Get = 0;
    pCompressedBuffer->m_Put = 0;
    pCompressedBuffer->m_nOffset = 0;
    pCompressedBuffer->m_nMaxPut = 0;
    pCompressedBuffer->m_Error = 0;
    if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
    {
      if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
        pCompressedBuffer->m_Memory.m_pMemory = nullptr;
      }
      pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
    }
    v9 = *(const void ***)(p_elem + 16);
    *(_DWORD *)(p_elem + 12) = 0;
    CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: *v9, size: *(_DWORD *)(p_elem + 8));
    szFileName_256 = 0;
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
    for ( szFileName_252 = Inorder; ; szFileName_252 = Inorder )
    {
      v11 = Inorder;
      if ( Inorder >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || Inorder > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
        || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_pSaveDirectory->m_Files.m_Tree,
             i: Inorder) == szFileName_252 )
      {
        break;
      }
      v12 = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      v13.m_Id = v12[v11].m_Data.elem.name.m_Id;
      v14 = (int)&v12[v11].m_Data.elem;
      *(_DWORD *)&dst[264] = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: v13);
      if ( V_stristr(pStr: *(const char **)&dst[264], pSearch: ".hl") != nullptr )
      {
        FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: *(const char **)&dst[264]);
        if ( FileIndex == 0xFFFF || FileIndex == 0 )
          nCompressedSize = 0;
        else
          nCompressedSize = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)FileIndex].m_Data.elem.nCompressedSize;
        *(_DWORD *)&dst[260] = nCompressedSize;
        if ( nCompressedSize != 0 )
        {
          memset(dst, value: 0, count: 0x104u);
          V_strncpy(pDest: dst, pSrc: *(const char **)&dst[264], maxLen: 260);
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: dst, size: 260);
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: &dst[260], size: 4);
          v17 = *(_DWORD *)(v14 + 12);
          *(_DWORD *)&dst[264] = v14 + 12;
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: **(const void ***)(v14 + 20), size: v17);
          if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
          {
            v18 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(v14 + 4));
            _Msg(
              a1: "SIM: Packed: %s [Size: %.02f KB]\n",
              v18,
              (double)(unsigned int)**(_DWORD **)&dst[264] * 0.0009765625);
          }
          ++szFileName_256;
        }
      }
      Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_pSaveDirectory->m_Files.m_Tree,
                  i: szFileName_252);
    }
    *(_DWORD *)(p_elem + 12) = *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 28);
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    {
      v19 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
      _Msg(
        a1: "SIM: (%s) Total Files Packed: %d [Size: %.02f KB]\n",
        v19,
        szFileName_256,
        (double)*(unsigned int *)(p_elem + 12) * 0.0009765625);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1450
// Name: public: virtual void CSaveRestoreFileSystem::DirectoryCopy(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::DirectoryCopy(
        CSaveRestoreFileSystem *this,
        const char *pPath,
        const char *pDestFileName,
        bool bIsXSave)
{
  int v5; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  unsigned __int16 j; // ax
  unsigned __int16 v8; // si
  int v9; // edi
  const char *v10; // eax
  unsigned __int16 Inorder; // di
  const char *v12; // esi
  int FileIndex; // eax
  char *v14; // eax
  unsigned int *v15; // eax
  CSaveDirectory::file_t *file; // [esp+Ch] [ebp-8h]
  unsigned int nCompressedSize; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  unsigned __int16 ia; // [esp+1Ch] [ebp+8h]

  if ( V_stristr(pStr: pPath, pSearch: "*.hl?") != nullptr )
  {
    if ( saverestore->StorageDeviceValid(this: saverestore) )
    {
      v5 = this->Open(this, a2: pDestFileName, a3: "rb", a4: pPath);
      if ( v5 != 0 )
      {
        m_pSaveDirectory = this->m_pSaveDirectory;
        i = (int)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem;
        for ( j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &m_pSaveDirectory->m_Files.m_Tree);
              ;
              j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &this->m_pSaveDirectory->m_Files.m_Tree,
                    i: v8) )
        {
          v8 = j;
          v9 = j;
          if ( j >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
            || j > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
            || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                 this: &this->m_pSaveDirectory->m_Files.m_Tree,
                 i: j) == j )
          {
            break;
          }
          v10 = CUtlSymbolTable::String(
                  this: &this->m_pSaveDirectory->m_SymbolTable,
                  id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem.name);
          V_stristr(pStr: v10, pSearch: ".hl");
        }
        g_pFileSystem->AsyncWriteFile(
          this: g_pFileSystem,
          a2: pDestFileName,
          a3: *(const CUtlBuffer **)(i + 16),
          a4: *(_DWORD *)(i + 8),
          a5: true,
          a6: false,
          a7: nullptr);
        *(_DWORD *)(i + 16) = 0;
        this->RemoveFile(this, a2: pDestFileName, a3: nullptr);
        Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
        ia = Inorder;
        while ( Inorder < this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
             && Inorder <= this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
             && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                  this: &this->m_pSaveDirectory->m_Files.m_Tree,
                  i: Inorder) != Inorder )
        {
          file = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
          v12 = CUtlSymbolTable::String(
                  this: &this->m_pSaveDirectory->m_SymbolTable,
                  id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem.name);
          if ( V_stristr(pStr: v12, pSearch: ".hl") != nullptr )
          {
            FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: v12);
            if ( FileIndex != 0xFFFF && FileIndex != 0 )
            {
              nCompressedSize = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)FileIndex].m_Data.elem.nCompressedSize;
              if ( nCompressedSize != 0 )
              {
                v14 = (char *)MemAlloc_Alloc(nSize: 0x104u);
                qmemcpy(v14, v12, 0x104u);
                g_pFileSystem->AsyncAppend(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: v14,
                  a4: 260,
                  a5: true,
                  a6: nullptr);
                v15 = (unsigned int *)MemAlloc_Alloc(nSize: 4u);
                if ( v15 != nullptr )
                  *v15 = nCompressedSize;
                else
                  v15 = nullptr;
                g_pFileSystem->AsyncAppend(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: v15,
                  a4: 4,
                  a5: true,
                  a6: nullptr);
                g_pFileSystem->AsyncWriteFile(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: file->pCompressedBuffer,
                  a4: file->nCompressedSize,
                  a5: false,
                  a6: true,
                  a7: nullptr);
                Inorder = ia;
              }
            }
          }
          ia = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                 this: &this->m_pSaveDirectory->m_Files.m_Tree,
                 i: Inorder);
          Inorder = ia;
        }
      }
    }
    else
    {
      CSaveRestoreFileSystem::DirectorCopyToMemory(this, pPath, pDestFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D16C0
// Name: public: virtual int CSaveRestoreFileSystem::DirectoryCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSaveRestoreFileSystem::DirectoryCount(CSaveRestoreFileSystem *this, const char *pPath)
{
  const char *result; // eax
  unsigned __int16 i; // ax
  unsigned __int16 v5; // si
  int v6; // edi
  const char *v7; // eax
  int count; // [esp+14h] [ebp+8h]

  result = V_stristr(pStr: pPath, pSearch: "*.hl?");
  if ( result != nullptr )
  {
    count = 0;
    for ( i = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
          ;
          i = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_pSaveDirectory->m_Files.m_Tree,
                i: v5) )
    {
      v5 = i;
      v6 = i;
      if ( i >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || i > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
        || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_pSaveDirectory->m_Files.m_Tree,
             i) == i )
      {
        break;
      }
      v7 = CUtlSymbolTable::String(
             this: &this->m_pSaveDirectory->m_SymbolTable,
             id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.name);
      if ( V_stristr(pStr: v7, pSearch: ".hl") != nullptr )
        ++count;
    }
    return (const char *)count;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1770
// Name: public: virtual void CSaveRestoreFileSystem::DirectoryClear(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::DirectoryClear(CSaveRestoreFileSystem *this, const char *pPath, bool bIsXSave)
{
  unsigned __int16 Inorder; // bx
  CSaveDirectory *m_pSaveDirectory; // ecx
  int *v6; // ecx
  CSaveDirectory *v7; // ecx
  CUtlSymbol *p_elem; // edi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax

  if ( V_stristr(pStr: pPath, pSearch: "*.hl?") != nullptr )
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
    while ( 1 )
    {
      m_pSaveDirectory = this->m_pSaveDirectory;
      if ( Inorder >= m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || Inorder > m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index )
      {
        break;
      }
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1068F540 = 0x1FFFF;
      }
      v6 = Inorder == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder];
      if ( *(_WORD *)v6 == Inorder )
        break;
      v7 = this->m_pSaveDirectory;
      p_elem = (CUtlSymbol *)&v7->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &v7->m_Files.m_Tree,
                  i: Inorder);
      v9 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
      if ( V_stristr(pStr: v9, pSearch: ".hl") != nullptr )
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
        {
          v10 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
          _Msg(a1: "SIM: Cleared: %s\n", v10);
        }
        v11 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
        this->RemoveFile(this, a2: v11, a3: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D18C0
// Name: public: virtual void CSaveRestoreFileSystem::AuditFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::AuditFiles(CSaveRestoreFileSystem *this)
{
  CSaveRestoreFileSystem *v1; // esi
  unsigned int v2; // ebx
  unsigned __int16 Inorder; // di
  CSaveDirectory *m_pSaveDirectory; // esi
  int *v5; // eax
  CSaveDirectory *v6; // eax
  int p_elem; // esi
  unsigned __int16 v8; // ax
  const char *v9; // eax
  __int128 v10; // [esp-10h] [ebp-34h]
  unsigned __int16 v11; // [esp+10h] [ebp-14h]
  unsigned int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  unsigned int v14; // [esp+1Ch] [ebp-8h]

  v1 = this;
  v2 = 0;
  v13 = 0;
  v14 = 0;
  Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
  while ( 1 )
  {
    m_pSaveDirectory = v1->m_pSaveDirectory;
    if ( Inorder >= m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
      || Inorder > m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index )
    {
      break;
    }
    if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1068F540 = 0x1FFFF;
    }
    v5 = Inorder == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder];
    if ( *(_WORD *)v5 == Inorder )
      break;
    v6 = this->m_pSaveDirectory;
    p_elem = (int)&v6->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    v8 = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
           this: &v6->m_Files.m_Tree,
           i: Inorder);
    v14 += *(_DWORD *)(p_elem + 8);
    ++v13;
    v11 = v8;
    v12 = *(_DWORD *)(p_elem + 12) + v2;
    v9 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
    _Msg(
      a1: "SIM: File: %s [c: %.02f KB / u: %.02f KB]\n",
      v9,
      0.0009765625 * (double)*(unsigned int *)(p_elem + 12),
      (double)*(unsigned int *)(p_elem + 8) * 0.0009765625);
    v2 = v12;
    Inorder = v11;
    v1 = this;
  }
  _Msg(a1: "SIM: ------------------------------------------------------------");
  *((double *)&v10 + 1) = (double)(v14 + v2) * 0.0009765625;
  *(double *)&v10 = (double)v14 * 0.0009765625;
  _Msg(
    a1: "SIM: Total files: %d [c: %.02f KB / c: %d KB] : Total Size: %.02f KB\n",
    v13,
    0.0009765625 * (double)v2,
    (_DWORD)v10,
    *(double *)((char *)&v10 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x101D1B60
// Name: public: void CUtlMap<class CUtlSymbol,struct CSaveDirectory::file_t,unsigned short>::Reinsert(class CUtlSymbol const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Reinsert(
        CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *this,
        int key,
        _BOOL2 i)
{
  unsigned __int16 v3; // bx
  BOOL v5; // edi
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t *p_m_Data; // [esp-Ch] [ebp-18h]
  unsigned __int16 v7; // [esp-4h] [ebp-10h]

  v3 = i;
  v5 = i;
  v7 = i;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Data.key.m_Id = *(_WORD *)key;
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v7);
  if ( v3 != 0xFFFF )
  {
    key = 0xFFFF;
    p_m_Data = &this->m_Tree.m_Elements.m_pMemory[v5].m_Data;
    LOBYTE(i) = 0;
    CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->m_Tree,
      insert: p_m_Data,
      parent: (unsigned __int16 *)&key,
      leftchild: (bool *)&i);
    CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
      this: &this->m_Tree,
      i: v3,
      parent: key,
      isLeft: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1BD0
// Name: public: CSaveDirectory::CSaveDirectory(void)
// Source: json
//------------------------------------------------------------------------------
CSaveDirectory *__thiscall CSaveDirectory::CSaveDirectory(CSaveDirectory *this)
{
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t insert; // [esp+Ch] [ebp-20h] BYREF
  CUtlSymbol v5; // [esp+2Ah] [ebp-2h] BYREF

  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_SymbolTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Files.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Files.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Files.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Files.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_Files.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Files.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Files.m_Tree.m_FirstFree = -1;
  this->m_Files.m_Tree.m_pElements = m_pMemory;
  if ( this->m_Files.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Files.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlSymbol *, const CUtlSymbol *))CDefOps<unsigned short>::LessFunc;
  insert.key = (CUtlSymbol)CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: &v5, pString: "dummy")->m_Id;
  insert.elem.name.m_Id = insert.key.m_Id;
  memset(&insert.elem.nSize, 0, 16);
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Files.m_Tree,
    &insert);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D1C60
// Name: public: CSaveDirectory::~CSaveDirectory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDirectory::~CSaveDirectory(CSaveDirectory *this)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ebx
  unsigned __int16 j; // ax
  int *v3; // ecx
  unsigned __int16 v4; // si
  unsigned __int16 Inorder; // ax
  int v6; // esi
  CUtlBuffer *pBuffer; // edi
  CUtlBuffer *pCompressedBuffer; // edi
  unsigned __int16 idx; // [esp+Ch] [ebp-Ch]
  unsigned __int16 i; // [esp+10h] [ebp-8h]

  p_m_Files = &this->m_Files;
  for ( j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Files.m_Tree);
        j < p_m_Files->m_Tree.m_Elements.m_nAllocationCount && j <= p_m_Files->m_Tree.m_LastAlloc.index;
        j = i )
  {
    if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1068F540 = 0x1FFFF;
    }
    v3 = j == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&p_m_Files->m_Tree.m_Elements.m_pMemory[j];
    if ( *(_WORD *)v3 == j )
      break;
    v4 = j;
    idx = j;
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &p_m_Files->m_Tree,
                i: j);
    v6 = v4;
    pBuffer = this->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.pBuffer;
    i = Inorder;
    if ( pBuffer != nullptr )
    {
      if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
          pBuffer->m_Memory.m_pMemory = nullptr;
        }
        pBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pBuffer);
    }
    pCompressedBuffer = this->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.pCompressedBuffer;
    if ( pCompressedBuffer != nullptr )
    {
      if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
          pCompressedBuffer->m_Memory.m_pMemory = nullptr;
        }
        pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pCompressedBuffer);
    }
    if ( idx != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Files->m_Tree,
        elem: idx);
      p_m_Files->m_Tree.m_Elements.m_pMemory[v6].m_Left = idx;
      p_m_Files->m_Tree.m_Elements.m_pMemory[v6].m_Right = p_m_Files->m_Tree.m_FirstFree;
      --p_m_Files->m_Tree.m_NumElements;
      p_m_Files->m_Tree.m_FirstFree = idx;
    }
  }
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_Files->m_Tree);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x101D1DE0
// Name: public: virtual void CSaveRestoreFileSystem::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::RenameFile(
        CSaveRestoreFileSystem *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  int FileIndex; // eax
  _BOOL2 v6; // di
  const char *v7; // eax
  const char *v8; // eax
  char pDest[260]; // [esp+8h] [ebp-104h] BYREF

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pOldPath);
  v6 = FileIndex;
  if ( FileIndex != 0xFFFF )
  {
    v7 = V_UnqualifiedFileName(in: pNewPath);
    V_strncpy(pDest, pSrc: v7, maxLen: 260);
    v8 = _V_strlower(start: pDest);
    CUtlSymbolTable::AddString(
      this: &this->m_pSaveDirectory->m_SymbolTable,
      result: (CUtlSymbol *)&pOldPath,
      pString: v8);
    this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.name.m_Id = (unsigned __int16)pOldPath;
    CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Reinsert(
      this: &this->m_pSaveDirectory->m_Files,
      key: (int)&pOldPath,
      i: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1E70
// Name: public: virtual void CSaveRestoreFileSystem::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::RemoveFile(
        CSaveRestoreFileSystem *this,
        const char *pRelativePath,
        const char *pathID)
{
  int FileIndex; // ebx
  int v5; // edi
  CUtlBuffer *pBuffer; // esi
  CUtlBuffer *pCompressedBuffer; // esi
  CSaveDirectory *m_pSaveDirectory; // esi

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pRelativePath);
  if ( FileIndex != 0xFFFF )
  {
    v5 = (unsigned __int16)FileIndex;
    pBuffer = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.pBuffer;
    if ( pBuffer != nullptr )
    {
      if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
          pBuffer->m_Memory.m_pMemory = nullptr;
        }
        pBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pBuffer);
    }
    pCompressedBuffer = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.pCompressedBuffer;
    if ( pCompressedBuffer != nullptr )
    {
      if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
          pCompressedBuffer->m_Memory.m_pMemory = nullptr;
        }
        pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pCompressedBuffer);
    }
    m_pSaveDirectory = this->m_pSaveDirectory;
    if ( (_WORD)FileIndex != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &m_pSaveDirectory->m_Files.m_Tree,
        elem: FileIndex);
      m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Left = FileIndex;
      m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Right = m_pSaveDirectory->m_Files.m_Tree.m_FirstFree;
      --m_pSaveDirectory->m_Files.m_Tree.m_NumElements;
      m_pSaveDirectory->m_Files.m_Tree.m_FirstFree = FileIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1F70
// Name: public: virtual void __near * CSaveRestoreFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSaveRestoreFileSystem::Open(
        CSaveRestoreFileSystem *this,
        const char *pFullName,
        const char *pOptions,
        const char *pathID)
{
  const char *v5; // eax
  const char *v6; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  int v8; // eax
  CUtlBuffer *v9; // eax
  CUtlBuffer *v10; // edi
  CUtlBuffer *v11; // eax
  CUtlBuffer *v12; // eax
  CSaveDirectory *v13; // ecx
  CSaveDirectory::file_t *p_elem; // edi
  void *result; // eax
  CUtlBuffer *pBuffer; // ecx
  CUtlBuffer *v17; // ecx
  char pDest[260]; // [esp+Ch] [ebp-15Ch] BYREF
  CSaveDirectory::file_t newFile; // [esp+110h] [ebp-58h]
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t search; // [esp+128h] [ebp-40h] BYREF
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t insert; // [esp+144h] [ebp-24h] BYREF
  int idx; // [esp+160h] [ebp-8h]
  CUtlSymbol id; // [esp+164h] [ebp-4h] BYREF

  v5 = V_UnqualifiedFileName(in: pFullName);
  V_strncpy(pDest, pSrc: v5, maxLen: 260);
  v6 = _V_strlower(start: pDest);
  CUtlSymbolTable::AddString(this: &this->m_pSaveDirectory->m_SymbolTable, result: &id, pString: v6);
  m_pSaveDirectory = this->m_pSaveDirectory;
  search.elem.name.m_Id = -1;
  memset(&search.elem.nSize, 0, 16);
  search.key = id;
  v8 = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &m_pSaveDirectory->m_Files.m_Tree,
         &search);
  idx = v8;
  if ( (unsigned __int16)v8 == 0xFFFF )
  {
    if ( _V_stricmp(s1: pOptions, s2: "rb") == 0 )
      return nullptr;
    newFile.name = id;
    v9 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v9 != nullptr )
      v10 = CUtlBuffer::CUtlBuffer(this: v9, growSize: 0, initSize: 0, nFlags: 0);
    else
      v10 = nullptr;
    v11 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v11 != nullptr )
      v12 = CUtlBuffer::CUtlBuffer(this: v11, growSize: 0, initSize: 0, nFlags: 0);
    else
      v12 = nullptr;
    v13 = this->m_pSaveDirectory;
    insert.key = id;
    insert.elem.eType = newFile.eType;
    insert.elem.pCompressedBuffer = v12;
    insert.elem.name.m_Id = newFile.name.m_Id;
    insert.elem.nSize = 0;
    insert.elem.nCompressedSize = 0;
    insert.elem.pBuffer = v10;
    LOWORD(v8) = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                   this: &v13->m_Files.m_Tree,
                   &insert);
    idx = (unsigned __int16)v8;
  }
  p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem;
  if ( _V_stricmp(s1: pOptions, s2: "rb") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    result = (void *)idx;
    p_elem->eType = 0;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "wb") == 0 )
  {
    pBuffer = p_elem->pBuffer;
    pBuffer->m_Get = 0;
    pBuffer->m_Put = 0;
    pBuffer->m_Error = 0;
    pBuffer->m_nOffset = 0;
    pBuffer->m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: pBuffer, nPut: 0);
    result = (void *)idx;
    p_elem->eType = 1;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "a") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    result = (void *)idx;
    p_elem->eType = 1;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "ab+") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    v17 = p_elem->pBuffer;
    p_elem->eType = 1;
    CUtlBuffer::SeekPut(this: v17, type: SEEK_TAIL, offset: 0);
    return (void *)idx;
  }
  _Warning(a1: "CSaveRestoreFileSystem: Attempted to open %s with unsupported option %s\n", pFullName, pOptions);
  return nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CED30
// Name: void SaveInMemoryCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveInMemoryCallback()
{
  _Warning(a1: "save_in_memory is compatible with only the Xbox 360!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101CEED0
// Name: public: void CSaveRestoreFileSystem::Compress(struct CSaveDirectory::file_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSaveRestoreFileSystem::Compress(CSaveRestoreFileSystem *this, CSaveDirectory::file_t *pFile)
{
  CUtlBuffer *pCompressedBuffer; // edi
  CUtlBuffer *pBuffer; // ecx
  unsigned int nSize; // edx
  int *p_nCompressedSize; // edi
  unsigned __int8 *v7; // eax
  CUtlBuffer *v8; // edi
  unsigned int v9; // edi
  unsigned int nCompressedSize; // eax
  const char *v11; // eax
  CLZSS v12; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch]
  unsigned int v14; // [esp+20h] [ebp-8h]
  CSaveRestoreFileSystem *compressor; // [esp+24h] [ebp-4h] OVERLAPPED
  float destBytes; // [esp+30h] [ebp+8h]

  pCompressedBuffer = pFile->pCompressedBuffer;
  compressor = this;
  pCompressedBuffer->m_Get = 0;
  pCompressedBuffer->m_Put = 0;
  pCompressedBuffer->m_nOffset = 0;
  pCompressedBuffer->m_nMaxPut = 0;
  pCompressedBuffer->m_Error = 0;
  if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
      pCompressedBuffer->m_Memory.m_pMemory = nullptr;
    }
    pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
  }
  pBuffer = pFile->pBuffer;
  nSize = pFile->nSize;
  p_nCompressedSize = (int *)&pFile->nCompressedSize;
  v13 = 2048;
  v7 = CLZSS::Compress(
         this: (CLZSS *)&v12.m_pHashTarget,
         pInput: pBuffer->m_Memory.m_pMemory,
         inputLength: nSize,
         pOutputSize: &pFile->nCompressedSize);
  if ( v7 != nullptr )
  {
    CUtlBuffer::AssumeMemory(
      this: pFile->pCompressedBuffer,
      pMemory: v7,
      nSize: *p_nCompressedSize,
      nInitialPut: *p_nCompressedSize,
      nFlags: 0);
  }
  else
  {
    CUtlBuffer::Put(this: pFile->pCompressedBuffer, pMem: pFile->pBuffer->m_Memory.m_pMemory, size: pFile->nSize);
    *p_nCompressedSize = pFile->nSize;
  }
  CUtlBuffer::SeekGet(this: pFile->pCompressedBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::SeekPut(this: pFile->pCompressedBuffer, type: SEEK_HEAD, offset: *p_nCompressedSize);
  v8 = pFile->pBuffer;
  v8->m_Get = 0;
  v8->m_Put = 0;
  v8->m_nOffset = 0;
  v8->m_nMaxPut = 0;
  v8->m_Error = 0;
  if ( v8->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Memory.m_pMemory);
      v8->m_Memory.m_pMemory = nullptr;
    }
    v8->m_Memory.m_nAllocationCount = 0;
  }
  v9 = pFile->nSize;
  nCompressedSize = pFile->nCompressedSize;
  pFile->nSize = 0;
  v14 = nCompressedSize;
  destBytes = 0.0;
  if ( v9 != 0 )
    destBytes = (1.0 - (double)nCompressedSize / (double)v9) * 100.0;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = CUtlSymbolTable::String(this: &compressor->m_pSaveDirectory->m_SymbolTable, id: pFile->name);
    _Msg(a1: "SIM: SaveDir: (%s) Compressed %d bytes to %d bytes. (%.0f%%)\n", v11, v9, v14, destBytes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CF040
// Name: public: void CSaveRestoreFileSystem::Uncompress(struct CSaveDirectory::file_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Uncompress(CSaveRestoreFileSystem *this, CSaveDirectory::file_t *pFile)
{
  CUtlBuffer *pBuffer; // edi
  CUtlBuffer *pCompressedBuffer; // ecx
  unsigned int ActualSize; // eax
  unsigned __int8 *v5; // edi
  int v6; // eax
  CUtlBuffer *v7; // ecx
  unsigned int nCompressedSize; // edi
  unsigned int nSize; // ebx
  const char *v10; // eax
  CLZSS compressor; // [esp+Ch] [ebp-10h] BYREF
  CSaveRestoreFileSystem *v12; // [esp+18h] [ebp-4h]

  pBuffer = pFile->pBuffer;
  v12 = this;
  pBuffer->m_Get = 0;
  pBuffer->m_Put = 0;
  pBuffer->m_nOffset = 0;
  pBuffer->m_nMaxPut = 0;
  pBuffer->m_Error = 0;
  if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( pBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
      pBuffer->m_Memory.m_pMemory = nullptr;
    }
    pBuffer->m_Memory.m_nAllocationCount = 0;
  }
  pCompressedBuffer = pFile->pCompressedBuffer;
  compressor.m_nWindowSize = 4096;
  ActualSize = CLZSS::GetActualSize(this: &compressor, pInput: pCompressedBuffer->m_Memory.m_pMemory);
  if ( ActualSize != 0 )
  {
    v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: ActualSize);
    v6 = CLZSS::Uncompress(this: &compressor, pInput: pFile->pCompressedBuffer->m_Memory.m_pMemory, pOutput: v5);
    CUtlBuffer::AssumeMemory(this: pFile->pBuffer, pMemory: v5, nSize: v6, nInitialPut: v6, nFlags: 0);
  }
  else
  {
    CUtlBuffer::Put(
      this: pFile->pBuffer,
      pMem: pFile->pCompressedBuffer->m_Memory.m_pMemory,
      size: pFile->nCompressedSize);
  }
  v7 = pFile->pBuffer;
  pFile->nSize = v7->m_nMaxPut;
  CUtlBuffer::SeekGet(this: v7, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::SeekPut(this: pFile->pBuffer, type: SEEK_HEAD, offset: pFile->nSize);
  nCompressedSize = pFile->nCompressedSize;
  nSize = pFile->nSize;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = CUtlSymbolTable::String(this: &v12->m_pSaveDirectory->m_SymbolTable, id: pFile->name);
    _Msg(a1: "SIM: SaveDir: (%s) Uncompressed %d bytes to %d bytes.\n", v10, nCompressedSize, nSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFC50
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::AsyncWrite(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  int v8; // ebx
  int v9; // eax
  CSaveDirectory::file_t *p_elem; // esi

  v8 = -5;
  v9 = this->Open(this, a2: pFileName, a3: "wb", a4: nullptr);
  if ( v9 != 0 )
  {
    p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.elem;
    if ( p_elem->eType == 1 )
    {
      CUtlBuffer::Put(
        this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.elem.pBuffer,
        pMem: pSrc,
        size: nSrcBytes);
      p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
      CSaveRestoreFileSystem::Compress(this, pFile: p_elem);
      v8 = 0;
    }
    else
    {
      _Warning(a1: "AsyncWrite: Attempted to write to a read-only file");
    }
  }
  if ( bFreeMemory )
    free(pMem: pSrc);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101CFCE0
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::AsyncAppend(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  int v7; // ebx
  int v8; // eax
  CSaveDirectory::file_t *p_elem; // esi

  v7 = -5;
  v8 = this->Open(this, a2: pFileName, a3: "a", a4: nullptr);
  if ( v8 != 0 )
  {
    p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem;
    if ( p_elem->eType == 1 )
    {
      CUtlBuffer::Put(
        this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.pBuffer,
        pMem: pSrc,
        size: nSrcBytes);
      p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
      CSaveRestoreFileSystem::Compress(this, pFile: p_elem);
      v7 = 0;
    }
    else
    {
      _Warning(a1: "AsyncAppend: Attempted to write to a read-only file");
    }
  }
  if ( bFreeMemory )
    free(pMem: pSrc);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101CFD70
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystem::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystem::AsyncAppendFile(
        CSaveRestoreFileSystem *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  int v5; // eax

  v5 = this->Open(this, a2: pSrcFileName, a3: "rb", a4: nullptr);
  if ( v5 != 0 )
    return this->AsyncAppend(
             this,
             a2: pDestFileName,
             a3: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem.pBuffer->m_Memory.m_pMemory,
             a4: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem.nSize,
             a5: false,
             a6: nullptr);
  else
    return FSASYNC_ERR_FILEOPEN;
}

//------------------------------------------------------------------------------
// Address: 0x101CFDD0
// Name: public: virtual bool CSaveRestoreFileSystem::DirectoryExtract(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystem::DirectoryExtract(
        CSaveRestoreFileSystem *this,
        void *pFile,
        int fileCount,
        bool bIsXSave)
{
  void *v5; // ebx
  int v6; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v8; // eax
  int p_elem; // edi
  void *v10; // eax
  const char *v11; // eax
  char fileName[260]; // [esp+Ch] [ebp-108h] BYREF
  int i; // [esp+110h] [ebp-4h]

  i = 0;
  if ( fileCount <= 0 )
    return 1;
  v5 = pFile;
  while ( 1 )
  {
    this->Read(this, a2: fileName, a3: 260, a4: v5);
    this->Read(this, a2: &pFile, a3: 4, a4: v5);
    if ( pFile == nullptr )
      break;
    v6 = this->Open(this, a2: fileName, a3: "wb", a4: nullptr);
    if ( v6 == 0 )
      break;
    m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
    v8 = (unsigned __int16)v6;
    p_elem = (int)&m_pMemory[v8].m_Data.elem;
    CUtlBuffer::EnsureCapacity(this: m_pMemory[v8].m_Data.elem.pCompressedBuffer, num: (int)pFile);
    v10 = (void *)this->Read(
                    this,
                    a2: (void *)(**(_DWORD **)(p_elem + 20)
                           + *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 16)
                           - *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 32)),
                    a3: (int)pFile,
                    a4: v5);
    if ( v10 != pFile )
      break;
    CUtlBuffer::SeekPut(this: *(CUtlBuffer **)(p_elem + 20), type: SEEK_HEAD, offset: (int)pFile);
    *(_DWORD *)(p_elem + 12) = pFile;
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    {
      v11 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
      _Msg(a1: "SIM: Extracted: %s [Size: %d KB]\n", v11, *(_DWORD *)(p_elem + 12) >> 10);
    }
    if ( ++i >= fileCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CFEF0
// Name: public: virtual bool CSaveRestoreFileSystem::LoadFileFromDisk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystem::LoadFileFromDisk(CSaveRestoreFileSystem *this, const char *pFilename)
{
  int v3; // ebx
  void *v5; // edi
  CSaveDirectory::file_t *p_elem; // esi

  v3 = this->Open(this, a2: pFilename, a3: "wb", a4: nullptr);
  if ( v3 == 0 )
    return 0;
  v5 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: pFilename, a3: "rb", a4: 0, a5: 0, a6: 0);
  if ( v5 == nullptr )
    return 0;
  p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem;
  if ( !g_pFileSystem->ReadToBuffer(this: g_pFileSystem, a2: v5, a3: p_elem->pCompressedBuffer, a4: 0, a5: nullptr) )
    return 0;
  p_elem->nCompressedSize = p_elem->pCompressedBuffer->m_nMaxPut;
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SIM: Loaded %s into memory\n", pFilename);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D11C0
// Name: private: int CSaveRestoreFileSystem::GetFileIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::GetFileIndex(CSaveRestoreFileSystem *this, const char *filename)
{
  const char *v3; // eax
  const char *v4; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  char pDest[260]; // [esp+4h] [ebp-120h] BYREF
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t search; // [esp+108h] [ebp-1Ch] BYREF

  v3 = V_UnqualifiedFileName(in: filename);
  V_strncpy(pDest, pSrc: v3, maxLen: 260);
  v4 = _V_strlower(start: pDest);
  CUtlSymbolTable::AddString(this: &this->m_pSaveDirectory->m_SymbolTable, result: (CUtlSymbol *)&filename, pString: v4);
  m_pSaveDirectory = this->m_pSaveDirectory;
  search.elem.name.m_Id = -1;
  memset(&search.elem.nSize, 0, 16);
  search.key.m_Id = (unsigned __int16)filename;
  return CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_pSaveDirectory->m_Files.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x101D1240
// Name: public: virtual bool CSaveRestoreFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystem::FileExists(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  int FileIndex; // eax

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pFileName);
  if ( FileIndex == 0xFFFF )
    FileIndex = 0;
  return FileIndex != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D1260
// Name: public: virtual void CSaveRestoreFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Close(CSaveRestoreFileSystem *this, void *hFile)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CSaveDirectory::file_t *p_elem; // edi
  const char *v6; // eax
  CUtlBuffer *pBuffer; // esi

  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Files->m_Tree,
           i: (unsigned __int16)hFile) != (_WORD)hFile )
    {
      m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      p_elem = &m_pMemory[(unsigned __int16)hFile].m_Data.elem;
      if ( p_elem->eType != 0 )
      {
        CSaveRestoreFileSystem::Compress(this, pFile: &m_pMemory[(unsigned __int16)hFile].m_Data.elem);
      }
      else
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
        {
          v6 = CUtlSymbolTable::String(
                 this: &this->m_pSaveDirectory->m_SymbolTable,
                 id: m_pMemory[(unsigned __int16)hFile].m_Data.elem.name);
          _Msg(a1: "SIM: Closed file: %s\n", v6);
        }
        pBuffer = p_elem->pBuffer;
        pBuffer->m_Get = 0;
        pBuffer->m_Put = 0;
        pBuffer->m_nOffset = 0;
        pBuffer->m_nMaxPut = 0;
        pBuffer->m_Error = 0;
        if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
        {
          if ( pBuffer->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
            pBuffer->m_Memory.m_pMemory = nullptr;
          }
          pBuffer->m_Memory.m_nAllocationCount = 0;
        }
        p_elem->nSize = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1350
// Name: public: virtual int CSaveRestoreFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::Read(CSaveRestoreFileSystem *this, void *pOutput, int size, void *hFile)
{
  int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) != (_WORD)hFile )
      {
        if ( this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.eType == 0 )
          return CUtlBuffer::GetUpTo(
                   this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
                   pMem: pOutput,
                   nSize: size);
        _Warning(a1: "Read: Attempted to read from a write-only file");
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D13D0
// Name: public: virtual int CSaveRestoreFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystem::Write(CSaveRestoreFileSystem *this, const void *pInput, int size, void *hFile)
{
  int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  CSaveDirectory::file_t *p_elem; // esi

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) != (_WORD)hFile )
      {
        p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem;
        if ( p_elem->eType == 1 )
        {
          CUtlBuffer::Put(
            this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
            pMem: pInput,
            size);
          p_elem->nSize = p_elem->pBuffer->m_nMaxPut;
          return size;
        }
        _Warning(a1: "Write: Attempted to write to a read-only file");
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1460
// Name: public: virtual void CSaveRestoreFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::Seek(
        CSaveRestoreFileSystem *this,
        void *hFile,
        int pos,
        FileSystemSeek_t method)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  CSaveDirectory::file_t *p_elem; // eax

  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Files->m_Tree,
           i: (unsigned __int16)hFile) != (_WORD)hFile )
    {
      p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem;
      if ( p_elem->eType != 0 )
      {
        if ( p_elem->eType == 1 )
          CUtlBuffer::SeekPut(
            this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
            type: (CUtlBuffer::SeekType_t)method,
            offset: pos);
      }
      else
      {
        CUtlBuffer::SeekGet(
          this: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer,
          type: (CUtlBuffer::SeekType_t)method,
          offset: pos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D14E0
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Tell(CSaveRestoreFileSystem *this, void *hFile)
{
  unsigned int result; // eax
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int eType; // ecx

  result = 0;
  if ( hFile != nullptr )
  {
    p_m_Files = &this->m_pSaveDirectory->m_Files;
    if ( (unsigned __int16)hFile < p_m_Files->m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)hFile <= p_m_Files->m_Tree.m_LastAlloc.index )
    {
      if ( CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &p_m_Files->m_Tree,
             i: (unsigned __int16)hFile) == (_WORD)hFile )
        return 0;
      m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      eType = m_pMemory[(unsigned __int16)hFile].m_Data.elem.eType;
      if ( eType == 0 )
        return m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer->m_Get;
      if ( eType != 1 )
        return 0;
      else
        return m_pMemory[(unsigned __int16)hFile].m_Data.elem.pBuffer->m_Put;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1560
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Size(CSaveRestoreFileSystem *this, void *hFile)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ecx

  if ( hFile == nullptr )
    return 0;
  p_m_Files = &this->m_pSaveDirectory->m_Files;
  if ( (unsigned __int16)hFile >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
    || (unsigned __int16)hFile > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_Files->m_Tree,
         i: (unsigned __int16)hFile) == (_WORD)hFile )
  {
    return 0;
  }
  else
  {
    return this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)hFile].m_Data.elem.nSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D15C0
// Name: public: virtual unsigned int CSaveRestoreFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystem::Size(
        CSaveRestoreFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  void *FileIndex; // eax

  FileIndex = (void *)CSaveRestoreFileSystem::GetFileIndex(this, filename: pFileName);
  if ( FileIndex == (void *)0xFFFF )
    FileIndex = nullptr;
  return this->Size_2(this, a2: FileIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101D15F0
// Name: public: void CSaveRestoreFileSystem::DirectorCopyToMemory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSaveRestoreFileSystem::DirectorCopyToMemory(
        CSaveRestoreFileSystem *this,
        const char *pPath,
        const char *pDestFileName)
{
  int v4; // eax
  int v5; // edx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  CUtlBuffer *pCompressedBuffer; // edi
  int p_elem; // ebx
  const void **v9; // edx
  unsigned __int16 Inorder; // ax
  int v11; // edi
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *v12; // eax
  CUtlSymbol v13; // cx
  int v14; // edi
  int FileIndex; // eax
  unsigned int nCompressedSize; // eax
  int v17; // edx
  const char *v18; // eax
  const char *v19; // eax
  _BYTE dst[268]; // [esp+14h] [ebp-10Ch] OVERLAPPED BYREF
  unsigned __int16 szFileName_252; // [esp+128h] [ebp+8h]
  int szFileName_256; // [esp+12Ch] [ebp+Ch]

  v4 = this->Open(this, a2: pDestFileName, a3: "ab+", a4: pPath);
  if ( v4 != 0 )
  {
    v5 = (unsigned __int16)v4;
    m_pMemory = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
    pCompressedBuffer = m_pMemory[v5].m_Data.elem.pCompressedBuffer;
    p_elem = (int)&m_pMemory[v5].m_Data.elem;
    pCompressedBuffer->m_Get = 0;
    pCompressedBuffer->m_Put = 0;
    pCompressedBuffer->m_nOffset = 0;
    pCompressedBuffer->m_nMaxPut = 0;
    pCompressedBuffer->m_Error = 0;
    if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
    {
      if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
        pCompressedBuffer->m_Memory.m_pMemory = nullptr;
      }
      pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
    }
    v9 = *(const void ***)(p_elem + 16);
    *(_DWORD *)(p_elem + 12) = 0;
    CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: *v9, size: *(_DWORD *)(p_elem + 8));
    szFileName_256 = 0;
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
    for ( szFileName_252 = Inorder; ; szFileName_252 = Inorder )
    {
      v11 = Inorder;
      if ( Inorder >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || Inorder > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
        || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_pSaveDirectory->m_Files.m_Tree,
             i: Inorder) == szFileName_252 )
      {
        break;
      }
      v12 = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory;
      v13.m_Id = v12[v11].m_Data.elem.name.m_Id;
      v14 = (int)&v12[v11].m_Data.elem;
      *(_DWORD *)&dst[264] = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: v13);
      if ( V_stristr(pStr: *(const char **)&dst[264], pSearch: ".hl") != nullptr )
      {
        FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: *(const char **)&dst[264]);
        if ( FileIndex == 0xFFFF || FileIndex == 0 )
          nCompressedSize = 0;
        else
          nCompressedSize = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)FileIndex].m_Data.elem.nCompressedSize;
        *(_DWORD *)&dst[260] = nCompressedSize;
        if ( nCompressedSize != 0 )
        {
          memset(dst, value: 0, count: 0x104u);
          V_strncpy(pDest: dst, pSrc: *(const char **)&dst[264], maxLen: 260);
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: dst, size: 260);
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: &dst[260], size: 4);
          v17 = *(_DWORD *)(v14 + 12);
          *(_DWORD *)&dst[264] = v14 + 12;
          CUtlBuffer::Put(this: *(CUtlBuffer **)(p_elem + 20), pMem: **(const void ***)(v14 + 20), size: v17);
          if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
          {
            v18 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(v14 + 4));
            _Msg(
              a1: "SIM: Packed: %s [Size: %.02f KB]\n",
              v18,
              (double)(unsigned int)**(_DWORD **)&dst[264] * 0.0009765625);
          }
          ++szFileName_256;
        }
      }
      Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_pSaveDirectory->m_Files.m_Tree,
                  i: szFileName_252);
    }
    *(_DWORD *)(p_elem + 12) = *(_DWORD *)(*(_DWORD *)(p_elem + 20) + 28);
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    {
      v19 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
      _Msg(
        a1: "SIM: (%s) Total Files Packed: %d [Size: %.02f KB]\n",
        v19,
        szFileName_256,
        (double)*(unsigned int *)(p_elem + 12) * 0.0009765625);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1870
// Name: public: virtual void CSaveRestoreFileSystem::DirectoryCopy(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::DirectoryCopy(
        CSaveRestoreFileSystem *this,
        const char *pPath,
        const char *pDestFileName,
        bool bIsXSave)
{
  int v5; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  unsigned __int16 j; // ax
  unsigned __int16 v8; // si
  int v9; // edi
  const char *v10; // eax
  unsigned __int16 Inorder; // di
  const char *v12; // esi
  int FileIndex; // eax
  char *v14; // eax
  unsigned int *v15; // eax
  CSaveDirectory::file_t *file; // [esp+Ch] [ebp-8h]
  unsigned int nCompressedSize; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  unsigned __int16 ia; // [esp+1Ch] [ebp+8h]

  if ( V_stristr(pStr: pPath, pSearch: "*.hl?") != nullptr )
  {
    if ( saverestore->StorageDeviceValid(this: saverestore) )
    {
      v5 = this->Open(this, a2: pDestFileName, a3: "rb", a4: pPath);
      if ( v5 != 0 )
      {
        m_pSaveDirectory = this->m_pSaveDirectory;
        i = (int)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem;
        for ( j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &m_pSaveDirectory->m_Files.m_Tree);
              ;
              j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &this->m_pSaveDirectory->m_Files.m_Tree,
                    i: v8) )
        {
          v8 = j;
          v9 = j;
          if ( j >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
            || j > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
            || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                 this: &this->m_pSaveDirectory->m_Files.m_Tree,
                 i: j) == j )
          {
            break;
          }
          v10 = CUtlSymbolTable::String(
                  this: &this->m_pSaveDirectory->m_SymbolTable,
                  id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem.name);
          V_stristr(pStr: v10, pSearch: ".hl");
        }
        g_pFileSystem->AsyncWriteFile(
          this: g_pFileSystem,
          a2: pDestFileName,
          a3: *(const CUtlBuffer **)(i + 16),
          a4: *(_DWORD *)(i + 8),
          a5: true,
          a6: false,
          a7: nullptr);
        *(_DWORD *)(i + 16) = 0;
        this->RemoveFile(this, a2: pDestFileName, a3: nullptr);
        Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
        ia = Inorder;
        while ( Inorder < this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
             && Inorder <= this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
             && CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                  this: &this->m_pSaveDirectory->m_Files.m_Tree,
                  i: Inorder) != Inorder )
        {
          file = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
          v12 = CUtlSymbolTable::String(
                  this: &this->m_pSaveDirectory->m_SymbolTable,
                  id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem.name);
          if ( V_stristr(pStr: v12, pSearch: ".hl") != nullptr )
          {
            FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: v12);
            if ( FileIndex != 0xFFFF && FileIndex != 0 )
            {
              nCompressedSize = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)FileIndex].m_Data.elem.nCompressedSize;
              if ( nCompressedSize != 0 )
              {
                v14 = (char *)MemAlloc_Alloc(nSize: 0x104u);
                qmemcpy(v14, v12, 0x104u);
                g_pFileSystem->AsyncAppend(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: v14,
                  a4: 260,
                  a5: true,
                  a6: nullptr);
                v15 = (unsigned int *)MemAlloc_Alloc(nSize: 4u);
                if ( v15 != nullptr )
                  *v15 = nCompressedSize;
                else
                  v15 = nullptr;
                g_pFileSystem->AsyncAppend(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: v15,
                  a4: 4,
                  a5: true,
                  a6: nullptr);
                g_pFileSystem->AsyncWriteFile(
                  this: g_pFileSystem,
                  a2: pDestFileName,
                  a3: file->pCompressedBuffer,
                  a4: file->nCompressedSize,
                  a5: false,
                  a6: true,
                  a7: nullptr);
                Inorder = ia;
              }
            }
          }
          ia = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                 this: &this->m_pSaveDirectory->m_Files.m_Tree,
                 i: Inorder);
          Inorder = ia;
        }
      }
    }
    else
    {
      CSaveRestoreFileSystem::DirectorCopyToMemory(this, pPath, pDestFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1AE0
// Name: public: virtual int CSaveRestoreFileSystem::DirectoryCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSaveRestoreFileSystem::DirectoryCount(CSaveRestoreFileSystem *this, const char *pPath)
{
  const char *result; // eax
  unsigned __int16 i; // ax
  unsigned __int16 v5; // si
  int v6; // edi
  const char *v7; // eax
  int count; // [esp+14h] [ebp+8h]

  result = V_stristr(pStr: pPath, pSearch: "*.hl?");
  if ( result != nullptr )
  {
    count = 0;
    for ( i = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
          ;
          i = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_pSaveDirectory->m_Files.m_Tree,
                i: v5) )
    {
      v5 = i;
      v6 = i;
      if ( i >= this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || i > this->m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index
        || CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_pSaveDirectory->m_Files.m_Tree,
             i) == i )
      {
        break;
      }
      v7 = CUtlSymbolTable::String(
             this: &this->m_pSaveDirectory->m_SymbolTable,
             id: this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.name);
      if ( V_stristr(pStr: v7, pSearch: ".hl") != nullptr )
        ++count;
    }
    return (const char *)count;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1B90
// Name: public: virtual void CSaveRestoreFileSystem::DirectoryClear(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::DirectoryClear(CSaveRestoreFileSystem *this, const char *pPath, bool bIsXSave)
{
  unsigned __int16 Inorder; // bx
  CSaveDirectory *m_pSaveDirectory; // ecx
  int *v6; // ecx
  CSaveDirectory *v7; // ecx
  CUtlSymbol *p_elem; // edi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax

  if ( V_stristr(pStr: pPath, pSearch: "*.hl?") != nullptr )
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
    while ( 1 )
    {
      m_pSaveDirectory = this->m_pSaveDirectory;
      if ( Inorder >= m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
        || Inorder > m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index )
      {
        break;
      }
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1068F540 = 0x1FFFF;
      }
      v6 = Inorder == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder];
      if ( *(_WORD *)v6 == Inorder )
        break;
      v7 = this->m_pSaveDirectory;
      p_elem = (CUtlSymbol *)&v7->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &v7->m_Files.m_Tree,
                  i: Inorder);
      v9 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
      if ( V_stristr(pStr: v9, pSearch: ".hl") != nullptr )
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
        {
          v10 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
          _Msg(a1: "SIM: Cleared: %s\n", v10);
        }
        v11 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: p_elem[2]);
        this->RemoveFile(this, a2: v11, a3: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1CE0
// Name: public: virtual void CSaveRestoreFileSystem::AuditFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::AuditFiles(CSaveRestoreFileSystem *this)
{
  CSaveRestoreFileSystem *v1; // esi
  unsigned int v2; // ebx
  unsigned __int16 Inorder; // di
  CSaveDirectory *m_pSaveDirectory; // esi
  int *v5; // eax
  CSaveDirectory *v6; // eax
  int p_elem; // esi
  unsigned __int16 v8; // ax
  const char *v9; // eax
  __int128 v10; // [esp-10h] [ebp-34h]
  unsigned __int16 v11; // [esp+10h] [ebp-14h]
  unsigned int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  unsigned int v14; // [esp+1Ch] [ebp-8h]

  v1 = this;
  v2 = 0;
  v13 = 0;
  v14 = 0;
  Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pSaveDirectory->m_Files.m_Tree);
  while ( 1 )
  {
    m_pSaveDirectory = v1->m_pSaveDirectory;
    if ( Inorder >= m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_nAllocationCount
      || Inorder > m_pSaveDirectory->m_Files.m_Tree.m_LastAlloc.index )
    {
      break;
    }
    if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1068F540 = 0x1FFFF;
    }
    v5 = Inorder == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[Inorder];
    if ( *(_WORD *)v5 == Inorder )
      break;
    v6 = this->m_pSaveDirectory;
    p_elem = (int)&v6->m_Files.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    v8 = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
           this: &v6->m_Files.m_Tree,
           i: Inorder);
    v14 += *(_DWORD *)(p_elem + 8);
    ++v13;
    v11 = v8;
    v12 = *(_DWORD *)(p_elem + 12) + v2;
    v9 = CUtlSymbolTable::String(this: &this->m_pSaveDirectory->m_SymbolTable, id: *(CUtlSymbol *)(p_elem + 4));
    _Msg(
      a1: "SIM: File: %s [c: %.02f KB / u: %.02f KB]\n",
      v9,
      0.0009765625 * (double)*(unsigned int *)(p_elem + 12),
      (double)*(unsigned int *)(p_elem + 8) * 0.0009765625);
    v2 = v12;
    Inorder = v11;
    v1 = this;
  }
  _Msg(a1: "SIM: ------------------------------------------------------------");
  *((double *)&v10 + 1) = (double)(v14 + v2) * 0.0009765625;
  *(double *)&v10 = (double)v14 * 0.0009765625;
  _Msg(
    a1: "SIM: Total files: %d [c: %.02f KB / c: %d KB] : Total Size: %.02f KB\n",
    v13,
    0.0009765625 * (double)v2,
    (_DWORD)v10,
    *(double *)((char *)&v10 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x101D1F80
// Name: public: void CUtlMap<class CUtlSymbol,struct CSaveDirectory::file_t,unsigned short>::Reinsert(class CUtlSymbol const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Reinsert(
        CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *this,
        int key,
        _BOOL2 i)
{
  unsigned __int16 v3; // bx
  BOOL v5; // edi
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t *p_m_Data; // [esp-Ch] [ebp-18h]
  unsigned __int16 v7; // [esp-4h] [ebp-10h]

  v3 = i;
  v5 = i;
  v7 = i;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Data.key.m_Id = *(_WORD *)key;
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v7);
  if ( v3 != 0xFFFF )
  {
    key = 0xFFFF;
    p_m_Data = &this->m_Tree.m_Elements.m_pMemory[v5].m_Data;
    LOBYTE(i) = 0;
    CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->m_Tree,
      insert: p_m_Data,
      parent: (unsigned __int16 *)&key,
      leftchild: (bool *)&i);
    CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
      this: &this->m_Tree,
      i: v3,
      parent: key,
      isLeft: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1FF0
// Name: public: CSaveDirectory::CSaveDirectory(void)
// Source: json
//------------------------------------------------------------------------------
CSaveDirectory *__thiscall CSaveDirectory::CSaveDirectory(CSaveDirectory *this)
{
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t insert; // [esp+Ch] [ebp-20h] BYREF
  CUtlSymbol v5; // [esp+2Ah] [ebp-2h] BYREF

  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_SymbolTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Files.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Files.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Files.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Files.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_Files.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Files.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Files.m_Tree.m_FirstFree = -1;
  this->m_Files.m_Tree.m_pElements = m_pMemory;
  if ( this->m_Files.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Files.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlSymbol *, const CUtlSymbol *))CDefOps<unsigned short>::LessFunc;
  insert.key = (CUtlSymbol)CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: &v5, pString: "dummy")->m_Id;
  insert.elem.name.m_Id = insert.key.m_Id;
  memset(&insert.elem.nSize, 0, 16);
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Files.m_Tree,
    &insert);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D2080
// Name: public: CSaveDirectory::~CSaveDirectory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDirectory::~CSaveDirectory(CSaveDirectory *this)
{
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short> *p_m_Files; // ebx
  unsigned __int16 j; // ax
  int *v3; // ecx
  unsigned __int16 v4; // si
  unsigned __int16 Inorder; // ax
  int v6; // esi
  CUtlBuffer *pBuffer; // edi
  CUtlBuffer *pCompressedBuffer; // edi
  unsigned __int16 idx; // [esp+Ch] [ebp-Ch]
  unsigned __int16 i; // [esp+10h] [ebp-8h]

  p_m_Files = &this->m_Files;
  for ( j = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Files.m_Tree);
        j < p_m_Files->m_Tree.m_Elements.m_nAllocationCount && j <= p_m_Files->m_Tree.m_LastAlloc.index;
        j = i )
  {
    if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1068F540 = 0x1FFFF;
    }
    v3 = j == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&p_m_Files->m_Tree.m_Elements.m_pMemory[j];
    if ( *(_WORD *)v3 == j )
      break;
    v4 = j;
    idx = j;
    Inorder = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &p_m_Files->m_Tree,
                i: j);
    v6 = v4;
    pBuffer = this->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.pBuffer;
    i = Inorder;
    if ( pBuffer != nullptr )
    {
      if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
          pBuffer->m_Memory.m_pMemory = nullptr;
        }
        pBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pBuffer);
    }
    pCompressedBuffer = this->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.pCompressedBuffer;
    if ( pCompressedBuffer != nullptr )
    {
      if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
          pCompressedBuffer->m_Memory.m_pMemory = nullptr;
        }
        pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pCompressedBuffer);
    }
    if ( idx != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Files->m_Tree,
        elem: idx);
      p_m_Files->m_Tree.m_Elements.m_pMemory[v6].m_Left = idx;
      p_m_Files->m_Tree.m_Elements.m_pMemory[v6].m_Right = p_m_Files->m_Tree.m_FirstFree;
      --p_m_Files->m_Tree.m_NumElements;
      p_m_Files->m_Tree.m_FirstFree = idx;
    }
  }
  CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_Files->m_Tree);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x101D2200
// Name: public: virtual void CSaveRestoreFileSystem::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::RenameFile(
        CSaveRestoreFileSystem *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  int FileIndex; // eax
  _BOOL2 v6; // di
  const char *v7; // eax
  const char *v8; // eax
  char pDest[260]; // [esp+8h] [ebp-104h] BYREF

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pOldPath);
  v6 = FileIndex;
  if ( FileIndex != 0xFFFF )
  {
    v7 = V_UnqualifiedFileName(in: pNewPath);
    V_strncpy(pDest, pSrc: v7, maxLen: 260);
    v8 = _V_strlower(start: pDest);
    CUtlSymbolTable::AddString(
      this: &this->m_pSaveDirectory->m_SymbolTable,
      result: (CUtlSymbol *)&pOldPath,
      pString: v8);
    this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.name.m_Id = (unsigned __int16)pOldPath;
    CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Reinsert(
      this: &this->m_pSaveDirectory->m_Files,
      key: (int)&pOldPath,
      i: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2290
// Name: public: virtual void CSaveRestoreFileSystem::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystem::RemoveFile(
        CSaveRestoreFileSystem *this,
        const char *pRelativePath,
        const char *pathID)
{
  int FileIndex; // ebx
  int v5; // edi
  CUtlBuffer *pBuffer; // esi
  CUtlBuffer *pCompressedBuffer; // esi
  CSaveDirectory *m_pSaveDirectory; // esi

  FileIndex = CSaveRestoreFileSystem::GetFileIndex(this, filename: pRelativePath);
  if ( FileIndex != 0xFFFF )
  {
    v5 = (unsigned __int16)FileIndex;
    pBuffer = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.pBuffer;
    if ( pBuffer != nullptr )
    {
      if ( pBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBuffer->m_Memory.m_pMemory);
          pBuffer->m_Memory.m_pMemory = nullptr;
        }
        pBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pBuffer);
    }
    pCompressedBuffer = this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.pCompressedBuffer;
    if ( pCompressedBuffer != nullptr )
    {
      if ( pCompressedBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( pCompressedBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pCompressedBuffer->m_Memory.m_pMemory);
          pCompressedBuffer->m_Memory.m_pMemory = nullptr;
        }
        pCompressedBuffer->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: pCompressedBuffer);
    }
    m_pSaveDirectory = this->m_pSaveDirectory;
    if ( (_WORD)FileIndex != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &m_pSaveDirectory->m_Files.m_Tree,
        elem: FileIndex);
      m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Left = FileIndex;
      m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[v5].m_Right = m_pSaveDirectory->m_Files.m_Tree.m_FirstFree;
      --m_pSaveDirectory->m_Files.m_Tree.m_NumElements;
      m_pSaveDirectory->m_Files.m_Tree.m_FirstFree = FileIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2390
// Name: public: virtual void __near * CSaveRestoreFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSaveRestoreFileSystem::Open(
        CSaveRestoreFileSystem *this,
        const char *pFullName,
        const char *pOptions,
        const char *pathID)
{
  const char *v5; // eax
  const char *v6; // eax
  CSaveDirectory *m_pSaveDirectory; // ecx
  int v8; // eax
  CUtlBuffer *v9; // eax
  CUtlBuffer *v10; // edi
  CUtlBuffer *v11; // eax
  CUtlBuffer *v12; // eax
  CSaveDirectory *v13; // ecx
  CSaveDirectory::file_t *p_elem; // edi
  void *result; // eax
  CUtlBuffer *pBuffer; // ecx
  CUtlBuffer *v17; // ecx
  char pDest[260]; // [esp+Ch] [ebp-15Ch] BYREF
  CSaveDirectory::file_t newFile; // [esp+110h] [ebp-58h]
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t search; // [esp+128h] [ebp-40h] BYREF
  CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t insert; // [esp+144h] [ebp-24h] BYREF
  int idx; // [esp+160h] [ebp-8h]
  CUtlSymbol id; // [esp+164h] [ebp-4h] BYREF

  v5 = V_UnqualifiedFileName(in: pFullName);
  V_strncpy(pDest, pSrc: v5, maxLen: 260);
  v6 = _V_strlower(start: pDest);
  CUtlSymbolTable::AddString(this: &this->m_pSaveDirectory->m_SymbolTable, result: &id, pString: v6);
  m_pSaveDirectory = this->m_pSaveDirectory;
  search.elem.name.m_Id = -1;
  memset(&search.elem.nSize, 0, 16);
  search.key = id;
  v8 = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &m_pSaveDirectory->m_Files.m_Tree,
         &search);
  idx = v8;
  if ( (unsigned __int16)v8 == 0xFFFF )
  {
    if ( _V_stricmp(s1: pOptions, s2: "rb") == 0 )
      return nullptr;
    newFile.name = id;
    v9 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v9 != nullptr )
      v10 = CUtlBuffer::CUtlBuffer(this: v9, growSize: 0, initSize: 0, nFlags: 0);
    else
      v10 = nullptr;
    v11 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v11 != nullptr )
      v12 = CUtlBuffer::CUtlBuffer(this: v11, growSize: 0, initSize: 0, nFlags: 0);
    else
      v12 = nullptr;
    v13 = this->m_pSaveDirectory;
    insert.key = id;
    insert.elem.eType = newFile.eType;
    insert.elem.pCompressedBuffer = v12;
    insert.elem.name.m_Id = newFile.name.m_Id;
    insert.elem.nSize = 0;
    insert.elem.nCompressedSize = 0;
    insert.elem.pBuffer = v10;
    LOWORD(v8) = CUtlRBTree<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                   this: &v13->m_Files.m_Tree,
                   &insert);
    idx = (unsigned __int16)v8;
  }
  p_elem = &this->m_pSaveDirectory->m_Files.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem;
  if ( _V_stricmp(s1: pOptions, s2: "rb") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    result = (void *)idx;
    p_elem->eType = 0;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "wb") == 0 )
  {
    pBuffer = p_elem->pBuffer;
    pBuffer->m_Get = 0;
    pBuffer->m_Put = 0;
    pBuffer->m_Error = 0;
    pBuffer->m_nOffset = 0;
    pBuffer->m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: pBuffer, nPut: 0);
    result = (void *)idx;
    p_elem->eType = 1;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "a") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    result = (void *)idx;
    p_elem->eType = 1;
    return result;
  }
  if ( _V_stricmp(s1: pOptions, s2: "ab+") == 0 )
  {
    CSaveRestoreFileSystem::Uncompress(this, pFile: p_elem);
    v17 = p_elem->pBuffer;
    p_elem->eType = 1;
    CUtlBuffer::SeekPut(this: v17, type: SEEK_TAIL, offset: 0);
    return (void *)idx;
  }
  _Warning(a1: "CSaveRestoreFileSystem: Attempted to open %s with unsupported option %s\n", pFullName, pOptions);
  return nullptr;
}

} // namespace engine_xlsp
