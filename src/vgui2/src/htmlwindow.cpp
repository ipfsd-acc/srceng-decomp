// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/htmlwindow.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: _IsEqualGUID
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( rguid1->Data1 == rguid2->Data1 )
  {
    v4 -= 4;
    rguid2 = (const _GUID *)((char *)rguid2 + 4);
    rguid1 = (const _GUID *)((char *)rguid1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AFE0
// Name: _dynamic_initializer_for__html_windows__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__html_windows__()
{
  return atexit(func: dynamic_atexit_destructor_for__html_windows__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B360
// Name: _dynamic_atexit_destructor_for__html_windows__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__html_windows__()
{
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&html_windows);
}

//------------------------------------------------------------------------------
// Address: 0x1003AFF0
// Name: _dynamic_initializer_for__g_Input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Input__()
{
  CInputWin32::CInputWin32(this: &g_Input);
  return atexit(func: dynamic_atexit_destructor_for__g_Input__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B010
// Name: _dynamic_initializer_for____g_CreateCInputWin32IInput_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCInputWin32IInput_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCInputWin32IInput_reg,
           fn: _CreateCInputWin32IInputInternal_interface,
           pName: "VGUI_Input005");
}

//------------------------------------------------------------------------------
// Address: 0x1003B030
// Name: _dynamic_initializer_for____g_CreateCInputWin32IInputInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCInputWin32IInputInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCInputWin32IInputInternal_reg,
           fn: _CreateCInputWin32IInputInternal_interface,
           pName: "VGUI_InputInternal001");
}

//------------------------------------------------------------------------------
// Address: 0x1003B050
// Name: _dynamic_initializer_for__g_Scheme__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Scheme__()
{
  CSchemeManager::CSchemeManager(this: &g_Scheme);
  return atexit(func: dynamic_atexit_destructor_for__g_Scheme__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B070
// Name: _dynamic_initializer_for____g_CreateCSchemeManagerISchemeManager_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCSchemeManagerISchemeManager_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCSchemeManagerISchemeManager_reg,
           fn: _CreateCSchemeManagerISchemeManager_interface,
           pName: "VGUI_Scheme010");
}

//------------------------------------------------------------------------------
// Address: 0x1003B370
// Name: _dynamic_atexit_destructor_for__g_Input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Input__()
{
  CInputWin32::~CInputWin32(this: &g_Input);
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100BA950
// Name: _dynamic_initializer_for__html_windows__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__html_windows__()
{
  return atexit(func: dynamic_atexit_destructor_for__html_windows__);
}

//------------------------------------------------------------------------------
// Address: 0x100BB4D0
// Name: _dynamic_atexit_destructor_for__html_windows__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__html_windows__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&html_windows);
}

//------------------------------------------------------------------------------
// Address: 0x100BA960
// Name: _dynamic_initializer_for__g_FontTextureCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FontTextureCache__()
{
  CFontTextureCache::CFontTextureCache(this: &g_FontTextureCache);
  return atexit(func: dynamic_atexit_destructor_for__g_FontTextureCache__);
}

//------------------------------------------------------------------------------
// Address: 0x100BA980
// Name: _dynamic_initializer_for__g_MatSystemSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatSystemSurface__()
{
  CMatSystemSurface::CMatSystemSurface(this: &g_MatSystemSurface);
  return atexit(func: dynamic_atexit_destructor_for__g_MatSystemSurface__);
}

//------------------------------------------------------------------------------
// Address: 0x100BA9A0
// Name: _dynamic_initializer_for____g_CreateCMatSystemSurfaceISurface_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCMatSystemSurfaceISurface_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCMatSystemSurfaceISurface_reg,
           fn: (void *(__cdecl *)())_CreateCMatSystemSurfaceISurface_interface,
           pName: "VGUI_Surface031");
}

//------------------------------------------------------------------------------
// Address: 0x100BA9C0
// Name: _dynamic_initializer_for____g_CreateCMatSystemSurfaceISchemeSurface_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCMatSystemSurfaceISchemeSurface_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCMatSystemSurfaceISchemeSurface_reg,
           fn: (void *(__cdecl *)())_CreateCMatSystemSurfaceISchemeSurface_interface,
           pName: "SchemeSurface001");
}

//------------------------------------------------------------------------------
// Address: 0x100BA9E0
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9F0
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA00
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA10
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA20
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA30
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA40
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA50
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA60
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA70
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA80
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA90
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAA0
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAB0
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAC0
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAD0
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAE0
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAAF0
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB00
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB10
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB20
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB30
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB40
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB50
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB60
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB70
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB80
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB90
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABA0
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABB0
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABC0
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABD0
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABE0
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100BABF0
// Name: _dynamic_initializer_for__s_TextureDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TextureDictionary__()
{
  CTextureDictionary::CTextureDictionary(this: &s_TextureDictionary);
  return atexit(func: dynamic_atexit_destructor_for__s_TextureDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x100BAC10
// Name: _dynamic_initializer_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_FontManager__()
{
  CFontManager::CFontManager(this: &s_FontManager);
  return atexit(func: dynamic_atexit_destructor_for__s_FontManager__);
}

//------------------------------------------------------------------------------
// Address: 0x100BB4E0
// Name: _dynamic_atexit_destructor_for__g_FontTextureCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FontTextureCache__()
{
  CFontTextureCache::~CFontTextureCache(this: &g_FontTextureCache);
}

//------------------------------------------------------------------------------
// Address: 0x100BB4F0
// Name: _dynamic_atexit_destructor_for__g_MatSystemSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatSystemSurface__()
{
  CMatSystemSurface::~CMatSystemSurface(this: &g_MatSystemSurface);
}

//------------------------------------------------------------------------------
// Address: 0x100BB500
// Name: _dynamic_atexit_destructor_for__s_TextureDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TextureDictionary__()
{
  CUtlDict<int,int>::RemoveAll(this: &s_TextureDictionary.m_TextureIDs);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &s_TextureDictionary.m_TextureIDs.m_Elements.m_Tree);
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(this: &s_TextureDictionary.m_Textures);
  if ( s_TextureDictionary.m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_TextureDictionary.m_Textures.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_TextureDictionary.m_Textures.m_Memory.m_pMemory);
      s_TextureDictionary.m_Textures.m_Memory.m_pMemory = nullptr;
    }
    s_TextureDictionary.m_Textures.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB560
// Name: _dynamic_atexit_destructor_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_FontManager__()
{
  CFontManager::ClearAllFonts(this: &s_FontManager);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_FontManager.m_Win32Fonts);
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::Purge(this: &s_FontManager.m_FontAmalgams);
  if ( s_FontManager.m_FontAmalgams.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_FontManager.m_FontAmalgams.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_FontManager.m_FontAmalgams.m_Memory.m_pMemory);
      s_FontManager.m_FontAmalgams.m_Memory.m_pMemory = nullptr;
    }
    s_FontManager.m_FontAmalgams.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vguimatsurface
