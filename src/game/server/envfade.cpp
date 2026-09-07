// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envfade.cpp
// Functions: 12
// ============================================================

#include "game\server\envfade.h"

//------------------------------------------------------------------------------
// Address: 0x1011CE10
// Name: private: virtual struct datamap_t __near * CEnvFade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvFade::GetDataDescMap(CEnvFade *this)
{
  return &CEnvFade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011CE20
// Name: public: virtual int CEnvFade::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvFade::DrawDebugTextOverlays(CEnvFade *this)
{
  int result; // eax
  int v3; // esi
  int v4; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    duration: %f", this->m_Duration);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    hold time: %f", this->m_HoldTime);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011CF00
// Name: public: void CEnvFade::InputFade(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFade::InputFade(CEnvFade *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  int v4; // esi

  m_Value = this->m_spawnflags.m_Value;
  v4 = 2 - ((m_Value & 1) != 0);
  if ( (m_Value & 2) != 0 )
    v4 |= 4u;
  if ( (m_Value & 8) != 0 )
    v4 |= 8u;
  if ( (m_Value & 4) != 0 )
  {
    if ( inputdata->pActivator->IsNetClient(this: inputdata->pActivator) )
      UTIL_ScreenFade(
        pEntity: inputdata->pActivator,
        color: &this->m_clrRender.m_Value,
        fadeTime: this->m_Duration,
        fadeHold: this->m_HoldTime,
        flags: v4);
  }
  else
  {
    UTIL_ScreenFadeAll(
      color: &this->m_clrRender.m_Value,
      fadeTime: this->m_Duration,
      fadeHold: this->m_HoldTime,
      flags: v4 | 0x10);
  }
  this->m_flFadeStartTime = gpGlobals->curtime;
  COutputEvent::FireOutput(this: &this->m_OnBeginFade, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011CFE0
// Name: public: void CEnvFade::InputReverseFade(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFade::InputReverseFade(CEnvFade *this, inputdata_t *inputdata)
{
  int m_Value; // ecx
  int v4; // edi
  float m_flFadeStartTime; // xmm1_4
  float v6; // xmm0_4
  float m_Duration; // xmm1_4
  color32_s fadeColor; // [esp+18h] [ebp-4h] BYREF

  m_Value = this->m_spawnflags.m_Value;
  v4 = ((m_Value & 1) != 0) + 1;
  if ( (m_Value & 2) != 0 )
    v4 |= 4u;
  if ( (m_Value & 8) != 0 )
    v4 |= 8u;
  m_flFadeStartTime = this->m_flFadeStartTime;
  fadeColor = (color32_s)this->m_clrRender;
  if ( m_flFadeStartTime != 0.0 )
  {
    v6 = gpGlobals->curtime - m_flFadeStartTime;
    m_Duration = this->m_Duration;
    if ( m_Duration > v6 )
      fadeColor.a = (int)(float)((float)((float)this->m_clrRender.m_Value.a * v6) / m_Duration);
  }
  if ( (m_Value & 4) != 0 )
  {
    if ( inputdata->pActivator->IsNetClient(this: inputdata->pActivator) )
      UTIL_ScreenFade(
        pEntity: inputdata->pActivator,
        color: &fadeColor,
        fadeTime: this->m_flReverseFadeDuration,
        fadeHold: this->m_HoldTime,
        flags: v4);
  }
  else
  {
    UTIL_ScreenFadeAll(
      color: &fadeColor,
      fadeTime: this->m_flReverseFadeDuration,
      fadeHold: this->m_HoldTime,
      flags: v4 | 0x10);
  }
  this->m_flReverseFadeStartTime = gpGlobals->curtime;
  COutputEvent::FireOutput(this: &this->m_OnBeginFade, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011D110
// Name: GetFadeParms
// Source: json
//------------------------------------------------------------------------------
void __usercall GetFadeParms(const CCommand *args@<esi>, color32_s *clrFade@<edi>, float *flTime)
{
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  *flTime = 2.0;
  if ( args->m_nArgc > 1 )
    *flTime = atof(nptr: args->m_ppArgv[1]);
  *clrFade = (color32_s)-16777216;
  if ( args->m_nArgc > 4 )
  {
    v3 = locale;
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    clrFade->r = atoi(nptr: v3);
    v4 = locale;
    if ( args->m_nArgc > 3 )
      v4 = args->m_ppArgv[3];
    clrFade->g = atoi(nptr: v4);
    v5 = locale;
    if ( args->m_nArgc > 4 )
      v5 = args->m_ppArgv[4];
    clrFade->b = atoi(nptr: v5);
    if ( args->m_nArgc == 5 )
      clrFade->a = atoi(nptr: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D1C0
// Name: CC_FadeOut
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_FadeOut(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  color32_s clrFade; // [esp+14h] [ebp-8h] BYREF
  float flTime; // [esp+18h] [ebp-4h] BYREF

  GetFadeParms(args, &clrFade, &flTime);
  CommandClient = UTIL_GetCommandClient();
  UTIL_ScreenFade(pEntity: CommandClient, color: &clrFade, fadeTime: flTime, fadeHold: 0.0, flags: 26);
}

//------------------------------------------------------------------------------
// Address: 0x1011D210
// Name: CC_FadeIn
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_FadeIn(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  color32_s clrFade; // [esp+14h] [ebp-8h] BYREF
  float flTime; // [esp+18h] [ebp-4h] BYREF

  GetFadeParms(args, &clrFade, &flTime);
  CommandClient = UTIL_GetCommandClient();
  UTIL_ScreenFade(pEntity: CommandClient, color: &clrFade, fadeTime: flTime, fadeHold: 0.0, flags: 17);
}

//------------------------------------------------------------------------------
// Address: 0x10402C70
// Name: CEnvFade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvFade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvFade>();
  CEnvFade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011D260
// Name: class CEnvFade __near * _CreateEntityTemplate<class CEnvFade>(class CEnvFade __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvFade *__cdecl _CreateEntityTemplate<CEnvFade>(CEnvFade *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CEnvFade::`vftable';
    v3[215] = 0;
    v3[218] = -1;
    v3[219] = 0;
    v3[221] = 0;
    v3[222] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvFade *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402C80
// Name: _dynamic_initializer_for__fadeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fadeout__()
{
  ConCommand::ConCommand(
    this: &fadeout,
    pName: "fadeout",
    callback: (void (__cdecl *)())CC_FadeOut,
    pHelpString: "fadeout {time r g b}: Fades the screen to black or to the specified color over the given number of seconds.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fadeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10402CB0
// Name: _dynamic_initializer_for__fadein__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fadein__()
{
  ConCommand::ConCommand(
    this: &fadein,
    pName: "fadein",
    callback: (void (__cdecl *)())CC_FadeIn,
    pHelpString: "fadein {time r g b}: Fades the screen in from black or from the specified color over the given number of seconds.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fadein__);
}

//------------------------------------------------------------------------------
// Address: 0x10402CE0
// Name: _dynamic_initializer_for__env_hudhint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_hudhint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvHudHint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_hudhint,
           a3: "env_hudhint");
}
