// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/objectbar.cpp
// Functions: 31
// ============================================================

#include "hammer\objectbar.h"

//------------------------------------------------------------------------------
// Address: 0x10088600
// Name: FindSolidType
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindSolidType(const char *pName)
{
  int v1; // edi
  unsigned int v2; // esi

  v1 = 0;
  v2 = 0;
  while ( _V_stricmp(s1: pName, s2: SolidTypes[v2].pszName) != 0 )
  {
    ++v2;
    ++v1;
    if ( v2 >= 7 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10088650
// Name: public: int CObjectBar::GetPrefabBounds(class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectBar::GetPrefabBounds(CObjectBar *this, BoundBox *pBox)
{
  CPrefab *ID; // eax
  CMapClass **v4; // esi
  Vector maxs; // [esp+0h] [ebp-18h] BYREF
  Vector mins; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->ListType != listPrefabs )
    return 0;
  ID = CPrefab::FindID(dwID: iNewObjIndex);
  v4 = (CMapClass **)ID;
  if ( ID == nullptr || ID->GetType(this: ID) != 0 )
    return 0;
  if ( ((unsigned __int8 (__thiscall *)(CMapClass **))LODWORD((*v4)->m_Origin.y))(a1: v4) == 0 )
    ((void (__thiscall *)(CMapClass **, _DWORD))(*v4)->m_pParent)(a1: v4, a2: 0);
  if ( ((unsigned __int8 (__thiscall *)(CMapClass **))LODWORD((*v4)->m_Origin.y))(a1: v4) == 0 )
    return 0;
  CMapClass::GetRender2DBox(this: v4[138], &mins, &maxs);
  pBox->bmins = mins;
  pBox->bmaxs = maxs;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088720
// Name: public: static char const __near * CObjectBar::GetDefaultEntityClass(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CObjectBar::GetDefaultEntityClass()
{
  return szNewObjName;
}

//------------------------------------------------------------------------------
// Address: 0x10088730
// Name: public: class CMapClass __near * CObjectBar::BuildPrefabObjectAtPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPrefab3D *__thiscall CObjectBar::BuildPrefabObjectAtPoint(CObjectBar *this, const Vector *HitPos)
{
  CPrefab3D *result; // eax

  result = (CPrefab3D *)CPrefab::FindID(dwID: iNewObjIndex);
  if ( result != nullptr )
    return (CPrefab3D *)CPrefab3D::CreateAtPointAroundOrigin(this: result, point: HitPos);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088760
// Name: public: void CObjectBar::DoHideControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::DoHideControls(CObjectBar *this)
{
  CObjectBar::<unnamed_type_ListType> ListType; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]

  ListType = this->ListType;
  switch ( ListType )
  {
    case listPrimitives:
      DlgItem = CWnd::GetDlgItem(this, nID: 1219);
      CWnd::ShowWindow(this: DlgItem, nCmdShow: 0);
      CWnd::ShowWindow(this: &this->m_Faces, nCmdShow: 5);
      CWnd::ShowWindow(this: &this->m_FacesSpin, nCmdShow: 5);
      v8 = 5;
      v4 = CWnd::GetDlgItem(this, nID: 1278);
LABEL_8:
      CWnd::ShowWindow(this: v4, nCmdShow: v8);
      break;
    case listPrefabs:
      CWnd::ShowWindow(this: &this->m_Faces, nCmdShow: 0);
      CWnd::ShowWindow(this: &this->m_FacesSpin, nCmdShow: 0);
      v5 = CWnd::GetDlgItem(this, nID: 1278);
      CWnd::ShowWindow(this: v5, nCmdShow: 0);
      v8 = 5;
LABEL_7:
      v4 = CWnd::GetDlgItem(this, nID: 1219);
      goto LABEL_8;
    case listEntities:
      CWnd::ShowWindow(this: &this->m_Faces, nCmdShow: 0);
      CWnd::ShowWindow(this: &this->m_FacesSpin, nCmdShow: 0);
      v6 = CWnd::GetDlgItem(this, nID: 1278);
      CWnd::ShowWindow(this: v6, nCmdShow: 0);
      v8 = 0;
      goto LABEL_7;
    default:
      break;
  }
  v9 = this->ListType == listEntities ? 5 : 0;
  v7 = CWnd::GetDlgItem(this, nID: 1278);
  CWnd::ShowWindow(this: v7, nCmdShow: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10088850
// Name: protected: void CObjectBar::UpdateControl(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::UpdateControl(CObjectBar *this, CCmdUI *pCmdUI)
{
  int v2; // edi
  ToolID_t ActiveToolID; // eax

  if ( pCmdUI->m_nID == 1007 || pCmdUI->m_nID == 1010 )
  {
    v2 = 0;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      ActiveToolID = CToolManager::GetActiveToolID(this: CMapDoc::m_pMapDoc->m_pToolManager);
      if ( ActiveToolID == TOOL_ENTITY || ActiveToolID == TOOL_BLOCK )
        v2 = 1;
    }
    pCmdUI->Enable(this: pCmdUI, a2: v2);
  }
  else if ( pCmdUI->m_nID == 1219 )
  {
    pCmdUI->Enable(this: pCmdUI, a2: this->ListType == listPrefabs);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: CMapDoc::m_pMapDoc != nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100888E0
// Name: protected: void CObjectBar::UpdateFaceControl(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::UpdateFaceControl(CObjectBar *this, CCmdUI *pCmdUI)
{
  BOOL v3; // eax

  CWnd::GetDlgItem(this, nID: pCmdUI->m_nID);
  v3 = CMapDoc::m_pMapDoc != nullptr;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = false;
    if ( this->ListType == listPrimitives )
      v3 = byte_1072E438[20 * this->iBlockSel] != 0;
  }
  pCmdUI->Enable(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10088940
// Name: public: virtual int CObjectBar::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectBar::PreTranslateMessage(CObjectBar *this, tagMSG *pMsg)
{
  return CControlBar::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10088980
// Name: public: class CWnd __near * CSpinButtonCtrl::SetBuddy(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CSpinButtonCtrl::SetBuddy(CSpinButtonCtrl *this, CWnd *pWndBuddy)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v3; // eax

  m_hWnd = (HWND__ *)pWndBuddy;
  if ( pWndBuddy != nullptr )
    m_hWnd = pWndBuddy->m_hWnd;
  v3 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x469u, wParam: (WPARAM)m_hWnd, lParam: 0);
  return CWnd::FromHandle(hWnd: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100889B0
// Name: public: void CSpinButtonCtrl::SetRange(short,short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpinButtonCtrl::SetRange(CSpinButtonCtrl *this, unsigned __int16 nLower, unsigned __int16 nUpper)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x465u, wParam: 0, lParam: nUpper | (nLower << 16));
}

//------------------------------------------------------------------------------
// Address: 0x100889E0
// Name: public: bool CObjectBar::UseRandomYawOnEntityPlacement(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CObjectBar::UseRandomYawOnEntityPlacement(CObjectBar *this)
{
  HWND__ *m_hWnd; // eax
  HWND DlgItem; // eax

  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  DlgItem = GetDlgItem(hDlg: m_hWnd, nIDDlgItem: 1278);
  return SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088A10
// Name: public: virtual void CObjectBar::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::DoDataExchange(CObjectBar *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_CreateList);
}

//------------------------------------------------------------------------------
// Address: 0x10088A30
// Name: private: class CPrefab __near * CObjectBar::FindPrefabByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrefab *__thiscall CObjectBar::FindPrefabByName(CObjectBar *this, const char *pName)
{
  WPARAM v3; // eax
  LRESULT v4; // eax
  CPrefabLibrary *ID; // eax
  CPrefabLibrary *v6; // edi
  CPrefab *v7; // esi
  __POSITION *p; // [esp+Ch] [ebp-4h] BYREF

  v3 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v4 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
  ID = CPrefabLibrary::FindID(dwID: v4);
  v6 = ID;
  if ( ID == nullptr )
    return nullptr;
  p = (__POSITION *)1;
  v7 = CPrefabLibrary::EnumPrefabs(this: ID, &p);
  if ( v7 == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: pName, s2: v7->szName) != 0 )
  {
    v7 = CPrefabLibrary::EnumPrefabs(this: v6, &p);
    if ( v7 == nullptr )
      return nullptr;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10088AD0
// Name: public: bool CObjectBar::IsEntityToolCreatingPrefab(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CObjectBar::IsEntityToolCreatingPrefab(CObjectBar *this)
{
  return this->m_iLastTool == 2
      && SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10088B00
// Name: public: bool CObjectBar::IsEntityToolCreatingEntity(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CObjectBar::IsEntityToolCreatingEntity(CObjectBar *this)
{
  return this->m_iLastTool == 2
      && SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10088B30
// Name: private: void CObjectBar::LoadPrefabCategories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadPrefabCategories(CObjectBar *this)
{
  CPrefabLibrary *i; // esi
  WPARAM v3; // eax
  __POSITION *p; // [esp+Ch] [ebp-4h] BYREF

  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  p = (__POSITION *)1;
  for ( i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None);
        i != nullptr;
        i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None) )
  {
    v3 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)i->m_szName);
    SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x151u, wParam: v3, lParam: i->dwID);
  }
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_CategoryList.m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10088BE0
// Name: FindGameDataClass
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindGameDataClass(const char *pName)
{
  GameData *v1; // eax
  int m_Size; // edi
  int v3; // esi
  GDclass *v5; // eax

  v1 = pGD;
  if ( pGD == nullptr )
    return -1;
  m_Size = pGD->m_Classes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v5 = v3 < v1->m_Classes.m_Size ? v1->m_Classes.m_Memory.m_pMemory[v3] : nullptr;
    if ( _V_stricmp(s1: pName, s2: v5->m_szName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    v1 = pGD;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10088C40
// Name: private: void CObjectBar::LoadBlockCategories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadBlockCategories(CObjectBar *this)
{
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Primitives");
  CObjectBar::LoadPrefabCategories(this);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_CategoryList.m_hWnd, lpRect: nullptr, bErase: true);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10088CC0
// Name: private: void CObjectBar::LoadEntityCategories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadEntityCategories(CObjectBar *this)
{
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Entities");
  CObjectBar::LoadPrefabCategories(this);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_CategoryList.m_hWnd, lpRect: nullptr, bErase: true);
  SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10088D40
// Name: public: virtual void CObjectBar::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::OnTextChanged(CObjectBar *this, const char *pSelection)
{
  int m_dwRef; // eax
  int v4; // eax
  CPrefab *PrefabByName; // eax
  char *m_pszData; // ecx
  CEdit_vtbl *dwID; // eax
  int SolidType; // eax
  CEdit_vtbl *v9; // edi
  BOOL v10; // eax
  BOOL v11; // eax
  unsigned int v12; // edi
  char szBuf[128]; // [esp+8h] [ebp-80h] BYREF

  m_dwRef = this->m_dwRef;
  if ( m_dwRef != 0 )
  {
    v4 = m_dwRef - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        iNewObjIndex = FindGameDataClass(pName: pSelection);
        if ( iNewObjIndex != -1 )
          V_strncpy(pDest: szNewObjName, pSrc: pSelection, maxLen: 128);
      }
    }
    else
    {
      PrefabByName = CObjectBar::FindPrefabByName(this: (CObjectBar *)((char *)this - 236), pName: pSelection);
      if ( PrefabByName != nullptr )
      {
        m_pszData = this->m_PrevSel[0].block.strItem.m_pszData;
        dwID = (CEdit_vtbl *)PrefabByName->dwID;
        iNewObjIndex = (unsigned int)dwID;
        if ( m_pszData == (char *)1 )
        {
          this->m_Faces.__vftable = dwID;
        }
        else if ( m_pszData == (char *)2 )
        {
          this->m_CategoryList.m_pMFCCtrlContainer = (CMFCControlContainer *)dwID;
        }
      }
    }
  }
  else
  {
    SolidType = FindSolidType(pName: pSelection);
    v9 = this->m_Faces.__vftable;
    iNewObjIndex = SolidType;
    if ( v9 != (CEdit_vtbl *)-1 )
    {
      CWnd::GetWindowTextA(this: (CWnd *)&this->m_CreateList.m_ptGestureFrom, lpszString: szBuf, nMaxCount: 128);
      dword_1072E42C[5 * (_DWORD)v9] = atoi(nptr: szBuf);
    }
    this->m_Faces.__vftable = (CEdit_vtbl *)iNewObjIndex;
  }
  if ( this->m_dwRef == 0 )
  {
    v10 = CMapDoc::m_pMapDoc != nullptr;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v10 = false;
      if ( this->m_dwRef == 0 )
        v10 = byte_1072E438[20 * (int)this->m_Faces.__vftable] != 0;
    }
    CWnd::EnableWindow(this: (CWnd *)&this->m_CreateList.m_ptGestureFrom, bEnable: v10);
    v11 = CMapDoc::m_pMapDoc != nullptr;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v11 = false;
      if ( this->m_dwRef == 0 )
        v11 = byte_1072E438[20 * (int)this->m_Faces.__vftable] != 0;
    }
    CWnd::EnableWindow(this: (CWnd *)&this->m_CreateList.m_LastTextChangedValue, bEnable: v11);
    v12 = 5 * iNewObjIndex;
    SendMessageA(
      hWnd: (HWND)this->m_CategoryList.m_pModuleState,
      Msg: 0x465u,
      wParam: 0,
      lParam: LOWORD(dword_1072E434[5 * iNewObjIndex]) | (LOWORD(dword_1072E430[5 * iNewObjIndex]) << 16));
    SendMessageA(
      hWnd: (HWND)this->m_CategoryList.m_pModuleState,
      Msg: 0x467u,
      wParam: 0,
      lParam: LOWORD(dword_1072E42C[v12]));
    itoa(val: dword_1072E42C[v12], buf: szBuf, radix: 0xAu);
    CWnd::SetWindowTextA(this: (CWnd *)&this->m_CreateList.m_ptGestureFrom, lpszString: szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088F20
// Name: public: CObjectBar::tagprevsel::tagblock::tagblock(void)
// Source: json
//------------------------------------------------------------------------------
CObjectBar::tagprevsel::tagentity *__thiscall CObjectBar::tagprevsel::tagblock::tagblock(
        CObjectBar::tagprevsel::tagentity *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->strItem.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v3 = AfxGetStringManager();
  if ( v3 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->strCategory.m_pszData = (char *)&v3->GetNilString(this: v3)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10088FC0
// Name: public: int CObjectBar::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectBar::Create(CObjectBar *this, CWnd *pParentWnd)
{
  int result; // eax
  void *p_m_Faces; // edi
  HWND__ *v5; // eax

  result = CHammerBar::Create(this, pParentWnd, nIDTemplate: 0xA2u, nStyle: 0x4100u, nID: 0xE808u);
  if ( result != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: "New Objects");
    CFilteredComboBox::SubclassDlgItem(this: &this->m_CreateList, nID: 0x3EFu, pParent: this);
    CFilteredComboBox::SetOnlyProvideSuggestions(this: &this->m_CreateList, bOnlyProvideSuggestions: true);
    CWnd::SubclassDlgItem(this: &this->m_CategoryList, nID: 0x3F2u, pParent: this);
    p_m_Faces = &this->m_Faces;
    CWnd::SubclassDlgItem(this: &this->m_Faces, nID: 0x3F1u, pParent: this);
    CWnd::SubclassDlgItem(this: &this->m_FacesSpin, nID: 0x3F0u, pParent: this);
    if ( this != (CObjectBar *)-540 )
      p_m_Faces = this->m_Faces.m_hWnd;
    v5 = (HWND__ *)SendMessageA(hWnd: this->m_FacesSpin.m_hWnd, Msg: 0x469u, wParam: (WPARAM)p_m_Faces, lParam: 0);
    CWnd::FromHandle(hWnd: v5);
    this->iBlockSel = -1;
    this->iEntitySel = -1;
    this->m_iLastTool = -1;
    CObjectBar::LoadBlockCategories(this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10089090
// Name: public: CObjectBar::tagprevsel::tagprevsel(void)
// Source: json
//------------------------------------------------------------------------------
CObjectBar::tagprevsel *__thiscall CObjectBar::tagprevsel::tagprevsel(CObjectBar::tagprevsel *this)
{
  CObjectBar::tagprevsel::tagblock::tagblock(this: (CObjectBar::tagprevsel::tagentity *)&this->block);
  CObjectBar::tagprevsel::tagblock::tagblock(this: &this->entity);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100890E0
// Name: public: class CMapClass __near * CObjectBar::CreateInBox(class BoundBox __near *,class CMapView __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CObjectBar::CreateInBox(CObjectBar *this, BoundBox *pBox, CMapView *pView)
{
  _DWORD *v4; // eax
  int v5; // edx
  CMapView *v6; // ecx
  int v7; // ebx
  __int64 v8; // rdi
  bool v9; // zf
  CAfxStringMgr *StringManager; // eax
  BoundBox *v11; // esi
  CMapView *v13; // eax
  StockBlock *v14; // eax
  StockSolid *v15; // esi
  CMapView *v16; // eax
  StockWedge *v17; // eax
  CMapView *v18; // eax
  StockCylinder *v19; // eax
  CMapView *v20; // eax
  CMapView *v21; // eax
  CMapView *v22; // eax
  CMapSolid *Arch; // ebx
  StockSolid_vtbl *v24; // edi
  int v25; // eax
  const char *v26; // eax
  int v27; // eax
  int v28; // ecx
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v31; // ecx
  void *v32; // edx
  CMapSolid *v33; // esi
  const char *DefaultTextureName; // eax
  int v35; // eax
  int j; // edi
  CMapClass *v37; // eax
  CUtlReference<CMapClass> *v38; // ecx
  void *v39; // edx
  CMapSolid *v40; // esi
  const char *v41; // eax
  CPrefab *ID; // eax
  float flCrossSectionalRadius; // [esp+10h] [ebp-105BCh]
  __int64 fRotationStartAngle; // [esp+14h] [ebp-105B8h]
  float fRotationArc; // [esp+1Ch] [ebp-105B0h]
  int m_iAddHeight; // [esp+20h] [ebp-105ACh]
  CTorusDlg fStartAngle; // [esp+34h] [ebp-10598h] BYREF
  char v48[48]; // [esp+10520h] [ebp-ACh] BYREF
  Vector v49; // [esp+105A0h] [ebp-2Ch] BYREF
  int v50; // [esp+105ACh] [ebp-20h]
  int v51; // [esp+105B0h] [ebp-1Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+105B4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v53; // [esp+105B8h] [ebp-14h]
  void *v54; // [esp+105BCh] [ebp-10h]
  int v55; // [esp+105C8h] [ebp-4h]

  v51 = 0;
  v50 = 1;
  v4 = __RTDynamicCast(
         inptr: pView,
         VfDelta: 0,
         SrcType: &CMapView `RTTI Type Descriptor',
         TargetType: &CMapView2D `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v5 = v4[47];
    v51 = v4[46];
    v50 = v5;
  }
  if ( this->ListType != listPrimitives )
  {
    ID = CPrefab::FindID(dwID: iNewObjIndex);
    if ( ID != nullptr )
      return (CMapSolid *)ID->CreateInBox(this: ID, a2: pBox);
    else
      return nullptr;
  }
  else
  {
    CWnd::GetWindowTextA(this: &this->m_Faces, lpszString: v48, nMaxCount: 128);
    LODWORD(v8) = atoi(nptr: v48);
    v6 = (CMapView *)dword_1072E434[5 * iNewObjIndex];
    v7 = dword_1072E430[5 * iNewObjIndex];
    HIDWORD(v8) = 20 * iNewObjIndex;
    v9 = byte_1072E438[20 * iNewObjIndex] == 0;
    pView = v6;
    if ( v9 || (int)v8 >= v7 && (int)v8 <= (int)v6 )
    {
      if ( (int)iNewObjIndex >= 5 )
      {
        HIDWORD(v8) = pBox;
        if ( iNewObjIndex == 5 )
        {
          CArchDlg::CArchDlg(
            this: (CArchDlg *)&fStartAngle.m_pParentWnd,
            boxmins: &pBox->bmins,
            boxmaxs: &pBox->bmaxs,
            pParent: nullptr);
          v55 = 9;
          BoundBox::GetBoundsSize(this: (BoundBox *)HIDWORD(v8), size: &v49);
          v27 = (int)*(&v49.x + v50);
          v28 = (int)*(&v49.x + v51);
          LODWORD(fStartAngle.m_fRotationArc) = v8;
          if ( v28 < v27 )
            v27 = v28;
          fStartAngle.m_iMaxWallWidth = v27;
          if ( CDialog::DoModal(this: (CDialog *)&fStartAngle.m_pParentWnd) != 1 )
          {
            v55 = -1;
            CArchDlg::~CArchDlg(this: (CArchDlg *)&fStartAngle.m_pParentWnd);
            return nullptr;
          }
          CArchDlg::SaveValues(this: (CArchDlg *)&fStartAngle.m_pParentWnd);
          Arch = (CMapSolid *)CreateArch(
                                a1: v7,
                                a2: v8,
                                a3: SHIDWORD(v8),
                                pBox: (BoundBox *)HIDWORD(v8),
                                fStartAngle: fStartAngle.m_fCrossSectionRadius,
                                iSides: SLODWORD(fStartAngle.m_fRotationArc),
                                fArc: *(float *)&fStartAngle.m_iAddHeight,
                                iWallWidth: SLODWORD(fStartAngle.m_fRotationAngle),
                                iAddHeight: fStartAngle.m_iRotationSides);
          for ( i = 0; i < Arch->m_Children.m_Size; ++i )
          {
            m_pObject = Arch->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&Arch->m_Children.m_Memory
                                                                                    + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&Arch->m_Children.m_Memory + 2)) >> 5)].m_pObject;
            if ( m_pObject != nullptr )
            {
              v54 = Arch->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&Arch->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&Arch->m_Children.m_Memory + 2)) >> 5)].m_pObject;
              m_pHead = m_pObject->m_References.m_pHead;
              v31 = m_pObject->m_References.m_pHead;
              if ( v31 != nullptr )
                v31->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
              v53 = nullptr;
              m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
            }
            v32 = v54;
            LOBYTE(v55) = 9;
            if ( v54 != nullptr )
            {
              if ( v53 != nullptr )
              {
                v53->m_pNext = m_pHead;
                if ( m_pHead != nullptr )
                  m_pHead->m_pPrev = v53;
              }
              else if ( *((CUtlReference<CMapClass> ***)v54 + 8) == &m_pHead )
              {
                *((_DWORD *)v54 + 8) = m_pHead;
                if ( m_pHead != nullptr )
                  m_pHead->m_pPrev = nullptr;
              }
              v53 = nullptr;
              m_pHead = nullptr;
              v54 = nullptr;
            }
            v33 = (CMapSolid *)__RTDynamicCast(
                                 inptr: v32,
                                 VfDelta: 0,
                                 SrcType: &CMapClass `RTTI Type Descriptor',
                                 TargetType: &CMapSolid `RTTI Type Descriptor',
                                 isReference: 0);
            if ( v33 != nullptr )
            {
              DefaultTextureName = GetDefaultTextureName();
              CMapSolid::SetTexture(this: v33, pszTex: DefaultTextureName, iFace: -1);
            }
          }
          v55 = -1;
          CArchDlg::~CArchDlg(this: (CArchDlg *)&fStartAngle.m_pParentWnd);
        }
        else
        {
          CTorusDlg::CTorusDlg(this: &fStartAngle, boxmins: &pBox->bmins, boxmaxs: &pBox->bmaxs, pParent: nullptr);
          v55 = 11;
          BoundBox::GetBoundsSize(this: (BoundBox *)HIDWORD(v8), size: &v49);
          v35 = (int)*(&v49.x + v50);
          if ( (int)*(&v49.x + v51) < v35 )
            v35 = (int)*(&v49.x + v51);
          fStartAngle.m_iMaxWallWidth = v35;
          if ( CDialog::DoModal(this: &fStartAngle) != 1 )
          {
            v55 = -1;
            CTorusDlg::~CTorusDlg(this: &fStartAngle);
            return nullptr;
          }
          CTorusDlg::SaveValues(this: &fStartAngle);
          m_iAddHeight = fStartAngle.m_iAddHeight;
          fRotationArc = fStartAngle.m_fRotationArc;
          fRotationStartAngle = *(_QWORD *)&fStartAngle.m_fRotationAngle;
          flCrossSectionalRadius = CTorusDlg::GetTorusCrossSectionRadius(this: &fStartAngle);
          Arch = (CMapSolid *)CreateTorus(
                                a1: v7,
                                a2: v8,
                                pBox: (BoundBox *)HIDWORD(v8),
                                fStartAngle: fStartAngle.m_fAngle,
                                iSides: fStartAngle.m_iSides,
                                fArc: fStartAngle.m_fArc,
                                iWallWidth: fStartAngle.m_iWallWidth,
                                flCrossSectionalRadius,
                                fRotationStartAngle: *(float *)&fRotationStartAngle,
                                iRotationSides: SHIDWORD(fRotationStartAngle),
                                fRotationArc,
                                iAddHeight: m_iAddHeight);
          for ( j = 0; j < Arch->m_Children.m_Size; ++j )
          {
            v37 = Arch->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&Arch->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&Arch->m_Children.m_Memory + 2)) >> 5)].m_pObject;
            if ( v37 != nullptr )
            {
              v54 = Arch->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&Arch->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&Arch->m_Children.m_Memory + 2)) >> 5)].m_pObject;
              m_pHead = v37->m_References.m_pHead;
              v38 = v37->m_References.m_pHead;
              if ( v38 != nullptr )
                v38->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
              v53 = nullptr;
              v37->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
            }
            v39 = v54;
            LOBYTE(v55) = 11;
            if ( v54 != nullptr )
            {
              if ( v53 != nullptr )
              {
                v53->m_pNext = m_pHead;
                if ( m_pHead != nullptr )
                  m_pHead->m_pPrev = v53;
              }
              else if ( *((CUtlReference<CMapClass> ***)v54 + 8) == &m_pHead )
              {
                *((_DWORD *)v54 + 8) = m_pHead;
                if ( m_pHead != nullptr )
                  m_pHead->m_pPrev = nullptr;
              }
              v53 = nullptr;
              m_pHead = nullptr;
              v54 = nullptr;
            }
            v40 = (CMapSolid *)__RTDynamicCast(
                                 inptr: v39,
                                 VfDelta: 0,
                                 SrcType: &CMapClass `RTTI Type Descriptor',
                                 TargetType: &CMapSolid `RTTI Type Descriptor',
                                 isReference: 0);
            if ( v40 != nullptr )
            {
              v41 = GetDefaultTextureName();
              CMapSolid::SetTexture(this: v40, pszTex: v41, iFace: -1);
            }
          }
          v55 = -1;
          CTorusDlg::~CTorusDlg(this: &fStartAngle);
        }
      }
      else
      {
        switch ( iNewObjIndex )
        {
          case 0u:
            v13 = (CMapView *)operator new(nSize: 0x28u);
            pView = v13;
            v55 = 3;
            if ( v13 == nullptr )
              goto LABEL_16;
            v14 = StockBlock::StockBlock(this: (StockBlock *)v13);
            v55 = -1;
            v15 = v14;
            goto LABEL_27;
          case 1u:
            v16 = (CMapView *)operator new(nSize: 0x28u);
            pView = v16;
            v55 = 4;
            if ( v16 != nullptr )
            {
              v17 = StockWedge::StockWedge(this: (StockWedge *)v16);
              v55 = -1;
              v15 = v17;
            }
            else
            {
LABEL_16:
              v55 = -1;
              v15 = nullptr;
            }
            goto LABEL_27;
          case 2u:
            v18 = (CMapView *)operator new(nSize: 0x28u);
            pView = v18;
            v55 = 5;
            if ( v18 == nullptr )
              goto LABEL_25;
            v19 = StockCylinder::StockCylinder(this: (StockCylinder *)v18);
            break;
          case 3u:
            v20 = (CMapView *)operator new(nSize: 0x28u);
            pView = v20;
            v55 = 6;
            if ( v20 == nullptr )
              goto LABEL_25;
            v19 = (StockCylinder *)StockSpike::StockSpike(this: (StockSpike *)v20);
            break;
          default:
            v21 = (CMapView *)operator new(nSize: 0x28u);
            pView = v21;
            v55 = 7;
            if ( v21 != nullptr )
              v19 = (StockCylinder *)StockSphere::StockSphere(this: (StockSphere *)v21);
            else
LABEL_25:
              v19 = nullptr;
            break;
        }
        v55 = -1;
        v15 = v19;
        StockSolid::SetFieldData(this: v19, iIndex: 3, iData: v8);
LABEL_27:
        v22 = (CMapView *)operator new(nSize: 0x240u);
        pView = v22;
        v55 = 8;
        if ( v22 != nullptr )
          Arch = CMapSolid::CMapSolid(this: (CMapSolid *)v22, Parent0: nullptr);
        else
          Arch = nullptr;
        v55 = -1;
        v15->SetFromBox(this: v15, a2: pBox);
        v24 = v15->__vftable;
        v25 = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
        v24->CreateMapSolid(this: v15, a2: Arch, a3: (TextureAlignment_t)v25);
        v26 = GetDefaultTextureName();
        CMapSolid::SetTexture(this: Arch, pszTex: v26, iFace: -1);
        StockSolid::~StockSolid(this: v15);
        operator delete(p: v15);
      }
      return Arch;
    }
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pBox = (BoundBox *)&StringManager->GetNilString(this: StringManager)[1];
    v55 = 1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pBox,
      pszFormat: "The face count for a %s must be in the range of %d to %d.",
      *(const char **)((char *)&SolidTypes[0].pszName + HIDWORD(v8)),
      v7,
      pView);
    v11 = pBox;
    AfxMessageBox(lpszText: (const char *)pBox, nType: 0, nIDHelp: 0);
    v55 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)&v11[-1].bmaxs.z) <= 0 )
      (*(void (__thiscall **)(_DWORD, float *))(*(_DWORD *)LODWORD(v11[-1].bmins.z) + 4))(
        a1: LODWORD(v11[-1].bmins.z),
        a2: &v11[-1].bmins.z);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100897D0
