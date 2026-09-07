// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributemdlpickerpanel.cpp
// Functions: 7
// ============================================================

#include "vgui2\dme_controls\attributemdlpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046FF60
// Name: public: static char const __near * CAttributeMDLPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeMDLPickerPanel::GetPanelClassName()
{
  return "CAttributeMDLPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046FF70
// Name: private: virtual void CAttributeMDLPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeMDLPickerPanel::ShowPickerDialog(CAttributeMDLPickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi
  char pszModelName[1024]; // [esp+8h] [ebp-400h] BYREF

  v2 = (CMDLPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  this->m_pData->GetText_2(this: this->m_pData, a2: pszModelName, a3: 1024);
  CBaseAssetPickerFrame::SetInitialSelection(this: v3, pAssetName: pszModelName);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470050
// Name: public: static void CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
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
// Address: 0x004700E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeMDLPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeMDLPickerPanel::GetMessageMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470110
// Name: public: virtual struct PanelAnimationMap __near * CAttributeMDLPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeMDLPickerPanel::GetAnimMap(CAttributeMDLPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00470120
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeMDLPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeMDLPickerPanel::GetKBMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470150
// Name: public: CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(
        CAttributeMDLPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeMDLPickerPanel_vtbl *)&CAttributeMDLPickerPanel::`vftable';
  if ( `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
    v4->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
    v5->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
    v6->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10493440
// Name: public: static char const __near * CAttributeMDLPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeMDLPickerPanel::GetPanelClassName()
{
  return "CAttributeMDLPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10493450
// Name: private: virtual void CAttributeMDLPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeMDLPickerPanel::ShowPickerDialog(CAttributeMDLPickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi
  char pszModelName[1024]; // [esp+8h] [ebp-400h] BYREF

  v2 = (CMDLPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  this->m_pData->GetText_2(this: this->m_pData, a2: pszModelName, a3: 1024);
  CBaseAssetPickerFrame::SetInitialSelection(this: v3, pAssetName: pszModelName);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104934D0
// Name: public: static void CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
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
// Address: 0x10493560
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeMDLPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeMDLPickerPanel::GetMessageMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10493590
// Name: public: virtual struct PanelAnimationMap __near * CAttributeMDLPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeMDLPickerPanel::GetAnimMap(CAttributeMDLPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104935A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeMDLPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeMDLPickerPanel::GetKBMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104935D0
// Name: public: CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(
        CAttributeMDLPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeMDLPickerPanel_vtbl *)&CAttributeMDLPickerPanel::`vftable';
  if ( `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
    v4->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
    v5->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
    v6->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00499B60
// Name: public: static char const __near * CAttributeMDLPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeMDLPickerPanel::GetPanelClassName()
{
  return "CAttributeMDLPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00499B70
// Name: private: virtual void CAttributeMDLPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeMDLPickerPanel::ShowPickerDialog(CAttributeMDLPickerPanel *this)
{
  CMDLPickerFrame *v2; // eax
  CMDLPickerFrame *v3; // esi
  char pszModelName[1024]; // [esp+8h] [ebp-400h] BYREF

  v2 = (CMDLPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMDLPickerFrame::CMDLPickerFrame(this: v2, pParent: this, pTitle: "Select .MDL File", nFlags: -1);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  this->m_pData->GetText_2(this: this->m_pData, a2: pszModelName, a3: 1024);
  CBaseAssetPickerFrame::SetInitialSelection(this: v3, pAssetName: pszModelName);
  CBaseAssetPickerFrame::DoModal(this: v3, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00499C50
// Name: public: static void CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
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
// Address: 0x00499CE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeMDLPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeMDLPickerPanel::GetMessageMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00499D10
// Name: public: virtual struct PanelAnimationMap __near * CAttributeMDLPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeMDLPickerPanel::GetAnimMap(CAttributeMDLPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00499D20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeMDLPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeMDLPickerPanel::GetKBMap(CAttributeMDLPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
  `CAttributeMDLPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00499D50
// Name: public: CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(
        CAttributeMDLPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeMDLPickerPanel_vtbl *)&CAttributeMDLPickerPanel::`vftable';
  if ( `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeMDLPickerPanel");
    v4->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeMDLPickerPanel");
    v5->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeMDLPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeMDLPickerPanel");
    v6->pfnClassName = CAttributeMDLPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeMDLPickerPanel::PanelMessageFunc_OnMDLSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
