// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demoaction_types.cpp
// Functions: 57
// ============================================================

#include "engine\cl_demoaction_types.h"

//------------------------------------------------------------------------------
// Address: 0x100763E0
// Name: public: virtual void CDemoActionSkipAhead::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::SaveKeysToBuffer(CDemoActionSkipAhead *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nSkipToTick == -1 )
  {
    if ( this->m_flSkipToTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "skiptotime \"%.3f\"\n", this->m_flSkipToTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "skiptotick \"%i\"\n", this->m_nSkipToTick);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076450
// Name: public: void CDemoActionSkipAhead::SetSkipToTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::SetSkipToTime(CBaseDemoActionWithStopTime *this, float t)
{
  this->m_bUsingStopTick = t == -1.0;
  this->m_flStopTime = t;
}

//------------------------------------------------------------------------------
// Address: 0x10076490
// Name: public: virtual void CDemoActionSkipAhead::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::FireAction(CDemoActionSkipAhead *this)
{
  if ( this->m_bUsingSkipTick )
    demoplayer->SkipToTick(this: demoplayer, a2: this->m_nSkipToTick, a3: false, a4: false);
  else
    demoplayer->SkipToTick(
      this: demoplayer,
      a2: (int)(float)((float)(this->m_flSkipToTime / host_state.interval_per_tick) + 0.5),
      a3: false,
      a4: false);
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100764F0
// Name: public: virtual bool CDemoActionSkipAhead::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionSkipAhead::Update(CDemoActionStopPlayback *this, const DemoActionTimingContext *tc)
{
  char result; // al

  result = CBaseDemoAction::Update(this, tc);
  if ( result != 0 )
  {
    CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076520
// Name: public: virtual void CDemoActionStopPlayback::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionStopPlayback::FireAction(CDemoActionStopPlayback *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: "disconnect\n", nTickDelay: 0);
  }
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076560
// Name: public: void CDemoActionPlayCommands::SetCommandStream(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::SetCommandStream(CDemoActionPlayCommands *this, const char *stream)
{
  V_strncpy(pDest: this->m_szCommandStream, pSrc: stream, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10076580
// Name: public: virtual void CDemoActionPlayCommands::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::FireAction(CDemoActionPlayCommands *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]

  if ( this->m_szCommandStream[0] != 0 )
  {
    v4 = va(format: "%s\n", this->m_szCommandStream);
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
  }
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100765C0
// Name: public: virtual void CDemoActionPlayCommands::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::SaveKeysToBuffer(CDemoActionPlayCommands *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "commands \"%s\"\n", this->m_szCommandStream);
}

//------------------------------------------------------------------------------
// Address: 0x10076600
// Name: public: virtual bool CDemoActionScreenFadeStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionScreenFadeStart::Init(CDemoActionScreenFadeStart *this, KeyValues *pInitData)
{
  char result; // al
  int Int; // ebx
  unsigned __int8 v6; // al
  unsigned __int8 v7; // [esp+10h] [ebp-20h]
  unsigned __int8 v8; // [esp+14h] [ebp-1Ch]
  unsigned __int8 b; // [esp+18h] [ebp-18h]
  int g; // [esp+1Ch] [ebp-14h]
  int r; // [esp+20h] [ebp-10h]
  int fadepurge; // [esp+24h] [ebp-Ch]
  int fadestayout; // [esp+28h] [ebp-8h]
  float fademodulate; // [esp+2Ch] [ebp-4h]
  float Float; // [esp+38h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    Float = KeyValues::GetFloat(this: pInitData, keyName: "duration", defaultValue: 0.0);
    fademodulate = KeyValues::GetFloat(this: pInitData, keyName: "holdtime", defaultValue: 0.0);
    Int = KeyValues::GetInt(this: pInitData, keyName: "FFADE_IN", defaultValue: 0);
    fadestayout = KeyValues::GetInt(this: pInitData, keyName: "FFADE_OUT", defaultValue: 0);
    fadepurge = KeyValues::GetInt(this: pInitData, keyName: "FFADE_MODULATE", defaultValue: 0);
    r = KeyValues::GetInt(this: pInitData, keyName: "FFADE_STAYOUT", defaultValue: 0);
    g = KeyValues::GetInt(this: pInitData, keyName: "FFADE_PURGE", defaultValue: 0);
    b = KeyValues::GetInt(this: pInitData, keyName: "r", defaultValue: 255);
    v8 = KeyValues::GetInt(this: pInitData, keyName: "g", defaultValue: 255);
    v7 = KeyValues::GetInt(this: pInitData, keyName: "b", defaultValue: 255);
    v6 = KeyValues::GetInt(this: pInitData, keyName: "a", defaultValue: 255);
    this->fade.duration = (int)(float)(Float * 512.0);
    *(_DWORD *)&this->fade.holdTime = (unsigned __int16)(int)(float)(fademodulate * 512.0);
    if ( Int != 0 )
      this->fade.fadeFlags = 1;
    if ( fadestayout != 0 )
      this->fade.fadeFlags |= 2u;
    if ( fadepurge != 0 )
      this->fade.fadeFlags |= 4u;
    if ( r != 0 )
      this->fade.fadeFlags |= 8u;
    if ( g != 0 )
      this->fade.fadeFlags |= 0x10u;
    this->fade.r = b;
    this->fade.a = v6;
    this->fade.g = v8;
    this->fade.b = v7;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100767A0
// Name: public: virtual void CDemoActionScreenFadeStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionScreenFadeStart::FireAction(CDemoActionScreenFadeStart *this)
{
  g_ClientDLL->View_Fade(this: g_ClientDLL, a2: &this->fade);
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100767D0
// Name: public: virtual void CDemoActionScreenFadeStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionScreenFadeStart::SaveKeysToBuffer(
        CDemoActionScreenFadeStart *this,
        int depth,
        CUtlBuffer *buf)
{
  __int16 fadeFlags; // ax
  int v6; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]
  int fadepurge; // [esp+14h] [ebp-Ch]
  int fadestayout; // [esp+18h] [ebp-8h]
  int fademodulate; // [esp+1Ch] [ebp-4h]
  float v11; // [esp+28h] [ebp+8h]

  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  fadeFlags = this->fade.fadeFlags;
  fademodulate = fadeFlags & 1;
  fadestayout = fadeFlags & 2;
  v11 = (double)this->fade.holdTime * 0.001953125;
  fadepurge = fadeFlags & 4;
  v7 = fadeFlags & 8;
  v6 = fadeFlags & 0x10;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "duration \"%.3f\"\n", 0.001953125 * (double)this->fade.duration);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "holdtime \"%.3f\"\n", v11);
  if ( fademodulate > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_IN \"1\"\n");
  if ( fadestayout > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_OUT \"1\"\n");
  if ( fadepurge > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_MODULATE \"1\"\n");
  if ( v7 > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_STAYOUT \"1\"\n");
  if ( v6 > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_PURGE \"1\"\n");
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r \"%i\"\n", this->fade.r);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g \"%i\"\n", this->fade.g);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b \"%i\"\n", this->fade.b);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a \"%i\"\n", this->fade.a);
}

//------------------------------------------------------------------------------
// Address: 0x10076930
// Name: public: void CDemoActionTextMessageStart::SetMessageText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::SetMessageText(CDemoActionTextMessageStart *this, const char *text)
{
  V_strncpy(pDest: this->m_szMessageText, pSrc: text, maxLen: 512);
}

//------------------------------------------------------------------------------
// Address: 0x10076950
// Name: public: char const __near * CDemoActionPlaySoundStart::GetSoundName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoActionPlaySoundStart::GetSoundName(CDemoActionPlaySoundStart *this)
{
  return this->m_szSoundName;
}

