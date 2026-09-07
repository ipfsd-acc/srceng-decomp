// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/fileloaderthread.cpp
// Functions: 15
// ============================================================

#include "utils\scenemanager\fileloaderthread.h"

//------------------------------------------------------------------------------
// Address: 0x00405D90
// Name: public: virtual void __near * CFileLoaderThread::GetShutdownHandle(void)
// Source: json
//------------------------------------------------------------------------------
CAppSystemGroup::AppSystemGroupStage_t __thiscall CFileLoaderThread::GetShutdownHandle(CAppSystemGroup *this)
{
  return this->m_nCurrentStage;
}

//------------------------------------------------------------------------------
// Address: 0x00405DA0
// Name: public: virtual void CFileLoaderThread::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::Lock(CFileLoaderThread *this)
{
  EnterCriticalSection(lpCriticalSection: &this->cs);
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x00405DC0
// Name: public: virtual void CFileLoaderThread::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::Unlock(CFileLoaderThread *this)
{
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: &this->cs);
}

//------------------------------------------------------------------------------
// Address: 0x00405DD0
// Name: public: virtual int ThreadIOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::open(ThreadIOReadBinary *this, const char *pFileName)
{
  const char *GameDirectory; // eax
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  GameDirectory = SceneManager_GetGameDirectory();
  V_snprintf(pDest: filename, maxLen: 512, pFormat: "%s%s", GameDirectory, pFileName);
  return _open(path: filename, oflag: 0x8000, pmode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00405E20
// Name: public: virtual int ThreadIOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::read(ThreadIOReadBinary *this, void *pOutput, unsigned int size, int file)
{
  if ( file == -1 )
    return 0;
  else
    return _read(fh: file, buf: pOutput, cnt: size);
}

//------------------------------------------------------------------------------
// Address: 0x00405E50
// Name: public: virtual void ThreadIOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ThreadIOReadBinary::seek(ThreadIOReadBinary *this, int file, int pos)
{
  if ( file != -1 )
    _lseek(fh: file, pos, mthd: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00405E70
// Name: public: virtual unsigned int ThreadIOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadIOReadBinary::tell(ThreadIOReadBinary *this, int file)
{
  if ( file == -1 )
    return 0;
  else
    return _tell(filedes: file);
}

//------------------------------------------------------------------------------
// Address: 0x00405E90
// Name: public: virtual unsigned int ThreadIOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge ThreadIOReadBinary::size@<eax>(ThreadIOReadBinary *this@<ecx>, int a2@<ebx>, int file)
{
  int v5; // ebx
  unsigned int v6; // esi

  if ( file == -1 )
    return 0;
  v5 = ((int (__thiscall *)(ThreadIOReadBinary *, int, int))this->tell)(a1: this, a2: file, a3: a2);
  _lseek(fh: file, pos: 0, mthd: 2);
  v6 = this->tell(this, a2: file);
  _lseek(fh: file, pos: v5, mthd: 0);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: public: virtual void ThreadIOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ThreadIOReadBinary::close(ThreadIOReadBinary *this, int file)
{
  if ( file != -1 )
    _close(fh: file);
}

//------------------------------------------------------------------------------
// Address: 0x00405F00
// Name: public: virtual int CFileLoaderThread::ProcessCompleted(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileLoaderThread::ProcessCompleted(CFileLoaderThread *this)
{
  int m_Size; // esi
  int v3; // eax
  CFileLoaderThread::SentenceRequest *v4; // esi
  int c; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Size = this->m_Completed.m_Size;
  v3 = m_Size - 1;
  c = m_Size;
  i = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v4 = this->m_Completed.m_Memory.m_pMemory[v3];
      CWaveFile::SetThreadLoadedSentence(this: v4->wavefile, sentence: &v4->sentence);
      CSentence::~CSentence(this: &v4->sentence);
      free(pMem: v4);
      if ( --i < 0 )
        break;
      v3 = i;
    }
    m_Size = c;
  }
  this->m_Completed.m_Size = 0;
  this->Unlock(this);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00405F70
// Name: public: virtual CFileLoaderThread::~CFileLoaderThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::~CFileLoaderThread(CFileLoaderThread *this)
{
  _RTL_CRITICAL_SECTION *p_cs; // edi
  void *m_hShutdown; // [esp-4h] [ebp-10h]

  p_cs = &this->cs;
  this->__vftable = (CFileLoaderThread_vtbl *)&CFileLoaderThread::`vftable';
  EnterCriticalSection(lpCriticalSection: &this->cs);
  m_hShutdown = this->m_hShutdown;
  this->m_bLocked = true;
  SetEvent(hEvent: m_hShutdown);
  Sleep(dwMilliseconds: 2u);
  TerminateThread(hThread: this->m_hThread, dwExitCode: 0);
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: p_cs);
  CloseHandle(hObject: this->m_hThread);
  CloseHandle(hObject: this->m_hShutdown);
  DeleteCriticalSection(lpCriticalSection: p_cs);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Completed);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Pending);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileList);
}

//------------------------------------------------------------------------------
// Address: 0x00405FF0
// Name: FileLoaderThreadFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall FileLoaderThreadFunc(void **threadobject)
{
  int v2; // ebx
  void *v4; // eax
  int v5; // eax
  void *v6; // ebx
  int v7; // edx
  _BYTE *v8; // eax
  char *v9; // ecx
  int v10; // eax
  _DWORD *v11; // ebx
  _DWORD *v12; // esi
  void **v13; // ecx
  int v14; // eax
  int m_nAllocationCount; // eax
  int v16; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  CUtlSymbolTable::StringPool_t **v18; // eax
  bool SentenceFromWavFileUsingIO; // al
  bool v20; // zf
  CUtlSymbolTable::StringPool_t *v21; // edx
  void *v22; // ebx
  _BYTE *v23; // eax
  char *v24; // ecx
  int v25; // eax
  CUtlSymbolTable::StringPool_t **v26; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v27; // [esp+8h] [ebp-1Ch] BYREF
  int v28; // [esp+14h] [ebp-10h]
  CUtlSymbolTable::StringPool_t **v29; // [esp+18h] [ebp-Ch]
  _DWORD *v30; // [esp+1Ch] [ebp-8h]
  void *pMem; // [esp+20h] [ebp-4h]
  void *threadobjecta; // [esp+2Ch] [ebp+8h]
  char *threadobjectb; // [esp+2Ch] [ebp+8h]
  void *threadobjectc; // [esp+2Ch] [ebp+8h]

  v2 = 0;
  if ( threadobject != nullptr )
  {
    while ( 1 )
    {
      v4 = (void *)(*((int (__thiscall **)(void **))*threadobject + 6))(a1: threadobject);
      if ( WaitForSingleObject(hHandle: v4, dwMilliseconds: 0) == 0 )
        break;
      (*((void (__thiscall **)(void **))*threadobject + 4))(a1: threadobject);
      v5 = 0;
      pMem = threadobject[10];
      threadobjecta = nullptr;
      if ( (int)pMem > 0 )
      {
        do
        {
          v6 = threadobject[15];
          v7 = (int)threadobject[7] + 4 * v5;
          v8 = threadobject[13];
          v30 = (_DWORD *)v7;
          if ( (int)((char *)v6 + 1) > (int)v8 )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)threadobject + 4,
              num: (_BYTE *)v6 - v8 + 1);
          threadobject[15] = (char *)threadobject[15] + 1;
          v9 = (char *)threadobject[12];
          v10 = (_BYTE *)threadobject[15] - (_BYTE *)v6 - 1;
          threadobject[16] = v9;
          if ( v10 > 0 )
            _V_memmove(dest: &v9[4 * (_DWORD)v6 + 4], src: &v9[4 * (_DWORD)v6], count: 4 * v10);
          v11 = (char *)threadobject[12] + 4 * (_DWORD)v6;
          if ( v11 != nullptr )
            *v11 = *v30;
          threadobject[28] = (char *)threadobject[28] + 1;
          v5 = (int)threadobjecta + 1;
          threadobjecta = (void *)v5;
        }
        while ( v5 < (int)pMem );
        v2 = 0;
      }
      threadobject[10] = nullptr;
      (*((void (__thiscall **)(void **))*threadobject + 5))(a1: threadobject);
      v12 = threadobject[15];
      v30 = v12;
      if ( v12 != nullptr )
      {
        memset(&v27, 0, sizeof(v27));
        v28 = 0;
        v29 = nullptr;
        if ( (int)v12 > 0 )
        {
          pMem = v12;
          do
          {
            v13 = (void **)threadobject[12];
            v14 = (int)threadobject[15] - 1;
            threadobjectb = (char *)*v13;
            if ( v14 > 0 )
              _V_memmove(dest: v13, src: v13 + 1, count: 4 * v14);
            m_nAllocationCount = v27.m_nAllocationCount;
            threadobject[15] = (char *)threadobject[15] - 1;
            v16 = v2;
            if ( v2 + 1 > m_nAllocationCount )
            {
              CUtlMemory<CChoreoActor *,int>::Grow(this: &v27, num: v2 - m_nAllocationCount + 1);
              v2 = v28;
            }
            m_pMemory = v27.m_pMemory;
            v28 = ++v2;
            v29 = v27.m_pMemory;
            if ( v2 - v16 - 1 > 0 )
            {
              _V_memmove(dest: &v27.m_pMemory[v16 + 1], src: &v27.m_pMemory[v16], count: 4 * (v2 - v16 - 1));
              m_pMemory = v27.m_pMemory;
            }
            v18 = &m_pMemory[v16];
            if ( v18 != nullptr )
              *v18 = (CUtlSymbolTable::StringPool_t *)threadobjectb;
            threadobject[29] = (char *)threadobject[29] + 1;
            SentenceFromWavFileUsingIO = SceneManager_LoadSentenceFromWavFileUsingIO(
                                           wavfile: threadobjectb + 1,
                                           sentence: (CSentence *)(threadobjectb + 260),
                                           io: (IFileReadBinary *)threadobject + 25);
            v20 = pMem == (void *)1;
            pMem = (char *)pMem - 1;
            *threadobjectb = SentenceFromWavFileUsingIO;
          }
          while ( !v20 );
          v12 = v30;
        }
        (*((void (__thiscall **)(void **))*threadobject + 4))(a1: threadobject);
        for ( threadobjectc = nullptr; (int)threadobjectc < (int)v12; threadobjectc = (char *)threadobjectc + 1 )
        {
          v21 = v27.m_pMemory[(_DWORD)threadobjectc];
          v20 = LOBYTE(v21->m_TotalLen) == 0;
          pMem = v21;
          if ( v20 )
          {
            CSentence::~CSentence(this: (CSentence *)v21[21].m_Data);
            free(pMem);
          }
          else
          {
            threadobject[30] = (char *)threadobject[30] + 1;
            v22 = threadobject[20];
            v23 = threadobject[18];
            if ( (int)((char *)v22 + 1) > (int)v23 )
            {
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(threadobject + 17),
                num: (_BYTE *)v22 - v23 + 1);
              v21 = (CUtlSymbolTable::StringPool_t *)pMem;
            }
            threadobject[20] = (char *)threadobject[20] + 1;
            v24 = (char *)threadobject[17];
            v25 = (_BYTE *)threadobject[20] - (_BYTE *)v22 - 1;
            threadobject[21] = v24;
            if ( v25 > 0 )
            {
              _V_memmove(dest: &v24[4 * (_DWORD)v22 + 4], src: &v24[4 * (_DWORD)v22], count: 4 * v25);
              v21 = (CUtlSymbolTable::StringPool_t *)pMem;
            }
            v12 = v30;
            v26 = (CUtlSymbolTable::StringPool_t **)((char *)threadobject[17] + 4 * (_DWORD)v22);
            if ( v26 != nullptr )
              *v26 = v21;
          }
        }
        (*((void (__thiscall **)(void **))*threadobject + 5))(a1: threadobject);
        if ( v27.m_nGrowSize >= 0 && v27.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_pMemory);
        v2 = 0;
      }
      Sleep(dwMilliseconds: 0x64u);
    }
    ExitThread(dwExitCode: 0);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004062B0
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
// Address: 0x004062D0
// Name: public: virtual void CFileLoaderThread::AddWaveFilesToThread(class CUtlVector<class CWaveFile __near *,class CUtlMemory<class CWaveFile __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoaderThread::AddWaveFilesToThread(
        CFileLoaderThread *this,
        CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *wavefiles)
{
  CFileLoaderThread::SentenceRequest *v3; // eax
  CFileLoaderThread::SentenceRequest *v4; // edi
  CFileLoaderThread::SentenceRequest *v5; // ebx
  CWaveFile *v6; // ecx
  const char *FileName; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFileLoaderThread::SentenceRequest **m_pMemory; // ecx
  int v11; // eax
  CFileLoaderThread::SentenceRequest **v12; // edi
  int c; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  c = wavefiles->m_Size;
  for ( i = 0; i < c; ++i )
  {
    v3 = (CFileLoaderThread::SentenceRequest *)operator new(nSize: 0x154u);
    v4 = v3;
    if ( v3 != nullptr )
    {
      CSentence::CSentence(this: &v3->sentence);
      v4->filename[0] = 0;
      CSentence::Reset(this: &v4->sentence);
      v4->wavefile = nullptr;
      v4->valid = false;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v6 = wavefiles->m_Memory.m_pMemory[i];
    v5->wavefile = v6;
    FileName = CWaveFile::GetFileName(this: v6);
    V_strncpy(pDest: v5->filename, pSrc: FileName, maxLen: 256);
    m_Size = this->m_FileList.m_Size;
    m_nAllocationCount = this->m_FileList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_FileList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FileList.m_Size;
    m_pMemory = this->m_FileList.m_Memory.m_pMemory;
    v11 = this->m_FileList.m_Size - m_Size - 1;
    this->m_FileList.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_FileList.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = v5;
    ++this->m_nTotalAdds;
  }
  this->Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x004063F0
// Name: public: CFileLoaderThread::CFileLoaderThread(void)
// Source: json
//------------------------------------------------------------------------------
CFileLoaderThread *__thiscall CFileLoaderThread::CFileLoaderThread(CFileLoaderThread *this)
{
  this->__vftable = (CFileLoaderThread_vtbl *)&CFileLoaderThread::`vftable';
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
  this->m_nTotalAdds = 0;
  this->m_nTotalProcessed = 0;
  this->m_nTotalCompleted = 0;
  this->m_nTotalPending = 0;
  this->m_bLocked = false;
  InitializeCriticalSection(lpCriticalSection: &this->cs);
  this->m_hShutdown = CreateEventA(
                        lpEventAttributes: nullptr,
                        bManualReset: true,
                        bInitialState: false,
                        lpName: nullptr);
  this->m_hThread = nullptr;
  this->m_hThread = CreateThread(
                      lpThreadAttributes: nullptr,
                      dwStackSize: 0,
                      lpStartAddress: (LPTHREAD_START_ROUTINE)FileLoaderThreadFunc,
                      lpParameter: this,
                      dwCreationFlags: 0,
                      lpThreadId: &this->m_nThreadId);
  return this;
}
