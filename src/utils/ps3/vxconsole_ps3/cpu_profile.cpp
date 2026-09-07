// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/cpu_profile.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00404D70
// Name: void CpuProfile_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_SaveConfig()
{
  char buff[256]; // [esp+8h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+108h] [ebp-2Ch] BYREF

  if ( g_cpuProfile_hWndSamples != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_cpuProfile_hWndSamples, lpwndpl: &wp);
    g_cpuProfile_samplesWindowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "profileSamplesWindowRect", value: buff);
  }
  Sys_SetRegistryInteger(keyName: "profileSamplesScale", value: g_cpuProfile_samples_scale);
  if ( g_cpuProfile_hWndHistory != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_cpuProfile_hWndHistory, lpwndpl: &wp);
    g_cpuProfile_historyWindowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "profileHistoryWindowRect", value: buff);
  }
  Sys_SetRegistryInteger(keyName: "profileHistoryScale", value: g_cpuProfile_history_scale);
  Sys_SetRegistryInteger(keyName: "cpuProfileFpsLabels", value: g_cpuProfile_fpsLabels);
}

//------------------------------------------------------------------------------
// Address: 0x00404EB0
// Name: void CpuProfile_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryString(keyName: "profileSamplesWindowRect", value: buff, defValue: &str, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_cpuProfile_samplesWindowRect,
         &g_cpuProfile_samplesWindowRect.top,
         &g_cpuProfile_samplesWindowRect.right,
         &g_cpuProfile_samplesWindowRect.bottom) != 4 )
  {
    *(_QWORD *)&g_cpuProfile_samplesWindowRect.left = 0;
    *(_QWORD *)&g_cpuProfile_samplesWindowRect.right = 0;
  }
  Sys_GetRegistryInteger(keyName: "profileSamplesScale", defValue: 0, value: &g_cpuProfile_samples_scale);
  if ( g_cpuProfile_samples_scale < -10 || g_cpuProfile_samples_scale > 10 )
    g_cpuProfile_samples_scale = 0;
  Sys_GetRegistryString(keyName: "profileHistoryWindowRect", value: buff, defValue: &str, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_cpuProfile_historyWindowRect,
         &g_cpuProfile_historyWindowRect.top,
         &g_cpuProfile_historyWindowRect.right,
         &g_cpuProfile_historyWindowRect.bottom) != 4 )
  {
    *(_QWORD *)&g_cpuProfile_historyWindowRect.left = 0;
    *(_QWORD *)&g_cpuProfile_historyWindowRect.right = 0;
  }
  Sys_GetRegistryInteger(keyName: "profileHistoryScale", defValue: 0, value: &g_cpuProfile_history_scale);
  if ( g_cpuProfile_history_scale < -5 || g_cpuProfile_history_scale > 5 )
    g_cpuProfile_history_scale = 0;
  Sys_GetRegistryInteger(keyName: "cpuProfileFpsLabels", defValue: 0, value: &g_cpuProfile_fpsLabels);
}

