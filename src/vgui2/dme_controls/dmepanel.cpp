// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmepanel.cpp
// Functions: 39
// ============================================================

#include "vgui2\dme_controls\dmepanel.h"

//------------------------------------------------------------------------------
// Address: 0x00468D30
// Name: public: static char const __near * CDmePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePanel::GetPanelClassName()
{
  return "CDmePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468D40
// Name: public: virtual void CDmePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::ApplySchemeSettings(CDmePanel *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->m_pEditorNames->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pEditorNames, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00468D80
// Name: public: virtual void CDmePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::PerformLayout(CDmePanel *this)
{
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  vgui::EditablePanel *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    vgui::Panel::SetBounds(this: this->m_pEditorNames, x: 1, y: 1, wide: w - 2, tall: 20);
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
      vgui::Panel::SetBounds(this: m_pDmeEditorPanel, x: 0, y: 24, wide: w, tall: h - 24);
  }
  else
  {
    v3 = this->m_pDmeEditorPanel;
    if ( v3 != nullptr )
      vgui::Panel::SetBounds(this: v3, x: 0, y: 0, wide: w, tall: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468E50
// Name: private: virtual void CDmePanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnOpenContextMenu(CDmePanel *this, KeyValues *params)
{
  KeyValues *Copy; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  Copy = KeyValues::MakeCopy(this: params);
  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: Copy,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468EA0
// Name: private: virtual void CDmePanel::OnCut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCut(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCut");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F00
// Name: private: virtual void CDmePanel::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCopy(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCopy");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F60
// Name: private: virtual void CDmePanel::OnPaste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPaste(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPaste");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468FC0
// Name: private: virtual void CDmePanel::OnPasteInsert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteInsert(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteInsert");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469020
// Name: private: virtual void CDmePanel::OnPasteReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteReference(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteReference");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469080
// Name: private: virtual void CDmePanel::OnEditDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnEditDelete(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnEditDelete");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004690E0
// Name: protected: CBaseDmePanelFactory::CBaseDmePanelFactory(char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__thiscall CBaseDmePanelFactory::CBaseDmePanelFactory(
        CBaseDmePanelFactory *this,
        const char *pElementType,
        const char *pEditorName,
        const char *pEditorDisplayName,
        bool bIsDefault,
        bool bIsOverride)
{
  CBaseDmePanelFactory *v7; // edi
  char v8; // cl
  CBaseDmePanelFactory *pPrevFactory; // [esp+Ch] [ebp-4h]

  this->__vftable = (CBaseDmePanelFactory_vtbl *)&CBaseDmePanelFactory::`vftable';
  v7 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  pPrevFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    goto LABEL_10;
  while ( _V_stricmp(s1: v7->m_pElementType, s2: pElementType) != 0
       || _V_stricmp(s1: v7->m_pEditorDisplayName, s2: pEditorDisplayName) != 0 )
  {
    pPrevFactory = v7;
    v7 = v7->m_pNext;
    if ( v7 == nullptr )
      goto LABEL_10;
  }
  if ( bIsOverride )
  {
    if ( pPrevFactory != nullptr )
      pPrevFactory->m_pNext = v7->m_pNext;
    else
      CBaseDmePanelFactory::s_pFirstDmePanelFactory = v7->m_pNext;
LABEL_10:
    this->m_pNext = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
    CBaseDmePanelFactory::s_pFirstDmePanelFactory = this;
    this->m_pElementType = pElementType;
    v8 = *((_BYTE *)this + 16);
    this->m_pEditorName = pEditorName;
    this->m_pEditorDisplayName = pEditorDisplayName;
    *((_BYTE *)this + 16) = bIsDefault | v8 & 0xFC | (2 * bIsOverride);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004691A0
// Name: struct DmeFactoryHandle_t__ __near * DmePanelFirstFactory(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__cdecl DmePanelFirstFactory(CDmElement *pElement)
{
  CBaseDmePanelFactory *v1; // esi
  int v3; // [esp+8h] [ebp-4h] BYREF

  v1 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return nullptr;
  while ( pElement != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v3, a3: v1->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v3) != 0 )
      break;
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00469200
// Name: struct DmeFactoryHandle_t__ __near * DmePanelNextFactory(struct DmeFactoryHandle_t__ __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
DmeFactoryHandle_t__ *__cdecl DmePanelNextFactory(DmeFactoryHandle_t__ *h, CDmElement *pElement)
{
  int v2; // esi
  CDmElement *v3; // edi

  if ( h == nullptr )
    return nullptr;
  v2 = *((_DWORD *)h + 5);
  if ( v2 == 0 )
    return nullptr;
  v3 = pElement;
  while ( v3 != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&h, a3: *(const char **)(v2 + 4));
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, DmeFactoryHandle_t__ *))v3->IsA)(a1: v3, a2: h) != 0 )
      break;
    v2 = *(_DWORD *)(v2 + 20);
    if ( v2 == 0 )
      return nullptr;
  }
  return (DmeFactoryHandle_t__ *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x00469260
// Name: private: static bool CDmePanel::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *,char const __near *,struct CDmePanel::EditorPanelMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmePanel::CreateDmePanel(
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement,
        const char *pEditorName,
        CDmePanel::EditorPanelMap_t *pMap)
{
  CBaseDmePanelFactory *v5; // esi
  int v6; // ebx
  CBaseDmePanelFactory *v7; // ecx
  int InheritanceDepth; // eax
  int v10; // [esp+Ch] [ebp-8h] BYREF
  CBaseDmePanelFactory *pBestFactory; // [esp+10h] [ebp-4h]

  v5 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  v6 = -1;
  pBestFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return 0;
  do
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v10, a3: v5->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v10) != 0 )
    {
      if ( pEditorName != nullptr )
      {
        if ( _V_stricmp(s1: pEditorName, s2: v5->m_pEditorName) == 0 )
        {
          v7 = v5;
          goto LABEL_6;
        }
      }
      else if ( (*((_BYTE *)v5 + 16) & 1) != 0 )
      {
        InheritanceDepth = CDmElement::GetInheritanceDepth(this: pElement, pTypeName: v5->m_pElementType);
        if ( v6 < 0 || InheritanceDepth <= v6 )
        {
          v6 = InheritanceDepth;
          pBestFactory = v5;
        }
      }
    }
    v5 = v5->m_pNext;
  }
  while ( v5 != nullptr );
  v7 = pBestFactory;
LABEL_6:
  if ( v7 == nullptr )
    return 0;
  pMap->m_pFactory = v7;
  pMap->m_pEditorPanel = (vgui::EditablePanel *)v7->CreateDmePanel(this: v7, a2: pParent, a3: pPanelName, a4: pElement);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004693F0
// Name: public: virtual bool CDmePanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePanel::IsDroppable(CDmePanel *this, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  bool result; // al
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  result = msglist->m_Size == 1
        && (Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1),
            v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
            v6 = v5,
            v5 != nullptr)
        && v5->IsA(this: v5, a2: CDmElement::m_classType)
        && v6 != g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004695B0
// Name: public: static void CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469640
// Name: public: static void CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004696D0
// Name: public: static void CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "NotifyViewedElementChanged";
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
// Address: 0x00469760
// Name: public: static void CDmePanel::PanelMessageFunc_OnCut::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCut::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCut";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004697F0
// Name: public: static void CDmePanel::PanelMessageFunc_OnCopy::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCopy::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCopy";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469880
// Name: public: static void CDmePanel::PanelMessageFunc_OnPaste::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPaste::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPaste";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469910
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteReference";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004699A0
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteInsert";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469A30
// Name: public: static void CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnEditDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469AC0
// Name: public: static void CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
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
// Address: 0x00469B50
// Name: public: class CUtlString __near & CUtlStringMap<class CUtlString>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CUtlStringMap<CUtlString>::operator[](CUtlStringMap<CUtlString> *this, const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x00469BF0
// Name: private: void CDmePanel::DeleteCachedPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::DeleteCachedPanels(CDmePanel *this)
{
  int m_NumElements; // edx
  int v2; // eax
  int v3; // edi
  int m_Size; // ebx
  int v5; // esi
  vgui::EditablePanel *m_pEditorPanel; // ecx
  CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > > *p_m_EditorPanelCache; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  CDmePanel *v10; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements;
  v2 = 0;
  v10 = this;
  nCount = m_NumElements;
  i = 0;
  if ( this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = (unsigned __int16)v2;
      m_Size = this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Size;
      v5 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          m_pEditorPanel = v10->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Memory.m_pMemory[v5].m_pEditorPanel;
          m_pEditorPanel->MarkForDeletion(this: m_pEditorPanel);
          ++v5;
        }
        while ( v5 < m_Size );
        m_NumElements = nCount;
        v2 = i;
      }
      this = v10;
      i = ++v2;
    }
    while ( v2 < m_NumElements );
  }
  p_m_EditorPanelCache = &this->m_EditorPanelCache;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_EditorPanelCache->m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x00469C80
// Name: public: void CDmePanel::SetEditor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::SetEditor(CDmePanel *this, const char *pEditorName)
{
  const char *v2; // ebx
  const char *v4; // eax
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *v6; // eax
  CBaseDmePanelFactory *m_Size; // ecx
  int v8; // ebx
  CDmElement *v9; // edi
  vgui::EditablePanel *v10; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // eax
  int v13; // ebx
  int v14; // ecx
  const char *m_pAsString; // eax
  CBaseDmePanelFactory *m_pFactory; // ecx
  int v17; // edx
  const char *v18; // [esp-4h] [ebp-24h]
  CDmePanel::EditorPanelMap_t pMap; // [esp+Ch] [ebp-14h] BYREF
  int v20; // [esp+14h] [ebp-Ch] BYREF
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *entries; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h] BYREF

  v2 = pEditorName;
  if ( pEditorName == nullptr
    || (v18 = pEditorName,
        v4 = CUtlString::operator char const *(this: &this->m_CurrentEditorName),
        _V_stricmp(s1: v4, s2: v18) != 0) )
  {
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
    {
      m_pDmeEditorPanel->SetParent_2(this: m_pDmeEditorPanel, a2: nullptr);
      this->m_pDmeEditorPanel = nullptr;
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    }
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle) != nullptr && v2 != nullptr )
    {
      if ( CUtlSymbolTable::Find(
             this: &this->m_EditorPanelCache.m_SymbolTable,
             result: (CUtlSymbol *)&i + 1,
             pString: v2)->m_Id != 0xFFFF )
      {
        v6 = CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
               this: &this->m_EditorPanelCache,
               pString: v2);
        m_Size = (CBaseDmePanelFactory *)v6->m_Size;
        entries = v6;
        pMap.m_pFactory = m_Size;
        i = 0;
        if ( (int)m_Size > 0 )
        {
          while ( 1 )
          {
            v8 = (int)&v6->m_Memory.m_pMemory[i];
            v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
            g_pDataModel->GetSymbol(
              this: g_pDataModel,
              result: (CUtlSymbolLarge *)&v20,
              a3: *(const char **)(*(_DWORD *)(v8 + 4) + 4));
            if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))v9->IsA)(a1: v9, a2: v20) != 0 )
              break;
            if ( ++i >= (int)pMap.m_pFactory )
              goto LABEL_15;
            v6 = entries;
          }
          v10 = *(vgui::EditablePanel **)v8;
          this->m_pDmeEditorPanel = *(vgui::EditablePanel **)v8;
          v10->SetParent_2(this: v10, a2: this);
          v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
          (*(void (__thiscall **)(_DWORD, vgui::EditablePanel *, CDmElement *))(**(_DWORD **)(v8 + 4) + 4))(
            a1: *(_DWORD *)(v8 + 4),
            a2: this->m_pDmeEditorPanel,
            a3: v11);
LABEL_15:
          v2 = pEditorName;
        }
      }
      if ( this->m_pDmeEditorPanel != nullptr )
        goto LABEL_23;
      v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
      if ( CDmePanel::CreateDmePanel(pParent: this, pPanelName: "DmePanelEditor", pElement: v12, pEditorName: v2, &pMap) != 0 )
      {
        CUtlSymbolTable::AddString(this: &this->m_EditorPanelCache.m_SymbolTable, result: (CUtlSymbol *)&i, pString: v2);
        v13 = (unsigned __int16)i;
        v14 = this->m_EditorPanelCache.m_Vector.m_Size;
        if ( v14 <= (unsigned __int16)i && v14 < (unsigned __int16)i + 1 )
          CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
            this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache,
            elem: v14,
            num: (unsigned __int16)i + 1 - v14);
        CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
          this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13],
          elem: this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13].m_Size,
          src: (const vgui::PropertySheet::Page_t *)&pMap);
        v2 = pEditorName;
        this->m_pDmeEditorPanel = pMap.m_pEditorPanel;
      }
      if ( this->m_pDmeEditorPanel != nullptr )
      {
LABEL_23:
        m_pAsString = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlSymbolTable::AddString(
          this: &this->m_LastUsedEditorType.m_SymbolTable,
          result: (CUtlSymbol *)&pEditorName,
          pString: m_pAsString);
        m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        v17 = this->m_LastUsedEditorType.m_Vector.m_Size;
        pMap.m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        if ( v17 <= (unsigned __int16)pEditorName && v17 < (unsigned __int16)pEditorName + 1 )
        {
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
            this: &this->m_LastUsedEditorType.m_Vector,
            elem: v17,
            num: (unsigned __int16)pEditorName + 1 - v17);
          m_pFactory = pMap.m_pFactory;
        }
        CUtlString::operator=(
          this: &this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory[(_DWORD)m_pFactory],
          src: v2);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: v2);
        this->m_pDmeEditorPanel->AddActionSignalTarget_2(this: this->m_pDmeEditorPanel, a2: this);
      }
      this->InvalidateLayout(this, a2: false, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469F20
// Name: private: virtual void CDmePanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnTextChanged(CDmePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  const char *String; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pEditorNames);
  if ( ActiveItemUserData != nullptr )
  {
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "editorName", defaultValue: nullptr);
    CDmePanel::SetEditor(this, pEditorName: String);
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469F70
// Name: public: CDmePanel::CDmePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmePanel *__thiscall CDmePanel::CDmePanel(
        CDmePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        bool bComboBoxVisible)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox_vtbl *v10; // edx
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  if ( `CDmePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v5->pfnClassName = CDmePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePanel");
    v6->pfnClassName = CDmePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
    v7->pfnClassName = CDmePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnCut::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnCopy::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPaste::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hElement.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_LastUsedEditorType.m_Vector.m_Size = 0;
  this->m_LastUsedEditorType.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_LastUsedEditorType.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_EditorPanelCache.m_Vector.m_Size = 0;
  this->m_EditorPanelCache.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_EditorPanelCache.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &this->m_CurrentEditorName);
  CUtlString::CUtlString(this: &this->m_DefaultEditorType);
  v8 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(
           this: v8,
           parent: this,
           panelName: "EditorDisplayNames",
           numLines: 6,
           allowEdit: false);
  else
    v9 = nullptr;
  this->m_pEditorNames = v9;
  v10 = v9->__vftable;
  if ( bComboBoxVisible )
    ((void (__stdcall *)(CDmePanel *))v10->AddActionSignalTarget_2)(a1: this);
  else
    ((void (__stdcall *)(_DWORD))v10->SetVisible)(a1: 0);
  this->m_pDmeEditorPanel = nullptr;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: DMELEMENT_HANDLE_INVALID);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046A150
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePanel::GetMessageMap(CDmePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetMessageMap'::`2'::s_pMap;
  `CDmePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
  `CDmePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A180
// Name: public: virtual struct PanelAnimationMap __near * CDmePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePanel::GetAnimMap(CDmePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046A190
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePanel::GetKBMap(CDmePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetKBMap'::`2'::s_pMap;
  `CDmePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
  `CDmePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A1C0
// Name: public: virtual CDmePanel::~CDmePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::~CDmePanel(CDmePanel *this)
{
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  CDmePanel::DeleteCachedPanels(this);
  this->m_DefaultEditorType.m_Storage.m_nActualLength = 0;
  if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory);
      this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_DefaultEditorType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CurrentEditorName.m_Storage.m_nActualLength = 0;
  if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory);
      this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_CurrentEditorName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_EditorPanelCache.m_SymbolTable);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_LastUsedEditorType.m_SymbolTable);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_LastUsedEditorType.m_Vector);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hElement, hElement: this->m_hElement.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046A290
