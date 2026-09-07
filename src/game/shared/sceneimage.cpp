// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/sceneimage.cpp
// Functions: 14
// ============================================================

#include "game\shared\sceneimage.h"

//------------------------------------------------------------------------------
// Address: 0x004B27A0
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSceneTokenProcessor::CurrentToken(CSceneTokenProcessor *this)
{
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x004B27B0
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  return GetToken(crossline) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B27D0
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  return TokenAvailable() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B27E0
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  const char *v2; // eax
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 2048, pFormat: fmt, params);
  v2 = CUtlString::Get(this: &this->m_Filename);
  _Warning(a1: "%s: %s", v2, string);
}

//------------------------------------------------------------------------------
// Address: 0x004B2910
// Name: public: SceneFile_t::~SceneFile_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneFile_t::~SceneFile_t(SceneFile_t *this)
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->soundList);
  if ( this->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->compiledBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->compiledBuffer.m_Memory.m_pMemory);
      this->compiledBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->compiledBuffer.m_Memory.m_nAllocationCount = 0;
  }
  this->fileName.m_Storage.m_nActualLength = 0;
  if ( this->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->fileName.m_Storage.m_Memory.m_pMemory);
      this->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2970
// Name: public: void CChoreoStringPool::GetTableAndPool(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoStringPool::GetTableAndPool(
        CChoreoStringPool *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *offsets,
        CUtlBuffer *buffer)
{
  CChoreoStringPool *v3; // ebx
  int m_NumElements; // eax
  unsigned int *m_pMemory; // edx
  unsigned int *v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  unsigned int *v11; // ecx
  int v12; // eax
  unsigned int *v13; // ebx
  const char *v14; // ebx
  unsigned __int8 m_Flags; // cl
  int m_Put; // eax
  int m_nTab; // eax
  int v18; // ebx
  unsigned int v19; // [esp-4h] [ebp-14h]
  unsigned int currentOffset; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]

  v3 = this;
  offsets[1].m_pMemory = nullptr;
  if ( offsets->m_nGrowSize >= 0 )
  {
    if ( offsets->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: offsets->m_pMemory);
      offsets->m_pMemory = nullptr;
    }
    offsets->m_nAllocationCount = 0;
  }
  offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
  buffer->m_Get = 0;
  buffer->m_Put = 0;
  buffer->m_nOffset = 0;
  buffer->m_nMaxPut = 0;
  buffer->m_Error = 0;
  if ( buffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer->m_Memory.m_pMemory);
      buffer->m_Memory.m_pMemory = nullptr;
    }
    buffer->m_Memory.m_nAllocationCount = 0;
  }
  m_NumElements = v3->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements;
  if ( offsets->m_nAllocationCount < m_NumElements && offsets->m_nGrowSize >= 0 )
  {
    m_pMemory = (unsigned int *)offsets->m_pMemory;
    offsets->m_nAllocationCount = m_NumElements;
    v19 = 4 * m_NumElements;
    if ( m_pMemory != nullptr )
    {
      v8 = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v19);
      v3 = this;
    }
    else
    {
      v8 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v19);
    }
    offsets->m_pMemory = (CUtlSymbolTable::StringPool_t **)v8;
  }
  offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v3->m_nOffset);
  currentOffset = 0;
  i = 0;
  if ( v3->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v9 = (int)offsets[1].m_pMemory;
      m_nAllocationCount = offsets->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: offsets, num: v9 - m_nAllocationCount + 1);
      ++offsets[1].m_pMemory;
      v11 = (unsigned int *)offsets->m_pMemory;
      v12 = (int)offsets[1].m_pMemory - v9 - 1;
      offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (unsigned int *)&offsets->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = currentOffset;
      v14 = CUtlSymbolTable::String(this: &this->m_StringMap.m_SymbolTable, id: (CUtlSymbol)i);
      CUtlBuffer::Put(this: buffer, pMem: v14, size: strlen(v14) + 1);
      currentOffset += strlen(v14) + 1;
      ++i;
    }
    while ( i < this->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements );
    v3 = this;
  }
  for ( ; (buffer->m_Put & 3) != 0; ++v3->m_nOffset )
  {
    m_Flags = buffer->m_Flags;
    if ( (m_Flags & 1) != 0 )
    {
      m_Put = buffer->m_Put;
      if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      {
        if ( (m_Flags & 0x10) != 0 )
          m_nTab = 0;
        else
          m_nTab = buffer->m_nTab;
        v18 = m_nTab - 1;
        if ( m_nTab - 1 < 0 )
        {
          v3 = this;
        }
        else
        {
          do
          {
            if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
            {
              buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = 9;
              CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
            }
            --v18;
          }
          while ( v18 >= 0 );
          v3 = this;
        }
      }
    }
    if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2C40
// Name: public: virtual bool CChoreoStringPool::GetString(short,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoStringPool::GetString(CChoreoStringPool *this, __int16 stringId, char *buff, int buffSize)
{
  const char *v4; // eax

  if ( stringId < 0 || stringId >= (int)this->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements )
  {
    V_strncpy(pDest: buff, pSrc: defaultValue, maxLen: buffSize);
    return 0;
  }
  else
  {
    v4 = CUtlSymbolTable::String(this: &this->m_StringMap.m_SymbolTable, id: (CUtlSymbol)stringId);
    V_strncpy(pDest: buff, pSrc: v4, maxLen: buffSize);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2D90
// Name: public: virtual short CChoreoStringPool::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CChoreoStringPool::FindOrAddString(CChoreoStringPool *this, const char *pString)
{
  const char *v2; // ebx
  int m_Id; // eax
  int v5; // ebx
  int m_Size; // ecx
  const char *v8; // [esp-8h] [ebp-18h]
  CUtlSymbolTable *p_m_SymbolTable; // [esp+8h] [ebp-8h]
  CUtlSymbol v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = pString;
  p_m_SymbolTable = &this->m_StringMap.m_SymbolTable;
  m_Id = CUtlSymbolTable::Find(this: &this->m_StringMap.m_SymbolTable, result: &v10, pString)->m_Id;
  if ( m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &this->m_StringMap.m_SymbolTable, result: &v10, pString: v2);
    v5 = v10.m_Id;
    m_Size = this->m_StringMap.m_Vector.m_Size;
    if ( m_Size <= v10.m_Id && m_Size < v10.m_Id + 1 )
      CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
        this: &this->m_StringMap.m_Vector,
        elem: m_Size,
        num: v10.m_Id + 1 - m_Size);
    this->m_StringMap.m_Vector.m_Memory.m_pMemory[v5] = this->m_nOffset;
    v8 = pString;
    this->m_nOffset += strlen(pString) + 1;
    LOWORD(m_Id) = (CUtlSymbol)CUtlSymbolTable::Find(
                                 this: p_m_SymbolTable,
                                 result: (CUtlSymbol *)&pString + 1,
                                 pString: v8)->m_Id;
  }
  return m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004B2E20
// Name: void FindSoundsInEvent(class CChoreoEvent __near *,class CUtlVector<short,class CUtlMemory<short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindSoundsInEvent(CChoreoEvent *pEvent, CUtlVector<short,CUtlMemory<short,int> > *soundList)
{
  CChoreoEvent *v2; // esi
  char *Parameters; // eax
  __int16 v4; // ax
  CUtlVector<short,CUtlMemory<short,int> > *v5; // esi
  int m_Size; // edi
  __int16 v7; // bx
  int v8; // eax
  __int16 *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  __int16 *v11; // ecx
  int v12; // eax
  __int16 *v13; // eax
  CChoreoEvent *v14; // edi
  unsigned __int16 v15; // bx
  int v16; // edi
  int v17; // eax
  __int16 *v18; // ecx
  int v19; // eax
  unsigned __int16 *v20; // eax
  char tok[64]; // [esp+4h] [ebp-40h] BYREF

  v2 = pEvent;
  if ( pEvent != nullptr && CChoreoEvent::GetType(this: pEvent) == SPEAK )
  {
    Parameters = CChoreoEvent::GetParameters(this: v2);
    v4 = CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString: Parameters);
    v5 = soundList;
    m_Size = soundList->m_Size;
    v7 = v4;
    v8 = 0;
    if ( m_Size <= 0 )
      goto LABEL_9;
    m_pMemory = soundList->m_Memory.m_pMemory;
    while ( *m_pMemory != v7 )
    {
      ++v8;
      ++m_pMemory;
      if ( v8 >= m_Size )
        goto LABEL_9;
    }
    if ( v8 == -1 )
    {
LABEL_9:
      m_nAllocationCount = soundList->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &soundList->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v5->m_Size;
      v11 = v5->m_Memory.m_pMemory;
      v12 = v5->m_Size - m_Size - 1;
      v5->m_pElements = v5->m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 2 * v12);
      v13 = &v5->m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v7;
    }
    v14 = pEvent;
    if ( CChoreoEvent::GetCloseCaptionType(this: pEvent) == CC_MASTER
      && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v14, dest: tok, destlen: 64) != 0 )
    {
      v15 = CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString: tok);
      pEvent = (CChoreoEvent *)v15;
      if ( CUtlVector<short,CUtlMemory<short,int>>::Find(this: v5, src: (const __int16 *)&pEvent) == -1 )
      {
        v16 = v5->m_Size;
        v17 = v5->m_Memory.m_nAllocationCount;
        if ( v16 + 1 > v17 )
          CUtlMemory<CUtlSymbol,int>::Grow(this: &v5->m_Memory, num: v16 - v17 + 1);
        ++v5->m_Size;
        v18 = v5->m_Memory.m_pMemory;
        v19 = v5->m_Size - v16 - 1;
        v5->m_pElements = v5->m_Memory.m_pMemory;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 2 * v19);
        v20 = (unsigned __int16 *)&v5->m_Memory.m_pMemory[v16];
        if ( v20 != nullptr )
          *v20 = v15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2F70
// Name: bool UpdateTargetFile_VCD(struct SceneFile_t __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __usercall UpdateTargetFile_VCD@<al>(
        char *a1@<edi>,
        SceneFile_t *pEntry,
        const char *pSourceName,
        const char *pTargetName,
        bool bWriteToZip,
        bool bLittleEndian)
{
  CChoreoScene *Scene; // eax
  CChoreoScene *v8; // edi
  int v9; // esi
  CChoreoEvent *Event; // eax
  CUtlBuffer *p_compiledBuffer; // esi
  unsigned __int8 *v12; // ebx
  CUtlBuffer sourceBuf; // [esp+8h] [ebp-40h] BYREF
  __int64 v14; // [esp+38h] [ebp-10h]
  unsigned int compressedSize; // [esp+40h] [ebp-8h] BYREF
  unsigned int crcSource; // [esp+44h] [ebp-4h] BYREF

  pEntry->crcFileName = 0;
  CUtlString::Set(this: &pEntry->fileName, pValue: pSourceName);
  CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( scriptlib->ReadFileToBuffer(this: scriptlib, a2: pSourceName, a3: &sourceBuf, a4: false, a5: false) != 0 )
  {
    CRC32_Init(pulCRC: &crcSource);
    CRC32_ProcessBuffer(pulCRC: &crcSource, pBuffer: sourceBuf.m_Memory.m_pMemory, nBuffer: sourceBuf.m_Put);
    CRC32_Final(pulCRC: &crcSource);
    ParseFromMemory(buffer: (char *)sourceBuf.m_Memory.m_pMemory, size: sourceBuf.m_Put);
    CUtlString::operator=(this: &g_SceneTokenProcessor.m_Filename, src: pSourceName);
    Scene = ChoreoLoadScene(a1, filename: pSourceName, callback: nullptr, tokenizer: &g_SceneTokenProcessor, pfn: _Msg);
    v8 = Scene;
    if ( Scene != nullptr )
    {
      v9 = 0;
      if ( CChoreoScene::GetNumEvents(this: (IterateRIFF *)Scene) > 0 )
      {
        do
        {
          Event = CChoreoScene::GetEvent(this: v8, event: v9);
          FindSoundsInEvent(pEvent: Event, soundList: &pEntry->soundList);
          ++v9;
        }
        while ( v9 < CChoreoScene::GetNumEvents(this: (IterateRIFF *)v8) );
      }
      v14 = (__int64)(CChoreoScene::FindStopTime(this: v8) * 1000.0 + 0.5);
      pEntry->msecs = v14;
      p_compiledBuffer = &pEntry->compiledBuffer;
      v14 = (__int64)(CChoreoScene::FindLastSpeakTime(this: v8) * 1000.0 + 0.5);
      pEntry->lastspeak_msecs = v14;
      pEntry->compiledBuffer.m_Get = 0;
      pEntry->compiledBuffer.m_Put = 0;
      pEntry->compiledBuffer.m_Error = 0;
      pEntry->compiledBuffer.m_nOffset = 0;
      pEntry->compiledBuffer.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &pEntry->compiledBuffer, nPut: 0);
      CUtlBuffer::SetBigEndian(this: &pEntry->compiledBuffer, bigEndian: !bLittleEndian);
      CChoreoScene::SaveToBinaryBuffer(
        this: v8,
        buf: (CChoreoActor *)&pEntry->compiledBuffer,
        nTextVersionCRC: crcSource,
        pStringPool: &g_ChoreoStringPool);
      v12 = LZMA_Compress(
              pInput: pEntry->compiledBuffer.m_Memory.m_pMemory,
              inputSize: pEntry->compiledBuffer.m_Put,
              pOutputSize: &compressedSize,
              dictionarySize: 0x12u);
      if ( v12 != nullptr )
      {
        pEntry->compiledBuffer.m_Get = 0;
        pEntry->compiledBuffer.m_Put = 0;
        pEntry->compiledBuffer.m_nOffset = 0;
        pEntry->compiledBuffer.m_nMaxPut = 0;
        pEntry->compiledBuffer.m_Error = 0;
        if ( pEntry->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( p_compiledBuffer->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_compiledBuffer->m_Memory.m_pMemory);
            p_compiledBuffer->m_Memory.m_pMemory = nullptr;
          }
          pEntry->compiledBuffer.m_Memory.m_nAllocationCount = 0;
        }
        CUtlBuffer::EnsureCapacity(this: p_compiledBuffer, num: compressedSize);
        CUtlBuffer::Put(this: p_compiledBuffer, pMem: v12, size: compressedSize);
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      }
      CChoreoScene::~CChoreoScene(this: v8);
      free(pMem: v8);
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B31E0
// Name: bool CreateTargetFile_VCD(char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetFile_VCD(
        const char *pSourceName,
        const char *pTargetName,
        bool bWriteToZip,
        bool bLittleEndian)
{
  char *v4; // edi
  int v5; // esi
  char updated; // bl

  v4 = (char *)CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
                 this: &g_SceneFiles,
                 elem: g_SceneFiles.m_Size);
  v5 = (int)v4;
  updated = UpdateTargetFile_VCD(
              a1: v4,
              pEntry: &g_SceneFiles.m_Memory.m_pMemory[(_DWORD)v4],
              pSourceName,
              pTargetName,
              bWriteToZip,
              bLittleEndian);
  if ( updated == 0 )
  {
    SceneFile_t::~SceneFile_t(this: &g_SceneFiles.m_Memory.m_pMemory[v5]);
    if ( g_SceneFiles.m_Size - (int)v4 - 1 > 0 )
      _V_memmove(
        dest: &g_SceneFiles.m_Memory.m_pMemory[v5],
        src: &g_SceneFiles.m_Memory.m_pMemory[v5 + 1],
        count: 96 * (g_SceneFiles.m_Size - (_DWORD)v4 - 1));
    --g_SceneFiles.m_Size;
  }
  return updated;
}