//------------------------------------------------------------------------------
// Address: 0x00404FF0
// Name: void CpuProfile_SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_SetTitle()
{
  char *v0; // eax
  char v1; // cl
  char *v2; // eax
  char v3; // cl
  char v4; // [esp+3h] [ebp-81h] BYREF
  char titleBuff[128]; // [esp+4h] [ebp-80h] BYREF

  if ( g_cpuProfile_hWndSamples != nullptr )
  {
    strcpy(titleBuff, "CPU Usage Snapshot");
    if ( VProf_GetState() == VPROF_CPU )
    {
      v0 = &v4;
      do
        v1 = *++v0;
      while ( v1 != 0 );
      strcpy(v0, " [ON]");
    }
    SetWindowTextA(hWnd: g_cpuProfile_hWndSamples, lpString: titleBuff);
  }
  if ( g_cpuProfile_hWndHistory != nullptr )
  {
    strcpy(titleBuff, "CPU Usage History");
    if ( VProf_GetState() == VPROF_CPU )
    {
      v2 = &v4;
      do
        v3 = *++v2;
      while ( v3 != 0 );
      strcpy(v2, " [ON]");
    }
    SetWindowTextA(hWnd: g_cpuProfile_hWndHistory, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004050E0
// Name: void CpuProfile_UpdateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_UpdateWindow()
{
  if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
    InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
    InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x00405130
// Name: void CpuProfile_ZoomIn(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_ZoomIn(int *scale, int numSteps)
{
  if ( ++*scale <= numSteps )
  {
    if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
      InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
    if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
      InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405190
// Name: void CpuProfile_ZoomOut(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_ZoomOut(int *scale, int numSteps)
{
  if ( --*scale >= -numSteps )
  {
    if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
      InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
    if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
      InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = -numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051F0
// Name: void ProfileSamples_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProfileSamples_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  void (__stdcall *v3)(HDC, HGDIOBJ); // ebx
  int v4; // ecx
  int v5; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ebx
  const char *v9; // eax
  int v10; // edi
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  int v13; // ebx
  COLORREF v14; // eax
  HGDIOBJ v15; // eax
  double v16; // st7
  int v17; // ecx
  double v18; // st6
  int v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // edi
  double v23; // st7
  char labelBuff[128]; // [esp+14h] [ebp-E0h] BYREF
  tagPOINT points[4]; // [esp+94h] [ebp-60h] BYREF
  HFONT__ *hFontOld; // [esp+B4h] [ebp-40h]
  HPEN__ *hPenOld; // [esp+B8h] [ebp-3Ch]
  int windowWidth; // [esp+BCh] [ebp-38h]
  HPEN__ *hGreyPen; // [esp+C4h] [ebp-30h]
  HBRUSH__ *hColoredBrush; // [esp+C8h] [ebp-2Ch]
  int timingWidth; // [esp+CCh] [ebp-28h]
  tagRECT rect; // [esp+D0h] [ebp-24h] BYREF
  HPEN__ *hBlackPen; // [esp+E0h] [ebp-14h]
  int windowHeight; // [esp+E4h] [ebp-10h]
  int y; // [esp+E8h] [ebp-Ch]
  int x; // [esp+ECh] [ebp-8h]
  int numTicks; // [esp+F0h] [ebp-4h]
  int i; // [esp+100h] [ebp+Ch]
  int ia; // [esp+100h] [ebp+Ch]
  int ib; // [esp+100h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: 0);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  SetBkColor(hdc, color: g_backgroundColor);
  v4 = clientRect->right - clientRect->left;
  windowHeight = clientRect->bottom - clientRect->top;
  timingWidth = (int)(float)((float)((float)((float)((float)(g_cpuProfile_samples_scale + 10) * 0.050000001) * 2.7)
                                   + 0.30000001)
                           * 200.0);
  windowWidth = v4;
  numTicks = (v4 - 150) / timingWidth + 1;
  if ( numTicks < 0 )
    numTicks = 1;
  v5 = 150;
  rect.left = 0;
  rect.right = 150;
  rect.top = 0;
  rect.bottom = 15;
  DrawTextA(hdc, lpchText: "Name", cchText: -1, lprc: &rect, format: 0);
  v6 = 0;
  x = 150;
  i = 0;
  if ( numTicks > 0 )
  {
    y = windowHeight + 15;
    while ( 1 )
    {
      rect.left = v5 - 40;
      rect.right = v5 + 40;
      rect.top = 0;
      rect.bottom = 15;
      if ( g_cpuProfile_fpsLabels != 0 )
      {
        if ( v6 != 0 )
          v7 = 60.0 / (float)v6;
        else
          v7 = 0.0;
        sprintf(string: labelBuff, format: "%.2ffps", v7);
      }
      else
      {
        sprintf(string: labelBuff, format: "%.2fms", (float)((float)v6 * 16.666666));
      }
      DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 1u);
      v3(hdc, h: hBlackPen);
      MoveToEx(hdc, x: v5, y: 15, lppt: nullptr);
      LineTo(hdc, x: v5, y);
      if ( g_cpuProfile_samples_tickMarks && g_cpuProfile_samples_scale > -10 )
      {
        v3(hdc, h: hGreyPen);
        v8 = timingWidth / 4;
        for ( windowHeight = 3; windowHeight != 0; --windowHeight )
        {
          v5 += v8;
          MoveToEx(hdc, x: v5, y: 15, lppt: nullptr);
          LineTo(hdc, x: v5, y);
        }
        v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
        v5 = x;
      }
      v5 += timingWidth;
      x = v5;
      if ( ++i >= numTicks )
        break;
      v6 = i;
    }
  }
  v3(hdc, h: hBlackPen);
  MoveToEx(hdc, x: 0, y: 15, lppt: nullptr);
  LineTo(hdc, x: windowWidth, y: 15);
  ia = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v9 = pDest;
    v10 = 30;
    *(float *)&x = COERCE_FLOAT(pDest);
    do
    {
      if ( v9 != nullptr )
      {
        rect.left = 0;
        rect.right = 145;
        rect.top = v10 - 15;
        rect.bottom = v10;
        DrawTextA(hdc, lpchText: v9, cchText: -1, lprc: &rect, format: 0x18026u);
        MoveToEx(hdc, x: 0, y: v10, lppt: nullptr);
        LineTo(hdc, x: 150, y: v10);
        v9 = (const char *)x;
        v10 += 15;
      }
      v9 += 2120;
      ++ia;
      x = (int)v9;
    }
    while ( ia < g_cpuProfile_numCounters );
  }
  v3(hdc, h: hBlackPen);
  if ( g_cpuProfile_numSamples - 1 >= 0 )
    v11 = (g_cpuProfile_numSamples - 1) & 0x800001FF;
  else
    v11 = 0;
  ib = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v12 = &unk_449B18;
    numTicks = (int)&unk_449B18;
    v13 = 19;
    y = (int)g_cpuProfile_counters + 4 * v11;
    do
    {
      if ( v12 != (_DWORD *)-4 )
      {
        if ( g_cpuProfile_samples_colors )
          v14 = v12[17];
        else
          v14 = g_backgroundColor;
        *(float *)&hColoredBrush = COERCE_FLOAT(CreateSolidBrush(color: v14));
        v15 = SelectObject(hdc, h: hColoredBrush);
        v16 = (double)timingWidth;
        windowHeight = (int)v15;
        v17 = *(_DWORD *)y;
        *(float *)&x = v16;
        v18 = (double)*(int *)y;
        if ( v17 < 0 )
          v18 = v18 + 4294967300.0;
        v19 = (int)(v16 * (v18 * 0.000060000002));
        v20 = windowWidth;
        if ( v19 > windowWidth )
          v19 = windowWidth;
        Rectangle(hdc, left: 150, top: v13 - 1, right: v19 + 150, bottom: v13 + 9);
        v21 = (int)((double)*(unsigned int *)numTicks * 0.000060000002 * *(float *)&x);
        if ( v21 > v20 )
          v21 = v20;
        v22 = v21 + 150;
        points[1].x = v21 + 154;
        points[1].y = v13 + 4;
        points[3].y = v13 + 4;
        points[0].x = v21 + 150;
        points[0].y = v13;
        points[2].x = v21 + 150;
        points[2].y = v13 + 8;
        points[3].x = v21 + 146;
        Polygon(hdc, apt: points, cpt: 4);
        SelectObject(hdc, h: (HGDIOBJ)windowHeight);
        DeleteObject(ho: hColoredBrush);
        v23 = (double)*(unsigned int *)numTicks * 0.001;
        *(float *)&hColoredBrush = v23;
        if ( v23 >= 0.0099999998 )
        {
          sprintf(string: labelBuff, format: "%.2f", *(float *)&hColoredBrush);
          rect.left = v22 + 8;
          rect.top = v13 - 4;
          rect.right = v22 + 108;
          rect.bottom = v13 + 11;
          DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x24u);
        }
        v12 = (_DWORD *)numTicks;
        v13 += 15;
      }
      y += 2120;
      v12 += 530;
      ++ib;
      numTicks = (int)v12;
    }
    while ( ib < g_cpuProfile_numCounters );
    v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
  v3(hdc, h: hFontOld);
  v3(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x004056F0
// Name: void ProfileHistory_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProfileHistory_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // ebx
  COLORREF *v9; // edi
  int v10; // eax
  COLORREF v11; // eax
  HBRUSH SolidBrush; // ebx
  HBRUSH__ *v13; // eax
  int v14; // edi
  char labelBuff[128]; // [esp+14h] [ebp-C4h] BYREF
  tagRECT rect; // [esp+94h] [ebp-44h] BYREF
  HPEN__ *hPenOld; // [esp+A4h] [ebp-34h]
  HFONT__ *hFontOld; // [esp+A8h] [ebp-30h]
  int h; // [esp+ACh] [ebp-2Ch]
  HPEN__ *hBlackPen; // [esp+B0h] [ebp-28h]
  int windowHeight; // [esp+B4h] [ebp-24h]
  HBRUSH__ *hBrushOld; // [esp+B8h] [ebp-20h]
  HPEN__ *hGreyPen; // [esp+BCh] [ebp-1Ch]
  int timingHeight; // [esp+C0h] [ebp-18h]
  int j; // [esp+C4h] [ebp-14h]
  int v26; // [esp+C8h] [ebp-10h]
  int x; // [esp+CCh] [ebp-Ch]
  int i; // [esp+D0h] [ebp-8h]
  int numTicks; // [esp+D4h] [ebp-4h]
  int y; // [esp+E4h] [ebp+Ch]
  int ya; // [esp+E4h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: 0);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  j = (int)CreatePen(iStyle: 5, cWidth: 0, color: 0);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  v3 = clientRect->bottom - clientRect->top;
  v4 = clientRect->right - clientRect->left;
  timingHeight = (int)(float)((float)((float)((float)((float)(g_cpuProfile_history_scale + 5) * 0.1) * 2.7) + 0.30000001)
                            * 100.0);
  windowHeight = v3;
  numTicks = v3 / timingHeight + 2;
  if ( numTicks < 0 )
    numTicks = 1;
  SetBkColor(hdc, color: g_backgroundColor);
  y = v3;
  i = 0;
  if ( numTicks > 0 )
  {
    do
    {
      SelectObject(hdc, h: hBlackPen);
      MoveToEx(hdc, x: 0, y: v3, lppt: nullptr);
      LineTo(hdc, x: v4, y: v3);
      if ( g_cpuProfile_history_tickMarks && g_cpuProfile_history_scale > -5 )
      {
        SelectObject(hdc, h: hGreyPen);
        v5 = timingHeight / 4;
        v26 = timingHeight / 4;
        x = 3;
        while ( 1 )
        {
          v3 += v5;
          MoveToEx(hdc, x: 0, y: v3, lppt: nullptr);
          LineTo(hdc, x: v4, y: v3);
          if ( --x == 0 )
            break;
          v5 = v26;
        }
        v3 = y;
      }
      v6 = i;
      if ( i != 0 )
      {
        rect.left = v4 - 50;
        rect.right = v4;
        rect.top = v3 - 20;
        rect.bottom = v3;
        v7 = (float)i;
        if ( g_cpuProfile_fpsLabels != 0 )
          sprintf(string: labelBuff, format: "%.2ffps", (float)(60.0 / v7));
        else
          sprintf(string: labelBuff, format: "%.2fms", (float)(v7 * 16.666666));
        DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x2Au);
        v6 = i;
      }
      v3 -= timingHeight;
      y = v3;
      i = v6 + 1;
    }
    while ( v6 + 1 < numTicks );
  }
  if ( g_cpuProfile_numSamples != 0 )
  {
    SelectObject(hdc, h: (HGDIOBJ)j);
    i = g_cpuProfile_numSamples - 1;
    x = v4 - 51;
    if ( v4 - 51 >= 0 )
    {
      v8 = g_cpuProfile_numCounters;
      do
      {
        ya = windowHeight;
        j = 0;
        if ( v8 - 1 > 0 )
        {
          v9 = (COLORREF *)&dword_449B5C;
          numTicks = 0;
          v26 = (int)&dword_449B5C;
          do
          {
            if ( v9 != (COLORREF *)64 )
            {
              v10 = (int)((double)g_cpuProfile_counters[numTicks + i % 512] * 0.000060000002 * (double)timingHeight);
              h = v10;
              if ( v10 != 0 )
              {
                if ( v10 > windowHeight )
                  h = windowHeight;
                if ( g_cpuProfile_history_colors )
                  v11 = *v9;
                else
                  v11 = 5263440;
                SolidBrush = CreateSolidBrush(color: v11);
                v13 = (HBRUSH__ *)SelectObject(hdc, h: SolidBrush);
                v14 = ya - h;
                hBrushOld = v13;
                Rectangle(hdc, left: x - 4, top: ya - h, right: x, bottom: ya + 1);
                ya = v14;
                SelectObject(hdc, h: hBrushOld);
                DeleteObject(ho: SolidBrush);
                v8 = g_cpuProfile_numCounters;
                v9 = (COLORREF *)v26;
              }
            }
            numTicks += 530;
            v9 += 530;
            ++j;
            v26 = (int)v9;
          }
          while ( j < v8 - 1 );
        }
        if ( --i < 0 )
          break;
        x -= 4;
      }
      while ( x >= 0 );
    }
  }
  SelectObject(hdc, h: hFontOld);
  SelectObject(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x00405A70
// Name: long CpuProfile_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall CpuProfile_WndProc(HWND hwnd, UINT message, HMENU wParam, LONG *lParam)
{
  LONG WindowLongA; // eax
  bool v6; // bl
  HDC v8; // eax
  vprofState_e State; // eax
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-50h] BYREF
  tagRECT rect; // [esp+4Ch] [ebp-10h] BYREF
  bool bIsHistory_3; // [esp+67h] [ebp+Bh]

  WindowLongA = GetWindowLongA(hWnd: hwnd, nIndex: -21);
  v6 = WindowLongA == 1;
  bIsHistory_3 = WindowLongA == 2;
  if ( message > 0xF )
  {
    if ( message != 256 )
    {
      if ( message == 273 )
      {
        if ( (unsigned __int16)wParam <= 0xC549u )
        {
          if ( (unsigned __int16)wParam != 50505 )
          {
            switch ( (unsigned __int16)wParam )
            {
              case 0x9CE0u:
                if ( WindowLongA == 1 )
                {
                  g_cpuProfile_samples_tickMarks ^= 1u;
                  CpuProfile_UpdateWindow();
                  return 0;
                }
                if ( WindowLongA == 2 )
                  g_cpuProfile_history_tickMarks ^= 1u;
                goto LABEL_6;
              case 0x9CE1u:
                if ( WindowLongA == 1 )
                {
                  g_cpuProfile_samples_colors ^= 1u;
                  CpuProfile_UpdateWindow();
                  return 0;
                }
                if ( WindowLongA == 2 )
                  g_cpuProfile_history_colors ^= 1u;
                break;
              case 0x9CE2u:
                goto $LN11;
              case 0x9CE3u:
                goto $LN7_1;
              case 0x9CE4u:
                if ( VProf_GetState() == VPROF_CPU )
                  VProf_Enable(state: VPROF_OFF);
                else
                  VProf_Enable(state: VPROF_CPU);
                CpuProfile_SetTitle();
                return 0;
              default:
                return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
            }
            goto LABEL_6;
          }
          g_cpuProfile_fpsLabels ^= 1u;
          CpuProfile_UpdateWindow();
          return 0;
        }
      }
      else if ( message == 278 )
      {
        if ( WindowLongA == 1 )
        {
          CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE0u, uCheck: g_cpuProfile_samples_tickMarks ? 8 : 0);
          CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE1u, uCheck: g_cpuProfile_samples_colors ? 8 : 0);
        }
        else if ( WindowLongA == 2 )
        {
          CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE0u, uCheck: g_cpuProfile_history_tickMarks ? 8 : 0);
          CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE1u, uCheck: g_cpuProfile_history_colors ? 8 : 0);
        }
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC549u, uCheck: g_cpuProfile_fpsLabels != 0 ? 8 : 0);
        State = VProf_GetState();
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE4u, uCheck: State != VPROF_CPU ? 0 : 8);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
    }
    if ( wParam == (HMENU)45 )
    {
$LN11:
      if ( WindowLongA == 1 )
      {
        CpuProfile_ZoomIn(scale: &g_cpuProfile_samples_scale, numSteps: 10);
        return 0;
      }
      if ( WindowLongA == 2 )
        CpuProfile_ZoomIn(scale: &g_cpuProfile_history_scale, numSteps: 5);
    }
    else
    {
      if ( wParam != (HMENU)46 )
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
$LN7_1:
      if ( WindowLongA == 1 )
      {
        CpuProfile_ZoomOut(scale: &g_cpuProfile_samples_scale, numSteps: 10);
        return 0;
      }
      if ( WindowLongA == 2 )
      {
        CpuProfile_ZoomOut(scale: &g_cpuProfile_history_scale, numSteps: 5);
        return 0;
      }
    }
    return 0;
  }
  if ( message != 15 )
  {
    if ( message == 1 )
    {
      SetWindowLongA(hWnd: hwnd, nIndex: -21, dwNewLong: *lParam);
      g_cpuProfile_lastPeakTime = 0;
      return 0;
    }
    if ( message != 2 )
    {
      if ( message == 5 )
      {
LABEL_6:
        CpuProfile_UpdateWindow();
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
    }
    CpuProfile_SaveConfig();
    if ( v6 )
    {
      g_cpuProfile_hWndSamples = nullptr;
    }
    else if ( bIsHistory_3 )
    {
      g_cpuProfile_hWndHistory = nullptr;
    }
    if ( VProf_GetState() == VPROF_CPU )
    {
      VProf_Enable(state: VPROF_OFF);
      return 0;
    }
    return 0;
  }
  GetClientRect(hWnd: hwnd, lpRect: &rect);
  v8 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
  if ( v6 )
  {
    ProfileSamples_Draw(hdc: v8, clientRect: &rect);
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    return 0;
  }
  else
  {
    if ( bIsHistory_3 )
      ProfileHistory_Draw(hdc: v8, clientRect: &rect);
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E10
// Name: void CpuProfileHistory_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfileHistory_Open()
{
  if ( g_cpuProfile_hWndHistory != nullptr )
  {
    if ( IsIconic(hWnd: g_cpuProfile_hWndHistory) )
      ShowWindow(hWnd: g_cpuProfile_hWndHistory, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_cpuProfile_hWndHistory);
  }
  else
  {
    if ( VProf_GetState() == VPROF_OFF )
      VProf_Enable(state: VPROF_CPU);
    g_cpuProfile_hWndHistory = CreateWindowExA(
                                 dwExStyle: 0x200u,
                                 lpClassName: "CPUPROFILEHISTORYCLASS",
                                 lpWindowName: &str,
                                 dwStyle: 0x80CF0000,
                                 X: 0,
                                 Y: 0,
                                 nWidth: 600,
                                 nHeight: 500,
                                 hWndParent: g_hDlgMain,
                                 hMenu: nullptr,
                                 hInstance: g_hInstance,
                                 lpParam: (LPVOID)2);
    CpuProfile_SetTitle();
    if ( g_cpuProfile_historyWindowRect.right != 0 && g_cpuProfile_historyWindowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_cpuProfile_hWndHistory,
        X: g_cpuProfile_historyWindowRect.left,
        Y: g_cpuProfile_historyWindowRect.top,
        nWidth: g_cpuProfile_historyWindowRect.right - g_cpuProfile_historyWindowRect.left,
        nHeight: g_cpuProfile_historyWindowRect.bottom - g_cpuProfile_historyWindowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_cpuProfile_hWndHistory, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: void CpuProfileSamples_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfileSamples_Open()
{
  if ( g_cpuProfile_hWndSamples != nullptr )
  {
    if ( IsIconic(hWnd: g_cpuProfile_hWndSamples) )
      ShowWindow(hWnd: g_cpuProfile_hWndSamples, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_cpuProfile_hWndSamples);
  }
  else
  {
    if ( VProf_GetState() == VPROF_OFF )
      VProf_Enable(state: VPROF_CPU);
    g_cpuProfile_hWndSamples = CreateWindowExA(
                                 dwExStyle: 0x200u,
                                 lpClassName: "CPUPROFILESAMPLESCLASS",
                                 lpWindowName: &str,
                                 dwStyle: 0x80CF0000,
                                 X: 0,
                                 Y: 0,
                                 nWidth: 600,
                                 nHeight: 500,
                                 hWndParent: g_hDlgMain,
                                 hMenu: nullptr,
                                 hInstance: g_hInstance,
                                 lpParam: (LPVOID)1);
    CpuProfile_SetTitle();
    if ( g_cpuProfile_samplesWindowRect.right != 0 && g_cpuProfile_samplesWindowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_cpuProfile_hWndSamples,
        X: g_cpuProfile_samplesWindowRect.left,
        Y: g_cpuProfile_samplesWindowRect.top,
        nWidth: g_cpuProfile_samplesWindowRect.right - g_cpuProfile_samplesWindowRect.left,
        nHeight: g_cpuProfile_samplesWindowRect.bottom - g_cpuProfile_samplesWindowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_cpuProfile_hWndSamples, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405FD0
// Name: void CpuProfile_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_Clear()
{
  g_cpuProfile_numCounters = 0;
  g_cpuProfile_numSamples = 0;
  if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
    InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
    InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x00406030
// Name: bool CpuProfile_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CpuProfile_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h] BYREF
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = CpuProfile_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)4;
  wndclass.hCursor = (HICON__ *)"CPUPROFILESAMPLESCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  memset(&wndclass.lpfnWndProc, 0, 24);
  v2[0] = 0;
  v2[1] = CpuProfile_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)4;
  wndclass.hCursor = (HICON__ *)"CPUPROFILEHISTORYCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  CpuProfile_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004061F0
// Name: int rc_SetCpuProfileData(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetCpuProfileData(unsigned __int8 *data, unsigned int nPayloadSize)
{
  unsigned int SystemTime; // eax
  int v4; // eax
  int v5; // ecx
  unsigned int *v6; // esi
  unsigned int *v7; // edx
  int v8; // eax
  int v9; // edi
  int v10; // ebx
  bool v11; // zf
  unsigned int localCounters[64]; // [esp+0h] [ebp-110h] BYREF
  unsigned __int64 counters; // [esp+100h] [ebp-10h]
  int total; // [esp+108h] [ebp-8h]
  bool newPeaks; // [esp+10Fh] [ebp-1h]

  if ( g_cpuProfile_numCounters != 0 )
  {
    if ( nPayloadSize != 4 * g_cpuProfile_numCounters - 4 )
      return -1;
    memcpy(dst: (unsigned __int8 *)localCounters, src: data, count: nPayloadSize);
  }
  SystemTime = Sys_GetSystemTime();
  if ( SystemTime - g_cpuProfile_lastPeakTime <= 0xBB8 )
  {
    newPeaks = false;
  }
  else
  {
    g_cpuProfile_lastPeakTime = SystemTime;
    newPeaks = true;
  }
  v4 = g_cpuProfile_numSamples % 512;
  ++g_cpuProfile_numSamples;
  v5 = 0;
  total = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v6 = (unsigned int *)&unk_449B18;
    v7 = &g_cpuProfile_counters[v4];
    do
    {
      HIDWORD(counters) = localCounters[v5];
      v8 = _byteswap_ulong(HIDWORD(counters));
      v9 = g_cpuProfile_numCounters;
      v10 = g_cpuProfile_numCounters - 1;
      localCounters[v5] = v8;
      if ( v5 == v10 )
        v8 = total;
      else
        total += v8;
      v11 = !newPeaks;
      *v7 = v8;
      if ( !v11 || *v6 < *v7 )
        *v6 = *v7;
      ++v5;
      v7 += 530;
      v6 += 530;
    }
    while ( v5 < v9 );
  }
  DebugCommand(pStrFormat: "SetCpuProfileData( 0x%8.8x )\n", (_DWORD)counters);
  if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
    InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
    InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004063C0
// Name: int rc_SetCpuProfile(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetCpuProfile(unsigned __int8 *data, unsigned int nPayloadSize)
{
  int v2; // ebx
  signed int v3; // esi
  char *v4; // edi
  unsigned int *p_color; // esi
  CUtlVector<xrProfile_t,CUtlMemory<xrProfile_t,int> > localList; // [esp+Ch] [ebp-14h] BYREF

  v2 = 0;
  memset(&localList, 0, sizeof(localList));
  CUtlVector<xrProfile_t,CUtlMemory<xrProfile_t,int>>::InsertMultipleBefore(
    this: &localList,
    elem: 0,
    num: nPayloadSize / 0x44);
  memcpy(dst: (unsigned __int8 *)localList.m_Memory.m_pMemory, src: data, count: nPayloadSize);
  v3 = nPayloadSize / 0x44;
  g_cpuProfile_numCounters = nPayloadSize / 0x44;
  if ( (int)(nPayloadSize / 0x44) > 63 )
  {
    g_cpuProfile_numCounters = 63;
    v3 = 63;
  }
  if ( v3 > 0 )
  {
    v4 = pDest;
    p_color = &localList.m_Memory.m_pMemory->color;
    do
    {
      *p_color = _byteswap_ulong(*p_color);
      memset(dst: (unsigned __int8 *)v4 - 2052, value: 0, count: 0x848u);
      V_strncpy(pDest: v4, pSrc: (const char *)p_color - 64, maxLen: 64);
      *((_DWORD *)v4 + 16) = *p_color;
      ++v2;
      p_color += 17;
      v4 += 2120;
    }
    while ( v2 < g_cpuProfile_numCounters );
    v3 = g_cpuProfile_numCounters;
  }
  memset(dst: (unsigned __int8 *)&g_cpuProfile_counters[530 * v3], value: 0, count: 0x848u);
  *(_DWORD *)&pDest[2120 * v3] = *(_DWORD *)aTota;
  g_cpuProfile_numCounters = v3 + 1;
  word_449B20[1060 * v3] = 108;
  dword_449B5C[530 * v2] = 0xFFFFFF;
  if ( localList.m_Memory.m_nGrowSize >= 0 && localList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: localList.m_Memory.m_pMemory);
  return 0;
}
