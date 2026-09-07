// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/bot_util.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102CFEA0
// Name: int UTIL_ClientsInGame(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_ClientsInGame()
{
  int v0; // esi
  int i; // edi

  v0 = 1;
  for ( i = 0; v0 <= gpGlobals->maxClients; ++v0 )
  {
    if ( UTIL_PlayerByIndex(playerIndex: v0) != nullptr )
      ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102CFEE0
// Name: int UTIL_HumansOnTeam(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_HumansOnTeam(int teamID, bool isAlive)
{
  int v2; // edi
  int i; // ebx
  CBasePlayer *v4; // eax
  CBaseEntity *v5; // esi

  v2 = 1;
  for ( i = 0; v2 <= gpGlobals->maxClients; ++v2 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: v2);
    v5 = v4;
    if ( v4 != nullptr
      && !v4->IsBot(this: v4)
      && CBaseEntity::GetTeamNumber(this: v5) == teamID
      && (!isAlive || v5->IsAlive(this: v5)) )
    {
      ++i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102CFF50
// Name: int UTIL_BotsInGame(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_BotsInGame()
{
  int v0; // esi
  int i; // edi
  CBasePlayer *v2; // eax

  v0 = 1;
  for ( i = 0; v0 <= gpGlobals->maxClients; ++v0 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v0);
    if ( v2 != nullptr && v2->IsBot(this: v2) )
      ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102CFFA0
// Name: bool UTIL_KickBotFromTeam(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_KickBotFromTeam(int kickTeam)
{
  CGlobalVars *v1; // eax
  int v2; // edi
  CBasePlayer *v3; // esi
  int v4; // edi
  IVEngineServer_vtbl *v6; // edi
  const char *v7; // eax
  char *v8; // eax

  v1 = gpGlobals;
  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
  {
LABEL_7:
    v4 = 1;
    if ( v1->maxClients < 1 )
      return 0;
    while ( 1 )
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v4);
      if ( v3 != nullptr && v3->IsBot(this: v3) && CBaseEntity::GetTeamNumber(this: v3) == kickTeam )
        break;
      if ( ++v4 > gpGlobals->maxClients )
        return 0;
    }
    v6 = engine->__vftable;
  }
  else
  {
    while ( 1 )
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      if ( v3 != nullptr
        && v3->IsBot(this: v3)
        && !v3->IsAlive(this: v3)
        && CBaseEntity::GetTeamNumber(this: v3) == kickTeam )
      {
        break;
      }
      v1 = gpGlobals;
      if ( ++v2 > gpGlobals->maxClients )
        goto LABEL_7;
    }
    v6 = engine->__vftable;
  }
  v7 = v3->GetPlayerName(this: v3);
  v8 = UTIL_VarArgs(format: "kick \"%s\"\n", v7);
  v6->ServerCommand(this: engine, a2: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D0090
// Name: bool UTIL_IsTeamAllBots(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsTeamAllBots(int team)
{
  int v1; // edi
  int v2; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi

  v1 = 1;
  v2 = 0;
  if ( gpGlobals->maxClients < 1 )
    return v2 != 0;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v1);
    v4 = v3;
    if ( v3 != nullptr && CBaseEntity::GetTeamNumber(this: v3) == team )
    {
      if ( !v4->IsBot(this: v4) )
        break;
      ++v2;
    }
    if ( ++v1 > gpGlobals->maxClients )
      return v2 != 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x102D00F0
// Name: void UTIL_ConstructBotNetName(char __near *,int,class BotProfile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ConstructBotNetName(char *name, int nameLength, const BotProfile *profile)
{
  const BotProfile *v3; // edi
  char *m_pszString; // eax
  const char *v5; // ebx
  int v6; // ecx
  char *WeaponPreferenceAsString; // esi
  const char *TranslatedWeaponAlias; // eax
  unsigned __int16 v9; // di
  CStringRegistry *v10; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  CSWeaponType *v12; // eax
  char *v13; // eax
  char wpnName[128]; // [esp+14h] [ebp-114h] BYREF
  char prefix[64]; // [esp+94h] [ebp-94h] BYREF
  char temp[64]; // [esp+D4h] [ebp-54h] BYREF
  char skillStr[20]; // [esp+114h] [ebp-14h] BYREF

  v3 = profile;
  if ( profile != nullptr )
  {
    if ( (cv_bot_prefix.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cv_bot_prefix.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)locale;
    }
    if ( strlen(m_pszString) != 0 )
    {
      v5 = BotDifficultyName[0];
      v6 = 3;
      while ( ((1 << v6) & profile->m_difficultyFlags) == 0 )
      {
        if ( --v6 <= 0 )
          goto LABEL_13;
      }
      v5 = BotDifficultyName[v6];
LABEL_13:
      if ( profile->m_weaponPreferenceCount == 0 )
        goto LABEL_18;
      WeaponPreferenceAsString = (char *)BotProfile::GetWeaponPreferenceAsString(this: profile, i: 0);
      TranslatedWeaponAlias = GetTranslatedWeaponAlias(szAlias: WeaponPreferenceAsString);
      V_snprintf(pDest: wpnName, maxLen: 128, pFormat: "weapon_%s", TranslatedWeaponAlias);
      v9 = LookupWeaponInfoSlot(name: wpnName);
      if ( v9 != (unsigned __int16)GetInvalidWeaponInfoHandle(this: v10) )
      {
        FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v9);
        v12 = (CSWeaponType *)__RTDynamicCast(
                                inptr: FileWeaponInfoFromHandle,
                                VfDelta: 0,
                                SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
                                TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
                                isReference: 0);
        if ( v12 != nullptr )
          WeaponPreferenceAsString = WeaponClassAsString(weaponType: v12[467]);
      }
      v3 = profile;
      if ( WeaponPreferenceAsString == nullptr )
LABEL_18:
        WeaponPreferenceAsString = (char *)locale;
      V_snprintf(pDest: skillStr, maxLen: 16, pFormat: "%.0f", (float)(v3->m_skill * 100.0));
      if ( (cv_bot_prefix.m_nFlags & 0x1000) != 0 )
      {
        v13 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v13 = cv_bot_prefix.m_pParent->m_Value.m_pszString;
        if ( v13 == nullptr )
          v13 = (char *)locale;
      }
      V_strncpy(pDest: temp, pSrc: v13, maxLen: 64);
      V_StrSubst(pIn: temp, pMatch: "<difficulty>", pReplaceWith: v5, pOut: prefix, outLen: 64, bCaseSensitive: false);
      V_StrSubst(
        pIn: prefix,
        pMatch: "<weaponclass>",
        pReplaceWith: WeaponPreferenceAsString,
        pOut: temp,
        outLen: 64,
        bCaseSensitive: false);
      V_StrSubst(pIn: temp, pMatch: "<skill>", pReplaceWith: skillStr, pOut: prefix, outLen: 64, bCaseSensitive: false);
      V_snprintf(pDest: name, maxLen: nameLength, pFormat: "%s %s", prefix, v3->m_name);
    }
    else
    {
      V_strncpy(pDest: name, pSrc: profile->m_name, maxLen: nameLength);
    }
  }
  else
  {
    *name = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D02F0
// Name: void UTIL_DrawBeamPoints(class Vector,class Vector,int,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DrawBeamPoints(
        Vector vecStart,
        Vector vecEnd,
        int iLifetime,
        unsigned __int8 bRed,
        unsigned __int8 bGreen,
        unsigned __int8 bBlue)
{
  NDebugOverlay::Line(origin: &vecStart, target: &vecEnd, r: bRed, g: bGreen, b: bBlue, noDepthTest: 1, duration: 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x102D0330
// Name: void CONSOLE_ECHO(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CONSOLE_ECHO(char *pszMsg, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, pszMsg);
  vsprintf(string: szStr, format: pszMsg, ap);
  _Msg(a1: "%s", szStr);
}

//------------------------------------------------------------------------------
// Address: 0x102D0360
// Name: void InitBotTrig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitBotTrig()
{
  int i; // esi
  __m128d v1; // xmm0
  __m128i v2; // xmm0
  double v3; // xmm0_8

  for ( i = 0; i < 256; ++i )
  {
    v1 = 0;
    v1.m128d_f64[0] = (double)i * 6.283185307179586 * 0.00392156862745098;
    v2 = (__m128i)_mm_cvtpd_ps(v1);
    *(double *)v2.m128i_i64 = *(float *)v2.m128i_i32;
    __libm_sse2_cos(X: v2);
    *(float *)&v3 = v3;
    cosTable[i] = *(float *)&v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D03B0
// Name: float BotCOS(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl BotCOS(float angle)
{
  return cosTable[(int)(AngleNormalizePositive(angle) * 255.0 * 0.0027777778)];
}

//------------------------------------------------------------------------------
// Address: 0x102D03E0
// Name: float BotSIN(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl BotSIN(float angle)
{
  return cosTable[(int)(AngleNormalizePositive(angle: angle - 90.0) * 255.0 * 0.0027777778)];
}

//------------------------------------------------------------------------------
// Address: 0x102D0420
// Name: bool WildcardMatch(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WildcardMatch(const char *query, const char *test)
{
  const char *v2; // edi
  const char *v3; // esi
  char v4; // bl
  const char *querya; // [esp+10h] [ebp+8h]

  v2 = query;
  if ( query != nullptr )
  {
    v3 = test;
    if ( test != nullptr )
    {
      v4 = *test;
      if ( *test != 0 )
      {
        while ( *v2 != 0 )
        {
          querya = (const char *)tolower(c: *v2);
          if ( (const char *)tolower(c: v4) == querya )
          {
            v4 = *++v3;
            ++v2;
            if ( v4 != 0 )
              continue;
          }
          goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        if ( *v2 != 0 )
          return *v2 == 42;
      }
      if ( *v3 == 0 )
        return 1;
      return *v2 == 42;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102D0490
// Name: bool UTIL_IsNameTaken(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_IsNameTaken(const char *name, bool ignoreHumans)
{
  int v2; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  void *v5; // eax
  const char *v6; // eax

  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v2);
    v4 = v3;
    if ( v3 != nullptr )
    {
      if ( v3->IsPlayer(this: v3) && v4->IsBot(this: v4) )
        break;
      if ( !ignoreHumans )
      {
        v6 = v4->GetPlayerName(this: v4);
        goto LABEL_10;
      }
    }
LABEL_12:
    if ( ++v2 > gpGlobals->maxClients )
      return 0;
  }
  v5 = __RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &CBasePlayer `RTTI Type Descriptor',
         TargetType: &CCSBot `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 == nullptr )
    goto LABEL_12;
  v6 = **((const char ***)v5 + 1768);
  if ( v6 == nullptr )
    goto LABEL_12;
LABEL_10:
  if ( name != v6 && _V_stricmp(s1: name, s2: v6) != 0 )
    goto LABEL_12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D0550
// Name: class CBasePlayer __near * UTIL_GetClosestPlayer(class Vector const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_GetClosestPlayer(const Vector *pos, float *distance)
{
  int v2; // edi
  CBaseEntity *v3; // ebx
  CBasePlayer *v4; // eax
  CBaseEntity *v5; // esi
  edict_t *m_pPev; // eax
  float v7; // xmm2_4
  Vector playerOrigin; // [esp+0h] [ebp-10h] BYREF
  float closeDistSq; // [esp+Ch] [ebp-4h]

  v2 = 1;
  v3 = nullptr;
  for ( closeDistSq = 1.0e12; v2 <= gpGlobals->maxClients; ++v2 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: v2);
    v5 = v4;
    if ( v4 != nullptr )
    {
      m_pPev = v4->m_Network.m_pPev;
      if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 && v5->IsAlive(this: v5) )
      {
        GetCentroid(result: &playerOrigin, player: v5);
        v7 = (float)(playerOrigin.z - pos->z) * (float)(playerOrigin.z - pos->z);
        if ( closeDistSq > (float)((float)((float)((float)(playerOrigin.x - pos->x) * (float)(playerOrigin.x - pos->x))
                                         + (float)((float)(playerOrigin.y - pos->y) * (float)(playerOrigin.y - pos->y)))
                                 + v7) )
        {
          closeDistSq = (float)((float)((float)(playerOrigin.x - pos->x) * (float)(playerOrigin.x - pos->x))
                              + (float)((float)(playerOrigin.y - pos->y) * (float)(playerOrigin.y - pos->y)))
                      + v7;
          v3 = v5;
        }
      }
    }
  }
  if ( distance != nullptr )
    *distance = fsqrt(closeDistSq);
  return (CBasePlayer *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x102D0640
// Name: bool UTIL_IsVisibleToTeam(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_IsVisibleToTeam(const Vector *spot, int team)
{
  int v2; // edi
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi
  const Vector *v5; // eax
  CGameTrace v7; // [esp+Ch] [ebp-60h] BYREF
  Vector v8; // [esp+60h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+6Ch] [ebp+0h] BYREF

  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v2);
    v4 = v3;
    if ( v3 != nullptr && v3->IsAlive(this: v3) && CBaseEntity::GetTeamNumber(this: v4) == team )
    {
      v5 = v4->EyePosition(this: v4, result: &v8);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)v4,
        vecAbsStart: v5,
        vecAbsEnd: spot,
        mask: 1u,
        ignore: v4,
        collisionGroup: 0,
        ptr: &v7);
      if ( v7.fraction == 1.0 )
        break;
    }
    if ( ++v2 > gpGlobals->maxClients )
      return 0;
  }
  return 1;
}