// Name: private: void CDmePanel::PopulateEditorNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::PopulateEditorNames(
        CDmePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pPanelName)
{
  const char *v5; // eax
  int v6; // ebx
  const char *m_pAsString; // eax
  CUtlString *v8; // eax
  char *v9; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v11; // eax
  DmeFactoryHandle_t__ *Factory; // edi
  int v13; // ebx
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  int v16; // ebx
  const char *v17; // ebx
  CDmElement *v18; // eax
  int InheritanceDepth; // eax
  CDmElement *v20; // eax
  DmElementHandle_t m_handle; // [esp-8h] [ebp-24h]
  DmElementHandle_t v22; // [esp-8h] [ebp-24h]
  int nItemID; // [esp+4h] [ebp-18h]
  const char *pPreferredEditor; // [esp+8h] [ebp-14h]
  int nActiveItemID; // [esp+Ch] [ebp-10h]
  int nBestInheritanceDepth; // [esp+10h] [ebp-Ch]
  const char *pEditorName; // [esp+14h] [ebp-8h]
  CUtlSymbol result; // [esp+1Ah] [ebp-2h] BYREF

  vgui::ComboBox::RemoveAll(this: this->m_pEditorNames);
  this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: defaultValue);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle) != nullptr )
    {
      v5 = *(const char **)(((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                              a1: g_pDataModel,
                              a2: this->m_hElement.m_handle,
                              a3: a2)
                          + 52);
      v6 = -1;
      if ( v5 == (const char *)-1 )
        v5 = defaultValue;
      if ( CUtlSymbolTable::Find(this: &this->m_LastUsedEditorType.m_SymbolTable, &result, pString: v5)->m_Id == 0xFFFF )
      {
        v9 = (char *)CUtlString::operator char const *(this: &this->m_DefaultEditorType);
      }
      else
      {
        m_pAsString = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v8 = CUtlStringMap<CUtlString>::operator[](this: &this->m_LastUsedEditorType, pString: m_pAsString);
        v9 = CUtlString::Get(this: v8);
      }
      GetElement = g_pDataModel->GetElement;
      pPreferredEditor = v9;
      m_handle = this->m_hElement.m_handle;
      nBestInheritanceDepth = -1;
      nActiveItemID = -1;
      HIBYTE(result.m_Id) = 0;
      v11 = (CDmElement *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))GetElement)(
                            a1: g_pDataModel,
                            a2: m_handle,
                            a3);
      Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: v11);
      if ( Factory != nullptr )
      {
        do
        {
          v13 = *((_DWORD *)Factory + 3);
          pEditorName = *((const char **)Factory + 2);
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "entry", firstKey: "editorName", firstValue: pEditorName);
          else
            v15 = nullptr;
          v16 = ((int (__thiscall *)(vgui::ComboBox *, int, KeyValues *, DmElementHandle_t))this->m_pEditorNames->AddItem_2)(
                  a1: this->m_pEditorNames,
                  a2: v13,
                  a3: v15,
                  a4: v22);
          nItemID = v16;
          if ( pPanelName == nullptr || _V_stricmp(s1: pPanelName, s2: pEditorName) != 0 )
          {
            if ( pPreferredEditor == nullptr
              || HIBYTE(result.m_Id) != 0
              || _V_stricmp(s1: pPreferredEditor, s2: pEditorName) != 0 )
            {
              if ( ((_BYTE)Factory[4] & 1) != 0 )
              {
                v17 = *((const char **)Factory + 1);
                v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
                InheritanceDepth = CDmElement::GetInheritanceDepth(this: v18, pTypeName: v17);
                if ( nBestInheritanceDepth < 0 || InheritanceDepth < nBestInheritanceDepth )
                {
                  nBestInheritanceDepth = InheritanceDepth;
                  nActiveItemID = nItemID;
                }
              }
            }
            else
            {
              nBestInheritanceDepth = 0;
              nActiveItemID = v16;
            }
          }
          else
          {
            nBestInheritanceDepth = 0;
            nActiveItemID = v16;
            HIBYTE(result.m_Id) = 1;
          }
          v22 = this->m_hElement.m_handle;
          v20 = (CDmElement *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          Factory = DmePanelNextFactory(h: Factory, pElement: v20);
        }
        while ( Factory != nullptr );
        v6 = nActiveItemID;
      }
      if ( this->m_pEditorNames->GetItemCount(this: this->m_pEditorNames) != 0 )
      {
        if ( v6 < 0 )
          vgui::ComboBox::ActivateItemByRow(this: this->m_pEditorNames, row: 0);
        else
          this->m_pEditorNames->ActivateItem(this: this->m_pEditorNames, a2: v6);
      }
      else
      {
        this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: defaultValue);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
        this->OnTextChanged(this);
      }
    }
    else
    {
      this->OnTextChanged(this);
    }
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A550
// Name: public: void CDmePanel::SetDmeElement(class CDmElement __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::SetDmeElement(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CDmElement *pDmeElement,
        bool bForce,
        const char *pPanelName)
{
  int BufferType; // eax
  const char *v7; // eax
  DmElementHandle_t v8; // eax

  if ( pDmeElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
  else
    BufferType = -1;
  if ( this->m_hElement.m_handle != BufferType
    || bForce
    || pPanelName != nullptr
    && (v7 = CUtlString::Get(this: &this->m_CurrentEditorName), _V_stricmp(s1: pPanelName, s2: v7) != 0) )
  {
    if ( pDmeElement != nullptr )
      v8 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
    else
      v8 = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: v8);
    CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    CDmePanel::PopulateEditorNames(this, a2: (int)pPanelName, a3: a2, pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A600
// Name: public: virtual void CDmePanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::OnPanelDropped(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  DmElementHandle_t BufferType; // eax

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = (CExpressionCalculator *)v5;
    if ( v5 != nullptr
      && v5->IsA(this: v5, a2: CDmElement::m_classType)
      && v6 != (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)
      && this->m_hElement.m_handle != CCodecBuffer_Block::GetBufferType(this: v6) )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: BufferType);
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this, a2: (int)this, a3: a2, pPanelName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A6B0
// Name: private: virtual void CDmePanel::OnViewedElementChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnViewedElementChanged(CDmePanel *this, KeyValues *kv)
{
  CDmePanel *v2; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v6; // edi
  CDmeHandle<CDmElement,0> *p_m_hElement; // esi
  DmeFactoryHandle_t__ *Factory; // esi
  const char *v9; // eax
  int BufferType; // eax
  DmElementHandle_t v11; // eax
  int i; // edi
  int ItemIDFromRow; // esi
  KeyValues *ItemUserData; // eax
  const char *v15; // eax
  DmeFactoryHandle_t__ *j; // esi
  const char *v17; // edi
  const char *v18; // eax
  const char *v19; // ebx
  KeyValues *v20; // eax
  const KeyValues *v21; // eax
  DmElementHandle_t v22; // esi
  CDmElement *v23; // eax
  const char *v24; // [esp-4h] [ebp-18h]
  const char *String; // [esp-4h] [ebp-18h]
  CDmeElementRefHelper *v27; // [esp+10h] [ebp-4h]
  KeyValues *kva; // [esp+1Ch] [ebp+8h]

  v2 = this;
  Int = KeyValues::GetInt(this: kv, keyName: "dmeelement", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
  {
    v6 = v5;
    kva = (KeyValues *)v5;
  }
  else
  {
    kva = nullptr;
    v6 = nullptr;
  }
  p_m_hElement = &v2->m_hElement;
  v27 = &v2->m_hElement;
  if ( v6 == g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hElement.m_handle) )
    return;
  if ( CUtlString::Length(this: &v2->m_CurrentEditorName) == 0 )
  {
LABEL_12:
    if ( v6 != nullptr )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
      goto LABEL_15;
    }
LABEL_14:
    BufferType = -1;
LABEL_15:
    if ( p_m_hElement->m_handle != BufferType )
    {
      if ( v6 != nullptr )
        v11 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
      else
        v11 = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: p_m_hElement, h: v11);
      CUtlString::operator=(this: &v2->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this: v2, a2: (int)v2, a3: (int)v6, pPanelName: nullptr);
    }
    return;
  }
  if ( v6 == nullptr )
    goto LABEL_14;
  Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: v6);
  if ( Factory == nullptr )
  {
LABEL_11:
    p_m_hElement = &v2->m_hElement;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v24 = *((const char **)Factory + 2);
    v9 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v9, s2: v24) == 0 )
      break;
    Factory = DmePanelNextFactory(h: Factory, pElement: v6);
    if ( Factory == nullptr )
      goto LABEL_11;
  }
  for ( i = v2->m_pEditorNames->GetItemCount(this: v2->m_pEditorNames) - 1; i >= 0; --i )
  {
    ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: v2->m_pEditorNames, row: i);
    ItemUserData = vgui::ComboBox::GetItemUserData(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
    String = KeyValues::GetString(this: ItemUserData, keyName: "editorName", defaultValue: defaultValue);
    v15 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v15, s2: String) != 0 )
      vgui::ComboBox::DeleteItem(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
  }
  for ( j = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: (CDmElement *)kva);
        j != nullptr;
        j = DmePanelNextFactory(h: j, pElement: (CDmElement *)kva) )
  {
    v17 = *((const char **)j + 2);
    v18 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v17, s2: v18) != 0 )
    {
      v19 = *((const char **)j + 3);
      v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v20 != nullptr )
        v21 = KeyValues::KeyValues(this: v20, setName: "entry", firstKey: "editorName", firstValue: v17);
      else
        v21 = nullptr;
      this->m_pEditorNames->AddItem_2(this: this->m_pEditorNames, a2: v19, a3: v21);
      v2 = this;
    }
  }
  v22 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)kva);
  if ( v22 != *(_DWORD *)v27 )
  {
    CDmeElementRefHelper::Unref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
    *(_DWORD *)v27 = v22;
    if ( v22 != DMELEMENT_HANDLE_INVALID )
    {
      v23 = g_pDataModel->GetElement(this: g_pDataModel, a2: v22);
      if ( v23 != nullptr && !v23->IsA(this: v23, a2: CDmElement::m_classType) )
        *(_DWORD *)v27 = -1;
    }
    CDmeElementRefHelper::Ref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CB1E0
// Name: public: unsigned short CUtlStringMap<class CSheet __near *>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlStringMap<CSheet *>::AddString(CUtlStringMap<CSheet *> *this, const char *pString)
{
  unsigned __int16 result; // ax
  int m_Size; // edx
  int v5; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  result = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString )
  {
    v5 = (unsigned __int16)pString + 1;
    if ( m_Size < v5 )
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
        elem: m_Size,
        num: v5 - m_Size);
      return (unsigned __int16)pString;
    }
  }
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1021D950
// Name: public: unsigned short CUtlStringMap<class CSheet __near *>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlStringMap<CSheet *>::AddString(CUtlStringMap<CSheet *> *this, const char *pString)
{
  unsigned __int16 result; // ax
  int m_Size; // edx
  int v5; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  result = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString )
  {
    v5 = (unsigned __int16)pString + 1;
    if ( m_Size < v5 )
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
        elem: m_Size,
        num: v5 - m_Size);
      return (unsigned __int16)pString;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10463730
