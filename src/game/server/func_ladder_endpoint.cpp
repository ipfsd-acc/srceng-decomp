// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_ladder_endpoint.cpp
// Functions: 2
// ============================================================

#include "game\server\func_ladder_endpoint.h"

//------------------------------------------------------------------------------
// Address: 0x1013B6B0
// Name: private: bool CFuncLadderEndPoint::Validate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFuncLadderEndPoint::Validate(CFuncLadderEndPoint *this)
{
  CBaseEntity *NextTarget; // eax
  CBaseEntity *v3; // eax
  CBaseEntity *v4; // ebx
  const char *pszValue; // edi
  CFuncLadder *EntityByName; // eax
  CBaseEntity *v8; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  Vector startPos; // [esp+8h] [ebp-18h] BYREF
  Vector endPos; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  startPos = this->m_vecAbsOrigin;
  NextTarget = CBaseEntity::GetNextTarget(this);
  v3 = (CBaseEntity *)__RTDynamicCast(
                        inptr: NextTarget,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CFuncLadderEndPoint `RTTI Type Descriptor',
                        isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    if ( (v3->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    endPos = v4->m_vecAbsOrigin;
    EntityByName = (CFuncLadder *)CreateEntityByName(
                                    className: "func_useableladder",
                                    iForceEdictIndex: -1,
                                    bNotify: true);
    v8 = EntityByName;
    if ( EntityByName != nullptr )
    {
      CFuncLadder::SetEndPoints(
        this: EntityByName,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)this,
        a4: (int)EntityByName,
        p1: &startPos,
        p2: &endPos);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CBaseEntity::SetAbsOrigin(this: v8, absOrigin: &this->m_vecAbsOrigin);
      m_Index = this->m_pParent.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v8->SetParent(this: v8, a2: (CBaseEntity *)m_pEntity, a3: -1);
      CBaseEntity::SetName(this: v8, newName: this->m_iName.m_Value);
      v8->Spawn(this: v8);
    }
    UTIL_Remove(oldObj: v4);
    UTIL_Remove(oldObj: this);
    return 1;
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(a1: 1, a2: "func_ladderendpoint(%s) without matching target\n", pszValue);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B820
// Name: public: virtual void CFuncLadderEndPoint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadderEndPoint::Activate(CFuncLadderEndPoint *this)
{
  CBaseEntity::Activate(this);
  if ( (this->m_iEFlags & 1) == 0 )
    CFuncLadderEndPoint::Validate(this);
}
