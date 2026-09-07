// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/mem_profile.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00413910
// Name: void MemProfile_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_SaveConfig()
{
  char buff[256]; // [esp+4h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+104h] [ebp-2Ch] BYREF

  if ( g_memProfile_hWnd != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_memProfile_hWnd, lpwndpl: &wp);
    g_memProfile_WindowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "MemProfileWindowRect", value: buff);
  }
  Sys_SetRegistryInteger(keyName: "MemProfileScale", value: g_memProfile_scale);
  Sys_SetRegistryInteger(keyName: "MemProfileTickMarks", value: g_memProfile_tickMarks);
  Sys_SetRegistryInteger(keyName: "MemProfileColors", value: g_memProfile_colors);
}

//------------------------------------------------------------------------------
// Address: 0x004139D0
// Name: void MemProfile_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryString(keyName: "MemProfileWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_memProfile_WindowRect,
         &g_memProfile_WindowRect.top,
         &g_memProfile_WindowRect.right,
         &g_memProfile_WindowRect.bottom) != 4 )
  {
    *(_QWORD *)&g_memProfile_WindowRect.left = 0;
    *(_QWORD *)&g_memProfile_WindowRect.right = 0;
  }
  Sys_GetRegistryInteger(keyName: "MemProfileScale", defValue: 0, value: &g_memProfile_scale);
  if ( g_memProfile_scale < -8 || g_memProfile_scale > 8 )
    g_memProfile_scale = 0;
  Sys_GetRegistryInteger(keyName: "MemProfileTickMarks", defValue: 1, value: &g_memProfile_tickMarks);
  Sys_GetRegistryInteger(keyName: "MemProfileColors", defValue: 1, value: &g_memProfile_colors);
}

