// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributefilepickerpanel.cpp
// Functions: 13
// ============================================================

#include "vgui2\dme_controls\attributefilepickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046B6D0
// Name: public: static char const __near * CAttributeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046B6E0
// Name: private: virtual void CAttributeDmeFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDmeFilePickerPanel::SetupFileOpenDialog(
        CAttributeDmeFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose DMX file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.dmx",
    filterName: "DMX (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046B730
// Name: private: virtual void CAttributeAviFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAviFilePickerPanel::SetupFileOpenDialog(
        CAttributeAviFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose AVI file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.avi",
    filterName: "AVI (*.avi)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046B780
// Name: private: virtual void CAttributeShtFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShtFilePickerPanel::SetupFileOpenDialog(
        CAttributeShtFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose Sheet file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.sht",
    filterName: "SHT (*.sht)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046B7D0
// Name: private: virtual void CAttributeRawFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeRawFilePickerPanel::SetupFileOpenDialog(
        CAttributeRawFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose RAW file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.raw",
    filterName: "RAW (*.raw)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046B820
// Name: private: virtual void CAttributeFilePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::ShowPickerDialog(CAttributeFilePickerPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  vgui::IInput *v4; // edi
  vgui::IInput_vtbl *v5; // ebx
  int v6; // eax

  v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Choose file",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  this->SetupFileOpenDialog(this, a2: v3);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
  v4 = g_pVGuiInput;
  v5 = g_pVGuiInput->__vftable;
  v6 = v3->GetVPanel(this: v3);
  v5->SetAppModalSurface(this: v4, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046B890
// Name: private: virtual void CAttributeFilePickerPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::OnFileSelected(CAttributeFilePickerPanel *this, const char *fullpath)
{
  char relativepath[512]; // [esp+4h] [ebp-200h] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFullFileSystem->FullPathToRelativePath(this: g_pFullFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    this->m_pData->SetText(this: this->m_pData, a2: relativepath);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B910
// Name: public: static void CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B9B0
// Name: public: virtual CAttributeFilePickerPanel::~CAttributeFilePickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::~CAttributeFilePickerPanel(CAttributeFilePickerPanel *this)
{
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046B9C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeFilePickerPanel::GetMessageMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046B9F0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeFilePickerPanel::GetAnimMap(CAttributeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046BA00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeFilePickerPanel::GetKBMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BA30
// Name: public: CAttributeFilePickerPanel::CAttributeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeFilePickerPanel *__thiscall CAttributeFilePickerPanel::CAttributeFilePickerPanel(
        CAttributeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  if ( `CAttributeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v4->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
    v5->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
    v6->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048EB70
// Name: public: static char const __near * CAttributeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1048EB80
// Name: private: virtual void CAttributeDmeFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDmeFilePickerPanel::SetupFileOpenDialog(
        CAttributeDmeFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose DMX file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.dmx",
    filterName: "DMX (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1048EBD0
// Name: private: virtual void CAttributeAviFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAviFilePickerPanel::SetupFileOpenDialog(
        CAttributeAviFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose AVI file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.avi",
    filterName: "AVI (*.avi)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1048EC20
// Name: private: virtual void CAttributeShtFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShtFilePickerPanel::SetupFileOpenDialog(
        CAttributeShtFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose Sheet file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.sht",
    filterName: "SHT (*.sht)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1048EC70
// Name: private: virtual void CAttributeRawFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeRawFilePickerPanel::SetupFileOpenDialog(
        CAttributeRawFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose RAW file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.raw",
    filterName: "RAW (*.raw)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1048ECC0
// Name: private: virtual void CAttributeFilePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::ShowPickerDialog(CAttributeFilePickerPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  vgui::IInput *v4; // edi
  vgui::IInput_vtbl *v5; // ebx
  int v6; // eax

  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Choose file",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  this->SetupFileOpenDialog(this, a2: v3);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
  v4 = g_pVGuiInput;
  v5 = g_pVGuiInput->__vftable;
  v6 = v3->GetVPanel(this: v3);
  v5->SetAppModalSurface(this: v4, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1048ED30
// Name: private: virtual void CAttributeFilePickerPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::OnFileSelected(CAttributeFilePickerPanel *this, const char *fullpath)
{
  char relativepath[512]; // [esp+4h] [ebp-200h] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFullFileSystem->FullPathToRelativePath(this: g_pFullFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    this->m_pData->SetText(this: this->m_pData, a2: relativepath);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048EDB0
// Name: public: static void CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048EE50
// Name: public: virtual CAttributeFilePickerPanel::~CAttributeFilePickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::~CAttributeFilePickerPanel(CAttributeFilePickerPanel *this)
{
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1048EE60
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeFilePickerPanel::GetMessageMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048EE90
// Name: public: virtual struct PanelAnimationMap __near * CAttributeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeFilePickerPanel::GetAnimMap(CAttributeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1048EEA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeFilePickerPanel::GetKBMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048EED0
// Name: public: CAttributeFilePickerPanel::CAttributeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeFilePickerPanel *__thiscall CAttributeFilePickerPanel::CAttributeFilePickerPanel(
        CAttributeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  if ( `CAttributeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v4->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
    v5->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
    v6->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00495250
// Name: public: static char const __near * CAttributeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00495260
// Name: private: virtual void CAttributeDmeFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDmeFilePickerPanel::SetupFileOpenDialog(
        CAttributeDmeFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose DMX file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.dmx",
    filterName: "DMX (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004952B0
// Name: private: virtual void CAttributeAviFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAviFilePickerPanel::SetupFileOpenDialog(
        CAttributeAviFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose AVI file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.avi",
    filterName: "AVI (*.avi)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00495300
// Name: private: virtual void CAttributeShtFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShtFilePickerPanel::SetupFileOpenDialog(
        CAttributeShtFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose Sheet file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.sht",
    filterName: "SHT (*.sht)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00495350
// Name: private: virtual void CAttributeRawFilePickerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeRawFilePickerPanel::SetupFileOpenDialog(
        CAttributeRawFilePickerPanel *this,
        vgui::FileOpenDialog *pDialog)
{
  pDialog->SetTitle_2(this: pDialog, a2: "Choose RAW file", a3: true);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.raw",
    filterName: "RAW (*.raw)",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004953A0
// Name: private: virtual void CAttributeFilePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::ShowPickerDialog(CAttributeFilePickerPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  vgui::IInput *v4; // edi
  vgui::IInput_vtbl *v5; // ebx
  int v6; // eax

  v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Choose file",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  this->SetupFileOpenDialog(this, a2: v3);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
  v4 = g_pVGuiInput;
  v5 = g_pVGuiInput->__vftable;
  v6 = v3->GetVPanel(this: v3);
  v5->SetAppModalSurface(this: v4, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00495410
// Name: private: virtual void CAttributeFilePickerPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::OnFileSelected(CAttributeFilePickerPanel *this, const char *fullpath)
{
  char relativepath[512]; // [esp+4h] [ebp-200h] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFullFileSystem->FullPathToRelativePath(this: g_pFullFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    this->m_pData->SetText(this: this->m_pData, a2: relativepath);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495490
// Name: public: static void CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495530
// Name: public: virtual CAttributeFilePickerPanel::~CAttributeFilePickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeFilePickerPanel::~CAttributeFilePickerPanel(CAttributeFilePickerPanel *this)
{
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00495540
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeFilePickerPanel::GetMessageMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495570
// Name: public: virtual struct PanelAnimationMap __near * CAttributeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeFilePickerPanel::GetAnimMap(CAttributeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00495580
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeFilePickerPanel::GetKBMap(CAttributeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  `CAttributeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004955B0
// Name: public: CAttributeFilePickerPanel::CAttributeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeFilePickerPanel *__thiscall CAttributeFilePickerPanel::CAttributeFilePickerPanel(
        CAttributeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeFilePickerPanel_vtbl *)&CAttributeFilePickerPanel::`vftable';
  if ( `CAttributeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
    v4->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
    v5->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
    v6->pfnClassName = CAttributeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeFilePickerPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
