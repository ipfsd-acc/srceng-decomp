// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/sfmphonemeextractor.cpp
// Functions: 20
// ============================================================

#include "sfmobjects\sfmphonemeextractor.h"

//------------------------------------------------------------------------------
// Address: 0x0053A290
// Name: UniquePhonemeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl UniquePhonemeLessFunc(CBasePhonemeTag *const *lhs, CBasePhonemeTag *const *rhs)
{
  return (*lhs)->m_nPhonemeCode < (*rhs)->m_nPhonemeCode;
}

//------------------------------------------------------------------------------
// Address: 0x0053A310
// Name: public: virtual void CSFMPhonemeExtractor::GetAPIInfo(int,class CUtlString __near *,enum PE_APITYPE __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::GetAPIInfo(
        CSFMPhonemeExtractor *this,
        int index,
        CUtlString *pPrintName,
        PE_APITYPE *pAPIType)
{
  IPhonemeExtractor *extractor; // ecx
  const char *v6; // eax

  extractor = this->m_Extractors.m_Memory.m_pMemory[index].extractor;
  v6 = extractor->GetName(this: extractor);
  CUtlString::Set(this: pPrintName, pValue: v6);
  *pAPIType = this->m_Extractors.m_Memory.m_pMemory[index].apitype;
}

//------------------------------------------------------------------------------
// Address: 0x0053B220
// Name: public: virtual void CSFMPhonemeExtractor::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::Shutdown(CSFMPhonemeExtractor *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Extractors.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: this->m_Extractors.m_Memory.m_pMemory[v3--].module);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Extractors.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0053B260
// Name: private: bool CSFMPhonemeExtractor::GetWaveFormat(char const __near *,class CUtlBuffer __near *,int __near *,class CSentence __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSFMPhonemeExtractor::GetWaveFormat(
        CSFMPhonemeExtractor *this,
        const char *filename,
        CUtlBuffer *pBuf,
        int *pDataSize,
        CSentence *sentence,
        bool *bGotSentence)
{
  char v6; // bl
  unsigned int Name; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  CUtlBuffer v12; // [esp+Ch] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+3Ch] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+54h] [ebp-10h] BYREF
  char gotData_3; // [esp+6Fh] [ebp+Bh]

  InFileRIFF::InFileRIFF(this: &riff, pFileName: filename, io: g_pFSIOReadBinary);
  IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
  v6 = 0;
  gotData_3 = 0;
  *bGotSentence = false;
  if ( !IterateRIFF::ChunkAvailable(this: &walk) )
    goto LABEL_18;
  do
  {
    Name = ConCommandBase::GetName(this: &walk);
    if ( Name == 544501094 )
    {
      v11 = IterateRIFF::ChunkSize(this: &walk);
      CUtlBuffer::SeekPut(this: pBuf, type: SEEK_HEAD, offset: v11);
      IterateRIFF::ChunkRead(this: &walk, pOutput: pBuf->m_Memory.m_pMemory);
      v6 = 1;
    }
    else
    {
      if ( Name == 1413563478 )
      {
        *bGotSentence = true;
        CUtlBuffer::CUtlBuffer(this: &v12, growSize: 0, initSize: 0, nFlags: 1u);
        v9 = IterateRIFF::ChunkSize(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v12, num: v9);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v12.m_Memory.m_pMemory);
        v10 = IterateRIFF::ChunkSize(this: &walk);
        CUtlBuffer::SeekPut(this: &v12, type: SEEK_HEAD, offset: v10);
        CSentence::InitFromDataChunk(this: sentence, data: v12.m_Memory.m_pMemory, size: v12.m_Put);
        if ( v12.m_Memory.m_nGrowSize >= 0 && v12.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Memory.m_pMemory);
      }
      else if ( Name == 1635017060 )
      {
        *pDataSize = IterateRIFF::ChunkSize(this: &walk);
        gotData_3 = 1;
      }
      if ( v6 == 0 )
        goto LABEL_9;
    }
    if ( gotData_3 != 0 && *bGotSentence )
      goto LABEL_12;
LABEL_9:
    IterateRIFF::ChunkNext(this: &walk);
  }
  while ( IterateRIFF::ChunkAvailable(this: &walk) );
  if ( v6 != 0 && gotData_3 != 0 )
  {
LABEL_12:
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
LABEL_18:
  InFileRIFF::~InFileRIFF(this: &riff);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0053B3F0
// Name: public: virtual bool CSFMPhonemeExtractor::GetSentence(class CDmeGameSound __near *,class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSFMPhonemeExtractor::GetSentence(
        CSFMPhonemeExtractor *this,
        CDmeGameSound *gameSound,
        CSentence *sentence)
{
  char *m_Id; // eax
  char *v5; // eax
  char fullpath[512]; // [esp+4h] [ebp-430h] BYREF
  char soundname[512]; // [esp+204h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+404h] [ebp-30h] BYREF

  m_Id = (char *)gameSound->m_SoundName.m_Storage.u.CDmeSound::m_Id;
  if ( m_Id == (char *)-1 )
    m_Id = (char *)&pParentName;
  v5 = PSkipSoundChars(pch: m_Id);
  V_snprintf(pDest: soundname, maxLen: 512, pFormat: "sound/%s", v5);
  V_FixSlashes(pname: soundname, separator: 92);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: soundname,
    a3: "GAME",
    a4: fullpath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  HIBYTE(gameSound) = 0;
  if ( CSFMPhonemeExtractor::GetWaveFormat(
         this,
         filename: soundname,
         pBuf: &buf,
         pDataSize: (int *)&sentence,
         sentence,
         bGotSentence: (bool *)&gameSound + 3) != 0 )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return HIBYTE(gameSound);
  }
  else
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B4F0
// Name: StoreValveDataChunk
// Source: json
//------------------------------------------------------------------------------
void __cdecl StoreValveDataChunk(CSentence *sentence, IterateOutputRIFF *store)
{
  CUtlBuffer buf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  CSentence::SaveToBuffer(this: sentence, &buf);
  IterateOutputRIFF::ChunkWriteData(this: store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0053B550
// Name: SaveSentenceToWavFile
// Source: json
//------------------------------------------------------------------------------
char __usercall SaveSentenceToWavFile@<al>(const char *pWavFile@<esi>, int a2@<ebx>, int a3@<edi>, CSentence *sentence)
{
  CP4File *v4; // edi
  char v6; // bl
  unsigned int Name; // eax
  char pTempFile[512]; // [esp+0h] [ebp-290h] BYREF
  OutFileRIFF riffout; // [esp+200h] [ebp-90h] BYREF
  CUtlBuffer buf; // [esp+21Ch] [ebp-74h] BYREF
  InFileRIFF riff; // [esp+24Ch] [ebp-44h] BYREF
  IterateOutputRIFF store; // [esp+25Ch] [ebp-34h] BYREF
  IterateRIFF walk; // [esp+278h] [ebp-18h] BYREF

  V_StripExtension(in: pWavFile, out: pTempFile, outSize: 512);
  V_DefaultExtension(path: pTempFile, extension: ".tmp", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pTempFile, a3: "GAME") )
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pTempFile, a3: "GAME");
  v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pWavFile);
  ((void (__thiscall *)(CP4File *, int))v4->Edit)(a1: v4, a2: a3);
  if ( g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: pWavFile, a3: nullptr) )
  {
    ((void (__thiscall *)(IFileSystem *, const char *, char *, const char *, int))g_pFullFileSystem->RenameFile)(
      a1: g_pFullFileSystem,
      a2: pWavFile,
      a3: pTempFile,
      a4: "GAME",
      a5: a2);
    InFileRIFF::InFileRIFF(this: &riff, pFileName: pTempFile, io: g_pFSIOReadBinary);
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    OutFileRIFF::OutFileRIFF(this: &riffout, pFileName: (int)pWavFile, io: (int)g_pFSIOWriteBinary);
    IterateOutputRIFF::IterateOutputRIFF(this: &store, riff: &riffout);
    v6 = 0;
    if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      goto LABEL_14;
    do
    {
      Name = ConCommandBase::GetName(this: &walk);
      IterateOutputRIFF::ChunkStart(this: &store, chunkname: Name);
      if ( ConCommandBase::GetName(this: &walk) == 1413563478 )
      {
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
        CSentence::SaveToBuffer(this: sentence, &buf);
        IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        v6 = 1;
      }
      else
      {
        IterateOutputRIFF::CopyChunkData(this: &store, input: &walk);
      }
      IterateOutputRIFF::ChunkFinish(this: &store);
      IterateRIFF::ChunkNext(this: &walk);
    }
    while ( IterateRIFF::ChunkAvailable(this: &walk) );
    if ( v6 == 0 )
    {
LABEL_14:
      IterateOutputRIFF::ChunkStart(this: &store, chunkname: 0x54414456u);
      StoreValveDataChunk(sentence, &store);
      IterateOutputRIFF::ChunkFinish(this: &store);
    }
    OutFileRIFF::~OutFileRIFF(this: &riffout);
    InFileRIFF::~InFileRIFF(this: &riff);
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pTempFile, a3: nullptr);
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 1;
  }
  else
  {
    _Warning(a1: "%s is not writable, can't save sentence data to file\n", pWavFile);
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B7A0
// Name: void AddBookmarkAtSoundMediaTime(char const __near *,class DmeTime_t,class DmeTime_t,struct DmeClipStack_t const __near &,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBookmarkAtSoundMediaTime(
        const char *pName,
        DmeTime_t tStart,
        DmeTime_t tEnd,
        DmeClipStack_t *srcStack,
        ExtractDesc_t *info)
{
  DmeTime_t *v5; // eax
  ExtractDesc_t *v6; // esi
  DmeTime_t *v7; // eax
  DmeTime_t *v8; // eax
  DmeTime_t *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  CDmAttribute *m_Id; // ecx
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *Bookmarks; // esi
  DmeTime_t result; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t v17; // [esp+10h] [ebp-4h] BYREF
  ExtractDesc_t *tStarta; // [esp+20h] [ebp+Ch]
  ExtractDesc_t *tEnda; // [esp+24h] [ebp+10h]

  v5 = DmeClipStack_t::FromChildMediaTime(this: srcStack, &result, t: tStart, bClamp: false);
  v6 = info;
  v7 = CDmeClip::ToChildMediaTime(this: info->m_pMovie, result: (DmeTime_t *)&info, t: (DmeTime_t)v5->m_tms, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: v6->m_pShot, result: &v17, t: (DmeTime_t)v7->m_tms, bClamp: 0);
  tStarta = (ExtractDesc_t *)v17.m_tms;
  v8 = DmeClipStack_t::FromChildMediaTime(this: srcStack, &result, t: tEnd, bClamp: false);
  v9 = CDmeClip::ToChildMediaTime(this: v6->m_pMovie, result: &v17, t: (DmeTime_t)v8->m_tms, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: v6->m_pShot, result: (DmeTime_t *)&info, t: (DmeTime_t)v9->m_tms, bClamp: 0);
  tEnda = info;
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeBookmark::m_classType.u.m_Id,
          a3: pName,
          a4: v6->m_pShot->m_fileId,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = v11;
  if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeBookmark::m_classType) )
    v12 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&info, a3: pName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: *(CDmAttribute **)v12[1].m_Id.m_Value,
    value: (const CUtlSymbolLarge *)&info);
  info = tStarta;
  CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)&v12[1].m_Id.m_Value[8], value: (const DmeTime_t *)&info);
  m_Id = (CDmAttribute *)v12[1].m_Name.m_Storage.u.m_Id;
  info = (ExtractDesc_t *)((char *)tEnda - (char *)tStarta);
  CDmAttribute::SetValue<DmeTime_t>(this: m_Id, value: (const DmeTime_t *)&info);
  ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: v6->m_pShot);
  if ( ActiveBookmarkSet != nullptr )
  {
    Bookmarks = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
    info = (ExtractDesc_t *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v12);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: Bookmarks,
      src: (DmElementHandle_t *)&info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053D510
// Name: private: class CDmeChannelsClip __near * CSFMPhonemeExtractor::FindFacialChannelsClip(class CUtlVector<struct LogPreview_t __near *,class CUtlMemory<struct LogPreview_t __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CSFMPhonemeExtractor::FindFacialChannelsClip(
        CSFMPhonemeExtractor *this,
        const CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *list)
{
  CDmeChannelsClip *v2; // esi
  int v3; // edi
  CDmElement *v4; // eax
  char *v5; // eax
  CExpressionCalculator *v6; // ecx
  CDmeChannelsClip *Referring; // eax

  v2 = nullptr;
  v3 = list->m_Size - 1;
  if ( v3 < 0 )
    goto LABEL_13;
  do
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: list->m_Memory.m_pMemory[v3]->m_hChannels[0].m_handle);
    if ( v4 != nullptr && (v5 = (char *)&v4[-1] + 64) != nullptr )
      v6 = (CExpressionCalculator *)(v5 + 4);
    else
      v6 = nullptr;
    Referring = FindReferringElement<CDmeChannelsClip>(
                  pElement: v6,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( v2 != nullptr )
    {
      if ( v2 != Referring )
        _Warning(a1: "Selected controls overlap multiple channels clips!!!\n");
    }
    else if ( Referring != nullptr )
    {
      v2 = Referring;
    }
    --v3;
  }
  while ( v3 >= 0 );
  if ( v2 == nullptr )
LABEL_13:
    _Warning(a1: "Unable to determine destination channels clip!!!\n");
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0053D610
// Name: public: virtual bool CSFMPhonemeExtractor::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSFMPhonemeExtractor::Init@<al>(CSFMPhonemeExtractor *this@<ecx>, int a2@<edi>)
{
  const char *i; // eax
  struct CSysModule *v4; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IPhonemeExtractor *v6; // eax
  char fullpath[512]; // [esp+4h] [ebp-210h] BYREF
  Extractor e; // [esp+204h] [ebp-10h] BYREF
  int findHandle; // [esp+210h] [ebp-4h] BYREF

  for ( i = g_pFullFileSystem->FindFirstEx(
              this: g_pFullFileSystem,
              a2: "phonemeextractors/*.dll",
              a3: "EXECUTABLE_PATH",
              a4: &findHandle);
        i != nullptr;
        i = (const char *)((int (__thiscall *)(IFileSystem *))g_pFullFileSystem->FindNext)(a1: g_pFullFileSystem) )
  {
    V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "phonemeextractors/%s", i);
    v4 = (struct CSysModule *)((int (__thiscall *)(IFileSystem *, char *, _DWORD, int, int))g_pFullFileSystem->LoadModule)(
                                a1: g_pFullFileSystem,
                                a2: fullpath,
                                a3: 0,
                                a4: 1,
                                a5: a2);
    e.module = v4;
    if ( v4 != nullptr )
    {
      Factory = Sys_GetFactory(pModule: v4);
      if ( Factory != nullptr )
      {
        v6 = (IPhonemeExtractor *)Factory(a1: "PHONEME_EXTRACTOR_001", a2: nullptr);
        e.extractor = v6;
        if ( v6 != nullptr )
        {
          e.apitype = v6->GetAPIType(this: v6);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: &this->m_Extractors,
            elem: this->m_Extractors.m_Size,
            src: &e);
        }
        else
        {
          _Warning(
            a1: "Unable to get IPhonemeExtractor interface version %s from %s\n",
            "PHONEME_EXTRACTOR_001",
            fullpath);
        }
      }
    }
    a2 = findHandle;
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0053D730
// Name: BuildPhonemeStream
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildPhonemeStream(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list@<esi>, CSentence *in)
{
  CSentence *v2; // edi
  int v3; // ecx
  CWordTag *v4; // ebx
  int v5; // eax
  const CBasePhonemeTag *v6; // edi
  CBasePhonemeTag *v7; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CBasePhonemeTag **v10; // ecx
  int v11; // eax
  CBasePhonemeTag **v12; // eax
  int m_Size; // eax
  int v14; // ebx
  CBasePhonemeTag *v15; // eax
  int v16; // edi
  int v17; // eax
  CBasePhonemeTag **v18; // ecx
  int v19; // eax
  CBasePhonemeTag **v20; // eax
  int i; // [esp+8h] [ebp-Ch]
  CBasePhonemeTag *ia; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  CBasePhonemeTag *newTag; // [esp+10h] [ebp-4h]

  v2 = in;
  v3 = 0;
  for ( i = 0; v3 < v2->m_Words.m_Size; i = v3 )
  {
    v4 = v2->m_Words.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      v5 = 0;
      j = 0;
      if ( v4->m_Phonemes.m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Phonemes.m_Memory.m_pMemory[v5];
          if ( v6 != nullptr )
          {
            v7 = (CBasePhonemeTag *)operator new(nSize: 0xCu);
            if ( v7 != nullptr )
              newTag = CBasePhonemeTag::CBasePhonemeTag(this: v7, from: v6);
            else
              newTag = nullptr;
            m_pMemory = (int)list[1].m_pMemory;
            m_nAllocationCount = list->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
            ++list[1].m_pMemory;
            v10 = (CBasePhonemeTag **)list->m_pMemory;
            v11 = (int)list[1].m_pMemory - m_pMemory - 1;
            list[1].m_nAllocationCount = (int)list->m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
            v12 = (CBasePhonemeTag **)&list->m_pMemory[m_pMemory];
            if ( v12 != nullptr )
              *v12 = newTag;
          }
          v5 = j + 1;
          j = v5;
        }
        while ( v5 < v4->m_Phonemes.m_Size );
        v2 = in;
        v3 = i;
      }
    }
    ++v3;
  }
  if ( v2->m_Words.m_Size == 0 )
  {
    m_Size = v2->m_RunTimePhonemes.m_Size;
    if ( m_Size != 0 )
    {
      v14 = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v15 = (CBasePhonemeTag *)operator new(nSize: 0xCu);
          if ( v15 != nullptr )
            ia = CBasePhonemeTag::CBasePhonemeTag(this: v15, from: v2->m_RunTimePhonemes.m_Memory.m_pMemory[v14]);
          else
            ia = nullptr;
          v16 = (int)list[1].m_pMemory;
          v17 = list->m_nAllocationCount;
          if ( v16 + 1 > v17 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v16 - v17 + 1);
          ++list[1].m_pMemory;
          v18 = (CBasePhonemeTag **)list->m_pMemory;
          v19 = (int)list[1].m_pMemory - v16 - 1;
          list[1].m_nAllocationCount = (int)list->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v20 = (CBasePhonemeTag **)&list->m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = ia;
          if ( ++v14 >= in->m_RunTimePhonemes.m_Size )
            break;
          v2 = in;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053D8D0
// Name: private: void CSFMPhonemeExtractor::BuildPhonemeLogList(class CUtlVector<struct LogPreview_t __near *,class CUtlMemory<struct LogPreview_t __near *,int>> __near &,class CUtlVector<class CDmeLog __near *,class CUtlMemory<class CDmeLog __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::BuildPhonemeLogList(
        CSFMPhonemeExtractor *this,
        CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *list,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *logs)
{
  CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *v3; // ecx
  int v4; // eax
  DmElementHandle_t *p_m_handle; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // eax
  CDmeChannel *v9; // ecx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeLog **v12; // ecx
  int v13; // eax
  CDmeLog **v14; // eax
  CDmeLog *log; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]
  int logsa; // [esp+14h] [ebp+Ch]

  v3 = list;
  v4 = 0;
  for ( i = 0; v4 < list->m_Size; i = v4 )
  {
    p_m_handle = &v3->m_Memory.m_pMemory[v4]->m_hChannels[0].m_handle;
    for ( logsa = 3; logsa != 0; --logsa )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
      if ( v7 != nullptr && v7 != (CDmElement *)4 )
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
        v9 = v8 != nullptr ? (CDmeChannel *)((char *)&v8[-1] + 64) : nullptr;
        log = CDmeChannel::GetLog(this: v9);
        if ( log != nullptr )
        {
          m_pMemory = (int)logs[1].m_pMemory;
          m_nAllocationCount = logs->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: logs, num: m_pMemory - m_nAllocationCount + 1);
          ++logs[1].m_pMemory;
          v12 = (CDmeLog **)logs->m_pMemory;
          v13 = (int)logs[1].m_pMemory - m_pMemory - 1;
          logs[1].m_nAllocationCount = (int)logs->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
          v14 = (CDmeLog **)&logs->m_pMemory[m_pMemory];
          if ( v14 != nullptr )
            *v14 = log;
        }
      }
      ++p_m_handle;
    }
    v3 = list;
    v4 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DB40
