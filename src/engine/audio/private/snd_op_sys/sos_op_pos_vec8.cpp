// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_pos_vec8.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_pos_vec8.h"

//------------------------------------------------------------------------------
// Address: 0x1004D070
// Name: public: virtual void CSosOperatorPosVec8::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPosVec8::SetDefaults(CSosOperatorPosVec8 *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
  pVoidMem[5] = 0;
  pVoidMem[6] = 0;
  pVoidMem[9] = 1065353216;
  pVoidMem[10] = -1;
  pVoidMem[7] = 0;
  pVoidMem[8] = -1;
  pVoidMem[11] = 0;
  pVoidMem[14] = -1;
  pVoidMem[12] = 0;
  pVoidMem[15] = -1;
  pVoidMem[13] = 0;
  pVoidMem[16] = -1;
  pVoidMem[17] = 0;
  pVoidMem[20] = -1;
  pVoidMem[18] = 0;
  pVoidMem[21] = -1;
  pVoidMem[19] = 0;
  pVoidMem[22] = -1;
  pVoidMem[23] = 0;
  pVoidMem[26] = -1;
  pVoidMem[24] = 0;
  pVoidMem[27] = -1;
  pVoidMem[25] = 0;
  pVoidMem[28] = -1;
  pVoidMem[29] = 0;
  pVoidMem[32] = -1;
  pVoidMem[30] = 0;
  pVoidMem[33] = -1;
  pVoidMem[31] = 0;
  pVoidMem[34] = -1;
  pVoidMem[35] = 0;
  pVoidMem[38] = -1;
  pVoidMem[36] = 0;
  pVoidMem[39] = -1;
  pVoidMem[37] = 0;
  pVoidMem[40] = -1;
  pVoidMem[41] = 0;
  pVoidMem[44] = -1;
  pVoidMem[42] = 0;
  pVoidMem[45] = -1;
  pVoidMem[43] = 0;
  pVoidMem[46] = -1;
  pVoidMem[47] = 0;
  pVoidMem[50] = -1;
  pVoidMem[48] = 0;
  pVoidMem[51] = -1;
  pVoidMem[49] = 0;
  pVoidMem[52] = -1;
  pVoidMem[53] = 0;
  pVoidMem[56] = -1;
  pVoidMem[54] = 0;
  pVoidMem[57] = -1;
  pVoidMem[55] = 0;
  pVoidMem[58] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D1C0
// Name: public: virtual void CSosOperatorPosVec8::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPosVec8::Execute(
        CSosOperatorPosVec8 *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  int v7; // esi
  float *v8; // edx
  double v9; // st7

  v6 = pVoidMem[9];
  v7 = (int)pVoidMem[7];
  if ( v7 >= (int)v6 )
    v7 = (int)v6 - 1;
  v8 = pVoidMem + 11;
  switch ( v7 < 0 ? 0 : v7 )
  {
    case 1:
      v8 = pVoidMem + 17;
      break;
    case 2:
      v8 = pVoidMem + 23;
      break;
    case 3:
      v8 = pVoidMem + 29;
      break;
    case 4:
      v8 = pVoidMem + 35;
      break;
    case 5:
      v8 = pVoidMem + 41;
      break;
    case 6:
      v8 = pVoidMem + 47;
      break;
    case 7:
      v8 = pVoidMem + 53;
      break;
    default:
      break;
  }
  pVoidMem[3] = *v8;
  pVoidMem[4] = v8[1];
  v9 = v8[2];
  pVoidMem[6] = v6 - 1.0;
  pVoidMem[5] = v9;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D290
// Name: public: CSosOperatorPosVec8::CSosOperatorPosVec8(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPosVec8 *__thiscall CSosOperatorPosVec8::CSosOperatorPosVec8(CSosOperatorPosVec8 *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-8h] [ebp-28h]
  int v11; // [esp-8h] [ebp-28h]
  int v12; // [esp-8h] [ebp-28h]
  int v13; // [esp-8h] [ebp-28h]
  int v14; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPosVec8_vtbl *)&CSosOperatorPosVec8::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 12;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_max_index", element: &nIndex);
  v9 = this->m_vInputs.m_Size;
  src.m_nOffset = 28;
  src.m_nOffsetOffset = 32;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v9,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_index", element: &nIndex);
  v10 = this->m_vInputs.m_Size;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v10,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_entry_count", element: &nIndex);
  v3 = this->m_vInputs.m_Size;
  src.m_nOffset = 44;
  src.m_nOffsetOffset = 56;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v3,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_0", element: &nIndex);
  v11 = this->m_vInputs.m_Size;
  src.m_nOffset = 68;
  src.m_nOffsetOffset = 80;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v11,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_1", element: &nIndex);
  v12 = this->m_vInputs.m_Size;
  src.m_nOffset = 92;
  src.m_nOffsetOffset = 104;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v12,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_2", element: &nIndex);
  v4 = this->m_vInputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffset = 116;
  src.m_nOffsetOffset = 128;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v4,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_3", element: &nIndex);
  v13 = this->m_vInputs.m_Size;
  src.m_nOffset = 140;
  src.m_nOffsetOffset = 152;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v13,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_4", element: &nIndex);
  src.m_nOffset = 164;
  src.m_nOffsetOffset = 176;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_5", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffset = 188;
  src.m_nOffsetOffset = 200;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_6", element: &nIndex);
  v14 = this->m_vInputs.m_Size;
  src.m_nOffset = 212;
  src.m_nOffsetOffset = 224;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v14,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_7", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "util_pos_vec8",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004D5E0
