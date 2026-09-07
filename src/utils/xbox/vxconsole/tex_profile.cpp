// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/tex_profile.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00428A20
// Name: void TexProfile_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryString(keyName: "texProfileSamplesWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_texProfile_samplesWindowRect,
         &g_texProfile_samplesWindowRect.top,
         &g_texProfile_samplesWindowRect.right,
         &g_texProfile_samplesWindowRect.bottom) != 4
    || g_texProfile_samplesWindowRect.left < 0
    || g_texProfile_samplesWindowRect.top < 0
    || g_texProfile_samplesWindowRect.right < 0
    || g_texProfile_samplesWindowRect.bottom < 0 )
  {
    *(_QWORD *)&g_texProfile_samplesWindowRect.left = 0;
    *(_QWORD *)&g_texProfile_samplesWindowRect.right = 0;
  }
  Sys_GetRegistryInteger(keyName: "texProfileSamplesScale", defValue: 0, value: &g_texProfile_samples_scale);
  if ( g_texProfile_samples_scale < -10 || g_texProfile_samples_scale > 10 )
    g_texProfile_samples_scale = 0;
  Sys_GetRegistryString(keyName: "texProfileHistoryWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_texProfile_historyWindowRect,
         &g_texProfile_historyWindowRect.top,
         &g_texProfile_historyWindowRect.right,
         &g_texProfile_historyWindowRect.bottom) != 4
    || g_texProfile_historyWindowRect.left < 0
    || g_texProfile_historyWindowRect.top < 0
    || g_texProfile_historyWindowRect.right < 0
    || g_texProfile_historyWindowRect.bottom < 0 )
  {
    *(_QWORD *)&g_texProfile_historyWindowRect.left = 0;
    *(_QWORD *)&g_texProfile_historyWindowRect.right = 0;
  }
  Sys_GetRegistryInteger(keyName: "texProfileHistoryScale", defValue: 0, value: &g_texProfile_history_scale);
  if ( g_texProfile_history_scale < -5 || g_texProfile_history_scale > 5 )
    g_texProfile_history_scale = 0;
  Sys_GetRegistryInteger(keyName: "texProfileCurrentFrame", defValue: 0, value: &g_texProfile_currentFrame);
}

//------------------------------------------------------------------------------
// Address: 0x00428BA0
// Name: void TexProfile_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_SaveConfig()
{
  char buff[256]; // [esp+8h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+108h] [ebp-2Ch] BYREF

  if ( g_texProfile_hWndSamples != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_texProfile_hWndSamples, lpwndpl: &wp);
    g_texProfile_samplesWindowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "texProfileSamplesWindowRect", value: buff);
  }
  Sys_SetRegistryInteger(keyName: "texProfileSamplesScale", value: g_texProfile_samples_scale);
  if ( g_texProfile_hWndHistory != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_texProfile_hWndHistory, lpwndpl: &wp);
    g_texProfile_historyWindowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "texProfileHistoryWindowRect", value: buff);
  }
  Sys_SetRegistryInteger(keyName: "texProfileHistoryScale", value: g_texProfile_history_scale);
  Sys_SetRegistryInteger(keyName: "texProfileCurrentFrame", value: g_texProfile_currentFrame);
}

