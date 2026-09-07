// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_memdump.cpp
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418CB0
// Name: char __near * ShowMemDump_FormatSize(int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ShowMemDump_FormatSize(int size, char *pBuff, bool bUnits)
{
  char *v3; // esi

  if ( g_showMemDump_showBytes != 0 )
  {
    if ( g_showMemDump_showBytes == 1 )
    {
      v3 = pBuff;
      sprintf(string: pBuff, format: "%.2f", (float)((float)size * 0.0009765625));
      if ( !bUnits )
        return v3;
      strcat(pBuff, " K");
      return pBuff;
    }
    else
    {
      if ( g_showMemDump_showBytes == 2 )
      {
        v3 = pBuff;
        sprintf(string: pBuff, format: "%.2f", (float)((float)size * 0.00000095367432));
        if ( bUnits )
          strcat(pBuff, " MB");
        return v3;
      }
      return pBuff;
    }
  }
  else
  {
    sprintf(string: pBuff, format: "%d", size);
    return pBuff;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418D90
// Name: void ShowMemDump_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showMemDumpSortColumn", value: g_showMemDump_sortColumn);
  Sys_SetRegistryInteger(keyName: "showMemDumpSortDescending", value: g_showMemDump_sortDescending);
  Sys_SetRegistryInteger(keyName: "showMemDumpShowBytes", value: g_showMemDump_showBytes);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showMemDump_hWnd, lpwndpl: &wp);
  g_showMemDump_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showMemDumpWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x00418E50
// Name: void ShowMemDump_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showMemDumpSortColumn", defValue: 0, value: &g_showMemDump_sortColumn);
  Sys_GetRegistryInteger(keyName: "showMemDumpSortDescending", defValue: 0, value: &g_showMemDump_sortDescending);
  Sys_GetRegistryInteger(keyName: "showMemDumpShowBytes", defValue: 1, value: &g_showMemDump_showBytes);
  Sys_GetRegistryString(keyName: "showMemDumpWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showMemDump_windowRect,
         &g_showMemDump_windowRect.top,
         &g_showMemDump_windowRect.right,
         &g_showMemDump_windowRect.bottom) != 4
    || g_showMemDump_windowRect.left < 0
    || g_showMemDump_windowRect.top < 0
    || g_showMemDump_windowRect.right < 0
    || g_showMemDump_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showMemDump_windowRect.left = 0;
    *(_QWORD *)&g_showMemDump_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418F10
// Name: void ShowMemDump_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Clear()
{
  int v0; // edi
  int v1; // esi

  if ( g_showMemDump_hWnd != nullptr )
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showMemDump_pMemory != nullptr )
  {
    v0 = 0;
    if ( g_showMemDump_numMemory > 0 )
    {
      v1 = 0;
      do
      {
        free(pMem: g_showMemDump_pMemory[v1].detail.pAllocationName);
        ++v0;
        ++v1;
      }
      while ( v0 < g_showMemDump_numMemory );
    }
    Sys_Free(ptr: g_showMemDump_pMemory);
    g_showMemDump_pMemory = nullptr;
    g_showMemDump_numMemory = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418FA0
// Name: void ShowMemDump_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Export()
{
  int v0; // edi
  _iobuf *v1; // eax
  _iobuf *v2; // esi
  int i; // ebx
  int currentSize; // ecx
  int peakSize; // ecx
  int totalSize; // ecx
  int overheadSize; // ecx
  int peakOverheadSize; // ecx
  char logFilename[260]; // [esp+14h] [ebp-19Ch] BYREF
  tagOFNA ofn; // [esp+118h] [ebp-98h] BYREF
  char buff[64]; // [esp+170h] [ebp-40h] BYREF

  if ( g_showMemDump_format == 1 )
  {
    v0 = 0;
    memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
    ofn.lStructSize = 88;
    ofn.hwndOwner = g_showMemDump_hWnd;
    ofn.lpstrFile = logFilename;
    logFilename[0] = 0;
    ofn.nMaxFile = 260;
    ofn.lpstrFilter = "Excel CSV";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = "c:\\";
    ofn.Flags = 2048;
    if ( GetOpenFileNameA(a1: &ofn) )
    {
      Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 0x104u, bForce: false);
      v1 = fopen(file: logFilename, mode: "wt+");
      v2 = v1;
      if ( v1 != nullptr )
      {
        fprintf(str: v1, format: "Allocation Type");
        fprintf(str: v2, format: ",Current Size");
        fprintf(str: v2, format: ",Peak Size");
        fprintf(str: v2, format: ",Total Allocations");
        fprintf(str: v2, format: ",Overhead Size");
        fprintf(str: v2, format: ",Peak Overhead Size");
        fprintf(str: v2, format: ",Time(ms)");
        fprintf(str: v2, format: ",Current Count");
        fprintf(str: v2, format: ",Peak Count");
        fprintf(str: v2, format: ",Total Count");
        fprintf(str: v2, format: ",<=16 Byte Allocations");
        fprintf(str: v2, format: ",17-32 Byte Allocations");
        fprintf(str: v2, format: ",33-128 Byte Allocations");
        fprintf(str: v2, format: ",129-1024 Byte Allocations");
        fprintf(str: v2, format: ",>1024 Byte Allocations");
        fprintf(str: v2, format: "\n");
        for ( i = 0; i < g_showMemDump_numMemory; ++v0 )
        {
          fprintf(str: v2, format: "\"%s\"", g_showMemDump_pMemory[v0].detail.pAllocationName);
          currentSize = g_showMemDump_pMemory[v0].detail.currentSize;
          if ( g_showMemDump_showBytes != 0 )
          {
            if ( g_showMemDump_showBytes == 1 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)currentSize * 0.0009765625));
            }
            else if ( g_showMemDump_showBytes == 2 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)currentSize * 0.00000095367432));
            }
          }
          else
          {
            sprintf(string: buff, format: "%d", currentSize);
          }
          fprintf(str: v2, format: ",%s", buff);
          peakSize = g_showMemDump_pMemory[v0].detail.peakSize;
          if ( g_showMemDump_showBytes != 0 )
          {
            if ( g_showMemDump_showBytes == 1 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)peakSize * 0.0009765625));
            }
            else if ( g_showMemDump_showBytes == 2 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)peakSize * 0.00000095367432));
            }
          }
          else
          {
            sprintf(string: buff, format: "%d", peakSize);
          }
          fprintf(str: v2, format: ",%s", buff);
          totalSize = g_showMemDump_pMemory[v0].detail.totalSize;
          if ( g_showMemDump_showBytes != 0 )
          {
            if ( g_showMemDump_showBytes == 1 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)totalSize * 0.0009765625));
            }
            else if ( g_showMemDump_showBytes == 2 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)totalSize * 0.00000095367432));
            }
          }
          else
          {
            sprintf(string: buff, format: "%d", totalSize);
          }
          fprintf(str: v2, format: ",%s", buff);
          overheadSize = g_showMemDump_pMemory[v0].detail.overheadSize;
          if ( g_showMemDump_showBytes != 0 )
          {
            if ( g_showMemDump_showBytes == 1 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)overheadSize * 0.0009765625));
            }
            else if ( g_showMemDump_showBytes == 2 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)overheadSize * 0.00000095367432));
            }
          }
          else
          {
            sprintf(string: buff, format: "%d", overheadSize);
          }
          fprintf(str: v2, format: ",%s", buff);
          peakOverheadSize = g_showMemDump_pMemory[v0].detail.peakOverheadSize;
          if ( g_showMemDump_showBytes != 0 )
          {
            if ( g_showMemDump_showBytes == 1 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)peakOverheadSize * 0.0009765625));
            }
            else if ( g_showMemDump_showBytes == 2 )
            {
              sprintf(string: buff, format: "%.2f", (float)((float)peakOverheadSize * 0.00000095367432));
            }
          }
          else
          {
            sprintf(string: buff, format: "%d", peakOverheadSize);
          }
          fprintf(str: v2, format: ",%s", buff);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.time);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.currentCount);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.peakCount);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.totalCount);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.lte16);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.lte32);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.lte128);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.lte1024);
          fprintf(str: v2, format: ",%d", g_showMemDump_pMemory[v0].detail.gt1024);
          fprintf(str: v2, format: "\n");
          ++i;
        }
        fclose(stream: v2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419560
// Name: void ShowMemDump_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Summary()
{
  int v0; // esi
  int v1; // edi
  int v2; // ebx
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int *p_size; // eax
  int v7; // ecx
  int v8; // ecx
  memory_t *v9; // edi
  int size; // ebx
  int allocated; // ecx
  int v12; // ecx
  int v13; // ebx
  memory_t *v14; // eax
  bool v15; // zf
  int v16; // edx
  int v17; // edx
  char buff[1024]; // [esp+50h] [ebp-434h] BYREF
  int currentCount; // [esp+450h] [ebp-34h]
  int totalCount; // [esp+454h] [ebp-30h]
  int time; // [esp+458h] [ebp-2Ch]
  int peakCount; // [esp+45Ch] [ebp-28h]
  int freeSize; // [esp+460h] [ebp-24h]
  int allocSize; // [esp+464h] [ebp-20h]
  int committedSize; // [esp+468h] [ebp-1Ch]
  int totalSize; // [esp+46Ch] [ebp-18h]
  int lte128; // [esp+470h] [ebp-14h]
  int i; // [esp+474h] [ebp-10h]
  int lte1024; // [esp+478h] [ebp-Ch]
  int lte32; // [esp+47Ch] [ebp-8h]
  int gt1024; // [esp+480h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  if ( g_showMemDump_format == 1 )
  {
    v12 = g_showMemDump_numMemory;
    v13 = 0;
    totalSize = 0;
    allocSize = 0;
    committedSize = 0;
    time = 0;
    currentCount = 0;
    peakCount = 0;
    totalCount = 0;
    i = 0;
    lte32 = 0;
    lte128 = 0;
    lte1024 = 0;
    gt1024 = 0;
    freeSize = 0;
    if ( g_showMemDump_numMemory > 0 )
    {
      v14 = g_showMemDump_pMemory;
      do
      {
        v15 = V_strncasecmp(s1: *(const char **)((char *)&v14->detail.pAllocationName + v0), s2: "Totals,", n: 7) == 0;
        v14 = g_showMemDump_pMemory;
        if ( !v15 )
        {
          totalSize += *(_DWORD *)&g_showMemDump_pMemory->detail.peakSizeBuff[v0 + 32];
          allocSize += *(_DWORD *)&g_showMemDump_pMemory->detail.totalSizeBuff[v0 + 32];
          committedSize += *(_DWORD *)&g_showMemDump_pMemory->detail.overheadSizeBuff[v0 + 32];
          time += *(_DWORD *)&g_showMemDump_pMemory->detail.peakOverheadSizeBuff[v0 + 32];
          currentCount += *(_DWORD *)&g_showMemDump_pMemory->detail.timeBuff[v0 + 32];
          peakCount += *(_DWORD *)&g_showMemDump_pMemory->detail.currentCountBuff[v0 + 32];
          totalCount += *(_DWORD *)&g_showMemDump_pMemory->detail.peakCountBuff[v0 + 32];
          i += *(_DWORD *)&g_showMemDump_pMemory->detail.totalCountBuff[v0 + 32];
          v16 = *(_DWORD *)&g_showMemDump_pMemory->detail.lte32Buff[v0 + 32];
          lte32 += *(_DWORD *)&g_showMemDump_pMemory->detail.lte16Buff[v0 + 32];
          lte128 += v16;
          v17 = *(_DWORD *)&g_showMemDump_pMemory->detail.lte1024Buff[v0 + 32];
          v1 += *(int *)((char *)&g_showMemDump_pMemory->detail.currentSize + v0);
          v13 += *(_DWORD *)&g_showMemDump_pMemory->detail.currentSizeBuff[v0 + 32];
          lte1024 += *(_DWORD *)&g_showMemDump_pMemory->detail.lte128Buff[v0 + 32];
          gt1024 += v17;
        }
        v12 = g_showMemDump_numMemory;
        v0 += 728;
        ++freeSize;
      }
      while ( freeSize < g_showMemDump_numMemory );
    }
    sprintf(
      string: buff,
      format: "Entries:\t\t\t%d\n"
      "Current Size:\t\t%.2f MB\n"
      "Peak Size:\t\t%.2f MB\n"
      "Total Size:\t\t%.2f MB\n"
      "Overhead Size:\t\t%d\n"
      "Peak Overhead Size:\t%d\n"
      "Time:\t\t\t%d\n"
      "Current Count:\t\t%d\n"
      "Peak Count:\t\t%d\n"
      "Total Count:\t\t%d\n"
      "<= 16:\t\t\t%d\n"
      "17-32:\t\t\t%d\n"
      "33-128:\t\t\t%d\n"
      "129-1024:\t\t%d\n"
      "> 1024:\t\t\t%d\n",
      v12,
      (float)((float)v1 * 0.00000095367432),
      (float)((float)v13 * 0.00000095367432),
      (float)((float)totalSize * 0.00000095367432),
      allocSize,
      committedSize,
      time,
      currentCount,
      peakCount,
      totalCount,
      i,
      lte32,
      lte128,
      lte1024,
      gt1024);
    MessageBoxA(hWnd: g_showMemDump_hWnd, lpText: buff, lpCaption: "Memory Dump Summary", uType: 0);
  }
  else
  {
    v2 = g_showMemDump_numMemory;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    lte128 = 0;
    lte32 = 0;
    gt1024 = 0;
    lte1024 = 0;
    freeSize = 0;
    i = 0;
    if ( g_showMemDump_numMemory >= 2 )
    {
      p_size = &g_showMemDump_pMemory[1].pool.size;
      totalSize = ((unsigned int)(g_showMemDump_numMemory - 2) >> 1) + 1;
      i = 2 * totalSize;
      do
      {
        v7 = *(p_size - 182);
        gt1024 += v7 * *(p_size - 164);
        lte128 += v7 * *(p_size - 173);
        v8 = *p_size;
        v4 += *(p_size - 146);
        lte1024 += *p_size * p_size[18];
        v0 += p_size[36];
        lte32 += v8 * p_size[9];
        p_size += 364;
        --totalSize;
      }
      while ( totalSize != 0 );
      v3 = freeSize;
      v2 = g_showMemDump_numMemory;
      v5 = freeSize;
      v1 = freeSize;
    }
    if ( i < v2 )
    {
      v9 = &g_showMemDump_pMemory[i];
      size = v9->pool.size;
      allocated = v9->pool.allocated;
      v3 = size * v9->pool.free;
      v1 = v9->pool.committedSize;
      v5 = size * allocated;
    }
    sprintf(
      string: buff,
      format: "Total Free:\t\t%.2f MB\nTotal Allocated:\t\t%.2f MB\nTotal Committed:\t\t%.2f MB\n",
      (float)((float)(v3 + gt1024 + lte1024) * 0.00000095367432),
      (float)((float)(v5 + lte128 + lte32) * 0.00000095367432),
      (float)((float)(v1 + v4 + v0) * 0.00000095367432));
    MessageBoxA(hWnd: g_showMemDump_hWnd, lpText: buff, lpCaption: "Memory Dump Summary", uType: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419880
// Name: int ShowMemDump_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowMemDump_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax

  result = 0;
  if ( g_showMemDump_format != 0 )
  {
    switch ( g_showMemDump_sortColumn )
    {
      case 0:
        result = _V_stricmp(s1: *(const char **)(lParam1 + 220), s2: *(const char **)(lParam2 + 220));
        break;
      case 1:
        result = *(_DWORD *)(lParam1 + 224) - *(_DWORD *)(lParam2 + 224);
        break;
      case 2:
        result = *(_DWORD *)(lParam1 + 260) - *(_DWORD *)(lParam2 + 260);
        break;
      case 3:
        result = *(_DWORD *)(lParam1 + 296) - *(_DWORD *)(lParam2 + 296);
        break;
      case 4:
        result = *(_DWORD *)(lParam1 + 332) - *(_DWORD *)(lParam2 + 332);
        break;
      case 5:
        result = *(_DWORD *)(lParam1 + 368) - *(_DWORD *)(lParam2 + 368);
        break;
      case 6:
        result = *(_DWORD *)(lParam1 + 404) - *(_DWORD *)(lParam2 + 404);
        break;
      case 7:
        result = *(_DWORD *)(lParam1 + 440) - *(_DWORD *)(lParam2 + 440);
        break;
      case 8:
        result = *(_DWORD *)(lParam1 + 476) - *(_DWORD *)(lParam2 + 476);
        break;
      case 9:
        result = *(_DWORD *)(lParam1 + 512) - *(_DWORD *)(lParam2 + 512);
        break;
      case 10:
        result = *(_DWORD *)(lParam1 + 548) - *(_DWORD *)(lParam2 + 548);
        break;
      case 11:
        result = *(_DWORD *)(lParam1 + 584) - *(_DWORD *)(lParam2 + 584);
        break;
      case 12:
        result = *(_DWORD *)(lParam1 + 620) - *(_DWORD *)(lParam2 + 620);
        break;
      case 13:
        result = *(_DWORD *)(lParam1 + 656) - *(_DWORD *)(lParam2 + 656);
        break;
      case 14:
        result = *(_DWORD *)(lParam1 + 692) - *(_DWORD *)(lParam2 + 692);
        break;
      default:
        break;
    }
  }
  else
  {
    switch ( g_showMemDump_sortColumn )
    {
      case 0:
        result = *(_DWORD *)(lParam1 + 4) - *(_DWORD *)(lParam2 + 4);
        break;
      case 1:
        result = *(_DWORD *)(lParam1 + 40) - *(_DWORD *)(lParam2 + 40);
        break;
      case 2:
        result = *(_DWORD *)(lParam1 + 76) - *(_DWORD *)(lParam2 + 76);
        break;
      case 3:
        result = *(_DWORD *)(lParam1 + 112) - *(_DWORD *)(lParam2 + 112);
        break;
      case 4:
        result = *(_DWORD *)(lParam1 + 148) - *(_DWORD *)(lParam2 + 148);
        break;
      case 5:
        result = *(_DWORD *)(lParam1 + 184) - *(_DWORD *)(lParam2 + 184);
        break;
      default:
        break;
    }
  }
  if ( g_showMemDump_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419AE0
// Name: void ShowMemDump_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  label_t *v2; // esi
  signed int v3; // edi
  char *v4; // esi
  char v5; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int count; // [esp+68h] [ebp-4h]

  if ( g_showMemDump_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowMemDump_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    if ( g_showMemDump_format != 0 )
    {
      count = 15;
      v2 = g_showMemDump_DetailLabels;
    }
    else
    {
      count = 6;
      v2 = g_showMemDump_PoolLabels;
    }
    v3 = 0;
    v4 = (char *)&v2[1];
    do
    {
      if ( v3 == g_showMemDump_sortColumn )
        v5 = 2 * (g_showMemDump_sortDescending == 0) + 60;
      else
        v5 = 32;
      sprintf(string: v4, format: "%s %c", *((const char **)v4 - 3), v5);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v4;
      SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x101Au, wParam: v3++, lParam: (LPARAM)&lvc);
      v4 += 76;
    }
    while ( v3 < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C00
// Name: void ShowMemDump_FormatItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_FormatItems()
{
  int v0; // ebx
  int committedSize; // ecx
  char *committedSizeBuff; // esi
  char *currentSizeBuff; // esi
  int currentSize; // eax
  char *peakSizeBuff; // esi
  int peakSize; // eax
  char *totalSizeBuff; // esi
  int totalSize; // eax
  char *overheadSizeBuff; // esi
  int overheadSize; // eax
  char *peakOverheadSizeBuff; // esi
  int peakOverheadSize; // eax
  int i; // [esp+14h] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( g_showMemDump_format != 0 )
  {
    if ( g_showMemDump_numMemory > 0 )
    {
      do
      {
        currentSizeBuff = g_showMemDump_pMemory[v0].detail.currentSizeBuff;
        currentSize = g_showMemDump_pMemory[v0].detail.currentSize;
        if ( g_showMemDump_showBytes != 0 )
        {
          if ( g_showMemDump_showBytes == 1 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.currentSizeBuff,
              format: "%.2f",
              (float)((float)currentSize * 0.0009765625));
            strcat(currentSizeBuff, " K");
          }
          else if ( g_showMemDump_showBytes == 2 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.currentSizeBuff,
              format: "%.2f",
              (float)((float)currentSize * 0.00000095367432));
            strcat(currentSizeBuff, " MB");
          }
        }
        else
        {
          sprintf(string: g_showMemDump_pMemory[v0].detail.currentSizeBuff, format: "%d", currentSize);
        }
        peakSizeBuff = g_showMemDump_pMemory[v0].detail.peakSizeBuff;
        peakSize = g_showMemDump_pMemory[v0].detail.peakSize;
        if ( g_showMemDump_showBytes != 0 )
        {
          if ( g_showMemDump_showBytes == 1 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.peakSizeBuff,
              format: "%.2f",
              (float)((float)peakSize * 0.0009765625));
            strcat(peakSizeBuff, " K");
          }
          else if ( g_showMemDump_showBytes == 2 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.peakSizeBuff,
              format: "%.2f",
              (float)((float)peakSize * 0.00000095367432));
            strcat(peakSizeBuff, " MB");
          }
        }
        else
        {
          sprintf(string: g_showMemDump_pMemory[v0].detail.peakSizeBuff, format: "%d", peakSize);
        }
        totalSizeBuff = g_showMemDump_pMemory[v0].detail.totalSizeBuff;
        totalSize = g_showMemDump_pMemory[v0].detail.totalSize;
        if ( g_showMemDump_showBytes != 0 )
        {
          if ( g_showMemDump_showBytes == 1 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.totalSizeBuff,
              format: "%.2f",
              (float)((float)totalSize * 0.0009765625));
            strcat(totalSizeBuff, " K");
          }
          else if ( g_showMemDump_showBytes == 2 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.totalSizeBuff,
              format: "%.2f",
              (float)((float)totalSize * 0.00000095367432));
            strcat(totalSizeBuff, " MB");
          }
        }
        else
        {
          sprintf(string: g_showMemDump_pMemory[v0].detail.totalSizeBuff, format: "%d", totalSize);
        }
        overheadSizeBuff = g_showMemDump_pMemory[v0].detail.overheadSizeBuff;
        overheadSize = g_showMemDump_pMemory[v0].detail.overheadSize;
        if ( g_showMemDump_showBytes != 0 )
        {
          if ( g_showMemDump_showBytes == 1 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.overheadSizeBuff,
              format: "%.2f",
              (float)((float)overheadSize * 0.0009765625));
            strcat(overheadSizeBuff, " K");
          }
          else if ( g_showMemDump_showBytes == 2 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.overheadSizeBuff,
              format: "%.2f",
              (float)((float)overheadSize * 0.00000095367432));
            strcat(overheadSizeBuff, " MB");
          }
        }
        else
        {
          sprintf(string: g_showMemDump_pMemory[v0].detail.overheadSizeBuff, format: "%d", overheadSize);
        }
        peakOverheadSizeBuff = g_showMemDump_pMemory[v0].detail.peakOverheadSizeBuff;
        peakOverheadSize = g_showMemDump_pMemory[v0].detail.peakOverheadSize;
        if ( g_showMemDump_showBytes != 0 )
        {
          if ( g_showMemDump_showBytes == 1 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.peakOverheadSizeBuff,
              format: "%.2f",
              (float)((float)peakOverheadSize * 0.0009765625));
            strcat(peakOverheadSizeBuff, " K");
          }
          else if ( g_showMemDump_showBytes == 2 )
          {
            sprintf(
              string: g_showMemDump_pMemory[v0].detail.peakOverheadSizeBuff,
              format: "%.2f",
              (float)((float)peakOverheadSize * 0.00000095367432));
            strcat(peakOverheadSizeBuff, " MB");
          }
        }
        else
        {
          sprintf(string: g_showMemDump_pMemory[v0].detail.peakOverheadSizeBuff, format: "%d", peakOverheadSize);
        }
        ++v0;
        ++i;
      }
      while ( i < g_showMemDump_numMemory );
    }
  }
  else if ( g_showMemDump_numMemory > 0 )
  {
    do
    {
      sprintf(string: g_showMemDump_pMemory[v0].pool.sizeBuff, format: "%d", g_showMemDump_pMemory[v0].pool.size);
      committedSize = g_showMemDump_pMemory[v0].pool.committedSize;
      committedSizeBuff = g_showMemDump_pMemory[v0].pool.committedSizeBuff;
      if ( g_showMemDump_showBytes != 0 )
      {
        if ( g_showMemDump_showBytes == 1 )
        {
          sprintf(
            string: g_showMemDump_pMemory[v0].pool.committedSizeBuff,
            format: "%.2f",
            (float)((float)committedSize * 0.0009765625));
          strcat(committedSizeBuff, " K");
        }
        else if ( g_showMemDump_showBytes == 2 )
        {
          sprintf(
            string: g_showMemDump_pMemory[v0].pool.committedSizeBuff,
            format: "%.2f",
            (float)((float)committedSize * 0.00000095367432));
          strcat(committedSizeBuff, " MB");
        }
      }
      else
      {
        sprintf(string: g_showMemDump_pMemory[v0].pool.committedSizeBuff, format: "%d", committedSize);
      }
      ++v0;
      ++i;
    }
    while ( i < g_showMemDump_numMemory );
  }
  ShowMemDump_SortItems();
}

