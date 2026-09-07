// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/toolswitchmenubutton.cpp
// Functions: 17
// ============================================================

#include "tools\toolutils\toolswitchmenubutton.h"

//------------------------------------------------------------------------------
// Address: 0x102C0F50
// Name: public: static char const __near * CLoadToolDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLoadToolDialog::GetPanelClassName()
{
  return "CLoadToolDialog";
}

//------------------------------------------------------------------------------
// Address: 0x102C0F60
// Name: public: static char const __near * CToolSwitchMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolSwitchMenuButton::GetPanelClassName()
{
  return "CToolSwitchMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C0F70
// Name: public: virtual void CToolSwitchMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToolSwitchMenuButton::OnShowMenu(CToolSwitchMenuButton *this@<ecx>, int a2@<ebx>, vgui::Menu *menu)
{
  int v4; // edi
  int v5; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  int v8; // ebx
  const IToolSystem *v9; // eax
  char v10; // al
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  char toolcmd[32]; // [esp+8h] [ebp-24h] BYREF
  int c; // [esp+28h] [ebp-4h]
  vgui::Menu *menua; // [esp+34h] [ebp+8h]

  CToolMenuButton::OnShowMenu(this, menu);
  CToolMenuButton::Reset(this);
  v4 = 0;
  c = enginetools->GetToolCount(this: enginetools);
  if ( c > 0 )
  {
    do
    {
      v5 = ((int (__thiscall *)(IEngineTool *, int, int))enginetools->GetToolName)(a1: enginetools, a2: v4, a3: a2);
      V_snprintf(pDest: toolcmd, maxLen: 0x20u, pFormat: "OnTool%i", v4);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Command", firstKey: "command", firstValue: toolcmd);
      else
        v7 = nullptr;
      a2 = 0;
      v8 = ((int (__thiscall *)(CToolSwitchMenuButton *, int, int, KeyValues *, vgui::Panel *, _DWORD))this->AddCheckableMenuItem)(
             a1: this,
             a2: v5,
             a3: v5,
             a4: v7,
             a5: this->m_pActionTarget,
             a6: 0);
      this->CToolMenuButton::m_pMenu->SetItemEnabled(this: this->CToolMenuButton::m_pMenu, a2: v8, a3: true);
      menua = (vgui::Menu *)enginetools->__vftable;
      v9 = enginetools->GetToolSystem(this: enginetools, a2: v4);
      v10 = ((int (__thiscall *)(IEngineTool *, const IToolSystem *))menua->m_OnNavigateFrom_register)(
              a1: enginetools,
              a2: v9);
      vgui::Menu::SetMenuItemChecked(this: this->CToolMenuButton::m_pMenu, itemID: v8, state: v10);
      ++v4;
    }
    while ( v4 < c );
  }
  this->CToolMenuButton::m_pMenu->AddSeparator(this: this->CToolMenuButton::m_pMenu);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "OnShowLoadToolDialog");
  else
    v12 = nullptr;
  this->CToolMenuButton::m_pMenu->AddMenuItem(
    this: this->CToolMenuButton::m_pMenu,
    a2: "#ToolShowLoadToolDialog",
    a3: v12,
    a4: this,
    a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102C10C0
// Name: protected: virtual void CLoadToolDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLoadToolDialog::OnCommand(CLoadToolDialog *this@<ecx>, int a2@<ebx>, KeyValues *pCommand)
{
  KeyValues *v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // ebx
  char *String; // eax
  CFmtStrN<256> v9; // [esp+8h] [ebp-114h] BYREF
  CFmtStrN<256> *v10; // [esp+114h] [ebp-8h]
  int nCount; // [esp+118h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+124h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Ok") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v5 = 0;
    if ( v4 != nullptr )
      pActionKeys = KeyValues::KeyValues(this: v4, setName: "OnLoadTools");
    else
      pActionKeys = nullptr;
    nCount = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pModuleList->GetSelectedItemsCount)(
               a1: this->m_pModuleList,
               a2);
    KeyValues::SetInt(this: pActionKeys, keyName: "count", value: nCount);
    if ( nCount > 0 )
    {
      do
      {
        v6 = this->m_pModuleList->GetSelectedItem(this: this->m_pModuleList, a2: v5);
        v7 = this->m_pModuleList->GetItem(this: this->m_pModuleList, a2: v6);
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "%i", v5);
        String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: &var);
        KeyValues::SetString(this: pActionKeys, keyName: v10->m_szBuf, value: String);
        ++v5;
      }
      while ( v5 < nCount );
    }
    this->CloseModal(this);
    this->PostActionSignal(this, a2: pActionKeys);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C11F0
