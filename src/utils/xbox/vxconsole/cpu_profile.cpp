// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/cpu_profile.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F0D0
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
// Address: 0x0040F210
// Name: void CpuProfile_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CpuProfile_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryString(keyName: "profileSamplesWindowRect", value: buff, defValue: &defValue, valueLen: 256);
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
  if ( g_cpuProfile_samples_scale < -20 || g_cpuProfile_samples_scale > 20 )
    g_cpuProfile_samples_scale = 0;
  Sys_GetRegistryString(keyName: "profileHistoryWindowRect", value: buff, defValue: &defValue, valueLen: 256);
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
// Address: 0x0040F350
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
// Address: 0x0040F440
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
// Address: 0x0040F490
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
// Address: 0x0040F4F0
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
// Address: 0x0040F550
// Name: void ProfileSamples_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProfileSamples_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  int v3; // ebx
  int v4; // ecx
  int v5; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ebx
  int v9; // edi
  void (__stdcall *v10)(HDC, HGDIOBJ); // edi
  const char *v11; // eax
  int v12; // edi
  char *v13; // edi
  int v14; // edx
  double v15; // st6
  double v16; // st6
  int v17; // eax
  double v18; // st6
  int v19; // eax
  int v20; // ebx
  _DWORD *v21; // eax
  int v22; // ebx
  COLORREF v23; // eax
  HGDIOBJ v24; // eax
  double v25; // st7
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // edi
  double v30; // st7
  double *v31; // eax
  int v32; // edi
  double v33; // xmm0_8
  double v34; // xmm1_8
  double v35; // xmm0_8
  int v36; // eax
  int v37; // eax
  double v38; // xmm1_8
  int v39; // ebx
  COLORREF scale; // [esp+24h] [ebp-198h]
  char labelBuff[256]; // [esp+34h] [ebp-188h] BYREF
  double cur; // [esp+134h] [ebp-88h]
  double rangeLow; // [esp+13Ch] [ebp-80h]
  double stddev; // [esp+144h] [ebp-78h]
  double avg; // [esp+14Ch] [ebp-70h]
  tagPOINT points[4]; // [esp+154h] [ebp-68h] BYREF
  HFONT__ *hFontOld; // [esp+174h] [ebp-48h]
  HPEN__ *hPenOld; // [esp+178h] [ebp-44h]
  unsigned int backColorOld; // [esp+17Ch] [ebp-40h]
  unsigned int textColorOld; // [esp+180h] [ebp-3Ch]
  double rangeHigh; // [esp+184h] [ebp-38h]
  HPEN__ *hGreyPen; // [esp+18Ch] [ebp-30h]
  HPEN__ *hBlackPen; // [esp+190h] [ebp-2Ch]
  int windowWidth; // [esp+194h] [ebp-28h]
  float v55; // [esp+198h] [ebp-24h]
  tagRECT rect; // [esp+19Ch] [ebp-20h] BYREF
  int currentSample; // [esp+1ACh] [ebp-10h]
  int y; // [esp+1B0h] [ebp-Ch]
  int wavg; // [esp+1B4h] [ebp-8h]
  int w1; // [esp+1B8h] [ebp-4h]
  int i; // [esp+1C8h] [ebp+Ch]
  int ia; // [esp+1C8h] [ebp+Ch]
  int ib; // [esp+1C8h] [ebp+Ch]
  int ic; // [esp+1C8h] [ebp+Ch]
  int id; // [esp+1C8h] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: g_textColor);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  backColorOld = SetBkColor(hdc, color: g_backgroundColor);
  textColorOld = SetTextColor(hdc, color: g_textColor);
  v3 = clientRect->right - clientRect->left;
  v4 = clientRect->bottom - clientRect->top;
  currentSample = (int)(float)((float)((float)((float)((float)(g_cpuProfile_samples_scale + 20) * 0.025) * 5.6999998)
                                     + 0.30000001)
                             * 200.0);
  windowWidth = v3;
  wavg = v4;
  y = (v3 - 150) / currentSample + 1;
  if ( y < 0 )
    y = 1;
  rect.left = 0;
  rect.top = 0;
  v5 = 150;
  rect.right = 150;
  rect.bottom = 15;
  DrawTextA(hdc, lpchText: "Name", cchText: -1, lprc: &rect, format: 0);
  v6 = 0;
  w1 = 150;
  i = 0;
  if ( y > 0 )
  {
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
      SelectObject(hdc, h: hBlackPen);
      MoveToEx(hdc, x: v5, y: 15, lppt: nullptr);
      LineTo(hdc, x: v5, y: wavg + 15);
      if ( g_cpuProfile_samples_tickMarks && g_cpuProfile_samples_scale > -20 )
      {
        SelectObject(hdc, h: hGreyPen);
        v8 = currentSample / 4;
        LODWORD(v55) = 3;
        do
        {
          v5 += v8;
          MoveToEx(hdc, x: v5, y: 15, lppt: nullptr);
          LineTo(hdc, x: v5, y: wavg + 15);
          --LODWORD(v55);
        }
        while ( v55 != 0.0 );
        v5 = w1;
        v3 = windowWidth;
      }
      v5 += currentSample;
      w1 = v5;
      if ( ++i >= y )
        break;
      v6 = i;
    }
  }
  v55 = (float)currentSample;
  v9 = (int)(float)((float)currentSample * 0.059999999);
  if ( v9 <= v3 )
  {
    MoveToEx(hdc, x: v9 + 150, y: 15, lppt: nullptr);
    LineTo(hdc, x: v9 + 150, y: wavg + 15);
    rect.left = v9 + 110;
    rect.right = v9 + 190;
    rect.top = 0;
    rect.bottom = 15;
    if ( g_cpuProfile_fpsLabels != 0 )
      sprintf(string: labelBuff, format: "1000fps");
    else
      sprintf(string: labelBuff, format: "1 ms");
    DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 1u);
  }
  v10 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  SelectObject(hdc, h: hBlackPen);
  MoveToEx(hdc, x: 0, y: 15, lppt: nullptr);
  LineTo(hdc, x: v3, y: 15);
  ia = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v11 = pDest;
    v12 = 30;
    *(float *)&w1 = COERCE_FLOAT(pDest);
    do
    {
      if ( v11 != nullptr )
      {
        rect.left = 0;
        rect.right = 145;
        rect.top = v12 - 15;
        rect.bottom = v12;
        DrawTextA(hdc, lpchText: v11, cchText: -1, lprc: &rect, format: 0x18026u);
        MoveToEx(hdc, x: 0, y: v12, lppt: nullptr);
        LineTo(hdc, x: 150, y: v12);
        v11 = (const char *)w1;
        v12 += 15;
      }
      v11 += 2152;
      ++ia;
      w1 = (int)v11;
    }
    while ( ia < g_cpuProfile_numCounters );
    v10 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
  if ( g_cpuProfile_numSamples - 1 >= 0 )
    currentSample = (g_cpuProfile_numSamples - 1) % 512;
  else
    currentSample = 0;
  if ( g_cpuProfile_samples_averages )
  {
    SetBkColor(hdc, color: 0x8C8C8Cu);
    v10(hdc, h: g_hFixedFont);
    y = 15;
    ib = 0;
    if ( g_cpuProfile_numCounters > 0 )
    {
      v13 = pDest;
      wavg = (int)g_cpuProfile_counters + 4 * currentSample;
      do
      {
        if ( v13 != nullptr )
        {
          if ( _V_stricmp(s1: v13, s2: s2) == 0 )
            y += 15;
          v14 = *((_DWORD *)v13 - 2);
          v15 = (double)*(unsigned int *)wavg * 0.001;
          avg = *((double *)v13 - 3) * 0.001;
          cur = v15;
          v16 = (double)*((int *)v13 - 2);
          stddev = *((double *)v13 - 2) * 0.001;
          if ( v14 < 0 )
            v16 = v16 + 4294967296.0;
          v17 = *((_DWORD *)v13 - 1);
          rangeLow = v16 * 0.001;
          v18 = (double)*((int *)v13 - 1);
          if ( v17 < 0 )
            v18 = v18 + 4294967296.0;
          scale = *((_DWORD *)v13 + 16);
          rangeHigh = 0.001 * v18;
          SetTextColor(hdc, color: scale);
          sprintf(
            string: labelBuff,
            format: "cur %5.2f avg %5.2f stddev %6.3f [%6.3f->%6.3f]",
            cur,
            avg,
            stddev,
            rangeLow,
            rangeHigh);
          v19 = v3 - 408;
          rect.right = v3 - 8;
          rect.top = y;
          v20 = y + 15;
          rect.left = v19;
          rect.bottom = y + 15;
          DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x24u);
          y = v20;
          v3 = windowWidth;
        }
        wavg += 2152;
        v13 += 2152;
        ++ib;
      }
      while ( ib < g_cpuProfile_numCounters );
      v10 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    }
    SetBkColor(hdc, color: g_backgroundColor);
    SetTextColor(hdc, color: g_textColor);
    v10(hdc, h: g_hProportionalFont);
  }
  v10(hdc, h: hBlackPen);
  ic = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v21 = &unk_46BDA8;
    y = (int)&unk_46BDA8;
    v22 = 19;
    wavg = (int)g_cpuProfile_counters + 4 * currentSample;
    do
    {
      if ( v21 != (_DWORD *)-32 )
      {
        if ( g_cpuProfile_samples_colors )
          v23 = v21[24];
        else
          v23 = g_backgroundColor;
        currentSample = (int)CreateSolidBrush(color: v23);
        v24 = SelectObject(hdc, h: (HGDIOBJ)currentSample);
        v25 = (double)*(unsigned int *)wavg;
        w1 = (int)v24;
        v26 = (int)(v25 * 0.000060000002 * v55);
        v27 = windowWidth;
        if ( v26 > windowWidth )
          v26 = windowWidth;
        Rectangle(hdc, left: 150, top: v22 - 1, right: v26 + 150, bottom: v22 + 9);
        v28 = (int)((double)*(unsigned int *)y * 0.000060000002 * v55);
        if ( v28 > v27 )
          v28 = v27;
        v29 = v28 + 150;
        points[1].y = v22 + 4;
        points[3].y = v22 + 4;
        points[1].x = v28 + 154;
        points[0].x = v28 + 150;
        points[0].y = v22;
        points[2].x = v28 + 150;
        points[2].y = v22 + 8;
        points[3].x = v28 + 146;
        Polygon(hdc, apt: points, cpt: 4);
        SelectObject(hdc, h: (HGDIOBJ)w1);
        DeleteObject(ho: (HGDIOBJ)currentSample);
        v30 = (double)*(unsigned int *)y * 0.001;
        *(float *)&w1 = v30;
        if ( v30 >= 0.0099999998 )
        {
          sprintf(string: labelBuff, format: "%.2f", *(float *)&w1);
          rect.left = v29 + 8;
          rect.top = v22 - 4;
          rect.right = v29 + 108;
          rect.bottom = v22 + 11;
          DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x24u);
        }
        v21 = (_DWORD *)y;
        v22 += 15;
      }
      wavg += 2152;
      v21 += 538;
      ++ic;
      y = (int)v21;
    }
    while ( ic < g_cpuProfile_numCounters );
    v3 = windowWidth;
    v10 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
  if ( g_cpuProfile_samples_averages )
  {
    v10(hdc, h: hBlackPen);
    id = 0;
    if ( g_cpuProfile_numCounters > 0 )
    {
      v31 = (double *)&unk_46BDB0;
      v32 = 25;
      currentSample = (int)&unk_46BDB0;
      do
      {
        if ( v31 != (double *)-24 )
        {
          v33 = v31[1];
          v34 = (*v31 - v33) * 0.00005999999999999999;
          v35 = (v33 + *v31) * 0.00005999999999999999;
          v36 = (int)(v55 * (*v31 * 0.00005999999999999999));
          if ( v36 >= v3 )
            v36 = v3;
          wavg = v36 + 150;
          v37 = (int)(v55 * v34);
          if ( v37 >= v3 )
            v37 = v3;
          v38 = v55 * v35;
          w1 = v37 + 150;
          if ( (int)v38 < v3 )
            v3 = (int)v38;
          v39 = v3 + 150;
          MoveToEx(hdc, x: v37 + 150, y: v32 - 2, lppt: nullptr);
          LineTo(hdc, x: v39, y: v32 - 2);
          MoveToEx(hdc, x: w1, y: v32 - 4, lppt: nullptr);
          LineTo(hdc, x: w1, y: v32);
          MoveToEx(hdc, x: wavg, y: v32 - 4, lppt: nullptr);
          LineTo(hdc, x: wavg, y: v32);
          MoveToEx(hdc, x: v39, y: v32 - 4, lppt: nullptr);
          LineTo(hdc, x: v39, y: v32);
          v31 = (double *)currentSample;
          v3 = windowWidth;
          v32 += 15;
        }
        v31 += 269;
        ++id;
        currentSample = (int)v31;
      }
      while ( id < g_cpuProfile_numCounters );
      v10 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    }
  }
  SetBkColor(hdc, color: backColorOld);
  SetTextColor(hdc, color: textColorOld);
  v10(hdc, h: hFontOld);
  v10(hdc, h: hPenOld);
  DeleteObject(ho: hBlackPen);
  DeleteObject(ho: hGreyPen);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE50
