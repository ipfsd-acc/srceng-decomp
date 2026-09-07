// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/voice_status.cpp
// Functions: 18
// ============================================================

#include "game\shared\voice_status.h"

//------------------------------------------------------------------------------
// Address: 0x101A8D60
// Name: void ClientVoiceMgr_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientVoiceMgr_Shutdown()
{
  if ( g_VoiceStatus != nullptr )
    ((void (__thiscall *)(CVoiceStatus *, int))g_VoiceStatus->dtr_CVoiceStatus)(a1: g_VoiceStatus, a2: 1);
  g_VoiceStatus = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A8D80
// Name: public: void CVoiceStatus::StopSquelchMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::StopSquelchMode(CVoiceStatus *this)
{
  this->m_bInSquelchMode = false;
  this->m_pHelper->UpdateCursorState(this: this->m_pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x101A8D90
// Name: public: bool CVoiceStatus::IsPlayerBlocked(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVoiceStatus::IsPlayerBlocked(CVoiceStatus *this, int iPlayer)
{
  int result; // eax
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  result = ((int (__thiscall *)(IVEngineClient *, int, player_info_s *))engine->GetPlayerInfo)(
             a1: engine,
             a2: iPlayer,
             a3: &pi);
  if ( (_BYTE)result != 0 )
    return CVoiceBanMgr::GetPlayerBan(this: &this->m_BanMgr, playerID: (CVoiceBanMgr::BannedPlayer *)pi.guid);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8E50
// Name: public: float CVoiceStatus::GetHeadLabelOffset(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVoiceStatus::GetHeadLabelOffset(CVoiceStatus *this)
{
  return voice_head_icon_height.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x101A8E60
// Name: private: void CVoiceStatus::UpdateServerState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::UpdateServerState(CVoiceStatus *this, bool bForce)
{
  int m_nValue; // eax
  int v3; // eax
  int v4; // esi
  unsigned int v5; // eax
  int v6; // edi
  unsigned int v7; // ebx
  char str[2048]; // [esp+0h] [ebp-B14h] BYREF
  char numStr[512]; // [esp+800h] [ebp-314h] BYREF
  char pDest[112]; // [esp+A00h] [ebp-114h] BYREF
  player_info_s pi; // [esp+A70h] [ebp-A4h] BYREF
  int v12; // [esp+B00h] [ebp-14h]
  unsigned int banMask; // [esp+B04h] [ebp-10h]
  unsigned int serverBanMask; // [esp+B08h] [ebp-Ch]
  CVoiceStatus *v15; // [esp+B0Ch] [ebp-8h]
  bool bChange; // [esp+B13h] [ebp-1h]

  v15 = this;
  if ( g_bLevelInitialized )
  {
    if ( voice_modenable.m_pParent != nullptr )
      m_nValue = voice_modenable.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v3 = m_nValue != 0;
    if ( bForce || this->m_bServerModEnable != v3 )
    {
      this->m_bServerModEnable = v3;
      V_snprintf(pDest, maxLen: 0x100u, pFormat: "VModEnable %d", v3);
      engine->ServerCmd(this: engine, a2: pDest, a3: true);
      if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
        _Msg(a1: "CVoiceStatus::UpdateServerState: Sending '%s'\n", pDest);
    }
    V_strncpy(pDest: str, pSrc: "vban", maxLen: 2048);
    v4 = 0;
    bChange = false;
    v12 = 0;
    do
    {
      v5 = 0;
      serverBanMask = 0;
      banMask = 0;
      v6 = 1;
      do
      {
        if ( v4 >= 64 )
          break;
        v7 = v5 + 1;
        if ( engine->GetPlayerInfo(this: engine, a2: v5 + 1, a3: &pi) )
        {
          if ( CVoiceBanMgr::GetPlayerBan(this: &v15->m_BanMgr, playerID: (CVoiceBanMgr::BannedPlayer *)pi.guid) )
            banMask |= v6;
          if ( ((1 << (v4 & 0x1F)) & v15->m_ServerBannedPlayers.m_Ints[v4 >> 5]) != 0 )
            serverBanMask |= v6;
        }
        ++v4;
        v5 = v7;
        v6 = __ROL4__(v6, 1);
      }
      while ( v7 < 0x20 );
      if ( serverBanMask != banMask )
        bChange = true;
      V_snprintf(pDest: numStr, maxLen: 0x200u, pFormat: " %x", banMask);
      V_strncat(pDest: str, pSrc: numStr, destBufferSize: 0x800u, max_chars_to_copy: -1);
      v4 = v12 + 32;
      v12 = v4;
    }
    while ( (unsigned int)v4 < 0x40 );
    if ( bChange || bForce )
    {
      if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
        _Msg(a1: "CVoiceStatus::UpdateServerState: Sending '%s'\n", str);
      engine->ServerCmd(this: engine, a2: str, a3: false);
    }
    else if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
    {
      _Msg(a1: "CVoiceStatus::UpdateServerState: no change\n");
    }
    v15->m_LastUpdateServerState = *(float *)(gpGlobals.m_Index + 12);
  }
  else if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
  {
    _Msg(a1: "CVoiceStatus::UpdateServerState: g_bLevelInitialized\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9080
// Name: public: void CVoiceStatus::HandleVoiceMaskMsg(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::HandleVoiceMaskMsg(CVoiceStatus *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v8; // edx
  unsigned int v9; // edi
  int v10; // eax
  const unsigned int *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  const unsigned int *v20; // edx
  unsigned int v21; // edi
  int v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebx
  unsigned int v26; // edx
  int v27; // ecx
  unsigned int v28; // eax
  int v29; // edx
  int v30; // ecx
  const unsigned int *v31; // eax
  const unsigned int *v32; // ecx
  CVoiceStatus *v33; // eax
  unsigned int v34; // ecx
  const unsigned int *v35; // edx
  unsigned int v36; // edi
  int v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // ebx
  unsigned int dw; // [esp+10h] [ebp-4h]
  bf_read *msga; // [esp+1Ch] [ebp+8h]

  dw = 0;
  msga = (bf_read *)&this->m_ServerBannedPlayers;
  do
  {
    m_nBitsAvail = msg->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = msg->m_nInBufWord;
      v5 = m_nBitsAvail - 32;
      msg->m_nBitsAvail = v5;
      if ( v5 != 0 )
      {
        msg->m_nInBufWord = 0;
      }
      else
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
      goto LABEL_19;
    }
    v8 = msg->m_pBufferEnd;
    v9 = msg->m_nInBufWord;
    v10 = 32 - m_nBitsAvail;
    v11 = msg->m_pDataIn;
    if ( v11 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v11 > v8 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *v11;
    }
    msg->m_pDataIn = v11 + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      m_nInBufWord = 0;
    }
    else
    {
      v12 = msg->m_nInBufWord;
      v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v10;
      v14 = v12 >> v10;
      m_nInBufWord = v13 | v9;
      msg->m_nInBufWord = v14;
    }
LABEL_19:
    msga[-1].m_nBitsAvail = m_nInBufWord;
    v15 = msg->m_nBitsAvail;
    if ( v15 >= 32 )
    {
      v16 = msg->m_nInBufWord;
      v17 = v15 - 32;
      msg->m_nBitsAvail = v17;
      if ( v17 != 0 )
      {
        msg->m_nInBufWord = 0;
      }
      else
      {
        v18 = msg->m_pDataIn;
        v19 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v18 == v19 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v18 + 1;
        }
        else if ( v18 <= v19 )
        {
          msg->m_nInBufWord = *v18;
          msg->m_pDataIn = v18 + 1;
        }
        else
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
        }
      }
      goto LABEL_36;
    }
    v20 = msg->m_pBufferEnd;
    v21 = msg->m_nInBufWord;
    v22 = 32 - v15;
    v23 = msg->m_pDataIn;
    if ( v23 == v20 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_33;
      }
      msg->m_nInBufWord = *v23;
    }
    msg->m_pDataIn = v23 + 1;
LABEL_33:
    if ( msg->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = msg->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v22;
      v26 = v24 >> v22;
      v16 = v25 | v21;
      msg->m_nInBufWord = v26;
    }
LABEL_36:
    msga->m_pDebugName = (const char *)v16;
    if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
    {
      _Msg(a1: "CVoiceStatus::HandleVoiceMaskMsg\n");
      _Msg(a1: "    - m_AudiblePlayers[%d] = %lu\n", dw, msga[-1].m_nBitsAvail);
      _Msg(a1: "    - m_ServerBannedPlayers[%d] = %lu\n", dw, msga->m_pDebugName);
    }
    msga = (bf_read *)((char *)msga + 4);
    ++dw;
  }
  while ( dw < 2 );
  v27 = msg->m_nBitsAvail;
  if ( v27 < 8 )
  {
    v35 = msg->m_pBufferEnd;
    v36 = msg->m_nInBufWord;
    v37 = 8 - v27;
    v38 = msg->m_pDataIn;
    if ( v38 == v35 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v38 > v35 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_55;
      }
      msg->m_nInBufWord = *v38;
    }
    msg->m_pDataIn = v38 + 1;
LABEL_55:
    if ( msg->m_bOverflow )
    {
      this->m_bServerModEnable = 0;
    }
    else
    {
      v39 = msg->m_nInBufWord;
      v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v37;
      msg->m_nInBufWord = v39 >> v37;
      this->m_bServerModEnable = v40 | v36;
    }
    return;
  }
  v28 = msg->m_nInBufWord;
  v29 = (unsigned __int8)v28;
  v30 = v27 - 8;
  msg->m_nBitsAvail = v30;
  if ( v30 != 0 )
  {
    msg->m_nInBufWord = v28 >> 8;
    this->m_bServerModEnable = (unsigned __int8)v28;
  }
  else
  {
    v31 = msg->m_pDataIn;
    v32 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v31 + 1;
      msg->m_nBitsAvail = 1;
      this->m_bServerModEnable = v29;
    }
    else
    {
      if ( v31 <= v32 )
      {
        v34 = *v31;
        msg->m_pDataIn = v31 + 1;
        v33 = this;
        msg->m_nInBufWord = v34;
      }
      else
      {
        v33 = this;
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      v33->m_bServerModEnable = v29;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A93C0
// Name: public: void CVoiceStatus::SetPlayerBlockedState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::SetPlayerBlockedState(CVoiceStatus *this, int iPlayer, bool blocked)
{
  ConVar *m_pParent; // eax
  bool PlayerBan; // al
  bool v6; // al
  player_info_s pi; // [esp+Ch] [ebp-90h] BYREF

  if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
    _Msg(a1: "CVoiceStatus::SetPlayerBlockedState part 1\n");
  if ( engine->GetPlayerInfo(this: engine, a2: iPlayer, a3: &pi) )
  {
    m_pParent = voice_clientdebug.m_pParent;
    if ( voice_clientdebug.m_pParent != nullptr )
    {
      if ( voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
      {
        _Msg(a1: "CVoiceStatus::SetPlayerBlockedState part 2\n");
        m_pParent = voice_clientdebug.m_pParent;
      }
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue == 1 )
      {
        PlayerBan = CVoiceBanMgr::GetPlayerBan(this: &this->m_BanMgr, playerID: (CVoiceBanMgr::BannedPlayer *)pi.guid);
        _Msg(a1: "CVoiceStatus::SetPlayerBlockedState: setting player %d ban to %d\n", iPlayer, !PlayerBan);
      }
    }
    v6 = CVoiceBanMgr::GetPlayerBan(this: &this->m_BanMgr, playerID: (CVoiceBanMgr::BannedPlayer *)pi.guid);
    CVoiceBanMgr::SetPlayerBan(this: &this->m_BanMgr, playerID: (CVoiceBanMgr::BannedPlayer *)pi.guid, bSquelch: !v6);
    CVoiceStatus::UpdateServerState(this, bForce: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9490
// Name: void __MsgFunc_VoiceMask(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_VoiceMask(bf_read *msg)
{
  if ( g_pInternalVoiceStatus != nullptr )
    CVoiceStatus::HandleVoiceMaskMsg(this: g_pInternalVoiceStatus, msg);
}

//------------------------------------------------------------------------------
// Address: 0x101A94B0
// Name: void __MsgFunc_RequestState(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_RequestState()
{
  CVoiceStatus *v0; // esi

  if ( g_pInternalVoiceStatus != nullptr )
  {
    v0 = g_pInternalVoiceStatus;
    if ( voice_clientdebug.m_pParent != nullptr && voice_clientdebug.m_pParent->m_Value.m_nValue == 1 )
      _Msg(a1: "CVoiceStatus::HandleReqStateMsg\n");
    CVoiceStatus::UpdateServerState(this: v0, bForce: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A94F0
// Name: public: virtual int CVoiceStatus::Init(class IVoiceStatusHelper __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVoiceStatus::Init(CVoiceStatus *this, IVoiceStatusHelper *pHelper, unsigned int pParentPanel)
{
  const char *v4; // eax
  IMaterial *(__thiscall *FindMaterial)(IMaterialSystem *, const char *, const char *, bool, const char *); // edx
  IMaterial *v6; // eax

  v4 = engine->GetGameDirectory(this: engine);
  if ( v4 != nullptr )
  {
    CVoiceBanMgr::Init(this: &this->m_BanMgr, pGameDir: v4);
    this->m_bBanMgrInitialized = true;
  }
  FindMaterial = materials->FindMaterial;
  g_pInternalVoiceStatus = this;
  v6 = FindMaterial(this: materials, a2: "voice/icntlk_pl", a3: "VGUI textures", a4: true, a5: nullptr);
  this->m_pHeadLabelMaterial = v6;
  v6->IncrementReferenceCount(this: v6);
  this->m_bInSquelchMode = false;
  this->m_pHelper = pHelper;
  this->m_pParentPanel = pParentPanel;
  CUserMessages::HookMessage(this: usermessages, name: "VoiceMask", hook: __MsgFunc_VoiceMask);
  CUserMessages::HookMessage(
    this: usermessages,
    name: "RequestState",
    hook: (void (__cdecl *)(bf_read *))__MsgFunc_RequestState);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A95A0
// Name: public: void CVoiceStatus::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::LevelShutdown(CVoiceStatus *this)
{
  bool *m_bAboveThreshold; // edi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  int i; // ebx

  m_bAboveThreshold = this->m_bAboveThreshold;
  p_m_timestamp = &this->m_bAboveThresholdTimer[0].m_timestamp;
  for ( i = 2; i != 0; --i )
  {
    *(m_bAboveThreshold - 2) = false;
    *m_bAboveThreshold = false;
    if ( p_m_timestamp->m_Value != -1.0 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-2].m_Value) + 4))(
        a1: p_m_timestamp - 2,
        a2: p_m_timestamp);
      p_m_timestamp->m_Value = -1.0;
    }
    ++m_bAboveThreshold;
    p_m_timestamp += 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9600
// Name: public: void CVoiceStatus::Frame(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::Frame(CVoiceStatus *this, long double frametime)
{
  if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_LastUpdateServerState) > 1.0 )
    CVoiceStatus::UpdateServerState(this, bForce: false);
}

//------------------------------------------------------------------------------
// Address: 0x101A9630
// Name: public: void CVoiceStatus::DrawHeadLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceStatus::DrawHeadLabels(CVoiceStatus *this)
{
  int v2; // esi
  int v3; // ebx
  int v4; // eax
  int m_nValue; // eax
  int v6; // edx
  C_BasePlayer *LocalPlayer; // esi
  int SplitScreenPlayerSlot; // eax
  bool v9; // bl
  int v10; // eax
  unsigned int *v11; // edx
  int v12; // eax
  IMatRenderContext *v13; // eax
  IMatRenderContext *v14; // edi
  int v15; // esi
  int v16; // edx
  IClientNetworkable *v17; // eax
  C_BasePlayer *v18; // ebx
  int v19; // eax
  int v20; // esi
  IMaterial *(__thiscall *GetHeadLabelMaterial)(C_BasePlayer *); // eax
  IMatRenderContext_vtbl *v22; // esi
  int v23; // eax
  IMesh *v24; // esi
  float v25; // xmm0_4
  float *v26; // eax
  float *m_pCurrPosition; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float *v39; // eax
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float *v46; // eax
  float v47; // xmm1_4
  float v48; // xmm2_4
  float *v49; // eax
  float *v50; // eax
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-288h] BYREF
  float v55; // [esp+1F4h] [ebp-A0h]
  float v56; // [esp+1F8h] [ebp-9Ch]
  float v57; // [esp+1FCh] [ebp-98h]
  float v58; // [esp+200h] [ebp-94h]
  float v59; // [esp+204h] [ebp-90h]
  float v60; // [esp+208h] [ebp-8Ch]
  float v61; // [esp+20Ch] [ebp-88h]
  float v62; // [esp+210h] [ebp-84h]
  float v63; // [esp+214h] [ebp-80h]
  float v64; // [esp+218h] [ebp-7Ch]
  float v65; // [esp+21Ch] [ebp-78h]
  float v66; // [esp+220h] [ebp-74h]
  float v67; // [esp+224h] [ebp-70h]
  int v68; // [esp+228h] [ebp-6Ch]
  int v69; // [esp+22Ch] [ebp-68h]
  int v70; // [esp+230h] [ebp-64h]
  int v71; // [esp+234h] [ebp-60h]
  int v72; // [esp+238h] [ebp-5Ch]
  int v73; // [esp+23Ch] [ebp-58h]
  int v74; // [esp+240h] [ebp-54h]
  int v75; // [esp+244h] [ebp-50h]
  int v76; // [esp+248h] [ebp-4Ch]
  float v77; // [esp+24Ch] [ebp-48h]
  float v78; // [esp+250h] [ebp-44h]
  int v79; // [esp+254h] [ebp-40h]
  float v80; // [esp+258h] [ebp-3Ch]
  int v81; // [esp+25Ch] [ebp-38h]
  int v82; // [esp+260h] [ebp-34h]
  int v83; // [esp+264h] [ebp-30h]
  int v84; // [esp+268h] [ebp-2Ch]
  float v85; // [esp+26Ch] [ebp-28h]
  CVoiceStatus *v86; // [esp+270h] [ebp-24h]
  IClientNetworkable *pClient; // [esp+274h] [ebp-20h]
  float flSize; // [esp+278h] [ebp-1Ch]
  Vector vOrigin; // [esp+27Ch] [ebp-18h] BYREF
  Vector vRight; // [esp+288h] [ebp-Ch] BYREF

  v86 = this;
  if ( voice_all_icons.m_pParent != nullptr && voice_all_icons.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = 0;
    do
    {
      v3 = v2 + 1;
      v4 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 12))(
             a1: cl_entitylist.m_Index + 131092,
             a2: v2 + 1);
      if ( v4 != 0 && v4 != -8 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(v4 + 8) + 36))(a1: v4 + 8) == 0 )
      {
        if ( voice_all_icons.m_pParent != nullptr )
          m_nValue = voice_all_icons.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v6 = 1 << (v2 & 0x1F);
        if ( m_nValue <= 0 )
          this->m_VoicePlayers.m_Ints[v2 >> 5] &= ~v6;
        else
          this->m_VoicePlayers.m_Ints[v2 >> 5] |= v6;
      }
      ++v2;
    }
    while ( v3 < 64 );
  }
  else if ( voice_local_icon.m_pParent != nullptr && voice_local_icon.m_pParent->m_Value.m_nValue != 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this: LocalPlayer);
    v9 = this->m_bTalking[SplitScreenPlayerSlot]
      && CountdownTimer::Now(this: (CEffectsClient *)&this->m_bAboveThresholdTimer[SplitScreenPlayerSlot]) <= this->m_bAboveThresholdTimer[SplitScreenPlayerSlot].m_timestamp.m_Value;
    v10 = LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable) - 1;
    v11 = &this->m_VoicePlayers.m_Ints[v10 >> 5];
    v12 = 1 << (v10 & 0x1F);
    if ( v9 )
      *v11 |= v12;
    else
      *v11 &= ~v12;
  }
  if ( this->m_bHeadLabelsDisabled || this->m_pHeadLabelMaterial == nullptr )
    return;
  v13 = materials->GetRenderContext(this: materials);
  v14 = v13;
  if ( v13 != nullptr )
    v13->BeginRender(this: v13);
  v15 = 0;
  while ( 1 )
  {
    v16 = *(_DWORD *)(cl_entitylist.m_Index + 131092);
    v76 = v15 + 1;
    v17 = (IClientNetworkable *)(*(int (__thiscall **)(unsigned int, int))(v16 + 12))(
                                  a1: cl_entitylist.m_Index + 131092,
                                  a2: v15 + 1);
    if ( v17 != nullptr )
      pClient = v17 + 2;
    else
      pClient = nullptr;
    v18 = (C_BasePlayer *)__RTDynamicCast(
                            inptr: pClient,
                            VfDelta: 0,
                            SrcType: &IClientNetworkable `RTTI Type Descriptor',
                            TargetType: &C_BasePlayer `RTTI Type Descriptor',
                            isReference: 0);
    if ( v18 != nullptr )
    {
      v19 = 1 << (v15 & 0x1F);
      v20 = v15 >> 5;
      v75 = v19;
      if ( (v19 & v86->m_VoicePlayers.m_Ints[v20]) == 0 )
      {
        if ( voice_icons_use_particles.m_pParent == nullptr
          || voice_icons_use_particles.m_pParent->m_Value.m_nValue == 0 )
        {
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      if ( pClient != nullptr && !pClient->IsDormant(this: pClient) )
        break;
      if ( voice_icons_use_particles.m_pParent == nullptr || voice_icons_use_particles.m_pParent->m_Value.m_nValue == 0 )
        goto LABEL_51;
LABEL_50:
      v18->UpdateSpeechVOIP(this: v18, a2: false);
    }
LABEL_51:
    v15 = v76;
    if ( v76 >= 64 )
      goto LABEL_54;
  }
  if ( C_BasePlayer::IsPlayerDead(this: v18) )
  {
    if ( voice_icons_use_particles.m_pParent == nullptr || voice_icons_use_particles.m_pParent->m_Value.m_nValue == 0 )
      goto LABEL_51;
    goto LABEL_50;
  }
  if ( voice_icons_use_particles.m_pParent == nullptr || voice_icons_use_particles.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( (v75 & v86->m_AudiblePlayers.m_Ints[v20]) != 0 )
    {
      v18->EyePosition(this: v18, result: &vOrigin);
      vOrigin.z = voice_head_icon_height.m_pParent->m_Value.m_fValue + vOrigin.z;
      vRight = *CurrentViewRight();
      if ( COERCE_FLOAT(LODWORD(vRight.z) & _mask__AbsFloat_) <= 0.95 )
      {
        vRight.z = 0.0;
        VectorNormalize(vec: &vRight);
        GetHeadLabelMaterial = v18->GetHeadLabelMaterial;
        v22 = v14->__vftable;
        flSize = voice_head_icon_size.m_pParent->m_Value.m_fValue;
        v23 = ((int (__thiscall *)(C_BasePlayer *, _DWORD))GetHeadLabelMaterial)(a1: v18, a2: 0);
        ((void (__thiscall *)(IMatRenderContext *, int))v22->Bind)(a1: v14, a2: v23);
        v24 = v14->GetDynamicMesh(this: v14, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
        CMeshBuilder::CMeshBuilder(this: &meshBuilder);
        CMeshBuilder::Begin(this: &meshBuilder, pMesh: v24, type: 7, numPrimitives: 1);
        v69 = 1258291455;
        v72 = 1258291455;
        v74 = 1258291455;
        v25 = flSize;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v26[1] = 0.0;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v77 = v25;
        v67 = v25 * 0.0;
        LODWORD(v85) = LODWORD(v25) ^ _mask__NegFloat_;
        v28 = (float)(vOrigin.x + (float)(vRight.x * COERCE_FLOAT(LODWORD(v25) ^ _mask__NegFloat_)))
            + (float)(v25 * 0.0);
        v29 = (float)(vOrigin.y + (float)(vRight.y * COERCE_FLOAT(LODWORD(v25) ^ _mask__NegFloat_)))
            + (float)(v25 * 0.0);
        v30 = (float)((float)(COERCE_FLOAT(LODWORD(v25) ^ _mask__NegFloat_) * vRight.z) + vOrigin.z) + v25;
        v64 = v28;
        v65 = v29;
        v66 = v30;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v28;
        m_pCurrPosition[1] = v29;
        m_pCurrPosition[2] = v30;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v31 = flSize;
        v79 = 1258291455;
        v71 = 1258291455;
        v81 = 1258291455;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        v32[1] = 0.0;
        v33 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v34 = (float)((float)(vRight.x * v31) + vOrigin.x) + v67;
        v35 = (float)((float)(vRight.y * v31) + vOrigin.y) + v67;
        v36 = (float)((float)(v31 * vRight.z) + vOrigin.z) + v77;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v34;
        v33[1] = v35;
        v55 = v34;
        v56 = v35;
        v57 = v36;
        v33[2] = v36;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = v85;
        v70 = 1258291455;
        v38 = flSize;
        v84 = 1258291455;
        v68 = 1258291455;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        v39[1] = 1.0;
        v80 = v37 * 0.0;
        v40 = v37 * 0.0;
        v78 = v37;
        v41 = v37;
        v42 = (float)(vRight.x * v38) + vOrigin.x;
        v43 = vRight.y * v38;
        v44 = (float)(v38 * vRight.z) + vOrigin.z;
        v45 = v42 + v40;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v47 = (float)(v43 + vOrigin.y) + v40;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45;
        v46[1] = v47;
        v61 = v45;
        v62 = v47;
        v63 = v44 + v41;
        v46[2] = v44 + v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v48 = v85;
        v82 = 1258291455;
        v83 = 1258291455;
        v73 = 1258291455;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        v49 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v49[1] = 1.0;
        v50 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v51 = (float)((float)(vRight.x * v48) + vOrigin.x) + v80;
        v52 = (float)((float)(vRight.y * v48) + vOrigin.y) + v80;
        v53 = (float)((float)(v48 * vRight.z) + vOrigin.z) + v78;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v51;
        v50[1] = v52;
        v58 = v51;
        v59 = v52;
        v60 = v53;
        v50[2] = v53;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
        v24->Draw_2(this: v24, a2: -1, a3: 0);
        CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      }
    }
    goto LABEL_51;
  }
  v18->UpdateSpeechVOIP(this: v18, a2: true);
LABEL_54:
  if ( v14 != nullptr )
  {
    v14->EndRender(this: v14);
    v14->Release(this: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9D30
// Name: public: void CVoiceStatus::UpdateSpeakerStatus(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVoiceStatus::UpdateSpeakerStatus(
        CVoiceStatus *this@<ecx>,
        _BYTE *a2@<ebx>,
        int a3@<esi>,
        int entindex,
        int iSsSlot,
        bool bTalking)
{
  int m_nValue; // eax
  bool v8; // bl
  int v9; // esi
  int v10; // esi
  float v11; // xmm0_4
  int v12; // edx
  int v13; // eax
  int v14; // ebx
  int v15; // esi
  bool PlayerBan; // al
  const char *v17; // edx
  const char *v18; // ecx
  int v19; // ebx
  bool *m_bTalking; // esi
  float v21; // xmm0_4
  bool v22; // zf
  double v23; // st7
  CEffectsClient *v24; // ebx
  double v25; // st7
  const char *v26; // edx
  const char *v27; // ecx
  CountdownTimer *v28; // edi
  double v29; // st7
  int v30; // eax
  int v31; // edx
  int v32; // eax
  _BYTE v35[44]; // [esp+4h] [ebp-B4h] BYREF
  CVoiceBanMgr::BannedPlayer playerID[2]; // [esp+30h] [ebp-88h] BYREF
  const char *v37; // [esp+94h] [ebp-24h]
  int v38; // [esp+98h] [ebp-20h]
  con_nprint_s np; // [esp+9Ch] [ebp-1Ch] BYREF
  CEffectsClient *m_bAboveThresholdTimer; // [esp+B4h] [ebp-4h]
  float bTalkinga; // [esp+C8h] [ebp+10h]

  if ( this->m_pParentPanel == 0 )
    return;
  if ( voice_clientdebug.m_pParent != nullptr )
  {
    m_nValue = voice_clientdebug.m_pParent->m_Value.m_nValue;
    if ( m_nValue == 1 )
    {
      v8 = bTalking;
      v9 = iSsSlot;
      _Msg(a1: "CVoiceStatus::UpdateSpeakerStatus: ent %d ss[%d] talking = %d\n", entindex, iSsSlot, bTalking);
      goto LABEL_39;
    }
    if ( m_nValue == 2 )
    {
      np.color[0] = 1.0;
      np.color[1] = 1.0;
      np.color[2] = 1.0;
      np.index = 0;
      np.time_to_live = 2.0;
      np.fixed_width_font = true;
      engine->Con_NXPrintf(this: engine, a2: &np, a3: "Total Players: %i", 64);
      v10 = 0;
      do
      {
        ++np.index;
        v38 = v10 + 1;
        if ( (((_BYTE)v10 + 1) & 1) != 0 )
          v11 = 0.69999999;
        else
          v11 = 0.89999998;
        np.color[2] = v11;
        np.color[1] = v11;
        np.color[0] = v11;
        if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int, _BYTE *, int, _BYTE *))engine->GetPlayerInfo)(
               a1: engine,
               a2: v10 + 1,
               a3: v35,
               a4: a3,
               a5: a2) == 0
          || !CVoiceBanMgr::GetPlayerBan(this: &this->m_BanMgr, playerID) )
        {
          v12 = 1 << (v10 & 0x1F);
          v13 = v10 >> 5;
          if ( (v12 & this->m_AudiblePlayers.m_Ints[v13]) != 0 && (v12 & this->m_VoicePlayers.m_Ints[v13]) != 0 )
          {
            np.color[0] = 0.0;
            np.color[1] = 1.0;
            np.color[2] = 0.0;
          }
        }
        v14 = 1 << (v10 & 0x1F);
        v15 = v10 >> 5;
        m_bAboveThresholdTimer = (CEffectsClient *)"YES";
        if ( (v14 & this->m_VoicePlayers.m_Ints[v15]) == 0 )
          m_bAboveThresholdTimer = (CEffectsClient *)" NO";
        v37 = "YES";
        if ( (v14 & this->m_AudiblePlayers.m_Ints[v15]) == 0 )
          v37 = " NO";
        a2 = v35;
        a3 = v38;
        if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *))engine->GetPlayerInfo)(a1: engine) == 0
          || (PlayerBan = CVoiceBanMgr::GetPlayerBan(this: &this->m_BanMgr, playerID), v17 = "YES", !PlayerBan) )
        {
          v17 = " NO";
        }
        v18 = "YES";
        if ( (v14 & this->m_VoiceEnabledPlayers.m_Ints[v15]) == 0 )
          v18 = " NO";
        v10 = v38;
        engine->Con_NXPrintf(
          this: engine,
          a2: &np,
          a3: "%02i enabled(%s) blocked(%s) audible(%s) speaking(%s)",
          v38,
          v18,
          v17,
          v37,
          m_bAboveThresholdTimer);
      }
      while ( v10 + 1 <= 64 );
      np.index += 2;
      np.color[0] = 1.0;
      np.color[1] = 1.0;
      np.color[2] = 1.0;
      engine->Con_NXPrintf(this: engine, a2: &np, a3: "Local Players: %i", 2);
      LOBYTE(v19) = -53 - (_BYTE)this;
      m_bTalking = this->m_bTalking;
      m_bAboveThresholdTimer = (CEffectsClient *)this->m_bAboveThresholdTimer;
      v38 = -53 - (_DWORD)this;
      do
      {
        ++np.index;
        if ( (((_BYTE)m_bTalking + (_BYTE)v19) & 1) != 0 )
          v21 = 0.69999999;
        else
          v21 = 0.89999998;
        v22 = !*m_bTalking;
        np.color[2] = v21;
        np.color[1] = v21;
        np.color[0] = v21;
        if ( v22 )
          goto LABEL_34;
        v23 = CountdownTimer::Now(this: m_bAboveThresholdTimer);
        v24 = m_bAboveThresholdTimer;
        if ( v23 <= *(float *)&m_bAboveThresholdTimer->m_bSuppressEvent )
        {
          np.color[0] = 0.0;
          np.color[1] = 1.0;
          np.color[2] = 0.0;
        }
        if ( !*m_bTalking
          || (v25 = CountdownTimer::Now(this: m_bAboveThresholdTimer),
              v26 = "YES",
              v25 > *(float *)&v24->m_bSuppressEvent) )
        {
LABEL_34:
          v26 = " NO";
        }
        v27 = "YES";
        if ( !*m_bTalking )
          v27 = " NO";
        v19 = v38;
        engine->Con_NXPrintf(
          this: engine,
          a2: &np,
          a3: "%02i speaking(%s) above_threshold(%s)",
          &m_bTalking[v38],
          v27,
          v26);
        m_bAboveThresholdTimer = (CEffectsClient *)((char *)m_bAboveThresholdTimer + 12);
        ++m_bTalking;
      }
      while ( (int)&m_bTalking[v19] < 2 );
    }
  }
  v9 = iSsSlot;
  v8 = bTalking;
