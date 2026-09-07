// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_interest_target.cpp
// Functions: 10
// ============================================================

#include "game\server\ai_interest_target.h"

//------------------------------------------------------------------------------
// Address: 0x10057AF0
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x10057B20
// Name: public: bool CAI_InterestTarget_t::IsThis(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_InterestTarget_t::IsThis(CAI_InterestTarget_t *this, CBaseEntity *pThis)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hTarget.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return pThis == nullptr;
  else
    return pThis == g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10057B70
// Name: public: bool CAI_InterestTarget_t::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_InterestTarget_t::IsActive(CAI_InterestTarget_t *this)
{
  bool result; // al
  unsigned int m_Index; // ecx

  result = false;
  if ( gpGlobals->curtime <= this->m_flEndTime )
  {
    if ( this->m_eType != LOOKAT_ENTITY )
      return true;
    m_Index = this->m_hTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057BC0
// Name: public: float CAI_InterestTarget_t::Interest(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_InterestTarget_t::Interest(CAI_InterestTarget_t *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float m_flRamp; // xmm2_4
  double v5; // xmm0_8
  __m128d v6; // xmm0
  double v7; // xmm0_8
  float v8; // xmm1_4
  float t; // [esp+4h] [ebp-4h]

  v2 = (float)(gpGlobals->curtime - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
  t = v2;
  if ( v2 < 0.0 )
    return 0.0;
  v3 = 1.0;
  if ( v2 > 1.0 )
    return 0.0;
  m_flRamp = this->m_flRamp;
  if ( m_flRamp == 0.0 || (float)(1.0 - m_flRamp) <= v2 )
  {
    if ( v2 > (float)(1.0 - m_flRamp) )
      v3 = (float)((float)((float)((float)(1.0 - v2) / m_flRamp) * 3.0) * (float)((float)(1.0 - v2) / m_flRamp))
         - (float)((float)((float)((float)((float)(1.0 - v2) / m_flRamp) * 2.0) * (float)((float)(1.0 - v2) / m_flRamp))
                 * (float)((float)(1.0 - v2) / m_flRamp));
    return this->m_flInterest * v3;
  }
  else
  {
    __libm_sse2_log(a1: (__m128d)0x3FC99999A0000000uLL);
    *(float *)&v5 = v5;
    v6.m128d_f64[0] = (float)((float)(*(float *)&v5 / m_flRamp) * t);
    __libm_sse2_exp(a1: v6);
    v8 = v7;
    return this->m_flInterest * (float)(1.0 - v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057CD0
// Name: public: class Vector const __near & CAI_InterestTarget_t::GetPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_InterestTarget_t::GetPosition(CAI_InterestTarget_t *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // ecx
  float *v10; // eax
  _BYTE v12[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_eType == LOOKAT_ENTITY )
  {
    m_Index = this->m_hTarget.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = &g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
          m_pEntity = v8->m_pEntity;
        else
          m_pEntity = nullptr;
        v10 = (float *)((int (__thiscall *)(IHandleEntity *, _BYTE *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                         a1: m_pEntity,
                         a2: v12);
        this->m_vecPosition.x = *v10;
        this->m_vecPosition.y = v10[1];
        this->m_vecPosition.z = v10[2];
      }
    }
  }
  return &this->m_vecPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10057D50
// Name: public: void CAI_InterestTarget::Add(class CBaseEntity __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_InterestTarget::Add(
        CAI_InterestTarget *this,
        CBaseEntity *pTarget,
        float flImportance,
        float flDuration,
        float flRamp)
{
  int m_Size; // ebx
  int v7; // edx
  CAI_InterestTarget_t *m_pMemory; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  CAI_InterestTarget_t *v14; // ecx
  int v15; // eax
  CAI_InterestTarget_t *v16; // ecx
  CAI_InterestTarget_t *v17; // esi

  m_Size = this->m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    while ( 1 )
    {
      m_Index = m_pMemory->m_hTarget.m_Index;
      if ( m_Index == -1
        || (m_Size = this->m_Size,
            g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pTarget && m_pMemory->m_flRamp == 0.0 )
        break;
      ++v7;
      ++m_pMemory;
      if ( v7 >= this->m_Size )
        goto LABEL_17;
    }
    if ( m_pMemory->m_flStartTime == gpGlobals->curtime && flImportance <= m_pMemory->m_flInterest )
      flImportance = m_pMemory->m_flInterest;
    v11 = m_Size - v7;
    if ( v11 - 1 > 0 )
      _V_memmove(dest: &this->m_Memory.m_pMemory[v7], src: &this->m_Memory.m_pMemory[v7 + 1], count: 36 * (v11 - 1));
    --this->m_Size;
  }
LABEL_17:
  v12 = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( v12 + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(this: &this->m_Memory, num: v12 - m_nAllocationCount + 1);
  ++this->m_Size;
  v14 = this->m_Memory.m_pMemory;
  v15 = this->m_Size - v12 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v15 > 0 )
    _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 36 * v15);
  v16 = &this->m_Memory.m_pMemory[v12];
  if ( v16 != nullptr )
    v16->m_hTarget.m_Index = -1;
  v17 = &this->m_Memory.m_pMemory[v12];
  v17->m_eType = LOOKAT_ENTITY;
  if ( pTarget != nullptr )
    v17->m_hTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
  else
    v17->m_hTarget.m_Index = -1;
  v17->m_vecPosition.x = 0.0;
  v17->m_vecPosition.y = 0.0;
  v17->m_vecPosition.z = 0.0;
  v17->m_flInterest = flImportance;
  v17->m_flStartTime = gpGlobals->curtime;
  v17->m_flEndTime = gpGlobals->curtime + flDuration;
  v17->m_flRamp = flRamp / flDuration;
}

//------------------------------------------------------------------------------
// Address: 0x10057EF0
// Name: public: void CAI_InterestTarget::Add(class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_InterestTarget::Add(
        CAI_InterestTarget *this,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  int m_Size; // edi
  int v7; // ecx
  float *p_z; // edx
  int v9; // edi
  int v10; // edi
  int m_nAllocationCount; // eax
  CAI_InterestTarget_t *m_pMemory; // ecx
  int v13; // eax
  CAI_InterestTarget_t *v14; // eax
  CAI_InterestTarget_t *v15; // eax

  m_Size = this->m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    p_z = &this->m_Memory.m_pMemory->m_vecPosition.z;
    while ( vecPosition->x != *(p_z - 2) || vecPosition->y != *(p_z - 1) || vecPosition->z != *p_z )
    {
      ++v7;
      p_z += 9;
      if ( v7 >= m_Size )
        goto LABEL_11;
    }
    v9 = m_Size - v7;
    if ( v9 - 1 > 0 )
      _V_memmove(dest: &this->m_Memory.m_pMemory[v7], src: &this->m_Memory.m_pMemory[v7 + 1], count: 36 * (v9 - 1));
    --this->m_Size;
  }
LABEL_11:
  v10 = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(this: &this->m_Memory, num: v10 - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v13 = this->m_Size - v10 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 36 * v13);
  v14 = &this->m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    v14->m_hTarget.m_Index = -1;
  v15 = &this->m_Memory.m_pMemory[v10];
  v15->m_eType = LOOKAT_POSITION;
  v15->m_hTarget.m_Index = -1;
  v15->m_vecPosition = *vecPosition;
  v15->m_flInterest = flImportance;
  v15->m_flStartTime = gpGlobals->curtime;
  v15->m_flEndTime = gpGlobals->curtime + flDuration;
  v15->m_flRamp = flRamp / flDuration;
}

//------------------------------------------------------------------------------
// Address: 0x10058030
// Name: public: void CAI_InterestTarget::Add(class CBaseEntity __near *,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_InterestTarget::Add(
        CAI_InterestTarget *this,
        CBaseEntity *pTarget,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  int m_Size; // edi
  int v8; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int v11; // edi
  int v12; // edi
  int m_nAllocationCount; // eax
  CAI_InterestTarget_t *v14; // ecx
  int v15; // eax
  CAI_InterestTarget_t *v16; // ecx
  CAI_InterestTarget_t *v17; // esi
  CAI_InterestTarget_t *m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v8 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    while ( 1 )
    {
      m_Index = m_pMemory->m_hTarget.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity == pTarget )
        break;
      ++m_pMemory;
      if ( ++v8 >= m_Size )
        goto LABEL_16;
    }
    if ( m_pMemory->m_flStartTime == gpGlobals->curtime && flImportance <= m_pMemory->m_flInterest )
      flImportance = m_pMemory->m_flInterest;
    v11 = m_Size - v8;
    if ( v11 - 1 > 0 )
      _V_memmove(dest: &this->m_Memory.m_pMemory[v8], src: &this->m_Memory.m_pMemory[v8 + 1], count: 36 * (v11 - 1));
    --this->m_Size;
  }
