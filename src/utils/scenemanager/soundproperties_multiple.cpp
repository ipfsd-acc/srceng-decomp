// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/soundproperties_multiple.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004105C0
// Name: PopulateChannelList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateChannelList(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // [esp-8h] [ebp-10h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1007);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( p != nullptr )
    {
      v4 = CSoundParametersInternal::ChannelToString(this: p);
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    }
    else
    {
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"CHAN_VOICE");
    }
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_VOICE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_AUTO");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_WEAPON");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_ITEM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_BODY");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_STREAM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_STATIC");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410680
// Name: PopulateVolumeList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateVolumeList(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // [esp-8h] [ebp-10h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1008);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( p != nullptr )
    {
      v4 = CSoundParametersInternal::VolumeToString(this: p);
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    }
    else
    {
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"VOL_NORM");
    }
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"VOL_NORM");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004106E0
// Name: PopulateSoundlevelList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateSoundlevelList(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // [esp-8h] [ebp-10h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1009);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( p != nullptr )
    {
      v4 = CSoundParametersInternal::SoundLevelToString(this: p);
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    }
    else
    {
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"SNDLVL_NORM");
    }
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_NORM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_NONE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_IDLE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_TALKING");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_STATIC");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_GUNFIRE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_25dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_30dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_35dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_40dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_45dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_50dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_55dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_60dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_65dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_70dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_75dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_80dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_85dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_90dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_95dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_100dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_105dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_120dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_130dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_140dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_150dB");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004108D0
// Name: PopulatePitchList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulatePitchList(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // [esp-8h] [ebp-10h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1010);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( p != nullptr )
    {
      v4 = CSoundParametersInternal::PitchToString(this: p);
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    }
    else
    {
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"PITCH_NORM");
    }
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_NORM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_LOW");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_HIGH");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004125F0
// Name: PopulateChannelList_0
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateChannelList_0(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // eax

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1007);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v4 = CSoundParametersInternal::ChannelToString(this: p);
    SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_VOICE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_AUTO");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_WEAPON");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_ITEM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_BODY");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_STREAM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CHAN_STATIC");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004126A0
// Name: PopulateVolumeList_0
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateVolumeList_0(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // eax

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1008);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v4 = CSoundParametersInternal::VolumeToString(this: p);
    SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"VOL_NORM");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004126F0
// Name: PopulateSoundlevelList_0
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateSoundlevelList_0(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // eax

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1009);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v4 = CSoundParametersInternal::SoundLevelToString(this: p);
    SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_NORM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_NONE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_IDLE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_TALKING");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_STATIC");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_GUNFIRE");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_25dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_30dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_35dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_40dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_45dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_50dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_55dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_60dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_65dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_70dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_75dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_80dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_85dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_90dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_95dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_100dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_105dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_120dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_130dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_140dB");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"SNDLVL_150dB");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004128D0
// Name: PopulatePitchList_0
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulatePitchList_0(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // eax

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1010);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v4 = CSoundParametersInternal::PitchToString(this: p);
    SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_NORM");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_LOW");
    SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"PITCH_HIGH");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412940
