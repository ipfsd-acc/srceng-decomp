// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributecolorpickerpanel.cpp
// Functions: 16
// ============================================================

#include "vgui2\dme_controls\attributecolorpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00471720
// Name: public: static char const __near * CAttributeColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeColorPickerPanel::GetPanelClassName()
{
  return "CAttributeColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00471730
// Name: public: virtual void CAttributeColorPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::PerformLayout(CAttributeColorPickerPanel *this)
{
  int pickerX; // [esp+4h] [ebp-10h] BYREF
  int pickerY; // [esp+8h] [ebp-Ch] BYREF
  int pickerW; // [esp+Ch] [ebp-8h] BYREF
  int pickerH; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  this->GetPickerBounds(this, a2: &pickerX, a3: &pickerY, a4: &pickerW, a5: &pickerH);
  vgui::Panel::SetBounds(this: this->m_pOpen, x: pickerX, y: pickerY, wide: pickerW, tall: pickerH);
}

//------------------------------------------------------------------------------
// Address: 0x00471940
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPreview";
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
// Address: 0x004719D0
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPicked";
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
// Address: 0x00471A60
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ColorPickerCancel";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471AF0
// Name: public: virtual void CAttributeColorPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCommand(CAttributeColorPickerPanel *this, const char *cmd)
{
  CColorPickerFrame *v3; // eax
  CColorPickerFrame *v4; // edi

  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
  {
    vgui::Panel::OnCommand(this, command: cmd);
  }
  else
  {
    this->m_InitialColor = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
    v3 = (CColorPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v3 != nullptr )
      v4 = CColorPickerFrame::CColorPickerFrame(this: v3, pParent: this, pTitle: "Select Color");
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    CColorPickerFrame::DoModal(this: v4, initialColor: this->m_InitialColor, pContextKeys: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471B70
// Name: private: void CAttributeColorPickerPanel::UpdateButtonColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::UpdateButtonColor(CAttributeColorPickerPanel *this)
{
  Color v2; // esi
  Color clr; // [esp+8h] [ebp-4h]

  clr = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
  clr._color[3] = -1;
  v2 = clr;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDefaultColor)(a1: this->m_pOpen, a2: clr, a3: clr);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetArmedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDepressedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00471BE0
// Name: public: virtual void CAttributeColorPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::Refresh(CAttributeColorPickerPanel *this)
{
  CAttributeTextPanel::Refresh(this);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x00471BF0
// Name: public: virtual void CAttributeColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::ApplySchemeSettings(
        CAttributeColorPickerPanel *this,
        vgui::IScheme *pScheme)
{
  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x00471C10
// Name: private: virtual void CAttributeColorPickerPanel::OnPreview(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPreview(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *data)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *m_pNotify; // esi
  IDmNotify *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-10h] BYREF
  Color c; // [esp+10h] [ebp-8h] BYREF
  Color defaultColor; // [esp+14h] [ebp-4h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &c);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->Refresh(this);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    m_pNotify = this->m_pNotify;
    v6 = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, int, int, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "CAttributeColorPickerPanel::OnPreview",
      a3: 4,
      a4: 0x2000,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471D10
// Name: private: virtual void CAttributeColorPickerPanel::OnCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCancelled(CAttributeColorPickerPanel *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v3; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-8h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v3 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  this->Refresh(this);
  m_pNotify = this->m_pNotify;
  g_pDataModel->PushNotificationScope(
    this: g_pDataModel,
    a2: "CAttributeColorPickerPanel::OnCancelled",
    a3: 4,
    a4: 0x2000);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v3 = m_pNotify;
  CBaseAttributePanel::SetDirty(this, dirty: false);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v3 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v3);
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x00471DE0
// Name: private: virtual void CAttributeColorPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPicked(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *data)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v5; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  *(_DWORD *)&guard.m_bOldValue = 0;
  KeyValues::GetColor(
    this: data,
    result: (Color *)&data,
    keyName: "color",
    defaultColor: (const Color *)&guard.m_bOldValue);
  if ( data == (KeyValues *)this->m_InitialColor )
    goto LABEL_9;
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v5 = nullptr;
  *(_WORD *)&guard.m_bReleased = 0;
  guard.m_pNotify = nullptr;
  guard.m_bOldValue = ((int (__thiscall *)(IDataModel *, int))IsUndoEnabled)(a1: g_pDataModel, a2);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  CChangeUndoScopeGuard::Release(this: &guard);
  m_pNotify = this->m_pNotify;
  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v5 = m_pNotify;
  ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
    a1: g_pDataModel,
    a2: "Set Attribute Value",
    a3: 4);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: (const Color *)&data);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v5 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v5);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    this->Refresh(this);
