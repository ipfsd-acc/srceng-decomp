// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/varlistpropertypage.cpp
// Functions: 23
// ============================================================

#include "tracker\adminserver\varlistpropertypage.h"

//------------------------------------------------------------------------------
// Address: 0x10004690
// Name: public: static char const __near * CVarListPropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVarListPropertyPage::GetPanelClassName()
{
  return "CVarListPropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: public: virtual CVarListPropertyPage::~CVarListPropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::~CVarListPropertyPage(CVarListPropertyPage *this)
{
  CRemoteServer *v2; // eax
  IServerDataResponse *v3; // [esp-4h] [ebp-8h]

  v3 = &this->IServerDataResponse;
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CVarListPropertyPage_vtbl *)&CVarListPropertyPage::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CVarListPropertyPage::`vftable'{for `IServerDataResponse'};
  v2 = RemoteServer();
  CRemoteServer::RemoveServerDataResponseTarget(this: v2, invalidRequester: v3);
  vgui::PropertyPage::~PropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100046D0
// Name: public: bool CVarListPropertyPage::LoadVarList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVarListPropertyPage::LoadVarList(CVarListPropertyPage *this, const char *varfile)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  KeyValues *i; // esi
  bool bSuccess; // [esp+Bh] [ebp-1h]

  bSuccess = false;
  this->m_pRulesList->DeleteAllItems(this: this->m_pRulesList);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "VarList");
  else
    v4 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: varfile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v4); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      this->m_pRulesList->AddItem(this: this->m_pRulesList, a2: i, a3: 0, a4: false, a5: false);
    bSuccess = true;
  }
  KeyValues::deleteThis(this: v4);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x10004780
