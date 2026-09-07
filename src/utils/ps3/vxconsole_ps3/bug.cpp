// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/bug.cpp
// Functions: 33
// ============================================================

#include "utils\ps3\vxconsole_ps3\bug.h"

//------------------------------------------------------------------------------
// Address: 0x00401E10
// Name: public: IScreenshotArrivalCallback::IScreenshotArrivalCallback(void)
// Source: json
//------------------------------------------------------------------------------
IScreenshotArrivalCallback *__thiscall IScreenshotArrivalCallback::IScreenshotArrivalCallback(
        IScreenshotArrivalCallback *this)
{
  this->__vftable = (IScreenshotArrivalCallback_vtbl *)&IScreenshotArrivalCallback::`vftable';
  this->m_CreationTime = _Plat_FloatTime();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401E30
// Name: public: bool IScreenshotArrivalCallback::IsStale(double)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IScreenshotArrivalCallback::IsStale(IScreenshotArrivalCallback *this, long double timeout)
{
  return _Plat_FloatTime() - this->m_CreationTime > timeout;
}

//------------------------------------------------------------------------------
// Address: 0x00401E60
// Name: char const __near * GetSubmissionURL(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSubmissionURL(int bugid)
{
  char *result; // eax
  const char *v2; // eax

  result = (char *)g_bug_pReporter->GetSubmissionURL(this: g_bug_pReporter);
  if ( result == nullptr )
  {
    v2 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v2 == nullptr )
      v2 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: url, maxLen: 260, pFormat: "%s/%i", v2, bugid);
    return url;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: class IBugReporter __near * BugReporter_LoadDLL(char const __near *,struct HINSTANCE__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
IBugReporter *__cdecl BugReporter_LoadDLL(const char *pDLLName, HINSTANCE__ **phModule)
{
  HMODULE LibraryA; // eax
  HINSTANCE__ *v3; // edi
  FARPROC CreateInterface; // eax
  int v6; // eax
  int v7; // esi

  *phModule = nullptr;
  LibraryA = LoadLibraryA(lpLibFileName: pDLLName);
  v3 = LibraryA;
  if ( LibraryA == nullptr )
  {
    Sys_MessageBox(title: "Bug Error", format: "Could not open '%s'\n", pDLLName);
    return nullptr;
  }
  CreateInterface = GetProcAddress(hModule: LibraryA, lpProcName: "CreateInterface");
  if ( CreateInterface == nullptr )
  {
    Sys_MessageBox(title: "Bug Error", format: "Missing '%s' interface for '%s'\n", "CreateInterface", pDLLName);
    return nullptr;
  }
  v6 = ((int (__cdecl *)(const char *, _DWORD))CreateInterface)(a1: "BugReporter005", a2: 0);
  v7 = v6;
  if ( v6 == 0 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Missing interface '%s' for '%s'\n", "BugReporter005", pDLLName);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 4))(a1: v6, a2: 0) == 0 )
    return nullptr;
  *phModule = v3;
  return (IBugReporter *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x00401F80
// Name: bool BugReporter_GetInterfaces(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugReporter_GetInterfaces()
{
  IBugReporter *DLL; // eax
  const char *v1; // eax
  _iobuf *v2; // esi
  const char *v3; // eax
  int v5; // [esp-4h] [ebp-108h]
  char fn[260]; // [esp+0h] [ebp-104h] BYREF

  DLL = g_bug_pReporter2;
  if ( g_bug_pReporter2 == nullptr )
  {
    DLL = BugReporter_LoadDLL(pDLLName: "bugreporter_filequeue.dll", phModule: &g_bug_hBugReporter2);
    g_bug_pReporter2 = DLL;
    if ( DLL == nullptr )
    {
      Sys_MessageBox(title: "Bug Error", format: "BugBait intialization failed!\n");
      DLL = g_bug_pReporter2;
    }
  }
  g_bug_pReporter = DLL;
  v1 = DLL->GetRepositoryURL(this: DLL);
  if ( v1 == nullptr )
    v1 = "\\\\fileserver\\bugs";
  V_snprintf(pDest: fn, maxLen: 260, pFormat: "%s/%s", v1, "info.txt");
  Sys_NormalizePath(path: fn, forceToLower: false);
  v2 = fopen(file: fn, mode: "rb");
  if ( v2 != nullptr )
  {
    v3 = (const char *)((int (__thiscall *)(IBugReporter *, int))g_bug_pReporter->GetRepositoryURL)(
                         a1: g_bug_pReporter,
                         a2: v5);
    if ( v3 == nullptr )
      v3 = "\\\\fileserver\\bugs";
    ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: Repository: '%s'\n", v3);
    fclose(stream: v2);
    return 1;
  }
  else
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to see '%s', check permissions and network connectivity.\n", fn);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402080
// Name: void init_destination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_destination(jpeg_common_struct *cinfo)
{
  jpeg_destination_mgr *err; // esi
  int v2; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 4096);
  err[1].free_in_buffer = v2;
  err->next_output_byte = (unsigned __int8 *)v2;
  err->free_in_buffer = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x004020B0
// Name: unsigned char empty_output_buffer(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl empty_output_buffer(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // esi

  dest = cinfo->dest;
  CUtlBuffer::Put(this: (CUtlBuffer *)dest[1].next_output_byte, pMem: (const void *)dest[1].free_in_buffer, size: 4096);
  dest->next_output_byte = (unsigned __int8 *)dest[1].free_in_buffer;
  dest->free_in_buffer = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004020E0
// Name: void term_destination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl term_destination(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax

  dest = cinfo->dest;
  if ( dest->free_in_buffer != 4096 )
    CUtlBuffer::Put(
      this: (CUtlBuffer *)dest[1].next_output_byte,
      pMem: (const void *)dest[1].free_in_buffer,
      size: 4096 - dest->free_in_buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00402110
// Name: void jpeg_UtlBuffer_dest(struct jpeg_compress_struct __near *,class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_UtlBuffer_dest(jpeg_common_struct *cinfo, CUtlBuffer *pBuffer)
{
  jpeg_destination_mgr *err; // eax

  if ( cinfo[1].err == nullptr )
    cinfo[1].err = (jpeg_error_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 28);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  err->init_destination = (void (__cdecl *)(jpeg_compress_struct *))init_destination;
  err->empty_output_buffer = empty_output_buffer;
  err->term_destination = term_destination;
  err[1].next_output_byte = (unsigned __int8 *)pBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x00402150
// Name: void BugDlg_GetAppData(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_GetAppData(HWND__ *hWnd)
{
  HWND DlgItem; // eax
  HWND v2; // eax

  memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1073, lpString: &str);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1074, lpString: &str);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1075, lpString: &str);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1076, lpString: &str);
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1061);
  EnableWindow(hWnd: DlgItem, bEnable: false);
  v2 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1060);
  EnableWindow(hWnd: v2, bEnable: false);
  if ( g_connectionState == kCONNECTEDAPP )
  {
    if ( g_bug_bFirstCommand )
    {
      ProcessCommand(strCmdIn: "vx_mapinfo");
    }
    else
    {
      g_bug_bFirstCommand = true;
      ProcessCommand(strCmdIn: "cmd bugpause ; vx_mapinfo");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402210
// Name: void BugDlg_GetDataFileBase(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_GetDataFileBase(char *suffix, bool bLocalPath, char *buf, int bufsize)
{
  int v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  char filename[260]; // [esp+0h] [ebp-2ACh] BYREF
  char who[128]; // [esp+104h] [ebp-1A8h] BYREF
  char filepath[260]; // [esp+184h] [ebp-128h] BYREF
  tm t; // [esp+288h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &t);
  strncpy(dest: (unsigned __int8 *)who, source: (unsigned __int8 *)suffix, count: 0x80u);
  strlwr(string: who);
  if ( bLocalPath )
  {
    v4 = 0;
    do
    {
      v5 = g_localPath[v4];
      filepath[v4++] = v5;
    }
    while ( v5 != 0 );
    Sys_AddFileSeperator(path: filepath, pathLen: 260);
    v6 = &who[127];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    strcpy(v6, "bug/");
    Sys_NormalizePath(path: filepath, forceToLower: false);
    Sys_CreatePath(pInPath: filepath);
  }
  else
  {
    filepath[0] = 0;
  }
  sprintf(string: filename, format: "%i_%02i_%02i_%s", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, who);
  V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%s%s", filepath, filename);
}

//------------------------------------------------------------------------------
// Address: 0x00402320
// Name: bool BugDlg_CheckSubmit(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BugDlg_CheckSubmit(HWND__ *hWnd)
{
  bool v1; // bl
  HWND DlgItem; // eax

  v1 = false;
  if ( g_bug_szTitle[0] != 0
    && g_bug_szDescription[0] != 0
    && g_bug_szSeverity[0] != 0
    && g_bug_szOwner[0] != 0
    && g_bug_szSubmitter[0] != 0
    && g_bug_szArea[0] != 0
    && g_bug_szMapNumber[0] != 0 )
  {
    v1 = g_bug_szCategory[0] != 0;
  }
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1079);
  EnableWindow(hWnd: DlgItem, bEnable: v1);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00402390
// Name: bool BugDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_GetChanges(HWND__ *hWnd)
{
  LRESULT v1; // eax
  unsigned __int8 *v2; // eax
  LRESULT v3; // eax
  unsigned __int8 *v4; // eax
  LRESULT v5; // eax
  const char *v6; // eax
  LRESULT v7; // eax
  const char *v8; // eax

  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1057, lpString: g_bug_szTitle, cchMax: 512);
  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1058, lpString: g_bug_szDescription, cchMax: 4096);
  v1 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v1 == -1
    || (v2 = (unsigned __int8 *)g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v1),
        strncpy(dest: (unsigned __int8 *)g_bug_szOwner, source: v2, count: 0x80u),
        byte_44705F = 0,
        V_stristr(pStr: g_bug_szOwner, pSearch: "unassigned") != nullptr) )
  {
    g_bug_szOwner[0] = 0;
  }
  v3 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1095, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 == -1 )
  {
    g_bug_szSubmitter[0] = 0;
  }
  else
  {
    v4 = (unsigned __int8 *)g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v3);
    strncpy(dest: (unsigned __int8 *)g_bug_szSubmitter, source: v4, count: 0x80u);
    byte_4470DF = 0;
  }
  v5 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v5 == -1 )
  {
    g_bug_szSeverity[0] = 0;
  }
  else
  {
    v6 = g_bug_pReporter->GetSeverity(this: g_bug_pReporter, a2: v5);
    V_strncpy(pDest: g_bug_szSeverity, pSrc: v6, maxLen: 128);
  }
  v7 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v7 == -1 )
  {
    g_bug_szCategory[0] = 0;
  }
  else
  {
    v8 = g_bug_pReporter->GetReportType(this: g_bug_pReporter, a2: v7);
    V_strncpy(pDest: g_bug_szCategory, pSrc: v8, maxLen: 128);
  }
  g_bug_bCompressScreenshot = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1083) != 0;
  BugDlg_CheckSubmit(hWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402510
// Name: bool BugDlg_OnAreaChanged(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl BugDlg_OnAreaChanged(HWND__ *hWnd)
{
  LRESULT v1; // eax
  const char *v2; // eax
  char szOldArea[260]; // [esp+0h] [ebp-104h] BYREF

  V_strncpy(pDest: szOldArea, pSrc: g_bug_szArea, maxLen: 260);
  v1 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v1 == -1 )
  {
    g_bug_szArea[0] = 0;
  }
  else
  {
    v2 = g_bug_pReporter->GetArea(this: g_bug_pReporter, a2: v1);
    V_strncpy(pDest: g_bug_szArea, pSrc: v2, maxLen: 128);
  }
  return _V_stricmp(s1: g_bug_szArea, s2: szOldArea) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004025A0
// Name: bool BugDlg_OnMapChanged(struct HWND__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BugDlg_OnMapChanged(HWND__ *hWnd)
{
  int v1; // ebx
  LRESULT v2; // eax
  LRESULT v3; // eax
  const char *v5; // eax
  char szOldMap[260]; // [esp+Ch] [ebp-104h] BYREF

  v1 = 0;
  v2 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x14Cu, wParam: 0xFFFFFFFF, lParam: (LPARAM)g_bug_szArea);
  if ( v2 != -1 )
    v1 = v2;
  V_strncpy(pDest: szOldMap, pSrc: g_bug_szMapNumber, maxLen: 260);
  v3 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 == -1 )
  {
    g_bug_szMapNumber[0] = 0;
  }
  else
  {
    v5 = g_bug_pReporter->GetLevel(this: g_bug_pReporter, a2: v1, a3: v3);
    V_strncpy(pDest: g_bug_szMapNumber, pSrc: v5, maxLen: 128);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00402640
// Name: void BugDlg_TakeScreenshot(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_TakeScreenshot(HWND__ *hWnd)
{
  char *v1; // eax
  char buff[1024]; // [esp+8h] [ebp-400h] BYREF

  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: "Working...");
  v1 = (char *)g_bug_pReporter->GetUserNameA_2(this: g_bug_pReporter);
  BugDlg_GetDataFileBase(suffix: v1, bLocalPath: true, buf: g_bug_szScreenshot, bufsize: 260);
  strcat(g_bug_szScreenshot, ".bmp");
  unlink(path: g_bug_szScreenshot);
  sprintf(string: buff, format: "*screenshot \"%s\"", g_bug_szScreenshot);
  if ( !ProcessCommand(strCmdIn: buff) )
    g_bug_szScreenshot[0] = 0;
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: g_bug_szScreenshot);
}

//------------------------------------------------------------------------------
// Address: 0x00402700
// Name: void BugDlg_Populate(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_Populate(HWND__ *hWnd)
{
  int v1; // ebx
  bool v2; // zf
  const char *v3; // eax
  WPARAM v4; // eax
  int v5; // ebx
  bool v6; // zf
  const char *v7; // eax
  WPARAM v8; // eax
  int v9; // ebx
  bool v10; // zf
  const char *v11; // eax
  WPARAM v12; // eax
  int v13; // ebx
  bool v14; // zf
  const char *v15; // eax
  WPARAM v16; // eax
  int v17; // ebx
  bool v18; // zf
  const char *v19; // eax
  WPARAM v20; // eax
  WPARAM v21; // ebx
  HWND DlgItem; // eax
  int v23; // ebx
  bool v24; // zf
  const char *v25; // eax
  HWND v26; // eax
  WPARAM v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  bool v31; // al
  HWND v32; // eax
  BOOL v33; // [esp-4h] [ebp-18h]
  BOOL v34; // [esp-4h] [ebp-18h]
  int areaIndex; // [esp+Ch] [ebp-8h]
  int count; // [esp+10h] [ebp-4h]
  int counta; // [esp+10h] [ebp-4h]
  int countb; // [esp+10h] [ebp-4h]
  int countc; // [esp+10h] [ebp-4h]
  int countd; // [esp+10h] [ebp-4h]
  int counte; // [esp+10h] [ebp-4h]

  g_bug_bActive = false;
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1057, Msg: 0xC5u, wParam: 0x1FFu, lParam: 0);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1057, lpString: g_bug_szTitle);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1058, Msg: 0xC5u, wParam: 0xFFFu, lParam: 0);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1058, lpString: g_bug_szDescription);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v1 = 0;
  count = g_bug_pReporter->GetDisplayNameCount(this: g_bug_pReporter);
  v2 = count == 0;
  if ( count > 0 )
  {
    do
    {
      v3 = g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v1);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v3);
      ++v1;
    }
    while ( v1 < count );
    v2 = count == 0;
  }
  if ( !v2 )
  {
    v4 = SendDlgItemMessageA(
           hDlg: hWnd,
           nIDDlgItem: 1080,
           Msg: 0x158u,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)g_bug_szOwner);
    if ( v4 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1080, Msg: 0x14Eu, wParam: v4, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1095, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v5 = 0;
  counta = g_bug_pReporter->GetDisplayNameCount(this: g_bug_pReporter);
  v6 = counta == 0;
  if ( counta > 0 )
  {
    do
    {
      v7 = g_bug_pReporter->GetDisplayName(this: g_bug_pReporter, a2: v5);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1095, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v7);
      ++v5;
    }
    while ( v5 < counta );
    v6 = counta == 0;
  }
  if ( !v6 )
  {
    v8 = SendDlgItemMessageA(
           hDlg: hWnd,
           nIDDlgItem: 1095,
           Msg: 0x158u,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)g_bug_szSubmitter);
    if ( v8 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1095, Msg: 0x14Eu, wParam: v8, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v9 = 0;
  countb = g_bug_pReporter->GetSeverityCount(this: g_bug_pReporter);
  v10 = countb == 0;
  if ( countb > 0 )
  {
    do
    {
      v11 = g_bug_pReporter->GetSeverity(this: g_bug_pReporter, a2: v9);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v11);
      ++v9;
    }
    while ( v9 < countb );
    v10 = countb == 0;
  }
  if ( !v10 )
  {
    v12 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1065,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szSeverity);
    if ( v12 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1065, Msg: 0x14Eu, wParam: v12, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v13 = 0;
  countc = g_bug_pReporter->GetReportTypeCount(this: g_bug_pReporter);
  v14 = countc == 0;
  if ( countc > 0 )
  {
    do
    {
      v15 = g_bug_pReporter->GetReportType(this: g_bug_pReporter, a2: v13);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v15);
      ++v13;
    }
    while ( v13 < countc );
    v14 = countc == 0;
  }
  if ( !v14 )
  {
    v16 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1096,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szCategory);
    if ( v16 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x14Eu, wParam: v16, lParam: 0);
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x14Bu, wParam: 0, lParam: 0);
  v17 = 0;
  countd = g_bug_pReporter->GetAreaCount(this: g_bug_pReporter);
  areaIndex = 0;
  v18 = countd == 0;
  if ( countd > 0 )
  {
    do
    {
      v19 = g_bug_pReporter->GetArea(this: g_bug_pReporter, a2: v17);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v19);
      ++v17;
    }
    while ( v17 < countd );
    v18 = countd == 0;
  }
  if ( !v18 )
  {
    v20 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1068,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szArea);
    v21 = v20;
    if ( v20 != -1 )
    {
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1068, Msg: 0x14Eu, wParam: v20, lParam: 0);
      areaIndex = v21;
    }
  }
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x14Bu, wParam: 0, lParam: 0);
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1078);
  EnableWindow(hWnd: DlgItem, bEnable: false);
  v23 = 0;
  counte = g_bug_pReporter->GetLevelCount(this: g_bug_pReporter, a2: areaIndex);
  v24 = counte == 0;
  if ( counte > 0 )
  {
    do
    {
      v25 = g_bug_pReporter->GetLevel(this: g_bug_pReporter, a2: areaIndex, a3: v23);
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v25);
      ++v23;
    }
    while ( v23 < counte );
    v24 = counte == 0;
  }
  if ( !v24 )
  {
    v26 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1078);
    EnableWindow(hWnd: v26, bEnable: true);
    v27 = SendDlgItemMessageA(
            hDlg: hWnd,
            nIDDlgItem: 1078,
            Msg: 0x158u,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)g_bug_szMapNumber);
    if ( v27 != -1 )
      SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1078, Msg: 0x14Eu, wParam: v27, lParam: 0);
  }
  CheckDlgButton(hDlg: hWnd, nIDButton: 1083, uCheck: g_bug_bCompressScreenshot);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1069, lpString: g_bug_szScreenshot);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1070, lpString: g_bug_szSavegame);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1071, lpString: g_bug_szBSPName);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1072, lpString: &str);
  v28 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1063);
  EnableWindow(hWnd: v28, bEnable: true);
  v29 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1062);
  EnableWindow(hWnd: v29, bEnable: false);
  v33 = g_connectionState == kCONNECTEDAPP;
  v30 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1059);
  EnableWindow(hWnd: v30, bEnable: v33);
  if ( g_connectionState == kCONNECTEDAPP )
    BugDlg_TakeScreenshot(hWnd);
  BugDlg_GetAppData(hWnd);
  v31 = false;
  if ( g_bug_szTitle[0] != 0
    && g_bug_szDescription[0] != 0
    && g_bug_szSeverity[0] != 0
    && g_bug_szOwner[0] != 0
    && g_bug_szSubmitter[0] != 0
    && g_bug_szArea[0] != 0
    && g_bug_szMapNumber[0] != 0 )
  {
    v31 = g_bug_szCategory[0] != 0;
  }
  v34 = v31;
  v32 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1079);
  EnableWindow(hWnd: v32, bEnable: v34);
  g_bug_bActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x00402BB0
// Name: void BugDlg_SaveGame(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_SaveGame(HWND__ *hWnd)
{
  MessageBoxA(hWnd, lpText: "ERROR: savegame bugs not yet supported for ps3", lpCaption: "Oops", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00402BD0
// Name: void BugDlg_IncludeBSP(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_IncludeBSP(HWND__ *hWnd)
{
  MessageBoxA(hWnd, lpText: "ERROR: including BSP not yet supported for ps3", lpCaption: "Oops", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00402BF0
// Name: void BugDlg_Setup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_Setup(HWND hWnd)
{
  g_bug_hWnd = hWnd;
  g_bug_bFirstCommand = false;
  g_bug_szTitle[0] = 0;
  g_bug_szDescription[0] = 0;
  g_bug_szScreenshot[0] = 0;
  g_bug_szSavegame[0] = 0;
  g_bug_szBSPName[0] = 0;
  g_bug_bCompressScreenshot = true;
  memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
  BugDlg_Populate(hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x00402C40
// Name: bool BugDlg_UploadFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_UploadFile(const char *pLocalName, const char *pRemoteName, bool bDeleteLocal)
{
  int v3; // eax
  unsigned int v4; // ebx
  _iobuf *v5; // eax
  _iobuf *v6; // esi
  void *pLocalData; // [esp+Ch] [ebp-4h] BYREF

  ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: Uploading %s to %s\n", pLocalName, pRemoteName);
  v3 = Sys_LoadFile(filename: pLocalName, bufferptr: &pLocalData, bText: false);
  v4 = v3;
  if ( pLocalData != nullptr && v3 != 0 )
  {
    Sys_CreatePath(pInPath: pRemoteName);
    v5 = fopen(file: pRemoteName, mode: "wb");
    v6 = v5;
    if ( v5 != nullptr )
    {
      fwrite(buffer: pLocalData, size: v4, count: 1u, stream: v5);
      fclose(stream: v6);
      Sys_Free(ptr: pLocalData);
      if ( bDeleteLocal )
        unlink(path: pLocalName);
      return 1;
    }
    else
    {
      ConsoleWindowPrintf(
        rgb: 0xFFu,
        strFormat: "*** Bug Reporter: UploadFile: Unable to open remote path '%s'\n",
        pRemoteName);
      Sys_Free(ptr: pLocalData);
      return 0;
    }
  }
  else
  {
    ConsoleWindowPrintf(
      rgb: 0xFFu,
      strFormat: "*** Bug Reporter: UploadFile: Unable to open local path '%s'\n"
      "You can hit 'take shot' and try it again if you're feeling lucky.\n",
      pLocalName);
    g_bug_szScreenshot[0] = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D20
// Name: bool BugDlg_UploadBugSubmission(int,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BugDlg_UploadBugSubmission(
        int bugID,
        const char *pSavefile,
        const char *pScreenshot,
        const char *pBspFile)
{
  bool v4; // bl
  char *SubmissionURL; // eax
  char *v6; // eax
  char *v7; // eax
  char result; // al
  char szFilename[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char szRemotefile[260]; // [esp+110h] [ebp-208h] BYREF
  char szLocalfile[260]; // [esp+214h] [ebp-104h] BYREF

  v4 = true;
  if ( pSavefile != nullptr && *pSavefile != 0 )
  {
    V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pSavefile);
    Sys_StripPath(inpath: pSavefile, outpath: szFilename, outPathLen: 260);
    SubmissionURL = GetSubmissionURL(bugid: bugID);
    V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", SubmissionURL, szFilename);
    Sys_NormalizePath(path: szLocalfile, forceToLower: false);
    Sys_NormalizePath(path: szRemotefile, forceToLower: false);
    v4 = BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: false) != 0;
  }
  if ( pScreenshot != nullptr && *pScreenshot != 0 )
  {
    V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pScreenshot);
    Sys_StripPath(inpath: pScreenshot, outpath: szFilename, outPathLen: 260);
    v6 = GetSubmissionURL(bugid: bugID);
    V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", v6, szFilename);
    Sys_NormalizePath(path: szLocalfile, forceToLower: false);
    Sys_NormalizePath(path: szRemotefile, forceToLower: false);
    if ( BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: true) == 0 )
      v4 = false;
  }
  if ( pBspFile == nullptr )
    return v4;
  if ( *pBspFile == 0 )
    return v4;
  V_snprintf(pDest: szLocalfile, maxLen: 260, pFormat: "%s", pBspFile);
  Sys_StripPath(inpath: pBspFile, outpath: szFilename, outPathLen: 260);
  v7 = GetSubmissionURL(bugid: bugID);
  V_snprintf(pDest: szRemotefile, maxLen: 260, pFormat: "%s/%s", v7, szFilename);
  Sys_NormalizePath(path: szLocalfile, forceToLower: false);
  Sys_NormalizePath(path: szRemotefile, forceToLower: false);
  result = BugDlg_UploadFile(pLocalName: szLocalfile, pRemoteName: szRemotefile, bDeleteLocal: true);
  if ( result != 0 )
    return v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402F30
// Name: void BugDlg_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_SaveConfig()
{
  Sys_SetRegistryString(keyName: "bug_submitter", value: g_bug_szSubmitter);
  Sys_SetRegistryString(keyName: "bug_severity", value: g_bug_szSeverity);
  Sys_SetRegistryString(keyName: "bug_area", value: g_bug_szArea);
}

//------------------------------------------------------------------------------
// Address: 0x00402F70
// Name: void BugDlg_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_LoadConfig()
{
  const char *v0; // eax

  Sys_GetRegistryString(keyName: "bug_submitter", value: g_bug_szSubmitter, defValue: &str, valueLen: 128);
  Sys_GetRegistryString(keyName: "bug_severity", value: g_bug_szSeverity, defValue: &str, valueLen: 128);
  Sys_GetRegistryString(keyName: "bug_area", value: g_bug_szArea, defValue: "Portal 2", valueLen: 128);
  V_strncpy(pDest: g_bug_szCategory, pSrc: "MAP", maxLen: 128);
  if ( g_bug_pReporter2 != nullptr )
  {
    v0 = g_bug_pReporter2->GetUserNameForDisplayName(this: g_bug_pReporter2, a2: g_bug_szSubmitter);
    ConsoleWindowPrintf(
      rgb: 0xFFFF00u,
      strFormat: "*** Bug Reporter: BugBait Username: '%s' Display As: '%s'\n",
      g_bug_szSubmitter,
      v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403020
// Name: int rc_MapInfo(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_MapInfo(char *commandPtr)
{
  char *Token; // eax
  unsigned int v3; // eax
  void (__stdcall *v4)(HWND, int, LPCSTR); // esi
  const char *v5; // eax
  WPARAM v6; // eax
  BOOL v7; // eax
  HWND DlgItem; // eax
  HWND v9; // eax
  BOOL v10; // [esp+14h] [ebp-490h]
  BOOL v11; // [esp+14h] [ebp-490h]
  char complaint[1024]; // [esp+20h] [ebp-484h] BYREF
  char buff[128]; // [esp+420h] [ebp-84h] BYREF
  int mapinfosize; // [esp+4A0h] [ebp-4h] BYREF

  mapinfosize = 0;
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
  {
    MessageBoxA(
      hWnd: g_bug_hWnd,
      lpText: "Received corrupt map info from the console!",
      lpCaption: "Version Mismatch!!",
      uType: 0x30u);
    return 0;
  }
  sscanf(string: Token, format: "%d", &mapinfosize);
  v3 = mapinfosize;
  if ( mapinfosize == 1568 )
    goto LABEL_7;
  V_snprintf(
    pDest: complaint,
    maxLen: 1024,
    pFormat: "The version of vxconsole_ps3 you are using does not match\n"
    "the version of the game it's connected to. The game sent me\n"
    "%d bytes, but I was expecting %d. Map info is probably faulty.\n",
    mapinfosize,
    1568);
  if ( MessageBoxA(hWnd: g_bug_hWnd, lpText: complaint, lpCaption: "Version mismatch!", uType: 0x131u) == 1 )
  {
    v3 = mapinfosize;
    if ( (unsigned int)mapinfosize >= 0x620 )
    {
      v3 = 1568;
      mapinfosize = 1568;
    }
LABEL_7:
    memcpy(dst: (unsigned __int8 *)&g_bug_mapInfo, src: (unsigned __int8 *)++commandPtr, count: v3);
    LODWORD(g_bug_mapInfo.position[0]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[0]));
    LODWORD(g_bug_mapInfo.position[1]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[1]));
    LODWORD(g_bug_mapInfo.position[2]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.position[2]));
    LODWORD(g_bug_mapInfo.angle[0]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[0]));
    LODWORD(g_bug_mapInfo.angle[1]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[1]));
    LODWORD(g_bug_mapInfo.angle[2]) = _byteswap_ulong(LODWORD(g_bug_mapInfo.angle[2]));
    g_bug_mapInfo.build = _byteswap_ulong(g_bug_mapInfo.build);
    g_bug_mapInfo.skill = _byteswap_ulong(g_bug_mapInfo.skill);
    Sys_NormalizePath(path: g_bug_mapInfo.savePath, forceToLower: false);
    Sys_NormalizePath(path: g_bug_mapInfo.mapPath, forceToLower: false);
    if ( g_bug_hWnd != nullptr )
    {
      if ( g_bug_mapInfo.mapPath[0] != 0 )
      {
        Sys_StripPath(inpath: g_bug_mapInfo.mapPath, outpath: buff, outPathLen: 128);
        v4 = (void (__stdcall *)(HWND, int, LPCSTR))SetDlgItemTextA;
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1075, lpString: buff);
        v5 = V_strnchr(pStr: buff, c: 46, n: 128);
        if ( v5 != nullptr )
          *v5 = 0;
        v6 = SendDlgItemMessageA(
               hDlg: g_bug_hWnd,
               nIDDlgItem: 1078,
               Msg: 0x14Cu,
               wParam: 0xFFFFFFFF,
               lParam: (LPARAM)buff);
        if ( v6 == -1 )
          v6 = 0;
        SendDlgItemMessageA(hDlg: g_bug_hWnd, nIDDlgItem: 1078, Msg: 0x14Eu, wParam: v6, lParam: 0);
        BugDlg_OnMapChanged(hWnd: g_bug_hWnd);
        sprintf(
          string: buff,
          format: "%.2f %.2f %.2f",
          g_bug_mapInfo.position[0],
          g_bug_mapInfo.position[1],
          g_bug_mapInfo.position[2]);
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: buff);
        sprintf(
          string: buff,
          format: "%.2f %.2f %.2f",
          g_bug_mapInfo.angle[0],
          g_bug_mapInfo.angle[1],
          g_bug_mapInfo.angle[2]);
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: buff);
      }
      else
      {
        v4 = (void (__stdcall *)(HWND, int, LPCSTR))SetDlgItemTextA;
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1075, lpString: &str);
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: &str);
        SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: &str);
      }
      sprintf(string: buff, format: "%d", g_bug_mapInfo.build);
      v4(hDlg: g_bug_hWnd, nIDDlgItem: 1076, lpString: buff);
      v7 = g_bug_mapInfo.savePath[0] != 0 && g_bug_mapInfo.mapPath[0] != 0;
      v10 = v7;
      DlgItem = GetDlgItem(hDlg: g_bug_hWnd, nIDDlgItem: 1061);
      EnableWindow(hWnd: DlgItem, bEnable: v10);
      v11 = g_bug_mapInfo.mapPath[0] != 0;
      v9 = GetDlgItem(hDlg: g_bug_hWnd, nIDDlgItem: 1060);
      EnableWindow(hWnd: v9, bEnable: v11);
    }
    DebugCommand(pStrFormat: "MapInfo( %d )\n", mapinfosize);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004033B0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403400
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403460
// Name: public: void CUtlMemoryConservative<char>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryConservative<char>::EnsureCapacity(CUtlMemoryConservative<char> *this, int num)
{
  signed int v3; // eax
  unsigned int v4; // eax

  if ( this->m_pMemory != nullptr )
    v3 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_pMemory);
  else
    v3 = 0;
  if ( num <= v3 )
  {
    if ( this->m_pMemory != nullptr )
      v4 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_pMemory);
    else
      v4 = 0;
  }
  else
  {
    v4 = num;
  }
  this->m_pMemory = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: this->m_pMemory, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: bool BugDlg_CompressScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BugDlg_CompressScreenshot()
{
  HBITMAP__ *ImageA; // edi
  HDC__ *CompatibleDC; // ebx
  unsigned int v3; // ebx
  int biWidth; // edi
  void *v5; // esp
  unsigned int next_scanline; // eax
  char *v7; // ecx
  char *v8; // eax
  int v9; // esi
  _BYTE *v10; // ecx
  _BYTE *v11; // eax
  int v12; // eax
  char v13; // cl
  _BYTE v14[12]; // [esp+0h] [ebp-370h] BYREF
  jpeg_error_mgr jerr; // [esp+Ch] [ebp-364h] BYREF
  char jpgFilename[260]; // [esp+90h] [ebp-2E0h] BYREF
  jpeg_compress_struct cinfo; // [esp+194h] [ebp-1DCh] BYREF
  CUtlBuffer buf; // [esp+2FCh] [ebp-74h] BYREF
  tagBITMAPINFO bitmapInfo; // [esp+32Ch] [ebp-44h] BYREF
  char *pRowBuffer; // [esp+358h] [ebp-18h]
  unsigned __int8 *row_pointer[1]; // [esp+35Ch] [ebp-14h] BYREF
  HBITMAP__ *hBitmap; // [esp+360h] [ebp-10h]
  HDC__ *hDC; // [esp+364h] [ebp-Ch]
  char *pBMPBits; // [esp+368h] [ebp-8h]
  bool bSuccess; // [esp+36Fh] [ebp-1h]

  if ( g_bug_szScreenshot[0] == 0 )
    return false;
  bSuccess = false;
  pBMPBits = nullptr;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  ImageA = (HBITMAP__ *)LoadImageA(hInst: nullptr, name: g_bug_szScreenshot, type: 0, cx: 0, cy: 0, fuLoad: 0x2050u);
  hBitmap = ImageA;
  if ( ImageA != nullptr )
  {
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    hDC = CompatibleDC;
    if ( CompatibleDC != nullptr )
    {
      memset(dst: (unsigned __int8 *)&bitmapInfo, value: 0, count: sizeof(bitmapInfo));
      bitmapInfo.bmiHeader.biSize = 40;
      if ( GetDIBits(
             hdc: CompatibleDC,
             hbm: ImageA,
             start: 0,
             cLines: 0,
             lpvBits: nullptr,
             lpbmi: &bitmapInfo,
             usage: 0) != 0 )
      {
        pBMPBits = (char *)Sys_Alloc(size: bitmapInfo.bmiHeader.biSizeImage);
        if ( pBMPBits != nullptr )
        {
          v3 = abs32(bitmapInfo.bmiHeader.biHeight);
          if ( bitmapInfo.bmiHeader.biBitCount == 32
            && (bitmapInfo.bmiHeader.biCompression == 0 || bitmapInfo.bmiHeader.biCompression == 3) )
          {
            bitmapInfo.bmiHeader.biCompression = 0;
            if ( GetDIBits(hdc: hDC, hbm: ImageA, start: 0, cLines: v3, lpvBits: pBMPBits, lpbmi: &bitmapInfo, usage: 0) != 0 )
            {
              memset(dst: (unsigned __int8 *)&cinfo, value: 0, count: sizeof(cinfo));
              cinfo.err = jpeg_std_error(err: &jerr);
              jpeg_CreateCompress(&cinfo, version: 62, structsize: 0x168u);
              jpeg_UtlBuffer_dest((jpeg_common_struct *)&cinfo, pBuffer: &buf);
              cinfo.image_width = bitmapInfo.bmiHeader.biWidth;
              cinfo.image_height = v3;
              cinfo.input_components = 3;
              cinfo.in_color_space = JCS_RGB;
              jpeg_set_defaults(&cinfo);
              jpeg_set_quality(&cinfo, quality: 50, force_baseline: 1u);
              jpeg_start_compress(&cinfo, write_all_tables: 1u);
              biWidth = bitmapInfo.bmiHeader.biWidth;
              v5 = alloca(3 * bitmapInfo.bmiHeader.biWidth);
              next_scanline = cinfo.next_scanline;
              v7 = v14;
              pRowBuffer = v14;
              row_pointer[0] = v14;
              if ( cinfo.next_scanline < cinfo.image_height )
              {
                while ( 1 )
                {
                  if ( bitmapInfo.bmiHeader.biHeight >= 0 )
                    v8 = &pBMPBits[4 * biWidth * (v3 - next_scanline - 1)];
                  else
                    v8 = &pBMPBits[4 * biWidth * next_scanline];
                  v9 = 0;
                  if ( biWidth > 0 )
                  {
                    v10 = v7 + 2;
                    v11 = v8 + 1;
                    do
                    {
                      *(v10 - 2) = v11[1];
                      *(v10 - 1) = *v11;
                      *v10 = *(v11 - 1);
                      ++v9;
                      v11 += 4;
                      v10 += 3;
                    }
                    while ( v9 < bitmapInfo.bmiHeader.biWidth );
                  }
                  jpeg_write_scanlines(&cinfo, scanlines: row_pointer, num_lines: 1u);
                  next_scanline = cinfo.next_scanline;
                  if ( cinfo.next_scanline >= cinfo.image_height )
                    break;
                  biWidth = bitmapInfo.bmiHeader.biWidth;
                  v7 = pRowBuffer;
                }
              }
              jpeg_finish_compress(&cinfo);
              Sys_StripExtension(inpath: g_bug_szScreenshot, outpath: jpgFilename, outPathLen: 260);
              Sys_AddExtension(extension: ".jpg", outpath: jpgFilename, outPathLen: 260, bForce: true);
              if ( Sys_SaveFile(
                     filename: jpgFilename,
                     buffer: buf.m_Memory.m_pMemory,
                     count: buf.m_nMaxPut,
                     bText: false) )
              {
                unlink(path: g_bug_szScreenshot);
                v12 = 0;
                do
                {
                  v13 = jpgFilename[v12];
                  g_bug_szScreenshot[v12++] = v13;
                }
                while ( v13 != 0 );
                bSuccess = true;
              }
              ImageA = hBitmap;
            }
          }
          CompatibleDC = hDC;
        }
      }
    }
    DeleteObject(ho: ImageA);
    if ( CompatibleDC != nullptr )
      DeleteDC(hdc: CompatibleDC);
    if ( pBMPBits != nullptr )
      Sys_Free(ptr: pBMPBits);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x004037D0
// Name: bool BugDlg_Submit(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall BugDlg_Submit@<al>(int a1@<edi>, HWND hWnd)
{
  char *v2; // eax
  char *v3; // eax
  HANDLE FirstFileA; // eax
  LRESULT v5; // esi
  LRESULT v6; // esi
  unsigned __int8 *m_pMemory; // edx
  LRESULT v8; // eax
  unsigned __int8 v9; // cl
  unsigned __int8 v11; // cl
  IBugReporter_vtbl *v12; // esi
  const char *v13; // eax
  IBugReporter_vtbl *v14; // esi
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  bool v19; // bl
  char *SubmissionURL; // eax
  _iobuf *v21; // esi
  char v22[32768]; // [esp+20h] [ebp-110A8h] BYREF
  char buffer[32768]; // [esp+8020h] [ebp-90A8h] BYREF
  char Text[1024]; // [esp+10020h] [ebp-10A8h] BYREF
  char v25[1024]; // [esp+10420h] [ebp-CA8h] BYREF
  char pDest[256]; // [esp+10820h] [ebp-8A8h] BYREF
  char String[260]; // [esp+10920h] [ebp-7A8h] BYREF
  char string[260]; // [esp+10A24h] [ebp-6A4h] BYREF
  char v29[260]; // [esp+10B28h] [ebp-5A0h] BYREF
  _WIN32_FIND_DATAA dst; // [esp+10C2Ch] [ebp-49Ch] BYREF
  char out[260]; // [esp+10D6Ch] [ebp-35Ch] BYREF
  char outpath[260]; // [esp+10E70h] [ebp-258h] BYREF
  char path[260]; // [esp+10F74h] [ebp-154h] BYREF
  CUtlBuffer v34; // [esp+11078h] [ebp-50h] BYREF
  _DWORD v35[5]; // [esp+110A8h] [ebp-20h] BYREF
  WPARAM wParam[2]; // [esp+110BCh] [ebp-Ch] BYREF
  int bugID; // [esp+110C4h] [ebp-4h] BYREF

  sprintf(string, format: "%f %f %f", g_bug_mapInfo.position[0], g_bug_mapInfo.position[1], g_bug_mapInfo.position[2]);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1073, lpString: string);
  sprintf(string: String, format: "%f %f %f", g_bug_mapInfo.angle[0], g_bug_mapInfo.angle[1], g_bug_mapInfo.angle[2]);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1074, lpString: String);
  sprintf(string: v29, format: "%d", g_bug_mapInfo.build);
  SetDlgItemTextA(hDlg: g_bug_hWnd, nIDDlgItem: 1076, lpString: v29);
  V_FileBase(in: g_bug_mapInfo.mapPath, out, maxlen: 260);
  v2 = V_stristr(pStr: out, pSearch: ".bsp");
  if ( v2 != nullptr )
    *v2 = 0;
  v3 = V_stristr(pStr: out, pSearch: ".ps3");
  if ( v3 != nullptr )
    *v3 = 0;
  V_strncpy(pDest, pSrc: "Unknown Image Version", maxLen: 256);
  if ( g_bug_szScreenshot[0] != 0 )
  {
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    FirstFileA = FindFirstFileA(lpFileName: g_bug_szScreenshot, lpFindFileData: &dst);
    if ( FirstFileA == (HANDLE)-1 )
    {
      V_snprintf(
        pDest: Text,
        maxLen: 1024,
        pFormat: "I couldn't find the screenshot %s on your disk.\nDo you want to submit a bug without a screenshot?\n",
        g_bug_szScreenshot);
      if ( MessageBoxA(hWnd, lpText: Text, lpCaption: "Screenshot Fail", uType: 0x34u) != 6 )
        return false;
      g_bug_szScreenshot[0] = 0;
    }
    else
    {
      FindClose(hFindFile: FirstFileA);
    }
  }
  v22[0] = 0;
  wParam[0] = 20;
  wParam[1] = 0;
  v5 = SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x45Fu, (WPARAM)wParam, lParam: 0);
  if ( v5 != -2147024809 )
  {
    CUtlBuffer::CUtlBuffer(this: &v34, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &v34, num: v5);
    CUtlBuffer::PutChar(this: &v34, c: 0);
    v35[0] = v5;
    memset(&v35[1], 0, 16);
    v6 = SendDlgItemMessageA(
           hDlg: g_hDlgMain,
           nIDDlgItem: 1010,
           Msg: 0x45Eu,
           wParam: (WPARAM)v35,
           lParam: (LPARAM)v34.m_Memory.m_pMemory);
    CUtlBuffer::SeekPut(this: &v34, type: SEEK_CURRENT, offset: v6);
    m_pMemory = v34.m_Memory.m_pMemory;
    v8 = 0;
    if ( (unsigned int)v6 > 0x8000 )
    {
      v8 = v6 - 0x8000;
      if ( v6 - 0x8000 >= v6 )
        goto LABEL_27;
      while ( 1 )
      {
        v9 = v34.m_Memory.m_pMemory[v8];
        if ( v9 == 0 || v9 == 10 || v9 == 13 )
          break;
        if ( ++v8 >= v6 )
          goto LABEL_27;
      }
      if ( v8 >= v6 )
        goto LABEL_27;
      while ( 1 )
      {
        v11 = v34.m_Memory.m_pMemory[v8];
        if ( v11 == 0 || v11 != 10 && v11 != 13 )
          break;
        if ( ++v8 >= v6 )
          goto LABEL_27;
      }
    }
    if ( v8 < v6 )
    {
      V_strncpy(pDest: v22, pSrc: (const char *)&v34.m_Memory.m_pMemory[v8], maxLen: 0x8000);
      m_pMemory = v34.m_Memory.m_pMemory;
    }
LABEL_27:
    if ( v34.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  V_snprintf(
    pDest: buffer,
    maxLen: 0x8000,
    pFormat: "\n*** Playstation 3 ***\n%s\n\n%s\n",
    pDest,
    g_bug_mapInfo.details);
  ((void (__thiscall *)(IBugReporter *, int))g_bug_pReporter->StartNewBugReport)(a1: g_bug_pReporter, a2: a1);
  v12 = g_bug_pReporter->__vftable;
  v13 = g_bug_pReporter->GetUserNameForDisplayName(this: g_bug_pReporter, a2: g_bug_szOwner);
  v12->SetOwner(this: g_bug_pReporter, a2: v13);
  v14 = g_bug_pReporter->__vftable;
  v15 = g_bug_pReporter->GetUserNameForDisplayName(this: g_bug_pReporter, a2: g_bug_szSubmitter);
  v14->SetSubmitter(this: g_bug_pReporter, a2: v15);
  if ( out[0] != 0 )
    V_snprintf(pDest: v25, maxLen: 1024, pFormat: "%s: %s", out, g_bug_szTitle);
  else
    V_snprintf(pDest: v25, maxLen: 1024, pFormat: "%s", g_bug_szTitle);
  g_bug_pReporter->SetTitle(this: g_bug_pReporter, a2: v25);
  g_bug_pReporter->SetDescription(this: g_bug_pReporter, a2: g_bug_szDescription);
  g_bug_pReporter->SetLevel(this: g_bug_pReporter, a2: out);
  g_bug_pReporter->SetPosition(this: g_bug_pReporter, a2: string);
  g_bug_pReporter->SetOrientation(this: g_bug_pReporter, a2: String);
  g_bug_pReporter->SetBuildNumber(this: g_bug_pReporter, a2: v29);
  g_bug_pReporter->SetSeverity(this: g_bug_pReporter, a2: g_bug_szSeverity);
  g_bug_pReporter->SetReportType(this: g_bug_pReporter, a2: g_bug_szCategory);
  g_bug_pReporter->SetArea(this: g_bug_pReporter, a2: g_bug_szArea);
  g_bug_pReporter->SetMapNumber(this: g_bug_pReporter, a2: g_bug_szMapNumber);
  g_bug_pReporter->SetMiscInfo(this: g_bug_pReporter, a2: buffer);
  g_bug_pReporter->SetDriverInfo(this: g_bug_pReporter, a2: &str);
  g_bug_pReporter->SetExeName(this: g_bug_pReporter, a2: &str);
  g_bug_pReporter->SetGameDirectory(this: g_bug_pReporter, a2: &str);
  g_bug_pReporter->SetRAM(this: g_bug_pReporter, a2: 0);
  g_bug_pReporter->SetCPU(this: g_bug_pReporter, a2: 0);
  g_bug_pReporter->SetProcessor(this: g_bug_pReporter, a2: &str);
  g_bug_pReporter->SetDXVersion(this: g_bug_pReporter, a2: 0, a3: 0, a4: 0, a5: 0);
  g_bug_pReporter->SetOSVersion(this: g_bug_pReporter, a2: "PS3");
  g_bug_pReporter->ResetIncludedFiles(this: g_bug_pReporter);
  g_bug_pReporter->SetZipAttachmentName(this: g_bug_pReporter, a2: &str);
  if ( g_bug_szScreenshot[0] != 0 )
  {
    if ( g_bug_bCompressScreenshot )
      BugDlg_CompressScreenshot();
    Sys_StripPath(inpath: g_bug_szScreenshot, outpath, outPathLen: 260);
    v16 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v16 == nullptr )
      v16 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v16, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetScreenShot(this: g_bug_pReporter, a2: path);
  }
  if ( g_bug_szSavegame[0] != 0 )
  {
    Sys_StripPath(inpath: g_bug_szSavegame, outpath, outPathLen: 260);
    v17 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v17 == nullptr )
      v17 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v17, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetSaveGame(this: g_bug_pReporter, a2: path);
  }
  if ( g_bug_szBSPName[0] != 0 )
  {
    Sys_StripPath(inpath: g_bug_szBSPName, outpath, outPathLen: 260);
    v18 = g_bug_pReporter->GetRepositoryURL(this: g_bug_pReporter);
    if ( v18 == nullptr )
      v18 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/BugId/%s", v18, outpath);
    Sys_NormalizePath(path, forceToLower: false);
    g_bug_pReporter->SetBSPName(this: g_bug_pReporter, a2: path);
  }
  bugID = -1;
  v19 = g_bug_pReporter->CommitBugReport(this: g_bug_pReporter, a2: &bugID);
  if ( !v19 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to post bug report to database!\n");
    goto LABEL_50;
  }
  if ( BugDlg_UploadBugSubmission(
         bugID,
         pSavefile: g_bug_szSavegame,
         pScreenshot: g_bug_szScreenshot,
         pBspFile: g_bug_szBSPName) == 0 )
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to upload files to bug repository!\n");
LABEL_50:
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bug Reporter: BugBait submission failed\n");
    return false;
  }
  SubmissionURL = GetSubmissionURL(bugid: bugID);
  V_snprintf(pDest: &dst.cFileName[16], maxLen: 260, pFormat: "%s/%s", SubmissionURL, "vxconsolespew.txt");
  Sys_NormalizePath(path: &dst.cFileName[16], forceToLower: false);
  v21 = fopen(file: &dst.cFileName[16], mode: "wt");
  if ( v21 != nullptr )
  {
    fwrite(buffer, size: 1u, count: strlen(buffer), stream: v21);
    fwrite(buffer: "\n\n", size: 1u, count: 2u, stream: v21);
    fwrite(buffer: v22, size: 1u, count: strlen(v22), stream: v21);
    fclose(stream: v21);
  }
  else
  {
    Sys_MessageBox(title: "Bug Error", format: "Unable to upload console spew to bug repository!\n");
  }
  ConsoleWindowPrintf(rgb: 0xFFFF00u, strFormat: "*** Bug Reporter: BugBait submission succeeded!\n");
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x00404050
// Name: int BugDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall BugDlg_Proc(HWND__ *hwnd, unsigned int message, unsigned int wParam, int lParam)
{
  int result; // eax

  if ( message == 272 )
  {
    BugDlg_Setup(hWnd: hwnd);
    return 1;
  }
  else if ( message == 273 )
  {
    if ( (unsigned __int16)wParam > 0x3FCu )
    {
      switch ( (__int16)wParam )
      {
        case 1056:
          g_bug_szTitle[0] = 0;
          g_bug_szDescription[0] = 0;
          g_bug_szOwner[0] = 0;
          g_bug_szSeverity[0] = 0;
          g_bug_szMapNumber[0] = 0;
          g_bug_szScreenshot[0] = 0;
          g_bug_szSavegame[0] = 0;
          g_bug_szBSPName[0] = 0;
          g_bug_bCompressScreenshot = true;
          memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
          BugDlg_Populate(hWnd: hwnd);
          return 1;
        case 1057:
        case 1058:
          if ( !g_bug_bActive || HIWORD(wParam) != 768 )
            return 0;
          BugDlg_GetChanges(hWnd: hwnd);
          return 1;
        case 1059:
          BugDlg_GetAppData(hWnd: hwnd);
          return 1;
        case 1060:
          BugDlg_IncludeBSP(hWnd: hwnd);
          return 0;
        case 1061:
          BugDlg_SaveGame(hWnd: hwnd);
          return 0;
        case 1063:
          BugDlg_TakeScreenshot(hWnd: hwnd);
          return 0;
        case 1065:
        case 1080:
        case 1095:
        case 1096:
          if ( !g_bug_bActive || HIWORD(wParam) != 8 )
            return 0;
          goto $LN5_0;
        case 1068:
          if ( HIWORD(wParam) != 8 )
            return 0;
          if ( !BugDlg_OnAreaChanged(hWnd: hwnd) )
            goto LABEL_17;
          g_bug_szOwner[0] = 0;
          g_bug_szSeverity[0] = 0;
          g_bug_szMapNumber[0] = 0;
          g_bug_bCompressScreenshot = true;
          memset(dst: (unsigned __int8 *)&g_bug_mapInfo, value: 0, count: sizeof(g_bug_mapInfo));
          BugDlg_Populate(hWnd: hwnd);
          result = 1;
          break;
        case 1078:
          if ( !g_bug_bActive || HIWORD(wParam) != 8 )
            return 0;
          BugDlg_OnMapChanged(hWnd: hwnd);
          return 1;
        case 1079:
          if ( BugDlg_Submit(a1: (int)hwnd, hWnd: hwnd) )
            goto LABEL_28;
          return 0;
        case 1083:
$LN5_0:
          BugDlg_GetChanges(hWnd: hwnd);
LABEL_17:
          result = 1;
          break;
        default:
          return 0;
      }
    }
    else if ( (unsigned __int16)wParam == 1020 || (unsigned __int16)wParam == 2 )
    {
LABEL_28:
      if ( g_connectionState == kCONNECTEDAPP && g_bug_bFirstCommand )
        ProcessCommand(strCmdIn: "cmd bugunpause");
      EndDialog(hDlg: hwnd, nResult: wParam);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004042F0
// Name: void BugDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BugDlg_Open()
{
  if ( g_bug_hWnd == nullptr && BugReporter_GetInterfaces() != 0 )
  {
    BugDlg_LoadConfig();
    if ( (unsigned __int16)DialogBoxParamA(
                             hInstance: g_hInstance,
                             lpTemplateName: (LPCSTR)0x80,
                             hWndParent: g_hDlgMain,
                             lpDialogFunc: BugDlg_Proc,
                             dwInitParam: 0) == 1079 )
      BugDlg_SaveConfig();
    g_bug_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404340
// Name: int rc_Screenshot(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_Screenshot(char *commandPtr)
{
  unsigned __int8 *v1; // edi
  unsigned int v2; // esi
  unsigned int v3; // eax
  char v4; // dl
  char complaint[1024]; // [esp+4h] [ebp-414h] BYREF
  unsigned int uWidth; // [esp+404h] [ebp-14h] BYREF
  unsigned int uColorFmt; // [esp+408h] [ebp-10h] BYREF
  unsigned int nPrefixLen; // [esp+40Ch] [ebp-Ch] BYREF
  unsigned int uPitch; // [esp+410h] [ebp-8h] BYREF
  unsigned int uHeight; // [esp+414h] [ebp-4h] BYREF

  if ( sscanf(string: commandPtr, format: " %u %u %u %u%n", &uWidth, &uHeight, &uPitch, &uColorFmt, &nPrefixLen) <= 0 )
    return -1;
  v1 = (unsigned __int8 *)&commandPtr[nPrefixLen + 1];
  v2 = uPitch * uHeight;
  CUtlMemoryConservative<char>::EnsureCapacity(this: &g_mostRecentlyReceivedScreenshot.m_Data, num: uPitch * uHeight);
  memcpy(dst: (unsigned __int8 *)g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory, src: v1, count: v2);
  v3 = uColorFmt;
  g_mostRecentlyReceivedScreenshot.uWidth = uWidth;
  g_mostRecentlyReceivedScreenshot.uHeight = uHeight;
  g_mostRecentlyReceivedScreenshot.uPitch = uPitch;
  g_mostRecentlyReceivedScreenshot.uColorFmt = uColorFmt;
  if ( uColorFmt != 0 )
  {
    _snprintf(
      string: complaint,
      count: 0x400u,
      format: "Received a screenshot with an unknown color format.\n"
      "Your screenshot might look funny.\n"
      "width %d height %d pitch %d colorfmt %d\n",
      uWidth,
      uHeight,
      uPitch,
      uColorFmt);
    MessageBoxA(hWnd: nullptr, lpText: complaint, lpCaption: "Inappropriate Screenshot", uType: 0x30u);
  }
  else if ( v2 != 0 )
  {
    do
    {
      v4 = g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory[v3 + 1];
      g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory[v3 + 1] = g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory[v3 + 3];
      g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory[v3 + 3] = v4;
      v3 += 4;
    }
    while ( v3 < v2 );
  }
  if ( g_pOnScreenshotArrivalDoThis != nullptr )
  {
    g_pOnScreenshotArrivalDoThis->OnScreenshot(
      this: g_pOnScreenshotArrivalDoThis,
      a2: &g_mostRecentlyReceivedScreenshot);
    free(pMem: g_pOnScreenshotArrivalDoThis);
    g_pOnScreenshotArrivalDoThis = nullptr;
  }
  return 0;
}