//------------------------------------------------------------------------------
// Address: 0x004B3270
// Name: private: bool CSceneImage::WriteSceneImageFile(class CUtlBuffer __near &,bool,bool,class ISceneCompileStatus __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneImage::WriteSceneImageFile(
        CSceneImage *this,
        CUtlBuffer *targetBuffer,
        bool bLittleEndian,
        bool bQuiet,
        ISceneCompileStatus *pStatus)
{
  int v5; // ebx
  int m_Size; // edi
  CUtlBuffer *v7; // esi
  CUtlBuffer *v8; // edi
  int v9; // ecx
  IMemAlloc_vtbl *v10; // edx
  SceneImageEntry_t *v11; // eax
  int v12; // edi
  int v13; // ebx
  CUtlBuffer *v14; // eax
  const char *v15; // eax
  const char *v16; // edi
  const char *v17; // eax
  int v18; // ebx
  int nSceneSummaryOffset; // ebx
  unsigned int v20; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v22; // ecx
  SceneFile_t *m_pMemory; // eax
  int v24; // edi
  int v25; // ecx
  int *v26; // edi
  bool v27; // zf
  int *p_nDataLength; // edi
  int v29; // eax
  CUtlBuffer *v30; // edx
  int v31; // ebx
  CUtlBuffer *v32; // edx
  unsigned int v33; // edi
  int msecs; // ebx
  int v35; // edx
  CUtlBuffer *lastspeak_msecs; // eax
  int *v37; // eax
  int v38; // eax
  int *v39; // eax
  int v40; // eax
  int *v41; // eax
  bool v42; // cc
  int v43; // ebx
  int *v44; // eax
  int v45; // ebx
  unsigned int v46; // edi
  SceneFile_t *v47; // eax
  const char *v49; // [esp+10h] [ebp-1A8h]
  char szCleanName[260]; // [esp+1Ch] [ebp-19Ch] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > stringOffsets; // [esp+120h] [ebp-98h] BYREF
  CUtlBuffer stringPool; // [esp+134h] [ebp-84h] BYREF
  CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> imageDirectory; // [esp+164h] [ebp-54h] BYREF
  SceneImageEntry_t imageEntry; // [esp+180h] [ebp-38h] BYREF
  unsigned int crcFilename; // [esp+190h] [ebp-28h]
  SceneImageHeader_t imageHeader; // [esp+194h] [ebp-24h] BYREF
  int soundCount; // [esp+1A8h] [ebp-10h]
  int iScene; // [esp+1ACh] [ebp-Ch]
  int j; // [esp+1B0h] [ebp-8h] BYREF
  int soundId; // [esp+1B4h] [ebp-4h] BYREF

  _Msg(a1: "Scenes: Finalizing %d unique scenes.\n", g_SceneFiles.m_Size);
  v5 = 0;
  memset(&stringOffsets, 0, sizeof(stringOffsets));
  CUtlBuffer::CUtlBuffer(this: &stringPool, growSize: 0, initSize: 0, nFlags: 0);
  CChoreoStringPool::GetTableAndPool(
    this: &g_ChoreoStringPool,
    offsets: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&stringOffsets,
    buffer: &stringPool);
  m_Size = stringOffsets.m_Size;
  if ( !bQuiet )
  {
    _Msg(a1: "Scenes: String Table: %d bytes\n", 4 * stringOffsets.m_Size);
    _Msg(a1: "Scenes: String Pool: %d bytes\n", stringPool.m_Put);
  }
  soundCount = stringPool.m_Put + 4 * m_Size + 20 + 16 * g_SceneFiles.m_Size;
  imageHeader.nId = 1179210582;
  imageHeader.nVersion = 3;
  imageHeader.nNumScenes = g_SceneFiles.m_Size;
  imageHeader.nNumStrings = m_Size;
  imageHeader.nSceneEntryOffset = stringPool.m_Put + 4 * m_Size + 20;
  if ( !bLittleEndian )
  {
    imageHeader.nId = _byteswap_ulong(imageHeader.nId);
    imageHeader.nVersion = _byteswap_ulong(imageHeader.nVersion);
    imageHeader.nNumScenes = _byteswap_ulong(imageHeader.nNumScenes);
    imageHeader.nNumStrings = _byteswap_ulong(imageHeader.nNumStrings);
    imageHeader.nSceneEntryOffset = _byteswap_ulong(imageHeader.nSceneEntryOffset);
  }
  v7 = targetBuffer;
  CUtlBuffer::Put(this: targetBuffer, pMem: &imageHeader, size: 20);
  if ( m_Size > 0 )
  {
    do
    {
      v8 = (CUtlBuffer *)(4 * stringOffsets.m_Size + 20 + stringOffsets.m_Memory.m_pMemory[v5]);
      targetBuffer = v8;
      if ( !bLittleEndian )
        v8 = (CUtlBuffer *)_byteswap_ulong((unsigned int)targetBuffer);
      if ( (v7->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v7, pFmt: "%d", v8);
      }
      else
      {
        targetBuffer = v8;
        if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<int>(
              this: &v7->m_Byteswap,
              outputBuffer: (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset],
              inputBuffer: (int *)&targetBuffer,
              count: 1);
          else
            *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = v8;
          v7->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
        }
      }
      ++v5;
    }
    while ( v5 < stringOffsets.m_Size );
  }
  CUtlBuffer::Put(this: v7, pMem: stringPool.m_Memory.m_pMemory, size: stringPool.m_Put);
  v9 = g_SceneFiles.m_Size;
  memset(&imageDirectory, 0, 16);
  imageDirectory.m_pLessContext = nullptr;
  imageDirectory.m_bNeedsSort = false;
  if ( g_SceneFiles.m_Size > 0 )
  {
    v10 = _g_pMemAlloc->__vftable;
    imageDirectory.m_Memory.m_nAllocationCount = g_SceneFiles.m_Size;
    v11 = (SceneImageEntry_t *)v10->Alloc_2(this: _g_pMemAlloc, a2: 16 * g_SceneFiles.m_Size);
    v9 = g_SceneFiles.m_Size;
    imageDirectory.m_Memory.m_pMemory = v11;
  }
  v12 = 0;
  imageDirectory.m_pElements = imageDirectory.m_Memory.m_pMemory;
  iScene = 0;
  if ( v9 > 0 )
  {
    v13 = 0;
    soundId = 0;
    do
    {
      v14 = *(CUtlBuffer **)((char *)&g_SceneFiles.m_Memory.m_pMemory->crcFileName + v13);
      *(_QWORD *)&imageEntry.nDataLength = 0;
      crcFilename = 0;
      if ( v14 == nullptr )
      {
        v15 = CUtlString::operator char const *(this: (CUtlString *)((char *)&g_SceneFiles.m_Memory.m_pMemory->fileName
                                                                   + v13));
        V_strncpy(pDest: szCleanName, pSrc: v15, maxLen: 260);
        _V_strlower(start: szCleanName);
        V_FixSlashes(pname: szCleanName, separator: 92);
        v16 = V_stristr(pStr: szCleanName, pSearch: "scenes\\");
        if ( v16 == nullptr )
        {
          v17 = CUtlString::operator char const *(this: (CUtlString *)((char *)&g_SceneFiles.m_Memory.m_pMemory->fileName
                                                                     + v13));
          _Error(this: (ISceneTokenProcessor *)&stru_4F8424, a2: v17);
        }
        v18 = strlen(v16);
        CRC32_Init(pulCRC: (unsigned int *)&targetBuffer);
        CRC32_ProcessBuffer(pulCRC: (unsigned int *)&targetBuffer, pBuffer: v16, nBuffer: v18);
        CRC32_Final(pulCRC: (unsigned int *)&targetBuffer);
        v14 = targetBuffer;
        v12 = iScene;
        v13 = soundId;
      }
      imageEntry.nDataOffset = (int)v14;
      imageEntry.nDataLength = v12;
      if ( CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Find(
             this: &imageDirectory,
             src: (const SceneImageEntry_t *)&imageEntry.nDataOffset) != -1 )
        _Error(this: (ISceneTokenProcessor *)&stru_4F83E4, a2: v49);
      CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Insert(
        this: &imageDirectory,
        src: (const SceneImageEntry_t *)&imageEntry.nDataOffset);
      v9 = g_SceneFiles.m_Size;
      ++v12;
      v13 += 96;
      iScene = v12;
      soundId = v13;
    }
    while ( v12 < g_SceneFiles.m_Size );
  }
  nSceneSummaryOffset = 0;
  v20 = 0;
  memset(&imageEntry, 0, sizeof(imageEntry));
  if ( v9 > 0 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    imageEntry.nDataOffset = v9;
    v20 = (int)Alloc_2(this: _g_pMemAlloc, a2: 4 * v9);
    imageEntry.crcFilename = v20;
  }
  v22 = imageDirectory.m_Size;
  crcFilename = v20;
  soundId = soundCount;
  m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
  if ( imageDirectory.m_Size > 0 )
  {
    targetBuffer = (CUtlBuffer *)&imageDirectory.m_Memory.m_pMemory->nDataOffset;
    j = imageDirectory.m_Size;
    do
    {
      iScene = (int)targetBuffer->m_Memory.m_pMemory;
      v24 = nSceneSummaryOffset;
      if ( nSceneSummaryOffset + 1 > imageEntry.nDataOffset )
      {
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&imageEntry,
          num: nSceneSummaryOffset - imageEntry.nDataOffset + 1);
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
        nSceneSummaryOffset = imageEntry.nSceneSummaryOffset;
      }
      imageEntry.nSceneSummaryOffset = ++nSceneSummaryOffset;
      crcFilename = imageEntry.crcFilename;
      if ( nSceneSummaryOffset - v24 - 1 > 0 )
      {
        _V_memmove(
          dest: (void *)(imageEntry.crcFilename + 4 * v24 + 4),
          src: (const void *)(imageEntry.crcFilename + 4 * v24),
          count: 4 * (nSceneSummaryOffset - v24 - 1));
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      }
      v25 = iScene;
      v26 = (int *)(imageEntry.crcFilename + 4 * v24);
      if ( v26 != nullptr )
      {
        *v26 = iScene;
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      }
      targetBuffer = (CUtlBuffer *)((char *)targetBuffer + 16);
      v27 = j-- == 1;
      soundId += 4 * m_pMemory[v25].soundList.m_Size + 12;
    }
    while ( !v27 );
    v22 = imageDirectory.m_Size;
  }
  targetBuffer = (CUtlBuffer *)soundCount;
  j = 0;
  if ( v22 > 0 )
  {
    p_nDataLength = &imageDirectory.m_Memory.m_pMemory->nDataLength;
    do
    {
      v29 = *(_DWORD *)(imageEntry.crcFilename + 4 * j);
      *(p_nDataLength - 1) = soundId;
      v30 = targetBuffer;
      v31 = v29;
      v27 = !bLittleEndian;
      *p_nDataLength = g_SceneFiles.m_Memory.m_pMemory[v29].compiledBuffer.m_Put;
      p_nDataLength[1] = (int)v30;
      if ( v27 )
      {
        iScene = *(p_nDataLength - 2);
        *(p_nDataLength - 2) = _byteswap_ulong(iScene);
        iScene = *(p_nDataLength - 1);
        *(p_nDataLength - 1) = _byteswap_ulong(iScene);
        iScene = *p_nDataLength;
        *p_nDataLength = _byteswap_ulong(iScene);
        iScene = p_nDataLength[1];
        p_nDataLength[1] = _byteswap_ulong(iScene);
      }
      CUtlBuffer::Put(this: v7, pMem: p_nDataLength - 2, size: 16);
      m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      v32 = (CUtlBuffer *)(&targetBuffer->m_Get + g_SceneFiles.m_Memory.m_pMemory[v31].soundList.m_Size);
      soundId += g_SceneFiles.m_Memory.m_pMemory[v31].compiledBuffer.m_Put;
      p_nDataLength += 4;
      targetBuffer = v32;
      ++j;
    }
    while ( j < imageDirectory.m_Size );
  }
  for ( iScene = 0; iScene < imageDirectory.m_Size; ++iScene )
  {
    v33 = *(_DWORD *)(imageEntry.crcFilename + 4 * iScene);
    msecs = m_pMemory[v33].msecs;
    v35 = m_pMemory[v33].soundList.m_Size;
    lastspeak_msecs = (CUtlBuffer *)m_pMemory[v33].lastspeak_msecs;
    soundId = msecs;
    soundCount = v35;
    targetBuffer = lastspeak_msecs;
    if ( !bLittleEndian )
    {
      msecs = _byteswap_ulong(soundId);
      soundId = msecs;
      soundCount = _byteswap_ulong(soundCount);
      targetBuffer = (CUtlBuffer *)_byteswap_ulong((unsigned int)targetBuffer);
    }
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", msecs);
    }
    else
    {
      if ( !CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        goto LABEL_58;
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        v37 = (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset];
        if ( v37 != nullptr )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(j) = HIBYTE(soundId);
            BYTE1(j) = BYTE2(soundId);
            BYTE2(j) = BYTE1(msecs);
            HIBYTE(j) = msecs;
            _V_memcpy(dest: v37, src: &j, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_58;
          }
          if ( v37 != &soundId )
          {
            *v37 = msecs;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_58;
          }
        }
      }
      else
      {
        *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = msecs;
      }
      v7->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
    }