// Name: public: virtual unsigned int CSosOperatorPosVec8::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorPosVec8::GetSize(CSosOperatorPosVec8 *this)
{
  return 236;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004CE60
// Name: public: virtual void CSosOperatorPosVec8::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPosVec8::SetDefaults(CSosOperatorPosVec8 *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
  pVoidMem[5] = 0;
  pVoidMem[6] = 0;
  pVoidMem[9] = 1065353216;
  pVoidMem[10] = -1;
  pVoidMem[7] = 0;
  pVoidMem[8] = -1;
  pVoidMem[11] = 0;
  pVoidMem[14] = -1;
  pVoidMem[12] = 0;
  pVoidMem[15] = -1;
  pVoidMem[13] = 0;
  pVoidMem[16] = -1;
  pVoidMem[17] = 0;
  pVoidMem[20] = -1;
  pVoidMem[18] = 0;
  pVoidMem[21] = -1;
  pVoidMem[19] = 0;
  pVoidMem[22] = -1;
  pVoidMem[23] = 0;
  pVoidMem[26] = -1;
  pVoidMem[24] = 0;
  pVoidMem[27] = -1;
  pVoidMem[25] = 0;
  pVoidMem[28] = -1;
  pVoidMem[29] = 0;
  pVoidMem[32] = -1;
  pVoidMem[30] = 0;
  pVoidMem[33] = -1;
  pVoidMem[31] = 0;
  pVoidMem[34] = -1;
  pVoidMem[35] = 0;
  pVoidMem[38] = -1;
  pVoidMem[36] = 0;
  pVoidMem[39] = -1;
  pVoidMem[37] = 0;
  pVoidMem[40] = -1;
  pVoidMem[41] = 0;
  pVoidMem[44] = -1;
  pVoidMem[42] = 0;
  pVoidMem[45] = -1;
  pVoidMem[43] = 0;
  pVoidMem[46] = -1;
  pVoidMem[47] = 0;
  pVoidMem[50] = -1;
  pVoidMem[48] = 0;
  pVoidMem[51] = -1;
  pVoidMem[49] = 0;
  pVoidMem[52] = -1;
  pVoidMem[53] = 0;
  pVoidMem[56] = -1;
  pVoidMem[54] = 0;
  pVoidMem[57] = -1;
  pVoidMem[55] = 0;
  pVoidMem[58] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004CFB0
// Name: public: virtual void CSosOperatorPosVec8::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPosVec8::Execute(
        CSosOperatorPosVec8 *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  int v7; // esi
  float *v8; // edx
  double v9; // st7

  v6 = pVoidMem[9];
  v7 = (int)pVoidMem[7];
  if ( v7 >= (int)v6 )
    v7 = (int)v6 - 1;
  v8 = pVoidMem + 11;
  switch ( v7 < 0 ? 0 : v7 )
  {
    case 1:
      v8 = pVoidMem + 17;
      break;
    case 2:
      v8 = pVoidMem + 23;
      break;
    case 3:
      v8 = pVoidMem + 29;
      break;
    case 4:
      v8 = pVoidMem + 35;
      break;
    case 5:
      v8 = pVoidMem + 41;
      break;
    case 6:
      v8 = pVoidMem + 47;
      break;
    case 7:
      v8 = pVoidMem + 53;
      break;
    default:
      break;
  }
  pVoidMem[3] = *v8;
  pVoidMem[4] = v8[1];
  v9 = v8[2];
  pVoidMem[6] = v6 - 1.0;
  pVoidMem[5] = v9;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D080
// Name: public: CSosOperatorPosVec8::CSosOperatorPosVec8(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPosVec8 *__thiscall CSosOperatorPosVec8::CSosOperatorPosVec8(CSosOperatorPosVec8 *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-8h] [ebp-28h]
  int v11; // [esp-8h] [ebp-28h]
  int v12; // [esp-8h] [ebp-28h]
  int v13; // [esp-8h] [ebp-28h]
  int v14; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPosVec8_vtbl *)&CSosOperatorPosVec8::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 12;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_max_index", element: &nIndex);
  v9 = this->m_vInputs.m_Size;
  src.m_nOffset = 28;
  src.m_nOffsetOffset = 32;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v9,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_index", element: &nIndex);
  v10 = this->m_vInputs.m_Size;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v10,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_entry_count", element: &nIndex);
  v3 = this->m_vInputs.m_Size;
  src.m_nOffset = 44;
  src.m_nOffsetOffset = 56;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v3,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_0", element: &nIndex);
  v11 = this->m_vInputs.m_Size;
  src.m_nOffset = 68;
  src.m_nOffsetOffset = 80;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v11,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_1", element: &nIndex);
  v12 = this->m_vInputs.m_Size;
  src.m_nOffset = 92;
  src.m_nOffsetOffset = 104;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v12,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_2", element: &nIndex);
  v4 = this->m_vInputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffset = 116;
  src.m_nOffsetOffset = 128;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v4,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_3", element: &nIndex);
  v13 = this->m_vInputs.m_Size;
  src.m_nOffset = 140;
  src.m_nOffsetOffset = 152;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v13,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_4", element: &nIndex);
  src.m_nOffset = 164;
  src.m_nOffsetOffset = 176;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_5", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffset = 188;
  src.m_nOffsetOffset = 200;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_6", element: &nIndex);
  v14 = this->m_vInputs.m_Size;
  src.m_nOffset = 212;
  src.m_nOffsetOffset = 224;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v14,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position_7", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "util_pos_vec8",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004D3D0
// Name: public: virtual unsigned int CSosOperatorPosVec8::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorPosVec8::GetSize(CSosOperatorPosVec8 *this)
{
  return 236;
}

} // namespace engine_xlsp