// Name: private: void CObjectBar::LoadPrefabItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadPrefabItems(CObjectBar *this)
{
  CObjectBar *v1; // ebx
  WPARAM v2; // eax
  LRESULT v3; // eax
  CPrefab *v4; // eax
  char *szName; // esi
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v8; // eax
  int m_Size; // eax
  int v10; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  int v12; // eax
  vgui::ToolWindow *v13; // ebx
  char *m_pszData; // esi
  int (__thiscall ***v15)(_DWORD, _DWORD, int); // eax
  char *v16; // edi
  int v17; // eax
  int v18; // ecx
  char *v19; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+Ch] [ebp-38h] BYREF
  vgui::ToolWindow *v21; // [esp+20h] [ebp-24h]
  vgui::ToolWindow *v22; // [esp+24h] [ebp-20h]
  CObjectBar *v23; // [esp+28h] [ebp-1Ch]
  CPrefabLibrary *pLibrary; // [esp+2Ch] [ebp-18h]
  __POSITION *p; // [esp+30h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+34h] [ebp-10h] BYREF
  int v27; // [esp+40h] [ebp-4h]

  v1 = this;
  v23 = this;
  this->ListType = listPrefabs;
  memset(&suggestions, 0, sizeof(suggestions));
  v27 = 1;
  v2 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v3 = SendMessageA(hWnd: v1->m_CategoryList.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
  pLibrary = CPrefabLibrary::FindID(dwID: v3);
  p = (__POSITION *)1;
  v4 = CPrefabLibrary::EnumPrefabs(this: pLibrary, &p);
  if ( v4 != nullptr )
  {
    while ( 1 )
    {
      szName = v4->szName;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      v26.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v27) = 2;
      if ( szName != nullptr )
      {
        if ( ((unsigned int)szName & 0xFFFF0000) == 0 )
        {
          StringResourceHandle = AfxFindStringResourceHandle(__formal: (unsigned __int16)szName);
          if ( StringResourceHandle != nullptr )
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: &v26,
              hInstance: StringResourceHandle,
              nID: (unsigned __int16)szName);
          goto LABEL_10;
        }
        v8 = strlen(szName);
      }
      else
      {
        v8 = 0;
      }
      ATL::CSimpleStringT<char,0>::SetString(this: &v26, pszSrc: szName, nLength: v8);
LABEL_10:
      LOBYTE(v27) = 3;
      m_Size = suggestions.m_Size;
      v10 = suggestions.m_Size;
      if ( suggestions.m_Size + 1 > suggestions.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&suggestions,
          num: suggestions.m_Size - suggestions.m_Memory.m_nAllocationCount + 1);
        m_Size = suggestions.m_Size;
      }
      suggestions.m_Size = m_Size + 1;
      m_pMemory = suggestions.m_Memory.m_pMemory;
      v12 = m_Size - v10;
      suggestions.m_pElements = suggestions.m_Memory.m_pMemory;
      if ( v12 > 0 )
      {
        _V_memmove(
          dest: &suggestions.m_Memory.m_pMemory[v10 + 1],
          src: &suggestions.m_Memory.m_pMemory[v10],
          count: 4 * v12);
        m_pMemory = suggestions.m_Memory.m_pMemory;
      }
      v13 = (vgui::ToolWindow *)&m_pMemory[v10];
      v22 = v13;
      v21 = v13;
      LOBYTE(v27) = 4;
      if ( v13 != nullptr )
      {
        m_pszData = v26.m_pszData;
        v15 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v26.m_pszData - 4)
                                                                                       + 16))(a1: *((_DWORD *)v26.m_pszData
                                                                                                  - 4));
        if ( *((int *)m_pszData - 1) >= 0 && v15 == *((int (__thiscall ****)(_DWORD, _DWORD, int))m_pszData - 4) )
        {
          v16 = m_pszData - 16;
          _InterlockedExchangeAdd((volatile signed __int32 *)m_pszData - 1, 1u);
        }
        else
        {
          v17 = (**v15)(a1: v15, a2: *((_DWORD *)m_pszData - 3), a3: 1);
          v16 = (char *)v17;
          if ( v17 == 0 )
            ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v18);
          *(_DWORD *)(v17 + 4) = *((_DWORD *)m_pszData - 3);
          memcpy_s(
            dst: (void *)(v17 + 16),
            sizeInBytes: *((_DWORD *)m_pszData - 3) + 1,
            src: m_pszData,
            count: *((_DWORD *)m_pszData - 3) + 1);
        }
        v13->__vftable = (vgui::ToolWindow_vtbl *)(v16 + 16);
        LOBYTE(v27) = 4;
      }
      LOBYTE(v27) = 1;
      v19 = v26.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)v26.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v19 + 4))(a1: v19);
      v4 = CPrefabLibrary::EnumPrefabs(this: pLibrary, &p);
      if ( v4 == nullptr )
      {
        v1 = v23;
        break;
      }
    }
  }
  CFilteredComboBox::SetSuggestions(this: &v1->m_CreateList, &suggestions, flags: 3);
  v27 = -1;
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::~CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>(this: &suggestions);
}