//------------------------------------------------------------------------------
// Address: 0x0041A120
// Name: void ShowMemDump_AddViewItem(struct memory_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_AddViewItem(memory_t *pMemory)
{
  LRESULT v1; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showMemDump_hWnd != nullptr )
  {
    if ( g_showMemDump_format != 0 )
    {
      ShowMemDump_FormatSize(size: pMemory->detail.currentSize, pBuff: pMemory->detail.currentSizeBuff, bUnits: true);
      ShowMemDump_FormatSize(size: pMemory->detail.peakSize, pBuff: pMemory->detail.peakSizeBuff, bUnits: true);
      ShowMemDump_FormatSize(size: pMemory->detail.totalSize, pBuff: pMemory->detail.totalSizeBuff, bUnits: true);
      ShowMemDump_FormatSize(size: pMemory->detail.overheadSize, pBuff: pMemory->detail.overheadSizeBuff, bUnits: true);
      ShowMemDump_FormatSize(
        size: pMemory->detail.peakOverheadSize,
        pBuff: pMemory->detail.peakOverheadSizeBuff,
        bUnits: true);
      sprintf(string: pMemory->detail.timeBuff, format: "%d", pMemory->detail.time);
      sprintf(string: pMemory->detail.currentCountBuff, format: "%d", pMemory->detail.currentCount);
      sprintf(string: pMemory->detail.peakCountBuff, format: "%d", pMemory->detail.peakCount);
      sprintf(string: pMemory->detail.totalCountBuff, format: "%d", pMemory->detail.totalCount);
      sprintf(string: pMemory->detail.lte16Buff, format: "%d", pMemory->detail.lte16);
      sprintf(string: pMemory->detail.lte32Buff, format: "%d", pMemory->detail.lte32);
      sprintf(string: pMemory->detail.lte128Buff, format: "%d", pMemory->detail.lte128);
      sprintf(string: pMemory->detail.lte1024Buff, format: "%d", pMemory->detail.lte1024);
      sprintf(string: pMemory->detail.gt1024Buff, format: "%d", pMemory->detail.gt1024);
    }
    else
    {
      sprintf(string: pMemory->pool.sizeBuff, format: "%d", pMemory->pool.size);
      sprintf(string: pMemory->pool.poolBuff, format: "%d", pMemory->pool.pool);
      sprintf(string: pMemory->pool.allocatedBuff, format: "%d", pMemory->pool.allocated);
      sprintf(string: pMemory->pool.freeBuff, format: "%d", pMemory->pool.free);
      sprintf(string: pMemory->pool.committedBuff, format: "%d", pMemory->pool.committed);
      ShowMemDump_FormatSize(size: pMemory->pool.committedSize, pBuff: pMemory->pool.committedSizeBuff, bUnits: true);
    }
    v1 = SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    lvi.mask = 13;
    lvi.iItem = v1;
    memset(&lvi.iSubItem, 0, 12);
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pMemory;
    pMemory->listIndex = SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A370
// Name: void ShowMemDump_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Refresh()
{
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: "mem_dump");
}

