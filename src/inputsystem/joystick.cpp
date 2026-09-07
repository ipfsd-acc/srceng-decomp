// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: inputsystem/joystick.cpp
// Functions: 4
// ============================================================

#include "inputsystem\joystick.h"

//------------------------------------------------------------------------------
// Address: 0x10003680
// Name: private: void CInputSystem::InitializeJoysticks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::InitializeJoysticks(CInputSystem *this)
{
  int v2; // esi
  signed int NumDevs; // eax
  int v4; // edi
  CInputSystem::JoystickInfo_t *v5; // eax
  bool v6; // cl
  int v7; // eax
  void (__thiscall *EnableJoystickInput)(IInputSystem *, int, bool); // edx
  tagJOYCAPSA jc; // [esp+Ch] [ebp-1D0h] BYREF
  joyinfoex_tag ji; // [esp+1A0h] [ebp-3Ch] BYREF
  int nMaxJoysticks; // [esp+1D4h] [ebp-8h]
  int i; // [esp+1D8h] [ebp-4h]

  v2 = 0;
  this->m_nJoystickCount = 0;
  NumDevs = joyGetNumDevs();
  v4 = NumDevs;
  nMaxJoysticks = NumDevs;
  if ( NumDevs <= 4 )
  {
    if ( NumDevs <= 0 )
    {
      _DevMsg(a1: 1, a2: "joystick not found -- driver not present\n");
      return;
    }
  }
  else
  {
    nMaxJoysticks = 4;
    v4 = 4;
  }
  i = 0;
  if ( v4 > 0 )
  {
    do
    {
      _V_memset(dest: &ji, fill: 0, count: 52);
      ji.dwSize = 52;
      ji.dwFlags = 1024;
      if ( joyGetPosEx(uJoyID: v2, pji: &ji) == 0 )
      {
        _V_memset(dest: &jc, fill: 0, count: 404);
        if ( joyGetDevCapsA(uJoyID: v2, pjc: &jc, cbjc: 0x194u) == 0 )
        {
          v5 = &this->m_pJoystickInfo[this->m_nJoystickCount];
          this->m_pJoystickInfo[this->m_nJoystickCount].m_nDeviceId = v2;
          v5->m_JoyInfoEx = ji;
          v5->m_nButtonCount = jc.wNumButtons;
          v6 = (jc.wCaps & 0x10) != 0;
          v5->m_bHasPOVControl = v6;
          v5->m_bDiagonalPOVControlEnabled = false;
          v5->m_nFlags = 1155;
          v5->m_nAxisFlags = 0;
          if ( jc.wNumAxes >= 2 )
            v5->m_nAxisFlags = 3;
          if ( v6 )
            v5->m_nFlags = 1219;
          if ( (jc.wCaps & 1) != 0 )
          {
            v5->m_nFlags |= 4u;
            v5->m_nAxisFlags |= 4u;
          }
          if ( (jc.wCaps & 2) != 0 )
          {
            v5->m_nFlags |= 8u;
            v5->m_nAxisFlags |= 8u;
          }
          if ( (jc.wCaps & 4) != 0 )
          {
            v5->m_nFlags |= 0x10u;
            v5->m_nAxisFlags |= 0x10u;
          }
          if ( (jc.wCaps & 8) != 0 )
          {
            v5->m_nFlags |= 0x20u;
            v5->m_nAxisFlags |= 0x20u;
          }
          v5->m_nLastPolledButtons = 0;
          v5->m_nLastPolledAxisButtons = 0;
          v5->m_nLastPolledPOVState = 0;
          *(_QWORD *)v5->m_pLastPolledAxes = 0;
          *(_QWORD *)&v5->m_pLastPolledAxes[2] = 0;
          *(_QWORD *)&v5->m_pLastPolledAxes[4] = 0;
          v7 = i;
          EnableJoystickInput = this->EnableJoystickInput;
          ++this->m_nJoystickCount;
          EnableJoystickInput(this, a2: v7, a3: true);
          v2 = i;
          v4 = nMaxJoysticks;
        }
      }
      i = ++v2;
    }
    while ( v2 < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: private: void CInputSystem::UpdateJoystickButtonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::UpdateJoystickButtonState(CInputSystem *this, int nJoystick)
{
  int v2; // eax
  unsigned int v4; // edx
  CInputSystem::JoystickInfo_t *v5; // ebx
  int v6; // esi
  int v7; // edx
  int v8; // ebx
  int v9; // esi
  ButtonCode_t v10; // ebx
  int v11; // eax
  CInputSystem::JoystickInfo_t *v12; // ecx
  float v13; // xmm1_4
  unsigned int m_nLastPolledAxisButtons; // eax
  unsigned int v15; // eax
  int v16; // esi
  ButtonCode_t v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // eax
  ButtonCode_t v20; // [esp-4h] [ebp-2Ch]
  AnalogCode_t v21; // [esp-4h] [ebp-2Ch]
  unsigned int buttons; // [esp+14h] [ebp-14h]
  unsigned int buttonsa; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  float value; // [esp+1Ch] [ebp-Ch]
  float minValue; // [esp+20h] [ebp-8h]
  CInputSystem::JoystickInfo_t *info; // [esp+24h] [ebp-4h]

  v2 = nJoystick;
  v4 = this->m_pJoystickInfo[nJoystick].m_JoyInfoEx.dwButtons ^ this->m_pJoystickInfo[nJoystick].m_nLastPolledButtons;
  v5 = &this->m_pJoystickInfo[nJoystick];
  info = v5;
  buttons = v4;
  if ( v4 != 0 )
  {
    v6 = 0;
    if ( this->m_pJoystickInfo[nJoystick].m_nButtonCount > 0 )
    {
      while ( 1 )
      {
        if ( (v4 & (1 << v6)) != 0 )
        {
          v20 = 32 * nJoystick + v6 + 114;
          if ( (v4 & (1 << v6) & v5->m_JoyInfoEx.dwButtons) != 0 )
            CInputSystem::PostButtonPressedEvent(
              this,
              nType: IE_ButtonPressed,
              nTick: this->m_nLastSampleTick,
              scanCode: v20,
              virtualCode: v20);
          else
            CInputSystem::PostButtonReleasedEvent(
              this,
              nType: IE_ButtonReleased,
              nTick: this->m_nLastSampleTick,
              scanCode: v20,
              virtualCode: v20);
        }
        if ( ++v6 >= v5->m_nButtonCount )
          break;
        v4 = buttons;
      }
    }
    v2 = nJoystick;
    v5->m_nLastPolledButtons = v5->m_JoyInfoEx.dwButtons;
  }
  v7 = 0;
  minValue = joy_axisbutton_threshold.m_pParent->m_Value.m_fValue * 32768.0;
  j = 0;
  buttonsa = 1;
  while ( 1 )
  {
    if ( (buttonsa & v5->m_nAxisFlags) != 0 )
    {
      v8 = 6 * v2 + v7;
      v9 = 1 << (2 * v7);
      v21 = v8 + 4;
      v10 = 2 * v8 + 258;
      v11 = this->GetAnalogValue(this, a2: v21);
      v12 = info;
      v13 = (float)v11;
      value = (float)v11;
      if ( (float)v11 > minValue )
      {
        m_nLastPolledAxisButtons = info->m_nLastPolledAxisButtons;
        if ( (m_nLastPolledAxisButtons & v9) == 0 )
        {
          info->m_nLastPolledAxisButtons = v9 | m_nLastPolledAxisButtons;
          CInputSystem::PostButtonPressedEvent(
            this,
            nType: IE_ButtonPressed,
            nTick: this->m_nLastSampleTick,
            scanCode: v10,
            virtualCode: v10);
          v13 = value;
          v12 = info;
        }
      }
      if ( minValue >= v13 )
      {
        v15 = v12->m_nLastPolledAxisButtons;
        if ( (v15 & v9) != 0 )
        {
          v12->m_nLastPolledAxisButtons = v15 & ~v9;
          CInputSystem::PostButtonReleasedEvent(
            this,
            nType: IE_ButtonReleased,
            nTick: this->m_nLastSampleTick,
            scanCode: v10,
            virtualCode: v10);
          v13 = value;
          v12 = info;
        }
      }
      v16 = 2 * v9;
      v17 = v10 + 1;
      if ( COERCE_FLOAT(LODWORD(minValue) ^ _mask__NegFloat_) > v13 )
      {
        v18 = v12->m_nLastPolledAxisButtons;
        if ( (v18 & v16) == 0 )
        {
          v12->m_nLastPolledAxisButtons = v16 | v18;
          CInputSystem::PostButtonPressedEvent(
            this,
            nType: IE_ButtonPressed,
            nTick: this->m_nLastSampleTick,
            scanCode: v17,
            virtualCode: v17);
          v13 = value;
        }
      }
      if ( v13 >= COERCE_FLOAT(LODWORD(minValue) ^ _mask__NegFloat_) )
      {
        v19 = info->m_nLastPolledAxisButtons;
        if ( (v19 & v16) != 0 )
        {
          info->m_nLastPolledAxisButtons = v19 & ~v16;
          CInputSystem::PostButtonReleasedEvent(
            this,
            nType: IE_ButtonReleased,
            nTick: this->m_nLastSampleTick,
            scanCode: v17,
            virtualCode: v17);
        }
      }
      v5 = info;
      v7 = j;
    }
    j = ++v7;
    buttonsa = __ROL4__(buttonsa, 1);
    if ( v7 >= 6 )
      break;
    v2 = nJoystick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A40
// Name: private: void CInputSystem::UpdateJoystickPOVControl(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::UpdateJoystickPOVControl(CInputSystem *this, int nJoystick)
{
  CInputSystem *v2; // edx
  bool v3; // zf
  CInputSystem::JoystickInfo_t *v4; // ecx
  unsigned int dwPOV; // eax
  unsigned int v6; // ebx
  int v7; // esi
  int v8; // edi
  ButtonCode_t v9; // [esp-10h] [ebp-1Ch]
  CInputSystem::JoystickInfo_t *info; // [esp+0h] [ebp-Ch]
  unsigned int buttons; // [esp+4h] [ebp-8h]
  CInputSystem *v12; // [esp+8h] [ebp-4h]

  v2 = this;
  v3 = !this->m_pJoystickInfo[nJoystick].m_bHasPOVControl;
  v4 = &this->m_pJoystickInfo[nJoystick];
  v12 = v2;
  info = v4;
  if ( !v3 )
  {
    dwPOV = v4->m_JoyInfoEx.dwPOV;
    v6 = 0;
    if ( dwPOV != 0xFFFF )
    {
      v6 = dwPOV == 0;
      if ( dwPOV == 9000 )
        v6 |= 2u;
      if ( dwPOV == 18000 )
        v6 |= 4u;
      if ( dwPOV == 27000 )
        v6 |= 8u;
      if ( v4->m_bDiagonalPOVControlEnabled )
      {
        if ( dwPOV == 4500 )
          v6 |= 3u;
        if ( dwPOV == 13500 )
          v6 |= 6u;
        if ( dwPOV == 22500 )
          v6 |= 0xCu;
        if ( dwPOV == 13500 )
          v6 |= 9u;
      }
    }
    buttons = v6 ^ v4->m_nLastPolledPOVState;
    if ( buttons != 0 )
    {
      v7 = 0;
      v8 = 1;
      do
      {
        if ( (buttons & v8) != 0 )
        {
          v9 = v7 + 4 * nJoystick + 242;
          if ( (buttons & v8 & v6) != 0 )
            CInputSystem::PostButtonPressedEvent(
              this: v2,
              nType: IE_ButtonPressed,
              nTick: v2->m_nLastSampleTick,
              scanCode: v9,
              virtualCode: v9);
          else
            CInputSystem::PostButtonReleasedEvent(
              this: v2,
              nType: IE_ButtonReleased,
              nTick: v2->m_nLastSampleTick,
              scanCode: v9,
              virtualCode: v9);
          v2 = v12;
        }
        ++v7;
        v8 = __ROL4__(v8, 1);
      }
      while ( v7 < 4 );
      info->m_nLastPolledPOVState = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B40
// Name: private: void CInputSystem::PollJoystick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PollJoystick(CInputSystem *this)
{
  CInputSystem *v1; // ebx
  unsigned int *p_dwFlags; // edi
  unsigned int *v3; // esi
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // ecx
  bool v10; // zf
  int v11; // ebx
  int v12; // edx
  UINT v13; // [esp-10h] [ebp-2Ch]
  CInputSystem::InputState_t *state; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]
  CInputSystem *v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int *v18; // [esp+14h] [ebp-8h]
  CInputSystem *i; // [esp+18h] [ebp-4h]

  v1 = this;
  v16 = this;
  if ( this->m_JoysticksEnabled.m_nFlags != 0 )
  {
    state = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
    LOBYTE(this) = 0;
    i = nullptr;
    if ( v1->m_nJoystickCount > 0 )
    {
      p_dwFlags = &v1->m_pJoystickInfo[0].m_JoyInfoEx.dwFlags;
      v17 = 4;
      v18 = &v1->m_pJoystickInfo[0].m_JoyInfoEx.dwFlags;
      do
      {
        if ( ((1 << (char)this) & v1->m_JoysticksEnabled.m_nFlags) != 0 )
        {
          v3 = p_dwFlags - 1;
          _V_memset(dest: p_dwFlags - 1, fill: 0, count: 52);
          v4 = p_dwFlags[16];
          v13 = p_dwFlags[14];
          *(p_dwFlags - 1) = 52;
          *p_dwFlags = v4;
          if ( joyGetPosEx(uJoyID: v13, pji: (LPJOYINFOEX)(p_dwFlags - 1)) == 0 )
          {
            if ( joy_wwhack1.m_pParent != nullptr && joy_wwhack1.m_pParent->m_Value.m_nValue != 0 )
              p_dwFlags[5] += 100;
            v5 = 1;
            v6 = 0;
            v15 = 1;
            do
            {
              if ( (v5 & v18[13]) != 0 )
              {
                v7 = v6 + v17;
                switch ( v6 )
                {
                  case 1:
                    v8 = v3[3];
                    break;
                  case 2:
                    v8 = v3[4];
                    break;
                  case 3:
                    v8 = v3[5];
                    break;
                  case 4:
                    v8 = v3[6];
                    break;
                  case 5:
                    v8 = v3[7];
                    break;
                  default:
                    v8 = v3[2];
                    break;
                }
                v9 = v8 - 0x8000;
                v11 = v9 - state->m_pAnalogValue[v7];
                v10 = v9 == state->m_pAnalogValue[v7];
                state->m_pAnalogValue[v7] = v9;
                state->m_pAnalogDelta[v7] = v11;
                v12 = v11;
                v1 = v16;
                if ( !v10 )
                  CInputSystem::PostEvent(
                    this: v16,
                    nType: 3,
                    nTick: v16->m_nLastSampleTick,
                    nData: v7,
                    nData2: v9,
                    nData3: v12);
              }
              ++v6;
              v5 = __ROL4__(v15, 1);
              v15 = v5;
            }
            while ( v6 < 6 );
            CInputSystem::UpdateJoystickButtonState(this: v1, nJoystick: (int)i);
            CInputSystem::UpdateJoystickPOVControl(this: v1, nJoystick: (int)i);
            p_dwFlags = v18;
          }
        }
        v17 += 6;
        this = (CInputSystem *)((char *)&i->__vftable + 1);
        p_dwFlags += 27;
        i = this;
        v18 = p_dwFlags;
      }
      while ( (int)this < v1->m_nJoystickCount );
    }
  }
}
