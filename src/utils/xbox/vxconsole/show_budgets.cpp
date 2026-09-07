// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_budgets.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00415CF0
// Name: enum ItemGroup GetTextureGroup(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ItemGroup __cdecl GetTextureGroup(const char *pGroupName, const char *pLongName)
{
  ItemGroup result; // eax

  if ( _V_stricmp(s1: pGroupName, s2: "World Textures") != 0 && _V_stricmp(s1: pGroupName, s2: "Model Textures") != 0 )
  {
    result = _V_stricmp(s1: pGroupName, s2: "Lightmaps");
    if ( result != IG_LightMap )
    {
      if ( _V_stricmp(s1: pGroupName, s2: "CubeMap Textures") != 0
        && _V_stricmp(s1: pGroupName, s2: "Decal Textures") != 0
        && _V_stricmp(s1: pGroupName, s2: "SkyBox Textures") != 0 )
      {
        return IG_None;
      }
      else
      {
        return IG_World;
      }
    }
  }
  else if ( V_stristr(pStr: pLongName, pSearch: "models/player") != nullptr )
  {
    return IG_Character;
  }
  else if ( V_stristr(pStr: pLongName, pSearch: "models/weapons") != nullptr
         || V_stristr(pStr: pLongName, pSearch: "models/v_models") != nullptr
         || V_stristr(pStr: pLongName, pSearch: "models/w_models") != nullptr )
  {
    return IG_Weapon;
  }
  else
  {
    return 2 - (V_stristr(pStr: pLongName, pSearch: "models/") != nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415DF0
// Name: void ShowBudget_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowBudget_SizeWindow(HWND__ *hwnd, int cx, int cy)
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
    hWnd: g_showBudgets_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00415E40
// Name: void ShowBudget_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowBudget_Open()
{
  HWND v0; // edx
  char String[128]; // [esp+4h] [ebp-90h] BYREF
  tagRECT clientRect; // [esp+84h] [ebp-10h] BYREF

  g_budgetInfo.BSPSize = 0;
  if ( g_showBudgets_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showBudgets_hWnd) )
      ShowWindow(hWnd: g_showBudgets_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showBudgets_hWnd);
  }
  else
  {
    g_showBudgets_hWnd = CreateWindowExA(
                           dwExStyle: 0x200u,
                           lpClassName: "SHOWBUDGETCLASS",
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
    GetClientRect(hWnd: g_showBudgets_hWnd, lpRect: &clientRect);
    g_showBudgets_hWndListView = CreateWindowExA(
                                   dwExStyle: 0,
                                   lpClassName: "SysListView32",
                                   lpWindowName: &defValue,
                                   dwStyle: 0x50000005u,
                                   X: 0,
                                   Y: 0,
                                   nWidth: clientRect.right - clientRect.left,
                                   nHeight: clientRect.bottom - clientRect.top,
                                   hWndParent: g_showBudgets_hWnd,
                                   hMenu: (HMENU)0x64,
                                   hInstance: g_hInstance,
                                   lpParam: nullptr);
    SendMessageA(hWnd: g_showBudgets_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showBudgets_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showBudgets_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showBudgets_hWndListView, Msg: 0x1036u, wParam: 0x71u, lParam: 113);
    v0 = g_showBudgets_hWnd;
    if ( g_showBudgets_hWnd != nullptr )
    {
      strcpy(String, "Budgets");
      SetWindowTextA(hWnd: g_showBudgets_hWnd, lpString: String);
      v0 = g_showBudgets_hWnd;
    }
    if ( g_showBudgets_windowRect.right != 0 && g_showBudgets_windowRect.bottom != 0 )
    {
      MoveWindow(
        hWnd: v0,
        X: g_showBudgets_windowRect.left,
        Y: g_showBudgets_windowRect.top,
        nWidth: g_showBudgets_windowRect.right - g_showBudgets_windowRect.left,
        nHeight: g_showBudgets_windowRect.bottom - g_showBudgets_windowRect.top,
        bRepaint: false);
      v0 = g_showBudgets_hWnd;
    }
    ShowWindow(hWnd: v0, nCmdShow: 1);
    g_bspAquired = 0;
    g_texturesAquired = 0;
    g_modelsAquired = 0;
    g_cachedModelsAquired = 0;
    budgetSummaryShowing = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415FF0
// Name: int rc_ShowBudget(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_ShowBudget(char *commandPtr)
{
  const char *Token; // eax
  const char *v2; // eax
  int retAddr; // [esp+4h] [ebp-Ch] BYREF
  int xboxRetVal; // [esp+8h] [ebp-8h] BYREF
  int infoAddr; // [esp+Ch] [ebp-4h] BYREF

  g_budgetInfo.BSPSize = 0;
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%x", &infoAddr);
    v2 = GetToken(ppTokenStream: &commandPtr);
    if ( *v2 != 0 )
    {
      sscanf(string: v2, format: "%x", &retAddr);
      DmGetMemory(a1: infoAddr, a2: 4, a3: &g_budgetInfo, a4: 0);
      g_budgetInfo.BSPSize = _byteswap_ulong(g_budgetInfo.BSPSize);
      xboxRetVal = 0;
      DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
      DebugCommand(pStrFormat: "0x%8.8x = BudgetInfo( 0x%8.8x )\n", 0, infoAddr);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004160A0
// Name: void UpdateBudgetDisplayString(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateBudgetDisplayString()
{
  int v0; // esi
  int v1; // edi
  texture_t *v2; // ecx
  ItemGroup TextureGroup; // eax
  int v4; // ebx
  CacheEntry_t *m_pMemory; // ecx
  const char *v6; // eax
  const char *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  model_t *v11; // ecx
  int v12; // edi
  const char *pName; // esi
  int v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // eax
  int charTextures; // [esp+6Ch] [ebp-24h]
  int weaponTextures; // [esp+70h] [ebp-20h]
  int charModels; // [esp+74h] [ebp-1Ch]
  int weaponModels; // [esp+78h] [ebp-18h]
  int charAnimation; // [esp+7Ch] [ebp-14h]
  int mapModelTextures; // [esp+80h] [ebp-10h]
  int mapWorldTextures; // [esp+84h] [ebp-Ch]
  int lightMaps; // [esp+88h] [ebp-8h]
  int mapModels; // [esp+8Ch] [ebp-4h]

  v0 = 0;
  v1 = 0;
  charTextures = 0;
  weaponTextures = 0;
  mapModelTextures = 0;
  mapWorldTextures = 0;
  lightMaps = 0;
  if ( g_showTextures_numTextures > 0 )
  {
    v2 = g_showTextures_pTextures;
    do
    {
      TextureGroup = GetTextureGroup(
                       pGroupName: *(const char **)((char *)&v2->pGroupName + v0),
                       pLongName: *(const char **)((char *)&v2->pLongName + v0));
      v2 = g_showTextures_pTextures;
      switch ( TextureGroup )
      {
        case IG_LightMap:
          lightMaps += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v0 + 16];
          break;
        case IG_WorldModel:
          mapModelTextures += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v0 + 16];
          break;
        case IG_World:
          mapWorldTextures += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v0 + 16];
          break;
        case IG_Character:
          charTextures += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v0 + 16];
          break;
        case IG_Weapon:
          weaponTextures += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v0 + 16];
          break;
        default:
          break;
      }
      ++v1;
      v0 += 200;
    }
    while ( v1 < g_showTextures_numTextures );
    v0 = 0;
  }
  v4 = 0;
  charModels = 0;
  weaponModels = 0;
  charAnimation = 0;
  mapModels = 0;
  if ( g_showDataCache_Contents.m_Size > 0 )
  {
    m_pMemory = g_showDataCache_Contents.m_Memory.m_pMemory;
    do
    {
      v6 = CUtlString::operator char const *(this: (CUtlString *)((char *)&m_pMemory->name + v0));
      m_pMemory = g_showDataCache_Contents.m_Memory.m_pMemory;
      v7 = v6;
      if ( *(int *)&g_showDataCache_Contents.m_Memory.m_pMemory->lruOrderBuff[v0 + 16] < 0x40000 )
      {
        v8 = 5;
      }
      else if ( V_stristr(pStr: v6, pSearch: "models/weapons") != nullptr
             || V_stristr(pStr: v7, pSearch: "models/player") != nullptr )
      {
        m_pMemory = g_showDataCache_Contents.m_Memory.m_pMemory;
        v8 = 3;
      }
      else
      {
        m_pMemory = g_showDataCache_Contents.m_Memory.m_pMemory;
        v8 = 1;
      }
      v9 = v8 - 1;
      if ( v9 != 0 )
      {
        if ( v9 == 2 )
          charAnimation += *(_DWORD *)&m_pMemory->lruOrderBuff[v0 + 16];
      }
      else
      {
        mapModels += *(_DWORD *)&m_pMemory->lruOrderBuff[v0 + 16];
      }
      ++v4;
      v0 += 156;
    }
    while ( v4 < g_showDataCache_Contents.m_Size );
  }
  v10 = 0;
  if ( g_showModels_numModels > 0 )
  {
    v11 = g_showModels_pModels;
    v12 = 0;
    do
    {
      pName = v11[v12].pName;
      if ( V_stristr(pStr: pName, pSearch: "models/player") != nullptr )
      {
        v14 = 3;
      }
      else if ( V_stristr(pStr: pName, pSearch: "models/shells") != nullptr
             || V_stristr(pStr: pName, pSearch: "models/weapons") != nullptr
             || V_stristr(pStr: pName, pSearch: "models/w_models") != nullptr
             || (v15 = V_stristr(pStr: pName, pSearch: "models/v_models") == nullptr, v14 = 1, !v15) )
      {
        v14 = 4;
      }
      v16 = v14 - 1;
      v11 = g_showModels_pModels;
      if ( v16 != 0 )
      {
        v17 = v16 - 2;
        if ( v17 != 0 )
        {
          if ( v17 == 1 )
            weaponModels += g_showModels_pModels[v12].dataSize;
        }
        else
        {
          charModels += g_showModels_pModels[v12].dataSize;
        }
      }
      else
      {
        mapModels += g_showModels_pModels[v12].dataSize;
      }
      ++v10;
      ++v12;
    }
    while ( v10 < g_showModels_numModels );
  }
  V_snprintf(
    pDest: g_OutputBuff,
    maxLen: 4096,
    pFormat: "CHARACTER MEMORY (MB)\n"
    "  Character Textures, %3.2f\n"
    "  Weapon Textures, %3.2f\n"
    "  Character Models, %3.2f\n"
    "  Weapon Models, %3.2f\n"
    "  Animation, %3.2f\n"
    "  Character Total, %3.2f\n"
    "\n"
    "MAP MEMORY (MB)\n"
    "  Light Maps, %3.2f\n"
    "  World Textures, %3.2f\n"
    "  Model Textures, %3.2f\n"
    "  Models, %3.2f\n"
    "  BSP, %3.2f\n"
    "  Map Total, %3.2f\n"
    "\n",
    (float)((float)charTextures * 0.00000095367432),
    (float)((float)weaponTextures * 0.00000095367432),
    (float)((float)charModels * 0.00000095367432),
    (float)((float)weaponModels * 0.00000095367432),
    (float)((float)charAnimation * 0.00000095367432),
    (float)((float)(charTextures + weaponTextures + charModels + charAnimation + weaponModels) * 0.00000095367432),
    (float)((float)lightMaps * 0.00000095367432),
    (float)((float)mapWorldTextures * 0.00000095367432),
    (float)((float)mapModelTextures * 0.00000095367432),
    (float)((float)mapModels * 0.00000095367432),
    (float)((float)g_budgetInfo.BSPSize * 0.00000095367432),
    (float)((float)(mapModelTextures + mapWorldTextures + lightMaps + g_budgetInfo.BSPSize + mapModels)
          * 0.00000095367432));
}

//------------------------------------------------------------------------------
// Address: 0x00416400
// Name: void ShowBudget_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowBudget_Export()
{
  int v0; // edi
  _iobuf *v1; // eax
  _iobuf *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  char *pName; // esi
  int v10; // eax
  bool v11; // zf
  int m_Size; // eax
  int j; // ebx
  int v14; // edi
  const char *v15; // eax
  const char *v16; // esi
  int v17; // eax
  CacheEntry_t *v18; // esi
  const char *v19; // eax
  char logFilename[260]; // [esp+4h] [ebp-164h] BYREF
  tagOFNA ofn; // [esp+108h] [ebp-60h] BYREF
  _iobuf *fp; // [esp+160h] [ebp-8h]
  int i; // [esp+164h] [ebp-4h]

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_showBudgets_hWnd;
  ofn.lpstrFile = logFilename;
  logFilename[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "Excel CSV";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = "c:\\";
  ofn.Flags = 2048;
  if ( GetSaveFileNameA(a1: &ofn) )
  {
    Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 0x104u, bForce: false);
    v1 = fopen(file: logFilename, mode: "wt+");
    v2 = v1;
    fp = v1;
    if ( v1 != nullptr )
    {
      fprintf(str: v1, format: "SUMMARY\n\n");
      fprintf(str: v2, format: "%s", g_OutputBuff);
      fprintf(str: v2, format: "\n\nDETAILS\n\n");
      fprintf(str: v2, format: "Name,Group,Size,Width,Height,Format\n");
      fprintf(str: v2, format: "TEXTURES\n");
      v3 = g_showTextures_numTextures;
      do
      {
        v4 = 0;
        if ( v3 > 0 )
        {
          v5 = 0;
          do
          {
            if ( v0 == GetTextureGroup(
                         pGroupName: g_showTextures_pTextures[v5].pGroupName,
                         pLongName: g_showTextures_pTextures[v5].pLongName) )
              fprintf(
                str: fp,
                format: "\"%s\",\"%s\",\"%d\",\"%d\",\"%d\",\"%s\"\n",
                g_showTextures_pTextures[v5].pLongName,
                g_groupNames[v0],
                g_showTextures_pTextures[v5].size,
                g_showTextures_pTextures[v5].width,
                g_showTextures_pTextures[v5].height,
                g_showTextures_pTextures[v5].pFormatName);
            v3 = g_showTextures_numTextures;
            ++v4;
            ++v5;
          }
          while ( v4 < g_showTextures_numTextures );
          v2 = fp;
        }
        ++v0;
      }
      while ( v0 < 6 );
      fprintf(str: v2, format: "\n");
      fprintf(str: v2, format: "MODELS\n");
      v6 = g_showModels_numModels;
      for ( i = 0; i < 6; ++i )
      {
        v7 = 0;
        if ( v6 > 0 )
        {
          v8 = 0;
          do
          {
            pName = g_showModels_pModels[v8].pName;
            if ( V_stristr(pStr: pName, pSearch: "models/player") != nullptr )
            {
              v10 = 3;
            }
            else if ( V_stristr(pStr: pName, pSearch: "models/shells") != nullptr
                   || V_stristr(pStr: pName, pSearch: "models/weapons") != nullptr
                   || V_stristr(pStr: pName, pSearch: "models/w_models") != nullptr
                   || (v11 = V_stristr(pStr: pName, pSearch: "models/v_models") == nullptr, v10 = 1, !v11) )
            {
              v10 = 4;
            }
            if ( i == v10 )
              fprintf(
                str: fp,
                format: "\"%s\",\"%s\",\"%d\", , , \n",
                g_showModels_pModels[v8].pName,
                g_groupNames[i],
                g_showModels_pModels[v8].dataSize);
            v6 = g_showModels_numModels;
            ++v7;
            ++v8;
          }
          while ( v7 < g_showModels_numModels );
          v2 = fp;
        }
      }
      fprintf(str: v2, format: "\n");
      fprintf(str: v2, format: "DATA CACHE\n");
      m_Size = g_showDataCache_Contents.m_Size;
      for ( j = 0; j < 6; ++j )
      {
        v14 = 0;
        i = 0;
        if ( m_Size > 0 )
        {
          do
          {
            v15 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v14].name);
            v16 = v15;
            if ( g_showDataCache_Contents.m_Memory.m_pMemory[v14].size < 0x40000 )
            {
              v17 = 5;
            }
            else if ( V_stristr(pStr: v15, pSearch: "models/weapons") != nullptr
                   || V_stristr(pStr: v16, pSearch: "models/player") != nullptr )
            {
              v17 = 3;
            }
            else
            {
              v17 = 1;
            }
            if ( j == v17 )
            {
              v18 = &g_showDataCache_Contents.m_Memory.m_pMemory[v14];
              v19 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v14].name);
              fprintf(str: fp, format: "\"%s\",\"%s\",\"%d\", , , \n", v19, g_groupNames[j], v18->size);
            }
            m_Size = g_showDataCache_Contents.m_Size;
            ++v14;
            ++i;
          }
          while ( i < g_showDataCache_Contents.m_Size );
          v2 = fp;
        }
      }
      fclose(stream: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416770
// Name: void ShowBudget_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowBudget_Summary()
{
  UpdateBudgetDisplayString();
  MessageBoxA(hWnd: g_hwndOutputWindow, lpText: g_OutputBuff, lpCaption: "Budget Summary", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00416790
// Name: long ShowBudget_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
UINT __stdcall ShowBudget_WndProc(HWND__ *hwnd, UINT message, WPARAM wParam, unsigned int lParam)
{
  UINT result; // eax
  int v5; // eax

  if ( g_connectedToApp )
  {
    if ( g_bspAquired == 2 )
    {
      if ( g_texturesAquired == 2 )
      {
        if ( g_modelsAquired == 2 )
        {
          if ( g_cachedModelsAquired == 2 )
          {
            if ( !budgetSummaryShowing )
            {
              budgetSummaryShowing = true;
              ShowBudget_Summary();
            }
          }
          else if ( g_cachedModelsAquired == 0 )
          {
            ProcessCommand(strCmdIn: "vx_datacache_list");
            g_cachedModelsAquired = 1;
          }
        }
        else if ( g_modelsAquired == 0 )
        {
          ProcessCommand(strCmdIn: "vx_model_list");
          g_modelsAquired = 1;
        }
      }
      else if ( g_texturesAquired == 0 )
      {
        ProcessCommand(strCmdIn: "mat_get_textures all");
        g_texturesAquired = 1;
      }
    }
    else if ( g_bspAquired == 0 )
    {
      ProcessCommand(strCmdIn: "hunk_print_allocations");
      g_bspAquired = 1;
    }
  }
  if ( message <= 0x4E )
  {
    switch ( message )
    {
      case 0x4Eu:
        v5 = *(_DWORD *)(lParam + 8);
        if ( v5 != -114 )
        {
          if ( v5 == -108 )
            return 0;
          return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
        }
        break;
      case 1u:
        break;
      case 2u:
        g_showBudgets_hWnd = nullptr;
        return 0;
      case 5u:
        ShowBudget_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      default:
        return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
    }
    return 0;
  }
  if ( message == 273 )
  {
    switch ( (unsigned __int16)wParam )
    {
      case 0x9CC7u:
        ShowBudget_Summary();
        return 0;
      case 0x9CC8u:
        g_bspAquired = 0;
        g_texturesAquired = 0;
        g_modelsAquired = 0;
        g_cachedModelsAquired = 0;
        budgetSummaryShowing = false;
        return 0;
      case 0x9CC9u:
        ShowBudget_Export();
        return 0;
      default:
        break;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  result = message - 278;
  if ( message != 278 )
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416940
// Name: bool ShowBudget_Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ShowBudget_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowBudget_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)119;
  wndclass.hCursor = (HICON__ *)"SHOWBUDGETCLASS";
  return RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) != 0;
}
