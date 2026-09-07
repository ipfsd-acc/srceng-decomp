// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_output.cpp
// Functions: 69
// ============================================================

#include "hammer\op_output.h"

//------------------------------------------------------------------------------
// Address: 0x100E6DD0
// Name: public: bool CEntityConnection::CompareConnection(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEntityConnection::CompareConnection(CEntityConnection *this, CEntityConnection *pConnection)
{
  return _V_stricmp(s1: this->m_szOutput, s2: pConnection->m_szOutput) == 0
      && _V_stricmp(s1: this->m_szTargetEntity, s2: pConnection->m_szTargetEntity) == 0
      && _V_stricmp(s1: this->m_szInput, s2: pConnection->m_szInput) == 0
      && _V_stricmp(s1: this->m_szParam, s2: pConnection->m_szParam) == 0
      && this->m_fDelay == pConnection->m_fDelay
      && this->m_nTimesToFire == pConnection->m_nTimesToFire;
}

//------------------------------------------------------------------------------
// Address: 0x100E6E80
// Name: public: virtual struct CRuntimeClass __near * COP_Output::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Output::GetRuntimeClass(COP_Output *this)
{
  return &COP_Output::classCOP_Output;
}

//------------------------------------------------------------------------------
// Address: 0x100E6E90
// Name: public: bool COP_Output::ShouldShowHiddenTargets(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall COP_Output::ShouldShowHiddenTargets(COP_Output *this)
{
  return Options.general.bShowHiddenTargetsAsBroken == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E6EA0
// Name: protected: void COP_Output::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnSize(COP_Output *this, unsigned int nType, unsigned int cx, int cy)
{
  CAnchorMgr::OnSize(this: &this->m_AnchorMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100E6EB0
// Name: protected: void COP_Output::UpdateValidityButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateValidityButton(COP_Output *this)
{
  HWND Parent; // eax
  CObjectProperties *v3; // esi
  LRESULT v4; // eax
  LRESULT v5; // edi
  int v6; // esi
  CObjectProperties *pParent; // [esp+Ch] [ebp-4h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = (CObjectProperties *)CWnd::FromHandle(hWnd: Parent);
  pParent = v3;
  v4 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  v5 = v4;
  if ( v4 != 0 )
  {
    v6 = 0;
    if ( v4 <= 0 )
    {
LABEL_6:
      CObjectProperties::SetOutputButtonState(this: pParent, nState: 1);
    }
    else
    {
      while ( *(_BYTE *)(CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: v6) + 8) != 0 )
      {
        if ( ++v6 >= v5 )
          goto LABEL_6;
      }
      CObjectProperties::SetOutputButtonState(this: pParent, nState: 2);
    }
  }
  else
  {
    CObjectProperties::SetOutputButtonState(this: v3, nState: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6F40
// Name: protected: virtual void COP_Output::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::DoDataExchange(COP_Output *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x594, rControl: (HWND__ *)&this->m_ListCtrl);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: (CDataExchange *)&this->m_fDelay);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x3EF, value: &this->m_strOutput);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x595, value: &this->m_strTarget);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x596, value: &this->m_strInput);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x597, value: &this->m_strParam);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x5D5, value: &this->m_bFireOnce);
  DDX_Control(pDX, nIDC: (HWND__ *)0x670, rControl: (HWND__ *)&this->m_ctlShowHiddenTargetsAsBroken);
  DDX_Control(pDX, nIDC: (HWND__ *)0x56E, rControl: (HWND__ *)&this->m_AddControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x54A, rControl: (HWND__ *)&this->m_PasteControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x519, rControl: (HWND__ *)&this->m_DeleteControl);
}

//------------------------------------------------------------------------------
// Address: 0x100E7020
// Name: protected: void COP_Output::EnableEditControls(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::EnableEditControls(COP_Output *this, bool bValue)
{
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax
  CEdit *pDelayEdit; // [esp+Ch] [ebp-10h]
  CComboBox *pParamCombo; // [esp+10h] [ebp-Ch]
  CAutoSelComboBox *p_m_ComboOutput; // [esp+14h] [ebp-8h]

  p_m_ComboOutput = &this->m_ComboOutput;
  CWnd::EnableWindow(this: &this->m_ComboOutput, bEnable: bValue);
  CFilteredComboBox::EnableWindow(this: &this->m_ComboTarget, bEnable: bValue);
  DlgItem = CWnd::GetDlgItem(this, nID: 1534);
  CWnd::EnableWindow(this: DlgItem, bEnable: bValue);
  CWnd::EnableWindow(this: &this->m_ComboInput, bEnable: bValue);
  v4 = CWnd::GetDlgItem(this, nID: 1493);
  CWnd::EnableWindow(this: v4, bEnable: bValue);
  pDelayEdit = (CEdit *)CWnd::GetDlgItem(this, nID: 1009);
  CWnd::EnableWindow(this: pDelayEdit, bEnable: bValue);
  pParamCombo = (CComboBox *)CWnd::GetDlgItem(this, nID: 1431);
  CWnd::EnableWindow(this: pParamCombo, bEnable: bValue);
  v5 = CWnd::GetDlgItem(this, nID: 1535);
  CWnd::EnableWindow(this: v5, bEnable: bValue);
  if ( !bValue )
  {
    CFilteredComboBox::ForceEditControlText(this: &this->m_ComboTarget, pStr: &var);
    CWnd::SetWindowTextA(this: &this->m_ComboInput, lpszString: &var);
    CWnd::SetWindowTextA(this: p_m_ComboOutput, lpszString: &var);
    SendMessageA(hWnd: pParamCombo->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    CWnd::SetWindowTextA(this: pDelayEdit, lpszString: "0.0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7120
// Name: protected: void COP_Output::ResizeColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::ResizeColumns(COP_Output *this)
{
  if ( SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
  {
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 1u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 2u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 3u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 5u, lParam: 65534);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 6u, lParam: 65534);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 4u, lParam: 0xFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E71D0
// Name: protected: void COP_Output::UpdateColumnHeaderText(int,bool,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateColumnHeaderText(
        COP_Output *this,
        WPARAM nColumn,
        bool bIsSortColumn,
        SortDirection_t eDirection)
{
  unsigned int v5; // eax
  unsigned int v6; // kr00_4
  char v7; // cl
  HWND__ *m_hWnd; // [esp-10h] [ebp-14Ch]
  char szHeaderText[260]; // [esp+Ch] [ebp-130h] BYREF
  tagLVCOLUMNA Column; // [esp+110h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&Column, value: 0, count: sizeof(Column));
  m_hWnd = this->m_ListCtrl.m_hWnd;
  Column.mask = 4;
  Column.pszText = szHeaderText;
  Column.cchTextMax = 260;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1019u, wParam: nColumn, lParam: (LPARAM)&Column);
  v5 = 0;
  if ( szHeaderText[0] != 0 )
  {
    v6 = strlen(szHeaderText);
    v5 = v6;
    v7 = szHeaderText[v6 - 1];
    if ( v7 == 62 || v7 == 60 )
      v5 = v6 - 3;
  }
  if ( bIsSortColumn )
  {
    if ( v5 != 0 )
    {
      *(_WORD *)&szHeaderText[v5] = 8224;
      v5 += 2;
    }
    szHeaderText[v5++] = 2 * (eDirection == Sort_Ascending) + 60;
  }
  szHeaderText[v5] = 0;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Au, wParam: nColumn, lParam: (LPARAM)&Column);
}

//------------------------------------------------------------------------------
// Address: 0x100E72B0
// Name: protected: void COP_Output::FilterEntityOutputs(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::FilterEntityOutputs(COP_Output *this, GDclass *pEntity)
{
  LRESULT v3; // eax
  signed int v4; // esi
  char szText[260]; // [esp+4h] [ebp-104h] BYREF
  GDclass *pClass; // [esp+110h] [ebp+8h]

  pClass = *(GDclass **)&pEntity->m_VariableMap[14][0];
  if ( pClass != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    if ( v3 > 0 )
    {
      v4 = v3 - 1;
      do
      {
        if ( SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x148u, wParam: v4, lParam: (LPARAM)szText) != -1
          && GDclass::FindOutput(this: pClass, szName: szText) == nullptr )
        {
          SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x144u, wParam: v4, lParam: 0);
        }
        --v4;
      }
      while ( v4 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7340
// Name: protected: class CClassInput __near * COP_Output::GetInput(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall COP_Output::GetInput(COP_Output *this, char *szInput, int nSize)
{
  WPARAM v4; // esi
  CClassInput *result; // eax

  *szInput = 0;
  v4 = SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v4 == -1 && CWnd::GetWindowTextA(this: &this->m_ComboInput, lpszString: szInput, nMaxCount: nSize) > 0 )
    v4 = SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)szInput);
  result = nullptr;
  if ( v4 != -1 )
  {
    SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x148u, wParam: v4, lParam: (LPARAM)szInput);
    return (CClassInput *)SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E73D0
// Name: protected: class CClassOutput __near * COP_Output::GetOutput(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall COP_Output::GetOutput(COP_Output *this, char *szOutput, int nSize)
{
  WPARAM v4; // esi
  CClassOutput *result; // eax

  *szOutput = 0;
  v4 = SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v4 == -1 && CWnd::GetWindowTextA(this: &this->m_ComboOutput, lpszString: szOutput, nMaxCount: nSize) > 0 )
    v4 = SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)szOutput);
  result = nullptr;
  if ( v4 != -1 )
  {
    SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x148u, wParam: v4, lParam: (LPARAM)szOutput);
    return (CClassOutput *)SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E7460
// Name: protected: void COP_Output::StopPicking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::StopPicking(COP_Output *this)
{
  CToolManager *v2; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  BOOL m_bEntityParamTarget; // [esp-4h] [ebp-8h]

  if ( this->m_bPickingEntities )
  {
    this->m_bPickingEntities = false;
    v2 = ToolManager();
    CToolManager::SetTool(this: v2, eNewTool: TOOL_POINTER);
    DlgItem = CWnd::GetDlgItem(this, nID: 1534);
    if ( DlgItem != nullptr )
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1535);
    if ( v4 != nullptr )
      SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    if ( CFilteredComboBox::IsWindowEnabled(this: &this->m_ComboTarget) )
    {
      v5 = CWnd::GetDlgItem(this, nID: 1534);
      CWnd::EnableWindow(this: v5, bEnable: 1);
    }
    v6 = CWnd::GetDlgItem(this, nID: 1431);
    if ( CWnd::IsWindowEnabled(this: v6) != 0 )
    {
      m_bEntityParamTarget = this->m_bEntityParamTarget;
      v7 = CWnd::GetDlgItem(this, nID: 1535);
      CWnd::EnableWindow(this: v7, bEnable: m_bEntityParamTarget);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7660
// Name: ListCompareDelays
// Source: json
//------------------------------------------------------------------------------
int __stdcall ListCompareDelays(
        COutputConnection *pOutputConn1,
        COutputConnection *pOutputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareDelays(
           pConn1: *pOutputConn1->m_pConnList->m_Memory.m_pMemory,
           pConn2: *pOutputConn2->m_pConnList->m_Memory.m_pMemory,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E7690
// Name: ListCompareOutputNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall ListCompareOutputNames(
        COutputConnection *pOutputConn1,
        COutputConnection *pOutputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareOutputNames(
           pConn1: *pOutputConn1->m_pConnList->m_Memory.m_pMemory,
           pConn2: *pOutputConn2->m_pConnList->m_Memory.m_pMemory,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E76C0
// Name: ListCompareInputNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall ListCompareInputNames(
        COutputConnection *pOutputConn1,
        COutputConnection *pOutputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareInputNames(
           pConn1: *pOutputConn1->m_pConnList->m_Memory.m_pMemory,
           pConn2: *pOutputConn2->m_pConnList->m_Memory.m_pMemory,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E76F0
// Name: ListCompareTargetNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall ListCompareTargetNames(
        COutputConnection *pOutputConn1,
        COutputConnection *pOutputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareTargetNames(
           pConn1: *pOutputConn1->m_pConnList->m_Memory.m_pMemory,
           pConn2: *pOutputConn2->m_pConnList->m_Memory.m_pMemory,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E7720
// Name: protected: bool COP_Output::ValidateConnections(class COutputConnection __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Output::ValidateConnections(
        COP_Output *this,
        COutputConnection *pOutputConn,
        bool bVisibilityCheck)
{
  COutputConnection *v3; // eax
  int m_Size; // ecx
  int v5; // ebx
  const char *m_szSourceEntity; // esi
  int nCount; // [esp+Ch] [ebp-8h]

  v3 = pOutputConn;
  m_Size = pOutputConn->m_pConnList->m_Size;
  v5 = 0;
  nCount = m_Size;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_szSourceEntity = v3->m_pConnList->m_Memory.m_pMemory[v5]->m_szSourceEntity;
    if ( m_szSourceEntity != nullptr )
      break;
LABEL_7:
    if ( ++v5 >= m_Size )
      return 1;
  }
  if ( CEntityConnection::ValidateOutput(pEntityList: v3->m_pEntityList, pszOutput: m_szSourceEntity + 260) != 0
    && CEntityConnection::ValidateTarget(
         pEntityList: this->m_pMapEntityList,
         bVisibilityCheck,
         pszTarget: m_szSourceEntity + 516) != 0
    && CEntityConnection::ValidateInput(
         pszTarget: (char *)m_szSourceEntity + 516,
         pszInput: m_szSourceEntity + 776,
         bVisiblesOnly: bVisibilityCheck,
         pDoc: nullptr) != 0 )
  {
    v3 = pOutputConn;
    m_Size = nCount;
    goto LABEL_7;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E77C0
// Name: protected: bool COP_Output::ValidateExternalConnections(class COutputConnection __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Output::ValidateExternalConnections(
        COP_Output *this,
        __POSITION *pOutputConn,
        bool bVisibilityCheck)
{
  int v3; // edx
  int v4; // eax
  CEntityConnection **i; // ecx
  const char *v6; // ebx
  char result; // al
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v9; // eax
  void *v10; // eax
  CMapDoc *v11; // eax
  CMapDoc *v12; // esi

  v3 = *(_DWORD *)(*(_DWORD *)pOutputConn + 12);
  v4 = 0;
  if ( v3 <= 0 )
    return 1;
  for ( i = **(CEntityConnection ****)pOutputConn; ; ++i )
  {
    v6 = (const char *)*i;
    if ( *i != nullptr )
      break;
    if ( ++v4 >= v3 )
      return 1;
  }
  result = CEntityConnection::ValidateOutput(
             pEntityList: *(const CUtlReferenceVector<CMapEntity> **)&pOutputConn[4],
             pszOutput: v6 + 260);
  if ( result != 0 )
  {
    ModuleState = AfxGetModuleState();
    pOutputConn = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                    + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
    if ( pOutputConn != nullptr )
    {
      while ( 1 )
      {
        v9 = AfxGetModuleState();
        v10 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v9->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                         + 88))(
                        a1: v9->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                        a2: &pOutputConn);
        v11 = (CMapDoc *)__RTDynamicCast(
                           inptr: v10,
                           VfDelta: 0,
                           SrcType: &CDocument `RTTI Type Descriptor',
                           TargetType: &CMapDoc `RTTI Type Descriptor',
                           isReference: 0);
        v12 = v11;
        if ( v11 != nullptr
          && CEntityConnection::ValidateTarget(
               pEntityList: &v11->m_pWorld->m_EntityList,
               bVisibilityCheck,
               pszTarget: v6 + 516) == 1
          && CEntityConnection::ValidateInput(
               pszTarget: (char *)v6 + 516,
               pszInput: v6 + 776,
               bVisiblesOnly: bVisibilityCheck,
               pDoc: v12) == 1 )
        {
          break;
        }
        if ( pOutputConn == nullptr )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E78B0
// Name: public: static void COP_Output::EmptyCopyBuffer(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl COP_Output::EmptyCopyBuffer()
{
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *v0; // eax
  int m_Size; // ebx
  int v2; // edi
  CEntityConnection *v3; // esi

  v0 = COP_Output::m_pConnectionBuffer;
  m_Size = COP_Output::m_pConnectionBuffer->m_Size;
  v2 = 0;
  if ( m_Size <= 0 )
  {
    COP_Output::m_pConnectionBuffer->m_Size = 0;
  }
  else
  {
    do
    {
      v3 = v0->m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        CEntityConnection::~CEntityConnection(this: v0->m_Memory.m_pMemory[v2]);
        operator delete(p: v3);
        v0 = COP_Output::m_pConnectionBuffer;
      }
      ++v2;
    }
    while ( v2 < m_Size );
    v0->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7900
// Name: protected: void COP_Output::OnPickEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnPickEntity(COP_Output *this)
{
  CWnd *DlgItem; // eax
  CToolManager *v3; // eax
  CToolManager *v4; // eax
  CWnd *v5; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1534);
  if ( DlgItem != nullptr )
  {
    if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
    {
      this->m_bPickingEntities = true;
      this->m_PickEntityTarget.m_nDlgItem = 1429;
      v3 = ToolManager();
      CToolManager::GetToolForID(this: v3, eToolID: TOOL_PICK_ENTITY)[1].__vftable = (CBaseTool_vtbl *)&this->m_PickEntityTarget;
      v4 = ToolManager();
      CToolManager::SetTool(this: v4, eNewTool: TOOL_PICK_ENTITY);
      v5 = CWnd::GetDlgItem(this, nID: 1535);
      CWnd::EnableWindow(this: v5, bEnable: 0);
    }
    else
    {
      COP_Output::StopPicking(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7980
// Name: protected: void COP_Output::OnPickEntityParam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnPickEntityParam(COP_Output *this)
{
  CWnd *DlgItem; // eax
  CToolManager *v3; // eax
  CToolManager *v4; // eax
  CWnd *v5; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1535);
  if ( DlgItem != nullptr )
  {
    if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
    {
      this->m_bPickingEntities = true;
      this->m_PickEntityTarget.m_nDlgItem = 1431;
      v3 = ToolManager();
      CToolManager::GetToolForID(this: v3, eToolID: TOOL_PICK_ENTITY)[1].__vftable = (CBaseTool_vtbl *)&this->m_PickEntityTarget;
      v4 = ToolManager();
      CToolManager::SetTool(this: v4, eNewTool: TOOL_PICK_ENTITY);
      v5 = CWnd::GetDlgItem(this, nID: 1534);
      CWnd::EnableWindow(this: v5, bEnable: 0);
    }
    else
    {
      COP_Output::StopPicking(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7A00
// Name: protected: void COP_Output::SortListByColumn(int,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SortListByColumn(COP_Output *this, int nColumn, WPARAM eDirection)
{
  int (__stdcall *v3)(COutputConnection *, COutputConnection *, SortDirection_t); // eax

  switch ( nColumn )
  {
    case 1:
      v3 = ListCompareOutputNames;
      goto LABEL_6;
    case 2:
      v3 = ListCompareTargetNames;
      goto LABEL_6;
    case 3:
      v3 = ListCompareInputNames;
      goto LABEL_6;
    case 5:
      v3 = ListCompareDelays;
LABEL_6:
      if ( v3 != nullptr )
        SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1030u, wParam: eDirection, lParam: (LPARAM)v3);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7A60
// Name: protected: void COP_Output::UpdateEditedFireOnce(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedFireOnce(COP_Output *this)
{
  CWnd *DlgItem; // edi
  char v3; // al
  int m_Size; // edi
  int i; // eax
  CEntityConnection *v6; // ecx
  signed int j; // edi
  char *v8; // eax
  int nChecked; // [esp+8h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1493);
  if ( CWnd::IsWindowEnabled(this: DlgItem) != 0 )
  {
    v3 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF2u, wParam: 0, lParam: 0);
    m_Size = this->m_EditList.m_Size;
    nChecked = v3 & 3;
    for ( i = 0; i < m_Size; ++i )
    {
      v6 = this->m_EditList.m_Memory.m_pMemory[i];
      if ( v6 != nullptr )
        v6->m_nTimesToFire = 2 * (nChecked != 0) - 1;
    }
    for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
    {
      if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: j, lParam: 2) & 2) != 0 )
      {
        v8 = "Yes";
        if ( nChecked == 0 )
          v8 = "No";
        CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: j, nSubItem: 6, lpszText: v8);
      }
    }
    COP_Output::ResizeColumns(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7B50
// Name: protected: void COP_Output::UpdateEditedDelays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedDelays(COP_Output *this)
{
  CWnd *DlgItem; // edi
  int m_Size; // edx
  float v4; // xmm0_4
  int v5; // eax
  CEntityConnection *v6; // ecx
  CEntityConnection *v7; // ecx
  CEntityConnection *v8; // ecx
  CEntityConnection *v9; // ecx
  CEntityConnection *v10; // ecx
  signed int i; // edi
  char strDelay[256]; // [esp+8h] [ebp-104h] BYREF
  float flDelay; // [esp+108h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1009);
  if ( CWnd::IsWindowEnabled(this: DlgItem) != 0 )
  {
    CWnd::GetWindowTextA(this: DlgItem, lpszString: strDelay, nMaxCount: 256);
    flDelay = atof(nptr: strDelay);
    m_Size = this->m_EditList.m_Size;
    v4 = flDelay;
    v5 = 0;
    if ( m_Size >= 4 )
    {
      do
      {
        v6 = this->m_EditList.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
          v6->m_fDelay = v4;
        v7 = this->m_EditList.m_Memory.m_pMemory[v5 + 1];
        if ( v7 != nullptr )
          v7->m_fDelay = v4;
        v8 = this->m_EditList.m_Memory.m_pMemory[v5 + 2];
        if ( v8 != nullptr )
          v8->m_fDelay = v4;
        v9 = this->m_EditList.m_Memory.m_pMemory[v5 + 3];
        if ( v9 != nullptr )
          v9->m_fDelay = v4;
        v5 += 4;
      }
      while ( v5 < m_Size - 3 );
    }
    for ( ; v5 < m_Size; ++v5 )
    {
      v10 = this->m_EditList.m_Memory.m_pMemory[v5];
      if ( v10 != nullptr )
        v10->m_fDelay = v4;
    }
    for ( i = 0; i < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++i )
    {
      if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: i, lParam: 2) & 2) != 0 )
        CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: i, nSubItem: 5, lpszText: strDelay);
    }
    COP_Output::ResizeColumns(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7CA0
// Name: protected: void COP_Output::UpdateEditedParams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedParams(COP_Output *this)
{
  CWnd *DlgItem; // esi
  int m_Size; // ebx
  int i; // esi
  CEntityConnection *v5; // eax
  signed int j; // esi
  char strParam[256]; // [esp+8h] [ebp-100h] BYREF

  DlgItem = CWnd::GetDlgItem(this, nID: 1431);
  if ( CWnd::IsWindowEnabled(this: DlgItem) != 0 )
  {
    CWnd::GetWindowTextA(this: DlgItem, lpszString: strParam, nMaxCount: 256);
    if ( strcmp(strParam, PARAM_STRING_NONE) == 0 )
      strParam[0] = 0;
    m_Size = this->m_EditList.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v5 = this->m_EditList.m_Memory.m_pMemory[i];
      if ( v5 != nullptr )
        lstrcpynA(lpString1: v5->m_szParam, lpString2: strParam, iMaxLength: 256);
    }
    for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
    {
      if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: j, lParam: 2) & 2) != 0 )
        CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: j, nSubItem: 4, lpszText: strParam);
    }
    COP_Output::ResizeColumns(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7DC0
// Name: protected: void COP_Output::OnEditDelay(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COP_Output::OnEditDelay(COP_Output *this)
{
  COP_Output::UpdateEditedDelays(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E7DD0
// Name: protected: void COP_Output::OnFireOnce(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COP_Output::OnFireOnce(COP_Output *this)
{
  COP_Output::UpdateEditedFireOnce(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E7DE0
// Name: protected: void COP_Output::OnSelChangeParam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnSelChangeParam(COP_Output *this)
{
  CWnd *DlgItem; // esi

  DlgItem = CWnd::GetDlgItem(this, nID: 1431);
  if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) != -1 )
    CWnd::SetWindowTextA(this: DlgItem, lpszString: &var);
  COP_Output::UpdateEditedParams(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E7E20
// Name: protected: void COP_Output::OnEditUpdateParam(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COP_Output::OnEditUpdateParam(COP_Output *this)
{
  COP_Output::UpdateEditedParams(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E84E0
// Name: protected: void COP_Output::UpdateItemValidity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateItemValidity(COP_Output *this, int nItem)
{
  __POSITION *ItemData; // edi
  _DWORD *v4; // ebx
  int v5; // esi
  int v6; // eax
  CListCtrl *p_m_ListCtrl; // [esp+Ch] [ebp-Ch]
  bool bShowHiddenTargets; // [esp+13h] [ebp-5h]
  bool bShared; // [esp+17h] [ebp-1h]

  p_m_ListCtrl = &this->m_ListCtrl;
  ItemData = (__POSITION *)CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem);
  v4 = *(_DWORD **)ItemData;
  bShared = this->m_EntityList.m_Size == *(_DWORD *)(*(_DWORD *)ItemData + 12);
  bShowHiddenTargets = Options.general.bShowHiddenTargetsAsBroken == 1;
  if ( COP_Output::ValidateConnections(
         this,
         pOutputConn: (COutputConnection *)ItemData,
         bVisibilityCheck: Options.general.bShowHiddenTargetsAsBroken == 1) != 0 )
  {
    if ( bShowHiddenTargets )
    {
LABEL_7:
      ItemData[8] = (__POSITION)1;
      v6 = 2 * !bShared + 1;
      goto LABEL_11;
    }
    v5 = 0;
    if ( (int)v4[3] > 0 )
    {
      while ( CEntityConnection::AreAnyTargetEntitiesVisible(this: *(CEntityConnection **)(*v4 + 4 * v5)) == 0 )
      {
        if ( ++v5 >= v4[3] )
          goto LABEL_6;
      }
      goto LABEL_7;
    }
LABEL_6:
    v6 = 3;
    ItemData[8] = (__POSITION)1;
  }
  else if ( COP_Output::ValidateExternalConnections(this, pOutputConn: ItemData, bVisibilityCheck: bShowHiddenTargets) == 1 )
  {
    v6 = 4;
    ItemData[8] = (__POSITION)1;
  }
  else
  {
    ItemData[8] = 0;
    v6 = bShared ? 0 : 2;
  }
LABEL_11:
  CListCtrl::SetItem(
    this: p_m_ListCtrl,
    nItem,
    nSubItem: 0,
    nMask: 2u,
    lpszItem: nullptr,
    nImage: v6,
    nState: 0,
    nStateMask: 0,
    lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E85C0
// Name: protected: void COP_Output::SetSortColumn(int,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SetSortColumn(COP_Output *this, int nColumn, SortDirection_t eDirection)
{
  WPARAM m_nSortColumn; // eax
  int v5; // eax
  int v6; // eax
  WPARAM v7; // ecx
  int (__stdcall *v8)(COutputConnection *, COutputConnection *, SortDirection_t); // eax

  m_nSortColumn = this->m_nSortColumn;
  if ( m_nSortColumn != nColumn )
    COP_Output::UpdateColumnHeaderText(this, nColumn: m_nSortColumn, bIsSortColumn: false, eDirection);
  v5 = this->m_nSortColumn;
  if ( v5 != nColumn || this->m_eSortDirection[v5] != eDirection )
    COP_Output::UpdateColumnHeaderText(this, nColumn, bIsSortColumn: true, eDirection);
  this->m_nSortColumn = nColumn;
  this->m_eSortDirection[nColumn] = eDirection;
  v6 = this->m_nSortColumn;
  v7 = this->m_eSortDirection[v6];
  switch ( v6 )
  {
    case 1:
      v8 = ListCompareOutputNames;
      goto LABEL_11;
    case 2:
      v8 = ListCompareTargetNames;
      goto LABEL_11;
    case 3:
      v8 = ListCompareInputNames;
      goto LABEL_11;
    case 5:
      v8 = ListCompareDelays;
LABEL_11:
      if ( v8 != nullptr )
        SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1030u, wParam: v7, lParam: (LPARAM)v8);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8680
// Name: protected: void COP_Output::UpdateEditedInputs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedInputs(COP_Output *this)
{
  int m_Size; // ebx
  int i; // edi
  CEntityConnection *v4; // eax
  LRESULT j; // edi
  char strInput[256]; // [esp+Ch] [ebp-100h] BYREF

  COP_Output::GetInput(this, szInput: strInput, nSize: 256);
  m_Size = this->m_EditList.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_EditList.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
      lstrcpynA(lpString1: v4->m_szInput, lpString2: strInput, iMaxLength: 256);
  }
  for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
  {
    if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: j, lParam: 2) & 2) != 0 )
    {
      CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: j, nSubItem: 3, lpszText: strInput);
      COP_Output::UpdateItemValidity(this, nItem: j);
    }
  }
  COP_Output::UpdateValidityButton(this);
  COP_Output::ResizeColumns(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E8760
// Name: protected: void COP_Output::UpdateEditedOutputs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedOutputs(COP_Output *this)
{
  int m_Size; // ebx
  int i; // edi
  CEntityConnection *v4; // eax
  LRESULT j; // edi
  char strOutput[256]; // [esp+Ch] [ebp-100h] BYREF

  COP_Output::GetOutput(this, szOutput: strOutput, nSize: 256);
  m_Size = this->m_EditList.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_EditList.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
      lstrcpynA(lpString1: v4->m_szOutput, lpString2: strOutput, iMaxLength: 256);
  }
  for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
  {
    if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: j, lParam: 2) & 2) != 0 )
    {
      CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: j, nSubItem: 1, lpszText: strOutput);
      COP_Output::UpdateItemValidity(this, nItem: j);
    }
  }
  COP_Output::UpdateValidityButton(this);
  COP_Output::ResizeColumns(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E8840
// Name: protected: void COP_Output::OnShowHiddenTargetsAsBroken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnShowHiddenTargetsAsBroken(COP_Output *this)
{
  LRESULT v2; // ebx
  int i; // esi

  Options.general.bShowHiddenTargetsAsBroken = SendMessageA(
                                                 hWnd: this->m_ctlShowHiddenTargetsAsBroken.m_hWnd,
                                                 Msg: 0xF0u,
                                                 wParam: 0,
                                                 lParam: 0) != 0;
  v2 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  for ( i = 0; i < v2; ++i )
    COP_Output::UpdateItemValidity(this, nItem: i);
}

//------------------------------------------------------------------------------
// Address: 0x100E88A0
// Name: protected: void COP_Output::OnSelChangeOutput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnSelChangeOutput(COP_Output *this)
{
  CClassOutput *Output; // eax
  CAutoSelComboBox *p_m_ComboOutput; // ecx
  char szOutput[256]; // [esp+4h] [ebp-100h] BYREF

  this->bSkipEditControlRefresh = true;
  Output = COP_Output::GetOutput(this, szOutput, nSize: 256);
  p_m_ComboOutput = &this->m_ComboOutput;
  if ( Output != nullptr )
    CAutoSelComboBox::SetTextColor(this: p_m_ComboOutput, dwColor: 0);
  else
    CAutoSelComboBox::SetTextColor(this: p_m_ComboOutput, dwColor: 0xFFu);
  RedrawWindow(hWnd: this->m_ComboOutput.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  COP_Output::UpdateEditedOutputs(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E91B0
// Name: protected: void COP_Output::UpdateEditedTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditedTargets(COP_Output *this)
{
  char *v2; // eax
  int m_Size; // ebx
  int i; // edi
  CEntityConnection *v5; // ecx
  LRESULT j; // edi
  char strTarget[256]; // [esp+Ch] [ebp-110h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10Ch] [ebp-10h] BYREF
  int v9; // [esp+118h] [ebp-4h]

  strTarget[0] = 0;
  CFilteredComboBox::GetCurrentItem(this: &this->m_ComboTarget, &result);
  v9 = 0;
  V_strncpy(pDest: strTarget, pSrc: result.m_pszData, maxLen: 256);
  CTargetNameComboBox::GetSubEntityList(this: &this->m_ComboTarget, pName: strTarget);
  v9 = -1;
  v2 = result.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v2 + 4))(a1: v2);
  m_Size = this->m_EditList.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->m_EditList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      CEntityConnection::SetTargetName(this: v5, pszName: strTarget);
  }
  for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
  {
    if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: j, lParam: 2) & 2) != 0 )
    {
      CListCtrl::SetItemText(this: &this->m_ListCtrl, nItem: j, nSubItem: 2, lpszText: strTarget);
      COP_Output::UpdateItemValidity(this, nItem: j);
    }
  }
  COP_Output::UpdateValidityButton(this);
  COP_Output::ResizeColumns(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E9300
// Name: protected: void COP_Output::FilterInputList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::FilterInputList(COP_Output *this)
{
  CUtlReferenceVector<CMapEntity> *SubEntityList; // edi
  char *v3; // eax
  LRESULT v4; // eax
  signed int v5; // edi
  LRESULT v6; // eax
  char szTarget[256]; // [esp+8h] [ebp-114h] BYREF
  CUtlReferenceVector<CMapEntity> *pList; // [esp+108h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10Ch] [ebp-10h] BYREF
  int v10; // [esp+118h] [ebp-4h]

  szTarget[0] = 0;
  CFilteredComboBox::GetCurrentItem(this: &this->m_ComboTarget, &result);
  v10 = 0;
  V_strncpy(pDest: szTarget, pSrc: result.m_pszData, maxLen: 256);
  SubEntityList = CTargetNameComboBox::GetSubEntityList(this: &this->m_ComboTarget, pName: szTarget);
  pList = SubEntityList;
  v10 = -1;
  v3 = result.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
  if ( SubEntityList != nullptr && !this->m_bIsInstanceIOProxy )
  {
    v4 = SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    if ( v4 > 0 )
    {
      v5 = v4 - 1;
      do
      {
        v6 = SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x150u, wParam: v5, lParam: 0);
        if ( !MapEntityList_HasInput(pList, szInput: (const char *)(v6 + 4), eType: *(InputOutputType_t *)(v6 + 260)) )
          SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x144u, wParam: v5, lParam: 0);
        --v5;
      }
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9490
// Name: protected: void COP_Output::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnCopy(COP_Output *this)
{
  COP_Output *v1; // ebx
  LRESULT (__stdcall *v2)(HWND, UINT, WPARAM, LPARAM); // edi
  LRESULT v3; // eax
  int v4; // esi
  const CEntityConnection ***v5; // eax
  const CEntityConnection *v6; // edi
  CEntityConnection *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *p_m_Size; // esi
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *v11; // ebx
  CEntityConnection **m_pMemory; // ecx
  int v13; // eax
  CEntityConnection **v14; // ecx
  CEntityConnection **v15; // edi
  int nItem; // [esp+10h] [ebp-14h]
  CEntityConnection *v18; // [esp+14h] [ebp-10h]

  v1 = this;
  COP_Output::EmptyCopyBuffer();
  v2 = SendMessageA;
  if ( SendMessageA(hWnd: v1->m_ListCtrl.m_hWnd, Msg: 0x1032u, wParam: 0, lParam: 0) != 0 )
  {
    v3 = SendMessageA(hWnd: v1->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
    if ( v3 > 0 )
    {
      v4 = v3 - 1;
      nItem = v3 - 1;
      while ( 1 )
      {
        if ( (v2(hWnd: v1->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v4, lParam: 2) & 2) != 0 )
        {
          v5 = *(const CEntityConnection ****)CListCtrl::GetItemData(this: &v1->m_ListCtrl, nItem: v4);
          if ( v5 != nullptr )
          {
            v6 = **v5;
            if ( v6 != nullptr )
            {
              v7 = (CEntityConnection *)operator new(nSize: 0x510u);
              if ( v7 != nullptr )
                v18 = CEntityConnection::CEntityConnection(this: v7);
              else
                v18 = nullptr;
              CEntityConnection::operator=(this: v18, Other: v6);
              m_Size = COP_Output::m_pConnectionBuffer->m_Size;
              m_nAllocationCount = COP_Output::m_pConnectionBuffer->m_Memory.m_nAllocationCount;
              p_m_Size = &COP_Output::m_pConnectionBuffer->m_Size;
              v11 = COP_Output::m_pConnectionBuffer;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<CVisGroup *,int>::Grow(
                  this: (CUtlMemory<CCullTreeNode *,int> *)COP_Output::m_pConnectionBuffer,
                  num: m_Size - m_nAllocationCount + 1);
              ++*p_m_Size;
              m_pMemory = v11->m_Memory.m_pMemory;
              v13 = *p_m_Size - m_Size - 1;
              v11->m_pElements = v11->m_Memory.m_pMemory;
              if ( v13 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
              v14 = v11->m_Memory.m_pMemory;
              v4 = nItem;
              v1 = this;
              v15 = &v14[m_Size];
              if ( v15 != nullptr )
                *v15 = v18;
            }
          }
        }
        nItem = --v4;
        if ( v4 < 0 )
          break;
        v2 = SendMessageA;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9690
// Name: protected: void COP_Output::UpdateCombosForSelectedInput(class CClassInput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateCombosForSelectedInput(COP_Output *this, CClassInput *pInput)
{
  CWnd *DlgItem; // esi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  bool v7; // al
  char *v8; // eax
  CWnd *v9; // eax
  CAutoSelComboBox *p_m_ComboInput; // ecx
  int v11; // [esp-4h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTemp; // [esp+8h] [ebp-10h] BYREF
  int v13; // [esp+14h] [ebp-4h]
  unsigned __int8 bEnable_3; // [esp+23h] [ebp+Bh]

  if ( !this->m_bNoParamEdit )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1431);
    if ( pInput == nullptr || pInput->m_eType != iotVoid )
    {
      m_pszData = this->m_strLastParam.m_pszData;
      bEnable_3 = 1;
      if ( *((_DWORD *)m_pszData - 3) != 0 )
        CWnd::SetWindowTextA(this: DlgItem, lpszString: m_pszData);
    }
    else
    {
      bEnable_3 = 0;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      strTemp.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      v13 = 1;
      CWnd::GetWindowTextA(this: DlgItem, rString: &strTemp);
      if ( PARAM_STRING_NONE == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      if ( _mbscmp(s1: (const unsigned __int8 *)strTemp.m_pszData, s2: (const unsigned __int8 *)PARAM_STRING_NONE) != 0 )
        ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strLastParam, strSrc: (ATL::CStringData *)&strTemp);
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
      v13 = -1;
      v8 = strTemp.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)strTemp.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
    }
    COP_Output::UpdateEditedParams(this);
    CWnd::EnableWindow(this: DlgItem, bEnable: bEnable_3);
    v7 = pInput != nullptr && pInput->m_eType == iotEHandle;
    v11 = v7;
    this->m_bEntityParamTarget = v7;
    v9 = CWnd::GetDlgItem(this, nID: 1535);
    CWnd::EnableWindow(this: v9, bEnable: v11);
  }
  p_m_ComboInput = &this->m_ComboInput;
  if ( pInput != nullptr )
    CAutoSelComboBox::SetTextColor(this: p_m_ComboInput, dwColor: 0);
  else
    CAutoSelComboBox::SetTextColor(this: p_m_ComboInput, dwColor: 0xFFu);
  RedrawWindow(hWnd: this->m_ComboInput.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x100E98B0
// Name: protected: void COP_Output::SetConnection(class CUtlVector<class CEntityConnection __near *,class CUtlMemory<class CEntityConnection __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SetConnection(
        COP_Output *this,
        CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *pConnectionList)
{
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  int m_Size; // ecx
  int v6; // eax
  CEntityConnection *v7; // edi
  bool v8; // zf
  const char *m_szOutput; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strOutput; // ecx
  const char *m_szTargetEntity; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strTarget; // ecx
  CWnd *v13; // eax
  const char *m_szInput; // edi
  int v15; // eax
  CWnd *v16; // eax
  int v17; // eax
  int nConnCount; // [esp+Ch] [ebp-1Ch]
  CButton *pFireEdit; // [esp+10h] [ebp-18h]
  CEdit *pDelayEdit; // [esp+14h] [ebp-14h]
  int nConn; // [esp+18h] [ebp-10h]
  CComboBox *pParamEdit; // [esp+1Ch] [ebp-Ch]
  CEntityConnection *pConnection; // [esp+20h] [ebp-8h]
  bool bFirst; // [esp+27h] [ebp-1h]

  bFirst = true;
  pFireEdit = (CButton *)CWnd::GetDlgItem(this, nID: 1493);
  pDelayEdit = (CEdit *)CWnd::GetDlgItem(this, nID: 1009);
  pParamEdit = (CComboBox *)CWnd::GetDlgItem(this, nID: 1431);
  CWnd::EnableWindow(this: &this->m_ComboOutput, bEnable: 1);
  CFilteredComboBox::EnableWindow(this: &this->m_ComboTarget, bEnable: true);
  DlgItem = CWnd::GetDlgItem(this, nID: 1534);
  CWnd::EnableWindow(this: DlgItem, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_ComboInput, bEnable: 1);
  CWnd::EnableWindow(this: pFireEdit, bEnable: 1);
  CWnd::EnableWindow(this: pDelayEdit, bEnable: 1);
  CWnd::EnableWindow(this: pParamEdit, bEnable: 1);
  v4 = CWnd::GetDlgItem(this, nID: 1535);
  CWnd::EnableWindow(this: v4, bEnable: 0);
  this->m_bEntityParamTarget = false;
  m_Size = pConnectionList->m_Size;
  v6 = 0;
  nConnCount = m_Size;
  for ( nConn = 0; v6 < m_Size; nConn = v6 )
  {
    v7 = pConnectionList->m_Memory.m_pMemory[v6];
    pConnection = v7;
    if ( v7 != nullptr )
    {
      if ( CWnd::IsWindowEnabled(this: &this->m_ComboOutput) != 0 )
      {
        if ( bFirst )
        {
          v8 = v7->m_szOutput == nullptr;
          m_szOutput = v7->m_szOutput;
          p_m_strOutput = &this->m_strOutput;
          if ( v8 )
            ATL::CSimpleStringT<char,0>::SetString(this: p_m_strOutput, pszSrc: m_szOutput, nLength: 0);
          else
            ATL::CSimpleStringT<char,0>::SetString(this: p_m_strOutput, pszSrc: m_szOutput, nLength: strlen(m_szOutput));
        }
        else
        {
          if ( v7 == (CEntityConnection *)-260 )
            goto LABEL_55;
          if ( _mbscmp(
                 s1: (const unsigned __int8 *)this->m_strOutput.m_pszData,
                 s2: (const unsigned __int8 *)v7->m_szOutput) != 0 )
          {
            ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strOutput);
            CWnd::EnableWindow(this: &this->m_ComboOutput, bEnable: 0);
          }
        }
        v7 = pConnection;
      }
      if ( CFilteredComboBox::IsWindowEnabled(this: &this->m_ComboTarget) )
      {
        if ( bFirst )
        {
          v8 = v7->m_szTargetEntity == nullptr;
          m_szTargetEntity = v7->m_szTargetEntity;
          p_m_strTarget = &this->m_strTarget;
          if ( v8 )
            ATL::CSimpleStringT<char,0>::SetString(this: p_m_strTarget, pszSrc: m_szTargetEntity, nLength: 0);
          else
            ATL::CSimpleStringT<char,0>::SetString(
              this: p_m_strTarget,
              pszSrc: m_szTargetEntity,
              nLength: strlen(m_szTargetEntity));
        }
        else
        {
          if ( v7 == (CEntityConnection *)-516 )
            goto LABEL_55;
          if ( _mbscmp(
                 s1: (const unsigned __int8 *)this->m_strTarget.m_pszData,
                 s2: (const unsigned __int8 *)v7->m_szTargetEntity) != 0 )
          {
            ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strTarget);
            CFilteredComboBox::EnableWindow(this: &this->m_ComboTarget, bEnable: false);
            v13 = CWnd::GetDlgItem(this, nID: 1534);
            CWnd::EnableWindow(this: v13, bEnable: 0);
          }
        }
        v7 = pConnection;
      }
      if ( CWnd::IsWindowEnabled(this: &this->m_ComboInput) != 0 )
      {
        if ( bFirst )
        {
          m_szInput = v7->m_szInput;
          if ( m_szInput != nullptr )
            ATL::CSimpleStringT<char,0>::SetString(
              this: &this->m_strInput,
              pszSrc: m_szInput,
              nLength: strlen(m_szInput));
          else
            ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strInput, pszSrc: nullptr, nLength: 0);
        }
        else
        {
          if ( v7 == (CEntityConnection *)-776 )
            goto LABEL_55;
          if ( _mbscmp(
                 s1: (const unsigned __int8 *)this->m_strInput.m_pszData,
                 s2: (const unsigned __int8 *)v7->m_szInput) != 0 )
          {
            ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strInput);
            CWnd::EnableWindow(this: &this->m_ComboInput, bEnable: 0);
          }
        }
        v7 = pConnection;
      }
      if ( CWnd::IsWindowEnabled(this: pParamEdit) != 0 )
      {
        if ( bFirst )
        {
          if ( v7 == (CEntityConnection *)-1032 )
            v15 = 0;
          else
            v15 = strlen(v7->m_szParam);
          ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strParam, pszSrc: v7->m_szParam, nLength: v15);
          this->m_bNoParamEdit = false;
        }
        else
        {
          if ( v7 == (CEntityConnection *)-1032 )
LABEL_55:
            ATL::AtlThrowImpl(hr: -2147467259);
          if ( _mbscmp(
                 s1: (const unsigned __int8 *)this->m_strParam.m_pszData,
                 s2: (const unsigned __int8 *)v7->m_szParam) != 0 )
          {
            ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strParam);
            CWnd::EnableWindow(this: pParamEdit, bEnable: 0);
            v16 = CWnd::GetDlgItem(this, nID: 1535);
            CWnd::EnableWindow(this: v16, bEnable: 0);
            this->m_bNoParamEdit = true;
          }
        }
        v7 = pConnection;
      }
      if ( CWnd::IsWindowEnabled(this: pDelayEdit) != 0 )
      {
        if ( bFirst )
        {
          this->m_fDelay = v7->m_fDelay;
        }
        else if ( this->m_fDelay != v7->m_fDelay )
        {
          this->m_fDelay = 0.0;
          CWnd::EnableWindow(this: pDelayEdit, bEnable: 0);
        }
      }
      if ( CWnd::IsWindowEnabled(this: pFireEdit) != 0 )
      {
        if ( bFirst )
        {
          this->m_bFireOnce = v7->m_nTimesToFire != -1;
        }
        else if ( this->m_bFireOnce != v7->m_nTimesToFire )
        {
          this->m_bFireOnce = 0;
          CWnd::EnableWindow(this: pFireEdit, bEnable: 0);
        }
      }
      m_Size = nConnCount;
      v6 = nConn;
      bFirst = false;
    }
    ++v6;
  }
  v17 = strlen(this->m_strParam.m_pszData);
  if ( v17 == 0 )
  {
    if ( PARAM_STRING_NONE != nullptr )
      v17 = strlen(PARAM_STRING_NONE);
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strParam, pszSrc: PARAM_STRING_NONE, nLength: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9CD0
// Name: protected: void COP_Output::OnEditUpdateInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnEditUpdateInput(COP_Output *this)
{
  CClassInput *Input; // eax
  char szInput[256]; // [esp+4h] [ebp-100h] BYREF

  this->bSkipEditControlRefresh = true;
  Input = COP_Output::GetInput(this, szInput, nSize: 256);
  COP_Output::UpdateCombosForSelectedInput(this, pInput: Input);
  COP_Output::UpdateEditedInputs(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E9D10
// Name: protected: void COP_Output::UpdateEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEntityList(COP_Output *this)
{
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int i; // edi
  CMapEntity *m_pObject; // esi
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> src; // [esp+8h] [ebp-1Ch] BYREF
  COP_Output *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v7 = this;
  CUtlReferenceVector<CMapEntity>::RemoveAll(this: &this->m_EntityList);
  m_pObjectList = this->m_pObjectList;
  if ( m_pObjectList != nullptr )
  {
    for ( i = 0; i < m_pObjectList->m_Size; ++i )
    {
      m_pObject = (CMapEntity *)m_pObjectList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory
                                                                                          + 2) >> 27)][i & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr && m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0 )
      {
        m_pHead = m_pObject->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = m_pObject;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
        v8 = 0;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: &v7->m_EntityList,
          elem: v7->m_EntityList.m_Size,
          &src);
        v8 = -1;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
      }
      m_pObjectList = v7->m_pObjectList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9E60
// Name: public: COP_Output::COP_Output(void)
// Source: json
//------------------------------------------------------------------------------
COP_Output *__thiscall COP_Output::COP_Output(COP_Output *this)
{
  CEntityConnection **m_pMemory; // ecx
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax
  CAfxStringMgr *v7; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x12Cu, nIDCaption: 0, dwSize: 0x38u);
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Output_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CFilteredComboBox::ICallbacks::`vftable';
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Output_vtbl *)&COP_Output::`vftable'{for `CObjectPage'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&COP_Output::`vftable'{for `CFilteredComboBox::ICallbacks'};
  this->m_EntityList.m_Memory.m_pMemory = nullptr;
  this->m_EntityList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_EntityList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&this->m_EntityList,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_EntityList.m_Size = 0;
  this->m_EntityList.m_pElements = nullptr;
  this->m_EditList.m_Memory.m_pMemory = nullptr;
  this->m_EditList.m_Memory.m_nAllocationCount = 0;
  this->m_EditList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_EditList.m_Memory.m_pMemory;
  this->m_EditList.m_Size = 0;
  this->m_EditList.m_pElements = m_pMemory;
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  CWnd::CWnd(this: &this->m_ListCtrl);
  this->m_ListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_ComboOutput);
  CTargetNameComboBox::CTargetNameComboBox(this: &this->m_ComboTarget, pPassThru: &this->CFilteredComboBox::ICallbacks);
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_ComboInput);
  CWnd::CWnd(this: &this->m_CheckBoxFireOnce);
  this->m_CheckBoxFireOnce.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_ctlShowHiddenTargetsAsBroken);
  this->m_ctlShowHiddenTargetsAsBroken.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_AddControl);
  this->m_AddControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_PasteControl);
  this->m_PasteControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_DeleteControl);
  this->m_DeleteControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strOutput.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strTarget.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strInput.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strParam.m_pszData = (char *)&v6->GetNilString(this: v6)[1];
  this->m_PickEntityTarget.__vftable = (COP_OutputPickEntityTarget_vtbl *)&COP_OutputPickEntityTarget::`vftable';
  v7 = AfxGetStringManager();
  if ( v7 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strLastParam.m_pszData = (char *)&v7->GetNilString(this: v7)[1];
  this->m_bIgnoreTextChanged = false;
  this->m_pObjectList = nullptr;
  this->m_pEditObjectRuntimeClass = &editCMapClass::classeditCMapClass;
  this->m_nSortColumn = 1;
  this->m_pMapEntityList = nullptr;
  this->m_fDelay = 0.0;
  this->m_bPickingEntities = false;
  this->bSkipEditControlRefresh = false;
  this->m_eSortDirection[0] = Sort_Ascending;
  this->m_eSortDirection[1] = Sort_Ascending;
  this->m_eSortDirection[2] = Sort_Ascending;
  this->m_eSortDirection[3] = Sort_Ascending;
  this->m_eSortDirection[4] = Sort_Ascending;
  this->m_eSortDirection[5] = Sort_Ascending;
  this->m_PickEntityTarget.m_pDlg = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EA1A0
// Name: public: virtual COP_Output::~COP_Output(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::~COP_Output(COP_Output *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax
  volatile signed __int32 *v5; // eax
  volatile signed __int32 *v6; // eax
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *p_m_EditList; // edi

  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Output_vtbl *)&COP_Output::`vftable'{for `CObjectPage'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&COP_Output::`vftable'{for `CFilteredComboBox::ICallbacks'};
  v2 = (volatile signed __int32 *)(this->m_strLastParam.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strParam.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_strInput.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  v5 = (volatile signed __int32 *)(this->m_strTarget.m_pszData - 16);
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
  v6 = (volatile signed __int32 *)(this->m_strOutput.m_pszData - 16);
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(a1: v6);
  CButton::~CButton(this: &this->m_DeleteControl);
  CButton::~CButton(this: &this->m_PasteControl);
  CButton::~CButton(this: &this->m_AddControl);
  CButton::~CButton(this: &this->m_ctlShowHiddenTargetsAsBroken);
  CButton::~CButton(this: &this->m_CheckBoxFireOnce);
  CComboBox::~CComboBox(this: &this->m_ComboInput);
  CTargetNameComboBox::~CTargetNameComboBox(this: &this->m_ComboTarget);
  CComboBox::~CComboBox(this: &this->m_ComboOutput);
  CListCtrl::~CListCtrl(this: &this->m_ListCtrl);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_AnchorMgr);
  p_m_EditList = &this->m_EditList;
  this->m_EditList.m_Size = 0;
  if ( this->m_EditList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_EditList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_EditList->m_Memory.m_pMemory);
      p_m_EditList->m_Memory.m_pMemory = nullptr;
    }
    this->m_EditList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_EditList.m_pElements = this->m_EditList.m_Memory.m_pMemory;
  if ( this->m_EditList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_EditList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_EditList->m_Memory.m_pMemory);
      p_m_EditList->m_Memory.m_pMemory = nullptr;
    }
    this->m_EditList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &this->m_EntityList);
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Output_vtbl *)&CObjectPage::`vftable';
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EA3F0
// Name: protected: void COP_Output::AddEntityConnections(class CMapEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::AddEntityConnections(COP_Output *this, CMapEntity *pEntity, bool bFirst)
{
  COP_Output *v3; // esi
  HWND__ *m_hWnd; // eax
  int v5; // eax
  CEntityConnection *v6; // ebx
  LRESULT v7; // eax
  WPARAM v8; // edi
  int v9; // eax
  int v10; // esi
  CListCtrl *v11; // esi
  char *v12; // eax
  CUtlReference<CMapEntity> **v13; // ebx
  CUtlReference<CMapEntity> *v14; // eax
  CUtlReference<CMapEntity> *ItemData; // eax
  CUtlReference<CMapEntity> *m_pNext; // esi
  CUtlReference<CMapEntity> *v17; // ecx
  CUtlReference<CMapEntity> *v18; // edi
  CUtlReference<CMapEntity> *m_pPrev; // eax
  CEntityConnection **v20; // ecx
  int v21; // eax
  CEntityConnection **v22; // edi
  CUtlReference<CMapEntity> *v23; // ecx
  CUtlReference<CMapEntity> *v24; // ebx
  CUtlMemory<CCullTreeNode *,int> **v25; // eax
  CUtlMemory<CCullTreeNode *,int> *v26; // ebx
  CUtlReference<CMapEntity> *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CCullTreeNode **v29; // edx
  int v30; // eax
  CCullTreeNode **v31; // ecx
  CUtlReference<CMapEntity> *m_pHead; // ecx
  int v33; // ebx
  char string[20]; // [esp+0h] [ebp-154h] BYREF
  char szTemp[260]; // [esp+14h] [ebp-140h]
  int nConnCount; // [esp+118h] [ebp-3Ch] BYREF
  CEntityConnection *pConnection; // [esp+11Ch] [ebp-38h]
  int i; // [esp+120h] [ebp-34h]
  CUtlReference<CMapEntity> src; // [esp+124h] [ebp-30h] BYREF
  CUtlReference<CMapEntity> v40; // [esp+130h] [ebp-24h] BYREF
  CUtlReference<CMapEntity> **v41; // [esp+13Ch] [ebp-18h]
  CUtlReference<CMapEntity> v42; // [esp+140h] [ebp-14h]
  int v43; // [esp+150h] [ebp-4h]

  v3 = this;
  m_hWnd = this->m_ListCtrl.m_hWnd;
  *(_DWORD *)&szTemp[256] = this;
  SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v5 = 0;
  *(_DWORD *)&szTemp[244] = pEntity->m_Connections.m_Size;
  for ( *(_DWORD *)&szTemp[252] = 0; v5 < *(int *)&szTemp[244]; *(_DWORD *)&szTemp[252] = v5 )
  {
    v6 = pEntity->m_Connections.m_Memory.m_pMemory[v5];
    *(_DWORD *)&szTemp[248] = v6;
    if ( v6 != nullptr )
    {
      v7 = SendMessageA(hWnd: v3->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
      v8 = v7;
      if ( v7 <= 0 || (v9 = v7 - 1, v41 = (CUtlReference<CMapEntity> **)(v8 - 1), (int)(v8 - 1) < 0) )
      {
LABEL_5:
        v10 = *(_DWORD *)&szTemp[256];
        SendMessageA(hWnd: *(HWND *)(*(_DWORD *)&szTemp[256] + 344), Msg: 0x102Fu, wParam: v8 + 1, lParam: 0);
        v11 = (CListCtrl *)(v10 + 312);
        CListCtrl::InsertItem(
          this: v11,
          nMask: 2u,
          nItem: v8,
          lpszItem: (char *)&var,
          nState: 0,
          nStateMask: 0,
          nImage: 1,
          lParam: 0);
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 1, lpszText: v6->m_szOutput);
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 2, lpszText: v6->m_szTargetEntity);
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 3, lpszText: v6->m_szInput);
        sprintf(string: &string[4], format: "%.2f", v6->m_fDelay);
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 5, lpszText: &string[4]);
        v12 = "No";
        if ( v6->m_nTimesToFire != -1 )
          v12 = "Yes";
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 6, lpszText: v12);
        CListCtrl::SetItemText(this: v11, nItem: v8, nSubItem: 4, lpszText: v6->m_szParam);
        v13 = (CUtlReference<CMapEntity> **)operator new(nSize: 0xCu);
        v41 = v13;
        v14 = (CUtlReference<CMapEntity> *)operator new(nSize: 0x14u);
        v42.m_pPrev = v14;
        v43 = 2;
        if ( v14 != nullptr )
        {
          v14->m_pNext = nullptr;
          v14->m_pPrev = nullptr;
          v14->m_pObject = nullptr;
          LOBYTE(v43) = 3;
          v14[1].m_pNext = nullptr;
          v14[1].m_pPrev = v14->m_pNext;
          LOBYTE(v43) = 2;
        }
        else
        {
          v14 = nullptr;
        }
        v43 = -1;
        *v13 = v14;
        v24 = (CUtlReference<CMapEntity> *)operator new(nSize: 0x14u);
        v42.m_pPrev = v24;
        v43 = 4;
        if ( v24 != nullptr )
        {
          v24->m_pNext = nullptr;
          v24->m_pPrev = nullptr;
          v24->m_pObject = nullptr;
          CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
            this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v24,
            nGrowSize: 0,
            nInitSize: 0);
          v24[1].m_pNext = nullptr;
          v24[1].m_pPrev = nullptr;
          LOBYTE(v43) = 4;
        }
        else
        {
          v24 = nullptr;
        }
        v43 = -1;
        v25 = (CUtlMemory<CCullTreeNode *,int> **)v41;
        v41[1] = v24;
        v26 = *v25;
        m_pMemory = (CUtlReference<CMapEntity> *)(*v25)[1].m_pMemory;
        m_nAllocationCount = (*v25)->m_nAllocationCount;
        v42.m_pPrev = m_pMemory;
        if ( (int)&m_pMemory->m_pNext + 1 > m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: v26, num: (int)&m_pMemory->m_pNext - m_nAllocationCount + 1);
          m_pMemory = v42.m_pPrev;
        }
        ++v26[1].m_pMemory;
        v29 = v26->m_pMemory;
        v30 = (char *)v26[1].m_pMemory - (char *)m_pMemory - 1;
        v26[1].m_nAllocationCount = (int)v26->m_pMemory;
        if ( v30 > 0 )
        {
          _V_memmove(dest: &v29[(_DWORD)m_pMemory + 1], src: &v29[(_DWORD)m_pMemory], count: 4 * v30);
          m_pMemory = v42.m_pPrev;
        }
        v31 = &v26->m_pMemory[(_DWORD)m_pMemory];
        if ( v31 != nullptr )
          *v31 = *(CCullTreeNode **)&szTemp[248];
        m_pHead = pEntity->m_References.m_pHead;
        v40.m_pPrev = nullptr;
        v40.m_pObject = pEntity;
        v40.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &v40;
        v40.m_pPrev = nullptr;
        pEntity->m_References.m_pHead = &v40;
        v43 = 8;
        v33 = (int)v41;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: (CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *)v41[1],
          elem: (int)v41[1][1].m_pNext,
          src: &v40);
        v43 = -1;
        if ( v40.m_pObject != nullptr )
        {
          if ( v40.m_pPrev != nullptr )
          {
            v40.m_pPrev->m_pNext = v40.m_pNext;
            if ( v40.m_pNext != nullptr )
              v40.m_pNext->m_pPrev = v40.m_pPrev;
          }
          else if ( v40.m_pObject->m_References.m_pHead == &v40 )
          {
            v40.m_pObject->m_References.m_pHead = v40.m_pNext;
            if ( v40.m_pNext != nullptr )
              v40.m_pNext->m_pPrev = nullptr;
          }
          memset(&v40, 0, sizeof(v40));
        }
        *(_BYTE *)(v33 + 9) = 1;
        CListCtrl::SetItem(
          this: v11,
          nItem: v8,
          nSubItem: 0,
          nMask: 4u,
          lpszItem: nullptr,
          nImage: 0,
          nState: 0,
          nStateMask: 0,
          lParam: v33);
        goto LABEL_61;
      }
      while ( 1 )
      {
        ItemData = (CUtlReference<CMapEntity> *)CListCtrl::GetItemData(
                                                  this: (CListCtrl *)(*(_DWORD *)&szTemp[256] + 312),
                                                  nItem: v9);
        m_pNext = ItemData->m_pNext;
        v42.m_pPrev = ItemData;
        if ( CEntityConnection::CompareConnection(this: (CEntityConnection *)m_pNext->m_pNext->m_pNext, pConnection: v6) )
        {
          v17 = pEntity->m_References.m_pHead;
          pConnection = nullptr;
          i = (int)pEntity;
          nConnCount = (int)v17;
          if ( v17 != nullptr )
            v17->m_pPrev = (CUtlReference<CMapEntity> *)&nConnCount;
          pConnection = nullptr;
          pEntity->m_References.m_pHead = (CUtlReference<CMapEntity> *)&nConnCount;
          v43 = 0;
          HIBYTE(v42.m_pNext) = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
                                  this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)v42.m_pPrev->m_pPrev,
                                  src: (const CUtlReference<CMapClass> *)&nConnCount) == -1;
          v43 = -1;
          if ( i != 0 )
          {
            if ( pConnection != nullptr )
            {
              *(_DWORD *)pConnection->m_szSourceEntity = nConnCount;
              if ( nConnCount != 0 )
                *(_DWORD *)(nConnCount + 4) = pConnection;
            }
            else if ( *(int **)(i + 360) == &nConnCount )
            {
              *(_DWORD *)(i + 360) = nConnCount;
              if ( nConnCount != 0 )
                *(_DWORD *)(nConnCount + 4) = 0;
            }
            pConnection = nullptr;
            nConnCount = 0;
            i = 0;
          }
          if ( HIBYTE(v42.m_pNext) != 0 )
            break;
        }
        v41 = (CUtlReference<CMapEntity> **)((char *)v41 - 1);
        if ( (int)v41 < 0 )
          goto LABEL_5;
        v9 = (int)v41;
      }
      v18 = m_pNext[1].m_pNext;
      m_pPrev = m_pNext->m_pPrev;
      if ( (int)((char *)&v18->m_pNext + 1) > (int)m_pPrev )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)m_pNext,
          num: (char *)v18 - (char *)m_pPrev + 1);
      ++m_pNext[1].m_pNext;
      v20 = (CEntityConnection **)m_pNext->m_pNext;
      v21 = (char *)m_pNext[1].m_pNext - (char *)v18 - 1;
      m_pNext[1].m_pPrev = m_pNext->m_pNext;
      if ( v21 > 0 )
        _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
      v22 = (CEntityConnection **)((char *)m_pNext->m_pNext + 4 * (_DWORD)v18);
      if ( v22 != nullptr )
        *v22 = v6;
      v23 = pEntity->m_References.m_pHead;
      src.m_pPrev = nullptr;
      src.m_pObject = pEntity;
      src.m_pNext = v23;
      if ( v23 != nullptr )
        v23->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pEntity->m_References.m_pHead = &src;
      v43 = 1;
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
        this: (CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *)v42.m_pPrev->m_pPrev,
        elem: (int)v42.m_pPrev->m_pPrev[1].m_pNext,
        &src);
      v43 = -1;
      if ( src.m_pObject == nullptr )
        goto LABEL_61;
      if ( src.m_pPrev == nullptr )
      {
        if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
LABEL_39:
        memset(&src, 0, sizeof(src));
        goto LABEL_61;
      }
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext == nullptr )
        goto LABEL_39;
      src.m_pNext->m_pPrev = src.m_pPrev;
      memset(&src, 0, sizeof(src));
    }
LABEL_61:
    v3 = *(COP_Output **)&szTemp[256];
    v5 = *(_DWORD *)&szTemp[252] + 1;
  }
  SendMessageA(hWnd: v3->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100EA910
// Name: protected: void COP_Output::AddEntityOutputs(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::AddEntityOutputs(COP_Output *this, GDclass *pEntity)
{
  CMapInstance *ChildOf; // eax
  CMapInstance *v4; // esi
  int v5; // ebx
  const CUtlReference<CMapClass> *v6; // eax
  const char *Value; // eax
  _DWORD *v8; // edx
  int v9; // edi
  int v10; // esi
  int v11; // edi
  const char *v12; // eax
  GDclass *v13; // ecx
  int v14; // ebx
  CClassOutput *Output; // esi
  signed int v16; // eax
  char temp[512]; // [esp+Ch] [ebp-230h] BYREF
  COP_Output *v18; // [esp+20Ch] [ebp-30h]
  const char *pszTargetName; // [esp+210h] [ebp-2Ch]
  int nConnectionsCount; // [esp+214h] [ebp-28h]
  CUtlReferenceVector<CMapEntity> entityList; // [esp+218h] [ebp-24h] BYREF
  int nCount; // [esp+22Ch] [ebp-10h]
  int v23; // [esp+238h] [ebp-4h]
  GDclass *pClass; // [esp+244h] [ebp+8h]
  GDclass *pClassa; // [esp+244h] [ebp+8h]

  v18 = this;
  this->m_bIsInstanceIOProxy = false;
  if ( pEntity == nullptr || _V_stricmp(s1: (const char *)pEntity->m_VariableMap[15], s2: "func_instance") != 0 )
  {
    v13 = *(GDclass **)&pEntity->m_VariableMap[14][0];
    pClassa = v13;
    if ( v13 != nullptr )
    {
      v14 = 0;
      nCount = v13->m_Outputs.m_Size;
      if ( nCount > 0 )
      {
        while ( 1 )
        {
          Output = GDclass::GetOutput(this: v13, nIndex: v14);
          v16 = SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Output->m_szName);
          if ( v16 >= 0 )
            SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x151u, wParam: v16, lParam: (LPARAM)Output);
          if ( ++v14 >= nCount )
            break;
          v13 = pClassa;
        }
      }
    }
  }
  else
  {
    ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: (CMapEntity *)pEntity, ignoredArg: nullptr);
    v4 = ChildOf;
    v5 = 0;
    if ( ChildOf != nullptr && ChildOf->m_pInstancedMap != nullptr )
    {
      memset(&entityList, 0, 12);
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
        this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&entityList,
        nGrowSize: 0,
        nInitSize: 0);
      entityList.m_Size = 0;
      entityList.m_pElements = nullptr;
      v23 = 3;
      CMapDoc::FindEntitiesByClassName(
        this: v4->m_pInstancedMap,
        Found: &entityList,
        pszClassName: "func_instance_io_proxy",
        bVisiblesOnly: false);
      if ( entityList.m_Size == 1 )
      {
        v6 = CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Element(
               this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&entityList,
               i: 0);
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: (WCKeyValuesT<WCKVBase_Dict> *)&v6->m_pObject[1].m_nObjectID,
                  pszKey: "targetname",
                  piIndex: nullptr);
        this->m_bIsInstanceIOProxy = true;
        v8 = &v4->m_pInstancedMap->m_pWorld->__vftable;
        v9 = 0;
        pszTargetName = Value;
        nCount = (int)v8;
        pClass = nullptr;
        if ( (int)v8[99] > 0 )
        {
          while ( 1 )
          {
            v10 = *(_DWORD *)(*(_DWORD *)(v8[96] + 4 * (v9 >> ((unsigned __int64)(int)v8[98] >> 27)))
                            + 12 * (v9 & ((32 * v8[98]) >> 5))
                            + 8);
            if ( v10 != 0 )
            {
              nConnectionsCount = *(_DWORD *)(v10 + 332);
              if ( nConnectionsCount > 0 )
              {
                do
                {
                  v11 = *(_DWORD *)(*(_DWORD *)(v10 + 320) + 4 * v5);
                  if ( _V_stricmp(s1: (const char *)(v11 + 516), s2: pszTargetName) == 0 )
                  {
                    v12 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                            this: (WCKeyValuesT<WCKVBase_Dict> *)(v10 + 220),
                            pszKey: "targetname",
                            piIndex: nullptr);
                    sprintf(string: temp, format: "instance:%s;%s", v12, (const char *)(v11 + 260));
                    SendMessageA(hWnd: v18->m_ComboOutput.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)temp);
                  }
                  ++v5;
                }
                while ( v5 < nConnectionsCount );
                v9 = (int)pClass;
                v8 = (_DWORD *)nCount;
              }
            }
            pClass = (GDclass *)++v9;
            if ( v9 >= v8[99] )
              break;
            v5 = 0;
          }
        }
        v23 = -1;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
      }
      else
      {
        v23 = -1;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EABA0
// Name: protected: void COP_Output::FillOutputList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::FillOutputList(COP_Output *this)
{
  WPARAM v2; // eax
  int v3; // edi
  char i; // bl
  GDclass *m_pObject; // [esp-Ch] [ebp-10h]

  if ( this->m_EntityList.m_Size != 0 )
  {
    v2 = SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v2 != -1 )
      SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    v3 = 0;
    for ( i = 1; v3 < this->m_EntityList.m_Size; ++v3 )
    {
      m_pObject = (GDclass *)this->m_EntityList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_EntityList.m_Memory
                                                                                            + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
      if ( i != 0 )
      {
        COP_Output::AddEntityOutputs(this, pEntity: m_pObject);
        i = 0;
      }
      else
      {
        COP_Output::FilterEntityOutputs(this, pEntity: m_pObject);
      }
    }
    if ( SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) == 0 )
      CWnd::EnableWindow(this: &this->m_ComboOutput, bEnable: 0);
    SendMessageA(hWnd: this->m_ComboOutput.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAC90
// Name: protected: class CMapEntity __near * COP_Output::GetTargetInstanceIOProxy(void)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall COP_Output::GetTargetInstanceIOProxy(COP_Output *this)
{
  CTargetNameComboBox *p_m_ComboTarget; // esi
  CUtlReferenceVector<CMapEntity> *SubEntityList; // esi
  char *v3; // eax
  CMapEntity *m_pObject; // esi
  CMapInstance *ChildOf; // eax
  CMapInstance *v6; // esi
  CMapClass *v7; // esi
  char szTarget[256]; // [esp+4h] [ebp-124h] BYREF
  CUtlReferenceVector<CMapEntity> entityList; // [esp+104h] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11; // [esp+118h] [ebp-10h] BYREF
  int v12; // [esp+124h] [ebp-4h]

  p_m_ComboTarget = &this->m_ComboTarget;
  szTarget[0] = 0;
  CFilteredComboBox::GetCurrentItem(this: &this->m_ComboTarget, result: &v11);
  v12 = 0;
  V_strncpy(pDest: szTarget, pSrc: v11.m_pszData, maxLen: 256);
  SubEntityList = CTargetNameComboBox::GetSubEntityList(this: p_m_ComboTarget, pName: szTarget);
  v12 = -1;
  v3 = v11.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v11.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
  if ( SubEntityList != nullptr && SubEntityList->m_Size == 1 )
  {
    m_pObject = (*SubEntityList->m_Memory.m_pMemory)->m_pObject;
    if ( _V_stricmp(s1: m_pObject->m_szClass, s2: "func_instance") == 0 )
    {
      ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: m_pObject, ignoredArg: nullptr);
      v6 = ChildOf;
      if ( ChildOf != nullptr && ChildOf->m_pInstancedMap != nullptr )
      {
        CUtlReferenceVector<CMapEntity>::CUtlReferenceVector<CMapEntity>(this: &entityList);
        v12 = 2;
        CMapDoc::FindEntitiesByClassName(
          this: v6->m_pInstancedMap,
          Found: &entityList,
          pszClassName: "func_instance_io_proxy",
          bVisiblesOnly: false);
        if ( entityList.m_Size == 1 )
        {
          v7 = CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Element(
                 this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&entityList,
                 i: 0)->m_pObject;
          v12 = -1;
          CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
          return (CMapEntity *)v7;
        }
        v12 = -1;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EADF0
// Name: public: static class CObject __near * COP_Output::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Output *__stdcall COP_Output::CreateObject()
{
  COP_Output *v0; // eax

  v0 = (COP_Output *)operator new(nSize: 0x828u);
  if ( v0 != nullptr )
    return COP_Output::COP_Output(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EAE50
// Name: public: virtual void COP_OutputPickEntityTarget::OnNotifyPickEntity(class CToolPickEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_OutputPickEntityTarget::OnNotifyPickEntity(
        COP_OutputPickEntityTarget *this,
        CToolPickEntity *pTool)
{
  CMapEntity *m_pObject; // eax
  const char *Value; // eax
  CWnd *v5; // eax
  CWnd *DlgItem; // eax
  const char *v7; // [esp-4h] [ebp-40h]
  CUtlReferenceVector<CMapEntity> Partial; // [esp+8h] [ebp-34h] BYREF
  CUtlReferenceVector<CMapEntity> Full; // [esp+1Ch] [ebp-20h] BYREF
  int v10; // [esp+38h] [ebp-4h]

  memset(&Full, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Full,
    nGrowSize: 0,
    nInitSize: 0);
  Full.m_Size = 0;
  Full.m_pElements = nullptr;
  v10 = 3;
  memset(&Partial, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Partial,
    nGrowSize: 0,
    nInitSize: 0);
  Partial.m_Size = 0;
  Partial.m_pElements = nullptr;
  LOBYTE(v10) = 7;
  CToolPickEntity::GetSelectedEntities(this: pTool, EntityListFull: &Full, EntityListPartial: &Partial);
  m_pObject = (*Full.m_Memory.m_pMemory)->m_pObject;
  if ( m_pObject != nullptr )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &m_pObject->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
    if ( Value == nullptr )
      Value = &var;
    v7 = Value;
    if ( this->m_nDlgItem == 1429 )
    {
      CFilteredComboBox::SelectItem(this: &this->m_pDlg->m_ComboTarget, pStr: Value);
    }
    else if ( this->m_nDlgItem == 1431 )
    {
      DlgItem = CWnd::GetDlgItem(this: this->m_pDlg, nID: 1431);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: v7);
      COP_Output::UpdateEditedParams(this: this->m_pDlg);
    }
    else
    {
      v5 = CWnd::GetDlgItem(this: this->m_pDlg, nID: this->m_nDlgItem);
      CWnd::SetWindowTextA(this: v5, lpszString: v7);
    }
  }
  COP_Output::StopPicking(this: this->m_pDlg);
  LOBYTE(v10) = 3;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Partial);
  v10 = -1;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Full);
}

//------------------------------------------------------------------------------
// Address: 0x100EAFB0
// Name: protected: void COP_Output::RemoveAllEntityConnections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::RemoveAllEntityConnections(COP_Output *this)
{
  void (__stdcall *v1)(HWND, UINT, WPARAM, LPARAM); // edi
  COP_Output *v2; // esi
  LRESULT v3; // eax
  int v4; // ebx
  int *ItemData; // edi
  int v6; // esi
  CUtlReferenceVector<CMapEntity> *pEntityList; // [esp+Ch] [ebp-14h]

  v1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  v2 = this;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v3 = SendMessageA(hWnd: v2->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( v3 > 0 )
  {
    v4 = v3 - 1;
    do
    {
      ItemData = (int *)CListCtrl::GetItemData(this: &v2->m_ListCtrl, nItem: v4);
      v6 = *ItemData;
      pEntityList = (CUtlReferenceVector<CMapEntity> *)ItemData[1];
      SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1008u, wParam: v4, lParam: 0);
      operator delete(p: ItemData);
      if ( v6 != 0 )
      {
        *(_DWORD *)(v6 + 12) = 0;
        if ( *(int *)(v6 + 8) >= 0 )
        {
          if ( *(_DWORD *)v6 != 0 )
          {
            free(pMem: *(void **)v6);
            *(_DWORD *)v6 = 0;
          }
          *(_DWORD *)(v6 + 4) = 0;
        }
        *(_DWORD *)(v6 + 16) = *(_DWORD *)v6;
        if ( *(int *)(v6 + 8) >= 0 )
        {
          if ( *(_DWORD *)v6 != 0 )
          {
            free(pMem: *(void **)v6);
            *(_DWORD *)v6 = 0;
          }
          *(_DWORD *)(v6 + 4) = 0;
        }
        operator delete(p: (void *)v6);
      }
      if ( pEntityList != nullptr )
      {
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: pEntityList);
        operator delete(p: pEntityList);
      }
      --v4;
      v2 = this;
    }
    while ( v4 >= 0 );
    v1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  v1(hWnd: v2->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100EB0F0
// Name: protected: void COP_Output::UpdateConnectionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateConnectionList(COP_Output *this)
{
  CMapWorld *m_pWorld; // eax
  int v3; // edi
  CMapEntity *m_pObject; // eax
  LRESULT i; // edi
  bool bFirst; // [esp+4h] [ebp-4h]

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
    if ( m_pWorld != nullptr )
    {
      this->m_pMapEntityList = &m_pWorld->m_EntityList;
      this->m_bIgnoreTextChanged = true;
      CTargetNameComboBox::SetEntityList(
        this: &this->m_ComboTarget,
        pEntityList: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&m_pWorld->m_EntityList);
      this->m_bIgnoreTextChanged = false;
      COP_Output::UpdateEntityList(this);
      COP_Output::RemoveAllEntityConnections(this);
      v3 = 0;
      for ( bFirst = true; v3 < this->m_EntityList.m_Size; ++v3 )
      {
        m_pObject = this->m_EntityList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_EntityList.m_Memory
                                                                                   + 2) >> 27)][v3
                                                                                              & ((32
                                                                                                * *((_DWORD *)&this->m_EntityList.m_Memory
                                                                                                  + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          COP_Output::AddEntityConnections(this, pEntity: m_pObject, bFirst);
          bFirst = false;
        }
      }
      for ( i = 0; i < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++i )
        COP_Output::UpdateItemValidity(this, nItem: i);
      COP_Output::UpdateValidityButton(this);
      COP_Output::ResizeColumns(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB1F0
// Name: protected: virtual void COP_Output::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnDestroy(COP_Output *this)
{
  CWnd::EnableWindow(this: &this->m_ListCtrl, bEnable: 0);
  COP_Output::RemoveAllEntityConnections(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EB210
// Name: protected: void COP_Output::FillInputList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::FillInputList(COP_Output *this)
{
  int v2; // ebx
  CMapEntity *TargetInstanceIOProxy; // eax
  CEntityConnection *v4; // eax
  const CUtlReferenceVector<CMapEntity> *m_pMapEntityList; // eax
  int v6; // edx
  CMapEntity *m_pObject; // eax
  GDclass *m_pClass; // ebx
  CClassInput *Input; // ebx
  WPARAM v10; // eax
  signed int v11; // eax
  const CUtlReferenceVector<CMapEntity> *v12; // ecx
  int m_nGrowSize; // esi
  UtlRBTreeNode_t<int,int> *m_pMemory; // eax
  char temp[512]; // [esp+8h] [ebp-240h] BYREF
  int nCount; // [esp+208h] [ebp-40h]
  GDclass *pClass; // [esp+20Ch] [ebp-3Ch]
  CUtlRBTree<int,int,bool (__cdecl*)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int> > classCache; // [esp+210h] [ebp-38h] BYREF
  int pos; // [esp+234h] [ebp-14h]
  int i; // [esp+238h] [ebp-10h] BYREF
  int v21; // [esp+244h] [ebp-4h]

  v2 = 0;
  if ( this->m_pMapEntityList != nullptr )
  {
    SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    memset(&classCache.m_Elements, 0, sizeof(classCache.m_Elements));
    classCache.m_Root = -1;
    classCache.m_NumElements = 0;
    classCache.m_FirstFree = -1;
    classCache.m_LastAlloc.index = -1;
    classCache.m_pElements = nullptr;
    v21 = 1;
    classCache.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<DmeTime_t>::LessFunc;
    TargetInstanceIOProxy = COP_Output::GetTargetInstanceIOProxy(this);
    pos = (int)TargetInstanceIOProxy;
    if ( TargetInstanceIOProxy != nullptr )
    {
      this->m_bIsInstanceIOProxy = true;
      i = TargetInstanceIOProxy->m_Connections.m_Size;
      if ( i > 0 )
      {
        while ( 1 )
        {
          v4 = TargetInstanceIOProxy->m_Connections.m_Memory.m_pMemory[v2];
          sprintf(string: temp, format: "instance:%s;%s", v4->m_szTargetEntity, v4->m_szInput);
          SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)temp);
          if ( ++v2 >= i )
            break;
          TargetInstanceIOProxy = (CMapEntity *)pos;
        }
      }
    }
    else
    {
      m_pMapEntityList = this->m_pMapEntityList;
      v6 = 0;
      this->m_bIsInstanceIOProxy = false;
      pos = 0;
      if ( m_pMapEntityList->m_Size > 0 )
      {
        do
        {
          m_pObject = this->m_pMapEntityList->m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&this->m_pMapEntityList->m_Memory
                                                                                          + 2) >> 27)][pos & ((32 * *((_DWORD *)&this->m_pMapEntityList->m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            m_pClass = m_pObject->m_pClass;
            pClass = m_pClass;
            if ( m_pClass != nullptr )
            {
              i = (int)m_pClass;
              if ( CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::Find(
                     this: &classCache,
                     search: &i) == -1 )
              {
                i = (int)m_pClass;
                CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::Insert(
                  this: &classCache,
                  a2: (const char *)SendMessageA,
                  insert: &i);
                nCount = m_pClass->m_Inputs.m_Size;
                i = 0;
                if ( nCount > 0 )
                {
                  while ( 1 )
                  {
                    Input = GDclass::GetInput(this: m_pClass, nIndex: i);
                    v10 = SendMessageA(
                            hWnd: this->m_ComboInput.m_hWnd,
                            Msg: 0x158u,
                            wParam: 0xFFFFFFFF,
                            lParam: (LPARAM)Input->m_szName);
                    if ( v10 == -1
                      || *(_DWORD *)(SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x150u, wParam: v10, lParam: 0)
                                   + 260) != Input->m_eType )
                    {
                      v11 = SendMessageA(
                              hWnd: this->m_ComboInput.m_hWnd,
                              Msg: 0x143u,
                              wParam: 0,
                              lParam: (LPARAM)Input->m_szName);
                      if ( v11 >= 0 )
                        SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0x151u, wParam: v11, lParam: (LPARAM)Input);
                    }
                    if ( ++i >= nCount )
                      break;
                    m_pClass = pClass;
                  }
                }
              }
            }
          }
          v12 = this->m_pMapEntityList;
          v6 = pos + 1;
          pos = v6;
        }
        while ( v6 < v12->m_Size );
      }
    }
    SendMessageA(hWnd: this->m_ComboInput.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    v21 = 2;
    CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::RemoveAll(this: &classCache);
    m_nGrowSize = classCache.m_Elements.m_nGrowSize;
    m_pMemory = classCache.m_Elements.m_pMemory;
    classCache.m_FirstFree = -1;
    if ( classCache.m_Elements.m_nGrowSize >= 0 )
    {
      if ( classCache.m_Elements.m_pMemory != nullptr )
      {
        free(pMem: classCache.m_Elements.m_pMemory);
        m_pMemory = nullptr;
        classCache.m_Elements.m_pMemory = nullptr;
      }
      classCache.m_Elements.m_nAllocationCount = 0;
    }
    classCache.m_LastAlloc.index = -1;
    v21 = -1;
    if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
      free(pMem: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB4C0
// Name: protected: virtual void COP_Output::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnTextChanged(COP_Output *this, const char *pText)
{
  if ( LOBYTE(this->m_PasteControl.m_pfnSuper) == 0 )
  {
    LOBYTE(this->m_dwRef) = 1;
    COP_Output::FillInputList(this: (COP_Output *)((char *)this - 184));
    COP_Output::FilterInputList(this: (COP_Output *)((char *)this - 184));
    CWnd::SetWindowTextA(
      this: (CWnd *)&this->m_ComboTarget.m_pCurrentGestureInfo,
      lpszString: (const char *)this->m_PasteControl.m_bIsTouchWindowRegistered);
    COP_Output::UpdateEditedTargets(this: (COP_Output *)((char *)this - 184));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB510
// Name: protected: void COP_Output::UpdateEditControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateEditControls(COP_Output *this)
{
  LRESULT v2; // edi
  const CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > **ItemData; // eax
  CWnd *DlgItem; // ebx
  CWnd *v5; // eax
  CClassOutput *Output; // eax
  CAutoSelComboBox *p_m_ComboOutput; // ecx
  CClassInput *Input; // eax
  char *m_pszData; // [esp+4h] [ebp-214h]
  char *v10; // [esp+4h] [ebp-214h]
  char string[8]; // [esp+14h] [ebp-204h] BYREF
  char szTemp[260]; // [esp+1Ch] [ebp-1FCh] BYREF

  v2 = 0;
  this->m_EditList.m_Size = 0;
  CWnd::EnableWindow(this: &this->m_AddControl, bEnable: this->m_bCanEdit);
  CWnd::EnableWindow(this: &this->m_PasteControl, bEnable: this->m_bCanEdit);
  CWnd::EnableWindow(this: &this->m_DeleteControl, bEnable: this->m_bCanEdit);
  if ( CWnd::IsWindowEnabled(this: &this->m_ListCtrl) != 0
    && SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1032u, wParam: 0, lParam: 0) != 0 )
  {
    if ( SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v2, lParam: 2) & 2) != 0 )
        {
          ItemData = (const CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > **)CListCtrl::GetItemData(
                                                                                    this: &this->m_ListCtrl,
                                                                                    nItem: v2);
          CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int>>::AddVectorToTail(
            this: (CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *)&this->m_EditList,
            src: *ItemData);
        }
        ++v2;
      }
      while ( v2 < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
    }
    if ( this->m_EditList.m_Size > 0 )
    {
      COP_Output::SetConnection(this, pConnectionList: &this->m_EditList);
      COP_Output::FillOutputList(this);
      COP_Output::FillInputList(this);
      m_pszData = this->m_strTarget.m_pszData;
      this->m_bIgnoreTextChanged = true;
      CFilteredComboBox::SelectItem(this: &this->m_ComboTarget, pStr: m_pszData);
      v10 = this->m_strInput.m_pszData;
      this->m_bIgnoreTextChanged = false;
      CWnd::SetWindowTextA(this: &this->m_ComboInput, lpszString: v10);
      CWnd::SetWindowTextA(this: &this->m_ComboOutput, lpszString: this->m_strOutput.m_pszData);
      SendMessageA(hWnd: this->m_CheckBoxFireOnce.m_hWnd, Msg: 0xF1u, wParam: this->m_bFireOnce, lParam: 0);
      DlgItem = CWnd::GetDlgItem(this, nID: 1009);
      sprintf(string, format: "%.2f", this->m_fDelay);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: string);
      v5 = CWnd::GetDlgItem(this, nID: 1431);
      CWnd::SetWindowTextA(this: v5, lpszString: this->m_strParam.m_pszData);
      COP_Output::FilterInputList(this);
      Output = COP_Output::GetOutput(this, szOutput: &szTemp[252], nSize: 256);
      p_m_ComboOutput = &this->m_ComboOutput;
      if ( Output != nullptr )
        CAutoSelComboBox::SetTextColor(this: p_m_ComboOutput, dwColor: 0);
      else
        CAutoSelComboBox::SetTextColor(this: p_m_ComboOutput, dwColor: 0xFFu);
      RedrawWindow(hWnd: this->m_ComboOutput.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      Input = COP_Output::GetInput(this, szInput: &szTemp[252], nSize: 256);
      COP_Output::UpdateCombosForSelectedInput(this, pInput: Input);
    }
    if ( !this->m_bCanEdit )
      COP_Output::EnableEditControls(this, bValue: false);
  }
  else
  {
    COP_Output::EnableEditControls(this, bValue: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB770
// Name: protected: void COP_Output::OnMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnMark(COP_Output *this)
{
  COP_Output *v1; // edi
  LRESULT v2; // esi
  int v3; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v5; // eax
  void *v6; // eax
  CMapDoc *v7; // edi
  unsigned int v8; // eax
  int v9; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *ItemText; // eax
  char *v11; // eax
  int i; // esi
  CMapEntity *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  int j; // esi
  CMapDoc *v16; // esi
  CMainFrame *MainWnd; // eax
  CMainFrame *v18; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-7Ch]
  CEntityConnection *v20; // [esp-4h] [ebp-70h]
  CUtlReferenceVector<CMapClass> Select; // [esp+Ch] [ebp-60h] BYREF
  CUtlReferenceVector<CMapEntity> Found; // [esp+20h] [ebp-4Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+34h] [ebp-38h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+40h] [ebp-2Ch] BYREF
  CEntityConnection *pConnection; // [esp+44h] [ebp-28h]
  COP_Output *v26; // [esp+48h] [ebp-24h]
  __POSITION *pos; // [esp+4Ch] [ebp-20h] BYREF
  CMapDoc *pActiveDoc; // [esp+50h] [ebp-1Ch]
  int nItem; // [esp+54h] [ebp-18h]
  CMapDoc *pExternalDoc; // [esp+58h] [ebp-14h]
  bool bMultipleDocs; // [esp+5Eh] [ebp-Eh]
  bool bFoundInActive; // [esp+5Fh] [ebp-Dh]
  int v33; // [esp+68h] [ebp-4h]

  v1 = this;
  m_hWnd = this->m_ListCtrl.m_hWnd;
  v26 = this;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  pActiveDoc = CMapDoc::m_pMapDoc;
  pExternalDoc = nullptr;
  bMultipleDocs = false;
  bFoundInActive = false;
  pConnection = nullptr;
  if ( v2 > 0 )
  {
    memset(&Select, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Select.m_Memory, nGrowSize: 0, nInitSize: 0);
    Select.m_Size = 0;
    Select.m_pElements = nullptr;
    v33 = 3;
    v3 = v2 - 1;
    nItem = v3;
    if ( v3 >= 0 )
    {
      do
      {
        if ( (SendMessageA(hWnd: v1->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v3, lParam: 2) & 2) != 0 )
        {
          pConnection = ***(CEntityConnection ****)CListCtrl::GetItemData(this: &v1->m_ListCtrl, nItem: v3);
          ModuleState = AfxGetModuleState();
          pos = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                  + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
          if ( pos != nullptr )
          {
            do
            {
              v5 = AfxGetModuleState();
              v6 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                              + 88))(
                             a1: v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                             a2: &pos);
              v7 = (CMapDoc *)__RTDynamicCast(
                                inptr: v6,
                                VfDelta: 0,
                                SrcType: &CDocument `RTTI Type Descriptor',
                                TargetType: &CMapDoc `RTTI Type Descriptor',
                                isReference: 0);
              if ( v7 != nullptr )
              {
                v8 = 15;
                Found.m_Memory.m_pMemory = nullptr;
                Found.m_Memory.m_nBlocks = 0;
                v9 = 16;
                *((_DWORD *)&Found.m_Memory + 2) = 15;
                do
                {
                  v9 >>= 1;
                  v8 = ((v8 & 0xF8000000) + 0x8000000) ^ v8 & 0x7FFFFFF;
                  *((_DWORD *)&Found.m_Memory + 2) = v8;
                }
                while ( v9 > 1 );
                Found.m_Size = 0;
                Found.m_pElements = nullptr;
                LOBYTE(v33) = 7;
                ItemText = CListCtrl::GetItemText(this: &v26->m_ListCtrl, &result, nItem: v3, nSubItem: 2);
                LOBYTE(v33) = 8;
                CMapDoc::FindEntitiesByName(this: v7, &Found, pszName: ItemText->m_pszData, bVisiblesOnly: false);
                LOBYTE(v33) = 7;
                v11 = result.m_pszData - 16;
                if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
                  (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
                for ( i = 0; i < Found.m_Size; pExternalDoc = v7 )
                {
                  m_pObject = Found.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&Found.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&Found.m_Memory + 2)) >> 5)].m_pObject;
                  src.m_pPrev = nullptr;
                  src.m_pNext = nullptr;
                  src.m_pObject = m_pObject;
                  if ( m_pObject != nullptr )
                  {
                    m_pHead = m_pObject->CMapClass::m_References.m_pHead;
                    src.m_pNext = m_pHead;
                    if ( m_pHead != nullptr )
                      m_pHead->m_pPrev = &src;
                    src.m_pPrev = nullptr;
                    m_pObject->CMapClass::m_References.m_pHead = &src;
                  }
                  LOBYTE(v33) = 10;
                  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
                    this: &Select,
                    elem: Select.m_Size,
                    &src);
                  LOBYTE(v33) = 7;
                  if ( src.m_pObject != nullptr )
                  {
                    if ( src.m_pPrev != nullptr )
                    {
                      src.m_pPrev->m_pNext = src.m_pNext;
                      if ( src.m_pNext != nullptr )
                        src.m_pNext->m_pPrev = src.m_pPrev;
                    }
                    else if ( src.m_pObject->m_References.m_pHead == &src )
                    {
                      src.m_pObject->m_References.m_pHead = src.m_pNext;
                      if ( src.m_pNext != nullptr )
                        src.m_pNext->m_pPrev = nullptr;
                    }
                    memset(&src, 0, sizeof(src));
                  }
                  if ( pExternalDoc != nullptr && pExternalDoc != v7 )
                    bMultipleDocs = true;
                  if ( v7 == pActiveDoc )
                    bFoundInActive = true;
                  ++i;
                }
                LOBYTE(v33) = 13;
                CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this: &Found);
                if ( Found.m_Memory.m_pMemory != nullptr )
                {
                  for ( j = 0; j < Found.m_Memory.m_nBlocks; ++j )
                    free(pMem: Found.m_Memory.m_pMemory[j]);
                  Found.m_Memory.m_nBlocks = 0;
                  free(pMem: Found.m_Memory.m_pMemory);
                  Found.m_Memory.m_pMemory = nullptr;
                }
                Found.m_pElements = nullptr;
                LOBYTE(v33) = 3;
                v3 = nItem;
              }
            }
            while ( pos != nullptr );
            v1 = v26;
          }
        }
        nItem = --v3;
      }
      while ( v3 >= 0 );
      if ( bFoundInActive )
      {
        pExternalDoc = pActiveDoc;
      }
      else if ( bMultipleDocs )
      {
        CWnd::MessageBoxA(
          this: v1,
          lpszText: "Entities with same target name exist across multiple documents.",
          lpszCaption: "No Selection Done!",
          nType: 0x40u);
LABEL_48:
        v33 = -1;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Select);
        return;
      }
    }
    if ( Select.m_Size <= 0 )
    {
      CWnd::MessageBoxA(
        this: v1,
        lpszText: "No entities were found with that targetname.",
        lpszCaption: "No entities found",
        nType: 0x40u);
    }
    else
    {
      v16 = pExternalDoc;
      CMapDoc::SelectObjectList(this: pExternalDoc, pList: &Select, cmd: 1042);
      if ( Select.m_Size == 1 )
      {
        v20 = pConnection;
        MainWnd = GetMainWnd();
        CObjectProperties::SetPageToInput(this: MainWnd->pObjectProperties, pConnection: v20);
      }
      if ( v16 != pActiveDoc )
      {
        CMapDoc::SetActiveMapDoc(pDoc: v16);
        CMapDoc::ActivateMapDoc(pDoc: (__POSITION *)v16);
        v18 = GetMainWnd();
        CMainFrame::GlobalNotify(this: v18, a2: (int)v1, nCode: 1026);
        CMapDoc::UpdateAllViews(this: v16, nFlags: 2313, ub: nullptr);
      }
      CMapDoc::Center2DViewsOnSelection(this: v16);
    }
    goto LABEL_48;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBB70
// Name: protected: virtual int COP_Output::OnNotify(unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Output::OnNotify(COP_Output *this, unsigned int wParam, int lParam, int *pResult)
{
  int v5; // ecx
  int v7; // edi
  int m_nSortColumn; // ecx
  SortDirection_t v9; // edx

  if ( *(_DWORD *)(lParam + 4) != 1428 )
    return CPropertyPage::OnNotify(this, wParam, lParam, pResult);
  v5 = *(_DWORD *)(lParam + 8);
  switch ( v5 )
  {
    case -108:
      v7 = *(_DWORD *)(lParam + 16);
      if ( v7 < 6 )
      {
        m_nSortColumn = this->m_nSortColumn;
        v9 = this->m_eSortDirection[v7];
        if ( v7 == m_nSortColumn )
          v9 = this->m_eSortDirection[m_nSortColumn] == Sort_Ascending;
        COP_Output::SetSortColumn(this, nColumn: v7, eDirection: v9);
      }
      return 1;
    case -101:
      if ( ((*(_BYTE *)(lParam + 20) ^ *(_BYTE *)(lParam + 24)) & 2) != 0 )
      {
        if ( !this->bSkipEditControlRefresh )
          COP_Output::UpdateEditControls(this);
        this->bSkipEditControlRefresh = false;
        ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strLastParam);
      }
      return 1;
    case -3:
      COP_Output::OnMark(this);
      return 1;
    default:
      return CPropertyPage::OnNotify(this, wParam, lParam, pResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBC40
// Name: protected: void COP_Output::SetSelectedItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SetSelectedItem(COP_Output *this, int nSelectItem)
{
  void (__stdcall *v2)(HWND, UINT, WPARAM, LPARAM); // ebx
  signed int v4; // esi
  CListCtrl *p_m_ListCtrl; // ecx
  LRESULT nItemCount; // [esp+Ch] [ebp-4h]

  v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v4 = 0;
  nItemCount = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( nItemCount > 0 )
  {
    do
    {
      p_m_ListCtrl = &this->m_ListCtrl;
      if ( v4 == nSelectItem )
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 2u, nStateMask: 2u);
      else
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 0xFFFFFFFD, nStateMask: 2u);
      ++v4;
    }
    while ( v4 < nItemCount );
    v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  v2(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  COP_Output::UpdateEditControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EBCD0
// Name: public: void COP_Output::SetSelectedConnection(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SetSelectedConnection(COP_Output *this, CEntityConnection *pConnection)
{
  void (__stdcall *v2)(HWND, UINT, WPARAM, LPARAM); // edi
  signed int v4; // esi
  CEntityConnection ****ItemData; // eax
  CListCtrl *p_m_ListCtrl; // ecx
  LRESULT nItemCount; // [esp+Ch] [ebp-4h]

  v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v4 = 0;
  nItemCount = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( nItemCount > 0 )
  {
    do
    {
      ItemData = (CEntityConnection ****)CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: v4);
      p_m_ListCtrl = &this->m_ListCtrl;
      if ( ***ItemData == pConnection )
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 2u, nStateMask: 2u);
      else
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 0xFFFFFFFD, nStateMask: 2u);
      ++v4;
    }
    while ( v4 < nItemCount );
    v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  v2(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  COP_Output::UpdateEditControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EBD70
// Name: protected: void COP_Output::SetSelectedConnections(class CUtlVector<class CEntityConnection __near *,class CUtlMemory<class CEntityConnection __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::SetSelectedConnections(
        COP_Output *this,
        CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *List)
{
  void (__stdcall *v2)(HWND, UINT, WPARAM, LPARAM); // esi
  COP_Output *v3; // edi
  signed int v4; // ebx
  CListCtrl *p_m_ListCtrl; // esi
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *v6; // ecx
  int m_Size; // edx
  CEntityConnection **m_pMemory; // esi
  int v9; // eax
  CEntityConnection **v10; // ecx
  LRESULT nItemCount; // [esp+Ch] [ebp-18h]
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *pConnList; // [esp+10h] [ebp-14h]
  int nConnCount; // [esp+18h] [ebp-Ch]
  int nConn; // [esp+1Ch] [ebp-8h]
  bool bFound; // [esp+23h] [ebp-1h]

  v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  v3 = this;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  nConnCount = List->m_Size;
  v4 = 0;
  nItemCount = SendMessageA(hWnd: v3->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( nItemCount > 0 )
  {
    p_m_ListCtrl = &v3->m_ListCtrl;
    do
    {
      v6 = *(CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > **)CListCtrl::GetItemData(
                                                                                       this: p_m_ListCtrl,
                                                                                       nItem: v4);
      pConnList = v6;
      bFound = false;
      nConn = 0;
      if ( nConnCount > 0 )
      {
        m_Size = v6->m_Size;
        m_pMemory = List->m_Memory.m_pMemory;
        while ( 1 )
        {
          v9 = 0;
          if ( m_Size > 0 )
          {
            v10 = v6->m_Memory.m_pMemory;
            while ( *v10 != *m_pMemory )
            {
              ++v9;
              ++v10;
              if ( v9 >= m_Size )
                goto LABEL_12;
            }
            if ( v9 != -1 )
              break;
          }
LABEL_12:
          ++m_pMemory;
          if ( ++nConn >= nConnCount )
            goto LABEL_15;
          v6 = pConnList;
        }
        bFound = true;
LABEL_15:
        v3 = this;
      }
      p_m_ListCtrl = &v3->m_ListCtrl;
      CListCtrl::SetItemState(this: &v3->m_ListCtrl, nItem: v4++, nState: bFound ? 2 : -3, nStateMask: 2u);
    }
    while ( v4 < nItemCount );
    v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  v2(hWnd: v3->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  COP_Output::UpdateEditControls(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100EBE80
// Name: protected: void COP_Output::OnAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnAdd(COP_Output *this)
{
  int i; // edi
  CMapEntity *m_pObject; // ebx
  CEntityConnection *v4; // eax
  CEntityConnection *v5; // eax
  LRESULT v6; // edi
  CWnd *DlgItem; // eax

  for ( i = 0; i < this->m_EntityList.m_Size; ++i )
  {
    m_pObject = this->m_EntityList.m_Memory.m_pMemory[i >> (*((int *)&this->m_EntityList.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      v4 = (CEntityConnection *)operator new(nSize: 0x510u);
      if ( v4 != nullptr )
        v5 = CEntityConnection::CEntityConnection(this: v4);
      else
        v5 = nullptr;
      CEditGameClass::Connections_Add(this: &m_pObject->CEditGameClass, pConnection: v5);
    }
  }
  COP_Output::UpdateConnectionList(this);
  v6 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  COP_Output::SetSelectedItem(this, nSelectItem: v6 - 1);
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1013u, wParam: v6 - 1, lParam: 0);
  DlgItem = CWnd::GetDlgItem(this, nID: 1007);
  CWnd::SetFocus(this: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x100EBF80
// Name: protected: void COP_Output::OnPaste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnPaste(COP_Output *this)
{
  int m_Size; // eax
  int m_nGrowSize; // esi
  COP_Output *v3; // ebx
  int v4; // edi
  int v5; // edx
  CUtlReference<CMapEntity> *v6; // ecx
  int v7; // edx
  int v8; // eax
  const CEntityConnection *v9; // esi
  CEntityConnection *v10; // eax
  CEntityConnection *v11; // ebx
  int v12; // esi
  CEntityConnection **m_pMemory; // ecx
  CEntityConnection **v14; // esi
  int m_nSortColumn; // eax
  WPARAM v16; // ecx
  int (__stdcall *v17)(COutputConnection *, COutputConnection *, SortDirection_t); // eax
  CWnd *DlgItem; // eax
  CEntityConnection **v19; // eax
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > NewConnections; // [esp+8h] [ebp-38h] BYREF
  void *p; // [esp+1Ch] [ebp-24h]
  int nConnCount; // [esp+20h] [ebp-20h]
  CMapEntity *pEntity; // [esp+24h] [ebp-1Ch]
  int i; // [esp+28h] [ebp-18h]
  COP_Output *v25; // [esp+2Ch] [ebp-14h]
  int pos; // [esp+30h] [ebp-10h]
  int v27; // [esp+3Ch] [ebp-4h]

  m_Size = COP_Output::m_pConnectionBuffer->m_Size;
  m_nGrowSize = 0;
  v3 = this;
  v25 = this;
  if ( m_Size != 0 )
  {
    memset(&NewConnections, 0, sizeof(NewConnections));
    v4 = 0;
    v27 = 1;
    v5 = 0;
    pos = 0;
    if ( this->m_EntityList.m_Size > 0 )
    {
      do
      {
        v6 = v3->m_EntityList.m_Memory.m_pMemory[v5 >> (*((int *)&v3->m_EntityList.m_Memory + 2) >> 27)];
        v7 = pos;
        pEntity = v6[pos & ((32 * *((_DWORD *)&v3->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
        if ( pEntity != nullptr )
        {
          v8 = 0;
          nConnCount = COP_Output::m_pConnectionBuffer->m_Size;
          i = 0;
          if ( nConnCount > 0 )
          {
            do
            {
              v9 = COP_Output::m_pConnectionBuffer->m_Memory.m_pMemory[v8];
              if ( v9 != nullptr )
              {
                v10 = (CEntityConnection *)operator new(nSize: 0x510u);
                p = v10;
                LOBYTE(v27) = 2;
                if ( v10 != nullptr )
                  v11 = CEntityConnection::CEntityConnection(this: v10);
                else
                  v11 = nullptr;
                LOBYTE(v27) = 1;
                CEntityConnection::operator=(this: v11, Other: v9);
                CEditGameClass::Connections_Add(this: &pEntity->CEditGameClass, pConnection: v11);
                v12 = v4;
                if ( v4 + 1 > NewConnections.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CVisGroup *,int>::Grow(
                    this: (CUtlMemory<CCullTreeNode *,int> *)&NewConnections,
                    num: v4 - NewConnections.m_Memory.m_nAllocationCount + 1);
                  v4 = NewConnections.m_Size;
                }
                NewConnections.m_Size = ++v4;
                m_pMemory = NewConnections.m_Memory.m_pMemory;
                NewConnections.m_pElements = NewConnections.m_Memory.m_pMemory;
                if ( v4 - v12 - 1 > 0 )
                {
                  _V_memmove(
                    dest: &NewConnections.m_Memory.m_pMemory[v12 + 1],
                    src: &NewConnections.m_Memory.m_pMemory[v12],
                    count: 4 * (v4 - v12 - 1));
                  m_pMemory = NewConnections.m_Memory.m_pMemory;
                }
                v14 = &m_pMemory[v12];
                if ( v14 != nullptr )
                  *v14 = v11;
                v3 = v25;
              }
              v8 = i + 1;
              i = v8;
            }
            while ( v8 < nConnCount );
            v7 = pos;
          }
        }
        v5 = v7 + 1;
        pos = v5;
      }
      while ( v5 < v3->m_EntityList.m_Size );
      m_nGrowSize = NewConnections.m_Memory.m_nGrowSize;
    }
    COP_Output::UpdateConnectionList(this: v3);
    m_nSortColumn = v3->m_nSortColumn;
    v16 = v3->m_eSortDirection[m_nSortColumn];
    switch ( m_nSortColumn )
    {
      case 1:
        v17 = ListCompareOutputNames;
        goto LABEL_25;
      case 2:
        v17 = ListCompareTargetNames;
        goto LABEL_25;
      case 3:
        v17 = ListCompareInputNames;
        goto LABEL_25;
      case 5:
        v17 = ListCompareDelays;
LABEL_25:
        if ( v17 != nullptr )
          SendMessageA(hWnd: v3->m_ListCtrl.m_hWnd, Msg: 0x1030u, wParam: v16, lParam: (LPARAM)v17);
        break;
      default:
        break;
    }
    COP_Output::SetSelectedConnections(this: v3, List: &NewConnections);
    DlgItem = CWnd::GetDlgItem(this: v3, nID: 1007);
    CWnd::SetFocus(this: DlgItem);
    v27 = 3;
    v19 = NewConnections.m_Memory.m_pMemory;
    NewConnections.m_Size = 0;
    if ( m_nGrowSize >= 0 )
    {
      if ( NewConnections.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: NewConnections.m_Memory.m_pMemory);
        NewConnections.m_Memory.m_pMemory = nullptr;
        v19 = nullptr;
      }
      NewConnections.m_Memory.m_nAllocationCount = 0;
    }
    NewConnections.m_pElements = v19;
    v27 = -1;
    if ( m_nGrowSize >= 0 && v19 != nullptr )
      free(pMem: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC1E0
// Name: protected: void COP_Output::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::OnDelete(COP_Output *this)
{
  LRESULT v2; // eax
  int v3; // esi
  int v4; // edi
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *v5; // esi
  int m_Size; // ecx
  int v7; // eax
  CEntityConnection *v8; // edx
  int i; // esi
  CMapEntity *m_pObject; // eax
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // edi
  int v12; // esi
  CMapEntity *v13; // eax
  int v14; // eax
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *pConnList; // [esp+8h] [ebp-20h]
  int nConnCount; // [esp+Ch] [ebp-1Ch]
  int nItem; // [esp+10h] [ebp-18h]
  int nConn; // [esp+14h] [ebp-14h]
  CEntityConnection *pConnection; // [esp+18h] [ebp-10h]

  if ( SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1032u, wParam: 0, lParam: 0) != 0 )
  {
    v2 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
    v3 = 0;
    if ( v2 > 0 )
    {
      v4 = v2 - 1;
      nItem = v2 - 1;
      do
      {
        if ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v4, lParam: 2) & 2) != 0 )
        {
          v5 = *(CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > **)CListCtrl::GetItemData(
                                                                                           this: &this->m_ListCtrl,
                                                                                           nItem: v4);
          pConnList = v5;
          SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1008u, wParam: v4, lParam: 0);
          if ( v5 != nullptr )
          {
            m_Size = v5->m_Size;
            v7 = 0;
            nConnCount = m_Size;
            for ( nConn = 0; v7 < m_Size; nConn = v7 )
            {
              v8 = v5->m_Memory.m_pMemory[v7];
              pConnection = v8;
              if ( v8 != nullptr )
              {
                for ( i = 0; i < this->m_EntityList.m_Size; ++i )
                {
                  m_pObject = this->m_EntityList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_EntityList.m_Memory
                                                                                            + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
                  if ( m_pObject != nullptr )
                  {
                    CEditGameClass::Connections_Remove(this: &m_pObject->CEditGameClass, pConnection: v8);
                    v8 = pConnection;
                  }
                }
                m_pTargetEntityList = v8->m_pTargetEntityList;
                if ( m_pTargetEntityList != nullptr )
                {
                  v12 = 0;
                  if ( m_pTargetEntityList->m_Size > 0 )
                  {
                    do
                    {
                      v13 = m_pTargetEntityList->m_Memory.m_pMemory[v12 >> ((unsigned __int64)*((int *)&m_pTargetEntityList->m_Memory
                                                                                              + 2) >> 27)][v12 & ((32 * *((_DWORD *)&m_pTargetEntityList->m_Memory + 2)) >> 5)].m_pObject;
                      if ( v13 != nullptr )
                        CEditGameClass::Upstream_Remove(this: &v13->CEditGameClass, pConnection);
                      ++v12;
                    }
                    while ( v12 < m_pTargetEntityList->m_Size );
                    v8 = pConnection;
                  }
                }
                CEntityConnection::~CEntityConnection(this: v8);
                operator delete(p: pConnection);
                m_Size = nConnCount;
                v5 = pConnList;
                v4 = nItem;
                v7 = nConn;
              }
              ++v7;
            }
            v5->m_Size = 0;
            if ( v5->m_Memory.m_nGrowSize >= 0 )
            {
              if ( v5->m_Memory.m_pMemory != nullptr )
              {
                free(pMem: v5->m_Memory.m_pMemory);
                v5->m_Memory.m_pMemory = nullptr;
              }
              v5->m_Memory.m_nAllocationCount = 0;
            }
            v5->m_pElements = v5->m_Memory.m_pMemory;
            if ( v5->m_Memory.m_nGrowSize >= 0 )
            {
              if ( v5->m_Memory.m_pMemory != nullptr )
              {
                free(pMem: v5->m_Memory.m_pMemory);
                v5->m_Memory.m_pMemory = nullptr;
              }
              v5->m_Memory.m_nAllocationCount = 0;
            }
            operator delete(p: v5);
          }
          v3 = v4;
        }
        nItem = --v4;
      }
      while ( v4 >= 0 );
    }
    v14 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) - 1;
    if ( v3 > v14 )
      v3 = v14;
    COP_Output::SetSelectedItem(this, nSelectItem: v3);
    COP_Output::UpdateValidityButton(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC440
// Name: protected: virtual int COP_Output::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Output::OnInitDialog(COP_Output *this)
{
  LPARAM v2; // eax
  CButton *v3; // eax
  CImageList *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  AFX_MODULE_STATE *v9; // eax
  AFX_MODULE_STATE *v10; // eax
  AFX_MODULE_STATE *v11; // eax
  AFX_MODULE_STATE *v12; // eax
  AFX_MODULE_STATE *v13; // eax
  AFX_MODULE_STATE *v14; // eax
  struct _IMAGELIST *v15; // eax
  AFX_MODULE_STATE *v16; // eax
  HICON v17; // eax
  AFX_MODULE_STATE *v18; // eax
  HICON v19; // eax
  struct _IMAGELIST *v21; // [esp-Ch] [ebp-3C4h]
  struct _IMAGELIST *v22; // [esp-Ch] [ebp-3C4h]
  struct _IMAGELIST *v23; // [esp-Ch] [ebp-3C4h]
  struct _IMAGELIST *v24; // [esp-Ch] [ebp-3C4h]
  struct _IMAGELIST *v25; // [esp-Ch] [ebp-3C4h]
  HICON IconW; // [esp-4h] [ebp-3BCh]
  HICON v27; // [esp-4h] [ebp-3BCh]
  HICON v28; // [esp-4h] [ebp-3BCh]
  HICON v29; // [esp-4h] [ebp-3BCh]
  HICON v30; // [esp-4h] [ebp-3BCh]
  CAnchorDef anchorDefs[21]; // [esp+Ch] [ebp-3ACh] BYREF
  CButton *pButton; // [esp+3A8h] [ebp-10h]
  int v33; // [esp+3B4h] [ebp-4h]

  CDialog::OnInitDialog(this);
  this->m_bIsInstanceIOProxy = false;
  CAutoSelComboBox::SubclassDlgItem(this: &this->m_ComboOutput, nID: 0x3EFu, pParent: this);
  CAutoSelComboBox::SubclassDlgItem(this: &this->m_ComboInput, nID: 0x596u, pParent: this);
  CFilteredComboBox::SubclassDlgItem(this: &this->m_ComboTarget, nID: 0x595u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_CheckBoxFireOnce, nID: 0x5D5u, pParent: this);
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: 49);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 0,
    lpszColumnHeading: (char *)&var,
    nFormat: 2,
    nWidth: 20,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 1u,
    lpszColumnHeading: "My Output",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 2u,
    lpszColumnHeading: "Target Entity",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 3u,
    lpszColumnHeading: "Target Input",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 5u,
    lpszColumnHeading: "Delay",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 6u,
    lpszColumnHeading: "Only Once",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 4u,
    lpszColumnHeading: "Parameter",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  COP_Output::UpdateConnectionList(this);
  COP_Output::SetSortColumn(this, nColumn: this->m_nSortColumn, eDirection: this->m_eSortDirection[this->m_nSortColumn]);
  COP_Output::UpdateColumnHeaderText(
    this,
    nColumn: this->m_nSortColumn,
    bIsSortColumn: true,
    eDirection: this->m_eSortDirection[this->m_nSortColumn]);
  COP_Output::ResizeColumns(this);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strLastParam);
  COP_Output::SetSelectedItem(this, nSelectItem: 0);
  v2 = COP_Output::m_pImageList;
  if ( COP_Output::m_pImageList != 0 )
    goto LABEL_6;
  AfxGetModuleState();
  v3 = (CButton *)operator new(nSize: 8u);
  pButton = v3;
  v33 = 0;
  v4 = v3 != nullptr ? CImageList::CImageList(this: (CImageList *)v3) : nullptr;
  v33 = -1;
  COP_Output::m_pImageList = (LPARAM)v4;
  CImageList::Create(this: v4, cx: 16, cy: 16, nFlags: 1u, nInitial: 1, nGrow: 0);
  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x139);
  v21 = *(struct _IMAGELIST **)(COP_Output::m_pImageList + 4);
  v6 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v6->m_pDllIsolationWrappers,
    himl: v21,
    i: -1,
    hicon: IconW);
  v7 = AfxGetModuleState();
  v27 = LoadIconW(hInstance: v7->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x13A);
  v22 = *(struct _IMAGELIST **)(COP_Output::m_pImageList + 4);
  v8 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v8->m_pDllIsolationWrappers,
    himl: v22,
    i: -1,
    hicon: v27);
  v9 = AfxGetModuleState();
  v28 = LoadIconW(hInstance: v9->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x7A04);
  v23 = *(struct _IMAGELIST **)(COP_Output::m_pImageList + 4);
  v10 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v10->m_pDllIsolationWrappers,
    himl: v23,
    i: -1,
    hicon: v28);
  v11 = AfxGetModuleState();
  v29 = LoadIconW(hInstance: v11->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x7A03);
  v24 = *(struct _IMAGELIST **)(COP_Output::m_pImageList + 4);
  v12 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v12->m_pDllIsolationWrappers,
    himl: v24,
    i: -1,
    hicon: v29);
  v13 = AfxGetModuleState();
  v30 = LoadIconW(hInstance: v13->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x164);
  v25 = *(struct _IMAGELIST **)(COP_Output::m_pImageList + 4);
  v14 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v14->m_pDllIsolationWrappers,
    himl: v25,
    i: -1,
    hicon: v30);
  v2 = COP_Output::m_pImageList;
  if ( COP_Output::m_pImageList != 0 )
LABEL_6:
    v2 = *(_DWORD *)(v2 + 4);
  v15 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1003u, wParam: 1u, lParam: v2);
  CImageList::FromHandle(h: v15);
  pButton = (CButton *)CWnd::GetDlgItem(this, nID: 1534);
  if ( pButton != nullptr )
  {
    AfxGetModuleState();
    v16 = AfxGetModuleState();
    v17 = LoadIconW(hInstance: v16->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x13D);
    SendMessageA(hWnd: pButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)v17);
  }
  pButton = (CButton *)CWnd::GetDlgItem(this, nID: 1535);
  if ( pButton != nullptr )
  {
    AfxGetModuleState();
    v18 = AfxGetModuleState();
    v19 = LoadIconW(hInstance: v18->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x13D);
    SendMessageA(hWnd: pButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)v19);
  }
  CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1428, eSimpleAnchor: k_eSimpleAnchorAllSides);
  CAnchorDef::CAnchorDef(
    this: &anchorDefs[1],
    dlgItemID: 1670,
    eLeftSide: k_eAnchorLeft,
    eTopSide: k_eAnchorBottom,
    eRightSide: k_eAnchorRight,
    eBottomSide: k_eAnchorBottom);
  CAnchorDef::CAnchorDef(this: &anchorDefs[2], dlgItemID: 1671, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[3], dlgItemID: 1672, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[4], dlgItemID: 1673, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[5], dlgItemID: 1674, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[6], dlgItemID: 1675, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[7], dlgItemID: 1009, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[8], dlgItemID: 1493, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[9], dlgItemID: 1431, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[10], dlgItemID: 1430, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[11], dlgItemID: 1429, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[12], dlgItemID: 1007, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[13], dlgItemID: 1534, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[14], dlgItemID: 1535, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[15], dlgItemID: 1303, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[16], dlgItemID: 1390, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[17], dlgItemID: 1263, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[18], dlgItemID: 1354, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[19], dlgItemID: 1305, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[20], dlgItemID: 1648, eSimpleAnchor: k_eSimpleAnchorBottomRight);
  CAnchorMgr::Init(this: &this->m_AnchorMgr, hParentWnd: this->m_hWnd, pAnchors: anchorDefs, nAnchors: 21);
  SendMessageA(
    hWnd: this->m_ctlShowHiddenTargetsAsBroken.m_hWnd,
    Msg: 0xF1u,
    wParam: Options.general.bShowHiddenTargetsAsBroken == 1,
    lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EC960
// Name: public: virtual void COP_Output::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Output::UpdateData(COP_Output *this, int Mode, void *pData, bool bCanEdit)
{
  CObjectPage::UpdateData(this, Mode, pData, bCanEdit);
  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    if ( Mode == 2 )
    {
      SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
      COP_Output::UpdateConnectionList(this);
      COP_Output::SetSelectedItem(this, nSelectItem: 0);
      COP_Output::SortListByColumn(
        this,
        nColumn: this->m_nSortColumn,
        eDirection: this->m_eSortDirection[this->m_nSortColumn]);
    }
    COP_Output::UpdateEditControls(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC9E0
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Output::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COP_Output::GetMessageMap(COP_Output *this)
{
  return (const AFX_MSGMAP *)&off_105EF934;
}

//------------------------------------------------------------------------------
// Address: 0x101B4A40
// Name: public: static bool CDefOps<class DmeTime_t>::LessFunc(class DmeTime_t const __near &,class DmeTime_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<DmeTime_t>::LessFunc(
        const CKeyBindingsMgr::KBContext_t *lhs,
        const CKeyBindingsMgr::KBContext_t *rhs)
{
  return lhs->m_Handle < rhs->m_Handle;
}
