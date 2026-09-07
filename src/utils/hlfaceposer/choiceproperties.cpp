// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choiceproperties.cpp
// Functions: 5
// ============================================================

#include "utils\hlfaceposer\choiceproperties.h"

//------------------------------------------------------------------------------
// Address: 0x00423050
// Name: PopulateChoiceList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateChoiceList(HWND wnd@<eax>, CChoiceParams *params@<edi>)
{
  HWND DlgItem; // eax
  HWND v3; // ebx
  int m_Size; // ecx
  int m_nSelected; // eax
  int v6; // esi
  int c; // [esp+4h] [ebp-4h]
  int ca; // [esp+4h] [ebp-4h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1043);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    m_Size = params->m_Choices.m_Size;
    c = m_Size;
    if ( params->m_nSelected == -1 )
      params->m_nSelected = 0;
    m_nSelected = params->m_nSelected;
    if ( m_nSelected >= 0 && m_nSelected < m_Size )
    {
      SendMessageA(
        hWnd: v3,
        Msg: 0xCu,
        wParam: 0,
        lParam: (LPARAM)params->m_Choices.m_Memory.m_pMemory[m_nSelected].choice);
      m_Size = c;
    }
    if ( m_Size > 0 )
    {
      v6 = 0;
      for ( ca = m_Size; ca != 0; --ca )
        SendMessageA(
          hWnd: v3,
          Msg: 0x143u,
          wParam: 0,
          lParam: (LPARAM)params->m_Choices.m_Memory.m_pMemory[v6++].choice);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004230F0
// Name: ChoicePropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall ChoicePropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND DlgItem; // eax
  int m_Size; // ebx
  int v7; // esi
  int v8; // edi
  char selected[128]; // [esp+8h] [ebp-80h] BYREF

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_3, self: hwndDlg);
    PopulateChoiceList(wnd: hwndDlg, params: &g_Params_3);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1003, lpString: g_Params_3.m_szPrompt);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_3.m_szDialogTitle);
    return 1;
  }
  if ( uMsg != 273 )
    return 0;
  if ( wParam != 1 )
  {
    if ( wParam == 2 )
    {
      EndDialog(hDlg: hwndDlg, nResult: 0);
      return 1;
    }
    return 1;
  }
  selected[0] = 0;
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1043);
  if ( DlgItem != nullptr )
    SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x80u, lParam: (LPARAM)selected);
  m_Size = g_Params_3.m_Choices.m_Size;
  v7 = 0;
  g_Params_3.m_nSelected = -1;
  if ( g_Params_3.m_Choices.m_Size > 0 )
  {
    v8 = 0;
    while ( _V_stricmp(s1: g_Params_3.m_Choices.m_Memory.m_pMemory[v8].choice, s2: selected) != 0 )
    {
      ++v7;
      ++v8;
      if ( v7 >= m_Size )
        goto LABEL_13;
    }
    g_Params_3.m_nSelected = v7;
  }
LABEL_13:
  EndDialog(hDlg: hwndDlg, nResult: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423220
// Name: public: CChoiceParams::CChoiceParams(void)
// Source: json
//------------------------------------------------------------------------------
CChoiceParams *__thiscall CChoiceParams::CChoiceParams(CChoiceParams *this)
{
  this->m_Choices.m_Memory.m_pMemory = nullptr;
  this->m_Choices.m_Memory.m_nAllocationCount = 0;
  this->m_Choices.m_Memory.m_nGrowSize = 0;
  this->m_Choices.m_Size = 0;
  this->m_Choices.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423250
// Name: public: struct CChoiceParams __near & CChoiceParams::operator=(struct CChoiceParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoiceParams *__thiscall CChoiceParams::operator=(CChoiceParams *this, const CChoiceParams *__that)
{
  CChoiceParams *result; // eax
  char *m_szPrompt; // ecx
  int i; // esi
  int m_Size; // esi
  CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int> > *p_m_Choices; // ebx
  int m_nAllocationCount; // ecx
  ChoiceText *m_pMemory; // edx
  int v9; // ecx
  int v10; // edx
  int j; // eax
  ChoiceText *v12; // esi
  ChoiceText *v13; // edi

  result = this;
  this->CBaseDialogParams = __that->CBaseDialogParams;
  m_szPrompt = this->m_szPrompt;
  for ( i = 256; i != 0; --i )
  {
    *m_szPrompt = m_szPrompt[(char *)__that - (char *)this];
    ++m_szPrompt;
  }
  m_Size = __that->m_Choices.m_Size;
  p_m_Choices = &result->m_Choices;
  result->m_Choices.m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = result->m_Choices.m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
    {
      CUtlMemory<ChoiceText,int>::Grow(this: &result->m_Choices.m_Memory, num: m_Size - m_nAllocationCount);
      result = this;
    }
    p_m_Choices->m_Size += m_Size;
    m_pMemory = p_m_Choices->m_Memory.m_pMemory;
    v9 = p_m_Choices->m_Size - m_Size;
    p_m_Choices->m_pElements = p_m_Choices->m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      if ( m_Size <= 0 )
        goto LABEL_13;
      _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: v9 << 7);
      result = this;
    }
    if ( m_Size > 0 )
    {
      v10 = 0;
      for ( j = m_Size; j != 0; --j )
      {
        v12 = &__that->m_Choices.m_Memory.m_pMemory[v10];
        v13 = &p_m_Choices->m_Memory.m_pMemory[v10++];
        qmemcpy(v13, v12, sizeof(ChoiceText));
      }
      result = this;
    }
  }
LABEL_13:
  result->m_nSelected = __that->m_nSelected;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423320
// Name: int ChoiceProperties(struct CChoiceParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl ChoiceProperties(CChoiceParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR v2; // edi
  HWND Handle; // [esp-Ch] [ebp-14h]

  CChoiceParams::operator=(this: &g_Params_3, __that: params);
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v2 = DialogBoxParamA(
         hInstance: ModuleHandleA,
         lpTemplateName: (LPCSTR)0x73,
         hWndParent: Handle,
         lpDialogFunc: (DLGPROC)ChoicePropertiesDialogProc,
         dwInitParam: 0);
  CChoiceParams::operator=(this: params, __that: &g_Params_3);
  return v2;
}