LABEL_9:
    CBaseAttributePanel::SetDirty(this, dirty: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471F30
// Name: public: CAttributeColorPickerPanel::CAttributeColorPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeColorPickerPanel::CAttributeColorPickerPanel(
        CAttributeColorPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeColorPickerPanel_vtbl *)&CAttributeColorPickerPanel::`vftable';
  if ( `CAttributeColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v4->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
    v5->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
    v6->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(a1: (int)&savedregs);
  this->m_InitialColor = 0;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: defaultValue,
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00472050
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeColorPickerPanel::GetMessageMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472080
// Name: public: virtual struct PanelAnimationMap __near * CAttributeColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeColorPickerPanel::GetAnimMap(CAttributeColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00472090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeColorPickerPanel::GetKBMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10494C00
// Name: public: static char const __near * CAttributeColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeColorPickerPanel::GetPanelClassName()
{
  return "CAttributeColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10494C10
// Name: public: virtual void CAttributeColorPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::PerformLayout(CAttributeColorPickerPanel *this)
{
  int pickerX; // [esp+4h] [ebp-10h] BYREF
  int pickerY; // [esp+8h] [ebp-Ch] BYREF
  int pickerW; // [esp+Ch] [ebp-8h] BYREF
  int pickerH; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  this->GetPickerBounds(this, a2: &pickerX, a3: &pickerY, a4: &pickerW, a5: &pickerH);
  vgui::Panel::SetBounds(this: this->m_pOpen, x: pickerX, y: pickerY, wide: pickerW, tall: pickerH);
}

//------------------------------------------------------------------------------
// Address: 0x10494E40
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPreview";
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
// Address: 0x10494ED0
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPicked";
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
// Address: 0x10494F60
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ColorPickerCancel";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10494FF0
// Name: public: virtual void CAttributeColorPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCommand(CAttributeColorPickerPanel *this, const char *cmd)
{
  CColorPickerFrame *v3; // eax
  CColorPickerFrame *v4; // edi

  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
  {
    vgui::Panel::OnCommand(this, command: cmd);
  }
  else
  {
    this->m_InitialColor = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
    v3 = (CColorPickerFrame *)operator new(nSize: 0x224u);
    if ( v3 != nullptr )
      v4 = CColorPickerFrame::CColorPickerFrame(this: v3, pParent: this, pTitle: "Select Color");
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    CColorPickerFrame::DoModal(this: v4, initialColor: this->m_InitialColor, pContextKeys: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10495070
// Name: private: void CAttributeColorPickerPanel::UpdateButtonColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::UpdateButtonColor(CAttributeColorPickerPanel *this)
{
  Color v2; // esi
  Color clr; // [esp+8h] [ebp-4h]

  clr = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
  clr._color[3] = -1;
  v2 = clr;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDefaultColor)(a1: this->m_pOpen, a2: clr, a3: clr);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetArmedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDepressedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x104950E0
// Name: public: virtual void CAttributeColorPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::Refresh(CAttributeColorPickerPanel *this)
{
  CAttributeTextPanel::Refresh(this);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x104950F0
// Name: public: virtual void CAttributeColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::ApplySchemeSettings(
        CAttributeColorPickerPanel *this,
        vgui::IScheme *pScheme)
{
  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x10495110
// Name: private: virtual void CAttributeColorPickerPanel::OnPreview(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPreview(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *data)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *m_pNotify; // esi
  IDmNotify *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-10h] BYREF
  Color c; // [esp+10h] [ebp-8h] BYREF
  Color defaultColor; // [esp+14h] [ebp-4h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &c);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->Refresh(this);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    m_pNotify = this->m_pNotify;
    v6 = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, int, int, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "CAttributeColorPickerPanel::OnPreview",
      a3: 4,
      a4: 0x2000,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v6 = m_pNotify;
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v6 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v6);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10495210
// Name: private: virtual void CAttributeColorPickerPanel::OnCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCancelled(CAttributeColorPickerPanel *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v3; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-8h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v3 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  this->Refresh(this);
  m_pNotify = this->m_pNotify;
  g_pDataModel->PushNotificationScope(
    this: g_pDataModel,
    a2: "CAttributeColorPickerPanel::OnCancelled",
    a3: 4,
    a4: 0x2000);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v3 = m_pNotify;
  CBaseAttributePanel::SetDirty(this, dirty: false);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v3 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v3);
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x104952E0
// Name: private: virtual void CAttributeColorPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPicked(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *data)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  IDmNotify *v5; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  *(_DWORD *)&guard.m_bOldValue = 0;
  KeyValues::GetColor(
    this: data,
    result: (Color *)&data,
    keyName: "color",
    defaultColor: (const Color *)&guard.m_bOldValue);
  if ( data == (KeyValues *)this->m_InitialColor )
    goto LABEL_9;
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v5 = nullptr;
  *(_WORD *)&guard.m_bReleased = 0;
  guard.m_pNotify = nullptr;
  guard.m_bOldValue = ((int (__thiscall *)(IDataModel *, int))IsUndoEnabled)(a1: g_pDataModel, a2);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  CChangeUndoScopeGuard::Release(this: &guard);
  m_pNotify = this->m_pNotify;
  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v5 = m_pNotify;
  ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
    a1: g_pDataModel,
    a2: "Set Attribute Value",
    a3: 4);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: (const Color *)&data);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v5 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v5);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    this->Refresh(this);