// Name: SoundProperties_Multiple_OnOK
// Source: json
//------------------------------------------------------------------------------
void __usercall SoundProperties_Multiple_OnOK(HWND hwndDlg@<esi>)
{
  int v1; // ecx
  CSoundEntry *v2; // ecx
  ISoundEmitterSystemBase_vtbl *v3; // edi
  int v4; // eax
  int v5; // edi
  const CSoundParametersInternal *v6; // edi
  HWND DlgItem; // eax
  LRESULT v8; // eax
  ISoundEmitterSystemBase_vtbl *v9; // edi
  int v10; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  char sz[128]; // [esp+8h] [ebp-B4h] BYREF
  CSoundParametersInternal outparams; // [esp+88h] [ebp-34h] BYREF
  CSoundEntry *item; // [esp+B0h] [ebp-Ch]
  int c; // [esp+B4h] [ebp-8h]
  int i; // [esp+B8h] [ebp-4h]

  v1 = 0;
  c = g_Params_2.items.m_Size;
  for ( i = 0; v1 < c; i = v1 )
  {
    v2 = g_Params_2.items.m_Memory.m_pMemory[v1];
    item = v2;
    if ( v2 != nullptr )
    {
      v3 = g_pSoundEmitterSystem->__vftable;
      v4 = v2->GetName(this: v2);
      v5 = v3->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v4);
      if ( g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v5) )
      {
        v6 = g_pSoundEmitterSystem->InternalGetParametersForSound(this: g_pSoundEmitterSystem, a2: v5);
        if ( v6 == nullptr )
          return;
        CSoundParametersInternal::CSoundParametersInternal(this: &outparams);
        CSoundParametersInternal::CopyFrom(this: &outparams, src: v6);
        GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1007, lpString: sz, cchMax: 128);
        CSoundParametersInternal::ChannelFromString(this: &outparams, sz);
        GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1008, lpString: sz, cchMax: 128);
        CSoundParametersInternal::VolumeFromString(this: &outparams, sz);
        GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1009, lpString: sz, cchMax: 128);
        CSoundParametersInternal::SoundLevelFromString(this: &outparams, sz);
        GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1010, lpString: sz, cchMax: 128);
        CSoundParametersInternal::PitchFromString(this: &outparams, sz);
        DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1017);
        v8 = SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0);
        *((_BYTE *)&outparams + 28) ^= ((v8 == 1) ^ *((_BYTE *)&outparams + 28)) & 1;
        v9 = g_pSoundEmitterSystem->__vftable;
        v10 = ((int (__thiscall *)(CSoundEntry *, CSoundParametersInternal *))item->GetName)(a1: item, a2: &outparams);
        ((void (__thiscall *)(ISoundEmitterSystemBase *, int))v9->UpdateSoundParameters)(
          a1: g_pSoundEmitterSystem,
          a2: v10);
        CSoundParametersInternal::~CSoundParametersInternal(this: &outparams);
      }
    }
    v1 = i + 1;
  }
  WorkspaceManager = GetWorkspaceManager();
  CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
}

//------------------------------------------------------------------------------
// Address: 0x00412AF0
// Name: SoundProperties_MultipleDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall SoundProperties_MultipleDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  CSoundParametersInternal *SoundParameters; // edi
  HWND DlgItem; // eax
  HWND v7; // eax
  WPARAM v8; // [esp-10h] [ebp-14h]

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_2, self: hwndDlg);
    SoundParameters = CSoundEntry::GetSoundParameters(this: *g_Params_2.items.m_Memory.m_pMemory);
    v8 = (*((_BYTE *)SoundParameters + 28) & 1) != 0;
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1017);
    SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: v8, lParam: 0);
    PopulateChannelList_0(wnd: hwndDlg, p: SoundParameters);
    PopulateVolumeList_0(wnd: hwndDlg, p: SoundParameters);
    PopulateSoundlevelList_0(wnd: hwndDlg, p: SoundParameters);
    PopulatePitchList_0(wnd: hwndDlg, p: SoundParameters);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_2.m_szDialogTitle);
    v7 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1007);
    SetFocus(hWnd: v7);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      SoundProperties_Multiple_OnOK(hwndDlg);
      EndDialog(hDlg: hwndDlg, nResult: 1);
      return 0;
    }
    if ( wParam == 2 )
    {
      EndDialog(hDlg: hwndDlg, nResult: 0);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412BD0
// Name: int SoundProperties_Multiple(struct CSoundParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl SoundProperties_Multiple(CSoundParams *params)
{
  int m_Size; // esi
  int i; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  int v5; // esi
  int j; // eax
  HWND Handle; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp-4h] [ebp-14h]
  INT_PTR retval; // [esp+Ch] [ebp-4h]

  qmemcpy(&g_Params_2, params, 0x8Du);
  m_Size = params->items.m_Size;
  g_Params_2.items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(
    this: &g_Params_2.items,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    g_Params_2.items.m_Memory.m_pMemory[i] = params->items.m_Memory.m_pMemory[i];
  WorkspaceManager = GetWorkspaceManager();
  Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  retval = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x77,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)SoundProperties_MultipleDialogProc,
             dwInitParam: 0);
  params->CBaseDialogParams = g_Params_2.CBaseDialogParams;
  params->addsound = g_Params_2.addsound;
  v5 = g_Params_2.items.m_Size;
  v9 = g_Params_2.items.m_Size;
  params->items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(this: &params->items, elem: 0, num: v9);
  for ( j = 0; j < v5; ++j )
    params->items.m_Memory.m_pMemory[j] = g_Params_2.items.m_Memory.m_pMemory[j];
  return retval;
}
