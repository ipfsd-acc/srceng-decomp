// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/net_view_thread.cpp
// Functions: 213
// ============================================================

#include "utils\vmpi\net_view_thread.h"

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char *)realloc(pBlock: m_pMemory, newsize: m_nAllocationCount);
    else
      this->m_pMemory = (char *)malloc(size: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401410
// Name: public: CNetViewThread::CNetViewThread(void)
// Source: json
//------------------------------------------------------------------------------
CNetViewThread *__thiscall CNetViewThread::CNetViewThread(CNetViewThread *this)
{
  this->m_ComputerNames.m_Memory.m_pMemory = nullptr;
  this->m_ComputerNames.m_Memory.m_nAllocationCount = 0;
  this->m_ComputerNames.m_Memory.m_nGrowSize = 0;
  this->m_ComputerNames.m_Size = 0;
  this->m_ComputerNames.m_pElements = nullptr;
  this->m_hThread = nullptr;
  this->m_hThreadExitEvent = nullptr;
  InitializeCriticalSection(lpCriticalSection: &this->m_ComputerNamesCS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: public: CNetViewThread::~CNetViewThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetViewThread::~CNetViewThread(CNetViewThread *this)
{
  char **m_pMemory; // eax

  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hThreadExitEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_hThreadExitEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hThreadExitEvent);
    this->m_hThreadExitEvent = nullptr;
  }
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &this->m_ComputerNames);
  DeleteCriticalSection(lpCriticalSection: &this->m_ComputerNamesCS);
  this->m_ComputerNames.m_Size = 0;
  if ( this->m_ComputerNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ComputerNames.m_Memory.m_pMemory != nullptr )
    {
      free(pBlock: this->m_ComputerNames.m_Memory.m_pMemory);
      this->m_ComputerNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_ComputerNames.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_ComputerNames.m_Memory.m_pMemory;
  this->m_ComputerNames.m_pElements = this->m_ComputerNames.m_Memory.m_pMemory;
  if ( this->m_ComputerNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pBlock: m_pMemory);
      this->m_ComputerNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_ComputerNames.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: public: void CNetViewThread::GetComputerNames(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetViewThread::GetComputerNames(
        CNetViewThread *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *computerNames,
        bool bRemoveFromList)
{
  CNetViewThread *v3; // edi
  const char *v5; // edi
  char *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v10; // eax
  char **v11; // eax
  LPCRITICAL_SECTION lpCriticalSection; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  lpCriticalSection = &this->m_ComputerNamesCS;
  EnterCriticalSection(lpCriticalSection: &this->m_ComputerNamesCS);
  computerNames->m_Size = 0;
  if ( computerNames->m_Memory.m_nGrowSize >= 0 )
  {
    if ( computerNames->m_Memory.m_pMemory != nullptr )
    {
      free(pBlock: computerNames->m_Memory.m_pMemory);
      computerNames->m_Memory.m_pMemory = nullptr;
    }
    computerNames->m_Memory.m_nAllocationCount = 0;
  }
  computerNames->m_pElements = computerNames->m_Memory.m_pMemory;
  i = 0;
  if ( v3->m_ComputerNames.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_ComputerNames.m_Memory.m_pMemory[i];
      v6 = (char *)operator new[](nSize: strlen(v5) + 1);
      strcpy(v6, v5);
      m_Size = computerNames->m_Size;
      m_nAllocationCount = computerNames->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: &computerNames->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++computerNames->m_Size;
      m_pMemory = computerNames->m_Memory.m_pMemory;
      v10 = computerNames->m_Size - m_Size - 1;
      computerNames->m_pElements = computerNames->m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &computerNames->m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = v6;
      ++i;
      v3 = this;
    }
    while ( i < this->m_ComputerNames.m_Size );
  }
  if ( bRemoveFromList )
    CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_ComputerNames);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x00401610
// Name: private: void CNetViewThread::ParseComputerNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetViewThread::ParseComputerNames(CNetViewThread *this, const char *pNetViewOutput)
{
  _RTL_CRITICAL_SECTION *p_m_ComputerNamesCS; // esi
  const char *v4; // edi
  char v5; // al
  char *v6; // esi
  char v7; // cl
  int m_Size; // esi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v11; // eax
  char **v12; // esi
  char curComputerName[512]; // [esp+Ch] [ebp-204h] BYREF
  _RTL_CRITICAL_SECTION *v14; // [esp+20Ch] [ebp-4h]
  const char *pNetViewOutputa; // [esp+218h] [ebp+8h]
  const char *pNetViewOutputb; // [esp+218h] [ebp+8h]

  p_m_ComputerNamesCS = &this->m_ComputerNamesCS;
  v14 = &this->m_ComputerNamesCS;
  EnterCriticalSection(lpCriticalSection: &this->m_ComputerNamesCS);
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &this->m_ComputerNames);
  v4 = pNetViewOutput;
  if ( *pNetViewOutput != 0 )
  {
    do
    {
      if ( *v4 == 92 && v4[1] == 92 )
      {
        v5 = v4[2];
        v4 += 2;
        v6 = curComputerName;
        if ( v5 != 0 )
        {
          pNetViewOutputa = nullptr;
          do
          {
            if ( isspace(c: v5) != 0 )
              break;
            if ( (int)pNetViewOutputa >= 510 )
              break;
            v7 = *v4;
            v5 = v4[1];
            ++pNetViewOutputa;
            ++v4;
            *v6++ = v7;
          }
          while ( v5 != 0 );
        }
        *v6 = 0;
        pNetViewOutputb = strcpy((char *)operator new[](nSize: strlen(curComputerName) + 1), curComputerName);
        m_Size = this->m_ComputerNames.m_Size;
        m_nAllocationCount = this->m_ComputerNames.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(this: &this->m_ComputerNames.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++this->m_ComputerNames.m_Size;
        m_pMemory = this->m_ComputerNames.m_Memory.m_pMemory;
        v11 = this->m_ComputerNames.m_Size - m_Size - 1;
        this->m_ComputerNames.m_pElements = this->m_ComputerNames.m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &this->m_ComputerNames.m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = (char *)pNetViewOutputb;
      }
      ++v4;
    }
    while ( *v4 != 0 );
    p_m_ComputerNamesCS = v14;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_ComputerNamesCS);
}

//------------------------------------------------------------------------------
// Address: 0x00401740
// Name: private: void CNetViewThread::UpdateServicesFromNetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetViewThread::UpdateServicesFromNetView(CNetViewThread *this)
{
  int v1; // esi
  DWORD v2; // eax
  int m_Size; // [esp-14h] [ebp-20B0h]
  DWORD v4; // [esp-10h] [ebp-20ACh]
  char Buffer[8192]; // [esp+4h] [ebp-2098h] BYREF
  _STARTUPINFOA dst; // [esp+2004h] [ebp-98h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+2048h] [ebp-54h] BYREF
  _SECURITY_ATTRIBUTES PipeAttributes; // [esp+2058h] [ebp-44h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > v9; // [esp+2064h] [ebp-38h] BYREF
  CNetViewThread *v10; // [esp+2078h] [ebp-24h]
  void *hWritePipe; // [esp+207Ch] [ebp-20h] BYREF
  DWORD NumberOfBytesRead; // [esp+2080h] [ebp-1Ch] BYREF
  DWORD TotalBytesAvail; // [esp+2084h] [ebp-18h] BYREF
  void *hReadPipe; // [esp+2088h] [ebp-14h] BYREF
  char src; // [esp+208Fh] [ebp-Dh] BYREF
  int v16; // [esp+2098h] [ebp-4h]

  v10 = this;
  PipeAttributes.nLength = 12;
  PipeAttributes.bInheritHandle = 1;
  PipeAttributes.lpSecurityDescriptor = nullptr;
  if ( CreatePipe(&hReadPipe, &hWritePipe, lpPipeAttributes: &PipeAttributes, nSize: 0) )
  {
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.cb = 68;
    dst.dwFlags = 256;
    dst.hStdOutput = hWritePipe;
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: (LPSTR)"net view",
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: 8u,
           lpEnvironment: nullptr,
           lpCurrentDirectory: nullptr,
           lpStartupInfo: &dst,
           lpProcessInformation: &ProcessInformation) )
    {
      v1 = 0;
      memset(&v9, 0, sizeof(v9));
      v16 = 0;
      while ( 1 )
      {
        do
        {
          while ( 1 )
          {
            TotalBytesAvail = 0;
            NumberOfBytesRead = 0;
            PeekNamedPipe(
              hNamedPipe: hReadPipe,
              lpBuffer: nullptr,
              nBufferSize: 0,
              lpBytesRead: nullptr,
              lpTotalBytesAvail: &TotalBytesAvail,
              lpBytesLeftThisMessage: nullptr);
            v2 = TotalBytesAvail;
            if ( TotalBytesAvail != 0 )
            {
              if ( TotalBytesAvail >= 0x1FFF )
              {
                v2 = 0x1FFF;
                TotalBytesAvail = 0x1FFF;
              }
              ReadFile(
                hFile: hReadPipe,
                lpBuffer: Buffer,
                nNumberOfBytesToRead: v2,
                lpNumberOfBytesRead: &NumberOfBytesRead,
                lpOverlapped: nullptr);
            }
            if ( NumberOfBytesRead == 0 )
              break;
            v4 = NumberOfBytesRead;
            m_Size = v9.m_Size;
            Buffer[NumberOfBytesRead] = 0;
            CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
              this: &v9,
              elem: m_Size,
              num: v4,
              pToInsert: Buffer);
          }
        }
        while ( WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0x3E8u) == 258 );
        if ( v1 != 0 )
          break;
        v1 = 1;
      }
      src = 0;
      CUtlVector<char,CUtlMemory<char,int>>::AddToTail(this: &v9, &src);
      CNetViewThread::ParseComputerNames(this: v10, pNetViewOutput: v9.m_Memory.m_pMemory);
      CUtlVector<CIPAddr,CUtlMemory<CIPAddr,int>>::~CUtlVector<CIPAddr,CUtlMemory<CIPAddr,int>>(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v9);
    }
    CloseHandle(hObject: hReadPipe);
    CloseHandle(hObject: hWritePipe);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018D0
// Name: private: static unsigned long CNetViewThread::StaticThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
DWORD __stdcall CNetViewThread::StaticThreadFn(CNetViewThread *lpParameter)
{
  DWORD result; // eax

  do
  {
    CNetViewThread::UpdateServicesFromNetView(this: lpParameter);
    result = WaitForSingleObject(hHandle: lpParameter->m_hThreadExitEvent, dwMilliseconds: 0x7530u);
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: void CNetViewThread::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetViewThread::Init(CNetViewThread *this)
{
  unsigned int dwThreadID; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hThreadExitEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_hThreadExitEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hThreadExitEvent);
    this->m_hThreadExitEvent = nullptr;
  }
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &this->m_ComputerNames);
  this->m_hThreadExitEvent = CreateEventA(
                               lpEventAttributes: nullptr,
                               bManualReset: false,
                               bInitialState: false,
                               lpName: nullptr);
  dwThreadID = 0;
  this->m_hThread = CreateThread(
                      lpThreadAttributes: nullptr,
                      dwStackSize: 0,
                      lpStartAddress: (LPTHREAD_START_ROUTINE)CNetViewThread::StaticThreadFn,
                      lpParameter: this,
                      dwCreationFlags: 0,
                      lpThreadId: &dwThreadID);
}

//------------------------------------------------------------------------------
// Address: 0x0042D60A
// Name: protected: void CVSListBoxBase::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::Init(CVSListBoxBase *this)
{
  CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0xAu, nFlags: 0);
  if ( this->OnCreateList(this) != nullptr )
    CVSListBoxBase::AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043138F