//------------------------------------------------------------------------------
// Address: 0x10089A10
// Name: public: CObjectBar::CObjectBar(void)
// Source: json
//------------------------------------------------------------------------------
CObjectBar *__thiscall CObjectBar::CObjectBar(CObjectBar *this)
{
  ControlInfo_t *m_pMemory; // ecx
  CObjectBar::tagprevsel *m_PrevSel; // ebx
  int i; // eax

  CDialogBar::CDialogBar(this);
  this->CHammerBar::CDialogBar::CControlBar::CWnd::CCmdTarget::CObject::__vftable = (CObjectBar_vtbl *)&CHammerBar::`vftable';
  this->m_sizeDocked.cx = 0;
  this->m_sizeDocked.cy = 0;
  this->m_sizeFloating.cx = 0;
  this->m_sizeFloating.cy = 0;
  this->m_ControlList.m_Memory.m_pMemory = nullptr;
  this->m_ControlList.m_Memory.m_nAllocationCount = 0;
  this->m_ControlList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ControlList.m_Memory.m_pMemory;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_pElements = m_pMemory;
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CFilteredComboBox::ICallbacks::`vftable';
  this->CHammerBar::CDialogBar::CControlBar::CWnd::CCmdTarget::CObject::__vftable = (CObjectBar_vtbl *)&CObjectBar::`vftable'{for `CHammerBar'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CObjectBar::`vftable'{for `CFilteredComboBox::ICallbacks'};
  CFilteredComboBox::CFilteredComboBox(this: &this->m_CreateList, pCallbacks: &this->CFilteredComboBox::ICallbacks);
  CWnd::CWnd(this: &this->m_CategoryList);
  this->m_CategoryList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_Faces);
  this->m_Faces.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_FacesSpin);
  this->m_FacesSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  m_PrevSel = this->m_PrevSel;
  `eh vector constructor iterator'(
    ptr: this->m_PrevSel,
    size: 0x14u,
    count: 12,
    pCtor: (void (__thiscall *)(void *))CObjectBar::tagprevsel::tagprevsel,
    pDtor: (void (__thiscall *)(void *))CObjectBar::tagprevsel::~tagprevsel);
  for ( i = 12; i != 0; --i )
  {
    m_PrevSel->dwGameID = 0;
    ++m_PrevSel;
  }
  this->m_dwPrevGameID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10089B80
// Name: private: void CObjectBar::LoadBlockItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadBlockItems(CObjectBar *this)
{
  unsigned int i; // esi
  char *v3; // eax
  int j; // esi
  volatile signed __int32 *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > src; // [esp+20h] [ebp-10h] BYREF
  int v9; // [esp+2Ch] [ebp-4h]

  if ( SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == -1 )
    CObjectBar::LoadBlockCategories(this);
  if ( SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) != 0 )
  {
    CObjectBar::LoadPrefabItems(this);
  }
  else
  {
    this->ListType = listPrimitives;
    memset(&suggestions, 0, sizeof(suggestions));
    v9 = 1;
    for ( i = 0; i < 7; ++i )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &src,
        pszSrc: SolidTypes[i].pszName);
      LOBYTE(v9) = 2;
      CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
        this: &suggestions,
        elem: suggestions.m_Size,
        &src);
      LOBYTE(v9) = 1;
      v3 = src.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)src.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
    }
    CFilteredComboBox::SetSuggestions(this: &this->m_CreateList, &suggestions, flags: 3);
    v9 = 4;
    for ( j = suggestions.m_Size - 1; j >= 0; --j )
    {
      src.m_pszData = (char *)&suggestions.m_Memory.m_pMemory[j];
      LOBYTE(v9) = 4;
      v5 = (volatile signed __int32 *)(*(_DWORD *)src.m_pszData - 16);
      if ( _InterlockedDecrement(v5 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
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
    v9 = -1;
    if ( suggestions.m_Memory.m_nGrowSize >= 0 )
    {
      if ( suggestions.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: suggestions.m_Memory.m_pMemory);
        suggestions.m_Memory.m_pMemory = nullptr;
      }
      suggestions.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089D10
// Name: private: void CObjectBar::LoadEntityItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::LoadEntityItems(CObjectBar *this)
{
  GameData *v2; // ecx
  int m_Size; // edi
  int i; // esi
  GDclass *v5; // eax
  char *v6; // eax
  int j; // esi
  volatile signed __int32 *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > src; // [esp+20h] [ebp-10h] BYREF
  int v12; // [esp+2Ch] [ebp-4h]

  if ( SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == -1 )
    CObjectBar::LoadEntityCategories(this);
  if ( SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) != 0 )
  {
    CObjectBar::LoadPrefabItems(this);
  }
  else
  {
    this->ListType = listEntities;
    memset(&suggestions, 0, sizeof(suggestions));
    v12 = 1;
    v2 = pGD;
    if ( pGD != nullptr )
    {
      m_Size = pGD->m_Classes.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        if ( i < v2->m_Classes.m_Size )
          v5 = v2->m_Classes.m_Memory.m_pMemory[i];
        else
          v5 = nullptr;
        if ( !v5->m_bBase && !v5->m_bSolid )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
            this: &src,
            pszSrc: v5->m_szName);
          LOBYTE(v12) = 2;
          CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
            this: &suggestions,
            elem: suggestions.m_Size,
            &src);
          LOBYTE(v12) = 1;
          v6 = src.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)src.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
          v2 = pGD;
        }
      }
    }
    CFilteredComboBox::SetSuggestions(this: &this->m_CreateList, &suggestions, flags: 3);
    v12 = 4;
    for ( j = suggestions.m_Size - 1; j >= 0; --j )
    {
      src.m_pszData = (char *)&suggestions.m_Memory.m_pMemory[j];
      LOBYTE(v12) = 4;
      v8 = (volatile signed __int32 *)(*(_DWORD *)src.m_pszData - 16);
      if ( _InterlockedDecrement(v8 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v8 + 4))(a1: v8);
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
    v12 = -1;
    if ( suggestions.m_Memory.m_nGrowSize >= 0 )
    {
      if ( suggestions.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: suggestions.m_Memory.m_pMemory);
        suggestions.m_Memory.m_pMemory = nullptr;
      }
      suggestions.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089ED0
// Name: public: void CObjectBar::UpdateListForTool(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::UpdateListForTool(CObjectBar *this, int iTool)
{
  unsigned int dwID; // eax
  int v4; // ebx
  unsigned int v5; // edx
  int v6; // ecx
  CObjectBar::tagprevsel *v7; // eax
  unsigned int dwGameID; // edi
  unsigned int v9; // edi
  unsigned int v10; // edi
  unsigned int v11; // edi
  unsigned int v12; // edi
  ATL::CSimpleStringT<char,0> *v13; // edi
  int v14; // eax
  int v15; // edi
  CObjectBar::tagprevsel *i; // eax
  int m_iLastTool; // eax
  WPARAM v18; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v19; // ebx
  ATL::CStringData *CurrentItem; // eax
  char *v21; // eax
  CObjectBar::tagprevsel::tagentity *p_entity; // ecx
  WPARAM v23; // eax
  ATL::CStringData *v24; // eax
  char *m_pszData; // edx
  const char **v26; // edi
  char *v27; // ecx
  CObjectBar::tagprevsel::tagentity *v28; // edi
  BOOL v29; // eax
  BOOL v30; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+Ch] [ebp-10h] BYREF
  int v32; // [esp+18h] [ebp-4h]

  dwID = g_pGameConfig->dwID;
  v4 = 0;
  if ( this->m_dwPrevGameID != dwID )
  {
    this->m_dwPrevGameID = dwID;
    v5 = g_pGameConfig->dwID;
    v6 = 2;
    v7 = &this->m_PrevSel[1];
    do
    {
      dwGameID = v7[-1].dwGameID;
      if ( dwGameID == 0 )
        v4 = v6 - 2;
      if ( dwGameID == v5 )
        break;
      if ( v7->dwGameID == 0 )
        v4 = v6 - 1;
      if ( v7->dwGameID == v5 )
        break;
      v9 = v7[1].dwGameID;
      if ( v9 == 0 )
        v4 = v6;
      if ( v9 == v5 )
        break;
      v10 = v7[2].dwGameID;
      if ( v10 == 0 )
        v4 = v6 + 1;
      if ( v10 == v5 )
        break;
      v11 = v7[3].dwGameID;
      if ( v11 == 0 )
        v4 = v6 + 2;
      if ( v11 == v5 )
        break;
      v12 = v7[4].dwGameID;
      if ( v12 == 0 )
        v4 = v6 + 3;
      if ( v12 == v5 )
        break;
      v6 += 6;
      v7 += 6;
    }
    while ( v6 - 2 < 12 );
    v13 = (ATL::CSimpleStringT<char,0> *)((char *)this + 20 * v4);
    v13[196].m_pszData = (char *)v5;
    ATL::CSimpleStringT<char,0>::SetString(this: v13 + 198, pszSrc: "Primitives", nLength: 10);
    ATL::CSimpleStringT<char,0>::SetString(this: v13 + 197, pszSrc: "block", nLength: 5);
    ATL::CSimpleStringT<char,0>::SetString(
      this: &this->m_PrevSel[v4].entity.strCategory,
      pszSrc: "Entities",
      nLength: 8);
    if ( g_pGameConfig == (CGameConfig *)-288 )
      v14 = 0;
    else
      v14 = &g_pGameConfig->szDefaultPoint[strlen(g_pGameConfig->szDefaultPoint) + 1]
          - &g_pGameConfig->szDefaultPoint[1];
    ATL::CSimpleStringT<char,0>::SetString(this: v13 + 199, pszSrc: g_pGameConfig->szDefaultPoint, nLength: v14);
  }
  v15 = 0;
  for ( i = this->m_PrevSel; i->dwGameID != this->m_dwPrevGameID; ++i )
  {
    if ( ++v15 >= 12 )
      return;
  }
  if ( v15 == -1 )
    return;
  m_iLastTool = this->m_iLastTool;
  if ( m_iLastTool == 1 )
  {
    v18 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    v19 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)((char *)this + 20 * v15);
    if ( v18 != -1 )
    {
      CComboBox::GetLBText(this: &this->m_CategoryList, nIndex: v18, rString: v19 + 198);
      CurrentItem = (ATL::CStringData *)CFilteredComboBox::GetCurrentItem(this: &this->m_CreateList, &result);
      v32 = 0;
      ATL::CSimpleStringT<char,0>::operator=(this: v19 + 197, strSrc: CurrentItem);
      v32 = -1;
      v21 = result.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v21 + 4))(a1: v21);
      goto LABEL_41;
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(this: v19 + 198, pszSrc: &var);
    p_entity = (CObjectBar::tagprevsel::tagentity *)&v19[197];
    goto LABEL_40;
  }
  if ( m_iLastTool == 2 )
  {
    v23 = SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v23 == -1 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
        this: &this->m_PrevSel[v15].entity.strCategory,
        pszSrc: &var);
      p_entity = &this->m_PrevSel[v15].entity;
