// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_entity.cpp
// Functions: 223
// ============================================================

#include "hammer\op_entity.h"

//------------------------------------------------------------------------------
// Address: 0x10019EB0
// Name: struct DetailObjects::DetailObject_t __near * Construct<struct DetailObjects::DetailObject_t>(struct DetailObjects::DetailObject_t __near *)
// Source: json
//------------------------------------------------------------------------------
DetailObjects::DetailObject_t *__cdecl Construct<DetailObjects::DetailObject_t>(DetailObjects::DetailObject_t *pMemory)
{
  DetailObjects::DetailObject_t *result; // eax
  DetailObjects::DetailObjectGroup_t *m_pMemory; // esi

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_Name.m_Id = -1;
  pMemory->m_Groups.m_Memory.m_pMemory = nullptr;
  pMemory->m_Groups.m_Memory.m_nAllocationCount = 0;
  pMemory->m_Groups.m_Memory.m_nGrowSize = 0;
  m_pMemory = pMemory->m_Groups.m_Memory.m_pMemory;
  pMemory->m_Groups.m_Size = 0;
  pMemory->m_Groups.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6DE0
// Name: public: void CMyComboBox::OnChar(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMyComboBox::OnChar(
        CTextureWindow *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7960
// Name: public: static bool CInstancingHelper::ResolveInstancePath(class IFileSystem __near *,char const __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CInstancingHelper::ResolveInstancePath(
        IFileSystem *pFileSystem,
        const char *pBaseFilename,
        const char *pInstanceFilename,
        const char *pInstanceDirectory,
        char *pResolvedInstanceFilename,
        int nBufferSize)
{
  IBaseFileSystem *v6; // edi
  int v8; // eax
  char *v9; // ecx
  char instanceDirectoryRelativeFilename[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char fixedInstanceFilename[260]; // [esp+110h] [ebp-108h] BYREF
  char *pMapPathPosition; // [esp+214h] [ebp-4h]

  V_strncpy(pDest: fixedInstanceFilename, pSrc: pInstanceFilename, maxLen: 260);
  V_SetExtension(path: fixedInstanceFilename, extension: ".vmf", pathStringLength: 260);
  V_FixSlashes(pname: fixedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: fixedInstanceFilename);
  V_strncpy(pDest: pResolvedInstanceFilename, pSrc: pBaseFilename, maxLen: nBufferSize);
  V_StripFilename(path: pResolvedInstanceFilename);
  V_strncat(pDest: pResolvedInstanceFilename, pSrc: "\\", destBufferSize: nBufferSize, max_chars_to_copy: -1);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: fixedInstanceFilename,
    destBufferSize: nBufferSize,
    max_chars_to_copy: -1);
  V_RemoveDotSlashes(pFilename: pResolvedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: pResolvedInstanceFilename);
  V_FixSlashes(pname: pResolvedInstanceFilename, separator: 92);
  v6 = &pFileSystem->IBaseFileSystem;
  if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: pResolvedInstanceFilename, a3: nullptr) )
    return 1;
  pMapPathPosition = V_stristr(pStr: pResolvedInstanceFilename, pSearch: "\\maps\\");
  if ( pMapPathPosition != nullptr )
  {
    v8 = std::char_traits<char>::length(str: "\\maps\\");
    v9 = &pMapPathPosition[v8];
  }
  else
  {
    if ( V_strnicmp(s1: pResolvedInstanceFilename, s2: "maps\\", n: 5) != 0 )
      goto LABEL_9;
    v9 = pResolvedInstanceFilename + 5;
  }
  if ( v9 != nullptr )
  {
    *v9 = 0;
    V_strncat(
      pDest: pResolvedInstanceFilename,
      pSrc: fixedInstanceFilename,
      destBufferSize: nBufferSize,
      max_chars_to_copy: -1);
    if ( v6->FileExists(this: v6, a2: pResolvedInstanceFilename, a3: nullptr) )
      return 1;
  }
LABEL_9:
  if ( *pInstanceDirectory != 0 )
  {
    V_snprintf(
      pDest: instanceDirectoryRelativeFilename,
      maxLen: nBufferSize,
      pFormat: "%s/%s",
      pInstanceDirectory,
      fixedInstanceFilename);
    V_SetExtension(path: instanceDirectoryRelativeFilename, extension: ".vmf", pathStringLength: 260);
    V_FixSlashes(pname: instanceDirectoryRelativeFilename, separator: 92);
    V_RemoveDotSlashes(pFilename: instanceDirectoryRelativeFilename, separator: 92);
    V_FixDoubleSlashes(pStr: instanceDirectoryRelativeFilename);
    pFileSystem->RelativePathToFullPath(
      this: pFileSystem,
      a2: instanceDirectoryRelativeFilename,
      a3: "GAME",
      a4: pResolvedInstanceFilename,
      a5: nBufferSize,
      a6: FILTER_NONE,
      a7: nullptr);
    if ( v6->FileExists(this: v6, a2: instanceDirectoryRelativeFilename, a3: "GAME") )
      return 1;
  }
  pFileSystem->RelativePathToFullPath(
    this: pFileSystem,
    a2: fixedInstanceFilename,
    a3: "GAME",
    a4: pResolvedInstanceFilename,
    a5: nBufferSize,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( v6->FileExists(this: v6, a2: fixedInstanceFilename, a3: "GAME") )
    return 1;
  if ( nBufferSize > 0 )
    *pResolvedInstanceFilename = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7B80
// Name: public: virtual CColoredListCtrl::~CColoredListCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColoredListCtrl::~CColoredListCtrl(CColoredListCtrl *this)
{
  CListCtrl::~CListCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7BC0
// Name: public: virtual void CPickFaceTarget::OnNotifyPickFace(class CToolPickFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickFaceTarget::OnNotifyPickFace(CPickFaceTarget *this, CToolPickFace *pTool)
{
  this->m_pDlg->UpdatePickFaceText(this: this->m_pDlg, a2: pTool);
}

//------------------------------------------------------------------------------
// Address: 0x100D7BE0
// Name: public: virtual void CSmartControlTargetNameRouter::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartControlTargetNameRouter::OnTextChanged(CSmartControlTargetNameRouter *this, const char *pText)
{
  this->m_pDlg->OnSmartControlTargetNameChanged(this: this->m_pDlg, a2: pText);
}

//------------------------------------------------------------------------------
// Address: 0x100D7C00
// Name: public: virtual struct CRuntimeClass __near * COP_Entity::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Entity::GetRuntimeClass(COP_Entity *this)
{
  return &COP_Entity::classCOP_Entity;
}

//------------------------------------------------------------------------------
// Address: 0x100D7C10
// Name: public: static void CStringListTokenizer::TrimPrefixes(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CStringListTokenizer::TrimPrefixes(char *pszBuffer, const char *pszPrefix)
{
  unsigned __int8 *v2; // esi
  char *v3; // edi
  unsigned int v4; // ebx
  int v5; // eax

  v2 = (unsigned __int8 *)pszBuffer;
  v3 = &pszBuffer[strlen(pszBuffer)];
  v4 = strlen(pszPrefix);
  if ( pszBuffer < v3 )
  {
    do
    {
      if ( StringAfterPrefix(str: (const char *)v2, prefix: pszPrefix) != nullptr )
        memmove(dst: v2, src: &v2[v4], count: &v3[-v4] - (char *)v2 + 1);
      strchr(string: v2, chr: 0x20u);
      if ( v5 == 0 )
        break;
      v2 = (unsigned __int8 *)(v5 + 1);
    }
    while ( v5 + 1 < (unsigned int)v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7C90
// Name: protected: class CRect COP_Entity::CalculateSmartControlRect(void)
// Source: json
//------------------------------------------------------------------------------
CRect *__thiscall COP_Entity::CalculateSmartControlRect(COP_Entity *this, CRect *result)
{
  CWnd *DlgItem; // eax
  int v5; // ebx
  int top; // ecx
  int v7; // edx
  int nRight; // [esp+14h] [ebp+8h]

  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  DlgItem = CWnd::GetDlgItem(this, nID: 1009);
  GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: result);
  CWnd::ScreenToClient(this, lpRect: result);
  v5 = result->bottom - result->top;
  nRight = result->right - 10;
  GetWindowRect(hWnd: this->m_VarList.m_hWnd, lpRect: result);
  CWnd::ScreenToClient(this, lpRect: result);
  top = result->top;
  v7 = result->right + 10;
  result->right = nRight;
  result->left = v7;
  result->bottom = v5 + top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D7D10
// Name: protected: bool COP_Entity::BrowseParticles(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Entity::BrowseParticles(COP_Entity *this, char *szParticleSysName, int length)
{
  char v4; // bl
  CParticleBrowser *v5; // edi
  CParticleBrowser *v6; // eax
  CMainFrame *MainWnd; // eax
  CParticleBrowser *m_pParticleBrowser; // ecx

  v4 = 0;
  if ( this->m_pParticleBrowser == nullptr )
  {
    v5 = (CParticleBrowser *)operator new(nSize: 0x130u);
    v6 = nullptr;
    if ( v5 != nullptr )
    {
      MainWnd = GetMainWnd();
      v6 = CParticleBrowser::CParticleBrowser(this: v5, pParent: MainWnd);
    }
    this->m_pParticleBrowser = v6;
  }
  CParticleBrowser::SetParticleSysName(this: this->m_pParticleBrowser, pParticleSysName: szParticleSysName);
  if ( this->m_pParticleBrowser->DoModal(this: this->m_pParticleBrowser) == 1 )
  {
    CParticleBrowser::GetParticleSysName(this: this->m_pParticleBrowser, pParticleName: szParticleSysName, length);
    v4 = 1;
  }
  m_pParticleBrowser = this->m_pParticleBrowser;
  if ( m_pParticleBrowser != nullptr )
    ((void (__thiscall *)(CParticleBrowser *, int))m_pParticleBrowser->dtr_CObject)(a1: m_pParticleBrowser, a2: 1);
  this->m_pParticleBrowser = nullptr;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100D7DE0
// Name: public: void COP_Entity::SetFlagsPage(class COP_Flags __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetFlagsPage(COP_Entity *this, COP_Flags *pFlagsPage)
{
  this->m_pFlagsPage = pFlagsPage;
}

//------------------------------------------------------------------------------
// Address: 0x100D7DF0
// Name: void LoadFileSystemDialogModule(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadFileSystemDialogModule()
{
  struct CSysModule *Module; // eax
  char str[512]; // [esp+0h] [ebp-200h] BYREF

  Module = Sys_LoadModule(pModuleName: "FileSystemOpenDialog.dll");
  g_pFSDialogModule = Module;
  if ( Module != nullptr )
  {
    g_FSDialogFactory = Sys_GetFactory(pModule: Module);
    if ( g_FSDialogFactory != nullptr )
      return;
    if ( g_pFSDialogModule != nullptr )
    {
      Sys_UnloadModule(pModule: g_pFSDialogModule);
      g_pFSDialogModule = nullptr;
    }
  }
  V_snprintf(pDest: str, maxLen: 512, pFormat: "Can't load %s.\n", "FileSystemOpenDialog.dll");
  AfxMessageBox(lpszText: str, nType: 0, nIDHelp: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D7E70
// Name: void UnloadFileSystemDialogModule(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnloadFileSystemDialogModule()
{
  if ( g_pFSDialogModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFSDialogModule);
    g_pFSDialogModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7E90
// Name: protected: void COP_Entity::OnEntityHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnEntityHelp(COP_Entity *this)
{
  CEntityHelpDlg::ShowEntityHelpDialog();
  CEntityHelpDlg::SetEditGameClass(pClass: this->m_pDisplayClass);
}

//------------------------------------------------------------------------------
// Address: 0x100D7EB0
// Name: protected: virtual bool COP_Entity::OnUnknownEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Entity::OnUnknownEntry(COP_Entity *this, const char *pText)
{
  WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_VarMap[58]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D7EC0
// Name: protected: void COP_Entity::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnSize(COP_Entity *this, unsigned int nType, unsigned int cx, int cy)
{
  CAnchorMgr::OnSize(this: &this->m_AnchorMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100D7F20
// Name: bool UtlStringLessFunc(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UtlStringLessFunc(
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *lhs,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rhs)
{
  return _V_strcmp(s1: lhs->m_pszData, s2: rhs->m_pszData) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7F40
// Name: protected: virtual void COP_Entity::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::DoDataExchange(COP_Entity *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 1106, rControl: &this->m_cValue);
  DDX_Control(pDX, nIDC: 1024, rControl: &this->m_VarList);
  DDX_Control(pDX, nIDC: 1009, rControl: &this->m_cKey);
  DDX_Control(pDX, nIDC: 1494, rControl: &this->m_Comments);
  DDX_Control(pDX, nIDC: 1524, rControl: &this->m_KeyValueHelpText);
  DDX_Control(pDX, nIDC: 1354, rControl: &this->m_PasteControl);
}

//------------------------------------------------------------------------------
// Address: 0x100D7FC0
// Name: protected: void COP_Entity::StopPicking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::StopPicking(COP_Entity *this)
{
  CToolManager *v2; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax
  ToolID_t m_ToolPrePick; // [esp-8h] [ebp-Ch]

  if ( this->m_bPicking )
  {
    m_ToolPrePick = this->m_ToolPrePick;
    this->m_bPicking = false;
    v2 = ToolManager();
    CToolManager::SetTool(this: v2, eNewTool: m_ToolPrePick);
    DlgItem = CWnd::GetDlgItem(this, nID: 1535);
    if ( DlgItem != nullptr )
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1534);
    if ( v4 != nullptr )
      SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1533);
    if ( v5 != nullptr )
      SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8050
// Name: protected: virtual int COP_Entity::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Entity::OnApply(COP_Entity *this)
{
  this->m_pLastSmartControlVar = nullptr;
  COP_Entity::StopPicking(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D8070
// Name: private: int COP_Entity::GetKeyValueRowByShortName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall COP_Entity::GetKeyValueRowByShortName(COP_Entity *this, char *pShortName)
{
  char *m_szLongName; // eax
  GDclass *m_pDisplayClass; // ecx
  HWND__ *m_hWnd; // ecx
  tagLVFINDINFOA fi; // [esp+4h] [ebp-18h] BYREF

  m_szLongName = pShortName;
  if ( this->m_bSmartedit )
  {
    m_pDisplayClass = this->m_pDisplayClass;
    if ( m_pDisplayClass != nullptr )
      m_szLongName = GDclass::VarForName(this: m_pDisplayClass, pszName: pShortName, piIndex: nullptr)->m_szLongName;
  }
  m_hWnd = this->m_VarList.m_hWnd;
  fi.psz = m_szLongName;
  memset(&fi.lParam, 0, 16);
  fi.flags = 2;
  return SendMessageA(hWnd: m_hWnd, Msg: 0x100Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)&fi);
}

//------------------------------------------------------------------------------
// Address: 0x100D80E0
// Name: public: char const __near * CStringListTokenizer::NextToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStringListTokenizer::NextToken(CStringListTokenizer *this)
{
  char *m_pNextToken; // eax
  char *v3; // eax
  unsigned __int8 *v4; // eax
  _BYTE *v5; // eax
  char *v6; // ecx
  char *v8; // edx

  if ( this->m_pNextToken != nullptr )
  {
    do
    {
      m_pNextToken = this->m_pNextToken;
      if ( *m_pNextToken != 32 )
        break;
      v3 = m_pNextToken + 1;
      this->m_pNextToken = v3;
    }
    while ( v3 != nullptr );
  }
  v4 = (unsigned __int8 *)this->m_pNextToken;
  if ( v4 == nullptr || *v4 == 0 )
    return nullptr;
  strchr(string: v4, chr: 0x20u);
  if ( v5 != nullptr )
  {
    *v5 = 0;
    v6 = this->m_pNextToken;
    this->m_pNextToken = v5 + 1;
    this->m_pCurrentToken = v6;
    return v6;
  }
  else
  {
    v8 = this->m_pNextToken;
    this->m_pCurrentToken = v8;
    this->m_pNextToken = nullptr;
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8150
// Name: protected: int COP_Entity::GetCurVarListSelection(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Entity::GetCurVarListSelection(COP_Entity *this)
{
  int v2; // eax
  int v3; // esi

  v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 == 0 )
    return -1;
  v3 = v2 - 1;
  SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100D8190
// Name: protected: void COP_Entity::SetCurVarListSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetCurVarListSelection(COP_Entity *this, int iSel)
{
  LRESULT v3; // eax
  int v4; // esi
  LRESULT v5; // eax
  int v6; // [esp-10h] [ebp-18h]

  v3 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2);
  v4 = v3 + 1;
  if ( v3 != -1 )
  {
    do
    {
      v5 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v4 - 1, lParam: 2);
      v6 = v4 - 1;
      v4 = v5 + 1;
      CListCtrl::SetItemState(this: &this->m_VarList, nItem: v6, nState: 0, nStateMask: 2u);
    }
    while ( v4 != 0 );
  }
  CListCtrl::SetItemState(this: &this->m_VarList, nItem: iSel, nState: 2u, nStateMask: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x100D83A0
// Name: GetMatchingFlagsMask
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GetMatchingFlagsMask@<eax>(GDinputvariable *pVar2@<edi>, GDinputvariable *pVar1)
{
  unsigned int result; // eax
  int v3; // ebx
  int v4; // esi
  GDIVITEM *v5; // eax
  GDIVITEM *v6; // ecx
  int i; // [esp+0h] [ebp-Ch]
  unsigned int nMatchingMask; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  result = 0;
  nMatchingMask = 0;
  i = 0;
  if ( pVar1->m_Items.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v3 = 0;
      if ( pVar2->m_Items.m_Size > 0 )
      {
        v4 = 0;
        while ( 1 )
        {
          v5 = &pVar1->m_Items.m_Memory.m_pMemory[v9];
          v6 = &pVar2->m_Items.m_Memory.m_pMemory[v4];
          if ( v5->iValue == v6->iValue && _V_stricmp(s1: v5->szCaption, s2: v6->szCaption) == 0 )
            break;
          ++v3;
          ++v4;
          if ( v3 >= pVar2->m_Items.m_Size )
            goto LABEL_10;
        }
        nMatchingMask |= pVar1->m_Items.m_Memory.m_pMemory[v9].iValue;
      }
LABEL_10:
      ++v9;
      ++i;
    }
    while ( i < pVar1->m_Items.m_Size );
    return nMatchingMask;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D8440
// Name: private: void COP_Entity::AssignClassDefaults(class GDclass __near *,class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::AssignClassDefaults(COP_Entity *this, GDclass *pClass, GDclass *pOldClass)
{
  GDclass *v3; // ecx
  bool v4; // cc
  GDinputvariable *VariableAt; // edi
  const char *Value; // ebx
  unsigned int m_nDefault; // esi
  GDinputvariable *v8; // eax
  unsigned int MatchingFlagsMask; // eax
  COP_Entity *v10; // edi
  int m_Size; // ecx
  int v12; // eax
  GDIVITEM *m_pMemory; // edi
  MDkeyvalue newkv; // [esp+0h] [ebp-2ECh] BYREF
  char szValue[128]; // [esp+250h] [ebp-9Ch] BYREF
  int iIndex; // [esp+2D0h] [ebp-1Ch] BYREF
  unsigned int nOriginalFlagsValue; // [esp+2D4h] [ebp-18h] BYREF
  int i; // [esp+2D8h] [ebp-14h]
  COP_Entity *v19; // [esp+2DCh] [ebp-10h]
  int v20; // [esp+2E8h] [ebp-4h]

  v19 = this;
  v3 = pClass;
  if ( pClass != nullptr )
  {
    v4 = pClass->m_nVariables <= 0;
    i = 0;
    if ( !v4 )
    {
      do
      {
        VariableAt = GDclass::GetVariableAt(this: v3, iIndex: i);
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v19->m_kv, pszKey: VariableAt->m_szName, piIndex: &iIndex);
        if ( _V_stricmp(s1: VariableAt->m_szName, s2: "spawnflags") != 0 )
        {
          if ( Value == nullptr )
          {
            newkv.szKey[0] = 0;
            newkv.szValue[0] = 0;
            v20 = 0;
            GDinputvariable::ResetDefaults(this: VariableAt);
            GDinputvariable::ToKeyValue(this: VariableAt, pkv: &newkv);
            WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v19->m_kv, pszKey: newkv.szKey, pszValue: newkv.szValue);
            WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v19->m_kvAdded, pszKey: newkv.szKey, pszValue: "1");
            v20 = -1;
            CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&newkv);
          }
        }
        else
        {
          nOriginalFlagsValue = 0;
          if ( Value != nullptr )
            sscanf(string: Value, format: "%lu", &nOriginalFlagsValue);
          if ( pOldClass == nullptr || pOldClass == pClass )
          {
            m_Size = VariableAt->m_Items.m_Size;
            v12 = 0;
            if ( m_Size > 0 )
            {
              m_pMemory = VariableAt->m_Items.m_Memory.m_pMemory;
              do
              {
                v12 |= m_pMemory->iValue;
                ++m_pMemory;
                --m_Size;
              }
              while ( m_Size != 0 );
            }
            v10 = v19;
            m_nDefault = nOriginalFlagsValue & v12;
          }
          else
          {
            m_nDefault = VariableAt->m_nDefault;
            v8 = GDclass::VarForName(this: pOldClass, pszName: "spawnflags", piIndex: nullptr);
            if ( Value != nullptr && v8 != nullptr )
            {
              MatchingFlagsMask = GetMatchingFlagsMask(pVar2: VariableAt, pVar1: v8);
              m_nDefault = nOriginalFlagsValue & MatchingFlagsMask | ~MatchingFlagsMask & m_nDefault;
            }
            v10 = v19;
            COP_Flags::OnUpdateSpawnFlags(this: v19->m_pFlagsPage, value: m_nDefault);
          }
          V_snprintf(pDest: szValue, maxLen: 128, pFormat: "%lu", m_nDefault);
          if ( Value == nullptr || _V_stricmp(s1: Value, s2: szValue) != 0 )
            WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v10->m_kvAdded, pszKey: "spawnflags", pszValue: "1");
          WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v10->m_kv, pszKey: "spawnflags", pszValue: szValue);
        }
        v3 = pClass;
        ++i;
      }
      while ( i < pClass->m_nVariables );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8640
// Name: private: void COP_Entity::SetReadOnly(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetReadOnly(COP_Entity *this, bool bReadOnly)
{
  BOOL v3; // edi
  CWnd *DlgItem; // eax
  unsigned int i; // ebx
  CWnd *v6; // eax
  int j; // ebx
  CWnd **m_pMemory; // eax
  bool v9; // zf
  CWnd **v10; // eax

  v3 = !bReadOnly;
  CWnd::EnableWindow(this: &this->m_VarList, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cPickColor, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_SmartAngle, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_SmartAngleEdit, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_PasteControl, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_KeyValueHelpText, bEnable: v3);
  DlgItem = CWnd::GetDlgItem(this, nID: 1525);
  CWnd::EnableWindow(this: DlgItem, bEnable: v3);
  for ( i = 0; i < 6; ++i )
  {
    v6 = CWnd::GetDlgItem(this, nID: g_DumbEditControls[i]);
    if ( v6 != nullptr )
      CWnd::EnableWindow(this: v6, bEnable: !bReadOnly);
  }
  for ( j = 0; j < this->m_SmartControls.m_Size; ++j )
  {
    m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
    v9 = m_pMemory[j] == nullptr;
    v10 = &m_pMemory[j];
    if ( !v9 )
      CWnd::EnableWindow(this: *v10, bEnable: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8A50
// Name: IsValidTargetName
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidTargetName(const char *pTestName)
{
  CMapWorld *m_pWorld; // esi
  int v2; // edi
  CMapEntity *m_pObject; // eax
  const char *Value; // eax

  m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
  v2 = 0;
  if ( m_pWorld->m_EntityList.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_pObject = m_pWorld->m_EntityList.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&m_pWorld->m_EntityList.m_Memory
                                                                                   + 2) >> 27)][v2
                                                                                              & ((32
                                                                                                * *((_DWORD *)&m_pWorld->m_EntityList.m_Memory
                                                                                                  + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: &m_pObject->m_KeyValues,
                pszKey: "targetname",
                piIndex: nullptr);
      if ( Value != nullptr && _V_stricmp(s1: Value, s2: pTestName) == 0 )
        break;
    }
    if ( ++v2 >= m_pWorld->m_EntityList.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D8AE0
// Name: int InternalSortByColumn(class COP_Entity __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl InternalSortByColumn(COP_Entity *pDlg, char *pShortName1, char *pShortName2, int iColumn)
{
  char *m_szLongName; // eax
  COP_Entity *v5; // esi
  GDclass *m_pDisplayClass; // ecx
  HWND m_hWnd; // ecx
  WPARAM v8; // edi
  char *v9; // eax
  GDclass *v10; // ecx
  const char *v11; // eax
  int v12; // ebx
  int v13; // esi
  const char *v14; // eax
  unsigned int *v15; // eax
  HWND v17; // [esp-10h] [ebp-40h]
  LPARAM lParam[2]; // [esp+Ch] [ebp-24h] BYREF
  __int64 v19; // [esp+14h] [ebp-1Ch]
  __int64 v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+2Ch] [ebp-4h]

  m_szLongName = pShortName1;
  v5 = pDlg;
  if ( pDlg->m_bSmartedit )
  {
    m_pDisplayClass = pDlg->m_pDisplayClass;
    if ( m_pDisplayClass != nullptr )
      m_szLongName = GDclass::VarForName(this: m_pDisplayClass, pszName: pShortName1, piIndex: nullptr)->m_szLongName;
  }
  m_hWnd = v5->m_VarList.m_hWnd;
  lParam[1] = (LPARAM)m_szLongName;
  v19 = 0;
  v20 = 0;
  lParam[0] = 2;
  v8 = SendMessageA(hWnd: m_hWnd, Msg: 0x100Du, wParam: 0xFFFFFFFF, (LPARAM)lParam);
  v9 = pShortName2;
  if ( v5->m_bSmartedit )
  {
    v10 = v5->m_pDisplayClass;
    if ( v10 != nullptr )
      v9 = GDclass::VarForName(this: v10, pszName: pShortName2, piIndex: nullptr)->m_szLongName;
  }
  lParam[0] = 0;
  lParam[1] = (LPARAM)v9;
  v17 = v5->m_VarList.m_hWnd;
  v19 = 0;
  v20 = 0;
  lParam[0] = 2;
  v11 = (const char *)SendMessageA(hWnd: v17, Msg: 0x100Du, wParam: 0xFFFFFFFF, (LPARAM)lParam);
  pShortName2 = (char *)v11;
  if ( v8 == -1 || v11 == (const char *)-1 )
    return 0;
  v12 = iColumn;
  CListCtrl::GetItemText(
    this: &v5->m_VarList,
    result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDlg,
    nItem: v8,
    nSubItem: iColumn);
  v21 = 0;
  CListCtrl::GetItemText(
    this: &v5->m_VarList,
    result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pShortName1,
    nItem: (WPARAM)pShortName2,
    nSubItem: v12);
  LOBYTE(v21) = 1;
  v13 = _V_stricmp(s1: (const char *)pDlg, s2: pShortName1);
  LOBYTE(v21) = 0;
  v14 = pShortName1 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)pShortName1 - 1) <= 0 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v14 + 4))(a1: v14);
  v21 = -1;
  v15 = &pDlg[-1].CustomColors[13];
  if ( _InterlockedDecrement((volatile signed __int32 *)&pDlg[-1].m_bCustomColorsLoaded) <= 0 )
    (*(void (__stdcall **)(unsigned int *))(*(_DWORD *)*v15 + 4))(a1: v15);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x100D8C80
// Name: SortByColumn0
// Source: json
//------------------------------------------------------------------------------
int __stdcall SortByColumn0(char *iItem1, char *iItem2, COP_Entity *lpParam)
{
  return InternalSortByColumn(pDlg: lpParam, pShortName1: iItem1, pShortName2: iItem2, iColumn: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D8CA0
// Name: SortByColumn1
// Source: json
//------------------------------------------------------------------------------
int __stdcall SortByColumn1(char *iItem1, char *iItem2, COP_Entity *lpParam)
{
  return InternalSortByColumn(pDlg: lpParam, pShortName1: iItem1, pShortName2: iItem2, iColumn: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100D8CC0
// Name: public: CInstanceParmData::CInstanceParmData(void)
// Source: json
//------------------------------------------------------------------------------
CInstanceParmData *__thiscall CInstanceParmData::CInstanceParmData(CInstanceParmData *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_ParmKey; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v4; // eax

  p_m_ParmKey = &this->m_ParmKey;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_ParmKey->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_VariableName.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D8D60
// Name: public: CInstanceParmData::~CInstanceParmData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstanceParmData::~CInstanceParmData(CBoolString *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax

  v2 = (volatile signed __int32 *)(this->m_strOff.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strOn.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D8DF0
// Name: private: class GDinputvariable __near * COP_Entity::GetVariableAt(int)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall COP_Entity::GetVariableAt(COP_Entity *this, int index)
{
  __int16 v2; // ax

  v2 = this->m_VarMap[index];
  if ( v2 == -1 )
    return nullptr;
  if ( v2 > -10 )
    return GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v2);
  return this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v2)].m_Data.elem.m_ParmVariable;
}

//------------------------------------------------------------------------------
// Address: 0x100D8E40
// Name: protected: virtual bool COP_Entity::CustomDrawItemValue(struct tagDRAWITEMSTRUCT __near * const,struct tagRECT const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Entity::CustomDrawItemValue(COP_Entity *this, tagDRAWITEMSTRUCT *const p, const tagRECT *pRect)
{
  tagDRAWITEMSTRUCT *v4; // esi
  unsigned int itemID; // eax
  GDinputvariable *VariableAt; // eax
  GDinputvariable *v8; // edi
  GDIV_TYPE m_eType; // eax
  const char *Value; // eax
  HBRUSH SolidBrush; // edi
  HPEN Pen; // ebx
  float fb; // [esp+18h] [ebp-14h] BYREF
  float fg; // [esp+1Ch] [ebp-10h] BYREF
  float fr; // [esp+20h] [ebp-Ch] BYREF
  int r; // [esp+24h] [ebp-8h] BYREF
  int g; // [esp+28h] [ebp-4h] BYREF

  if ( LOBYTE(this->m_SmartAngle.m_pfnSuper) == 0 )
    return 0;
  v4 = p;
  itemID = p->itemID;
  if ( itemID >= 0x80
    || *((__int16 *)&this->m_SmartAngle.m_DragDC.m_bPrinting + itemID) < 0
    || this->m_SmartAngle.m_DragDC.m_hDC == nullptr )
  {
    return 0;
  }
  VariableAt = COP_Entity::GetVariableAt(this: (COP_Entity *)((char *)this - 188), index: itemID);
  v8 = VariableAt;
  if ( VariableAt == nullptr )
    return 0;
  m_eType = VariableAt->m_eType;
  if ( m_eType != ivColor255 && m_eType != ivColor1 )
    return 0;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
            this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_VarMap[56],
            pszKey: v8->m_szName,
            piIndex: nullptr);
  if ( Value == nullptr )
    return 0;
  if ( v8->m_eType == ivColor255 )
  {
    sscanf(string: Value, format: "%d %d %d", &r, &g, &p);
  }
  else
  {
    sscanf(string: Value, format: "%f %f %f", &fr, &fg, &fb);
    r = (int)(fr * 255.0);
    g = (int)(fg * 255.0);
    p = (tagDRAWITEMSTRUCT *const)(int)(fb * 255.0);
  }
  SolidBrush = CreateSolidBrush(color: (unsigned __int8)r | (((unsigned __int8)g | ((unsigned __int8)p << 8)) << 8));
  Pen = CreatePen(iStyle: 0, cWidth: 0, color: 0);
  SelectObject(hdc: v4->hDC, h: SolidBrush);
  SelectObject(hdc: v4->hDC, h: Pen);
  Rectangle(
    hdc: v4->hDC,
    left: pRect->left + 6,
    top: pRect->top + 2,
    right: pRect->right - 6,
    bottom: pRect->bottom - 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D99A0
// Name: public: CMapFaceIDList::~CMapFaceIDList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFaceIDList::~CMapFaceIDList(CMapFaceIDList *this)
{
  bool v2; // sf

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9A30
// Name: public: CStringListTokenizer::CStringListTokenizer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStringListTokenizer *__thiscall CStringListTokenizer::CStringListTokenizer(
        CStringListTokenizer *this,
        const char *szString)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  this->m_pString.m_p = nullptr;
  this->m_pString.m_p = nullptr;
  this->m_pNextToken = nullptr;
  this->m_pCurrentToken = nullptr;
  if ( szString != nullptr )
  {
    v3 = (char *)operator new[](nSize: strlen(szString) + 1);
    this->m_pString.m_p = v3;
    v4 = szString;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
    this->m_pNextToken = this->m_pString.m_p;
    this->m_pCurrentToken = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D9AC0
// Name: public: CStringListTokenizer::~CStringListTokenizer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringListTokenizer::~CStringListTokenizer(CStringListTokenizer *this)
{
  char *v2; // [esp-8h] [ebp-1Ch]
  char *m_p; // [esp-4h] [ebp-18h]

  m_p = this->m_pString.m_p;
  this->m_pString.m_p = nullptr;
  operator delete(p: m_p);
  v2 = this->m_pString.m_p;
  this->m_pString.m_p = nullptr;
  operator delete(p: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100D9B20
// Name: protected: void COP_Entity::BrowseTextures(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::BrowseTextures(COP_Entity *this, const char *szFilter, char bSprite)
{
  int v4; // eax
  int v5; // edi
  __int16 v6; // ax
  GDinputvariable *v7; // ebx
  CTextureBrowser *v8; // edi
  CMainFrame *MainWnd; // eax
  CTextureBrowser *v10; // edi
  IEditorTexture *ActiveTexture; // eax
  const char *m_szName; // ebx
  char szInitialTexture[128]; // [esp+Ch] [ebp-194h] BYREF
  char szName[260]; // [esp+8Ch] [ebp-114h] BYREF
  CTextureBrowser *v15; // [esp+190h] [ebp-10h]
  int v16; // [esp+19Ch] [ebp-4h]

  v4 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v4 != 0 )
  {
    v5 = v4 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v4 - 1, lParam: 2);
  }
  else
  {
    v5 = -1;
  }
  v6 = this->m_VarMap[v5];
  if ( v6 != -1 )
  {
    v7 = v6 > -10
       ? GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v6)
       : this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v6)].m_Data.elem.m_ParmVariable;
    if ( v7 != nullptr )
    {
      CWnd::GetWindowTextA(this: this->m_pSmartControl, lpszString: szInitialTexture, nMaxCount: 128);
      v8 = (CTextureBrowser *)operator new(nSize: 0xD00u);
      v15 = v8;
      v16 = 0;
      if ( v8 != nullptr )
      {
        MainWnd = GetMainWnd();
        v10 = CTextureBrowser::CTextureBrowser(this: v8, pParent: MainWnd);
      }
      else
      {
        v10 = nullptr;
      }
      v16 = -1;
      if ( *szFilter != 0 )
        CTextureBrowser::SetFilter(this: v10, pszFilter: szFilter);
      CTextureBrowser::SetInitialTexture(this: v10, pszTexture: szInitialTexture);
      if ( v10->DoModal(this: v10) == 1 )
      {
        ActiveTexture = CTextureSystem::FindActiveTexture(
                          this: &g_Textures,
                          pszInputName: v10->m_cTextureWindow.szCurTexture,
                          piIndex: nullptr,
                          bDummy: 1);
        if ( ActiveTexture != nullptr )
          ActiveTexture->GetShortName(this: ActiveTexture, a2: szName);
        else
          szName[0] = 0;
        if ( bSprite != 0 && g_pGameConfig->textureformat == tfVMT )
        {
          V_snprintf(pDest: &bSprite, maxLen: 4, pFormat: ".vmt");
          V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s.vmt", szName);
        }
        CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: szName);
        m_szName = v7->m_szName;
        WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: m_szName, pszValue: szName);
        WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kvAdded, pszKey: m_szName, pszValue: "1");
      }
      ((void (__thiscall *)(CTextureBrowser *, int))v10->dtr_CObject)(a1: v10, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9D10
// Name: protected: virtual bool COP_Entity::HandleBrowse(class CStringList __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __thiscall COP_Entity::HandleBrowse(COP_Entity *this, CStringList *lstBrowse)
{
  bool v2; // zf
  void *v4; // esi
  int v5; // eax
  char v6; // al
  unsigned int v7; // edi
  char *i; // eax
  char str[512]; // [esp+0h] [ebp-220h] BYREF
  CStringListTokenizer lstScripts; // [esp+200h] [ebp-20h] BYREF
  COP_Entity *v11; // [esp+20Ch] [ebp-14h]
  CArrayAutoPtr<char> szResultBuffer; // [esp+210h] [ebp-10h] BYREF
  int v13; // [esp+21Ch] [ebp-4h]

  v2 = *(_DWORD *)&this->m_VarMap[82] == 29;
  v11 = this;
  if ( !v2 || g_FSDialogFactory == nullptr )
    return 0;
  v4 = g_FSDialogFactory(a1: "FileSystemOpenDlg003", a2: nullptr);
  if ( v4 != nullptr )
  {
    (**(void (__thiscall ***)(void *, void *(__cdecl *)(const char *, int *), _DWORD))v4)(a1: v4, a2: g_Factory, a3: 0);
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v4 + 8))(a1: v4, a2: "*.nut");
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v4 + 8))(a1: v4, a2: "*.gm");
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v4 + 32))(a1: v4, a2: 1);
    if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
      || (v5 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-NewDialogs") != 0) )
    {
      v6 = (*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 24))(a1: v4);
    }
    else
    {
      v6 = (*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 28))(a1: v4);
    }
    if ( v6 == 1 )
    {
      v7 = (*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 36))(a1: v4);
      szResultBuffer.m_p = (char *)operator new[](nSize: v7);
      v13 = 1;
      (*(void (__thiscall **)(void *, char *, unsigned int))(*(_DWORD *)v4 + 20))(
        a1: v4,
        a2: szResultBuffer.m_p,
        a3: v7);
      V_FixSlashes(pname: szResultBuffer.m_p, separator: 47);
      if ( *(_DWORD *)&v11->m_VarMap[82] == 29 )
        CStringListTokenizer::TrimPrefixes(pszBuffer: szResultBuffer.m_p, pszPrefix: "scripts/vscripts/");
      CStringListTokenizer::CStringListTokenizer(this: &lstScripts, szString: szResultBuffer.m_p);
      LOBYTE(v13) = 2;
      for ( i = CStringListTokenizer::NextToken(this: &lstScripts);
            i != nullptr;
            i = CStringListTokenizer::NextToken(this: &lstScripts) )
      {
        CStringList::AddTail(this: lstBrowse, newElement: i);
      }
      LOBYTE(v13) = 1;
      CStringListTokenizer::~CStringListTokenizer(this: &lstScripts);
      v13 = -1;
      CArrayAutoPtr<char>::~CArrayAutoPtr<char>(this: &szResultBuffer);
    }
    (*(void (__thiscall **)(void *))(*(_DWORD *)v4 + 4))(a1: v4);
    return 1;
  }
  else
  {
    V_snprintf(pDest: str, maxLen: 512, pFormat: "Can't create %s interface.", "FileSystemOpenDlg003");
    AfxMessageBox(lpszText: str, nType: 0, nIDHelp: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9F00
// Name: protected: void COP_Entity::OnPickAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPickAngles(COP_Entity *this)
{
  CWnd *DlgItem; // eax
  int CurVarListSelection; // eax
  CToolManager *v4; // eax
  CToolManager *v5; // eax
  CBaseTool *ToolForID; // eax
  CToolManager *v7; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1535);
    if ( DlgItem != nullptr )
    {
      if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
      {
        CurVarListSelection = COP_Entity::GetCurVarListSelection(this);
        if ( CurVarListSelection != -1 && COP_Entity::GetVariableAt(this, index: CurVarListSelection) != nullptr )
        {
          v4 = ToolManager();
          this->m_ToolPrePick = CToolManager::GetActiveToolID(this: v4);
          this->m_bPicking = true;
          v5 = ToolManager();
          ToolForID = CToolManager::GetToolForID(this: v5, eToolID: TOOL_PICK_ANGLES);
          this->m_PickAnglesTarget.m_pDlg = this;
          ToolForID[1].__vftable = (CBaseTool_vtbl *)&this->m_PickAnglesTarget;
          v7 = ToolManager();
          CToolManager::SetTool(this: v7, eNewTool: TOOL_PICK_ANGLES);
        }
      }
      else
      {
        COP_Entity::StopPicking(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9FA0
// Name: protected: void COP_Entity::OnPickEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPickEntity(COP_Entity *this)
{
  CWnd *DlgItem; // eax
  int CurVarListSelection; // eax
  GDinputvariable *VariableAt; // edi
  CToolManager *v5; // eax
  CToolManager *v6; // eax
  CBaseTool *ToolForID; // ebx
  int m_eType; // eax
  CToolManager *v9; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1534);
    if ( DlgItem != nullptr )
    {
      if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
      {
        CurVarListSelection = COP_Entity::GetCurVarListSelection(this);
        if ( CurVarListSelection != -1 )
        {
          VariableAt = COP_Entity::GetVariableAt(this, index: CurVarListSelection);
          if ( VariableAt != nullptr )
          {
            v5 = ToolManager();
            this->m_ToolPrePick = CToolManager::GetActiveToolID(this: v5);
            this->m_bPicking = true;
            v6 = ToolManager();
            ToolForID = CToolManager::GetToolForID(this: v6, eToolID: TOOL_PICK_ENTITY);
            this->m_PickEntityTarget.m_pDlg = this;
            m_eType = VariableAt->m_eType;
            if ( m_eType > 0 )
            {
              if ( m_eType <= 3 )
              {
                strncpy(dest: (unsigned __int8 *)this->m_PickEntityTarget.m_szKey, source: "targetname", count: 0x3FFu);
              }
              else if ( m_eType == 27 )
              {
                strncpy(dest: (unsigned __int8 *)this->m_PickEntityTarget.m_szKey, source: "nodeid", count: 0x3FFu);
              }
            }
            ToolForID[1].__vftable = (CBaseTool_vtbl *)&this->m_PickEntityTarget;
            v9 = ToolManager();
            CToolManager::SetTool(this: v9, eNewTool: TOOL_PICK_ENTITY);
          }
        }
      }
      else
      {
        COP_Entity::StopPicking(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA0A0
// Name: protected: virtual void COP_Entity::UpdatePickFaceText(class CToolPickFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdatePickFaceText(COP_Entity *this, CToolPickFace *pTool)
{
  char szList[512]; // [esp+8h] [ebp-234h] BYREF
  CMapFaceList FaceListPartial; // [esp+208h] [ebp-34h] BYREF
  CMapFaceList FaceListFull; // [esp+21Ch] [ebp-20h] BYREF
  int v6; // [esp+238h] [ebp-4h]

  szList[0] = 0;
  memset(&FaceListFull, 0, sizeof(FaceListFull));
  v6 = 5;
  memset(&FaceListPartial, 0, sizeof(FaceListPartial));
  CToolPickFace::GetSelectedFaces(this: pTool, &FaceListFull, &FaceListPartial);
  if ( CMapWorld::FaceID_FaceListsToString(
         pszList: szList,
         nSize: 512,
         pFullFaceList: &FaceListFull,
         pPartialFaceList: &FaceListPartial) == 0 )
    CWnd::MessageBoxA(
      this,
      lpszText: "Too many faces selected for this keyvalue to hold. Deselect some faces.",
      lpszCaption: "Error",
      nType: 0);
  CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: szList);
  LOBYTE(v6) = 2;
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&FaceListPartial);
  v6 = -1;
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&FaceListFull);
}

//------------------------------------------------------------------------------
// Address: 0x100DA3D0
// Name: public: virtual void CColoredListCtrl::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColoredListCtrl::DrawItem(CColoredListCtrl *this, tagDRAWITEMSTRUCT *p)
{
  tagDRAWITEMSTRUCT *v2; // esi
  CDC *v4; // edi
  HBRUSH SolidBrush; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *ItemText; // eax
  char *v7; // eax
  CColoredListCtrl::IItemColorCallback *m_pCallback; // ecx
  WPARAM v9; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v10; // eax
  char *v11; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-A0h]
  WPARAM itemID; // [esp-8h] [ebp-98h]
  tagLVCOLUMNA columnInfo; // [esp+Ch] [ebp-84h] BYREF
  tagRECT rcFill; // [esp+38h] [ebp-58h]
  tagRECT rcItem; // [esp+48h] [ebp-48h] BYREF
  tagLOGBRUSH logBrush; // [esp+58h] [ebp-38h] BYREF
  CPen pen; // [esp+64h] [ebp-2Ch] BYREF
  CPen dashedPen; // [esp+6Ch] [ebp-24h] BYREF
  CBrush br; // [esp+74h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+7Ch] [ebp-14h] BYREF
  unsigned int txtColor; // [esp+80h] [ebp-10h] BYREF
  int v23; // [esp+8Ch] [ebp-4h]

  v2 = p;
  v4 = CDC::FromHandle(hDC: p->hDC);
  this->m_pCallback->GetItemColor(this: this->m_pCallback, a2: v2->itemID, a3: (unsigned int *)&p, a4: &txtColor);
  br.m_hObject = nullptr;
  br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v23 = 1;
  CPen::CPen(this: &pen, nPenStyle: 0, nWidth: 0, crColor: (unsigned int)p);
  LOBYTE(v23) = 2;
  logBrush.lbColor = 0;
  logBrush.lbHatch = 4;
  logBrush.lbStyle = 0;
  CPen::CPen(this: &dashedPen, nPenStyle: 8, nWidth: 1, pLogBrush: &logBrush, nStyleCount: 0, lpStyle: nullptr);
  LOBYTE(v23) = 3;
  if ( (v2->itemState & 1) != 0 )
    CDC::SelectObject(this: v4, pFont: (CFont *)&dashedPen);
  else
    CDC::SelectObject(this: v4, pFont: (CFont *)&pen);
  SolidBrush = CreateSolidBrush(color: (COLORREF)p);
  CGdiObject::Attach(this: &br, hObject: SolidBrush);
  CDC::SelectObject(this: v4, pFont: (CFont *)&br);
  rcFill = v2->rcItem;
  Rectangle(hdc: v4->m_hDC, left: rcFill.left, top: rcFill.top, right: rcFill.right, bottom: rcFill.bottom - 1);
  v4->SetTextColor(this: v4, a2: txtColor);
  itemID = v2->itemID;
  *(_QWORD *)&rcItem.left = *(_QWORD *)&v2->rcItem.left;
  rcItem.left += 3;
  *(_QWORD *)&rcItem.right = *(_QWORD *)&v2->rcItem.right;
  ItemText = CListCtrl::GetItemText(this, &result, nItem: itemID, nSubItem: 0);
  LOBYTE(v23) = 4;
  v4->DrawTextA(this: v4, a2: ItemText->m_pszData, a3: *((_DWORD *)ItemText->m_pszData - 3), a4: &rcItem, a5: 4u);
  LOBYTE(v23) = 3;
  v7 = result.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  m_hWnd = this->m_hWnd;
  columnInfo.mask = 2;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1019u, wParam: 0, lParam: (LPARAM)&columnInfo);
  m_pCallback = this->m_pCallback;
  *(_QWORD *)&rcItem.left = *(_QWORD *)&v2->rcItem.left;
  rcItem.left += columnInfo.cx;
  *(_QWORD *)&rcItem.right = *(_QWORD *)&v2->rcItem.right;
  if ( !m_pCallback->CustomDrawItemValue(this: m_pCallback, a2: v2, a3: &rcItem) )
  {
    v9 = v2->itemID;
    rcItem.left += 3;
    v10 = CListCtrl::GetItemText(this, &result, nItem: v9, nSubItem: 1);
    LOBYTE(v23) = 6;
    v4->DrawTextA(this: v4, a2: v10->m_pszData, a3: *((_DWORD *)v10->m_pszData - 3), a4: &rcItem, a5: 4u);
    LOBYTE(v23) = 3;
    v11 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
  }
  dashedPen.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v23) = 2;
  CGdiObject::~CGdiObject(this: &dashedPen);
  pen.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v23) = 1;
  CGdiObject::~CGdiObject(this: &pen);
  br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v23 = -1;
  CGdiObject::~CGdiObject(this: &br);
}

//------------------------------------------------------------------------------
// Address: 0x100DA640
// Name: protected: void COP_Entity::ApplyKeyValueToObject(class CEditGameClass __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::ApplyKeyValueToObject(
        COP_Entity *this,
        CEditGameClass *pObject,
        const char *pszKey,
        const char *pszValue)
{
  CEditGameClass *v4; // ebx
  GDclass *m_pClass; // ecx
  GDinputvariable *v6; // eax
  GDIV_TYPE m_eType; // eax
  CMapWorld *ActiveWorld; // esi
  const char *Value; // eax
  int v10; // eax
  int m_Size; // ecx
  int v12; // ebx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int *v16; // eax
  char szSetValue[512]; // [esp+8h] [ebp-25Ch] BYREF
  CMapFaceIDList CurFaceList; // [esp+208h] [ebp-5Ch] BYREF
  CMapFaceIDList FullFaceList; // [esp+21Ch] [ebp-48h] BYREF
  CMapFaceIDList PartialFaceList; // [esp+230h] [ebp-34h] BYREF
  CMapFaceIDList KeepFaceList; // [esp+244h] [ebp-20h] BYREF
  int v22; // [esp+260h] [ebp-4h]
  int i; // [esp+274h] [ebp+10h]

  v4 = pObject;
  m_pClass = pObject->m_pClass;
  if ( m_pClass != nullptr
    && (v6 = GDclass::VarForName(this: m_pClass, pszName: pszKey, piIndex: nullptr)) != nullptr
    && ((m_eType = v6->m_eType) == ivSideList || m_eType == ivSide) )
  {
    ActiveWorld = GetActiveWorld();
    memset(&CurFaceList, 0, sizeof(CurFaceList));
    v22 = 2;
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pObject->m_KeyValues, pszKey, piIndex: nullptr);
    if ( Value != nullptr )
      CMapWorld::FaceID_StringToFaceIDLists(
        this: ActiveWorld,
        pFullFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&CurFaceList,
        pPartialFaceList: nullptr,
        pszValue: Value);
    memset(&FullFaceList, 0, sizeof(FullFaceList));
    memset(&PartialFaceList, 0, sizeof(PartialFaceList));
    LOBYTE(v22) = 8;
    CMapWorld::FaceID_StringToFaceIDLists(
      this: ActiveWorld,
      pFullFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&FullFaceList,
      pPartialFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&PartialFaceList,
      pszValue);
    memset(&KeepFaceList, 0, sizeof(KeepFaceList));
    LOBYTE(v22) = 11;
    v10 = 0;
    i = 0;
    if ( PartialFaceList.m_Size > 0 )
    {
      m_Size = KeepFaceList.m_Size;
      do
      {
        v12 = PartialFaceList.m_Memory.m_pMemory[v10];
        v13 = 0;
        if ( CurFaceList.m_Size > 0 )
        {
          while ( CurFaceList.m_Memory.m_pMemory[v13] != v12 )
          {
            if ( ++v13 >= CurFaceList.m_Size )
              goto LABEL_20;
          }
          if ( v13 != -1 )
          {
            v14 = m_Size;
            if ( m_Size + 1 > KeepFaceList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&KeepFaceList,
                num: m_Size - KeepFaceList.m_Memory.m_nAllocationCount + 1);
              m_Size = KeepFaceList.m_Size;
            }
            KeepFaceList.m_Size = ++m_Size;
            v15 = m_Size - v14 - 1;
            KeepFaceList.m_pElements = KeepFaceList.m_Memory.m_pMemory;
            if ( v15 > 0 )
            {
              _V_memmove(
                dest: &KeepFaceList.m_Memory.m_pMemory[v14 + 1],
                src: &KeepFaceList.m_Memory.m_pMemory[v14],
                count: 4 * v15);
              m_Size = KeepFaceList.m_Size;
            }
            v16 = &KeepFaceList.m_Memory.m_pMemory[v14];
            if ( v16 != nullptr )
            {
              *v16 = v12;
              m_Size = KeepFaceList.m_Size;
            }
          }
        }
LABEL_20:
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < PartialFaceList.m_Size );
      v4 = pObject;
    }
    CUtlVector<int,CUtlMemory<int,int>>::AddVectorToTail(this: &FullFaceList, src: &KeepFaceList);
    CMapWorld::FaceID_FaceIDListsToString(
      pszList: szSetValue,
      nSize: 512,
      pFullFaceIDList: &FullFaceList,
      pPartialFaceIDList: nullptr);
    v4->SetKeyValue(this: v4, a2: pszKey, a3: szSetValue);
    LOBYTE(v22) = 8;
    CMapFaceIDList::~CMapFaceIDList(this: &KeepFaceList);
    LOBYTE(v22) = 5;
    CMapFaceIDList::~CMapFaceIDList(this: &PartialFaceList);
    LOBYTE(v22) = 2;
    CMapFaceIDList::~CMapFaceIDList(this: &FullFaceList);
    v22 = -1;
    CMapFaceIDList::~CMapFaceIDList(this: &CurFaceList);
  }
  else
  {
    pObject->SetKeyValue(this: pObject, a2: pszKey, a3: pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA880
// Name: private: void COP_Entity::RefreshKVListValues(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::RefreshKVListValues(COP_Entity *this, const char *pOnlyThisVar)
{
  COP_Entity *v2; // ebx
  HWND__ *m_hWnd; // eax
  CListCtrl *p_m_VarList; // esi
  const char *ItemData; // edi
  GDclass *m_pDisplayClass; // ecx
  GDinputvariable *v7; // eax
  GDinputvariable *v8; // esi
  char *Value; // edi
  GDIV_TYPE m_eType; // eax
  const char *v11; // eax
  char *v12; // ebx
  unsigned __int8 *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // eax
  int v17; // eax
  const char *v18; // edi
  unsigned int v19; // eax
  unsigned int v20; // esi
  unsigned int v21; // eax
  int v22; // eax
  LRESULT v23; // edi
  HWND v24; // [esp-18h] [ebp-240h]
  int v25; // [esp-14h] [ebp-23Ch]
  char *v26; // [esp-Ch] [ebp-234h]
  char tmpValueBuf[512]; // [esp+4h] [ebp-224h] BYREF
  CStringListTokenizer lstScripts; // [esp+204h] [ebp-24h] BYREF
  COP_Entity *v29; // [esp+210h] [ebp-18h]
  int i; // [esp+214h] [ebp-14h]
  const char *pValue; // [esp+218h] [ebp-10h]
  int v32; // [esp+224h] [ebp-4h]

  v2 = this;
  m_hWnd = this->m_VarList.m_hWnd;
  v29 = this;
  i = 0;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
  {
    p_m_VarList = &v2->m_VarList;
    while ( 1 )
    {
      ItemData = (const char *)CListCtrl::GetItemData(this: p_m_VarList, nItem: i);
      if ( pOnlyThisVar != nullptr && _V_stricmp(s1: ItemData, s2: pOnlyThisVar) != 0 )
        goto LABEL_45;
      if ( !v2->m_bSmartedit )
        break;
      m_pDisplayClass = v2->m_pDisplayClass;
      if ( m_pDisplayClass == nullptr )
        break;
      v7 = GDclass::VarForName(this: m_pDisplayClass, pszName: ItemData, piIndex: nullptr);
      v8 = v7;
      if ( v7 == nullptr )
        break;
      Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v2->m_kv, pszKey: v7->m_szName, piIndex: nullptr);
      if ( Value == nullptr )
        goto LABEL_43;
      m_eType = v8->m_eType;
      switch ( m_eType )
      {
        case ivChoices:
          v11 = GDinputvariable::ItemStringForValue(this: v8, szValue: Value);
          if ( v11 != nullptr )
            goto LABEL_40;
          break;
        case ivStudioModel:
        case ivSprite:
        case ivSound:
        case ivDecal:
        case ivMaterial:
        case ivScene:
        case ivScript:
          strrchr(string: (unsigned __int8 *)Value, chr: 0x5Cu);
          v20 = v19;
          strrchr(string: (unsigned __int8 *)Value, chr: 0x2Fu);
          if ( v20 <= v21 )
            strrchr(string: (unsigned __int8 *)Value, chr: 0x2Fu);
          else
            strrchr(string: (unsigned __int8 *)Value, chr: 0x5Cu);
          if ( v22 != 0 )
          {
            V_strncpy(pDest: tmpValueBuf, pSrc: (const char *)(v22 + 1), maxLen: 512);
            v26 = tmpValueBuf;
            v25 = i;
            goto LABEL_44;
          }
          break;
        case ivScriptList:
          CStringListTokenizer::CStringListTokenizer(this: &lstScripts, szString: Value);
          v32 = 0;
          v12 = tmpValueBuf;
          v13 = (unsigned __int8 *)CStringListTokenizer::NextToken(this: &lstScripts);
          if ( v13 != nullptr )
          {
            pValue = tmpValueBuf;
            do
            {
              strrchr(string: v13, chr: 0x5Cu);
              v15 = v14;
              strrchr(string: v13, chr: 0x2Fu);
              if ( v15 <= v16 )
                strrchr(string: v13, chr: 0x2Fu);
              else
                strrchr(string: v13, chr: 0x5Cu);
              if ( v17 != 0 )
                v18 = (const char *)(v17 + 1);
              else
                v18 = (const char *)v13;
              if ( v12 != tmpValueBuf )
                *v12++ = 32;
              V_strncpy(pDest: v12, pSrc: v18, maxLen: (char *)&lstScripts - v12);
              v12 += strlen(v18);
              if ( v12 >= (char *)&lstScripts )
                break;
              v13 = (unsigned __int8 *)CStringListTokenizer::NextToken(this: &lstScripts);
            }
            while ( v13 != nullptr );
            Value = (char *)pValue;
          }
          v32 = -1;
          CStringListTokenizer::~CStringListTokenizer(this: &lstScripts);
          v2 = v29;
          break;
        default:
          break;
      }
LABEL_41:
      if ( Value == nullptr )
      {
LABEL_43:
        v26 = (char *)&var;
        v25 = i;
        goto LABEL_44;
      }
      v26 = Value;
      v25 = i;
LABEL_44:
      p_m_VarList = &v2->m_VarList;
      CListCtrl::SetItemText(this: &v2->m_VarList, nItem: v25, nSubItem: 1, lpszText: v26);
LABEL_45:
      v24 = v2->m_VarList.m_hWnd;
      v23 = ++i;
      if ( v23 >= SendMessageA(hWnd: v24, Msg: 0x1004u, wParam: 0, lParam: 0) )
        return;
    }
    v11 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v2->m_kv, pszKey: ItemData, piIndex: nullptr);
LABEL_40:
    pValue = v11;
    Value = (char *)v11;
    goto LABEL_41;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAB30
// Name: protected: void COP_Entity::CreateSmartControls_Angle(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls_Angle(
        COP_Entity *this,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont,
        bool *bShowSmartAngles)
{
  const char *Value; // eax
  int v7; // eax
  CAngleBox *p_m_SmartAngle; // ecx
  int top; // ecx
  int bottom; // edi
  int v11; // eax
  int v12; // eax
  CWnd *v13; // eax
  char *v14; // ecx
  HWND__ *v15; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWnd **m_pMemory; // ecx
  int v21; // eax
  CWnd **v22; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-40h]
  HWND__ *v24; // [esp-8h] [ebp-40h]
  HWND__ *v25; // [esp-8h] [ebp-40h]
  HWND__ *v26; // [esp-8h] [ebp-40h]
  CRect rectAngleBox; // [esp+Ch] [ebp-2Ch] BYREF
  CRect rectAngleEdit; // [esp+1Ch] [ebp-1Ch] BYREF
  int v29; // [esp+34h] [ebp-4h]
  char *pszValue; // [esp+40h] [ebp+8h]
  const char *pszValuea; // [esp+40h] [ebp+8h]
  char *pszValueb; // [esp+40h] [ebp+8h]
  bool *bShowSmartAnglesa; // [esp+4Ch] [ebp+14h]

  pszValue = pVar->m_szName;
  if ( _V_stricmp(s1: pszValue, s2: "angles") != 0 )
  {
    *bShowSmartAngles = true;
    m_hWnd = this->m_SmartAngle.m_hWnd;
    memset(&rectAngleBox, 0, sizeof(rectAngleBox));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectAngleBox);
    v24 = this->m_SmartAngleEdit.m_hWnd;
    memset(&rectAngleEdit, 0, sizeof(rectAngleEdit));
    GetWindowRect(hWnd: v24, lpRect: &rectAngleEdit);
    CWnd::SetWindowPos(
      this: &this->m_SmartAngle,
      pWndInsertAfter: nullptr,
      x: ctrlrect->left - rectAngleEdit.left + rectAngleEdit.right + 4,
      y: ctrlrect->bottom + 10,
      cx: 0,
      cy: 0,
      nFlags: 5u);
    CWnd::SetWindowPos(
      this: &this->m_SmartAngleEdit,
      pWndInsertAfter: nullptr,
      x: ctrlrect->left,
      y: rectAngleBox.bottom + rectAngleEdit.top - rectAngleEdit.bottom - rectAngleBox.top + ctrlrect->bottom + 10,
      cx: 0,
      cy: 0,
      nFlags: 5u);
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pszValue, piIndex: nullptr);
    pszValuea = Value;
    if ( Value != nullptr )
    {
      v7 = _V_stricmp(s1: Value, s2: (const char *)CObjectPage::VALUE_DIFFERENT_STRING);
      p_m_SmartAngle = &this->m_SmartAngle;
      if ( v7 != 0 )
      {
        CAngleBox::SetDifferent(this: p_m_SmartAngle, bDifferent: false, bRedraw: true);
        CAngleBox::SetAngles(this: &this->m_SmartAngle, szAngles: pszValuea, bRedraw: true);
      }
      else
      {
        CAngleBox::SetDifferent(this: p_m_SmartAngle, bDifferent: true, bRedraw: true);
      }
    }
  }
  if ( bShowSmartAngles != nullptr )
  {
    v25 = this->m_SmartAngle.m_hWnd;
    memset(&rectAngleBox, 0, sizeof(rectAngleBox));
    GetWindowRect(hWnd: v25, lpRect: &rectAngleBox);
    CWnd::ScreenToClient(this, lpRect: &rectAngleBox);
    v26 = this->m_SmartAngleEdit.m_hWnd;
    memset(&rectAngleEdit, 0, sizeof(rectAngleEdit));
    GetWindowRect(hWnd: v26, lpRect: &rectAngleEdit);
    CWnd::ScreenToClient(this, lpRect: &rectAngleEdit);
    top = rectAngleEdit.top;
    bottom = rectAngleEdit.bottom;
    rectAngleBox.left = rectAngleBox.right + 8;
  }
  else
  {
    v11 = ctrlrect->bottom;
    top = v11 + 4;
    v12 = v11 - ctrlrect->top;
    rectAngleBox.left = ctrlrect->left;
    bottom = top + v12;
  }
  rectAngleBox.top = top;
  v13 = (CWnd *)operator new(nSize: 0x74u);
  pszValueb = (char *)v13;
  v29 = 0;
  if ( v13 != nullptr )
  {
    CWnd::CWnd(this: v13);
    v14 = pszValueb;
    *(_DWORD *)pszValueb = &CButton::`vftable';
    LOBYTE(v29) = 0;
    bShowSmartAnglesa = (bool *)pszValueb;
  }
  else
  {
    bShowSmartAnglesa = nullptr;
    v14 = nullptr;
  }
  v29 = -1;
  if ( this != nullptr )
    v15 = this->m_hWnd;
  else
    v15 = nullptr;
  (*(void (__thiscall **)(char *, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD))(*(_DWORD *)v14 + 92))(
    a1: v14,
    a2: 0,
    a3: "Button",
    a4: "Point At...",
    a5: 1342246915,
    a6: rectAngleBox.left,
    a7: rectAngleBox.top,
    a8: 58,
    a9: bottom - rectAngleBox.top + 2,
    a10: v15,
    a11: 1535,
    a12: 0);
  SendMessageA(hWnd: *((HWND *)bShowSmartAnglesa + 8), Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  AfxGetModuleState();
  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x143);
  SendMessageA(hWnd: *((HWND *)bShowSmartAnglesa + 8), Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)IconW);
  m_Size = this->m_SmartControls.m_Size;
  m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SmartControls.m_Size;
  m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
  v21 = this->m_SmartControls.m_Size - m_Size - 1;
  this->m_SmartControls.m_pElements = m_pMemory;
  if ( v21 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v21);
  v22 = &this->m_SmartControls.m_Memory.m_pMemory[m_Size];
  if ( v22 != nullptr )
    *v22 = (CWnd *)bShowSmartAnglesa;
}

//------------------------------------------------------------------------------
// Address: 0x100DAE00
// Name: protected: void COP_Entity::CreateSmartControls_Choices(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls_Choices(
        COP_Entity *this,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  CWnd *v5; // eax
  CWnd *v6; // edi
  GDIV_TYPE m_eType; // eax
  int v8; // esi
  int v9; // ebx
  CMapWorld *m_pWorld; // esi
  int v11; // edx
  CMapEntity *m_pObject; // eax
  GDclass *m_pClass; // ecx
  const char *Value; // eax
  GameData *v15; // ecx
  int m_Size; // ebx
  int i; // esi
  GDclass *v18; // eax
  int v19; // ebx
  int j; // esi
  GDclass *v21; // eax
  const char *v22; // eax
  const char *v23; // esi
  const char *v24; // eax
  int v25; // ebx
  int m_nAllocationCount; // eax
  CWnd **m_pMemory; // ecx
  int v28; // eax
  CWnd **v29; // ebx
  int pos; // [esp+2Ch] [ebp+Ch]

  v5 = (CWnd *)operator new(nSize: 0x78u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    CWnd::CWnd(this: v5);
    v6->__vftable = (CWnd_vtbl *)&CComboBox::`vftable';
    v6->__vftable = (CWnd_vtbl *)&CMyComboBox::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  v6[1].__vftable = (CWnd_vtbl *)this;
  ctrlrect->bottom += 150;
  ((void (__thiscall *)(CWnd *, int, CRect *, COP_Entity *, int))v6->__vftable[1].GetRuntimeClass)(
    a1: v6,
    a2: (pVar->m_eType != ivChoices ? 0x100 : 0) | 0x40A10242,
    a3: ctrlrect,
    a4: this,
    a5: 1);
  SendMessageA(hWnd: v6->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  SendMessageA(hWnd: v6->m_hWnd, Msg: 0x160u, wParam: 0x96u, lParam: 0);
  if ( this->m_bMultiEdit )
    SendMessageA(hWnd: v6->m_hWnd, Msg: 0x143u, wParam: 0, lParam: CObjectPage::VALUE_DIFFERENT_STRING);
  m_eType = pVar->m_eType;
  if ( m_eType == ivChoices )
  {
    v8 = 0;
    if ( pVar->m_Items.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        SendMessageA(
          hWnd: v6->m_hWnd,
          Msg: 0x143u,
          wParam: 0,
          lParam: (LPARAM)pVar->m_Items.m_Memory.m_pMemory[v9].szCaption);
        ++v8;
        ++v9;
      }
      while ( v8 < pVar->m_Items.m_Size );
    }
  }
  else if ( m_eType == ivFilterClass )
  {
    m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
    v11 = 0;
    for ( pos = 0; v11 < m_pWorld->m_EntityList.m_Size; pos = v11 )
    {
      m_pObject = m_pWorld->m_EntityList.m_Memory.m_pMemory[v11 >> (*((int *)&m_pWorld->m_EntityList.m_Memory + 2) >> 27)][pos & ((32 * *((_DWORD *)&m_pWorld->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
        m_pClass = m_pObject->m_pClass;
      else
        m_pClass = nullptr;
      if ( m_pClass != nullptr && m_pClass->m_bFilter )
      {
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: &m_pObject->m_KeyValues,
                  pszKey: "targetname",
                  piIndex: nullptr);
        if ( Value != nullptr )
          SendMessageA(hWnd: v6->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Value);
      }
      v11 = pos + 1;
    }
  }
  else
  {
    v15 = pGD;
    if ( m_eType == ivNPCClass )
    {
      if ( pGD != nullptr )
      {
        m_Size = pGD->m_Classes.m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          if ( i < v15->m_Classes.m_Size )
            v18 = v15->m_Classes.m_Memory.m_pMemory[i];
          else
            v18 = nullptr;
          if ( v18->m_bNPC )
          {
            SendMessageA(hWnd: v6->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v18->m_szName);
            v15 = pGD;
          }
        }
      }
    }
    else if ( pGD != nullptr )
    {
      v19 = pGD->m_Classes.m_Size;
      for ( j = 0; j < v19; ++j )
      {
        if ( j < v15->m_Classes.m_Size )
          v21 = v15->m_Classes.m_Memory.m_pMemory[j];
        else
          v21 = nullptr;
        if ( v21->m_bPoint )
        {
          SendMessageA(hWnd: v6->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v21->m_szName);
          v15 = pGD;
        }
      }
    }
  }
  v22 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
  v23 = v22;
  if ( v22 != nullptr )
  {
    if ( strcmp(v22, (const char *)CObjectPage::VALUE_DIFFERENT_STRING) == 0 )
    {
      SendMessageA(hWnd: v6->m_hWnd, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: CObjectPage::VALUE_DIFFERENT_STRING);
    }
    else if ( pVar->m_eType == ivChoices
           && (v24 = GDinputvariable::ItemStringForValue(this: pVar, szValue: v23)) != nullptr )
    {
      SendMessageA(hWnd: v6->m_hWnd, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)v24);
    }
    else
    {
      CWnd::SetWindowTextA(this: v6, lpszString: v23);
    }
  }
  this->m_pSmartControl = v6;
  v25 = this->m_SmartControls.m_Size;
  m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( v25 + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: v25 - m_nAllocationCount + 1);
  ++this->m_SmartControls.m_Size;
  m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
  v28 = this->m_SmartControls.m_Size - v25 - 1;
  this->m_SmartControls.m_pElements = m_pMemory;
  if ( v28 > 0 )
    _V_memmove(dest: &m_pMemory[v25 + 1], src: &m_pMemory[v25], count: 4 * v28);
  v29 = &this->m_SmartControls.m_Memory.m_pMemory[v25];
  if ( v29 != nullptr )
    *v29 = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100DB190
// Name: protected: void COP_Entity::CreateSmartControls_TargetName(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls_TargetName(
        COP_Entity *this,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  __int64 v4; // xmm0_8
  __int64 v5; // xmm1_8
  CTargetNameComboBox *v7; // esi
  const char *Value; // eax
  tagRECT v9; // [esp-24h] [ebp-34h]
  CRect ComboRect; // [esp+0h] [ebp-10h]

  v4 = *(_QWORD *)&ctrlrect->left;
  v5 = *(_QWORD *)&ctrlrect->right;
  ComboRect.right = ctrlrect->right;
  ComboRect.bottom = HIDWORD(v5) + 150;
  *(_QWORD *)&v9.left = v4;
  *(_QWORD *)&v9.right = *(_QWORD *)&ComboRect.right;
  v7 = CTargetNameComboBox::Create(
         pCallbacks: &this->m_SmartControlTargetNameRouter,
         dwStyle: 0x40A10142u,
         rect: v9,
         pParentWnd: this,
         nID: 2u);
  SendMessageA(hWnd: v7->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  SendMessageA(hWnd: v7->m_hWnd, Msg: 0x160u, wParam: 0x96u, lParam: 0);
  this->m_pSmartControl = v7;
  CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
    this: (CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *)&this->m_SmartControls,
    elem: this->m_SmartControls.m_Size,
    src: (CVisGroup *const *)&this->m_pSmartControl);
  CTargetNameComboBox::SetEntityList(this: v7, pEntityList: &CMapDoc::m_pMapDoc->m_pWorld->m_EntityList);
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
  CFilteredComboBox::SelectItem(this: v7, pStr: Value);
  if ( pVar->m_bReadOnly )
    CFilteredComboBox::EnableWindow(this: v7, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x100DB270
// Name: protected: void COP_Entity::CreateSmartControls_BasicEditControl(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls_BasicEditControl(
        COP_Entity *this,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *pHelperType)
{
  CWnd *v6; // eax
  CWnd *v7; // ebx
  CRect *v8; // edi
  HWND__ *m_hWnd; // edx
  const char *Value; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *v11; // ecx
  int v12; // eax
  int bottom; // eax
  int v14; // esi
  int v15; // edi
  CWnd *v16; // eax
  CWnd *v17; // ebx
  HWND__ *SafeHwnd; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWnd **m_pMemory; // ecx
  int v24; // eax
  CWnd **v25; // edi
  int v26; // edi
  int v27; // eax
  CWnd **v28; // ecx
  int v29; // eax
  CWnd **v30; // edi
  __int64 ButtonRect; // [esp+Ch] [ebp-28h]
  int ButtonRect_8; // [esp+14h] [ebp-20h]
  CWnd_vtbl *pData; // [esp+1Ch] [ebp-18h]
  CWnd *v34; // [esp+20h] [ebp-14h]
  int i; // [esp+3Ch] [ebp+8h]

  v6 = (CWnd *)operator new(nSize: 0x78u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    CWnd::CWnd(this: v6);
    v7->__vftable = (CWnd_vtbl *)&CEdit::`vftable';
    v7->__vftable = (CWnd_vtbl *)&CMyEdit::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  v34 = v7;
  v8 = ctrlrect;
  v7[1].__vftable = (CWnd_vtbl *)this;
  ctrlrect->bottom += 2;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  v7->CreateEx_2(
    this: v7,
    a2: 512u,
    a3: "EDIT",
    a4: &var,
    a5: 1082196096u,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: ctrlrect->right - ctrlrect->left,
    a9: ctrlrect->bottom - ctrlrect->top,
    a10: m_hWnd,
    a11: (HMENU__ *)1,
    a12: nullptr);
  SendMessageA(hWnd: v7->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
  if ( Value != nullptr )
    CWnd::SetWindowTextA(this: v7, lpszString: Value);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: v7, bEnable: 0);
  v11 = pHelperType;
  v12 = 0;
  for ( i = 0; v12 < pHelperType->m_Size; i = v12 )
  {
    if ( _V_strcmp(s1: v11->m_Memory.m_pMemory[v12], s2: "sphere") == 0 )
    {
      bottom = v8->bottom;
      ButtonRect = *(_QWORD *)&v8->left;
      HIDWORD(ButtonRect) = bottom + 4;
      v14 = 2 * bottom + 4 - v8->top;
      ButtonRect_8 = v8->left + 32;
      v15 = 0;
      if ( CMapDoc::GetFirst3DView(this: CMapDoc::m_pMapDoc) == nullptr )
        v15 = 0x8000000;
      v16 = (CWnd *)operator new(nSize: 0x74u);
      v17 = v16;
      if ( v16 != nullptr )
      {
        CWnd::CWnd(this: v16);
        v17->__vftable = (CWnd_vtbl *)&CButton::`vftable';
      }
      else
      {
        v17 = nullptr;
      }
      pData = v17->__vftable;
      SafeHwnd = CWnd::GetSafeHwnd(this);
      pData->CreateEx_2(
        this: v17,
        a2: 0,
        a3: "Button",
        a4: &var,
        a5: v15 | 0x50011040,
        a6: ButtonRect,
        a7: HIDWORD(ButtonRect),
        a8: ButtonRect_8 - ButtonRect,
        a9: v14 - HIDWORD(ButtonRect),
        a10: SafeHwnd,
        a11: (HMENU__ *)1215,
        a12: nullptr);
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x14E);
      SendMessageA(hWnd: v17->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)IconW);
      m_Size = this->m_SmartControls.m_Size;
      m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_SmartControls.m_Size;
      m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
      v24 = this->m_SmartControls.m_Size - m_Size - 1;
      this->m_SmartControls.m_pElements = m_pMemory;
      if ( v24 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v24);
      v25 = &this->m_SmartControls.m_Memory.m_pMemory[m_Size];
      if ( v25 != nullptr )
        *v25 = v17;
      v8 = ctrlrect;
      v7 = v34;
    }
    v11 = pHelperType;
    v12 = i + 1;
  }
  this->m_pSmartControl = v7;
  v26 = this->m_SmartControls.m_Size;
  v27 = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( v26 + 1 > v27 )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: v26 - v27 + 1);
  ++this->m_SmartControls.m_Size;
  v28 = this->m_SmartControls.m_Memory.m_pMemory;
  v29 = this->m_SmartControls.m_Size - v26 - 1;
  this->m_SmartControls.m_pElements = v28;
  if ( v29 > 0 )
    _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 4 * v29);
  v30 = &this->m_SmartControls.m_Memory.m_pMemory[v26];
  if ( v30 != nullptr )
    *v30 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100DB5A0
// Name: protected: void COP_Entity::CreateSmartControls_BrowseAndPlayButtons(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls_BrowseAndPlayButtons(
        COP_Entity *this,
        GDinputvariable *pVar,
        HMENU__ *ctrlrect,
        HFONT__ *hControlFont)
{
  int v4; // ecx
  int v5; // esi
  int v6; // edi
  GDIV_TYPE m_eType; // eax
  CWnd *v8; // eax
  CButton *v9; // ebx
  HWND__ *m_hWnd; // eax
  HMENU__ *v11; // eax
  int m_nAllocationCount; // ecx
  CWnd **m_pMemory; // edx
  int v14; // ecx
  CWnd **v15; // eax
  GDIV_TYPE v16; // eax
  CWnd *v17; // eax
  HWND *v18; // ebx
  void *v19; // eax
  CWnd *v20; // eax
  HMENU__ *v21; // ecx
  void *v22; // eax
  int m_Size; // edi
  int v24; // eax
  CWnd **v25; // ecx
  int v26; // eax
  CWnd **v27; // edi
  int ButtonRect; // [esp+0h] [ebp-24h]
  int ButtonRect_4; // [esp+4h] [ebp-20h]
  int ButtonRect_8; // [esp+8h] [ebp-1Ch]
  GDinputvariable *pVara; // [esp+2Ch] [ebp+8h]
  int message; // [esp+30h] [ebp+Ch]
  HMENU__ *messagea; // [esp+30h] [ebp+Ch]
  HMENU__ *messageb; // [esp+30h] [ebp+Ch]

  v4 = *((_DWORD *)ctrlrect + 3);
  ButtonRect = *(_DWORD *)ctrlrect;
  v5 = 2 * v4 + 4 - *((_DWORD *)ctrlrect + 1);
  v6 = v4 + 4;
  ButtonRect_8 = *(_DWORD *)ctrlrect + 54;
  m_eType = pVar->m_eType;
  ButtonRect_4 = v4 + 4;
  message = 1010;
  if ( m_eType == ivInstanceFile )
    message = 1686;
  if ( m_eType != ivScriptList )
  {
    v8 = (CWnd *)operator new(nSize: 0x74u);
    v9 = (CButton *)v8;
    if ( v8 != nullptr )
    {
      CWnd::CWnd(this: v8);
      v9->__vftable = (CButton_vtbl *)&CButton::`vftable';
    }
    else
    {
      v9 = nullptr;
    }
    m_hWnd = (HWND__ *)this;
    if ( this != nullptr )
      m_hWnd = this->m_hWnd;
    v9->CreateEx_2(
      this: v9,
      a2: 0,
      a3: "Button",
      a4: "Browse...",
      a5: 1342242816u,
      a6: ButtonRect,
      a7: v6,
      a8: ButtonRect_8 - ButtonRect,
      a9: v5 - v6,
      a10: m_hWnd,
      a11: (HMENU__ *)message,
      a12: nullptr);
    SendMessageA(hWnd: v9->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
    this->m_pSmartBrowseButton = v9;
    m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
    messagea = (HMENU__ *)this->m_SmartControls.m_Size;
    v11 = messagea;
    if ( (int)messagea + 1 > m_nAllocationCount )
    {
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
        num: (int)messagea - m_nAllocationCount + 1);
      v11 = messagea;
    }
    ++this->m_SmartControls.m_Size;
    m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
    v14 = this->m_SmartControls.m_Size - (_DWORD)v11 - 1;
    this->m_SmartControls.m_pElements = m_pMemory;
    if ( v14 > 0 )
    {
      _V_memmove(dest: &m_pMemory[(_DWORD)v11 + 1], src: &m_pMemory[(_DWORD)v11], count: 4 * v14);
      v11 = messagea;
    }
    v6 = ButtonRect_4;
    v15 = &this->m_SmartControls.m_Memory.m_pMemory[(_DWORD)v11];
    if ( v15 != nullptr )
      *v15 = v9;
  }
  v16 = pVar->m_eType;
  if ( v16 == ivSound || v16 == ivScene )
  {
    v20 = (CWnd *)operator new(nSize: 0x74u);
    messageb = (HMENU__ *)v20;
    if ( v20 != nullptr )
    {
      CWnd::CWnd(this: v20);
      v21 = messageb;
      *(_DWORD *)messageb = &CButton::`vftable';
      pVara = (GDinputvariable *)messageb;
    }
    else
    {
      pVara = nullptr;
      v21 = nullptr;
    }
    v22 = this;
    if ( this != nullptr )
      v22 = this->m_hWnd;
    (*(void (__thiscall **)(HMENU__ *, _DWORD, const char *, const char *, int, int, int, int, int, void *, int, _DWORD))(*(_DWORD *)v21 + 92))(
      a1: v21,
      a2: 0,
      a3: "Button",
      a4: "Play",
      a5: 1342242816,
      a6: ButtonRect_8 + 8,
      a7: v6,
      a8: 54,
      a9: v5 - v6,
      a10: v22,
      a11: 1121,
      a12: 0);
    v18 = (HWND *)pVara;
  }
  else
  {
    if ( v16 != ivScriptList )
      return;
    v17 = (CWnd *)operator new(nSize: 0x74u);
    v18 = (HWND *)v17;
    if ( v17 != nullptr )
    {
      CWnd::CWnd(this: v17);
      *v18 = (HWND)&CButton::`vftable';
    }
    else
    {
      v18 = nullptr;
    }
    v19 = this;
    if ( this != nullptr )
      v19 = this->m_hWnd;
    (*((void (__thiscall **)(HWND *, _DWORD, const char *, const char *, int, int, int, int, int, void *, int, _DWORD))*v18
     + 23))(
      a1: v18,
      a2: 0,
      a3: "Button",
      a4: "Manage...",
      a5: 1342242816,
      a6: ButtonRect,
      a7: v6,
      a8: ButtonRect_8 - ButtonRect,
      a9: v5 - v6,
      a10: v19,
      a11: 1121,
      a12: 0);
  }
  SendMessageA(hWnd: v18[8], Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  m_Size = this->m_SmartControls.m_Size;
  v24 = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > v24 )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: m_Size - v24 + 1);
  ++this->m_SmartControls.m_Size;
  v25 = this->m_SmartControls.m_Memory.m_pMemory;
  v26 = this->m_SmartControls.m_Size - m_Size - 1;
  this->m_SmartControls.m_pElements = v25;
  if ( v26 > 0 )
    _V_memmove(dest: &v25[m_Size + 1], src: &v25[m_Size], count: 4 * v26);
  v27 = &this->m_SmartControls.m_Memory.m_pMemory[m_Size];
  if ( v27 != nullptr )
    *v27 = (CWnd *)v18;
}

//------------------------------------------------------------------------------
// Address: 0x100DB8D0
// Name: protected: void COP_Entity::CreateSmartControls_MarkAndEyedropperButtons(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COP_Entity::CreateSmartControls_MarkAndEyedropperButtons(
        COP_Entity *this@<ecx>,
        int a2@<ebx>,
        HWND__ *a3@<edi>,
        int a4@<esi>,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  int bottom; // ecx
  int v8; // edi
  GDIV_TYPE m_eType; // eax
  int v10; // ebx
  CWnd *v11; // esi
  void *m_hWnd; // eax
  int v13; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CWnd **m_pMemory; // ecx
  int v17; // eax
  CWnd **v18; // ebx
  CWnd *v19; // eax
  HWND *v20; // ebx
  int v21; // eax
  int v22; // edi
  CWnd **v23; // ecx
  int v24; // eax
  CWnd **v25; // edi
  CWnd *v26; // eax
  CRect *v27; // ecx
  void *v28; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // eax
  int v31; // edi
  int v32; // eax
  CWnd **v33; // ecx
  int v34; // eax
  CWnd **v35; // edi
  int ButtonRect; // [esp+0h] [ebp-20h]
  int ButtonRecta; // [esp+0h] [ebp-20h]
  int ButtonRect_4; // [esp+4h] [ebp-1Ch]
  int ButtonRect_8; // [esp+8h] [ebp-18h]
  int ButtonRect_12; // [esp+Ch] [ebp-14h]
  CRect *ctrlrecta; // [esp+2Ch] [ebp+Ch]
  CRect *ctrlrectb; // [esp+2Ch] [ebp+Ch]
  HFONT__ *hControlFonta; // [esp+30h] [ebp+10h]

  bottom = ctrlrect->bottom;
  ButtonRect = ctrlrect->left;
  v8 = 2 * bottom + 4 - ctrlrect->top;
  m_eType = pVar->m_eType;
  v10 = bottom + 4;
  ButtonRect_4 = bottom + 4;
  ButtonRect_12 = v8;
  if ( m_eType == ivTargetDest || m_eType == ivTargetNameOrClass || m_eType == ivTargetSrc )
  {
    v11 = (CWnd *)operator new(nSize: 0x74u);
    if ( v11 != nullptr )
    {
      CWnd::CWnd(this: v11);
      v11->__vftable = (CWnd_vtbl *)&CButton::`vftable';
      ctrlrecta = (CRect *)v11;
    }
    else
    {
      ctrlrecta = nullptr;
      v11 = nullptr;
    }
    m_hWnd = this;
    if ( this != nullptr )
      m_hWnd = this->m_hWnd;
    v13 = v8 - v10;
    ((void (__thiscall *)(CWnd *, _DWORD, const char *, const char *, int, int, int, int, int, void *, int, _DWORD, HWND__ *, int, int))v11->CreateEx_2)(
      a1: v11,
      a2: 0,
      a3: "Button",
      a4: "Mark",
      a5: 1342242816,
      a6: ButtonRect,
      a7: v10,
      a8: 48,
      a9: v13,
      a10: m_hWnd,
      a11: 1303,
      a12: 0,
      a13: a3,
      a14: a4,
      a15: a2);
    SendMessageA(hWnd: v11->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
    m_Size = this->m_SmartControls.m_Size;
    m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
    ButtonRect_8 = ButtonRect + 48;
    ButtonRecta = ButtonRect + 52;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_SmartControls.m_Size;
    m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
    v17 = this->m_SmartControls.m_Size - m_Size - 1;
    this->m_SmartControls.m_pElements = m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
    v18 = &this->m_SmartControls.m_Memory.m_pMemory[m_Size];
    if ( v18 != nullptr )
      *v18 = (CWnd *)ctrlrecta;
    v19 = (CWnd *)operator new(nSize: 0x74u);
    v20 = (HWND *)v19;
    if ( v19 != nullptr )
    {
      CWnd::CWnd(this: v19);
      *v20 = (HWND)&CButton::`vftable';
    }
    else
    {
      v20 = nullptr;
    }
    a2 = 0;
    a4 = 1302;
    a3 = this->m_hWnd;
    (*((void (__thiscall **)(HWND *, _DWORD, const char *, const char *, int, int, int, int, int))*v20 + 23))(
      a1: v20,
      a2: 0,
      a3: "Button",
      a4: "Mark+Add",
      a5: 1342242816,
      a6: ButtonRecta,
      a7: ButtonRect_4,
      a8: 64,
      a9: v13);
    SendMessageA(hWnd: v20[8], Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
    v21 = this->m_SmartControls.m_Memory.m_nAllocationCount;
    ButtonRect = ButtonRect_8 + 72;
    v22 = this->m_SmartControls.m_Size;
    if ( v22 + 1 > v21 )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
        num: v22 - v21 + 1);
    ++this->m_SmartControls.m_Size;
    v23 = this->m_SmartControls.m_Memory.m_pMemory;
    v24 = this->m_SmartControls.m_Size - v22 - 1;
    this->m_SmartControls.m_pElements = v23;
    if ( v24 > 0 )
      _V_memmove(dest: &v23[v22 + 1], src: &v23[v22], count: 4 * v24);
    v25 = &this->m_SmartControls.m_Memory.m_pMemory[v22];
    if ( v25 != nullptr )
      *v25 = (CWnd *)v20;
    v10 = ButtonRect_4;
    v8 = ButtonRect_12;
  }
  v26 = (CWnd *)operator new(nSize: 0x74u);
  ctrlrectb = (CRect *)v26;
  if ( v26 != nullptr )
  {
    CWnd::CWnd(this: v26);
    v27 = ctrlrectb;
    ctrlrectb->left = (int)&CButton::`vftable';
    hControlFonta = (HFONT__ *)ctrlrectb;
  }
  else
  {
    hControlFonta = nullptr;
    v27 = nullptr;
  }
  v28 = this;
  if ( this != nullptr )
    v28 = this->m_hWnd;
  (*(void (__thiscall **)(CRect *, _DWORD, const char *, const char *, int, int, int, int, int, void *, int, _DWORD, HWND__ *, int, int))(v27->left + 92))(
    a1: v27,
    a2: 0,
    a3: "Button",
    a4: &var,
    a5: 1342246979,
    a6: ButtonRect,
    a7: v10,
    a8: 32,
    a9: v8 - v10,
    a10: v28,
    a11: 1534,
    a12: 0,
    a13: a3,
    a14: a4,
    a15: a2);
  AfxGetModuleState();
  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x13D);
  SendMessageA(hWnd: *((HWND *)hControlFonta + 8), Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)IconW);
  v31 = this->m_SmartControls.m_Size;
  v32 = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( v31 + 1 > v32 )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: v31 - v32 + 1);
  ++this->m_SmartControls.m_Size;
  v33 = this->m_SmartControls.m_Memory.m_pMemory;
  v34 = this->m_SmartControls.m_Size - v31 - 1;
  this->m_SmartControls.m_pElements = v33;
  if ( v34 > 0 )
    _V_memmove(dest: &v33[v31 + 1], src: &v33[v31], count: 4 * v34);
  v35 = &this->m_SmartControls.m_Memory.m_pMemory[v31];
  if ( v35 != nullptr )
    *v35 = (CWnd *)hControlFonta;
}

//------------------------------------------------------------------------------
// Address: 0x100DBC80
// Name: protected: void COP_Entity::CreateSmartControls_PickButton(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COP_Entity::CreateSmartControls_PickButton(
        COP_Entity *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  int bottom; // ecx
  int v8; // esi
  int v9; // edi
  CWnd *v10; // eax
  HWND *v11; // ebx
  void *m_hWnd; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWnd **m_pMemory; // ecx
  int v16; // eax
  CWnd **v17; // edi
  int ButtonRect; // [esp+0h] [ebp-20h]
  int ButtonRect_4; // [esp+4h] [ebp-1Ch]

  bottom = ctrlrect->bottom;
  ButtonRect = ctrlrect->left;
  v8 = 2 * bottom + 4 - ctrlrect->top;
  ButtonRect_4 = bottom + 4;
  v9 = ctrlrect->left + 54;
  v10 = (CWnd *)operator new(nSize: 0x74u);
  v11 = (HWND *)v10;
  if ( v10 != nullptr )
  {
    CWnd::CWnd(this: v10);
    *v11 = (HWND)&CButton::`vftable';
  }
  else
  {
    v11 = nullptr;
  }
  m_hWnd = this;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  (*((void (__thiscall **)(HWND *, _DWORD, const char *, const char *, int, int, int, int, int, void *, int, _DWORD, int, int, int))*v11
   + 23))(
    a1: v11,
    a2: 0,
    a3: "Button",
    a4: "Pick...",
    a5: 1342246915,
    a6: ButtonRect,
    a7: ButtonRect_4,
    a8: v9 - ButtonRect,
    a9: v8 - ButtonRect_4,
    a10: m_hWnd,
    a11: 1533,
    a12: 0,
    a13: a3,
    a14: a4,
    a15: a2);
  SendMessageA(hWnd: v11[8], Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  m_Size = this->m_SmartControls.m_Size;
  m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SmartControls.m_Size;
  m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
  v16 = this->m_SmartControls.m_Size - m_Size - 1;
  this->m_SmartControls.m_pElements = m_pMemory;
  if ( v16 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
  v17 = &this->m_SmartControls.m_Memory.m_pMemory[m_Size];
  if ( v17 != nullptr )
    *v17 = (CWnd *)v11;
}

//------------------------------------------------------------------------------
// Address: 0x100DBDD0
// Name: protected: void COP_Entity::CreateSmartControls_InstanceVariable(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COP_Entity::CreateSmartControls_InstanceVariable(
        COP_Entity *this@<ecx>,
        int a2@<ebx>,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  char *Value; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // eax
  CWnd *v10; // eax
  HWND *v11; // ebx
  HWND__ *m_hWnd; // eax
  CWnd *v14; // eax
  CEdit *v15; // eax
  char *v16; // eax
  const char *v17; // ecx
  CWnd *v18; // eax
  char *v19; // edx
  CEdit *m_pEditInstanceVariable; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_SmartControls; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CCullTreeNode **m_pMemory; // ecx
  int v25; // eax
  HFONT__ **v26; // ebx
  CEdit *m_pEditInstanceValue; // ebx
  int v28; // edi
  int v29; // eax
  CCullTreeNode **v30; // ecx
  int v31; // eax
  CEdit **v32; // edi
  CCullTreeNode **v33; // edi
  int v34; // eax
  CCullTreeNode **v35; // ecx
  int v36; // eax
  CCullTreeNode **v37; // eax
  CCullTreeNode **v38; // edi
  int v39; // eax
  CCullTreeNode **v40; // ecx
  int v41; // eax
  CRect **v42; // eax
  HWND__ *v43; // [esp-Ch] [ebp-80h]
  char ValueData[80]; // [esp+8h] [ebp-6Ch] BYREF
  void *pData; // [esp+58h] [ebp-1Ch]
  const char *pReplace; // [esp+5Ch] [ebp-18h]
  const char *pVariable; // [esp+60h] [ebp-14h]
  HWND *v49; // [esp+64h] [ebp-10h]
  int v50; // [esp+70h] [ebp-4h]
  CRect *ctrlrecta; // [esp+80h] [ebp+Ch]
  CRect *ctrlrectb; // [esp+80h] [ebp+Ch]
  HFONT__ *hControlFonta; // [esp+84h] [ebp+10h]

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
  pReplace = &var;
  pVariable = &var;
  if ( Value != nullptr )
  {
    v7 = (char *)(ValueData - Value);
    do
    {
      v8 = *Value;
      Value[(_DWORD)v7] = *Value;
      ++Value;
    }
    while ( v8 != 0 );
    pVariable = ValueData;
    strchr(string: (unsigned __int8 *)ValueData, chr: 0x20u);
    if ( v9 != 0 )
    {
      *(_BYTE *)v9 = 0;
      pReplace = (const char *)(v9 + 1);
    }
  }
  v10 = (CWnd *)operator new(nSize: 0x74u);
  v11 = (HWND *)v10;
  pData = v10;
  v50 = 0;
  if ( v10 != nullptr )
  {
    CWnd::CWnd(this: v10);
    *v11 = (HWND)&CStatic::`vftable';
    LOBYTE(v50) = 0;
    v49 = v11;
  }
  else
  {
    v49 = nullptr;
    v11 = nullptr;
  }
  v50 = -1;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  (*((void (__thiscall **)(HWND *, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD, int))*v11
   + 23))(
    a1: v11,
    a2: 0,
    a3: "STATIC",
    a4: "Variable:",
    a5: 1342177280,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: 50,
    a9: 24,
    a10: m_hWnd,
    a11: -1,
    a12: 0,
    a13: a2);
  SendMessageA(hWnd: v11[8], Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  v14 = (CWnd *)operator new(nSize: 0x74u);
  ctrlrecta = (CRect *)v14;
  v50 = 2;
  if ( v14 != nullptr )
  {
    CWnd::CWnd(this: v14);
    v15 = (CEdit *)ctrlrecta;
    ctrlrecta->left = (int)&CEdit::`vftable';
    LOBYTE(v50) = 2;
  }
  else
  {
    v15 = nullptr;
  }
  v50 = -1;
  this->m_pEditInstanceVariable = v15;
  ctrlrect->bottom += 2;
  this->m_pEditInstanceVariable->CreateEx_2(
    this: this->m_pEditInstanceVariable,
    a2: 512u,
    a3: "EDIT",
    a4: &var,
    a5: 1350631552u,
    a6: ctrlrect->left + 50,
    a7: ctrlrect->top,
    a8: ctrlrect->right - ctrlrect->left - 50,
    a9: 24,
    a10: this->m_hWnd,
    a11: (HMENU__ *)3,
    a12: nullptr);
  SendMessageA(hWnd: this->m_pEditInstanceVariable->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  CWnd::SetWindowTextA(this: this->m_pEditInstanceVariable, lpszString: pVariable);
  SendMessageA(hWnd: this->m_pEditInstanceVariable->m_hWnd, Msg: 0xC5u, wParam: 0x32u, lParam: 0);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: this->m_pEditInstanceVariable, bEnable: 0);
  ctrlrect->top += 26;
  ctrlrect->bottom += 26;
  v16 = (char *)operator new(nSize: 0x74u);
  pVariable = v16;
  v50 = 4;
  if ( v16 != nullptr )
  {
    CWnd::CWnd(this: (CWnd *)v16);
    v17 = pVariable;
    *(_DWORD *)pVariable = &CStatic::`vftable';
    LOBYTE(v50) = 4;
    ctrlrectb = (CRect *)v17;
  }
  else
  {
    ctrlrectb = nullptr;
    v17 = nullptr;
  }
  v50 = -1;
  (*(void (__thiscall **)(const char *, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD))(*(_DWORD *)v17 + 92))(
    a1: v17,
    a2: 0,
    a3: "STATIC",
    a4: "Value:",
    a5: 1342177280,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: 50,
    a9: 24,
    a10: this->m_hWnd,
    a11: -1,
    a12: 0);
  SendMessageA(hWnd: (HWND)ctrlrectb[2].left, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  v18 = (CWnd *)operator new(nSize: 0x74u);
  pData = v18;
  v50 = 6;
  if ( v18 != nullptr )
  {
    CWnd::CWnd(this: v18);
    v19 = (char *)pData;
    *(_DWORD *)pData = &CEdit::`vftable';
    LOBYTE(v50) = 6;
  }
  else
  {
    v19 = nullptr;
  }
  pVariable = v19;
  v50 = -1;
  v43 = this->m_hWnd;
  this->m_pEditInstanceValue = (CEdit *)v19;
  (*(void (__thiscall **)(const char *, int, const char *, const char *, int, int, int, int, int, HWND__ *, int))(*(_DWORD *)v19 + 92))(
    a1: pVariable,
    a2: 512,
    a3: "EDIT",
    a4: &var,
    a5: 1350631552,
    a6: ctrlrect->left + 50,
    a7: ctrlrect->top,
    a8: ctrlrect->right - ctrlrect->left - 50,
    a9: 24,
    a10: v43,
    a11: 4);
  SendMessageA(hWnd: this->m_pEditInstanceValue->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  CWnd::SetWindowTextA(this: this->m_pEditInstanceValue, lpszString: pReplace);
  SendMessageA(hWnd: this->m_pEditInstanceVariable->m_hWnd, Msg: 0xC5u, wParam: 0x1Cu, lParam: 0);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: this->m_pEditInstanceValue, bEnable: 0);
  m_pEditInstanceVariable = this->m_pEditInstanceVariable;
  p_m_SmartControls = (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls;
  this->m_pSmartControl = m_pEditInstanceVariable;
  m_Size = this->m_SmartControls.m_Size;
  hControlFonta = (HFONT__ *)m_pEditInstanceVariable;
  m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SmartControls.m_Size;
  m_pMemory = p_m_SmartControls->m_pMemory;
  v25 = this->m_SmartControls.m_Size - m_Size - 1;
  this->m_SmartControls.m_pElements = this->m_SmartControls.m_Memory.m_pMemory;
  if ( v25 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v25);
  v26 = (HFONT__ **)&p_m_SmartControls->m_pMemory[m_Size];
  if ( v26 != nullptr )
    *v26 = hControlFonta;
  m_pEditInstanceValue = this->m_pEditInstanceValue;
  v28 = this->m_SmartControls.m_Size;
  v29 = p_m_SmartControls->m_nAllocationCount;
  if ( v28 + 1 > v29 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: v28 - v29 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v30 = p_m_SmartControls->m_pMemory;
  v31 = (int)p_m_SmartControls[1].m_pMemory - v28 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v31 > 0 )
    _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
  v32 = (CEdit **)&p_m_SmartControls->m_pMemory[v28];
  if ( v32 != nullptr )
    *v32 = m_pEditInstanceValue;
  v33 = p_m_SmartControls[1].m_pMemory;
  v34 = p_m_SmartControls->m_nAllocationCount;
  if ( (int)v33 + 1 > v34 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: (int)v33 - v34 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v35 = p_m_SmartControls->m_pMemory;
  v36 = (char *)p_m_SmartControls[1].m_pMemory - (char *)v33 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v36 > 0 )
    _V_memmove(dest: &v35[(_DWORD)v33 + 1], src: &v35[(_DWORD)v33], count: 4 * v36);
  v37 = &p_m_SmartControls->m_pMemory[(_DWORD)v33];
  if ( v37 != nullptr )
    *v37 = (CCullTreeNode *)v49;
  v38 = p_m_SmartControls[1].m_pMemory;
  v39 = p_m_SmartControls->m_nAllocationCount;
  if ( (int)v38 + 1 > v39 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: (int)v38 - v39 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v40 = p_m_SmartControls->m_pMemory;
  v41 = (char *)p_m_SmartControls[1].m_pMemory - (char *)v38 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v41 > 0 )
    _V_memmove(dest: &v40[(_DWORD)v38 + 1], src: &v40[(_DWORD)v38], count: 4 * v41);
  v42 = (CRect **)&p_m_SmartControls->m_pMemory[(_DWORD)v38];
  if ( v42 != nullptr )
    *v42 = ctrlrectb;
}

//------------------------------------------------------------------------------
// Address: 0x100DC270
// Name: protected: void COP_Entity::CreateSmartControls_InstanceParm(class GDinputvariable __near *,class CRect __near &,struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COP_Entity::CreateSmartControls_InstanceParm(
        COP_Entity *this@<ecx>,
        int a2@<ebx>,
        GDinputvariable *pVar,
        CRect *ctrlrect,
        HFONT__ *hControlFont)
{
  char *Value; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // eax
  int v10; // eax
  CWnd *v11; // eax
  HWND *v12; // ebx
  HWND__ *m_hWnd; // eax
  CWnd *v15; // eax
  CEdit *v16; // eax
  CWnd *v17; // eax
  int v18; // ecx
  CWnd *v19; // eax
  CMyComboBox *v20; // eax
  const char *VarTypeName; // eax
  char *v22; // eax
  const char *v23; // ecx
  CWnd *v24; // eax
  char *v25; // edx
  CEdit *m_pEditInstanceVariable; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_SmartControls; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CCullTreeNode **m_pMemory; // ecx
  int v31; // eax
  HFONT__ **v32; // ebx
  int v33; // ebx
  int v34; // eax
  CCullTreeNode **v35; // ecx
  int v36; // eax
  HFONT__ **v37; // ebx
  CEdit *m_pEditInstanceDefault; // ebx
  int v39; // edi
  int v40; // eax
  CCullTreeNode **v41; // ecx
  int v42; // eax
  CEdit **v43; // edi
  CCullTreeNode **v44; // edi
  int v45; // eax
  CCullTreeNode **v46; // ecx
  int v47; // eax
  CCullTreeNode **v48; // eax
  CCullTreeNode **v49; // edi
  int v50; // eax
  CCullTreeNode **v51; // ecx
  int v52; // eax
  CRect **v53; // eax
  CCullTreeNode **v54; // edi
  int v55; // eax
  CCullTreeNode **v56; // ecx
  int v57; // eax
  int *v58; // eax
  HWND__ *v59; // [esp-Ch] [ebp-84h]
  char ValueData[80]; // [esp+8h] [ebp-70h] BYREF
  void *pData; // [esp+58h] [ebp-20h]
  const char *pDefault; // [esp+5Ch] [ebp-1Ch]
  const char *pType; // [esp+60h] [ebp-18h]
  HWND *v65; // [esp+64h] [ebp-14h]
  int i; // [esp+68h] [ebp-10h]
  int v67; // [esp+74h] [ebp-4h]
  CRect *ctrlrecta; // [esp+84h] [ebp+Ch]
  CRect *ctrlrectb; // [esp+84h] [ebp+Ch]
  HFONT__ *hControlFonta; // [esp+88h] [ebp+10h]
  HFONT__ *hControlFontb; // [esp+88h] [ebp+10h]

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
  pDefault = &var;
  pType = &var;
  i = (int)&var;
  if ( Value != nullptr )
  {
    v7 = (char *)(ValueData - Value);
    do
    {
      v8 = *Value;
      Value[(_DWORD)v7] = *Value;
      ++Value;
    }
    while ( v8 != 0 );
    i = (int)ValueData;
    strchr(string: (unsigned __int8 *)ValueData, chr: 0x20u);
    if ( v9 != 0 )
    {
      *(_BYTE *)v9 = 0;
      pType = (const char *)(v9 + 1);
      strchr(string: (unsigned __int8 *)(v9 + 1), chr: 0x20u);
      if ( v10 != 0 )
      {
        *(_BYTE *)v10 = 0;
        pDefault = (const char *)(v10 + 1);
      }
    }
  }
  v11 = (CWnd *)operator new(nSize: 0x74u);
  v12 = (HWND *)v11;
  pData = v11;
  v67 = 0;
  if ( v11 != nullptr )
  {
    CWnd::CWnd(this: v11);
    *v12 = (HWND)&CStatic::`vftable';
    LOBYTE(v67) = 0;
    v65 = v12;
  }
  else
  {
    v65 = nullptr;
    v12 = nullptr;
  }
  v67 = -1;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  (*((void (__thiscall **)(HWND *, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD, int))*v12
   + 23))(
    a1: v12,
    a2: 0,
    a3: "STATIC",
    a4: "Variable:",
    a5: 1342177280,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: 50,
    a9: 24,
    a10: m_hWnd,
    a11: -1,
    a12: 0,
    a13: a2);
  SendMessageA(hWnd: v12[8], Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  v15 = (CWnd *)operator new(nSize: 0x74u);
  ctrlrecta = (CRect *)v15;
  v67 = 2;
  if ( v15 != nullptr )
  {
    CWnd::CWnd(this: v15);
    v16 = (CEdit *)ctrlrecta;
    ctrlrecta->left = (int)&CEdit::`vftable';
    LOBYTE(v67) = 2;
  }
  else
  {
    v16 = nullptr;
  }
  v67 = -1;
  this->m_pEditInstanceVariable = v16;
  ctrlrect->bottom += 2;
  this->m_pEditInstanceVariable->CreateEx_2(
    this: this->m_pEditInstanceVariable,
    a2: 512u,
    a3: "EDIT",
    a4: &var,
    a5: 1350631552u,
    a6: ctrlrect->left + 50,
    a7: ctrlrect->top,
    a8: ctrlrect->right - ctrlrect->left - 50,
    a9: 24,
    a10: this->m_hWnd,
    a11: (HMENU__ *)5,
    a12: nullptr);
  SendMessageA(hWnd: this->m_pEditInstanceVariable->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  CWnd::SetWindowTextA(this: this->m_pEditInstanceVariable, lpszString: (const char *)i);
  SendMessageA(hWnd: this->m_pEditInstanceVariable->m_hWnd, Msg: 0xC5u, wParam: 0x32u, lParam: 0);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: this->m_pEditInstanceVariable, bEnable: 0);
  ctrlrect->top += 26;
  ctrlrect->bottom += 26;
  v17 = (CWnd *)operator new(nSize: 0x74u);
  i = (int)v17;
  v67 = 4;
  if ( v17 != nullptr )
  {
    CWnd::CWnd(this: v17);
    v18 = i;
    *(_DWORD *)i = &CStatic::`vftable';
    LOBYTE(v67) = 4;
    ctrlrectb = (CRect *)v18;
  }
  else
  {
    ctrlrectb = nullptr;
    v18 = 0;
  }
  v67 = -1;
  (*(void (__thiscall **)(int, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD))(*(_DWORD *)v18 + 92))(
    a1: v18,
    a2: 0,
    a3: "STATIC",
    a4: "Value:",
    a5: 1342177280,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: 50,
    a9: 24,
    a10: this->m_hWnd,
    a11: -1,
    a12: 0);
  SendMessageA(hWnd: (HWND)ctrlrectb[2].left, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  v19 = (CWnd *)operator new(nSize: 0x78u);
  i = (int)v19;
  v67 = 6;
  if ( v19 != nullptr )
  {
    CWnd::CWnd(this: v19);
    v20 = (CMyComboBox *)i;
    *(_DWORD *)i = &CComboBox::`vftable';
    v20->__vftable = (CMyComboBox_vtbl *)&CMyComboBox::`vftable';
    LOBYTE(v67) = 6;
  }
  else
  {
    v20 = nullptr;
  }
  v67 = -1;
  this->m_pComboInstanceParmType = v20;
  v20->m_pParent = this;
  ctrlrect->bottom += 150;
  ctrlrect->left += 50;
  this->m_pComboInstanceParmType->Create_2(
    this: this->m_pComboInstanceParmType,
    a2: 1352729411u,
    a3: ctrlrect,
    a4: this,
    a5: 5u);
  ctrlrect->left -= 50;
  SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x160u, wParam: 0x96u, lParam: 0);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: this->m_pComboInstanceParmType, bEnable: 0);
  for ( i = 0; i < 37; ++i )
  {
    VarTypeName = GDinputvariable::GetVarTypeName(eType: (GDIV_TYPE)i);
    SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)VarTypeName);
  }
  SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)pType);
  ctrlrect->top += 26;
  ctrlrect->bottom += 26;
  v22 = (char *)operator new(nSize: 0x74u);
  pType = v22;
  v67 = 9;
  if ( v22 != nullptr )
  {
    CWnd::CWnd(this: (CWnd *)v22);
    v23 = pType;
    *(_DWORD *)pType = &CStatic::`vftable';
    LOBYTE(v67) = 9;
    i = (int)v23;
  }
  else
  {
    i = 0;
    v23 = nullptr;
  }
  v67 = -1;
  (*(void (__thiscall **)(const char *, _DWORD, const char *, const char *, int, int, int, int, int, HWND__ *, int, _DWORD))(*(_DWORD *)v23 + 92))(
    a1: v23,
    a2: 0,
    a3: "STATIC",
    a4: "Default:",
    a5: 1342177280,
    a6: ctrlrect->left,
    a7: ctrlrect->top,
    a8: 50,
    a9: 24,
    a10: this->m_hWnd,
    a11: -1,
    a12: 0);
  SendMessageA(hWnd: *(HWND *)(i + 32), Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  v24 = (CWnd *)operator new(nSize: 0x74u);
  pData = v24;
  v67 = 11;
  if ( v24 != nullptr )
  {
    CWnd::CWnd(this: v24);
    v25 = (char *)pData;
    *(_DWORD *)pData = &CEdit::`vftable';
    LOBYTE(v67) = 11;
  }
  else
  {
    v25 = nullptr;
  }
  pType = v25;
  v67 = -1;
  v59 = this->m_hWnd;
  this->m_pEditInstanceDefault = (CEdit *)v25;
  (*(void (__thiscall **)(const char *, int, const char *, const char *, int, int, int, int, int, HWND__ *, int))(*(_DWORD *)v25 + 92))(
    a1: pType,
    a2: 512,
    a3: "EDIT",
    a4: &var,
    a5: 1350631552,
    a6: ctrlrect->left + 50,
    a7: ctrlrect->top,
    a8: ctrlrect->right - ctrlrect->left - 50,
    a9: 24,
    a10: v59,
    a11: 6);
  SendMessageA(hWnd: this->m_pEditInstanceDefault->m_hWnd, Msg: 0x30u, wParam: (WPARAM)hControlFont, lParam: 0);
  CWnd::SetWindowTextA(this: this->m_pEditInstanceDefault, lpszString: pDefault);
  SendMessageA(hWnd: this->m_pEditInstanceDefault->m_hWnd, Msg: 0xC5u, wParam: 0x1Cu, lParam: 0);
  if ( pVar->m_bReadOnly )
    CWnd::EnableWindow(this: this->m_pEditInstanceDefault, bEnable: 0);
  m_pEditInstanceVariable = this->m_pEditInstanceVariable;
  p_m_SmartControls = (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls;
  this->m_pSmartControl = m_pEditInstanceVariable;
  m_Size = this->m_SmartControls.m_Size;
  hControlFonta = (HFONT__ *)m_pEditInstanceVariable;
  m_nAllocationCount = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SmartControls.m_Size;
  m_pMemory = p_m_SmartControls->m_pMemory;
  v31 = this->m_SmartControls.m_Size - m_Size - 1;
  this->m_SmartControls.m_pElements = this->m_SmartControls.m_Memory.m_pMemory;
  if ( v31 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v31);
  v32 = (HFONT__ **)&p_m_SmartControls->m_pMemory[m_Size];
  if ( v32 != nullptr )
    *v32 = hControlFonta;
  v33 = this->m_SmartControls.m_Size;
  hControlFontb = (HFONT__ *)this->m_pComboInstanceParmType;
  v34 = this->m_SmartControls.m_Memory.m_nAllocationCount;
  if ( v33 + 1 > v34 )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_SmartControls,
      num: v33 - v34 + 1);
  ++this->m_SmartControls.m_Size;
  v35 = p_m_SmartControls->m_pMemory;
  v36 = this->m_SmartControls.m_Size - v33 - 1;
  this->m_SmartControls.m_pElements = this->m_SmartControls.m_Memory.m_pMemory;
  if ( v36 > 0 )
    _V_memmove(dest: &v35[v33 + 1], src: &v35[v33], count: 4 * v36);
  v37 = (HFONT__ **)&p_m_SmartControls->m_pMemory[v33];
  if ( v37 != nullptr )
    *v37 = hControlFontb;
  m_pEditInstanceDefault = this->m_pEditInstanceDefault;
  v39 = this->m_SmartControls.m_Size;
  v40 = p_m_SmartControls->m_nAllocationCount;
  if ( v39 + 1 > v40 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: v39 - v40 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v41 = p_m_SmartControls->m_pMemory;
  v42 = (int)p_m_SmartControls[1].m_pMemory - v39 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v42 > 0 )
    _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 4 * v42);
  v43 = (CEdit **)&p_m_SmartControls->m_pMemory[v39];
  if ( v43 != nullptr )
    *v43 = m_pEditInstanceDefault;
  v44 = p_m_SmartControls[1].m_pMemory;
  v45 = p_m_SmartControls->m_nAllocationCount;
  if ( (int)v44 + 1 > v45 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: (int)v44 - v45 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v46 = p_m_SmartControls->m_pMemory;
  v47 = (char *)p_m_SmartControls[1].m_pMemory - (char *)v44 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v47 > 0 )
    _V_memmove(dest: &v46[(_DWORD)v44 + 1], src: &v46[(_DWORD)v44], count: 4 * v47);
  v48 = &p_m_SmartControls->m_pMemory[(_DWORD)v44];
  if ( v48 != nullptr )
    *v48 = (CCullTreeNode *)v65;
  v49 = p_m_SmartControls[1].m_pMemory;
  v50 = p_m_SmartControls->m_nAllocationCount;
  if ( (int)v49 + 1 > v50 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: (int)v49 - v50 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v51 = p_m_SmartControls->m_pMemory;
  v52 = (char *)p_m_SmartControls[1].m_pMemory - (char *)v49 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v52 > 0 )
    _V_memmove(dest: &v51[(_DWORD)v49 + 1], src: &v51[(_DWORD)v49], count: 4 * v52);
  v53 = (CRect **)&p_m_SmartControls->m_pMemory[(_DWORD)v49];
  if ( v53 != nullptr )
    *v53 = ctrlrectb;
  v54 = p_m_SmartControls[1].m_pMemory;
  v55 = p_m_SmartControls->m_nAllocationCount;
  if ( (int)v54 + 1 > v55 )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_SmartControls, num: (int)v54 - v55 + 1);
  ++p_m_SmartControls[1].m_pMemory;
  v56 = p_m_SmartControls->m_pMemory;
  v57 = (char *)p_m_SmartControls[1].m_pMemory - (char *)v54 - 1;
  p_m_SmartControls[1].m_nAllocationCount = (int)p_m_SmartControls->m_pMemory;
  if ( v57 > 0 )
    _V_memmove(dest: &v56[(_DWORD)v54 + 1], src: &v56[(_DWORD)v54], count: 4 * v57);
  v58 = (int *)&p_m_SmartControls->m_pMemory[(_DWORD)v54];
  if ( v58 != nullptr )
    *v58 = i;
}

//------------------------------------------------------------------------------
// Address: 0x100DC970
// Name: protected: void COP_Entity::OnSetfocusKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnSetfocusKey(COP_Entity *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_szOldKeyName; // edi

  p_m_szOldKeyName = &this->m_szOldKeyName;
  CWnd::GetWindowTextA(this: &this->m_cKey, rString: &this->m_szOldKeyName);
  if ( *((_DWORD *)p_m_szOldKeyName->m_pszData - 3) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeLower(this: p_m_szOldKeyName);
    this->m_bChangingKeyName = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCB40
// Name: protected: void COP_Entity::RemoveBlankKeys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::RemoveBlankKeys(COP_Entity *this)
{
  WCKeyValuesT<WCKVBase_Dict> *p_m_kv; // ebx
  int Inorder; // esi
  int v3; // edi

  p_m_kv = &this->m_kv;
  Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_kv.m_KeyValues.m_Elements.m_Tree);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v3 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
             this: &p_m_kv->m_KeyValues.m_Elements.m_Tree,
             i: Inorder);
      if ( this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem.szValue[0] == 0 )
        WCKVBase_Dict::RemoveKeyAt(this: p_m_kv, nIndex: Inorder);
      Inorder = v3;
    }
    while ( v3 != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCBA0
// Name: protected: void COP_Entity::OnBrowseInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnBrowseInstance(COP_Entity *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  CMapDoc *v4; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *PathName; // eax
  char *m_pszData; // ecx
  char *v7; // edx
  char v8; // al
  char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  char *v13; // eax
  char *v14; // eax
  CFileDialog dlg; // [esp+8h] [ebp-320h] BYREF
  char FileName[260]; // [esp+20Ch] [ebp-11Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+310h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > MapFileName; // [esp+314h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > currentValue; // [esp+318h] [ebp-10h] BYREF
  int v20; // [esp+324h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  MapFileName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v20 = 1;
  v3 = AfxGetStringManager();
  if ( v3 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  currentValue.m_pszData = (char *)&v3->GetNilString(this: v3)[1];
  LOBYTE(v20) = 3;
  v4 = CMapDoc::m_pMapDoc;
  CWnd::GetWindowTextA(this: this->m_pSmartControl, rString: &currentValue);
  ATL::CSimpleStringT<char,0>::operator=(this: &MapFileName, strSrc: (ATL::CStringData *)&v4->m_strPathName);
  CInstancingHelper::ResolveInstancePath(
    pFileSystem: g_pFullFileSystem,
    pBaseFilename: MapFileName.m_pszData,
    pInstanceFilename: currentValue.m_pszData,
    pInstanceDirectory: CMapInstance::m_InstancePath,
    pResolvedInstanceFilename: FileName,
    nBufferSize: 260);
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: ".vmf",
    lpszFileName: FileName,
    dwFlags: 0x800000u,
    lpszFilter: "Valve Map Files (*.vmf)|*.vmf||",
    pParentWnd: this,
    dwSize: 0,
    bVistaStyle: 1);
  LOBYTE(v20) = 4;
  if ( CFileDialog::DoModal(this: &dlg) == 1 )
  {
    PathName = CFileDialog::GetPathName(this: &dlg, &result);
    LOBYTE(v20) = 5;
    m_pszData = PathName->m_pszData;
    v7 = FileName;
    do
    {
      v8 = *m_pszData;
      *v7++ = *m_pszData++;
    }
    while ( v8 != 0 );
    LOBYTE(v20) = 4;
    v9 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v9 + 4))(a1: *(_DWORD *)v9, a2: v9);
    V_RemoveDotSlashes(pFilename: FileName, separator: 92);
    V_FixDoubleSlashes(pStr: FileName);
    _V_strlower(start: FileName);
    strstr(str1: (unsigned __int8 *)FileName, str2: "\\maps\\");
    if ( v10 != 0 )
    {
      v11 = (const char *)(v10 + 6);
LABEL_15:
      *((_BYTE *)v11 - 1) = 0;
      CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: v11);
      goto LABEL_16;
    }
    if ( CMapInstance::m_InstancePath[0] != 0 )
    {
      strstr(str1: (unsigned __int8 *)FileName, str2: (unsigned __int8 *)CMapInstance::m_InstancePath);
      if ( v12 != 0 )
      {
        v11 = (const char *)(strlen(CMapInstance::m_InstancePath) + v12);
        goto LABEL_15;
      }
    }
  }
LABEL_16:
  LOBYTE(v20) = 3;
  CFileDialog::~CFileDialog(this: &dlg);
  LOBYTE(v20) = 1;
  v13 = currentValue.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)currentValue.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v13 + 4))(a1: *(_DWORD *)v13, a2: v13);
  v20 = -1;
  v14 = MapFileName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)MapFileName.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v14 + 4))(a1: *(_DWORD *)v14, a2: v14);
}

//------------------------------------------------------------------------------
// Address: 0x100DCDF0
// Name: protected: void COP_Entity::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnCopy(COP_Entity *this)
{
  int i; // edi
  int v3; // esi
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strClass; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+14h] [ebp-4h]

  WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &kvClipboard);
  bKvClipEmpty = 0;
  for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_kv.m_KeyValues.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_kv.m_KeyValues.m_Elements.m_Tree,
              i) )
  {
    v3 = (unsigned __int16)i;
    if ( _V_stricmp(
           s1: this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szKey,
           s2: "origin") != 0 )
      WCKeyValuesT<WCKVBase_Dict>::SetValue(
        this: &kvClipboard,
        pszKey: this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szKey,
        pszValue: this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szValue);
  }
  CFilteredComboBox::GetCurrentItem(this: &this->m_cClasses, result: &strClass);
  v6 = 0;
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &kvClipboard, pszKey: "xxxClassxxx", pszValue: strClass.m_pszData);
  v6 = -1;
  v4 = strClass.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strClass.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100DCF00
// Name: protected: void COP_Entity::GetFaceIDListsForKey(class CMapFaceIDList __near &,class CMapFaceIDList __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::GetFaceIDListsForKey(
        COP_Entity *this,
        CUtlMemory<vgui::TreeNode *,int> *FullFaces,
        CMapFaceIDList *PartialFaces,
        const char *pszKey)
{
  CMapWorld *ActiveWorld; // eax
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int v7; // edi
  CUtlReference<CMapClass> *v8; // ecx
  int v9; // edi
  int v10; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v12; // ecx
  void *v13; // edx
  char *v14; // eax
  const char *Value; // eax
  CMapFaceIDList TempFaces; // [esp+8h] [ebp-50h] BYREF
  CMapFaceIDList TempFullFaces; // [esp+1Ch] [ebp-3Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+30h] [ebp-28h] BYREF
  CUtlReference<CMapClass> *v19; // [esp+34h] [ebp-24h]
  void *inptr; // [esp+38h] [ebp-20h]
  COP_Entity *v21; // [esp+3Ch] [ebp-1Ch]
  int pos; // [esp+40h] [ebp-18h]
  CMapWorld *pWorld; // [esp+44h] [ebp-14h]
  bool bFirst; // [esp+4Bh] [ebp-Dh]
  int v25; // [esp+54h] [ebp-4h]

  v21 = this;
  ActiveWorld = GetActiveWorld();
  m_pObjectList = this->m_pObjectList;
  pWorld = ActiveWorld;
  if ( m_pObjectList != nullptr && ActiveWorld != nullptr )
  {
    v7 = 0;
    bFirst = true;
    for ( pos = 0; v7 < m_pObjectList->m_Size; pos = v7 )
    {
      v8 = m_pObjectList->m_Memory.m_pMemory[v7 >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)];
      v9 = pos;
      v10 = pos & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5);
      m_pObject = v8[v10].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = v8[v10].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v12 = m_pObject->m_References.m_pHead;
        if ( v12 != nullptr )
          v12->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v19 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v13 = inptr;
      v25 = -1;
      if ( inptr != nullptr )
      {
        if ( v19 != nullptr )
        {
          v19->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v19;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v19 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v14 = (char *)__RTDynamicCast(
                      inptr: v13,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapEntity `RTTI Type Descriptor',
                      isReference: 0);
      if ( v14 != nullptr )
      {
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: (WCKeyValuesT<WCKVBase_Dict> *)(v14 + 220),
                  pszKey,
                  piIndex: nullptr);
        if ( bFirst )
        {
          CMapWorld::FaceID_StringToFaceIDLists(
            this: pWorld,
            pFullFaceList: FullFaces,
            pPartialFaceList: nullptr,
            pszValue: Value);
          bFirst = false;
        }
        else
        {
          memset(&TempFaces, 0, sizeof(TempFaces));
          v25 = 3;
          CMapWorld::FaceID_StringToFaceIDLists(
            this: pWorld,
            pFullFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&TempFaces,
            pPartialFaceList: nullptr,
            pszValue: Value);
          memset(&TempFullFaces, 0, sizeof(TempFullFaces));
          LOBYTE(v25) = 5;
          CUtlVector<int,CUtlMemory<int,int>>::AddVectorToTail(
            this: &TempFullFaces,
            src: (const CUtlVector<int,CUtlMemory<int,int> > *)FullFaces);
          LOBYTE(v25) = 6;
          FullFaces[1].m_pMemory = nullptr;
          CMapFaceIDList::Intersect(
            this: &TempFaces,
            IntersectWith: &TempFullFaces,
            In: (CMapFaceIDList *)FullFaces,
            Out: PartialFaces);
          LOBYTE(v25) = 3;
          CMapFaceIDList::~CMapFaceIDList(this: &TempFullFaces);
          v25 = -1;
          CMapFaceIDList::~CMapFaceIDList(this: &TempFaces);
        }
      }
      m_pObjectList = v21->m_pObjectList;
      v7 = v9 + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD0E0
// Name: protected: void COP_Entity::GetFaceListsForKey(class CMapFaceList __near &,class CMapFaceList __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::GetFaceListsForKey(
        COP_Entity *this,
        CUtlMemory<CCullTreeNode *,int> *FullFaces,
        CMapFaceList *PartialFaces,
        const char *pszKey)
{
  CMapWorld *ActiveWorld; // eax
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int v7; // edi
  CUtlReference<CMapClass> *v8; // ecx
  int v9; // edi
  int v10; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v12; // ecx
  void *v13; // edx
  char *v14; // eax
  const char *Value; // eax
  CMapFaceList TempFaces; // [esp+8h] [ebp-50h] BYREF
  CMapFaceList TempFullFaces; // [esp+1Ch] [ebp-3Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+30h] [ebp-28h] BYREF
  CUtlReference<CMapClass> *v19; // [esp+34h] [ebp-24h]
  void *inptr; // [esp+38h] [ebp-20h]
  COP_Entity *v21; // [esp+3Ch] [ebp-1Ch]
  int pos; // [esp+40h] [ebp-18h]
  CMapWorld *pWorld; // [esp+44h] [ebp-14h]
  bool bFirst; // [esp+4Bh] [ebp-Dh]
  int v25; // [esp+54h] [ebp-4h]

  v21 = this;
  ActiveWorld = GetActiveWorld();
  m_pObjectList = this->m_pObjectList;
  pWorld = ActiveWorld;
  if ( m_pObjectList != nullptr && ActiveWorld != nullptr )
  {
    v7 = 0;
    bFirst = true;
    for ( pos = 0; v7 < m_pObjectList->m_Size; pos = v7 )
    {
      v8 = m_pObjectList->m_Memory.m_pMemory[v7 >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)];
      v9 = pos;
      v10 = pos & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5);
      m_pObject = v8[v10].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = v8[v10].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v12 = m_pObject->m_References.m_pHead;
        if ( v12 != nullptr )
          v12->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v19 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v13 = inptr;
      v25 = -1;
      if ( inptr != nullptr )
      {
        if ( v19 != nullptr )
        {
          v19->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v19;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v19 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v14 = (char *)__RTDynamicCast(
                      inptr: v13,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapEntity `RTTI Type Descriptor',
                      isReference: 0);
      if ( v14 != nullptr )
      {
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: (WCKeyValuesT<WCKVBase_Dict> *)(v14 + 220),
                  pszKey,
                  piIndex: nullptr);
        if ( bFirst )
        {
          CMapWorld::FaceID_StringToFaceLists(
            this: pWorld,
            pFullFaceList: FullFaces,
            pPartialFaceList: nullptr,
            pszValue: Value);
          bFirst = false;
        }
        else
        {
          memset(&TempFaces, 0, sizeof(TempFaces));
          v25 = 3;
          CMapWorld::FaceID_StringToFaceLists(
            this: pWorld,
            pFullFaceList: (CUtlMemory<CCullTreeNode *,int> *)&TempFaces,
            pPartialFaceList: nullptr,
            pszValue: Value);
          memset(&TempFullFaces, 0, sizeof(TempFullFaces));
          LOBYTE(v25) = 5;
          CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int>>::AddVectorToTail(
            this: &TempFullFaces,
            src: (const CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *)FullFaces);
          LOBYTE(v25) = 6;
          FullFaces[1].m_pMemory = nullptr;
          CMapFaceList::Intersect(
            this: &TempFaces,
            IntersectWith: &TempFullFaces,
            In: (CMapFaceList *)FullFaces,
            Out: PartialFaces);
          LOBYTE(v25) = 3;
          CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&TempFullFaces);
          v25 = -1;
          CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&TempFaces);
        }
      }
      m_pObjectList = v21->m_pObjectList;
      v7 = v9 + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD2C0
// Name: protected: void COP_Entity::OnPickFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPickFaces(COP_Entity *this)
{
  CWnd *DlgItem; // eax
  int CurVarListSelection; // eax
  GDinputvariable *VariableAt; // edi
  CToolManager *v5; // eax
  CToolManager *v6; // eax
  CToolManager *v7; // eax
  CToolPickFace *ToolForID; // ebx
  CToolManager *v9; // eax
  CToolPickFace *v10; // eax
  CToolManager *v11; // eax
  CMapFaceList FullFaces; // [esp+8h] [ebp-34h] BYREF
  CMapFaceList PartialFaces; // [esp+1Ch] [ebp-20h] BYREF
  int v14; // [esp+38h] [ebp-4h]

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1533);
    if ( DlgItem != nullptr )
    {
      if ( SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
      {
        CurVarListSelection = COP_Entity::GetCurVarListSelection(this);
        if ( CurVarListSelection != -1 )
        {
          VariableAt = COP_Entity::GetVariableAt(this, index: CurVarListSelection);
          if ( VariableAt != nullptr )
          {
            memset(&FullFaces, 0, sizeof(FullFaces));
            v14 = 5;
            memset(&PartialFaces, 0, sizeof(PartialFaces));
            COP_Entity::GetFaceListsForKey(
              this,
              (CUtlMemory<CCullTreeNode *,int> *)&FullFaces,
              &PartialFaces,
              pszKey: VariableAt->m_szName);
            v5 = ToolManager();
            this->m_ToolPrePick = CToolManager::GetActiveToolID(this: v5);
            this->m_bPicking = true;
            v6 = ToolManager();
            CToolManager::SetTool(this: v6, eNewTool: TOOL_PICK_FACE);
            v7 = ToolManager();
            ToolForID = (CToolPickFace *)CToolManager::GetToolForID(this: v7, eToolID: TOOL_PICK_FACE);
            CToolPickFace::SetSelectedFaces(this: ToolForID, FaceListFull: &FullFaces, FaceListPartial: &PartialFaces);
            this->m_PickFaceTarget.m_pDlg = this;
            ToolForID->m_pNotifyTarget = &this->m_PickFaceTarget;
            CToolPickFace::AllowMultiSelect(this: ToolForID, bAllow: VariableAt->m_eType == ivSideList);
            LOBYTE(v14) = 2;
            CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&PartialFaces);
            v14 = -1;
            CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&FullFaces);
          }
        }
      }
      else
      {
        this->m_bPicking = false;
        v9 = ToolManager();
        v10 = (CToolPickFace *)CToolManager::GetToolForID(this: v9, eToolID: TOOL_PICK_FACE);
        this->UpdatePickFaceText(this, a2: v10);
        v11 = ToolManager();
        CToolManager::SetTool(this: v11, eNewTool: TOOL_POINTER);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD690
// Name: protected: void COP_Entity::MergeKeyValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::MergeKeyValue(COP_Entity *this, const char *pszKey)
{
  GDclass *m_pEditClass; // ecx
  GDinputvariable *v4; // eax
  GDIV_TYPE m_eType; // ecx
  char szValue[512]; // [esp+Ch] [ebp-234h] BYREF
  CMapFaceIDList FaceIDListPartial; // [esp+20Ch] [ebp-34h] BYREF
  CMapFaceIDList FaceIDListFull; // [esp+220h] [ebp-20h] BYREF
  int v9; // [esp+23Ch] [ebp-4h]

  if ( pszKey != nullptr )
  {
    m_pEditClass = this->m_pEditClass;
    if ( m_pEditClass != nullptr )
    {
      v4 = GDclass::VarForName(this: m_pEditClass, pszName: pszKey, piIndex: nullptr);
      if ( v4 != nullptr )
      {
        m_eType = v4->m_eType;
        if ( m_eType != ivAngle )
        {
          if ( m_eType == ivSideList )
          {
            memset(&FaceIDListFull, 0, sizeof(FaceIDListFull));
            v9 = 5;
            memset(&FaceIDListPartial, 0, sizeof(FaceIDListPartial));
            COP_Entity::GetFaceIDListsForKey(
              this,
              FullFaces: (CUtlMemory<vgui::TreeNode *,int> *)&FaceIDListFull,
              PartialFaces: &FaceIDListPartial,
              pszKey);
            CMapWorld::FaceID_FaceIDListsToString(
              pszList: szValue,
              nSize: 512,
              pFullFaceIDList: &FaceIDListFull,
              pPartialFaceIDList: &FaceIDListPartial);
            WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey, pszValue: szValue);
            LOBYTE(v9) = 2;
            CMapFaceIDList::~CMapFaceIDList(this: &FaceIDListPartial);
            v9 = -1;
            CMapFaceIDList::~CMapFaceIDList(this: &FaceIDListFull);
            return;
          }
        }
        else if ( _V_stricmp(s1: v4->m_szName, s2: "angles") != 0 )
        {
          CAngleBox::SetDifferent(this: &this->m_SmartAngle, bDifferent: true, bRedraw: true);
        }
      }
    }
    WCKeyValuesT<WCKVBase_Dict>::SetValue(
      this: &this->m_kv,
      pszKey,
      pszValue: (const char *)CObjectPage::VALUE_DIFFERENT_STRING);
    if ( _V_stricmp(s1: pszKey, s2: "angles") == 0 )
      CAngleBox::SetDifferent(this: &this->m_Angle, bDifferent: true, bRedraw: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD810
// Name: private: void COP_Entity::UpdateAnchors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdateAnchors(COP_Entity *this)
{
  int i; // edi
  CWnd *v3; // eax
  HWND__ *m_hWnd; // eax
  const CAnchorDef *v5; // eax
  CAnchorDef *m_pMemory; // edi
  int m_nGrowSize; // esi
  CAnchorDef v8; // [esp+Ch] [ebp-390h] BYREF
  CAnchorDef anchorDefs[19]; // [esp+38h] [ebp-364h] BYREF
  CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > defs; // [esp+37Ch] [ebp-20h] BYREF
  int v11; // [esp+398h] [ebp-4h]

  CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1024, eSimpleAnchor: k_eSimpleAnchorAllSides);
  CAnchorDef::CAnchorDef(this: &anchorDefs[1], dlgItemID: 1119, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[2], dlgItemID: 1497, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[3], dlgItemID: 1668, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[4], dlgItemID: 1107, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[5], dlgItemID: 1105, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[6], dlgItemID: 1663, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[7], dlgItemID: 1009, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[8], dlgItemID: 1664, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[9], dlgItemID: 1396, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[10], dlgItemID: 1108, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[11], dlgItemID: 1109, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[12], dlgItemID: 1106, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[13], dlgItemID: 1525, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(
    this: &anchorDefs[14],
    dlgItemID: 1524,
    eLeftSide: k_eAnchorRight,
    eTopSide: k_eAnchorTop,
    eRightSide: k_eAnchorRight,
    eBottomSide: k_eAnchorBottom);
  CAnchorDef::CAnchorDef(this: &anchorDefs[15], dlgItemID: 1669, eSimpleAnchor: k_eSimpleAnchorBottomRight);
  CAnchorDef::CAnchorDef(
    this: &anchorDefs[16],
    dlgItemID: 1494,
    eLeftSide: k_eAnchorRight,
    eTopSide: k_eAnchorBottom,
    eRightSide: k_eAnchorRight,
    eBottomSide: k_eAnchorBottom);
  CAnchorDef::CAnchorDef(this: &anchorDefs[17], dlgItemID: 1033, eSimpleAnchor: k_eSimpleAnchorRightSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[18], dlgItemID: 1032, eSimpleAnchor: k_eSimpleAnchorRightSide);
  memset(&defs, 0, sizeof(defs));
  v11 = 1;
  CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::CopyArray(this: &defs, pArray: anchorDefs, size: 19);
  for ( i = 0; i < this->m_SmartControls.m_Size; ++i )
  {
    v3 = this->m_SmartControls.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      m_hWnd = v3->m_hWnd;
    else
      m_hWnd = nullptr;
    v5 = CAnchorDef::CAnchorDef(this: &v8, hWnd: m_hWnd, eSimpleAnchor: k_eSimpleAnchorRightSide);
    CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::InsertBefore(this: &defs, elem: defs.m_Size, src: v5);
  }
  m_pMemory = defs.m_Memory.m_pMemory;
  CAnchorMgr::Init(
    this: &this->m_AnchorMgr,
    hParentWnd: this->m_hWnd,
    pAnchors: defs.m_Memory.m_pMemory,
    nAnchors: defs.m_Size);
  v11 = 2;
  m_nGrowSize = defs.m_Memory.m_nGrowSize;
  defs.m_Size = 0;
  if ( defs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      m_pMemory = nullptr;
      defs.m_Memory.m_pMemory = nullptr;
    }
    defs.m_Memory.m_nAllocationCount = 0;
  }
  defs.m_pElements = m_pMemory;
  v11 = -1;
  if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
    free(pMem: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100DDA70
// Name: protected: void COP_Entity::DestroySmartControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::DestroySmartControls(COP_Entity *this)
{
  int i; // ebx
  CWnd *v3; // edi

  for ( i = 0; i < this->m_SmartControls.m_Size; ++i )
  {
    v3 = this->m_SmartControls.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      v3->DestroyWindow(this: v3);
      ((void (__thiscall *)(CWnd *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    }
  }
  this->m_SmartControls.m_Size = 0;
  this->m_pSmartBrowseButton = nullptr;
  this->m_pSmartControl = nullptr;
  this->m_pLastSmartControlVar = nullptr;
  this->m_pEditInstanceVariable = nullptr;
  this->m_pEditInstanceValue = nullptr;
  this->m_pComboInstanceParmType = nullptr;
  COP_Entity::UpdateAnchors(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DDAE0
// Name: protected: void COP_Entity::OnChangeSmartcontrolSel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnChangeSmartcontrolSel(COP_Entity *this)
{
  int v2; // eax
  int v3; // edi
  GDclass *m_pDisplayClass; // ecx
  __int16 v5; // ax
  GDinputvariable *v6; // eax
  GDIV_TYPE m_eType; // eax
  CWnd *m_pSmartControl; // edi
  WPARAM v9; // eax
  GDinputvariable *v10; // ebx
  char *v11; // eax
  char *v12; // edx
  char v13; // cl
  char szBuf[128]; // [esp+Ch] [ebp-98h] BYREF
  tagRECT rc; // [esp+8Ch] [ebp-18h] BYREF
  GDinputvariable *pVar; // [esp+9Ch] [ebp-8h]
  int iSel; // [esp+A0h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
    iSel = v3;
  }
  else
  {
    iSel = -1;
  }
  m_pDisplayClass = this->m_pDisplayClass;
  if ( m_pDisplayClass != nullptr )
  {
    v5 = this->m_VarMap[iSel];
    if ( v5 != -1 )
    {
      v6 = v5 > -10
         ? GDclass::GetVariableAt(this: m_pDisplayClass, iIndex: v5)
         : this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v5)].m_Data.elem.m_ParmVariable;
      pVar = v6;
      if ( v6 != nullptr )
      {
        m_eType = v6->m_eType;
        if ( m_eType == ivTargetSrc
          || m_eType == ivTargetDest
          || m_eType == ivTargetNameOrClass
          || m_eType == ivChoices
          || m_eType == ivNPCClass
          || m_eType == ivFilterClass
          || m_eType == ivPointEntityClass )
        {
          m_pSmartControl = this->m_pSmartControl;
          v9 = SendMessageA(hWnd: m_pSmartControl->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
          if ( v9 == -1 )
            CWnd::GetWindowTextA(this: m_pSmartControl, lpszString: szBuf, nMaxCount: 128);
          else
            SendMessageA(hWnd: m_pSmartControl->m_hWnd, Msg: 0x148u, wParam: v9, lParam: (LPARAM)szBuf);
          v10 = pVar;
          if ( pVar->m_eType == ivChoices )
          {
            v11 = (char *)GDinputvariable::ItemValueForString(this: pVar, szString: szBuf);
            if ( v11 != nullptr )
            {
              v12 = (char *)(szBuf - v11);
              do
              {
                v13 = *v11;
                v11[(_DWORD)v12] = *v11;
                ++v11;
              }
              while ( v13 != 0 );
            }
          }
          ATL::CSimpleStringT<char,0>::SetString(
            this: &this->m_LastSmartControlVarValue,
            pszSrc: szBuf,
            nLength: strlen(szBuf));
          WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kvAdded, pszKey: v10->m_szName, pszValue: "1");
          WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: v10->m_szName, pszValue: szBuf);
          COP_Entity::RefreshKVListValues(this, pOnlyThisVar: v10->m_szName);
          if ( CListCtrl::GetItemRect(this: &this->m_VarList, nItem: iSel, lpRect: &rc, nCode: 0) != 0 )
            InvalidateRect(hWnd: this->m_VarList.m_hWnd, lpRect: &rc, bErase: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDDA0
// Name: StripDirPrefix
// Source: json
//------------------------------------------------------------------------------
ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *__usercall StripDirPrefix@<eax>(
        const char *pFilename@<esi>,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pPrefix,
        const char *pPrefixa)
{
  int v3; // ebx
  char v4; // al

  v3 = std::char_traits<char>::length(str: pPrefixa);
  if ( V_stristr(pStr: pFilename, pSearch: pPrefixa) == pFilename && ((v4 = pFilename[v3]) == 47 || v4 == 92) )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: pPrefix,
      pszSrc: &pFilename[v3 + 1]);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: pPrefix,
      pszSrc: pFilename);
  return pPrefix;
}

//------------------------------------------------------------------------------
// Address: 0x100DDE30
// Name: public: COP_Entity::COP_Entity(void)
// Source: json
//------------------------------------------------------------------------------
COP_Entity *__thiscall COP_Entity::COP_Entity(COP_Entity *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  CWnd **m_pMemory; // ecx
  ATL::IAtlStringMgr *v4; // eax
  ATL::IAtlStringMgr *v5; // eax
  UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t,unsigned short> *v6; // ecx

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x6Au, nIDCaption: 0, dwSize: 0x38u);
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Entity_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CFilteredComboBox::ICallbacks::`vftable';
  this->CColoredListCtrl::IItemColorCallback::__vftable = (CColoredListCtrl::IItemColorCallback_vtbl *)&CColoredListCtrl::IItemColorCallback::`vftable';
  this->IDlgListManageBrowse::__vftable = (IDlgListManageBrowse_vtbl *)&IDlgListManageBrowse::`vftable';
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Entity_vtbl *)&COP_Entity::`vftable'{for `CObjectPage'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&COP_Entity::`vftable'{for `CFilteredComboBox::ICallbacks'};
  this->CColoredListCtrl::IItemColorCallback::__vftable = (CColoredListCtrl::IItemColorCallback_vtbl *)&COP_Entity::`vftable'{for `CColoredListCtrl::IItemColorCallback'};
  this->IDlgListManageBrowse::__vftable = (IDlgListManageBrowse_vtbl *)&COP_Entity::`vftable'{for `IDlgListManageBrowse'};
  CAngleCombo::CAngleCombo(this: &this->m_AngleEdit);
  CAngleCombo::CAngleCombo(this: &this->m_SmartAngleEdit);
  CWnd::CWnd(this: &this->m_cValue);
  this->m_cValue.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_VarList);
  this->m_VarList.__vftable = (CColoredListCtrl_vtbl *)&CListCtrl::`vftable';
  this->m_VarList.__vftable = (CColoredListCtrl_vtbl *)&CColoredListCtrl::`vftable';
  this->m_VarList.m_pCallback = &this->CColoredListCtrl::IItemColorCallback;
  CWnd::CWnd(this: &this->m_cKey);
  this->m_cKey.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CFilteredComboBox::CFilteredComboBox(this: &this->m_cClasses, pCallbacks: &this->CFilteredComboBox::ICallbacks);
  CWnd::CWnd(this: &this->m_Comments);
  this->m_Comments.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_KeyValueHelpText);
  this->m_KeyValueHelpText.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_PasteControl);
  this->m_PasteControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_szOldKeyName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  CAngleBox::CAngleBox(this: &this->m_Angle);
  CAngleBox::CAngleBox(this: &this->m_SmartAngle);
  CWnd::CWnd(this: &this->m_cPickColor);
  this->m_cPickColor.__vftable = (CButton_vtbl *)&CButton::`vftable';
  this->m_SmartControls.m_Memory.m_pMemory = nullptr;
  this->m_SmartControls.m_Memory.m_nAllocationCount = 0;
  this->m_SmartControls.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_SmartControls.m_Memory.m_pMemory;
  this->m_SmartControls.m_Size = 0;
  this->m_SmartControls.m_pElements = m_pMemory;
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_LastSmartControlVarValue.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strLastKey.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &this->m_kv);
  WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &this->m_kvAdded);
  this->m_PickAnglesTarget.__vftable = (CPickAnglesTarget_vtbl *)&CPickAnglesTarget::`vftable';
  this->m_PickEntityTarget.__vftable = (CPickEntityTarget_vtbl *)&CPickEntityTarget::`vftable';
  this->m_PickEntityTarget.m_szKey[0] = 0;
  this->m_PickEntityTarget.m_pDlg = nullptr;
  this->m_PickFaceTarget.__vftable = (CPickFaceTarget_vtbl *)&CPickFaceTarget::`vftable';
  this->m_SmartControlTargetNameRouter.__vftable = (CSmartControlTargetNameRouter_vtbl *)&CSmartControlTargetNameRouter::`vftable';
  this->m_SmartControlTargetNameRouter.m_pDlg = this;
  this->m_InstanceParmData.m_Tree.m_LessFunc.m_LessFunc = UtlStringLessFunc;
  this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_InstanceParmData.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_InstanceParmData.m_Tree.m_Elements.m_nGrowSize = 0;
  v6 = this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_InstanceParmData.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_InstanceParmData.m_Tree.m_FirstFree = -1;
  this->m_InstanceParmData.m_Tree.m_pElements = v6;
  this->m_iLastClassListSolidClasses = -9999;
  this->m_bAllowPresentProperties = true;
  this->m_nPresentPropertiesCalls = 0;
  this->m_bClassSelectionEmpty = false;
  CFilteredComboBox::SetOnlyProvideSuggestions(this: &this->m_cClasses, bOnlyProvideSuggestions: true);
  this->m_bPicking = false;
  this->m_pSmartBrowseButton = nullptr;
  this->m_pLastSmartControlVar = nullptr;
  this->m_pEditInstanceVariable = nullptr;
  this->m_pEditInstanceValue = nullptr;
  this->m_pComboInstanceParmType = nullptr;
  this->m_pEditInstanceDefault = nullptr;
  *(_WORD *)&this->m_bIgnoreKVChange = 0;
  this->m_bSmartedit = true;
  this->m_pSmartControl = nullptr;
  this->m_pDisplayClass = nullptr;
  this->m_pEditClass = nullptr;
  this->m_eEditType = ivString;
  this->m_nNewKeyCount = 0;
  this->m_iSortColumn = -1;
  this->m_bEnableControlUpdate = true;
  this->m_pEditObjectRuntimeClass = &editCEditGameClass::classeditCEditGameClass;
  this->m_pInstanceVar = nullptr;
  this->m_pModelBrowser = nullptr;
  this->m_pParticleBrowser = nullptr;
  this->m_bCustomColorsLoaded = false;
  memset(dst: (unsigned __int8 *)this->CustomColors, value: 0, count: sizeof(this->CustomColors));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DE230
// Name: public: virtual COP_Entity::~COP_Entity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::~COP_Entity(COP_Entity *this)
{
  CModelBrowser *m_pModelBrowser; // ecx
  CParticleBrowser *m_pParticleBrowser; // ecx
  volatile signed __int32 *v4; // eax
  volatile signed __int32 *v5; // eax
  CUtlVector<CWnd *,CUtlMemory<CWnd *,int> > *p_m_SmartControls; // edi
  volatile signed __int32 *v7; // eax

  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Entity_vtbl *)&COP_Entity::`vftable'{for `CObjectPage'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&COP_Entity::`vftable'{for `CFilteredComboBox::ICallbacks'};
  this->CColoredListCtrl::IItemColorCallback::__vftable = (CColoredListCtrl::IItemColorCallback_vtbl *)&COP_Entity::`vftable'{for `CColoredListCtrl::IItemColorCallback'};
  this->IDlgListManageBrowse::__vftable = (IDlgListManageBrowse_vtbl *)&COP_Entity::`vftable'{for `IDlgListManageBrowse'};
  COP_Entity::DestroySmartControls(this);
  m_pModelBrowser = this->m_pModelBrowser;
  if ( m_pModelBrowser != nullptr )
    ((void (__thiscall *)(CModelBrowser *, int))m_pModelBrowser->dtr_CObject)(a1: m_pModelBrowser, a2: 1);
  m_pParticleBrowser = this->m_pParticleBrowser;
  this->m_pModelBrowser = nullptr;
  if ( m_pParticleBrowser != nullptr )
    ((void (__thiscall *)(CParticleBrowser *, int))m_pParticleBrowser->dtr_CObject)(a1: m_pParticleBrowser, a2: 1);
  this->m_pParticleBrowser = nullptr;
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_InstanceParmData.m_Tree);
  WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &this->m_kvAdded);
  WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &this->m_kv);
  v4 = (volatile signed __int32 *)(this->m_strLastKey.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  v5 = (volatile signed __int32 *)(this->m_LastSmartControlVarValue.m_pszData - 16);
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
  p_m_SmartControls = &this->m_SmartControls;
  this->m_SmartControls.m_Size = 0;
  if ( this->m_SmartControls.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SmartControls->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SmartControls->m_Memory.m_pMemory);
      p_m_SmartControls->m_Memory.m_pMemory = nullptr;
    }
    this->m_SmartControls.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SmartControls.m_pElements = this->m_SmartControls.m_Memory.m_pMemory;
  if ( this->m_SmartControls.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SmartControls->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SmartControls->m_Memory.m_pMemory);
      p_m_SmartControls->m_Memory.m_pMemory = nullptr;
    }
    this->m_SmartControls.m_Memory.m_nAllocationCount = 0;
  }
  CButton::~CButton(this: &this->m_cPickColor);
  CAngleBox::~CAngleBox(this: &this->m_SmartAngle);
  CAngleBox::~CAngleBox(this: &this->m_Angle);
  v7 = (volatile signed __int32 *)(this->m_szOldKeyName.m_pszData - 16);
  if ( _InterlockedDecrement(v7 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(a1: v7);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_AnchorMgr);
  CButton::~CButton(this: &this->m_PasteControl);
  CEdit::~CEdit(this: &this->m_KeyValueHelpText);
  CEdit::~CEdit(this: &this->m_Comments);
  CFilteredComboBox::~CFilteredComboBox(this: &this->m_cClasses);
  CEdit::~CEdit(this: &this->m_cKey);
  CListCtrl::~CListCtrl(this: &this->m_VarList);
  CEdit::~CEdit(this: &this->m_cValue);
  CComboBox::~CComboBox(this: &this->m_SmartAngleEdit);
  CComboBox::~CComboBox(this: &this->m_AngleEdit);
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Entity_vtbl *)&CObjectPage::`vftable';
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DE4D0
// Name: protected: void COP_Entity::GetKeyState(char const __near *,enum EKeyState __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::GetKeyState(
        COP_Entity *this,
        const char *pShortName,
        EKeyState *pState,
        bool *pMissingTarget)
{
  GDinputvariable *v6; // eax
  GDinputvariable *v7; // ebx
  BOOL v8; // ebx
  bool *v9; // eax
  GDIV_TYPE m_eType; // eax
  const char *v11; // esi
  MDkeyvalue tmpkv; // [esp+4h] [ebp-44Ch] BYREF
  GDinputvariable varCopy; // [esp+254h] [ebp-1FCh] BYREF
  int v14; // [esp+44Ch] [ebp-4h]
  const char *pszCurValue; // [esp+458h] [ebp+8h]

  *pMissingTarget = false;
  if ( this->m_pDisplayClass != nullptr )
  {
    pszCurValue = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pShortName, piIndex: nullptr);
    if ( pszCurValue == nullptr )
      pszCurValue = &var;
    v6 = GDclass::VarForName(this: this->m_pDisplayClass, pszName: pShortName, piIndex: nullptr);
    v7 = v6;
    if ( v6 != nullptr )
    {
      m_eType = v6->m_eType;
      if ( m_eType == ivTargetSrc || m_eType == ivTargetDest )
      {
        v11 = pszCurValue;
        if ( *pszCurValue != 0 && IsValidTargetName(pTestName: pszCurValue) == 0 )
          *pMissingTarget = true;
      }
      else
      {
        v11 = pszCurValue;
      }
      GDinputvariable::GDinputvariable(this: &varCopy);
      v14 = 2;
      GDinputvariable::operator=(this: &varCopy, Other: v7);
      tmpkv.szKey[0] = 0;
      tmpkv.szValue[0] = 0;
      LOBYTE(v14) = 3;
      GDinputvariable::ResetDefaults(this: &varCopy);
      GDinputvariable::ToKeyValue(this: &varCopy, pkv: &tmpkv);
      *pState = _V_stricmp(s1: v11, s2: tmpkv.szValue) != 0;
      LOBYTE(v14) = 2;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
      v14 = -1;
      GDinputvariable::~GDinputvariable(this: &varCopy);
    }
    else
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMissingTarget,
        pszSrc: pShortName);
      v8 = CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Find(
             this: &this->m_InstanceParmData,
             key: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMissingTarget) != 0xFFFF;
      v14 = -1;
      v9 = pMissingTarget - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)pMissingTarget - 1) <= 0 )
        (*(void (__stdcall **)(bool *))(**(_DWORD **)v9 + 4))(a1: v9);
      *pState = v8 + 2;
    }
  }
  else
  {
    *pState = k_EKeyState_DefaultFGDValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE690
// Name: protected: void COP_Entity::ResortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::ResortItems(COP_Entity *this)
{
  LRESULT v2; // ebx
  const char *ItemData; // eax
  const char *v4; // edi
  GDclass *m_pDisplayClass; // ecx
  __int16 v6; // ax
  int v7; // edi
  char *v8; // eax
  HWND__ *m_hWnd; // edx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > key; // [esp+8h] [ebp-18h] BYREF
  int index; // [esp+Ch] [ebp-14h] BYREF
  __int16 *m_VarMap; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  SendMessageA(
    hWnd: this->m_VarList.m_hWnd,
    Msg: 0x1030u,
    wParam: (WPARAM)this,
    lParam: (LPARAM)g_ColumnSortFunctions[this->m_iSortColumn + 1]);
  if ( this->m_bSmartedit )
  {
    v2 = 0;
    if ( SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      m_VarMap = this->m_VarMap;
      do
      {
        ItemData = (const char *)CListCtrl::GetItemData(this: &this->m_VarList, nItem: v2);
        v4 = ItemData;
        if ( ItemData != nullptr )
        {
          m_pDisplayClass = this->m_pDisplayClass;
          index = -1;
          if ( m_pDisplayClass != nullptr
            && GDclass::VarForName(this: m_pDisplayClass, pszName: ItemData, piIndex: &index) != nullptr )
          {
            v6 = index;
LABEL_13:
            *m_VarMap = v6;
            goto LABEL_14;
          }
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
            this: &key,
            pszSrc: v4);
          v13 = 0;
          v7 = CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Find(
                 this: &this->m_InstanceParmData,
                 &key);
          v13 = -1;
          v8 = key.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)key.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
          if ( v7 == 0xFFFF )
          {
            v6 = -1;
            goto LABEL_13;
          }
          *m_VarMap = -10 - v7;
        }
LABEL_14:
        m_hWnd = this->m_VarList.m_hWnd;
        ++m_VarMap;
        ++v2;
      }
      while ( v2 < SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE7E0
// Name: protected: void COP_Entity::MergeObjectKeyValues(class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::MergeObjectKeyValues(COP_Entity *this, CEditGameClass *pEdit)
{
  unsigned __int16 i; // bx
  int v3; // esi
  const char *Value; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *v5; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
              i) )
  {
    v3 = i;
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: &this->m_kv,
              pszKey: pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szKey,
              piIndex: nullptr);
    if ( Value != nullptr )
    {
      v5 = &pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3];
      if ( strcmp(Value, v5->m_Data.elem.szValue) != 0 )
        COP_Entity::MergeKeyValue(this, pszKey: v5->m_Data.elem.szKey);
    }
    else
    {
      WCKeyValuesT<WCKVBase_Dict>::SetValue(
        this: &this->m_kv,
        pszKey: pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szKey,
        pszValue: pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.szValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE8B0
// Name: protected: void COP_Entity::LoadClassList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::LoadClassList(COP_Entity *this)
{
  char *m_pszData; // ebx
  CEditGameClass *EditObject; // esi
  GDclass *m_pClass; // eax
  int v4; // edi
  GDclass *v5; // eax
  char *v6; // eax
  int m_Size; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  int v9; // ebx
  GDclass *v10; // eax
  const char *m_szName; // esi
  int v12; // eax
  char *v13; // eax
  char *v14; // eax
  int i; // esi
  volatile signed __int32 *p_SetKeyValue; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+Ch] [ebp-30h] BYREF
  CEditGameClass *pEdit; // [esp+20h] [ebp-1Ch]
  int nCount; // [esp+24h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > suggestion; // [esp+28h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+2Ch] [ebp-10h] BYREF
  int v23; // [esp+38h] [ebp-4h]

  m_pszData = (char *)this;
  suggestion.m_pszData = (char *)this;
  EditObject = (CEditGameClass *)CObjectPage::GetEditObject(this);
  m_pClass = EditObject->m_pClass;
  v4 = -1;
  pEdit = EditObject;
  if ( m_pClass != nullptr )
  {
    if ( _V_stricmp(s1: "worldspawn", s2: EditObject->m_szClass) != 0 )
    {
      v5 = EditObject->m_pClass;
      v4 = v5 != nullptr && v5->m_bSolid;
    }
    else
    {
      v4 = 2;
    }
  }
  if ( *((_DWORD *)m_pszData + 553) != v4 )
  {
    memset(&suggestions, 0, sizeof(suggestions));
    v23 = 1;
    if ( v4 == 2 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &str,
        pszSrc: "worldspawn");
      LOBYTE(v23) = 2;
      CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
        this: &suggestions,
        elem: suggestions.m_Size,
        src: &str);
      LOBYTE(v23) = 1;
      v6 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
    }
    else
    {
      m_Size = pGD->m_Classes.m_Size;
      nCount = m_Size;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v23) = 5;
      v9 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          if ( v9 < pGD->m_Classes.m_Size )
            v10 = pGD->m_Classes.m_Memory.m_pMemory[v9];
          else
            v10 = nullptr;
          if ( !v10->m_bBase && (v4 == -1 || v4 == v10->m_bSolid) )
          {
            m_szName = v10->m_szName;
            v12 = v10 == (GDclass *)-19 ? 0 : strlen(v10->m_szName);
            ATL::CSimpleStringT<char,0>::SetString(this: &str, pszSrc: m_szName, nLength: v12);
            if ( _V_stricmp(s1: "worldspawn", s2: m_szName) != 0 )
              CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
                this: &suggestions,
                elem: suggestions.m_Size,
                src: &str);
          }
          ++v9;
        }
        while ( v9 < nCount );
      }
      LOBYTE(v23) = 1;
      v13 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
      m_pszData = suggestion.m_pszData;
    }
    *((_DWORD *)m_pszData + 553) = v4;
    CFilteredComboBox::SetSuggestions(this: (CFilteredComboBox *)(m_pszData + 796), &suggestions, flags: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &suggestion,
      pszSrc: pEdit->m_szClass);
    LOBYTE(v23) = 7;
    CFilteredComboBox::AddSuggestion(this: (CFilteredComboBox *)(m_pszData + 796), &suggestion);
    LOBYTE(v23) = 1;
    v14 = suggestion.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)suggestion.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v14 + 4))(a1: v14);
    v23 = 9;
    for ( i = suggestions.m_Size - 1; i >= 0; --i )
    {
      pEdit = (CEditGameClass *)&suggestions.m_Memory.m_pMemory[i];
      LOBYTE(v23) = 9;
      p_SetKeyValue = (volatile signed __int32 *)&pEdit->__vftable[-1].SetKeyValue;
      if ( _InterlockedDecrement(p_SetKeyValue + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)p_SetKeyValue + 4))(a1: p_SetKeyValue);
    }
    m_pMemory = suggestions.m_Memory.m_pMemory;
    suggestions.m_Size = 0;
    if ( suggestions.m_Memory.m_nGrowSize >= 0 )
    {
      if ( suggestions.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: suggestions.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        suggestions.m_Memory.m_pMemory = nullptr;
      }
      suggestions.m_Memory.m_nAllocationCount = 0;
    }
    suggestions.m_pElements = m_pMemory;
    v23 = -1;
    if ( suggestions.m_Memory.m_nGrowSize >= 0 && suggestions.m_Memory.m_pMemory != nullptr )
      free(pMem: suggestions.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEB70
// Name: protected: void COP_Entity::GetCurKey(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::GetCurKey(
        COP_Entity *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strKey)
{
  int v3; // eax
  int v4; // esi
  const char *ItemData; // eax
  ATL::CStringData *v6; // eax
  char *v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v8; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v3 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v3 != 0
    && (v4 = v3 - 1, SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v3 - 1, lParam: 2), v4 != -1) )
  {
    ItemData = (const char *)CListCtrl::GetItemData(this: &this->m_VarList, nItem: v4);
    v6 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                               this: &v8,
                               pszSrc: ItemData);
    v9 = 0;
    ATL::CSimpleStringT<char,0>::operator=(this: strKey, strSrc: v6);
    v9 = -1;
    v7 = v8.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)v8.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  }
  else
  {
    ATL::CSimpleStringT<char,0>::SetString(this: strKey, pszSrc: &var, nLength: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEC50
// Name: protected: void COP_Entity::CreateSmartControls(class GDinputvariable __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::CreateSmartControls(
        COP_Entity *this,
        GDinputvariable *pVar,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *pHelperType)
{
  const char *Value; // eax
  HWND__ *m_eType; // edi
  int v6; // eax
  HFONT__ *StockObject; // eax
  int v8; // ebx
  HFONT__ *v9; // ebx
  char *v10; // eax
  CRect ctrlrect; // [esp+8h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strValue; // [esp+18h] [ebp-18h] BYREF
  HFONT__ *hControlFont; // [esp+1Ch] [ebp-14h]
  bool bShowSmartAngles; // [esp+23h] [ebp-Dh] BYREF
  int v15; // [esp+2Ch] [ebp-4h]

  if ( pVar != nullptr )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: pVar->m_szName, piIndex: nullptr);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strValue,
      pszSrc: Value);
    v15 = 0;
    if ( this->m_SmartControls.m_Size <= 0
      || pVar != this->m_pLastSmartControlVar
      || _V_stricmp(s1: strValue.m_pszData, s2: this->m_LastSmartControlVarValue.m_pszData) != 0 )
    {
      this->m_bIgnoreKVChange = true;
      COP_Entity::DestroySmartControls(this);
      this->m_pLastSmartControlVar = pVar;
      ATL::CSimpleStringT<char,0>::operator=(
        this: &this->m_LastSmartControlVarValue,
        strSrc: (ATL::CStringData *)&strValue);
      COP_Entity::CalculateSmartControlRect(this, result: &ctrlrect);
      m_eType = (HWND__ *)pVar->m_eType;
      if ( m_eType == (HWND__ *)10 || m_eType == (HWND__ *)11 )
        v6 = 5;
      else
        v6 = 0;
      CWnd::ShowWindow(this: &this->m_cPickColor, nCmdShow: v6);
      StockObject = (HFONT__ *)GetStockObject(i: 17);
      hControlFont = StockObject;
      if ( StockObject == nullptr )
      {
        StockObject = (HFONT__ *)GetStockObject(i: 12);
        hControlFont = StockObject;
      }
      bShowSmartAngles = false;
      if ( m_eType == nullptr )
        COP_Entity::CreateSmartControls_Angle(this, pVar, &ctrlrect, hControlFont: StockObject, &bShowSmartAngles);
      v8 = bShowSmartAngles ? 5 : 0;
      CWnd::ShowWindow(this: &this->m_SmartAngle, nCmdShow: v8);
      CWnd::ShowWindow(this: &this->m_SmartAngleEdit, nCmdShow: v8);
      if ( m_eType == (HWND__ *)7 || m_eType == (HWND__ *)16 || m_eType == (HWND__ *)17 || m_eType == (HWND__ *)26 )
      {
        COP_Entity::CreateSmartControls_Choices(this, pVar, &ctrlrect, hControlFont);
      }
      else if ( m_eType == (HWND__ *)33 )
      {
        COP_Entity::CreateSmartControls_InstanceVariable(this, a2: v8, pVar, &ctrlrect, hControlFont);
      }
      else if ( m_eType == (HWND__ *)34 )
      {
        COP_Entity::CreateSmartControls_InstanceParm(this, a2: v8, pVar, &ctrlrect, hControlFont);
      }
      else
      {
        if ( m_eType == (HWND__ *)3 || m_eType == (HWND__ *)1 )
        {
          COP_Entity::CreateSmartControls_TargetName(this, pVar, &ctrlrect, hControlFont);
          v9 = hControlFont;
        }
        else
        {
          v9 = hControlFont;
          COP_Entity::CreateSmartControls_BasicEditControl(this, pVar, &ctrlrect, hControlFont, pHelperType);
        }
        if ( m_eType == (HWND__ *)12
          || m_eType == (HWND__ *)13
          || m_eType == (HWND__ *)14
          || m_eType == (HWND__ *)9
          || m_eType == (HWND__ *)19
          || m_eType == (HWND__ *)20
          || m_eType == (HWND__ *)28
          || m_eType == (HWND__ *)29
          || m_eType == (HWND__ *)30
          || m_eType == (HWND__ *)31 )
        {
          COP_Entity::CreateSmartControls_BrowseAndPlayButtons(this, pVar, (HMENU__ *)&ctrlrect, hControlFont: v9);
        }
        else if ( m_eType == (HWND__ *)1 || m_eType == (HWND__ *)2 || m_eType == (HWND__ *)3 || m_eType == (HWND__ *)27 )
        {
          COP_Entity::CreateSmartControls_MarkAndEyedropperButtons(
            this,
            a2: (int)v9,
            a3: m_eType,
            a4: (int)this,
            pVar,
            &ctrlrect,
            hControlFont: v9);
        }
        else if ( m_eType == (HWND__ *)21 || m_eType == (HWND__ *)22 )
        {
          COP_Entity::CreateSmartControls_PickButton(
            this,
            a2: (int)v9,
            a3: (int)m_eType,
            a4: (int)this,
            pVar,
            &ctrlrect,
            hControlFont: v9);
        }
      }
      CWnd::ShowWindow(this: this->m_pSmartControl, nCmdShow: 5);
      CWnd::SetWindowPos(
        this: this->m_pSmartControl,
        pWndInsertAfter: &this->m_VarList,
        x: 0,
        y: 0,
        cx: 0,
        cy: 0,
        nFlags: 0xBu);
      this->m_bIgnoreKVChange = false;
      COP_Entity::UpdateAnchors(this);
      v15 = -1;
      v10 = strValue.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)strValue.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v10 + 4))(a1: v10);
    }
    else
    {
      v15 = -1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEF30
// Name: protected: void COP_Entity::OnSelchangeKeyvalues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnSelchangeKeyvalues(COP_Entity *this)
{
  int v2; // eax
  WPARAM v3; // edi
  CEdit *p_m_cValue; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *ItemText; // eax
  char *v6; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  GDinputvariable *VariableAt; // eax
  GDinputvariable *v12; // edi
  const char *m_pszDescription; // eax
  char *m_pszData; // [esp-Ch] [ebp-3Ch]
  CUtlVector<char const *,CUtlMemory<char const *,int> > helperNames; // [esp+4h] [ebp-2Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+18h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+1Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > val; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+2Ch] [ebp-4h]

  if ( this->m_VarList.m_hWnd != nullptr )
  {
    if ( this->m_bSmartedit )
      COP_Entity::StopPicking(this);
    v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v2 == 0
      || (v3 = v2 - 1, SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2), v3 == -1) )
    {
      if ( this->m_bSmartedit )
        return;
      CWnd::SetWindowTextA(this: &this->m_cKey, lpszString: &var);
      p_m_cValue = &this->m_cValue;
      goto LABEL_23;
    }
    if ( this->m_bSmartedit )
    {
      VariableAt = COP_Entity::GetVariableAt(this, index: v3);
      v12 = VariableAt;
      if ( VariableAt == nullptr || this->m_pDisplayClass == nullptr )
      {
        COP_Entity::DestroySmartControls(this);
        p_m_cValue = &this->m_KeyValueHelpText;
LABEL_23:
        CWnd::SetWindowTextA(this: p_m_cValue, lpszString: &var);
        return;
      }
      memset(&helperNames, 0, sizeof(helperNames));
      v19 = 9;
      GDclass::GetHelperForGDVar(this: this->m_pDisplayClass, pVar: VariableAt, pszHelperName: &helperNames);
      m_pszDescription = v12->m_pszDescription;
      if ( m_pszDescription == nullptr )
        m_pszDescription = GDinputvariable::m_pszEmpty;
      CWnd::SetWindowTextA(this: &this->m_KeyValueHelpText, lpszString: m_pszDescription);
      COP_Entity::CreateSmartControls(this, pVar: v12, pHelperType: &helperNames);
      this->m_eEditType = v12->m_eType;
      v19 = -1;
      CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&helperNames);
    }
    else
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &str);
      v19 = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &val);
      LOBYTE(v19) = 1;
      ItemText = CListCtrl::GetItemText(this: &this->m_VarList, &result, nItem: v3, nSubItem: 0);
      LOBYTE(v19) = 2;
      ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: (ATL::CStringData *)ItemText);
      LOBYTE(v19) = 1;
      v6 = result.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
      v7 = CListCtrl::GetItemText(this: &this->m_VarList, &result, nItem: v3, nSubItem: 1);
      LOBYTE(v19) = 4;
      ATL::CSimpleStringT<char,0>::operator=(this: &val, strSrc: (ATL::CStringData *)v7);
      LOBYTE(v19) = 1;
      v8 = result.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
      m_pszData = str.m_pszData;
      this->m_bIgnoreKVChange = true;
      CWnd::SetWindowTextA(this: &this->m_cKey, lpszString: m_pszData);
      CWnd::SetWindowTextA(this: &this->m_cValue, lpszString: val.m_pszData);
      *(_WORD *)&this->m_bIgnoreKVChange = 0;
      LOBYTE(v19) = 0;
      v9 = val.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)val.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
      v19 = -1;
      v10 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v10 + 4))(a1: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF1D0
// Name: protected: void COP_Entity::OnRemovekeyvalue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnRemovekeyvalue(COP_Entity *this)
{
  int v2; // eax
  WPARAM v3; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  const char *ItemData; // eax
  ATL::CStringData *v6; // eax
  char *v7; // eax
  char *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+8h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strBuf; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+18h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
    if ( v3 != -1 )
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      strBuf.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      v11 = 1;
      ItemData = (const char *)CListCtrl::GetItemData(this: &this->m_VarList, nItem: v3);
      v6 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                                 this: &v9,
                                 pszSrc: ItemData);
      LOBYTE(v11) = 2;
      ATL::CSimpleStringT<char,0>::operator=(this: &strBuf, strSrc: v6);
      LOBYTE(v11) = 1;
      v7 = v9.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)v9.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
      WCKeyValuesT<WCKVBase_Dict>::RemoveKey(this: &this->m_kv, pszKey: strBuf.m_pszData);
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1008u, wParam: v3, lParam: 0);
      if ( v3 == SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) )
        COP_Entity::SetCurVarListSelection(this, iSel: v3 - 1);
      COP_Entity::ResortItems(this);
      COP_Entity::OnSelchangeKeyvalues(this);
      v11 = -1;
      v8 = strBuf.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)strBuf.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF330
// Name: protected: void COP_Entity::UpdateKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdateKeyValue(COP_Entity *this, const char *szKey, const char *szValue)
{
  const char *v3; // edi
  char *v5; // eax
  int m_pszData_low; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // eax
  char *v8; // eax
  char *v9; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > NewValue; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > key; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  v3 = szKey;
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kvAdded, pszKey: szKey, pszValue: "1");
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: szKey, pszValue: szValue);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &key,
    pszSrc: szKey);
  v13 = 0;
  NewValue.m_pszData = (char *)CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Find(
                                 this: &this->m_InstanceParmData,
                                 &key);
  v13 = -1;
  v5 = key.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)key.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  if ( NewValue.m_pszData != (char *)0xFFFF )
  {
    m_pszData_low = LOWORD(NewValue.m_pszData);
    v7 = ATL::operator+(
           a1: m_pszData_low * 24,
           a2: (int)this,
           &result,
           str1: &this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[m_pszData_low].m_Data.elem.m_VariableName,
           psz2: " ");
    v13 = 2;
    ATL::operator+(a1: m_pszData_low * 24, a2: (int)this, result: &NewValue, str1: v7, psz2: szValue);
    LOBYTE(v13) = 4;
    v8 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
    WCKeyValuesT<WCKVBase_Dict>::SetValue(
      this: &this->m_kvAdded,
      pszKey: this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[m_pszData_low].m_Data.elem.m_ParmKey.m_pszData,
      pszValue: "1");
    WCKeyValuesT<WCKVBase_Dict>::SetValue(
      this: &this->m_kv,
      pszKey: this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[m_pszData_low].m_Data.elem.m_ParmKey.m_pszData,
      pszValue: NewValue.m_pszData);
    COP_Entity::RefreshKVListValues(
      this,
      pOnlyThisVar: this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[m_pszData_low].m_Data.elem.m_ParmKey.m_pszData);
    v13 = -1;
    v9 = NewValue.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)NewValue.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
    v3 = szKey;
  }
  COP_Entity::RefreshKVListValues(this, pOnlyThisVar: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100DF4C0
// Name: protected: void COP_Entity::InternalOnChangeSmartcontrol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::InternalOnChangeSmartcontrol(COP_Entity *this, const char *szValue)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_LastSmartControlVarValue; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // edi
  __int16 v7; // ax
  GDinputvariable *v8; // edi
  const char *v9; // eax
  char *v10; // eax
  char szKey[80]; // [esp+4h] [ebp-78h] BYREF
  tagRECT rc; // [esp+54h] [ebp-28h] BYREF
  char *s1; // [esp+64h] [ebp-18h]
  int iSel; // [esp+68h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strValue; // [esp+6Ch] [ebp-10h] BYREF
  int v16; // [esp+78h] [ebp-4h]

  if ( !this->m_bIgnoreKVChange )
  {
    p_m_LastSmartControlVarValue = &this->m_LastSmartControlVarValue;
    v4 = szValue != nullptr ? strlen(szValue) : 0;
    ATL::CSimpleStringT<char,0>::SetString(this: p_m_LastSmartControlVarValue, pszSrc: szValue, nLength: v4);
    v5 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v5 != 0 )
    {
      v6 = v5 - 1;
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v5 - 1, lParam: 2);
      iSel = v6;
    }
    else
    {
      iSel = -1;
    }
    v7 = this->m_VarMap[iSel];
    if ( v7 != -1 )
    {
      v8 = v7 > -10
         ? GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v7)
         : this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v7)].m_Data.elem.m_ParmVariable;
      if ( v8 != nullptr )
      {
        s1 = v8->m_szName;
        V_strncpy(pDest: szKey, pSrc: v8->m_szName, maxLen: 80);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strValue,
          pszSrc: szValue);
        v16 = 0;
        if ( v8->m_eType == ivChoices )
        {
          v9 = GDinputvariable::ItemValueForString(this: v8, szString: szValue);
          if ( v9 != nullptr )
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(this: &strValue, pszSrc: v9);
        }
        COP_Entity::UpdateKeyValue(this, szKey, szValue: strValue.m_pszData);
        if ( this->m_bEnableControlUpdate && v8->m_eType == ivAngle )
        {
          if ( _V_stricmp(s1, s2: "angles") != 0 )
          {
            CAngleBox::SetDifferent(this: &this->m_SmartAngle, bDifferent: false, bRedraw: true);
            CAngleBox::SetAngles(this: &this->m_SmartAngle, szAngles: strValue.m_pszData, bRedraw: true);
          }
          else
          {
            CAngleBox::SetDifferent(this: &this->m_Angle, bDifferent: false, bRedraw: true);
            CAngleBox::SetAngles(this: &this->m_Angle, szAngles: strValue.m_pszData, bRedraw: true);
          }
        }
        if ( CListCtrl::GetItemRect(this: &this->m_VarList, nItem: iSel, lpRect: &rc, nCode: 0) != 0 )
          InvalidateRect(hWnd: this->m_VarList.m_hWnd, lpRect: &rc, bErase: false);
        v16 = -1;
        v10 = strValue.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)strValue.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v10 + 4))(a1: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF6C0
// Name: protected: void COP_Entity::OnChangeInstanceVariableControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnChangeInstanceVariableControl(COP_Entity *this)
{
  CEdit *m_pEditInstanceVariable; // ecx
  char *v3; // edi
  char v4; // al
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int v8; // eax
  int v9; // esi
  GDinputvariable *VariableAt; // eax
  char szValue[512]; // [esp+4h] [ebp-450h] BYREF
  char szVariable[512]; // [esp+204h] [ebp-250h] BYREF
  char szKey[80]; // [esp+404h] [ebp-50h] BYREF

  m_pEditInstanceVariable = this->m_pEditInstanceVariable;
  if ( m_pEditInstanceVariable != nullptr && this->m_pEditInstanceValue != nullptr )
  {
    CWnd::GetWindowTextA(this: m_pEditInstanceVariable, lpszString: szVariable, nMaxCount: 512);
    CWnd::GetWindowTextA(this: this->m_pEditInstanceValue, lpszString: szValue, nMaxCount: 512);
    if ( szValue[0] != 0 )
    {
      v3 = &szValue[511];
      do
        v4 = *++v3;
      while ( v4 != 0 );
      strcpy(v3, " ");
      v5 = strlen(szValue) + 1;
      v6 = &szValue[511];
      do
        v7 = *++v6;
      while ( v7 != 0 );
      qmemcpy(v6, szValue, v5);
    }
    v8 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v8 != 0 )
    {
      v9 = v8 - 1;
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v8 - 1, lParam: 2);
    }
    else
    {
      v9 = -1;
    }
    VariableAt = COP_Entity::GetVariableAt(this, index: v9);
    if ( VariableAt != nullptr )
    {
      V_strncpy(pDest: szKey, pSrc: VariableAt->m_szName, maxLen: 80);
      COP_Entity::UpdateKeyValue(this, szKey, szValue: szVariable);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF7E0
// Name: protected: void COP_Entity::OnChangeInstanceParmControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnChangeInstanceParmControl(COP_Entity *this)
{
  CEdit *m_pEditInstanceVariable; // ecx
  WPARAM v3; // eax
  char *v4; // edi
  char v5; // al
  unsigned int v6; // eax
  char *v7; // edi
  char v8; // cl
  char *v9; // edi
  char v10; // al
  unsigned int v11; // eax
  char *v12; // edi
  char v13; // cl
  int v14; // eax
  int v15; // esi
  GDinputvariable *VariableAt; // eax
  char szDefault[512]; // [esp+4h] [ebp-650h] BYREF
  char szValue[512]; // [esp+204h] [ebp-450h] BYREF
  char szVariable[512]; // [esp+404h] [ebp-250h] BYREF
  char szKey[80]; // [esp+604h] [ebp-50h] BYREF

  m_pEditInstanceVariable = this->m_pEditInstanceVariable;
  if ( m_pEditInstanceVariable != nullptr && this->m_pComboInstanceParmType != nullptr )
  {
    CWnd::GetWindowTextA(this: m_pEditInstanceVariable, lpszString: szVariable, nMaxCount: 512);
    v3 = SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 == -1 )
      CWnd::GetWindowTextA(this: this->m_pComboInstanceParmType, lpszString: szValue, nMaxCount: 512);
    else
      SendMessageA(hWnd: this->m_pComboInstanceParmType->m_hWnd, Msg: 0x148u, wParam: v3, lParam: (LPARAM)szValue);
    if ( szValue[0] != 0 )
    {
      v4 = &szValue[511];
      do
        v5 = *++v4;
      while ( v5 != 0 );
      strcpy(v4, " ");
      v6 = strlen(szValue) + 1;
      v7 = &szValue[511];
      do
        v8 = *++v7;
      while ( v8 != 0 );
      qmemcpy(v7, szValue, v6);
    }
    CWnd::GetWindowTextA(this: this->m_pEditInstanceDefault, lpszString: szDefault, nMaxCount: 512);
    if ( szDefault[0] != 0 )
    {
      v9 = &szValue[511];
      do
        v10 = *++v9;
      while ( v10 != 0 );
      strcpy(v9, " ");
      v11 = strlen(szDefault) + 1;
      v12 = &szValue[511];
      do
        v13 = *++v12;
      while ( v13 != 0 );
      qmemcpy(v12, szDefault, v11);
    }
    v14 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v14 != 0 )
    {
      v15 = v14 - 1;
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v14 - 1, lParam: 2);
    }
    else
    {
      v15 = -1;
    }
    VariableAt = COP_Entity::GetVariableAt(this, index: v15);
    if ( VariableAt != nullptr )
    {
      V_strncpy(pDest: szKey, pSrc: VariableAt->m_szName, maxLen: 80);
      COP_Entity::UpdateKeyValue(this, szKey, szValue: szVariable);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF9A0
// Name: protected: void COP_Entity::OnManageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnManageList(COP_Entity *this)
{
  IDlgListManageBrowse *v1; // eax
  CMainFrame *MainWnd; // eax
  CDlgListManage dlg; // [esp+0h] [ebp-180h] BYREF
  int v4; // [esp+17Ch] [ebp-4h]

  if ( this != nullptr )
    v1 = &this->IDlgListManageBrowse;
  else
    v1 = nullptr;
  CDlgListManage::CDlgListManage(this: &dlg, pParent: this, pBrowseImpl: v1, pObjectList: this->m_pObjectList);
  v4 = 0;
  if ( CDialog::DoModal(this: &dlg) == 1 )
  {
    CDlgListManage::SaveScriptChanges(this: &dlg);
    MainWnd = GetMainWnd();
    CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
  }
  v4 = -1;
  CDlgListManage::~CDlgListManage(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100DFA40
// Name: protected: virtual void COP_Entity::OnShowPropertySheet(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnShowPropertySheet(COP_Entity *this, int bShow, unsigned int nStatus)
{
  if ( bShow != 0 )
    COP_Entity::OnSelchangeKeyvalues(this);
  else
    COP_Entity::StopPicking(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DFA60
// Name: protected: long COP_Entity::OnChangeAngleBox(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Entity::OnChangeAngleBox(COP_Entity *this, unsigned int nID, int __formal)
{
  ATL::IAtlStringMgr *StringManager; // eax
  char v5; // bl
  char *m_pszData; // edi
  CEdit *m_pSmartControl; // ecx
  char szValue[512]; // [esp+8h] [ebp-210h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKey; // [esp+208h] [ebp-10h] BYREF
  int v11; // [esp+214h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strKey.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v11 = 1;
  COP_Entity::GetCurKey(this, &strKey);
  v5 = 0;
  if ( nID == 1105 || nID == 1107 )
  {
    CAngleBox::GetAngles(this: &this->m_Angle, szAngles: szValue);
    if ( _mbsicmp(s1: (const unsigned __int8 *)strKey.m_pszData, s2: "angles") == 0 )
      v5 = 1;
    ATL::CSimpleStringT<char,0>::SetString(this: &strKey, pszSrc: "angles", nLength: 6);
  }
  else
  {
    CAngleBox::GetAngles(this: &this->m_SmartAngle, szAngles: szValue);
    v5 = 1;
  }
  m_pszData = strKey.m_pszData;
  COP_Entity::UpdateKeyValue(this, szKey: strKey.m_pszData, szValue);
  if ( v5 != 0 )
  {
    if ( this->m_bSmartedit )
    {
      m_pSmartControl = (CEdit *)this->m_pSmartControl;
      if ( m_pSmartControl == nullptr )
        goto LABEL_15;
    }
    else
    {
      m_pSmartControl = &this->m_cValue;
    }
    this->m_bEnableControlUpdate = false;
    CWnd::SetWindowTextA(this: m_pSmartControl, lpszString: szValue);
    this->m_bEnableControlUpdate = true;
  }
LABEL_15:
  v11 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DFBB0
// Name: protected: virtual void COP_Entity::OnSmartControlTargetNameChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnSmartControlTargetNameChanged(COP_Entity *this, const char *pText)
{
  CFilteredComboBox *v3; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *CurrentItem; // eax
  char *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+4h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  v3 = (CFilteredComboBox *)__RTDynamicCast(
                              inptr: this->m_pSmartControl,
                              VfDelta: 0,
                              SrcType: &CWnd `RTTI Type Descriptor',
                              TargetType: &CFilteredComboBox `RTTI Type Descriptor',
                              isReference: 0);
  if ( v3 != nullptr )
  {
    CurrentItem = CFilteredComboBox::GetCurrentItem(this: v3, &result);
    v7 = 0;
    COP_Entity::InternalOnChangeSmartcontrol(this, szValue: CurrentItem->m_pszData);
    v7 = -1;
    v5 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFC40
// Name: protected: virtual void COP_Entity::GetItemColor(int,unsigned long __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::GetItemColor(
        COP_Entity *this,
        int iItem,
        unsigned int *pBackgroundColor,
        unsigned int *pTextColor)
{
  const char *ItemData; // eax
  unsigned int v6; // ecx
  EKeyState eState; // [esp+4h] [ebp-4h] BYREF

  ItemData = (const char *)CListCtrl::GetItemData(
                             this: (CListCtrl *)&this->m_SmartAngleEdit.m_xAccessibleServer,
                             nItem: iItem);
  COP_Entity::GetKeyState(
    this: (COP_Entity *)((char *)this - 188),
    pShortName: ItemData,
    pState: &eState,
    pMissingTarget: (bool *)&iItem + 3);
  switch ( eState )
  {
    case k_EKeyState_Modified:
      v6 = g_BgColor_Edited;
      break;
    case k_EKeyState_AddedManually:
      *pBackgroundColor = g_BgColor_Added;
      goto LABEL_9;
    case k_EKeyState_InstanceParm:
      *pBackgroundColor = g_BgColor_InstanceParm;
      goto LABEL_9;
    default:
      v6 = g_BgColor_Default;
      break;
  }
  *pBackgroundColor = v6;
LABEL_9:
  if ( HIBYTE(iItem) != 0 )
    *pTextColor = g_TextColor_MissingTarget;
  else
    *pTextColor = g_TextColor_Normal;
}

//------------------------------------------------------------------------------
// Address: 0x100DFCD0
// Name: public: void COP_Entity::OnUpdateSpawnFlags(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnUpdateSpawnFlags(COP_Entity *this, unsigned int preserveMask, unsigned int newValues)
{
  const char *Value; // eax
  char str[512]; // [esp+8h] [ebp-204h] BYREF
  unsigned int oldValue; // [esp+208h] [ebp-4h] BYREF

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: "spawnflags", piIndex: nullptr);
  if ( Value != nullptr )
  {
    oldValue = 0;
    sscanf(string: Value, format: "%lu", &oldValue);
    V_snprintf(pDest: str, maxLen: 512, pFormat: "%lu", preserveMask & oldValue | newValues & ~preserveMask);
    WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: "spawnflags", pszValue: str);
    COP_Entity::RefreshKVListValues(this, pOnlyThisVar: "spawnflags");
    COP_Entity::OnSelchangeKeyvalues(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFD70
// Name: public: static class CObject __near * COP_Entity::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Entity *__stdcall COP_Entity::CreateObject()
{
  COP_Entity *v0; // eax

  v0 = (COP_Entity *)operator new(nSize: 0xD44u);
  if ( v0 != nullptr )
    return COP_Entity::COP_Entity(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100DFDD0
// Name: int SortByItemEditedState(long,long,long)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall SortByItemEditedState(const char *iItem1, const char *iItem2, COP_Entity *lpParam)
{
  COP_Entity *v3; // esi
  EKeyState s1; // [esp+4h] [ebp-4h] BYREF

  v3 = lpParam;
  if ( lpParam->m_pDisplayClass == nullptr )
    return false;
  COP_Entity::GetKeyState(this: lpParam, pShortName: iItem1, pState: &s1, pMissingTarget: (bool *)&lpParam + 3);
  COP_Entity::GetKeyState(
    this: v3,
    pShortName: iItem2,
    pState: (EKeyState *)&iItem1,
    pMissingTarget: (bool *)&lpParam + 3);
  return (unsigned __int8)(s1 == k_EKeyState_AddedManually) < (unsigned __int8)(iItem1 == (const char *)2);
}

//------------------------------------------------------------------------------
// Address: 0x100DFE60
// Name: protected: virtual int COP_Entity::OnNotify(unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Entity::OnNotify(COP_Entity *this, unsigned int wParam, _DWORD *lParam, int *pResult)
{
  unsigned int v5; // eax

  if ( lParam[1] == 1024 && lParam[2] == -108 )
  {
    v5 = lParam[4];
    if ( v5 >= 2 )
      v5 = 2;
    this->m_iSortColumn = v5;
    COP_Entity::ResortItems(this);
  }
  return CPropertyPage::OnNotify(this, wParam, (int)lParam, pResult);
}

//------------------------------------------------------------------------------
// Address: 0x100DFEB0
// Name: public: virtual void COP_Entity::RememberState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::RememberState(COP_Entity *this)
{
  COP_Entity::GetCurKey(this, strKey: &this->m_strLastKey);
}

//------------------------------------------------------------------------------
// Address: 0x100DFEC0
// Name: protected: void COP_Entity::OnItemChangedKeyValues(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COP_Entity::OnItemChangedKeyValues(COP_Entity *this, tagNMHDR *pNMHDR, tagNMHDR *pResult)
{
  COP_Entity::OnSelchangeKeyvalues(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DFED0
// Name: protected: void COP_Entity::SetCurKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetCurKey(COP_Entity *this, const char *pszKey)
{
  LRESULT v3; // ebx
  int v4; // esi
  const char *ItemData; // eax
  char *v6; // eax
  char *v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v3 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    COP_Entity::SetCurVarListSelection(this, iSel: 0);
    COP_Entity::OnSelchangeKeyvalues(this);
  }
  else
  {
    while ( 1 )
    {
      ItemData = (const char *)CListCtrl::GetItemData(this: &this->m_VarList, nItem: v4);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &str,
        pszSrc: ItemData);
      v9 = 0;
      if ( _V_stricmp(s1: str.m_pszData, s2: pszKey) == 0 )
        break;
      v9 = -1;
      v6 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
      if ( ++v4 >= v3 )
        goto LABEL_6;
    }
    COP_Entity::SetCurVarListSelection(this, iSel: v4);
    if ( this->m_bSmartedit )
      COP_Entity::OnSelchangeKeyvalues(this);
    v9 = -1;
    v7 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFFE0
// Name: protected: void COP_Entity::OnChangeKeyorValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnChangeKeyorValue(COP_Entity *this)
{
  int v2; // eax
  int v3; // edi
  char szValue[512]; // [esp+4h] [ebp-254h] BYREF
  char szKey[80]; // [esp+204h] [ebp-54h] BYREF
  unsigned int value; // [esp+254h] [ebp-4h] BYREF

  if ( !this->m_bIgnoreKVChange )
  {
    v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v2 != 0 )
    {
      v3 = v2 - 1;
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
      if ( v3 != -1 )
      {
        CWnd::GetWindowTextA(this: &this->m_cKey, lpszString: szKey, nMaxCount: 80);
        CWnd::GetWindowTextA(this: &this->m_cValue, lpszString: szValue, nMaxCount: 512);
        COP_Entity::UpdateKeyValue(this, szKey, szValue);
        WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: szKey, pszValue: szValue);
        if ( _V_stricmp(s1: szKey, s2: "spawnflags") == 0 )
        {
          sscanf(string: szValue, format: "%lu", &value);
          COP_Flags::OnUpdateSpawnFlags(this: this->m_pFlagsPage, value);
        }
        if ( this->m_bEnableControlUpdate && _V_stricmp(s1: szKey, s2: "angles") == 0 )
        {
          CAngleBox::SetDifferent(this: &this->m_Angle, bDifferent: false, bRedraw: true);
          CAngleBox::SetAngles(this: &this->m_Angle, szAngles: szValue, bRedraw: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0110
// Name: protected: bool COP_Entity::BrowseModels(char __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COP_Entity::BrowseModels(COP_Entity *this, char *szModelName, int length, int *nSkin)
{
  CMainFrame *MainWnd; // eax
  CModelBrowser *ModelBrowser; // esi
  CMapDoc *v6; // edi
  int v7; // eax
  char pModelName[1024]; // [esp+Ch] [ebp-460h] BYREF
  EntityReportFilterParms_t filter; // [esp+40Ch] [ebp-60h] BYREF
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > usedModels; // [esp+444h] [ebp-28h] BYREF
  CWnd *pwndParent; // [esp+458h] [ebp-14h]
  bool bChanged; // [esp+45Fh] [ebp-Dh]
  int v14; // [esp+468h] [ebp-4h]

  pwndParent = this;
  bChanged = false;
  MainWnd = GetMainWnd();
  ModelBrowser = CMainFrame::GetModelBrowser(this: MainWnd);
  CModelBrowser::Show(this: ModelBrowser);
  memset(&usedModels, 0, sizeof(usedModels));
  v14 = 1;
  v6 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::GetUsedModels(this: CMapDoc::m_pMapDoc, &usedModels);
  CModelBrowser::SetUsedModelList(this: ModelBrowser, &usedModels);
  CModelBrowser::SetModelName(this: ModelBrowser, pModelName: szModelName);
  CModelBrowser::SetSkin(this: ModelBrowser, nSkin: *nSkin);
  v7 = ModelBrowser->DoModal(this: ModelBrowser);
  if ( v7 == 1 )
  {
    CModelBrowser::GetModelName(this: ModelBrowser, pModelName: szModelName, length);
    CModelBrowser::GetSkin(this: ModelBrowser, nSkin);
    bChanged = true;
  }
  else if ( v7 == 100 )
  {
    CModelBrowser::GetModelName(this: ModelBrowser, pModelName, length: 1024);
    CUtlString::CUtlString(this: &filter.m_filterKey);
    LOBYTE(v14) = 2;
    CUtlString::CUtlString(this: &filter.m_filterValue);
    LOBYTE(v14) = 3;
    CUtlString::CUtlString(this: &filter.m_filterClass);
    *(_DWORD *)&filter.m_bFilterByKeyvalue = 1;
    filter.m_nFilterByType = 0;
    LOBYTE(v14) = 5;
    CUtlString::Set(this: &filter.m_filterKey, pValue: "model");
    CUtlString::Set(this: &filter.m_filterValue, pValue: pModelName);
    CEntityReportDlg::ShowEntityReport(pDoc: v6, pwndParent, pParms: &filter);
    LOBYTE(v14) = 1;
    EntityReportFilterParms_t::~EntityReportFilterParms_t(this: &filter);
  }
  CModelBrowser::Hide(this: ModelBrowser);
  v14 = -1;
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &usedModels);
  return bChanged;
}

//------------------------------------------------------------------------------
// Address: 0x100E0290
// Name: protected: void COP_Entity::OnChangeSmartcontrol(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnChangeSmartcontrol(COP_Entity *this)
{
  CWnd *m_pSmartControl; // ecx
  char szValue[512]; // [esp+4h] [ebp-200h] BYREF

  m_pSmartControl = this->m_pSmartControl;
  if ( m_pSmartControl != nullptr )
  {
    CWnd::GetWindowTextA(this: m_pSmartControl, lpszString: szValue, nMaxCount: 512);
    COP_Entity::InternalOnChangeSmartcontrol(this, szValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E02D0
// Name: protected: void COP_Entity::OnPlaySound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPlaySound(COP_Entity *this)
{
  GDIV_TYPE m_eEditType; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // eax
  int v4; // eax
  char *v5; // eax
  char szCurrentSound[256]; // [esp+4h] [ebp-11Ch] BYREF
  char pPrefix[4]; // [esp+104h] [ebp-1Ch] BYREF
  SoundType_t type; // [esp+108h] [ebp-18h] BYREF
  int nIndex; // [esp+10Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > filename; // [esp+110h] [ebp-10h] BYREF
  int v11; // [esp+11Ch] [ebp-4h]

  if ( this->m_eEditType == ivScriptList )
    COP_Entity::OnManageList(this);
  m_eEditType = this->m_eEditType;
  if ( m_eEditType == ivSound || m_eEditType == ivScene )
  {
    CWnd::GetWindowTextA(this: this->m_pSmartControl, lpszString: szCurrentSound, nMaxCount: 256);
    if ( szCurrentSound[0] != 0 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &filename,
        pszSrc: szCurrentSound);
      v11 = 0;
      if ( this->m_eEditType == ivScene )
      {
        v3 = StripDirPrefix(
               pFilename: szCurrentSound,
               (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)pPrefix,
               pPrefixa: "scenes");
        LOBYTE(v11) = 1;
        ATL::CSimpleStringT<char,0>::operator=(this: &filename, strSrc: (ATL::CStringData *)v3);
        LOBYTE(v11) = 0;
        v4 = *(_DWORD *)pPrefix - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(*(_DWORD *)pPrefix - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 4))(a1: v4);
      }
      if ( CSoundSystem::FindSoundByName(this: &g_Sounds, pFilename: filename.m_pszData, &type, &nIndex) )
        CSoundSystem::Play(this: &g_Sounds, type, nIndex);
      v11 = -1;
      v5 = filename.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)filename.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0400
// Name: protected: void COP_Entity::OnBrowse(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COP_Entity::OnBrowse(COP_Entity *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  GDIV_TYPE m_eEditType; // eax
  const char *Value; // eax
  const char *v6; // eax
  void *v7; // edi
  char *v8; // esi
  const char *SelectedSound; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v10; // esi
  const char *v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v12; // eax
  int v13; // eax
  char v14; // al
  int v15; // eax
  unsigned int v16; // eax
  _BYTE *v17; // eax
  char szCurrentSkin[512]; // [esp+4h] [ebp-8D0h] BYREF
  CSoundBrowser soundDlg; // [esp+204h] [ebp-6D0h] BYREF
  char str[512]; // [esp+6B8h] [ebp-21Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+8B8h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > stripped; // [esp+8BCh] [ebp-18h] BYREF
  int numResultCharsNeeded; // [esp+8C0h] [ebp-14h] BYREF
  CArrayAutoPtr<char> szResultBuffer; // [esp+8C4h] [ebp-10h] BYREF
  int v27; // [esp+8D0h] [ebp-4h]

  m_eEditType = this->m_eEditType;
  switch ( m_eEditType )
  {
    case ivMaterial:
      COP_Entity::BrowseTextures(this, szFilter: (const char *)&byte_105EEA78, bSprite: 0);
      break;
    case ivStudioModel:
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_kv, pszKey: "skin", piIndex: nullptr);
      if ( Value != nullptr )
        szResultBuffer.m_p = (char *)V_atoi(str: Value);
      else
        szResultBuffer.m_p = nullptr;
      CWnd::GetWindowTextA(this: this->m_pSmartControl, lpszString: str, nMaxCount: 512);
      if ( COP_Entity::BrowseModels(this, szModelName: str, length: 512, nSkin: (int *)&szResultBuffer) )
      {
        CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: str);
        v6 = itoa(val: (int)szResultBuffer.m_p, buf: szCurrentSkin, radix: 10);
        COP_Entity::UpdateKeyValue(this, szKey: "skin", szValue: v6);
      }
      break;
    case ivParticleSystem:
      CWnd::GetWindowTextA(this: this->m_pSmartControl, lpszString: str, nMaxCount: 512);
      if ( COP_Entity::BrowseParticles(this, szParticleSysName: str, length: 512) != 0 )
        CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: str);
      break;
    case ivDecal:
      if ( g_pGameConfig->textureformat == tfVMT )
        COP_Entity::BrowseTextures(this, szFilter: "decals/", bSprite: 0);
      else
        COP_Entity::BrowseTextures(this, szFilter: "{", bSprite: 0);
      break;
    case ivSprite:
      COP_Entity::BrowseTextures(this, szFilter: "sprites/", bSprite: 1);
      break;
    case ivInstanceFile:
      COP_Entity::OnBrowseInstance(this);
      break;
    default:
      if ( g_FSDialogFactory != nullptr )
      {
        v7 = g_FSDialogFactory(a1: "FileSystemOpenDlg003", a2: nullptr);
        if ( v7 != nullptr )
        {
          (**(void (__thiscall ***)(void *, void *(__cdecl *)(const char *, int *), _DWORD))v7)(
            a1: v7,
            a2: g_Factory,
            a3: 0);
          switch ( this->m_eEditType )
          {
            case ivStudioModel:
              v8 = szInitialDir_2;
              (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: "*.jpg");
              (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: "*.mdl");
              (*(void (__thiscall **)(void *, char *, const char *))(*(_DWORD *)v7 + 12))(
                a1: v7,
                a2: szInitialDir_2,
                a3: "GAME");
              (*(void (__thiscall **)(void *, int))(*(_DWORD *)v7 + 16))(a1: v7, a2: 1);
              goto LABEL_37;
            case ivSound:
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              v27 = 0;
              CWnd::GetWindowTextA(
                this: this->m_pSmartControl,
                rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              CSoundBrowser::CSoundBrowser(this: &soundDlg, pCurrentSoundName: szResultBuffer.m_p, pParent: nullptr);
              LOBYTE(v27) = 1;
              if ( soundDlg.m_SoundType >= 2u )
                soundDlg.m_SoundType = 1;
              if ( CSoundBrowser::DoModal(this: &soundDlg) == 1 )
              {
                SelectedSound = CSoundBrowser::GetSelectedSound(this: &soundDlg);
                CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: SelectedSound);
              }
              LOBYTE(v27) = 0;
              CSoundBrowser::~CSoundBrowser(this: &soundDlg);
              v27 = -1;
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              goto Cleanup;
            case ivScene:
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              v27 = 2;
              CWnd::GetWindowTextA(
                this: this->m_pSmartControl,
                rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              StripDirPrefix(pFilename: szResultBuffer.m_p, pPrefix: &stripped, pPrefixa: "scenes");
              LOBYTE(v27) = 3;
              CSoundBrowser::CSoundBrowser(this: &soundDlg, pCurrentSoundName: stripped.m_pszData, pParent: nullptr);
              LOBYTE(v27) = 4;
              soundDlg.m_SoundType = 2;
              if ( CSoundBrowser::DoModal(this: &soundDlg) == 1 )
              {
                v10 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&numResultCharsNeeded,
                        pszSrc: "scenes\\");
                LOBYTE(v27) = 5;
                v11 = CSoundBrowser::GetSelectedSound(this: &soundDlg);
                v12 = ATL::operator+(a1: (int)v7, a2: (int)v10, &result, str1: v10, psz2: v11);
                LOBYTE(v27) = 6;
                CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: v12->m_pszData);
                LOBYTE(v27) = 5;
                ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &result);
                LOBYTE(v27) = 4;
                ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&numResultCharsNeeded);
              }
              LOBYTE(v27) = 3;
              CSoundBrowser::~CSoundBrowser(this: &soundDlg);
              LOBYTE(v27) = 2;
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &stripped);
              v27 = -1;
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szResultBuffer);
              goto Cleanup;
            case ivScript:
              v8 = szInitialDir_1;
              (*(void (__thiscall **)(void *, const char *, int, int))(*(_DWORD *)v7 + 8))(
                a1: v7,
                a2: "*.nut",
                a3,
                a4: a2);
              (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: "*.gm");
              goto LABEL_36;
            case ivScriptList:
              v8 = szInitialDir_0;
              (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: "*.nut");
              (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: "*.gm");
              (*(void (__thiscall **)(void *, char *, const char *))(*(_DWORD *)v7 + 12))(
                a1: v7,
                a2: szInitialDir_0,
                a3: "GAME");
              (*(void (__thiscall **)(void *, int))(*(_DWORD *)v7 + 32))(a1: v7, a2: 1);
              goto LABEL_37;
            default:
              v8 = szInitialDir;
              (*(void (__thiscall **)(void *, const char *, int, int))(*(_DWORD *)v7 + 8))(
                a1: v7,
                a2: "*.*",
                a3,
                a4: a2);
LABEL_36:
              (*(void (__thiscall **)(void *))(*(_DWORD *)v7 + 12))(a1: v7);
LABEL_37:
              if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
                || (v13 = _CommandLine(),
                    (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-NewDialogs") != 0) )
              {
                v14 = (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 24))(a1: v7);
              }
              else
              {
                v14 = (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 28))(a1: v7);
              }
              if ( v14 == 1 )
              {
                numResultCharsNeeded = (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 36))(a1: v7);
                szResultBuffer.m_p = (char *)operator new[](nSize: numResultCharsNeeded);
                v27 = 8;
                (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v7 + 20))(
                  a1: v7,
                  a2: szResultBuffer.m_p,
                  a3: numResultCharsNeeded);
                if ( v8 != nullptr )
                {
                  strchr(string: (unsigned __int8 *)szResultBuffer.m_p, chr: 0x20u);
                  v16 = v15 != 0 ? v15 - (unsigned int)szResultBuffer.m_p : 260;
                  _snprintf(string: v8, count: 0x104u, format: "%.*s", v16, szResultBuffer.m_p);
                  strrchr(string: (unsigned __int8 *)v8, chr: 0x5Cu);
                  if ( v17 != nullptr )
                    *v17 = 0;
                }
                if ( this->m_pSmartControl != nullptr )
                {
                  V_FixSlashes(pname: szResultBuffer.m_p, separator: 47);
                  if ( this->m_eEditType == ivScriptList )
                    CStringListTokenizer::TrimPrefixes(pszBuffer: szResultBuffer.m_p, pszPrefix: "scripts/vscripts/");
                  CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: szResultBuffer.m_p);
                }
                v27 = -1;
                CArrayAutoPtr<char>::~CArrayAutoPtr<char>(this: &szResultBuffer);
              }
Cleanup:
              (*(void (__thiscall **)(void *))(*(_DWORD *)v7 + 4))(a1: v7);
              break;
          }
        }
        else
        {
          V_snprintf(pDest: str, maxLen: 512, pFormat: "Can't create %s interface.", "FileSystemOpenDlg003");
          AfxMessageBox(lpszText: str, nType: 0, nIDHelp: 0);
        }
      }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0A10
// Name: private: void COP_Entity::SaveCustomColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SaveCustomColors(COP_Entity *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  int v3; // ecx
  int v4; // eax
  std::ios_base *v5; // ecx
  int v6; // eax
  char szFullPath[260]; // [esp+4h] [ebp-2C0h] BYREF
  char szRootDir[260]; // [esp+108h] [ebp-1BCh] BYREF
  std::ofstream file; // [esp+20Ch] [ebp-B8h] BYREF
  _BYTE *v10; // [esp+2B4h] [ebp-10h]
  int v11; // [esp+2C0h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szRootDir);
  V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "customcolors.dat", pStartingDir: szRootDir);
  std::ofstream::ofstream(this: &file, _Filename: szFullPath, _Mode: 34, _Prot: 64);
  v11 = 0;
  std::ostream::write(this: &file, _Str: (const char *)this->CustomColors, _Count: 64);
  if ( std::filebuf::close(this: (std::filebuf *)&file.gap0[4]) == nullptr )
  {
    v3 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
    v4 = *(_DWORD *)&file.gap0[v3 + 12];
    v5 = (std::ios_base *)&file.gap0[v3];
    v6 = v4 | 2;
    if ( v5[1].__vftable == nullptr )
      v6 |= 4u;
    std::ios_base::clear(this: v5, _State: v6, _Reraise: false);
  }
  v11 = -1;
  std::ofstream::~ofstream<char,std::char_traits<char>>(this: (std::ofstream *)&file.gap5C[4]);
  v10 = &file.gap5C[4];
  v11 = -1;
  *(_DWORD *)&file.gap5C[4] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)&file.gap5C[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100E0B20
// Name: protected: virtual struct AFX_MSGMAP const __near * CMyEdit::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMyEdit::GetMessageMap(CMyEdit *this)
{
  if ( (_S1_16 & 1) == 0 )
  {
    _S1_16 |= 1u;
    dword_107300CC = (int)CMyComboBox::OnChar;
    dword_107300D0 = 0;
    dword_107300D4 = 0;
    dword_107300D8 = 0;
    dword_107300DC = 0;
    dword_107300E0 = 0;
    dword_107300E4 = 0;
  }
  return (const AFX_MSGMAP *)&off_105EEA30;
}

//------------------------------------------------------------------------------
// Address: 0x100E0BA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CMyComboBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMyComboBox::GetMessageMap(CMyComboBox *this)
{
  if ( (_S2_5 & 1) == 0 )
  {
    _S2_5 |= 1u;
    dword_107300FC = (int)CMyComboBox::OnChar;
    dword_10730100 = 0;
    dword_10730104 = 0;
    dword_10730108 = 0;
    dword_1073010C = 0;
    dword_10730110 = 0;
    dword_10730114 = 0;
  }
  return (const AFX_MSGMAP *)&off_105EEA38;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C20
// Name: public: virtual void CPickAnglesTarget::OnNotifyPickAngles(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPickAnglesTarget::OnNotifyPickAngles(
        CPickAnglesTarget *this@<ecx>,
        char *a2@<ebx>,
        const Vector *vecPos)
{
  float v3; // esi
  CHistory *History; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ebx
  float v9; // eax
  int v10; // ecx
  float y; // edx
  CMapClass *v12; // eax
  CMapClass *v13; // esi
  CHistory *v14; // eax
  float v15; // xmm0_4
  COP_Entity *v16; // esi
  CWnd *m_pSmartControl; // ecx
  int v18; // eax
  int v19; // edx
  CMainFrame *MainWnd; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp+8h] [ebp-2BCh]
  CMapClass *v22; // [esp+10h] [ebp-2B4h]
  char szValue[32]; // [esp+20h] [ebp-2A4h] BYREF
  char string[32]; // [esp+220h] [ebp-A4h] BYREF
  char szAngles[80]; // [esp+240h] [ebp-84h] BYREF
  char szPitch[20]; // [esp+290h] [ebp-34h] BYREF
  Vector vecForward; // [esp+2A4h] [ebp-20h] BYREF
  Vector vecOrigin; // [esp+2B0h] [ebp-14h]
  QAngle angFace; // [esp+2BCh] [ebp-8h]

  v3 = *(float *)&this;
  LODWORD(vecForward.y) = this;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    List = CSelection::GetList(this: CMapDoc::m_pMapDoc->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Point At", bFromOpposite: 0);
    v5 = *(_DWORD *)(LODWORD(v3) + 4);
    v6 = *(_DWORD *)(v5 + 172);
    v7 = v5 + 172;
    v8 = 0;
    if ( *(int *)(v6 + 12) > 0 )
    {
      do
      {
        v9 = *(float *)(*(_DWORD *)(**(_DWORD **)v7 + 4 * (v8 >> (*(int *)(*(_DWORD *)v7 + 8) >> 27)))
                      + 12 * (v8 & ((32 * *(_DWORD *)(*(_DWORD *)v7 + 8)) >> 5))
                      + 8);
        if ( v9 != 0.0 )
        {
          vecOrigin.y = v9;
          vecForward.z = *(float *)(LODWORD(v9) + 32);
          v10 = *(_DWORD *)(LODWORD(v9) + 32);
          if ( v10 != 0 )
            *(_DWORD *)(v10 + 4) = &vecForward.z;
          vecOrigin.x = 0.0;
          *(_DWORD *)(LODWORD(v9) + 32) = &vecForward.z;
        }
        y = vecOrigin.y;
        angFace.y = NAN;
        if ( LODWORD(vecOrigin.y) != 0 )
        {
          if ( LODWORD(vecOrigin.x) != 0 )
          {
            *(_DWORD *)LODWORD(vecOrigin.x) = LODWORD(vecForward.z);
            if ( LODWORD(vecForward.z) != 0 )
              *(float *)(LODWORD(vecForward.z) + 4) = vecOrigin.x;
          }
          else if ( *(Vector **)(LODWORD(vecOrigin.y) + 32) == (Vector *)&vecForward.z )
          {
            *(float *)(LODWORD(vecOrigin.y) + 32) = vecForward.z;
            if ( LODWORD(vecForward.z) != 0 )
              *(_DWORD *)(LODWORD(vecForward.z) + 4) = 0;
          }
          vecOrigin.x = 0.0;
          vecForward.z = 0.0;
          vecOrigin.y = 0.0;
        }
        v12 = (CMapClass *)__RTDynamicCast(
                             inptr: (void *)LODWORD(y),
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CMapEntity `RTTI Type Descriptor',
                             isReference: 0);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v22 = v12;
          v14 = GetHistory();
          CHistory::Keep(this: v14, pObject: v22);
          ((void (__thiscall *)(CMapClass *, char *, char *))v13->GetOrigin)(a1: v13, a2: szPitch, a3: a2);
          *(float *)&szAngles[68] = vecPos->x - *(float *)szPitch;
          *(float *)&szAngles[72] = vecPos->y - *(float *)&szPitch[4];
          *(float *)&szAngles[76] = vecPos->z - *(float *)&szPitch[8];
          VectorAngles(forward: (const Vector *)&szAngles[68], angles: (QAngle *)&szPitch[12]);
          if ( v13 == (CMapClass *)-252 || V_strncasecmp(s1: (const char *)&v13[1].___u2, s2: "light_", n: 6) != 0 )
          {
            v15 = *(float *)&szPitch[12];
          }
          else
          {
            v15 = *(float *)&szPitch[12] * -1.0;
            *(float *)&szPitch[12] = *(float *)&szPitch[12] * -1.0;
          }
          sprintf(string, format: "%.0f %.0f %.0f", v15, *(float *)&szPitch[16], vecForward.x);
          a2 = string;
          ((void (__thiscall *)(CMapClass *, const char *))v13[1].IsSelected)(a1: &v13[1], a2: "angles");
          if ( v13 != (CMapClass *)-252 && V_strncasecmp(s1: (const char *)&v13[1].___u2, s2: "light_", n: 6) == 0 )
          {
            sprintf(string: &szAngles[48], format: "%.0f", *(float *)&szPitch[12]);
            ((void (__thiscall *)(CMapClass *, const char *, char *))v13[1].IsSelected)(
              a1: &v13[1],
              a2: "pitch",
              a3: &szAngles[48]);
          }
          v16 = *(COP_Entity **)(LODWORD(vecForward.y) + 4);
          m_pSmartControl = v16->m_pSmartControl;
          if ( m_pSmartControl != nullptr )
          {
            CWnd::GetWindowTextA(this: m_pSmartControl, lpszString: szValue, nMaxCount: 512);
            COP_Entity::InternalOnChangeSmartcontrol(this: v16, szValue);
          }
        }
        v18 = *(_DWORD *)(LODWORD(vecForward.y) + 4);
        v19 = *(_DWORD *)(v18 + 172);
        v7 = v18 + 172;
        ++v8;
      }
      while ( v8 < *(_DWORD *)(v19 + 12) );
      v3 = vecForward.y;
    }
    COP_Entity::StopPicking(this: *(COP_Entity **)(LODWORD(v3) + 4));
    MainWnd = GetMainWnd();
    CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0F00
// Name: private: void COP_Entity::SetSmartControlText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetSmartControlText(COP_Entity *this, const char *pszText)
{
  CFilteredComboBox *v3; // eax
  CWnd *m_pSmartControl; // ecx
  char szString[512]; // [esp+4h] [ebp-200h] BYREF

  v3 = (CFilteredComboBox *)__RTDynamicCast(
                              inptr: this->m_pSmartControl,
                              VfDelta: 0,
                              SrcType: &CWnd `RTTI Type Descriptor',
                              TargetType: &CTargetNameComboBox `RTTI Type Descriptor',
                              isReference: 0);
  if ( v3 != nullptr )
    CFilteredComboBox::SelectItem(this: v3, pStr: pszText);
  else
    CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: pszText);
  m_pSmartControl = this->m_pSmartControl;
  if ( m_pSmartControl != nullptr )
  {
    CWnd::GetWindowTextA(this: m_pSmartControl, lpszString: szString, nMaxCount: 512);
    COP_Entity::InternalOnChangeSmartcontrol(this, szValue: szString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0F80
// Name: private: void COP_Entity::LoadCustomColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::LoadCustomColors(COP_Entity *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  int v3; // ecx
  int v4; // eax
  std::ios_base *v5; // ecx
  int v6; // eax
  char szFullPath[260]; // [esp+4h] [ebp-2C8h] BYREF
  char szRootDir[260]; // [esp+108h] [ebp-1C4h] BYREF
  std::ifstream file; // [esp+20Ch] [ebp-C0h] BYREF
  _BYTE *v10; // [esp+2BCh] [ebp-10h]
  int v11; // [esp+2C8h] [ebp-4h]

  if ( !this->m_bCustomColorsLoaded )
  {
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szRootDir);
    V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "customcolors.dat", pStartingDir: szRootDir);
    std::ifstream::ifstream(this: &file, _Filename: szFullPath, _Mode: 33, _Prot: 64);
    v11 = 0;
    if ( *(_DWORD *)&file._Filebuffer[12] != 0 )
    {
      std::istream::read(this: &file, _Str: (char *)this->CustomColors, _Count: 64);
      if ( std::filebuf::close(this: (std::filebuf *)file.gap10) == nullptr )
      {
        v3 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
        v4 = *(_DWORD *)((char *)&file._Chcount + v3 + 4);
        v5 = (std::ios_base *)&file.gap0[v3];
        v6 = v4 | 2;
        if ( v5[1].__vftable == nullptr )
          v6 |= 4u;
        std::ios_base::clear(this: v5, _State: v6, _Reraise: false);
      }
    }
    this->m_bCustomColorsLoaded = true;
    v11 = -1;
    std::ifstream::~ifstream<char,std::char_traits<char>>(this: (std::ifstream *)file.gap68);
    v10 = file.gap68;
    v11 = -1;
    *(_DWORD *)file.gap68 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap68);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E10D0
// Name: protected: void COP_Entity::OnPickColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPickColor(COP_Entity *this)
{
  int v2; // eax
  int v3; // esi
  __int16 v4; // ax
  GDinputvariable *v5; // edi
  CWnd *m_pSmartControl; // ecx
  const char *v7; // eax
  int i; // esi
  CColorDialog v9; // [esp+8h] [ebp-158h] BYREF
  char string[24]; // [esp+C4h] [ebp-9Ch] BYREF
  char szTmp[128]; // [esp+DCh] [ebp-84h]
  unsigned int brightness; // [esp+15Ch] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
  }
  else
  {
    v3 = -1;
  }
  v4 = this->m_VarMap[v3];
  if ( v4 != -1 )
  {
    v5 = v4 > -10
       ? GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v4)
       : this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v4)].m_Data.elem.m_ParmVariable;
    if ( v5 != nullptr )
    {
      if ( !this->m_bCustomColorsLoaded )
        COP_Entity::LoadCustomColors(this);
      m_pSmartControl = this->m_pSmartControl;
      szTmp[117] = -1;
      szTmp[119] = -1;
      szTmp[115] = -1;
      *(_DWORD *)&szTmp[104] = -1;
      CWnd::GetWindowTextA(this: m_pSmartControl, lpszString: string, nMaxCount: 128);
      v7 = strtok(string, control: " ");
      for ( i = 0; v7 != nullptr; v7 = strtok(string: nullptr, control: " ") )
      {
        if ( *v7 != 0 )
        {
          if ( i == 3 )
          {
            *(_DWORD *)&szTmp[104] = atol(nptr: v7);
          }
          else if ( v5->m_eType == ivColor255 )
          {
            if ( i != 0 )
            {
              if ( i == 1 )
              {
                szTmp[119] = atol(nptr: v7);
              }
              else if ( i == 2 )
              {
                szTmp[115] = atol(nptr: v7);
              }
            }
            else
            {
              szTmp[117] = atol(nptr: v7);
            }
          }
          else if ( i != 0 )
          {
            if ( i == 1 )
            {
              *(_DWORD *)&szTmp[108] = (int)(atof(nptr: v7) * 255.0);
              szTmp[119] = szTmp[108];
            }
            else if ( i == 2 )
            {
              *(_DWORD *)&szTmp[108] = (int)(atof(nptr: v7) * 255.0);
              szTmp[115] = szTmp[108];
            }
          }
          else
          {
            *(_DWORD *)&szTmp[108] = (int)(atof(nptr: v7) * 255.0);
            szTmp[117] = szTmp[108];
          }
          ++i;
        }
      }
      CColorDialog::CColorDialog(
        this: (CColorDialog *)&v9.m_dwRef,
        clrInit: (unsigned __int8)szTmp[117] | (((unsigned __int8)szTmp[119] | ((unsigned __int8)szTmp[115] << 8)) << 8),
        dwFlags: 2u,
        pParentWnd: nullptr);
      brightness = 0;
      v9.m_cc.Flags = (unsigned int)this->CustomColors;
      if ( CColorDialog::DoModal(this: (CColorDialog *)&v9.m_dwRef) == 1 )
      {
        COP_Entity::SaveCustomColors(this);
        if ( v5->m_eType == ivColor255 )
          sprintf(
            string,
            format: "%d %d %d",
            LOBYTE(v9.m_cc.lpCustColors),
            BYTE1(v9.m_cc.lpCustColors),
            BYTE2(v9.m_cc.lpCustColors));
        else
          sprintf(
            string,
            format: "%.3f %.3f %.3f",
            (float)((float)LOBYTE(v9.m_cc.lpCustColors) * 0.0039215689),
            (float)((float)BYTE1(v9.m_cc.lpCustColors) * 0.0039215689),
            (float)((float)BYTE2(v9.m_cc.lpCustColors) * 0.0039215689));
        if ( *(_DWORD *)&szTmp[104] != -1 )
          sprintf(string: &string[strlen(string)], format: " %d", *(_DWORD *)&szTmp[104]);
        CWnd::SetWindowTextA(this: this->m_pSmartControl, lpszString: string);
        COP_Entity::RefreshKVListValues(this, pOnlyThisVar: nullptr);
        v9.m_dwRef = (int)&CCommonDialog::`vftable';
        brightness = -1;
      }
      else
      {
        v9.m_dwRef = (int)&CCommonDialog::`vftable';
        brightness = -1;
      }
      CDialog::~CDialog(this: (CDialog *)&v9.m_dwRef);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1470
// Name: protected: void COP_Entity::OnCameraDistance(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall COP_Entity::OnCameraDistance(COP_Entity *this@<ecx>, int a2@<ebp>)
{
  CMapDoc *v2; // esi
  CMapView3D *First3DView; // eax
  int v5; // eax
  int v6; // edi
  GDinputvariable *VariableAt; // edi
  CUtlReferenceVector<CMapClass> *List; // eax
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  int v11; // ecx
  __int128 v12; // xmm1
  int v13; // eax
  unsigned __int16 v14; // di
  int v15; // ecx
  int v16; // edi
  _DWORD *v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  int v21; // eax
  CHistory *History; // eax
  CHistory *v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // ecx
  void *v27; // edi
  void *v28; // esi
  __int128 v29; // xmm1
  __int128 v30; // xmm0
  const CUtlReferenceVector<CMapClass> *v31; // [esp-20h] [ebp-198h]
  char v32[12]; // [esp-Ch] [ebp-184h] BYREF
  char buf[255]; // [esp+0h] [ebp-178h] BYREF
  CUtlReferenceVector<CMapClass> objectList; // [esp+100h] [ebp-78h] BYREF
  float v35; // [esp+114h] [ebp-64h]
  Vector cameraPos; // [esp+118h] [ebp-60h] BYREF
  _BYTE objectPos[24]; // [esp+124h] [ebp-54h] OVERLAPPED BYREF
  _QWORD v38[2]; // [esp+13Ch] [ebp-3Ch] BYREF
  int i; // [esp+158h] [ebp-20h]
  int *v40; // [esp+15Ch] [ebp-1Ch]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+160h] [ebp-18h]
  int pos; // [esp+164h] [ebp-14h]
  int v43; // [esp+168h] [ebp-10h]
  int v44; // [esp+16Ch] [ebp-Ch]
  void *v45; // [esp+170h] [ebp-8h]
  int v46; // [esp+174h] [ebp-4h] BYREF
  void *retaddr; // [esp+178h] [ebp+0h]

  v44 = a2;
  v45 = retaddr;
  v43 = -1;
  pos = (int)&_ehhandler__OnCameraDistance_COP_Entity__IAEXXZ;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v40 = &v46;
  v2 = CMapDoc::m_pMapDoc;
  *(_DWORD *)&objectPos[4] = this;
  *(_DWORD *)objectPos = CMapDoc::m_pMapDoc;
  First3DView = CMapDoc::GetFirst3DView(this: CMapDoc::m_pMapDoc);
  if ( First3DView != nullptr )
  {
    CCamera::GetViewPoint(this: First3DView->m_pCamera, ViewPoint: (Vector *)&objectList.m_Size);
    if ( v2 != nullptr )
    {
      v5 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
      if ( v5 != 0 )
      {
        v6 = v5 - 1;
        SendMessageA(hWnd: *(HWND *)(*(_DWORD *)&objectPos[4] + 592), Msg: 0x100Cu, wParam: v5 - 1, lParam: 2);
        if ( v6 != -1 )
        {
          VariableAt = COP_Entity::GetVariableAt(this: *(COP_Entity **)&objectPos[4], index: v6);
          if ( VariableAt != nullptr )
          {
            List = (CUtlReferenceVector<CMapClass> *)CSelection::GetList(this: *(CSelection **)(*(_DWORD *)objectPos
                                                                                              + 440));
            if ( List->m_Size == 1 )
            {
              m_pObject = CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Element(
                            this: List,
                            i: 0)->m_pObject;
              if ( m_pObject != nullptr )
              {
                HIDWORD(v38[1]) = m_pObject;
                HIDWORD(v38[0]) = m_pObject->m_References.m_pHead;
                m_pHead = m_pObject->m_References.m_pHead;
                if ( m_pHead != nullptr )
                  m_pHead->m_pPrev = (CUtlReference<CMapClass> *)((char *)v38 + 4);
                LODWORD(v38[1]) = 0;
                m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)((char *)v38 + 4);
              }
              v11 = HIDWORD(v38[1]);
              v43 = -1;
              if ( HIDWORD(v38[1]) != 0 )
              {
                if ( LODWORD(v38[1]) != 0 )
                {
                  *(_DWORD *)LODWORD(v38[1]) = HIDWORD(v38[0]);
                  if ( HIDWORD(v38[0]) != 0 )
                    *(_DWORD *)(HIDWORD(v38[0]) + 4) = v38[1];
                }
                else if ( *(_QWORD **)(HIDWORD(v38[1]) + 32) == (_QWORD *)((char *)v38 + 4) )
                {
                  *(_DWORD *)(HIDWORD(v38[1]) + 32) = HIDWORD(v38[0]);
                  if ( HIDWORD(v38[0]) != 0 )
                    *(_DWORD *)(HIDWORD(v38[0]) + 4) = 0;
                }
                v38[1] = 0;
                HIDWORD(v38[0]) = 0;
              }
              (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v11 + 80))(a1: v11, a2: &cameraPos);
              v12 = 0;
              *(float *)&v12 = fsqrt(
                                 (float)((float)((float)(*(float *)&objectList.m_Size - cameraPos.x)
                                               * (float)(*(float *)&objectList.m_Size - cameraPos.x))
                                       + (float)((float)(*(float *)&objectList.m_pElements - cameraPos.y)
                                               * (float)(*(float *)&objectList.m_pElements - cameraPos.y)))
                               + (float)((float)(v35 - cameraPos.z) * (float)(v35 - cameraPos.z)));
              *(_OWORD *)&objectPos[8] = v12;
              itoa(val: (int)*(float *)&v12, buf: v32, radix: 10);
              CWnd::SetWindowTextA(this: *(CWnd **)(*(_DWORD *)&objectPos[4] + 2104), lpszString: v32);
            }
            else
            {
              *((_DWORD *)&objectList.m_Memory + 2) = VariableAt->m_szName;
              v13 = WCKVBase_Dict::FindByKeyName(
                      this: (WCKVBase_Dict *)(*(_DWORD *)&objectPos[4] + 2148),
                      pKeyName: VariableAt->m_szName);
              v14 = v13;
              if ( v13 != 0xFFFF )
              {
                CWnd::SetWindowTextA(
                  this: *(CWnd **)(*(_DWORD *)&objectPos[4] + 2104),
                  lpszString: (const char *)CObjectPage::VALUE_DIFFERENT_STRING);
                v15 = v14;
                v16 = *(_DWORD *)&objectPos[4];
                V_strncpy(
                  pDest: (char *)(604 * v15 + *(_DWORD *)(*(_DWORD *)&objectPos[4] + 2152) + 92),
                  pSrc: (const char *)CObjectPage::VALUE_DIFFERENT_STRING,
                  maxLen: 512);
                CUtlReferenceVector<CMapClass>::CUtlReferenceVector<CMapClass>(this: (CUtlReferenceVector<CMapClass> *)&buf[244]);
                v43 = 1;
                v17 = *(_DWORD **)(v16 + 172);
                for ( i = 0; i < v17[3]; v17 = *(_DWORD **)(*(_DWORD *)&objectPos[4] + 172) )
                {
                  v18 = *(_DWORD *)(*(_DWORD *)(*v17 + 4 * (i >> ((int)v17[2] >> 27)))
                                  + 12 * (i & ((32 * v17[2]) >> 5))
                                  + 8);
                  if ( v18 != 0 )
                  {
                    *(_DWORD *)&objectPos[20] = *(_DWORD *)(*(_DWORD *)(*v17 + 4 * (i >> ((int)v17[2] >> 27)))
                                                          + 12 * (i & ((32 * v17[2]) >> 5))
                                                          + 8);
                    *(_DWORD *)&objectPos[12] = *(_DWORD *)(v18 + 32);
                    v19 = *(_DWORD *)(v18 + 32);
                    if ( v19 != 0 )
                      *(_DWORD *)(v19 + 4) = &objectPos[12];
                    *(_DWORD *)&objectPos[16] = 0;
                    *(_DWORD *)(v18 + 32) = &objectPos[12];
                  }
                  v20 = *(_DWORD *)&objectPos[20];
                  LOBYTE(v43) = 1;
                  if ( *(_DWORD *)&objectPos[20] != 0 )
                  {
                    if ( *(_DWORD *)&objectPos[16] != 0 )
                    {
                      **(_DWORD **)&objectPos[16] = *(_DWORD *)&objectPos[12];
                      if ( *(_DWORD *)&objectPos[12] != 0 )
                        *(_DWORD *)(*(_DWORD *)&objectPos[12] + 4) = *(_DWORD *)&objectPos[16];
                    }
                    else if ( *(_BYTE **)(*(_DWORD *)&objectPos[20] + 32) == &objectPos[12] )
                    {
                      *(_DWORD *)(*(_DWORD *)&objectPos[20] + 32) = *(_DWORD *)&objectPos[12];
                      if ( *(_DWORD *)&objectPos[12] != 0 )
                        *(_DWORD *)(*(_DWORD *)&objectPos[12] + 4) = 0;
                    }
                    memset(&objectPos[12], 0, 12);
                  }
                  if ( v20 != 0
                    && !IsWorldObject(pObject: (CMapAtom *)v20)
                    && __RTDynamicCast(
                         inptr: (void *)v20,
                         VfDelta: 0,
                         SrcType: &CMapClass `RTTI Type Descriptor',
                         TargetType: &CEditGameClass `RTTI Type Descriptor',
                         isReference: 0) != nullptr )
                  {
                    v21 = *(_DWORD *)(v20 + 32);
                    LODWORD(v38[1]) = 0;
                    HIDWORD(v38[1]) = v20;
                    HIDWORD(v38[0]) = v21;
                    if ( v21 != 0 )
                      *(_DWORD *)(v21 + 4) = (char *)v38 + 4;
                    LODWORD(v38[1]) = 0;
                    *(_DWORD *)(v20 + 32) = (char *)v38 + 4;
                    LOBYTE(v43) = 3;
                    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
                      this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&buf[244],
                      elem: (int)objectList.m_Memory.m_pMemory,
                      src: (const CUtlReference<CMapClass> *)((char *)v38 + 4));
                    LOBYTE(v43) = 1;
                    if ( HIDWORD(v38[1]) != 0 )
                    {
                      if ( LODWORD(v38[1]) != 0 )
                      {
                        *(_DWORD *)LODWORD(v38[1]) = HIDWORD(v38[0]);
                        if ( HIDWORD(v38[0]) != 0 )
                          *(_DWORD *)(HIDWORD(v38[0]) + 4) = v38[1];
                      }
                      else if ( *(_QWORD **)(HIDWORD(v38[1]) + 32) == (_QWORD *)((char *)v38 + 4) )
                      {
                        *(_DWORD *)(HIDWORD(v38[1]) + 32) = HIDWORD(v38[0]);
                        if ( HIDWORD(v38[0]) != 0 )
                          *(_DWORD *)(HIDWORD(v38[0]) + 4) = 0;
                      }
                      v38[1] = 0;
                      HIDWORD(v38[0]) = 0;
                    }
                  }
                  ++i;
                }
                if ( (int)objectList.m_Memory.m_pMemory > 0 )
                {
                  v31 = CSelection::GetList(this: *(CSelection **)(*(_DWORD *)objectPos + 440));
                  History = GetHistory();
                  CHistory::MarkUndoPosition(
                    this: History,
                    pSelection: v31,
                    pszName: "Change Properties",
                    bFromOpposite: 0);
                  v23 = GetHistory();
                  CHistory::Keep(this: v23, pList: (const CUtlReferenceVector<CMapClass> *)&buf[244]);
                  v24 = 0;
                  i = 0;
                  if ( (int)objectList.m_Memory.m_pMemory > 0 )
                  {
                    while ( 1 )
                    {
                      v25 = *(_DWORD *)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)&objectPos[4] + 172)
                                                  + 4
                                                  * (v24 >> ((unsigned __int64)*(int *)(*(_DWORD *)(*(_DWORD *)&objectPos[4]
                                                                                                  + 172)
                                                                                      + 8) >> 27)))
                                      + 12
                                      * (v24 & ((32 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&objectPos[4] + 172) + 8)) >> 5))
                                      + 8);
                      if ( v25 != 0 )
                      {
                        *(_DWORD *)&objectPos[20] = *(_DWORD *)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)&objectPos[4] + 172)
                                                                          + 4
                                                                          * (v24 >> ((unsigned __int64)*(int *)(*(_DWORD *)(*(_DWORD *)&objectPos[4] + 172) + 8) >> 27)))
                                                              + 12
                                                              * (v24
                                                               & ((32
                                                                 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&objectPos[4] + 172)
                                                                             + 8)) >> 5))
                                                              + 8);
                        *(_DWORD *)&objectPos[12] = *(_DWORD *)(v25 + 32);
                        v26 = *(_DWORD *)(v25 + 32);
                        if ( v26 != 0 )
                          *(_DWORD *)(v26 + 4) = &objectPos[12];
                        *(_DWORD *)&objectPos[16] = 0;
                        *(_DWORD *)(v25 + 32) = &objectPos[12];
                      }
                      v27 = *(void **)&objectPos[20];
                      LOBYTE(v43) = 1;
                      if ( *(_DWORD *)&objectPos[20] != 0 )
                      {
                        if ( *(_DWORD *)&objectPos[16] != 0 )
                        {
                          **(_DWORD **)&objectPos[16] = *(_DWORD *)&objectPos[12];
                          if ( *(_DWORD *)&objectPos[12] != 0 )
                            *(_DWORD *)(*(_DWORD *)&objectPos[12] + 4) = *(_DWORD *)&objectPos[16];
                        }
                        else if ( *(_BYTE **)(*(_DWORD *)&objectPos[20] + 32) == &objectPos[12] )
                        {
                          *(_DWORD *)(*(_DWORD *)&objectPos[20] + 32) = *(_DWORD *)&objectPos[12];
                          if ( *(_DWORD *)&objectPos[12] != 0 )
                            *(_DWORD *)(*(_DWORD *)&objectPos[12] + 4) = 0;
                        }
                        memset(&objectPos[12], 0, 12);
                      }
                      v28 = __RTDynamicCast(
                              inptr: v27,
                              VfDelta: 0,
                              SrcType: &CMapClass `RTTI Type Descriptor',
                              TargetType: &CEditGameClass `RTTI Type Descriptor',
                              isReference: 0);
                      (*(void (__thiscall **)(void *, Vector *))(*(_DWORD *)v27 + 80))(a1: v27, a2: &cameraPos);
                      v29 = 0;
                      *(float *)&v29 = (float)((float)((float)(*(float *)&objectList.m_Size - cameraPos.x)
                                                     * (float)(*(float *)&objectList.m_Size - cameraPos.x))
                                             + (float)((float)(*(float *)&objectList.m_pElements - cameraPos.y)
                                                     * (float)(*(float *)&objectList.m_pElements - cameraPos.y)))
                                     + (float)((float)(v35 - cameraPos.z) * (float)(v35 - cameraPos.z));
                      v30 = v29;
                      *(float *)&v30 = fsqrt(*(float *)&v29);
                      *(_OWORD *)v38 = v30;
                      itoa(val: (int)*(float *)&v30, buf: v32, radix: 10);
                      (*(void (__thiscall **)(void *, _DWORD, char *))(*(_DWORD *)v28 + 4))(
                        a1: v28,
                        a2: *((_DWORD *)&objectList.m_Memory + 2),
                        a3: v32);
                      if ( ++i >= (int)objectList.m_Memory.m_pMemory )
                        break;
                      v24 = i;
                    }
                  }
                }
                v43 = -1;
                CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&buf[244]);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E19F0
// Name: private: void COP_Entity::PresentProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::PresentProperties(COP_Entity *this)
{
  HWND__ *m_hWnd; // eax
  int k; // esi
  int inserted; // eax
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // eax
  CMapEntity *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapEntity *v8; // ecx
  CMapInstance *ChildOf; // eax
  CMapInstance *v10; // esi
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // ecx
  unsigned __int16 Inorder; // si
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *v13; // eax
  const char *szValue; // edi
  int v15; // eax
  unsigned __int16 v16; // di
  char *v17; // eax
  GDinputvariable *v18; // eax
  GDinputvariable *v19; // eax
  int v20; // eax
  char *m_pszData; // esi
  int v22; // eax
  const char *v23; // esi
  int szKey; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  unsigned __int16 v27; // ax
  CVisGroup ***p_m_pElements; // eax
  int v29; // eax
  GDinputvariable *v30; // eax
  CAngleBox *p_m_Angle; // ecx
  int m; // edi
  MDkeyvalue *p_elem; // esi
  int v34; // eax
  char ValueData[80]; // [esp+4h] [ebp-B0h] BYREF
  void *p; // [esp+54h] [ebp-60h]
  const char *pKey; // [esp+58h] [ebp-5Ch]
  const char *pValue; // [esp+5Ch] [ebp-58h]
  CInstanceParmData InstanceParmData; // [esp+60h] [ebp-54h] BYREF
  CUtlReferenceVector<CMapEntity> entityList; // [esp+6Ch] [ebp-48h] BYREF
  int j; // [esp+80h] [ebp-34h]
  CMapEntity *pInstanceParmsEntity; // [esp+84h] [ebp-30h]
  int i; // [esp+88h] [ebp-2Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+8Ch] [ebp-28h] BYREF
  CUtlReference<CMapClass> *v45; // [esp+90h] [ebp-24h]
  CMapEntity *v46; // [esp+94h] [ebp-20h]
  int v47; // [esp+98h] [ebp-1Ch]
  CMapClass *pMapClass; // [esp+9Ch] [ebp-18h] BYREF
  const char *pReplace; // [esp+A0h] [ebp-14h]
  char v50; // [esp+A7h] [ebp-Dh]
  int v51; // [esp+B0h] [ebp-4h]

  v47 = 0;
  if ( this->m_bAllowPresentProperties )
  {
    m_hWnd = this->m_VarList.m_hWnd;
    ++this->m_nPresentPropertiesCalls;
    SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
    CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_InstanceParmData.m_Tree);
    memset(this->m_VarMap, 0xFFu, sizeof(this->m_VarMap));
    if ( this->m_bSmartedit && this->m_pDisplayClass != nullptr )
    {
      memset(this->m_VarMap, 0xFFu, sizeof(this->m_VarMap));
      for ( k = 0; k < this->m_pDisplayClass->m_nVariables; ++k )
      {
        i = (int)GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: k);
        pInstanceParmsEntity = (CMapEntity *)(i + 20);
        if ( _V_stricmp(s1: (const char *)(i + 20), s2: "spawnflags") != 0 )
        {
          inserted = CListCtrl::InsertItem(
                       this: &this->m_VarList,
                       nMask: 1u,
                       nItem: k,
                       lpszItem: (const char *)(i + 85),
                       nState: 0,
                       nStateMask: 0,
                       nImage: 0,
                       lParam: 0);
          CListCtrl::SetItem(
            this: &this->m_VarList,
            nItem: inserted,
            nSubItem: 0,
            nMask: 4u,
            lpszItem: nullptr,
            nImage: 0,
            nState: 0,
            nStateMask: 0,
            lParam: (int)pInstanceParmsEntity);
        }
      }
      m_pObjectList = this->m_pObjectList;
      if ( m_pObjectList->m_Size == 1 )
      {
        m_pObject = (CMapEntity *)(*m_pObjectList->m_Memory.m_pMemory)->m_pObject;
        if ( m_pObject != nullptr )
        {
          v46 = m_pObject;
          m_pHead = m_pObject->CMapClass::m_References.m_pHead;
          v7 = m_pObject->CMapClass::m_References.m_pHead;
          if ( v7 != nullptr )
            v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v45 = nullptr;
          m_pObject->CMapClass::m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v8 = v46;
        pMapClass = v46;
        v51 = -1;
        if ( v46 != nullptr )
        {
          if ( v45 != nullptr )
          {
            v45->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v45;
          }
          else if ( (CUtlReference<CMapClass> **)v46->CMapClass::m_References.m_pHead == &m_pHead )
          {
            v46->CMapClass::m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v45 = nullptr;
          m_pHead = nullptr;
          v46 = nullptr;
        }
        ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: v8, ignoredArg: nullptr);
        v10 = ChildOf;
        if ( ChildOf != nullptr && ChildOf->m_pInstancedMap != nullptr )
        {
          memset(&entityList, 0, 12);
          CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
            this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&entityList,
            nGrowSize: 0,
            nInitSize: 0);
          entityList.m_Size = 0;
          entityList.m_pElements = nullptr;
          v51 = 4;
          CMapDoc::FindEntitiesByClassName(
            this: v10->m_pInstancedMap,
            Found: &entityList,
            pszClassName: "func_instance_parms",
            bVisiblesOnly: false);
          if ( entityList.m_Size == 1 )
          {
            p_m_KeyValues = &(*entityList.m_Memory.m_pMemory)->m_pObject->m_KeyValues;
            pInstanceParmsEntity = (*entityList.m_Memory.m_pMemory)->m_pObject;
            Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &p_m_KeyValues->m_KeyValues.m_Elements.m_Tree);
            for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
            {
              v13 = &pInstanceParmsEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder];
              szValue = v13->m_Data.elem.szValue;
              if ( V_strncasecmp(s1: v13->m_Data.elem.szKey, s2: "parm", n: 4) == 0 )
              {
                pReplace = &var;
                if ( szValue != nullptr )
                {
                  strcpy(ValueData, szValue);
                  strchr(string: (unsigned __int8 *)ValueData, chr: 0x20u);
                  if ( v15 != 0 )
                  {
                    *(_BYTE *)v15 = 0;
                    pReplace = (const char *)(v15 + 1);
                  }
                  v16 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&pMapClass[1].m_nObjectID);
                  j = v16;
                  if ( v16 != 0xFFFF )
                  {
                    do
                    {
                      v17 = (char *)pMapClass[1].m_pParent + 604 * v16;
                      pKey = v17 + 12;
                      pValue = v17 + 92;
                      if ( V_strncasecmp(s1: v17 + 92, s2: ValueData, n: strlen(ValueData)) == 0 )
                      {
                        CInstanceParmData::CInstanceParmData(this: &InstanceParmData);
                        LOBYTE(v51) = 5;
                        v18 = (GDinputvariable *)operator new(nSize: 0x1F0u);
                        p = v18;
                        LOBYTE(v51) = 6;
                        if ( v18 != nullptr )
                          v19 = GDinputvariable::GDinputvariable(this: v18, szType: pReplace, szName: ValueData);
                        else
                          v19 = nullptr;
                        LOBYTE(v51) = 5;
                        InstanceParmData.m_ParmVariable = v19;
                        if ( pKey != nullptr )
                          v20 = strlen(pKey);
                        else
                          v20 = 0;
                        ATL::CSimpleStringT<char,0>::SetString(
                          this: &InstanceParmData.m_ParmKey,
                          pszSrc: pKey,
                          nLength: v20);
                        ATL::CSimpleStringT<char,0>::SetString(
                          this: &InstanceParmData.m_VariableName,
                          pszSrc: ValueData,
                          nLength: strlen(ValueData));
                        m_pszData = this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Insert(
                                                                                           this: &this->m_InstanceParmData,
                                                                                           key: &InstanceParmData.m_VariableName,
                                                                                           insert: &InstanceParmData)].m_Data.elem.m_VariableName.m_pszData;
                        v22 = CListCtrl::InsertItem(
                                this: &this->m_VarList,
                                nMask: 1u,
                                nItem: 0,
                                lpszItem: m_pszData,
                                nState: 0,
                                nStateMask: 0,
                                nImage: 0,
                                lParam: 0);
                        CListCtrl::SetItem(
                          this: &this->m_VarList,
                          nItem: v22,
                          nSubItem: 0,
                          nMask: 4u,
                          lpszItem: nullptr,
                          nImage: 0,
                          nState: 0,
                          nStateMask: 0,
                          lParam: (int)m_pszData);
                        WCKeyValuesT<WCKVBase_Dict>::SetValue(
                          this: &this->m_kv,
                          pszKey: ValueData,
                          pszValue: &pValue[strlen(ValueData) + 1]);
                        LOBYTE(v51) = 4;
                        CInstanceParmData::~CInstanceParmData(this: (CBoolString *)&InstanceParmData);
                        v16 = j;
                      }
                      v16 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                              this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&pMapClass[1].m_nObjectID,
                              i: v16);
                      j = v16;
                    }
                    while ( v16 != 0xFFFF );
                    Inorder = i;
                  }
                }
              }
              Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                          this: &pInstanceParmsEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                          i: Inorder);
            }
          }
          v51 = -1;
          CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
        }
      }
      v23 = (const char *)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_kv.m_KeyValues.m_Elements.m_Tree);
      for ( pReplace = v23; v23 != (const char *)0xFFFF; pReplace = v23 )
      {
        szKey = (int)this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v23].m_Data.elem.szKey;
        if ( GDclass::VarForName(this: this->m_pDisplayClass, pszName: (const char *)szKey, piIndex: nullptr) != nullptr )
          goto LABEL_51;
        StringManager = AfxGetStringManager();
        if ( StringManager == nullptr )
          ATL::AtlThrowImpl(hr: -2147467259);
        pMapClass = (CMapClass *)&StringManager->GetNilString(this: StringManager)[1];
        v51 = 9;
        if ( szKey != 0 )
        {
          if ( (szKey & 0xFFFF0000) != 0 )
          {
            ATL::CSimpleStringT<char,0>::SetString(
              this: (ATL::CSimpleStringT<char,0> *)&pMapClass,
              pszSrc: (const char *)szKey,
              nLength: strlen((const char *)szKey));
          }
          else
          {
            StringResourceHandle = AfxFindStringResourceHandle(__formal: (unsigned __int16)szKey);
            if ( StringResourceHandle != nullptr )
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMapClass,
                hInstance: StringResourceHandle,
                nID: (unsigned __int16)szKey);
            LOWORD(v23) = (_WORD)pReplace;
          }
        }
        else
        {
          ATL::CSimpleStringT<char,0>::SetString(
            this: (ATL::CSimpleStringT<char,0> *)&pMapClass,
            pszSrc: nullptr,
            nLength: 0);
        }
        v51 = 10;
        v47 |= 1u;
        v27 = CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Find(
                this: &this->m_InstanceParmData,
                key: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMapClass);
        v50 = 1;
        if ( v27 != 0xFFFF )
LABEL_51:
          v50 = 0;
        v51 = -1;
        if ( (v47 & 1) != 0 )
        {
          v47 &= ~1u;
          v51 = -1;
          p_m_pElements = &pMapClass[-1].m_VisGroups.m_List.m_pElements;
          if ( _InterlockedDecrement(&pMapClass[-1].m_nDropTraceMarker) <= 0 )
            ((void (__stdcall *)(CVisGroup ***))(**p_m_pElements)->m_Children.m_Memory.m_nAllocationCount)(a1: p_m_pElements);
        }
        if ( v50 != 0 )
        {
          v29 = CListCtrl::InsertItem(
                  this: &this->m_VarList,
                  nMask: 1u,
                  nItem: (int)pReplace,
                  lpszItem: (const char *)szKey,
                  nState: 0,
                  nStateMask: 0,
                  nImage: 0,
                  lParam: 0);
          CListCtrl::SetItem(
            this: &this->m_VarList,
            nItem: v29,
            nSubItem: 0,
            nMask: 4u,
            lpszItem: nullptr,
            nImage: 0,
            nState: 0,
            nStateMask: 0,
            lParam: szKey);
          LOWORD(v23) = (_WORD)pReplace;
        }
        v23 = (const char *)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                              this: &this->m_kv.m_KeyValues.m_Elements.m_Tree,
                              i: (unsigned __int16)v23);
      }
      v30 = GDclass::VarForName(this: this->m_pDisplayClass, pszName: "angles", piIndex: nullptr);
      p_m_Angle = &this->m_Angle;
      if ( v30 != nullptr )
        CAngleBox::Enable(this: p_m_Angle, bEnable: this->m_bCanEdit);
      else
        CAngleBox::Enable(this: p_m_Angle, bEnable: false);
    }
    else
    {
      COP_Entity::RemoveBlankKeys(this);
      for ( m = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_kv.m_KeyValues.m_Elements.m_Tree);
            m != 0xFFFF;
            m = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_kv.m_KeyValues.m_Elements.m_Tree,
                  i: m) )
      {
        p_elem = &this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)m].m_Data.elem;
        v34 = CListCtrl::InsertItem(
                this: &this->m_VarList,
                nMask: 1u,
                nItem: m,
                lpszItem: p_elem->szKey,
                nState: 0,
                nStateMask: 0,
                nImage: 0,
                lParam: 0);
        CListCtrl::SetItem(
          this: &this->m_VarList,
          nItem: v34,
          nSubItem: 0,
          nMask: 4u,
          lpszItem: nullptr,
          nImage: 0,
          nState: 0,
          nStateMask: 0,
          lParam: (int)p_elem);
      }
      CAngleBox::Enable(this: &this->m_Angle, bEnable: this->m_bCanEdit);
    }
    COP_Entity::RefreshKVListValues(this, pOnlyThisVar: nullptr);
    COP_Entity::ResortItems(this);
    COP_Entity::SetCurKey(this, pszKey: this->m_strLastKey.m_pszData);
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_VarList.m_hWnd, lpRect: nullptr, bErase: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2170
// Name: protected: void COP_Entity::OnDblClickKeyValues(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnDblClickKeyValues(COP_Entity *this, tagNMHDR *pNMHDR, tagNMHDR *pResult)
{
  int v4; // eax
  int v5; // edi
  GDinputvariable *VariableAt; // eax
  GDIV_TYPE m_eType; // eax
  CWnd *m_pSmartControl; // eax
  void *v9; // eax
  CWnd *v10; // ecx

  if ( this->m_bSmartedit )
  {
    v4 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
    if ( v4 != 0 )
    {
      v5 = v4 - 1;
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v4 - 1, lParam: 2);
      if ( v5 != -1 )
      {
        VariableAt = COP_Entity::GetVariableAt(this, index: v5);
        if ( VariableAt != nullptr )
        {
          m_eType = VariableAt->m_eType;
          if ( m_eType == ivColor255 || m_eType == ivColor1 )
          {
            COP_Entity::OnPickColor(this);
          }
          else
          {
            m_pSmartControl = this->m_pSmartControl;
            if ( m_pSmartControl != nullptr )
            {
              if ( this->m_pSmartBrowseButton != nullptr )
              {
                COP_Entity::OnBrowse(this, a2: v5, a3: (int)this);
              }
              else
              {
                v9 = __RTDynamicCast(
                       inptr: m_pSmartControl,
                       VfDelta: 0,
                       SrcType: &CWnd `RTTI Type Descriptor',
                       TargetType: &CMyEdit `RTTI Type Descriptor',
                       isReference: 0);
                v10 = this->m_pSmartControl;
                if ( v9 != nullptr )
                {
                  CWnd::SetFocus(this: v10);
                  SendMessageA(hWnd: this->m_pSmartControl->m_hWnd, Msg: 0xB1u, wParam: 0, lParam: -1);
                }
                else if ( __RTDynamicCast(
                            inptr: v10,
                            VfDelta: 0,
                            SrcType: &CWnd `RTTI Type Descriptor',
                            TargetType: &CMyComboBox `RTTI Type Descriptor',
                            isReference: 0) != nullptr
                       || __RTDynamicCast(
                            inptr: this->m_pSmartControl,
                            VfDelta: 0,
                            SrcType: &CWnd `RTTI Type Descriptor',
                            TargetType: &CTargetNameComboBox `RTTI Type Descriptor',
                            isReference: 0) != nullptr )
                {
                  CWnd::SetFocus(this: this->m_pSmartControl);
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E22B0
// Name: protected: void COP_Entity::OnAddkeyvalue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnAddkeyvalue(COP_Entity *this)
{
  COP_Entity *v1; // esi
  WCKeyValuesT<WCKVBase_Dict> *p_m_kv; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  int v4; // esi
  char *i; // ebx
  volatile signed __int32 *v6; // ebx
  int m_nNewKeyCount; // [esp-4h] [ebp-B8h]
  CNewKeyValue newkv; // [esp+4h] [ebp-B0h] BYREF
  COP_Entity *v9; // [esp+A0h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTemp; // [esp+A4h] [ebp-10h] BYREF
  int v11; // [esp+B0h] [ebp-4h]

  v1 = this;
  v9 = this;
  CNewKeyValue::CNewKeyValue(this: &newkv, pParent: nullptr);
  v11 = 0;
  m_nNewKeyCount = v1->m_nNewKeyCount;
  v1->m_nNewKeyCount = m_nNewKeyCount + 1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &newkv.m_Key,
    pszFormat: "newkey%d",
    m_nNewKeyCount);
  ATL::CSimpleStringT<char,0>::SetString(this: &newkv.m_Value, pszSrc: "value", nLength: 5);
  if ( CDialog::DoModal(this: &newkv) == 2 )
  {
    v11 = -1;
    CSearchReplaceDlg::~CSearchReplaceDlg(this: &newkv);
  }
  else
  {
    p_m_kv = &v1->m_kv;
    if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v1->m_kv, pszKey: newkv.m_Key.m_pszData, piIndex: nullptr) != nullptr )
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      strTemp.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v11) = 2;
      v4 = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strTemp,
        pszFormat: "%s#%d",
        newkv.m_Key.m_pszData,
        1);
      for ( i = strTemp.m_pszData;
            WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_kv, pszKey: strTemp.m_pszData, piIndex: nullptr) != nullptr;
            i = strTemp.m_pszData )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &strTemp,
          pszFormat: "%s#%d",
          newkv.m_Key.m_pszData,
          ++v4);
      }
      ATL::CSimpleStringT<char,0>::operator=(this: &newkv.m_Key, strSrc: (ATL::CStringData *)&strTemp);
      LOBYTE(v11) = 0;
      v6 = (volatile signed __int32 *)(i - 16);
      if ( _InterlockedDecrement(v6 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(a1: v6);
      v1 = v9;
    }
    WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v1->m_kvAdded, pszKey: newkv.m_Key.m_pszData, pszValue: "1");
    WCKeyValuesT<WCKVBase_Dict>::SetValue(
      this: p_m_kv,
      pszKey: newkv.m_Key.m_pszData,
      pszValue: newkv.m_Value.m_pszData);
    COP_Entity::PresentProperties(this: v1);
    COP_Entity::SetCurKey(this: v1, pszKey: newkv.m_Key.m_pszData);
    v11 = -1;
    CSearchReplaceDlg::~CSearchReplaceDlg(this: &newkv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2470
// Name: protected: void COP_Entity::UpdateEditClass(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdateEditClass(COP_Entity *this, const char *pszClass, bool bForce)
{
  GDclass *m_pEditClass; // ebx
  GDclass *v5; // eax
  unsigned __int16 Inorder; // di
  int v7; // ebx
  MDkeyvalue *p_elem; // edi
  GDclass *pOldEditClass; // [esp+Ch] [ebp-4h]

  m_pEditClass = this->m_pEditClass;
  pOldEditClass = m_pEditClass;
  v5 = GameData::ClassForName(this: pGD, pszName: pszClass, piIndex: nullptr);
  this->m_pEditClass = v5;
  if ( !bForce )
  {
    if ( v5 == m_pEditClass )
      return;
    goto LABEL_5;
  }
  if ( v5 != m_pEditClass )
  {
LABEL_5:
    if ( v5 != nullptr && m_pEditClass != nullptr && _V_stricmp(s1: pszClass, s2: "multi_manager") != 0 )
    {
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_kv.m_KeyValues.m_Elements.m_Tree);
      if ( Inorder != 0xFFFF )
      {
        do
        {
          v7 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                 this: &this->m_kv.m_KeyValues.m_Elements.m_Tree,
                 i: Inorder);
          p_elem = &this->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
          if ( GDclass::VarForName(this: this->m_pEditClass, pszName: p_elem->szKey, piIndex: nullptr) == nullptr )
            WCKeyValuesT<WCKVBase_Dict>::RemoveKey(this: &this->m_kv, pszKey: p_elem->szKey);
          Inorder = v7;
        }
        while ( v7 != 0xFFFF );
        m_pEditClass = pOldEditClass;
      }
    }
  }
  COP_Entity::AssignClassDefaults(this, pClass: this->m_pEditClass, pOldClass: m_pEditClass);
  COP_Entity::PresentProperties(this);
  if ( this->m_pDisplayClass == this->m_pEditClass && this->m_bCanEdit )
    COP_Entity::SetReadOnly(this, bReadOnly: false);
  else
    COP_Entity::SetReadOnly(this, bReadOnly: true);
}

//------------------------------------------------------------------------------
// Address: 0x100E25A0
// Name: protected: void COP_Entity::SetSmartedit(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::SetSmartedit(COP_Entity *this, bool bSet)
{
  CWnd *DlgItem; // eax
  unsigned int i; // edi
  CWnd *v5; // eax
  WPARAM m_bSmartedit; // edi
  CWnd *v7; // eax
  int v8; // [esp-8h] [ebp-Ch]

  if ( this->m_bSmartedit != bSet )
  {
    this->m_bSmartedit = bSet;
    if ( !bSet )
    {
      CWnd::ShowWindow(this: &this->m_cPickColor, nCmdShow: 0);
      CWnd::ShowWindow(this: &this->m_SmartAngle, nCmdShow: 0);
      CWnd::ShowWindow(this: &this->m_SmartAngleEdit, nCmdShow: 0);
      COP_Entity::DestroySmartControls(this);
    }
    CWnd::ShowWindow(this: &this->m_KeyValueHelpText, nCmdShow: this->m_bSmartedit ? 5 : 0);
    v8 = this->m_bSmartedit ? 5 : 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1525);
    CWnd::ShowWindow(this: DlgItem, nCmdShow: v8);
    for ( i = 0; i < 6; ++i )
    {
      v5 = CWnd::GetDlgItem(this, nID: g_DumbEditControls[i]);
      if ( v5 != nullptr )
        CWnd::ShowWindow(this: v5, nCmdShow: this->m_bSmartedit ? 0 : 5);
    }
    m_bSmartedit = this->m_bSmartedit;
    v7 = CWnd::GetDlgItem(this, nID: 1119);
    SendMessageA(hWnd: v7->m_hWnd, Msg: 0xF1u, wParam: m_bSmartedit, lParam: 0);
    COP_Entity::PresentProperties(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E26A0
// Name: protected: void COP_Entity::OnSmartedit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnSmartedit(COP_Entity *this)
{
  bool v2; // zf

  v2 = !this->m_bSmartedit;
  this->m_iSortColumn = -1;
  COP_Entity::SetSmartedit(this, bSet: v2);
  this->m_bWantSmartedit = this->m_bSmartedit;
}

//------------------------------------------------------------------------------
// Address: 0x100E26D0
// Name: protected: void COP_Entity::UpdateDisplayClass(class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdateDisplayClass(COP_Entity *this, GDclass *pClass)
{
  GDclass *m_pDisplayClass; // edi
  CWnd *DlgItem; // eax
  bool v5; // bl
  bool v7; // zf
  CWnd *v8; // eax
  CWnd *v9; // eax
  int lastNumPresentPropertiesCalls; // [esp+Ch] [ebp-4h]
  char bNeedsSetupForMode_3; // [esp+1Bh] [ebp+Bh]

  m_pDisplayClass = this->m_pDisplayClass;
  DlgItem = CWnd::GetDlgItem(this, nID: 1119);
  v5 = CWnd::IsWindowEnabled(this: DlgItem) != (m_pDisplayClass != nullptr);
  if ( pClass == m_pDisplayClass && !v5 )
    return;
  v7 = !this->m_bAllowPresentProperties;
  lastNumPresentPropertiesCalls = this->m_nPresentPropertiesCalls;
  bNeedsSetupForMode_3 = 1;
  this->m_pDisplayClass = pClass;
  if ( v7 )
  {
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
    CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_InstanceParmData.m_Tree);
    memset(this->m_VarMap, 0xFFu, sizeof(this->m_VarMap));
  }
  if ( this->m_pDisplayClass != nullptr )
  {
    CEntityHelpDlg::SetEditGameClass(pClass: this->m_pDisplayClass);
    v9 = CWnd::GetDlgItem(this, nID: 1119);
    CWnd::EnableWindow(this: v9, bEnable: 1);
    if ( v5 )
      this->m_bSmartedit = !this->m_bWantSmartedit;
    COP_Entity::SetSmartedit(this, bSet: this->m_bWantSmartedit);
  }
  else
  {
    if ( this->m_bSmartedit || v5 )
    {
      this->m_bSmartedit = true;
      COP_Entity::SetSmartedit(this, bSet: false);
      bNeedsSetupForMode_3 = 0;
    }
    v8 = CWnd::GetDlgItem(this, nID: 1119);
    CWnd::EnableWindow(this: v8, bEnable: 0);
    if ( bNeedsSetupForMode_3 == 0 )
      goto LABEL_12;
  }
  if ( this->m_nPresentPropertiesCalls == lastNumPresentPropertiesCalls )
    COP_Entity::PresentProperties(this);
LABEL_12:
  if ( this->m_pDisplayClass == this->m_pEditClass && this->m_bCanEdit )
    COP_Entity::SetReadOnly(this, bReadOnly: false);
  else
    COP_Entity::SetReadOnly(this, bReadOnly: true);
}

//------------------------------------------------------------------------------
// Address: 0x100E2840
// Name: protected: void COP_Entity::OnKillfocusKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnKillfocusKey(COP_Entity *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  char *v3; // eax
  bool v4; // cc
  unsigned __int8 *Value; // eax
  int CurVarListSelection; // ebx
  const char *ItemData; // eax
  ATL::CStringData *v8; // eax
  LRESULT KeyValueRowByShortName; // eax
  char szSaveValue[512]; // [esp+4h] [ebp-2B4h] BYREF
  CNewKeyValue newkv; // [esp+204h] [ebp-B4h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v12; // [esp+2A0h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strBuf; // [esp+2A4h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strOutput; // [esp+2A8h] [ebp-10h] BYREF
  int v15; // [esp+2B4h] [ebp-4h]

  if ( this->m_bChangingKeyName )
  {
    this->m_bChangingKeyName = false;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    strOutput.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v15 = 1;
    CWnd::GetWindowTextA(this: &this->m_cKey, rString: &strOutput);
    if ( *((_DWORD *)strOutput.m_pszData - 3) == 0 )
    {
      AfxMessageBox(lpszText: "Use the delete button to remove key/value pairs.", nType: 0, nIDHelp: 0);
      v15 = -1;
      v3 = strOutput.m_pszData - 16;
      v4 = _InterlockedDecrement((volatile signed __int32 *)strOutput.m_pszData - 1) <= 0;
      goto LABEL_6;
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeLower(this: &strOutput);
    if ( this->m_szOldKeyName.m_pszData == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    if ( _mbscmp(
           s1: (const unsigned __int8 *)strOutput.m_pszData,
           s2: (const unsigned __int8 *)this->m_szOldKeyName.m_pszData) == 0 )
    {
      v15 = -1;
      v3 = strOutput.m_pszData - 16;
      v4 = _InterlockedDecrement((volatile signed __int32 *)strOutput.m_pszData - 1) <= 0;
LABEL_6:
      if ( v4 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
      return;
    }
    memset(dst: (unsigned __int8 *)szSaveValue, value: 0, count: sizeof(szSaveValue));
    Value = (unsigned __int8 *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                                 this: &this->m_kv,
                                 pszKey: this->m_szOldKeyName.m_pszData,
                                 piIndex: nullptr);
    strncpy(dest: (unsigned __int8 *)szSaveValue, source: Value, count: 0x1FFu);
    CurVarListSelection = COP_Entity::GetCurVarListSelection(this);
    if ( CurVarListSelection != -1 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strBuf);
      LOBYTE(v15) = 4;
      ItemData = (const char *)CListCtrl::GetItemData(this: &this->m_VarList, nItem: CurVarListSelection);
      v8 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                                 this: &v12,
                                 pszSrc: ItemData);
      LOBYTE(v15) = 5;
      ATL::CSimpleStringT<char,0>::operator=(this: &strBuf, strSrc: v8);
      LOBYTE(v15) = 4;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v12);
      WCKeyValuesT<WCKVBase_Dict>::RemoveKey(this: &this->m_kv, pszKey: strBuf.m_pszData);
      SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1008u, wParam: CurVarListSelection, lParam: 0);
      CNewKeyValue::CNewKeyValue(this: &newkv, pParent: nullptr);
      LOBYTE(v15) = 6;
      ATL::CSimpleStringT<char,0>::operator=(this: &newkv.m_Key, strSrc: (ATL::CStringData *)&strOutput);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(this: &newkv.m_Value, pszSrc: szSaveValue);
      WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kvAdded, pszKey: newkv.m_Key.m_pszData, pszValue: "1");
      WCKeyValuesT<WCKVBase_Dict>::SetValue(
        this: &this->m_kv,
        pszKey: newkv.m_Key.m_pszData,
        pszValue: newkv.m_Value.m_pszData);
      COP_Entity::PresentProperties(this);
      KeyValueRowByShortName = COP_Entity::GetKeyValueRowByShortName(this, pShortName: newkv.m_Key.m_pszData);
      COP_Entity::SetCurVarListSelection(this, iSel: KeyValueRowByShortName);
      COP_Entity::OnSelchangeKeyvalues(this);
      LOBYTE(v15) = 4;
      CSearchReplaceDlg::~CSearchReplaceDlg(this: &newkv);
      LOBYTE(v15) = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strBuf);
    }
    v15 = -1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strOutput);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2AC0
// Name: private: void COP_Entity::PerformMark(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::PerformMark(COP_Entity *this, const char *szTargetName, bool bClear, bool bNameOrClass)
{
  int i; // esi
  CMapEntity *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CUtlReferenceVector<CMapClass> Select; // [esp+8h] [ebp-44h] BYREF
  CUtlReferenceVector<CMapEntity> Found; // [esp+1Ch] [ebp-30h] BYREF
  CUtlReference<CMapClass> src; // [esp+30h] [ebp-1Ch] BYREF
  CMapDoc *pDoc; // [esp+3Ch] [ebp-10h]
  int v12; // [esp+48h] [ebp-4h]

  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr && *szTargetName != 0 )
  {
    memset(&Found, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Found,
      nGrowSize: 0,
      nInitSize: 0);
    Found.m_Size = 0;
    Found.m_pElements = nullptr;
    v12 = 3;
    CMapDoc::FindEntitiesByName(this: pDoc, &Found, pszName: szTargetName, bVisiblesOnly: false);
    if ( Found.m_Size != 0
      || bNameOrClass
      && (CMapDoc::FindEntitiesByClassName(this: pDoc, &Found, pszClassName: szTargetName, bVisiblesOnly: false),
          Found.m_Size != 0) )
    {
      memset(&Select, 0, 12);
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Select.m_Memory, nGrowSize: 0, nInitSize: 0);
      Select.m_Size = 0;
      Select.m_pElements = nullptr;
      LOBYTE(v12) = 7;
      for ( i = 0; i < Found.m_Size; ++i )
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
        LOBYTE(v12) = 8;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &Select,
          elem: Select.m_Size,
          &src);
        LOBYTE(v12) = 7;
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
      if ( bClear )
        CMapDoc::SelectObjectList(this: pDoc, pList: &Select, cmd: 1042);
      else
        CMapDoc::SelectObjectList(this: pDoc, pList: &Select, cmd: 2);
      CMapDoc::Center2DViewsOnSelection(this: pDoc);
      LOBYTE(v12) = 3;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Select);
    }
    else
    {
      CWnd::MessageBoxA(
        this,
        lpszText: "No entities were found with that targetname.",
        lpszCaption: "No entities found",
        nType: 0x40u);
    }
    v12 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Found);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2CA0
// Name: protected: void COP_Entity::OnMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnMark(COP_Entity *this)
{
  int v2; // eax
  int v3; // edi
  __int16 v4; // ax
  GDinputvariable *VariableAt; // edi
  char szTargetName[256]; // [esp+Ch] [ebp-104h] BYREF

  v2 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
  }
  else
  {
    v3 = -1;
  }
  v4 = this->m_VarMap[v3];
  if ( v4 != -1 )
  {
    if ( v4 > -10 )
      VariableAt = GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v4);
    else
      VariableAt = this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v4)].m_Data.elem.m_ParmVariable;
    if ( VariableAt != nullptr )
    {
      CWnd::GetWindowTextA(this: this->m_pSmartControl, lpszString: szTargetName, nMaxCount: 256);
      COP_Entity::PerformMark(
        this,
        szTargetName,
        bClear: true,
        bNameOrClass: VariableAt->m_eType == ivTargetNameOrClass);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2D70
// Name: protected: void COP_Entity::OnMarkAndAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnMarkAndAdd(COP_Entity *this)
{
  int v2; // eax
  int v3; // esi
  __int16 v4; // ax
  int v5; // edi
  int m_Size; // esi
  void *v7; // esp
  CMapEntity **m_pMemory; // ebx
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int v10; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // eax
  CMapClass **v16; // eax
  int v17; // esi
  const char *Value; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-54h]
  _BYTE v20[12]; // [esp+0h] [ebp-44h] BYREF
  CUtlVector<CMapEntity *,CUtlMemory<CMapEntity *,int> > temp; // [esp+Ch] [ebp-38h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+20h] [ebp-24h] BYREF
  CUtlReference<CMapClass> *v23; // [esp+24h] [ebp-20h]
  CMapClass *v24; // [esp+28h] [ebp-1Ch]
  CMapClass *pMapClass; // [esp+2Ch] [ebp-18h]
  COP_Entity *v26; // [esp+30h] [ebp-14h]
  GDinputvariable *pVar; // [esp+34h] [ebp-10h]
  int v28; // [esp+40h] [ebp-4h]

  m_hWnd = this->m_VarList.m_hWnd;
  v26 = this;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2) + 1;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x100Cu, wParam: v2 - 1, lParam: 2);
  }
  else
  {
    v3 = -1;
  }
  v4 = this->m_VarMap[v3];
  if ( v4 != -1 )
  {
    pVar = v4 > -10
         ? GDclass::GetVariableAt(this: this->m_pDisplayClass, iIndex: v4)
         : this->m_InstanceParmData.m_Tree.m_Elements.m_pMemory[(unsigned __int16)(-10 - v4)].m_Data.elem.m_ParmVariable;
    v5 = 0;
    if ( pVar != nullptr )
    {
      m_Size = this->m_pObjectList->m_Size;
      v7 = alloca(4 * m_Size);
      m_pMemory = (CMapEntity **)v20;
      temp.m_Memory.m_pMemory = (CMapEntity **)v20;
      temp.m_Memory.m_nAllocationCount = m_Size;
      temp.m_Memory.m_nGrowSize = -1;
      temp.m_Size = 0;
      temp.m_pElements = (CMapEntity **)v20;
      v28 = 1;
      m_pObjectList = v26->m_pObjectList;
      v10 = 0;
      if ( m_pObjectList->m_Size > 0 )
      {
        do
        {
          m_pObject = m_pObjectList->m_Memory.m_pMemory[v10 >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory + 2) >> 27)][v10 & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            v24 = m_pObjectList->m_Memory.m_pMemory[v10 >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory + 2) >> 27)][v10 & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = m_pObject->m_References.m_pHead;
            v12 = m_pObject->m_References.m_pHead;
            if ( v12 != nullptr )
              v12->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
            v23 = nullptr;
            m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
          }
          pMapClass = v24;
          LOBYTE(v28) = 1;
          if ( v24 != nullptr )
          {
            if ( v23 != nullptr )
            {
              v23->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v23;
            }
            else if ( (CUtlReference<CMapClass> **)v24->m_References.m_pHead == &m_pHead )
            {
              v24->m_References.m_pHead = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v23 = nullptr;
            m_pHead = nullptr;
            v24 = nullptr;
          }
          v13 = temp.m_Size;
          v14 = temp.m_Size;
          if ( temp.m_Size + 1 > temp.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&temp,
              num: temp.m_Size - temp.m_Memory.m_nAllocationCount + 1);
            m_pMemory = temp.m_Memory.m_pMemory;
            v13 = temp.m_Size;
          }
          temp.m_Size = v13 + 1;
          v15 = v13 - v14;
          temp.m_pElements = m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &m_pMemory[v14 + 1], src: &m_pMemory[v14], count: 4 * v15);
          v16 = &m_pMemory[v14];
          if ( v16 != nullptr )
            *v16 = pMapClass;
          m_pObjectList = v26->m_pObjectList;
          ++v10;
        }
        while ( v10 < m_pObjectList->m_Size );
        v5 = temp.m_Size;
      }
      LOBYTE(pMapClass) = pVar->m_eType == ivTargetNameOrClass;
      v17 = 0;
      if ( v5 > 0 )
      {
        pVar = (GDinputvariable *)((char *)pVar + 20);
        do
        {
          Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: &m_pMemory[v17]->m_KeyValues,
                    pszKey: (const char *)pVar,
                    piIndex: nullptr);
          if ( Value != nullptr )
            COP_Entity::PerformMark(this: v26, szTargetName: Value, bClear: false, bNameOrClass: (bool)pMapClass);
          ++v17;
        }
        while ( v17 < v5 );
      }
      v28 = 3;
      temp.m_Size = 0;
      if ( temp.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          free(pMem: m_pMemory);
          m_pMemory = nullptr;
          temp.m_Memory.m_pMemory = nullptr;
        }
        temp.m_Memory.m_nAllocationCount = 0;
      }
      temp.m_pElements = m_pMemory;
      v28 = -1;
      if ( temp.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        free(pMem: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3020
// Name: public: virtual void CPickEntityTarget::OnNotifyPickEntity(class CToolPickEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickEntityTarget::OnNotifyPickEntity(CPickEntityTarget *this, CToolPickEntity *pTool)
{
  CMapEntity *m_pObject; // eax
  const char *Value; // eax
  CUtlReferenceVector<CMapEntity> Partial; // [esp+8h] [ebp-34h] BYREF
  CUtlReferenceVector<CMapEntity> Full; // [esp+1Ch] [ebp-20h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  memset(&Full, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Full,
    nGrowSize: 0,
    nInitSize: 0);
  Full.m_Size = 0;
  Full.m_pElements = nullptr;
  v7 = 3;
  memset(&Partial, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Partial,
    nGrowSize: 0,
    nInitSize: 0);
  Partial.m_Size = 0;
  Partial.m_pElements = nullptr;
  LOBYTE(v7) = 7;
  CToolPickEntity::GetSelectedEntities(this: pTool, EntityListFull: &Full, EntityListPartial: &Partial);
  m_pObject = (*Full.m_Memory.m_pMemory)->m_pObject;
  if ( m_pObject != nullptr )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: &m_pObject->m_KeyValues,
              pszKey: this->m_szKey,
              piIndex: nullptr);
    if ( Value == nullptr )
      Value = &var;
    COP_Entity::SetSmartControlText(this: this->m_pDlg, pszText: Value);
  }
  COP_Entity::StopPicking(this: this->m_pDlg);
  LOBYTE(v7) = 3;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Partial);
  v7 = -1;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Full);
}

//------------------------------------------------------------------------------
// Address: 0x100E3110
// Name: public: virtual void COP_Entity::MarkDataDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::MarkDataDirty(COP_Entity *this)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-14h]

  COP_Entity::UpdateDisplayClass(this, pClass: nullptr);
  m_hWnd = this->m_VarList.m_hWnd;
  this->m_pEditClass = nullptr;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_InstanceParmData.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100E3150
// Name: protected: virtual int COP_Entity::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Entity::OnInitDialog(COP_Entity *this)
{
  HWND__ *m_hWnd; // eax
  LONG v3; // eax
  HWND__ *v4; // ecx
  LRESULT v5; // eax

  CDialog::OnInitDialog(this);
  this->m_SmartControls.m_Size = 0;
  if ( this->m_SmartControls.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SmartControls.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_SmartControls.m_Memory.m_pMemory);
      this->m_SmartControls.m_Memory.m_pMemory = nullptr;
    }
    this->m_SmartControls.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SmartControls.m_pElements = this->m_SmartControls.m_Memory.m_pMemory;
  this->m_pDisplayClass = nullptr;
  this->m_pEditClass = nullptr;
  this->m_pLastSmartControlVar = nullptr;
  WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &this->m_kv);
  SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_InstanceParmData.m_Tree);
  memset(this->m_VarMap, 0xFFu, sizeof(this->m_VarMap));
  CWnd::SubclassDlgItem(this: &this->m_Angle, nID: 0x451u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_AngleEdit, nID: 0x453u, pParent: this);
  this->m_AngleEdit.m_pBox = &this->m_Angle;
  this->m_Angle.m_pEdit = &this->m_AngleEdit;
  CWnd::SubclassDlgItem(this: &this->m_SmartAngle, nID: 0x455u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_SmartAngleEdit, nID: 0x454u, pParent: this);
  this->m_SmartAngle.m_pEdit = &this->m_SmartAngleEdit;
  this->m_SmartAngleEdit.m_pBox = &this->m_SmartAngle;
  CFilteredComboBox::SubclassDlgItem(this: &this->m_cClasses, nID: 0x406u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cPickColor, nID: 0x574u, pParent: this);
  COP_Entity::LoadClassList(this);
  if ( this == (COP_Entity *)-560 )
    m_hWnd = nullptr;
  else
    m_hWnd = this->m_VarList.m_hWnd;
  v3 = GetWindowLongA(hWnd: m_hWnd, nIndex: -16) & 0xFFFFFBF0 | 0x40D;
  if ( this == (COP_Entity *)-560 )
    v4 = nullptr;
  else
    v4 = this->m_VarList.m_hWnd;
  SetWindowLongA(hWnd: v4, nIndex: -16, dwNewLong: v3);
  v5 = SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1037u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_VarList.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: v5 | 0x21);
  CListCtrl::InsertColumn(
    this: &this->m_VarList,
    nCol: 0,
    lpszColumnHeading: "Property Name",
    nFormat: 0,
    nWidth: 200,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_VarList,
    nCol: 1,
    lpszColumnHeading: "Value",
    nFormat: 0,
    nWidth: 150,
    nSubItem: -1);
  this->m_bWantSmartedit = true;
  COP_Entity::SetSmartedit(this, bSet: false);
  COP_Entity::UpdateAnchors(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E3330
// Name: protected: void COP_Entity::OnPaste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnPaste(COP_Entity *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  int Inorder; // eax
  int v4; // esi
  GDclass *v5; // eax
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+8h] [ebp-14h] BYREF
  int i; // [esp+Ch] [ebp-10h]
  int v9; // [esp+18h] [ebp-4h]

  if ( bKvClipEmpty == 0 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v9 = 1;
    COP_Entity::GetCurKey(this, strKey: &str);
    Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &kvClipboard.m_KeyValues.m_Elements.m_Tree);
    i = Inorder;
    if ( (unsigned __int16)Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        v4 = (unsigned __int16)Inorder;
        if ( strcmp(kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szKey, "xxxClassxxx") == 0 )
        {
          CFilteredComboBox::SelectItem(
            this: &this->m_cClasses,
            pStr: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue);
          COP_Entity::UpdateEditClass(
            this,
            pszClass: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue,
            bForce: false);
          v5 = GameData::ClassForName(
                 this: pGD,
                 pszName: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue,
                 piIndex: nullptr);
          COP_Entity::UpdateDisplayClass(this, pClass: v5);
        }
        else
        {
          WCKeyValuesT<WCKVBase_Dict>::SetValue(
            this: &this->m_kv,
            pszKey: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szKey,
            pszValue: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue);
          WCKeyValuesT<WCKVBase_Dict>::SetValue(
            this: &this->m_kvAdded,
            pszKey: kvClipboard.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szKey,
            pszValue: "1");
        }
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &kvClipboard.m_KeyValues.m_Elements.m_Tree,
              i);
        if ( i == 0xFFFF )
          break;
        LOWORD(Inorder) = i;
      }
    }
    COP_Entity::PresentProperties(this);
    m_pszData = str.m_pszData;
    COP_Entity::SetCurKey(this, pszKey: str.m_pszData);
    v9 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(a1: m_pszData - 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E34F0
// Name: protected: virtual void COP_Entity::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::OnTextChanged(COP_Entity *this, const char *pText)
{
  GDclass *v3; // eax

  this->m_PickEntityTarget.m_szKey[892] = 0;
  v3 = GameData::ClassForName(this: pGD, pszName: pText, piIndex: nullptr);
  COP_Entity::UpdateDisplayClass(this: (COP_Entity *)((char *)this - 184), pClass: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E3520
// Name: protected: static struct AFX_MSGMAP const __near * COP_Entity::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall COP_Entity::GetThisMessageMap()
{
  if ( (_S3_2 & 1) == 0 )
  {
    _S3_2 |= 1u;
    messageEntries_47[10].nID = 1009;
    messageEntries_47[10].nLastID = 1009;
    messageEntries_47[11].nID = 1009;
    messageEntries_47[11].nLastID = 1009;
    messageEntries_47[14].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeSmartcontrol;
    messageEntries_47[15].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeSmartcontrol;
    messageEntries_47[16].nID = 1010;
    messageEntries_47[16].nLastID = 1010;
    messageEntries_47[17].nID = 1686;
    messageEntries_47[17].nLastID = 1686;
    messageEntries_47[18].nID = 1121;
    messageEntries_47[18].nLastID = 1121;
    messageEntries_47[19].nID = 1303;
    messageEntries_47[19].nLastID = 1303;
    messageEntries_47[9].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnSize;
    messageEntries_47[10].nMessage = 273;
    messageEntries_47[10].nCode = 256;
    messageEntries_47[10].nSig = 57;
    messageEntries_47[10].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnSetfocusKey;
    messageEntries_47[11].nMessage = 273;
    messageEntries_47[11].nCode = 512;
    messageEntries_47[11].nSig = 57;
    messageEntries_47[11].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnKillfocusKey;
    messageEntries_47[12].nMessage = 1029;
    messageEntries_47[12].nCode = 0;
    messageEntries_47[12].nID = 0;
    messageEntries_47[12].nLastID = 0;
    messageEntries_47[12].nSig = 14;
    messageEntries_47[12].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeAngleBox;
    messageEntries_47[13].nMessage = 273;
    messageEntries_47[13].nCode = 1;
    messageEntries_47[13].nID = 1;
    messageEntries_47[13].nLastID = 1;
    messageEntries_47[13].nSig = 57;
    messageEntries_47[13].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeSmartcontrolSel;
    messageEntries_47[14].nMessage = 273;
    messageEntries_47[14].nCode = 6;
    messageEntries_47[14].nID = 1;
    messageEntries_47[14].nLastID = 1;
    messageEntries_47[14].nSig = 57;
    messageEntries_47[15].nMessage = 273;
    messageEntries_47[15].nCode = 768;
    messageEntries_47[15].nID = 1;
    messageEntries_47[15].nLastID = 1;
    messageEntries_47[15].nSig = 57;
    messageEntries_47[16].nMessage = 273;
    messageEntries_47[16].nCode = 0;
    messageEntries_47[16].nSig = 57;
    messageEntries_47[16].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnBrowse;
    messageEntries_47[17].nMessage = 273;
    messageEntries_47[17].nCode = 0;
    messageEntries_47[17].nSig = 57;
    messageEntries_47[17].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnBrowseInstance;
    messageEntries_47[18].nMessage = 273;
    messageEntries_47[18].nCode = 0;
    messageEntries_47[18].nSig = 57;
    messageEntries_47[18].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnPlaySound;
    messageEntries_47[19].nMessage = 273;
    messageEntries_47[19].nCode = 0;
    messageEntries_47[19].nSig = 57;
    messageEntries_47[19].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnMark;
    messageEntries_47[20].nMessage = 273;
    messageEntries_47[20].nCode = 0;
    messageEntries_47[20].nID = 1302;
    messageEntries_47[20].nLastID = 1302;
    messageEntries_47[20].nSig = 57;
    messageEntries_47[20].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnMarkAndAdd;
    messageEntries_47[21].nID = 1533;
    messageEntries_47[21].nLastID = 1533;
    messageEntries_47[22].nID = 1497;
    messageEntries_47[22].nLastID = 1497;
    messageEntries_47[23].nID = 1535;
    messageEntries_47[23].nLastID = 1535;
    messageEntries_47[24].nID = 1534;
    messageEntries_47[24].nLastID = 1534;
    messageEntries_47[25].nID = 1215;
    messageEntries_47[25].nLastID = 1215;
    messageEntries_47[26].nID = 3;
    messageEntries_47[26].nLastID = 3;
    messageEntries_47[27].nID = 4;
    messageEntries_47[27].nLastID = 4;
    messageEntries_47[28].nID = 5;
    messageEntries_47[28].nLastID = 5;
    messageEntries_47[29].nCode = 1;
    messageEntries_47[29].nID = 5;
    messageEntries_47[29].nLastID = 5;
    messageEntries_47[30].nID = 5;
    messageEntries_47[30].nLastID = 5;
    messageEntries_47[21].nMessage = 273;
    messageEntries_47[21].nCode = 0;
    messageEntries_47[21].nSig = 57;
    messageEntries_47[21].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnPickFaces;
    messageEntries_47[22].nMessage = 273;
    messageEntries_47[22].nCode = 0;
    messageEntries_47[22].nSig = 57;
    messageEntries_47[22].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnEntityHelp;
    messageEntries_47[23].nMessage = 273;
    messageEntries_47[23].nCode = 0;
    messageEntries_47[23].nSig = 57;
    messageEntries_47[23].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnPickAngles;
    messageEntries_47[24].nMessage = 273;
    messageEntries_47[24].nCode = 0;
    messageEntries_47[24].nSig = 57;
    messageEntries_47[24].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnPickEntity;
    messageEntries_47[25].nMessage = 273;
    messageEntries_47[25].nCode = 0;
    messageEntries_47[25].nSig = 57;
    messageEntries_47[25].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnCameraDistance;
    messageEntries_47[26].nMessage = 273;
    messageEntries_47[26].nCode = 768;
    messageEntries_47[26].nSig = 57;
    messageEntries_47[26].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceVariableControl;
    messageEntries_47[27].nMessage = 273;
    messageEntries_47[27].nCode = 768;
    messageEntries_47[27].nSig = 57;
    messageEntries_47[27].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceVariableControl;
    messageEntries_47[28].nMessage = 273;
    messageEntries_47[28].nCode = 768;
    messageEntries_47[28].nSig = 57;
    messageEntries_47[28].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceParmControl;
    messageEntries_47[29].nMessage = 273;
    messageEntries_47[29].nSig = 57;
    messageEntries_47[29].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceParmControl;
    messageEntries_47[30].nMessage = 273;
    messageEntries_47[30].nCode = 6;
    messageEntries_47[30].nSig = 57;
    messageEntries_47[30].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceParmControl;
    messageEntries_47[31].nMessage = 273;
    messageEntries_47[31].nCode = 768;
    messageEntries_47[31].nID = 6;
    messageEntries_47[31].nLastID = 6;
    messageEntries_47[31].nSig = 57;
    messageEntries_47[31].pfn = (void (__thiscall *)(CCmdTarget *))COP_Entity::OnChangeInstanceParmControl;
    messageEntries_47[32].nMessage = 0;
    messageEntries_47[32].nCode = 0;
    messageEntries_47[32].nID = 0;
    messageEntries_47[32].nLastID = 0;
    messageEntries_47[32].nSig = 0;
    messageEntries_47[32].pfn = nullptr;
  }
  return &messageMap_7;
}

//------------------------------------------------------------------------------
// Address: 0x100E3970
// Name: public: virtual void COP_Entity::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Entity::UpdateData(
        COP_Entity *this,
        unsigned int Mode,
        CEditGameClass *pData,
        const char *bCanEdit)
{
  HWND Focus; // eax
  char *m_szClass; // eax
  char v8; // cl
  const char *v9; // eax
  unsigned __int16 i; // di
  int v11; // eax
  const char *v12; // ecx
  const char *v13; // eax
  GDclass *v14; // eax
  GDclass *v15; // eax
  const char *m_pszComments; // eax
  char szComments[1024]; // [esp+Ch] [ebp-618h] BYREF
  char szBuf[512]; // [esp+40Ch] [ebp-218h] BYREF
  QAngle vecAngles; // [esp+60Ch] [ebp-18h] BYREF
  int v20; // [esp+620h] [ebp-4h]
  const char *pDataa; // [esp+630h] [ebp+Ch]

  CObjectPage::UpdateData(this, Mode, pData, (bool)bCanEdit);
  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    Focus = GetFocus();
    if ( CWnd::FromHandle(hWnd: Focus) == &this->m_cKey )
      COP_Entity::OnKillfocusKey(this);
    if ( Mode == 2 )
    {
      WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &this->m_kvAdded);
      this->m_bAllowPresentProperties = true;
      COP_Entity::PresentProperties(this);
    }
    else
    {
      if ( Mode <= 1 )
        this->m_bAllowPresentProperties = false;
      if ( pData != nullptr )
      {
        if ( Mode != 0 )
        {
          if ( Mode == 1 )
          {
            CFilteredComboBox::GetCurrentItem(
              this: &this->m_cClasses,
              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit);
            v20 = 1;
            if ( this->m_bClassSelectionEmpty )
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit,
                pszSrc: &var);
            if ( _V_stricmp(s1: bCanEdit, s2: pData->m_szClass) != 0 )
            {
              CFilteredComboBox::ForceEditControlText(this: &this->m_cClasses, pStr: &var);
              this->m_bClassSelectionEmpty = true;
              COP_Entity::UpdateEditClass(this, pszClass: &var, bForce: false);
              v15 = GameData::ClassForName(this: pGD, pszName: &var, piIndex: nullptr);
              COP_Entity::UpdateDisplayClass(this, pClass: v15);
            }
            else
            {
              COP_Entity::LoadClassList(this);
              CFilteredComboBox::SelectItem(this: &this->m_cClasses, pStr: pData->m_szClass);
            }
            CWnd::GetWindowTextA(this: &this->m_Comments, lpszString: szComments, nMaxCount: 1024);
            m_pszComments = pData->m_pszComments;
            if ( m_pszComments == nullptr )
              m_pszComments = CEditGameClass::g_pszEmpty;
            if ( strcmp(szComments, m_pszComments) != 0 )
              CWnd::SetWindowTextA(
                this: &this->m_Comments,
                lpszString: (const char *)CObjectPage::VALUE_DIFFERENT_STRING);
            COP_Entity::MergeObjectKeyValues(this, pEdit: pData);
            COP_Entity::SetCurKey(this, pszKey: this->m_strLastKey.m_pszData);
            v20 = -1;
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit);
          }
        }
        else
        {
          COP_Entity::LoadClassList(this);
          this->m_nNewKeyCount = 1;
          pData->GetAngles(this: pData, a2: &vecAngles);
          CAngleBox::SetAngles(this: &this->m_Angle, &vecAngles, bRedraw: false);
          CAngleBox::SetDifferent(this: &this->m_Angle, bDifferent: false, bRedraw: true);
          m_szClass = pData->m_szClass;
          pDataa = pData->m_szClass;
          do
          {
            v8 = *m_szClass;
            m_szClass[szBuf - pData->m_szClass] = *m_szClass;
            ++m_szClass;
          }
          while ( v8 != 0 );
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit,
            pszSrc: szBuf);
          v20 = 0;
          CFilteredComboBox::AddSuggestion(
            this: &this->m_cClasses,
            suggestion: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit);
          v20 = -1;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bCanEdit);
          CFilteredComboBox::SelectItem(this: &this->m_cClasses, pStr: szBuf);
          this->m_bClassSelectionEmpty = false;
          if ( CEditGameClass::IsClass(this: pData, pszClass: "worldspawn") || !this->m_bCanEdit )
            CFilteredComboBox::EnableWindow(this: &this->m_cClasses, bEnable: false);
          else
            CFilteredComboBox::EnableWindow(this: &this->m_cClasses, bEnable: true);
          v9 = pData->m_pszComments;
          if ( v9 == nullptr )
            v9 = CEditGameClass::g_pszEmpty;
          CWnd::SetWindowTextA(this: &this->m_Comments, lpszString: v9);
          WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &this->m_kv);
          for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pData->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
                i != 0xFFFF;
                i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                      this: &pData->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                      i) )
          {
            v11 = (int)&pData->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[i];
            v12 = (const char *)(v11 + 12);
            v13 = (const char *)(v11 + 92);
            if ( v12 != nullptr && v13 != nullptr )
              WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_kv, pszKey: v12, pszValue: v13);
          }
          COP_Entity::UpdateEditClass(this, pszClass: pDataa, bForce: true);
          v14 = GameData::ClassForName(this: pGD, pszName: pDataa, piIndex: nullptr);
          COP_Entity::UpdateDisplayClass(this, pClass: v14);
          COP_Entity::SetCurKey(this, pszKey: this->m_strLastKey.m_pszData);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3CF0
// Name: public: virtual bool COP_Entity::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Entity::SaveData(COP_Entity *this, SaveData_Reason_t reason)
{
  COP_Entity *v2; // ebx
  void (__thiscall *RememberState)(CObjectPage *); // edx
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  void *v7; // edx
  CEditGameClass *v8; // esi
  int Inorder; // edi
  int szKey; // esi
  CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // ebx
  unsigned __int16 v12; // si
  unsigned __int16 v13; // ax
  int v14; // esi
  int v15; // edi
  CEditGameClass *v16; // esi
  unsigned int v17; // kr00_4
  char *v18; // eax
  char *v19; // ecx
  int v20; // edx
  char v21; // al
  GDclass *v22; // eax
  char *v23; // eax
  char szComments[1024]; // [esp+8h] [ebp-42Ch] BYREF
  CMapClass *pObject; // [esp+408h] [ebp-2Ch]
  int pos; // [esp+40Ch] [ebp-28h]
  CUtlReference<CMapClass> *m_pHead; // [esp+410h] [ebp-24h] BYREF
  CUtlReference<CMapClass> *v29; // [esp+414h] [ebp-20h]
  void *inptr; // [esp+418h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strClassName; // [esp+41Ch] [ebp-18h] BYREF
  CEditGameClass *pEdit; // [esp+420h] [ebp-14h]
  COP_Entity *v33; // [esp+424h] [ebp-10h]
  int v34; // [esp+430h] [ebp-4h]

  v2 = this;
  RememberState = this->RememberState;
  v33 = this;
  ((void (__fastcall *)(COP_Entity *))RememberState)(a1: this);
  CFilteredComboBox::GetCurrentItem(this: &v2->m_cClasses, result: &strClassName);
  v34 = 0;
  if ( v2->m_bClassSelectionEmpty )
    ATL::CSimpleStringT<char,0>::SetString(this: &strClassName, pszSrc: &var, nLength: 0);
  COP_Entity::UpdateEditClass(this: v2, pszClass: strClassName.m_pszData, bForce: false);
  m_pObjectList = v2->m_pObjectList;
  for ( pos = 0; pos < m_pObjectList->m_Size; ++pos )
  {
    m_pObject = m_pObjectList->m_Memory.m_pMemory[pos >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)][pos & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      inptr = m_pObjectList->m_Memory.m_pMemory[pos >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)][pos & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v6 = m_pObject->m_References.m_pHead;
      if ( v6 != nullptr )
        v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v29 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v7 = inptr;
    pObject = (CMapClass *)inptr;
    LOBYTE(v34) = 0;
    if ( inptr != nullptr )
    {
      if ( v29 != nullptr )
      {
        v29->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v29;
      }
      else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
      {
        *((_DWORD *)inptr + 8) = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v29 = nullptr;
      m_pHead = nullptr;
      inptr = nullptr;
    }
    v8 = (CEditGameClass *)__RTDynamicCast(
                             inptr: v7,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CEditGameClass `RTTI Type Descriptor',
                             isReference: 0);
    pEdit = v8;
    if ( v8 != nullptr )
    {
      COP_Entity::RemoveBlankKeys(this: v2);
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_kv.m_KeyValues.m_Elements.m_Tree);
      if ( Inorder != 0xFFFF )
      {
        do
        {
          szKey = (int)v2->m_kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem.szKey;
          if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(
                 this: &v2->m_kvAdded,
                 pszKey: (const char *)szKey,
                 piIndex: nullptr) != nullptr )
          {
            V_FixSlashes(pname: (char *)(szKey + 80), separator: 47);
            if ( strcmp((const char *)(szKey + 80), (const char *)CObjectPage::VALUE_DIFFERENT_STRING) != 0 )
              COP_Entity::ApplyKeyValueToObject(
                this: v33,
                pObject: pEdit,
                pszKey: (const char *)szKey,
                pszValue: (const char *)(szKey + 80));
            v2 = v33;
          }
          Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                      this: &v2->m_kv.m_KeyValues.m_Elements.m_Tree,
                      i: Inorder);
        }
        while ( Inorder != 0xFFFF );
        v8 = pEdit;
      }
      p_m_Tree = &v8->m_KeyValues.m_KeyValues.m_Elements.m_Tree;
      v12 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v8->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
      if ( v12 != 0xFFFF )
      {
        do
        {
          v13 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: p_m_Tree,
                  i: v12);
          v14 = v12;
          v15 = v13;
          if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(
                 this: &v33->m_kv,
                 pszKey: pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v14].m_Data.elem.szKey,
                 piIndex: nullptr) == nullptr )
            ((void (__stdcall *)(MDkeyvalue *))pEdit->DeleteKeyValue)(a1: &pEdit->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v14].m_Data.elem);
          v12 = v15;
        }
        while ( v15 != 0xFFFF );
      }
      if ( *((int *)strClassName.m_pszData - 3) < 0 )
        ATL::AtlThrowImpl(hr: -2147024809);
      v16 = pEdit;
      if ( *strClassName.m_pszData != 0 )
        pEdit->SetClass(this: pEdit, a2: strClassName.m_pszData, a3: false);
      szComments[0] = 0;
      CWnd::GetWindowTextA(this: &v33->m_Comments, lpszString: szComments, nMaxCount: 1024);
      if ( strcmp(szComments, (const char *)CObjectPage::VALUE_DIFFERENT_STRING) != 0 )
      {
        operator delete(p: v16->m_pszComments);
        v17 = strlen(szComments);
        if ( v17 != 0 )
        {
          v18 = (char *)operator new[](nSize: v17 + 1);
          v19 = szComments;
          v16->m_pszComments = v18;
          v20 = v18 - szComments;
          do
          {
            v21 = *v19;
            v19[v20] = *v19;
            ++v19;
          }
          while ( v21 != 0 );
        }
        else
        {
          v16->m_pszComments = nullptr;
        }
      }
      v2 = v33;
    }
    pObject->PostUpdate(this: pObject, a2: Notify_Changed);
    m_pObjectList = v2->m_pObjectList;
  }
  v22 = GameData::ClassForName(this: pGD, pszName: strClassName.m_pszData, piIndex: nullptr);
  COP_Entity::UpdateDisplayClass(this: v2, pClass: v22);
  v34 = -1;
  v23 = strClassName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strClassName.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v23 + 4))(a1: v23);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E40A0
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Entity::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall COP_Entity::GetMessageMap(COP_Entity *this)
{
  return COP_Entity::GetThisMessageMap();
}

//------------------------------------------------------------------------------
// Address: 0x103504AC
// Name: protected: void CPropertyPage::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::Cleanup(CPropertyPage *this)
{
  COccManager *m_pOccManager; // eax

  m_pOccManager = AfxGetModuleState()->m_pOccManager;
  if ( m_pOccManager != nullptr && this->m_pOccDialogInfo != nullptr )
  {
    m_pOccManager->PostCreateDialog(this: m_pOccManager, a2: this->m_pOccDialogInfo);
    free(pMem: this->m_pOccDialogInfo);
    this->m_pOccDialogInfo = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10424E1E
// Name: protected: int CMFCImageEditorDialog::OnPickColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCImageEditorDialog::OnPickColor(CMFCImageEditorDialog *this, unsigned int color)
{
  CMFCColorBar::SetColor(this: &this->m_wndColorBar, color);
  CMFCImagePaintArea::SetColor(this: &this->m_wndLargeDrawArea, color);
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_PEN;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D8250
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t,unsigned short,class CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10424E51
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolPaste(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolPaste(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  CCmdUI_vtbl *v2; // esi
  BOOL v3; // eax

  v2 = pCmdUI->__vftable;
  v3 = IsClipboardFormatAvailable(format: 2u);
  v2->Enable(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10424E70
// Name: protected: void CMFCImageEditorDialog::OnToolEllipse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolEllipse(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_ELLIPSE;
}

//------------------------------------------------------------------------------
// Address: 0x10424E7B
// Name: protected: void CMFCImageEditorDialog::OnToolFill(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolFill(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_FILL;
}

//------------------------------------------------------------------------------
// Address: 0x10424E86
// Name: protected: void CMFCImageEditorDialog::OnToolLine(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolLine(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_LINE;
}

//------------------------------------------------------------------------------
// Address: 0x10424E91
// Name: protected: void CMFCImageEditorDialog::OnToolPen(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolPen(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_PEN;
}

//------------------------------------------------------------------------------
// Address: 0x10424E99
// Name: protected: void CMFCImageEditorDialog::OnToolPick(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolPick(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_COLOR;
}

//------------------------------------------------------------------------------
// Address: 0x10424EA4
// Name: protected: void CMFCImageEditorDialog::OnToolRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolRect(CMFCImageEditorDialog *this)
{
  this->m_wndLargeDrawArea.m_Mode = IMAGE_EDIT_MODE_RECT;
}

//------------------------------------------------------------------------------
// Address: 0x10424EAF
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolEllipse(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolEllipse(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_ELLIPSE);
}

//------------------------------------------------------------------------------
// Address: 0x10424ED1
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolFill(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolFill(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_FILL);
}

//------------------------------------------------------------------------------
// Address: 0x10424EF3
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolLine(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolLine(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_LINE);
}

//------------------------------------------------------------------------------
// Address: 0x10424F15
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolPen(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolPen(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_PEN);
}

//------------------------------------------------------------------------------
// Address: 0x10424F36
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolPick(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolPick(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_COLOR);
}

//------------------------------------------------------------------------------
// Address: 0x10424F58
// Name: protected: void CMFCImageEditorDialog::OnUpdateToolRect(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnUpdateToolRect(CMFCImageEditorDialog *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: this->m_wndLargeDrawArea.m_Mode == IMAGE_EDIT_MODE_RECT);
}

//------------------------------------------------------------------------------
// Address: 0x10424F7A
// Name: protected: virtual void CMFCImageEditorDialog::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::DoDataExchange(CMFCImageEditorDialog *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 16516, rControl: &this->m_wndColorPickerLocation);
  DDX_Control(pDX, nIDC: 16533, rControl: &this->m_wndPaletteBarLocation);
  DDX_Control(pDX, nIDC: 16519, rControl: &this->m_wndPreview);
  DDX_Control(pDX, nIDC: 16513, rControl: &this->m_wndLargeDrawArea);
}

//------------------------------------------------------------------------------
// Address: 0x10424FD4
// Name: protected: void CMFCImageEditorDialog::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnPaint(CMFCImageEditorDialog *this)
{
  HDC CompatibleDC; // eax
  CBitmap *m_pBitmap; // eax
  CGdiObject *v4; // ebx
  CDC v5; // [esp+10h] [ebp-74h] BYREF
  CPaintDC v6; // [esp+20h] [ebp-64h] BYREF
  int v7; // [esp+80h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v6, pWnd: this);
  v7 = 0;
  FillRect(hDC: v6.m_hDC, lprc: &this->m_rectPreviewFrame, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  CDC::CDC(this: &v5);
  LOBYTE(v7) = 1;
  CompatibleDC = CreateCompatibleDC(hdc: v6.m_hDC);
  CDC::Attach(this: &v5, hDC: CompatibleDC);
  m_pBitmap = this->m_pBitmap;
  if ( m_pBitmap != nullptr )
    m_pBitmap = (CBitmap *)m_pBitmap->m_hObject;
  v4 = CDC::SelectGdiObject(hDC: v5.m_hDC, h: m_pBitmap);
  BitBlt(
    hdc: v6.m_hDC,
    x: this->m_rectPreviewImage.left,
    y: this->m_rectPreviewImage.top,
    cx: this->m_sizeImage.cx,
    cy: this->m_sizeImage.cy,
    hdcSrc: v5.m_hDC,
    x1: 0,
    y1: 0,
    rop: 0xCC0020u);
  CDC::Draw3dRect(
    this: &v6,
    lpRect: &this->m_rectPreviewFrame,
    clrTopLeft: afxGlobalData.clrBtnHilite,
    clrBottomRight: afxGlobalData.clrBtnShadow);
  if ( v4 != nullptr )
    v4 = (CGdiObject *)v4->m_hObject;
  CDC::SelectGdiObject(hDC: v5.m_hDC, h: v4);
  CDC::DeleteDC(this: &v5);
  LOBYTE(v7) = 0;
  CDC::~CDC(this: &v5);
  v7 = -1;
  CPaintDC::~CPaintDC(this: &v6);
}

//------------------------------------------------------------------------------
// Address: 0x104250B7
// Name: protected: void CMFCImageEditorDialog::OnToolClear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolClear(CMFCImageEditorDialog *this)
{
  HDC CompatibleDC; // eax
  CBitmap *m_pBitmap; // eax
  void *m_hObject; // eax
  CGdiObject *v5; // eax
  int cx; // ecx
  CGdiObject *v7; // edi
  void *v8; // edi
  CWindowDC v9; // [esp+10h] [ebp-44h] BYREF
  CDC v10; // [esp+24h] [ebp-30h] BYREF
  RECT rc; // [esp+34h] [ebp-20h] BYREF
  int v12; // [esp+50h] [ebp-4h]

  CWindowDC::CWindowDC(this: &v9, pWnd: this);
  v12 = 0;
  CDC::CDC(this: &v10);
  LOBYTE(v12) = 1;
  CompatibleDC = CreateCompatibleDC(hdc: v9.m_hDC);
  CDC::Attach(this: &v10, hDC: CompatibleDC);
  m_pBitmap = this->m_pBitmap;
  if ( m_pBitmap != nullptr )
    m_hObject = m_pBitmap->m_hObject;
  else
    m_hObject = nullptr;
  v5 = CDC::SelectGdiObject(hDC: v10.m_hDC, h: m_hObject);
  cx = this->m_sizeImage.cx;
  v7 = v5;
  rc.bottom = this->m_sizeImage.cy;
  rc.left = 0;
  rc.top = 0;
  rc.right = cx;
  FillRect(hDC: v10.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  if ( v7 != nullptr )
    v8 = v7->m_hObject;
  else
    v8 = nullptr;
  CDC::SelectGdiObject(hDC: v10.m_hDC, h: v8);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectPreviewImage, bErase: true);
  InvalidateRect(hWnd: this->m_wndLargeDrawArea.m_hWnd, lpRect: nullptr, bErase: true);
  LOBYTE(v12) = 0;
  CDC::~CDC(this: &v10);
  v12 = -1;
  CWindowDC::~CWindowDC(this: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x10425188
// Name: protected: void CMFCImageEditorDialog::OnToolPaste(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolPaste(CMFCImageEditorDialog *this)
{
  CGdiObject *v2; // eax
  HDC CompatibleDC; // eax
  HDC v4; // eax
  CGdiObject *v5; // edi
  CBitmap *m_pBitmap; // eax
  void *m_hObject; // eax
  int cx; // ecx
  int v9; // ecx
  int cy; // edi
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  tagSTGMEDIUM StgMedium; // [esp+10h] [ebp-80h] BYREF
  _BYTE pv[4]; // [esp+1Ch] [ebp-74h] BYREF
  int v16; // [esp+20h] [ebp-70h]
  int v17; // [esp+24h] [ebp-6Ch]
  CGdiObject *v18; // [esp+34h] [ebp-5Ch]
  CGdiObject *v19; // [esp+38h] [ebp-58h]
  CDC v20; // [esp+3Ch] [ebp-54h] BYREF
  CDC pDcSrc; // [esp+4Ch] [ebp-44h] BYREF
  COleDataObject v22; // [esp+5Ch] [ebp-34h] BYREF
  int nXDest; // [esp+6Ch] [ebp-24h]
  RECT rc; // [esp+70h] [ebp-20h] BYREF
  int v25; // [esp+8Ch] [ebp-4h]

  COleDataObject::COleDataObject(this: &v22);
  v25 = 0;
  if ( COleDataObject::AttachClipboard(this: &v22) != 0
    && COleDataObject::IsDataAvailable(this: &v22, cfFormat: 2u, lpFormatEtc: nullptr) != 0
    && COleDataObject::GetData(this: &v22, cfFormat: 2u, lpStgMedium: &StgMedium, lpFormatEtc: nullptr) != 0
    && (v2 = CGdiObject::FromHandle(h: StgMedium.hBitmap), nXDest = (int)v2, v2 != nullptr) )
  {
    GetObjectA(h: v2->m_hObject, c: 24, pv);
    CDC::CDC(this: &v20);
    LOBYTE(v25) = 1;
    CDC::CDC(this: &pDcSrc);
    LOBYTE(v25) = 2;
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &pDcSrc, hDC: CompatibleDC);
    v4 = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &v20, hDC: v4);
    v5 = CDC::SelectGdiObject(hDC: pDcSrc.m_hDC, h: *(void **)(nXDest + 4));
    v18 = v5;
    if ( v5 != nullptr )
    {
      m_pBitmap = this->m_pBitmap;
      if ( m_pBitmap != nullptr )
        m_hObject = m_pBitmap->m_hObject;
      else
        m_hObject = nullptr;
      v19 = CDC::SelectGdiObject(hDC: v20.m_hDC, h: m_hObject);
      if ( v19 != nullptr )
      {
        cx = this->m_sizeImage.cx;
        rc.bottom = this->m_sizeImage.cy;
        rc.left = 0;
        rc.top = 0;
        rc.right = cx;
        FillRect(hDC: v20.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
        v9 = this->m_sizeImage.cx;
        nXDest = 0;
        if ( (v9 - v16) / 2 >= 0 )
          nXDest = (v9 - v16) / 2;
        cy = this->m_sizeImage.cy;
        if ( (cy - v17) / 2 >= 0 )
          v11 = (this->m_sizeImage.cy - v17) / 2;
        else
          v11 = 0;
        v12 = v9 - nXDest;
        if ( v12 >= v16 )
          v12 = v16;
        v13 = cy - v11;
        if ( cy - v11 >= v17 )
          v13 = v17;
        if ( v12 > 0 && v13 > 0 )
          CMFCToolBarImages::TransparentBlt(
            hdcDest: v20.m_hDC,
            nXDest,
            nYDest: v11,
            nWidth: v12,
            nHeight: v13,
            &pDcSrc,
            nXSrc: 0,
            nYSrc: 0,
            colorTransparent: 0xC0C0C0u,
            nWidthDest: -1,
            nHeightDest: -1);
        CDC::SelectGdiObject(hDC: v20.m_hDC, h: v19->m_hObject);
        CDC::SelectGdiObject(hDC: pDcSrc.m_hDC, h: v18->m_hObject);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectPreviewImage, bErase: true);
        InvalidateRect(hWnd: this->m_wndLargeDrawArea.m_hWnd, lpRect: nullptr, bErase: true);
      }
      else
      {
        AfxMessageBox(nIDPrompt: 0x3E84u, nType: 0, nIDHelp: 0xFFFFFFFF);
        CDC::SelectGdiObject(hDC: pDcSrc.m_hDC, h: v5->m_hObject);
      }
    }
    else
    {
      AfxMessageBox(nIDPrompt: 0x3E84u, nType: 0, nIDHelp: 0xFFFFFFFF);
    }
    LOBYTE(v25) = 1;
    CDC::~CDC(this: &pDcSrc);
    LOBYTE(v25) = 0;
    CDC::~CDC(this: &v20);
  }
  else
  {
    AfxMessageBox(nIDPrompt: 0x3E84u, nType: 0, nIDHelp: 0xFFFFFFFF);
  }
  v25 = -1;
  COleDataObject::Release(this: &v22);
}

//------------------------------------------------------------------------------
// Address: 0x10425399
// Name: Create16ColorsStdPalette
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall Create16ColorsStdPalette(CPalette *pal@<edi>)
{
  HGDIOBJ StockObject; // eax
  CGdiObject *v2; // ebx
  LOGPALETTE *v3; // esi
  HPALETTE Palette; // eax
  signed int v5; // esi
  tagPALETTEENTRY palEntry; // [esp+4h] [ebp-8h] BYREF
  int iDest; // [esp+8h] [ebp-4h]

  StockObject = GetStockObject(i: 15);
  v2 = CGdiObject::FromHandle(h: StockObject);
  if ( v2 != nullptr )
  {
    v3 = (LOGPALETTE *)operator new(nSize: 0x48u);
    v3->palVersion = 768;
    v3->palNumEntries = 16;
    Palette = CreatePalette(plpal: v3);
    CGdiObject::Attach(this: pal, hObject: Palette);
    operator delete(p: v3);
    v5 = 0;
    iDest = 0;
    do
    {
      if ( v5 < 8 || v5 >= 12 )
      {
        GetPaletteEntries(hpal: (HPALETTE)v2->m_hObject, iStart: v5, cEntries: 1u, pPalEntries: &palEntry);
        SetPaletteEntries(hpal: (HPALETTE)pal->m_hObject, iStart: iDest++, cEntries: 1u, pPalEntries: &palEntry);
      }
      ++v5;
    }
    while ( v5 < 20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10425423
// Name: protected: virtual int CMFCImageEditorDialog::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCImageEditorDialog::OnInitDialog(CMFCImageEditorDialog *this)
{
  CWnd *MainWnd; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSize *ButtonSize; // eax
  bool v7; // cc
  CPalette *p_pal; // eax
  int cx; // ecx
  int cy; // edi
  int v11; // eax
  int v12; // eax
  int *v13; // esi
  CWnd *v14; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  HWND__ *v17; // [esp-8h] [ebp-74h]
  HWND__ *v18; // [esp-8h] [ebp-74h]
  HWND__ *v19; // [esp-8h] [ebp-74h]
  CBitmap *m_pBitmap; // [esp-4h] [ebp-70h]
  _BYTE v21[4]; // [esp+10h] [ebp-5Ch] BYREF
  int v22; // [esp+14h] [ebp-58h]
  CWnd *p_m_wndLargeDrawArea; // [esp+18h] [ebp-54h]
  CPalette pal; // [esp+1Ch] [ebp-50h] BYREF
  CSize v25; // [esp+24h] [ebp-48h] BYREF
  tagRECT v26; // [esp+2Ch] [ebp-40h] BYREF
  tagRECT Rect; // [esp+3Ch] [ebp-30h] BYREF
  tagRECT rc; // [esp+4Ch] [ebp-20h] BYREF
  int v29; // [esp+68h] [ebp-4h]

  CDialog::OnInitDialog(this);
  if ( AfxGetMainWnd() != nullptr )
  {
    MainWnd = AfxGetMainWnd();
    if ( (CWnd::GetExStyle(this: MainWnd) & 0x400000) != 0 )
      CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: 0x400000u, nFlags: 0);
  }
  m_pBitmap = this->m_pBitmap;
  p_m_wndLargeDrawArea = &this->m_wndLargeDrawArea;
  CMFCImagePaintArea::SetBitmap(this: &this->m_wndLargeDrawArea, pBitmap: m_pBitmap);
  m_hWnd = this->m_wndPaletteBarLocation.m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
  v17 = this->m_wndPaletteBarLocation.m_hWnd;
  memset(&rc, 0, sizeof(rc));
  GetClientRect(hWnd: v17, lpRect: &rc);
  MapWindowPoints(
    hWndFrom: this->m_wndPaletteBarLocation.m_hWnd,
    hWndTo: this->m_hWnd,
    lpPoints: (LPPOINT)&rc,
    cPoints: 2u);
  InflateRect(lprc: &rc, dx: -2, dy: -2);
  CMFCToolBar::EnableLargeIcons(this: &this->m_wndPaletteBar, bEnable: 0);
  this->m_wndPaletteBar.Create(this: &this->m_wndPaletteBar, a2: this, a3: 1346381832u, a4: 59392u);
  v3 = AFX_GLOBAL_DATA::Is32BitIcons(this: &afxGlobalData);
  this->m_wndPaletteBar.LoadToolBar(
    this: &this->m_wndPaletteBar,
    a2: 16138u,
    a3: 0,
    a4: 0,
    a5: 1,
    a6: 0,
    a7: 0,
    a8: v3 != 0 ? 0x3F0Bu : 0);
  v25.cy = (int)this->m_wndPaletteBar.__vftable;
  v4 = (*(int (__thiscall **)(CMFCImageEditorPaletteBar *))(v25.cy + 444))(a1: &this->m_wndPaletteBar);
  (*(void (__thiscall **)(CMFCImageEditorPaletteBar *, int))(v25.cy + 480))(a1: &this->m_wndPaletteBar, a2: v4 | 0x30);
  v25.cy = (int)this->m_wndPaletteBar.__vftable;
  v5 = (*(int (__thiscall **)(CMFCImageEditorPaletteBar *))(v25.cy + 444))(a1: &this->m_wndPaletteBar);
  (*(void (__thiscall **)(CMFCImageEditorPaletteBar *, unsigned int))(v25.cy + 480))(
    a1: &this->m_wndPaletteBar,
    a2: v5 & 0xFFBFF0FF);
  CPane::SetBorders(this: &this->m_wndPaletteBar, cxLeft: 10, cyTop: 5, cxRight: 10, cyBottom: 5);
  ButtonSize = CMFCToolBar::GetButtonSize(this: &this->m_wndPaletteBar, a2: 0, result: &v25);
  CMFCToolBar::WrapToolBar(
    this: &this->m_wndPaletteBar,
    nWidth: 3 * ButtonSize->cx,
    nHeight: 0x7FFF,
    pDC: nullptr,
    nColumnWidth: -1,
    nRowHeight: -1);
  this->m_wndPaletteBar.CalcSize(this: &this->m_wndPaletteBar, result: (CSize *)v21, a3: 0);
  rc.bottom = v22 + rc.top + 10;
  this->m_wndPaletteBar.MoveWindow(this: &this->m_wndPaletteBar, a2: (CRect *)&rc, a3: 1, a4: nullptr);
  if ( rc.bottom - rc.top > Rect.bottom - Rect.top )
    CWnd::SetWindowPos(
      this: &this->m_wndPaletteBarLocation,
      pWndInsertAfter: nullptr,
      x: -1,
      y: -1,
      cx: Rect.right - Rect.left,
      cy: rc.bottom - rc.top + 7,
      nFlags: 0x16u);
  this->m_wndPaletteBar.SetWindowPos(
    this: &this->m_wndPaletteBar,
    a2: &CWnd::wndTop,
    a3: -1,
    a4: -1,
    a5: -1,
    a6: -1,
    a7: 19u,
    a8: nullptr);
  this->m_wndPaletteBar.m_hWndOwner = this->m_hWnd;
  v18 = this->m_wndColorPickerLocation.m_hWnd;
  this->m_wndPaletteBar.m_bRouteCommandsViaFrame = 0;
  memset(&v26, 0, sizeof(v26));
  GetClientRect(hWnd: v18, lpRect: &v26);
  MapWindowPoints(
    hWndFrom: this->m_wndColorPickerLocation.m_hWnd,
    hWndTo: this->m_hWnd,
    lpPoints: (LPPOINT)&v26,
    cPoints: 2u);
  InflateRect(lprc: &v26, dx: -2, dy: -2);
  this->m_wndColorBar.m_bInternal = 1;
  v25.cy = 4;
  pal.m_hObject = nullptr;
  pal.__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  v7 = this->m_nBitsPixel <= 8;
  v29 = 0;
  if ( v7 )
  {
    Create16ColorsStdPalette(&pal);
  }
  else
  {
    CMFCColorBar::EnableOtherButton(this: &this->m_wndColorBar, lpszLabel: "Other", bAltColorDlg: 1, bEnable: 1);
    v25.cy = 5;
    CMFCColorBar::SetVertMargin(this: &this->m_wndColorBar, nVertMargin: 1);
    CMFCColorBar::SetHorzMargin(this: &this->m_wndColorBar, nHorzMargin: 1);
  }
  if ( this->m_nBitsPixel > 8 )
    p_pal = nullptr;
  else
    p_pal = &pal;
  this->m_wndColorBar.CreateControl(
    this: &this->m_wndColorBar,
    a2: this,
    a3: (const CRect *)&v26,
    a4: 16516u,
    a5: v25.cy,
    a6: p_pal);
  CMFCColorBar::SetColor(this: &this->m_wndColorBar, color: 0);
  v29 = -1;
  pal.__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  CGdiObject::~CGdiObject(this: &pal);
  v19 = this->m_wndPreview.m_hWnd;
  v25.cy = (int)&this->m_rectPreviewImage;
  GetClientRect(hWnd: v19, lpRect: &this->m_rectPreviewImage);
  CWnd::MapWindowPoints(this: &this->m_wndPreview, pwndTo: this, lpRect: &this->m_rectPreviewImage);
  cx = this->m_sizeImage.cx;
  cy = this->m_sizeImage.cy;
  v11 = (this->m_rectPreviewImage.left + this->m_rectPreviewImage.right - cx) / 2;
  this->m_rectPreviewImage.left = v11;
  this->m_rectPreviewImage.right = cx + v11;
  v12 = (this->m_rectPreviewImage.top + this->m_rectPreviewImage.bottom - cy) / 2;
  this->m_rectPreviewImage.top = v12;
  this->m_rectPreviewImage.bottom = cy + v12;
  this->m_rectPreviewFrame.left = this->m_rectPreviewImage.left;
  this->m_rectPreviewFrame.top = this->m_rectPreviewImage.top;
  this->m_rectPreviewFrame.right = this->m_rectPreviewImage.right;
  this->m_rectPreviewFrame.bottom = this->m_rectPreviewImage.bottom;
  InflateRect(lprc: &this->m_rectPreviewFrame, dx: 4, dy: 4);
  v13 = (int *)v25.cy;
  v14 = p_m_wndLargeDrawArea;
  this->m_wndLargeDrawArea.m_rectParentPreviewArea.left = *(_DWORD *)v25.cy;
  this->m_wndLargeDrawArea.m_rectParentPreviewArea.top = *++v13;
  this->m_wndLargeDrawArea.m_rectParentPreviewArea.right = *++v13;
  this->m_wndLargeDrawArea.m_rectParentPreviewArea.bottom = v13[1];
  CWnd::ModifyStyle(this: v14, dwRemove: 0x10000u, dwAdd: 0, nFlags: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104257EE
// Name: protected: void CMFCImageEditorDialog::OnToolCopy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::OnToolCopy(CMFCImageEditorDialog *this)
{
  HDC CompatibleDC; // eax
  HDC v3; // eax
  HBITMAP CompatibleBitmap; // eax
  CBitmap *m_pBitmap; // eax
  void *v6; // eax
  CGdiObject *v7; // eax
  int v8; // ecx
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  int cx; // [esp-8h] [ebp-6Ch]
  int cy; // [esp-4h] [ebp-68h]
  CWindowDC dc; // [esp+10h] [ebp-54h] BYREF
  CDC memDCDest; // [esp+24h] [ebp-40h] BYREF
  CDC memDCSrc; // [esp+34h] [ebp-30h] BYREF
  CBitmap bitmapCopy; // [esp+44h] [ebp-20h] BYREF
  CGdiObject *v18; // [esp+4Ch] [ebp-18h]
  CGdiObject *v19; // [esp+50h] [ebp-14h]
  int v20; // [esp+60h] [ebp-4h]

  if ( this->m_pBitmap != nullptr )
  {
    v20 = 0;
    CWindowDC::CWindowDC(this: &dc, pWnd: this);
    LOBYTE(v20) = 1;
    CDC::CDC(this: &memDCDest);
    LOBYTE(v20) = 2;
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &memDCDest, hDC: CompatibleDC);
    CDC::CDC(this: &memDCSrc);
    LOBYTE(v20) = 3;
    v3 = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &memDCSrc, hDC: v3);
    bitmapCopy.m_hObject = nullptr;
    bitmapCopy.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
    cy = this->m_sizeImage.cy;
    cx = this->m_sizeImage.cx;
    LOBYTE(v20) = 4;
    CompatibleBitmap = CreateCompatibleBitmap(hdc: dc.m_hDC, cx, cy);
    if ( CGdiObject::Attach(this: &bitmapCopy, hObject: CompatibleBitmap) == 0 )
      goto LABEL_3;
    v19 = CDC::SelectGdiObject(hDC: memDCDest.m_hDC, h: bitmapCopy.m_hObject);
    m_pBitmap = this->m_pBitmap;
    v6 = m_pBitmap != nullptr ? m_pBitmap->m_hObject : nullptr;
    v7 = CDC::SelectGdiObject(hDC: memDCSrc.m_hDC, h: v6);
    v8 = this->m_sizeImage.cx;
    v18 = v7;
    BitBlt(
      hdc: memDCDest.m_hDC,
      x: 0,
      y: 0,
      cx: v8,
      cy: this->m_sizeImage.cy,
      hdcSrc: memDCSrc.m_hDC,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    v9 = v19 != nullptr ? v19->m_hObject : nullptr;
    CDC::SelectGdiObject(hDC: memDCDest.m_hDC, h: v9);
    v10 = v18 != nullptr ? v18->m_hObject : nullptr;
    CDC::SelectGdiObject(hDC: memDCSrc.m_hDC, h: v10);
    if ( OpenClipboard(hWndNewOwner: this->m_hWnd) )
    {
      if ( !EmptyClipboard()
        || (v11 = CGdiObject::Detach(this: &bitmapCopy), SetClipboardData(uFormat: 2u, hMem: v11) == nullptr) )
      {
        AfxMessageBox(nIDPrompt: 0x3E8Au, nType: 0, nIDHelp: 0xFFFFFFFF);
      }
      CloseClipboard();
    }
    else
    {
LABEL_3:
      AfxMessageBox(nIDPrompt: 0x3E8Au, nType: 0, nIDHelp: 0xFFFFFFFF);
    }
    LOBYTE(v20) = 3;
    bitmapCopy.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
    CGdiObject::~CGdiObject(this: &bitmapCopy);
    LOBYTE(v20) = 2;
    CDC::~CDC(this: &memDCSrc);
    LOBYTE(v20) = 1;
    CDC::~CDC(this: &memDCDest);
    LOBYTE(v20) = 0;
    CWindowDC::~CWindowDC(this: &dc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104259A0
// Name: public: CMFCImageEditorDialog::CMFCImageEditorDialog(class CBitmap __near *,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCImageEditorDialog *__thiscall CMFCImageEditorDialog::CMFCImageEditorDialog(
        CMFCImageEditorDialog *this,
        CBitmap *pBitmap,
        CWnd *pParent,
        int nBitsPixel)
{
  int bmBitsPixel; // eax
  tagBITMAP bmp; // [esp+10h] [ebp-28h] BYREF
  CMFCImageEditorDialog *v8; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v8 = this;
  CDialogEx::CDialogEx(this, nIDTemplate: 0x3F05u, pParent);
  v9 = 0;
  this->__vftable = (CMFCImageEditorDialog_vtbl *)&CMFCImageEditorDialog::`vftable';
  CWnd::CWnd(this: &this->m_wndColorPickerLocation);
  this->m_wndColorPickerLocation.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndPaletteBarLocation);
  this->m_wndPaletteBarLocation.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndPreview);
  this->m_wndPreview.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CMFCImagePaintArea::CMFCImagePaintArea(this: &this->m_wndLargeDrawArea, pParentDlg: this);
  this->m_pBitmap = pBitmap;
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_rectPreviewFrame.left = 0;
  this->m_rectPreviewFrame.top = 0;
  this->m_rectPreviewFrame.right = 0;
  this->m_rectPreviewFrame.bottom = 0;
  this->m_rectPreviewImage.left = 0;
  this->m_rectPreviewImage.top = 0;
  this->m_rectPreviewImage.right = 0;
  this->m_rectPreviewImage.bottom = 0;
  CMFCColorBar::CMFCColorBar(this: &this->m_wndColorBar);
  LOBYTE(v9) = 5;
  CMFCToolBar::CMFCToolBar(this: &this->m_wndPaletteBar);
  this->m_wndPaletteBar.__vftable = (CMFCImageEditorPaletteBar_vtbl *)&CMFCImageEditorPaletteBar::`vftable';
  GetObjectA(h: this->m_pBitmap->m_hObject, c: 24, pv: &bmp);
  this->m_sizeImage = *(CSize *)&bmp.bmWidth;
  bmBitsPixel = nBitsPixel;
  if ( nBitsPixel == -1 )
    bmBitsPixel = bmp.bmBitsPixel;
  this->m_nBitsPixel = bmBitsPixel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10425AEA
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCImageEditorDialog::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCImageEditorDialog::GetMessageMap(CMFCImageEditorDialog *this)
{
  return (const AFX_MSGMAP *)&off_10691CA4;
}

//------------------------------------------------------------------------------
// Address: 0x10425AF0
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarsKeyboardPropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarsKeyboardPropertyPage::GetRuntimeClass(CMFCToolBarsKeyboardPropertyPage *this)
{
  return &CMFCToolBarsKeyboardPropertyPage::classCMFCToolBarsKeyboardPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x10425AF6
// Name: protected: virtual void CMFCToolBarsKeyboardPropertyPage::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::DoDataExchange(
        CMFCToolBarsKeyboardPropertyPage *this,
        CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 16528, rControl: &this->m_wndAssignedToTitle);
  DDX_Control(pDX, nIDC: 16644, rControl: &this->m_wndNewKey);
  DDX_Control(pDX, nIDC: 16642, rControl: &this->m_wndViewTypeList);
  DDX_Control(pDX, nIDC: 16526, rControl: &this->m_wndViewIcon);
  DDX_Control(pDX, nIDC: 16646, rControl: &this->m_wndRemoveButton);
  DDX_Control(pDX, nIDC: 16643, rControl: &this->m_wndCurrentKeysList);
  DDX_Control(pDX, nIDC: 16641, rControl: &this->m_wndCommandsList);
  DDX_Control(pDX, nIDC: 16601, rControl: &this->m_wndCategoryList);
  DDX_Control(pDX, nIDC: 16645, rControl: &this->m_wndAssignButton);
  DDX_Text(pDX, nIDC: 16514, value: &this->m_strDescription);
  DDX_Text(pDX, nIDC: 16527, value: &this->m_strAssignedTo);
}

//------------------------------------------------------------------------------
// Address: 0x10425BCE
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnSelchangeCurrentKeysList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnSelchangeCurrentKeysList(CMFCToolBarsKeyboardPropertyPage *this)
{
  WPARAM v2; // eax
  tagACCEL *v3; // eax
  int v4; // [esp-4h] [ebp-10h]

  v2 = SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v4 = 0;
  if ( v2 == -1 )
  {
    this->m_pSelEntry = nullptr;
  }
  else
  {
    v3 = (tagACCEL *)SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    this->m_pSelEntry = v3;
    if ( v3 == nullptr )
      AfxThrowInvalidArgException();
    v4 = 1;
  }
  CWnd::EnableWindow(this: &this->m_wndRemoveButton, bEnable: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10425C28
// Name: public: virtual CMFCToolBarsKeyboardPropertyPage::~CMFCToolBarsKeyboardPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::~CMFCToolBarsKeyboardPropertyPage(
        CMFCToolBarsKeyboardPropertyPage *this)
{
  tagACCEL *m_lpAccel; // eax

  this->__vftable = (CMFCToolBarsKeyboardPropertyPage_vtbl *)&CMFCToolBarsKeyboardPropertyPage::`vftable';
  m_lpAccel = this->m_lpAccel;
  if ( m_lpAccel != nullptr )
    operator delete(p: m_lpAccel);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strAllCategory.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strAssignedTo.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDescription.m_pszData - 1);
  CButton::~CButton(this: &this->m_wndAssignButton);
  CComboBox::~CComboBox(this: &this->m_wndCategoryList);
  CListBox::~CListBox(this: &this->m_wndCommandsList);
  CListBox::~CListBox(this: &this->m_wndCurrentKeysList);
  CButton::~CButton(this: &this->m_wndRemoveButton);
  CStatic::~CStatic(this: &this->m_wndViewIcon);
  CComboBox::~CComboBox(this: &this->m_wndViewTypeList);
  CMFCAcceleratorKeyAssignCtrl::~CMFCAcceleratorKeyAssignCtrl(this: &this->m_wndNewKey);
  CStatic::~CStatic(this: &this->m_wndAssignedToTitle);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x10425D19
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::AddKeyEntry(struct tagACCEL __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::AddKeyEntry(CMFCToolBarsKeyboardPropertyPage *this, tagACCEL *pEntry)
{
  ATL::IAtlStringMgr *StringManager; // eax
  WPARAM v4; // eax
  CMFCAcceleratorKey helper; // [esp+10h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+18h] [ebp-10h] BYREF
  int v7; // [esp+24h] [ebp-4h]

  if ( pEntry == nullptr )
    AfxThrowInvalidArgException();
  CMFCAcceleratorKey::CMFCAcceleratorKey(this: &helper, lpAccel: pEntry);
  v7 = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
  LOBYTE(v7) = 1;
  CMFCAcceleratorKey::Format(this: &helper, &str);
  v4 = SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)str.m_pszData);
  SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x19Au, wParam: v4, lParam: (LPARAM)pEntry);
  ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
  v7 = -1;
  CMFCAcceleratorKey::~CMFCAcceleratorKey(this: &helper);
}

//------------------------------------------------------------------------------
// Address: 0x10425DCE
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(CMFCToolBarsKeyboardPropertyPage *this)
{
  WPARAM v2; // eax
  CFrameWnd *ParentFrame; // eax
  int v4; // edi
  int v5; // [esp-4h] [ebp-14h]
  int i; // [esp+Ch] [ebp-4h]

  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strDescription);
  SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  CMFCToolBarsKeyboardPropertyPage::OnSelchangeCurrentKeysList(this);
  v2 = SendMessageA(hWnd: this->m_wndCommandsList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v5 = 0;
  if ( v2 == -1 )
  {
    this->m_pSelButton = nullptr;
  }
  else
  {
    this->m_pSelButton = (CMFCToolBarButton *)SendMessageA(
                                                hWnd: this->m_wndCommandsList.m_hWnd,
                                                Msg: 0x199u,
                                                wParam: v2,
                                                lParam: 0);
    ParentFrame = CWnd::GetParentFrame(this);
    if ( ParentFrame != nullptr && ParentFrame->m_hWnd != nullptr )
      ParentFrame->GetMessageString(this: ParentFrame, a2: this->m_pSelButton->m_nID, a3: &this->m_strDescription);
    if ( this->m_lpAccel != nullptr )
    {
      i = 0;
      if ( this->m_nAccelSize > 0 )
      {
        v4 = 0;
        do
        {
          if ( this->m_pSelButton->m_nID == this->m_lpAccel[v4].cmd )
            CMFCToolBarsKeyboardPropertyPage::AddKeyEntry(this, pEntry: &this->m_lpAccel[v4]);
          ++i;
          ++v4;
        }
        while ( i < this->m_nAccelSize );
      }
    }
    v5 = 1;
  }
  CWnd::EnableWindow(this: &this->m_wndNewKey, bEnable: v5);
  CWnd::UpdateData(this, bSaveAndValidate: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10425EBF
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnRemove(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnRemove(CMFCToolBarsKeyboardPropertyPage *this)
{
  tagACCEL *v2; // eax
  tagACCEL *v3; // esi
  tagACCEL *v4; // edi
  WPARAM v5; // edi
  LRESULT listcount; // [esp+4h] [ebp-14h]
  tagACCEL *p; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  tagACCEL *v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  if ( this->m_pSelEntry == nullptr
    || (p = this->m_lpAccel) == nullptr
    || (v2 = (tagACCEL *)operator new(nSize: 6 * (this->m_nAccelSize - 1)), this->m_lpAccel = v2, v2 == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  i = 0;
  if ( this->m_nAccelSize > 0 )
  {
    v3 = p;
    v10 = 0;
    v9 = p;
    do
    {
      if ( this->m_pSelEntry != v3 )
      {
        v4 = &this->m_lpAccel[v10++];
        *(_DWORD *)&v4->fVirt = *(_DWORD *)&v3->fVirt;
        v4->cmd = v3->cmd;
        v5 = 0;
        listcount = SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
        if ( listcount > 0 )
        {
          while ( (tagACCEL *)SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x199u, wParam: v5, lParam: 0) != v9 )
          {
            if ( (int)++v5 >= listcount )
              goto LABEL_13;
          }
          SendMessageA(
            hWnd: this->m_wndCurrentKeysList.m_hWnd,
            Msg: 0x19Au,
            wParam: v5,
            lParam: (LPARAM)&this->m_lpAccel[v10 - 1]);
        }
      }
LABEL_13:
      ++i;
      v3 = ++v9;
    }
    while ( i < this->m_nAccelSize );
  }
  operator delete(p);
  CKeyboardManager::UpdateAccelTable(
    this: afxKeyboardManager,
    pTemplate: this->m_pSelTemplate,
    lpAccel: this->m_lpAccel,
    nSize: --this->m_nAccelSize,
    pDefaultFrame: nullptr);
  CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(this);
  CWnd::SetFocus(this: &this->m_wndCommandsList);
}

//------------------------------------------------------------------------------
// Address: 0x10425FF7
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnSelchangeViewType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnSelchangeViewType(CMFCToolBarsKeyboardPropertyPage *this)
{
  tagACCEL *m_lpAccel; // eax
  WPARAM v3; // eax
  LRESULT v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // eax
  HACCEL__ *m_hAccelTable; // ecx
  CObject *v8; // eax
  HACCEL__ *v9; // eax
  int v10; // eax
  tagACCEL *v11; // eax
  CFrameWnd *pWndMaina; // [esp+Ch] [ebp-8h]
  CFrameWnd *pWndMain; // [esp+Ch] [ebp-8h]
  CMultiDocTemplateEx *pTemplate; // [esp+10h] [ebp-4h]

  m_lpAccel = this->m_lpAccel;
  this->m_hAccelTable = nullptr;
  this->m_pSelTemplate = nullptr;
  if ( m_lpAccel != nullptr )
  {
    operator delete(p: m_lpAccel);
    this->m_lpAccel = nullptr;
  }
  v3 = SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 == -1 )
  {
    SendMessageA(hWnd: this->m_wndViewIcon.m_hWnd, Msg: 0x170u, wParam: 0, lParam: 0);
    return;
  }
  v4 = SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
  pTemplate = (CMultiDocTemplateEx *)v4;
  if ( v4 != 0 )
  {
    pWndMaina = *(CFrameWnd **)(v4 + 84);
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    IconW = LoadIconW(
              hInstance: ModuleState->m_hCurrentResourceHandle,
              lpIconName: (LPCWSTR)(unsigned __int16)pWndMaina);
    m_hAccelTable = pTemplate->m_hAccelTable;
    goto LABEL_9;
  }
  v8 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: this->m_pParentFrame);
  pWndMain = (CFrameWnd *)v8;
  if ( v8 != nullptr )
  {
    IconW = (HICON)GetClassLongA(hWnd: (HWND)v8[8].__vftable, nIndex: -14);
    m_hAccelTable = pWndMain->m_hAccelTable;
LABEL_9:
    this->m_hAccelTable = m_hAccelTable;
    if ( IconW != nullptr )
      goto LABEL_11;
  }
  IconW = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F00);
LABEL_11:
  SendMessageA(hWnd: this->m_wndViewIcon.m_hWnd, Msg: 0x170u, wParam: (WPARAM)IconW, lParam: 0);
  v9 = this->m_hAccelTable;
  if ( v9 == nullptr
    || (v10 = CopyAcceleratorTableA(hAccelSrc: v9, lpAccelDst: nullptr, cAccelEntries: 0),
        this->m_nAccelSize = v10,
        v11 = (tagACCEL *)operator new(nSize: 6 * v10),
        this->m_lpAccel = v11,
        v11 == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  CopyAcceleratorTableA(hAccelSrc: this->m_hAccelTable, lpAccelDst: v11, cAccelEntries: this->m_nAccelSize);
  this->m_pSelTemplate = pTemplate;
  CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042614B
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnResetAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnResetAll(CMFCToolBarsKeyboardPropertyPage *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // esi
  CFrameWnd *m_pParentFrame; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
  v7 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EF3u);
  if ( StringResourceHandle == nullptr
    || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &str,
         hInstance: StringResourceHandle,
         nID: 0x3EF3u) == 0 )
  {
    AfxThrowInvalidArgException();
  }
  m_pszData = str.m_pszData;
  if ( AfxMessageBox(lpszText: str.m_pszData, nType: 0x24u, nIDHelp: 0) == 6 )
  {
    CKeyboardManager::ResetAll(this: afxKeyboardManager);
    m_pParentFrame = this->m_pParentFrame;
    if ( m_pParentFrame != nullptr )
      SendMessageA(hWnd: m_pParentFrame->m_hWnd, Msg: AFX_WM_RESETKEYBOARD, wParam: 0, lParam: 0);
    CMFCToolBarsKeyboardPropertyPage::OnSelchangeViewType(this);
    CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(this);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x104261E3
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnSelchangeCategory(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnSelchangeCategory(CMFCToolBarsKeyboardPropertyPage *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  BOOL v3; // ebx
  CFont *Font; // eax
  CFont *v5; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  void *m_pNodeHead; // eax
  __POSITION *v9; // ecx
  CMFCToolBarButton *v10; // eax
  unsigned int m_nID; // ecx
  char *v12; // eax
  bool v13; // zf
  WPARAM v14; // eax
  CSize *TextExtent; // eax
  int SystemMetrics; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-64h]
  CClientDC dcCommands; // [esp+10h] [ebp-50h] BYREF
  CSize v19; // [esp+24h] [ebp-3Ch] BYREF
  CSize result; // [esp+2Ch] [ebp-34h] BYREF
  CFont *pOldFont; // [esp+34h] [ebp-2Ch]
  CMFCToolBarsCustomizeDialog *pWndParent; // [esp+38h] [ebp-28h]
  __POSITION *pos; // [esp+3Ch] [ebp-24h]
  CObList *pCategoryButtonsList; // [esp+40h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCategory; // [esp+44h] [ebp-1Ch] BYREF
  int iIndex; // [esp+48h] [ebp-18h]
  CMFCToolBarButton *pButton; // [esp+4Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+50h] [ebp-10h] BYREF
  int v29; // [esp+5Ch] [ebp-4h]

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  iIndex = SendMessageA(hWnd: this->m_wndCategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( iIndex != -1 )
  {
    SendMessageA(hWnd: this->m_wndCommandsList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
    pCategoryButtonsList = (CObList *)SendMessageA(
                                        hWnd: this->m_wndCategoryList.m_hWnd,
                                        Msg: 0x150u,
                                        wParam: iIndex,
                                        lParam: 0);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strCategory, pStringMgr: StringManager);
    v29 = 0;
    CComboBox::GetLBText(this: &this->m_wndCategoryList, nIndex: iIndex, rString: &strCategory);
    v3 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: &strCategory,
           psz: this->m_strAllCategory.m_pszData) == 0;
    CClientDC::CClientDC(this: &dcCommands, pWnd: &this->m_wndCommandsList);
    LOBYTE(v29) = 1;
    Font = CWnd::GetFont(this: &this->m_wndCommandsList);
    v5 = CDC::SelectObject(this: &dcCommands, pFont: Font);
    m_hWnd = this->m_hWnd;
    pOldFont = v5;
    Parent = GetParent(hWnd: m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    pWndParent = (CMFCToolBarsCustomizeDialog *)AfxDynamicDownCast(
                                                  pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog,
                                                  pObject: v7);
    if ( pWndParent == nullptr )
      goto LABEL_3;
    m_pNodeHead = pCategoryButtonsList->m_pNodeHead;
    iIndex = 0;
    if ( m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        v9 = *(__POSITION **)m_pNodeHead;
        v10 = *((CMFCToolBarButton **)m_pNodeHead + 2);
        pos = v9;
        pButton = v10;
        if ( v10 == nullptr )
          break;
        m_nID = v10->m_nID;
        if ( m_nID != 0 && m_nID != -1 )
        {
          v12 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v10->m_strText.m_pszData - 1)[1];
          strText.m_pszData = v12;
          v13 = *((_DWORD *)pButton->m_strTextCustom.m_pszData - 3) == 0;
          LOBYTE(v29) = 2;
          if ( !v13
            && (v3
             || CMFCToolBarsCustomizeDialog::GetCountInCategory(
                  this: pWndParent,
                  lpszItemName: v12,
                  lstCommands: pCategoryButtonsList) > 1) )
          {
            ATL::CSimpleStringT<char,0>::operator=(
              this: &strText,
              strSrc: (ATL::CStringData *)&pButton->m_strTextCustom);
          }
          v14 = SendMessageA(
                  hWnd: this->m_wndCommandsList.m_hWnd,
                  Msg: 0x180u,
                  wParam: 0,
                  lParam: (LPARAM)strText.m_pszData);
          SendMessageA(hWnd: this->m_wndCommandsList.m_hWnd, Msg: 0x19Au, wParam: v14, lParam: (LPARAM)pButton);
          TextExtent = CDC::GetTextExtent(this: &dcCommands, &result, str: &strText);
          if ( iIndex <= TextExtent->cx )
            iIndex = CDC::GetTextExtent(this: &dcCommands, result: &v19, str: &strText)->cx;
          LOBYTE(v29) = 1;
          ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
        }
        if ( pos == nullptr )
          goto LABEL_18;
        m_pNodeHead = pos;
      }
LABEL_3:
      AfxThrowInvalidArgException();
    }
LABEL_18:
    SystemMetrics = GetSystemMetrics(nIndex: 21);
    SendMessageA(hWnd: this->m_wndCommandsList.m_hWnd, Msg: 0x194u, wParam: iIndex + SystemMetrics, lParam: 0);
    CDC::SelectObject(this: &dcCommands, pFont: pOldFont);
    CWnd::EnableWindow(this: &this->m_wndNewKey, bEnable: 0);
    SendMessageA(hWnd: this->m_wndCommandsList.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
    CMFCToolBarsKeyboardPropertyPage::OnSelchangeCommandsList(this);
    LOBYTE(v29) = 0;
    CClientDC::~CClientDC(this: &dcCommands);
    ATL::CStringData::Release(this: (ATL::CStringData *)strCategory.m_pszData - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10426438
// Name: public: CMFCToolBarsKeyboardPropertyPage::CMFCToolBarsKeyboardPropertyPage(class CFrameWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsKeyboardPropertyPage *__thiscall CMFCToolBarsKeyboardPropertyPage::CMFCToolBarsKeyboardPropertyPage(
        CMFCToolBarsKeyboardPropertyPage *this,
        CFrameWnd *pParentFrame,
        int bAutoSet)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v5; // eax
  ATL::IAtlStringMgr *v6; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x3F08u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CMFCToolBarsKeyboardPropertyPage_vtbl *)&CMFCToolBarsKeyboardPropertyPage::`vftable';
  CWnd::CWnd(this: &this->m_wndAssignedToTitle);
  this->m_wndAssignedToTitle.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl(this: &this->m_wndNewKey);
  CWnd::CWnd(this: &this->m_wndViewTypeList);
  this->m_wndViewTypeList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_wndViewIcon);
  this->m_wndViewIcon.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndRemoveButton);
  this->m_wndRemoveButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndCurrentKeysList);
  this->m_wndCurrentKeysList.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::CWnd(this: &this->m_wndCommandsList);
  this->m_wndCommandsList.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::CWnd(this: &this->m_wndCategoryList);
  this->m_wndCategoryList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_wndAssignButton);
  this->m_wndAssignButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDescription, pStringMgr: StringManager);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAssignedTo, pStringMgr: v5);
  this->m_bAutoSet = bAutoSet;
  this->m_pParentFrame = pParentFrame;
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAllCategory, pStringMgr: v6);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDescription, pszSrc: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strAssignedTo, pszSrc: &var);
  this->m_hAccelTable = nullptr;
  this->m_lpAccel = nullptr;
  this->m_nAccelSize = 0;
  this->m_pSelTemplate = nullptr;
  this->m_pSelButton = nullptr;
  this->m_pSelEntry = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104265CD
// Name: protected: virtual int CMFCToolBarsKeyboardPropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsKeyboardPropertyPage::OnInitDialog(CMFCToolBarsKeyboardPropertyPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CMFCToolBarsCustomizeDialog *v4; // eax
  CDocManager *m_pDocManager; // eax
  LRESULT v6; // eax
  LRESULT v7; // eax
  int v8; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  CMultiDocTemplateEx_vtbl *v10; // eax
  WPARAM v11; // eax
  CObject *v12; // eax
  ATL::IAtlStringMgr *v13; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v15; // eax
  int iIndex; // [esp+10h] [ebp-24h]
  WPARAM iIndexa; // [esp+10h] [ebp-24h]
  __POSITION *pos; // [esp+14h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strName; // [esp+18h] [ebp-1Ch] BYREF
  CMultiDocTemplateEx *pTemplate; // [esp+1Ch] [ebp-18h]
  int bIsAlreadyExist; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  int v24; // [esp+30h] [ebp-4h]

  CDialog::OnInitDialog(this);
  if ( afxKeyboardManager == nullptr )
    goto LABEL_2;
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (CMFCToolBarsCustomizeDialog *)AfxDynamicDownCast(
                                        pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog,
                                        pObject: v3);
  CMFCToolBarsCustomizeDialog::FillCategoriesComboBox(this: v4, wndCategory: &this->m_wndCategoryList, bAddEmpty: 0);
  SendMessageA(hWnd: this->m_wndCategoryList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  CMFCToolBarsKeyboardPropertyPage::OnSelchangeCategory(this);
  m_pDocManager = AfxGetModuleState()->m_pCurrentWinApp->m_pDocManager;
  iIndex = (int)m_pDocManager;
  if ( this->m_bAutoSet != 0 && m_pDocManager != nullptr )
  {
    pos = m_pDocManager->GetFirstDocTemplatePosition(this: m_pDocManager);
    while ( pos != nullptr )
    {
      pTemplate = (CMultiDocTemplateEx *)(*(int (__thiscall **)(int, __POSITION **))(*(_DWORD *)iIndex + 20))(
                                           a1: iIndex,
                                           a2: &pos);
      if ( CObject::IsKindOf(this: pTemplate, pClass: &CMultiDocTemplate::classCMultiDocTemplate) != 0
        && pTemplate->m_hAccelTable != nullptr )
      {
        bIsAlreadyExist = 0;
        i = 0;
        do
        {
          v6 = SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
          if ( i >= v6 )
            break;
          v7 = SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x150u, wParam: i, lParam: 0);
          if ( v7 != 0 )
          {
            v8 = *(_DWORD *)(v7 + 84);
            bIsAlreadyExist = 1;
            if ( v8 == pTemplate->m_nIDResource )
              continue;
          }
          bIsAlreadyExist = 0;
          ++i;
        }
        while ( bIsAlreadyExist == 0 );
        if ( bIsAlreadyExist == 0 )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strName, pStringMgr: StringManager);
          v10 = pTemplate->__vftable;
          v24 = 0;
          v10->GetDocString(this: pTemplate, a2: &strName, a3: fileNewName);
          v11 = SendMessageA(
                  hWnd: this->m_wndViewTypeList.m_hWnd,
                  Msg: 0x143u,
                  wParam: 0,
                  lParam: (LPARAM)strName.m_pszData);
          SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x151u, wParam: v11, lParam: (LPARAM)pTemplate);
          v24 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
        }
      }
    }
  }
  v12 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: this->m_pParentFrame);
  if ( v12 != nullptr && v12[32].__vftable != nullptr )
  {
    v13 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strName, pStringMgr: v13);
    v24 = 1;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EF2u);
    if ( StringResourceHandle != nullptr )
      v15 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: &strName,
              hInstance: StringResourceHandle,
              nID: 0x3EF2u);
    else
      v15 = 0;
    if ( v15 == 0 )
LABEL_2:
      AfxThrowInvalidArgException();
    iIndexa = SendMessageA(
                hWnd: this->m_wndViewTypeList.m_hWnd,
                Msg: 0x143u,
                wParam: 0,
                lParam: (LPARAM)strName.m_pszData);
    SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x151u, wParam: iIndexa, lParam: 0);
    SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x14Eu, wParam: iIndexa, lParam: 0);
    CMFCToolBarsKeyboardPropertyPage::OnSelchangeViewType(this);
    v24 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
  }
  if ( SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == -1 )
  {
    SendMessageA(hWnd: this->m_wndViewTypeList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    CMFCToolBarsKeyboardPropertyPage::OnSelchangeViewType(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10426834
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnUpdateNewShortcutKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnUpdateNewShortcutKey(CMFCToolBarsKeyboardPropertyPage *this)
{
  int v2; // ecx
  int v3; // edi
  tagACCEL *m_lpAccel; // eax
  HWND Parent; // eax
  CWnd *v6; // eax
  CMFCToolBarsCustomizeDialog *v7; // eax
  const char *CommandName; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strAssignedTo; // ecx
  HINSTANCE__ *StringResourceHandle; // eax
  int i; // [esp+8h] [ebp-4h]

  if ( this == (CMFCToolBarsKeyboardPropertyPage *)-404 )
LABEL_2:
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAssignedTo);
  CWnd::ShowWindow(this: &this->m_wndAssignedToTitle, nCmdShow: 0);
  CWnd::EnableWindow(this: &this->m_wndAssignButton, bEnable: 0);
  if ( this->m_wndNewKey.m_bIsDefined != 0 )
  {
    if ( this->m_lpAccel == nullptr )
      goto LABEL_2;
    v2 = 0;
    i = 0;
    v3 = 0;
    do
    {
      if ( i >= this->m_nAccelSize )
        break;
      m_lpAccel = this->m_lpAccel;
      if ( this->m_wndNewKey.m_Accel.key == m_lpAccel[v3].key
        && ((m_lpAccel[v3].fVirt ^ this->m_wndNewKey.m_Accel.fVirt) & 0x1D) == 0 )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v6 = CWnd::FromHandle(hWnd: Parent);
        v7 = (CMFCToolBarsCustomizeDialog *)AfxDynamicDownCast(
                                              pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog,
                                              pObject: v6);
        if ( v7 == nullptr )
          goto LABEL_2;
        CommandName = CMFCToolBarsCustomizeDialog::GetCommandName(this: v7, uiCmd: this->m_lpAccel[v3].cmd);
        p_m_strAssignedTo = &this->m_strAssignedTo;
        if ( CommandName != nullptr )
          ATL::CSimpleStringT<char,0>::SetString(this: p_m_strAssignedTo, pszSrc: CommandName);
        else
          ATL::CSimpleStringT<char,0>::SetString(this: p_m_strAssignedTo, pszSrc: "????");
        v2 = 1;
      }
      ++i;
      ++v3;
    }
    while ( v2 == 0 );
    if ( v2 == 0 )
    {
      StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3E89u);
      if ( StringResourceHandle == nullptr
        || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: &this->m_strAssignedTo,
             hInstance: StringResourceHandle,
             nID: 0x3E89u) == 0 )
      {
        goto LABEL_2;
      }
      CWnd::EnableWindow(this: &this->m_wndAssignButton, bEnable: 1);
    }
    CWnd::ShowWindow(this: &this->m_wndAssignedToTitle, nCmdShow: 5);
  }
  CWnd::UpdateData(this, bSaveAndValidate: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10426971
// Name: public: void CMFCToolBarsKeyboardPropertyPage::SetAllCategory(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::SetAllCategory(
        CMFCToolBarsKeyboardPropertyPage *this,
        const char *lpszCategory)
{
  if ( lpszCategory == nullptr )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strAllCategory, pszSrc: lpszCategory);
}

//------------------------------------------------------------------------------
// Address: 0x1042698D
// Name: public: static class CObject __near * CMFCToolBarsKeyboardPropertyPage::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsKeyboardPropertyPage *__stdcall CMFCToolBarsKeyboardPropertyPage::CreateObject()
{
  CMFCToolBarsKeyboardPropertyPage *v0; // ecx
  CMFCToolBarsKeyboardPropertyPage *result; // eax

  v0 = (CMFCToolBarsKeyboardPropertyPage *)operator new(nSize: 0x500u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarsKeyboardPropertyPage::CMFCToolBarsKeyboardPropertyPage(
             this: v0,
             pParentFrame: nullptr,
             bAutoSet: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104269BF
// Name: protected: void CMFCToolBarsKeyboardPropertyPage::OnAssign(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsKeyboardPropertyPage::OnAssign(CMFCToolBarsKeyboardPropertyPage *this)
{
  CMFCToolBarButton *m_pSelButton; // eax
  HWND Parent; // eax
  CWnd *v4; // eax
  CObject *v5; // eax
  tagACCEL *v6; // eax
  WPARAM v7; // esi
  tagACCEL *v8; // edi
  LRESULT listcount; // [esp+Ch] [ebp-10h]
  tagACCEL *lpAccelOld; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  if ( this->m_lpAccel == nullptr )
    goto LABEL_2;
  m_pSelButton = this->m_pSelButton;
  if ( m_pSelButton == nullptr
    || this->m_wndNewKey.m_bIsDefined == 0
    || this == (CMFCToolBarsKeyboardPropertyPage *)-404 )
  {
    goto LABEL_2;
  }
  this->m_wndNewKey.m_Accel.cmd = m_pSelButton->m_nID;
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = AfxDynamicDownCast(pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog, pObject: v4);
  if ( ((int (__thiscall *)(CObject *, tagACCEL *))v5->__vftable[32].dtr_CObject)(
         a1: v5,
         a2: &this->m_wndNewKey.m_Accel) == 0 )
    return;
  lpAccelOld = this->m_lpAccel;
  v6 = (tagACCEL *)operator new(nSize: 6 * (this->m_nAccelSize + 1));
  this->m_lpAccel = v6;
  if ( v6 == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  memcpy(dst: &v6->fVirt, src: &lpAccelOld->fVirt, count: 6 * this->m_nAccelSize);
  listcount = SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  i = 0;
  if ( this->m_nAccelSize > 0 )
  {
    v12 = 0;
    do
    {
      v7 = 0;
      if ( listcount > 0 )
      {
        while ( (tagACCEL *)SendMessageA(hWnd: this->m_wndCurrentKeysList.m_hWnd, Msg: 0x199u, wParam: v7, lParam: 0) != &lpAccelOld[v12] )
        {
          if ( (int)++v7 >= listcount )
            goto LABEL_15;
        }
        SendMessageA(
          hWnd: this->m_wndCurrentKeysList.m_hWnd,
          Msg: 0x19Au,
          wParam: v7,
          lParam: (LPARAM)&this->m_lpAccel[v12]);
      }
LABEL_15:
      ++i;
      ++v12;
    }
    while ( i < this->m_nAccelSize );
  }
  v8 = &this->m_lpAccel[this->m_nAccelSize];
  *(_DWORD *)&v8->fVirt = *(_DWORD *)&this->m_wndNewKey.m_Accel.fVirt;
  v8->cmd = this->m_wndNewKey.m_Accel.cmd;
  ++this->m_nAccelSize;
  operator delete(p: lpAccelOld);
  CKeyboardManager::UpdateAccelTable(
    this: afxKeyboardManager,
    pTemplate: this->m_pSelTemplate,
    lpAccel: this->m_lpAccel,
    nSize: this->m_nAccelSize,
    pDefaultFrame: nullptr);
  CMFCToolBarsKeyboardPropertyPage::AddKeyEntry(this, pEntry: &this->m_lpAccel[this->m_nAccelSize - 1]);
  CMFCAcceleratorKeyAssignCtrl::ResetKey(this: &this->m_wndNewKey);
  CMFCToolBarsKeyboardPropertyPage::OnUpdateNewShortcutKey(this);
  CWnd::SetFocus(this: &this->m_wndCommandsList);
}

//------------------------------------------------------------------------------
// Address: 0x10426B79
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarsKeyboardPropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarsKeyboardPropertyPage::GetMessageMap(CMFCToolBarsKeyboardPropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_10692080;
}

//------------------------------------------------------------------------------
// Address: 0x10426B7F
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarsOptionsPropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarsOptionsPropertyPage::GetRuntimeClass(CMFCToolBarsOptionsPropertyPage *this)
{
  return &CMFCToolBarsOptionsPropertyPage::classCMFCToolBarsOptionsPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x10426B85
// Name: public: virtual CMFCToolBarsOptionsPropertyPage::~CMFCToolBarsOptionsPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::~CMFCToolBarsOptionsPropertyPage(
        CMFCToolBarsOptionsPropertyPage *this)
{
  this->__vftable = (CMFCToolBarsOptionsPropertyPage_vtbl *)&CMFCToolBarsOptionsPropertyPage::`vftable';
  CButton::~CButton(this: &this->m_wndShowShortcutKeys);
  CButton::~CButton(this: &this->m_wndShowAllMenusDelay);
  CStatic::~CStatic(this: &this->m_wndRuMenusTitle);
  CStatic::~CStatic(this: &this->m_wndRuMenusLine);
  CButton::~CButton(this: &this->m_wndResetUsageBtn);
  CButton::~CButton(this: &this->m_wndRUMenus);
  CButton::~CButton(this: &this->m_wndLargeIcons);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x10426C19
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OShowTooltipsWithKeys(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OShowTooltipsWithKeys(CMFCToolBarsOptionsPropertyPage *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CMFCToolBar::m_bShowShortcutKeys = this->m_bShowShortcutKeys;
}

//------------------------------------------------------------------------------
// Address: 0x10426C32
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OnShowTooltips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OnShowTooltips(CMFCToolBarsOptionsPropertyPage *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CMFCToolBar::m_bShowTooltips = this->m_bShowTooltips;
  CWnd::EnableWindow(this: &this->m_wndShowShortcutKeys, bEnable: this->m_bShowTooltips);
}

//------------------------------------------------------------------------------
// Address: 0x10426C5D
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OnResetUsageData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OnResetUsageData(CMFCToolBarsOptionsPropertyPage *this)
{
  if ( AfxMessageBox(nIDPrompt: 0x3F74u, nType: 4u, nIDHelp: 0xFFFFFFFF) == 6 )
    CMFCCmdUsageCount::Reset(this: &CMFCToolBar::m_UsageCount);
}

//------------------------------------------------------------------------------
// Address: 0x10426C7B
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OnShowRecentlyUsedMenus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OnShowRecentlyUsedMenus(CMFCToolBarsOptionsPropertyPage *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CWnd::EnableWindow(this: &this->m_wndShowAllMenusDelay, bEnable: this->m_bRecentlyUsedMenus);
  CMFCMenuBar::m_bRecentlyUsedMenus = this->m_bRecentlyUsedMenus;
}

//------------------------------------------------------------------------------
// Address: 0x10426CA7
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OnShowMenusDelay(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OnShowMenusDelay(CMFCToolBarsOptionsPropertyPage *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CMFCMenuBar::m_bShowAllMenusDelay = this->m_bShowAllMenusDelay;
}

//------------------------------------------------------------------------------
// Address: 0x10426CC0
// Name: protected: void CMFCToolBarsOptionsPropertyPage::OnLargeIcons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::OnLargeIcons(CMFCToolBarsOptionsPropertyPage *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CMFCToolBar::SetLargeIcons(bLargeIcons: this->m_bLargeIcons);
}

//------------------------------------------------------------------------------
// Address: 0x10426CD9
// Name: public: CMFCToolBarsOptionsPropertyPage::CMFCToolBarsOptionsPropertyPage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsOptionsPropertyPage *__thiscall CMFCToolBarsOptionsPropertyPage::CMFCToolBarsOptionsPropertyPage(
        CMFCToolBarsOptionsPropertyPage *this,
        int bIsMenuBarExist)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x3F09u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CMFCToolBarsOptionsPropertyPage_vtbl *)&CMFCToolBarsOptionsPropertyPage::`vftable';
  CWnd::CWnd(this: &this->m_wndLargeIcons);
  this->m_wndLargeIcons.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndRUMenus);
  this->m_wndRUMenus.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndResetUsageBtn);
  this->m_wndResetUsageBtn.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndRuMenusLine);
  this->m_wndRuMenusLine.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndRuMenusTitle);
  this->m_wndRuMenusTitle.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndShowAllMenusDelay);
  this->m_wndShowAllMenusDelay.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndShowShortcutKeys);
  this->m_wndShowShortcutKeys.__vftable = (CButton_vtbl *)&CButton::`vftable';
  this->m_bIsMenuBarExist = bIsMenuBarExist;
  this->m_bShowTooltips = CMFCToolBar::m_bShowTooltips;
  this->m_bShowShortcutKeys = CMFCToolBar::m_bShowShortcutKeys;
  this->m_bRecentlyUsedMenus = CMFCMenuBar::m_bRecentlyUsedMenus;
  this->m_bShowAllMenusDelay = CMFCMenuBar::m_bShowAllMenusDelay;
  this->m_bLargeIcons = CMFCToolBar::m_bLargeIcons;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10426E06
// Name: protected: virtual void CMFCToolBarsOptionsPropertyPage::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsOptionsPropertyPage::DoDataExchange(
        CMFCToolBarsOptionsPropertyPage *this,
        CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 16653, rControl: &this->m_wndLargeIcons);
  DDX_Control(pDX, nIDC: 16655, rControl: &this->m_wndRUMenus);
  DDX_Control(pDX, nIDC: 16657, rControl: &this->m_wndResetUsageBtn);
  DDX_Control(pDX, nIDC: 16538, rControl: &this->m_wndRuMenusLine);
  DDX_Control(pDX, nIDC: 16539, rControl: &this->m_wndRuMenusTitle);
  DDX_Control(pDX, nIDC: 16656, rControl: &this->m_wndShowAllMenusDelay);
  DDX_Control(pDX, nIDC: 16652, rControl: &this->m_wndShowShortcutKeys);
  DDX_Check(pDX, nIDC: 16651, value: &this->m_bShowTooltips);
  DDX_Check(pDX, nIDC: 16652, value: &this->m_bShowShortcutKeys);
  DDX_Check(pDX, nIDC: 16655, value: &this->m_bRecentlyUsedMenus);
  DDX_Check(pDX, nIDC: 16656, value: &this->m_bShowAllMenusDelay);
  DDX_Check(pDX, nIDC: 16653, value: &this->m_bLargeIcons);
}

//------------------------------------------------------------------------------
// Address: 0x10426EEF
// Name: protected: virtual int CMFCToolBarsOptionsPropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsOptionsPropertyPage::OnInitDialog(CMFCToolBarsOptionsPropertyPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CObject *v4; // eax

  CDialog::OnInitDialog(this);
  CWnd::EnableWindow(this: &this->m_wndShowShortcutKeys, bEnable: this->m_bShowTooltips);
  CWnd::EnableWindow(this: &this->m_wndShowAllMenusDelay, bEnable: this->m_bRecentlyUsedMenus);
  if ( CMFCToolBar::m_lstBasicCommands.m_nCount == 0 || this->m_bIsMenuBarExist == 0 )
  {
    CWnd::ShowWindow(this: &this->m_wndRUMenus, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndRUMenus, bEnable: 0);
    CWnd::ShowWindow(this: &this->m_wndResetUsageBtn, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndResetUsageBtn, bEnable: 0);
    CWnd::ShowWindow(this: &this->m_wndRuMenusLine, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndRuMenusLine, bEnable: 0);
    CWnd::ShowWindow(this: &this->m_wndRuMenusTitle, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndRuMenusTitle, bEnable: 0);
    CWnd::ShowWindow(this: &this->m_wndShowAllMenusDelay, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndShowAllMenusDelay, bEnable: 0);
  }
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = AfxDynamicDownCast(pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog, pObject: v3);
  if ( v4 == nullptr )
    AfxThrowInvalidArgException();
  if ( SLOBYTE(v4[82].__vftable) < 0 )
  {
    CWnd::ShowWindow(this: &this->m_wndLargeIcons, nCmdShow: 0);
    CWnd::EnableWindow(this: &this->m_wndLargeIcons, bEnable: 0);
    this->m_bLargeIcons = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10426FFD
// Name: public: static class CObject __near * CMFCToolBarsOptionsPropertyPage::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsOptionsPropertyPage *__stdcall CMFCToolBarsOptionsPropertyPage::CreateObject()
{
  CMFCToolBarsOptionsPropertyPage *v0; // ecx
  CMFCToolBarsOptionsPropertyPage *result; // eax

  v0 = (CMFCToolBarsOptionsPropertyPage *)operator new(nSize: 0x3ECu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarsOptionsPropertyPage::CMFCToolBarsOptionsPropertyPage(this: v0, bIsMenuBarExist: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042702E
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarsOptionsPropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarsOptionsPropertyPage::GetMessageMap(CMFCToolBarsOptionsPropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_10692350;
}

//------------------------------------------------------------------------------
// Address: 0x10427034
// Name: public: CVSToolsListBox::CVSToolsListBox(class CMFCToolBarsToolsPropertyPage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVSToolsListBox *__thiscall CVSToolsListBox::CVSToolsListBox(
        CVSToolsListBox *this,
        CMFCToolBarsToolsPropertyPage *pParent)
{
  CVSListBox::CVSListBox(this);
  this->m_pParent = pParent;
  this->__vftable = (CVSToolsListBox_vtbl *)&CVSToolsListBox::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10427057
// Name: public: virtual CVSToolsListBox::~CVSToolsListBox(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVSToolsListBox::~CVSToolsListBox(CVSToolsListBox *this)
{
  CVSListBox::~CVSListBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042705C
// Name: public: virtual int CVSToolsListBox::OnBeforeRemoveItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSToolsListBox::OnBeforeRemoveItem(CVSToolsListBox *this, int iItem)
{
  CUserTool *v3; // eax

  v3 = (CUserTool *)this->GetItemData(this, a2: iItem);
  CUserToolsManager::RemoveTool(this: afxUserToolsManager, pTool: v3);
  this->m_pParent->m_pSelTool = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10427090
// Name: public: virtual void CVSToolsListBox::OnAfterMoveItemUp(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSToolsListBox::OnAfterMoveItemUp(CVSToolsListBox *this, int iItem)
{
  CUserTool *v2; // eax

  v2 = (CUserTool *)this->GetItemData(this, a2: iItem);
  CUserToolsManager::MoveToolUp(this: afxUserToolsManager, pTool: v2);
}

//------------------------------------------------------------------------------
// Address: 0x104270B0
// Name: public: virtual void CVSToolsListBox::OnAfterMoveItemDown(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSToolsListBox::OnAfterMoveItemDown(CVSToolsListBox *this, int iItem)
{
  CUserTool *v2; // eax

  v2 = (CUserTool *)this->GetItemData(this, a2: iItem);
  CUserToolsManager::MoveToolDown(this: afxUserToolsManager, pTool: v2);
}

//------------------------------------------------------------------------------
// Address: 0x104270D0
// Name: public: virtual int CMFCToolBarsToolsPropertyPage::OnKillActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsToolsPropertyPage::OnKillActive(CMFCToolBarsToolsPropertyPage *this)
{
  int result; // eax

  result = this->m_pParentSheet->CheckToolsValidity(
             this: this->m_pParentSheet,
             a2: &afxUserToolsManager->m_lstUserTools);
  if ( result != 0 )
    return CPropertyPage::OnKillActive(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104270F8
// Name: protected: void CMFCToolBarsToolsPropertyPage::EnableControls(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::EnableControls(CMFCToolBarsToolsPropertyPage *this)
{
  BOOL v2; // edi

  v2 = this->m_wndToolsList.GetSelItem(this: &this->m_wndToolsList) >= 0;
  CWnd::EnableWindow(this: &this->m_wndCommandEdit, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_wndArgumentsEdit, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_wndInitialDirEdit, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_wndBrowseBtn, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_wndInitialDirBtn, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_wndArgumentsBtn, bEnable: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10427181
// Name: protected: virtual void CMFCToolBarsToolsPropertyPage::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(CMFCToolBarsToolsPropertyPage *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 16997, rControl: &this->m_wndInitialDirBtn);
  DDX_Control(pDX, nIDC: 16989, rControl: &this->m_wndArgumentsBtn);
  DDX_Control(pDX, nIDC: 16924, rControl: &this->m_wndArgumentsEdit);
  DDX_Control(pDX, nIDC: 16925, rControl: &this->m_wndInitialDirEdit);
  DDX_Control(pDX, nIDC: 16922, rControl: &this->m_wndCommandEdit);
  DDX_Control(pDX, nIDC: 16923, rControl: &this->m_wndBrowseBtn);
  DDX_Control(pDX, nIDC: 16921, rControl: &this->m_wndToolsList);
  DDX_Text(pDX, nIDC: 16922, value: &this->m_strCommand);
  DDX_Text(pDX, nIDC: 16924, value: &this->m_strArguments);
  DDX_Text(pDX, nIDC: 16925, value: &this->m_strInitialDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x10427246
// Name: protected: virtual int CMFCToolBarsToolsPropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsToolsPropertyPage::OnInitDialog(CMFCToolBarsToolsPropertyPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CMFCToolBarsCustomizeDialog *v4; // eax
  CObList::CNode *m_pNodeHead; // edi
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *data; // eax
  unsigned int m_uiInitialDirMenuID; // ebx
  HMENU SubMenu; // eax
  HMENU__ *v9; // eax
  unsigned int m_uiArgumentsMenuID; // ebx
  HMENU v11; // eax
  HMENU__ *v12; // eax

  CDialog::OnInitDialog(this);
  if ( afxUserToolsManager == nullptr
    || (Parent = GetParent(hWnd: this->m_hWnd),
        v3 = CWnd::FromHandle(hWnd: Parent),
        v4 = (CMFCToolBarsCustomizeDialog *)AfxDynamicDownCast(
                                              pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog,
                                              pObject: v3),
        this->m_pParentSheet = v4,
        v4 == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  CVSListBoxBase::SetStandardButtons(this: &this->m_wndToolsList, uiBtns: 0xFu);
  this->m_pParentSheet->OnInitToolsPage(this: this->m_pParentSheet);
  m_pNodeHead = afxUserToolsManager->m_lstUserTools.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    this->m_wndToolsList.AddItem(this: &this->m_wndToolsList, a2: &data[1], a3: (unsigned int)data, a4: -1);
  }
  m_uiInitialDirMenuID = afxUserToolsManager->m_uiInitialDirMenuID;
  if ( m_uiInitialDirMenuID != 0 )
  {
    CWnd::ShowWindow(this: &this->m_wndInitialDirBtn, nCmdShow: 5);
    CMenu::LoadMenuA(this: &this->m_menuInitialDir, nIDResource: m_uiInitialDirMenuID);
    SubMenu = GetSubMenu(hMenu: this->m_menuInitialDir.m_hMenu, nPos: 0);
    v9 = (HMENU__ *)CMenu::FromHandle(hMenu: SubMenu);
    if ( v9 != nullptr )
      v9 = *((HMENU__ **)v9 + 1);
    this->m_wndInitialDirBtn.m_hMenu = v9;
  }
  m_uiArgumentsMenuID = afxUserToolsManager->m_uiArgumentsMenuID;
  if ( m_uiArgumentsMenuID != 0 )
  {
    CWnd::ShowWindow(this: &this->m_wndArgumentsBtn, nCmdShow: 5);
    CMenu::LoadMenuA(this: &this->m_menuArguments, nIDResource: m_uiArgumentsMenuID);
    v11 = GetSubMenu(hMenu: this->m_menuArguments.m_hMenu, nPos: 0);
    v12 = (HMENU__ *)CMenu::FromHandle(hMenu: v11);
    if ( v12 != nullptr )
      v12 = *((HMENU__ **)v12 + 1);
    this->m_wndArgumentsBtn.m_hMenu = v12;
  }
  this->m_wndInitialDirBtn.m_bRightArrow = 1;
  this->m_wndArgumentsBtn.m_bRightArrow = 1;
  CMFCToolBarsToolsPropertyPage::EnableControls(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10427379
// Name: public: virtual CMFCToolBarsToolsPropertyPage::~CMFCToolBarsToolsPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::~CMFCToolBarsToolsPropertyPage(CMFCToolBarsToolsPropertyPage *this)
{
  CMenu *p_m_menuInitialDir; // ecx

  this->__vftable = (CMFCToolBarsToolsPropertyPage_vtbl *)&CMFCToolBarsToolsPropertyPage::`vftable';
  p_m_menuInitialDir = &this->m_menuInitialDir;
  p_m_menuInitialDir->__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: p_m_menuInitialDir);
  this->m_menuArguments.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_menuArguments);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strInitialDirectory.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strArguments.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCommand.m_pszData - 1);
  CVSListBox::~CVSListBox(this: &this->m_wndToolsList);
  CButton::~CButton(this: &this->m_wndBrowseBtn);
  CEdit::~CEdit(this: &this->m_wndCommandEdit);
  CEdit::~CEdit(this: &this->m_wndInitialDirEdit);
  CEdit::~CEdit(this: &this->m_wndArgumentsEdit);
  CMFCMenuButton::~CMFCMenuButton(this: &this->m_wndArgumentsBtn);
  CMFCMenuButton::~CMFCMenuButton(this: &this->m_wndInitialDirBtn);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042747F
// Name: protected: void CMFCToolBarsToolsPropertyPage::OnArgumentsOptions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::OnArgumentsOptions(CMFCToolBarsToolsPropertyPage *this)
{
  int v2; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned int m_nMenuResult; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // esi
  int v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strItem; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_wndArgumentsBtn.m_nMenuResult != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strItem, pStringMgr: StringManager);
    m_nMenuResult = this->m_wndArgumentsBtn.m_nMenuResult;
    v9 = 0;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nMenuResult);
    if ( StringResourceHandle == nullptr
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: &strItem,
           hInstance: StringResourceHandle,
           nID: m_nMenuResult) == 0 )
    {
      AfxThrowInvalidArgException();
    }
    m_pszData = strItem.m_pszData;
    v7 = *((_DWORD *)strItem.m_pszData - 3);
    if ( v7 > 0 )
    {
      do
      {
        if ( v2 < 0 || v2 > v7 )
          ATL::AtlThrowImpl(hr: -2147024809);
        SendMessageA(hWnd: this->m_wndArgumentsEdit.m_hWnd, Msg: 0x102u, wParam: m_pszData[v2], lParam: 0);
        v7 = *((_DWORD *)m_pszData - 3);
        ++v2;
      }
      while ( v2 < v7 );
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427516
// Name: protected: void CMFCToolBarsToolsPropertyPage::OnInitialDirectoryOptions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::OnInitialDirectoryOptions(CMFCToolBarsToolsPropertyPage *this)
{
  int v2; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned int m_nMenuResult; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // esi
  int v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strItem; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_wndInitialDirBtn.m_nMenuResult != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strItem, pStringMgr: StringManager);
    m_nMenuResult = this->m_wndInitialDirBtn.m_nMenuResult;
    v9 = 0;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nMenuResult);
    if ( StringResourceHandle != nullptr
      && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: &strItem,
           hInstance: StringResourceHandle,
           nID: m_nMenuResult) != 0 )
    {
      m_pszData = strItem.m_pszData;
      v7 = *((_DWORD *)strItem.m_pszData - 3);
      if ( v7 > 0 )
      {
        do
        {
          if ( v2 < 0 || v2 > v7 )
            ATL::AtlThrowImpl(hr: -2147024809);
          SendMessageA(hWnd: this->m_wndInitialDirEdit.m_hWnd, Msg: 0x102u, wParam: m_pszData[v2], lParam: 0);
          v7 = *((_DWORD *)m_pszData - 3);
          ++v2;
        }
        while ( v2 < v7 );
      }
    }
    else
    {
      m_pszData = strItem.m_pszData;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104275AC
// Name: public: virtual void CVSToolsListBox::OnAfterRenameItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSToolsListBox::OnAfterRenameItem(CVSToolsListBox *this, int iItem)
{
  ATL::CSimpleStringT<char,0> *v3; // edi
  ATL::CStringData *v4; // eax

  v3 = (ATL::CSimpleStringT<char,0> *)this->GetItemData(this, a2: iItem);
  v4 = (ATL::CStringData *)this->GetItemText(this, result: &iItem, a3: iItem);
  ATL::CSimpleStringT<char,0>::operator=(this: v3 + 1, strSrc: v4);
  ATL::CStringData::Release(this: (ATL::CStringData *)(iItem - 16));
}

//------------------------------------------------------------------------------
// Address: 0x104275F8
// Name: public: virtual void CVSToolsListBox::OnSelectionChanged(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSToolsListBox::OnSelectionChanged(CVSToolsListBox *this)
{
  int v2; // eax
  unsigned int v3; // edi

  v2 = this->GetSelItem(this);
  if ( v2 >= 0 )
  {
    v3 = this->GetItemData(this, a2: v2);
    if ( v3 != 0 )
    {
      ATL::CSimpleStringT<char,0>::operator=(
        this: &this->m_pParent->m_strCommand,
        strSrc: (ATL::CStringData *)(v3 + 20));
      ATL::CSimpleStringT<char,0>::operator=(
        this: &this->m_pParent->m_strArguments,
        strSrc: (ATL::CStringData *)(v3 + 8));
      ATL::CSimpleStringT<char,0>::operator=(
        this: &this->m_pParent->m_strInitialDirectory,
        strSrc: (ATL::CStringData *)(v3 + 12));
      goto LABEL_6;
    }
  }
  else
  {
    v3 = 0;
  }
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_pParent->m_strCommand);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_pParent->m_strArguments);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_pParent->m_strInitialDirectory);
LABEL_6:
  this->m_pParent->m_pParentSheet->OnBeforeChangeTool(
    this: this->m_pParent->m_pParentSheet,
    a2: this->m_pParent->m_pSelTool);
  this->m_pParent->m_pSelTool = (CUserTool *)v3;
  CWnd::UpdateData(this: this->m_pParent, bSaveAndValidate: 0);
  CMFCToolBarsToolsPropertyPage::EnableControls(this: this->m_pParent);
  this->m_pParent->m_pParentSheet->OnAfterChangeTool(
    this: this->m_pParent->m_pParentSheet,
    a2: this->m_pParent->m_pSelTool);
}

//------------------------------------------------------------------------------
// Address: 0x104276EE
// Name: protected: void CMFCToolBarsToolsPropertyPage::OnUpdateTool(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::OnUpdateTool(CMFCToolBarsToolsPropertyPage *this)
{
  int v2; // eax
  CUserTool *v3; // edi

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  v2 = this->m_wndToolsList.GetSelItem(this: &this->m_wndToolsList);
  if ( v2 < 0 )
    v3 = nullptr;
  else
    v3 = (CUserTool *)this->m_wndToolsList.GetItemData(this: &this->m_wndToolsList, a2: v2);
  if ( v3 != nullptr )
  {
    CUserTool::SetCommand(this: v3, lpszCmd: this->m_strCommand.m_pszData);
    ATL::CSimpleStringT<char,0>::operator=(this: &v3->m_strArguments, strSrc: (ATL::CStringData *)&this->m_strArguments);
    ATL::CSimpleStringT<char,0>::operator=(
      this: &v3->m_strInitialDirectory,
      strSrc: (ATL::CStringData *)&this->m_strInitialDirectory);
  }
  else
  {
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strCommand);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strArguments);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strInitialDirectory);
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
  CMFCToolBarsToolsPropertyPage::EnableControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042778D
// Name: protected: class CUserTool __near * CMFCToolBarsToolsPropertyPage::CreateNewTool(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserTool *__thiscall CMFCToolBarsToolsPropertyPage::CreateNewTool(CMFCToolBarsToolsPropertyPage *this)
{
  unsigned int v1; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strError; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  v1 = afxUserToolsManager->m_uiCmdLast - afxUserToolsManager->m_uiCmdFirst + 1;
  if ( afxUserToolsManager->m_lstUserTools.m_nCount != v1 )
    return CUserToolsManager::CreateNewTool(this: afxUserToolsManager);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strError, pStringMgr: StringManager);
  v6 = 0;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strError, nFormatID: 0x3E98u, v1);
  m_pszData = strError.m_pszData;
  AfxMessageBox(lpszText: strError.m_pszData, nType: 0, nIDHelp: 0);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104277F3
// Name: public: virtual void CMFCToolBarsToolsPropertyPage::OnOK(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::OnOK(CMFCToolBarsToolsPropertyPage *this)
{
  CMFCToolBarsToolsPropertyPage::OnUpdateTool(this);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10427805
// Name: public: CMFCToolBarsToolsPropertyPage::CMFCToolBarsToolsPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsToolsPropertyPage *__thiscall CMFCToolBarsToolsPropertyPage::CMFCToolBarsToolsPropertyPage(
        CMFCToolBarsToolsPropertyPage *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x4220u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CMFCToolBarsToolsPropertyPage_vtbl *)&CMFCToolBarsToolsPropertyPage::`vftable';
  CMFCMenuButton::CMFCMenuButton(this: &this->m_wndInitialDirBtn);
  CMFCMenuButton::CMFCMenuButton(this: &this->m_wndArgumentsBtn);
  CWnd::CWnd(this: &this->m_wndArgumentsEdit);
  this->m_wndArgumentsEdit.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_wndInitialDirEdit);
  this->m_wndInitialDirEdit.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_wndCommandEdit);
  this->m_wndCommandEdit.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_wndBrowseBtn);
  this->m_wndBrowseBtn.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CVSToolsListBox::CVSToolsListBox(this: &this->m_wndToolsList, pParent: this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCommand, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strArguments, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strInitialDirectory, pStringMgr: v4);
  this->m_menuArguments.m_hMenu = nullptr;
  this->m_menuArguments.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_menuInitialDir.m_hMenu = nullptr;
  this->m_menuInitialDir.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCommand, pszSrc: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strArguments, pszSrc: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strInitialDirectory, pszSrc: &var);
  this->m_pSelTool = nullptr;
  this->m_pParentSheet = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10427956
// Name: public: virtual void CVSToolsListBox::OnAfterAddItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSToolsListBox::OnAfterAddItem(CVSToolsListBox *this, int iItem)
{
  CUserTool *NewTool; // edi
  CVSToolsListBox_vtbl *v4; // eax
  ATL::CStringData *v5; // eax
  int v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  NewTool = CMFCToolBarsToolsPropertyPage::CreateNewTool(this: this->m_pParent);
  v4 = this->__vftable;
  if ( NewTool != nullptr )
  {
    v5 = (ATL::CStringData *)v4->GetItemText(
                               this,
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v6,
                               a3: iItem);
    v7 = 0;
    ATL::CSimpleStringT<char,0>::operator=(this: &NewTool->m_strLabel, strSrc: v5);
    v7 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)(v6 - 16));
    this->SetItemData(this, a2: iItem, a3: (unsigned int)NewTool);
    this->OnSelectionChanged(this);
  }
  else
  {
    v4->RemoveItem(this, a2: iItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104279CC
// Name: protected: void CMFCToolBarsToolsPropertyPage::OnBrowseCommand(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsToolsPropertyPage::OnBrowseCommand(CMFCToolBarsToolsPropertyPage *this)
{
  ATL::CStringData *PathName; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-218h] BYREF
  CFileDialog v4; // [esp+14h] [ebp-214h] BYREF
  int v5; // [esp+224h] [ebp-4h]

  CFileDialog::CFileDialog(
    this: &v4,
    bOpenFileDialog: 1,
    lpszDefExt: afxUserToolsManager->m_strDefExt.m_pszData,
    lpszFileName: nullptr,
    dwFlags: 0,
    lpszFilter: afxUserToolsManager->m_strFilter.m_pszData,
    pParentWnd: this,
    dwSize: 0,
    bVistaStyle: 1);
  v5 = 0;
  if ( CFileDialog::DoModal(this: &v4) == 1 )
  {
    PathName = (ATL::CStringData *)CFileDialog::GetPathName(this: &v4, &result);
    LOBYTE(v5) = 1;
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strCommand, strSrc: PathName);
    LOBYTE(v5) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
    CWnd::UpdateData(this, bSaveAndValidate: 0);
    CMFCToolBarsToolsPropertyPage::OnUpdateTool(this);
  }
  v5 = -1;
  CFileDialog::~CFileDialog(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10427A69
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarsToolsPropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarsToolsPropertyPage::GetMessageMap(CMFCToolBarsToolsPropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_10692780;
}

//------------------------------------------------------------------------------
// Address: 0x10427A6F
// Name: public: virtual struct CRuntimeClass __near * CMFCMousePropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCMousePropertyPage::GetRuntimeClass(CMFCMousePropertyPage *this)
{
  return &CMFCMousePropertyPage::classCMFCMousePropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x10427A75
// Name: protected: virtual void CMFCMousePropertyPage::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::DoDataExchange(CMFCMousePropertyPage *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 16631, rControl: &this->m_wndListOfViews);
  DDX_Control(pDX, nIDC: 16634, rControl: &this->m_wndListOfCommands);
  DDX_Control(pDX, nIDC: 16514, rControl: &this->m_wndCommandDescription);
  DDX_Text(pDX, nIDC: 16514, value: &this->m_strCommandDescription);
}

//------------------------------------------------------------------------------
// Address: 0x10427ACE
// Name: protected: void CMFCMousePropertyPage::OnSelchangeListOfCommands(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::OnSelchangeListOfCommands(CMFCMousePropertyPage *this)
{
  WPARAM v2; // eax
  LRESULT v3; // edi
  CFrameWnd *ParentFrame; // eax

  if ( afxMouseManager == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_iCurrViewId >= 0 )
  {
    v2 = SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
    v3 = SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    ParentFrame = CWnd::GetParentFrame(this);
    if ( ParentFrame != nullptr && ParentFrame->m_hWnd != nullptr )
      ParentFrame->GetMessageString(this: ParentFrame, a2: v3, a3: &this->m_strCommandDescription);
    else
      ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strCommandDescription);
    CMouseManager::SetCommandForDblClk(this: afxMouseManager, iViewId: this->m_iCurrViewId, uiCmd: v3);
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
  else
  {
    MessageBeep(uType: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427B69
// Name: protected: void CMFCMousePropertyPage::EnableDblClkControls(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::EnableDblClkControls(CMFCMousePropertyPage *this, int bEnable)
{
  CWnd::EnableWindow(this: &this->m_wndListOfCommands, bEnable);
  CWnd::EnableWindow(this: &this->m_wndCommandDescription, bEnable);
  if ( bEnable == 0 )
  {
    SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x186u, wParam: 0xFFFFFFFF, lParam: 0);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strCommandDescription);
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427BC1
// Name: protected: int CMFCMousePropertyPage::SelectCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCMousePropertyPage::SelectCommand(CMFCMousePropertyPage *this, unsigned int uiCmd)
{
  CFrameWnd *ParentFrame; // eax
  WPARAM iCmdIndex; // [esp+Ch] [ebp-4h]

  ParentFrame = CWnd::GetParentFrame(this);
  if ( ParentFrame != nullptr && ParentFrame->m_hWnd != nullptr )
    ParentFrame->GetMessageString(this: ParentFrame, a2: uiCmd, a3: &this->m_strCommandDescription);
  else
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strCommandDescription);
  CWnd::UpdateData(this, bSaveAndValidate: 0);
  iCmdIndex = 0;
  if ( SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) <= 0 )
    return 0;
  while ( uiCmd != SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x199u, wParam: iCmdIndex, lParam: 0) )
  {
    if ( (int)++iCmdIndex >= SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
      return 0;
  }
  SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x186u, wParam: iCmdIndex, lParam: 0);
  SendMessageA(hWnd: this->m_wndListOfCommands.m_hWnd, Msg: 0x197u, wParam: iCmdIndex, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10427C7E
// Name: public: virtual CMFCMousePropertyPage::~CMFCMousePropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::~CMFCMousePropertyPage(CMFCMousePropertyPage *this)
{
  this->__vftable = (CMFCMousePropertyPage_vtbl *)&CMFCMousePropertyPage::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCommandDescription.m_pszData - 1);
  CStatic::~CStatic(this: &this->m_wndCommandDescription);
  CListBox::~CListBox(this: &this->m_wndListOfCommands);
  CListCtrl::~CListCtrl(this: &this->m_wndListOfViews);
  CImageList::~CImageList(this: &this->m_ViewsImages);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x10427CF3
// Name: protected: void CMFCMousePropertyPage::OnNoDblcliick(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::OnNoDblcliick(CMFCMousePropertyPage *this)
{
  CMouseManager::SetCommandForDblClk(this: afxMouseManager, iViewId: this->m_iCurrViewId, uiCmd: 0);
  CMFCMousePropertyPage::EnableDblClkControls(this, bEnable: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10427D16
// Name: protected: void CMFCMousePropertyPage::OnUseDblcliick(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::OnUseDblcliick(CMFCMousePropertyPage *this)
{
  int m_iCurrViewId; // esi

  CMFCMousePropertyPage::EnableDblClkControls(this, bEnable: 1);
  m_iCurrViewId = this->m_iCurrViewId;
  if ( m_iCurrViewId >= 0 )
    CMouseManager::SetCommandForDblClk(this: afxMouseManager, iViewId: m_iCurrViewId, uiCmd: 0);
  else
    MessageBeep(uType: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10427D46
// Name: protected: void CMFCMousePropertyPage::OnItemchangedListViews(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCMousePropertyPage::OnItemchangedListViews(
        CMFCMousePropertyPage *this,
        tagNMHDR *pNMHDR,
        int *pResult)
{
  int ItemData; // eax
  unsigned int ViewDblClickCommand; // edi
  int i; // [esp+Ch] [ebp+8h]

  if ( afxMouseManager == nullptr || pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  *pResult = 0;
  if ( pNMHDR[2].idFrom == 8 )
  {
    i = 0;
    if ( SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      while ( (SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x102Cu, wParam: i, lParam: 10) & 2) == 0 )
      {
        if ( ++i >= SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) )
          return;
      }
      ItemData = CListCtrl::GetItemData(this: &this->m_wndListOfViews, nItem: i);
      this->m_iCurrViewId = ItemData;
      ViewDblClickCommand = CMouseManager::GetViewDblClickCommand(this: afxMouseManager, iId: ItemData);
      if ( ViewDblClickCommand != 0 )
      {
        CWnd::CheckDlgButton(this, nIDButton: 16633, nCheck: 1u);
        CWnd::CheckDlgButton(this, nIDButton: 16632, nCheck: 0);
        CMFCMousePropertyPage::EnableDblClkControls(this, bEnable: 1);
        CMFCMousePropertyPage::SelectCommand(this, uiCmd: ViewDblClickCommand);
      }
      else
      {
        CWnd::CheckDlgButton(this, nIDButton: 16633, nCheck: 0);
        CWnd::CheckDlgButton(this, nIDButton: 16632, nCheck: 1u);
        CMFCMousePropertyPage::EnableDblClkControls(this, bEnable: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427E41
// Name: protected: virtual int CMFCMousePropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCMousePropertyPage::OnInitDialog(CMFCMousePropertyPage *this)
{
  CStringList::CNode *m_pNodeHead; // eax
  int ViewIdByName; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON__ *IconW; // eax
  HICON v6; // eax
  int v7; // eax
  ATL::CStringData *v8; // ecx
  LRESULT v9; // eax
  int v10; // eax
  LRESULT v11; // eax
  AFX_MODULE_STATE *v12; // eax
  HWND Parent; // eax
  CWnd *v14; // eax
  CObject *v15; // eax
  HWND__ *v17; // [esp-10h] [ebp-A8h]
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-A4h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-A0h]
  ATL::CStringData *v20; // [esp-4h] [ebp-9Ch]
  CStringList listOfNames; // [esp+10h] [ebp-88h] BYREF
  CStringList::CNode *pNext; // [esp+2Ch] [ebp-6Ch]
  int nImage; // [esp+30h] [ebp-68h]
  LRESULT v24; // [esp+34h] [ebp-64h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v25; // [esp+38h] [ebp-60h] BYREF
  char *psz; // [esp+3Ch] [ebp-5Ch]
  int nItem; // [esp+40h] [ebp-58h]
  HICON hIcon; // [esp+44h] [ebp-54h]
  _IMAGEINFO pImageInfo; // [esp+48h] [ebp-50h] BYREF
  tagRECT rcDst; // [esp+68h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+78h] [ebp-20h] BYREF
  int v32; // [esp+94h] [ebp-4h]

  if ( afxMouseManager == nullptr )
    goto LABEL_2;
  CDialog::OnInitDialog(this);
  CStringList::CStringList(this: &listOfNames, nBlockSize: 10);
  v32 = 0;
  CMouseManager::GetViewNames(this: afxMouseManager, &listOfNames);
  CImageList::Create(
    this: &this->m_ViewsImages,
    cx: afxGlobalData.m_sizeSmallIcon.cx,
    cy: afxGlobalData.m_sizeSmallIcon.cy,
    nFlags: 1u,
    nInitial: listOfNames.m_nCount,
    nGrow: 1);
  CListCtrl::SetImageList(this: &this->m_wndListOfViews, pImageList: &this->m_ViewsImages, nImageList: 1);
  m_hWnd = this->m_wndListOfViews.m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  CListCtrl::InsertColumn(
    this: &this->m_wndListOfViews,
    nCol: 0,
    lpszColumnHeading: &var,
    nFormat: 0,
    nWidth: Rect.right - Rect.left - 1,
    nSubItem: -1);
  m_pNodeHead = listOfNames.m_pNodeHead;
  v24 = 0;
  if ( listOfNames.m_pNodeHead != nullptr )
  {
    while ( m_pNodeHead != nullptr )
    {
      v20 = (ATL::CStringData *)(m_pNodeHead->data.m_pszData - 16);
      pNext = m_pNodeHead->pNext;
      psz = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: v20)[1];
      nImage = -1;
      LOBYTE(v32) = 1;
      ViewIdByName = CMouseManager::GetViewIdByName(this: afxMouseManager, lpszName: psz);
      hIcon = (HICON)CMouseManager::GetViewIconId(this: afxMouseManager, iViewId: ViewIdByName);
      if ( hIcon != nullptr )
      {
        AfxGetModuleState();
        ModuleState = AfxGetModuleState();
        IconW = LoadIconW(
                  hInstance: ModuleState->m_hCurrentResourceHandle,
                  lpIconName: (LPCWSTR)(unsigned __int16)hIcon);
        hIcon = IconW;
        if ( IconW != nullptr )
        {
          nImage = CImageList::Add(this: &this->m_ViewsImages, hIcon: IconW);
          DestroyIcon(hIcon);
        }
      }
      v6 = (HICON)SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
      v17 = this->m_wndListOfViews.m_hWnd;
      hIcon = v6;
      nItem = 0;
      if ( SendMessageA(hWnd: v17, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
      {
        while ( 1 )
        {
          CListCtrl::GetItemText(this: &this->m_wndListOfViews, result: &v25, nItem, nSubItem: 0);
          LOBYTE(v32) = 2;
          v7 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &v25, psz);
          v8 = (ATL::CStringData *)(v25.m_pszData - 16);
          LOBYTE(v32) = 1;
          if ( v7 > 0 )
            break;
          ATL::CStringData::Release(this: v8);
          ++nItem;
          v9 = SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
          if ( nItem >= v9 )
            goto LABEL_15;
        }
        hIcon = (HICON)nItem;
        ATL::CStringData::Release(this: v8);
      }
LABEL_15:
      CListCtrl::InsertItem(
        this: &this->m_wndListOfViews,
        nMask: 3u,
        nItem: (int)hIcon,
        lpszItem: psz,
        nState: 0,
        nStateMask: 0,
        nImage,
        lParam: 0);
      v10 = CMouseManager::GetViewIdByName(this: afxMouseManager, lpszName: psz);
      CListCtrl::SetItem(
        this: &this->m_wndListOfViews,
        nItem: (int)hIcon,
        nSubItem: 0,
        nMask: 4u,
        lpszItem: nullptr,
        nImage: 0,
        nState: 0,
        nStateMask: 0,
        lParam: v10);
      v11 = SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1011u, wParam: 0, lParam: (LPARAM)psz);
      if ( v11 > v24 )
        v24 = v11;
      LOBYTE(v32) = 0;
      ATL::CStringData::Release(this: (ATL::CStringData *)psz - 1);
      if ( pNext == nullptr )
        goto LABEL_18;
      m_pNodeHead = pNext;
    }
LABEL_2:
    AfxThrowInvalidArgException();
  }
LABEL_18:
  m_hImageList = this->m_ViewsImages.m_hImageList;
  v12 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_GetImageInfo(
    this: *(CComCtlWrapper **)v12->m_pDllIsolationWrappers,
    himl: m_hImageList,
    i: 0,
    &pImageInfo);
  CopyRect(lprcDst: &rcDst, lprcSrc: &pImageInfo.rcImage);
  SendMessageA(
    hWnd: this->m_wndListOfViews.m_hWnd,
    Msg: 0x101Eu,
    wParam: 0,
    lParam: (unsigned __int16)(v24 + LOWORD(rcDst.right) - LOWORD(rcDst.left) + 10));
  Parent = GetParent(hWnd: this->m_hWnd);
  v14 = CWnd::FromHandle(hWnd: Parent);
  v15 = AfxDynamicDownCast(pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog, pObject: v14);
  if ( v15 == nullptr )
    goto LABEL_2;
  v15->__vftable[30].Serialize(this: v15, a2: (CArchive *)&this->m_wndListOfCommands);
  CListCtrl::SetItemState(this: &this->m_wndListOfViews, nItem: 0, nState: 3u, nStateMask: 3u);
  SendMessageA(hWnd: this->m_wndListOfViews.m_hWnd, Msg: 0x1013u, wParam: 0, lParam: 0);
  v32 = -1;
  CStringList::~CStringList(this: &listOfNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10428157
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCMousePropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCMousePropertyPage::GetMessageMap(CMFCMousePropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_10692A18;
}

//------------------------------------------------------------------------------
// Address: 0x1042815D
// Name: public: CMFCMousePropertyPage::CMFCMousePropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCMousePropertyPage *__thiscall CMFCMousePropertyPage::CMFCMousePropertyPage(CMFCMousePropertyPage *this)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x3F07u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CMFCMousePropertyPage_vtbl *)&CMFCMousePropertyPage::`vftable';
  CImageList::CImageList(this: &this->m_ViewsImages);
  CWnd::CWnd(this: &this->m_wndListOfViews);
  this->m_wndListOfViews.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_wndListOfCommands);
  this->m_wndListOfCommands.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::CWnd(this: &this->m_wndCommandDescription);
  this->m_wndCommandDescription.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCommandDescription, pStringMgr: StringManager);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCommandDescription, pszSrc: &var);
  this->m_iCurrViewId = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10428214
// Name: public: static class CObject __near * CMFCMousePropertyPage::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCMousePropertyPage *__stdcall CMFCMousePropertyPage::CreateObject()
{
  CMFCMousePropertyPage *v0; // ecx
  CMFCMousePropertyPage *result; // eax

  v0 = (CMFCMousePropertyPage *)operator new(nSize: 0x214u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCMousePropertyPage::CMFCMousePropertyPage(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428244
// Name: public: virtual struct CRuntimeClass __near * CMFCOutlookBarPaneAdapter::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCOutlookBarPaneAdapter::GetRuntimeClass(CMFCOutlookBarPaneAdapter *this)
{
  return &CMFCOutlookBarPaneAdapter::classCMFCOutlookBarPaneAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x1042824A
// Name: public: CMFCOutlookBarPaneAdapter::CMFCOutlookBarPaneAdapter(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPaneAdapter *__thiscall CMFCOutlookBarPaneAdapter::CMFCOutlookBarPaneAdapter(
        CMFCOutlookBarPaneAdapter *this)
{
  CDockablePaneAdapter::CDockablePaneAdapter(this);
  this->__vftable = (CMFCOutlookBarPaneAdapter_vtbl *)&CMFCOutlookBarPaneAdapter::`vftable';
  this->m_pTabbedControlBarRTC = &CMFCOutlookBar::classCMFCOutlookBar;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10428268
// Name: protected: void CMFCOutlookBarPaneAdapter::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPaneAdapter::OnNcDestroy(CMFCOutlookBarPaneAdapter *this)
{
  CPane::OnNcDestroy(this);
  if ( this != nullptr )
    ((void (__thiscall *)(CMFCOutlookBarPaneAdapter *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10428281
// Name: public: static class CObject __near * CMFCOutlookBarPaneAdapter::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPaneAdapter *__stdcall CMFCOutlookBarPaneAdapter::CreateObject()
{
  CMFCOutlookBarPaneAdapter *v0; // ecx
  CMFCOutlookBarPaneAdapter *result; // eax

  v0 = (CMFCOutlookBarPaneAdapter *)operator new(nSize: 0x368u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCOutlookBarPaneAdapter::CMFCOutlookBarPaneAdapter(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104282D8
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCOutlookBarPaneAdapter::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCOutlookBarPaneAdapter::GetMessageMap(CMFCOutlookBarPaneAdapter *this)
{
  return (const AFX_MSGMAP *)&off_10692E68;
}

//------------------------------------------------------------------------------
// Address: 0x104282DE
// Name: public: _AFX_OLE_STATE::_AFX_OLE_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_OLE_STATE *__thiscall _AFX_OLE_STATE::_AFX_OLE_STATE(_AFX_OLE_STATE *this)
{
  this->__vftable = (_AFX_OLE_STATE_vtbl *)&_AFX_OLE_STATE::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042832F
// Name: public: CSmartDockingHighlighterWnd::CSmartDockingHighlighterWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartDockingHighlighterWnd *__thiscall CSmartDockingHighlighterWnd::CSmartDockingHighlighterWnd(
        CSmartDockingHighlighterWnd *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CSmartDockingHighlighterWnd_vtbl *)&CSmartDockingHighlighterWnd::`vftable';
  this->m_pWndOwner = nullptr;
  this->m_rectLast.left = 0;
  this->m_rectLast.top = 0;
  this->m_rectLast.right = 0;
  this->m_rectLast.bottom = 0;
  this->m_rectTab.left = 0;
  this->m_rectTab.top = 0;
  this->m_rectTab.right = 0;
  this->m_rectTab.bottom = 0;
  this->m_bTabbed = 0;
  this->m_bShown = 0;
  this->m_bUseThemeColorInShading = 0;
  SetRectEmpty(lprc: &this->m_rectLast);
  SetRectEmpty(lprc: &this->m_rectTab);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10428389
// Name: public: virtual CSmartDockingHighlighterWnd::~CSmartDockingHighlighterWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::~CSmartDockingHighlighterWnd(CSmartDockingHighlighterWnd *this)
{
  this->__vftable = (CSmartDockingHighlighterWnd_vtbl *)&CSmartDockingHighlighterWnd::`vftable';
  CWnd::~CWnd(this);
}
