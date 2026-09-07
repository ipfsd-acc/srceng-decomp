// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudvoicestatus.cpp
// Functions: 24
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudvoicestatus.h"

//------------------------------------------------------------------------------
// Address: 0x10215BC0
// Name: public: void SFHudVoiceStatus::SetConfig(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::SetConfig(SFHudDeathNoticeAndBotStatus *this, IScaleformUI *pui, void *obj)
{
  long double v5; // st7
  IScaleformUI *m_pScaleformUI; // ecx
  long double v7; // st7
  IScaleformUI *v8; // ecx
  float v9; // xmm0_4
  float fFadeInTime; // [esp+8h] [ebp-4h]
  float fAnimationTime; // [esp+18h] [ebp+Ch]

  v5 = this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 0);
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_nNotificationDisplayMax = (int)v5;
  fAnimationTime = m_pScaleformUI->Params_GetArgAsNumber(this: m_pScaleformUI, a2: obj, a3: 1);
  fFadeInTime = this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 2);
  v7 = this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 4);
  v8 = this->m_pScaleformUI;
  this->m_nPanelSize = (int)v7;
  this->m_fNotificationLifetime = v8->Params_GetArgAsNumber(this: v8, a2: obj, a3: 5);
  v9 = fAnimationTime / (float)this->m_nPanelSize;
  this->m_fNotificationScrollRate = v9;
  this->m_fNotificationFadeRate = fFadeInTime * 0.0099999998;
  this->m_fHideAndShowFadeRate = fFadeInTime * 0.0099999998;
  this->m_fAnimationTracker = v9;
  this->m_fScrollFadeTracker = v9;
}

