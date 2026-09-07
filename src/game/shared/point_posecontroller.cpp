// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/point_posecontroller.cpp
// Functions: 25
// ============================================================

#include "game\shared\point_posecontroller.h"

//------------------------------------------------------------------------------
// Address: 0x1014D1B0
// Name: public: virtual class ClientClass __near * C_PoseController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PoseController::GetClientClass(C_PoseController *this)
{
  return &__g_C_PoseControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1014D3E0
// Name: public: C_PoseController::C_PoseController(void)
// Source: json
//------------------------------------------------------------------------------
C_PoseController *__thiscall C_PoseController::C_PoseController(C_PoseController *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PoseController_vtbl *)&C_PoseController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PoseController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PoseController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PoseController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PoseController::`vftable';
  this->m_hProps[0].m_Index = -1;
  this->m_hProps[1].m_Index = -1;
  this->m_hProps[2].m_Index = -1;
  this->m_hProps[3].m_Index = -1;
  CInterpolatedValue::CInterpolatedValue(this: &this->m_PoseTransitionValue);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014D440
// Name: public: virtual void C_PoseController::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PoseController::Spawn(C_PoseController *this)
{
  _QWORD v2[2]; // [esp+18h] [ebp-10h] BYREF

  LODWORD(v2[0]) =  __thiscall C_PoseController::`vcall'{4,{flat}};
  HIDWORD(v2[0]) = 12;
  v2[1] = 0;
  C_BaseEntity::ThinkSet(this, a2: (int)v2, func: v2[0], thinkTime: 0.0, szContext: nullptr);
  ((void (__thiscall *)(C_PoseController *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
  this->m_fCurrentFMod = 0.0;
  CInterpolatedValue::Init(
    this: &this->m_PoseTransitionValue,
    startValue: 0.0,
    endValue: 0.0,
    dt: 0.0,
    type: INTERP_LINEAR);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1014D4F0
// Name: private: void C_PoseController::UpdateModulation(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_PoseController::UpdateModulation(C_PoseController *this)
{
  __m128 m_fFModTimeOffset_low; // xmm0
  __m128d v3; // xmm0
  __m128i v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  bool v7; // sf
  unsigned int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  bool v11; // zf
  unsigned int v12; // eax
  int v13; // eax
  float m_fFModRate; // xmm0_4
  float m_fFModAmplitude; // xmm0_4
  float m_fCurrentFMod; // xmm1_4

  switch ( this->m_nFModType )
  {
    case POSECONTROLLER_FMODTYPE_NONE:
      this->m_fCurrentFMod = 0.0;
      break;
    case POSECONTROLLER_FMODTYPE_SINE:
      m_fFModTimeOffset_low = (__m128)LODWORD(this->m_fFModTimeOffset);
      m_fFModTimeOffset_low.m128_f32[0] = (float)(m_fFModTimeOffset_low.m128_f32[0] + *(float *)(gpGlobals.m_Index + 12))
                                        * this->m_fFModRate;
      v3 = _mm_cvtps_pd(m_fFModTimeOffset_low);
      v3.m128d_f64[0] = v3.m128d_f64[0] * 6.283185307179586;
      v4 = (__m128i)_mm_cvtpd_ps(v3);
      *(double *)v4.m128i_i64 = *(float *)v4.m128i_i32;
      __libm_sse2_sin(X: v4);
      *(float *)&v5 = v5;
      this->m_fCurrentFMod = *(float *)&v5 * this->m_fFModAmplitude;
      break;
    case POSECONTROLLER_FMODTYPE_SQUARE:
      if ( (int)COERCE_FLOAT(
                  COERCE_UNSIGNED_INT(
                    (float)(this->m_fFModTimeOffset + *(float *)(gpGlobals.m_Index + 12))
                  * (float)(this->m_fFModRate * 2.0))
                & _mask__AbsFloat_)
         % 2 != 0 )
        LODWORD(this->m_fCurrentFMod) = LODWORD(this->m_fFModAmplitude) ^ _mask__NegFloat_;
      else
        this->m_fCurrentFMod = this->m_fFModAmplitude;
      break;
    case POSECONTROLLER_FMODTYPE_TRIANGLE:
      LODWORD(v6) = COERCE_UNSIGNED_INT(
                      (float)(this->m_fFModTimeOffset + *(float *)(gpGlobals.m_Index + 12))
                    * (float)(this->m_fFModRate * 4.0))
                  & _mask__AbsFloat_;
      v8 = (int)v6 & 0x80000003;
      v7 = (int)v6 < 0;
      v9 = v6 - (float)(int)v6;
      if ( v7 )
        v8 = (((_BYTE)v8 - 1) | 0xFFFFFFFC) + 1;
      switch ( v8 )
      {
        case 0u:
          this->m_fCurrentFMod = this->m_fFModAmplitude * v9;
          break;
        case 1u:
          this->m_fCurrentFMod = (float)(1.0 - v9) * this->m_fFModAmplitude;
          break;
        case 2u:
          LODWORD(this->m_fCurrentFMod) = COERCE_UNSIGNED_INT(this->m_fFModAmplitude * v9) ^ _mask__NegFloat_;
          break;
        case 3u:
          goto $LN7_19;
        default:
          return;
      }
      break;
    case POSECONTROLLER_FMODTYPE_SAWTOOTH:
      LODWORD(v10) = COERCE_UNSIGNED_INT(
                       (float)(this->m_fFModTimeOffset + *(float *)(gpGlobals.m_Index + 12))
                     * (float)(this->m_fFModRate * 2.0))
                   & _mask__AbsFloat_;
      v12 = (int)v10 & 0x80000001;
      v11 = v12 == 0;
      v7 = (int)v10 < 0;
      v9 = v10 - (float)(int)v10;
      if ( v7 )
        v11 = (((_BYTE)v12 - 1) | 0xFFFFFFFE) == -1;
      if ( v11 )
        this->m_fCurrentFMod = this->m_fFModAmplitude * v9;
      else
$LN7_19:
        this->m_fCurrentFMod = (float)(v9 - 1.0) * this->m_fFModAmplitude;
      break;
    case POSECONTROLLER_FMODTYPE_NOISE:
      v13 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: 1);
      m_fFModRate = this->m_fFModRate;
      if ( v13 != 0 )
        this->m_fCurrentFMod = this->m_fCurrentFMod - (float)(m_fFModRate * *(float *)(gpGlobals.m_Index + 16));
      else
        this->m_fCurrentFMod = (float)(m_fFModRate * *(float *)(gpGlobals.m_Index + 16)) + this->m_fCurrentFMod;
      LODWORD(m_fFModAmplitude) = LODWORD(this->m_fFModAmplitude) ^ _mask__NegFloat_;
      m_fCurrentFMod = this->m_fCurrentFMod;
      if ( m_fFModAmplitude <= m_fCurrentFMod )
      {
        m_fFModAmplitude = this->m_fFModAmplitude;
        if ( m_fCurrentFMod <= m_fFModAmplitude )
          m_fFModAmplitude = this->m_fCurrentFMod;
      }
      this->m_fCurrentFMod = m_fFModAmplitude;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D7F0
// Name: private: void C_PoseController::SetCurrentPose(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PoseController::SetCurrentPose(C_PoseController *this, float fCurrentPoseValue)
{
  C_PoseController *v2; // edi
  int v3; // ebx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  C_BaseAnimating *v6; // esi
  bool v7; // zf
  float flValue; // xmm0_4
  int v9; // edi
  CStudioHdr *m_pStudioHdr; // eax
  float fPoseValueMin; // [esp+14h] [ebp-10h] BYREF
  float fPoseValueMax; // [esp+18h] [ebp-Ch] BYREF
  float v14; // [esp+1Ch] [ebp-8h]
  CHandle<C_BaseEntity> *m_hProps; // [esp+20h] [ebp-4h]

  v2 = this;
  v3 = 0;
  m_hProps = this->m_hProps;
  do
  {
    m_Index = m_hProps->m_Index;
    if ( m_hProps->m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    v6 = (C_BaseAnimating *)__RTDynamicCast(
                              inptr: m_pEntity,
                              VfDelta: 0,
                              SrcType: &C_BaseEntity `RTTI Type Descriptor',
                              TargetType: &C_BaseAnimating `RTTI Type Descriptor',
                              isReference: 0);
    if ( v6 != nullptr )
    {
      C_BaseAnimating::GetPoseParameterRange(
        this: v6,
        index: v2->m_chPoseIndex[v3],
        minValue: &fPoseValueMin,
        maxValue: &fPoseValueMax);
      v7 = v6->m_pStudioHdr == nullptr;
      flValue = (float)((float)(fPoseValueMax - fPoseValueMin) * fCurrentPoseValue) + fPoseValueMin;
      v9 = v2->m_chPoseIndex[v3];
      v14 = flValue;
      if ( v7 )
      {
        if ( v6->GetModel(this: &v6->IClientRenderable) != nullptr )
          C_BaseAnimating::LockStudioHdr(this: v6);
        flValue = v14;
      }
      m_pStudioHdr = v6->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      C_BaseAnimating::SetPoseParameter(this: v6, pStudioHdr: m_pStudioHdr, iParameter: v9, flValue);
      v2 = this;
    }
    ++m_hProps;
    ++v3;
  }
  while ( v3 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x1014D900
// Name: public: virtual void C_PoseController::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PoseController::OnDataChanged(C_PoseController *this, DataUpdateType_t updateType)
{
  float fCurrentPoseValue; // xmm0_4
  double v4; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float startValue; // xmm0_4
  char m_Index; // al
  float fClientPoseValue; // [esp+24h] [ebp+8h]

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: -996040704);
    fCurrentPoseValue = *(float *)this->m_chPoseIndex;
    LOBYTE(this->m_fFModRate) = this->m_hProps[3].m_Index;
    this->m_fFModAmplitude = fCurrentPoseValue;
    C_PoseController::SetCurrentPose(this: (C_PoseController *)((char *)this - 8), fCurrentPoseValue);
  }
  if ( LOBYTE(this->m_fFModRate) != LOBYTE(this->m_hProps[3].m_Index) )
  {
    v4 = CInterpolatedValue::Interp(
           this: (CInterpolatedValue *)&this->m_fCurrentPoseValue,
           curTime: *(float *)(gpGlobals.m_Index + 12))
       + this->m_fFModAmplitude;
    v5 = 1.0;
    fClientPoseValue = v4;
    v6 = fClientPoseValue;
    if ( v4 >= 0.0 )
    {
      if ( fClientPoseValue > 1.0 )
        v6 = fClientPoseValue - 1.0;
    }
    else
    {
      v6 = fClientPoseValue + 1.0;
    }
    v7 = *(float *)this->m_chPoseIndex;
    if ( LOBYTE(this->m_fPoseValue) != 0 )
    {
      if ( v6 >= 0.5 )
        v5 = -1.0;
      startValue = (float)(v5 + v6) - v7;
      if ( COERCE_FLOAT(LODWORD(startValue) & _mask__AbsFloat_) > COERCE_FLOAT(COERCE_UNSIGNED_INT(v6 - v7) & _mask__AbsFloat_) )
        startValue = v6 - v7;
      CInterpolatedValue::Init(
        this: (CInterpolatedValue *)&this->m_fCurrentPoseValue,
        startValue,
        endValue: 0.0,
        dt: *(float *)&this->m_bPoseValueParity,
        type: INTERP_LINEAR);
    }
    else
    {
      CInterpolatedValue::Init(
        this: (CInterpolatedValue *)&this->m_fCurrentPoseValue,
        startValue: v6 - v7,
        endValue: 0.0,
        dt: *(float *)&this->m_bPoseValueParity,
        type: INTERP_LINEAR);
    }
    m_Index = this->m_hProps[3].m_Index;
    this->m_fFModAmplitude = *(float *)this->m_chPoseIndex;
    LOBYTE(this->m_fFModRate) = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DA80
// Name: public: virtual void C_PoseController::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PoseController::ClientThink(C_PoseController *this)
{
  double v2; // st7
  float v3; // xmm0_4
  float fCurrentPoseValue; // [esp+Ch] [ebp-4h]

  C_PoseController::UpdateModulation(this: (C_PoseController *)((char *)this - 12));
  this->m_fFModRate = (float)((float)(this->m_fFModAmplitude + this->m_fPoseValue) * *(float *)(gpGlobals.m_Index + 16))
                    + this->m_fFModRate;
  v2 = CInterpolatedValue::Interp(
         this: (CInterpolatedValue *)&this->m_bOldPoseValueParity,
         curTime: *(float *)(gpGlobals.m_Index + 12))
     + this->m_fFModRate;
  fCurrentPoseValue = v2;
  v3 = fCurrentPoseValue;
  if ( v2 >= 0.0 )
  {
    if ( fCurrentPoseValue > 1.0 )
      v3 = fCurrentPoseValue - 1.0;
    C_PoseController::SetCurrentPose(this: (C_PoseController *)((char *)this - 12), fCurrentPoseValue: v3);
  }
  else
  {
    C_PoseController::SetCurrentPose(
      this: (C_PoseController *)((char *)this - 12),
      fCurrentPoseValue: fCurrentPoseValue + 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041B6A0
// Name: DT_PoseController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PoseController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PoseController::g_RecvTable);
  return atexit(func: DT_PoseController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6C0
// Name: DT_PoseController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PoseController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PoseController::ignored>();
  DT_PoseController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433520
// Name: DT_PoseController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PoseController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PoseController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1014D7A0
// Name: _C_PoseController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PoseController_CreateObject(int entnum, int serialNum)
{
  C_PoseController *v2; // eax
  C_PoseController *v3; // eax
  C_PoseController *v4; // esi

  v2 = (C_PoseController *)C_BaseEntity::operator new(stAllocateBlock: 0x9D8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PoseController::C_PoseController(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1041B6D0
// Name: _dynamic_initializer_for__ui_posedebug_fade_in_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_posedebug_fade_in_time__()
{
  ConVar::ConVar(
    this: &ui_posedebug_fade_in_time,
    pName: "ui_posedebug_fade_in_time",
    pDefaultValue: "0.2",
    flags: 147456,
    pHelpString: "Time during which a new pose activity layer is shown in green in +posedebug UI");
  return atexit(func: dynamic_atexit_destructor_for__ui_posedebug_fade_in_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B700
// Name: _dynamic_initializer_for__ui_posedebug_fade_out_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_posedebug_fade_out_time__()
{
  ConVar::ConVar(
    this: &ui_posedebug_fade_out_time,
    pName: "ui_posedebug_fade_out_time",
    pDefaultValue: "0.8",
    flags: 147456,
    pHelpString: "Time to keep a no longer active pose activity layer in red until removing it from +posedebug UI");
  return atexit(func: dynamic_atexit_destructor_for__ui_posedebug_fade_out_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B730
// Name: _dynamic_initializer_for__s_PoseDebuggerImpl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseDebuggerImpl__()
{
  CPoseDebuggerImpl::CPoseDebuggerImpl(this: &s_PoseDebuggerImpl);
  return atexit(func: dynamic_atexit_destructor_for__s_PoseDebuggerImpl__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B750
// Name: _dynamic_initializer_for__posedebuggerstart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__posedebuggerstart__()
{
  ConCommand::ConCommand(
    this: &posedebuggerstart,
    pName: "+posedebug",
    callback: (void (__cdecl *)())IN_PoseDebuggerStart,
    pHelpString: "Turn on pose debugger or add ents to pose debugger UI",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__posedebuggerstart__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B780
// Name: _dynamic_initializer_for__posedebuggerend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__posedebuggerend__()
{
  ConCommand::ConCommand(
    this: &posedebuggerend,
    pName: "-posedebug",
    callback: (void (__cdecl *)())IN_PoseDebuggerEnd,
    pHelpString: "Turn off pose debugger or hide ents from pose debugger UI",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__posedebuggerend__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7B0
// Name: _dynamic_initializer_for__s_PrecacheRegister__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PrecacheRegister__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PrecacheRegister__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7C0
// Name: _dynamic_initializer_for____g_C_PredictedViewModelClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PredictedViewModelClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PredictedViewModelClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PredictedViewModelClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B7E0
// Name: _dynamic_initializer_for__g_Cpredicted_viewmodelFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cpredicted_viewmodelFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_PredictedViewModel *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "predicted_viewmodel",
             a3: "C_PredictedViewModel",
             a4: 3456,
             a5: CC_PredictedViewModelFactory);
  __g_C_PredictedViewModelClientClass.m_pMapClassname = "predicted_viewmodel";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433530
// Name: _dynamic_atexit_destructor_for__ui_posedebug_fade_in_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_posedebug_fade_in_time__()
{
  ConVar::~ConVar(this: &ui_posedebug_fade_in_time);
}

//------------------------------------------------------------------------------
// Address: 0x10433540
// Name: _dynamic_atexit_destructor_for__ui_posedebug_fade_out_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_posedebug_fade_out_time__()
{
  ConVar::~ConVar(this: &ui_posedebug_fade_out_time);
}

//------------------------------------------------------------------------------
// Address: 0x10433550
// Name: _dynamic_atexit_destructor_for__posedebuggerstart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__posedebuggerstart__()
{
  ConCommand::~ConCommand(this: &posedebuggerstart);
}

//------------------------------------------------------------------------------
// Address: 0x10433560
// Name: _dynamic_atexit_destructor_for__posedebuggerend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__posedebuggerend__()
{
  ConCommand::~ConCommand(this: &posedebuggerend);
}

//------------------------------------------------------------------------------
// Address: 0x10433570
// Name: _dynamic_atexit_destructor_for__s_PoseDebuggerImpl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseDebuggerImpl__()
{
  s_PoseDebuggerImpl.__vftable = (CPoseDebuggerImpl_vtbl *)&CPoseDebuggerImpl::`vftable';
  CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_PoseDebuggerImpl.m_mapModelOld.m_Tree);
  CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_PoseDebuggerImpl.m_mapModel.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10433590
// Name: _dynamic_atexit_destructor_for__s_PrecacheRegister__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PrecacheRegister__()
{
  s_PrecacheRegister.__vftable = (CPrecacheRegister_vtbl *)&CPrecacheRegister::`vftable';
  IGameSystem::~IGameSystem(this: &s_PrecacheRegister);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101D35F0
// Name: public: virtual struct datamap_t __near * CPoseController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPoseController::GetDataDescMap(CPoseController *this)
{
  return &CPoseController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D3600
// Name: public: virtual class ServerClass __near * CPoseController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPoseController::GetServerClass(CPoseController *this)
{
  return &g_CPoseController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101D3610
// Name: public: virtual void CPoseController::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::Spawn(CPoseController *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CBaseEntity::ThinkSet(this, func:  __thiscall CBaseEntity::`vcall'{200,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D3960
// Name: public: void CPoseController::InputGetFMod(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputGetFMod(CPoseController *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  DevMsg(
    a1: "FMod values for pose controller %s\nTYPE: %i\nTIME OFFSET: %f\nRATE: %f\nAMPLITUDE: %f\n",
    pszValue,
    this->m_nFModType.m_Value,
    this->m_fFModTimeOffset.m_Value,
    this->m_fFModRate.m_Value,
    this->m_fFModAmplitude.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x101D39C0
// Name: public: void CPoseController::SetCurrentPose(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::SetCurrentPose(CPoseController *this, float fCurrentPoseValue)
{
  CPoseController *v2; // edi
  int v3; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseAnimating *v6; // esi
  bool v7; // zf
  float flValue; // xmm0_4
  int v9; // edi
  CStudioHdr *m_pStudioHdr; // eax
  float fPoseValueMin; // [esp+14h] [ebp-10h] BYREF
  float fPoseValueMax; // [esp+18h] [ebp-Ch] BYREF
  float v14; // [esp+1Ch] [ebp-8h]
  CPoseController::NetworkVar_m_hProps *p_m_hProps; // [esp+20h] [ebp-4h]

  v2 = this;
  v3 = 0;
  p_m_hProps = &this->m_hProps;
  do
  {
    m_Index = p_m_hProps->m_Value[0].m_Index;
    if ( p_m_hProps->m_Value[0].m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    v6 = (CBaseAnimating *)__RTDynamicCast(
                             inptr: m_pEntity,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CBaseAnimating `RTTI Type Descriptor',
                             isReference: 0);
    if ( v6 != nullptr )
    {
      CBaseAnimating::GetPoseParameterRange(
        this: v6,
        index: v2->m_chPoseIndex.m_Value[v3],
        minValue: &fPoseValueMin,
        maxValue: &fPoseValueMax);
      v7 = v6->m_pStudioHdr == nullptr;
      flValue = (float)((float)(fPoseValueMax - fPoseValueMin) * fCurrentPoseValue) + fPoseValueMin;
      v9 = v2->m_chPoseIndex.m_Value[v3];
      v14 = flValue;
      if ( v7 )
      {
        if ( CBaseEntity::GetModel(this: v6) != nullptr )
          CBaseAnimating::LockStudioHdr(this: v6);
        flValue = v14;
      }
      m_pStudioHdr = v6->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      CBaseAnimating::SetPoseParameter(this: v6, pStudioHdr: m_pStudioHdr, iParameter: v9, flValue);
      v2 = this;
    }
    p_m_hProps = (CPoseController::NetworkVar_m_hProps *)((char *)p_m_hProps + 4);
    ++v3;
  }
  while ( v3 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x101D3AC0
// Name: public: void CPoseController::BuildPropList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::BuildPropList(CPoseController *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // ebx
  CPoseController::NetworkVar_m_hProps *p_m_hProps; // edi
  CBaseAnimating *v5; // eax
  CBaseAnimating *v6; // esi
  CDynamicProp *v7; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const CBaseHandle *v10; // eax
  unsigned int v11; // ebx
  CPoseController::NetworkVar_m_hProps *v12; // edi
  edict_t *m_pPev; // ecx
  const char *v14; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  int v16; // ebx
  unsigned __int8 v17; // al
  edict_t *v18; // ecx
  const char *v19; // eax
  CPoseController *v20; // edx
  int v21; // edi
  CHandle<CBaseEntity> *v22; // ebx
  unsigned int v23; // eax
  char *v24; // esi
  CBaseEdict *v25; // ecx
  int v26; // [esp+14h] [ebp-14h]
  CBasePlayer *pEnt; // [esp+18h] [ebp-10h]
  CPoseController::NetworkVar_m_hProps *v28; // [esp+1Ch] [ebp-Ch]
  int iPropNum; // [esp+24h] [ebp-4h]

  pszValue = this->m_iszPropName.pszValue;
  iPropNum = 0;
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
  pEnt = EntityByName;
  if ( EntityByName != nullptr )
  {
    p_m_hProps = &this->m_hProps;
    v28 = &this->m_hProps;
    v26 = -852 - (_DWORD)this;
    while ( iPropNum < 4 )
    {
      v5 = (CBaseAnimating *)__RTDynamicCast(
                               inptr: EntityByName,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CBaseAnimating `RTTI Type Descriptor',
                               isReference: 0);
      v6 = v5;
      if ( v5 != nullptr )
      {
        v7 = (CDynamicProp *)__RTDynamicCast(
                               inptr: v5,
                               VfDelta: 0,
                               SrcType: &CBaseAnimating `RTTI Type Descriptor',
                               TargetType: &CDynamicProp `RTTI Type Descriptor',
                               isReference: 0);
        if ( v7 != nullptr )
          CDynamicProp::PropSetSequence(this: v7, nSequence: 0);
        m_Index = p_m_hProps->m_Value[0].m_Index;
        if ( p_m_hProps->m_Value[0].m_Index == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        }
        if ( m_pEntity != v6 )
        {
          v10 = v6->GetRefEHandle(this: v6);
          v11 = v10->m_Index;
          v12 = (CPoseController::NetworkVar_m_hProps *)((char *)&this->m_hProps + (_DWORD)p_m_hProps + v26);
          if ( v12->m_Value[0].m_Index != v10->m_Index )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * iPropNum + 852);
            }
            v12->m_Value[0].m_Index = v11;
          }
        }
        v14 = this->m_iszPoseParameterName.pszValue;
        if ( v14 == nullptr )
          v14 = locale;
        if ( v6->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v6) != nullptr )
          CBaseAnimating::LockStudioHdr(this: v6);
        m_pStudioHdr = v6->m_pStudioHdr;
        if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
          m_pStudioHdr = nullptr;
        v16 = CBaseAnimating::LookupPoseParameter(this: v6, pStudioHdr: m_pStudioHdr, szName: v14);
        if ( v16 == -1 )
          v16 = 24;
        v17 = this->m_chPoseIndex.m_Value[iPropNum];
        if ( v17 != v16 && (_BYTE)v16 != v17 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v18 = this->m_Network.m_pPev;
            if ( v18 != nullptr )
              CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: iPropNum + 868);
          }
          this->m_chPoseIndex.m_Value[iPropNum] = v16;
        }
        EntityByName = pEnt;
        v28 = (CPoseController::NetworkVar_m_hProps *)((char *)v28 + 4);
        ++iPropNum;
        p_m_hProps = v28;
      }
      v19 = this->m_iszPropName.pszValue;
      if ( v19 == nullptr )
        v19 = locale;
      pEnt = CGlobalEntityList::FindEntityByName(
               this: &gEntList,
               pStartEntity: EntityByName,
               szName: v19,
               pSearchingEntity: nullptr,
               pActivator: nullptr,
               pCaller: nullptr,
               pFilter: nullptr);
      if ( pEnt == nullptr )
      {
        if ( iPropNum >= 4 )
          break;
        goto LABEL_43;
      }
      EntityByName = pEnt;
    }
  }
  else
  {
LABEL_43:
    v20 = this;
    v21 = -852 - (_DWORD)this;
    v22 = &this->m_hProps.m_Value[iPropNum];
    while ( 1 )
    {
      v23 = v22->m_Index;
      if ( v22->m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber == HIWORD(v23)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity != nullptr )
      {
        v24 = (char *)&v20->m_hProps + v21;
        if ( *(unsigned int *)((char *)&v22->m_Index + (_DWORD)v24) != -1 )
        {
          if ( v20->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v20->m_Network + 76) |= 1u;
          }
          else
          {
            v25 = &v20->m_Network.m_pPev->CBaseEdict;
            if ( v25 != nullptr )
            {
              CBaseEdict::StateChanged(this: v25, offset: 4 * iPropNum + 852);
              v21 = -852 - (_DWORD)this;
            }
          }
          *(unsigned int *)((char *)&v22->m_Index + (_DWORD)v24) = -1;
        }
      }
      ++v22;
      if ( ++iPropNum >= 4 )
        break;
      v20 = this;
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D3D90
// Name: public: void CPoseController::BuildPoseIndexList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::BuildPoseIndexList(CPoseController *this)
{
  CPoseController *v1; // ebx
  int v2; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseAnimating *v5; // esi
  const char *pszValue; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  int v8; // ebx
  unsigned __int8 v9; // al
  edict_t *m_pPev; // ecx
  CPoseController::NetworkVar_m_hProps *p_m_hProps; // [esp+10h] [ebp-4h]

  v1 = this;
  v2 = 0;
  p_m_hProps = &this->m_hProps;
  while ( 1 )
  {
    m_Index = p_m_hProps->m_Value[0].m_Index;
    if ( p_m_hProps->m_Value[0].m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    v5 = (CBaseAnimating *)__RTDynamicCast(
                             inptr: m_pEntity,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CBaseAnimating `RTTI Type Descriptor',
                             isReference: 0);
    if ( v5 != nullptr )
    {
      pszValue = v1->m_iszPoseParameterName.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( v5->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v5) != nullptr )
        CBaseAnimating::LockStudioHdr(this: v5);
      m_pStudioHdr = v5->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      v8 = CBaseAnimating::LookupPoseParameter(this: v5, pStudioHdr: m_pStudioHdr, szName: pszValue);
      if ( v8 == -1 )
        v8 = 24;
      v9 = this->m_chPoseIndex.m_Value[v2];
      if ( v9 != v8 && (_BYTE)v8 != v9 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: v2 + 868);
        }
        this->m_chPoseIndex.m_Value[v2] = v8;
      }
    }
    p_m_hProps = (CPoseController::NetworkVar_m_hProps *)((char *)p_m_hProps + 4);
    if ( ++v2 >= 4 )
      break;
    v1 = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3EB0
// Name: public: void CPoseController::InputSetPoseParameterName(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetPoseParameterName(CPoseController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszPoseParameterName.pszValue = iVal;
  CPoseController::BuildPoseIndexList(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D3F60
// Name: public: virtual void CPoseController::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::Think(CPoseController *this)
{
  if ( !this->m_bDisablePropLookup )
  {
    CPoseController::BuildPropList(this);
    CPoseController::SetCurrentPose(this, fCurrentPoseValue: this->m_fPoseValue.m_Value);
    this->m_bDisablePropLookup = true;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3FB0
// Name: public: void CPoseController::SetPoseValue(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::SetPoseValue(CPoseController *this, float fValue)
{
  float v2; // xmm0_4
  CPoseController *v3; // edx
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fPoseValue> *p_m_fPoseValue; // edi
  edict_t *m_pPev; // ecx
  CNetworkVarBase<bool,CPoseController::NetworkVar_m_bPoseValueParity> *p_m_bPoseValueParity; // esi
  bool v7; // bl
  CBaseEdict *v8; // ecx

  v2 = 0.0;
  v3 = this;
  if ( fValue >= 0.0 )
  {
    v2 = 1.0;
    if ( fValue <= 1.0 )
      v2 = fValue;
  }
  p_m_fPoseValue = &this->m_fPoseValue;
  if ( this->m_fPoseValue.m_Value != v2 )
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
        v3 = this;
      }
    }
    p_m_fPoseValue->m_Value = v2;
  }
  p_m_bPoseValueParity = &v3->m_bPoseValueParity;
  v7 = !v3->m_bPoseValueParity.m_Value;
  if ( v3->m_bPoseValueParity.m_Value != v7 )
  {
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v8 != nullptr )
      {
        CBaseEdict::StateChanged(this: v8, offset: 0x369u);
        v3 = this;
      }
    }
    p_m_bPoseValueParity->m_Value = v7;
  }
  CPoseController::SetCurrentPose(this: v3, fCurrentPoseValue: p_m_fPoseValue->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x101D4080
// Name: public: void CPoseController::RandomizeFMod(float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CPoseController::RandomizeFMod(CPoseController *this, float fExtremeness)
{
  unsigned int v3; // eax
  edict_t *m_pPev; // ecx
  PoseController_FModType_t v5; // edi
  edict_t *v6; // ecx
  double v7; // st7
  float v8; // xmm0_4
  float v9; // xmm1_4
  edict_t *v10; // ecx
  double v11; // st7
  float v12; // xmm0_4
  double v13; // st7
  float v14; // xmm0_4
  edict_t *v15; // ecx
  float v16; // [esp+Ch] [ebp-4h]
  float v17; // [esp+Ch] [ebp-4h]
  float fExtremenessa; // [esp+18h] [ebp+8h]
  float fExtremenessb; // [esp+18h] [ebp+8h]
  float fExtremenessc; // [esp+18h] [ebp+8h]

  if ( fExtremeness >= 0.0 )
  {
    if ( fExtremeness <= 1.0 )
      v16 = fExtremeness;
    else
      v16 = 1.0;
  }
  else
  {
    v16 = 0.0;
  }
  v3 = _RandomInt((IUniformRandomStream *)this, a2: 1, a3: 5);
  v5 = v3;
  if ( v3 <= 5 && this->m_nFModType.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x384u);
    }
    this->m_nFModType.m_Value = v5;
  }
  v7 = _RandomFloat(this: (IUniformRandomStream *)m_pPev, a2: -1.0, a3: 1.0);
  if ( v7 >= -1.0 )
  {
    v8 = v7;
    fExtremenessa = v7;
    if ( fExtremenessa > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = -1.0;
  }
  if ( this->m_fFModTimeOffset.m_Value != v8 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x388u);
    }
    this->m_fFModTimeOffset.m_Value = v8;
  }
  v9 = v16 * -10.0;
  v17 = v16 * 10.0;
  v11 = _RandomFloat(this: (IUniformRandomStream *)v6, a2: v9, a3: v17);
  if ( v11 >= -10.0 )
  {
    v12 = v11;
    fExtremenessb = v11;
    if ( fExtremenessb > 10.0 )
      v12 = 10.0;
  }
  else
  {
    v12 = -10.0;
  }
  if ( this->m_fFModRate.m_Value != v12 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x38Cu);
    }
    this->m_fFModRate.m_Value = v12;
  }
  v13 = _RandomFloat(this: (IUniformRandomStream *)v10, a2: 0.0, a3: v17);
  if ( v13 >= 0.0 )
  {
    v14 = v13;
    fExtremenessc = v13;
    if ( fExtremenessc > 10.0 )
      v14 = 10.0;
  }
  else
  {
    v14 = 0.0;
  }
  if ( this->m_fFModAmplitude.m_Value != v14 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fFModAmplitude.m_Value = v14;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x390u);
      this->m_fFModAmplitude.m_Value = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D42E0
// Name: public: void CPoseController::InputSetPoseValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetPoseValue(CPoseController *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    CPoseController::SetPoseValue(this, fValue: inputdata->value.flVal);
  else
    CPoseController::SetPoseValue(this, fValue: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101D4320
// Name: public: void CPoseController::InputSetInterpolationTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetInterpolationTime(CPoseController *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v3; // xmm0_4
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fInterpolationTime> *p_m_fInterpolationTime; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = 0.0;
  if ( flVal >= 0.0 )
  {
    v3 = 10.0;
    if ( flVal <= 10.0 )
      goto LABEL_4;
  }
LABEL_5:
  p_m_fInterpolationTime = &this->m_fInterpolationTime;
  if ( this->m_fInterpolationTime.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fInterpolationTime->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
      p_m_fInterpolationTime->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D43B0
// Name: public: void CPoseController::InputSetCycleFrequency(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetCycleFrequency(CPoseController *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v3; // xmm0_4
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fCycleFrequency> *p_m_fCycleFrequency; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = -10.0;
  if ( flVal >= -10.0 )
  {
    v3 = 10.0;
    if ( flVal <= 10.0 )
      goto LABEL_4;
  }
LABEL_5:
  p_m_fCycleFrequency = &this->m_fCycleFrequency;
  if ( this->m_fCycleFrequency.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fCycleFrequency->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      p_m_fCycleFrequency->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4440
// Name: public: void CPoseController::InputSetFModType(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetFModType(CPoseController *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  CNetworkVarBase<enum PoseController_FModType_t,CPoseController::NetworkVar_m_nFModType> *p_m_nFModType; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( (unsigned int)pszValue > 5 )
      return;
  }
  else
  {
    pszValue = nullptr;
  }
  p_m_nFModType = &this->m_nFModType;
  if ( (const char *)this->m_nFModType.m_Value != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nFModType->m_Value = (PoseController_FModType_t)pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x384u);
      p_m_nFModType->m_Value = (PoseController_FModType_t)pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D44A0
// Name: public: void CPoseController::InputSetFModTimeOffset(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetFModTimeOffset(CPoseController *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v3; // xmm0_4
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fFModTimeOffset> *p_m_fFModTimeOffset; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = -1.0;
  if ( flVal >= -1.0 )
  {
    v3 = 1.0;
    if ( flVal <= 1.0 )
      goto LABEL_4;
  }
LABEL_5:
  p_m_fFModTimeOffset = &this->m_fFModTimeOffset;
  if ( this->m_fFModTimeOffset.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fFModTimeOffset->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
      p_m_fFModTimeOffset->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4530
// Name: public: void CPoseController::InputSetFModRate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetFModRate(CPoseController *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v3; // xmm0_4
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fFModRate> *p_m_fFModRate; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = -10.0;
  if ( flVal >= -10.0 )
  {
    v3 = 10.0;
    if ( flVal <= 10.0 )
      goto LABEL_4;
  }
LABEL_5:
  p_m_fFModRate = &this->m_fFModRate;
  if ( this->m_fFModRate.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fFModRate->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x38Cu);
      p_m_fFModRate->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D45C0
// Name: public: void CPoseController::InputSetFModAmplitude(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputSetFModAmplitude(CPoseController *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float v3; // xmm0_4
  CNetworkVarBase<float,CPoseController::NetworkVar_m_fFModAmplitude> *p_m_fFModAmplitude; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_FLOAT )
  {
    flVal = 0.0;
LABEL_4:
    v3 = flVal;
    goto LABEL_5;
  }
  flVal = inputdata->value.flVal;
  v3 = 0.0;
  if ( flVal >= 0.0 )
  {
    v3 = 10.0;
    if ( flVal <= 10.0 )
      goto LABEL_4;
  }
LABEL_5:
  p_m_fFModAmplitude = &this->m_fFModAmplitude;
  if ( this->m_fFModAmplitude.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fFModAmplitude->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x390u);
      p_m_fFModAmplitude->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4650
// Name: public: void CPoseController::InputRandomizeFMod(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseController::InputRandomizeFMod(CPoseController *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    CPoseController::RandomizeFMod(this, fExtremeness: inputdata->value.flVal);
  else
    CPoseController::RandomizeFMod(this, fExtremeness: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10408730
// Name: CPoseController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPoseController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPoseController>();
  CPoseController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408760
// Name: DT_PoseController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PoseController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PoseController::g_SendTable);
  return atexit(func: DT_PoseController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408780
// Name: DT_PoseController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PoseController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PoseController::ignored>();
  DT_PoseController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D490
// Name: DT_PoseController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PoseController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PoseController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101D3EF0
// Name: class CPoseController __near * _CreateEntityTemplate<class CPoseController>(class CPoseController __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoseController *__cdecl _CreateEntityTemplate<CPoseController>(CPoseController *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPoseController::`vftable';
    v3[213] = -1;
    v3[214] = -1;
    v3[215] = -1;
    v3[216] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPoseController *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408740
// Name: _dynamic_initializer_for__g_CPoseController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPoseController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPoseController_ClassReg,
           pNetworkName: "CPoseController",
           pTable: &DT_PoseController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D4A0
// Name: _ServerClassInit_DT_PoseController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PoseController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_99;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D4C0
// Name: _DataMapInit_CPoseController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPoseController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_339);
}

//------------------------------------------------------------------------------
// Address: 0x1041D4D0
// Name: _DataMapInit_CPointSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_340);
}

//------------------------------------------------------------------------------
// Address: 0x1041D4E0
// Name: _dynamic_atexit_destructor_for__g_PointTemplatePrecacher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PointTemplatePrecacher__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PointTemplatePrecacher.m_Ents);
  IGameSystem::~IGameSystem(this: &g_PointTemplatePrecacher);
}

//------------------------------------------------------------------------------
// Address: 0x1041D500
// Name: _DataMapInit_template_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_template_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_341);
}

//------------------------------------------------------------------------------
// Address: 0x1041D510
// Name: _DataMapInit_CPointTemplate__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointTemplate__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_342);
}

//------------------------------------------------------------------------------
// Address: 0x1041D520
// Name: _DataMapInit_CPointAngleSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointAngleSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_343);
}

//------------------------------------------------------------------------------
// Address: 0x1041D530
// Name: _DataMapInit_CPointProximitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointProximitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_344);
}

//------------------------------------------------------------------------------
// Address: 0x1041D540
// Name: _dynamic_atexit_destructor_for__g_debug_angularsensor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_angularsensor__()
{
  ConVar::~ConVar(this: &g_debug_angularsensor);
}

//------------------------------------------------------------------------------
// Address: 0x1041D550
// Name: _DataMapInit_CPointAngularVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointAngularVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_345);
}

//------------------------------------------------------------------------------
// Address: 0x1041D560
// Name: _DataMapInit_CPointVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_346);
}

//------------------------------------------------------------------------------
// Address: 0x1041D570
// Name: _DataMapInit_CPointHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_347);
}

//------------------------------------------------------------------------------
// Address: 0x1041D580
// Name: _DataMapInit_CPointTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_348);
}

} // namespace server
