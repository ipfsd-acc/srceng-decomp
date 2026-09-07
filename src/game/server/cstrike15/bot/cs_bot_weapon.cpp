// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_weapon.cpp
// Functions: 83
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_weapon.h"

//------------------------------------------------------------------------------
// Address: 0x102A6CD0
// Name: public: virtual int CBot<class CCSPlayer>::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBot<CCSPlayer>::OnTakeDamage@<eax>(
        CBot<CCSPlayer> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const CTakeDamageInfo *info)
{
  return CCSPlayer::OnTakeDamage(this, a2, a3, inputInfo: info);
}

//------------------------------------------------------------------------------
// Address: 0x102A6CE0
// Name: public: virtual void CBot<class CCSPlayer>::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBot<CCSPlayer>::Event_Killed(
        CBot<CCSPlayer> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *info)
{
  CCSPlayer::Event_Killed(this, a2, a3, a4, info);
}

//------------------------------------------------------------------------------
// Address: 0x102A6CF0
// Name: public: virtual void CBot<class CCSPlayer>::Walk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::Walk(CBot<CCSPlayer> *this)
{
  this->m_isRunning = false;
}

//------------------------------------------------------------------------------
// Address: 0x102A6D00
// Name: public: bool CBot<class CCSPlayer>::IsEnemy(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsEnemy(CBot<CCSPlayer> *this, CBaseEntity *ent)
{
  int TeamNumber; // esi

  if ( !ent->IsPlayer(this: ent) || !ent->IsAlive(this: ent) )
    return false;
  TeamNumber = CBaseEntity::GetTeamNumber(this: ent);
  return TeamNumber != CBaseEntity::GetTeamNumber(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A6D50
// Name: public: int CBot<class CCSPlayer>::GetEnemiesRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBot<CCSPlayer>::GetEnemiesRemaining(CBot<CCSPlayer> *this)
{
  int result; // eax
  int v2; // edi
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi
  int TeamNumber; // ebx
  int count; // [esp+8h] [ebp-4h]

  result = 0;
  v2 = 1;
  count = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = v3;
      if ( v3 != nullptr && v3->IsPlayer(this: v3) && v4->IsAlive(this: v4) )
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
        if ( TeamNumber != CBaseEntity::GetTeamNumber(this) && v4->IsAlive(this: v4) )
          ++count;
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
    return count;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A6DE0
// Name: public: int CBot<class CCSPlayer>::GetFriendsRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBot<CCSPlayer>::GetFriendsRemaining(CBot<CCSPlayer> *this)
{
  int result; // eax
  int v2; // edi
  CBasePlayer *v3; // eax
  CBot<CCSPlayer> *v4; // esi
  int TeamNumber; // ebx
  int count; // [esp+8h] [ebp-4h]

  result = 0;
  v2 = 1;
  count = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = (CBot<CCSPlayer> *)v3;
      if ( v3 != nullptr
        && (!v3->IsPlayer(this: v3)
         || !v4->IsAlive(this: v4)
         || (TeamNumber = CBaseEntity::GetTeamNumber(this: v4)) == CBaseEntity::GetTeamNumber(this))
        && v4->IsAlive(this: v4)
        && v4 != this )
      {
        ++count;
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
    return count;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A85E0
// Name: public: bool CBot<class CCSPlayer>::IsLocalPlayerWatchingMe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsLocalPlayerWatchingMe(CBot<CCSPlayer> *this)
{
  CBasePlayer *ListenServerHost; // esi
  int m_nValue; // ecx
  edict_t *m_pPev; // eax

  if ( engine->IsDedicatedServer(this: engine) )
    return false;
  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost == nullptr )
    return false;
  if ( cv_bot_debug_target.m_pParent == nullptr || (m_nValue = cv_bot_debug_target.m_pParent->m_Value.m_nValue) <= 0 )
    return ((ListenServerHost->m_afPhysicsFlags.m_Value & 8) != 0 || !ListenServerHost->IsAlive(this: ListenServerHost))
        && this == ListenServerHost->GetObserverTarget(this: ListenServerHost)
        && (unsigned int)(ListenServerHost->GetObserverMode(this: ListenServerHost) - 4) <= 1;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    return m_pPev - gpGlobals->pEdicts == m_nValue;
  else
    return m_nValue == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A8710
// Name: public: virtual bool CBot<class CCSPlayer>::Jump(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::Jump(CBot<CCSPlayer> *this, bool mustJump)
{
  float v2; // xmm0_4
  bool result; // al

  v2 = gpGlobals->curtime - this->m_jumpTimestamp;
  result = true;
  if ( v2 <= 3.0 && (v2 < 0.89999998 || (this->m_fFlags.m_Value & 1) == 0)
    || this->m_isCrouching
    || !mustJump && v2 < 0.89999998
    || v2 < 0.30000001 )
  {
    return false;
  }
  this->m_buttonFlags |= 2u;
  this->m_jumpTimestamp = gpGlobals->curtime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A8790
// Name: public: void CBot<class CCSPlayer>::PrintIfWatched(char __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void CBot<CCSPlayer>::PrintIfWatched(CBot<CCSPlayer> *this, char *format, ...)
{
  int m_nValue; // ecx
  int v3; // eax
  const char *v4; // esi
  CBasePlayer *ListenServerHost; // eax
  const char *v6; // [esp-18h] [ebp-418h]
  char buffer[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+410h] [ebp+10h] BYREF

  va_start(ap, format);
  if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
    {
      if ( cv_bot_debug.m_pParent == nullptr )
        return;
      m_nValue = cv_bot_debug.m_pParent->m_Value.m_nValue;
      if ( m_nValue == 1 || m_nValue == 3 )
        goto LABEL_10;
    }
    if ( cv_bot_debug.m_pParent != nullptr )
    {
      v3 = cv_bot_debug.m_pParent->m_Value.m_nValue;
      if ( v3 == 2 || v3 == 4 )
      {
LABEL_10:
        v4 = this->GetPlayerName(this);
        vsprintf(string: buffer, format, ap);
        if ( v4 == nullptr )
          v4 = "(NULL netname)";
        v6 = UTIL_VarArgs(format: "%s: %s", v4, buffer);
        ListenServerHost = UTIL_GetListenServerHost();
        ClientPrint(
          player: ListenServerHost,
          msg_dest: 2u,
          msg_name: v6,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        CBotManager::AddDebugMessage(this: TheBots, msg: buffer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0610
// Name: public: virtual bool CBot<class CCSPlayer>::Initialize(class BotProfile const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBot<CCSPlayer>::Initialize(CBot<CCSPlayer> *this, const BotProfile *profile, int team)
{
  this->m_profile = profile;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B06C0
// Name: public: virtual void CBot<class CCSPlayer>::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::Spawn(CBot<CCSPlayer> *this)
{
  if ( this->m_profile == nullptr )
    this->Initialize(this, a2: g_botInitProfile, a3: g_botInitTeam);
  CCSPlayer::Spawn(this);
  CBaseEntity::AddFlag(this, flags: 768);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_jumpTimestamp = 0.0;
  this->m_forwardSpeed = 0.0;
  this->m_strafeSpeed = 0.0;
  *(_WORD *)&this->m_isRunning = 1;
  this->m_postureStackIndex = 0;
  *(_QWORD *)&this->m_verticalSpeed = 1120403456;
}

//------------------------------------------------------------------------------
// Address: 0x102B12D0
// Name: public: CBot<class CCSPlayer>::CBot<class CCSPlayer>(void)
// Source: json
//------------------------------------------------------------------------------
CBot<CCSPlayer> *__thiscall CBot<CCSPlayer>::CBot<CCSPlayer>(CBot<CCSPlayer> *this)
{
  unsigned int v2; // ecx

  CCSPlayer::CCSPlayer(this);
  this->CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBot<CCSPlayer>_vtbl *)&CBot<CCSPlayer>::`vftable'{for `CBasePlayer'};
  this->CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CBot<CCSPlayer>::`vftable'{for `CAI_ExpresserSink'};
  this->CCSPlayer::ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CBot<CCSPlayer>::`vftable';
  this->m_args.m_Memory.m_pMemory = nullptr;
  this->m_args.m_Memory.m_nAllocationCount = 0;
  this->m_args.m_Memory.m_nGrowSize = 0;
  this->m_args.m_Size = 0;
  this->m_args.m_pElements = nullptr;
  this->m_userCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_userCmd.command_number = 0;
  this->m_userCmd.tick_count = 0;
  this->m_userCmd.viewangles.x = 0.0;
  this->m_userCmd.viewangles.y = 0.0;
  this->m_userCmd.viewangles.z = 0.0;
  this->m_userCmd.forwardmove = 0.0;
  this->m_userCmd.sidemove = 0.0;
  this->m_userCmd.upmove = 0.0;
  this->m_userCmd.buttons = 0;
  this->m_userCmd.impulse = 0;
  this->m_userCmd.weaponselect = 0;
  this->m_userCmd.weaponsubtype = 0;
  this->m_userCmd.random_seed = 0;
  this->m_userCmd.hasbeenpredicted = false;
  *(_DWORD *)&this->m_userCmd.mousedx = 0;
  this->m_userCmd.headangles.x = 0.0;
  this->m_userCmd.headangles.y = 0.0;
  this->m_userCmd.headangles.z = 0.0;
  this->m_userCmd.headoffset.x = 0.0;
  this->m_userCmd.headoffset.y = 0.0;
  this->m_userCmd.headoffset.z = 0.0;
  this->m_profile = nullptr;
  v2 = `CBot<CCSPlayer>::CBot<CCSPlayer>'::`2'::nextID;
  if ( `CBot<CCSPlayer>::CBot<CCSPlayer>'::`2'::nextID == 0 )
  {
    v2 = 1;
    `CBot<CCSPlayer>::CBot<CCSPlayer>'::`2'::nextID = 1;
  }
  this->m_id = v2;
  ++`CBot<CCSPlayer>::CBot<CCSPlayer>'::`2'::nextID;
  this->m_postureStackIndex = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B13F0
// Name: public: virtual bool CBot<class CCSPlayer>::IsRunning(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsRunning(CBot<CCSPlayer> *this)
{
  return this->m_isRunning;
}

//------------------------------------------------------------------------------
// Address: 0x102B1400
// Name: public: virtual void CBot<class CCSPlayer>::Run(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::Run(CBot<CCSPlayer> *this)
{
  this->m_isRunning = true;
}

//------------------------------------------------------------------------------
// Address: 0x102B1410
// Name: public: virtual void CBot<class CCSPlayer>::Crouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::Crouch(CBot<CCSPlayer> *this)
{
  this->m_isCrouching = true;
}

//------------------------------------------------------------------------------
// Address: 0x102B1420
// Name: public: virtual void CBot<class CCSPlayer>::StandUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::StandUp(CBot<CCSPlayer> *this)
{
  this->m_isCrouching = false;
}

//------------------------------------------------------------------------------
// Address: 0x102B1430
// Name: public: virtual void CBot<class CCSPlayer>::MoveForward(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::MoveForward(CBot<CCSPlayer> *this)
{
  this->m_forwardSpeed = this->GetMoveSpeed(this);
  this->m_buttonFlags = this->m_buttonFlags & 0xFFFFFFE7 | 8;
}

//------------------------------------------------------------------------------
// Address: 0x102B1460
// Name: public: virtual void CBot<class CCSPlayer>::MoveBackward(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::MoveBackward(CBot<CCSPlayer> *this)
{
  double v2; // st7
  int m_buttonFlags; // eax

  v2 = ((double (__thiscall *)(CBot<CCSPlayer> *))this->GetMoveSpeed)(a1: this);
  m_buttonFlags = this->m_buttonFlags;
  this->m_forwardSpeed = -v2;
  this->m_buttonFlags = m_buttonFlags & 0xFFFFFFE7 | 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x102B1490
// Name: public: virtual void CBot<class CCSPlayer>::StrafeLeft(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::StrafeLeft(CBot<CCSPlayer> *this)
{
  double v2; // st7
  int m_buttonFlags; // eax

  v2 = ((double (__thiscall *)(CBot<CCSPlayer> *))this->GetMoveSpeed)(a1: this);
  m_buttonFlags = this->m_buttonFlags;
  this->m_strafeSpeed = -v2;
  this->m_buttonFlags = m_buttonFlags & 0xFFFFF9FF | 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x102B14C0
// Name: public: virtual void CBot<class CCSPlayer>::StrafeRight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::StrafeRight(CBot<CCSPlayer> *this)
{
  this->m_strafeSpeed = this->GetMoveSpeed(this);
  this->m_buttonFlags = this->m_buttonFlags & 0xFFFFF9FF | 0x400;
}

//------------------------------------------------------------------------------
// Address: 0x102B14F0
// Name: public: virtual void CBot<class CCSPlayer>::ClearMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::ClearMovement(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags &= 0xFFFFFE65;
  this->m_forwardSpeed = 0.0;
  this->m_strafeSpeed = 0.0;
  this->m_verticalSpeed = 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x102B1520
// Name: public: virtual void CBot<class CCSPlayer>::UseEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::UseEnvironment(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags |= 0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1530
// Name: public: virtual void CBot<class CCSPlayer>::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::PrimaryAttack(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1540
// Name: public: virtual void CBot<class CCSPlayer>::ClearPrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::ClearPrimaryAttack(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1550
// Name: public: virtual void CBot<class CCSPlayer>::TogglePrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::TogglePrimaryAttack(CBot<CCSPlayer> *this)
{
  int m_buttonFlags; // eax

  m_buttonFlags = this->m_buttonFlags;
  if ( (m_buttonFlags & 1) != 0 )
    this->m_buttonFlags = m_buttonFlags & 0xFFFFFFFE;
  else
    this->m_buttonFlags = m_buttonFlags | 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B1570
// Name: public: virtual void CBot<class CCSPlayer>::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::SecondaryAttack(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags |= 0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1580
// Name: public: virtual void CBot<class CCSPlayer>::Reload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::Reload(CBot<CCSPlayer> *this)
{
  this->m_buttonFlags |= 0x2000u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1590
// Name: public: virtual void CBot<class CCSPlayer>::BuildUserCmd(class CUserCmd __near &,class QAngle const __near &,float,float,float,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::BuildUserCmd(
        CBot<CCSPlayer> *this,
        CUserCmd *cmd,
        const QAngle *viewangles,
        float forwardmove,
        float sidemove,
        float upmove,
        int buttons,
        unsigned __int8 impulse)
{
  int tickcount; // ecx

  _V_memset(dest: (void *)cmd, fill: 0, count: 88);
  tickcount = gpGlobals->tickcount;
  cmd->forwardmove = forwardmove;
  cmd->impulse = impulse;
  cmd->sidemove = sidemove;
  cmd->command_number = tickcount;
  cmd->upmove = upmove;
  cmd->buttons = buttons;
  cmd->viewangles = *viewangles;
  cmd->random_seed = random->RandomInt(this: random, a2: 0, a3: 0x7FFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x102B1610
// Name: public: virtual void CBot<class CCSPlayer>::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::SetModel(CBot<CCSPlayer> *this, const char *modelName)
{
  CBasePlayer::SetModel(this, szModelName: modelName);
}

//------------------------------------------------------------------------------
// Address: 0x102B1620
// Name: public: virtual void CBot<class CCSPlayer>::UpdatePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBot<CCSPlayer>::UpdatePlayer(CBot<CCSPlayer> *this)
{
  CBot<CCSPlayer>_vtbl *v2; // edi
  int v3; // eax

  if ( this->m_isCrouching )
  {
    this->m_buttonFlags |= 4u;
  }
  else if ( !this->m_isRunning )
  {
    this->m_buttonFlags |= 0x20000u;
  }
  if ( (this->m_iEFlags & 0x100) != 0 )
  {
    this->m_buttonFlags = 0;
    this->m_forwardSpeed = 0.0;
    this->m_strafeSpeed = 0.0;
    this->m_verticalSpeed = 0.0;
  }
  v2 = this->CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v3 = ((int (__thiscall *)(CBot<CCSPlayer> *, _DWORD, _DWORD, _DWORD, int, _DWORD))this->EyeAngles)(
         a1: this,
         a2: LODWORD(this->m_forwardSpeed),
         a3: LODWORD(this->m_strafeSpeed),
         a4: LODWORD(this->m_verticalSpeed),
         a5: this->m_buttonFlags,
         a6: 0);
  ((void (__thiscall *)(CBot<CCSPlayer> *, CUserCmd *, int))v2->BuildUserCmd)(a1: this, a2: &this->m_userCmd, a3: v3);
  this->ProcessUsercmds(this, a2: &this->m_userCmd, a3: 1, a4: 1, a5: 0, a6: false);
}

//------------------------------------------------------------------------------
// Address: 0x102B16F0
// Name: public: virtual int CBot<class CCSPlayer>::Cmd_Argc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBot<CCSPlayer>::Cmd_Argc(CBot<CCSPlayer> *this)
{
  return this->m_args.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102B1700
// Name: public: virtual char __near * CBot<class CCSPlayer>::Cmd_Argv(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBot<CCSPlayer>::Cmd_Argv(CBot<CCSPlayer> *this, int argc)
{
  if ( argc < 0 || argc >= this->m_args.m_Size )
    return nullptr;
  else
    return this->m_args.m_Memory.m_pMemory[argc];
}

//------------------------------------------------------------------------------
// Address: 0x102B1730
// Name: protected: virtual float CBot<class CCSPlayer>::GetMoveSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBot<CCSPlayer>::GetMoveSpeed(CBot<CCSPlayer> *this)
{
  return this->m_flMaxspeed.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102B1FF0
// Name: public: virtual bool CBot<class CCSPlayer>::ClientCommand(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::ClientCommand(CBot<CCSPlayer> *this, const CCommand *args)
{
  CBot<CCSPlayer> *v2; // ebx
  int i; // esi
  CUtlMemory<vgui::TreeNode *,int> *p_m_args; // edi
  char *j; // ecx
  char k; // al
  const char *Token; // esi
  char *v8; // ebx
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  char **v13; // eax
  const char *cmd; // [esp+10h] [ebp-4h]

  v2 = this;
  for ( i = 0; i < v2->m_args.m_Size; ++i )
    free(pMem: v2->m_args.m_Memory.m_pMemory[i]);
  p_m_args = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_args;
  v2->m_args.m_Size = 0;
  if ( args->m_nArgc == 0 )
  {
    cmd = locale;
    goto LABEL_7;
  }
  for ( j = args->m_pArgSBuffer; ; j = (char *)cmd )
  {
    for ( k = *j; k != 0; k = *++j )
    {
      if ( k > 32 )
        break;
      if ( k == 10 )
        return CCSPlayer::ClientCommand(this: v2, args);
    }
    if ( *j == 10 )
      break;
    if ( *j == 0 )
      break;
    cmd = SharedParse(data: j);
    if ( cmd == nullptr )
      break;
    Token = SharedGetToken();
    v8 = (char *)operator new(nSize: strlen(Token) + 1);
    strcpy(v8, Token);
    m_pMemory = p_m_args[1].m_pMemory;
    m_nAllocationCount = p_m_args->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_args, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_args[1].m_pMemory;
    v11 = p_m_args->m_pMemory;
    v12 = (char *)p_m_args[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_args[1].m_nAllocationCount = (int)p_m_args->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
    v13 = (char **)&p_m_args->m_pMemory[(_DWORD)m_pMemory];
    if ( v13 != nullptr )
      *v13 = v8;
    v2 = this;
LABEL_7:
    ;
  }
  return CCSPlayer::ClientCommand(this: v2, args);
}

//------------------------------------------------------------------------------
// Address: 0x102B9CD0
// Name: public: class Vector const __near & CBot<class CCSPlayer>::GetViewVector(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBot<CCSPlayer>::GetViewVector(CBot<CCSPlayer> *this)
{
  Vector *v1; // esi
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  float *v3; // eax
  QAngle angles; // [esp+8h] [ebp-Ch] BYREF

  v1 = (Vector *)this;
  PunchAngle = CBasePlayer::GetPunchAngle(this);
  v3 = (float *)(*(int (__thiscall **)(Vector *))(LODWORD(v1->x) + 508))(a1: v1);
  angles.x = PunchAngle->m_Value.x + *v3;
  angles.y = PunchAngle->m_Value.y + v3[1];
  v1 = (Vector *)((char *)v1 + 7192);
  angles.z = PunchAngle->m_Value.z + v3[2];
  AngleVectors(&angles, forward: v1);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x102B9D40
// Name: public: bool CBot<class CCSPlayer>::IsLookingAtPosition(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsLookingAtPosition(CBot<CCSPlayer> *this, const Vector *pos, float angleTolerance)
{
  Vector *v4; // eax
  const QAngle *v5; // eax
  float z; // ecx
  QAngle idealAngles; // [esp+Ch] [ebp-28h] BYREF
  QAngle viewAngles; // [esp+18h] [ebp-1Ch] BYREF
  Vector to; // [esp+24h] [ebp-10h] BYREF
  float deltaPitch; // [esp+30h] [ebp-4h]
  float deltaYaw; // [esp+3Ch] [ebp+8h]

  v4 = this->EyePosition(this, result: &viewAngles);
  to.x = pos->x - v4->x;
  to.y = pos->y - v4->y;
  to.z = pos->z - v4->z;
  VectorAngles(forward: &to, angles: &idealAngles);
  v5 = this->EyeAngles(this);
  z = v5->z;
  *(_QWORD *)&viewAngles.x = *(_QWORD *)&v5->x;
  viewAngles.z = z;
  deltaYaw = AngleNormalize(angle: idealAngles.y - viewAngles.y);
  deltaPitch = AngleNormalize(angle: idealAngles.x - viewAngles.x);
  return angleTolerance > fabs(deltaYaw) && angleTolerance > COERCE_FLOAT(LODWORD(deltaPitch) & _mask__AbsFloat_);
}

//------------------------------------------------------------------------------
// Address: 0x102C1A00
// Name: public: bool CBot<class CCSPlayer>::IsActiveWeaponOutOfAmmo(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsActiveWeaponOutOfAmmo(CBot<CCSPlayer> *this)
{
  CWeaponCSBase *ActiveCSWeapon; // eax

  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
  return ActiveCSWeapon == nullptr || !ActiveCSWeapon->HasAnyAmmo(this: ActiveCSWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x102C1A20
// Name: public: bool CBot<class CCSPlayer>::IsActiveWeaponRecoilHigh(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBot<CCSPlayer>::IsActiveWeaponRecoilHigh(CBot<CCSPlayer> *this)
{
  return CBasePlayer::GetPunchAngle(this)->m_Value.x < -1.5;
}

//------------------------------------------------------------------------------
// Address: 0x102C1A40
// Name: public: bool CBot<class CCSPlayer>::IsUsingScope(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsUsingScope(CBot<CCSPlayer> *this)
{
  int FOV; // edi

  FOV = CBasePlayer::GetFOV(this);
  return FOV < CBasePlayer::GetDefaultFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C2140
// Name: public: bool CBot<class CCSPlayer>::IsPlayerLookingAtMe(class CBasePlayer __near *,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsPlayerLookingAtMe(CBot<CCSPlayer> *this, CBasePlayer *other, float cosTolerance)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  const QAngle *v5; // eax
  Vector otherForward; // [esp+8h] [ebp-24h] BYREF
  QAngle angles; // [esp+14h] [ebp-18h] BYREF
  Vector toOther; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (other->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: other, a2: (int)&savedregs);
  toOther.x = other->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  toOther.y = other->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  toOther.z = other->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &toOther);
  PunchAngle = CBasePlayer::GetPunchAngle(this: other);
  v5 = other->EyeAngles(this: other);
  angles.x = PunchAngle->m_Value.x + v5->x;
  angles.y = PunchAngle->m_Value.y + v5->y;
  angles.z = PunchAngle->m_Value.z + v5->z;
  AngleVectors(&angles, forward: &otherForward);
  return COERCE_FLOAT(LODWORD(cosTolerance) ^ _mask__NegFloat_) > (float)((float)((float)(otherForward.x * toOther.x)
                                                                                + (float)(otherForward.y * toOther.y))
                                                                        + (float)(otherForward.z * toOther.z));
}

//------------------------------------------------------------------------------
// Address: 0x102C81B0
// Name: private: void CCSBot::SetAimOffset(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::SetAimOffset(CCSBot *this@<ecx>, int a2@<ebp>, int a3@<edi>, float accuracy)
{
  float m_lookYawVel; // xmm1_4
  float m_lookPitchVel; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float *v9; // eax
  __int128 v10; // xmm0
  int FOV; // edi
  int DefaultFOV; // eax
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  __int128 v16; // [esp+1Ch] [ebp-2Ch] BYREF
  float v17; // [esp+34h] [ebp-14h]
  float v18; // [esp+38h] [ebp-10h]
  int v19; // [esp+3Ch] [ebp-Ch]
  void *v20; // [esp+40h] [ebp-8h]
  void *retaddr; // [esp+48h] [ebp+0h]

  v19 = a2;
  v20 = retaddr;
  if ( accuracy < 1.0 )
  {
    m_lookYawVel = this->m_lookYawVel;
    if ( m_lookYawVel >= 100.0
      || m_lookYawVel <= -100.0
      || (m_lookPitchVel = this->m_lookPitchVel) >= 100.0
      || m_lookPitchVel <= -100.0 )
    {
      this->m_aimSpreadTimestamp = gpGlobals->curtime;
    }
    v7 = 2.0;
    if ( (float)((float)(1.0 - accuracy) * 5.0) > 2.0 )
      v7 = (float)(1.0 - accuracy) * 5.0;
    v8 = (float)(gpGlobals->curtime - this->m_aimSpreadTimestamp) / v7;
    if ( v8 > 0.75 )
      v8 = 0.75;
    if ( accuracy <= v8 )
      accuracy = v8;
  }
  v9 = (float *)((int (__thiscall *)(CCSBot *, char *, int))this->EyePosition)(a1: this, a2: (char *)&v16 + 4, a3);
  v10 = 0;
  *(float *)&v10 = fsqrt(
                     (float)((float)((float)(this->m_lastEnemyPosition.y - v9[1])
                                   * (float)(this->m_lastEnemyPosition.y - v9[1]))
                           + (float)((float)(this->m_lastEnemyPosition.z - v9[2])
                                   * (float)(this->m_lastEnemyPosition.z - v9[2])))
                   + (float)((float)(this->m_lastEnemyPosition.x - *v9) * (float)(this->m_lastEnemyPosition.x - *v9)));
  v16 = v10;
  FOV = CBasePlayer::GetFOV(this);
  DefaultFOV = CBasePlayer::GetDefaultFOV(this);
  v18 = (float)((float)((float)(FOV / DefaultFOV) * 0.050000001) * *(float *)&v10) * (float)(1.0 - accuracy);
  LODWORD(v17) = LODWORD(v18) ^ _mask__NegFloat_;
  this->m_aimOffsetGoal.x = _RandomFloat(
                              this: (IUniformRandomStream *)DefaultFOV,
                              a2: COERCE_FLOAT(LODWORD(v18) ^ _mask__NegFloat_),
                              a3: v18);
  this->m_aimOffsetGoal.y = _RandomFloat(this: v13, a2: v17, a3: v18);
  this->m_aimOffsetGoal.z = _RandomFloat(this: v14, a2: v17, a3: v18);
  this->m_aimOffsetTimestamp = _RandomFloat(this: v15, a2: 0.25, a3: 1.0) + gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102C83C0
// Name: public: bool CCSBot::IsUsing(enum CSWeaponID)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsing(CCSBot *this, CSWeaponID weaponID)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr
      && ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == weaponID;
}

//------------------------------------------------------------------------------
// Address: 0x102C83F0
// Name: public: bool CCSBot::IsUsingSniperRifle(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingSniperRifle(CCSBot *this)
{
  CWeaponCSBase *ActiveWeapon; // eax

  ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr
      && CWeaponCSBase::GetCSWpnData(this: ActiveWeapon)->m_WeaponType == WEAPONTYPE_SNIPER_RIFLE;
}

//------------------------------------------------------------------------------
// Address: 0x102C8420
// Name: public: bool CCSBot::IsSniper(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsSniper(CCSBot *this)
{
  CWeaponCSBase *v1; // eax

  v1 = (CWeaponCSBase *)this->Weapon_GetSlot(this, a2: 0);
  return v1 != nullptr && CWeaponCSBase::GetCSWpnData(this: v1)->m_WeaponType == WEAPONTYPE_SNIPER_RIFLE;
}

//------------------------------------------------------------------------------
// Address: 0x102C8450
// Name: public: bool CCSBot::IsSniping(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsSniping(CCSBot *this)
{
  CCSBot::TaskType m_task; // eax

  m_task = this->m_task;
  return m_task == MOVE_TO_SNIPER_SPOT || m_task == SNIPING;
}

//------------------------------------------------------------------------------
// Address: 0x102C8470
// Name: public: bool CCSBot::IsUsingShotgun(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingShotgun(CCSBot *this)
{
  CWeaponCSBase *ActiveWeapon; // eax

  ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr && CWeaponCSBase::GetCSWpnData(this: ActiveWeapon)->m_WeaponType == WEAPONTYPE_SHOTGUN;
}

//------------------------------------------------------------------------------
// Address: 0x102C8490
// Name: public: bool CCSBot::IsUsingMachinegun(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingMachinegun(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr
      && ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 11;
}

//------------------------------------------------------------------------------
// Address: 0x102C84B0
// Name: public: bool CCSBot::IsPrimaryWeaponEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsPrimaryWeaponEmpty(CCSBot *this)
{
  CBaseCombatWeapon *v1; // eax

  v1 = this->Weapon_GetSlot(this, a2: 0);
  return v1 == nullptr || !v1->HasAnyAmmo(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102C84E0
// Name: public: bool CCSBot::IsPistolEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsPistolEmpty(CCSBot *this)
{
  CBaseCombatWeapon *v1; // eax

  v1 = this->Weapon_GetSlot(this, a2: 1);
  return v1 == nullptr || !v1->HasAnyAmmo(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102C8510
// Name: public: bool CCSBot::HasGrenade(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::HasGrenade(CCSBot *this)
{
  return this->Weapon_GetSlot(this, a2: 3) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C8530
// Name: public: bool CCSBot::IsUsingKnife(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingKnife(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr
      && ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 31;
}

//------------------------------------------------------------------------------
// Address: 0x102C8550
// Name: public: bool CCSBot::IsUsingPistol(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingPistol(CCSBot *this)
{
  CWeaponCSBase *ActiveWeapon; // eax

  ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr && CWeaponCSBase::IsPistol(this: ActiveWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x102C8570
// Name: public: bool CCSBot::IsUsingGrenade(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsUsingGrenade(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // esi

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr
      && (((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 32
       || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 34
       || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 33
       || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 35
       || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 36);
}

//------------------------------------------------------------------------------
// Address: 0x102C85E0
// Name: public: bool FOVClearOfFriends::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall FOVClearOfFriends::operator()(FOVClearOfFriends *this, CCSBot *player)
{
  Vector *v3; // esi
  Vector *v4; // eax
  bool result; // al
  _BYTE v6[12]; // [esp+8h] [ebp-30h] BYREF
  _BYTE v7[12]; // [esp+14h] [ebp-24h] BYREF
  Vector forward; // [esp+20h] [ebp-18h] BYREF
  Vector to; // [esp+2Ch] [ebp-Ch] BYREF

  result = true;
  if ( player != this->m_me
    && player->IsAlive(this: player)
    && CBaseEntity::InSameTeam(this: this->m_me, pEntity: player) )
  {
    v3 = this->m_me->EyePosition(this: this->m_me, result: v7);
    v4 = player->EyePosition(this: player, result: v6);
    to.x = v4->x - v3->x;
    to.y = v4->y - v3->y;
    to.z = v4->z - v3->z;
    VectorNormalize(vec: &to);
    CBasePlayer::EyeVectors(this: this->m_me, pForward: &forward, pRight: nullptr, pUp: nullptr);
    if ( (float)((float)((float)(to.x * forward.x) + (float)(forward.y * to.y)) + (float)(forward.z * to.z)) > 0.94999999
      && CCSBot::IsVisible(this: this->m_me, player, testFOV: false, visParts: nullptr) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C86E0
// Name: private: void CCSBot::UpdateAimOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::UpdateAimOffset(CCSBot *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  float v4; // xmm1_4
  float v5; // xmm2_4

  if ( gpGlobals->curtime >= this->m_aimOffsetTimestamp )
    CCSBot::SetAimOffset(this, a2, a3, accuracy: this->m_profile->m_skill);
  v4 = (float)((float)(this->m_aimOffsetGoal.y - this->m_aimOffset.y) * 0.1) + this->m_aimOffset.y;
  v5 = (float)((float)(this->m_aimOffsetGoal.z - this->m_aimOffset.z) * 0.1) + this->m_aimOffset.z;
  this->m_aimOffset.x = (float)((float)(this->m_aimOffsetGoal.x - this->m_aimOffset.x) * 0.1) + this->m_aimOffset.x;
  this->m_aimOffset.y = v4;
  this->m_aimOffset.z = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102C8790
// Name: public: void CCSBot::EquipKnife(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::EquipKnife(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( ActiveWeapon == nullptr
    || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) != 31 )
  {
    this->SelectItem(this, a2: "weapon_knife", a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C87D0
// Name: public: bool CCSBot::EquipGrenade(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::EquipGrenade(CCSBot *this, bool noSmoke)
{
  CWeaponCSBase *v3; // eax
  CBaseCombatWeapon *v5; // edi
  const char *pszValue; // edi

  v3 = (CWeaponCSBase *)this->Weapon_GetSlot(this, a2: 0);
  if ( (v3 == nullptr || CWeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType != WEAPONTYPE_SNIPER_RIFLE)
    && (!CCSGameRules::IsPlayingFreestyle(this: (CCSGameRules *)g_pGameRules)
     || CCSGameRules::GetFreestyleBotDifficulty(this: (CCSGameRules *)g_pGameRules) != 1) )
  {
    if ( CCSBot::IsUsingGrenade(this) )
      return 1;
    if ( this->Weapon_GetSlot(this, a2: 3) != nullptr )
    {
      v5 = this->Weapon_GetSlot(this, a2: 3);
      if ( noSmoke && ((int (__thiscall *)(CBaseCombatWeapon *))v5->__vftable[1].GetModelName)(a1: v5) == 34 )
        return 0;
      pszValue = v5->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      this->SelectItem(this, a2: pszValue, a3: 0);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C88A0
// Name: public: bool CCSBot::CanActiveWeaponFire(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::CanActiveWeaponFire(CCSBot *this)
{
  return CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
      && gpGlobals->curtime >= CBaseCombatCharacter::GetActiveWeapon(this)->m_flNextPrimaryAttack.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102C88E0
// Name: public: virtual bool CCSBot::BumpWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::BumpWeapon(CCSBot *this, CWeaponCSBase *pWeapon)
{
  CWeaponCSBase *v3; // eax
  CBaseCombatWeapon *v4; // edi
  CBaseCombatWeapon *v5; // eax
  CWeaponCSBase *v6; // eax
  int v7; // ebx
  const BotProfile *m_profile; // eax
  int v9; // ebx
  CSWeaponID v10; // edi
  CWeaponCSBase *myGun; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  CWeaponCSBase *droppedGun; // [esp+18h] [ebp+8h]

  v3 = (CWeaponCSBase *)__RTDynamicCast(
                          inptr: pWeapon,
                          VfDelta: 0,
                          SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                          TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                          isReference: 0);
  v4 = v3;
  droppedGun = v3;
  if ( v3 != nullptr && v3->GetSlot(this: v3) == 0 )
  {
    v5 = this->Weapon_GetSlot(this, a2: 0);
    v6 = (CWeaponCSBase *)__RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
    myGun = v6;
    if ( v6 != nullptr )
    {
      v7 = v6->GetCSWeaponID(this: v6);
      if ( ((int (__thiscall *)(CBaseCombatWeapon *))v4->__vftable[1].GetModelName)(a1: v4) != v7
        && BotProfile::HasPrimaryPreference(this: this->m_profile)
        && (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) >= 2.5 )
      {
        m_profile = this->m_profile;
        v9 = 0;
        if ( m_profile->m_weaponPreferenceCount > 0 )
        {
          for ( i = 16; ; i += 4 )
          {
            v10 = *(CSWeaponID *)((char *)&m_profile->m_name + i);
            if ( IsPrimaryWeapon(id: v10) )
            {
              if ( v10 == myGun->GetCSWeaponID(this: myGun) )
                goto LABEL_15;
              if ( v10 == droppedGun->GetCSWeaponID(this: droppedGun) )
                break;
            }
            m_profile = this->m_profile;
            if ( ++v9 >= m_profile->m_weaponPreferenceCount )
              return CCSPlayer::BumpWeapon(this, pBaseWeapon: droppedGun);
          }
          CCSPlayer::DropRifle(this, fromDeath: false);
LABEL_15:
          v4 = droppedGun;
        }
      }
    }
  }
  return CCSPlayer::BumpWeapon(this, pBaseWeapon: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102C8A30
// Name: public: bool CCSBot::IsFriendInLineOfFire(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsFriendInLineOfFire(CCSBot *this)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  const QAngle *v3; // eax
  float z; // ecx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v6; // eax
  Vector *(__thiscall *v7)(CBaseEntity *, Vector *); // edx
  const Vector *v8; // eax
  CBaseEntity *m_pEnt; // edi
  bool result; // al
  CGameTrace v11; // [esp+8h] [ebp-84h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-30h] BYREF
  Vector v13; // [esp+68h] [ebp-24h] BYREF
  float v14; // [esp+74h] [ebp-18h]
  float v15; // [esp+78h] [ebp-14h]
  float v16; // [esp+7Ch] [ebp-10h]
  Vector aimDir; // [esp+80h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  PunchAngle = CBasePlayer::GetPunchAngle(this);
  v3 = this->EyeAngles(this);
  aimDir.x = PunchAngle->m_Value.x + v3->x;
  aimDir.y = PunchAngle->m_Value.y + v3->y;
  aimDir.z = PunchAngle->m_Value.z + v3->z;
  AngleVectors(angles: (const QAngle *)&aimDir, forward: &this->m_viewForward);
  z = this->m_viewForward.z;
  EyePosition = this->EyePosition;
  *(_QWORD *)&aimDir.x = *(_QWORD *)&this->m_viewForward.x;
  v14 = aimDir.x * 10000.0;
  aimDir.z = z;
  v15 = aimDir.y * 10000.0;
  v16 = z * 10000.0;
  v6 = (float *)EyePosition(this, result: &v13);
  v7 = this->EyePosition;
  aimDir.x = *v6 + v14;
  aimDir.y = v6[1] + v15;
  aimDir.z = v6[2] + v16;
  v8 = (const Vector *)((int (__thiscall *)(CCSBot *))v7)(a1: this);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: v8,
    &vecAbsEnd,
    mask: (unsigned int)&aimDir,
    ignore: (const IHandleEntity *)0x201400B,
    collisionGroup: (int)this,
    ptr: nullptr);
  result = false;
  if ( CGameTrace::DidHitNonWorldEntity(this: &v11) )
  {
    m_pEnt = v11.m_pEnt;
    if ( v11.m_pEnt != nullptr
      && v11.m_pEnt->IsPlayer(this: v11.m_pEnt)
      && m_pEnt->IsAlive(this: m_pEnt)
      && CBaseEntity::InSameTeam(this: m_pEnt, pEntity: this) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8B90
// Name: public: float CCSBot::ComputeWeaponSightRange(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
double __usercall CCSBot::ComputeWeaponSightRange@<st0>(CCSBot *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  float *v6; // eax
  float z; // ecx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v9; // eax
  Vector *(__thiscall *v10)(CBaseEntity *, Vector *); // edx
  float v11; // xmm0_4
  const Vector *v12; // eax
  float *v13; // eax
  _DWORD v17[3]; // [esp-Ch] [ebp-A4h] BYREF
  CGameTrace v18; // [esp+0h] [ebp-98h]
  int v19; // [esp+54h] [ebp-44h]
  int v20; // [esp+58h] [ebp-40h]
  int v21; // [esp+5Ch] [ebp-3Ch]
  _DWORD v22[2]; // [esp+60h] [ebp-38h] BYREF
  const Vector *v23; // [esp+68h] [ebp-30h]
  QAngle *v24; // [esp+6Ch] [ebp-2Ch]
  int v25; // [esp+70h] [ebp-28h]
  int v26; // [esp+74h] [ebp-24h]
  float v27; // [esp+78h] [ebp-20h]
  float v28; // [esp+7Ch] [ebp-1Ch]
  QAngle v29; // [esp+80h] [ebp-18h] BYREF
  Vector aimDir; // [esp+8Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+98h] [ebp+0h]

  aimDir.x = a2;
  aimDir.y = retaddr;
  PunchAngle = CBasePlayer::GetPunchAngle(this);
  v6 = (float *)((int (__thiscall *)(CCSBot *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, int, int, int, _DWORD, _DWORD, const Vector *, QAngle *, int, int, _DWORD, _DWORD))this->EyeAngles)(
                  a1: this,
                  a2: a3,
                  a3: a4,
                  a4: v17[0],
                  a5: v17[1],
                  a6: v17[2],
                  a7: LODWORD(v18.startpos.x),
                  a8: LODWORD(v18.startpos.y),
                  a9: LODWORD(v18.startpos.z),
                  a10: LODWORD(v18.endpos.x),
                  a11: LODWORD(v18.endpos.y),
                  a12: LODWORD(v18.endpos.z),
                  a13: LODWORD(v18.plane.normal.x),
                  a14: LODWORD(v18.plane.normal.y),
                  a15: LODWORD(v18.plane.normal.z),
                  a16: LODWORD(v18.plane.dist),
                  a17: *(_DWORD *)&v18.plane.type,
                  a18: LODWORD(v18.fraction),
                  a19: v18.contents,
                  a20: *(_DWORD *)&v18.dispFlags,
                  a21: LODWORD(v18.fractionleftsolid),
                  a22: v18.surface.name,
                  a23: *(_DWORD *)&v18.surface.surfaceProps,
                  a24: v18.hitgroup,
                  a25: *(_DWORD *)&v18.physicsbone,
                  a26: v18.m_pEnt,
                  a27: v18.hitbox,
                  a28: v19,
                  a29: v20,
                  a30: v21,
                  a31: v22[0],
                  a32: v22[1],
                  a33: v23,
                  a34: v24,
                  a35: v25,
                  a36: v26,
                  a37: LODWORD(v27),
                  a38: LODWORD(v28));
  v29.x = PunchAngle->m_Value.x + *v6;
  v29.y = PunchAngle->m_Value.y + v6[1];
  v29.z = PunchAngle->m_Value.z + v6[2];
  AngleVectors(angles: &v29, forward: &this->m_viewForward);
  z = this->m_viewForward.z;
  EyePosition = this->EyePosition;
  *(_QWORD *)&v29.x = *(_QWORD *)&this->m_viewForward.x;
  *(float *)&v26 = v29.x * 10000.0;
  v29.z = z;
  v27 = v29.y * 10000.0;
  v9 = (float *)EyePosition(this, result: COERCE_VECTOR_(z * 10000.0));
  v10 = this->EyePosition;
  v29.x = *v9 + *(float *)&v26;
  v29.y = v9[1] + v27;
  v11 = v9[2] + v28;
  v28 = COERCE_FLOAT(v17);
  v27 = 0.0;
  v26 = (int)this;
  v25 = 33636363;
  v24 = &v29;
  v23 = (const Vector *)v22;
  v29.z = v11;
  v12 = (const Vector *)((int (__thiscall *)(CCSBot *))v10)(a1: this);
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&aimDir,
    a2: (int)this,
    vecAbsStart: v12,
    vecAbsEnd: v23,
    mask: (unsigned int)v24,
    ignore: (const IHandleEntity *)v25,
    collisionGroup: v26,
    ptr: (CGameTrace *)LODWORD(v27));
  v13 = (float *)((int (__thiscall *)(CCSBot *, _DWORD *, _DWORD))this->EyePosition)(
                   a1: this,
                   a2: v22,
                   a3: LODWORD(v28));
  return fsqrt(
           (float)((float)((float)(v13[1] - v18.startpos.y) * (float)(v13[1] - v18.startpos.y))
                 + (float)((float)(v13[2] - v18.startpos.z) * (float)(v13[2] - v18.startpos.z)))
         + (float)((float)(*v13 - v18.startpos.x) * (float)(*v13 - v18.startpos.x)));
}

//------------------------------------------------------------------------------
// Address: 0x102C8D10
// Name: public: bool CCSBot::DidPlayerJustFireWeapon(class CCSPlayer const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::DidPlayerJustFireWeapon(CCSBot *this, CCSPlayer *player)
{
  CWeaponCSBase *ActiveCSWeapon; // esi

  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: player);
  return ActiveCSWeapon != nullptr
      && !ActiveCSWeapon->IsSilenced(this: ActiveCSWeapon)
      && ActiveCSWeapon->m_flNextPrimaryAttack.m_Value > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102C8D60
// Name: public: bool CBot<class CCSPlayer>::IsPlayerFacingMe(class CBasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsPlayerFacingMe(CBot<CCSPlayer> *this, CBasePlayer *other)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  const QAngle *v4; // eax
  Vector otherForward; // [esp+8h] [ebp-24h] BYREF
  QAngle angles; // [esp+14h] [ebp-18h] BYREF
  Vector toOther; // [esp+20h] [ebp-Ch]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (other->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: other, a2: (int)&savedregs);
  toOther.x = other->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  toOther.y = other->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  toOther.z = other->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
  PunchAngle = CBasePlayer::GetPunchAngle(this: other);
  v4 = other->EyeAngles(this: other);
  angles.x = PunchAngle->m_Value.x + v4->x;
  angles.y = PunchAngle->m_Value.y + v4->y;
  angles.z = PunchAngle->m_Value.z + v4->z;
  AngleVectors(&angles, forward: &otherForward);
  return (float)((float)((float)(otherForward.x * toOther.x) + (float)(otherForward.y * toOther.y))
               + (float)(otherForward.z * toOther.z)) < 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C8E70
// Name: public: bool CNavArea::IsVisible(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsVisible(CNavArea *this, const Vector *eye, Vector *visSpot)
{
  float v4; // xmm0_4
  NavCornerType v6; // edi
  Vector *v7; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  CGameTrace v10; // [esp+8h] [ebp-88h] BYREF
  Vector v11; // [esp+5Ch] [ebp-34h] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+68h] [ebp-28h] BYREF
  Vector vecAbsEnd; // [esp+78h] [ebp-18h] BYREF
  Vector corner; // [esp+84h] [ebp-Ch] BYREF
  int savedregs; // [esp+90h] [ebp+0h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  corner.x = this->m_center.x;
  corner.y = this->m_center.y;
  v4 = this->m_center.z + 53.25;
  traceFilter.__vftable = (CTraceFilterNoNPCsOrPlayer_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  corner.z = v4;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)this,
    vecAbsStart: eye,
    vecAbsEnd: &corner,
    mask: 0x2006041u,
    pFilter: &traceFilter,
    ptr: &v10);
  if ( v10.fraction == 1.0 )
  {
    if ( visSpot != nullptr )
      *visSpot = this->m_center;
    return 1;
  }
  else
  {
    v6 = NORTH_WEST;
    while ( 1 )
    {
      v7 = CNavArea::GetCorner(this, result: &v11, corner: v6);
      x = v7->x;
      y = v7->y;
      corner.z = v7->z;
      corner.x = x;
      corner.y = y;
      vecAbsEnd.x = x;
      vecAbsEnd.y = y;
      vecAbsEnd.z = corner.z + 53.25;
      UTIL_TraceLine(
        a1: (int)&savedregs,
        a2: (int)this,
        vecAbsStart: eye,
        &vecAbsEnd,
        mask: 0x2006041u,
        pFilter: &traceFilter,
        ptr: &v10);
      if ( v10.fraction == 1.0 )
        break;
      if ( ++v6 >= NUM_CORNERS )
        return 0;
    }
    if ( visSpot != nullptr )
      *visSpot = corner;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8FC0
// Name: public: bool CCSBotManager::AllowFriendlyFireDamage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowFriendlyFireDamage(CCSGameRules *this)
{
  return friendlyfire.m_pParent != nullptr && friendlyfire.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C8FE0
// Name: public: float CBot<class CCSPlayer>::GetActiveWeaponAmmoRatio(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBot<CCSPlayer>::GetActiveWeaponAmmoRatio(CBot<CCSPlayer> *this)
{
  CWeaponCSBase *ActiveCSWeapon; // eax
  int m_Value; // ecx
  float v4; // [esp+0h] [ebp-8h]

  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
  if ( ActiveCSWeapon == nullptr )
    return 0.0;
  m_Value = ActiveCSWeapon->m_iClip1.m_Value;
  if ( m_Value < 0 )
    return 1.0;
  v4 = (float)m_Value;
  return v4 / (double)ActiveCSWeapon->GetMaxClip1(this: ActiveCSWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x102C9030
// Name: public: bool CBot<class CCSPlayer>::IsActiveWeaponClipEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBot<CCSPlayer>::IsActiveWeaponClipEmpty(CBot<CCSPlayer> *this)
{
  CWeaponCSBase *ActiveCSWeapon; // eax

  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
  return ActiveCSWeapon != nullptr && ActiveCSWeapon->m_iClip1.m_Value == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C90D0
// Name: public: void CCSBot::FireWeaponAtEnemy(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::FireWeaponAtEnemy(CCSBot *this@<ecx>, int a2@<edi>)
{
  unsigned int m_Index; // ecx
  CBasePlayer **v4; // eax
  CBasePlayer *v5; // edi
  CWeaponCSBase *ActiveWeapon; // eax
  float curtime; // xmm0_4
  float *v8; // eax
  CBaseCombatWeapon *v9; // eax
  double v10; // st7
  float v11; // xmm0_4
  const Vector *ViewVector; // eax
  float z; // ecx
  __m128 v14; // xmm0
  __m128i v15; // xmm0
  double v16; // xmm0_8
  IUniformRandomStream *v17; // ecx
  double v18; // st7
  CCSBot_vtbl *v19; // edx
  const BotProfile *m_profile; // ecx
  float v21; // xmm0_4
  float v22; // xmm0_4
  Vector aimDir; // [esp+14h] [ebp-20h] BYREF
  Vector toAimSpot; // [esp+20h] [ebp-14h] BYREF
  float fProjectedSpread; // [esp+2Ch] [ebp-8h]
  float rangeToEnemy; // [esp+30h] [ebp-4h]

  if ( cv_bot_dont_shoot.m_pParent == nullptr || cv_bot_dont_shoot.m_pParent->m_Value.m_nValue == 0 )
  {
    m_Index = this->m_enemy.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        v5 = *v4;
        if ( *v4 != nullptr )
        {
          GetCentroid(result: &aimDir, player: this);
          ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
          if ( ActiveWeapon == nullptr
            || CWeaponCSBase::GetCSWpnData(this: ActiveWeapon)->m_WeaponType != WEAPONTYPE_SNIPER_RIFLE
            || CCSBot::IsNotMoving(this, minDuration: 0.0)
            && !CCSBot::IsWaitingForZoom(this)
            && CCSBot::HasViewBeenSteady(this, duration: this->m_profile->m_reactionTime) )
          {
            curtime = gpGlobals->curtime;
            if ( curtime > this->m_fireWeaponTimestamp
              && (float)(curtime - this->m_currentEnemyAcquireTimestamp) >= this->m_profile->m_attackDelay
              && !CCSBot::IsSurprised(this)
              && (!CCSBot::IsRecognizedEnemyProtectedByShield(this)
               || !CBot<CCSPlayer>::IsPlayerFacingMe(this, other: v5))
              && !CCSPlayer::IsReloading(this)
              && !CBot<CCSPlayer>::IsActiveWeaponClipEmpty(this)
              && this->m_isEnemyVisible )
            {
              v8 = (float *)((int (__thiscall *)(CCSBot *, Vector *, int))this->EyePosition)(
                              a1: this,
                              a2: &aimDir,
                              a3: a2);
              toAimSpot.x = this->m_aimSpot.x - *v8;
              toAimSpot.y = this->m_aimSpot.y - v8[1];
              toAimSpot.z = this->m_aimSpot.z - v8[2];
              rangeToEnemy = VectorNormalize(vec: &toAimSpot);
              if ( !CCSBot::IsUsingSniperRifle(this)
                || ((v9 = CBaseCombatCharacter::GetActiveWeapon(this),
                     v10 = ((double (__thiscall *)(CBaseCombatWeapon *))v9->__vftable[1].ShouldCollide)(a1: v9),
                     fProjectedSpread = v10 * rangeToEnemy,
                     !CCSBot::IsUsing(this, weaponID: WEAPON_AWP))
                  ? (v11 = 25.0)
                  : (v11 = 50.0),
                    fProjectedSpread <= v11) )
              {
                ViewVector = CBot<CCSPlayer>::GetViewVector(this);
                z = ViewVector->z;
                *(_QWORD *)&aimDir.x = *(_QWORD *)&ViewVector->x;
                aimDir.z = z;
                fProjectedSpread = (float)((float)(aimDir.y * toAimSpot.y) + (float)(toAimSpot.x * aimDir.x))
                                 + (float)(z * toAimSpot.z);
                v14 = (__m128)(CCSBot::IsUsingSniperRifle(this) ? 0x41800000u : 0x42000000u);
                v14.m128_f32[0] = v14.m128_f32[0] / rangeToEnemy;
                v15 = (__m128i)_mm_cvtps_pd(v14);
                __libm_sse2_atan();
                *(float *)v15.m128i_i32 = *(double *)v15.m128i_i64;
                *(double *)v15.m128i_i64 = *(float *)v15.m128i_i32;
                __libm_sse2_cos(X: v15);
                *(float *)&v16 = v16;
                if ( fProjectedSpread > *(float *)&v16 )
                {
                  if ( !CCSBotManager::AllowFriendlyFireDamage(this: (CCSGameRules *)TheBots)
                    || !CCSBot::IsFriendInLineOfFire(this) )
                  {
                    if ( CCSBot::IsUsingKnife(this) )
                    {
                      if ( rangeToEnemy < 75.0 )
                      {
                        CCSBot::ForceRun(this, duration: 5.0);
                        if ( CBot<CCSPlayer>::IsPlayerFacingMe(this, other: v5) )
                        {
                          v18 = _RandomFloat(this: v17, a2: 0.0, a3: 100.0);
                          v19 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
                          if ( v18 >= 33.299999 )
                            ((void (__fastcall *)(CCSBot *))v19->PrimaryAttack)(a1: this);
                          else
                            ((void (__fastcall *)(CCSBot *))v19->SecondaryAttack)(a1: this);
                        }
                        else
                        {
                          ((void (__fastcall *)(CCSBot *))this->SecondaryAttack)(a1: this);
                        }
                      }
                    }
                    else
                    {
                      ((void (__fastcall *)(CCSBot *))this->PrimaryAttack)(a1: this);
                    }
                  }
                  if ( CCSBot::IsUsingPistol(this) )
                  {
                    m_profile = this->m_profile;
                    if ( m_profile->m_skill <= 0.75 || rangeToEnemy >= 360.0 )
                    {
                      v21 = 0.40000001;
                      goto LABEL_42;
                    }
                  }
                  else if ( this->m_profile->m_skill >= 0.5 && rangeToEnemy >= 400.0 && !CCSBot::IsUsingMachinegun(this) )
                  {
                    if ( !CCSBot::IsUsingSniperRifle(this) && rangeToEnemy > 800.0 )
                    {
                      this->m_fireWeaponTimestamp = _RandomFloat(
                                                      this: (IUniformRandomStream *)m_profile,
                                                      a2: 0.30000001,
                                                      a3: 0.69999999);
                      goto LABEL_51;
                    }
                    v21 = 0.25;
LABEL_42:
                    this->m_fireWeaponTimestamp = _RandomFloat(
                                                    this: (IUniformRandomStream *)m_profile,
                                                    a2: 0.15000001,
                                                    a3: v21);
LABEL_51:
                    v22 = this->m_fireWeaponTimestamp - g_BotUpdateInterval;
                    this->m_fireWeaponTimestamp = v22;
                    this->m_fireWeaponTimestamp = gpGlobals->curtime + v22;
                    return;
                  }
                  this->m_fireWeaponTimestamp = 0.0;
                  goto LABEL_51;
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9530
// Name: public: bool CCSBot::AdjustZoom(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::AdjustZoom(CCSBot *this, float range)
{
  char v3; // bl
  CWeaponCSBase *ActiveWeapon; // eax
  CCSBot *v5; // ecx
  CountdownTimer *p_m_zoomTimer; // edi
  double v7; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float rangea; // [esp+10h] [ebp+8h]

  v3 = 0;
  ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
  if ( ActiveWeapon == nullptr
    || CWeaponCSBase::GetCSWpnData(this: ActiveWeapon)->m_WeaponType != WEAPONTYPE_SNIPER_RIFLE )
  {
    v5 = this;
    goto LABEL_10;
  }
  v5 = this;
  if ( range <= 150.0 )
  {
LABEL_10:
    if ( (float)CBasePlayer::GetFOV(this: v5) > 60.0 )
      return v3;
    CBasePlayer::GetFOV(this);
    goto LABEL_12;
  }
  if ( range >= 1500.0 )
  {
    if ( CCSBot::GetZoomLevel(this) == HIGH_ZOOM )
      return v3;
  }
  else if ( CCSBot::GetZoomLevel(this) == LOW_ZOOM )
  {
    return v3;
  }
LABEL_12:
  v3 = 1;
  this->SecondaryAttack(this);
  p_m_zoomTimer = &this->m_zoomTimer;
  v7 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_zoomTimer) + 0.25;
  p_m_timestamp = &this->m_zoomTimer.m_timestamp;
  if ( p_m_zoomTimer->m_timestamp.m_Value != v7 )
  {
    p_m_zoomTimer->NetworkStateChanged(this: p_m_zoomTimer, a2: &p_m_zoomTimer->m_timestamp);
    rangea = v7;
    p_m_timestamp->m_Value = rangea;
  }
  if ( p_m_zoomTimer->m_duration.m_Value != 0.25 )
  {
    p_m_zoomTimer->NetworkStateChanged(this: p_m_zoomTimer, a2: &p_m_zoomTimer->m_duration);
    p_m_zoomTimer->m_duration.m_Value = 0.25;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102C9640
// Name: private: bool CCSBot::DoEquip(class CWeaponCSBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::DoEquip(CCSBot *this, CWeaponCSBase *weapon)
{
  const char *pszValue; // eax
  double v5; // st7
  double m_Value; // st6
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float weapona; // [esp+10h] [ebp+8h]

  if ( weapon == nullptr || !weapon->HasAnyAmmo(this: weapon) )
    return 0;
  pszValue = weapon->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  this->SelectItem(this, a2: pszValue, a3: 0);
  v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_equipTimer);
  m_Value = this->m_equipTimer.m_timestamp.m_Value;
  p_m_timestamp = &this->m_equipTimer.m_timestamp;
  if ( m_Value != v5 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value) + 4))(
      a1: p_m_timestamp - 1,
      a2: p_m_timestamp);
    weapona = v5;
    p_m_timestamp->m_Value = weapona;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C96D0
// Name: public: void CCSBot::EquipBestWeapon(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::EquipBestWeapon(CCSBot *this, bool mustEquip)
{
  CWeaponCSBase *v3; // eax
  CWeaponCSBase *v4; // esi
  CSWeaponType m_WeaponType; // eax
  CWeaponCSBase *v6; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  float mustEquipa; // [esp+10h] [ebp+8h]

  if ( mustEquip
    || this->m_equipTimer.m_timestamp.m_Value <= 0.0
    || (mustEquipa = IntervalTimer::Now(this: (CEffectsServer *)&this->m_equipTimer)
                   - this->m_equipTimer.m_timestamp.m_Value) >= 5.0 )
  {
    if ( (v3 = (CWeaponCSBase *)this->Weapon_GetSlot(this, a2: 0), v4 = v3, v3 == nullptr)
      || ((m_WeaponType = CWeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType, cv_bot_allow_shotguns.m_pParent == nullptr)
       || cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_SHOTGUN)
      && (cv_bot_allow_machine_guns.m_pParent == nullptr
       || cv_bot_allow_machine_guns.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_MACHINEGUN)
      && (cv_bot_allow_rifles.m_pParent == nullptr
       || cv_bot_allow_rifles.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_RIFLE)
      && (cv_bot_allow_shotguns.m_pParent == nullptr
       || cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_SHOTGUN)
      && (cv_bot_allow_snipers.m_pParent == nullptr
       || cv_bot_allow_snipers.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_SNIPER_RIFLE)
      && (cv_bot_allow_sub_machine_guns.m_pParent == nullptr
       || cv_bot_allow_sub_machine_guns.m_pParent->m_Value.m_nValue == 0
       || m_WeaponType != WEAPONTYPE_SUBMACHINEGUN)
      || CCSBot::DoEquip(this, weapon: v4) == 0 )
    {
      if ( cv_bot_allow_pistols.m_pParent == nullptr
        || cv_bot_allow_pistols.m_pParent->m_Value.m_nValue == 0
        || (v6 = (CWeaponCSBase *)this->Weapon_GetSlot(this, a2: 1), CCSBot::DoEquip(this, weapon: v6) == 0) )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
        if ( ActiveWeapon == nullptr
          || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) != 31 )
        {
          this->SelectItem(this, a2: "weapon_knife", a3: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9820
// Name: public: void CCSBot::EquipPistol(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::EquipPistol(CCSBot *this)
{
  CWeaponCSBase *ActiveWeapon; // eax
  CWeaponCSBase *v3; // eax
  float v4; // [esp+4h] [ebp-4h]

  if ( (this->m_equipTimer.m_timestamp.m_Value <= 0.0
     || (v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_equipTimer) - this->m_equipTimer.m_timestamp.m_Value) >= 5.0)
    && cv_bot_allow_pistols.m_pParent != nullptr
    && cv_bot_allow_pistols.m_pParent->m_Value.m_nValue != 0 )
  {
    ActiveWeapon = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
    if ( ActiveWeapon == nullptr || !CWeaponCSBase::IsPistol(this: ActiveWeapon) )
    {
      v3 = (CWeaponCSBase *)this->Weapon_GetSlot(this, a2: 1);
      CCSBot::DoEquip(this, weapon: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C98A0
// Name: public: void CCSBot::ThrowGrenade(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CCSBot::ThrowGrenade(CCSBot *this, const Vector *target)
{
  IUniformRandomStream *v3; // ecx
  float duration; // [esp+Ch] [ebp-Ch]

  if ( CCSBot::IsUsingGrenade(this) && this->m_grenadeTossState == NOT_THROWING && !CBasePlayer::IsOnLadder(this) )
  {
    this->m_grenadeTossState = START_THROW;
    CountdownTimer::Start(this: &this->m_tossGrenadeTimer, duration: 2.0);
    CCSBot::SetLookAt(
      this,
      desc: "GrenadeThrow",
      pos: target,
      pri: PRIORITY_UNINTERRUPTABLE,
      duration: 4.0,
      clearIfClose: false,
      angleTolerance: 3.0,
      attack: false);
    duration = _RandomFloat(this: v3, a2: 2.0, a3: 4.0);
    CCSBot::Wait(this, duration);
    if ( cv_bot_debug.m_pParent != nullptr
      && cv_bot_debug.m_pParent->m_Value.m_nValue != 0
      && CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
    {
      NDebugOverlay::Cross3D(position: target, size: 25.0, r: 255, g: 125, b: 0, noDepthTest: 1, flDuration: 3.0);
    }
    CBot<CCSPlayer>::PrintIfWatched(this, format: "%3.2f: Grenade: START_THROW\n", gpGlobals->curtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C99D0
// Name: private: void CCSBot::LookForGrenadeTargets(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CCSBot::LookForGrenadeTargets(CCSBot *this@<ecx>, float a2@<ebp>)
{
  CNavArea *m_initialEncounterArea; // edi
  int v4; // eax
  float v5; // xmm0_4
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  Vector *v9; // eax
  __int128 v10; // xmm0
  Vector *(__thiscall *v11)(CBaseEntity *, Vector *); // edx
  const CViewVectors *v12; // eax
  CGameRules_vtbl *v13; // edx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float x; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  bool v21; // cc
  int v22; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace result; // [esp+0h] [ebp-128h] BYREF
  Ray_t ray; // [esp+58h] [ebp-D0h] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+ACh] [ebp-7Ch] BYREF
  Vector v26; // [esp+BCh] [ebp-6Ch] BYREF
  Vector maxs; // [esp+C8h] [ebp-60h] BYREF
  _BYTE mins[24]; // [esp+D4h] [ebp-54h] OVERLAPPED BYREF
  Vector target; // [esp+ECh] [ebp-3Ch]
  float v30; // [esp+F8h] [ebp-30h]
  float v31; // [esp+FCh] [ebp-2Ch]
  float heightInc; // [esp+100h] [ebp-28h]
  float tossHeight; // [esp+104h] [ebp-24h]
  float low; // [esp+108h] [ebp-20h] BYREF
  float h; // [esp+10Ch] [ebp-1Ch]
  float safeSpace; // [esp+110h] [ebp-18h]
  Vector tossTarget; // [esp+114h] [ebp-14h]
  float lastH; // [esp+120h] [ebp-8h]
  float retaddr; // [esp+128h] [ebp+0h]

  tossTarget.z = a2;
  lastH = retaddr;
  if ( CCSBot::IsUsingGrenade(this) && this->m_grenadeTossState == NOT_THROWING )
  {
    m_initialEncounterArea = (CNavArea *)this->m_initialEncounterArea;
    if ( m_initialEncounterArea != nullptr )
    {
      v4 = (3 - (CBaseEntity::GetTeamNumber(this) != 2)) % 2;
      v5 = m_initialEncounterArea->m_earliestOccupyTime[v4];
      LODWORD(tossTarget.x) = &m_initialEncounterArea->m_earliestOccupyTime[v4];
      if ( v5 > gpGlobals->curtime )
      {
        CCSBot::EquipBestWeapon(this, mustEquip: true);
        return;
      }
      EyePosition = this->EyePosition;
      low = 0.0;
      h = 0.0;
      safeSpace = 0.0;
      v7 = EyePosition(this, result: (Vector *)&traceFilter.m_pPassEnt);
      if ( CNavArea::IsVisible(this: m_initialEncounterArea, eye: v7, visSpot: (Vector *)&low) != 0 )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
        if ( ActiveWeapon != nullptr
          && ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 34 )
        {
          CCSBot::ThrowGrenade(this, target: (const Vector *)&low);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "Throwing smoke grenade!");
          this->m_initialEncounterArea = nullptr;
          return;
        }
        if ( (float)(*(float *)LODWORD(tossTarget.x)
                   - (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696])) <= 1.5 )
        {
          v9 = this->EyePosition(this, result: &mins[12]);
          v10 = 0;
          *(float *)&v10 = fsqrt(
                             (float)((float)((float)(h - v9->y) * (float)(h - v9->y))
                                   + (float)((float)(safeSpace - v9->z) * (float)(safeSpace - v9->z)))
                           + (float)((float)(low - v9->x) * (float)(low - v9->x)));
          *(_OWORD *)&mins[8] = v10;
          v30 = *(float *)&v10 * 0.2;
          CTraceFilterSimple::CTraceFilterSimple(
            this: (CTraceFilterSimple *)(&ray.m_IsSwept + 3),
            passedict: this,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          v11 = this->EyePosition;
          target.z = v30 * 0.1;
          *(_DWORD *)(&ray.m_IsSwept + 3) = &CTraceFilterNoNPCsOrPlayer::`vftable';
          tossHeight = v30 * 0.5;
          v11(this, result: (Vector *)&traceFilter.m_pPassEnt);
          v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
          *(_QWORD *)&v10 = *(_QWORD *)&v12->m_vHullMin.x;
          v13 = g_pGameRules->__vftable;
          maxs.z = v12->m_vHullMin.z;
          GetViewVectors = v13->GetViewVectors;
          *(_QWORD *)&maxs.x = v10;
          *(_QWORD *)&v10 = *(_QWORD *)&GetViewVectors(this: g_pGameRules)->m_vHullMax.x;
          v26.z = target.z;
          *(_QWORD *)&v26.x = v10;
          *(float *)&mins[4] = tossHeight + v30;
          v15 = 0.0;
          maxs.z = 0.0;
          v31 = 0.0;
          HIBYTE(tossTarget.y) = 0;
          tossTarget.x = 0.0;
          heightInc = 0.0;
          *(float *)mins = v30 * 3.0;
          if ( (float)(v30 * 3.0) > 0.0 )
          {
            while ( 1 )
            {
              *(float *)&mins[12] = low;
              *(float *)&mins[16] = h;
              *(float *)&mins[20] = safeSpace + v15;
              ray.m_Extents.y = 0.0;
              Ray_t::Init(
                this: (Ray_t *)&result.m_pEnt,
                start: (const Vector *)&traceFilter.m_pPassEnt,
                end: (const Vector *)&mins[12],
                mins: &maxs,
                maxs: &v26);
              enginetrace->TraceRay(
                this: enginetrace,
                a2: (const Ray_t *)&result.m_pEnt,
                a3: 33579145u,
                a4: (ITraceFilter *)(&ray.m_IsSwept + 3),
                a5: (CGameTrace *)&v22);
              if ( result.plane.normal.z != 1.0 )
                break;
              if ( HIBYTE(tossTarget.y) != 0 )
                goto LABEL_16;
              v16 = heightInc;
              v17 = heightInc;
              v31 = heightInc;
              HIBYTE(tossTarget.y) = 1;
LABEL_17:
              tossTarget.x = v16;
              v15 = v16 + target.z;
              heightInc = v16 + target.z;
              if ( *(float *)mins <= (float)(v16 + target.z) )
              {
                x = *(float *)&mins[4];
                goto LABEL_20;
              }
            }
            if ( HIBYTE(tossTarget.y) != 0 )
            {
              x = tossTarget.x;
              v17 = v31;
LABEL_20:
              if ( HIBYTE(tossTarget.y) != 0 )
              {
                v19 = v30;
                if ( v17 <= v30 )
                {
                  v20 = x - tossHeight;
                  if ( v30 > (float)(x - tossHeight) )
                  {
                    v21 = v17 <= v20;
                    goto LABEL_25;
                  }
                }
                else
                {
                  v20 = v17 + tossHeight;
                  v21 = (float)(v17 + tossHeight) <= x;
LABEL_25:
                  if ( v21 )
                    v19 = v20;
                  else
                    v19 = (float)(x + v17) * 0.5;
                }
                *(float *)&mins[12] = low;
                *(float *)&mins[16] = h;
                *(float *)&mins[20] = safeSpace + v19;
                CCSBot::ThrowGrenade(this, target: (const Vector *)&mins[12]);
                this->m_initialEncounterArea = nullptr;
              }
              return;
            }
LABEL_16:
            v17 = v31;
            v16 = heightInc;
            goto LABEL_17;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9DB0
// Name: private: void CCSBot::UpdateGrenadeThrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateGrenadeThrow(CCSBot *this)
{
  FOVClearOfFriends fovClear; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_grenadeTossState == START_THROW )
  {
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_tossGrenadeTimer) <= this->m_tossGrenadeTimer.m_timestamp.m_Value )
    {
      if ( this->m_lookAtSpotState == LOOK_AT_SPOT )
      {
        fovClear.m_me = this;
        if ( ForEachPlayer<FOVClearOfFriends>(func: &fovClear) )
        {
          this->m_grenadeTossState = FINISH_THROW;
          CountdownTimer::Start(this: &this->m_tossGrenadeTimer, duration: 1.0);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "%3.2f: Grenade: FINISH_THROW\n", gpGlobals->curtime);
        }
        else
        {
          CBot<CCSPlayer>::PrintIfWatched(this, format: "%3.2f: Grenade: Friend is in the way...\n", gpGlobals->curtime);
        }
      }
      this->PrimaryAttack(this);
    }
    else
    {
      CCSBot::EquipBestWeapon(this, mustEquip: true);
      this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
      this->m_lookAtDesc = nullptr;
      this->m_grenadeTossState = NOT_THROWING;
      CBot<CCSPlayer>::PrintIfWatched(this, format: "%3.2f: Grenade: THROW FAILED\n", gpGlobals->curtime);
    }
  }
  else if ( this->m_grenadeTossState == FINISH_THROW )
  {
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_tossGrenadeTimer) > this->m_tossGrenadeTimer.m_timestamp.m_Value )
    {
      this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
      this->m_lookAtDesc = nullptr;
      this->m_grenadeTossState = NOT_THROWING;
      CBot<CCSPlayer>::PrintIfWatched(this, format: "%3.2f: Grenade: THROW COMPLETE\n", gpGlobals->curtime);
    }
  }
  else if ( CCSBot::IsUsingGrenade(this) )
  {
    this->PrimaryAttack(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9F40
// Name: public: bool GrenadeResponse::operator()(class ActiveGrenade __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GrenadeResponse::operator()(GrenadeResponse *this, ActiveGrenade *ag)
{
  const Vector *Position; // eax
  CBaseGrenade *v6; // ebx
  IUniformRandomStream *v7; // ecx
  float v8; // xmm0_4
  CCSBot *v9; // ecx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v11; // eax
  float v12; // xmm0_4
  CCSBot *v13; // eax
  CCSBot *m_me; // ebx
  const Vector *v15; // eax
  double v16; // st7
  CBaseGrenade *m_entity; // [esp+8h] [ebp-64h]
  int v18; // [esp+14h] [ebp-58h] BYREF
  Vector away; // [esp+20h] [ebp-4Ch] BYREF
  Vector forward; // [esp+2Ch] [ebp-40h] BYREF
  QAngle eyeAngles; // [esp+38h] [ebp-34h] BYREF
  Vector velDir; // [esp+44h] [ebp-28h] BYREF
  float v23; // [esp+50h] [ebp-1Ch]
  float v24; // [esp+54h] [ebp-18h]
  float v25; // [esp+58h] [ebp-14h]
  Vector to; // [esp+5Ch] [ebp-10h] BYREF
  float range; // [esp+68h] [ebp-4h]
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  float yaw; // [esp+74h] [ebp+8h]
  float yawa; // [esp+74h] [ebp+8h]

  m_entity = ag->m_entity;
  Position = ActiveGrenade::GetPosition(this: ag);
  if ( !CCSBot::IsVisible(this: this->m_me, pos: Position, testFOV: true, ignore: m_entity) || ag->m_isSmoke )
    return 1;
  v6 = ag->m_entity;
  if ( (ag->m_entity->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: ag->m_entity, a2: (int)&savedregs);
  velDir = v6->m_vecAbsVelocity;
  yaw = VectorNormalize(vec: &velDir);
  if ( !ag->m_isFlashbang || (float)(ag->m_entity->m_flDetonateTime - gpGlobals->curtime) >= 0.5 )
  {
    m_me = this->m_me;
    if ( (this->m_me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_me, a2: (int)&savedregs);
    v15 = ActiveGrenade::GetPosition(this: ag);
    to.x = v15->x - m_me->m_vecAbsOrigin.x;
    to.y = v15->y - m_me->m_vecAbsOrigin.y;
    to.z = v15->z - m_me->m_vecAbsOrigin.z;
    v16 = VectorNormalize(vec: &to);
    range = v16;
    if ( v16 > 750.0 )
      return 1;
    if ( yaw <= 50.0 )
    {
      if ( range < 300.0 )
        CBot<CCSPlayer>::PrintIfWatched(this: this->m_me, format: "Retreating from a grenade that landed near me!\n");
    }
    else
    {
      if ( (float)((float)((float)(velDir.y * to.y) + (float)(to.x * velDir.x)) + (float)(velDir.z * to.z)) >= -0.5 )
        return 1;
      CBot<CCSPlayer>::PrintIfWatched(this: this->m_me, format: "Retreating from a grenade thrown towards me!\n");
    }
    CCSBot::TryToRetreat(this: this->m_me, maxRange: 300.0, duration: 1.0);
    return 0;
  }
  eyeAngles = *this->m_me->EyeAngles(this: this->m_me);
  yawa = _RandomFloat(this: (IUniformRandomStream *)LODWORD(eyeAngles.z), a2: 100.0, a3: 135.0);
  v8 = yawa;
  if ( _RandomFloat(this: v7, a2: -1.0, a3: 1.0) < 0.0 )
    LODWORD(v8) = LODWORD(yawa) ^ _mask__NegFloat_;
  eyeAngles.y = v8 + eyeAngles.y;
  AngleVectors(angles: &eyeAngles, &forward);
  v9 = this->m_me;
  EyePosition = this->m_me->EyePosition;
  v23 = forward.x * 1000.0;
  v24 = forward.y * 1000.0;
  v18 = (int)&v18;
  v25 = forward.z * 1000.0;
  v11 = (float *)((int (__thiscall *)(CCSBot *))EyePosition)(a1: v9);
  away.x = *v11 - v23;
  away.y = v11[1] - v24;
  v12 = v11[2] - v25;
  v13 = this->m_me;
  away.z = v12;
  v13->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
  v13->m_lookAtDesc = nullptr;
  CCSBot::SetLookAt(
    this: this->m_me,
    desc: "Avoid Flashbang",
    pos: &away,
    pri: PRIORITY_UNINTERRUPTABLE,
    duration: 2.0,
    clearIfClose: false,
    angleTolerance: 5.0,
    attack: false);
  this->m_me->m_isAimingAtEnemy = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CA250
// Name: private: void CCSBot::ReloadCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ReloadCheck(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  CWeaponCSBase *ActiveCSWeapon; // eax
  CWeaponCSBase *v4; // eax
  CBaseCombatWeapon *v5; // eax
  IUniformRandomStream *v6; // ecx
  const Vector *NearbyRetreatSpot; // edi
  float m_skill; // [esp+Ch] [ebp-4h]

  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) != 0 && !CCSBot::IsDefusingBomb(this) )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( ActiveWeapon == nullptr || !ActiveWeapon->m_bInReload.m_Value )
    {
      ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
      if ( ActiveCSWeapon == nullptr || ActiveCSWeapon->m_iClip1.m_Value != 0 )
      {
        if ( (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) <= 3.0
          || CBot<CCSPlayer>::GetActiveWeaponAmmoRatio(this) > 0.60000002
          || this->m_profile->m_skill > 0.5 && CCSBot::IsAttacking(this) )
        {
          return;
        }
      }
      else if ( this->m_profile->m_skill > 0.5 && CCSBot::IsAttacking(this) )
      {
        v4 = (CWeaponCSBase *)CBaseCombatCharacter::GetActiveWeapon(this);
        if ( !CWeaponCSBase::IsPistol(this: v4) && !CCSBot::IsPistolEmpty(this) )
        {
          CCSBot::EquipPistol(this);
          return;
        }
      }
      v5 = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( v5 == nullptr
        || ((int (__thiscall *)(CBaseCombatWeapon *))v5->__vftable[1].GetModelName)(a1: v5) != 7
        || CBot<CCSPlayer>::IsActiveWeaponClipEmpty(this) )
      {
        this->Reload(this);
        if ( CCSBot::GetNearbyEnemyCount(this) != 0 )
        {
          m_skill = this->m_profile->m_skill;
          if ( !CCSBot::IsHiding(this)
            && m_skill * 100.0 + 25.0 > _RandomFloat(this: v6, a2: 0.0, a3: 100.0)
            && (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) < 5.0 )
          {
            CBot<CCSPlayer>::PrintIfWatched(this, format: "Retreating to a safe spot to reload!\n");
            NearbyRetreatSpot = FindNearbyRetreatSpot(me: this, maxRange: 1000.0);
            if ( NearbyRetreatSpot != nullptr )
            {
              CCSBot::IgnoreEnemies(this, duration: 10.0);
              this->Run(this);
              this->StandUp(this);
              CCSBot::Hide(this, hidingSpot: NearbyRetreatSpot, duration: 0.0, holdPosition: false);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA480
// Name: private: void CCSBot::SilencerCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SilencerCheck(CCSBot *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v3; // eax
  CBaseCombatWeapon *v4; // eax
  float *v5; // edi
  unsigned __int8 v6; // bl
  const BotProfile *m_profile; // eax
  int v8; // eax
  const char *v9; // eax

  if ( !CCSBot::IsDefusingBomb(this) )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( (ActiveWeapon == nullptr || !ActiveWeapon->m_bInReload.m_Value) && !CCSBot::IsAttacking(this) )
    {
      v3 = CBaseCombatCharacter::GetActiveWeapon(this);
      if ( v3 != nullptr
        && ((int (__thiscall *)(CBaseCombatWeapon *))v3->__vftable[1].GetModelName)(a1: v3) == 12
        && (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) >= 3.5
        && CCSBot::GetNearbyEnemyCount(this) == 0 )
      {
        v4 = CBaseCombatCharacter::GetActiveWeapon(this);
        v5 = (float *)v4;
        if ( v4 != nullptr )
        {
          v6 = ((int (__thiscall *)(CBaseCombatWeapon *))v4->__vftable[1].SetModelIndex)(a1: v4);
          if ( v5[294] < gpGlobals->curtime )
          {
            m_profile = this->m_profile;
            v8 = m_profile->m_prefersSilencer || m_profile->m_skill > 0.69999999;
            if ( v6 != v8 && !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this) )
            {
              v9 = "Unequipping";
              if ( v6 == 0 )
                v9 = "Equipping";
              CBot<CCSPlayer>::PrintIfWatched(this, format: "%s silencer!\n", v9);
              (*(void (__thiscall **)(float *))(*(_DWORD *)v5 + 1132))(a1: v5);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA6D0
// Name: public: void CCSBot::AvoidEnemyGrenades(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::AvoidEnemyGrenades(CCSBot *this)
{
  GrenadeResponse respond; // [esp+Ch] [ebp-4h] BYREF

  respond.m_me = this;
  if ( this->m_profile->m_skill >= 0.5
    && IntervalTimer::Now(this: (CEffectsServer *)&this->m_isAvoidingGrenade) > this->m_isAvoidingGrenade.m_timestamp.m_Value
    && this->m_profile->m_skill >= 0.60000002 )
  {
    respond.m_me = this;
    if ( !CBotManager::ForEachGrenade<GrenadeResponse>(this: TheBots, func: &respond) )
      CountdownTimer::Start(this: &this->m_isAvoidingGrenade, duration: 4.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2170
// Name: __CreateCServerGameTagsIServerGameTags_interface_20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_20()
{
  return &_g_CServerGameTags_singleton_20;
}

//------------------------------------------------------------------------------
// Address: 0x102C9050
// Name: bool ForEachPlayer<class FOVClearOfFriends>(class FOVClearOfFriends __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<FOVClearOfFriends>(FOVClearOfFriends *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CCSBot *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = (CCSBot *)v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && !FOVClearOfFriends::operator()(this: func, player: v3) )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CA750
// Name: __CreateCServerGameTagsIServerGameTags_interface_29
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_29()
{
  return &_g_CServerGameTags_singleton_29;
}

//------------------------------------------------------------------------------
// Address: 0x102CA760
// Name: __CreateCServerGameTagsIServerGameTags_interface_30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_30()
{
  return &_g_CServerGameTags_singleton_30;
}