//------------------------------------------------------------------------------
// Address: 0x102162F0
// Name: public: void CUtlMemory<struct SFHudDeathNoticeAndBotStatus::NoticeText_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SFHudDeathNoticeAndBotStatus::NoticeText_t,int>::Grow(
        CUtlMemory<SFHudDeathNoticeAndBotStatus::NoticeText_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 544 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SFHudDeathNoticeAndBotStatus::NoticeText_t *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: v7);
    else
      this->m_pMemory = (SFHudDeathNoticeAndBotStatus::NoticeText_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223100
// Name: protected: void SFHudVoiceStatus::ColorizeNotice(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::ColorizeNotice(
        SFHudVoiceStatus *this,
        const char *szNotice,
        char *colorStr,
        int clientId)
{
  int v4; // ebx
  const char *v5; // edi
  char v6; // cl
  int v7; // esi
  char *v8; // eax
  char v9; // cl
  const char *v10; // eax
  unsigned int v11; // esi
  char subStr[1024]; // [esp+0h] [ebp-800h] BYREF
  char colorToken[1024]; // [esp+400h] [ebp-400h] BYREF
  int lastColorCode; // [esp+810h] [ebp+10h]

  if ( clientId > 0 )
    g_PR->GetTeam(this: &g_PR->IGameResources, a2: clientId);
  v4 = 0;
  v5 = szNotice;
  if ( szNotice != nullptr && (v6 = *szNotice, *szNotice > 0) && v6 < 8 )
  {
    v7 = v6;
    lastColorCode = v6;
    v5 = szNotice + 1;
  }
  else
  {
    lastColorCode = -1;
    v7 = -1;
  }
  if ( v5 != nullptr )
  {
    while ( *v5 != 0 )
    {
      v8 = subStr;
      do
      {
        v9 = *v5;
        if ( *v5 == 0 || v9 < 8 )
          break;
        switch ( v9 )
        {
          case '"':
            *(_WORD *)v8 = 28966;
            *((_WORD *)v8 + 1) = 28533;
            *((_WORD *)v8 + 2) = 15220;
            v8 += 6;
            break;
          case '&':
            *(_WORD *)v8 = 24870;
            *((_WORD *)v8 + 1) = 28781;
            v8[4] = 59;
            v8 += 5;
            break;
          case '\'':
            *(_WORD *)v8 = 24870;
            *((_WORD *)v8 + 1) = 28528;
            *((_WORD *)v8 + 2) = 15219;
            v8 += 6;
            break;
          case '<':
            *(_WORD *)v8 = 27686;
            *((_WORD *)v8 + 1) = 15220;
            v8 += 4;
            break;
          case '>':
            *(_WORD *)v8 = 26406;
            *((_WORD *)v8 + 1) = 15220;
            v8 += 4;
            break;
          default:
            *v8++ = v9;
            break;
        }
        ++v5;
      }
      while ( v5 != nullptr );
      *v8 = 0;
      if ( v7 >= 0 )
      {
        switch ( v7 )
        {
          case 1:
          case 3:
          case 6:
          case 7:
            goto $LN38_2;
          case 4:
            v10 = "#40ff40";
            break;
          case 5:
            v10 = "#9dc250";
            break;
          default:
            v10 = "#ff0000";
            break;
        }
      }
      else
      {
$LN38_2:
        v10 = "#95abc0";
      }
      V_snprintf(pDest: colorToken, maxLen: 0x400u, pFormat: "<font color=\"%s\">%s</font>", v10, subStr);
      v11 = _V_strlen(str: colorToken);
      V_strncpy(pDest: &colorStr[v4], pSrc: colorToken, maxLen: v11 + 1);
      v4 += v11;
      if ( *v5 != 0 )
        lastColorCode = *v5++;
      if ( v5 == nullptr )
        break;
      v7 = lastColorCode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223300
// Name: public: void CUtlMemory<struct SFHudVoiceStatus::NoticeText_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SFHudVoiceStatus::NoticeText_t,int>::Grow(
        CUtlMemory<SFHudVoiceStatus::NoticeText_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2080 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SFHudVoiceStatus::NoticeText_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (SFHudVoiceStatus::NoticeText_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102233A0
// Name: void __MsgFunc_SFHudVoiceStatus_RadioText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudVoiceStatus_RadioText(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHud *v3; // eax
  CHudChat *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard v5; // [esp+0h] [ebp-4h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
  if ( Element != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &v5,
      slot: *(_DWORD *)&Element[1].m_bRegisteredForEvents - 2);
    v3 = GetHud(nSlot: 0);
    v4 = (CHudChat *)CHud::FindElement(this: v3, pName: "CHudChat");
    if ( v4 != nullptr )
      CHudChat::MsgFunc_RadioText(this: v4, msg);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223400
// Name: void __MsgFunc_SFHudVoiceStatus_SayText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudVoiceStatus_SayText(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHud *v3; // eax
  CHudElement *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard v5; // [esp+0h] [ebp-4h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
  if ( Element != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &v5,
      slot: *(_DWORD *)&Element[1].m_bRegisteredForEvents - 2);
    v3 = GetHud(nSlot: 0);
    v4 = CHud::FindElement(this: v3, pName: "CHudChat");
    if ( v4 != nullptr )
      ((void (__thiscall *)(CHudElement *, bf_read *))v4->__vftable[1].Reset)(a1: v4, a2: msg);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223460
// Name: void __MsgFunc_SFHudVoiceStatus_SayText2(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudVoiceStatus_SayText2(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHud *v3; // eax
  CHudElement *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard v5; // [esp+0h] [ebp-4h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
  if ( Element != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &v5,
      slot: *(_DWORD *)&Element[1].m_bRegisteredForEvents - 2);
    v3 = GetHud(nSlot: 0);
    v4 = CHud::FindElement(this: v3, pName: "CHudChat");
    if ( v4 != nullptr )
      ((void (__thiscall *)(CHudElement *, bf_read *))v4->__vftable[1].ProcessInput)(a1: v4, a2: msg);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102234C0
// Name: void __MsgFunc_SFHudVoiceStatus_TextMsg(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudVoiceStatus_TextMsg(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHud *v3; // eax
  CHudElement *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard v5; // [esp+0h] [ebp-4h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
  if ( Element != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &v5,
      slot: *(_DWORD *)&Element[1].m_bRegisteredForEvents - 2);
    v3 = GetHud(nSlot: 0);
    v4 = CHud::FindElement(this: v3, pName: "CHudChat");
    if ( v4 != nullptr )
      ((void (__thiscall *)(CHudElement *, bf_read *))v4->__vftable[1].GetEventDebugID)(a1: v4, a2: msg);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223520
// Name: void __MsgFunc_SFHudVoiceStatus_RawAudio(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudVoiceStatus_RawAudio(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHud *v3; // eax
  CHudChat *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard v5; // [esp+0h] [ebp-4h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
  if ( Element != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &v5,
      slot: *(_DWORD *)&Element[1].m_bRegisteredForEvents - 2);
    v3 = GetHud(nSlot: 0);
    v4 = (CHudChat *)CHud::FindElement(this: v3, pName: "CHudChat");
    if ( v4 != nullptr )
      CHudChat::MsgFunc_RawAudio(this: v4, msg);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223590
// Name: public: virtual void SFHudVoiceStatus::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::LevelInit(SFHudVoiceStatus *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "VoiceStatus",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudVoiceStatus_VoiceStatus);
}

//------------------------------------------------------------------------------
// Address: 0x102235C0
// Name: protected: void SFHudVoiceStatus::GenerateVoiceText(wchar_t __near *,int,class C_BasePlayer __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::GenerateVoiceText(
        SFHudVoiceStatus *this,
        wchar_t *pString,
        unsigned int strLength,
        C_BasePlayer *pChatter,
        const char *pChatterName,
        bool bIsAlive,
        bool bSameTeam)
{
  char *m_szLastPlaceName; // eax
  wchar_t *v8; // eax
  wchar_t *v9; // esi
  const wchar_t *v10; // esi
  wchar_t pDest[1024]; // [esp+4h] [ebp-1084h] BYREF
  wchar_t pSrc[1024]; // [esp+804h] [ebp-884h] BYREF
  _BYTE v13[128]; // [esp+1004h] [ebp-84h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v14; // [esp+1084h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &v14,
    slot: this->m_iFlashSlot - 2);
  if ( (sf_sv_alltalk == nullptr
     || sf_sv_alltalk->m_pParent != nullptr && sf_sv_alltalk->m_pParent->m_Value.m_nValue != 0)
    && !bSameTeam )
  {
    goto LABEL_17;
  }
  if ( pChatter != nullptr )
    m_szLastPlaceName = pChatter->m_szLastPlaceName;
  else
    m_szLastPlaceName = nullptr;
  if ( bIsAlive )
  {
    if ( m_szLastPlaceName == nullptr || *m_szLastPlaceName == 0 )
      goto LABEL_17;
    v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: m_szLastPlaceName);
  }
  else
  {
    v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUI_Voice_Dead_Location");
  }
  v9 = v8;
  V_snwprintf(pDest, maxLen: 1024, pFormat: L"<font color=\"%s\">%s</font>", L"#40ff40", v8);
  if ( v9 == nullptr
    || *v9 == 0
    || (v10 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Voice_UseLocation")) == nullptr )
  {
LABEL_17:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pChatterName, a3: pSrc, a4: 2048);
    goto LABEL_18;
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pChatterName, a3: (wchar_t *)v13, a4: 128);
  g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: pSrc, a3: 2048, a4: v10, a5: 2, v13, pDest);
LABEL_18:
  V_wcsncpy(pDest: pString, pSrc, maxLenInBytes: strLength);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v14);
}

