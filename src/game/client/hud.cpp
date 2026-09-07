// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud.cpp
// Functions: 50
// ============================================================

#include "game\client\hud.h"

//------------------------------------------------------------------------------
// Address: 0x100EE190
// Name: bool RenderGroupLessFunc(class CHudElement __near * const __near &,class CHudElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RenderGroupLessFunc(CHudElement *const *lhs, CHudElement *const *rhs)
{
  int v2; // esi
  int v3; // edi

  v2 = (int)*rhs;
  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 64))(a1: *lhs);
  return v3 < (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 64))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EE1C0
// Name: public: virtual void CHudElement::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudElement::SetActive(CHudElement *this, bool bActive)
{
  this->m_bActive = bActive;
}

//------------------------------------------------------------------------------
// Address: 0x100EE1E0
// Name: class CHud __near & GetHud(int)
// Source: json
//------------------------------------------------------------------------------
CHud *__cdecl GetHud(int nSlot)
{
  int v1; // eax

  v1 = nSlot;
  if ( nSlot == -1 )
    v1 = 0;
  return &gHUD[v1];
}

//------------------------------------------------------------------------------
// Address: 0x100EE200
// Name: void MsgFunc_ResetHUD(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_ResetHUD(bf_read *msg)
{
  CHud::MsgFunc_ResetHUD(this: gHUD, msg);
}

//------------------------------------------------------------------------------
// Address: 0x100EE220
// Name: void MsgFunc_SendAudio(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_SendAudio(bf_read *msg)
{
  CHud::MsgFunc_SendAudio(this: gHUD, msg);
}

//------------------------------------------------------------------------------
// Address: 0x100EE250
// Name: public: void CHudTexture::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTexture::Precache(CHudTexture *this)
{
  unsigned int hFont; // eax
  wchar_t wideChars[2]; // [esp+4h] [ebp-4h] BYREF

  if ( this->bRenderUsingFont && !this->bPrecached )
  {
    hFont = this->hFont;
    if ( hFont != 0 )
    {
      wideChars[0] = this->cCharacterInFont;
      wideChars[1] = 0;
      g_pVGuiSurface->PrecacheFontCharacters(this: g_pVGuiSurface, a2: hFont, a3: wideChars);
      this->bPrecached = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE2B0
// Name: public: void CHudTexture::DrawSelf(int,int,int,int,class Color const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTexture::DrawSelf(
        CHudTexture *this,
        int x,
        int y,
        int w,
        int h,
        const Color *clr,
        float flApparentZ)
{
  if ( this->bRenderUsingFont )
  {
    ((void (__stdcall *)(_DWORD))g_pVGuiSurface->DrawSetApparentDepth)(a1: LODWORD(flApparentZ));
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->hFont);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: *clr);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: y);
    ((void (__stdcall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawUnicodeChar)(
      a1: (unsigned __int16)this->cCharacterInFont,
      a2: 0);
    g_pVGuiSurface->DrawClearApparentDepth(this: g_pVGuiSurface);
  }
  else if ( this->textureId != -1 )
  {
    ((void (__stdcall *)(_DWORD))g_pVGuiSurface->DrawSetApparentDepth)(a1: LODWORD(flApparentZ));
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->textureId);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: *clr);
    ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawTexturedSubRect)(
      a1: g_pVGuiSurface,
      a2: x,
      a3: y,
      a4: x + w,
      a5: y + h,
      a6: LODWORD(this->texCoords[0]),
      a7: LODWORD(this->texCoords[1]),
      a8: LODWORD(this->texCoords[2]),
      a9: LODWORD(this->texCoords[3]));
    g_pVGuiSurface->DrawClearApparentDepth(this: g_pVGuiSurface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE410
// Name: public: void CHud::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHud::OnRestore(CHud *this)
{
  CHud::ResetHUD(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EE420
// Name: public: float CHud::GetSensitivity(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHud::GetSensitivity(CHud *this)
{
  return this->m_flMouseSensitivity;
}

//------------------------------------------------------------------------------
// Address: 0x100EE430
// Name: public: float CHud::GetFOVSensitivityAdjust(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHud::GetFOVSensitivityAdjust(CHud *this)
{
  return this->m_flFOVSensitivityAdjust;
}

//------------------------------------------------------------------------------
// Address: 0x100EE440
// Name: public: void CHud::ProcessInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::ProcessInput(CHud *this, bool bActive)
{
  if ( bActive )
  {
    this->m_iKeyBits = input->GetButtonBits(this: input, a2: false);
    CHud::Think(this: gHUD);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE470
// Name: public: void CHud::UpdateHud(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::UpdateHud(CHud *this, bool bActive)
{
  IClientMode *ClientMode; // eax

  this->m_iKeyBits &= 0xFFCFFFFF;
  ClientMode = GetClientMode();
  ClientMode->Update(this: ClientMode);
  CLCD::Update(this: &gLCD);
}

//------------------------------------------------------------------------------
// Address: 0x100EE4A0
// Name: private: void CHudIcons::SetupNewHudTexture(class CHudTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudIcons::SetupNewHudTexture(CHudIcons *this, CHudTexture *t)
{
  CHudTexture *v2; // esi
  unsigned int v3; // eax
  vgui::IScheme *v4; // eax
  unsigned int v5; // eax
  int cCharacterInFont; // edi
  int v7; // eax
  float v8; // xmm1_4
  float top; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  int tall; // [esp+8h] [ebp-4h] BYREF

  v2 = t;
  if ( t->bRenderUsingFont )
  {
    v3 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "basemodui_scheme");
    v4 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v3);
    v5 = v4->GetFont(this: v4, a2: v2->szTextureFile, a3: true);
    cCharacterInFont = v2->cCharacterInFont;
    v2->hFont = v5;
    v2->rc.top = 0;
    v2->rc.left = 0;
    v2->rc.right = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v5, a3: cCharacterInFont);
    v2->rc.bottom = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2->hFont);
  }
  else
  {
    v7 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v2->textureId = v7;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v7, a3: v2->szTextureFile, a4: 0, a5: false);
    g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: v2->textureId, a3: (int *)&t, a4: &tall);
    v8 = (float)(int)t;
    top = (float)v2->rc.top;
    v2->texCoords[0] = (float)((float)v2->rc.left + 0.5) / (float)(int)t;
    v10 = (float)tall;
    v2->texCoords[1] = (float)(top + 0.5) / (float)tall;
    v11 = (float)((float)v2->rc.right - 0.5) / v8;
    v12 = (float)((float)v2->rc.bottom - 0.5) / v10;
    v2->texCoords[2] = v11;
    v2->texCoords[3] = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE620
// Name: class CHudIcons __near & HudIcons(void)
// Source: json
//------------------------------------------------------------------------------
CHudIcons *__cdecl HudIcons()
{
  return &g_HudIcons;
}

//------------------------------------------------------------------------------
// Address: 0x100EE630
// Name: public: CHudTexture::CHudTexture(void)
// Source: json
//------------------------------------------------------------------------------
CHudTexture *__thiscall CHudTexture::CHudTexture(CHudTexture *this)
{
  _V_memset(dest: (int)this, fill: nullptr, count: 0x40u);
  _V_memset(dest: (int)this->szTextureFile, fill: nullptr, count: 0x40u);
  _V_memset(dest: (int)this->texCoords, fill: nullptr, count: 0x10u);
  _V_memset(dest: (int)&this->rc, fill: nullptr, count: 0x10u);
  *(_WORD *)&this->bRenderUsingFont = 0;
  this->cCharacterInFont = 0;
  this->hFont = 0;
  this->textureId = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EE690
// Name: public: class CHudTexture __near & CHudTexture::operator=(class CHudTexture const __near &)
// Source: json
//------------------------------------------------------------------------------
CHudTexture *__thiscall CHudTexture::operator=(CHudTexture *this, const CHudTexture *src)
{
  if ( this != src )
  {
    V_strncpy(pDest: this->szShortName, pSrc: src->szShortName, maxLen: 64);
    V_strncpy(pDest: this->szTextureFile, pSrc: src->szTextureFile, maxLen: 64);
    _V_memcpy(dest: (unsigned __int8 *)this->texCoords, src: (unsigned __int8 *)src->texCoords, count: 0x10u);
    this->textureId = src->textureId;
    this->rc = src->rc;
    this->bRenderUsingFont = src->bRenderUsingFont;
    this->cCharacterInFont = src->cCharacterInFont;
    this->hFont = src->hFont;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EE730
// Name: protected: void CHudElement::InitCHudElementAfterConstruction(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudElement::InitCHudElementAfterConstruction(CHudElement *this, const char *pElementName)
{
  this->m_pHud = nullptr;
  this->m_bActive = false;
  this->m_iHiddenBits = 0;
  this->m_pElementName = pElementName;
  this->m_nSplitScreenPlayerSlot = -1;
  *(_WORD *)&this->m_bNeedsRemove = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EE760
// Name: public: void CHud::InitColors(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::InitColors(CHud *this, int scheme)
{
  vgui::IScheme *v2; // esi
  Color v4; // ecx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx

  v2 = (vgui::IScheme *)scheme;
  v4 = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)scheme + 20))(
                   a1: scheme,
                   a2: &scheme,
                   a3: "Normal",
                   a4: -12529409);
  scheme = -16764673;
  this->m_clrNormal = v4;
  this->m_clrCaution = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                   a1: v2,
                                   a2: &scheme,
                                   a3: "Caution",
                                   a4: -16764673);
  GetColor = v2->GetColor;
  scheme = -16736001;
  this->m_clrYellowish = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                                     a1: v2,
                                     a2: &scheme,
                                     a3: "Yellowish",
                                     a4: -16736001);
}