LABEL_58:
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", targetBuffer);
    }
    else
    {
      if ( !CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        goto LABEL_69;
      v38 = (int)&v7->m_Memory.m_pMemory[-v7->m_nOffset];
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        v39 = (int *)(v7->m_Put + v38);
        if ( v39 != nullptr )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(j) = HIBYTE(targetBuffer);
            BYTE1(j) = BYTE2(targetBuffer);
            BYTE2(j) = BYTE1(targetBuffer);
            HIBYTE(j) = (_BYTE)targetBuffer;
            _V_memcpy(dest: v39, src: &j, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_69;
          }
          if ( v39 != &soundId )
          {
            *v39 = (int)targetBuffer;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_69;
          }
        }
      }
      else
      {
        *(_DWORD *)(v38 + v7->m_Put) = targetBuffer;
      }
      v7->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
    }
LABEL_69:
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", soundCount);
      goto LABEL_80;
    }
    if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
    {
      v40 = (int)&v7->m_Memory.m_pMemory[-v7->m_nOffset];
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) == 0 )
      {
        *(_DWORD *)(v40 + v7->m_Put) = soundCount;
LABEL_78:
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
        goto LABEL_80;
      }
      v41 = (int *)(v7->m_Put + v40);
      if ( v41 == nullptr )
        goto LABEL_78;
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        LOBYTE(targetBuffer) = HIBYTE(soundCount);
        BYTE1(targetBuffer) = BYTE2(soundCount);
        BYTE2(targetBuffer) = BYTE1(soundCount);
        HIBYTE(targetBuffer) = soundCount;
        _V_memcpy(dest: v41, src: &targetBuffer, count: 4);
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
      }
      else
      {
        if ( v41 == (int *)&targetBuffer )
          goto LABEL_78;
        *v41 = soundCount;
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
      }
    }
LABEL_80:
    m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
    v42 = g_SceneFiles.m_Memory.m_pMemory[v33].soundList.m_Size <= 0;
    j = 0;
    if ( !v42 )
    {
      do
      {
        v43 = m_pMemory[v33].soundList.m_Memory.m_pMemory[j];
        soundId = v43;
        if ( !bLittleEndian )
        {
          v43 = _byteswap_ulong(soundId);
          soundId = v43;
        }
        if ( (v7->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v7, pFmt: "%d", v43);
          goto LABEL_94;
        }
        if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = v43;
LABEL_92:
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_94;
          }
          v44 = (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset];
          if ( v44 == nullptr )
            goto LABEL_92;
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(targetBuffer) = HIBYTE(soundId);
            BYTE1(targetBuffer) = BYTE2(soundId);
            BYTE2(targetBuffer) = BYTE1(v43);
            HIBYTE(targetBuffer) = v43;
            _V_memcpy(dest: v44, src: &targetBuffer, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
          }
          else
          {
            if ( v44 == (int *)&targetBuffer )
              goto LABEL_92;
            *v44 = v43;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
          }
        }
