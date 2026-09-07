// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_stubs.cpp
// Functions: 19
// ============================================================

#include "engine\audio\private\snd_stubs.h"

//------------------------------------------------------------------------------
// Address: 0x100364E0
// Name: public: virtual bool CEngineVoiceSteam::IsLocalPlayerTalking(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVoiceSteam::IsLocalPlayerTalking(CEngineVoiceSteam *this, int iController)
{
  CSteam3Client *v3; // eax
  int v4; // eax
  CStatTime *v5; // ecx

  v3 = Steam3Client();
  v4 = v3->m_pSteamUser->GetAvailableVoice(this: v3->m_pSteamUser, a2: nullptr, a3: nullptr);
  return v4 == 0 || v4 == 3 || _Plat_FloatTime(this: v5) - this->m_flLastTalkingTimestamp <= 0.2000000029802322;
}

//------------------------------------------------------------------------------
// Address: 0x10036530
// Name: public: virtual void CEngineVoiceSteam::VoiceResetLocalData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::VoiceResetLocalData(CEngineVoiceSteam *this, int iController)
{
  memset(dst: &this->m_pbVoiceData[(unsigned int)(73728 * iController) >> 2], value: 0, count: 0x4800u);
}

//------------------------------------------------------------------------------
// Address: 0x10036560
// Name: public: virtual void CEngineVoiceStub::GetRemoteTalkers(int __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::GetRemoteTalkers(
        CEngineVoiceStub *this,
        int *pNumTalkers,
        unsigned __int64 *pRemoteTalkers)
{
  if ( pNumTalkers != nullptr )
    *pNumTalkers = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036590
// Name: public: virtual void CEngineVoiceStub::GetVoiceData(int,unsigned char const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::GetVoiceData(
        CEngineVoiceStub *this,
        int iController,
        const unsigned __int8 **ppvVoiceDataBuffer,
        unsigned int *pnumVoiceDataBytes)
{
  if ( ppvVoiceDataBuffer != nullptr )
    *ppvVoiceDataBuffer = nullptr;
  if ( pnumVoiceDataBytes != nullptr )
    *pnumVoiceDataBytes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100365C0
// Name: public: virtual void CEngineVoiceStub::PlayIncomingVoiceData(unsigned __int64,unsigned char const __near *,unsigned int,bool const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::PlayIncomingVoiceData(
        CAudioDeviceNull *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        portable_samplepair_t *samplecount)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100365D0
