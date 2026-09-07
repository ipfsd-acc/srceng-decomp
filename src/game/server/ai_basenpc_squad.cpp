// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc_squad.cpp
// Functions: 7
// ============================================================

#include "game\server\ai_basenpc_squad.h"

//------------------------------------------------------------------------------
// Address: 0x10040EE0
// Name: public: bool CAI_BaseNPC::OccupyStrategySlotRange(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::OccupyStrategySlotRange(CAI_BaseNPC *this, int slotIDStart, int slotIDEnd)
{
  CBaseEntity *v4; // eax
  BOOL result; // eax
  int *p_m_iMySquadSlot; // [esp-4h] [ebp-8h]

  result = true;
  if ( this->m_pSquad != nullptr )
  {
    p_m_iMySquadSlot = &this->m_iMySquadSlot;
    v4 = this->GetEnemy_2(this);
    if ( !CAI_Squad::OccupyStrategySlotRange(
            this: this->m_pSquad,
            pEnemy: v4,
            slotIDStart,
            slotIDEnd,
            pSlot: p_m_iMySquadSlot) )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040F30
// Name: public: void CAI_BaseNPC::VacateStrategySlot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::VacateStrategySlot(CAI_BaseNPC *this)
{
  CBaseEntity *v2; // eax
  int m_iMySquadSlot; // [esp-4h] [ebp-8h]

  if ( this->m_pSquad != nullptr )
  {
    m_iMySquadSlot = this->m_iMySquadSlot;
    v2 = this->GetEnemy_2(this);
    CAI_Squad::VacateStrategySlot(this: this->m_pSquad, pEnemy: v2, slot: m_iMySquadSlot);
    this->m_iMySquadSlot = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040F70
// Name: public: virtual void CAI_BaseNPC::SetSquad(class CAI_Squad __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetSquad(CAI_BaseNPC *this, CAI_Squad *pSquad)
{
  CAI_Squad *m_pSquad; // eax

  m_pSquad = this->m_pSquad;
  if ( m_pSquad != pSquad )
  {
    if ( m_pSquad != nullptr && this->m_iMySquadSlot != -1 )
      CAI_BaseNPC::VacateStrategySlot(this);
    this->m_pSquad = pSquad;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040FB0
// Name: public: virtual bool CAI_BaseNPC::IsValidShootPosition(class Vector const __near &,class CAI_Node __near *,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsValidShootPosition(
        CAI_BaseNPC *this,
        const Vector *vecShootLocation,
        CAI_Node *pNode,
        const CAI_Hint *pHint)
{
  const char *pszValue; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pszValue = this->m_strHintGroup.pszValue;
  if ( pszValue == nullptr || pHint != nullptr && pHint->m_NodeData.strGroup.pszValue == pszValue )
    return true;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  return (float)((float)((float)(vecShootLocation->x - this->m_vecAbsOrigin.x)
                       * (float)(vecShootLocation->x - this->m_vecAbsOrigin.x))
               + (float)((float)(vecShootLocation->y - this->m_vecAbsOrigin.y)
                       * (float)(vecShootLocation->y - this->m_vecAbsOrigin.y))) <= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10041030
// Name: public: bool CAI_BaseNPC::IsSquadmateInSpread(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::IsSquadmateInSpread(
        CAI_BaseNPC *this,
        const Vector *sourcePos,
        const Vector *targetPos,
        float flSpread,
        float maxDistOffCenter)
{
  CAI_Squad *m_pSquad; // ecx
  CAI_BaseNPC *FirstMember; // esi
  AISquadIter_t__ *iter; // [esp+14h] [ebp-4h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  m_pSquad = this->m_pSquad;
  if ( m_pSquad == nullptr )
    return 0;
  FirstMember = CAI_Squad::GetFirstMember(this: m_pSquad, pIter: &iter, bIgnoreSilentMembers: true);
  if ( FirstMember == nullptr )
    return 0;
  while ( 1 )
  {
    if ( FirstMember->m_takedamage.m_Value != 0 && FirstMember != this )
    {
      if ( (FirstMember->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: FirstMember, a2: (int)&savedregs);
      if ( CAI_BaseNPC::PointInSpread(
             this,
             pCheckEntity: FirstMember,
             sourcePos,
             (const Vector2D *)targetPos,
             testPoint: &FirstMember->m_vecAbsOrigin,
             flSpread,
             maxDistOffCenter) )
      {
        break;
      }
    }
    FirstMember = CAI_Squad::GetNextMember(this: this->m_pSquad, pIter: &iter, bIgnoreSilentMembers: true);
    if ( FirstMember == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100410E0
// Name: public: void CAI_BaseNPC::CheckSquad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::CheckSquad(CAI_BaseNPC *this)
{
  CAI_Squad *m_pSquad; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  CAI_BaseNPC *i; // edi
  IPhysicsObject *v5; // ecx
  const char *pszValue; // eax
  const char *v7; // eax
  const char *DebugName; // [esp-Ch] [ebp-14h]
  AISquadIter_t__ *iter; // [esp+4h] [ebp-4h] BYREF

  m_pSquad = this->m_pSquad;
  if ( m_pSquad != nullptr && CAI_Squad::IsLeader(this: m_pSquad, pNPC: this) )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject == nullptr
      || (((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) == 0 )
    {
      for ( i = CAI_Squad::GetFirstMember(this: this->m_pSquad, pIter: &iter, bIgnoreSilentMembers: true);
            i != nullptr;
            i = CAI_Squad::GetNextMember(this: this->m_pSquad, pIter: &iter, bIgnoreSilentMembers: true) )
      {
        if ( this->IRelationType(this, a2: i) < D_LI )
        {
          v5 = i->m_pPhysicsObject;
          if ( v5 == nullptr || (((int (__thiscall *)(IPhysicsObject *))v5->GetGameFlags)(a1: v5) & 4) == 0 )
          {
            pszValue = this->m_pSquad->m_Name.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            _Warning(a1: "ERROR: Squad '%s' has enemies in it!\n", pszValue);
            DebugName = CBaseEntity::GetDebugName(this: i);
            v7 = CBaseEntity::GetDebugName(this);
            _Warning(a1: "%s doesn't like %s\n\n", v7, DebugName);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100411C0
// Name: public: virtual bool CAI_BaseNPC::IsValidCover(class Vector const __near &,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsValidCover(CAI_BaseNPC *this, const Vector *vecCoverLocation, const CAI_Hint *pHint)
{
  const char *pszValue; // eax
  float v6; // xmm0_4
  unsigned int m_nAITraceMask; // eax
  Hull_t m_eHull; // [esp-8h] [ebp-78h]
  CGameTrace tr; // [esp+4h] [ebp-6Ch] BYREF
  Vector endPos; // [esp+58h] [ebp-18h] BYREF
  Vector startPos; // [esp+64h] [ebp-Ch]

  pszValue = this->m_strHintGroup.pszValue;
  if ( pszValue != nullptr && *pszValue != 0 && (pHint == nullptr || pHint->m_NodeData.strGroup.pszValue != pszValue) )
    return false;
  startPos.z = vecCoverLocation->z;
  m_eHull = this->m_eHull;
  *(_QWORD *)&startPos.x = *(_QWORD *)&vecCoverLocation->x;
  v6 = startPos.z - NAI_Hull::Mins(id: m_eHull)->z;
  m_nAITraceMask = this->m_nAITraceMask;
  startPos.z = v6;
  *(_QWORD *)&endPos.x = *(_QWORD *)&startPos.x;
  endPos.z = v6 + 0.01;
  UTIL_TraceEntity(pEntity: this, vecAbsStart: vecCoverLocation, vecAbsEnd: &endPos, mask: m_nAITraceMask, ptr: &tr);
  return !tr.startsolid;
}