LABEL_94:
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
        ++j;
      }
      while ( j < g_SceneFiles.m_Memory.m_pMemory[v33].soundList.m_Size );
    }
  }
  v45 = 0;
  if ( imageDirectory.m_Size > 0 )
  {
    v46 = imageEntry.crcFilename;
    while ( 1 )
    {
      CUtlBuffer::Put(
        this: v7,
        pMem: m_pMemory[*(_DWORD *)(v46 + 4 * v45)].compiledBuffer.m_Memory.m_pMemory,
        size: m_pMemory[*(_DWORD *)(v46 + 4 * v45)].compiledBuffer.m_Put);
      if ( ++v45 >= imageDirectory.m_Size )
        break;
      m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
    }
  }
  if ( !bQuiet )
    _Msg(a1: "Scenes: Final size: %.2f MB\n", (float)((float)v7->m_Put * 0.00000095367432));
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this: &g_SceneFiles);
  v47 = g_SceneFiles.m_Memory.m_pMemory;
  if ( g_SceneFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SceneFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SceneFiles.m_Memory.m_pMemory);
      v47 = nullptr;
      g_SceneFiles.m_Memory.m_pMemory = nullptr;
    }
    g_SceneFiles.m_Memory.m_nAllocationCount = 0;
  }
  g_SceneFiles.m_pElements = v47;
  if ( imageEntry.nDataLength >= 0 && imageEntry.crcFilename != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)imageEntry.crcFilename);
  if ( imageDirectory.m_Memory.m_nGrowSize >= 0 && imageDirectory.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: imageDirectory.m_Memory.m_pMemory);
  if ( stringPool.m_Memory.m_nGrowSize >= 0 )
  {
    if ( stringPool.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stringPool.m_Memory.m_pMemory);
      stringPool.m_Memory.m_pMemory = nullptr;
    }
    stringPool.m_Memory.m_nAllocationCount = 0;
  }
  if ( stringOffsets.m_Memory.m_nGrowSize >= 0 && stringOffsets.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stringOffsets.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B3BF0
// Name: public: virtual bool CSceneImage::UpdateSceneImageFile(class CUtlBuffer __near &,char const __near *,bool,bool,class ISceneCompileStatus __near *,class CUtlString __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSceneImage::UpdateSceneImageFile@<al>(
        CSceneImage *this@<ecx>,
        const char *a2@<ebx>,
        CUtlBuffer *targetBuffer,
        char *pchModPath,
        BOOL bLittleEndian,
        BOOL bQuiet,
        ISceneCompileStatus *pStatus,
        CUtlString *pFilesToUpdate,
        int nUpdateCount)
{
  char v10; // bl
  SceneFile_t *m_pMemory; // eax
  int *v12; // eax
  int v13; // edi
  signed int i; // esi
  unsigned __int8 *v15; // ebx
  unsigned __int8 *v16; // ebx
  void *v17; // ecx
  void *v18; // edx
  unsigned __int8 *v19; // eax
  int v20; // edi
  unsigned __int8 *v21; // edi
  int v22; // eax
  void *v23; // edx
  SceneFile_t *v24; // esi
  unsigned int v25; // ecx
  void *v26; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  __int16 *v29; // ecx
  int v30; // eax
  __int16 *v31; // edi
  unsigned int v32; // eax
  int v33; // ebx
  int v34; // edi
  unsigned int crcFileName; // esi
  CUtlString *v36; // ecx
  char *v37; // ebx
  const char *v38; // eax
  const char *v39; // edi
  int v40; // esi
  int v41; // ecx
  int v42; // esi
  int v43; // eax
  unsigned int v44; // edx
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  SceneFile_t *v48; // esi
  __int16 *v49; // eax
  int v50; // eax
  const char *v51; // [esp-4h] [ebp-1134h]
  char pString[4096]; // [esp+8h] [ebp-1128h] BYREF
  char pDest[260]; // [esp+1008h] [ebp-128h] BYREF
  CSceneImage *v54; // [esp+110Ch] [ebp-24h]
  char *pSourceName; // [esp+1110h] [ebp-20h]
  unsigned int pMem; // [esp+1114h] [ebp-1Ch] BYREF
  unsigned int v57; // [esp+1118h] [ebp-18h]
  signed int v58; // [esp+111Ch] [ebp-14h]
  signed int v59; // [esp+1120h] [ebp-10h]
  int offset; // [esp+1124h] [ebp-Ch]
  __int16 *v61; // [esp+1128h] [ebp-8h]
  void *j; // [esp+112Ch] [ebp-4h]
  bool pStr_3; // [esp+113Fh] [ebp+Fh]

  v54 = this;
  if ( targetBuffer->m_Put <= 0 )
    return this->CreateSceneImageFile(
             this,
             a2: targetBuffer,
             a3: pchModPath,
             a4: bLittleEndian,
             a5: bQuiet,
             a6: pStatus);
  v51 = a2;
  v10 = 1;
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this: &g_SceneFiles);
  m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
  if ( g_SceneFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SceneFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SceneFiles.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_SceneFiles.m_Memory.m_pMemory = nullptr;
    }
    g_SceneFiles.m_Memory.m_nAllocationCount = 0;
  }
  g_SceneFiles.m_pElements = m_pMemory;
  v12 = g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory;
  g_ChoreoStringPool.m_StringMap.m_Vector.m_Size = 0;
  if ( g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory);
      v12 = nullptr;
      g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  g_ChoreoStringPool.m_StringMap.m_Vector.m_pElements = v12;
  CUtlSymbolTable::RemoveAll(this: &g_ChoreoStringPool.m_StringMap.m_SymbolTable);
  g_ChoreoStringPool.m_nOffset = 0;
  CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Get(this: targetBuffer, &pMem, size: 20);
  if ( !bLittleEndian )
  {
    pMem = _byteswap_ulong(pMem);
    v57 = _byteswap_ulong(v57);
    v58 = _byteswap_ulong(v58);
    v59 = _byteswap_ulong(v59);
    offset = _byteswap_ulong(offset);
  }
  if ( pMem != 1179210582 )
    v10 = 0;
  if ( v57 == 3 && v10 != 0 )
  {
    v13 = offset;
    CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: 4 * v59 + 20);
    for ( i = 0; i < v59; ++i )
    {
      CUtlBuffer::GetString(this: targetBuffer, pString, nMaxChars: 4096);
      CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString);
    }
    CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: v13);
    v15 = &targetBuffer->m_Memory.m_pMemory[v13];
    pSourceName = nullptr;
    if ( v58 > 0 )
    {
      v16 = v15 + 4;
      do
      {
        if ( !bLittleEndian )
        {
          j = *((void **)v16 - 1);
          v17 = *(void **)v16;
          *((_DWORD *)v16 - 1) = _byteswap_ulong((unsigned int)j);
          j = v17;
          v18 = *((void **)v16 + 1);
          *(_DWORD *)v16 = _byteswap_ulong((unsigned int)v17);
          j = v18;
          *((_DWORD *)v16 + 1) = _byteswap_ulong((unsigned int)v18);
          j = *((void **)v16 + 2);
          *((_DWORD *)v16 + 2) = _byteswap_ulong((unsigned int)j);
        }
        v19 = targetBuffer->m_Memory.m_pMemory;
        v20 = *((_DWORD *)v16 + 2);
        j = &targetBuffer->m_Memory.m_pMemory[*(_DWORD *)v16];
        v21 = &v19[v20];
        v22 = CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
                this: &g_SceneFiles,
                elem: g_SceneFiles.m_Size);
        v23 = j;
        v24 = &g_SceneFiles.m_Memory.m_pMemory[v22];
        v24->crcFileName = *((_DWORD *)v16 - 1);
        CUtlBuffer::Put(this: &v24->compiledBuffer, pMem: v23, size: *((_DWORD *)v16 + 1));
        v25 = *((_DWORD *)v21 + 1);
        v24->msecs = *(_DWORD *)v21;
        v26 = *((void **)v21 + 2);
        v24->lastspeak_msecs = v25;
        if ( (int)v26 > 0 )
        {
          v61 = (__int16 *)(v21 + 12);
          for ( j = v26; j != nullptr; j = (char *)j - 1 )
          {
            m_Size = v24->soundList.m_Size;
            m_nAllocationCount = v24->soundList.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CUtlSymbol,int>::Grow(this: &v24->soundList.m_Memory, num: m_Size - m_nAllocationCount + 1);
            ++v24->soundList.m_Size;
            v29 = v24->soundList.m_Memory.m_pMemory;
            v30 = v24->soundList.m_Size - m_Size - 1;
            v24->soundList.m_pElements = v29;
            if ( v30 > 0 )
              _V_memmove(dest: &v29[m_Size + 1], src: &v29[m_Size], count: 2 * v30);
            v31 = &v24->soundList.m_Memory.m_pMemory[m_Size];
            if ( v31 != nullptr )
              *v31 = *v61;
            v61 += 2;
          }
        }
        v16 += 16;
        ++pSourceName;
      }
      while ( (int)pSourceName < v58 );
    }
  }
  v32 = 0;
  v33 = 0;
  if ( g_SceneFiles.m_Size > 0 )
  {
    v34 = 0;
    do
    {
      crcFileName = g_SceneFiles.m_Memory.m_pMemory[v34].crcFileName;
      if ( crcFileName <= v32 )
        _Error(this: (ISceneTokenProcessor *)&stru_4F8580, a2: v51);
      ++v33;
      ++v34;
      v32 = crcFileName;
    }
    while ( v33 < g_SceneFiles.m_Size );
  }
  pStr_3 = V_stristr(pStr: pchModPath, pSearch: "\\tf") != nullptr;
  v61 = nullptr;
  if ( nUpdateCount <= 0 )
    goto LABEL_77;
  v36 = pFilesToUpdate;
  j = pFilesToUpdate;
  do
  {
    v37 = (char *)CUtlString::operator char const *(this: v36);
    pSourceName = v37;
    v38 = V_stristr(pStr: v37, pSearch: "scenes\\");
    if ( v38 == nullptr || !bLittleEndian && pStr_3 && V_stristr(pStr: v38, pSearch: "high\\") != nullptr )
      goto LABEL_76;
    V_strncpy(pDest, pSrc: v37, maxLen: 260);
    _V_strlower(start: pDest);
    V_FixSlashes(pname: pDest, separator: 92);
    v39 = V_stristr(pStr: pDest, pSearch: "scenes\\");
    if ( v39 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_4F8538, a2: v37);
    v40 = strlen(v39);
    CRC32_Init(pulCRC: (unsigned int *)&pFilesToUpdate);
    CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pFilesToUpdate, pBuffer: v39, nBuffer: v40);
    CRC32_Final(pulCRC: (unsigned int *)&pFilesToUpdate);
    pStatus->UpdateStatus(this: pStatus, a2: v37, a3: bQuiet, a4: (int)v61, a5: nUpdateCount);
    v41 = g_SceneFiles.m_Size;
    v42 = 1;
    if ( g_SceneFiles.m_Size < 1 )
    {
LABEL_54:
      v46 = CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
              this: &g_SceneFiles,
              elem: g_SceneFiles.m_Size);
      v47 = v46;
      if ( UpdateTargetFile_VCD(
             a1: (char *)(96 * v46),
             pEntry: &g_SceneFiles.m_Memory.m_pMemory[v46],
             pSourceName,
             pTargetName: defaultValue,
             bWriteToZip: false,
             bLittleEndian) == 0 )
      {
        v48 = &g_SceneFiles.m_Memory.m_pMemory[v47];
        v48->soundList.m_Size = 0;
        if ( v48->soundList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->soundList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->soundList.m_Memory.m_pMemory);
            v48->soundList.m_Memory.m_pMemory = nullptr;
          }
          v48->soundList.m_Memory.m_nAllocationCount = 0;
        }
        v49 = v48->soundList.m_Memory.m_pMemory;
        v48->soundList.m_pElements = v49;
        if ( v48->soundList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v49 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v49);
            v48->soundList.m_Memory.m_pMemory = nullptr;
          }
          v48->soundList.m_Memory.m_nAllocationCount = 0;
        }
        if ( v48->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->compiledBuffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->compiledBuffer.m_Memory.m_pMemory);
            v48->compiledBuffer.m_Memory.m_pMemory = nullptr;
          }
          v48->compiledBuffer.m_Memory.m_nAllocationCount = 0;
        }
        v48->fileName.m_Storage.m_nActualLength = 0;
        if ( v48->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->fileName.m_Storage.m_Memory.m_pMemory);
            v48->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v48->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v50 = g_SceneFiles.m_Size - v46 - 1;
        if ( v50 > 0 )
          _V_memmove(
            dest: &g_SceneFiles.m_Memory.m_pMemory[v47],
            src: &g_SceneFiles.m_Memory.m_pMemory[v47 + 1],
            count: 96 * v50);
        --g_SceneFiles.m_Size;
        _Error(this: (ISceneTokenProcessor *)&stru_4F8504, a2: pSourceName);
      }
      goto LABEL_76;
    }
    while ( 1 )
    {
      v43 = (v41 + v42) / 2;
      v44 = g_SceneFiles.m_Memory.m_pMemory[v43 - 1].crcFileName;
      if ( (unsigned int)pFilesToUpdate >= v44 )
        break;
      v41 = v43 - 1;
LABEL_51:
      if ( v41 < v42 )
        goto LABEL_54;
    }
    if ( (unsigned int)pFilesToUpdate > v44 )
    {
      v42 = v43 + 1;
      goto LABEL_51;
    }
    v45 = v43 - 1;
    if ( v45 == -1 )
      goto LABEL_54;
    if ( UpdateTargetFile_VCD(
           a1: (char *)pFilesToUpdate,
           pEntry: &g_SceneFiles.m_Memory.m_pMemory[v45],
           pSourceName: v37,
           pTargetName: defaultValue,
           bWriteToZip: false,
           bLittleEndian) == 0 )
      _Error(this: (ISceneTokenProcessor *)&stru_4F84D4, a2: v37);
LABEL_76:
    v36 = (CUtlString *)((char *)j + 16);
    v61 = (__int16 *)((char *)v61 + 1);
    j = (char *)j + 16;
  }
  while ( (int)v61 < nUpdateCount );
LABEL_77:
  CUtlBuffer::SeekPut(this: targetBuffer, type: SEEK_HEAD, offset: 0);
  return CSceneImage::WriteSceneImageFile(this: v54, targetBuffer, bLittleEndian, bQuiet, pStatus);
}

//------------------------------------------------------------------------------
// Address: 0x004B4230
// Name: public: virtual bool CSceneImage::CreateSceneImageFile(class CUtlBuffer __near &,char const __near *,bool,bool,class ISceneCompileStatus __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneImage::CreateSceneImageFile(
        CSceneImage *this,
        CUtlBuffer *targetBuffer,
        const char *pchModPath,
        bool bLittleEndian,
        BOOL bQuiet,
        ISceneCompileStatus *pStatus)
{
  const char *i; // eax
  int v8; // ebx
  const char *v9; // esi
  const char *v10; // eax
  const char *v11; // edi
  fileList_t *v12; // eax
  char v13; // bl
  fileList_t *m_pMemory; // eax
  char searchPaths[512]; // [esp+8h] [ebp-35Ch] BYREF
  char szPath[260]; // [esp+208h] [ebp-15Ch] BYREF
  CUtlSymbolTable vcdSymbolTable; // [esp+30Ch] [ebp-58h] BYREF
  CUtlSymbol v18; // [esp+344h] [ebp-20h] BYREF
  CUtlSymbol v19; // [esp+346h] [ebp-1Eh] BYREF
  CSceneImage *v20; // [esp+348h] [ebp-1Ch]
  unsigned int v21; // [esp+34Ch] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > vcdFileList; // [esp+350h] [ebp-14h] BYREF
  bool bGameIsTF_3; // [esp+373h] [ebp+Fh]

  v20 = this;
  memset(&vcdFileList, 0, sizeof(vcdFileList));
  CUtlSymbolTable::CUtlSymbolTable(this: &vcdSymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  _Msg(a1: "\n");
  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: searchPaths, a5: 512);
  for ( i = strtok(string: searchPaths, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
  {
    V_ComposeFileName(path: i, filename: "scenes/*.vcd", dest: szPath, destSize: 260);
    scriptlib->FindFiles(this: scriptlib, a2: szPath, a3: true, a4: &vcdFileList);
    _Msg(a1: "Scenes: Searching '%s' - Found %d scenes.\n", szPath, 0);
  }
  if ( vcdFileList.m_Size != 0 )
  {
    bGameIsTF_3 = V_stristr(pStr: pchModPath, pSearch: "\\tf") != nullptr;
    v8 = 0;
    if ( vcdFileList.m_Size > 0 )
    {
      v21 = 0;
      do
      {
        v9 = CUtlString::operator char const *(this: &vcdFileList.m_Memory.m_pMemory[v21 / 0x18].fileName);
        v10 = V_stristr(pStr: v9, pSearch: "scenes\\");
        v11 = v10;
        if ( v10 != nullptr
          && (bLittleEndian || !bGameIsTF_3 || V_stristr(pStr: v10, pSearch: "high\\") == nullptr)
          && CUtlSymbolTable::Find(this: &vcdSymbolTable, result: &v19, pString: v11)->m_Id == 0xFFFF )
        {
          CUtlSymbolTable::AddString(this: &vcdSymbolTable, result: &v18, pString: v11);
          pStatus->UpdateStatus(this: pStatus, a2: v9, a3: bQuiet, a4: v8, a5: vcdFileList.m_Size);
          if ( CreateTargetFile_VCD(pSourceName: v9, pTargetName: defaultValue, bWriteToZip: false, bLittleEndian) == 0 )
            _Error(this: (ISceneTokenProcessor *)&stru_4F8504, a2: v9);
        }
        v21 += 24;
        ++v8;
      }
      while ( v8 < vcdFileList.m_Size );
    }
    if ( g_SceneFiles.m_Size != 0 )
    {
      v13 = CSceneImage::WriteSceneImageFile(this: v20, targetBuffer, bLittleEndian, bQuiet, pStatus);
      CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
      CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
      m_pMemory = vcdFileList.m_Memory.m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( vcdFileList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vcdFileList.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          vcdFileList.m_Memory.m_pMemory = nullptr;
        }
        vcdFileList.m_Memory.m_nAllocationCount = 0;
      }
      vcdFileList.m_pElements = m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return v13;
    }
    else
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
      CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
      v12 = vcdFileList.m_Memory.m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( vcdFileList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vcdFileList.m_Memory.m_pMemory);
          v12 = nullptr;
          vcdFileList.m_Memory.m_pMemory = nullptr;
        }
        vcdFileList.m_Memory.m_nAllocationCount = 0;
      }
      vcdFileList.m_pElements = v12;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      return 1;
    }
  }
  else
  {
    _Msg(a1: "Scenes: No Scene Files found!\n");
    CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
    return 0;
  }
}

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004B5970
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSceneTokenProcessor::CurrentToken(CSceneTokenProcessor *this)
{
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x004B5980
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  return GetToken(crossline) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B59A0
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  return TokenAvailable() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B59B0
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  const char *v2; // eax
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 2048, pFormat: fmt, params);
  v2 = CUtlString::Get(this: &this->m_Filename);
  _Warning(a1: "%s: %s", v2, string);
}

