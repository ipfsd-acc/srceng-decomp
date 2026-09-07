// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributesequencepickerpanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\dme_controls\attributesequencepickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00470250
// Name: public: static char const __near * CAttributeSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00470260
// Name: private: virtual void CAttributeSequencePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowPickerDialog(CAttributeSequencePickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi

  v2 = (CMDLPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004702B0
// Name: private: void CAttributeSequencePickerPanel::ShowSequencePickerDialog(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowSequencePickerDialog(
        CAttributeSequencePickerPanel *this,
        const char *pMDLName)
{
  int v3; // ebx
  const char *TextType; // eax
  const char *v5; // esi
  CSequencePickerFrame *v6; // eax
  CSequencePickerFrame *v7; // esi

  if ( pMDLName != nullptr && *pMDLName != 0 )
  {
    v3 = 3;
    TextType = CAttributeTextPanel::GetTextType(this);
    v5 = TextType;
    if ( TextType != nullptr )
    {
      if ( _V_stricmp(s1: TextType, s2: "activityName") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "sequenceName") == 0 )
          v3 = 1;
      }
      else
      {
        v3 = 2;
      }
    }
    v6 = (CSequencePickerFrame *)MemAlloc_Alloc(nSize: 0x220u);
    if ( v6 != nullptr )
      v7 = CSequencePickerFrame::CSequencePickerFrame(this: v6, pParent: this, nFlags: v3);
    else
      v7 = nullptr;
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    CSequencePickerFrame::DoModal(this: v7, pMDLName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470340
// Name: private: virtual void CAttributeSequencePickerPanel::OnSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnSequenceSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004703B0
// Name: private: virtual void CAttributeSequencePickerPanel::OnMDLSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnMDLSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", String);
  CAttributeSequencePickerPanel::ShowSequencePickerDialog(this, pMDLName: pRelativePath);
}

//------------------------------------------------------------------------------
// Address: 0x00470400
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x00470490
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequenceSelected";
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
// Address: 0x00470520
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSequencePickerPanel::GetMessageMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470550
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSequencePickerPanel::GetAnimMap(CAttributeSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00470560
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSequencePickerPanel::GetKBMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470590
// Name: public: CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(
        CAttributeSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSequencePickerPanel_vtbl *)&CAttributeSequencePickerPanel::`vftable';
  if ( `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    v4->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
    v5->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
    v6->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104936D0
// Name: public: static char const __near * CAttributeSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104936E0
// Name: private: virtual void CAttributeSequencePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowPickerDialog(CAttributeSequencePickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi

  v2 = (CMDLPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10493730
// Name: private: void CAttributeSequencePickerPanel::ShowSequencePickerDialog(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowSequencePickerDialog(
        CAttributeSequencePickerPanel *this,
        const char *pMDLName)
{
  int v3; // ebx
  const char *TextType; // eax
  const char *v5; // esi
  CSequencePickerFrame *v6; // eax
  CSequencePickerFrame *v7; // esi

  if ( pMDLName != nullptr && *pMDLName != 0 )
  {
    v3 = 3;
    TextType = CAttributeTextPanel::GetTextType(this);
    v5 = TextType;
    if ( TextType != nullptr )
    {
      if ( _V_stricmp(s1: TextType, s2: "activityName") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "sequenceName") == 0 )
          v3 = 1;
      }
      else
      {
        v3 = 2;
      }
    }
    v6 = (CSequencePickerFrame *)operator new(nSize: 0x220u);
    if ( v6 != nullptr )
      v7 = CSequencePickerFrame::CSequencePickerFrame(this: v6, pParent: this, nFlags: v3);
    else
      v7 = nullptr;
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    CSequencePickerFrame::DoModal(this: v7, pMDLName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104937C0
// Name: private: virtual void CAttributeSequencePickerPanel::OnSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnSequenceSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  char *String; // eax
  char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10493830
// Name: private: virtual void CAttributeSequencePickerPanel::OnMDLSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnMDLSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  char *String; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  V_snprintf(pDest: pRelativePath, maxLen: 0x104u, pFormat: "models\\%s", String);
  CAttributeSequencePickerPanel::ShowSequencePickerDialog(this, pMDLName: pRelativePath);
}

//------------------------------------------------------------------------------
// Address: 0x10493880
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x10493910
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequenceSelected";
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
// Address: 0x104939A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSequencePickerPanel::GetMessageMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104939D0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSequencePickerPanel::GetAnimMap(CAttributeSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104939E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSequencePickerPanel::GetKBMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10493A10
// Name: public: CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(
        CAttributeSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSequencePickerPanel_vtbl *)&CAttributeSequencePickerPanel::`vftable';
  if ( `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    v4->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
    v5->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
    v6->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00499E50
// Name: public: static char const __near * CAttributeSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00499E60
// Name: private: virtual void CAttributeSequencePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowPickerDialog(CAttributeSequencePickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi

  v2 = (CMDLPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00499EB0
// Name: private: void CAttributeSequencePickerPanel::ShowSequencePickerDialog(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::ShowSequencePickerDialog(
        CAttributeSequencePickerPanel *this,
        const char *pMDLName)
{
  int v3; // ebx
  const char *TextType; // eax
  const char *v5; // esi
  CSequencePickerFrame *v6; // eax
  CSequencePickerFrame *v7; // esi

  if ( pMDLName != nullptr && *pMDLName != 0 )
  {
    v3 = 3;
    TextType = CAttributeTextPanel::GetTextType(this);
    v5 = TextType;
    if ( TextType != nullptr )
    {
      if ( _V_stricmp(s1: TextType, s2: "activityName") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "sequenceName") == 0 )
          v3 = 1;
      }
      else
      {
        v3 = 2;
      }
    }
    v6 = (CSequencePickerFrame *)MemAlloc_Alloc(nSize: 0x220u);
    if ( v6 != nullptr )
      v7 = CSequencePickerFrame::CSequencePickerFrame(this: v6, pParent: this, nFlags: v3);
    else
      v7 = nullptr;
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    CSequencePickerFrame::DoModal(this: v7, pMDLName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499F40
// Name: private: virtual void CAttributeSequencePickerPanel::OnSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnSequenceSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499FB0
// Name: private: virtual void CAttributeSequencePickerPanel::OnMDLSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSequencePickerPanel::OnMDLSelected(
        CAttributeSequencePickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", String);
  CAttributeSequencePickerPanel::ShowSequencePickerDialog(this, pMDLName: pRelativePath);
}

//------------------------------------------------------------------------------
// Address: 0x0049A000
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x0049A090
// Name: public: static void CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequenceSelected";
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
// Address: 0x0049A120
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSequencePickerPanel::GetMessageMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A150
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSequencePickerPanel::GetAnimMap(CAttributeSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049A160
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSequencePickerPanel::GetKBMap(CAttributeSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
  `CAttributeSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A190
// Name: public: CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(
        CAttributeSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSequencePickerPanel_vtbl *)&CAttributeSequencePickerPanel::`vftable';
  if ( `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSequencePickerPanel");
    v4->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSequencePickerPanel");
    v5->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSequencePickerPanel");
    v6->pfnClassName = CAttributeSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSequencePickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  CAttributeSequencePickerPanel::PanelMessageFunc_OnSequenceSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
