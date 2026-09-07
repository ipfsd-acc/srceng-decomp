// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/saveinfo.cpp
// Functions: 58
// ============================================================

#include "hammer\saveinfo.h"

//------------------------------------------------------------------------------
// Address: 0x100A02F0
// Name: public: bool CSaveInfo::ShouldSaveObject(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveInfo::ShouldSaveObject(CSaveInfo *this, CMapClass *pObject)
{
  return !this->m_bVisiblesOnly || (*((_BYTE *)pObject + 180) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x105CC53E
// Name: _CMFCBaseTabCtrl::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__info__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl CMFCBaseTabCtrl::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__info__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)info.m_strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC54C
// Name: _dynamic_atexit_destructor_for__CBasePane::m_CriticalSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBasePane::m_CriticalSection__()
{
  CCriticalSection::~CCriticalSection(this: &CBasePane::m_CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x105CC556
// Name: _dynamic_atexit_destructor_for__strBaseControlBarProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strBaseControlBarProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strBaseControlBarProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC564
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___8()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_8.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC572
// Name: _dynamic_atexit_destructor_for__strRegEntryNameControlBars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRegEntryNameControlBars__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRegEntryNameControlBars.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC580
// Name: _dynamic_atexit_destructor_for__strWindowPlacementRegSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strWindowPlacementRegSection__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strWindowPlacementRegSection.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC58E
// Name: _dynamic_atexit_destructor_for__strRectMainKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRectMainKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRectMainKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC59C
// Name: _dynamic_atexit_destructor_for__strFlagsKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strFlagsKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strFlagsKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5AA
// Name: _dynamic_atexit_destructor_for__strShowCmdKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strShowCmdKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strShowCmdKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5B8
// Name: _dynamic_atexit_destructor_for__strRegEntryNameSizingBars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRegEntryNameSizingBars__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRegEntryNameSizingBars.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5C6
// Name: _dynamic_atexit_destructor_for__strRegEntryVersion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRegEntryVersion__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRegEntryVersion.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5D4
// Name: _dynamic_atexit_destructor_for__strVersionMajorKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strVersionMajorKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strVersionMajorKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5E2
// Name: _dynamic_atexit_destructor_for__strVersionMinorKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strVersionMinorKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strVersionMinorKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5F0
// Name: _dynamic_atexit_destructor_for__strMenuProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strMenuProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strMenuProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC5FE
// Name: _dynamic_atexit_destructor_for__CMFCDropDownFrame::m_strClassName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCDropDownFrame::m_strClassName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCDropDownFrame::m_strClassName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC60C
// Name: _CDockablePane::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CDockablePane::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_3.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC61A
// Name: _dynamic_atexit_destructor_for__CMFCToolBarButton::m_lstProtectedCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBarButton::m_lstProtectedCommands__()
{
  CMFCToolBarButton::m_lstProtectedCommands.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CMFCToolBarButton::m_lstProtectedCommands);
}

//------------------------------------------------------------------------------
// Address: 0x105CC62E
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___9()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_9.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC63C
// Name: _dynamic_atexit_destructor_for__CMFCToolBarButton::m_strClipboardFormatName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBarButton::m_strClipboardFormatName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCToolBarButton::m_strClipboardFormatName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC64A
// Name: _dynamic_atexit_destructor_for__strDummyAmpSeq___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strDummyAmpSeq___0()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strDummyAmpSeq_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC658
// Name: _dynamic_atexit_destructor_for__strUserToolsProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strUserToolsProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strUserToolsProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC666
// Name: _dynamic_atexit_destructor_for__strUserToolsEntry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strUserToolsEntry__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strUserToolsEntry.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC674
// Name: _dynamic_atexit_destructor_for__CMFCCustomizeMenuButton::m_mapPresentIDs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCCustomizeMenuButton::m_mapPresentIDs__()
{
  CMFCCustomizeMenuButton::m_mapPresentIDs.__vftable = (CMap<unsigned int,unsigned int,int,int>_vtbl *)&CMap<unsigned int,unsigned int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCCustomizeMenuButton::m_mapPresentIDs);
}

//------------------------------------------------------------------------------
// Address: 0x105CC688
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___10()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_10.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC696
// Name: _AFXPlaySystemSound_::_11_::_dynamic_atexit_destructor_for__cs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AFXPlaySystemSound_::_11_::_dynamic_atexit_destructor_for__cs__()
{
  CCriticalSection::~CCriticalSection(this: &stru_1083CC40);
}

//------------------------------------------------------------------------------
// Address: 0x105CC6A0
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___11()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_11.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC6AE
// Name: _dynamic_atexit_destructor_for__strRibbonProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRibbonProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRibbonProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC6BC
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___12()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_12.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC6CA
// Name: _dynamic_atexit_destructor_for__gc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gc__()
{
  CPaneContainerGC::CleanUp(this: &gc);
  CObList::~CObList(this: &gc.m_lstDisposedContainers);
}

//------------------------------------------------------------------------------
// Address: 0x105CC6F7
// Name: _dynamic_atexit_destructor_for__strOutlookBarProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strOutlookBarProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strOutlookBarProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC705
// Name: _dynamic_atexit_destructor_for__strRegCustomPages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRegCustomPages__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRegCustomPages.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC713
// Name: _dynamic_atexit_destructor_for__CMFCTabCtrl::m_mapDocIcons__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCTabCtrl::m_mapDocIcons__()
{
  CMFCTabCtrl::m_mapDocIcons.__vftable = (CMap<unsigned int,unsigned int,HICON__ *,HICON__ *>_vtbl *)&CMap<unsigned int,unsigned int,HICON__ *,HICON__ *>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCTabCtrl::m_mapDocIcons);
}

//------------------------------------------------------------------------------
// Address: 0x105CC727
// Name: _dynamic_atexit_destructor_for__strRibbonProfile___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRibbonProfile___0()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRibbonProfile_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC735
// Name: _dynamic_atexit_destructor_for__strMenusProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strMenusProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strMenusProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC743
// Name: _dynamic_atexit_destructor_for__CMFCColorBar::m_ColorNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCColorBar::m_ColorNames__()
{
  CMFCColorBar::m_ColorNames.__vftable = (CMap<unsigned long,unsigned long,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,char const *>_vtbl *)&CMap<unsigned long,unsigned long,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *>::`vftable';
  CMap<unsigned long,unsigned long,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *>::RemoveAll(this: &CMFCColorBar::m_ColorNames);
}

//------------------------------------------------------------------------------
// Address: 0x105CC757
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridToolTipCtrl::m_strClassName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridToolTipCtrl::m_strClassName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridToolTipCtrl::m_strClassName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC765
// Name: _dynamic_atexit_destructor_for__CMFCToolBarFontComboBox::m_lstFonts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBarFontComboBox::m_lstFonts__()
{
  CObList::~CObList(this: &CMFCToolBarFontComboBox::m_lstFonts);
}

//------------------------------------------------------------------------------
// Address: 0x105CC76F
// Name: _CMFCRibbonPanelMenuBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCRibbonPanelMenuBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_4.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC77D
// Name: _dynamic_atexit_destructor_for__CMFCRibbonGallery::m_mapSelectedItems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCRibbonGallery::m_mapSelectedItems__()
{
  CMFCRibbonGallery::m_mapSelectedItems.__vftable = (CMap<unsigned int,unsigned int,int,int>_vtbl *)&CMap<unsigned int,unsigned int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCRibbonGallery::m_mapSelectedItems);
}

//------------------------------------------------------------------------------
// Address: 0x105CC791
// Name: _CMFCTasksPaneFrameWnd::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCTasksPaneFrameWnd::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_5.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC79F
// Name: _dynamic_atexit_destructor_for__CMFCRibbonKeyTip::m_strClassName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCRibbonKeyTip::m_strClassName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCRibbonKeyTip::m_strClassName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7AD
// Name: _dynamic_atexit_destructor_for__strControlBarProfile___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strControlBarProfile___0()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strControlBarProfile_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7BB
// Name: _dynamic_atexit_destructor_for__strRegEntryName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRegEntryName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRegEntryName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7C9
// Name: _dynamic_atexit_destructor_for__strMouseProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strMouseProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strMouseProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7D7
// Name: _dynamic_atexit_destructor_for__strRebarKeyFmt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRebarKeyFmt__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRebarKeyFmt.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7E5
// Name: _dynamic_atexit_destructor_for__strRebarKey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRebarKey__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRebarKey.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC7F3
// Name: _dynamic_atexit_destructor_for__strRebarId__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strRebarId__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strRebarId.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC801
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___13
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___13()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_13.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC80F
// Name: _dynamic_atexit_destructor_for___afxOleState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxOleState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxOleState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC819
// Name: _dynamic_atexit_destructor_for__CMFCRibbonStatusBarPane::m_CriticalSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCRibbonStatusBarPane::m_CriticalSection__()
{
  CCriticalSection::~CCriticalSection(this: &CMFCRibbonStatusBarPane::m_CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x105CC823
// Name: _dynamic_atexit_destructor_for__CMFCRibbonStatusBarPane::m_mapAnimations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCRibbonStatusBarPane::m_mapAnimations__()
{
  CMFCRibbonStatusBarPane::m_mapAnimations.__vftable = (CMap<unsigned int,unsigned int,CMFCRibbonStatusBarPane *,CMFCRibbonStatusBarPane *>_vtbl *)&CMap<unsigned int,unsigned int,CMFCRibbonStatusBarPane *,CMFCRibbonStatusBarPane *>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCRibbonStatusBarPane::m_mapAnimations);
}

//------------------------------------------------------------------------------
// Address: 0x105CC837
// Name: _GetSmartDockingWndClassName_0__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetSmartDockingWndClassName_0__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)`GetSmartDockingWndClassName<0>'::`2'::strSDWndClassName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC845
// Name: _GetSmartDockingWndClassName_2080__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetSmartDockingWndClassName_2080__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)`GetSmartDockingWndClassName<2080>'::`2'::strSDWndClassName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC853
// Name: _dynamic_atexit_destructor_for__CMFCColorMenuButton::m_ColorsByID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCColorMenuButton::m_ColorsByID__()
{
  CMFCColorMenuButton::m_ColorsByID.__vftable = (CMap<unsigned int,unsigned int,unsigned long,unsigned long>_vtbl *)&CMap<unsigned int,unsigned int,unsigned long,unsigned long>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: &CMFCColorMenuButton::m_ColorsByID);
}

//------------------------------------------------------------------------------
// Address: 0x105CC867
// Name: _dynamic_atexit_destructor_for__strTasksPaneProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strTasksPaneProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTasksPaneProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC875
// Name: _CMFCTasksPane::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCTasksPane::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_6.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC883
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___14
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___14()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_14.m_pszData - 1);
}
