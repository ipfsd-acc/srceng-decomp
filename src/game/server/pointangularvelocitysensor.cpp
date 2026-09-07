// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pointangularvelocitysensor.cpp
// Functions: 19
// ============================================================

#include "game\server\pointangularvelocitysensor.h"

//------------------------------------------------------------------------------
// Address: 0x101D9380
// Name: private: virtual struct datamap_t __near * CPointAngularVelocitySensor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointAngularVelocitySensor::GetDataDescMap(CPointAngularVelocitySensor *this)
{
  return &CPointAngularVelocitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D9390
// Name: private: void CPointAngularVelocitySensor::FireCompareOutput(int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::FireCompareOutput(
        CPointAngularVelocitySensor *this,
        int nCompareResult,
        CBaseEntity *pActivator)
{
  COutputEvent *p_m_OnLessThanOrEqualTo; // ecx
  COutputEvent *p_m_OnGreaterThan; // ecx
  CBaseEntity *v6; // [esp-8h] [ebp-14h]
  CPointAngularVelocitySensor *v7; // [esp-4h] [ebp-10h]

  v7 = this;
  v6 = pActivator;
  if ( nCompareResult == -1 )
  {
    COutputEvent::FireOutput(this: &this->m_OnLessThan, pActivator, pCaller: this, fDelay: 0.0);
    p_m_OnLessThanOrEqualTo = &this->m_OnLessThanOrEqualTo;
  }
  else
  {
    if ( nCompareResult == 1 )
    {
      p_m_OnGreaterThan = &this->m_OnGreaterThan;
    }
    else
    {
      COutputEvent::FireOutput(this: &this->m_OnEqualTo, pActivator, pCaller: this, fDelay: 0.0);
      v7 = this;
      v6 = pActivator;
      p_m_OnGreaterThan = &this->m_OnLessThanOrEqualTo;
    }
    COutputEvent::FireOutput(this: p_m_OnGreaterThan, pActivator: v6, pCaller: v7, fDelay: 0.0);
    p_m_OnLessThanOrEqualTo = &this->m_OnGreaterThanOrEqualTo;
  }
  COutputEvent::FireOutput(this: p_m_OnLessThanOrEqualTo, pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101D9410
// Name: private: virtual struct datamap_t __near * CPointVelocitySensor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointVelocitySensor::GetDataDescMap(CPointVelocitySensor *this)
{
  return &CPointVelocitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D9420
// Name: public: virtual void CPointAngularVelocitySensor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::Spawn(CPointAngularVelocitySensor *this)
{
  LODWORD(this->m_flThreshold) &= _mask__AbsFloat_;
  this->m_nLastFireResult = -2;
  this->m_nLastCompareResult = -2;
  this->m_lastOrientation = vec3_angle;
}

//------------------------------------------------------------------------------
// Address: 0x101D9480
// Name: public: virtual void CPointAngularVelocitySensor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::Activate(CPointAngularVelocitySensor *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTargetEntity.m_Index = -1;
  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9520
// Name: public: virtual void CPointVelocitySensor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointVelocitySensor::Spawn(CPointVelocitySensor *this)
{
  Vector vLine; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  vLine.x = this->m_vecAxis.x - this->m_vecAbsOrigin.x;
  vLine.y = this->m_vecAxis.y - this->m_vecAbsOrigin.y;
  vLine.z = this->m_vecAxis.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &vLine);
  this->m_vecAxis = vLine;
}

//------------------------------------------------------------------------------
// Address: 0x101D95C0
// Name: public: virtual void CPointVelocitySensor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointVelocitySensor::Activate(CPointVelocitySensor *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTargetEntity.m_Index = -1;
  if ( this->m_bEnabled )
  {
    m_Index = this->m_hTargetEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9660
// Name: private: void CPointVelocitySensor::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointVelocitySensor::InputEnable(CPointVelocitySensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // edx

  if ( !this->m_bEnabled )
  {
    this->m_bEnabled = true;
    m_Index = this->m_hTargetEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D96D0
// Name: private: void CPointAngularVelocitySensor::DrawDebugLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::DrawDebugLines(CPointAngularVelocitySensor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // edi
  unsigned int v10; // edx
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Vector *p_m_vecAbsOrigin; // edi
  unsigned int v17; // eax
  unsigned int v18; // edx
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  unsigned int v24; // eax
  unsigned int v25; // edx
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  unsigned int v31; // eax
  Vector *v32; // edi
  unsigned int v33; // ecx
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  unsigned int v39; // edx
  unsigned int v40; // ecx
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  unsigned int v46; // edx
  unsigned int v47; // ecx
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  unsigned int v53; // edx
  QAngle Angles; // [esp+Ch] [ebp-54h] BYREF
  Vector vAxisUp; // [esp+18h] [ebp-48h] BYREF
  Vector vAxisForward; // [esp+24h] [ebp-3Ch] BYREF
  Vector vRight; // [esp+30h] [ebp-30h] BYREF
  Vector vAxisRight; // [esp+3Ch] [ebp-24h] BYREF
  Vector vLine; // [esp+48h] [ebp-18h] BYREF
  float v60; // [esp+54h] [ebp-Ch]
  float v61; // [esp+58h] [ebp-8h]
  float v62; // [esp+5Ch] [ebp-4h]
  int savedregs; // [esp+60h] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      if ( (v9->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
      AngleVectors(angles: &v9->m_angAbsRotation, forward: &vLine, right: &vRight, up: &vAxisForward);
      v10 = (unsigned int)this->m_iEFlags >> 11;
      v11 = vLine.x * 64.0;
      v12 = vLine.y * 64.0;
      v13 = vLine.z * 64.0;
      v60 = vLine.x * 64.0;
      v61 = vLine.y * 64.0;
      v62 = vLine.z * 64.0;
      if ( (v10 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v13 = v62;
        v12 = v61;
        v11 = v60;
      }
      v14 = v12 + this->m_vecAbsOrigin.y;
      v15 = v13 + this->m_vecAbsOrigin.z;
      p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
      v17 = (unsigned int)this->m_iEFlags >> 11;
      vAxisRight.x = this->m_vecAbsOrigin.x + v11;
      vAxisRight.y = v14;
      vAxisRight.z = v15;
      if ( (v17 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &vAxisRight,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 0,
        duration: 0.0);
      v18 = (unsigned int)this->m_iEFlags >> 11;
      v19 = vRight.x * 64.0;
      v20 = vRight.y * 64.0;
      v21 = vRight.z * 64.0;
      v60 = vRight.x * 64.0;
      v61 = vRight.y * 64.0;
      v62 = vRight.z * 64.0;
      if ( (v18 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v21 = v62;
        v20 = v61;
        v19 = v60;
      }
      v22 = v20 + this->m_vecAbsOrigin.y;
      v23 = v21 + this->m_vecAbsOrigin.z;
      v24 = (unsigned int)this->m_iEFlags >> 11;
      vAxisRight.x = p_m_vecAbsOrigin->x + v19;
      vAxisRight.y = v22;
      vAxisRight.z = v23;
      if ( (v24 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &vAxisRight,
        r: 0,
        g: 255,
        b: 0,
        noDepthTest: 0,
        duration: 0.0);
      v25 = (unsigned int)this->m_iEFlags >> 11;
      v26 = vAxisForward.x * 64.0;
      v27 = vAxisForward.y * 64.0;
      v28 = vAxisForward.z * 64.0;
      v60 = vAxisForward.x * 64.0;
      v61 = vAxisForward.y * 64.0;
      v62 = vAxisForward.z * 64.0;
      if ( (v25 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v27 = v61;
        v28 = v62;
        v26 = v60;
      }
      v29 = v27 + this->m_vecAbsOrigin.y;
      v30 = v28 + this->m_vecAbsOrigin.z;
      v31 = (unsigned int)this->m_iEFlags >> 11;
      vAxisRight.x = p_m_vecAbsOrigin->x + v26;
      vAxisRight.y = v29;
      vAxisRight.z = v30;
      if ( (v31 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &vAxisRight,
        r: 0,
        g: 0,
        b: 255,
        noDepthTest: 0,
        duration: 0.0);
    }
  }
  if ( this->m_bUseHelper )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v32 = &this->m_vecAbsOrigin;
    vLine.x = this->m_vecAxis.x - this->m_vecAbsOrigin.x;
    vLine.y = this->m_vecAxis.y - this->m_vecAbsOrigin.y;
    vLine.z = this->m_vecAxis.z - this->m_vecAbsOrigin.z;
    VectorNormalize(vec: &vLine);
    VectorAngles(forward: &vLine, angles: &Angles);
    AngleVectors(angles: &Angles, forward: &vAxisForward, right: &vAxisRight, up: &vAxisUp);
    v33 = (unsigned int)this->m_iEFlags >> 11;
    v34 = vAxisForward.x * 64.0;
    v35 = vAxisForward.y * 64.0;
    v36 = vAxisForward.z * 64.0;
    v60 = vAxisForward.x * 64.0;
    v61 = vAxisForward.y * 64.0;
    v62 = vAxisForward.z * 64.0;
    if ( (v33 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v35 = v61;
      v36 = v62;
      v34 = v60;
    }
    v37 = v35 + this->m_vecAbsOrigin.y;
    v38 = v36 + this->m_vecAbsOrigin.z;
    v39 = (unsigned int)this->m_iEFlags >> 11;
    vRight.x = v32->x + v34;
    vRight.y = v37;
    vRight.z = v38;
    if ( (v39 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Line(
      origin: &this->m_vecAbsOrigin,
      target: &vRight,
      r: 255,
      g: 0,
      b: 0,
      noDepthTest: 0,
      duration: 0.0);
    v40 = (unsigned int)this->m_iEFlags >> 11;
    v41 = vAxisRight.x * 64.0;
    v42 = vAxisRight.y * 64.0;
    v43 = vAxisRight.z * 64.0;
    v60 = vAxisRight.x * 64.0;
    v61 = vAxisRight.y * 64.0;
    v62 = vAxisRight.z * 64.0;
    if ( (v40 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v41 = v60;
      v42 = v61;
      v43 = v62;
    }
    v44 = v42 + this->m_vecAbsOrigin.y;
    v45 = v43 + this->m_vecAbsOrigin.z;
    v46 = (unsigned int)this->m_iEFlags >> 11;
    vRight.x = v32->x + v41;
    vRight.y = v44;
    vRight.z = v45;
    if ( (v46 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Line(
      origin: &this->m_vecAbsOrigin,
      target: &vRight,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 0,
      duration: 0.0);
    v47 = (unsigned int)this->m_iEFlags >> 11;
    v48 = vAxisUp.x * 64.0;
    v49 = vAxisUp.y * 64.0;
    v50 = vAxisUp.z * 64.0;
    v60 = vAxisUp.x * 64.0;
    v61 = vAxisUp.y * 64.0;
    v62 = vAxisUp.z * 64.0;
    if ( (v47 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v48 = v60;
      v49 = v61;
      v50 = v62;
    }
    v51 = v49 + this->m_vecAbsOrigin.y;
    v52 = v50 + this->m_vecAbsOrigin.z;
    v53 = (unsigned int)this->m_iEFlags >> 11;
    vRight.x = v32->x + v48;
    vRight.y = v51;
    vRight.z = v52;
    if ( (v53 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Line(
      origin: &this->m_vecAbsOrigin,
      target: &vRight,
      r: 0,
      g: 0,
      b: 255,
      noDepthTest: 0,
      duration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9C10
// Name: private: float CPointAngularVelocitySensor::SampleAngularVelocity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __userpurge CPointAngularVelocitySensor::SampleAngularVelocity@<st0>(
        CPointAngularVelocitySensor *this@<ecx>,
        int a2@<ebp>,
        CBaseEntity *pEntity)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  double LastThink; // st7
  double v6; // st7
  bool v7; // zf
  double result; // st7
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  __int128 v12; // xmm0
  float v13; // xmm0_4
  __int128 v14; // xmm1
  float z; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  int v19; // [esp-Ch] [ebp-68h] BYREF
  __int128 vecVelocity; // [esp+0h] [ebp-5Ch] OVERLAPPED BYREF
  Vector vecWorldAngVelocity; // [esp+10h] [ebp-4Ch] BYREF
  float v22; // [esp+1Ch] [ebp-40h]
  float v23; // [esp+20h] [ebp-3Ch]
  QAngle angles; // [esp+24h] [ebp-38h] BYREF
  __int128 vecAngVel; // [esp+30h] [ebp-2Ch] OVERLAPPED BYREF
  float v26; // [esp+4Ch] [ebp-10h]
  _DWORD v27[2]; // [esp+50h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+5Ch] [ebp+0h]

  v27[0] = a2;
  v27[1] = retaddr;
  if ( pEntity->m_MoveType.m_Value == 6 )
  {
    m_pPhysicsObject = pEntity->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: (Vector *)&v19, a3: (Vector *)&angles);
      m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: nullptr, a3: (QAngle *)&vecWorldAngVelocity.z);
      LODWORD(v26) = &gpGlobals->curtime;
      LastThink = CBaseEntity::GetLastThink(this, szContext: nullptr);
      v6 = *(float *)LODWORD(v26) - LastThink;
      v26 = v6;
      v7 = v6 == 0.0;
      result = 0.0;
      if ( v7 )
        v9 = 0.1;
      else
        v9 = v26;
      v10 = v22;
      v11 = v23;
      v12 = 0;
      *(float *)&v12 = fsqrt(
                         (float)((float)((float)(v22 - this->m_lastOrientation.y)
                                       * (float)(v22 - this->m_lastOrientation.y))
                               + (float)((float)(v23 - this->m_lastOrientation.z)
                                       * (float)(v23 - this->m_lastOrientation.z)))
                       + (float)((float)(vecWorldAngVelocity.z - this->m_lastOrientation.x)
                               * (float)(vecWorldAngVelocity.z - this->m_lastOrientation.x)));
      vecVelocity = v12;
      v13 = (float)((float)(angles.y * angles.y) + (float)(angles.z * angles.z)) + (float)(angles.x * angles.x);
      v14 = 0;
      *(float *)&v14 = fsqrt(v13);
      vecAngVel = v14;
      if ( *(float *)&v14 * 0.01 <= (float)(*(float *)&vecVelocity / v9) )
      {
        this->m_lastOrientation.x = vecWorldAngVelocity.z;
        this->m_lastOrientation.y = v10;
        this->m_lastOrientation.z = v11;
        if ( this->m_bUseHelper )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v27);
          *((float *)&vecAngVel + 1) = this->m_vecAxis.x - this->m_vecAbsOrigin.x;
          *((float *)&vecAngVel + 2) = this->m_vecAxis.y - this->m_vecAbsOrigin.y;
          *((float *)&vecAngVel + 3) = this->m_vecAxis.z - this->m_vecAbsOrigin.z;
          VectorNormalize(vec: (Vector *)((char *)&vecAngVel + 4));
          m_pPhysicsObject->LocalToWorldVector(
            this: m_pPhysicsObject,
            a2: (Vector *)((char *)&vecVelocity + 4),
            a3: (const Vector *)&angles);
          return *((float *)&vecVelocity + 2) * *((float *)&vecAngVel + 2)
               + *((float *)&vecAngVel + 1) * *((float *)&vecVelocity + 1)
               + *((float *)&vecVelocity + 3) * *((float *)&vecAngVel + 3);
        }
        else
        {
          return fsqrt(v13);
        }
      }
    }
    else
    {
      return 0.0;
    }
  }
  else
  {
    z = pEntity->m_vecAngVelocity.z;
    *(_QWORD *)&angles.x = *(_QWORD *)&pEntity->m_vecAngVelocity.x;
    v16 = fabs(angles.x);
    v17 = fabs(angles.y);
    angles.z = z;
    if ( v16 <= v17 )
      v16 = v17;
    v18 = fabs(angles.z);
    if ( v16 <= v18 )
      return v18;
    else
      return v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D9EA0
// Name: public: CPointAngularVelocitySensor::CPointAngularVelocitySensor(void)
// Source: json
//------------------------------------------------------------------------------
CPointAngularVelocitySensor *__thiscall CPointAngularVelocitySensor::CPointAngularVelocitySensor(
        CPointAngularVelocitySensor *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CPointAngularVelocitySensor_vtbl *)&CPointAngularVelocitySensor::`vftable';
  this->m_hTargetEntity.m_Index = -1;
  this->m_AngularVelocity.m_Value.iVal = 0;
  this->m_AngularVelocity.m_Value.eVal.m_Index = -1;
  this->m_AngularVelocity.m_Value.fieldType = FIELD_VOID;
  this->m_OnLessThan.m_Value.iVal = 0;
  this->m_OnLessThan.m_Value.eVal.m_Index = -1;
  this->m_OnLessThan.m_Value.fieldType = FIELD_VOID;
  this->m_OnLessThanOrEqualTo.m_Value.iVal = 0;
  this->m_OnLessThanOrEqualTo.m_Value.eVal.m_Index = -1;
  this->m_OnLessThanOrEqualTo.m_Value.fieldType = FIELD_VOID;
  this->m_OnGreaterThan.m_Value.iVal = 0;
  this->m_OnGreaterThan.m_Value.eVal.m_Index = -1;
  this->m_OnGreaterThan.m_Value.fieldType = FIELD_VOID;
  this->m_OnGreaterThanOrEqualTo.m_Value.iVal = 0;
  this->m_OnGreaterThanOrEqualTo.m_Value.eVal.m_Index = -1;
  this->m_OnGreaterThanOrEqualTo.m_Value.fieldType = FIELD_VOID;
  this->m_OnEqualTo.m_Value.iVal = 0;
  this->m_OnEqualTo.m_Value.eVal.m_Index = -1;
  this->m_OnEqualTo.m_Value.fieldType = FIELD_VOID;
  this->m_flFireInterval = 0.2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D9FB0
// Name: public: virtual void CPointAngularVelocitySensor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::Think(CPointAngularVelocitySensor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  int *v8; // eax
  int v9; // edi
  float v10; // xmm0_4
  int m_nLastCompareResult; // eax
  float m_flFireTime; // xmm0_4
  float m_flThreshold; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (int *)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = 0;
      m_flThreshold = this->m_flThreshold;
      if ( v9 != 0 )
      {
        value = CPointAngularVelocitySensor::SampleAngularVelocity(
                  this,
                  a2: (int)&savedregs,
                  pEntity: (CBaseEntity *)v9);
        if ( g_debug_angularsensor.m_pParent != nullptr && g_debug_angularsensor.m_pParent->m_Value.m_nValue != 0 )
          CPointAngularVelocitySensor::DrawDebugLines(this);
        v10 = value;
        if ( value != this->m_flLastAngVelocity )
        {
          CEntityOutputTemplate<float,1>::Set(
            this: &this->m_AngularVelocity,
            value,
            pActivator: (CBaseEntity *)v9,
            pCaller: this);
          v10 = value;
          this->m_flLastAngVelocity = value;
        }
        if ( v10 <= m_flThreshold )
        {
          if ( v10 == m_flThreshold )
            v9 = 0;
          else
            v9 = -1;
        }
        else
        {
          v9 = 1;
        }
      }
      m_nLastCompareResult = this->m_nLastCompareResult;
      if ( v9 == m_nLastCompareResult )
      {
        m_flFireTime = this->m_flFireTime;
        if ( m_flFireTime != 0.0 && gpGlobals->curtime >= m_flFireTime )
        {
          CPointAngularVelocitySensor::FireCompareOutput(this, nCompareResult: v9, pActivator: this);
          this->m_nLastFireResult = v9;
          this->m_flFireTime = 0.0;
        }
      }
      else if ( v9 == this->m_nLastFireResult )
      {
        this->m_flFireTime = 0.0;
        this->m_nLastCompareResult = v9;
      }
      else
      {
        if ( m_nLastCompareResult != -2 )
          this->m_flFireTime = this->m_flFireInterval + gpGlobals->curtime;
        this->m_nLastCompareResult = v9;
      }
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA140
// Name: private: void CPointAngularVelocitySensor::InputTestWithInterval(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::InputTestWithInterval(
        CPointAngularVelocitySensor *this,
        inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  CBaseEntity *m_pEntity; // edi
  int v6; // eax
  float v7; // xmm0_4
  float m_flThreshold; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->m_flFireTime = this->m_flFireInterval + gpGlobals->curtime;
    this->m_nLastFireResult = -2;
    v4 = this->m_hTargetEntity.m_Index;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
    m_flThreshold = this->m_flThreshold;
    if ( m_pEntity != nullptr )
    {
      value = CPointAngularVelocitySensor::SampleAngularVelocity(this, a2: (int)&savedregs, pEntity: m_pEntity);
      if ( g_debug_angularsensor.m_pParent != nullptr && g_debug_angularsensor.m_pParent->m_Value.m_nValue != 0 )
        CPointAngularVelocitySensor::DrawDebugLines(this);
      v7 = value;
      if ( value != this->m_flLastAngVelocity )
      {
        CEntityOutputTemplate<float,1>::Set(this: &this->m_AngularVelocity, value, pActivator: m_pEntity, pCaller: this);
        v7 = value;
        this->m_flLastAngVelocity = value;
      }
      if ( v7 > m_flThreshold )
      {
        v6 = 1;
        goto LABEL_19;
      }
      if ( v7 != m_flThreshold )
      {
        v6 = -1;
        goto LABEL_19;
      }
    }
    v6 = 0;
LABEL_19:
    this->m_nLastCompareResult = v6;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA290
// Name: private: void CPointAngularVelocitySensor::InputTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointAngularVelocitySensor::InputTest(CPointAngularVelocitySensor *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  int v5; // eax
  float m_flThreshold; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  m_flThreshold = this->m_flThreshold;
  if ( m_pEntity != nullptr )
  {
    v7 = CPointAngularVelocitySensor::SampleAngularVelocity(this, a2: (int)&savedregs, pEntity: m_pEntity);
    if ( g_debug_angularsensor.m_pParent != nullptr && g_debug_angularsensor.m_pParent->m_Value.m_nValue != 0 )
      CPointAngularVelocitySensor::DrawDebugLines(this);
    if ( v7 > m_flThreshold )
    {
      v5 = 1;
      goto LABEL_14;
    }
    if ( v7 != m_flThreshold )
    {
      v5 = -1;
      goto LABEL_14;
    }
  }
  v5 = 0;
LABEL_14:
  CPointAngularVelocitySensor::FireCompareOutput(this, nCompareResult: v5, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x101DA340
// Name: private: void CPointVelocitySensor::SampleVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointVelocitySensor::SampleVelocity(CPointVelocitySensor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // ecx
  IHandleEntity *m_pEntity; // esi
  CEntInfo *v7; // eax
  IHandleEntity *v8; // eax
  IHandleEntity_vtbl *v9; // ecx
  CBaseEntity *v10; // esi
  float x; // xmm1_4
  float value; // xmm0_4
  bool v13; // zf
  Vector vecVelocity; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[v3].m_SerialNumber == v5 )
        m_pEntity = g_pEntityList->m_EntPtrArray[v3].m_pEntity;
      else
        m_pEntity = nullptr;
      v7 = &g_pEntityList->m_EntPtrArray[v3];
      if ( BYTE2(m_pEntity[53].__vftable) == 6 )
      {
        if ( v7->m_SerialNumber == v5 )
          v8 = v7->m_pEntity;
        else
          v8 = nullptr;
        v9 = v8[82].__vftable;
        if ( v9 != nullptr )
          (*((void (__thiscall **)(IHandleEntity_vtbl *, Vector *, _DWORD))v9->dtr_IHandleEntity + 52))(
            a1: v9,
            a2: &vecVelocity,
            a3: 0);
      }
      else
      {
        if ( v7->m_SerialNumber == v5 )
          v10 = (CBaseEntity *)v7->m_pEntity;
        else
          v10 = nullptr;
        if ( (v10->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: v10, a2: (int)&savedregs);
        vecVelocity = v10->m_vecAbsVelocity;
      }
      x = this->m_vecAxis.x;
      if ( vec3_origin.x == x && vec3_origin.y == this->m_vecAxis.y && vec3_origin.z == this->m_vecAxis.z )
        value = 1.0;
      else
        value = (float)((float)(this->m_vecAxis.y * vecVelocity.y) + (float)(x * vecVelocity.x))
              + (float)(this->m_vecAxis.z * vecVelocity.z);
      v13 = value == this->m_Velocity.m_Value.flVal;
      this->m_fPrevVelocity = value;
      if ( !v13 )
        CEntityOutputTemplate<float,1>::Set(this: &this->m_Velocity, value, pActivator: nullptr, pCaller: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA530
// Name: public: virtual void CPointVelocitySensor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointVelocitySensor::Think(CPointVelocitySensor *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hTargetEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && this->m_bEnabled )
  {
    CPointVelocitySensor::SampleVelocity(this);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104088F0
// Name: CPointAngularVelocitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointAngularVelocitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointAngularVelocitySensor>();
  CPointAngularVelocitySensor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408920
// Name: CPointVelocitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointVelocitySensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointVelocitySensor>();
  CPointVelocitySensor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA4C0
// Name: class CPointVelocitySensor __near * _CreateEntityTemplate<class CPointVelocitySensor>(class CPointVelocitySensor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPointVelocitySensor *__cdecl _CreateEntityTemplate<CPointVelocitySensor>(
        CPointVelocitySensor *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPointVelocitySensor::`vftable';
    v3[213] = -1;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPointVelocitySensor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