// Name: void ProfileHistory_Draw(struct HDC__ __near *,struct tagRECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProfileHistory_Draw(HDC__ *hdc, tagRECT *clientRect)
{
  COLORREF v2; // eax
  HGDIOBJ (__stdcall *v3)(HDC, HGDIOBJ); // edi
  int v4; // ebx
  float v5; // xmm0_4
  int v6; // eax
  bool v7; // sf
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  COLORREF *v13; // ebx
  int v14; // eax
  COLORREF v15; // eax
  HBRUSH SolidBrush; // ebx
  HBRUSH__ *v17; // eax
  int v18; // edi
  char labelBuff[128]; // [esp+14h] [ebp-CCh] BYREF
  tagRECT rect; // [esp+94h] [ebp-4Ch] BYREF
  HFONT__ *hFontOld; // [esp+A4h] [ebp-3Ch]
  unsigned int backColorOld; // [esp+A8h] [ebp-38h]
  HPEN__ *hPenOld; // [esp+ACh] [ebp-34h]
  unsigned int textColorOld; // [esp+B0h] [ebp-30h]
  HBRUSH__ *hBrushOld; // [esp+B4h] [ebp-2Ch]
  HPEN__ *hGreyPen; // [esp+B8h] [ebp-28h]
  HPEN__ *hBlackPen; // [esp+BCh] [ebp-24h]
  int timingHeight; // [esp+C0h] [ebp-20h]
  int windowHeight; // [esp+C4h] [ebp-1Ch]
  int j; // [esp+C8h] [ebp-18h]
  int v31; // [esp+CCh] [ebp-14h]
  int h; // [esp+D0h] [ebp-10h]
  int x; // [esp+D4h] [ebp-Ch]
  int numTicks; // [esp+D8h] [ebp-8h]
  int i; // [esp+DCh] [ebp-4h]
  int y; // [esp+ECh] [ebp+Ch]
  int ya; // [esp+ECh] [ebp+Ch]

  hBlackPen = CreatePen(iStyle: 0, cWidth: 1, color: g_textColor);
  v2 = Sys_ColorScale(color: g_backgroundColor, scale: 0.85000002);
  hGreyPen = CreatePen(iStyle: 0, cWidth: 1, color: v2);
  v3 = SelectObject;
  j = (int)CreatePen(iStyle: 5, cWidth: 0, color: 0);
  hPenOld = (HPEN__ *)SelectObject(hdc, h: hBlackPen);
  hFontOld = (HFONT__ *)SelectObject(hdc, h: g_hProportionalFont);
  backColorOld = SetBkColor(hdc, color: g_backgroundColor);
  textColorOld = SetTextColor(hdc, color: g_textColor);
  v4 = clientRect->right - clientRect->left;
  v5 = (float)((float)((float)((float)(g_cpuProfile_history_scale + 5) * 0.1) * 2.7) + 0.30000001) * 100.0;
  windowHeight = clientRect->bottom - clientRect->top;
  v6 = windowHeight / (int)v5;
  timingHeight = (int)v5;
  h = v4;
  v7 = v6 + 2 < 0;
  v8 = v6 + 2;
  numTicks = v8;
  if ( v7 )
  {
    numTicks = 1;
    v8 = 1;
  }
  y = windowHeight;
  i = 0;
  if ( v8 > 0 )
  {
    do
    {
      SelectObject(hdc, h: hBlackPen);
      MoveToEx(hdc, x: 0, y, lppt: nullptr);
      LineTo(hdc, x: v4, y);
      if ( g_cpuProfile_history_tickMarks && g_cpuProfile_history_scale > -5 )
      {
        v9 = y;
        SelectObject(hdc, h: hGreyPen);
        v10 = timingHeight / 4;
        v31 = timingHeight / 4;
        x = 3;
        while ( 1 )
        {
          v9 += v10;
          MoveToEx(hdc, x: 0, y: v9, lppt: nullptr);
          LineTo(hdc, x: h, y: v9);
          if ( --x == 0 )
            break;
          v10 = v31;
        }
        v4 = h;
      }
      v11 = i;
      if ( i != 0 )
      {
        rect.left = v4 - 50;
        rect.right = v4;
        rect.top = y - 20;
        rect.bottom = y;
        v12 = (float)i;
        if ( g_cpuProfile_fpsLabels != 0 )
          sprintf(string: labelBuff, format: "%.2ffps", (float)(60.0 / v12));
        else
          sprintf(string: labelBuff, format: "%.2fms", (float)(v12 * 16.666666));
        DrawTextA(hdc, lpchText: labelBuff, cchText: -1, lprc: &rect, format: 0x2Au);
        v11 = i;
      }
      y -= timingHeight;
      i = v11 + 1;
    }
    while ( v11 + 1 < numTicks );
  }
  if ( g_cpuProfile_numSamples != 0 )
  {
    SelectObject(hdc, h: (HGDIOBJ)j);
    i = g_cpuProfile_numSamples - 1;
    for ( x = v4 - 51; x >= 0; x -= 4 )
    {
      ya = windowHeight;
      j = 0;
      if ( g_cpuProfile_numCounters - 1 > 0 )
      {
        v13 = (COLORREF *)&dword_46BE08;
        numTicks = 0;
        v31 = (int)&dword_46BE08;
        do
        {
          if ( v13 != (COLORREF *)64 )
          {
            v14 = (int)((double)g_cpuProfile_counters[numTicks + i % 512] * 0.000060000002 * (double)timingHeight);
            h = v14;
            if ( v14 != 0 )
            {
              if ( v14 > windowHeight )
                h = windowHeight;
              if ( g_cpuProfile_history_colors )
                v15 = *v13;
              else
                v15 = 5263440;
              SolidBrush = CreateSolidBrush(color: v15);
              v17 = (HBRUSH__ *)v3(hdc, h: SolidBrush);
              v18 = ya - h;
              hBrushOld = v17;
              Rectangle(hdc, left: x - 4, top: ya - h, right: x, bottom: ya + 1);
              ya = v18;
              SelectObject(hdc, h: hBrushOld);
              DeleteObject(ho: SolidBrush);
              v3 = SelectObject;
              v13 = (COLORREF *)v31;
            }
          }
          numTicks += 538;
          v13 += 538;
          ++j;
          v31 = (int)v13;
        }
        while ( j < g_cpuProfile_numCounters - 1 );
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
// Address: 0x00410200
// Name: long CpuProfile_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CpuProfile_WndProc(HWND hwnd, UINT message, HMENU wParam, LONG *lParam)
{
  LONG WindowLongA; // eax
  bool v6; // bl
  int result; // eax
  HDC v8; // eax
  vprofState_e State; // eax
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
        g_cpuProfile_lastPeakTime = 0;
        result = 0;
        break;
      case 2u:
        CpuProfile_SaveConfig();
        if ( v6 )
        {
          g_cpuProfile_hWndSamples = nullptr;
        }
        else if ( bIsHistory_3 )
        {
          g_cpuProfile_hWndHistory = nullptr;
        }
        if ( VProf_GetState() != VPROF_CPU )
          return 0;
        VProf_Enable(state: VPROF_OFF);
        result = 0;
        break;
      case 5u:
        goto LABEL_38;
      case 0xFu:
        GetClientRect(hWnd: hwnd, lpRect: &rect);
        v8 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
        if ( v6 )
        {
          DrawHelper(hdc: v8, clientRect: (HBRUSH__ *)&rect, drawFunc: ProfileSamples_Draw);
        }
        else if ( bIsHistory_3 )
        {
          DrawHelper(hdc: v8, clientRect: (HBRUSH__ *)&rect, drawFunc: ProfileHistory_Draw);
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
    if ( wParam == (HMENU)45 )
    {
$LN11_0:
      if ( WindowLongA == 1 )
      {
        CpuProfile_ZoomIn(scale: &g_cpuProfile_samples_scale, numSteps: 20);
        return 0;
      }
      if ( WindowLongA == 2 )
        CpuProfile_ZoomIn(scale: &g_cpuProfile_history_scale, numSteps: 5);
    }
    else
    {
      if ( wParam != (HMENU)46 )
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
$LN7_3:
      if ( WindowLongA == 1 )
      {
        CpuProfile_ZoomOut(scale: &g_cpuProfile_samples_scale, numSteps: 20);
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
  if ( message != 273 )
  {
    if ( message == 278 )
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
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CDFu, uCheck: g_cpuProfile_samples_averages ? 8 : 0);
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC549u, uCheck: g_cpuProfile_fpsLabels != 0 ? 8 : 0);
      State = VProf_GetState();
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CE4u, uCheck: State != VPROF_CPU ? 0 : 8);
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  if ( (unsigned __int16)wParam > 0xC549u )
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  if ( (unsigned __int16)wParam == 50505 )
  {
    g_cpuProfile_fpsLabels ^= 1u;
    CpuProfile_UpdateWindow();
    return 0;
  }
  else
  {
    switch ( (unsigned __int16)wParam )
    {
      case 0x9CDFu:
        g_cpuProfile_samples_averages ^= 1u;
        CpuProfile_UpdateWindow();
        return 0;
      case 0x9CE0u:
        if ( WindowLongA == 1 )
        {
          g_cpuProfile_samples_tickMarks ^= 1u;
          CpuProfile_UpdateWindow();
          return 0;
        }
        if ( WindowLongA == 2 )
          g_cpuProfile_history_tickMarks ^= 1u;
        goto LABEL_38;
      case 0x9CE1u:
        if ( WindowLongA == 1 )
        {
          g_cpuProfile_samples_colors ^= 1u;
          CpuProfile_UpdateWindow();
          result = 0;
        }
        else
        {
          if ( WindowLongA == 2 )
            g_cpuProfile_history_colors ^= 1u;
LABEL_38:
          CpuProfile_UpdateWindow();
          result = 0;
        }
        break;
      case 0x9CE2u:
        goto $LN11_0;
      case 0x9CE3u:
        goto $LN7_3;
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
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004105F0
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
// Address: 0x004106C0
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
    if ( VProf_GetState() != VPROF_OFF )
      VProf_Enable(state: VPROF_OFF);
    else
      VProf_Enable(state: VPROF_CPU);
    CpuProfile_SetTitle();
  }
  else
  {
    if ( VProf_GetState() == VPROF_OFF )
      VProf_Enable(state: VPROF_CPU);
    g_cpuProfile_hWndSamples = CreateWindowExA(
                                 dwExStyle: 0x200u,
                                 lpClassName: "CPUPROFILESAMPLESCLASS",
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
// Address: 0x004107C0
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
// Address: 0x00410820
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
// Address: 0x00410930
// Name: int rc_SetCpuProfile(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetCpuProfile(char *commandPtr)
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
  g_cpuProfile_numCounters = numProfiles;
  if ( numProfiles > 63 )
  {
    g_cpuProfile_numCounters = 63;
    v4 = 63;
  }
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = pDest;
    p_color = &localList->color;
    do
    {
      *p_color = _byteswap_ulong(*p_color);
      memset(dst: (unsigned __int8 *)v6 - 2080, value: 0, count: 0x868u);
      V_strncpy(pDest: v6, pSrc: (const char *)p_color - 128, maxLen: 64);
      *((_DWORD *)v6 + 16) = *p_color;
      ++v5;
      p_color += 33;
      v6 += 2152;
    }
    while ( v5 < g_cpuProfile_numCounters );
    v4 = g_cpuProfile_numCounters;
  }
  memset(dst: (unsigned __int8 *)&g_cpuProfile_counters[538 * v4], value: 0, count: 0x868u);
  *(_DWORD *)&pDest[2152 * v4] = *(_DWORD *)s2;
  g_cpuProfile_numCounters = v4 + 1;
  word_46BDCC[1076 * v4] = 108;
  dword_46BE08[538 * v5] = 0xFFFFFF;
  xboxRetVal = _byteswap_ulong(v4);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = SetCpuProfile( 0x%8.8x, 0x%8.8x )\n", v4, numProfiles, profileList);
  free(pMem: localList);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410B10
// Name: int rc_SetCpuProfileData(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SetCpuProfileData(char *commandPtr)
{
  char *Token; // eax
  unsigned int SystemTime; // eax
  int v3; // edi
  int v4; // ecx
  unsigned int *v5; // esi
  unsigned int *v6; // edx
  int v7; // eax
  int v8; // ebx
  bool v9; // zf
  double v10; // xmm0_8
  double v11; // st7
  int v12; // ebx
  int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  _DWORD *v19; // esi
  int v20; // edx
  double v21; // st7
  double v22; // xmm0_8
  double v23; // st6
  int v24; // ecx
  int v25; // eax
  unsigned int v26; // eax
  unsigned int localCounters[64]; // [esp+4h] [ebp-140h] BYREF
  double avg; // [esp+104h] [ebp-40h]
  double sum; // [esp+10Ch] [ebp-38h]
  double devSquared; // [esp+114h] [ebp-30h]
  unsigned int v32; // [esp+11Ch] [ebp-28h]
  int currentSample; // [esp+120h] [ebp-24h]
  int i; // [esp+124h] [ebp-20h]
  _DWORD *v35; // [esp+128h] [ebp-1Ch]
  int total; // [esp+12Ch] [ebp-18h]
  int count; // [esp+130h] [ebp-14h]
  unsigned int *v38; // [esp+134h] [ebp-10h]
  int counters; // [esp+138h] [ebp-Ch] BYREF
  int v40; // [esp+13Ch] [ebp-8h]
  bool newPeaks; // [esp+143h] [ebp-1h]

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &counters);
  if ( g_cpuProfile_numCounters != 0 )
    DmGetMemory(a1: counters, a2: 4 * g_cpuProfile_numCounters - 4, a3: localCounters, a4: 0);
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
  v3 = g_cpuProfile_numSamples % 512;
  v4 = 0;
  currentSample = g_cpuProfile_numSamples % 512;
  ++g_cpuProfile_numSamples;
  total = 0;
  i = 0;
  if ( g_cpuProfile_numCounters > 0 )
  {
    v40 = 0;
    v5 = (unsigned int *)&unk_46BDA8;
    v6 = &g_cpuProfile_counters[v3];
    v35 = &unk_46BDA8;
    v38 = v6;
    do
    {
      count = localCounters[v4];
      v7 = _byteswap_ulong(count);
      v8 = g_cpuProfile_numCounters - 1;
      localCounters[v4] = v7;
      if ( v4 == v8 )
        v7 = total;
      else
        total += v7;
      v9 = !newPeaks;
      *v6 = v7;
      if ( !v9 || *v5 < *v6 )
        *v5 = *v6;
      if ( g_cpuProfile_samples_averages )
      {
        v10 = 0.0;
        sum = 0.0;
        v11 = 0.0;
        v12 = 0;
        v13 = 0;
        v14 = -1;
        v15 = 0;
        while ( 1 )
        {
          v16 = g_cpuProfile_numSamples;
          if ( g_cpuProfile_numSamples >= 32 )
            v16 = 32;
          if ( v13 >= v16 )
            break;
          v17 = v3 & 0x800001FF;
          if ( v3 < 0 )
            v17 = (((_WORD)v17 - 1) | 0xFFFFFE00) + 1 + ((int)((((_WORD)v17 - 1) | 0xFFFFFE00) + 1) < 0 ? 0x200 : 0);
          count = v12 + 1;
          v18 = g_cpuProfile_counters[v17 + v40];
          v32 = v18;
          ++v12;
          v11 = v11 + (double)v18;
          if ( v18 > v15 )
            v15 = v18;
          sum = v11;
          v10 = v11;
          if ( v18 < v14 )
            v14 = v18;
          ++v13;
          --v3;
        }
        v19 = v35;
        v35[6] = v14;
        v19[7] = v15;
        if ( v12 <= 0 )
        {
          *((_QWORD *)v19 + 1) = 0;
          *((_QWORD *)v19 + 2) = 0;
        }
        else
        {
          v20 = currentSample;
          avg = v10 / (double)v12;
          v21 = avg;
          *((double *)v19 + 1) = avg;
          v22 = 0.0;
          devSquared = 0.0;
          v23 = 0.0;
          v24 = 0;
          while ( 1 )
          {
            v25 = g_cpuProfile_numSamples;
            if ( g_cpuProfile_numSamples >= 32 )
              v25 = 32;
            if ( v24 >= v25 )
              break;
            v26 = v20 & 0x800001FF;
            if ( v20 < 0 )
              v26 = (((_WORD)v26 - 1) | 0xFFFFFE00) + 1 + ((int)((((_WORD)v26 - 1) | 0xFFFFFE00) + 1) < 0 ? 0x200 : 0);
            ++v24;
            --v20;
            v23 = v23
                + ((double)g_cpuProfile_counters[v26 + v40] - v21) * ((double)g_cpuProfile_counters[v26 + v40] - v21);
            devSquared = v23;
            v22 = v23;
          }
          *((double *)v19 + 2) = sqrt(v22 / (double)(v12 - 1));
        }
        v3 = currentSample;
        v4 = i;
        v6 = v38;
      }
      v40 += 538;
      ++v4;
      v6 += 538;
      v5 = v35 + 538;
      i = v4;
      v38 = v6;
      v35 += 538;
    }
    while ( v4 < g_cpuProfile_numCounters );
  }
  DebugCommand(pStrFormat: "SetCpuProfileData( 0x%8.8x )\n", counters);
  if ( g_cpuProfile_hWndSamples != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndSamples) )
    InvalidateRect(hWnd: g_cpuProfile_hWndSamples, lpRect: nullptr, bErase: true);
  if ( g_cpuProfile_hWndHistory != nullptr && !IsIconic(hWnd: g_cpuProfile_hWndHistory) )
    InvalidateRect(hWnd: g_cpuProfile_hWndHistory, lpRect: nullptr, bErase: true);
  return 0;
}
