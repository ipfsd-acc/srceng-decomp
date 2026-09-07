// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_playmovie.cpp
// Functions: 8
// ============================================================

#include "game\server\logic_playmovie.h"

//------------------------------------------------------------------------------
// Address: 0x10166AE0
// Name: public: virtual struct datamap_t __near * CLogicPlayMovie::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicPlayMovie::GetDataDescMap(CLogicPlayMovie *this)
{
  return &CLogicPlayMovie::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10166AF0
// Name: private: void CLogicPlayMovie::InputMovieFinished(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayMovie::InputMovieFinished(CLogicPlayMovie *this, inputdata_t *data)
{
  COutputEvent::FireOutput(this: &this->m_OnPlaybackFinished, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10166B10
// Name: private: void CLogicPlayMovie::InputPlayMovie(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayMovie::InputPlayMovie(CLogicPlayMovie *this, inputdata_t *data)
{
  const char *v2; // edx
  const char *pszValue; // eax
  const char *v4; // ecx
  char szClientCmd[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = "playvideo_exitcommand";
  if ( !this->m_bAllowUserSkip )
    v2 = "playvideo_exitcommand_nointerrupt";
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = this->m_strMovieFilename.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  V_snprintf(pDest: szClientCmd, maxLen: 256, pFormat: "%s %s end_movie %s\n", v2, v4, pszValue);
  engine->ServerCommand(this: engine, a2: szClientCmd);
}

//------------------------------------------------------------------------------
// Address: 0x10166B90
// Name: private: void CLogicPlayMovie::InputPlayMovieForAllPlayers(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayMovie::InputPlayMovieForAllPlayers(CLogicPlayMovie *this, inputdata_t *data)
{
  const char *v2; // esi
  const char *pszValue; // edx
  const char *v4; // eax
  char v5; // bl
  int v6; // esi
  CBasePlayer *v7; // eax
  signed int m_pPev; // eax
  int i; // esi
  CBasePlayer *v10; // eax
  char szClientCmd[256]; // [esp+Ch] [ebp-100h] BYREF

  v2 = "playvideo_exitcommand";
  if ( !this->m_bAllowUserSkip )
    v2 = "playvideo_exitcommand_nointerrupt";
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = this->m_strMovieFilename.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  V_snprintf(pDest: szClientCmd, maxLen: 256, pFormat: "%s %s end_movie %s\n", v2, v4, pszValue);
  v5 = 0;
  v6 = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    while ( 1 )
    {
      v7 = UTIL_PlayerByIndex(playerIndex: v6);
      if ( v7 != nullptr )
      {
        m_pPev = (signed int)v7->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        if ( engine->IsSplitScreenPlayer(this: engine, a2: m_pPev) )
          break;
      }
      if ( ++v6 > gpGlobals->maxClients )
        goto LABEL_15;
    }
    v5 = 1;
  }
LABEL_15:
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v10 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v10 != nullptr )
    {
      engine->ClientCommand(this: engine, a2: v10->m_Network.m_pPev, a3: szClientCmd);
      if ( v5 != 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166CA0
// Name: private: void CLogicPlayMovie::InputPlayLevelTransitionMovie(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayMovie::InputPlayLevelTransitionMovie(CLogicPlayMovie *this, inputdata_t *data)
{
  float m_bFadeInTime; // xmm0_4
  const char *pszValue; // eax
  int i; // esi
  CBasePlayer *v5; // eax
  char szClientCmd[256]; // [esp+Ch] [ebp-100h] BYREF

  m_bFadeInTime = this->m_bFadeInTime;
  if ( m_bFadeInTime < 0.1 )
    m_bFadeInTime = 0.1;
  this->m_bFadeInTime = m_bFadeInTime;
  pszValue = this->m_strMovieFilename.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(
    pDest: szClientCmd,
    maxLen: 256,
    pFormat: "%s %s %f\n",
    "playvideo_end_level_transition",
    pszValue,
    m_bFadeInTime);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v5 != nullptr )
      engine->ClientCommand(this: engine, a2: v5->m_Network.m_pPev, a3: szClientCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166D60
// Name: private: void CLogicPlayMovie::InputFadeAllMovies(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayMovie::InputFadeAllMovies(CLogicPlayMovie *this, inputdata_t *data)
{
  int i; // esi
  CBasePlayer *v3; // eax
  char szClientCmd[256]; // [esp+Ch] [ebp-100h] BYREF

  V_snprintf(pDest: szClientCmd, maxLen: 256, pFormat: "%s %f\n", "stopvideos_fadeout", 1.0);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v3 != nullptr )
      engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: szClientCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405790
// Name: CLogicPlayMovie_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicPlayMovie_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicPlayMovie>();
  CLogicPlayMovie_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166E30
// Name: class CLogicPlayMovie __near * _CreateEntityTemplate<class CLogicPlayMovie>(class CLogicPlayMovie __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicPlayMovie *__cdecl _CreateEntityTemplate<CLogicPlayMovie>(CLogicPlayMovie *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CLogicPlayMovie::`vftable';
    v3[216] = 0;
    v3[219] = -1;
    v3[220] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicPlayMovie *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