// Name: private: void CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(class DmeTime_t,class CUtlDict<struct LogPreview_t __near *,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
        CSFMPhonemeExtractor *this,
        DmeTime_t tHeadPosition,
        const CUtlDict<LogPreview_t *,int> *controlLookup)
{
  int Inorder; // eax
  LogPreview_t *elem; // edi
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  CDmaVar<float> *m_pData; // eax
  DmElementHandle_t *p_m_handle; // edi
  int i; // ebx
  CDmElement *v11; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v13; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // eax
  float flDefaultValue; // [esp+Ch] [ebp-8h] BYREF
  int j; // [esp+10h] [ebp-4h]

  Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup->m_Elements.m_Tree);
  j = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      elem = controlLookup->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: elem->m_hControl.m_handle);
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "defaultValue");
      v7 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v7, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      flDefaultValue = m_pData->m_Storage;
      p_m_handle = &elem->m_hChannels[0].m_handle;
      for ( i = 3; i != 0; --i )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
        if ( v11 != nullptr && v11 != (CDmElement *)4 )
        {
          Log = CDmeChannel::GetLog(this: (CDmeChannel *)((char *)&v11[-1] + 64));
          v13 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
          if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
          {
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v13);
            Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(this: v13, index: TopmostLayer);
            if ( Layer != nullptr )
              CDmeTypedLogLayer<float>::InsertKey(
                this: Layer,
                nTime: tHeadPosition,
                value: &flDefaultValue,
                interpSetting: SEGMENT_INTERPOLATE,
                curveType: 0,
                bIgnoreTolerance: 0);
          }
        }
        ++p_m_handle;
      }
      j = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
            this: &controlLookup->m_Elements.m_Tree,
            i: j);
      if ( j == -1 )
        break;
      Inorder = j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DCC0
// Name: private: void CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(class DmeTime_t,class CUtlDict<struct LogPreview_t __near *,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(
        CSFMPhonemeExtractor *this,
        DmeTime_t tHeadPosition,
        const CUtlDict<LogPreview_t *,int> *controlLookup)
{
  const CUtlDict<LogPreview_t *,int> *v3; // esi
  int i; // ebx
  DmElementHandle_t *p_m_handle; // edi
  CDmElement *v6; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v8; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // eax
  CDmeTypedLogLayer<float> *v11; // esi
  float flCurrentValue; // [esp+Ch] [ebp-8h] BYREF
  int j; // [esp+10h] [ebp-4h]

  v3 = controlLookup;
  for ( i = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
              this: &controlLookup->m_Elements.m_Tree,
              i) )
  {
    p_m_handle = &v3->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem->m_hChannels[0].m_handle;
    for ( j = 3; j != 0; --j )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
      if ( v6 != nullptr && v6 != (CDmElement *)4 )
      {
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)((char *)&v6[-1] + 64));
        v8 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
        if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
        {
          TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
          Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(this: v8, index: TopmostLayer);
          v11 = Layer;
          if ( Layer != nullptr )
          {
            flCurrentValue = *CDmeTypedLogLayer<float>::GetValue(this: Layer, time: tHeadPosition);
            CDmeTypedLogLayer<float>::InsertKey(
              this: v11,
              nTime: tHeadPosition,
              value: &flCurrentValue,
              interpSetting: SEGMENT_INTERPOLATE,
              curveType: 0,
              bIgnoreTolerance: 0);
          }
        }
      }
      ++p_m_handle;
    }
    v3 = controlLookup;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DDA0
// Name: private: void CSFMPhonemeExtractor::StampControlValueLogs(class CDmePreset __near *,class DmeTime_t,float,class CUtlDict<struct LogPreview_t __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::StampControlValueLogs(
        CSFMPhonemeExtractor *this,
        CDmePreset *preset,
        DmeTime_t tHeadPosition,
        float flIntensity,
        CUtlDict<LogPreview_t *,int> *controlLookup)
{
  CDmaVar<Vector> *Bookmarks; // esi
  float z; // eax
  int v7; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *m_pAsString; // esi
  const char *v11; // eax
  int v12; // eax
  LogPreview_t *v13; // edi
  const char **v14; // ebx
  CDmElement *v15; // eax
  CDmeChannel *v16; // esi
  CDmElement *v17; // edi
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v19; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // esi
  CDmaVar<float> *v22; // eax
  CDmaVar<float> *v23; // eax
  float *v24; // eax
  const char *v25; // [esp-4h] [ebp-38h]
  CUtlMap<char const *,LogPreview_t *,int>::Node_t search; // [esp+Ch] [ebp-28h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v27; // [esp+14h] [ebp-20h] BYREF
  float value; // [esp+1Ch] [ebp-18h] BYREF
  float flNewValue; // [esp+20h] [ebp-14h]
  CDmElement *v30; // [esp+24h] [ebp-10h]
  LogPreview_t *lp; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  float flDefault; // [esp+30h] [ebp-4h]
  CDmeHandle<CDmeChannel,0> *preseta; // [esp+3Ch] [ebp+8h]

  if ( !CDmePreset::IsAnimated(this: preset) )
  {
    Bookmarks = CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)preset);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v27);
    z = Bookmarks[1].m_Storage.z;
    v7 = 0;
    if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
    {
      v27.m_pAttribute = nullptr;
      v27.m_pStorage = nullptr;
    }
    else
    {
      v27.m_pAttribute = (CDmAttribute *)LODWORD(Bookmarks[1].m_Storage.z);
      v27.m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(z) + 4);
    }
    j = 0;
    if ( CDmrElementArray<CDmElement>::Count(this: (CDmrElementArray<CDmElement> *)&v27) > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v27.m_pStorage->m_Memory.m_pMemory[v7].m_tms);
        v9 = v8;
        v30 = v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
        {
          m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
          {
            v11 = &pParentName;
LABEL_12:
            search.key = v11;
            v12 = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::Find(
                    this: &controlLookup->m_Elements.m_Tree,
                    &search);
            if ( v12 != -1 )
            {
              lp = controlLookup->m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
              v13 = lp;
              v14 = s_pAttributeValueNames;
              preseta = lp->m_hChannels;
              while ( 1 )
              {
                v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: preseta->m_handle);
                if ( v15 != nullptr )
                {
                  v16 = (CDmeChannel *)((char *)&v15[-1] + 64);
                  if ( v15 != (CDmElement *)4 )
                  {
                    v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_hControl.m_handle);
                    if ( v17 != nullptr )
                    {
                      Log = CDmeChannel::GetLog(this: v16);
                      v19 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
                      if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
                      {
                        TopmostLayer = CDmeLog::GetTopmostLayer(this: v19);
                        Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(
                                                              this: v19,
                                                              index: TopmostLayer);
                        if ( Layer != nullptr )
                        {
                          v22 = CDmElement::GetValue<float>(this: v17, pAttributeName: "defaultValue");
                          v25 = *v14;
                          flDefault = v22->m_Storage;
                          v23 = CDmElement::GetValue<float>(this: v30, pAttributeName: v25);
                          flNewValue = (float)(v23->m_Storage - flDefault) * flIntensity;
                          v24 = (float *)CDmeTypedLogLayer<float>::GetValue(this: Layer, time: tHeadPosition);
                          value = (float)((float)(*v24 - flDefault) + flNewValue) + flDefault;
                          CDmeTypedLogLayer<float>::InsertKey(
                            this: Layer,
                            nTime: tHeadPosition,
                            &value,
                            interpSetting: SEGMENT_INTERPOLATE,
                            curveType: 0,
                            bIgnoreTolerance: 0);
                        }
                      }
                    }
                  }
                }
                ++preseta;
                if ( (int)++v14 >= (int)&sfm_phonemeextractor )
                  break;
                v13 = lp;
              }
              v7 = j;
            }
            goto LABEL_24;
          }
          v11 = m_pAsString;
          if ( m_pAsString != nullptr )
            goto LABEL_12;
        }