//------------------------------------------------------------------------------
// Address: 0x10076960
// Name: public: void CDemoActionTextMessageStart::SetFontName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::SetFontName(CDemoActionTextMessageStart *this, const char *font)
{
  V_strncpy(pDest: this->m_szVguiFont, pSrc: font, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10076980
// Name: public: char const __near * CDemoActionTextMessageStart::GetFontName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoActionTextMessageStart::GetFontName(CDemoActionTextMessageStart *this)
{
  char *m_szVguiFont; // esi
  bool v2; // zf
  char *result; // eax

  m_szVguiFont = this->m_szVguiFont;
  v2 = V_strcasecmp(s1: "TextMessageDefault", s2: this->m_szVguiFont) == 0;
  result = (char *)defaultValue;
  if ( !v2 )
    return m_szVguiFont;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100769B0
// Name: public: virtual bool CDemoActionTextMessageStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionTextMessageStart::Init(CDemoActionTextMessageStart *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax
  const char *v6; // eax
  int Int; // ebx
  int v8; // eax
  int v9; // [esp+10h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    this->message.fadein = KeyValues::GetFloat(this: pInitData, keyName: "fadein", defaultValue: 0.0);
    this->message.fadeout = KeyValues::GetFloat(this: pInitData, keyName: "fadeout", defaultValue: 0.0);
    this->message.holdtime = KeyValues::GetFloat(this: pInitData, keyName: "holdtime", defaultValue: 0.0);
    this->message.fxtime = KeyValues::GetFloat(this: pInitData, keyName: "fxtime", defaultValue: 0.0);
    this->message.x = KeyValues::GetFloat(this: pInitData, keyName: "x", defaultValue: 0.0);
    this->message.y = KeyValues::GetFloat(this: pInitData, keyName: "y", defaultValue: 0.0);
    String = KeyValues::GetString(this: pInitData, keyName: "message", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szMessageText, pSrc: String, maxLen: 512);
    v6 = KeyValues::GetString(this: pInitData, keyName: "font", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szVguiFont, pSrc: v6, maxLen: 64);
    this->message.r1 = KeyValues::GetInt(this: pInitData, keyName: "r1", defaultValue: 255);
    this->message.g1 = KeyValues::GetInt(this: pInitData, keyName: "g1", defaultValue: 255);
    this->message.b1 = KeyValues::GetInt(this: pInitData, keyName: "b1", defaultValue: 255);
    this->message.a1 = KeyValues::GetInt(this: pInitData, keyName: "a1", defaultValue: 255);
    this->message.r2 = KeyValues::GetInt(this: pInitData, keyName: "r2", defaultValue: 255);
    this->message.g2 = KeyValues::GetInt(this: pInitData, keyName: "g2", defaultValue: 255);
    this->message.b2 = KeyValues::GetInt(this: pInitData, keyName: "b2", defaultValue: 255);
    this->message.a2 = KeyValues::GetInt(this: pInitData, keyName: "a2", defaultValue: 255);
    Int = KeyValues::GetInt(this: pInitData, keyName: "FADEINOUT", defaultValue: 0);
    v9 = KeyValues::GetInt(this: pInitData, keyName: "FLICKER", defaultValue: 0);
    v8 = KeyValues::GetInt(this: pInitData, keyName: "WRITEOUT", defaultValue: 0);
    this->message.effect = 0;
    if ( Int != 0 )
      this->message.effect = 0;
    if ( v9 != 0 )
      this->message.effect = 1;
    if ( v8 != 0 )
      this->message.effect = 2;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076BD0
// Name: public: struct client_textmessage_t __near * CDemoActionTextMessageStart::GetTextMessage(void)
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__thiscall CDemoActionTextMessageStart::GetTextMessage(CDemoActionTextMessageStart *this)
{
  return &this->message;
}

//------------------------------------------------------------------------------
// Address: 0x10076BE0
// Name: public: virtual void CDemoActionTextMessageStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::FireAction(CDemoActionTextMessageStart *this)
{
  char *m_szVguiFont; // edi

  m_szVguiFont = this->m_szVguiFont;
  if ( V_strcasecmp(s1: "TextMessageDefault", s2: this->m_szVguiFont) == 0 )
    m_szVguiFont = (char *)defaultValue;
  this->message.pVGuiSchemeFontName = m_szVguiFont;
  TextMessage_DemoMessageFull(pszMessage: this->m_szMessageText, message: &this->message);
  CL_HudMessage(pMessage: "__DEMOMESSAGE__");
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076C40
// Name: public: virtual void CDemoActionTextMessageStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::SaveKeysToBuffer(
        CDemoActionTextMessageStart *this,
        int depth,
        CUtlBuffer *buf)
{
  int effect; // eax
  bool v7; // zf
  char *m_szVguiFont; // eax
  BOOL v9; // [esp+Ch] [ebp-4h]
  BOOL v10; // [esp+18h] [ebp+8h]
  BOOL v11; // [esp+1Ch] [ebp+Ch]

  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  effect = this->message.effect;
  v11 = effect == 0;
  v10 = effect == 1;
  v9 = effect == 2;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "message \"%s\"\n", this->m_szMessageText);
  v7 = V_strcasecmp(s1: "TextMessageDefault", s2: this->m_szVguiFont) == 0;
  m_szVguiFont = (char *)defaultValue;
  if ( !v7 )
    m_szVguiFont = this->m_szVguiFont;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "font \"%s\"\n", m_szVguiFont);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fadein \"%.3f\"\n", this->message.fadein);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fadeout \"%.3f\"\n", this->message.fadeout);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "holdtime \"%.3f\"\n", this->message.holdtime);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fxtime \"%.3f\"\n", this->message.fxtime);
  if ( v11 > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FADEINOUT \"1\"\n");
  if ( v10 > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FLICKER \"1\"\n");
  if ( v9 > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "WRITEOUT \"1\"\n");
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "x \"%f\"\n", this->message.x);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "y \"%f\"\n", this->message.y);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r1 \"%i\"\n", this->message.r1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g1 \"%i\"\n", this->message.g1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b1 \"%i\"\n", this->message.b1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a1 \"%i\"\n", this->message.a1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r2 \"%i\"\n", this->message.r2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g2 \"%i\"\n", this->message.g2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b2 \"%i\"\n", this->message.b2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a2 \"%i\"\n", this->message.a2);
}

//------------------------------------------------------------------------------
// Address: 0x10076E50
// Name: public: void CDemoActionCDTrackStart::SetTrack(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::SetTrack(CDemoActionCDTrackStart *this, int track)
{
  this->m_nCDTrack = track;
}

//------------------------------------------------------------------------------
// Address: 0x10076E60
// Name: public: int CDemoActionCDTrackStart::GetTrack(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoActionCDTrackStart::GetTrack(CDemoActionCDTrackStart *this)
{
  return this->m_nCDTrack;
}

//------------------------------------------------------------------------------
// Address: 0x10076E70
// Name: public: virtual void CDemoActionCDTrackStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::FireAction(CDemoActionCDTrackStop *this)
{
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076E80
// Name: public: virtual void CDemoActionCDTrackStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::SaveKeysToBuffer(CDemoActionCDTrackStart *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "track \"%i\"\n", this->m_nCDTrack);
}