//------------------------------------------------------------------------------
// Address: 0x004B5B50
// Name: public: SceneFile_t::~SceneFile_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneFile_t::~SceneFile_t(SceneFile_t *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->soundList);
  if ( this->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->compiledBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->compiledBuffer.m_Memory.m_pMemory);
      this->compiledBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->compiledBuffer.m_Memory.m_nAllocationCount = 0;
  }
  this->fileName.m_Storage.m_nActualLength = 0;
  if ( this->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->fileName.m_Storage.m_Memory.m_pMemory);
      this->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5BB0
// Name: public: void CChoreoStringPool::GetTableAndPool(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoStringPool::GetTableAndPool(
        CChoreoStringPool *this,
        CUtlMemory<S3RGBA,int> *offsets,
        CUtlBuffer *buffer)
{
  CChoreoStringPool *v3; // ebx
  int m_NumElements; // eax
  unsigned int *m_pMemory; // edx
  unsigned int *v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  unsigned int *v11; // ecx
  int v12; // eax
  unsigned int *v13; // ebx
  char *v14; // ebx
  unsigned __int8 m_Flags; // cl
  int m_Put; // eax
  int m_nTab; // eax
  int v18; // ebx
  unsigned int v19; // [esp-4h] [ebp-14h]
  unsigned int currentOffset; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]

  v3 = this;
  offsets[1].m_pMemory = nullptr;
  if ( offsets->m_nGrowSize >= 0 )
  {
    if ( offsets->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: offsets->m_pMemory);
      offsets->m_pMemory = nullptr;
    }
    offsets->m_nAllocationCount = 0;
  }
  offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
  buffer->m_Get = 0;
  buffer->m_Put = 0;
  buffer->m_nOffset = 0;
  buffer->m_nMaxPut = 0;
  buffer->m_Error = 0;
  if ( buffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer->m_Memory.m_pMemory);
      buffer->m_Memory.m_pMemory = nullptr;
    }
    buffer->m_Memory.m_nAllocationCount = 0;
  }
  m_NumElements = v3->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements;
  if ( offsets->m_nAllocationCount < m_NumElements && offsets->m_nGrowSize >= 0 )
  {
    m_pMemory = (unsigned int *)offsets->m_pMemory;
    offsets->m_nAllocationCount = m_NumElements;
    v19 = 4 * m_NumElements;
    if ( m_pMemory != nullptr )
    {
      v8 = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v19);
      v3 = this;
    }
    else
    {
      v8 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v19);
    }
    offsets->m_pMemory = (S3RGBA *)v8;
  }
  offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v3->m_nOffset);
  currentOffset = 0;
  i = 0;
  if ( v3->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v9 = (int)offsets[1].m_pMemory;
      m_nAllocationCount = offsets->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: offsets, num: v9 - m_nAllocationCount + 1);
      ++offsets[1].m_pMemory;
      v11 = (unsigned int *)offsets->m_pMemory;
      v12 = (int)offsets[1].m_pMemory - v9 - 1;
      offsets[1].m_nAllocationCount = (int)offsets->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (unsigned int *)&offsets->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = currentOffset;
      v14 = CUtlSymbolTable::String(this: &this->m_StringMap.m_SymbolTable, id: (CUtlSymbol)i);
      CUtlBuffer::Put(this: buffer, pMem: v14, size: strlen(v14) + 1);
      currentOffset += strlen(v14) + 1;
      ++i;
    }
    while ( i < this->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements );
    v3 = this;
  }
  for ( ; (buffer->m_Put & 3) != 0; ++v3->m_nOffset )
  {
    m_Flags = buffer->m_Flags;
    if ( (m_Flags & 1) != 0 )
    {
      m_Put = buffer->m_Put;
      if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      {
        if ( (m_Flags & 0x10) != 0 )
          m_nTab = 0;
        else
          m_nTab = buffer->m_nTab;
        v18 = m_nTab - 1;
        if ( m_nTab - 1 < 0 )
        {
          v3 = this;
        }
        else
        {
          do
          {
            if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
            {
              buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = 9;
              CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
            }
            --v18;
          }
          while ( v18 >= 0 );
          v3 = this;
        }
      }
    }
    if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5E80
// Name: public: virtual bool CChoreoStringPool::GetString(short,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoStringPool::GetString(CChoreoStringPool *this, __int16 stringId, char *buff, int buffSize)
{
  char *v4; // eax

  if ( stringId < 0 || stringId >= (int)this->m_StringMap.m_SymbolTable.m_Lookup.m_NumElements )
  {
    V_strncpy(pDest: buff, pSrc: pDefaultValue, maxLen: buffSize);
    return 0;
  }
  else
  {
    v4 = CUtlSymbolTable::String(this: &this->m_StringMap.m_SymbolTable, id: (CUtlSymbol)stringId);
    V_strncpy(pDest: buff, pSrc: v4, maxLen: buffSize);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5FD0
// Name: public: virtual short CChoreoStringPool::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CChoreoStringPool::FindOrAddString(CChoreoStringPool *this, char *pString)
{
  char *v2; // ebx
  int m_Id; // eax
  int v5; // ebx
  int m_Size; // ecx
  const char *v8; // [esp-8h] [ebp-18h]
  CUtlSymbolTable *p_m_SymbolTable; // [esp+8h] [ebp-8h]
  CUtlSymbol v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = pString;
  p_m_SymbolTable = &this->m_StringMap.m_SymbolTable;
  m_Id = CUtlSymbolTable::Find(this: &this->m_StringMap.m_SymbolTable, result: &v10, pString)->m_Id;
  if ( m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &this->m_StringMap.m_SymbolTable, result: &v10, pString: v2);
    v5 = v10.m_Id;
    m_Size = this->m_StringMap.m_Vector.m_Size;
    if ( m_Size <= v10.m_Id && m_Size < v10.m_Id + 1 )
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_StringMap,
        elem: m_Size,
        num: v10.m_Id + 1 - m_Size);
    this->m_StringMap.m_Vector.m_Memory.m_pMemory[v5] = this->m_nOffset;
    v8 = pString;
    this->m_nOffset += strlen(pString) + 1;
    LOWORD(m_Id) = (CUtlSymbol)CUtlSymbolTable::Find(
                                 this: p_m_SymbolTable,
                                 result: (CUtlSymbol *)&pString + 1,
                                 pString: v8)->m_Id;
  }
  return m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004B6060
// Name: void FindSoundsInEvent(class CChoreoEvent __near *,class CUtlVector<short,class CUtlMemory<short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindSoundsInEvent(CChoreoEvent *pEvent, CUtlVector<short,CUtlMemory<short,int> > *soundList)
{
  CChoreoEvent *v2; // esi
  char *Parameters; // eax
  __int16 v4; // ax
  CUtlMemory<CUtlSymbol,int> *v5; // esi
  int m_Size; // edi
  __int16 v7; // bx
  int v8; // eax
  __int16 *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CUtlSymbol *v11; // ecx
  int v12; // eax
  CUtlSymbol *v13; // eax
  CChoreoEvent *v14; // edi
  unsigned __int16 v15; // bx
  CUtlSymbol *v16; // edi
  int v17; // eax
  CUtlSymbol *v18; // ecx
  int v19; // eax
  CUtlSymbol *v20; // eax
  char tok[64]; // [esp+4h] [ebp-40h] BYREF

  v2 = pEvent;
  if ( pEvent != nullptr && CChoreoEvent::GetType(this: pEvent) == SPEAK )
  {
    Parameters = CChoreoEvent::GetParameters(this: v2);
    v4 = CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString: Parameters);
    v5 = (CUtlMemory<CUtlSymbol,int> *)soundList;
    m_Size = soundList->m_Size;
    v7 = v4;
    v8 = 0;
    if ( m_Size <= 0 )
      goto LABEL_9;
    m_pMemory = soundList->m_Memory.m_pMemory;
    while ( *m_pMemory != v7 )
    {
      ++v8;
      ++m_pMemory;
      if ( v8 >= m_Size )
        goto LABEL_9;
    }
    if ( v8 == -1 )
    {
LABEL_9:
      m_nAllocationCount = soundList->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<CUtlSymbol,int> *)soundList,
          num: m_Size - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v11 = v5->m_pMemory;
      v12 = (int)v5[1].m_pMemory - m_Size - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 2 * v12);
      v13 = &v5->m_pMemory[m_Size];
      if ( v13 != nullptr )
        v13->m_Id = v7;
    }
    v14 = pEvent;
    if ( CChoreoEvent::GetCloseCaptionType(this: pEvent) == CC_MASTER
      && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v14, dest: tok, destlen: 64) != 0 )
    {
      v15 = CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString: tok);
      pEvent = (CChoreoEvent *)v15;
      if ( CUtlVector<short,CUtlMemory<short,int>>::Find(
             this: (CUtlVector<short,CUtlMemory<short,int> > *)v5,
             src: (const __int16 *)&pEvent) == -1 )
      {
        v16 = v5[1].m_pMemory;
        v17 = v5->m_nAllocationCount;
        if ( (int)&v16->m_Id + 1 > v17 )
          CUtlMemory<CUtlSymbol,int>::Grow(this: v5, num: (int)&v16->m_Id - v17 + 1);
        ++v5[1].m_pMemory;
        v18 = v5->m_pMemory;
        v19 = (char *)v5[1].m_pMemory - (char *)v16 - 1;
        v5[1].m_nAllocationCount = (int)v5->m_pMemory;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[(_DWORD)v16 + 1], src: &v18[(_DWORD)v16], count: 2 * v19);
        v20 = &v5->m_pMemory[(_DWORD)v16];
        if ( v20 != nullptr )
          v20->m_Id = v15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B61A0
// Name: bool UpdateTargetFile_VCD(struct SceneFile_t __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateTargetFile_VCD(
        SceneFile_t *pEntry,
        const char *pSourceName,
        const char *pTargetName,
        bool bWriteToZip,
        bool bLittleEndian)
{
  CVTFTexture *Scene; // eax
  CChoreoScene *v7; // edi
  int v8; // esi
  CChoreoEvent *Event; // eax
  CUtlBuffer *p_compiledBuffer; // esi
  unsigned __int8 *v11; // ebx
  CUtlBuffer sourceBuf; // [esp+8h] [ebp-40h] BYREF
  __int64 v13; // [esp+38h] [ebp-10h]
  unsigned int compressedSize; // [esp+40h] [ebp-8h] BYREF
  unsigned int crcSource; // [esp+44h] [ebp-4h] BYREF

  pEntry->crcFileName = 0;
  CUtlString::Set(this: &pEntry->fileName, pValue: pSourceName);
  CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( scriptlib->ReadFileToBuffer(this: scriptlib, a2: pSourceName, a3: &sourceBuf, a4: false, a5: false) != 0 )
  {
    CRC32_Init(pulCRC: &crcSource);
    CRC32_ProcessBuffer(pulCRC: &crcSource, pBuffer: sourceBuf.m_Memory.m_pMemory, nBuffer: sourceBuf.m_Put);
    CRC32_Final(pulCRC: &crcSource);
    ParseFromMemory(buffer: (char *)sourceBuf.m_Memory.m_pMemory, size: sourceBuf.m_Put);
    CUtlString::operator=(this: &g_SceneTokenProcessor.m_Filename, src: pSourceName);
    Scene = (CVTFTexture *)ChoreoLoadScene(
                             filename: pSourceName,
                             callback: nullptr,
                             tokenizer: &g_SceneTokenProcessor,
                             pfn: _Msg);
    v7 = (CChoreoScene *)Scene;
    if ( Scene != nullptr )
    {
      v8 = 0;
      if ( CChoreoScene::GetNumEvents(this: Scene) > 0 )
      {
        do
        {
          Event = CChoreoScene::GetEvent(this: v7, event: v8);
          FindSoundsInEvent(pEvent: Event, soundList: &pEntry->soundList);
          ++v8;
        }
        while ( v8 < CChoreoScene::GetNumEvents(this: (CVTFTexture *)v7) );
      }
      v13 = (__int64)(CChoreoScene::FindStopTime(this: v7) * 1000.0 + 0.5);
      pEntry->msecs = v13;
      p_compiledBuffer = &pEntry->compiledBuffer;
      v13 = (__int64)(CChoreoScene::FindLastSpeakTime(this: v7) * 1000.0 + 0.5);
      pEntry->lastspeak_msecs = v13;
      pEntry->compiledBuffer.m_Get = 0;
      pEntry->compiledBuffer.m_Put = 0;
      pEntry->compiledBuffer.m_Error = 0;
      pEntry->compiledBuffer.m_nOffset = 0;
      pEntry->compiledBuffer.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &pEntry->compiledBuffer, nPut: 0);
      CUtlBuffer::SetBigEndian(this: &pEntry->compiledBuffer, bigEndian: !bLittleEndian);
      CChoreoScene::SaveToBinaryBuffer(
        this: v7,
        buf: &pEntry->compiledBuffer,
        nTextVersionCRC: crcSource,
        pStringPool: &g_ChoreoStringPool);
      v11 = LZMA_Compress(
              pInput: pEntry->compiledBuffer.m_Memory.m_pMemory,
              inputSize: pEntry->compiledBuffer.m_Put,
              pOutputSize: &compressedSize,
              dictionarySize: 0x12u);
      if ( v11 != nullptr )
      {
        pEntry->compiledBuffer.m_Get = 0;
        pEntry->compiledBuffer.m_Put = 0;
        pEntry->compiledBuffer.m_nOffset = 0;
        pEntry->compiledBuffer.m_nMaxPut = 0;
        pEntry->compiledBuffer.m_Error = 0;
        if ( pEntry->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( p_compiledBuffer->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_compiledBuffer->m_Memory.m_pMemory);
            p_compiledBuffer->m_Memory.m_pMemory = nullptr;
          }
          pEntry->compiledBuffer.m_Memory.m_nAllocationCount = 0;
        }
        CUtlBuffer::EnsureCapacity(this: p_compiledBuffer, num: compressedSize);
        CUtlBuffer::Put(this: p_compiledBuffer, pMem: v11, size: compressedSize);
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      }
      CChoreoScene::~CChoreoScene(this: v7);
      free(pMem: v7);
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6410
// Name: bool CreateTargetFile_VCD(char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetFile_VCD(
        const char *pSourceName,
        const char *pTargetName,
        bool bWriteToZip,
        bool bLittleEndian)
{
  int v4; // edi
  int v5; // esi
  char updated; // bl

  v4 = CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(this: &g_SceneFiles, elem: g_SceneFiles.m_Size);
  v5 = v4;
  updated = UpdateTargetFile_VCD(
              pEntry: &g_SceneFiles.m_Memory.m_pMemory[v4],
              pSourceName,
              pTargetName,
              bWriteToZip,
              bLittleEndian);
  if ( updated == 0 )
  {
    SceneFile_t::~SceneFile_t(this: &g_SceneFiles.m_Memory.m_pMemory[v5]);
    if ( g_SceneFiles.m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &g_SceneFiles.m_Memory.m_pMemory[v5],
        src: &g_SceneFiles.m_Memory.m_pMemory[v5 + 1],
        count: 96 * (g_SceneFiles.m_Size - v4 - 1));
    --g_SceneFiles.m_Size;
  }
  return updated;
}

