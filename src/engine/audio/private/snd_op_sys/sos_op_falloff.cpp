// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_falloff.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_falloff.h"

//------------------------------------------------------------------------------
// Address: 0x100480E0
// Name: public: virtual void CSosOperatorFalloff::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::SetDefaults(CSosOperatorFalloff *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 1065353216;
  pVoidMem[3] = 1065353216;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10048110
// Name: public: virtual void CSosOperatorFalloff::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::Execute(
        CSosOperatorFalloff *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v7; // xmm0_4
  double v9; // st7
  float v10; // [esp+4h] [ebp-10h]
  float i; // [esp+1Ch] [ebp+8h]

  v7 = pVoidMem[5];
  if ( v7 == 0.0 )
  {
    v9 = 0.0;
  }
  else
  {
    i = snd_refdist.m_pParent->m_Value.m_fValue;
    v9 = snd_refdb_dist_mult / FastPow10(i: v7 * 0.050000001) / i;
  }
  v10 = v9;
  pVoidMem[7] = SND_GetGainFromMult(gain: 1.0, dist_mult: v10, dist: pVoidMem[3]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100481B0
// Name: public: CSosOperatorFalloff::CSosOperatorFalloff(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFalloff *__thiscall CSosOperatorFalloff::CSosOperatorFalloff(CSosOperatorFalloff *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFalloff_vtbl *)&CSosOperatorFalloff::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 28;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_distance", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 20;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_level", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_falloff",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049940
// Name: public: virtual void CSosOperatorFalloff::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::Print(
        CSosOperatorDashboard *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047E50
// Name: public: virtual void CSosOperatorFalloff::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::SetDefaults(CSosOperatorFalloff *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 1065353216;
  pVoidMem[3] = 1065353216;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047E80
// Name: public: virtual void CSosOperatorFalloff::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::Execute(
        CSosOperatorFalloff *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v7; // xmm0_4
  double v9; // st7
  float dist_mult; // [esp+4h] [ebp-10h]
  float flDistMult; // [esp+1Ch] [ebp+8h]

  v7 = pVoidMem[5];
  if ( v7 == 0.0 )
  {
    v9 = 0.0;
  }
  else
  {
    flDistMult = snd_refdist.m_pParent->m_Value.m_fValue;
    v9 = snd_refdb_dist_mult / FastPow10(i: v7 * 0.050000001) / flDistMult;
  }
  dist_mult = v9;
  pVoidMem[7] = SND_GetGainFromMult(gain: 1.0, dist_mult, dist: pVoidMem[3]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047F20
// Name: public: CSosOperatorFalloff::CSosOperatorFalloff(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFalloff *__thiscall CSosOperatorFalloff::CSosOperatorFalloff(CSosOperatorFalloff *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFalloff_vtbl *)&CSosOperatorFalloff::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 28;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_distance", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 20;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_level", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_falloff",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004DD90
// Name: public: virtual void CSosOperatorFalloff::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFalloff::Print(
        CSosOperatorDashboard *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
}

} // namespace engine_xlsp