//------------------------------------------------------------------------------
// Address: 0x00413A90
// Name: void MemProfile_SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_SetTitle()
{
  HWND v0; // edx
  char *v1; // eax
  char v2; // cl
  char v3; // [esp-1h] [ebp-81h] BYREF
  char titleBuff[128]; // [esp+0h] [ebp-80h] BYREF

  v0 = g_memProfile_hWnd;
  if ( g_memProfile_hWnd != nullptr )
  {
    strcpy(titleBuff, "Free Memory Available");
    if ( g_memProfile_Timer != 0 )
    {
      v1 = &v3;
      do
        v2 = *++v1;
      while ( v2 != 0 );
      strcpy(v1, " [ON]");
    }
    SetWindowTextA(hWnd: v0, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413B10
// Name: void MemProfile_EnableProfiling(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_EnableProfiling(bool bEnable)
{
  if ( g_memProfile_hWnd != nullptr )
  {
    if ( bEnable )
    {
      if ( g_memProfile_Timer == 0 )
        g_memProfile_Timer = SetTimer(hWnd: g_memProfile_hWnd, nIDEvent: 0x1001u, uElapse: 0x64u, lpTimerFunc: nullptr);
    }
    else if ( g_memProfile_Timer != 0 )
    {
      KillTimer(hWnd: g_memProfile_hWnd, uIDEvent: 0x1001u);
      g_memProfile_Timer = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413B70
// Name: void MemProfile_UpdateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_UpdateWindow()
{
  if ( g_memProfile_hWnd != nullptr && !IsIconic(hWnd: g_memProfile_hWnd) )
    InvalidateRect(hWnd: g_memProfile_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x00413BA0
// Name: int rc_FreeMemory(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_FreeMemory(char *commandPtr)
{
  char *Token; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-18h]
  int freeMemory; // [esp+4h] [ebp-4h] BYREF

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &freeMemory);
  v4 = freeMemory;
  v2 = g_memProfile_numSamples + 1;
  g_memProfile_samples[g_memProfile_numSamples % 512] = freeMemory;
  g_memProfile_numSamples = v2;
  DebugCommand(pStrFormat: "FreeMemory( 0x%8.8x )\n", v4);
  if ( g_memProfile_hWnd != nullptr && !IsIconic(hWnd: g_memProfile_hWnd) )
    InvalidateRect(hWnd: g_memProfile_hWnd, lpRect: nullptr, bErase: true);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413C30
// Name: void MemProfile_ZoomIn(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_ZoomIn(int *scale, int numSteps)
{
  if ( ++*scale <= numSteps )
  {
    if ( g_memProfile_hWnd != nullptr && !IsIconic(hWnd: g_memProfile_hWnd) )
      InvalidateRect(hWnd: g_memProfile_hWnd, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413C70
// Name: void MemProfile_ZoomOut(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_ZoomOut(int *scale, int numSteps)
{
  if ( --*scale >= -numSteps )
  {
    if ( g_memProfile_hWnd != nullptr && !IsIconic(hWnd: g_memProfile_hWnd) )
      InvalidateRect(hWnd: g_memProfile_hWnd, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = -numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413CB0
// Name: void MemProfile_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  int v3; // ebx
  int v4; // edi
  float v5; // xmm0_4
  int v6; // eax
  bool v7; // sf
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  float v11; // xmm0_4
  int v12; // eax
  COLORREF v13; // eax
  HBRUSH SolidBrush; // edi
  char labelBuff[128]; // [esp+10h] [ebp-C4h] BYREF
  tagRECT rect; // [esp+90h] [ebp-44h] BYREF
  int gapY; // [esp+A0h] [ebp-34h]
  unsigned int textColorOld; // [esp+A4h] [ebp-30h]
  HPEN__ *hPenOld; // [esp+A8h] [ebp-2Ch]
  HFONT__ *hFontOld; // [esp+ACh] [ebp-28h]
  unsigned int backColorOld; // [esp+B0h] [ebp-24h]
  HPEN__ *hBlackPen; // [esp+B4h] [ebp-20h]
  HPEN__ *hGreyPen; // [esp+B8h] [ebp-1Ch]
  int memoryHeight; // [esp+BCh] [ebp-18h]
  HPEN__ *hNullPen; // [esp+C0h] [ebp-14h]
  int windowHeight; // [esp+C4h] [ebp-10h]
  int h; // [esp+C8h] [ebp-Ch]
  int numTicks; // [esp+CCh] [ebp-8h]
  int x; // [esp+D0h] [ebp-4h]
  int y; // [esp+E0h] [ebp+Ch]
  int ya; // [esp+E0h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: g_textColor);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  *(float *)&hNullPen = COERCE_FLOAT(CreatePen(iStyle: 5, cWidth: 0, color: 0));
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  backColorOld = SetBkColor(hdc, color: g_backgroundColor);
  textColorOld = SetTextColor(hdc, color: g_textColor);
  v3 = clientRect->bottom - clientRect->top;
  v4 = clientRect->right - clientRect->left;
  v5 = (float)((float)((float)((float)(g_memProfile_scale + 8) * 0.0625) * 2.8) + 0.2) * 100.0;
  v6 = v3 / (int)v5;
  memoryHeight = (int)v5;
  windowHeight = v3;
  v7 = v6 + 2 < 0;
  v8 = v6 + 2;
  numTicks = v8;
  if ( v7 )
  {
    numTicks = 1;
  }
  else
  {
    if ( v8 <= 33 )
      goto LABEL_6;
    numTicks = 33;
  }
  v8 = numTicks;
LABEL_6:
  y = v3;
  x = 0;
  if ( v8 > 0 )
  {
    do
    {
      SelectObject(hdc, h: hBlackPen);
      MoveToEx(hdc, x: 0, y, lppt: nullptr);
      LineTo(hdc, x: v4, y);
      if ( g_memProfile_tickMarks != 0 )
      {
        gapY = memoryHeight / 4;
        if ( memoryHeight / 4 >= 10 )
        {
          v9 = y;
          SelectObject(hdc, h: hGreyPen);
          for ( h = 3; h != 0; --h )
          {
            v9 += gapY;
            MoveToEx(hdc, x: 0, y: v9, lppt: nullptr);
            LineTo(hdc, x: v4, y: v9);
          }
          v3 = windowHeight;
        }
      }
      v10 = x;
      if ( x != 0 )
      {
        rect.left = v4 - 50;
        rect.right = v4;
        rect.top = y - 20;
        rect.bottom = y;
        sprintf(string: labelBuff, format: "%d MB", 16 * x);
        DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x2Au);
        v10 = x;
      }
      y -= memoryHeight;
      x = v10 + 1;
    }
    while ( v10 + 1 < numTicks );
  }
  if ( g_memProfile_numSamples != 0 )
  {
    SelectObject(hdc, h: hNullPen);
    ya = g_memProfile_numSamples - 1;
    x = v4 - 51;
    if ( v4 - 51 >= 0 )
    {
      *(float *)&hNullPen = (float)memoryHeight;
      do
      {
        v11 = (float)g_memProfile_samples[ya % 512] * 0.00000095367432;
        v12 = (int)(float)((float)(v11 * 0.0625) * *(float *)&hNullPen);
        h = v12;
        if ( v12 != 0 )
        {
          if ( v12 > v3 )
            h = v3;
          if ( v11 < 10.0 )
          {
            v13 = 6619135;
            if ( v11 < 5.0 )
              v13 = 255;
          }
          else
          {
            v13 = 6618980;
          }
          if ( g_memProfile_colors == 0 )
            v13 = 5263440;
          SolidBrush = CreateSolidBrush(color: v13);
          windowHeight = (int)SelectObject(hdc, h: SolidBrush);
          Rectangle(hdc, left: x - 4, top: v3 - h, right: x, bottom: v3 + 1);
          SelectObject(hdc, h: (HGDIOBJ)windowHeight);
          DeleteObject(ho: SolidBrush);
        }
        if ( --ya < 0 )
          break;
        x -= 4;
      }
      while ( x >= 0 );
    }
  }
  SetBkColor(hdc, color: backColorOld);
  SetTextColor(hdc, color: textColorOld);
  SelectObject(hdc, h: hFontOld);
  SelectObject(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x00413FF0
// Name: void MemProfile_TimerProc(struct HWND__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_TimerProc()
{
  if ( !busy_0 )
  {
    busy_0 = true;
    if ( g_connectedToApp )
      DmAPI_SendCommand(strCommand: "XCMD!__memory__ quiet", wait: false);
    busy_0 = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414020
// Name: long MemProfile_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall MemProfile_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, LONG *lParam)
{
  LRESULT result; // eax
  HDC v5; // eax
  tagPAINTSTRUCT ps; // [esp+4h] [ebp-50h] BYREF
  tagRECT rect; // [esp+44h] [ebp-10h] BYREF

  if ( message > 0x14 )
  {
    switch ( message )
    {
      case 0x100u:
        if ( wParam == (HMENU)45 )
        {
$LN10_1:
          MemProfile_ZoomIn(scale: &g_memProfile_scale, numSteps: 8);
          result = 0;
        }
        else
        {
          if ( wParam != (HMENU)46 )
            goto LABEL_24;
$LN2_1:
          MemProfile_ZoomOut(scale: &g_memProfile_scale, numSteps: 8);
          result = 0;
        }
        break;
      case 0x111u:
        switch ( (unsigned __int16)wParam )
        {
          case 0xC591u:
            g_memProfile_tickMarks ^= 1u;
$LN16_2:
            MemProfile_UpdateWindow();
            result = 0;
            break;
          case 0xC592u:
            goto $LN10_1;
          case 0xC593u:
            goto $LN2_1;
          case 0xC594u:
            MemProfile_EnableProfiling(bEnable: g_memProfile_Timer == 0);
            MemProfile_SetTitle();
            result = 0;
            break;
          case 0xC596u:
            g_memProfile_colors ^= 1u;
            MemProfile_UpdateWindow();
            result = 0;
            break;
          default:
            goto LABEL_24;
        }
        break;
      case 0x113u:
        if ( (_WORD)wParam != 4097 )
          goto LABEL_24;
        MemProfile_TimerProc();
        result = 0;
        break;
      case 0x116u:
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC591u, uCheck: g_memProfile_tickMarks != 0 ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC596u, uCheck: g_memProfile_colors != 0 ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC594u, uCheck: g_memProfile_Timer != 0 ? 8 : 0);
        result = 0;
        break;
      default:
LABEL_24:
        result = DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
        break;
    }
  }
  else if ( message == 20 )
  {
    return 1;
  }
  else
  {
    switch ( message )
    {
      case 1u:
        SetWindowLongA(hWnd: hwnd, nIndex: -21, dwNewLong: *lParam);
        g_memProfile_numSamples = 0;
        memset(dst: (unsigned __int8 *)g_memProfile_samples, value: 0, count: sizeof(g_memProfile_samples));
        result = 0;
        break;
      case 2u:
        MemProfile_SaveConfig();
        if ( g_memProfile_hWnd != nullptr && g_memProfile_Timer != 0 )
        {
          KillTimer(hWnd: g_memProfile_hWnd, uIDEvent: 0x1001u);
          g_memProfile_Timer = 0;
        }
        g_memProfile_hWnd = nullptr;
        result = 0;
        break;
      case 5u:
        goto $LN16_2;
      case 0xFu:
        GetClientRect(hWnd: hwnd, lpRect: &rect);
        v5 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
        DrawHelper(hdc: v5, clientRect: (HBRUSH__ *)&rect, drawFunc: MemProfile_Draw);
        EndPaint(hWnd: hwnd, lpPaint: &ps);
        result = 0;
        break;
      default:
        goto LABEL_24;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004142D0
// Name: void MemProfile_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemProfile_Open()
{
  HWND Window; // eax

  if ( g_memProfile_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_memProfile_hWnd) )
      ShowWindow(hWnd: g_memProfile_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_memProfile_hWnd);
  }
  else
  {
    Window = CreateWindowExA(
               dwExStyle: 0x200u,
               lpClassName: "MEMPROFILECLASS",
               lpWindowName: &defValue,
               dwStyle: 0x80CF0000,
               X: 0,
               Y: 0,
               nWidth: 600,
               nHeight: 500,
               hWndParent: g_hDlgMain,
               hMenu: nullptr,
               hInstance: g_hInstance,
               lpParam: (LPVOID)1);
    g_memProfile_hWnd = Window;
    if ( Window != nullptr && g_memProfile_Timer == 0 )
      g_memProfile_Timer = SetTimer(hWnd: Window, nIDEvent: 0x1001u, uElapse: 0x64u, lpTimerFunc: nullptr);
    MemProfile_SetTitle();
    if ( g_memProfile_WindowRect.right != 0 && g_memProfile_WindowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_memProfile_hWnd,
        X: g_memProfile_WindowRect.left,
        Y: g_memProfile_WindowRect.top,
        nWidth: g_memProfile_WindowRect.right - g_memProfile_WindowRect.left,
        nHeight: g_memProfile_WindowRect.bottom - g_memProfile_WindowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_memProfile_hWnd, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004143B0
// Name: bool MemProfile_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall MemProfile_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = MemProfile_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)133;
  wndclass.hCursor = (HICON__ *)"MEMPROFILECLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  MemProfile_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414450
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}
