// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/waveproperties.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00419510
// Name: WaveProperties_OnOK
// Source: json
//------------------------------------------------------------------------------
void __usercall WaveProperties_OnOK(HWND hwndDlg@<edi>, int a2@<ebx>)
{
  CWaveFile *v2; // esi
  HWND DlgItem; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  char sentencetext[512]; // [esp+4h] [ebp-204h] BYREF
  BOOL voiceduck; // [esp+204h] [ebp-4h]

  v2 = *g_Params_4.items.m_Memory.m_pMemory;
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1021, lpString: sentencetext, cchMax: 512);
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
  LOBYTE(voiceduck) = SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
  MultipleRequestChangeContext();
  CWaveFile::SetVoiceDuck(this: v2, a2, duck: voiceduck);
  CWaveFile::SetSentenceText(this: v2, newText: sentencetext);
  WorkspaceManager = GetWorkspaceManager();
  CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
}

//------------------------------------------------------------------------------
// Address: 0x00419590
// Name: WaveProperties_ExportSentence
// Source: json
//------------------------------------------------------------------------------
void WaveProperties_ExportSentence()
{
  int m_Size; // ebx
  int v1; // edi
  CWaveFile *v2; // esi
  const char *v3; // eax
  char relative[512]; // [esp+4h] [ebp-200h] BYREF

  m_Size = g_Params_4.items.m_Size;
  if ( g_Params_4.items.m_Size > 0 )
  {
    MultipleRequestChangeContext();
    v1 = 0;
    while ( 1 )
    {
      v2 = g_Params_4.items.m_Memory.m_pMemory[v1];
      CWaveFile::GetPhonemeExportFile(this: v2, path: relative, maxlen: 512);
      if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: relative, a3: nullptr) )
        goto LABEL_6;
      v3 = va(fmt: "Overwrite '%s'?", relative);
      if ( MultipleRequest(prompt: v3) == 0 )
        break;
LABEL_7:
      if ( ++v1 >= m_Size )
        return;
    }
    filesystem->RemoveFile(this: filesystem, a2: relative, a3: nullptr);
LABEL_6:
    CWaveFile::ExportValveDataChunk(this: v2, tempfile: relative);
    goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419650
// Name: WaveProperties_ImportSentence
// Source: json
//------------------------------------------------------------------------------
void WaveProperties_ImportSentence()
{
  int m_Size; // ebx
  int v1; // edi
  CWaveFile *v2; // esi
  char relative[512]; // [esp+4h] [ebp-200h] BYREF

  m_Size = g_Params_4.items.m_Size;
  if ( g_Params_4.items.m_Size > 0 )
  {
    v1 = 0;
    do
    {
      v2 = g_Params_4.items.m_Memory.m_pMemory[v1];
      CWaveFile::GetPhonemeExportFile(this: v2, path: relative, maxlen: 512);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: relative, a3: nullptr) )
        CWaveFile::ImportValveDataChunk(this: v2, a2: m_Size, a3: v1, a4: (int)v2, tempfile: relative);
      ++v1;
    }
    while ( v1 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004196D0
// Name: WaveProperties_InitSentenceData
// Source: json
//------------------------------------------------------------------------------
void __usercall WaveProperties_InitSentenceData(HWND hwndDlg@<edi>)
{
  CWaveFile *v1; // esi
  const char *v2; // eax
  char *SentenceText; // eax
  HWND DlgItem; // eax
  WPARAM VoiceDuck; // [esp-8h] [ebp-10h]

  v1 = *g_Params_4.items.m_Memory.m_pMemory;
  v2 = (const char *)(***(int (__thiscall ****)(CWaveFile *))g_Params_4.items.m_Memory.m_pMemory)(a1: *g_Params_4.items.m_Memory.m_pMemory);
  SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1019, lpString: v2);
  SentenceText = CWaveFile::GetSentenceText(this: v1);
  SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1021, lpString: SentenceText);
  VoiceDuck = CWaveFile::GetVoiceDuck(this: v1);
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: VoiceDuck, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00419730
// Name: WavePropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __userpurge WavePropertiesDialogProc@<eax>(
        int a1@<ebx>,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned __int16 wParam,
        int lParam)
{
  HWND DlgItem; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_4, self: hwndDlg);
    WaveProperties_InitSentenceData(hwndDlg);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_4.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1019);
    SetFocus(hWnd: DlgItem);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam > 0x403u )
    {
      if ( wParam == 1028 )
      {
        WaveProperties_ImportSentence();
        WaveProperties_InitSentenceData(hwndDlg);
        return 0;
      }
    }
    else
    {
      switch ( wParam )
      {
        case 0x403u:
          WaveProperties_ExportSentence();
          return 0;
        case 1u:
          WaveProperties_OnOK(hwndDlg, a2: a1);
          EndDialog(hDlg: hwndDlg, nResult: 1);
          return 0;
        case 2u:
          EndDialog(hDlg: hwndDlg, nResult: 0);
          return 0;
        default:
          break;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419860
// Name: int WaveProperties(struct CWaveParams __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WaveProperties(CWaveParams *params)
{
  int m_Size; // esi
  int i; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  INT_PTR v5; // eax
  int v6; // esi
  int j; // eax
  HWND Handle; // [esp-Ch] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-14h]
  int retval; // [esp+Ch] [ebp-4h]

  g_Params_4.CBaseDialogParams = params->CBaseDialogParams;
  m_Size = params->items.m_Size;
  g_Params_4.items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&g_Params_4.items,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    g_Params_4.items.m_Memory.m_pMemory[i] = params->items.m_Memory.m_pMemory[i];
  WorkspaceManager = GetWorkspaceManager();
  Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v5 = DialogBoxParamA(
         hInstance: ModuleHandleA,
         lpTemplateName: (LPCSTR)0x76,
         hWndParent: Handle,
         lpDialogFunc: (DLGPROC)WavePropertiesDialogProc,
         dwInitParam: 0);
  params->CBaseDialogParams = g_Params_4.CBaseDialogParams;
  v6 = g_Params_4.items.m_Size;
  v10 = g_Params_4.items.m_Size;
  retval = v5;
  params->items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&params->items,
    elem: 0,
    num: v10);
  for ( j = 0; j < v6; ++j )
    params->items.m_Memory.m_pMemory[j] = g_Params_4.items.m_Memory.m_pMemory[j];
  return retval;
}