// Name: public: static char const __near * CDmePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePanel::GetPanelClassName()
{
  return "CDmePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10463740
// Name: public: virtual void CDmePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::ApplySchemeSettings(CDmePanel *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->m_pEditorNames->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pEditorNames, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10463780
// Name: public: virtual void CDmePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::PerformLayout(CDmePanel *this)
{
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  vgui::EditablePanel *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    vgui::Panel::SetBounds(this: this->m_pEditorNames, x: 1, y: 1, wide: w - 2, tall: 20);
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
      vgui::Panel::SetBounds(this: m_pDmeEditorPanel, x: 0, y: 24, wide: w, tall: h - 24);
  }
  else
  {
    v3 = this->m_pDmeEditorPanel;
    if ( v3 != nullptr )
      vgui::Panel::SetBounds(this: v3, x: 0, y: 0, wide: w, tall: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463810
// Name: private: virtual void CDmePanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnOpenContextMenu(CDmePanel *this, KeyValues *params)
{
  KeyValues *Copy; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  Copy = KeyValues::MakeCopy(this: params);
  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: Copy,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463860
// Name: private: virtual void CDmePanel::OnCut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCut(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCut");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104638C0
// Name: private: virtual void CDmePanel::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCopy(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCopy");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463920
// Name: private: virtual void CDmePanel::OnPaste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPaste(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPaste");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463980
// Name: private: virtual void CDmePanel::OnPasteInsert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteInsert(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteInsert");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104639E0
// Name: private: virtual void CDmePanel::OnPasteReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteReference(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteReference");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463A40
// Name: private: virtual void CDmePanel::OnEditDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnEditDelete(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnEditDelete");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463AA0
// Name: protected: CBaseDmePanelFactory::CBaseDmePanelFactory(char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__thiscall CBaseDmePanelFactory::CBaseDmePanelFactory(
        CBaseDmePanelFactory *this,
        const char *pElementType,
        const char *pEditorName,
        const char *pEditorDisplayName,
        bool bIsDefault,
        bool bIsOverride)
{
  CBaseDmePanelFactory *v7; // edi
  char v8; // cl
  CBaseDmePanelFactory *pPrevFactory; // [esp+Ch] [ebp-4h]

  this->__vftable = (CBaseDmePanelFactory_vtbl *)&CBaseDmePanelFactory::`vftable';
  v7 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  pPrevFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    goto LABEL_10;
  while ( _V_stricmp(s1: v7->m_pElementType, s2: pElementType) != 0
       || _V_stricmp(s1: v7->m_pEditorDisplayName, s2: pEditorDisplayName) != 0 )
  {
    pPrevFactory = v7;
    v7 = v7->m_pNext;
    if ( v7 == nullptr )
      goto LABEL_10;
  }
  if ( bIsOverride )
  {
    if ( pPrevFactory != nullptr )
      pPrevFactory->m_pNext = v7->m_pNext;
    else
      CBaseDmePanelFactory::s_pFirstDmePanelFactory = v7->m_pNext;
LABEL_10:
    this->m_pNext = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
    CBaseDmePanelFactory::s_pFirstDmePanelFactory = this;
    this->m_pElementType = pElementType;
    v8 = *((_BYTE *)this + 16);
    this->m_pEditorName = pEditorName;
    this->m_pEditorDisplayName = pEditorDisplayName;
    *((_BYTE *)this + 16) = bIsDefault | v8 & 0xFC | (2 * bIsOverride);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10463B60
// Name: struct DmeFactoryHandle_t__ __near * DmePanelFirstFactory(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__cdecl DmePanelFirstFactory(CDmElement *pElement)
{
  CBaseDmePanelFactory *v1; // esi
  int v3; // [esp+8h] [ebp-4h] BYREF

  v1 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return nullptr;
  while ( pElement != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v3, a3: v1->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v3) != 0 )
      break;
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10463BC0
// Name: struct DmeFactoryHandle_t__ __near * DmePanelNextFactory(struct DmeFactoryHandle_t__ __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
DmeFactoryHandle_t__ *__cdecl DmePanelNextFactory(DmeFactoryHandle_t__ *h, CDmElement *pElement)
{
  int v2; // esi
  CDmElement *v3; // edi

  if ( h == nullptr )
    return nullptr;
  v2 = *((_DWORD *)h + 5);
  if ( v2 == 0 )
    return nullptr;
  v3 = pElement;
  while ( v3 != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&h, a3: *(const char **)(v2 + 4));
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, DmeFactoryHandle_t__ *))v3->IsA)(a1: v3, a2: h) != 0 )
      break;
    v2 = *(_DWORD *)(v2 + 20);
    if ( v2 == 0 )
      return nullptr;
  }
  return (DmeFactoryHandle_t__ *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10463C20
// Name: private: static bool CDmePanel::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *,char const __near *,struct CDmePanel::EditorPanelMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmePanel::CreateDmePanel(
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement,
        const char *pEditorName,
        CDmePanel::EditorPanelMap_t *pMap)
{
  CBaseDmePanelFactory *v5; // esi
  int v6; // ebx
  CBaseDmePanelFactory *v7; // ecx
  int InheritanceDepth; // eax
  int v10; // [esp+Ch] [ebp-8h] BYREF
  CBaseDmePanelFactory *pBestFactory; // [esp+10h] [ebp-4h]

  v5 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  v6 = -1;
  pBestFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return 0;
  do
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v10, a3: v5->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v10) != 0 )
    {
      if ( pEditorName != nullptr )
      {
        if ( _V_stricmp(s1: pEditorName, s2: v5->m_pEditorName) == 0 )
        {
          v7 = v5;
          goto LABEL_6;
        }
      }
      else if ( (*((_BYTE *)v5 + 16) & 1) != 0 )
      {
        InheritanceDepth = CDmElement::GetInheritanceDepth(this: pElement, pTypeName: v5->m_pElementType);
        if ( v6 < 0 || InheritanceDepth <= v6 )
        {
          v6 = InheritanceDepth;
          pBestFactory = v5;
        }
      }
    }
    v5 = v5->m_pNext;
  }
  while ( v5 != nullptr );
  v7 = pBestFactory;
LABEL_6:
  if ( v7 == nullptr )
    return 0;
  pMap->m_pFactory = v7;
  pMap->m_pEditorPanel = (vgui::EditablePanel *)v7->CreateDmePanel(this: v7, a2: pParent, a3: pPanelName, a4: pElement);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10463E00
// Name: public: virtual bool CDmePanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePanel::IsDroppable(CDmePanel *this, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  bool result; // al
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  result = msglist->m_Size == 1
        && (Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1),
            v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
            v6 = v5,
            v5 != nullptr)
        && v5->IsA(this: v5, a2: CDmElement::m_classType)
        && v6 != g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10463F80
// Name: public: static void CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464010
// Name: public: static void CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104640A0
// Name: public: static void CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "NotifyViewedElementChanged";
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
// Address: 0x10464130
// Name: public: static void CDmePanel::PanelMessageFunc_OnCut::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCut::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCut";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104641C0
// Name: public: static void CDmePanel::PanelMessageFunc_OnCopy::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCopy::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCopy";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464250
// Name: public: static void CDmePanel::PanelMessageFunc_OnPaste::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPaste::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPaste";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104642E0
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteReference";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464370
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteInsert";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464400
// Name: public: static void CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnEditDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464490
// Name: public: static void CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
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
// Address: 0x10464520
// Name: public: class CUtlString __near & CUtlStringMap<class CUtlString>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CUtlStringMap<CUtlString>::operator[](CUtlStringMap<CUtlString> *this, const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x104645C0
// Name: private: void CDmePanel::DeleteCachedPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::DeleteCachedPanels(CDmePanel *this)
{
  int m_NumElements; // edx
  int v2; // eax
  int v3; // edi
  int m_Size; // ebx
  int v5; // esi
  vgui::EditablePanel *m_pEditorPanel; // ecx
  CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > > *p_m_EditorPanelCache; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  CDmePanel *v10; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements;
  v2 = 0;
  v10 = this;
  nCount = m_NumElements;
  i = 0;
  if ( this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = (unsigned __int16)v2;
      m_Size = this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Size;
      v5 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          m_pEditorPanel = v10->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Memory.m_pMemory[v5].m_pEditorPanel;
          m_pEditorPanel->MarkForDeletion(this: m_pEditorPanel);
          ++v5;
        }
        while ( v5 < m_Size );
        m_NumElements = nCount;
        v2 = i;
      }
      this = v10;
      i = ++v2;
    }
    while ( v2 < m_NumElements );
  }
  p_m_EditorPanelCache = &this->m_EditorPanelCache;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_EditorPanelCache->m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x10464650
// Name: public: void CDmePanel::SetEditor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::SetEditor(CDmePanel *this, const char *pEditorName)
{
  const char *v2; // ebx
  const char *v4; // eax
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *v6; // eax
  CBaseDmePanelFactory *m_Size; // ecx
  int v8; // ebx
  CDmElement *v9; // edi
  vgui::EditablePanel *v10; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // eax
  int v13; // ebx
  int v14; // ecx
  const char *m_pAsString; // eax
  CBaseDmePanelFactory *m_pFactory; // ecx
  int v17; // edx
  const char *v18; // [esp-4h] [ebp-24h]
  CDmePanel::EditorPanelMap_t pMap; // [esp+Ch] [ebp-14h] BYREF
  int v20; // [esp+14h] [ebp-Ch] BYREF
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *entries; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h] BYREF

  v2 = pEditorName;
  if ( pEditorName == nullptr
    || (v18 = pEditorName,
        v4 = CUtlString::operator char const *(this: &this->m_CurrentEditorName),
        _V_stricmp(s1: v4, s2: v18) != 0) )
  {
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
    {
      m_pDmeEditorPanel->SetParent_2(this: m_pDmeEditorPanel, a2: nullptr);
      this->m_pDmeEditorPanel = nullptr;
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    }
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle) != nullptr && v2 != nullptr )
    {
      if ( CUtlSymbolTable::Find(
             this: &this->m_EditorPanelCache.m_SymbolTable,
             result: (CUtlSymbol *)&i + 1,
             pString: v2)->m_Id != 0xFFFF )
      {
        v6 = CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
               this: &this->m_EditorPanelCache,
               pString: v2);
        m_Size = (CBaseDmePanelFactory *)v6->m_Size;
        entries = v6;
        pMap.m_pFactory = m_Size;
        i = 0;
        if ( (int)m_Size > 0 )
        {
          while ( 1 )
          {
            v8 = (int)&v6->m_Memory.m_pMemory[i];
            v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
            g_pDataModel->GetSymbol(
              this: g_pDataModel,
              result: (CUtlSymbolLarge *)&v20,
              a3: *(const char **)(*(_DWORD *)(v8 + 4) + 4));
            if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))v9->IsA)(a1: v9, a2: v20) != 0 )
              break;
            if ( ++i >= (int)pMap.m_pFactory )
              goto LABEL_15;
            v6 = entries;
          }
          v10 = *(vgui::EditablePanel **)v8;
          this->m_pDmeEditorPanel = *(vgui::EditablePanel **)v8;
          v10->SetParent_2(this: v10, a2: this);
          v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
          (*(void (__thiscall **)(_DWORD, vgui::EditablePanel *, CDmElement *))(**(_DWORD **)(v8 + 4) + 4))(
            a1: *(_DWORD *)(v8 + 4),
            a2: this->m_pDmeEditorPanel,
            a3: v11);
LABEL_15:
          v2 = pEditorName;
        }
      }
      if ( this->m_pDmeEditorPanel != nullptr )
        goto LABEL_23;
      v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
      if ( CDmePanel::CreateDmePanel(pParent: this, pPanelName: "DmePanelEditor", pElement: v12, pEditorName: v2, &pMap) != 0 )
      {
        CUtlSymbolTable::AddString(this: &this->m_EditorPanelCache.m_SymbolTable, result: (CUtlSymbol *)&i, pString: v2);
        v13 = (unsigned __int16)i;
        v14 = this->m_EditorPanelCache.m_Vector.m_Size;
        if ( v14 <= (unsigned __int16)i && v14 < (unsigned __int16)i + 1 )
          CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
            this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache,
            elem: v14,
            num: (unsigned __int16)i + 1 - v14);
        CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
          this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13],
          elem: this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13].m_Size,
          src: (const vgui::PropertySheet::Page_t *)&pMap);
        v2 = pEditorName;
        this->m_pDmeEditorPanel = pMap.m_pEditorPanel;
      }
      if ( this->m_pDmeEditorPanel != nullptr )
      {
LABEL_23:
        m_pAsString = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        CUtlSymbolTable::AddString(
          this: &this->m_LastUsedEditorType.m_SymbolTable,
          result: (CUtlSymbol *)&pEditorName,
          pString: m_pAsString);
        m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        v17 = this->m_LastUsedEditorType.m_Vector.m_Size;
        pMap.m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        if ( v17 <= (unsigned __int16)pEditorName && v17 < (unsigned __int16)pEditorName + 1 )
        {
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
            this: &this->m_LastUsedEditorType.m_Vector,
            elem: v17,
            num: (unsigned __int16)pEditorName + 1 - v17);
          m_pFactory = pMap.m_pFactory;
        }
        CUtlString::operator=(
          this: &this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory[(_DWORD)m_pFactory],
          src: v2);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: v2);
        this->m_pDmeEditorPanel->AddActionSignalTarget_2(this: this->m_pDmeEditorPanel, a2: this);
      }
      this->InvalidateLayout(this, a2: false, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104648F0
// Name: private: virtual void CDmePanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnTextChanged(CDmePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  const char *String; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pEditorNames);
  if ( ActiveItemUserData != nullptr )
  {
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "editorName", defaultValue: nullptr);
    CDmePanel::SetEditor(this, pEditorName: String);
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464930
// Name: public: CDmePanel::CDmePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmePanel *__thiscall CDmePanel::CDmePanel(
        CDmePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        bool bComboBoxVisible)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox_vtbl *v10; // edx
  int _10; // [esp+10h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  if ( `CDmePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v5->pfnClassName = CDmePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePanel");
    v6->pfnClassName = CDmePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
    v7->pfnClassName = CDmePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnCut::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnCopy::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnPaste::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(a1: (int)&_10);
  CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&_10);
  this->m_hElement.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_LastUsedEditorType.m_Vector.m_Size = 0;
  this->m_LastUsedEditorType.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_LastUsedEditorType.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_EditorPanelCache.m_Vector.m_Size = 0;
  this->m_EditorPanelCache.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_EditorPanelCache.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &this->m_CurrentEditorName);
  CUtlString::CUtlString(this: &this->m_DefaultEditorType);
  v8 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(
           this: v8,
           parent: this,
           panelName: "EditorDisplayNames",
           numLines: 6,
           allowEdit: false);
  else
    v9 = nullptr;
  this->m_pEditorNames = v9;
  v10 = v9->__vftable;
  if ( bComboBoxVisible )
    ((void (__stdcall *)(CDmePanel *))v10->AddActionSignalTarget_2)(a1: this);
  else
    ((void (__stdcall *)(_DWORD))v10->SetVisible)(a1: 0);
  this->m_pDmeEditorPanel = nullptr;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: DMELEMENT_HANDLE_INVALID);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10464B10
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePanel::GetMessageMap(CDmePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetMessageMap'::`2'::s_pMap;
  `CDmePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
  `CDmePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10464B40
// Name: public: virtual struct PanelAnimationMap __near * CDmePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePanel::GetAnimMap(CDmePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10464B50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePanel::GetKBMap(CDmePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetKBMap'::`2'::s_pMap;
  `CDmePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
  `CDmePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10464B80
// Name: public: virtual CDmePanel::~CDmePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::~CDmePanel(CDmePanel *this)
{
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  CDmePanel::DeleteCachedPanels(this);
  this->m_DefaultEditorType.m_Storage.m_nActualLength = 0;
  if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory);
      this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_DefaultEditorType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CurrentEditorName.m_Storage.m_nActualLength = 0;
  if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory);
      this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_CurrentEditorName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_EditorPanelCache.m_SymbolTable);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_LastUsedEditorType.m_SymbolTable);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_LastUsedEditorType.m_Vector);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hElement, hElement: this->m_hElement.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10464C50
