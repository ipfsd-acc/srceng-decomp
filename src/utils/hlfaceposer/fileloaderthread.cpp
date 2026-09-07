// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/fileloaderthread.cpp
// Functions: 14
// ============================================================

#include "utils\hlfaceposer\fileloaderthread.h"

//------------------------------------------------------------------------------
// Address: 0x004576A0
// Name: public: virtual void __near * CFileLoaderThread::GetShutdownHandle(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileLoaderThread::GetShutdownHandle(CFileLoaderThread *this)
{
  return this->m_hShutdown;
}

//------------------------------------------------------------------------------
// Address: 0x004576B0
// Name: public: virtual int ThreadIOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::open(ThreadIOReadBinary *this, const char *pFileName)
{
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  filesystem->RelativePathToFullPath(
    this: filesystem,
    a2: pFileName,
    a3: "GAME",
    a4: filename,
    a5: 512,
    a6: (PathTypeFilter_t)0,
    a7: nullptr);
  return _open(path: filename, oflag: 0x8000, pmode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00457700
// Name: public: virtual int ThreadIOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::read(ThreadIOReadBinary *this, void *pOutput, unsigned int size, int file)
{
  int result; // eax

  result = file;
  if ( file != 0 )
    return _read(fh: file, buf: pOutput, cnt: size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457730
// Name: public: virtual void ThreadIOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ThreadIOReadBinary::seek(ThreadIOReadBinary *this, int file, int pos)
{
  if ( file != 0 )
    _lseek(fh: file, pos, mthd: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00457750
// Name: public: virtual unsigned int ThreadIOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::tell(ThreadIOReadBinary *this, unsigned int file)
{
  int result; // eax

  result = file;
  if ( file != 0 )
    return _tell(filedes: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457770
// Name: public: virtual unsigned int ThreadIOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge ThreadIOReadBinary::size@<eax>(ThreadIOReadBinary *this@<ecx>, int a2@<ebx>, int file)
{
  int v5; // ebx
  unsigned int v6; // esi

  if ( file == 0 )
    return 0;
  v5 = ((int (__thiscall *)(ThreadIOReadBinary *, int, int))this->tell)(a1: this, a2: file, a3: a2);
  _lseek(fh: file, pos: 0, mthd: 2);
  v6 = this->tell(this, a2: file);
  _lseek(fh: file, pos: v5, mthd: 0);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004577C0
// Name: public: virtual void ThreadIOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ThreadIOReadBinary::close(ThreadIOReadBinary *this, int file)
{
  if ( file != 0 )
    _close(fh: file);
}

//------------------------------------------------------------------------------
// Address: 0x004577E0
// Name: public: virtual int CFileLoaderThread::GetPendingLoadCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileLoaderThread::GetPendingLoadCount(CFileLoaderThread *this)
{
  return this->m_nTotalPending.m_value - this->m_nTotalProcessed.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x004577F0
// Name: public: virtual int CFileLoaderThread::ProcessCompleted(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileLoaderThread::ProcessCompleted(CFileLoaderThread *this)
{
  CFileLoaderThread *v1; // esi
  CThreadFastMutex *p_m_Mutex; // edi
  DWORD CurrentThreadId; // ecx
  int result; // eax
  int v5; // ebx
  CFileLoaderThread::SentenceRequest *v6; // esi
  int c; // [esp+Ch] [ebp-8h]

  v1 = this;
  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  result = v1->m_Completed.m_Size;
  v5 = result - 1;
  c = result;
  if ( result - 1 >= 0 )
  {
    do
    {
      v6 = v1->m_Completed.m_Memory.m_pMemory[v5];
      if ( !CWaveFile::HasLoadedSentenceInfo(this: v6->wavefile) )
        CWaveFile::SetThreadLoadedSentence(this: v6->wavefile, sentence: &v6->sentence);
      CSentence::~CSentence(this: &v6->sentence);
      free(pMem: v6);
      v1 = this;
      --v5;
    }
    while ( v5 >= 0 );
    result = c;
  }
  v1->m_Completed.m_Size = 0;
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004578A0
// Name: public: virtual CFileLoaderThread::~CFileLoaderThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::~CFileLoaderThread(CFileLoaderThread *this)
{
  CThreadFastMutex *p_m_Mutex; // edi
  DWORD CurrentThreadId; // ecx

  this->__vftable = (CFileLoaderThread_vtbl *)&CFileLoaderThread::`vftable';
  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  SetEvent(hEvent: this->m_hShutdown);
  Sleep(dwMilliseconds: 2u);
  TerminateThread(hThread: this->m_hThread, dwExitCode: 0);
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
  CloseHandle(hObject: this->m_hThread);
  CloseHandle(hObject: this->m_hShutdown);
  CloseHandle(hObject: this->m_hNewItems);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Completed);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Pending);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileList);
}

//------------------------------------------------------------------------------
// Address: 0x00457950
// Name: FileLoaderThreadFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall FileLoaderThreadFunc(char *threadobject)
{
  char *v1; // edi
  void *v3; // eax
  DWORD CurrentThreadId; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int *v10; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ebx
  bool v12; // zf
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // edi
  int v17; // esi
  CUtlSymbolTable::StringPool_t **v18; // eax
  CUtlSymbolTable::StringPool_t *v19; // edi
  DWORD v20; // eax
  volatile signed __int32 *v21; // esi
  bool v22; // al
  DWORD v23; // edx
  volatile signed __int32 *v24; // ecx
  int v25; // eax
  CUtlSymbolTable::StringPool_t *v26; // ebx
  int v27; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v28; // esi
  int v29; // edi
  CUtlSymbolTable::StringPool_t **v30; // ecx
  int v31; // eax
  CUtlSymbolTable::StringPool_t **v32; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v33; // [esp+4h] [ebp-20h] BYREF
  int v34; // [esp+10h] [ebp-14h]
  CUtlSymbolTable::StringPool_t **v35; // [esp+14h] [ebp-10h]
  int v36; // [esp+18h] [ebp-Ch]
  CUtlSymbolTable::StringPool_t *v37; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v1 = threadobject;
  if ( threadobject != nullptr )
  {
    while ( 1 )
    {
      v3 = (void *)(*(int (__thiscall **)(char *))(*(_DWORD *)v1 + 20))(a1: v1);
      if ( WaitForSingleObject(hHandle: v3, dwMilliseconds: 0) == 0 )
        ExitThread(dwExitCode: 0);
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != *((_DWORD *)v1 + 1)
        && _InterlockedCompareExchange((volatile signed __int32 *)v1 + 1, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: v1 + 4, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++*((_DWORD *)v1 + 2);
      }
      v5 = 0;
      i = *((_DWORD *)v1 + 6);
      if ( i > 0 )
      {
        do
        {
          v6 = *((_DWORD *)v1 + 11);
          v37 = (CUtlSymbolTable::StringPool_t *)(*((_DWORD *)v1 + 3) + 4 * v5);
          v7 = *((_DWORD *)v1 + 9);
          if ( v6 + 1 > v7 )
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v1 + 32),
              num: v6 - v7 + 1);
          ++*((_DWORD *)v1 + 11);
          v8 = *((_DWORD *)v1 + 8);
          v9 = *((_DWORD *)v1 + 11) - 1;
          *((_DWORD *)v1 + 12) = v8;
          if ( v9 > 0 )
            _V_memmove(dest: (void *)(v8 + 4), src: (const void *)v8, count: 4 * v9);
          v10 = *((int **)v1 + 8);
          if ( v10 != nullptr )
            *v10 = v37->m_TotalLen;
          _InterlockedExchangeAdd((volatile signed __int32 *)v1 + 24, 1u);
          ++v5;
        }
        while ( v5 < i );
      }
      m_pMemory = nullptr;
      *((_DWORD *)v1 + 6) = 0;
      v12 = (*((_DWORD *)v1 + 2))-- == 1;
      if ( v12 )
        _InterlockedExchange((volatile __int32 *)v1 + 1, 0);
      v13 = *((_DWORD *)v1 + 11);
      v36 = v13;
      if ( v13 != 0 )
      {
        v14 = 0;
        memset(&v33, 0, sizeof(v33));
        v34 = 0;
        v35 = nullptr;
        i = 0;
        if ( v13 > 0 )
        {
          while ( 1 )
          {
            v15 = *((_DWORD *)v1 + 11) - 1;
            v37 = **((CUtlSymbolTable::StringPool_t ***)v1 + 8);
            if ( v15 > 0 )
              _V_memmove(dest: *((void **)v1 + 8), src: (const void *)(*((_DWORD *)v1 + 8) + 4), count: 4 * v15);
            --*((_DWORD *)v1 + 11);
            v16 = v14;
            if ( v14 + 1 > v33.m_nAllocationCount )
            {
              CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: &v33, num: v14 - v33.m_nAllocationCount + 1);
              v14 = v34;
              m_pMemory = v33.m_pMemory;
            }
            v34 = v14 + 1;
            v17 = v14 - v16;
            v35 = m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * v17);
            v18 = &m_pMemory[v16];
            v19 = v37;
            if ( v18 != nullptr )
              *v18 = v37;
            _InterlockedExchangeAdd((volatile signed __int32 *)threadobject + 25, 1u);
            v20 = GetCurrentThreadId();
            v21 = (volatile signed __int32 *)(threadobject + 4);
            if ( v20 != *((_DWORD *)threadobject + 1) && _InterlockedCompareExchange(v21, v20, 0) != 0 )
            {
              _mm_pause();
              CThreadFastMutex::Lock(a1: v21, a2: v20, a3: 0);
            }
            else
            {
              ++*((_DWORD *)threadobject + 2);
            }
            v22 = !CWaveFile::HasLoadedSentenceInfo(this: (CWaveFile *)v19[28].m_TotalLen);
            v12 = (*((_DWORD *)threadobject + 2))-- == 1;
            if ( v12 )
              _InterlockedExchange(v21, 0);
            LOBYTE(v19->m_TotalLen) = v22
                                    ? SceneManager_LoadSentenceFromWavFileUsingIO(
                                        wavfile: (const char *)&v19->m_TotalLen + 1,
                                        sentence: (CSentence *)v19[21].m_Data,
                                        io: (IFileReadBinary *)threadobject + 21)
                                    : 1;
            if ( WaitForSingleObject(hHandle: *((HANDLE *)threadobject + 26), dwMilliseconds: 0) == 0 )
              break;
            v1 = threadobject;
            if ( ++i >= v36 )
              goto LABEL_43;
            v14 = v34;
            m_pMemory = v33.m_pMemory;
          }
          ResetEvent(hEvent: *((HANDLE *)threadobject + 26));
          v1 = threadobject;
        }
LABEL_43:
        v23 = GetCurrentThreadId();
        v24 = (volatile signed __int32 *)(v1 + 4);
        if ( v23 != *((_DWORD *)v1 + 1) && _InterlockedCompareExchange(v24, v23, 0) != 0 )
        {
          _mm_pause();
          CThreadFastMutex::Lock(a1: v24, a2: v23, a3: 0);
        }
        else
        {
          ++*((_DWORD *)v1 + 2);
        }
        v25 = 0;
        for ( i = 0; v25 < v34; i = v25 )
        {
          v26 = v33.m_pMemory[v25];
          if ( LOBYTE(v26->m_TotalLen) != 0 )
          {
            ++*((_DWORD *)v1 + 23);
            v27 = *((_DWORD *)v1 + 14);
            v28 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v1 + 52);
            v29 = *((_DWORD *)v1 + 16);
            if ( v29 + 1 > v27 )
              CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: v28, num: v29 - v27 + 1);
            ++v28[1].m_pMemory;
            v30 = v28->m_pMemory;
            v31 = (int)v28[1].m_pMemory - v29 - 1;
            v28[1].m_nAllocationCount = (int)v28->m_pMemory;
            if ( v31 > 0 )
              _V_memmove(dest: &v30[v29 + 1], src: &v30[v29], count: 4 * v31);
            v32 = &v28->m_pMemory[v29];
            v1 = threadobject;
            if ( v32 != nullptr )
              *v32 = v26;
          }
          else
          {
            CSentence::~CSentence(this: (CSentence *)v26[21].m_Data);
            free(pMem: v26);
          }
          v25 = i + 1;
        }
        v12 = (*((_DWORD *)v1 + 2))-- == 1;
        if ( v12 )
          _InterlockedExchange((volatile __int32 *)v1 + 1, 0);
        if ( v33.m_nGrowSize >= 0 && v33.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v33.m_pMemory);
      }
      Sleep(dwMilliseconds: 0xAu);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457CE0
// Name: public: virtual void CFileLoaderThread::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::Start(CFileLoaderThread *this)
{
  this->m_hThread = CreateThread(
                      lpThreadAttributes: nullptr,
                      dwStackSize: 0,
                      lpStartAddress: (LPTHREAD_START_ROUTINE)FileLoaderThreadFunc,
                      lpParameter: this,
                      dwCreationFlags: 0,
                      lpThreadId: &this->m_nThreadId);
}

//------------------------------------------------------------------------------
// Address: 0x00457D00
// Name: public: virtual void CFileLoaderThread::AddWaveFilesToThread(class CUtlVector<class CWaveFile __near *,class CUtlMemory<class CWaveFile __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::AddWaveFilesToThread(
        CFileLoaderThread *this,
        CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *wavefiles)
{
  CThreadFastMutex *p_m_Mutex; // edi
  DWORD CurrentThreadId; // ecx
  CFileLoaderThread::SentenceRequest *v5; // eax
  CFileLoaderThread::SentenceRequest *v6; // edi
  CFileLoaderThread::SentenceRequest *v7; // ebx
  CWaveFile *v8; // ecx
  const char *FileName; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFileLoaderThread::SentenceRequest **m_pMemory; // ecx
  int v13; // eax
  CFileLoaderThread::SentenceRequest **v14; // edi
  CThreadFastMutex *generated_id_5; // [esp+Ch] [ebp-10h]
  int c; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]

  p_m_Mutex = &this->m_Mutex;
  generated_id_5 = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  c = wavefiles->m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      v5 = (CFileLoaderThread::SentenceRequest *)operator new(nSize: 0x154u);
      v6 = v5;
      if ( v5 != nullptr )
      {
        CSentence::CSentence(this: &v5->sentence);
        v6->filename[0] = 0;
        CSentence::Reset(this: &v6->sentence);
        v6->wavefile = nullptr;
        v6->valid = false;
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      v8 = wavefiles->m_Memory.m_pMemory[i];
      v7->wavefile = v8;
      FileName = CWaveFile::GetFileName(this: v8);
      V_strncpy(pDest: v7->filename, pSrc: FileName, maxLen: 256);
      m_Size = this->m_FileList.m_Size;
      m_nAllocationCount = this->m_FileList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_FileList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FileList.m_Size;
      m_pMemory = this->m_FileList.m_Memory.m_pMemory;
      v13 = this->m_FileList.m_Size - m_Size - 1;
      this->m_FileList.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
      v14 = &this->m_FileList.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = v7;
      ++this->m_nTotalAdds;
      ++i;
    }
    while ( i < c );
    p_m_Mutex = generated_id_5;
  }
  SetEvent(hEvent: this->m_hNewItems);
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x00457E60
// Name: public: CFileLoaderThread::CFileLoaderThread(void)
// Source: json
//------------------------------------------------------------------------------
CFileLoaderThread *__thiscall CFileLoaderThread::CFileLoaderThread(CFileLoaderThread *this)
{
  this->__vftable = (CFileLoaderThread_vtbl *)&CFileLoaderThread::`vftable';
  this->m_Mutex.m_ownerID = 0;
  this->m_Mutex.m_depth = 0;
  this->m_FileList.m_Memory.m_pMemory = nullptr;
  this->m_FileList.m_Memory.m_nAllocationCount = 0;
  this->m_FileList.m_Memory.m_nGrowSize = 0;
  this->m_FileList.m_Size = 0;
  this->m_FileList.m_pElements = nullptr;
  this->m_Pending.m_Memory.m_pMemory = nullptr;
  this->m_Pending.m_Memory.m_nAllocationCount = 0;
  this->m_Pending.m_Memory.m_nGrowSize = 0;
  this->m_Pending.m_Size = 0;
  this->m_Pending.m_pElements = nullptr;
  this->m_Completed.m_Memory.m_pMemory = nullptr;
  this->m_Completed.m_Memory.m_nAllocationCount = 0;
  this->m_Completed.m_Memory.m_nGrowSize = 0;
  this->m_Completed.m_Size = 0;
  this->m_Completed.m_pElements = nullptr;
  this->m_ThreadIO.__vftable = (ThreadIOReadBinary_vtbl *)&ThreadIOReadBinary::`vftable';
  this->m_nTotalPending.m_value = 0;
  this->m_nTotalProcessed.m_value = 0;
  this->m_nTotalAdds = 0;
  _InterlockedExchange(&this->m_nTotalProcessed.m_value, 0);
  this->m_nTotalCompleted = 0;
  _InterlockedExchange(&this->m_nTotalPending.m_value, 0);
  this->m_hShutdown = CreateEventA(
                        lpEventAttributes: nullptr,
                        bManualReset: true,
                        bInitialState: false,
                        lpName: nullptr);
  this->m_hThread = nullptr;
  this->m_hNewItems = CreateEventA(
                        lpEventAttributes: nullptr,
                        bManualReset: true,
                        bInitialState: false,
                        lpName: nullptr);
  this->m_hThread = CreateThread(
                      lpThreadAttributes: nullptr,
                      dwStackSize: 0,
                      lpStartAddress: (LPTHREAD_START_ROUTINE)FileLoaderThreadFunc,
                      lpParameter: this,
                      dwCreationFlags: 0,
                      lpThreadId: &this->m_nThreadId);
  return this;
}
