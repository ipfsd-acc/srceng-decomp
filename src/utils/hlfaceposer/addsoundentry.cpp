// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/addsoundentry.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041F770
// Name: PopulateScriptList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateScriptList(HWND wnd@<eax>)
{
  HWND DlgItem; // eax
  HWND v2; // edi
  int v3; // esi
  const char *v4; // eax
  const char *v5; // eax
  int c; // [esp+4h] [ebp-4h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1062);
  v2 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v3 = 0;
    c = soundemitter->GetNumSoundScripts(this: soundemitter);
    if ( c > 0 )
    {
      do
      {
        v4 = soundemitter->GetSoundScriptName(this: soundemitter, a2: v3);
        SendMessageA(hWnd: v2, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v4);
        if ( v3 == 0 && g_Params_0.m_szScriptName[0] == 0 )
        {
          v5 = soundemitter->GetSoundScriptName(this: soundemitter, a2: 0);
          SendMessageA(hWnd: v2, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v5);
        }
        ++v3;
      }
      while ( v3 < c );
    }
    if ( g_Params_0.m_szScriptName[0] != 0 )
      SendMessageA(hWnd: v2, Msg: 0xCu, wParam: 0, lParam: (LPARAM)g_Params_0.m_szScriptName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F830
// Name: AddSoundPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall AddSoundPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  HWND DlgItem; // eax
  HWND v9; // eax
  CSoundParametersInternal params; // [esp+8h] [ebp-28h] BYREF

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_0, self: hwndDlg);
    PopulateScriptList(wnd: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1061, lpString: g_Params_0.m_szSoundName);
    if ( g_Params_0.m_bReadOnlySoundName )
    {
      DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1061);
      if ( DlgItem != nullptr )
        SendMessageA(hWnd: DlgItem, Msg: 0xCFu, wParam: 1u, lParam: 0);
    }
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_0.m_szDialogTitle);
    v9 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1061);
    SetFocus(hWnd: v9);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam != 1 )
    {
      if ( wParam == 2 )
      {
        EndDialog(hDlg: hwndDlg, nResult: 0);
        return 1;
      }
      return 1;
    }
    g_Params_0.m_szSoundName[0] = 0;
    g_Params_0.m_szScriptName[0] = 0;
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1061, lpString: g_Params_0.m_szSoundName, cchMax: 256);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1062, lpString: g_Params_0.m_szScriptName, cchMax: 256);
    if ( g_Params_0.m_szSoundName[0] == 0 || g_Params_0.m_szScriptName[0] == 0 )
      return 1;
    v5 = soundemitter->GetSoundIndex(this: soundemitter, a2: g_Params_0.m_szSoundName);
    if ( soundemitter->IsValidIndex(this: soundemitter, a2: v5) )
    {
      if ( !g_Params_0.m_bAllowExistingSound )
      {
        v6 = va(fmt: "Sound '%s' already exists", g_Params_0.m_szSoundName);
        mxMessageBox(parent: nullptr, msg: v6, title: g_appTitle, style: 0);
        return 1;
      }
      EndDialog(hDlg: hwndDlg, nResult: 1);
      return 1;
    }
    if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: g_Params_0.m_szScriptName, a3: nullptr) )
    {
      v7 = va(fmt: "Script '%s' does not exist", g_Params_0.m_szScriptName);
LABEL_15:
      mxMessageBox(parent: nullptr, msg: v7, title: g_appTitle, style: 0);
      return 1;
    }
    if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: g_Params_0.m_szScriptName, a3: nullptr) )
    {
      v7 = va(fmt: "Script '%s' is read-only, you need to check it out of VSS", g_Params_0.m_szScriptName);
      goto LABEL_15;
    }
    CSoundParametersInternal::CSoundParametersInternal(this: &params);
    params.channel = 2;
    params.soundlevel = (sound_interval_t<unsigned short>)80;
    soundemitter->ExpandSoundNameMacros(this: soundemitter, a2: &params, a3: g_Params_0.m_szWaveFile);
    soundemitter->AddSound(this: soundemitter, a2: g_Params_0.m_szSoundName, a3: g_Params_0.m_szScriptName, a4: &params);
    EndDialog(hDlg: hwndDlg, nResult: 1);
    CSoundParametersInternal::~CSoundParametersInternal(this: &params);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FA90
// Name: int AddSound(struct CAddSoundParams __near *,struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl AddSound(CAddSoundParams *params, HWND__ *parent)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax

  g_Params_0 = *params;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x77,
             hWndParent: parent,
             lpDialogFunc: (DLGPROC)AddSoundPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_0;
  return result;
}
