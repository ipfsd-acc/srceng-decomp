// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/cvarnegatecheckbutton.cpp
// Functions: 10
// ============================================================

#include "game\client\cstrike15\gameui\cvarnegatecheckbutton.h"

//------------------------------------------------------------------------------
// Address: 0x101D3E80
// Name: public: static char const __near * CCvarNegateCheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCvarNegateCheckButton::GetPanelClassName()
{
  return "CCvarNegateCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x101D3E90
// Name: public: virtual void CCvarNegateCheckButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarNegateCheckButton::Paint(CCvarNegateCheckButton *this)
{
  CCvarNegateCheckButton *v1; // esi
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  v1 = this;
  if ( this->m_pszCvarName != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
    if ( !ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
      return;
    if ( var.m_pConVarState->m_Value.m_fValue >= 0.0 )
    {
      if ( v1->m_bStartState )
      {
        v1->SetSelected(this: v1, a2: false);
        v1->m_bStartState = false;
      }
    }
    else if ( !v1->m_bStartState )
    {
      v1->SetSelected(this: v1, a2: true);
      v1->m_bStartState = true;
      vgui::Button::Paint(this: v1);
      return;
    }
    this = v1;
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D3F20
// Name: public: void CCvarNegateCheckButton::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarNegateCheckButton::Reset(CCvarNegateCheckButton *this)
{
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
  {
    this->m_bStartState = var.m_pConVarState->m_Value.m_fValue < 0.0;
    this->SetSelected(this, a2: this->m_bStartState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3F90
// Name: public: void CCvarNegateCheckButton::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarNegateCheckButton::ApplyChanges(CCvarNegateCheckButton *this)
{
  char *m_pszCvarName; // eax
  bool v3; // al
  float v4; // xmm0_4
  float v5; // xmm0_4
  ConVarRef var; // [esp+8h] [ebp-Ch] BYREF
  float value; // [esp+10h] [ebp-4h]

  m_pszCvarName = this->m_pszCvarName;
  if ( m_pszCvarName != nullptr && *m_pszCvarName != 0 )
  {
    ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
    value = fabs(var.m_pConVarState->m_Value.m_fValue);
    if ( value < 0.00001 )
      value = 0.022;
    v3 = this->IsSelected(this);
    v4 = value;
    this->m_bStartState = v3;
    v5 = -v4;
    if ( !v3 )
      v5 = -v5;
    ((void (__stdcall *)(_DWORD))var.m_pConVar->SetValue_3)(a1: LODWORD(v5));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4030
// Name: private: virtual void CCvarNegateCheckButton::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarNegateCheckButton::OnButtonChecked(CCvarNegateCheckButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartState )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4090
// Name: public: virtual struct vgui::PanelMessageMap __near * CCvarNegateCheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCvarNegateCheckButton::GetMessageMap(CCvarNegateCheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCvarNegateCheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarNegateCheckButton::GetMessageMap'::`2'::s_pMap;
  `CCvarNegateCheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCvarNegateCheckButton");
  `CCvarNegateCheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D40C0
// Name: public: virtual struct PanelAnimationMap __near * CCvarNegateCheckButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCvarNegateCheckButton::GetAnimMap(CCvarNegateCheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CCvarNegateCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x101D40D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCvarNegateCheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCvarNegateCheckButton::GetKBMap(CCvarNegateCheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCvarNegateCheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarNegateCheckButton::GetKBMap'::`2'::s_pMap;
  `CCvarNegateCheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarNegateCheckButton");
  `CCvarNegateCheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4140
// Name: public: static void CCvarNegateCheckButton::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCvarNegateCheckButton::PanelMessageFunc_OnButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CCvarNegateCheckButton::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `CCvarNegateCheckButton::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarNegateCheckButton::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCvarNegateCheckButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D41D0
// Name: public: CCvarNegateCheckButton::CCvarNegateCheckButton(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarNegateCheckButton *__thiscall CCvarNegateCheckButton::CCvarNegateCheckButton(
        CCvarNegateCheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  char *v9; // eax
  ConVarRef v11; // [esp+8h] [ebp-8h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (CCvarNegateCheckButton_vtbl *)&CCvarNegateCheckButton::`vftable';
  if ( `CCvarNegateCheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `CCvarNegateCheckButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CCvarNegateCheckButton");
    v6->pfnClassName = CCvarNegateCheckButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::CheckButton");
  }
  if ( `CCvarNegateCheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCvarNegateCheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CCvarNegateCheckButton");
    v7->pfnClassName = CCvarNegateCheckButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::CheckButton");
  }
  if ( `CCvarNegateCheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCvarNegateCheckButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarNegateCheckButton");
    v8->pfnClassName = CCvarNegateCheckButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::CheckButton");
  }
  CCvarNegateCheckButton::PanelMessageFunc_OnButtonChecked::InitVar();
  if ( cvarname != nullptr )
    v9 = MemAlloc_StrDup(pString: cvarname);
  else
    v9 = nullptr;
  this->m_pszCvarName = v9;
  ConVarRef::ConVarRef(this: &v11, pName: v9);
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v11) )
  {
    this->m_bStartState = v11.m_pConVarState->m_Value.m_fValue < 0.0;
    this->SetSelected(this, a2: this->m_bStartState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}
