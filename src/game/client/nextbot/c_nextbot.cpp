// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/nextbot/c_nextbot.cpp
// Functions: 12
// ============================================================

#include "game\client\nextbot\c_nextbot.h"

//------------------------------------------------------------------------------
// Address: 0x1023D950
// Name: public: virtual class ClientClass __near * C_NextBotCombatCharacter::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_NextBotCombatCharacter::GetClientClass(C_NextBotCombatCharacter *this)
{
  return &__g_C_NextBotCombatCharacterClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023D9D0
// Name: public: virtual void C_NextBotCombatCharacter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_NextBotCombatCharacter::Spawn(C_NextBotCombatCharacter *this)
{
  C_BaseFlex::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023D9E0
// Name: public: virtual void C_NextBotCombatCharacter::UpdateClientSideAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_NextBotCombatCharacter::UpdateClientSideAnimation(C_NextBotCombatCharacter *this)
{
  if ( !this->IsDormant(this: &this->IClientNetworkable) )
    C_BaseAnimating::UpdateClientSideAnimation(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023DA00
// Name: private: void C_NextBotCombatCharacter::UpdateShadowLOD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_NextBotCombatCharacter::UpdateShadowLOD(C_NextBotCombatCharacter *this)
{
  ShadowType_t m_shadowType; // ebx
  C_BasePlayer *LocalPlayer; // eax
  float *v4; // edi
  const Vector *v5; // eax

  m_shadowType = this->m_shadowType;
  if ( this->m_bForceShadowType )
  {
    this->m_shadowType = this->m_forcedShadowType;
  }
  else if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr
         && (LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1),
             v4 = (float *)LocalPlayer->GetAbsOrigin(this: LocalPlayer),
             v5 = this->GetAbsOrigin(this),
             (float)(NextBotShadowDist.m_pParent->m_Value.m_fValue * NextBotShadowDist.m_pParent->m_Value.m_fValue) > (float)((float)((float)((float)(v5->x - *v4) * (float)(v5->x - *v4)) + (float)((float)(v5->y - v4[1]) * (float)(v5->y - v4[1]))) + (float)((float)(v5->z - v4[2]) * (float)(v5->z - v4[2])))) )
  {
    this->m_shadowType = SHADOWS_RENDER_TO_TEXTURE_DYNAMIC;
  }
  else
  {
    this->m_shadowType = SHADOWS_SIMPLE;
  }
  if ( m_shadowType != this->m_shadowType )
    C_BaseEntity::DestroyShadow(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023DAC0
// Name: public: virtual enum ShadowType_t C_NextBotCombatCharacter::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
ShadowType_t __thiscall C_NextBotCombatCharacter::ShadowCastType(C_NextBotCombatCharacter *this)
{
  if ( HIWORD(this->m_flOldSimulationTime) == 0xFFFF || (this->m_nOldRenderMode & 1) == 0 )
    return SHADOWS_NONE;
  if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_shadowType) > this->m_shadowTimer.m_duration.m_Value )
  {
    CountdownTimer::Start(this: (CountdownTimer *)&this->m_shadowType, duration: 0.15000001);
    C_NextBotCombatCharacter::UpdateShadowLOD(this: (C_NextBotCombatCharacter *)((char *)this - 4));
  }
  return *(&this->m_bloodColor + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1023DB40
// Name: public: C_NextBotCombatCharacter::C_NextBotCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
C_NextBotCombatCharacter *__thiscall C_NextBotCombatCharacter::C_NextBotCombatCharacter(C_NextBotCombatCharacter *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  int v4; // eax
  int v5; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v7; // eax
  C_NextBotCombatCharacter **v8; // eax

  C_BaseCombatCharacter::C_BaseCombatCharacter(this);
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_NextBotCombatCharacter_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_NextBotCombatCharacter::`vftable';
  this->m_shadowTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_shadowTimer.__vftable;
  this->m_shadowTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_shadowTimer.m_duration);
  v3 = this->m_shadowTimer.__vftable;
  this->m_shadowTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_shadowTimer, a2: &this->m_shadowTimer.m_timestamp);
  this->m_EntClientFlags |= 2u;
  this->m_shadowType = SHADOWS_SIMPLE;
  this->m_forcedShadowType = SHADOWS_NONE;
  this->m_bForceShadowType = false;
  if ( (_S7_24 & 1) == 0 )
  {
    _S7_24 |= 1u;
    stru_1066CD34.m_pMemory = nullptr;
    stru_1066CD34.m_nAllocationCount = 0;
    stru_1066CD34.m_nGrowSize = 0;
    dword_1066CD40 = 0;
    dword_1066CD44 = 0;
    atexit(func: TheClientNextBots_::_2_::_dynamic_atexit_destructor_for__manager__);
  }
  v4 = dword_1066CD40;
  v5 = dword_1066CD40;
  if ( dword_1066CD40 + 1 > stru_1066CD34.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: &stru_1066CD34,
      num: dword_1066CD40 - stru_1066CD34.m_nAllocationCount + 1);
    v4 = dword_1066CD40;
  }
  m_pMemory = stru_1066CD34.m_pMemory;
  dword_1066CD40 = v4 + 1;
  v7 = v4 - v5;
  dword_1066CD44 = (int)stru_1066CD34.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&stru_1066CD34.m_pMemory[v5 + 1],
      src: (unsigned __int8 *)&stru_1066CD34.m_pMemory[v5],
      count: 4 * v7);
    m_pMemory = stru_1066CD34.m_pMemory;
  }
  v8 = (C_NextBotCombatCharacter **)&m_pMemory[v5];
  if ( v8 != nullptr )
    *v8 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023DC70
// Name: public: virtual C_NextBotCombatCharacter::~C_NextBotCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_NextBotCombatCharacter::~C_NextBotCombatCharacter(C_NextBotCombatCharacter *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_NextBotCombatCharacter_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_NextBotCombatCharacter::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_NextBotCombatCharacter::`vftable';
  if ( (_S7_24 & 1) == 0 )
  {
    _S7_24 |= 1u;
    stru_1066CD34.m_pMemory = nullptr;
    stru_1066CD34.m_nAllocationCount = 0;
    stru_1066CD34.m_nGrowSize = 0;
    dword_1066CD40 = 0;
    dword_1066CD44 = 0;
    atexit(func: TheClientNextBots_::_2_::_dynamic_atexit_destructor_for__manager__);
  }
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&stru_1066CD34,
    &src);
  C_BaseCombatCharacter::~C_BaseCombatCharacter(this);
}

//------------------------------------------------------------------------------
// Address: 0x10429EF0
// Name: DT_NextBot::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_NextBot::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_NextBot::g_RecvTable);
  return atexit(func: DT_NextBot::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429F10
// Name: DT_NextBot::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_NextBot::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_NextBot::ignored>();
  DT_NextBot::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436280
// Name: DT_NextBot::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_NextBot::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_NextBot::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1023DD00
// Name: _C_NextBotCombatCharacter_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_NextBotCombatCharacter_CreateObject(int entnum, int serialNum)
{
  C_NextBotCombatCharacter *v2; // eax
  C_NextBotCombatCharacter *BotCombatCharacter; // eax
  C_NextBotCombatCharacter *v4; // esi

  v2 = (C_NextBotCombatCharacter *)C_BaseEntity::operator new(stAllocateBlock: 0x1258u);
  if ( v2 == nullptr )
    return nullptr;
  BotCombatCharacter = C_NextBotCombatCharacter::C_NextBotCombatCharacter(this: v2);
  v4 = BotCombatCharacter;
  if ( BotCombatCharacter == nullptr )
    return nullptr;
  BotCombatCharacter->Init(this: BotCombatCharacter, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10429F20
// Name: _dynamic_initializer_for____g_C_BaseTempEntityClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseTempEntityClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseTempEntityClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseTempEntityClientClass;
  return result;
}