//------------------------------------------------------------------------------
// Address: 0x0041A390
// Name: void ShowMemDump_PopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_PopulateList()
{
  int v0; // ebx
  label_t *v1; // edi
  signed int i; // esi
  char *name; // eax
  int v4; // edi
  int v5; // esi
  tagLVCOLUMNA lvc; // [esp+0h] [ebp-2Ch] BYREF

  while ( SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x101Cu, wParam: 0, lParam: 0) != 0 )
    ;
  if ( g_showMemDump_format != 0 )
  {
    v0 = 15;
    v1 = g_showMemDump_DetailLabels;
  }
  else
  {
    v0 = 6;
    v1 = g_showMemDump_PoolLabels;
  }
  for ( i = 0; i < v0; ++i )
  {
    memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
    lvc.cx = v1->width;
    lvc.iSubItem = 0;
    lvc.fmt = 0;
    name = (char *)v1->name;
    lvc.mask = 15;
    lvc.pszText = name;
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x101Bu, wParam: i, lParam: (LPARAM)&lvc);
    v1 = (label_t *)((char *)v1 + 76);
  }
  v4 = 0;
  if ( g_showMemDump_numMemory > 0 )
  {
    v5 = 0;
    do
    {
      ShowMemDump_AddViewItem(pMemory: &g_showMemDump_pMemory[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < g_showMemDump_numMemory );
  }
  ShowMemDump_SortItems();
}

//------------------------------------------------------------------------------
// Address: 0x0041A460
// Name: void ShowMemDump_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_SizeWindow(HWND__ *hwnd, int cx, int cy)
{
  int right; // ecx
  int bottom; // eax
  tagRECT rcClient; // [esp+0h] [ebp-10h] BYREF

  right = cx;
  if ( cx == 0 || (bottom = cy, cy == 0) )
  {
    GetClientRect(hWnd: hwnd, lpRect: &rcClient);
    right = rcClient.right;
    bottom = rcClient.bottom;
  }
  SetWindowPos(
    hWnd: g_showMemDump_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0041A4B0
// Name: void ShowMemDump_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Open()
{
  HWND v0; // edx
  tagRECT clientRect; // [esp+0h] [ebp-10h] BYREF

  if ( g_showMemDump_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showMemDump_hWnd) )
      ShowWindow(hWnd: g_showMemDump_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showMemDump_hWnd);
  }
  else
  {
    g_showMemDump_hWnd = CreateWindowExA(
                           dwExStyle: 0x200u,
                           lpClassName: "SHOWMEMDUMPCLASS",
                           lpWindowName: &defValue,
                           dwStyle: 0x80CF0000,
                           X: 0,
                           Y: 0,
                           nWidth: 700,
                           nHeight: 400,
                           hWndParent: g_hDlgMain,
                           hMenu: nullptr,
                           hInstance: g_hInstance,
                           lpParam: nullptr);
    GetClientRect(hWnd: g_showMemDump_hWnd, lpRect: &clientRect);
    g_showMemDump_hWndListView = CreateWindowExA(
                                   dwExStyle: 0,
                                   lpClassName: "SysListView32",
                                   lpWindowName: &defValue,
                                   dwStyle: 0x50000001u,
                                   X: 0,
                                   Y: 0,
                                   nWidth: clientRect.right - clientRect.left,
                                   nHeight: clientRect.bottom - clientRect.top,
                                   hWndParent: g_showMemDump_hWnd,
                                   hMenu: (HMENU)0x64,
                                   hInstance: g_hInstance,
                                   lpParam: nullptr);
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showMemDump_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    ShowMemDump_PopulateList();
    v0 = g_showMemDump_hWnd;
    if ( g_showMemDump_hWnd != nullptr )
    {
      SetWindowTextA(hWnd: g_showMemDump_hWnd, lpString: "Memory Dump");
      v0 = g_showMemDump_hWnd;
    }
    if ( g_showMemDump_windowRect.right != 0 && g_showMemDump_windowRect.bottom != 0 )
    {
      MoveWindow(
        hWnd: v0,
        X: g_showMemDump_windowRect.left,
        Y: g_showMemDump_windowRect.top,
        nWidth: g_showMemDump_windowRect.right - g_showMemDump_windowRect.left,
        nHeight: g_showMemDump_windowRect.bottom - g_showMemDump_windowRect.top,
        bRepaint: false);
      v0 = g_showMemDump_hWnd;
    }
    ShowWindow(hWnd: v0, nCmdShow: 1);
    if ( g_connectedToApp )
      ProcessCommand(strCmdIn: "mem_dump");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A640
// Name: void MatchAllocationName(struct memory_t __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatchAllocationName(memory_t **pMemory)
{
  memory_t *v1; // esi
  int v2; // edi

  v1 = g_showMemDump_pMemory;
  v2 = 0;
  if ( g_showMemDump_numMemory > 0 )
  {
    while ( strcmp(v1->detail.pAllocationName, (*pMemory)->detail.pAllocationName) != 0 )
    {
      ++v2;
      ++v1;
      if ( v2 >= g_showMemDump_numMemory )
        return;
    }
    *pMemory = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A6D0
// Name: void ShowMemDump_Parse(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_Parse(memory_t *pBuffer, int fileSize)
{
  int v2; // edi
  char *Token; // eax
  memory_t *v4; // esi
  int v5; // ebx
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  char *v9; // eax
  const char *v10; // eax
  char *v11; // eax
  const char *v12; // eax
  char *v13; // eax
  const char *v14; // eax
  char *v15; // eax
  const char *v16; // eax
  char *v17; // eax
  const char *v18; // eax
  unsigned __int8 *v19; // ebx
  char *i; // edi
  char *v21; // eax
  unsigned int v22; // edi
  unsigned __int8 *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  char *v27; // eax
  char *v28; // eax
  char *v29; // eax
  char *v30; // eax
  char *v31; // eax
  char *v32; // eax
  char *v33; // eax
  char *v34; // eax
  char *v35; // eax
  char *v36; // eax
  char *v37; // eax
  memory_t *pCurRecordStart; // [esp+4h] [ebp-8h]
  int numLines; // [esp+8h] [ebp-4h]

  ShowMemDump_Clear();
  if ( pBuffer != nullptr && fileSize != 0 )
  {
    Sys_SetScriptData(data: (const char *)pBuffer, length: fileSize);
    Sys_SkipRestOfLine();
    Sys_SaveParser();
    v2 = 0;
    numLines = 0;
    Token = Sys_GetToken(crossline: true);
    if ( Token != nullptr )
    {
      do
      {
        if ( *Token == 0 )
          break;
        ++v2;
        Sys_SkipRestOfLine();
        Token = Sys_GetToken(crossline: true);
      }
      while ( Token != nullptr );
      numLines = v2;
    }
    g_showMemDump_pMemory = (memory_t *)Sys_Alloc(size: 728 * v2);
    Sys_RestoreParser();
    v4 = g_showMemDump_pMemory;
    pBuffer = g_showMemDump_pMemory;
    if ( V_strnicmp(s1: g_sys_scriptptr, s2: "pool ", n: 5) != 0 )
    {
      v19 = (unsigned __int8 *)g_sys_scriptptr;
      for ( i = V_stristr(pStr: g_sys_scriptptr, pSearch: ", line ");
            i != nullptr;
            i = V_stristr(pStr: g_sys_scriptptr, pSearch: ", line ") )
      {
        g_sys_scriptptr = i + 7;
        v21 = Sys_GetToken(crossline: false);
        if ( v21 == nullptr || *v21 == 0 )
          break;
        if ( !g_showMemDump_bCollapseOutput )
          i = g_sys_scriptptr;
        v22 = i - (char *)v19;
        memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(memory_t));
        pCurRecordStart = v4;
        v23 = (unsigned __int8 *)operator new(nSize: v22 + 1);
        v4->detail.pAllocationName = (char *)v23;
        memcpy(dst: v23, src: v19, count: v22);
        v4->detail.pAllocationName[v22] = 0;
        Sys_NormalizePath(path: v4->detail.pAllocationName, forceToLower: false);
        if ( g_showMemDump_bCollapseOutput )
        {
          MatchAllocationName(pMemory: &pBuffer);
          v4 = pBuffer;
        }
        v24 = Sys_GetToken(crossline: false);
        if ( v24 == nullptr )
          break;
        if ( *v24 == 0 )
          break;
        v4->detail.currentSize += (int)(atof(nptr: v24) * 1024.0);
        v25 = Sys_GetToken(crossline: false);
        if ( v25 == nullptr )
          break;
        if ( *v25 == 0 )
          break;
        v4->detail.peakSize += (int)(atof(nptr: v25) * 1024.0);
        v26 = Sys_GetToken(crossline: false);
        if ( v26 == nullptr )
          break;
        if ( *v26 == 0 )
          break;
        v4->detail.totalSize += (int)(atof(nptr: v26) * 1024.0);
        v27 = Sys_GetToken(crossline: false);
        if ( v27 == nullptr )
          break;
        if ( *v27 == 0 )
          break;
        v4->detail.overheadSize += (int)(atof(nptr: v27) * 1024.0);
        v28 = Sys_GetToken(crossline: false);
        if ( v28 == nullptr )
          break;
        if ( *v28 == 0 )
          break;
        v4->detail.peakOverheadSize += (int)(atof(nptr: v28) * 1024.0);
        v29 = Sys_GetToken(crossline: false);
        if ( v29 == nullptr )
          break;
        if ( *v29 == 0 )
          break;
        v4->detail.time += atoi(nptr: v29);
        v30 = Sys_GetToken(crossline: false);
        if ( v30 == nullptr )
          break;
        if ( *v30 == 0 )
          break;
        v4->detail.currentCount += atoi(nptr: v30);
        v31 = Sys_GetToken(crossline: false);
        if ( v31 == nullptr )
          break;
        if ( *v31 == 0 )
          break;
        v4->detail.peakCount += atoi(nptr: v31);
        v32 = Sys_GetToken(crossline: false);
        if ( v32 == nullptr )
          break;
        if ( *v32 == 0 )
          break;
        v4->detail.totalCount += atoi(nptr: v32);
        v33 = Sys_GetToken(crossline: false);
        if ( v33 == nullptr )
          break;
        if ( *v33 == 0 )
          break;
        v4->detail.lte16 += atoi(nptr: v33);
        v34 = Sys_GetToken(crossline: false);
        if ( v34 == nullptr )
          break;
        if ( *v34 == 0 )
          break;
        v4->detail.lte32 += atoi(nptr: v34);
        v35 = Sys_GetToken(crossline: false);
        if ( v35 == nullptr )
          break;
        if ( *v35 == 0 )
          break;
        v4->detail.lte128 += atoi(nptr: v35);
        v36 = Sys_GetToken(crossline: false);
        if ( v36 == nullptr )
          break;
        if ( *v36 == 0 )
          break;
        v4->detail.lte1024 += atoi(nptr: v36);
        v37 = Sys_GetToken(crossline: false);
        if ( v37 == nullptr || *v37 == 0 )
          break;
        v4->detail.gt1024 += atoi(nptr: v37);
        Sys_SkipRestOfLine();
        if ( v4 == pCurRecordStart )
        {
          ++v4;
          ++g_showMemDump_numMemory;
        }
        else
        {
          v4 = pCurRecordStart;
        }
        pBuffer = v4;
        if ( g_showMemDump_numMemory >= numLines )
          break;
        v19 = (unsigned __int8 *)g_sys_scriptptr;
      }
      v5 = 1;
    }
    else
    {
      v5 = 0;
LABEL_9:
      memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(memory_t));
      v6 = Sys_GetToken(crossline: true);
      if ( v6 != nullptr )
      {
        while ( *v6 != 0 )
        {
          if ( _V_stricmp(s1: v6, s2: "pool") == 0 )
          {
            v7 = Sys_GetToken(crossline: false);
            if ( v7 != nullptr && *v7 != 0 )
            {
              v8 = atoi(nptr: v7);
              if ( v8 == g_showMemDump_numMemory )
              {
                v4->pool.pool = v8;
                v9 = Sys_GetToken(crossline: false);
                if ( v9 != nullptr && *v9 != 0 && _V_stricmp(s1: v9, s2: "size:") == 0 )
                {
                  v10 = Sys_GetToken(crossline: false);
                  if ( v10 != nullptr && *v10 != 0 )
                  {
                    v4->pool.size = atoi(nptr: v10);
                    v11 = Sys_GetToken(crossline: false);
                    if ( v11 != nullptr && *v11 != 0 && _V_stricmp(s1: v11, s2: "allocated:") == 0 )
                    {
                      v12 = Sys_GetToken(crossline: false);
                      if ( v12 != nullptr && *v12 != 0 )
                      {
                        v4->pool.allocated = atoi(nptr: v12);
                        v13 = Sys_GetToken(crossline: false);
                        if ( v13 != nullptr && *v13 != 0 && _V_stricmp(s1: v13, s2: "free:") == 0 )
                        {
                          v14 = Sys_GetToken(crossline: false);
                          if ( v14 != nullptr && *v14 != 0 )
                          {
                            v4->pool.free = atoi(nptr: v14);
                            v15 = Sys_GetToken(crossline: false);
                            if ( v15 != nullptr && *v15 != 0 && _V_stricmp(s1: v15, s2: "committed:") == 0 )
                            {
                              v16 = Sys_GetToken(crossline: false);
                              if ( v16 != nullptr && *v16 != 0 )
                              {
                                v4->pool.committed = atoi(nptr: v16);
                                v17 = Sys_GetToken(crossline: false);
                                if ( v17 != nullptr && *v17 != 0 && _V_stricmp(s1: v17, s2: "committedsize:") == 0 )
                                {
                                  v18 = Sys_GetToken(crossline: false);
                                  if ( v18 != nullptr && *v18 != 0 )
                                  {
                                    v4->pool.committedSize = atoi(nptr: v18);
                                    ++v4;
                                    if ( ++g_showMemDump_numMemory < v2 )
                                      goto LABEL_9;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            break;
          }
          v6 = Sys_GetToken(crossline: true);
          if ( v6 == nullptr )
            break;
        }
      }
    }
    if ( g_showMemDump_format != v5 )
    {
      g_showMemDump_format = v5;
      g_showMemDump_sortColumn = 0;
      g_showMemDump_sortDescending = 0;
    }
    ShowMemDump_PopulateList();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AD30
// Name: int rc_MemDump(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_MemDump(char *pCommand)
{
  char *Token; // eax
  char *v2; // edx
  char v3; // cl
  unsigned __int8 v4; // al
  int fileSize; // [esp+4h] [ebp-8h] BYREF
  char *pBuffer; // [esp+8h] [ebp-4h] BYREF

  Token = GetToken(ppTokenStream: &pCommand);
  if ( *Token == 0 )
    return -1;
  v2 = (char *)(g_showMemDump_currentFilename - Token);
  do
  {
    v3 = *Token;
    Token[(_DWORD)v2] = *Token;
    ++Token;
  }
  while ( v3 != 0 );
  v4 = LoadTargetFile(pTargetPath: g_showMemDump_currentFilename, pFileSize: &fileSize, pData: (void **)&pBuffer);
  DebugCommand(pStrFormat: "0x%8.8x = MemDump( %s )\n", v4, g_showMemDump_currentFilename);
  ShowMemDump_Parse((memory_t *)pBuffer, fileSize);
  Sys_Free(ptr: pBuffer);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041ADB0
// Name: void ShowMemDump_RefreshView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMemDump_RefreshView()
{
  int fileSize; // [esp+0h] [ebp-8h] BYREF
  char *pBuffer; // [esp+4h] [ebp-4h] BYREF

  if ( strlen(g_showMemDump_currentFilename) != 0
    && LoadTargetFile(pTargetPath: g_showMemDump_currentFilename, pFileSize: &fileSize, pData: (void **)&pBuffer) != 0 )
  {
    ShowMemDump_Parse((memory_t *)pBuffer, fileSize);
    Sys_Free(ptr: pBuffer);
  }
  else if ( g_connectedToApp )
  {
    ProcessCommand(strCmdIn: "mem_dump");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AE20
// Name: long ShowMemDump_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowMemDump_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC55Fu, uCheck: g_showMemDump_showBytes != 0 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC562u, uCheck: g_showMemDump_showBytes != 1 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC563u, uCheck: g_showMemDump_showBytes != 2 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC565u, uCheck: g_showMemDump_bCollapseOutput ? 8 : 0);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam <= 0xC55Fu )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0xC55Fu:
          g_showMemDump_showBytes = 0;
          ShowMemDump_FormatItems();
          return 0;
        case 0x9CC7u:
          ShowMemDump_Summary();
          return 0;
        case 0x9CC8u:
          ShowMemDump_Refresh();
          return 0;
        case 0x9CC9u:
          ShowMemDump_Export();
          return 0;
        default:
          break;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    switch ( (unsigned __int16)wParam )
    {
      case 0xC562u:
        g_showMemDump_showBytes = 1;
        ShowMemDump_FormatItems();
        return 0;
      case 0xC563u:
        g_showMemDump_showBytes = 2;
        ShowMemDump_FormatItems();
        return 0;
      case 0xC565u:
        g_showMemDump_bCollapseOutput = !g_showMemDump_bCollapseOutput;
        ShowMemDump_RefreshView();
        return 0;
      default:
        break;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        ShowMemDump_SaveConfig();
        g_showMemDump_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowMemDump_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 != -150 )
  {
    if ( v5 == -108 )
    {
      if ( g_showMemDump_sortColumn == *(_DWORD *)(lParam + 16) )
        g_showMemDump_sortDescending ^= 1u;
      else
        g_showMemDump_sortColumn = *(_DWORD *)(lParam + 16);
      ShowMemDump_SortItems();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  v6 = *(_DWORD *)(lParam + 44);
  v7 = *(_DWORD *)(lParam + 20);
  if ( g_showMemDump_format != 0 )
  {
    switch ( v7 )
    {
      case 0:
        *(_DWORD *)(lParam + 32) = *(_DWORD *)(v6 + 220);
        result = 0;
        break;
      case 1:
        *(_DWORD *)(lParam + 32) = v6 + 228;
        result = 0;
        break;
      case 2:
        *(_DWORD *)(lParam + 32) = v6 + 264;
        result = 0;
        break;
      case 3:
        *(_DWORD *)(lParam + 32) = v6 + 300;
        result = 0;
        break;
      case 4:
        *(_DWORD *)(lParam + 32) = v6 + 336;
        result = 0;
        break;
      case 5:
        *(_DWORD *)(lParam + 32) = v6 + 372;
        result = 0;
        break;
      case 6:
        *(_DWORD *)(lParam + 32) = v6 + 408;
        result = 0;
        break;
      case 7:
        *(_DWORD *)(lParam + 32) = v6 + 444;
        result = 0;
        break;
      case 8:
        *(_DWORD *)(lParam + 32) = v6 + 480;
        result = 0;
        break;
      case 9:
        *(_DWORD *)(lParam + 32) = v6 + 516;
        result = 0;
        break;
      case 10:
        *(_DWORD *)(lParam + 32) = v6 + 552;
        result = 0;
        break;
      case 11:
        *(_DWORD *)(lParam + 32) = v6 + 588;
        result = 0;
        break;
      case 12:
        *(_DWORD *)(lParam + 32) = v6 + 624;
        result = 0;
        break;
      case 13:
        *(_DWORD *)(lParam + 32) = v6 + 660;
        result = 0;
        break;
      case 14:
        *(_DWORD *)(lParam + 32) = v6 + 696;
        result = 0;
        break;
      default:
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
  }
  else
  {
    switch ( v7 )
    {
      case 0:
        *(_DWORD *)(lParam + 32) = v6 + 8;
        result = 0;
        break;
      case 1:
        *(_DWORD *)(lParam + 32) = v6 + 44;
        result = 0;
        break;
      case 2:
        *(_DWORD *)(lParam + 32) = v6 + 80;
        result = 0;
        break;
      case 3:
        *(_DWORD *)(lParam + 32) = v6 + 116;
        result = 0;
        break;
      case 4:
        *(_DWORD *)(lParam + 32) = v6 + 152;
        result = 0;
        break;
      case 5:
        *(_DWORD *)(lParam + 32) = v6 + 188;
        result = 0;
        break;
      default:
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B1E0
// Name: bool ShowMemDump_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowMemDump_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowMemDump_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)127;
  wndclass.hCursor = (HICON__ *)"SHOWMEMDUMPCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowMemDump_LoadConfig();
  return 1;
}
