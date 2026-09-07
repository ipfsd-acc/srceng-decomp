// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_activity.cpp
// Functions: 4
// ============================================================

#include "game\server\ai_activity.h"

//------------------------------------------------------------------------------
// Address: 0x10005D10
// Name: public: static void CAI_BaseNPC::AddActivityToSR(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_BaseNPC::AddActivityToSR(const char *actName, int actID)
{
  if ( CAI_BaseNPC::m_pActivitySR != nullptr
    && CStringRegistry::GetStringID(this: CAI_BaseNPC::m_pActivitySR, stringText: actName) == -1 )
  {
    lastActID = actID;
    CStringRegistry::AddString(this: CAI_BaseNPC::m_pActivitySR, stringText: actName, stringID: actID);
    ++CAI_BaseNPC::m_iNumActivities;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D50
// Name: public: static char const __near * CAI_BaseNPC::GetActivityName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAI_BaseNPC::GetActivityName(int actID)
{
  if ( actID == -1 )
    return "ACT_INVALID";
  else
    return ActivityList_NameForIndex(activityIndex: actID);
}

//------------------------------------------------------------------------------
// Address: 0x10005D70
// Name: public: static int CAI_BaseNPC::GetActivityID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_BaseNPC::GetActivityID(const char *actName)
{
  if ( CAI_BaseNPC::m_pActivitySR != nullptr )
    return CStringRegistry::GetStringID(this: CAI_BaseNPC::m_pActivitySR, stringText: actName);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10005DB0
// Name: private: static void CAI_BaseNPC::InitDefaultActivitySR(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None
