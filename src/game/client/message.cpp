// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/message.cpp
// Functions: 34
// ============================================================

#include "game\client\message.h"

//------------------------------------------------------------------------------
// Address: 0x100EA4D0
// Name: public: virtual void CHudMessage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::ApplySchemeSettings(CHudGeiger *this, vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, pScheme: (int)scheme);
  ((void (__thiscall *)(CHudGeiger *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011F740
// Name: public: static char const __near * CHudMessage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudMessage::GetPanelClassName()
{
  return "CHudMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1011F750
// Name: public: virtual void CHudMessage::VidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::VidInit(CHudMessage *this)
{
  CHudIcons *v2; // eax
  CHudIcons *v3; // eax

  v2 = HudIcons();
  this->m_iconTitleHalf = CHudIcons::GetIcon(this: v2, szIcon: "title_half");
  v3 = HudIcons();
  this->m_iconTitleLife = CHudIcons::GetIcon(this: v3, szIcon: "title_life");
}

//------------------------------------------------------------------------------
// Address: 0x1011F790
// Name: public: virtual void CHudMessage::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::Reset(CHudMessage *this)
{
  memset(dst: (int)this->m_pMessages, value: nullptr, count: sizeof(this->m_pMessages));
  memset(dst: (int)this->m_startTime, value: nullptr, count: sizeof(this->m_startTime));
  *(_QWORD *)&this->m_gameTitleTime = 0;
  this->m_bHaveMessage = false;
}

//------------------------------------------------------------------------------
// Address: 0x1011F7E0
// Name: public: int CHudMessage::XPosition(float,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHudMessage::XPosition(CHudMessage *this, float x, int width, int totalWidth)
{
  int v4; // esi

  if ( x == -1.0 )
  {
    v4 = (ScreenWidth() - width) / 2;
  }
  else if ( x >= 0.0 )
  {
    v4 = (int)(float)((float)ScreenWidth() * x);
  }
  else
  {
    v4 = (int)((double)ScreenWidth() * (float)(x + 1.0) - (double)totalWidth);
  }
  if ( v4 + width > ScreenWidth() )
    return ScreenWidth() - width;
  if ( v4 >= 0 )
    return v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011F890
// Name: public: int CHudMessage::YPosition(float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHudMessage::YPosition(CHudMessage *this, float y, int height)
{
  int v3; // esi

  if ( y == -1.0 )
  {
    v3 = (int)((double)(ScreenHeight() - height) * 0.5);
  }
  else if ( y >= 0.0 )
  {
    v3 = (int)(float)((float)ScreenHeight() * y);
  }
  else
  {
    v3 = (int)((double)ScreenHeight() * (float)(y + 1.0) - (double)height);
  }
  if ( v3 + height > ScreenHeight() )
    return ScreenHeight() - height;
  if ( v3 >= 0 )
    return v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011F950
// Name: public: void CHudMessage::MessageScanNextChar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MessageScanNextChar(CHudMessage *this)
{
  client_textmessage_t *pMessage; // eax
  int r1; // ebx
  int effect; // edi
  int fadeBlend; // edx
  int b2; // esi
  float v6; // xmm1_4
  float time; // xmm2_4
  float v8; // xmm0_4
  float fxtime; // xmm1_4
  int srcBlue; // [esp+10h] [ebp-10h]
  int srcGreen; // [esp+14h] [ebp-Ch]
  int destGreen; // [esp+18h] [ebp-8h]
  int destRed; // [esp+1Ch] [ebp-4h]

  pMessage = this->m_parms.pMessage;
  r1 = pMessage->r1;
  srcGreen = pMessage->g1;
  effect = pMessage->effect;
  srcBlue = pMessage->b1;
  fadeBlend = 0;
  b2 = 0;
  destGreen = 0;
  destRed = 0;
  if ( pMessage->effect < 0 )
    goto LABEL_15;
  if ( effect <= 1 )
  {
    b2 = 0;
    destGreen = 0;
    destRed = 0;
  }
  else
  {
    if ( effect != 2 )
      goto LABEL_15;
    v6 = pMessage->fadein + this->m_parms.charTime;
    time = this->m_parms.time;
    this->m_parms.charTime = v6;
    if ( v6 > time )
    {
      srcBlue = 0;
      srcGreen = 0;
      r1 = 0;
      goto LABEL_15;
    }
    b2 = 0;
    v8 = time - v6;
    destGreen = 0;
    destRed = 0;
    if ( time <= this->m_parms.fadeTime )
    {
      fxtime = pMessage->fxtime;
      if ( v8 > fxtime )
        goto LABEL_15;
      b2 = pMessage->b2;
      destRed = pMessage->r2;
      destGreen = pMessage->g2;
      fadeBlend = (int)(255.0 - (1.0 / fxtime * v8 * 255.0 + 0.5));
      goto LABEL_11;
    }
  }
  fadeBlend = this->m_parms.fadeBlend;
LABEL_11:
  if ( fadeBlend <= 255 )
  {
    if ( fadeBlend < 0 )
      fadeBlend = 0;
  }
  else
  {
    fadeBlend = 255;
  }
LABEL_15:
  this->m_parms.r = (fadeBlend * destRed + r1 * (255 - fadeBlend)) >> 8;
  this->m_parms.g = (fadeBlend * destGreen + srcGreen * (255 - fadeBlend)) >> 8;
  this->m_parms.b = (fadeBlend * b2 + srcBlue * (255 - fadeBlend)) >> 8;
}

//------------------------------------------------------------------------------
// Address: 0x1011FAB0
// Name: public: void CHudMessage::SetFont(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::SetFont(CHudMessage *this, unsigned int scheme, const char *pFontName)
{
  vgui::IScheme *v4; // eax
  unsigned int v5; // esi

  v4 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: scheme);
  if ( v4 != nullptr )
  {
    v5 = v4->GetFont(this: v4, a2: pFontName, a3: false);
    textmessage->SetFont(this: textmessage, a2: v5);
    this->m_parms.font = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FB00
// Name: public: void CHudMessage::MessageScanStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MessageScanStart(CHudMessage *this)
{
  client_textmessage_t *pMessage; // eax
  int effect; // ecx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float time; // xmm0_4
  float fadein; // xmm2_4
  float fadeout; // xmm2_4
  const char *vguiFontName; // edi
  unsigned int v12; // eax
  vgui::IScheme *v13; // eax
  unsigned int v14; // edi

  pMessage = this->m_parms.pMessage;
  effect = pMessage->effect;
  if ( pMessage->effect >= 0 )
  {
    if ( effect <= 1 )
    {
      v7 = pMessage->holdtime + pMessage->fadein;
      time = this->m_parms.time;
      this->m_parms.fadeTime = v7;
      fadein = pMessage->fadein;
      if ( fadein <= time )
      {
        if ( time <= v7 )
        {
          this->m_parms.fadeBlend = 0;
        }
        else
        {
          fadeout = pMessage->fadeout;
          if ( fadeout <= 0.0 )
            this->m_parms.fadeBlend = 255;
          else
            this->m_parms.fadeBlend = (int)(float)((float)((float)(time - v7) / fadeout) * 255.0);
        }
      }
      else
      {
        effect = (int)((float)(fadein - time) * (1.0 / pMessage->fadein) * 255.0);
        this->m_parms.fadeBlend = effect;
      }
      this->m_parms.charTime = 0.0;
      if ( pMessage->effect == 1 && rand(this: (IUniformRandomStream *)effect) % 100 < 10 )
        this->m_parms.charTime = 1.0;
    }
    else if ( effect == 2 )
    {
      v4 = this->m_parms.time;
      v5 = (float)((float)this->m_parms.length * pMessage->fadein) + pMessage->holdtime;
      this->m_parms.fadeTime = v5;
      if ( v4 <= v5 || (v6 = pMessage->fadeout) <= 0.0 )
        this->m_parms.fadeBlend = 0;
      else
        this->m_parms.fadeBlend = (int)(float)((float)((float)(v4 - v5) / v6) * 255.0);
    }
  }
  vguiFontName = this->m_parms.vguiFontName;
  this->m_parms.font = g_hFontTrebuchet24;
  if ( vguiFontName != nullptr && *vguiFontName != 0 )
  {
    v12 = g_pVGuiSchemeManager->GetDefaultScheme(this: g_pVGuiSchemeManager);
    v13 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v12);
    if ( v13 != nullptr )
    {
      v14 = v13->GetFont(this: v13, a2: vguiFontName, a3: false);
      textmessage->SetFont(this: textmessage, a2: v14);
      this->m_parms.font = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FCB0
// Name: public: void CHudMessage::MessageAdd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MessageAdd(CHudMessage *this, const char *pName)
{
  client_textmessage_t *v3; // edx
  int v4; // esi
  client_textmessage_t **m_pMessages; // edi
  int v6; // eax
  int v7; // eax
  client_textmessage_t **v8; // ecx
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx
  float time; // [esp+0h] [ebp-4h]
  client_textmessage_t *pMessage; // [esp+Ch] [ebp+8h]

  time = *(float *)(gpGlobals.m_Index + 12);
  if ( *pName == 35 )
  {
    v3 = TextMessageGet(pName: pName + 1);
    pMessage = v3;
  }
  else
  {
    pMessage = TextMessageGet(pName);
    v3 = pMessage;
  }
  if ( v3 != nullptr )
  {
    if ( v3->pClearMessage != nullptr )
    {
      v4 = 0;
      m_pMessages = this->m_pMessages;
      while ( 1 )
      {
        if ( *m_pMessages != nullptr )
        {
          v6 = _V_stricmp(s1: (*m_pMessages)->pName, s2: v3->pClearMessage);
          v3 = pMessage;
          if ( v6 == 0 )
            break;
        }
        ++v4;
        ++m_pMessages;
        if ( v4 >= 16 )
          goto LABEL_12;
      }
      this->m_startTime[v4] = 0.0;
      this->m_pMessages[v4] = nullptr;
    }
LABEL_12:
    v7 = 0;
    v8 = this->m_pMessages;
    while ( *v8 != nullptr )
    {
      ++v7;
      ++v8;
      if ( v7 >= 16 )
        goto LABEL_17;
    }
    this->m_pMessages[v7] = v3;
    this->m_startTime[v7] = time;
LABEL_17:
    SetVisible = this->SetVisible;
    this->m_parms.time = time;
    this->m_bHaveMessage = true;
    SetVisible(this: &this->vgui::Panel, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FDA0
// Name: public: void CHudMessage::MsgFunc_GameTitle(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MsgFunc_GameTitle(CHudMessage *this, bf_read *msg)
{
  client_textmessage_t *v3; // eax
  double v4; // st7
  CViewEffects *ViewEffects; // eax
  ScreenFade_t v6; // [esp+4h] [ebp-Ch] BYREF

  v3 = TextMessageGet(pName: "GAMETITLE");
  this->m_pGameTitle = v3;
  if ( v3 != nullptr )
  {
    v4 = *(float *)(gpGlobals.m_Index + 12);
    this->m_bHaveMessage = true;
    this->m_gameTitleTime = v4;
  }
  *(_DWORD *)&v6.r = -16777216;
  *(_DWORD *)&v6.duration = 33556992;
  v6.fadeFlags = 17;
  ViewEffects = GetViewEffects();
  ViewEffects->Fade(this: ViewEffects, a2: &v6);
  _Msg(a1: "%i gametitle fade\n", *(_DWORD *)(gpGlobals.m_Index + 4));
}

//------------------------------------------------------------------------------
// Address: 0x1011FE30
// Name: public: virtual int CHudMessage::GetFontInfo(struct FONTABC __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHudMessage::GetFontInfo(CHudMessage *this, FONTABC *pABCs, int hFont)
{
  char *pinToSibling; // edi
  int v5; // ebx
  int *p_abcC; // esi
  unsigned int v7; // eax
  FONTABC *v8; // ecx
  int v9; // edx
  int c; // [esp+4h] [ebp-4h] BYREF

  pinToSibling = (char *)hFont;
  if ( hFont == 0 )
  {
    pinToSibling = this->_pinToSibling;
    if ( pinToSibling == nullptr )
      return 0;
  }
  if ( pABCs != nullptr )
  {
    v5 = 0;
    p_abcC = &pABCs->abcC;
    do
    {
      g_pVGuiSurface->GetCharABCwide(
        this: g_pVGuiSurface,
        a2: (unsigned int)pinToSibling,
        a3: (char)v5,
        a4: &hFont,
        a5: (int *)&pABCs,
        a6: &c);
      v7 = hFont;
      v8 = pABCs;
      v9 = c;
      *(p_abcC - 2) = hFont;
      *(p_abcC - 1) = (int)v8;
      *p_abcC = v9;
      p_abcC[1] = (int)v8 + v7 + v9;
      ++v5;
      p_abcC += 4;
    }
    while ( v5 < 256 );
  }
  return g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: (unsigned int)pinToSibling);
}

//------------------------------------------------------------------------------
// Address: 0x1011FEC0
// Name: private: virtual void CHudMessage::GetTextExtents(int __near *,int __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::GetTextExtents(CHudMessage *this, int *wide, int *tall, char *string)
{
  *wide = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: this->m_hFont, a3: string);
  *tall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x1011FF10
// Name: public: virtual void CHudMessage::SetDefaultFont(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::SetDefaultFont(CHudMessage *this)
{
  ((void (__thiscall *)(CHudMessage *, _DWORD))this->Init)(a1: this, a2: *(_DWORD *)&this->_pinToSiblingCorner);
}

//------------------------------------------------------------------------------
// Address: 0x1011FF20
// Name: public: virtual void CHudMessage::GetLength(int __near *,int __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::GetLength(CHudMessage *this, int *wide, int *tall, const char *string)
{
  (*(void (__thiscall **)(char *, int *, int *, const char *))(*((_DWORD *)this - 97) + 72))(
    a1: (char *)this - 388,
    a2: wide,
    a3: tall,
    a4: string);
}

//------------------------------------------------------------------------------
// Address: 0x1011FF40
// Name: void DispatchHudText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchHudText(const char *pszText)
{
  CHud *v1; // eax
  CHudElement *v2; // eax
  CHud *Hud; // eax
  CHudMessage *Element; // eax

  if ( pszText != nullptr )
  {
    Hud = GetHud(nSlot: -1);
    Element = (CHudMessage *)CHud::FindElement(this: Hud, pName: "CHudMessage");
    CHudMessage::MessageAdd(this: Element, pName: pszText);
  }
  else
  {
    v1 = GetHud(nSlot: -1);
    v2 = CHud::FindElement(this: v1, pName: "CHudMessage");
    v2->Reset(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FF90
// Name: void __MsgFunc_CHudMessage_HudText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudMessage_HudText(bf_read *msg)
{
  CHud *Hud; // eax
  CHudMessage *Element; // esi
  char pStr[2048]; // [esp+4h] [ebp-800h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = (CHudMessage *)CHud::FindElement(this: Hud, pName: "CHudMessage");
  if ( Element != nullptr )
  {
    CBitRead::ReadString(this: msg, pStr, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
    CHudMessage::MessageAdd(this: Element, pName: pStr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FFF0
// Name: void __MsgFunc_CHudMessage_GameTitle(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudMessage_GameTitle(bf_read *msg)
{
  CHud *Hud; // eax
  CHudMessage *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudMessage *)CHud::FindElement(this: Hud, pName: "CHudMessage");
  if ( Element != nullptr )
    CHudMessage::MsgFunc_GameTitle(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10120020
// Name: public: void CHudMessage::MessageDrawScan(struct client_textmessage_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MessageDrawScan(CHudMessage *this, client_textmessage_t *pMessage, float time)
{
  signed int v4; // edi
  void *v5; // esp
  char *v6; // edx
  wchar_t *v7; // edi
  int v8; // ecx
  const char *pVGuiSchemeFontName; // eax
  unsigned int v10; // eax
  wchar_t i; // ax
  int v12; // edi
  int v13; // edi
  float v14; // xmm1_4
  int v15; // eax
  float v16; // xmm0_4
  int v17; // ecx
  unsigned __int8 v18; // dl
  char *v19; // edi
  wchar_t j; // ax
  float x; // xmm0_4
  int width; // ebx
  int v23; // edi
  int v24; // edi
  int y; // eax
  int k; // edi
  int totalWidth; // [esp+24h] [ebp-C18h]
  char v28[12]; // [esp+28h] [ebp-C14h] BYREF
  wchar_t textBuf[1024]; // [esp+34h] [ebp-C08h] BYREF
  wchar_t line[512]; // [esp+834h] [ebp-408h]
  const wchar_t *pPerm; // [esp+C34h] [ebp-8h]
  char *localString; // [esp+C38h] [ebp-4h]
  Color boxColor; // [esp+C48h] [ebp+Ch]
  float boxColora; // [esp+C48h] [ebp+Ch]
  Color boxColorb; // [esp+C48h] [ebp+Ch]

  v4 = _V_strlen(str: pMessage->pMessage);
  v5 = alloca(v4 + 2);
  v6 = (char *)pMessage->pMessage;
  localString = v28;
  V_strncpy(pDest: v28, pSrc: v6, maxLen: v4 + 2);
  if ( v4 > 0 && iscntrl(c: localString[v4 - 1]) != 0 )
    localString[v4 - 1] = 0;
  v7 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: localString);
  if ( v7 == nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pMessage->pMessage, a3: textBuf, a4: 2048);
    v7 = textBuf;
  }
  v8 = 0;
  this->m_parms.lines = 1;
  this->m_parms.time = time;
  this->m_parms.pMessage = pMessage;
  this->m_parms.totalWidth = 0;
  pVGuiSchemeFontName = pMessage->pVGuiSchemeFontName;
  pPerm = v7;
  localString = nullptr;
  boxColor = 0;
  this->m_parms.vguiFontName = pVGuiSchemeFontName;
  if ( this->m_parms.font == 0 )
  {
    if ( pVGuiSchemeFontName != nullptr && *pVGuiSchemeFontName != 0 )
    {
      totalWidth = (int)pVGuiSchemeFontName;
      v10 = g_pVGuiSchemeManager->GetDefaultScheme(this: g_pVGuiSchemeManager);
      CHudMessage::SetFont(this, scheme: v10, pFontName: (const char *)totalWidth);
      v8 = 0;
    }
    else
    {
      this->m_parms.font = g_hFontTrebuchet24;
    }
  }
  for ( i = *v7; i != 0; ++v7 )
  {
    if ( i == 10 )
    {
      ++this->m_parms.lines;
      if ( v8 > this->m_parms.totalWidth )
        this->m_parms.totalWidth = v8;
      boxColor = 0;
    }
    else
    {
      *(_DWORD *)&boxColor += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: this->m_parms.font, a3: i);
    }
    i = v7[1];
    ++localString;
    v8 = (int)boxColor;
  }
  if ( v8 > this->m_parms.totalWidth )
    this->m_parms.totalWidth = v8;
  this->m_parms.length = (int)localString;
  v12 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_parms.font);
  totalWidth = v12 * this->m_parms.lines;
  this->m_parms.totalHeight = totalWidth;
  this->m_parms.y = CHudMessage::YPosition(this, y: pMessage->y, height: totalWidth);
  localString = (char *)pPerm;
  this->m_parms.charTime = 0.0;
  CHudMessage::MessageScanStart(this);
  if ( pMessage->bRoundedRectBackdropBox )
  {
    totalWidth = this->m_parms.totalWidth;
    boxColora = (float)v12 * pMessage->flBoxSize;
    v13 = (int)(float)((float)CHudMessage::XPosition(this, x: pMessage->x, width: totalWidth, totalWidth) - boxColora);
    v14 = boxColora;
    v15 = (int)(float)((float)CHudMessage::YPosition(this, y: pMessage->y, height: this->m_parms.totalHeight)
                     - (float)(boxColora * 0.5));
    v16 = (float)(255.0 - (float)this->m_parms.fadeBlend) * 0.0039215689;
    if ( v16 >= 0.0 )
    {
      if ( v16 > 1.0 )
        v16 = 1.0;
    }
    else
    {
      v16 = 0.0;
    }
    boxColorb._color[1] = pMessage->boxcolor[1];
    v17 = pMessage->boxcolor[3];
    boxColorb._color[0] = pMessage->boxcolor[0];
    v18 = pMessage->boxcolor[2];
    totalWidth = 0;
    boxColorb._color[2] = v18;
    boxColorb._color[3] = (int)(float)((float)v17 * v16);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->DrawBox)(
      a1: v13,
      a2: v15,
      a3: (int)(float)((float)this->m_parms.totalWidth + (float)(v14 * 2.0)),
      a4: (int)(float)((float)((float)(v14 * 2.0) * 0.5) + (float)this->m_parms.totalHeight),
      a5: boxColorb,
      a6: 1065353216,
      a7: 0);
  }
  for ( pPerm = nullptr; (int)pPerm < this->m_parms.lines; pPerm = (const wchar_t *)((char *)pPerm + 1) )
  {
    v19 = localString;
    this->m_parms.lineLength = 0;
    this->m_parms.width = 0;
    for ( j = *(_WORD *)v19; j != 0; v19 += 2 )
    {
      if ( j == 10 )
        break;
      line[this->m_parms.lineLength] = j;
      this->m_parms.width += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: this->m_parms.font, a3: j);
      if ( ++this->m_parms.lineLength > 0x1FFu )
        this->m_parms.lineLength = 511;
      j = *((_WORD *)v19 + 1);
    }
    x = pMessage->x;
    width = this->m_parms.width;
    line[this->m_parms.lineLength] = 0;
    localString = v19 + 2;
    if ( x == -1.0 )
    {
      v24 = (ScreenWidth() - width) / 2;
    }
    else if ( x >= 0.0 )
    {
      v24 = (int)(float)((float)ScreenWidth() * x);
    }
    else
    {
      v23 = this->m_parms.totalWidth;
      v24 = (int)((double)ScreenWidth() * (float)(x + 1.0) - (double)v23);
    }
    if ( v24 + width <= ScreenWidth() )
    {
      if ( v24 < 0 )
        v24 = 0;
    }
    else
    {
      v24 = ScreenWidth() - width;
    }
    y = this->m_parms.y;
    this->m_parms.x = v24;
    textmessage->SetPosition(this: textmessage, a2: v24, a3: y);
    if ( this->m_parms.fadeBlend > 255 )
      this->m_parms.fadeBlend = 255;
    for ( k = 0; k < this->m_parms.lineLength; ++k )
    {
      this->m_parms.text = line[k];
      CHudMessage::MessageScanNextChar(this);
      textmessage->AddChar(
        this: textmessage,
        a2: this->m_parms.r,
        a3: this->m_parms.g,
        a4: this->m_parms.b,
        a5: 255 - this->m_parms.fadeBlend,
        a6: this->m_parms.text);
    }
    this->m_parms.y += g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_parms.font);
  }
  textmessage->SetDefaultFont(this: textmessage);
}

//------------------------------------------------------------------------------
// Address: 0x10120560
// Name: public: virtual bool CHudMessage::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudMessage::ShouldDraw(CHudMessage *this)
{
  return CHudElement::ShouldDraw(this) != 0 && (this->m_bHaveMessage || this->m_Messages.m_Size != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10120590
// Name: public: void CHudMessage::MsgFunc_HudMsg(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::MsgFunc_HudMsg(CHudMessage *this, bf_read *msg)
{
  int m_nBitsAvail; // edx
  unsigned int m_nInBufWord; // edi
  int v5; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v8; // ecx
  int v9; // eax
  const unsigned int *v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // ebx
  client_textmessage_t *v13; // eax
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  const unsigned int *v19; // edx
  unsigned int v20; // edi
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // ebx
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  const unsigned int *v28; // ecx
  const unsigned int *v29; // edx
  const unsigned int *v30; // edx
  unsigned int v31; // edi
  int v32; // eax
  const unsigned int *v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ebx
  int v36; // ecx
  unsigned int v37; // eax
  char v38; // dl
  int v39; // ecx
  const unsigned int *v40; // ecx
  unsigned int v41; // ecx
  const unsigned int *v42; // edx
  unsigned int v43; // edi
  const unsigned int *v44; // ecx
  unsigned int v45; // edx
  unsigned int v46; // ebx
  unsigned int v47; // edx
  int v48; // ecx
  unsigned int v49; // eax
  char v50; // dl
  int v51; // ecx
  const unsigned int *v52; // ecx
  unsigned int v53; // ecx
  const unsigned int *v54; // edx
  unsigned int v55; // edi
  const unsigned int *v56; // ecx
  unsigned int v57; // edx
  unsigned int v58; // ebx
  unsigned int v59; // edx
  int v60; // ecx
  unsigned int v61; // eax
  char v62; // dl
  int v63; // ecx
  const unsigned int *v64; // ecx
  unsigned int v65; // ecx
  const unsigned int *v66; // edx
  unsigned int v67; // edi
  const unsigned int *v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // ebx
  unsigned int v71; // edx
  int v72; // ecx
  unsigned int v73; // eax
  char v74; // dl
  int v75; // ecx
  const unsigned int *v76; // ecx
  unsigned int v77; // ecx
  const unsigned int *v78; // edx
  unsigned int v79; // edi
  const unsigned int *v80; // ecx
  unsigned int v81; // edx
  unsigned int v82; // ebx
  unsigned int v83; // edx
  int v84; // ecx
  unsigned int v85; // eax
  char v86; // dl
  int v87; // ecx
  const unsigned int *v88; // ecx
  unsigned int v89; // ecx
  const unsigned int *v90; // edx
  unsigned int v91; // edi
  const unsigned int *v92; // ecx
  unsigned int v93; // edx
  unsigned int v94; // ebx
  unsigned int v95; // edx
  int v96; // ecx
  unsigned int v97; // eax
  char v98; // dl
  int v99; // ecx
  const unsigned int *v100; // ecx
  unsigned int v101; // ecx
  const unsigned int *v102; // edx
  unsigned int v103; // edi
  const unsigned int *v104; // ecx
  unsigned int v105; // edx
  unsigned int v106; // ebx
  unsigned int v107; // edx
  int v108; // ecx
  unsigned int v109; // eax
  char v110; // dl
  int v111; // ecx
  const unsigned int *v112; // ecx
  unsigned int v113; // ecx
  const unsigned int *v114; // edx
  unsigned int v115; // edi
  const unsigned int *v116; // ecx
  unsigned int v117; // edx
  unsigned int v118; // ebx
  unsigned int v119; // edx
  int v120; // ecx
  unsigned int v121; // eax
  char v122; // dl
  int v123; // ecx
  const unsigned int *v124; // ecx
  unsigned int v125; // ecx
  const unsigned int *v126; // edx
  unsigned int v127; // edi
  const unsigned int *v128; // ecx
  unsigned int v129; // edx
  unsigned int v130; // ebx
  unsigned int v131; // edx
  int v132; // ecx
  unsigned int v133; // eax
  unsigned int v134; // edx
  int v135; // ecx
  const unsigned int *v136; // eax
  const unsigned int *v137; // ecx
  unsigned int v138; // ecx
  const unsigned int *v139; // edx
  unsigned int v140; // edi
  int v141; // eax
  const unsigned int *v142; // ecx
  unsigned int v143; // edx
  unsigned int v144; // ebx
  unsigned int v145; // edx
  int v146; // ecx
  unsigned int v147; // eax
  int v148; // ecx
  const unsigned int *v149; // ecx
  const unsigned int *v150; // edx
  const unsigned int *v151; // edx
  unsigned int v152; // edi
  int v153; // eax
  const unsigned int *v154; // ecx
  unsigned int v155; // edx
  unsigned int v156; // ebx
  int v157; // ecx
  unsigned int v158; // eax
  int v159; // ecx
  const unsigned int *v160; // ecx
  const unsigned int *v161; // edx
  const unsigned int *v162; // edx
  unsigned int v163; // edi
  int v164; // eax
  const unsigned int *v165; // ecx
  unsigned int v166; // edx
  unsigned int v167; // ebx
  int v168; // ecx
  unsigned int v169; // eax
  int v170; // ecx
  const unsigned int *v171; // ecx
  const unsigned int *v172; // edx
  const unsigned int *v173; // edx
  unsigned int v174; // edi
  int v175; // eax
  const unsigned int *v176; // ecx
  unsigned int v177; // edx
  unsigned int v178; // ebx
  int v179; // ecx
  unsigned int v180; // eax
  int v181; // ecx
  const unsigned int *v182; // ecx
  const unsigned int *v183; // edx
  const unsigned int *v184; // edx
  unsigned int v185; // edi
  int v186; // eax
  const unsigned int *v187; // ecx
  unsigned int v188; // edx
  unsigned int v189; // ebx
  char *pMessage; // ecx
  int channel; // [esp+10h] [ebp-8h]
  int v193; // [esp+14h] [ebp-4h]
  int v194; // [esp+14h] [ebp-4h]
  int v195; // [esp+14h] [ebp-4h]
  int v196; // [esp+14h] [ebp-4h]
  int v197; // [esp+14h] [ebp-4h]
  int v198; // [esp+14h] [ebp-4h]
  client_textmessage_t *pNetMessage; // [esp+20h] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  m_nInBufWord = msg->m_nInBufWord;
  if ( m_nBitsAvail >= 8 )
  {
    v5 = (unsigned __int8)m_nInBufWord;
    msg->m_nBitsAvail = m_nBitsAvail - 8;
    if ( m_nBitsAvail == 8 )
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        msg->m_nInBufWord = *m_pDataIn;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    else
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
    }
    goto LABEL_18;
  }
  v8 = msg->m_pDataIn;
  v9 = 8 - m_nBitsAvail;
  v10 = msg->m_pBufferEnd;
  if ( v8 == v10 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v8 > v10 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_15;
    }
    msg->m_nInBufWord = *v8;
  }
  msg->m_pDataIn = v8 + 1;
LABEL_15:
  if ( msg->m_bOverflow )
  {
    v5 = 0;
  }
  else
  {
    v11 = msg->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v9;
    v5 = v12 | m_nInBufWord;
    msg->m_nInBufWord = v11 >> v9;
  }
LABEL_18:
  channel = v5 % 6;
  v13 = TextMessageGet(pName: s_NetworkMessageNames[v5 % 6]);
  pNetMessage = v13;
  if ( v13 != nullptr && v13->pMessage != nullptr )
  {
    v14 = msg->m_nBitsAvail;
    if ( v14 >= 32 )
    {
      v15 = msg->m_nInBufWord;
      v16 = v14 - 32;
      msg->m_nBitsAvail = v16;
      if ( v16 != 0 )
      {
        msg->m_nInBufWord = 0;
        v193 = v15;
      }
      else
      {
        v17 = msg->m_pDataIn;
        v18 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v17 == v18 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v17 + 1;
          v193 = v15;
        }
        else
        {
          if ( v17 <= v18 )
          {
            msg->m_nInBufWord = *v17;
            msg->m_pDataIn = v17 + 1;
          }
          else
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
          }
          v193 = v15;
        }
      }
LABEL_38:
      LODWORD(pNetMessage->x) = v193;
      v25 = msg->m_nBitsAvail;
      if ( v25 >= 32 )
      {
        v26 = msg->m_nInBufWord;
        v27 = v25 - 32;
        msg->m_nBitsAvail = v27;
        if ( v27 != 0 )
        {
          msg->m_nInBufWord = 0;
          v194 = v26;
        }
        else
        {
          v28 = msg->m_pDataIn;
          v29 = msg->m_pBufferEnd;
          msg->m_nBitsAvail = 32;
          if ( v28 == v29 )
          {
            msg->m_nBitsAvail = 1;
            msg->m_nInBufWord = 0;
            msg->m_pDataIn = v28 + 1;
            v194 = v26;
          }
          else
          {
            if ( v28 <= v29 )
            {
              msg->m_nInBufWord = *v28;
              msg->m_pDataIn = v28 + 1;
            }
            else
            {
              msg->m_bOverflow = true;
              msg->m_nInBufWord = 0;
            }
            v194 = v26;
          }
        }
LABEL_56:
        LODWORD(pNetMessage->y) = v194;
        v36 = msg->m_nBitsAvail;
        if ( v36 >= 8 )
        {
          v37 = msg->m_nInBufWord;
          v38 = v37;
          v39 = v36 - 8;
          msg->m_nBitsAvail = v39;
          if ( v39 != 0 )
          {
            msg->m_nInBufWord = v37 >> 8;
          }
          else
          {
            v37 = (unsigned int)msg->m_pDataIn;
            v40 = msg->m_pBufferEnd;
            msg->m_nBitsAvail = 32;
            if ( (const unsigned int *)v37 == v40 )
            {
              msg->m_pDataIn = (const unsigned int *)(v37 + 4);
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              LOBYTE(v37) = v38;
            }
            else
            {
              if ( v37 <= (unsigned int)v40 )
              {
                v41 = *(_DWORD *)v37;
                msg->m_pDataIn = (const unsigned int *)(v37 + 4);
                msg->m_nInBufWord = v41;
              }
              else
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
              }
              LOBYTE(v37) = v38;
            }
          }
LABEL_74:
          pNetMessage->r1 = v37;
          v48 = msg->m_nBitsAvail;
          if ( v48 >= 8 )
          {
            v49 = msg->m_nInBufWord;
            v50 = v49;
            v51 = v48 - 8;
            msg->m_nBitsAvail = v51;
            if ( v51 != 0 )
            {
              msg->m_nInBufWord = v49 >> 8;
            }
            else
            {
              v49 = (unsigned int)msg->m_pDataIn;
              v52 = msg->m_pBufferEnd;
              msg->m_nBitsAvail = 32;
              if ( (const unsigned int *)v49 == v52 )
              {
                msg->m_pDataIn = (const unsigned int *)(v49 + 4);
                msg->m_nBitsAvail = 1;
                msg->m_nInBufWord = 0;
                LOBYTE(v49) = v50;
              }
              else
              {
                if ( v49 <= (unsigned int)v52 )
                {
                  v53 = *(_DWORD *)v49;
                  msg->m_pDataIn = (const unsigned int *)(v49 + 4);
                  msg->m_nInBufWord = v53;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
                LOBYTE(v49) = v50;
              }
            }
LABEL_92:
            pNetMessage->g1 = v49;
            v60 = msg->m_nBitsAvail;
            if ( v60 >= 8 )
            {
              v61 = msg->m_nInBufWord;
              v62 = v61;
              v63 = v60 - 8;
              msg->m_nBitsAvail = v63;
              if ( v63 != 0 )
              {
                msg->m_nInBufWord = v61 >> 8;
              }
              else
              {
                v61 = (unsigned int)msg->m_pDataIn;
                v64 = msg->m_pBufferEnd;
                msg->m_nBitsAvail = 32;
                if ( (const unsigned int *)v61 == v64 )
                {
                  msg->m_pDataIn = (const unsigned int *)(v61 + 4);
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  LOBYTE(v61) = v62;
                }
                else
                {
                  if ( v61 <= (unsigned int)v64 )
                  {
                    v65 = *(_DWORD *)v61;
                    msg->m_pDataIn = (const unsigned int *)(v61 + 4);
                    msg->m_nInBufWord = v65;
                  }
                  else
                  {
                    msg->m_bOverflow = true;
                    msg->m_nInBufWord = 0;
                  }
                  LOBYTE(v61) = v62;
                }
              }
LABEL_110:
              pNetMessage->b1 = v61;
              v72 = msg->m_nBitsAvail;
              if ( v72 >= 8 )
              {
                v73 = msg->m_nInBufWord;
                v74 = v73;
                v75 = v72 - 8;
                msg->m_nBitsAvail = v75;
                if ( v75 != 0 )
                {
                  msg->m_nInBufWord = v73 >> 8;
                }
                else
                {
                  v73 = (unsigned int)msg->m_pDataIn;
                  v76 = msg->m_pBufferEnd;
                  msg->m_nBitsAvail = 32;
                  if ( (const unsigned int *)v73 == v76 )
                  {
                    msg->m_pDataIn = (const unsigned int *)(v73 + 4);
                    msg->m_nBitsAvail = 1;
                    msg->m_nInBufWord = 0;
                    LOBYTE(v73) = v74;
                  }
                  else
                  {
                    if ( v73 <= (unsigned int)v76 )
                    {
                      v77 = *(_DWORD *)v73;
                      msg->m_pDataIn = (const unsigned int *)(v73 + 4);
                      msg->m_nInBufWord = v77;
                    }
                    else
                    {
                      msg->m_bOverflow = true;
                      msg->m_nInBufWord = 0;
                    }
                    LOBYTE(v73) = v74;
                  }
                }
LABEL_128:
                pNetMessage->a1 = v73;
                v84 = msg->m_nBitsAvail;
                if ( v84 >= 8 )
                {
                  v85 = msg->m_nInBufWord;
                  v86 = v85;
                  v87 = v84 - 8;
                  msg->m_nBitsAvail = v87;
                  if ( v87 != 0 )
                  {
                    msg->m_nInBufWord = v85 >> 8;
                  }
                  else
                  {
                    v85 = (unsigned int)msg->m_pDataIn;
                    v88 = msg->m_pBufferEnd;
                    msg->m_nBitsAvail = 32;
                    if ( (const unsigned int *)v85 == v88 )
                    {
                      msg->m_pDataIn = (const unsigned int *)(v85 + 4);
                      msg->m_nBitsAvail = 1;
                      msg->m_nInBufWord = 0;
                      LOBYTE(v85) = v86;
                    }
                    else
                    {
                      if ( v85 <= (unsigned int)v88 )
                      {
                        v89 = *(_DWORD *)v85;
                        msg->m_pDataIn = (const unsigned int *)(v85 + 4);
                        msg->m_nInBufWord = v89;
                      }
                      else
                      {
                        msg->m_bOverflow = true;
                        msg->m_nInBufWord = 0;
                      }
                      LOBYTE(v85) = v86;
                    }
                  }
LABEL_146:
                  pNetMessage->r2 = v85;
                  v96 = msg->m_nBitsAvail;
                  if ( v96 >= 8 )
                  {
                    v97 = msg->m_nInBufWord;
                    v98 = v97;
                    v99 = v96 - 8;
                    msg->m_nBitsAvail = v99;
                    if ( v99 != 0 )
                    {
                      msg->m_nInBufWord = v97 >> 8;
                    }
                    else
                    {
                      v97 = (unsigned int)msg->m_pDataIn;
                      v100 = msg->m_pBufferEnd;
                      msg->m_nBitsAvail = 32;
                      if ( (const unsigned int *)v97 == v100 )
                      {
                        msg->m_pDataIn = (const unsigned int *)(v97 + 4);
                        msg->m_nBitsAvail = 1;
                        msg->m_nInBufWord = 0;
                        LOBYTE(v97) = v98;
                      }
                      else
                      {
                        if ( v97 <= (unsigned int)v100 )
                        {
                          v101 = *(_DWORD *)v97;
                          msg->m_pDataIn = (const unsigned int *)(v97 + 4);
                          msg->m_nInBufWord = v101;
                        }
                        else
                        {
                          msg->m_bOverflow = true;
                          msg->m_nInBufWord = 0;
                        }
                        LOBYTE(v97) = v98;
                      }
                    }
LABEL_164:
                    pNetMessage->g2 = v97;
                    v108 = msg->m_nBitsAvail;
                    if ( v108 >= 8 )
                    {
                      v109 = msg->m_nInBufWord;
                      v110 = v109;
                      v111 = v108 - 8;
                      msg->m_nBitsAvail = v111;
                      if ( v111 != 0 )
                      {
                        msg->m_nInBufWord = v109 >> 8;
                      }
                      else
                      {
                        v109 = (unsigned int)msg->m_pDataIn;
                        v112 = msg->m_pBufferEnd;
                        msg->m_nBitsAvail = 32;
                        if ( (const unsigned int *)v109 == v112 )
                        {
                          msg->m_pDataIn = (const unsigned int *)(v109 + 4);
                          msg->m_nBitsAvail = 1;
                          msg->m_nInBufWord = 0;
                          LOBYTE(v109) = v110;
                        }
                        else
                        {
                          if ( v109 <= (unsigned int)v112 )
                          {
                            v113 = *(_DWORD *)v109;
                            msg->m_pDataIn = (const unsigned int *)(v109 + 4);
                            msg->m_nInBufWord = v113;
                          }
                          else
                          {
                            msg->m_bOverflow = true;
                            msg->m_nInBufWord = 0;
                          }
                          LOBYTE(v109) = v110;
                        }
                      }
LABEL_182:
                      pNetMessage->b2 = v109;
                      v120 = msg->m_nBitsAvail;
                      if ( v120 >= 8 )
                      {
                        v121 = msg->m_nInBufWord;
                        v122 = v121;
                        v123 = v120 - 8;
                        msg->m_nBitsAvail = v123;
                        if ( v123 != 0 )
                        {
                          msg->m_nInBufWord = v121 >> 8;
                        }
                        else
                        {
                          v121 = (unsigned int)msg->m_pDataIn;
                          v124 = msg->m_pBufferEnd;
                          msg->m_nBitsAvail = 32;
                          if ( (const unsigned int *)v121 == v124 )
                          {
                            msg->m_pDataIn = (const unsigned int *)(v121 + 4);
                            msg->m_nBitsAvail = 1;
                            msg->m_nInBufWord = 0;
                            LOBYTE(v121) = v122;
                          }
                          else
                          {
                            if ( v121 <= (unsigned int)v124 )
                            {
                              v125 = *(_DWORD *)v121;
                              msg->m_pDataIn = (const unsigned int *)(v121 + 4);
                              msg->m_nInBufWord = v125;
                            }
                            else
                            {
                              msg->m_bOverflow = true;
                              msg->m_nInBufWord = 0;
                            }
                            LOBYTE(v121) = v122;
                          }
                        }
LABEL_200:
                        pNetMessage->a2 = v121;
                        v132 = msg->m_nBitsAvail;
                        if ( v132 >= 8 )
                        {
                          v133 = msg->m_nInBufWord;
                          v134 = (unsigned __int8)v133;
                          v135 = v132 - 8;
                          msg->m_nBitsAvail = v135;
                          if ( v135 != 0 )
                          {
                            msg->m_nInBufWord = v133 >> 8;
                            v133 = (unsigned __int8)v133;
                          }
                          else
                          {
                            v136 = msg->m_pDataIn;
                            v137 = msg->m_pBufferEnd;
                            msg->m_nBitsAvail = 32;
                            if ( v136 == v137 )
                            {
                              msg->m_pDataIn = v136 + 1;
                              msg->m_nBitsAvail = 1;
                              msg->m_nInBufWord = 0;
                              v133 = v134;
                            }
                            else
                            {
                              if ( v136 <= v137 )
                              {
                                v138 = *v136;
                                msg->m_pDataIn = v136 + 1;
                                msg->m_nInBufWord = v138;
                              }
                              else
                              {
                                msg->m_bOverflow = true;
                                msg->m_nInBufWord = 0;
                              }
                              v133 = v134;
                            }
                          }
LABEL_218:
                          pNetMessage->effect = v133;
                          v146 = msg->m_nBitsAvail;
                          if ( v146 >= 32 )
                          {
                            v147 = msg->m_nInBufWord;
                            v148 = v146 - 32;
                            msg->m_nBitsAvail = v148;
                            if ( v148 != 0 )
                            {
                              msg->m_nInBufWord = 0;
                              v195 = v147;
                            }
                            else
                            {
                              v149 = msg->m_pDataIn;
                              v150 = msg->m_pBufferEnd;
                              msg->m_nBitsAvail = 32;
                              if ( v149 == v150 )
                              {
                                msg->m_nBitsAvail = 1;
                                msg->m_nInBufWord = 0;
                                msg->m_pDataIn = v149 + 1;
                                v195 = v147;
                              }
                              else
                              {
                                if ( v149 <= v150 )
                                {
                                  msg->m_nInBufWord = *v149;
                                  msg->m_pDataIn = v149 + 1;
                                }
                                else
                                {
                                  msg->m_bOverflow = true;
                                  msg->m_nInBufWord = 0;
                                }
                                v195 = v147;
                              }
                            }
LABEL_236:
                            LODWORD(pNetMessage->fadein) = v195;
                            v157 = msg->m_nBitsAvail;
                            if ( v157 >= 32 )
                            {
                              v158 = msg->m_nInBufWord;
                              v159 = v157 - 32;
                              msg->m_nBitsAvail = v159;
                              if ( v159 != 0 )
                              {
                                msg->m_nInBufWord = 0;
                                v196 = v158;
                              }
                              else
                              {
                                v160 = msg->m_pDataIn;
                                v161 = msg->m_pBufferEnd;
                                msg->m_nBitsAvail = 32;
                                if ( v160 == v161 )
                                {
                                  msg->m_nBitsAvail = 1;
                                  msg->m_nInBufWord = 0;
                                  msg->m_pDataIn = v160 + 1;
                                  v196 = v158;
                                }
                                else
                                {
                                  if ( v160 <= v161 )
                                  {
                                    msg->m_nInBufWord = *v160;
                                    msg->m_pDataIn = v160 + 1;
                                  }
                                  else
                                  {
                                    msg->m_bOverflow = true;
                                    msg->m_nInBufWord = 0;
                                  }
                                  v196 = v158;
                                }
                              }
LABEL_254:
                              LODWORD(pNetMessage->fadeout) = v196;
                              v168 = msg->m_nBitsAvail;
                              if ( v168 >= 32 )
                              {
                                v169 = msg->m_nInBufWord;
                                v170 = v168 - 32;
                                msg->m_nBitsAvail = v170;
                                if ( v170 != 0 )
                                {
                                  msg->m_nInBufWord = 0;
                                  v197 = v169;
                                }
                                else
                                {
                                  v171 = msg->m_pDataIn;
                                  v172 = msg->m_pBufferEnd;
                                  msg->m_nBitsAvail = 32;
                                  if ( v171 == v172 )
                                  {
                                    msg->m_nBitsAvail = 1;
                                    msg->m_nInBufWord = 0;
                                    msg->m_pDataIn = v171 + 1;
                                    v197 = v169;
                                  }
                                  else
                                  {
                                    if ( v171 <= v172 )
                                    {
                                      msg->m_nInBufWord = *v171;
                                      msg->m_pDataIn = v171 + 1;
                                    }
                                    else
                                    {
                                      msg->m_bOverflow = true;
                                      msg->m_nInBufWord = 0;
                                    }
                                    v197 = v169;
                                  }
                                }
LABEL_272:
                                LODWORD(pNetMessage->holdtime) = v197;
                                v179 = msg->m_nBitsAvail;
                                if ( v179 >= 32 )
                                {
                                  v180 = msg->m_nInBufWord;
                                  v181 = v179 - 32;
                                  msg->m_nBitsAvail = v181;
                                  if ( v181 == 0 )
                                  {
                                    v182 = msg->m_pDataIn;
                                    v183 = msg->m_pBufferEnd;
                                    msg->m_nBitsAvail = 32;
                                    if ( v182 == v183 )
                                    {
                                      msg->m_nBitsAvail = 1;
                                      msg->m_nInBufWord = 0;
                                      msg->m_pDataIn = v182 + 1;
                                      v198 = v180;
LABEL_289:
                                      pMessage = (char *)pNetMessage->pMessage;
                                      LODWORD(pNetMessage->fxtime) = v198;
                                      pNetMessage->pName = s_NetworkMessageNames[channel];
                                      CBitRead::ReadString(
                                        this: msg,
                                        pStr: pMessage,
                                        maxLen: 512,
                                        bLine: false,
                                        pOutNumChars: nullptr);
                                      CHudMessage::MessageAdd(this, pName: pNetMessage->pName);
                                      return;
                                    }
                                    if ( v182 <= v183 )
                                    {
                                      msg->m_nInBufWord = *v182;
                                      msg->m_pDataIn = v182 + 1;
                                      v198 = v180;
                                      goto LABEL_289;
                                    }
                                    msg->m_bOverflow = true;
                                  }
                                  msg->m_nInBufWord = 0;
                                  v198 = v180;
                                  goto LABEL_289;
                                }
                                v184 = msg->m_pBufferEnd;
                                v185 = msg->m_nInBufWord;
                                v186 = 32 - v179;
                                v187 = msg->m_pDataIn;
                                if ( v187 == v184 )
                                {
                                  msg->m_nBitsAvail = 1;
                                  msg->m_nInBufWord = 0;
                                  msg->m_bOverflow = true;
                                }
                                else
                                {
                                  if ( v187 > v184 )
                                  {
                                    msg->m_bOverflow = true;
                                    msg->m_nInBufWord = 0;
                                    goto LABEL_286;
                                  }
                                  msg->m_nInBufWord = *v187;
                                }
                                msg->m_pDataIn = v187 + 1;
LABEL_286:
                                if ( msg->m_bOverflow )
                                {
                                  v198 = 0;
                                }
                                else
                                {
                                  v188 = msg->m_nInBufWord;
                                  v189 = (v188 & CBitBuffer::s_nMaskTable[v186]) << msg->m_nBitsAvail;
                                  msg->m_nBitsAvail = 32 - v186;
                                  v198 = v189 | v185;
                                  msg->m_nInBufWord = v188 >> v186;
                                }
                                goto LABEL_289;
                              }
                              v173 = msg->m_pBufferEnd;
                              v174 = msg->m_nInBufWord;
                              v175 = 32 - v168;
                              v176 = msg->m_pDataIn;
                              if ( v176 == v173 )
                              {
                                msg->m_nBitsAvail = 1;
                                msg->m_nInBufWord = 0;
                                msg->m_bOverflow = true;
                              }
                              else
                              {
                                if ( v176 > v173 )
                                {
                                  msg->m_bOverflow = true;
                                  msg->m_nInBufWord = 0;
                                  goto LABEL_269;
                                }
                                msg->m_nInBufWord = *v176;
                              }
                              msg->m_pDataIn = v176 + 1;
LABEL_269:
                              if ( msg->m_bOverflow )
                              {
                                v197 = 0;
                              }
                              else
                              {
                                v177 = msg->m_nInBufWord;
                                v178 = (v177 & CBitBuffer::s_nMaskTable[v175]) << msg->m_nBitsAvail;
                                msg->m_nBitsAvail = 32 - v175;
                                v197 = v178 | v174;
                                msg->m_nInBufWord = v177 >> v175;
                              }
                              goto LABEL_272;
                            }
                            v162 = msg->m_pBufferEnd;
                            v163 = msg->m_nInBufWord;
                            v164 = 32 - v157;
                            v165 = msg->m_pDataIn;
                            if ( v165 == v162 )
                            {
                              msg->m_nBitsAvail = 1;
                              msg->m_nInBufWord = 0;
                              msg->m_bOverflow = true;
                            }
                            else
                            {
                              if ( v165 > v162 )
                              {
                                msg->m_bOverflow = true;
                                msg->m_nInBufWord = 0;
                                goto LABEL_251;
                              }
                              msg->m_nInBufWord = *v165;
                            }
                            msg->m_pDataIn = v165 + 1;
LABEL_251:
                            if ( msg->m_bOverflow )
                            {
                              v196 = 0;
                            }
                            else
                            {
                              v166 = msg->m_nInBufWord;
                              v167 = (v166 & CBitBuffer::s_nMaskTable[v164]) << msg->m_nBitsAvail;
                              msg->m_nBitsAvail = 32 - v164;
                              v196 = v167 | v163;
                              msg->m_nInBufWord = v166 >> v164;
                            }
                            goto LABEL_254;
                          }
                          v151 = msg->m_pBufferEnd;
                          v152 = msg->m_nInBufWord;
                          v153 = 32 - v146;
                          v154 = msg->m_pDataIn;
                          if ( v154 == v151 )
                          {
                            msg->m_nBitsAvail = 1;
                            msg->m_nInBufWord = 0;
                            msg->m_bOverflow = true;
                          }
                          else
                          {
                            if ( v154 > v151 )
                            {
                              msg->m_bOverflow = true;
                              msg->m_nInBufWord = 0;
                              goto LABEL_233;
                            }
                            msg->m_nInBufWord = *v154;
                          }
                          msg->m_pDataIn = v154 + 1;
LABEL_233:
                          if ( msg->m_bOverflow )
                          {
                            v195 = 0;
                          }
                          else
                          {
                            v155 = msg->m_nInBufWord;
                            v156 = (v155 & CBitBuffer::s_nMaskTable[v153]) << msg->m_nBitsAvail;
                            msg->m_nBitsAvail = 32 - v153;
                            v195 = v156 | v152;
                            msg->m_nInBufWord = v155 >> v153;
                          }
                          goto LABEL_236;
                        }
                        v139 = msg->m_pBufferEnd;
                        v140 = msg->m_nInBufWord;
                        v141 = 8 - v132;
                        v142 = msg->m_pDataIn;
                        if ( v142 == v139 )
                        {
                          msg->m_nBitsAvail = 1;
                          msg->m_nInBufWord = 0;
                          msg->m_bOverflow = true;
                        }
                        else
                        {
                          if ( v142 > v139 )
                          {
                            msg->m_bOverflow = true;
                            msg->m_nInBufWord = 0;
                            goto LABEL_215;
                          }
                          msg->m_nInBufWord = *v142;
                        }
                        msg->m_pDataIn = v142 + 1;
LABEL_215:
                        if ( msg->m_bOverflow )
                        {
                          v133 = 0;
                        }
                        else
                        {
                          v143 = msg->m_nInBufWord;
                          v144 = (v143 & CBitBuffer::s_nMaskTable[v141]) << msg->m_nBitsAvail;
                          msg->m_nBitsAvail = 32 - v141;
                          v145 = v143 >> v141;
                          v133 = v144 | v140;
                          msg->m_nInBufWord = v145;
                        }
                        goto LABEL_218;
                      }
                      v126 = msg->m_pBufferEnd;
                      v127 = msg->m_nInBufWord;
                      v121 = 8 - v120;
                      v128 = msg->m_pDataIn;
                      if ( v128 == v126 )
                      {
                        msg->m_nBitsAvail = 1;
                        msg->m_nInBufWord = 0;
                        msg->m_bOverflow = true;
                      }
                      else
                      {
                        if ( v128 > v126 )
                        {
                          msg->m_bOverflow = true;
                          msg->m_nInBufWord = 0;
                          goto LABEL_197;
                        }
                        msg->m_nInBufWord = *v128;
                      }
                      msg->m_pDataIn = v128 + 1;
LABEL_197:
                      if ( msg->m_bOverflow )
                      {
                        LOBYTE(v121) = 0;
                      }
                      else
                      {
                        v129 = msg->m_nInBufWord;
                        v130 = (v129 & CBitBuffer::s_nMaskTable[v121]) << msg->m_nBitsAvail;
                        msg->m_nBitsAvail = 32 - v121;
                        v131 = v129 >> v121;
                        LOBYTE(v121) = v130 | v127;
                        msg->m_nInBufWord = v131;
                      }
                      goto LABEL_200;
                    }
                    v114 = msg->m_pBufferEnd;
                    v115 = msg->m_nInBufWord;
                    v109 = 8 - v108;
                    v116 = msg->m_pDataIn;
                    if ( v116 == v114 )
                    {
                      msg->m_nBitsAvail = 1;
                      msg->m_nInBufWord = 0;
                      msg->m_bOverflow = true;
                    }
                    else
                    {
                      if ( v116 > v114 )
                      {
                        msg->m_bOverflow = true;
                        msg->m_nInBufWord = 0;
                        goto LABEL_179;
                      }
                      msg->m_nInBufWord = *v116;
                    }
                    msg->m_pDataIn = v116 + 1;
LABEL_179:
                    if ( msg->m_bOverflow )
                    {
                      LOBYTE(v109) = 0;
                    }
                    else
                    {
                      v117 = msg->m_nInBufWord;
                      v118 = (v117 & CBitBuffer::s_nMaskTable[v109]) << msg->m_nBitsAvail;
                      msg->m_nBitsAvail = 32 - v109;
                      v119 = v117 >> v109;
                      LOBYTE(v109) = v118 | v115;
                      msg->m_nInBufWord = v119;
                    }
                    goto LABEL_182;
                  }
                  v102 = msg->m_pBufferEnd;
                  v103 = msg->m_nInBufWord;
                  v97 = 8 - v96;
                  v104 = msg->m_pDataIn;
                  if ( v104 == v102 )
                  {
                    msg->m_nBitsAvail = 1;
                    msg->m_nInBufWord = 0;
                    msg->m_bOverflow = true;
                  }
                  else
                  {
                    if ( v104 > v102 )
                    {
                      msg->m_bOverflow = true;
                      msg->m_nInBufWord = 0;
                      goto LABEL_161;
                    }
                    msg->m_nInBufWord = *v104;
                  }
                  msg->m_pDataIn = v104 + 1;
LABEL_161:
                  if ( msg->m_bOverflow )
                  {
                    LOBYTE(v97) = 0;
                  }
                  else
                  {
                    v105 = msg->m_nInBufWord;
                    v106 = (v105 & CBitBuffer::s_nMaskTable[v97]) << msg->m_nBitsAvail;
                    msg->m_nBitsAvail = 32 - v97;
                    v107 = v105 >> v97;
                    LOBYTE(v97) = v106 | v103;
                    msg->m_nInBufWord = v107;
                  }
                  goto LABEL_164;
                }
                v90 = msg->m_pBufferEnd;
                v91 = msg->m_nInBufWord;
                v85 = 8 - v84;
                v92 = msg->m_pDataIn;
                if ( v92 == v90 )
                {
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  msg->m_bOverflow = true;
                }
                else
                {
                  if ( v92 > v90 )
                  {
                    msg->m_bOverflow = true;
                    msg->m_nInBufWord = 0;
                    goto LABEL_143;
                  }
                  msg->m_nInBufWord = *v92;
                }
                msg->m_pDataIn = v92 + 1;
LABEL_143:
                if ( msg->m_bOverflow )
                {
                  LOBYTE(v85) = 0;
                }
                else
                {
                  v93 = msg->m_nInBufWord;
                  v94 = (v93 & CBitBuffer::s_nMaskTable[v85]) << msg->m_nBitsAvail;
                  msg->m_nBitsAvail = 32 - v85;
                  v95 = v93 >> v85;
                  LOBYTE(v85) = v94 | v91;
                  msg->m_nInBufWord = v95;
                }
                goto LABEL_146;
              }
              v78 = msg->m_pBufferEnd;
              v79 = msg->m_nInBufWord;
              v73 = 8 - v72;
              v80 = msg->m_pDataIn;
              if ( v80 == v78 )
              {
                msg->m_nBitsAvail = 1;
                msg->m_nInBufWord = 0;
                msg->m_bOverflow = true;
              }
              else
              {
                if ( v80 > v78 )
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                  goto LABEL_125;
                }
                msg->m_nInBufWord = *v80;
              }
              msg->m_pDataIn = v80 + 1;
LABEL_125:
              if ( msg->m_bOverflow )
              {
                LOBYTE(v73) = 0;
              }
              else
              {
                v81 = msg->m_nInBufWord;
                v82 = (v81 & CBitBuffer::s_nMaskTable[v73]) << msg->m_nBitsAvail;
                msg->m_nBitsAvail = 32 - v73;
                v83 = v81 >> v73;
                LOBYTE(v73) = v82 | v79;
                msg->m_nInBufWord = v83;
              }
              goto LABEL_128;
            }
            v66 = msg->m_pBufferEnd;
            v67 = msg->m_nInBufWord;
            v61 = 8 - v60;
            v68 = msg->m_pDataIn;
            if ( v68 == v66 )
            {
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              msg->m_bOverflow = true;
            }
            else
            {
              if ( v68 > v66 )
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
                goto LABEL_107;
              }
              msg->m_nInBufWord = *v68;
            }
            msg->m_pDataIn = v68 + 1;
LABEL_107:
            if ( msg->m_bOverflow )
            {
              LOBYTE(v61) = 0;
            }
            else
            {
              v69 = msg->m_nInBufWord;
              v70 = (v69 & CBitBuffer::s_nMaskTable[v61]) << msg->m_nBitsAvail;
              msg->m_nBitsAvail = 32 - v61;
              v71 = v69 >> v61;
              LOBYTE(v61) = v70 | v67;
              msg->m_nInBufWord = v71;
            }
            goto LABEL_110;
          }
          v54 = msg->m_pBufferEnd;
          v55 = msg->m_nInBufWord;
          v49 = 8 - v48;
          v56 = msg->m_pDataIn;
          if ( v56 == v54 )
          {
            msg->m_nBitsAvail = 1;
            msg->m_nInBufWord = 0;
            msg->m_bOverflow = true;
          }
          else
          {
            if ( v56 > v54 )
            {
              msg->m_bOverflow = true;
              msg->m_nInBufWord = 0;
              goto LABEL_89;
            }
            msg->m_nInBufWord = *v56;
          }
          msg->m_pDataIn = v56 + 1;
LABEL_89:
          if ( msg->m_bOverflow )
          {
            LOBYTE(v49) = 0;
          }
          else
          {
            v57 = msg->m_nInBufWord;
            v58 = (v57 & CBitBuffer::s_nMaskTable[v49]) << msg->m_nBitsAvail;
            msg->m_nBitsAvail = 32 - v49;
            v59 = v57 >> v49;
            LOBYTE(v49) = v58 | v55;
            msg->m_nInBufWord = v59;
          }
          goto LABEL_92;
        }
        v42 = msg->m_pBufferEnd;
        v43 = msg->m_nInBufWord;
        v37 = 8 - v36;
        v44 = msg->m_pDataIn;
        if ( v44 == v42 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        else
        {
          if ( v44 > v42 )
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
            goto LABEL_71;
          }
          msg->m_nInBufWord = *v44;
        }
        msg->m_pDataIn = v44 + 1;
LABEL_71:
        if ( msg->m_bOverflow )
        {
          LOBYTE(v37) = 0;
        }
        else
        {
          v45 = msg->m_nInBufWord;
          v46 = (v45 & CBitBuffer::s_nMaskTable[v37]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v37;
          v47 = v45 >> v37;
          LOBYTE(v37) = v46 | v43;
          msg->m_nInBufWord = v47;
        }
        goto LABEL_74;
      }
      v30 = msg->m_pBufferEnd;
      v31 = msg->m_nInBufWord;
      v32 = 32 - v25;
      v33 = msg->m_pDataIn;
      if ( v33 == v30 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      else
      {
        if ( v33 > v30 )
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
          goto LABEL_53;
        }
        msg->m_nInBufWord = *v33;
      }
      msg->m_pDataIn = v33 + 1;
LABEL_53:
      if ( msg->m_bOverflow )
      {
        v194 = 0;
      }
      else
      {
        v34 = msg->m_nInBufWord;
        v35 = (v34 & CBitBuffer::s_nMaskTable[v32]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v32;
        v194 = v35 | v31;
        msg->m_nInBufWord = v34 >> v32;
      }
      goto LABEL_56;
    }
    v19 = msg->m_pBufferEnd;
    v20 = msg->m_nInBufWord;
    v21 = 32 - v14;
    v22 = msg->m_pDataIn;
    if ( v22 == v19 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v22 > v19 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_35;
      }
      msg->m_nInBufWord = *v22;
    }
    msg->m_pDataIn = v22 + 1;
LABEL_35:
    if ( msg->m_bOverflow )
    {
      v193 = 0;
    }
    else
    {
      v23 = msg->m_nInBufWord;
      v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v21;
      v193 = v24 | v20;
      msg->m_nInBufWord = v23 >> v21;
    }
    goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121420
// Name: void __MsgFunc_CHudMessage_HudMsg(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudMessage_HudMsg(bf_read *msg)
{
  CHud *Hud; // eax
  CHudMessage *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudMessage *)CHud::FindElement(this: Hud, pName: "CHudMessage");
  if ( Element != nullptr )
    CHudMessage::MsgFunc_HudMsg(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10121450
// Name: public: virtual void CHudMessage::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::Init(CHudMessage *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "HudText", hook: __MsgFunc_CHudMessage_HudText);
  CUserMessages::HookMessage(this: usermessages, name: "GameTitle", hook: __MsgFunc_CHudMessage_GameTitle);
  CUserMessages::HookMessage(this: usermessages, name: "HudMsg", hook: __MsgFunc_CHudMessage_HudMsg);
  this->Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x101214A0
// Name: private: void CHudMessage::ResetCharacters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::ResetCharacters(CHudMessage *this)
{
  bool v2; // sf
  CHudMessage::message_t *m_pMemory; // ecx

  v2 = this->m_Messages.m_Memory.m_nGrowSize < 0;
  this->m_Messages.m_Size = 0;
  if ( v2 )
  {
    this->m_Messages.m_pElements = this->m_Messages.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Messages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Messages.m_Memory.m_pMemory);
      this->m_Messages.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Messages.m_Memory.m_pMemory;
    this->m_Messages.m_Memory.m_nAllocationCount = 0;
    this->m_Messages.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121500
// Name: private: void CHudMessage::PaintCharacters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::PaintCharacters(CHudMessage *this)
{
  void (__thiscall *DrawSetTextFont)(vgui::ISurface *, unsigned int); // eax
  int m_Size; // eax
  CHudMessage::message_t *v4; // esi
  unsigned int font; // esi
  unsigned int v6; // eax
  int y; // eax
  CHudMessage::message_t *m_pMemory; // ecx
  unsigned int m_hFont; // [esp-4h] [ebp-28h]
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  int i; // [esp+14h] [ebp-10h]
  int ypos; // [esp+18h] [ebp-Ch]
  unsigned int v15; // [esp+1Ch] [ebp-8h]
  int xpos; // [esp+20h] [ebp-4h]

  DrawSetTextFont = g_pVGuiSurface->DrawSetTextFont;
  m_hFont = this->m_hFont;
  xpos = 0;
  ypos = 0;
  DrawSetTextFont(this: g_pVGuiSurface, a2: m_hFont);
  m_Size = this->m_Messages.m_Size;
  if ( m_Size > 0 )
  {
    v15 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v4 = &this->m_Messages.m_Memory.m_pMemory[v15 / 0x10];
      switch ( v4->type )
      {
        case 1u:
          y = v4->y;
          xpos = v4->x;
          ypos = y;
          break;
        case 2u:
          v6 = this->m_hFont;
          if ( v6 != 0 )
          {
            g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: v6, a3: v4->ch, a4: &a, a5: &b, a6: &c);
            if ( v4->ch > 0x20u )
            {
              ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor_2)(
                a1: v4->r,
                a2: v4->g,
                a3: v4->b,
                a4: v4->a);
              g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: xpos, a3: ypos);
              ((void (__stdcall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawUnicodeChar)(a1: v4->ch, a2: 0);
            }
            xpos += c + b + a;
          }
          break;
        case 3u:
          font = v4->font;
          this->m_hFont = font;
          g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
          break;
        default:
          break;
      }
      v15 += 16;
    }
  }
  this->m_Messages.m_Size = 0;
  if ( this->m_Messages.m_Memory.m_nGrowSize < 0 )
  {
    this->m_Messages.m_pElements = this->m_Messages.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Messages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Messages.m_Memory.m_pMemory);
      this->m_Messages.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Messages.m_Memory.m_pMemory;
    this->m_Messages.m_Memory.m_nAllocationCount = 0;
    this->m_Messages.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101216E0
// Name: public: CHudMessage::CHudMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudMessage *__thiscall CHudMessage::CHudMessage(CHudMessage *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax
  unsigned int v8; // edx

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudMessage");
  this->ITextMessage::__vftable = (ITextMessage_vtbl *)&ITextMessage::`vftable';
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudMessage_vtbl *)&CHudMessage::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudMessage::`vftable'{for `vgui::Panel'};
  this->ITextMessage::__vftable = (ITextMessage_vtbl *)&CHudMessage::`vftable'{for `ITextMessage'};
  if ( `CHudMessage::ChainToMap'::`2'::chained == 0 )
  {
    `CHudMessage::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudMessage");
    v3->pfnClassName = CHudMessage::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudMessage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudMessage::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudMessage");
    v4->pfnClassName = CHudMessage::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudMessage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudMessage::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudMessage");
    v5->pfnClassName = CHudMessage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_Messages.m_Memory.m_pMemory = nullptr;
  this->m_Messages.m_Memory.m_nAllocationCount = 0;
  this->m_Messages.m_Memory.m_nGrowSize = 0;
  this->m_Messages.m_Size = 0;
  this->m_Messages.m_pElements = nullptr;
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  if ( textmessage == nullptr )
    textmessage = &this->ITextMessage;
  v8 = g_hFontTrebuchet24;
  this->m_hFont = g_hFontTrebuchet24;
  this->m_hDefaultFont = v8;
  CHudMessage::ResetCharacters(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10121840
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudMessage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudMessage::GetMessageMap(CHudMessage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudMessage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudMessage::GetMessageMap'::`2'::s_pMap;
  `CHudMessage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudMessage");
  `CHudMessage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121870
// Name: public: virtual struct PanelAnimationMap __near * CHudMessage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudMessage::GetAnimMap(CHudMessage *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudMessage");
}

//------------------------------------------------------------------------------
// Address: 0x10121880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudMessage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudMessage::GetKBMap(CHudMessage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudMessage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudMessage::GetKBMap'::`2'::s_pMap;
  `CHudMessage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudMessage");
  `CHudMessage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101218B0
// Name: public: virtual void CHudMessage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::Paint(CHudMessage *this)
{
  int totalHeight; // xmm1_4
  float v3; // xmm0_4
  float *width; // edx
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  _DWORD *length; // ecx
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  _BYTE *v14; // eax
  unsigned __int8 v15; // cl
  unsigned __int8 v16; // dl
  CHudTexture *v17; // ecx
  _BYTE *v18; // eax
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // dl
  float *v21; // eax
  int i; // ecx
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  vgui::Panel::PanelAnimationVar_m_nPaintBackgroundType *p_m_m_nPaintBackgroundType_register; // edi
  client_textmessage_t *v31; // eax
  int effect; // ecx
  float v33; // xmm0_4
  float v34; // xmm1_4
  bool v35; // zf
  int y; // [esp+4h] [ebp-24h]
  int xa; // [esp+18h] [ebp-10h]
  int x; // [esp+18h] [ebp-10h]
  float brightness; // [esp+1Ch] [ebp-Ch]
  float brightnessa; // [esp+1Ch] [ebp-Ch]
  Color drawn; // [esp+20h] [ebp-8h] BYREF
  unsigned __int8 v42; // [esp+27h] [ebp-1h]

  totalHeight = this->m_parms.totalHeight;
  drawn = 0;
  if ( *(float *)&totalHeight > 0.0 )
  {
    v3 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&totalHeight;
    if ( *(float *)&totalHeight > *(float *)(gpGlobals.m_Index + 12) )
      this->m_parms.totalHeight = *(int *)(gpGlobals.m_Index + 12);
    width = (float *)this->m_parms.width;
    v5 = width[5];
    v6 = width[7];
    v7 = width[6];
    if ( v3 <= (float)((float)(v5 + v6) + v7) )
    {
      v8 = v6 + v5;
      if ( v3 >= 0.0 )
      {
        if ( v5 <= v3 )
        {
          if ( v3 <= v8 )
          {
            v9 = 1.0;
          }
          else if ( v7 <= 0.0 )
          {
            v9 = 0.0;
          }
          else
          {
            v9 = 1.0 - (float)((float)(v3 - v8) / v7);
          }
        }
        else
        {
          v9 = 1.0 - (float)((float)(v5 - v3) / v5);
        }
        brightness = v9;
      }
      else
      {
        brightness = 0.0;
      }
      length = (_DWORD *)this->m_parms.length;
      v11 = length[40] - length[39];
      v12 = length[42] - length[41];
      y = v11 + *(_DWORD *)(this->m_parms.lineLength + 160) - *(_DWORD *)(this->m_parms.lineLength + 156);
      xa = CHudMessage::XPosition(this: (CHudMessage *)((char *)this - 56), x: width[3], width: y, totalWidth: y);
      v13 = CHudMessage::YPosition(
              this: (CHudMessage *)((char *)this - 56),
              y: *(float *)(this->m_parms.width + 16),
              height: v12);
      v14 = (_BYTE *)this->m_parms.width;
      v15 = v14[6];
      v16 = v14[5];
      drawn._color[0] = v14[4];
      drawn._color[2] = v15;
      v17 = (CHudTexture *)this->m_parms.length;
      drawn._color[1] = v16;
      v42 = (int)(float)(brightness * 255.0);
      drawn._color[3] = v42;
      CHudTexture::DrawSelf(this: v17, x: xa, y: v13, clr: &drawn, flApparentZ: 1.0);
      v18 = (_BYTE *)this->m_parms.width;
      v19 = v18[6];
      v20 = v18[5];
      LOBYTE(v18) = v18[4];
      drawn._color[2] = v19;
      drawn._color[1] = v20;
      drawn._color[0] = (unsigned __int8)v18;
      drawn._color[3] = v42;
      CHudTexture::DrawSelf(
        this: (CHudTexture *)this->m_parms.lineLength,
        x: v11 + xa,
        y: v13,
        clr: &drawn,
        flApparentZ: 1.0);
      drawn = (Color)1;
    }
    else
    {
      this->m_parms.totalHeight = 0;
    }
  }
  v21 = (float *)&this->m_pMessages[2];
  for ( i = 4; i != 0; --i )
  {
    if ( *((_DWORD *)v21 - 16) != 0 )
    {
      v23 = *(float *)(gpGlobals.m_Index + 12);
      if ( *v21 > v23 )
        *v21 = (float)((float)(this->m_startTime[3] + v23) - *v21) + 0.2;
    }
    if ( *((_DWORD *)v21 - 15) != 0 )
    {
      v24 = v21[1];
      v25 = *(float *)(gpGlobals.m_Index + 12);
      if ( v24 > v25 )
        v21[1] = (float)((float)(this->m_startTime[3] + v25) - v24) + 0.2;
    }
    if ( *((_DWORD *)v21 - 14) != 0 )
    {
      v26 = v21[2];
      v27 = *(float *)(gpGlobals.m_Index + 12);
      if ( v26 > v27 )
        v21[2] = (float)((float)(this->m_startTime[3] + v27) - v26) + 0.2;
    }
    if ( *((_DWORD *)v21 - 13) != 0 )
    {
      v28 = v21[3];
      v29 = *(float *)(gpGlobals.m_Index + 12);
      if ( v28 > v29 )
        v21[3] = (float)((float)(this->m_startTime[3] + v29) - v28) + 0.2;
    }
    v21 += 4;
  }
  p_m_m_nPaintBackgroundType_register = &this->m_m_nPaintBackgroundType_register;
  for ( x = 16; x != 0; --x )
  {
    v31 = *(client_textmessage_t **)p_m_m_nPaintBackgroundType_register;
    if ( *(_DWORD *)p_m_m_nPaintBackgroundType_register == 0 )
      goto LABEL_42;
    effect = v31->effect;
    if ( v31->effect >= 0 )
    {
      if ( effect <= 1 )
      {
        v33 = (float)((float)(*(float *)&p_m_m_nPaintBackgroundType_register[64] + v31->fadein) + v31->fadeout)
            + v31->holdtime;
        goto LABEL_39;
      }
      if ( effect == 2 )
      {
        brightnessa = (double)strlen(v31->pMessage) * v31->fadein
                    + *(float *)&p_m_m_nPaintBackgroundType_register[64]
                    + v31->fadeout
                    + v31->holdtime;
        v33 = brightnessa;
        goto LABEL_39;
      }
    }
    v33 = 0.0;
LABEL_39:
    v34 = *(float *)(gpGlobals.m_Index + 12);
    if ( v33 < v34 )
    {
      *(_DWORD *)p_m_m_nPaintBackgroundType_register = 0;
    }
    else
    {
      CHudMessage::MessageDrawScan(
        this: (CHudMessage *)((char *)this - 56),
        pMessage: v31,
        time: v34 - *(float *)&p_m_m_nPaintBackgroundType_register[64]);
      ++*(_DWORD *)&drawn;
    }
LABEL_42:
    p_m_m_nPaintBackgroundType_register += 4;
  }
  v35 = drawn == 0;
  this->m_startTime[3] = *(float *)(gpGlobals.m_Index + 12);
  if ( v35 )
    LOBYTE(this->m_parms.lines) = 0;
  CHudMessage::PaintCharacters(this: (CHudMessage *)((char *)this - 56));
}

//------------------------------------------------------------------------------
// Address: 0x10121C80
// Name: public: virtual void CHudMessage::SetPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::SetPosition(CHudMessage *this, __int16 x, __int16 y)
{
  unsigned int v4; // esi

  if ( (int)this->m_sNavUpName.m_Storage.m_Memory.m_pMemory < 2048 )
  {
    v4 = this->m_pinSibling.m_iPanelID
       + 16
       * CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int>>::AddToTail(this: (CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int> > *)&this->m_pinSibling);
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 0;
    *(_WORD *)(v4 + 12) = 0;
    *(_BYTE *)(v4 + 14) = 0;
    *(_DWORD *)v4 = 0;
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 83) + 132))(a1: (char *)this - 332, a2: 1);
    *(_BYTE *)(v4 + 10) = 1;
    *(_WORD *)(v4 + 4) = x;
    *(_WORD *)(v4 + 6) = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121CF0
// Name: public: virtual void CHudMessage::AddChar(int,int,int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::AddChar(CHudMessage *this, char r, char g, char b, char a, wchar_t ch)
{
  unsigned int v7; // esi

  if ( (int)this->m_sNavUpName.m_Storage.m_Memory.m_pMemory < 2048 )
  {
    v7 = this->m_pinSibling.m_iPanelID
       + 16
       * CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int>>::AddToTail(this: (CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int> > *)&this->m_pinSibling);
    *(_DWORD *)(v7 + 4) = 0;
    *(_DWORD *)(v7 + 8) = 0;
    *(_WORD *)(v7 + 12) = 0;
    *(_BYTE *)(v7 + 14) = 0;
    *(_DWORD *)v7 = 0;
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 83) + 132))(a1: (char *)this - 332, a2: 1);
    *(_BYTE *)(v7 + 11) = r;
    *(_BYTE *)(v7 + 12) = g;
    *(_BYTE *)(v7 + 10) = 2;
    *(_BYTE *)(v7 + 13) = b;
    *(_BYTE *)(v7 + 14) = a;
    *(_WORD *)(v7 + 8) = ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121D70
// Name: public: virtual void CHudMessage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMessage::SetFont(CHudMessage *this, char *hCustomFont)
{
  unsigned int v3; // esi

  this->_pinToSibling = hCustomFont;
  if ( (int)this->m_sNavUpName.m_Storage.m_Memory.m_pMemory < 2048 )
  {
    v3 = this->m_pinSibling.m_iPanelID
       + 16
       * CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int>>::AddToTail(this: (CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int> > *)&this->m_pinSibling);
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_WORD *)(v3 + 12) = 0;
    *(_BYTE *)(v3 + 14) = 0;
    *(_DWORD *)v3 = 0;
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 83) + 132))(a1: (char *)this - 332, a2: 1);
    *(_BYTE *)(v3 + 10) = 3;
    *(_DWORD *)v3 = this->_pinToSibling;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121DE0
// Name: Create_CHudMessage
// Source: json
//------------------------------------------------------------------------------
CHudMessage *__cdecl Create_CHudMessage()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 648);
  memset(dst: v0, value: 0, count: 0x288u);
  if ( v0 != nullptr )
    return CHudMessage::CHudMessage(this: (CHudMessage *)v0, pElementName: "CHudMessage");
  else
    return nullptr;
}
