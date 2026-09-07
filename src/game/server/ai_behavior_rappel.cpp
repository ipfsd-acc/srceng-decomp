// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_rappel.cpp
// Functions: 8
// ============================================================

#include "game\server\ai_behavior_rappel.h"

//------------------------------------------------------------------------------
// Address: 0x10048350
// Name: public: virtual struct datamap_t __near * CRopeAnchor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRopeAnchor::GetDataDescMap(CRopeAnchor *this)
{
  return &CRopeAnchor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10048360
// Name: public: void CRopeAnchor::RemoveThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeAnchor::RemoveThink(CRopeAnchor *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hRope.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  UTIL_Remove(oldObj: m_pEntity);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100483D0
// Name: public: void CRopeAnchor::FallThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeAnchor::FallThink(CRopeAnchor *this)
{
  __int64 v2; // xmm0_8
  Vector vecVelocity; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  v2 = *(_QWORD *)&this->m_vecAbsVelocity.x;
  vecVelocity.z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecVelocity.x = v2;
  vecVelocity.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1041235968,
                    a3: 1106247680);
  vecVelocity.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1041235968,
                    a3: 1106247680);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecVelocity);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CRopeAnchor::RemoveThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 3.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100484C0
// Name: public: virtual void CRopeAnchor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRopeAnchor::Spawn(CRopeAnchor *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  float v4; // xmm0_4
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // edi
  CRopeKeyframe *v12; // eax

  CPointEntity::Spawn(this);
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  v4 = 384.0;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      if ( (v11->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v11, a2);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      LODWORD(v4) = COERCE_UNSIGNED_INT(v11->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z) & _mask__AbsFloat_;
    }
  }
  v12 = CRopeKeyframe::CreateWithSecondPointDetached(
          pStartEnt: this,
          iStartAttachment: -1,
          ropeLength: (int)v4,
          ropeWidth: 1,
          pMaterialName: "cable/cable.vmt",
          numSegments: 5,
          bInitialHang: true,
          pClassName: "keyframe_rope");
  if ( v12 != nullptr )
    this->m_hRope.m_Index = v12->GetRefEHandle(this: v12)->m_Index;
  else
    this->m_hRope.m_Index = -1;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CRopeAnchor::FallThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10048630
// Name: public: void CBeam::SetWidth(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetWidth(CBeam *this, float width)
{
  float v2; // xmm0_4
  CNetworkVarBase<float,CBeam::NetworkVar_m_fWidth> *p_m_fWidth; // esi
  edict_t *m_pPev; // ecx

  v2 = width;
  if ( width > 102.3 )
    v2 = 102.3;
  p_m_fWidth = &this->m_fWidth;
  if ( this->m_fWidth.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fWidth->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C4u);
      p_m_fWidth->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100486A0
// Name: public: void CBeam::SetEndWidth(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetEndWidth(CBeam *this, float endWidth)
{
  float v2; // xmm0_4
  CNetworkVarBase<float,CBeam::NetworkVar_m_fEndWidth> *p_m_fEndWidth; // esi
  edict_t *m_pPev; // ecx

  v2 = endWidth;
  if ( endWidth > 102.3 )
    v2 = 102.3;
  p_m_fEndWidth = &this->m_fEndWidth;
  if ( this->m_fEndWidth.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fEndWidth->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C8u);
      p_m_fEndWidth->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FB8C0
// Name: CAI_RappelBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_RappelBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_RappelBehavior>(__formal: nullptr);
  CAI_RappelBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB8D0
// Name: CRopeAnchor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRopeAnchor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRopeAnchor>(__formal: nullptr);
  CRopeAnchor_DataDescInit::g_DataMapHolder = result;
  return result;
}