//------------------------------------------------------------------------------
// Address: 0x100EE7E0
// Name: public: void CHudTexture::DrawSelf(int,int,class Color const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTexture::DrawSelf(CHudTexture *this, int x, int y, const Color *clr, float flApparentZ)
{
  CHudTexture::DrawSelf(
    this,
    x,
    y,
    w: this->rc.right - this->rc.left,
    h: this->rc.bottom - this->rc.top,
    clr,
    flApparentZ);
}

//------------------------------------------------------------------------------
// Address: 0x100EE820
// Name: public: void CHudTexture::DrawSelfCropped(int,int,int,int,int,int,int,int,class Color,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTexture::DrawSelfCropped(
        CHudTexture *this,
        int x,
        int y,
        int cropx,
        int cropy,
        int cropw,
        int croph,
        int finalWidth,
        int finalHeight,
        Color clr,
        float flApparentZ)
{
  int v13; // edi
  int v14; // ecx
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  void (__thiscall *DrawSetApparentDepth)(vgui::ISurface *, float); // eax
  FontCharRenderInfo info; // [esp+24h] [ebp-3Ch] BYREF
  float tCoords[4]; // [esp+50h] [ebp-10h]
  float frac; // [esp+7Ch] [ebp+1Ch]

  if ( this->bRenderUsingFont )
  {
    v13 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->hFont);
    frac = (float)(v13 - croph) / (float)v13;
    ((void (__stdcall *)(_DWORD))g_pVGuiSurface->DrawSetApparentDepth)(a1: LODWORD(flApparentZ));
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->hFont);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: clr);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: y - cropy);
    if ( ((unsigned __int8 (__stdcall *)(_DWORD, FontCharRenderInfo *))g_pVGuiSurface->DrawGetUnicodeCharRenderInfo)(
           a1: (unsigned __int16)this->cCharacterInFont,
           a2: &info) != 0 )
    {
      if ( cropy != 0 )
      {
        info.verts->m_Position.y = (float)((float)(info.verts[1].m_Position.y - info.verts->m_Position.y) * frac)
                                 + info.verts->m_Position.y;
        info.verts->m_TexCoord.y = (float)((float)(info.verts[1].m_TexCoord.y - info.verts->m_TexCoord.y) * frac)
                                 + info.verts->m_TexCoord.y;
      }
      else if ( croph != v13 )
      {
        info.verts[1].m_Position.y = (float)((float)(info.verts[1].m_Position.y - info.verts->m_Position.y)
                                           * (float)(1.0 - frac))
                                   + info.verts->m_Position.y;
        info.verts[1].m_TexCoord.y = (float)((float)(info.verts[1].m_TexCoord.y - info.verts->m_TexCoord.y)
                                           * (float)(1.0 - frac))
                                   + info.verts->m_TexCoord.y;
      }
      g_pVGuiSurface->DrawRenderCharFromInfo(this: g_pVGuiSurface, a2: &info);
    }
    g_pVGuiSurface->DrawClearApparentDepth(this: g_pVGuiSurface);
  }
  else if ( this->textureId != -1 )
  {
    v14 = this->rc.bottom - this->rc.top;
    v15 = this->texCoords[0];
    v16 = this->texCoords[1];
    v17 = this->texCoords[3];
    v18 = this->texCoords[2] - v15;
    v19 = 1.0 / (float)(this->rc.right - this->rc.left);
    tCoords[0] = (float)((float)((float)cropx * v19) * v18) + v15;
    v20 = v17 - v16;
    tCoords[1] = (float)((float)((float)cropy * (float)(1.0 / (float)v14)) * v20) + v16;
    DrawSetApparentDepth = g_pVGuiSurface->DrawSetApparentDepth;
    tCoords[3] = (float)((float)((float)(croph + cropy) * (float)(1.0 / (float)v14)) * v20) + v16;
    tCoords[2] = (float)((float)((float)(cropw + cropx) * v19) * v18) + v15;
    ((void (__stdcall *)(_DWORD))DrawSetApparentDepth)(a1: LODWORD(flApparentZ));
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->textureId);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawTexturedSubRect)(
      a1: g_pVGuiSurface,
      a2: x,
      a3: y,
      a4: x + finalWidth,
      a5: y + finalHeight,
      a6: LODWORD(tCoords[0]),
      a7: LODWORD(tCoords[1]),
      a8: LODWORD(tCoords[2]),
      a9: LODWORD(tCoords[3]));
    g_pVGuiSurface->DrawClearApparentDepth(this: g_pVGuiSurface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEB20
// Name: public: bool CHud::IsHidden(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHud::IsHidden(CHud *this, int iHudFlags)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v5; // edi
  int m_iHideHUD; // ebx
  ConVar *m_pConVarState; // edx
  IClientMode *ClientMode; // eax
  int v9; // ecx
  SplitScreenConVarRef hidehudref; // [esp+4h] [ebp-10h] BYREF

  if ( !this->m_bEngineIsInGame )
    return true;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: this->m_nSplitScreenSlot);
  v5 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return true;
  m_iHideHUD = LocalPlayer->m_Local.m_iHideHUD;
  SplitScreenConVarRef::SplitScreenConVarRef(this: &hidehudref, pName: "hidehud");
  m_pConVarState = hidehudref.m_Info[this->m_nSplitScreenSlot].m_pConVarState;
  if ( m_pConVarState->m_Value.m_nValue != 0 )
    m_iHideHUD = m_pConVarState->m_Value.m_nValue;
  ClientMode = GetClientMode();
  if ( ((double (__thiscall *)(IClientMode *))ClientMode->GetBlurFade)(a1: ClientMode) != 0.0
    || (m_iHideHUD & 4) != 0
    || engine->IsLevelMainMenuBackground(this: engine) )
  {
    return true;
  }
  v9 = iHudFlags;
  if ( (iHudFlags & 0x10) != 0 )
  {
    if ( v5->GetHealth(this: v5) <= 0 )
      return true;
    v9 = iHudFlags;
  }
  if ( (v9 & 0x20) != 0 && !v5->m_Local.m_bWearingSuit )
    return true;
  return (v9 & m_iHideHUD) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EEC00