//------------------------------------------------------------------------------
// Address: 0x004B64A0
// Name: private: bool CSceneImage::WriteSceneImageFile(class CUtlBuffer __near &,bool,bool,class ISceneCompileStatus __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneImage::WriteSceneImageFile(
        CSceneImage *this,
        CUtlBuffer *targetBuffer,
        bool bLittleEndian,
        bool bQuiet,
        ISceneCompileStatus *pStatus)
{
  int v5; // ebx
  int m_Size; // edi
  CUtlBuffer *v7; // esi
  CUtlBuffer *v8; // edi
  int v9; // ecx
  IMemAlloc_vtbl *v10; // edx
  SceneImageEntry_t *v11; // eax
  int v12; // edi
  int v13; // ebx
  CUtlBuffer *v14; // eax
  const char *v15; // eax
  const char *v16; // edi
  const char *v17; // eax
  int v18; // ebx
  int nSceneSummaryOffset; // ebx
  unsigned int v20; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v22; // ecx
  SceneFile_t *m_pMemory; // eax
  int v24; // edi
  int v25; // ecx
  int *v26; // edi
  bool v27; // zf
  int *p_nDataLength; // edi
  int v29; // eax
  CUtlBuffer *v30; // edx
  int v31; // ebx
  CUtlBuffer *v32; // edx
  unsigned int v33; // edi
  int msecs; // ebx
  int v35; // edx
  CUtlBuffer *lastspeak_msecs; // eax
  int *v37; // eax
  int v38; // eax
  int *v39; // eax
  int v40; // eax
  int *v41; // eax
  bool v42; // cc
  int v43; // ebx
  int *v44; // eax
  int v45; // ebx
  unsigned int v46; // edi
  SceneFile_t *v47; // eax
  const char *v49; // [esp+10h] [ebp-1A8h]
  char szCleanName[260]; // [esp+1Ch] [ebp-19Ch] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > stringOffsets; // [esp+120h] [ebp-98h] BYREF
  CUtlBuffer stringPool; // [esp+134h] [ebp-84h] BYREF
  CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> imageDirectory; // [esp+164h] [ebp-54h] BYREF
  SceneImageEntry_t imageEntry; // [esp+180h] [ebp-38h] BYREF
  unsigned int crcFilename; // [esp+190h] [ebp-28h]
  SceneImageHeader_t imageHeader; // [esp+194h] [ebp-24h] BYREF
  int soundCount; // [esp+1A8h] [ebp-10h]
  int iScene; // [esp+1ACh] [ebp-Ch]
  int j; // [esp+1B0h] [ebp-8h] BYREF
  int soundId; // [esp+1B4h] [ebp-4h] BYREF

  _Msg(a1: "Scenes: Finalizing %d unique scenes.\n", g_SceneFiles.m_Size);
  v5 = 0;
  memset(&stringOffsets, 0, sizeof(stringOffsets));
  CUtlBuffer::CUtlBuffer(this: &stringPool, growSize: 0, initSize: 0, nFlags: 0);
  CChoreoStringPool::GetTableAndPool(
    this: &g_ChoreoStringPool,
    offsets: (CUtlMemory<S3RGBA,int> *)&stringOffsets,
    buffer: &stringPool);
  m_Size = stringOffsets.m_Size;
  if ( !bQuiet )
  {
    _Msg(a1: "Scenes: String Table: %d bytes\n", 4 * stringOffsets.m_Size);
    _Msg(a1: "Scenes: String Pool: %d bytes\n", stringPool.m_Put);
  }
  soundCount = stringPool.m_Put + 4 * m_Size + 20 + 16 * g_SceneFiles.m_Size;
  imageHeader.nId = 1179210582;
  imageHeader.nVersion = 3;
  imageHeader.nNumScenes = g_SceneFiles.m_Size;
  imageHeader.nNumStrings = m_Size;
  imageHeader.nSceneEntryOffset = stringPool.m_Put + 4 * m_Size + 20;
  if ( !bLittleEndian )
  {
    imageHeader.nId = _byteswap_ulong(imageHeader.nId);
    imageHeader.nVersion = _byteswap_ulong(imageHeader.nVersion);
    imageHeader.nNumScenes = _byteswap_ulong(imageHeader.nNumScenes);
    imageHeader.nNumStrings = _byteswap_ulong(imageHeader.nNumStrings);
    imageHeader.nSceneEntryOffset = _byteswap_ulong(imageHeader.nSceneEntryOffset);
  }
  v7 = targetBuffer;
  CUtlBuffer::Put(this: targetBuffer, pMem: &imageHeader, size: 20);
  if ( m_Size > 0 )
  {
    do
    {
      v8 = (CUtlBuffer *)(4 * stringOffsets.m_Size + 20 + stringOffsets.m_Memory.m_pMemory[v5]);
      targetBuffer = v8;
      if ( !bLittleEndian )
        v8 = (CUtlBuffer *)_byteswap_ulong((unsigned int)targetBuffer);
      if ( (v7->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v7, pFmt: "%d", v8);
      }
      else
      {
        targetBuffer = v8;
        if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v7->m_Byteswap,
              outputBuffer: (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset],
              inputBuffer: (int *)&targetBuffer,
              count: 1);
          else
            *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = v8;
          v7->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
        }
      }
      ++v5;
    }
    while ( v5 < stringOffsets.m_Size );
  }
  CUtlBuffer::Put(this: v7, pMem: stringPool.m_Memory.m_pMemory, size: stringPool.m_Put);
  v9 = g_SceneFiles.m_Size;
  memset(&imageDirectory, 0, 16);
  imageDirectory.m_pLessContext = nullptr;
  imageDirectory.m_bNeedsSort = false;
  if ( g_SceneFiles.m_Size > 0 )
  {
    v10 = _g_pMemAlloc->__vftable;
    imageDirectory.m_Memory.m_nAllocationCount = g_SceneFiles.m_Size;
    v11 = (SceneImageEntry_t *)v10->Alloc_2(this: _g_pMemAlloc, a2: 16 * g_SceneFiles.m_Size);
    v9 = g_SceneFiles.m_Size;
    imageDirectory.m_Memory.m_pMemory = v11;
  }
  v12 = 0;
  imageDirectory.m_pElements = imageDirectory.m_Memory.m_pMemory;
  iScene = 0;
  if ( v9 > 0 )
  {
    v13 = 0;
    soundId = 0;
    do
    {
      v14 = *(CUtlBuffer **)((char *)&g_SceneFiles.m_Memory.m_pMemory->crcFileName + v13);
      *(_QWORD *)&imageEntry.nDataLength = 0;
      crcFilename = 0;
      if ( v14 == nullptr )
      {
        v15 = CUtlString::operator char const *(this: (CUtlString *)((char *)&g_SceneFiles.m_Memory.m_pMemory->fileName
                                                                   + v13));
        V_strncpy(pDest: szCleanName, pSrc: v15, maxLen: 260);
        _V_strlower(start: szCleanName);
        V_FixSlashes(pname: szCleanName, separator: 92);
        v16 = V_stristr(pStr: szCleanName, pSearch: "scenes\\");
        if ( v16 == nullptr )
        {
          v17 = CUtlString::operator char const *(this: (CUtlString *)((char *)&g_SceneFiles.m_Memory.m_pMemory->fileName
                                                                     + v13));
          _Error(this: (ISceneTokenProcessor *)&stru_5B2FA8, a2: v17);
        }
        v18 = strlen(v16);
        CRC32_Init(pulCRC: (unsigned int *)&targetBuffer);
        CRC32_ProcessBuffer(pulCRC: (unsigned int *)&targetBuffer, pBuffer: v16, nBuffer: v18);
        CRC32_Final(pulCRC: (unsigned int *)&targetBuffer);
        v14 = targetBuffer;
        v12 = iScene;
        v13 = soundId;
      }
      imageEntry.nDataOffset = (int)v14;
      imageEntry.nDataLength = v12;
      if ( CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Find(
             this: &imageDirectory,
             src: (const SceneImageEntry_t *)&imageEntry.nDataOffset) != -1 )
        _Error(this: (ISceneTokenProcessor *)&stru_5B2F68, a2: v49);
      CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Insert(
        this: &imageDirectory,
        src: (const SceneImageEntry_t *)&imageEntry.nDataOffset);
      v9 = g_SceneFiles.m_Size;
      ++v12;
      v13 += 96;
      iScene = v12;
      soundId = v13;
    }
    while ( v12 < g_SceneFiles.m_Size );
  }
  nSceneSummaryOffset = 0;
  v20 = 0;
  memset(&imageEntry, 0, sizeof(imageEntry));
  if ( v9 > 0 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    imageEntry.nDataOffset = v9;
    v20 = (int)Alloc_2(this: _g_pMemAlloc, a2: 4 * v9);
    imageEntry.crcFilename = v20;
  }
  v22 = imageDirectory.m_Size;
  crcFilename = v20;
  soundId = soundCount;
  m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
  if ( imageDirectory.m_Size > 0 )
  {
    targetBuffer = (CUtlBuffer *)&imageDirectory.m_Memory.m_pMemory->nDataOffset;
    j = imageDirectory.m_Size;
    do
    {
      iScene = (int)targetBuffer->m_Memory.m_pMemory;
      v24 = nSceneSummaryOffset;
      if ( nSceneSummaryOffset + 1 > imageEntry.nDataOffset )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&imageEntry,
          num: nSceneSummaryOffset - imageEntry.nDataOffset + 1);
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
        nSceneSummaryOffset = imageEntry.nSceneSummaryOffset;
      }
      imageEntry.nSceneSummaryOffset = ++nSceneSummaryOffset;
      crcFilename = imageEntry.crcFilename;
      if ( nSceneSummaryOffset - v24 - 1 > 0 )
      {
        _V_memmove(
          dest: (void *)(imageEntry.crcFilename + 4 * v24 + 4),
          src: (const void *)(imageEntry.crcFilename + 4 * v24),
          count: 4 * (nSceneSummaryOffset - v24 - 1));
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      }
      v25 = iScene;
      v26 = (int *)(imageEntry.crcFilename + 4 * v24);
      if ( v26 != nullptr )
      {
        *v26 = iScene;
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      }
      targetBuffer = (CUtlBuffer *)((char *)targetBuffer + 16);
      v27 = j-- == 1;
      soundId += 4 * m_pMemory[v25].soundList.m_Size + 12;
    }
    while ( !v27 );
    v22 = imageDirectory.m_Size;
  }
  targetBuffer = (CUtlBuffer *)soundCount;
  j = 0;
  if ( v22 > 0 )
  {
    p_nDataLength = &imageDirectory.m_Memory.m_pMemory->nDataLength;
    do
    {
      v29 = *(_DWORD *)(imageEntry.crcFilename + 4 * j);
      *(p_nDataLength - 1) = soundId;
      v30 = targetBuffer;
      v31 = v29;
      v27 = !bLittleEndian;
      *p_nDataLength = g_SceneFiles.m_Memory.m_pMemory[v29].compiledBuffer.m_Put;
      p_nDataLength[1] = (int)v30;
      if ( v27 )
      {
        iScene = *(p_nDataLength - 2);
        *(p_nDataLength - 2) = _byteswap_ulong(iScene);
        iScene = *(p_nDataLength - 1);
        *(p_nDataLength - 1) = _byteswap_ulong(iScene);
        iScene = *p_nDataLength;
        *p_nDataLength = _byteswap_ulong(iScene);
        iScene = p_nDataLength[1];
        p_nDataLength[1] = _byteswap_ulong(iScene);
      }
      CUtlBuffer::Put(this: v7, pMem: p_nDataLength - 2, size: 16);
      m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
      v32 = (CUtlBuffer *)(&targetBuffer->m_Get + g_SceneFiles.m_Memory.m_pMemory[v31].soundList.m_Size);
      soundId += g_SceneFiles.m_Memory.m_pMemory[v31].compiledBuffer.m_Put;
      p_nDataLength += 4;
      targetBuffer = v32;
      ++j;
    }
    while ( j < imageDirectory.m_Size );
  }
  for ( iScene = 0; iScene < imageDirectory.m_Size; ++iScene )
  {
    v33 = *(_DWORD *)(imageEntry.crcFilename + 4 * iScene);
    msecs = m_pMemory[v33].msecs;
    v35 = m_pMemory[v33].soundList.m_Size;
    lastspeak_msecs = (CUtlBuffer *)m_pMemory[v33].lastspeak_msecs;
    soundId = msecs;
    soundCount = v35;
    targetBuffer = lastspeak_msecs;
    if ( !bLittleEndian )
    {
      msecs = _byteswap_ulong(soundId);
      soundId = msecs;
      soundCount = _byteswap_ulong(soundCount);
      targetBuffer = (CUtlBuffer *)_byteswap_ulong((unsigned int)targetBuffer);
    }
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", msecs);
    }
    else
    {
      if ( !CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        goto LABEL_58;
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        v37 = (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset];
        if ( v37 != nullptr )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(j) = HIBYTE(soundId);
            BYTE1(j) = BYTE2(soundId);
            BYTE2(j) = BYTE1(msecs);
            HIBYTE(j) = msecs;
            _V_memcpy(dest: v37, src: &j, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_58;
          }
          if ( v37 != &soundId )
          {
            *v37 = msecs;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_58;
          }
        }
      }
      else
      {
        *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = msecs;
      }
      v7->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
    }
