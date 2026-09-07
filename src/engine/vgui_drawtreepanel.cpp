// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_drawtreepanel.cpp
// Functions: 27
// ============================================================

#include "engine\vgui_drawtreepanel.h"

//------------------------------------------------------------------------------
// Address: 0x1020B1C0
// Name: void ChangeCallback_RefreshDrawTree(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChangeCallback_RefreshDrawTree()
{
  g_bForceRefresh = true;
}

//------------------------------------------------------------------------------
// Address: 0x1020B1D0
// Name: void vgui_drawtree_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl vgui_drawtree_on_f()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&vgui_drawtree.IConVar, value: 1, a2: v0, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1020B1E0
// Name: void vgui_drawtree_off_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl vgui_drawtree_off_f()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&vgui_drawtree.IConVar, value: 0, a2: v0, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1020B1F0
// Name: public: virtual void CVGuiTree::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiTree::ApplySchemeSettings(CVGuiTree *this, vgui::IScheme *pScheme)
{
  CVGuiTree_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "ConsoleText", a3: false);
  v3->SetFont(this, a2: v4);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020B240
// Name: public: static char const __near * CDrawTreeFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDrawTreeFrame::GetPanelClassName()
{
  return "CDrawTreeFrame";
}

//------------------------------------------------------------------------------
// Address: 0x1020B250
// Name: void VGui_MoveDrawTreePanelToFront(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_MoveDrawTreePanelToFront()
{
  if ( g_pDrawTreeFrame != nullptr )
    g_pDrawTreeFrame->MoveToFront(this: g_pDrawTreeFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1020B270
// Name: void vgui_drawtree_clear_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_drawtree_clear_f()
{
  if ( g_pDrawTreeFrame != nullptr && g_pDrawTreeFrame->m_pTree != nullptr )
    g_pDrawTreeFrame->m_pTree->RemoveAll(this: g_pDrawTreeFrame->m_pTree);
}

//------------------------------------------------------------------------------
// Address: 0x1020B2A0
// Name: public: static char const __near * vgui::TreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TreeView::GetPanelClassName()
{
  return "TreeView";
}

//------------------------------------------------------------------------------
// Address: 0x1020B2B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TreeView::GetMessageMap(vgui::TreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetMessageMap'::`2'::s_pMap;
  `vgui::TreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  `vgui::TreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B2E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TreeView::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TreeView::GetAnimMap(vgui::TreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "TreeView");
}

//------------------------------------------------------------------------------
// Address: 0x1020B2F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TreeView::GetKBMap(vgui::TreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetKBMap'::`2'::s_pMap;
  `vgui::TreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  `vgui::TreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B320
// Name: bool UpdateItemState(class vgui::TreeView __near *,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UpdateItemState(KeyValues *pTree, int iChildItemId, KeyValues *pSub)
{
  KeyValues *v3; // esi
  int Int; // eax
  KeyValues *v5; // edi
  char *v6; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  char v10; // al
  void (__thiscall *v11)(KeyValues *, int, KeyValues **); // edx
  char *String; // [esp-4h] [ebp-24h]
  int iBaseColor_8; // [esp+14h] [ebp-Ch]
  vgui::IPanel *ipanel; // [esp+18h] [ebp-8h]
  bool bRet; // [esp+1Fh] [ebp-1h]

  v3 = pTree;
  ipanel = g_pVGuiPanel;
  bRet = false;
  pTree = (KeyValues *)(*(int (__thiscall **)(KeyValues *, int))(*(_DWORD *)pTree + 864))(a1: pTree, a2: iChildItemId);
  Int = KeyValues::GetInt(this: pTree, keyName: "PanelPtr", defaultValue: 0);
  v5 = pSub;
  if ( Int != KeyValues::GetInt(this: pSub, keyName: "PanelPtr", defaultValue: 0)
    || (String = KeyValues::GetString(this: v5, keyName: "Text", defaultValue: defaultValue),
        v6 = KeyValues::GetString(this: pTree, keyName: "Text", defaultValue: defaultValue),
        _V_stricmp(s1: v6, s2: String) != 0) )
  {
    (*(void (__thiscall **)(KeyValues *, int, KeyValues *))(*(_DWORD *)v3 + 876))(a1: v3, a2: iChildItemId, a3: v5);
    bRet = true;
  }
  v7 = KeyValues::GetInt(this: v5, keyName: "PanelPtr", defaultValue: 0);
  v8 = 255;
  iBaseColor_8 = 255;
  if ( ipanel->IsPopup(this: ipanel, a2: v7) )
    iBaseColor_8 = 0;
  v9 = 0;
  if ( g_FocusPanelList.m_Size > 0 )
  {
    while ( g_FocusPanelList.m_Memory.m_pMemory[v9] != v7 )
    {
      if ( ++v9 >= g_FocusPanelList.m_Size )
        goto LABEL_12;
    }
    if ( v9 != -1 )
    {
      v8 = 0;
      iBaseColor_8 = 0;
      (*(void (__thiscall **)(KeyValues *, int, int))(*(_DWORD *)v3 + 972))(a1: v3, a2: iChildItemId, a3: 1);
    }
  }
LABEL_12:
  if ( ipanel->IsVisible(this: ipanel, a2: v7) )
  {
    v10 = -1;
  }
  else
  {
    v8 >>= 1;
    iBaseColor_8 >>= 1;
    v10 = 127;
  }
  v11 = *(void (__thiscall **)(KeyValues *, int, KeyValues **))(*(_DWORD *)v3 + 944);
  BYTE1(pTree) = v10;
  BYTE2(pTree) = iBaseColor_8;
  LOBYTE(pTree) = v8;
  HIBYTE(pTree) = -1;
  v11(a1: v3, a2: iChildItemId, a3: &pTree);
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1020B480
// Name: public: void CDrawTreeFrame::RecalculateSelectedHighlight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawTreeFrame::RecalculateSelectedHighlight(CDrawTreeFrame *this)
{
  CVGuiTree *m_pTree; // ecx
  KeyValues *v3; // eax
  unsigned int Int; // [esp-4h] [ebp-20h]
  CUtlVector<int,CUtlMemory<int,int> > list; // [esp+8h] [ebp-14h] BYREF

  if ( vgui_drawtree_draw_selected.m_pParent != nullptr
    && vgui_drawtree_draw_selected.m_pParent->m_Value.m_nValue != 0
    && this->m_pTree->GetSelectedItemCount(this: this->m_pTree) == 1 )
  {
    m_pTree = this->m_pTree;
    memset(&list, 0, sizeof(list));
    m_pTree->GetSelectedItems(this: m_pTree, a2: &list);
    v3 = this->m_pTree->GetItemData(this: this->m_pTree, a2: *list.m_Memory.m_pMemory);
    Int = 0;
    if ( v3 != nullptr )
      Int = KeyValues::GetInt(this: v3, keyName: "PanelPtr", defaultValue: 0);
    vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: Int);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
  }
  else
  {
    vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B530
// Name: void VGui_RecursivePrintTree(unsigned int,class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_RecursivePrintTree(
        int a1@<edi>,
        int a2@<esi>,
        const void *current,
        KeyValues *pCurrentParent,
        int popupDepthCounter)
{
  vgui::IPanel *v5; // esi
  char *v6; // eax
  int m_nValue; // edi
  vgui::IPanel_vtbl *v8; // edx
  CFmtStrN<256> *v9; // eax
  int v10; // eax
  CFmtStrN<256> *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  int Int; // eax
  CFmtStrN<256> *v15; // eax
  unsigned int v16; // eax
  vgui::IScheme *v17; // eax
  vgui::IScheme *v18; // edi
  int v19; // eax
  const char *v20; // eax
  CFmtStrN<256> *v21; // eax
  const char *v22; // eax
  KeyValues *v23; // edi
  int v24; // edi
  unsigned int v25; // eax
  int v26; // [esp-18h] [ebp-148h]
  int v27; // [esp-14h] [ebp-144h]
  int v28; // [esp-10h] [ebp-140h]
  int v29; // [esp-Ch] [ebp-13Ch]
  const char *v30; // [esp-Ch] [ebp-13Ch]
  int v33; // [esp-4h] [ebp-134h]
  CFmtStrN<256> v34; // [esp+4h] [ebp-12Ch] BYREF
  int h; // [esp+110h] [ebp-20h] BYREF
  KeyValues *pVal; // [esp+114h] [ebp-1Ch]
  CUtlString name; // [esp+118h] [ebp-18h] BYREF
  int x; // [esp+128h] [ebp-8h]
  int w; // [esp+12Ch] [ebp-4h] BYREF

  if ( current != nullptr )
  {
    if ( (v5 = g_pVGuiPanel, vgui_drawtree_visible.m_pParent != nullptr)
      && vgui_drawtree_visible.m_pParent->m_Value.m_nValue != 0
      || !g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: (unsigned int)current) )
    {
      if ( (vgui_drawtree_hidden.m_pParent != nullptr && vgui_drawtree_hidden.m_pParent->m_Value.m_nValue != 0
         || v5->IsVisible(this: v5, a2: (unsigned int)current))
        && (popupDepthCounter > 0 || !v5->IsPopup(this: v5, a2: (unsigned int)current)) )
      {
        pVal = KeyValues::CreateNewKey(this: pCurrentParent);
        CUtlString::CUtlString(this: &name);
        v6 = (char *)((int (__thiscall *)(vgui::IPanel *, const void *, int))v5->GetName)(a1: v5, a2: current, a3: a2);
        if ( v6 == nullptr || *v6 == 0 )
          v6 = "(no name)";
        CUtlString::operator=(this: &name, src: v6);
        if ( v5->IsMouseInputEnabled(this: v5, a2: (unsigned int)current) )
          CUtlString::operator+=(this: &name, rhs: ", +m");
        if ( v5->IsKeyBoardInputEnabled(this: v5, a2: (unsigned int)current) )
          CUtlString::operator+=(this: &name, rhs: ", +k");
        if ( vgui_drawtree_bounds.m_pParent != nullptr )
        {
          m_nValue = vgui_drawtree_bounds.m_pParent->m_Value.m_nValue;
          if ( m_nValue > 0 )
          {
            CUtlString::operator+=(this: &name, rhs: ", ");
            ((void (__thiscall *)(vgui::IPanel *, const void *, int *, int *, int, int))v5->GetSize)(
              a1: v5,
              a2: current,
              a3: &w,
              a4: &h,
              a5: a1,
              a6: v33);
            v8 = v5->__vftable;
            if ( m_nValue == 1 )
            {
              ((void (__thiscall *)(vgui::IPanel *))v8->GetPos)(a1: v5);
              v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: "[%-4i %-4i %-4i %-4i]", x, current, w, h);
            }
            else
            {
              ((void (__thiscall *)(vgui::IPanel *, const void *))v8->GetAbsPos)(a1: v5, a2: current);
              v10 = ((int (__thiscall *)(vgui::IPanel *, const void *, int, const void *, int, int))v5->GetMessageContextId)(
                      a1: v5,
                      a2: current,
                      a3: x,
                      a4: current,
                      a5: w,
                      a6: h);
              v9 = CFmtStrN<256>::CFmtStrN<256>(
                     this: &v34,
                     pszFormat: "abs [%d][%-4i %-4i %-4i %-4i]",
                     v10,
                     v26,
                     v27,
                     v28,
                     v29);
            }
            CUtlString::operator+=(this: &name, rhs: v9->m_szBuf);
          }
        }
        if ( vgui_drawtree_panelptr.m_pParent != nullptr && vgui_drawtree_panelptr.m_pParent->m_Value.m_nValue != 0 )
        {
          v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " - [0x%p]", current);
          CUtlString::operator+=(this: &name, rhs: v11->m_szBuf);
        }
        if ( vgui_drawtree_panelalpha.m_pParent != nullptr && vgui_drawtree_panelalpha.m_pParent->m_Value.m_nValue != 0 )
        {
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v13 = KeyValues::KeyValues(this: v12, setName: "alpha");
          else
            v13 = nullptr;
          v5->RequestInfo(this: v5, a2: (unsigned int)current, a3: v13);
          Int = KeyValues::GetInt(this: v13, keyName: "alpha", defaultValue: 0);
          v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " - [%d]", Int);
          CUtlString::operator+=(this: &name, rhs: v15->m_szBuf);
          KeyValues::deleteThis(this: v13);
        }
        if ( vgui_drawtree_scheme.m_pParent != nullptr && vgui_drawtree_scheme.m_pParent->m_Value.m_nValue != 0 )
        {
          v16 = v5->GetScheme(this: v5, a2: (unsigned int)current);
          if ( v16 != 0 )
          {
            v17 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v16);
            v18 = v17;
            if ( v17 != nullptr )
            {
              v19 = (int)v17->GetFileName(this: v17);
              v20 = (const char *)((int (__thiscall *)(vgui::IScheme *, int))v18->GetName)(a1: v18, a2: v19);
              v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " [%s - %s]", v20, v30);
              CUtlString::operator+=(this: &name, rhs: v21->m_szBuf);
            }
          }
        }
        v22 = CUtlString::operator char const *(this: &name);
        v23 = pVal;
        KeyValues::SetString(this: pVal, keyName: "Text", value: v22);
        KeyValues::SetInt(this: v23, keyName: "PanelPtr", value: (int)current);
        if ( current == (const void *)g_pDrawTreeFrame->m_pTree->GetVPanel(this: g_pDrawTreeFrame->m_pTree) )
        {
          CUtlString::~CUtlString(this: &name);
        }
        else
        {
          v24 = 0;
          w = v5->GetChildCount(this: v5, a2: (unsigned int)current);
          if ( w > 0 )
          {
            do
            {
              v25 = v5->GetChild(this: v5, a2: (unsigned int)current, a3: v24);
              VGui_RecursivePrintTree(current: v25, pCurrentParent: pVal, popupDepthCounter: popupDepthCounter - 1);
              ++v24;
            }
            while ( v24 < w );
          }
          name.m_Storage.m_nActualLength = 0;
          if ( name.m_Storage.m_Memory.m_nGrowSize >= 0 && name.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: name.m_Storage.m_Memory.m_pMemory);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B910
// Name: void VGui_AddPopupsToKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_AddPopupsToKeyValues(unsigned int a1@<esi>, KeyValues *pCurrentParent)
{
  int v2; // ebx
  const void *v3; // edi
  int count; // [esp+4h] [ebp-4h]

  v2 = 0;
  count = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface);
  if ( count > 0 )
  {
    do
    {
      v3 = (const void *)g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v2);
      if ( vgui_drawtree_hidden.m_pParent != nullptr && vgui_drawtree_hidden.m_pParent->m_Value.m_nValue != 0
        || (a1 = (unsigned int)v3, v3 == nullptr) )
      {
LABEL_7:
        VGui_RecursivePrintTree(a1: (int)v3, a2: a1, current: v3, pCurrentParent, popupDepthCounter: 1);
      }
      else
      {
        while ( g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: a1) )
        {
          a1 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: a1);
          if ( a1 == 0 )
            goto LABEL_7;
        }
      }
      ++v2;
    }
    while ( v2 < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B9B0
// Name: void VGui_FillKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_FillKeyValues(int a1@<edi>, unsigned int a2@<esi>, KeyValues *pCurrentParent)
{
  CEngineVGui *v3; // eax
  const void *v4; // eax

  v3 = EngineVGui();
  if ( v3->IsInitialized(this: v3) )
  {
    v4 = (const void *)g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    if ( vgui_drawtree_popupsonly.m_pParent != nullptr && vgui_drawtree_popupsonly.m_pParent->m_Value.m_nValue != 0 )
    {
      VGui_AddPopupsToKeyValues(a1: a2, pCurrentParent);
    }
    else if ( vgui_drawtree_render_order.m_pParent != nullptr
           && vgui_drawtree_render_order.m_pParent->m_Value.m_nValue != 0 )
    {
      VGui_RecursivePrintTree(a1, a2: (int)pCurrentParent, current: v4, pCurrentParent, popupDepthCounter: 0);
      VGui_AddPopupsToKeyValues(a1: (unsigned int)pCurrentParent, pCurrentParent);
    }
    else
    {
      VGui_RecursivePrintTree(a1, a2, current: v4, pCurrentParent, popupDepthCounter: 99999);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BA30
// Name: void VGui_DrawHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_DrawHierarchy(int a1@<edi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi

  if ( vgui_drawtree.m_pParent != nullptr && vgui_drawtree.m_pParent->m_Value.m_nValue > 0 )
  {
    g_pDrawTreeFrame->SetVisible(this: g_pDrawTreeFrame, a2: true);
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: defaultValue);
    else
      v2 = nullptr;
    KeyValues::SetString(this: v2, keyName: "Text", value: "<shouldn't see this>");
    VGui_FillKeyValues(a1, a2: (unsigned int)v2, pCurrentParent: v2);
    IncrementalUpdateTree(pTree: g_pDrawTreeFrame->m_pTree, pValues: v2);
    KeyValues::deleteThis(this: v2);
  }
  else
  {
    g_pDrawTreeFrame->SetVisible(this: g_pDrawTreeFrame, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BAC0
// Name: void VGui_UpdateDrawTreePanel(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall VGui_UpdateDrawTreePanel(int a1@<edi>)
{
  VGui_DrawHierarchy(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1020BAD0
// Name: public: static void CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TreeViewItemSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BB60
// Name: public: CDrawTreeFrame::CDrawTreeFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDrawTreeFrame *__thiscall CDrawTreeFrame::CDrawTreeFrame(CDrawTreeFrame *this, vgui::Panel *parent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TreeView *v7; // eax
  CVGuiTree *v8; // edi
  CConVarCheckButton *v9; // eax
  CConVarCheckButton *v10; // edi
  CConVarCheckButton *v11; // eax
  CConVarCheckButton *v12; // edi
  CConVarCheckButton *v13; // eax
  CConVarCheckButton *v14; // edi
  CConVarCheckButton *v15; // eax
  CConVarCheckButton *v16; // edi
  CConVarCheckButton *v17; // eax
  CConVarCheckButton *v18; // edi
  CConVarCheckButton *v19; // eax
  CConVarCheckButton *v20; // edi
  CConVarCheckButton *v21; // eax
  CConVarCheckButton *v22; // edi
  CConVarCheckButton *v23; // eax
  CConVarCheckButton *v24; // edi
  CConVarCheckButton *v25; // eax
  CConVarCheckButton *v26; // edi
  CConVarCheckButton *v27; // eax
  CConVarCheckButton *v28; // edi
  CConVarCheckButton *v29; // eax
  CConVarCheckButton *v30; // edi
  Color *BgColor; // eax
  unsigned __int8 v32; // cl
  unsigned __int8 v33; // dl
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: pName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDrawTreeFrame_vtbl *)&CDrawTreeFrame::`vftable';
  if ( `CDrawTreeFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
    v4->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CDrawTreeFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDrawTreeFrame");
    v5->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CDrawTreeFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDrawTreeFrame");
    v6->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title: "VGUI Hierarchy", surfaceTitle: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  v7 = (vgui::TreeView *)MemAlloc_Alloc(nSize: 0x1BCu);
  v8 = (CVGuiTree *)v7;
  if ( v7 != nullptr )
  {
    vgui::TreeView::TreeView(this: v7, parent: this, panelName: "Tree view");
    v8->__vftable = (CVGuiTree_vtbl *)&CVGuiTree::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pTree = v8;
  v8->SetVisible(this: v8, a2: true);
  v9 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v9 != nullptr )
    v10 = CConVarCheckButton::CConVarCheckButton(
            this: v9,
            parent: this,
            panelName: "show visible",
            text: "Show Visible");
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pShowVisible = v10;
  v10->SetVisible(this: v10, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowVisible, pVar: &vgui_drawtree_visible);
  v11 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v11 != nullptr )
    v12 = CConVarCheckButton::CConVarCheckButton(this: v11, parent: this, panelName: "show hidden", text: "Show Hidden");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pShowHidden = v12;
  v12->SetVisible(this: v12, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowHidden, pVar: &vgui_drawtree_hidden);
  v13 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v13 != nullptr )
    v14 = CConVarCheckButton::CConVarCheckButton(this: v13, parent: this, panelName: "popups only", text: "Popups Only");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pPopupsOnly = v14;
  v14->SetVisible(this: v14, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pPopupsOnly, pVar: &vgui_drawtree_popupsonly);
  v15 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v15 != nullptr )
    v16 = CConVarCheckButton::CConVarCheckButton(
            this: v15,
            parent: this,
            panelName: "draw focus",
            text: "Highlight MouseOver");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pDrawFocus = v16;
  v16->SetVisible(this: v16, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pDrawFocus, pVar: &vgui_drawfocus);
  v17 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v17 != nullptr )
    v18 = CConVarCheckButton::CConVarCheckButton(this: v17, parent: this, panelName: "freeze option", text: "Freeze");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pFreeze = v18;
  v18->SetVisible(this: v18, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pFreeze, pVar: &vgui_drawtree_freeze);
  v19 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v19 != nullptr )
    v20 = CConVarCheckButton::CConVarCheckButton(
            this: v19,
            parent: this,
            panelName: "panel ptr option",
            text: "Show Addresses");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pShowPanelPtr = v20;
  v20->SetVisible(this: v20, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowPanelPtr, pVar: &vgui_drawtree_panelptr);
  v21 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v21 != nullptr )
    v22 = CConVarCheckButton::CConVarCheckButton(
            this: v21,
            parent: this,
            panelName: "panel alpha option",
            text: "Show Alpha");
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pShowPanelAlpha = v22;
  v22->SetVisible(this: v22, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowPanelAlpha, pVar: &vgui_drawtree_panelalpha);
  v23 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v23 != nullptr )
    v24 = CConVarCheckButton::CConVarCheckButton(
            this: v23,
            parent: this,
            panelName: "render order option",
            text: "In Render Order");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pRenderOrder = v24;
  v24->SetVisible(this: v24, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pRenderOrder, pVar: &vgui_drawtree_render_order);
  v25 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v25 != nullptr )
    v26 = CConVarCheckButton::CConVarCheckButton(
            this: v25,
            parent: this,
            panelName: "show panel bounds",
            text: "Show Panel Bounds");
  else
    v26 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v26);
  this->m_pShowBounds = v26;
  v26->SetVisible(this: v26, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowBounds, pVar: &vgui_drawtree_bounds);
  v27 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v27 != nullptr )
    v28 = CConVarCheckButton::CConVarCheckButton(
            this: v27,
            parent: this,
            panelName: "highlight selected",
            text: "Highlight Selected");
  else
    v28 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v28);
  this->m_pHighlightSelected = v28;
  v28->SetVisible(this: v28, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pHighlightSelected, pVar: &vgui_drawtree_draw_selected);
  v29 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v29 != nullptr )
    v30 = CConVarCheckButton::CConVarCheckButton(this: v29, parent: this, panelName: "show scheme", text: "Show Scheme");
  else
    v30 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v30);
  this->m_pShowScheme = v30;
  v30->SetVisible(this: v30, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowScheme, pVar: &vgui_drawtree_scheme);
  BgColor = vgui::Panel::GetBgColor(this, result: (Color *)&parent);
  v32 = BgColor->_color[1];
  LOBYTE(pName) = BgColor->_color[0];
  v33 = BgColor->_color[2];
  BYTE1(pName) = v32;
  BYTE2(pName) = v33;
  HIBYTE(pName) = 0x80;
  CBaseDemoAction::SetStartTick(this, color: (Color)pName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020C050
// Name: public: virtual void CDrawTreeFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawTreeFrame::PerformLayout(CDrawTreeFrame *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int Tall; // eax
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // eax
  int t; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int w; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &t);
  v2 = y;
  vgui::Panel::SetPos(this: this->m_pShowVisible, x, y);
  vgui::Panel::SetWide(this: this->m_pShowVisible, wide: w / 2);
  v3 = vgui::Panel::GetTall(this: this->m_pShowVisible) + v2;
  vgui::Panel::SetPos(this: this->m_pShowHidden, x, y: v3);
  vgui::Panel::SetWide(this: this->m_pShowHidden, wide: w / 2);
  v4 = vgui::Panel::GetTall(this: this->m_pShowHidden) + v3;
  vgui::Panel::SetPos(this: this->m_pPopupsOnly, x, y: v4);
  vgui::Panel::SetWide(this: this->m_pPopupsOnly, wide: w / 2);
  v5 = vgui::Panel::GetTall(this: this->m_pPopupsOnly) + v4;
  vgui::Panel::SetPos(this: this->m_pDrawFocus, x, y: v5);
  vgui::Panel::SetWide(this: this->m_pDrawFocus, wide: w / 2);
  v6 = vgui::Panel::GetTall(this: this->m_pDrawFocus) + v5;
  vgui::Panel::SetPos(this: this->m_pShowBounds, x, y: v6);
  vgui::Panel::SetWide(this: this->m_pShowBounds, wide: w / 2);
  v7 = vgui::Panel::GetTall(this: this->m_pShowBounds) + v6;
  vgui::Panel::SetPos(this: this->m_pShowScheme, x, y: v7);
  vgui::Panel::SetWide(this: this->m_pShowScheme, wide: w / 2);
  Tall = vgui::Panel::GetTall(this: this->m_pShowScheme);
  vgui::Panel::SetBounds(this: this->m_pTree, x, y: Tall + v7, wide: w, tall: t + y - (Tall + v7));
  v9 = y;
  vgui::Panel::SetPos(this: this->m_pFreeze, x: x + w / 2, y);
  vgui::Panel::SetWide(this: this->m_pFreeze, wide: w / 2);
  v10 = vgui::Panel::GetTall(this: this->m_pFreeze) + v9;
  vgui::Panel::SetPos(this: this->m_pShowPanelPtr, x: x + w / 2, y: v10);
  vgui::Panel::SetWide(this: this->m_pShowPanelPtr, wide: w / 2);
  v11 = vgui::Panel::GetTall(this: this->m_pShowPanelPtr) + v10;
  vgui::Panel::SetPos(this: this->m_pShowPanelAlpha, x: x + w / 2, y: v11);
  vgui::Panel::SetWide(this: this->m_pShowPanelAlpha, wide: w / 2);
  v12 = vgui::Panel::GetTall(this: this->m_pShowPanelAlpha) + v11;
  vgui::Panel::SetPos(this: this->m_pRenderOrder, x: x + w / 2, y: v12);
  vgui::Panel::SetWide(this: this->m_pRenderOrder, wide: w / 2);
  v13 = vgui::Panel::GetTall(this: this->m_pRenderOrder);
  vgui::Panel::SetPos(this: this->m_pHighlightSelected, x: x + w / 2, y: v13 + v12);
  vgui::Panel::SetWide(this: this->m_pHighlightSelected, wide: w / 2);
  vgui::Panel::GetTall(this: this->m_pHighlightSelected);
}

