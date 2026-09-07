// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/sync_files.cpp
// Functions: 26
// ============================================================

#include "utils\ps3\vxconsole_ps3\sync_files.h"

//------------------------------------------------------------------------------
// Address: 0x00410C00
// Name: void SyncFilesDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SyncFilesDlg_Open()
{
  int i; // eax

  for ( i = MessageBoxA(
              hWnd: g_hDlgMain,
              lpText: "Sync Files is not yet implemented for PS3.",
              lpCaption: "Missing Feature",
              uType: 2u);
        i == 4;
        i = MessageBoxA(
              hWnd: g_hDlgMain,
              lpText: "Sync Files still isn't implemented for PS3.",
              lpCaption: "Missing Feature",
              uType: 2u) )
  {
    ;
  }
  if ( i == 5 )
    MessageBoxA(
      hWnd: g_hDlgMain,
      lpText: "You can't just ignore this!\nThe feature DOES NOT EXIST.",
      lpCaption: "Missing Feature",
      uType: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x00410C60
// Name: char const __near * V_QualifiedFileName(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl V_QualifiedFileName(const char *in, int numDirs)
{
  const char *result; // eax
  char v4; // cl

  for ( result = &in[strlen(in) - 1]; result > in; --result )
  {
    v4 = *(result - 1);
    if ( v4 == 92 || v4 == 47 )
      --numDirs;
    if ( numDirs < 0 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410CA0
// Name: public: CSHFileOpThread::CSHFileOpThread(struct _SHFILEOPSTRUCTA const __near &)
// Source: json
//------------------------------------------------------------------------------
CSHFileOpThread *__thiscall CSHFileOpThread::CSHFileOpThread(CSHFileOpThread *this, const _SHFILEOPSTRUCTA *fileop)
{
  char *m_szFrom; // eax
  const char *pFrom; // ecx
  const char *pTo; // eax
  const char *lpszProgressTitle; // edi

  CThread::CThread(this);
  this->__vftable = (CSHFileOpThread_vtbl *)&CSHFileOpThread::`vftable';
  this->m_nFileOp.hwnd = fileop->hwnd;
  this->m_nFileOp.wFunc = fileop->wFunc;
  m_szFrom = this->m_szFrom;
  this->m_nFileOp.pFrom = this->m_szFrom;
  this->m_nFileOp.pTo = this->m_szTo;
  this->m_nFileOp.fFlags = fileop->fFlags;
  this->m_nFileOp.fAnyOperationsAborted = fileop->fAnyOperationsAborted;
  this->m_nFileOp.hNameMappings = fileop->hNameMappings;
  this->m_nFileOp.lpszProgressTitle = this->m_szProgressTitle;
  pFrom = fileop->pFrom;
  if ( pFrom != nullptr )
    V_strncpy(pDest: m_szFrom, pSrc: pFrom, maxLen: 260);
  else
    memset(dst: (unsigned __int8 *)m_szFrom, value: 0, count: 0x104u);
  pTo = fileop->pTo;
  if ( pTo != nullptr )
    V_strncpy(pDest: this->m_szTo, pSrc: pTo, maxLen: 260);
  else
    memset(dst: (unsigned __int8 *)this->m_szTo, value: 0, count: sizeof(this->m_szTo));
  lpszProgressTitle = fileop->lpszProgressTitle;
  if ( lpszProgressTitle != nullptr )
    V_strncpy(pDest: this->m_szProgressTitle, pSrc: lpszProgressTitle, maxLen: 260);
  else
    memset(dst: (unsigned __int8 *)this->m_szProgressTitle, value: 0, count: sizeof(this->m_szProgressTitle));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410D70
// Name: protected: virtual int CSHFileOpThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSHFileOpThread::Run(CSHFileOpThread *this)
{
  return SHFileOperationA(lpFileOp: &this->m_nFileOp);
}

//------------------------------------------------------------------------------
// Address: 0x00410D80
// Name: protected: virtual void CSHFileOpThread::OnExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSHFileOpThread::OnExit(CSHFileOpThread *this)
{
  PostMessageA(hWnd: g_hDlgMain, Msg: 0x40Au, wParam: 0, lParam: 0);
  CThread::OnExit(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410DB0
// Name: bool IsADirectoryUploadCurrentlyInProgress(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsADirectoryUploadCurrentlyInProgress()
{
  return g_install_FTP.m_pProgressBar != nullptr || gp_install_CopyToPCThread != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00410DD0
// Name: void HandleCleanupOfGlobalFileUploadThread(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleCleanupOfGlobalFileUploadThread()
{
  char boo[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( gp_install_CopyToPCThread != nullptr )
  {
    CThread::Join(this: gp_install_CopyToPCThread, a2: 0xFFFFFFFF);
    if ( CThread::GetResult(this: gp_install_CopyToPCThread) != 0 )
    {
      V_snprintf(
        pDest: boo,
        maxLen: 1024,
        pFormat: "Copying %s to %s failed.",
        gp_install_CopyToPCThread->m_nFileOp.pFrom,
        gp_install_CopyToPCThread->m_nFileOp.pTo);
      MessageBoxA(hWnd: g_hDlgMain, lpText: boo, lpCaption: "Failure", uType: 0);
    }
    if ( gp_install_CopyToPCThread != nullptr )
      ((void (__thiscall *)(CSHFileOpThread *, int))gp_install_CopyToPCThread->dtr_CThread)(
        a1: gp_install_CopyToPCThread,
        a2: 1);
    gp_install_CopyToPCThread = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410E60
// Name: int SortDVDImages(struct dvdimage_t const __near *,struct dvdimage_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortDVDImages(const dvdimage_t *pA, const dvdimage_t *pB)
{
  char *v2; // esi
  char *v3; // eax
  char szStringB[256]; // [esp+4h] [ebp-200h] BYREF
  char szStringA[256]; // [esp+104h] [ebp-100h] BYREF

  V_strncpy(pDest: szStringA, pSrc: pA->szString, maxLen: 256);
  V_strncpy(pDest: szStringB, pSrc: pB->szString, maxLen: 256);
  v2 = V_stristr(pStr: szStringA, pSearch: " (");
  v3 = V_stristr(pStr: szStringB, pSearch: " (");
  if ( v2 != nullptr )
    *v2 = 0;
  if ( v3 != nullptr )
    *v3 = 0;
  return _V_stricmp(s1: szStringB, s2: szStringA);
}

//------------------------------------------------------------------------------
// Address: 0x00411030
// Name: private: void CVXPS3DirectoryUploadState::OnUploadComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVXPS3DirectoryUploadState::OnUploadComplete(CVXPS3DirectoryUploadState *this)
{
  CProgress *m_pProgressBar; // edi

  if ( this->m_nNumFailures != 0 )
    ConsoleWindowPrintf(
      rgb: 0xFFu,
      strFormat: "UPLOAD ERROR: %d files failed, see target manager for details.\n",
      this->m_nNumFailures);
  SNPS3CancelFTPEvents();
  m_pProgressBar = this->m_pProgressBar;
  if ( this->m_pProgressBar != nullptr )
  {
    CProgress::~CProgress(this: this->m_pProgressBar);
    free(pMem: m_pProgressBar);
  }
  this->m_pProgressBar = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004110B0
// Name: void AbandonImageInstallationDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AbandonImageInstallationDialog()
{
  CProgress *m_pProgressBar; // esi

  if ( g_install_FTP.m_nNumFailures != 0 )
    ConsoleWindowPrintf(
      rgb: 0xFFu,
      strFormat: "UPLOAD ERROR: %d files failed, see target manager for details.\n",
      g_install_FTP.m_nNumFailures);
  SNPS3CancelFTPEvents();
  m_pProgressBar = g_install_FTP.m_pProgressBar;
  if ( g_install_FTP.m_pProgressBar != nullptr )
  {
    CProgress::~CProgress(this: g_install_FTP.m_pProgressBar);
    free(pMem: m_pProgressBar);
  }
  g_install_FTP.m_pProgressBar = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00411110
// Name: bool InstallDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InstallDlg_GetChanges(HWND__ *hWnd)
{
  WPARAM v1; // esi
  HWND DlgItem; // eax

  g_install_bForceSync = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1083) != 0;
  g_install_bCleanTarget = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1091) != 0;
  g_install_bCopyToPC = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1093) != 0;
  v1 = 0;
  g_install_bCopyToPS3 = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1094) != 0;
  g_install_Selection = -1;
  if ( g_install_dvdImages.m_Size > 0 )
  {
    while ( 1 )
    {
      DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
      if ( SendMessageA(hWnd: DlgItem, Msg: 0x102Cu, wParam: v1, lParam: 3) == 3 )
        break;
      if ( (int)++v1 >= g_install_dvdImages.m_Size )
        return 1;
    }
    g_install_Selection = v1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004112E0
// Name: public: dvdimage_t::~dvdimage_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall dvdimage_t::~dvdimage_t(dvdimage_t *this)
{
  this->notesString.m_Storage.m_nActualLength = 0;
  if ( this->notesString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->notesString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->notesString.m_Storage.m_Memory.m_pMemory);
      this->notesString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->notesString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->versionDetailString.m_Storage.m_nActualLength = 0;
  if ( this->versionDetailString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->versionDetailString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->versionDetailString.m_Storage.m_Memory.m_pMemory);
      this->versionDetailString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->versionDetailString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->installPath.m_Storage.m_nActualLength = 0;
  if ( this->installPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->installPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->installPath.m_Storage.m_Memory.m_pMemory);
      this->installPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->installPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411390
// Name: struct dvdimage_t __near * CopyConstruct<struct dvdimage_t>(struct dvdimage_t __near *,struct dvdimage_t const __near &)
// Source: json
//------------------------------------------------------------------------------
dvdimage_t *__cdecl CopyConstruct<dvdimage_t>(dvdimage_t *pMemory, const dvdimage_t *src)
{
  if ( pMemory == nullptr )
    return nullptr;
  qmemcpy(pMemory, src, 0x104u);
  CUtlString::CUtlString(this: &pMemory->installPath, string: &src->installPath);
  CUtlString::CUtlString(this: &pMemory->versionDetailString, string: &src->versionDetailString);
  CUtlString::CUtlString(this: &pMemory->notesString, string: &src->notesString);
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x004114F0
// Name: private: int CVXPS3DirectoryUploadState::RecomputeProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVXPS3DirectoryUploadState::RecomputeProgressBar(CVXPS3DirectoryUploadState *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  SNPS3Transfer *m_pMemory; // edi
  const char *v5; // esi
  unsigned int v6; // ebx
  unsigned __int64 *p_Size; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // kr00_4
  unsigned int v11; // edx
  int v12; // esi
  unsigned __int64 v13; // kr08_8
  int v14; // esi
  unsigned int v15; // edx
  const char *v16; // eax
  unsigned int v17; // esi
  char szStatus2[256]; // [esp+Ch] [ebp-238h] BYREF
  char szStatus3[256]; // [esp+10Ch] [ebp-138h] BYREF
  CUtlVector<SNPS3Transfer,CUtlMemory<SNPS3Transfer,int> > transferlist; // [esp+20Ch] [ebp-38h] BYREF
  unsigned int i; // [esp+220h] [ebp-24h]
  const char *szLastFilenameInProgress; // [esp+224h] [ebp-20h]
  unsigned __int64 nTotalBytes; // [esp+228h] [ebp-1Ch]
  int nTransferredFiles; // [esp+230h] [ebp-14h]
  CVXPS3DirectoryUploadState *v25; // [esp+234h] [ebp-10h]
  unsigned __int64 nTransferredBytes; // [esp+238h] [ebp-Ch]
  unsigned int filecount; // [esp+240h] [ebp-4h] BYREF

  filecount = 0x4000;
  transferlist.m_Memory.m_nAllocationCount = 0x4000;
  transferlist.m_Memory.m_nGrowSize = 0x4000;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v25 = this;
  transferlist.m_Memory.m_pMemory = (SNPS3Transfer *)Alloc_2(this: _g_pMemAlloc, a2: 22020096u);
  transferlist.m_Size = 0;
  transferlist.m_pElements = transferlist.m_Memory.m_pMemory;
  CUtlVector<SNPS3Transfer,CUtlMemory<SNPS3Transfer,int>>::InsertMultipleBefore(
    this: &transferlist,
    elem: 0,
    num: 0x4000);
  m_pMemory = transferlist.m_Memory.m_pMemory;
  if ( SNPS3GetFileTransferList(
         a1: g_PS3CurrentTargetConn.m_nSNHandle,
         a2: (int)&filecount,
         a3: (int)transferlist.m_Memory.m_pMemory) >= 0 )
  {
    if ( filecount != 0 )
    {
      CProgress::HideMeter(this: this->m_pProgressBar, bHide: false);
      v5 = nullptr;
      nTotalBytes = 0;
      nTransferredFiles = 0;
      v6 = 0;
      szLastFilenameInProgress = nullptr;
      nTransferredBytes = 0;
      if ( filecount != 0 )
      {
        p_Size = &m_pMemory->Size;
        v8 = HIDWORD(nTransferredBytes);
        for ( i = filecount; i != 0; --i )
        {
          v9 = *(_DWORD *)p_Size;
          v10 = nTotalBytes;
          LODWORD(nTotalBytes) = *(_DWORD *)p_Size + nTotalBytes;
          v11 = *((_DWORD *)p_Size + 1);
          v12 = *((_DWORD *)p_Size - 331);
          v13 = *p_Size + __PAIR64__(v6, v10);
          v6 = HIDWORD(v13);
          LODWORD(nTotalBytes) = v13;
          v14 = v12 - 1;
          if ( v14 != 0 )
          {
            if ( v14 == 15 )
            {
              v15 = *((_DWORD *)p_Size + 2);
              szLastFilenameInProgress = (const char *)(p_Size - 165);
              v8 = (__PAIR64__(v8, v15) + __PAIR64__(*((_DWORD *)p_Size + 3), nTransferredBytes)) >> 32;
              LODWORD(nTransferredBytes) = v15 + nTransferredBytes;
            }
            else
            {
              v8 = (__PAIR64__(v11, v9) + __PAIR64__(v8, nTransferredBytes)) >> 32;
              LODWORD(nTransferredBytes) = v9 + nTransferredBytes;
              ++nTransferredFiles;
            }
          }
          p_Size += 168;
        }
        v5 = szLastFilenameInProgress;
      }
      else
      {
        v8 = HIDWORD(nTransferredBytes);
      }
      memset(szStatus3, 0, sizeof(szStatus3));
      V_snprintf(
        pDest: szStatus2,
        maxLen: 256,
        pFormat: "%d / %d uploaded  (%I64u/%I64u mb)",
        nTransferredFiles,
        filecount,
        __PAIR64__(v8, nTransferredBytes) >> 20,
        __PAIR64__(v6, nTotalBytes) >> 20);
      if ( v5 != nullptr )
      {
        v16 = V_QualifiedFileName(in: v5, numDirs: 1);
        V_snprintf(pDest: szStatus3, maxLen: 256, pFormat: "Currently: %s", v16);
      }
      if ( v6 != 0 || (unsigned int)nTotalBytes > 0x7FFF )
        CProgress::SetMeter(
          this: v25->m_pProgressBar,
          currentPos: __PAIR64__(v8, nTransferredBytes) >> 12,
          range: __PAIR64__(v6, nTotalBytes) >> 12);
      else
        CProgress::SetMeter(this: v25->m_pProgressBar, currentPos: nTransferredBytes, range: nTotalBytes);
      CProgress::SetStatus(
        this: v25->m_pProgressBar,
        line1: nullptr,
        line2: szStatus2,
        line3: v5 != nullptr ? szStatus3 : nullptr);
      m_pMemory = transferlist.m_Memory.m_pMemory;
    }
    v17 = filecount;
    if ( transferlist.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v17;
  }
  else
  {
    CProgress::HideMeter(this: this->m_pProgressBar, bHide: true);
    V_snprintf(pDest: szStatus3, maxLen: 256, pFormat: "A bug in the target manager broke my progress bar.");
    CProgress::SetStatus(this: this->m_pProgressBar, line1: nullptr, line2: szStatus3, line3: nullptr);
    CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&transferlist);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411740
// Name: private: void CVXPS3DirectoryUploadState::OnFTPEvent(int,unsigned int,unsigned int,long,unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVXPS3DirectoryUploadState::OnFTPEvent(
        CVXPS3DirectoryUploadState *this,
        int target,
        unsigned int eventType,
        unsigned int eventParam,
        int resultcode,
        unsigned int datalength,
        unsigned __int8 *eventData)
{
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // eax
  int v10; // ebx
  CProgress *m_pProgressBar; // esi
  signed int v12; // eax
  CProgress *v13; // esi
  char szStatus3[256]; // [esp+4h] [ebp-100h] BYREF
  unsigned __int8 *sentinel; // [esp+120h] [ebp+1Ch]

  if ( eventType == 103 )
  {
    v8 = eventData;
    v9 = &eventData[datalength];
    v10 = 0;
    sentinel = v9;
    if ( v8 < v9 )
    {
      do
      {
        if ( *(_DWORD *)v8 == 4 )
          ++this->m_nNumFailures;
        if ( g_install_bForceSync && *(_DWORD *)v8 == 2 )
        {
          SNPS3RetryFileTransfer();
          v9 = sentinel;
        }
        else if ( *(_DWORD *)v8 != 0 && *((_DWORD *)v8 + 1) == this->m_nLastFileID )
        {
          HIBYTE(eventType) = 1;
        }
        v10 = *((_DWORD *)v8 + 1);
        v8 += 16;
      }
      while ( v8 < v9 );
      if ( HIBYTE(eventType) != 0 )
      {
        if ( this->m_nNumFailures != 0 )
          ConsoleWindowPrintf(
            rgb: 0xFFu,
            strFormat: "UPLOAD ERROR: %d files failed, see target manager for details.\n",
            this->m_nNumFailures);
        SNPS3CancelFTPEvents();
        m_pProgressBar = this->m_pProgressBar;
        if ( this->m_pProgressBar != nullptr )
        {
          CProgress::~CProgress(this: this->m_pProgressBar);
          free(pMem: m_pProgressBar);
          this->m_pProgressBar = nullptr;
          return;
        }
        goto LABEL_22;
      }
    }
    v12 = CVXPS3DirectoryUploadState::RecomputeProgressBar(this);
    if ( this->m_pProgressBar == nullptr )
    {
      if ( this->m_nNumFailures != 0 )
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "UPLOAD ERROR: %d files failed, see target manager for details.\n",
          this->m_nNumFailures);
      SNPS3CancelFTPEvents();
      v13 = this->m_pProgressBar;
      if ( this->m_pProgressBar != nullptr )
      {
        CProgress::~CProgress(this: this->m_pProgressBar);
        free(pMem: v13);
      }
LABEL_22:
      this->m_pProgressBar = nullptr;
      return;
    }
    if ( v12 >= 0 )
    {
      if ( v12 == 0 )
        CVXPS3DirectoryUploadState::OnUploadComplete(this);
    }
    else
    {
      V_snprintf(
        pDest: szStatus3,
        maxLen: 256,
        pFormat: "Approximately %d files remaining.",
        this->m_nLastFileID - v10 + 1);
      CProgress::SetStatus(this: this->m_pProgressBar, line1: nullptr, line2: nullptr, line3: szStatus3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411AE0
// Name: private: static void CVXPS3DirectoryUploadState::TargetEventCallback(int,unsigned int,unsigned int,long,unsigned int,unsigned char __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CVXPS3DirectoryUploadState::TargetEventCallback(
        int target,
        unsigned int eventType,
        unsigned int eventParam,
        int resultcode,
        unsigned int datalength,
        unsigned __int8 *eventData,
        CVXPS3DirectoryUploadState *pUserData)
{
  CVXPS3DirectoryUploadState::OnFTPEvent(
    this: pUserData,
    target,
    eventType,
    eventParam,
    resultcode,
    datalength,
    eventData);
}

//------------------------------------------------------------------------------
// Address: 0x00411B10
// Name: public: long CVXPS3DirectoryUploadState::UploadDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CVXPS3DirectoryUploadState::UploadDirectory(
        CVXPS3DirectoryUploadState *this,
        const char *pSourcePath,
        const char *pDestPath)
{
  HRESULT v5; // eax
  HRESULT v6; // edi
  const char *v7; // ebx
  int v8; // eax
  int v9; // edi
  CProgress *v10; // eax
  CProgress *v11; // eax
  char szStatus1[160]; // [esp+4h] [ebp-A0h] BYREF

  if ( this->m_pProgressBar != nullptr )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "\nERROR: tried to initiate two simultaneous game uploads\n");
    return 0x80000000;
  }
  else
  {
    v5 = SNPS3RegisterFTPEventHandler();
    v6 = v5;
    if ( v5 >= 0 )
    {
      v7 = pSourcePath;
      this->m_nNumFailures = 0;
      v8 = SNPS3UploadDirectory();
      v9 = v8;
      if ( v8 >= 0 )
      {
        v10 = (CProgress *)operator new(nSize: 0x28u);
        if ( v10 != nullptr )
          v11 = CProgress::CProgress(this: v10);
        else
          v11 = nullptr;
        this->m_pProgressBar = v11;
        memset(szStatus1, 0, sizeof(szStatus1));
        V_snprintf(pDest: szStatus1, maxLen: 159, pFormat: "Uploading %s", v7);
        CProgress::Open(this: this->m_pProgressBar, title: "Uploading Directory", canCancel: false, bHasMeter: true);
        CProgress::SetStatus(this: this->m_pProgressBar, line1: szStatus1, line2: &str, line3: &str);
        if ( this->m_pProgressBar != nullptr )
        {
          CProgress::HideMeter(this: this->m_pProgressBar, bHide: true);
          return 0;
        }
        else
        {
          return 0x80000000;
        }
      }
      else
      {
        pSourcePath = "?";
        SNPS3TranslateError(a1: v8, a2: (int)&pSourcePath);
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "Could not upload %s to %s: %s\n",
          v7,
          pDestPath,
          (const char *)&pSourcePath);
        return v9;
      }
    }
    else
    {
      DmAPI_DisplayError(message: "Could not register FTP event handler. ", hr: v5);
      return v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411C70
// Name: void InstallDlg_InstallImage(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_InstallImage(const char *pInstallPath)
{
  HWND__ *v1; // edx
  CSHFileOpThread *v2; // eax
  CSHFileOpThread *v3; // eax
  HRESULT v4; // eax
  char szSourcePath[260]; // [esp+0h] [ebp-124h] BYREF
  _SHFILEOPSTRUCTA fileop; // [esp+104h] [ebp-20h] BYREF

  if ( g_install_bCopyToPC || g_install_bCopyToPS3 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "\nSyncing From Install Depot: %s\n", pInstallPath);
    if ( g_install_bCopyToPC && gp_install_CopyToPCThread == nullptr )
    {
      if ( g_targetPath[0] != 0 )
      {
        V_snprintf(pDest: szSourcePath, maxLen: 260, pFormat: "%s\\*.*%c", pInstallPath, 0);
        v1 = g_hDlgMain;
        g_targetPath[strlen(g_targetPath) + 1] = 0;
        fileop.hwnd = v1;
        fileop.wFunc = 2;
        fileop.pFrom = szSourcePath;
        fileop.pTo = g_targetPath;
        fileop.fFlags = 784;
        fileop.lpszProgressTitle = "Copying image...";
        v2 = (CSHFileOpThread *)operator new(nSize: 0x394u);
        if ( v2 != nullptr )
          v3 = CSHFileOpThread::CSHFileOpThread(this: v2, &fileop);
        else
          v3 = nullptr;
        gp_install_CopyToPCThread = v3;
        CThread::SetName(this: v3, a2: "CopyPS3bdvd");
        gp_install_CopyToPCThread->Start(this: gp_install_CopyToPCThread, a2: 0, a3: PRIORITY_DEFAULT);
      }
      else
      {
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Please set a destination directory in the Config dialog.");
      }
    }
    if ( g_install_bCopyToPS3 )
    {
      V_ComposeFileName(path: pInstallPath, filename: "PS3_GAME/USRDIR", dest: szSourcePath, destSize: 260);
      v4 = CVXPS3DirectoryUploadState::UploadDirectory(
             this: &g_install_FTP,
             pSourcePath: szSourcePath,
             pDestPath: "/dev_hdd0/game/PORT00002");
      ConsoleWindowPrintf(rgb: 0, strFormat: "\nresult: %d\n", v4);
    }
  }
  else
  {
    MessageBoxA(
      hWnd: g_install_dlg_hwnd,
      lpText: "Both the \"copy to PC\" and the \"copy to PS3\" boxes were unchecked.\n"
      "Where the heck do you expect me to put the image?\n"
      "At least one of these has to be selected.",
      lpCaption: "User Failure",
      uType: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411DF0
// Name: void InstallDlg_Populate(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Populate(HWND__ *hWnd)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  HANDLE FirstFileA; // esi
  int v3; // ebx
  int v4; // edi
  _WIN32_FIND_DATAA *m_pMemory; // ecx
  int m_Size; // ebx
  int v7; // ebx
  int v8; // eax
  char *cFileName; // esi
  char *v10; // eax
  char *v11; // edi
  char v12; // al
  char *v13; // edi
  char *v14; // eax
  int v15; // ebx
  char *v16; // esi
  int v17; // eax
  int v18; // esi
  bool v19; // zf
  char szPath[260]; // [esp+Ch] [ebp-A70h] BYREF
  char szVersionPath[260]; // [esp+110h] [ebp-96Ch] BYREF
  char szNotesPath[260]; // [esp+214h] [ebp-868h] BYREF
  char szEbootBinPath[260]; // [esp+318h] [ebp-764h] BYREF
  char szNotes[256]; // [esp+41Ch] [ebp-660h] BYREF
  char szCommentBuff[128]; // [esp+51Ch] [ebp-560h] BYREF
  char szInstallPath[260]; // [esp+59Ch] [ebp-4E0h] BYREF
  char szToken[256]; // [esp+6A0h] [ebp-3DCh] BYREF
  dvdimage_t image; // [esp+7A0h] [ebp-2DCh] BYREF
  char timeOfDay[256]; // [esp+8D4h] [ebp-1A8h] BYREF
  tagLVITEMA _macro_lvi; // [esp+9D4h] [ebp-A8h] BYREF
  CProgress progress; // [esp+A10h] [ebp-6Ch] BYREF
  int v32; // [esp+A38h] [ebp-44h]
  int c; // [esp+A3Ch] [ebp-40h]
  int month; // [esp+A40h] [ebp-3Ch] BYREF
  int year; // [esp+A44h] [ebp-38h] BYREF
  int minute; // [esp+A48h] [ebp-34h] BYREF
  HWND__ *hWndListView; // [esp+A4Ch] [ebp-30h]
  int day; // [esp+A50h] [ebp-2Ch] BYREF
  int whichdata; // [esp+A54h] [ebp-28h]
  char *pNotesString; // [esp+A58h] [ebp-24h] BYREF
  char *v41; // [esp+A5Ch] [ebp-20h]
  CUtlVector<_WIN32_FIND_DATAA,CUtlMemory<_WIN32_FIND_DATAA,int> > vFindDatas; // [esp+A60h] [ebp-1Ch] BYREF
  char *pVersionDetailString; // [esp+A74h] [ebp-8h] BYREF
  int hour; // [esp+A78h] [ebp-4h] BYREF

  hWndListView = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
  SendMessageA(hWnd: hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
  V_ComposeFileName(path: g_installPath, filename: "DVD_*", dest: szPath, destSize: 260);
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  vFindDatas.m_Memory.m_nAllocationCount = 128;
  vFindDatas.m_Memory.m_nGrowSize = 0;
  vFindDatas.m_Memory.m_pMemory = (_WIN32_FIND_DATAA *)Alloc_2(this: _g_pMemAlloc, a2: 40960u);
  vFindDatas.m_Size = 0;
  vFindDatas.m_pElements = vFindDatas.m_Memory.m_pMemory;
  CUtlVector<_WIN32_FIND_DATAA,CUtlMemory<_WIN32_FIND_DATAA,int>>::InsertMultipleBefore(
    this: &vFindDatas,
    elem: 0,
    num: 1);
  FirstFileA = FindFirstFileA(lpFileName: szPath, lpFindFileData: vFindDatas.m_Memory.m_pMemory);
  if ( FirstFileA == (HANDLE)-1 )
  {
    m_Size = vFindDatas.m_Size;
  }
  else
  {
    do
    {
      v3 = vFindDatas.m_Size;
      v4 = vFindDatas.m_Size;
      if ( vFindDatas.m_Size + 1 > vFindDatas.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<_WIN32_FIND_DATAA,int>::Grow(
          this: &vFindDatas.m_Memory,
          num: vFindDatas.m_Size - vFindDatas.m_Memory.m_nAllocationCount + 1);
        v3 = vFindDatas.m_Size;
      }
      m_pMemory = vFindDatas.m_Memory.m_pMemory;
      m_Size = v3 + 1;
      vFindDatas.m_Size = m_Size;
      vFindDatas.m_pElements = vFindDatas.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
      {
        _V_memmove(
          dest: &vFindDatas.m_Memory.m_pMemory[v4 + 1],
          src: &vFindDatas.m_Memory.m_pMemory[v4],
          count: 320 * (m_Size - v4 - 1));
        m_pMemory = vFindDatas.m_Memory.m_pMemory;
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &m_pMemory[m_Size - 1]) );
    FindClose(hFindFile: FirstFileA);
  }
  v7 = m_Size - 1;
  vFindDatas.m_Size = v7;
  CProgress::CProgress(this: &progress);
  CProgress::SetStatus(this: &progress, line1: "Searching fileserver for images", line2: nullptr, line3: nullptr);
  CProgress::SetMeter(this: &progress, currentPos: 0, range: v7);
  v8 = rand() % 16;
  CProgress::Open(this: &progress, title: szSynonymsForSearching[v8], canCancel: true, bHasMeter: true);
  whichdata = 0;
  if ( v7 > 0 )
  {
    cFileName = vFindDatas.m_Memory.m_pMemory->cFileName;
    v41 = vFindDatas.m_Memory.m_pMemory->cFileName;
    do
    {
      CProgress::SetStatus(this: &progress, line1: "Searching fileserver for images", line2: nullptr, line3: cFileName);
      if ( _V_stricmp(s1: cFileName, s2: ".") == 0 )
        goto LABEL_55;
      if ( _V_stricmp(s1: cFileName, s2: "..") == 0 )
        goto LABEL_55;
      if ( (*(cFileName - 44) & 0x10) == 0 )
        goto LABEL_55;
      V_strncpy(pDest: szInstallPath, pSrc: g_installPath, maxLen: 260);
      V_AppendSlash(pStr: szInstallPath, strSize: 260);
      V_strncat(pDest: szInstallPath, pSrc: cFileName, destBufferSize: 0x104u, max_chars_to_copy: -1);
      V_ComposeFileName(path: szInstallPath, filename: "PS3_GAME/USRDIR/EBOOT.BIN", dest: szEbootBinPath, destSize: 260);
      if ( Sys_Exists(filename: szEbootBinPath) == 0 )
        goto LABEL_55;
      V_ComposeFileName(path: szInstallPath, filename: "version.txt", dest: szVersionPath, destSize: 260);
      pVersionDetailString = nullptr;
      if ( Sys_LoadFile(filename: szVersionPath, bufferptr: (void **)&pVersionDetailString, bText: false) == -1 )
      {
        pVersionDetailString = (char *)operator new(nSize: 0x40u);
        strncpy(dest: (unsigned __int8 *)pVersionDetailString, source: "<MISSING VERSION INFO>", count: 0x3Fu);
      }
      v10 = V_stristr(pStr: pVersionDetailString, pSearch: "\r\n");
      if ( v10 != nullptr )
        *v10 = 0;
      szNotes[0] = 0;
      V_ComposeFileName(path: szInstallPath, filename: "notes.txt", dest: szNotesPath, destSize: 260);
      pNotesString = nullptr;
      if ( Sys_LoadFile(filename: szNotesPath, bufferptr: (void **)&pNotesString, bText: false) != -1
        && pNotesString != nullptr )
      {
        v11 = pNotesString;
        while ( 1 )
        {
          v12 = *v11;
          if ( *v11 == 0 )
            break;
          while ( isprint(c: v12) == 0 )
          {
            v12 = *++v11;
            if ( v12 == 0 )
              goto LABEL_25;
          }
          if ( *v11 == 0 )
            break;
          v14 = V_stristr(pStr: v11, pSearch: "\r\n");
          if ( v14 != nullptr )
          {
            v15 = v14 - v11;
            if ( (unsigned int)(v14 - v11) >= 0xFF )
              v15 = 255;
            _V_memcpy(dest: szToken, src: v11, count: v15);
            szToken[v15] = 0;
            if ( v15 > 0 )
            {
              v16 = &szInstallPath[v15 + 259];
              v32 = 1 - (_DWORD)szToken;
              do
              {
                c = *v16;
                if ( isprint(c) != 0 && isspace(c) == 0 )
                  break;
                v17 = v32;
                *v16-- = 0;
              }
              while ( (int)&v16[v17] > 0 );
              cFileName = v41;
            }
          }
          else
          {
            V_strncpy(pDest: szToken, pSrc: v11, maxLen: 256);
            v15 = strlen(v11);
          }
          v11 += v15;
          Sys_StripQuotesFromToken(pToken: szToken);
          if ( szNotes[0] != 0 && szToken[0] != 0 )
            V_strncat(pDest: szNotes, pSrc: ", ", destBufferSize: 0x100u, max_chars_to_copy: -1);
          V_strncat(pDest: szNotes, pSrc: szToken, destBufferSize: 0x100u, max_chars_to_copy: -1);
          v7 = vFindDatas.m_Size;
        }
LABEL_25:
        Sys_Free(ptr: pNotesString);
      }
      CUtlString::CUtlString(this: &image.installPath);
      CUtlString::CUtlString(this: &image.versionDetailString);
      CUtlString::CUtlString(this: &image.notesString);
      year = 0;
      month = 0;
      day = 0;
      hour = 0;
      minute = 0;
      memset(timeOfDay, 0, sizeof(timeOfDay));
      sscanf(string: cFileName, format: "DVD_%d_%d_%d_%d_%d_%s", &year, &month, &day, &hour, &minute, timeOfDay);
      v13 = timeOfDay;
      if ( timeOfDay[0] != 0 )
      {
        if ( V_strnicmp(s1: timeOfDay, s2: "PM", n: 2) == 0 )
        {
          if ( hour != 12 )
            hour += 12;
LABEL_49:
          v13 = &timeOfDay[2];
          goto LABEL_50;
        }
        if ( timeOfDay[0] != 0 && V_strnicmp(s1: timeOfDay, s2: "AM", n: 2) == 0 )
        {
          if ( hour == 12 )
            hour = 0;
          goto LABEL_49;
        }
      }
LABEL_50:
      if ( *v13 == 95 )
        V_snprintf(pDest: szCommentBuff, maxLen: 128, pFormat: " (%s)", v13 + 1);
      else
        szCommentBuff[0] = 0;
      V_snprintf(
        pDest: image.szString,
        maxLen: 260,
        pFormat: "%2.2d/%2.2d/%4.4d %2.2d:%2.2d%s",
        month,
        day,
        year,
        hour,
        minute,
        szCommentBuff);
      CUtlString::operator=(this: &image.installPath, src: szInstallPath);
      CUtlString::operator=(this: &image.versionDetailString, src: pVersionDetailString);
      CUtlString::operator=(this: &image.notesString, src: szNotes);
      CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::InsertBefore(
        this: &g_install_dvdImages,
        elem: g_install_dvdImages.m_Size,
        src: &image);
      Sys_Free(ptr: pVersionDetailString);
      CProgress::SetMeter(this: &progress, currentPos: whichdata, range: v7);
      if ( CProgress::IsCancel(this: &progress) )
      {
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::RemoveAll(this: &g_install_dvdImages);
        PostMessageA(hWnd: g_install_dlg_hwnd, Msg: 0x111u, wParam: 2u, lParam: 0);
        dvdimage_t::~dvdimage_t(this: &image);
        CProgress::~CProgress(this: &progress);
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&vFindDatas);
        return;
      }
      dvdimage_t::~dvdimage_t(this: &image);
LABEL_55:
      cFileName += 320;
      ++whichdata;
      v41 = cFileName;
    }
    while ( whichdata < v7 );
  }
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Sort(
    this: &g_install_dvdImages,
    pfnCompare: (int (__cdecl *)(const void *, const void *))SortDVDImages);
  v18 = 0;
  v19 = g_install_dvdImages.m_Size == 0;
  if ( g_install_dvdImages.m_Size > 0 )
  {
    do
    {
      memset(dst: (unsigned __int8 *)&_macro_lvi, value: 0, count: sizeof(_macro_lvi));
      _macro_lvi.mask = 13;
      _macro_lvi.iItem = v18;
      memset(&_macro_lvi.iSubItem, 0, 12);
      _macro_lvi.pszText = (char *)-1;
      _macro_lvi.lParam = v18;
      SendMessageA(hWnd: hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&_macro_lvi);
      ++v18;
    }
    while ( v18 < g_install_dvdImages.m_Size );
    v19 = g_install_dvdImages.m_Size == 0;
  }
  if ( !v19 )
  {
    _macro_lvi.stateMask = 3;
    _macro_lvi.state = 3;
    SendMessageA(hWnd: hWndListView, Msg: 0x102Bu, wParam: 0, lParam: (LPARAM)&_macro_lvi);
  }
  CProgress::~CProgress(this: &progress);
  if ( vFindDatas.m_Memory.m_nGrowSize >= 0 && vFindDatas.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vFindDatas.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00412520
// Name: void InstallDlg_Setup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Setup(HWND__ *hWnd)
{
  HWND DlgItem; // esi
  tagLVCOLUMNA lvc; // [esp+Ch] [ebp-2Ch] BYREF

  g_install_Selection = -1;
  g_install_bForceSync = false;
  g_install_bCleanTarget = false;
  g_install_dlg_hwnd = hWnd;
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
  memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.mask = 15;
  lvc.cx = 200;
  lvc.pszText = "Date Built:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 0, lParam: (LPARAM)&lvc);
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.cx = 250;
  lvc.pszText = "Notes:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 1u, lParam: (LPARAM)&lvc);
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.cx = 500;
  lvc.pszText = "Perforce Changelist:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 2u, lParam: (LPARAM)&lvc);
  SendMessageA(hWnd: DlgItem, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
  SendMessageA(hWnd: DlgItem, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
  SendMessageA(hWnd: DlgItem, Msg: 0x1036u, wParam: 0x21u, lParam: 33);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1093, uCheck: g_install_bCopyToPC);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1094, uCheck: g_install_bCopyToPS3);
  InstallDlg_Populate(hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x00412650
// Name: int InstallDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall InstallDlg_Proc(HWND__ *hWnd, unsigned int message, INT_PTR wParam, _DWORD *lParam)
{
  int v5; // ecx
  int v6; // eax
  int v7; // ecx

  if ( message != 78 )
  {
    if ( message == 272 )
    {
      InstallDlg_Setup(hWnd);
      return 1;
    }
    if ( message == 273 )
    {
      if ( (unsigned __int16)wParam > 0x3FCu )
      {
        if ( (unsigned __int16)wParam == 1089 )
        {
          InstallDlg_Populate(hWnd);
          return 1;
        }
      }
      else
      {
        if ( (unsigned __int16)wParam == 1020 || (unsigned __int16)wParam == 2 )
        {
          EndDialog(hDlg: hWnd, nResult: wParam);
          return 1;
        }
        if ( (unsigned __int16)wParam == 1019 )
        {
          InstallDlg_GetChanges(hWnd);
          EndDialog(hDlg: hWnd, nResult: wParam);
          return 1;
        }
      }
    }
    return 0;
  }
  if ( lParam[2] != -150 )
    return 0;
  v5 = lParam[5];
  v6 = lParam[11];
  if ( v5 != 0 )
  {
    v7 = v5 - 1;
    if ( v7 != 0 )
    {
      if ( v7 != 1 )
        return 0;
      lParam[8] = CUtlString::Get(this: &g_install_dvdImages.m_Memory.m_pMemory[v6].versionDetailString);
      return 1;
    }
    else
    {
      lParam[8] = CUtlString::Get(this: &g_install_dvdImages.m_Memory.m_pMemory[v6].notesString);
      return 1;
    }
  }
  else
  {
    lParam[8] = &g_install_dvdImages.m_Memory.m_pMemory[v6];
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412790
// Name: void InstallDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Open()
{
  const char *v0; // eax

  if ( (unsigned __int16)DialogBoxParamA(
                           hInstance: g_hInstance,
                           lpTemplateName: (LPCSTR)0x84,
                           hWndParent: g_hDlgMain,
                           lpDialogFunc: (DLGPROC)InstallDlg_Proc,
                           dwInitParam: 0) == 1019
    && g_install_Selection != -1 )
  {
    v0 = CUtlString::Get(this: &g_install_dvdImages.m_Memory.m_pMemory[g_install_Selection].installPath);
    InstallDlg_InstallImage(pInstallPath: v0);
  }
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
}

//------------------------------------------------------------------------------
// Address: 0x00424FA8
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x00424FAE
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x00424FB4
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00424FBA
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}
