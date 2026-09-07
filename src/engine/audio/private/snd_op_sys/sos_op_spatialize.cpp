// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_spatialize.cpp
// Functions: 3
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_spatialize.h"

//------------------------------------------------------------------------------
// Address: 0x1004DF30
// Name: public: virtual void CSosOperatorSpatializeSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpatializeSpeakers::SetDefaults(CSosOperatorSpatializeSpeakers *this, _DWORD *pVoidMem)
{
  pVoidMem[11] = 0;
  pVoidMem[12] = -1;
  pVoidMem[13] = 1061158912;
  pVoidMem[14] = -1;
  pVoidMem[9] = 0;
  pVoidMem[10] = -1;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[15] = 0;
  pVoidMem[16] = 0;
  pVoidMem[17] = 0;
  pVoidMem[18] = 0;
  pVoidMem[19] = 0;
  pVoidMem[20] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DFA0
// Name: public: virtual void CSosOperatorSpatializeSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSosOperatorSpatializeSpeakers::Execute(
        CSosOperatorSpatializeSpeakers *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        channel_t *nOpIndex)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float build_volumes[12]; // [esp+10h] [ebp-4Ch] BYREF
  Vector v13; // [esp+40h] [ebp-1Ch] BYREF
  Vector vSourceVector; // [esp+4Ch] [ebp-10h]
  int vPosition; // [esp+58h] [ebp-4h] OVERLAPPED
  float flRearStereoScale; // [esp+64h] [ebp+8h]

  v7 = *((float *)pVoidMem + 11);
  v8 = *((float *)pVoidMem + 9);
  vPosition = *((_DWORD *)pVoidMem + 13);
  flRearStereoScale = 0.0;
  if ( v7 > 0.0 && v7 > v8 )
  {
    v10 = v7 * 0.5;
    v11 = v8 - v10;
    if ( v11 < 0.0 )
      v11 = 0.0;
    flRearStereoScale = 1.0 - (float)(v11 / v10);
  }
  vSourceVector = *(Vector *)((_BYTE *)pVoidMem + 1);
  memset(build_volumes, 0, sizeof(build_volumes));
  v13.x = vSourceVector.x - pScratchPad->m_vPlayerOrigin[0].x;
  v13.y = vSourceVector.y - pScratchPad->m_vPlayerOrigin[0].y;
  v13.z = vSourceVector.z - pScratchPad->m_vPlayerOrigin[0].z;
  VectorNormalize(vec: &v13);
  ((void (__thiscall *)(IAudioDevice *, _DWORD, float *, Vector *, _DWORD, int))g_AudioDevice->SpatializeChannel)(
    a1: g_AudioDevice,
    a2: 0,
    a3: build_volumes,
    a4: &v13,
    a5: LODWORD(flRearStereoScale),
    a6: vPosition);
  SND_MergeVolumes((const float (*)[6])build_volumes, volumes: (float *)pVoidMem + 15);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: (int)nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E0D0
// Name: public: CSosOperatorSpatializeSpeakers::CSosOperatorSpatializeSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSpatializeSpeakers *__thiscall CSosOperatorSpatializeSpeakers::CSosOperatorSpatializeSpeakers(
        CSosOperatorSpatializeSpeakers *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSpatializeSpeakers_vtbl *)&CSosOperatorSpatializeSpeakers::`vftable';
  src.m_nCount = 6;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 44;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_radius", element: &nIndex);
  v7 = this->m_vInputs.m_Size;
  src.m_nOffset = 52;
  src.m_nOffsetOffset = 56;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v7,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_rear_stereo_scale", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_distance", element: &nIndex);
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_spatialize_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004DD20
// Name: public: virtual void CSosOperatorSpatializeSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpatializeSpeakers::SetDefaults(CSosOperatorSpatializeSpeakers *this, _DWORD *pVoidMem)
{
  pVoidMem[11] = 0;
  pVoidMem[12] = -1;
  pVoidMem[13] = 1061158912;
  pVoidMem[14] = -1;
  pVoidMem[9] = 0;
  pVoidMem[10] = -1;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[15] = 0;
  pVoidMem[16] = 0;
  pVoidMem[17] = 0;
  pVoidMem[18] = 0;
  pVoidMem[19] = 0;
  pVoidMem[20] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DDA0
// Name: public: virtual void CSosOperatorSpatializeSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpatializeSpeakers::Execute(
        CSosOperatorSpatializeSpeakers *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float build_volumes[2][6]; // [esp+10h] [ebp-4Ch] BYREF
  Vector vSourceVector; // [esp+40h] [ebp-1Ch] BYREF
  Vector vPosition; // [esp+4Ch] [ebp-10h]
  int flRearStereoScale; // [esp+58h] [ebp-4h]
  float flMono; // [esp+64h] [ebp+8h]

  v7 = *((float *)pVoidMem + 11);
  v8 = *((float *)pVoidMem + 9);
  flRearStereoScale = *((_DWORD *)pVoidMem + 13);
  flMono = 0.0;
  if ( v7 > 0.0 && v7 > v8 )
  {
    v10 = v7 * 0.5;
    v11 = v8 - v10;
    if ( v11 < 0.0 )
      v11 = 0.0;
    flMono = 1.0 - (float)(v11 / v10);
  }
  vPosition = *(Vector *)((_BYTE *)pVoidMem + 1);
  memset(build_volumes, 0, sizeof(build_volumes));
  vSourceVector.x = vPosition.x - pScratchPad->m_vPlayerOrigin[0].x;
  vSourceVector.y = vPosition.y - pScratchPad->m_vPlayerOrigin[0].y;
  vSourceVector.z = vPosition.z - pScratchPad->m_vPlayerOrigin[0].z;
  VectorNormalize(vec: &vSourceVector);
  ((void (__thiscall *)(IAudioDevice *, _DWORD, float *, Vector *, _DWORD, int))g_AudioDevice->SpatializeChannel)(
    a1: g_AudioDevice,
    a2: 0,
    a3: (float *)build_volumes,
    a4: &vSourceVector,
    a5: LODWORD(flMono),
    a6: flRearStereoScale);
  SND_MergeVolumes(build_volumes, volumes: (float *)pVoidMem + 15);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DED0
// Name: public: CSosOperatorSpatializeSpeakers::CSosOperatorSpatializeSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSpatializeSpeakers *__thiscall CSosOperatorSpatializeSpeakers::CSosOperatorSpatializeSpeakers(
        CSosOperatorSpatializeSpeakers *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSpatializeSpeakers_vtbl *)&CSosOperatorSpatializeSpeakers::`vftable';
  src.m_nCount = 6;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 44;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_radius", element: &nIndex);
  v7 = this->m_vInputs.m_Size;
  src.m_nOffset = 52;
  src.m_nOffsetOffset = 56;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v7,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_rear_stereo_scale", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_distance", element: &nIndex);
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_spatialize_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
