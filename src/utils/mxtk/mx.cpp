// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mx.cpp
// Functions: 15
// ============================================================

#include "utils\mxtk\mx.h"

//------------------------------------------------------------------------------
// Address: 0x004C2AB0
// Name: public: mxLinkedList::mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
mxLinkedList *__thiscall mxLinkedList::mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *v2; // eax
  mxListNode_s *d_head; // ecx

  this->d_head = (mxListNode_s *)operator new(nSize: 0xCu);
  v2 = (mxListNode_s *)operator new(nSize: 0xCu);
  d_head = this->d_head;
  this->d_tail = v2;
  d_head->d_data = nullptr;
  this->d_head->d_next = this->d_tail;
  this->d_head->d_prev = nullptr;
  this->d_tail->d_data = nullptr;
  this->d_tail->d_next = nullptr;
  this->d_tail->d_prev = this->d_head;
  this->d_nodeCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C2B00
// Name: public: void mxLinkedList::remove(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::remove(mxLinkedList *this, void *data)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v4; // esi

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v4 = d_next->d_next;
      if ( d_next->d_data == data )
      {
        d_next->d_prev->d_next = v4;
        d_next->d_next->d_prev = d_next->d_prev;
        free(pMem: d_next);
      }
      d_next = v4;
    }
    while ( v4 != this->d_tail );
  }
  --this->d_nodeCount;
}

