// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributetextentry.cpp
// Functions: 24
// ============================================================

#include "vgui2\dme_controls\attributetextentry.h"

//------------------------------------------------------------------------------
// Address: 0x0047F2B0
// Name: public: static char const __near * CAttributeTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextEntry::GetPanelClassName()
{
  return "CAttributeTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x0047F2C0
// Name: protected: virtual void CAttributeTextEntry::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::ApplySchemeSettings(CAttributeTextEntry *this, vgui::IScheme *pScheme)
{
  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  this->SetBorder(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0047F2F0
// Name: protected: virtual bool CAttributeTextEntry::GetDropContextMenu(class vgui::Menu __near *,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAttributeTextEntry::GetDropContextMenu(
        CAttributeTextEntry *this,
        vgui::Menu *menu,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  menu->AddMenuItem(this: menu, a2: "Drop as Text", a3: "#BxDropText", a4: "droptext", a5: this, a6: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F320
// Name: protected: virtual void CAttributeTextEntry::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnTextChanged(CAttributeTextEntry *this, KeyValues *data)
{
  this->m_bValueStored = true;
}

//------------------------------------------------------------------------------
// Address: 0x0047F330
// Name: protected: virtual bool CAttributeTextEntry::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeTextEntry::IsDroppable(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v4; // edi
  vgui::Panel *Ptr; // ebx
  CAttributeTextPanel *v6; // eax
  CAttributeTextPanel *v7; // esi
  const char *TextType; // ebx
  const char *String; // eax
  int v10; // esi
  IDataModel_vtbl *v11; // esi
  int Int; // eax

  if ( !this->IsEnabled(this) || msglist->m_Size != 1 )
    return false;
  v4 = *msglist->m_Memory.m_pMemory;
  Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v4, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->GetParent(this) )
    return false;
  v6 = (CAttributeTextPanel *)this->GetParent(this);
  v7 = v6;
  if ( v6 == nullptr )
    return false;
  TextType = CAttributeTextPanel::GetTextType(this: v6);
  if ( *TextType != 0 )
  {
    String = KeyValues::GetString(this: v4, keyName: "texttype", defaultValue: defaultValue);
    if ( _V_stricmp(s1: TextType, s2: String) != 0 )
      return false;
  }
  v10 = v7->m_AttributeType - 1;
  if ( v10 != 0 )
    return v10 != 14;
  v11 = g_pDataModel->__vftable;
  Int = KeyValues::GetInt(this: v4, keyName: "root", defaultValue: 0);
  return v11->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)Int) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047F410
// Name: public: float const __near & CBaseAttributePanel::GetAttributeValue<float>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CBaseAttributePanel::GetAttributeValue<float>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<float> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<float>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp = 0.0;
    return (CDmaVar<float> *)&`CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F4A0
// Name: public: void CBaseAttributePanel::SetAttributeValue<float>(float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<float>(CBaseAttributePanel *this, float *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
      this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F550
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<float>(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<float>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        float newValue,
        float originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F670
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<int>(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<int>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        int newValue,
        int originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F790
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<bool>(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<bool>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        bool newValue,
        bool originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F8B0
// Name: public: static void CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x0047F940
// Name: public: CAttributeTextEntry::CAttributeTextEntry(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeTextEntry::CAttributeTextEntry(
        CAttributeTextEntry *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (CAttributeTextEntry_vtbl *)&CAttributeTextEntry::`vftable';
  if ( `CAttributeTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    v4->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
    v5->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
    v6->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TextEntry");
  }
  CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_bValueStored = false;
  this->m_nOriginalValue = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.5);
  this->m_szOriginalText[0] = 0;
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047FA50
// Name: public: virtual bool CAttributeTextEntry::GetSelectedRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeTextEntry::GetSelectedRange(CAttributeTextEntry *this, int *cx0, int *cx1)
{
  return vgui::TextEntry::GetSelectedRange(this, cx0, cx1);
}

//------------------------------------------------------------------------------
// Address: 0x0047FA60
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextEntry::GetMessageMap(CAttributeTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047FA90
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextEntry::GetAnimMap(CAttributeTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x0047FAA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextEntry::GetKBMap(CAttributeTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047FAD0
// Name: private: void CAttributeTextEntry::StoreInitialValue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::StoreInitialValue(CAttributeTextEntry *this, bool bForce)
{
  int (*GetParent)(void); // edx
  int v4; // ecx

  if ( !this->m_bValueStored || bForce )
  {
    GetParent = (int (*)(void))this->GetParent;
    this->m_bValueStored = true;
    v4 = GetParent();
    switch ( *(_DWORD *)(v4 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FB60
// Name: private: void CAttributeTextEntry::WriteInitialValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::WriteInitialValueToAttribute(CAttributeTextEntry *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  vgui::Panel *v3; // esi
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bValueStored )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v3 = this->GetParent(this);
    switch ( *(_DWORD *)&v3[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v3, value: (int *)&this->___u7);
        break;
      case 3:
        CBaseAttributePanel::SetAttributeValue<float>(this: (CBaseAttributePanel *)v3, value: &this->m_flOriginalValue);
        break;
      case 4:
        CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v3, value: (bool *)&this->___u7);
        break;
      default:
        CBaseAttributePanel::SetAttributeValueFromString(
          this: (CBaseAttributePanel *)v3,
          pString: this->m_szOriginalText);
        break;
    }
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v3, dirty: false);
    v3->__vftable[1].Repaint(this: v3);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FC30
// Name: protected: virtual void CAttributeTextEntry::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnSetFocus(CAttributeTextEntry *this)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v3; // ecx

  vgui::TextEntry::OnSetFocus(this);
  if ( !this->m_bValueStored )
  {
    GetParent = this->GetParent;
    this->m_bValueStored = true;
    v3 = (int)GetParent(this);
    switch ( *(_DWORD *)(v3 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FCB0
// Name: private: void CAttributeTextEntry::WriteValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::WriteValueToAttribute(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  vgui::Panel *v4; // edi
  int v5; // eax
  int v6; // eax
  float newValue; // [esp+8h] [ebp-410h]
  bool originalValue; // [esp+Ch] [ebp-40Ch]
  int originalValuea; // [esp+Ch] [ebp-40Ch]
  int originalValueb; // [esp+Ch] [ebp-40Ch]
  char newText[1024]; // [esp+18h] [ebp-400h] BYREF

  if ( this->m_bValueStored )
  {
    GetText_2 = this->GetText_2;
    this->m_bValueStored = false;
    GetText_2(this, a2: newText, a3: 1024);
    v4 = this->GetParent(this);
    switch ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        originalValueb = this->m_nOriginalValue;
        v6 = atoi(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<int>(this, a2, newValue: v6, originalValue: originalValueb);
        break;
      case 3:
        originalValuea = this->m_nOriginalValue;
        newValue = atof(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<float>(this, a2, newValue, originalValue: *(float *)&originalValuea);
        break;
      case 4:
        originalValue = this->m_bOriginalValue;
        v5 = atoi(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<bool>(this, a2, newValue: v5 != 0, originalValue);
        break;
      default:
        if ( _V_strcmp(s1: newText, s2: this->m_szOriginalText) != 0 )
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
          if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
          {
            ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
            CAttributeTextEntry::StoreInitialValue(this, bForce: true);
          }
        }
        else
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: false);
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FDF0
// Name: protected: virtual void CAttributeTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::OnKillFocus(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v4; // ecx

  vgui::TextEntry::OnKillFocus(this);
  if ( this->IsEnabled(this) )
  {
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
    if ( !this->m_bValueStored )
    {
      GetParent = this->GetParent;
      this->m_bValueStored = true;
      v4 = (int)GetParent(this);
      switch ( *(_DWORD *)(v4 + 616) )
      {
        case 2:
          this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 3:
          this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 4:
          this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        default:
          this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FE90
// Name: protected: virtual void CAttributeTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnMouseWheeled(CAttributeTextEntry *this@<ecx>, int a2@<esi>, int delta)
{
  vgui::Panel *v4; // esi
  int v5; // eax
  CChangeUndoScopeGuard *p_notify; // ecx
  float v7; // xmm0_4
  bool v8; // al
  float v9; // xmm0_4
  CDmaVar<float> *Attribute; // eax
  int v11; // xmm1_4
  int v12; // edi
  CElementTreeNotifyScopeGuard notify; // [esp+4h] [ebp-10h] BYREF
  CDisableUndoScopeGuard v15; // [esp+Ch] [ebp-8h] BYREF

  if ( !this->HasFocus(this) || !this->IsEnabled(this) )
  {
    vgui::TextEntry::OnMouseWheeled(this, delta);
    return;
  }
  v4 = this->GetParent(this);
  v5 = *(_DWORD *)&v4[1].m_m_nBgTextureId1_register;
  if ( (v5 & 8) != 0 && (v5 & 0x10) != 0 )
  {
    ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
    CAttributeTextEntry::StoreInitialValue(this, bForce: true);
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 2 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
      v12 = 10 * delta;
    else
      v12 = delta;
    *(_DWORD *)&v15.m_bOldValue = v12
                                + CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v4, value: (int *)&v15.m_bOldValue);
    goto LABEL_24;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 3 )
  {
    if ( ((unsigned __int8 (__thiscall *)(vgui::IInput *, int, int))g_pVGuiInput->IsKeyDown)(
           a1: g_pVGuiInput,
           a2: 79,
           a3: a2) != 0 )
    {
      v7 = (float)delta * 10.0;
    }
    else
    {
      v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v9 = (float)delta;
      if ( v8 )
        v7 = v9 * 0.01;
      else
        v7 = v9 * 0.1;
    }
    *(float *)&delta = v7;
    Attribute = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4);
    *(float *)&v15.m_bOldValue = *(float *)&delta + Attribute->m_Storage;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v11 = 1065353216;
      if ( *(float *)&v15.m_bOldValue > 1.0 || (v11 = 0, *(float *)&v15.m_bOldValue < 0.0) )
        *(_DWORD *)&v15.m_bOldValue = v11;
    }
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<float>(this: (CBaseAttributePanel *)v4, value: (float *)&v15.m_bOldValue);
LABEL_24:
    p_notify = (CChangeUndoScopeGuard *)&notify;
    goto LABEL_25;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register != 4 )
    return;
  HIBYTE(delta) = !CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
  CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &v15);
  CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v4, value: (bool *)&delta + 3);
  p_notify = &v15;
LABEL_25:
  CChangeUndoScopeGuard::Release(this: p_notify);
  v4->__vftable[1].Repaint(this: v4);
  if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
  {
    CElementTreeNotifyScopeGuard::CElementTreeNotifyScopeGuard(
      this: &notify,
      pReason: "CAttributeTextEntry::OnMouseWheeled",
      nNotifyFlags: 8448,
      pNotify: (IDmNotify *)v4[1].m_nPaintBackgroundType);
    CElementTreeNotifyScopeGuard::~CElementTreeNotifyScopeGuard(this: &notify);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004800B0
// Name: protected: virtual void CAttributeTextEntry::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnPanelDropped(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v3; // ebx
  vgui::Panel *Ptr; // esi
  CAttributeTextPanel *v5; // eax
  CAttributeTextPanel *v6; // esi
  const char *v7; // eax
  int Int; // eax
  CAttributeTextEntry_vtbl *v9; // ebx
  const char *v10; // [esp-Ch] [ebp-14h]
  const char *String; // [esp-Ch] [ebp-14h]
  KeyValues *data; // [esp+4h] [ebp-4h]
  const char *cmd; // [esp+10h] [ebp+8h]
  const char *cmda; // [esp+10h] [ebp+8h]
  CAttributeTextEntry_vtbl *cmdb; // [esp+10h] [ebp+8h]
  IDataModel_vtbl *cmdc; // [esp+10h] [ebp+8h]

  if ( msglist->m_Size == 1 )
  {
    v3 = *msglist->m_Memory.m_pMemory;
    data = v3;
    Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr);
    if ( Ptr != this->GetParent(this) )
    {
      v5 = (CAttributeTextPanel *)this->GetParent(this);
      v6 = v5;
      if ( v5 != nullptr )
      {
        cmd = CAttributeTextPanel::GetTextType(this: v5);
        if ( *cmd == 0
          || (v7 = KeyValues::GetString(this: v3, keyName: "texttype", defaultValue: defaultValue),
              _V_stricmp(s1: cmd, s2: v7) == 0) )
        {
          cmda = KeyValues::GetString(this: v3, keyName: "command", defaultValue: defaultValue);
          if ( _V_stricmp(s1: cmda, s2: "droptext") != 0 && _V_stricmp(s1: cmda, s2: "default") != 0 )
            goto LABEL_15;
          if ( v6->m_AttributeType == AT_FIRST_VALUE_TYPE )
          {
            cmdc = g_pDataModel->__vftable;
            Int = KeyValues::GetInt(this: v3, keyName: "root", defaultValue: 0);
            if ( cmdc->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)Int) != nullptr )
            {
              CBaseAttributePanel::SetDirty(this: v6, dirty: true);
              v9 = this->__vftable;
              String = KeyValues::GetString(this: data, keyName: "text", defaultValue: defaultValue);
              v9->SetText(this, a2: String);
LABEL_13:
              if ( (v6->m_nFlags & 0x10) != 0 )
                v6->Apply(this: v6);
            }
          }
          else if ( v6->m_AttributeType != AT_FIRST_ARRAY_TYPE )
          {
            CBaseAttributePanel::SetDirty(this: v6, dirty: true);
            cmdb = this->__vftable;
            v10 = KeyValues::GetString(this: v3, keyName: "text", defaultValue: defaultValue);
            cmdb->SetText(this, a2: v10);
            goto LABEL_13;
          }
LABEL_15:
          CAttributeTextEntry::StoreInitialValue(this, bForce: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480240
// Name: protected: virtual void CAttributeTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnKeyCodeTyped(CAttributeTextEntry *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  bool v4; // al
  vgui::Panel *v5; // eax

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
  {
    v4 = true;
  }
  if ( code == KEY_Z )
  {
    if ( v4 )
    {
      CAttributeTextEntry::WriteInitialValueToAttribute(this);
      return;
    }
    goto LABEL_12;
  }
  if ( code != KEY_ENTER )
  {
LABEL_12:
    vgui::TextEntry::OnKeyCodeTyped(this, code);
    return;
  }
  v5 = this->GetParent(this);
  if ( (*(_DWORD *)&v5[1].m_m_nBgTextureId1_register & 0x10) != 0 )
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
  else
    ((void (__thiscall *)(vgui::Panel *))v5->__vftable[1].PaintTraverse)(a1: v5);
  CAttributeTextEntry::StoreInitialValue(this, bForce: true);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104A2530
// Name: public: static char const __near * CAttributeTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextEntry::GetPanelClassName()
{
  return "CAttributeTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x104A2540
// Name: protected: virtual void CAttributeTextEntry::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::ApplySchemeSettings(CAttributeTextEntry *this, vgui::IScheme *pScheme)
{
  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  this->SetBorder(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104A2570
// Name: protected: virtual bool CAttributeTextEntry::GetDropContextMenu(class vgui::Menu __near *,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAttributeTextEntry::GetDropContextMenu(
        CAttributeTextEntry *this,
        vgui::Menu *menu,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  menu->AddMenuItem(this: menu, a2: "Drop as Text", a3: "#BxDropText", a4: "droptext", a5: this, a6: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104A25A0
// Name: protected: virtual void CAttributeTextEntry::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnTextChanged(CAttributeTextEntry *this, KeyValues *data)
{
  this->m_bValueStored = true;
}

//------------------------------------------------------------------------------
// Address: 0x104A25B0
// Name: protected: virtual bool CAttributeTextEntry::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeTextEntry::IsDroppable(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v4; // edi
  vgui::Panel *Ptr; // ebx
  CAttributeTextPanel *v6; // eax
  CAttributeTextPanel *v7; // esi
  const char *TextType; // ebx
  char *String; // eax
  int v10; // esi
  IDataModel_vtbl *v11; // esi
  int Int; // eax

  if ( !this->IsEnabled(this) || msglist->m_Size != 1 )
    return false;
  v4 = *msglist->m_Memory.m_pMemory;
  Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v4, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->GetParent(this) )
    return false;
  v6 = (CAttributeTextPanel *)this->GetParent(this);
  v7 = v6;
  if ( v6 == nullptr )
    return false;
  TextType = CAttributeTextPanel::GetTextType(this: v6);
  if ( *TextType != 0 )
  {
    String = KeyValues::GetString(this: v4, keyName: "texttype", defaultValue: &var);
    if ( _V_stricmp(s1: TextType, s2: String) != 0 )
      return false;
  }
  v10 = v7->m_AttributeType - 1;
  if ( v10 != 0 )
    return v10 != 14;
  v11 = g_pDataModel->__vftable;
  Int = KeyValues::GetInt(this: v4, keyName: "root", defaultValue: 0);
  return v11->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)Int) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104A2690
// Name: public: float const __near & CBaseAttributePanel::GetAttributeValue<float>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CBaseAttributePanel::GetAttributeValue<float>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<float> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<float>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp = 0.0;
    return (CDmaVar<float> *)&`CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2720
// Name: public: void CBaseAttributePanel::SetAttributeValue<float>(float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<float>(CBaseAttributePanel *this, float *value)
{
  char *m_szAttributeName; // edi
  CFmtStrN<256> *v4; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  int v8; // eax
  int m_nArrayIndex; // esi
  CDmElement *v10; // ebx
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+114h] [ebp-8h] BYREF

  m_szAttributeName = this->m_szAttributeName;
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "Set %s", this->m_szAttributeName);
  g_pDataModel->StartUndo(this: g_pDataModel, a2: v4->m_szBuf, a3: v4->m_szBuf, a4: 0);
  GetElement = g_pDataModel->GetElement;
  if ( this->m_nArrayIndex >= 0 )
  {
    v8 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v10 = (CDmElement *)v8;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v12,
      pElement: v10,
      pAttributeName: m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
      this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v12,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: m_szAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x104A27F0
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<float>(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<float>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        float newValue,
        float originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2910
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<int>(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<int>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        int newValue,
        int originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2A30
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<bool>(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<bool>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        bool newValue,
        bool originalValue)
{
  CBaseAttributePanel *v4; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &newValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2B50
// Name: public: static void CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x104A2BE0
// Name: public: CAttributeTextEntry::CAttributeTextEntry(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeTextEntry::CAttributeTextEntry(
        CAttributeTextEntry *this,
        vgui::Panel *parent,
        vgui::Panel *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int _8; // [esp+8h] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (CAttributeTextEntry_vtbl *)&CAttributeTextEntry::`vftable';
  if ( `CAttributeTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    v4->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
    v5->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
    v6->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TextEntry");
  }
  CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&_8);
  this->m_bValueStored = false;
  this->m_nOriginalValue = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.5);
  this->m_szOriginalText[0] = 0;
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A2CF0
// Name: public: virtual bool CAttributeTextEntry::GetSelectedRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAttributeTextEntry::GetSelectedRange(CAttributeTextEntry *this, int *cx0, int *cx1)
{
  return vgui::TextEntry::GetSelectedRange(this, cx0, cx1);
}

//------------------------------------------------------------------------------
// Address: 0x104A2D00
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextEntry::GetMessageMap(CAttributeTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A2D30
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextEntry::GetAnimMap(CAttributeTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x104A2D40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextEntry::GetKBMap(CAttributeTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A2DA0
// Name: private: void CAttributeTextEntry::StoreInitialValue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::StoreInitialValue(CAttributeTextEntry *this, bool bForce)
{
  int (*GetParent)(void); // edx
  int v4; // ecx

  if ( !this->m_bValueStored || bForce )
  {
    GetParent = (int (*)(void))this->GetParent;
    this->m_bValueStored = true;
    v4 = GetParent();
    switch ( *(_DWORD *)(v4 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2E30
// Name: private: void CAttributeTextEntry::WriteInitialValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::WriteInitialValueToAttribute(CAttributeTextEntry *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  vgui::Panel *v3; // esi
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bValueStored )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v3 = this->GetParent(this);
    switch ( *(_DWORD *)&v3[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v3, value: (int *)&this->___u7);
        break;
      case 3:
        CBaseAttributePanel::SetAttributeValue<float>(this: (CBaseAttributePanel *)v3, value: &this->m_flOriginalValue);
        break;
      case 4:
        CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v3, value: (bool *)&this->___u7);
        break;
      default:
        CBaseAttributePanel::SetAttributeValueFromString(
          this: (CBaseAttributePanel *)v3,
          pString: this->m_szOriginalText);
        break;
    }
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v3, dirty: false);
    v3->__vftable[1].Repaint(this: v3);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2F00
// Name: protected: virtual void CAttributeTextEntry::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnSetFocus(CAttributeTextEntry *this)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v3; // ecx

  vgui::TextEntry::OnSetFocus(this);
  if ( !this->m_bValueStored )
  {
    GetParent = this->GetParent;
    this->m_bValueStored = true;
    v3 = (int)GetParent(this);
    switch ( *(_DWORD *)(v3 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2F80
// Name: private: void CAttributeTextEntry::WriteValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::WriteValueToAttribute(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  vgui::Panel *v4; // edi
  int v5; // eax
  int v6; // eax
  float v7; // [esp+0h] [ebp-410h]
  bool m_bOriginalValue; // [esp+4h] [ebp-40Ch]
  int v9; // [esp+4h] [ebp-40Ch]
  int m_nOriginalValue; // [esp+4h] [ebp-40Ch]
  char s1[4]; // [esp+10h] [ebp-400h] BYREF

  if ( this->m_bValueStored )
  {
    GetText_2 = this->GetText_2;
    this->m_bValueStored = false;
    GetText_2(this, a2: s1, a3: 1024);
    v4 = this->GetParent(this);
    switch ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        m_nOriginalValue = this->m_nOriginalValue;
        v6 = atoi(nptr: s1);
        CAttributeTextEntry::ApplyMouseWheel<int>(this, a2, newValue: v6, originalValue: m_nOriginalValue);
        break;
      case 3:
        v9 = this->m_nOriginalValue;
        v7 = atof(nptr: s1);
        CAttributeTextEntry::ApplyMouseWheel<float>(this, a2, newValue: v7, originalValue: *(float *)&v9);
        break;
      case 4:
        m_bOriginalValue = this->m_bOriginalValue;
        v5 = atoi(nptr: s1);
        CAttributeTextEntry::ApplyMouseWheel<bool>(this, a2, newValue: v5 != 0, originalValue: m_bOriginalValue);
        break;
      default:
        if ( _V_strcmp(s1, s2: this->m_szOriginalText) != 0 )
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
          if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
          {
            ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
            CAttributeTextEntry::StoreInitialValue(this, bForce: true);
          }
        }
        else
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: false);
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A30C0
// Name: protected: virtual void CAttributeTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::OnKillFocus(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v4; // ecx

  vgui::TextEntry::OnKillFocus(this);
  if ( this->IsEnabled(this) )
  {
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
    if ( !this->m_bValueStored )
    {
      GetParent = this->GetParent;
      this->m_bValueStored = true;
      v4 = (int)GetParent(this);
      switch ( *(_DWORD *)(v4 + 616) )
      {
        case 2:
          this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 3:
          this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 4:
          this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        default:
          this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3160
// Name: protected: virtual void CAttributeTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnMouseWheeled(CAttributeTextEntry *this@<ecx>, int a2@<esi>, int delta)
{
  vgui::Panel *v4; // esi
  int v5; // eax
  CChangeUndoScopeGuard *p_notify; // ecx
  float v7; // xmm0_4
  bool v8; // al
  float v9; // xmm0_4
  CDmaVar<float> *Attribute; // eax
  int v11; // xmm1_4
  int v12; // edi
  CElementTreeNotifyScopeGuard notify; // [esp+4h] [ebp-10h] BYREF
  CDisableUndoScopeGuard v15; // [esp+Ch] [ebp-8h] BYREF

  if ( !this->HasFocus(this) || !this->IsEnabled(this) )
  {
    vgui::TextEntry::OnMouseWheeled(this, delta);
    return;
  }
  v4 = this->GetParent(this);
  v5 = *(_DWORD *)&v4[1].m_m_nBgTextureId1_register;
  if ( (v5 & 8) != 0 && (v5 & 0x10) != 0 )
  {
    ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
    CAttributeTextEntry::StoreInitialValue(this, bForce: true);
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 2 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
      v12 = 10 * delta;
    else
      v12 = delta;
    *(_DWORD *)&v15.m_bOldValue = v12
                                + CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v4, value: (int *)&v15.m_bOldValue);
    goto LABEL_24;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 3 )
  {
    if ( ((unsigned __int8 (__thiscall *)(vgui::IInput *, int, int))g_pVGuiInput->IsKeyDown)(
           a1: g_pVGuiInput,
           a2: 79,
           a3: a2) != 0 )
    {
      v7 = (float)delta * 10.0;
    }
    else
    {
      v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v9 = (float)delta;
      if ( v8 )
        v7 = v9 * 0.01;
      else
        v7 = v9 * 0.1;
    }
    *(float *)&delta = v7;
    Attribute = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4);
    *(float *)&v15.m_bOldValue = *(float *)&delta + Attribute->m_Storage;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v11 = 1065353216;
      if ( *(float *)&v15.m_bOldValue > 1.0 || (v11 = 0, *(float *)&v15.m_bOldValue < 0.0) )
        *(_DWORD *)&v15.m_bOldValue = v11;
    }
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<float>(this: (CBaseAttributePanel *)v4, value: (float *)&v15.m_bOldValue);
LABEL_24:
    p_notify = (CChangeUndoScopeGuard *)&notify;
    goto LABEL_25;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register != 4 )
    return;
  HIBYTE(delta) = !CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
  CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &v15);
  CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v4, value: (bool *)&delta + 3);
  p_notify = &v15;
LABEL_25:
  CChangeUndoScopeGuard::Release(this: p_notify);
  v4->__vftable[1].Repaint(this: v4);
  if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
  {
    CElementTreeNotifyScopeGuard::CElementTreeNotifyScopeGuard(
      this: &notify,
      pReason: "CAttributeTextEntry::OnMouseWheeled",
      nNotifyFlags: 8448,
      pNotify: (IDmNotify *)v4[1].m_nPaintBackgroundType);
    CElementTreeNotifyScopeGuard::~CElementTreeNotifyScopeGuard(this: &notify);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3380
// Name: protected: virtual void CAttributeTextEntry::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnPanelDropped(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v3; // ebx
  vgui::Panel *Ptr; // esi
  CAttributeTextPanel *v5; // eax
  CAttributeTextPanel *v6; // esi
  char *v7; // eax
  int Int; // eax
  CAttributeTextEntry_vtbl *v9; // ebx
  char *v10; // [esp-Ch] [ebp-14h]
  char *String; // [esp-Ch] [ebp-14h]
  KeyValues *data; // [esp+4h] [ebp-4h]
  const char *cmd; // [esp+10h] [ebp+8h]
  char *cmda; // [esp+10h] [ebp+8h]
  CAttributeTextEntry_vtbl *cmdb; // [esp+10h] [ebp+8h]
  IDataModel_vtbl *cmdc; // [esp+10h] [ebp+8h]

  if ( msglist->m_Size == 1 )
  {
    v3 = *msglist->m_Memory.m_pMemory;
    data = v3;
    Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr);
    if ( Ptr != this->GetParent(this) )
    {
      v5 = (CAttributeTextPanel *)this->GetParent(this);
      v6 = v5;
      if ( v5 != nullptr )
      {
        cmd = CAttributeTextPanel::GetTextType(this: v5);
        if ( *cmd == 0
          || (v7 = KeyValues::GetString(this: v3, keyName: "texttype", defaultValue: &var),
              _V_stricmp(s1: cmd, s2: v7) == 0) )
        {
          cmda = KeyValues::GetString(this: v3, keyName: "command", defaultValue: &var);
          if ( _V_stricmp(s1: cmda, s2: "droptext") != 0 && _V_stricmp(s1: cmda, s2: aDefa) != 0 )
            goto LABEL_15;
          if ( v6->m_AttributeType == AT_FIRST_VALUE_TYPE )
          {
            cmdc = g_pDataModel->__vftable;
            Int = KeyValues::GetInt(this: v3, keyName: "root", defaultValue: 0);
            if ( cmdc->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)Int) != nullptr )
            {
              CBaseAttributePanel::SetDirty(this: v6, dirty: true);
              v9 = this->__vftable;
              String = KeyValues::GetString(this: data, keyName: "text", defaultValue: &var);
              v9->SetText(this, a2: String);
LABEL_13:
              if ( (v6->m_nFlags & 0x10) != 0 )
                v6->Apply(this: v6);
            }
          }
          else if ( v6->m_AttributeType != AT_FIRST_ARRAY_TYPE )
          {
            CBaseAttributePanel::SetDirty(this: v6, dirty: true);
            cmdb = this->__vftable;
            v10 = KeyValues::GetString(this: v3, keyName: "text", defaultValue: &var);
            cmdb->SetText(this, a2: v10);
            goto LABEL_13;
          }
LABEL_15:
          CAttributeTextEntry::StoreInitialValue(this, bForce: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3510
// Name: protected: virtual void CAttributeTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnKeyCodeTyped(CAttributeTextEntry *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  bool v4; // al
  vgui::Panel *v5; // eax

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
  {
    v4 = true;
  }
  if ( code == KEY_Z )
  {
    if ( v4 )
    {
      CAttributeTextEntry::WriteInitialValueToAttribute(this);
      return;
    }
    goto LABEL_12;
  }
  if ( code != KEY_ENTER )
  {
LABEL_12:
    vgui::TextEntry::OnKeyCodeTyped(this, code);
    return;
  }
  v5 = this->GetParent(this);
  if ( (*(_DWORD *)&v5[1].m_m_nBgTextureId1_register & 0x10) != 0 )
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
  else
    ((void (__thiscall *)(vgui::Panel *))v5->__vftable[1].PaintTraverse)(a1: v5);
  CAttributeTextEntry::StoreInitialValue(this, bForce: true);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A2CD0
// Name: public: static char const __near * CAttributeTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextEntry::GetPanelClassName()
{
  return "CAttributeTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x004A2CE0
// Name: protected: virtual void CAttributeTextEntry::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::ApplySchemeSettings(CAttributeTextEntry *this, vgui::IScheme *pScheme)
{
  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  this->SetBorder(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004A2D10
// Name: protected: virtual bool CAttributeTextEntry::GetDropContextMenu(class vgui::Menu __near *,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAttributeTextEntry::GetDropContextMenu(
        CAttributeTextEntry *this,
        vgui::Menu *menu,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  menu->AddMenuItem(this: menu, a2: "Drop as Text", a3: "#BxDropText", a4: "droptext", a5: this, a6: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2D40
// Name: protected: virtual void CAttributeTextEntry::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnTextChanged(CAttributeTextEntry *this, KeyValues *data)
{
  this->m_bValueStored = true;
}

//------------------------------------------------------------------------------
// Address: 0x004A2D50
// Name: protected: virtual bool CAttributeTextEntry::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeTextEntry::IsDroppable(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v4; // edi
  vgui::Panel *Ptr; // ebx
  CAttributeTextPanel *v6; // eax
  CAttributeTextPanel *v7; // esi
  const char *TextType; // ebx
  const char *String; // eax
  int v10; // esi
  int v11; // esi
  int Int; // eax

  if ( !this->IsEnabled(this) || msglist->m_Size != 1 )
    return false;
  v4 = *msglist->m_Memory.m_pMemory;
  Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v4, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->GetParent(this) )
    return false;
  v6 = (CAttributeTextPanel *)this->GetParent(this);
  v7 = v6;
  if ( v6 == nullptr )
    return false;
  TextType = CAttributeTextPanel::GetTextType(this: v6);
  if ( *TextType != 0 )
  {
    String = KeyValues::GetString(this: v4, keyName: "texttype", defaultValue: defaultValue);
    if ( _V_stricmp(s1: TextType, s2: String) != 0 )
      return false;
  }
  v10 = v7->m_AttributeType - 1;
  if ( v10 != 0 )
    return v10 != 14;
  v11 = *(_DWORD *)g_pDataModel.u.m_Id;
  Int = KeyValues::GetInt(this: v4, keyName: "root", defaultValue: 0);
  return (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v11 + 72))(a1: g_pDataModel.u, a2: Int) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004A2E30
// Name: public: float const __near & CBaseAttributePanel::GetAttributeValue<float>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CBaseAttributePanel::GetAttributeValue<float>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<float> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<float>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp = 0.0;
    return (CDmaVar<float> *)&`CBaseAttributePanel::GetAttributeValue<float>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2EC0
// Name: public: void CBaseAttributePanel::SetAttributeValue<float>(float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<float>(CBaseAttributePanel *this, const float *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  int v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = (CDmElement *)v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: (CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
      this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2F70
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<float>(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<float>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        float newValue,
        float originalValue)
{
  CBaseAttributePanel *v4; // esi
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v6 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<float>(this: v4, value: &newValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v6 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3090
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<int>(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<int>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        int newValue,
        int originalValue)
{
  CBaseAttributePanel *v4; // esi
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v6 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<int>(this: v4, value: &newValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v6 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A31B0
// Name: private: void CAttributeTextEntry::ApplyMouseWheel<bool>(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::ApplyMouseWheel<bool>(
        CAttributeTextEntry *this@<ecx>,
        int a2@<ebx>,
        bool newValue,
        bool originalValue)
{
  CBaseAttributePanel *v4; // esi
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  IDmNotify *v6; // edi
  IDmNotify *m_pNotify; // ebx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = (CBaseAttributePanel *)this->GetParent(this);
  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v6 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &originalValue);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( (v4->m_nFlags & 0x10) != 0 )
  {
    v4->Apply(this: v4);
  }
  else
  {
    m_pNotify = v4->m_pNotify;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v6 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue<bool>(this: v4, value: &newValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v6 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A32D0
// Name: public: static void CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x004A3360
// Name: public: CAttributeTextEntry::CAttributeTextEntry(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeTextEntry::CAttributeTextEntry(
        CAttributeTextEntry *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (CAttributeTextEntry_vtbl *)&CAttributeTextEntry::`vftable';
  if ( `CAttributeTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
    v4->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
    v5->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TextEntry");
  }
  if ( `CAttributeTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
    v6->pfnClassName = CAttributeTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TextEntry");
  }
  CAttributeTextEntry::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_bValueStored = false;
  this->m_nOriginalValue = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.5);
  this->m_szOriginalText[0] = 0;
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A3470
// Name: public: virtual bool CAttributeTextEntry::GetSelectedRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAttributeTextEntry::GetSelectedRange(CAttributeTextEntry *this, int *cx0, int *cx1)
{
  return vgui::TextEntry::GetSelectedRange(this, cx0, cx1);
}

//------------------------------------------------------------------------------
// Address: 0x004A3480
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextEntry::GetMessageMap(CAttributeTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A34B0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextEntry::GetAnimMap(CAttributeTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x004A34C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextEntry::GetKBMap(CAttributeTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextEntry");
  `CAttributeTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A34F0
// Name: private: void CAttributeTextEntry::StoreInitialValue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::StoreInitialValue(CAttributeTextEntry *this, bool bForce)
{
  int (*GetParent)(void); // edx
  int v4; // ecx

  if ( !this->m_bValueStored || bForce )
  {
    GetParent = (int (*)(void))this->GetParent;
    this->m_bValueStored = true;
    v4 = GetParent();
    switch ( *(_DWORD *)(v4 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3580
// Name: private: void CAttributeTextEntry::WriteInitialValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::WriteInitialValueToAttribute(CAttributeTextEntry *this)
{
  unsigned __int8 (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  vgui::Panel *v3; // esi
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bValueStored )
  {
    v2 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v2)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    v3 = this->GetParent(this);
    switch ( *(_DWORD *)&v3[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v3, value: (const int *)&this->___u7);
        break;
      case 3:
        CBaseAttributePanel::SetAttributeValue<float>(this: (CBaseAttributePanel *)v3, value: &this->m_flOriginalValue);
        break;
      case 4:
        CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v3, value: (bool *)&this->___u7);
        break;
      default:
        CBaseAttributePanel::SetAttributeValueFromString(
          this: (CBaseAttributePanel *)v3,
          pString: this->m_szOriginalText);
        break;
    }
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v3, dirty: false);
    v3->__vftable[1].Repaint(this: v3);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3650
// Name: protected: virtual void CAttributeTextEntry::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnSetFocus(CAttributeTextEntry *this)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v3; // ecx

  vgui::TextEntry::OnSetFocus(this);
  if ( !this->m_bValueStored )
  {
    GetParent = this->GetParent;
    this->m_bValueStored = true;
    v3 = (int)GetParent(this);
    switch ( *(_DWORD *)(v3 + 616) )
    {
      case 2:
        this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 3:
        this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      case 4:
        this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v3)->m_Storage;
        break;
      default:
        this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A36D0
// Name: private: void CAttributeTextEntry::WriteValueToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::WriteValueToAttribute(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  vgui::Panel *v4; // edi
  int v5; // eax
  int v6; // eax
  float newValue; // [esp+8h] [ebp-410h]
  bool originalValue; // [esp+Ch] [ebp-40Ch]
  int originalValuea; // [esp+Ch] [ebp-40Ch]
  int originalValueb; // [esp+Ch] [ebp-40Ch]
  char newText[1024]; // [esp+18h] [ebp-400h] BYREF

  if ( this->m_bValueStored )
  {
    GetText_2 = this->GetText_2;
    this->m_bValueStored = false;
    GetText_2(this, a2: newText, a3: 1024);
    v4 = this->GetParent(this);
    switch ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register )
    {
      case 2:
        originalValueb = this->m_nOriginalValue;
        v6 = atoi(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<int>(this, a2, newValue: v6, originalValue: originalValueb);
        break;
      case 3:
        originalValuea = this->m_nOriginalValue;
        newValue = atof(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<float>(this, a2, newValue, originalValue: *(float *)&originalValuea);
        break;
      case 4:
        originalValue = this->m_bOriginalValue;
        v5 = atoi(nptr: newText);
        CAttributeTextEntry::ApplyMouseWheel<bool>(this, a2, newValue: v5 != 0, originalValue);
        break;
      default:
        if ( _V_strcmp(s1: newText, s2: this->m_szOriginalText) != 0 )
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
          if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
          {
            ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
            CAttributeTextEntry::StoreInitialValue(this, bForce: true);
          }
        }
        else
        {
          CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: false);
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3810
// Name: protected: virtual void CAttributeTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeTextEntry::OnKillFocus(CAttributeTextEntry *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *(__thiscall *GetParent)(vgui::Panel *); // edx
  int v4; // ecx

  vgui::TextEntry::OnKillFocus(this);
  if ( this->IsEnabled(this) )
  {
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
    if ( !this->m_bValueStored )
    {
      GetParent = this->GetParent;
      this->m_bValueStored = true;
      v4 = (int)GetParent(this);
      switch ( *(_DWORD *)(v4 + 616) )
      {
        case 2:
          this->m_nOriginalValue = CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 3:
          this->m_flOriginalValue = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        case 4:
          this->m_bOriginalValue = CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
          break;
        default:
          this->GetText_2(this, a2: this->m_szOriginalText, a3: 1024);
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A38B0
// Name: protected: virtual void CAttributeTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnMouseWheeled(CAttributeTextEntry *this@<ecx>, int a2@<esi>, int delta)
{
  vgui::Panel *v4; // esi
  int v5; // eax
  CChangeUndoScopeGuard *p_notify; // ecx
  float v7; // xmm0_4
  bool v8; // al
  float v9; // xmm0_4
  CDmaVar<float> *Attribute; // eax
  int v11; // xmm1_4
  int v12; // edi
  CElementTreeNotifyScopeGuard notify; // [esp+4h] [ebp-10h] BYREF
  CDisableUndoScopeGuard v15; // [esp+Ch] [ebp-8h] BYREF

  if ( !this->HasFocus(this) || !this->IsEnabled(this) )
  {
    vgui::TextEntry::OnMouseWheeled(this, delta);
    return;
  }
  v4 = this->GetParent(this);
  v5 = *(_DWORD *)&v4[1].m_m_nBgTextureId1_register;
  if ( (v5 & 8) != 0 && (v5 & 0x10) != 0 )
  {
    ((void (__thiscall *)(vgui::Panel *))v4->__vftable[1].PaintTraverse)(a1: v4);
    CAttributeTextEntry::StoreInitialValue(this, bForce: true);
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 2 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
      v12 = 10 * delta;
    else
      v12 = delta;
    *(_DWORD *)&v15.m_bOldValue = v12
                                + CBaseAttributePanel::GetAttributeValue<int>(this: (CBaseAttributePanel *)v4)->m_Storage;
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<int>(this: (CBaseAttributePanel *)v4, value: (const int *)&v15.m_bOldValue);
    goto LABEL_24;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register == 3 )
  {
    if ( ((unsigned __int8 (__thiscall *)(vgui::IInput *, int, int))g_pVGuiInput->IsKeyDown)(
           a1: g_pVGuiInput,
           a2: 79,
           a3: a2) != 0 )
    {
      v7 = (float)delta * 10.0;
    }
    else
    {
      v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v9 = (float)delta;
      if ( v8 )
        v7 = v9 * 0.01;
      else
        v7 = v9 * 0.1;
    }
    *(float *)&delta = v7;
    Attribute = CBaseAttributePanel::GetAttributeValue<float>(this: (CBaseAttributePanel *)v4);
    *(float *)&v15.m_bOldValue = *(float *)&delta + Attribute->m_Storage;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v11 = 1065353216;
      if ( *(float *)&v15.m_bOldValue > 1.0 || (v11 = 0, *(float *)&v15.m_bOldValue < 0.0) )
        *(_DWORD *)&v15.m_bOldValue = v11;
    }
    CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: (CDisableUndoScopeGuard *)&notify);
    CBaseAttributePanel::SetAttributeValue<float>(
      this: (CBaseAttributePanel *)v4,
      value: (const float *)&v15.m_bOldValue);
LABEL_24:
    p_notify = (CChangeUndoScopeGuard *)&notify;
    goto LABEL_25;
  }
  if ( *(_DWORD *)&v4[1].m_m_nPaintBackgroundType_register != 4 )
    return;
  HIBYTE(delta) = !CBaseAttributePanel::GetAttributeValue<bool>(this: (CBaseAttributePanel *)v4)->m_Storage;
  CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &v15);
  CBaseAttributePanel::SetAttributeValue<bool>(this: (CBaseAttributePanel *)v4, value: (bool *)&delta + 3);
  p_notify = &v15;
LABEL_25:
  CChangeUndoScopeGuard::Release(this: p_notify);
  v4->__vftable[1].Repaint(this: v4);
  if ( (*(_DWORD *)&v4[1].m_m_nBgTextureId1_register & 0x10) != 0 )
  {
    CElementTreeNotifyScopeGuard::CElementTreeNotifyScopeGuard(
      this: &notify,
      pReason: "CAttributeTextEntry::OnMouseWheeled",
      nNotifyFlags: 8448,
      pNotify: (IDmNotify *)v4[1].m_nPaintBackgroundType);
    CElementTreeNotifyScopeGuard::~CElementTreeNotifyScopeGuard(this: &notify);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this: (CBaseAttributePanel *)v4, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3AD0
// Name: protected: virtual void CAttributeTextEntry::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextEntry::OnPanelDropped(
        CAttributeTextEntry *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  KeyValues *v3; // ebx
  vgui::Panel *Ptr; // esi
  CAttributeTextPanel *v5; // eax
  CAttributeTextPanel *v6; // esi
  const char *v7; // eax
  int Int; // eax
  CAttributeTextEntry_vtbl *v9; // ebx
  const char *v10; // [esp-Ch] [ebp-14h]
  const char *String; // [esp-Ch] [ebp-14h]
  KeyValues *data; // [esp+4h] [ebp-4h]
  const char *cmd; // [esp+10h] [ebp+8h]
  const char *cmda; // [esp+10h] [ebp+8h]
  CAttributeTextEntry_vtbl *cmdb; // [esp+10h] [ebp+8h]
  const char *cmdc; // [esp+10h] [ebp+8h]

  if ( msglist->m_Size == 1 )
  {
    v3 = *msglist->m_Memory.m_pMemory;
    data = v3;
    Ptr = (vgui::Panel *)KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr);
    if ( Ptr != this->GetParent(this) )
    {
      v5 = (CAttributeTextPanel *)this->GetParent(this);
      v6 = v5;
      if ( v5 != nullptr )
      {
        cmd = CAttributeTextPanel::GetTextType(this: v5);
        if ( *cmd == 0
          || (v7 = KeyValues::GetString(this: v3, keyName: "texttype", defaultValue: defaultValue),
              _V_stricmp(s1: cmd, s2: v7) == 0) )
        {
          cmda = KeyValues::GetString(this: v3, keyName: "command", defaultValue: defaultValue);
          if ( _V_stricmp(s1: cmda, s2: "droptext") != 0 && _V_stricmp(s1: cmda, s2: "default") != 0 )
            goto LABEL_15;
          if ( v6->m_AttributeType == AT_FIRST_VALUE_TYPE )
          {
            cmdc = *(const char **)g_pDataModel.u.m_pAsString;
            Int = KeyValues::GetInt(this: v3, keyName: "root", defaultValue: 0);
            if ( (*((int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))cmdc + 18))(
                   a1: g_pDataModel.u,
                   a2: Int) != 0 )
            {
              CBaseAttributePanel::SetDirty(this: v6, dirty: true);
              v9 = this->__vftable;
              String = KeyValues::GetString(this: data, keyName: "text", defaultValue: defaultValue);
              v9->SetText(this, a2: String);
LABEL_13:
              if ( (v6->m_nFlags & 0x10) != 0 )
                v6->Apply(this: v6);
            }
          }
          else if ( v6->m_AttributeType != AT_FIRST_ARRAY_TYPE )
          {
            CBaseAttributePanel::SetDirty(this: v6, dirty: true);
            cmdb = this->__vftable;
            v10 = KeyValues::GetString(this: v3, keyName: "text", defaultValue: defaultValue);
            cmdb->SetText(this, a2: v10);
            goto LABEL_13;
          }
LABEL_15:
          CAttributeTextEntry::StoreInitialValue(this, bForce: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3C60
// Name: protected: virtual void CAttributeTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeTextEntry::OnKeyCodeTyped(CAttributeTextEntry *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  bool v4; // al
  vgui::Panel *v5; // eax

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
  {
    v4 = true;
  }
  if ( code == KEY_Z )
  {
    if ( v4 )
    {
      CAttributeTextEntry::WriteInitialValueToAttribute(this);
      return;
    }
    goto LABEL_12;
  }
  if ( code != KEY_ENTER )
  {
LABEL_12:
    vgui::TextEntry::OnKeyCodeTyped(this, code);
    return;
  }
  v5 = this->GetParent(this);
  if ( (*(_DWORD *)&v5[1].m_m_nBgTextureId1_register & 0x10) != 0 )
    CAttributeTextEntry::WriteValueToAttribute(this, a2);
  else
    ((void (__thiscall *)(vgui::Panel *))v5->__vftable[1].PaintTraverse)(a1: v5);
  CAttributeTextEntry::StoreInitialValue(this, bForce: true);
}

} // namespace sceneviewer