LABEL_9:
    CBaseAttributePanel::SetDirty(this, dirty: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10495430
// Name: public: CAttributeColorPickerPanel::CAttributeColorPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeColorPickerPanel::CAttributeColorPickerPanel(
        CAttributeColorPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeColorPickerPanel_vtbl *)&CAttributeColorPickerPanel::`vftable';
  if ( `CAttributeColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v4->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
    v5->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
    v6->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(a1: (int)&savedregs);
  this->m_InitialColor = 0;
  v7 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: &var,
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10495550
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeColorPickerPanel::GetMessageMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495580
// Name: public: virtual struct PanelAnimationMap __near * CAttributeColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeColorPickerPanel::GetAnimMap(CAttributeColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10495590
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeColorPickerPanel::GetKBMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049B310
// Name: public: static char const __near * CAttributeColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeColorPickerPanel::GetPanelClassName()
{
  return "CAttributeColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049B320
// Name: public: virtual void CAttributeColorPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::PerformLayout(CAttributeColorPickerPanel *this)
{
  int pickerX; // [esp+4h] [ebp-10h] BYREF
  int pickerY; // [esp+8h] [ebp-Ch] BYREF
  int pickerW; // [esp+Ch] [ebp-8h] BYREF
  int pickerH; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  this->GetPickerBounds(this, a2: &pickerX, a3: &pickerY, a4: &pickerW, a5: &pickerH);
  vgui::Panel::SetBounds(this: this->m_pOpen, x: pickerX, y: pickerY, wide: pickerW, tall: pickerH);
}

//------------------------------------------------------------------------------
// Address: 0x0049B520
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPreview";
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
// Address: 0x0049B5B0
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPicked";
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
// Address: 0x0049B640
// Name: public: static void CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded )
  {
    `CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ColorPickerCancel";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B6D0
// Name: public: virtual void CAttributeColorPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCommand(CAttributeColorPickerPanel *this, const char *cmd)
{
  CColorPickerFrame *v3; // eax
  CColorPickerFrame *v4; // edi

  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
  {
    vgui::Panel::OnCommand(this, command: cmd);
  }
  else
  {
    this->m_InitialColor = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
    v3 = (CColorPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v3 != nullptr )
      v4 = CColorPickerFrame::CColorPickerFrame(this: v3, pParent: this, pTitle: "Select Color");
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    CColorPickerFrame::DoModal(this: v4, initialColor: this->m_InitialColor, pContextKeys: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B750
// Name: private: void CAttributeColorPickerPanel::UpdateButtonColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::UpdateButtonColor(CAttributeColorPickerPanel *this)
{
  Color v2; // esi
  Color clr; // [esp+8h] [ebp-4h]

  clr = CBaseAttributePanel::GetAttributeValue<Color>(this)->m_Storage;
  clr._color[3] = -1;
  v2 = clr;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDefaultColor)(a1: this->m_pOpen, a2: clr, a3: clr);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetArmedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pOpen->SetDepressedColor)(a1: this->m_pOpen, a2: v2, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0049B7C0
// Name: public: virtual void CAttributeColorPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::Refresh(CAttributeColorPickerPanel *this)
{
  CAttributeTextPanel::Refresh(this);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049B7D0
// Name: public: virtual void CAttributeColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::ApplySchemeSettings(
        CAttributeColorPickerPanel *this,
        vgui::IScheme *pScheme)
{
  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  CAttributeColorPickerPanel::UpdateButtonColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049B7F0
// Name: private: virtual void CAttributeColorPickerPanel::OnPreview(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPreview(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *data)
{
  unsigned __int8 (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  IDmNotify *m_pNotify; // esi
  IDmNotify *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-10h] BYREF
  Color c; // [esp+10h] [ebp-8h] BYREF
  Color defaultColor; // [esp+14h] [ebp-4h] BYREF

  v4 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v4)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &c);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->Refresh(this);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    m_pNotify = this->m_pNotify;
    v6 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 460))(
      a1: g_pDataModel.u,
      a2: "CAttributeColorPickerPanel::OnPreview",
      a3: 4,
      a4: 0x2000,
      a5: a2);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v6 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v6 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v6);
  }
  else
  {
    CBaseAttributePanel::SetDirty(this, dirty: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B8F0
// Name: private: virtual void CAttributeColorPickerPanel::OnCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeColorPickerPanel::OnCancelled(CAttributeColorPickerPanel *this)
{
  unsigned __int8 (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  IDmNotify *v3; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-8h] BYREF

  v2 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v3 = nullptr;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v2)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  this->Refresh(this);
  m_pNotify = this->m_pNotify;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CAttributeColorPickerPanel::OnCancelled",
    a3: 4,
    a4: 0x2000);
  if ( m_pNotify != nullptr
    && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 444))(
         a1: g_pDataModel.u,
         a2: m_pNotify) != 0 )
  {
    v3 = m_pNotify;
  }
  CBaseAttributePanel::SetDirty(this, dirty: false);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
  if ( v3 != nullptr )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
      a1: g_pDataModel.u,
      a2: v3);
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x0049B9C0
// Name: private: virtual void CAttributeColorPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeColorPickerPanel::OnPicked(
        CAttributeColorPickerPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *data)
{
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, int); // edx
  IDmNotify *v5; // ebx
  IDmNotify *m_pNotify; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  *(_DWORD *)&guard.m_bOldValue = 0;
  KeyValues::GetColor(
    this: data,
    result: (Color *)&data,
    keyName: "color",
    defaultColor: (const Color *)&guard.m_bOldValue);
  if ( data == (KeyValues *)this->m_InitialColor )
    goto LABEL_9;
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v5 = nullptr;
  *(_WORD *)&guard.m_bReleased = 0;
  guard.m_pNotify = nullptr;
  guard.m_bOldValue = ((int (__thiscall *)(_DWORD, _DWORD))v4)(
                        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                        a2);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: &this->m_InitialColor);
  CChangeUndoScopeGuard::Release(this: &guard);
  m_pNotify = this->m_pNotify;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 256))(
    a1: g_pDataModel.u,
    a2: "Set Attribute Value",
    a3: "Set Attribute Value",
    a4: 0);
  if ( m_pNotify != nullptr
    && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 444))(
         a1: g_pDataModel.u,
         a2: m_pNotify) != 0 )
  {
    v5 = m_pNotify;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 460))(
    a1: g_pDataModel.u,
    a2: "Set Attribute Value",
    a3: 4);
  CBaseAttributePanel::SetAttributeValue<Color>(this, value: (const Color *)&data);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
  if ( v5 != nullptr )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
      a1: g_pDataModel.u,
      a2: v5);
  if ( (this->m_nFlags & 0x10) != 0 )
  {
    this->Refresh(this);
LABEL_9:
    CBaseAttributePanel::SetDirty(this, dirty: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BB10
// Name: public: CAttributeColorPickerPanel::CAttributeColorPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeColorPickerPanel::CAttributeColorPickerPanel(
        CAttributeColorPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeColorPickerPanel_vtbl *)&CAttributeColorPickerPanel::`vftable';
  if ( `CAttributeColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
    v4->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
    v5->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
    v6->pfnClassName = CAttributeColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeColorPickerPanel::PanelMessageFunc_OnPreview::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAttributeColorPickerPanel::PanelMessageFunc_OnCancelled::InitVar(a1: (int)&savedregs);
  this->m_InitialColor = 0;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: defaultValue,
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049BC30
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeColorPickerPanel::GetMessageMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049BC60
// Name: public: virtual struct PanelAnimationMap __near * CAttributeColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeColorPickerPanel::GetAnimMap(CAttributeColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049BC70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeColorPickerPanel::GetKBMap(CAttributeColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeColorPickerPanel");
  `CAttributeColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