LABEL_40:
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(this: &p_entity->strItem, pszSrc: &var);
      goto LABEL_41;
    }
    CComboBox::GetLBText(this: &this->m_CategoryList, nIndex: v23, rString: &this->m_PrevSel[v15].entity.strCategory);
    v24 = (ATL::CStringData *)CFilteredComboBox::GetCurrentItem(this: &this->m_CreateList, &result);
    v32 = 2;
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_PrevSel[v15].entity.strItem, strSrc: v24);
    v32 = -1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &result);
  }
LABEL_41:
  this->m_iLastTool = iTool;
  if ( iTool == 1 )
  {
    CObjectBar::LoadBlockCategories(this);
    m_pszData = this->m_PrevSel[v15].block.strCategory.m_pszData;
    v26 = (const char **)((char *)this + 20 * v15);
    SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)m_pszData);
    CObjectBar::LoadBlockItems(this);
    CFilteredComboBox::SelectItem(this: &this->m_CreateList, pStr: v26[197]);
    this->OnTextChanged(this: &this->CFilteredComboBox::ICallbacks, a2: v26[197]);
    this->iBlockSel = FindSolidType(pName: v26[197]);
  }
  else
  {
    if ( iTool != 2 )
    {
      SendMessageA(hWnd: this->m_CategoryList.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
      CFilteredComboBox::Clear(this: &this->m_CreateList);
      CObjectBar::DoHideControls(this);
      return;
    }
    CObjectBar::LoadEntityCategories(this);
    SendMessageA(
      hWnd: this->m_CategoryList.m_hWnd,
      Msg: 0x14Du,
      wParam: 0xFFFFFFFF,
      lParam: (LPARAM)this->m_PrevSel[v15].entity.strCategory.m_pszData);
    CObjectBar::LoadEntityItems(this);
    v27 = this->m_PrevSel[v15].entity.strItem.m_pszData;
    v28 = &this->m_PrevSel[v15].entity;
    CFilteredComboBox::SelectItem(this: &this->m_CreateList, pStr: v27);
    this->OnTextChanged(this: &this->CFilteredComboBox::ICallbacks, a2: v28->strItem.m_pszData);
    this->iEntitySel = FindGameDataClass(pName: v28->strItem.m_pszData);
  }
  CObjectBar::DoHideControls(this);
  v29 = CMapDoc::m_pMapDoc != nullptr;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v29 = false;
    if ( this->ListType == listPrimitives )
      v29 = byte_1072E438[20 * this->iBlockSel] != 0;
  }
  CWnd::EnableWindow(this: &this->m_Faces, bEnable: v29);
  v30 = CMapDoc::m_pMapDoc != nullptr;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v30 = false;
    if ( this->ListType == listPrimitives )
      v30 = byte_1072E438[20 * this->iBlockSel] != 0;
  }
  CWnd::EnableWindow(this: &this->m_FacesSpin, bEnable: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1008A330
// Name: protected: void CObjectBar::OnChangeCategory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::OnChangeCategory(CObjectBar *this)
{
  CObjectBar::<unnamed_type_ListType> ListType; // eax
  __int32 v3; // eax
  bool v4; // zf
  int m_iLastTool; // eax

  ListType = this->ListType;
  if ( ListType == listPrimitives )
    goto LABEL_8;
  v3 = ListType - 1;
  if ( v3 != 0 )
  {
    v4 = v3 == 1;
    goto LABEL_6;
  }
  m_iLastTool = this->m_iLastTool;
  if ( m_iLastTool == 1 )
  {
LABEL_8:
    this->iBlockSel = -1;
    CObjectBar::LoadBlockItems(this);
    goto LABEL_9;
  }
  v4 = m_iLastTool == 2;
LABEL_6:
  if ( v4 )
  {
    this->iEntitySel = -1;
    CObjectBar::LoadEntityItems(this);
    CObjectBar::DoHideControls(this);
    return;
  }
LABEL_9:
  CObjectBar::DoHideControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008A390
// Name: protected: virtual struct AFX_MSGMAP const __near * CObjectBar::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CObjectBar::GetMessageMap(CObjectBar *this)
{
  return (const AFX_MSGMAP *)&off_105E43B8;
}
