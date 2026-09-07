// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_delta.cpp
// Functions: 3
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_delta.h"

//------------------------------------------------------------------------------
// Address: 0x10047950
// Name: public: virtual void CSosOperatorDelta::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDelta::SetDefaults(CSosOperatorDelta *this, float *pVoidMem)
{
  pVoidMem[3] = 0.0;
  pVoidMem[4] = NAN;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = 0.0;
  pVoidMem[7] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x10047A30
// Name: public: virtual void CSosOperatorDelta::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDelta::Execute(
        CSosOperatorDelta *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4

  v6 = pVoidMem[3];
  pVoidMem[5] = v6 - pVoidMem[6];
  pVoidMem[6] = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047A80
// Name: public: CSosOperatorDelta::CSosOperatorDelta(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDelta *__thiscall CSosOperatorDelta::CSosOperatorDelta(CSosOperatorDelta *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-14h] BYREF
  __int16 v7; // [esp+10h] [ebp-8h]
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDelta_vtbl *)&CSosOperatorDelta::`vftable';
  v7 = 1;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  v7 = 1;
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 20;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_delta",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047770
// Name: public: virtual void CSosOperatorDelta::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDelta::SetDefaults(CSosOperatorDelta *this, float *pVoidMem)
{
  pVoidMem[3] = 0.0;
  pVoidMem[4] = NAN;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = 0.0;
  pVoidMem[7] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x100477B0
// Name: public: virtual void CSosOperatorDelta::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDelta::Execute(
        CSosOperatorDelta *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4

  v6 = pVoidMem[3];
  pVoidMem[5] = v6 - pVoidMem[6];
  pVoidMem[6] = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047800
// Name: public: CSosOperatorDelta::CSosOperatorDelta(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDelta *__thiscall CSosOperatorDelta::CSosOperatorDelta(CSosOperatorDelta *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-14h] BYREF
  __int16 v7; // [esp+10h] [ebp-8h]
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDelta_vtbl *)&CSosOperatorDelta::`vftable';
  v7 = 1;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  v7 = 1;
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 20;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_delta",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