// Name: protected: virtual void CMFCPropertyGridCtrl::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::Init(CMFCPropertyGridCtrl *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v3; // eax
  CMFCPropertyGridCtrl_vtbl *v4; // eax
  int v5; // eax
  CMFCPropertyGridCtrl_vtbl *v6; // eax
  int v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  BOOL v10; // eax
  _HD_ITEMA hdItem; // [esp+Ch] [ebp-44h] BYREF
  CRect rectDummy; // [esp+3Ch] [ebp-14h] BYREF

  memset(&rectDummy, 0, sizeof(rectDummy));
  SetRectEmpty(lprc: &rectDummy);
  if ( afxGlobalData.m_hcurStretch == nullptr )
  {
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    afxGlobalData.m_hcurStretch = LoadCursorW(
                                    hInstance: ModuleState->m_hCurrentResourceHandle,
                                    lpCursorName: (LPCWSTR)0x7904);
  }
  if ( afxGlobalData.m_hcurStretchVert == nullptr )
  {
    AfxGetModuleState();
    v3 = AfxGetModuleState();
    afxGlobalData.m_hcurStretchVert = LoadCursorW(
                                        hInstance: v3->m_hCurrentResourceHandle,
                                        lpCursorName: (LPCWSTR)0x7905);
  }
  this->InitHeader(this);
  v4 = this->__vftable;
  hdItem.mask = 6;
  hdItem.fmt = 0;
  hdItem.pszText = "Property";
  hdItem.cchTextMax = 100;
  v5 = (int)v4->GetHeaderCtrl(this);
  SendMessageA(hWnd: *(HWND *)(v5 + 32), Msg: 0x1201u, wParam: 0, lParam: (LPARAM)&hdItem);
  v6 = this->__vftable;
  hdItem.pszText = "Value";
  hdItem.cchTextMax = 100;
  v7 = (int)v6->GetHeaderCtrl(this);
  SendMessageA(hWnd: *(HWND *)(v7 + 32), Msg: 0x1201u, wParam: 1u, lParam: (LPARAM)&hdItem);
  this->m_wndScrollVert.Create(this: &this->m_wndScrollVert, a2: 1342177281u, a3: &rectDummy, a4: this, a5: 2u);
  this->m_ToolTip.Create(this: &this->m_ToolTip, a2: this, a3: 1u);
  SendMessageA(hWnd: this->m_ToolTip.m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
  if ( afxGlobalData.m_nMaxToolTipWidth != -1 )
    SendMessageA(hWnd: this->m_ToolTip.m_hWnd, Msg: 0x418u, wParam: 0, lParam: afxGlobalData.m_nMaxToolTipWidth);
  CWnd::SetWindowPos(
    this: &this->m_ToolTip,
    pWndInsertAfter: &CWnd::wndTop,
    x: -1,
    y: -1,
    cx: -1,
    cy: -1,
    nFlags: 0x13u);
  ((void (__stdcall *)(CMFCPropertyGridCtrl *))this->m_IPToolTip.Create)(a1: this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: Parent);
  v10 = v9 == nullptr || CObject::IsKindOf(this: v9, pClass: &CDialog::classCDialog) == 0;
  this->m_bControlBarColors = v10;
  this->AdjustLayout(this);
  CMFCPropertyGridCtrl::CreateBoldFont(this);
  CMFCPropertyGridCtrl::CalcEditMargin(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437A37
// Name: protected: void CMFCFontComboBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::Init(CMFCFontComboBox *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int IsKindOf; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  IsKindOf = CObject::IsKindOf(this: v3, pClass: &CMFCToolBar::classCMFCToolBar);
  this->m_bToolBarMode = IsKindOf;
  if ( IsKindOf == 0 )
    CMFCFontComboBox::Setup(this, nFontType: 7, nCharSet: 1u, nPitchAndFamily: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043CC7F
// Name: public: bool ATL::CImage::CInitGDIPlus::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ATL::CImage::CInitGDIPlus::Init(ATL::CImage::CInitGDIPlus *this)
{
  Gdiplus::GdiplusStartupInput input; // [esp+8h] [ebp-1Ch] BYREF
  Gdiplus::GdiplusStartupOutput output; // [esp+18h] [ebp-Ch] BYREF
  bool fRet; // [esp+23h] [ebp-1h]

  if ( this->m_dwLastError != 0 )
    return false;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  fRet = true;
  if ( this->m_dwToken == 0 )
  {
    input.GdiplusVersion = 1;
    memset(&input.DebugEventCallback, 0, 12);
    fRet = GdiplusStartup(a1: this, a2: &input, a3: &output) == 0;
  }
  LeaveCriticalSection(lpCriticalSection: &this->m_sect);
  return fRet;
}

//------------------------------------------------------------------------------
// Address: 0x00469186
// Name: private: long CCriticalSection::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CCriticalSection::Init(CCriticalSection *this)
{
  HRESULT result; // eax

  if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: &this->m_sect, dwSpinCount: 0) )
    return 0;
  result = GetLastError();
  if ( result > 0 )
    return (unsigned __int16)result | 0x80070000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494FC1
// Name: public: void CPaneDivider::Init(int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::Init(CPaneDivider *this, int bDefaultSlider, CWnd *pParentWnd)
{
  this->m_nID = -1;
  this->m_bDefaultDivider = bDefaultSlider;
  this->m_dwDividerStyle = 0;
  this->m_nWidth = 0;
  this->m_bCaptured = false;
  this->m_pContainerManager = nullptr;
  SetRectEmpty(lprc: &this->m_rectLastDragRect);
  SetRectEmpty(lprc: &this->m_rectDragBounds);
  this->m_nStep = -1;
  this->m_nMinOffset = 0;
  this->m_nMaxOffset = 0;
  this->m_bAutoHideMode = 0;
  this->m_pParentWndForSerialize = pParentWnd;
}

//------------------------------------------------------------------------------
// Address: 0x004D6652
// Name: public: void CMFCDragFrameImpl::Init(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::Init(CMFCDragFrameImpl *this, CWnd *pDraggedWnd)
{
  CWnd *v3; // ebx
  CObject *v4; // eax
  CWnd *v5; // eax
  CObject *v6; // edi
  CDockingManager *DockingManager; // eax

  this->m_pDraggedWnd = pDraggedWnd;
  v3 = nullptr;
  if ( CObject::IsKindOf(this: pDraggedWnd, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
  {
    v4 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: this->m_pDraggedWnd);
  }
  else
  {
    if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) == 0 )
      goto LABEL_8;
    v6 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
    v4 = (CObject *)((int (__thiscall *)(CObject *, _DWORD))v6->__vftable[45].Serialize)(a1: v6, a2: 0);
    if ( v4 == nullptr )
    {
      v5 = (CWnd *)v6->__vftable[34].GetRuntimeClass(this: v6);
      goto LABEL_7;
    }
  }
  v5 = CWnd::FromHandlePermanent(hWnd: (HWND__ *)v4[47].__vftable);
LABEL_7:
  v3 = v5;
LABEL_8:
  DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v3);
  this->m_pDockManager = DockingManager;
  if ( afxGlobalUtils.m_bDialogApp == 0 && DockingManager == nullptr )
    AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x004EFAFB
// Name: public: void CRecentPaneContainerInfo::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::Init(CRecentPaneContainerInfo *this)
{
  this->m_pRecentBarContainer = nullptr;
  SetRect(lprc: &this->m_rectDockedRect, xLeft: 0, yTop: 0, xRight: 30, yBottom: 30);
  this->m_pRecentContainerOfTabWnd = nullptr;
  this->m_nRecentPercent = 50;
  this->m_bIsRecentLeftBar = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EFB2A
// Name: public: void CRecentDockSiteInfo::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::Init(CRecentDockSiteInfo *this)
{
  SetRect(lprc: &this->m_rectRecentFloatingRect, xLeft: 10, yTop: 10, xRight: 110, yBottom: 110);
  this->m_nRecentTabNumber = -1;
  this->m_nRecentRowIndex = 0;
  this->m_pRecentDockBar = nullptr;
  this->m_pRecentDockBarRow = nullptr;
  this->m_hRecentDefaultSlider = nullptr;
  this->m_hRecentMiniFrame = nullptr;
  this->m_dwRecentAlignmentToFrame = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x0051C3CB
// Name: public: long ATL::CComCriticalSection::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ATL::CComCriticalSection::Init(ATL::CComCriticalSection *this)
{
  int v1; // esi
  signed int LastError; // eax

  v1 = 0;
  if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &this->m_sec, dwSpinCount: 0) )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      return (unsigned __int16)LastError | 0x80070000;
    return LastError;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0043153E
// Name: protected: long CMFCPropertyGridCtrl::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnSetFont(CMFCPropertyGridCtrl *this, HFONT__ *wParam, int __formal)
{
  this->m_hFont = wParam;
  CMFCPropertyGridCtrl::CreateBoldFont(this);
  CMFCPropertyGridCtrl::CalcEditMargin(this);
  this->AdjustLayout(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043156C
// Name: public: virtual void CMFCPropertyGridCtrl::OnPropertyChanged(class CMFCPropertyGridProperty __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnPropertyChanged(CMFCPropertyGridCtrl *this, CMFCPropertyGridProperty *pProp)
{
  int DlgCtrlID; // eax
  UINT v4; // esi
  WPARAM v5; // ebx
  CWnd *Owner; // eax

  CMFCPropertyGridProperty::SetModifiedFlag(this: pProp);
  DlgCtrlID = CWnd::GetDlgCtrlID(this);
  v4 = AFX_WM_PROPERTY_CHANGED;
  v5 = DlgCtrlID;
  Owner = CWnd::GetOwner(this);
  SendMessageA(hWnd: Owner->m_hWnd, Msg: v4, wParam: v5, lParam: (LPARAM)pProp);
}

//------------------------------------------------------------------------------
// Address: 0x004315A9
// Name: protected: void CMFCPropertyGridCtrl::OnHeaderTrack(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnHeaderTrack(CMFCPropertyGridCtrl *this, tagNMHDR *pNMHDR, int *pResult)
{
  int v3; // eax

  if ( pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  v3 = this->m_rectList.right - this->m_rectList.left;
  if ( *(_DWORD *)(pNMHDR[1].code + 4) < v3 )
    v3 = *(_DWORD *)(pNMHDR[1].code + 4);
  *(_DWORD *)(pNMHDR[1].code + 4) = v3;
  CMFCPropertyGridCtrl::TrackHeader(this, nOffset: *(_DWORD *)(pNMHDR[1].code + 4));
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004315EF
// Name: protected: void CMFCPropertyGridCtrl::OnHeaderEndTrack(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnHeaderEndTrack(CMFCPropertyGridCtrl *this, tagNMHDR *__formal, int *pResult)
{
  CMFCPropertyGridCtrl::TrackHeader(this, nOffset: -1);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00431605
// Name: protected: void CMFCPropertyGridCtrl::SetScrollSizes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetScrollSizes(CMFCPropertyGridCtrl *this)
{
  UINT v2; // edi
  int m_nRowHeight; // ecx
  int TotalItems; // eax
  int m_nVertScrollOffset; // eax
  CScrollBar *p_m_wndScrollVert; // [esp+8h] [ebp-24h]
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-20h] BYREF

  v2 = 0;
  p_m_wndScrollVert = &this->m_wndScrollVert;
  if ( this != (CMFCPropertyGridCtrl *)-580 && this->m_wndScrollVert.m_hWnd != nullptr )
  {
    m_nRowHeight = this->m_nRowHeight;
    if ( m_nRowHeight != 0 )
    {
      this->m_nVertScrollPage = (this->m_rectList.bottom - this->m_rectList.top) / m_nRowHeight - 1;
      TotalItems = CMFCPropertyGridCtrl::GetTotalItems(this, bIncludeHidden: 0);
      this->m_nVertScrollTotal = TotalItems;
      if ( TotalItems <= this->m_nVertScrollPage )
      {
        this->m_nVertScrollPage = 0;
        this->m_nVertScrollTotal = 0;
      }
      m_nVertScrollOffset = this->m_nVertScrollOffset;
      if ( m_nVertScrollOffset >= this->m_nVertScrollTotal )
        m_nVertScrollOffset = this->m_nVertScrollTotal;
      this->m_nVertScrollOffset = m_nVertScrollOffset;
    }
    else
    {
      this->m_nVertScrollPage = 0;
      this->m_nVertScrollTotal = 0;
      this->m_nVertScrollOffset = 0;
    }
    memset(dst: (unsigned __int8 *)&ScrollInfo, value: 0, count: sizeof(ScrollInfo));
    ScrollInfo.nMax = this->m_nVertScrollTotal;
    ScrollInfo.nPage = this->m_nVertScrollPage;
    ScrollInfo.nPos = this->m_nVertScrollOffset;
    ScrollInfo.cbSize = 28;
    ScrollInfo.fMask = 7;
    ScrollInfo.nMin = 0;
    CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: true);
    if ( this->m_nVertScrollTotal <= 0 )
      v2 = 3;
    EnableScrollBar(hWnd: this->m_wndScrollVert.m_hWnd, wSBflags: 2u, wArrows: v2);
    CWnd::EnableWindow(this: p_m_wndScrollVert, bEnable: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431721
// Name: protected: void CMFCPropertyGridCtrl::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnDestroy(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridProperty *v2; // eax

  while ( this->m_lstProps.m_nCount != 0 )
  {
    v2 = CList<CPropertyPage *,CPropertyPage *>::RemoveHead(this: &this->m_lstProps);
    if ( v2 != nullptr )
      ((void (__thiscall *)(CMFCPropertyGridProperty *, int))v2->dtr_CObject)(a1: v2, a2: 1);
  }
  this->m_pSel = nullptr;
  this->m_IPToolTip.DestroyWindow(this: &this->m_IPToolTip);
  this->m_ToolTip.DestroyWindow(this: &this->m_ToolTip);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x00431774
// Name: protected: virtual int CMFCPropertyGridCtrl::CompareProps(class CMFCPropertyGridProperty const __near *,class CMFCPropertyGridProperty const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::CompareProps(
        CMFCPropertyGridCtrl *this,
        const CMFCPropertyGridProperty *pProp1,
        const CMFCPropertyGridProperty *pProp2)
{
  return ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: &pProp1->m_strName,
           psz: pProp2->m_strName.m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x00437A6C
// Name: protected: virtual void CMFCFontComboBox::PreSubclassWindow(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::PreSubclassWindow(CMFCFontComboBox *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CBasePane *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CMFCFontComboBox::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437A8B
// Name: protected: int CMFCFontComboBox::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::OnCreate(CMFCFontComboBox *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    CMFCFontComboBox::Init(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437AAB
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCFontComboBox::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCFontComboBox::GetMessageMap(CMFCFontComboBox *this)
{
  return (const AFX_MSGMAP *)&off_5321EC;
}

//------------------------------------------------------------------------------
// Address: 0x00437AB1
// Name: public: virtual int CMFCEditBrowseCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::PreTranslateMessage(CMFCEditBrowseCtrl *this, tagMSG *pMsg)
{
  unsigned int wParam; // edx

  if ( pMsg->message != 260 )
    return CWnd::PreTranslateMessage(this, pMsg);
  if ( this->m_Mode == BrowseMode_None )
    return CWnd::PreTranslateMessage(this, pMsg);
  wParam = pMsg->wParam;
  if ( wParam != 40 && wParam != 39 )
    return CWnd::PreTranslateMessage(this, pMsg);
  this->OnBrowse(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00437AEF
// Name: protected: void CMFCEditBrowseCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnLButtonUp(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]

  if ( this->m_bIsButtonCaptured != 0 )
  {
    ReleaseCapture();
    m_hWnd = this->m_hWnd;
    this->m_bIsButtonPressed = 0;
    this->m_bIsButtonCaptured = 0;
    this->m_bIsButtonHighlighted = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    if ( PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
      this->OnBrowse(this);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437B54
// Name: protected: void CMFCEditBrowseCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnMouseMove(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]

  if ( this->m_bIsButtonCaptured != 0 )
  {
    v4 = PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT);
    if ( v4 != this->m_bIsButtonPressed )
    {
      m_hWnd = this->m_hWnd;
      this->m_bIsButtonPressed = v4;
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
  }
  else
  {
    if ( this->m_bIsButtonHighlighted != 0 && !PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
    {
      this->m_bIsButtonHighlighted = 0;
      ReleaseCapture();
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437BD6
// Name: protected: void CMFCEditBrowseCtrl::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcCalcSize(
        CMFCEditBrowseCtrl *this,
        int bCalcValidRects,
        tagNCCALCSIZE_PARAMS *lpncsp)
{
  CWnd::Default(this);
  if ( this->m_Mode != BrowseMode_None )
    lpncsp->rgrc[0].right -= this->m_nBrowseButtonWidth;
}

//------------------------------------------------------------------------------
// Address: 0x00437BFA
// Name: protected: long CMFCEditBrowseCtrl::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnNcHitTest(CMFCEditBrowseCtrl *this, CPoint point)
{
  CPoint ptClient; // [esp+4h] [ebp-8h] BYREF

  ptClient = point;
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptClient);
  if ( this->m_Mode != BrowseMode_None && PtInRect(lprc: &this->m_rectBtn, pt: ptClient.tagPOINT) )
    return 2;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437C4E
// Name: public: virtual void CMFCEditBrowseCtrl::OnChangeLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnChangeLayout(CMFCEditBrowseCtrl *this)
{
  int v2; // eax

  if ( this == nullptr || this->m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  v2 = this->m_sizeImage.cx + 8;
  if ( v2 < 20 )
    v2 = 20;
  this->m_nBrowseButtonWidth = v2;
  CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x27u);
  if ( this->m_Mode != BrowseMode_None )
  {
    GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_rectBtn);
    this->m_rectBtn.left = this->m_rectBtn.right - this->m_nBrowseButtonWidth;
    CWnd::ScreenToClient(this, lpRect: &this->m_rectBtn);
  }
  else
  {
    SetRectEmpty(lprc: &this->m_rectBtn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437CC1
// Name: protected: void CMFCEditBrowseCtrl::OnNcMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcMouseMove(CMFCEditBrowseCtrl *this, unsigned int nHitTest, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]
  CPoint ptClient; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bIsButtonCaptured == 0 )
  {
    ptClient = point;
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptClient);
    if ( PtInRect(lprc: &this->m_rectBtn, pt: ptClient.tagPOINT) )
    {
      v4 = SetCapture(hWnd: this->m_hWnd);
      CWnd::FromHandle(hWnd: v4);
      m_hWnd = this->m_hWnd;
      this->m_bIsButtonHighlighted = 1;
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437D38
// Name: protected: void CMFCEditBrowseCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnCancelMode(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-14h]

  CWnd::Default(this);
  if ( CWnd::IsWindowEnabled(this) != 0 )
    ReleaseCapture();
  m_hWnd = this->m_hWnd;
  this->m_bIsButtonPressed = 0;
  this->m_bIsButtonCaptured = 0;
  this->m_bIsButtonHighlighted = 0;
  RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
}

//------------------------------------------------------------------------------
// Address: 0x00437D73
// Name: protected: void CMFCEditBrowseCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnLButtonDown(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-8h]

  if ( this->m_Mode != BrowseMode_None && PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
  {
    CWnd::SetFocus(this);
    m_hWnd = this->m_hWnd;
    this->m_bIsButtonPressed = 1;
    this->m_bIsButtonCaptured = 1;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437DDD
// Name: protected: void CMFCEditBrowseCtrl::OnRButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnRButtonUp(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  if ( this->m_Mode == BrowseMode_None || !PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437E11
// Name: public: struct CComCtlWrapper::ImageList_ReplaceIcon_Type CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_ReplaceIcon_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_ReplaceIcon_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_ReplaceIcon.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_ReplaceIcon.p = (int (__stdcall *)(_IMAGELIST *, int, HICON__ *))GetProcAddress(
                                                                                          hModule: ModuleHandleA,
                                                                                          lpProcName: "ImageList_ReplaceIcon");
  }
  result->p = (int (__stdcall *)(_IMAGELIST *, int, HICON__ *))this->m__ImageList_ReplaceIcon;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437E40
// Name: public: int CComCtlWrapper::_ImageList_ReplaceIcon(struct _IMAGELIST __near *,int,struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_ReplaceIcon(CComCtlWrapper *this, _IMAGELIST *himl, int i, HICON__ *hicon)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(_IMAGELIST *, int, HICON__ *); // esi
  BOOL v9; // esi
  DWORD LastError; // edi
  int v11; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_ReplaceIcon_Type v12; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = -1;
  if ( !v6 )
    return -1;
  ms_exc.registration.TryLevel = 0;
  CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(this, result: &v12);
  p = this->m__ImageList_ReplaceIcon.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v14 = ((int (__stdcall *)(_IMAGELIST *, int, HICON__ *, int))p)(a1: himl, a2: i, a3: hicon, a4: v11);
  ms_exc.registration.TryLevel = -2;
  v9 = v14 == -1;
  if ( v14 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 )
    SetLastError(dwErrCode: LastError);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00437EED
// Name: public: struct CComCtlWrapper::ImageList_AddMasked_Type CComCtlWrapper::GetProcAddress_ImageList_AddMasked(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_AddMasked_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_AddMasked(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_AddMasked_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_AddMasked.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_AddMasked.p = (int (__stdcall *)(_IMAGELIST *, HBITMAP__ *, unsigned int))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "ImageList_AddMasked");
  }
  result->p = (int (__stdcall *)(_IMAGELIST *, HBITMAP__ *, unsigned int))this->m__ImageList_AddMasked;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437F1C
// Name: public: int CComCtlWrapper::_ImageList_AddMasked(struct _IMAGELIST __near *,struct HBITMAP__ __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_AddMasked(
        CComCtlWrapper *this,
        _IMAGELIST *himl,
        HBITMAP__ *hbmImage,
        unsigned int crMask)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(_IMAGELIST *, HBITMAP__ *, unsigned int); // esi
  BOOL v9; // esi
  DWORD LastError; // edi
  int v11; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_AddMasked_Type v12; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = -1;
  if ( !v6 )
    return -1;
  ms_exc.registration.TryLevel = 0;
  CComCtlWrapper::GetProcAddress_ImageList_AddMasked(this, result: &v12);
  p = this->m__ImageList_AddMasked.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v14 = ((int (__stdcall *)(_IMAGELIST *, HBITMAP__ *, unsigned int, int))p)(
          a1: himl,
          a2: hbmImage,
          a3: crMask,
          a4: v11);
  ms_exc.registration.TryLevel = -2;
  v9 = v14 == -1;
  if ( v14 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 )
    SetLastError(dwErrCode: LastError);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00437FC9
// Name: int AfxImageList_AddMasked(struct _IMAGELIST __near *,struct HBITMAP__ __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxImageList_AddMasked(_IMAGELIST *himl, HBITMAP__ *hbmImage, unsigned int crMask)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_AddMasked(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl,
           hbmImage,
           crMask);
}

//------------------------------------------------------------------------------
// Address: 0x00437FEA
// Name: public: int CImageList::Add(struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CImageList::Add(CImageList *this, HICON__ *hIcon)
{
  AFX_MODULE_STATE *ModuleState; // eax
  _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-Ch]

  m_hImageList = this->m_hImageList;
  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_ReplaceIcon(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl: m_hImageList,
           i: -1,
           hicon: hIcon);
}

//------------------------------------------------------------------------------
// Address: 0x0043800B
// Name: protected: void CMFCEditBrowseCtrl::SetInternalImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::SetInternalImage(CMFCEditBrowseCtrl *this)
{
  CImageList *p_m_ImageBrowse; // ecx
  const char *v3; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  HANDLE ImageA; // ebx
  unsigned int v6; // eax
  CGdiObject *v7; // eax
  HBITMAP__ *m_hObject; // ecx
  AFX_MODULE_STATE *v9; // eax
  _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-30h]
  HBITMAP__ *v11; // [esp-8h] [ebp-2Ch]
  int v12; // [esp-4h] [ebp-28h]
  tagBITMAP bmpObj; // [esp+Ch] [ebp-18h] BYREF

  p_m_ImageBrowse = &this->m_ImageBrowse;
  if ( p_m_ImageBrowse != nullptr && p_m_ImageBrowse->m_hImageList != nullptr )
    CImageList::DeleteImageList(this: p_m_ImageBrowse);
  v3 = (const char *)(AFX_GLOBAL_DATA::Is32BitIcons(this: &afxGlobalData) != 0 ? 17049 : 17032);
  ModuleState = AfxGetModuleState();
  ImageA = LoadImageA(hInst: ModuleState->m_hCurrentResourceHandle, name: v3, type: 0, cx: 0, cy: 0, fuLoad: 0x2000u);
  if ( ImageA != nullptr )
  {
    GetObjectA(h: ImageA, c: 24, pv: &bmpObj);
    switch ( bmpObj.bmBitsPixel )
    {
      case 8u:
        v12 = 9;
        break;
      case 0x10u:
        v12 = 17;
        break;
      case 0x18u:
        v12 = 25;
        break;
      default:
        v6 = bmpObj.bmBitsPixel == 32 ? 33 : 5;
LABEL_13:
        CImageList::Create(this: &this->m_ImageBrowse, cx: 16, cy: 16, nFlags: v6, nInitial: 0, nGrow: 0);
        v7 = CGdiObject::FromHandle(h: ImageA);
        if ( v7 != nullptr )
          m_hObject = (HBITMAP__ *)v7->m_hObject;
        else
          m_hObject = nullptr;
        v11 = m_hObject;
        m_hImageList = this->m_ImageBrowse.m_hImageList;
        v9 = AfxGetModuleState();
        CComCtlWrapper::_ImageList_AddMasked(
          this: *(CComCtlWrapper **)v9->m_pDllIsolationWrappers,
          himl: m_hImageList,
          hbmImage: v11,
          crMask: 0xFF00FFu);
        this->m_sizeImage.cx = 16;
        this->m_sizeImage.cy = 16;
        this->m_bDefaultImage = 1;
        return;
    }
    v6 = v12;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043810E
// Name: public: virtual void CMFCEditBrowseCtrl::OnAfterUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnAfterUpdate(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // esi
  WPARAM DlgCtrlID; // ebx
  CWnd *Owner; // eax
  HWND__ *v5; // ebx
  CWnd *v6; // eax
  int wParam; // [esp+4h] [ebp-4h]

  if ( CWnd::GetOwner(this) != nullptr )
  {
    if ( this != nullptr )
      m_hWnd = this->m_hWnd;
    else
      m_hWnd = nullptr;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    Owner = CWnd::GetOwner(this);
    PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x300u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
    if ( this != nullptr )
      v5 = this->m_hWnd;
    else
      v5 = nullptr;
    wParam = CWnd::GetDlgCtrlID(this);
    v6 = CWnd::GetOwner(this);
    PostMessageA(hWnd: v6->m_hWnd, Msg: 0x400u, wParam, lParam: (LPARAM)v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043817E
// Name: public: CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCEditBrowseCtrl *__thiscall CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(CMFCEditBrowseCtrl *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax

  CWnd::CWnd(this);
  this->__vftable = (CMFCEditBrowseCtrl_vtbl *)&CMFCEditBrowseCtrl::`vftable';
  this->m_rectBtn.left = 0;
  this->m_rectBtn.top = 0;
  this->m_rectBtn.right = 0;
  this->m_rectBtn.bottom = 0;
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strLabel, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDefFileExt, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileFilter, pStringMgr: v4);
  CImageList::CImageList(this: &this->m_ImageBrowse);
  SetRectEmpty(lprc: &this->m_rectBtn);
  this->m_sizeImage.cx = 0;
  this->m_bIsButtonPressed = 0;
  this->m_bIsButtonHighlighted = 0;
  this->m_bIsButtonCaptured = 0;
  this->m_Mode = BrowseMode_None;
  this->m_sizeImage.cy = 0;
  this->m_nBrowseButtonWidth = 20;
  this->m_bDefaultImage = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438246
// Name: public: virtual CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(CMFCEditBrowseCtrl *this)
{
  this->__vftable = (CMFCEditBrowseCtrl_vtbl *)&CMFCEditBrowseCtrl::`vftable';
  CImageList::~CImageList(this: &this->m_ImageBrowse);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileFilter.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDefFileExt.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strLabel.m_pszData - 1);
  CEdit::~CEdit(this);
}

//------------------------------------------------------------------------------
// Address: 0x004382AA
// Name: public: virtual void CMFCEditBrowseCtrl::OnDrawBrowseButton(class CDC __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnDrawBrowseButton(
        CMFCEditBrowseCtrl *this,
        CDC *pDC,
        CRect rect,
        int bIsButtonPressed,
        int bHighlight)
{
  int v5; // esi
  CMFCVisualManager *Instance; // eax
  int v7; // esi
  int v8; // edi
  CMFCVisualManager *v9; // eax
  CGdiObject *v10; // eax
  CFont *pFont; // [esp+Ch] [ebp-28h]
  unsigned int clrText; // [esp+10h] [ebp-24h] BYREF
  unsigned int clrTextOld; // [esp+14h] [ebp-20h]
  CMFCEditBrowseCtrl *v14; // [esp+18h] [ebp-1Ch]
  int nTextMode; // [esp+1Ch] [ebp-18h]
  CRect rectText; // [esp+20h] [ebp-14h] BYREF

  v5 = 0;
  v14 = this;
  if ( bIsButtonPressed != 0 )
  {
    v5 = 1;
  }
  else if ( bHighlight != 0 )
  {
    v5 = 2;
  }
  clrText = afxGlobalData.clrBtnText;
  Instance = CMFCVisualManager::GetInstance();
  if ( ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCEditBrowseCtrl *, int, unsigned int *))Instance->OnDrawBrowseButton)(
         a1: Instance,
         a2: pDC,
         a3: rect.left,
         a4: rect.top,
         a5: rect.right,
         a6: rect.bottom,
         a7: v14,
         a8: v5,
         a9: &clrText) != 0 )
  {
    nTextMode = 0;
    clrTextOld = (unsigned int)&v14->m_ImageBrowse;
    if ( v14 == (CMFCEditBrowseCtrl *)-176 || v14->m_ImageBrowse.m_hImageList == nullptr )
    {
      if ( *((_DWORD *)v14->m_strLabel.m_pszData - 3) != 0 )
      {
        clrTextOld = pDC->SetTextColor(this: pDC, a2: clrText);
        nTextMode = CDC::SetBkMode(this: pDC, nBkMode: 1);
        v10 = pDC->SelectStockObject(this: pDC, a2: 17);
        rectText = rect;
        pFont = (CFont *)v10;
        InflateRect(lprc: &rectText, dx: -1, dy: -2);
        OffsetRect(lprc: &rectText, dx: 0, dy: -2);
        if ( bIsButtonPressed != 0 )
          OffsetRect(lprc: &rectText, dx: 1, dy: 1);
        pDC->DrawTextA(
          this: pDC,
          a2: v14->m_strLabel.m_pszData,
          a3: *((_DWORD *)v14->m_strLabel.m_pszData - 3),
          a4: &rectText,
          a5: 37u);
        pDC->SetTextColor(this: pDC, a2: clrTextOld);
        CDC::SetBkMode(this: pDC, nBkMode: nTextMode);
        pDC->SelectObject(this: pDC, a2: pFont);
      }
    }
    else
    {
      if ( v14->m_bDefaultImage != 0 )
      {
        if ( v14->m_Mode == BrowseMode_File )
        {
          nTextMode = 1;
        }
        else if ( v14->m_Mode == BrowseMode_Folder )
        {
          nTextMode = 0;
        }
      }
      v7 = (rect.right + rect.left) / 2 - v14->m_sizeImage.cx / 2;
      v8 = (rect.top + rect.bottom) / 2 - v14->m_sizeImage.cy / 2;
      if ( bIsButtonPressed != 0 )
      {
        v9 = CMFCVisualManager::GetInstance();
        if ( v9->IsOffsetPressedButton(this: v9) != 0 )
        {
          ++v7;
          ++v8;
        }
      }
      CImageList::Draw(
        this: (CImageList *)clrTextOld,
        pDC,
        nImage: nTextMode,
        pt: (tagPOINT)__PAIR64__(v8, v7),
        nStyle: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438467
// Name: public: void CMFCEditBrowseCtrl::EnableFolderBrowseButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableFolderBrowseButton(CMFCEditBrowseCtrl *this)
{
  if ( this == nullptr || this->m_hWnd == nullptr || afxShellManager == nullptr )
    AfxThrowInvalidArgException();
  this->m_Mode = BrowseMode_Folder;
  CMFCEditBrowseCtrl::SetInternalImage(this);
  this->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004384BF
// Name: public: virtual int CMFCEditBrowseCtrl::OnIllegalFileName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnIllegalFileName(
        CMFCEditBrowseCtrl *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strFileName)
{
  ATL::IAtlStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::IAtlStringMgr *v5; // eax
  char *m_pszData; // esi
  char *v7; // edi
  char *v9; // [esp-8h] [ebp-2Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strError; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strError, pStringMgr: StringManager);
  v12 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF100u);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &strError,
      hInstance: StringResourceHandle,
      nID: 0xF100u);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: v5);
  m_pszData = strError.m_pszData;
  v9 = strFileName->m_pszData;
  LOBYTE(v12) = 1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &strMessage,
    pszFormat: "%s\r\n%s",
    v9,
    strError.m_pszData);
  v7 = strMessage.m_pszData;
  CWnd::MessageBoxA(this, lpszText: strMessage.m_pszData, lpszCaption: nullptr, nType: 0x30u);
  ATL::CStringData::Release(this: (ATL::CStringData *)v7 - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043854D
// Name: protected: void CMFCEditBrowseCtrl::OnNcPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcPaint(CMFCEditBrowseCtrl *this)
{
  int top; // eax
  HRGN v3; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  HWND__ *v5; // [esp-8h] [ebp-74h]
  CWindowDC v6; // [esp+10h] [ebp-5Ch] BYREF
  CGdiObject v7; // [esp+24h] [ebp-48h] BYREF
  tagRECT rc; // [esp+2Ch] [ebp-40h] BYREF
  tagRECT v9; // [esp+3Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+4Ch] [ebp-20h] BYREF
  int v11; // [esp+68h] [ebp-4h]

  CWnd::Default(this);
  if ( this->m_Mode != BrowseMode_None )
  {
    CWindowDC::CWindowDC(this: &v6, pWnd: this);
    m_hWnd = this->m_hWnd;
    v11 = 0;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    this->m_rectBtn = (CRect)Rect;
    v5 = this->m_hWnd;
    this->m_rectBtn.left = this->m_rectBtn.right - this->m_nBrowseButtonWidth;
    memset((void *)&v9, 0, sizeof(v9));
    GetClientRect(hWnd: v5, lpRect: &v9);
    CWnd::ClientToScreen(this, lpRect: &v9);
    OffsetRect(lprc: &this->m_rectBtn, dx: v9.right + this->m_nBrowseButtonWidth - Rect.right, dy: 0);
    top = Rect.top;
    this->m_rectBtn.top += v9.top - Rect.top;
    this->m_rectBtn.bottom += v9.bottom - Rect.bottom;
    rc = (tagRECT)this->m_rectBtn;
    OffsetRect(lprc: &rc, dx: -Rect.left, dy: -top);
    v7.m_hObject = nullptr;
    v7.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    LOBYTE(v11) = 1;
    v3 = CreateRectRgnIndirect(lprect: &rc);
    CGdiObject::Attach(this: &v7, hObject: v3);
    CDC::SelectClipRgn(this: &v6, pRgn: (CRgn *)&v7);
    ((void (__thiscall *)(CMFCEditBrowseCtrl *, CWindowDC *, int, int, int, int, int, int))this->OnDrawBrowseButton)(
      a1: this,
      a2: &v6,
      a3: rc.left,
      a4: rc.top,
      a5: rc.right,
      a6: rc.bottom,
      a7: this->m_bIsButtonPressed,
      a8: this->m_bIsButtonHighlighted);
    CDC::SelectClipRgn(this: &v6, pRgn: nullptr);
    CWnd::ScreenToClient(this, lpRect: &this->m_rectBtn);
    LOBYTE(v11) = 0;
    v7.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &v7);
    v11 = -1;
    CWindowDC::~CWindowDC(this: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004386AC
// Name: public: void CMFCEditBrowseCtrl::EnableBrowseButton(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableBrowseButton(CMFCEditBrowseCtrl *this, int bEnable, const char *szLabel)
{
  CMFCEditBrowseCtrl_vtbl *v4; // eax

  if ( this == nullptr || this->m_hWnd == nullptr || szLabel == nullptr )
    AfxThrowInvalidArgException();
  this->m_Mode = bEnable != 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strLabel, pszSrc: szLabel);
  CImageList::DeleteImageList(this: &this->m_ImageBrowse);
  this->m_sizeImage.cx = 0;
  v4 = this->__vftable;
  this->m_sizeImage.cy = 0;
  v4->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043870F
// Name: public: void CMFCEditBrowseCtrl::EnableFileBrowseButton(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableFileBrowseButton(
        CMFCEditBrowseCtrl *this,
        const char *lpszDefExt,
        const char *lpszFilter)
{
  const char *v4; // eax
  const char *v5; // edi

  if ( this == nullptr || this->m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  v4 = lpszDefExt;
  this->m_Mode = BrowseMode_File;
  v5 = szGroupName;
  if ( lpszDefExt == nullptr )
    v4 = szGroupName;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDefFileExt, pszSrc: v4);
  if ( lpszFilter != nullptr )
    v5 = lpszFilter;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileFilter, pszSrc: v5);
  CMFCEditBrowseCtrl::SetInternalImage(this);
  this->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438777
// Name: protected: long CMFCEditBrowseCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnInitControl(CMFCEditBrowseCtrl *this, unsigned int wParam, const char *lParam)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CTagManager tagManager; // [esp+10h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strBrowseMode; // [esp+1Ch] [ebp-10h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v13 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v13) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strBrowseMode, pStringMgr: v5);
  LOBYTE(v13) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCEditBrowse_Mode",
         strTag: &strBrowseMode,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strBrowseMode.m_pszData - 3) != 0 )
  {
    v6 = atoi(nptr: strBrowseMode.m_pszData);
    if ( v6 != 0 )
    {
      v7 = v6 - 1;
      if ( v7 != 0 )
      {
        v8 = v7 - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
            CMFCEditBrowseCtrl::EnableBrowseButton(this, bEnable: 1, szLabel: "...");
        }
        else
        {
          CMFCEditBrowseCtrl::EnableFolderBrowseButton(this);
        }
      }
      else
      {
        CMFCEditBrowseCtrl::EnableFileBrowseButton(this, lpszDefExt: nullptr, lpszFilter: nullptr);
      }
    }
    else
    {
      CMFCEditBrowseCtrl::EnableBrowseButton(this, bEnable: 0, szLabel: "...");
    }
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strBrowseMode.m_pszData - 1);
  LOBYTE(v13) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043884F
// Name: public: virtual void CMFCEditBrowseCtrl::OnBrowse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnBrowse(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax
  char *v5; // ecx
  ATL::IAtlStringMgr *StringManager; // eax
  const unsigned __int8 *v7; // eax
  int v8; // eax
  HWND Parent; // eax
  HWND v10; // eax
  CWnd *v11; // eax
  char *m_pszData; // [esp-4h] [ebp-348h]
  char *v13; // [esp-4h] [ebp-348h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-334h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v15; // [esp+14h] [ebp-330h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v16; // [esp+18h] [ebp-32Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v17; // [esp+1Ch] [ebp-328h] BYREF
  ATL::CSimpleStringT<char,0> v18; // [esp+20h] [ebp-324h] BYREF
  ATL::CSimpleStringT<char,0> v19; // [esp+24h] [ebp-320h] BYREF
  ATL::CSimpleStringT<char,0> v20; // [esp+28h] [ebp-31Ch] BYREF
  char v21; // [esp+2Fh] [ebp-315h]
  CFileDialog v22; // [esp+30h] [ebp-314h] BYREF
  char _Filename[268]; // [esp+234h] [ebp-110h] BYREF
  int v24; // [esp+340h] [ebp-4h]

  v19.m_pszData = nullptr;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_Mode == BrowseMode_File )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v20, pStringMgr: StringManager);
    v24 = 2;
    CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
    if ( *((_DWORD *)v20.m_pszData - 3) != 0 )
    {
      _splitpath_s(
        _Path: v20.m_pszData,
        _Drive: nullptr,
        _DriveSize: 0,
        _Dir: nullptr,
        _DirSize: 0,
        _Filename,
        _FilenameSize: 0x100u,
        _Ext: nullptr,
        _ExtSize: 0);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v17,
        pszSrc: _Filename);
      LOBYTE(v24) = 3;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: &v17);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: &v17);
      if ( *((_DWORD *)v17.m_pszData - 3) == 0 )
        ATL::CSimpleStringT<char,0>::Empty(this: &v20);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v16,
        pszSrc: "*?<>|");
      LOBYTE(v24) = 4;
      v7 = _mbspbrk(string: (const unsigned __int8 *)v20.m_pszData, charset: (const unsigned __int8 *)v16.m_pszData);
      if ( v7 != nullptr
        && v7 - (const unsigned __int8 *)v20.m_pszData >= 0
        && this->OnIllegalFileName(this, a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20) == 0 )
      {
        CWnd::SetFocus(this);
        ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v20.m_pszData - 1);
        return;
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
      LOBYTE(v24) = 2;
      ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
    }
    CFileDialog::CFileDialog(
      this: &v22,
      bOpenFileDialog: 1,
      lpszDefExt: *((_DWORD *)this->m_strDefFileExt.m_pszData - 3) != 0 ? this->m_strDefFileExt.m_pszData : nullptr,
      lpszFileName: v20.m_pszData,
      dwFlags: 0,
      lpszFilter: *((_DWORD *)this->m_strFileFilter.m_pszData - 3) != 0 ? this->m_strFileFilter.m_pszData : nullptr,
      pParentWnd: nullptr,
      dwSize: 0,
      bVistaStyle: 1);
    LOBYTE(v24) = 5;
    if ( CFileDialog::DoModal(this: &v22) != 1
      || (m_pszData = CFileDialog::GetPathName(this: &v22, &result)->m_pszData,
          LOBYTE(v24) = 6,
          v19.m_pszData = (char *)1,
          v8 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                 this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20,
                 psz: m_pszData),
          v21 = 1,
          v8 == 0) )
    {
      v21 = 0;
    }
    v24 = 5;
    if ( ((int)v19.m_pszData & 1) != 0 )
      ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
    if ( v21 != 0 )
    {
      v13 = CFileDialog::GetPathName(this: &v22, result: &v15)->m_pszData;
      LOBYTE(v24) = 7;
      CWnd::SetWindowTextA(this, lpszString: v13);
      LOBYTE(v24) = 5;
      ATL::CStringData::Release(this: (ATL::CStringData *)v15.m_pszData - 1);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xB9u, wParam: 1u, lParam: 0);
      this->OnAfterUpdate(this);
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
    {
      v10 = GetParent(hWnd: this->m_hWnd);
      v11 = CWnd::FromHandle(hWnd: v10);
      RedrawWindow(hWnd: v11->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x481u);
    }
    LOBYTE(v24) = 2;
    CFileDialog::~CFileDialog(this: &v22);
    v5 = v20.m_pszData;
  }
  else
  {
    if ( this->m_Mode != BrowseMode_Folder || afxShellManager == nullptr )
      goto LABEL_32;
    v3 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v19, pStringMgr: v3);
    v24 = 0;
    CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v19);
    v4 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v18, pStringMgr: v4);
    LOBYTE(v24) = 1;
    if ( CShellManager::BrowseForFolder(
           this: afxShellManager,
           strFolder: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v18,
           pWndParent: this,
           lplszInitialFolder: v19.m_pszData,
           lpszTitle: nullptr,
           ulFlags: 1u,
           piFolderImage: nullptr) != 0
      && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v18,
           psz: v19.m_pszData) != 0 )
    {
      CWnd::SetWindowTextA(this, lpszString: v18.m_pszData);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xB9u, wParam: 1u, lParam: 0);
      this->OnAfterUpdate(this);
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)v18.m_pszData - 1);
    v5 = v19.m_pszData;
  }
  v24 = -1;
  ATL::CStringData::Release(this: (ATL::CStringData *)v5 - 1);