LABEL_16:
  v12 = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( v12 + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(this: &this->m_Memory, num: v12 - m_nAllocationCount + 1);
  ++this->m_Size;
  v14 = this->m_Memory.m_pMemory;
  v15 = this->m_Size - v12 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v15 > 0 )
    _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 36 * v15);
  v16 = &this->m_Memory.m_pMemory[v12];
  if ( v16 != nullptr )
    v16->m_hTarget.m_Index = -1;
  v17 = &this->m_Memory.m_pMemory[v12];
  v17->m_eType = LOOKAT_BOTH;
  if ( pTarget != nullptr )
    v17->m_hTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
  else
    v17->m_hTarget.m_Index = -1;
  v17->m_vecPosition = *vecPosition;
  v17->m_flInterest = flImportance;
  v17->m_flStartTime = gpGlobals->curtime;
  v17->m_flEndTime = gpGlobals->curtime + flDuration;
  v17->m_flRamp = flRamp / flDuration;
}

//------------------------------------------------------------------------------
// Address: 0x10401720
// Name: _dynamic_initializer_for__target_cdaudio__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__target_cdaudio__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTargetCDAudioRep> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &target_cdaudio,
           a3: "target_cdaudio");
}

//------------------------------------------------------------------------------
// Address: 0x10401750
// Name: _dynamic_initializer_for__target_changegravity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__target_changegravity__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTargetChangeGravity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &target_changegravity,
           a3: "target_changegravity");
}
