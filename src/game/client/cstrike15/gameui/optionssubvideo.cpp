// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubvideo.cpp
// Functions: 74
// ============================================================

#include "game\client\cstrike15\gameui\optionssubvideo.h"

//------------------------------------------------------------------------------
// Address: 0x100F4390
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F43D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017FF10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017FF40
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x1017FF50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D74C0
// Name: public: virtual void COptionsSubVideoThirdPartyCreditsDlg::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoThirdPartyCreditsDlg::Activate(CMultiplayerAdvancedDialog *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax

  vgui::Frame::Activate(this);
  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101E0950
// Name: public: static char const __near * COptionsSubVideo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubVideo::GetPanelClassName()
{
  return "COptionsSubVideo";
}

//------------------------------------------------------------------------------
// Address: 0x101E0960
// Name: public: static char const __near * COptionsSubVideoThirdPartyCreditsDlg::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubVideoThirdPartyCreditsDlg::GetPanelClassName()
{
  return "COptionsSubVideoThirdPartyCreditsDlg";
}

//------------------------------------------------------------------------------
// Address: 0x101E0970
// Name: public: static char const __near * CGammaDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGammaDialog::GetPanelClassName()
{
  return "CGammaDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101E0980
// Name: public: static char const __near * COptionsSubVideoAdvancedDlg::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubVideoAdvancedDlg::GetPanelClassName()
{
  return "COptionsSubVideoAdvancedDlg";
}

//------------------------------------------------------------------------------
// Address: 0x101E0990
// Name: public: void COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(class vgui::ComboBox __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(
        COptionsSubVideoAdvancedDlg *this,
        vgui::ComboBox *combo,
        int iItem)
{
  wchar_t newText[512]; // [esp+8h] [ebp-800h] BYREF
  wchar_t text[512]; // [esp+408h] [ebp-400h] BYREF

  vgui::ComboBox::GetItemText(this: combo, itemID: iItem, text, bufLenInBytes: 1024);
  _snwprintf(string: newText, count: 0x200u, format: L"%s *", text);
  combo->UpdateItem(this: combo, a2: iItem, a3: newText, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E0A00
// Name: public: void COptionsSubVideoAdvancedDlg::MarkDefaultSettingsAsRecommended(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::MarkDefaultSettingsAsRecommended(COptionsSubVideoAdvancedDlg *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  vgui::ComboBox *m_pDXLevel; // ecx
  int (__thiscall *GetItemCount)(vgui::ComboBox *); // edx
  int v6; // ebx
  KeyValues *ItemUserData; // eax
  int Int; // ebx
  int v9; // eax
  vgui::ComboBox *v10; // ecx
  bool v11; // zf
  int v12; // ebx
  int (__thiscall *v13)(vgui::ComboBox *); // edx
  int v14; // ebx
  int v15; // ebx
  vgui::ComboBox *m_pFilteringMode; // ebx
  int m_nNumAAModes; // edx
  int v18; // eax
  int *p_m_nQualityLevel; // ecx
  vgui::ComboBox *m_pAntialiasingMode; // ebx
  vgui::ComboBox *m_pShadowDetail; // ebx
  vgui::ComboBox *m_pShaderDetail; // ebx
  vgui::ComboBox *m_pWaterDetail; // ebx
  vgui::ComboBox *m_pVSync; // ebx
  vgui::ComboBox *m_pHDR; // ebx
  vgui::ComboBox *m_pColorCorrection; // ebx
  vgui::ComboBox *m_pMotionBlur; // edi
  int v28; // ebx
  int v29; // [esp-Ch] [ebp-85Ch]
  int v30; // [esp-Ch] [ebp-85Ch]
  BOOL v31; // [esp-Ch] [ebp-85Ch]
  int v32; // [esp-Ch] [ebp-85Ch]
  BOOL v33; // [esp-4h] [ebp-854h]
  unsigned __int16 string[512]; // [esp+Ch] [ebp-844h] BYREF
  wchar_t text[512]; // [esp+40Ch] [ebp-444h] BYREF
  vgui::ComboBox *v36; // [esp+80Ch] [ebp-44h]
  int nAnisotropicLevel; // [esp+810h] [ebp-40h]
  int nMotionBlur; // [esp+814h] [ebp-3Ch]
  int nWaterUseRealtimeReflection; // [esp+818h] [ebp-38h]
  int nAASamples; // [esp+81Ch] [ebp-34h]
  int nRenderToTextureShadows; // [esp+820h] [ebp-30h]
  int nForceTrilinear; // [esp+824h] [ebp-2Ch]
  int nAAQuality; // [esp+828h] [ebp-28h]
  int nWaterUseEntityReflection; // [esp+82Ch] [ebp-24h]
  int nShadowDepthTextureShadows; // [esp+830h] [ebp-20h]
  int nColorCorrection; // [esp+834h] [ebp-1Ch]
  int nReduceFillRate; // [esp+838h] [ebp-18h]
  int nMatVSync; // [esp+83Ch] [ebp-14h]
  int nRootLOD; // [esp+840h] [ebp-10h]
  int nDXLevel; // [esp+844h] [ebp-Ch]
  int nSkipLevels; // [esp+848h] [ebp-8h]
  int i; // [esp+84Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "config");
  else
    v3 = nullptr;
  materials->GetRecommendedConfigurationInfo(this: materials, a2: 0, a3: v3);
  nSkipLevels = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_picmip", defaultValue: 0);
  nAnisotropicLevel = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_forceaniso", defaultValue: 1);
  nForceTrilinear = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_trilinear", defaultValue: 0);
  nAASamples = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_antialias", defaultValue: 0);
  nAAQuality = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_aaquality", defaultValue: 0);
  nRenderToTextureShadows = KeyValues::GetInt(this: v3, keyName: "ConVar.r_shadowrendertotexture", defaultValue: 0);
  nShadowDepthTextureShadows = KeyValues::GetInt(this: v3, keyName: "ConVar.r_flashlightdepthtexture", defaultValue: 0);
  nWaterUseRealtimeReflection = KeyValues::GetInt(this: v3, keyName: "ConVar.r_waterforceexpensive", defaultValue: 0);
  nWaterUseEntityReflection = KeyValues::GetInt(
                                this: v3,
                                keyName: "ConVar.r_waterforcereflectentities",
                                defaultValue: 0);
  nMatVSync = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_vsync", defaultValue: 1);
  nRootLOD = KeyValues::GetInt(this: v3, keyName: "ConVar.r_rootlod", defaultValue: 0);
  nReduceFillRate = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_reducefillrate", defaultValue: 0);
  nDXLevel = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_dxlevel", defaultValue: 0);
  nColorCorrection = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_colorcorrection", defaultValue: 0);
  nMotionBlur = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_motion_blur_enabled", defaultValue: 0);
  if ( this->m_pDXLevel->GetItemCount(this: this->m_pDXLevel) > 1 )
  {
    m_pDXLevel = this->m_pDXLevel;
    GetItemCount = m_pDXLevel->GetItemCount;
    v6 = 0;
    i = 0;
    if ( GetItemCount(this: m_pDXLevel) > 0 )
    {
      while ( 1 )
      {
        ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pDXLevel, itemID: v6);
        Int = KeyValues::GetInt(this: ItemUserData, keyName: "dxlevel", defaultValue: 0);
        v9 = KeyValues::GetInt(this: v3, keyName: "ConVar.mat_dxlevel", defaultValue: 0);
        v10 = this->m_pDXLevel;
        v11 = Int == v9;
        v12 = i;
        if ( v11 )
          break;
        v13 = v10->GetItemCount;
        v6 = ++i;
        if ( i >= v13(this: v10) )
          goto LABEL_10;
      }
      v36 = this->m_pDXLevel;
      vgui::ComboBox::GetItemText(this: v10, itemID: i, text, bufLenInBytes: 1024);
      _snwprintf(string, count: 0x200u, format: L"%s *", text);
      v36->UpdateItem(this: v36, a2: v12, a3: string, a4: nullptr);
    }
  }
LABEL_10:
  v14 = 2 - nRootLOD;
  v29 = 2 - nRootLOD;
  nRootLOD = (int)this->m_pModelDetail;
  vgui::ComboBox::GetItemText(this: (vgui::ComboBox *)nRootLOD, itemID: v29, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  (*(void (__thiscall **)(int, int, wchar_t *, _DWORD))(*(_DWORD *)nRootLOD + 1172))(
    a1: nRootLOD,
    a2: v14,
    a3: text,
    a4: 0);
  v15 = 2 - nSkipLevels;
  v30 = 2 - nSkipLevels;
  nSkipLevels = (int)this->m_pTextureDetail;
  vgui::ComboBox::GetItemText(this: (vgui::ComboBox *)nSkipLevels, itemID: v30, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  (*(void (__thiscall **)(int, int, wchar_t *, _DWORD))(*(_DWORD *)nSkipLevels + 1172))(
    a1: nSkipLevels,
    a2: v15,
    a3: text,
    a4: 0);
  switch ( nAnisotropicLevel )
  {
    case 2:
      COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(this, combo: this->m_pFilteringMode, iItem: 2);
      break;
    case 4:
      COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(this, combo: this->m_pFilteringMode, iItem: 3);
      break;
    case 8:
      COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(this, combo: this->m_pFilteringMode, iItem: 4);
      break;
    case 16:
      COptionsSubVideoAdvancedDlg::SetComboItemAsRecommended(this, combo: this->m_pFilteringMode, iItem: 5);
      break;
    default:
      m_pFilteringMode = this->m_pFilteringMode;
      if ( nForceTrilinear != 0 )
      {
        vgui::ComboBox::GetItemText(this: m_pFilteringMode, itemID: 1, text: string, bufLenInBytes: 1024);
        _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
        m_pFilteringMode->UpdateItem(this: m_pFilteringMode, a2: 1, a3: text, a4: nullptr);
      }
      else
      {
        vgui::ComboBox::GetItemText(this: m_pFilteringMode, itemID: 0, text: string, bufLenInBytes: 1024);
        _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
        m_pFilteringMode->UpdateItem(this: m_pFilteringMode, a2: 0, a3: text, a4: nullptr);
      }
      break;
  }
  m_nNumAAModes = this->m_nNumAAModes;
  v18 = 0;
  if ( m_nNumAAModes <= 0 )
  {
LABEL_23:
    i = 0;
  }
  else
  {
    p_m_nQualityLevel = &this->m_nAAModes[0].m_nQualityLevel;
    while ( *(p_m_nQualityLevel - 1) != nAASamples || *p_m_nQualityLevel != nAAQuality )
    {
      ++v18;
      p_m_nQualityLevel += 2;
      if ( v18 >= m_nNumAAModes )
        goto LABEL_23;
    }
    i = v18;
  }
  m_pAntialiasingMode = this->m_pAntialiasingMode;
  vgui::ComboBox::GetItemText(this: m_pAntialiasingMode, itemID: i, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pAntialiasingMode->UpdateItem(this: m_pAntialiasingMode, a2: i, a3: text, a4: nullptr);
  m_pShadowDetail = this->m_pShadowDetail;
  if ( nShadowDepthTextureShadows != 0 )
  {
    vgui::ComboBox::GetItemText(this: m_pShadowDetail, itemID: 2, text: string, bufLenInBytes: 1024);
    _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
    m_pShadowDetail->UpdateItem(this: m_pShadowDetail, a2: 2, a3: text, a4: nullptr);
  }
  else if ( nRenderToTextureShadows != 0 )
  {
    vgui::ComboBox::GetItemText(this: m_pShadowDetail, itemID: 1, text: string, bufLenInBytes: 1024);
    _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
    m_pShadowDetail->UpdateItem(this: m_pShadowDetail, a2: 1, a3: text, a4: nullptr);
  }
  else
  {
    vgui::ComboBox::GetItemText(this: m_pShadowDetail, itemID: 0, text: string, bufLenInBytes: 1024);
    _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
    m_pShadowDetail->UpdateItem(this: m_pShadowDetail, a2: 0, a3: text, a4: nullptr);
  }
  m_pShaderDetail = this->m_pShaderDetail;
  v33 = nReduceFillRate == 0;
  nReduceFillRate = v33;
  vgui::ComboBox::GetItemText(this: m_pShaderDetail, itemID: v33, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pShaderDetail->UpdateItem(this: m_pShaderDetail, a2: nReduceFillRate, a3: text, a4: nullptr);
  m_pWaterDetail = this->m_pWaterDetail;
  if ( nWaterUseRealtimeReflection != 0 )
  {
    if ( nWaterUseEntityReflection != 0 )
    {
      vgui::ComboBox::GetItemText(this: m_pWaterDetail, itemID: 2, text: string, bufLenInBytes: 1024);
      _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
      ((void (__thiscall *)(vgui::ComboBox *, int))m_pWaterDetail->UpdateItem)(a1: m_pWaterDetail, a2: 2);
    }
    else
    {
      vgui::ComboBox::GetItemText(this: m_pWaterDetail, itemID: 1, text: string, bufLenInBytes: 1024);
      _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
      ((void (__thiscall *)(vgui::ComboBox *, int))m_pWaterDetail->UpdateItem)(a1: m_pWaterDetail, a2: 1);
    }
  }
  else
  {
    vgui::ComboBox::GetItemText(this: m_pWaterDetail, itemID: 0, text: string, bufLenInBytes: 1024);
    _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
    ((void (__thiscall *)(vgui::ComboBox *, _DWORD))m_pWaterDetail->UpdateItem)(a1: m_pWaterDetail, a2: 0);
  }
  m_pVSync = this->m_pVSync;
  v31 = nMatVSync != 0;
  nMatVSync = v31;
  vgui::ComboBox::GetItemText(this: m_pVSync, itemID: v31, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pVSync->UpdateItem(this: m_pVSync, a2: nMatVSync, a3: text, a4: nullptr);
  m_pHDR = this->m_pHDR;
  v32 = nDXLevel < 90 ? 0 : 2;
  nDXLevel = v32;
  vgui::ComboBox::GetItemText(this: m_pHDR, itemID: v32, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pHDR->UpdateItem(this: m_pHDR, a2: nDXLevel, a3: text, a4: nullptr);
  m_pColorCorrection = this->m_pColorCorrection;
  vgui::ComboBox::GetItemText(this: m_pColorCorrection, itemID: nColorCorrection, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pColorCorrection->UpdateItem(this: m_pColorCorrection, a2: nColorCorrection, a3: text, a4: nullptr);
  m_pMotionBlur = this->m_pMotionBlur;
  v28 = nMotionBlur;
  vgui::ComboBox::GetItemText(this: m_pMotionBlur, itemID: nMotionBlur, text: string, bufLenInBytes: 1024);
  _snwprintf(string: text, count: 0x200u, format: L"%s *", string);
  m_pMotionBlur->UpdateItem(this: m_pMotionBlur, a2: v28, a3: text, a4: nullptr);
  KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101E11E0
// Name: public: bool COptionsSubVideoAdvancedDlg::RequiresRestart(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COptionsSubVideoAdvancedDlg::RequiresRestart(COptionsSubVideoAdvancedDlg *this)
{
  CGameUI *v2; // eax
  CGameUI *v3; // eax
  CGameUI *v4; // eax
  KeyValues *ActiveItemUserData; // eax
  int m_nValue; // edi
  bool result; // al
  int v8; // edi
  ConVarRef mat_hdr_level; // [esp+8h] [ebp-10h] BYREF
  ConVarRef mat_dxlevel; // [esp+10h] [ebp-8h] BYREF

  v2 = GameUI();
  result = false;
  if ( v2->IsInLevel(this: v2) )
  {
    v3 = GameUI();
    if ( !CGameUI::IsInBackgroundLevel(this: v3) )
    {
      v4 = GameUI();
      if ( CGameUI::IsInMultiplayer(this: v4) )
      {
        ConVarRef::ConVarRef(this: &mat_dxlevel, pName: "mat_dxlevel");
        ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pDXLevel);
        if ( ActiveItemUserData != nullptr )
        {
          m_nValue = mat_dxlevel.m_pConVarState->m_Value.m_nValue;
          if ( m_nValue != KeyValues::GetInt(this: ActiveItemUserData, keyName: "dxlevel", defaultValue: 0) )
            return true;
        }
        if ( this->m_pHDR->IsEnabled(this: this->m_pHDR) )
        {
          ConVarRef::ConVarRef(this: &mat_hdr_level, pName: "mat_hdr_level");
          v8 = mat_hdr_level.m_pConVarState->m_Value.m_nValue;
          if ( v8 != vgui::ComboBox::GetActiveItem(this: this->m_pHDR) )
            return true;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E12A0
// Name: private: void COptionsSubVideo::PrepareResolutionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::PrepareResolutionList(COptionsSubVideo *this)
{
  const MaterialSystem_Config_t *v2; // eax
  vgui::ComboBox *m_pWindowed; // ecx
  int ActiveItem; // eax
  bool v5; // zf
  bool v6; // sf
  void (__thiscall *GetDesktopResolution)(IGameUIFuncs *, int *, int *); // eax
  int v8; // edi
  vmode_s *v9; // eax
  vmode_s *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  int v13; // ebx
  AspectRatioMode_t m_Mode; // edi
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  char sz[256]; // [esp+Ch] [ebp-22Ch] BYREF
  char pDest[256]; // [esp+10Ch] [ebp-12Ch] BYREF
  int desktopHeight; // [esp+20Ch] [ebp-2Ch] BYREF
  int desktopWidth; // [esp+210h] [ebp-28h] BYREF
  BOOL bFoundWidescreen; // [esp+214h] [ebp-24h]
  int currentWidth; // [esp+218h] [ebp-20h] BYREF
  int i; // [esp+21Ch] [ebp-1Ch]
  int currentHeight; // [esp+220h] [ebp-18h] BYREF
  const MaterialSystem_Config_t *config; // [esp+224h] [ebp-14h]
  int count; // [esp+228h] [ebp-10h] BYREF
  int selectedItemID; // [esp+22Ch] [ebp-Ch]
  vmode_s *plist; // [esp+230h] [ebp-8h] BYREF
  bool bWindowed; // [esp+237h] [ebp-1h]

  this->m_pMode->GetText_2(this: this->m_pMode, a2: sz, a3: 256);
  currentWidth = 0;
  currentHeight = 0;
  sscanf(string: sz, format: "%i x %i", &currentWidth, &currentHeight);
  vgui::ComboBox::RemoveAll(this: this->m_pMode);
  this->m_pAspectRatio->SetItemEnabled(this: this->m_pAspectRatio, a2: 1, a3: false);
  this->m_pAspectRatio->SetItemEnabled(this: this->m_pAspectRatio, a2: 2, a3: false);
  plist = nullptr;
  count = 0;
  gameuifuncs->GetVideoModes(this: gameuifuncs, a2: &plist, a3: &count);
  v2 = materials->GetCurrentConfigForVideoCard(this: materials);
  m_pWindowed = this->m_pWindowed;
  config = v2;
  ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pWindowed);
  v5 = ActiveItem == 0;
  v6 = ActiveItem < 0;
  GetDesktopResolution = gameuifuncs->GetDesktopResolution;
  bWindowed = !v6 && !v5;
  GetDesktopResolution(this: gameuifuncs, a2: &desktopWidth, a3: &desktopHeight);
  v8 = -1;
  LOBYTE(bFoundWidescreen) = 0;
  selectedItemID = -1;
  i = 0;
  if ( count > 0 )
  {
    v9 = plist;
    do
    {
      if ( v9->width == 1280 && v9->height == 1024 )
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%i x %i (LCD)", 1280, 1024);
      else
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%i x %i", v9->width, v9->height);
      v10 = plist;
      if ( !bWindowed || plist->width <= desktopWidth && plist->height <= desktopHeight )
      {
        v11 = 99999.0;
        v12 = (float)plist->width / (float)plist->height;
        v13 = -1;
        m_Mode = ASPECT_RATIO_4x3;
        v15 = fabs(*(float *)&dword_105B168C - v12);
        if ( v15 < 99999.0 )
        {
          m_Mode = g_RatioToAspectModes[0].m_Mode;
          v11 = v15;
        }
        v16 = fabs(*(float *)&dword_105B1694 - v12);
        if ( v11 > v16 )
        {
          m_Mode = dword_105B1690;
          v11 = v16;
        }
        v17 = fabs(*(float *)&dword_105B169C - v12);
        if ( v11 > v17 )
        {
          m_Mode = dword_105B1698;
          v11 = v17;
        }
        if ( v11 > fabs(*(float *)&dword_105B16A4 - v12) )
          m_Mode = dword_105B16A0;
        if ( m_Mode > ASPECT_RATIO_4x3 )
        {
          this->m_pAspectRatio->SetItemEnabled(this: this->m_pAspectRatio, a2: m_Mode, a3: true);
          LOBYTE(bFoundWidescreen) = 1;
        }
        if ( m_Mode == vgui::ComboBox::GetActiveItem(this: this->m_pAspectRatio) )
          v13 = this->m_pMode->AddItem_2(this: this->m_pMode, a2: pDest, a3: nullptr);
        v10 = plist;
        if ( plist->width == currentWidth && plist->height == currentHeight
          || selectedItemID == -1
          && plist->width == config->m_VideoMode.m_Width
          && plist->height == config->m_VideoMode.m_Height )
        {
          selectedItemID = v13;
        }
      }
      v9 = v10 + 1;
      ++i;
      plist = v9;
    }
    while ( i < count );
    v8 = selectedItemID;
  }
  this->m_pAspectRatio->SetEnabled(this: this->m_pAspectRatio, a2: bFoundWidescreen);
  this->m_nSelectedMode = v8;
  if ( v8 == -1 )
  {
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%d x %d", config->m_VideoMode.m_Width, config->m_VideoMode.m_Height);
    this->m_pMode->SetText(this: this->m_pMode, a2: pDest);
  }
  else
  {
    this->m_pMode->ActivateItem(this: this->m_pMode, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E15A0
// Name: private: void COptionsSubVideo::SetCurrentResolutionComboItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::SetCurrentResolutionComboItem(COptionsSubVideo *this)
{
  const MaterialSystem_Config_t *v2; // eax
  int v3; // edx
  vmode_s *v4; // ecx
  int height; // edi
  char sz[256]; // [esp+Ch] [ebp-108h] BYREF
  int count; // [esp+10Ch] [ebp-8h] BYREF
  vmode_s *plist; // [esp+110h] [ebp-4h] BYREF

  plist = nullptr;
  count = 0;
  gameuifuncs->GetVideoModes(this: gameuifuncs, a2: &plist, a3: &count);
  v2 = materials->GetCurrentConfigForVideoCard(this: materials);
  v3 = 0;
  if ( count > 0 )
  {
    v4 = plist;
    while ( 1 )
    {
      if ( v4->width == v2->m_VideoMode.m_Width )
      {
        height = v4->height;
        if ( height == v2->m_VideoMode.m_Height )
          break;
      }
      ++v3;
      plist = ++v4;
      if ( v3 >= count )
        return;
    }
    if ( v3 != -1 )
    {
      if ( v4->width == 1280 && height == 1024 )
        V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%i x %i (LCD)", 1280, 1024);
      else
        V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%i x %i", v4->width, v4->height);
      this->m_pMode->SetText(this: this->m_pMode, a2: sz);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1670
// Name: public: virtual void COptionsSubVideo::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::PerformLayout(COptionsSubVideo *this)
{
  const MaterialSystem_Config_t *v2; // eax

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pGammaButton != nullptr )
  {
    v2 = materials->GetCurrentConfigForVideoCard(this: materials);
    this->m_pGammaButton->SetEnabled(this: this->m_pGammaButton, a2: (v2->m_Flags & 1) == 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E16B0
// Name: private: virtual void COptionsSubVideo::OnTextChanged(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OnTextChanged(COptionsSubVideo *this, vgui::ComboBox *pPanel, const char *pszText)
{
  const MaterialSystem_Config_t *v4; // edi
  int ActiveItem; // eax
  const char *v6; // edx
  int h; // [esp+4h] [ebp-4h] BYREF

  if ( pPanel == this->m_pMode )
  {
    v4 = materials->GetCurrentConfigForVideoCard(this: materials);
    ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pMode);
    v6 = pszText;
    this->m_nSelectedMode = ActiveItem;
    pPanel = nullptr;
    h = 0;
    sscanf(string: v6, format: "%i x %i", &pPanel, &h);
    if ( (vgui::ComboBox *)v4->m_VideoMode.m_Width != pPanel || v4->m_VideoMode.m_Height != h )
      this->OnDataChanged(this);
  }
  else if ( pPanel == this->m_pAspectRatio )
  {
    COptionsSubVideo::PrepareResolutionList(this);
  }
  else if ( pPanel == this->m_pWindowed )
  {
    COptionsSubVideo::PrepareResolutionList(this);
    this->OnDataChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1760
// Name: private: virtual void COptionsSubVideo::LaunchBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::LaunchBenchmark(COptionsSubVideo *this)
{
  CCStrike15BasePanel *v1; // eax

  v1 = BasePanel();
  CBaseModPanel::OnOpenBenchmarkDialog(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101E1770
// Name: protected: virtual void COptionsSubVideoThirdPartyCreditsDlg::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoThirdPartyCreditsDlg::ApplySchemeSettings(
        COptionsSubVideoThirdPartyCreditsDlg *this,
        vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/OptionsSubVideoThirdPartyDlg.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E17A0
// Name: public: virtual void COptionsSubVideoThirdPartyCreditsDlg::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoThirdPartyCreditsDlg::OnKeyCodeTyped(
        CMultiplayerAdvancedDialog *this,
        ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->Close(this);
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x101E1800
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubVideo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubVideo::GetMessageMap(COptionsSubVideo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubVideo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideo::GetMessageMap'::`2'::s_pMap;
  `COptionsSubVideo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
  `COptionsSubVideo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1830
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubVideo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubVideo::GetAnimMap(COptionsSubVideo *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubVideo");
}

//------------------------------------------------------------------------------
// Address: 0x101E1840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubVideo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubVideo::GetKBMap(COptionsSubVideo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubVideo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideo::GetKBMap'::`2'::s_pMap;
  `COptionsSubVideo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideo");
  `COptionsSubVideo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1870
// Name: public: virtual void COptionsSubVideo::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OnResetData(COptionsSubVideo *this)
{
  const MaterialSystem_Config_t *v2; // edi

  this->m_bRequireRestart = false;
  v2 = materials->GetCurrentConfigForVideoCard(this: materials);
  this->m_pWindowed->ActivateItem(this: this->m_pWindowed, a2: v2->m_Flags & 1);
  this->m_pGammaButton->SetEnabled(this: this->m_pGammaButton, a2: (v2->m_Flags & 1) == 0);
  COptionsSubVideo::SetCurrentResolutionComboItem(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E18D0
// Name: public: virtual void COptionsSubVideo::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OnApplyChanges(COptionsSubVideo *this)
{
  INetChannelInfo *v2; // eax
  const char *v3; // eax
  const char *v4; // edi
  vgui::Panel *v5; // eax
  int m_nSelectedMode; // eax
  bool v7; // bl
  const MaterialSystem_Config_t *v8; // eax
  char szCmd[256]; // [esp+Ch] [ebp-208h] BYREF
  char sz[256]; // [esp+10Ch] [ebp-108h] BYREF
  int width; // [esp+20Ch] [ebp-8h] BYREF
  int height; // [esp+210h] [ebp-4h] BYREF

  if ( this->RequiresRestart(this) )
  {
    v2 = engine->GetNetChannelInfo(this: engine);
    if ( v2 != nullptr )
    {
      v3 = v2->GetAddress(this: v2);
      v4 = v3;
      if ( v3 != nullptr )
      {
        if ( V_strncmp(s1: v3, s2: "127.0.0.1", count: 9) != 0 && V_strncmp(s1: v4, s2: "localhost", count: 9) != 0 )
          engine->ClientCmd_Unrestricted(this: engine, a2: "retry\n");
        else
          engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect\n");
      }
    }
  }
  if ( vgui::PHandle::Get(this: &this->m_hOptionsSubVideoAdvancedDlg) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hOptionsSubVideoAdvancedDlg);
    ((void (__thiscall *)(vgui::Panel *))v5->__vftable[1].SetPaintEnabled)(a1: v5);
  }
  m_nSelectedMode = this->m_nSelectedMode;
  if ( m_nSelectedMode == -1 )
    this->m_pMode->GetText_2(this: this->m_pMode, a2: sz, a3: 256);
  else
    vgui::ComboBox::GetItemText(this: this->m_pMode, itemID: m_nSelectedMode, text: sz, bufLenInBytes: 256);
  width = 0;
  height = 0;
  sscanf(string: sz, format: "%i x %i", &width, &height);
  v7 = vgui::ComboBox::GetActiveItem(this: this->m_pWindowed) > 0;
  v8 = materials->GetCurrentConfigForVideoCard(this: materials);
  if ( v8->m_VideoMode.m_Width != width || v8->m_VideoMode.m_Height != height || (v8->m_Flags & 1) != v7 )
  {
    V_snprintf(pDest: szCmd, maxLen: 0x100u, pFormat: "mat_setvideomode %i %i %i\n", width, height, v7);
    engine->ClientCmd_Unrestricted(this: engine, a2: szCmd);
  }
  engine->ClientCmd_Unrestricted(this: engine, a2: "mat_savechanges\n");
}

//------------------------------------------------------------------------------
// Address: 0x101E1A70
// Name: public: virtual bool COptionsSubVideo::RequiresRestart(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COptionsSubVideo::RequiresRestart(COptionsSubVideo *this)
{
  COptionsSubVideoAdvancedDlg *v2; // eax
  bool v3; // zf
  bool result; // al

  if ( vgui::PHandle::Get(this: &this->m_hOptionsSubVideoAdvancedDlg) == nullptr )
    return this->m_bRequireRestart;
  v2 = (COptionsSubVideoAdvancedDlg *)vgui::PHandle::Get(this: &this->m_hOptionsSubVideoAdvancedDlg);
  v3 = !COptionsSubVideoAdvancedDlg::RequiresRestart(this: v2);
  result = true;
  if ( v3 )
    return this->m_bRequireRestart;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1AB0
// Name: public: COptionsSubVideoThirdPartyCreditsDlg::COptionsSubVideoThirdPartyCreditsDlg(unsigned int)
// Source: json
//------------------------------------------------------------------------------
COptionsSubVideoThirdPartyCreditsDlg *__thiscall COptionsSubVideoThirdPartyCreditsDlg::COptionsSubVideoThirdPartyCreditsDlg(
        COptionsSubVideoThirdPartyCreditsDlg *this,
        unsigned int hParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager *v7; // ebx
  unsigned int Scheme; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v12; // [esp-8h] [ebp-1Ch]
  vgui::ISchemeManager_vtbl *v13; // [esp+Ch] [ebp-8h]
  vgui::ISchemeManager_vtbl *v14; // [esp+10h] [ebp-4h]

  vgui::Frame::Frame(this, parent: nullptr, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COptionsSubVideoThirdPartyCreditsDlg_vtbl *)&COptionsSubVideoThirdPartyCreditsDlg::`vftable';
  if ( `COptionsSubVideoThirdPartyCreditsDlg::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoThirdPartyCreditsDlg::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
    v3->pfnClassName = COptionsSubVideoThirdPartyCreditsDlg::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COptionsSubVideoThirdPartyCreditsDlg::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoThirdPartyCreditsDlg::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
    v4->pfnClassName = COptionsSubVideoThirdPartyCreditsDlg::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COptionsSubVideoThirdPartyCreditsDlg::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoThirdPartyCreditsDlg::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
    v5->pfnClassName = COptionsSubVideoThirdPartyCreditsDlg::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetProportional(this, state: true);
  vgui::Frame::SetTitle(this, title: "#GameUI_ThirdPartyVideo_Title", surfaceTitle: true);
  v6 = g_pVGuiSchemeManager;
  v7 = g_pVGuiSchemeManager;
  v13 = g_pVGuiSchemeManager->__vftable;
  v14 = g_pVGuiSchemeManager->__vftable;
  Scheme = vgui::Panel::GetScheme(this);
  v12 = ((int (__thiscall *)(vgui::ISchemeManager *, unsigned int))v14->GetProportionalScaledValueEx)(
          a1: v6,
          a2: Scheme);
  v9 = vgui::Panel::GetScheme(this);
  v10 = ((int (__thiscall *)(vgui::ISchemeManager *, unsigned int, int, int))v13->GetProportionalScaledValueEx)(
          a1: v7,
          a2: v9,
          a3: 500,
          a4: v12);
  vgui::Panel::SetSize(this, wide: v10, tall: 200);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E1BF0
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap(
        COptionsSubVideoThirdPartyCreditsDlg *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap'::`2'::s_pMap;
  `COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
  `COptionsSubVideoThirdPartyCreditsDlg::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1C20
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubVideoThirdPartyCreditsDlg::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubVideoThirdPartyCreditsDlg::GetAnimMap(
        COptionsSubVideoThirdPartyCreditsDlg *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
}

//------------------------------------------------------------------------------
// Address: 0x101E1C30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubVideoThirdPartyCreditsDlg::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubVideoThirdPartyCreditsDlg::GetKBMap(
        COptionsSubVideoThirdPartyCreditsDlg *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubVideoThirdPartyCreditsDlg::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideoThirdPartyCreditsDlg::GetKBMap'::`2'::s_pMap;
  `COptionsSubVideoThirdPartyCreditsDlg::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideoThirdPartyCreditsDlg");
  `COptionsSubVideoThirdPartyCreditsDlg::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E1CC0
// Name: private: virtual void COptionsSubVideo::OpenThirdPartyVideoCreditsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OpenThirdPartyVideoCreditsDialog(COptionsSubVideo *this)
{
  COptionsSubVideoThirdPartyCreditsDlg *v2; // edi
  unsigned int v3; // eax
  COptionsSubVideoThirdPartyCreditsDlg *v4; // eax
  vgui::Panel *v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_OptionsSubVideoThirdPartyCreditsDlg) == nullptr )
  {
    v2 = (COptionsSubVideoThirdPartyCreditsDlg *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
    {
      v3 = this->GetVParent(this);
      v4 = COptionsSubVideoThirdPartyCreditsDlg::COptionsSubVideoThirdPartyCreditsDlg(this: v2, hParent: v3);
    }
    else
    {
      v4 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_OptionsSubVideoThirdPartyCreditsDlg, pPanel: v4);
  }
  v5 = vgui::PHandle::Get(this: &this->m_OptionsSubVideoThirdPartyCreditsDlg);
  v5->__vftable[1].OnTick(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101E1D30
// Name: public: static void COptionsSubVideo::PanelMessageFunc_OpenGammaDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_OpenGammaDialog::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_OpenGammaDialog::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_OpenGammaDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OpenGammaDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1DC0
// Name: public: static void COptionsSubVideo::PanelMessageFunc_OnDataChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_OnDataChanged::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_OnDataChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_OnDataChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1E50
// Name: public: static void COptionsSubVideo::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000002LL;
    LODWORD(v4.m[2][2]) = "panel";
    LODWORD(v4.m[2][3]) = 1;
    LODWORD(v4.m[3][0]) = "text";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1EF0
// Name: public: static void COptionsSubVideo::PanelMessageFunc_OpenAdvanced::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_OpenAdvanced::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_OpenAdvanced::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_OpenAdvanced::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubVideo::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OpenAdvanced";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1F80
// Name: public: static void COptionsSubVideo::PanelMessageFunc_LaunchBenchmark::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_LaunchBenchmark::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_LaunchBenchmark::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_LaunchBenchmark::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Label::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LaunchBenchmark";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2010
// Name: public: static void COptionsSubVideo::PanelMessageFunc_OpenThirdPartyVideoCreditsDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideo::PanelMessageFunc_OpenThirdPartyVideoCreditsDialog::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideo::PanelMessageFunc_OpenThirdPartyVideoCreditsDialog::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideo::PanelMessageFunc_OpenThirdPartyVideoCreditsDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubVideo::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OpenThirdPartyVideoCreditsDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E20A0
// Name: public: static void CGammaDialog::PanelMessageFunc_OnGammaChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGammaDialog::PanelMessageFunc_OnGammaChanged::InitVar(int a1@<ebp>)
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
  if ( !`CGammaDialog::PanelMessageFunc_OnGammaChanged::InitVar'::`2'::bAdded )
  {
    `CGammaDialog::PanelMessageFunc_OnGammaChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2140
// Name: public: static void CGammaDialog::PanelMessageFunc_OnOK::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGammaDialog::PanelMessageFunc_OnOK::InitVar(int a1@<ebp>)
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
  if ( !`CGammaDialog::PanelMessageFunc_OnOK::InitVar'::`2'::bAdded )
  {
    `CGammaDialog::PanelMessageFunc_OnOK::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OK";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E21D0
// Name: public: static void CGammaDialog::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGammaDialog::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
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
  if ( !`CGammaDialog::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `CGammaDialog::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2270
// Name: public: static void CGammaDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGammaDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CGammaDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CGammaDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2310
// Name: public: static void COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E23B0
// Name: public: static void COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnGameUIHidden::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnGameUIHidden::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnGameUIHidden::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnGameUIHidden::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GameUIHidden";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2440
// Name: public: static void COptionsSubVideoAdvancedDlg::PanelMessageFunc_ResetDXLevelCombo::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideoAdvancedDlg::PanelMessageFunc_ResetDXLevelCombo::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideoAdvancedDlg::PanelMessageFunc_ResetDXLevelCombo::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideoAdvancedDlg::PanelMessageFunc_ResetDXLevelCombo::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetDXLevelCombo";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E24D0
// Name: public: static void COptionsSubVideoAdvancedDlg::PanelMessageFunc_OK_Confirmed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVideoAdvancedDlg::PanelMessageFunc_OK_Confirmed::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVideoAdvancedDlg::PanelMessageFunc_OK_Confirmed::InitVar'::`2'::bAdded )
  {
    `COptionsSubVideoAdvancedDlg::PanelMessageFunc_OK_Confirmed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OK_Confirmed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2560
// Name: public: COptionsSubVideo::COptionsSubVideo(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubVideo *__thiscall COptionsSubVideo::COptionsSubVideo(COptionsSubVideo *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::URLButton *v22; // eax
  vgui::URLButton *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  int v29; // ebx
  int v30; // edi
  const MaterialSystem_Config_t *v31; // eax
  float v32; // xmm2_4
  float v33; // xmm0_4
  AspectRatioMode_t m_Mode; // eax
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  vgui::ComboBox *m_pAspectRatio; // ecx
  __int32 v39; // eax
  bool v40; // zf
  vgui::ComboBox_vtbl *v41; // eax
  vgui::ComboBox *v42; // eax
  vgui::ComboBox *v43; // eax
  char pszAspectName[3][64]; // [esp+Ch] [ebp-C0h] BYREF
  int savedregs; // [esp+CCh] [ebp+0h] BYREF
  int i16x10ItemID; // [esp+D4h] [ebp+8h]

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubVideo_vtbl *)&COptionsSubVideo::`vftable';
  if ( `COptionsSubVideo::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideo::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideo");
    v3->pfnClassName = COptionsSubVideo::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubVideo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubVideo::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubVideo");
    v4->pfnClassName = COptionsSubVideo::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubVideo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideo::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideo");
    v5->pfnClassName = COptionsSubVideo::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubVideo::PanelMessageFunc_OpenGammaDialog::InitVar();
  COptionsSubVideo::PanelMessageFunc_OnDataChanged::InitVar();
  COptionsSubVideo::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  COptionsSubVideo::PanelMessageFunc_OpenAdvanced::InitVar();
  COptionsSubVideo::PanelMessageFunc_LaunchBenchmark::InitVar();
  this->m_hOptionsSubVideoAdvancedDlg.m_iPanelID = -1;
  COptionsSubVideo::PanelMessageFunc_OpenThirdPartyVideoCreditsDialog::InitVar();
  this->m_OptionsSubVideoThirdPartyCreditsDlg.m_iPanelID = -1;
  this->m_bRequireRestart = false;
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "GammaButton",
           text: "#GameUI_AdjustGamma",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pGammaButton = v7;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "OpenGammaDialog");
  else
    v9 = nullptr;
  this->m_pGammaButton->SetCommand(this: this->m_pGammaButton, a2: v9);
  v10 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: this, panelName: "Resolution", numLines: 8, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pMode = v11;
  v12 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v12 != nullptr )
    v13 = vgui::ComboBox::ComboBox(this: v12, parent: this, panelName: "AspectRatio", numLines: 6, allowEdit: false);
  else
    v13 = nullptr;
  this->m_pAspectRatio = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "AdvancedButton",
            text: "#GameUI_AdvancedEllipsis",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pAdvanced = v15;
  v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v16 != nullptr )
    v17 = KeyValues::KeyValues(this: v16, setName: "OpenAdvanced");
  else
    v17 = nullptr;
  this->m_pAdvanced->SetCommand(this: this->m_pAdvanced, a2: v17);
  v18 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "BenchmarkButton",
            text: "#GameUI_LaunchBenchmark",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v19 = nullptr;
  this->m_pBenchmark = v19;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "LaunchBenchmark");
  else
    v21 = nullptr;
  this->m_pBenchmark->SetCommand(this: this->m_pBenchmark, a2: v21);
  v22 = (vgui::URLButton *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v22 != nullptr )
    v23 = vgui::URLButton::URLButton(
            this: v22,
            parent: this,
            panelName: "ThirdPartyVideoCredits",
            text: "#GameUI_ThirdPartyTechCredits",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v23 = nullptr;
  this->m_pThirdPartyCredits = v23;
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "OpenThirdPartyVideoCreditsDialog");
  else
    v25 = nullptr;
  this->m_pThirdPartyCredits->SetCommand(this: this->m_pThirdPartyCredits, a2: v25);
  v26 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#GameUI_AspectNormal");
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v26, a3: (char *)pszAspectName, a4: 32);
  v27 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#GameUI_AspectWide16x9");
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v27, a3: pszAspectName[1], a4: 32);
  v28 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#GameUI_AspectWide16x10");
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v28, a3: pszAspectName[2], a4: 32);
  v29 = this->m_pAspectRatio->AddItem_2(this: this->m_pAspectRatio, a2: (const char *)pszAspectName, a3: nullptr);
  v30 = this->m_pAspectRatio->AddItem_2(this: this->m_pAspectRatio, a2: pszAspectName[1], a3: nullptr);
  i16x10ItemID = this->m_pAspectRatio->AddItem_2(this: this->m_pAspectRatio, a2: pszAspectName[2], a3: nullptr);
  v31 = materials->GetCurrentConfigForVideoCard(this: materials);
  v32 = 99999.0;
  v33 = (float)v31->m_VideoMode.m_Width / (float)v31->m_VideoMode.m_Height;
  m_Mode = ASPECT_RATIO_4x3;
  v35 = fabs(*(float *)&dword_105B168C - v33);
  if ( v35 < 99999.0 )
  {
    m_Mode = g_RatioToAspectModes[0].m_Mode;
    v32 = v35;
  }
  v36 = fabs(*(float *)&dword_105B1694 - v33);
  if ( v32 > v36 )
  {
    m_Mode = dword_105B1690;
    v32 = v36;
  }
  v37 = fabs(*(float *)&dword_105B169C - v33);
  if ( v32 > v37 )
  {
    m_Mode = dword_105B1698;
    v32 = v37;
  }
  m_pAspectRatio = this->m_pAspectRatio;
  if ( v32 > fabs(*(float *)&dword_105B16A4 - v33) )
    m_Mode = dword_105B16A0;
  v39 = m_Mode - 1;
  if ( v39 != 0 )
  {
    v40 = v39 == 1;
    v41 = m_pAspectRatio->__vftable;
    if ( v40 )
      ((void (__stdcall *)(int))v41->ActivateItem)(a1: i16x10ItemID);
    else
      ((void (__stdcall *)(int))v41->ActivateItem)(a1: v29);
  }
  else
  {
    ((void (__stdcall *)(int))m_pAspectRatio->ActivateItem)(a1: v30);
  }
  v42 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v42 != nullptr )
    v43 = vgui::ComboBox::ComboBox(
            this: v42,
            parent: this,
            panelName: "DisplayModeCombo",
            numLines: 6,
            allowEdit: false);
  else
    v43 = nullptr;
  this->m_pWindowed = v43;
  v43->AddItem_2(this: v43, a2: "#GameUI_Fullscreen", a3: nullptr);
  this->m_pWindowed->AddItem_2(this: this->m_pWindowed, a2: "#GameUI_Windowed", a3: nullptr);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\OptionsSubVideo.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  COptionsSubVideo::PrepareResolutionList(this);
  if ( !g_pFullFileSystem->FileExists(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: "maps/test_hardware.bsp",
          a3: nullptr) )
    this->m_pBenchmark->SetVisible(this: this->m_pBenchmark, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E2A60
// Name: public: CGammaDialog::CGammaDialog(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CGammaDialog *__userpurge CGammaDialog::CGammaDialog@<eax>(
        CGammaDialog *this@<ecx>,
        int a2@<ebp>,
        unsigned int hParent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CCvarSlider *v7; // eax
  CCvarSlider *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  KeyValues *v15; // eax
  KeyValues *v16; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "OptionsSubVideoGammaDlg", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CGammaDialog_vtbl *)&CGammaDialog::`vftable';
  if ( `CGammaDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CGammaDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
    v4->pfnClassName = CGammaDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CGammaDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGammaDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CGammaDialog");
    v5->pfnClassName = CGammaDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CGammaDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGammaDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CGammaDialog");
    v6->pfnClassName = CGammaDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CGammaDialog::PanelMessageFunc_OnGammaChanged::InitVar();
  CGammaDialog::PanelMessageFunc_OnOK::InitVar();
  CGammaDialog::PanelMessageFunc_OnControlModified::InitVar(a1: a2);
  CGammaDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: a2);
  vgui::Frame::SetTitle(this, title: "#GameUI_AdjustGamma_Title", surfaceTitle: true);
  vgui::Panel::SetSize(this, wide: 400, tall: 260);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = CCvarSlider::CCvarSlider(
           this: v7,
           parent: this,
           panelName: "Gamma",
           caption: "#GameUI_Gamma",
           minValue: 1.6,
           maxValue: 2.5999999,
           cvarname: "mat_monitorgamma",
           bAllowOutOfRange: false);
  else
    v8 = nullptr;
  this->m_pGammaSlider = v8;
  v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "Gamma label", text: "#GameUI_Gamma");
  else
    v10 = nullptr;
  this->m_pGammaLabel = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "GammaEntry");
  else
    v12 = nullptr;
  this->m_pGammaEntry = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "OKButton",
            text: "#vgui_ok",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "OK");
  else
    v16 = nullptr;
  v14->SetCommand(this: v14, a2: v16);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/OptionsSubVideoGammaDlg.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  this->m_pGammaSlider->SetTickCaptions(this: this->m_pGammaSlider, a2: "#GameUI_Light", a3: "#GameUI_Dark");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E2CA0
// Name: public: virtual void CGammaDialog::OnGammaChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::OnGammaChanged(CGammaDialog *this, CCvarSlider *panel)
{
  CCvarSlider *m_pGammaSlider; // ecx

  m_pGammaSlider = this->m_pGammaSlider;
  if ( panel == m_pGammaSlider )
    CCvarSlider::ApplyChanges(this: m_pGammaSlider);
}

//------------------------------------------------------------------------------
// Address: 0x101E2CC0
// Name: public: virtual void CGammaDialog::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::OnOK(CGammaDialog *this)
{
  float v2; // xmm0_4
  void (__thiscall *Close)(vgui::Frame *); // edx

  v2 = (float)this->m_pGammaSlider->GetValue(this: this->m_pGammaSlider);
  Close = this->Close;
  this->m_flOriginalGamma = v2;
  Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E2CF0
// Name: public: virtual void CGammaDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::OnClose(CGammaDialog *this)
{
  this->m_pGammaSlider->SetValue(this: this->m_pGammaSlider, a2: (int)this->m_flOriginalGamma, a3: true);
  CCvarSlider::ApplyChanges(this: this->m_pGammaSlider);
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E2D30
// Name: public: virtual void CGammaDialog::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::OnTextChanged(CGammaDialog *this, vgui::TextEntry *panel)
{
  long double v3; // st7
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  char buf[64]; // [esp+10h] [ebp-40h] BYREF
  float fValue; // [esp+58h] [ebp+8h]

  if ( panel == this->m_pGammaEntry )
  {
    this->m_pGammaEntry->GetText_2(this: this->m_pGammaEntry, a2: buf, a3: 64);
    v3 = atof(nptr: buf);
    if ( v3 >= 1.0 )
    {
      fValue = v3;
      CCvarSlider::SetSliderValue(this: this->m_pGammaSlider, fValue);
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "ApplyButtonEnable");
        this->PostActionSignal(this, a2: v5);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2DE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CGammaDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGammaDialog::GetMessageMap(CGammaDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGammaDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGammaDialog::GetMessageMap'::`2'::s_pMap;
  `CGammaDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGammaDialog");
  `CGammaDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E2E10
// Name: public: virtual struct PanelAnimationMap __near * CGammaDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGammaDialog::GetAnimMap(CGammaDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CGammaDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101E2E20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGammaDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGammaDialog::GetKBMap(CGammaDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGammaDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGammaDialog::GetKBMap'::`2'::s_pMap;
  `CGammaDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGammaDialog");
  `CGammaDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E2E50
// Name: public: virtual void CGammaDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::Activate(CGammaDialog *this)
{
  int v2; // eax
  CCvarSlider *m_pGammaSlider; // ecx
  double SliderValue; // st7
  char pDest[64]; // [esp+Ch] [ebp-40h] BYREF

  vgui::Frame::Activate(this);
  v2 = this->m_pGammaSlider->GetValue(this: this->m_pGammaSlider);
  m_pGammaSlider = this->m_pGammaSlider;
  this->m_flOriginalGamma = (float)v2;
  SliderValue = CCvarSlider::GetSliderValue(this: m_pGammaSlider);
  V_snprintf(pDest, maxLen: 0x40u, pFormat: " %.1f", SliderValue);
  this->m_pGammaEntry->SetText(this: this->m_pGammaEntry, a2: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101E2EC0
// Name: public: virtual void CGammaDialog::OnControlModified(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGammaDialog::OnControlModified(CGammaDialog *this, CCvarSlider *panel)
{
  CCvarSlider *m_pGammaSlider; // ecx
  double SliderValue; // st7
  char pDest[64]; // [esp+Ch] [ebp-40h] BYREF

  m_pGammaSlider = this->m_pGammaSlider;
  if ( panel == m_pGammaSlider && CCvarSlider::HasBeenModified(this: m_pGammaSlider) )
  {
    SliderValue = CCvarSlider::GetSliderValue(this: this->m_pGammaSlider);
    V_snprintf(pDest, maxLen: 0x40u, pFormat: " %.1f", SliderValue);
    this->m_pGammaEntry->SetText(this: this->m_pGammaEntry, a2: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2F20
// Name: public: COptionsSubVideoAdvancedDlg::COptionsSubVideoAdvancedDlg(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubVideoAdvancedDlg *__thiscall COptionsSubVideoAdvancedDlg::COptionsSubVideoAdvancedDlg(
        COptionsSubVideoAdvancedDlg *this,
        KeyValues *parent)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  vgui::ComboBox *v6; // eax
  unsigned int v7; // ebx
  vgui::ComboBox *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  int v11; // ecx
  int v12; // eax
  KeyValues *v13; // eax
  int v14; // edi
  int v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  vgui::ComboBox *v18; // eax
  vgui::ComboBox *v19; // eax
  vgui::ComboBox *v20; // eax
  vgui::ComboBox *v21; // eax
  vgui::ComboBox *v22; // eax
  vgui::ComboBox *v23; // eax
  vgui::ComboBox *v24; // eax
  vgui::ComboBox *v25; // eax
  vgui::ComboBox *v26; // eax
  vgui::ComboBox *v27; // eax
  vgui::ComboBox *v28; // eax
  vgui::ComboBox *v29; // eax
  vgui::ComboBox *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::ComboBox *v32; // eax
  vgui::ComboBox *v33; // eax
  vgui::ComboBox *v34; // eax
  vgui::ComboBox *v35; // eax
  vgui::ComboBox *v36; // eax
  vgui::ComboBox *v37; // eax
  vgui::ComboBox *v38; // eax
  vgui::ComboBox *v39; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v41; // eax
  char szDXLevelName[64]; // [esp+2Ch] [ebp-50h] BYREF
  ConVarRef mat_dxlevel; // [esp+6Ch] [ebp-10h] BYREF
  const MaterialSystem_Config_t *config; // [esp+74h] [ebp-8h]
  KeyValues *pTempKV; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  KeyValues *pKeyValues; // [esp+84h] [ebp+8h]

  vgui::Frame::Frame(
    this,
    (vgui::Panel *)parent,
    panelName: "OptionsSubVideoAdvancedDlg",
    showTaskbarIcon: true,
    bPopup: true);
  this->__vftable = (COptionsSubVideoAdvancedDlg_vtbl *)&COptionsSubVideoAdvancedDlg::`vftable';
  if ( `COptionsSubVideoAdvancedDlg::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoAdvancedDlg::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
    v3->pfnClassName = COptionsSubVideoAdvancedDlg::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COptionsSubVideoAdvancedDlg::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoAdvancedDlg::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubVideoAdvancedDlg");
    v4->pfnClassName = COptionsSubVideoAdvancedDlg::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COptionsSubVideoAdvancedDlg::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVideoAdvancedDlg::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideoAdvancedDlg");
    v5->pfnClassName = COptionsSubVideoAdvancedDlg::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  COptionsSubVideoAdvancedDlg::PanelMessageFunc_OnGameUIHidden::InitVar(a1: (int)&savedregs);
  COptionsSubVideoAdvancedDlg::PanelMessageFunc_ResetDXLevelCombo::InitVar();
  COptionsSubVideoAdvancedDlg::PanelMessageFunc_OK_Confirmed::InitVar();
  vgui::Frame::SetTitle(this, title: "#GameUI_VideoAdvanced_Title", surfaceTitle: true);
  vgui::Panel::SetSize(this, wide: 260, tall: 400);
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  v7 = 0;
  if ( v6 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "dxlabel", numLines: 6, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pDXLevel = v8;
  config = materials->GetCurrentConfigForVideoCard(this: materials);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(this: v9, setName: "config");
    pKeyValues = v10;
  }
  else
  {
    pKeyValues = nullptr;
    v10 = nullptr;
  }
  materials->GetRecommendedConfigurationInfo(this: materials, a2: 0, a3: v10);
  vgui::ComboBox::RemoveAll(this: this->m_pDXLevel);
  do
  {
    v12 = _CommandLine(a1: v11);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-dxlevel", a3: 0) != 0
      || g_DirectXLevels[v7] == config->dxSupportLevel
      || g_DirectXLevels[v7] >= KeyValues::GetInt(this: v10, keyName: "ConVar.mat_dxlevel", defaultValue: 0) )
    {
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        pTempKV = KeyValues::KeyValues(this: v13, setName: "config");
      else
        pTempKV = nullptr;
      v14 = g_DirectXLevels[v7];
      if ( v14 == KeyValues::GetInt(this: pKeyValues, keyName: "ConVar.mat_dxlevel", defaultValue: 0)
        || materials->GetRecommendedConfigurationInfo(this: materials, a2: v14, a3: pTempKV) )
      {
        v15 = g_DirectXLevels[v7];
        if ( v15 == 95 )
          V_snprintf(pDest: szDXLevelName, maxLen: 0x40u, pFormat: "DirectX v9.0+");
        else
          V_snprintf(pDest: szDXLevelName, maxLen: 0x40u, pFormat: "DirectX v%.1f", (float)((float)v15 * 0.1));
        v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v16 != nullptr )
          v17 = KeyValues::KeyValues(
                  this: v16,
                  setName: "dxlevel",
                  firstKey: "dxlevel",
                  firstValue: g_DirectXLevels[v7]);
        else
          v17 = nullptr;
        this->m_pDXLevel->AddItem_2(this: this->m_pDXLevel, a2: szDXLevelName, a3: v17);
      }
      KeyValues::deleteThis(this: pTempKV);
      v10 = pKeyValues;
    }
    ++v7;
  }
  while ( v7 < 5 );
  KeyValues::deleteThis(this: v10);
  v18 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v18 != nullptr )
    v19 = vgui::ComboBox::ComboBox(this: v18, parent: this, panelName: "ModelDetail", numLines: 6, allowEdit: false);
  else
    v19 = nullptr;
  this->m_pModelDetail = v19;
  v19->AddItem_2(this: v19, a2: "#gameui_low", a3: nullptr);
  this->m_pModelDetail->AddItem_2(this: this->m_pModelDetail, a2: "#gameui_medium", a3: nullptr);
  this->m_pModelDetail->AddItem_2(this: this->m_pModelDetail, a2: "#gameui_high", a3: nullptr);
  v20 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v20 != nullptr )
    v21 = vgui::ComboBox::ComboBox(this: v20, parent: this, panelName: "TextureDetail", numLines: 6, allowEdit: false);
  else
    v21 = nullptr;
  this->m_pTextureDetail = v21;
  v21->AddItem_2(this: v21, a2: "#gameui_low", a3: nullptr);
  this->m_pTextureDetail->AddItem_2(this: this->m_pTextureDetail, a2: "#gameui_medium", a3: nullptr);
  this->m_pTextureDetail->AddItem_2(this: this->m_pTextureDetail, a2: "#gameui_high", a3: nullptr);
  this->m_pTextureDetail->AddItem_2(this: this->m_pTextureDetail, a2: "#gameui_ultra", a3: nullptr);
  this->m_nNumAAModes = 0;
  v22 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v22 != nullptr )
    v23 = vgui::ComboBox::ComboBox(
            this: v22,
            parent: this,
            panelName: "AntialiasingMode",
            numLines: 10,
            allowEdit: false);
  else
    v23 = nullptr;
  this->m_pAntialiasingMode = v23;
  v23->AddItem_2(this: v23, a2: "#GameUI_None", a3: nullptr);
  this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 1;
  this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 0;
  if ( materials->SupportsMSAAMode(this: materials, a2: 2) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_2X", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 2;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 0;
  }
  if ( materials->SupportsMSAAMode(this: materials, a2: 4) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_4X", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 4;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 0;
  }
  if ( materials->SupportsMSAAMode(this: materials, a2: 6) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_6X", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 6;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 0;
  }
  if ( materials->SupportsCSAAMode(this: materials, a2: 4, a3: 2) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_8X_CSAA", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 4;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 2;
  }
  if ( materials->SupportsCSAAMode(this: materials, a2: 4, a3: 4) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_16X_CSAA", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 4;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 4;
  }
  if ( materials->SupportsMSAAMode(this: materials, a2: 8) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_8X", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 8;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 0;
  }
  if ( materials->SupportsCSAAMode(this: materials, a2: 8, a3: 2) )
  {
    this->m_pAntialiasingMode->AddItem_2(this: this->m_pAntialiasingMode, a2: "#GameUI_16XQ_CSAA", a3: nullptr);
    this->m_nAAModes[this->m_nNumAAModes].m_nNumSamples = 8;
    this->m_nAAModes[this->m_nNumAAModes++].m_nQualityLevel = 2;
  }
  v24 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v24 != nullptr )
    v25 = vgui::ComboBox::ComboBox(this: v24, parent: this, panelName: "FilteringMode", numLines: 6, allowEdit: false);
  else
    v25 = nullptr;
  this->m_pFilteringMode = v25;
  v25->AddItem_2(this: v25, a2: "#GameUI_Bilinear", a3: nullptr);
  this->m_pFilteringMode->AddItem_2(this: this->m_pFilteringMode, a2: "#GameUI_Trilinear", a3: nullptr);
  this->m_pFilteringMode->AddItem_2(this: this->m_pFilteringMode, a2: "#GameUI_Anisotropic2X", a3: nullptr);
  this->m_pFilteringMode->AddItem_2(this: this->m_pFilteringMode, a2: "#GameUI_Anisotropic4X", a3: nullptr);
  this->m_pFilteringMode->AddItem_2(this: this->m_pFilteringMode, a2: "#GameUI_Anisotropic8X", a3: nullptr);
  this->m_pFilteringMode->AddItem_2(this: this->m_pFilteringMode, a2: "#GameUI_Anisotropic16X", a3: nullptr);
  v26 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v26 != nullptr )
    v27 = vgui::ComboBox::ComboBox(this: v26, parent: this, panelName: "ShadowDetail", numLines: 6, allowEdit: false);
  else
    v27 = nullptr;
  this->m_pShadowDetail = v27;
  v27->AddItem_2(this: v27, a2: "#gameui_low", a3: nullptr);
  this->m_pShadowDetail->AddItem_2(this: this->m_pShadowDetail, a2: "#gameui_medium", a3: nullptr);
  if ( g_pMaterialSystemHardwareConfig->SupportsShadowDepthTextures(this: g_pMaterialSystemHardwareConfig) )
    this->m_pShadowDetail->AddItem_2(this: this->m_pShadowDetail, a2: "#gameui_high", a3: nullptr);
  ConVarRef::ConVarRef(this: &mat_dxlevel, pName: "mat_dxlevel");
  v28 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v28 != nullptr )
    v29 = vgui::ComboBox::ComboBox(this: v28, parent: this, panelName: "HDR", numLines: 6, allowEdit: false);
  else
    v29 = nullptr;
  this->m_pHDR = v29;
  v29->AddItem_2(this: v29, a2: "#GameUI_hdr_level0", a3: nullptr);
  this->m_pHDR->AddItem_2(this: this->m_pHDR, a2: "#GameUI_hdr_level1", a3: nullptr);
  if ( materials->SupportsHDRMode(this: materials, a2: HDR_TYPE_INTEGER) )
    this->m_pHDR->AddItem_2(this: this->m_pHDR, a2: "#GameUI_hdr_level2", a3: nullptr);
  this->m_pHDR->SetEnabled(this: this->m_pHDR, a2: mat_dxlevel.m_pConVarState->m_Value.m_nValue >= 80);
  v30 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v30 != nullptr )
    v31 = vgui::ComboBox::ComboBox(this: v30, parent: this, panelName: "WaterDetail", numLines: 6, allowEdit: false);
  else
    v31 = nullptr;
  this->m_pWaterDetail = v31;
  v31->AddItem_2(this: v31, a2: "#gameui_noreflections", a3: nullptr);
  this->m_pWaterDetail->AddItem_2(this: this->m_pWaterDetail, a2: "#gameui_reflectonlyworld", a3: nullptr);
  this->m_pWaterDetail->AddItem_2(this: this->m_pWaterDetail, a2: "#gameui_reflectall", a3: nullptr);
  v32 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v32 != nullptr )
    v33 = vgui::ComboBox::ComboBox(this: v32, parent: this, panelName: "VSync", numLines: 2, allowEdit: false);
  else
    v33 = nullptr;
  this->m_pVSync = v33;
  v33->AddItem_2(this: v33, a2: "#gameui_disabled", a3: nullptr);
  this->m_pVSync->AddItem_2(this: this->m_pVSync, a2: "#gameui_enabled", a3: nullptr);
  v34 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v34 != nullptr )
    v35 = vgui::ComboBox::ComboBox(this: v34, parent: this, panelName: "ShaderDetail", numLines: 6, allowEdit: false);
  else
    v35 = nullptr;
  this->m_pShaderDetail = v35;
  v35->AddItem_2(this: v35, a2: "#gameui_low", a3: nullptr);
  this->m_pShaderDetail->AddItem_2(this: this->m_pShaderDetail, a2: "#gameui_high", a3: nullptr);
  v36 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v36 != nullptr )
    v37 = vgui::ComboBox::ComboBox(this: v36, parent: this, panelName: "ColorCorrection", numLines: 2, allowEdit: false);
  else
    v37 = nullptr;
  this->m_pColorCorrection = v37;
  v37->AddItem_2(this: v37, a2: "#gameui_disabled", a3: nullptr);
  this->m_pColorCorrection->AddItem_2(this: this->m_pColorCorrection, a2: "#gameui_enabled", a3: nullptr);
  v38 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v38 != nullptr )
    v39 = vgui::ComboBox::ComboBox(this: v38, parent: this, panelName: "MotionBlur", numLines: 2, allowEdit: false);
  else
    v39 = nullptr;
  this->m_pMotionBlur = v39;
  v39->AddItem_2(this: v39, a2: "#gameui_disabled", a3: nullptr);
  this->m_pMotionBlur->AddItem_2(this: this->m_pMotionBlur, a2: "#gameui_enabled", a3: nullptr);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/OptionsSubVideoAdvancedDlg.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  this->m_pDXLevel->SetEnabled(this: this->m_pDXLevel, a2: false);
  this->m_pColorCorrection->SetEnabled(
    this: this->m_pColorCorrection,
    a2: mat_dxlevel.m_pConVarState->m_Value.m_nValue >= 90);
  this->m_pMotionBlur->SetEnabled(this: this->m_pMotionBlur, a2: mat_dxlevel.m_pConVarState->m_Value.m_nValue >= 90);
  if ( g_pCVar->FindVar_2(this: g_pCVar, a2: "fov_desired") == nullptr )
  {
    ChildByName = vgui::Panel::FindChildByName(this, childName: "FovSlider", recurseDown: false);
    if ( ChildByName != nullptr )
      ChildByName->SetVisible(this: ChildByName, a2: false);
    v41 = vgui::Panel::FindChildByName(this, childName: "FovLabel", recurseDown: false);
    if ( v41 != nullptr )
      v41->SetVisible(this: v41, a2: false);
  }
  COptionsSubVideoAdvancedDlg::MarkDefaultSettingsAsRecommended(this);
  this->m_bUseChanges = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E39A0
// Name: public: virtual void COptionsSubVideoAdvancedDlg::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::Activate(COptionsSubVideoAdvancedDlg *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax

  vgui::Frame::Activate(this);
  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  if ( !this->m_bUseChanges )
    this->OnResetData(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E39E0
// Name: public: virtual void COptionsSubVideoAdvancedDlg::OnGameUIHidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::OnGameUIHidden(COptionsSubVideoAdvancedDlg *this)
{
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E39F0
// Name: public: virtual void COptionsSubVideoAdvancedDlg::OK_Confirmed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::OK_Confirmed(COptionsSubVideoAdvancedDlg *this)
{
  void (*Close)(void); // edx

  Close = (void (*)(void))this->Close;
  this->m_bUseChanges = true;
  Close();
}

//------------------------------------------------------------------------------
// Address: 0x101E3A10
// Name: public: void COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(
        COptionsSubVideoAdvancedDlg *this,
        const char *pConVarName,
        int value)
{
  char szCmd[256]; // [esp+0h] [ebp-100h] BYREF

  V_snprintf(pDest: szCmd, maxLen: 0x100u, pFormat: "%s %d\n", pConVarName, value);
  engine->ClientCmd_Unrestricted(this: engine, a2: szCmd);
}

//------------------------------------------------------------------------------
// Address: 0x101E3A60
// Name: public: virtual void COptionsSubVideoAdvancedDlg::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::ApplyChanges(COptionsSubVideoAdvancedDlg *this)
{
  KeyValues *ActiveItemUserData; // eax
  int Int; // eax
  int ActiveItem; // eax
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  CCvarSlider *ChildByName; // eax
  int v14; // [esp-4h] [ebp-110h]
  char pDest[256]; // [esp+4h] [ebp-108h] BYREF
  ConVarRef mat_hdr_level; // [esp+104h] [ebp-8h] BYREF

  if ( this->m_bUseChanges )
  {
    ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pDXLevel);
    Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: "dxlevel", defaultValue: 0);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_dxlevel", Int);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pModelDetail);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_rootlod", 2 - ActiveItem);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    v5 = vgui::ComboBox::GetActiveItem(this: this->m_pTextureDetail);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_picmip", 2 - v5);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_trilinear", 0);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_forceaniso", 1);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    switch ( vgui::ComboBox::GetActiveItem(this: this->m_pFilteringMode) )
    {
      case 1:
        COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(this, pConVarName: "mat_trilinear", value: 1);
        break;
      case 2:
        v14 = 2;
        goto LABEL_8;
      case 3:
        v14 = 4;
        goto LABEL_8;
      case 4:
        v14 = 8;
        goto LABEL_8;
      case 5:
        v14 = 16;
LABEL_8:
        COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(this, pConVarName: "mat_forceaniso", value: v14);
        break;
      default:
        break;
    }
    v6 = vgui::ComboBox::GetActiveItem(this: this->m_pAntialiasingMode);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_antialias", this->m_nAAModes[v6].m_nNumSamples);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_aaquality", this->m_nAAModes[v6].m_nQualityLevel);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    if ( this->m_pHDR->IsEnabled(this: this->m_pHDR) )
    {
      ConVarRef::ConVarRef(this: &mat_hdr_level, pName: "mat_hdr_level");
      v7 = vgui::ComboBox::GetActiveItem(this: this->m_pHDR);
      mat_hdr_level.m_pConVar->SetValue_2(this: mat_hdr_level.m_pConVar, a2: v7);
    }
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pShadowDetail) != 0 )
    {
      if ( vgui::ComboBox::GetActiveItem(this: this->m_pShadowDetail) == 1 )
      {
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_shadowrendertotexture", 1);
        engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_flashlightdepthtexture", 0);
        engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
      }
      else if ( vgui::ComboBox::GetActiveItem(this: this->m_pShadowDetail) == 2 )
      {
        COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(this, pConVarName: "r_shadowrendertotexture", value: 1);
        COptionsSubVideoAdvancedDlg::ApplyChangesToConVar(this, pConVarName: "r_flashlightdepthtexture", value: 1);
      }
    }
    else
    {
      V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_shadowrendertotexture", 0);
      engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
      V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_flashlightdepthtexture", 0);
      engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    }
    v8 = vgui::ComboBox::GetActiveItem(this: this->m_pShaderDetail);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_reducefillrate", v8 <= 0);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    v9 = vgui::ComboBox::GetActiveItem(this: this->m_pWaterDetail) - 1;
    if ( v9 != 0 )
    {
      if ( v9 == 1 )
      {
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_waterforceexpensive", 1);
        engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_waterforcereflectentities", 1);
        goto LABEL_23;
      }
      V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_waterforceexpensive", 0);
    }
    else
    {
      V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_waterforceexpensive", 1);
    }
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "r_waterforcereflectentities", 0);
LABEL_23:
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    v10 = vgui::ComboBox::GetActiveItem(this: this->m_pVSync);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_vsync", v10);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    v11 = vgui::ComboBox::GetActiveItem(this: this->m_pColorCorrection);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_colorcorrection", v11);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    v12 = vgui::ComboBox::GetActiveItem(this: this->m_pMotionBlur);
    V_snprintf(pDest, maxLen: 0x100u, pFormat: "%s %d\n", "mat_motion_blur_enabled", v12);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
    ChildByName = (CCvarSlider *)vgui::Panel::FindChildByName(this, childName: "FOVSlider", recurseDown: false);
    if ( ChildByName != nullptr )
      CCvarSlider::ApplyChanges(this: ChildByName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4000
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubVideoAdvancedDlg::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubVideoAdvancedDlg::GetMessageMap(COptionsSubVideoAdvancedDlg *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubVideoAdvancedDlg::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideoAdvancedDlg::GetMessageMap'::`2'::s_pMap;
  `COptionsSubVideoAdvancedDlg::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVideoAdvancedDlg");
  `COptionsSubVideoAdvancedDlg::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E4030
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubVideoAdvancedDlg::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubVideoAdvancedDlg::GetAnimMap(COptionsSubVideoAdvancedDlg *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubVideoAdvancedDlg");
}

//------------------------------------------------------------------------------
// Address: 0x101E4040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubVideoAdvancedDlg::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubVideoAdvancedDlg::GetKBMap(COptionsSubVideoAdvancedDlg *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubVideoAdvancedDlg::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVideoAdvancedDlg::GetKBMap'::`2'::s_pMap;
  `COptionsSubVideoAdvancedDlg::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVideoAdvancedDlg");
  `COptionsSubVideoAdvancedDlg::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E4070
// Name: public: virtual void COptionsSubVideoAdvancedDlg::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COptionsSubVideoAdvancedDlg::OnTextChanged(
        COptionsSubVideoAdvancedDlg *this@<ecx>,
        int a2@<esi>,
        vgui::ComboBox *panel)
{
  vgui::QueryBox *v4; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( panel == this->m_pDXLevel && COptionsSubVideoAdvancedDlg::RequiresRestart(this) )
  {
    v4 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
    if ( v4 != nullptr )
      Box = vgui::QueryBox::QueryBox(
              this: v4,
              title: "#GameUI_SettingRequiresDisconnect_Title",
              queryText: "#GameUI_SettingRequiresDisconnect_Info",
              parent: nullptr);
    else
      Box = nullptr;
    ((void (__thiscall *)(vgui::QueryBox *, COptionsSubVideoAdvancedDlg *, int))Box->AddActionSignalTarget_2)(
      a1: Box,
      a2: this,
      a3: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "ResetDXLevelCombo");
    else
      v7 = nullptr;
    vgui::QueryBox::SetCancelCommand(this: Box, keyValues: v7);
    Box->DoModal_2(this: Box, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4100
// Name: public: virtual void COptionsSubVideoAdvancedDlg::ResetDXLevelCombo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::ResetDXLevelCombo(COptionsSubVideoAdvancedDlg *this)
{
  int v2; // esi
  KeyValues *ItemUserData; // eax
  int m_nValue; // ebx
  int Int; // eax
  vgui::ComboBox_vtbl *v6; // edx
  int v7; // eax
  ConVarRef mat_hdr_level; // [esp+8h] [ebp-10h] BYREF
  ConVarRef mat_dxlevel; // [esp+10h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &mat_dxlevel, pName: "mat_dxlevel");
  v2 = 0;
  if ( this->m_pDXLevel->GetItemCount(this: this->m_pDXLevel) > 0 )
  {
    while ( 1 )
    {
      ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pDXLevel, itemID: v2);
      m_nValue = mat_dxlevel.m_pConVarState->m_Value.m_nValue;
      Int = KeyValues::GetInt(this: ItemUserData, keyName: "dxlevel", defaultValue: 0);
      v6 = this->m_pDXLevel->__vftable;
      if ( Int == m_nValue )
        break;
      if ( ++v2 >= ((int (*)(void))v6->GetItemCount)() )
        goto LABEL_6;
    }
    ((void (__stdcall *)(int))v6->ActivateItem)(a1: v2);
  }
LABEL_6:
  if ( this->m_pHDR->IsEnabled(this: this->m_pHDR) )
  {
    ConVarRef::ConVarRef(this: &mat_hdr_level, pName: "mat_hdr_level");
    v7 = mat_hdr_level.m_pConVarState->m_Value.m_nValue;
    if ( v7 >= 0 )
    {
      if ( v7 > 2 )
        v7 = 2;
    }
    else
    {
      v7 = 0;
    }
    this->m_pHDR->ActivateItem(this: this->m_pHDR, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E41D0
// Name: public: virtual void COptionsSubVideoAdvancedDlg::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::OnResetData(COptionsSubVideoAdvancedDlg *this)
{
  int m_nValue; // eax
  int v3; // eax
  int v4; // eax
  int m_nNumAAModes; // edx
  int v6; // eax
  int *p_m_nQualityLevel; // ecx
  vgui::ComboBox_vtbl *v8; // eax
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // edx
  int v10; // eax
  char szVersion[64]; // [esp+3Ch] [ebp-110h] BYREF
  char dxVer[64]; // [esp+7Ch] [ebp-D0h] BYREF
  ConVarRef mat_antialias; // [esp+BCh] [ebp-90h] BYREF
  ConVarRef mat_reducefillrate; // [esp+C4h] [ebp-88h] BYREF
  ConVarRef mat_dxlevel; // [esp+CCh] [ebp-80h] BYREF
  ConVarRef r_rootlod; // [esp+D4h] [ebp-78h] BYREF
  ConVarRef mat_motion_blur_enabled; // [esp+DCh] [ebp-70h] BYREF
  ConVarRef mat_picmip; // [esp+E4h] [ebp-68h] BYREF
  ConVarRef mat_colorcorrection; // [esp+ECh] [ebp-60h] BYREF
  ConVarRef mat_trilinear; // [esp+F4h] [ebp-58h] BYREF
  ConVarRef mat_vsync; // [esp+FCh] [ebp-50h] BYREF
  ConVarRef mat_hdr_level; // [esp+104h] [ebp-48h] BYREF
  ConVarRef r_waterforcereflectentities; // [esp+10Ch] [ebp-40h] BYREF
  ConVarRef r_flashlightdepthtexture; // [esp+114h] [ebp-38h] BYREF
  ConVarRef r_waterforceexpensive; // [esp+11Ch] [ebp-30h] BYREF
  ConVarRef mat_aaquality; // [esp+124h] [ebp-28h] BYREF
  ConVarRef mat_forceaniso; // [esp+12Ch] [ebp-20h] BYREF
  ConVarRef r_shadowrendertotexture; // [esp+134h] [ebp-18h] BYREF
  int os; // [esp+13Ch] [ebp-10h] BYREF
  int subVersion; // [esp+140h] [ebp-Ch] BYREF
  int majorVersion; // [esp+144h] [ebp-8h] BYREF
  int minorVersion; // [esp+148h] [ebp-4h] BYREF

  ConVarRef::ConVarRef(this: &mat_dxlevel, pName: "mat_dxlevel");
  ConVarRef::ConVarRef(this: &r_rootlod, pName: "r_rootlod");
  ConVarRef::ConVarRef(this: &mat_picmip, pName: "mat_picmip");
  ConVarRef::ConVarRef(this: &mat_trilinear, pName: "mat_trilinear");
  ConVarRef::ConVarRef(this: &mat_forceaniso, pName: "mat_forceaniso");
  ConVarRef::ConVarRef(this: &mat_antialias, pName: "mat_antialias");
  ConVarRef::ConVarRef(this: &mat_aaquality, pName: "mat_aaquality");
  ConVarRef::ConVarRef(this: &mat_vsync, pName: "mat_vsync");
  ConVarRef::ConVarRef(this: &r_flashlightdepthtexture, pName: "r_flashlightdepthtexture");
  ConVarRef::ConVarRef(this: &r_waterforceexpensive, pName: "r_waterforceexpensive");
  ConVarRef::ConVarRef(this: &r_waterforcereflectentities, pName: "r_waterforcereflectentities");
  ConVarRef::ConVarRef(this: &mat_reducefillrate, pName: "mat_reducefillrate");
  ConVarRef::ConVarRef(this: &mat_hdr_level, pName: "mat_hdr_level");
  ConVarRef::ConVarRef(this: &mat_colorcorrection, pName: "mat_colorcorrection");
  ConVarRef::ConVarRef(this: &mat_motion_blur_enabled, pName: "mat_motion_blur_enabled");
  ConVarRef::ConVarRef(this: &r_shadowrendertotexture, pName: "r_shadowrendertotexture");
  this->ResetDXLevelCombo(this);
  m_nValue = r_rootlod.m_pConVarState->m_Value.m_nValue;
  if ( m_nValue >= 0 )
  {
    if ( m_nValue > 2 )
      m_nValue = 2;
  }
  else
  {
    m_nValue = 0;
  }
  this->m_pModelDetail->ActivateItem(this: this->m_pModelDetail, a2: 2 - m_nValue);
  v3 = mat_picmip.m_pConVarState->m_Value.m_nValue;
  if ( v3 >= -1 )
  {
    if ( v3 > 2 )
      v3 = 2;
  }
  else
  {
    v3 = -1;
  }
  this->m_pTextureDetail->ActivateItem(this: this->m_pTextureDetail, a2: 2 - v3);
  if ( r_flashlightdepthtexture.m_pConVarState->m_Value.m_nValue != 0 )
  {
    r_shadowrendertotexture.m_pConVar->SetValue_2(this: r_shadowrendertotexture.m_pConVar, a2: 1);
    this->m_pShadowDetail->ActivateItem(this: this->m_pShadowDetail, a2: 2);
  }
  else
  {
    this->m_pShadowDetail->ActivateItem(
      this: this->m_pShadowDetail,
      a2: r_shadowrendertotexture.m_pConVarState->m_Value.m_nValue != 0);
  }
  this->m_pShaderDetail->ActivateItem(
    this: this->m_pShaderDetail,
    a2: mat_reducefillrate.m_pConVarState->m_Value.m_nValue == 0);
  v4 = mat_hdr_level.m_pConVarState->m_Value.m_nValue;
  if ( v4 >= 0 )
  {
    if ( v4 > 2 )
      v4 = 2;
  }
  else
  {
    v4 = 0;
  }
  this->m_pHDR->ActivateItem(this: this->m_pHDR, a2: v4);
  switch ( mat_forceaniso.m_pConVarState->m_Value.m_nValue )
  {
    case 2:
      this->m_pFilteringMode->ActivateItem(this: this->m_pFilteringMode, a2: 2);
      break;
    case 4:
      this->m_pFilteringMode->ActivateItem(this: this->m_pFilteringMode, a2: 3);
      break;
    case 8:
      this->m_pFilteringMode->ActivateItem(this: this->m_pFilteringMode, a2: 4);
      break;
    case 0x10:
      this->m_pFilteringMode->ActivateItem(this: this->m_pFilteringMode, a2: 5);
      break;
    default:
      ((void (__stdcall *)(bool))this->m_pFilteringMode->ActivateItem)(a1: mat_trilinear.m_pConVarState->m_Value.m_nValue != 0);
      break;
  }
  m_nNumAAModes = this->m_nNumAAModes;
  v6 = 0;
  if ( m_nNumAAModes <= 0 )
  {
LABEL_27:
    v6 = 0;
  }
  else
  {
    p_m_nQualityLevel = &this->m_nAAModes[0].m_nQualityLevel;
    while ( *(p_m_nQualityLevel - 1) != mat_antialias.m_pConVarState->m_Value.m_nValue
         || *p_m_nQualityLevel != mat_aaquality.m_pConVarState->m_Value.m_nValue )
    {
      ++v6;
      p_m_nQualityLevel += 2;
      if ( v6 >= m_nNumAAModes )
        goto LABEL_27;
    }
  }
  this->m_pAntialiasingMode->ActivateItem(this: this->m_pAntialiasingMode, a2: v6);
  v8 = this->m_pWaterDetail->__vftable;
  if ( r_waterforceexpensive.m_pConVarState->m_Value.m_nValue != 0 )
  {
    ActivateItem = v8->ActivateItem;
    if ( r_waterforcereflectentities.m_pConVarState->m_Value.m_nValue != 0 )
      ((void (__stdcall *)(int))ActivateItem)(a1: 2);
    else
      ((void (__stdcall *)(int))ActivateItem)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v8->ActivateItem)(a1: 0);
  }
  this->m_pVSync->ActivateItem(this: this->m_pVSync, a2: mat_vsync.m_pConVarState->m_Value.m_nValue);
  this->m_pColorCorrection->ActivateItem(
    this: this->m_pColorCorrection,
    a2: mat_colorcorrection.m_pConVarState->m_Value.m_nValue);
  this->m_pMotionBlur->ActivateItem(
    this: this->m_pMotionBlur,
    a2: mat_motion_blur_enabled.m_pConVarState->m_Value.m_nValue);
  v10 = mat_dxlevel.m_pConVarState->m_Value.m_nValue;
  if ( v10 == 95 )
    V_snprintf(pDest: dxVer, maxLen: 0x40u, pFormat: "DirectX v9.0+");
  else
    V_snprintf(pDest: dxVer, maxLen: 0x40u, pFormat: "DirectX v%.1f", (float)((float)v10 * 0.1));
  this->SetControlString_2(this, a2: "dxlabel", a3: dxVer);
  szVersion[0] = 0;
  g_pVGuiSystem->GetRegistryString(
    this: g_pVGuiSystem,
    a2: "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\DirectX\\Version",
    a3: szVersion,
    a4: 64);
  os = 0;
  majorVersion = 0;
  minorVersion = 0;
  subVersion = 0;
  sscanf(string: szVersion, format: "%d.%d.%d.%d", &os, &majorVersion, &minorVersion, &subVersion);
  V_snprintf(pDest: dxVer, maxLen: 0x40u, pFormat: "DirectX v%d.%d", majorVersion, minorVersion);
  this->SetControlString_2(this, a2: "dxinstalledlabel", a3: dxVer);
}

//------------------------------------------------------------------------------
// Address: 0x101E4610
// Name: public: virtual void COptionsSubVideoAdvancedDlg::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideoAdvancedDlg::OnCommand(COptionsSubVideoAdvancedDlg *this, const char *command)
{
  vgui::QueryBox *v3; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  void (__thiscall *Close)(vgui::Frame *); // edx

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else if ( COptionsSubVideoAdvancedDlg::RequiresRestart(this) )
  {
    v3 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
    if ( v3 != nullptr )
      Box = vgui::QueryBox::QueryBox(
              this: v3,
              title: "#GameUI_SettingRequiresDisconnect_Title",
              queryText: "#GameUI_SettingRequiresDisconnect_Info",
              parent: nullptr);
    else
      Box = nullptr;
    Box->AddActionSignalTarget_2(this: Box, a2: this);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "OK_Confirmed");
    else
      v6 = nullptr;
    vgui::QueryBox::SetOKCommand(this: Box, keyValues: v6);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "ResetDXLevelCombo");
    else
      v8 = nullptr;
    vgui::QueryBox::SetCancelCommand(this: Box, keyValues: v8);
    Box->DoModal_2(this: Box, a2: nullptr);
    Box->MoveToFront(this: Box);
  }
  else
  {
    Close = this->Close;
    this->m_bUseChanges = true;
    Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4710
// Name: private: virtual void COptionsSubVideo::OpenAdvanced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OpenAdvanced(COptionsSubVideo *this)
{
  vgui::DHANDLE<COptionsSubVideoAdvancedDlg> *p_m_hOptionsSubVideoAdvancedDlg; // edi
  COptionsSubVideoAdvancedDlg *v2; // esi
  CCStrike15BasePanel *v3; // eax
  vgui::Panel *ChildByName; // eax
  COptionsSubVideoAdvancedDlg *v5; // eax
  vgui::Panel *v6; // eax

  p_m_hOptionsSubVideoAdvancedDlg = &this->m_hOptionsSubVideoAdvancedDlg;
  if ( vgui::PHandle::Get(this: &this->m_hOptionsSubVideoAdvancedDlg) == nullptr )
  {
    v2 = (COptionsSubVideoAdvancedDlg *)MemAlloc_Alloc(nSize: 0x2CCu);
    if ( v2 != nullptr )
    {
      v3 = BasePanel();
      ChildByName = vgui::Panel::FindChildByName(this: v3, childName: "OptionsDialog", recurseDown: false);
      v5 = COptionsSubVideoAdvancedDlg::COptionsSubVideoAdvancedDlg(this: v2, parent: ChildByName);
    }
    else
    {
      v5 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_hOptionsSubVideoAdvancedDlg, pPanel: v5);
  }
  v6 = vgui::PHandle::Get(this: p_m_hOptionsSubVideoAdvancedDlg);
  v6->__vftable[1].OnTick(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101E4780
// Name: public: virtual void COptionsSubVideo::OpenGammaDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVideo::OpenGammaDialog(COptionsSubVideo *this)
{
  unsigned int v1; // esi
  CGammaDialog *v2; // eax
  CGammaDialog *v3; // eax
  vgui::Panel *v4; // eax

  v1 = this->GetVParent(this);
  if ( vgui::PHandle::Get(this: &COptionsSubVideo::m_hGammaDialog) == nullptr )
  {
    v2 = (CGammaDialog *)MemAlloc_Alloc(nSize: 0x228u);
    if ( v2 != nullptr )
      v3 = CGammaDialog::CGammaDialog(this: v2, hParent: v1);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &COptionsSubVideo::m_hGammaDialog, pPanel: v3);
  }
  v4 = vgui::PHandle::Get(this: &COptionsSubVideo::m_hGammaDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1038FC30
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10395BC0
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  wchar_t v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x103971E0
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}
