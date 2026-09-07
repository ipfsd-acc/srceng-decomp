// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fish.cpp
// Functions: 34
// ============================================================

#include "game\server\fish.h"

//------------------------------------------------------------------------------
// Address: 0x10127C50
// Name: public: virtual struct datamap_t __near * CFish::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFish::GetDataDescMap(CFish *this)
{
  return &CFish::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127C60
// Name: void SendProxy_FishAngle(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_FishAngle(const SendProp *pProp, const void *pStruct, float *pData, DVariant *pOut)
{
  float i; // xmm0_4

  for ( i = *pData; i > 360.0; i = i - 360.0 )
    ;
  if ( i >= 0.0 )
  {
    pOut->m_Float = i;
  }
  else
  {
    do
      i = i + 360.0;
    while ( i < 0.0 );
    pOut->m_Float = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127CB0
// Name: public: virtual class ServerClass __near * CFish::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFish::GetServerClass(CFish *this)
{
  return &g_CFish_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10127CC0
// Name: public: virtual struct datamap_t __near * CFishPool::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFishPool::GetDataDescMap(CFishPool *this)
{
  return &CFishPool::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127CD0
// Name: public: virtual bool CFishPool::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFishPool::KeyValue(CFishPool *this, char *szKeyName, const char *szValue)
{
  long double v5; // st7
  const char *v6; // ebx

  if ( szKeyName != "fish_count" && _V_stricmp(s1: szKeyName, s2: "fish_count") != 0 )
  {
    if ( szKeyName != "max_range" && _V_stricmp(s1: szKeyName, s2: "max_range") != 0 )
    {
      v6 = szValue;
      if ( szKeyName == "model" || _V_stricmp(s1: szKeyName, s2: "model") == 0 )
      {
        CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this, name: v6, bPreload: true);
        this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
        CBaseEntity::DispatchUpdateTransmitState(this);
      }
      return CBaseEntity::KeyValue(this, szKeyName, szValue: v6);
    }
    else
    {
      v5 = atof(nptr: szValue);
      *(float *)&szValue = v5;
      this->m_maxRange = v5;
      if ( v5 > 1.0 )
      {
        if ( *(float *)&szValue > 255.0 )
          this->m_maxRange = 255.0;
        return true;
      }
      else
      {
        this->m_maxRange = 1.0;
        return true;
      }
    }
  }
  else
  {
    this->m_fishCount = atoi(nptr: szValue);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127DF0
// Name: public: bool CountdownTimer::IsElapsed(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CountdownTimer::IsElapsed(CountdownTimer *this)
{
  return IntervalTimer::Now((CEffectsServer *)this) > this->m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10128040
// Name: public: void CountdownTimer::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CountdownTimer::Reset(CountdownTimer *this)
{
  double v2; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float v4; // [esp+4h] [ebp-4h]

  v2 = IntervalTimer::Now((CEffectsServer *)this) + this->m_duration.m_Value;
  p_m_timestamp = &this->m_timestamp;
  if ( p_m_timestamp->m_Value != v2 )
  {
    (*(void (__thiscall **)(int, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))LODWORD(p_m_timestamp[-2].m_Value))(
      a1: (int)&p_m_timestamp[-2],
      a2: p_m_timestamp);
    v4 = v2;
    p_m_timestamp->m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128080
// Name: public: void CountdownTimer::Start(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CountdownTimer::Start(CountdownTimer *this, float duration)
{
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  v3 = IntervalTimer::Now((CEffectsServer *)this) + duration;
  if ( this->m_timestamp.m_Value != v3 )
  {
    this->NetworkStateChanged(this, a2: &this->m_timestamp);
    v4 = v3;
    this->m_timestamp.m_Value = v4;
  }
  if ( this->m_duration.m_Value != duration )
  {
    this->NetworkStateChanged(this, a2: &this->m_duration);
    this->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101280F0
// Name: public: void CFish::FlockTo(class CFish __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFish::FlockTo(CFish *this, CFish *other, float amount)
{
  unsigned int v5; // eax
  float z; // xmm0_4
  unsigned int v7; // edx
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edi
  double v10; // st7
  float v11; // xmm3_4
  float y; // xmm6_4
  float x; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  Vector to; // [esp+14h] [ebp-10h] BYREF
  float maxRange; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  float range; // [esp+2Ch] [ebp+8h]
  Vector v22; // 0:^10.12

  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_disperseTimer) > this->m_disperseTimer.m_timestamp.m_Value )
  {
    if ( other != nullptr )
    {
      v5 = (unsigned int)this->m_iEFlags >> 11;
      maxRange = 100.0;
      if ( (v5 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (other->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: other, a2: (int)&savedregs);
      v22.x = other->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      v22.y = other->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      z = other->m_vecAbsOrigin.z;
    }
    else
    {
      v7 = (unsigned int)this->m_iEFlags >> 11;
      maxRange = 300.0;
      if ( (v7 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      m_Index = this->m_pool.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
      v22.x = m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      v22.y = m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      z = m_pEntity->m_vecAbsOrigin.z;
    }
    v22.z = z - this->m_vecAbsOrigin.z;
    to = v22;
    v10 = VectorNormalize(vec: &to);
    range = v10;
    if ( v10 <= maxRange )
    {
      if ( other != nullptr && (v11 = v10, range < 25.0) )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
        {
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
          v11 = v10;
        }
        if ( (other->m_iEFlags & 0x1000) != 0 )
        {
          CBaseEntity::CalcAbsoluteVelocity(this: other, a2: (int)&savedregs);
          v11 = v10;
        }
        y = to.y;
        x = to.x;
        v14 = to.z;
        if ( (float)((float)((float)(to.y * (float)(other->m_vecAbsVelocity.y - this->m_vecAbsVelocity.y))
                           + (float)((float)(other->m_vecAbsVelocity.x - this->m_vecAbsVelocity.x) * to.x))
                   + (float)(to.z * (float)(other->m_vecAbsVelocity.z - this->m_vecAbsVelocity.z))) < 0.0 )
        {
          v15 = (float)(1.0 - (float)(v11 * 0.039999999)) * 5.0;
          if ( (float)((float)((float)(this->m_perp.y * to.y) + (float)(this->m_perp.x * to.x))
                     + (float)(this->m_perp.z * to.z)) <= 0.0 )
            this->m_angleChange = v15 + this->m_angleChange;
          else
            this->m_angleChange = this->m_angleChange - v15;
          return;
        }
      }
      else
      {
        v14 = to.z;
        y = to.y;
        x = to.x;
      }
      v16 = (float)((float)((float)((float)-this->m_forward.y * y) + (float)((float)-this->m_forward.x * x))
                  + (float)((float)-this->m_forward.z * v14))
          + 1.0;
      if ( (float)((float)((float)(this->m_forward.x * y) + (float)((float)-this->m_forward.y * x)) + (float)(v14 * 0.0)) <= 1.0 )
        v17 = -1.0;
      else
        v17 = 1.0;
      if ( v16 > 1.0 )
      {
        if ( this->m_turnClockwise )
          v17 = 1.0;
        else
          v17 = -1.0;
      }
      this->m_angleChange = (float)((float)((float)((float)(1.0 - (float)(range / maxRange))
                                                  * (float)(amount * 0.69999999))
                                          * v17)
                                  * v16)
                          + this->m_angleChange;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128490
// Name: public: float CFish::Avoid(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFish::Avoid(CFish *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  unsigned int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  Vector *p_m_vecAbsOrigin; // edi
  IHandleEntity *v9; // ecx
  float v10; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  int m_iEFlags; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float m_avoidRange; // xmm3_4
  int v18; // ecx
  float v19; // xmm3_4
  unsigned int v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm2_4
  int v23; // edx
  float v24; // xmm0_4
  float v25; // xmm1_4
  CGameTrace v26; // [esp+8h] [ebp-74h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-20h] BYREF
  float v28; // [esp+68h] [ebp-14h]
  float v29; // [esp+6Ch] [ebp-10h]
  float v30; // [esp+70h] [ebp-Ch]
  float leftDanger; // [esp+74h] [ebp-8h]
  float rightDanger; // [esp+78h] [ebp-4h]
  IHandleEntity savedregs; // [esp+7Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  m_Index = this->m_pool.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  v4 = this->m_pool.m_Index;
  v5 = m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  v6 = m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  v7 = m_pEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
  p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    v9 = nullptr;
  else
    v9 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( (float)((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7)) <= (float)((float)(*(float *)&v9[217].__vftable
                                                                                                 - 20.0)
                                                                                         * (float)(*(float *)&v9[217].__vftable
                                                                                                 - 20.0)) )
  {
    y = this->m_perp.y;
    z = this->m_perp.z;
    m_iEFlags = this->m_iEFlags;
    rightDanger = 0.0;
    leftDanger = 0.0;
    v15 = this->m_forward.y + (float)(y * 0.2);
    v16 = this->m_forward.z + (float)(z * 0.2);
    m_avoidRange = this->m_avoidRange;
    v28 = (float)((float)(this->m_perp.x * 0.2) + this->m_forward.x) * m_avoidRange;
    v29 = v15 * m_avoidRange;
    v30 = v16 * m_avoidRange;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v18 = this->m_iEFlags;
    vecAbsEnd.x = p_m_vecAbsOrigin->x + v28;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + v29;
    vecAbsEnd.z = this->m_vecAbsOrigin.z + v30;
    if ( (v18 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x201400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &v26);
    if ( v26.fraction < 1.0 )
      rightDanger = 1.0 - v26.fraction;
    v19 = this->m_avoidRange;
    v20 = (unsigned int)this->m_iEFlags >> 11;
    v21 = (float)(this->m_forward.y - (float)(this->m_perp.y * 0.2)) * v19;
    v22 = (float)(this->m_forward.z - (float)(this->m_perp.z * 0.2)) * v19;
    v28 = (float)(this->m_forward.x - (float)(this->m_perp.x * 0.2)) * v19;
    v29 = v21;
    v30 = v22;
    if ( (v20 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v23 = this->m_iEFlags;
    vecAbsEnd.x = p_m_vecAbsOrigin->x + v28;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + v29;
    vecAbsEnd.z = this->m_vecAbsOrigin.z + v30;
    if ( (v23 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x201400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &v26);
    if ( v26.fraction >= 1.0 )
      v24 = leftDanger;
    else
      v24 = 1.0 - v26.fraction;
    if ( this->m_turnClockwise )
    {
      v25 = rightDanger;
      if ( rightDanger <= 0.0 )
      {
        this->m_angleChange = (float)(v24 * 100.0) + this->m_angleChange;
        goto LABEL_40;
      }
    }
    else
    {
      if ( v24 > 0.0 )
      {
        this->m_angleChange = (float)(v24 * 100.0) + this->m_angleChange;
        v25 = rightDanger;
        goto LABEL_40;
      }
      v25 = rightDanger;
    }
    this->m_angleChange = this->m_angleChange - (float)(v25 * 100.0);
LABEL_40:
    if ( v24 <= v25 )
      return v25;
    rightDanger = v24;
    return v24;
  }
  if ( (float)((float)((float)(this->m_forward.y * v6) + (float)(v5 * this->m_forward.x))
             + (float)(this->m_forward.z * v7)) < 0.0 )
  {
    if ( this->m_turnClockwise )
      v10 = -100.0;
    else
      v10 = 100.0;
    this->m_angleChange = this->m_angleChange + v10;
  }
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101288A0
// Name: public: void CFish::Panic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFish::Panic(CFish *this)
{
  IUniformRandomStream *v2; // ecx
  double v3; // st7
  double v4; // st7
  float v5; // [esp+14h] [ebp-8h]
  float v6; // [esp+14h] [ebp-8h]
  float v7; // [esp+18h] [ebp-4h]
  float v8; // [esp+18h] [ebp-4h]

  v7 = _RandomFloat((IUniformRandomStream *)this, a2: 5.0, a3: 15.0);
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_panicTimer) + v7;
  if ( this->m_panicTimer.m_timestamp.m_Value != v3 )
  {
    this->m_panicTimer.NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_timestamp);
    v5 = v3;
    this->m_panicTimer.m_timestamp.m_Value = v5;
  }
  if ( this->m_panicTimer.m_duration.m_Value != v7 )
  {
    this->m_panicTimer.NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_duration);
    this->m_panicTimer.m_duration.m_Value = v7;
  }
  v8 = _RandomFloat(this: v2, a2: 10.0, a3: 20.0);
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_moveTimer) + v8;
  if ( this->m_moveTimer.m_timestamp.m_Value != v4 )
  {
    this->m_moveTimer.NetworkStateChanged(this: &this->m_moveTimer, a2: &this->m_moveTimer.m_timestamp);
    v6 = v4;
    this->m_moveTimer.m_timestamp.m_Value = v6;
  }
  if ( this->m_moveTimer.m_duration.m_Value != v8 )
  {
    this->m_moveTimer.NetworkStateChanged(this: &this->m_moveTimer, a2: &this->m_moveTimer.m_duration);
    this->m_moveTimer.m_duration.m_Value = v8;
  }
  this->m_desiredSpeed = this->m_panicSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x101289E0
// Name: public: virtual void CFishPool::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFishPool::FireGameEvent(CFishPool *this, CBasePlayer *event)
{
  int v4; // eax
  const char *v5; // eax
  int v6; // xmm0_4
  int v7; // edi
  CBaseEntity *v8; // edx
  unsigned int v9; // eax
  CBaseEntity *m_pEntity; // esi
  float v11; // xmm0_4
  unsigned int v12; // eax
  CFish *v13; // ecx
  float range; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  CBasePlayer *player; // [esp+1Ch] [ebp+8h]

  v4 = ((int (__thiscall *)(CBasePlayer *, const char *, _DWORD))event->GetModelIndex)(a1: event, a2: "userid", a3: 0);
  player = UTIL_PlayerByUserId(userID: v4);
  v5 = (const char *)((int (__thiscall *)(CBasePlayer *))event->SetRefEHandle)(a1: event);
  if ( _V_strcmp(s1: "player_footstep", s2: v5) != 0 )
    v6 = 1140457472;
  else
    v6 = 1117126656;
  v7 = 0;
  for ( range = *(float *)&v6; v7 < SLODWORD(this->m_Network.m_PVSInfo.m_vCenter[1]); ++v7 )
  {
    v8 = player;
    if ( player != nullptr )
    {
      v9 = *(_DWORD *)&this->m_Network.m_PVSInfo.m_pClusters[2 * v7];
      if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
        v8 = player;
      }
      if ( (v8->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&savedregs);
        v8 = player;
      }
      v11 = v8->m_vecAbsOrigin.x - m_pEntity->m_vecAbsOrigin.x;
      if ( (float)((float)((float)(v11 * v11)
                         + (float)((float)(v8->m_vecAbsOrigin.y - m_pEntity->m_vecAbsOrigin.y)
                                 * (float)(v8->m_vecAbsOrigin.y - m_pEntity->m_vecAbsOrigin.y)))
                 + (float)((float)(v8->m_vecAbsOrigin.z - m_pEntity->m_vecAbsOrigin.z)
                         * (float)(v8->m_vecAbsOrigin.z - m_pEntity->m_vecAbsOrigin.z))) > (float)(range * range) )
        continue;
    }
    v12 = *(_DWORD *)&this->m_Network.m_PVSInfo.m_pClusters[2 * v7];
    if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
      v13 = nullptr;
    else
      v13 = (CFish *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    CFish::Panic(this: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128B60
// Name: public: CFish::CFish(void)
// Source: json
//------------------------------------------------------------------------------
CFish *__thiscall CFish::CFish(CFish *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx
  CountdownTimer_vtbl *v9; // edx
  CountdownTimer_vtbl *v10; // edx
  CountdownTimer_vtbl *v11; // edx

  CBaseAnimating::CBaseAnimating(this);
  this->__vftable = (CFish_vtbl *)&CFish::`vftable';
  this->m_pool.m_Index = -1;
  this->m_turnTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_turnTimer.__vftable;
  this->m_turnTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_turnTimer.m_duration);
  v3 = this->m_turnTimer.__vftable;
  this->m_turnTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_turnTimer, a2: &this->m_turnTimer.m_timestamp);
  this->m_goTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_goTimer.__vftable;
  this->m_goTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_goTimer.m_duration);
  v5 = this->m_goTimer.__vftable;
  this->m_goTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_goTimer, a2: &this->m_goTimer.m_timestamp);
  this->m_moveTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_moveTimer.__vftable;
  this->m_moveTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_moveTimer.m_duration);
  v7 = this->m_moveTimer.__vftable;
  this->m_moveTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_moveTimer, a2: &this->m_moveTimer.m_timestamp);
  this->m_panicTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v8 = this->m_panicTimer.__vftable;
  this->m_panicTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v8->NetworkStateChanged)(a1: &this->m_panicTimer.m_duration);
  v9 = this->m_panicTimer.__vftable;
  this->m_panicTimer.m_timestamp.m_Value = -1.0;
  v9->NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_timestamp);
  this->m_disperseTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v10 = this->m_disperseTimer.__vftable;
  this->m_disperseTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v10->NetworkStateChanged)(a1: &this->m_disperseTimer.m_duration);
  v11 = this->m_disperseTimer.__vftable;
  this->m_disperseTimer.m_timestamp.m_Value = -1.0;
  v11->NetworkStateChanged(this: &this->m_disperseTimer, a2: &this->m_disperseTimer.m_timestamp);
  this->m_visible.m_Memory.m_pMemory = nullptr;
  this->m_visible.m_Memory.m_nAllocationCount = 0;
  this->m_visible.m_Memory.m_nGrowSize = 0;
  this->m_visible.m_Size = 0;
  this->m_visible.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10128CD0
// Name: public: void CFish::Initialize(class CFishPool __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFish::Initialize(CFish *this, CFishPool *pool, float id)
{
  CFishPool *v3; // edi
  edict_t *m_pPev; // ecx
  float v6; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  const char *v14; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v3 = pool;
  if ( pool != nullptr )
    this->m_pool.m_Index = pool->GetRefEHandle(this: pool)->m_Index;
  else
    this->m_pool.m_Index = -1;
  *(float *)&this->m_id = id;
  if ( (v3->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
  if ( v3->m_vecAbsOrigin.x != this->m_poolOrigin.m_Value.x
    || v3->m_vecAbsOrigin.y != this->m_poolOrigin.m_Value.y
    || v3->m_vecAbsOrigin.z != this->m_poolOrigin.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4C0u);
    }
    this->m_poolOrigin.m_Value.x = v3->m_vecAbsOrigin.x;
    this->m_poolOrigin.m_Value.y = v3->m_vecAbsOrigin.y;
    this->m_poolOrigin.m_Value.z = v3->m_vecAbsOrigin.z;
  }
  m_Value = this->m_waterLevel.m_Value;
  id = v3->m_waterLevel;
  v6 = id;
  if ( m_Value != id )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x4CCu);
        v6 = id;
      }
    }
    this->m_waterLevel.m_Value = v6;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v9 = this->m_vecAbsOrigin.x - this->m_poolOrigin.m_Value.x;
  v10 = this->m_vecAbsOrigin.y - this->m_poolOrigin.m_Value.y;
  if ( this->m_x.m_Value != v9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x494u);
    }
    this->m_x.m_Value = v9;
  }
  if ( this->m_y.m_Value != v10 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x498u);
    }
    this->m_y.m_Value = v10;
  }
  if ( this->m_z.m_Value != this->m_poolOrigin.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x49Cu);
    }
    this->m_z.m_Value = this->m_poolOrigin.m_Value.z;
  }
  v14 = *(const char **)((int (__thiscall *)(CFishPool *, CFishPool **))v3->GetModelName)(a1: v3, a2: &pool);
  if ( v14 == nullptr )
    v14 = locale;
  this->SetModel(this, a2: v14);
}

//------------------------------------------------------------------------------
// Address: 0x10128F30
// Name: public: virtual void CFish::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CFish::Spawn(CFish *this)
{
  IUniformRandomStream *v2; // ecx
  edict_t *m_pPev; // ecx
  double v4; // st7
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  float v11; // [esp+14h] [ebp-4h]
  float m_calmSpeed; // [esp+14h] [ebp-4h]
  float v13; // [esp+14h] [ebp-4h]
  float v14; // [esp+14h] [ebp-4h]
  float v15; // [esp+14h] [ebp-4h]

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x1C);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLY, moveCollide: MOVECOLLIDE_DEFAULT);
  v4 = _RandomFloat(this: v2, a2: 0.0, a3: 360.0);
  if ( this->m_angle.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A0u);
    }
    v11 = v4;
    this->m_angle.m_Value = v11;
  }
  this->m_angleChange = 0.0;
  this->m_forward.x = 1.0;
  this->m_forward.y = 0.0;
  this->m_forward.z = 0.0;
  this->m_perp.y = this->m_forward.x;
  this->m_perp.z = 0.0;
  this->m_speed = 0.0;
  LODWORD(this->m_perp.x) = _mask__NegFloat_;
  this->m_calmSpeed = _RandomFloat(this: (IUniformRandomStream *)m_pPev, a2: 10.0, a3: 20.0);
  m_calmSpeed = this->m_calmSpeed;
  this->m_panicSpeed = _RandomFloat(this: v5, a2: 4.0, a3: 5.0) * m_calmSpeed;
  this->m_desiredSpeed = m_calmSpeed;
  this->m_turnClockwise = _RandomInt(this: v6, a2: 0, a3: 100) < 50;
  this->m_avoidRange = _RandomFloat(this: v7, a2: 40.0, a3: 75.0);
  if ( this->m_iHealth.m_Value != 1 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 1;
  }
  if ( this->m_iMaxHealth.m_Value != 1 )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = 1;
  }
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  v13 = _RandomFloat(this: v8, a2: 0.0, a3: 10.0);
  if ( this->m_disperseTimer.m_timestamp.m_Value != IntervalTimer::Now(this: (CEffectsServer *)&this->m_disperseTimer)
                                                  + v13 )
  {
    ((void (__thiscall *)(CountdownTimer *))this->m_disperseTimer.NetworkStateChanged)(a1: &this->m_disperseTimer);
    LODWORD(this->m_disperseTimer.m_timestamp.m_Value) = &this->m_disperseTimer.m_timestamp;
  }
  if ( this->m_disperseTimer.m_duration.m_Value != v13 )
  {
    this->m_disperseTimer.NetworkStateChanged(this: &this->m_disperseTimer, a2: &this->m_disperseTimer.m_duration);
    this->m_disperseTimer.m_duration.m_Value = v13;
  }
  v14 = _RandomFloat(this: v9, a2: 10.0, a3: 60.0);
  if ( this->m_goTimer.m_timestamp.m_Value != IntervalTimer::Now(this: (CEffectsServer *)&this->m_goTimer) + v14 )
  {
    ((void (__thiscall *)(CountdownTimer *))this->m_goTimer.NetworkStateChanged)(a1: &this->m_goTimer);
    LODWORD(this->m_goTimer.m_timestamp.m_Value) = &this->m_goTimer.m_timestamp;
  }
  if ( this->m_goTimer.m_duration.m_Value != v14 )
  {
    this->m_goTimer.NetworkStateChanged(this: &this->m_goTimer, a2: &this->m_goTimer.m_duration);
    this->m_goTimer.m_duration.m_Value = v14;
  }
  v15 = _RandomFloat(this: v10, a2: 2.0, a3: 10.0);
  if ( this->m_moveTimer.m_timestamp.m_Value != IntervalTimer::Now(this: (CEffectsServer *)&this->m_moveTimer) + v15 )
  {
    ((void (__thiscall *)(CountdownTimer *))this->m_moveTimer.NetworkStateChanged)(a1: &this->m_moveTimer);
    LODWORD(this->m_moveTimer.m_timestamp.m_Value) = &this->m_moveTimer.m_timestamp;
  }
  if ( this->m_moveTimer.m_duration.m_Value != v15 )
  {
    this->m_moveTimer.NetworkStateChanged(this: &this->m_moveTimer, a2: &this->m_moveTimer.m_duration);
    this->m_moveTimer.m_duration.m_Value = v15;
  }
  this->m_desiredSpeed = this->m_calmSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10129310
// Name: public: virtual void CFish::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFish::Event_Killed(CFish *this, const CTakeDamageInfo *info)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129370
// Name: public: virtual void CFish::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFish::Touch(CFish *this, CBaseEntity *other)
{
  if ( other != nullptr && other->IsPlayer(this: other) )
    CFish::Panic(this);
}

//------------------------------------------------------------------------------
// Address: 0x101293A0
// Name: public: void CFish::Update(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CFish::Update(CFish *this, float deltaT)
{
  float x; // xmm0_4
  float v4; // xmm2_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v7; // xmm4_4
  float m_Value; // xmm6_4
  edict_t *m_pPev; // ecx
  float v10; // xmm4_4
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float v15; // edx
  IUniformRandomStream *v16; // ecx
  double m_panicSpeed; // st7
  IUniformRandomStream *v18; // ecx
  IUniformRandomStream *v19; // ecx
  int v20; // edi
  float v21; // xmm0_4
  float v22; // xmm0_4
  float m_angleChange; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  edict_t *v26; // ecx
  __m128i v27; // xmm0
  double v28; // xmm0_8
  double v29; // xmm0_8
  float m_desiredSpeed; // xmm1_4
  float v31; // xmm0_4
  float m_speed; // xmm1_4
  unsigned int v33; // ecx
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  IHandleEntity *v37; // eax
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float duration; // [esp+Ch] [ebp-28h]
  Vector vel; // [esp+10h] [ebp-24h] BYREF
  Vector toCenter; // [esp+1Ch] [ebp-18h] BYREF
  float i; // [esp+28h] [ebp-Ch]
  unsigned __int64 v45; // [esp+2Ch] [ebp-8h] OVERLAPPED
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  x = this->m_vecAbsOrigin.x - this->m_poolOrigin.m_Value.x;
  v4 = -255.0;
  y = this->m_vecAbsOrigin.y - this->m_poolOrigin.m_Value.y;
  z = this->m_vecAbsOrigin.z - this->m_poolOrigin.m_Value.z;
  toCenter.x = x;
  toCenter.y = y;
  toCenter.z = z;
  if ( x >= -255.0 )
  {
    if ( x <= 255.0 )
      v7 = x;
    else
      v7 = 255.0;
  }
  else
  {
    v7 = -255.0;
  }
  m_Value = this->m_x.m_Value;
  *((float *)&v45 + 1) = v7;
  if ( m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
        v7 = *((float *)&v45 + 1);
        z = toCenter.z;
        y = toCenter.y;
        x = toCenter.x;
        v4 = -255.0;
      }
    }
    this->m_x.m_Value = v7;
  }
  if ( y >= -255.0 )
  {
    if ( y <= 255.0 )
      v4 = y;
    else
      v4 = 255.0;
  }
  v10 = this->m_y.m_Value;
  *((float *)&v45 + 1) = v4;
  if ( v10 != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x498u);
        v4 = *((float *)&v45 + 1);
        z = toCenter.z;
        y = toCenter.y;
        x = toCenter.x;
      }
    }
    this->m_y.m_Value = v4;
  }
  if ( this->m_z.m_Value != this->m_poolOrigin.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x49Cu);
        z = toCenter.z;
        y = toCenter.y;
        x = toCenter.x;
      }
    }
    this->m_z.m_Value = this->m_poolOrigin.m_Value.z;
  }
  if ( this->m_lifeState.m_Value == 2 )
  {
    m_Index = this->m_pool.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (float)((float)((float)(y * y) + (float)(x * x)) + (float)(z * z)) <= (float)((float)(*(float *)&m_pEntity[217].__vftable
                                                                                             - 5.0)
                                                                                     * (float)(*(float *)&m_pEntity[217].__vftable
                                                                                             - 5.0)) )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      v15 = this->m_vecAbsVelocity.z;
      *(_QWORD *)&toCenter.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
      toCenter.x = toCenter.x - (float)(toCenter.x * deltaT);
      toCenter.y = toCenter.y - (float)(toCenter.y * deltaT);
      toCenter.z = v15 - (float)(v15 * deltaT);
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &toCenter);
    }
    else
    {
      memset((void *)&toCenter, 0, sizeof(toCenter));
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &toCenter);
    }
    return;
  }
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_turnTimer) > this->m_turnTimer.m_timestamp.m_Value )
  {
    duration = _RandomFloat(this: v16, a2: 10.0, a3: 30.0);
    CountdownTimer::Start(this: &this->m_turnTimer, duration);
    this->m_turnClockwise = !this->m_turnClockwise;
  }
  if ( this->m_panicTimer.m_timestamp.m_Value - IntervalTimer::Now(this: (CEffectsServer *)&this->m_panicTimer) > 0.0 )
  {
    m_panicSpeed = this->m_panicSpeed;
LABEL_48:
    this->m_desiredSpeed = m_panicSpeed;
    goto LABEL_49;
  }
  if ( this->m_moveTimer.m_timestamp.m_Value - IntervalTimer::Now(this: (CEffectsServer *)&this->m_moveTimer) > 0.0 )
  {
LABEL_47:
    m_panicSpeed = this->m_calmSpeed;
    goto LABEL_48;
  }
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_goTimer) > this->m_goTimer.m_timestamp.m_Value )
  {
    vel.y = _RandomFloat(this: v18, a2: 10.0, a3: 60.0);
    CountdownTimer::Start(this: &this->m_goTimer, duration: vel.y);
    toCenter.x = _RandomFloat(this: v19, a2: 2.0, a3: 10.0);
    CountdownTimer::Start(this: &this->m_moveTimer, duration: toCenter.x);
    goto LABEL_47;
  }
LABEL_49:
  *((float *)&v45 + 1) = CFish::Avoid(this);
  v20 = 0;
  if ( this->m_visible.m_Size > 0 )
  {
    v21 = 1.0 - *((float *)&v45 + 1);
    for ( i = 1.0 - *((float *)&v45 + 1); ; v21 = i )
    {
      CFish::FlockTo(this, other: this->m_visible.m_Memory.m_pMemory[v20++], amount: v21);
      if ( v20 >= this->m_visible.m_Size )
        break;
    }
  }
  CFish::FlockTo(this, other: nullptr, amount: 1.0 - *((float *)&v45 + 1));
  v22 = (float)((float)((float)(this->m_speed / this->m_panicSpeed) * 175.0) + 25.0) * deltaT;
  m_angleChange = this->m_angleChange;
  if ( m_angleChange > v22 || (LODWORD(v22) ^= _mask__NegFloat_, v22 > m_angleChange) )
    this->m_angleChange = v22;
  v24 = this->m_angle.m_Value;
  i = this->m_angleChange + v24;
  v25 = i;
  if ( v24 != i )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v26 = this->m_Network.m_pPev;
      if ( v26 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v26->CBaseEdict, offset: 0x4A0u);
        v25 = i;
      }
    }
    this->m_angle.m_Value = v25;
  }
  this->m_angleChange = 0.0;
  v27 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_angle.m_Value));
  *(double *)v27.m128i_i64 = *(double *)v27.m128i_i64 * 3.141592653589793 * 0.005555555555555556;
  v45 = v27.m128i_i64[0];
  __libm_sse2_cos(X: v27);
  *(float *)&v28 = v28;
  i = *(float *)&v28;
  this->m_forward.x = *(float *)&v28;
  __libm_sse2_sin(X: (__m128i)v45);
  this->m_forward.z = 0.0;
  *(float *)&v29 = v29;
  this->m_forward.y = *(float *)&v29;
  this->m_perp.z = 0.0;
  m_desiredSpeed = this->m_desiredSpeed;
  this->m_perp.x = -*(float *)&v29;
  this->m_perp.y = i;
  this->m_speed = (float)((float)((float)(m_desiredSpeed - this->m_speed) * 2.0) * deltaT) + this->m_speed;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_moveTimer) > this->m_moveTimer.m_timestamp.m_Value )
  {
    v31 = this->m_desiredSpeed - deltaT;
    this->m_desiredSpeed = v31;
    if ( v31 < 0.0 )
      this->m_desiredSpeed = 0.0;
  }
  m_speed = this->m_speed;
  v33 = this->m_pool.m_Index;
  v34 = this->m_forward.x * m_speed;
  v35 = this->m_forward.y * m_speed;
  v36 = this->m_forward.z * m_speed;
  vel.x = v34;
  vel.y = v35;
  vel.z = v36;
  if ( v33 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_SerialNumber != HIWORD(v33) )
    v37 = nullptr;
  else
    v37 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_pEntity;
  v38 = toCenter.z;
  if ( (float)((float)((float)(toCenter.y * toCenter.y) + (float)(toCenter.x * toCenter.x)) + (float)(v38 * v38)) > (float)((float)(*(float *)&v37[217].__vftable - 5.0) * (float)(*(float *)&v37[217].__vftable - 5.0)) )
  {
    toCenter.z = -toCenter.z;
    v39 = (float)((float)(v35 * (float)-toCenter.y) + (float)(v34 * (float)-toCenter.x)) + (float)((float)-v38 * vel.z);
    toCenter.x = -toCenter.x;
    toCenter.y = -toCenter.y;
    if ( v39 < 0.0 )
    {
      VectorNormalize(vec: &toCenter);
      v40 = (float)((float)(COERCE_FLOAT(LODWORD(toCenter.y) ^ _mask__NegFloat_) * vel.x) + (float)(vel.y * toCenter.x))
          + (float)(vel.z * 0.0);
      vel.x = COERCE_FLOAT(LODWORD(toCenter.y) ^ _mask__NegFloat_) * v40;
      vel.y = v40 * toCenter.x;
      vel.z = v40 * 0.0;
    }
  }
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vel);
  this->m_flSpeed = this->m_speed;
}

//------------------------------------------------------------------------------
// Address: 0x10129AF0
// Name: public: CFishPool::CFishPool(void)
// Source: json
//------------------------------------------------------------------------------
CFishPool *__thiscall CFishPool::CFishPool(CFishPool *this)
{
  CountdownTimer_vtbl *v2; // edx
  void (__thiscall *NetworkStateChanged)(CountdownTimer *, void *); // eax
  double v4; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // [esp+Ch] [ebp-8h]
  float v7; // [esp+10h] [ebp-4h]

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CFishPool_vtbl *)&CFishPool::`vftable'{for `CBaseEntity'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CFishPool::`vftable'{for `CGameEventListener'};
  this->m_fishes.m_Memory.m_pMemory = nullptr;
  this->m_fishes.m_Memory.m_nAllocationCount = 0;
  this->m_fishes.m_Memory.m_nGrowSize = 0;
  this->m_fishes.m_Size = 0;
  this->m_fishes.m_pElements = nullptr;
  this->m_visTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_visTimer.__vftable;
  p_m_duration = &this->m_visTimer.m_duration;
  this->m_visTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_visTimer.m_duration);
  NetworkStateChanged = this->m_visTimer.NetworkStateChanged;
  this->m_visTimer.m_timestamp.m_Value = -1.0;
  NetworkStateChanged(this: &this->m_visTimer, a2: &this->m_visTimer.m_timestamp);
  this->m_maxRange = 255.0;
  this->m_fishCount = 0;
  this->m_swimDepth = 0.0;
  this->m_isDormant = false;
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_visTimer) + 0.5;
  if ( this->m_visTimer.m_timestamp.m_Value != v4 )
  {
    this->m_visTimer.NetworkStateChanged(this: &this->m_visTimer, a2: &this->m_visTimer.m_timestamp);
    v7 = v4;
    this->m_visTimer.m_timestamp.m_Value = v7;
  }
  if ( p_m_duration->m_Value != 0.5 )
  {
    this->m_visTimer.NetworkStateChanged(this: &this->m_visTimer, a2: &this->m_visTimer.m_duration);
    p_m_duration->m_Value = 0.5;
  }
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_shoot", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_footstep", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "weapon_fire", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "hegrenade_detonate",
    a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "flashbang_detonate",
    a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "smokegrenade_detonate",
    a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "molotov_detonate", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "decoy_detonate", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "bomb_exploded", a4: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10129DC0
// Name: public: void CFishPool::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFishPool::Update(CFishPool *this)
{
  float thinkTime; // xmm0_4
  CFishPool *v2; // ebx
  int i; // esi
  CHandle<CFish> *m_pMemory; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  float *p_m_Value; // edi
  double v8; // st7
  int v9; // edx
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  int v12; // esi
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  int v15; // eax
  unsigned int v16; // eax
  IHandleEntity *v17; // ecx
  CHandle<CFish> *v18; // edx
  unsigned int v19; // eax
  CBaseEntityList *v20; // esi
  IHandleEntity *v21; // ebx
  unsigned int v22; // eax
  CBaseEntity *v23; // edi
  unsigned int v24; // eax
  CBaseEntity *v25; // esi
  CHandle<CFish> *v26; // edx
  unsigned int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // eax
  IHandleEntity *v30; // ecx
  IHandleEntity_vtbl *v31; // edi
  IHandleEntity_vtbl *v32; // eax
  IHandleEntity *v33; // esi
  IHandleEntity_vtbl *v34; // ecx
  int v35; // eax
  IHandleEntity **v36; // eax
  CHandle<CFish> *v37; // edx
  unsigned int v38; // eax
  IHandleEntity *v39; // ebx
  unsigned int v40; // eax
  IHandleEntity *v41; // ecx
  IHandleEntity_vtbl *v42; // edi
  IHandleEntity_vtbl *v43; // eax
  IHandleEntity *v44; // esi
  IHandleEntity_vtbl *v45; // ecx
  int v46; // eax
  IHandleEntity **v47; // eax
  int k; // esi
  unsigned int v49; // eax
  CFish *v50; // ecx
  CGameTrace result; // [esp+14h] [ebp-78h] BYREF
  Vector vecAbsVelocity; // [esp+68h] [ebp-24h] BYREF
  int v53; // [esp+74h] [ebp-18h]
  int v54; // [esp+78h] [ebp-14h]
  IHandleEntity *v55; // [esp+7Ch] [ebp-10h]
  int j; // [esp+80h] [ebp-Ch]
  unsigned int v57; // [esp+84h] [ebp-8h]
  CFishPool *v58; // [esp+88h] [ebp-4h]
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  thinkTime = gpGlobals->curtime + 0.1;
  v2 = this;
  v58 = this;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  if ( fish_dormant.m_pParent != nullptr && fish_dormant.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !v2->m_isDormant )
    {
      for ( i = 0; i < v2->m_fishes.m_Size; ++i )
      {
        m_pMemory = v2->m_fishes.m_Memory.m_pMemory;
        memset((void *)&vecAbsVelocity, 0, sizeof(vecAbsVelocity));
        m_Index = m_pMemory[i].m_Index;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        CBaseEntity::SetAbsVelocity(this: m_pEntity, &vecAbsVelocity);
      }
      v2->m_isDormant = true;
    }
  }
  else
  {
    v2->m_isDormant = false;
    p_m_Value = &v2->m_visTimer.m_timestamp.m_Value;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&v2->m_visTimer) > v2->m_visTimer.m_timestamp.m_Value )
    {
      v8 = IntervalTimer::Now(this: (CEffectsServer *)&v2->m_visTimer) + v2->m_visTimer.m_duration.m_Value;
      *(float *)&v54 = v8;
      if ( *p_m_Value != v8 )
      {
        v2->m_visTimer.NetworkStateChanged(this: &v2->m_visTimer, a2: &v2->m_visTimer.m_timestamp);
        *p_m_Value = *(float *)&v54;
      }
      v9 = 0;
      if ( v2->m_fishes.m_Size > 0 )
      {
        do
        {
          v10 = v2->m_fishes.m_Memory.m_pMemory[v9].m_Index;
          if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
            v11 = nullptr;
          else
            v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          ++v9;
          v11[332].__vftable = nullptr;
        }
        while ( v9 < v2->m_fishes.m_Size );
        if ( v2->m_fishes.m_Size > 0 )
        {
          v57 = 0;
          v12 = 1;
          v54 = 1;
          do
          {
            v13 = v2->m_fishes.m_Memory.m_pMemory[v57 / 4].m_Index;
            if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
              v14 = nullptr;
            else
              v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
            if ( v14->__vftable[22].GetRefEHandle(this: v14) != nullptr )
            {
              v15 = v12;
              j = v12;
              if ( v12 < v2->m_fishes.m_Size )
              {
                do
                {
                  v16 = v2->m_fishes.m_Memory.m_pMemory[v15].m_Index;
                  if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
                    v17 = nullptr;
                  else
                    v17 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
                  if ( v17->__vftable[22].GetRefEHandle(this: v17) != nullptr )
                  {
                    v18 = v2->m_fishes.m_Memory.m_pMemory;
                    v19 = v18[v57 / 4].m_Index;
                    v20 = g_pEntityList;
                    if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
                      v21 = nullptr;
                    else
                      v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
                    v22 = v18[j].m_Index;
                    if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
                      v23 = nullptr;
                    else
                      v23 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
                    if ( (v23->m_iEFlags & 0x800) != 0 )
                    {
                      CBaseEntity::CalcAbsolutePosition(this: v23, a2: (int)&savedregs);
                      v20 = g_pEntityList;
                    }
                    v24 = v58->m_fishes.m_Memory.m_pMemory[v57 / 4].m_Index;
                    if ( v24 == -1 || v20->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
                      v25 = nullptr;
                    else
                      v25 = (CBaseEntity *)v20->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
                    if ( (v25->m_iEFlags & 0x800) != 0 )
                      CBaseEntity::CalcAbsolutePosition(this: v25, a2: (int)&savedregs);
                    UTIL_TraceLine(
                      a1: &savedregs,
                      a2: (int)&v25->m_vecAbsOrigin,
                      vecAbsStart: &v25->m_vecAbsOrigin,
                      vecAbsEnd: &v23->m_vecAbsOrigin,
                      mask: 0x201400Bu,
                      ignore: v21,
                      collisionGroup: 0,
                      ptr: &result);
                    if ( result.fraction >= 1.0 )
                    {
                      v26 = v58->m_fishes.m_Memory.m_pMemory;
                      v53 = 4 * j;
                      v27 = v26[j].m_Index;
                      if ( v27 == -1
                        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
                      {
                        v55 = nullptr;
                      }
                      else
                      {
                        v55 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
                      }
                      v28 = v57;
                      v29 = v26[v57 / 4].m_Index;
                      if ( v29 == -1
                        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber != HIWORD(v29) )
                      {
                        v30 = nullptr;
                      }
                      else
                      {
                        v30 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
                      }
                      v31 = v30[332].__vftable;
                      v32 = v30[330].__vftable;
                      v33 = v30 + 329;
                      if ( (int)((char *)&v31->dtr_IHandleEntity + 1) > (int)v32 )
                        CUtlMemory<CNavLadder *,int>::Grow(
                          this: (CUtlMemory<vgui::TreeNode *,int> *)&v30[329],
                          num: (char *)v31 - (char *)v32 + 1);
                      ++v33[3].__vftable;
                      v34 = v33->__vftable;
                      v35 = (char *)v33[3].__vftable - (char *)v31 - 1;
                      v33[4].__vftable = v33->__vftable;
                      if ( v35 > 0 )
                        _V_memmove(
                          dest: &v34->SetRefEHandle + (_DWORD)v31,
                          src: &v34->dtr_IHandleEntity + (_DWORD)v31,
                          count: 4 * v35);
                      v36 = (IHandleEntity **)(&v33->dtr_IHandleEntity + (_DWORD)v31);
                      if ( v36 != nullptr )
                        *v36 = v55;
                      v37 = v58->m_fishes.m_Memory.m_pMemory;
                      v38 = *(unsigned int *)((char *)&v37->m_Index + v28);
                      if ( v38 == -1
                        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_SerialNumber != HIWORD(v38) )
                      {
                        v39 = nullptr;
                      }
                      else
                      {
                        v39 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_pEntity;
                      }
                      v40 = v37[v53 / 4u].m_Index;
                      if ( v40 == -1
                        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_SerialNumber != HIWORD(v40) )
                      {
                        v41 = nullptr;
                      }
                      else
                      {
                        v41 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_pEntity;
                      }
                      v42 = v41[332].__vftable;
                      v43 = v41[330].__vftable;
                      v44 = v41 + 329;
                      if ( (int)((char *)&v42->dtr_IHandleEntity + 1) > (int)v43 )
                        CUtlMemory<CNavLadder *,int>::Grow(
                          this: (CUtlMemory<vgui::TreeNode *,int> *)&v41[329],
                          num: (char *)v42 - (char *)v43 + 1);
                      ++v44[3].__vftable;
                      v45 = v44->__vftable;
                      v46 = (char *)v44[3].__vftable - (char *)v42 - 1;
                      v44[4].__vftable = v44->__vftable;
                      if ( v46 > 0 )
                        _V_memmove(
                          dest: &v45->SetRefEHandle + (_DWORD)v42,
                          src: &v45->dtr_IHandleEntity + (_DWORD)v42,
                          count: 4 * v46);
                      v47 = (IHandleEntity **)(&v44->dtr_IHandleEntity + (_DWORD)v42);
                      if ( v47 != nullptr )
                        *v47 = v39;
                    }
                  }
                  v2 = v58;
                  v15 = j + 1;
                  j = v15;
                }
                while ( v15 < v58->m_fishes.m_Size );
                v12 = v54;
              }
            }
            v57 += 4;
            v54 = ++v12;
          }
          while ( v12 - 1 < v2->m_fishes.m_Size );
        }
      }
    }
    for ( k = 0; k < v2->m_fishes.m_Size; ++k )
    {
      v49 = v2->m_fishes.m_Memory.m_pMemory[k].m_Index;
      if ( v49 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v49].m_SerialNumber != HIWORD(v49) )
        v50 = nullptr;
      else
        v50 = (CFish *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v49].m_pEntity;
      CFish::Update(this: v50, deltaT: 0.1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A620
// Name: public: virtual void CFishPool::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFishPool::Spawn(CFishPool *this)
{
  IUniformRandomStream *v2; // ecx
  int v3; // edi
  unsigned int v4; // ecx
  CFish *v5; // esi
  unsigned int *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CFish> *m_pMemory; // ecx
  int v10; // eax
  CHandle<CFish> *v11; // edi
  QAngle heading; // [esp+14h] [ebp-14h] BYREF
  CHandle<CFish> hFish; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFishPool::Update,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  this->m_waterLevel = UTIL_WaterLevel(
                         position: &this->m_vecAbsOrigin,
                         minz: this->m_vecAbsOrigin.z,
                         maxz: this->m_vecAbsOrigin.z + 1000.0);
  v3 = 0;
  for ( i = 0; v3 < this->m_fishCount; i = v3 )
  {
    heading.y = _RandomFloat(this: v2, a2: 0.0, a3: 360.0);
    v4 = (unsigned int)this->m_iEFlags >> 11;
    heading.x = 0.0;
    heading.z = 0.0;
    if ( (v4 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = (CFish *)CBaseEntity::Create(
                    szName: "fish",
                    vecOrigin: &this->m_vecAbsOrigin,
                    vecAngles: &heading,
                    pOwner: this);
    CFish::Initialize(this: v5, pool: this, id: *(float *)&v3);
    if ( v5 != nullptr )
    {
      v6 = (unsigned int *)v5->GetRefEHandle(this: v5);
      m_Size = this->m_fishes.m_Size;
      hFish.m_Index = *v6;
      m_nAllocationCount = this->m_fishes.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_fishes,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_fishes.m_Size;
      m_pMemory = this->m_fishes.m_Memory.m_pMemory;
      v10 = this->m_fishes.m_Size - m_Size - 1;
      this->m_fishes.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v2 = (IUniformRandomStream *)this->m_fishes.m_Memory.m_pMemory;
      v11 = (CHandle<CFish> *)&v2[m_Size];
      if ( v11 != nullptr )
        v11->m_Index = hFish.m_Index;
    }
    v3 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104034D0
// Name: _dynamic_initializer_for__fish_dormant__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fish_dormant__()
{
  ConVar::ConVar(
    this: &fish_dormant,
    pName: "fish_dormant",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "Turns off interactive fish behavior. Fish become immobile and unresponsive.");
  return atexit(func: dynamic_atexit_destructor_for__fish_dormant__);
}

//------------------------------------------------------------------------------
// Address: 0x10403500
// Name: _dynamic_initializer_for__fish__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fish__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFish> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &fish,
           a3: "fish");
}

//------------------------------------------------------------------------------
// Address: 0x10403520
// Name: CFish_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFish_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFish>();
  CFish_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403550
// Name: DT_CFish::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CFish::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CFish::g_SendTable);
  return atexit(func: DT_CFish::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403570
// Name: DT_CFish::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CFish::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CFish::ignored>();
  DT_CFish::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104035A0
// Name: CFishPool_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFishPool_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFishPool>();
  CFishPool_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B380
// Name: _dynamic_atexit_destructor_for__fish_dormant__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fish_dormant__()
{
  ConVar::~ConVar(this: &fish_dormant);
}

//------------------------------------------------------------------------------
// Address: 0x1041B390
// Name: DT_CFish::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CFish::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CFish::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403530
// Name: _dynamic_initializer_for__g_CFish_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFish_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CFish_ClassReg, pNetworkName: "CFish", pTable: &DT_CFish::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3A0
// Name: _ServerClassInit_DT_CFish::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CFish::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_59;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3C0
// Name: _DataMapInit_CFish__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFish__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_201);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3D0
// Name: _DataMapInit_CFishPool__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFishPool__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_202);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3E0
// Name: _DataMapInit_CFlexExpresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFlexExpresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_203);
}