//------------------------------------------------------------------------------
// Address: 0x004C2B50
// Name: void mx_addWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_addWidget(mxWidget *widget)
{
  mxLinkedList *v1; // esi
  mxListNode_s *v2; // eax

  v1 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    v2 = (mxListNode_s *)operator new(nSize: 0xCu);
    v2->d_data = widget;
    v1->d_tail->d_prev->d_next = v2;
    v2->d_prev = v1->d_tail->d_prev;
    v2->d_next = v1->d_tail;
    v1->d_tail->d_prev = v2;
    ++v1->d_nodeCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2BA0
// Name: void mx_removeWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_removeWidget(mxWidget *widget)
{
  if ( g_widgetList != nullptr )
    mxLinkedList::remove(this: g_widgetList, data: widget);
}

//------------------------------------------------------------------------------
// Address: 0x004C2BC0
// Name: struct HWND__ __near * mx_CreateToolTipControl(void)
// Source: json
//------------------------------------------------------------------------------
HWND__ *__cdecl mx_CreateToolTipControl()
{
  HWND__ *result; // eax
  HWND__ *Handle; // eax
  HMODULE ModuleHandleA; // [esp-8h] [ebp-8h]
  char *v3; // [esp-4h] [ebp-4h]

  result = (HWND__ *)g_hwndToolTipControl;
  if ( g_hwndToolTipControl == nullptr && g_mainWindow != nullptr )
  {
    v3 = (char *)g_hwndToolTipControl;
    ModuleHandleA = GetModuleHandleA(lpModuleName: g_hwndToolTipControl);
    Handle = mxWidget::getHandle(this: g_mainWindow);
    result = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "tooltips_class32",
               lpWindowName: defaultValue,
               dwStyle: 0x80000008,
               X: 0,
               Y: 0,
               nWidth: 0,
               nHeight: 0,
               hWndParent: Handle,
               hMenu: nullptr,
               hInstance: ModuleHandleA,
               lpParam: v3);
    g_hwndToolTipControl = (LPCSTR)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C2C10
// Name: RecursiveHandleEvent
// Source: json
//------------------------------------------------------------------------------
void __usercall RecursiveHandleEvent(mxWindow *window@<eax>, mxEvent *event@<edi>)
{
  mxWindow *i; // esi

  for ( i = window; i != nullptr; i = mxWidget::getParent(this: i) )
  {
    if ( i->handleEvent(this: i, a2: event) != 0 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2C40
// Name: public: static int mx::run(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl mx::run()
{
  int v0; // edi
  mxWindow *v1; // ecx
  HWND__ *Handle; // eax
  int (__thiscall *handleEvent)(mxWindow *, mxEvent *); // eax
  HACCEL v5; // [esp-8h] [ebp-44h]
  mxEvent event; // [esp+Ch] [ebp-30h] BYREF

  v0 = 0;
  while ( 1 )
  {
    while ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
    {
      v1 = g_idleWindow;
      if ( g_idleWindow == nullptr )
        break;
LABEL_10:
      v0 = 0;
      if ( v1 != nullptr )
      {
        handleEvent = v1->handleEvent;
        event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
        memset(&event.widget, 0, 40);
        event.event = 3;
        handleEvent(this: v1, a2: &event);
      }
    }
    if ( !GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
      return msg.wParam;
    if ( g_hAcceleratorTable == nullptr
      || (v5 = g_hAcceleratorTable,
          Handle = mxWidget::getHandle(this: g_mainWindow),
          TranslateAcceleratorA(hWnd: Handle, hAccTable: v5, lpMsg: &msg) == 0) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    if ( ++v0 > 10 )
    {
      v1 = g_idleWindow;
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2D20
// Name: public: static int mx::check(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mx::check()
{
  if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
    return 0;
  if ( GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
  {
    TranslateMessage(lpMsg: &msg);
    DispatchMessageA(lpMsg: &msg);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C2D70
// Name: public: static void mx::setIdleWindow(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx::setIdleWindow(mxWindow *window)
{
  g_idleWindow = window;
}

//------------------------------------------------------------------------------
// Address: 0x004C2D80
// Name: public: static char const __near * mx::getApplicationPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mx::getApplicationPath()
{
  _BYTE *v0; // eax

  GetModuleFileNameA(hModule: nullptr, lpFilename: path_0, nSize: 0x100u);
  strrchr(string: (unsigned __int8 *)path_0, chr: 0x5Cu);
  if ( v0 != nullptr )
    *v0 = 0;
  return path_0;
}

//------------------------------------------------------------------------------
// Address: 0x004C2DB0
// Name: public: static int mx::getTickCount(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall mx::getTickCount()
{
  return GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x004C2DC0
// Name: public: mxLinkedList::~mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::~mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v3; // edi
  mxListNode_s *d_tail; // [esp-4h] [ebp-8h]

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v3 = d_next->d_next;
      free(pMem: d_next);
      d_next = v3;
    }
    while ( v3 != this->d_tail );
  }
  this->d_head->d_next = this->d_tail;
  this->d_tail->d_prev = this->d_head;
  d_tail = this->d_tail;
  this->d_nodeCount = 0;
  free(pMem: d_tail);
  free(pMem: this->d_head);
}

//------------------------------------------------------------------------------
// Address: 0x004C2E20
// Name: public: static void mx::quit(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl mx::quit()
{
  mxLinkedList *v0; // eax
  mxListNode_s *d_prev; // esi
  void *d_data; // ecx
  mxListNode_s *v3; // esi
  void *v4; // ecx
  mxListNode_s *v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // ecx
  mxLinkedList *v7; // esi
  HMODULE ModuleHandleA; // eax

  isClosing = true;
  if ( g_mainWindow != nullptr && !g_mainWindow->Closing(this: g_mainWindow) )
  {
    isClosing = false;
    return;
  }
  v0 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    d_prev = g_widgetList->d_tail->d_prev;
    if ( d_prev != g_widgetList->d_head && d_prev != nullptr )
    {
      do
      {
        d_data = d_prev->d_data;
        d_prev = v0->d_head != d_prev->d_prev ? d_prev->d_prev : nullptr;
        if ( d_data != nullptr )
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)d_data + 4))(a1: d_data) == 0 )
          {
            isClosing = false;
            return;
          }
          v0 = g_widgetList;
        }
      }
      while ( d_prev != nullptr );
    }
    v3 = v0->d_tail->d_prev;
    if ( v3 != v0->d_head && v3 != nullptr )
    {
      do
      {
        v4 = v3->d_data;
        v3 = v0->d_head != v3->d_prev ? v3->d_prev : nullptr;
        if ( v4 != nullptr )
        {
          (*(void (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
          v0 = g_widgetList;
        }
      }
      while ( v3 != nullptr );
    }
    v5 = v0->d_tail->d_prev;
    if ( v5 != v0->d_head && v5 != nullptr )
    {
      do
      {
        v6 = (void (__thiscall ***)(_DWORD, int))v5->d_data;
        v5 = v0->d_head != v5->d_prev ? v5->d_prev : nullptr;
        if ( v6 != nullptr )
        {
          (**v6)(a1: v6, a2: 1);
          v0 = g_widgetList;
        }
      }
      while ( v5 != nullptr );
    }
    v7 = v0;
    if ( v0 != nullptr )
    {
      mxLinkedList::~mxLinkedList(this: v0);
      free(pMem: v7);
    }
  }
  if ( g_hwndToolTipControl != nullptr )
    DestroyWindow(hWnd: (HWND)g_hwndToolTipControl);
  if ( g_hAcceleratorTable != nullptr )
  {
    DestroyAcceleratorTable(hAccel: g_hAcceleratorTable);
    g_hAcceleratorTable = nullptr;
  }
  PostQuitMessage(nExitCode: 0);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  UnregisterClassA(lpClassName: "mx_class", hInstance: ModuleHandleA);
}

//------------------------------------------------------------------------------
// Address: 0x004C2F60
// Name: WndProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall WndProc(HWND hwnd, UINT uMessage, unsigned int wParam, unsigned int lParam)
{
  int result; // eax
  int v6; // eax
  mxWidget *v7; // eax
  int v8; // ecx
  LRESULT v9; // eax
  HWND v10; // ecx
  LONG v11; // eax
  LONG v12; // eax
  mxWidget *v13; // eax
  int v14; // ecx
  LONG v15; // eax
  mxWidget *v16; // eax
  int v17; // ecx
  LRESULT v18; // eax
  HWND v19; // ecx
  signed int v20; // eax
  mxWidget *v21; // eax
  int v22; // ecx
  int *v23; // eax
  int v24; // edx
  int *v25; // eax
  int v26; // edx
  int v27; // edx
  ConVar *v28; // eax
  ConVar *v29; // edi
  LONG v30; // eax
  LONG v31; // edi
  void (__stdcall *v32)(mxEvent *); // edx
  int v33; // eax
  int *WindowLongA; // edi
  LONG v35; // esi
  void (__thiscall *v36)(LONG, mxEvent *); // edx
  LONG v37; // eax
  int (__thiscall *v38)(LONG, mxEvent *); // edx
  LONG v39; // edi
  int (__thiscall *v40)(LONG, mxEvent *); // edx
  LONG v41; // eax
  bool v42; // zf
  ConVar *v43; // eax
  mxWidget *v44; // edi
  mxWindow *Parent; // eax
  int v46; // ebx
  LONG v47; // edi
  int v48; // ebx
  HWND v49; // [esp-10h] [ebp-ECh]
  HWND v50; // [esp-8h] [ebp-E4h]
  HWND v51; // [esp-8h] [ebp-E4h]
  HWND v52; // [esp-8h] [ebp-E4h]
  HWND v53; // [esp-8h] [ebp-E4h]
  HWND v54; // [esp-8h] [ebp-E4h]
  char className[128]; // [esp+Ch] [ebp-D0h] BYREF
  mxWindow *v56; // [esp+8Ch] [ebp-50h]
  LPARAM lParama[3]; // [esp+90h] [ebp-4Ch] BYREF
  tagRECT rc; // [esp+9Ch] [ebp-40h] BYREF
  mxEvent event; // [esp+ACh] [ebp-30h] BYREF
  HWND__ *hwnda; // [esp+E4h] [ebp+8h]
  mxWindow *window; // [esp+F0h] [ebp+14h]
  mxWindow *windowa; // [esp+F0h] [ebp+14h]
  mxWindow *windowb; // [esp+F0h] [ebp+14h]
  mxWindow *windowe; // [esp+F0h] [ebp+14h]
  mxWindow *windowf; // [esp+F0h] [ebp+14h]
  mxWindow *windowc; // [esp+F0h] [ebp+14h]
  mxWindow *windowd; // [esp+F0h] [ebp+14h]

  if ( uMessage > 0x100 )
  {
    if ( uMessage > 0x111 )
    {
      switch ( uMessage )
      {
        case 0x113u:
          if ( isClosing )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 2;
          goto LABEL_158;
        case 0x114u:
        case 0x115u:
          v43 = (ConVar *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
          v44 = (mxWidget *)v43;
          if ( v43 != nullptr
            && (mxWidget::getType(this: v43) == (const char *)15
             || mxWidget::getType(this: (ConVar *)v44) == (const char *)14)
            && (unsigned __int16)wParam <= 8u )
          {
            mxEvent::mxEvent(this: &event);
            event.event = 0;
            event.widget = v44;
            event.action = mxWidget::getId(this: v44);
            event.modifiers = (unsigned __int16)wParam;
            event.height = HIWORD(wParam);
            Parent = mxWidget::getParent(this: v44);
            if ( event.action > 0 )
              RecursiveHandleEvent(window: Parent, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x200u:
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v48 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.event = bDragging + 8;
          event.y = SHIWORD(lParam);
          event.modifiers = 0;
          if ( (wParam & 1) != 0 )
          {
            v48 = 1;
            event.buttons = 1;
          }
          if ( (wParam & 2) != 0 )
          {
            v48 |= 2u;
            event.buttons = v48;
          }
          if ( (wParam & 0x10) != 0 )
            event.buttons = v48 | 4;
          if ( (wParam & 8) != 0 )
            event.modifiers = 1;
          if ( (wParam & 4) != 0 )
            event.modifiers |= 2u;
          goto LABEL_158;
        case 0x201u:
        case 0x204u:
        case 0x207u:
          bDragging = true;
          SetCapture(hWnd: hwnd);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v46 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.y = SHIWORD(lParam);
          event.event = 7;
          event.modifiers = 0;
          if ( uMessage == 519 )
            event.buttons = 4;
          else
            event.buttons = (uMessage == 516) + 1;
          if ( (wParam & 1) != 0 )
            event.buttons |= 1u;
          if ( (wParam & 2) != 0 )
            event.buttons |= 2u;
          if ( (wParam & 0x10) != 0 )
            event.buttons |= 4u;
          if ( (wParam & 8) != 0 )
          {
            v46 = 1;
            event.modifiers = 1;
          }
          if ( (wParam & 4) != 0 )
            event.modifiers = v46 | 2;
LABEL_158:
          v24 = *WindowLongA;
LABEL_159:
          (*(void (__stdcall **)(mxEvent *))(v24 + 12))(a1: &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x202u:
        case 0x205u:
        case 0x208u:
          v47 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v47 != 0 )
          {
            mxEvent::mxEvent(this: &event);
            event.y = SHIWORD(lParam);
            event.event = 6;
            event.x = (__int16)lParam;
            event.modifiers = 0;
            if ( uMessage == 520 )
              event.buttons = 4;
            else
              event.buttons = (uMessage == 517) + 1;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers = 1;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            (*(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v47 + 12))(a1: v47, a2: &event);
          }
          bDragging = false;
          ReleaseCapture();
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x20Au:
          windowd = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( windowd != nullptr )
          {
            memset(dst: (unsigned __int8 *)&event, value: 0, count: sizeof(event));
            event.y = SHIWORD(lParam);
            event.event = 12;
            event.x = (__int16)lParam;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers |= 1u;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            event.height = SHIWORD(wParam);
            RecursiveHandleEvent(window: windowd, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x210u:
          v56 = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v56 == nullptr || wParam != 513 && wParam != 519 && wParam != 516 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.y = SHIWORD(lParam);
          event.event = 22;
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.modifiers = 0;
          if ( wParam == 513 )
          {
            event.buttons = 1;
          }
          else if ( wParam == 516 )
          {
            event.buttons = 2;
          }
          else
          {
            event.buttons = 4;
          }
          v56->handleEvent(this: v56, a2: &event);
          RecursiveHandleEvent(window: v56, &event);
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
    }
    if ( uMessage != 273 )
    {
      switch ( uMessage )
      {
        case 0x101u:
        case 0x105u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 10;
          goto LABEL_72;
        case 0x102u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 21;
LABEL_72:
          v40 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v39 + 12);
          event.key = wParam;
          if ( v40(a1: v39, a2: &event) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
LABEL_73:
          result = 0;
          break;
        case 0x104u:
          goto $LN25_5;
        case 0x106u:
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      return result;
    }
    v41 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    windowc = (mxWindow *)v41;
    if ( (_WORD)wParam != 0 && v41 != 0 )
    {
      mxEvent::mxEvent(this: &event);
      GetClassNameA(hWnd: (HWND)lParam, lpClassName: className, nMaxCount: 128);
      if ( _V_stricmp(s1: className, s2: "edit") != 0 )
      {
        if ( _V_stricmp(s1: className, s2: "combobox") != 0 && _V_stricmp(s1: className, s2: "listbox") != 0 )
          goto LABEL_84;
        v42 = HIWORD(wParam) == 1;
      }
      else
      {
        v42 = HIWORD(wParam) == 768;
      }
      if ( v42 )
      {
LABEL_84:
        event.event = 0;
        event.widget = (mxWidget *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
        event.action = (unsigned __int16)wParam;
        RecursiveHandleEvent(window: windowc, &event);
      }
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  if ( uMessage == 256 )
  {
$LN25_5:
    v37 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    if ( v37 != 0 )
    {
      v38 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v37 + 12);
      event.key = wParam;
      event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
      memset(&event.widget, 0, 28);
      event.modifiers = 0;
      event.flags = 0;
      event.event = 11;
      if ( v38(a1: v37, a2: &event) != 0 )
        return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  switch ( uMessage )
  {
    case 5u:
      mxEvent::mxEvent(this: &event);
      v23 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v23 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      event.width = (unsigned __int16)lParam;
      event.event = 1;
      event.height = HIWORD(lParam);
      v24 = *v23;
      goto LABEL_159;
    case 6u:
      windowa = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( windowa == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 14;
      event.widget = nullptr;
      event.action = (_WORD)wParam != 0;
      RecursiveHandleEvent(window: windowa, &event);
      return 0;
    case 7u:
    case 8u:
      window = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( window == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 13;
      event.widget = nullptr;
      event.action = uMessage == 7;
      RecursiveHandleEvent(window, &event);
      return 0;
    case 0xFu:
      if ( !isClosing )
      {
        v30 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
        if ( v30 != 0 )
          (*(void (__thiscall **)(LONG))(*(_DWORD *)v30 + 16))(a1: v30);
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0x10u:
      if ( g_mainWindow == nullptr )
        goto LABEL_73;
      if ( hwnd == mxWidget::getHandle(this: g_mainWindow) )
      {
        mx::quit();
        return 0;
      }
      ShowWindow(hWnd: hwnd, nCmdShow: 0);
      v35 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v35 == 0 )
        goto LABEL_73;
      mxEvent::mxEvent(this: &event);
      v36 = *(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v35 + 12);
      event.event = 19;
      v36(a1: v35, a2: &event);
      return 0;
    case 0x14u:
      v28 = (ConVar *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v29 = v28;
      if ( v28 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      if ( mxWidget::getType(this: v28) == (const char *)3 || mxWidget::getType(this: v29) == (const char *)4 )
        return 0;
      if ( isClosing || (unsigned __int8)v29->GetFlags(this: v29) != 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      return 0;
    case 0x47u:
      mxEvent::mxEvent(this: &event);
      v25 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v25 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v26 = *(_DWORD *)(lParam + 12);
      event.x = *(_DWORD *)(lParam + 8);
      event.width = *(_DWORD *)(lParam + 16);
      event.y = v26;
      v27 = *(_DWORD *)(lParam + 20);
      event.event = 20;
      event.height = v27;
      v24 = *v25;
      goto LABEL_159;
    case 0x4Eu:
      if ( isClosing )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      v6 = *(_DWORD *)(lParam + 8);
      switch ( v6 )
      {
        case -402:
          if ( *(_DWORD *)(lParam + 4) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          windowb = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v50 = *(HWND *)lParam;
          event.event = 0;
          v7 = (mxWidget *)GetWindowLongA(hWnd: v50, nIndex: -21);
          v8 = *(_DWORD *)(lParam + 4);
          event.widget = v7;
          event.action = v8;
LABEL_13:
          v9 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
          v10 = *(HWND *)lParam;
          rc.left = v9;
          SendMessageA(hWnd: v10, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
          event.x = rc.left;
          event.y = rc.bottom;
LABEL_14:
          RecursiveHandleEvent(window: windowb, &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -101:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v11 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v51 = *(HWND *)lParam;
            windowe = (mxWindow *)v11;
            event.event = 0;
            event.widget = (mxWidget *)GetWindowLongA(hWnd: v51, nIndex: -21);
            event.action = *(_DWORD *)(lParam + 4);
            RecursiveHandleEvent(window: windowe, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -5:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v12 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v52 = *(HWND *)lParam;
            windowb = (mxWindow *)v12;
            event.event = 0;
            v13 = (mxWidget *)GetWindowLongA(hWnd: v52, nIndex: -21);
            v14 = *(_DWORD *)(lParam + 4);
            event.widget = v13;
            event.action = v14;
            event.flags = 1;
            if ( v13 == nullptr || mxWidget::getType(this: (ConVar *)v13) != (const char *)18 )
              goto LABEL_14;
            goto LABEL_13;
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        default:
          break;
      }
      if ( v6 != -3 )
      {
        if ( v6 == -552 )
        {
          v20 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x130Bu, wParam: 0, lParam: 0);
          if ( v20 >= 0 )
          {
            v49 = *(HWND *)lParam;
            lParama[0] = 8;
            SendMessageA(hWnd: v49, Msg: 0x1305u, wParam: v20, lParam: (LPARAM)lParama);
            if ( rc.bottom != 0 )
              mxWidget::setVisible(this: (mxWidget *)rc.bottom, b: false);
          }
        }
        else if ( v6 == -551 )
        {
          mxTab_resizeChild(hwnd: *(HWND__ **)lParam);
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            windowf = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v54 = *(HWND *)lParam;
            event.event = 0;
            v21 = (mxWidget *)GetWindowLongA(hWnd: v54, nIndex: -21);
            v22 = *(_DWORD *)(lParam + 4);
            event.widget = v21;
            event.action = v22;
            RecursiveHandleEvent(window: windowf, &event);
          }
        }
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      if ( *(_DWORD *)(lParam + 4) == 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v15 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v53 = *(HWND *)lParam;
      hwnda = (HWND__ *)v15;
      event.event = 0;
      v16 = (mxWidget *)GetWindowLongA(hWnd: v53, nIndex: -21);
      v17 = *(_DWORD *)(lParam + 4);
      event.widget = v16;
      event.action = v17;
      event.flags = 2;
      if ( v16 != nullptr && mxWidget::getType(this: (ConVar *)v16) == (const char *)18 )
      {
        v18 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
        v19 = *(HWND *)lParam;
        rc.left = v18;
        SendMessageA(hWnd: v19, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
        event.x = rc.left;
        event.y = rc.bottom;
      }
      RecursiveHandleEvent(window: (mxWindow *)hwnda, &event);
      result = 1;
      break;
    case 0xA0u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 17;
      event.x = (__int16)lParam;
      event.y = SHIWORD(lParam);
      event.buttons = 0;
      event.modifiers = 0;
      goto LABEL_158;
    case 0xA1u:
    case 0xA4u:
    case 0xA7u:
      v31 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v31 != 0 )
      {
        mxEvent::mxEvent(this: &event);
        event.event = 16;
        event.x = (__int16)lParam;
        event.y = SHIWORD(lParam);
        event.modifiers = 0;
        if ( uMessage == 167 )
        {
          v32 = *(void (__stdcall **)(mxEvent *))(*(_DWORD *)v31 + 12);
          event.buttons = 4;
          v32(a1: &event);
        }
        else
        {
          v33 = *(_DWORD *)v31;
          event.buttons = (uMessage == 164) + 1;
          (*(void (__stdcall **)(mxEvent *))(v33 + 12))(a1: &event);
        }
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0xA2u:
    case 0xA5u:
    case 0xA8u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.y = SHIWORD(lParam);
      event.event = 15;
      event.x = (__int16)lParam;
      event.modifiers = 0;
      if ( uMessage == 168 )
        event.buttons = 4;
      else
        event.buttons = (uMessage == 165) + 1;
      goto LABEL_158;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C3D10
// Name: public: static int mx::init(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mx::init()
{
  mxLinkedList *v1; // eax
  tagWNDCLASSA wc; // [esp+8h] [ebp-28h] BYREF

  wc.style = 35;
  wc.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  wc.hIcon = LoadIconA(hInstance: wc.hInstance, lpIconName: "MX_ICON");
  wc.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wc.hbrBackground = (HBRUSH__ *)5;
  wc.lpszMenuName = nullptr;
  wc.lpszClassName = "mx_class";
  if ( wc.hIcon == nullptr )
    wc.hIcon = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F05);
  if ( RegisterClassA(lpWndClass: &wc) == 0 )
    return 0;
  InitCommonControls();
  v1 = (mxLinkedList *)operator new(nSize: 0xCu);
  if ( v1 != nullptr )
    g_widgetList = mxLinkedList::mxLinkedList(this: v1);
  else
    g_widgetList = nullptr;
  isClosing = false;
  return 1;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056E130
// Name: public: mxLinkedList::mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
mxLinkedList *__thiscall mxLinkedList::mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *v2; // eax
  mxListNode_s *d_head; // ecx

  this->d_head = (mxListNode_s *)operator new(nSize: 0xCu);
  v2 = (mxListNode_s *)operator new(nSize: 0xCu);
  d_head = this->d_head;
  this->d_tail = v2;
  d_head->d_data = nullptr;
  this->d_head->d_next = this->d_tail;
  this->d_head->d_prev = nullptr;
  this->d_tail->d_data = nullptr;
  this->d_tail->d_next = nullptr;
  this->d_tail->d_prev = this->d_head;
  this->d_nodeCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056E180
// Name: public: void mxLinkedList::remove(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::remove(mxLinkedList *this, void *data)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v4; // esi

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v4 = d_next->d_next;
      if ( d_next->d_data == data )
      {
        d_next->d_prev->d_next = v4;
        d_next->d_next->d_prev = d_next->d_prev;
        free(pMem: d_next);
      }
      d_next = v4;
    }
    while ( v4 != this->d_tail );
  }
  --this->d_nodeCount;
}

//------------------------------------------------------------------------------
// Address: 0x0056E1D0
// Name: void mx_addWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_addWidget(mxWidget *widget)
{
  mxLinkedList *v1; // esi
  mxListNode_s *v2; // eax

  v1 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    v2 = (mxListNode_s *)operator new(nSize: 0xCu);
    v2->d_data = widget;
    v1->d_tail->d_prev->d_next = v2;
    v2->d_prev = v1->d_tail->d_prev;
    v2->d_next = v1->d_tail;
    v1->d_tail->d_prev = v2;
    ++v1->d_nodeCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056E220
// Name: void mx_removeWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_removeWidget(mxWidget *widget)
{
  if ( g_widgetList != nullptr )
    mxLinkedList::remove(this: g_widgetList, data: widget);
}

//------------------------------------------------------------------------------
// Address: 0x0056E240
// Name: struct HWND__ __near * mx_CreateToolTipControl(void)
// Source: json
//------------------------------------------------------------------------------
HWND__ *__cdecl mx_CreateToolTipControl()
{
  HWND__ *result; // eax
  HWND__ *Handle; // eax
  HMODULE ModuleHandleA; // [esp-8h] [ebp-8h]
  char *v3; // [esp-4h] [ebp-4h]

  result = (HWND__ *)g_hwndToolTipControl;
  if ( g_hwndToolTipControl == nullptr && g_mainWindow != nullptr )
  {
    v3 = (char *)g_hwndToolTipControl;
    ModuleHandleA = GetModuleHandleA(lpModuleName: g_hwndToolTipControl);
    Handle = mxWidget::getHandle(this: g_mainWindow);
    result = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "tooltips_class32",
               lpWindowName: WindowName,
               dwStyle: 0x80000008,
               X: 0,
               Y: 0,
               nWidth: 0,
               nHeight: 0,
               hWndParent: Handle,
               hMenu: nullptr,
               hInstance: ModuleHandleA,
               lpParam: v3);
    g_hwndToolTipControl = (LPCSTR)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056E290
// Name: RecursiveHandleEvent
// Source: json
//------------------------------------------------------------------------------
void __usercall RecursiveHandleEvent(mxWindow *window@<eax>, mxEvent *event@<edi>)
{
  mxWindow *i; // esi

  for ( i = window; i != nullptr; i = mxWidget::getParent(this: i) )
  {
    if ( i->handleEvent(this: i, a2: event) != 0 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056E2C0
// Name: public: static int mx::run(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl mx::run()
{
  int v0; // edi
  mxWindow *v1; // ecx
  HWND__ *Handle; // eax
  int (__thiscall *handleEvent)(mxWindow *, mxEvent *); // eax
  HACCEL v5; // [esp-8h] [ebp-44h]
  mxEvent event; // [esp+Ch] [ebp-30h] BYREF

  v0 = 0;
  while ( 1 )
  {
    while ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
    {
      v1 = g_idleWindow;
      if ( g_idleWindow == nullptr )
        break;
LABEL_10:
      v0 = 0;
      if ( v1 != nullptr )
      {
        handleEvent = v1->handleEvent;
        event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
        memset(&event.widget, 0, 40);
        event.event = 3;
        handleEvent(this: v1, a2: &event);
      }
    }
    if ( !GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
      return msg.wParam;
    if ( g_hAcceleratorTable == nullptr
      || (v5 = g_hAcceleratorTable,
          Handle = mxWidget::getHandle(this: g_mainWindow),
          TranslateAcceleratorA(hWnd: Handle, hAccTable: v5, lpMsg: &msg) == 0) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    if ( ++v0 > 10 )
    {
      v1 = g_idleWindow;
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056E3A0
// Name: public: static void mx::setIdleWindow(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx::setIdleWindow(mxWindow *window)
{
  g_idleWindow = window;
}

//------------------------------------------------------------------------------
// Address: 0x0056E3B0
// Name: public: static char const __near * mx::getApplicationPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mx::getApplicationPath()
{
  _BYTE *v0; // eax

  GetModuleFileNameA(hModule: nullptr, lpFilename: path, nSize: 0x100u);
  strrchr(string: (unsigned __int8 *)path, chr: 0x5Cu);
  if ( v0 != nullptr )
    *v0 = 0;
  return path;
}

//------------------------------------------------------------------------------
// Address: 0x0056E3E0
// Name: public: static int mx::getTickCount(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall mx::getTickCount()
{
  return GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x0056E3F0
// Name: public: mxLinkedList::~mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::~mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v3; // edi
  mxListNode_s *d_tail; // [esp-4h] [ebp-8h]

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v3 = d_next->d_next;
      free(pMem: d_next);
      d_next = v3;
    }
    while ( v3 != this->d_tail );
  }
  this->d_head->d_next = this->d_tail;
  this->d_tail->d_prev = this->d_head;
  d_tail = this->d_tail;
  this->d_nodeCount = 0;
  free(pMem: d_tail);
  free(pMem: this->d_head);
}

//------------------------------------------------------------------------------
// Address: 0x0056E450
// Name: public: static void mx::quit(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl mx::quit()
{
  mxLinkedList *v0; // eax
  mxListNode_s *d_prev; // esi
  void *d_data; // ecx
  mxListNode_s *v3; // esi
  void *v4; // ecx
  mxListNode_s *v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // ecx
  mxLinkedList *v7; // esi
  HMODULE ModuleHandleA; // eax

  isClosing = true;
  if ( g_mainWindow != nullptr && !g_mainWindow->Closing(this: g_mainWindow) )
  {
    isClosing = false;
    return;
  }
  v0 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    d_prev = g_widgetList->d_tail->d_prev;
    if ( d_prev != g_widgetList->d_head && d_prev != nullptr )
    {
      do
      {
        d_data = d_prev->d_data;
        d_prev = v0->d_head != d_prev->d_prev ? d_prev->d_prev : nullptr;
        if ( d_data != nullptr )
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)d_data + 4))(a1: d_data) == 0 )
          {
            isClosing = false;
            return;
          }
          v0 = g_widgetList;
        }
      }
      while ( d_prev != nullptr );
    }
    v3 = v0->d_tail->d_prev;
    if ( v3 != v0->d_head && v3 != nullptr )
    {
      do
      {
        v4 = v3->d_data;
        v3 = v0->d_head != v3->d_prev ? v3->d_prev : nullptr;
        if ( v4 != nullptr )
        {
          (*(void (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
          v0 = g_widgetList;
        }
      }
      while ( v3 != nullptr );
    }
    v5 = v0->d_tail->d_prev;
    if ( v5 != v0->d_head && v5 != nullptr )
    {
      do
      {
        v6 = (void (__thiscall ***)(_DWORD, int))v5->d_data;
        v5 = v0->d_head != v5->d_prev ? v5->d_prev : nullptr;
        if ( v6 != nullptr )
        {
          (**v6)(a1: v6, a2: 1);
          v0 = g_widgetList;
        }
      }
      while ( v5 != nullptr );
    }
    v7 = v0;
    if ( v0 != nullptr )
    {
      mxLinkedList::~mxLinkedList(this: v0);
      free(pMem: v7);
    }
  }
  if ( g_hwndToolTipControl != nullptr )
    DestroyWindow(hWnd: (HWND)g_hwndToolTipControl);
  if ( g_hAcceleratorTable != nullptr )
  {
    DestroyAcceleratorTable(hAccel: g_hAcceleratorTable);
    g_hAcceleratorTable = nullptr;
  }
  PostQuitMessage(nExitCode: 0);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  UnregisterClassA(lpClassName: "mx_class", hInstance: ModuleHandleA);
}

//------------------------------------------------------------------------------
// Address: 0x0056E590
// Name: WndProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall WndProc(HWND hwnd, UINT uMessage, unsigned int wParam, unsigned int lParam)
{
  int result; // eax
  int v6; // eax
  mxWidget *v7; // eax
  int v8; // ecx
  LRESULT v9; // eax
  HWND v10; // ecx
  LONG v11; // eax
  LONG v12; // eax
  mxWidget *v13; // eax
  int v14; // ecx
  LONG v15; // eax
  mxWidget *v16; // eax
  int v17; // ecx
  LRESULT v18; // eax
  HWND v19; // ecx
  signed int v20; // eax
  mxWidget *v21; // eax
  int v22; // ecx
  int *v23; // eax
  int v24; // edx
  int *v25; // eax
  int v26; // edx
  int v27; // edx
  ConVar *v28; // eax
  ConVar *v29; // edi
  LONG v30; // eax
  LONG v31; // edi
  void (__stdcall *v32)(mxEvent *); // edx
  int v33; // eax
  int *WindowLongA; // edi
  LONG v35; // esi
  void (__thiscall *v36)(LONG, mxEvent *); // edx
  LONG v37; // eax
  int (__thiscall *v38)(LONG, mxEvent *); // edx
  LONG v39; // edi
  int (__thiscall *v40)(LONG, mxEvent *); // edx
  LONG v41; // eax
  bool v42; // zf
  ConVar *v43; // eax
  mxWidget *v44; // edi
  mxWindow *Parent; // eax
  int v46; // ebx
  LONG v47; // edi
  int v48; // ebx
  HWND v49; // [esp-10h] [ebp-ECh]
  HWND v50; // [esp-8h] [ebp-E4h]
  HWND v51; // [esp-8h] [ebp-E4h]
  HWND v52; // [esp-8h] [ebp-E4h]
  HWND v53; // [esp-8h] [ebp-E4h]
  HWND v54; // [esp-8h] [ebp-E4h]
  char className[128]; // [esp+Ch] [ebp-D0h] BYREF
  mxWindow *v56; // [esp+8Ch] [ebp-50h]
  LPARAM lParama[3]; // [esp+90h] [ebp-4Ch] BYREF
  tagRECT rc; // [esp+9Ch] [ebp-40h] BYREF
  mxEvent event; // [esp+ACh] [ebp-30h] BYREF
  HWND__ *hwnda; // [esp+E4h] [ebp+8h]
  mxWindow *window; // [esp+F0h] [ebp+14h]
  mxWindow *windowa; // [esp+F0h] [ebp+14h]
  mxWindow *windowb; // [esp+F0h] [ebp+14h]
  mxWindow *windowe; // [esp+F0h] [ebp+14h]
  mxWindow *windowf; // [esp+F0h] [ebp+14h]
  mxWindow *windowc; // [esp+F0h] [ebp+14h]
  mxWindow *windowd; // [esp+F0h] [ebp+14h]

  if ( uMessage > 0x100 )
  {
    if ( uMessage > 0x111 )
    {
      switch ( uMessage )
      {
        case 0x113u:
          if ( isClosing )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 2;
          goto LABEL_158;
        case 0x114u:
        case 0x115u:
          v43 = (ConVar *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
          v44 = (mxWidget *)v43;
          if ( v43 != nullptr
            && (mxWidget::getType(this: v43) == (const char *)15
             || mxWidget::getType(this: (ConVar *)v44) == (const char *)14)
            && (unsigned __int16)wParam <= 8u )
          {
            mxEvent::mxEvent(this: &event);
            event.event = 0;
            event.widget = v44;
            event.action = mxWidget::getId(this: v44);
            event.modifiers = (unsigned __int16)wParam;
            event.height = HIWORD(wParam);
            Parent = mxWidget::getParent(this: v44);
            if ( event.action > 0 )
              RecursiveHandleEvent(window: Parent, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x200u:
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v48 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.event = bDragging + 8;
          event.y = SHIWORD(lParam);
          event.modifiers = 0;
          if ( (wParam & 1) != 0 )
          {
            v48 = 1;
            event.buttons = 1;
          }
          if ( (wParam & 2) != 0 )
          {
            v48 |= 2u;
            event.buttons = v48;
          }
          if ( (wParam & 0x10) != 0 )
            event.buttons = v48 | 4;
          if ( (wParam & 8) != 0 )
            event.modifiers = 1;
          if ( (wParam & 4) != 0 )
            event.modifiers |= 2u;
          goto LABEL_158;
        case 0x201u:
        case 0x204u:
        case 0x207u:
          bDragging = true;
          SetCapture(hWnd: hwnd);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v46 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.y = SHIWORD(lParam);
          event.event = 7;
          event.modifiers = 0;
          if ( uMessage == 519 )
            event.buttons = 4;
          else
            event.buttons = (uMessage == 516) + 1;
          if ( (wParam & 1) != 0 )
            event.buttons |= 1u;
          if ( (wParam & 2) != 0 )
            event.buttons |= 2u;
          if ( (wParam & 0x10) != 0 )
            event.buttons |= 4u;
          if ( (wParam & 8) != 0 )
          {
            v46 = 1;
            event.modifiers = 1;
          }
          if ( (wParam & 4) != 0 )
            event.modifiers = v46 | 2;
LABEL_158:
          v24 = *WindowLongA;
LABEL_159:
          (*(void (__stdcall **)(mxEvent *))(v24 + 12))(a1: &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x202u:
        case 0x205u:
        case 0x208u:
          v47 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v47 != 0 )
          {
            mxEvent::mxEvent(this: &event);
            event.y = SHIWORD(lParam);
            event.event = 6;
            event.x = (__int16)lParam;
            event.modifiers = 0;
            if ( uMessage == 520 )
              event.buttons = 4;
            else
              event.buttons = (uMessage == 517) + 1;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers = 1;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            (*(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v47 + 12))(a1: v47, a2: &event);
          }
          bDragging = false;
          ReleaseCapture();
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x20Au:
          windowd = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( windowd != nullptr )
          {
            memset(dst: (unsigned __int8 *)&event, value: 0, count: sizeof(event));
            event.y = SHIWORD(lParam);
            event.event = 12;
            event.x = (__int16)lParam;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers |= 1u;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            event.height = SHIWORD(wParam);
            RecursiveHandleEvent(window: windowd, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x210u:
          v56 = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v56 == nullptr || wParam != 513 && wParam != 519 && wParam != 516 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.y = SHIWORD(lParam);
          event.event = 22;
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.modifiers = 0;
          if ( wParam == 513 )
          {
            event.buttons = 1;
          }
          else if ( wParam == 516 )
          {
            event.buttons = 2;
          }
          else
          {
            event.buttons = 4;
          }
          v56->handleEvent(this: v56, a2: &event);
          RecursiveHandleEvent(window: v56, &event);
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
    }
    if ( uMessage != 273 )
    {
      switch ( uMessage )
      {
        case 0x101u:
        case 0x105u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 10;
          goto LABEL_72;
        case 0x102u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 21;
LABEL_72:
          v40 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v39 + 12);
          event.key = wParam;
          if ( v40(a1: v39, a2: &event) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
LABEL_73:
          result = 0;
          break;
        case 0x104u:
          goto $LN25_17;
        case 0x106u:
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      return result;
    }
    v41 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    windowc = (mxWindow *)v41;
    if ( (_WORD)wParam != 0 && v41 != 0 )
    {
      mxEvent::mxEvent(this: &event);
      GetClassNameA(hWnd: (HWND)lParam, lpClassName: className, nMaxCount: 128);
      if ( _V_stricmp(s1: className, s2: "edit") != 0 )
      {
        if ( _V_stricmp(s1: className, s2: "combobox") != 0 && _V_stricmp(s1: className, s2: "listbox") != 0 )
          goto LABEL_84;
        v42 = HIWORD(wParam) == 1;
      }
      else
      {
        v42 = HIWORD(wParam) == 768;
      }
      if ( v42 )
      {
LABEL_84:
        event.event = 0;
        event.widget = (mxWidget *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
        event.action = (unsigned __int16)wParam;
        RecursiveHandleEvent(window: windowc, &event);
      }
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  if ( uMessage == 256 )
  {
$LN25_17:
    v37 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    if ( v37 != 0 )
    {
      v38 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v37 + 12);
      event.key = wParam;
      event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
      memset(&event.widget, 0, 28);
      event.modifiers = 0;
      event.flags = 0;
      event.event = 11;
      if ( v38(a1: v37, a2: &event) != 0 )
        return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  switch ( uMessage )
  {
    case 5u:
      mxEvent::mxEvent(this: &event);
      v23 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v23 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      event.width = (unsigned __int16)lParam;
      event.event = 1;
      event.height = HIWORD(lParam);
      v24 = *v23;
      goto LABEL_159;
    case 6u:
      windowa = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( windowa == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 14;
      event.widget = nullptr;
      event.action = (_WORD)wParam != 0;
      RecursiveHandleEvent(window: windowa, &event);
      return 0;
    case 7u:
    case 8u:
      window = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( window == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 13;
      event.widget = nullptr;
      event.action = uMessage == 7;
      RecursiveHandleEvent(window, &event);
      return 0;
    case 0xFu:
      if ( !isClosing )
      {
        v30 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
        if ( v30 != 0 )
          (*(void (__thiscall **)(LONG))(*(_DWORD *)v30 + 16))(a1: v30);
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0x10u:
      if ( g_mainWindow == nullptr )
        goto LABEL_73;
      if ( hwnd == mxWidget::getHandle(this: g_mainWindow) )
      {
        mx::quit();
        return 0;
      }
      ShowWindow(hWnd: hwnd, nCmdShow: 0);
      v35 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v35 == 0 )
        goto LABEL_73;
      mxEvent::mxEvent(this: &event);
      v36 = *(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v35 + 12);
      event.event = 19;
      v36(a1: v35, a2: &event);
      return 0;
    case 0x14u:
      v28 = (ConVar *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v29 = v28;
      if ( v28 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      if ( mxWidget::getType(this: v28) == (const char *)3 || mxWidget::getType(this: v29) == (const char *)4 )
        return 0;
      if ( isClosing || (unsigned __int8)v29->GetFlags(this: v29) != 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      return 0;
    case 0x47u:
      mxEvent::mxEvent(this: &event);
      v25 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v25 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v26 = *(_DWORD *)(lParam + 12);
      event.x = *(_DWORD *)(lParam + 8);
      event.width = *(_DWORD *)(lParam + 16);
      event.y = v26;
      v27 = *(_DWORD *)(lParam + 20);
      event.event = 20;
      event.height = v27;
      v24 = *v25;
      goto LABEL_159;
    case 0x4Eu:
      if ( isClosing )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      v6 = *(_DWORD *)(lParam + 8);
      switch ( v6 )
      {
        case -402:
          if ( *(_DWORD *)(lParam + 4) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          windowb = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v50 = *(HWND *)lParam;
          event.event = 0;
          v7 = (mxWidget *)GetWindowLongA(hWnd: v50, nIndex: -21);
          v8 = *(_DWORD *)(lParam + 4);
          event.widget = v7;
          event.action = v8;
LABEL_13:
          v9 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
          v10 = *(HWND *)lParam;
          rc.left = v9;
          SendMessageA(hWnd: v10, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
          event.x = rc.left;
          event.y = rc.bottom;
LABEL_14:
          RecursiveHandleEvent(window: windowb, &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -101:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v11 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v51 = *(HWND *)lParam;
            windowe = (mxWindow *)v11;
            event.event = 0;
            event.widget = (mxWidget *)GetWindowLongA(hWnd: v51, nIndex: -21);
            event.action = *(_DWORD *)(lParam + 4);
            RecursiveHandleEvent(window: windowe, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -5:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v12 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v52 = *(HWND *)lParam;
            windowb = (mxWindow *)v12;
            event.event = 0;
            v13 = (mxWidget *)GetWindowLongA(hWnd: v52, nIndex: -21);
            v14 = *(_DWORD *)(lParam + 4);
            event.widget = v13;
            event.action = v14;
            event.flags = 1;
            if ( v13 == nullptr || mxWidget::getType(this: (ConVar *)v13) != (const char *)18 )
              goto LABEL_14;
            goto LABEL_13;
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        default:
          break;
      }
      if ( v6 != -3 )
      {
        if ( v6 == -552 )
        {
          v20 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x130Bu, wParam: 0, lParam: 0);
          if ( v20 >= 0 )
          {
            v49 = *(HWND *)lParam;
            lParama[0] = 8;
            SendMessageA(hWnd: v49, Msg: 0x1305u, wParam: v20, lParam: (LPARAM)lParama);
            if ( rc.bottom != 0 )
              mxWidget::setVisible(this: (mxWidget *)rc.bottom, b: false);
          }
        }
        else if ( v6 == -551 )
        {
          mxTab_resizeChild(hwnd: *(HWND__ **)lParam);
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            windowf = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v54 = *(HWND *)lParam;
            event.event = 0;
            v21 = (mxWidget *)GetWindowLongA(hWnd: v54, nIndex: -21);
            v22 = *(_DWORD *)(lParam + 4);
            event.widget = v21;
            event.action = v22;
            RecursiveHandleEvent(window: windowf, &event);
          }
        }
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      if ( *(_DWORD *)(lParam + 4) == 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v15 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v53 = *(HWND *)lParam;
      hwnda = (HWND__ *)v15;
      event.event = 0;
      v16 = (mxWidget *)GetWindowLongA(hWnd: v53, nIndex: -21);
      v17 = *(_DWORD *)(lParam + 4);
      event.widget = v16;
      event.action = v17;
      event.flags = 2;
      if ( v16 != nullptr && mxWidget::getType(this: (ConVar *)v16) == (const char *)18 )
      {
        v18 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
        v19 = *(HWND *)lParam;
        rc.left = v18;
        SendMessageA(hWnd: v19, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
        event.x = rc.left;
        event.y = rc.bottom;
      }
      RecursiveHandleEvent(window: (mxWindow *)hwnda, &event);
      result = 1;
      break;
    case 0xA0u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 17;
      event.x = (__int16)lParam;
      event.y = SHIWORD(lParam);
      event.buttons = 0;
      event.modifiers = 0;
      goto LABEL_158;
    case 0xA1u:
    case 0xA4u:
    case 0xA7u:
      v31 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v31 != 0 )
      {
        mxEvent::mxEvent(this: &event);
        event.event = 16;
        event.x = (__int16)lParam;
        event.y = SHIWORD(lParam);
        event.modifiers = 0;
        if ( uMessage == 167 )
        {
          v32 = *(void (__stdcall **)(mxEvent *))(*(_DWORD *)v31 + 12);
          event.buttons = 4;
          v32(a1: &event);
        }
        else
        {
          v33 = *(_DWORD *)v31;
          event.buttons = (uMessage == 164) + 1;
          (*(void (__stdcall **)(mxEvent *))(v33 + 12))(a1: &event);
        }
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0xA2u:
    case 0xA5u:
    case 0xA8u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.y = SHIWORD(lParam);
      event.event = 15;
      event.x = (__int16)lParam;
      event.modifiers = 0;
      if ( uMessage == 168 )
        event.buttons = 4;
      else
        event.buttons = (uMessage == 165) + 1;
      goto LABEL_158;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056F340
// Name: public: static int mx::init(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mx::init()
{
  mxLinkedList *v1; // eax
  tagWNDCLASSA wc; // [esp+8h] [ebp-28h] BYREF

  wc.style = 35;
  wc.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  wc.hIcon = LoadIconA(hInstance: wc.hInstance, lpIconName: "MX_ICON");
  wc.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wc.hbrBackground = (HBRUSH__ *)5;
  wc.lpszMenuName = nullptr;
  wc.lpszClassName = "mx_class";
  if ( wc.hIcon == nullptr )
    wc.hIcon = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F05);
  if ( RegisterClassA(lpWndClass: &wc) == 0 )
    return 0;
  InitCommonControls();
  v1 = (mxLinkedList *)operator new(nSize: 0xCu);
  if ( v1 != nullptr )
    g_widgetList = mxLinkedList::mxLinkedList(this: v1);
  else
    g_widgetList = nullptr;
  isClosing = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0056F410
// Name: public: static void mx::createAccleratorTable(int,struct mx::Accel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx::createAccleratorTable(int numentries, mx::Accel_t *entries)
{
  tagACCEL *m_pMemory; // ebx
  int m_Size; // edi
  mx::Accel_t *v5; // ecx
  unsigned __int16 command; // dx
  unsigned __int8 flags; // al
  int v8; // esi
  tagACCEL *v9; // eax
  bool v10; // zf
  CUtlVector<tagACCEL,CUtlMemory<tagACCEL,int> > accelentries; // [esp+Ch] [ebp-20h] BYREF
  tagACCEL add; // [esp+20h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-4h]
  mx::Accel_t *numentriesa; // [esp+34h] [ebp+8h]

  m_pMemory = nullptr;
  m_Size = 0;
  memset(&accelentries, 0, sizeof(accelentries));
  if ( numentries > 0 )
  {
    v5 = entries;
    numentriesa = entries;
    v13 = numentries;
    do
    {
      command = v5->command;
      add.key = v5->key;
      flags = v5->flags;
      add.cmd = command;
      add.fVirt = 0;
      if ( (flags & 1) != 0 )
        add.fVirt = 16;
      if ( (flags & 2) != 0 )
        add.fVirt |= 8u;
      if ( (flags & 4) != 0 )
        add.fVirt |= 4u;
      if ( (flags & 8) != 0 )
        add.fVirt |= 1u;
      v8 = m_Size;
      if ( m_Size + 1 > accelentries.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<mx::Accel_t,int>::Grow(
          this: &accelentries.m_Memory,
          num: m_Size - accelentries.m_Memory.m_nAllocationCount + 1);
        m_Size = accelentries.m_Size;
        m_pMemory = accelentries.m_Memory.m_pMemory;
        v5 = numentriesa;
      }
      accelentries.m_Size = ++m_Size;
      accelentries.m_pElements = m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 6 * (m_Size - v8 - 1));
        v5 = numentriesa;
      }
      v9 = &m_pMemory[v8];
      if ( v9 != nullptr )
        *v9 = add;
      ++v5;
      v10 = v13-- == 1;
      numentriesa = v5;
    }
    while ( !v10 );
  }
  g_hAcceleratorTable = CreateAcceleratorTableA(paccel: m_pMemory, cAccel: m_Size);
  if ( accelentries.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004294C0
// Name: public: mxEvent::mxEvent(void)
// Source: json
//------------------------------------------------------------------------------
mxEvent *__thiscall mxEvent::mxEvent(mxEvent *this)
{
  this->__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
  this->event = 0;
  this->widget = nullptr;
  this->action = 0;
  this->width = 0;
  this->height = 0;
  this->x = 0;
  this->y = 0;
  this->buttons = 0;
  this->key = 0;
  this->modifiers = 0;
  this->flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429520
// Name: public: mxLinkedList::mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
mxLinkedList *__thiscall mxLinkedList::mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *v2; // eax
  mxListNode_s *d_head; // ecx

  this->d_head = (mxListNode_s *)operator new(nSize: 0xCu);
  v2 = (mxListNode_s *)operator new(nSize: 0xCu);
  d_head = this->d_head;
  this->d_tail = v2;
  d_head->d_data = nullptr;
  this->d_head->d_next = this->d_tail;
  this->d_head->d_prev = nullptr;
  this->d_tail->d_data = nullptr;
  this->d_tail->d_next = nullptr;
  this->d_tail->d_prev = this->d_head;
  this->d_nodeCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429570
// Name: public: void mxLinkedList::remove(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::remove(mxLinkedList *this, void *data)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v4; // esi

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v4 = d_next->d_next;
      if ( d_next->d_data == data )
      {
        d_next->d_prev->d_next = v4;
        d_next->d_next->d_prev = d_next->d_prev;
        free(pMem: d_next);
      }
      d_next = v4;
    }
    while ( v4 != this->d_tail );
  }
  --this->d_nodeCount;
}

//------------------------------------------------------------------------------
// Address: 0x004295C0
// Name: void mx_addWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_addWidget(mxWidget *widget)
{
  mxLinkedList *v1; // esi
  mxListNode_s *v2; // eax

  v1 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    v2 = (mxListNode_s *)operator new(nSize: 0xCu);
    v2->d_data = widget;
    v1->d_tail->d_prev->d_next = v2;
    v2->d_prev = v1->d_tail->d_prev;
    v2->d_next = v1->d_tail;
    v1->d_tail->d_prev = v2;
    ++v1->d_nodeCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429610
// Name: void mx_removeWidget(class mxWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx_removeWidget(mxWidget *widget)
{
  if ( g_widgetList != nullptr )
    mxLinkedList::remove(this: g_widgetList, data: widget);
}

//------------------------------------------------------------------------------
// Address: 0x00429630
// Name: RecursiveHandleEvent
// Source: json
//------------------------------------------------------------------------------
void __usercall RecursiveHandleEvent(mxWindow *window@<eax>, mxEvent *event@<edi>)
{
  mxWindow *i; // esi

  for ( i = window; i != nullptr; i = mxWidget::getParent(this: i) )
  {
    if ( i->handleEvent(this: i, a2: event) != 0 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429660
// Name: public: static int mx::run(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl mx::run()
{
  int v0; // edi
  mxWindow *v1; // ecx
  HWND__ *Handle; // eax
  int (__thiscall *handleEvent)(mxWindow *, mxEvent *); // eax
  HACCEL v5; // [esp-8h] [ebp-44h]
  mxEvent event; // [esp+Ch] [ebp-30h] BYREF

  v0 = 0;
  while ( 1 )
  {
    while ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
    {
      v1 = g_idleWindow;
      if ( g_idleWindow == nullptr )
        break;
LABEL_10:
      v0 = 0;
      if ( v1 != nullptr )
      {
        handleEvent = v1->handleEvent;
        event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
        memset(&event.widget, 0, 40);
        event.event = 3;
        handleEvent(this: v1, a2: &event);
      }
    }
    if ( !GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
      return msg.wParam;
    if ( g_hAcceleratorTable == nullptr
      || (v5 = g_hAcceleratorTable,
          Handle = mxWidget::getHandle(this: g_mainWindow),
          TranslateAcceleratorA(hWnd: Handle, hAccTable: v5, lpMsg: &msg) == 0) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    if ( ++v0 > 10 )
    {
      v1 = g_idleWindow;
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429740
// Name: public: static void mx::setIdleWindow(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mx::setIdleWindow(mxWindow *window)
{
  g_idleWindow = window;
}

//------------------------------------------------------------------------------
// Address: 0x00429750
// Name: public: static char const __near * mx::getApplicationPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mx::getApplicationPath()
{
  _BYTE *v0; // eax

  GetModuleFileNameA(hModule: nullptr, lpFilename: path, nSize: 0x100u);
  strrchr(string: (unsigned __int8 *)path, chr: 0x5Cu);
  if ( v0 != nullptr )
    *v0 = 0;
  return path;
}

//------------------------------------------------------------------------------
// Address: 0x00429780
// Name: public: static int mx::getTickCount(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall mx::getTickCount()
{
  return GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x00429790
// Name: public: mxLinkedList::~mxLinkedList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLinkedList::~mxLinkedList(mxLinkedList *this)
{
  mxListNode_s *d_next; // eax
  mxListNode_s *v3; // edi
  mxListNode_s *d_tail; // [esp-4h] [ebp-8h]

  d_next = this->d_head->d_next;
  if ( d_next != this->d_tail )
  {
    do
    {
      v3 = d_next->d_next;
      free(pMem: d_next);
      d_next = v3;
    }
    while ( v3 != this->d_tail );
  }
  this->d_head->d_next = this->d_tail;
  this->d_tail->d_prev = this->d_head;
  d_tail = this->d_tail;
  this->d_nodeCount = 0;
  free(pMem: d_tail);
  free(pMem: this->d_head);
}

//------------------------------------------------------------------------------
// Address: 0x004297F0
// Name: public: static void mx::quit(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl mx::quit()
{
  mxLinkedList *v0; // eax
  mxListNode_s *d_prev; // esi
  void *d_data; // ecx
  mxListNode_s *v3; // esi
  void *v4; // ecx
  mxListNode_s *v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // ecx
  mxLinkedList *v7; // esi
  HMODULE ModuleHandleA; // eax

  isClosing = true;
  if ( g_mainWindow != nullptr && !g_mainWindow->Closing(this: g_mainWindow) )
  {
    isClosing = false;
    return;
  }
  v0 = g_widgetList;
  if ( g_widgetList != nullptr )
  {
    d_prev = g_widgetList->d_tail->d_prev;
    if ( d_prev != g_widgetList->d_head && d_prev != nullptr )
    {
      do
      {
        d_data = d_prev->d_data;
        d_prev = v0->d_head != d_prev->d_prev ? d_prev->d_prev : nullptr;
        if ( d_data != nullptr )
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)d_data + 4))(a1: d_data) == 0 )
          {
            isClosing = false;
            return;
          }
          v0 = g_widgetList;
        }
      }
      while ( d_prev != nullptr );
    }
    v3 = v0->d_tail->d_prev;
    if ( v3 != v0->d_head && v3 != nullptr )
    {
      do
      {
        v4 = v3->d_data;
        v3 = v0->d_head != v3->d_prev ? v3->d_prev : nullptr;
        if ( v4 != nullptr )
        {
          (*(void (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
          v0 = g_widgetList;
        }
      }
      while ( v3 != nullptr );
    }
    v5 = v0->d_tail->d_prev;
    if ( v5 != v0->d_head && v5 != nullptr )
    {
      do
      {
        v6 = (void (__thiscall ***)(_DWORD, int))v5->d_data;
        v5 = v0->d_head != v5->d_prev ? v5->d_prev : nullptr;
        if ( v6 != nullptr )
        {
          (**v6)(a1: v6, a2: 1);
          v0 = g_widgetList;
        }
      }
      while ( v5 != nullptr );
    }
    v7 = v0;
    if ( v0 != nullptr )
    {
      mxLinkedList::~mxLinkedList(this: v0);
      free(pMem: v7);
    }
  }
  if ( g_hwndToolTipControl != nullptr )
    DestroyWindow(hWnd: g_hwndToolTipControl);
  if ( g_hAcceleratorTable != nullptr )
  {
    DestroyAcceleratorTable(hAccel: g_hAcceleratorTable);
    g_hAcceleratorTable = nullptr;
  }
  PostQuitMessage(nExitCode: 0);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  UnregisterClassA(lpClassName: "mx_class", hInstance: ModuleHandleA);
}

//------------------------------------------------------------------------------
// Address: 0x00429930
// Name: WndProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall WndProc(HWND hwnd, UINT uMessage, unsigned int wParam, unsigned int lParam)
{
  int result; // eax
  int v6; // eax
  mxWidget *v7; // eax
  int v8; // ecx
  LRESULT v9; // eax
  HWND v10; // ecx
  LONG v11; // eax
  LONG v12; // eax
  mxWidget *v13; // eax
  int v14; // ecx
  LONG v15; // eax
  mxWidget *v16; // eax
  int v17; // ecx
  LRESULT v18; // eax
  HWND v19; // ecx
  signed int v20; // eax
  mxWidget *v21; // eax
  int v22; // ecx
  int *v23; // eax
  int v24; // edx
  int *v25; // eax
  int v26; // edx
  int v27; // edx
  ConVar *v28; // eax
  ConVar *v29; // edi
  LONG v30; // eax
  LONG v31; // edi
  void (__stdcall *v32)(mxEvent *); // edx
  int v33; // eax
  int *WindowLongA; // edi
  LONG v35; // esi
  void (__thiscall *v36)(LONG, mxEvent *); // edx
  LONG v37; // eax
  int (__thiscall *v38)(LONG, mxEvent *); // edx
  LONG v39; // edi
  int (__thiscall *v40)(LONG, mxEvent *); // edx
  LONG v41; // eax
  bool v42; // zf
  ConVar *v43; // eax
  mxWidget *v44; // edi
  mxWindow *Parent; // eax
  int v46; // ebx
  LONG v47; // edi
  int v48; // ebx
  HWND v49; // [esp-10h] [ebp-ECh]
  HWND v50; // [esp-8h] [ebp-E4h]
  HWND v51; // [esp-8h] [ebp-E4h]
  HWND v52; // [esp-8h] [ebp-E4h]
  HWND v53; // [esp-8h] [ebp-E4h]
  HWND v54; // [esp-8h] [ebp-E4h]
  char className[128]; // [esp+Ch] [ebp-D0h] BYREF
  mxWindow *v56; // [esp+8Ch] [ebp-50h]
  LPARAM lParama[3]; // [esp+90h] [ebp-4Ch] BYREF
  tagRECT rc; // [esp+9Ch] [ebp-40h] BYREF
  mxEvent event; // [esp+ACh] [ebp-30h] BYREF
  mxWindow *hwnda; // [esp+E4h] [ebp+8h]
  mxWindow *window; // [esp+F0h] [ebp+14h]
  mxWindow *windowa; // [esp+F0h] [ebp+14h]
  mxWindow *windowb; // [esp+F0h] [ebp+14h]
  mxWindow *windowe; // [esp+F0h] [ebp+14h]
  mxWindow *windowf; // [esp+F0h] [ebp+14h]
  mxWindow *windowc; // [esp+F0h] [ebp+14h]
  mxWindow *windowd; // [esp+F0h] [ebp+14h]

  if ( uMessage > 0x100 )
  {
    if ( uMessage > 0x111 )
    {
      switch ( uMessage )
      {
        case 0x113u:
          if ( isClosing )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 2;
          goto LABEL_158;
        case 0x114u:
        case 0x115u:
          v43 = (ConVar *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
          v44 = (mxWidget *)v43;
          if ( v43 != nullptr
            && (mxWidget::getType(this: v43) == (const char *)15
             || mxWidget::getType(this: (ConVar *)v44) == (const char *)14)
            && (unsigned __int16)wParam <= 8u )
          {
            mxEvent::mxEvent(this: &event);
            event.event = 0;
            event.widget = v44;
            event.action = mxWidget::getId(this: v44);
            event.modifiers = (unsigned __int16)wParam;
            event.height = HIWORD(wParam);
            Parent = mxWidget::getParent(this: v44);
            if ( event.action > 0 )
              RecursiveHandleEvent(window: Parent, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x200u:
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v48 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.event = bDragging + 8;
          event.y = SHIWORD(lParam);
          event.modifiers = 0;
          if ( (wParam & 1) != 0 )
          {
            v48 = 1;
            event.buttons = 1;
          }
          if ( (wParam & 2) != 0 )
          {
            v48 |= 2u;
            event.buttons = v48;
          }
          if ( (wParam & 0x10) != 0 )
            event.buttons = v48 | 4;
          if ( (wParam & 8) != 0 )
            event.modifiers = 1;
          if ( (wParam & 4) != 0 )
            event.modifiers |= 2u;
          goto LABEL_158;
        case 0x201u:
        case 0x204u:
        case 0x207u:
          bDragging = true;
          SetCapture(hWnd: hwnd);
          WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v46 = 0;
          if ( WindowLongA == nullptr )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.x = (__int16)lParam;
          event.y = SHIWORD(lParam);
          event.event = 7;
          event.modifiers = 0;
          if ( uMessage == 519 )
            event.buttons = 4;
          else
            event.buttons = (uMessage == 516) + 1;
          if ( (wParam & 1) != 0 )
            event.buttons |= 1u;
          if ( (wParam & 2) != 0 )
            event.buttons |= 2u;
          if ( (wParam & 0x10) != 0 )
            event.buttons |= 4u;
          if ( (wParam & 8) != 0 )
          {
            v46 = 1;
            event.modifiers = 1;
          }
          if ( (wParam & 4) != 0 )
            event.modifiers = v46 | 2;
LABEL_158:
          v24 = *WindowLongA;
LABEL_159:
          (*(void (__stdcall **)(mxEvent *))(v24 + 12))(a1: &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x202u:
        case 0x205u:
        case 0x208u:
          v47 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v47 != 0 )
          {
            mxEvent::mxEvent(this: &event);
            event.y = SHIWORD(lParam);
            event.event = 6;
            event.x = (__int16)lParam;
            event.modifiers = 0;
            if ( uMessage == 520 )
              event.buttons = 4;
            else
              event.buttons = (uMessage == 517) + 1;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers = 1;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            (*(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v47 + 12))(a1: v47, a2: &event);
          }
          bDragging = false;
          ReleaseCapture();
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x20Au:
          windowd = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( windowd != nullptr )
          {
            memset(dst: (unsigned __int8 *)&event, value: 0, count: sizeof(event));
            event.y = SHIWORD(lParam);
            event.event = 12;
            event.x = (__int16)lParam;
            if ( (wParam & 1) != 0 )
              event.buttons |= 1u;
            if ( (wParam & 2) != 0 )
              event.buttons |= 2u;
            if ( (wParam & 0x10) != 0 )
              event.buttons |= 4u;
            if ( (wParam & 8) != 0 )
              event.modifiers |= 1u;
            if ( (wParam & 4) != 0 )
              event.modifiers |= 2u;
            event.height = SHIWORD(wParam);
            RecursiveHandleEvent(window: windowd, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case 0x210u:
          v56 = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v56 == nullptr || wParam != 513 && wParam != 519 && wParam != 516 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.y = SHIWORD(lParam);
          event.event = 22;
          event.x = (__int16)lParam;
          event.buttons = 0;
          event.modifiers = 0;
          if ( wParam == 513 )
          {
            event.buttons = 1;
          }
          else if ( wParam == 516 )
          {
            event.buttons = 2;
          }
          else
          {
            event.buttons = 4;
          }
          v56->handleEvent(this: v56, a2: &event);
          RecursiveHandleEvent(window: v56, &event);
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
    }
    if ( uMessage != 273 )
    {
      switch ( uMessage )
      {
        case 0x101u:
        case 0x105u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 10;
          goto LABEL_72;
        case 0x102u:
          v39 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
          if ( v39 == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          mxEvent::mxEvent(this: &event);
          event.event = 21;
LABEL_72:
          v40 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v39 + 12);
          event.key = wParam;
          if ( v40(a1: v39, a2: &event) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
LABEL_73:
          result = 0;
          break;
        case 0x104u:
          goto $LN25_0;
        case 0x106u:
          return 0;
        default:
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      return result;
    }
    v41 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    windowc = (mxWindow *)v41;
    if ( (_WORD)wParam != 0 && v41 != 0 )
    {
      mxEvent::mxEvent(this: &event);
      GetClassNameA(hWnd: (HWND)lParam, lpClassName: className, nMaxCount: 128);
      if ( _V_stricmp(s1: className, s2: "edit") != 0 )
      {
        if ( _V_stricmp(s1: className, s2: "combobox") != 0 && _V_stricmp(s1: className, s2: "listbox") != 0 )
          goto LABEL_84;
        v42 = HIWORD(wParam) == 1;
      }
      else
      {
        v42 = HIWORD(wParam) == 768;
      }
      if ( v42 )
      {
LABEL_84:
        event.event = 0;
        event.widget = (mxWidget *)GetWindowLongA(hWnd: (HWND)lParam, nIndex: -21);
        event.action = (unsigned __int16)wParam;
        RecursiveHandleEvent(window: windowc, &event);
      }
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  if ( uMessage == 256 )
  {
$LN25_0:
    v37 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    if ( v37 != 0 )
    {
      v38 = *(int (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v37 + 12);
      event.key = wParam;
      event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
      memset(&event.widget, 0, 28);
      event.modifiers = 0;
      event.flags = 0;
      event.event = 11;
      if ( v38(a1: v37, a2: &event) != 0 )
        return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  switch ( uMessage )
  {
    case 5u:
      mxEvent::mxEvent(this: &event);
      v23 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v23 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      event.width = (unsigned __int16)lParam;
      event.event = 1;
      event.height = HIWORD(lParam);
      v24 = *v23;
      goto LABEL_159;
    case 6u:
      windowa = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( windowa == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 14;
      event.widget = nullptr;
      event.action = (_WORD)wParam != 0;
      RecursiveHandleEvent(window: windowa, &event);
      return 0;
    case 7u:
    case 8u:
      window = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( window == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 13;
      event.widget = nullptr;
      event.action = uMessage == 7;
      RecursiveHandleEvent(window, &event);
      return 0;
    case 0xFu:
      if ( !isClosing )
      {
        v30 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
        if ( v30 != 0 )
          (*(void (__thiscall **)(LONG))(*(_DWORD *)v30 + 16))(a1: v30);
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0x10u:
      if ( g_mainWindow == nullptr )
        goto LABEL_73;
      if ( hwnd == mxWidget::getHandle(this: g_mainWindow) )
      {
        mx::quit();
        return 0;
      }
      ShowWindow(hWnd: hwnd, nCmdShow: 0);
      v35 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v35 == 0 )
        goto LABEL_73;
      mxEvent::mxEvent(this: &event);
      v36 = *(void (__thiscall **)(LONG, mxEvent *))(*(_DWORD *)v35 + 12);
      event.event = 19;
      v36(a1: v35, a2: &event);
      return 0;
    case 0x14u:
      v28 = (ConVar *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v29 = v28;
      if ( v28 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      if ( mxWidget::getType(this: v28) == (const char *)3 || mxWidget::getType(this: v29) == (const char *)4 )
        return 0;
      if ( isClosing || (unsigned __int8)v29->GetFlags(this: v29) != 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      return 0;
    case 0x47u:
      mxEvent::mxEvent(this: &event);
      v25 = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v25 == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v26 = *(_DWORD *)(lParam + 12);
      event.x = *(_DWORD *)(lParam + 8);
      event.width = *(_DWORD *)(lParam + 16);
      event.y = v26;
      v27 = *(_DWORD *)(lParam + 20);
      event.event = 20;
      event.height = v27;
      v24 = *v25;
      goto LABEL_159;
    case 0x4Eu:
      if ( isClosing )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      v6 = *(_DWORD *)(lParam + 8);
      switch ( v6 )
      {
        case -402:
          if ( *(_DWORD *)(lParam + 4) == 0 )
            return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
          windowb = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
          v50 = *(HWND *)lParam;
          event.event = 0;
          v7 = (mxWidget *)GetWindowLongA(hWnd: v50, nIndex: -21);
          v8 = *(_DWORD *)(lParam + 4);
          event.widget = v7;
          event.action = v8;
LABEL_13:
          v9 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
          v10 = *(HWND *)lParam;
          rc.left = v9;
          SendMessageA(hWnd: v10, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
          event.x = rc.left;
          event.y = rc.bottom;
LABEL_14:
          RecursiveHandleEvent(window: windowb, &event);
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -101:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v11 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v51 = *(HWND *)lParam;
            windowe = (mxWindow *)v11;
            event.event = 0;
            event.widget = (mxWidget *)GetWindowLongA(hWnd: v51, nIndex: -21);
            event.action = *(_DWORD *)(lParam + 4);
            RecursiveHandleEvent(window: windowe, &event);
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        case -5:
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            v12 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v52 = *(HWND *)lParam;
            windowb = (mxWindow *)v12;
            event.event = 0;
            v13 = (mxWidget *)GetWindowLongA(hWnd: v52, nIndex: -21);
            v14 = *(_DWORD *)(lParam + 4);
            event.widget = v13;
            event.action = v14;
            event.flags = 1;
            if ( v13 == nullptr || mxWidget::getType(this: (ConVar *)v13) != (const char *)18 )
              goto LABEL_14;
            goto LABEL_13;
          }
          return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
        default:
          break;
      }
      if ( v6 != -3 )
      {
        if ( v6 == -552 )
        {
          v20 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x130Bu, wParam: 0, lParam: 0);
          if ( v20 >= 0 )
          {
            v49 = *(HWND *)lParam;
            lParama[0] = 8;
            SendMessageA(hWnd: v49, Msg: 0x1305u, wParam: v20, lParam: (LPARAM)lParama);
            if ( rc.bottom != 0 )
              mxWidget::setVisible(this: (mxWidget *)rc.bottom, b: false);
          }
        }
        else if ( v6 == -551 )
        {
          mxTab_resizeChild(hwnd: *(HWND__ **)lParam);
          if ( *(_DWORD *)(lParam + 4) != 0 )
          {
            windowf = (mxWindow *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
            v54 = *(HWND *)lParam;
            event.event = 0;
            v21 = (mxWidget *)GetWindowLongA(hWnd: v54, nIndex: -21);
            v22 = *(_DWORD *)(lParam + 4);
            event.widget = v21;
            event.action = v22;
            RecursiveHandleEvent(window: windowf, &event);
          }
        }
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      }
      if ( *(_DWORD *)(lParam + 4) == 0 )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      v15 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      v53 = *(HWND *)lParam;
      hwnda = (mxWindow *)v15;
      event.event = 0;
      v16 = (mxWidget *)GetWindowLongA(hWnd: v53, nIndex: -21);
      v17 = *(_DWORD *)(lParam + 4);
      event.widget = v16;
      event.action = v17;
      event.flags = 2;
      if ( v16 != nullptr && mxWidget::getType(this: (ConVar *)v16) == (const char *)18 )
      {
        v18 = SendMessageA(hWnd: *(HWND *)lParam, Msg: 0x110Au, wParam: 9u, lParam: 0);
        v19 = *(HWND *)lParam;
        rc.left = v18;
        SendMessageA(hWnd: v19, Msg: 0x1104u, wParam: 1u, lParam: (LPARAM)&rc);
        event.x = rc.left;
        event.y = rc.bottom;
      }
      RecursiveHandleEvent(window: hwnda, &event);
      result = 1;
      break;
    case 0xA0u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.event = 17;
      event.x = (__int16)lParam;
      event.y = SHIWORD(lParam);
      event.buttons = 0;
      event.modifiers = 0;
      goto LABEL_158;
    case 0xA1u:
    case 0xA4u:
    case 0xA7u:
      v31 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( v31 != 0 )
      {
        mxEvent::mxEvent(this: &event);
        event.event = 16;
        event.x = (__int16)lParam;
        event.y = SHIWORD(lParam);
        event.modifiers = 0;
        if ( uMessage == 167 )
        {
          v32 = *(void (__stdcall **)(mxEvent *))(*(_DWORD *)v31 + 12);
          event.buttons = 4;
          v32(a1: &event);
        }
        else
        {
          v33 = *(_DWORD *)v31;
          event.buttons = (uMessage == 164) + 1;
          (*(void (__stdcall **)(mxEvent *))(v33 + 12))(a1: &event);
        }
      }
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
    case 0xA2u:
    case 0xA5u:
    case 0xA8u:
      WindowLongA = (int *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA == nullptr )
        return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
      mxEvent::mxEvent(this: &event);
      event.y = SHIWORD(lParam);
      event.event = 15;
      event.x = (__int16)lParam;
      event.modifiers = 0;
      if ( uMessage == 168 )
        event.buttons = 4;
      else
        event.buttons = (uMessage == 165) + 1;
      goto LABEL_158;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: uMessage, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A6E0
// Name: public: static int mx::init(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mx::init()
{
  mxLinkedList *v1; // eax
  tagWNDCLASSA wc; // [esp+8h] [ebp-28h] BYREF

  wc.style = 35;
  wc.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  wc.hIcon = LoadIconA(hInstance: wc.hInstance, lpIconName: "MX_ICON");
  wc.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wc.hbrBackground = (HBRUSH__ *)5;
  wc.lpszMenuName = nullptr;
  wc.lpszClassName = "mx_class";
  if ( wc.hIcon == nullptr )
    wc.hIcon = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F05);
  if ( RegisterClassA(lpWndClass: &wc) == 0 )
    return 0;
  InitCommonControls();
  v1 = (mxLinkedList *)operator new(nSize: 0xCu);
  if ( v1 != nullptr )
    g_widgetList = mxLinkedList::mxLinkedList(this: v1);
  else
    g_widgetList = nullptr;
  isClosing = false;
  return 1;
}

} // namespace scenemanager