LABEL_58:
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", targetBuffer);
    }
    else
    {
      if ( !CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        goto LABEL_69;
      v38 = (int)&v7->m_Memory.m_pMemory[-v7->m_nOffset];
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        v39 = (int *)(v7->m_Put + v38);
        if ( v39 != nullptr )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(j) = HIBYTE(targetBuffer);
            BYTE1(j) = BYTE2(targetBuffer);
            BYTE2(j) = BYTE1(targetBuffer);
            HIBYTE(j) = (_BYTE)targetBuffer;
            _V_memcpy(dest: v39, src: &j, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_69;
          }
          if ( v39 != &soundId )
          {
            *v39 = (int)targetBuffer;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_69;
          }
        }
      }
      else
      {
        *(_DWORD *)(v38 + v7->m_Put) = targetBuffer;
      }
      v7->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
    }
LABEL_69:
    if ( (v7->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v7, pFmt: "%d", soundCount);
      goto LABEL_80;
    }
    if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
    {
      v40 = (int)&v7->m_Memory.m_pMemory[-v7->m_nOffset];
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) == 0 )
      {
        *(_DWORD *)(v40 + v7->m_Put) = soundCount;
LABEL_78:
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
        goto LABEL_80;
      }
      v41 = (int *)(v7->m_Put + v40);
      if ( v41 == nullptr )
        goto LABEL_78;
      if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
      {
        LOBYTE(targetBuffer) = HIBYTE(soundCount);
        BYTE1(targetBuffer) = BYTE2(soundCount);
        BYTE2(targetBuffer) = BYTE1(soundCount);
        HIBYTE(targetBuffer) = soundCount;
        _V_memcpy(dest: v41, src: &targetBuffer, count: 4);
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
      }
      else
      {
        if ( v41 == (int *)&targetBuffer )
          goto LABEL_78;
        *v41 = soundCount;
        v7->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
      }
    }
LABEL_80:
    m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
    v42 = g_SceneFiles.m_Memory.m_pMemory[v33].soundList.m_Size <= 0;
    j = 0;
    if ( !v42 )
    {
      do
      {
        v43 = m_pMemory[v33].soundList.m_Memory.m_pMemory[j];
        soundId = v43;
        if ( !bLittleEndian )
        {
          v43 = _byteswap_ulong(soundId);
          soundId = v43;
        }
        if ( (v7->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v7, pFmt: "%d", v43);
          goto LABEL_94;
        }
        if ( CUtlBuffer::CheckPut(this: v7, nSize: 4) )
        {
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset] = v43;
LABEL_92:
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
            goto LABEL_94;
          }
          v44 = (int *)&v7->m_Memory.m_pMemory[v7->m_Put - v7->m_nOffset];
          if ( v44 == nullptr )
            goto LABEL_92;
          if ( (*(_BYTE *)&v7->m_Byteswap & 1) != 0 )
          {
            LOBYTE(targetBuffer) = HIBYTE(soundId);
            BYTE1(targetBuffer) = BYTE2(soundId);
            BYTE2(targetBuffer) = BYTE1(v43);
            HIBYTE(targetBuffer) = v43;
            _V_memcpy(dest: v44, src: &targetBuffer, count: 4);
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
          }
          else
          {
            if ( v44 == (int *)&targetBuffer )
              goto LABEL_92;
            *v44 = v43;
            v7->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v7, nPut: v7->m_Put);
          }
        }