//------------------------------------------------------------------------------
// Address: 0x1020C2F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDrawTreeFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDrawTreeFrame::GetMessageMap(CDrawTreeFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDrawTreeFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDrawTreeFrame::GetMessageMap'::`2'::s_pMap;
  `CDrawTreeFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
  `CDrawTreeFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C320
// Name: public: virtual struct PanelAnimationMap __near * CDrawTreeFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDrawTreeFrame::GetAnimMap(CDrawTreeFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDrawTreeFrame");
}

//------------------------------------------------------------------------------
// Address: 0x1020C330
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDrawTreeFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDrawTreeFrame::GetKBMap(CDrawTreeFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDrawTreeFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDrawTreeFrame::GetKBMap'::`2'::s_pMap;
  `CDrawTreeFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDrawTreeFrame");
  `CDrawTreeFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C360
// Name: public: virtual void CDrawTreeFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CDrawTreeFrame::OnClose(CDrawTreeFrame *this)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&vgui_drawtree.IConVar, value: 0);
  vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C380
// Name: public: virtual void CDrawTreeFrame::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDrawTreeFrame::OnItemSelected(CDrawTreeFrame *this)
{
  CDrawTreeFrame::RecalculateSelectedHighlight(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020C390
// Name: void VGui_CreateDrawTreePanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_CreateDrawTreePanel(vgui::Panel *parent)
{
  CDrawTreeFrame *v1; // eax
  CDrawTreeFrame *v2; // esi
  int Wide; // eax
  int v4; // [esp-4h] [ebp-Ch]

  v1 = (CDrawTreeFrame *)MemAlloc_Alloc(nSize: 0x244u);
  if ( v1 != nullptr )
    v2 = CDrawTreeFrame::CDrawTreeFrame(this: v1, parent, pName: "DrawTreeFrame");
  else
    v2 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v2);
  g_pDrawTreeFrame = v2;
  v2->SetVisible(this: v2, a2: false);
  v4 = vgui::Panel::GetTall(this: parent) - 10;
  Wide = vgui::Panel::GetWide(this: parent);
  vgui::Panel::SetBounds(this: g_pDrawTreeFrame, x: Wide - 300, y: 0, wide: 300, tall: v4);
  vgui::Panel::MakePopup(this: g_pDrawTreeFrame, showTaskbarIcon: false, disabled: false);
  g_pDrawTreeFrame->SetKeyBoardInputEnabled(this: g_pDrawTreeFrame, a2: true);
  g_pDrawTreeFrame->SetMouseInputEnabled(this: g_pDrawTreeFrame, a2: true);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1020B2D0
// Name: void ChangeCallback_RefreshDrawTree(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChangeCallback_RefreshDrawTree()
{
  g_bForceRefresh = true;
}

//------------------------------------------------------------------------------
// Address: 0x1020B300
// Name: public: virtual void CVGuiTree::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiTree::ApplySchemeSettings(CVGuiTree *this, vgui::IScheme *pScheme)
{
  CVGuiTree_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "ConsoleText", a3: false);
  v3->SetFont(this, a2: v4);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020B350
// Name: public: static char const __near * CDrawTreeFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDrawTreeFrame::GetPanelClassName()
{
  return "CDrawTreeFrame";
}

//------------------------------------------------------------------------------
// Address: 0x1020B360
// Name: void VGui_MoveDrawTreePanelToFront(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_MoveDrawTreePanelToFront()
{
  if ( g_pDrawTreeFrame != nullptr )
    g_pDrawTreeFrame->MoveToFront(this: g_pDrawTreeFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1020B380
// Name: void vgui_drawtree_clear_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_drawtree_clear_f()
{
  if ( g_pDrawTreeFrame != nullptr && g_pDrawTreeFrame->m_pTree != nullptr )
    g_pDrawTreeFrame->m_pTree->RemoveAll(this: g_pDrawTreeFrame->m_pTree);
}

//------------------------------------------------------------------------------
// Address: 0x1020B3B0
// Name: public: static char const __near * vgui::TreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TreeView::GetPanelClassName()
{
  return "TreeView";
}

//------------------------------------------------------------------------------
// Address: 0x1020B3C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TreeView::GetMessageMap(vgui::TreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetMessageMap'::`2'::s_pMap;
  `vgui::TreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  `vgui::TreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B3F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TreeView::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TreeView::GetAnimMap(vgui::TreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "TreeView");
}

//------------------------------------------------------------------------------
// Address: 0x1020B400
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TreeView::GetKBMap(vgui::TreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetKBMap'::`2'::s_pMap;
  `vgui::TreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  `vgui::TreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B430
// Name: bool UpdateItemState(class vgui::TreeView __near *,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UpdateItemState(KeyValues *pTree, int iChildItemId, KeyValues *pSub)
{
  KeyValues *v3; // esi
  int Int; // eax
  KeyValues *v5; // edi
  const char *v6; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  char v10; // al
  void (__thiscall *v11)(KeyValues *, int, KeyValues **); // edx
  const char *String; // [esp-4h] [ebp-24h]
  int iBaseColor_8; // [esp+14h] [ebp-Ch]
  vgui::IPanel *ipanel; // [esp+18h] [ebp-8h]
  bool bRet; // [esp+1Fh] [ebp-1h]

  v3 = pTree;
  ipanel = g_pVGuiPanel;
  bRet = false;
  pTree = (KeyValues *)(*(int (__thiscall **)(KeyValues *, int))(*(_DWORD *)pTree + 864))(a1: pTree, a2: iChildItemId);
  Int = KeyValues::GetInt(this: pTree, keyName: "PanelPtr", defaultValue: 0);
  v5 = pSub;
  if ( Int != KeyValues::GetInt(this: pSub, keyName: "PanelPtr", defaultValue: 0)
    || (String = KeyValues::GetString(this: v5, keyName: "Text", defaultValue: defaultValue),
        v6 = KeyValues::GetString(this: pTree, keyName: "Text", defaultValue: defaultValue),
        _V_stricmp(s1: v6, s2: String) != 0) )
  {
    (*(void (__thiscall **)(KeyValues *, int, KeyValues *))(*(_DWORD *)v3 + 876))(a1: v3, a2: iChildItemId, a3: v5);
    bRet = true;
  }
  v7 = KeyValues::GetInt(this: v5, keyName: "PanelPtr", defaultValue: 0);
  v8 = 255;
  iBaseColor_8 = 255;
  if ( ipanel->IsPopup(this: ipanel, a2: v7) )
    iBaseColor_8 = 0;
  v9 = 0;
  if ( g_FocusPanelList.m_Size > 0 )
  {
    while ( g_FocusPanelList.m_Memory.m_pMemory[v9] != v7 )
    {
      if ( ++v9 >= g_FocusPanelList.m_Size )
        goto LABEL_12;
    }
    if ( v9 != -1 )
    {
      v8 = 0;
      iBaseColor_8 = 0;
      (*(void (__thiscall **)(KeyValues *, int, int))(*(_DWORD *)v3 + 972))(a1: v3, a2: iChildItemId, a3: 1);
    }
  }
LABEL_12:
  if ( ipanel->IsVisible(this: ipanel, a2: v7) )
  {
    v10 = -1;
  }
  else
  {
    v8 >>= 1;
    iBaseColor_8 >>= 1;
    v10 = 127;
  }
  v11 = *(void (__thiscall **)(KeyValues *, int, KeyValues **))(*(_DWORD *)v3 + 944);
  BYTE1(pTree) = v10;
  BYTE2(pTree) = iBaseColor_8;
  LOBYTE(pTree) = v8;
  HIBYTE(pTree) = -1;
  v11(a1: v3, a2: iChildItemId, a3: &pTree);
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1020B590
// Name: public: void CDrawTreeFrame::RecalculateSelectedHighlight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawTreeFrame::RecalculateSelectedHighlight(CDrawTreeFrame *this)
{
  CVGuiTree *m_pTree; // ecx
  KeyValues *v3; // eax
  unsigned int Int; // [esp-4h] [ebp-20h]
  CUtlVector<int,CUtlMemory<int,int> > list; // [esp+8h] [ebp-14h] BYREF

  if ( vgui_drawtree_draw_selected.m_pParent != nullptr
    && vgui_drawtree_draw_selected.m_pParent->m_Value.m_nValue != 0
    && this->m_pTree->GetSelectedItemCount(this: this->m_pTree) == 1 )
  {
    m_pTree = this->m_pTree;
    memset(&list, 0, sizeof(list));
    m_pTree->GetSelectedItems(this: m_pTree, a2: &list);
    v3 = this->m_pTree->GetItemData(this: this->m_pTree, a2: *list.m_Memory.m_pMemory);
    Int = 0;
    if ( v3 != nullptr )
      Int = KeyValues::GetInt(this: v3, keyName: "PanelPtr", defaultValue: 0);
    vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: Int);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
  }
  else
  {
    vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B640
// Name: void VGui_RecursivePrintTree(unsigned int,class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_RecursivePrintTree(
        int a1@<edi>,
        int a2@<esi>,
        const void *current,
        KeyValues *pCurrentParent,
        int popupDepthCounter)
{
  vgui::IPanel *v5; // esi
  const char *v6; // eax
  int m_nValue; // edi
  vgui::IPanel_vtbl *v8; // edx
  CFmtStrN<256> *v9; // eax
  int v10; // eax
  CFmtStrN<256> *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  int Int; // eax
  CFmtStrN<256> *v15; // eax
  unsigned int v16; // eax
  vgui::IScheme *v17; // eax
  vgui::IScheme *v18; // edi
  int v19; // eax
  const char *v20; // eax
  CFmtStrN<256> *v21; // eax
  const char *v22; // eax
  KeyValues *v23; // edi
  int v24; // edi
  unsigned int v25; // eax
  int v26; // [esp-18h] [ebp-148h]
  int v27; // [esp-14h] [ebp-144h]
  int v28; // [esp-10h] [ebp-140h]
  int v29; // [esp-Ch] [ebp-13Ch]
  const char *v30; // [esp-Ch] [ebp-13Ch]
  int v33; // [esp-4h] [ebp-134h]
  CFmtStrN<256> v34; // [esp+4h] [ebp-12Ch] BYREF
  int h; // [esp+110h] [ebp-20h] BYREF
  KeyValues *pVal; // [esp+114h] [ebp-1Ch]
  CUtlString name; // [esp+118h] [ebp-18h] BYREF
  int x; // [esp+128h] [ebp-8h]
  int w; // [esp+12Ch] [ebp-4h] BYREF

  if ( current != nullptr )
  {
    if ( (v5 = g_pVGuiPanel, vgui_drawtree_visible.m_pParent != nullptr)
      && vgui_drawtree_visible.m_pParent->m_Value.m_nValue != 0
      || !g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: (unsigned int)current) )
    {
      if ( (vgui_drawtree_hidden.m_pParent != nullptr && vgui_drawtree_hidden.m_pParent->m_Value.m_nValue != 0
         || v5->IsVisible(this: v5, a2: (unsigned int)current))
        && (popupDepthCounter > 0 || !v5->IsPopup(this: v5, a2: (unsigned int)current)) )
      {
        pVal = KeyValues::CreateNewKey(this: pCurrentParent);
        CUtlString::CUtlString(this: &name);
        v6 = (const char *)((int (__thiscall *)(vgui::IPanel *, const void *, int))v5->GetName)(
                             a1: v5,
                             a2: current,
                             a3: a2);
        if ( v6 == nullptr || *v6 == 0 )
          v6 = "(no name)";
        CUtlString::operator=(this: &name, src: v6);
        if ( v5->IsMouseInputEnabled(this: v5, a2: (unsigned int)current) )
          CUtlString::operator+=(this: &name, rhs: ", +m");
        if ( v5->IsKeyBoardInputEnabled(this: v5, a2: (unsigned int)current) )
          CUtlString::operator+=(this: &name, rhs: ", +k");
        if ( vgui_drawtree_bounds.m_pParent != nullptr )
        {
          m_nValue = vgui_drawtree_bounds.m_pParent->m_Value.m_nValue;
          if ( m_nValue > 0 )
          {
            CUtlString::operator+=(this: &name, rhs: ", ");
            ((void (__thiscall *)(vgui::IPanel *, const void *, int *, int *, int, int))v5->GetSize)(
              a1: v5,
              a2: current,
              a3: &w,
              a4: &h,
              a5: a1,
              a6: v33);
            v8 = v5->__vftable;
            if ( m_nValue == 1 )
            {
              ((void (__thiscall *)(vgui::IPanel *))v8->GetPos)(a1: v5);
              v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: "[%-4i %-4i %-4i %-4i]", x, current, w, h);
            }
            else
            {
              ((void (__thiscall *)(vgui::IPanel *, const void *))v8->GetAbsPos)(a1: v5, a2: current);
              v10 = ((int (__thiscall *)(vgui::IPanel *, const void *, int, const void *, int, int))v5->GetMessageContextId)(
                      a1: v5,
                      a2: current,
                      a3: x,
                      a4: current,
                      a5: w,
                      a6: h);
              v9 = CFmtStrN<256>::CFmtStrN<256>(
                     this: &v34,
                     pszFormat: "abs [%d][%-4i %-4i %-4i %-4i]",
                     v10,
                     v26,
                     v27,
                     v28,
                     v29);
            }
            CUtlString::operator+=(this: &name, rhs: v9->m_szBuf);
          }
        }
        if ( vgui_drawtree_panelptr.m_pParent != nullptr && vgui_drawtree_panelptr.m_pParent->m_Value.m_nValue != 0 )
        {
          v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " - [0x%p]", current);
          CUtlString::operator+=(this: &name, rhs: v11->m_szBuf);
        }
        if ( vgui_drawtree_panelalpha.m_pParent != nullptr && vgui_drawtree_panelalpha.m_pParent->m_Value.m_nValue != 0 )
        {
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v13 = KeyValues::KeyValues(this: v12, setName: "alpha");
          else
            v13 = nullptr;
          v5->RequestInfo(this: v5, a2: (unsigned int)current, a3: v13);
          Int = KeyValues::GetInt(this: v13, keyName: "alpha", defaultValue: 0);
          v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " - [%d]", Int);
          CUtlString::operator+=(this: &name, rhs: v15->m_szBuf);
          KeyValues::deleteThis(this: v13);
        }
        if ( vgui_drawtree_scheme.m_pParent != nullptr && vgui_drawtree_scheme.m_pParent->m_Value.m_nValue != 0 )
        {
          v16 = v5->GetScheme(this: v5, a2: (unsigned int)current);
          if ( v16 != 0 )
          {
            v17 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v16);
            v18 = v17;
            if ( v17 != nullptr )
            {
              v19 = (int)v17->GetFileName(this: v17);
              v20 = (const char *)((int (__thiscall *)(vgui::IScheme *, int))v18->GetName)(a1: v18, a2: v19);
              v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: " [%s - %s]", v20, v30);
              CUtlString::operator+=(this: &name, rhs: v21->m_szBuf);
            }
          }
        }
        v22 = CUtlString::operator char const *(this: &name);
        v23 = pVal;
        KeyValues::SetString(this: pVal, keyName: "Text", value: v22);
        KeyValues::SetInt(this: v23, keyName: "PanelPtr", value: (int)current);
        if ( current == (const void *)g_pDrawTreeFrame->m_pTree->GetVPanel(this: g_pDrawTreeFrame->m_pTree) )
        {
          CUtlString::~CUtlString(this: &name);
        }
        else
        {
          v24 = 0;
          w = v5->GetChildCount(this: v5, a2: (unsigned int)current);
          if ( w > 0 )
          {
            do
            {
              v25 = v5->GetChild(this: v5, a2: (unsigned int)current, a3: v24);
              VGui_RecursivePrintTree(current: v25, pCurrentParent: pVal, popupDepthCounter: popupDepthCounter - 1);
              ++v24;
            }
            while ( v24 < w );
          }
          name.m_Storage.m_nActualLength = 0;
          if ( name.m_Storage.m_Memory.m_nGrowSize >= 0 && name.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: name.m_Storage.m_Memory.m_pMemory);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BA20
// Name: void VGui_AddPopupsToKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_AddPopupsToKeyValues(unsigned int a1@<esi>, KeyValues *pCurrentParent)
{
  int v2; // ebx
  const void *v3; // edi
  int count; // [esp+4h] [ebp-4h]

  v2 = 0;
  count = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface);
  if ( count > 0 )
  {
    do
    {
      v3 = (const void *)g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v2);
      if ( vgui_drawtree_hidden.m_pParent != nullptr && vgui_drawtree_hidden.m_pParent->m_Value.m_nValue != 0
        || (a1 = (unsigned int)v3, v3 == nullptr) )
      {
LABEL_7:
        VGui_RecursivePrintTree(a1: (int)v3, a2: a1, current: v3, pCurrentParent, popupDepthCounter: 1);
      }
      else
      {
        while ( g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: a1) )
        {
          a1 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: a1);
          if ( a1 == 0 )
            goto LABEL_7;
        }
      }
      ++v2;
    }
    while ( v2 < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BB40
// Name: void VGui_DrawHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_DrawHierarchy()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi

  if ( vgui_drawtree.m_pParent != nullptr && vgui_drawtree.m_pParent->m_Value.m_nValue > 0 )
  {
    g_pDrawTreeFrame->SetVisible(this: g_pDrawTreeFrame, a2: true);
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
      v1 = KeyValues::KeyValues(this: v0, setName: defaultValue);
    else
      v1 = nullptr;
    KeyValues::SetString(this: v1, keyName: "Text", value: "<shouldn't see this>");
    VGui_FillKeyValues(pCurrentParent: v1);
    IncrementalUpdateTree(pTree: g_pDrawTreeFrame->m_pTree, pValues: v1);
    KeyValues::deleteThis(this: v1);
  }
  else
  {
    g_pDrawTreeFrame->SetVisible(this: g_pDrawTreeFrame, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BBD0
// Name: void VGui_UpdateDrawTreePanel(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl VGui_UpdateDrawTreePanel()
{
  VGui_DrawHierarchy();
}

//------------------------------------------------------------------------------
// Address: 0x1020BBE0
// Name: public: static void CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TreeViewItemSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BC70
// Name: public: CDrawTreeFrame::CDrawTreeFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDrawTreeFrame *__thiscall CDrawTreeFrame::CDrawTreeFrame(CDrawTreeFrame *this, vgui::Panel *parent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TreeView *v7; // eax
  CVGuiTree *v8; // edi
  CConVarCheckButton *v9; // eax
  CConVarCheckButton *v10; // edi
  CConVarCheckButton *v11; // eax
  CConVarCheckButton *v12; // edi
  CConVarCheckButton *v13; // eax
  CConVarCheckButton *v14; // edi
  CConVarCheckButton *v15; // eax
  CConVarCheckButton *v16; // edi
  CConVarCheckButton *v17; // eax
  CConVarCheckButton *v18; // edi
  CConVarCheckButton *v19; // eax
  CConVarCheckButton *v20; // edi
  CConVarCheckButton *v21; // eax
  CConVarCheckButton *v22; // edi
  CConVarCheckButton *v23; // eax
  CConVarCheckButton *v24; // edi
  CConVarCheckButton *v25; // eax
  CConVarCheckButton *v26; // edi
  CConVarCheckButton *v27; // eax
  CConVarCheckButton *v28; // edi
  CConVarCheckButton *v29; // eax
  CConVarCheckButton *v30; // edi
  Color *BgColor; // eax
  unsigned __int8 v32; // cl
  unsigned __int8 v33; // dl
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: pName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDrawTreeFrame_vtbl *)&CDrawTreeFrame::`vftable';
  if ( `CDrawTreeFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
    v4->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CDrawTreeFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDrawTreeFrame");
    v5->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CDrawTreeFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDrawTreeFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDrawTreeFrame");
    v6->pfnClassName = CDrawTreeFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  CDrawTreeFrame::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title: "VGUI Hierarchy", surfaceTitle: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  v7 = (vgui::TreeView *)MemAlloc_Alloc(nSize: 0x1BCu);
  v8 = (CVGuiTree *)v7;
  if ( v7 != nullptr )
  {
    vgui::TreeView::TreeView(this: v7, parent: this, panelName: "Tree view");
    v8->__vftable = (CVGuiTree_vtbl *)&CVGuiTree::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pTree = v8;
  v8->SetVisible(this: v8, a2: true);
  v9 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v9 != nullptr )
    v10 = CConVarCheckButton::CConVarCheckButton(
            this: v9,
            parent: this,
            panelName: "show visible",
            text: "Show Visible");
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pShowVisible = v10;
  v10->SetVisible(this: v10, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowVisible, pVar: &vgui_drawtree_visible);
  v11 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v11 != nullptr )
    v12 = CConVarCheckButton::CConVarCheckButton(this: v11, parent: this, panelName: "show hidden", text: "Show Hidden");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pShowHidden = v12;
  v12->SetVisible(this: v12, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowHidden, pVar: &vgui_drawtree_hidden);
  v13 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v13 != nullptr )
    v14 = CConVarCheckButton::CConVarCheckButton(this: v13, parent: this, panelName: "popups only", text: "Popups Only");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pPopupsOnly = v14;
  v14->SetVisible(this: v14, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pPopupsOnly, pVar: &vgui_drawtree_popupsonly);
  v15 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v15 != nullptr )
    v16 = CConVarCheckButton::CConVarCheckButton(
            this: v15,
            parent: this,
            panelName: "draw focus",
            text: "Highlight MouseOver");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pDrawFocus = v16;
  v16->SetVisible(this: v16, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pDrawFocus, pVar: &vgui_drawfocus);
  v17 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v17 != nullptr )
    v18 = CConVarCheckButton::CConVarCheckButton(this: v17, parent: this, panelName: "freeze option", text: "Freeze");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pFreeze = v18;
  v18->SetVisible(this: v18, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pFreeze, pVar: &vgui_drawtree_freeze);
  v19 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v19 != nullptr )
    v20 = CConVarCheckButton::CConVarCheckButton(
            this: v19,
            parent: this,
            panelName: "panel ptr option",
            text: "Show Addresses");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pShowPanelPtr = v20;
  v20->SetVisible(this: v20, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowPanelPtr, pVar: &vgui_drawtree_panelptr);
  v21 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v21 != nullptr )
    v22 = CConVarCheckButton::CConVarCheckButton(
            this: v21,
            parent: this,
            panelName: "panel alpha option",
            text: "Show Alpha");
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pShowPanelAlpha = v22;
  v22->SetVisible(this: v22, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowPanelAlpha, pVar: &vgui_drawtree_panelalpha);
  v23 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v23 != nullptr )
    v24 = CConVarCheckButton::CConVarCheckButton(
            this: v23,
            parent: this,
            panelName: "render order option",
            text: "In Render Order");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pRenderOrder = v24;
  v24->SetVisible(this: v24, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pRenderOrder, pVar: &vgui_drawtree_render_order);
  v25 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v25 != nullptr )
    v26 = CConVarCheckButton::CConVarCheckButton(
            this: v25,
            parent: this,
            panelName: "show panel bounds",
            text: "Show Panel Bounds");
  else
    v26 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v26);
  this->m_pShowBounds = v26;
  v26->SetVisible(this: v26, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowBounds, pVar: &vgui_drawtree_bounds);
  v27 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v27 != nullptr )
    v28 = CConVarCheckButton::CConVarCheckButton(
            this: v27,
            parent: this,
            panelName: "highlight selected",
            text: "Highlight Selected");
  else
    v28 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v28);
  this->m_pHighlightSelected = v28;
  v28->SetVisible(this: v28, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pHighlightSelected, pVar: &vgui_drawtree_draw_selected);
  v29 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v29 != nullptr )
    v30 = CConVarCheckButton::CConVarCheckButton(this: v29, parent: this, panelName: "show scheme", text: "Show Scheme");
  else
    v30 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v30);
  this->m_pShowScheme = v30;
  v30->SetVisible(this: v30, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowScheme, pVar: &vgui_drawtree_scheme);
  BgColor = vgui::Panel::GetBgColor(this, result: (Color *)&parent);
  v32 = BgColor->_color[1];
  LOBYTE(pName) = BgColor->_color[0];
  v33 = BgColor->_color[2];
  BYTE1(pName) = v32;
  BYTE2(pName) = v33;
  HIBYTE(pName) = 0x80;
  CBaseDemoAction::SetStartTick(this, color: (Color)pName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020C160
// Name: public: virtual void CDrawTreeFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawTreeFrame::PerformLayout(CDrawTreeFrame *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int Tall; // eax
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // eax
  int t; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int w; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &t);
  v2 = y;
  vgui::Panel::SetPos(this: this->m_pShowVisible, x, y);
  vgui::Panel::SetWide(this: this->m_pShowVisible, wide: w / 2);
  v3 = vgui::Panel::GetTall(this: this->m_pShowVisible) + v2;
  vgui::Panel::SetPos(this: this->m_pShowHidden, x, y: v3);
  vgui::Panel::SetWide(this: this->m_pShowHidden, wide: w / 2);
  v4 = vgui::Panel::GetTall(this: this->m_pShowHidden) + v3;
  vgui::Panel::SetPos(this: this->m_pPopupsOnly, x, y: v4);
  vgui::Panel::SetWide(this: this->m_pPopupsOnly, wide: w / 2);
  v5 = vgui::Panel::GetTall(this: this->m_pPopupsOnly) + v4;
  vgui::Panel::SetPos(this: this->m_pDrawFocus, x, y: v5);
  vgui::Panel::SetWide(this: this->m_pDrawFocus, wide: w / 2);
  v6 = vgui::Panel::GetTall(this: this->m_pDrawFocus) + v5;
  vgui::Panel::SetPos(this: this->m_pShowBounds, x, y: v6);
  vgui::Panel::SetWide(this: this->m_pShowBounds, wide: w / 2);
  v7 = vgui::Panel::GetTall(this: this->m_pShowBounds) + v6;
  vgui::Panel::SetPos(this: this->m_pShowScheme, x, y: v7);
  vgui::Panel::SetWide(this: this->m_pShowScheme, wide: w / 2);
  Tall = vgui::Panel::GetTall(this: this->m_pShowScheme);
  vgui::Panel::SetBounds(this: this->m_pTree, x, y: Tall + v7, wide: w, tall: t + y - (Tall + v7));
  v9 = y;
  vgui::Panel::SetPos(this: this->m_pFreeze, x: x + w / 2, y);
  vgui::Panel::SetWide(this: this->m_pFreeze, wide: w / 2);
  v10 = vgui::Panel::GetTall(this: this->m_pFreeze) + v9;
  vgui::Panel::SetPos(this: this->m_pShowPanelPtr, x: x + w / 2, y: v10);
  vgui::Panel::SetWide(this: this->m_pShowPanelPtr, wide: w / 2);
  v11 = vgui::Panel::GetTall(this: this->m_pShowPanelPtr) + v10;
  vgui::Panel::SetPos(this: this->m_pShowPanelAlpha, x: x + w / 2, y: v11);
  vgui::Panel::SetWide(this: this->m_pShowPanelAlpha, wide: w / 2);
  v12 = vgui::Panel::GetTall(this: this->m_pShowPanelAlpha) + v11;
  vgui::Panel::SetPos(this: this->m_pRenderOrder, x: x + w / 2, y: v12);
  vgui::Panel::SetWide(this: this->m_pRenderOrder, wide: w / 2);
  v13 = vgui::Panel::GetTall(this: this->m_pRenderOrder);
  vgui::Panel::SetPos(this: this->m_pHighlightSelected, x: x + w / 2, y: v13 + v12);
  vgui::Panel::SetWide(this: this->m_pHighlightSelected, wide: w / 2);
  vgui::Panel::GetTall(this: this->m_pHighlightSelected);
}