LABEL_24:
        j = ++v7;
      }
      while ( v7 < CDmrElementArray<CDmElement>::Count(this: (CDmrElementArray<CDmElement> *)&v27) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DFC0
// Name: private: void CSFMPhonemeExtractor::ClearInterstitialSpaces(class CDmeChannelsClip __near *,class CUtlDict<struct LogPreview_t __near *,int> __near &,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::ClearInterstitialSpaces(
        CSFMPhonemeExtractor *this,
        CDmeLogLayer *pChannelsClip,
        CUtlDict<LogPreview_t *,int> *controlLookup,
        ExtractDesc_t *info)
{
  CDmeFilmClip *m_pMovie; // ecx
  CExtractInfo *v6; // esi
  int v7; // eax
  float m_flDuration; // xmm1_4
  float v9; // xmm0_4
  int m_tms; // esi
  int v11; // esi
  CDmeLog *v12; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *v14; // eax
  CDmeLogLayer *v15; // esi
  int j; // esi
  CDmeFilmClip *sec; // [esp+0h] [ebp-C0h]
  DmeTime_t v18; // [esp+10h] [ebp-B0h] BYREF
  DmeTime_t result; // [esp+14h] [ebp-ACh] BYREF
  DmeClipStack_t srcStack; // [esp+18h] [ebp-A8h] BYREF
  DmeClipStack_t dstStack; // [esp+48h] [ebp-78h] BYREF
  DmeTime_t tStartTime; // [esp+78h] [ebp-48h] BYREF
  DmeTime_t tChannelMediaStartTime; // [esp+7Ch] [ebp-44h] BYREF
  float f; // [esp+80h] [ebp-40h]
  DmeTime_t tEndTime; // [esp+84h] [ebp-3Ch] BYREF
  DmeTime_t tSoundMediaStartTime; // [esp+88h] [ebp-38h] BYREF
  DmeTime_t tSoundMediaEndTime; // [esp+8Ch] [ebp-34h] BYREF
  DmeTime_t tChannelMediaEndTime; // [esp+90h] [ebp-30h] BYREF
  CUtlVector<CDmeLog *,CUtlMemory<CDmeLog *,int> > logs; // [esp+94h] [ebp-2Ch] BYREF
  CSFMPhonemeExtractor *v30; // [esp+A8h] [ebp-18h]
  unsigned int v31; // [esp+ACh] [ebp-14h]
  DmeTime_t tChannelRelativeStartTime; // [esp+B0h] [ebp-10h] BYREF
  DmeTime_t v33; // [esp+B4h] [ebp-Ch] BYREF
  int i; // [esp+B8h] [ebp-8h]
  DmeTime_t tMaxTime; // [esp+BCh] [ebp-4h]
  CDmeLogLayer *layer; // [esp+C8h] [ebp+8h]
  DmeTime_t tMinTime; // [esp+D0h] [ebp+10h]
  int tMinTimea; // [esp+D0h] [ebp+10h]

  v30 = this;
  if ( info->m_WorkList.m_Size != 0 && info->m_nExtractType != EXTRACT_WIPE_SOUNDS )
  {
    memset(&logs, 0, sizeof(logs));
    CSFMPhonemeExtractor::BuildPhonemeLogList(
      this,
      list: &info->m_ControlList,
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&logs);
    tMinTime.m_tms = 0x7FFFFFFF;
    tMaxTime.m_tms = -2147483647;
    i = 0;
    if ( info->m_WorkList.m_Size > 0 )
    {
      v31 = 0;
      do
      {
        m_pMovie = info->m_pMovie;
        v6 = &info->m_WorkList.m_Memory.m_pMemory[v31 / 0x84];
        srcStack.m_tStart.m_tms = 0x80000000;
        srcStack.m_tDuration.m_tms = 0x80000000;
        srcStack.m_tOffset.m_tms = 0x80000000;
        dstStack.m_tStart.m_tms = 0x80000000;
        dstStack.m_tDuration.m_tms = 0x80000000;
        dstStack.m_tOffset.m_tms = 0x80000000;
        sec = info->m_pShot;
        memset(&srcStack, 0, 20);
        srcStack.m_bOptimized = false;
        memset(&dstStack, 0, 20);
        dstStack.m_bOptimized = false;
        CDmeClip::BuildClipStack(this: v6->m_pClip, pStack: &srcStack, pMovie: m_pMovie, pShot: sec);
        DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaStartTime, t: 0, bClamp: false);
        v7 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v6->m_flDuration));
        DmeClipStack_t::FromChildMediaTime(
          this: &srcStack,
          result: &tSoundMediaEndTime,
          t: (DmeTime_t)v7,
          bClamp: false);
        CDmeClip::GetStartInChildMediaTime(this: v6->m_pClip, result: &tStartTime);
        CDmeClip::GetEndInChildMediaTime(this: v6->m_pClip, result: &tEndTime);
        CDmeClip::BuildClipStack(
          this: (CDmeClip *)pChannelsClip,
          pStack: &dstStack,
          pMovie: info->m_pMovie,
          pShot: info->m_pShot);
        DmeClipStack_t::ToChildMediaTime(
          this: &dstStack,
          result: &tChannelMediaStartTime,
          t: tSoundMediaStartTime,
          bClamp: 0);
        DmeClipStack_t::ToChildMediaTime(
          this: &dstStack,
          result: &tChannelMediaEndTime,
          t: tSoundMediaEndTime,
          bClamp: 0);
        m_flDuration = v6->m_flDuration;
        v9 = 0.0;
        m_tms = tChannelMediaStartTime.m_tms;
        if ( m_flDuration != 0.0 )
          v9 = (float)((float)(tChannelMediaEndTime.m_tms - tChannelMediaStartTime.m_tms) * 0.000099999997)
             / m_flDuration;
        v33.m_tms = tStartTime.m_tms;
        f = v9;
        DmeTime_t::operator*=(this: &v33, &result, f: v9);
        tChannelRelativeStartTime.m_tms = m_tms + v33.m_tms;
        v33.m_tms = tEndTime.m_tms;
        DmeTime_t::operator*=(this: &v33, result: &v18, f);
        v11 = v33.m_tms + m_tms;
        if ( tChannelRelativeStartTime.m_tms < tMinTime.m_tms )
          tMinTime.m_tms = tChannelRelativeStartTime.m_tms;
        if ( v11 > tMaxTime.m_tms )
          tMaxTime.m_tms = v11;
        CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &dstStack.m_clips);
        if ( dstStack.m_clips.m_Memory.m_nGrowSize >= 0 )
        {
          if ( dstStack.m_clips.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstStack.m_clips.m_Memory.m_pMemory);
            dstStack.m_clips.m_Memory.m_pMemory = nullptr;
          }
          dstStack.m_clips.m_Memory.m_nAllocationCount = 0;
        }
        CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
        if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 && srcStack.m_clips.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
        v31 += 132;
        ++i;
      }
      while ( i < info->m_WorkList.m_Size );
    }
    tMinTimea = tMinTime.m_tms - 1;
    ++tMaxTime.m_tms;
    for ( i = 0; i < logs.m_Size; ++i )
    {
      v12 = logs.m_Memory.m_pMemory[i];
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v12);
      v14 = CDmeLog::GetLayer(this: v12, index: TopmostLayer);
      v15 = v14;
      layer = v14;
      if ( info->m_nExtractType != EXTRACT_WIPE_RANGE )
      {
        v14->ClearKeys(this: v14);
      }
      else
      {
        CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
          this: v30,
          tHeadPosition: (DmeTime_t)tMinTimea,
          controlLookup);
        CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v30, tHeadPosition: tMaxTime, controlLookup);
        for ( j = CDmeLogLayer::GetKeyCount(this: v15) - 1; j >= 0; --j )
        {
          CDmeLogLayer::GetKeyTime(this: layer, result: &tChannelRelativeStartTime, nKeyIndex: j);
          if ( tChannelRelativeStartTime.m_tms > tMinTimea && tChannelRelativeStartTime.m_tms < tMaxTime.m_tms )
            layer->RemoveKey(this: layer, a2: j, a3: 1);
        }
      }
    }
    if ( logs.m_Memory.m_nGrowSize >= 0 && logs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: logs.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053E3D0
// Name: private: void CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(class CUtlVector<class CBasePhonemeTag __near *,class CUtlMemory<class CBasePhonemeTag __near *,int>> const __near &,class CDmeAnimationSet __near *,class CDmePresetGroup __near *,class CUtlDict<class CDmePreset __near *,unsigned short> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(
        CSFMPhonemeExtractor *this,
        const CUtlVector<CBasePhonemeTag *,CUtlMemory<CBasePhonemeTag *,int> > *stream,
        CDmeAnimationSet *pSet,
        CDmePresetGroup *pPresetGroup,
        int phonemeToPresetDict)
{
  const CUtlVector<CBasePhonemeTag *,CUtlMemory<CBasePhonemeTag *,int> > *v5; // eax
  int v6; // edi
  unsigned __int16 v7; // ax
  unsigned __int16 elem; // dx
  unsigned __int16 v9; // cx
  int v10; // esi
  UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short> *m_pMemory; // eax
  int v12; // esi
  int v13; // edx
  CBasePhonemeTag **v14; // esi
  CUtlDict<CDmePreset *,unsigned short> *v15; // edi
  const char *v16; // eax
  CDmePhonemeMapping *Mapping; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v19; // esi
  CDmaVar<CUtlSymbolLarge> *m_pData; // eax
  CDmePreset *Preset; // ebx
  const char *Name; // eax
  char *v23; // eax
  unsigned __int16 v24; // ax
  unsigned __int16 v25; // dx
  unsigned __int16 v26; // cx
  int v27; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v29; // eax
  int v30; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v31; // ecx
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t *p_m_Data; // esi
  char remappedph[32]; // [esp+Ch] [ebp-74h] BYREF
  char ph[32]; // [esp+2Ch] [ebp-54h] BYREF
  CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl*)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short> > uniquePhonemes; // [esp+4Ch] [ebp-34h] BYREF
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t search; // [esp+68h] [ebp-18h] BYREF
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t insert; // [esp+70h] [ebp-10h] BYREF
  CBasePhonemeTag *tag; // [esp+78h] [ebp-8h] BYREF
  bool leftchild; // [esp+7Fh] [ebp-1h] BYREF

  v5 = stream;
  v6 = 0;
  uniquePhonemes.m_LessFunc = (bool (__cdecl *)(CBasePhonemeTag *const *, CBasePhonemeTag *const *))UniquePhonemeLessFunc;
  memset(&uniquePhonemes.m_Elements, 0, sizeof(uniquePhonemes.m_Elements));
  *(_DWORD *)&uniquePhonemes.m_Root = 0xFFFF;
  *(_DWORD *)&uniquePhonemes.m_FirstFree = -1;
  uniquePhonemes.m_pElements = nullptr;
  if ( stream->m_Size > 0 )
  {
    do
    {
      tag = v5->m_Memory.m_pMemory[v6];
      if ( CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::Find(
             this: &uniquePhonemes,
             search: &tag) == 0xFFFF )
      {
        insert.elem = (CDmePreset *)0xFFFF;
        leftchild = false;
        CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &uniquePhonemes,
          insert: &tag,
          parent: (unsigned __int16 *)&insert.elem,
          &leftchild);
        v7 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&uniquePhonemes);
        elem = (unsigned __int16)insert.elem;
        v9 = v7;
        v10 = 3 * v7;
        m_pMemory = uniquePhonemes.m_Elements.m_pMemory;
        v12 = 4 * v10;
        *(unsigned __int16 *)((char *)&uniquePhonemes.m_Elements.m_pMemory->m_Right + v12) = -1;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v12) = -1;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v12) = 0;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v12) = elem;
        if ( elem == 0xFFFF )
        {
          uniquePhonemes.m_Root = v9;
        }
        else
        {
          v13 = elem;
          if ( leftchild )
            m_pMemory[v13].m_Left = v9;
          else
            m_pMemory[v13].m_Right = v9;
        }
        CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::InsertRebalance(
          this: &uniquePhonemes,
          elem: v9);
        ++uniquePhonemes.m_NumElements;
        v14 = (CBasePhonemeTag **)((char *)&uniquePhonemes.m_Elements.m_pMemory->m_Data + v12);
        if ( v14 != nullptr )
          *v14 = tag;
      }
      v5 = stream;
      ++v6;
    }
    while ( v6 < stream->m_Size );
  }
  tag = (CBasePhonemeTag *)(unsigned __int16)CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::FirstInorder(this: &uniquePhonemes);
  if ( tag != (CBasePhonemeTag *)0xFFFF )
  {
    v15 = (CUtlDict<CDmePreset *,unsigned short> *)phonemeToPresetDict;
    do
    {
      v16 = ConvertPhoneme(code: uniquePhonemes.m_Elements.m_pMemory[(unsigned __int16)tag].m_Data->m_nPhonemeCode);
      V_strncpy(pDest: ph, pSrc: v16, maxLen: 32);
      V_snprintf(pDest: remappedph, maxLen: 32, pFormat: "p_%s", ph);
      Mapping = CDmeAnimationSet::FindMapping(this: pSet, pRawPhoneme: ph);
      if ( Mapping != nullptr )
      {
        if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
          dword_5D4BE4 = 0;
          `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal = -1;
        }
        Attribute = CDmElement::FindAttribute(this: Mapping, pAttributeName: "preset");
        v19 = Attribute;
        if ( Attribute != nullptr )
        {
          if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
          }
          if ( (Attribute->m_nFlags & 0x1F) == 5 )
          {
            m_pData = (CDmaVar<CUtlSymbolLarge> *)Attribute->m_pData;
          }
          else if ( CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(this: Attribute) )
          {
            if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal = DMELEMENT_HANDLE_INVALID;
            }
            CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
              this: v19,
              value: &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal);
            m_pData = (CDmaVar<CUtlSymbolLarge> *)&`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal;
          }
          else
          {
            m_pData = &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
          }
        }
        else
        {
          m_pData = (CDmaVar<CUtlSymbolLarge> *)&`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
        }
        V_strncpy(
          pDest: remappedph,
          pSrc: m_pData->m_Storage.u.m_Id != -1 ? m_pData->m_Storage.u.m_pAsString : nullptr,
          maxLen: 32);
      }
      Preset = CDmePresetGroup::FindPreset(this: pPresetGroup, pPresetName: remappedph);
      if ( Preset != nullptr )
      {
        search.key = ph;
        if ( CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
               this: &v15->m_Elements.m_Tree,
               &search) == 0xFFFF )
        {
          v23 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(ph) + 1);
          if ( v23 != nullptr )
            strcpy(v23, ph);
          else
            v23 = nullptr;
          insert.key = v23;
          insert.elem = Preset;
          phonemeToPresetDict = 0xFFFF;
          HIBYTE(stream) = 0;
          CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &v15->m_Elements.m_Tree,
            &insert,
            parent: (unsigned __int16 *)&phonemeToPresetDict,
            leftchild: (bool *)&stream + 3);
          v24 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &v15->m_Elements.m_Tree);
          v25 = phonemeToPresetDict;
          v26 = v24;
          v27 = v24;
          v28 = &v15->m_Elements.m_Tree.m_Elements.m_pMemory[v27];
          v28->m_Right = -1;
          v28->m_Left = -1;
          v28->m_Parent = v25;
          v28->m_Tag = 0;
          if ( v25 == 0xFFFF )
          {
            v15->m_Elements.m_Tree.m_Root = v26;
          }
          else
          {
            v29 = v15->m_Elements.m_Tree.m_Elements.m_pMemory;
            v30 = v25;
            if ( HIBYTE(stream) != 0 )
              v29[v30].m_Left = v26;
            else
              v29[v30].m_Right = v26;
          }
          CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: &v15->m_Elements.m_Tree,
            elem: v26);
          v31 = v15->m_Elements.m_Tree.m_Elements.m_pMemory;
          ++v15->m_Elements.m_Tree.m_NumElements;
          p_m_Data = &v31[v27].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
      }
      else
      {
        Name = CDmElement::GetName(this: pSet);
        _Warning(a1: "Animation set '%s' missing phoneme preset for '%s' -> '%s'\n", Name, ph, remappedph);
      }
      tag = (CBasePhonemeTag *)(unsigned __int16)CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::NextInorder(
                                                   this: &uniquePhonemes,
                                                   i: (unsigned __int16)tag);
    }
    while ( tag != (CBasePhonemeTag *)0xFFFF );
  }
  CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::RemoveAll(this: &uniquePhonemes);
  if ( uniquePhonemes.m_Elements.m_nGrowSize >= 0 && uniquePhonemes.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uniquePhonemes.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0053E7A0
// Name: private: void CSFMPhonemeExtractor::LogPhonemes(int,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::LogPhonemes(CSFMPhonemeExtractor *this, DmeTime_t nItemIndex, CExtractInfo *info)
{
  CExtractInfo *v4; // ebx
  CDmeAnimationSet *m_nGrowSize; // ecx
  int v6; // edi
  const char *v7; // esi
  LogPreview_t *const *v8; // ebx
  char *m_Id; // eax
  CSFMPhonemeExtractor *v10; // edi
  CDmeFilmClip *m_nAllocationCount; // edx
  int v12; // ecx
  int v13; // eax
  CDmeFilmClip *v14; // edx
  float m_flDuration; // xmm1_4
  float v16; // xmm0_4
  int v17; // ebx
  float v18; // xmm0_4
  double v19; // xmm2_8
  float v20; // xmm0_4
  float v21; // xmm1_4
  DmeTime_t v22; // edi
  DmeTime_t v23; // ebx
  DmeTime_t *v24; // eax
  DmeTime_t *v25; // eax
  DmeTime_t *v26; // eax
  DmeTime_t *v27; // eax
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmePreset *Bookmarks; // eax
  int v30; // edi
  CDmElement *v31; // eax
  CDmElement *v32; // ebx
  int v33; // eax
  int v34; // ebx
  int j; // ebx
  CBasePhonemeTag *v36; // edi
  const char *v37; // eax
  unsigned int m_flStartTime_low; // xmm0_4
  CDmePreset *v39; // eax
  unsigned int m_flEndTime_low; // xmm0_4
  int v41; // eax
  float v42; // xmm1_4
  float v43; // xmm1_4
  double v44; // xmm0_8
  CBasePhonemeTag *v45; // esi
  int v46; // eax
  unsigned int v47; // xmm0_4
  int v48; // ebx
  int v49; // edi
  int v50; // eax
  DmeTime_t *p_tStart; // ecx
  int m_tms; // ecx
  int v53; // eax
  DmeTime_t *p_tPostPhonemeTime; // eax
  float v55; // xmm1_4
  float v56; // xmm0_4
  const char *v57; // eax
  unsigned __int16 v58; // ax
  CDmePreset *elem; // eax
  bool v60; // cc
  CBasePhonemeTag *v61; // ebx
  int v62; // eax
  unsigned int v63; // xmm0_4
  const char *v64; // eax
  unsigned __int16 v65; // ax
  DmeTime_t v66; // ebx
  DmeTime_t *p_tKeyTime; // eax
  DmeTime_t v68; // ebx
  int v69; // esi
  int m_Size; // edi
  CDmeLog **m_pMemory; // ebx
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int> *v73; // edi
  CDmeAnimationSet *v74; // [esp+Ch] [ebp-134h]
  CDmeFilmClip *sec; // [esp+10h] [ebp-130h]
  CDmeFilmClip *seca; // [esp+10h] [ebp-130h]
  int sec_4; // [esp+14h] [ebp-12Ch]
  float sec_4a; // [esp+14h] [ebp-12Ch]
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t search; // [esp+24h] [ebp-11Ch] BYREF
  DmeClipStack_t dstStack; // [esp+2Ch] [ebp-114h] BYREF
  DmeTime_t tSoundMediaEndTime; // [esp+5Ch] [ebp-E4h] BYREF
  DmeTime_t tStartTime; // [esp+60h] [ebp-E0h] BYREF
  double tStep; // [esp+64h] [ebp-DCh] BYREF
  DmeTime_t tSoundMediaStartTime; // [esp+6Ch] [ebp-D4h] BYREF
  DmeTime_t tChannelMediaEndTime; // [esp+70h] [ebp-D0h] BYREF
  DmeTime_t tChannelMediaStartTime; // [esp+74h] [ebp-CCh] BYREF
  DmeTime_t tEndTime; // [esp+78h] [ebp-C8h] BYREF
  DmeClipStack_t srcStack; // [esp+7Ch] [ebp-C4h] BYREF
  double flScale; // [esp+ACh] [ebp-94h]
  CUtlVector<CDmeLog *,CUtlMemory<CDmeLog *,int> > logs; // [esp+B4h] [ebp-8Ch] BYREF
  double flEndSoundTime; // [esp+C8h] [ebp-78h] BYREF
  CUtlDict<CDmePreset *,unsigned short> phonemeToPresetDict; // [esp+D0h] [ebp-70h] BYREF
  CUtlDict<LogPreview_t *,int> controlLookup; // [esp+ECh] [ebp-54h] BYREF
  double t; // [esp+110h] [ebp-30h]
  DmeTime_t flIntensity; // [esp+118h] [ebp-28h]
  int flOOFilter; // [esp+11Ch] [ebp-24h]
  DmeTime_t tEnd; // [esp+120h] [ebp-20h] BYREF
  DmeTime_t tStart; // [esp+124h] [ebp-1Ch] BYREF
  DmeTime_t tPostPhonemeTime; // [esp+128h] [ebp-18h] BYREF
  DmeTime_t tKeyTime; // [esp+12Ch] [ebp-14h] BYREF
  DmeTime_t flFilter; // [esp+130h] [ebp-10h] BYREF
  DmeTime_t tPhonemeTime; // [esp+134h] [ebp-Ch] BYREF
  int i; // [esp+138h] [ebp-8h]
  CDmePreset *preset; // [esp+13Ch] [ebp-4h]
  int tOffset; // [esp+148h] [ebp+8h]
  CExtractInfo *item; // [esp+14Ch] [ebp+Ch]

  v4 = (CExtractInfo *)(info->m_sHintText.m_Storage.m_Memory.m_nAllocationCount + 132 * nItemIndex.m_tms);
  i = (int)this;
  m_nGrowSize = (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize;
  v6 = 0;
  item = v4;
  if ( m_nGrowSize == nullptr || v4->m_pClip == nullptr || v4->m_pSound == nullptr )
    return;
  tPostPhonemeTime.m_tms = (int)CDmeAnimationSet::FindPresetGroup(this: m_nGrowSize, pGroupName: "phoneme");
  if ( tPostPhonemeTime.m_tms == 0 )
  {
    v7 = *(const char **)(info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize + 20);
    if ( v7 == (const char *)-1 )
      v7 = &pParentName;
    _Warning(a1: "Animation set '%s' missing preset group 'phoneme'\n", v7);
    return;
  }
  if ( CDmeAnimationSet::GetPhonemeMap(this: (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize)->m_Storage.m_Size == 0 )
    CDmeAnimationSet::RestoreDefaultPhonemeMap(this: (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize);
  v74 = (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize;
  memset(&phonemeToPresetDict.m_Elements.m_Tree.m_Elements, 0, sizeof(phonemeToPresetDict.m_Elements.m_Tree.m_Elements));
  *(_DWORD *)&phonemeToPresetDict.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&phonemeToPresetDict.m_Elements.m_Tree.m_FirstFree = -1;
  phonemeToPresetDict.m_Elements.m_Tree.m_pElements = nullptr;
  phonemeToPresetDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(
    this: (CSFMPhonemeExtractor *)i,
    stream: &v4->m_ApplyTags,
    pSet: v74,
    pPresetGroup: (CDmePresetGroup *)tPostPhonemeTime.m_tms,
    (int)&phonemeToPresetDict);
  preset = (CDmePreset *)CSFMPhonemeExtractor::FindFacialChannelsClip(
                           this: (CSFMPhonemeExtractor *)i,
                           list: (const CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *)&info->m_Sentence.m_Words);
  if ( preset == nullptr )
  {
LABEL_21:
    CUtlDict<CDmePreset *,unsigned short>::RemoveAll(this: &phonemeToPresetDict);
    CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &phonemeToPresetDict.m_Elements.m_Tree);
    return;
  }
  memset(&controlLookup.m_Elements.m_Tree.m_Elements, 0, sizeof(controlLookup.m_Elements.m_Tree.m_Elements));
  controlLookup.m_Elements.m_Tree.m_Root = -1;
  controlLookup.m_Elements.m_Tree.m_NumElements = 0;
  controlLookup.m_Elements.m_Tree.m_FirstFree = -1;
  controlLookup.m_Elements.m_Tree.m_LastAlloc.index = -1;
  controlLookup.m_Elements.m_Tree.m_pElements = nullptr;
  controlLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  if ( info->m_Sentence.m_Words.m_Size > 0 )
  {
    do
    {
      v8 = (LogPreview_t *const *)&info->m_Sentence.m_Words.m_Memory.m_pMemory[v6];
      m_Id = (char *)g_pDataModel->GetElement(this: g_pDataModel, a2: (*v8)->m_hControl.m_handle)->m_Name.m_Storage.u.m_Id;
      if ( m_Id == (char *)-1 )
        m_Id = (char *)&pParentName;
      CUtlDict<LogPreview_t *,int>::Insert(this: &controlLookup, pName: m_Id, element: v8);
      ++v6;
    }
    while ( v6 < info->m_Sentence.m_Words.m_Size );
  }
  v10 = (CSFMPhonemeExtractor *)i;
  if ( nItemIndex.m_tms == 0 && *(int *)&info->m_bUseSentence > 1 )
    CSFMPhonemeExtractor::ClearInterstitialSpaces(
      this: (CSFMPhonemeExtractor *)i,
      pChannelsClip: (CDmeLogLayer *)preset,
      &controlLookup,
      (ExtractDesc_t *)info);
  m_nAllocationCount = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount;
  memset(&srcStack, 0, 20);
  srcStack.m_tStart.m_tms = 0x80000000;
  srcStack.m_tDuration.m_tms = 0x80000000;
  srcStack.m_tOffset.m_tms = 0x80000000;
  sec = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory;
  srcStack.m_bOptimized = false;
  CDmeClip::BuildClipStack(this: item->m_pClip, pStack: &srcStack, pMovie: sec, pShot: m_nAllocationCount);
  if ( srcStack.m_clips.m_Size == 0 )
  {
    CDmeClip::BuildClipStack(
      this: item->m_pClip,
      pStack: &srcStack,
      pMovie: (const CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
      pShot: nullptr);
    if ( srcStack.m_clips.m_Size == 0 )
    {
      _Msg(a1: v12, a2: "Couldn't build stack sound clip to current shot\n");
      DmeClipStack_t::~DmeClipStack_t(this: &srcStack);
      CUtlDict<LogPreview_t *,int>::RemoveAll(this: &controlLookup);
      CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>(this: &controlLookup.m_Elements.m_Tree);
      goto LABEL_21;
    }
  }
  DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaStartTime, t: 0, bClamp: false);
  v13 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(item->m_flDuration));
  DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaEndTime, t: (DmeTime_t)v13, bClamp: false);
  CDmeClip::GetStartInChildMediaTime(this: item->m_pClip, result: &tStartTime);
  CDmeClip::GetEndInChildMediaTime(this: item->m_pClip, result: &tEndTime);
  v14 = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount;
  memset(&dstStack, 0, 20);
  dstStack.m_tStart.m_tms = 0x80000000;
  dstStack.m_tDuration.m_tms = 0x80000000;
  dstStack.m_tOffset.m_tms = 0x80000000;
  seca = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory;
  dstStack.m_bOptimized = false;
  CDmeClip::BuildClipStack(this: (CDmeClip *)preset, pStack: &dstStack, pMovie: seca, pShot: v14);
  DmeClipStack_t::ToChildMediaTime(this: &dstStack, result: &tChannelMediaStartTime, t: tSoundMediaStartTime, bClamp: 0);
  DmeClipStack_t::ToChildMediaTime(this: &dstStack, result: &tChannelMediaEndTime, t: tSoundMediaEndTime, bClamp: 0);
  m_flDuration = item->m_flDuration;
  v16 = 0.0;
  if ( m_flDuration != 0.0 )
    v16 = (float)((float)(tChannelMediaEndTime.m_tms - tChannelMediaStartTime.m_tms) * 0.000099999997) / m_flDuration;
  v17 = 0;
  tOffset = tChannelMediaStartTime.m_tms;
  flScale = v16;
  memset(&logs, 0, sizeof(logs));
  CSFMPhonemeExtractor::BuildPhonemeLogList(
    this: v10,
    list: (CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *)&info->m_Sentence.m_Words,
    (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&logs);
  if ( logs.m_Size > 0 )
  {
    do
    {
      logs.m_Memory.m_pMemory[v17]->AddNewLayer(this: logs.m_Memory.m_pMemory[v17]);
      ++v17;
    }
    while ( v17 < logs.m_Size );
  }
  v18 = (float)tStartTime.m_tms * 0.000099999997;
  if ( v18 < 0.0 )
    v18 = 0.0;
  v19 = v18;
  v20 = (float)tEndTime.m_tms * 0.000099999997;
  v21 = item->m_flDuration;
  t = v19;
  if ( v20 > v21 )
    v20 = v21;
  flEndSoundTime = v20;
  flIntensity.m_tms = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(v19 * flScale)) + tOffset - 1;
  CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(this: v10, tHeadPosition: flIntensity, &controlLookup);
  tPostPhonemeTime.m_tms = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(flEndSoundTime * flScale))
                         + tOffset
                         + 1;
  CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(this: v10, tHeadPosition: tPostPhonemeTime, &controlLookup);
  if ( LOBYTE(info->m_sHintText.m_Storage.m_Memory.m_pMemory) != 0 )
  {
    v22.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&t);
    tPhonemeTime.m_tms = v22.m_tms;
    v23.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&flEndSoundTime);
    tStart.m_tms = v23.m_tms;
    v24 = DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tKeyTime, t: v22, bClamp: false);
    v25 = CDmeClip::ToChildMediaTime(
            this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
            result: &tKeyTime,
            t: (DmeTime_t)v24->m_tms,
            bClamp: 0);
    CDmeClip::ToChildMediaTime(
      this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount,
      result: &tEnd,
      t: (DmeTime_t)v25->m_tms,
      bClamp: 0);
    v26 = DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tKeyTime, t: v23, bClamp: false);
    v27 = CDmeClip::ToChildMediaTime(
            this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
            result: &tKeyTime,
            t: (DmeTime_t)v26->m_tms,
            bClamp: 0);
    CDmeClip::ToChildMediaTime(
      this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount,
      result: &flFilter,
      t: (DmeTime_t)v27->m_tms,
      bClamp: 0);
    ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount);
    if ( ActiveBookmarkSet != nullptr )
    {
      Bookmarks = (CDmePreset *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
      v30 = *(_DWORD *)&Bookmarks->m_Id.m_Value[8] - 1;
      preset = Bookmarks;
      if ( v30 >= 0 )
      {
        while ( 1 )
        {
          v31 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&Bookmarks->OnAttributeChanged + v30));
          v32 = v31;
          if ( v31 != nullptr && v31->IsA(this: v31, a2: CDmeBookmark::m_classType) )
          {
            v33 = *(_DWORD *)&v32[1].m_Id.m_Value[4];
            v34 = *(_DWORD *)&v32[1].m_Id.m_Value[12];
            if ( v33 <= flFilter.m_tms && v33 + v34 >= tEnd.m_tms )
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
                this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)preset,
                elem: v30);
          }
          if ( --v30 < 0 )
            break;
          Bookmarks = preset;
        }
      }
      v22.m_tms = tPhonemeTime.m_tms;
    }
    AddBookmarkAtSoundMediaTime(pName: "start", tStart: v22, tEnd: v22, &srcStack, (ExtractDesc_t *)info);
    for ( j = 0; j < item->m_ApplyTags.m_Size; ++j )
    {
      v36 = item->m_ApplyTags.m_Memory.m_pMemory[j];
      v37 = ConvertPhoneme(code: v36->m_nPhonemeCode);
      m_flStartTime_low = LODWORD(v36->m_flStartTime);
      tPhonemeTime.m_tms = (int)v37;
      v39 = (CDmePreset *)DmeTime_t::RoundSecondsToTMS(sec: m_flStartTime_low);
      m_flEndTime_low = LODWORD(v36->m_flEndTime);
      preset = v39;
      v41 = DmeTime_t::RoundSecondsToTMS(sec: m_flEndTime_low);
      AddBookmarkAtSoundMediaTime(
        pName: (const char *)tPhonemeTime.m_tms,
        tStart: (DmeTime_t)preset,
        tEnd: (DmeTime_t)v41,
        &srcStack,
        (ExtractDesc_t *)info);
    }
    AddBookmarkAtSoundMediaTime(pName: "end", tStart, tEnd: tStart, &srcStack, (ExtractDesc_t *)info);
    v10 = (CSFMPhonemeExtractor *)i;
  }
  if ( info->m_pSound < (CDmeGameSound *)2 )
  {
    tPhonemeTime.m_tms = 0;
    for ( i = 0; i < item->m_ApplyTags.m_Size; ++i )
    {
      v61 = item->m_ApplyTags.m_Memory.m_pMemory[i];
      v62 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v61->m_flStartTime));
      v63 = LODWORD(v61->m_flEndTime);
      tKeyTime.m_tms = v62;
      *(float *)&flOOFilter = COERCE_FLOAT(DmeTime_t::RoundSecondsToTMS(sec: v63));
      v64 = ConvertPhoneme(code: v61->m_nPhonemeCode);
      if ( v64 != nullptr )
      {
        LODWORD(tStep) = v64;
        v65 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &phonemeToPresetDict.m_Elements.m_Tree,
                search: (const CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t *)&tStep);
      }
      else
      {
        v65 = -1;
      }
      if ( v65 != 0xFFFF )
      {
        preset = phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory[v65].m_Data.elem;
        if ( preset != nullptr )
        {
          sec_4a = flScale;
          flFilter.m_tms = tKeyTime.m_tms;
          tStart.m_tms = LODWORD(sec_4a);
          DmeTime_t::operator*=(this: &flFilter, result: &tEnd, f: sec_4a);
          v66.m_tms = tOffset + flFilter.m_tms;
          if ( info->m_pSound == nullptr )
          {
            if ( v66.m_tms - 1 > flIntensity.m_tms )
            {
              CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
                this: v10,
                tHeadPosition: (DmeTime_t)(v66.m_tms - 1),
                &controlLookup);
              if ( tPhonemeTime.m_tms != 0 )
                CSFMPhonemeExtractor::StampControlValueLogs(
                  this: v10,
                  preset: (CDmePreset *)tPhonemeTime.m_tms,
                  tHeadPosition: (DmeTime_t)(v66.m_tms - 1),
                  flIntensity: 1.0,
                  &controlLookup);
            }
            tPhonemeTime.m_tms = (int)preset;
          }
          CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v10, tHeadPosition: v66, &controlLookup);
          CSFMPhonemeExtractor::StampControlValueLogs(
            this: v10,
            preset,
            tHeadPosition: v66,
            flIntensity: 1.0,
            &controlLookup);
          if ( info->m_pSound == nullptr && i == item->m_ApplyTags.m_Size - 1 )
          {
            flFilter.m_tms = flOOFilter;
            DmeTime_t::operator*=(this: &flFilter, result: (DmeTime_t *)&flEndSoundTime + 1, f: *(float *)&tStart.m_tms);
            tKeyTime.m_tms = flFilter.m_tms + tOffset;
            p_tKeyTime = &tKeyTime;
            if ( flFilter.m_tms + tOffset >= tPostPhonemeTime.m_tms )
              p_tKeyTime = &tPostPhonemeTime;
            v68.m_tms = p_tKeyTime->m_tms;
            CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
              this: v10,
              tHeadPosition: (DmeTime_t)(p_tKeyTime->m_tms - 1),
              &controlLookup);
            CSFMPhonemeExtractor::StampControlValueLogs(
              this: v10,
              preset,
              tHeadPosition: (DmeTime_t)(v68.m_tms - 1),
              flIntensity: 1.0,
              &controlLookup);
            CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v10, tHeadPosition: v68, &controlLookup);
          }
        }
      }
    }
  }
  else
  {
    v42 = *(float *)&info->m_Sentence.m_RunTimePhonemes.m_Size;
    if ( v42 >= 1.0 )
    {
      if ( v42 > 1000.0 )
        v42 = 1000.0;
    }
    else
    {
      v42 = 1.0;
    }
    tStep = 1.0 / v42;
    v43 = *(float *)&info->m_Sentence.m_RunTimePhonemes.m_pElements;
    if ( v43 <= 0.001 )
      v43 = 0.001;
    flFilter.m_tms = LODWORD(v43);
    *(float *)&flOOFilter = 1.0 / v43;
    v44 = t;
    if ( flEndSoundTime > t )
    {
      do
      {
        tPhonemeTime.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&v44);
        tKeyTime.m_tms = tOffset + DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(t * flScale));
        CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v10, tHeadPosition: tKeyTime, &controlLookup);
        preset = nullptr;
        if ( item->m_ApplyTags.m_Size > 0 )
        {
          do
          {
            v45 = item->m_ApplyTags.m_Memory.m_pMemory[(_DWORD)preset];
            v46 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v45->m_flStartTime));
            v47 = LODWORD(v45->m_flEndTime);
            v48 = v46;
            tStart.m_tms = v46;
            v49 = DmeTime_t::RoundSecondsToTMS(sec: v47);
            tEnd.m_tms = v49;
            v50 = DmeTime_t::RoundSecondsToTMS(sec: flFilter.m_tms);
            p_tStart = &tStart;
            if ( v48 <= tPhonemeTime.m_tms )
              p_tStart = &tPhonemeTime;
            m_tms = p_tStart->m_tms;
            v53 = tPhonemeTime.m_tms + v50;
            if ( v49 >= v53 )
            {
              tPostPhonemeTime.m_tms = v53;
              p_tPostPhonemeTime = &tPostPhonemeTime;
            }
            else
            {
              p_tPostPhonemeTime = &tEnd;
            }
            v55 = (float)((float)(m_tms - tPhonemeTime.m_tms) * 0.000099999997) * *(float *)&flOOFilter;
            v56 = (float)((float)(p_tPostPhonemeTime->m_tms - tPhonemeTime.m_tms) * 0.000099999997)
                * *(float *)&flOOFilter;
            if ( v55 < 1.0 && v56 > 0.0 )
            {
              if ( v56 > 1.0 )
                v56 = 1.0;
              if ( v55 < 0.0 )
                v55 = 0.0;
              sec_4 = v45->m_nPhonemeCode;
              *(float *)&flIntensity.m_tms = v56 - v55;
              v57 = ConvertPhoneme(code: sec_4);
              if ( v57 != nullptr )
              {
                search.key = v57;
                v58 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                        this: &phonemeToPresetDict.m_Elements.m_Tree,
                        &search);
              }
              else
              {
                v58 = -1;
              }
              if ( v58 != 0xFFFF )
              {
                elem = phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory[v58].m_Data.elem;
                if ( elem != nullptr )
                  CSFMPhonemeExtractor::StampControlValueLogs(
                    this: (CSFMPhonemeExtractor *)i,
                    preset: elem,
                    tHeadPosition: tKeyTime,
                    flIntensity: *(float *)&flIntensity.m_tms,
                    &controlLookup);
              }
            }
            preset = (CDmePreset *)((char *)preset + 1);
          }
          while ( (int)preset < item->m_ApplyTags.m_Size );
          v10 = (CSFMPhonemeExtractor *)i;
        }
        v44 = t + tStep;
        v60 = flEndSoundTime <= t + tStep;
        t = t + tStep;
      }
      while ( !v60 );
    }
  }
  v69 = 0;
  if ( logs.m_Size > 0 )
  {
    m_Size = logs.m_Size;
    m_pMemory = logs.m_Memory.m_pMemory;
    do
      ((void (__stdcall *)(int, int, _DWORD))m_pMemory[v69++]->FlattenLayers)(a1: 953267991, a2: 1, a3: 0);
    while ( v69 < m_Size );
  }
  if ( logs.m_Memory.m_nGrowSize >= 0 && logs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: logs.m_Memory.m_pMemory);
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &dstStack.m_clips);
  if ( dstStack.m_clips.m_Memory.m_nGrowSize >= 0 )
  {
    if ( dstStack.m_clips.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstStack.m_clips.m_Memory.m_pMemory);
      dstStack.m_clips.m_Memory.m_pMemory = nullptr;
    }
    dstStack.m_clips.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
  if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 )
  {
    if ( srcStack.m_clips.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
      srcStack.m_clips.m_Memory.m_pMemory = nullptr;
    }
    srcStack.m_clips.m_Memory.m_nAllocationCount = 0;
  }
  Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    v73 = controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v73[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
                  this: &controlLookup.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
  }
  CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::RemoveAll(this: &controlLookup.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::RemoveAll(this: &controlLookup.m_Elements.m_Tree);
  if ( controlLookup.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
  CUtlDict<CDmePreset *,unsigned short>::RemoveAll(this: &phonemeToPresetDict);
  CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &phonemeToPresetDict.m_Elements.m_Tree);
  if ( phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053F350
// Name: public: virtual void CSFMPhonemeExtractor::ReApply(struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::ReApply(CSFMPhonemeExtractor *this, CExtractInfo *info)
{
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *Bookmarks; // eax
  int i; // esi

  if ( LOBYTE(info->m_sHintText.m_Storage.m_Memory.m_pMemory) != 0 )
  {
    ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount);
    if ( ActiveBookmarkSet != nullptr )
    {
      Bookmarks = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: Bookmarks);
    }
  }
  for ( i = 0; i < *(_DWORD *)&info->m_bUseSentence; ++i )
    CSFMPhonemeExtractor::LogPhonemes(this, nItemIndex: (DmeTime_t)i, info);
}

//------------------------------------------------------------------------------
// Address: 0x0053F3A0
// Name: public: virtual void CSFMPhonemeExtractor::Extract(enum PE_APITYPE const __near &,struct ExtractDesc_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::Extract(
        CSFMPhonemeExtractor *this,
        const PE_APITYPE *apiType,
        ExtractDesc_t *info,
        bool bWritePhonemesToWavFiles)
{
  ExtractDesc_t *v4; // esi
  bool v5; // zf
  int m_Size; // edx
  int v7; // eax
  Extractor *m_pMemory; // edi
  Extractor *i; // ecx
  CExtractInfo *v10; // ebx
  const char *v11; // eax
  const char *v12; // eax
  char *m_Id; // edi
  char *v14; // eax
  unsigned __int8 *v15; // edi
  double v16; // st7
  int v17; // ecx
  int v18; // eax
  int v19; // esi
  int v20; // esi
  int v21; // ecx
  const char *v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // esi
  double v26; // st7
  CWordTag *v27; // eax
  double v28; // st5
  int m_uiEndByte; // ecx
  double v30; // st4
  int v31; // edx
  CPhonemeTag *v32; // ecx
  double v33; // st4
  int j; // esi
  DmeTime_t v35; // edi
  char pFullPath[512]; // [esp+28h] [ebp-4F4h] BYREF
  char pSoundName[512]; // [esp+228h] [ebp-2F4h] BYREF
  CSentence in; // [esp+428h] [ebp-F4h] BYREF
  CSentence out; // [esp+474h] [ebp-A8h] BYREF
  CUtlBuffer buf; // [esp+4C0h] [ebp-5Ch] BYREF
  Extractor *extractor; // [esp+4F0h] [ebp-2Ch]
  float bytespersecond; // [esp+4F4h] [ebp-28h]
  CSFMPhonemeExtractor *v43; // [esp+4F8h] [ebp-24h]
  int nDataSize; // [esp+4FCh] [ebp-20h] BYREF
  CExtractInfo *workItem; // [esp+500h] [ebp-1Ch]
  int nWorkItem; // [esp+504h] [ebp-18h]
  int nChannels; // [esp+508h] [ebp-14h]
  unsigned int v48; // [esp+50Ch] [ebp-10h]
  float flTrueSampleSize; // [esp+510h] [ebp-Ch]
  float flSampleRate; // [esp+514h] [ebp-8h]
  int nBitsPerSample; // [esp+518h] [ebp-4h]

  v4 = info;
  v5 = info->m_pSet == nullptr;
  v43 = this;
  if ( !v5 )
  {
    m_Size = this->m_Extractors.m_Size;
    v7 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Extractors.m_Memory.m_pMemory;
      for ( i = m_pMemory; i->apitype != *apiType; ++i )
      {
        if ( ++v7 >= m_Size )
          return;
      }
      if ( v7 != -1 )
      {
        extractor = &m_pMemory[v7];
        nWorkItem = 0;
        if ( info->m_WorkList.m_Size > 0 )
        {
          v48 = 0;
          do
          {
            v10 = &v4->m_WorkList.m_Memory.m_pMemory[v48 / 0x84];
            workItem = v10;
            v10->m_flDuration = 0.0;
            CSentence::CSentence(this: &in);
            CSentence::CSentence(this: &out);
            v11 = CUtlString::operator char const *(this: &v10->m_sHintText);
            CSentence::SetText(this: &in, text: v11);
            v12 = CUtlString::operator char const *(this: &v10->m_sHintText);
            CSentence::SetText(this: &out, text: v12);
            m_Id = (char *)&pParentName;
            if ( v10->m_pSound->m_SoundName.m_Storage.u.m_Id != -1 )
              m_Id = (char *)v10->m_pSound->m_SoundName.m_Storage.u.m_Id;
            if ( v10->m_bFullPathInSoundName
              && g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_Id, a3: nullptr) )
            {
              V_strncpy(pDest: pSoundName, pSrc: m_Id, maxLen: 512);
              V_strncpy(pDest: pFullPath, pSrc: m_Id, maxLen: 512);
            }
            else
            {
              v14 = PSkipSoundChars(pch: m_Id);
              V_snprintf(pDest: pSoundName, maxLen: 512, pFormat: "sound/%s", v14);
              V_FixSlashes(pname: pSoundName, separator: 92);
              g_pFullFileSystem->RelativePathToFullPath(
                this: g_pFullFileSystem,
                a2: pSoundName,
                a3: "GAME",
                a4: pFullPath,
                a5: 512,
                a6: FILTER_NONE,
                a7: nullptr);
            }
            CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
            if ( CSFMPhonemeExtractor::GetWaveFormat(
                   this: v43,
                   filename: pSoundName,
                   pBuf: &buf,
                   pDataSize: &nDataSize,
                   sentence: &v10->m_Sentence,
                   bGotSentence: &v10->m_bSentenceValid) != 0 )
            {
              v15 = buf.m_Memory.m_pMemory;
              if ( *((unsigned __int16 *)buf.m_Memory.m_pMemory + 7) > 8u )
              {
                v16 = (double)*((unsigned int *)buf.m_Memory.m_pMemory + 1);
                v17 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 7);
                nBitsPerSample = v17;
                v18 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1);
                flSampleRate = v16;
                nChannels = v18;
                v5 = *(_WORD *)buf.m_Memory.m_pMemory == 2;
                flTrueSampleSize = (float)((v17 * v18) >> 3);
                v19 = nDataSize / (v17 >> 3);
                if ( v5 )
                {
                  v20 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 9);
                  v21 = 7 * *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1)
                      + *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1) * (v20 - 2) / 2;
                  v10 = workItem;
                  nBitsPerSample = 16;
                  flTrueSampleSize = 0.5;
                  v19 = nDataSize / v21 * v20;
                  if ( nDataSize % v21 != 0 )
                    v19 += 2 * (nDataSize % v21 - v21) / nChannels + *((unsigned __int16 *)buf.m_Memory.m_pMemory + 9);
                }
                if ( flSampleRate > 0.0 )
                  v10->m_flDuration = (float)v19 / flSampleRate;
                v22 = CUtlString::operator char const *(this: &v10->m_sHintText);
                CSentence::CreateEventWordDistribution(this: &in, pszText: v22, flSentenceDuration: v10->m_flDuration);
                if ( v10->m_bUseSentence && v10->m_bSentenceValid )
                {
                  _Msg(a1: v23, a2: "Using .wav file phonemes for (%s)\n");
                  CSentence::operator=(this: &out, src: &v10->m_Sentence);
                }
                else
                {
                  extractor->extractor->Extract(
                    this: extractor->extractor,
                    a2: pFullPath,
                    a3: (int)(float)((float)(flSampleRate * v10->m_flDuration) * flTrueSampleSize),
                    a4: (void (*)(const char *, ...))_Msg,
                    a5: &in,
                    a6: &out);
                  if ( *apiType == SPEECH_API_LIPSINC && nChannels == 2 && nBitsPerSample == 16 )
                    v24 = flTrueSampleSize * 2.0;
                  else
                    v24 = flTrueSampleSize;
                  v25 = 0;
                  bytespersecond = v24 * flSampleRate;
                  if ( out.m_Words.m_Size > 0 )
                  {
                    v26 = bytespersecond;
                    do
                    {
                      v27 = out.m_Words.m_Memory.m_pMemory[v25];
                      if ( v27 != nullptr )
                      {
                        v28 = 1.0 / v26;
                        m_uiEndByte = v27->m_uiEndByte;
                        v27->m_flStartTime = (double)v27->m_uiStartByte * (1.0 / v26);
                        v30 = (double)(int)v27->m_uiEndByte;
                        if ( m_uiEndByte < 0 )
                          v30 = v30 + 4294967300.0;
                        v31 = 0;
                        for ( v27->m_flEndTime = v30 * v28; v31 < v27->m_Phonemes.m_Size; ++v31 )
                        {
                          v32 = v27->m_Phonemes.m_Memory.m_pMemory[v31];
                          if ( v32 != nullptr )
                          {
                            v15 = (unsigned __int8 *)v32->m_uiEndByte;
                            v32->m_flStartTime = (double)v32->m_uiStartByte * v28;
                            v33 = (double)(int)v32->m_uiEndByte;
                            if ( (int)v15 < 0 )
                              v33 = v33 + 4294967300.0;
                            v32->m_flEndTime = v33 * v28;
                          }
                        }
                      }
                      ++v25;
                    }
                    while ( v25 < out.m_Words.m_Size );
                  }
                  if ( bWritePhonemesToWavFiles )
                    SaveSentenceToWavFile(pWavFile: pFullPath, a2: (int)v10, a3: (int)v15, sentence: &out);
                }
                for ( j = 0; j < v10->m_ApplyTags.m_Size; ++j )
                  free(pMem: v10->m_ApplyTags.m_Memory.m_pMemory[j]);
                v10->m_ApplyTags.m_Size = 0;
                BuildPhonemeStream(list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v10->m_ApplyTags, in: &out);
                if ( buf.m_Memory.m_nGrowSize >= 0 )
                {
                  if ( buf.m_Memory.m_pMemory != nullptr )
                  {
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
                    buf.m_Memory.m_pMemory = nullptr;
                  }
                  buf.m_Memory.m_nAllocationCount = 0;
                }
                CSentence::~CSentence(this: &out);
                CSentence::~CSentence(this: &in);
                v4 = info;
                goto LABEL_58;
              }
              _Warning(
                a1: "Cannot extract phonemes from '%s', %u bits per sample.\n",
                pSoundName,
                *((unsigned __int16 *)buf.m_Memory.m_pMemory + 7));
            }
            if ( buf.m_Memory.m_nGrowSize >= 0 )
            {
              if ( buf.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
                buf.m_Memory.m_pMemory = nullptr;
              }
              buf.m_Memory.m_nAllocationCount = 0;
            }
            CSentence::~CSentence(this: &out);
            CSentence::~CSentence(this: &in);
LABEL_58:
            v48 += 132;
            ++nWorkItem;
          }
          while ( nWorkItem < v4->m_WorkList.m_Size );
        }
        for ( v35.m_tms = 0; v35.m_tms < v4->m_WorkList.m_Size; ++v35.m_tms )
          CSFMPhonemeExtractor::LogPhonemes(this: v43, nItemIndex: v35, info: (CExtractInfo *)v4);
      }
    }
  }
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00540590
// Name: UniquePhonemeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl UniquePhonemeLessFunc(CBasePhonemeTag *const *lhs, CBasePhonemeTag *const *rhs)
{
  return (*lhs)->m_nPhonemeCode < (*rhs)->m_nPhonemeCode;
}

//------------------------------------------------------------------------------
// Address: 0x00540760
// Name: public: virtual void CSFMPhonemeExtractor::GetAPIInfo(int,class CUtlString __near *,enum PE_APITYPE __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::GetAPIInfo(
        CSFMPhonemeExtractor *this,
        int index,
        CUtlString *pPrintName,
        PE_APITYPE *pAPIType)
{
  IPhonemeExtractor *extractor; // ecx
  const char *v6; // eax

  extractor = this->m_Extractors.m_Memory.m_pMemory[index].extractor;
  v6 = extractor->GetName(this: extractor);
  CUtlString::Set(this: pPrintName, pValue: v6);
  *pAPIType = this->m_Extractors.m_Memory.m_pMemory[index].apitype;
}

//------------------------------------------------------------------------------
// Address: 0x00541660
// Name: public: virtual void CSFMPhonemeExtractor::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::Shutdown(CSFMPhonemeExtractor *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Extractors.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: this->m_Extractors.m_Memory.m_pMemory[v3--].module);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Extractors.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005416A0
// Name: private: bool CSFMPhonemeExtractor::GetWaveFormat(char const __near *,class CUtlBuffer __near *,int __near *,class CSentence __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSFMPhonemeExtractor::GetWaveFormat(
        CSFMPhonemeExtractor *this,
        const char *filename,
        CUtlBuffer *pBuf,
        int *pDataSize,
        CSentence *sentence,
        bool *bGotSentence)
{
  char v6; // bl
  unsigned int Name; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  CUtlBuffer v12; // [esp+Ch] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+3Ch] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+54h] [ebp-10h] BYREF
  char gotData_3; // [esp+6Fh] [ebp+Bh]

  InFileRIFF::InFileRIFF(this: &riff, pFileName: filename, io: g_pFSIOReadBinary);
  IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
  v6 = 0;
  gotData_3 = 0;
  *bGotSentence = false;
  if ( !IterateRIFF::ChunkAvailable(this: &walk) )
    goto LABEL_18;
  do
  {
    Name = ConCommandBase::GetName(this: &walk);
    if ( Name == 544501094 )
    {
      v11 = IterateRIFF::ChunkSize(this: &walk);
      CUtlBuffer::SeekPut(this: pBuf, type: SEEK_HEAD, offset: v11);
      IterateRIFF::ChunkRead(this: &walk, pOutput: pBuf->m_Memory.m_pMemory);
      v6 = 1;
    }
    else
    {
      if ( Name == 1413563478 )
      {
        *bGotSentence = true;
        CUtlBuffer::CUtlBuffer(this: &v12, growSize: 0, initSize: 0, nFlags: 1u);
        v9 = IterateRIFF::ChunkSize(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v12, num: v9);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v12.m_Memory.m_pMemory);
        v10 = IterateRIFF::ChunkSize(this: &walk);
        CUtlBuffer::SeekPut(this: &v12, type: SEEK_HEAD, offset: v10);
        CSentence::InitFromDataChunk(this: sentence, data: v12.m_Memory.m_pMemory, size: v12.m_Put);
        if ( v12.m_Memory.m_nGrowSize >= 0 && v12.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Memory.m_pMemory);
      }
      else if ( Name == 1635017060 )
      {
        *pDataSize = IterateRIFF::ChunkSize(this: &walk);
        gotData_3 = 1;
      }
      if ( v6 == 0 )
        goto LABEL_9;
    }
    if ( gotData_3 != 0 && *bGotSentence )
      goto LABEL_12;
LABEL_9:
    IterateRIFF::ChunkNext(this: &walk);
  }
  while ( IterateRIFF::ChunkAvailable(this: &walk) );
  if ( v6 != 0 && gotData_3 != 0 )
  {
LABEL_12:
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
LABEL_18:
  InFileRIFF::~InFileRIFF(this: &riff);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00541830
// Name: public: virtual bool CSFMPhonemeExtractor::GetSentence(class CDmeGameSound __near *,class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSFMPhonemeExtractor::GetSentence(
        CSFMPhonemeExtractor *this,
        CDmeGameSound *gameSound,
        CSentence *sentence)
{
  char *m_Id; // eax
  char *v5; // eax
  char fullpath[512]; // [esp+4h] [ebp-430h] BYREF
  char soundname[512]; // [esp+204h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+404h] [ebp-30h] BYREF

  m_Id = (char *)gameSound->m_SoundName.m_Storage.u.CDmeSound::m_Id;
  if ( m_Id == (char *)-1 )
    m_Id = (char *)&pch;
  v5 = PSkipSoundChars(pch: m_Id);
  V_snprintf(pDest: soundname, maxLen: 512, pFormat: "sound/%s", v5);
  V_FixSlashes(pname: soundname, separator: 92);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: soundname,
    a3: "GAME",
    a4: fullpath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  HIBYTE(gameSound) = 0;
  if ( CSFMPhonemeExtractor::GetWaveFormat(
         this,
         filename: soundname,
         pBuf: &buf,
         pDataSize: (int *)&sentence,
         sentence,
         bGotSentence: (bool *)&gameSound + 3) != 0 )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return HIBYTE(gameSound);
  }
  else
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00541930
// Name: StoreValveDataChunk
// Source: json
//------------------------------------------------------------------------------
void __cdecl StoreValveDataChunk(CSentence *sentence, IterateOutputRIFF *store)
{
  CUtlBuffer buf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  CSentence::SaveToBuffer(this: sentence, &buf);
  IterateOutputRIFF::ChunkWriteData(this: store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00541990
// Name: SaveSentenceToWavFile
// Source: json
//------------------------------------------------------------------------------
char __usercall SaveSentenceToWavFile@<al>(const char *pWavFile@<esi>, int a2@<ebx>, int a3@<edi>, CSentence *sentence)
{
  CP4File *v4; // edi
  char v6; // bl
  unsigned int Name; // eax
  char pTempFile[512]; // [esp+0h] [ebp-290h] BYREF
  OutFileRIFF riffout; // [esp+200h] [ebp-90h] BYREF
  CUtlBuffer buf; // [esp+21Ch] [ebp-74h] BYREF
  InFileRIFF riff; // [esp+24Ch] [ebp-44h] BYREF
  IterateOutputRIFF store; // [esp+25Ch] [ebp-34h] BYREF
  IterateRIFF walk; // [esp+278h] [ebp-18h] BYREF

  V_StripExtension(in: pWavFile, out: pTempFile, outSize: 512);
  V_DefaultExtension(path: pTempFile, extension: ".tmp", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pTempFile, a3: "GAME") )
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pTempFile, a3: "GAME");
  v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pWavFile);
  ((void (__thiscall *)(CP4File *, int))v4->Edit)(a1: v4, a2: a3);
  if ( g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: pWavFile, a3: nullptr) )
  {
    ((void (__thiscall *)(IFileSystem *, const char *, char *, const char *, int))g_pFullFileSystem->RenameFile)(
      a1: g_pFullFileSystem,
      a2: pWavFile,
      a3: pTempFile,
      a4: "GAME",
      a5: a2);
    InFileRIFF::InFileRIFF(this: &riff, pFileName: pTempFile, io: g_pFSIOReadBinary);
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    OutFileRIFF::OutFileRIFF(this: &riffout, pFileName: (int)pWavFile, io: (int)g_pFSIOWriteBinary);
    IterateOutputRIFF::IterateOutputRIFF(this: &store, riff: &riffout);
    v6 = 0;
    if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      goto LABEL_14;
    do
    {
      Name = ConCommandBase::GetName(this: &walk);
      IterateOutputRIFF::ChunkStart(this: &store, chunkname: Name);
      if ( ConCommandBase::GetName(this: &walk) == 1413563478 )
      {
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
        CSentence::SaveToBuffer(this: sentence, &buf);
        IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        v6 = 1;
      }
      else
      {
        IterateOutputRIFF::CopyChunkData(this: &store, input: &walk);
      }
      IterateOutputRIFF::ChunkFinish(this: &store);
      IterateRIFF::ChunkNext(this: &walk);
    }
    while ( IterateRIFF::ChunkAvailable(this: &walk) );
    if ( v6 == 0 )
    {
LABEL_14:
      IterateOutputRIFF::ChunkStart(this: &store, chunkname: 0x54414456u);
      StoreValveDataChunk(sentence, &store);
      IterateOutputRIFF::ChunkFinish(this: &store);
    }
    OutFileRIFF::~OutFileRIFF(this: &riffout);
    InFileRIFF::~InFileRIFF(this: &riff);
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pTempFile, a3: nullptr);
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 1;
  }
  else
  {
    _Warning(a1: "%s is not writable, can't save sentence data to file\n");
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00541BE0
// Name: void AddBookmarkAtSoundMediaTime(char const __near *,class DmeTime_t,class DmeTime_t,struct DmeClipStack_t const __near &,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBookmarkAtSoundMediaTime(
        const char *pName,
        DmeTime_t tStart,
        DmeTime_t tEnd,
        DmeClipStack_t *srcStack,
        ExtractDesc_t *info)
{
  DmeTime_t *v5; // eax
  ExtractDesc_t *v6; // esi
  DmeTime_t *v7; // eax
  DmeTime_t *v8; // eax
  DmeTime_t *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  CDmAttribute *m_Id; // ecx
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *Bookmarks; // esi
  DmeTime_t result; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t v17; // [esp+10h] [ebp-4h] BYREF
  ExtractDesc_t *tStarta; // [esp+20h] [ebp+Ch]
  ExtractDesc_t *tEnda; // [esp+24h] [ebp+10h]

  v5 = DmeClipStack_t::FromChildMediaTime(this: srcStack, &result, t: tStart, bClamp: false);
  v6 = info;
  v7 = CDmeClip::ToChildMediaTime(this: info->m_pMovie, result: (DmeTime_t *)&info, t: (DmeTime_t)v5->m_tms, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: v6->m_pShot, result: &v17, t: (DmeTime_t)v7->m_tms, bClamp: 0);
  tStarta = (ExtractDesc_t *)v17.m_tms;
  v8 = DmeClipStack_t::FromChildMediaTime(this: srcStack, &result, t: tEnd, bClamp: false);
  v9 = CDmeClip::ToChildMediaTime(this: v6->m_pMovie, result: &v17, t: (DmeTime_t)v8->m_tms, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: v6->m_pShot, result: (DmeTime_t *)&info, t: (DmeTime_t)v9->m_tms, bClamp: 0);
  tEnda = info;
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeBookmark::m_classType.u.m_Id,
          a3: pName,
          a4: v6->m_pShot->m_fileId,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = v11;
  if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeBookmark::m_classType) )
    v12 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&info, a3: pName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: *(CDmAttribute **)v12[1].m_Id.m_Value,
    value: (const CUtlSymbolLarge *)&info);
  info = tStarta;
  CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)&v12[1].m_Id.m_Value[8], value: (const DmeTime_t *)&info);
  m_Id = (CDmAttribute *)v12[1].m_Name.m_Storage.u.m_Id;
  info = (ExtractDesc_t *)((char *)tEnda - (char *)tStarta);
  CDmAttribute::SetValue<DmeTime_t>(this: m_Id, value: (const DmeTime_t *)&info);
  ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: v6->m_pShot);
  if ( ActiveBookmarkSet != nullptr )
  {
    Bookmarks = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
    info = (ExtractDesc_t *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v12);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: Bookmarks,
      src: (const DmElementHandle_t *)&info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00543980
// Name: private: class CDmeChannelsClip __near * CSFMPhonemeExtractor::FindFacialChannelsClip(class CUtlVector<struct LogPreview_t __near *,class CUtlMemory<struct LogPreview_t __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CSFMPhonemeExtractor::FindFacialChannelsClip(
        CSFMPhonemeExtractor *this,
        const CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *list)
{
  CDmeChannelsClip *v2; // esi
  int v3; // edi
  CDmElement *v4; // eax
  char *v5; // eax
  CExpressionCalculator *v6; // ecx
  CDmeChannelsClip *Referring; // eax

  v2 = nullptr;
  v3 = list->m_Size - 1;
  if ( v3 < 0 )
    goto LABEL_13;
  do
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: list->m_Memory.m_pMemory[v3]->m_hChannels[0].m_handle);
    if ( v4 != nullptr && (v5 = (char *)&v4[-1] + 64) != nullptr )
      v6 = (CExpressionCalculator *)(v5 + 4);
    else
      v6 = nullptr;
    Referring = FindReferringElement<CDmeChannelsClip>(
                  pElement: v6,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( v2 != nullptr )
    {
      if ( v2 != Referring )
        _Warning(a1: "Selected controls overlap multiple channels clips!!!\n");
    }
    else if ( Referring != nullptr )
    {
      v2 = Referring;
    }
    --v3;
  }
  while ( v3 >= 0 );
  if ( v2 == nullptr )
LABEL_13:
    _Warning(a1: "Unable to determine destination channels clip!!!\n");
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00543A80
// Name: public: virtual bool CSFMPhonemeExtractor::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSFMPhonemeExtractor::Init@<al>(CSFMPhonemeExtractor *this@<ecx>, int a2@<edi>)
{
  const char *i; // eax
  struct CSysModule *v4; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IPhonemeExtractor *v6; // eax
  char fullpath[512]; // [esp+4h] [ebp-210h] BYREF
  Extractor e; // [esp+204h] [ebp-10h] BYREF
  int findHandle; // [esp+210h] [ebp-4h] BYREF

  for ( i = g_pFullFileSystem->FindFirstEx(
              this: g_pFullFileSystem,
              a2: "phonemeextractors/*.dll",
              a3: "EXECUTABLE_PATH",
              a4: &findHandle);
        i != nullptr;
        i = (const char *)((int (__thiscall *)(IFileSystem *))g_pFullFileSystem->FindNext)(a1: g_pFullFileSystem) )
  {
    V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "phonemeextractors/%s", i);
    v4 = (struct CSysModule *)((int (__thiscall *)(IFileSystem *, char *, _DWORD, int, int))g_pFullFileSystem->LoadModule)(
                                a1: g_pFullFileSystem,
                                a2: fullpath,
                                a3: 0,
                                a4: 1,
                                a5: a2);
    e.module = v4;
    if ( v4 != nullptr )
    {
      Factory = Sys_GetFactory(pModule: v4);
      if ( Factory != nullptr )
      {
        v6 = (IPhonemeExtractor *)Factory(a1: "PHONEME_EXTRACTOR_001", a2: nullptr);
        e.extractor = v6;
        if ( v6 != nullptr )
        {
          e.apitype = v6->GetAPIType(this: v6);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: &this->m_Extractors,
            elem: this->m_Extractors.m_Size,
            src: &e);
        }
        else
        {
          _Warning(a1: "Unable to get IPhonemeExtractor interface version %s from %s\n");
        }
      }
    }
    a2 = findHandle;
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00543BA0
// Name: BuildPhonemeStream
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildPhonemeStream(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list@<esi>, CSentence *in)
{
  CSentence *v2; // edi
  int v3; // ecx
  CWordTag *v4; // ebx
  int v5; // eax
  const CBasePhonemeTag *v6; // edi
  CBasePhonemeTag *v7; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CBasePhonemeTag **v10; // ecx
  int v11; // eax
  CBasePhonemeTag **v12; // eax
  int m_Size; // eax
  int v14; // ebx
  CBasePhonemeTag *v15; // eax
  int v16; // edi
  int v17; // eax
  CBasePhonemeTag **v18; // ecx
  int v19; // eax
  CBasePhonemeTag **v20; // eax
  int i; // [esp+8h] [ebp-Ch]
  CBasePhonemeTag *ia; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  CBasePhonemeTag *newTag; // [esp+10h] [ebp-4h]

  v2 = in;
  v3 = 0;
  for ( i = 0; v3 < v2->m_Words.m_Size; i = v3 )
  {
    v4 = v2->m_Words.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      v5 = 0;
      j = 0;
      if ( v4->m_Phonemes.m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Phonemes.m_Memory.m_pMemory[v5];
          if ( v6 != nullptr )
          {
            v7 = (CBasePhonemeTag *)operator new(nSize: 0xCu);
            if ( v7 != nullptr )
              newTag = CBasePhonemeTag::CBasePhonemeTag(this: v7, from: v6);
            else
              newTag = nullptr;
            m_pMemory = (int)list[1].m_pMemory;
            m_nAllocationCount = list->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
            ++list[1].m_pMemory;
            v10 = (CBasePhonemeTag **)list->m_pMemory;
            v11 = (int)list[1].m_pMemory - m_pMemory - 1;
            list[1].m_nAllocationCount = (int)list->m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
            v12 = (CBasePhonemeTag **)&list->m_pMemory[m_pMemory];
            if ( v12 != nullptr )
              *v12 = newTag;
          }
          v5 = j + 1;
          j = v5;
        }
        while ( v5 < v4->m_Phonemes.m_Size );
        v2 = in;
        v3 = i;
      }
    }
    ++v3;
  }
  if ( v2->m_Words.m_Size == 0 )
  {
    m_Size = v2->m_RunTimePhonemes.m_Size;
    if ( m_Size != 0 )
    {
      v14 = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v15 = (CBasePhonemeTag *)operator new(nSize: 0xCu);
          if ( v15 != nullptr )
            ia = CBasePhonemeTag::CBasePhonemeTag(this: v15, from: v2->m_RunTimePhonemes.m_Memory.m_pMemory[v14]);
          else
            ia = nullptr;
          v16 = (int)list[1].m_pMemory;
          v17 = list->m_nAllocationCount;
          if ( v16 + 1 > v17 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v16 - v17 + 1);
          ++list[1].m_pMemory;
          v18 = (CBasePhonemeTag **)list->m_pMemory;
          v19 = (int)list[1].m_pMemory - v16 - 1;
          list[1].m_nAllocationCount = (int)list->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v20 = (CBasePhonemeTag **)&list->m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = ia;
          if ( ++v14 >= in->m_RunTimePhonemes.m_Size )
            break;
          v2 = in;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00543D40
// Name: private: void CSFMPhonemeExtractor::BuildPhonemeLogList(class CUtlVector<struct LogPreview_t __near *,class CUtlMemory<struct LogPreview_t __near *,int>> __near &,class CUtlVector<class CDmeLog __near *,class CUtlMemory<class CDmeLog __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::BuildPhonemeLogList(
        CSFMPhonemeExtractor *this,
        CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *list,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *logs)
{
  CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *v3; // ecx
  int v4; // eax
  DmElementHandle_t *p_m_handle; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // eax
  CDmeChannel *v9; // ecx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeLog **v12; // ecx
  int v13; // eax
  CDmeLog **v14; // eax
  CDmeLog *log; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]
  int logsa; // [esp+14h] [ebp+Ch]

  v3 = list;
  v4 = 0;
  for ( i = 0; v4 < list->m_Size; i = v4 )
  {
    p_m_handle = &v3->m_Memory.m_pMemory[v4]->m_hChannels[0].m_handle;
    for ( logsa = 3; logsa != 0; --logsa )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
      if ( v7 != nullptr && v7 != (CDmElement *)4 )
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
        v9 = v8 != nullptr ? (CDmeChannel *)((char *)&v8[-1] + 64) : nullptr;
        log = CDmeChannel::GetLog(this: v9);
        if ( log != nullptr )
        {
          m_pMemory = (int)logs[1].m_pMemory;
          m_nAllocationCount = logs->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: logs, num: m_pMemory - m_nAllocationCount + 1);
          ++logs[1].m_pMemory;
          v12 = (CDmeLog **)logs->m_pMemory;
          v13 = (int)logs[1].m_pMemory - m_pMemory - 1;
          logs[1].m_nAllocationCount = (int)logs->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
          v14 = (CDmeLog **)&logs->m_pMemory[m_pMemory];
          if ( v14 != nullptr )
            *v14 = log;
        }
      }
      ++p_m_handle;
    }
    v3 = list;
    v4 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00543FC0
// Name: private: void CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(class DmeTime_t,class CUtlDict<struct LogPreview_t __near *,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
        CSFMPhonemeExtractor *this,
        DmeTime_t tHeadPosition,
        const CUtlDict<LogPreview_t *,int> *controlLookup)
{
  int Inorder; // eax
  LogPreview_t *elem; // edi
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  CDmaVar<float> *m_pData; // eax
  DmElementHandle_t *p_m_handle; // edi
  int i; // ebx
  CDmElement *v11; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v13; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // eax
  float flDefaultValue; // [esp+Ch] [ebp-8h] BYREF
  int j; // [esp+10h] [ebp-4h]

  Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup->m_Elements.m_Tree);
  j = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      elem = controlLookup->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: elem->m_hControl.m_handle);
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "defaultValue");
      v7 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v7, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      flDefaultValue = m_pData->m_Storage;
      p_m_handle = &elem->m_hChannels[0].m_handle;
      for ( i = 3; i != 0; --i )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
        if ( v11 != nullptr && v11 != (CDmElement *)4 )
        {
          Log = CDmeChannel::GetLog(this: (CDmeChannel *)((char *)&v11[-1] + 64));
          v13 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
          if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
          {
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v13);
            Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(this: v13, index: TopmostLayer);
            if ( Layer != nullptr )
              CDmeTypedLogLayer<float>::InsertKey(
                this: Layer,
                nTime: tHeadPosition,
                value: &flDefaultValue,
                interpSetting: SEGMENT_INTERPOLATE,
                curveType: 0,
                bIgnoreTolerance: 0);
          }
        }
        ++p_m_handle;
      }
      j = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
            this: &controlLookup->m_Elements.m_Tree,
            i: j);
      if ( j == -1 )
        break;
      Inorder = j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544140
// Name: private: void CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(class DmeTime_t,class CUtlDict<struct LogPreview_t __near *,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(
        CSFMPhonemeExtractor *this,
        DmeTime_t tHeadPosition,
        const CUtlDict<LogPreview_t *,int> *controlLookup)
{
  const CUtlDict<LogPreview_t *,int> *v3; // esi
  int i; // ebx
  DmElementHandle_t *p_m_handle; // edi
  CDmElement *v6; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v8; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // eax
  CDmeTypedLogLayer<float> *v11; // esi
  float flCurrentValue; // [esp+Ch] [ebp-8h] BYREF
  int j; // [esp+10h] [ebp-4h]

  v3 = controlLookup;
  for ( i = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
              this: &controlLookup->m_Elements.m_Tree,
              i) )
  {
    p_m_handle = &v3->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem->m_hChannels[0].m_handle;
    for ( j = 3; j != 0; --j )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *p_m_handle);
      if ( v6 != nullptr && v6 != (CDmElement *)4 )
      {
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)((char *)&v6[-1] + 64));
        v8 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
        if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
        {
          TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
          Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(this: v8, index: TopmostLayer);
          v11 = Layer;
          if ( Layer != nullptr )
          {
            flCurrentValue = *CDmeTypedLogLayer<float>::GetValue(
                                this: Layer,
                                a2: i,
                                a3: (int)p_m_handle,
                                time: tHeadPosition);
            CDmeTypedLogLayer<float>::InsertKey(
              this: v11,
              nTime: tHeadPosition,
              value: &flCurrentValue,
              interpSetting: SEGMENT_INTERPOLATE,
              curveType: 0,
              bIgnoreTolerance: 0);
          }
        }
      }
      ++p_m_handle;
    }
    v3 = controlLookup;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544220
// Name: private: void CSFMPhonemeExtractor::StampControlValueLogs(class CDmePreset __near *,class DmeTime_t,float,class CUtlDict<struct LogPreview_t __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::StampControlValueLogs(
        CSFMPhonemeExtractor *this,
        CDmePreset *preset,
        DmeTime_t tHeadPosition,
        float flIntensity,
        CUtlDict<LogPreview_t *,int> *controlLookup)
{
  CDmaVar<Vector> *Bookmarks; // esi
  float z; // eax
  int v7; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *m_pAsString; // esi
  const char *v11; // eax
  int v12; // eax
  LogPreview_t *v13; // edi
  const char **v14; // ebx
  CDmElement *v15; // eax
  CDmeChannel *v16; // esi
  CDmElement *v17; // edi
  CDmeLog *Log; // eax
  CDmeTypedLog<CUtlSymbolLarge> *v19; // esi
  int TopmostLayer; // eax
  CDmeTypedLogLayer<float> *Layer; // esi
  CDmaVar<float> *v22; // eax
  CDmaVar<float> *v23; // eax
  float *v24; // eax
  const char *v25; // [esp-4h] [ebp-38h]
  CUtlMap<char const *,LogPreview_t *,int>::Node_t search; // [esp+Ch] [ebp-28h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v27; // [esp+14h] [ebp-20h] BYREF
  float value; // [esp+1Ch] [ebp-18h] BYREF
  float flNewValue; // [esp+20h] [ebp-14h]
  CDmElement *v30; // [esp+24h] [ebp-10h]
  LogPreview_t *lp; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  float flDefault; // [esp+30h] [ebp-4h]
  CDmeHandle<CDmeChannel,0> *preseta; // [esp+3Ch] [ebp+8h]

  if ( !CDmePreset::IsAnimated(this: preset) )
  {
    Bookmarks = CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)preset);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v27);
    z = Bookmarks[1].m_Storage.z;
    v7 = 0;
    if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
    {
      v27.m_pAttribute = nullptr;
      v27.m_pStorage = nullptr;
    }
    else
    {
      v27.m_pAttribute = (CDmAttribute *)LODWORD(Bookmarks[1].m_Storage.z);
      v27.m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(z) + 4);
    }
    j = 0;
    if ( CDmrElementArray<CDmElement>::Count(this: (CDmrElementArray<CDmElement> *)&v27) > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v27.m_pStorage->m_Memory.m_pMemory[v7].m_tms);
        v9 = v8;
        v30 = v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
        {
          m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
          {
            v11 = &pch;
LABEL_12:
            search.key = v11;
            v12 = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::Find(
                    this: &controlLookup->m_Elements.m_Tree,
                    &search);
            if ( v12 != -1 )
            {
              lp = controlLookup->m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
              v13 = lp;
              v14 = s_pAttributeValueNames;
              preseta = lp->m_hChannels;
              while ( 1 )
              {
                v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: preseta->m_handle);
                if ( v15 != nullptr )
                {
                  v16 = (CDmeChannel *)((char *)&v15[-1] + 64);
                  if ( v15 != (CDmElement *)4 )
                  {
                    v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_hControl.m_handle);
                    if ( v17 != nullptr )
                    {
                      Log = CDmeChannel::GetLog(this: v16);
                      v19 = (CDmeTypedLog<CUtlSymbolLarge> *)Log;
                      if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
                      {
                        TopmostLayer = CDmeLog::GetTopmostLayer(this: v19);
                        Layer = (CDmeTypedLogLayer<float> *)CDmeTypedLog<DmeTime_t>::GetLayer(
                                                              this: v19,
                                                              index: TopmostLayer);
                        if ( Layer != nullptr )
                        {
                          v22 = CDmElement::GetValue<float>(this: v17, pAttributeName: "defaultValue");
                          v25 = *v14;
                          flDefault = v22->m_Storage;
                          v23 = CDmElement::GetValue<float>(this: v30, pAttributeName: v25);
                          flNewValue = (float)(v23->m_Storage - flDefault) * flIntensity;
                          v24 = CDmeTypedLogLayer<float>::GetValue(
                                  this: Layer,
                                  a2: (int)v14,
                                  a3: (int)v17,
                                  time: tHeadPosition);
                          value = (float)((float)(*v24 - flDefault) + flNewValue) + flDefault;
                          CDmeTypedLogLayer<float>::InsertKey(
                            this: Layer,
                            nTime: tHeadPosition,
                            &value,
                            interpSetting: SEGMENT_INTERPOLATE,
                            curveType: 0,
                            bIgnoreTolerance: 0);
                        }
                      }
                    }
                  }
                }
                ++preseta;
                if ( (int)++v14 >= (int)&sfm_phonemeextractor )
                  break;
                v13 = lp;
              }
              v7 = j;
            }
            goto LABEL_24;
          }
          v11 = m_pAsString;
          if ( m_pAsString != nullptr )
            goto LABEL_12;
        }
LABEL_24:
        j = ++v7;
      }
      while ( v7 < CDmrElementArray<CDmElement>::Count(this: (CDmrElementArray<CDmElement> *)&v27) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544440
// Name: private: void CSFMPhonemeExtractor::ClearInterstitialSpaces(class CDmeChannelsClip __near *,class CUtlDict<struct LogPreview_t __near *,int> __near &,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::ClearInterstitialSpaces(
        CSFMPhonemeExtractor *this,
        CDmeLogLayer *pChannelsClip,
        CUtlDict<LogPreview_t *,int> *controlLookup,
        ExtractDesc_t *info)
{
  CDmeFilmClip *m_pMovie; // ecx
  CExtractInfo *v6; // esi
  int v7; // eax
  float m_flDuration; // xmm1_4
  float v9; // xmm0_4
  int m_tms; // esi
  int v11; // esi
  CDmeLog *v12; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *v14; // eax
  CDmeLogLayer *v15; // esi
  int j; // esi
  CDmeFilmClip *sec; // [esp+0h] [ebp-C0h]
  DmeTime_t v18; // [esp+10h] [ebp-B0h] BYREF
  DmeTime_t result; // [esp+14h] [ebp-ACh] BYREF
  DmeClipStack_t srcStack; // [esp+18h] [ebp-A8h] BYREF
  DmeClipStack_t dstStack; // [esp+48h] [ebp-78h] BYREF
  DmeTime_t tStartTime; // [esp+78h] [ebp-48h] BYREF
  DmeTime_t tChannelMediaStartTime; // [esp+7Ch] [ebp-44h] BYREF
  float f; // [esp+80h] [ebp-40h]
  DmeTime_t tEndTime; // [esp+84h] [ebp-3Ch] BYREF
  DmeTime_t tSoundMediaStartTime; // [esp+88h] [ebp-38h] BYREF
  DmeTime_t tSoundMediaEndTime; // [esp+8Ch] [ebp-34h] BYREF
  DmeTime_t tChannelMediaEndTime; // [esp+90h] [ebp-30h] BYREF
  CUtlVector<CDmeLog *,CUtlMemory<CDmeLog *,int> > logs; // [esp+94h] [ebp-2Ch] BYREF
  CSFMPhonemeExtractor *v30; // [esp+A8h] [ebp-18h]
  unsigned int v31; // [esp+ACh] [ebp-14h]
  DmeTime_t tChannelRelativeStartTime; // [esp+B0h] [ebp-10h] BYREF
  DmeTime_t v33; // [esp+B4h] [ebp-Ch] BYREF
  int i; // [esp+B8h] [ebp-8h]
  DmeTime_t tMaxTime; // [esp+BCh] [ebp-4h]
  CDmeLogLayer *layer; // [esp+C8h] [ebp+8h]
  DmeTime_t tMinTime; // [esp+D0h] [ebp+10h]
  int tMinTimea; // [esp+D0h] [ebp+10h]

  v30 = this;
  if ( info->m_WorkList.m_Size != 0 && info->m_nExtractType != EXTRACT_WIPE_SOUNDS )
  {
    memset(&logs, 0, sizeof(logs));
    CSFMPhonemeExtractor::BuildPhonemeLogList(
      this,
      list: &info->m_ControlList,
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&logs);
    tMinTime.m_tms = 0x7FFFFFFF;
    tMaxTime.m_tms = -2147483647;
    i = 0;
    if ( info->m_WorkList.m_Size > 0 )
    {
      v31 = 0;
      do
      {
        m_pMovie = info->m_pMovie;
        v6 = &info->m_WorkList.m_Memory.m_pMemory[v31 / 0x84];
        srcStack.m_tStart.m_tms = 0x80000000;
        srcStack.m_tDuration.m_tms = 0x80000000;
        srcStack.m_tOffset.m_tms = 0x80000000;
        dstStack.m_tStart.m_tms = 0x80000000;
        dstStack.m_tDuration.m_tms = 0x80000000;
        dstStack.m_tOffset.m_tms = 0x80000000;
        sec = info->m_pShot;
        memset(&srcStack, 0, 20);
        srcStack.m_bOptimized = false;
        memset(&dstStack, 0, 20);
        dstStack.m_bOptimized = false;
        CDmeClip::BuildClipStack(this: v6->m_pClip, pStack: &srcStack, pMovie: m_pMovie, pShot: sec);
        DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaStartTime, t: 0, bClamp: false);
        v7 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v6->m_flDuration));
        DmeClipStack_t::FromChildMediaTime(
          this: &srcStack,
          result: &tSoundMediaEndTime,
          t: (DmeTime_t)v7,
          bClamp: false);
        CDmeClip::GetStartInChildMediaTime(this: v6->m_pClip, result: &tStartTime);
        CDmeClip::GetEndInChildMediaTime(this: v6->m_pClip, result: &tEndTime);
        CDmeClip::BuildClipStack(
          this: (CDmeClip *)pChannelsClip,
          pStack: &dstStack,
          pMovie: info->m_pMovie,
          pShot: info->m_pShot);
        DmeClipStack_t::ToChildMediaTime(
          this: &dstStack,
          result: &tChannelMediaStartTime,
          t: tSoundMediaStartTime,
          bClamp: 0);
        DmeClipStack_t::ToChildMediaTime(
          this: &dstStack,
          result: &tChannelMediaEndTime,
          t: tSoundMediaEndTime,
          bClamp: 0);
        m_flDuration = v6->m_flDuration;
        v9 = 0.0;
        m_tms = tChannelMediaStartTime.m_tms;
        if ( m_flDuration != 0.0 )
          v9 = (float)((float)(tChannelMediaEndTime.m_tms - tChannelMediaStartTime.m_tms) * 0.000099999997)
             / m_flDuration;
        v33.m_tms = tStartTime.m_tms;
        f = v9;
        DmeTime_t::operator*=(this: &v33, &result, f: v9);
        tChannelRelativeStartTime.m_tms = m_tms + v33.m_tms;
        v33.m_tms = tEndTime.m_tms;
        DmeTime_t::operator*=(this: &v33, result: &v18, f);
        v11 = v33.m_tms + m_tms;
        if ( tChannelRelativeStartTime.m_tms < tMinTime.m_tms )
          tMinTime.m_tms = tChannelRelativeStartTime.m_tms;
        if ( v11 > tMaxTime.m_tms )
          tMaxTime.m_tms = v11;
        CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &dstStack.m_clips);
        if ( dstStack.m_clips.m_Memory.m_nGrowSize >= 0 )
        {
          if ( dstStack.m_clips.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstStack.m_clips.m_Memory.m_pMemory);
            dstStack.m_clips.m_Memory.m_pMemory = nullptr;
          }
          dstStack.m_clips.m_Memory.m_nAllocationCount = 0;
        }
        CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
        if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 && srcStack.m_clips.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
        v31 += 132;
        ++i;
      }
      while ( i < info->m_WorkList.m_Size );
    }
    tMinTimea = tMinTime.m_tms - 1;
    ++tMaxTime.m_tms;
    for ( i = 0; i < logs.m_Size; ++i )
    {
      v12 = logs.m_Memory.m_pMemory[i];
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v12);
      v14 = CDmeLog::GetLayer(this: v12, index: TopmostLayer);
      v15 = v14;
      layer = v14;
      if ( info->m_nExtractType != EXTRACT_WIPE_RANGE )
      {
        v14->ClearKeys(this: v14);
      }
      else
      {
        CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
          this: v30,
          tHeadPosition: (DmeTime_t)tMinTimea,
          controlLookup);
        CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v30, tHeadPosition: tMaxTime, controlLookup);
        for ( j = CDmeLogLayer::GetKeyCount(this: v15) - 1; j >= 0; --j )
        {
          CDmeLogLayer::GetKeyTime(this: layer, result: &tChannelRelativeStartTime, nKeyIndex: j);
          if ( tChannelRelativeStartTime.m_tms > tMinTimea && tChannelRelativeStartTime.m_tms < tMaxTime.m_tms )
            layer->RemoveKey(this: layer, a2: j, a3: 1);
        }
      }
    }
    if ( logs.m_Memory.m_nGrowSize >= 0 && logs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: logs.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544850
// Name: private: void CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(class CUtlVector<class CBasePhonemeTag __near *,class CUtlMemory<class CBasePhonemeTag __near *,int>> const __near &,class CDmeAnimationSet __near *,class CDmePresetGroup __near *,class CUtlDict<class CDmePreset __near *,unsigned short> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(
        CSFMPhonemeExtractor *this,
        const CUtlVector<CBasePhonemeTag *,CUtlMemory<CBasePhonemeTag *,int> > *stream,
        CDmeAnimationSet *pSet,
        CDmePresetGroup *pPresetGroup,
        int phonemeToPresetDict)
{
  const CUtlVector<CBasePhonemeTag *,CUtlMemory<CBasePhonemeTag *,int> > *v5; // eax
  int v6; // edi
  unsigned __int16 v7; // ax
  unsigned __int16 elem; // dx
  unsigned __int16 v9; // cx
  int v10; // esi
  UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short> *m_pMemory; // eax
  int v12; // esi
  int v13; // edx
  CBasePhonemeTag **v14; // esi
  CUtlDict<CDmePreset *,unsigned short> *v15; // edi
  const char *v16; // eax
  CDmePhonemeMapping *Mapping; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v19; // esi
  CDmaVar<CUtlSymbolLarge> *m_pData; // eax
  CDmePreset *Preset; // ebx
  char *v22; // eax
  unsigned __int16 v23; // ax
  unsigned __int16 v24; // dx
  unsigned __int16 v25; // cx
  int v26; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v27; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short> *v30; // ecx
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t *p_m_Data; // esi
  char remappedph[32]; // [esp+Ch] [ebp-74h] BYREF
  char ph[32]; // [esp+2Ch] [ebp-54h] BYREF
  CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl*)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short> > uniquePhonemes; // [esp+4Ch] [ebp-34h] BYREF
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t search; // [esp+68h] [ebp-18h] BYREF
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t insert; // [esp+70h] [ebp-10h] BYREF
  CBasePhonemeTag *tag; // [esp+78h] [ebp-8h] BYREF
  bool leftchild; // [esp+7Fh] [ebp-1h] BYREF

  v5 = stream;
  v6 = 0;
  uniquePhonemes.m_LessFunc = (bool (__cdecl *)(CBasePhonemeTag *const *, CBasePhonemeTag *const *))UniquePhonemeLessFunc;
  memset(&uniquePhonemes.m_Elements, 0, sizeof(uniquePhonemes.m_Elements));
  *(_DWORD *)&uniquePhonemes.m_Root = 0xFFFF;
  *(_DWORD *)&uniquePhonemes.m_FirstFree = -1;
  uniquePhonemes.m_pElements = nullptr;
  if ( stream->m_Size > 0 )
  {
    do
    {
      tag = v5->m_Memory.m_pMemory[v6];
      if ( CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::Find(
             this: &uniquePhonemes,
             search: &tag) == 0xFFFF )
      {
        insert.elem = (CDmePreset *)0xFFFF;
        leftchild = false;
        CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &uniquePhonemes,
          insert: &tag,
          parent: (unsigned __int16 *)&insert.elem,
          &leftchild);
        v7 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&uniquePhonemes);
        elem = (unsigned __int16)insert.elem;
        v9 = v7;
        v10 = 3 * v7;
        m_pMemory = uniquePhonemes.m_Elements.m_pMemory;
        v12 = 4 * v10;
        *(unsigned __int16 *)((char *)&uniquePhonemes.m_Elements.m_pMemory->m_Right + v12) = -1;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v12) = -1;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v12) = 0;
        *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v12) = elem;
        if ( elem == 0xFFFF )
        {
          uniquePhonemes.m_Root = v9;
        }
        else
        {
          v13 = elem;
          if ( leftchild )
            m_pMemory[v13].m_Left = v9;
          else
            m_pMemory[v13].m_Right = v9;
        }
        CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::InsertRebalance(
          this: &uniquePhonemes,
          elem: v9);
        ++uniquePhonemes.m_NumElements;
        v14 = (CBasePhonemeTag **)((char *)&uniquePhonemes.m_Elements.m_pMemory->m_Data + v12);
        if ( v14 != nullptr )
          *v14 = tag;
      }
      v5 = stream;
      ++v6;
    }
    while ( v6 < stream->m_Size );
  }
  tag = (CBasePhonemeTag *)(unsigned __int16)CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::FirstInorder(this: &uniquePhonemes);
  if ( tag != (CBasePhonemeTag *)0xFFFF )
  {
    v15 = (CUtlDict<CDmePreset *,unsigned short> *)phonemeToPresetDict;
    do
    {
      v16 = ConvertPhoneme(code: uniquePhonemes.m_Elements.m_pMemory[(unsigned __int16)tag].m_Data->m_nPhonemeCode);
      V_strncpy(pDest: ph, pSrc: v16, maxLen: 32);
      V_snprintf(pDest: remappedph, maxLen: 32, pFormat: "p_%s", ph);
      Mapping = CDmeAnimationSet::FindMapping(this: pSet, pRawPhoneme: ph);
      if ( Mapping != nullptr )
      {
        if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
          dword_5D6CC4 = 0;
          `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal = -1;
        }
        Attribute = CDmElement::FindAttribute(this: Mapping, pAttributeName: "preset");
        v19 = Attribute;
        if ( Attribute != nullptr )
        {
          if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
          }
          if ( (Attribute->m_nFlags & 0x1F) == 5 )
          {
            m_pData = (CDmaVar<CUtlSymbolLarge> *)Attribute->m_pData;
          }
          else if ( CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(this: Attribute) )
          {
            if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal = DMELEMENT_HANDLE_INVALID;
            }
            CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
              this: v19,
              value: &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal);
            m_pData = (CDmaVar<CUtlSymbolLarge> *)&`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal;
          }
          else
          {
            m_pData = &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
          }
        }
        else
        {
          m_pData = (CDmaVar<CUtlSymbolLarge> *)&`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
        }
        V_strncpy(
          pDest: remappedph,
          pSrc: m_pData->m_Storage.u.m_Id != -1 ? m_pData->m_Storage.u.m_pAsString : nullptr,
          maxLen: 32);
      }
      Preset = CDmePresetGroup::FindPreset(this: pPresetGroup, pPresetName: remappedph);
      if ( Preset != nullptr )
      {
        search.key = ph;
        if ( CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
               this: &v15->m_Elements.m_Tree,
               &search) == 0xFFFF )
        {
          v22 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(ph) + 1);
          if ( v22 != nullptr )
            strcpy(v22, ph);
          else
            v22 = nullptr;
          insert.key = v22;
          insert.elem = Preset;
          phonemeToPresetDict = 0xFFFF;
          HIBYTE(stream) = 0;
          CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &v15->m_Elements.m_Tree,
            &insert,
            parent: (unsigned __int16 *)&phonemeToPresetDict,
            leftchild: (bool *)&stream + 3);
          v23 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &v15->m_Elements.m_Tree);
          v24 = phonemeToPresetDict;
          v25 = v23;
          v26 = v23;
          v27 = &v15->m_Elements.m_Tree.m_Elements.m_pMemory[v26];
          v27->m_Right = -1;
          v27->m_Left = -1;
          v27->m_Parent = v24;
          v27->m_Tag = 0;
          if ( v24 == 0xFFFF )
          {
            v15->m_Elements.m_Tree.m_Root = v25;
          }
          else
          {
            v28 = v15->m_Elements.m_Tree.m_Elements.m_pMemory;
            v29 = v24;
            if ( HIBYTE(stream) != 0 )
              v28[v29].m_Left = v25;
            else
              v28[v29].m_Right = v25;
          }
          CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: &v15->m_Elements.m_Tree,
            elem: v25);
          v30 = v15->m_Elements.m_Tree.m_Elements.m_pMemory;
          ++v15->m_Elements.m_Tree.m_NumElements;
          p_m_Data = &v30[v26].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
      }
      else
      {
        CDmElement::GetName(this: pSet);
        _Warning(a1: "Animation set '%s' missing phoneme preset for '%s' -> '%s'\n");
      }
      tag = (CBasePhonemeTag *)(unsigned __int16)CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::NextInorder(
                                                   this: &uniquePhonemes,
                                                   i: (unsigned __int16)tag);
    }
    while ( tag != (CBasePhonemeTag *)0xFFFF );
  }
  CUtlRBTree<CBasePhonemeTag *,unsigned short,bool (__cdecl *)(CBasePhonemeTag * const &,CBasePhonemeTag * const &),CUtlMemory<UtlRBTreeNode_t<CBasePhonemeTag *,unsigned short>,unsigned short>>::RemoveAll(this: &uniquePhonemes);
  if ( uniquePhonemes.m_Elements.m_nGrowSize >= 0 && uniquePhonemes.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uniquePhonemes.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00544C20
// Name: private: void CSFMPhonemeExtractor::LogPhonemes(int,struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::LogPhonemes(CSFMPhonemeExtractor *this, DmeTime_t nItemIndex, CExtractInfo *info)
{
  CExtractInfo *v4; // ebx
  CDmeAnimationSet *m_nGrowSize; // ecx
  int v6; // edi
  LogPreview_t *const *v7; // ebx
  char *m_Id; // eax
  CSFMPhonemeExtractor *v9; // edi
  CDmeFilmClip *m_nAllocationCount; // edx
  int v11; // ecx
  int v12; // eax
  CDmeFilmClip *v13; // edx
  float m_flDuration; // xmm1_4
  float v15; // xmm0_4
  int v16; // ebx
  float v17; // xmm0_4
  double v18; // xmm2_8
  float v19; // xmm0_4
  float v20; // xmm1_4
  DmeTime_t v21; // edi
  DmeTime_t v22; // ebx
  DmeTime_t *v23; // eax
  DmeTime_t *v24; // eax
  DmeTime_t *v25; // eax
  DmeTime_t *v26; // eax
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmePreset *Bookmarks; // eax
  int v29; // edi
  CDmElement *v30; // eax
  CDmElement *v31; // ebx
  int v32; // eax
  int v33; // ebx
  int j; // ebx
  CBasePhonemeTag *v35; // edi
  const char *v36; // eax
  unsigned int m_flStartTime_low; // xmm0_4
  CDmePreset *v38; // eax
  unsigned int m_flEndTime_low; // xmm0_4
  int v40; // eax
  float v41; // xmm1_4
  float v42; // xmm1_4
  double v43; // xmm0_8
  CBasePhonemeTag *v44; // esi
  int v45; // eax
  unsigned int v46; // xmm0_4
  int v47; // ebx
  int v48; // edi
  int v49; // eax
  DmeTime_t *p_tStart; // ecx
  int m_tms; // ecx
  int v52; // eax
  DmeTime_t *p_tPostPhonemeTime; // eax
  float v54; // xmm1_4
  float v55; // xmm0_4
  const char *v56; // eax
  unsigned __int16 v57; // ax
  CDmePreset *elem; // eax
  bool v59; // cc
  CBasePhonemeTag *v60; // ebx
  int v61; // eax
  unsigned int v62; // xmm0_4
  const char *v63; // eax
  unsigned __int16 v64; // ax
  DmeTime_t v65; // ebx
  DmeTime_t *p_tKeyTime; // eax
  DmeTime_t v67; // ebx
  int v68; // esi
  int m_Size; // edi
  CDmeLog **m_pMemory; // ebx
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int> *v72; // edi
  CDmeAnimationSet *v73; // [esp+Ch] [ebp-134h]
  CDmeFilmClip *sec; // [esp+10h] [ebp-130h]
  CDmeFilmClip *seca; // [esp+10h] [ebp-130h]
  int sec_4; // [esp+14h] [ebp-12Ch]
  float sec_4a; // [esp+14h] [ebp-12Ch]
  CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t search; // [esp+24h] [ebp-11Ch] BYREF
  DmeClipStack_t dstStack; // [esp+2Ch] [ebp-114h] BYREF
  DmeTime_t tSoundMediaEndTime; // [esp+5Ch] [ebp-E4h] BYREF
  DmeTime_t tStartTime; // [esp+60h] [ebp-E0h] BYREF
  double tStep; // [esp+64h] [ebp-DCh] BYREF
  DmeTime_t tSoundMediaStartTime; // [esp+6Ch] [ebp-D4h] BYREF
  DmeTime_t tChannelMediaEndTime; // [esp+70h] [ebp-D0h] BYREF
  DmeTime_t tChannelMediaStartTime; // [esp+74h] [ebp-CCh] BYREF
  DmeTime_t tEndTime; // [esp+78h] [ebp-C8h] BYREF
  DmeClipStack_t srcStack; // [esp+7Ch] [ebp-C4h] BYREF
  double flScale; // [esp+ACh] [ebp-94h]
  CUtlVector<CDmeLog *,CUtlMemory<CDmeLog *,int> > logs; // [esp+B4h] [ebp-8Ch] BYREF
  double flEndSoundTime; // [esp+C8h] [ebp-78h] BYREF
  CUtlDict<CDmePreset *,unsigned short> phonemeToPresetDict; // [esp+D0h] [ebp-70h] BYREF
  CUtlDict<LogPreview_t *,int> controlLookup; // [esp+ECh] [ebp-54h] BYREF
  double t; // [esp+110h] [ebp-30h]
  DmeTime_t flIntensity; // [esp+118h] [ebp-28h]
  int flOOFilter; // [esp+11Ch] [ebp-24h]
  DmeTime_t tEnd; // [esp+120h] [ebp-20h] BYREF
  DmeTime_t tStart; // [esp+124h] [ebp-1Ch] BYREF
  DmeTime_t tPostPhonemeTime; // [esp+128h] [ebp-18h] BYREF
  DmeTime_t tKeyTime; // [esp+12Ch] [ebp-14h] BYREF
  DmeTime_t flFilter; // [esp+130h] [ebp-10h] BYREF
  DmeTime_t tPhonemeTime; // [esp+134h] [ebp-Ch] BYREF
  int i; // [esp+138h] [ebp-8h]
  CDmePreset *preset; // [esp+13Ch] [ebp-4h]
  int tOffset; // [esp+148h] [ebp+8h]
  CExtractInfo *item; // [esp+14Ch] [ebp+Ch]

  v4 = (CExtractInfo *)(info->m_sHintText.m_Storage.m_Memory.m_nAllocationCount + 132 * nItemIndex.m_tms);
  i = (int)this;
  m_nGrowSize = (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize;
  v6 = 0;
  item = v4;
  if ( m_nGrowSize != nullptr && v4->m_pClip != nullptr && v4->m_pSound != nullptr )
  {
    tPostPhonemeTime.m_tms = (int)CDmeAnimationSet::FindPresetGroup(this: m_nGrowSize, pGroupName: "phoneme");
    if ( tPostPhonemeTime.m_tms == 0 )
    {
      _Warning(a1: "Animation set '%s' missing preset group 'phoneme'\n");
      return;
    }
    if ( CDmeAnimationSet::GetPhonemeMap(this: (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize)->m_Storage.m_Size == 0 )
      CDmeAnimationSet::RestoreDefaultPhonemeMap(this: (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize);
    v73 = (CDmeAnimationSet *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nGrowSize;
    memset(
      &phonemeToPresetDict.m_Elements.m_Tree.m_Elements,
      0,
      sizeof(phonemeToPresetDict.m_Elements.m_Tree.m_Elements));
    *(_DWORD *)&phonemeToPresetDict.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&phonemeToPresetDict.m_Elements.m_Tree.m_FirstFree = -1;
    phonemeToPresetDict.m_Elements.m_Tree.m_pElements = nullptr;
    phonemeToPresetDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    CSFMPhonemeExtractor::BuildPhonemeToPresetMapping(
      this: (CSFMPhonemeExtractor *)i,
      stream: &v4->m_ApplyTags,
      pSet: v73,
      pPresetGroup: (CDmePresetGroup *)tPostPhonemeTime.m_tms,
      (int)&phonemeToPresetDict);
    preset = (CDmePreset *)CSFMPhonemeExtractor::FindFacialChannelsClip(
                             this: (CSFMPhonemeExtractor *)i,
                             list: (const CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *)&info->m_Sentence.m_Words);
    if ( preset == nullptr )
      goto LABEL_19;
    memset(&controlLookup.m_Elements.m_Tree.m_Elements, 0, sizeof(controlLookup.m_Elements.m_Tree.m_Elements));
    controlLookup.m_Elements.m_Tree.m_Root = -1;
    controlLookup.m_Elements.m_Tree.m_NumElements = 0;
    controlLookup.m_Elements.m_Tree.m_FirstFree = -1;
    controlLookup.m_Elements.m_Tree.m_LastAlloc.index = -1;
    controlLookup.m_Elements.m_Tree.m_pElements = nullptr;
    controlLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    if ( info->m_Sentence.m_Words.m_Size > 0 )
    {
      do
      {
        v7 = (LogPreview_t *const *)&info->m_Sentence.m_Words.m_Memory.m_pMemory[v6];
        m_Id = (char *)g_pDataModel->GetElement(this: g_pDataModel, a2: (*v7)->m_hControl.m_handle)->m_Name.m_Storage.u.m_Id;
        if ( m_Id == (char *)-1 )
          m_Id = (char *)&pch;
        CUtlDict<LogPreview_t *,int>::Insert(this: &controlLookup, pName: m_Id, element: v7);
        ++v6;
      }
      while ( v6 < info->m_Sentence.m_Words.m_Size );
    }
    v9 = (CSFMPhonemeExtractor *)i;
    if ( nItemIndex.m_tms == 0 && *(int *)&info->m_bUseSentence > 1 )
      CSFMPhonemeExtractor::ClearInterstitialSpaces(
        this: (CSFMPhonemeExtractor *)i,
        pChannelsClip: (CDmeLogLayer *)preset,
        &controlLookup,
        (ExtractDesc_t *)info);
    m_nAllocationCount = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount;
    memset(&srcStack, 0, 20);
    srcStack.m_tStart.m_tms = 0x80000000;
    srcStack.m_tDuration.m_tms = 0x80000000;
    srcStack.m_tOffset.m_tms = 0x80000000;
    sec = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory;
    srcStack.m_bOptimized = false;
    CDmeClip::BuildClipStack(this: item->m_pClip, pStack: &srcStack, pMovie: sec, pShot: m_nAllocationCount);
    if ( srcStack.m_clips.m_Size == 0 )
    {
      CDmeClip::BuildClipStack(
        this: item->m_pClip,
        pStack: &srcStack,
        pMovie: (const CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
        pShot: nullptr);
      if ( srcStack.m_clips.m_Size == 0 )
      {
        _Msg(a1: v11, a2: "Couldn't build stack sound clip to current shot\n");
        DmeClipStack_t::~DmeClipStack_t(this: &srcStack);
        CUtlDict<LogPreview_t *,int>::RemoveAll(this: &controlLookup);
        CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>(this: &controlLookup.m_Elements.m_Tree);
LABEL_19:
        CUtlDict<CDmePreset *,unsigned short>::RemoveAll(this: &phonemeToPresetDict);
        CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &phonemeToPresetDict.m_Elements.m_Tree);
        return;
      }
    }
    DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaStartTime, t: 0, bClamp: false);
    v12 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(item->m_flDuration));
    DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tSoundMediaEndTime, t: (DmeTime_t)v12, bClamp: false);
    CDmeClip::GetStartInChildMediaTime(this: item->m_pClip, result: &tStartTime);
    CDmeClip::GetEndInChildMediaTime(this: item->m_pClip, result: &tEndTime);
    v13 = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount;
    memset(&dstStack, 0, 20);
    dstStack.m_tStart.m_tms = 0x80000000;
    dstStack.m_tDuration.m_tms = 0x80000000;
    dstStack.m_tOffset.m_tms = 0x80000000;
    seca = (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory;
    dstStack.m_bOptimized = false;
    CDmeClip::BuildClipStack(this: (CDmeClip *)preset, pStack: &dstStack, pMovie: seca, pShot: v13);
    DmeClipStack_t::ToChildMediaTime(
      this: &dstStack,
      result: &tChannelMediaStartTime,
      t: tSoundMediaStartTime,
      bClamp: 0);
    DmeClipStack_t::ToChildMediaTime(this: &dstStack, result: &tChannelMediaEndTime, t: tSoundMediaEndTime, bClamp: 0);
    m_flDuration = item->m_flDuration;
    v15 = 0.0;
    if ( m_flDuration != 0.0 )
      v15 = (float)((float)(tChannelMediaEndTime.m_tms - tChannelMediaStartTime.m_tms) * 0.000099999997) / m_flDuration;
    v16 = 0;
    tOffset = tChannelMediaStartTime.m_tms;
    flScale = v15;
    memset(&logs, 0, sizeof(logs));
    CSFMPhonemeExtractor::BuildPhonemeLogList(
      this: v9,
      list: (CUtlVector<LogPreview_t *,CUtlMemory<LogPreview_t *,int> > *)&info->m_Sentence.m_Words,
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&logs);
    if ( logs.m_Size > 0 )
    {
      do
      {
        logs.m_Memory.m_pMemory[v16]->AddNewLayer(this: logs.m_Memory.m_pMemory[v16]);
        ++v16;
      }
      while ( v16 < logs.m_Size );
    }
    v17 = (float)tStartTime.m_tms * 0.000099999997;
    if ( v17 < 0.0 )
      v17 = 0.0;
    v18 = v17;
    v19 = (float)tEndTime.m_tms * 0.000099999997;
    v20 = item->m_flDuration;
    t = v18;
    if ( v19 > v20 )
      v19 = v20;
    flEndSoundTime = v19;
    flIntensity.m_tms = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(v18 * flScale)) + tOffset - 1;
    CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(this: v9, tHeadPosition: flIntensity, &controlLookup);
    tPostPhonemeTime.m_tms = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(flEndSoundTime * flScale))
                           + tOffset
                           + 1;
    CSFMPhonemeExtractor::WriteCurrentValuesIntoLogLayers(this: v9, tHeadPosition: tPostPhonemeTime, &controlLookup);
    if ( LOBYTE(info->m_sHintText.m_Storage.m_Memory.m_pMemory) != 0 )
    {
      v21.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&t);
      tPhonemeTime.m_tms = v21.m_tms;
      v22.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&flEndSoundTime);
      tStart.m_tms = v22.m_tms;
      v23 = DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tKeyTime, t: v21, bClamp: false);
      v24 = CDmeClip::ToChildMediaTime(
              this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
              result: &tKeyTime,
              t: (DmeTime_t)v23->m_tms,
              bClamp: 0);
      CDmeClip::ToChildMediaTime(
        this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount,
        result: &tEnd,
        t: (DmeTime_t)v24->m_tms,
        bClamp: 0);
      v25 = DmeClipStack_t::FromChildMediaTime(this: &srcStack, result: &tKeyTime, t: v22, bClamp: false);
      v26 = CDmeClip::ToChildMediaTime(
              this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_pMemory,
              result: &tKeyTime,
              t: (DmeTime_t)v25->m_tms,
              bClamp: 0);
      CDmeClip::ToChildMediaTime(
        this: (CDmeClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount,
        result: &flFilter,
        t: (DmeTime_t)v26->m_tms,
        bClamp: 0);
      ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount);
      if ( ActiveBookmarkSet != nullptr )
      {
        Bookmarks = (CDmePreset *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
        v29 = *(_DWORD *)&Bookmarks->m_Id.m_Value[8] - 1;
        preset = Bookmarks;
        if ( v29 >= 0 )
        {
          while ( 1 )
          {
            v30 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&Bookmarks->OnAttributeChanged + v29));
            v31 = v30;
            if ( v30 != nullptr && v30->IsA(this: v30, a2: CDmeBookmark::m_classType) )
            {
              v32 = *(_DWORD *)&v31[1].m_Id.m_Value[4];
              v33 = *(_DWORD *)&v31[1].m_Id.m_Value[12];
              if ( v32 <= flFilter.m_tms && v32 + v33 >= tEnd.m_tms )
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
                  this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)preset,
                  elem: v29);
            }
            if ( --v29 < 0 )
              break;
            Bookmarks = preset;
          }
        }
        v21.m_tms = tPhonemeTime.m_tms;
      }
      AddBookmarkAtSoundMediaTime(pName: "start", tStart: v21, tEnd: v21, &srcStack, (ExtractDesc_t *)info);
      for ( j = 0; j < item->m_ApplyTags.m_Size; ++j )
      {
        v35 = item->m_ApplyTags.m_Memory.m_pMemory[j];
        v36 = ConvertPhoneme(code: v35->m_nPhonemeCode);
        m_flStartTime_low = LODWORD(v35->m_flStartTime);
        tPhonemeTime.m_tms = (int)v36;
        v38 = (CDmePreset *)DmeTime_t::RoundSecondsToTMS(sec: m_flStartTime_low);
        m_flEndTime_low = LODWORD(v35->m_flEndTime);
        preset = v38;
        v40 = DmeTime_t::RoundSecondsToTMS(sec: m_flEndTime_low);
        AddBookmarkAtSoundMediaTime(
          pName: (const char *)tPhonemeTime.m_tms,
          tStart: (DmeTime_t)preset,
          tEnd: (DmeTime_t)v40,
          &srcStack,
          (ExtractDesc_t *)info);
      }
      AddBookmarkAtSoundMediaTime(pName: "end", tStart, tEnd: tStart, &srcStack, (ExtractDesc_t *)info);
      v9 = (CSFMPhonemeExtractor *)i;
    }
    if ( info->m_pSound < (CDmeGameSound *)2 )
    {
      tPhonemeTime.m_tms = 0;
      for ( i = 0; i < item->m_ApplyTags.m_Size; ++i )
      {
        v60 = item->m_ApplyTags.m_Memory.m_pMemory[i];
        v61 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v60->m_flStartTime));
        v62 = LODWORD(v60->m_flEndTime);
        tKeyTime.m_tms = v61;
        *(float *)&flOOFilter = COERCE_FLOAT(DmeTime_t::RoundSecondsToTMS(sec: v62));
        v63 = ConvertPhoneme(code: v60->m_nPhonemeCode);
        if ( v63 != nullptr )
        {
          LODWORD(tStep) = v63;
          v64 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &phonemeToPresetDict.m_Elements.m_Tree,
                  search: (const CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t *)&tStep);
        }
        else
        {
          v64 = -1;
        }
        if ( v64 != 0xFFFF )
        {
          preset = phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory[v64].m_Data.elem;
          if ( preset != nullptr )
          {
            sec_4a = flScale;
            flFilter.m_tms = tKeyTime.m_tms;
            tStart.m_tms = LODWORD(sec_4a);
            DmeTime_t::operator*=(this: &flFilter, result: &tEnd, f: sec_4a);
            v65.m_tms = tOffset + flFilter.m_tms;
            if ( info->m_pSound == nullptr )
            {
              if ( v65.m_tms - 1 > flIntensity.m_tms )
              {
                CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
                  this: v9,
                  tHeadPosition: (DmeTime_t)(v65.m_tms - 1),
                  &controlLookup);
                if ( tPhonemeTime.m_tms != 0 )
                  CSFMPhonemeExtractor::StampControlValueLogs(
                    this: v9,
                    preset: (CDmePreset *)tPhonemeTime.m_tms,
                    tHeadPosition: (DmeTime_t)(v65.m_tms - 1),
                    flIntensity: 1.0,
                    &controlLookup);
              }
              tPhonemeTime.m_tms = (int)preset;
            }
            CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v9, tHeadPosition: v65, &controlLookup);
            CSFMPhonemeExtractor::StampControlValueLogs(
              this: v9,
              preset,
              tHeadPosition: v65,
              flIntensity: 1.0,
              &controlLookup);
            if ( info->m_pSound == nullptr && i == item->m_ApplyTags.m_Size - 1 )
            {
              flFilter.m_tms = flOOFilter;
              DmeTime_t::operator*=(
                this: &flFilter,
                result: (DmeTime_t *)&flEndSoundTime + 1,
                f: *(float *)&tStart.m_tms);
              tKeyTime.m_tms = flFilter.m_tms + tOffset;
              p_tKeyTime = &tKeyTime;
              if ( flFilter.m_tms + tOffset >= tPostPhonemeTime.m_tms )
                p_tKeyTime = &tPostPhonemeTime;
              v67.m_tms = p_tKeyTime->m_tms;
              CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(
                this: v9,
                tHeadPosition: (DmeTime_t)(p_tKeyTime->m_tms - 1),
                &controlLookup);
              CSFMPhonemeExtractor::StampControlValueLogs(
                this: v9,
                preset,
                tHeadPosition: (DmeTime_t)(v67.m_tms - 1),
                flIntensity: 1.0,
                &controlLookup);
              CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v9, tHeadPosition: v67, &controlLookup);
            }
          }
        }
      }
    }
    else
    {
      v41 = *(float *)&info->m_Sentence.m_RunTimePhonemes.m_Size;
      if ( v41 >= 1.0 )
      {
        if ( v41 > 1000.0 )
          v41 = 1000.0;
      }
      else
      {
        v41 = 1.0;
      }
      tStep = 1.0 / v41;
      v42 = *(float *)&info->m_Sentence.m_RunTimePhonemes.m_pElements;
      if ( v42 <= 0.001 )
        v42 = 0.001;
      flFilter.m_tms = LODWORD(v42);
      *(float *)&flOOFilter = 1.0 / v42;
      v43 = t;
      if ( flEndSoundTime > t )
      {
        do
        {
          tPhonemeTime.m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(unsigned __int64 *)&v43);
          tKeyTime.m_tms = tOffset + DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT64(t * flScale));
          CSFMPhonemeExtractor::WriteDefaultValuesIntoLogLayers(this: v9, tHeadPosition: tKeyTime, &controlLookup);
          preset = nullptr;
          if ( item->m_ApplyTags.m_Size > 0 )
          {
            do
            {
              v44 = item->m_ApplyTags.m_Memory.m_pMemory[(_DWORD)preset];
              v45 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(v44->m_flStartTime));
              v46 = LODWORD(v44->m_flEndTime);
              v47 = v45;
              tStart.m_tms = v45;
              v48 = DmeTime_t::RoundSecondsToTMS(sec: v46);
              tEnd.m_tms = v48;
              v49 = DmeTime_t::RoundSecondsToTMS(sec: flFilter.m_tms);
              p_tStart = &tStart;
              if ( v47 <= tPhonemeTime.m_tms )
                p_tStart = &tPhonemeTime;
              m_tms = p_tStart->m_tms;
              v52 = tPhonemeTime.m_tms + v49;
              if ( v48 >= v52 )
              {
                tPostPhonemeTime.m_tms = v52;
                p_tPostPhonemeTime = &tPostPhonemeTime;
              }
              else
              {
                p_tPostPhonemeTime = &tEnd;
              }
              v54 = (float)((float)(m_tms - tPhonemeTime.m_tms) * 0.000099999997) * *(float *)&flOOFilter;
              v55 = (float)((float)(p_tPostPhonemeTime->m_tms - tPhonemeTime.m_tms) * 0.000099999997)
                  * *(float *)&flOOFilter;
              if ( v54 < 1.0 && v55 > 0.0 )
              {
                if ( v55 > 1.0 )
                  v55 = 1.0;
                if ( v54 < 0.0 )
                  v54 = 0.0;
                sec_4 = v44->m_nPhonemeCode;
                *(float *)&flIntensity.m_tms = v55 - v54;
                v56 = ConvertPhoneme(code: sec_4);
                if ( v56 != nullptr )
                {
                  search.key = v56;
                  v57 = CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                          this: &phonemeToPresetDict.m_Elements.m_Tree,
                          &search);
                }
                else
                {
                  v57 = -1;
                }
                if ( v57 != 0xFFFF )
                {
                  elem = phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory[v57].m_Data.elem;
                  if ( elem != nullptr )
                    CSFMPhonemeExtractor::StampControlValueLogs(
                      this: (CSFMPhonemeExtractor *)i,
                      preset: elem,
                      tHeadPosition: tKeyTime,
                      flIntensity: *(float *)&flIntensity.m_tms,
                      &controlLookup);
                }
              }
              preset = (CDmePreset *)((char *)preset + 1);
            }
            while ( (int)preset < item->m_ApplyTags.m_Size );
            v9 = (CSFMPhonemeExtractor *)i;
          }
          v43 = t + tStep;
          v59 = flEndSoundTime <= t + tStep;
          t = t + tStep;
        }
        while ( !v59 );
      }
    }
    v68 = 0;
    if ( logs.m_Size > 0 )
    {
      m_Size = logs.m_Size;
      m_pMemory = logs.m_Memory.m_pMemory;
      do
        ((void (__stdcall *)(int, int, _DWORD))m_pMemory[v68++]->FlattenLayers)(a1: 953267991, a2: 1, a3: 0);
      while ( v68 < m_Size );
    }
    if ( logs.m_Memory.m_nGrowSize >= 0 && logs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: logs.m_Memory.m_pMemory);
    CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &dstStack.m_clips);
    if ( dstStack.m_clips.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dstStack.m_clips.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstStack.m_clips.m_Memory.m_pMemory);
        dstStack.m_clips.m_Memory.m_pMemory = nullptr;
      }
      dstStack.m_clips.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
    if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 )
    {
      if ( srcStack.m_clips.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
        srcStack.m_clips.m_Memory.m_pMemory = nullptr;
      }
      srcStack.m_clips.m_Memory.m_nAllocationCount = 0;
    }
    Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::FirstInorder(this: &controlLookup.m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      v72 = controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory;
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v72[Inorder].m_Data.key);
        Inorder = CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::NextInorder(
                    this: &controlLookup.m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
    }
    CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::RemoveAll(this: &controlLookup.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int,CUtlMap<char const *,LogPreview_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,LogPreview_t *,int>::Node_t,int>,int>>::RemoveAll(this: &controlLookup.m_Elements.m_Tree);
    if ( controlLookup.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlLookup.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
    CUtlDict<CDmePreset *,unsigned short>::RemoveAll(this: &phonemeToPresetDict);
    CUtlRBTree<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CDmePreset *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmePreset *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &phonemeToPresetDict.m_Elements.m_Tree);
    if ( phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: phonemeToPresetDict.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005457D0
// Name: public: virtual void CSFMPhonemeExtractor::ReApply(struct ExtractDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::ReApply(CSFMPhonemeExtractor *this, CExtractInfo *info)
{
  CDmeTransform *ActiveBookmarkSet; // eax
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *Bookmarks; // eax
  int i; // esi

  if ( LOBYTE(info->m_sHintText.m_Storage.m_Memory.m_pMemory) != 0 )
  {
    ActiveBookmarkSet = (CDmeTransform *)CDmeFilmClip::GetActiveBookmarkSet(this: (CDmeFilmClip *)info->m_Sentence.m_RunTimePhonemes.m_Memory.m_nAllocationCount);
    if ( ActiveBookmarkSet != nullptr )
    {
      Bookmarks = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeBookmarkSet::GetBookmarks(this: ActiveBookmarkSet);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: Bookmarks);
    }
  }
  for ( i = 0; i < *(_DWORD *)&info->m_bUseSentence; ++i )
    CSFMPhonemeExtractor::LogPhonemes(this, nItemIndex: (DmeTime_t)i, info);
}

//------------------------------------------------------------------------------
// Address: 0x00545820
// Name: public: virtual void CSFMPhonemeExtractor::Extract(enum PE_APITYPE const __near &,struct ExtractDesc_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMPhonemeExtractor::Extract(
        CSFMPhonemeExtractor *this,
        const PE_APITYPE *apiType,
        ExtractDesc_t *info,
        bool bWritePhonemesToWavFiles)
{
  ExtractDesc_t *v4; // esi
  bool v5; // zf
  int m_Size; // edx
  int v7; // eax
  Extractor *m_pMemory; // edi
  Extractor *i; // ecx
  CExtractInfo *v10; // ebx
  const char *v11; // eax
  const char *v12; // eax
  char *m_Id; // edi
  char *v14; // eax
  unsigned __int8 *v15; // edi
  double v16; // st7
  int v17; // ecx
  int v18; // eax
  int v19; // esi
  int v20; // esi
  int v21; // ecx
  const char *v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // esi
  double v26; // st7
  CWordTag *v27; // eax
  double v28; // st5
  int m_uiEndByte; // ecx
  double v30; // st4
  int v31; // edx
  CPhonemeTag *v32; // ecx
  double v33; // st4
  int j; // esi
  DmeTime_t v35; // edi
  char pFullPath[512]; // [esp+28h] [ebp-4F4h] BYREF
  char pSoundName[512]; // [esp+228h] [ebp-2F4h] BYREF
  CSentence in; // [esp+428h] [ebp-F4h] BYREF
  CSentence out; // [esp+474h] [ebp-A8h] BYREF
  CUtlBuffer buf; // [esp+4C0h] [ebp-5Ch] BYREF
  Extractor *extractor; // [esp+4F0h] [ebp-2Ch]
  float bytespersecond; // [esp+4F4h] [ebp-28h]
  CSFMPhonemeExtractor *v43; // [esp+4F8h] [ebp-24h]
  int nDataSize; // [esp+4FCh] [ebp-20h] BYREF
  CExtractInfo *workItem; // [esp+500h] [ebp-1Ch]
  int nWorkItem; // [esp+504h] [ebp-18h]
  int nChannels; // [esp+508h] [ebp-14h]
  unsigned int v48; // [esp+50Ch] [ebp-10h]
  float flTrueSampleSize; // [esp+510h] [ebp-Ch]
  float flSampleRate; // [esp+514h] [ebp-8h]
  int nBitsPerSample; // [esp+518h] [ebp-4h]

  v4 = info;
  v5 = info->m_pSet == nullptr;
  v43 = this;
  if ( !v5 )
  {
    m_Size = this->m_Extractors.m_Size;
    v7 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Extractors.m_Memory.m_pMemory;
      for ( i = m_pMemory; i->apitype != *apiType; ++i )
      {
        if ( ++v7 >= m_Size )
          return;
      }
      if ( v7 != -1 )
      {
        extractor = &m_pMemory[v7];
        nWorkItem = 0;
        if ( info->m_WorkList.m_Size > 0 )
        {
          v48 = 0;
          do
          {
            v10 = &v4->m_WorkList.m_Memory.m_pMemory[v48 / 0x84];
            workItem = v10;
            v10->m_flDuration = 0.0;
            CSentence::CSentence(this: &in);
            CSentence::CSentence(this: &out);
            v11 = CUtlString::operator char const *(this: &v10->m_sHintText);
            CSentence::SetText(this: &in, text: v11);
            v12 = CUtlString::operator char const *(this: &v10->m_sHintText);
            CSentence::SetText(this: &out, text: v12);
            m_Id = (char *)&pch;
            if ( v10->m_pSound->m_SoundName.m_Storage.u.m_Id != -1 )
              m_Id = (char *)v10->m_pSound->m_SoundName.m_Storage.u.m_Id;
            if ( v10->m_bFullPathInSoundName
              && g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_Id, a3: nullptr) )
            {
              V_strncpy(pDest: pSoundName, pSrc: m_Id, maxLen: 512);
              V_strncpy(pDest: pFullPath, pSrc: m_Id, maxLen: 512);
            }
            else
            {
              v14 = PSkipSoundChars(pch: m_Id);
              V_snprintf(pDest: pSoundName, maxLen: 512, pFormat: "sound/%s", v14);
              V_FixSlashes(pname: pSoundName, separator: 92);
              g_pFullFileSystem->RelativePathToFullPath(
                this: g_pFullFileSystem,
                a2: pSoundName,
                a3: "GAME",
                a4: pFullPath,
                a5: 512,
                a6: FILTER_NONE,
                a7: nullptr);
            }
            CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
            if ( CSFMPhonemeExtractor::GetWaveFormat(
                   this: v43,
                   filename: pSoundName,
                   pBuf: &buf,
                   pDataSize: &nDataSize,
                   sentence: &v10->m_Sentence,
                   bGotSentence: &v10->m_bSentenceValid) != 0 )
            {
              v15 = buf.m_Memory.m_pMemory;
              if ( *((unsigned __int16 *)buf.m_Memory.m_pMemory + 7) > 8u )
              {
                v16 = (double)*((unsigned int *)buf.m_Memory.m_pMemory + 1);
                v17 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 7);
                nBitsPerSample = v17;
                v18 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1);
                flSampleRate = v16;
                nChannels = v18;
                v5 = *(_WORD *)buf.m_Memory.m_pMemory == 2;
                flTrueSampleSize = (float)((v17 * v18) >> 3);
                v19 = nDataSize / (v17 >> 3);
                if ( v5 )
                {
                  v20 = *((unsigned __int16 *)buf.m_Memory.m_pMemory + 9);
                  v21 = 7 * *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1)
                      + *((unsigned __int16 *)buf.m_Memory.m_pMemory + 1) * (v20 - 2) / 2;
                  v10 = workItem;
                  nBitsPerSample = 16;
                  flTrueSampleSize = 0.5;
                  v19 = nDataSize / v21 * v20;
                  if ( nDataSize % v21 != 0 )
                    v19 += 2 * (nDataSize % v21 - v21) / nChannels + *((unsigned __int16 *)buf.m_Memory.m_pMemory + 9);
                }
                if ( flSampleRate > 0.0 )
                  v10->m_flDuration = (float)v19 / flSampleRate;
                v22 = CUtlString::operator char const *(this: &v10->m_sHintText);
                CSentence::CreateEventWordDistribution(this: &in, pszText: v22, flSentenceDuration: v10->m_flDuration);
                if ( v10->m_bUseSentence && v10->m_bSentenceValid )
                {
                  _Msg(a1: v23, a2: "Using .wav file phonemes for (%s)\n");
                  CSentence::operator=(this: &out, src: &v10->m_Sentence);
                }
                else
                {
                  extractor->extractor->Extract(
                    this: extractor->extractor,
                    a2: pFullPath,
                    a3: (int)(float)((float)(flSampleRate * v10->m_flDuration) * flTrueSampleSize),
                    a4: (void (*)(const char *, ...))_Msg,
                    a5: &in,
                    a6: &out);
                  if ( *apiType == SPEECH_API_LIPSINC && nChannels == 2 && nBitsPerSample == 16 )
                    v24 = flTrueSampleSize * 2.0;
                  else
                    v24 = flTrueSampleSize;
                  v25 = 0;
                  bytespersecond = v24 * flSampleRate;
                  if ( out.m_Words.m_Size > 0 )
                  {
                    v26 = bytespersecond;
                    do
                    {
                      v27 = out.m_Words.m_Memory.m_pMemory[v25];
                      if ( v27 != nullptr )
                      {
                        v28 = 1.0 / v26;
                        m_uiEndByte = v27->m_uiEndByte;
                        v27->m_flStartTime = (double)v27->m_uiStartByte * (1.0 / v26);
                        v30 = (double)(int)v27->m_uiEndByte;
                        if ( m_uiEndByte < 0 )
                          v30 = v30 + 4294967300.0;
                        v31 = 0;
                        for ( v27->m_flEndTime = v30 * v28; v31 < v27->m_Phonemes.m_Size; ++v31 )
                        {
                          v32 = v27->m_Phonemes.m_Memory.m_pMemory[v31];
                          if ( v32 != nullptr )
                          {
                            v15 = (unsigned __int8 *)v32->m_uiEndByte;
                            v32->m_flStartTime = (double)v32->m_uiStartByte * v28;
                            v33 = (double)(int)v32->m_uiEndByte;
                            if ( (int)v15 < 0 )
                              v33 = v33 + 4294967300.0;
                            v32->m_flEndTime = v33 * v28;
                          }
                        }
                      }
                      ++v25;
                    }
                    while ( v25 < out.m_Words.m_Size );
                  }
                  if ( bWritePhonemesToWavFiles )
                    SaveSentenceToWavFile(pWavFile: pFullPath, a2: (int)v10, a3: (int)v15, sentence: &out);
                }
                for ( j = 0; j < v10->m_ApplyTags.m_Size; ++j )
                  free(pMem: v10->m_ApplyTags.m_Memory.m_pMemory[j]);
                v10->m_ApplyTags.m_Size = 0;
                BuildPhonemeStream(list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v10->m_ApplyTags, in: &out);
                if ( buf.m_Memory.m_nGrowSize >= 0 )
                {
                  if ( buf.m_Memory.m_pMemory != nullptr )
                  {
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
                    buf.m_Memory.m_pMemory = nullptr;
                  }
                  buf.m_Memory.m_nAllocationCount = 0;
                }
                CSentence::~CSentence(this: &out);
                CSentence::~CSentence(this: &in);
                v4 = info;
                goto LABEL_58;
              }
              _Warning(a1: "Cannot extract phonemes from '%s', %u bits per sample.\n");
            }
            if ( buf.m_Memory.m_nGrowSize >= 0 )
            {
              if ( buf.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
                buf.m_Memory.m_pMemory = nullptr;
              }
              buf.m_Memory.m_nAllocationCount = 0;
            }
            CSentence::~CSentence(this: &out);
            CSentence::~CSentence(this: &in);
LABEL_58:
            v48 += 132;
            ++nWorkItem;
          }
          while ( nWorkItem < v4->m_WorkList.m_Size );
        }
        for ( v35.m_tms = 0; v35.m_tms < v4->m_WorkList.m_Size; ++v35.m_tms )
          CSFMPhonemeExtractor::LogPhonemes(this: v43, nItemIndex: v35, info: (CExtractInfo *)v4);
      }
    }
  }
}

} // namespace sfmgen
