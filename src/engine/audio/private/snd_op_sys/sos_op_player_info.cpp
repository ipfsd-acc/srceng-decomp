// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_player_info.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_player_info.h"

//------------------------------------------------------------------------------
// Address: 0x1004CAC0
// Name: public: virtual void CSosOperatorViewInfo::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorViewInfo::SetDefaults(CSosOperatorViewInfo *this, float *pVoidMem)
{
  pVoidMem[3] = 0.0;
  pVoidMem[4] = 0.0;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = 0.0;
  pVoidMem[7] = 0.0;
  pVoidMem[8] = 0.0;
  pVoidMem[13] = 0.0;
  pVoidMem[14] = 0.0;
  pVoidMem[15] = 0.0;
  pVoidMem[16] = 0.0;
  pVoidMem[17] = 0.0;
  pVoidMem[18] = 0.0;
  pVoidMem[9] = 0.0;
  pVoidMem[10] = 0.0;
  pVoidMem[11] = 0.0;
  pVoidMem[21] = 0.0;
  pVoidMem[22] = NAN;
  pVoidMem[24] = 0.0;
  pVoidMem[25] = 0.0;
  pVoidMem[26] = 0.0;
  pVoidMem[23] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x1004CB50
// Name: public: virtual void CSosOperatorViewInfo::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorViewInfo::Execute(
        CSosOperatorViewInfo *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v6; // edi
  float *p_x; // eax
  float v8; // xmm0_4
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v21; // [esp-4h] [ebp-10h]

  v6 = (int)pVoidMem[21];
  if ( v6 <= 1 )
  {
    if ( v6 < 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: %s, input_source_index %i is invalid, clamped\n",
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key,
          v6);
      v6 = 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Error: %s, input_source_index %i is greater than MAX_SPLITSCREEN_CLIENTS, clamped\n",
        pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key,
        v6);
    v6 = 1;
  }
  if ( pVoidMem[23] == 0.0 )
  {
    p_x = &pScratchPad->m_vPlayerOrigin[v6].x;
    pVoidMem[24] = *p_x;
    pVoidMem[25] = p_x[1];
    pVoidMem[26] = p_x[2];
  }
  v8 = g_ClientGlobalVariables.curtime - pVoidMem[23];
  pVoidMem[23] = g_ClientGlobalVariables.curtime;
  if ( v8 > 0.0 )
  {
    v9 = &pScratchPad->m_vPlayerOrigin[v6].x;
    v21 = 1.0 / v8;
    pVoidMem[3] = *v9;
    v10 = pVoidMem[3];
    pVoidMem[4] = v9[1];
    v11 = pVoidMem[4];
    pVoidMem[5] = v9[2];
    pVoidMem[6] = v10;
    v12 = pVoidMem[5];
    pVoidMem[8] = v12;
    pVoidMem[7] = v11;
    v13 = v10 - pVoidMem[24];
    v14 = v11 - pVoidMem[25];
    v15 = (float)(v12 - pVoidMem[26]) * v21;
    pVoidMem[15] = v15;
    pVoidMem[18] = v15;
    v16 = v13 * v21;
    pVoidMem[13] = v16;
    pVoidMem[16] = v16;
    v17 = v14 * v21;
    pVoidMem[14] = v17;
    pVoidMem[17] = v17;
    v18 = v17 * v17;
    v19 = v16 * v16;
    pVoidMem[12] = fsqrt((float)((float)(v15 * v15) + v19) + v18);
    pVoidMem[19] = fsqrt(v19 + v18);
    pVoidMem[24] = *v9;
    pVoidMem[25] = v9[1];
    pVoidMem[26] = v9[2];
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CD60
// Name: public: CSosOperatorViewInfo::CSosOperatorViewInfo(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorViewInfo *__thiscall CSosOperatorViewInfo::CSosOperatorViewInfo(CSosOperatorViewInfo *this)
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
  int v15; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorViewInfo_vtbl *)&CSosOperatorViewInfo::`vftable';
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
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position_x", element: &nIndex);
  v9 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 28;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v9,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position_y", element: &nIndex);
  v10 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 32;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v10,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position_z", element: &nIndex);
  v3 = this->m_vOutputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v3,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_angles", element: &nIndex);
  v11 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 52;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v11,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity_vector", element: &nIndex);
  v12 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 64;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v12,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity_vector_x", element: &nIndex);
  v4 = this->m_vOutputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffsetOffset = 68;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v4,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity_vector_y", element: &nIndex);
  v13 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 72;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v13,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity_vector_z", element: &nIndex);
  v14 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v14,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity", element: &nIndex);
  v5 = this->m_vOutputs.m_Size;
  src.m_nCount = 0;
  src.m_nOffsetOffset = 76;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_velocity_xy", element: &nIndex);
  src.m_nCount = 1;
  v15 = this->m_vInputs.m_Size;
  src.m_nOffset = 84;
  src.m_nOffsetOffset = 88;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v15,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_source_index", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "game_view_info",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004D060
// Name: public: virtual unsigned int CSosOperatorViewInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorViewInfo::GetSize(CSosOperatorViewInfo *this)
{
  return 108;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004C8B0
// Name: public: virtual void CSosOperatorViewInfo::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorViewInfo::SetDefaults(CSosOperatorViewInfo *this, float *pVoidMem)
{
  pVoidMem[3] = 0.0;
  pVoidMem[4] = 0.0;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = 0.0;
  pVoidMem[7] = 0.0;
  pVoidMem[8] = 0.0;
  pVoidMem[13] = 0.0;
  pVoidMem[14] = 0.0;
  pVoidMem[15] = 0.0;
  pVoidMem[16] = 0.0;
  pVoidMem[17] = 0.0;
  pVoidMem[18] = 0.0;
  pVoidMem[9] = 0.0;
  pVoidMem[10] = 0.0;
  pVoidMem[11] = 0.0;
  pVoidMem[21] = 0.0;
  pVoidMem[22] = NAN;
  pVoidMem[24] = 0.0;
  pVoidMem[25] = 0.0;
  pVoidMem[26] = 0.0;
  pVoidMem[23] = g_pSoundServices->GetHostTime(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x1004C940
// Name: public: virtual void CSosOperatorViewInfo::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorViewInfo::Execute(
        CSosOperatorViewInfo *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v6; // edi
  float *p_x; // eax
  float v8; // xmm0_4
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v21; // [esp-4h] [ebp-10h]

  v6 = (int)pVoidMem[21];
  if ( v6 <= 1 )
  {
    if ( v6 < 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: %s, input_source_index %i is invalid, clamped\n",
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key,
          v6);
      v6 = 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Error: %s, input_source_index %i is greater than MAX_SPLITSCREEN_CLIENTS, clamped\n",
        pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key,
        v6);
    v6 = 1;
  }
  if ( pVoidMem[23] == 0.0 )
  {
    p_x = &pScratchPad->m_vPlayerOrigin[v6].x;
    pVoidMem[24] = *p_x;
    pVoidMem[25] = p_x[1];
    pVoidMem[26] = p_x[2];
  }
  v8 = g_ClientGlobalVariables.curtime - pVoidMem[23];
  pVoidMem[23] = g_ClientGlobalVariables.curtime;
  if ( v8 > 0.0 )
  {
    v9 = &pScratchPad->m_vPlayerOrigin[v6].x;
    v21 = 1.0 / v8;
    pVoidMem[3] = *v9;
    v10 = pVoidMem[3];
    pVoidMem[4] = v9[1];
    v11 = pVoidMem[4];
    pVoidMem[5] = v9[2];
    pVoidMem[6] = v10;
    v12 = pVoidMem[5];
    pVoidMem[8] = v12;
    pVoidMem[7] = v11;
    v13 = v10 - pVoidMem[24];
    v14 = v11 - pVoidMem[25];
    v15 = (float)(v12 - pVoidMem[26]) * v21;
    pVoidMem[15] = v15;
    pVoidMem[18] = v15;
    v16 = v13 * v21;
    pVoidMem[13] = v16;
    pVoidMem[16] = v16;
    v17 = v14 * v21;
    pVoidMem[14] = v17;
    pVoidMem[17] = v17;
    v18 = v17 * v17;
    v19 = v16 * v16;
    pVoidMem[12] = fsqrt((float)((float)(v15 * v15) + v19) + v18);
    pVoidMem[19] = fsqrt(v19 + v18);
    pVoidMem[24] = *v9;
    pVoidMem[25] = v9[1];
    pVoidMem[26] = v9[2];
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CE50
// Name: public: virtual unsigned int CSosOperatorViewInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorViewInfo::GetSize(CSosOperatorViewInfo *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x103103D0
// Name: _dynamic_initializer_for__play__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__play__()
{
  ConCommand::ConCommand(
    this: &play,
    pName: "play",
    callback: S_Play,
    pHelpString: "Play a sound.",
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__play__);
}

//------------------------------------------------------------------------------
// Address: 0x10320DE0
// Name: _dynamic_atexit_destructor_for__play__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__play__()
{
  ConCommand::~ConCommand(this: &play);
}

//------------------------------------------------------------------------------
// Address: 0x10310400
// Name: _dynamic_initializer_for__playflush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playflush__()
{
  ConCommand::ConCommand(
    this: &playflush,
    pName: "playflush",
    callback: S_Play,
    pHelpString: "Play a sound, reloading from disk in case of changes.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playflush__);
}

//------------------------------------------------------------------------------
// Address: 0x10310430
// Name: _dynamic_initializer_for__playvol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvol__()
{
  ConCommand::ConCommand(
    this: &playvol,
    pName: "playvol",
    callback: S_PlayVol,
    pHelpString: "Play a sound at a specified volume.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvol__);
}

//------------------------------------------------------------------------------
// Address: 0x10320DF0
// Name: _dynamic_atexit_destructor_for__playflush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playflush__()
{
  ConCommand::~ConCommand(this: &playflush);
}

//------------------------------------------------------------------------------
// Address: 0x10320E00
// Name: _dynamic_atexit_destructor_for__playvol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvol__()
{
  ConCommand::~ConCommand(this: &playvol);
}

} // namespace engine_xlsp
