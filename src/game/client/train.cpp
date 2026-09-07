// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/train.cpp
// Functions: 10
// ============================================================

#include "game\client\train.h"

//------------------------------------------------------------------------------
// Address: 0x1017A530
// Name: public: static char const __near * CHudTrain::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudTrain::GetPanelClassName()
{
  return "CHudTrain";
}

//------------------------------------------------------------------------------
// Address: 0x1017A540
// Name: public: virtual bool CHudTrain::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudTrain::ShouldDraw(CHudTrain *this)
{
  return CHudElement::ShouldDraw(this) != 0 && this->m_iPos != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017A560
// Name: public: CHudTrain::CHudTrain(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudTrain *__thiscall CHudTrain::CHudTrain(CHudTrain *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudTrain");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudTrain_vtbl *)&CHudTrain::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudTrain::`vftable'{for `vgui::Panel'};
  if ( `CHudTrain::ChainToMap'::`2'::chained == 0 )
  {
    `CHudTrain::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudTrain");
    v3->pfnClassName = CHudTrain::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudTrain::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudTrain::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudTrain");
    v4->pfnClassName = CHudTrain::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudTrain::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudTrain::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudTrain");
    v5->pfnClassName = CHudTrain::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017A650
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudTrain::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudTrain::GetMessageMap(CHudTrain *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudTrain::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudTrain::GetMessageMap'::`2'::s_pMap;
  `CHudTrain::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudTrain");
  `CHudTrain::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A680
// Name: public: virtual struct PanelAnimationMap __near * CHudTrain::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudTrain::GetAnimMap(CHudTrain *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudTrain");
}

//------------------------------------------------------------------------------
// Address: 0x1017A690
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudTrain::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudTrain::GetKBMap(CHudTrain *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudTrain::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudTrain::GetKBMap'::`2'::s_pMap;
  `CHudTrain::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudTrain");
  `CHudTrain::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A6C0
// Name: public: void CHudTrain::MsgFunc_Train(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTrain::MsgFunc_Train(CHudTrain *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  CHudTrain *v16; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = msg->m_nBitsAvail;
  v16 = this;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      this->m_iPos = 0;
    }
    else
    {
      v14 = msg->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v12;
      msg->m_nInBufWord = v14 >> v12;
      v16->m_iPos = v15 | m_nInBufWord;
    }
    return;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  v6 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msg->m_nInBufWord = v4 >> 8;
    this->m_iPos = (unsigned __int8)v4;
  }
  else
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nInBufWord = 0;
      msg->m_nBitsAvail = 1;
      msg->m_pDataIn = v7 + 1;
      this->m_iPos = v5;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        msg->m_pDataIn = v7 + 1;
        msg->m_nInBufWord = v9;
      }
      else
      {
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      this->m_iPos = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A800
// Name: Create_CHudTrain
// Source: json
//------------------------------------------------------------------------------
CHudTrain *__cdecl Create_CHudTrain()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 396);
  memset(dst: v0, value: 0, count: 0x18Cu);
  if ( v0 != nullptr )
    return CHudTrain::CHudTrain(this: (CHudTrain *)v0, pElementName: "CHudTrain");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017A840
// Name: void __MsgFunc_CHudTrain_Train(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudTrain_Train(bf_read *msg)
{
  CHud *Hud; // eax
  CHudTrain *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudTrain *)CHud::FindElement(this: Hud, pName: "CHudTrain");
  if ( Element != nullptr )
    CHudTrain::MsgFunc_Train(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x1017A870
// Name: public: virtual void CHudTrain::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTrain::Init(CHudTrain *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "Train", hook: __MsgFunc_CHudTrain_Train);
  this->m_iPos = 0;
}