// Name: protected: virtual void CToolSwitchMenuButton::OnLoadTools(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolSwitchMenuButton::OnLoadTools(CToolSwitchMenuButton *this, KeyValues *params)
{
  int Int; // ebx
  int i; // esi
  CFmtStrN<256> *v4; // eax
  char *String; // eax
  CFmtStrN<256> v6; // [esp+Ch] [ebp-10Ch] BYREF

  Int = KeyValues::GetInt(this: params, keyName: "count", defaultValue: 0);
  for ( i = 0; i < Int; ++i )
  {
    v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v6, pszFormat: "%i", i);
    String = KeyValues::GetString(this: params, keyName: v4->m_szBuf, defaultValue: &var);
    if ( String != nullptr && *String != 0 )
      enginetools->LoadToolModule(this: enginetools, a2: String, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1270
// Name: public: static void CToolSwitchMenuButton::PanelMessageFunc_OnShowLoadToolDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolSwitchMenuButton::PanelMessageFunc_OnShowLoadToolDialog::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CToolSwitchMenuButton::PanelMessageFunc_OnShowLoadToolDialog::InitVar'::`2'::bAdded )
  {
    `CToolSwitchMenuButton::PanelMessageFunc_OnShowLoadToolDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolSwitchMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowLoadToolDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1300
// Name: public: static void CToolSwitchMenuButton::PanelMessageFunc_OnLoadTools::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolSwitchMenuButton::PanelMessageFunc_OnLoadTools::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CToolSwitchMenuButton::PanelMessageFunc_OnLoadTools::InitVar'::`2'::bAdded )
  {
    `CToolSwitchMenuButton::PanelMessageFunc_OnLoadTools::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CToolSwitchMenuButton::`vcall'{1228,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolSwitchMenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnLoadTools";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1390
// Name: public: CLoadToolDialog::CLoadToolDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CLoadToolDialog *__thiscall CLoadToolDialog::CLoadToolDialog(CLoadToolDialog *this, vgui::Panel *panel)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ListPanel *v6; // eax
  CUtlString *m_Size; // edi
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  const char *(__thiscall *FindFirstEx)(IFileSystem *, const char *, const char *, int *); // edx
  const char *i; // ebx
  CUtlString *v15; // ebx
  CUtlString *m_pMemory; // ecx
  CUtlString *v17; // ebx
  CUtlString *v18; // ebx
  KeyValues *v19; // eax
  KeyValues *v20; // edi
  char *v21; // eax
  char searchpath[260]; // [esp+Ch] [ebp-230h] BYREF
  char sz[260]; // [esp+110h] [ebp-12Ch] BYREF
  CUtlString v25; // [esp+214h] [ebp-28h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > toolmodules; // [esp+224h] [ebp-18h] BYREF
  CUtlString *string; // [esp+238h] [ebp-4h]

  vgui::Frame::Frame(this, parent: panel, panelName: "LoadToolDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CLoadToolDialog_vtbl *)&CLoadToolDialog::`vftable';
  if ( `CLoadToolDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CLoadToolDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CLoadToolDialog");
    v3->pfnClassName = CLoadToolDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CLoadToolDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLoadToolDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CLoadToolDialog");
    v4->pfnClassName = CLoadToolDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CLoadToolDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLoadToolDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadToolDialog");
    v5->pfnClassName = CLoadToolDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  v6 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  m_Size = nullptr;
  if ( v6 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v6, parent: this, panelName: "ModuleList");
  else
    v8 = nullptr;
  this->m_pModuleList = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_pModuleList->AddColumnHeader(this: this->m_pModuleList, a2: 0, a3: "text", a4: "Text", a5: 250, a6: 2);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pModuleList, bState: true);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "#VGui_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pLoadButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Cancel",
            text: "#vgui_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetSize(this, wide: 300, tall: 400);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  V_strncpy(pDest: searchpath, pSrc: "tools/*.dll", maxLen: 260);
  FindFirstEx = g_pFullFileSystem->FindFirstEx;
  memset(&toolmodules, 0, sizeof(toolmodules));
  for ( i = FindFirstEx(this: g_pFullFileSystem, a2: searchpath, a3: "EXECUTABLE_PATH", a4: (int *)&panel);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: panel) )
  {
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)panel) )
    {
      memset(sz, 0, sizeof(sz));
      V_FileBase(in: i, out: sz, maxlen: 260);
      string = CUtlString::CUtlString(this: &v25, pString: sz);
      v15 = m_Size;
      if ( (int)&m_Size->m_Storage.m_Memory.m_pMemory + 1 > toolmodules.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&toolmodules,
          num: (int)&m_Size->m_Storage.m_Memory.m_pMemory - toolmodules.m_Memory.m_nAllocationCount + 1);
        m_Size = (CUtlString *)toolmodules.m_Size;
      }
      m_pMemory = toolmodules.m_Memory.m_pMemory;
      m_Size = (CUtlString *)((char *)m_Size + 1);
      toolmodules.m_Size = (int)m_Size;
      toolmodules.m_pElements = toolmodules.m_Memory.m_pMemory;
      if ( (char *)m_Size - (char *)v15 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&toolmodules.m_Memory.m_pMemory[(int)v15 + 1],
          src: (unsigned __int8 *)&toolmodules.m_Memory.m_pMemory[(_DWORD)v15],
          count: 16 * ((char *)m_Size - (char *)v15 - 1));
        m_pMemory = toolmodules.m_Memory.m_pMemory;
      }
      v17 = &m_pMemory[(_DWORD)v15];
      if ( v17 != nullptr )
        CUtlString::CUtlString(this: v17, string);
      v25.m_Storage.m_nActualLength = 0;
      if ( v25.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v25.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25.m_Storage.m_Memory.m_pMemory);
          v25.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v25.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)panel);
  if ( (int)m_Size > 0 )
  {
    v18 = toolmodules.m_Memory.m_pMemory;
    for ( string = m_Size; string != nullptr; string = (CUtlString *)((char *)string - 1) )
    {
      v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v19 != nullptr )
        v20 = KeyValues::KeyValues(this: v19, setName: "item");
      else
        v20 = nullptr;
      v21 = (char *)CUtlString::operator char const *(this: v18);
      KeyValues::SetString(this: v20, keyName: "text", value: v21);
      this->m_pModuleList->AddItem(this: this->m_pModuleList, a2: v20, a3: 0, a4: false, a5: false);
      ++v18;
    }
  }
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/loadtooldialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &toolmodules);
  if ( toolmodules.m_Memory.m_nGrowSize >= 0 && toolmodules.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: toolmodules.m_Memory.m_pMemory);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C1750
// Name: public: virtual struct vgui::PanelMessageMap __near * CLoadToolDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLoadToolDialog::GetMessageMap(CLoadToolDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLoadToolDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadToolDialog::GetMessageMap'::`2'::s_pMap;
  `CLoadToolDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLoadToolDialog");
  `CLoadToolDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C1780
// Name: public: virtual struct PanelAnimationMap __near * CLoadToolDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLoadToolDialog::GetAnimMap(CLoadToolDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CLoadToolDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102C1790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLoadToolDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLoadToolDialog::GetKBMap(CLoadToolDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLoadToolDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadToolDialog::GetKBMap'::`2'::s_pMap;
  `CLoadToolDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadToolDialog");
  `CLoadToolDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C17C0
// Name: protected: virtual void CToolSwitchMenuButton::OnShowLoadToolDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolSwitchMenuButton::OnShowLoadToolDialog(CToolSwitchMenuButton *this)
{
  CLoadToolDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax

  v2 = (CLoadToolDialog *)operator new(nSize: 0x220u);
  if ( v2 != nullptr )
    v3 = (CDragDropHelperPanel *)CLoadToolDialog::CLoadToolDialog(this: v2, panel: this);
  else
    v3 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hLoadToolDialog,
    pPanel: v3);
  v4 = vgui::PHandle::Get(this: &this->m_hLoadToolDialog);
  v4->__vftable[1].dtr_Panel(this: v4);
  v5 = vgui::PHandle::Get(this: &this->m_hLoadToolDialog);
  v5->AddActionSignalTarget_2(this: v5, a2: this);
  v6 = vgui::PHandle::Get(this: &this->m_hLoadToolDialog);
  v6->__vftable[1].IsEnabled(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C1840
// Name: public: CToolSwitchMenuButton::CToolSwitchMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CToolSwitchMenuButton *__thiscall CToolSwitchMenuButton::CToolSwitchMenuButton(
        CToolSwitchMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionTarget)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CToolMenuButton::CToolMenuButton(this, parent, panelName, text, actionTarget: pActionTarget);
  this->__vftable = (CToolSwitchMenuButton_vtbl *)&CToolSwitchMenuButton::`vftable';
  if ( `CToolSwitchMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CToolSwitchMenuButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CToolSwitchMenuButton");
    v6->pfnClassName = CToolSwitchMenuButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
  }
  if ( `CToolSwitchMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolSwitchMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CToolSwitchMenuButton");
    v7->pfnClassName = CToolSwitchMenuButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
  }
  if ( `CToolSwitchMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolSwitchMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolSwitchMenuButton");
    v8->pfnClassName = CToolSwitchMenuButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
  }
  CToolSwitchMenuButton::PanelMessageFunc_OnShowLoadToolDialog::InitVar(a1: (int)&savedregs);
  CToolSwitchMenuButton::PanelMessageFunc_OnLoadTools::InitVar(a1: (int)&savedregs);
  this->m_hLoadToolDialog.m_iPanelID = -1;
  vgui::MenuButton::SetMenu(this, menu: this->CToolMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C1930
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolSwitchMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolSwitchMenuButton::GetMessageMap(CToolSwitchMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolSwitchMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolSwitchMenuButton::GetMessageMap'::`2'::s_pMap;
  `CToolSwitchMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolSwitchMenuButton");
  `CToolSwitchMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C1960
// Name: public: virtual struct PanelAnimationMap __near * CToolSwitchMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolSwitchMenuButton::GetAnimMap(CToolSwitchMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolSwitchMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C1970
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolSwitchMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolSwitchMenuButton::GetKBMap(CToolSwitchMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolSwitchMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolSwitchMenuButton::GetKBMap'::`2'::s_pMap;
  `CToolSwitchMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolSwitchMenuButton");
  `CToolSwitchMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C19A0
// Name: class CToolMenuButton __near * CreateToolSwitchMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CToolSwitchMenuButton *__cdecl CreateToolSwitchMenuButton(
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionTarget)
{
  CToolSwitchMenuButton *v4; // eax

  v4 = (CToolSwitchMenuButton *)operator new(nSize: 0x248u);
  if ( v4 != nullptr )
    return CToolSwitchMenuButton::CToolSwitchMenuButton(this: v4, parent, panelName, text, pActionTarget);
  else
    return nullptr;
}
