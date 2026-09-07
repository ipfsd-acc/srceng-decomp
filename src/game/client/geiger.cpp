// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/geiger.cpp
// Functions: 12
// ============================================================

#include "game\client\geiger.h"

//------------------------------------------------------------------------------
// Address: 0x100EA4C0
// Name: public: static char const __near * CHudGeiger::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudGeiger::GetPanelClassName()
{
  return "CHudGeiger";
}

//------------------------------------------------------------------------------
// Address: 0x100EA500
// Name: public: virtual void CHudGeiger::VidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudGeiger::VidInit(CHudGeiger *this)
{
  this->m_iGeigerRange = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EA510
// Name: public: virtual bool CHudGeiger::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudGeiger::ShouldDraw(CHudGeiger *this)
{
  int m_iGeigerRange; // eax

  m_iGeigerRange = this->m_iGeigerRange;
  return m_iGeigerRange > 0 && m_iGeigerRange < 1000 && CHudElement::ShouldDraw(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EA540
// Name: public: CHudGeiger::CHudGeiger(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudGeiger *__thiscall CHudGeiger::CHudGeiger(CHudGeiger *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudGeiger");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudGeiger_vtbl *)&CHudGeiger::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudGeiger::`vftable'{for `vgui::Panel'};
  if ( `CHudGeiger::ChainToMap'::`2'::chained == 0 )
  {
    `CHudGeiger::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudGeiger");
    v3->pfnClassName = CHudGeiger::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudGeiger::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudGeiger::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudGeiger");
    v4->pfnClassName = CHudGeiger::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudGeiger::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudGeiger::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudGeiger");
    v5->pfnClassName = CHudGeiger::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  this->m_flLastSoundTestTime = -9999.0;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)8);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EA640
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudGeiger::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudGeiger::GetMessageMap(CHudGeiger *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudGeiger::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudGeiger::GetMessageMap'::`2'::s_pMap;
  `CHudGeiger::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudGeiger");
  `CHudGeiger::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EA670
// Name: public: virtual struct PanelAnimationMap __near * CHudGeiger::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudGeiger::GetAnimMap(CHudGeiger *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudGeiger");
}

//------------------------------------------------------------------------------
// Address: 0x100EA680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudGeiger::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudGeiger::GetKBMap(CHudGeiger *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudGeiger::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudGeiger::GetKBMap'::`2'::s_pMap;
  `CHudGeiger::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudGeiger");
  `CHudGeiger::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EA6B0
// Name: public: void CHudGeiger::MsgFunc_Geiger(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudGeiger::MsgFunc_Geiger(CHudGeiger *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  unsigned int v7; // edx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  CHudGeiger *v16; // [esp+Ch] [ebp-4h]

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
      this->m_iGeigerRange = 0;
    }
    else
    {
      v14 = msg->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v12;
      msg->m_nInBufWord = v14 >> v12;
      v16->m_iGeigerRange = 4 * (v15 | m_nInBufWord);
    }
    return;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  v6 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    v7 = v4 >> 8;
  }
  else
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nInBufWord = 0;
      msg->m_nBitsAvail = 1;
      msg->m_pDataIn = v8 + 1;
      this->m_iGeigerRange = 4 * v5;
      return;
    }
    if ( v8 > v9 )
    {
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
      this->m_iGeigerRange = 4 * v5;
      return;
    }
    v7 = *v8;
    msg->m_pDataIn = v8 + 1;
  }
  msg->m_nInBufWord = v7;
  this->m_iGeigerRange = 4 * v5;
}

//------------------------------------------------------------------------------
// Address: 0x100EA800
// Name: Create_CHudGeiger
// Source: json
//------------------------------------------------------------------------------
CHudGeiger *__cdecl Create_CHudGeiger()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 400);
  memset(dst: v0, value: 0, count: 0x190u);
  if ( v0 != nullptr )
    return CHudGeiger::CHudGeiger(this: (CHudGeiger *)v0, pElementName: "CHudGeiger");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EA840