// Name: public: virtual void CEngineVoiceSteam::GetVoiceData(int,unsigned char const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CEngineVoiceSteam::GetVoiceData(
        CEngineVoiceSteam *this,
        unsigned int iController,
        const unsigned __int8 **ppvVoiceDataBuffer,
        unsigned int *pnumVoiceDataBytes)
{
  const unsigned __int8 **v4; // ebx
  const unsigned __int8 *v5; // esi
  unsigned int *v6; // edi
  CSteam3Client *v7; // eax
  int v8; // eax
  void *v9; // esp
  CSteam3Client *v10; // eax
  int v11; // esi
  double v12; // st7
  int v13; // [esp-5630h] [ebp-563Ch] BYREF

  v4 = ppvVoiceDataBuffer;
  v5 = &this->m_pbVoiceData[(73728 * iController) >> 2];
  *ppvVoiceDataBuffer = v5;
  v6 = pnumVoiceDataBytes;
  if ( this->m_bVoiceForPs3 )
  {
    v9 = alloca(22064);
    iController = 22050;
    v10 = Steam3Client();
    v8 = v10->m_pSteamUser->GetVoice(
           this: v10->m_pSteamUser,
           a2: false,
           a3: nullptr,
           a4: 0,
           a5: nullptr,
           a6: true,
           a7: &v13,
           a8: iController,
           a9: &iController);
  }
  else
  {
    v7 = Steam3Client();
    v8 = v7->m_pSteamUser->GetVoice(
           this: v7->m_pSteamUser,
           a2: true,
           a3: (void *)v5,
           a4: 18432u,
           a5: v6,
           a6: false,
           a7: nullptr,
           a8: 0,
           a9: nullptr);
  }
  v11 = v8;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    ConVarRef::ConVarRef(this: &voice_enable, pName: "voice_enable");
  }
  if ( (_S2 & 2) == 0 )
  {
    _S2 |= 2u;
    ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  }
  if ( (_S2 & 4) == 0 )
  {
    _S2 |= 4u;
    ConVarRef::ConVarRef(this: &voice_ptt, pName: "voice_ptt");
  }
  if ( voice_enable.m_pConVarState->m_Value.m_nValue == 0
    || voice_vox.m_pConVarState->m_Value.m_nValue == 0
    && (iController = LODWORD(voice_ptt.m_pConVarState->m_Value.m_fValue), *(float *)&iController != 0.0)
    && (v12 = _Plat_FloatTime(this: (CStatTime *)voice_vox.m_pConVarState)) - *(float *)&iController > 1.0
    || v11 != 0 && v11 != 3 )
  {
    *v6 = 0;
    *v4 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036720
// Name: protected: void CEngineVoiceSteam::AudioInitializationUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::AudioInitializationUpdate(CEngineVoiceSteam *this)
{
  bool v2; // bl
  int v3; // eax

  v2 = this->m_arrRemoteVoice.m_Size > 0;
  v3 = 0;
  while ( !this->m_bLocalVoice[v3] )
  {
    if ( (unsigned int)++v3 >= 4 )
      goto LABEL_6;
  }
  v2 = true;
LABEL_6:
  if ( v2 != this->m_bInitializedAudio )
  {
    memset(dst: this->m_pbVoiceData, value: 0, count: sizeof(this->m_pbVoiceData));
    if ( v2 )
    {
      Voice_ForceInit();
      this->m_bInitializedAudio = v2;
    }
    else
    {
      Voice_Deinit();
      this->m_bInitializedAudio = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036780
// Name: class CEngineVoiceStub __near * Audio_GetEngineVoiceStub(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceStub *__cdecl Audio_GetEngineVoiceStub()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    s_EngineVoiceStub.__vftable = (CEngineVoiceStub_vtbl *)&CEngineVoiceStub::`vftable';
  }
  return &s_EngineVoiceStub;
}

//------------------------------------------------------------------------------
// Address: 0x100367B0
// Name: protected: bool CEngineVoiceSteam::IsPlayerTalking(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVoiceSteam::IsPlayerTalking(CEngineVoiceSteam *this, unsigned __int64 uid)
{
  IMatchSystem *v3; // eax
  IMatchVoice *v4; // eax
  bool result; // al
  int m_Size; // edx
  int v7; // eax
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // esi
  CStatTime *i; // ecx

  v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v4 = v3->GetMatchVoice(this: v3);
  result = ((int (__thiscall *)(IMatchVoice *, _DWORD, _DWORD))v4->CanPlaybackTalker)(a1: v4, a2: uid, a3: HIDWORD(uid));
  if ( result )
  {
    m_Size = this->m_arrRemoteVoice.m_Size;
    v7 = 0;
    if ( m_Size <= 0 )
    {
      return false;
    }
    else
    {
      m_pMemory = this->m_arrRemoteVoice.m_Memory.m_pMemory;
      for ( i = (CStatTime *)m_pMemory; *(_QWORD *)&i->__vftable != uid; i += 6 )
      {
        if ( ++v7 >= m_Size )
          return false;
      }
      return _Plat_FloatTime(this: i) - m_pMemory[v7].m_flLastTalkTimestamp < 0.2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036850
// Name: public: virtual void CEngineVoiceSteam::GetRemoteTalkers(int __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::GetRemoteTalkers(
        CEngineVoiceSteam *this,
        int *pNumTalkers,
        unsigned __int64 *pRemoteTalkers)
{
  int v3; // eax
  int v4; // edx
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // esi

  if ( pNumTalkers != nullptr )
    *pNumTalkers = this->m_arrRemoteVoice.m_Size;
  if ( pRemoteTalkers != nullptr )
  {
    v3 = 0;
    if ( this->m_arrRemoteVoice.m_Size > 0 )
    {
      v4 = 0;
      do
      {
        m_pMemory = this->m_arrRemoteVoice.m_Memory.m_pMemory;
        LODWORD(pRemoteTalkers[v3]) = m_pMemory[v4].m_xuid;
        HIDWORD(pRemoteTalkers[v3++]) = HIDWORD(m_pMemory[v4++].m_xuid);
      }
      while ( v3 < this->m_arrRemoteVoice.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100368A0
// Name: protected: void CEngineVoiceSteam::UpdateHUDVoiceStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEngineVoiceSteam::UpdateHUDVoiceStatus(
        CEngineVoiceSteam *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  int v4; // esi
  int v5; // edi
  char v6; // bl
  bool (__thiscall *GetPlayerInfo)(IVEngineClient *, int, player_info_s *); // edx
  int v8; // ebx
  bool IsPlayerTalking; // al
  void (__thiscall *OnChangeVoiceStatus)(ISoundServices *, int, int, bool); // edx
  player_info_s infoClient; // [esp+0h] [ebp-A0h] BYREF
  int iIndex; // [esp+90h] [ebp-10h]
  CEngineVoiceSteam *v16; // [esp+94h] [ebp-Ch]
  int bTalking; // [esp+98h] [ebp-8h]
  int iSsSlot; // [esp+9Ch] [ebp-4h]

  v16 = this;
  if ( GetBaseLocalClient()->m_nMaxClients > 0 )
  {
    v4 = 1;
    do
    {
      v5 = -1;
      v6 = 0;
      iSsSlot = -1;
      if ( GetLocalClient(nSlot: 0)->m_nPlayerSlot == v4 - 1 )
      {
        v5 = 0;
        v6 = 1;
        iSsSlot = 0;
      }
      GetPlayerInfo = engineClient->GetPlayerInfo;
      iIndex = v4;
      if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int, player_info_s *, int, int, int))GetPlayerInfo)(
             a1: engineClient,
             a2: v4,
             a3: &infoClient,
             a4: a3,
             a5: a4,
             a6: a2) != 0
        && infoClient.xuid != 0 )
      {
        if ( v6 != 0 )
        {
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v4, a3: -1, a4: false);
          v8 = -1;
          IsPlayerTalking = v16->IsLocalPlayerTalking(this: v16, a2: v5);
        }
        else
        {
          IsPlayerTalking = CEngineVoiceSteam::IsPlayerTalking(this: v16, uid: infoClient.xuid);
          v8 = iIndex;
        }
        OnChangeVoiceStatus = g_pSoundServices->OnChangeVoiceStatus;
        LOBYTE(bTalking) = IsPlayerTalking;
        a2 = bTalking;
        a4 = iSsSlot;
        a3 = v8;
        ((void (__thiscall *)(ISoundServices *))OnChangeVoiceStatus)(a1: g_pSoundServices);
      }
      else
      {
        a2 = 0;
        a4 = -1;
        a3 = v4;
        ((void (__thiscall *)(ISoundServices *))g_pSoundServices->OnChangeVoiceStatus)(a1: g_pSoundServices);
        if ( v6 != 0 )
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v4, a3: iSsSlot, a4: false);
      }
      ++v4;
    }
    while ( v4 - 1 < GetBaseLocalClient()->m_nMaxClients );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036A00
// Name: public: virtual void CEngineVoiceSteam::RemovePlayerFromVoiceList(unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::RemovePlayerFromVoiceList(
        CEngineVoiceSteam *this,
        unsigned __int64 xPlayer,
        unsigned int iController)
{
  CSteam3Client *v4; // eax
  int m_Size; // esi
  int v6; // eax
  CEngineVoiceSteam::RemoteTalker_t *i; // edx

  if ( xPlayer != 0 )
  {
    m_Size = this->m_arrRemoteVoice.m_Size;
    v6 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_arrRemoteVoice.m_Memory.m_pMemory; i->m_xuid != xPlayer; ++i )
      {
        if ( ++v6 >= m_Size )
          return;
      }
      if ( v6 != -1 )
      {
        CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::FastRemove(
          this: &this->m_arrRemoteVoice,
          elem: v6);
        CEngineVoiceSteam::AudioInitializationUpdate(this);
      }
    }
  }
  else if ( iController <= 3 )
  {
    this->m_bLocalVoice[iController] = false;
    CEngineVoiceSteam::AudioInitializationUpdate(this);
    v4 = Steam3Client();
    v4->m_pSteamUser->StopVoiceRecording(this: v4->m_pSteamUser);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036A80
// Name: public: virtual bool CEngineVoiceSteam::VoiceUpdateData(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVoiceSteam::VoiceUpdateData(CEngineVoiceSteam *this, int iController)
{
  CSteam3Client *v3; // eax
  int v4; // eax
  CStatTime *v5; // ecx
  bool v6; // bl

  v3 = Steam3Client();
  v4 = v3->m_pSteamUser->GetAvailableVoice(this: v3->m_pSteamUser, a2: nullptr, a3: nullptr);
  v6 = v4 == 0;
  if ( v4 == 0 )
    this->m_flLastTalkingTimestamp = _Plat_FloatTime(this: v5);
  CEngineVoiceSteam::UpdateHUDVoiceStatus(this);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10036AC0
// Name: public: virtual void CEngineVoiceSteam::RemoveAllTalkers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::RemoveAllTalkers(CEngineVoiceSteam *this)
{
  *(_DWORD *)this->m_bLocalVoice = 0;
  this->m_arrRemoteVoice.m_Size = 0;
  CEngineVoiceSteam::AudioInitializationUpdate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036B60
// Name: public: CEngineVoiceSteam::CEngineVoiceSteam(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceSteam *__thiscall CEngineVoiceSteam::CEngineVoiceSteam(CEngineVoiceSteam *this)
{
  this->__vftable = (CEngineVoiceSteam_vtbl *)&CEngineVoiceSteam::`vftable';
  this->m_arrRemoteVoice.m_Memory.m_pMemory = nullptr;
  this->m_arrRemoteVoice.m_Memory.m_nAllocationCount = 0;
  this->m_arrRemoteVoice.m_Memory.m_nGrowSize = 0;
  this->m_arrRemoteVoice.m_Size = 0;
  this->m_arrRemoteVoice.m_pElements = nullptr;
  this->m_resampleCelp2Pc.m_sampLeftover = 0;
  this->m_resampleCelp2Pc.m_iTargetTick = 0;
  this->m_resamplePc2Celp.m_sampLeftover = 0;
  this->m_resamplePc2Celp.m_iTargetTick = 0;
  *(_DWORD *)this->m_bLocalVoice = 0;
  memset(dst: this->m_pbVoiceData, value: 0, count: sizeof(this->m_pbVoiceData));
  *(_WORD *)&this->m_bVoiceForPs3 = 0;
  this->m_flLastTalkingTimestamp = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036BD0
// Name: public: virtual void CEngineVoiceSteam::AddPlayerToVoiceList(unsigned __int64,int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::AddPlayerToVoiceList(
        CEngineVoiceSteam *this,
        unsigned __int64 xPlayer,
        unsigned int iController,
        unsigned __int64 uiFlags)
{
  int m_nValue; // eax
  CSteam3Client *v6; // eax
  int v7; // eax
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // ecx
  int m_Size; // eax
  CSteam3Client *v10; // eax
  CEngineVoiceSteam::RemoteTalker_t rt; // [esp+8h] [ebp-18h] BYREF

  if ( xPlayer != 0 )
  {
    v7 = 0;
    if ( this->m_arrRemoteVoice.m_Size <= 0 )
      goto LABEL_12;
    m_pMemory = this->m_arrRemoteVoice.m_Memory.m_pMemory;
    while ( m_pMemory->m_xuid != xPlayer )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= this->m_arrRemoteVoice.m_Size )
        goto LABEL_12;
    }
    if ( v7 == -1 )
    {
LABEL_12:
      m_Size = this->m_arrRemoteVoice.m_Size;
      rt.m_xuid = xPlayer;
      rt.m_uiFlags = uiFlags;
      rt.m_flLastTalkTimestamp = 0.0;
      CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
        this: &this->m_arrRemoteVoice,
        elem: m_Size,
        src: &rt);
      this->m_bVoiceForPs3 = (uiFlags & 1) != 0;
      CEngineVoiceSteam::AudioInitializationUpdate(this);
      v10 = Steam3Client();
      v10->m_pSteamUser->StartVoiceRecording(this: v10->m_pSteamUser);
    }
  }
  else if ( iController <= 3 )
  {
    this->m_bLocalVoice[iController] = true;
    CEngineVoiceSteam::AudioInitializationUpdate(this);
    if ( snd_voice_echo.m_pParent != nullptr )
    {
      m_nValue = snd_voice_echo.m_pParent->m_Value.m_nValue;
      if ( m_nValue != 0 )
      {
        this->m_bVoiceForPs3 = m_nValue == 2;
        v6 = Steam3Client();
        v6->m_pSteamUser->StartVoiceRecording(this: v6->m_pSteamUser);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036CC0
// Name: public: virtual void CEngineVoiceSteam::PlayIncomingVoiceData(unsigned __int64,unsigned char const __near *,unsigned int,bool const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::PlayIncomingVoiceData(
        CEngineVoiceSteam *this,
        unsigned __int64 xuid,
        const unsigned __int8 *pbData,
        unsigned int dwDataSize,
        const bool *bAudiblePlayers)
{
  int v5; // edi
  int i; // esi
  IMatchSystem *v7; // eax
  int v8; // eax
  int (__thiscall ***v9)(_DWORD); // eax
  int v10; // edx
  IMatchSystem *v11; // eax
  IMatchVoice *v12; // eax
  int m_Size; // edx
  int v14; // eax
  CEngineVoiceSteam::RemoteTalker_t *j; // ecx
  CEngineVoiceSteam *v16; // ebx
  BOOL m_bVoiceForPs3; // eax
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // eax
  int v19; // esi
  CSteam3Client *v20; // eax
  int Channel; // eax
  CEngineVoiceSteam::RemoteTalker_t *v22; // edi
  CStatTime *v23; // ecx
  char v24[20]; // [esp+10h] [ebp-5644h] BYREF
  CEngineVoiceSteam::RemoteTalker_t v25; // [esp+5634h] [ebp-20h] BYREF
  int v26; // [esp+564Ch] [ebp-8h] BYREF
  CEngineVoiceSteam *v27; // [esp+5650h] [ebp-4h]

  v5 = 0;
  v27 = this;
  for ( i = 0; i == 0; ++i )
  {
    v7 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
    v8 = v7->GetPlayerManager(this: v7);
    v9 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 4))(a1: v8, a2: i);
    if ( v9 != nullptr && (**v9)(a1: v9) == (_DWORD)xuid && v10 == HIDWORD(xuid) )
    {
      if ( snd_voice_echo.m_pParent == nullptr || snd_voice_echo.m_pParent->m_Value.m_nValue == 0 )
        return;
      v16 = v27;
      if ( v27->m_arrRemoteVoice.m_Size == 0 )
      {
        m_bVoiceForPs3 = v27->m_bVoiceForPs3;
        v25.m_xuid = 0;
        v25.m_flLastTalkTimestamp = 0.0;
        v25.m_uiFlags = m_bVoiceForPs3;
        CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
          this: &v27->m_arrRemoteVoice,
          elem: v27->m_arrRemoteVoice.m_Size,
          src: &v25);
      }
      goto playvoice;
    }
  }
  v11 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v12 = v11->GetMatchVoice(this: v11);
  if ( ((int (__thiscall *)(IMatchVoice *, _DWORD, _DWORD))v12->CanPlaybackTalker)(a1: v12, a2: xuid, a3: HIDWORD(xuid)) != 0 )
  {
    m_Size = v27->m_arrRemoteVoice.m_Size;
    v14 = 0;
    if ( m_Size > 0 )
    {
      for ( j = v27->m_arrRemoteVoice.m_Memory.m_pMemory; j->m_xuid != xuid; ++j )
      {
        if ( ++v14 >= m_Size )
          return;
      }
      v5 = v14;
      if ( v14 != -1 )
      {
        v16 = v27;
playvoice:
        m_pMemory = v16->m_arrRemoteVoice.m_Memory.m_pMemory;
        v26 = 0;
        v19 = v5;
        if ( (m_pMemory[v5].m_uiFlags & 1) != 0
          || (v20 = Steam3Client(),
              v20->m_pSteamUser->DecompressVoice(
                this: v20->m_pSteamUser,
                a2: pbData,
                a3: dwDataSize,
                a4: v24,
                a5: 22050u,
                a6: (unsigned int *)&v26) == k_EVoiceResultOK) )
        {
          Channel = Voice_GetChannel(nEntity: v5);
          if ( Channel != -1 || (Channel = Voice_AssignChannel(nEntity: v5, bProximity: false, timePadding: 0.0)) != -1 )
          {
            Voice_AddIncomingData(nChannel: Channel, pchData: v24, nCount: v26, iSequenceNumber: 0, isCompressed: false);
            v22 = v16->m_arrRemoteVoice.m_Memory.m_pMemory;
            v22[v19].m_flLastTalkTimestamp = _Plat_FloatTime(this: v23);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036E70
// Name: class IEngineVoice __near * Audio_GetEngineVoiceSteam(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceSteam *__cdecl Audio_GetEngineVoiceSteam()
{
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    CEngineVoiceSteam::CEngineVoiceSteam(this: &s_EngineVoiceSteam);
    atexit(func: Audio_GetEngineVoiceSteam_::_2_::_dynamic_atexit_destructor_for__s_EngineVoiceSteam__);
  }
  return &s_EngineVoiceSteam;
}

//------------------------------------------------------------------------------
// Address: 0x102DCB60
// Name: public: virtual void CEngineVoiceStub::SetPlaybackPriority(unsigned __int64,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::SetPlaybackPriority(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10036220
// Name: public: virtual bool CEngineVoiceSteam::IsLocalPlayerTalking(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVoiceSteam::IsLocalPlayerTalking(CEngineVoiceSteam *this, int iController)
{
  CSteam3Client *v3; // eax
  int v4; // eax

  v3 = Steam3Client();
  v4 = v3->m_pSteamUser->GetAvailableVoice(this: v3->m_pSteamUser, a2: nullptr, a3: nullptr);
  return v4 == 0 || v4 == 3 || _Plat_FloatTime() - this->m_flLastTalkingTimestamp <= 0.2000000029802322;
}

//------------------------------------------------------------------------------
// Address: 0x10036270
// Name: public: virtual void CEngineVoiceSteam::VoiceResetLocalData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::VoiceResetLocalData(CEngineVoiceSteam *this, int iController)
{
  memset(dst: &this->m_pbVoiceData[(unsigned int)(73728 * iController) >> 2], value: 0, count: 0x4800u);
}

//------------------------------------------------------------------------------
// Address: 0x100362A0
// Name: public: virtual void CEngineVoiceStub::GetRemoteTalkers(int __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::GetRemoteTalkers(
        CEngineVoiceStub *this,
        int *pNumTalkers,
        unsigned __int64 *pRemoteTalkers)
{
  if ( pNumTalkers != nullptr )
    *pNumTalkers = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100362C0
// Name: public: virtual void CEngineVoiceStub::GetVoiceData(int,unsigned char const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::GetVoiceData(
        CEngineVoiceStub *this,
        int iController,
        const unsigned __int8 **ppvVoiceDataBuffer,
        unsigned int *pnumVoiceDataBytes)
{
  if ( ppvVoiceDataBuffer != nullptr )
    *ppvVoiceDataBuffer = nullptr;
  if ( pnumVoiceDataBytes != nullptr )
    *pnumVoiceDataBytes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100362F0
// Name: public: virtual void CEngineVoiceStub::PlayIncomingVoiceData(unsigned __int64,unsigned char const __near *,unsigned int,bool const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::PlayIncomingVoiceData(
        CAudioDeviceNull *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        portable_samplepair_t *samplecount)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10036300
// Name: public: virtual void CEngineVoiceSteam::GetVoiceData(int,unsigned char const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CEngineVoiceSteam::GetVoiceData(
        CEngineVoiceSteam *this,
        unsigned int iController,
        const unsigned __int8 **ppvVoiceDataBuffer,
        unsigned int *pnumVoiceDataBytes)
{
  const unsigned __int8 **v4; // ebx
  const unsigned __int8 *v5; // esi
  unsigned int *v6; // edi
  CSteam3Client *v7; // eax
  int v8; // eax
  void *v9; // esp
  CSteam3Client *v10; // eax
  int v11; // esi
  int v12; // [esp-5630h] [ebp-563Ch] BYREF

  v4 = ppvVoiceDataBuffer;
  v5 = &this->m_pbVoiceData[(73728 * iController) >> 2];
  *ppvVoiceDataBuffer = v5;
  v6 = pnumVoiceDataBytes;
  if ( this->m_bVoiceForPs3 )
  {
    v9 = alloca(22064);
    iController = 22050;
    v10 = Steam3Client();
    v8 = v10->m_pSteamUser->GetVoice(
           this: v10->m_pSteamUser,
           a2: false,
           a3: nullptr,
           a4: 0,
           a5: nullptr,
           a6: true,
           a7: &v12,
           a8: iController,
           a9: &iController);
  }
  else
  {
    v7 = Steam3Client();
    v8 = v7->m_pSteamUser->GetVoice(
           this: v7->m_pSteamUser,
           a2: true,
           a3: (void *)v5,
           a4: 18432u,
           a5: v6,
           a6: false,
           a7: nullptr,
           a8: 0,
           a9: nullptr);
  }
  v11 = v8;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    ConVarRef::ConVarRef(this: &voice_enable, pName: "voice_enable");
  }
  if ( (_S2 & 2) == 0 )
  {
    _S2 |= 2u;
    ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  }
  if ( (_S2 & 4) == 0 )
  {
    _S2 |= 4u;
    ConVarRef::ConVarRef(this: &voice_ptt, pName: "voice_ptt");
  }
  if ( voice_enable.m_pConVarState->m_Value.m_nValue == 0
    || voice_vox.m_pConVarState->m_Value.m_nValue == 0
    && (iController = LODWORD(voice_ptt.m_pConVarState->m_Value.m_fValue), *(float *)&iController != 0.0)
    && _Plat_FloatTime() - *(float *)&iController > 1.0
    || v11 != 0 && v11 != 3 )
  {
    *v6 = 0;
    *v4 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036450
// Name: protected: void CEngineVoiceSteam::AudioInitializationUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::AudioInitializationUpdate(CEngineVoiceSteam *this)
{
  bool v2; // bl
  int v3; // eax

  v2 = this->m_arrRemoteVoice.m_Size > 0;
  v3 = 0;
  while ( !this->m_bLocalVoice[v3] )
  {
    if ( (unsigned int)++v3 >= 4 )
      goto LABEL_6;
  }
  v2 = true;
LABEL_6:
  if ( v2 != this->m_bInitializedAudio )
  {
    memset(dst: this->m_pbVoiceData, value: 0, count: sizeof(this->m_pbVoiceData));
    if ( v2 )
    {
      Voice_ForceInit();
      this->m_bInitializedAudio = v2;
    }
    else
    {
      Voice_Deinit();
      this->m_bInitializedAudio = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100364B0
// Name: class CEngineVoiceStub __near * Audio_GetEngineVoiceStub(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceStub *__cdecl Audio_GetEngineVoiceStub()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    s_EngineVoiceStub.__vftable = (CEngineVoiceStub_vtbl *)&CEngineVoiceStub::`vftable';
  }
  return &s_EngineVoiceStub;
}

//------------------------------------------------------------------------------
// Address: 0x10036580
// Name: public: virtual void CEngineVoiceSteam::GetRemoteTalkers(int __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::GetRemoteTalkers(
        CEngineVoiceSteam *this,
        int *pNumTalkers,
        unsigned __int64 *pRemoteTalkers)
{
  int v3; // eax
  int v4; // edx
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // esi

  if ( pNumTalkers != nullptr )
    *pNumTalkers = this->m_arrRemoteVoice.m_Size;
  if ( pRemoteTalkers != nullptr )
  {
    v3 = 0;
    if ( this->m_arrRemoteVoice.m_Size > 0 )
    {
      v4 = 0;
      do
      {
        m_pMemory = this->m_arrRemoteVoice.m_Memory.m_pMemory;
        LODWORD(pRemoteTalkers[v3]) = m_pMemory[v4].m_xuid;
        HIDWORD(pRemoteTalkers[v3++]) = HIDWORD(m_pMemory[v4++].m_xuid);
      }
      while ( v3 < this->m_arrRemoteVoice.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036730
// Name: public: virtual void CEngineVoiceSteam::RemovePlayerFromVoiceList(unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::RemovePlayerFromVoiceList(
        CEngineVoiceSteam *this,
        unsigned __int64 xPlayer,
        unsigned int iController)
{
  CSteam3Client *v4; // eax
  int m_Size; // esi
  int v6; // eax
  CEngineVoiceSteam::RemoteTalker_t *i; // edx

  if ( xPlayer != 0 )
  {
    m_Size = this->m_arrRemoteVoice.m_Size;
    v6 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_arrRemoteVoice.m_Memory.m_pMemory; i->m_xuid != xPlayer; ++i )
      {
        if ( ++v6 >= m_Size )
          return;
      }
      if ( v6 != -1 )
      {
        CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::FastRemove(
          this: &this->m_arrRemoteVoice,
          elem: v6);
        CEngineVoiceSteam::AudioInitializationUpdate(this);
      }
    }
  }
  else if ( iController <= 3 )
  {
    this->m_bLocalVoice[iController] = false;
    CEngineVoiceSteam::AudioInitializationUpdate(this);
    v4 = Steam3Client();
    v4->m_pSteamUser->StopVoiceRecording(this: v4->m_pSteamUser);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100367F0
// Name: public: virtual void CEngineVoiceSteam::RemoveAllTalkers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::RemoveAllTalkers(CEngineVoiceSteam *this)
{
  *(_DWORD *)this->m_bLocalVoice = 0;
  this->m_arrRemoteVoice.m_Size = 0;
  CEngineVoiceSteam::AudioInitializationUpdate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036800
// Name: public: CEngineVoiceSteam::CEngineVoiceSteam(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceSteam *__thiscall CEngineVoiceSteam::CEngineVoiceSteam(CEngineVoiceSteam *this)
{
  this->__vftable = (CEngineVoiceSteam_vtbl *)&CEngineVoiceSteam::`vftable';
  this->m_arrRemoteVoice.m_Memory.m_pMemory = nullptr;
  this->m_arrRemoteVoice.m_Memory.m_nAllocationCount = 0;
  this->m_arrRemoteVoice.m_Memory.m_nGrowSize = 0;
  this->m_arrRemoteVoice.m_Size = 0;
  this->m_arrRemoteVoice.m_pElements = nullptr;
  this->m_resampleCelp2Pc.m_sampLeftover = 0;
  this->m_resampleCelp2Pc.m_iTargetTick = 0;
  this->m_resamplePc2Celp.m_sampLeftover = 0;
  this->m_resamplePc2Celp.m_iTargetTick = 0;
  *(_DWORD *)this->m_bLocalVoice = 0;
  memset(dst: this->m_pbVoiceData, value: 0, count: sizeof(this->m_pbVoiceData));
  *(_WORD *)&this->m_bVoiceForPs3 = 0;
  this->m_flLastTalkingTimestamp = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036870
// Name: public: virtual void CEngineVoiceSteam::AddPlayerToVoiceList(unsigned __int64,int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::AddPlayerToVoiceList(
        CEngineVoiceSteam *this,
        unsigned __int64 xPlayer,
        unsigned int iController,
        unsigned __int64 uiFlags)
{
  int m_nValue; // eax
  CSteam3Client *v6; // eax
  int v7; // eax
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // ecx
  int m_Size; // eax
  CSteam3Client *v10; // eax
  CEngineVoiceSteam::RemoteTalker_t rt; // [esp+8h] [ebp-18h] BYREF

  if ( xPlayer != 0 )
  {
    v7 = 0;
    if ( this->m_arrRemoteVoice.m_Size <= 0 )
      goto LABEL_12;
    m_pMemory = this->m_arrRemoteVoice.m_Memory.m_pMemory;
    while ( m_pMemory->m_xuid != xPlayer )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= this->m_arrRemoteVoice.m_Size )
        goto LABEL_12;
    }
    if ( v7 == -1 )
    {
LABEL_12:
      m_Size = this->m_arrRemoteVoice.m_Size;
      rt.m_xuid = xPlayer;
      rt.m_uiFlags = uiFlags;
      rt.m_flLastTalkTimestamp = 0.0;
      CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
        this: &this->m_arrRemoteVoice,
        elem: m_Size,
        src: &rt);
      this->m_bVoiceForPs3 = (uiFlags & 1) != 0;
      CEngineVoiceSteam::AudioInitializationUpdate(this);
      v10 = Steam3Client();
      v10->m_pSteamUser->StartVoiceRecording(this: v10->m_pSteamUser);
    }
  }
  else if ( iController <= 3 )
  {
    this->m_bLocalVoice[iController] = true;
    CEngineVoiceSteam::AudioInitializationUpdate(this);
    if ( snd_voice_echo.m_pParent != nullptr )
    {
      m_nValue = snd_voice_echo.m_pParent->m_Value.m_nValue;
      if ( m_nValue != 0 )
      {
        this->m_bVoiceForPs3 = m_nValue == 2;
        v6 = Steam3Client();
        v6->m_pSteamUser->StartVoiceRecording(this: v6->m_pSteamUser);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036960
// Name: public: virtual void CEngineVoiceSteam::PlayIncomingVoiceData(unsigned __int64,unsigned char const __near *,unsigned int,bool const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceSteam::PlayIncomingVoiceData(
        CEngineVoiceSteam *this,
        unsigned __int64 xuid,
        const unsigned __int8 *pbData,
        unsigned int dwDataSize,
        const bool *bAudiblePlayers)
{
  int v5; // edi
  int i; // esi
  IMatchSystem *v7; // eax
  int v8; // eax
  int (__thiscall ***v9)(_DWORD); // eax
  int v10; // edx
  IMatchSystem *v11; // eax
  IMatchVoice *v12; // eax
  int m_Size; // edx
  int v14; // eax
  CEngineVoiceSteam::RemoteTalker_t *j; // ecx
  CEngineVoiceSteam *v16; // ebx
  BOOL m_bVoiceForPs3; // eax
  CEngineVoiceSteam::RemoteTalker_t *m_pMemory; // eax
  int v19; // esi
  CSteam3Client *v20; // eax
  int Channel; // eax
  CEngineVoiceSteam::RemoteTalker_t *v22; // edi
  char pchData[22052]; // [esp+30h] [ebp-5644h] BYREF
  CEngineVoiceSteam::RemoteTalker_t src; // [esp+5654h] [ebp-20h] BYREF
  int nCount; // [esp+566Ch] [ebp-8h] BYREF
  CEngineVoiceSteam *v26; // [esp+5670h] [ebp-4h]

  v5 = 0;
  v26 = this;
  for ( i = 0; i == 0; ++i )
  {
    v7 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
    v8 = v7->GetPlayerManager(this: v7);
    v9 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 4))(a1: v8, a2: i);
    if ( v9 != nullptr && (**v9)(a1: v9) == (_DWORD)xuid && v10 == HIDWORD(xuid) )
    {
      if ( snd_voice_echo.m_pParent == nullptr || snd_voice_echo.m_pParent->m_Value.m_nValue == 0 )
        return;
      v16 = v26;
      if ( v26->m_arrRemoteVoice.m_Size == 0 )
      {
        m_bVoiceForPs3 = v26->m_bVoiceForPs3;
        src.m_xuid = 0;
        src.m_flLastTalkTimestamp = 0.0;
        src.m_uiFlags = m_bVoiceForPs3;
        CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
          this: &v26->m_arrRemoteVoice,
          elem: v26->m_arrRemoteVoice.m_Size,
          &src);
      }
      goto playvoice;
    }
  }
  v11 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v12 = v11->GetMatchVoice(this: v11);
  if ( ((int (__thiscall *)(IMatchVoice *, _DWORD, _DWORD))v12->CanPlaybackTalker)(a1: v12, a2: xuid, a3: HIDWORD(xuid)) != 0 )
  {
    m_Size = v26->m_arrRemoteVoice.m_Size;
    v14 = 0;
    if ( m_Size > 0 )
    {
      for ( j = v26->m_arrRemoteVoice.m_Memory.m_pMemory; j->m_xuid != xuid; ++j )
      {
        if ( ++v14 >= m_Size )
          return;
      }
      v5 = v14;
      if ( v14 != -1 )
      {
        v16 = v26;
playvoice:
        m_pMemory = v16->m_arrRemoteVoice.m_Memory.m_pMemory;
        nCount = 0;
        v19 = v5;
        if ( (m_pMemory[v5].m_uiFlags & 1) != 0
          || (v20 = Steam3Client(),
              v20->m_pSteamUser->DecompressVoice(
                this: v20->m_pSteamUser,
                a2: pbData,
                a3: dwDataSize,
                a4: pchData,
                a5: 22050u,
                a6: (unsigned int *)&nCount) == k_EVoiceResultOK) )
        {
          Channel = Voice_GetChannel(nEntity: v5);
          if ( Channel != -1 || (Channel = Voice_AssignChannel(nEntity: v5, bProximity: false, timePadding: 0.0)) != -1 )
          {
            Voice_AddIncomingData(nChannel: Channel, pchData, nCount, iSequenceNumber: 0, isCompressed: false);
            v22 = v16->m_arrRemoteVoice.m_Memory.m_pMemory;
            v22[v19].m_flLastTalkTimestamp = _Plat_FloatTime();
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036B10
// Name: class IEngineVoice __near * Audio_GetEngineVoiceSteam(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVoiceSteam *__cdecl Audio_GetEngineVoiceSteam()
{
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    CEngineVoiceSteam::CEngineVoiceSteam(this: &s_EngineVoiceSteam);
    atexit(func: Audio_GetEngineVoiceSteam_::_2_::_dynamic_atexit_destructor_for__s_EngineVoiceSteam__);
  }
  return &s_EngineVoiceSteam;
}

//------------------------------------------------------------------------------
// Address: 0x102AB0F0
// Name: public: virtual void CEngineVoiceStub::SetPlaybackPriority(unsigned __int64,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVoiceStub::SetPlaybackPriority(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

} // namespace engine_xlsp
