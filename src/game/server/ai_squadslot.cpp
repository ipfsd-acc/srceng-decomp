// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_squadslot.cpp
// Functions: 2
// ============================================================

#include "game\server\ai_squadslot.h"

//------------------------------------------------------------------------------
// Address: 0x1008CC80
// Name: public: virtual char const __near * CAI_BaseNPC::GetSquadSlotDebugName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BaseNPC::GetSquadSlotDebugName(CAI_BaseNPC *this, int iSquadSlot)
{
  const char *result; // eax

  switch ( iSquadSlot )
  {
    case -1:
      result = "None";
      break;
    case 0:
      result = "SQUAD_SLOT_ATTACK1";
      break;
    case 1:
      result = "SQUAD_SLOT_ATTACK2";
      break;
    case 2:
      result = "SQUAD_SLOT_INVESTIGATE_SOUND";
      break;
    case 3:
      result = "SQUAD_SLOT_EXCLUSIVE_HANDSIGN";
      break;
    case 4:
      result = "SQUAD_SLOT_EXCLUSIVE_RELOAD";
      break;
    case 5:
      result = "SQUAD_SLOT_PICKUP_WEAPON1";
      break;
    case 6:
      result = "SQUAD_SLOT_PICKUP_WEAPON2";
      break;
    case 7:
      result = "SQUAD_SLOT_SPECIAL_ATTACK";
      break;
    default:
      result = "Failed to specify!";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008CD20
// Name: private: static void CAI_BaseNPC::InitDefaultSquadSlotSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_BaseNPC::InitDefaultSquadSlotSR()
{
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_ATTACK1",
    symbolID: 1000000000);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_ATTACK2",
    symbolID: 1000000001);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_INVESTIGATE_SOUND",
    symbolID: 1000000002);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_EXCLUSIVE_HANDSIGN",
    symbolID: 1000000003);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_EXCLUSIVE_RELOAD",
    symbolID: 1000000004);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_PICKUP_WEAPON1",
    symbolID: 1000000005);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_PICKUP_WEAPON2",
    symbolID: 1000000006);
  CAI_GlobalNamespace::AddSymbol(
    this: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pszSymbol: "SQUAD_SLOT_SPECIAL_ATTACK",
    symbolID: 1000000007);
}
