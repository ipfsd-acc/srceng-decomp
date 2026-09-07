// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/in_main.cpp
// Functions: 109
// ============================================================

#include "game\client\in_main.h"

//------------------------------------------------------------------------------
// Address: 0x10114BA0
// Name: SplitScreenTeleport
// Source: json
//------------------------------------------------------------------------------
void __usercall SplitScreenTeleport(int nSlot@<eax>)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v2; // esi
  int v3; // eax
  float v4; // ecx
  __int64 v5; // xmm0_8
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  int v7; // eax
  float v8; // ecx
  char cmd[256]; // [esp+34h] [ebp-118h] BYREF
  QAngle angles; // [esp+134h] [ebp-18h]
  Vector vecOrigin; // [esp+140h] [ebp-Ch]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot);
  v2 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    v3 = (int)LocalPlayer->GetAbsOrigin(this: LocalPlayer);
    v4 = *(float *)(v3 + 8);
    v5 = *(_QWORD *)v3;
    GetAbsAngles = v2->GetAbsAngles;
    vecOrigin.z = v4;
    *(_QWORD *)&vecOrigin.x = v5;
    v7 = (int)GetAbsAngles(this: v2);
    v8 = *(float *)(v7 + 8);
    *(_QWORD *)&angles.x = *(_QWORD *)v7;
    angles.z = v8;
    if ( C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr )
    {
      V_snprintf(
        pDest: cmd,
        maxLen: 256,
        pFormat: "cmd%d setpos %f %f %f;setang %f %f %f\n",
        1,
        vecOrigin.x,
        vecOrigin.y,
        vecOrigin.z,
        angles.x,
        angles.y,
        angles.z);
      engine->ClientCmd(this: engine, a2: cmd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114C90
// Name: ss_teleport
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_teleport()
{
  SplitScreenTeleport(nSlot: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10114CA0
// Name: void IN_JoystickChangedCallback_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_JoystickChangedCallback_f()
{
  input->Joystick_Advanced(this: input, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10114CB0
// Name: public: virtual struct kbutton_t __near * CInput::FindKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
kbutton_t *__thiscall CInput::FindKey(CInput *this, const char *name)
{
  CKeyboardKey *m_pKeys; // esi

  m_pKeys = this->m_pKeys;
  if ( m_pKeys == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: name, s2: m_pKeys->name) != 0 )
  {
    m_pKeys = m_pKeys->next;
    if ( m_pKeys == nullptr )
      return nullptr;
  }
  return m_pKeys->pkey;
}

//------------------------------------------------------------------------------
// Address: 0x10114CF0
// Name: public: CInput::~CInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::~CInput(CInput *this)
{
  this->__vftable = (CInput_vtbl *)&CInput::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10114D00
// Name: protected: void CInput::Init_Keyboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Init_Keyboard(CInput *this)
{
  kbutton_t *(__thiscall *FindKey)(struct CInput *, const char *); // edx
  CKeyboardKey *v3; // edi
  CKeyboardKey *v4; // edi

  FindKey = this->FindKey;
  this->m_pKeys = nullptr;
  if ( ((int (__stdcall *)(const char *))FindKey)(a1: "in_graph") == 0 )
  {
    v3 = (CKeyboardKey *)MemAlloc_Alloc(nSize: 0x28u);
    V_strncpy(pDest: v3->name, pSrc: "in_graph", maxLen: 32);
    v3->pkey = &in_graph;
    v3->next = this->m_pKeys;
    this->m_pKeys = v3;
  }
  if ( this->FindKey(this, a2: "in_jlook") == nullptr )
  {
    v4 = (CKeyboardKey *)MemAlloc_Alloc(nSize: 0x28u);
    V_strncpy(pDest: v4->name, pSrc: "in_jlook", maxLen: 32);
    v4->pkey = &in_jlook;
    v4->next = this->m_pKeys;
    this->m_pKeys = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114D90
// Name: public: struct kbutton_t::Split_t __near & kbutton_t::GetPerUser(int)
// Source: json
//------------------------------------------------------------------------------
kbutton_t *__thiscall kbutton_t::GetPerUser(kbutton_t *this, int nSlot)
{
  int v2; // eax

  v2 = nSlot;
  if ( nSlot == -1 )
    v2 = 0;
  return this + v2;
}

//------------------------------------------------------------------------------
// Address: 0x10114DB0
// Name: void KeyDown(struct kbutton_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeyDown(kbutton_t *b, const char *c)
{
  int v2; // eax
  int v3; // edx
  int state; // eax

  v2 = -1;
  if ( c != nullptr && *c != 0 )
    v2 = atoi(nptr: c);
  if ( v2 != b->m_PerUser[0].down[0] )
  {
    v3 = b->m_PerUser[0].down[1];
    if ( v2 != v3 )
    {
      if ( b->m_PerUser[0].down[0] == 0 )
      {
        b->m_PerUser[0].down[0] = v2;
        goto LABEL_10;
      }
      if ( v3 == 0 )
      {
        b->m_PerUser[0].down[1] = v2;
LABEL_10:
        state = b->m_PerUser[0].state;
        if ( (state & 1) == 0 )
          b->m_PerUser[0].state = state | 3;
        return;
      }
      if ( *c != 0 )
        _DevMsg(a1: 1, a2: "Three keys down for a button '%c' '%c' '%c'!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114E20
// Name: void KeyUp(struct kbutton_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeyUp(kbutton_t *b, const char *c)
{
  int v2; // eax
  int v3; // edx
  int state; // eax

  if ( c == nullptr || *c == 0 )
  {
    b->m_PerUser[0].down[1] = 0;
    b->m_PerUser[0].down[0] = 0;
    b->m_PerUser[0].state = 4;
    return;
  }
  v2 = atoi(nptr: c);
  v3 = b->m_PerUser[0].down[0];
  if ( b->m_PerUser[0].down[0] == v2 )
  {
    b->m_PerUser[0].down[0] = 0;
  }
  else
  {
    if ( b->m_PerUser[0].down[1] != v2 )
      return;
    b->m_PerUser[0].down[1] = 0;
    if ( v3 != 0 )
      return;
  }
  if ( b->m_PerUser[0].down[1] == 0 )
  {
    state = b->m_PerUser[0].state;
    if ( (state & 1) != 0 )
      b->m_PerUser[0].state = state & 0xFFFFFFFA | 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114E90
// Name: void IN_ForceSpeedDown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ForceSpeedDown()
{
  if ( in_speed.m_PerUser[0].down[0] != -1 && in_speed.m_PerUser[0].down[1] != -1 )
  {
    if ( in_speed.m_PerUser[0].down[0] == 0 )
    {
      in_speed.m_PerUser[0].down[0] = -1;
      goto LABEL_7;
    }
    if ( in_speed.m_PerUser[0].down[1] == 0 )
    {
      in_speed.m_PerUser[0].down[1] = -1;
LABEL_7:
      if ( (in_speed.m_PerUser[0].state & 1) == 0 )
        in_speed.m_PerUser[0].state |= 3u;
      return;
    }
    if ( MEMORY[0] != 0 )
      _DevMsg(a1: 1, a2: "Three keys down for a button '%c' '%c' '%c'!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114EF0
// Name: void IN_ForceSpeedUp(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ForceSpeedUp()
{
  in_speed.m_PerUser[0].down[1] = 0;
  in_speed.m_PerUser[0].down[0] = 0;
  in_speed.m_PerUser[0].state = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10114F10
// Name: public: virtual float CInput::KeyState(struct kbutton_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::KeyState(CInput *this, kbutton_t *key)
{
  float v2; // xmm0_4
  int v3; // eax
  int v4; // ecx
  double v6; // xmm0_8
  float val; // [esp+0h] [ebp-4h]

  v2 = 0.0;
  v3 = key->m_PerUser[0].state & 4;
  v4 = key->m_PerUser[0].state & 1;
  if ( (key->m_PerUser[0].state & 2) != 0 )
  {
    if ( v3 == 0 )
    {
      if ( v4 != 0 )
      {
        key->m_PerUser[0].state = v4;
        return (float)0.5;
      }
      goto LABEL_5;
    }
    if ( v4 != 0 )
    {
      key->m_PerUser[0].state = v4;
      return 0.75;
    }
    v2 = 0.25;
  }
  else if ( v3 == 0 )
  {
    if ( v4 != 0 )
    {
      v6 = 1.0;
      goto LABEL_6;
    }
LABEL_5:
    v6 = 0.0;
LABEL_6:
    val = v6;
    key->m_PerUser[0].state = v4;
    return val;
  }
  key->m_PerUser[0].state = v4;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10114FC0
// Name: public: virtual void CInput::IN_SetSampleTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::IN_SetSampleTime(CInput *this, float frametime)
{
  this->m_PerUser[0].m_flKeyboardSampleTime = frametime;
}

//------------------------------------------------------------------------------
// Address: 0x10114FE0
// Name: protected: struct CInput::PerUserInput_t __near & CInput::GetPerUser(int)
// Source: json
//------------------------------------------------------------------------------
const CInput::PerUserInput_t *__thiscall CInput::GetPerUser(CInput *this, int nSlot)
{
  if ( nSlot == -1 )
    return this->m_PerUser;
  else
    return &this->m_PerUser[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x10115000
// Name: public: virtual void CInput::CheckPaused(class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CheckPaused(CInput *this, CUserCmd *cmd)
{
  if ( engine->IsPaused(this: engine) )
  {
    cmd->buttons = 0;
    cmd->forwardmove = 0.0;
    cmd->sidemove = 0.0;
    cmd->upmove = 0.0;
    cmd->weaponselect = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115040
// Name: public: virtual class CUserCmd __near * CInput::GetUserCmd(int,int)
// Source: json
//------------------------------------------------------------------------------
CUserCmd *__thiscall CInput::GetUserCmd(CInput *this, int nSlot, int sequence_number)
{
  CInput::PerUserInput_t *m_PerUser; // esi
  int v4; // eax

  if ( nSlot == -1 )
    m_PerUser = this->m_PerUser;
  else
    m_PerUser = &this->m_PerUser[nSlot];
  v4 = (int)&m_PerUser->m_pCommands[sequence_number % 150];
  return *(_DWORD *)(v4 + 4) != sequence_number ? nullptr : (CUserCmd *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101150A0
// Name: public: virtual int CInput::GetButtonBits(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInput::GetButtonBits(CInput *this, bool bResetState)
{
  int m_nClearInputState; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int result; // eax

  m_nClearInputState = this->m_PerUser[0].m_nClearInputState;
  v4 = 0;
  if ( (in_speed.m_PerUser[0].state & 3) != 0 )
    v4 = 0x20000;
  v5 = -3;
  if ( (m_nClearInputState & 0x20000) != 0 )
    v5 = -4;
  if ( bResetState )
    in_speed.m_PerUser[0].state &= v5;
  if ( (in_walk.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x40000u;
  v6 = -3;
  if ( (m_nClearInputState & 0x40000) != 0 )
    v6 = -4;
  if ( bResetState )
    in_walk.m_PerUser[0].state &= v6;
  if ( (in_attack.m_PerUser[0].state & 3) != 0 )
    v4 |= 1u;
  v7 = -3;
  if ( (m_nClearInputState & 1) != 0 )
    v7 = -4;
  if ( bResetState )
    in_attack.m_PerUser[0].state &= v7;
  if ( (in_duck.m_PerUser[0].state & 3) != 0 )
    v4 |= 4u;
  v8 = -3;
  if ( (m_nClearInputState & 4) != 0 )
    v8 = -4;
  if ( bResetState )
    in_duck.m_PerUser[0].state &= v8;
  if ( (in_jump.m_PerUser[0].state & 3) != 0 )
    v4 |= 2u;
  v9 = -3;
  if ( (m_nClearInputState & 2) != 0 )
    v9 = -4;
  if ( bResetState )
    in_jump.m_PerUser[0].state &= v9;
  if ( (in_forward.m_PerUser[0].state & 3) != 0 )
    v4 |= 8u;
  v10 = -3;
  if ( (m_nClearInputState & 8) != 0 )
    v10 = -4;
  if ( bResetState )
    in_forward.m_PerUser[0].state &= v10;
  if ( (in_back.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x10u;
  v11 = -3;
  if ( (m_nClearInputState & 0x10) != 0 )
    v11 = -4;
  if ( bResetState )
    in_back.m_PerUser[0].state &= v11;
  if ( (in_use.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x20u;
  v12 = -3;
  if ( (m_nClearInputState & 0x20) != 0 )
    v12 = -4;
  if ( bResetState )
    in_use.m_PerUser[0].state &= v12;
  if ( (in_left.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x80u;
  v13 = -3;
  if ( (m_nClearInputState & 0x80u) != 0 )
    v13 = -4;
  if ( bResetState )
    in_left.m_PerUser[0].state &= v13;
  if ( (in_right.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x100u;
  v14 = -3;
  if ( (m_nClearInputState & 0x100) != 0 )
    v14 = -4;
  if ( bResetState )
    in_right.m_PerUser[0].state &= v14;
  if ( (in_moveleft.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x200u;
  v15 = -3;
  if ( (m_nClearInputState & 0x200) != 0 )
    v15 = -4;
  if ( bResetState )
    in_moveleft.m_PerUser[0].state &= v15;
  if ( (in_moveright.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x400u;
  v16 = -3;
  if ( (m_nClearInputState & 0x400) != 0 )
    v16 = -4;
  if ( bResetState )
    in_moveright.m_PerUser[0].state &= v16;
  if ( (in_attack2.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x800u;
  v17 = -3;
  if ( (m_nClearInputState & 0x800) != 0 )
    v17 = -4;
  if ( bResetState )
    in_attack2.m_PerUser[0].state &= v17;
  if ( (in_reload.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x2000u;
  v18 = -3;
  if ( (m_nClearInputState & 0x2000) != 0 )
    v18 = -4;
  if ( bResetState )
    in_reload.m_PerUser[0].state &= v18;
  if ( (in_alt1.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x4000u;
  v19 = -3;
  if ( (m_nClearInputState & 0x4000) != 0 )
    v19 = -4;
  if ( bResetState )
    in_alt1.m_PerUser[0].state &= v19;
  if ( (in_alt2.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x8000u;
  v20 = -3;
  if ( (m_nClearInputState & 0x8000) != 0 )
    v20 = -4;
  if ( bResetState )
    in_alt2.m_PerUser[0].state &= v20;
  if ( (in_score.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x10000u;
  v21 = -3;
  if ( (m_nClearInputState & 0x10000) != 0 )
    v21 = -4;
  if ( bResetState )
    in_score.m_PerUser[0].state &= v21;
  if ( (in_zoom.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x80000u;
  v22 = -3;
  if ( (m_nClearInputState & 0x80000) != 0 )
    v22 = -4;
  if ( bResetState )
    in_zoom.m_PerUser[0].state &= v22;
  if ( (in_grenade1.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x800000u;
  v23 = -3;
  if ( (m_nClearInputState & 0x800000) != 0 )
    v23 = -4;
  if ( bResetState )
    in_grenade1.m_PerUser[0].state &= v23;
  if ( (in_grenade2.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x1000000u;
  v24 = -3;
  if ( (m_nClearInputState & 0x1000000) != 0 )
    v24 = -4;
  if ( bResetState )
    in_grenade2.m_PerUser[0].state &= v24;
  if ( (in_lookspin.m_PerUser[0].state & 3) != 0 )
    v4 |= 0x2000000u;
  v25 = -3;
  if ( (m_nClearInputState & 0x2000000) != 0 )
    v25 = -4;
  if ( bResetState )
    in_lookspin.m_PerUser[0].state &= v25;
  if ( ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_ducktoggle) != 0.0 )
    v4 |= 4u;
  if ( ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_speedtoggle) != 0.0 )
    v4 |= 0x20000u;
  if ( in_cancel[0] != 0 )
    v4 |= 0x40u;
  if ( (GetHud(nSlot: 0)->m_iKeyBits & 0x100000) != 0 )
    v4 |= 0x100000u;
  if ( (GetHud(nSlot: 0)->m_iKeyBits & 0x200000) != 0 )
    v4 |= 0x200000u;
  result = ~m_nClearInputState & v4;
  if ( bResetState )
    this->m_PerUser[0].m_nClearInputState = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101154B0
// Name: public: virtual float CInput::GetLastForwardMove(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::GetLastForwardMove(CInput *this)
{
  return this->m_PerUser[0].m_flLastForwardMove;
}

//------------------------------------------------------------------------------
// Address: 0x101154C0
// Name: public: unsigned long CUserCmd::GetChecksum(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUserCmd::GetChecksum(CUserCmd *this)
{
  unsigned int crc; // [esp+4h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->command_number, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->tick_count, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->viewangles.x, nBuffer: 12);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->forwardmove, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->sidemove, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->upmove, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->buttons, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->impulse, nBuffer: 1);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->weaponselect, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->weaponsubtype, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->random_seed, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->mousedx, nBuffer: 2);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->mousedy, nBuffer: 2);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x101155B0
// Name: void IN_Joystick_Advanced_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Joystick_Advanced_f(const CCommand *args)
{
  ((void (__stdcall *)(bool))input->Joystick_Advanced)(a1: args->m_nArgc == 2);
}

//------------------------------------------------------------------------------
// Address: 0x101155D0
// Name: void IN_CommanderMouseMoveDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_CommanderMouseMoveDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_commandermousemove, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_commandermousemove, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115610
// Name: void IN_CommanderMouseMoveUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_CommanderMouseMoveUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_commandermousemove, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_commandermousemove, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115650
// Name: void IN_BreakDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_BreakDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_break, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_break, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115690
// Name: void IN_BreakUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_BreakUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_break, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_break, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101156D0
// Name: void IN_KLookDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_KLookDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_klook, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_klook, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115710
// Name: void IN_KLookUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_KLookUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_klook, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_klook, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115750
// Name: void IN_JLookDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_JLookDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_jlook, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_jlook, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115790
// Name: void IN_JLookUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_JLookUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_jlook, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_jlook, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101157D0
// Name: void IN_UpDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_UpDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_up, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_up, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115810
// Name: void IN_UpUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_UpUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_up, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_up, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115850
// Name: void IN_DownDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_DownDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_down, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_down, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115890
// Name: void IN_DownUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_DownUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_down, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_down, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101158D0
// Name: void IN_LeftDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LeftDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_left, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_left, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115910
// Name: void IN_LeftUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LeftUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_left, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_left, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115950
// Name: void IN_RightDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_RightDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_right, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_right, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115990
// Name: void IN_RightUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_RightUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_right, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_right, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101159D0
// Name: void IN_ForwardDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ForwardDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_forward, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_forward, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115A10
// Name: void IN_ForwardUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ForwardUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_forward, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_forward, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115A50
// Name: void IN_BackDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_BackDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_back, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_back, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115A90
// Name: void IN_BackUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_BackUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_back, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_back, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115AD0
// Name: void IN_LookupDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookupDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_lookup, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_lookup, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115B10
// Name: void IN_LookupUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookupUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_lookup, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_lookup, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115B50
// Name: void IN_LookdownDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookdownDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_lookdown, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_lookdown, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115B90
// Name: void IN_LookdownUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookdownUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_lookdown, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_lookdown, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115BD0
// Name: void IN_MoveleftDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_MoveleftDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_moveleft, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_moveleft, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115C10
// Name: void IN_MoveleftUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_MoveleftUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_moveleft, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_moveleft, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115C50
// Name: void IN_MoverightDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_MoverightDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_moveright, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_moveright, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115C90
// Name: void IN_MoverightUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_MoverightUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_moveright, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_moveright, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115CD0
// Name: void IN_StrafeDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_StrafeDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_strafe, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_strafe, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115D10
// Name: void IN_StrafeUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_StrafeUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_strafe, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_strafe, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115D50
// Name: void IN_Attack2Down(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Attack2Down(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_attack2, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_attack2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115D90
// Name: void IN_Attack2Up(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Attack2Up(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_attack2, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_attack2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115DD0
// Name: void IN_UseDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_UseDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_use, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_use, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115E10
// Name: void IN_UseUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_UseUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_use, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_use, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115E50
// Name: void IN_JumpDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_JumpDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_jump, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_jump, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115E90
// Name: void IN_JumpUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_JumpUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_jump, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_jump, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10115ED0
// Name: void IN_DuckToggle(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_DuckToggle(const CCommand *args)
{
  if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_ducktoggle) == 0.0 )
  {
    if ( args->m_nArgc > 1 )
      KeyDown(b: &in_ducktoggle, c: args->m_ppArgv[1]);
    else
      KeyDown(b: &in_ducktoggle, c: prType);
  }
  else if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_ducktoggle) != 0.0 )
  {
    in_ducktoggle.m_PerUser[0].down[1] = 0;
    in_ducktoggle.m_PerUser[0].down[0] = 0;
    in_ducktoggle.m_PerUser[0].state = 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115F60
// Name: void IN_SpeedToggle(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_SpeedToggle(const CCommand *args)
{
  if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_speedtoggle) == 0.0 )
  {
    if ( args->m_nArgc > 1 )
      KeyDown(b: &in_speedtoggle, c: args->m_ppArgv[1]);
    else
      KeyDown(b: &in_speedtoggle, c: prType);
  }
  else if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_speedtoggle) != 0.0 )
  {
    in_speedtoggle.m_PerUser[0].down[1] = 0;
    in_speedtoggle.m_PerUser[0].down[0] = 0;
    in_speedtoggle.m_PerUser[0].state = 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115FF0
// Name: void IN_WalkDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_WalkDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_walk, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_walk, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116030
// Name: void IN_WalkUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_WalkUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_walk, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_walk, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116070
// Name: void IN_ReloadDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ReloadDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_reload, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_reload, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101160B0
// Name: void IN_ReloadUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ReloadUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_reload, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_reload, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101160F0
// Name: void IN_Alt1Down(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Alt1Down(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_alt1, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_alt1, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116130
// Name: void IN_Alt1Up(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Alt1Up(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_alt1, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_alt1, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116170
// Name: void IN_Alt2Down(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Alt2Down(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_alt2, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_alt2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101161B0
// Name: void IN_Alt2Up(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Alt2Up(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_alt2, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_alt2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101161F0
// Name: void IN_GraphDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_GraphDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_graph, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_graph, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116230
// Name: void IN_GraphUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_GraphUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_graph, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_graph, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116270
// Name: void IN_ZoomDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ZoomDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_zoom, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_zoom, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101162B0
// Name: void IN_ZoomUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ZoomUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_zoom, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_zoom, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101162F0
// Name: void IN_Grenade1Up(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Grenade1Up(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_grenade1, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_grenade1, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116330
// Name: void IN_Grenade1Down(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Grenade1Down(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_grenade1, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_grenade1, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116370
// Name: void IN_Grenade2Up(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Grenade2Up(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_grenade2, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_grenade2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101163B0
// Name: void IN_Grenade2Down(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Grenade2Down(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_grenade2, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_grenade2, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101163F0
// Name: void IN_AttackDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_AttackDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_attack, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_attack, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10116430
// Name: void IN_AttackUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_AttackUp(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = prType;
  KeyUp(b: &in_attack, c: v1);
  in_cancel[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10116470
// Name: void IN_Impulse(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_Impulse(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    in_impulse[0] = atoi(nptr: args->m_ppArgv[1]);
  else
    in_impulse[0] = atoi(nptr: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101164B0
// Name: void IN_ScoreDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ScoreDown(const CCommand *args)
{
  const char *v1; // eax
  IViewPort *ViewPortInterface; // eax

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = prType;
  KeyDown(b: &in_score, c: v1);
  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116500
// Name: void IN_ScoreUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_ScoreUp(const CCommand *args)
{
  const char *v1; // eax
  IViewPort *ViewPortInterface; // eax
  CVoiceStatus *ClientVoiceMgr; // eax

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = prType;
  KeyUp(b: &in_score, c: v1);
  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: false);
    ClientVoiceMgr = GetClientVoiceMgr();
    CVoiceStatus::StopSquelchMode(this: ClientVoiceMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116560
// Name: void IN_LookSpinDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookSpinDown(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyDown(b: &in_lookspin, c: args->m_ppArgv[1]);
  else
    KeyDown(b: &in_lookspin, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101165A0
// Name: void IN_LookSpinUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_LookSpinUp(const CCommand *args)
{
  if ( args->m_nArgc > 1 )
    KeyUp(b: &in_lookspin, c: args->m_ppArgv[1]);
  else
    KeyUp(b: &in_lookspin, c: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101165E0
// Name: protected: void CInput::AdjustYaw(int,float,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::AdjustYaw(CInput *this, int nSlot, float speed, QAngle *viewangles)
{
  int v6; // eax
  double v7; // st7
  float (__thiscall *KeyState)(struct CInput *, kbutton_t *); // eax
  CInput::PerUserInput_t *m_PerUser; // edi
  float v10; // xmm1_4
  float forwarda; // [esp+3Ch] [ebp+8h]
  float forwardb; // [esp+3Ch] [ebp+8h]
  float forwardc; // [esp+3Ch] [ebp+8h]
  float forward; // [esp+3Ch] [ebp+8h]
  float sidea; // [esp+40h] [ebp+Ch]
  float side; // [esp+40h] [ebp+Ch]

  v6 = nSlot;
  if ( nSlot == -1 )
    v6 = 0;
  if ( (in_strafe.m_PerUser[v6].state & 1) == 0 )
  {
    forwarda = cl_yawspeed.m_pParent->m_Value.m_fValue;
    v7 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_right);
    KeyState = this->KeyState;
    viewangles->y = viewangles->y - v7 * (forwarda * speed);
    forwardb = cl_yawspeed.m_pParent->m_Value.m_fValue;
    viewangles->y = ((double (__thiscall *)(CInput *, kbutton_t *))KeyState)(a1: this, a2: &in_left)
                  * (forwardb
                   * speed)
                  + viewangles->y;
  }
  if ( nSlot == -1 )
    m_PerUser = this->m_PerUser;
  else
    m_PerUser = &this->m_PerUser[nSlot];
  if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
    && thirdperson_platformer.m_pParent != nullptr
    && thirdperson_platformer.m_pParent->m_Value.m_nValue != 0 )
  {
    sidea = this->KeyState(this, a2: &in_moveleft);
    side = sidea - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveright);
    forwardc = this->KeyState(this, a2: &in_forward);
    forward = forwardc - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_back);
    v10 = forward;
    if ( side != 0.0 || forward != 0.0 )
    {
      __libm_sse2_atan2();
      v10 = forward;
      viewangles->y = (float)(side * 57.29578) + m_PerUser->m_vecCameraOffset.y;
    }
    if ( side != 0.0
      || v10 != 0.0
      || ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_right) != 0.0
      || ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_left) != 0.0 )
    {
      ConVar::SetValue(this: (ConVar *)&cam_idealyaw.IConVar, value: m_PerUser->m_vecCameraOffset.y - viewangles->y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101167A0
// Name: protected: void CInput::ComputeSideMove(int,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ComputeSideMove(CInput *this, int nSlot, CUserCmd *cmd)
{
  __m128 m_fValue_low; // xmm0
  double v5; // xmm0_8
  double v6; // xmm0_8
  int v7; // eax
  double v9; // st7
  float (__thiscall *KeyState)(struct CInput *, kbutton_t *); // eax
  double v11; // st7
  float (__thiscall *v12)(struct CInput *, kbutton_t *); // eax
  float v13; // [esp+4h] [ebp-8h]
  float v14; // [esp+4h] [ebp-8h]
  float ideal_sin; // [esp+8h] [ebp-4h]
  int ideal_cos; // [esp+14h] [ebp+8h]
  float ideal_cosa; // [esp+14h] [ebp+8h]
  float cmda; // [esp+18h] [ebp+Ch]
  float cmdb; // [esp+18h] [ebp+Ch]
  float cmdc; // [esp+18h] [ebp+Ch]
  float cmdd; // [esp+18h] [ebp+Ch]

  if ( this->CAM_IsThirdPerson(this, a2: -1) == 0
    || thirdperson_platformer.m_pParent == nullptr
    || thirdperson_platformer.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
      && thirdperson_screenspace.m_pParent != nullptr
      && thirdperson_screenspace.m_pParent->m_Value.m_nValue != 0 )
    {
      m_fValue_low = (__m128)LODWORD(cam_idealyaw.m_pParent->m_Value.m_fValue);
      m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * 0.017453292;
      ideal_cos = m_fValue_low.m128_i32[0];
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(m_fValue_low));
      *(float *)&v5 = v5;
      ideal_sin = *(float *)&v5;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)ideal_cos));
      *(float *)&v6 = v6;
      v13 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveright) * *(float *)&v6;
      v14 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_back) * ideal_sin + v13;
      ideal_cosa = v14
                 - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveleft)
                 * *(float *)&v6;
      cmd->sidemove = (ideal_cosa
                     - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_forward)
                     * ideal_sin)
                    * cl_sidespeed.m_pParent->m_Value.m_fValue
                    + cmd->sidemove;
    }
    else
    {
      v7 = nSlot;
      if ( nSlot == -1 )
        v7 = 0;
      if ( (in_strafe.m_PerUser[v7].state & 1) != 0 )
      {
        cmda = cl_sidespeed.m_pParent->m_Value.m_fValue;
        v9 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_right);
        KeyState = this->KeyState;
        cmd->sidemove = v9 * cmda + cmd->sidemove;
        cmdb = cl_sidespeed.m_pParent->m_Value.m_fValue;
        cmd->sidemove = cmd->sidemove
                      - ((double (__thiscall *)(CInput *, kbutton_t *))KeyState)(a1: this, a2: &in_left) * cmdb;
      }
      cmdc = cl_sidespeed.m_pParent->m_Value.m_fValue;
      v11 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveright);
      v12 = this->KeyState;
      cmd->sidemove = v11 * cmdc + cmd->sidemove;
      cmdd = cl_sidespeed.m_pParent->m_Value.m_fValue;
      cmd->sidemove = cmd->sidemove
                    - ((double (__thiscall *)(CInput *, kbutton_t *))v12)(a1: this, a2: &in_moveleft) * cmdd;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116960
// Name: protected: void CInput::ComputeForwardMove(int,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ComputeForwardMove(CInput *this, int nSlot, CUserCmd *cmd)
{
  BOOL v4; // eax
  __m128 m_fValue_low; // xmm0
  double v6; // xmm0_8
  double v7; // xmm0_8
  int v8; // eax
  double v10; // st7
  float (__thiscall *KeyState)(struct CInput *, kbutton_t *); // eax
  float v12; // [esp+4h] [ebp-8h]
  float v13; // [esp+4h] [ebp-8h]
  float ideal_sin; // [esp+8h] [ebp-4h]
  int ideal_cos; // [esp+14h] [ebp+8h]
  float ideal_cosa; // [esp+14h] [ebp+8h]
  float ideal_cosb; // [esp+14h] [ebp+8h]
  float cmda; // [esp+18h] [ebp+Ch]

  if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
    && thirdperson_platformer.m_pParent != nullptr
    && thirdperson_platformer.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_forward) != 0.0
      || ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveright) != 0.0
      || ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_back) != 0.0
      || ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveleft) != 0.0;
    cmd->forwardmove = (float)((float)v4 * cl_forwardspeed.m_pParent->m_Value.m_fValue) + cmd->forwardmove;
  }
  else if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
         && thirdperson_screenspace.m_pParent != nullptr
         && thirdperson_screenspace.m_pParent->m_Value.m_nValue != 0 )
  {
    m_fValue_low = (__m128)LODWORD(cam_idealyaw.m_pParent->m_Value.m_fValue);
    m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * 0.017453292;
    ideal_cos = m_fValue_low.m128_i32[0];
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(m_fValue_low));
    *(float *)&v6 = v6;
    ideal_sin = *(float *)&v6;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)ideal_cos));
    *(float *)&v7 = v7;
    v12 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_forward) * *(float *)&v7;
    v13 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveright) * ideal_sin + v12;
    ideal_cosa = v13
               - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_back) * *(float *)&v7;
    cmd->forwardmove = (ideal_cosa
                      - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_moveleft)
                      * ideal_sin)
                     * cl_forwardspeed.m_pParent->m_Value.m_fValue
                     + cmd->forwardmove;
  }
  else
  {
    v8 = nSlot;
    if ( nSlot == -1 )
      v8 = 0;
    if ( (in_klook.m_PerUser[v8].state & 1) == 0 )
    {
      ideal_cosb = cl_forwardspeed.m_pParent->m_Value.m_fValue;
      v10 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_forward);
      KeyState = this->KeyState;
      cmd->forwardmove = v10 * ideal_cosb + cmd->forwardmove;
      cmda = cl_backspeed.m_pParent->m_Value.m_fValue;
      cmd->forwardmove = cmd->forwardmove
                       - ((double (__thiscall *)(CInput *, kbutton_t *))KeyState)(a1: this, a2: &in_back) * cmda;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116B80
// Name: public: virtual void CInput::CheckSplitScreenMimic(int,class CUserCmd __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CheckSplitScreenMimic(CInput *this, int nSlot, CUserCmd *cmd, CUserCmd *pPlayer0Command)
{
  C_BasePlayer *LocalPlayer; // edi
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // ebx
  int v7; // eax
  float v8; // ecx
  __int64 v9; // xmm0_8
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  int v11; // eax
  float v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm0_4
  float forwardmove; // xmm1_4
  float v16; // xmm3_4
  Vector rightDir; // [esp+4h] [ebp-30h] BYREF
  Vector delta; // [esp+10h] [ebp-24h]
  Vector lookDir; // [esp+1Ch] [ebp-18h] BYREF
  Vector moveDir; // [esp+28h] [ebp-Ch] BYREF

  if ( ss_mimic.m_pParent != nullptr && ss_mimic.m_pParent->m_Value.m_nValue > 0 && nSlot != 0 )
  {
    CUserCmd::operator=(this: cmd, src: pPlayer0Command);
    cmd->weaponsubtype = 0;
    cmd->weaponselect = 0;
    engine->SetViewAngles(this: engine, a2: &cmd->viewangles);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
    v5 = C_BasePlayer::GetLocalPlayer(nSlot);
    v6 = v5;
    if ( LocalPlayer != nullptr && v5 != nullptr )
    {
      v7 = (int)LocalPlayer->GetAbsOrigin(this: LocalPlayer);
      v8 = *(float *)(v7 + 8);
      v9 = *(_QWORD *)v7;
      GetAbsOrigin = v6->GetAbsOrigin;
      lookDir.z = v8;
      *(_QWORD *)&lookDir.x = v9;
      v11 = (int)GetAbsOrigin(this: v6);
      v12 = *(float *)(v11 + 8);
      *(_QWORD *)&moveDir.x = *(_QWORD *)v11;
      delta.y = *((float *)&v9 + 1) - moveDir.y;
      delta.x = *(float *)&v9 - moveDir.x;
      moveDir.z = v12;
      v13 = (float)(delta.y * delta.y) + (float)(delta.x * delta.x);
      delta.z = lookDir.z - v12;
      if ( v13 <= 65536.0 )
      {
        cmd->buttons &= 0xFFFFF9E7;
        if ( v13 <= 4096.0 )
        {
          *(_QWORD *)&cmd->sidemove = 0;
          cmd->forwardmove = 0.0;
        }
        else
        {
          AngleVectors(angles: &cmd->viewangles, forward: &lookDir, right: &rightDir, up: nullptr);
          lookDir.z = 0.0;
          VectorNormalize(vec: &lookDir);
          *(_QWORD *)&moveDir.x = *(_QWORD *)&delta.x;
          moveDir.z = 0.0;
          VectorNormalize(vec: &moveDir);
          v14 = rightDir.x * moveDir.x;
          cmd->forwardmove = (float)((float)((float)(lookDir.y * moveDir.y) + (float)(moveDir.x * lookDir.x))
                                   + (float)(moveDir.z * lookDir.z))
                           * cl_forwardspeed.m_pParent->m_Value.m_fValue;
          forwardmove = cmd->forwardmove;
          v16 = (float)((float)((float)(rightDir.y * moveDir.y) + v14) + (float)(rightDir.z * moveDir.z))
              * cl_sidespeed.m_pParent->m_Value.m_fValue;
          cmd->sidemove = v16;
          cmd->upmove = 0.0;
          if ( forwardmove <= 0.0 )
          {
            if ( forwardmove < 0.0 )
              cmd->buttons |= 0x10u;
          }
          else
          {
            cmd->buttons |= 8u;
          }
          if ( v16 <= 0.0 )
          {
            if ( v16 < 0.0 )
              cmd->buttons |= 0x400u;
          }
          else
          {
            cmd->buttons |= 0x200u;
          }
        }
      }
      else
      {
        SplitScreenTeleport(nSlot: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116DB0
// Name: protected: void CInput::ValidateUserCmd(class CUserCmd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ValidateUserCmd(CInput *this, CUserCmd *usercmd, int sequence_number)
{
  unsigned int Checksum; // eax
  CVerifiedUserCmd *m_pVerifiedCommands; // edx
  int v6; // ecx

  Checksum = CUserCmd::GetChecksum(this: usercmd);
  m_pVerifiedCommands = this->m_PerUser[0].m_pVerifiedCommands;
  v6 = sequence_number % 150;
  if ( Checksum != m_pVerifiedCommands[v6].m_crc )
    CUserCmd::operator=(this: usercmd, src: &m_pVerifiedCommands[v6].m_cmd);
}

//------------------------------------------------------------------------------
// Address: 0x10116E10
// Name: public: virtual void CInput::ClearInputButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ClearInputButton(CInput *this, int bits)
{
  if ( in_forceuser.m_pParent == nullptr || in_forceuser.m_pParent->m_Value.m_nValue == 0 )
    this->m_PerUser[0].m_nClearInputState |= bits;
}

//------------------------------------------------------------------------------
// Address: 0x10116E30
// Name: public: virtual float CInput::GetLookSpring(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::GetLookSpring(CInput *this)
{
  if ( lookspring.m_pParent != nullptr )
    return (double)lookspring.m_pParent->m_Value.m_nValue;
  else
    return (double)0;
}

//------------------------------------------------------------------------------
// Address: 0x10116EC0
// Name: public: CInput::PerUserInput_t::PerUserInput_t(void)
// Source: json
//------------------------------------------------------------------------------
CInput::PerUserInput_t *__thiscall CInput::PerUserInput_t::PerUserInput_t(CInput::PerUserInput_t *this)
{
  this->m_hSelectedWeapon.m_Index = -1;
  this->m_flAccumulatedMouseXMovement = 0.0;
  this->m_flAccumulatedMouseYMovement = 0.0;
  this->m_flPreviousMouseXPosition = 0.0;
  this->m_flPreviousMouseYPosition = 0.0;
  this->m_flRemainingJoystickSampleTime = 0.0;
  this->m_flKeyboardSampleTime = 0.0;
  this->m_flSpinFrameTime = 0.0;
  this->m_flSpinRate = 0.0;
  this->m_flLastYawAngle = 0.0;
  *(_WORD *)&this->m_fCameraInterceptingMouse = 0;
  this->m_fCameraMovingWithMouse = false;
  this->m_vecCameraOffset.x = 0.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_fCameraDistanceMove = false;
  this->m_nCameraOldX = 0;
  this->m_nCameraOldY = 0;
  this->m_nCameraX = 0;
  this->m_nCameraY = 0;
  this->m_CameraIsOrthographic = false;
  this->m_angPreviousViewAngles.x = 0.0;
  this->m_angPreviousViewAngles.y = 0.0;
  this->m_angPreviousViewAngles.z = 0.0;
  this->m_angPreviousViewAnglesTilt.x = 0.0;
  this->m_angPreviousViewAnglesTilt.y = 0.0;
  this->m_angPreviousViewAnglesTilt.z = 0.0;
  this->m_flLastForwardMove = 0.0;
  this->m_pCommands = nullptr;
  this->m_pVerifiedCommands = nullptr;
  this->m_nClearInputState = 0;
  this->m_pCameraThirdData = nullptr;
  this->m_nCamCommand = 0;
  this->m_flPreviousJoystickForwardMove = 0.0;
  this->m_flPreviousJoystickSideMove = 0.0;
  this->m_flPreviousJoystickYaw = 0.0;
  this->m_flPreviousJoystickPitch = 0.0;
  *(_DWORD *)&this->m_bPreviousJoystickUseAbsoluteYaw = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10116FC0
// Name: bool UsingMouselook(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl UsingMouselook(int nSlot)
{
  if ( (_S5_103 & 1) == 0 )
  {
    _S5_103 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_MouseLook, pName: "cl_mouselook");
  }
  return s_MouseLook.m_Info[nSlot].m_pConVarState->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117000
// Name: void IN_CenterView_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_CenterView_f()
{
  QAngle viewangles; // [esp+0h] [ebp-Ch] BYREF

  if ( (_S5_103 & 1) == 0 )
  {
    _S5_103 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_MouseLook, pName: "cl_mouselook");
  }
  if ( s_MouseLook.m_Info[0].m_pConVarState->m_Value.m_nValue == 0 && input->CAM_InterceptingMouse(this: input) == 0 )
  {
    engine->GetViewAngles(this: engine, a2: &viewangles);
    viewangles.x = 0.0;
    engine->SetViewAngles(this: engine, a2: &viewangles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117080
// Name: public: CInput::CInput(void)
// Source: json
//------------------------------------------------------------------------------
CInput *__thiscall CInput::CInput(CInput *this)
{
  this->__vftable = (CInput_vtbl *)&CInput::`vftable';
  CInput::PerUserInput_t::PerUserInput_t(this: this->m_PerUser);
  this->m_IKContactPointMutex.m_ownerID = 0;
  this->m_IKContactPointMutex.m_depth = 0;
  this->m_PerUser[0].m_pCommands = nullptr;
  this->m_PerUser[0].m_pCameraThirdData = nullptr;
  this->m_PerUser[0].m_pVerifiedCommands = nullptr;
  this->m_lastAutoAimValue = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101170D0
// Name: void IN_DuckDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_DuckDown(const CCommand *args)
{
  const char *v1; // eax
  SplitScreenConVarRef option_duck_method; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &option_duck_method, pName: "option_duck_method");
  if ( ConVarRef::IsValid(this: &option_duck_method)
    && option_duck_method.m_Info[0].m_pConVarState->m_Value.m_nValue != 0 )
  {
    IN_DuckToggle(args);
  }
  else
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = prType;
    KeyDown(b: &in_duck, c: v1);
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_ducktoggle) != 0.0 )
    {
      in_ducktoggle.m_PerUser[0].down[1] = 0;
      in_ducktoggle.m_PerUser[0].down[0] = 0;
      in_ducktoggle.m_PerUser[0].state = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117170
// Name: void IN_DuckUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_DuckUp(const CCommand *args)
{
  const char *v1; // eax
  SplitScreenConVarRef option_duck_method; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &option_duck_method, pName: "option_duck_method");
  if ( !ConVarRef::IsValid(this: &option_duck_method)
    || option_duck_method.m_Info[0].m_pConVarState->m_Value.m_nValue == 0 )
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = prType;
    KeyUp(b: &in_duck, c: v1);
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_ducktoggle) != 0.0 )
    {
      in_ducktoggle.m_PerUser[0].down[1] = 0;
      in_ducktoggle.m_PerUser[0].down[0] = 0;
      in_ducktoggle.m_PerUser[0].state = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117200
// Name: void IN_SpeedDown(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_SpeedDown(const CCommand *args)
{
  const char *v1; // eax
  SplitScreenConVarRef option_speed_method; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &option_speed_method, pName: "option_speed_method");
  if ( ConVarRef::IsValid(this: &option_speed_method)
    && option_speed_method.m_Info[0].m_pConVarState->m_Value.m_nValue != 0 )
  {
    IN_SpeedToggle(args);
  }
  else
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = prType;
    KeyDown(b: &in_speed, c: v1);
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_speedtoggle) != 0.0 )
    {
      in_speedtoggle.m_PerUser[0].down[1] = 0;
      in_speedtoggle.m_PerUser[0].down[0] = 0;
      in_speedtoggle.m_PerUser[0].state = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101172A0
// Name: void IN_SpeedUp(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_SpeedUp(const CCommand *args)
{
  const char *v1; // eax
  SplitScreenConVarRef option_speed_method; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &option_speed_method, pName: "option_speed_method");
  if ( !ConVarRef::IsValid(this: &option_speed_method)
    || option_speed_method.m_Info[0].m_pConVarState->m_Value.m_nValue == 0 )
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = prType;
    KeyUp(b: &in_speed, c: v1);
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_speedtoggle) != 0.0 )
    {
      in_speedtoggle.m_PerUser[0].down[1] = 0;
      in_speedtoggle.m_PerUser[0].down[0] = 0;
      in_speedtoggle.m_PerUser[0].state = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117330
// Name: public: virtual int CInput::KeyEvent(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInput::KeyEvent(CInput *this, int down, ButtonCode_t code, const char *pszCurrentBinding)
{
  IClientMode *ClientMode; // eax

  if ( (code == KEY_COUNT
     || code == MOUSE_RIGHT
     || code == MOUSE_MIDDLE
     || code == MOUSE_WHEEL_UP
     || code == MOUSE_WHEEL_DOWN)
    && (this->m_PerUser[0].m_fCameraInterceptingMouse
     || m_allowGameMouse.m_pParent == nullptr
     || m_allowGameMouse.m_pParent->m_Value.m_nValue == 0) )
  {
    return 0;
  }
  if ( GetClientMode() == nullptr )
    return 1;
  ClientMode = GetClientMode();
  return ClientMode->KeyInput(this: ClientMode, a2: down, a3: code, a4: pszCurrentBinding);
}

//------------------------------------------------------------------------------
// Address: 0x101173A0
// Name: protected: float CInput::DetermineKeySpeed(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInput::DetermineKeySpeed(CInput *this, int nSlot, float frametime)
{
  CInput::PerUserInput_t *m_PerUser; // eax
  float m_flKeyboardSampleTime; // xmm0_4
  float v6; // xmm1_4
  int v7; // eax
  float speed; // [esp+Ch] [ebp+Ch]

  if ( in_usekeyboardsampletime.m_pParent != nullptr && in_usekeyboardsampletime.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( nSlot == -1 )
      m_PerUser = this->m_PerUser;
    else
      m_PerUser = &this->m_PerUser[nSlot];
    m_flKeyboardSampleTime = m_PerUser->m_flKeyboardSampleTime;
    if ( m_flKeyboardSampleTime <= 0.0 )
      return 0.0;
    v6 = frametime;
    if ( frametime > m_flKeyboardSampleTime )
      v6 = m_PerUser->m_flKeyboardSampleTime;
    m_PerUser->m_flKeyboardSampleTime = m_flKeyboardSampleTime - v6;
  }
  else
  {
    v6 = frametime;
  }
  speed = v6;
  v7 = nSlot;
  if ( nSlot == -1 )
    v7 = 0;
  if ( (in_speed.m_PerUser[v7].state & 1) != 0 )
    return (float)(cl_anglespeedkey.m_pParent->m_Value.m_fValue * v6);
  return speed;
}

//------------------------------------------------------------------------------
// Address: 0x10117440
// Name: protected: void CInput::AdjustPitch(int,float,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::AdjustPitch(CInput *this, int nSlot, float speed, QAngle *viewangles)
{
  int v5; // eax
  double v6; // st7
  float (__thiscall *KeyState)(struct CInput *, kbutton_t *); // eax
  double v8; // st7
  float up; // [esp+Ch] [ebp+8h]
  float upa; // [esp+Ch] [ebp+8h]
  float upb; // [esp+Ch] [ebp+8h]
  float down; // [esp+14h] [ebp+10h]

  if ( (_S5_103 & 1) == 0 )
  {
    _S5_103 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_MouseLook, pName: "cl_mouselook");
  }
  v5 = nSlot;
  if ( s_MouseLook.m_Info[nSlot].m_pConVarState->m_Value.m_nValue == 0 )
  {
    if ( nSlot == -1 )
      v5 = 0;
    if ( (in_klook.m_PerUser[v5].state & 1) != 0 )
    {
      view->StopPitchDrift(this: view);
      up = cl_pitchspeed.m_pParent->m_Value.m_fValue;
      v6 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_forward);
      KeyState = this->KeyState;
      viewangles->x = viewangles->x - v6 * (up * speed);
      upa = cl_pitchspeed.m_pParent->m_Value.m_fValue;
      viewangles->x = ((double (__thiscall *)(CInput *, kbutton_t *))KeyState)(a1: this, a2: &in_back) * (upa * speed)
                    + viewangles->x;
    }
    upb = this->KeyState(this, a2: &in_lookup);
    v8 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_lookdown);
    viewangles->x = viewangles->x - cl_pitchspeed.m_pParent->m_Value.m_fValue * speed * upb;
    viewangles->x = v8 * (speed * cl_pitchspeed.m_pParent->m_Value.m_fValue) + viewangles->x;
    if ( upb != 0.0 || (down = v8) != 0.0 )
      view->StopPitchDrift(this: view);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117570
// Name: protected: void CInput::AdjustAngles(int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInput::AdjustAngles(CInput *this@<ecx>, int a2@<edi>, int nSlot, float frametime)
{
  double v5; // st7
  CViewEffects *ViewEffects; // eax
  CViewEffects *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float x; // xmm1_4
  float v11; // xmm1_4
  QAngle viewangles; // [esp+28h] [ebp-Ch] BYREF
  float speed; // [esp+40h] [ebp+Ch]
  QAngle vecAnglesBeforeTilt; // 0:^1C.12

  v5 = CInput::DetermineKeySpeed(this, nSlot, frametime);
  speed = v5;
  if ( v5 > 0.0 )
  {
    ((void (__thiscall *)(IVEngineClient *, QAngle *, int))engine->GetViewAngles)(a1: engine, a2: &viewangles, a3: a2);
    viewangles.x = viewangles.x - this->m_PerUser[0].m_angPreviousViewAnglesTilt.x;
    viewangles.y = viewangles.y - this->m_PerUser[0].m_angPreviousViewAnglesTilt.y;
    viewangles.z = viewangles.z - this->m_PerUser[0].m_angPreviousViewAnglesTilt.z;
    vecAnglesBeforeTilt = viewangles;
    ViewEffects = GetViewEffects();
    ViewEffects->CalcTilt(this: ViewEffects);
    v7 = GetViewEffects();
    ((void (__thiscall *)(CViewEffects *, QAngle *, int))v7->ApplyTilt)(a1: v7, a2: &viewangles, a3: 1065353216);
    v8 = viewangles.y - vecAnglesBeforeTilt.y;
    v9 = viewangles.z - vecAnglesBeforeTilt.z;
    this->m_PerUser[0].m_angPreviousViewAnglesTilt.x = viewangles.x - vecAnglesBeforeTilt.x;
    this->m_PerUser[0].m_angPreviousViewAnglesTilt.y = v8;
    this->m_PerUser[0].m_angPreviousViewAnglesTilt.z = v9;
    CInput::AdjustYaw(this, nSlot, speed, &viewangles);
    CInput::AdjustPitch(this, nSlot, speed, &viewangles);
    x = viewangles.x;
    if ( viewangles.x > cl_pitchdown.m_pParent->m_Value.m_fValue )
    {
      x = cl_pitchdown.m_pParent->m_Value.m_fValue;
      viewangles.x = x;
    }
    if ( COERCE_FLOAT(LODWORD(cl_pitchup.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_) > x )
      LODWORD(viewangles.x) = LODWORD(cl_pitchup.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
    v11 = 50.0;
    if ( viewangles.z > 50.0 || (v11 = -50.0, viewangles.z < -50.0) )
      viewangles.z = v11;
    engine->SetViewAngles(this: engine, a2: &viewangles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117700
// Name: protected: void CInput::ControllerMove(int,float,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ControllerMove(CInput *this, int nSlot, float frametime, CUserCmd *cmd)
{
  int v5; // eax
  CInput::PerUserInput_t *m_PerUser; // eax

  if ( m_allowGameMouse.m_pParent != nullptr && m_allowGameMouse.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = in_forceuser.m_pParent != nullptr ? in_forceuser.m_pParent->m_Value.m_nValue : 0;
    if ( nSlot == v5 )
    {
      if ( nSlot == -1 )
        m_PerUser = this->m_PerUser;
      else
        m_PerUser = &this->m_PerUser[nSlot];
      if ( !m_PerUser->m_fCameraInterceptingMouse && this->m_fMouseActive )
        CInput::MouseMove(this, nSlot, cmd);
    }
  }
  ((void (__thiscall *)(CInput *, _DWORD, CUserCmd *))this->JoyStickMove)(a1: this, a2: LODWORD(frametime), a3: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x10117780
// Name: public: virtual void CInput::ExtraMouseSample(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInput::ExtraMouseSample(
        CInput *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        float frametime,
        bool active)
{
  IClientMode *ClientMode; // eax
  IClientMode_vtbl *v8; // edx
  float v9; // ecx
  QAngle viewangles; // [esp+28h] [ebp-Ch] BYREF
  int savedregs; // [esp+34h] [ebp+0h]
  float activea; // [esp+40h] [ebp+Ch]
  float activeb; // [esp+40h] [ebp+Ch]

  if ( (_S6_31 & 1) == 0 )
  {
    _S6_31 |= 1u;
    dummy[0].__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
    dword_1064864C = 0;
    dword_10648650 = 0;
    *(_QWORD *)byte_10648654 = 0;
    *(_DWORD *)&byte_10648654[8] = 0;
    dword_10648660 = 0;
    dword_10648664 = 0;
    dword_10648668 = 0;
    dword_1064866C = 0;
    byte_10648670 = 0;
    dword_10648674 = 0;
    dword_10648678 = 0;
    dword_1064867C = 0;
    dword_10648680 = 0;
    byte_10648684 = 0;
    dword_10648688 = 0;
    dword_1064868C = 0;
    dword_10648690 = 0;
    dword_10648694 = 0;
    dword_10648698 = 0;
    dword_1064869C = 0;
    atexit(func: CInput::ExtraMouseSample_::_2_::_dynamic_atexit_destructor_for__dummy__);
  }
  dword_1064864C = 0;
  dword_10648650 = 0;
  *(_QWORD *)byte_10648654 = 0;
  *(_DWORD *)&byte_10648654[8] = 0;
  dword_10648660 = 0;
  dword_10648664 = 0;
  dword_10648668 = 0;
  dword_1064866C = 0;
  byte_10648670 = 0;
  dword_10648674 = 0;
  dword_10648678 = 0;
  dword_1064867C = 0;
  dword_10648680 = 0;
  byte_10648684 = 0;
  dword_10648688 = 0;
  dword_1064868C = 0;
  dword_10648690 = 0;
  dword_10648694 = 0;
  dword_10648698 = 0;
  dword_1064869C = 0;
  if ( active )
  {
    CInput::AdjustAngles(this, a2: a3, nSlot: 0, frametime);
    CInput::ComputeSideMove(this, nSlot: 0, cmd: dummy);
    activea = cl_upspeed.m_pParent->m_Value.m_fValue;
    *(float *)&dword_10648668 = ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_up)
                              * activea
                              + *(float *)&dword_10648668;
    activeb = cl_upspeed.m_pParent->m_Value.m_fValue;
    *(float *)&dword_10648668 = *(float *)&dword_10648668
                              - ((double (__thiscall *)(CInput *, kbutton_t *))this->KeyState)(a1: this, a2: &in_down)
                              * activeb;
    CInput::ComputeForwardMove(this, nSlot: 0, cmd: dummy);
    CInput::ControllerMove(this, nSlot: 0, frametime, cmd: dummy);
  }
  ((void (__thiscall *)(IVEngineClient *, QAngle *, int, int))engine->GetViewAngles)(
    a1: engine,
    a2: &viewangles,
    a3: a4,
    a4: a2);
  if ( round_start_reset_duck.m_pParent != nullptr && round_start_reset_duck.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_ducktoggle) != 0.0 )
    {
      in_ducktoggle.m_PerUser[0].down[1] = 0;
      in_ducktoggle.m_PerUser[0].down[0] = 0;
      in_ducktoggle.m_PerUser[0].state = 4;
    }
    ConVar::SetValue(this: (ConVar *)&round_start_reset_duck.IConVar, value: 0);
  }
  if ( round_start_reset_speed.m_pParent != nullptr && round_start_reset_speed.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_speedtoggle) != 0.0 )
    {
      in_speedtoggle.m_PerUser[0].down[1] = 0;
      in_speedtoggle.m_PerUser[0].down[0] = 0;
      in_speedtoggle.m_PerUser[0].state = 4;
    }
    ConVar::SetValue(this: (ConVar *)&round_start_reset_speed.IConVar, value: 0);
  }
  dword_1064866C = this->GetButtonBits(this, a2: false);
  *(QAngle *)byte_10648654 = viewangles;
  this->m_PerUser[0].m_angPreviousViewAngles = viewangles;
  ClientMode = GetClientMode();
  v8 = ClientMode->__vftable;
  viewangles.y = v9;
  if ( ((unsigned __int8 (__thiscall *)(IClientMode *, _DWORD, CUserCmd *))v8->CreateMove)(
         a1: ClientMode,
         a2: LODWORD(frametime),
         a3: dummy) != 0 )
  {
    engine->SetViewAngles(this: engine, a2: (QAngle *)byte_10648654);
    prediction->SetLocalViewAngles(this: prediction, a2: (QAngle *)byte_10648654);
  }
  ((void (__thiscall *)(CInput *, CUserCmd *, int))this->CheckPaused)(a1: this, a2: dummy, a3: savedregs);
  this->CheckSplitScreenMimic(this, a2: 0, a3: dummy, a4: dummy);
}

//------------------------------------------------------------------------------
// Address: 0x10117B10
// Name: public: virtual void CInput::EncodeUserCmdToBuffer(int,class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::EncodeUserCmdToBuffer(CInput *this, int nSlot, bf_write *buf, int sequence_number)
{
  CUserCmd *(__thiscall *GetUserCmd)(struct CInput *, int, int); // eax
  const CUserCmd *v5; // eax
  CUserCmd nullcmd; // [esp+0h] [ebp-58h] BYREF

  memset(&nullcmd.command_number, 0, 37);
  memset(&nullcmd.weaponselect, 0, 17);
  GetUserCmd = this->GetUserCmd;
  nullcmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  memset((void *)&nullcmd.headangles, 0, 24);
  v5 = GetUserCmd(this, a2: nSlot, a3: sequence_number);
  WriteUsercmd(buf, to: v5, from: &nullcmd);
}

//------------------------------------------------------------------------------
// Address: 0x10117BB0
// Name: public: virtual void CInput::DecodeUserCmdFromBuffer(int,class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::DecodeUserCmdFromBuffer(CInput *this, int nSlot, bf_read *buf, int sequence_number)
{
  CInput::PerUserInput_t *m_PerUser; // esi
  CUserCmd nullcmd; // [esp+0h] [ebp-58h] BYREF

  memset(&nullcmd.command_number, 0, 37);
  memset(&nullcmd.weaponselect, 0, 17);
  nullcmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  memset((void *)&nullcmd.headangles, 0, 24);
  if ( nSlot == -1 )
    m_PerUser = this->m_PerUser;
  else
    m_PerUser = &this->m_PerUser[nSlot];
  ReadUsercmd(buf, move: &m_PerUser->m_pCommands[sequence_number % 150], from: &nullcmd);
}

//------------------------------------------------------------------------------
// Address: 0x10117C80
// Name: public: virtual bool CInput::WriteUsercmdDeltaToBuffer(int,class bf_write __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CInput::WriteUsercmdDeltaToBuffer@<al>(
        CInput *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int nSlot,
        bf_write *buf,
        int from,
        int to,
        bool isnewcommand)
{
  int m_iCurBit; // eax
  CUserCmd *v11; // eax
  CUserCmd *v12; // eax
  CUserCmd *p_nullcmd; // edi
  unsigned int Checksum; // eax
  int v15; // edx
  CUserCmd nullcmd; // [esp+0h] [ebp-60h] BYREF
  int startbit; // [esp+58h] [ebp-8h]
  CUserCmd *f; // [esp+5Ch] [ebp-4h]

  m_iCurBit = buf->m_iCurBit;
  nullcmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  memset(&nullcmd.command_number, 0, 37);
  memset(&nullcmd.weaponselect, 0, 17);
  memset((void *)&nullcmd.headangles, 0, 24);
  startbit = m_iCurBit;
  if ( from == -1 )
  {
    f = &nullcmd;
  }
  else
  {
    v11 = this->GetUserCmd(this, a2: nSlot, a3: from);
    f = v11;
    if ( v11 != nullptr )
      CInput::ValidateUserCmd(this, usercmd: v11, sequence_number: from);
    else
      f = &nullcmd;
  }
  v12 = (CUserCmd *)((int (__thiscall *)(CInput *, int, int, int, int, int))this->GetUserCmd)(
                      a1: this,
                      a2: nSlot,
                      a3: to,
                      a4: a3,
                      a5: a4,
                      a6: a2);
  p_nullcmd = v12;
  if ( v12 != nullptr )
  {
    Checksum = CUserCmd::GetChecksum(this: v12);
    v15 = to % 150;
    if ( Checksum != this->m_PerUser[0].m_pVerifiedCommands[v15].m_crc )
      CUserCmd::operator=(this: p_nullcmd, src: &this->m_PerUser[0].m_pVerifiedCommands[v15].m_cmd);
  }
  else
  {
    p_nullcmd = &nullcmd;
  }
  WriteUsercmd(buf, to: p_nullcmd, from: f);
  if ( !buf->m_bOverflow )
    return 1;
  _Msg(
    a1: "WARNING! User command buffer overflow(%i %i), last cmd was %i bits long\n",
    from,
    to,
    buf->m_iCurBit - startbit);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117DD0
// Name: public: virtual void CInput::Shutdown_All(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Shutdown_All(CInput *this)
{
  CKeyboardKey *m_pKeys; // eax
  CKeyboardKey *next; // esi
  CUserCmd *m_pCommands; // ecx
  CVerifiedUserCmd *m_pVerifiedCommands; // edx
  CVerifiedUserCmd *v6; // eax
  int i; // ecx

  this->DeactivateMouse(this);
  m_pKeys = this->m_pKeys;
  if ( m_pKeys != nullptr )
  {
    do
    {
      next = m_pKeys->next;
      C_BaseEntity::operator delete(pMem: m_pKeys);
      m_pKeys = next;
    }
    while ( next != nullptr );
  }
  this->m_pKeys = nullptr;
  m_pCommands = this->m_PerUser[0].m_pCommands;
  if ( m_pCommands != nullptr )
  {
    if ( LODWORD(m_pCommands[-1].headoffset.z) != 0 )
      ((void (__thiscall *)(CUserCmd *, int))m_pCommands->dtr_CUserCmd)(a1: m_pCommands, a2: 3);
    else
      C_BaseEntity::operator delete(pMem: &m_pCommands[-1].headoffset.z);
  }
  m_pVerifiedCommands = this->m_PerUser[0].m_pVerifiedCommands;
  this->m_PerUser[0].m_pCommands = nullptr;
  if ( m_pVerifiedCommands != nullptr )
  {
    v6 = &m_pVerifiedCommands[m_pVerifiedCommands[-1].m_crc];
    for ( i = m_pVerifiedCommands[-1].m_crc - 1; i >= 0; v6->m_cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable' )
    {
      --v6;
      --i;
    }
    C_BaseEntity::operator delete(pMem: &m_pVerifiedCommands[-1].m_crc);
  }
  this->m_PerUser[0].m_pVerifiedCommands = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10117E60
// Name: public: virtual void CInput::MakeWeaponSelection(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::MakeWeaponSelection(CInput *this, C_BaseCombatWeapon *weapon)
{
  if ( weapon != nullptr )
    this->m_PerUser[0].m_hSelectedWeapon.m_Index = weapon->GetRefEHandle(this: weapon)->m_Index;
  else
    this->m_PerUser[0].m_hSelectedWeapon.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10117E90
// Name: public: virtual void CInput::CreateMove(int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInput::CreateMove(
        CInput *this@<ecx>,
        int a2@<edi>,
        int sequence_number,
        float input_sample_frametime,
        float active)
{
  CUserCmd *v6; // esi
  float (__thiscall *KeyState)(struct CInput *, kbutton_t *); // eax
  double v8; // st7
  float (__thiscall *v9)(struct CInput *, kbutton_t *); // eax
  double v10; // st7
  IHandleEntity *m_pEntity; // ebx
  unsigned int m_Index; // eax
  unsigned int v13; // ecx
  int v14; // eax
  float forwardmove; // xmm0_4
  int v16; // eax
  IClientMode *ClientMode; // eax
  C_HLTVCamera *v18; // eax
  CVerifiedUserCmd *v19; // edi
  int v20; // [esp+18h] [ebp-24h]
  QAngle viewangles; // [esp+24h] [ebp-18h] BYREF
  float mx; // [esp+30h] [ebp-Ch] BYREF
  CVerifiedUserCmd *pVerified; // [esp+34h] [ebp-8h]
  unsigned int v24; // [esp+38h] [ebp-4h]

  v20 = a2;
  v6 = &this->m_PerUser[0].m_pCommands[sequence_number % 150];
  pVerified = &this->m_PerUser[0].m_pVerifiedCommands[sequence_number % 150];
  v6->tick_count = 0;
  v6->viewangles.x = 0.0;
  v6->viewangles.y = 0.0;
  v6->viewangles.z = 0.0;
  v6->forwardmove = 0.0;
  v6->sidemove = 0.0;
  v6->upmove = 0.0;
  v6->buttons = 0;
  v6->impulse = 0;
  v6->weaponselect = 0;
  v6->weaponsubtype = 0;
  v6->random_seed = 0;
  v6->hasbeenpredicted = false;
  *(_DWORD *)&v6->mousedx = 0;
  v6->headangles.x = 0.0;
  v6->headangles.y = 0.0;
  v6->headangles.z = 0.0;
  v6->headoffset.x = 0.0;
  v6->headoffset.y = 0.0;
  v6->headoffset.z = 0.0;
  v6->command_number = sequence_number;
  v24 = 88 * (sequence_number % 150);
  v6->tick_count = *(_DWORD *)(gpGlobals.m_Index + 24);
  if ( LOBYTE(active) != 0
    || sv_noclipduringpause.m_pParent != nullptr && sv_noclipduringpause.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( in_forceuser.m_pParent == nullptr || in_forceuser.m_pParent->m_Value.m_nValue == 0 )
    {
      CInput::AdjustAngles(this, a2: (int)this, nSlot: 0, frametime: input_sample_frametime);
      CInput::ComputeSideMove(this, nSlot: 0, cmd: v6);
      KeyState = this->KeyState;
      active = cl_upspeed.m_pParent->m_Value.m_fValue;
      v8 = ((double (__thiscall *)(CInput *, kbutton_t *))KeyState)(a1: this, a2: &in_up);
      v6->upmove = v8 * active + v6->upmove;
      v9 = this->KeyState;
      active = cl_upspeed.m_pParent->m_Value.m_fValue;
      v10 = ((double (__thiscall *)(CInput *, kbutton_t *))v9)(a1: this, a2: &in_down);
      v6->upmove = v6->upmove - v10 * active;
      CInput::ComputeForwardMove(this, nSlot: 0, cmd: v6);
    }
    CInput::ControllerMove(this, nSlot: 0, frametime: input_sample_frametime, cmd: v6);
  }
  else if ( !this->m_PerUser[0].m_fCameraInterceptingMouse && this->m_fMouseActive )
  {
    CInput::GetAccumulatedMouseDeltasAndResetAccumulators(this, nSlot: 0, &mx, my: &active);
    ((void (__thiscall *)(CInput *, int))this->ResetMouse)(a1: this, a2: v20);
  }
  ((void (__thiscall *)(IVEngineClient *, QAngle *, int))engine->GetViewAngles)(a1: engine, a2: &viewangles, a3: v20);
  m_pEntity = nullptr;
  v6->impulse = in_impulse[0];
  in_impulse[0] = 0;
  m_Index = this->m_PerUser[0].m_hSelectedWeapon.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v13 = this->m_PerUser[0].m_hSelectedWeapon.m_Index;
    if ( v13 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber == HIWORD(v13) )
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    v6->weaponselect = ((int (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &m_pEntity[2]);
    v6->weaponsubtype = (int)m_pEntity->__vftable[74].GetRefEHandle(this: m_pEntity);
    this->m_PerUser[0].m_hSelectedWeapon.m_Index = -1;
  }
  v14 = this->GetButtonBits(this, a2: true);
  v6->buttons = v14;
  if ( in_joystick.m_pParent != nullptr && in_joystick.m_pParent->m_Value.m_nValue != 0 )
  {
    forwardmove = v6->forwardmove;
    if ( forwardmove <= 0.0 )
    {
      if ( forwardmove >= 0.0 )
        goto LABEL_25;
      v16 = v14 | 0x10;
    }
    else
    {
      v16 = v14 | 8;
    }
    v6->buttons = v16;
  }
LABEL_25:
  v6->viewangles = viewangles;
  this->m_PerUser[0].m_angPreviousViewAngles = viewangles;
  ClientMode = GetClientMode();
  if ( ((unsigned __int8 (__thiscall *)(IClientMode *, _DWORD, CUserCmd *))ClientMode->CreateMove)(
         a1: ClientMode,
         a2: LODWORD(input_sample_frametime),
         a3: v6) != 0 )
    engine->SetViewAngles(this: engine, a2: &v6->viewangles);
  this->CheckPaused(this, a2: v6);
  this->CheckSplitScreenMimic(this, a2: 0, a3: v6, a4: &this->m_PerUser[0].m_pCommands[v24 / 0x58]);
  this->m_PerUser[0].m_flLastForwardMove = v6->forwardmove;
  v6->random_seed = MD5_PseudoRandom(nSeed: sequence_number) & 0x7FFFFFFF;
  v18 = HLTVCamera();
  C_HLTVCamera::CreateMove(this: v18, cmd: v6);
  v19 = pVerified;
  CUserCmd::operator=(this: &pVerified->m_cmd, src: v6);
  v19->m_crc = CUserCmd::GetChecksum(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101181D0
// Name: public: virtual void CInput::Init_All(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Init_All(CInput *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax
  CUserCmd *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  int v9; // edx
  _DWORD *v10; // eax
  CVerifiedUserCmd *v11; // eax
  CUserCmd *v12; // [esp+Ch] [ebp-4h]
  CVerifiedUserCmd *v13; // [esp+Ch] [ebp-4h]

  this->m_hInputContext = engine->GetInputContext(this: engine, a2: 0);
  v2 = MemAlloc_Alloc(nSize: 0x3394u);
  if ( v2 != nullptr )
  {
    *v2 = 150;
    v3 = v2 + 1;
    v12 = (CUserCmd *)(v2 + 1);
    v4 = 149;
    v5 = v2 + 6;
    do
    {
      *v3 = &CUserCmd::`vftable';
      *(v5 - 4) = 0;
      *(v5 - 3) = 0;
      *(v5 - 2) = 0;
      *(v5 - 1) = 0;
      *v5 = 0;
      v5[1] = 0;
      v5[2] = 0;
      v5[3] = 0;
      v5[4] = 0;
      *((_BYTE *)v5 + 20) = 0;
      v5[6] = 0;
      v5[7] = 0;
      v5[8] = 0;
      *((_BYTE *)v5 + 40) = 0;
      *((_WORD *)v5 + 18) = 0;
      *((_WORD *)v5 + 19) = 0;
      v5[11] = 0;
      v5[12] = 0;
      v5[13] = 0;
      v5[14] = 0;
      v5[15] = 0;
      v5[16] = 0;
      v3 += 22;
      v5 += 22;
      --v4;
    }
    while ( v4 >= 0 );
    v6 = v12;
  }
  else
  {
    v6 = nullptr;
  }
  this->m_PerUser[0].m_pCommands = v6;
  v7 = MemAlloc_Alloc(nSize: 0x35ECu);
  if ( v7 != nullptr )
  {
    *v7 = 150;
    v8 = v7 + 1;
    v13 = (CVerifiedUserCmd *)(v7 + 1);
    v9 = 149;
    v10 = v7 + 6;
    do
    {
      *v8 = &CUserCmd::`vftable';
      *(v10 - 4) = 0;
      *(v10 - 3) = 0;
      *(v10 - 2) = 0;
      *(v10 - 1) = 0;
      *v10 = 0;
      v10[1] = 0;
      v10[2] = 0;
      v10[3] = 0;
      v10[4] = 0;
      *((_BYTE *)v10 + 20) = 0;
      v10[6] = 0;
      v10[7] = 0;
      v10[8] = 0;
      *((_BYTE *)v10 + 40) = 0;
      *((_WORD *)v10 + 18) = 0;
      *((_WORD *)v10 + 19) = 0;
      v10[11] = 0;
      v10[12] = 0;
      v10[13] = 0;
      v10[14] = 0;
      v10[15] = 0;
      v10[16] = 0;
      v8 += 23;
      v10 += 23;
      --v9;
    }
    while ( v9 >= 0 );
    v11 = v13;
  }
  else
  {
    v11 = nullptr;
  }
  this->m_PerUser[0].m_pVerifiedCommands = v11;
  this->m_fRestoreSPI = false;
  *(_WORD *)&this->m_fMouseInitialized = 0;
  _V_memset(dest: (int)this->m_rgOrigMouseParms, fill: nullptr, count: 0xCu);
  _V_memset(dest: (int)this->m_rgNewMouseParms, fill: nullptr, count: 0xCu);
  _V_memset(dest: (int)this->m_rgCheckMouseParam, fill: nullptr, count: 3u);
  this->m_rgNewMouseParms[0] = 0;
  this->m_rgNewMouseParms[1] = 0;
  this->m_rgNewMouseParms[2] = 1;
  this->m_fMouseParmsValid = false;
  this->m_fJoystickAdvancedInit = false;
  this->m_lastAutoAimValue = 1.0;
  CInput::Init_Mouse(this);
  CInput::Init_Keyboard(this);
  this->Init_Camera(this);
}