// Name: protected: virtual void CVarListPropertyPage::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::PerformLayout(CVarListPropertyPage *this)
{
  vgui::EditablePanel::PerformLayout(this);
  this->OnItemSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x100047A0
// Name: private: virtual void CVarListPropertyPage::EditVariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::EditVariable(CVarListPropertyPage *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  v2 = this->m_pRulesList->GetSelectedItem(this: this->m_pRulesList, a2: 0);
  v3 = this->m_pRulesList->GetItem(this: this->m_pRulesList, a2: v2);
  if ( v3 != nullptr )
    this->OnEditVariable(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100047E0
// Name: protected: virtual void CVarListPropertyPage::OnEditVariable(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::OnEditVariable(CVarListPropertyPage *this, KeyValues *rule)
{
  CVarEditDialog *v3; // eax
  CVarEditDialog *v4; // eax

  v3 = (CVarEditDialog *)operator new(nSize: 0x224u);
  if ( v3 != nullptr )
  {
    v4 = CVarEditDialog::CVarEditDialog(this: v3, parent: this, name: "VarEditDialog");
    CVarEditDialog::Activate(this: v4, actionSignalTarget: this, rules: rule);
  }
  else
  {
    CVarEditDialog::Activate(this: nullptr, actionSignalTarget: this, rules: rule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004830
// Name: public: virtual void CVarListPropertyPage::RefreshVarList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::RefreshVarList(CVarListPropertyPage *this)
{
  int i; // edi
  KeyValues *v3; // eax
  CRemoteServer *v4; // eax
  CRemoteServer *v5; // eax
  const char *Name; // [esp-8h] [ebp-10h]

  for ( i = 0; i < this->m_pRulesList->GetItemCount(this: this->m_pRulesList); ++i )
  {
    v3 = this->m_pRulesList->GetItem(this: this->m_pRulesList, a2: i);
    if ( v3 != nullptr )
    {
      Name = KeyValues::GetName(this: v3);
      v4 = RemoteServer();
      CRemoteServer::RequestValue(this: v4, requester: &this->IServerDataResponse, variable: Name);
    }
  }
  v5 = RemoteServer();
  CRemoteServer::ProcessServerResponse(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100048B0
// Name: public: void CVarListPropertyPage::SetVarString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::SetVarString(CVarListPropertyPage *this, const char *varName, const char *value)
{
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *String; // eax
  KeyValues *Key; // eax
  const char *v9; // eax
  unsigned int iValue; // [esp+18h] [ebp+Ch]

  v4 = this->m_pRulesList->GetItem_2(this: this->m_pRulesList, a2: varName);
  v5 = this->m_pRulesList->GetItem(this: this->m_pRulesList, a2: v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    String = KeyValues::GetString(this: v5, keyName: "type", defaultValue: defaultValue);
    if ( _V_stricmp(s1: String, s2: "enumeration") != 0 )
    {
      KeyValues::SetString(this: v6, keyName: "value", value);
    }
    else
    {
      iValue = atoi(nptr: value);
      Key = KeyValues::FindKey(this: v6, keyName: "list", bCreate: true);
      v9 = KeyValues::GetString(this: Key, keyName: value, defaultValue: defaultValue);
      KeyValues::SetString(this: v6, keyName: "value", value: v9);
      KeyValues::SetInt(this: v6, keyName: "enum", value: iValue);
    }
    this->m_pRulesList->ApplyItemChanges(this: this->m_pRulesList, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004990
// Name: public: void CVarListPropertyPage::SetCustomStringList(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::SetCustomStringList(
        CVarListPropertyPage *this,
        const char *varName,
        const char *stringList)
{
  int v4; // eax
  KeyValues *v5; // eax

  v4 = this->m_pRulesList->GetItem_2(this: this->m_pRulesList, a2: varName);
  v5 = this->m_pRulesList->GetItem(this: this->m_pRulesList, a2: v4);
  if ( v5 != nullptr )
    KeyValues::SetString(this: v5, keyName: "stringlist", value: stringList);
}

//------------------------------------------------------------------------------
// Address: 0x100049E0
// Name: public: char const __near * CVarListPropertyPage::GetVarString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVarListPropertyPage::GetVarString(CVarListPropertyPage *this, const char *varName)
{
  int v3; // eax
  KeyValues *v4; // eax

  v3 = this->m_pRulesList->GetItem_2(this: this->m_pRulesList, a2: varName);
  v4 = this->m_pRulesList->GetItem(this: this->m_pRulesList, a2: v3);
  if ( v4 != nullptr )
    return KeyValues::GetString(this: v4, keyName: "value", defaultValue: defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10004A30
// Name: private: virtual void CVarListPropertyPage::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::OnItemSelected(CVarListPropertyPage *this)
{
  int v2; // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx

  v2 = this->m_pRulesList->GetSelectedItemsCount(this: this->m_pRulesList);
  SetEnabled = this->m_pEditButton->SetEnabled;
  if ( v2 <= 0 )
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  else
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10004A70
// Name: protected: virtual void CVarListPropertyPage::OnVarChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::OnVarChanged(CVarListPropertyPage *this, const char *var)
{
  IServerDataResponse *v2; // eax
  CRemoteServer *v3; // eax
  CRemoteServer *v4; // eax
  IServerDataResponse *v5; // [esp-8h] [ebp-8h]

  if ( this != nullptr )
    v2 = &this->IServerDataResponse;
  else
    v2 = nullptr;
  v5 = v2;
  v3 = RemoteServer();
  CRemoteServer::RequestValue(this: v3, requester: v5, variable: var);
  v4 = RemoteServer();
  CRemoteServer::ProcessServerResponse(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10004AB0
// Name: protected: virtual void CVarListPropertyPage::OnServerDataResponse(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarListPropertyPage::OnServerDataResponse(
        CVarListPropertyPage *this,
        const char *value,
        const char *response)
{
  CVarListPropertyPage::SetVarString(
    this: (CVarListPropertyPage *)((char *)this - 392),
    varName: value,
    value: response);
}

//------------------------------------------------------------------------------
// Address: 0x10004AD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVarListPropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVarListPropertyPage::GetMessageMap(CVarListPropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVarListPropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVarListPropertyPage::GetMessageMap'::`2'::s_pMap;
  `CVarListPropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVarListPropertyPage");
  `CVarListPropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004B00
// Name: public: virtual struct PanelAnimationMap __near * CVarListPropertyPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVarListPropertyPage::GetAnimMap(CVarListPropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CVarListPropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x10004B10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVarListPropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVarListPropertyPage::GetKBMap(CVarListPropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVarListPropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVarListPropertyPage::GetKBMap'::`2'::s_pMap;
  `CVarListPropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVarListPropertyPage");
  `CVarListPropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004B90
// Name: public: static void CVarListPropertyPage::PanelMessageFunc_OnVarChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVarListPropertyPage::PanelMessageFunc_OnVarChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVarListPropertyPage::PanelMessageFunc_OnVarChanged::InitVar'::`2'::bAdded )
  {
    `CVarListPropertyPage::PanelMessageFunc_OnVarChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVarListPropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "VarChanged";
    v4.func = v2;
    v4.firstParamName = "var";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C30
// Name: public: static void CVarListPropertyPage::PanelMessageFunc_EditVariable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVarListPropertyPage::PanelMessageFunc_EditVariable::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVarListPropertyPage::PanelMessageFunc_EditVariable::InitVar'::`2'::bAdded )
  {
    `CVarListPropertyPage::PanelMessageFunc_EditVariable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVarListPropertyPage::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVarListPropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "EditVariable";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CC0
// Name: public: static void CVarListPropertyPage::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVarListPropertyPage::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVarListPropertyPage::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CVarListPropertyPage::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CPlayerPanel::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVarListPropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004D50
// Name: public: CVarListPropertyPage::CVarListPropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVarListPropertyPage *__thiscall CVarListPropertyPage::CVarListPropertyPage(
        CVarListPropertyPage *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&IServerDataResponse::`vftable';
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CVarListPropertyPage_vtbl *)&CVarListPropertyPage::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CVarListPropertyPage::`vftable'{for `IServerDataResponse'};
  if ( `CVarListPropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `CVarListPropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVarListPropertyPage");
    v4->pfnClassName = CVarListPropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CVarListPropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVarListPropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVarListPropertyPage");
    v5->pfnClassName = CVarListPropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CVarListPropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVarListPropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVarListPropertyPage");
    v6->pfnClassName = CVarListPropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CVarListPropertyPage::PanelMessageFunc_OnVarChanged::InitVar(a1: (int)&savedregs);
  CVarListPropertyPage::PanelMessageFunc_EditVariable::InitVar(a1: (int)&savedregs);
  CVarListPropertyPage::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "RulesList");
  else
    v8 = nullptr;
  this->m_pRulesList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "Variable", a5: 256, a6: 0);
  this->m_pRulesList->AddColumnHeader(this: this->m_pRulesList, a2: 1, a3: "value", a4: "Value", a5: 256, a6: 0);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "EditButton",
            text: "Edit...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pEditButton = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "EditVariable");
  else
    v12 = nullptr;
  this->m_pEditButton->SetCommand(this: this->m_pEditButton, a2: v12);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004B1E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B210
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x1004B220
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}
