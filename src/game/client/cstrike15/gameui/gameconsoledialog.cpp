// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/gameconsoledialog.cpp
// Functions: 14
// ============================================================

#include "game\client\cstrike15\gameui\gameconsoledialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D5320
// Name: public: static char const __near * CGameConsoleDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGameConsoleDialog::GetPanelClassName()
{
  return "CGameConsoleDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D5330
// Name: private: virtual void CGameConsoleDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsoleDialog::OnCommand(CGameConsoleDialog *this, const char *command)
{
  CGameUI *v3; // eax

  if ( _V_stricmp(s1: command, s2: "Close") == 0 )
  {
    v3 = GameUI();
    if ( CGameUI::IsInBackgroundLevel(this: v3) )
      engine->ClientCmd_Unrestricted(this: engine, a2: "unpause");
  }
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x101D5380
// Name: private: virtual void CGameConsoleDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsoleDialog::OnKeyCodeTyped(CGameConsoleDialog *this, ButtonCode_t code)
{
  char *v3; // eax
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Frame::OnKeyCodeTyped(this, code);
  if ( vgui::CConsolePanel::TextEntryHasFocus(this: this->m_pConsolePanel) && (unsigned int)(code - 92) <= 0xB )
  {
    v3 = (char *)gameuifuncs->GetBindingForButtonCode(this: gameuifuncs, a2: code);
    if ( v3 != nullptr && *v3 != 0 )
    {
      V_strncpy(pDest: szCommand, pSrc: v3, maxLen: 256);
      engine->ClientCmd_Unrestricted(this: engine, a2: szCommand);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5400
// Name: private: virtual void CGameConsoleDialog::OnClosedByHittingTilde(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsoleDialog::OnClosedByHittingTilde(CGameConsoleDialog *this)
{
  CGameUI *v1; // eax

  v1 = GameUI();
  CGameUI::HideGameUI(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101D5420
// Name: public: static void CGameConsoleDialog::PanelMessageFunc_OnClosedByHittingTilde::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGameConsoleDialog::PanelMessageFunc_OnClosedByHittingTilde::InitVar(int a1@<ebp>)
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
  if ( !`CGameConsoleDialog::PanelMessageFunc_OnClosedByHittingTilde::InitVar'::`2'::bAdded )
  {
    `CGameConsoleDialog::PanelMessageFunc_OnClosedByHittingTilde::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGameConsoleDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ClosedByHittingTilde";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D54B0
// Name: public: static void CGameConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGameConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`CGameConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CGameConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGameConsoleDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5550
// Name: public: CGameConsoleDialog::CGameConsoleDialog(void)
// Source: json
//------------------------------------------------------------------------------
CGameConsoleDialog *__thiscall CGameConsoleDialog::CGameConsoleDialog(CGameConsoleDialog *this)
{
  vgui::PanelMessageMap *v2; // esi
  PanelAnimationMap *v3; // esi
  vgui::PanelKeyBindingMap *v4; // esi

  vgui::CConsoleDialog::CConsoleDialog(this, pParent: nullptr, pName: "GameConsole", bStatusVersion: false);
  this->__vftable = (CGameConsoleDialog_vtbl *)&CGameConsoleDialog::`vftable';
  if ( `CGameConsoleDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CGameConsoleDialog::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CGameConsoleDialog");
    v2->pfnClassName = CGameConsoleDialog::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::CConsoleDialog");
  }
  if ( `CGameConsoleDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGameConsoleDialog::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CGameConsoleDialog");
    v3->pfnClassName = CGameConsoleDialog::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::CConsoleDialog");
  }
  if ( `CGameConsoleDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGameConsoleDialog::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CGameConsoleDialog");
    v4->pfnClassName = CGameConsoleDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::CConsoleDialog");
  }
  CGameConsoleDialog::PanelMessageFunc_OnClosedByHittingTilde::InitVar();
  CGameConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar();
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D5620
// Name: public: virtual struct vgui::PanelMessageMap __near * CGameConsoleDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGameConsoleDialog::GetMessageMap(CGameConsoleDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGameConsoleDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameConsoleDialog::GetMessageMap'::`2'::s_pMap;
  `CGameConsoleDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGameConsoleDialog");
  `CGameConsoleDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D5650
// Name: public: virtual struct PanelAnimationMap __near * CGameConsoleDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGameConsoleDialog::GetAnimMap(CGameConsoleDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CGameConsoleDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D5660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGameConsoleDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGameConsoleDialog::GetKBMap(CGameConsoleDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGameConsoleDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameConsoleDialog::GetKBMap'::`2'::s_pMap;
  `CGameConsoleDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGameConsoleDialog");
  `CGameConsoleDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5E40
// Name: private: virtual void CGameConsoleDialog::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsoleDialog::OnCommandSubmitted(CGameConsoleDialog *this, const char *pCommand)
{
  engine->ClientCmd_Unrestricted(this: engine, a2: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x103C2880
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsoleDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsoleDialog::GetMessageMap(vgui::CConsoleDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C28B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsoleDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsoleDialog::GetAnimMap(vgui::CConsoleDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsoleDialog");
}

//------------------------------------------------------------------------------
// Address: 0x103C28C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsoleDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsoleDialog::GetKBMap(vgui::CConsoleDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}
