// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/voice_gamemgr.cpp
// Functions: 26
// ============================================================

#include "game\shared\voice_gamemgr.h"

//------------------------------------------------------------------------------
// Address: 0x100759D0
// Name: public: CBitVecT<class CVarBitVecBase<unsigned short>>::CBitVecT<class CVarBitVecBase<unsigned short>>(int)
// Source: json
//------------------------------------------------------------------------------
CBitVecT<CVarBitVecBase<unsigned short> > *__thiscall CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(
        CBitVecT<CVarBitVecBase<unsigned short> > *this,
        int numBits)
{
  int v3; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned int *m_pInt; // eax

  this->m_numBits = numBits;
  v3 = (numBits + 31) / 32;
  this->m_numInts = v3;
  this->m_pInt = nullptr;
  if ( (_WORD)v3 != 0 )
  {
    if ( (unsigned __int16)v3 == 1 )
      p_m_iBitStringStorage = &this->m_iBitStringStorage;
    else
      p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v3);
    this->m_pInt = p_m_iBitStringStorage;
  }
  m_pInt = this->m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: (int)m_pInt, value: nullptr, count: 4 * this->m_numInts);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025CEB0
// Name: class CVoiceGameMgr __near * GetVoiceGameMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVoiceGameMgr *__cdecl GetVoiceGameMgr()
{
  return &g_VoiceGameMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1025CEC0
// Name: public: bool CVoiceGameMgr::Init(class IVoiceGameMgrHelper __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceGameMgr::Init(CVoiceGameMgr *this, IVoiceGameMgrHelper *pHelper, int maxClients)
{
  int v3; // eax

  this->m_pHelper = pHelper;
  v3 = maxClients;
  if ( maxClients > 64 )
    v3 = 64;
  this->m_nMaxPlayers = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025CEE0
// Name: public: void CBitVecAccessor::operator=(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitVecAccessor::operator=(CBitVecAccessor *this, int val)
{
  int m_iBit; // ecx
  unsigned int *v4; // eax
  int v5; // edx

  m_iBit = this->m_iBit;
  v4 = &this->m_pDWords[m_iBit >> 5];
  v5 = 1 << (m_iBit & 0x1F);
  if ( val != 0 )
    *v4 |= v5;
  else
    *v4 &= ~v5;
}

//------------------------------------------------------------------------------
// Address: 0x1025CF10
// Name: VoiceServerDebug
// Source: json
//------------------------------------------------------------------------------
void VoiceServerDebug(char *pFmt, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(ap, pFmt);
  if ( voice_serverdebug.m_pParent != nullptr && voice_serverdebug.m_pParent->m_Value.m_nValue != 0 )
  {
    _vsnprintf(string, count: 0x1000u, format: pFmt, ap);
    _Msg(a1: "%s", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025CF90
// Name: public: bool CBitVecT<class CFixedBitVecBase<64>>::Compare(class CBitVecT<class CFixedBitVecBase<64>> const __near &,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitVecT<CFixedBitVecBase<64>>::Compare(
        CBitVecT<CFixedBitVecBase<64> > *this,
        const CBitVecT<CFixedBitVecBase<64> > *other,
        int nBits)
{
  int v3; // eax
  unsigned int v5; // edx

  v3 = nBits;
  if ( nBits == -1 )
  {
    v3 = 64;
  }
  else if ( nBits > 64 )
  {
    return false;
  }
  v5 = (8 * ((v3 + 7) / 8)) >> 3;
  if ( v5 < 4 )
  {
LABEL_7:
    if ( v5 == 0 )
      return true;
  }
  else
  {
    while ( this->m_Ints[0] == other->m_Ints[0] )
    {
      v5 -= 4;
      other = (const CBitVecT<CFixedBitVecBase<64> > *)((char *)other + 4);
      this = (CBitVecT<CFixedBitVecBase<64> > *)((char *)this + 4);
      if ( v5 < 4 )
        goto LABEL_7;
    }
  }
  return LOBYTE(this->m_Ints[0]) == LOBYTE(other->m_Ints[0])
      && (v5 <= 1
       || BYTE1(this->m_Ints[0]) == BYTE1(other->m_Ints[0])
       && (v5 <= 2 || BYTE2(this->m_Ints[0]) == BYTE2(other->m_Ints[0]) && v5 <= 3));
}

//------------------------------------------------------------------------------
// Address: 0x1025D050
// Name: public: void CVoiceGameMgr::ClientConnected(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceGameMgr::ClientConnected(CVoiceGameMgr *this, edict_t *pEdict)
{
  edict_t *v2; // eax
  _QWORD *v3; // ecx
  CBitVec<64> *v4; // eax

  v2 = pEdict;
  if ( pEdict != nullptr )
    v2 = (edict_t *)(pEdict - gpGlobals->pEdicts);
  g_bWantModEnable.m_Ints[((int)&v2[-1].m_pUnk + 3) >> 5] |= 1 << (((_BYTE)v2 - 1) & 0x1F);
  v3 = (_QWORD *)((char *)&unk_10660C10 + 8 * (_DWORD)v2);
  if ( v3 != nullptr )
    *v3 = 0;
  v4 = &g_SentGameRulesMasks[(int)v2 + 63];
  if ( v4 != nullptr )
    *v4 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025D0B0
// Name: public: bool CVoiceGameMgr::ClientCommand(class CBasePlayer __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceGameMgr::ClientCommand(CVoiceGameMgr *this, CBasePlayer *pPlayer, const CCommand *args)
{
  edict_t *m_pPev; // eax
  int v4; // esi
  const CCommand *v5; // edi
  const char *v6; // eax
  int m_nArgc; // eax
  int v8; // esi
  char **v9; // ebx
  char *v10; // eax
  const char *v12; // eax
  const char *v13; // eax
  int v14; // eax
  const char *v15; // edi
  int v16; // eax
  const char *v17; // eax
  CBitVecAccessor v18; // [esp+0h] [ebp-8h] BYREF
  int playerClientIndex; // [esp+10h] [ebp+8h]

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v4 = (int)&m_pPev[-1].m_pUnk + 3;
  playerClientIndex = (int)&m_pPev[-1].m_pUnk + 3;
  if ( (int)&m_pPev[-1].m_pUnk + 3 < 0 || v4 >= this->m_nMaxPlayers )
  {
    if ( args->m_nArgc > 0 )
      v17 = args->m_ppArgv[0];
    else
      v17 = locale;
    VoiceServerDebug(pFmt: "CVoiceGameMgr::ClientCommand: cmd %s from invalid client (%d)\n", v17, v4);
    return 1;
  }
  else
  {
    v5 = args;
    v6 = locale;
    if ( args->m_nArgc > 0 )
      v6 = args->m_ppArgv[0];
    if ( _V_stricmp(s1: v6, s2: "vban") != 0 || (m_nArgc = v5->m_nArgc, v5->m_nArgc < 2) )
    {
      v12 = locale;
      if ( v5->m_nArgc > 0 )
        v12 = v5->m_ppArgv[0];
      if ( _V_stricmp(s1: v12, s2: "VModEnable") != 0 || v5->m_nArgc < 2 )
      {
        return 0;
      }
      else
      {
        v13 = locale;
        if ( v5->m_nArgc > 1 )
          v13 = v5->m_ppArgv[1];
        v14 = atoi(nptr: v13);
        VoiceServerDebug(pFmt: "CVoiceGameMgr::ClientCommand: VModEnable (%d)\n", v14 != 0);
        if ( v5->m_nArgc > 1 )
          v15 = v5->m_ppArgv[1];
        else
          v15 = locale;
        v18.m_pDWords = (unsigned int *)&g_PlayerModEnable;
        v18.m_iBit = v4;
        v16 = atoi(nptr: v15);
        CBitVecAccessor::operator=(this: &v18, val: v16 != 0);
        g_bWantModEnable.m_Ints[v4 >> 5] &= ~(1 << (v4 & 0x1F));
        return 1;
      }
    }
    else
    {
      v8 = 1;
      if ( m_nArgc > 1 )
      {
        v9 = (char **)&v5->m_ppArgv[1];
        do
        {
          args = nullptr;
          if ( v8 < 0 || v8 >= m_nArgc )
            v10 = (char *)locale;
          else
            v10 = *v9;
          sscanf(string: v10, format: "%x", &args);
          if ( v8 > 2 )
          {
            VoiceServerDebug(pFmt: "CVoiceGameMgr::ClientCommand: invalid index (%d)\n", v8);
          }
          else
          {
            VoiceServerDebug(pFmt: "CVoiceGameMgr::ClientCommand: vban (0x%x) from %d\n", args, playerClientIndex);
            g_PlayerModEnable.m_Ints[2 * playerClientIndex + 1 + v8] = (unsigned int)args;
          }
          m_nArgc = v5->m_nArgc;
          ++v8;
          ++v9;
        }
        while ( v8 < v5->m_nArgc );
      }
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D2A0
// Name: public: bool CVoiceGameMgr::IsPlayerIgnoringPlayer(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVoiceGameMgr::IsPlayerIgnoringPlayer(CVoiceGameMgr *this, int iTalker, int iListener)
{
  return (g_PlayerModEnable.m_Ints[2 * iListener + ((iTalker - 1) >> 5)] & (1 << ((iTalker - 1) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025D2D0
// Name: private: void CVoiceGameMgr::UpdateMasks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceGameMgr::UpdateMasks(CVoiceGameMgr *this)
{
  int m_nValue; // eax
  int v2; // esi
  int v3; // edi
  CBasePlayer *v4; // ebx
  int v5; // ebx
  int v6; // esi
  int v7; // esi
  CBasePlayer *v8; // ebx
  int v9; // eax
  int v10; // esi
  unsigned int *v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  int *v15; // ebx
  int i; // esi
  int j; // eax
  int v18; // ebx
  int v19; // esi
  int v20; // edi
  CSingleUserRecipientFilter user; // [esp+0h] [ebp-54h] BYREF
  CBitVec<64> ProximityMask; // [esp+20h] [ebp-34h] BYREF
  CBitVec<64> gameRulesMask; // [esp+28h] [ebp-2Ch] BYREF
  int v24; // [esp+30h] [ebp-24h]
  int v25; // [esp+34h] [ebp-20h]
  int v26; // [esp+38h] [ebp-1Ch]
  CBaseEntity *pEnt; // [esp+3Ch] [ebp-18h]
  int v28; // [esp+40h] [ebp-14h]
  int v29; // [esp+44h] [ebp-10h]
  BOOL bCanHear; // [esp+48h] [ebp-Ch]
  CVoiceGameMgr *v31; // [esp+4Ch] [ebp-8h]
  bool bAllTalk; // [esp+52h] [ebp-2h]
  bool bProximity; // [esp+53h] [ebp-1h] BYREF

  this->m_UpdateInterval = 0.0;
  v31 = this;
  if ( sv_alltalk.m_pParent != nullptr )
    m_nValue = sv_alltalk.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bAllTalk = m_nValue != 0;
  v2 = 0;
  if ( this->m_nMaxPlayers > 0 )
  {
    v3 = 0;
    v28 = 0;
    do
    {
      v29 = v2 + 1;
      v4 = UTIL_PlayerByIndex(playerIndex: v2 + 1);
      pEnt = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        CRecipientFilter::CRecipientFilter(this: &user);
        user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
        CRecipientFilter::AddRecipient(this: &user, player: v4);
        v5 = 1 << (v2 & 0x1F);
        v6 = v2 >> 5;
        v24 = v6 * 4;
        v25 = v5;
        if ( (v5 & g_bWantModEnable.m_Ints[v6]) != 0 )
        {
          UserMessageBegin(filter: &user, messagename: "RequestState");
          MessageEnd();
          g_bWantModEnable.m_Ints[v6] &= ~v5;
        }
        gameRulesMask = 0;
        ProximityMask = 0;
        bProximity = false;
        if ( (v5 & g_PlayerModEnable.m_Ints[v6]) != 0 )
        {
          v7 = 0;
          if ( v31->m_nMaxPlayers > 0 )
          {
            do
            {
              v26 = v7 + 1;
              v8 = UTIL_PlayerByIndex(playerIndex: v7 + 1);
              if ( v8 != nullptr
                && v8->IsPlayer(this: v8)
                && (v31->m_pHelper->CanPlayerHearPlayer(
                      this: v31->m_pHelper,
                      a2: (CBasePlayer *)pEnt,
                      a3: v8,
                      a4: &bProximity)
                 || bAllTalk) )
              {
                v9 = 1 << (v7 & 0x1F);
                v10 = v7 >> 5;
                gameRulesMask.m_Ints[v10] |= v9;
                v11 = &ProximityMask.m_Ints[v10];
                if ( bProximity )
                  *v11 |= v9;
                else
                  *v11 &= ~v9;
              }
              v7 = v26;
            }
            while ( v26 < v31->m_nMaxPlayers );
          }
        }
        if ( !CBitVecT<CFixedBitVecBase<64>>::Compare(
                this: &gameRulesMask,
                other: (CBitVec<64> *)((char *)g_SentGameRulesMasks + v3),
                nBits: -1)
          || !CBitVecT<CFixedBitVecBase<64>>::Compare(
                this: (CBitVec<64> *)((char *)g_BanMasks + v3),
                other: (CBitVec<64> *)((char *)g_SentBanMasks + v3),
                nBits: -1) )
        {
          v12 = gameRulesMask.m_Ints[0];
          v13 = *(unsigned int *)((char *)g_BanMasks[0].m_Ints + v3);
          *(unsigned int *)((char *)&g_SentGameRulesMasks[0].m_Ints[1] + v3) = gameRulesMask.m_Ints[1];
          *(unsigned int *)((char *)g_SentGameRulesMasks[0].m_Ints + v3) = v12;
          v14 = *(int *)((char *)&dword_10660A1C + v3);
          v15 = (int *)((char *)g_BanMasks + v3);
          *(unsigned int *)((char *)g_SentBanMasks[0].m_Ints + v3) = v13;
          *(int *)((char *)&dword_10660E1C + v3) = v14;
          UserMessageBegin(filter: &user, messagename: "VoiceMask");
          for ( i = 0; i < 2; ++i )
          {
            MessageWriteLong(iValue: gameRulesMask.m_Ints[i]);
            MessageWriteLong(iValue: *v15++);
          }
          MessageWriteByte(iValue: (*(unsigned int *)((_BYTE *)g_PlayerModEnable.m_Ints + v24) & v25) != 0);
          MessageEnd();
        }
        for ( j = 0; j < v31->m_nMaxPlayers; v3 = v28 )
        {
          v18 = 1 << (j & 0x1F);
          v19 = j >> 5;
          if ( (v18 & gameRulesMask.m_Ints[v19]) == 0
            || (LOBYTE(bCanHear) = 1, (v18 & *(unsigned int *)((_BYTE *)g_BanMasks[0].m_Ints + v3 + v19 * 4)) != 0) )
          {
            LOBYTE(bCanHear) = 0;
          }
          v20 = j + 1;
          g_pVoiceServer->SetClientListening(this: g_pVoiceServer, a2: v29, a3: j + 1, a4: bCanHear);
          if ( bCanHear )
            ((void (__stdcall *)(int, int, bool))g_pVoiceServer->SetClientProximity)(
              a1: v29,
              a2: v20,
              a3: (v18 & ProximityMask.m_Ints[v19]) != 0);
          j = v20;
        }
        CRecipientFilter::~CRecipientFilter(this: &user);
      }
      v2 = v29;
      v3 += 8;
      v28 = v3;
    }
    while ( v29 < v31->m_nMaxPlayers );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D5A0
// Name: public: void CVoiceGameMgr::Update(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceGameMgr::Update(CVoiceGameMgr *this, long double frametime)
{
  long double v2; // xmm0_8

  v2 = frametime + this->m_UpdateInterval;
  this->m_UpdateInterval = v2;
  if ( v2 >= 0.3 )
    CVoiceGameMgr::UpdateMasks(this);
}

//------------------------------------------------------------------------------
// Address: 0x104083C0
// Name: _dynamic_initializer_for__voice_player_speaking_delay_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_player_speaking_delay_threshold__()
{
  ConVar::ConVar(
    this: &voice_player_speaking_delay_threshold,
    pName: "voice_player_speaking_delay_threshold",
    pDefaultValue: "0.5f",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__voice_player_speaking_delay_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CA80
// Name: _dynamic_initializer_for__voice_serverdebug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_serverdebug__()
{
  ConVar::ConVar(this: &voice_serverdebug, pName: "voice_serverdebug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_serverdebug__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D330
// Name: _dynamic_atexit_destructor_for__voice_player_speaking_delay_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_player_speaking_delay_threshold__()
{
  ConVar::~ConVar(this: &voice_player_speaking_delay_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFA0
// Name: _dynamic_atexit_destructor_for__voice_serverdebug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_serverdebug__()
{
  ConVar::~ConVar(this: &voice_serverdebug);
}

//------------------------------------------------------------------------------
// Address: 0x104083F0
// Name: _dynamic_initializer_for__g_CPlayerVoiceListener_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerVoiceListener_ScriptDesc__()
{
  InitCPlayerVoiceListenerScriptDesc();
  g_CPlayerVoiceListener_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CPlayerVoiceListener_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CPlayerVoiceListener_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x10408420
// Name: _dynamic_initializer_for__g_PlayerVoiceListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlayerVoiceListener__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_PlayerVoiceListener, name: nullptr);
  g_PlayerVoiceListener.__vftable = (CPlayerVoiceListener_vtbl *)&CPlayerVoiceListener::`vftable';
  memset(dst: (int)g_PlayerVoiceListener.m_flLastPlayerSpeechTime, value: nullptr, count: 0x40u);
  memset(dst: (int)g_PlayerVoiceListener.m_flPlayerSpeechDuration, value: nullptr, count: 0x40u);
  return atexit(func: dynamic_atexit_destructor_for__g_PlayerVoiceListener__);
}

//------------------------------------------------------------------------------
// Address: 0x10408460
// Name: _anonymous_namespace_::_dynamic_initializer_for____g_CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *anonymous_namespace_::_dynamic_initializer_for____g_CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_reg,
           fn: anonymous_namespace_::__CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_interface,
           pName: "PlayerInfoManager001");
}

//------------------------------------------------------------------------------
// Address: 0x10408480
// Name: _dynamic_initializer_for____g_CreateCPlayerInfoManagerIPlayerInfoManager_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCPlayerInfoManagerIPlayerInfoManager_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPlayerInfoManagerIPlayerInfoManager_reg,
           fn: _CreateCPlayerInfoManagerIPlayerInfoManager_interface,
           pName: "PlayerInfoManager002");
}

//------------------------------------------------------------------------------
// Address: 0x104084A0
// Name: _dynamic_initializer_for____g_CreateCPluginBotManagerIBotManager_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCPluginBotManagerIBotManager_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPluginBotManagerIBotManager_reg,
           fn: _CreateCPluginBotManagerIBotManager_interface,
           pName: "BotManager001");
}

//------------------------------------------------------------------------------
// Address: 0x1040CAB0
// Name: _dynamic_initializer_for__sv_alltalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_alltalk__()
{
  ConVar::ConVar(
    this: &sv_alltalk,
    pName: "sv_alltalk",
    pDefaultValue: "0",
    flags: 524544,
    pHelpString: "Players can hear all other players' voice communication, no team restrictions");
  return atexit(func: dynamic_atexit_destructor_for__sv_alltalk__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CAE0
// Name: _dynamic_initializer_for__g_VoiceGameMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VoiceGameMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VoiceGameMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D340
// Name: _dynamic_atexit_destructor_for__g_PlayerVoiceListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlayerVoiceListener__()
{
  IGameSystem::~IGameSystem(this: &g_PlayerVoiceListener);
}

//------------------------------------------------------------------------------
// Address: 0x1041D350
// Name: _dynamic_atexit_destructor_for__g_CPlayerVoiceListener_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CPlayerVoiceListener_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFB0
// Name: _dynamic_atexit_destructor_for__sv_alltalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_alltalk__()
{
  ConVar::~ConVar(this: &sv_alltalk);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFC0
// Name: _dynamic_atexit_destructor_for__g_VoiceGameMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VoiceGameMgr__()
{
  g_VoiceGameMgr.__vftable = (CVoiceGameMgr_vtbl *)&CVoiceGameMgr::`vftable';
}
