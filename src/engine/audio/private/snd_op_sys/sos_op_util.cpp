// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_util.cpp
// Functions: 3
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_util.h"

//------------------------------------------------------------------------------
// Address: 0x1004F3B0
// Name: public: virtual void CSosOperatorPrintFloat::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPrintFloat::SetDefaults(CSosOperatorPrintFloat *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004F3D0
// Name: public: virtual void CSosOperatorPrintFloat::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPrintFloat::Execute(
        CSosOperatorPrintFloat *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        channel_t *pStack,
        int nOpIndex)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "SOS PRINT FLOAT: %s: %f\n",
      *(const char **)(LODWORD(pStack->fvolume_target[7]) + 24 * nOpIndex + 16),
      pVoidMem[3]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F450
// Name: public: CSosOperatorPrintFloat::CSosOperatorPrintFloat(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPrintFloat *__thiscall CSosOperatorPrintFloat::CSosOperatorPrintFloat(CSosOperatorPrintFloat *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPrintFloat_vtbl *)&CSosOperatorPrintFloat::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "util_print_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004F130
// Name: public: virtual void CSosOperatorPrintFloat::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPrintFloat::SetDefaults(CSosOperatorPrintFloat *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004F150
// Name: public: virtual void CSosOperatorPrintFloat::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPrintFloat::Execute(
        CSosOperatorPrintFloat *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "SOS PRINT FLOAT: %s: %f\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key,
      pVoidMem[3]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F1D0
// Name: public: CSosOperatorPrintFloat::CSosOperatorPrintFloat(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPrintFloat *__thiscall CSosOperatorPrintFloat::CSosOperatorPrintFloat(CSosOperatorPrintFloat *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPrintFloat_vtbl *)&CSosOperatorPrintFloat::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "util_print_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