LABEL_94:
        m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
        ++j;
      }
      while ( j < g_SceneFiles.m_Memory.m_pMemory[v33].soundList.m_Size );
    }
  }
  v45 = 0;
  if ( imageDirectory.m_Size > 0 )
  {
    v46 = imageEntry.crcFilename;
    while ( 1 )
    {
      CUtlBuffer::Put(
        this: v7,
        pMem: m_pMemory[*(_DWORD *)(v46 + 4 * v45)].compiledBuffer.m_Memory.m_pMemory,
        size: m_pMemory[*(_DWORD *)(v46 + 4 * v45)].compiledBuffer.m_Put);
      if ( ++v45 >= imageDirectory.m_Size )
        break;
      m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
    }
  }
  if ( !bQuiet )
    _Msg(a1: "Scenes: Final size: %.2f MB\n", (float)((float)v7->m_Put * 0.00000095367432));
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this: &g_SceneFiles);
  v47 = g_SceneFiles.m_Memory.m_pMemory;
  if ( g_SceneFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SceneFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SceneFiles.m_Memory.m_pMemory);
      v47 = nullptr;
      g_SceneFiles.m_Memory.m_pMemory = nullptr;
    }
    g_SceneFiles.m_Memory.m_nAllocationCount = 0;
  }
  g_SceneFiles.m_pElements = v47;
  if ( imageEntry.nDataLength >= 0 && imageEntry.crcFilename != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)imageEntry.crcFilename);
  if ( imageDirectory.m_Memory.m_nGrowSize >= 0 && imageDirectory.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: imageDirectory.m_Memory.m_pMemory);
  if ( stringPool.m_Memory.m_nGrowSize >= 0 )
  {
    if ( stringPool.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stringPool.m_Memory.m_pMemory);
      stringPool.m_Memory.m_pMemory = nullptr;
    }
    stringPool.m_Memory.m_nAllocationCount = 0;
  }
  if ( stringOffsets.m_Memory.m_nGrowSize >= 0 && stringOffsets.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stringOffsets.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6E20
// Name: public: virtual bool CSceneImage::UpdateSceneImageFile(class CUtlBuffer __near &,char const __near *,bool,bool,class ISceneCompileStatus __near *,class CUtlString __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSceneImage::UpdateSceneImageFile@<al>(
        CSceneImage *this@<ecx>,
        const char *a2@<ebx>,
        CUtlBuffer *targetBuffer,
        char *pchModPath,
        BOOL bLittleEndian,
        BOOL bQuiet,
        ISceneCompileStatus *pStatus,
        CUtlString *pFilesToUpdate,
        int nUpdateCount)
{
  char v10; // bl
  SceneFile_t *m_pMemory; // eax
  int *v12; // eax
  int v13; // edi
  signed int i; // esi
  unsigned __int8 *v15; // ebx
  unsigned __int8 *v16; // ebx
  void *v17; // ecx
  void *v18; // edx
  unsigned __int8 *v19; // eax
  int v20; // edi
  unsigned __int8 *v21; // edi
  int v22; // eax
  void *v23; // edx
  SceneFile_t *v24; // esi
  unsigned int v25; // ecx
  void *v26; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  __int16 *v29; // ecx
  int v30; // eax
  __int16 *v31; // edi
  unsigned int v32; // eax
  int v33; // ebx
  int v34; // edi
  unsigned int crcFileName; // esi
  CUtlString *v36; // ecx
  char *v37; // ebx
  const char *v38; // eax
  const char *v39; // edi
  int v40; // esi
  int v41; // ecx
  int v42; // esi
  int v43; // eax
  unsigned int v44; // edx
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  SceneFile_t *v48; // esi
  __int16 *v49; // eax
  int v50; // eax
  const char *v51; // [esp-4h] [ebp-1134h]
  char pString[4096]; // [esp+8h] [ebp-1128h] BYREF
  char pDest[260]; // [esp+1008h] [ebp-128h] BYREF
  CSceneImage *v54; // [esp+110Ch] [ebp-24h]
  char *pSourceName; // [esp+1110h] [ebp-20h]
  unsigned int pMem; // [esp+1114h] [ebp-1Ch] BYREF
  unsigned int v57; // [esp+1118h] [ebp-18h]
  signed int v58; // [esp+111Ch] [ebp-14h]
  signed int v59; // [esp+1120h] [ebp-10h]
  int offset; // [esp+1124h] [ebp-Ch]
  __int16 *v61; // [esp+1128h] [ebp-8h]
  void *j; // [esp+112Ch] [ebp-4h]
  bool pStr_3; // [esp+113Fh] [ebp+Fh]

  v54 = this;
  if ( targetBuffer->m_Put <= 0 )
    return this->CreateSceneImageFile(
             this,
             a2: targetBuffer,
             a3: pchModPath,
             a4: bLittleEndian,
             a5: bQuiet,
             a6: pStatus);
  v51 = a2;
  v10 = 1;
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this: &g_SceneFiles);
  m_pMemory = g_SceneFiles.m_Memory.m_pMemory;
  if ( g_SceneFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SceneFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SceneFiles.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_SceneFiles.m_Memory.m_pMemory = nullptr;
    }
    g_SceneFiles.m_Memory.m_nAllocationCount = 0;
  }
  g_SceneFiles.m_pElements = m_pMemory;
  v12 = g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory;
  g_ChoreoStringPool.m_StringMap.m_Vector.m_Size = 0;
  if ( g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory);
      v12 = nullptr;
      g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    g_ChoreoStringPool.m_StringMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  g_ChoreoStringPool.m_StringMap.m_Vector.m_pElements = v12;
  CUtlSymbolTable::RemoveAll(this: &g_ChoreoStringPool.m_StringMap.m_SymbolTable);
  g_ChoreoStringPool.m_nOffset = 0;
  CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Get(this: targetBuffer, &pMem, size: 20);
  if ( !bLittleEndian )
  {
    pMem = _byteswap_ulong(pMem);
    v57 = _byteswap_ulong(v57);
    v58 = _byteswap_ulong(v58);
    v59 = _byteswap_ulong(v59);
    offset = _byteswap_ulong(offset);
  }
  if ( pMem != 1179210582 )
    v10 = 0;
  if ( v57 == 3 && v10 != 0 )
  {
    v13 = offset;
    CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: 4 * v59 + 20);
    for ( i = 0; i < v59; ++i )
    {
      CUtlBuffer::GetString(this: targetBuffer, pString, nMaxChars: 4096);
      CChoreoStringPool::FindOrAddString(this: &g_ChoreoStringPool, pString);
    }
    CUtlBuffer::SeekGet(this: targetBuffer, type: SEEK_HEAD, offset: v13);
    v15 = &targetBuffer->m_Memory.m_pMemory[v13];
    pSourceName = nullptr;
    if ( v58 > 0 )
    {
      v16 = v15 + 4;
      do
      {
        if ( !bLittleEndian )
        {
          j = *((void **)v16 - 1);
          v17 = *(void **)v16;
          *((_DWORD *)v16 - 1) = _byteswap_ulong((unsigned int)j);
          j = v17;
          v18 = *((void **)v16 + 1);
          *(_DWORD *)v16 = _byteswap_ulong((unsigned int)v17);
          j = v18;
          *((_DWORD *)v16 + 1) = _byteswap_ulong((unsigned int)v18);
          j = *((void **)v16 + 2);
          *((_DWORD *)v16 + 2) = _byteswap_ulong((unsigned int)j);
        }
        v19 = targetBuffer->m_Memory.m_pMemory;
        v20 = *((_DWORD *)v16 + 2);
        j = &targetBuffer->m_Memory.m_pMemory[*(_DWORD *)v16];
        v21 = &v19[v20];
        v22 = CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
                this: &g_SceneFiles,
                elem: g_SceneFiles.m_Size);
        v23 = j;
        v24 = &g_SceneFiles.m_Memory.m_pMemory[v22];
        v24->crcFileName = *((_DWORD *)v16 - 1);
        CUtlBuffer::Put(this: &v24->compiledBuffer, pMem: v23, size: *((_DWORD *)v16 + 1));
        v25 = *((_DWORD *)v21 + 1);
        v24->msecs = *(_DWORD *)v21;
        v26 = *((void **)v21 + 2);
        v24->lastspeak_msecs = v25;
        if ( (int)v26 > 0 )
        {
          v61 = (__int16 *)(v21 + 12);
          for ( j = v26; j != nullptr; j = (char *)j - 1 )
          {
            m_Size = v24->soundList.m_Size;
            m_nAllocationCount = v24->soundList.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CUtlSymbol,int>::Grow(
                this: (CUtlMemory<CUtlSymbol,int> *)&v24->soundList,
                num: m_Size - m_nAllocationCount + 1);
            ++v24->soundList.m_Size;
            v29 = v24->soundList.m_Memory.m_pMemory;
            v30 = v24->soundList.m_Size - m_Size - 1;
            v24->soundList.m_pElements = v29;
            if ( v30 > 0 )
              _V_memmove(dest: &v29[m_Size + 1], src: &v29[m_Size], count: 2 * v30);
            v31 = &v24->soundList.m_Memory.m_pMemory[m_Size];
            if ( v31 != nullptr )
              *v31 = *v61;
            v61 += 2;
          }
        }
        v16 += 16;
        ++pSourceName;
      }
      while ( (int)pSourceName < v58 );
    }
  }
  v32 = 0;
  v33 = 0;
  if ( g_SceneFiles.m_Size > 0 )
  {
    v34 = 0;
    do
    {
      crcFileName = g_SceneFiles.m_Memory.m_pMemory[v34].crcFileName;
      if ( crcFileName <= v32 )
        _Error(this: (ISceneTokenProcessor *)&stru_5B3108, a2: v51);
      ++v33;
      ++v34;
      v32 = crcFileName;
    }
    while ( v33 < g_SceneFiles.m_Size );
  }
  pStr_3 = V_stristr(pStr: pchModPath, pSearch: "\\tf") != nullptr;
  v61 = nullptr;
  if ( nUpdateCount <= 0 )
    goto LABEL_77;
  v36 = pFilesToUpdate;
  j = pFilesToUpdate;
  do
  {
    v37 = (char *)CUtlString::operator char const *(this: v36);
    pSourceName = v37;
    v38 = V_stristr(pStr: v37, pSearch: "scenes\\");
    if ( v38 == nullptr || !bLittleEndian && pStr_3 && V_stristr(pStr: v38, pSearch: "high\\") != nullptr )
      goto LABEL_76;
    V_strncpy(pDest, pSrc: v37, maxLen: 260);
    _V_strlower(start: pDest);
    V_FixSlashes(pname: pDest, separator: 92);
    v39 = V_stristr(pStr: pDest, pSearch: "scenes\\");
    if ( v39 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_5B30BC, a2: v37);
    v40 = strlen(v39);
    CRC32_Init(pulCRC: (unsigned int *)&pFilesToUpdate);
    CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pFilesToUpdate, pBuffer: v39, nBuffer: v40);
    CRC32_Final(pulCRC: (unsigned int *)&pFilesToUpdate);
    pStatus->UpdateStatus(this: pStatus, a2: v37, a3: bQuiet, a4: (int)v61, a5: nUpdateCount);
    v41 = g_SceneFiles.m_Size;
    v42 = 1;
    if ( g_SceneFiles.m_Size < 1 )
    {
LABEL_54:
      v46 = CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
              this: &g_SceneFiles,
              elem: g_SceneFiles.m_Size);
      v47 = v46;
      if ( UpdateTargetFile_VCD(
             pEntry: &g_SceneFiles.m_Memory.m_pMemory[v46],
             pSourceName,
             pTargetName: pDefaultValue,
             bWriteToZip: false,
             bLittleEndian) == 0 )
      {
        v48 = &g_SceneFiles.m_Memory.m_pMemory[v47];
        v48->soundList.m_Size = 0;
        if ( v48->soundList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->soundList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->soundList.m_Memory.m_pMemory);
            v48->soundList.m_Memory.m_pMemory = nullptr;
          }
          v48->soundList.m_Memory.m_nAllocationCount = 0;
        }
        v49 = v48->soundList.m_Memory.m_pMemory;
        v48->soundList.m_pElements = v49;
        if ( v48->soundList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v49 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v49);
            v48->soundList.m_Memory.m_pMemory = nullptr;
          }
          v48->soundList.m_Memory.m_nAllocationCount = 0;
        }
        if ( v48->compiledBuffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->compiledBuffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->compiledBuffer.m_Memory.m_pMemory);
            v48->compiledBuffer.m_Memory.m_pMemory = nullptr;
          }
          v48->compiledBuffer.m_Memory.m_nAllocationCount = 0;
        }
        v48->fileName.m_Storage.m_nActualLength = 0;
        if ( v48->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v48->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48->fileName.m_Storage.m_Memory.m_pMemory);
            v48->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v48->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v50 = g_SceneFiles.m_Size - v46 - 1;
        if ( v50 > 0 )
          _V_memmove(
            dest: &g_SceneFiles.m_Memory.m_pMemory[v47],
            src: &g_SceneFiles.m_Memory.m_pMemory[v47 + 1],
            count: 96 * v50);
        --g_SceneFiles.m_Size;
        _Error(this: (ISceneTokenProcessor *)&stru_5B3088, a2: pSourceName);
      }
      goto LABEL_76;
    }
    while ( 1 )
    {
      v43 = (v41 + v42) / 2;
      v44 = g_SceneFiles.m_Memory.m_pMemory[v43 - 1].crcFileName;
      if ( (unsigned int)pFilesToUpdate >= v44 )
        break;
      v41 = v43 - 1;
LABEL_51:
      if ( v41 < v42 )
        goto LABEL_54;
    }
    if ( (unsigned int)pFilesToUpdate > v44 )
    {
      v42 = v43 + 1;
      goto LABEL_51;
    }
    v45 = v43 - 1;
    if ( v45 == -1 )
      goto LABEL_54;
    if ( UpdateTargetFile_VCD(
           pEntry: &g_SceneFiles.m_Memory.m_pMemory[v45],
           pSourceName: v37,
           pTargetName: pDefaultValue,
           bWriteToZip: false,
           bLittleEndian) == 0 )
      _Error(this: (ISceneTokenProcessor *)&stru_5B3058, a2: v37);
LABEL_76:
    v36 = (CUtlString *)((char *)j + 16);
    v61 = (__int16 *)((char *)v61 + 1);
    j = (char *)j + 16;
  }
  while ( (int)v61 < nUpdateCount );
LABEL_77:
  CUtlBuffer::SeekPut(this: targetBuffer, type: SEEK_HEAD, offset: 0);
  return CSceneImage::WriteSceneImageFile(this: v54, targetBuffer, bLittleEndian, bQuiet, pStatus);
}

//------------------------------------------------------------------------------
// Address: 0x004B7460
// Name: public: virtual bool CSceneImage::CreateSceneImageFile(class CUtlBuffer __near &,char const __near *,bool,bool,class ISceneCompileStatus __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneImage::CreateSceneImageFile(
        CSceneImage *this,
        CUtlBuffer *targetBuffer,
        const char *pchModPath,
        bool bLittleEndian,
        BOOL bQuiet,
        ISceneCompileStatus *pStatus)
{
  const char *i; // eax
  int v8; // ebx
  const char *v9; // esi
  const char *v10; // eax
  char *v11; // edi
  fileList_t *v12; // eax
  char v13; // bl
  fileList_t *m_pMemory; // eax
  char searchPaths[512]; // [esp+8h] [ebp-35Ch] BYREF
  char szPath[260]; // [esp+208h] [ebp-15Ch] BYREF
  CUtlSymbolTable vcdSymbolTable; // [esp+30Ch] [ebp-58h] BYREF
  CUtlSymbol v18; // [esp+344h] [ebp-20h] BYREF
  CUtlSymbol v19; // [esp+346h] [ebp-1Eh] BYREF
  CSceneImage *v20; // [esp+348h] [ebp-1Ch]
  unsigned int v21; // [esp+34Ch] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > vcdFileList; // [esp+350h] [ebp-14h] BYREF
  bool bGameIsTF_3; // [esp+373h] [ebp+Fh]

  v20 = this;
  memset(&vcdFileList, 0, sizeof(vcdFileList));
  CUtlSymbolTable::CUtlSymbolTable(this: &vcdSymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  _Msg(a1: "\n");
  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: searchPaths, a5: 512);
  for ( i = strtok(string: searchPaths, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
  {
    V_ComposeFileName(path: i, filename: "scenes/*.vcd", dest: szPath, destSize: 260);
    scriptlib->FindFiles(this: scriptlib, a2: szPath, a3: true, a4: &vcdFileList);
    _Msg(a1: "Scenes: Searching '%s' - Found %d scenes.\n", szPath, 0);
  }
  if ( vcdFileList.m_Size != 0 )
  {
    bGameIsTF_3 = V_stristr(pStr: pchModPath, pSearch: "\\tf") != nullptr;
    v8 = 0;
    if ( vcdFileList.m_Size > 0 )
    {
      v21 = 0;
      do
      {
        v9 = CUtlString::operator char const *(this: &vcdFileList.m_Memory.m_pMemory[v21 / 0x18].fileName);
        v10 = V_stristr(pStr: v9, pSearch: "scenes\\");
        v11 = (char *)v10;
        if ( v10 != nullptr
          && (bLittleEndian || !bGameIsTF_3 || V_stristr(pStr: v10, pSearch: "high\\") == nullptr)
          && CUtlSymbolTable::Find(this: &vcdSymbolTable, result: &v19, pString: v11)->m_Id == 0xFFFF )
        {
          CUtlSymbolTable::AddString(this: &vcdSymbolTable, result: &v18, pString: v11);
          pStatus->UpdateStatus(this: pStatus, a2: v9, a3: bQuiet, a4: v8, a5: vcdFileList.m_Size);
          if ( CreateTargetFile_VCD(pSourceName: v9, pTargetName: pDefaultValue, bWriteToZip: false, bLittleEndian) == 0 )
            _Error(this: (ISceneTokenProcessor *)&stru_5B3088, a2: v9);
        }
        v21 += 24;
        ++v8;
      }
      while ( v8 < vcdFileList.m_Size );
    }
    if ( g_SceneFiles.m_Size != 0 )
    {
      v13 = CSceneImage::WriteSceneImageFile(this: v20, targetBuffer, bLittleEndian, bQuiet, pStatus);
      CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
      CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
      m_pMemory = vcdFileList.m_Memory.m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( vcdFileList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vcdFileList.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          vcdFileList.m_Memory.m_pMemory = nullptr;
        }
        vcdFileList.m_Memory.m_nAllocationCount = 0;
      }
      vcdFileList.m_pElements = m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return v13;
    }
    else
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
      CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
      v12 = vcdFileList.m_Memory.m_pMemory;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( vcdFileList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vcdFileList.m_Memory.m_pMemory);
          v12 = nullptr;
          vcdFileList.m_Memory.m_pMemory = nullptr;
        }
        vcdFileList.m_Memory.m_nAllocationCount = 0;
      }
      vcdFileList.m_pElements = v12;
      if ( vcdFileList.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      return 1;
    }
  }
  else
  {
    _Msg(a1: "Scenes: No Scene Files found!\n");
    CUtlSymbolTable::~CUtlSymbolTable(this: &vcdSymbolTable);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&vcdFileList);
    return 0;
  }
}

} // namespace makegamedata
