// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_distant_dsp.cpp
// Functions: 3
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_distant_dsp.h"

//------------------------------------------------------------------------------
// Address: 0x10047B40
// Name: public: virtual void CSosOperatorDistantDSP::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDistantDSP::SetDefaults(CSosOperatorDistantDSP *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 1065353216;
  pVoidMem[3] = 1065353216;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1115815936;
  pVoidMem[6] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047B80
// Name: public: virtual void CSosOperatorDistantDSP::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDistantDSP::Execute(
        CSosOperatorDistantDSP *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        channel_t *pStack,
        int nOpIndex)
{
  if ( pChannel != nullptr )
  {
    pVoidMem[7] = SND_GetDspMix(pchannel: pChannel, idist: (int)pVoidMem[3], flSndlvl: pVoidMem[5]);
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      *(const char **)(LODWORD(pStack->fvolume_target[7]) + 24 * nOpIndex + 16));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047C20
// Name: public: CSosOperatorDistantDSP::CSosOperatorDistantDSP(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDistantDSP *__thiscall CSosOperatorDistantDSP::CSosOperatorDistantDSP(CSosOperatorDistantDSP *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDistantDSP_vtbl *)&CSosOperatorDistantDSP::`vftable';
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
    pName: "calc_distant_dsp",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100478C0
// Name: public: virtual void CSosOperatorDistantDSP::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDistantDSP::SetDefaults(CSosOperatorDistantDSP *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 1065353216;
  pVoidMem[3] = 1065353216;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1115815936;
  pVoidMem[6] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047900
// Name: public: virtual void CSosOperatorDistantDSP::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDistantDSP::Execute(
        CSosOperatorDistantDSP *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( pChannel != nullptr )
  {
    pVoidMem[7] = SND_GetDspMix(pchannel: pChannel, idist: (int)pVoidMem[3], flSndlvl: pVoidMem[5]);
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100479A0
// Name: public: CSosOperatorDistantDSP::CSosOperatorDistantDSP(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDistantDSP *__thiscall CSosOperatorDistantDSP::CSosOperatorDistantDSP(CSosOperatorDistantDSP *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDistantDSP_vtbl *)&CSosOperatorDistantDSP::`vftable';
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
    pName: "calc_distant_dsp",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