//------------------------------------------------------------------------------
// Address: 0x10223710
// Name: protected: void SFHudVoiceStatus::RecalculateEndingYPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::RecalculateEndingYPos(SFHudVoiceStatus *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // edx
  int v4; // eax
  int i; // ebx
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // esi
  int v7; // ebx

  v1 = this->m_vecNoticeText.m_Size - 1;
  v2 = v1 - this->m_nNotificationDisplayMax;
  v3 = v1;
  if ( v1 >= 0 )
  {
    v4 = v1;
    for ( i = 1 - v2; v3 >= v2; i = 1 - v2 )
    {
      m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
      if ( m_pMemory[v4].m_pPanel != nullptr )
      {
        if ( v3 >= this->m_nNotificationDisplayMax )
          v7 = v3 + i;
        else
          v7 = v3 + 1;
        m_pMemory[v4].m_nYEnd = -(this->m_nPanelSize * v7);
      }
      --v4;
      if ( --v3 < 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223780
// Name: protected: void SFHudVoiceStatus::UpdateVoiceStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::UpdateVoiceStatus(SFHudVoiceStatus *this)
{
  C_BasePlayer *v2; // ebx
  IGameResources *v3; // eax
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v5; // edi
  int SplitScreenPlayerSlot; // edi
  CVoiceStatus *v7; // eax
  int v8; // edi
  CVoiceStatus *ClientVoiceMgr; // eax
  IGameResources *v10; // ebx
  bool v11; // al
  int v12; // ebx
  bool v13; // bl
  int v14; // ebx
  int v15; // eax
  const char *PlayerName; // eax
  C_BasePlayer_vtbl *v17; // edx
  bool v18; // al
  C_BasePlayer_vtbl *v19; // edx
  int v20; // ebx
  IGameResources *v21; // edi
  const char *v22; // eax
  IGameResources_vtbl *v23; // edx
  bool v24; // al
  IGameResources_vtbl *v25; // edx
  float m_Value; // xmm0_4
  int v27; // eax
  int v28; // eax
  unsigned __int64 Xuid; // rax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *v32; // edi
  double v33; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  char j; // al
  IScaleformUI *v36; // ecx
  char v37; // dl
  int v38; // eax
  wchar_t wcString[1024]; // [esp+Ch] [ebp-930h] BYREF
  char xuidText[256]; // [esp+80Ch] [ebp-130h] BYREF
  int v41; // [esp+90Ch] [ebp-30h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+910h] [ebp-2Ch] BYREF
  float v43; // [esp+914h] [ebp-28h]
  int newChatterSpeakerState; // [esp+918h] [ebp-24h]
  C_CS_PlayerResource *pCSPR; // [esp+91Ch] [ebp-20h]
  C_BasePlayer *bSameTeam; // [esp+920h] [ebp-1Ch]
  int iPrevSpeakerTalking; // [esp+924h] [ebp-18h]
  bool bIsBot; // [esp+92Bh] [ebp-11h]
  int newChatterTeamNum; // [esp+92Ch] [ebp-10h]
  bool bIsLocalPlayer; // [esp+933h] [ebp-9h]
  int iBestHumanTalking; // [esp+934h] [ebp-8h]
  int iBestBotTalking; // [esp+938h] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  v2 = nullptr;
  newChatterTeamNum = 0;
  iBestHumanTalking = -1;
  newChatterSpeakerState = 0;
  bIsLocalPlayer = false;
  v3 = GameResources();
  if ( v3 != nullptr )
    pCSPR = (C_CS_PlayerResource *)&v3[-608];
  else
    pCSPR = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v5 = LocalPlayer;
  bSameTeam = LocalPlayer;
  if ( LocalPlayer == nullptr
    || !GetClientVoiceMgr()->m_bTalking[iBestBotTalking = C_BasePlayer::GetSplitScreenPlayerSlot(this: LocalPlayer)] )
  {
    v8 = 1;
    iPrevSpeakerTalking = -1;
    iBestHumanTalking = -1;
    iBestBotTalking = -1;
    if ( *(int *)(gpGlobals.m_Index + 20) < 1 )
      goto LABEL_38;
    while ( 1 )
    {
      ClientVoiceMgr = GetClientVoiceMgr();
      LODWORD(v43) = 4 * ((v8 - 1) >> 5);
      v41 = 1 << ((v8 - 1) & 0x1F);
      if ( (v41 & *(unsigned int *)((_BYTE *)ClientVoiceMgr->m_VoicePlayers.m_Ints + LODWORD(v43))) != 0 )
      {
        v13 = true;
        v10 = &pCSPR->IGameResources;
        v11 = pCSPR->IsFakePlayer(this: &pCSPR->IGameResources, a2: v8);
        bIsBot = v11;
        if ( sf_sv_alltalk == nullptr
          || sf_sv_alltalk->m_pParent == nullptr
          || sf_sv_alltalk->m_pParent->m_Value.m_nValue == 0
          || v11 )
        {
          v12 = v10->GetTeam(this: v10, a2: v8);
          if ( bSameTeam->GetTeamNumber(this: bSameTeam) != v12 )
            v13 = false;
        }
        if ( (pCSPR->IsAlive(this: &pCSPR->IGameResources, a2: v8) || !bSameTeam->IsAlive(this: bSameTeam)) && v13 )
        {
          if ( v8 == this->m_lastChattingEntIdx )
          {
            v14 = v8;
            iPrevSpeakerTalking = v8;
            if ( bIsBot )
              goto LABEL_33;
            if ( (v41 & *(unsigned int *)((_BYTE *)GetClientVoiceMgr()->m_AudiblePlayers.m_Ints + LODWORD(v43))) != 0 )
              goto LABEL_29;
          }
          else if ( bIsBot )
          {
LABEL_33:
            if ( iBestBotTalking == -1 )
              iBestBotTalking = v8;
            goto LABEL_27;
          }
          if ( iBestHumanTalking == -1 )
            iBestHumanTalking = v8;
        }
      }
LABEL_27:
      if ( ++v8 > *(_DWORD *)(gpGlobals.m_Index + 20) )
      {
        v8 = iBestHumanTalking;
        v14 = iPrevSpeakerTalking;
LABEL_29:
        if ( v14 != -1 )
        {
          if ( v8 == -1 )
          {
            iBestHumanTalking = v14;
            v2 = (C_BasePlayer *)newChatterTeamNum;
          }
          else
          {
            v2 = (C_BasePlayer *)newChatterTeamNum;
            iBestHumanTalking = v8;
          }
          goto LABEL_39;
        }
        v2 = (C_BasePlayer *)newChatterTeamNum;
        if ( v8 != -1 )
        {
          iBestHumanTalking = v8;
          goto LABEL_39;
        }
LABEL_38:
        iBestHumanTalking = iBestBotTalking;
        goto LABEL_39;
      }
    }
  }
  v2 = v5;
  bIsLocalPlayer = true;
  SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this: v5);
  v7 = GetClientVoiceMgr();
  if ( v7->m_bTalking[SplitScreenPlayerSlot]
    && CountdownTimer::Now(this: (CEffectsClient *)&v7->m_bAboveThresholdTimer[SplitScreenPlayerSlot]) <= v7->m_bAboveThresholdTimer[SplitScreenPlayerSlot].m_timestamp.m_Value )
  {
    newChatterSpeakerState = 2;
  }
  else
  {
    newChatterSpeakerState = 1;
  }
LABEL_39:
  iPrevSpeakerTalking = -1;
  LOBYTE(iBestBotTalking) = 1;
  newChatterTeamNum = -1;
  if ( v2 != nullptr )
  {
    v15 = v2->entindex(this: &v2->IClientNetworkable);
  }
  else
  {
    v15 = iBestHumanTalking;
    if ( iBestHumanTalking == -1 )
      goto LABEL_69;
  }
  iPrevSpeakerTalking = v15;
  if ( v15 != -1 )
  {
    if ( bIsLocalPlayer )
    {
      PlayerName = C_BasePlayer::GetPlayerName(this: bSameTeam);
      v17 = v2->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      iBestHumanTalking = (int)PlayerName;
      v18 = v17->IsAlive(this: v2);
      v19 = v2->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      LOBYTE(iBestBotTalking) = v18;
      newChatterTeamNum = v19->GetTeamNumber(this: v2);
    }
    else
    {
      v20 = iPrevSpeakerTalking;
      v21 = &pCSPR->IGameResources;
      v22 = pCSPR->GetPlayerName(this: &pCSPR->IGameResources, a2: iPrevSpeakerTalking);
      v23 = v21->__vftable;
      iBestHumanTalking = (int)v22;
      v24 = v23->IsAlive(this: v21, a2: v20);
      v25 = v21->__vftable;
      LOBYTE(iBestBotTalking) = v24;
      newChatterTeamNum = v25->GetTeam(this: v21, a2: v20);
      v2 = UTIL_PlayerByIndex(entindex: v20);
    }
    m_Value = this->m_closeVoiceNoticeTimer.m_timestamp.m_Value;
    if ( m_Value > 0.0 && m_Value != -1.0 )
    {
      this->m_closeVoiceNoticeTimer.NetworkStateChanged(
        this: &this->m_closeVoiceNoticeTimer,
        a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
      this->m_closeVoiceNoticeTimer.m_timestamp.m_Value = -1.0;
    }
    if ( iPrevSpeakerTalking != this->m_lastChattingEntIdx
      || (_BYTE)iBestBotTalking != this->m_lastChatterWasAlive
      || newChatterTeamNum != this->m_lastChatterTeamNum
      || newChatterSpeakerState != this->m_lastChatterSpeakerState )
    {
      wcString[0] = 0;
      if ( bSameTeam == nullptr
        || (v27 = bSameTeam->GetTeamNumber(this: bSameTeam), LOBYTE(bSameTeam) = 1, newChatterTeamNum != v27) )
      {
        LOBYTE(bSameTeam) = 0;
      }
      SFHudVoiceStatus::GenerateVoiceText(
        this,
        pString: wcString,
        strLength: 0x800u,
        pChatter: v2,
        pChatterName: (const char *)iBestHumanTalking,
        bIsAlive: iBestBotTalking,
        (bool)bSameTeam);
      xuidText[0] = 0;
      if ( g_PR != nullptr && v2 != nullptr )
      {
        v28 = v2->entindex(this: &v2->IClientNetworkable);
        C_PlayerResource::FillXuidText(this: g_PR, iIndex: v28, buf: xuidText, bufSize: 0xFFu);
      }
      else
      {
        Xuid = C_PlayerResource::GetXuid(this: pCSPR, iIndex: iPrevSpeakerTalking);
        V_snprintf(pDest: xuidText, maxLen: 0xFFu, pFormat: "%llu", Xuid);
      }
      for ( i = 1; ; i = 0 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        v32 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 5);
        if ( v32 != nullptr )
        {
          this->m_pScaleformUI->ValueArray_SetElement(this: this->m_pScaleformUI, a2: v32, a3: 0, a4: wcString);
          this->m_pScaleformUI->ValueArray_SetElement_5(
            this: this->m_pScaleformUI,
            a2: v32,
            a3: 1,
            a4: newChatterTeamNum);
          this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v32, a3: 2, a4: iBestBotTalking);
          this->m_pScaleformUI->ValueArray_SetElement_5(
            this: this->m_pScaleformUI,
            a2: v32,
            a3: 3,
            a4: newChatterSpeakerState);
          this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v32, a3: 4, a4: xuidText);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "ShowVoiceNotice",
            a4: v32,
            a5: 5u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v32, a3: 5u);
        }
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    }
    goto LABEL_85;
  }
LABEL_69:
  if ( this->m_lastChattingEntIdx != -1 )
  {
    v33 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_closeVoiceNoticeTimer) + 0.5;
    v43 = v33;
    if ( this->m_closeVoiceNoticeTimer.m_timestamp.m_Value != v33 )
    {
      this->m_closeVoiceNoticeTimer.NetworkStateChanged(
        this: &this->m_closeVoiceNoticeTimer,
        a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
      this->m_closeVoiceNoticeTimer.m_timestamp.m_Value = v43;
    }
    if ( this->m_closeVoiceNoticeTimer.m_duration.m_Value != 0.5 )
    {
      this->m_closeVoiceNoticeTimer.NetworkStateChanged(
        this: &this->m_closeVoiceNoticeTimer,
        a2: &this->m_closeVoiceNoticeTimer.m_duration);
      this->m_closeVoiceNoticeTimer.m_duration.m_Value = 0.5;
    }
  }
  p_m_timestamp = &this->m_closeVoiceNoticeTimer.m_timestamp;
  if ( this->m_closeVoiceNoticeTimer.m_timestamp.m_Value > 0.0
    && CountdownTimer::Now(this: (CEffectsClient *)&this->m_closeVoiceNoticeTimer) > this->m_closeVoiceNoticeTimer.m_timestamp.m_Value )
  {
    for ( j = 1; ; j = 0 )
    {
      v36 = this->m_pScaleformUI;
      if ( j == 0 )
        break;
      if ( v36 != nullptr )
        v36->LockSlot(this: v36, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "HideVoiceNotice",
        a4: nullptr,
        a5: 0);
    }
    if ( v36 != nullptr )
      v36->UnlockSlot(this: v36, a2: this->m_iFlashSlot);
    if ( p_m_timestamp->m_Value != -1.0 )
    {
      this->m_closeVoiceNoticeTimer.NetworkStateChanged(
        this: &this->m_closeVoiceNoticeTimer,
        a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
      p_m_timestamp->m_Value = -1.0;
    }
  }
LABEL_85:
  v37 = iBestBotTalking;
  v38 = newChatterTeamNum;
  this->m_lastChattingEntIdx = iPrevSpeakerTalking;
  this->m_lastChatterSpeakerState = newChatterSpeakerState;
  this->m_lastChatterWasAlive = v37;
  this->m_lastChatterTeamNum = v38;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10223D90
// Name: protected: void SFHudVoiceStatus::UpdateNotices(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudVoiceStatus::UpdateNotices(
        SFHudVoiceStatus *this@<ecx>,
        ScaleformDisplayInfo *p_dinfo@<ebx>,
        void *m_pPanel@<edi>)
{
  float v3; // xmm0_4
  int m_Size; // ecx
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  char v9; // al
  char v10; // dl
  int v11; // ecx
  ISFTextObject *v12; // edx
  int v13; // ebx
  int v14; // eax
  int v15; // edi
  SFHudVoiceStatus::NoticeText_t *v16; // eax
  bool v17; // zf
  void **p_m_pPanel; // eax
  IScaleformUI *v19; // ecx
  int m_fY; // ebx
  float m_fAlpha; // xmm0_4
  IScaleformUI *v22; // ecx
  SFHudVoiceStatus::NoticeText_t *v23; // eax
  SFHudVoiceStatus::NoticeText_t *v24; // ecx
  SFHudVoiceStatus::NoticeText_t *v25; // eax
  float v26; // xmm0_4
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // edx
  void *v28; // ebx
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *v31; // edi
  IScaleformUI *v32; // ecx
  ScaleformDisplayInfo dinfoPrevious; // [esp+0h] [ebp-88h] BYREF
  ScaleformDisplayInfo dinfo; // [esp+38h] [ebp-50h] BYREF
  float fAlpha; // [esp+70h] [ebp-18h]
  int nUpperBound; // [esp+74h] [ebp-14h]
  int nPos; // [esp+78h] [ebp-10h]
  ISFTextObject *text; // [esp+7Ch] [ebp-Ch] BYREF
  int v41; // [esp+80h] [ebp-8h]
  bool bFadeNotices; // [esp+85h] [ebp-3h]
  bool bAnimateNotices; // [esp+86h] [ebp-2h]
  bool bOkToAnimate; // [esp+87h] [ebp-1h]

  v3 = *(float *)(gpGlobals.m_Index + 12);
  m_Size = this->m_vecNoticeText.m_Size;
  v6 = v3 - this->m_fLastUpdateTime;
  this->m_fLastUpdateTime = v3;
  if ( m_Size > 0 )
  {
    v7 = this->m_fAnimationTracker - v6;
    v8 = this->m_fScrollFadeTracker - v6;
    v9 = 0;
    v10 = 0;
    bAnimateNotices = false;
    bFadeNotices = false;
    this->m_fAnimationTracker = v7;
    this->m_fScrollFadeTracker = v8;
    if ( v7 <= 0.0 )
    {
      v9 = 1;
      this->m_fAnimationTracker = this->m_fNotificationScrollRate + v7;
      bAnimateNotices = true;
    }
    if ( v8 <= 0.0 )
    {
      v10 = 1;
      this->m_fScrollFadeTracker = this->m_fNotificationFadeRate + v8;
      bFadeNotices = true;
    }
    if ( v9 != 0 || v10 != 0 )
    {
      v11 = m_Size - 1;
      v12 = (ISFTextObject *)(v11 - this->m_nNotificationDisplayMax);
      v13 = v11;
      nUpperBound = v11;
      text = v12;
      nPos = v11;
      if ( v11 >= 0 )
      {
        v14 = 2080 * v11;
        v41 = 2080 * v11;
        v15 = v11;
        while ( 1 )
        {
          if ( v13 < (int)v12 )
          {
LABEL_32:
            m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
            v28 = *(void **)((char *)&m_pMemory->m_pPanel + v14);
            if ( v28 != nullptr && *((_BYTE *)&m_pMemory->m_szNotice[1024] + v14) != 0 )
            {
              text = *(ISFTextObject **)((char *)&m_pMemory->m_pText + v14);
              if ( this->m_vecNoticeText.m_Size - v11 - 1 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&m_pMemory[v41 / 0x820u],
                  src: (unsigned __int8 *)&m_pMemory[v41 / 0x820u + 1],
                  count: 2080 * (this->m_vecNoticeText.m_Size - v11 - 1));
              --this->m_vecNoticeText.m_Size;
              for ( i = 1; ; i = 0 )
              {
                m_pScaleformUI = this->m_pScaleformUI;
                if ( i == 0 )
                  break;
                if ( m_pScaleformUI != nullptr )
                  m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
                v31 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
                this->m_pScaleformUI->ValueArray_SetElement_6(this: this->m_pScaleformUI, a2: v31, a3: 0, a4: v28);
                this->m_pScaleformUI->Value_InvokeWithoutReturn(
                  this: this->m_pScaleformUI,
                  a2: this->m_FlashAPI,
                  a3: "RemovePanel",
                  a4: v31,
                  a5: 1u);
                this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v31, a3: 1u);
              }
              if ( m_pScaleformUI != nullptr )
                m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
              v32 = this->m_pScaleformUI;
              if ( v32 != nullptr )
                v32->ReleaseValue(this: v32, a2: v28);
              ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &text);
              SFHudVoiceStatus::RecalculateEndingYPos(this);
            }
            return;
          }
          v16 = this->m_vecNoticeText.m_Memory.m_pMemory;
          v17 = v16[v15].m_pPanel == nullptr;
          p_m_pPanel = &v16[v15].m_pPanel;
          if ( !v17 )
            break;
LABEL_31:
          v14 = v41;
          --v13;
          --v15;
          nPos = v13;
          if ( v13 < 0 )
            goto LABEL_32;
        }
        v19 = this->m_pScaleformUI;
        dinfo.m_iSetFlags = 0;
        ((void (__thiscall *)(IScaleformUI *, void *, ScaleformDisplayInfo *, void *, ScaleformDisplayInfo *))v19->Value_GetDisplayInfo)(
          a1: v19,
          a2: *p_m_pPanel,
          a3: &dinfo,
          a4: m_pPanel,
          a5: p_dinfo);
        m_fY = (int)dinfo.m_fY;
        m_fAlpha = dinfo.m_fAlpha;
        fAlpha = m_fAlpha;
        bOkToAnimate = true;
        if ( nPos >= nUpperBound )
        {
          if ( m_fY != 0 )
            goto LABEL_18;
        }
        else
        {
          if ( m_fY != 0 )
            goto LABEL_18;
          v22 = this->m_pScaleformUI;
          v23 = this->m_vecNoticeText.m_Memory.m_pMemory;
          dinfoPrevious.m_iSetFlags = 0;
          v22->Value_GetDisplayInfo(this: v22, a2: v23[v15 + 1].m_pPanel, a3: &dinfoPrevious);
          m_fAlpha = fAlpha;
          if ( dinfoPrevious.m_fY >= (float)((float)this->m_nPanelSize * -1.0) )
          {
            bOkToAnimate = false;
            goto LABEL_18;
          }
        }
        dinfo.m_iSetFlags |= 8u;
        v24 = this->m_vecNoticeText.m_Memory.m_pMemory;
        dinfo.m_fAlpha = 100.0;
        v24[v15].m_fFadeStartTime = *(float *)(gpGlobals.m_Index + 12) + this->m_fNotificationLifetime;
        this->m_vecNoticeText.m_Memory.m_pMemory[v15].m_bFadeOut = true;
LABEL_18:
        if ( bAnimateNotices )
        {
          if ( !bOkToAnimate )
          {
LABEL_30:
            p_dinfo = &dinfo;
            m_pPanel = this->m_vecNoticeText.m_Memory.m_pMemory[v15].m_pPanel;
            ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->Value_SetDisplayInfo)(a1: this->m_pScaleformUI);
            v12 = text;
            v11 = nUpperBound;
            v13 = nPos;
            goto LABEL_31;
          }
          if ( m_fY - 1 >= this->m_vecNoticeText.m_Memory.m_pMemory[v15].m_nYEnd )
          {
            dinfo.m_iSetFlags |= 2u;
            dinfo.m_fY = (double)(m_fY - 1);
          }
        }
        if ( bOkToAnimate && bFadeNotices && m_fY != 0 )
        {
          v25 = &this->m_vecNoticeText.m_Memory.m_pMemory[v15];
          if ( v25->m_bFadeOut && *(float *)(gpGlobals.m_Index + 12) > v25->m_fFadeStartTime && m_fAlpha > 0.0 )
          {
            v26 = m_fAlpha - 2.0;
            dinfo.m_iSetFlags |= 8u;
            dinfo.m_fAlpha = v26;
            if ( v26 < 0.0 )
              v25->m_bRemove = true;
          }
        }
        goto LABEL_30;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224100
// Name: protected: void SFHudVoiceStatus::SaveHideRestoreShow(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::SaveHideRestoreShow(SFHudVoiceStatus *this, bool bSaveAndHide)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  unsigned int v6; // edi
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // eax
  bool v8; // zf
  void **p_m_pPanel; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  SFHudVoiceStatus::NoticeText_t *v11; // eax
  SFHudVoiceStatus::NoticeText_t *v12; // eax
  float m_fFadeStartTimeDelta; // xmm0_4
  float m_fAlpha; // xmm0_4
  SFHudVoiceStatus::NoticeText_t *v15; // eax
  float m_fFadeStartTime; // xmm0_4
  ScaleformDisplayInfo dinfo; // [esp+Ch] [ebp-40h] BYREF
  int nLowerBound; // [esp+44h] [ebp-8h]
  int nPos; // [esp+48h] [ebp-4h]

  v3 = this->m_vecNoticeText.m_Size - 1;
  v4 = v3 - this->m_nNotificationDisplayMax;
  v5 = v3;
  nLowerBound = v4;
  nPos = v3;
  if ( v3 >= 0 )
  {
    v6 = v3;
    do
    {
      if ( v5 < v4 )
        break;
      m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
      v8 = m_pMemory[v6].m_pPanel == nullptr;
      p_m_pPanel = &m_pMemory[v6].m_pPanel;
      if ( !v8 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        dinfo.m_iSetFlags = 0;
        m_pScaleformUI->Value_GetDisplayInfo(this: m_pScaleformUI, a2: *p_m_pPanel, a3: &dinfo);
        v11 = this->m_vecNoticeText.m_Memory.m_pMemory;
        if ( bSaveAndHide )
        {
          m_fAlpha = dinfo.m_fAlpha;
          v11[v6].m_fAlpha = m_fAlpha;
          v15 = this->m_vecNoticeText.m_Memory.m_pMemory;
          m_fFadeStartTime = v15[v6].m_fFadeStartTime;
          if ( m_fFadeStartTime > 0.0 )
            v15[v6].m_fFadeStartTimeDelta = m_fFadeStartTime - *(float *)(gpGlobals.m_Index + 12);
          dinfo.m_bVisibility = false;
        }
        else
        {
          v11[v6].m_fAlpha = 0.0;
          v12 = this->m_vecNoticeText.m_Memory.m_pMemory;
          m_fFadeStartTimeDelta = v12[v6].m_fFadeStartTimeDelta;
          if ( m_fFadeStartTimeDelta > 0.0 )
            v12[v6].m_fFadeStartTime = *(float *)(gpGlobals.m_Index + 12) + m_fFadeStartTimeDelta;
          dinfo.m_bVisibility = true;
        }
        dinfo.m_iSetFlags |= 0x10u;
        this->m_pScaleformUI->Value_SetDisplayInfo(
          this: this->m_pScaleformUI,
          a2: this->m_vecNoticeText.m_Memory.m_pMemory[v6].m_pPanel,
          a3: &dinfo);
        v4 = nLowerBound;
        v5 = nPos;
      }
      --v5;
      --v6;
      nPos = v5;
    }
    while ( v5 >= 0 );
  }
  if ( bSaveAndHide )
  {
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "HideVoiceNotice",
      a4: nullptr,
      a5: 0);
    if ( this->m_closeVoiceNoticeTimer.m_timestamp.m_Value != -1.0 )
    {
      this->m_closeVoiceNoticeTimer.NetworkStateChanged(
        this: &this->m_closeVoiceNoticeTimer,
        a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
      this->m_closeVoiceNoticeTimer.m_timestamp.m_Value = -1.0;
    }
    this->m_lastChattingEntIdx = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224310
// Name: public: virtual bool SFHudVoiceStatus::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudVoiceStatus::PreUnloadFlash(SFHudVoiceStatus *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edi
  IScaleformUI *m_pScaleformUI; // ecx
  void **p_m_pPanel; // ebx
  int nLowerBound; // [esp+8h] [ebp-8h]
  int nPos; // [esp+Ch] [ebp-4h]

  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  v2 = this->m_vecNoticeText.m_Size - 1;
  v3 = v2 - this->m_nNotificationDisplayMax;
  nPos = v2;
  nLowerBound = v3;
  if ( v2 >= 0 )
  {
    v4 = v2;
    while ( nPos >= v3 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      p_m_pPanel = &this->m_vecNoticeText.m_Memory.m_pMemory[v4].m_pPanel;
      if ( m_pScaleformUI != nullptr && *p_m_pPanel != nullptr )
      {
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: *p_m_pPanel);
        *p_m_pPanel = nullptr;
      }
      ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(
        this,
        value: &this->m_vecNoticeText.m_Memory.m_pMemory[v4--].m_pText);
      if ( --nPos < 0 )
        break;
      v3 = nLowerBound;
    }
  }
  this->m_vecNoticeText.m_Size = 0;
  if ( this->m_vecNoticeText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecNoticeText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecNoticeText.m_Memory.m_pMemory);
      this->m_vecNoticeText.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecNoticeText.m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecNoticeText.m_pElements = this->m_vecNoticeText.m_Memory.m_pMemory;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102243E0
// Name: protected: void SFHudVoiceStatus::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::ShowPanel(SFHudVoiceStatus *this, bool bShow)
{
  char i; // al

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      if ( bShow )
        SFHudVoiceStatus::SaveHideRestoreShow(this, bSaveAndHide: false);
      else
        SFHudVoiceStatus::SaveHideRestoreShow(this, bSaveAndHide: true);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224440
// Name: public: virtual void SFHudVoiceStatus::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::SetActive(SFHudVoiceStatus *this, bool bActive)
{
  if ( bActive != this->m_bActive )
    SFHudVoiceStatus::ShowPanel(this, bShow: bActive);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10224470
// Name: public: virtual void SFHudVoiceStatus::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudVoiceStatus::ProcessInput(
        SFHudVoiceStatus *this@<ecx>,
        ScaleformDisplayInfo *a2@<ebx>,
        void *a3@<edi>)
{
  SFHudVoiceStatus::UpdateNotices(this, p_dinfo: a2, m_pPanel: a3);
  SFHudVoiceStatus::UpdateVoiceStatus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10224480
// Name: public: SFHudVoiceStatus::SFHudVoiceStatus(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudVoiceStatus *__thiscall SFHudVoiceStatus::SFHudVoiceStatus(SFHudVoiceStatus *this, const char *value)
{
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  SFHudVoiceStatus::NoticeText_t *v7; // eax

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (SFHudVoiceStatus_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudVoiceStatus_vtbl *)&SFHudVoiceStatus::`vftable';
  this->m_nNotificationDisplayMax = 0;
  this->m_fNotificationScrollRate = 0.0;
  this->m_fNotificationFadeRate = 0.0;
  this->m_fNotificationLifetime = 0.0;
  this->m_fHideAndShowFadeRate = 0.0;
  this->m_nPanelSize = 0;
  this->m_fLastUpdateTime = 0.0;
  this->m_fAnimationTracker = 0.0;
  this->m_fScrollFadeTracker = 0.0;
  this->m_vecNoticeText.m_Memory.m_pMemory = nullptr;
  this->m_vecNoticeText.m_Memory.m_nAllocationCount = 0;
  this->m_vecNoticeText.m_Memory.m_nGrowSize = 0;
  this->m_vecNoticeText.m_Size = 0;
  this->m_vecNoticeText.m_pElements = nullptr;
  this->m_lastChattingEntIdx = -1;
  this->m_lastChatterWasAlive = false;
  this->m_lastChatterTeamNum = -1;
  this->m_lastChatterSpeakerState = -1;
  this->m_closeVoiceNoticeTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v3 = this->m_closeVoiceNoticeTimer.__vftable;
  this->m_closeVoiceNoticeTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v3->NetworkStateChanged)(a1: &this->m_closeVoiceNoticeTimer.m_duration);
  v4 = this->m_closeVoiceNoticeTimer.__vftable;
  this->m_closeVoiceNoticeTimer.m_timestamp.m_Value = -1.0;
  v4->NetworkStateChanged(this: &this->m_closeVoiceNoticeTimer, a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x80);
  if ( this->m_vecNoticeText.m_Memory.m_nAllocationCount < 16 && this->m_vecNoticeText.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_vecNoticeText.m_Memory.m_nAllocationCount = 16;
    m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (SFHudVoiceStatus::NoticeText_t *)((int (__stdcall *)(SFHudVoiceStatus::NoticeText_t *, int))v6->Realloc_2)(
                                               a1: m_pMemory,
                                               a2: 33280);
    else
      v7 = (SFHudVoiceStatus::NoticeText_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 33280);
    this->m_vecNoticeText.m_Memory.m_pMemory = v7;
  }
  this->m_vecNoticeText.m_pElements = this->m_vecNoticeText.m_Memory.m_pMemory;
  if ( this->m_closeVoiceNoticeTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_closeVoiceNoticeTimer.NetworkStateChanged(
      this: &this->m_closeVoiceNoticeTimer,
      a2: &this->m_closeVoiceNoticeTimer.m_timestamp);
    this->m_closeVoiceNoticeTimer.m_timestamp.m_Value = -1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102245E0
// Name: public: virtual void SFHudVoiceStatus::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVoiceStatus::FlashReady(SFHudVoiceStatus *this)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bFlashAPIIsValid )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iFlashSlot - 2);
    CUserMessages::HookMessage(this: usermessages, name: "RadioText", hook: __MsgFunc_SFHudVoiceStatus_RadioText);
    CUserMessages::HookMessage(this: usermessages, name: "SayText", hook: __MsgFunc_SFHudVoiceStatus_SayText);
    CUserMessages::HookMessage(this: usermessages, name: "SayText2", hook: __MsgFunc_SFHudVoiceStatus_SayText2);
    CUserMessages::HookMessage(this: usermessages, name: "TextMsg", hook: __MsgFunc_SFHudVoiceStatus_TextMsg);
    CUserMessages::HookMessage(this: usermessages, name: "RawAudio", hook: __MsgFunc_SFHudVoiceStatus_RawAudio);
    SFHudVoiceStatus::ShowPanel(this, bShow: false);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_reset_vote", a4: false);
  if ( sf_sv_alltalk == nullptr )
    sf_sv_alltalk = cvar->FindVar_2(this: cvar, a2: "sv_alltalk");
}

//------------------------------------------------------------------------------
// Address: 0x102246C0
// Name: public: void SFHudVoiceStatus::PushNotice(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudVoiceStatus::PushNotice(
        SFHudVoiceStatus *this@<ecx>,
        ScaleformDisplayInfo *p_dinfo@<ebx>,
        void *m_pPanel@<edi>,
        const char *szNoticeText,
        int clientId)
{
  char v6; // al
  void *v7; // edi
  void *v8; // ebx
  IScaleformUI *m_pScaleformUI; // ecx
  ISFTextObject *v10; // eax
  IScaleformUI *v11; // ecx
  bool v12; // zf
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // eax
  char szColorNotice[1024]; // [esp+4h] [ebp-C58h] BYREF
  SFHudVoiceStatus::NoticeText_t notice; // [esp+404h] [ebp-858h] BYREF
  ScaleformDisplayInfo dinfo; // [esp+C24h] [ebp-38h] BYREF

  if ( this->m_bFlashAPIIsValid && this->m_bActive )
  {
    SFHudVoiceStatus::ColorizeNotice(this, szNotice: szNoticeText, colorStr: szColorNotice, clientId);
    memset(&notice.m_pPanel, 0, 13);
    memset(&notice.m_nYEnd, 0, 12);
    notice.m_bRemove = false;
    _V_memset(dest: (int)&notice, fill: nullptr, count: 0x800u);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szColorNotice, a3: (wchar_t *)&notice, a4: 2048);
    v6 = 1;
    while ( v6 != 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v7 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement(
        this: this->m_pScaleformUI,
        a2: v7,
        a3: 0,
        a4: (const wchar_t *)&notice);
      v8 = this->m_pScaleformUI->Value_Invoke(
             this: this->m_pScaleformUI,
             a2: this->m_FlashAPI,
             a3: "AddPanel",
             a4: v7,
             a5: 1);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v7, a3: 1u);
      if ( this->m_pScaleformUI->Value_GetType(this: this->m_pScaleformUI, a2: v8) == VT_DisplayObject )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        notice.m_pPanel = v8;
        v10 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, void *, const char *, void *, ScaleformDisplayInfo *))m_pScaleformUI->TextObject_MakeTextObjectFromMember)(
                                 a1: m_pScaleformUI,
                                 a2: v8,
                                 a3: "Text",
                                 a4: m_pPanel,
                                 a5: p_dinfo);
        if ( v10 != nullptr )
        {
          notice.m_pText = v10;
          v10->SetTextHTML(this: v10, a2: notice.m_szNotice);
        }
        CUtlVector<SFHudVoiceStatus::NoticeText_t,CUtlMemory<SFHudVoiceStatus::NoticeText_t,int>>::InsertBefore(
          this: &this->m_vecNoticeText,
          elem: 0,
          src: &notice);
        v11 = this->m_pScaleformUI;
        dinfo.m_iSetFlags = 0;
        v11->Value_GetDisplayInfo(this: v11, a2: notice.m_pPanel, a3: &dinfo);
        v12 = this->m_vecNoticeText.m_Size == 1;
        dinfo.m_fAlpha = 0.0;
        if ( v12 )
        {
          dinfo.m_fY = (double)-this->m_nPanelSize;
          dinfo.m_iSetFlags |= 0xAu;
          m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
          dinfo.m_fAlpha = 100.0;
          m_pMemory->m_fFadeStartTime = *(float *)(gpGlobals.m_Index + 12) + this->m_fNotificationLifetime;
          this->m_vecNoticeText.m_Memory.m_pMemory->m_bFadeOut = true;
        }
        else
        {
          dinfo.m_iSetFlags |= 0xAu;
          dinfo.m_fY = 0.0;
        }
        p_dinfo = &dinfo;
        m_pPanel = notice.m_pPanel;
        ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->Value_SetDisplayInfo)(a1: this->m_pScaleformUI);
        SFHudVoiceStatus::RecalculateEndingYPos(this);
        v6 = 0;
      }
      else
      {
        if ( this->m_pScaleformUI != nullptr && v8 != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v8);
        v6 = 0;
      }
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224900
// Name: public: virtual void SFHudVoiceStatus::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudVoiceStatus::FireGameEvent(SFHudVoiceStatus *this@<ecx>, int a2@<ebx>, IGameEvent *event)
{
  const char *(__thiscall *GetName)(IGameEvent *); // edx
  const char *v5; // eax
  IVEngineClient_vtbl *v6; // edi
  int v7; // eax
  ScaleformDisplayInfo *v8; // edi
  ScaleformDisplayInfo *LocalPlayerIndex; // ebx
  vgui::ILocalize_vtbl *v10; // esi
  int v11; // eax
  vgui::ILocalize_vtbl *v12; // esi
  int v13; // eax
  wchar_t wszMessage[1024]; // [esp+8h] [ebp-C48h] BYREF
  char szMessage[1024]; // [esp+808h] [ebp-448h] BYREF
  wchar_t wszPlayerName[32]; // [esp+C08h] [ebp-48h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+C48h] [ebp-8h] BYREF
  SFHudVoiceStatus *v19; // [esp+C4Ch] [ebp-4h]
  bool vote_3; // [esp+C5Bh] [ebp+Bh]

  GetName = event->GetName;
  v19 = this;
  v5 = GetName(this: event);
  if ( _V_strcmp(s1: v5, s2: "player_reset_vote") == 0 )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iFlashSlot - 2);
    v6 = engine->__vftable;
    v7 = event->GetInt(this: event, a2: "userid", a3: 0);
    v8 = (ScaleformDisplayInfo *)v6->GetPlayerForUserID(this: engine, a2: v7);
    vote_3 = event->GetBool(this: event, a2: "vote", a3: false);
    LocalPlayerIndex = (ScaleformDisplayInfo *)GetLocalPlayerIndex();
    if ( v8 != LocalPlayerIndex && vote_3 && g_PR != nullptr )
    {
      v10 = g_pVGuiLocalize->__vftable;
      v11 = ((int (__thiscall *)(IGameResources *, ScaleformDisplayInfo *, wchar_t *, int, int))g_PR->GetPlayerName)(
              a1: &g_PR->IGameResources,
              a2: v8,
              a3: wszPlayerName,
              a4: 64,
              a5: a2);
      ((void (__thiscall *)(vgui::ILocalize *, int))v10->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v11);
      memset(wszMessage, 0, sizeof(wszMessage));
      memset(szMessage, 0, sizeof(szMessage));
      v12 = g_pVGuiLocalize->__vftable;
      v13 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
              a1: g_pVGuiLocalize,
              a2: "#SFUI_Player_Wants_Restart",
              a3: 1,
              a4: wszPlayerName);
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v12->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: wszMessage,
        a3: 2048,
        a4: v13);
      V_wcstostr(pWString: wszMessage, nInSize: -1, pString: szMessage, nOutSize: 1024);
      SFHudVoiceStatus::PushNotice(
        this: v19,
        p_dinfo: LocalPlayerIndex,
        m_pPanel: v8,
        szNoticeText: szMessage,
        clientId: (int)LocalPlayerIndex);
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224A80
// Name: Create_SFHudVoiceStatus
// Source: json
//------------------------------------------------------------------------------
SFHudVoiceStatus *__cdecl Create_SFHudVoiceStatus()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156);
  memset(dst: v0, value: 0, count: 0x9Cu);
  if ( v0 != nullptr )
    return SFHudVoiceStatus::SFHudVoiceStatus(this: (SFHudVoiceStatus *)v0, value: "SFHudVoiceStatus");
  else
    return nullptr;
}