//------------------------------------------------------------------------------
// Address: 0x00428CE0
// Name: void TexProfile_SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_SetTitle()
{
  char *v0; // eax
  char v1; // cl
  char *v2; // eax
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  char v8; // [esp+3h] [ebp-81h] BYREF
  char titleBuff[128]; // [esp+4h] [ebp-80h] BYREF

  if ( g_texProfile_hWndSamples != nullptr )
  {
    strcpy(titleBuff, "D3D Usage Snapshot");
    if ( VProf_GetState() == VPROF_TEXTURE || VProf_GetState() == VPROF_TEXTUREFRAME )
    {
      v0 = &v8;
      do
        v1 = *++v0;
      while ( v1 != 0 );
      strcpy(v0, " [ON]");
    }
    if ( g_texProfile_currentFrame != 0 )
    {
      v2 = &v8;
      do
        v3 = *++v2;
      while ( v3 != 0 );
      strcpy(v2, " [FRAME]");
    }
    SetWindowTextA(hWnd: g_texProfile_hWndSamples, lpString: titleBuff);
  }
  if ( g_texProfile_hWndHistory != nullptr )
  {
    strcpy(titleBuff, "D3D Usage History");
    if ( VProf_GetState() == VPROF_TEXTURE || VProf_GetState() == VPROF_TEXTUREFRAME )
    {
      v4 = &v8;
      do
        v5 = *++v4;
      while ( v5 != 0 );
      strcpy(v4, " [ON]");
    }
    if ( g_texProfile_currentFrame != 0 )
    {
      v6 = &v8;
      do
        v7 = *++v6;
      while ( v7 != 0 );
      strcpy(v6, " [FRAME]");
    }
    SetWindowTextA(hWnd: g_texProfile_hWndHistory, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428E50
// Name: void TexProfile_UpdateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_UpdateWindow()
{
  if ( g_texProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_texProfile_hWndSamples) )
    InvalidateRect(hWnd: g_texProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_texProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_texProfile_hWndHistory) )
    InvalidateRect(hWnd: g_texProfile_hWndHistory, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x00428EA0
// Name: void TexProfile_ZoomIn(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_ZoomIn(int *scale, int numSteps)
{
  if ( ++*scale <= numSteps )
  {
    if ( g_texProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_texProfile_hWndSamples) )
      InvalidateRect(hWnd: g_texProfile_hWndSamples, lpRect: nullptr, bErase: true);
    if ( g_texProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_texProfile_hWndHistory) )
      InvalidateRect(hWnd: g_texProfile_hWndHistory, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428F00
// Name: void TexProfile_ZoomOut(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfile_ZoomOut(int *scale, int numSteps)
{
  if ( --*scale >= -numSteps )
  {
    if ( g_texProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_texProfile_hWndSamples) )
      InvalidateRect(hWnd: g_texProfile_hWndSamples, lpRect: nullptr, bErase: true);
    if ( g_texProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_texProfile_hWndHistory) )
      InvalidateRect(hWnd: g_texProfile_hWndHistory, lpRect: nullptr, bErase: true);
  }
  else
  {
    *scale = -numSteps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428F60
// Name: void TexProfileSamples_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfileSamples_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  void (__stdcall *v3)(HDC, HGDIOBJ); // edi
  int v4; // ecx
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // edi
  const char *v9; // ebx
  unsigned int v10; // ecx
  _DWORD *v11; // eax
  int v12; // ebx
  COLORREF v13; // eax
  HGDIOBJ v14; // eax
  double v15; // st7
  int v16; // eax
  double v17; // st6
  int v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // edi
  double v22; // st7
  char labelBuff[128]; // [esp+14h] [ebp-E8h] BYREF
  tagPOINT points[4]; // [esp+94h] [ebp-68h] BYREF
  unsigned int textColorOld; // [esp+B4h] [ebp-48h]
  HPEN__ *hPenOld; // [esp+B8h] [ebp-44h]
  unsigned int backColorOld; // [esp+BCh] [ebp-40h]
  HFONT__ *hFontOld; // [esp+C0h] [ebp-3Ch]
  HPEN__ *hGreyPen; // [esp+C8h] [ebp-34h]
  int windowWidth; // [esp+CCh] [ebp-30h]
  int v31; // [esp+D0h] [ebp-2Ch]
  int tickWidth; // [esp+D4h] [ebp-28h]
  float sample; // [esp+D8h] [ebp-24h]
  HPEN__ *hBlackPen; // [esp+DCh] [ebp-20h]
  tagRECT rect; // [esp+E0h] [ebp-1Ch] BYREF
  int windowHeight; // [esp+F0h] [ebp-Ch]
  int y; // [esp+F4h] [ebp-8h]
  int numTicks; // [esp+F8h] [ebp-4h]
  int i; // [esp+108h] [ebp+Ch]
  int ia; // [esp+108h] [ebp+Ch]
  int ib; // [esp+108h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: g_textColor);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  backColorOld = SetBkColor(hdc, color: g_backgroundColor);
  textColorOld = SetTextColor(hdc, color: g_textColor);
  v4 = clientRect->right - clientRect->left;
  windowHeight = clientRect->bottom - clientRect->top;
  tickWidth = (int)(float)((float)((float)((float)((float)(g_texProfile_samples_scale + 10) * 0.050000001) * 2.7)
                                 + 0.30000001)
                         * 200.0);
  windowWidth = v4;
  numTicks = (v4 - 150) / tickWidth + 1;
  if ( numTicks < 0 )
    numTicks = 1;
  rect.left = 0;
  rect.top = 0;
  v5 = 150;
  rect.right = 150;
  rect.bottom = 15;
  DrawTextA(hdc, lpchText: "Name", cchText: -1, lprc: &rect, format: 0);
  i = 0;
  if ( numTicks > 0 )
  {
    y = windowHeight + 15;
    do
    {
      rect.right = v5 + 40;
      rect.left = v5 - 40;
      rect.top = 0;
      rect.bottom = 15;
      sprintf(string: labelBuff, format: "%dMB", 4 * i);
      DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 1u);
      v3(hdc, h: hBlackPen);
      MoveToEx(hdc, x: v5, y: 15, lppt: nullptr);
      LineTo(hdc, x: v5, y);
      if ( g_texProfile_samples_tickMarks && g_texProfile_samples_scale > -10 )
      {
        v6 = v5;
        SelectObject(hdc, h: hGreyPen);
        v7 = tickWidth / 4;
        v31 = tickWidth / 4;
        windowHeight = 3;
        while ( 1 )
        {
          v6 += v7;
          MoveToEx(hdc, x: v6, y: 15, lppt: nullptr);
          LineTo(hdc, x: v6, y);
          if ( --windowHeight == 0 )
            break;
          v7 = v31;
        }
        v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
      }
      v5 += tickWidth;
      ++i;
    }
    while ( i < numTicks );
  }
  v3(hdc, h: hBlackPen);
  MoveToEx(hdc, x: 0, y: 15, lppt: nullptr);
  LineTo(hdc, x: windowWidth, y: 15);
  ia = 0;
  if ( g_texProfile_numCounters > 0 )
  {
    v8 = 30;
    v9 = dword_495DE4;
    do
    {
      if ( v9 != nullptr )
      {
        rect.left = 0;
        rect.right = 145;
        rect.top = v8 - 15;
        rect.bottom = v8;
        DrawTextA(hdc, lpchText: v9, cchText: -1, lprc: &rect, format: 0x18026u);
        MoveToEx(hdc, x: 0, y: v8, lppt: nullptr);
        LineTo(hdc, x: 150, y: v8);
        v8 += 15;
      }
      v9 += 2120;
      ++ia;
    }
    while ( ia < g_texProfile_numCounters );
    v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
  v3(hdc, h: hBlackPen);
  if ( g_texProfile_numSamples - 1 >= 0 )
    v10 = (g_texProfile_numSamples - 1) & 0x800001FF;
  else
    v10 = 0;
  ib = 0;
  if ( g_texProfile_numCounters > 0 )
  {
    v11 = &unk_495DE0;
    numTicks = (int)&unk_495DE0;
    v12 = 19;
    y = (int)g_texProfile_counters + 4 * v10;
    do
    {
      if ( v11 != (_DWORD *)-4 )
      {
        if ( g_texProfile_samples_colors )
          v13 = v11[17];
        else
          v13 = g_backgroundColor;
        sample = COERCE_FLOAT(CreateSolidBrush(color: v13));
        v14 = SelectObject(hdc, h: (HGDIOBJ)LODWORD(sample));
        v15 = (double)tickWidth;
        windowHeight = (int)v14;
        v16 = *(_DWORD *)y;
        *(float *)&v31 = v15;
        v17 = (double)*(int *)y;
        if ( v16 < 0 )
          v17 = v17 + 4294967300.0;
        v18 = (int)(v15 * (v17 * 0.00000023841858));
        v19 = windowWidth;
        if ( v18 > windowWidth )
          v18 = windowWidth;
        Rectangle(hdc, left: 150, top: v12 - 1, right: v18 + 150, bottom: v12 + 9);
        v20 = (int)((double)*(unsigned int *)numTicks * 0.00000023841858 * *(float *)&v31);
        if ( v20 > v19 )
          v20 = v19;
        v21 = v20 + 150;
        points[1].y = v12 + 4;
        points[3].y = v12 + 4;
        points[1].x = v20 + 154;
        points[0].x = v20 + 150;
        points[0].y = v12;
        points[2].x = v20 + 150;
        points[2].y = v12 + 8;
        points[3].x = v20 + 146;
        Polygon(hdc, apt: points, cpt: 4);
        SelectObject(hdc, h: (HGDIOBJ)windowHeight);
        DeleteObject(ho: (HGDIOBJ)LODWORD(sample));
        v22 = (double)*(unsigned int *)numTicks * 0.0009765625;
        sample = v22;
        if ( v22 >= 0.0099999998 )
        {
          sprintf(string: labelBuff, format: "%.2f MB", (float)(sample * 0.0009765625));
          rect.left = v21 + 8;
          rect.top = v12 - 4;
          rect.right = v21 + 108;
          rect.bottom = v12 + 11;
          DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x24u);
        }
        v11 = (_DWORD *)numTicks;
        v12 += 15;
      }
      y += 2120;
      v11 += 530;
      ++ib;
      numTicks = (int)v11;
    }
    while ( ib < g_texProfile_numCounters );
    v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
  SetBkColor(hdc, color: backColorOld);
  SetTextColor(hdc, color: textColorOld);
  v3(hdc, h: hFontOld);
  v3(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x00429440
// Name: void TexProfileHistory_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfileHistory_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  void (__stdcall *v3)(HDC, HGDIOBJ); // edi
  COLORREF v4; // eax
  int v5; // ebx
  float v6; // xmm0_4
  int v7; // eax
  bool v8; // sf
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  COLORREF *v13; // ebx
  int v14; // eax
  COLORREF v15; // eax
  HBRUSH SolidBrush; // ebx
  HBRUSH__ *v17; // eax
  int v18; // edi
  char labelBuff[128]; // [esp+10h] [ebp-CCh] BYREF
  tagRECT rect; // [esp+90h] [ebp-4Ch] BYREF
  HFONT__ *hFontOld; // [esp+A0h] [ebp-3Ch]
  unsigned int backColorOld; // [esp+A4h] [ebp-38h]
  HPEN__ *hPenOld; // [esp+A8h] [ebp-34h]
  unsigned int textColorOld; // [esp+ACh] [ebp-30h]
  HBRUSH__ *hBrushOld; // [esp+B0h] [ebp-2Ch]
  int h; // [esp+B4h] [ebp-28h]
  HPEN__ *hGreyPen; // [esp+B8h] [ebp-24h]
  HPEN__ *hBlackPen; // [esp+BCh] [ebp-20h]
  int tickHeight; // [esp+C0h] [ebp-1Ch]
  int windowHeight; // [esp+C4h] [ebp-18h]
  int j; // [esp+C8h] [ebp-14h]
  int v32; // [esp+CCh] [ebp-10h]
  int x; // [esp+D0h] [ebp-Ch]
  int numTicks; // [esp+D4h] [ebp-8h]
  int i; // [esp+D8h] [ebp-4h]
  int y; // [esp+E8h] [ebp+Ch]
  int ya; // [esp+E8h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: g_textColor);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  j = (int)CreatePen(iStyle: 5, cWidth: 0, color: 0);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  backColorOld = SetBkColor(hdc, color: g_backgroundColor);
  v4 = SetTextColor(hdc, color: g_textColor);
  v5 = clientRect->right - clientRect->left;
  v6 = (float)((float)((float)((float)(g_texProfile_history_scale + 5) * 0.1) * 2.7) + 0.30000001) * 100.0;
  textColorOld = v4;
  windowHeight = clientRect->bottom - clientRect->top;
  v7 = windowHeight / (int)v6;
  tickHeight = (int)v6;
  v8 = v7 + 2 < 0;
  v9 = v7 + 2;
  numTicks = v9;
  if ( v8 )
  {
    numTicks = 1;
    v9 = 1;
  }
  y = windowHeight;
  i = 0;
  if ( v9 > 0 )
  {
    do
    {
      v3(hdc, h: hBlackPen);
      MoveToEx(hdc, x: 0, y, lppt: nullptr);
      LineTo(hdc, x: v5, y);
      if ( g_texProfile_history_tickMarks && g_texProfile_history_scale > -5 )
      {
        v10 = y;
        SelectObject(hdc, h: hGreyPen);
        v11 = tickHeight / 4;
        v32 = tickHeight / 4;
        x = 3;
        while ( 1 )
        {
          v10 += v11;
          MoveToEx(hdc, x: 0, y: v10, lppt: nullptr);
          LineTo(hdc, x: v5, y: v10);
          if ( --x == 0 )
            break;
          v11 = v32;
        }
        v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
      }
      v12 = i;
      if ( i != 0 )
      {
        rect.left = v5 - 50;
        rect.bottom = y;
        rect.right = v5;
        rect.top = y - 20;
        sprintf(string: labelBuff, format: "%dMB", 4 * i);
        DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x2Au);
        v12 = i;
      }
      y -= tickHeight;
      i = v12 + 1;
    }
    while ( v12 + 1 < numTicks );
  }
  if ( g_texProfile_numSamples != 0 )
  {
    v3(hdc, h: (HGDIOBJ)j);
    i = g_texProfile_numSamples - 1;
    for ( x = v5 - 51; x >= 0; x -= 4 )
    {
      ya = windowHeight;
      j = 0;
      if ( g_texProfile_numCounters - 1 > 0 )
      {
        v13 = (COLORREF *)&dword_495E24;
        numTicks = 0;
        v32 = (int)&dword_495E24;
        do
        {
          if ( v13 != (COLORREF *)64 )
          {
            v14 = (int)((double)g_texProfile_counters[numTicks + i % 512] * 0.00000023841858 * (double)tickHeight);
            h = v14;
            if ( v14 != 0 )
            {
              if ( v14 > windowHeight )
                h = windowHeight;
              if ( g_texProfile_history_colors )
                v15 = *v13;
              else
                v15 = 5263440;
              SolidBrush = CreateSolidBrush(color: v15);
              v17 = (HBRUSH__ *)((HGDIOBJ (__stdcall *)(HDC, HGDIOBJ))v3)(hdc, h: SolidBrush);
              v18 = ya - h;
              hBrushOld = v17;
              Rectangle(hdc, left: x - 4, top: ya - h, right: x, bottom: ya + 1);
              ya = v18;
              SelectObject(hdc, h: hBrushOld);
              DeleteObject(ho: SolidBrush);
              v13 = (COLORREF *)v32;
              v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
            }
          }
          numTicks += 530;
          v13 += 530;
          ++j;
          v32 = (int)v13;
        }
        while ( j < g_texProfile_numCounters - 1 );
      }
      if ( --i < 0 )
        break;
    }
  }
  SetBkColor(hdc, color: backColorOld);
  SetTextColor(hdc, color: textColorOld);
  v3(hdc, h: hFontOld);
  v3(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x004297B0
// Name: long TexProfile_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall TexProfile_WndProc(HWND hwnd, UINT message, HMENU wParam, LONG *lParam)
{
  LONG WindowLongA; // eax
  bool v6; // bl
  int result; // eax
  HDC v8; // eax
  UINT v9; // eax
  bool v11; // al
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-50h] BYREF
  tagRECT rect; // [esp+4Ch] [ebp-10h] BYREF
  bool bIsHistory_3; // [esp+67h] [ebp+Bh]

  WindowLongA = GetWindowLongA(hWnd: hwnd, nIndex: -21);
  v6 = WindowLongA == 1;
  bIsHistory_3 = WindowLongA == 2;
  if ( message <= 0x14 )
  {
    if ( message == 20 )
      return 1;
    switch ( message )
    {
      case 1u:
        SetWindowLongA(hWnd: hwnd, nIndex: -21, dwNewLong: *lParam);
        g_texProfile_lastPeakTime = 0;
        result = 0;
        break;
      case 2u:
        TexProfile_SaveConfig();
        if ( v6 )
        {
          g_texProfile_hWndSamples = nullptr;
        }
        else if ( bIsHistory_3 )
        {
          g_texProfile_hWndHistory = nullptr;
        }
        if ( VProf_GetState() != VPROF_TEXTURE && VProf_GetState() != VPROF_TEXTUREFRAME )
          return 0;
        VProf_Enable(state: VPROF_OFF);
        result = 0;
        break;
      case 5u:
        goto LABEL_31;
      case 0xFu:
        GetClientRect(hWnd: hwnd, lpRect: &rect);
        v8 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
        if ( v6 )
        {
          DrawHelper(hdc: v8, clientRect: (HBRUSH__ *)&rect, drawFunc: TexProfileSamples_Draw);
        }
        else if ( bIsHistory_3 )
        {
          DrawHelper(hdc: v8, clientRect: (HBRUSH__ *)&rect, drawFunc: TexProfileHistory_Draw);
        }
        EndPaint(hWnd: hwnd, lpPaint: &ps);
        result = 0;
        break;
      default:
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
    }
    return result;
  }
  if ( message == 256 )
  {
    if ( wParam == (HMENU)45 || wParam == (HMENU)46 )
      return 0;
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  if ( message != 273 )
  {
    if ( message == 278 )
    {
      if ( WindowLongA == 1 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE6u, uCheck: g_texProfile_samples_tickMarks ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE8u, uCheck: g_texProfile_samples_colors ? 8 : 0);
      }
      else if ( WindowLongA == 2 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE6u, uCheck: g_texProfile_history_tickMarks ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE8u, uCheck: g_texProfile_history_colors ? 8 : 0);
      }
      if ( VProf_GetState() == VPROF_TEXTURE || VProf_GetState() == VPROF_TEXTUREFRAME )
        v9 = 8;
      else
        v9 = 0;
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CEEu, uCheck: v9);
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CF0u, uCheck: g_texProfile_currentFrame != 0 ? 8 : 0);
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  switch ( (unsigned __int16)wParam )
  {
    case 0x9CE6u:
    case 0x9CE8u:
LABEL_31:
      TexProfile_UpdateWindow();
      return 0;
    case 0x9CECu:
    case 0x9CEDu:
      return 0;
    case 0x9CEEu:
      if ( VProf_GetState() != VPROF_TEXTURE && VProf_GetState() != VPROF_TEXTUREFRAME )
        goto LABEL_47;
      VProf_Enable(state: VPROF_OFF);
      TexProfile_SetTitle();
      result = 0;
      break;
    case 0x9CF0u:
      v11 = VProf_GetState() == VPROF_TEXTURE || VProf_GetState() == VPROF_TEXTUREFRAME;
      g_texProfile_currentFrame ^= 1u;
      if ( v11 )
      {
LABEL_47:
        if ( g_texProfile_currentFrame != 0 )
          VProf_Enable(state: VPROF_TEXTUREFRAME);
        else
          VProf_Enable(state: VPROF_TEXTURE);
      }
      TexProfile_SetTitle();
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429BB0
// Name: void TexProfileHistory_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfileHistory_Open()
{
  if ( g_texProfile_hWndHistory != nullptr )
  {
    if ( IsIconic(hWnd: g_texProfile_hWndHistory) )
      ShowWindow(hWnd: g_texProfile_hWndHistory, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_texProfile_hWndHistory);
  }
  else
  {
    if ( VProf_GetState() == VPROF_OFF )
    {
      if ( g_texProfile_currentFrame != 0 )
        VProf_Enable(state: VPROF_TEXTUREFRAME);
      else
        VProf_Enable(state: VPROF_TEXTURE);
    }
    g_texProfile_hWndHistory = CreateWindowExA(
                                 dwExStyle: 0x200u,
                                 lpClassName: "TEXPROFILEHISTORYCLASS",
                                 lpWindowName: &defValue,
                                 dwStyle: 0x80CF0000,
                                 X: 0,
                                 Y: 0,
                                 nWidth: 600,
                                 nHeight: 500,
                                 hWndParent: g_hDlgMain,
                                 hMenu: nullptr,
                                 hInstance: g_hInstance,
                                 lpParam: (LPVOID)2);
    TexProfile_SetTitle();
    if ( g_texProfile_historyWindowRect.right != 0 && g_texProfile_historyWindowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_texProfile_hWndHistory,
        X: g_texProfile_historyWindowRect.left,
        Y: g_texProfile_historyWindowRect.top,
        nWidth: g_texProfile_historyWindowRect.right - g_texProfile_historyWindowRect.left,
        nHeight: g_texProfile_historyWindowRect.bottom - g_texProfile_historyWindowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_texProfile_hWndHistory, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429C90
// Name: void TexProfileSamples_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexProfileSamples_Open()
{
  if ( g_texProfile_hWndSamples != nullptr )
  {
    if ( IsIconic(hWnd: g_texProfile_hWndSamples) )
      ShowWindow(hWnd: g_texProfile_hWndSamples, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_texProfile_hWndSamples);
  }
  else
  {
    if ( VProf_GetState() == VPROF_OFF )
    {
      if ( g_texProfile_currentFrame != 0 )
        VProf_Enable(state: VPROF_TEXTUREFRAME);
      else
        VProf_Enable(state: VPROF_TEXTURE);
    }
    g_texProfile_hWndSamples = CreateWindowExA(
                                 dwExStyle: 0x200u,
                                 lpClassName: "TEXPROFILESAMPLESCLASS",
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
    TexProfile_SetTitle();
    if ( g_texProfile_samplesWindowRect.right != 0 && g_texProfile_samplesWindowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_texProfile_hWndSamples,
        X: g_texProfile_samplesWindowRect.left,
        Y: g_texProfile_samplesWindowRect.top,
        nWidth: g_texProfile_samplesWindowRect.right - g_texProfile_samplesWindowRect.left,
        nHeight: g_texProfile_samplesWindowRect.bottom - g_texProfile_samplesWindowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_texProfile_hWndSamples, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429D70
// Name: bool TexProfile_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall TexProfile_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h] BYREF
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = TexProfile_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)120;
  wndclass.hCursor = (HICON__ *)"TEXPROFILESAMPLESCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  memset(&wndclass.lpfnWndProc, 0, 24);
  v2[0] = 0;
  v2[1] = TexProfile_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)120;
  wndclass.hCursor = (HICON__ *)"TEXPROFILEHISTORYCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  TexProfile_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429E80
// Name: int rc_SetTexProfile(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetTexProfile(char *commandPtr)
{
  char *Token; // eax
  char *v2; // eax
  char *v3; // eax
  signed int v4; // esi
  int v5; // ebx
  char *v6; // edi
  unsigned int *p_color; // esi
  xrProfile_t *localList; // [esp+8h] [ebp-14h]
  int retAddr; // [esp+Ch] [ebp-10h] BYREF
  int xboxRetVal; // [esp+10h] [ebp-Ch] BYREF
  int profileList; // [esp+14h] [ebp-8h] BYREF
  int numProfiles; // [esp+18h] [ebp-4h] BYREF

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &numProfiles);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%x", &profileList);
  v3 = GetToken(ppTokenStream: &commandPtr);
  if ( *v3 == 0 )
    return -1;
  sscanf(string: v3, format: "%x", &retAddr);
  localList = (xrProfile_t *)operator new(nSize: 132 * numProfiles);
  memset(dst: (unsigned __int8 *)localList, value: 0, count: 132 * numProfiles);
  DmGetMemory(a1: profileList, a2: 132 * numProfiles, a3: localList, a4: 0);
  v4 = numProfiles;
  g_texProfile_numCounters = numProfiles;
  if ( numProfiles > 63 )
  {
    g_texProfile_numCounters = 63;
    v4 = 63;
  }
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = dword_495DE4;
    p_color = &localList->color;
    do
    {
      *p_color = _byteswap_ulong(*p_color);
      memset(dst: (unsigned __int8 *)v6 - 2052, value: 0, count: 0x848u);
      V_strncpy(pDest: v6, pSrc: (const char *)p_color - 128, maxLen: 64);
      *((_DWORD *)v6 + 16) = *p_color;
      ++v5;
      p_color += 33;
      v6 += 2120;
    }
    while ( v5 < g_texProfile_numCounters );
    v4 = g_texProfile_numCounters;
  }
  memset(dst: (unsigned __int8 *)&g_texProfile_counters[530 * v4], value: 0, count: 0x848u);
  *(_DWORD *)&dword_495DE4[2120 * v4] = *(_DWORD *)s2;
  g_texProfile_numCounters = v4 + 1;
  word_495DE8[1060 * v4] = 108;
  dword_495E24[530 * v5] = 0xFFFFFF;
  xboxRetVal = _byteswap_ulong(v4);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = SetTexProfile( 0x%8.8x, 0x%8.8x )\n", v4, numProfiles, profileList);
  free(pMem: localList);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042A060
// Name: int rc_SetTexProfileData(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetTexProfileData(char *commandPtr)
{
  char *Token; // eax
  unsigned int SystemTime; // eax
  int v3; // eax
  int v4; // ecx
  unsigned int *v5; // esi
  unsigned int *v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  bool v10; // zf
  unsigned int localCounters[64]; // [esp+4h] [ebp-110h] BYREF
  unsigned int v13; // [esp+104h] [ebp-10h]
  int total; // [esp+108h] [ebp-Ch]
  int counters; // [esp+10Ch] [ebp-8h] BYREF
  bool newPeaks; // [esp+113h] [ebp-1h]

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &counters);
  if ( g_texProfile_numCounters != 0 )
    DmGetMemory(a1: counters, a2: 4 * g_texProfile_numCounters - 4, a3: localCounters, a4: 0);
  SystemTime = Sys_GetSystemTime();
  if ( SystemTime - g_texProfile_lastPeakTime <= 0xBB8 )
  {
    newPeaks = false;
  }
  else
  {
    g_texProfile_lastPeakTime = SystemTime;
    newPeaks = true;
  }
  v3 = g_texProfile_numSamples % 512;
  ++g_texProfile_numSamples;
  v4 = 0;
  total = 0;
  if ( g_texProfile_numCounters > 0 )
  {
    v5 = (unsigned int *)&unk_495DE0;
    v6 = &g_texProfile_counters[v3];
    do
    {
      v13 = localCounters[v4];
      v7 = _byteswap_ulong(v13);
      v8 = g_texProfile_numCounters;
      v9 = g_texProfile_numCounters - 1;
      localCounters[v4] = v7;
      if ( v4 == v9 )
        v7 = total;
      else
        total += v7;
      v10 = !newPeaks;
      *v6 = v7;
      if ( !v10 || *v5 < *v6 )
        *v5 = *v6;
      ++v4;
      v6 += 530;
      v5 += 530;
    }
    while ( v4 < v8 );
  }
  DebugCommand(pStrFormat: "SetTexProfileData( 0x%8.8x )\n", counters);
  if ( g_texProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_texProfile_hWndSamples) )
    InvalidateRect(hWnd: g_texProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_texProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_texProfile_hWndHistory) )
    InvalidateRect(hWnd: g_texProfile_hWndHistory, lpRect: nullptr, bErase: true);
  return 0;
}