// Name: void __MsgFunc_CHudGeiger_Geiger(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudGeiger_Geiger(bf_read *msg)
{
  CHud *Hud; // eax
  CHudGeiger *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudGeiger *)CHud::FindElement(this: Hud, pName: "CHudGeiger");
  if ( Element != nullptr )
    CHudGeiger::MsgFunc_Geiger(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x100EA870
// Name: public: virtual void CHudGeiger::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudGeiger::Init(CHudGeiger *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "Geiger", hook: __MsgFunc_CHudGeiger_Geiger);
  this->m_iGeigerRange = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EA8A0
// Name: public: virtual void CHudGeiger::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudGeiger::Paint(CHudGeiger *this)
{
  char v1; // bl
  float m_flAlpha; // eax
  int v3; // esi
  float v4; // xmm0_4
  float v5; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  char sz[256]; // [esp+0h] [ebp-220h] BYREF
  CLocalPlayerFilter filter; // [esp+100h] [ebp-120h] BYREF
  CSoundParameters params; // [esp+120h] [ebp-100h] BYREF
  EmitSound_t ep; // [esp+1D4h] [ebp-4Ch] BYREF
  float flvol; // [esp+21Ch] [ebp-4h]

  flvol = 0.0;
  v1 = 0;
  if ( (float)(*(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_m_nPaintBackgroundType_register) >= 0.06 )
  {
    m_flAlpha = this->m_flAlpha;
    *(_DWORD *)&this->m_m_nPaintBackgroundType_register = *(_DWORD *)(gpGlobals.m_Index + 12);
    if ( SLODWORD(m_flAlpha) <= 800 )
    {
      if ( SLODWORD(m_flAlpha) <= 600 )
      {
        if ( SLODWORD(m_flAlpha) <= 500 )
        {
          if ( SLODWORD(m_flAlpha) <= 400 )
          {
            if ( SLODWORD(m_flAlpha) <= 300 )
            {
              if ( SLODWORD(m_flAlpha) <= 200 )
              {
                if ( SLODWORD(m_flAlpha) <= 150 )
                {
                  if ( SLODWORD(m_flAlpha) <= 100 )
                  {
                    if ( SLODWORD(m_flAlpha) <= 75 )
                    {
                      if ( SLODWORD(m_flAlpha) <= 50 )
                      {
                        v4 = 0.5;
                        v3 = 95;
                      }
                      else
                      {
                        v4 = 0.47499999;
                        v3 = 90;
                      }
                    }
                    else
                    {
                      v4 = 0.44999999;
                      v3 = 80;
                      v1 = 1;
                    }
                  }
                  else
                  {
                    v4 = 0.42500001;
                    v3 = 60;
                    v1 = 1;
                  }
                }
                else
                {
                  v4 = 0.40000001;
                  v3 = 40;
                  v1 = 1;
                }
              }
              else
              {
                v4 = 0.38999999;
                v3 = 28;
                v1 = 1;
              }
            }
            else
            {
              v4 = 0.34999999;
              v3 = 8;
              v1 = 1;
            }
          }
          else
          {
            v4 = 0.30000001;
            v3 = 8;
            v1 = 1;
          }
        }
        else
        {
          v4 = 0.25;
          v3 = 4;
        }
      }
      else
      {
        v4 = 0.2;
        v3 = 2;
      }
      flvol = v4;
    }
    else
    {
      v3 = 0;
    }
    v5 = (float)((float)((float)random->RandomInt(this: random, a2: 0, a3: 127) * flvol) * 0.0039215689) + 0.25;
    RandomInt = random->RandomInt;
    flvol = v5;
    if ( RandomInt(this: random, a2: 0, a3: 127) < v3 )
    {
      if ( v1 != 0 )
        V_strncpy(pDest: sz, pSrc: "Geiger.BeepHigh", maxLen: 256);
      else
        V_strncpy(pDest: sz, pSrc: "Geiger.BeepLow", maxLen: 256);
      params.channel = 0;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_pOperatorsKV = nullptr;
      params.volume = 1.0;
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.soundlevel = SNDLVL_NORM;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_nRandomSeed = -1;
      if ( C_BaseEntity::GetParametersForSound(soundname: sz, &params, actormodel: nullptr) )
      {
        CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
        EmitSound_t::EmitSound_t(this: &ep);
        ep.m_pSoundName = params.soundname;
        ep.m_SoundLevel = params.soundlevel;
        ep.m_nChannel = params.channel;
        ep.m_flVolume = flvol;
        ep.m_nPitch = params.pitch;
        C_BaseEntity::EmitSound(&filter, iEntIndex: -1, params: &ep);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
      }
    }
  }
}
