// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_sys_time.cpp
// Functions: 3
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_sys_time.h"

//------------------------------------------------------------------------------
// Address: 0x1004F270
// Name: public: virtual void CSosOperatorSysTime::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSysTime::SetDefaults(CSosOperatorSysTime *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004F290
// Name: public: virtual void CSosOperatorSysTime::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSysTime::Execute(
        CSosOperatorSysTime *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  pVoidMem[4] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
  pVoidMem[3] = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F2F0
// Name: public: CSosOperatorSysTime::CSosOperatorSysTime(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSysTime *__thiscall CSosOperatorSysTime::CSosOperatorSysTime(CSosOperatorSysTime *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSysTime_vtbl *)&CSosOperatorSysTime::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_client_time", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_host_time", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_sys_time",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004EFF0
// Name: public: virtual void CSosOperatorSysTime::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSysTime::SetDefaults(CSosOperatorSysTime *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004F010
// Name: public: virtual void CSosOperatorSysTime::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSysTime::Execute(
        CSosOperatorSysTime *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  pVoidMem[4] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
  pVoidMem[3] = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F070
// Name: public: CSosOperatorSysTime::CSosOperatorSysTime(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSysTime *__thiscall CSosOperatorSysTime::CSosOperatorSysTime(CSosOperatorSysTime *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSysTime_vtbl *)&CSosOperatorSysTime::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_client_time", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_host_time", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_sys_time",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
