// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/predicted_viewmodel.cpp
// Functions: 56
// ============================================================

#include "game\shared\predicted_viewmodel.h"

//------------------------------------------------------------------------------
// Address: 0x10150680
// Name: public: virtual class ClientClass __near * C_PredictedViewModel::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PredictedViewModel::GetClientClass(C_PredictedViewModel *this)
{
  return &__g_C_PredictedViewModelClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10150700
// Name: public: virtual void C_PredictedViewModel::AddViewModelBob(class C_BasePlayer __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_PredictedViewModel::AddViewModelBob(
        C_PredictedViewModel *this@<ecx>,
        long double a2@<esi:edi>,
        C_BasePlayer *owner,
        Vector *eyePosition,
        QAngle *eyeAngles)
{
  HIDWORD(a2) = this;
  if ( cl_use_new_headbob.m_pParent != nullptr
    && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0
    && C_BaseViewModel::ViewModelIndex((C_BaseCombatWeapon *)this) == 1 )
  {
    HIDWORD(a2) += 3420;
    CalcViewModelBobHelper(a1: a2, player: owner, pBobState: (BobState_t *)HIDWORD(a2));
    AddViewModelBobHelper(origin: eyePosition, angles: eyeAngles, pBobState: (BobState_t *)HIDWORD(a2));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150750
// Name: public: virtual void C_PredictedViewModel::CalcViewModelView(class C_BasePlayer __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_PredictedViewModel::CalcViewModelView(
        C_PredictedViewModel *this@<ecx>,
        QAngle *a2@<ebx>,
        int a3@<esi>,
        C_BasePlayer *owner,
        const Vector *eyePosition,
        const QAngle *eyeAngles)
{
  __int64 v7; // xmm0_8
  float z; // ecx
  float x; // xmm0_4
  float m_fValue; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  Vector vecNewOrigin; // [esp+4h] [ebp-18h] BYREF
  QAngle vecNewAngles; // [esp+10h] [ebp-Ch] BYREF

  if ( cl_use_new_headbob.m_pParent != nullptr && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = *(_QWORD *)&eyePosition->x;
    vecNewOrigin.z = eyePosition->z;
    z = eyeAngles->z;
    *(_QWORD *)&vecNewOrigin.x = v7;
    *(_QWORD *)&vecNewAngles.x = *(_QWORD *)&eyeAngles->x;
    vecNewAngles.z = z;
    if ( owner != nullptr )
      owner->IsPlayer(this: owner);
    x = this->m_vLoweredWeaponOffset.x;
    m_fValue = cl_gunlowerspeed.m_pParent->m_Value.m_fValue;
    if ( (float)-x <= m_fValue )
    {
      if ( (float)-m_fValue <= (float)-x )
        v11 = 0.0;
      else
        v11 = x - m_fValue;
    }
    else
    {
      v11 = x + m_fValue;
    }
    v12 = vecNewAngles.x + v11;
    this->m_vLoweredWeaponOffset.x = v11;
    vecNewAngles.x = v12;
    C_BaseViewModel::CalcViewModelView(
      this,
      a2,
      a3: (int)owner,
      owner,
      eyePosition: &vecNewOrigin,
      eyeAngles: &vecNewAngles);
  }
  else
  {
    C_BaseViewModel::CalcViewModelView(this, a2, a3, owner, eyePosition, eyeAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150840
// Name: public: virtual void C_PredictedViewModel::CalcViewModelLag(class Vector __near &,class QAngle __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PredictedViewModel::CalcViewModelLag(
        C_PredictedViewModel *this,
        Vector *origin,
        QAngle *angles,
        QAngle *__formal)
{
  Vector *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  bool (__thiscall *NoteChanged)(struct CInterpolatedVar<QAngle> *, float, float, bool); // edx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float m_fValue; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+20h] [ebp-40h] BYREF
  Vector right; // [esp+2Ch] [ebp-34h] BYREF
  Vector up; // [esp+38h] [ebp-28h] BYREF
  Vector vLaggedForward; // [esp+44h] [ebp-1Ch] BYREF
  QAngle v25; // [esp+50h] [ebp-10h] BYREF
  float interp; // [esp+5Ch] [ebp-4h]

  interp = cl_wpn_sway_interp.m_pParent->m_Value.m_fValue;
  if ( interp != 0.0 )
  {
    if ( !prediction->InPrediction(this: prediction) || prediction->IsFirstTimePredicted(this: prediction) )
    {
      AngleVectors(angles, &forward, &right, &up);
      v7 = interp;
      this->m_vLagAngles.x = angles->x;
      NoteChanged = this->m_LagAnglesHistory.NoteChanged;
      this->m_vLagAngles.y = angles->y;
      this->m_vLagAngles.z = angles->z;
      ((void (__thiscall *)(CInterpolatedVar<QAngle> *, _DWORD, _DWORD, _DWORD))NoteChanged)(
        a1: &this->m_LagAnglesHistory,
        a2: *(_DWORD *)(gpGlobals.m_Index + 12),
        a3: LODWORD(v7),
        a4: 0);
      CInterpolatedVarArrayBase<QAngle,0>::Interpolate(
        this: &this->m_LagAnglesHistory,
        currentTime: *(float *)(gpGlobals.m_Index + 12),
        interpolation_amount: interp);
      v9 = this->m_vLagAngles.y - angles->y;
      v10 = this->m_vLagAngles.z - angles->z;
      v25.x = -(float)(this->m_vLagAngles.x - angles->x);
      v25.y = -v9;
      v25.z = -v10;
      AngleVectors(angles: &v25, forward: &vLaggedForward, right: nullptr, up: nullptr);
      v11 = cl_wpn_sway_scale.m_pParent->m_Value.m_fValue * (float)(1.0 - vLaggedForward.x);
      m_fValue = cl_wpn_sway_scale.m_pParent->m_Value.m_fValue;
      v13 = m_fValue * (float)-vLaggedForward.z;
      v14 = -(float)(m_fValue * (float)-vLaggedForward.y);
      v15 = up.y * v13;
      v16 = up.z * v13;
      v17 = right.x * v14;
      v5 = origin;
      up.y = right.y * v14;
      up.z = right.z * v14;
      v18 = (float)(forward.y * v11) + (float)(right.y * v14);
      v19 = (float)(forward.z * v11) + up.z;
      v20 = (float)((float)(forward.x * v11) + v17) + (float)(up.x * v13);
      this->m_vPredictedOffset.x = v20;
      this->m_vPredictedOffset.y = v18 + v15;
      this->m_vPredictedOffset.z = v19 + v16;
      origin->x = v20 + origin->x;
      v6 = origin->y + this->m_vPredictedOffset.y;
    }
    else
    {
      v5 = origin;
      origin->x = origin->x + this->m_vPredictedOffset.x;
      v6 = this->m_vPredictedOffset.y + origin->y;
    }
    v5->y = v6;
    v5->z = this->m_vPredictedOffset.z + v5->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150AA0
// Name: public: virtual C_PredictedViewModel::~C_PredictedViewModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PredictedViewModel::~C_PredictedViewModel(C_PredictedViewModel *this)
{
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // eax

  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PredictedViewModel_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientUnknown'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientRenderable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientNetworkable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientThinkable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PredictedViewModel::`vftable'{for `C_BaseAnimating'};
  this->C_BaseViewModel::IHasOwner::__vftable = (IHasOwner_vtbl *)&C_PredictedViewModel::`vftable'{for `IHasOwner'};
  this->m_LagAnglesHistory.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  *(_DWORD *)&this->m_LagAnglesHistory.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_LagAnglesHistory.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_LagAnglesHistory.m_LastNetworkedValue);
  m_pElements = this->m_LagAnglesHistory.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_LagAnglesHistory.m_VarHistory.m_pElements = nullptr;
  this->m_LagAnglesHistory.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&IInterpolatedVar::`vftable';
  C_BaseViewModel::~C_BaseViewModel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10150B30
// Name: public: virtual bool C_PredictedViewModel::ShouldPredict(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PredictedViewModel::ShouldPredict(C_PredictedViewModel *this)
{
  C_BaseEntity *v1; // eax

  v1 = this->GetOwner(this);
  return C_BasePlayer::IsLocalPlayer(pEntity: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10150B50
// Name: public: C_PredictedViewModel::C_PredictedViewModel(void)
// Source: json
//------------------------------------------------------------------------------
C_PredictedViewModel *__thiscall C_PredictedViewModel::C_PredictedViewModel(C_PredictedViewModel *this)
{
  C_BaseViewModel::C_BaseViewModel(this);
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PredictedViewModel_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientUnknown'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientRenderable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientNetworkable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PredictedViewModel::`vftable'{for `IClientThinkable'};
  this->C_BaseViewModel::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PredictedViewModel::`vftable'{for `C_BaseAnimating'};
  this->C_BaseViewModel::IHasOwner::__vftable = (IHasOwner_vtbl *)&C_PredictedViewModel::`vftable'{for `IHasOwner'};
  this->m_LagAnglesHistory.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  this->m_LagAnglesHistory.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_LagAnglesHistory.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_LagAnglesHistory.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: &this->m_LagAnglesHistory.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_LagAnglesHistory.m_pDebugName = "CPredictedViewModel::m_LagAnglesHistory";
  this->m_LagAnglesHistory.m_pValue = nullptr;
  this->m_LagAnglesHistory.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_LagAnglesHistory.m_fType = 1;
  this->m_LagAnglesHistory.m_LastNetworkedTime = 0.0;
  this->m_LagAnglesHistory.m_LastNetworkedValue = nullptr;
  this->m_LagAnglesHistory.m_bLooping = nullptr;
  this->m_LagAnglesHistory.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVar<QAngle>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(this: &this->m_LagAnglesHistory, flCurrentTime: 0.0, newmax: 1);
  this->m_BobState.m_flBobTime = 0.0;
  this->m_BobState.m_flLastBobTime = 0.0;
  this->m_BobState.m_flLastSpeed = 0.0;
  this->m_BobState.m_flVerticalBob = 0.0;
  this->m_BobState.m_flLateralBob = 0.0;
  this->m_vLagAngles.x = 0.0;
  this->m_vLagAngles.y = 0.0;
  this->m_vLagAngles.z = 0.0;
  this->m_LagAnglesHistory.Setup(this: &this->m_LagAnglesHistory, a2: (void *)&this->m_vLagAngles, a3: 16);
  this->m_vPredictedOffset.x = 0.0;
  this->m_vPredictedOffset.y = 0.0;
  this->m_vPredictedOffset.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10150D00
// Name: CC_PredictedViewModelFactory
// Source: json
//------------------------------------------------------------------------------
C_PredictedViewModel *__cdecl CC_PredictedViewModelFactory()
{
  C_PredictedViewModel *v0; // eax

  v0 = (C_PredictedViewModel *)C_BaseEntity::operator new(stAllocateBlock: 0xD80u);
  if ( v0 != nullptr )
    return C_PredictedViewModel::C_PredictedViewModel(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1041B810
// Name: DT_PredictedViewModel::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PredictedViewModel::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PredictedViewModel::g_RecvTable);
  return atexit(func: DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B830
// Name: DT_PredictedViewModel::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PredictedViewModel::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PredictedViewModel::ignored>();
  DT_PredictedViewModel::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104335B0
// Name: DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PredictedViewModel::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10150CB0
// Name: _C_PredictedViewModel_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PredictedViewModel_CreateObject(int entnum, int serialNum)
{
  C_PredictedViewModel *v2; // eax
  C_PredictedViewModel *v3; // eax
  C_PredictedViewModel *v4; // esi

  v2 = (C_PredictedViewModel *)C_BaseEntity::operator new(stAllocateBlock: 0xD80u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PredictedViewModel::C_PredictedViewModel(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1041B840
// Name: _dynamic_initializer_for__cl_wpn_sway_interp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_wpn_sway_interp__()
{
  ConVar::ConVar(this: &cl_wpn_sway_interp, pName: "cl_wpn_sway_interp", pDefaultValue: "0.1", flags: 8);
  return atexit(func: dynamic_atexit_destructor_for__cl_wpn_sway_interp__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B870
// Name: _dynamic_initializer_for__cl_wpn_sway_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_wpn_sway_scale__()
{
  ConVar::ConVar(this: &cl_wpn_sway_scale, pName: "cl_wpn_sway_scale", pDefaultValue: "1.0", flags: 16392);
  return atexit(func: dynamic_atexit_destructor_for__cl_wpn_sway_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B8A0
// Name: _dynamic_initializer_for__cl_gunlowerangle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_gunlowerangle__()
{
  ConVar::ConVar(this: &cl_gunlowerangle, pName: "cl_gunlowerangle", pDefaultValue: "90", flags: 8);
  return atexit(func: dynamic_atexit_destructor_for__cl_gunlowerangle__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B8D0
// Name: _dynamic_initializer_for__cl_gunlowerspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_gunlowerspeed__()
{
  ConVar::ConVar(this: &cl_gunlowerspeed, pName: "cl_gunlowerspeed", pDefaultValue: "2", flags: 8);
  return atexit(func: dynamic_atexit_destructor_for__cl_gunlowerspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B900
// Name: _dynamic_initializer_for__cl_predictweapons__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictweapons__()
{
  ConVar::ConVar(
    this: &cl_predictweapons,
    pName: "cl_predictweapons",
    pDefaultValue: "1",
    flags: 512,
    pHelpString: "Perform client side prediction of weapon effects.");
  return atexit(func: dynamic_atexit_destructor_for__cl_predictweapons__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B930
// Name: _dynamic_initializer_for__cl_lagcompensation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_lagcompensation__()
{
  ConVar::ConVar(
    this: &cl_lagcompensation,
    pName: "cl_lagcompensation",
    pDefaultValue: "1",
    flags: 512,
    pHelpString: "Perform server side lag compensation of weapon firing events.");
  return atexit(func: dynamic_atexit_destructor_for__cl_lagcompensation__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B960
// Name: _dynamic_initializer_for__cl_showerror__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showerror__()
{
  ConVar::ConVar(
    this: &cl_showerror,
    pName: "cl_showerror",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show prediction errors, 2 for above plus detailed field deltas.");
  return atexit(func: dynamic_atexit_destructor_for__cl_showerror__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B990
// Name: _dynamic_initializer_for__cl_idealpitchscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_idealpitchscale__()
{
  ConVar::ConVar(this: &cl_idealpitchscale, pName: "cl_idealpitchscale", pDefaultValue: "0.8", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_idealpitchscale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9C0
// Name: _dynamic_initializer_for__cl_predictionlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictionlist__()
{
  ConVar::ConVar(
    this: &cl_predictionlist,
    pName: "cl_predictionlist",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show which entities are predicting\n");
  return atexit(func: dynamic_atexit_destructor_for__cl_predictionlist__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9F0
// Name: _dynamic_initializer_for__cl_predictionentitydump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictionentitydump__()
{
  ConVar::ConVar(
    this: &cl_predictionentitydump,
    pName: "cl_pdump",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Dump info about this entity to screen.");
  return atexit(func: dynamic_atexit_destructor_for__cl_predictionentitydump__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA20
// Name: _dynamic_initializer_for__cl_predictionentitydumpbyclass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictionentitydumpbyclass__()
{
  ConVar::ConVar(
    this: &cl_predictionentitydumpbyclass,
    pName: "cl_pclass",
    pDefaultValue: prType,
    flags: 0x4000,
    pHelpString: "Dump entity by prediction classname.");
  return atexit(func: dynamic_atexit_destructor_for__cl_predictionentitydumpbyclass__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA50
// Name: _dynamic_initializer_for__cl_pred_optimize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pred_optimize__()
{
  ConVar::ConVar(
    this: &cl_pred_optimize,
    pName: "cl_pred_optimize",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Optimize for not copying data if didn't receive a network update (1), and also for not repredicting if there were no errors (2).");
  return atexit(func: dynamic_atexit_destructor_for__cl_pred_optimize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA80
// Name: _dynamic_initializer_for__cl_pred_doresetlatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pred_doresetlatch__()
{
  ConVar::ConVar(this: &cl_pred_doresetlatch, pName: "cl_pred_doresetlatch", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_pred_doresetlatch__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAB0
// Name: _dynamic_initializer_for__cl_prediction_error_timestamps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_prediction_error_timestamps__()
{
  ConVar::ConVar(
    this: &cl_prediction_error_timestamps,
    pName: "cl_prediction_error_timestamps",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_prediction_error_timestamps__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAE0
// Name: _dynamic_initializer_for__g_OptimizedDataMapPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OptimizedDataMapPool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OptimizedDataMapPool,
    blockSize: 0x60u,
    numElements: 20,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OptimizedDataMapPool__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB00
// Name: _dynamic_initializer_for__cl_pred_error_verbose__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pred_error_verbose__()
{
  ConVar::ConVar(
    this: &cl_pred_error_verbose,
    pName: "cl_pred_error_verbose",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show more field info when spewing prediction errors.");
  return atexit(func: dynamic_atexit_destructor_for__cl_pred_error_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB30
// Name: _dynamic_initializer_for__pwatchent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__pwatchent__()
{
  ConVar::ConVar(
    this: &pwatchent,
    pName: "pwatchent",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Entity to watch for prediction system changes.");
  return atexit(func: dynamic_atexit_destructor_for__pwatchent__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB60
// Name: _dynamic_initializer_for__pwatchvar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__pwatchvar__()
{
  ConVar::ConVar(
    this: &pwatchvar,
    pName: "pwatchvar",
    pDefaultValue: prType,
    flags: 0x4000,
    pHelpString: "Entity variable to watch in prediction system for changes.");
  return atexit(func: dynamic_atexit_destructor_for__pwatchvar__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB90
// Name: _dynamic_initializer_for__cl_predictioncopy_describe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictioncopy_describe_command__()
{
  ConCommand::ConCommand(
    this: &cl_predictioncopy_describe_command,
    pName: "cl_predictioncopy_describe",
    callback: (void (__cdecl *)())cl_predictioncopy_describe,
    pHelpString: "Describe datamap_t for entindex",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_predictioncopy_describe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BBC0
// Name: _dynamic_initializer_for__g_ChangeTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ChangeTracker__()
{
  *(_BYTE *)&g_ChangeTracker &= 0xFCu;
  CUtlString::CUtlString(this: &g_ChangeTracker.m_strFieldName);
  CUtlString::CUtlString(this: &g_ChangeTracker.m_strContext);
  g_ChangeTracker.m_History.m_Memory.m_pMemory = nullptr;
  g_ChangeTracker.m_History.m_Memory.m_nAllocationCount = 0;
  g_ChangeTracker.m_History.m_Memory.m_nGrowSize = 0;
  g_ChangeTracker.m_History.m_Size = 0;
  g_ChangeTracker.m_History.m_pElements = nullptr;
  _V_memset(dest: (int)g_ChangeTracker.m_OrigValueBuf, fill: nullptr, count: 0x80u);
  return atexit(func: dynamic_atexit_destructor_for__g_ChangeTracker__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC20
// Name: _dynamic_initializer_for__cl_pred_track_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pred_track_command__()
{
  ConCommand::ConCommand(
    this: &cl_pred_track_command,
    pName: "cl_pred_track",
    callback: (void (__cdecl *)())cl_pred_track,
    pHelpString: "<entindex> <fieldname>:  Track changes to entity index entindex, for field fieldname.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_pred_track_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC50
// Name: _dynamic_initializer_for__sv_pushaway_clientside_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_clientside_size__()
{
  ConVar::ConVar(
    this: &sv_pushaway_clientside_size,
    pName: "sv_pushaway_clientside_size",
    pDefaultValue: "15",
    flags: 8194,
    pHelpString: "Minimum size of pushback objects");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_clientside_size__);
}

//------------------------------------------------------------------------------
// Address: 0x104335C0
// Name: _dynamic_atexit_destructor_for__cl_wpn_sway_interp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_wpn_sway_interp__()
{
  ConVar::~ConVar(this: &cl_wpn_sway_interp);
}

//------------------------------------------------------------------------------
// Address: 0x104335D0
// Name: _dynamic_atexit_destructor_for__cl_wpn_sway_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_wpn_sway_scale__()
{
  ConVar::~ConVar(this: &cl_wpn_sway_scale);
}

//------------------------------------------------------------------------------
// Address: 0x104335E0
// Name: _dynamic_atexit_destructor_for__cl_gunlowerangle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_gunlowerangle__()
{
  ConVar::~ConVar(this: &cl_gunlowerangle);
}

//------------------------------------------------------------------------------
// Address: 0x104335F0
// Name: _dynamic_atexit_destructor_for__cl_gunlowerspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_gunlowerspeed__()
{
  ConVar::~ConVar(this: &cl_gunlowerspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10433600
// Name: _dynamic_atexit_destructor_for__cl_predictweapons__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictweapons__()
{
  ConVar::~ConVar(this: &cl_predictweapons);
}

//------------------------------------------------------------------------------
// Address: 0x10433610
// Name: _dynamic_atexit_destructor_for__cl_lagcompensation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_lagcompensation__()
{
  ConVar::~ConVar(this: &cl_lagcompensation);
}

//------------------------------------------------------------------------------
// Address: 0x10433620
// Name: _dynamic_atexit_destructor_for__cl_showerror__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showerror__()
{
  ConVar::~ConVar(this: &cl_showerror);
}

//------------------------------------------------------------------------------
// Address: 0x10433630
// Name: _dynamic_atexit_destructor_for__cl_idealpitchscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_idealpitchscale__()
{
  ConVar::~ConVar(this: &cl_idealpitchscale);
}

//------------------------------------------------------------------------------
// Address: 0x10433640
// Name: _dynamic_atexit_destructor_for__cl_predictionlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictionlist__()
{
  ConVar::~ConVar(this: &cl_predictionlist);
}

//------------------------------------------------------------------------------
// Address: 0x10433650
// Name: _dynamic_atexit_destructor_for__cl_predictionentitydump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictionentitydump__()
{
  ConVar::~ConVar(this: &cl_predictionentitydump);
}

//------------------------------------------------------------------------------
// Address: 0x10433660
// Name: _dynamic_atexit_destructor_for__cl_predictionentitydumpbyclass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictionentitydumpbyclass__()
{
  ConVar::~ConVar(this: &cl_predictionentitydumpbyclass);
}

//------------------------------------------------------------------------------
// Address: 0x10433670
// Name: _dynamic_atexit_destructor_for__cl_pred_optimize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pred_optimize__()
{
  ConVar::~ConVar(this: &cl_pred_optimize);
}

//------------------------------------------------------------------------------
// Address: 0x10433680
// Name: _dynamic_atexit_destructor_for__cl_pred_doresetlatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pred_doresetlatch__()
{
  ConVar::~ConVar(this: &cl_pred_doresetlatch);
}

//------------------------------------------------------------------------------
// Address: 0x10433690
// Name: _dynamic_atexit_destructor_for__cl_prediction_error_timestamps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_prediction_error_timestamps__()
{
  ConVar::~ConVar(this: &cl_prediction_error_timestamps);
}

//------------------------------------------------------------------------------
// Address: 0x104336A0
// Name: _dynamic_atexit_destructor_for__cl_pred_error_verbose__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pred_error_verbose__()
{
  ConVar::~ConVar(this: &cl_pred_error_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x104336B0
// Name: _dynamic_atexit_destructor_for__pwatchent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pwatchent__()
{
  ConVar::~ConVar(this: &pwatchent);
}

//------------------------------------------------------------------------------
// Address: 0x104336C0
// Name: _dynamic_atexit_destructor_for__pwatchvar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pwatchvar__()
{
  ConVar::~ConVar(this: &pwatchvar);
}

//------------------------------------------------------------------------------
// Address: 0x104336D0
// Name: _dynamic_atexit_destructor_for__cl_predictioncopy_describe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictioncopy_describe_command__()
{
  ConCommand::~ConCommand(this: &cl_predictioncopy_describe_command);
}

//------------------------------------------------------------------------------
// Address: 0x104336E0
// Name: _dynamic_atexit_destructor_for__g_OptimizedDataMapPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OptimizedDataMapPool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OptimizedDataMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x104336F0
// Name: _dynamic_atexit_destructor_for__cl_pred_track_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pred_track_command__()
{
  ConCommand::~ConCommand(this: &cl_pred_track_command);
}

//------------------------------------------------------------------------------
// Address: 0x10433700
// Name: _dynamic_atexit_destructor_for__g_ChangeTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ChangeTracker__()
{
  CValueChangeTracker::~CValueChangeTracker(this: &g_ChangeTracker);
}

//------------------------------------------------------------------------------
// Address: 0x10433710
// Name: _dynamic_atexit_destructor_for__sv_pushaway_clientside_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_clientside_size__()
{
  ConVar::~ConVar(this: &sv_pushaway_clientside_size);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101DD010
// Name: public: virtual class ServerClass __near * CPredictedViewModel::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPredictedViewModel::GetServerClass(CPredictedViewModel *this)
{
  return &g_CPredictedViewModel_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10408A90
// Name: _dynamic_initializer_for__predicted_viewmodel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__predicted_viewmodel__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPredictedViewModel> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &predicted_viewmodel,
           a3: "predicted_viewmodel");
}

//------------------------------------------------------------------------------
// Address: 0x10408AB0
// Name: DT_PredictedViewModel::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PredictedViewModel::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PredictedViewModel::g_SendTable);
  return atexit(func: DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408AD0
// Name: DT_PredictedViewModel::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PredictedViewModel::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PredictedViewModel::ignored>();
  DT_PredictedViewModel::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D660
// Name: DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PredictedViewModel::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PredictedViewModel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D670
// Name: _ServerClassInit_DT_PredictedViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PredictedViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_187;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