LABEL_32:
  CWnd::SetFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043CCDD
// Name: public: void ATL::CImage::CInitGDIPlus::ReleaseGDIPlus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::CInitGDIPlus::ReleaseGDIPlus(ATL::CImage::CInitGDIPlus *this)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // edi

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  if ( this->m_dwToken != 0 )
    GdiplusShutdown(a1: this->m_dwToken);
  this->m_dwToken = 0;
  LeaveCriticalSection(lpCriticalSection: p_m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD06
// Name: public: void ATL::CImage::CInitGDIPlus::IncreaseCImageCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::CInitGDIPlus::IncreaseCImageCount(ATL::CImage::CInitGDIPlus *this)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // edi

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  ++this->m_nCImageObjects;
  LeaveCriticalSection(lpCriticalSection: p_m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD23
// Name: public: void ATL::CImage::CInitGDIPlus::DecreaseCImageCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::CInitGDIPlus::DecreaseCImageCount(ATL::CImage::CInitGDIPlus *this)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // edi

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  if ( this->m_nCImageObjects-- == 1 )
    ATL::CImage::CInitGDIPlus::ReleaseGDIPlus(this);
  LeaveCriticalSection(lpCriticalSection: p_m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD49
// Name: public: struct HDC__ __near * ATL::CImage::CDCCache::GetDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HDC __thiscall ATL::CImage::CDCCache::GetDC(ATL::CImage::CDCCache *this)
{
  int v1; // edi
  HDC result; // eax

  v1 = 0;
  while ( 1 )
  {
    result = (HDC)InterlockedExchange(Target: (volatile LONG *)this, Value: 0);
    if ( result != nullptr )
      break;
    ++v1;
    this = (ATL::CImage::CDCCache *)((char *)this + 4);
    if ( v1 >= 4 )
      return CreateCompatibleDC(hdc: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD71
// Name: public: void ATL::CImage::CDCCache::ReleaseDC(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::CDCCache::ReleaseDC(ATL::CImage::CDCCache *this, HDC__ *hDC)
{
  int v2; // edi
  HDC v4; // eax

  v2 = 0;
  while ( 1 )
  {
    v4 = (HDC)InterlockedExchange(Target: (volatile LONG *)this, Value: (LONG)hDC);
    if ( v4 == nullptr )
      break;
    ++v2;
    this = (ATL::CImage::CDCCache *)((char *)this + 4);
    hDC = v4;
    if ( v2 >= 4 )
    {
      DeleteDC(hdc: v4);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CDA3
// Name: public: ATL::CImage::CImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CImage *__thiscall ATL::CImage::CImage(ATL::CImage *this)
{
  this->m_iTransparentColor = -1;
  this->m_clrTransparentColor = -1;
  this->__vftable = (ATL::CImage_vtbl *)&ATL::CImage::`vftable';
  this->m_hBitmap = nullptr;
  this->m_pBits = nullptr;
  this->m_nWidth = 0;
  this->m_nHeight = 0;
  this->m_nPitch = 0;
  this->m_nBPP = 0;
  *(_WORD *)&this->m_bIsDIBSection = 0;
  this->m_hDC = nullptr;
  this->m_nDCRefCount = 0;
  this->m_hOldBitmap = nullptr;
  ATL::CImage::CInitGDIPlus::IncreaseCImageCount(this: &ATL::CImage::s_initGDIPlus);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043CDE3
// Name: public: struct HBITMAP__ __near * ATL::CImage::Detach(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBITMAP__ *__thiscall ATL::CImage::Detach(ATL::CImage *this)
{
  HBITMAP__ *result; // eax

  result = this->m_hBitmap;
  this->m_iTransparentColor = -1;
  this->m_clrTransparentColor = -1;
  this->m_hBitmap = nullptr;
  this->m_pBits = nullptr;
  this->m_nWidth = 0;
  this->m_nHeight = 0;
  this->m_nBPP = 0;
  this->m_nPitch = 0;
  *(_WORD *)&this->m_bIsDIBSection = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CE07
// Name: public: struct HDC__ __near * ATL::CImage::GetDC(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HDC__ *__thiscall ATL::CImage::GetDC(ATL::CImage *this)
{
  HDC__ *DC; // eax
  HBITMAP__ *m_hBitmap; // [esp-4h] [ebp-8h]

  ++this->m_nDCRefCount;
  if ( this->m_hDC == nullptr )
  {
    DC = ATL::CImage::CDCCache::GetDC(this: &ATL::CImage::s_cache);
    m_hBitmap = this->m_hBitmap;
    this->m_hDC = DC;
    this->m_hOldBitmap = (HBITMAP__ *)SelectObject(hdc: DC, h: m_hBitmap);
  }
  return this->m_hDC;
}

//------------------------------------------------------------------------------
// Address: 0x0043CE34
// Name: public: void ATL::CImage::ReleaseDC(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::ReleaseDC(ATL::CImage *this)
{
  if ( this->m_nDCRefCount-- == 1 )
  {
    SelectObject(hdc: this->m_hDC, h: this->m_hOldBitmap);
    ATL::CImage::CDCCache::ReleaseDC(this: &ATL::CImage::s_cache, hDC: this->m_hDC);
    this->m_hDC = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CE5D
// Name: private: void ATL::CImage::UpdateBitmapInfo(enum ATL::CImage::DIBOrientation)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::UpdateBitmapInfo(ATL::CImage *this, ATL::CImage::DIBOrientation eOrientation)
{
  int biWidth; // eax
  int v4; // edi
  int v5; // kr00_4
  char *bmBits; // ecx
  int v7; // eax
  int bmBitsPixel; // eax
  int biHeight; // [esp-4h] [ebp-64h]
  tagDIBSECTION dibsection; // [esp+8h] [ebp-58h] BYREF

  if ( GetObjectA(h: this->m_hBitmap, c: 84, pv: &dibsection) == 84 )
  {
    biWidth = dibsection.dsBmih.biWidth;
    biHeight = dibsection.dsBmih.biHeight;
    this->m_bIsDIBSection = true;
    this->m_nWidth = biWidth;
    v4 = abs(lnumber: biHeight);
    v5 = dibsection.dsBmih.biBitCount * this->m_nWidth + 31;
    this->m_nBPP = dibsection.dsBmih.biBitCount;
    bmBits = (char *)dibsection.dsBm.bmBits;
    v7 = 4 * (v5 / 32);
    this->m_nHeight = v4;
    this->m_nPitch = v7;
    this->m_pBits = bmBits;
    if ( eOrientation == DIBOR_DEFAULT )
      eOrientation = (dibsection.dsBmih.biHeight > 0) + 1;
    if ( eOrientation == DIBOR_BOTTOMUP )
    {
      this->m_pBits = &bmBits[v7 * (v4 - 1)];
      this->m_nPitch = -4 * (v5 / 32);
    }
  }
  else
  {
    this->m_nWidth = dibsection.dsBm.bmWidth;
    this->m_nHeight = dibsection.dsBm.bmHeight;
    bmBitsPixel = dibsection.dsBm.bmBitsPixel;
    this->m_bIsDIBSection = false;
    this->m_nBPP = bmBitsPixel;
    this->m_nPitch = 0;
    this->m_pBits = nullptr;
  }
  this->m_iTransparentColor = -1;
  this->m_bHasAlphaChannel = false;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF24
// Name: protected: int CFrameImpl::IsOwnerDrawCaption(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameImpl::IsOwnerDrawCaption(CFrameImpl *this)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  return Instance->IsOwnerDrawCaption(this: Instance) != 0 && this->m_bIsOleInPlaceActive == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF4B
// Name: public: int CMDIFrameWndEx::AreMDITabs(int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIFrameWndEx::AreMDITabs(CMDIFrameWndEx *this, int *pnMDITabsType)
{
  if ( pnMDITabsType != nullptr )
  {
    *pnMDITabsType = 0;
    if ( this->m_wndClientArea.m_bTabIsEnabled != 0 )
    {
      *pnMDITabsType = 1;
    }
    else if ( this->m_wndClientArea.m_bIsMDITabbedGroup != 0 )
    {
      *pnMDITabsType = 2;
    }
  }
  return this->m_wndClientArea.m_bTabIsEnabled != 0 || this->m_wndClientArea.m_bIsMDITabbedGroup != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF94
// Name: public: virtual struct CRuntimeClass __near * CMDIChildWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMDIChildWndEx::GetRuntimeClass(CMDIChildWndEx *this)
{
  return &CMDIChildWndEx::classCMDIChildWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF9A
// Name: public: virtual CMDIFrameWnd::~CMDIFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMDIFrameWnd::~CMDIFrameWnd(CMDIChildWnd *this)
{
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043CF9F
// Name: protected: long CMDIChildWndEx::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnSetText(CMDIChildWndEx *this, unsigned int __formal, const char *lParam)
{
  int v4; // edi
  CMDIFrameWndEx *m_pMDIFrame; // eax

  v4 = CWnd::Default(this);
  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr )
    CMDIClientAreaWnd::UpdateTabs(this: &m_pMDIFrame->m_wndClientArea, bSetActiveTabVisible: 1);
  CFrameImpl::OnSetText(this: &this->m_Impl, __formal: lParam);
  this->SetTaskbarTabText(this, a2: lParam);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043CFE9
// Name: protected: long CMDIChildWndEx::OnSetIcon(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnSetIcon(CMDIChildWndEx *this, unsigned int __formal, unsigned int __formala)
{
  int v4; // edi
  CMDIFrameWndEx *m_pMDIFrame; // eax

  v4 = CWnd::Default(this);
  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr )
    CMDIClientAreaWnd::UpdateTabs(this: &m_pMDIFrame->m_wndClientArea, bSetActiveTabVisible: 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043D014
// Name: protected: virtual int CMDIChildWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::PreCreateWindow(CMDIChildWndEx *this, tagCREATESTRUCTA *cs)
{
  CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
  return CMDIChildWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x0043D037
// Name: public: int CMDIChildWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::AddPane(CMDIChildWndEx *this, CBasePane *pControlBar, int bTail)
{
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043D055
// Name: public: int CMDIChildWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::InsertPane(CMDIChildWndEx *this, CBasePane *pControlBar, CBasePane *pTarget, int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x0043D066
// Name: public: void CMDIChildWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::RemovePaneFromDockManager(
        CMDIChildWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
}

//------------------------------------------------------------------------------
// Address: 0x0043D077
// Name: public: void CMDIChildWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::DockPane(
        CMDIChildWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *__formal)
{
  if ( pBar->CanFloat(this: pBar) != 0 && CMDIChildWndEx::m_bEnableFloatingBars == 0 )
    pBar->m_dwControlBarStyle &= ~1u;
  if ( pBar->CanBeResized(this: pBar) != 0 || pBar->CanFloat(this: pBar) != 0 )
  {
    pBar->EnableDocking(this: pBar, a2: 61440u);
    CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect: nullptr);
  }
  else
  {
    CMDIChildWndEx::AddPane(this, pControlBar: pBar, bTail: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D0EF
// Name: public: class CBasePane __near * CMDIChildWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CMDIChildWndEx::PaneFromPoint(
        CMDIChildWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043D116
// Name: public: int CMDIChildWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::IsPointNearDockSite(
        CMDIChildWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x0043D136
// Name: public: virtual int CMDIChildWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnMoveMiniFrame(CMDIChildWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0043D147
// Name: protected: void CMDIChildWndEx::OnSysCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnSysCommand(CMDIChildWndEx *this, unsigned int nID, int lParam)
{
  CMDIFrameWndEx *m_pMDIFrame; // ecx

  if ( nID != 61696
    || (m_pMDIFrame = this->m_pMDIFrame) == nullptr
    || !CMDIFrameWndEx::AreMDITabs(this: m_pMDIFrame, pnMDITabsType: nullptr) )
  {
    CFrameWnd::OnSysCommand(this, nID, lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D17F
// Name: protected: long CMDIChildWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnIdleUpdateCmdUI(CMDIChildWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D198
// Name: protected: long CMDIChildWndEx::OnChangeVisualManager(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnChangeVisualManager(
        CMDIChildWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax

  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr && m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup == 0 )
    CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D1BB
// Name: public: virtual void CMDIChildWndEx::OnTaskbarTabThumbnailActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailActivate(
        CMDIChildWndEx *this,
        unsigned int nState,
        CWnd *pWndOther,
        int bMinimized)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( nState != 2 )
    this->ActivateTopLevelFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043D1EA
// Name: public: virtual int CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate(
        CMDIChildWndEx *this,
        CWnd *pDesktopWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( message == 514 )
    this->ActivateTopLevelFrame(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043D21F
// Name: public: virtual struct CRuntimeClass __near * CMDITabProxyWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMDITabProxyWnd::GetRuntimeClass(CMDITabProxyWnd *this)
{
  return &CMDITabProxyWnd::classCMDITabProxyWnd;
}

//------------------------------------------------------------------------------
// Address: 0x0043D225
// Name: public: CMDITabProxyWnd::CMDITabProxyWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDITabProxyWnd *__thiscall CMDITabProxyWnd::CMDITabProxyWnd(CMDITabProxyWnd *this)
{
  CWnd::CWnd(this);
  this->m_pRelatedMDIChildFrame = nullptr;
  this->__vftable = (CMDITabProxyWnd_vtbl *)&CMDITabProxyWnd::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043D23D
// Name: protected: void CMDITabProxyWnd::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDITabProxyWnd::OnActivate(
        CMDITabProxyWnd *this,
        unsigned int nState,
        CWnd *pWndOther,
        int bMinimized)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    this->m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailActivate(
      this: this->m_pRelatedMDIChildFrame,
      a2: nState,
      a3: pWndOther,
      a4: bMinimized);
}

//------------------------------------------------------------------------------
// Address: 0x0043D258
// Name: protected: int CMDITabProxyWnd::OnMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDITabProxyWnd::OnMouseActivate(
        CMDITabProxyWnd *this,
        CWnd *pDesktopWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    return this->m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailMouseActivate(
             this: this->m_pRelatedMDIChildFrame,
             a2: pDesktopWnd,
             a3: nHitTest,
             a4: message);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D275
// Name: protected: void CMDITabProxyWnd::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDITabProxyWnd::OnClose(CMDITabProxyWnd *this)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    this->m_pRelatedMDIChildFrame->OnPressTaskbarThmbnailCloseButton(this: this->m_pRelatedMDIChildFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0043D287
// Name: public: CList<struct HWND__ __near *,struct HWND__ __near *>::CList<struct HWND__ __near *,struct HWND__ __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HWND__ *,HWND__ *> *__thiscall CList<HWND__ *,HWND__ *>::CList<HWND__ *,HWND__ *>(
        CList<HWND__ *,HWND__ *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004691AE
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  HRESULT v2; // eax

  CSyncObject::CSyncObject(this, pstrName: nullptr);
  this->__vftable = (CCriticalSection_vtbl *)&CCriticalSection::`vftable';
  v2 = CCriticalSection::Init(this);
  if ( v2 < 0 )
    ATL::AtlThrowImpl(hr: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004691E9
// Name: public: virtual CCriticalSection::~CCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  this->__vftable = (CCriticalSection_vtbl *)&CCriticalSection::`vftable';
  DeleteCriticalSection(lpCriticalSection: &this->m_sect);
  CSyncObject::~CSyncObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x00469206
// Name: public: virtual int CCriticalSection::Lock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCriticalSection::Lock(CCriticalSection *this, unsigned int dwTimeout)
{
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00469216
// Name: public: virtual int CCriticalSection::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: &this->m_sect);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00469224
// Name: public: Gdiplus::Graphics::Graphics(class Gdiplus::Image __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Graphics *__thiscall Gdiplus::Graphics::Graphics(Gdiplus::Graphics *this, Gdiplus::Image *image)
{
  Gdiplus::GpGraphics *graphics; // [esp+4h] [ebp-4h] BYREF

  graphics = nullptr;
  if ( image != nullptr )
    this->lastResult = GdipGetImageGraphicsContext(a1: image->nativeImage, a2: &graphics);
  this->nativeGraphics = graphics;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00469253
// Name: public: enum Gdiplus::Status Gdiplus::Graphics::DrawImage(class Gdiplus::Image __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Status __thiscall Gdiplus::Graphics::DrawImage(Gdiplus::Graphics *this, Gdiplus::Image *image, int x, int y)
{
  Gdiplus::GpImage *nativeImage; // eax
  Gdiplus::Status result; // eax

  if ( image != nullptr )
    nativeImage = image->nativeImage;
  else
    nativeImage = nullptr;
  result = GdipDrawImageI(a1: this->nativeGraphics, a2: nativeImage, a3: x, a4: y);
  if ( result == Ok )
    return Ok;
  this->lastResult = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469287
// Name: public: virtual CMFCZoomKernel::~CMFCZoomKernel(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCZoomKernel::~CMFCZoomKernel(CMFCZoomKernel *this)
{
  this->__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  CMFCZoomKernel::Empty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00495036
// Name: public: virtual int CPaneDivider::IsHorizontal(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CPaneDivider::IsHorizontal(CPaneDivider *this)
{
  return this->m_dwDividerStyle & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00495040
// Name: public: virtual int CPaneDivider::IsAutoHideMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::IsAutoHideMode(CPaneDivider *this)
{
  return this->m_bAutoHideMode;
}

//------------------------------------------------------------------------------
// Address: 0x00495047
// Name: public: class CDockablePane __near * CPaneDivider::FindTabbedPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__thiscall CPaneDivider::FindTabbedPane(CPaneDivider *this, unsigned int nID)
{
  CPaneContainerManager *m_pContainerManager; // ecx

  m_pContainerManager = this->m_pContainerManager;
  if ( m_pContainerManager != nullptr )
    return CPaneContainerManager::FindTabbedPane(this: m_pContainerManager, nID);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495062
// Name: public: virtual void CPaneDivider::AddPane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::AddPane(CPaneDivider *this, CDockablePane *pBar)
{
  this->m_pContainerManager->AddPane(this: this->m_pContainerManager, a2: pBar);
  this->CheckVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x00495087
// Name: public: virtual class CDockablePane __near * CPaneDivider::AddRecentPane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__thiscall CPaneDivider::AddRecentPane(CPaneDivider *this, CDockablePane *pBar)
{
  CPaneContainer *RecentTabContainer; // eax
  CDockablePane *v5; // eax
  CDockablePane *pAddedBar; // [esp+Ch] [ebp-4h]
  CPaneContainer *pRecentContainer; // [esp+18h] [ebp+8h]

  pAddedBar = nullptr;
  pRecentContainer = CRecentDockSiteInfo::GetRecentPaneContainer(this: &pBar->m_recentDockInfo, bForSlider: 1);
  RecentTabContainer = CRecentDockSiteInfo::GetRecentTabContainer(this: &pBar->m_recentDockInfo, bForSlider: 1);
  if ( pRecentContainer != nullptr )
  {
    v5 = this->m_pContainerManager->AddPaneToRecentPaneContainer(
           this: this->m_pContainerManager,
           a2: pBar,
           a3: pRecentContainer);
LABEL_5:
    pAddedBar = v5;
    this->CheckVisibility(this);
    return pAddedBar;
  }
  if ( RecentTabContainer != nullptr )
  {
    v5 = this->m_pContainerManager->AddPaneToRecentPaneContainer(
           this: this->m_pContainerManager,
           a2: pBar,
           a3: RecentTabContainer);
    goto LABEL_5;
  }
  return pAddedBar;
}

//------------------------------------------------------------------------------
// Address: 0x004950F5
// Name: public: virtual int CPaneDivider::InsertPane(class CDockablePane __near *,class CDockablePane __near *,unsigned long,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::InsertPane(
        CPaneDivider *this,
        CDockablePane *pBarToInsert,
        CDockablePane *pTargetBar,
        unsigned int dwAlignment,
        const tagRECT *lpRect)
{
  int v6; // edi

  v6 = 0;
  if ( this->m_pContainerManager != nullptr )
  {
    v6 = this->m_pContainerManager->InsertPane(
           this: this->m_pContainerManager,
           a2: pBarToInsert,
           a3: pTargetBar,
           a4: dwAlignment,
           a5: lpRect,
           a6: DM_UNKNOWN);
    this->CheckVisibility(this);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00495136
// Name: public: class CBasePane const __near * CPaneDivider::GetFirstPane(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CBasePane *__thiscall CPaneDivider::GetFirstPane(CPaneDivider *this)
{
  if ( this->m_pContainerManager != nullptr )
    return this->m_pContainerManager->GetFirstPane(this: this->m_pContainerManager);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049514F
// Name: public: virtual int CPaneDivider::ReplacePane(class CDockablePane __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::ReplacePane(
        CPaneDivider *this,
        CDockablePane *pBarToReplace,
        CDockablePane *pBarToReplaceWith)
{
  int v5; // edi

  if ( this->m_pContainerManager == nullptr )
    return 0;
  CDockablePane::SetDefaultPaneDivider(this: pBarToReplaceWith, hSliderWnd: this->m_hWnd);
  v5 = this->m_pContainerManager->ReplacePane(this: this->m_pContainerManager, a2: pBarToReplace, a3: pBarToReplaceWith);
  this->CheckVisibility(this);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00495195
// Name: protected: void CPaneDivider::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPaneDivider::OnDestroy(CPaneDivider *this)
{
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049519A
// Name: protected: void CPaneDivider::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnNcDestroy(CPaneDivider *this)
{
  CPaneContainerManager *m_pContainerManager; // ecx
  CPaneContainerManager *v3; // ecx

  m_pContainerManager = this->m_pContainerManager;
  if ( m_pContainerManager != nullptr )
    m_pContainerManager->RemovePaneDivider(this: m_pContainerManager, a2: this);
  v3 = this->m_pContainerManager;
  if ( v3 != nullptr && this->m_bDefaultDivider != 0 )
  {
    ((void (__thiscall *)(CPaneContainerManager *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    this->m_pContainerManager = nullptr;
  }
  CWnd::OnNcDestroy(this);
  ((void (__thiscall *)(CPaneDivider *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004951E5
// Name: public: void CPaneDivider::ShowWindow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::ShowWindow(CPaneDivider *this, int nCmdShow)
{
  CWnd::ShowWindow(this, nCmdShow);
}

//------------------------------------------------------------------------------
// Address: 0x004951F0
// Name: public: void CPaneDivider::StoreRecentDockSiteInfo(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::StoreRecentDockSiteInfo(CPaneDivider *this, CDockablePane *pBar)
{
  if ( this->m_pContainerManager != nullptr )
    this->m_pContainerManager->StoreRecentDockSiteInfo(this: this->m_pContainerManager, a2: pBar);
}

//------------------------------------------------------------------------------
// Address: 0x00495213
// Name: public: void CPaneDivider::StoreRecentTabRelatedInfo(class CDockablePane __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::StoreRecentTabRelatedInfo(
        CPaneDivider *this,
        CDockablePane *pDockingBar,
        CDockablePane *pTabbedBar)
{
  CPaneContainerManager *m_pContainerManager; // ecx
  CPaneContainer *v4; // eax
  int bLeftBar; // [esp+0h] [ebp-4h] BYREF

  bLeftBar = (int)this;
  if ( this->m_pContainerManager != nullptr )
  {
    m_pContainerManager = this->m_pContainerManager;
    bLeftBar = 0;
    v4 = m_pContainerManager->FindPaneContainer(this: m_pContainerManager, a2: pTabbedBar, a3: &bLeftBar);
    if ( v4 != nullptr )
      pDockingBar->m_recentDockInfo.StoreDockInfo(this: &pDockingBar->m_recentDockInfo, a2: v4, a3: pTabbedBar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495255
// Name: public: class CPaneContainer __near * CPaneDivider::FindPaneContainer(class CDockablePane __near *,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CPaneDivider::FindPaneContainer(CPaneDivider *this, CDockablePane *pBar, int *bLeftBar)
{
  return this->m_pContainerManager->FindPaneContainer(this: this->m_pContainerManager, a2: pBar, a3: bLeftBar);
}

//------------------------------------------------------------------------------
// Address: 0x00495269
// Name: public: virtual int CPaneDivider::AddPaneContainer(class CPaneContainerManager __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::AddPaneContainer(
        CPaneDivider *this,
        CPaneContainerManager *barContainerManager,
        int bOuterEdge)
{
  int v4; // edi

  v4 = 0;
  if ( this->m_pContainerManager != nullptr )
  {
    v4 = this->m_pContainerManager->AddPaneContainerManager_2(
           this: this->m_pContainerManager,
           a2: barContainerManager,
           a3: bOuterEdge);
    this->CheckVisibility(this);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004952A3
// Name: public: virtual int CPaneDivider::AddPaneContainer(class CDockablePane __near *,class CPaneContainerManager __near &,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::AddPaneContainer(
        CPaneDivider *this,
        CDockablePane *pTargetBar,
        CPaneContainerManager *barContainerManager,
        unsigned int dwAlignment)
{
  int v5; // edi

  v5 = 0;
  if ( this->m_pContainerManager != nullptr )
  {
    v5 = this->m_pContainerManager->AddPaneContainerManager(
           this: this->m_pContainerManager,
           a2: pTargetBar,
           a3: dwAlignment,
           a4: barContainerManager,
           a5: 1);
    this->CheckVisibility(this);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004952E2
// Name: public: virtual void CPaneDivider::OnShowPane(class CDockablePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnShowPane(CPaneDivider *this, CDockablePane *pBar, int bShow)
{
  int v4; // eax
  CPaneContainerManager *m_pContainerManager; // ecx
  int v6; // eax

  if ( this->m_pContainerManager != nullptr && this->IsAutoHideMode(this) == 0 )
  {
    v4 = this->m_pContainerManager->OnShowPane(this: this->m_pContainerManager, a2: pBar, a3: bShow);
    if ( bShow != 0 )
    {
      CWnd::ShowWindow(this, nCmdShow: 5);
    }
    else
    {
      CWnd::ShowWindow(this, nCmdShow: v4 != 0 ? 5 : 0);
      m_pContainerManager = this->m_pContainerManager;
      bShow = 0;
      v6 = (int)m_pContainerManager->FindPaneContainer(this: m_pContainerManager, a2: pBar, a3: &bShow);
      if ( v6 != 0 )
        (*(void (__thiscall **)(int, CDockablePane *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: pBar, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049535C
// Name: public: virtual int CPaneDivider::CheckVisibility(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::CheckVisibility(CPaneDivider *this)
{
  int v2; // edi

  if ( this->m_bDefaultDivider == 0 || this->IsAutoHideMode(this) != 0 || this->m_pContainerManager == nullptr )
    return 0;
  v2 = this->m_pContainerManager->IsRootPaneContainerVisible(this: this->m_pContainerManager);
  CWnd::ShowWindow(this, nCmdShow: v2 != 0 ? 5 : 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004953A6
// Name: public: virtual int CPaneDivider::DoesContainFloatingPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::DoesContainFloatingPane(CPaneDivider *this)
{
  if ( this->m_pContainerManager != nullptr )
    return this->m_pContainerManager->DoesContainFloatingPane(this: this->m_pContainerManager);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004953BF
// Name: public: virtual int CPaneDivider::DoesAllowDynInsertBefore(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::DoesAllowDynInsertBefore(CPaneDivider *this)
{
  if ( this->m_pContainerManager != nullptr )
    return this->m_pContainerManager->DoesAllowDynInsertBefore(this: this->m_pContainerManager);
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004953D9
// Name: public: virtual void CPaneDivider::CalcExpectedDockedRect(class CWnd __near *,class CPoint,class CRect __near &,int __near &,class CDockablePane __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::CalcExpectedDockedRect(
        CPaneDivider *this,
        CDockablePane *pWndToDock,
        CPoint ptMouse,
        CRect *rectResult,
        int *bDrawTab,
        CBasePane **ppTargetBar)
{
  CPaneContainerManager *m_pContainerManager; // eax
  CGlobalUtils globalUtilsLocal; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  CGlobalUtils::CGlobalUtils(this: &globalUtilsLocal);
  m_pContainerManager = this->m_pContainerManager;
  v9 = 0;
  if ( m_pContainerManager != nullptr )
    CGlobalUtils::CalcExpectedDockedRect(
      this: &globalUtilsLocal,
      barContainerManager: m_pContainerManager,
      pWndToDock,
      ptMouse,
      rectResult,
      bDrawTab,
      ppTargetBar);
  v9 = -1;
  CGlobalUtils::~CGlobalUtils(this: &globalUtilsLocal);
}

//------------------------------------------------------------------------------
// Address: 0x0049542C
// Name: public: virtual void CPaneDivider::NotifyAboutRelease(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::NotifyAboutRelease(CPaneDivider *this)
{
  if ( CPaneContainerManager::IsEmpty(this: this->m_pContainerManager)
    && CPaneContainerManager::GetTotalRefCount(this: this->m_pContainerManager) == 0 )
  {
    CBasePane::RemovePaneFromDockManager(
      this,
      pBar: this,
      bDestroy: 1,
      bAdjustLayout: 0,
      bAutoHide: this->m_bAutoHideMode,
      pBarReplacement: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495465
// Name: public: void CPaneDivider::GetPanes(class CObList __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::GetPanes(CPaneDivider *this, CObList *lstBars)
{
  CPaneContainerManager *m_pContainerManager; // ecx

  m_pContainerManager = this->m_pContainerManager;
  if ( m_pContainerManager != nullptr )
    CPaneContainerManager::AddPanesToList(this: m_pContainerManager, plstControlBars: lstBars, plstSliders: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00495482
// Name: public: class CRect CPaneDivider::GetRootContainerRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CPaneDivider::GetRootContainerRect(CPaneDivider *this, CRect *result)
{
  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  SetRectEmpty(lprc: result);
  if ( this->m_pContainerManager != nullptr )
    this->m_pContainerManager->GetWindowRect(this: this->m_pContainerManager, a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004954C2
// Name: public: CPaneDivider::CPaneDivider(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__thiscall CPaneDivider::CPaneDivider(CPaneDivider *this)
{
  CBasePane::CBasePane(this);
  this->__vftable = (CPaneDivider_vtbl *)&CPaneDivider::`vftable';
  this->m_rectLastDragRect.left = 0;
  this->m_rectLastDragRect.top = 0;
  this->m_rectLastDragRect.right = 0;
  this->m_rectLastDragRect.bottom = 0;
  this->m_rectDragBounds.left = 0;
  this->m_rectDragBounds.top = 0;
  this->m_rectDragBounds.right = 0;
  this->m_rectDragBounds.bottom = 0;
  this->m_ptHotTotal.x = 0;
  this->m_ptHotTotal.y = 0;
  this->m_ptHotDrag.x = 0;
  this->m_ptHotDrag.y = 0;
  CPaneDivider::Init(this, bDefaultSlider: 0, pParentWnd: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00495550
// Name: protected: int CPaneDivider::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::OnSetCursor(CPaneDivider *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  unsigned int m_dwDividerStyle; // eax

  if ( nHitTest != 1 )
    return CWnd::Default(this);
  m_dwDividerStyle = this->m_dwDividerStyle;
  if ( (m_dwDividerStyle & 1) != 0 )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurStretchVert);
  }
  else if ( (m_dwDividerStyle & 2) != 0 )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurStretch);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0049558B
// Name: protected: void CPaneDivider::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnLButtonDown(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  int v5; // edi
  HWND DesktopWindow; // eax
  CWnd *v7; // eax
  CPaneContainerManager *m_pContainerManager; // ecx
  int *p_m_nMaxOffset; // esi
  bool v10; // zf
  int m_nMinOffset; // eax
  tagSIZE v12; // [esp-1Ch] [ebp-60h]
  tagSIZE v13; // [esp-10h] [ebp-54h]
  HWND__ *v14; // [esp-8h] [ebp-4Ch]
  HWND__ *m_hWnd; // [esp-4h] [ebp-48h]
  CWindowDC v16; // [esp+10h] [ebp-34h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-20h] BYREF
  int v18; // [esp+40h] [ebp-4h]

  if ( !this->m_bCaptured )
  {
    m_hWnd = this->m_hWnd;
    this->m_bCaptured = true;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
    v14 = this->m_hWnd;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: v14, lpRect: &Rect);
    v5 = this->m_nWidth / 2;
    DesktopWindow = GetDesktopWindow();
    v7 = CWnd::FromHandle(hWnd: DesktopWindow);
    CWindowDC::CWindowDC(this: &v16, pWnd: v7);
    v13.cy = v5;
    v13.cx = v5;
    v12.cy = v5;
    v12.cx = v5;
    v18 = 0;
    CDC::DrawDragRect(
      this: &v16,
      lpRect: &Rect,
      size: v12,
      lpRectLast: nullptr,
      sizeLast: v13,
      pBrush: nullptr,
      pBrushLast: nullptr);
    this->m_rectLastDragRect.left = Rect.left;
    this->m_rectLastDragRect.top = Rect.top;
    m_pContainerManager = this->m_pContainerManager;
    this->m_rectLastDragRect.right = Rect.right;
    this->m_rectLastDragRect.bottom = Rect.bottom;
    this->m_rectDragBounds = (CRect)Rect;
    if ( m_pContainerManager != nullptr )
    {
      p_m_nMaxOffset = &this->m_nMaxOffset;
      m_pContainerManager->GetMinMaxOffset(
        this: m_pContainerManager,
        a2: this,
        a3: &this->m_nMinOffset,
        a4: &this->m_nMaxOffset,
        a5: &this->m_nStep);
      v10 = this->IsHorizontal(this) == 0;
      m_nMinOffset = this->m_nMinOffset;
      if ( v10 )
      {
        this->m_rectDragBounds.left = Rect.left + m_nMinOffset;
        this->m_rectDragBounds.right = Rect.right + *p_m_nMaxOffset;
      }
      else
      {
        this->m_rectDragBounds.top = Rect.top + m_nMinOffset;
        this->m_rectDragBounds.bottom = Rect.bottom + *p_m_nMaxOffset;
      }
      this->m_pContainerManager->SetResizeMode(this: this->m_pContainerManager, a2: 1);
    }
    v18 = -1;
    CWindowDC::~CWindowDC(this: &v16);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x004956B3
// Name: protected: void CPaneDivider::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnLButtonUp(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  this->StopTracking(this, a2: 1);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x004956CD
// Name: protected: void CPaneDivider::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnMouseMove(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  int left; // edx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int right; // ecx
  int m_nWidth; // ecx
  int top; // esi
  int v11; // edx
  int bottom; // eax
  HWND DesktopWindow; // eax
  CWnd *v14; // eax
  tagSIZE v15; // [esp-1Ch] [ebp-68h]
  tagSIZE v16; // [esp-10h] [ebp-5Ch]
  CWindowDC v17; // [esp+10h] [ebp-3Ch] BYREF
  tagPOINT Point; // [esp+24h] [ebp-28h] BYREF
  tagRECT Rect; // [esp+2Ch] [ebp-20h] BYREF
  int v20; // [esp+48h] [ebp-4h]

  if ( this->m_bCaptured )
  {
    Point.x = 0;
    Point.y = 0;
    Rect = (tagRECT)this->m_rectLastDragRect;
    GetCursorPos(lpPoint: &Point);
    if ( (this->m_dwDividerStyle & 2) != 0 )
    {
      left = this->m_rectDragBounds.left;
      v5 = this->m_nWidth / 2;
      v6 = this->m_nWidth + Point.x - v5;
      Rect.left = Point.x - v5;
      Rect.right = v6;
      if ( Point.x - v5 < left )
      {
        v7 = this->m_rectLastDragRect.right - this->m_rectLastDragRect.left;
        Rect.left = left;
        v6 = left + v7;
        Rect.right = v6;
      }
      right = this->m_rectDragBounds.right;
      if ( v6 > right )
      {
        Rect.right = this->m_rectDragBounds.right;
        Rect.left = this->m_rectLastDragRect.left + right - this->m_rectLastDragRect.right;
      }
    }
    else
    {
      m_nWidth = this->m_nWidth;
      top = this->m_rectDragBounds.top;
      v5 = m_nWidth / 2;
      v11 = m_nWidth + Point.y - m_nWidth / 2;
      Rect.top = Point.y - m_nWidth / 2;
      Rect.bottom = v11;
      if ( Rect.top < top )
      {
        v11 = m_nWidth + top;
        Rect.top = top;
        Rect.bottom = m_nWidth + top;
      }
      bottom = this->m_rectDragBounds.bottom;
      if ( v11 > bottom )
      {
        Rect.bottom = this->m_rectDragBounds.bottom;
        Rect.top = bottom - m_nWidth;
      }
    }
    DesktopWindow = GetDesktopWindow();
    v14 = CWnd::FromHandle(hWnd: DesktopWindow);
    CWindowDC::CWindowDC(this: &v17, pWnd: v14);
    v16.cy = v5;
    v16.cx = v5;
    v20 = 0;
    v15.cy = v5;
    v15.cx = v5;
    CDC::DrawDragRect(
      this: &v17,
      lpRect: &Rect,
      size: v15,
      lpRectLast: &this->m_rectLastDragRect,
      sizeLast: v16,
      pBrush: nullptr,
      pBrushLast: nullptr);
    v20 = -1;
    this->m_rectLastDragRect = (CRect)Rect;
    CWindowDC::~CWindowDC(this: &v17);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x00495808
// Name: protected: void CPaneDivider::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnCancelMode(CPaneDivider *this)
{
  this->StopTracking(this, a2: 0);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049581F
// Name: protected: virtual void CPaneDivider::StopTracking(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::StopTracking(CPaneDivider *this, int bMoveSlider)
{
  int v3; // ecx
  CPaneContainerManager *m_pContainerManager; // ecx
  tagSIZE v5; // [esp-1Ch] [ebp-78h]
  tagSIZE v6; // [esp-10h] [ebp-6Ch]
  HWND__ *m_hWnd; // [esp-8h] [ebp-64h]
  CWindowDC v8; // [esp+10h] [ebp-4Ch] BYREF
  _DWORD v9[2]; // [esp+24h] [ebp-38h] BYREF
  tagRECT rc; // [esp+2Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+3Ch] [ebp-20h] BYREF
  int v12; // [esp+58h] [ebp-4h]

  if ( this->m_bCaptured )
  {
    m_hWnd = this->m_hWnd;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    v3 = this->m_rectLastDragRect.left - Rect.left;
    v9[1] = this->m_rectLastDragRect.top - Rect.top;
    v9[0] = v3;
    memset((void *)&rc, 0, sizeof(rc));
    SetRectEmpty(lprc: &rc);
    CWindowDC::CWindowDC(this: &v8, pWnd: nullptr);
    v6.cy = this->m_nWidth / 2;
    v6.cx = v6.cy;
    v5.cy = v6.cy;
    v5.cx = v6.cy;
    v12 = 0;
    CDC::DrawDragRect(
      this: &v8,
      lpRect: &rc,
      size: v5,
      lpRectLast: &this->m_rectLastDragRect,
      sizeLast: v6,
      pBrush: nullptr,
      pBrushLast: nullptr);
    if ( bMoveSlider != 0 )
      this->Move(this, a2: (CPoint *)v9, a3: 1);
    SetRectEmpty(lprc: &this->m_rectLastDragRect);
    ReleaseCapture();
    m_pContainerManager = this->m_pContainerManager;
    this->m_bCaptured = false;
    if ( m_pContainerManager != nullptr )
      m_pContainerManager->SetResizeMode(this: m_pContainerManager, a2: 0);
    v12 = -1;
    CWindowDC::~CWindowDC(this: &v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004958FA
// Name: protected: void CPaneDivider::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnPaint(CPaneDivider *this)
{
  CMFCVisualManager *Instance; // eax
  CDC *p_m_dcMem; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-C8h]
  CPaintDC v5; // [esp+10h] [ebp-B0h] BYREF
  CMemDC v6; // [esp+64h] [ebp-5Ch] BYREF
  tagRECT Rect; // [esp+A0h] [ebp-20h] BYREF
  int v8; // [esp+BCh] [ebp-4h]

  CPaintDC::CPaintDC(this: &v5, pWnd: this);
  v8 = 0;
  CMemDC::CMemDC(this: &v6, dc: &v5, pWnd: this);
  m_hWnd = this->m_hWnd;
  LOBYTE(v8) = 1;
  memset((void *)&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  Instance = CMFCVisualManager::GetInstance();
  p_m_dcMem = &v6.m_dcMem;
  if ( v6.m_bMemDC == 0 )
    p_m_dcMem = v6.m_dc;
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CPaneDivider *, int, int, int, int, int))Instance->OnDrawPaneDivider)(
    a1: Instance,
    a2: p_m_dcMem,
    a3: this,
    a4: Rect.left,
    a5: Rect.top,
    a6: Rect.right,
    a7: Rect.bottom,
    a8: this->m_bAutoHideMode);
  LOBYTE(v8) = 0;
  CMemDC::~CMemDC(this: &v6);
  v8 = -1;
  CPaintDC::~CPaintDC(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x00495998
// Name: public: virtual void CPaneDivider::Move(class CPoint __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::Move(CPaneDivider *this, CPoint *ptOffset, int __formal)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  int v6; // ebx
  HWND v7; // eax
  CWnd *v8; // eax
  unsigned int m_dwDividerStyle; // eax
  bool v10; // zf
  int x; // ebx
  HWND__ *m_hWnd; // [esp-4h] [ebp-2Ch]
  void *hdwp; // [esp+Ch] [ebp-1Ch] BYREF
  CPoint *v14; // [esp+10h] [ebp-18h]
  CRect rectSlider; // [esp+14h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  v14 = ptOffset;
  Parent = GetParent(hWnd: m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  memset(&rectSlider, 0, sizeof(rectSlider));
  v6 = CWnd::GetExStyle(this: v5) & 0x400000;
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectSlider);
  v7 = GetParent(hWnd: this->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: v7);
  CWnd::ScreenToClient(this: v8, lpRect: &rectSlider);
  m_dwDividerStyle = this->m_dwDividerStyle;
  if ( (m_dwDividerStyle & 2) != 0 )
  {
    v10 = v6 == 0;
    x = v14->x;
    if ( !v10 )
      x = -x;
    OffsetRect(lprc: &rectSlider, dx: x, dy: 0);
  }
  else
  {
    if ( (m_dwDividerStyle & 1) == 0 )
      return;
    x = v14->y;
    OffsetRect(lprc: &rectSlider, dx: 0, dy: x);
  }
  hdwp = BeginDeferWindowPos(nNumWindows: 50);
  if ( this->m_pContainerManager != nullptr )
    this->m_pContainerManager->OnPaneDividerMove(this: this->m_pContainerManager, a2: this, a3: 0, a4: x, a5: &hdwp);
  EndDeferWindowPos(hWinPosInfo: hdwp);
  this->AdjustDockingLayout(this, a2: nullptr);
  this->SetWindowPos(
    this,
    a2: nullptr,
    a3: rectSlider.left,
    a4: rectSlider.top,
    a5: rectSlider.right - rectSlider.left,
    a6: rectSlider.bottom - rectSlider.top,
    a7: 20u,
    a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00495AB0
// Name: public: virtual void CPaneDivider::RemovePane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::RemovePane(CPaneDivider *this, CDockablePane *pBar)
{
  if ( this->m_pContainerManager != nullptr )
  {
    this->m_pContainerManager->RemovePaneFromPaneContainer(this: this->m_pContainerManager, a2: pBar);
    CBasePane::RemovePaneFromDockManager(
      this,
      pBar: &pBar->CPane,
      bDestroy: 0,
      bAdjustLayout: 0,
      bAutoHide: this->m_bAutoHideMode,
      pBarReplacement: nullptr);
    if ( !CPaneContainerManager::IsEmpty(this: this->m_pContainerManager)
      || CPaneContainerManager::GetTotalRefCount(this: this->m_pContainerManager) != 0
      || CRecentDockSiteInfo::GetRecentDefaultPaneDivider(this: &pBar->m_recentDockInfo) == this )
    {
      if ( this->CheckVisibility(this) == 0 )
        CWnd::ShowWindow(this, nCmdShow: 0);
    }
    else
    {
      CBasePane::RemovePaneFromDockManager(
        this,
        pBar: this,
        bDestroy: 1,
        bAdjustLayout: 0,
        bAutoHide: this->m_bAutoHideMode,
        pBarReplacement: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495B42
// Name: public: virtual class CSize CPaneDivider::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPaneDivider::CalcFixedLayout(CPaneDivider *this, CSize *result, int __formal, int a4)
{
  int v5; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  CRect rectContainer; // [esp+Ch] [ebp-24h] BYREF
  CRect rectWnd; // [esp+1Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  rectContainer.left = 0;
  result->cx = rectWnd.right - rectWnd.left;
  rectContainer.top = 0;
  result->cy = rectWnd.bottom - rectWnd.top;
  rectContainer.right = 0;
  rectContainer.bottom = 0;
  if ( this->m_pContainerManager != nullptr )
  {
    this->m_pContainerManager->GetWindowRect(this: this->m_pContainerManager, a2: &rectContainer);
    v5 = rectContainer.bottom - rectContainer.top;
    result->cx += rectContainer.right - rectContainer.left;
    result->cy += v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495BD1
// Name: protected: int CPaneDivider::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::OnCreate(CPaneDivider *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( afxGlobalData.m_hcurStretch == nullptr )
    {
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      afxGlobalData.m_hcurStretch = LoadCursorW(
                                      hInstance: ModuleState->m_hCurrentResourceHandle,
                                      lpCursorName: (LPCWSTR)0x7904);
    }
    if ( afxGlobalData.m_hcurStretchVert == nullptr )
    {
      AfxGetModuleState();
      v4 = AfxGetModuleState();
      afxGlobalData.m_hcurStretchVert = LoadCursorW(
                                          hInstance: v4->m_hCurrentResourceHandle,
                                          lpCursorName: (LPCWSTR)0x7905);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495C32
// Name: public: static class CObject __near * CPaneDivider::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__stdcall CPaneDivider::CreateObject()
{
  CPaneDivider *v0; // ecx
  CPaneDivider *result; // eax

  v0 = (CPaneDivider *)operator new(nSize: 0x15Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CPaneDivider::CPaneDivider(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D66ED
// Name: public: void CMFCDragFrameImpl::ResetState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::ResetState(CMFCDragFrameImpl *this)
{
  this->m_ptHot.x = -1;
  this->m_ptHot.y = -1;
  SetRectEmpty(lprc: &this->m_rectDrag);
  SetRectEmpty(lprc: &this->m_rectExpectedDocked);
  this->m_nInsertedTabID = -1;
  this->m_pFinalTargetBar = nullptr;
  this->m_pOldTargetBar = nullptr;
  this->m_bDockToTab = 0;
  this->m_bDragStarted = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D6725
// Name: protected: virtual struct AFX_MSGMAP const __near * CDummyDockablePane::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDummyDockablePane::GetMessageMap(CDummyDockablePane *this)
{
  return (const AFX_MSGMAP *)&off_5446D0;
}

//------------------------------------------------------------------------------
// Address: 0x004D674C
// Name: protected: void CMFCDragFrameImpl::DrawDragFrame(struct tagRECT const __near *,struct tagRECT const __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::DrawDragFrame(
        CMFCDragFrameImpl *this,
        const tagRECT *lpRectOld,
        const tagRECT *lpRectNew,
        int bFirstTime,
        int nNewThickness,
        int nOldThikness)
{
  HWND DesktopWindow; // eax
  CWnd *v8; // eax
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // esi
  tagSIZE v11; // [esp-1Ch] [ebp-4Ch]
  const tagRECT *v12; // [esp-14h] [ebp-44h]
  CRect v13; // [esp-10h] [ebp-40h] BYREF
  CWindowDC dc; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+2Ch] [ebp-4h]

  DesktopWindow = GetDesktopWindow();
  v8 = CWnd::FromHandle(hWnd: DesktopWindow);
  CWindowDC::CWindowDC(this: &dc, pWnd: v8);
  m_pDockManager = this->m_pDockManager;
  v15 = 0;
  if ( m_pDockManager != nullptr
    && (m_pSDManager = m_pDockManager->m_pSDManager) != nullptr
    && m_pSDManager->m_bCreated != 0
    && m_pSDManager->m_bStarted != 0 )
  {
    CopyRect(lprcDst: &v13, lprcSrc: lpRectNew);
    CSmartDockingManager::ShowPlaceAt(this: m_pSDManager, rect: v13);
  }
  else
  {
    v13.bottom = 0;
    v13.right = 0;
    v13.top = nOldThikness;
    v13.left = nOldThikness;
    if ( bFirstTime != 0 )
      v12 = nullptr;
    else
      v12 = lpRectOld;
    v11.cy = nNewThickness;
    v11.cx = nNewThickness;
    CDC::DrawDragRect(
      this: &dc,
      lpRect: lpRectNew,
      size: v11,
      lpRectLast: v12,
      sizeLast: *(tagSIZE *)&v13.left,
      pBrush: (CBrush *)v13.right,
      pBrushLast: (CBrush *)v13.bottom);
  }
  v15 = -1;
  CWindowDC::~CWindowDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x004D67E0
// Name: protected: void CMFCDragFrameImpl::DrawFrameTab(class CDockablePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::DrawFrameTab(CMFCDragFrameImpl *this, CDockablePane *pTargetBar, int bErase)
{
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // eax
  int m_nDragFrameThicknessDock; // ebx
  int v7; // edi
  int bottom; // eax
  CRect v9; // [esp-1Ch] [ebp-78h] BYREF
  int v10; // [esp-Ch] [ebp-68h]
  HWND m_hWnd; // [esp-8h] [ebp-64h]
  CRect *p_rectWnd; // [esp-4h] [ebp-60h]
  CMFCDragFrameImpl *v13; // [esp+Ch] [ebp-50h]
  int bSDockingIsOn; // [esp+10h] [ebp-4Ch]
  CSmartDockingManager *pSDManager; // [esp+14h] [ebp-48h]
  CRect rectLine; // [esp+18h] [ebp-44h] BYREF
  CRect rectEmpty; // [esp+28h] [ebp-34h] BYREF
  CRect rectWnd; // [esp+38h] [ebp-24h] BYREF
  CRect rectSmallTab; // [esp+48h] [ebp-14h] BYREF

  p_rectWnd = &rectWnd;
  m_hWnd = pTargetBar->m_hWnd;
  v13 = this;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  m_pDockManager = this->m_pDockManager;
  pSDManager = nullptr;
  bSDockingIsOn = 0;
  if ( m_pDockManager != nullptr )
  {
    m_pSDManager = m_pDockManager->m_pSDManager;
    pSDManager = m_pSDManager;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
      bSDockingIsOn = m_pSDManager->m_bStarted != 0;
  }
  m_nDragFrameThicknessDock = afxGlobalData.m_nDragFrameThicknessDock;
  rectSmallTab.top = rectWnd.top;
  rectSmallTab.right = rectWnd.right;
  rectSmallTab.bottom = rectWnd.bottom;
  rectSmallTab.left = rectWnd.left + 10;
  v7 = 0;
  if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
  {
    rectWnd.top += afxGlobalData.m_nTextHeightHorz;
    rectSmallTab.bottom = rectSmallTab.top + afxGlobalData.m_nTextHeightHorz;
  }
  else
  {
    rectWnd.bottom -= afxGlobalData.m_nTextHeightHorz;
    rectSmallTab.top = rectSmallTab.bottom - afxGlobalData.m_nTextHeightHorz;
  }
  rectSmallTab.right = rectSmallTab.left + 40;
  if ( rectSmallTab.left + 40 >= rectWnd.right )
    rectSmallTab.right = rectWnd.right - afxGlobalData.m_nDragFrameThicknessDock - 4;
  memset(&rectEmpty, 0, sizeof(rectEmpty));
  SetRectEmpty(lprc: &rectEmpty);
  bottom = rectSmallTab.bottom;
  memset(&rectLine, 0, sizeof(rectLine));
  if ( CTabbedPane::m_bTabsAlwaysTop == 0 )
    bottom = rectSmallTab.top;
  SetRect(
    lprc: &rectLine,
    xLeft: m_nDragFrameThicknessDock + rectSmallTab.left,
    yTop: bottom - m_nDragFrameThicknessDock,
    xRight: rectSmallTab.right - m_nDragFrameThicknessDock,
    yBottom: bottom + m_nDragFrameThicknessDock);
  if ( bErase != 0 )
  {
    if ( bSDockingIsOn != 0 )
    {
      CSmartDockingManager::HidePlace(this: pSDManager);
      return;
    }
  }
  else
  {
    if ( bSDockingIsOn != 0 )
    {
      p_rectWnd = (CRect *)(rectSmallTab.bottom - rectSmallTab.top);
      m_hWnd = (HWND)(rectSmallTab.right - rectSmallTab.left);
      v10 = 10;
      CopyRect(lprcDst: &v9, lprcSrc: &rectWnd);
      CSmartDockingManager::ShowTabbedPlaceAt(
        this: pSDManager,
        rect: v9,
        nTabXOffset: v10,
        nTabWidth: (int)m_hWnd,
        nTabHeight: (int)p_rectWnd);
      return;
    }
    v7 = 1;
  }
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectSmallTab,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectWnd,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectLine,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  v13->m_bFrameTabDrawn = v7;
}

//------------------------------------------------------------------------------
// Address: 0x004D6974
// Name: public: void CMFCDragFrameImpl::RemoveTabPreDocking(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::RemoveTabPreDocking(CMFCDragFrameImpl *this, CDockablePane *pOldTargetBar)
{
  CDockablePane *m_pOldTargetBar; // ebx
  CObject *v4; // edi
  CDockablePane *m_pWndDummy; // ecx
  CDockingManager *m_pDockManager; // eax
  BOOL v7; // ebx
  CSmartDockingManager *m_pSDManager; // eax
  int v9; // eax
  int v10; // eax
  CSmartDockingManager *v11; // eax

  m_pOldTargetBar = pOldTargetBar;
  if ( (pOldTargetBar != nullptr || (m_pOldTargetBar = this->m_pOldTargetBar) != nullptr)
    && this->m_nInsertedTabID != -1 )
  {
    v4 = AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: &m_pOldTargetBar->CPane);
    if ( v4 != nullptr
      && this->m_bFrameTabDrawn == 0
      && (m_pWndDummy = this->m_pWndDummy) != nullptr
      && m_pWndDummy->m_hWnd != nullptr )
    {
      m_pDockManager = this->m_pDockManager;
      v7 = false;
      if ( m_pDockManager != nullptr )
      {
        m_pSDManager = m_pDockManager->m_pSDManager;
        if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
          v7 = m_pSDManager->m_bStarted != 0;
      }
      CWnd::ShowWindow(this: &m_pWndDummy->CPane, nCmdShow: 0);
      if ( !v7 )
        CDockingManager::LockUpdate(this: this->m_pDockManager, bLock: 0);
      v9 = ((int (__thiscall *)(CObject *))v4->__vftable[77].Serialize)(a1: v4);
      if ( (CDockablePane *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v9 + 428))(a1: v9, a2: this->m_nInsertedTabID) == this->m_pWndDummy )
      {
        v10 = ((int (__thiscall *)(CObject *))v4->__vftable[77].Serialize)(a1: v4);
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 404))(a1: v10, a2: this->m_nInsertedTabID, a3: 1);
      }
      if ( !v7 )
        CDockingManager::LockUpdate(this: this->m_pDockManager, bLock: 1);
    }
    else
    {
      CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: m_pOldTargetBar, bErase: 1);
    }
    v11 = this->m_pDockManager->m_pSDManager;
    if ( v11 != nullptr && v11->m_bCreated != 0 && v11->m_bStarted != 0 )
      CWnd::ShowWindow(this: this->m_pDraggedWnd, nCmdShow: 5);
  }
  this->m_nInsertedTabID = -1;
  this->m_pOldTargetBar = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D6A7A
// Name: public: void CMFCDragFrameImpl::EndDrawDragFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::EndDrawDragFrame(CMFCDragFrameImpl *this, int bClearInternalRects)
{
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // ecx
  CRect *p_m_rectExpectedDocked; // esi
  int *p_top; // esi
  CDockingManager *v7; // ebx
  int bSDockingIsOn; // [esp+8h] [ebp-28h]
  CRect rectDocked; // [esp+Ch] [ebp-24h] BYREF
  CRect rectEmpty; // [esp+1Ch] [ebp-14h] BYREF

  m_pDockManager = this->m_pDockManager;
  if ( m_pDockManager != nullptr )
  {
    m_pSDManager = m_pDockManager->m_pSDManager;
    bSDockingIsOn = 0;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
    {
      bSDockingIsOn = 1;
      CSmartDockingManager::HidePlace(this: m_pSDManager);
    }
    memset(&rectEmpty, 0, sizeof(rectEmpty));
    SetRectEmpty(lprc: &rectEmpty);
    p_m_rectExpectedDocked = &this->m_rectExpectedDocked;
    if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      p_m_rectExpectedDocked = &this->m_rectDrag;
    rectDocked.left = p_m_rectExpectedDocked->left;
    p_top = &p_m_rectExpectedDocked->top;
    rectDocked.top = *p_top++;
    rectDocked.right = *p_top;
    rectDocked.bottom = p_top[1];
    if ( this->m_nInsertedTabID == -1 )
    {
      if ( bSDockingIsOn == 0 )
        CMFCDragFrameImpl::DrawDragFrame(
          this,
          lpRectOld: &rectEmpty,
          lpRectNew: &rectDocked,
          bFirstTime: 0,
          nNewThickness: this->m_nOldThickness,
          nOldThikness: 4);
    }
    else
    {
      this->m_bDockToTab = 1;
    }
    if ( bClearInternalRects != 0 )
    {
      CMFCDragFrameImpl::RemoveTabPreDocking(this, pOldTargetBar: nullptr);
      SetRectEmpty(lprc: &this->m_rectExpectedDocked);
      SetRectEmpty(lprc: &this->m_rectDrag);
      this->m_pFinalTargetBar = this->m_pTargetBar;
      this->m_pTargetBar = nullptr;
    }
    this->m_bDragStarted = 0;
    v7 = this->m_pDockManager;
    if ( v7 == nullptr )
      AfxThrowInvalidArgException();
    if ( bSDockingIsOn == 0 )
      CDockingManager::LockUpdate(this: v7, bLock: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6B6F
// Name: public: void CMFCDragFrameImpl::PlaceTabPreDocking(class CBaseTabbedPane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::PlaceTabPreDocking(
        CMFCDragFrameImpl *this,
        CBaseTabbedPane *pTabbedBar,
        int bFirstTime)
{
  HWND__ *m_hWnd; // ebx
  ATL::IAtlStringMgr *StringManager; // eax
  CWnd *m_pDraggedWnd; // ecx
  CObject *v7; // eax
  CWnd *v8; // eax
  CDockablePane *v9; // eax
  CDockablePane *v10; // edi
  CDockablePane *v11; // eax
  CWnd *v12; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CMFCBaseTabCtrl *v14; // eax
  CSmartDockingManager *m_pSDManager; // eax
  CMFCBaseTabCtrl *v16; // eax
  CDockablePane *m_pWndDummy; // edx
  int v18; // eax
  ATL::CStringData *v19; // ecx
  ATL::CSimpleStringT<char,0> v20; // [esp+18h] [ebp-24h] BYREF
  _DWORD v21[7]; // [esp+1Ch] [ebp-20h] BYREF
  int v22; // [esp+38h] [ebp-4h]

  if ( this->m_nInsertedTabID == -1 )
  {
    m_hWnd = nullptr;
    if ( bFirstTime == 0 )
      CMFCDragFrameImpl::EndDrawDragFrame(this, bClearInternalRects: 0);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v20, pStringMgr: StringManager);
    m_pDraggedWnd = this->m_pDraggedWnd;
    v22 = 0;
    if ( CObject::IsKindOf(this: m_pDraggedWnd, pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd) != 0 )
    {
      v7 = AfxDynamicDownCast(pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd, pObject: this->m_pDraggedWnd);
      if ( v7 != nullptr )
      {
        v8 = (CWnd *)((int (__thiscall *)(CObject *))v7->__vftable[35].dtr_CObject)(a1: v7);
        if ( v8 != nullptr )
          CWnd::GetWindowTextA(
            this: v8,
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
      }
    }
    else
    {
      CWnd::GetWindowTextA(
        this: this->m_pDraggedWnd,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
    }
    if ( this->m_pWndDummy == nullptr )
    {
      v9 = (CDockablePane *)operator new(nSize: 0x350u);
      v10 = v9;
      LOBYTE(v22) = 1;
      if ( v9 != nullptr )
      {
        CDockablePane::CDockablePane(this: v9);
        v10->__vftable = (CDockablePane_vtbl *)&CDummyDockablePane::`vftable';
        v11 = v10;
      }
      else
      {
        v11 = nullptr;
      }
      v12 = this->m_pDraggedWnd;
      this->m_pWndDummy = v11;
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
      LOBYTE(v22) = 0;
      memset(v21, 0, 16);
      if ( g_pTopLevelFrame == nullptr )
        TopLevelFrame = CWnd::GetTopLevelFrame(this: v12);
      this->m_pWndDummy->CreateEx(
        this: this->m_pWndDummy,
        a2: 0,
        a3: szGroupName,
        a4: TopLevelFrame,
        a5: (const tagRECT *)v21,
        a6: 0,
        a7: AFX_DUMMY_WND_ID,
        a8: 0x40000000u,
        a9: 32u,
        a10: 15u,
        a11: nullptr);
    }
    v14 = pTabbedBar->GetUnderlyingWindow(this: pTabbedBar);
    v14->AddTab(this: v14, a2: &this->m_pWndDummy->CPane, a3: v20.m_pszData, a4: -1u, a5: 1);
    m_pSDManager = this->m_pDockManager->m_pSDManager;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
      CWnd::ShowWindow(this: this->m_pDraggedWnd, nCmdShow: 0);
    v16 = pTabbedBar->GetUnderlyingWindow(this: pTabbedBar);
    m_pWndDummy = this->m_pWndDummy;
    if ( m_pWndDummy != nullptr )
      m_hWnd = m_pWndDummy->m_hWnd;
    v18 = v16->GetTabFromHwnd(this: v16, a2: m_hWnd);
    v19 = (ATL::CStringData *)(v20.m_pszData - 16);
    this->m_nInsertedTabID = v18;
    this->m_pOldTargetBar = pTabbedBar;
    ATL::CStringData::Release(this: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6CE1
// Name: public: void CMFCDragFrameImpl::PlaceTabPreDocking(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::PlaceTabPreDocking(CMFCDragFrameImpl *this, CWnd *pCBarToPlaceOn)
{
  CBaseTabbedPane *v3; // edi
  CDockablePane *v4; // eax
  CDockablePane *v5; // edi

  v3 = (CBaseTabbedPane *)AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: pCBarToPlaceOn);
  if ( v3 != nullptr
    && (v3->GetVisibleTabsNum(this: v3) > 1 && v3->IsHideSingleTab(this: v3) != 0
     || v3->GetVisibleTabsNum(this: v3) > 0 && v3->IsHideSingleTab(this: v3) == 0) )
  {
    this->m_pTargetBar = v3;
    CMFCDragFrameImpl::PlaceTabPreDocking(this, pTabbedBar: v3, bFirstTime: 1);
  }
  else if ( this->m_nInsertedTabID == -1 )
  {
    v4 = (CDockablePane *)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: pCBarToPlaceOn);
    v5 = v4;
    if ( v4 != nullptr )
    {
      CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: v4, bErase: 0);
      this->m_pTargetBar = v5;
      this->m_pOldTargetBar = v5;
      this->m_nInsertedTabID = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6D7F
// Name: public: void CMFCDragFrameImpl::MoveDragFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::MoveDragFrame(CMFCDragFrameImpl *this, int bForceMove)
{
  CDockablePane *v3; // eax
  CDockablePane *v4; // esi
  CDockablePane *v5; // eax
  CWnd *m_pDraggedWnd; // ecx
  CFrameWnd *TopLevelFrame; // eax
  int v8; // esi
  CDockingManager *m_pDockManager; // ecx
  CRect *p_m_rectExpectedDocked; // esi
  int *p_top; // esi
  CObject *v12; // esi
  CDockablePane **p_m_pTargetBar; // edi
  CDockingManager *v14; // ecx
  CSmartDockingManager *m_pSDManager; // eax
  CWnd *v16; // ecx
  CObject *v17; // eax
  CBaseTabbedPane *v18; // esi
  bool v19; // zf
  CDockablePane *m_nDragFrameThicknessFloat; // eax
  CRect *p_m_rectDrag; // esi
  int *v22; // esi
  CDockablePane *v23; // esi
  int v24; // [esp+10h] [ebp-74h]
  int dy; // [esp+14h] [ebp-70h]
  BOOL p; // [esp+1Ch] [ebp-68h]
  int bDrawTab; // [esp+20h] [ebp-64h] BYREF
  int bFirstTime; // [esp+24h] [ebp-60h]
  tagPOINT Point; // [esp+28h] [ebp-5Ch] BYREF
  CDockablePane *pOldTargetBar; // [esp+30h] [ebp-54h]
  tagRECT RectOld; // [esp+34h] [ebp-50h] BYREF
  _DWORD v32[4]; // [esp+44h] [ebp-40h] BYREF
  tagRECT RectNew; // [esp+54h] [ebp-30h] BYREF
  tagRECT rc; // [esp+64h] [ebp-20h] BYREF
  int v35; // [esp+80h] [ebp-4h]
  CSize v36; // 0:^40.8

  this->m_pFinalTargetBar = nullptr;
  if ( this->m_pDraggedWnd != nullptr && this->m_pDockManager != nullptr )
  {
    if ( this->m_pWndDummy == nullptr )
    {
      v3 = (CDockablePane *)operator new(nSize: 0x350u);
      v4 = v3;
      v35 = 0;
      if ( v3 != nullptr )
      {
        CDockablePane::CDockablePane(this: v3);
        v4->__vftable = (CDockablePane_vtbl *)&CDummyDockablePane::`vftable';
        v5 = v4;
      }
      else
      {
        v5 = nullptr;
      }
      v35 = -1;
      m_pDraggedWnd = this->m_pDraggedWnd;
      this->m_pWndDummy = v5;
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
      memset(v32, 0, sizeof(v32));
      if ( g_pTopLevelFrame == nullptr )
        TopLevelFrame = CWnd::GetTopLevelFrame(this: m_pDraggedWnd);
      this->m_pWndDummy->CreateEx(
        this: this->m_pWndDummy,
        a2: 0,
        a3: szGroupName,
        a4: TopLevelFrame,
        a5: (const tagRECT *)v32,
        a6: 0,
        a7: AFX_DUMMY_WND_ID,
        a8: 0x40000000u,
        a9: 32u,
        a10: 15u,
        a11: nullptr);
    }
    v36 = CDockablePane::m_sizeDragSensitivity;
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    v8 = Point.y - this->m_ptHot.y;
    v24 = Point.x - this->m_ptHot.x;
    dy = v8;
    if ( abs(lnumber: v24) >= v36.cx
      || abs(lnumber: v8) >= v36.cy
      || !IsRectEmpty(lprc: &this->m_rectDrag)
      || bForceMove != 0 )
    {
      m_pDockManager = this->m_pDockManager;
      this->m_bDragStarted = 1;
      CDockingManager::LockUpdate(this: m_pDockManager, bLock: 1);
      p_m_rectExpectedDocked = &this->m_rectExpectedDocked;
      if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
        p_m_rectExpectedDocked = &this->m_rectDrag;
      bFirstTime = 0;
      RectOld.left = p_m_rectExpectedDocked->left;
      p_top = &p_m_rectExpectedDocked->top;
      RectOld.top = *p_top++;
      RectOld.right = *p_top;
      RectOld.bottom = p_top[1];
      if ( IsRectEmpty(lprc: &this->m_rectDrag) )
      {
        if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
        {
          GetWindowRect(hWnd: this->m_pDraggedWnd->m_hWnd, lpRect: &this->m_rectDrag);
        }
        else if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) != 0 )
        {
          v12 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
          GetWindowRect(hWnd: this->m_pDraggedWnd->m_hWnd, lpRect: &this->m_rectDrag);
          if ( ((int (__thiscall *)(CObject *, _DWORD))v12->__vftable[45].Serialize)(a1: v12, a2: 0) == 0 )
          {
            this->m_rectDrag.right = this->m_rectDrag.left + (char *)v12[120].__vftable - (char *)v12[118].__vftable;
            this->m_rectDrag.bottom = this->m_rectDrag.top + (char *)v12[121].__vftable - (char *)v12[119].__vftable;
          }
          if ( !PtInRect(lprc: &this->m_rectDrag, pt: this->m_ptHot.tagPOINT) )
            OffsetRect(lprc: &this->m_rectDrag, dx: this->m_ptHot.x - this->m_rectDrag.left - 5, dy: 0);
        }
        bFirstTime = 1;
      }
      bDrawTab = 0;
      p_m_pTargetBar = &this->m_pTargetBar;
      pOldTargetBar = this->m_pTargetBar;
      memset((void *)&rc, 0, sizeof(rc));
      SetRectEmpty(lprc: &rc);
      v14 = this->m_pDockManager;
      p = false;
      if ( v14 != nullptr )
      {
        m_pSDManager = v14->m_pSDManager;
        if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
          p = m_pSDManager->m_bStarted != 0;
      }
      CDockingManager::CalcExpectedDockedRect(
        this: v14,
        pWnd: this->m_pDraggedWnd,
        ptMouse: (CPoint)Point,
        rectResult: (CRect *)&rc,
        &bDrawTab,
        ppTargetBar: p_m_pTargetBar);
      if ( pOldTargetBar != nullptr
        && this->m_nInsertedTabID != -1
        && (pOldTargetBar != *p_m_pTargetBar || bDrawTab == 0) )
      {
        CMFCDragFrameImpl::RemoveTabPreDocking(this, pOldTargetBar);
        bFirstTime = 1;
      }
      v16 = this->m_pDraggedWnd;
      pOldTargetBar = (CDockablePane *)1;
      if ( CObject::IsKindOf(this: v16, pClass: &CPaneFrameWnd::classCPaneFrameWnd) == 0
        && CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) != 0 )
      {
        v17 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
        pOldTargetBar = (CDockablePane *)((int (__thiscall *)(CObject *))v17->__vftable[32].Serialize)(a1: v17);
      }
      if ( *p_m_pTargetBar != nullptr && pOldTargetBar != nullptr )
      {
        v18 = (CBaseTabbedPane *)AfxDynamicDownCast(
                                   pClass: &CBaseTabbedPane::classCBaseTabbedPane,
                                   pObject: &(*p_m_pTargetBar)->CPane);
        if ( v18 == nullptr )
          goto LABEL_46;
        if ( bDrawTab != 0 )
        {
          if ( v18->GetVisibleTabsNum(this: v18) > 1 && v18->IsHideSingleTab(this: v18) != 0
            || v18->GetVisibleTabsNum(this: v18) > 0 && v18->IsHideSingleTab(this: v18) == 0 )
          {
            CMFCDragFrameImpl::PlaceTabPreDocking(this, pTabbedBar: v18, bFirstTime);
            return;
          }
LABEL_46:
          if ( bDrawTab != 0 )
          {
            if ( this->m_nInsertedTabID == -1 )
            {
              if ( bFirstTime == 0 )
                CMFCDragFrameImpl::EndDrawDragFrame(this, bClearInternalRects: 0);
              CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: *p_m_pTargetBar, bErase: 0);
              this->m_nInsertedTabID = 1;
            }
            return;
          }
        }
      }
      OffsetRect(lprc: &this->m_rectDrag, dx: v24, dy);
      this->m_ptHot = (CPoint)Point;
      this->m_rectExpectedDocked = (CRect)rc;
      v19 = !IsRectEmpty(lprc: &this->m_rectExpectedDocked);
      m_nDragFrameThicknessFloat = (CDockablePane *)afxGlobalData.m_nDragFrameThicknessFloat;
      if ( v19 )
        m_nDragFrameThicknessFloat = (CDockablePane *)afxGlobalData.m_nDragFrameThicknessDock;
      pOldTargetBar = m_nDragFrameThicknessFloat;
      p_m_rectDrag = &this->m_rectExpectedDocked;
      memset((void *)&RectNew, 0, sizeof(RectNew));
      if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      {
        p_m_rectDrag = &this->m_rectDrag;
        if ( !PtInRect(lprc: &this->m_rectDrag, pt: Point) )
          OffsetRect(
            lprc: &this->m_rectDrag,
            dx: Point.x - (p_m_rectDrag->left + (this->m_rectDrag.right - this->m_rectDrag.left) / 2),
            dy: Point.y - (this->m_rectDrag.top + 5));
      }
      RectNew.left = p_m_rectDrag->left;
      v22 = &p_m_rectDrag->top;
      RectNew.top = *v22++;
      RectNew.right = *v22;
      RectNew.bottom = v22[1];
      if ( !p || !IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      {
        v23 = pOldTargetBar;
        CMFCDragFrameImpl::DrawDragFrame(
          this,
          lpRectOld: &RectOld,
          lpRectNew: &RectNew,
          bFirstTime,
          nNewThickness: (int)pOldTargetBar,
          nOldThikness: this->m_nOldThickness);
        this->m_nOldThickness = (int)v23;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D71B2
// Name: public: CMFCCaptionMenuButton::CMFCCaptionMenuButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionMenuButton *__thiscall CMFCCaptionMenuButton::CMFCCaptionMenuButton(CMFCCaptionMenuButton *this)
{
  CMFCCaptionButton::CMFCCaptionButton(this);
  this->m_nMenuResult = 0;
  this->m_bMenuIsActive = 0;
  this->__vftable = (CMFCCaptionMenuButton_vtbl *)&CMFCCaptionMenuButton::`vftable';
  this->m_bOSMenu = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D71D5
// Name: public: CMFCCaptionMenuButton::CMFCCaptionMenuButton(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionMenuButton *__thiscall CMFCCaptionMenuButton::CMFCCaptionMenuButton(
        CMFCCaptionMenuButton *this,
        unsigned int nHit,
        int bLeftAlign)
{
  CMFCCaptionButton::CMFCCaptionButton(this, nHit, bLeftAlign);
  this->m_nMenuResult = 0;
  this->m_bMenuIsActive = 0;
  this->__vftable = (CMFCCaptionMenuButton_vtbl *)&CMFCCaptionMenuButton::`vftable';
  this->m_bOSMenu = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D722B
// Name: public: virtual void CMFCCaptionMenuButton::OnDraw(class CDC __near *,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionMenuButton::OnDraw(
        CMFCCaptionMenuButton *this,
        CDC *pDC,
        int bActive,
        int bHorz,
        int bMaximized,
        int bDisabled)
{
  CMFCVisualManager *Instance; // eax

  if ( this->m_bHidden == 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    Instance->OnDrawCaptionButton(
      this: Instance,
      a2: pDC,
      a3: this,
      a4: bActive,
      a5: bHorz,
      a6: bMaximized,
      a7: bDisabled,
      a8: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D725C
// Name: public: void CMFCCaptionMenuButton::ShowMenu(struct HMENU__ __near *,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionMenuButton::ShowMenu(CMFCCaptionMenuButton *this, HMENU__ *hMenu, CWnd *pWndOwner)
{
  int v4; // ebx
  int v5; // ebx
  CRect *v6; // eax
  int v7; // eax
  CMFCCaptionMenuButton_vtbl *v8; // eax
  const RECT *v9; // eax
  CPoint point; // [esp+10h] [ebp-2Ch] BYREF
  CRect v11; // [esp+18h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+28h] [ebp-14h] BYREF

  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: pWndOwner->m_hWnd, lpRect: &rectWnd);
  CMFCCaptionButton::GetSize(result: (CSize *)&point);
  v4 = rectWnd.left + this->m_ptOrg.x;
  point.y += rectWnd.top + this->m_ptOrg.y;
  v5 = point.x + v4;
  this->m_bMenuIsActive = 1;
  this->m_bPushed = 1;
  v6 = this->GetRect(this, result: &v11);
  InvalidateRect(hWnd: pWndOwner->m_hWnd, lpRect: v6, bErase: true);
  SendMessageA(hWnd: pWndOwner->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
  if ( this->m_bOSMenu != 0 || afxContextMenuManager == nullptr )
    v7 = TrackPopupMenu(
           hMenu,
           uFlags: 0x180u,
           x: v5,
           y: point.y,
           nReserved: 0,
           hWnd: pWndOwner->m_hWnd,
           prcRect: nullptr);
  else
    v7 = afxContextMenuManager->TrackPopupMenu(
           this: afxContextMenuManager,
           a2: hMenu,
           a3: v5,
           a4: point.y,
           a5: pWndOwner,
           a6: 1);
  this->m_nMenuResult = v7;
  v8 = this->__vftable;
  this->m_bMenuIsActive = 0;
  this->m_bPushed = 0;
  v9 = v8->GetRect(this, result: &v11);
  InvalidateRect(hWnd: pWndOwner->m_hWnd, lpRect: v9, bErase: true);
  SendMessageA(hWnd: pWndOwner->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004D7364
// Name: public: virtual struct CRuntimeClass __near * CBaseTabbedPane::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBaseTabbedPane::GetRuntimeClass(CBaseTabbedPane *this)
{
  return &CBaseTabbedPane::classCBaseTabbedPane;
}

//------------------------------------------------------------------------------
// Address: 0x004D736A
// Name: protected: void CBaseTabbedPane::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBaseTabbedPane::OnNcDestroy(CBaseTabbedPane *this)
{
  CMFCBaseTabCtrl *m_pTabWnd; // ecx

  m_pTabWnd = this->m_pTabWnd;
  if ( m_pTabWnd != nullptr )
  {
    ((void (__thiscall *)(CMFCBaseTabCtrl *, int))m_pTabWnd->dtr_CObject)(a1: m_pTabWnd, a2: 1);
    this->m_pTabWnd = nullptr;
  }
  CPane::OnNcDestroy(this);
  if ( this->m_bAutoDestroy != 0 )
    ((void (__thiscall *)(CBaseTabbedPane *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004D73A4
// Name: public: virtual class CWnd __near * CBaseTabbedPane::FindPaneByID(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CBaseTabbedPane::FindPaneByID(CBaseTabbedPane *this, unsigned int uBarID)
{
  int v3; // edi
  CWnd *v4; // ebx

  v3 = 0;
  if ( this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_pTabWnd->GetTabWnd(this: this->m_pTabWnd, a2: v3);
    if ( CWnd::GetDlgCtrlID(this: v4) == uBarID )
      break;
    if ( ++v3 >= this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004D73FF
// Name: public: virtual class CWnd __near * CBaseTabbedPane::FindBarByTabNumber(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CBaseTabbedPane::FindBarByTabNumber(CBaseTabbedPane *this, int nTabNum, int bGetWrappedBar)
{
  CMFCBaseTabCtrl **p_m_pTabWnd; // esi
  CObject *v4; // eax
  CObject *v5; // edi
  CObject *v6; // eax

  if ( nTabNum < 0 )
    return nullptr;
  p_m_pTabWnd = &this->m_pTabWnd;
  if ( nTabNum >= this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) )
    return nullptr;
  v4 = (*p_m_pTabWnd)->GetTabWnd(this: *p_m_pTabWnd, a2: nTabNum);
  v5 = v4;
  if ( bGetWrappedBar != 0 && CObject::IsKindOf(this: v4, pClass: &CDockablePaneAdapter::classCDockablePaneAdapter) != 0 )
  {
    v6 = AfxDynamicDownCast(pClass: &CDockablePaneAdapter::classCDockablePaneAdapter, pObject: v5);
    return (CWnd *)v6->__vftable[78].GetRuntimeClass(this: v6);
  }
  return (CWnd *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004D7468
// Name: protected: virtual void CBaseTabbedPane::StoreRecentDockSiteInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBaseTabbedPane::StoreRecentDockSiteInfo(CBaseTabbedPane *this)
{
  int v2; // ebx
  int i; // edi
  CWnd *v4; // eax
  CObject *v5; // eax

  v2 = this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd);
  for ( i = 0; i < v2; ++i )
  {
    v4 = this->m_pTabWnd->GetTabWnd(this: this->m_pTabWnd, a2: i);
    v5 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: v4);
    if ( v5 != nullptr )
      v5->__vftable[74].dtr_CObject(this: v5);
  }
  CDockablePane::StoreRecentDockSiteInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EFB5F
// Name: public: class CPaneContainer __near * CRecentDockSiteInfo::GetRecentPaneContainer(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CRecentDockSiteInfo::GetRecentPaneContainer(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_pRecentBarContainer;
  else
    return this->m_recentMiniFrameInfo.m_pRecentBarContainer;
}

//------------------------------------------------------------------------------
// Address: 0x004EFB79
// Name: public: class CPaneContainer __near * CRecentDockSiteInfo::GetRecentTabContainer(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CRecentDockSiteInfo::GetRecentTabContainer(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_pRecentContainerOfTabWnd;
  else
    return this->m_recentMiniFrameInfo.m_pRecentContainerOfTabWnd;
}

//------------------------------------------------------------------------------
// Address: 0x004EFB93
// Name: public: class CRect __near & CRecentDockSiteInfo::GetRecentDockedRect(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CRecentDockSiteInfo::GetRecentDockedRect(CRecentDockSiteInfo *this, int bForSlider)
{
  CRect *result; // eax

  result = &this->m_recentSliderInfo.m_rectDockedRect;
  if ( bForSlider == 0 )
    return &this->m_recentMiniFrameInfo.m_rectDockedRect;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EFBA8
// Name: public: int CRecentDockSiteInfo::GetRecentDockedPercent(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRecentDockSiteInfo::GetRecentDockedPercent(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_nRecentPercent;
  else
    return this->m_recentMiniFrameInfo.m_nRecentPercent;
}

//------------------------------------------------------------------------------
// Address: 0x004EFBC2
// Name: public: int CRecentDockSiteInfo::IsRecentLeftPane(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRecentDockSiteInfo::IsRecentLeftPane(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_bIsRecentLeftBar;
  else
    return this->m_recentMiniFrameInfo.m_bIsRecentLeftBar;
}

//------------------------------------------------------------------------------
// Address: 0x004EFBDC
// Name: public: class CList<struct HWND__ __near *,struct HWND__ __near *> __near & CRecentDockSiteInfo::GetRecentListOfPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HWND__ *,HWND__ *> *__thiscall CRecentDockSiteInfo::GetRecentListOfPanes(
        CRecentDockSiteInfo *this,
        int bForSlider)
{
  CList<HWND__ *,HWND__ *> *result; // eax

  result = &this->m_recentSliderInfo.m_lstRecentListOfBars;
  if ( bForSlider == 0 )
    return &this->m_recentMiniFrameInfo.m_lstRecentListOfBars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EFBF4
// Name: public: class CPaneDivider __near * CRecentDockSiteInfo::GetRecentDefaultPaneDivider(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__thiscall CRecentDockSiteInfo::GetRecentDefaultPaneDivider(CRecentDockSiteInfo *this)
{
  CWnd *v1; // eax

  v1 = CWnd::FromHandlePermanent(hWnd: this->m_hRecentDefaultSlider);
  return (CPaneDivider *)AfxDynamicDownCast(pClass: &CPaneDivider::classCPaneDivider, pObject: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004EFC0A
// Name: public: virtual void CRecentDockSiteInfo::SetInfo(int,class CRecentDockSiteInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::SetInfo(CRecentDockSiteInfo *this, int bForSlider, CRecentDockSiteInfo *srcInfo)
{
  if ( bForSlider != 0 )
  {
    this->m_dwRecentAlignmentToFrame = srcInfo->m_dwRecentAlignmentToFrame;
    this->m_hRecentDefaultSlider = srcInfo->m_hRecentDefaultSlider;
    this->m_recentSliderInfo.SetInfo(this: &this->m_recentSliderInfo, a2: &srcInfo->m_recentSliderInfo);
  }
  else
  {
    this->m_rectRecentFloatingRect = srcInfo->m_rectRecentFloatingRect;
    this->m_hRecentMiniFrame = srcInfo->m_hRecentMiniFrame;
    this->m_recentMiniFrameInfo.SetInfo(this: &this->m_recentMiniFrameInfo, a2: &srcInfo->m_recentMiniFrameInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFC56
// Name: public: CRecentPaneContainerInfo::CRecentPaneContainerInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentPaneContainerInfo *__thiscall CRecentPaneContainerInfo::CRecentPaneContainerInfo(CRecentPaneContainerInfo *this)
{
  this->__vftable = (CRecentPaneContainerInfo_vtbl *)&CRecentPaneContainerInfo::`vftable';
  this->m_rectDockedRect.left = 0;
  this->m_rectDockedRect.top = 0;
  this->m_rectDockedRect.right = 0;
  this->m_rectDockedRect.bottom = 0;
  CList<HWND__ *,HWND__ *>::CList<HWND__ *,HWND__ *>(this: &this->m_lstRecentListOfBars, nBlockSize: 10);
  CRecentPaneContainerInfo::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EFC84
// Name: public: virtual CRecentPaneContainerInfo::~CRecentPaneContainerInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::~CRecentPaneContainerInfo(CRecentPaneContainerInfo *this)
{
  CList<HWND__ *,HWND__ * &> *p_m_lstRecentListOfBars; // ecx

  this->__vftable = (CRecentPaneContainerInfo_vtbl *)&CRecentPaneContainerInfo::`vftable';
  p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_lstRecentListOfBars;
  p_m_lstRecentListOfBars->__vftable = (CList<HWND__ *,HWND__ * &>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: p_m_lstRecentListOfBars);
}

//------------------------------------------------------------------------------
// Address: 0x004EFC98
// Name: public: virtual void CRecentPaneContainerInfo::StoreDockInfo(class CPaneContainer __near *,class CDockablePane __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::StoreDockInfo(
        CRecentPaneContainerInfo *this,
        CPaneContainer *pRecentContainer,
        CDockablePane *pBar,
        CDockablePane *pTabbedBar)
{
  int IsLeftPane; // eax
  CPaneContainer *m_pRecentBarContainer; // eax
  CPaneContainerManager *m_pContainerManager; // ecx
  CPaneContainer *m_pRecentContainerOfTabWnd; // eax
  CPaneContainerManager *v9; // ecx
  CDockablePane *v10; // eax

  if ( pRecentContainer != nullptr )
  {
    CPaneContainer::AddRef(this: pRecentContainer);
    if ( pTabbedBar != nullptr )
      IsLeftPane = CPaneContainer::IsLeftPane(this: pRecentContainer, pBar: pTabbedBar);
    else
      IsLeftPane = CPaneContainer::IsLeftPane(this: pRecentContainer, pBar);
    this->m_bIsRecentLeftBar = IsLeftPane;
  }
  m_pRecentBarContainer = this->m_pRecentBarContainer;
  if ( m_pRecentBarContainer != nullptr && m_pRecentBarContainer->m_bDisposed == 0 )
  {
    m_pContainerManager = m_pRecentBarContainer->m_pContainerManager;
    --m_pRecentBarContainer->m_dwRefCount;
    if ( this->m_pRecentBarContainer->m_dwRefCount <= 0 )
      CPaneContainer::ReleaseEmptyPaneContainer(this: m_pContainerManager->m_pRootContainer);
    this->m_pRecentBarContainer = nullptr;
  }
  m_pRecentContainerOfTabWnd = this->m_pRecentContainerOfTabWnd;
  if ( m_pRecentContainerOfTabWnd != nullptr && m_pRecentContainerOfTabWnd->m_bDisposed == 0 )
  {
    v9 = m_pRecentContainerOfTabWnd->m_pContainerManager;
    --m_pRecentContainerOfTabWnd->m_dwRefCount;
    if ( this->m_pRecentContainerOfTabWnd->m_dwRefCount <= 0 )
      CPaneContainer::ReleaseEmptyPaneContainer(this: v9->m_pRootContainer);
    this->m_pRecentContainerOfTabWnd = nullptr;
  }
  GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &this->m_rectDockedRect);
  v10 = pTabbedBar;
  if ( pTabbedBar != nullptr )
  {
    this->m_pRecentContainerOfTabWnd = pRecentContainer;
  }
  else
  {
    v10 = pBar;
    this->m_pRecentBarContainer = pRecentContainer;
  }
  this->m_nRecentPercent = v10->m_nLastPercent;
}

//------------------------------------------------------------------------------
// Address: 0x004EFD55
// Name: public: CRecentDockSiteInfo::CRecentDockSiteInfo(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentDockSiteInfo *__thiscall CRecentDockSiteInfo::CRecentDockSiteInfo(CRecentDockSiteInfo *this, CPane *pBar)
{
  this->__vftable = (CRecentDockSiteInfo_vtbl *)&CRecentDockSiteInfo::`vftable';
  this->m_rectRecentFloatingRect.left = 0;
  this->m_rectRecentFloatingRect.top = 0;
  this->m_rectRecentFloatingRect.right = 0;
  this->m_rectRecentFloatingRect.bottom = 0;
  CRecentPaneContainerInfo::CRecentPaneContainerInfo(this: &this->m_recentSliderInfo);
  CRecentPaneContainerInfo::CRecentPaneContainerInfo(this: &this->m_recentMiniFrameInfo);
  this->m_pBar = pBar;
  CRecentDockSiteInfo::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EFD98
// Name: public: virtual CRecentDockSiteInfo::~CRecentDockSiteInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::~CRecentDockSiteInfo(CRecentDockSiteInfo *this)
{
  this->__vftable = (CRecentDockSiteInfo_vtbl *)&CRecentDockSiteInfo::`vftable';
  CRecentPaneContainerInfo::~CRecentPaneContainerInfo(this: &this->m_recentMiniFrameInfo);
  CRecentPaneContainerInfo::~CRecentPaneContainerInfo(this: &this->m_recentSliderInfo);
}

//------------------------------------------------------------------------------
// Address: 0x004EFDCD
// Name: public: virtual void CRecentDockSiteInfo::StoreDockInfo(class CPaneContainer __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::StoreDockInfo(
        CRecentDockSiteInfo *this,
        CPaneContainer *pRecentContainer,
        CDockablePane *pTabbedBar)
{
  CObject *v4; // eax
  CDockablePane *v5; // ecx
  CDockablePane *v6; // ebx
  CWnd *v7; // edi
  CWnd *v8; // eax
  CWnd *v9; // eax
  CRecentPaneContainerInfo_vtbl *v10; // edx
  CPaneFrameWnd *pRecentMiniFrame; // [esp+Ch] [ebp-4h]
  CPaneFrameWnd *pRecentMiniFramea; // [esp+Ch] [ebp-4h]

  v4 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: this->m_pBar);
  v5 = pTabbedBar;
  v6 = (CDockablePane *)v4;
  if ( pTabbedBar == nullptr )
    v5 = (CDockablePane *)v4;
  pRecentMiniFrame = (CPaneFrameWnd *)CDockablePane::GetDefaultPaneDivider(this: v5);
  v7 = v6->GetParentMiniFrame(this: &v6->CPane, a2: 0);
  if ( v7 != nullptr )
  {
    v8 = CWnd::FromHandlePermanent(hWnd: this->m_hRecentMiniFrame);
    pRecentMiniFramea = (CPaneFrameWnd *)AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: v8);
    this->m_hRecentMiniFrame = v7->m_hWnd;
    this->m_recentMiniFrameInfo.StoreDockInfo(
      this: &this->m_recentMiniFrameInfo,
      a2: pRecentContainer,
      a3: v6,
      a4: pTabbedBar);
    CWnd::ScreenToClient(this: v7, lpRect: &this->m_recentMiniFrameInfo.m_rectDockedRect);
    GetWindowRect(hWnd: v7->m_hWnd, lpRect: &this->m_rectRecentFloatingRect);
    if ( pRecentMiniFramea != nullptr )
      PostMessageA(hWnd: pRecentMiniFramea->m_hWnd, Msg: AFX_WM_CHECKEMPTYMINIFRAME, wParam: 0, lParam: 0);
  }
  else if ( pRecentMiniFrame != nullptr )
  {
    ((void (__thiscall *)(CRecentPaneContainerInfo *, CPaneContainer *, CDockablePane *))this->m_recentSliderInfo.StoreDockInfo)(
      a1: &this->m_recentSliderInfo,
      a2: pRecentContainer,
      a3: v6);
    v9 = (CWnd *)((int (__thiscall *)(CDockablePane *, CRect *))v6->GetDockSiteFrameWnd)(
                   a1: v6,
                   a2: &this->m_recentSliderInfo.m_rectDockedRect);
    CWnd::ScreenToClient(this: v9, lpRect: (tagRECT *)pTabbedBar);
    this->m_hRecentDefaultSlider = pRecentMiniFrame->m_hWnd;
    this->m_dwRecentAlignmentToFrame = ((int (__thiscall *)(CPaneFrameWnd *))pRecentMiniFrame->OnMovePane)(a1: pRecentMiniFrame);
  }
  else
  {
    v10 = this->m_recentMiniFrameInfo.__vftable;
    this->m_hRecentMiniFrame = nullptr;
    ((void (__stdcall *)(_DWORD, CDockablePane *, _DWORD))v10->StoreDockInfo)(a1: 0, a2: v6, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFF09
// Name: public: void CList<struct HWND__ __near *,struct HWND__ __near *>::AddTail(class CList<struct HWND__ __near *,struct HWND__ __near *> __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<HWND__ *,HWND__ *>::AddTail(
        CList<unsigned long,unsigned long> *this,
        CList<unsigned long,unsigned long> *pNewList)
{
  CList<unsigned long,unsigned long>::CNode *m_pNodeHead; // esi
  CFrameWnd *data; // [esp-4h] [ebp-Ch]

  if ( pNewList == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = pNewList->m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (CFrameWnd *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    CList<CFrameWnd *,CFrameWnd *>::AddTail((CList<CFrameWnd *,CFrameWnd *> *)this, newElement: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFF39
// Name: public: virtual void CRecentPaneContainerInfo::SetInfo(class CRecentPaneContainerInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::SetInfo(CRecentPaneContainerInfo *this, CRecentPaneContainerInfo *srcInfo)
{
  CPaneContainer *m_pRecentBarContainer; // ecx
  CPaneContainer *v4; // ecx
  CPaneContainer *m_pRecentContainerOfTabWnd; // ecx
  CPaneContainer *v6; // ecx

  m_pRecentBarContainer = srcInfo->m_pRecentBarContainer;
  if ( m_pRecentBarContainer != nullptr )
    CPaneContainer::AddRef(this: m_pRecentBarContainer);
  v4 = this->m_pRecentBarContainer;
  if ( v4 != nullptr )
    CPaneContainer::Release(this: v4);
  this->m_pRecentBarContainer = srcInfo->m_pRecentBarContainer;
  this->m_rectDockedRect = srcInfo->m_rectDockedRect;
  this->m_nRecentPercent = srcInfo->m_nRecentPercent;
  m_pRecentContainerOfTabWnd = srcInfo->m_pRecentContainerOfTabWnd;
  if ( m_pRecentContainerOfTabWnd != nullptr )
    CPaneContainer::AddRef(this: m_pRecentContainerOfTabWnd);
  v6 = this->m_pRecentContainerOfTabWnd;
  if ( v6 != nullptr )
    CPaneContainer::Release(this: v6);
  this->m_pRecentContainerOfTabWnd = srcInfo->m_pRecentContainerOfTabWnd;
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstRecentListOfBars);
  CList<HWND__ *,HWND__ *>::AddTail(
    this: (CList<unsigned long,unsigned long> *)&this->m_lstRecentListOfBars,
    pNewList: (CList<unsigned long,unsigned long> *)&srcInfo->m_lstRecentListOfBars);
}

//------------------------------------------------------------------------------
// Address: 0x004EFFB0
// Name: public: void CRecentDockSiteInfo::SaveListOfRecentPanes(class CList<struct HWND__ __near *,struct HWND__ __near *> __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::SaveListOfRecentPanes(
        CRecentDockSiteInfo *this,
        CList<HWND__ *,HWND__ *> *lstOrg,
        int bForSlider)
{
  CList<HWND__ *,HWND__ * &> *p_m_lstRecentListOfBars; // esi

  p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_recentSliderInfo.m_lstRecentListOfBars;
  if ( bForSlider == 0 )
    p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_recentMiniFrameInfo.m_lstRecentListOfBars;
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: p_m_lstRecentListOfBars);
  CList<HWND__ *,HWND__ *>::AddTail(
    this: (CList<unsigned long,unsigned long> *)p_m_lstRecentListOfBars,
    pNewList: (CList<unsigned long,unsigned long> *)lstOrg);
}

//------------------------------------------------------------------------------
// Address: 0x0051C3F6
// Name: public: ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::_ATL_BASE_MODULE70 *__thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(ATL::_ATL_BASE_MODULE70 *this)
{
  memset(dst: (unsigned __int8 *)&this->m_csResource, value: 0, count: sizeof(this->m_csResource));
  this->m_rgResourceInstance.m_aT = nullptr;
  this->m_rgResourceInstance.m_nSize = 0;
  this->m_rgResourceInstance.m_nAllocSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051C41B
// Name: public: ATL::CAtlBaseModule::~CAtlBaseModule(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(ATL::CAtlBaseModule *this)
{
  DeleteCriticalSection(lpCriticalSection: &this->m_csResource.m_sec);
  ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::RemoveAll(this: &this->m_rgResourceInstance);
}

//------------------------------------------------------------------------------
// Address: 0x0051C433
// Name: public: ATL::CAtlBaseModule::CAtlBaseModule(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CAtlBaseModule *__thiscall ATL::CAtlBaseModule::CAtlBaseModule(ATL::CAtlBaseModule *this)
{
  ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(this);
  this->cbSize = 56;
  this->m_hInstResource = (HINSTANCE__ *)0x400000;
  this->m_hInst = (HINSTANCE__ *)0x400000;
  this->dwAtlBuildVer = 2560;
  this->pguidVer = &GUID_ATLVer100;
  if ( (ATL::CComCriticalSection::Init(this: &this->m_csResource) & 0x80000000) != 0 )
    ATL::CAtlBaseModule::m_bInitFailed = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051C473
// Name: public: ATL::CImage::CInitGDIPlus::CInitGDIPlus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CImage::CInitGDIPlus *__thiscall ATL::CImage::CInitGDIPlus::CInitGDIPlus(ATL::CImage::CInitGDIPlus *this)
{
  signed int LastError; // eax

  this->m_dwToken = 0;
  this->m_nCImageObjects = 0;
  this->m_dwLastError = 0;
  if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &this->m_sect, dwSpinCount: 0) )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    this->m_dwLastError = LastError;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051C4AE
// Name: public: ATL::CImage::CDCCache::~CDCCache(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::CDCCache::~CDCCache(ATL::CImage::CDCCache *this)
{
  int i; // esi

  for ( i = 0; i < 4; ++i )
  {
    if ( this->m_ahDCs[i] != nullptr )
      DeleteDC(hdc: this->m_ahDCs[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051C4CE
// Name: OleUIBusyA(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
UINT __stdcall OleUIBusyA(LPOLEUIBUSYA a1)
{
  return __imp__OleUIBusyA@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4D4
// Name: CreateStdAccessibleObject(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall CreateStdAccessibleObject(HWND hwnd, LONG idObject, const IID *const riid, void **ppvObject)
{
  return __imp__CreateStdAccessibleObject@16(hwnd, idObject, riid, ppvObject);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4DA
// Name: AccessibleObjectFromWindow(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AccessibleObjectFromWindow(HWND hwnd, DWORD dwId, const IID *const riid, void **ppvObject)
{
  return __imp__AccessibleObjectFromWindow@16(hwnd, dwId, riid, ppvObject);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4E0
// Name: LresultFromObject(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LONG_PTR __stdcall LresultFromObject(const IID *const riid, WPARAM wParam, LPUNKNOWN punk)
{
  return __imp__LresultFromObject@12(riid, wParam, punk);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4E6
// Name: GdipFree(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipFree(int a1)
{
  return __imp__GdipFree@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4EC
// Name: GdipAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipAlloc(int a1)
{
  return __imp__GdipAlloc@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4F2
// Name: GdipDeleteGraphics(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDeleteGraphics(int a1)
{
  return __imp__GdipDeleteGraphics@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4F8
// Name: GdipDisposeImage(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDisposeImage(int a1)
{
  return __imp__GdipDisposeImage@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4FE
// Name: GdipCreateBitmapFromHBITMAP(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return __imp__GdipCreateBitmapFromHBITMAP@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0051C504
// Name: GdiplusStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return __imp__GdiplusStartup@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0051C50A
// Name: GdiplusShutdown(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdiplusShutdown(int a1)
{
  return __imp__GdiplusShutdown@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C510
// Name: GdipCreateFromHDC(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return __imp__GdipCreateFromHDC@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C516
// Name: GdipSetInterpolationMode(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipSetInterpolationMode(int a1, int a2)
{
  return __imp__GdipSetInterpolationMode@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C51C
// Name: GdipDrawImageRectI(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDrawImageRectI(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return __imp__GdipDrawImageRectI@24(a1, a2, a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x0051C522
// Name: GdipCloneImage(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCloneImage(int a1, int a2)
{
  return __imp__GdipCloneImage@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C528
// Name: GdipGetImageWidth(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return __imp__GdipGetImageWidth@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C52E
// Name: GdipGetImageHeight(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return __imp__GdipGetImageHeight@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C534
// Name: GdipGetImagePixelFormat(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePixelFormat(int a1, int a2)
{
  return __imp__GdipGetImagePixelFormat@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C53A
// Name: GdipGetImagePaletteSize(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePaletteSize(int a1, int a2)
{
  return __imp__GdipGetImagePaletteSize@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C540
// Name: GdipGetImagePalette(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePalette(int a1, int a2, int a3)
{
  return __imp__GdipGetImagePalette@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0051C546
// Name: GdipCreateBitmapFromStream(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromStream(int a1, int a2)
{
  return __imp__GdipCreateBitmapFromStream@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C54C
// Name: GdipCreateBitmapFromScan0(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromScan0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return __imp__GdipCreateBitmapFromScan0@24(a1, a2, a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x0051C552
// Name: GdipBitmapLockBits(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipBitmapLockBits(int a1, int a2, int a3, int a4, int a5)
{
  return __imp__GdipBitmapLockBits@20(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x0051C558
// Name: GdipBitmapUnlockBits(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipBitmapUnlockBits(int a1, int a2)
{
  return __imp__GdipBitmapUnlockBits@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C55E
// Name: GdipGetImageGraphicsContext(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageGraphicsContext(int a1, int a2)
{
  return __imp__GdipGetImageGraphicsContext@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C564
// Name: GdipDrawImageI(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDrawImageI(int a1, int a2, int a3, int a4)
{
  return __imp__GdipDrawImageI@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0051C56A
// Name: ImmReleaseContext(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmReleaseContext(HWND a1, HIMC a2)
{
  return __imp__ImmReleaseContext@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0051C570
// Name: ImmGetOpenStatus(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmGetOpenStatus(HIMC a1)
{
  return __imp__ImmGetOpenStatus@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C576
// Name: ImmGetContext(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HIMC __stdcall ImmGetContext(HWND a1)
{
  return __imp__ImmGetContext@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0051C57C
// Name: ReuseDDElParam(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LPARAM __stdcall ReuseDDElParam(LPARAM lParam, UINT msgIn, UINT msgOut, UINT_PTR uiLo, UINT_PTR uiHi)
{
  return __imp__ReuseDDElParam@20(lParam, msgIn, msgOut, uiLo, uiHi);
}

//------------------------------------------------------------------------------
// Address: 0x0051C582
// Name: UnpackDDElParam(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall UnpackDDElParam(UINT msg, LPARAM lParam, PUINT_PTR puiLo, PUINT_PTR puiHi)
{
  return __imp__UnpackDDElParam@16(msg, lParam, puiLo, puiHi);
}

//------------------------------------------------------------------------------
// Address: 0x0051C588
// Name: WinMain(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AfxWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

//------------------------------------------------------------------------------
// Address: 0x0051C593
// Name: void _AfxTermAppState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _AfxTermAppState()
{
  AfxTermLocalData(hInst: nullptr, bAll: 1);
  AfxCriticalTerm();
  AfxTlsRelease();
}

//------------------------------------------------------------------------------
// Address: 0x0051C5A6
// Name: int AfxWinMain(struct HINSTANCE__ __near *,struct HINSTANCE__ __near *,char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxWinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  int v4; // ebx
  CWinThread *Thread; // esi
  CWinApp *m_pCurrentWinApp; // edi
  int v7; // eax

  v4 = -1;
  Thread = AfxGetThread();
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( AfxWinInit(hInstance, hPrevInstance, lpCmdLine, nCmdShow) != 0
    && (m_pCurrentWinApp == nullptr || m_pCurrentWinApp->InitApplication(this: m_pCurrentWinApp) != 0) )
  {
    if ( Thread->InitInstance(this: Thread) != 0 )
    {
      v7 = Thread->Run(this: Thread);
    }
    else
    {
      if ( Thread->m_pMainWnd != nullptr )
        Thread->m_pMainWnd->DestroyWindow(this: Thread->m_pMainWnd);
      v7 = Thread->ExitInstance(this: Thread);
    }
    v4 = v7;
  }
  AfxWinTerm();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x005283E0
// Name: _dynamic_initializer_for__g_SortColumns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SortColumns__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SortColumns__);
}

//------------------------------------------------------------------------------
// Address: 0x005283F0
// Name: _dynamic_initializer_for__theApp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__theApp__()
{
  CWinApp::CWinApp(this: &theApp, lpszAppName: nullptr);
  theApp.__vftable = (CVMPIBrowserServicesApp_vtbl *)&CVMPIBrowserServicesApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__theApp__);
}

//------------------------------------------------------------------------------
// Address: 0x00528420
// Name: _dynamic_initializer_for__g_Starter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Starter__()
{
  WSAData WSAData; // [esp+0h] [ebp-190h] BYREF

  return WSAStartup(wVersionRequested: 0x202u, lpWSAData: &WSAData);
}

//------------------------------------------------------------------------------
// Address: 0x0052843F
// Name: _dynamic_initializer_for___afxHtmlHelpState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___afxHtmlHelpState__()
{
  return atexit(func: dynamic_atexit_destructor_for___afxHtmlHelpState__);
}
