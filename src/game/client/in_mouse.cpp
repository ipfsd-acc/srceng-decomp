// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/in_mouse.cpp
// Functions: 33
// ============================================================

#include "game\client\in_mouse.h"

//------------------------------------------------------------------------------
// Address: 0x101183C0
// Name: public: virtual void CInput::ActivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ActivateMouse(CInput *this)
{
  void (__thiscall *ResetMouse)(struct CInput *); // eax
  int rawX; // [esp+4h] [ebp-8h] BYREF
  int rawY; // [esp+8h] [ebp-4h] BYREF

  if ( !this->m_fMouseActive && this->m_fMouseInitialized )
  {
    if ( this->m_fMouseParmsValid )
      this->m_fRestoreSPI = SystemParametersInfoA(
                              uiAction: 4u,
                              uiParam: 0,
                              pvParam: this->m_rgNewMouseParms,
                              fWinIni: 0);
    ResetMouse = this->ResetMouse;
    this->m_fMouseActive = true;
    ResetMouse(this);
    g_pInputStackSystem->SetCursorIcon(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: nullptr);
    CInput::GetPerUser(this, nSlot: 0)->m_flAccumulatedMouseXMovement = 0.0;
    CInput::GetPerUser(this, nSlot: 0)->m_flAccumulatedMouseYMovement = 0.0;
    inputsystem->GetRawMouseAccumulators(this: inputsystem, a2: &rawX, a3: &rawY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118460
// Name: public: virtual void CInput::DeactivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::DeactivateMouse(CInput *this)
{
  IInputStackSystem_vtbl *v2; // edi
  InputCursorHandle_t__ *v3; // eax

  if ( this->m_fMouseActive && this->m_fMouseInitialized )
  {
    if ( this->m_fRestoreSPI )
      SystemParametersInfoA(uiAction: 4u, uiParam: 0, pvParam: this->m_rgOrigMouseParms, fWinIni: 0);
    this->m_fMouseActive = false;
    v2 = g_pInputStackSystem->__vftable;
    v3 = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 1);
    v2->SetCursorIcon(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: v3);
    CInput::GetPerUser(this, nSlot: -1)->m_flAccumulatedMouseXMovement = 0.0;
    CInput::GetPerUser(this, nSlot: -1)->m_flAccumulatedMouseYMovement = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101184E0
// Name: protected: void CInput::CheckMouseAcclerationVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::CheckMouseAcclerationVars(CInput *this)
{
  int v2; // esi
  char v3; // bl
  int v4; // ecx
  const char *v5; // eax
  char sz[256]; // [esp+4h] [ebp-10Ch] BYREF
  int values[3]; // [esp+104h] [ebp-Ch]

  if ( this->m_fMouseActive && this->m_fMouseInitialized && this->m_fMouseParmsValid && this->m_fRestoreSPI )
  {
    v2 = 0;
    if ( m_mousespeed.m_pParent != nullptr )
      values[2] = m_mousespeed.m_pParent->m_Value.m_nValue;
    else
      values[2] = 0;
    if ( m_mouseaccel1.m_pParent != nullptr )
      values[0] = m_mouseaccel1.m_pParent->m_Value.m_nValue;
    else
      values[0] = 0;
    if ( m_mouseaccel2.m_pParent != nullptr )
      values[1] = m_mouseaccel2.m_pParent->m_Value.m_nValue;
    else
      values[1] = 0;
    v3 = 0;
    do
    {
      if ( this->m_rgCheckMouseParam[v2] )
      {
        v4 = values[v2];
        if ( v4 != this->m_rgNewMouseParms[v2] )
        {
          v3 = 1;
          this->m_rgNewMouseParms[v2] = v4;
          if ( v2 != 0 )
          {
            if ( v2 == 1 )
              v5 = "m_mouseaccel2";
            else
              v5 = "m_mousespeed";
          }
          else
          {
            v5 = "m_mouseaccel1";
          }
          V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "Mouse parameter '%s' set to %i\n", v5, v4);
          DevMsg(a1: "%s", sz);
        }
      }
      ++v2;
    }
    while ( v2 < 3 );
    if ( v3 != 0 )
      this->m_fRestoreSPI = SystemParametersInfoA(
                              uiAction: 4u,
                              uiParam: 0,
                              pvParam: this->m_rgNewMouseParms,
                              fWinIni: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101185E0
// Name: protected: void CInput::Init_Mouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::Init_Mouse(CInput *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  bool v5; // al
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nomouse") == 0 )
  {
    CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseXPosition = 0.0;
    CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseYPosition = 0.0;
    this->m_fMouseInitialized = true;
    this->m_fMouseParmsValid = false;
    v4 = _CommandLine(a1: v3);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-useforcedmparms") != 0 )
    {
      v5 = SystemParametersInfoA(uiAction: 3u, uiParam: 0, pvParam: this->m_rgOrigMouseParms, fWinIni: 0);
      this->m_fMouseParmsValid = v5;
      if ( v5 )
      {
        v7 = _CommandLine(a1: v6);
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-noforcemspd") != 0 )
        {
          v8 = this->m_rgOrigMouseParms[2];
          this->m_rgNewMouseParms[2] = v8;
        }
        else
        {
          this->m_rgCheckMouseParam[2] = true;
        }
        v9 = _CommandLine(a1: v8);
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-noforcemaccel") != 0 )
        {
          v10 = this->m_rgOrigMouseParms[1];
          this->m_rgNewMouseParms[0] = this->m_rgOrigMouseParms[0];
          this->m_rgNewMouseParms[1] = v10;
        }
        else
        {
          *(_WORD *)this->m_rgCheckMouseParam = 257;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101186B0
// Name: protected: virtual void CInput::GetWindowCenter(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::GetWindowCenter(CInput *this, int *x, int *y)
{
  int v3; // eax
  int h; // [esp+0h] [ebp-8h] BYREF
  int w; // [esp+4h] [ebp-4h] BYREF

  engine->GetScreenSize(this: engine, a2: &w, a3: &h);
  v3 = h;
  *x = w >> 1;
  *y = v3 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x101186F0
// Name: protected: void CInput::ScaleMouse(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ScaleMouse(CInput *this, int nSlot, float *x, float *y)
{
  CHud *Hud; // eax
  CHud *v7; // eax
  float m_fValue; // xmm0_4
  int m_nValue; // eax
  float v10; // xmm0_4
  int v11; // eax
  float mx; // [esp+8h] [ebp-4h]
  float accelerated_sensitivity_max; // [esp+14h] [ebp+8h]
  float my; // [esp+18h] [ebp+Ch]
  float mouse_sensitivity; // [esp+1Ch] [ebp+10h]

  mx = *x;
  my = *y;
  Hud = GetHud(nSlot);
  if ( CHud::GetSensitivity(this: Hud) == 0.0 )
  {
    m_fValue = sensitivity.m_pParent->m_Value.m_fValue;
  }
  else
  {
    v7 = GetHud(nSlot);
    mouse_sensitivity = CHud::GetSensitivity(this: v7);
    m_fValue = mouse_sensitivity;
  }
  if ( m_customaccel.m_pParent == nullptr )
    goto LABEL_9;
  m_nValue = m_customaccel.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 1 && m_nValue != 2 )
  {
    if ( m_nValue == 3 )
    {
      __libm_sse2_pow();
      m_fValue = (float)((float)(my * my) + (float)(mx * mx)) * m_fValue;
    }
LABEL_9:
    *x = *x * m_fValue;
    *y = *y * m_fValue;
    return;
  }
  accelerated_sensitivity_max = m_customaccel_max.m_pParent->m_Value.m_fValue;
  __libm_sse2_pow();
  v10 = (float)(fsqrt((float)(my * my) + (float)(mx * mx)) * m_customaccel_scale.m_pParent->m_Value.m_fValue) + m_fValue;
  if ( accelerated_sensitivity_max > 0.000099999997 && v10 > accelerated_sensitivity_max )
    v10 = accelerated_sensitivity_max;
  *x = *x * v10;
  *y = *y * v10;
  if ( m_customaccel.m_pParent != nullptr )
  {
    v11 = m_customaccel.m_pParent->m_Value.m_nValue;
    if ( v11 == 2 || v11 == 4 )
    {
      *x = m_yaw.m_pParent->m_Value.m_fValue * *x;
      *y = ((double (__thiscall *)(ConVar_ServerBounded *))m_pitch->GetFloat)(a1: m_pitch) * *y;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101188C0
// Name: protected: virtual void CInput::ApplyMouse(int,class QAngle __near &,class CUserCmd __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ApplyMouse(
        CInput *this,
        int nSlot,
        QAngle *viewangles,
        CUserCmd *cmd,
        float mouse_x,
        float mouse_y)
{
  const CInput::PerUserInput_t *PerUser; // ebx
  float v8; // xmm0_4
  float m_fValue; // xmm0_4
  float v10; // xmm0_4

  PerUser = CInput::GetPerUser(this, nSlot);
  if ( (kbutton_t::GetPerUser(this: &in_strafe, nSlot)->state & 1) != 0
    || lookstrafe.m_pParent != nullptr && lookstrafe.m_pParent->m_Value.m_nValue != 0 )
  {
    cmd->sidemove = (float)(m_side.m_pParent->m_Value.m_fValue * mouse_x) + cmd->sidemove;
  }
  else if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
         && thirdperson_platformer.m_pParent != nullptr
         && thirdperson_platformer.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( mouse_x != 0.0 )
    {
      v8 = PerUser->m_vecCameraOffset.y - (float)(m_yaw.m_pParent->m_Value.m_fValue * mouse_x);
      PerUser->m_vecCameraOffset.y = v8;
      ConVar::SetValue(this: (ConVar *)&cam_idealyaw.IConVar, value: v8 - viewangles->y);
    }
  }
  else
  {
    viewangles->y = viewangles->y - (float)(m_yaw.m_pParent->m_Value.m_fValue * mouse_x);
  }
  if ( (kbutton_t::GetPerUser(this: &in_strafe, nSlot)->state & 1) != 0 )
  {
    cmd->forwardmove = cmd->forwardmove - (float)(m_forward.m_pParent->m_Value.m_fValue * mouse_y);
  }
  else if ( this->CAM_IsThirdPerson(this, a2: -1) != 0
         && thirdperson_platformer.m_pParent != nullptr
         && thirdperson_platformer.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( mouse_y != 0.0 )
    {
      PerUser->m_vecCameraOffset.x = ((double (__thiscall *)(ConVar_ServerBounded *))m_pitch->GetFloat)(a1: m_pitch)
                                   * mouse_y
                                   + PerUser->m_vecCameraOffset.x;
      ConVar::SetValue(this: (ConVar *)&cam_idealpitch.IConVar, value: PerUser->m_vecCameraOffset.x - viewangles->x);
    }
  }
  else
  {
    viewangles->x = ((double (__thiscall *)(ConVar_ServerBounded *))m_pitch->GetFloat)(a1: m_pitch) * mouse_y
                  + viewangles->x;
    m_fValue = cl_pitchdown.m_pParent->m_Value.m_fValue;
    if ( viewangles->x > m_fValue )
      viewangles->x = m_fValue;
    LODWORD(v10) = LODWORD(cl_pitchup.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
    if ( v10 > viewangles->x )
      viewangles->x = v10;
  }
  cmd->mousedx = (int)mouse_x;
  cmd->mousedy = (int)mouse_y;
}

//------------------------------------------------------------------------------
// Address: 0x10118AB0
// Name: protected: void CInput::GetMousePos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::GetMousePos(CInput *this, int *ox, int *oy)
{
  g_pInputSystem->GetCursorPosition(this: g_pInputSystem, a2: ox, a3: oy);
}

//------------------------------------------------------------------------------
// Address: 0x10118AD0
// Name: public: virtual void CInput::GetFullscreenMousePos(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::GetFullscreenMousePos(CInput *this, int *mx, int *my, int *unclampedx, int *unclampedy)
{
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int h; // [esp+4h] [ebp-18h] BYREF
  int w; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int current_posx; // [esp+14h] [ebp-8h] BYREF
  int current_posy; // [esp+18h] [ebp-4h] BYREF

  if ( !g_pInputStackSystem->IsTopmostEnabledContext(this: g_pInputStackSystem, a2: this->m_hInputContext) )
  {
    this->GetWindowCenter(this, a2: &x, a3: &y);
    g_pInputSystem->GetCursorPosition(this: g_pInputSystem, a2: &current_posx, a3: &current_posy);
    current_posy -= y;
    current_posx -= x;
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
    v6 = w / 2 + current_posx;
    current_posy += h / 2;
    if ( unclampedx != nullptr )
      *unclampedx = v6;
    if ( unclampedy != nullptr )
      *unclampedy = current_posy;
    current_posx = v6 < 0 ? 0 : v6;
    if ( ScreenWidth() < current_posx )
      current_posx = ScreenWidth();
    current_posy &= (current_posy < 0) - 1;
    v7 = ScreenHeight();
    v8 = current_posy;
    if ( v7 < current_posy )
      v8 = ScreenHeight();
    *mx = current_posx;
    *my = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118BD0
// Name: public: virtual void CInput::SetFullscreenMousePos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::SetFullscreenMousePos(CInput *this, int mx, int my)
{
  g_pInputStackSystem->SetCursorPosition(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: mx, a4: my);
}

//------------------------------------------------------------------------------
// Address: 0x10118C00
// Name: public: virtual void CInput::ClearStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ClearStates(CInput *this)
{
  int rawX; // [esp+4h] [ebp-8h] BYREF
  int rawY; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_fMouseActive )
  {
    CInput::GetPerUser(this, nSlot: -1)->m_flAccumulatedMouseXMovement = 0.0;
    CInput::GetPerUser(this, nSlot: -1)->m_flAccumulatedMouseYMovement = 0.0;
    inputsystem->GetRawMouseAccumulators(this: inputsystem, a2: &rawX, a3: &rawY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118C50
// Name: public: virtual float ConVar_m_pitch::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall ConVar_m_pitch::GetFloat(ConVar_m_pitch *this)
{
  ConVar *v1; // eax
  ConVar *m_pParent; // ecx

  v1 = (ConVar *)sv_cheats;
  if ( sv_cheats == nullptr )
  {
    v1 = cvar->FindVar_2(this: cvar, a2: "sv_cheats");
    sv_cheats = v1;
  }
  m_pParent = this->m_pParent;
  if ( v1 == nullptr || v1->m_pParent != nullptr && v1->m_pParent->m_Value.m_nValue != 0 )
    return m_pParent->m_Value.m_fValue;
  if ( m_pParent->m_Value.m_fValue <= 0.0 )
    return -0.022;
  return 0.022;
}

//------------------------------------------------------------------------------
// Address: 0x10118CC0
// Name: public: virtual void CInput::ResetMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::ResetMouse(CInput *this)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  this->GetWindowCenter(this, a2: &x, a3: &y);
  g_pInputStackSystem->SetCursorPosition(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: x, a4: y);
}

//------------------------------------------------------------------------------
// Address: 0x10118D00
// Name: protected: void CInput::GetAccumulatedMouseDeltasAndResetAccumulators(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::GetAccumulatedMouseDeltasAndResetAccumulators(CInput *this, int nSlot, float *mx, float *my)
{
  float *v4; // edx
  const CInput::PerUserInput_t *PerUser; // eax
  float *v6; // edx
  int rawMouseY; // [esp+0h] [ebp-4h] BYREF

  rawMouseY = (int)this;
  if ( m_rawinput.m_pParent != nullptr && m_rawinput.m_pParent->m_Value.m_nValue != 0 )
  {
    inputsystem->GetRawMouseAccumulators(this: inputsystem, a2: &nSlot, a3: &rawMouseY);
    v4 = my;
    *mx = (float)nSlot;
    *v4 = (float)rawMouseY;
  }
  else
  {
    PerUser = CInput::GetPerUser(this, nSlot);
    v6 = my;
    *mx = PerUser->m_flAccumulatedMouseXMovement;
    *v6 = PerUser->m_flAccumulatedMouseYMovement;
    PerUser->m_flAccumulatedMouseXMovement = 0.0;
    PerUser->m_flAccumulatedMouseYMovement = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118D80
// Name: protected: void CInput::GetMouseDelta(int,float,float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::GetMouseDelta(
        CInput *this,
        int nSlot,
        float inmousex,
        float inmousey,
        float *pOutMouseX,
        float *pOutMouseY)
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &s_m_filter, pName: "m_filter");
  }
  if ( s_m_filter.m_Info[nSlot].m_pConVarState->m_Value.m_nValue != 0 )
  {
    *pOutMouseX = (float)(CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseXPosition + inmousex) * 0.5;
    *pOutMouseY = (float)(CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseYPosition + inmousey) * 0.5;
  }
  else
  {
    *pOutMouseX = inmousex;
    *pOutMouseY = inmousey;
  }
  CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseXPosition = inmousex;
  CInput::GetPerUser(this, nSlot: -1)->m_flPreviousMouseYPosition = inmousey;
}

//------------------------------------------------------------------------------
// Address: 0x10118E50
// Name: public: virtual void CInput::AccumulateMouse(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInput::AccumulateMouse(CInput *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, int nSlot)
{
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  CInput::PerUserInput_t *PerUser; // esi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // ecx
  int v12; // esi
  int v13; // edx
  int v14; // eax
  int current_posy; // [esp+0h] [ebp-10h] BYREF
  int oy; // [esp+4h] [ebp-Ch] BYREF
  int h; // [esp+8h] [ebp-8h] BYREF
  int ox; // [esp+Ch] [ebp-4h] BYREF

  ox = (int)this;
  if ( cl_mouseenable.m_pParent != nullptr && cl_mouseenable.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = nSlot;
    if ( UsingMouselook(nSlot) && (m_rawinput.m_pParent == nullptr || m_rawinput.m_pParent->m_Value.m_nValue == 0) )
    {
      engine->GetScreenSize(this: engine, a2: &nSlot, a3: &h);
      v6 = nSlot >> 1;
      v7 = h >> 1;
      PerUser = (CInput::PerUserInput_t *)CInput::GetPerUser(this: (CInput *)ox, nSlot: v5);
      if ( PerUser->m_fCameraInterceptingMouse || !g_pVGuiSurface->IsCursorLocked(this: g_pVGuiSurface) )
      {
        v12 = ox;
        if ( *(_BYTE *)(ox + 6) != 0 )
        {
          ((void (__thiscall *)(IInputSystem *, int *, int *, int, int, int))g_pInputSystem->GetCursorPosition)(
            a1: g_pInputSystem,
            a2: &ox,
            a3: &oy,
            a4: a3,
            a5: a2,
            a6: a4);
          v13 = ox;
          if ( ox >= 0 )
          {
            if ( ox > nSlot - 1 )
              v13 = nSlot - 1;
          }
          else
          {
            v13 = 0;
          }
          v14 = h - 1;
          ox = v13;
          if ( oy >= 0 )
          {
            if ( oy <= v14 )
              v14 = oy;
          }
          else
          {
            v14 = 0;
          }
          oy = v14;
          g_pInputStackSystem->SetCursorPosition(
            this: g_pInputStackSystem,
            a2: *(InputContextHandle_t__ **)(v12 + 268),
            a3: v13,
            a4: v14);
        }
      }
      else
      {
        g_pInputSystem->GetCursorPosition(this: g_pInputSystem, a2: &oy, a3: &current_posy);
        v9 = current_posy;
        PerUser->m_flAccumulatedMouseXMovement = (float)(oy - v6) + PerUser->m_flAccumulatedMouseXMovement;
        v10 = (float)(v9 - v7) + PerUser->m_flAccumulatedMouseYMovement;
        v11 = ox;
        PerUser->m_flAccumulatedMouseYMovement = v10;
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 116))(a1: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118FB0
// Name: protected: void CInput::MouseMove(int,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInput::MouseMove(CInput *this, int nSlot, CUserCmd *cmd)
{
  int v4; // edi
  IClientMode *ClientMode; // eax
  QAngle viewangles; // [esp+24h] [ebp-18h] BYREF
  float mx; // [esp+30h] [ebp-Ch] BYREF
  int mouse_x; // [esp+34h] [ebp-8h] BYREF
  int mouse_y; // [esp+38h] [ebp-4h] BYREF

  engine->GetViewAngles(this: engine, a2: &viewangles);
  CInput::CheckMouseAcclerationVars(this);
  view->StopPitchDrift(this: view);
  v4 = nSlot;
  if ( !CInput::GetPerUser(this, nSlot)->m_fCameraInterceptingMouse
    && g_pInputStackSystem->IsTopmostEnabledContext(this: g_pInputStackSystem, a2: this->m_hInputContext) )
  {
    this->AccumulateMouse(this, a2: v4);
    CInput::GetAccumulatedMouseDeltasAndResetAccumulators(this, nSlot: v4, &mx, my: (float *)&nSlot);
    CInput::GetMouseDelta(
      this,
      nSlot: v4,
      inmousex: mx,
      inmousey: *(float *)&nSlot,
      pOutMouseX: (float *)&mouse_x,
      pOutMouseY: (float *)&mouse_y);
    CInput::ScaleMouse(this, nSlot: v4, x: (float *)&mouse_x, y: (float *)&mouse_y);
    ClientMode = GetClientMode();
    ClientMode->OverrideMouseInput(this: ClientMode, a2: (float *)&mouse_x, a3: (float *)&mouse_y);
    ((void (__thiscall *)(CInput *, int, QAngle *, CUserCmd *, int, int))this->ApplyMouse)(
      a1: this,
      a2: v4,
      a3: &viewangles,
      a4: cmd,
      a5: mouse_x,
      a6: mouse_y);
    this->ResetMouse(this);
  }
  engine->SetViewAngles(this: engine, a2: &viewangles);
}

//------------------------------------------------------------------------------
// Address: 0x10432A90
// Name: _CInput::ExtraMouseSample_::_2_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CInput::ExtraMouseSample_::_2_::_dynamic_atexit_destructor_for__dummy__()
{
  dummy[0].__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10432AA0
// Name: _dynamic_atexit_destructor_for__m_filter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_filter__()
{
  ConVar::~ConVar(this: &m_filter);
}

//------------------------------------------------------------------------------
// Address: 0x10432AB0
// Name: _dynamic_atexit_destructor_for__sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sensitivity__()
{
  ConVar::~ConVar(this: &sensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x10432AC0
// Name: _dynamic_atexit_destructor_for__m_side__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_side__()
{
  ConVar::~ConVar(this: &m_side);
}

//------------------------------------------------------------------------------
// Address: 0x10432AD0
// Name: _dynamic_atexit_destructor_for__m_yaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_yaw__()
{
  ConVar::~ConVar(this: &m_yaw);
}

//------------------------------------------------------------------------------
// Address: 0x10432AE0
// Name: _dynamic_atexit_destructor_for__m_forward__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_forward__()
{
  ConVar::~ConVar(this: &m_forward);
}

//------------------------------------------------------------------------------
// Address: 0x10432AF0
// Name: _dynamic_atexit_destructor_for__m_customaccel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_customaccel__()
{
  ConVar::~ConVar(this: &m_customaccel);
}

//------------------------------------------------------------------------------
// Address: 0x10432B00
// Name: _dynamic_atexit_destructor_for__m_customaccel_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_customaccel_scale__()
{
  ConVar::~ConVar(this: &m_customaccel_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10432B10
// Name: _dynamic_atexit_destructor_for__m_customaccel_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_customaccel_max__()
{
  ConVar::~ConVar(this: &m_customaccel_max);
}

//------------------------------------------------------------------------------
// Address: 0x10432B20
// Name: _dynamic_atexit_destructor_for__m_customaccel_exponent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_customaccel_exponent__()
{
  ConVar::~ConVar(this: &m_customaccel_exponent);
}

//------------------------------------------------------------------------------
// Address: 0x10432B30
// Name: _dynamic_atexit_destructor_for__m_mousespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_mousespeed__()
{
  ConVar::~ConVar(this: &m_mousespeed);
}

//------------------------------------------------------------------------------
// Address: 0x10432B40
// Name: _dynamic_atexit_destructor_for__m_mouseaccel1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_mouseaccel1__()
{
  ConVar::~ConVar(this: &m_mouseaccel1);
}

//------------------------------------------------------------------------------
// Address: 0x10432B50
// Name: _dynamic_atexit_destructor_for__m_mouseaccel2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_mouseaccel2__()
{
  ConVar::~ConVar(this: &m_mouseaccel2);
}

//------------------------------------------------------------------------------
// Address: 0x10432B60
// Name: _dynamic_atexit_destructor_for__m_rawinput__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_rawinput__()
{
  ConVar::~ConVar(this: &m_rawinput);
}

//------------------------------------------------------------------------------
// Address: 0x10432B70
// Name: _dynamic_atexit_destructor_for__cl_mouselook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_mouselook__()
{
  ConVar::~ConVar(this: &cl_mouselook);
}

//------------------------------------------------------------------------------
// Address: 0x10432B80
// Name: _dynamic_atexit_destructor_for__cl_mouseenable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_mouseenable__()
{
  ConVar::~ConVar(this: &cl_mouseenable);
}