// Name: private: void CDmePanel::PopulateEditorNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::PopulateEditorNames(
        CDmePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pPanelName)
{
  const char *v5; // eax
  int v6; // ebx
  const char *m_pAsString; // eax
  CUtlString *v8; // eax
  char *v9; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v11; // eax
  DmeFactoryHandle_t__ *Factory; // edi
  int v13; // ebx
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  int v16; // ebx
  const char *v17; // ebx
  CDmElement *v18; // eax
  int InheritanceDepth; // eax
  CDmElement *v20; // eax
  DmElementHandle_t m_handle; // [esp-8h] [ebp-24h]
  DmElementHandle_t v22; // [esp-8h] [ebp-24h]
  int nItemID; // [esp+4h] [ebp-18h]
  const char *pPreferredEditor; // [esp+8h] [ebp-14h]
  int nActiveItemID; // [esp+Ch] [ebp-10h]
  int nBestInheritanceDepth; // [esp+10h] [ebp-Ch]
  const char *pEditorName; // [esp+14h] [ebp-8h]
  CUtlSymbol result; // [esp+1Ah] [ebp-2h] BYREF

  vgui::ComboBox::RemoveAll(this: this->m_pEditorNames);
  this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: &var);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle) != nullptr )
    {
      v5 = *(const char **)(((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                              a1: g_pDataModel,
                              a2: this->m_hElement.m_handle,
                              a3: a2)
                          + 52);
      v6 = -1;
      if ( v5 == (const char *)-1 )
        v5 = &var;
      if ( CUtlSymbolTable::Find(this: &this->m_LastUsedEditorType.m_SymbolTable, &result, pString: v5)->m_Id == 0xFFFF )
      {
        v9 = (char *)CUtlString::operator char const *(this: &this->m_DefaultEditorType);
      }
      else
      {
        m_pAsString = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        v8 = CUtlStringMap<CUtlString>::operator[](this: &this->m_LastUsedEditorType, pString: m_pAsString);
        v9 = CUtlString::Get(this: v8);
      }
      GetElement = g_pDataModel->GetElement;
      pPreferredEditor = v9;
      m_handle = this->m_hElement.m_handle;
      nBestInheritanceDepth = -1;
      nActiveItemID = -1;
      HIBYTE(result.m_Id) = 0;
      v11 = (CDmElement *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))GetElement)(
                            a1: g_pDataModel,
                            a2: m_handle,
                            a3);
      Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: v11);
      if ( Factory != nullptr )
      {
        do
        {
          v13 = *((_DWORD *)Factory + 3);
          pEditorName = *((const char **)Factory + 2);
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "entry", firstKey: "editorName", firstValue: pEditorName);
          else
            v15 = nullptr;
          v16 = ((int (__thiscall *)(vgui::ComboBox *, int, KeyValues *, DmElementHandle_t))this->m_pEditorNames->AddItem_2)(
                  a1: this->m_pEditorNames,
                  a2: v13,
                  a3: v15,
                  a4: v22);
          nItemID = v16;
          if ( pPanelName == nullptr || _V_stricmp(s1: pPanelName, s2: pEditorName) != 0 )
          {
            if ( pPreferredEditor == nullptr
              || HIBYTE(result.m_Id) != 0
              || _V_stricmp(s1: pPreferredEditor, s2: pEditorName) != 0 )
            {
              if ( ((_BYTE)Factory[4] & 1) != 0 )
              {
                v17 = *((const char **)Factory + 1);
                v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle);
                InheritanceDepth = CDmElement::GetInheritanceDepth(this: v18, pTypeName: v17);
                if ( nBestInheritanceDepth < 0 || InheritanceDepth < nBestInheritanceDepth )
                {
                  nBestInheritanceDepth = InheritanceDepth;
                  nActiveItemID = nItemID;
                }
              }
            }
            else
            {
              nBestInheritanceDepth = 0;
              nActiveItemID = v16;
            }
          }
          else
          {
            nBestInheritanceDepth = 0;
            nActiveItemID = v16;
            HIBYTE(result.m_Id) = 1;
          }
          v22 = this->m_hElement.m_handle;
          v20 = (CDmElement *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          Factory = DmePanelNextFactory(h: Factory, pElement: v20);
        }
        while ( Factory != nullptr );
        v6 = nActiveItemID;
      }
      if ( this->m_pEditorNames->GetItemCount(this: this->m_pEditorNames) != 0 )
      {
        if ( v6 < 0 )
          vgui::ComboBox::ActivateItemByRow(this: this->m_pEditorNames, row: 0);
        else
          this->m_pEditorNames->ActivateItem(this: this->m_pEditorNames, a2: v6);
      }
      else
      {
        this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: &var);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
        this->OnTextChanged(this);
      }
    }
    else
    {
      this->OnTextChanged(this);
    }
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464F10
// Name: public: void CDmePanel::SetDmeElement(class CDmElement __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::SetDmeElement(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CDmElement *pDmeElement,
        bool bForce,
        const char *pPanelName)
{
  int BufferType; // eax
  const char *v7; // eax
  DmElementHandle_t v8; // eax

  if ( pDmeElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
  else
    BufferType = -1;
  if ( this->m_hElement.m_handle != BufferType
    || bForce
    || pPanelName != nullptr
    && (v7 = CUtlString::Get(this: &this->m_CurrentEditorName), _V_stricmp(s1: pPanelName, s2: v7) != 0) )
  {
    if ( pDmeElement != nullptr )
      v8 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
    else
      v8 = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: v8);
    CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    CDmePanel::PopulateEditorNames(this, a2: (int)pPanelName, a3: a2, pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10464FC0
// Name: public: virtual void CDmePanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::OnPanelDropped(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  DmElementHandle_t BufferType; // eax

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = (CExpressionCalculator *)v5;
    if ( v5 != nullptr
      && v5->IsA(this: v5, a2: CDmElement::m_classType)
      && v6 != (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hElement.m_handle)
      && this->m_hElement.m_handle != CCodecBuffer_Block::GetBufferType(this: v6) )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: BufferType);
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this, a2: (int)this, a3: a2, pPanelName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10465070
// Name: private: virtual void CDmePanel::OnViewedElementChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnViewedElementChanged(CDmePanel *this, KeyValues *kv)
{
  CDmePanel *v2; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v6; // edi
  CDmeHandle<CDmElement,0> *p_m_hElement; // esi
  DmeFactoryHandle_t__ *Factory; // esi
  const char *v9; // eax
  int BufferType; // eax
  DmElementHandle_t v11; // eax
  int i; // edi
  int ItemIDFromRow; // esi
  KeyValues *ItemUserData; // eax
  const char *v15; // eax
  DmeFactoryHandle_t__ *j; // esi
  const char *v17; // edi
  const char *v18; // eax
  const char *v19; // ebx
  KeyValues *v20; // eax
  const KeyValues *v21; // eax
  DmElementHandle_t v22; // esi
  CDmElement *v23; // eax
  const char *v24; // [esp-4h] [ebp-18h]
  const char *String; // [esp-4h] [ebp-18h]
  CDmeElementRefHelper *v27; // [esp+10h] [ebp-4h]
  KeyValues *kva; // [esp+1Ch] [ebp+8h]

  v2 = this;
  Int = KeyValues::GetInt(this: kv, keyName: "dmeelement", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
  {
    v6 = v5;
    kva = (KeyValues *)v5;
  }
  else
  {
    kva = nullptr;
    v6 = nullptr;
  }
  p_m_hElement = &v2->m_hElement;
  v27 = &v2->m_hElement;
  if ( v6 == g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hElement.m_handle) )
    return;
  if ( CUtlString::Length(this: &v2->m_CurrentEditorName) == 0 )
  {
LABEL_12:
    if ( v6 != nullptr )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
      goto LABEL_15;
    }
LABEL_14:
    BufferType = -1;
LABEL_15:
    if ( p_m_hElement->m_handle != BufferType )
    {
      if ( v6 != nullptr )
        v11 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
      else
        v11 = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: p_m_hElement, h: v11);
      CUtlString::operator=(this: &v2->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this: v2, a2: (int)v2, a3: (int)v6, pPanelName: nullptr);
    }
    return;
  }
  if ( v6 == nullptr )
    goto LABEL_14;
  Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: v6);
  if ( Factory == nullptr )
  {
LABEL_11:
    p_m_hElement = &v2->m_hElement;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v24 = *((const char **)Factory + 2);
    v9 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v9, s2: v24) == 0 )
      break;
    Factory = DmePanelNextFactory(h: Factory, pElement: v6);
    if ( Factory == nullptr )
      goto LABEL_11;
  }
  for ( i = v2->m_pEditorNames->GetItemCount(this: v2->m_pEditorNames) - 1; i >= 0; --i )
  {
    ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: v2->m_pEditorNames, row: i);
    ItemUserData = vgui::ComboBox::GetItemUserData(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
    String = KeyValues::GetString(this: ItemUserData, keyName: "editorName", defaultValue: &var);
    v15 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v15, s2: String) != 0 )
      vgui::ComboBox::DeleteItem(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
  }
  for ( j = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: (CDmElement *)kva);
        j != nullptr;
        j = DmePanelNextFactory(h: j, pElement: (CDmElement *)kva) )
  {
    v17 = *((const char **)j + 2);
    v18 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v17, s2: v18) != 0 )
    {
      v19 = *((const char **)j + 3);
      v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v20 != nullptr )
        v21 = KeyValues::KeyValues(this: v20, setName: "entry", firstKey: "editorName", firstValue: v17);
      else
        v21 = nullptr;
      this->m_pEditorNames->AddItem_2(this: this->m_pEditorNames, a2: v19, a3: v21);
      v2 = this;
    }
  }
  v22 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)kva);
  if ( v22 != *(_DWORD *)v27 )
  {
    CDmeElementRefHelper::Unref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
    *(_DWORD *)v27 = v22;
    if ( v22 != DMELEMENT_HANDLE_INVALID )
    {
      v23 = g_pDataModel->GetElement(this: g_pDataModel, a2: v22);
      if ( v23 != nullptr && !v23->IsA(this: v23, a2: CDmElement::m_classType) )
        *(_DWORD *)v27 = -1;
    }
    CDmeElementRefHelper::Ref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004806B0
// Name: public: static char const __near * CDmePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePanel::GetPanelClassName()
{
  return "CDmePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004806C0
// Name: public: virtual void CDmePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::ApplySchemeSettings(CDmePanel *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->m_pEditorNames->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pEditorNames, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00480700
// Name: public: virtual void CDmePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::PerformLayout(CDmePanel *this)
{
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  vgui::EditablePanel *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    vgui::Panel::SetBounds(this: this->m_pEditorNames, x: 1, y: 1, wide: w - 2, tall: 20);
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
      vgui::Panel::SetBounds(this: m_pDmeEditorPanel, x: 0, y: 24, wide: w, tall: h - 24);
  }
  else
  {
    v3 = this->m_pDmeEditorPanel;
    if ( v3 != nullptr )
      vgui::Panel::SetBounds(this: v3, x: 0, y: 0, wide: w, tall: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480790
// Name: private: virtual void CDmePanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnOpenContextMenu(CDmePanel *this, KeyValues *params)
{
  KeyValues *Copy; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  Copy = KeyValues::MakeCopy(this: params);
  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: Copy,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004807E0
// Name: private: virtual void CDmePanel::OnCut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCut(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCut");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480840
// Name: private: virtual void CDmePanel::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnCopy(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnCopy");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004808A0
// Name: private: virtual void CDmePanel::OnPaste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPaste(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPaste");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480900
// Name: private: virtual void CDmePanel::OnPasteInsert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteInsert(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteInsert");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480960
// Name: private: virtual void CDmePanel::OnPasteReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnPasteReference(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnPasteReference");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004809C0
// Name: private: virtual void CDmePanel::OnEditDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnEditDelete(CDmePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CDmePanel_vtbl *v4; // edi
  int v5; // eax

  if ( this->m_pDmeEditorPanel != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnEditDelete");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->m_pDmeEditorPanel->GetVPanel)(
           a1: this->m_pDmeEditorPanel,
           a2: v3,
           a3: 0);
    ((void (__thiscall *)(CDmePanel *, int))v4->PostMessage_2)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480A20
// Name: protected: CBaseDmePanelFactory::CBaseDmePanelFactory(char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__thiscall CBaseDmePanelFactory::CBaseDmePanelFactory(
        CBaseDmePanelFactory *this,
        const char *pElementType,
        const char *pEditorName,
        const char *pEditorDisplayName,
        bool bIsDefault,
        bool bIsOverride)
{
  CBaseDmePanelFactory *v7; // edi
  char v8; // cl
  CBaseDmePanelFactory *pPrevFactory; // [esp+Ch] [ebp-4h]

  this->__vftable = (CBaseDmePanelFactory_vtbl *)&CBaseDmePanelFactory::`vftable';
  v7 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  pPrevFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    goto LABEL_10;
  while ( _V_stricmp(s1: v7->m_pElementType, s2: pElementType) != 0
       || _V_stricmp(s1: v7->m_pEditorDisplayName, s2: pEditorDisplayName) != 0 )
  {
    pPrevFactory = v7;
    v7 = v7->m_pNext;
    if ( v7 == nullptr )
      goto LABEL_10;
  }
  if ( bIsOverride )
  {
    if ( pPrevFactory != nullptr )
      pPrevFactory->m_pNext = v7->m_pNext;
    else
      CBaseDmePanelFactory::s_pFirstDmePanelFactory = v7->m_pNext;
LABEL_10:
    this->m_pNext = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
    CBaseDmePanelFactory::s_pFirstDmePanelFactory = this;
    this->m_pElementType = pElementType;
    v8 = *((_BYTE *)this + 16);
    this->m_pEditorName = pEditorName;
    this->m_pEditorDisplayName = pEditorDisplayName;
    *((_BYTE *)this + 16) = bIsDefault | v8 & 0xFC | (2 * bIsOverride);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00480AE0
// Name: struct DmeFactoryHandle_t__ __near * DmePanelFirstFactory(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseDmePanelFactory *__cdecl DmePanelFirstFactory(CDmElement *pElement)
{
  CBaseDmePanelFactory *v1; // esi
  int v3; // [esp+8h] [ebp-4h] BYREF

  v1 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return nullptr;
  while ( pElement != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &v3,
      a3: v1->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v3) != 0 )
      break;
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00480B40
// Name: struct DmeFactoryHandle_t__ __near * DmePanelNextFactory(struct DmeFactoryHandle_t__ __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
DmeFactoryHandle_t__ *__cdecl DmePanelNextFactory(DmeFactoryHandle_t__ *h, CDmElement *pElement)
{
  int v2; // esi
  CDmElement *v3; // edi

  if ( h == nullptr )
    return nullptr;
  v2 = *((_DWORD *)h + 5);
  if ( v2 == 0 )
    return nullptr;
  v3 = pElement;
  while ( v3 != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmeFactoryHandle_t__ **, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &h,
      a3: *(_DWORD *)(v2 + 4));
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, DmeFactoryHandle_t__ *))v3->IsA)(a1: v3, a2: h) != 0 )
      break;
    v2 = *(_DWORD *)(v2 + 20);
    if ( v2 == 0 )
      return nullptr;
  }
  return (DmeFactoryHandle_t__ *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x00480BA0
// Name: private: static bool CDmePanel::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *,char const __near *,struct CDmePanel::EditorPanelMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmePanel::CreateDmePanel(
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement,
        const char *pEditorName,
        CDmePanel::EditorPanelMap_t *pMap)
{
  CBaseDmePanelFactory *v5; // esi
  int v6; // ebx
  CBaseDmePanelFactory *v7; // ecx
  int InheritanceDepth; // eax
  int v10; // [esp+Ch] [ebp-8h] BYREF
  CBaseDmePanelFactory *pBestFactory; // [esp+10h] [ebp-4h]

  v5 = CBaseDmePanelFactory::s_pFirstDmePanelFactory;
  v6 = -1;
  pBestFactory = nullptr;
  if ( CBaseDmePanelFactory::s_pFirstDmePanelFactory == nullptr )
    return 0;
  do
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &v10,
      a3: v5->m_pElementType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))pElement->IsA)(a1: pElement, a2: v10) != 0 )
    {
      if ( pEditorName != nullptr )
      {
        if ( _V_stricmp(s1: pEditorName, s2: v5->m_pEditorName) == 0 )
        {
          v7 = v5;
          goto LABEL_6;
        }
      }
      else if ( (*((_BYTE *)v5 + 16) & 1) != 0 )
      {
        InheritanceDepth = CDmElement::GetInheritanceDepth(this: pElement, pTypeName: v5->m_pElementType);
        if ( v6 < 0 || InheritanceDepth <= v6 )
        {
          v6 = InheritanceDepth;
          pBestFactory = v5;
        }
      }
    }
    v5 = v5->m_pNext;
  }
  while ( v5 != nullptr );
  v7 = pBestFactory;
LABEL_6:
  if ( v7 == nullptr )
    return 0;
  pMap->m_pFactory = v7;
  pMap->m_pEditorPanel = (vgui::EditablePanel *)v7->CreateDmePanel(this: v7, a2: pParent, a3: pPanelName, a4: pElement);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480C80
// Name: public: virtual bool CDmePanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePanel::IsDroppable(CDmePanel *this, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  bool result; // al
  int Int; // eax
  int v5; // eax
  int v6; // esi

  result = msglist->m_Size == 1
        && (Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1),
            v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: Int),
            v6 = v5,
            v5 != 0)
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0
        && v6 != (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: this->m_hElement.m_handle);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480D90
// Name: public: static void CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480E20
// Name: public: static void CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480EB0
// Name: public: static void CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "NotifyViewedElementChanged";
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
// Address: 0x00480F40
// Name: public: static void CDmePanel::PanelMessageFunc_OnCut::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCut::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCut::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCut";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480FD0
// Name: public: static void CDmePanel::PanelMessageFunc_OnCopy::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnCopy::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnCopy::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCopy";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481060
// Name: public: static void CDmePanel::PanelMessageFunc_OnPaste::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPaste::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPaste::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPaste";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004810F0
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteReference::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteReference";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481180
// Name: public: static void CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPasteInsert";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481210
// Name: public: static void CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnEditDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnEditDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004812A0
// Name: public: static void CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
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
// Address: 0x00481330
// Name: public: class CUtlString __near & CUtlStringMap<class CUtlString>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CUtlStringMap<CUtlString>::operator[](CUtlStringMap<CUtlString> *this, const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x00481380
// Name: private: void CDmePanel::DeleteCachedPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::DeleteCachedPanels(CDmePanel *this)
{
  int m_NumElements; // edx
  int v2; // eax
  int v3; // edi
  int m_Size; // ebx
  int v5; // esi
  vgui::EditablePanel *m_pEditorPanel; // ecx
  CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > > *p_m_EditorPanelCache; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  CDmePanel *v10; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements;
  v2 = 0;
  v10 = this;
  nCount = m_NumElements;
  i = 0;
  if ( this->m_EditorPanelCache.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = (unsigned __int16)v2;
      m_Size = this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Size;
      v5 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          m_pEditorPanel = v10->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v3].m_Memory.m_pMemory[v5].m_pEditorPanel;
          m_pEditorPanel->MarkForDeletion(this: m_pEditorPanel);
          ++v5;
        }
        while ( v5 < m_Size );
        m_NumElements = nCount;
        v2 = i;
      }
      this = v10;
      i = ++v2;
    }
    while ( v2 < m_NumElements );
  }
  p_m_EditorPanelCache = &this->m_EditorPanelCache;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_EditorPanelCache->m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x00481410
// Name: public: void CDmePanel::SetEditor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::SetEditor(CDmePanel *this, const char *pEditorName)
{
  const char *v2; // ebx
  const char *v4; // eax
  vgui::EditablePanel *m_pDmeEditorPanel; // ecx
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *v6; // eax
  CBaseDmePanelFactory *m_Size; // ecx
  int v8; // ebx
  int v9; // edi
  vgui::EditablePanel *v10; // ecx
  int v11; // eax
  CDmElement *v12; // eax
  int v13; // ebx
  int v14; // ecx
  const char *v15; // eax
  CBaseDmePanelFactory *m_pFactory; // ecx
  int v17; // edx
  const char *v18; // [esp-4h] [ebp-24h]
  CDmePanel::EditorPanelMap_t pMap; // [esp+Ch] [ebp-14h] BYREF
  int v20; // [esp+14h] [ebp-Ch] BYREF
  CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *entries; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h] BYREF

  v2 = pEditorName;
  if ( pEditorName == nullptr
    || (v18 = pEditorName,
        v4 = CUtlString::operator char const *(this: &this->m_CurrentEditorName),
        _V_stricmp(s1: v4, s2: v18) != 0) )
  {
    m_pDmeEditorPanel = this->m_pDmeEditorPanel;
    if ( m_pDmeEditorPanel != nullptr )
    {
      m_pDmeEditorPanel->SetParent_2(this: m_pDmeEditorPanel, a2: nullptr);
      this->m_pDmeEditorPanel = nullptr;
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    }
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hElement.m_handle) != 0
      && v2 != nullptr )
    {
      if ( CUtlSymbolTable::Find(
             this: &this->m_EditorPanelCache.m_SymbolTable,
             result: (CUtlSymbol *)&i + 1,
             pString: v2)->m_Id != 0xFFFF )
      {
        v6 = (CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *)CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](this: (CFaceSetData *)&this->m_EditorPanelCache, pFaceSetName: v2);
        m_Size = (CBaseDmePanelFactory *)v6->m_Size;
        entries = v6;
        pMap.m_pFactory = m_Size;
        i = 0;
        if ( (int)m_Size > 0 )
        {
          while ( 1 )
          {
            v8 = (int)&v6->m_Memory.m_pMemory[i];
            v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: this->m_hElement.m_handle);
            (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 200))(
              a1: g_pDataModel.u,
              a2: &v20,
              a3: *(_DWORD *)(*(_DWORD *)(v8 + 4) + 4));
            if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v20) != 0 )
              break;
            if ( ++i >= (int)pMap.m_pFactory )
              goto LABEL_15;
            v6 = entries;
          }
          v10 = *(vgui::EditablePanel **)v8;
          this->m_pDmeEditorPanel = *(vgui::EditablePanel **)v8;
          v10->SetParent_2(this: v10, a2: this);
          v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: this->m_hElement.m_handle);
          (*(void (__thiscall **)(_DWORD, vgui::EditablePanel *, int))(**(_DWORD **)(v8 + 4) + 4))(
            a1: *(_DWORD *)(v8 + 4),
            a2: this->m_pDmeEditorPanel,
            a3: v11);
LABEL_15:
          v2 = pEditorName;
        }
      }
      if ( this->m_pDmeEditorPanel != nullptr )
        goto LABEL_23;
      v12 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_hElement.m_handle);
      if ( CDmePanel::CreateDmePanel(pParent: this, pPanelName: "DmePanelEditor", pElement: v12, pEditorName: v2, &pMap) != 0 )
      {
        CUtlSymbolTable::AddString(this: &this->m_EditorPanelCache.m_SymbolTable, result: (CUtlSymbol *)&i, pString: v2);
        v13 = (unsigned __int16)i;
        v14 = this->m_EditorPanelCache.m_Vector.m_Size;
        if ( v14 <= (unsigned __int16)i && v14 < (unsigned __int16)i + 1 )
          CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
            this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache,
            elem: v14,
            num: (unsigned __int16)i + 1 - v14);
        CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
          this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13],
          elem: this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory[v13].m_Size,
          src: (const vgui::PropertySheet::Page_t *)&pMap);
        v2 = pEditorName;
        this->m_pDmeEditorPanel = pMap.m_pEditorPanel;
      }
      if ( this->m_pDmeEditorPanel != nullptr )
      {
LABEL_23:
        v15 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                 a1: g_pDataModel.u,
                                 a2: this->m_hElement.m_handle)
                             + 52);
        if ( v15 == (const char *)-1 )
          v15 = defaultValue;
        CUtlSymbolTable::AddString(
          this: &this->m_LastUsedEditorType.m_SymbolTable,
          result: (CUtlSymbol *)&pEditorName,
          pString: v15);
        m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        v17 = this->m_LastUsedEditorType.m_Vector.m_Size;
        pMap.m_pFactory = (CBaseDmePanelFactory *)(unsigned __int16)pEditorName;
        if ( v17 <= (unsigned __int16)pEditorName && v17 < (unsigned __int16)pEditorName + 1 )
        {
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
            this: &this->m_LastUsedEditorType.m_Vector,
            elem: v17,
            num: (unsigned __int16)pEditorName + 1 - v17);
          m_pFactory = pMap.m_pFactory;
        }
        CUtlString::operator=(
          this: &this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory[(_DWORD)m_pFactory],
          src: v2);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: v2);
        this->m_pDmeEditorPanel->AddActionSignalTarget_2(this: this->m_pDmeEditorPanel, a2: this);
      }
      this->InvalidateLayout(this, a2: false, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004816B0
// Name: private: virtual void CDmePanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnTextChanged(CDmePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  const char *String; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pEditorNames);
  if ( ActiveItemUserData != nullptr )
  {
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "editorName", defaultValue: nullptr);
    CDmePanel::SetEditor(this, pEditorName: String);
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004816F0
// Name: public: CDmePanel::CDmePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmePanel *__thiscall CDmePanel::CDmePanel(
        CDmePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        bool bComboBoxVisible)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox_vtbl *v10; // edx
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  if ( `CDmePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
    v5->pfnClassName = CDmePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePanel");
    v6->pfnClassName = CDmePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
    v7->pfnClassName = CDmePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnViewedElementChanged::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnCut::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnCopy::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPaste::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPasteReference::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnPasteInsert::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnEditDelete::InitVar(a1: (int)&savedregs);
  CDmePanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hElement.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_LastUsedEditorType.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_LastUsedEditorType.m_Vector.m_Size = 0;
  this->m_LastUsedEditorType.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_LastUsedEditorType.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  this->m_EditorPanelCache.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_EditorPanelCache.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_EditorPanelCache.m_Vector.m_Size = 0;
  this->m_EditorPanelCache.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_EditorPanelCache.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &this->m_CurrentEditorName);
  CUtlString::CUtlString(this: &this->m_DefaultEditorType);
  v8 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(
           this: v8,
           parent: this,
           panelName: "EditorDisplayNames",
           numLines: 6,
           allowEdit: false);
  else
    v9 = nullptr;
  this->m_pEditorNames = v9;
  v10 = v9->__vftable;
  if ( bComboBoxVisible )
    ((void (__stdcall *)(CDmePanel *))v10->AddActionSignalTarget_2)(a1: this);
  else
    ((void (__stdcall *)(_DWORD))v10->SetVisible)(a1: 0);
  this->m_pDmeEditorPanel = nullptr;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: DMELEMENT_HANDLE_INVALID);
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004818D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePanel::GetMessageMap(CDmePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetMessageMap'::`2'::s_pMap;
  `CDmePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePanel");
  `CDmePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481900
// Name: public: virtual struct PanelAnimationMap __near * CDmePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePanel::GetAnimMap(CDmePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00481910
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePanel::GetKBMap(CDmePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePanel::GetKBMap'::`2'::s_pMap;
  `CDmePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePanel");
  `CDmePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481940
// Name: public: virtual CDmePanel::~CDmePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::~CDmePanel(CDmePanel *this)
{
  this->__vftable = (CDmePanel_vtbl *)&CDmePanel::`vftable';
  CDmePanel::DeleteCachedPanels(this);
  this->m_DefaultEditorType.m_Storage.m_nActualLength = 0;
  if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory);
      this->m_DefaultEditorType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_DefaultEditorType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CurrentEditorName.m_Storage.m_nActualLength = 0;
  if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory);
      this->m_CurrentEditorName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_CurrentEditorName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_EditorPanelCache.m_SymbolTable);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_EditorPanelCache);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_LastUsedEditorType.m_SymbolTable);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_LastUsedEditorType.m_Vector);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hElement, hElement: this->m_hElement.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00481A10
// Name: private: void CDmePanel::PopulateEditorNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::PopulateEditorNames(
        CDmePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pPanelName)
{
  const char *v5; // eax
  int v6; // ebx
  const char *v7; // eax
  CUtlString *v8; // eax
  char *v9; // eax
  int (__thiscall *v10)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int); // edx
  CDmElement *v11; // eax
  DmeFactoryHandle_t__ *Factory; // edi
  int v13; // ebx
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  int v16; // ebx
  const char *v17; // ebx
  CDmElement *v18; // eax
  int InheritanceDepth; // eax
  CDmElement *v20; // eax
  DmElementHandle_t m_handle; // [esp-8h] [ebp-24h]
  DmElementHandle_t v22; // [esp-8h] [ebp-24h]
  int nItemID; // [esp+4h] [ebp-18h]
  const char *pPreferredEditor; // [esp+8h] [ebp-14h]
  int nActiveItemID; // [esp+Ch] [ebp-10h]
  int nBestInheritanceDepth; // [esp+10h] [ebp-Ch]
  const char *pEditorName; // [esp+14h] [ebp-8h]
  CUtlSymbol result; // [esp+1Ah] [ebp-2h] BYREF

  vgui::ComboBox::RemoveAll(this: this->m_pEditorNames);
  this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: defaultValue);
  if ( this->m_pEditorNames->IsVisible(this: this->m_pEditorNames) )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hElement.m_handle) != 0 )
    {
      v5 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: this->m_hElement.m_handle,
                              a3: a2)
                          + 52);
      v6 = -1;
      if ( v5 == (const char *)-1 )
        v5 = defaultValue;
      if ( CUtlSymbolTable::Find(this: &this->m_LastUsedEditorType.m_SymbolTable, &result, pString: v5)->m_Id == 0xFFFF )
      {
        v9 = (char *)CUtlString::operator char const *(this: &this->m_DefaultEditorType);
      }
      else
      {
        v7 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                a1: g_pDataModel.u,
                                a2: this->m_hElement.m_handle)
                            + 52);
        if ( v7 == (const char *)-1 )
          v7 = defaultValue;
        v8 = CUtlStringMap<CUtlString>::operator[](this: &this->m_LastUsedEditorType, pString: v7);
        v9 = CUtlString::Get(this: v8);
      }
      v10 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72);
      pPreferredEditor = v9;
      m_handle = this->m_hElement.m_handle;
      nBestInheritanceDepth = -1;
      nActiveItemID = -1;
      HIBYTE(result.m_Id) = 0;
      v11 = (CDmElement *)((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v10)(
                            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                            a2: m_handle,
                            a3);
      Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: v11);
      if ( Factory != nullptr )
      {
        do
        {
          v13 = *((_DWORD *)Factory + 3);
          pEditorName = *((const char **)Factory + 2);
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "entry", firstKey: "editorName", firstValue: pEditorName);
          else
            v15 = nullptr;
          v16 = ((int (__thiscall *)(vgui::ComboBox *, int, KeyValues *, DmElementHandle_t))this->m_pEditorNames->AddItem_2)(
                  a1: this->m_pEditorNames,
                  a2: v13,
                  a3: v15,
                  a4: v22);
          nItemID = v16;
          if ( pPanelName == nullptr || _V_stricmp(s1: pPanelName, s2: pEditorName) != 0 )
          {
            if ( pPreferredEditor == nullptr
              || HIBYTE(result.m_Id) != 0
              || _V_stricmp(s1: pPreferredEditor, s2: pEditorName) != 0 )
            {
              if ( ((_BYTE)Factory[4] & 1) != 0 )
              {
                v17 = *((const char **)Factory + 1);
                v18 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                      a1: g_pDataModel.u,
                                      a2: this->m_hElement.m_handle);
                InheritanceDepth = CDmElement::GetInheritanceDepth(this: v18, pTypeName: v17);
                if ( nBestInheritanceDepth < 0 || InheritanceDepth < nBestInheritanceDepth )
                {
                  nBestInheritanceDepth = InheritanceDepth;
                  nActiveItemID = nItemID;
                }
              }
            }
            else
            {
              nBestInheritanceDepth = 0;
              nActiveItemID = v16;
            }
          }
          else
          {
            nBestInheritanceDepth = 0;
            nActiveItemID = v16;
            HIBYTE(result.m_Id) = 1;
          }
          v22 = this->m_hElement.m_handle;
          v20 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(a1: g_pDataModel.u);
          Factory = DmePanelNextFactory(h: Factory, pElement: v20);
        }
        while ( Factory != nullptr );
        v6 = nActiveItemID;
      }
      if ( this->m_pEditorNames->GetItemCount(this: this->m_pEditorNames) != 0 )
      {
        if ( v6 < 0 )
          vgui::ComboBox::ActivateItemByRow(this: this->m_pEditorNames, row: 0);
        else
          this->m_pEditorNames->ActivateItem(this: this->m_pEditorNames, a2: v6);
      }
      else
      {
        this->m_pEditorNames->SetText(this: this->m_pEditorNames, a2: defaultValue);
        CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
        this->OnTextChanged(this);
      }
    }
    else
    {
      this->OnTextChanged(this);
    }
  }
  else
  {
    CDmePanel::SetEditor(this, pEditorName: pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481CD0
// Name: public: void CDmePanel::SetDmeElement(class CDmElement __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::SetDmeElement(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CDmElement *pDmeElement,
        bool bForce,
        const char *pPanelName)
{
  int BufferType; // eax
  const char *v7; // eax
  DmElementHandle_t v8; // eax

  if ( pDmeElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
  else
    BufferType = -1;
  if ( this->m_hElement.m_handle != BufferType
    || bForce
    || pPanelName != nullptr
    && (v7 = CUtlString::Get(this: &this->m_CurrentEditorName), _V_stricmp(s1: pPanelName, s2: v7) != 0) )
  {
    if ( pDmeElement != nullptr )
      v8 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDmeElement);
    else
      v8 = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: v8);
    CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
    CDmePanel::PopulateEditorNames(this, a2: (int)pPanelName, a3: a2, pPanelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481D80
// Name: public: virtual void CDmePanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePanel::OnPanelDropped(
        CDmePanel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  int Int; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  DmElementHandle_t BufferType; // eax

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v6 = (CExpressionCalculator *)v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmElement::m_classType.u) != 0
      && v6 != (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: this->m_hElement.m_handle)
      && this->m_hElement.m_handle != CCodecBuffer_Block::GetBufferType(this: v6) )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hElement, h: BufferType);
      CUtlString::operator=(this: &this->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this, a2: (int)this, a3: a2, pPanelName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481E30
// Name: private: virtual void CDmePanel::OnViewedElementChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanel::OnViewedElementChanged(CDmePanel *this, KeyValues *kv)
{
  CDmePanel *v2; // ebx
  int Int; // eax
  int v4; // eax
  CExpressionCalculator *v5; // esi
  CExpressionCalculator *v6; // edi
  CDmeHandle<CDmElement,0> *p_m_hElement; // esi
  DmeFactoryHandle_t__ *Factory; // esi
  const char *v9; // eax
  int BufferType; // eax
  DmElementHandle_t v11; // eax
  int i; // edi
  int ItemIDFromRow; // esi
  KeyValues *ItemUserData; // eax
  const char *v15; // eax
  DmeFactoryHandle_t__ *j; // esi
  const char *v17; // edi
  const char *v18; // eax
  const char *v19; // ebx
  KeyValues *v20; // eax
  const KeyValues *v21; // eax
  int v22; // esi
  int v23; // eax
  const char *v24; // [esp-4h] [ebp-18h]
  const char *String; // [esp-4h] [ebp-18h]
  CDmeElementRefHelper *v27; // [esp+10h] [ebp-4h]
  KeyValues *kva; // [esp+1Ch] [ebp+8h]

  v2 = this;
  Int = KeyValues::GetInt(this: kv, keyName: "dmeelement", defaultValue: -1);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    v6 = v5;
    kva = (KeyValues *)v5;
  }
  else
  {
    kva = nullptr;
    v6 = nullptr;
  }
  p_m_hElement = &v2->m_hElement;
  v27 = &v2->m_hElement;
  if ( v6 == (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                        a1: g_pDataModel.u,
                                        a2: v2->m_hElement.m_handle) )
    return;
  if ( CUtlString::Length(this: &v2->m_CurrentEditorName) == 0 )
  {
LABEL_12:
    if ( v6 != nullptr )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
      goto LABEL_15;
    }
LABEL_14:
    BufferType = -1;
LABEL_15:
    if ( p_m_hElement->m_handle != BufferType )
    {
      if ( v6 != nullptr )
        v11 = CCodecBuffer_Block::GetBufferType(this: v6);
      else
        v11 = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: p_m_hElement, h: v11);
      CUtlString::operator=(this: &v2->m_CurrentEditorName, src: nullptr);
      CDmePanel::PopulateEditorNames(this: v2, a2: (int)v2, a3: (int)v6, pPanelName: nullptr);
    }
    return;
  }
  if ( v6 == nullptr )
    goto LABEL_14;
  Factory = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: (CDmElement *)v6);
  if ( Factory == nullptr )
  {
LABEL_11:
    p_m_hElement = &v2->m_hElement;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v24 = *((const char **)Factory + 2);
    v9 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v9, s2: v24) == 0 )
      break;
    Factory = DmePanelNextFactory(h: Factory, pElement: (CDmElement *)v6);
    if ( Factory == nullptr )
      goto LABEL_11;
  }
  for ( i = v2->m_pEditorNames->GetItemCount(this: v2->m_pEditorNames) - 1; i >= 0; --i )
  {
    ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: v2->m_pEditorNames, row: i);
    ItemUserData = vgui::ComboBox::GetItemUserData(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
    String = KeyValues::GetString(this: ItemUserData, keyName: "editorName", defaultValue: defaultValue);
    v15 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v15, s2: String) != 0 )
      vgui::ComboBox::DeleteItem(this: v2->m_pEditorNames, itemID: ItemIDFromRow);
  }
  for ( j = (DmeFactoryHandle_t__ *)DmePanelFirstFactory(pElement: (CDmElement *)kva);
        j != nullptr;
        j = DmePanelNextFactory(h: j, pElement: (CDmElement *)kva) )
  {
    v17 = *((const char **)j + 2);
    v18 = CUtlString::operator char const *(this: &v2->m_CurrentEditorName);
    if ( _V_stricmp(s1: v17, s2: v18) != 0 )
    {
      v19 = *((const char **)j + 3);
      v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v20 != nullptr )
        v21 = KeyValues::KeyValues(this: v20, setName: "entry", firstKey: "editorName", firstValue: v17);
      else
        v21 = nullptr;
      this->m_pEditorNames->AddItem_2(this: this->m_pEditorNames, a2: v19, a3: v21);
      v2 = this;
    }
  }
  v22 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)kva);
  if ( v22 != *(_DWORD *)v27 )
  {
    CDmeElementRefHelper::Unref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
    *(_DWORD *)v27 = v22;
    if ( v22 != -1 )
    {
      v23 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: v22);
      if ( v23 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v23 + 16))(
             a1: v23,
             a2: CDmElement::m_classType.u) == 0 )
      {
        *(_DWORD *)v27 = -1;
      }
    }
    CDmeElementRefHelper::Ref(this: v27, hElement: *(_DWORD *)v27, handleType: HT_WEAK);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F7040
// Name: public: unsigned short CUtlStringMap<class CSheet __near *>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlStringMap<CSheet *>::AddString(CUtlStringMap<CSheet *> *this, const char *pString)
{
  unsigned __int16 result; // ax
  int m_Size; // edx
  int v5; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  result = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString )
  {
    v5 = (unsigned __int16)pString + 1;
    if ( m_Size < v5 )
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
        elem: m_Size,
        num: v5 - m_Size);
      return (unsigned __int16)pString;
    }
  }
  return result;
}

} // namespace sceneviewer