//------------------------------------------------------------------------------
// Address: 0x1020C400
// Name: public: virtual struct vgui::PanelMessageMap __near * CDrawTreeFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDrawTreeFrame::GetMessageMap(CDrawTreeFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDrawTreeFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDrawTreeFrame::GetMessageMap'::`2'::s_pMap;
  `CDrawTreeFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDrawTreeFrame");
  `CDrawTreeFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C430
// Name: public: virtual struct PanelAnimationMap __near * CDrawTreeFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDrawTreeFrame::GetAnimMap(CDrawTreeFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDrawTreeFrame");
}

//------------------------------------------------------------------------------
// Address: 0x1020C440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDrawTreeFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDrawTreeFrame::GetKBMap(CDrawTreeFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDrawTreeFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDrawTreeFrame::GetKBMap'::`2'::s_pMap;
  `CDrawTreeFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDrawTreeFrame");
  `CDrawTreeFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C470
// Name: public: virtual void CDrawTreeFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CDrawTreeFrame::OnClose(CDrawTreeFrame *this)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&vgui_drawtree.IConVar, value: 0, a2: v1, a3: v2);
  vgui::VPanelHandle::Set(this: &g_DrawTreeSelectedPanel, pent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C490
// Name: public: virtual void CDrawTreeFrame::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDrawTreeFrame::OnItemSelected(CDrawTreeFrame *this)
{
  CDrawTreeFrame::RecalculateSelectedHighlight(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020C4A0
// Name: void VGui_CreateDrawTreePanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_CreateDrawTreePanel(vgui::Panel *parent)
{
  CDrawTreeFrame *v1; // eax
  CDrawTreeFrame *v2; // esi
  int Wide; // eax
  int v4; // [esp-4h] [ebp-Ch]

  v1 = (CDrawTreeFrame *)MemAlloc_Alloc(nSize: 0x244u);
  if ( v1 != nullptr )
    v2 = CDrawTreeFrame::CDrawTreeFrame(this: v1, parent, pName: "DrawTreeFrame");
  else
    v2 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v2);
  g_pDrawTreeFrame = v2;
  v2->SetVisible(this: v2, a2: false);
  v4 = vgui::Panel::GetTall(this: parent) - 10;
  Wide = vgui::Panel::GetWide(this: parent);
  vgui::Panel::SetBounds(this: g_pDrawTreeFrame, x: Wide - 300, y: 0, wide: 300, tall: v4);
  vgui::Panel::MakePopup(this: g_pDrawTreeFrame, showTaskbarIcon: false, disabled: false);
  g_pDrawTreeFrame->SetKeyBoardInputEnabled(this: g_pDrawTreeFrame, a2: true);
  g_pDrawTreeFrame->SetMouseInputEnabled(this: g_pDrawTreeFrame, a2: true);
}

} // namespace engine_xlsp
