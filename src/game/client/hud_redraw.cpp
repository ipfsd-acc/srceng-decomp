// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_redraw.cpp
// Functions: 2
// ============================================================

#include "game\client\hud_redraw.h"

//------------------------------------------------------------------------------
// Address: 0x1010F920
// Name: FovChanged_Callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl FovChanged_Callback(IConVar *pConVar)
{
  IVEngineClient_vtbl *v1; // esi
  char *v2; // eax
  ConVarRef var; // [esp+10h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( engine->IsInGame(this: engine) )
  {
    v1 = engine->__vftable;
    v2 = VarArgs(format: "fov %f\n", var.m_pConVarState->m_Value.m_fValue);
    v1->ServerCmd(this: engine, a2: v2, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F980
// Name: public: void CHud::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::Think(CHud *this)
{
  CHud *v1; // esi
  const UniqueId_t *HudList; // edi
  bool v3; // al
  int v4; // ebx
  int v5; // esi
  vgui::Panel *v6; // edi
  C_BasePlayer *LocalPlayer; // eax
  int v8; // eax
  float m_flScreenShotTime; // xmm0_4
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *hudPanelList; // [esp+Ch] [ebp-10h]
  CUtlVector<CHudElement *,CUtlMemory<CHudElement *,int> > *list; // [esp+10h] [ebp-Ch]
  int c; // [esp+14h] [ebp-8h]
  char visible; // [esp+18h] [ebp-4h]

  v1 = this;
  HudList = CHud::GetHudList((CDmxElement *)this);
  list = (CUtlVector<CHudElement *,CUtlMemory<CHudElement *,int> > *)HudList;
  hudPanelList = CHud::GetHudPanelList(this: v1);
  c = *(_DWORD *)&HudList->m_Value[12];
  v3 = engine->IsInGame(this: engine) && !engine->IsLevelMainMenuBackground(this: engine);
  v4 = 0;
  v1->m_bEngineIsInGame = v3;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(*(_DWORD *)HudList->m_Value + 4 * v4);
      v6 = hudPanelList->m_Memory.m_pMemory[v4];
      visible = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 44))(a1: v5);
      (*(void (__thiscall **)(int, char))(*(_DWORD *)v5 + 52))(a1: v5, a2: visible);
      if ( v6 != nullptr && v6->IsVisible(this: v6) != visible )
        v6->SetVisible(this: v6, a2: visible);
      if ( visible != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5);
      if ( ++v4 >= c )
        break;
      HudList = (const UniqueId_t *)list;
    }
    v1 = this;
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v8 = (int)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
    if ( v8 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 1412))(a1: v8);
  }
  m_flScreenShotTime = v1->m_flScreenShotTime;
  if ( m_flScreenShotTime > 0.0 && *(float *)(gpGlobals.m_Index + 12) > m_flScreenShotTime )
  {
    engine->ClientCmd(this: engine, a2: "screenshot");
    v1->m_flScreenShotTime = -1.0;
  }
}
