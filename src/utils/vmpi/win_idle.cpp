// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/win_idle.cpp
// Functions: 8
// ============================================================

#include "utils\vmpi\win_idle.h"

//------------------------------------------------------------------------------
// Address: 0x00405EB0
// Name: protected: static unsigned long CWinIdle::ThreadStub(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CWinIdle::ThreadStub(unsigned int (__thiscall ***pIdle)(_DWORD))
{
  return (**pIdle)(a1: pIdle);
}

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: public: CWinIdle::CWinIdle(void)
// Source: json
//------------------------------------------------------------------------------
CWinIdle *__thiscall CWinIdle::CWinIdle(CWinIdle *this)
{
  this->__vftable = (CWinIdle_vtbl *)&CWinIdle::`vftable';
  this->m_hIdleEvent = nullptr;
  this->m_hStopEvent = nullptr;
  this->m_hWnd = nullptr;
  this->m_uMsg = 0;
  this->m_dwDelay = 0;
  this->m_hIdleThread = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: public: virtual void __near * CWinIdle::GetThreadHandle(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CWinIdle::GetThreadHandle(CWinIdle *this)
{
  return this->m_hIdleThread;
}

//------------------------------------------------------------------------------
// Address: 0x00405EF0
// Name: protected: virtual unsigned long CWinIdle::RunIdle(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinIdle::RunIdle(CWinIdle *this)
{
  void *m_hStopEvent; // eax
  void *m_hIdleEvent; // ecx
  void *aEvents[2]; // [esp+8h] [ebp-8h] BYREF

  m_hStopEvent = this->m_hStopEvent;
  m_hIdleEvent = this->m_hIdleEvent;
  aEvents[0] = m_hStopEvent;
  aEvents[1] = m_hIdleEvent;
  while ( WaitForMultipleObjects(nCount: 2u, lpHandles: aEvents, bWaitAll: false, dwMilliseconds: 0xFFFFFFFF) != 0 )
  {
    PostMessageA(hWnd: this->m_hWnd, Msg: this->m_uMsg, wParam: this->m_wParam, lParam: this->m_lParam);
    Sleep(dwMilliseconds: this->m_dwDelay);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405F60
// Name: public: virtual int CWinIdle::StartIdle(struct HWND__ __near *,unsigned int,unsigned int,long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinIdle::StartIdle(
        CWinIdle *this,
        HWND__ *hWnd,
        unsigned int uMessage,
        unsigned int wParam,
        int lParam,
        unsigned int dwDelay)
{
  HWND__ *v8; // ebx
  HANDLE EventA; // eax
  bool v10; // zf
  HANDLE Thread; // eax
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx

  if ( this->m_hIdleThread != nullptr )
    return false;
  v8 = hWnd;
  if ( hWnd == nullptr )
    return false;
  this->m_hIdleEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: nullptr);
  v10 = this->m_hIdleEvent == nullptr;
  this->m_hStopEvent = EventA;
  if ( v10 || EventA == nullptr )
    return false;
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)CWinIdle::ThreadStub,
             lpParameter: this,
             dwCreationFlags: 0,
             lpThreadId: (LPDWORD)&hWnd);
  this->m_hIdleThread = Thread;
  if ( Thread != nullptr )
  {
    SetThreadPriority(hThread: Thread, nPriority: -15);
    v12 = wParam;
    v13 = lParam;
    this->m_uMsg = uMessage;
    v14 = dwDelay;
    this->m_hWnd = v8;
    this->m_wParam = v12;
    this->m_lParam = v13;
    this->m_dwDelay = v14;
  }
  return this->m_hIdleThread != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00406000
// Name: public: virtual int CWinIdle::EndIdle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinIdle::EndIdle(CWinIdle *this)
{
  if ( this->m_hIdleThread == nullptr )
    return 0;
  SetEvent(hEvent: this->m_hStopEvent);
  WaitForSingleObject(hHandle: this->m_hIdleThread, dwMilliseconds: 0xFFFFFFFF);
  CloseHandle(hObject: this->m_hIdleThread);
  CloseHandle(hObject: this->m_hIdleEvent);
  CloseHandle(hObject: this->m_hStopEvent);
  this->m_hIdleEvent = nullptr;
  this->m_hStopEvent = nullptr;
  this->m_hIdleThread = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406060
// Name: public: virtual void CWinIdle::NextIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinIdle::NextIdle(CWinIdle *this)
{
  if ( this->m_hIdleThread != nullptr )
    SetEvent(hEvent: this->m_hIdleEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00406080
// Name: public: virtual CWinIdle::~CWinIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinIdle::~CWinIdle(CWinIdle *this)
{
  this->__vftable = (CWinIdle_vtbl *)&CWinIdle::`vftable';
  CWinIdle::EndIdle(this);
}
