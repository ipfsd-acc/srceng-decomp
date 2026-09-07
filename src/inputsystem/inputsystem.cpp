// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: inputsystem/inputsystem.cpp
// Functions: 83
// ============================================================

#include "inputsystem\inputsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IInputSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IInputSystem,0>::GetTier(CTier2AppSystem<IInputStackSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: virtual bool CTier2AppSystem<class IInputStackSystem,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IInputStackSystem,0>::Connect(
        CTier2AppSystem<IInputStackSystem,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IInputStackSystem,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IInputStackSystem,0>::Init(CTier2AppSystem<IInputStackSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: public: virtual void CInputSystem::SleepUntilInput(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SleepUntilInput(CInputSystem *this, int nMaxSleepTimeMS)
{
  DWORD v2; // eax

  v2 = nMaxSleepTimeMS;
  if ( nMaxSleepTimeMS < 0 )
    v2 = -1;
  MsgWaitForMultipleObjects(
    nCount: 1u,
    pHandles: &this->m_hEvent,
    fWaitAll: false,
    dwMilliseconds: v2,
    dwWakeMask: 0x4BFu);
}

//------------------------------------------------------------------------------
// Address: 0x100013B0
// Name: public: virtual void CInputSystem::AddUIEventListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::AddUIEventListener(CInputSystem *this)
{
  ++this->m_nUIEventClientCount;
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: public: virtual void CInputSystem::RemoveUIEventListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::RemoveUIEventListener(CInputSystem *this)
{
  --this->m_nUIEventClientCount;
}

//------------------------------------------------------------------------------
// Address: 0x100013D0
// Name: public: virtual struct PlatWindow_t__ __near * CInputSystem::GetAttachedWindow(void)const
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall CInputSystem::GetAttachedWindow(CInputSystem *this)
{
  return this->m_hAttachedHWnd;
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual void CInputSystem::DetachFromWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::DetachFromWindow(CInputSystem *this)
{
  if ( this->m_hAttachedHWnd != nullptr )
  {
    this->ResetInputState(this);
    if ( this->m_ChainedWndProc != nullptr )
    {
      SetWindowLongW(hWnd: this->m_hAttachedHWnd, nIndex: -4, dwNewLong: (LONG)this->m_ChainedWndProc);
      this->m_ChainedWndProc = nullptr;
    }
    this->m_hAttachedHWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: public: virtual void CInputSystem::EnableInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::EnableInput(CInputSystem *this, bool bEnable)
{
  this->m_bEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: virtual void CInputSystem::EnableMessagePump(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::EnableMessagePump(CInputSystem *this, bool bEnable)
{
  this->m_bPumpEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: virtual char const __near * CInputSystem::ButtonCodeToString(enum ButtonCode_t)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInputSystem::ButtonCodeToString(CInputSystem *this, ButtonCode_t code)
{
  return ButtonCode_ButtonCodeToString(code, bXController: this->m_bXController);
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual char const __near * CInputSystem::AnalogCodeToString(enum AnalogCode_t)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInputSystem::AnalogCodeToString(CInputSystem *this, AnalogCode_t code)
{
  return AnalogCode_AnalogCodeToString(code);
}

//------------------------------------------------------------------------------
// Address: 0x10001480
// Name: public: virtual enum ButtonCode_t CInputSystem::StringToButtonCode(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall CInputSystem::StringToButtonCode(CInputSystem *this, const char *pString)
{
  return ButtonCode_StringToButtonCode(pString, bXController: true);
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: virtual enum AnalogCode_t CInputSystem::StringToAnalogCode(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
AnalogCode_t __thiscall CInputSystem::StringToAnalogCode(CInputSystem *this, const char *pString)
{
  return AnalogCode_StringToAnalogCode(pString);
}

//------------------------------------------------------------------------------
// Address: 0x100014C0
// Name: public: virtual enum ButtonCode_t CInputSystem::VirtualKeyToButtonCode(int)const
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall CInputSystem::VirtualKeyToButtonCode(CInputSystem *this, int nVirtualKey)
{
  return ButtonCode_VirtualKeyToButtonCode(keyCode: nVirtualKey);
}

//------------------------------------------------------------------------------
// Address: 0x100014E0
// Name: public: virtual int CInputSystem::ButtonCodeToVirtualKey(enum ButtonCode_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::ButtonCodeToVirtualKey(CInputSystem *this, ButtonCode_t code)
{
  return ButtonCode_ButtonCodeToVirtualKey(code);
}

//------------------------------------------------------------------------------
// Address: 0x10001500
// Name: private: enum ButtonCode_t CInputSystem::XKeyToButtonCode(int,int)const
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall CInputSystem::XKeyToButtonCode(CInputSystem *this, int nPort, int nXKey)
{
  if ( this->m_bXController )
    return ButtonCode_XKeyToButtonCode(nPort, keyCode: nXKey);
  else
    return BUTTON_CODE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10001530
// Name: public: virtual enum ButtonCode_t CInputSystem::ScanCodeToButtonCode(int)const
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall CInputSystem::ScanCodeToButtonCode(CInputSystem *this, int lParam)
{
  return ButtonCode_ScanCodeToButtonCode(lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: private: void CInputSystem::ProcessEvent(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ProcessEvent(CInputSystem *this, unsigned int uMsg, unsigned int wParam, int lParam)
{
  HWND Focus; // esi
  void (__stdcall *WindowLongW)(HWND, unsigned int, unsigned int, int); // eax

  Focus = GetFocus();
  WindowLongW = (void (__stdcall *)(HWND, unsigned int, unsigned int, int))GetWindowLongW(hWnd: Focus, nIndex: -4);
  if ( WindowLongW != nullptr )
    WindowLongW(a1: Focus, a2: uMsg, a3: wParam, a4: lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: virtual int CInputSystem::GetPollCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetPollCount(CInputSystem *this)
{
  return this->m_nPollCount;
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: virtual void CInputSystem::SampleDevices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SampleDevices(CInputSystem *this)
{
  int v2; // eax
  bool v3; // zf

  v2 = _Plat_MSTime();
  v3 = !this->m_bXController;
  this->m_nLastSampleTick = v2 - this->m_StartupTimeTick;
  if ( v3 )
    CInputSystem::PollJoystick(this);
  else
    CInputSystem::PollXDevices(this);
}

//------------------------------------------------------------------------------
// Address: 0x100015C0
// Name: public: virtual void CInputSystem::SetRumble(float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SetRumble(CInputSystem *this, float fLeftMotor, float fRightMotor, int userId)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100015D0
// Name: public: virtual int CInputSystem::GetJoystickCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetJoystickCount(CInputSystem *this)
{
  return this->m_nJoystickCount;
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: virtual void CInputSystem::EnableJoystickDiagonalPOV(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::EnableJoystickDiagonalPOV(CInputSystem *this, int nJoystick, bool bEnable)
{
  this->m_pJoystickInfo[nJoystick].m_bDiagonalPOVControlEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: virtual int CInputSystem::GetPollTick(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetPollTick(CInputSystem *this)
{
  return this->m_nLastPollTick;
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: virtual int CInputSystem::GetAnalogValue(enum AnalogCode_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetAnalogValue(CInputSystem *this, AnalogCode_t code)
{
  return this->m_InputState[1].m_pAnalogValue[code];
}

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: virtual int CInputSystem::GetAnalogDelta(enum AnalogCode_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetAnalogDelta(CInputSystem *this, AnalogCode_t code)
{
  return this->m_InputState[1].m_pAnalogDelta[code];
}

//------------------------------------------------------------------------------
// Address: 0x10001650
// Name: public: virtual int CInputSystem::GetButtonPressedTick(enum ButtonCode_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetButtonPressedTick(CInputSystem *this, ButtonCode_t code)
{
  return this->m_InputState[1].m_ButtonPressedTick[code];
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: virtual int CInputSystem::GetButtonReleasedTick(enum ButtonCode_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetButtonReleasedTick(CInputSystem *this, ButtonCode_t code)
{
  return this->m_InputState[1].m_ButtonReleasedTick[code];
}

//------------------------------------------------------------------------------
// Address: 0x10001690
// Name: private: void CInputSystem::ZeroAnalogState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ZeroAnalogState(CInputSystem *this, int nFirstState, int nLastState)
{
  CInputSystem::InputState_t *v3; // esi

  v3 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
  memset(dst: (unsigned __int8 *)&v3->m_pAnalogDelta[nFirstState], value: 0, count: 4 * (nLastState - nFirstState) + 4);
  memset(dst: (unsigned __int8 *)&v3->m_pAnalogValue[nFirstState], value: 0, count: 4 * (nLastState - nFirstState) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: private: int CInputSystem::ButtonMaskFromMouseWParam(unsigned int,enum ButtonCode_t,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::ButtonMaskFromMouseWParam(CInputSystem *this, char wParam, ButtonCode_t code, bool bDown)
{
  int result; // eax

  result = (wParam & 1) != 0;
  if ( (wParam & 2) != 0 )
    result |= 2u;
  if ( (wParam & 0x10) != 0 )
    result |= 4u;
  if ( (wParam & 0x20) != 0 )
    result |= 8u;
  if ( (wParam & 0x40) != 0 )
    return result | 0x10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: public: virtual void CInputSystem::GetCursorPosition(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::GetCursorPosition(CInputSystem *this, tagPOINT *pX, int *pY)
{
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_hAttachedHWnd != nullptr )
  {
    GetCursorPos(lpPoint: &pt);
    ScreenToClient(hWnd: this->m_hAttachedHWnd, lpPoint: &pt);
    *pX = pt;
  }
  else
  {
    *pY = 0;
    pX->x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: public: virtual void CInputSystem::SetMouseCursorVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SetMouseCursorVisible(CInputSystem *this, bool bVisible)
{
  this->m_bCursorVisible = bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x10001790
// Name: public: virtual void CInputSystem::GetRawMouseAccumulators(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::GetRawMouseAccumulators(CInputSystem *this, int *accumX, int *accumY)
{
  *accumX = this->m_mouseRawAccumX;
  *accumY = this->m_mouseRawAccumY;
  this->m_mouseRawAccumY = 0;
  this->m_mouseRawAccumX = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100017C0
// Name: private: void CInputSystem::InitCursors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::InitCursors(CInputSystem *this)
{
  InputCursorHandle_t__ **m_pDefaultCursors; // edi

  m_pDefaultCursors = this->m_pDefaultCursors;
  memset(dst: (unsigned __int8 *)this->m_pDefaultCursors, value: 0, count: sizeof(this->m_pDefaultCursors));
  *m_pDefaultCursors = nullptr;
  this->m_pDefaultCursors[1] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  this->m_pDefaultCursors[2] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F01);
  this->m_pDefaultCursors[3] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F02);
  this->m_pDefaultCursors[4] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F03);
  this->m_pDefaultCursors[5] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F8A);
  this->m_pDefaultCursors[6] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F04);
  this->m_pDefaultCursors[7] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F82);
  this->m_pDefaultCursors[8] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F83);
  this->m_pDefaultCursors[9] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
  this->m_pDefaultCursors[10] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
  this->m_pDefaultCursors[11] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
  this->m_pDefaultCursors[12] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F88);
  this->m_pDefaultCursors[13] = (InputCursorHandle_t__ *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F89);
}

//------------------------------------------------------------------------------
// Address: 0x100018B0
// Name: public: virtual struct InputCursorHandle_t__ __near * CInputSystem::GetStandardCursor(enum InputStandardCursor_t)
// Source: json
//------------------------------------------------------------------------------
InputCursorHandle_t__ *__thiscall CInputSystem::GetStandardCursor(CInputSystem *this, InputStandardCursor_t id)
{
  return this->m_pDefaultCursors[id];
}

//------------------------------------------------------------------------------
// Address: 0x100018D0
// Name: public: virtual void CInputSystem::SetCursorIcon(struct InputCursorHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SetCursorIcon(CInputSystem *this, InputCursorHandle_t__ *hCursor)
{
  SetCursor((HCURSOR)hCursor);
}

//------------------------------------------------------------------------------
// Address: 0x100018E0
// Name: public: virtual void CInputSystem::EnableMouseCapture(struct PlatWindow_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::EnableMouseCapture(CInputSystem *this, PlatWindow_t__ *hWnd)
{
  PlatWindow_t__ *m_hCurrentCaptureWnd; // eax

  m_hCurrentCaptureWnd = this->m_hCurrentCaptureWnd;
  if ( m_hCurrentCaptureWnd != hWnd )
  {
    if ( m_hCurrentCaptureWnd != nullptr )
      ReleaseCapture();
    this->m_hCurrentCaptureWnd = hWnd;
    if ( hWnd != nullptr )
      SetCapture((HWND)hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001920
// Name: public: virtual void CInputSystem::DisableMouseCapture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::DisableMouseCapture(CInputSystem *this)
{
  this->EnableMouseCapture(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: private: void CInputSystem::PressX360Button(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PressX360Button(CInputSystem *this, const CCommand *args)
{
  const char *v3; // edx
  int v4; // ecx
  char c2; // al

  if ( args->m_nArgc >= 2 )
  {
    v3 = str;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = 0;
    while ( 1 )
    {
      if ( *v3 == press_x360_button_codes[v4].c1 )
      {
        c2 = press_x360_button_codes[v4].c2;
        if ( v3[1] == c2 || c2 == 0 )
          break;
      }
      if ( (unsigned int)++v4 >= 0x10 )
        return;
    }
    this->m_press_x360_buttons[0] |= 1 << v4;
  }
  else
  {
    _Warning(
      a1: "press_x360_button: requires a key to send (lt, rt, st[art], ba[ck], lb, rb, a, b, x, y, l[eft], r[right], u[p], d[own])");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019B0
// Name: private: void CInputSystem::PollPressX360Button(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PollPressX360Button(CInputSystem *this)
{
  unsigned int v2; // edi
  int v3; // ebx
  unsigned int pressedButtons; // [esp+Ch] [ebp-8h]
  unsigned int releasedButtons; // [esp+10h] [ebp-4h]

  v2 = 0;
  pressedButtons = this->m_press_x360_buttons[0];
  releasedButtons = this->m_press_x360_buttons[1];
  this->m_press_x360_buttons[0] = 0;
  this->m_press_x360_buttons[1] = pressedButtons;
  v3 = 1;
  do
  {
    if ( (v3 & releasedButtons) != 0 )
      CInputSystem::PostXKeyEvent(this, userId: 0, xKey: press_x360_button_codes[v2].key, nSample: 0);
    if ( (v3 & pressedButtons) != 0 )
      CInputSystem::PostXKeyEvent(this, userId: 0, xKey: press_x360_button_codes[v2].key, nSample: 0x8000);
    ++v2;
    v3 = __ROL4__(v3, 1);
  }
  while ( v2 < 16 );
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: public: virtual void CConCommandMemberAccessor<class CInputSystem>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CInputSystem>::CommandCallback(
        CConCommandMemberAccessor<CInputSystem> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(_DWORD, const CCommand *))this->m_pszName)(a1: *(_DWORD *)&this->m_bRegistered, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: virtual int CConCommandMemberAccessor<class CInputSystem>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CInputSystem>::CommandCompletionCallback(
        CConCommandMemberAccessor<CInputSystem> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(ConCommandBase *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_pszName)(
           a1: this->m_pNext,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x10001A80
// Name: public: void CUtlMemory<struct InputEvent_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<InputEvent_t,int>::Grow(CUtlMemory<InputEvent_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  InputEvent_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 2;
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (InputEvent_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (InputEvent_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B20
// Name: public: virtual void CInputSystem::EnableJoystickInput(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::EnableJoystickInput(CInputSystem *this, char nJoystick, bool bEnable)
{
  int v3; // eax

  v3 = 1 << nJoystick;
  if ( bEnable )
    this->m_JoysticksEnabled.m_nFlags |= v3;
  else
    this->m_JoysticksEnabled.m_nFlags &= ~(_WORD)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: virtual int CInputSystem::GetEventCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::GetEventCount(CInputSystem *this)
{
  return this->m_InputState[1].m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: CInputSystem::CCommandMemberInitializer_PressX360Button::CCommandMemberInitializer_PressX360Button(void)
// Source: json
//------------------------------------------------------------------------------
CInputSystem::CCommandMemberInitializer_PressX360Button *__thiscall CInputSystem::CCommandMemberInitializer_PressX360Button::CCommandMemberInitializer_PressX360Button(
        CInputSystem::CCommandMemberInitializer_PressX360Button *this)
{
  ICommandCallback *v2; // eax

  if ( this != nullptr )
    v2 = &this->m_ConCommandAccessor.ICommandCallback;
  else
    v2 = nullptr;
  ConCommand::ConCommand(
    this: &this->m_ConCommandAccessor,
    pName: "press_x360_button",
    pCallback: v2,
    pHelpString: "Press the specified Xbox 360 controller button (lt, rt, st[art], ba[ck], lb, rb, a, b, x, y, l[eft], r[right], u[p], d[own])",
    flags: 0,
    pCompletionCallback: nullptr);
  this->m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  this->m_ConCommandAccessor.m_pOwner = (CInputSystem *)((char *)this - 4);
  this->m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CInputSystem>_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ConCommand'};
  this->m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ICommandCallback'};
  this->m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ICommandCompletionCallback'};
  this->m_ConCommandAccessor.m_Func = CInputSystem::PressX360Button;
  this->m_ConCommandAccessor.m_CompletionFunc = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: virtual void __near * CBaseAppSystem<class IInputSystem>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<IInputSystem>::QueryInterface(
        CBaseAppSystem<IInputStackSystem> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: public: virtual void CBaseAppSystem<class IInputSystem>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IInputSystem>::Reconnect(
        CBaseAppSystem<IInputStackSystem> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual bool CInputSystem::IsButtonDown(enum ButtonCode_t)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CInputSystem::IsButtonDown(CInputSystem *this, ButtonCode_t code)
{
  return (this->m_InputState[1].m_ButtonState.m_Ints[code >> 5] & (1 << (code & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: public: virtual struct InputEvent_t const __near * CInputSystem::GetEventData(void)const
// Source: json
//------------------------------------------------------------------------------
const InputEvent_t *__thiscall CInputSystem::GetEventData(CInputSystem *this)
{
  return this->m_InputState[1].m_Events.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10001C30
// Name: public: int CUtlVector<struct InputEvent_t,class CUtlMemory<struct InputEvent_t,int>>::InsertBefore(int,struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertBefore(
        CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int> > *this,
        int elem,
        const InputEvent_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  InputEvent_t *m_pMemory; // ecx
  int v7; // eax
  InputEvent_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<InputEvent_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: public: int CUtlVector<struct InputEvent_t,class CUtlMemory<struct InputEvent_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertMultipleBefore(
        CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  InputEvent_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<InputEvent_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: public: virtual enum InitReturnVal_t CInputSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CInputSystem::Init(CInputSystem *this)
{
  InitReturnVal_t result; // eax
  struct CSysModule *Module; // eax

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->m_StartupTimeTick = _Plat_MSTime();
  this->m_uiMouseWheel = RegisterWindowMessageA(lpString: "MSWHEEL_ROLLMSG");
  result = (InitReturnVal_t)CreateEventA(
                              lpEventAttributes: nullptr,
                              bManualReset: false,
                              bInitialState: false,
                              lpName: nullptr);
  this->m_hEvent = (void *)result;
  if ( result != INIT_FAILED )
  {
    ButtonCode_InitKeyTranslationTable();
    ButtonCode_UpdateScanCodeLayout();
    ConVar::SetValue(this: (ConVar *)&joy_xcontroller_found.IConVar, value: 0);
    Module = Sys_LoadModule(pModuleName: "XInput1_3.dll");
    this->m_pXInputDLL = Module;
    if ( Module != nullptr )
      CInputSystem::InitializeXDevices(this);
    if ( this->m_nJoystickCount != 0 )
      this->m_bXController = true;
    else
      CInputSystem::InitializeJoysticks(this);
    if ( this->m_bXController )
      ConVar::SetValue(this: (ConVar *)&joy_xcontroller_found.IConVar, value: 1);
    CInputSystem::InitCursors(this);
    return INIT_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001DF0
// Name: public: virtual bool CInputSystem::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputSystem::Connect(CInputSystem *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001E20
// Name: private: void CInputSystem::ClearInputState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ClearInputState(CInputSystem *this, bool bPurgeState)
{
  int *p_m_nGrowSize; // esi
  int i; // edi

  p_m_nGrowSize = &this->m_InputState[0].m_Events.m_Memory.m_nGrowSize;
  for ( i = 2; i != 0; --i )
  {
    if ( p_m_nGrowSize != (int *)2720 )
    {
      *((_QWORD *)p_m_nGrowSize - 340) = 0;
      *((_QWORD *)p_m_nGrowSize - 339) = 0;
      *((_QWORD *)p_m_nGrowSize - 338) = 0;
      *((_QWORD *)p_m_nGrowSize - 337) = 0;
      *((_QWORD *)p_m_nGrowSize - 336) = 0;
    }
    memset(dst: (unsigned __int8 *)p_m_nGrowSize - 232, value: 0, count: 0x70u);
    memset(dst: (unsigned __int8 *)p_m_nGrowSize - 120, value: 0, count: 0x70u);
    memset(dst: (unsigned __int8 *)p_m_nGrowSize - 2680, value: 0, count: 0x4C8u);
    memset(dst: (unsigned __int8 *)p_m_nGrowSize - 1456, value: 0, count: 0x4C8u);
    if ( bPurgeState )
    {
      p_m_nGrowSize[1] = 0;
      if ( *p_m_nGrowSize >= 0 )
      {
        if ( *(p_m_nGrowSize - 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(p_m_nGrowSize - 2));
          *(p_m_nGrowSize - 2) = 0;
        }
        *(p_m_nGrowSize - 1) = 0;
      }
      p_m_nGrowSize[2] = *(p_m_nGrowSize - 2);
      *((_BYTE *)p_m_nGrowSize + 12) = 0;
    }
    p_m_nGrowSize += 684;
  }
  memset(dst: (unsigned __int8 *)this->m_appXKeys, value: 0, count: sizeof(this->m_appXKeys));
}

//------------------------------------------------------------------------------
// Address: 0x10001F20
// Name: public: int CUtlVector<struct InputCursorHandle_t__ __near *,class CUtlMemory<struct InputCursorHandle_t__ __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>::InsertMultipleBefore(
        CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  InputCursorHandle_t__ **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable::StringPool_t *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: private: void CInputSystem::PostEvent(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PostEvent(CInputSystem *this, int nType, int nTick, int nData, int nData2, int nData3)
{
  CInputSystem::InputState_t *v6; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  InputEvent_t *m_pMemory; // ecx
  int v10; // eax
  InputEvent_t *v11; // eax

  v6 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
  m_nAllocationCount = this->m_InputState[(unsigned __int8)this->m_bIsPolling].m_Events.m_Memory.m_nAllocationCount;
  m_Size = this->m_InputState[(unsigned __int8)this->m_bIsPolling].m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<InputEvent_t,int>::Grow(
      this: &this->m_InputState[(unsigned __int8)this->m_bIsPolling].m_Events.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++v6->m_Events.m_Size;
  m_pMemory = v6->m_Events.m_Memory.m_pMemory;
  v10 = v6->m_Events.m_Size - m_Size - 1;
  v6->m_Events.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v10);
  v11 = &v6->m_Events.m_Memory.m_pMemory[m_Size];
  v11->m_nType = nType;
  v11->m_nTick = nTick;
  v11->m_nData = nData;
  v11->m_nData2 = nData2;
  v11->m_nData3 = nData3;
  v6->m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x10002040
// Name: private: void CInputSystem::PostButtonPressedEvent(enum InputEventType_t,int,enum ButtonCode_t,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PostButtonPressedEvent(
        CInputSystem *this,
        InputEventType_t nType,
        int nTick,
        ButtonCode_t scanCode,
        ButtonCode_t virtualCode)
{
  CInputSystem::InputState_t *v6; // edi
  int v7; // esi
  unsigned int *v8; // ecx

  v6 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
  v7 = 1 << (scanCode & 0x1F);
  v8 = &v6->m_ButtonState.m_Ints[scanCode >> 5];
  if ( (v7 & *v8) == 0 )
  {
    *v8 |= v7;
    v6->m_ButtonPressedTick[scanCode] = nTick;
    CInputSystem::PostEvent(this, nType, nTick, nData: scanCode, nData2: virtualCode, nData3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100020A0
// Name: private: void CInputSystem::PostButtonReleasedEvent(enum InputEventType_t,int,enum ButtonCode_t,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PostButtonReleasedEvent(
        CInputSystem *this,
        InputEventType_t nType,
        int nTick,
        ButtonCode_t scanCode,
        ButtonCode_t virtualCode)
{
  CInputSystem::InputState_t *v6; // edi
  int v7; // eax
  unsigned int *v8; // ecx

  v6 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
  v7 = 1 << (scanCode & 0x1F);
  v8 = &v6->m_ButtonState.m_Ints[scanCode >> 5];
  if ( (v7 & *v8) != 0 )
  {
    *v8 &= ~v7;
    v6->m_ButtonReleasedTick[scanCode] = nTick;
    CInputSystem::PostEvent(this, nType, nTick, nData: scanCode, nData2: virtualCode, nData3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002100
// Name: private: void CInputSystem::PollInputState_Windows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PollInputState_Windows(CInputSystem *this)
{
  bool v1; // zf
  tagMSG msg; // [esp+0h] [ebp-20h] BYREF
  CInputSystem *v3; // [esp+1Ch] [ebp-4h]

  v1 = !this->m_bPumpEnabled;
  v3 = this;
  if ( !v1 && PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    while ( msg.message != 18 )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
      if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
        return;
    }
    CInputSystem::PostEvent(this: v3, nType: 100, nTick: v3->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002190
// Name: public: virtual void CInputSystem::PostUserEvent(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PostUserEvent(CInputSystem *this, const InputEvent_t *event)
{
  CInputSystem::InputState_t *v2; // esi

  v2 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
  CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertBefore(
    this: &this->m_InputState[(unsigned __int8)this->m_bIsPolling].m_Events,
    elem: this->m_InputState[(unsigned __int8)this->m_bIsPolling].m_Events.m_Size,
    src: event);
  v2->m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x100021D0
// Name: private: void CInputSystem::ReleaseAllButtons(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ReleaseAllButtons(CInputSystem *this, int nFirstButton, int nLastButton)
{
  int v4; // edi
  int v5; // esi
  int m_nLastSampleTick; // ecx
  CInputSystem::InputState_t *v7; // eax
  bool v8; // zf
  unsigned int *v9; // eax
  CInputSystem::InputState_t *v10; // [esp+Ch] [ebp-4h]
  int nFirstButtona; // [esp+18h] [ebp+8h]

  v4 = __ROL4__(1, nFirstButton);
  v5 = nFirstButton;
  if ( nFirstButton <= nLastButton )
  {
    nFirstButtona = 4 * nFirstButton + 1264;
    do
    {
      m_nLastSampleTick = this->m_nLastSampleTick;
      v7 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
      v8 = (v4 & v7->m_ButtonState.m_Ints[v5 >> 5]) == 0;
      v10 = v7;
      v9 = &v7->m_ButtonState.m_Ints[v5 >> 5];
      if ( !v8 )
      {
        *v9 &= ~v4;
        *(unsigned int *)((char *)v10->m_ButtonState.m_Ints + nFirstButtona) = m_nLastSampleTick;
        CInputSystem::PostEvent(this, nType: 1, nTick: m_nLastSampleTick, nData: v5, nData2: v5, nData3: 0);
      }
      nFirstButtona += 4;
      ++v5;
      v4 = __ROL4__(v4, 1);
    }
    while ( v5 <= nLastButton );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002260
// Name: private: void CInputSystem::UpdateMouseButtonState(int,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::UpdateMouseButtonState(CInputSystem *this, int nButtonMask, ButtonCode_t dblClickCode)
{
  int v4; // esi
  int m_nLastSampleTick; // ebx
  int v6; // edx
  int v7; // edx
  CInputSystem::InputState_t *v8; // ebx
  int v9; // eax
  unsigned int *v10; // ecx
  bool v11; // zf
  CInputSystem::InputState_t *v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v14 = 1;
  v4 = 107;
  v15 = 423;
  v13 = 5;
  do
  {
    if ( (nButtonMask & v14) != 0 )
    {
      m_nLastSampleTick = this->m_nLastSampleTick;
      v6 = 1 << (v4 & 0x1F);
      v12 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
      if ( (v6 & v12->m_ButtonState.m_Ints[v4 >> 5]) == 0 )
      {
        v12->m_ButtonState.m_Ints[v4 >> 5] |= v6;
        v12->m_ButtonState.m_Ints[v15 - 306] = m_nLastSampleTick;
        CInputSystem::PostEvent(
          this,
          nType: v4 != dblClickCode ? 0 : 2,
          nTick: m_nLastSampleTick,
          nData: v4,
          nData2: v4,
          nData3: 0);
      }
    }
    else
    {
      v7 = this->m_nLastSampleTick;
      v8 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
      v9 = 1 << (v4 & 0x1F);
      v10 = &v8->m_ButtonState.m_Ints[v4 >> 5];
      if ( (v9 & *v10) != 0 )
      {
        *v10 &= ~v9;
        v8->m_ButtonState.m_Ints[v15] = v7;
        CInputSystem::PostEvent(this, nType: 1, nTick: v7, nData: v4, nData2: v4, nData3: 0);
      }
    }
    ++v15;
    ++v4;
    v11 = v13-- == 1;
    v14 = __ROL4__(v14, 1);
  }
  while ( !v11 );
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: public: virtual void CInputSystem::SetCursorPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::SetCursorPosition(CInputSystem *this, int x, int y)
{
  HWND__ *m_hAttachedHWnd; // eax
  BOOL m_bIsPolling; // edx
  CInputSystem::InputState_t *v7; // esi
  bool v8; // cl
  bool v9; // zf
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF
  bool bXChanged_3; // [esp+17h] [ebp+Bh]
  bool bYChanged_3; // [esp+1Bh] [ebp+Fh]

  m_hAttachedHWnd = this->m_hAttachedHWnd;
  if ( m_hAttachedHWnd != nullptr )
  {
    pt.x = x;
    pt.y = y;
    ClientToScreen(hWnd: m_hAttachedHWnd, lpPoint: &pt);
    SetCursorPos(X: pt.x, Y: pt.y);
    m_bIsPolling = this->m_bIsPolling;
    v7 = &this->m_InputState[m_bIsPolling];
    v8 = this->m_InputState[m_bIsPolling].m_pAnalogValue[0] != x;
    v9 = this->m_InputState[m_bIsPolling].m_pAnalogValue[1] == y;
    v7->m_pAnalogValue[1] = y;
    bYChanged_3 = !v9;
    bXChanged_3 = v8;
    v7->m_pAnalogValue[0] = x;
    v7->m_pAnalogDelta[0] = 0;
    v7->m_pAnalogDelta[1] = 0;
    if ( v8 )
      CInputSystem::PostEvent(this, nType: 3, nTick: this->m_nLastSampleTick, nData: 0, nData2: x, nData3: 0);
    if ( bYChanged_3 )
      CInputSystem::PostEvent(
        this,
        nType: 3,
        nTick: this->m_nLastSampleTick,
        nData: 1,
        nData2: v7->m_pAnalogValue[1],
        nData3: v7->m_pAnalogDelta[1]);
    if ( bXChanged_3 || bYChanged_3 )
      CInputSystem::PostEvent(
        this,
        nType: 3,
        nTick: this->m_nLastSampleTick,
        nData: 2,
        nData2: v7->m_pAnalogValue[0],
        nData3: v7->m_pAnalogValue[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002440
// Name: private: void CInputSystem::UpdateMousePositionState(struct CInputSystem::InputState_t __near &,short,short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::UpdateMousePositionState(
        CInputSystem *this,
        CInputSystem::InputState_t *state,
        __int16 x,
        __int16 y)
{
  int v4; // ebx
  int v6; // ecx

  v4 = state->m_pAnalogValue[1];
  v6 = x - state->m_pAnalogValue[0];
  state->m_pAnalogValue[1] = y;
  state->m_pAnalogValue[0] = x;
  state->m_pAnalogDelta[0] = v6;
  state->m_pAnalogDelta[1] = y - v4;
  if ( v6 != 0 )
    CInputSystem::PostEvent(this, nType: 3, nTick: this->m_nLastSampleTick, nData: 0, nData2: x, nData3: v6);
  if ( state->m_pAnalogDelta[1] != 0 )
    CInputSystem::PostEvent(
      this,
      nType: 3,
      nTick: this->m_nLastSampleTick,
      nData: 1,
      nData2: state->m_pAnalogValue[1],
      nData3: state->m_pAnalogDelta[1]);
  if ( state->m_pAnalogDelta[0] != 0 || state->m_pAnalogDelta[1] != 0 )
    CInputSystem::PostEvent(
      this,
      nType: 3,
      nTick: this->m_nLastSampleTick,
      nData: 2,
      nData2: state->m_pAnalogValue[0],
      nData3: state->m_pAnalogValue[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: private: void CInputSystem::LocateMouseClick(long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::LocateMouseClick(CInputSystem *this, int lParam)
{
  if ( this->m_nUIEventClientCount > 0 )
    CInputSystem::PostEvent(
      this,
      nType: 200,
      nTick: this->m_nLastSampleTick,
      nData: (__int16)lParam,
      nData2: SHIWORD(lParam),
      nData3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10002540
// Name: public: long CInputSystem::WindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputSystem::WindowProc(
        CInputSystem *this,
        HWND__ *hwnd,
        UINT uMsg,
        signed int wParam,
        unsigned int lParam)
{
  int (__stdcall *v6)(HWND__ *, unsigned int, unsigned int, int); // esi
  int result; // eax
  int m_nLastSampleTick; // ecx
  HWND__ *m_hAttachedHWnd; // eax
  UINT v10; // edi
  int (__stdcall *m_ChainedWndProc)(HWND__ *, unsigned int, unsigned int, int); // esi
  BOOL m_bIsPolling; // ecx
  CInputSystem::InputState_t *v13; // ebx
  unsigned int v14; // edi
  unsigned __int8 v15; // al
  int v16; // edi
  int v17; // eax
  int (__stdcall *v18)(HWND__ *, unsigned int, unsigned int, int); // esi
  ButtonCode_t v19; // edi
  __int32 v20; // edi
  int v21; // eax
  ButtonCode_t v22; // edi
  char KeyState; // al
  ButtonCode_t v24; // edi
  ButtonCode_t v25; // edi
  ButtonCode_t v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  BOOL v38; // ecx
  int v39; // eax
  int v40; // edi
  int v41; // eax
  int v42; // [esp-18h] [ebp-24h]
  int v43; // [esp-18h] [ebp-24h]
  int v44; // [esp-10h] [ebp-1Ch]
  ButtonCode_t v45; // [esp-Ch] [ebp-18h]
  unsigned int dwSize; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bEnabled )
  {
    if ( this->m_nUIEventClientCount > 0 && hwnd != this->m_hLastIMEHWnd )
    {
      m_nLastSampleTick = this->m_nLastSampleTick;
      this->m_hLastIMEHWnd = hwnd;
      CInputSystem::PostEvent(this, nType: 205, nTick: m_nLastSampleTick, nData: (int)hwnd, nData2: 0, nData3: 0);
    }
    m_hAttachedHWnd = this->m_hAttachedHWnd;
    v10 = uMsg;
    if ( hwnd != m_hAttachedHWnd && uMsg != 28 )
    {
      m_ChainedWndProc = this->m_ChainedWndProc;
      if ( m_ChainedWndProc != nullptr )
        return CallWindowProcA(lpPrevWndFunc: m_ChainedWndProc, hWnd: hwnd, Msg: uMsg, wParam, lParam);
      return 0;
    }
    m_bIsPolling = this->m_bIsPolling;
    v13 = &this->m_InputState[m_bIsPolling];
    if ( uMsg > 0x200 )
    {
      switch ( uMsg )
      {
        case 0x201u:
          CInputSystem::LocateMouseClick(this, lParam);
          v45 = BUTTON_CODE_INVALID;
          v28 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: KEY_COUNT, bDown: true);
          goto LABEL_76;
        case 0x202u:
          CInputSystem::LocateMouseClick(this, lParam);
          v29 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: KEY_COUNT, bDown: false);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v29, dblClickCode: BUTTON_CODE_INVALID);
          goto LABEL_26;
        case 0x203u:
          CInputSystem::LocateMouseClick(this, lParam);
          v35 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: KEY_COUNT, bDown: true);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v35, dblClickCode: KEY_COUNT);
          goto LABEL_26;
        case 0x204u:
          CInputSystem::LocateMouseClick(this, lParam);
          v30 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_RIGHT, bDown: true);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v30, dblClickCode: BUTTON_CODE_INVALID);
          goto LABEL_26;
        case 0x205u:
          CInputSystem::LocateMouseClick(this, lParam);
          v45 = BUTTON_CODE_INVALID;
          v28 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_RIGHT, bDown: false);
          goto LABEL_76;
        case 0x206u:
          CInputSystem::LocateMouseClick(this, lParam);
          v36 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_RIGHT, bDown: true);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v36, dblClickCode: MOUSE_RIGHT);
          goto LABEL_26;
        case 0x207u:
          CInputSystem::LocateMouseClick(this, lParam);
          v31 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_MIDDLE, bDown: true);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v31, dblClickCode: BUTTON_CODE_INVALID);
          goto LABEL_26;
        case 0x208u:
          CInputSystem::LocateMouseClick(this, lParam);
          v32 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_MIDDLE, bDown: false);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v32, dblClickCode: BUTTON_CODE_INVALID);
          goto LABEL_26;
        case 0x209u:
          CInputSystem::LocateMouseClick(this, lParam);
          v45 = MOUSE_MIDDLE;
          v28 = CInputSystem::ButtonMaskFromMouseWParam(this, wParam, code: MOUSE_MIDDLE, bDown: true);
LABEL_76:
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v28, dblClickCode: v45);
          goto LABEL_26;
        case 0x20Au:
          v38 = SHIWORD(wParam) <= 0;
          dwSize = HIWORD(wParam);
          v39 = this->m_nLastSampleTick;
          v13->m_ButtonReleasedTick[v38 + 112] = v39;
          v13->m_ButtonPressedTick[v38 + 112] = v39;
          v40 = v38 + 112;
          CInputSystem::PostEvent(
            this,
            nType: 0,
            nTick: this->m_nLastSampleTick,
            nData: v38 + 112,
            nData2: v38 + 112,
            nData3: 0);
          CInputSystem::PostEvent(this, nType: 1, nTick: this->m_nLastSampleTick, nData: v40, nData2: v40, nData3: 0);
          v41 = (__int16)dwSize / 120;
          v13->m_pAnalogValue[3] += v41;
          v44 = v13->m_pAnalogValue[3];
          v13->m_pAnalogDelta[3] = v41;
          CInputSystem::PostEvent(this, nType: 3, nTick: this->m_nLastSampleTick, nData: 3, nData2: v44, nData3: v41);
          goto LABEL_25;
        case 0x20Bu:
          CInputSystem::LocateMouseClick(this, lParam);
          v33 = CInputSystem::ButtonMaskFromMouseWParam(
                  this,
                  wParam,
                  code: (ButtonCode_t)((HIWORD(wParam) != 1) + 110),
                  bDown: true);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v33, dblClickCode: BUTTON_CODE_INVALID);
          return 1;
        case 0x20Cu:
          CInputSystem::LocateMouseClick(this, lParam);
          v34 = CInputSystem::ButtonMaskFromMouseWParam(
                  this,
                  wParam,
                  code: (ButtonCode_t)((HIWORD(wParam) != 1) + 110),
                  bDown: false);
          CInputSystem::UpdateMouseButtonState(this, nButtonMask: v34, dblClickCode: BUTTON_CODE_INVALID);
          return 1;
        case 0x20Du:
          CInputSystem::LocateMouseClick(this, lParam);
          v37 = CInputSystem::ButtonMaskFromMouseWParam(
                  this,
                  wParam,
                  code: (ButtonCode_t)((HIWORD(wParam) != 1) + 110),
                  bDown: true);
          CInputSystem::UpdateMouseButtonState(
            this,
            nButtonMask: v37,
            dblClickCode: (ButtonCode_t)((HIWORD(wParam) != 1) + 110));
          return 1;
        case 0x281u:
$LN123:
          if ( this->m_nUIEventClientCount > 0 )
            lParam &= 0x3FFFFFF0u;
          goto LABEL_26;
        case 0x282u:
          if ( this->m_nUIEventClientCount <= 0 )
            goto LABEL_26;
          switch ( wParam )
          {
            case 3:
              CInputSystem::PostEvent(this, nType: 210, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
              result = 0;
              break;
            case 4:
              CInputSystem::PostEvent(this, nType: 211, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
              goto $LN123;
            case 5:
              CInputSystem::PostEvent(this, nType: 209, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
              result = 1;
              break;
            case 6:
            case 7:
            case 8:
              CInputSystem::PostEvent(this, nType: 212, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
              if ( wParam != 8 )
                goto $LN123;
              return 0;
            default:
              goto $LN123;
          }
          return result;
        case 0x286u:
          if ( this->m_nUIEventClientCount <= 0 )
            goto LABEL_26;
          return 0;
        default:
          goto LABEL_26;
      }
    }
    if ( uMsg == 512 )
    {
      CInputSystem::UpdateMousePositionState(
        this,
        state: &this->m_InputState[m_bIsPolling],
        x: lParam,
        y: SHIWORD(lParam));
      v27 = (wParam & 1) != 0;
      if ( (wParam & 2) != 0 )
        v27 |= 2u;
      if ( (wParam & 0x10) != 0 )
        v27 |= 4u;
      if ( (wParam & 0x20) != 0 )
        v27 |= 8u;
      if ( (wParam & 0x40) != 0 )
        v27 |= 0x10u;
      CInputSystem::UpdateMouseButtonState(this, nButtonMask: v27, dblClickCode: BUTTON_CODE_INVALID);
    }
    else
    {
      if ( uMsg > 0x1C )
      {
        switch ( uMsg )
        {
          case 0x20u:
            if ( this->m_nUIEventClientCount > 0 )
              CInputSystem::PostEvent(this, nType: 201, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
            goto LABEL_26;
          case 0x51u:
            if ( this->m_nUIEventClientCount > 0 )
              CInputSystem::PostEvent(this, nType: 204, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
            goto LABEL_26;
          case 0xFFu:
            dwSize = 40;
            GetRawInputData(
              hRawInput: (HRAWINPUT)lParam,
              uiCommand: 0x10000003u,
              pData: lpb,
              pcbSize: &dwSize,
              cbSizeHeader: 0x10u);
            if ( *(_DWORD *)lpb != 0 )
              goto LABEL_25;
            this->m_mouseRawAccumX += dword_1001D8F4;
            this->m_mouseRawAccumY += dword_1001D8F8;
            goto LABEL_26;
          case 0x100u:
          case 0x104u:
            if ( (lParam & 0x40000000) == 0 )
            {
              dwSize = ButtonCode_VirtualKeyToButtonCode(keyCode: wParam);
              v19 = ButtonCode_ScanCodeToButtonCode(lParam);
              CInputSystem::PostButtonPressedEvent(
                this,
                nType: IE_ButtonPressed,
                nTick: this->m_nLastSampleTick,
                scanCode: v19,
                virtualCode: (ButtonCode_t)dwSize);
              if ( v19 == KEY_CAPSLOCK || v19 == KEY_SCROLLLOCK || v19 == KEY_NUMLOCK )
              {
                v20 = v19 - 69;
                if ( v20 != 0 )
                {
                  if ( v20 == 2 )
                  {
                    v21 = 145;
                    v22 = KEY_SCROLLLOCKTOGGLE;
                  }
                  else
                  {
                    v21 = 20;
                    v22 = KEY_CAPSLOCKTOGGLE;
                  }
                }
                else
                {
                  v21 = 144;
                  v22 = KEY_NUMLOCKTOGGLE;
                }
                KeyState = GetKeyState(nVirtKey: v21);
                CInputSystem::PostButtonPressedEvent(
                  this,
                  nType: (InputEventType_t)((KeyState & 1) == 0),
                  nTick: this->m_nLastSampleTick,
                  scanCode: v22,
                  virtualCode: v22);
              }
            }
            if ( this->m_nUIEventClientCount > 0 )
            {
              v24 = ButtonCode_VirtualKeyToButtonCode(keyCode: wParam);
              if ( (_WORD)lParam != 0 )
              {
                for ( dwSize = (unsigned __int16)lParam; dwSize != 0; --dwSize )
                  CInputSystem::PostEvent(
                    this,
                    nType: 203,
                    nTick: this->m_nLastSampleTick,
                    nData: v24,
                    nData2: 0,
                    nData3: 0);
              }
            }
            goto LABEL_25;
          case 0x101u:
          case 0x105u:
            v25 = ButtonCode_VirtualKeyToButtonCode(keyCode: wParam);
            v26 = ButtonCode_ScanCodeToButtonCode(lParam);
            CInputSystem::PostButtonReleasedEvent(
              this,
              nType: IE_ButtonReleased,
              nTick: this->m_nLastSampleTick,
              scanCode: v26,
              virtualCode: v25);
            goto LABEL_25;
          case 0x102u:
          case 0x106u:
            if ( this->m_nUIEventClientCount > 0 && !this->m_bIMEComposing )
              CInputSystem::PostEvent(
                this,
                nType: 202,
                nTick: this->m_nLastSampleTick,
                nData: (unsigned __int16)wParam,
                nData2: 0,
                nData3: 0);
            goto LABEL_26;
          case 0x10Du:
            if ( this->m_nUIEventClientCount <= 0 )
              goto LABEL_26;
            v42 = this->m_nLastSampleTick;
            this->m_bIMEComposing = true;
            CInputSystem::PostEvent(this, nType: 206, nTick: v42, nData: 0, nData2: 0, nData3: 0);
            return 1;
          case 0x10Eu:
            if ( this->m_nUIEventClientCount <= 0 )
              goto LABEL_26;
            v43 = this->m_nLastSampleTick;
            this->m_bIMEComposing = false;
            CInputSystem::PostEvent(this, nType: 208, nTick: v43, nData: 0, nData2: 0, nData3: 0);
            return 1;
          case 0x10Fu:
            if ( this->m_nUIEventClientCount <= 0 )
              goto LABEL_26;
            CInputSystem::PostEvent(
              this,
              nType: 207,
              nTick: this->m_nLastSampleTick,
              nData: lParam,
              nData2: 0,
              nData3: 0);
            return 1;
          default:
            goto LABEL_26;
        }
      }
      switch ( uMsg )
      {
        case 0x1Cu:
          if ( hwnd == m_hAttachedHWnd && wParam != 1 )
            this->ResetInputState(this);
          break;
        case 5u:
          v14 = HIWORD(lParam);
          dwSize = (unsigned __int16)lParam;
          if ( wParam == 1 || IsIconic(hWnd: hwnd) )
          {
            v14 = 0;
            v15 = 1;
            dwSize = 0;
          }
          else
          {
            v15 = 0;
          }
          CInputSystem::PostEvent(
            this,
            nType: 104,
            nTick: this->m_nLastSampleTick,
            nData: dwSize,
            nData2: v14,
            nData3: v15);
LABEL_25:
          v10 = uMsg;
          break;
        case 0x10u:
          CInputSystem::PostEvent(this, nType: 103, nTick: this->m_nLastSampleTick, nData: 0, nData2: 0, nData3: 0);
          return 0;
        default:
          break;
      }
    }
LABEL_26:
    if ( v10 == this->m_uiMouseWheel )
    {
      v16 = (wParam <= 0) + 112;
      v17 = this->m_nLastSampleTick;
      v13->m_ButtonReleasedTick[v16] = v17;
      v13->m_ButtonPressedTick[v16] = v17;
      CInputSystem::PostEvent(this, nType: 0, nTick: this->m_nLastSampleTick, nData: v16, nData2: v16, nData3: 0);
      CInputSystem::PostEvent(this, nType: 1, nTick: this->m_nLastSampleTick, nData: v16, nData2: v16, nData3: 0);
      v13->m_pAnalogValue[3] += wParam / 120;
      v13->m_pAnalogDelta[3] = wParam / 120;
      CInputSystem::PostEvent(
        this,
        nType: 3,
        nTick: this->m_nLastSampleTick,
        nData: 3,
        nData2: v13->m_pAnalogValue[3],
        nData3: wParam / 120);
      v10 = uMsg;
    }
    v18 = this->m_ChainedWndProc;
    if ( v18 != nullptr )
      return CallWindowProcA(lpPrevWndFunc: v18, hWnd: hwnd, Msg: v10, wParam, lParam);
    return 0;
  }
  v6 = this->m_ChainedWndProc;
  if ( v6 != nullptr )
    return CallWindowProcA(lpPrevWndFunc: v6, hWnd: hwnd, Msg: uMsg, wParam, lParam);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002FE0
// Name: public: virtual void CTier2AppSystem<class IInputStackSystem,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IInputStackSystem,0>::Disconnect(CTier2AppSystem<IInputStackSystem,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10002FF0
// Name: public: virtual CInputSystem::~CInputSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::~CInputSystem(CInputSystem *this)
{
  struct CSysModule *m_pXInputDLL; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+Ch] [ebp-4h]

  m_pXInputDLL = this->m_pXInputDLL;
  this->__vftable = (CInputSystem_vtbl *)&CInputSystem::`vftable';
  if ( m_pXInputDLL != nullptr )
  {
    Sys_UnloadModule(pModule: m_pXInputDLL);
    this->m_pXInputDLL = nullptr;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_UserCursors.m_SymbolTable);
  CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>::~CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_UserCursors);
  v5 = 1;
  v3 = (char *)this + 8268;
  do
  {
    v3 -= 2736;
    *((_DWORD *)v3 + 3) = 0;
    if ( *((int *)v3 + 2) >= 0 )
    {
      if ( *(_DWORD *)v3 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
        *(_DWORD *)v3 = 0;
      }
      *((_DWORD *)v3 + 1) = 0;
    }
    v4 = *(void **)v3;
    *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
    if ( *((int *)v3 + 2) >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *(_DWORD *)v3 = 0;
      }
      *((_DWORD *)v3 + 1) = 0;
    }
    --v5;
  }
  while ( v5 >= 0 );
  this->m_PressX360Button_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CInputSystem>_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ConCommand'};
  this->m_PressX360Button_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ICommandCallback'};
  this->m_PressX360Button_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CInputSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_PressX360Button_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_PressX360Button_register.m_ConCommandAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x100030C0
// Name: InputSystemWindowProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputSystemWindowProc(HWND__ *hwnd, UINT uMsg, unsigned int wParam, unsigned int lParam)
{
  return CInputSystem::WindowProc(this: &g_InputSystem, hwnd, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x100030D0
// Name: public: virtual void CInputSystem::AttachToWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::AttachToWindow(CInputSystem *this, HWND__ *hWnd)
{
  tagRAWINPUTDEVICE Rid[1]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_hAttachedHWnd != nullptr )
  {
    _Warning(a1: "CInputSystem::AttachToWindow: Cannot attach to two windows at once!\n");
  }
  else
  {
    this->m_ChainedWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))GetWindowLongW(
                                                                                             hWnd,
                                                                                             nIndex: -4);
    SetWindowLongW(hWnd, nIndex: -4, dwNewLong: (LONG)InputSystemWindowProc);
    *(_DWORD *)&Rid[0].usUsagePage = 131073;
    Rid[0].dwFlags = 256;
    Rid[0].hwndTarget = hWnd;
    RegisterRawInputDevices(pRawInputDevices: Rid, uiNumDevices: 1u, cbSize: 0xCu);
    this->m_hAttachedHWnd = hWnd;
    CInputSystem::ClearInputState(this, bPurgeState: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003150
// Name: public: virtual void CInputSystem::ResetInputState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ResetInputState(CInputSystem *this)
{
  BOOL m_bIsPolling; // eax
  CInputSystem::InputState_t *v3; // edi

  CInputSystem::ReleaseAllButtons(this, nFirstButton: 0, nLastButton: 305);
  m_bIsPolling = this->m_bIsPolling;
  v3 = &this->m_InputState[m_bIsPolling];
  memset(
    dst: (unsigned __int8 *)this->m_InputState[m_bIsPolling].m_pAnalogDelta,
    value: 0,
    count: sizeof(this->m_InputState[m_bIsPolling].m_pAnalogDelta));
  memset(dst: (unsigned __int8 *)v3->m_pAnalogValue, value: 0, count: sizeof(v3->m_pAnalogValue));
  CInputSystem::ClearInputState(this, bPurgeState: false);
  this->m_mouseRawAccumY = 0;
  this->m_mouseRawAccumX = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100031C0
// Name: private: void CInputSystem::CopyInputState(struct CInputSystem::InputState_t __near *,struct CInputSystem::InputState_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::CopyInputState(
        CInputSystem *this,
        CInputSystem::InputState_t *pDest,
        CInputSystem::InputState_t *src,
        bool bCopyEvents)
{
  int m_Size; // eax

  pDest->m_Events.m_Size = 0;
  pDest->m_bDirty = false;
  if ( src->m_bDirty )
  {
    memcpy(dst: (unsigned __int8 *)pDest, (unsigned __int8 *)src, count: 0x2Cu);
    pDest->m_ButtonReleasedTick[0] = src->m_ButtonReleasedTick[0];
    pDest->m_pAnalogDelta[0] = src->m_pAnalogDelta[0];
    pDest->m_pAnalogValue[0] = src->m_pAnalogValue[0];
    if ( bCopyEvents )
    {
      m_Size = src->m_Events.m_Size;
      if ( m_Size > 0 )
      {
        if ( pDest->m_Events.m_Size < m_Size )
          CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertMultipleBefore(
            this: &pDest->m_Events,
            elem: pDest->m_Events.m_Size,
            num: m_Size - pDest->m_Events.m_Size);
        memcpy(
          dst: (unsigned __int8 *)pDest->m_Events.m_Memory.m_pMemory,
          src: (unsigned __int8 *)src->m_Events.m_Memory.m_pMemory,
          count: 20 * src->m_Events.m_Size);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003280
// Name: public: virtual void CInputSystem::PollInputState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PollInputState(CInputSystem *this)
{
  CInputSystem::PollPressX360Button(this);
  ++this->m_nPollCount;
  this->m_bIsPolling = true;
  CInputSystem::CopyInputState(this, pDest: &this->m_InputState[1], src: this->m_InputState, bCopyEvents: true);
  this->SampleDevices(this);
  this->m_nLastPollTick = this->m_nLastSampleTick;
  CInputSystem::PollInputState_Windows(this);
  this->m_InputState[0].m_Events.m_Size = 0;
  this->m_InputState[0].m_bDirty = false;
  if ( this->m_InputState[1].m_bDirty )
  {
    memcpy(dst: (unsigned __int8 *)this->m_InputState, src: (unsigned __int8 *)&this->m_InputState[1], count: 0x2Cu);
    this->m_InputState[0].m_ButtonReleasedTick[0] = this->m_InputState[1].m_ButtonReleasedTick[0];
    this->m_InputState[0].m_pAnalogDelta[0] = this->m_InputState[1].m_pAnalogDelta[0];
    this->m_InputState[0].m_pAnalogValue[0] = this->m_InputState[1].m_pAnalogValue[0];
  }
  this->m_bIsPolling = false;
}

//------------------------------------------------------------------------------
// Address: 0x10003320
// Name: private: void CInputSystem::ShutdownCursors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ShutdownCursors(CInputSystem *this)
{
  int m_NumElements; // ebx
  int v3; // edi
  bool v4; // sf
  InputCursorHandle_t__ **m_pDefaultCursors; // esi
  int i; // edi

  m_NumElements = this->m_UserCursors.m_SymbolTable.m_Lookup.m_NumElements;
  v3 = 0;
  if ( this->m_UserCursors.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
      DestroyCursor(hCursor: (HCURSOR)this->m_UserCursors.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v3++]);
    while ( v3 < m_NumElements );
  }
  v4 = this->m_UserCursors.m_Vector.m_Memory.m_nGrowSize < 0;
  this->m_UserCursors.m_Vector.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_UserCursors.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UserCursors.m_Vector.m_Memory.m_pMemory);
      this->m_UserCursors.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    this->m_UserCursors.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  this->m_UserCursors.m_Vector.m_pElements = this->m_UserCursors.m_Vector.m_Memory.m_pMemory;
  CUtlSymbolTable::RemoveAll(this: &this->m_UserCursors.m_SymbolTable);
  m_pDefaultCursors = this->m_pDefaultCursors;
  for ( i = 14; i != 0; --i )
  {
    if ( *m_pDefaultCursors != nullptr )
    {
      DestroyCursor(hCursor: (HCURSOR)*m_pDefaultCursors);
      *m_pDefaultCursors = nullptr;
    }
    ++m_pDefaultCursors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100033D0
// Name: public: CInputSystem::CInputSystem(void)
// Source: json
//------------------------------------------------------------------------------
CInputSystem *__thiscall CInputSystem::CInputSystem(CInputSystem *this)
{
  CInputSystem::InputState_t *m_InputState; // ecx
  int v3; // edx
  int *p_m_nGrowSize; // eax

  this->__vftable = (CInputSystem_vtbl *)&CInputSystem::`vftable';
  CInputSystem::CCommandMemberInitializer_PressX360Button::CCommandMemberInitializer_PressX360Button(this: &this->m_PressX360Button_register);
  m_InputState = this->m_InputState;
  v3 = 1;
  p_m_nGrowSize = &this->m_InputState[0].m_Events.m_Memory.m_nGrowSize;
  do
  {
    if ( m_InputState != nullptr )
    {
      *(_QWORD *)m_InputState->m_ButtonState.m_Ints = 0;
      *(_QWORD *)&m_InputState->m_ButtonState.m_Ints[2] = 0;
      *(_QWORD *)&m_InputState->m_ButtonState.m_Ints[4] = 0;
      *(_QWORD *)&m_InputState->m_ButtonState.m_Ints[6] = 0;
      *(_QWORD *)&m_InputState->m_ButtonState.m_Ints[8] = 0;
    }
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    ++m_InputState;
    p_m_nGrowSize += 684;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_JoysticksEnabled.m_nFlags = 0;
  this->m_UserCursors.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_UserCursors.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_UserCursors.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_UserCursors.m_Vector.m_Size = 0;
  this->m_UserCursors.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_UserCursors.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  this->m_StartupTimeTick = 0;
  this->m_nLastSampleTick = 0;
  this->m_nLastPollTick = 0;
  this->m_ChainedWndProc = nullptr;
  this->m_hAttachedHWnd = nullptr;
  this->m_hEvent = nullptr;
  this->m_JoysticksEnabled.m_nFlags = 0;
  this->m_nJoystickCount = 0;
  this->m_nPollCount = 0;
  this->m_uiMouseWheel = 0;
  this->m_bXController = false;
  *(_DWORD *)&this->m_bEnabled = 257;
  this->m_nUIEventClientCount = 0;
  this->m_hLastIMEHWnd = nullptr;
  this->m_hCurrentCaptureWnd = nullptr;
  this->m_bCursorVisible = true;
  _V_memset(dest: this->m_press_x360_buttons, fill: 0, count: 8);
  this->m_pXInputDLL = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003510
// Name: public: virtual void CInputSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Force-skipped: ?Shutdown@CInputSystem@@UAEXXZ

//------------------------------------------------------------------------------
// Address: 0x10003550
// Name: public: virtual struct InputCursorHandle_t__ __near * CInputSystem::LoadCursorFromFileA(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
InputCursorHandle_t__ *__thiscall CInputSystem::LoadCursorFromFileA(
        CInputSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  int m_Id; // eax
  HCURSOR CursorFromFileA; // ebx
  int v7; // edi
  int m_Size; // eax
  char fullpath[512]; // [esp+4h] [ebp-400h] BYREF
  char fn[512]; // [esp+204h] [ebp-200h] BYREF

  if ( g_pFullFileSystem == nullptr )
    return nullptr;
  V_strncpy(pDest: fn, pSrc: pFileName, maxLen: 512);
  _V_strlower(start: fn);
  V_FixSlashes(pname: fn, separator: 92);
  m_Id = CUtlSymbolTable::Find(
           this: &this->m_UserCursors.m_SymbolTable,
           result: (CUtlSymbol *)&pFileName + 1,
           pString: fn)->m_Id;
  if ( (_WORD)m_Id != 0xFFFF )
    return this->m_UserCursors.m_Vector.m_Memory.m_pMemory[m_Id];
  g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: fn);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: fn,
    a3: pPathID,
    a4: fullpath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  CursorFromFileA = LoadCursorFromFileA(lpFileName: fullpath);
  CUtlSymbolTable::AddString(this: &this->m_UserCursors.m_SymbolTable, result: (CUtlSymbol *)&pFileName, pString: fn);
  v7 = (unsigned __int16)pFileName;
  m_Size = this->m_UserCursors.m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pFileName && m_Size < (unsigned __int16)pFileName + 1 )
    CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>::InsertMultipleBefore(
      this: &this->m_UserCursors.m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pFileName + 1 - m_Size);
  this->m_UserCursors.m_Vector.m_Memory.m_pMemory[v7] = (InputCursorHandle_t__ *)CursorFromFileA;
  return (InputCursorHandle_t__ *)CursorFromFileA;
}

//------------------------------------------------------------------------------
// Address: 0x10006280
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 2;
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100063D0
// Name: public: CUtlVector<struct InputCursorHandle_t__ __near *,class CUtlMemory<struct InputCursorHandle_t__ __near *,int>>::~CUtlVector<struct InputCursorHandle_t__ __near *,class CUtlMemory<struct InputCursorHandle_t__ __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>::~CUtlVector<InputCursorHandle_t__ *,CUtlMemory<InputCursorHandle_t__ *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: public: virtual void CInputSystem::StopRumble(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::StopRumble(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: __CreateCInputSystemIInputSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CInputSystem *__cdecl _CreateCInputSystemIInputSystem_interface()
{
  return &g_InputSystem;
}