// Name: testhudanim
// Source: json
//------------------------------------------------------------------------------
void __cdecl testhudanim(const CCommand *args)
{
  IClientMode *ClientMode; // eax
  const char *v2; // edx
  vgui::AnimationController *v3; // eax
  const char *v4; // [esp-4h] [ebp-8h]

  if ( args->m_nArgc == 2 )
  {
    ClientMode = GetClientMode();
    v2 = prType;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v4 = v2;
    v3 = ClientMode->GetViewportAnimationController(this: ClientMode);
    vgui::AnimationController::StartAnimationSequence(this: v3, sequenceName: v4);
  }
  else
  {
    _Msg(a1: "Usage:\n   testhudanim <anim name>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EECB0
// Name: public: void CHud::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::LevelShutdown(CHud *this)
{
  int i; // esi
  CHudElement *v3; // ecx

  for ( i = 0; i < this->m_HudList.m_Size; ++i )
  {
    v3 = this->m_HudList.m_Memory.m_pMemory[i];
    v3->LevelShutdown(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EECE0
// Name: public: void CHud::VidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::VidInit(CHud *this)
{
  int i; // esi
  CHudElement *v3; // ecx

  for ( i = 0; i < this->m_HudList.m_Size; ++i )
  {
    v3 = this->m_HudList.m_Memory.m_pMemory[i];
    v3->VidInit(this: v3);
  }
  CHud::ResetHUD(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EED10
// Name: public: class CHudElement __near * CHud::FindElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudElement *__thiscall CHud::FindElement(CHud *this, const char *pName)
{
  int v3; // edi
  CHudElement *v4; // ecx
  const char *v5; // eax

  v3 = 0;
  if ( this->m_HudList.m_Size <= 0 )
  {
LABEL_4:
    _DevWarning(a1: 1, a2: "[%d] Could not find Hud Element: %s\n", this->m_nSplitScreenSlot, pName);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_HudList.m_Memory.m_pMemory[v3];
      v5 = v4->GetName(this: v4);
      if ( _V_stricmp(s1: v5, s2: pName) == 0 )
        return this->m_HudList.m_Memory.m_pMemory[v3];
      if ( ++v3 >= this->m_HudList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EED70
// Name: public: void CHud::OnSplitScreenStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::OnSplitScreenStateChanged(CHud *this)
{
  int i; // esi
  CHudElement *v3; // ecx

  for ( i = 0; i < this->m_HudList.m_Size; ++i )
  {
    v3 = this->m_HudList.m_Memory.m_pMemory[i];
    v3->OnSplitScreenStateChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF780
// Name: public: void CHud::RemoveHudElement(class CHudElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::RemoveHudElement(CHud *this, CHudElement *pHudElement)
{
  int m_Size; // eax
  int v4; // edi
  CHudElement **m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_HudList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v4 = -1;
  }
  else
  {
    m_pMemory = this->m_HudList.m_Memory.m_pMemory;
    while ( *m_pMemory != pHudElement )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
  }
  v6 = m_Size - v4 - 1;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&this->m_HudList.m_Memory.m_pMemory[v4],
      src: (unsigned __int8 *)&this->m_HudList.m_Memory.m_pMemory[v4 + 1],
      count: 4 * v6);
  --this->m_HudList.m_Size;
  if ( this->m_HudPanelList.m_Size - v4 - 1 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&this->m_HudPanelList.m_Memory.m_pMemory[v4],
      src: (unsigned __int8 *)&this->m_HudPanelList.m_Memory.m_pMemory[v4 + 1],
      count: 4 * (this->m_HudPanelList.m_Size - v4 - 1));
  --this->m_HudPanelList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100F08B0
// Name: public: CHudElement::CHudElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudElement *__thiscall CHudElement::CHudElement(CHudElement *this, const char *pElementName)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->__vftable = (CHudElement_vtbl *)&CHudElement::`vftable';
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_pHud = nullptr;
  this->m_bActive = false;
  this->m_iHiddenBits = 0;
  this->m_pElementName = pElementName;
  this->m_nSplitScreenPlayerSlot = -1;
  *(_WORD *)&this->m_bNeedsRemove = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F0900
// Name: public: virtual CHudElement::~CHudElement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudElement::~CHudElement(CHudElement *this)
{
  bool v2; // zf

  v2 = !this->m_bNeedsRemove;
  this->__vftable = (CHudElement_vtbl *)&CHudElement::`vftable';
  if ( !v2 )
    CHud::RemoveHudElement(this: gHUD, pHudElement: this);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_HudRenderGroups);
  v2 = !this->m_bRegisteredForEvents;
  this->__vftable = (CHudElement_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->__vftable = (CHudElement_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100F0960
// Name: public: void CHud::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::Shutdown(CHud *this)
{
  int i; // edi
  CHudElement *v3; // ecx

  CLCD::Shutdown(this: &gLCD);
  for ( i = this->m_HudList.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_HudList.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CHudElement *, int))v3->dtr_IGameEventListener2)(a1: v3, a2: 1);
  }
  this->m_HudList.m_Size = 0;
  if ( this->m_HudList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HudList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HudList.m_Memory.m_pMemory);
      this->m_HudList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HudList.m_pElements = this->m_HudList.m_Memory.m_pMemory;
  this->m_HudPanelList.m_Size = 0;
  if ( this->m_HudPanelList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HudPanelList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HudPanelList.m_Memory.m_pMemory);
      this->m_HudPanelList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudPanelList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HudPanelList.m_pElements = this->m_HudPanelList.m_Memory.m_pMemory;
  g_HudIcons.m_bHudTexturesLoaded = false;
}

//------------------------------------------------------------------------------
// Address: 0x100F1670
// Name: public: void CHud::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::LevelInit(CHud *this)
{
  int i; // esi
  CHudElement *v3; // ecx
  int m_NumElements; // ecx
  int v5; // ebx
  CHudRenderGroup *elem; // esi
  int iCount; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_HudList.m_Size; ++i )
  {
    v3 = this->m_HudList.m_Memory.m_pMemory[i];
    v3->LevelInit(this: v3);
  }
  m_NumElements = this->m_RenderGroups.m_Tree.m_NumElements;
  v5 = 0;
  iCount = m_NumElements;
  if ( this->m_RenderGroups.m_Tree.m_NumElements != 0 )
  {
    do
    {
      elem = this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem;
      elem->bHidden = false;
      elem->m_pLockingElements.m_heap.m_Size = 0;
      if ( elem->m_pLockingElements.m_heap.m_Memory.m_nGrowSize >= 0 )
      {
        if ( elem->m_pLockingElements.m_heap.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_pLockingElements.m_heap.m_Memory.m_pMemory);
          m_NumElements = iCount;
          elem->m_pLockingElements.m_heap.m_Memory.m_pMemory = nullptr;
        }
        elem->m_pLockingElements.m_heap.m_Memory.m_nAllocationCount = 0;
      }
      ++v5;
      elem->m_pLockingElements.m_heap.m_pElements = elem->m_pLockingElements.m_heap.m_Memory.m_pMemory;
    }
    while ( v5 < m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1700
// Name: public: void CHud::AddHudElement(class CHudElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::AddHudElement(CHud *this, vgui::TreeNode *pHudElement)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_HudList; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v7; // eax
  vgui::TreeNode **v8; // eax
  vgui::Panel *v9; // eax
  int v10; // edi
  int v11; // eax
  vgui::Panel **v12; // ecx
  int v13; // eax
  vgui::Panel **v14; // eax
  vgui::Panel *pPanel; // [esp+18h] [ebp+8h]

  p_m_HudList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_HudList;
  pHudElement->m_LastNavDirection = ND_UP;
  m_nAllocationCount = this->m_HudList.m_Memory.m_nAllocationCount;
  m_Size = this->m_HudList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_HudList, num: m_Size - m_nAllocationCount + 1);
  ++p_m_HudList[1].m_pMemory;
  m_pMemory = p_m_HudList->m_pMemory;
  v7 = (int)p_m_HudList[1].m_pMemory - m_Size - 1;
  p_m_HudList[1].m_nAllocationCount = (int)p_m_HudList->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &p_m_HudList->m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pHudElement;
  v9 = (vgui::Panel *)__RTDynamicCast(
                        inptr: pHudElement,
                        VfDelta: 0,
                        SrcType: &CHudElement `RTTI Type Descriptor',
                        TargetType: &vgui::Panel `RTTI Type Descriptor',
                        isReference: 0);
  v10 = this->m_HudPanelList.m_Size;
  pPanel = v9;
  v11 = this->m_HudPanelList.m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v11 )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_HudPanelList,
      num: v10 - v11 + 1);
  ++this->m_HudPanelList.m_Size;
  v12 = this->m_HudPanelList.m_Memory.m_pMemory;
  v13 = this->m_HudPanelList.m_Size - v10 - 1;
  this->m_HudPanelList.m_pElements = v12;
  if ( v13 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v12[v10 + 1], src: (unsigned __int8 *)&v12[v10], count: 4 * v13);
  v14 = &this->m_HudPanelList.m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    *v14 = pPanel;
  ((void (__thiscall *)(vgui::TreeNode *, CHud *))pHudElement->PaintTraverse)(a1: pHudElement, a2: this);
  pHudElement->m_InternalMouseDoublePressed_register = (vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed)1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1BA0
// Name: void FreeHudTextureList(class CUtlDict<class CHudTexture __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeHudTextureList(CUtlDict<CHudTexture *,int> *list)
{
  int m_NumElements; // ebx
  int v2; // esi
  int i; // esi

  m_NumElements = list->m_Elements.m_Tree.m_NumElements;
  if ( m_NumElements > 0 )
  {
    v2 = 0;
    do
    {
      C_BaseEntity::operator delete(pMem: (void *)list->m_Elements.m_Tree.m_Elements.m_pMemory[v2++].m_Data.elem);
      --m_NumElements;
    }
    while ( m_NumElements != 0 );
  }
  for ( i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &list->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
              this: &list->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)list->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &list->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100F1C20
// Name: public: bool CHud::LockRenderGroup(int,class CHudElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHud::LockRenderGroup(CHud *this, int iGroupIndex, CHudElement *pLocker)
{
  CHudRenderGroup *elem; // esi
  int m_Size; // ecx
  int v7; // eax
  CHudElement **m_pMemory; // edx
  CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  search.key = iGroupIndex;
  if ( CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_RenderGroups.m_Tree,
         &search) == 0xFFFF )
    return 0;
  search.key = iGroupIndex;
  elem = this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                                            this: &this->m_RenderGroups.m_Tree,
                                                            &search)].m_Data.elem;
  if ( elem == nullptr )
    return 0;
  if ( pLocker != nullptr )
  {
    m_Size = elem->m_pLockingElements.m_heap.m_Size;
    v7 = 0;
    if ( m_Size <= 0 )
    {
LABEL_9:
      CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::Insert(
        this: &elem->m_pLockingElements,
        element: &pLocker);
    }
    else
    {
      m_pMemory = elem->m_pLockingElements.m_heap.m_Memory.m_pMemory;
      while ( pLocker != *m_pMemory )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_9;
      }
    }
    return 1;
  }
  else
  {
    elem->bHidden = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1CC0
// Name: public: bool CHud::UnlockRenderGroup(int,class CHudElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHud::UnlockRenderGroup(CHud *this, int iGroupIndex, CHudElement *pLocker)
{
  CHudRenderGroup *elem; // eax
  int m_Size; // esi
  int v7; // edx
  CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int> > *p_m_pLockingElements; // ecx
  CHudElement **i; // eax
  CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  search.key = iGroupIndex;
  if ( CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_RenderGroups.m_Tree,
         &search) == 0xFFFF )
    return 0;
  search.key = iGroupIndex;
  elem = this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                                            this: &this->m_RenderGroups.m_Tree,
                                                            &search)].m_Data.elem;
  if ( elem == nullptr )
    return 0;
  if ( elem->bHidden && pLocker == nullptr )
  {
    elem->bHidden = false;
    return 1;
  }
  m_Size = elem->m_pLockingElements.m_heap.m_Size;
  v7 = 0;
  if ( m_Size <= 0 )
    return 0;
  p_m_pLockingElements = &elem->m_pLockingElements;
  for ( i = elem->m_pLockingElements.m_heap.m_Memory.m_pMemory; pLocker != *i; ++i )
  {
    if ( ++v7 >= m_Size )
      return 0;
  }
  CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int>>::RemoveAt(
    this: p_m_pLockingElements,
    index: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1D60
// Name: public: bool CHud::IsRenderGroupLockedFor(class CHudElement __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHud::IsRenderGroupLockedFor(CHud *this, CHudElement *pHudElement, int iGroupIndex)
{
  bool result; // al
  CHudRenderGroup *elem; // eax
  CHudElement *v6; // ecx
  int v7; // edi
  CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  search.key = iGroupIndex;
  if ( CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_RenderGroups.m_Tree,
         &search) != 0xFFFF )
  {
    search.key = iGroupIndex;
    elem = this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                                              this: &this->m_RenderGroups.m_Tree,
                                                              &search)].m_Data.elem;
    if ( elem != nullptr )
    {
      if ( elem->bHidden )
        return true;
      if ( elem->m_pLockingElements.m_heap.m_Size != 0 )
      {
        if ( pHudElement == nullptr )
          return true;
        v6 = *elem->m_pLockingElements.m_heap.m_Memory.m_pMemory;
        result = false;
        if ( v6 != pHudElement )
        {
          v7 = v6->GetRenderGroupPriority(this: v6);
          if ( v7 > pHudElement->GetRenderGroupPriority(this: pHudElement) )
            return true;
        }
        return result;
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100F1E10
// Name: public: class CHudTexture __near * CHudIcons::GetIcon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudTexture *__thiscall CHudIcons::GetIcon(CHudIcons *this, const char *szIcon)
{
  int v3; // eax
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( szIcon != nullptr
    && (search.key = szIcon,
        (v3 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                this: &this->m_Icons.m_Elements.m_Tree,
                &search)) != -1) )
  {
    return this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1EC0
// Name: public: virtual bool CHudElement::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudElement::ShouldDraw(CHudElement *this)
{
  CHud *m_pHud; // ecx
  int m_Size; // ebx
  int v4; // esi
  CHud *Hud; // [esp+Ch] [ebp-8h]

  m_pHud = this->m_pHud;
  if ( m_pHud == nullptr || CHud::IsHidden(this: m_pHud, iHudFlags: this->m_iHiddenBits) )
    return 0;
  m_Size = this->m_HudRenderGroups.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 1;
  Hud = GetHud(nSlot: -1);
  while ( !CHud::IsRenderGroupLockedFor(
             this: Hud,
             pHudElement: this,
             iGroupIndex: this->m_HudRenderGroups.m_Memory.m_pMemory[v4]) )
  {
    if ( ++v4 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F1F40
// Name: public: CHudIcons::~CHudIcons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudIcons::~CHudIcons(CHudIcons *this)
{
  int v2; // esi
  int v3; // edi
  CUtlDict<CHudTexture *,int> *p_m_Icons; // esi
  int i; // edi
  int j; // edi

  v2 = this->m_Icons.m_Elements.m_Tree.m_NumElements - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlMemoryPool::Free(
        this: &g_HudTextureMemoryPool,
        memBlock: (void *)this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v3--].m_Data.elem);
      --v2;
    }
    while ( v2 >= 0 );
  }
  p_m_Icons = &this->m_Icons;
  for ( i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Icons.m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
              this: &p_m_Icons->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &p_m_Icons->m_Elements.m_Tree);
  for ( j = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &p_m_Icons->m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
              this: &p_m_Icons->m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &p_m_Icons->m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &p_m_Icons->m_Elements.m_Tree);
  this->m_Icons.m_Elements.m_Tree.m_FirstFree = -1;
  if ( this->m_Icons.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory);
      this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Icons.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Icons.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_Icons.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory);
      this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Icons.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F20D0
// Name: public: CHud::~CHud(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::~CHud(CHud *this)
{
  unsigned __int16 v2; // ax
  int v3; // ebx
  CHudRenderGroup *elem; // esi
  CHudElement **m_pMemory; // eax
  const char **v6; // eax
  vgui::Panel **v7; // eax
  CHudElement **v8; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = this->m_RenderGroups.m_Tree.m_NumElements - 1;
  i = this->m_RenderGroups.m_Tree.m_NumElements - 1;
  if ( this->m_RenderGroups.m_Tree.m_NumElements != 0 )
  {
    do
    {
      v3 = v2;
      elem = this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
      if ( v2 != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_RenderGroups.m_Tree,
          elem: v2);
        this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[v3].m_Left = i;
        this->m_RenderGroups.m_Tree.m_Elements.m_pMemory[v3].m_Right = this->m_RenderGroups.m_Tree.m_FirstFree;
        --this->m_RenderGroups.m_Tree.m_NumElements;
        this->m_RenderGroups.m_Tree.m_FirstFree = i;
      }
      if ( elem != nullptr )
      {
        elem->m_pLockingElements.m_heap.m_Size = 0;
        if ( elem->m_pLockingElements.m_heap.m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_pLockingElements.m_heap.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_pLockingElements.m_heap.m_Memory.m_pMemory);
            elem->m_pLockingElements.m_heap.m_Memory.m_pMemory = nullptr;
          }
          elem->m_pLockingElements.m_heap.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = elem->m_pLockingElements.m_heap.m_Memory.m_pMemory;
        elem->m_pLockingElements.m_heap.m_pElements = m_pMemory;
        if ( elem->m_pLockingElements.m_heap.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            elem->m_pLockingElements.m_heap.m_Memory.m_pMemory = nullptr;
          }
          elem->m_pLockingElements.m_heap.m_Memory.m_nAllocationCount = 0;
        }
        C_BaseEntity::operator delete(pMem: elem);
      }
      v2 = --i;
    }
    while ( i >= 0 );
  }
  CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderGroups.m_Tree);
  this->m_RenderGroups.m_Tree.m_FirstFree = -1;
  if ( this->m_RenderGroups.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderGroups.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderGroups.m_Tree.m_Elements.m_pMemory);
      this->m_RenderGroups.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_RenderGroups.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_RenderGroups.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_RenderGroups.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderGroups.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderGroups.m_Tree.m_Elements.m_pMemory);
      this->m_RenderGroups.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_RenderGroups.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_RenderGroupNames.m_Size = 0;
  if ( this->m_RenderGroupNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderGroupNames.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderGroupNames.m_Memory.m_pMemory);
      this->m_RenderGroupNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderGroupNames.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_RenderGroupNames.m_Memory.m_pMemory;
  this->m_RenderGroupNames.m_pElements = v6;
  if ( this->m_RenderGroupNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_RenderGroupNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderGroupNames.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HudPanelList.m_Size = 0;
  if ( this->m_HudPanelList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HudPanelList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HudPanelList.m_Memory.m_pMemory);
      this->m_HudPanelList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudPanelList.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_HudPanelList.m_Memory.m_pMemory;
  this->m_HudPanelList.m_pElements = v7;
  if ( this->m_HudPanelList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_HudPanelList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudPanelList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HudList.m_Size = 0;
  if ( this->m_HudList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HudList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HudList.m_Memory.m_pMemory);
      this->m_HudList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudList.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_HudList.m_Memory.m_pMemory;
  this->m_HudList.m_pElements = v8;
  if ( this->m_HudList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_HudList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HudList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F22E0
// Name: public: int CHud::AddHudRenderGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHud::AddHudRenderGroup(CHud *this, vgui::TreeNode *pszGroupName)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_RenderGroupNames; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  CHudRenderGroup *v8; // eax
  CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t insert; // [esp+Ch] [ebp-Ch] BYREF
  CHud *v11; // [esp+14h] [ebp-4h]

  m_nAllocationCount = this->m_RenderGroupNames.m_Memory.m_nAllocationCount;
  p_m_RenderGroupNames = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_RenderGroupNames;
  m_Size = this->m_RenderGroupNames.m_Size;
  v11 = this;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_RenderGroupNames, num: m_Size - m_nAllocationCount + 1);
  ++p_m_RenderGroupNames[1].m_pMemory;
  m_pMemory = p_m_RenderGroupNames->m_pMemory;
  v6 = (int)p_m_RenderGroupNames[1].m_pMemory - m_Size - 1;
  p_m_RenderGroupNames[1].m_nAllocationCount = (int)p_m_RenderGroupNames->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_RenderGroupNames->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pszGroupName;
  v8 = (CHudRenderGroup *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v8 != nullptr )
  {
    v8->m_pLockingElements.m_heap.m_Memory.m_pMemory = nullptr;
    v8->m_pLockingElements.m_heap.m_Memory.m_nAllocationCount = 0;
    v8->m_pLockingElements.m_heap.m_Memory.m_nGrowSize = 0;
    v8->m_pLockingElements.m_heap.m_Size = 0;
    v8->m_pLockingElements.m_heap.m_pElements = nullptr;
    v8->m_pLockingElements.m_LessFunc = RenderGroupLessFunc;
    v8->bHidden = false;
  }
  else
  {
    v8 = nullptr;
  }
  insert.elem = v8;
  insert.key = m_Size;
  return CUtlRBTree<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CHudRenderGroup *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CHudRenderGroup *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &v11->m_RenderGroups.m_Tree,
           a2: (const char *)m_Size,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x100F23F0
// Name: void LoadHudTextures(class CUtlDict<class CHudTexture __near *,int> __near &,char __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadHudTextures(
        CUtlDict<CHudTexture *,int> *list,
        char *szFilenameWithoutExtension,
        const unsigned __int8 *pICEKey)
{
  KeyValues *EncryptedKVFile; // eax
  KeyValues *v4; // esi
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // edi
  CHudTexture *v7; // eax
  CHudTexture *v8; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v11; // eax
  char *v12; // eax
  CHudTexture *v13; // ecx
  char *v14; // eax
  char v15; // dl
  const char *v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *v20; // ecx
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *v23; // eax
  CUtlMap<char const *,CHudTexture *,int>::Node_t *p_m_Data; // esi
  CUtlMap<char const *,CHudTexture *,int>::Node_t insert; // [esp+4h] [ebp-14h] BYREF
  KeyValues *pKeyValuesData; // [esp+Ch] [ebp-Ch]
  int parent; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  EncryptedKVFile = ReadEncryptedKVFile(
                      filesystem: filesystem,
                      szFilenameWithoutExtension,
                      pICEKey,
                      bForceReadEncryptedFile: false);
  v4 = EncryptedKVFile;
  pKeyValuesData = EncryptedKVFile;
  if ( EncryptedKVFile != nullptr )
  {
    Key = KeyValues::FindKey(this: EncryptedKVFile, keyName: "TextureData", bCreate: false);
    if ( Key != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          v7 = (CHudTexture *)MemAlloc_Alloc(nSize: 0xACu);
          v8 = v7;
          if ( v7 != nullptr )
          {
            _V_memset(dest: (void *)v7, fill: 0, count: 64);
            _V_memset(dest: v8->szTextureFile, fill: 0, count: 64);
            _V_memset(dest: v8->texCoords, fill: 0, count: 16);
            _V_memset(dest: &v8->rc, fill: 0, count: 16);
            v8->textureId = -1;
            *(_WORD *)&v8->bRenderUsingFont = 0;
            v8->cCharacterInFont = 0;
            v8->hFont = 0;
          }
          else
          {
            v8 = nullptr;
          }
          Name = KeyValues::GetName(this: FirstSubKey);
          V_strncpy(pDest: v8->szShortName, pSrc: Name, maxLen: 64);
          if ( KeyValues::GetString(this: FirstSubKey, keyName: "font", defaultValue: nullptr) != nullptr )
          {
            v8->bRenderUsingFont = true;
            v8->cCharacterInFont = *KeyValues::GetString(this: FirstSubKey, keyName: "character", defaultValue: prType);
            String = KeyValues::GetString(this: FirstSubKey, keyName: "font", defaultValue: prType);
            V_strncpy(pDest: v8->szTextureFile, pSrc: String, maxLen: 64);
          }
          else
          {
            v8->bRenderUsingFont = false;
            v11 = KeyValues::GetString(this: FirstSubKey, keyName: "file", defaultValue: prType);
            V_strncpy(pDest: v8->szTextureFile, pSrc: v11, maxLen: 64);
            v8->rc.left = KeyValues::GetInt(this: FirstSubKey, keyName: "x", defaultValue: 0);
            v8->rc.top = KeyValues::GetInt(this: FirstSubKey, keyName: "y", defaultValue: 0);
            v8->rc.right = v8->rc.left + KeyValues::GetInt(this: FirstSubKey, keyName: "width", defaultValue: 0);
            v8->rc.bottom = v8->rc.top + KeyValues::GetInt(this: FirstSubKey, keyName: "height", defaultValue: 0);
          }
          v12 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v8->szShortName) + 1);
          parent = (int)v12;
          if ( v12 != nullptr )
          {
            v13 = v8;
            v14 = (char *)(v12 - (char *)v8);
            do
            {
              v15 = v13->szShortName[0];
              v13->szShortName[(_DWORD)v14] = v13->szShortName[0];
              v13 = (CHudTexture *)((char *)v13 + 1);
            }
            while ( v15 != 0 );
            v16 = (const char *)parent;
          }
          else
          {
            v16 = nullptr;
          }
          insert.key = v16;
          insert.elem = v8;
          parent = -1;
          leftchild = false;
          CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FindInsertionPosition(
            this: &list->m_Elements.m_Tree,
            &insert,
            &parent,
            &leftchild);
          v17 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
                  this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)list,
                  a2: (const char *)FirstSubKey);
          v18 = parent;
          v19 = v17;
          v20 = &list->m_Elements.m_Tree.m_Elements.m_pMemory[v17];
          v20->m_Parent = parent;
          v20->m_Right = -1;
          v20->m_Left = -1;
          v20->m_Tag = 0;
          if ( v18 == -1 )
          {
            list->m_Elements.m_Tree.m_Root = v17;
          }
          else
          {
            v21 = v18;
            m_pMemory = list->m_Elements.m_Tree.m_Elements.m_pMemory;
            if ( leftchild )
              m_pMemory[v21].m_Left = v17;
            else
              m_pMemory[v21].m_Right = v17;
          }
          CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::InsertRebalance(
            this: &list->m_Elements.m_Tree,
            elem: v17);
          v23 = list->m_Elements.m_Tree.m_Elements.m_pMemory;
          ++list->m_Elements.m_Tree.m_NumElements;
          p_m_Data = &v23[v19].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v4 = pKeyValuesData;
      }
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F26B0
// Name: public: int CHud::RegisterForRenderGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHud::RegisterForRenderGroup(CHud *this, char *pszGroupName)
{
  int m_Size; // edx
  int result; // eax
  const char **i; // esi

  m_Size = this->m_RenderGroupNames.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return CHud::AddHudRenderGroup(this, (vgui::TreeNode *)pszGroupName);
  for ( i = this->m_RenderGroupNames.m_Memory.m_pMemory; *i != pszGroupName; ++i )
  {
    if ( ++result >= m_Size )
      return CHud::AddHudRenderGroup(this, (vgui::TreeNode *)pszGroupName);
  }
  if ( result == -1 )
    return CHud::AddHudRenderGroup(this, (vgui::TreeNode *)pszGroupName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F26F0
// Name: public: class CHudTexture __near * CHudIcons::AddUnsearchableHudIconToList(class CHudTexture __near &)
// Source: json
//------------------------------------------------------------------------------
CHudTexture *__thiscall CHudIcons::AddUnsearchableHudIconToList(CHudIcons *this, CHudTexture *texture)
{
  const CHudTexture *v2; // ebx
  int v4; // eax
  CHudTexture *result; // eax
  CHudTexture *v6; // eax
  CHudTexture *v7; // esi
  char composedName[512]; // [esp+8h] [ebp-208h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+208h] [ebp-8h] BYREF

  v2 = texture;
  if ( texture->bRenderUsingFont )
    V_snprintf(
      pDest: composedName,
      maxLen: 0x200u,
      pFormat: "%s_c%i",
      texture->szTextureFile,
      texture->cCharacterInFont);
  else
    V_snprintf(
      pDest: composedName,
      maxLen: 0x200u,
      pFormat: "%s_%i_%i_%i_%i",
      texture->szTextureFile,
      texture->rc.left,
      texture->rc.top,
      texture->rc.right,
      texture->rc.bottom);
  search.key = composedName;
  v4 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
         this: &this->m_Icons.m_Elements.m_Tree,
         &search);
  if ( v4 == -1 || (result = this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem) == nullptr )
  {
    v6 = (CHudTexture *)CUtlMemoryPool::Alloc(this: &g_HudTextureMemoryPool);
    v7 = v6;
    if ( v6 != nullptr )
      CHudTexture::CHudTexture(this: v6);
    texture = v7;
    CHudTexture::operator=(this: v7, src: v2);
    CHudIcons::SetupNewHudTexture(this, t: v7);
    return this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlDict<CHudTexture *,int>::Insert(
                                                                  this: &this->m_Icons,
                                                                  pName: composedName,
                                                                  element: &texture)].m_Data.elem;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F27F0
// Name: public: class CHudTexture __near * CHudIcons::AddSearchableHudIconToList(class CHudTexture __near &)
// Source: json
//------------------------------------------------------------------------------
CHudTexture *__thiscall CHudIcons::AddSearchableHudIconToList(CHudIcons *this, CHudTexture *texture)
{
  const CHudTexture *v2; // ebx
  int v4; // eax
  CHudTexture *result; // eax
  CHudTexture *v6; // eax
  CHudTexture *v7; // edi
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  v2 = texture;
  if ( texture == nullptr
    || (search.key = (const char *)texture,
        (v4 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                this: &this->m_Icons.m_Elements.m_Tree,
                &search)) == -1)
    || (result = this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem) == nullptr )
  {
    v6 = (CHudTexture *)CUtlMemoryPool::Alloc(this: &g_HudTextureMemoryPool);
    v7 = v6;
    if ( v6 != nullptr )
      CHudTexture::CHudTexture(this: v6);
    texture = v7;
    CHudTexture::operator=(this: v7, src: v2);
    CHudIcons::SetupNewHudTexture(this, t: v7);
    return this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlDict<CHudTexture *,int>::Insert(
                                                                  this: &this->m_Icons,
                                                                  pName: v2->szShortName,
                                                                  element: &texture)].m_Data.elem;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F2870
// Name: public: void CHudIcons::RefreshHudTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudIcons::RefreshHudTextures(CHudIcons *this)
{
  CHudIcons *v1; // ebx
  bool v2; // zf
  const char *v3; // edi
  int v4; // eax
  CHudTexture *elem; // esi
  int textureId; // eax
  float v7; // xmm1_4
  float top; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  CUtlDict<CHudTexture *,int> *p_m_Icons; // esi
  int j; // eax
  int v14; // edi
  CHudTexture *v15; // esi
  vgui::IScheme *v16; // eax
  unsigned int v17; // eax
  int cCharacterInFont; // ebx
  int v19; // eax
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *m_pMemory; // edi
  CUtlDict<CHudTexture *,int> textureList; // [esp+4h] [ebp-40h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+28h] [ebp-1Ch] BYREF
  int tall; // [esp+30h] [ebp-14h] BYREF
  int wide; // [esp+34h] [ebp-10h] BYREF
  int i; // [esp+38h] [ebp-Ch]
  CHudIcons *v27; // [esp+3Ch] [ebp-8h]
  const char **p_elem; // [esp+40h] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHudTexturesLoaded;
  v27 = this;
  if ( !v2 )
  {
    textureList.m_Elements.m_Tree.m_Root = -1;
    textureList.m_Elements.m_Tree.m_FirstFree = -1;
    textureList.m_Elements.m_Tree.m_LastAlloc.index = -1;
    memset(&textureList.m_Elements.m_Tree.m_Elements, 0, sizeof(textureList.m_Elements.m_Tree.m_Elements));
    textureList.m_Elements.m_Tree.m_NumElements = 0;
    textureList.m_Elements.m_Tree.m_pElements = nullptr;
    textureList.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/hud_textures", pICEKey: nullptr);
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/mod_textures", pICEKey: nullptr);
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/instructor_textures", pICEKey: nullptr);
    if ( textureList.m_Elements.m_Tree.m_NumElements > 0 )
    {
      p_elem = (const char **)&textureList.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem;
      for ( i = textureList.m_Elements.m_Tree.m_NumElements; i != 0; --i )
      {
        v3 = *p_elem;
        if ( *p_elem != nullptr )
        {
          search.key = *p_elem;
          v4 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                 this: &v1->m_Icons.m_Elements.m_Tree,
                 &search);
          if ( v4 != -1 )
          {
            elem = v1->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
            if ( elem != nullptr )
            {
              V_strncpy(pDest: elem->szTextureFile, pSrc: (char *)v3 + 64, maxLen: 64);
              if ( !elem->bRenderUsingFont )
              {
                textureId = elem->textureId;
                *(_QWORD *)&elem->rc.left = *(_QWORD *)(v3 + 156);
                *(_QWORD *)&elem->rc.top = *(_QWORD *)(v3 + 164);
                g_pVGuiSurface->DrawSetTextureFile(
                  this: g_pVGuiSurface,
                  a2: textureId,
                  a3: elem->szTextureFile,
                  a4: 0,
                  a5: false);
                g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: elem->textureId, a3: &wide, a4: &tall);
                v7 = (float)wide;
                top = (float)elem->rc.top;
                elem->texCoords[0] = (float)((float)elem->rc.left + 0.5) / (float)wide;
                v9 = (float)tall;
                elem->texCoords[1] = (float)(top + 0.5) / (float)tall;
                v10 = (float)((float)elem->rc.right - 0.5) / v7;
                v11 = (float)((float)elem->rc.bottom - 0.5) / v9;
                elem->texCoords[2] = v10;
                elem->texCoords[3] = v11;
              }
              v1 = v27;
            }
          }
        }
        p_elem += 6;
      }
    }
    FreeHudTextureList(list: &textureList);
    p_m_Icons = &v1->m_Icons;
    tall = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "basemodui_scheme");
    for ( j = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_Icons.m_Elements.m_Tree);
          ;
          j = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
                this: &v1->m_Icons.m_Elements.m_Tree,
                i: v14) )
    {
      v14 = j;
      if ( j < 0
        || j >= p_m_Icons->m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || j > p_m_Icons->m_Elements.m_Tree.m_LastAlloc.index )
      {
        break;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10643F6C = -1;
        dword_10643F70 = -1;
        dword_10643F74 = 1;
      }
      if ( p_m_Icons->m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Left == j )
        break;
      v15 = v1->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.elem;
      if ( v15 != nullptr && v15->bRenderUsingFont )
      {
        v16 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: tall);
        v17 = v16->GetFont(this: v16, a2: v15->szTextureFile, a3: true);
        cCharacterInFont = v15->cCharacterInFont;
        v15->hFont = v17;
        v15->rc.top = 0;
        v15->rc.left = 0;
        v15->rc.right = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v17, a3: cCharacterInFont);
        v19 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v15->hFont);
        v1 = v27;
        v15->rc.bottom = v19;
      }
      p_m_Icons = &v1->m_Icons;
    }
    Inorder = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &textureList.m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      m_pMemory = textureList.m_Elements.m_Tree.m_Elements.m_pMemory;
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[Inorder].m_Data.key);
        Inorder = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
                    this: &textureList.m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
    }
    CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &textureList.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &textureList.m_Elements.m_Tree);
    if ( textureList.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && textureList.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: textureList.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2C00
// Name: public: void CHudElement::RegisterForRenderGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudElement::RegisterForRenderGroup(CHudElement *this, const char *pszGroupName)
{
  int v3; // eax
  int m_Size; // ecx
  CUtlMemory<vgui::TreeNode *,int> *p_m_HudRenderGroups; // esi
  int v6; // ebx
  int v7; // eax
  vgui::TreeNode **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v10; // edi
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  vgui::TreeNode **v13; // eax

  v3 = 0;
  if ( gHUD[0].m_RenderGroupNames.m_Size <= 0 )
    goto LABEL_6;
  while ( gHUD[0].m_RenderGroupNames.m_Memory.m_pMemory[v3] != pszGroupName )
  {
    if ( ++v3 >= gHUD[0].m_RenderGroupNames.m_Size )
      goto LABEL_6;
  }
  if ( v3 == -1 )
LABEL_6:
    v3 = CHud::AddHudRenderGroup(this: gHUD, pszGroupName);
  m_Size = this->m_HudRenderGroups.m_Size;
  p_m_HudRenderGroups = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_HudRenderGroups;
  v6 = v3;
  v7 = 0;
  if ( m_Size <= 0 )
    goto LABEL_13;
  m_pMemory = p_m_HudRenderGroups->m_pMemory;
  while ( *m_pMemory != (vgui::TreeNode *)v6 )
  {
    ++v7;
    ++m_pMemory;
    if ( v7 >= m_Size )
      goto LABEL_13;
  }
  if ( v7 == -1 )
  {
LABEL_13:
    m_nAllocationCount = this->m_HudRenderGroups.m_Memory.m_nAllocationCount;
    v10 = this->m_HudRenderGroups.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_HudRenderGroups, num: v10 - m_nAllocationCount + 1);
    ++p_m_HudRenderGroups[1].m_pMemory;
    v11 = p_m_HudRenderGroups->m_pMemory;
    v12 = (int)p_m_HudRenderGroups[1].m_pMemory - v10 - 1;
    p_m_HudRenderGroups[1].m_nAllocationCount = (int)p_m_HudRenderGroups->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v10 + 1], src: &v11[v10], count: 4 * v12);
    v13 = &p_m_HudRenderGroups->m_pMemory[v10];
    if ( v13 != nullptr )
      *v13 = (vgui::TreeNode *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2CC0
// Name: public: void CHudIcons::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudIcons::Init(CHudIcons *this)
{
  CHudTexture **p_elem; // esi
  int i; // ebx
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *m_pMemory; // edi
  CUtlDict<CHudTexture *,int> textureList; // [esp+4h] [ebp-24h] BYREF

  if ( !this->m_bHudTexturesLoaded )
  {
    this->m_bHudTexturesLoaded = true;
    memset(&textureList.m_Elements.m_Tree.m_Elements, 0, sizeof(textureList.m_Elements.m_Tree.m_Elements));
    textureList.m_Elements.m_Tree.m_Root = -1;
    textureList.m_Elements.m_Tree.m_NumElements = 0;
    textureList.m_Elements.m_Tree.m_FirstFree = -1;
    textureList.m_Elements.m_Tree.m_LastAlloc.index = -1;
    textureList.m_Elements.m_Tree.m_pElements = nullptr;
    textureList.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/hud_textures", pICEKey: nullptr);
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/mod_textures", pICEKey: nullptr);
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/instructor_textures", pICEKey: nullptr);
    LoadHudTextures(list: &textureList, szFilenameWithoutExtension: "scripts/instructor_modtextures", pICEKey: nullptr);
    if ( textureList.m_Elements.m_Tree.m_NumElements > 0 )
    {
      p_elem = &textureList.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem;
      for ( i = textureList.m_Elements.m_Tree.m_NumElements; i != 0; --i )
      {
        CHudIcons::AddSearchableHudIconToList(this, texture: *p_elem);
        p_elem += 6;
      }
    }
    FreeHudTextureList(list: &textureList);
    Inorder = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &textureList.m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      m_pMemory = textureList.m_Elements.m_Tree.m_Elements.m_pMemory;
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[Inorder].m_Data.key);
        Inorder = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
                    this: &textureList.m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
    }
    CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &textureList.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &textureList.m_Elements.m_Tree);
    if ( textureList.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && textureList.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: textureList.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2DF0
// Name: public: void CHud::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::Init(CHud *this)
{
  unsigned int v2; // eax
  vgui::IScheme *v3; // eax
  int j; // esi
  CHudElement *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  IBaseFileSystem *v8; // eax
  int v9; // eax
  vgui::Panel *v10; // esi
  CHudElement *v11; // edi
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // [esp-8h] [ebp-1Ch]
  const char *v18; // [esp-8h] [ebp-1Ch]
  int numelements; // [esp+8h] [ebp-Ch]
  KeyValues *kv; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  this->m_nSplitScreenSlot = 0;
  CUserMessages::HookMessage(this: usermessages, name: "ResetHUD", hook: MsgFunc_ResetHUD);
  CUserMessages::HookMessage(this: usermessages, name: "SendAudio", hook: MsgFunc_SendAudio);
  v2 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "basemodui_scheme");
  v3 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v2);
  g_hFontTrebuchet24 = v3->GetFont(this: v3, a2: "CenterPrintText", a3: true);
  CHudElementHelper::CreateAllElements();
  CLCD::Init(this: &gLCD);
  for ( j = 0; j < this->m_HudList.m_Size; ++j )
  {
    v5 = this->m_HudList.m_Memory.m_pMemory[j];
    v5->Init(this: v5);
  }
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "layout");
    kv = v7;
    if ( v7 != nullptr )
    {
      if ( filesystem != nullptr )
        v8 = &filesystem->IBaseFileSystem;
      else
        v8 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v7,
             filesystem: v8,
             resourceName: "scripts/HudLayout.res",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        v9 = 0;
        numelements = this->m_HudList.m_Size;
        i = 0;
        if ( numelements > 0 )
        {
          do
          {
            v10 = this->m_HudPanelList.m_Memory.m_pMemory[v9];
            v11 = this->m_HudList.m_Memory.m_pMemory[v9];
            if ( v10 != nullptr )
            {
              v12 = v10->GetName(this: v10);
              if ( KeyValues::FindKey(this: kv, keyName: v12, bCreate: false) == nullptr )
              {
                v13 = (int)v10->GetName(this: v10);
                v14 = (const char *)((int (__thiscall *)(CHudElement *, int))v11->GetName)(a1: v11, a2: v13);
                _Msg(a1: "Hud element '%s' doesn't have an entry '%s' in scripts/HudLayout.res\n", v14, v17);
              }
              if ( !v11->m_bIsParentedToClientDLLRootPanel && v10->GetParent(this: v10) == nullptr )
              {
                v15 = (int)v10->GetName(this: v10);
                v16 = (const char *)((int (__thiscall *)(CHudElement *, int))v11->GetName)(a1: v11, a2: v15);
                DevMsg(a1: "Hud element '%s'/'%s' doesn't have a parent\n", v16, v18);
              }
              v9 = i;
            }
            i = ++v9;
          }
          while ( v9 < numelements );
          v7 = kv;
        }
      }
      KeyValues::deleteThis(this: v7);
    }
  }
  CHudIcons::Init(this: &g_HudIcons);
}

//------------------------------------------------------------------------------
// Address: 0x1014B890
// Name: public: virtual void CHudElement::SetHud(class CHud __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudElement::SetHud(CHudElement *this, CHud *pHud)
{
  this->m_pHud = pHud;
}
