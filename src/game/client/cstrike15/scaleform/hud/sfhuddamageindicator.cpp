// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhuddamageindicator.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhuddamageindicator.h"

//------------------------------------------------------------------------------
// Address: 0x10219310
// Name: protected: void SFHudDamageIndicator::IndicateDamage(enum SFHudDamageIndicator::DamageDirection,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::IndicateDamage(
        SFHudDamageIndicator *this,
        SFHudDamageIndicator::DamageDirection dmgDir,
        float newPercentage)
{
  char i; // al
  void *v5; // edi

  if ( this->m_bActive && this->m_FlashAPI != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v5 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v5, a3: 0, a4: dmgDir);
      ((void (__stdcall *)(void *, int, _DWORD))this->m_pScaleformUI->ValueArray_SetElement_4)(
        a1: v5,
        a2: 1,
        a3: LODWORD(newPercentage));
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showDamageDirection",
        a4: v5,
        a5: 2u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v5, a3: 2u);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102193E0
// Name: protected: void SFHudDamageIndicator::HideAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::HideAll(SFHudDamageIndicator *this)
{
  char i; // al

  if ( this->m_FlashAPI != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hideAll",
        a4: nullptr,
        a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219440
// Name: public: virtual void SFHudDamageIndicator::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::ProcessInput(SFHudDamageIndicator *this)
{
  float v1; // xmm0_4
  float m_flAttackFront; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  bool v6; // cc
  float m_flAttackRear; // xmm1_4
  float v8; // xmm1_4
  float m_flAttackLeft; // xmm1_4
  float v10; // xmm1_4
  float m_flAttackRight; // xmm1_4
  float v12; // xmm1_4
  float newPercentage; // [esp+0h] [ebp-Ch]

  v1 = *(float *)(gpGlobals.m_Index + 12);
  m_flAttackFront = this->m_flAttackFront;
  if ( this->m_flFadeCompleteTime <= v1 )
  {
    if ( m_flAttackFront > 0.0
      || this->m_flAttackRear > 0.0
      || this->m_flAttackLeft > 0.0
      || this->m_flAttackRight > 0.0 )
    {
      this->m_flAttackFront = 0.0;
      this->m_flAttackRear = 0.0;
      this->m_flAttackRight = 0.0;
      this->m_flAttackLeft = 0.0;
      SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageTotal, newPercentage: -1.0);
    }
  }
  else
  {
    v4 = (float)(v1 - this->m_lastFrameTime) * g_FadeScale;
    if ( m_flAttackFront > 0.0 )
    {
      v5 = m_flAttackFront - v4;
      if ( v5 < 0.0 )
        v5 = 0.0;
      v6 = v5 <= g_StartFadeThreshold;
      this->m_flAttackFront = v5;
      if ( v6 )
      {
        this->m_flAttackFront = 0.0;
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageUp, newPercentage: -1.0);
      }
      else
      {
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageUp, newPercentage: v5);
      }
    }
    m_flAttackRear = this->m_flAttackRear;
    if ( m_flAttackRear > 0.0 )
    {
      v8 = m_flAttackRear - v4;
      if ( v8 < 0.0 )
        v8 = 0.0;
      v6 = v8 <= g_StartFadeThreshold;
      this->m_flAttackRear = v8;
      if ( v6 )
      {
        this->m_flAttackRear = 0.0;
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageDown, newPercentage: -1.0);
      }
      else
      {
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageDown, newPercentage: v8);
      }
    }
    m_flAttackLeft = this->m_flAttackLeft;
    if ( m_flAttackLeft > 0.0 )
    {
      v10 = m_flAttackLeft - v4;
      if ( v10 < 0.0 )
        v10 = 0.0;
      v6 = v10 <= g_StartFadeThreshold;
      this->m_flAttackLeft = v10;
      if ( v6 )
      {
        this->m_flAttackLeft = 0.0;
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageLeft, newPercentage: -1.0);
      }
      else
      {
        SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageLeft, newPercentage: v10);
      }
    }
    m_flAttackRight = this->m_flAttackRight;
    if ( m_flAttackRight > 0.0 )
    {
      v12 = m_flAttackRight - v4;
      if ( v12 < 0.0 )
        v12 = 0.0;
      v6 = v12 <= g_StartFadeThreshold;
      this->m_flAttackRight = v12;
      if ( v6 )
      {
        this->m_flAttackRight = 0.0;
        newPercentage = -1.0;
      }
      else
      {
        newPercentage = v12;
      }
      SFHudDamageIndicator::IndicateDamage(this, dmgDir: SFDD_DamageRight, newPercentage);
    }
  }
  this->m_lastFrameTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10219600
