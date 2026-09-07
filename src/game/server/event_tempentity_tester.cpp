// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/event_tempentity_tester.cpp
// Functions: 3
// ============================================================

#include "game\server\event_tempentity_tester.h"

//------------------------------------------------------------------------------
// Address: 0x10325340
// Name: public: static class CBaseEntity __near * CTempEntTester::Create(class Vector const __near &,class QAngle const __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CTempEntTester::Create(
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        const char *lifetime,
        const char *single_te)
{
  int v4; // eax
  double v5; // xmm0_8
  float v6; // xmm0_4
  double v7; // xmm0_8
  CBaseEntity *result; // eax
  float *v9; // esi
  void (__thiscall *v10)(float *); // eax
  char classname[128]; // [esp+0h] [ebp-80h] BYREF
  float life; // [esp+90h] [ebp+10h]

  if ( lifetime != nullptr
    && *lifetime != 0
    && ((float)(v4 = atoi(nptr: lifetime)) >= 1.0 ? (v5 = (float)v4) : (v5 = 1.0),
        (v6 = v5) <= 1000.0 ? (v7 = v6) : (v7 = 1000.0),
        (life = (float)v7 + gpGlobals->curtime, single_te != nullptr) && *single_te != 0) )
  {
    V_strncpy(pDest: classname, pSrc: single_te, maxLen: 128);
    strlwr(string: classname);
    result = CBaseEntity::CreateNoSpawn(szName: "te_tester", vecOrigin, vecAngles, pOwner: nullptr);
    v9 = (float *)result;
    if ( result != nullptr )
    {
      V_strncpy(pDest: (char *)&result[1].m_pfnThink, pSrc: classname, maxLen: 64);
      v10 = *(void (__thiscall **)(float *))(*(_DWORD *)v9 + 96);
      v9[214] = life;
      v10(a1: v9);
      return (CBaseEntity *)v9;
    }
  }
  else
  {
    _Msg(a1: "Usage:  te <lifetime> <entname>\n");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325450
// Name: public: virtual void CTempEntTester::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntTester::Spawn(CTempEntTester *this)
{
  CBaseTempEntity *List; // eax
  const char *v3; // eax
  int v4; // eax
  CBaseTempEntity *Next; // eax
  char name[128]; // [esp+Ch] [ebp-80h] BYREF

  CBaseEntity::AddEffects(this, nEffects: 32);
  List = CBaseTempEntity::GetList();
  this->m_pCurrent = List;
  if ( List != nullptr )
  {
    do
    {
      v3 = CBaseTempEntity::GetName(this: this->m_pCurrent);
      V_strncpy(pDest: name, pSrc: v3, maxLen: 128);
      strlwr(string: name);
      strstr(str1: (unsigned __int8 *)name, str2: (unsigned __int8 *)this->m_szClass);
      if ( v4 != 0 )
        break;
      Next = (CBaseTempEntity *)CBaseTempEntity::GetNext(this: (CBaseAchievement *)this->m_pCurrent);
      this->m_pCurrent = Next;
    }
    while ( Next != nullptr );
  }
  if ( this->m_pCurrent != nullptr )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    DevMsg(a1: "Couldn't find temp entity '%s'\n", this->m_szClass);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325520
// Name: public: virtual void CTempEntTester::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntTester::Think(CTempEntTester *this)
{
  if ( this->m_pCurrent == nullptr
    || (this->m_pCurrent->Test(
          this: this->m_pCurrent,
          a2: (const Vector *)&this->m_vecOrigin,
          a3: (const QAngle *)&this->m_angRotation),
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr),
        gpGlobals->curtime >= this->m_fLifeTime) )
  {
    UTIL_Remove(oldObj: this);
  }
}
