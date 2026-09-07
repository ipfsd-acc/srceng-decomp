// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubdifficulty.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\gameui\optionssubdifficulty.h"

//------------------------------------------------------------------------------
// Address: 0x101D9590
// Name: public: static char const __near * COptionsSubDifficulty::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubDifficulty::GetPanelClassName()
{
  return "COptionsSubDifficulty";
}

//------------------------------------------------------------------------------
// Address: 0x101D95A0
// Name: public: virtual void COptionsSubDifficulty::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubDifficulty::OnResetData(COptionsSubDifficulty *this)
{
  int m_nValue; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pName: "skill");
  m_nValue = var.m_pConVarState->m_Value.m_nValue;
  if ( m_nValue == 1 )
  {
    this->m_pEasyRadio->SetSelected(this: this->m_pEasyRadio, a2: true);
  }
  else if ( m_nValue == 3 )
  {
    this->m_pHardRadio->SetSelected(this: this->m_pHardRadio, a2: true);
  }
  else
  {
    this->m_pNormalRadio->SetSelected(this: this->m_pNormalRadio, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9610
// Name: public: virtual void COptionsSubDifficulty::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubDifficulty::OnApplyChanges(COptionsSubDifficulty *this)
{
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pName: "skill");
  if ( this->m_pEasyRadio->IsSelected(this: this->m_pEasyRadio) )
  {
    var.m_pConVar->SetValue_2(this: var.m_pConVar, a2: 1);
  }
  else if ( this->m_pHardRadio->IsSelected(this: this->m_pHardRadio) )
  {
    var.m_pConVar->SetValue_2(this: var.m_pConVar, a2: 3);
  }
  else
  {
    var.m_pConVar->SetValue_2(this: var.m_pConVar, a2: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9690
// Name: public: static void COptionsSubDifficulty::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubDifficulty::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubDifficulty::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `COptionsSubDifficulty::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubDifficulty");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9720
// Name: public: COptionsSubDifficulty::COptionsSubDifficulty(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubDifficulty *__thiscall COptionsSubDifficulty::COptionsSubDifficulty(
        COptionsSubDifficulty *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::RadioButton *v6; // eax
  vgui::RadioButton *v7; // eax
  vgui::RadioButton *v8; // eax
  vgui::RadioButton *v9; // eax
  vgui::RadioButton *v10; // eax
  vgui::RadioButton *v11; // eax

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubDifficulty_vtbl *)&COptionsSubDifficulty::`vftable';
  if ( `COptionsSubDifficulty::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubDifficulty::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubDifficulty");
    v3->pfnClassName = COptionsSubDifficulty::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubDifficulty::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubDifficulty::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubDifficulty");
    v4->pfnClassName = COptionsSubDifficulty::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubDifficulty::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubDifficulty::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubDifficulty");
    v5->pfnClassName = COptionsSubDifficulty::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubDifficulty::PanelMessageFunc_OnRadioButtonChecked::InitVar();
  v6 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v6 != nullptr )
    v7 = vgui::RadioButton::RadioButton(this: v6, parent: this, panelName: "Skill1Radio", text: "#GameUI_SkillEasy");
  else
    v7 = nullptr;
  this->m_pEasyRadio = v7;
  v8 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v8 != nullptr )
    v9 = vgui::RadioButton::RadioButton(this: v8, parent: this, panelName: "Skill2Radio", text: "#GameUI_SkillNormal");
  else
    v9 = nullptr;
  this->m_pNormalRadio = v9;
  v10 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = vgui::RadioButton::RadioButton(this: v10, parent: this, panelName: "Skill3Radio", text: "#GameUI_SkillHard");
  else
    v11 = nullptr;
  this->m_pHardRadio = v11;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/OptionsSubDifficulty.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D9880
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubDifficulty::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubDifficulty::GetMessageMap(COptionsSubDifficulty *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubDifficulty::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubDifficulty::GetMessageMap'::`2'::s_pMap;
  `COptionsSubDifficulty::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubDifficulty");
  `COptionsSubDifficulty::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D98B0
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubDifficulty::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubDifficulty::GetAnimMap(COptionsSubDifficulty *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubDifficulty");
}

//------------------------------------------------------------------------------
// Address: 0x101D98C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubDifficulty::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubDifficulty::GetKBMap(COptionsSubDifficulty *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubDifficulty::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubDifficulty::GetKBMap'::`2'::s_pMap;
  `COptionsSubDifficulty::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubDifficulty");
  `COptionsSubDifficulty::GetKBMap'::`2'::s_pMap = result;
  return result;
}
