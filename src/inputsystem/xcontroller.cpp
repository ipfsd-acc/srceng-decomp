// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: inputsystem/xcontroller.cpp
// Functions: 5
// ============================================================

#include "inputsystem\xcontroller.h"

//------------------------------------------------------------------------------
// Address: 0x10004760
// Name: private: void CInputSystem::OpenXDevice(struct CInputSystem::xdevice_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::OpenXDevice(CInputSystem *this, CInputSystem::xdevice_t *pXDevice, int userId)
{
  unsigned __int8 Type; // dl
  _XINPUT_CAPABILITIES capabilities; // [esp+Ch] [ebp-14h] BYREF

  pXDevice->userId = -1;
  pXDevice->active = false;
  if ( PC_XInputGetCapabilities(a1: userId, a2: 1u, a3: &capabilities) == 0 && capabilities.SubType == 1 )
  {
    Type = capabilities.Type;
    pXDevice->flags = capabilities.Flags;
    pXDevice->type = Type;
    pXDevice->stickThreshold[0] = 7849;
    pXDevice->stickThreshold[1] = 7849;
    pXDevice->stickScale[0] = 1.3149805;
    pXDevice->stickScale[1] = 1.3149805;
    pXDevice->subtype = 1;
    pXDevice->userId = userId;
    pXDevice->active = true;
    pXDevice->quitTimeout = 0;
    pXDevice->dpadLock = 0;
    pXDevice->stickThreshold[2] = 8689;
    pXDevice->stickScale[2] = 1.3608539;
    pXDevice->stickThreshold[3] = 8689;
    pXDevice->stickScale[3] = 1.3608539;
    pXDevice->vibration = 0;
    pXDevice->pendingRumbleUpdate = false;
    ++this->m_nJoystickCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: private: void CInputSystem::PostXKeyEvent(int,enum xKey_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PostXKeyEvent(CInputSystem *this, int userId, xKey_t xKey, int nSample)
{
  xKey_t v4; // edx
  int v5; // ebx
  int v6; // edi
  int v8; // ecx
  bool v9; // zf
  int v10; // eax
  float v11; // xmm0_4
  CInputSystem::InputState_t *v12; // eax
  int v13; // eax
  __int32 v14; // eax
  ButtonCode_t v15; // [esp-4h] [ebp-10h]

  v4 = xKey;
  v5 = 0;
  v6 = nSample;
  switch ( xKey )
  {
    case XK_STICK1_UP:
    case XK_STICK1_DOWN:
      v8 = 6 * userId + 5;
      v9 = xKey == XK_STICK1_UP;
      goto LABEL_6;
    case XK_STICK1_LEFT:
    case XK_STICK1_RIGHT:
      v8 = 6 * userId + 4;
      v9 = xKey == XK_STICK1_LEFT;
      goto LABEL_6;
    case XK_STICK2_UP:
    case XK_STICK2_DOWN:
      v8 = 6 * userId + 7;
      v9 = xKey == XK_STICK2_UP;
      goto LABEL_6;
    case XK_STICK2_LEFT:
    case XK_STICK2_RIGHT:
      v8 = 6 * userId + 8;
      v9 = xKey == XK_STICK2_LEFT;
LABEL_6:
      v10 = nSample;
      if ( v9 )
        v10 = -nSample;
      v5 = 13107;
      v11 = (float)v10;
      if ( v8 != 28 )
      {
        v12 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
        v12->m_pAnalogDelta[v8] = (int)(float)(v11 - (float)v12->m_pAnalogValue[v8]);
        v12->m_pAnalogValue[v8] = (int)v11;
        v13 = v12->m_pAnalogDelta[v8];
        if ( v13 != 0 )
          CInputSystem::PostEvent(
            this,
            nType: 3,
            nTick: this->m_nLastSampleTick,
            nData: v8,
            nData2: (int)v11,
            nData3: v13);
        v4 = xKey;
      }
      break;
    default:
      break;
  }
  v14 = v4 + 26 * userId;
  this->m_appXKeys[0][v14].sample = nSample;
  if ( nSample <= v5 )
  {
    v6 = 0;
    this->m_appXKeys[0][v14].repeats = 0;
  }
  else
  {
    ++this->m_appXKeys[0][v14].repeats;
  }
  if ( this->m_appXKeys[0][v14].repeats <= 1 )
  {
    v15 = CInputSystem::XKeyToButtonCode(this, nPort: userId, nXKey: v4);
    if ( v6 != 0 )
      CInputSystem::PostButtonPressedEvent(
        this,
        nType: IE_ButtonPressed,
        nTick: this->m_nLastSampleTick,
        scanCode: v15,
        virtualCode: v15);
    else
      CInputSystem::PostButtonReleasedEvent(
        this,
        nType: IE_ButtonReleased,
        nTick: this->m_nLastSampleTick,
        scanCode: v15,
        virtualCode: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004970
// Name: private: void CInputSystem::ReadXDevice(struct CInputSystem::xdevice_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::ReadXDevice(CInputSystem *this, CInputSystem::xdevice_t *pXDevice)
{
  _XINPUT_STATE *v3; // edi
  int wButtons; // eax
  unsigned int i; // edi
  int v6; // ecx
  int v7; // eax
  int dpadLock; // edx
  int bLeftTrigger; // eax
  int userId; // ecx
  int v11; // edi
  char *v12; // eax
  int bRightTrigger; // eax
  int v14; // ecx
  int v15; // edi
  char *v16; // eax
  int m_nValue; // eax
  int sThumbLX; // edi
  int sThumbLY; // ecx
  int v20; // ecx
  int sThumbRX; // eax
  int sThumbRY; // ecx
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  float v28; // xmm0_4
  int v29; // eax
  int v30; // ecx
  float v31; // xmm0_4
  int v32; // eax
  int v33; // ecx
  float v34; // xmm0_4
  int v35; // ebx
  int v36; // edi
  int v37; // eax
  float v38; // xmm0_4
  CInputSystem::InputState_t *v39; // ecx
  int v40; // ecx
  char *v41; // eax
  xKey_t v42; // ebx
  int v43; // ebx
  int v44; // eax
  float v45; // xmm0_4
  CInputSystem::InputState_t *v46; // ecx
  int v47; // ecx
  char *v48; // eax
  xKey_t v49; // eax
  int v50; // ebx
  int v51; // edi
  int v52; // eax
  float v53; // xmm0_4
  CInputSystem::InputState_t *v54; // ecx
  int v55; // ecx
  char *v56; // eax
  xKey_t v57; // edi
  int v58; // edi
  int v59; // eax
  float v60; // xmm0_4
  CInputSystem::InputState_t *v61; // ecx
  int v62; // ecx
  char *v63; // eax
  int v64; // ebx
  xKey_t v65; // eax
  int v66; // ebx
  int v67; // edi
  int v68; // eax
  float v69; // xmm0_4
  CInputSystem::InputState_t *v70; // ecx
  int v71; // ecx
  char *v72; // eax
  xKey_t v73; // edi
  int v74; // edi
  int v75; // eax
  float v76; // xmm0_4
  CInputSystem::InputState_t *v77; // ecx
  int v78; // ecx
  char *v79; // eax
  xKey_t v80; // eax
  int v81; // ebx
  int v82; // edi
  int v83; // eax
  float v84; // xmm0_4
  CInputSystem::InputState_t *v85; // ecx
  int v86; // ecx
  char *v87; // eax
  xKey_t v88; // ebx
  int v89; // edi
  int v90; // eax
  float v91; // xmm0_4
  CInputSystem::InputState_t *v92; // ecx
  int v93; // ecx
  char *v94; // eax
  xKey_t v95; // eax
  ButtonCode_t v96; // [esp-4h] [ebp-24h]
  ButtonCode_t v97; // [esp-4h] [ebp-24h]
  ButtonCode_t v98; // [esp-4h] [ebp-24h]
  ButtonCode_t v99; // [esp-4h] [ebp-24h]
  ButtonCode_t v100; // [esp-4h] [ebp-24h]
  ButtonCode_t v101; // [esp-4h] [ebp-24h]
  ButtonCode_t v102; // [esp-4h] [ebp-24h]
  ButtonCode_t v103; // [esp-4h] [ebp-24h]
  ButtonCode_t v104; // [esp-4h] [ebp-24h]
  ButtonCode_t v105; // [esp-4h] [ebp-24h]
  int buttons; // [esp+Ch] [ebp-14h]
  int buttonsa; // [esp+Ch] [ebp-14h]
  int buttonsb; // [esp+Ch] [ebp-14h]
  int buttonsc; // [esp+Ch] [ebp-14h]
  _XINPUT_STATE *nX2; // [esp+10h] [ebp-10h]
  int nX2a; // [esp+10h] [ebp-10h]
  int nX2b; // [esp+10h] [ebp-10h]
  int nY1; // [esp+14h] [ebp-Ch]
  _XINPUT_STATE *newStatePtr; // [esp+18h] [ebp-8h]
  int newStatePtra; // [esp+18h] [ebp-8h]
  bool bDpadIsAxial; // [esp+1Fh] [ebp-1h]

  v3 = &pXDevice->states[pXDevice->newState];
  nX2 = &pXDevice->states[pXDevice->newState ^ 1];
  newStatePtr = v3;
  if ( pXDevice->states[pXDevice->newState].Gamepad.wButtons == 48 )
  {
    if ( pXDevice->quitTimeout != 0 )
    {
      if ( GetTickCount() - pXDevice->quitTimeout > 0x7D0 )
      {
        pXDevice->quitTimeout = 0;
        CInputSystem::ProcessEvent(this, uMsg: 0x464u, wParam: 0, lParam: (int)"quit_gameconsole");
      }
    }
    else
    {
      pXDevice->quitTimeout = GetTickCount();
    }
  }
  else
  {
    pXDevice->quitTimeout = 0;
  }
  if ( nX2->dwPacketNumber != v3->dwPacketNumber )
  {
    wButtons = v3->Gamepad.wButtons;
    buttons = wButtons ^ nX2->Gamepad.wButtons;
    if ( buttons != 0 )
    {
      bDpadIsAxial = (((wButtons & 0xF) - 1) & wButtons & 0xF) == 0;
      for ( i = 0; i < 28; i += 2 )
      {
        v6 = buttons & g_digitalXKeyTable[i / 2].xinput;
        if ( v6 != 0 )
        {
          v7 = (unsigned __int16)(v6 & newStatePtr->Gamepad.wButtons) != 0 ? 0x8000 : 0;
          if ( (v6 & 0xF) != 0 )
          {
            if ( bDpadIsAxial )
            {
              if ( v7 != 0 )
                pXDevice->dpadLock = v6;
            }
            else
            {
              dpadLock = pXDevice->dpadLock;
              if ( dpadLock != 0 && dpadLock != v6 )
                continue;
            }
          }
          CInputSystem::PostXKeyEvent(this, userId: pXDevice->userId, xKey: (xKey_t)dword_1001BDA4[i], nSample: v7);
        }
      }
    }
    if ( newStatePtr->Gamepad.bLeftTrigger <= 0x1Eu )
      newStatePtr->Gamepad.bLeftTrigger = 0;
    bLeftTrigger = newStatePtr->Gamepad.bLeftTrigger;
    if ( bLeftTrigger != nX2->Gamepad.bLeftTrigger )
    {
      userId = pXDevice->userId;
      v11 = (int)(float)((float)((float)bLeftTrigger * 32768.0) * 0.0039215689);
      v12 = (char *)this + 208 * pXDevice->userId;
      *((_DWORD *)v12 + 1536) = v11;
      if ( v11 <= 0 )
      {
        *((_DWORD *)v12 + 1535) = 0;
        v11 = 0;
      }
      else
      {
        ++*((_DWORD *)v12 + 1535);
      }
      if ( *((int *)v12 + 1535) <= 1 )
      {
        v96 = CInputSystem::XKeyToButtonCode(this, nPort: userId, nXKey: 15);
        if ( v11 != 0 )
          CInputSystem::PostButtonPressedEvent(
            this,
            nType: IE_ButtonPressed,
            nTick: this->m_nLastSampleTick,
            scanCode: v96,
            virtualCode: v96);
        else
          CInputSystem::PostButtonReleasedEvent(
            this,
            nType: IE_ButtonReleased,
            nTick: this->m_nLastSampleTick,
            scanCode: v96,
            virtualCode: v96);
      }
    }
    if ( newStatePtr->Gamepad.bRightTrigger <= 0x1Eu )
      newStatePtr->Gamepad.bRightTrigger = 0;
    bRightTrigger = newStatePtr->Gamepad.bRightTrigger;
    if ( bRightTrigger != nX2->Gamepad.bRightTrigger )
    {
      v14 = pXDevice->userId;
      v15 = (int)(float)((float)((float)bRightTrigger * 32768.0) * 0.0039215689);
      v16 = (char *)this + 208 * pXDevice->userId;
      *((_DWORD *)v16 + 1538) = v15;
      if ( v15 <= 0 )
      {
        *((_DWORD *)v16 + 1537) = 0;
        v15 = 0;
      }
      else
      {
        ++*((_DWORD *)v16 + 1537);
      }
      if ( *((int *)v16 + 1537) <= 1 )
      {
        v97 = CInputSystem::XKeyToButtonCode(this, nPort: v14, nXKey: 16);
        if ( v15 != 0 )
          CInputSystem::PostButtonPressedEvent(
            this,
            nType: IE_ButtonPressed,
            nTick: this->m_nLastSampleTick,
            scanCode: v97,
            virtualCode: v97);
        else
          CInputSystem::PostButtonReleasedEvent(
            this,
            nType: IE_ButtonReleased,
            nTick: this->m_nLastSampleTick,
            scanCode: v97,
            virtualCode: v97);
      }
    }
    if ( joy_deadzone_mode.m_pParent != nullptr )
      m_nValue = joy_deadzone_mode.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue != 0 )
    {
      sThumbLX = newStatePtr->Gamepad.sThumbLX;
      sThumbLY = newStatePtr->Gamepad.sThumbLY;
      if ( sThumbLX < -pXDevice->stickThreshold[0]
        || sThumbLX > pXDevice->stickThreshold[0]
        || sThumbLY < -pXDevice->stickThreshold[1]
        || sThumbLY > pXDevice->stickThreshold[1] )
      {
        nY1 = newStatePtr->Gamepad.sThumbLY;
      }
      else
      {
        sThumbLX = 0;
        nY1 = 0;
      }
      v20 = pXDevice->stickThreshold[2];
      sThumbRX = newStatePtr->Gamepad.sThumbRX;
      nX2a = newStatePtr->Gamepad.sThumbRY;
      if ( sThumbRX < -v20 || sThumbRX > v20 )
      {
        sThumbRY = newStatePtr->Gamepad.sThumbRY;
      }
      else
      {
        sThumbRY = newStatePtr->Gamepad.sThumbRY;
        if ( nX2a >= -pXDevice->stickThreshold[3] && nX2a <= pXDevice->stickThreshold[3] )
        {
          nX2b = 0;
          newStatePtra = 0;
          goto LABEL_79;
        }
      }
      nX2b = newStatePtr->Gamepad.sThumbRX;
      goto LABEL_78;
    }
    v23 = pXDevice->stickThreshold[0];
    v24 = newStatePtr->Gamepad.sThumbLX;
    if ( v24 < -v23 )
    {
      v25 = v23 + v24;
    }
    else
    {
      if ( v24 <= v23 )
      {
        sThumbLX = 0;
LABEL_63:
        v26 = pXDevice->stickThreshold[1];
        v27 = newStatePtr->Gamepad.sThumbLY;
        v28 = pXDevice->stickScale[1];
        if ( v27 < -v26 )
        {
          nY1 = (int)(float)((float)(v26 + v27) * v28);
        }
        else if ( v27 > v26 )
        {
          nY1 = (int)(float)((float)(v27 - v26) * v28);
        }
        else
        {
          nY1 = 0;
        }
        v29 = newStatePtr->Gamepad.sThumbRX;
        v30 = pXDevice->stickThreshold[2];
        v31 = pXDevice->stickScale[2];
        if ( v29 < -v30 )
        {
          nX2b = (int)(float)((float)(v30 + v29) * v31);
        }
        else if ( v29 > v30 )
        {
          nX2b = (int)(float)((float)(v29 - v30) * v31);
        }
        else
        {
          nX2b = 0;
        }
        v32 = newStatePtr->Gamepad.sThumbRY;
        v33 = pXDevice->stickThreshold[3];
        v34 = pXDevice->stickScale[3];
        if ( v32 >= -v33 )
        {
          if ( v32 > v33 )
            newStatePtra = (int)(float)((float)(v32 - v33) * v34);
          else
            newStatePtra = 0;
LABEL_79:
          if ( sThumbLX >= 0 )
          {
            if ( sThumbLX <= 0 )
            {
              v42 = XK_NULL;
              goto LABEL_104;
            }
            v43 = pXDevice->userId;
            v44 = 6 * pXDevice->userId + 4;
            buttonsa = sThumbLX;
            v45 = (float)sThumbLX;
            if ( 6 * pXDevice->userId != 24 )
            {
              v46 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
              v46->m_pAnalogDelta[v44] = (int)(float)(v45 - (float)v46->m_pAnalogValue[v44]);
              v46->m_pAnalogValue[v44] = (int)v45;
              v47 = v46->m_pAnalogDelta[v44];
              if ( v47 != 0 )
                CInputSystem::PostEvent(
                  this,
                  nType: 3,
                  nTick: this->m_nLastSampleTick,
                  nData: 6 * v43 + 4,
                  nData2: (int)v45,
                  nData3: v47);
            }
            v48 = (char *)this + 208 * v43;
            *((_DWORD *)v48 + 1546) = sThumbLX;
            if ( sThumbLX <= 13107 )
            {
              *((_DWORD *)v48 + 1545) = 0;
              buttonsa = 0;
            }
            else
            {
              ++*((_DWORD *)v48 + 1545);
            }
            if ( *((int *)v48 + 1545) <= 1 )
            {
              v99 = CInputSystem::XKeyToButtonCode(this, nPort: v43, nXKey: 20);
              if ( buttonsa != 0 )
              {
                CInputSystem::PostButtonPressedEvent(
                  this,
                  nType: IE_ButtonPressed,
                  nTick: this->m_nLastSampleTick,
                  scanCode: v99,
                  virtualCode: v99);
                v42 = XK_STICK1_RIGHT;
                goto LABEL_104;
              }
              CInputSystem::PostButtonReleasedEvent(
                this,
                nType: IE_ButtonReleased,
                nTick: this->m_nLastSampleTick,
                scanCode: v99,
                virtualCode: v99);
            }
            v42 = XK_STICK1_RIGHT;
            goto LABEL_104;
          }
          v35 = pXDevice->userId;
          v36 = -sThumbLX;
          v37 = 6 * pXDevice->userId + 4;
          v38 = (float)-v36;
          if ( 6 * pXDevice->userId != 24 )
          {
            v39 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
            v39->m_pAnalogDelta[v37] = (int)(float)(v38 - (float)v39->m_pAnalogValue[v37]);
            v39->m_pAnalogValue[v37] = (int)v38;
            v40 = v39->m_pAnalogDelta[v37];
            if ( v40 != 0 )
              CInputSystem::PostEvent(
                this,
                nType: 3,
                nTick: this->m_nLastSampleTick,
                nData: 6 * v35 + 4,
                nData2: (int)v38,
                nData3: v40);
          }
          v41 = (char *)this + 208 * v35;
          *((_DWORD *)v41 + 1544) = v36;
          if ( v36 <= 13107 )
          {
            v36 = 0;
            *((_DWORD *)v41 + 1543) = 0;
          }
          else
          {
            ++*((_DWORD *)v41 + 1543);
          }
          if ( *((int *)v41 + 1543) <= 1 )
          {
            v98 = CInputSystem::XKeyToButtonCode(this, nPort: v35, nXKey: 19);
            if ( v36 != 0 )
            {
              CInputSystem::PostButtonPressedEvent(
                this,
                nType: IE_ButtonPressed,
                nTick: this->m_nLastSampleTick,
                scanCode: v98,
                virtualCode: v98);
              v42 = XK_STICK1_LEFT;
LABEL_104:
              v49 = pXDevice->lastStickKeys[0];
              if ( v49 != XK_NULL && v49 != v42 )
                CInputSystem::PostXKeyEvent(this, userId: pXDevice->userId, xKey: v49, nSample: 0);
              pXDevice->lastStickKeys[0] = v42;
              if ( nY1 >= 0 )
              {
                if ( nY1 <= 0 )
                {
                  v57 = XK_NULL;
                  goto LABEL_132;
                }
                v58 = pXDevice->userId;
                v59 = 6 * pXDevice->userId + 5;
                v60 = (float)-nY1;
                if ( 6 * pXDevice->userId != 23 )
                {
                  v61 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                  v61->m_pAnalogDelta[v59] = (int)(float)(v60 - (float)v61->m_pAnalogValue[v59]);
                  v61->m_pAnalogValue[v59] = (int)v60;
                  v62 = v61->m_pAnalogDelta[v59];
                  if ( v62 != 0 )
                    CInputSystem::PostEvent(
                      this,
                      nType: 3,
                      nTick: this->m_nLastSampleTick,
                      nData: 6 * v58 + 5,
                      nData2: (int)v60,
                      nData3: v62);
                }
                v63 = (char *)this + 208 * v58;
                *((_DWORD *)v63 + 1540) = nY1;
                if ( nY1 <= 13107 )
                {
                  v64 = 0;
                  *((_DWORD *)v63 + 1539) = 0;
                }
                else
                {
                  ++*((_DWORD *)v63 + 1539);
                  v64 = nY1;
                }
                if ( *((int *)v63 + 1539) <= 1 )
                {
                  v101 = CInputSystem::XKeyToButtonCode(this, nPort: v58, nXKey: 17);
                  if ( v64 != 0 )
                  {
                    CInputSystem::PostButtonPressedEvent(
                      this,
                      nType: IE_ButtonPressed,
                      nTick: this->m_nLastSampleTick,
                      scanCode: v101,
                      virtualCode: v101);
                    v57 = XK_STICK1_UP;
                    goto LABEL_132;
                  }
                  CInputSystem::PostButtonReleasedEvent(
                    this,
                    nType: IE_ButtonReleased,
                    nTick: this->m_nLastSampleTick,
                    scanCode: v101,
                    virtualCode: v101);
                }
                v57 = XK_STICK1_UP;
                goto LABEL_132;
              }
              v50 = pXDevice->userId;
              v51 = -nY1;
              v52 = 6 * pXDevice->userId + 5;
              v53 = (float)-nY1;
              if ( 6 * pXDevice->userId != 23 )
              {
                v54 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                v54->m_pAnalogDelta[v52] = (int)(float)(v53 - (float)v54->m_pAnalogValue[v52]);
                v54->m_pAnalogValue[v52] = (int)v53;
                v55 = v54->m_pAnalogDelta[v52];
                if ( v55 != 0 )
                  CInputSystem::PostEvent(
                    this,
                    nType: 3,
                    nTick: this->m_nLastSampleTick,
                    nData: v52,
                    nData2: (int)v53,
                    nData3: v55);
              }
              v56 = (char *)this + 208 * v50;
              *((_DWORD *)v56 + 1542) = v51;
              if ( v51 <= 13107 )
              {
                v51 = 0;
                *((_DWORD *)v56 + 1541) = 0;
              }
              else
              {
                ++*((_DWORD *)v56 + 1541);
              }
              if ( *((int *)v56 + 1541) <= 1 )
              {
                v100 = CInputSystem::XKeyToButtonCode(this, nPort: v50, nXKey: 18);
                if ( v51 != 0 )
                {
                  CInputSystem::PostButtonPressedEvent(
                    this,
                    nType: IE_ButtonPressed,
                    nTick: this->m_nLastSampleTick,
                    scanCode: v100,
                    virtualCode: v100);
                  v57 = XK_STICK1_DOWN;
LABEL_132:
                  v65 = pXDevice->lastStickKeys[1];
                  if ( v65 != XK_NULL && v65 != v57 )
                    CInputSystem::PostXKeyEvent(this, userId: pXDevice->userId, xKey: v65, nSample: 0);
                  pXDevice->lastStickKeys[1] = v57;
                  if ( nX2b >= 0 )
                  {
                    if ( nX2b <= 0 )
                    {
                      v73 = XK_NULL;
                      goto LABEL_160;
                    }
                    v74 = pXDevice->userId;
                    v75 = 6 * pXDevice->userId + 8;
                    buttonsb = nX2b;
                    v76 = (float)nX2b;
                    if ( 6 * pXDevice->userId != 20 )
                    {
                      v77 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                      v77->m_pAnalogDelta[v75] = (int)(float)(v76 - (float)v77->m_pAnalogValue[v75]);
                      v77->m_pAnalogValue[v75] = (int)v76;
                      v78 = v77->m_pAnalogDelta[v75];
                      if ( v78 != 0 )
                        CInputSystem::PostEvent(
                          this,
                          nType: 3,
                          nTick: this->m_nLastSampleTick,
                          nData: v75,
                          nData2: (int)v76,
                          nData3: v78);
                    }
                    v79 = (char *)this + 208 * v74;
                    *((_DWORD *)v79 + 1554) = nX2b;
                    if ( nX2b <= 13107 )
                    {
                      *((_DWORD *)v79 + 1553) = 0;
                      buttonsb = 0;
                    }
                    else
                    {
                      ++*((_DWORD *)v79 + 1553);
                    }
                    if ( *((int *)v79 + 1553) <= 1 )
                    {
                      v103 = CInputSystem::XKeyToButtonCode(this, nPort: v74, nXKey: 24);
                      if ( buttonsb != 0 )
                      {
                        CInputSystem::PostButtonPressedEvent(
                          this,
                          nType: IE_ButtonPressed,
                          nTick: this->m_nLastSampleTick,
                          scanCode: v103,
                          virtualCode: v103);
                        v73 = XK_STICK2_RIGHT;
                        goto LABEL_160;
                      }
                      CInputSystem::PostButtonReleasedEvent(
                        this,
                        nType: IE_ButtonReleased,
                        nTick: this->m_nLastSampleTick,
                        scanCode: v103,
                        virtualCode: v103);
                    }
                    v73 = XK_STICK2_RIGHT;
                    goto LABEL_160;
                  }
                  v66 = pXDevice->userId;
                  v67 = -nX2b;
                  v68 = 6 * pXDevice->userId + 8;
                  v69 = (float)nX2b;
                  if ( 6 * pXDevice->userId != 20 )
                  {
                    v70 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                    v70->m_pAnalogDelta[v68] = (int)(float)(v69 - (float)v70->m_pAnalogValue[v68]);
                    v70->m_pAnalogValue[v68] = (int)v69;
                    v71 = v70->m_pAnalogDelta[v68];
                    if ( v71 != 0 )
                      CInputSystem::PostEvent(
                        this,
                        nType: 3,
                        nTick: this->m_nLastSampleTick,
                        nData: v68,
                        nData2: (int)v69,
                        nData3: v71);
                  }
                  v72 = (char *)this + 208 * v66;
                  *((_DWORD *)v72 + 1552) = v67;
                  if ( v67 <= 13107 )
                  {
                    v67 = 0;
                    *((_DWORD *)v72 + 1551) = 0;
                  }
                  else
                  {
                    ++*((_DWORD *)v72 + 1551);
                  }
                  if ( *((int *)v72 + 1551) <= 1 )
                  {
                    v102 = CInputSystem::XKeyToButtonCode(this, nPort: v66, nXKey: 23);
                    if ( v67 != 0 )
                    {
                      CInputSystem::PostButtonPressedEvent(
                        this,
                        nType: IE_ButtonPressed,
                        nTick: this->m_nLastSampleTick,
                        scanCode: v102,
                        virtualCode: v102);
                      v73 = XK_STICK2_LEFT;
LABEL_160:
                      v80 = pXDevice->lastStickKeys[2];
                      if ( v80 != XK_NULL && v80 != v73 )
                        CInputSystem::PostXKeyEvent(this, userId: pXDevice->userId, xKey: v80, nSample: 0);
                      pXDevice->lastStickKeys[2] = v73;
                      if ( newStatePtra >= 0 )
                      {
                        if ( newStatePtra <= 0 )
                        {
                          v88 = XK_NULL;
                          goto LABEL_188;
                        }
                        v89 = pXDevice->userId;
                        v90 = 6 * pXDevice->userId + 7;
                        buttonsc = newStatePtra;
                        v91 = (float)-newStatePtra;
                        if ( 6 * pXDevice->userId != 21 )
                        {
                          v92 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                          v92->m_pAnalogDelta[v90] = (int)(float)(v91 - (float)v92->m_pAnalogValue[v90]);
                          v92->m_pAnalogValue[v90] = (int)v91;
                          v93 = v92->m_pAnalogDelta[v90];
                          if ( v93 != 0 )
                            CInputSystem::PostEvent(
                              this,
                              nType: 3,
                              nTick: this->m_nLastSampleTick,
                              nData: v90,
                              nData2: (int)v91,
                              nData3: v93);
                        }
                        v94 = (char *)this + 208 * v89;
                        *((_DWORD *)v94 + 1548) = newStatePtra;
                        if ( newStatePtra <= 13107 )
                        {
                          *((_DWORD *)v94 + 1547) = 0;
                          buttonsc = 0;
                        }
                        else
                        {
                          ++*((_DWORD *)v94 + 1547);
                        }
                        if ( *((int *)v94 + 1547) <= 1 )
                        {
                          v105 = CInputSystem::XKeyToButtonCode(this, nPort: v89, nXKey: 21);
                          if ( buttonsc != 0 )
                          {
                            CInputSystem::PostButtonPressedEvent(
                              this,
                              nType: IE_ButtonPressed,
                              nTick: this->m_nLastSampleTick,
                              scanCode: v105,
                              virtualCode: v105);
                            v88 = XK_STICK2_UP;
                            goto LABEL_188;
                          }
                          CInputSystem::PostButtonReleasedEvent(
                            this,
                            nType: IE_ButtonReleased,
                            nTick: this->m_nLastSampleTick,
                            scanCode: v105,
                            virtualCode: v105);
                        }
                        v88 = XK_STICK2_UP;
                        goto LABEL_188;
                      }
                      v81 = pXDevice->userId;
                      v82 = -newStatePtra;
                      v83 = 6 * pXDevice->userId + 7;
                      v84 = (float)-newStatePtra;
                      if ( 6 * pXDevice->userId != 21 )
                      {
                        v85 = &this->m_InputState[(unsigned __int8)this->m_bIsPolling];
                        v85->m_pAnalogDelta[v83] = (int)(float)(v84 - (float)v85->m_pAnalogValue[v83]);
                        v85->m_pAnalogValue[v83] = (int)v84;
                        v86 = v85->m_pAnalogDelta[v83];
                        if ( v86 != 0 )
                          CInputSystem::PostEvent(
                            this,
                            nType: 3,
                            nTick: this->m_nLastSampleTick,
                            nData: v83,
                            nData2: (int)v84,
                            nData3: v86);
                      }
                      v87 = (char *)this + 208 * v81;
                      *((_DWORD *)v87 + 1550) = v82;
                      if ( v82 <= 13107 )
                      {
                        v82 = 0;
                        *((_DWORD *)v87 + 1549) = 0;
                      }
                      else
                      {
                        ++*((_DWORD *)v87 + 1549);
                      }
                      if ( *((int *)v87 + 1549) <= 1 )
                      {
                        v104 = CInputSystem::XKeyToButtonCode(this, nPort: v81, nXKey: 22);
                        if ( v82 != 0 )
                        {
                          CInputSystem::PostButtonPressedEvent(
                            this,
                            nType: IE_ButtonPressed,
                            nTick: this->m_nLastSampleTick,
                            scanCode: v104,
                            virtualCode: v104);
                          v88 = XK_STICK2_DOWN;
LABEL_188:
                          v95 = pXDevice->lastStickKeys[3];
                          if ( v95 != XK_NULL && v95 != v88 )
                            CInputSystem::PostXKeyEvent(this, userId: pXDevice->userId, xKey: v95, nSample: 0);
                          pXDevice->lastStickKeys[3] = v88;
                          pXDevice->newState ^= 1u;
                          return;
                        }
                        CInputSystem::PostButtonReleasedEvent(
                          this,
                          nType: IE_ButtonReleased,
                          nTick: this->m_nLastSampleTick,
                          scanCode: v104,
                          virtualCode: v104);
                      }
                      v88 = XK_STICK2_DOWN;
                      goto LABEL_188;
                    }
                    CInputSystem::PostButtonReleasedEvent(
                      this,
                      nType: IE_ButtonReleased,
                      nTick: this->m_nLastSampleTick,
                      scanCode: v102,
                      virtualCode: v102);
                  }
                  v73 = XK_STICK2_LEFT;
                  goto LABEL_160;
                }
                CInputSystem::PostButtonReleasedEvent(
                  this,
                  nType: IE_ButtonReleased,
                  nTick: this->m_nLastSampleTick,
                  scanCode: v100,
                  virtualCode: v100);
              }
              v57 = XK_STICK1_DOWN;
              goto LABEL_132;
            }
            CInputSystem::PostButtonReleasedEvent(
              this,
              nType: IE_ButtonReleased,
              nTick: this->m_nLastSampleTick,
              scanCode: v98,
              virtualCode: v98);
          }
          v42 = XK_STICK1_LEFT;
          goto LABEL_104;
        }
        sThumbRY = (int)(float)((float)(v33 + v32) * v34);
LABEL_78:
        newStatePtra = sThumbRY;
        goto LABEL_79;
      }
      v25 = v24 - v23;
    }
    sThumbLX = (int)(float)((float)v25 * pXDevice->stickScale[0]);
    goto LABEL_63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005540
// Name: private: void CInputSystem::InitializeXDevices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::InitializeXDevices(CInputSystem *this)
{
  int v2; // eax
  DWORD (__stdcall *XInputGetCapabilities)(DWORD, DWORD, XINPUT_CAPABILITIES *); // eax
  CInputSystem::xdevice_t *m_XDevices; // ebx
  int i; // esi
  struct CSysModule *m_pXInputDLL; // [esp-8h] [ebp-10h]

  v2 = _KeyValuesSystem();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 28))(a1: v2, a2: "INPUTSWAPAB", a3: 0);
  m_pXInputDLL = this->m_pXInputDLL;
  this->m_nJoystickCount = 0;
  PC_XInputGetState = (unsigned int (__stdcall *)(unsigned int, _XINPUT_STATE *))GetProcAddress(
                                                                                   hModule: (HMODULE)m_pXInputDLL,
                                                                                   lpProcName: "XInputGetState");
  PC_XInputSetState = (unsigned int (__stdcall *)(unsigned int, _XINPUT_VIBRATION *))GetProcAddress(
                                                                                       hModule: (HMODULE)this->m_pXInputDLL,
                                                                                       lpProcName: "XInputSetState");
  XInputGetCapabilities = (DWORD (__stdcall *)(DWORD, DWORD, XINPUT_CAPABILITIES *))GetProcAddress(
                                                                                      hModule: (HMODULE)this->m_pXInputDLL,
                                                                                      lpProcName: "XInputGetCapabilities");
  PC_XInputGetCapabilities = XInputGetCapabilities;
  if ( PC_XInputGetState != nullptr && PC_XInputSetState != nullptr && XInputGetCapabilities != nullptr )
  {
    m_XDevices = this->m_XDevices;
    for ( i = 0; i < 4; ++i )
      CInputSystem::OpenXDevice(this, pXDevice: m_XDevices++, userId: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055E0
// Name: private: void CInputSystem::PollXDevices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputSystem::PollXDevices(CInputSystem *this)
{
  int v2; // ebx
  CInputSystem::xdevice_t *m_XDevices; // edi
  unsigned int State; // eax
  int v5; // ebx
  int v6; // eax
  int userId; // [esp+Ch] [ebp-4h]

  v2 = 0;
  m_XDevices = this->m_XDevices;
  userId = 0;
  do
  {
    State = PC_XInputGetState(a1: v2, a2: &m_XDevices->states[m_XDevices->newState]);
    if ( State != 0 )
    {
      if ( State == 1167 && m_XDevices->active )
      {
        v5 = m_XDevices->userId;
        v6 = 32 * m_XDevices->userId;
        m_XDevices->userId = -1;
        m_XDevices->active = false;
        --this->m_nJoystickCount;
        CInputSystem::ReleaseAllButtons(this, nFirstButton: v6 + 228, nLastButton: v6 + 259);
        CInputSystem::ZeroAnalogState(this, nFirstState: 6 * v5 + 8, nLastState: 6 * v5 + 7);
        memset(dst: (unsigned __int8 *)this->m_appXKeys[v5], value: 0, count: sizeof(this->m_appXKeys[v5]));
        CInputSystem::PostEvent(this, nType: 102, nTick: this->m_nLastSampleTick, nData: v5, nData2: 0, nData3: 0);
        v2 = userId;
      }
    }
    else
    {
      if ( !m_XDevices->active )
      {
        CInputSystem::OpenXDevice(this, pXDevice: m_XDevices, userId: v2);
        CInputSystem::PostEvent(this, nType: 101, nTick: this->m_nLastSampleTick, nData: v2, nData2: 0, nData3: 0);
      }
      CInputSystem::ReadXDevice(this, pXDevice: m_XDevices);
      if ( m_XDevices->pendingRumbleUpdate )
      {
        PC_XInputSetState(a1: m_XDevices->userId, a2: &m_XDevices->vibration);
        m_XDevices->pendingRumbleUpdate = false;
      }
    }
    ++v2;
    ++m_XDevices;
    userId = v2;
  }
  while ( v2 < 4 );
}