//------------------------------------------------------------------------------
// Address: 0x10076EC0
// Name: public: void CDemoActionPlaySoundStart::SetSoundName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::SetSoundName(CDemoActionPlaySoundStart *this, const char *name)
{
  V_strncpy(pDest: this->m_szSoundName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x10076EE0
// Name: public: virtual void CDemoActionPlaySoundStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::SaveKeysToBuffer(
        CDemoActionPlaySoundStart *this,
        int depth,
        CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "sound \"%s\"\n", this->m_szSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10076F20
// Name: public: virtual bool CBaseDemoActionWithStopTime::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoActionWithStopTime::Update(
        CBaseDemoActionWithStopTime *this,
        const DemoActionTimingContext *tc)
{
  char result; // al

  result = CBaseDemoAction::Update(this, tc);
  if ( result != 0 )
  {
    if ( CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this) )
    {
      if ( this->m_bUsingStopTick )
      {
        if ( tc->curtick >= this->m_nStopTick )
        {
          CBaseDemoAction::SetFinishedAction(this, finished: true);
          return 1;
        }
      }
      else if ( tc->curtime >= this->m_flStopTime )
      {
        CBaseDemoAction::SetFinishedAction(this, finished: true);
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076F90
// Name: public: void CBaseDemoActionWithStopTime::SetStopTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoActionWithStopTime::SetStopTick(CBaseDemoActionWithStopTime *this, int tick)
{
  this->m_bUsingStopTick = tick != -1;
  this->m_nStopTick = tick;
}

//------------------------------------------------------------------------------
// Address: 0x10076FB0
// Name: public: virtual void CDemoActionChangePlaybackRate::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::FireAction(CDemoActionChangePlaybackRate *this)
{
  ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: this->m_flPlaybackRate);
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076FE0
// Name: public: float CDemoActionPausePlayback::GetPauseTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDemoActionPausePlayback::GetPauseTime(CDemoActionPausePlayback *this)
{
  return this->m_flPauseTime;
}

//------------------------------------------------------------------------------
// Address: 0x10076FF0
// Name: public: virtual void CDemoActionPausePlayback::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::FireAction(CDemoActionPausePlayback *this)
{
  ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: this->m_flPauseTime);
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x10077020
// Name: FnCreateCDemoActionPausePlayback
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPausePlayback()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA8u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPausePlayback::`vftable';
  *(_DWORD *)&v1[1].m_szActionName[2] = 0;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PAUSE);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077060
// Name: public: virtual void CDemoActionZoom::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionZoom::FireAction(CDemoActionZoom *this)
{
  double v2; // st7

  v2 = ((double (__thiscall *)(IRender *))g_EngineRenderer->GetFov)(a1: g_EngineRenderer);
  this->m_flOriginalFOV = v2;
  scr_demo_override_fov = v2;
  this->m_flFOVStartTime = host_time;
}

//------------------------------------------------------------------------------
// Address: 0x10077090
// Name: public: virtual void CDemoActionZoom::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionZoom::SaveKeysToBuffer(CDemoActionZoom *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "spline \"%i\"\n", this->m_bSpline);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "stayout \"%i\"\n", this->m_bStayout);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "finalfov \"%f\"\n", this->m_flFinalFOV);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovrateout \"%f\"\n", this->m_flFOVRateOut);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovratein \"%f\"\n", this->m_flFOVRateIn);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovhold \"%f\"\n", this->m_flHoldTime);
}

//------------------------------------------------------------------------------
// Address: 0x10077140
// Name: FnCreateCDemoActionZoom
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionZoom()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xB4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionZoom::`vftable';
  LOWORD(v1[1].__vftable) = 0;
  v1[1].m_Type = DEMO_ACTION_UNKNOWN;
  *(_DWORD *)&v1[1].m_bActionFired = 0;
  *(_DWORD *)&v1[1].m_szActionName[2] = 0;
  *(_DWORD *)&v1[1].m_szActionName[6] = 0;
  *(_DWORD *)&v1[1].m_szActionName[10] = 0;
  *(_DWORD *)&v1[1].m_szActionName[14] = 0;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_ZOOM);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100771B0
// Name: public: virtual bool CDemoActionSkipAhead::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionSkipAhead::Init(CDemoActionSkipAhead *this, KeyValues *pInitData)
{
  char result; // al
  int Int; // eax
  double Float; // st7
  float v6; // [esp+10h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    Int = KeyValues::GetInt(this: pInitData, keyName: "skiptotick", defaultValue: -1);
    this->m_bUsingSkipTick = Int != -1;
    this->m_nSkipToTick = Int;
    Float = KeyValues::GetFloat(this: pInitData, keyName: "skiptotime", defaultValue: -1.0);
    this->m_bUsingSkipTick = Float == -1.0;
    v6 = Float;
    this->m_flSkipToTime = v6;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077240
// Name: FnCreateCDemoActionSkipAhead
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionSkipAhead()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionSkipAhead::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_SKIPAHEAD);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077280
// Name: FnCreateCDemoActionStopPlayback
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionStopPlayback()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x98u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionStopPlayback::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_STOPPLAYBACK);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100772C0
// Name: public: virtual bool CDemoActionPlayCommands::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionPlayCommands::Init(CDemoActionPlayCommands *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    String = KeyValues::GetString(this: pInitData, keyName: "commands", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szCommandStream, pSrc: String, maxLen: 256);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077310
// Name: FnCreateCDemoActionPlayCommands
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPlayCommands()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x198u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPlayCommands::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCOMMANDS);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077350
// Name: FnCreateCDemoActionScreenFadeStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionScreenFadeStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionScreenFadeStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_SCREENFADE_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077390
// Name: FnCreateCDemoActionTextMessageStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionTextMessageStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x318u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionTextMessageStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_TEXTMESSAGE_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100773D0
// Name: public: virtual bool CDemoActionCDTrackStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionCDTrackStart::Init(CDemoActionCDTrackStart *this, KeyValues *pInitData)
{
  char result; // al

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    this->m_nCDTrack = KeyValues::GetInt(this: pInitData, keyName: "track", defaultValue: -1);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077410
// Name: FnCreateCDemoActionCDTrackStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionCDTrackStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionCDTrackStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCDTRACK_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077450
// Name: FnCreateCDemoActionCDTrackStop
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionCDTrackStop()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x98u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionCDTrackStop::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCDTRACK_STOP);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077490
// Name: public: virtual bool CDemoActionPlaySoundStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionPlaySoundStart::Init(CDemoActionPlaySoundStart *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    String = KeyValues::GetString(this: pInitData, keyName: "sound", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szSoundName, pSrc: String, maxLen: 128);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100774E0
// Name: public: virtual void CDemoActionPlaySoundStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::FireAction(CDemoActionPlaySoundStart *this)
{
  CDemoActionPlaySoundStart *v1; // ebx
  CSfxTable *v2; // edi
  CClientState *LocalClient; // eax
  StartSoundParams_t params; // [esp+Ch] [ebp-68h] BYREF
  CDemoActionPlaySoundStart *v5; // [esp+70h] [ebp-4h]

  v1 = this;
  v5 = this;
  v2 = S_PrecacheSound(name: this->m_szSoundName);
  if ( v2 != nullptr )
  {
    params.userdata = 0;
    params.delay = 0.0;
    params.speakerentity = -1;
    params.initialStreamPosition = 0;
    params.skipInitialSamples = 0;
    params.m_nQueuedGUID = -1;
    params.m_nSoundScriptHandle = -1;
    memset(&params.m_pSoundEntryName, 0, 16);
    *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 2;
    LocalClient = GetLocalClient(nSlot: -1);
    params.soundsource = CBaseClientState::GetViewEntity(this: LocalClient);
    memset(&params.origin, 0, 24);
    params.entchannel = 0;
    params.pSfx = v2;
    params.fvol = 1.0;
    params.soundlevel = SNDLVL_IDLE;
    params.flags = 0;
    params.pitch = 100;
    S_StartSound(&params);
    v1 = v5;
  }
  CBaseDemoAction::SetFinishedAction(this: v1, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100775F0
// Name: FnCreateCDemoActionPlaySoundStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPlaySoundStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x118u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPlaySoundStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYSOUND_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077630
// Name: public: virtual bool CBaseDemoActionWithStopTime::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoActionWithStopTime::Init(CBaseDemoActionWithStopTime *this, KeyValues *pInitData)
{
  char result; // al
  int Int; // eax
  double Float; // st7
  float v6; // [esp+10h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    Int = KeyValues::GetInt(this: pInitData, keyName: "stoptick", defaultValue: -1);
    this->m_bUsingStopTick = Int != -1;
    this->m_nStopTick = Int;
    Float = KeyValues::GetFloat(this: pInitData, keyName: "stoptime", defaultValue: -1.0);
    this->m_bUsingStopTick = Float == -1.0;
    v6 = Float;
    this->m_flStopTime = v6;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100776C0
// Name: public: virtual void CDemoActionChangePlaybackRate::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::SaveKeysToBuffer(
        CDemoActionChangePlaybackRate *this,
        int depth,
        CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nStopTick == -1 )
  {
    if ( this->m_flStopTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptime \"%.3f\"\n", this->m_flStopTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptick \"%i\"\n", this->m_nStopTick);
  }
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "playbackrate \"%f\"\n", this->m_flPlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x10077750
// Name: public: void CDemoActionChangePlaybackRate::SetPlaybackRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::SetPlaybackRate(CDemoActionChangePlaybackRate *this, float rate)
{
  int v2; // xmm1_4
  float v3; // xmm0_4

  v2 = 981668463;
  v3 = rate;
  if ( rate < 0.001 || (v2 = 1148846080, rate > 1000.0) )
    v3 = *(float *)&v2;
  this->m_flPlaybackRate = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10077790
// Name: FnCreateCDemoActionChangePlaybackRate
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionChangePlaybackRate()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xACu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionChangePlaybackRate::`vftable';
  *(_DWORD *)&v1[1].m_szActionName[2] = 1065353216;
  *(_DWORD *)&v1[1].m_szActionName[6] = 1065353216;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_CHANGEPLAYBACKRATE);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100777E0
// Name: public: virtual void CDemoActionPausePlayback::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::SaveKeysToBuffer(CDemoActionPausePlayback *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nStopTick == -1 )
  {
    if ( this->m_flStopTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptime \"%.3f\"\n", this->m_flStopTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptick \"%i\"\n", this->m_nStopTick);
  }
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "pausetime \"%f\"\n", this->m_flPauseTime);
}

//------------------------------------------------------------------------------
// Address: 0x10077870
// Name: public: void CDemoActionPausePlayback::SetPauseTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::SetPauseTime(CDemoActionPausePlayback *this, float t)
{
  int v2; // xmm1_4
  float v3; // xmm0_4

  v2 = 0;
  v3 = t;
  if ( t < 0.0 || (v2 = 1133903872, t > 300.0) )
    v3 = *(float *)&v2;
  this->m_flPauseTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100778D0
// Name: public: virtual bool CDemoActionZoom::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionZoom::Init(CDemoActionZoom *this, KeyValues *pInitData)
{
  char result; // al

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    this->m_bSpline = KeyValues::GetInt(this: pInitData, keyName: "spline", defaultValue: 1) != 0;
    this->m_bStayout = KeyValues::GetInt(this: pInitData, keyName: "stayout", defaultValue: 1) != 0;
    this->m_flFinalFOV = KeyValues::GetFloat(this: pInitData, keyName: "finalfov", defaultValue: 0.0);
    this->m_flFOVRateOut = KeyValues::GetFloat(this: pInitData, keyName: "fovrateout", defaultValue: 0.0);
    this->m_flFOVRateIn = KeyValues::GetFloat(this: pInitData, keyName: "fovratein", defaultValue: 0.0);
    this->m_flHoldTime = KeyValues::GetFloat(this: pInitData, keyName: "fovhold", defaultValue: 0.0);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077990
// Name: public: virtual bool CDemoActionZoom::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionZoom::Update(CDemoActionZoom *this, float tc)
{
  char result; // al
  float v4; // xmm0_4
  float m_flFOVRateOut; // xmm2_4
  float m_flFinalFOV; // xmm0_4
  float v7; // xmm1_4
  float m_flFOVRateIn; // xmm2_4
  float v9; // xmm3_4
  double v10; // st7
  float m_flOriginalFOV; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float minVal; // [esp+4h] [ebp-8h] BYREF
  float maxVal; // [esp+8h] [ebp-4h] BYREF

  result = CBaseDemoAction::Update(this, tc: (const DemoActionTimingContext *)LODWORD(tc));
  if ( result == 0 )
    return result;
  if ( !CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this) )
    return 1;
  v4 = host_time - this->m_flFOVStartTime;
  m_flFOVRateOut = this->m_flFOVRateOut;
  if ( v4 <= m_flFOVRateOut )
  {
    v13 = 0.0;
    if ( m_flFOVRateOut > 0.0 )
      v13 = v4 / m_flFOVRateOut;
    if ( this->m_bSpline )
      v13 = (float)((float)(v13 * 3.0) * v13) - (float)((float)((float)(v13 * 2.0) * v13) * v13);
    if ( v13 >= 0.0 )
    {
      if ( v13 > 1.0 )
        v13 = 1.0;
    }
    else
    {
      v13 = 0.0;
    }
    scr_demo_override_fov = (float)((float)(this->m_flFinalFOV - this->m_flOriginalFOV) * v13) + this->m_flOriginalFOV;
    return 1;
  }
  if ( this->m_bStayout )
  {
    m_flFinalFOV = this->m_flFinalFOV;
LABEL_6:
    scr_demo_override_fov = m_flFinalFOV;
    CBaseDemoAction::SetFinishedAction(this, finished: true);
    return 1;
  }
  v7 = this->m_flHoldTime + m_flFOVRateOut;
  if ( v7 < v4 )
  {
    m_flFOVRateIn = this->m_flFOVRateIn;
    if ( v4 > (float)(m_flFOVRateIn + v7) )
    {
      m_flFinalFOV = 0.0;
      goto LABEL_6;
    }
    v9 = 0.0;
    tc = 0.0;
    if ( m_flFOVRateIn > 0.0 )
    {
      v9 = (float)(v4 - v7) / m_flFOVRateIn;
      tc = v9;
    }
    if ( this->m_bSpline )
      tc = (float)((float)(v9 * 3.0) * v9) - (float)((float)((float)(v9 * 2.0) * v9) * v9);
    maxVal = 1.0;
    minVal = 0.0;
    v10 = clamp<float,float,float>(val: &tc, &minVal, &maxVal);
    m_flOriginalFOV = this->m_flOriginalFOV;
    v12 = this->m_flFinalFOV;
    tc = 1.0 - v10;
    scr_demo_override_fov = (float)((float)(v12 - m_flOriginalFOV) * tc) + m_flOriginalFOV;
    return 1;
  }
  else
  {
    scr_demo_override_fov = this->m_flFinalFOV;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077B90
// Name: public: virtual bool CDemoActionChangePlaybackRate::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionChangePlaybackRate::Init(CDemoActionChangePlaybackRate *this, KeyValues *pInitData)
{
  char result; // al
  double Float; // st7
  float v5; // xmm0_4
  float v6; // [esp+10h] [ebp+8h]

  result = CBaseDemoActionWithStopTime::Init(this, pInitData);
  if ( result != 0 )
  {
    Float = KeyValues::GetFloat(this: pInitData, keyName: "playbackrate", defaultValue: 1.0);
    if ( Float >= 0.001 )
    {
      v5 = Float;
      v6 = Float;
      if ( v6 > 1000.0 )
        v5 = 1000.0;
      this->m_flPlaybackRate = v5;
      return 1;
    }
    else
    {
      this->m_flPlaybackRate = 0.001;
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077C10
// Name: public: virtual bool CDemoActionPausePlayback::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionPausePlayback::Init(CDemoActionPausePlayback *this, KeyValues *pInitData)
{
  char result; // al
  double Float; // st7
  float v5; // xmm0_4
  float v6; // [esp+10h] [ebp+8h]

  result = CBaseDemoActionWithStopTime::Init(this, pInitData);
  if ( result != 0 )
  {
    Float = KeyValues::GetFloat(this: pInitData, keyName: "pausetime", defaultValue: 1.0);
    if ( Float >= 0.0 )
    {
      v5 = Float;
      v6 = Float;
      if ( v6 > 300.0 )
        v5 = 300.0;
      this->m_flPauseTime = v5;
      return 1;
    }
    else
    {
      this->m_flPauseTime = 0.0;
      return 1;
    }
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100760B0
// Name: public: virtual void CDemoActionSkipAhead::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::SaveKeysToBuffer(CDemoActionSkipAhead *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nSkipToTick == -1 )
  {
    if ( this->m_flSkipToTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "skiptotime \"%.3f\"\n", this->m_flSkipToTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "skiptotick \"%i\"\n", this->m_nSkipToTick);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076120
// Name: public: virtual void CDemoActionSkipAhead::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::FireAction(CDemoActionSkipAhead *this)
{
  if ( this->m_bUsingSkipTick )
    demoplayer->SkipToTick(this: demoplayer, a2: this->m_nSkipToTick, a3: false, a4: false);
  else
    demoplayer->SkipToTick(
      this: demoplayer,
      a2: (int)(float)((float)(this->m_flSkipToTime / host_state.interval_per_tick) + 0.5),
      a3: false,
      a4: false);
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076180
// Name: public: virtual bool CDemoActionSkipAhead::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionSkipAhead::Update(CDemoActionStopPlayback *this, const DemoActionTimingContext *tc)
{
  char result; // al

  result = CBaseDemoAction::Update(this, tc);
  if ( result != 0 )
  {
    CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100761B0
// Name: public: virtual void CDemoActionStopPlayback::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionStopPlayback::FireAction(CDemoActionStopPlayback *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: "disconnect\n", nTickDelay: 0);
  }
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x100761F0
// Name: public: void CDemoActionPlayCommands::SetCommandStream(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::SetCommandStream(CDemoActionPlayCommands *this, const char *stream)
{
  V_strncpy(pDest: this->m_szCommandStream, pSrc: stream, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10076210
// Name: public: virtual void CDemoActionPlayCommands::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::FireAction(CDemoActionPlayCommands *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]

  if ( this->m_szCommandStream[0] != 0 )
  {
    v4 = va(format: "%s\n", this->m_szCommandStream);
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
  }
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076250
// Name: public: virtual void CDemoActionPlayCommands::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlayCommands::SaveKeysToBuffer(CDemoActionPlayCommands *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "commands \"%s\"\n", this->m_szCommandStream);
}

//------------------------------------------------------------------------------
// Address: 0x10076290
// Name: public: virtual bool CDemoActionScreenFadeStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionScreenFadeStart::Init(CDemoActionScreenFadeStart *this, KeyValues *pInitData)
{
  char result; // al
  int Int; // ebx
  unsigned __int8 v6; // al
  unsigned __int8 b; // [esp+10h] [ebp-20h]
  unsigned __int8 g; // [esp+14h] [ebp-1Ch]
  unsigned __int8 r; // [esp+18h] [ebp-18h]
  int fadepurge; // [esp+1Ch] [ebp-14h]
  int fadestayout; // [esp+20h] [ebp-10h]
  int fademodulate; // [esp+24h] [ebp-Ch]
  int fadeout; // [esp+28h] [ebp-8h]
  float holdTime; // [esp+2Ch] [ebp-4h]
  float duration; // [esp+38h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    duration = KeyValues::GetFloat(this: pInitData, keyName: "duration", defaultValue: 0.0);
    holdTime = KeyValues::GetFloat(this: pInitData, keyName: "holdtime", defaultValue: 0.0);
    Int = KeyValues::GetInt(this: pInitData, keyName: "FFADE_IN", defaultValue: 0);
    fadeout = KeyValues::GetInt(this: pInitData, keyName: "FFADE_OUT", defaultValue: 0);
    fademodulate = KeyValues::GetInt(this: pInitData, keyName: "FFADE_MODULATE", defaultValue: 0);
    fadestayout = KeyValues::GetInt(this: pInitData, keyName: "FFADE_STAYOUT", defaultValue: 0);
    fadepurge = KeyValues::GetInt(this: pInitData, keyName: "FFADE_PURGE", defaultValue: 0);
    r = KeyValues::GetInt(this: pInitData, keyName: "r", defaultValue: 255);
    g = KeyValues::GetInt(this: pInitData, keyName: "g", defaultValue: 255);
    b = KeyValues::GetInt(this: pInitData, keyName: "b", defaultValue: 255);
    v6 = KeyValues::GetInt(this: pInitData, keyName: "a", defaultValue: 255);
    this->fade.duration = (int)(float)(duration * 512.0);
    *(_DWORD *)&this->fade.holdTime = (unsigned __int16)(int)(float)(holdTime * 512.0);
    if ( Int != 0 )
      this->fade.fadeFlags = 1;
    if ( fadeout != 0 )
      this->fade.fadeFlags |= 2u;
    if ( fademodulate != 0 )
      this->fade.fadeFlags |= 4u;
    if ( fadestayout != 0 )
      this->fade.fadeFlags |= 8u;
    if ( fadepurge != 0 )
      this->fade.fadeFlags |= 0x10u;
    this->fade.r = r;
    this->fade.a = v6;
    this->fade.g = g;
    this->fade.b = b;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076430
// Name: public: virtual void CDemoActionScreenFadeStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionScreenFadeStart::FireAction(CDemoActionScreenFadeStart *this)
{
  g_ClientDLL->View_Fade(this: g_ClientDLL, a2: &this->fade);
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076460
// Name: public: virtual void CDemoActionScreenFadeStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionScreenFadeStart::SaveKeysToBuffer(
        CDemoActionScreenFadeStart *this,
        int depth,
        CUtlBuffer *buf)
{
  __int16 fadeFlags; // ax
  int fadepurge; // [esp+14h] [ebp-14h]
  int fadestayout; // [esp+18h] [ebp-10h]
  int fademodulate; // [esp+1Ch] [ebp-Ch]
  int fadeout; // [esp+20h] [ebp-8h]
  int fadein; // [esp+24h] [ebp-4h]
  float holdTime; // [esp+30h] [ebp+8h]

  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  fadeFlags = this->fade.fadeFlags;
  fadein = fadeFlags & 1;
  fadeout = fadeFlags & 2;
  holdTime = (double)this->fade.holdTime * 0.001953125;
  fademodulate = fadeFlags & 4;
  fadestayout = fadeFlags & 8;
  fadepurge = fadeFlags & 0x10;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "duration \"%.3f\"\n", 0.001953125 * (double)this->fade.duration);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "holdtime \"%.3f\"\n", holdTime);
  if ( fadein > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_IN \"1\"\n");
  if ( fadeout > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_OUT \"1\"\n");
  if ( fademodulate > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_MODULATE \"1\"\n");
  if ( fadestayout > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_STAYOUT \"1\"\n");
  if ( fadepurge > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FFADE_PURGE \"1\"\n");
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r \"%i\"\n", this->fade.r);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g \"%i\"\n", this->fade.g);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b \"%i\"\n", this->fade.b);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a \"%i\"\n", this->fade.a);
}

//------------------------------------------------------------------------------
// Address: 0x100765E0
// Name: public: void CDemoActionTextMessageStart::SetFontName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::SetFontName(CDemoActionTextMessageStart *this, const char *font)
{
  V_strncpy(pDest: this->m_szVguiFont, pSrc: font, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10076630
// Name: public: virtual bool CDemoActionTextMessageStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionTextMessageStart::Init(CDemoActionTextMessageStart *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax
  const char *v6; // eax
  int Int; // ebx
  int v8; // eax
  int fadeinoutflicker; // [esp+18h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    this->message.fadein = KeyValues::GetFloat(this: pInitData, keyName: "fadein", defaultValue: 0.0);
    this->message.fadeout = KeyValues::GetFloat(this: pInitData, keyName: "fadeout", defaultValue: 0.0);
    this->message.holdtime = KeyValues::GetFloat(this: pInitData, keyName: "holdtime", defaultValue: 0.0);
    this->message.fxtime = KeyValues::GetFloat(this: pInitData, keyName: "fxtime", defaultValue: 0.0);
    this->message.x = KeyValues::GetFloat(this: pInitData, keyName: "x", defaultValue: 0.0);
    this->message.y = KeyValues::GetFloat(this: pInitData, keyName: "y", defaultValue: 0.0);
    String = KeyValues::GetString(this: pInitData, keyName: "message", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szMessageText, pSrc: String, maxLen: 512);
    v6 = KeyValues::GetString(this: pInitData, keyName: "font", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szVguiFont, pSrc: v6, maxLen: 64);
    this->message.r1 = KeyValues::GetInt(this: pInitData, keyName: "r1", defaultValue: 255);
    this->message.g1 = KeyValues::GetInt(this: pInitData, keyName: "g1", defaultValue: 255);
    this->message.b1 = KeyValues::GetInt(this: pInitData, keyName: "b1", defaultValue: 255);
    this->message.a1 = KeyValues::GetInt(this: pInitData, keyName: "a1", defaultValue: 255);
    this->message.r2 = KeyValues::GetInt(this: pInitData, keyName: "r2", defaultValue: 255);
    this->message.g2 = KeyValues::GetInt(this: pInitData, keyName: "g2", defaultValue: 255);
    this->message.b2 = KeyValues::GetInt(this: pInitData, keyName: "b2", defaultValue: 255);
    this->message.a2 = KeyValues::GetInt(this: pInitData, keyName: "a2", defaultValue: 255);
    Int = KeyValues::GetInt(this: pInitData, keyName: "FADEINOUT", defaultValue: 0);
    fadeinoutflicker = KeyValues::GetInt(this: pInitData, keyName: "FLICKER", defaultValue: 0);
    v8 = KeyValues::GetInt(this: pInitData, keyName: "WRITEOUT", defaultValue: 0);
    this->message.effect = 0;
    if ( Int != 0 )
      this->message.effect = 0;
    if ( fadeinoutflicker != 0 )
      this->message.effect = 1;
    if ( v8 != 0 )
      this->message.effect = 2;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076850
// Name: public: struct client_textmessage_t __near * CDemoActionTextMessageStart::GetTextMessage(void)
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__thiscall CDemoActionTextMessageStart::GetTextMessage(CDemoActionTextMessageStart *this)
{
  return &this->message;
}

//------------------------------------------------------------------------------
// Address: 0x10076860
// Name: public: virtual void CDemoActionTextMessageStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::FireAction(CDemoActionTextMessageStart *this)
{
  char *m_szVguiFont; // edi

  m_szVguiFont = this->m_szVguiFont;
  if ( V_strcasecmp(s1: "TextMessageDefault", s2: this->m_szVguiFont) == 0 )
    m_szVguiFont = (char *)defaultValue;
  this->message.pVGuiSchemeFontName = m_szVguiFont;
  TextMessage_DemoMessageFull(pszMessage: this->m_szMessageText, message: &this->message);
  CL_HudMessage(pMessage: "__DEMOMESSAGE__");
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100768C0
// Name: public: virtual void CDemoActionTextMessageStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionTextMessageStart::SaveKeysToBuffer(
        CDemoActionTextMessageStart *this,
        int depth,
        CUtlBuffer *buf)
{
  int effect; // eax
  bool v7; // zf
  char *m_szVguiFont; // eax
  BOOL fadewriteout; // [esp+14h] [ebp-4h]
  BOOL fadeinoutflicker; // [esp+20h] [ebp+8h]
  BOOL fadeinout; // [esp+24h] [ebp+Ch]

  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  effect = this->message.effect;
  fadeinout = effect == 0;
  fadeinoutflicker = effect == 1;
  fadewriteout = effect == 2;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "message \"%s\"\n", this->m_szMessageText);
  v7 = V_strcasecmp(s1: "TextMessageDefault", s2: this->m_szVguiFont) == 0;
  m_szVguiFont = (char *)defaultValue;
  if ( !v7 )
    m_szVguiFont = this->m_szVguiFont;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "font \"%s\"\n", m_szVguiFont);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fadein \"%.3f\"\n", this->message.fadein);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fadeout \"%.3f\"\n", this->message.fadeout);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "holdtime \"%.3f\"\n", this->message.holdtime);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fxtime \"%.3f\"\n", this->message.fxtime);
  if ( fadeinout > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FADEINOUT \"1\"\n");
  if ( fadeinoutflicker > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "FLICKER \"1\"\n");
  if ( fadewriteout > 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "WRITEOUT \"1\"\n");
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "x \"%f\"\n", this->message.x);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "y \"%f\"\n", this->message.y);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r1 \"%i\"\n", this->message.r1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g1 \"%i\"\n", this->message.g1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b1 \"%i\"\n", this->message.b1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a1 \"%i\"\n", this->message.a1);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "r2 \"%i\"\n", this->message.r2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "g2 \"%i\"\n", this->message.g2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "b2 \"%i\"\n", this->message.b2);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "a2 \"%i\"\n", this->message.a2);
}

//------------------------------------------------------------------------------
// Address: 0x10076AD0
// Name: public: void CDemoActionCDTrackStart::SetTrack(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::SetTrack(CDemoActionCDTrackStart *this, int track)
{
  this->m_nCDTrack = track;
}

//------------------------------------------------------------------------------
// Address: 0x10076AE0
// Name: public: int CDemoActionCDTrackStart::GetTrack(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoActionCDTrackStart::GetTrack(CDemoActionCDTrackStart *this)
{
  return this->m_nCDTrack;
}

//------------------------------------------------------------------------------
// Address: 0x10076AF0
// Name: public: virtual void CDemoActionCDTrackStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::FireAction(CDemoActionCDTrackStop *this)
{
  CBaseDemoAction::SetFinishedAction(this, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076B00
// Name: public: virtual void CDemoActionCDTrackStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionCDTrackStart::SaveKeysToBuffer(CDemoActionCDTrackStart *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "track \"%i\"\n", this->m_nCDTrack);
}

//------------------------------------------------------------------------------
// Address: 0x10076B40
// Name: public: void CDemoActionPlaySoundStart::SetSoundName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::SetSoundName(CDemoActionPlaySoundStart *this, const char *name)
{
  V_strncpy(pDest: this->m_szSoundName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x10076B60
// Name: public: virtual void CDemoActionPlaySoundStart::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::SaveKeysToBuffer(
        CDemoActionPlaySoundStart *this,
        int depth,
        CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "sound \"%s\"\n", this->m_szSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10076BA0
// Name: public: virtual bool CBaseDemoActionWithStopTime::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoActionWithStopTime::Update(
        CBaseDemoActionWithStopTime *this,
        const DemoActionTimingContext *tc)
{
  char result; // al

  result = CBaseDemoAction::Update(this, tc);
  if ( result != 0 )
  {
    if ( CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this) )
    {
      if ( this->m_bUsingStopTick )
      {
        if ( tc->curtick >= this->m_nStopTick )
        {
          CBaseDemoAction::SetFinishedAction(this, finished: true);
          return 1;
        }
      }
      else if ( tc->curtime >= this->m_flStopTime )
      {
        CBaseDemoAction::SetFinishedAction(this, finished: true);
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076C10
// Name: public: void CBaseDemoActionWithStopTime::SetStopTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoActionWithStopTime::SetStopTick(CBaseDemoActionWithStopTime *this, int tick)
{
  this->m_bUsingStopTick = tick != -1;
  this->m_nStopTick = tick;
}

//------------------------------------------------------------------------------
// Address: 0x10076C30
// Name: public: void CDemoActionSkipAhead::SetSkipToTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionSkipAhead::SetSkipToTime(CBaseDemoActionWithStopTime *this, float t)
{
  this->m_bUsingStopTick = t == -1.0;
  this->m_flStopTime = t;
}

//------------------------------------------------------------------------------
// Address: 0x10076C70
// Name: public: float CDemoActionPausePlayback::GetPauseTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDemoActionPausePlayback::GetPauseTime(CDemoActionPausePlayback *this)
{
  return this->m_flPauseTime;
}

//------------------------------------------------------------------------------
// Address: 0x10076C80
// Name: public: virtual void CDemoActionChangePlaybackRate::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::FireAction(CDemoActionChangePlaybackRate *this)
{
  ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: this->m_flPlaybackRate);
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076CB0
// Name: public: virtual void CDemoActionPausePlayback::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::FireAction(CDemoActionPausePlayback *this)
{
  ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: this->m_flPauseTime);
  CBaseDemoAction::SetActionFired(this, fired: true);
}

//------------------------------------------------------------------------------
// Address: 0x10076CE0
// Name: FnCreateCDemoActionPausePlayback
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPausePlayback()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA8u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPausePlayback::`vftable';
  *(_DWORD *)&v1[1].m_szActionName[2] = 0;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PAUSE);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10076D20
// Name: public: virtual void CDemoActionZoom::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionZoom::FireAction(CDemoActionZoom *this)
{
  double v2; // st7

  v2 = ((double (__thiscall *)(IRender *))g_EngineRenderer->GetFov)(a1: g_EngineRenderer);
  this->m_flOriginalFOV = v2;
  scr_demo_override_fov = v2;
  this->m_flFOVStartTime = host_time;
}

//------------------------------------------------------------------------------
// Address: 0x10076D50
// Name: public: virtual void CDemoActionZoom::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionZoom::SaveKeysToBuffer(CDemoActionZoom *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "spline \"%i\"\n", this->m_bSpline);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "stayout \"%i\"\n", this->m_bStayout);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "finalfov \"%f\"\n", this->m_flFinalFOV);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovrateout \"%f\"\n", this->m_flFOVRateOut);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovratein \"%f\"\n", this->m_flFOVRateIn);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "fovhold \"%f\"\n", this->m_flHoldTime);
}

//------------------------------------------------------------------------------
// Address: 0x10076E00
// Name: FnCreateCDemoActionZoom
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionZoom()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xB4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionZoom::`vftable';
  LOWORD(v1[1].__vftable) = 0;
  v1[1].m_Type = DEMO_ACTION_UNKNOWN;
  *(_DWORD *)&v1[1].m_bActionFired = 0;
  *(_DWORD *)&v1[1].m_szActionName[2] = 0;
  *(_DWORD *)&v1[1].m_szActionName[6] = 0;
  *(_DWORD *)&v1[1].m_szActionName[10] = 0;
  *(_DWORD *)&v1[1].m_szActionName[14] = 0;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_ZOOM);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10076F00
// Name: FnCreateCDemoActionSkipAhead
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionSkipAhead()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionSkipAhead::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_SKIPAHEAD);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10076F40
// Name: FnCreateCDemoActionStopPlayback
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionStopPlayback()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x98u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionStopPlayback::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_STOPPLAYBACK);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10076F80
// Name: public: virtual bool CDemoActionPlayCommands::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionPlayCommands::Init(CDemoActionPlayCommands *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    String = KeyValues::GetString(this: pInitData, keyName: "commands", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szCommandStream, pSrc: String, maxLen: 256);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076FD0
// Name: FnCreateCDemoActionPlayCommands
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPlayCommands()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x198u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPlayCommands::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCOMMANDS);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077010
// Name: FnCreateCDemoActionScreenFadeStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionScreenFadeStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xA4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionScreenFadeStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_SCREENFADE_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077050
// Name: FnCreateCDemoActionTextMessageStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionTextMessageStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x318u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionTextMessageStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_TEXTMESSAGE_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100770D0
// Name: FnCreateCDemoActionCDTrackStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionCDTrackStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionCDTrackStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCDTRACK_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077110
// Name: FnCreateCDemoActionCDTrackStop
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionCDTrackStop()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x98u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionCDTrackStop::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYCDTRACK_STOP);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077150
// Name: public: virtual bool CDemoActionPlaySoundStart::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionPlaySoundStart::Init(CDemoActionPlaySoundStart *this, KeyValues *pInitData)
{
  char result; // al
  const char *String; // eax

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    String = KeyValues::GetString(this: pInitData, keyName: "sound", defaultValue: defaultValue);
    V_strncpy(pDest: this->m_szSoundName, pSrc: String, maxLen: 128);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100771A0
// Name: public: virtual void CDemoActionPlaySoundStart::FireAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPlaySoundStart::FireAction(CDemoActionPlaySoundStart *this)
{
  CDemoActionPlaySoundStart *v1; // ebx
  CSfxTable *v2; // edi
  CClientState *LocalClient; // eax
  StartSoundParams_t params; // [esp+Ch] [ebp-68h] BYREF
  CDemoActionPlaySoundStart *v5; // [esp+70h] [ebp-4h]

  v1 = this;
  v5 = this;
  v2 = S_PrecacheSound(name: this->m_szSoundName);
  if ( v2 != nullptr )
  {
    params.userdata = 0;
    params.delay = 0.0;
    params.speakerentity = -1;
    params.initialStreamPosition = 0;
    params.skipInitialSamples = 0;
    params.m_nQueuedGUID = -1;
    params.m_nSoundScriptHandle = -1;
    memset(&params.m_pSoundEntryName, 0, 16);
    *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 2;
    LocalClient = GetLocalClient(nSlot: -1);
    params.soundsource = CBaseClientState::GetViewEntity(this: LocalClient);
    memset(&params.origin, 0, 24);
    params.entchannel = 0;
    params.pSfx = v2;
    params.fvol = 1.0;
    params.soundlevel = SNDLVL_IDLE;
    params.flags = 0;
    params.pitch = 100;
    S_StartSound(&params);
    v1 = v5;
  }
  CBaseDemoAction::SetFinishedAction(this: v1, finished: true);
}

//------------------------------------------------------------------------------
// Address: 0x100772B0
// Name: FnCreateCDemoActionPlaySoundStart
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionPlaySoundStart()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0x118u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionPlaySoundStart::`vftable';
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_PLAYSOUND_START);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10077320
// Name: public: virtual bool CBaseDemoActionWithStopTime::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoActionWithStopTime::Init(CBaseDemoActionWithStopTime *this, KeyValues *pInitData)
{
  char result; // al
  int Int; // eax
  double Float; // st7
  float pInitDataa; // [esp+14h] [ebp+8h]

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    Int = KeyValues::GetInt(this: pInitData, keyName: "stoptick", defaultValue: -1);
    this->m_bUsingStopTick = Int != -1;
    this->m_nStopTick = Int;
    Float = KeyValues::GetFloat(this: pInitData, keyName: "stoptime", defaultValue: -1.0);
    this->m_bUsingStopTick = Float == -1.0;
    pInitDataa = Float;
    this->m_flStopTime = pInitDataa;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100773B0
// Name: public: virtual void CDemoActionChangePlaybackRate::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::SaveKeysToBuffer(
        CDemoActionChangePlaybackRate *this,
        int depth,
        CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nStopTick == -1 )
  {
    if ( this->m_flStopTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptime \"%.3f\"\n", this->m_flStopTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptick \"%i\"\n", this->m_nStopTick);
  }
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "playbackrate \"%f\"\n", this->m_flPlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x10077440
// Name: public: void CDemoActionChangePlaybackRate::SetPlaybackRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionChangePlaybackRate::SetPlaybackRate(CDemoActionChangePlaybackRate *this, float rate)
{
  int v2; // xmm1_4
  float v3; // xmm0_4

  v2 = 981668463;
  v3 = rate;
  if ( rate < 0.001 || (v2 = 1148846080, rate > 1000.0) )
    v3 = *(float *)&v2;
  this->m_flPlaybackRate = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10077480
// Name: FnCreateCDemoActionChangePlaybackRate
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl FnCreateCDemoActionChangePlaybackRate()
{
  CBaseDemoAction *v0; // eax
  CBaseDemoAction *v1; // esi

  v0 = (CBaseDemoAction *)CBaseDemoAction::operator new(sz: 0xACu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseDemoAction::CBaseDemoAction(this: v0);
  v1->__vftable = (CBaseDemoAction_vtbl *)&CDemoActionChangePlaybackRate::`vftable';
  *(_DWORD *)&v1[1].m_szActionName[2] = 1065353216;
  *(_DWORD *)&v1[1].m_szActionName[6] = 1065353216;
  CEngine::SetQuitting(this: v1, actionType: DEMO_ACTION_CHANGEPLAYBACKRATE);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100774D0
// Name: public: virtual void CDemoActionPausePlayback::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::SaveKeysToBuffer(CDemoActionPausePlayback *this, int depth, CUtlBuffer *buf)
{
  CBaseDemoAction::SaveKeysToBuffer(this, depth, buf);
  if ( this->m_nStopTick == -1 )
  {
    if ( this->m_flStopTime != -1.0 )
      CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptime \"%.3f\"\n", this->m_flStopTime);
  }
  else
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "stoptick \"%i\"\n", this->m_nStopTick);
  }
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "pausetime \"%f\"\n", this->m_flPauseTime);
}

//------------------------------------------------------------------------------
// Address: 0x10077560
// Name: public: void CDemoActionPausePlayback::SetPauseTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionPausePlayback::SetPauseTime(CDemoActionPausePlayback *this, float t)
{
  int v2; // xmm1_4
  float v3; // xmm0_4

  v2 = 0;
  v3 = t;
  if ( t < 0.0 || (v2 = 1133903872, t > 300.0) )
    v3 = *(float *)&v2;
  this->m_flPauseTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10077590
// Name: public: virtual bool CDemoActionZoom::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionZoom::Init(CDemoActionZoom *this, KeyValues *pInitData)
{
  char result; // al

  result = CBaseDemoAction::Init(this, pInitData);
  if ( result != 0 )
  {
    this->m_bSpline = KeyValues::GetInt(this: pInitData, keyName: "spline", defaultValue: 1) != 0;
    this->m_bStayout = KeyValues::GetInt(this: pInitData, keyName: "stayout", defaultValue: 1) != 0;
    this->m_flFinalFOV = KeyValues::GetFloat(this: pInitData, keyName: "finalfov", defaultValue: 0.0);
    this->m_flFOVRateOut = KeyValues::GetFloat(this: pInitData, keyName: "fovrateout", defaultValue: 0.0);
    this->m_flFOVRateIn = KeyValues::GetFloat(this: pInitData, keyName: "fovratein", defaultValue: 0.0);
    this->m_flHoldTime = KeyValues::GetFloat(this: pInitData, keyName: "fovhold", defaultValue: 0.0);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077650
// Name: public: virtual bool CDemoActionZoom::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionZoom::Update(CDemoActionZoom *this, float tc)
{
  char result; // al
  float v4; // xmm0_4
  float m_flFOVRateOut; // xmm2_4
  float m_flFinalFOV; // xmm0_4
  float v7; // xmm1_4
  float m_flFOVRateIn; // xmm2_4
  float v9; // xmm3_4
  double v10; // st7
  float m_flOriginalFOV; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float minVal; // [esp+4h] [ebp-8h] BYREF
  float maxVal; // [esp+8h] [ebp-4h] BYREF

  result = CBaseDemoAction::Update(this, tc: (const DemoActionTimingContext *)LODWORD(tc));
  if ( result == 0 )
    return result;
  if ( !CBaseDemoAction::GetActionFired((vgui::BuildGroup *)this) )
    return 1;
  v4 = host_time - this->m_flFOVStartTime;
  m_flFOVRateOut = this->m_flFOVRateOut;
  if ( v4 <= m_flFOVRateOut )
  {
    v13 = 0.0;
    if ( m_flFOVRateOut > 0.0 )
      v13 = v4 / m_flFOVRateOut;
    if ( this->m_bSpline )
      v13 = (float)((float)(v13 * 3.0) * v13) - (float)((float)((float)(v13 * 2.0) * v13) * v13);
    if ( v13 >= 0.0 )
    {
      if ( v13 > 1.0 )
        v13 = 1.0;
    }
    else
    {
      v13 = 0.0;
    }
    scr_demo_override_fov = (float)((float)(this->m_flFinalFOV - this->m_flOriginalFOV) * v13) + this->m_flOriginalFOV;
    return 1;
  }
  if ( this->m_bStayout )
  {
    m_flFinalFOV = this->m_flFinalFOV;
LABEL_6:
    scr_demo_override_fov = m_flFinalFOV;
    CBaseDemoAction::SetFinishedAction(this, finished: true);
    return 1;
  }
  v7 = this->m_flHoldTime + m_flFOVRateOut;
  if ( v7 < v4 )
  {
    m_flFOVRateIn = this->m_flFOVRateIn;
    if ( v4 > (float)(m_flFOVRateIn + v7) )
    {
      m_flFinalFOV = 0.0;
      goto LABEL_6;
    }
    v9 = 0.0;
    tc = 0.0;
    if ( m_flFOVRateIn > 0.0 )
    {
      v9 = (float)(v4 - v7) / m_flFOVRateIn;
      tc = v9;
    }
    if ( this->m_bSpline )
      tc = (float)((float)(v9 * 3.0) * v9) - (float)((float)((float)(v9 * 2.0) * v9) * v9);
    maxVal = 1.0;
    minVal = 0.0;
    v10 = clamp<float,float,float>(val: &tc, &minVal, &maxVal);
    m_flOriginalFOV = this->m_flOriginalFOV;
    v12 = this->m_flFinalFOV;
    tc = 1.0 - v10;
    scr_demo_override_fov = (float)((float)(v12 - m_flOriginalFOV) * tc) + m_flOriginalFOV;
    return 1;
  }
  else
  {
    scr_demo_override_fov = this->m_flFinalFOV;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077850
// Name: public: virtual bool CDemoActionChangePlaybackRate::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoActionChangePlaybackRate::Init(CDemoActionChangePlaybackRate *this, KeyValues *pInitData)
{
  char result; // al
  double Float; // st7
  float v5; // xmm0_4
  float pInitDataa; // [esp+14h] [ebp+8h]

  result = CBaseDemoActionWithStopTime::Init(this, pInitData);
  if ( result != 0 )
  {
    Float = KeyValues::GetFloat(this: pInitData, keyName: "playbackrate", defaultValue: 1.0);
    if ( Float >= 0.001 )
    {
      v5 = Float;
      pInitDataa = Float;
      if ( pInitDataa > 1000.0 )
        v5 = 1000.0;
      this->m_flPlaybackRate = v5;
      return 1;
    }
    else
    {
      this->m_flPlaybackRate = 0.001;
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B60
// Name: public: char const __near * CDemoActionPlaySoundStart::GetSoundName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoActionPlaySoundStart::GetSoundName(CDemoActionPlaySoundStart *this)
{
  return this->m_szSoundName;
}

} // namespace engine_xlsp