LABEL_39:
  switch ( entindex )
  {
    case -1:
      if ( v9 >= 0 )
        this->m_bTalking[v9] = v8;
      break;
    case -2:
      if ( v9 >= 0 )
        this->m_bServerAcked[v9] = v8;
      break;
    case -3:
      if ( v9 >= 0 )
      {
        this->m_bAboveThreshold[v9] = v8;
        if ( v8 )
        {
          v28 = &this->m_bAboveThresholdTimer[v9];
          v29 = CountdownTimer::Now(this: (CEffectsClient *)v28) + 0.5;
          if ( v28->m_timestamp.m_Value != v29 )
          {
            v28->NetworkStateChanged(this: v28, a2: &v28->m_timestamp);
            bTalkinga = v29;
            v28->m_timestamp.m_Value = bTalkinga;
          }
          if ( v28->m_duration.m_Value != 0.5 )
          {
            v28->NetworkStateChanged(this: v28, a2: &v28->m_duration);
            v28->m_duration.m_Value = 0.5;
          }
        }
      }
      break;
    default:
      v30 = entindex - 1;
      if ( (unsigned int)(entindex - 1) <= 0x3F )
      {
        if ( v8 )
        {
          v31 = 1 << (v30 & 0x1F);
          v32 = v30 >> 5;
          this->m_VoicePlayers.m_Ints[v32] |= v31;
          this->m_VoiceEnabledPlayers.m_Ints[v32] |= v31;
        }
        else
        {
          this->m_VoicePlayers.m_Ints[v30 >> 5] &= ~(1 << (v30 & 0x1F));
        }
      }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA160
// Name: void ClientVoiceMgr_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientVoiceMgr_LevelInit()
{
  if ( g_VoiceStatus != nullptr )
    CVoiceStatus::LevelShutdown(this: g_VoiceStatus);
}

//------------------------------------------------------------------------------
// Address: 0x101AA170
// Name: public: CVoiceStatus::CVoiceStatus(void)
// Source: json
//------------------------------------------------------------------------------
CVoiceStatus *__thiscall CVoiceStatus::CVoiceStatus(CVoiceStatus *this)
{
  CountdownTimer *m_bAboveThresholdTimer; // edi
  CountdownTimer *v3; // esi
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  bool *m_bServerAcked; // esi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  int v9; // [esp+Ch] [ebp-4h]
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CVoiceStatus_vtbl *)&CVoiceStatus::`vftable';
  if ( this != (CVoiceStatus *)-16 )
    this->m_VoicePlayers = 0;
  if ( this != (CVoiceStatus *)-24 )
    this->m_AudiblePlayers = 0;
  if ( this != (CVoiceStatus *)-32 )
    this->m_VoiceEnabledPlayers = 0;
  if ( this != (CVoiceStatus *)-40 )
    this->m_ServerBannedPlayers = 0;
  CVoiceBanMgr::CVoiceBanMgr(this: &this->m_BanMgr);
  m_bAboveThresholdTimer = this->m_bAboveThresholdTimer;
  v9 = 1;
  v3 = this->m_bAboveThresholdTimer;
  do
  {
    m_bAboveThresholdTimer->__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
    v4 = v3->__vftable;
    v3->m_duration.m_Value = 0.0;
    v4->NetworkStateChanged(this: v3, a2: &v3->m_duration);
    v5 = v3->__vftable;
    v3->m_timestamp.m_Value = -1.0;
    v5->NetworkStateChanged(this: v3, a2: &v3->m_timestamp);
    ++m_bAboveThresholdTimer;
    ++v3;
    --v9;
  }
  while ( v9 >= 0 );
  this->m_LastUpdateServerState = 0.0;
  this->m_nControlSize = 0;
  this->m_bBanMgrInitialized = false;
  m_bServerAcked = this->m_bServerAcked;
  p_m_timestamp = &this->m_bAboveThresholdTimer[0].m_timestamp;
  for ( i = 2; i != 0; --i )
  {
    *(m_bServerAcked - 4) = false;
    *m_bServerAcked = false;
    *(m_bServerAcked - 2) = false;
    if ( p_m_timestamp->m_Value != -1.0 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-2].m_Value) + 4))(
        a1: p_m_timestamp - 2,
        a2: p_m_timestamp);
      p_m_timestamp->m_Value = -1.0;
    }
    ++m_bServerAcked;
    p_m_timestamp += 3;
  }
  this->m_bServerModEnable = -1;
  this->m_pHeadLabelMaterial = nullptr;
  this->m_bHeadLabelsDisabled = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101AA2A0
// Name: void ClientVoiceMgr_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientVoiceMgr_Init()
{
  CVoiceStatus *v0; // eax

  if ( g_VoiceStatus == nullptr )
  {
    v0 = (CVoiceStatus *)MemAlloc_Alloc(nSize: 0x2864u);
    if ( v0 != nullptr )
      g_VoiceStatus = CVoiceStatus::CVoiceStatus(this: v0);
    else
      g_VoiceStatus = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA2E0
// Name: class CVoiceStatus __near * GetClientVoiceMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVoiceStatus *__cdecl GetClientVoiceMgr()
{
  CVoiceStatus *result; // eax
  CVoiceStatus *v1; // eax

  result = g_VoiceStatus;
  if ( g_VoiceStatus == nullptr )
  {
    v1 = (CVoiceStatus *)MemAlloc_Alloc(nSize: 0x2864u);
    if ( v1 != nullptr )
    {
      result = CVoiceStatus::CVoiceStatus(this: v1);
      g_VoiceStatus = result;
    }
    else
    {
      g_VoiceStatus = nullptr;
      return nullptr;
    }
  }
  return result;
}