// Name: public: virtual void SFHudDamageIndicator::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall SFHudDamageIndicator::FlashReady(SFHudDamageIndicator *this)
{
  SFHudDamageIndicator::HideAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10219610
// Name: public: virtual void SFHudDamageIndicator::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::LevelInit(SFHudDamageIndicator *this)
{
  if ( this->m_bFlashAPIIsValid )
    SFHudDamageIndicator::HideAll(this);
  else
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "DamageIndicatorModule",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudDamageIndicator_DamageIndicatorModule);
}

//------------------------------------------------------------------------------
// Address: 0x10219640
// Name: public: virtual void SFHudDamageIndicator::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::Reset(SFHudDamageIndicator *this)
{
  this->m_flAttackFront = 0.0;
  this->m_flAttackRear = 0.0;
  *(_QWORD *)&this->m_flAttackLeft = 0;
  this->m_flFadeCompleteTime = 0.0;
  SFHudDamageIndicator::HideAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10219670
// Name: public: virtual void SFHudDamageIndicator::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::SetActive(SFHudDamageIndicator *this, bool bActive)
{
  if ( this->m_bActive && !bActive )
    SFHudDamageIndicator::HideAll(this);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x102196A0
// Name: private: void SFHudDamageIndicator::CalcDamageDirection(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudDamageIndicator::CalcDamageDirection(
        SFHudDamageIndicator *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecFrom)
{
  C_BasePlayer *LocalPlayer; // eax
  float *v5; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  const QAngle *v8; // eax
  float m_flAttackFront; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float m_flAttackRear; // xmm0_4
  float m_flAttackRight; // xmm0_4
  float v14; // xmm1_4
  float m_flAttackLeft; // xmm0_4
  Vector v16; // [esp-Ch] [ebp-30h] BYREF
  Vector right; // [esp+0h] [ebp-24h] BYREF
  Vector forward; // [esp+Ch] [ebp-18h] BYREF
  Vector vecDelta; // [esp+18h] [ebp-Ch]
  float retaddr; // [esp+24h] [ebp+0h]

  vecDelta.x = a2;
  vecDelta.y = retaddr;
  if ( vec3_origin.x == vecFrom->x && vec3_origin.y == vecFrom->y && vec3_origin.z == vecFrom->z )
  {
    this->m_flAttackFront = 0.0;
    this->m_flAttackRear = 0.0;
    *(_QWORD *)&this->m_flAttackLeft = 0;
  }
  else
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v5 = (float *)LocalPlayer->GetRenderOrigin(this: &LocalPlayer->IClientRenderable);
      y = vecFrom->y;
      z = vecFrom->z;
      forward.x = vecFrom->x - *v5;
      forward.y = y - v5[1];
      forward.z = z - v5[2];
      if ( g_CloseDamageDistance < fsqrt(
                                     (float)((float)(forward.y * forward.y) + (float)(forward.z * forward.z))
                                   + (float)(forward.x * forward.x)) )
      {
        VectorNormalize(vec: &forward);
        v8 = MainViewAngles(nSlot: 0);
        AngleVectors(angles: v8, forward: &right, right: &v16, up: nullptr);
        m_flAttackFront = (float)((float)(right.x * forward.x) + (float)(right.y * forward.y))
                        + (float)(right.z * forward.z);
        v10 = g_DirectionDotTolerance;
        v11 = (float)((float)(v16.x * forward.x) + (float)(v16.y * forward.y)) + (float)(v16.z * forward.z);
        if ( m_flAttackFront <= 0.0 )
        {
          m_flAttackRear = fabs(m_flAttackFront);
          if ( m_flAttackRear > g_DirectionDotTolerance )
          {
            if ( this->m_flAttackRear > m_flAttackRear )
              m_flAttackRear = this->m_flAttackRear;
            this->m_flAttackRear = m_flAttackRear;
          }
        }
        else if ( m_flAttackFront > g_DirectionDotTolerance )
        {
          if ( this->m_flAttackFront > m_flAttackFront )
            m_flAttackFront = this->m_flAttackFront;
          this->m_flAttackFront = m_flAttackFront;
        }
        if ( v11 <= 0.0 )
        {
          v14 = fabs(v11);
          if ( v14 > v10 )
          {
            m_flAttackLeft = this->m_flAttackLeft;
            if ( m_flAttackLeft <= v14 )
              m_flAttackLeft = v14;
            this->m_flAttackLeft = m_flAttackLeft;
          }
        }
        else if ( v11 > v10 )
        {
          m_flAttackRight = this->m_flAttackRight;
          if ( m_flAttackRight <= v11 )
            m_flAttackRight = v11;
          this->m_flAttackRight = m_flAttackRight;
        }
      }
      else
      {
        this->m_flAttackFront = 1.0;
        this->m_flAttackRear = 1.0;
        this->m_flAttackRight = 1.0;
        this->m_flAttackLeft = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102198D0
// Name: public: void SFHudDamageIndicator::MsgFunc_Damage(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDamageIndicator::MsgFunc_Damage(SFHudDamageIndicator *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // edx
  unsigned int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  SFHudDamageIndicator *v15; // ecx
  Vector vecFrom; // [esp+8h] [ebp-10h] BYREF
  SFHudDamageIndicator *v17; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v17 = this;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_15;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_15:
    if ( msg->m_bOverflow )
    {
      v4 = 0;
    }
    else
    {
      v13 = msg->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v11;
      msg->m_nInBufWord = v13 >> v11;
      v4 = v14 | m_nInBufWord;
    }
    goto LABEL_18;
  }
  v3 = msg->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    msg->m_nInBufWord = v3 >> 8;
  }
  else
  {
    v6 = msg->m_pDataIn;
    v7 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      v8 = *v6;
      msg->m_pDataIn = v6 + 1;
      msg->m_nInBufWord = v8;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
LABEL_18:
  CBitRead::ReadBitVec3Coord(this: msg, fa: &vecFrom);
  if ( v4 > 0 )
  {
    v15 = v17;
    v17->m_flFadeCompleteTime = *(float *)(gpGlobals.m_Index + 12) + g_DetectDamageTakenInterval;
    SFHudDamageIndicator::CalcDamageDirection(this: v15, a2: COERCE_FLOAT(&savedregs), &vecFrom);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219A00
// Name: void __MsgFunc_SFHudDamageIndicator_Damage(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudDamageIndicator_Damage(bf_read *msg)
{
  CHud *Hud; // eax
  SFHudDamageIndicator *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (SFHudDamageIndicator *)CHud::FindElement(this: Hud, pName: "SFHudDamageIndicator");
  if ( Element != nullptr )
    SFHudDamageIndicator::MsgFunc_Damage(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10219A30
// Name: public: SFHudDamageIndicator::SFHudDamageIndicator(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudDamageIndicator *__thiscall SFHudDamageIndicator::SFHudDamageIndicator(
        SFHudDamageIndicator *this,
        const char *value)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->m_iFlashSlot = -1;
  this->__vftable = (SFHudDamageIndicator_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudDamageIndicator_vtbl *)&SFHudDamageIndicator::`vftable';
  this->m_lastFrameTime = 0.0;
  this->m_flAttackFront = 0.0;
  this->m_flAttackRear = 0.0;
  this->m_flAttackLeft = 0.0;
  this->m_flAttackRight = 0.0;
  this->m_flFadeCompleteTime = 0.0;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)8);
  CUserMessages::HookMessage(this: usermessages, name: "Damage", hook: __MsgFunc_SFHudDamageIndicator_Damage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10219AC0
// Name: Create_SFHudDamageIndicator
// Source: json
//------------------------------------------------------------------------------
SFHudDamageIndicator *__cdecl Create_SFHudDamageIndicator()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96);
  memset(dst: v0, value: 0, count: 0x60u);
  if ( v0 != nullptr )
    return SFHudDamageIndicator::SFHudDamageIndicator(this: (SFHudDamageIndicator *)v0, value: "SFHudDamageIndicator");
  else
    return nullptr;
}
